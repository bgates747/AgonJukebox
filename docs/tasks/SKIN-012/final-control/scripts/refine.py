"""Deterministic palette-preserving profile and contour refinement."""

import numpy as np
from PIL import Image, ImageDraw
from scipy.ndimage import distance_transform_edt


def palette_check(a):
    if a.dtype != np.uint8 or a.ndim != 3 or a.shape[2] != 3:
        raise ValueError("Expected an RGB uint8 raster")
    if np.any(a % 85):
        raise ValueError("Off-palette output")


def mode_rgb(samples):
    """Categorical color mode, with stable lowest-palette-index tie breaking."""
    codes = (samples[:, 0] // 85) * 16 + (samples[:, 1] // 85) * 4 + samples[:, 2] // 85
    n = int(np.argmax(np.bincount(codes, minlength=64)))
    return np.array([n // 16, (n // 4) % 4, n % 4], dtype=np.uint8) * 85


def quantize(a):
    return (np.clip(np.floor(np.asarray(a, dtype=float) / 85 + 0.5), 0, 3) * 85).astype(np.uint8)


def linear_stops(profile):
    """Piecewise linear RGB ramps whose quantized samples equal the profile.

    A segment is extended only if every final native pixel stays identical;
    thin shadow bands and multiple highlights therefore cannot disappear.
    """
    stops = [0]
    while stops[-1] < len(profile) - 1:
        start = stops[-1]
        best = start + 1
        for end in range(start + 2, len(profile)):
            fitted = np.linspace(profile[start].astype(float), profile[end].astype(float), end-start+1)
            if np.array_equal(quantize(fitted), profile[start:end+1]):
                best = end
        stops.append(best)
    result = np.empty_like(profile)
    for start, end in zip(stops, stops[1:]):
        result[start:end+1] = quantize(np.linspace(profile[start].astype(float), profile[end].astype(float), end-start+1))
    if len(profile) == 1:
        result[:] = profile
    assert np.array_equal(result, profile)
    return result, [[int(i), profile[i].tolist()] for i in stops]


def axis_profile(a, region):
    x0,y0,x1,y1 = region['box']
    roi = a[y0:y1,x0:x1].copy()
    axis = region['axis']
    samples = roi.transpose(1,0,2) if axis == 'x' else roi
    profile = np.array([mode_rgb(s) for s in samples])
    profile, stops = linear_stops(profile)
    output = np.broadcast_to(profile[None,:,:], roi.shape) if axis == 'x' else np.broadcast_to(profile[:,None,:], roi.shape)
    a[y0:y1,x0:x1] = output
    return {'name':region['name'],'box':region['box'],'method':'categorical profile, exact quantized piecewise-linear ramps',
            'axis':axis,'gradient_stops':stops,'changed_pixels':int(np.any(roi!=output,axis=2).sum()),
            'pixels':roi.shape[0]*roi.shape[1]}


def polygon_mask(size, points):
    im = Image.new('1',size)
    ImageDraw.Draw(im).polygon([tuple(p) for p in points],fill=1)
    return np.array(im,dtype=bool)


def contour_bevel(a, region, templates):
    """Fit discrete depth/orientation shading to a geometric frame mask.

    Distance is measured inward from a padded outer shape. Local inward normals
    classify lighting faces; the inner shape cuts out the face/content area.
    Pixel sampling and output are categorical, never blurred or dithered.
    """
    x0,y0,x1,y1 = region['box']; w,h=x1-x0,y1-y0
    roi=a[y0:y1,x0:x1].copy()
    outer=polygon_mask((w,h),region['outer'])
    inner=polygon_mask((w,h),region['inner'])
    mask=outer & ~inner
    if 'outside_color' in region:
        a[y0:y1,x0:x1][~outer]=region['outside_color']
    if 'face_color' in region:
        a[y0:y1,x0:x1][inner]=region['face_color']
    distance=distance_transform_edt(np.pad(outer,1))[1:-1,1:-1]
    gy,gx=np.gradient(distance)
    side=np.where(np.abs(gx)>np.abs(gy),np.where(gx>=0,0,2),np.where(gy>=0,1,3))
    depth=np.maximum(0,np.floor(distance+1e-6).astype(int)-1)
    table=[]
    inherited={(e['depth'],e['face']):e['color'] for e in templates.get(region.get('reuse_from'),[])}
    for d in sorted(set(depth[mask].tolist())):
        for face in range(4):
            selected=mask & (depth==d) & (side==face)
            if not selected.any(): continue
            face_name=['left','top','right','bottom'][face]
            color=np.array(inherited[(d,face_name)],dtype=np.uint8) if (d,face_name) in inherited else mode_rgb(roi[selected])
            a[y0:y1,x0:x1][selected]=color
            table.append({'depth':d,'face':['left','top','right','bottom'][face], 'color':color.tolist(),'samples':int(selected.sum())})
    templates[region['name']]=table
    changed=np.any(roi!=a[y0:y1,x0:x1],axis=2)
    return {'name':region['name'],'box':region['box'],'method':'geometric contour distance and directional categorical shading',
            'shading_table':table,'changed_pixels':int(changed.sum()),'mask_pixels':int(mask.sum())}


def refine(source, parameters):
    a=source.copy();changes=[];templates={}
    for r in parameters['axis_regions']:
        changes.append(axis_profile(a,r))
    for r in parameters['bevels']:
        changes.append(contour_bevel(a,r,templates))
    for r in parameters['mirrors']:
        x0,y0,x1,y1=r['source']; x,y=r['target'];w=x1-x0;h=y1-y0
        original=a[y:y+h,x:x+w].copy()
        a[y:y+h,x:x+w]=a[y0:y1,x0:x1][:,::-1].copy()
        changes.append({'name':r['name'],'method':'canonical horizontal reflection','source':r['source'],'target':r['target'],
                        'changed_pixels':int(np.any(original!=a[y:y+h,x:x+w],axis=2).sum()),'lighting':r['lighting']})
    for r in parameters.get('protect_art',[]):
        x0,y0,x1,y1=r['box']
        a[y0:y1,x0:x1]=source[y0:y1,x0:x1]
    palette_check(a)
    return a, changes

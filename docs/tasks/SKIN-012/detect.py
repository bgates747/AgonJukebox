"""Find complete light-colored transport symbols inside protected face ROIs."""

import numpy as np


def foreground(a):
    # Cream/white/gray glyph pixels, including RGB222 antialias levels. The
    # face ROIs exclude beveled edges and the cyan volume-level indicator.
    return np.all(a>=85,axis=2)


def icons_from_rois(source,rois):
    icons=[]
    for region in rois:
        x0,y0,x1,y1=region['box']
        ys,xs=np.nonzero(foreground(source[y0:y1,x0:x1]))
        if not len(xs): raise ValueError(f"No symbol found: {region['name']}")
        box=[max(x0,x0+int(xs.min())-1),max(y0,y0+int(ys.min())-1),
             min(x1,x0+int(xs.max())+2),min(y1,y0+int(ys.max())+2)]
        icons.append({'name':region['name'],'box':box,'background':region['background'],
                      'method':'light-pixel bounds within face ROI, padded by one pixel',
                      'foreground_pixels':len(xs)})
    return icons

"""Deterministic grayscale/threshold candidate review; never modifies input pixels.
White regions use 4-connectivity; their black holes use complementary 8-connectivity.
Scores are heuristics, not semantic shape recognition. No denoising or morphology.
"""
import argparse, hashlib, html, json, sys
from pathlib import Path
import numpy as np
from PIL import Image, ImageDraw, __version__ as pillow_version
import scipy
from scipy import ndimage as ndi

def sha(p): return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def grays(image):
 rgb=np.asarray(image.convert('RGB'),dtype=float)/255
 lin=np.where(rgb<=.04045,rgb/12.92,((rgb+.055)/1.055)**2.4)
 y=lin@np.array([.2126,.7152,.0722])
 perceptual=np.where(y<=.0031308,12.92*y,1.055*y**(1/2.4)-.055)
 return {'pillow-luma':np.asarray(image.convert('L')),
 'rec709-encoded':np.rint(rgb@np.array([.2126,.7152,.0722])*255).astype('uint8'),
 'linear-luminance-srgb':np.clip(np.rint(perceptual*255),0,255).astype('uint8')}
def load(p):
 with Image.open(p) as im:
  if 'A' in im.getbands() and im.getchannel('A').getextrema()!=(255,255):
   raise ValueError('Transparent inputs require an explicit background before ranking')
  return im.convert('RGB')
def calibrate(source,reference):
 im=load(source);ref=np.asarray(load(reference))
 if ref.shape!=np.asarray(im).shape: raise ValueError('Reference dimensions differ')
 if not np.all((ref==0)|(ref==255)) or not np.all(ref==ref[:,:,:1]): raise ValueError('Reference must be binary grayscale')
 truth=ref[:,:,0]==255; rows=[]
 for method,g in grays(im).items():
  white=np.bincount(g[truth],minlength=256);black=np.bincount(g[~truth],minlength=256)
  # Convention: white iff grayscale > threshold.
  errors=np.cumsum(white)+black.sum()-np.cumsum(black)
  best=int(errors.argmin()); rows.append(dict(method=method,threshold=best,
   equally_best_thresholds=np.flatnonzero(errors==errors[best]).tolist(),
   mismatch_pixels=int(errors[best]),agreement=1-float(errors[best])/truth.size))
 return {'source_sha256':sha(source),'mask_sha256':sha(reference),'fits':sorted(rows,key=lambda r:r['mismatch_pixels'])}
def components(mask):
 labels,n=ndi.label(mask); areas=np.bincount(labels.ravel())[1:]
 return labels,areas

def measure(g,t,contrast=None):
 m=g>t;labels,areas=components(m);pixels=m.size;white=int(m.sum())
 if not white or white==pixels: return None
 # Sixteen source pixels ~= two output pixels for a 1448x1086 -> 512x384 image.
 minimum=max(4,round(pixels/(512*384)*2))
 useful=areas[areas>=minimum]; tiny=areas[areas<minimum]
 if not len(useful): return None
 lo=g>max(0,t-4);hi=g>min(255,t+4)
 _,al=components(lo);_,ah=components(hi)
 nl=int((al>=minimum).sum());nh=int((ah>=minimum).sum())
 topology_stability=1-min(1,abs(nl-nh)/max(len(useful),1))
 pixel_stability=float(hi.sum()/max(1,lo.sum()))
 # Does each boundary have a meaningful local luminance contrast? Sample +/-2 px.
 boundary=m & ~ndi.binary_erosion(m)
 if contrast is None: contrast=ndi.maximum_filter(g,size=5).astype(float)-ndi.minimum_filter(g,size=5)
 edge_support=float(np.minimum(contrast[boundary]/64,1).mean())
 tiny_fraction=len(tiny)/max(1,len(areas));dominant=float(areas.max()/white)
 white_fraction=white/pixels
 # Uniform masks and one giant white blob are not useful shape decompositions.
 coverage=min(1,white_fraction/.20,(1-white_fraction)/.20)
 separation=1-max(0,(dominant-.20)/.80)
 score=100*coverage*(.30*pixel_stability+.25*topology_stability+.20*edge_support+.15*(1-tiny_fraction)+.10*separation)
 return dict(threshold=t,score=round(score,6),white_fraction=white_fraction,
  components=len(areas),useful_components=len(useful),tiny_components=len(tiny),
  tiny_area=int(tiny.sum()),minimum_useful_area=minimum,dominant_fraction=dominant,
  pixel_stability=pixel_stability,topology_stability=topology_stability,edge_support=edge_support)
def save_mask(m,p): Image.fromarray((m*255).astype('uint8')).convert('1').save(p)
def shape_map(m):
 labels,areas=components(m);n=len(areas)
 ids=np.arange(n+1,dtype=np.uint32)
 colors=np.stack([64+(ids*67)%192,64+(ids*113)%192,64+(ids*157)%192],axis=1).astype('uint8');colors[0]=0
 return Image.fromarray(colors[labels])
def run(source,out,reference_source=None,reference_mask=None):
 if out.exists(): raise ValueError('Output exists; choose a new review directory')
 if bool(reference_source)!=bool(reference_mask): raise ValueError('Supply both reference arguments')
 im=load(source); hashes={str(source):sha(source)}
 calibration=calibrate(reference_source,reference_mask) if reference_source else None
 if calibration:
  hashes.update({str(p):sha(p) for p in [reference_source,reference_mask]})
 gs=grays(im); rows=[]
 for name,g in gs.items():
  contrast=ndi.maximum_filter(g,size=5).astype(float)-ndi.minimum_filter(g,size=5)
  # 4-level sweep over almost the full range; reference fit added explicitly.
  thresholds=set(range(4,253,4))
  if calibration: thresholds.update(r['threshold'] for r in calibration['fits'] if r['method']==name)
  for t in sorted(thresholds):
   r=measure(g,t,contrast)
   if r: rows.append(dict(method=name,**r))
  print(name,'complete',flush=True)
 rows.sort(key=lambda r:(-r['score'],r['method'],r['threshold']))
 # Reject near-duplicate results, including different formulas yielding same mask.
 selected=[];masks=[]
 for r in rows:
  m=gs[r['method']]>r['threshold']
  if not .12<=r['white_fraction']<=.85: continue
  if any(np.mean(m!=old)<.025 for old in masks): continue
  selected.append(dict(r));masks.append(m)
  if len(selected)==5: break
 if not selected: raise ValueError('No nondegenerate candidates')
 out.mkdir(parents=True);im.save(out/'source.png')
 cards=[];sheet=Image.new('RGB',(1024,420*((len(selected)+1)//2)), '#252525');draw=ImageDraw.Draw(sheet)
 for i,(r,m) in enumerate(zip(selected,masks),1):
  stem=f'candidate-{i:02d}';r['mask']=stem+'.png'
  save_mask(m,out/r['mask']);shape_map(m).save(out/(stem+'-shapes.png'))
  Image.fromarray(gs[r['method']]).save(out/(stem+'-gray.png'))
  preview=Image.open(out/r['mask']).convert('RGB').resize((512,384),Image.Resampling.NEAREST)
  preview.save(out/(stem+'-512.png'))
  x=((i-1)%2)*512;y=((i-1)//2)*420
  draw.text((x+10,y+6),f"{i}: {r['method']} > {r['threshold']} | {r['useful_components']} regions | {r['score']:.1f}",fill='white')
  sheet.paste(preview,(x,y+30))
  cards.append(f'''<section><h2>Candidate {i}: {html.escape(r['method'])} &gt; {r['threshold']}</h2>
<p>Score {r['score']:.1f}; {r['useful_components']} useful regions; {r['tiny_components']} tiny regions; white {r['white_fraction']:.1%}.</p>
<a href="{stem}.png">Full-resolution binary PNG</a> · <a href="{stem}-gray.png">Grayscale</a>
<div class="pair"><img src="{stem}.png"><img src="{stem}-shapes.png"></div></section>''')
 sheet.save(out/'comparison.png')
 report=dict(source=str(source),source_hashes=hashes,dimensions=im.size,
  versions={'python':sys.version.split()[0],'numpy':np.__version__,'Pillow':pillow_version,'scipy':scipy.__version__},
  threshold_convention='white iff gray > threshold; full source resolution, no cleanup',
  calibration=calibration,selected=selected,sweep=rows)
 (out/'report.json').write_text(json.dumps(report,indent=2)+'\n')
 (out/'index.html').write_text('''<!doctype html><meta charset="utf-8"><title>Threshold shape review</title>
<style>body{background:#202124;color:#eee;font:16px system-ui;margin:24px}a{color:#8bd3ff}.pair{display:flex;gap:12px}.pair img{width:49%;object-fit:contain;image-rendering:pixelated}section{margin:40px 0}img{max-width:100%}</style>
<h1>Threshold shape candidates</h1><p>Left: untouched binary threshold. Right: connected white regions colored for inspection (not proposed skin colors). Click a binary link for original dimensions. Browser previews are scaled.</p>
<p>Heuristic ranking favors threshold stability, boundary contrast and few speckles; it cannot recognize intended artwork or recover equal-luminance color boundaries. Tiny regions are counted, never removed. 512×384 previews use nearest neighbor only, not final vector rasterization.</p>
<details><summary>Original source</summary><img src="source.png"></details>'''+''.join(cards))
 for p,h in hashes.items(): assert sha(p)==h,'Input changed'
 for r in selected:
  with Image.open(out/r['mask']) as check:
   assert check.size==im.size and check.mode=='1'
 print('Review:',out/'index.html',flush=True)
 return report
if __name__=='__main__':
 p=argparse.ArgumentParser(description=__doc__);p.add_argument('source',type=Path);p.add_argument('--out',type=Path,required=True)
 p.add_argument('--reference-source',type=Path);p.add_argument('--reference-mask',type=Path)
 a=p.parse_args();run(a.source.resolve(),a.out.resolve(),a.reference_source,a.reference_mask)

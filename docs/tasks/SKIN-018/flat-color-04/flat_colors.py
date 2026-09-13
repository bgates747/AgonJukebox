"""Source-sampled Agon64 flat-color drafts using the accepted 70s shape mask.
Reuses the Art Deco inset/histogram sampler and canonical Agon64 palette.
"""
from pathlib import Path
import sys,argparse,json,hashlib,shutil
import numpy as np
from PIL import Image,ImageDraw
from scipy import ndimage as ndi
from scipy.cluster.vq import kmeans2
HERE=Path(__file__).resolve().parent;PROJECT=HERE.parents[2]
sys.path.insert(0,str(HERE.parent/'SKIN-013'))
from colorize_shapes import sample_color,indexed_png
SOURCE=PROJECT/'that-70s-skin.png'
MASK=HERE/'state-text-02/clean-mask.png'
EDITS=HERE/'state-text-02/report.json'
PALETTE=HERE.parent/'SKIN-013/flat-color-full-02/Agon64.gpl'
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def oklab(rgb):
 a=np.asarray(rgb,dtype=float)/255
 lin=np.where(a<=.04045,a/12.92,((a+.055)/1.055)**2.4)
 lms=lin @ np.array([[.4122214708,.5363325363,.0514459929],[.2119034982,.6806995451,.1073969566],[.0883024619,.2817188376,.6299787005]]).T
 return np.cbrt(lms) @ np.array([[.2104542553,.7936177850,-.0040720468],[1.9779984951,-2.4285922050,.4505937099],[.0259040371,.7827717662,-.8086757660]]).T

def build(out):
 if out.exists():raise ValueError('Output exists; choose a fresh worksheet')
 inputs={str(p):sha(p) for p in [SOURCE,MASK,EDITS,PALETTE]}
 rgb=np.array(Image.open(SOURCE).convert('RGB'));mask=np.array(Image.open(MASK).convert('L'))==255
 palette=[]
 for line in PALETTE.read_text().splitlines():
  words=line.split()
  if len(words)>=3 and all(w.isdecimal() for w in words[:3]):palette.append(list(map(int,words[:3])))
 palette=np.array(palette,dtype='uint8');assert palette.shape==(64,3) and not np.any(palette%85)
 assert mask.shape==rgb.shape[:2]==(1086,1448)
 edits=json.loads(EDITS.read_text())['regions'];exclude=np.zeros(mask.shape,dtype=bool)
 for r in edits:
  x0,y0,x1,y1=r['box'];exclude[y0:y1,x0:x1]=True
 # Preserve the four-connectivity used to select candidate 1.
 labels,count=ndi.label(mask);boxes=ndi.find_objects(labels);flat=np.zeros_like(rgb);raw=np.zeros_like(rgb)
 params={'sample_inset_source_pixels':2,'histogram_bin_width':16};records=[]
 for ident,sl in enumerate(boxes,1):
  region=labels[sl]==ident;samplemask=region & ~exclude[sl]
  if not samplemask.any(): raise ValueError(f'Region {ident} has no original nontext pixels')
  result=sample_color(rgb[sl],samplemask,params,palette)
  flat[sl][region]=result['fill_rgb'];raw[sl][region]=np.rint(result['representative_rgb']).astype('uint8')
  y,x=sl;records.append(dict(id=ident,box=[x.start,y.start,x.stop,y.stop],area=int(region.sum()),**result))
 # Optional supplementary background: threshold mask discarded dark brown along
 # with black ink. Explicit color rule only adds dark warm source pixels outside
 # accepted white shapes; small components (<64 source pixels) are left black.
 signed=rgb.astype('int16');gray=np.array(Image.open(SOURCE).convert('L'))
 brown=(signed[:,:,0]-signed[:,:,1]>=12)&(signed[:,:,1]-signed[:,:,2]>=6)&(gray<100)&~mask&~exclude
 blabels,bcount=ndi.label(brown);areas=np.bincount(blabels.ravel());keep=areas>=64;keep[0]=False;brown=keep[blabels]
 if not brown.any():raise ValueError('No supplementary brown backdrop found')
 sampled_brown=sample_color(rgb,brown,params,palette)
 # Fill cleared state-text boxes to the same backdrop. They contain only the
 # previously reviewed state-text excisions; highlighted-row boxes stay gold.
 for r in edits:
  if r['fill']==0:
   x0,y0,x1,y1=r['box'];brown[y0:y1,x0:x1]|=~mask[y0:y1,x0:x1]
 extended=flat.copy();extended[brown]=sampled_brown['fill_rgb']
 raw_extended=raw.copy();raw_extended[brown]=np.rint(sampled_brown['representative_rgb']).astype('uint8')
 assert np.array_equal(extended[mask],flat[mask])
 assert not np.any(flat[~mask])
 # Eight color-family seeds selected by visual inspection of this source.
 # Centers are then fitted to actual source pixels, not invented output colors.
 training=rgb[::6,::6].reshape(-1,3);weight=np.array([1.,2.5,2.5]);lab=oklab(training)*weight
 seeds_rgb=np.array([[0,0,0],[255,245,200],[215,80,20],[230,175,25],[65,35,20],[110,135,55],[40,120,115],[170,60,50]])
 centers,assignment=kmeans2(lab,oklab(seeds_rgb)*weight,iter=40,minit='matrix',missing='raise')
 family_rgb=np.array([np.median(training[assignment==i],axis=0) for i in range(8)])
 family_palette=np.argmin(np.sum(((oklab(family_rgb)[:,None,:]-oklab(palette)[None,:,:])*np.array([1.,2.,2.]))**2,axis=2),axis=1)
 consistent=np.zeros_like(rgb);family_records=[]
 for rec,sl in zip(records,boxes):
  region=labels[sl]==rec['id'];samplemask=region & ~exclude[sl]
  inset=ndi.binary_erosion(samplemask,iterations=2)
  samples=rgb[sl][inset if inset.any() else samplemask]
  classes=np.argmin(np.sum((oklab(samples)[:,None,:]*weight-centers[None,:,:])**2,axis=2),axis=1)
  family=int(np.bincount(classes,minlength=8).argmax())
  # Manually identified fine playlist rules share the cream static-label color.
  x0,y0,x1,y1=rec['box']
  if x1-x0>900 and y1-y0<=6 and 240<=y0<=633: family=1
  consistent[sl][region]=palette[family_palette[family]]
  family_records.append(dict(id=rec['id'],family=family,fill_rgb=palette[family_palette[family]].tolist(),winning_fraction=float(np.mean(classes==family))))
 # Expanded cleared fields suppress source text shadows as well as bright glyphs;
 # never replace accepted foreground pixels or touch the selected row.
 background=brown.copy()
 for r in edits:
  if r['fill']==0:
   x0,y0,x1,y1=r['box'];x0=max(0,x0-3);y0=max(0,y0-2);x1=min(1448,x1+3);y1=min(1086,y1+3)
   background[y0:y1,x0:x1]|=~mask[y0:y1,x0:x1]
 brown_family=int(np.argmin(np.sum((oklab(np.array(sampled_brown['representative_rgb']))*weight-centers)**2,axis=1)))
 consistent[background]=palette[family_palette[brown_family]]
 out.mkdir(parents=True);shutil.copyfile(SOURCE,out/'original.png');shutil.copyfile(MASK,out/'clean-mask.png');shutil.copyfile(PALETTE,out/'Agon64.gpl')
 for name,a in [('candidate-1-mask-only',flat),('candidate-2-brown-backdrop',extended),('candidate-3-consistent-families',consistent)]:
  indexed_png(a,palette,out/(name+'.png'))
  preview=Image.fromarray(a).resize((512,384),Image.Resampling.NEAREST)
  indexed_png(np.array(preview),palette,out/(name+'-512.png'))
  preview.resize((1536,1152),Image.Resampling.NEAREST).save(out/(name+'-3x.png'))
 (out/'color-families.json').write_text(json.dumps({'initial_source_family_seeds':seeds_rgb.tolist(),'clustering_lab_weights':weight.tolist(),'palette_lab_weights':[1,2,2],'source_rgb':family_rgb.tolist(),'agon_rgb':palette[family_palette].tolist(),'regions':family_records},indent=2)+'\n')
 Image.fromarray(raw_extended).save(out/'source-sampled-flat.png')
 Image.fromarray(np.uint8(brown)*255).convert('1').save(out/'supplementary-background-mask.png')
 Image.fromarray(np.uint8(background)*255).convert('1').save(out/'candidate-3-background-mask.png')
 np.save(out/'shape-labels.npy',labels,allow_pickle=False)
 (out/'shapes.json').write_text(json.dumps(records,indent=2)+'\n')
 # Actual visible Agon colors, with pixel usage. No diagnostic colors in drafts.
 swatches=[]
 colors,amounts=np.unique(consistent.reshape(-1,3),axis=0,return_counts=True)
 for c,amount in sorted(zip(colors,amounts),key=lambda pair:-pair[1]):
  hexcode='#'+''.join(f'{n:02x}' for n in c)
  swatches.append(f'<div class="swatch"><i style="background:{hexcode}"></i><code>{hexcode}</code> {amount/labels.size:.1%}</div>')
 family_table='<table><tr><th>Source family</th><th>Sampled RGB</th><th>Agon RGB</th></tr>'
 for title,src,dst in zip(['Ink','Cream','Orange','Gold','Brown','Green','Teal','Rust'],family_rgb,palette[family_palette]):
  def swatch(c):
   code='#'+''.join(f'{int(round(n)):02x}' for n in c)
   return f'<td style="padding:8px"><i style="display:inline-block;width:60px;height:28px;background:{code};border:1px solid #aaa;vertical-align:middle"></i> {code}</td>'
  family_table+='<tr><td>'+title+'</td>'+swatch(src)+swatch(dst)+'</tr>'
 family_table+='</table>'
 gallery=[]
 # Regions chosen by manual semantic inspection as likely future gradient studies.
 crops=[('Rainbow and flower',(295,0,1152,195)),('Left rails and flower',(10,195,176,824)),('Transport buttons',(174,838,1276,978)),('Lower record',(418,977,1030,1086))]
 for i,(title,box) in enumerate(crops,1):
  Image.fromarray(consistent).crop(box).save(out/f'element-{i}.png')
  gallery.append(f'<figure><figcaption>{i}. {title}</figcaption><img src="element-{i}.png"></figure>')
 report=dict(inputs_sha256=inputs,shape_count=count,connectivity=4,source_size=[1448,1086],preview_size=[512,384],
  sampling=params,state_text_excluded_from_sampling=True,visible_colors=len(colors),
  supplementary_brown=dict(color=sampled_brown,rule='R-G >= 12, G-B >= 6, Pillow L < 100; outside white mask and text boxes; 4-connected area >=64; cleared nonselected text boxes filled',added_pixels=int(brown.sum())),
  candidate_1_black_outside_mask=True,candidate_2_white_shape_geometry_and_colors_unchanged=True,
  rasterization='Source-resolution masks; nearest-neighbor target preview only, not vector tracing or smoothing',
  consistent_color_method='Eight global source families in Oklab; visually chosen source-family seeds; weighted Oklab [1,2.5,2.5] clustering; per-region majority family; palette distance weights [1,2,2]; manually identified fine rules use cream',
  off_palette_pixels=int(np.any(extended%85,axis=2).sum()+np.any(consistent%85,axis=2).sum()))
 assert report['off_palette_pixels']==0
 for p,h in inputs.items():assert sha(Path(p))==h
 (out/'report.json').write_text(json.dumps(report,indent=2)+'\n')
 (out/'index.html').write_text('''<!doctype html><html><head><meta charset="utf-8"><title>70s skin — flat Agon colors</title>
<style>body{background:#242426;color:#eee;font:17px system-ui;margin:24px}p{max-width:1100px}a{color:#9edcff}button,select{font:inherit;padding:8px;margin:4px}.tools{position:sticky;top:0;background:#242426;z-index:3;padding:8px}.viewport{overflow:auto;max-height:82vh;border:1px solid #888}#main{display:block;max-width:none;image-rendering:pixelated}.swatches{display:flex;gap:15px;flex-wrap:wrap}.swatch i{display:inline-block;width:36px;height:30px;border:1px solid #888;vertical-align:middle;margin-right:8px}figure{margin:24px 0}figure img{max-width:100%;image-rendering:pixelated}figcaption{padding:8px 0}code{font-size:16px}</style></head><body>
<h1>70s skin — flat Agon64 colors</h1>
<p>Colors sampled from the original art, one flat fill per cleaned-mask region, using the established Art Deco sampler. All numbered candidates use only actual Agon colors. No gradients or dithering.</p>
<p><b>1 — Accepted mask only:</b> preserves its exact shape geometry; all excluded dark areas remain black.<br><b>2 — Brown backdrop restored:</b> same foreground shapes and colors, plus an explicitly derived dark-brown background mask. This recovers some dark artwork that grayscale thresholding merged with black outlines. The added mask is provisional.<br><b>3 — Consistent source colors (suggested):</b> eight visually identified source color families, nearest Agon colors using chroma-emphasized Oklab distance. Keeps related petals/bands consistent and preserves teal better than direct RGB matching. Fine playlist rules are assigned the same cream as static labels. Same accepted foreground geometry; supplementary backdrop and cleared text-shadow areas are explicit additions.</p>
<div class="tools"><button onclick="show('candidate-1-mask-only')">1: Mask only</button><button onclick="show('candidate-2-brown-backdrop')">2: Brown backdrop</button><button onclick="show('candidate-3-consistent-families')">3: Consistent colors</button><button onclick="show('original')">Original artwork</button><button onclick="show('source-sampled-flat')">Sampled colors before Agon mapping</button>
<label>View <select onchange="resize(this.value)"><option value="fit">Fit width</option><option value="native">512×384 preview</option><option value="1">100% source</option><option value="2">200% source</option></select></label><span id="caption"></span></div>
<div class="viewport" id="viewport"><img id="main" src="candidate-3-consistent-families.png" alt="Flat skin review"></div>
<p>The original and “before Agon mapping” views are references, not palette-compliant candidates. Target previews use nearest neighbor; vector smoothing is still a separate step. State text is cleared; the arrow and nontext controls are retained.</p>
<h2>Actual colors in candidate 3</h2><div class="swatches">'''+''.join(swatches)+'''</div><h2>Original color families → Agon64</h2><p>The limited palette maps the dark brown to dark red and the orange to ochre. These are reviewable approximations, not exact original colors. Source swatches in this table are reference colors.</p>'''+family_table+'''
<p><a href="candidate-1-mask-only.png">Candidate 1 PNG</a> · <a href="candidate-2-brown-backdrop.png">Candidate 2 PNG</a> · <a href="supplementary-background-mask.png">Added brown-region mask</a> · <a href="candidate-3-consistent-families.png">Candidate 3 PNG</a> · <a href="color-families.json">Consistent color families</a> · <a href="shapes.json">Per-shape sampled colors</a> · <a href="report.json">Method and checks</a></p>
<h2>Elements for later gradient experiments</h2><p>These remain flat in this worksheet. Broad rainbow bands, rails and record labels give us room to compare a few discrete Agon shade steps later.</p>'''+''.join(gallery)+'''
<script>let current='candidate-3-consistent-families',scale='fit';function show(s){current=s;paint()}function resize(s){scale=s;paint()}function paint(){let image=document.getElementById('main');let native=scale==='native'&&current.startsWith('candidate-');image.src=current+(native?'-512':'')+'.png';image.style.width=(scale==='fit'?document.getElementById('viewport').clientWidth:scale==='native'?512:1448*Number(scale))+'px';document.getElementById('caption').textContent=current}window.addEventListener('resize',paint);paint();</script></body></html>''')
 shutil.copyfile(Path(__file__),out/'flat_colors.py')
 print(json.dumps({'shapes':count,'colors':len(colors),'brown':sampled_brown['fill'],'worksheet':str(out/'index.html')}))
if __name__=='__main__':
 p=argparse.ArgumentParser(description=__doc__);p.add_argument('--out',required=True,type=Path);a=p.parse_args();build(a.out.resolve())

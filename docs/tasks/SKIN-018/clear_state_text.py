"""Manually reviewed rectangular text excisions from accepted binary candidate 1.
Coordinates are half-open source pixels. No resampling or morphology.
"""
from pathlib import Path
import argparse,hashlib,json,html
import numpy as np
from PIL import Image,ImageDraw
ROOT=Path(__file__).resolve().parent
SOURCE=ROOT/'review-01/candidate-01.png'

def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def build(out):
 if out.exists():raise ValueError('Output exists; choose a fresh worksheet directory')
 source_hash=sha(SOURCE)
 with Image.open(SOURCE) as im:before=np.asarray(im.convert('L')).copy()
 assert before.shape==(1086,1448) and np.all(np.isin(before,[0,255]))
 after=before.copy();regions=[];allowed=np.zeros(before.shape,dtype=bool)
 rows=[(252,283),(290,321),(328,355),(367,395),(405,433),(444,472),(482,510),(521,549),(559,587),(597,626)]
 for i,(top,bottom) in enumerate(rows):
  for label,left,right in [('row number',242,276),('filename',323,753),('duration',1092,1196)]:
   regions.append(dict(name=f'Row {i}: {label}',box=[left,top,right,bottom],fill=255 if i==3 else 0))
 regions.extend([
  dict(name='Playing filename',box=[514,716,937,764],fill=0),
  dict(name='Elapsed and total time',box=[594,765,855,795],fill=0),
  dict(name='Current directory /MUSIC',box=[175,1005,319,1045],fill=0),
  dict(name='File count 10 FILES',box=[1125,1005,1298,1045],fill=0)])
 for r in regions:
  x0,y0,x1,y1=r['box'];old=after[y0:y1,x0:x1]
  r['changed_pixels']=int(np.count_nonzero(old!=r['fill']))
  assert r['changed_pixels']>0,r['name']
  old[:]=r['fill'];allowed[y0:y1,x0:x1]=True
 changed=before!=after
 assert not changed[~allowed].any()
 out.mkdir(parents=True)
 Image.fromarray(before).convert('1').save(out/'before.png')
 Image.fromarray(after).convert('1').save(out/'clean-mask.png')
 # Color marks only changed pixels. It is not a skin color proposal.
 overlay=np.repeat(before[:,:,None],3,axis=2);overlay[changed]=[255,60,110]
 Image.fromarray(overlay).save(out/'changes.png')
 Image.fromarray(np.uint8(changed)*255).convert('1').save(out/'changed-pixels.png')
 annotated=Image.fromarray(np.repeat(before[:,:,None],3,axis=2));draw=ImageDraw.Draw(annotated)
 for r in regions:
  x0,y0,x1,y1=r['box'];draw.rectangle((x0,y0,x1-1,y1-1),outline='#ff3c6e',width=2)
 annotated.save(out/'reviewed-regions.png')
 cards=[]
 for i,(name,box) in enumerate([
  ('Playlist: ten row numbers, filenames and durations',(225,207,1229,637)),
  ('Now playing: filename and time',(507,642,943,797)),
  ('Directory: folder icon retained',(35,989,409,1059)),
  ('File count: panel retained',(1035,989,1415,1059))],1):
  for stem,a in [('before',before),('after',after)]:
   Image.fromarray(a).crop(box).save(out/f'crop-{i}-{stem}.png')
  cards.append(f'<section><h2>{i}. {html.escape(name)}</h2><div class="pair"><figure><figcaption>Before</figcaption><img src="crop-{i}-before.png"></figure><figure><figcaption>After</figcaption><img src="crop-{i}-after.png"></figure></div></section>')
 report=dict(source=str(SOURCE),source_sha256=source_hash,dimensions=[1448,1086],
  regions=regions,changed_pixels=int(changed.sum()),outside_regions_unchanged=True,
  static_labels_retained=['AGON JUKEBOX','#','FILE NAME','TIME','NOW PLAYING'],
  nontext_retained=['selection bar and triangle','row rules','transport icons','progress bar','volume graphic','folder icon','all decorative artwork'])
 (out/'report.json').write_text(json.dumps(report,indent=2)+'\n')
 (out/'index.html').write_text('''<!doctype html><html><head><meta charset="utf-8"><title>70s skin — state text removal</title>
<style>body{font:17px system-ui;background:#222327;color:#eee;margin:24px}a{color:#9edcff}button,select{font:inherit;padding:8px;margin:4px}h1{margin-bottom:8px}.tools{position:sticky;top:0;background:#222327;padding:10px;z-index:2}.viewport{overflow:auto;max-height:82vh;border:1px solid #777}#main{display:block;image-rendering:pixelated;max-width:none}.pair{display:flex;gap:16px}figure{margin:0;flex:1;min-width:0}.pair img{width:100%;image-rendering:pixelated}figcaption{padding:8px 0;color:#ccc}section{margin:40px 0}p{max-width:1000px}</style></head><body>
<h1>70s skin — candidate 1, state text removed</h1>
<p>Manually inspected source-pixel excisions. Static labels, decorative shapes and nontext controls remain. The selected row stays white; its black text is filled white. All other text is cleared to black.</p>
<p>Kept: <b>AGON JUKEBOX · # · FILE NAME · TIME · NOW PLAYING</b>. Selection marker, highlight, progress bar and volume graphic are preserved for this text-only pass.</p>
<div class="tools"><button onclick="show('clean-mask.png')">Clean result</button><button onclick="show('before.png')">Original candidate 1</button><button onclick="show('changes.png')">Changed pixels (pink)</button><button onclick="show('reviewed-regions.png')">Inspected regions</button>
<label>Zoom <select onchange="zoom(this.value)"><option value="fit">Fit width</option><option value="1">100%</option><option value="2">200%</option><option value="3">300%</option></select></label><span id="viewname">Clean result</span></div>
<div class="viewport" id="viewport"><img id="main" src="clean-mask.png" alt="Skin mask review"></div>
<p><a href="clean-mask.png">Full-resolution clean PNG</a> · <a href="report.json">Coordinates and verification</a> · <a href="changed-pixels.png">Binary change mask</a></p>
'''+''.join(cards)+'''
<script>let scale='fit';function zoom(s){scale=s;document.getElementById('main').style.width=(s==='fit'?document.getElementById('viewport').clientWidth:1448*Number(s))+'px'}function show(src){document.getElementById('main').src=src;document.getElementById('viewname').textContent=src}window.addEventListener('resize',()=>zoom(scale));zoom('fit');</script></body></html>''')
 assert sha(SOURCE)==source_hash
 with Image.open(out/'clean-mask.png') as im:assert np.array_equal(np.asarray(im.convert('L')),after)
 print(json.dumps({'output':str(out),'changed_pixels':int(changed.sum()),'regions':len(regions)}))
if __name__=='__main__':
 p=argparse.ArgumentParser(description=__doc__);p.add_argument('--out',type=Path,required=True);a=p.parse_args();build(a.out.resolve())

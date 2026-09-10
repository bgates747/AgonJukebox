"""Independent reconstruction from saved manifests and canonical AGNB pixels."""

import argparse
import json
from pathlib import Path

import numpy as np
from PIL import Image

from toolkit import canonical


def reconstruct(folder,utils):
    manifest=json.loads((folder/'manifest.json').read_text())
    _,viewer,_=canonical(utils)
    data,records=viewer.parse_container(folder/'graphics.agnb')
    by_id={r.bufferId:r for r in records}
    images={}
    for entry in manifest['assets']:
        if 'derive' in entry:
            recipe=entry['derive']
            if recipe['op']!='mirror-x': raise ValueError('Unknown derivation')
            image=images[recipe['source']][:,::-1].copy()
        else:
            r=by_id[entry['buffer_id']]
            raw=np.frombuffer(data[r.dataOffset:r.dataOffset+r.dataSize],dtype=np.uint8).reshape(r.height,r.width)
            if np.any((raw >> 6)!=3): raise ValueError('Unexpected nonopaque AGNB pixels')
            image=np.stack([(raw&3)*85,((raw>>2)&3)*85,((raw>>4)&3)*85],axis=2)
        expected=np.array(Image.open(folder/entry['png']).convert('RGB'))
        if not np.array_equal(image,expected): raise ValueError(f"AGNB/PNG mismatch: {entry['name']}")
        images[entry['name']]=image
    result=np.zeros((384,512,3),dtype=np.uint8)
    coverage=np.zeros((384,512),dtype=np.uint16)
    for op in manifest['operations']:
        if op['op']=='fill':
            x0,y0,x1,y1=op['box']
            if not(0<=x0<x1<=512 and 0<=y0<y1<=384): raise ValueError('Fill out of bounds')
            result[y0:y1,x0:x1]=op['color'];coverage[y0:y1,x0:x1]+=1
        else:
            a=images[op['asset']];h,w=a.shape[:2]
            for i in range(op.get('count',1)):
                x,y=op['at'];dx,dy=op.get('step',[0,0]);x+=i*dx;y+=i*dy
                if not(0<=x<x+w<=512 and 0<=y<y+h<=384): raise ValueError('Bitmap out of bounds')
                result[y:y+h,x:x+w]=a;coverage[y:y+h,x:x+w]+=1
    if np.any(coverage==0): raise ValueError('Uncovered pixels')
    static=result.copy()
    overlay=np.array(Image.open(folder/'demo-overlay.png').convert('RGBA'))
    if not np.isin(overlay[:,:,3],[0,255]).all(): raise ValueError('Fractional alpha')
    mask=overlay[:,:,3]==255
    result[mask]=overlay[:,:,:3][mask]
    if np.any(result%85): raise ValueError('Off-palette reconstruction')
    return result,static,{'uncovered_pixels':0,'overdraw_pixels':int((coverage>1).sum()),'agnb_records_checked':len(records)}


def main():
    p=argparse.ArgumentParser();p.add_argument('folder',type=Path)
    p.add_argument('--utils',type=Path,default=Path('/home/smith/Agon/mystuff/agon-utils'))
    args=p.parse_args()
    result,static,report=reconstruct(args.folder,args.utils)
    expected=np.array(Image.open(args.folder/'preview.png').convert('RGB'))
    expected_static=np.array(Image.open(args.folder/'static.png').convert('RGB'))
    if not np.array_equal(result,expected) or not np.array_equal(static,expected_static):
        raise ValueError('Independent reconstruction differs from review image')
    print(json.dumps({'pass':True,**report},indent=2))


if __name__=='__main__': main()

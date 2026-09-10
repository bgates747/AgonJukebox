"""Focused invariants and corruption checks for the saved reconstruction."""

import argparse
import json
from pathlib import Path
import shutil
import tempfile

import numpy as np
from PIL import Image

from refine import refine
from render import reconstruct
from toolkit import canonical, sha


def main():
    p=argparse.ArgumentParser();p.add_argument('folder',type=Path)
    p.add_argument('--source',type=Path,required=True)
    p.add_argument('--utils',type=Path,default=Path('/home/smith/Agon/mystuff/agon-utils'))
    args=p.parse_args();folder=args.folder.resolve()
    params=json.loads((folder/'resolved-parameters.json').read_text())
    assert sha(args.source)==params['source_sha256']
    original=np.array(Image.open(args.source).convert('RGB'))
    actual,static,coverage=reconstruct(folder,args.utils)
    expected=np.array(Image.open(folder/'preview.png').convert('RGB'))
    assert actual.shape==(384,512,3) and np.array_equal(actual,expected)
    twice,_=refine(actual,params)
    assert np.array_equal(twice,actual), 'Repeated refinement must not drift'
    for region in params.get('protect_art',[]):
        x0,y0,x1,y1=region['box']
        assert np.array_equal(actual[y0:y1,x0:x1],original[y0:y1,x0:x1])
    for region in params.get('icon_rois',[]):
        x0,y0,x1,y1=region['box'];before=original[y0:y1,x0:x1]
        symbol=np.all(before>=85,axis=2)
        assert np.array_equal(actual[y0:y1,x0:x1][symbol],before[symbol]), 'A source symbol pixel was lost'
    for path in list((folder/'assets').glob('*.png'))+[folder/'preview.png',folder/'static.png',folder/'demo-overlay.png']:
        a=np.array(Image.open(path).convert('RGBA'))
        assert np.all(a[:,:,:3]%85==0) and np.isin(a[:,:,3],[0,255]).all()
    _,viewer,_=canonical(args.utils)
    data,records=viewer.parse_container(folder/'graphics.agnb')
    rejected=[]
    with tempfile.TemporaryDirectory(prefix='skin012-verify-') as work:
        work=Path(work)
        shutil.copytree(folder,work/'candidate')
        trial=work/'candidate'
        corrupt=bytearray(data);corrupt[records[0].dataOffset]^=1
        (trial/'graphics.agnb').write_bytes(corrupt)
        try: reconstruct(trial,args.utils)
        except ValueError: rejected.append('corrupt AGNB pixel')
        else: raise AssertionError('Corruption was accepted')
        (trial/'graphics.agnb').write_bytes(data)
        manifest=json.loads((trial/'manifest.json').read_text())
        op=next(o for o in manifest['operations'] if o['op']=='bitmap')
        op['at']=[512,384]
        (trial/'manifest.json').write_text(json.dumps(manifest))
        try: reconstruct(trial,args.utils)
        except ValueError: rejected.append('out-of-bounds placement')
        else: raise AssertionError('Invalid placement was accepted')
    print(json.dumps({'pass':True,'reconstruction':coverage,'palette_and_dimensions':'pass',
                      'idempotent_refinement':'pass','original_symbols_preserved':'pass',
                      'source_sha256':sha(args.source),'rejected':rejected},indent=2))


if __name__=='__main__':main()

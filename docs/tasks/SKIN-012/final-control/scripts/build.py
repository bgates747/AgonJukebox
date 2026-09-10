"""Build a reviewable Art Deco reconstruction; never modify source artwork."""

import argparse
from collections import Counter
import hashlib
import json
from pathlib import Path
import shutil
import sys

import agonutils
import numpy as np
from PIL import Image, ImageDraw, __version__ as pillow_version
import scipy

from extract import extract
from refine import palette_check, refine
from render import reconstruct
from toolkit import ROOT, canonical, sha


def write_json(path,value):
    path.write_text(json.dumps(value,indent=2)+'\n')


def save_png(path,a):
    palette_check(a[:,:,:3])
    Image.fromarray(a).save(path)
    with Image.open(path) as saved:
        if saved.size!=(a.shape[1],a.shape[0]): raise ValueError('Saved dimensions changed')
        if not np.array_equal(np.array(saved),a): raise ValueError('Saved pixels changed')


def costs(assets,ops,container_bytes,overlay):
    uploaded=[a for a in assets if 'derive' not in a]
    derived=[a for a in assets if 'derive' in a]
    payload=sum(a['width']*a['height'] for a in uploaded)
    resident=sum(a['width']*a['height'] for a in assets)
    # Pinned agnb_api.inc: clear(6), bounded write(8+N), consolidate(6),
    # select(5), bitmap create(8); caller's canonical I/O buffer is 8192 bytes.
    overhead=sum(25+8*((a['width']*a['height']+8191)//8192) for a in uploaded)
    # Copy one consolidated source by value (10), reverse within rows (9),
    # then select/create bitmap (13): 32 command bytes per mirrored variant.
    derive_commands=32*len(derived)
    draws=0;fills=0;selections=0;last=None
    for op in ops:
        if op['op']=='fill': fills+=1
        else:
            if op['asset']!=last: selections+=1;last=op['asset']
            draws+=op.get('count',1)
    commands=fills*15+draws*6+selections*5
    repeated=Counter(o['asset'] for o in ops if o['op']=='repeat')
    mapped=[a['name'] for a in assets if a['name'] in repeated and a['width']==8 and a['height']<=16]
    return {
        'kind':'Host payload measurements and protocol model; no target execution',
        'baseline_full_static_rgba2222_bytes':512*384,
        'unique_rgba2222_payload_bytes':payload,
        'pixel_payload_reduction_percent':round(100*(1-payload/(512*384)),2),
        'agnb_bytes':container_bytes,'agnb_overhead_bytes':container_bytes-payload,
        'bitmap_records':len(uploaded),'resident_bitmap_buffers':len(assets),
        'derived_mirrored_buffers':len(derived),'mirror_creation_tx_bytes':derive_commands,
        'asset_upload_tx_bytes':payload+overhead+derive_commands,'asset_upload_protocol_overhead_bytes':overhead,
        'raw_full_frame_upload_tx_bytes':512*384+25+8*24,
        'vdp_pixel_storage_bytes':resident,
        'stored_static_draw_sequence_bytes':commands,
        'vdp_pixels_plus_stored_commands_bytes':resident+commands,
        'static_draw_bitmap_placements':draws,'static_draw_fills':fills,
        'static_draw_bitmap_selections':selections,'unbuffered_static_draw_tx_bytes':commands,
        'stored_static_draw_upload_tx_bytes':commands+6+8*((commands+8191)//8192),
        'stored_static_redraw_call_tx_bytes':6,
        'selected_static_strategy':'One stored direct-bitmap/fill sequence; mirrored buffers built once by copy/reverse at loading (modeled, not deployed)',
        'mapped_character_codes_assigned':0,'horizontal_print_candidates':mapped,
        'demo_overlay_bytes_not_in_runtime_package':int(overlay[:,:,3].astype(bool).sum()),
        'excluded':'VDP object/allocator metadata, MOS↔VDP mode packets, common setup/context commands, application fonts and changing-text traffic. These costs require the integration task; the demo overlay is host-only.',
        'normal_playback':'Static chrome is drawn on entry or restoration, not on each playback tick. Current application dynamic-widget traffic is not changed or measured here.'
    }


def main():
    p=argparse.ArgumentParser()
    p.add_argument('--params',type=Path,required=True)
    p.add_argument('--out',type=Path,required=True)
    p.add_argument('--utils',type=Path,default=Path('/home/smith/Agon/mystuff/agon-utils'))
    args=p.parse_args();out=args.out.resolve()
    if out.exists(): raise SystemExit(f'Refusing to overwrite {out}')
    params=json.loads(args.params.read_text())
    source=(args.params.resolve().parent/params['source']).resolve()
    source_hash=sha(source)
    if source_hash!=params['source_sha256']: raise ValueError('Source hash changed')
    source_pixels=np.array(Image.open(source).convert('RGB'))
    if source_pixels.shape!=(384,512,3): raise ValueError('Wrong source dimensions')
    palette_check(source_pixels)
    versions={'numpy':np.__version__,'scipy':scipy.__version__,'Pillow':pillow_version}
    lock=json.loads((ROOT/'toolchain.json').read_text())
    if versions!=lock['versions']: raise ValueError('Dependency versions differ from toolchain lock')
    writer,viewer,palette=canonical(args.utils)
    out.mkdir(parents=True);(out/'assets').mkdir()
    (out/'scripts').mkdir()
    for path in ROOT.glob('*.py'):
        shutil.copy2(path,out/'scripts'/path.name)
    shutil.copy2(ROOT/'toolchain.json',out/'scripts'/'toolchain.json')
    shutil.copy2(args.params,out/'parameters.json')
    candidate,changes=refine(source_pixels,params)
    ex,static,overlay=extract(candidate,params)
    entries=[];records=[]
    for i,a in enumerate(ex.assets):
        pixels=a.pop('pixels');h,w=pixels.shape[:2];name=a['name']
        png=out/'assets'/f'{name}.png';rgba=png.with_suffix('.rgba2')
        save_png(png,pixels)
        agonutils.img_to_rgba2(str(png),str(rgba),str(palette),'RGB',None)
        if rgba.stat().st_size!=w*h: raise ValueError('Unexpected packed pixel size')
        buffer_id=0x3000+i
        entry={**a,'buffer_id':buffer_id,'width':w,'height':h,'png':str(png.relative_to(out)),
               'rgba2':str(rgba.relative_to(out)),'rgba2_sha256':sha(rgba)}
        entries.append(entry)
        if 'derive' not in entry:
            records.append(writer.ImageRecord('SKIN-012 scripted extraction',name,buffer_id,w,h,rgba,w*h))
    container=writer.build_container(records);(out/'graphics.agnb').write_bytes(container)
    _,parsed=viewer.parse_container(out/'graphics.agnb')
    assert len(parsed)==len(records)
    manifest={'format':'skin012-host-proof-1','size':[512,384],'parameters':params['name'],
              'assets':entries,'operations':ex.operations,'demo_overlay':'demo-overlay.png',
              'notice':'Study manifest, not production skin.cfg. Asset IDs are explicit study IDs.'}
    write_json(out/'manifest.json',manifest)
    save_png(out/'demo-overlay.png',overlay)
    result,saved_static,validation=reconstruct(out,args.utils)
    if not np.array_equal(result,candidate): raise ValueError('Asset reconstruction changed candidate pixels')
    if not np.array_equal(saved_static,static): raise ValueError('Static reconstruction differs')
    save_png(out/'preview.png',result);save_png(out/'static.png',saved_static)
    diff=np.any(source_pixels!=result,axis=2)
    allowed=np.zeros((384,512),dtype=bool)
    for region in params['axis_regions']+params['bevels']:
        x0,y0,x1,y1=region['box'];allowed[y0:y1,x0:x1]=True
    for region in params['mirrors']:
        x0,y0,x1,y1=region['source'];x,y=region['target']
        allowed[y:y+y1-y0,x:x+x1-x0]=True
    if np.any(diff & ~allowed): raise ValueError('Unrecorded artwork changes outside declared regions')
    difference=source_pixels.copy();difference[diff]=[255,0,255]
    save_png(out/'differences.png',difference)
    save_png(out/'changed-mask.png',np.repeat((diff[:,:,None]*255).astype(np.uint8),3,axis=2))
    comparison=np.concatenate((source_pixels,result,difference),axis=1)
    save_png(out/'comparison.png',comparison)
    column=np.concatenate((source_pixels[:344,:68],result[:344,:68],difference[:344,:68]),axis=1)
    save_png(out/'column-comparison.png',np.repeat(np.repeat(column,3,axis=0),3,axis=1))
    # Native asset contact sheet with palette-safe bitmap labels.
    tiles=Image.new('RGB',(640,((len(entries)+7)//8)*90),(0,0,0));draw=ImageDraw.Draw(tiles)
    for i,entry in enumerate(entries):
        x=(i%8)*80;y=(i//8)*90
        tiles.paste(Image.open(out/entry['png']),(x,y))
        draw.text((x,y+65),f"{i}: {entry['width']}x{entry['height']}",fill=(255,255,255),font_size=8)
    # Pillow's diagnostic text can be antialiased; snap the contact sheet too.
    sheet=(np.floor(np.array(tiles,dtype=float)/85+0.5)*85).clip(0,255).astype(np.uint8)
    save_png(out/'asset-sheet.png',sheet)
    report=costs(entries,ex.operations,len(container),overlay)
    report['changes']=changes
    report['changed_pixels']=int(diff.sum());report['changed_percent']=round(100*diff.mean(),3)
    report['validation']={**validation,'source_sha256_unchanged':sha(source)==source_hash,
                          'size':[512,384],'unique_colors':len(np.unique(result.reshape(-1,3),axis=0)),
                          'off_palette_pixels':0,'reconstruction_matches_candidate':True,
                          'changes_outside_declared_regions':0}
    report['provenance']={'freeze_commit':'f2f252d','source_sha256':source_hash,'toolchain':lock,
                          'scripts':{f.name:sha(f) for f in ROOT.glob('*.py')},'parameters_sha256':sha(args.params)}
    write_json(out/'report.json',report)
    print(json.dumps({k:report[k] for k in ('unique_rgba2222_payload_bytes','pixel_payload_reduction_percent','bitmap_records','changed_pixels','changed_percent','asset_upload_tx_bytes','stored_static_draw_sequence_bytes')},indent=2))


if __name__=='__main__': main()

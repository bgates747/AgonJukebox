"""Build the bounded Art Deco skin using the existing font and AGNB tools.

Run with the project's .venv. Generated files may be rebuilt; source.png/svg
and the Author's font are immutable inputs. --output-root permits a separate
repeat build without touching the application or emulator deployment.
"""
from __future__ import annotations

import argparse
import hashlib
import importlib.util
import json
from pathlib import Path
import shutil
import struct
import sys
import tempfile

from PIL import Image, ImageDraw
import agonutils as au

SOURCE = Path(__file__).resolve().parent
PROJECT = SOURCE.parents[2]
UTILS = PROJECT.parent / "agon-utils"
BLACK = (0, 0, 0)
TEXT = (255, 255, 170)
GOLD = (255, 170, 85)
CYAN = (0, 170, 170)
# Stock mode-20 logical palette, from agon_palette.h defaultPalette40.
PALETTE = [0,32,8,40,2,34,10,42,21,48,12,60,3,51,15,63,
           1,4,5,6,7,9,11,13,14,16,17,18,19,20,22,23,
           24,25,26,27,28,29,30,31,33,35,36,37,38,39,41,43,
           44,45,46,47,49,50,52,53,54,55,56,57,58,59,61,62]


def module(name, path):
    spec = importlib.util.spec_from_file_location(name, path)
    value = importlib.util.module_from_spec(spec)
    sys.modules[name] = value
    spec.loader.exec_module(value)
    return value


# VDU encoders promoted from the existing SKIN-000 traffic proof.
def word(n): return struct.pack('<H', n)
def xy(x, y): return struct.pack('<hh', x, y)
def context(n): return bytes([23, 0, 0xc8, 0, n])
def font(n): return bytes([23, 0, 0x95, 0]) + word(n) + b'\0'
def move(x, y): return bytes([25, 4]) + xy(x, y)
def colour(rgb): return PALETTE.index(rgb[0]//85*16 + rgb[1]//85*4 + rgb[2]//85)
def gcol(rgb): return bytes([18, 0, colour(rgb)])
def fill(x, y, w, h, rgb): return gcol(rgb) + move(x, y) + bytes([25, 101]) + xy(x+w-1, y+h-1)
def clear_buffer(n): return bytes([23, 0, 0xa0]) + word(n) + b'\2'
def sha(data): return hashlib.sha256(data).hexdigest()


def build(output: Path):
    source = SOURCE / 'source.png'
    if sha(source.read_bytes()) != '8b61a2b393284fa777b15a78ac34c7e1f218fc06c58234fdb9f7f9fd60b3e8b4':
        raise ValueError('accepted source.png changed; review and update its provenance explicitly')
    im = Image.open(source).convert('RGB')
    assert im.size == (512, 384)
    assert all(all(c in (0,85,170,255) for c in rgb) for rgb in im.get_flattened_data())
    original = im.copy()
    draw = ImageDraw.Draw(im)
    # Clear the concept's sample content and selected row, preserving its frame.
    for rect in [(80,74,432,85), (80,87,432,224), (139,250,374,278),
                 (20,354,145,370), (350,354,491,370)]:
        draw.rectangle(rect, fill=BLACK)
    for row in range(10):
        draw.line((82, 101+row*12, 430, 101+row*12), fill=(85,85,0))

    editor = UTILS / 'examples/font_editor/src/python'
    sys.path.insert(0, str(editor))
    from config_manager import load_font_metadata_from_xml
    from agon_font import read_font, get_chars_from_image
    font_path = PROJECT / 'src/fonts/neutrino_5x8.font'
    cfg = load_font_metadata_from_xml(str(font_path)+'.xml')
    cfg, sheet = read_font(str(font_path), cfg)
    assert (cfg['font_width_mod'], cfg['font_height_mod']) == (5,8)
    assert len(font_path.read_bytes()) == 2048
    glyphs = get_chars_from_image(cfg, sheet)
    playlist_font = PROJECT / 'src/fonts/terminus/Lat7-Terminus12x6_6x12.font'
    playlist_cfg = load_font_metadata_from_xml(str(playlist_font)+'.xml')
    playlist_cfg, playlist_sheet = read_font(str(playlist_font), playlist_cfg)
    assert (playlist_cfg['font_width_mod'], playlist_cfg['font_height_mod']) == (6,12)
    assert len(playlist_font.read_bytes()) == 3072
    playlist_glyphs = get_chars_from_image(playlist_cfg, playlist_sheet)

    manifest_path = UTILS / 'examples/agnb/images/shared/scripts/image_manifest.py'
    writer_path = UTILS / 'examples/agnb/images/container/scripts/do_assembly.py'
    viewer_path = UTILS / 'examples/agnb/images/container/scripts/view_agnb.py'
    manifest = module('image_manifest', manifest_path)
    writer = module('artdeco_agnb_writer', writer_path)
    viewer = module('artdeco_agnb_viewer', viewer_path)
    package = output / 'skins/artdeco'
    ui = output / 'src/ui/artdeco'
    review = output / 'src/skins/artdeco/generated'
    for directory in [package/'fonts', ui, review]:
        directory.mkdir(parents=True, exist_ok=True)
    shutil.copyfile(font_path, package/'fonts/neutrino_5x8.font')
    shutil.copyfile(playlist_font, package/'fonts/Lat7-Terminus12x6_6x12.font')
    (package/'skin.cfg').write_text('format=artdeco-test2\ngraphics.file=graphics.agnb\nfont.file=fonts/neutrino_5x8.font\nplaylist.font.file=fonts/Lat7-Terminus12x6_6x12.font\n')

    assets = []
    by_name = {}
    entries = []
    placements = []
    with tempfile.TemporaryDirectory(prefix='artdeco-agnb-') as temp:
        scratch = Path(temp)

        def asset(name, image, role):
            image = image.convert('RGBA')
            assert len(assets) < 240, 'image IDs would collide with font 0x21f0'
            buffer_id = 0x2100 + len(assets)
            code = 128+len(assets) if len(assets) < 128 else None
            png, raw = scratch/(name+'.png'), scratch/(name+'.rgba2')
            image.save(png)
            au.img_to_rgba2(str(png), str(raw), str(editor/'colors/Agon64.gpl'), 'RGB', None)
            restored = scratch/(name+'-restored.png')
            au.rgba2_to_img(str(raw), str(restored), image.width, image.height)
            assert Image.open(restored).convert('RGBA').tobytes() == image.tobytes()
            entry = manifest.ImageManifestEntry(True, role, name, buffer_id,
                image.width, image.height, 1, png.name, raw.name, raw.stat().st_size)
            entries.append(entry)
            result = {'name':name, 'id':buffer_id, 'code':code, 'width':image.width,
                      'height':image.height, 'role':role, 'sha256':sha(raw.read_bytes()),
                      'image':image}
            assets.append(result)
            by_name[name] = result
            return result

        # Opaque widget states restore their own background and border.
        transport = original.crop((122,307,214,336))
        asset('idle', transport, 'play/pause feedback')
        for name, active in [('pause',(4,5,39,24)), ('play',(55,5,86,24))]:
            state = transport.copy()
            state_draw = ImageDraw.Draw(state)
            state_draw.rectangle(active, fill=CYAN)
            # Preserve the original button symbol above the active field.
            mask = transport.convert('RGB')
            for y in range(active[1],active[3]+1):
                for x in range(active[0],active[2]+1):
                    if mask.getpixel((x,y)) == TEXT:
                        state.putpixel((x,y), TEXT)
            asset(name, state, 'play/pause feedback')
        for name, rect in [('shuffle',(266,307,305,336)), ('loop',(308,307,349,336))]:
            state = original.crop(rect)
            asset(name+'_off', state, name+' feedback')
            active = state.copy()
            active.putdata([CYAN if rgb == GOLD else rgb for rgb in state.get_flattened_data()])
            asset(name+'_on', active, name+' feedback')
        for level in range(12):
            state = original.crop((368,307,435,336))
            d = ImageDraw.Draw(state)
            d.rectangle((21,6,60,23), fill=BLACK)
            for bar in range(level):
                x = 22 + bar*3
                d.rectangle((x,22-bar, x+1,23), fill=CYAN)
            asset('volume_'+str(level), state, 'volume feedback')
        progress = Image.new('RGB',(230,10),BLACK)
        d = ImageDraw.Draw(progress)
        d.rectangle((0,0,229,9), outline=TEXT)
        d.rectangle((1,1,228,8), outline=(85,85,0))
        asset('progress_track', progress, 'progress background')
        asset('progress_marker', Image.new('RGB',(7,6),GOLD), 'progress marker')

        # Deduplicate exact 32x32 decorative tiles; blank tiles are free fills.
        tiles = {}
        for y in range(0,384,32):
            for x in range(0,512,32):
                tile = im.crop((x,y,x+32,y+32))
                if not tile.getbbox():
                    continue
                key = tile.tobytes()
                if key not in tiles:
                    tiles[key] = asset('tile_'+str(len(tiles)).zfill(3), tile, 'static decoration')
                placements.append({'name':tiles[key]['name'], 'x':x, 'y':y})
        manifest.write_manifest(scratch/'images.jsonl', entries)
        manifest.validate_asset_files(entries, scratch)
        records = [writer.ImageRecord(e.source,e.name,e.bufferId,e.width,e.height,
                   scratch/e.rgba2,e.dataSize) for e in entries]
        packed = writer.build_container(records)
        (package/'graphics.agnb').write_bytes(packed)
        data, parsed = viewer.parse_container(package/'graphics.agnb')
        assert len(parsed) == len(entries)
        for r,e in zip(parsed, entries):
            assert (r.bufferId,r.width,r.height,r.dataSize) == (e.bufferId,e.width,e.height,e.dataSize)
            assert data[r.dataOffset:r.dataOffset+r.dataSize] == (scratch/e.rgba2).read_bytes()

    reconstructed = Image.new('RGB',(512,384),BLACK)
    for p in placements:
        reconstructed.paste(by_name[p['name']]['image'], (p['x'],p['y']))
    assert reconstructed.tobytes() == im.tobytes()
    reconstructed.save(review/'backdrop.png')
    meta = b''.join(struct.pack('<HHHBI',a['id'],a['width'],a['height'],1,a['width']*a['height']) for a in assets)
    (ui/'image-meta.bin').write_bytes(meta)

    def put_asset(a,x,y):
        if a['code'] is None:
            return bytes([23,27,32])+word(a['id'])+bytes([25,237])+xy(x,y)
        return move(x,y+a['height']-8)+bytes([a['code']])

    # Native coordinates, graphics cursor, transparent text; separate art bank.
    common = context(1)+bytes([23,0,200,2,79,5,23,0,192,0,23,16,64,0])+font(0x21f0)+bytes([23,1,0])
    mapping = b''.join(bytes([23,0,146,a['code']])+word(a['id']) for a in assets if a['code'] is not None)
    contexts = common+bytes([23,0,200,1,2])+context(2)+font(65535)+mapping+context(1)
    (ui/'contexts.vdu').write_bytes(contexts)
    static = context(1)+fill(0,0,512,384,BLACK)+context(2)
    static += b''.join(put_asset(by_name[p['name']],p['x'],p['y']) for p in placements)
    static += context(1)+font(0x21f0)
    (ui/'static.vdu').write_bytes(static)
    cleanup = context(0)+font(65535)+bytes([23,0,200,1,1,23,0,200,1,2])
    cleanup += bytes([23,0,149,4])+word(0x21f0)
    cleanup += bytes([23,0,149,4])+word(0x21f1)
    cleanup += b''.join(clear_buffer(a['id']) for a in assets)+clear_buffer(0x21f0)+clear_buffer(0x21f1)+clear_buffer(0x2200)
    (ui/'cleanup.vdu').write_bytes(cleanup)

    generated = ['; Generated by src/skins/artdeco/build.py.']
    specs = {}
    def packet(name, data, slots):
        assert 0 < len(data) <= 96, (name,len(data))
        generated.append(name+':')
        for start in range(0,len(data),24):
            generated.append('    db '+','.join(map(str,data[start:start+24])))
        generated.extend([f'{name}_end:',f'{name}_len: equ {len(data)}'])
        generated.extend(f'{name}_{label}: equ {name}+{offset}' for label,offset in slots.items())
        generated.extend([name+'_send:',f'    ld hl,{name}',f'    ld bc,{name}_len','    jp ui_send'])

    def text_widget(name,x,y,n,bg=BLACK,fg=TEXT,rect=None,slot='text',cell=(5,8)):
        width,height = cell
        rect = rect or (x,y,n*width,height)
        assert x >= rect[0] and y >= rect[1]
        assert x+n*width <= rect[0]+rect[2] and y+height <= rect[1]+rect[3]
        data = context(1)+font(0x21f1 if cell == (6,12) else 0x21f0)
        slots = {'bg':len(data)+2}
        data += fill(*rect,bg)
        slots['fg'] = len(data)+2
        data += gcol(fg)+move(x,y)
        slots[slot] = len(data)
        packet(name,data+b' '*n,slots)
        specs[name] = {'kind':'text','x':x,'y':y,'n':n,'bg':bg,'fg':fg,'rect':rect,'cell':cell}

    def art_widget(name, asset_name,x,y):
        a = by_name[asset_name]
        data = context(2)
        slots = {'x':len(data)+2,'code':len(data)+6}
        data += put_asset(a,x,y)+context(1)
        packet(name,data,slots)
        specs[name] = {'kind':'art','x':x,'y':y,'asset':asset_name}

    text_widget('w_path',85,76,48)
    text_widget('w_page',366,76,13)
    for row in range(10):
        text_widget('w_row'+str(row),82,88+row*12,58,rect=(81,88+row*12,350,12),cell=(6,12))
    generated += ['ui_rows:']+[f'    dl w_row{n},w_row{n}_text' for n in range(10)]
    text_widget('w_message',100,215,48,fg=GOLD)
    text_widget('w_track',146,251,44)
    text_widget('w_elapsed',183,267,8,slot='digits')
    text_widget('w_duration',289,267,8,slot='digits')
    text_widget('w_detail',24,359,23)
    text_widget('w_voltext',388,359,13)
    art_widget('w_play','idle',122,307)
    art_widget('w_shuffle','shuffle_off',266,307)
    art_widget('w_loop','loop_off',308,307)
    art_widget('w_volume','volume_11',368,307)
    art_widget('w_progress','progress_track',141,280)
    art_widget('w_marker','progress_marker',143,282)
    # Existing event producers retain these fields; no hints/extra icons draw.
    generated += ['w_hint_text: blkb 15,32','w_hint_send: ret',
                  'w_mode_code: db 0','w_mode_send: ret',
                  'w_thumb_x: dw 0','w_thumb_send: ret',
                  'ui_volume_x: blkb 12,0']
    generated.append('ui_volume_codes: db '+','.join(str(by_name['volume_'+str(n)]['code']) for n in range(12)))
    for name in ['idle','play','pause','shuffle_off','shuffle_on','loop_off','loop_on']:
        generated.append(f'art_{name}: equ {by_name[name]["code"]}')
    generated += ['art_playing: equ art_pause','art_paused: equ art_play',
                  'ui_row_columns: equ 58',f'ui_normal_fg: equ {colour(TEXT)}',f'ui_selected_bg: equ {colour(GOLD)}',
                  'ui_selected_fg: equ 0','ui_progress_origin: equ 143','ui_idle_play_code: equ art_idle',
                  f'sa_image_count: equ {len(assets)}']
    for label,filename in [('sa_image_meta','image-meta.bin'),('sa_contexts','contexts.vdu'),
                           ('sa_cleanup','cleanup.vdu'),('ui_static','static.vdu')]:
        generated += [f'{label}: incbin "../ui/artdeco/{filename}"',f'{label}_end:']
    (ui/'widgets.inc').write_text('\n'.join(generated)+'\n')

    def preview(fields):
        result = reconstructed.copy()
        for name,spec in specs.items():
            if name == 'w_marker' and not fields.get('active',False):
                continue
            x,y = spec['x'],spec['y']
            if spec['kind'] == 'art':
                art = by_name[fields.get(name,spec['asset'])]['image']
                if name == 'w_marker':
                    x += fields.get('progress',0)
                result.paste(art,(x,y))
                continue
            bg,fg = spec['bg'],spec['fg']
            if name == 'w_row'+str(fields.get('selected',0)):
                bg,fg = GOLD,BLACK
            rx,ry,rw,rh = spec['rect']
            ImageDraw.Draw(result).rectangle((rx,ry,rx+rw-1,ry+rh-1),fill=bg)
            value = fields.get(name,'')[:spec['n']].ljust(spec['n'])
            width,height = spec['cell']
            chars = playlist_glyphs if spec['cell'] == (6,12) else glyphs
            for index,char in enumerate(value):
                mask = chars[ord(char)].convert('L').crop((0,0,width,height))
                result.paste(fg,(x+index*width,y,x+index*width+width,y+height),mask)
        return result

    example = {'w_path':'/music/Albums','w_page':'01 OF 01','selected':3,
        'w_track':'PLAYING Led_Zeppelin__Physical_Graffiti.wav',
        'w_message':'Ready','w_elapsed':'00:01:26','w_duration':'01:22:15',
        'w_detail':'RATE 32000 Hz','w_voltext':'VOL 11','w_play':'pause',
        'w_shuffle':'shuffle_on','active':True,'progress':4}
    for index,name in enumerate(['<DIR> Boston','<DIR> Led Zeppelin','Boston__Boston.wav',
            'Led_Zeppelin__Physical_Graffiti.wav','Pink_Floyd__The_Wall.wav',
            'The_Cars__Heartbeat_City.wav','Wild_Flower.wav']):
        example['w_row'+str(index)] = f'{index:02d} '+name
    preview(example).save(review/'preview.png')

    # Paused state reached by case16 of the existing target suite. Elapsed and
    # marker pixels are excluded: timer scheduling intentionally varies by host.
    target = {'w_path':'/qualification/Play','w_page':'01 OF 02','selected':0,
        'w_track':'PAUSED  00_Long_65535.wav','w_message':'Loop current song; Shuffle setting retained',
        'w_duration':'00:00:04','w_detail':'RATE 65535 Hz','w_voltext':'VOL 10',
        'w_play':'play','w_shuffle':'shuffle_on','w_loop':'loop_on','w_volume':'volume_10'}
    for index in range(10):
        target['w_row'+str(index)] = f'{index:02d} {index:02d}_'+('Long_65535.wav' if index==0 else 'Short_8000.wav')
    expected = preview(target)
    expected.save(review/'test-paused.png')
    points = {(x,y) for y in range(0,384,9) for x in range(0,512,11)}
    for spec in specs.values():
        if spec['kind']=='text' and spec['n'] != 8:
            # Native glyphs and their blank spacing, not just field backgrounds.
            width,height = spec['cell']
            for y in range(spec['y'],spec['y']+height):
                for x in range(spec['x'],spec['x']+min(16,spec['n'])*width,3):
                    points.add((x,y))
    points = sorted((x,y) for x,y in points if not (180<=x<225 and 266<=y<276) and not (140<=x<372 and 279<=y<291))
    payload = b''.join(xy(x,y)+bytes(expected.getpixel((x,y))) for x,y in points)
    fixture = output/'tests/fixtures/artdeco/widget-samples.bin'
    fixture.parent.mkdir(parents=True,exist_ok=True)
    fixture.write_bytes(payload)
    (ui/'test-meta.inc').write_text(f'lt_sample_count: equ {len(points)}\n')
    info = {'format':'artdeco-authoring-test1','source_sha256':sha(source.read_bytes()),
        'builder_sha256':sha(Path(__file__).read_bytes()),
        'font_sha256':sha(font_path.read_bytes()),'source_svg_sha256':sha((SOURCE/'source.svg').read_bytes()),
        'playlist_font_sha256':sha(playlist_font.read_bytes()),
        'screen':[512,384],'font_cell':[5,8],'playlist_font_cell':[6,12],'browser_columns':58,'browser_rows':10,
        'control_legends':False,'placements':placements,'widgets':specs,
        'assets':[{k:v for k,v in a.items() if k!='image'} for a in assets],
        'image_count':len(assets),'unique_backdrop_tiles':len(tiles),'backdrop_placements':len(placements),
        'bitmap_payload_bytes':sum(a['width']*a['height'] for a in assets),
        'agnb_bytes':len(packed),'font_bytes':5120,'static_command_bytes':len(static),
        'test_pixels':len(points),'agnb_sha256':sha(packed),
        'tool_hashes':{str(p.relative_to(UTILS)):sha(p.read_bytes()) for p in [manifest_path,writer_path,viewer_path,editor/'agon_font.py']},
        'checks':['Agon palette','exact font dimensions','RGBA2222 round trips',
                  'canonical manifest validation','independent AGNB record/payload validation',
                  'exact tiled backdrop reconstruction','bounded widget packets <=96 bytes']}
    (review/'build.json').write_text(json.dumps(info,indent=2)+'\n')
    print(json.dumps({k:info[k] for k in ['image_count','unique_backdrop_tiles','backdrop_placements',
        'bitmap_payload_bytes','agnb_bytes','font_bytes','static_command_bytes','test_pixels']},indent=2))


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--output-root', type=Path, default=PROJECT)
    args = parser.parse_args()
    build(args.output_root.resolve())

"""Build the bounded 70s skin using the existing font and AGNB tools.

Run with the project's .venv. Generated files may be rebuilt; source.png
and the existing fonts are immutable inputs. --output-root permits a separate
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
BG = (85, 0, 0)
ROW_Y = [90,103,117,130,144,157,171,184,198,211]
TEXT = (255, 255, 170)
GOLD = (255, 170, 0)
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
    assert sha(source.read_bytes()) == 'a1082a8ddc0e6ea3f3ee36036e21948cdceab1572c5427299e06f793fe80f5ee'
    im = Image.open(source).convert('RGB')
    assert im.size == (512,384) and all(all(c%85==0 for c in pixel) for pixel in im.get_flattened_data())
    original = im.copy()
    draw = ImageDraw.Draw(im)
    # Remove the baked highlight and normalize blank row interiors/rules.
    draw.rectangle((80,87,432,223),fill=BG)
    for y in ROW_Y: draw.line((80,y+12,432,y+12),fill=TEXT)
    # Restore the frame under the baked selection arrow from a clean scanline.
    for y in range(124,145):
        for x in range(65,82): im.putpixel((x,y),original.getpixel((x,112)))
    # Runtime supplies these progress/status fields, including the slash.
    draw.rectangle((139,281,374,291),fill=BG)

    editor = UTILS / 'examples/font_editor/src/python'
    sys.path.insert(0, str(editor))
    from config_manager import load_font_metadata_from_xml
    from agon_font import read_font, read_png_font, write_agon_font, get_chars_from_image
    font_path = PROJECT / 'src/fonts/neutrino_5x8.font'
    cfg = load_font_metadata_from_xml(str(font_path)+'.xml')
    cfg, sheet = read_font(str(font_path), cfg)
    assert (cfg['font_width_mod'], cfg['font_height_mod']) == (5,8)
    assert len(font_path.read_bytes()) == 2048
    glyphs = get_chars_from_image(cfg, sheet)
    # Reuse the canonical editor's monochrome reader; no new font converter.
    playlist_stem = 'Lat7-Terminus12x6_6x12'
    playlist_source = PROJECT/'src/fonts/terminus'/ (playlist_stem+'.font')
    pcfg = load_font_metadata_from_xml(str(playlist_source)+'.xml')
    pcfg, psheet = read_font(str(playlist_source),pcfg)
    assert (pcfg['font_width_mod'],pcfg['font_height_mod']) == (6,12)
    pglyphs = get_chars_from_image(pcfg,psheet)
    playlist_glyphs = {}; playlist_sources = {}
    for name,bg,fg in [('normal',BG,TEXT),('selected',GOLD,BLACK)]:
        playlist_glyphs[name] = {}
        for code in range(32,127):
            img=Image.new('RGBA',(6,12),bg+(255,))
            img.paste(fg+(255,),(0,0,6,12),pglyphs[code].convert('L').crop((0,0,6,12)))
            playlist_glyphs[name][code]=img
        playlist_sources[name]=sha(b''.join(im.tobytes() for im in playlist_glyphs[name].values()))

    manifest_path = UTILS / 'examples/agnb/images/shared/scripts/image_manifest.py'
    writer_path = UTILS / 'examples/agnb/images/container/scripts/do_assembly.py'
    viewer_path = UTILS / 'examples/agnb/images/container/scripts/view_agnb.py'
    manifest = module('image_manifest', manifest_path)
    writer = module('seventies_agnb_writer', writer_path)
    viewer = module('seventies_agnb_viewer', viewer_path)
    package = output / 'skins/seventies'
    ui = output / 'src/ui/seventies'
    review = output / 'src/skins/seventies/generated'
    for directory in [package/'fonts', ui, review]:
        directory.mkdir(parents=True, exist_ok=True)
    shutil.copyfile(font_path, package/'fonts/neutrino_5x8.font')
    playlist_font = package/'fonts'/(playlist_stem+'.font')
    shutil.copyfile(playlist_source,playlist_font)
    assert len(playlist_font.read_bytes())==3072
    (package/'skin.cfg').write_text('format=seventies-test1\ngraphics.file=graphics.agnb\nfont.file=fonts/neutrino_5x8.font\n'
        f'playlist.font.file=fonts/{playlist_stem}.font\nplaylist.graphics.file=fonts/{playlist_stem}.agnb\n')

    assets = []
    by_name = {}
    entries = []
    placements = []
    playlist_assets = []
    with tempfile.TemporaryDirectory(prefix='seventies-agnb-') as temp:
        scratch = Path(temp)

        def encode_image(name, image):
            image = image.convert('RGBA')
            png, raw = scratch/(name+'.png'), scratch/(name+'.rgba2')
            image.save(png)
            au.img_to_rgba2(str(png), str(raw), str(editor/'colors/Agon64.gpl'), 'RGB', None)
            restored = scratch/(name+'-restored.png')
            au.rgba2_to_img(str(raw), str(restored), image.width, image.height)
            assert Image.open(restored).convert('RGBA').tobytes() == image.tobytes()
            return image,png,raw

        def asset(name, image, role):
            assert len(assets) < 240, 'image IDs would collide with font 0x21f0'
            buffer_id = 0x2100 + len(assets)
            code = 128+len(assets) if len(assets) < 128 else None
            image,png,raw = encode_image(name,image)
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
                    if mask.getpixel((x,y)) == BLACK:
                        state.putpixel((x,y), BLACK)
            asset(name, state, 'play/pause feedback')
        for name, rect in [('shuffle',(266,307,305,336)), ('loop',(308,307,349,336))]:
            state = original.crop(rect)
            asset(name+'_off', state, name+' feedback')
            active = state.copy()
            active.putdata([CYAN if rgb == TEXT else rgb for rgb in state.get_flattened_data()])
            asset(name+'_on', active, name+' feedback')
        for level in range(12):
            state = original.crop((368,307,435,336))
            d = ImageDraw.Draw(state)
            d.rectangle((21,6,60,23), fill=TEXT)
            for bar in range(level):
                x = 22 + bar*3
                d.rectangle((x,22-bar, x+1,23), fill=BLACK)
            asset('volume_'+str(level), state, 'volume feedback')
        progress = Image.new('RGB',(230,8),BG)
        d = ImageDraw.Draw(progress)
        d.rectangle((0,0,229,7), outline=TEXT)
        d.rectangle((1,1,228,6), outline=(85,85,0))
        asset('progress_track', progress, 'progress background')
        asset('progress_marker', Image.new('RGB',(7,6),GOLD), 'progress marker')

        pointer = Image.new('RGBA',(10,12),(0,0,0,0))
        ImageDraw.Draw(pointer).polygon([(0,0),(9,5),(9,6),(0,11)], fill=TEXT+(255,), outline=(0,0,0,255))
        asset('selection_pointer', pointer, 'selection sprite')

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
        def pack_images(records_in, path, manifest_name):
            assert 0 < len(records_in) < 256
            manifest.write_manifest(scratch/manifest_name, records_in)
            manifest.validate_asset_files(records_in, scratch)
            records = [writer.ImageRecord(e.source,e.name,e.bufferId,e.width,e.height,
                       scratch/e.rgba2,e.dataSize) for e in records_in]
            packed = writer.build_container(records)
            path.write_bytes(packed)
            data, parsed = viewer.parse_container(path)
            assert len(parsed) == len(records_in)
            for r,e in zip(parsed, records_in):
                assert (r.bufferId,r.width,r.height,r.dataSize) == (e.bufferId,e.width,e.height,e.dataSize)
                assert data[r.dataOffset:r.dataOffset+r.dataSize] == (scratch/e.rgba2).read_bytes()
            return packed

        packed = pack_images(entries,package/'graphics.agnb','images.jsonl')
        playlist_entries = []
        for variant,first_id in [('normal',0x2300),('selected',0x2400)]:
            for code,image in playlist_glyphs[variant].items():
                name = f'playlist_{variant}_{code:03d}'
                image,png,raw = encode_image(name,image)
                identifier = first_id+code-32
                playlist_entries.append(manifest.ImageManifestEntry(True,'playlist glyph',name,
                    identifier,6,12,1,png.name,raw.name,raw.stat().st_size))
                playlist_assets.append({'name':name,'id':identifier,'char':code,'variant':variant,
                    'width':6,'height':12,'sha256':sha(raw.read_bytes())})
        playlist_packed = pack_images(playlist_entries,package/'fonts'/(playlist_stem+'.agnb'),'playlist.jsonl')
        assert len({a['id'] for a in assets+playlist_assets}) == len(assets)+len(playlist_assets)

    reconstructed = Image.new('RGB',(512,384),BLACK)
    for p in placements:
        reconstructed.paste(by_name[p['name']]['image'], (p['x'],p['y']))
    assert reconstructed.tobytes() == im.tobytes()
    reconstructed.save(review/'backdrop.png')
    meta = b''.join(struct.pack('<HHHBI',a['id'],a['width'],a['height'],1,a['width']*a['height']) for a in assets)
    (ui/'image-meta.bin').write_bytes(meta)
    (ui/'playlist-meta.bin').write_bytes(b''.join(struct.pack('<HHHBI',a['id'],6,12,1,72) for a in playlist_assets))

    def put_asset(a,x,y):
        if a['code'] is None:
            return bytes([23,27,32])+word(a['id'])+bytes([25,237])+xy(x,y)
        return move(x,y+a['height']-8)+bytes([a['code']])

    # Native coordinates, graphics cursor, transparent text; separate art bank.
    common = context(1)+bytes([23,0,200,2,79,5,23,0,192,0,23,16,64,0])+font(0x21f0)+bytes([23,1,0])
    mapping = b''.join(bytes([23,0,146,a['code']])+word(a['id']) for a in assets if a['code'] is not None)
    contexts = common+bytes([23,0,200,1,2])+context(2)+font(65535)+mapping+context(1)
    for variant,identifier in [('normal',3),('selected',4)]:
        # Clone the clean small-text context; never inherit the decorative map.
        contexts += context(1)+bytes([23,0,200,1,identifier])+context(identifier)+font(0x21f1)
        contexts += b''.join(bytes([23,0,146,a['char']])+word(a['id'])
                            for a in playlist_assets if a['variant'] == variant)
    contexts += context(1)
    (ui/'contexts.vdu').write_bytes(contexts)
    static = context(1)+fill(0,0,512,384,BLACK)+context(2)
    static += b''.join(put_asset(by_name[p['name']],p['x'],p['y']) for p in placements)
    static += context(1)+font(0x21f0)
    static += bytes([23,27,4,0,23,27,5,23,27,38])+word(by_name['selection_pointer']['id'])+bytes([23,27,7,1,23,27,12,23,27,15])
    (ui/'static.vdu').write_bytes(static)
    cleanup = bytes([23,27,4,0,23,27,12,23,27,5,23,27,7,0,23,27,15])+context(0)+font(65535)+b''.join(bytes([23,0,200,1,n]) for n in (1,2,3,4))
    cleanup += bytes([23,0,149,4])+word(0x21f0)
    cleanup += bytes([23,0,149,4])+word(0x21f1)
    cleanup += b''.join(clear_buffer(a['id']) for a in assets+playlist_assets)+clear_buffer(0x21f0)+clear_buffer(0x21f1)+clear_buffer(0x2200)
    (ui/'cleanup.vdu').write_bytes(cleanup)

    generated = ['; Generated by src/skins/seventies/build.py.']
    specs = {}
    def packet(name, data, slots):
        assert 0 < len(data) <= 96, (name,len(data))
        generated.append(name+':')
        for start in range(0,len(data),24):
            generated.append('    db '+','.join(map(str,data[start:start+24])))
        generated.extend([f'{name}_end:',f'{name}_len: equ {len(data)}'])
        generated.extend(f'{name}_{label}: equ {name}+{offset}' for label,offset in slots.items())
        generated.extend([name+'_send:',f'    ld hl,{name}',f'    ld bc,{name}_len','    jp ui_send'])

    def text_widget(name,x,y,n,bg=BG,fg=TEXT,rect=None,slot='text',cell=(5,8)):
        width,height = cell
        rect = rect or (x,y,n*width,height)
        assert x >= rect[0] and y >= rect[1]
        assert x+n*width <= rect[0]+rect[2] and y+height <= rect[1]+rect[3]
        data = context(3 if cell == (6,12) else 1)+font(0x21f1 if cell == (6,12) else 0x21f0)
        slots = {'context':4,'bg':len(data)+2}
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

    text_widget('w_path',62,357,15)
    text_widget('w_page',374,367,8)
    text_widget('w_count',394,355,13)
    for row,y in enumerate(ROW_Y):
        text_widget('w_row'+str(row),84,y,58,rect=(80,y,353,12),cell=(6,12))
    generated += ['ui_rows:']+[f'    dl w_row{n},w_row{n}_text' for n in range(10)]
    text_widget('w_message',136,291,48,fg=TEXT)
    text_widget('w_track',181,256,30)
    text_widget('w_elapsed',213,273,8,slot='digits')
    text_widget('w_duration',282,273,8,slot='digits')
    text_widget('w_detail',20,367,23)
    text_widget('w_voltext',434,367,13)
    art_widget('w_play','idle',122,307)
    art_widget('w_shuffle','shuffle_off',266,307)
    art_widget('w_loop','loop_off',308,307)
    art_widget('w_volume','volume_11',368,307)
    art_widget('w_progress','progress_track',141,282)
    art_widget('w_marker','progress_marker',143,283)
    generated += ['ui_selection_y: db '+','.join(map(str,ROW_Y)),f'ui_normal_bg: equ {colour(BG)}']
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
                  'ui_selected_fg: equ 0','ui_normal_context: equ 3','ui_selected_context: equ 4',
                  'ui_progress_origin: equ 143','ui_idle_play_code: equ art_idle',
                  f'sa_image_count: equ {len(assets)}',f'sa_playlist_image_count: equ {len(playlist_assets)}']
    for label,filename in [('sa_image_meta','image-meta.bin'),('sa_contexts','contexts.vdu'),
                           ('sa_playlist_image_meta','playlist-meta.bin'),
                           ('sa_cleanup','cleanup.vdu'),('ui_static','static.vdu')]:
        generated += [f'{label}: incbin "../ui/seventies/{filename}"',f'{label}_end:']
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
            for index,char in enumerate(value):
                if spec['cell'] == (6,12):
                    variant = 'selected' if bg == GOLD else 'normal'
                    image = playlist_glyphs[variant][ord(char) if 32 <= ord(char) <= 126 else ord('?')]
                    result.paste(image,(x+index*width,y))
                else:
                    mask = glyphs[ord(char)].convert('L').crop((0,0,width,height))
                    result.paste(fg,(x+index*width,y,x+index*width+width,y+height),mask)
        if fields.get('has_entries',True):
            pointer = by_name['selection_pointer']['image']
            result.paste(pointer,(69,ROW_Y[fields.get('selected',0)]),pointer)
        return result

    example = {'w_path':'/music/Albums','w_page':'01 OF 01','selected':3,
        'w_track':'PLAYING Seven After Midnight','w_count':'007 FILES',
        'w_message':'Ready','w_elapsed':'00:01:26','w_duration':'01:22:15',
        'w_detail':'RATE 32000 Hz','w_voltext':'VOL 11','w_play':'pause',
        'w_shuffle':'shuffle_on','active':True,'progress':4}
    for index,name in enumerate(['<DIR> Boston','<DIR> Led Zeppelin','Boston__Boston.wav',
            'Led_Zeppelin__Physical_Graffiti.wav','Pink_Floyd__The_Wall.wav',
            'The_Cars__Heartbeat_City.wav','Wild_Flower.wav']):
        example['w_row'+str(index)] = f'{index:02d}   '+name.ljust(42)+'   '+('        ' if name.startswith('<DIR>') else '00:04:18')
    preview(example).save(review/'preview.png')

    # Paused state reached by case16 of the existing target suite. Elapsed and
    # marker pixels are excluded: timer scheduling intentionally varies by host.
    target = {'w_path':'/qualificati...','w_page':'01 OF 02','selected':0,
        'w_track':'PAUSED  00_Long_65535.wav','w_count':'012 FILES','w_message':'Loop current song; Shuffle setting retained',
        'w_duration':'00:00:04','w_detail':'RATE 65535 Hz','w_voltext':'VOL 10',
        'w_play':'play','w_shuffle':'shuffle_on','w_loop':'loop_on','w_volume':'volume_10'}
    for index in range(10):
        name=f'{index:02d}_'+('Long_65535.wav' if index==0 else 'Short_8000.wav')
        target['w_row'+str(index)] = f'{index:02d}   '+name.ljust(42)+'   '+('00:00:04' if index==0 else '00:00:01')
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
    points = sorted((x,y) for x,y in points if not (212<=x<254 and 272<=y<282) and not (140<=x<372 and 281<=y<291))
    payload = b''.join(xy(x,y)+bytes(expected.getpixel((x,y))) for x,y in points)
    fixture = output/'tests/fixtures/seventies/widget-samples.bin'
    fixture.parent.mkdir(parents=True,exist_ok=True)
    fixture.write_bytes(payload)
    # Test every printable glyph in both context maps, with consecutive output
    # proving six-pixel advance. Sample a checkerboard plus every shade in each
    # glyph, keeping the test executable below the player's fixed RAM workspace.
    font_draw = b''
    font_points = {}
    for variant,ctx,x0,bg,fg in [('normal',3,16,BG,TEXT),('selected',4,240,GOLD,BLACK)]:
        font_draw += context(ctx)+font(0x21f1)+fill(x0,16,96,72,bg)+gcol(fg)
        for row in range(6):
            codes = list(range(32+row*16,min(48+row*16,127)))
            font_draw += move(x0,16+row*12)+bytes(codes)
            for col,code in enumerate(codes):
                image = playlist_glyphs[variant][code].convert('RGB')
                sample = {(x,y) for y in range(12) for x in range(6) if (x+y)%2 == 0}
                shades = {}
                for y in range(12):
                    for x in range(6):
                        shades.setdefault(image.getpixel((x,y)),(x,y))
                sample.update(shades.values())
                sample.update([(0,0),(5,11)])
                for x,y in sample:
                    font_points[(x0+col*6+x,16+row*12+y)] = image.getpixel((x,y))
    font_draw += context(1)
    (fixture.parent/'font-probe.vdu').write_bytes(font_draw)
    (fixture.parent/'font-samples.bin').write_bytes(b''.join(xy(x,y)+bytes(rgb)
        for (x,y),rgb in sorted(font_points.items())))
    (ui/'test-meta.inc').write_text(f'lt_sample_count: equ {len(points)}\nlt_font_sample_count: equ {len(font_points)}\n')
    info = {'format':'seventies-authoring-test1','source_sha256':sha(source.read_bytes()),
        'builder_sha256':sha(Path(__file__).read_bytes()),
        'font_sha256':sha(font_path.read_bytes()),'source_reference':'SKIN-018 flat-color-04 candidate 3',
        'playlist_choice':'terminus','playlist_font':playlist_stem,
        'playlist_font_sha256':sha(playlist_font.read_bytes()),'playlist_source_sha256':playlist_sources,
        'playlist_assets':playlist_assets,'playlist_image_count':len(playlist_assets),
        'playlist_agnb_sha256':sha(playlist_packed),'playlist_agnb_bytes':len(playlist_packed),
        'playlist_bitmap_bytes':sum(a['width']*a['height'] for a in playlist_assets),
        'playlist_contexts':{'normal':3,'selected':4},'row_packet_bytes':94,
        'screen':[512,384],'font_cell':[5,8],'playlist_font_cell':[6,12],'browser_columns':58,'browser_rows':10,
        'control_legends':False,'placements':placements,'widgets':specs,
        'assets':[{k:v for k,v in a.items() if k!='image'} for a in assets],
        'image_count':len(assets),'unique_backdrop_tiles':len(tiles),'backdrop_placements':len(placements),
        'bitmap_payload_bytes':sum(a['width']*a['height'] for a in assets),
        'agnb_bytes':len(packed),'font_bytes':5120,'static_command_bytes':len(static),
        'test_pixels':len(points),'font_test_pixels':len(font_points),'agnb_sha256':sha(packed),
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

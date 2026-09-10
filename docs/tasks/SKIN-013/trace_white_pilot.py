"""White-region pilot with a separately saved headless Inkscape Simplify pass."""
import argparse
import copy
import json
import os
from pathlib import Path
import re
import shutil
import subprocess
import xml.etree.ElementTree as ET

import numpy as np
from PIL import Image
from scipy import ndimage as ndi

from potrace_bridge import library, trace, svg_document
from trace_black_pilot import sha, save_json, render_svg, topology, comparison_sheet

ROOT = Path(__file__).resolve().parent
SVG = '{http://www.w3.org/2000/svg}'
ET.register_namespace('', SVG[1:-1])


def white_image(mask):
    return Image.fromarray(np.where(mask, 255, 0).astype('uint8')).convert('RGB')


def path_counts(svg):
    """Count SVG segments, including implicit repeats of a path command."""
    paths = list(ET.parse(svg).getroot().iter(SVG + 'path'))
    counts = dict(objects=len(paths), segments=0, subpaths=0)
    arity = dict(M=2, L=2, H=1, V=1, C=6, S=4, Q=4, T=2, A=7)
    pattern = r'[MmLlHhVvCcSsQqTtAaZz]|[-+]?(?:\d*\.\d+|\d+\.?\d*)(?:[eE][-+]?\d+)?'
    for path in paths:
        tokens = re.findall(pattern, path.get('d', ''))
        i, command = 0, None
        while i < len(tokens):
            if len(tokens[i]) == 1 and tokens[i].isalpha():
                command = tokens[i].upper()
                i += 1
                if command == 'Z':
                    command = None
                    continue
            if command not in arity:
                raise ValueError('Invalid SVG path data')
            values = tokens[i:i + arity[command]]
            assert len(values) == arity[command]
            for value in values:
                float(value)
            i += len(values)
            if command == 'M':
                counts['subpaths'] += 1
                command = 'L'
            else:
                counts['segments'] += 1
    return counts


def simplify(source, dest, profile, threshold):
    profile.mkdir()
    preferences = ('<inkscape version="1"><group id="options">'
                   f'<group id="simplifythreshold" value="{threshold}"/>'
                   '</group></inkscape>\n')
    (profile / 'preferences.xml').write_text(preferences)
    env = dict(os.environ, INKSCAPE_PROFILE_DIR=str(profile))
    args = ['inkscape', str(source), '--actions=select-all:all;path-simplify',
            '--export-type=svg', '--export-plain-svg', f'--export-filename={dest}']
    result = subprocess.run(args, env=env, capture_output=True, text=True, timeout=45)
    if result.returncode or not dest.exists():
        raise RuntimeError(result.stderr or result.stdout or 'SVG export was not produced')
    return dict(argv=args, preference='/options/simplifythreshold', value=threshold,
                passes=1, profile=str(profile), stderr=result.stderr.strip())


def save_individual_shapes(svg, folder):
    folder.mkdir()
    root = ET.parse(svg).getroot()
    entries = []
    for i, path in enumerate(root.iter(SVG + 'path'), 1):
        doc = ET.Element(SVG + 'svg', {k: root.get(k) for k in ('width', 'height', 'viewBox')})
        doc.append(copy.deepcopy(path))
        filename = f'shape-{i:03d}.svg'
        ET.ElementTree(doc).write(folder / filename, encoding='utf-8', xml_declaration=True)
        entries.append(dict(file=filename, path_id=path.get('id')))
    save_json(folder / 'index.json', entries)
    return entries


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--params', type=Path, default=ROOT / 'white-trace-parameters.json')
    parser.add_argument('--source', type=Path)
    parser.add_argument('--out', type=Path, required=True)
    args = parser.parse_args()
    params = json.loads(args.params.read_text())
    source = args.source.resolve() if args.source else ROOT / params['source']
    out = args.out.resolve()
    if out.exists():
        parser.error('Output exists; preserve candidates and hand edits')
    assert sha(source) == params['source_sha256']
    image = Image.open(source).convert('RGB')
    assert list(image.size) == params['canvas']
    colors = np.unique(np.array(image).reshape(-1, 3), axis=0)
    assert set(map(tuple, colors.tolist())) == {(0, 0, 0), (255, 255, 255)}
    assert params['simplify_passes'] == 1
    user_preferences = Path('/home/smith/.config/inkscape/preferences.xml')
    prefs_before = sha(user_preferences) if user_preferences.exists() else None
    out.mkdir(parents=True)
    (out / 'elements').mkdir()
    (out / 'profiles').mkdir()
    for name in ('trace_white_pilot.py', 'trace_black_pilot.py', 'potrace_bridge.py'):
        shutil.copyfile(ROOT / name, out / name)
    shutil.copyfile(args.params, out / 'parameters.json')
    report = dict(source=str(source), source_sha256=sha(source), selection='exact RGB(255,255,255)',
                  scope=params['notice'], potrace=library().potrace_version().decode(),
                  inkscape=subprocess.check_output(['inkscape', '--version'], text=True).strip(),
                  regions=[])
    rows = []
    for region in params['regions']:
        name, box = region['name'], region['box']
        folder = out / 'elements' / name
        folder.mkdir()
        crop = image.crop(box)
        crop.save(folder / 'source.png')
        raw = np.all(np.array(crop) == 255, axis=2)
        paths = trace(raw, params['alphamax'], params['opttolerance'])
        assert sum(p['sign'] == '+' for p in paths) == topology(raw)['components']
        assert sum(p['sign'] == '-' for p in paths) == topology(raw)['holes']
        traced = folder / 'traced.svg'
        traced.write_text(svg_document(paths, crop.width, crop.height, name, fill='#ffffff'))
        save_json(folder / 'traced-paths.json', paths)
        command = simplify(traced, folder / 'simplified.svg', out / 'profiles' / name,
                           params['simplify_threshold'])
        individual = save_individual_shapes(traced, folder / 'shapes')
        simplified_individual = save_individual_shapes(folder / 'simplified.svg', folder / 'simplified-shapes')
        raw_shapes = [dict(contour=p['id'], source_area=p['area']) for p in paths if p['sign'] == '+']
        rec = dict(name=name, source_box=box, size=list(crop.size), original_topology=topology(raw),
                   shapes=raw_shapes, individual_shapes=individual,
                   simplified_individual_shapes=simplified_individual,
                   inkscape_command=command, variants=[])
        renders = {}
        for variant in ('traced', 'simplified'):
            svg = folder / f'{variant}.svg'
            before = path_counts(svg)
            actual = render_svg(svg, folder / f'{variant}-render.png', crop.size)
            white_image(actual).save(folder / f'{variant}-black-white.png')
            renders[variant] = actual
            difference = np.zeros((*raw.shape, 3), dtype=np.uint8)
            difference[raw & actual] = 255
            difference[raw & ~actual] = [255, 0, 0]
            difference[actual & ~raw] = [0, 255, 0]
            Image.fromarray(difference).save(folder / f'{variant}-differences.png')
            outline = actual ^ ndi.binary_erosion(actual)
            overlay = np.array(crop)
            overlay[outline] = [0, 255, 255]
            Image.fromarray(overlay).save(folder / f'{variant}-overlay.png')
            rec['variants'].append(dict(name=variant, **before, svg_bytes=svg.stat().st_size,
                foreground_iou=float((raw & actual).sum() / (raw | actual).sum()),
                xor_pixels=int((raw ^ actual).sum()), rendered_topology=topology(actual)))
        assert rec['variants'][0]['objects'] == rec['variants'][1]['objects']
        assert rec['variants'][0]['subpaths'] == rec['variants'][1]['subpaths']
        save_json(folder / 'region.json', rec)
        report['regions'].append(rec)
        rows.append((name, [crop, white_image(renders['traced']), white_image(renders['simplified']),
                            Image.open(folder / 'simplified-overlay.png').copy()]))
        print(name, [(v['name'], v['objects'], v['segments']) for v in rec['variants']], flush=True)
    comparison_sheet(rows, ['Source white shapes', 'Initial vectors', 'Inkscape simplified', 'Contour overlay'], out / 'comparison.png')
    report['source_unchanged'] = sha(source) == params['source_sha256']
    report['user_inkscape_preferences_unchanged'] = (sha(user_preferences) if user_preferences.exists() else None) == prefs_before
    assert report['source_unchanged'] and report['user_inkscape_preferences_unchanged']
    save_json(out / 'report.json', report)
    print('Saved', out, flush=True)


if __name__ == '__main__':
    main()

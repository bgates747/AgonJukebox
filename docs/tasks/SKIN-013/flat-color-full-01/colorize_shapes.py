"""Trace a full binary mask, sample flat colors, and render hard-edged Agon PNGs.

Use the project .venv. The output directory must be new. Source files and prior
pilots are never changed. See the generated README, parameters and report.
"""
import argparse
import copy
import csv
import hashlib
import json
import os
from pathlib import Path
import shutil
import subprocess
import xml.etree.ElementTree as ET

import numpy as np
from PIL import Image
from scipy import ndimage as ndi

from potrace_bridge import trace, svg_groups, library
from cairo_flat_svg import render

ROOT = Path(__file__).resolve().parent
SVG = '{http://www.w3.org/2000/svg}'
ET.register_namespace('', SVG[1:-1])


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def save_json(path, obj):
    path.write_text(json.dumps(obj, indent=2) + '\n')


def hex_color(rgb):
    return '#' + ''.join(f'{int(v):02x}' for v in rgb)


def sample_color(rgb, mask, params, palette):
    inset = params['sample_inset_source_pixels']
    interior = ndi.binary_erosion(mask, iterations=inset) if inset else mask
    fallback = not interior.any()
    sampled = rgb[mask if fallback else interior]
    step = params['histogram_bin_width']
    bins = (256 + step - 1) // step
    q = sampled.astype(np.int32) // step
    codes = q[:, 0] * bins * bins + q[:, 1] * bins + q[:, 2]
    counts = np.bincount(codes, minlength=bins ** 3)
    winning = int(counts.argmax())
    representative = np.median(sampled[codes == winning], axis=0)
    distances = ((palette.astype(float) - representative) ** 2).sum(axis=1)
    index = int(distances.argmin())
    return {'sample_count': len(sampled), 'inset_fallback': fallback,
            'winning_bin': winning, 'winning_bin_count': int(counts[winning]),
            'winning_bin_fraction': float(counts[winning] / len(sampled)),
            'representative_rgb': representative.tolist(), 'palette_index': index,
            'fill_rgb': palette[index].tolist(), 'fill': hex_color(palette[index])}


def indexed_png(rgb, palette, path):
    # Exact mapping: reject renderer fringe colors instead of hiding them.
    lookup = {tuple(map(int, c)): i for i, c in enumerate(palette)}
    indices = np.fromiter((lookup[tuple(p)] for p in rgb.reshape(-1, 3)), dtype=np.uint8)
    image = Image.fromarray(indices.reshape(rgb.shape[:2]))
    image.putpalette(palette.ravel().tolist())
    image.save(path)
    with Image.open(path) as saved:
        assert saved.mode == 'P' and len(saved.getpalette()) == 192
        assert np.array_equal(np.array(saved.convert('RGB')), rgb)


def inkscape_export(svg, png, profile, size):
    args = ['inkscape', str(svg), f'--export-filename={png}',
            f'--export-width={size[0]}', f'--export-height={size[1]}',
            '--export-area-page', '--export-png-use-dithering=false']
    result = subprocess.run(args, env=dict(os.environ, INKSCAPE_PROFILE_DIR=str(profile)),
                            capture_output=True, text=True, check=True, timeout=60)
    return {'argv': args, 'stderr': result.stderr.strip()}


def aa_probe(out):
    folder = out / 'antialias-probe'; folder.mkdir()
    measurements = []
    for name in ('default', 'crispEdges', 'preferences-zero', 'document-flag'):
        profile = folder / (name + '-profile'); profile.mkdir()
        profile.joinpath('preferences.xml').write_text(
            '<inkscape version="1"><group id="extensions" '
            'org.inkscape.output.png.inkscape.png_antialias="0"/></inkscape>')
        flag = '<sodipodi:namedview inkscape:antialias-rendering="false"/>' if name == 'document-flag' else ''
        hint = ' shape-rendering="crispEdges"' if name == 'crispEdges' else ''
        svg = folder / (name + '.svg'); png = folder / (name + '.png')
        svg.write_text('<svg xmlns="http://www.w3.org/2000/svg" '
            'xmlns:inkscape="http://www.inkscape.org/namespaces/inkscape" '
            'xmlns:sodipodi="http://sodipodi.sourceforge.net/DTD/sodipodi-0.dtd" '
            'width="64" height="48" viewBox="0 0 100 75"' + hint + '>' + flag +
            '<path fill="#ffaa00" d="M3,4 L95,62 L12,70 Z"/>'
            '<path fill="#55aaff" d="M60,5 C98,0 93,44 60,40 C45,38 43,10 60,5 Z"/></svg>')
        if name in ('default', 'crispEdges'):
            profile.joinpath('preferences.xml').write_text('<inkscape version="1"/>')
        command = inkscape_export(svg, png, profile, (64, 48))
        rgba = np.array(Image.open(png).convert('RGBA'))
        measurements.append({'case': name, 'partial_alpha_pixels': int(((rgba[:, :, 3] > 0) & (rgba[:, :, 3] < 255)).sum()),
                             'visible_colors': len(np.unique(rgba[rgba[:, :, 3] > 0, :3], axis=0)), 'command': command})
    svg = folder / 'default.svg'
    renderer = render(svg, folder / 'cairo-none.png', (64, 48))
    rgba = np.array(Image.open(folder / 'cairo-none.png').convert('RGBA'))
    assert set(map(tuple, np.unique(rgba[:, :, :3].reshape(-1, 3), axis=0))) == {(0, 0, 0), (255, 170, 0), (85, 170, 255)}
    assert np.all(rgba[:, :, 3] == 255)
    save_json(folder / 'report.json', {'inkscape': measurements, 'selected_renderer': renderer})
    return measurements


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--mask', type=Path, required=True)
    parser.add_argument('--reference', type=Path, required=True)
    parser.add_argument('--params', type=Path, default=ROOT / 'flat-color-parameters-v1.json')
    parser.add_argument('--palette', type=Path, default=ROOT / 'Agon64.gpl' if (ROOT / 'Agon64.gpl').exists() else Path('/home/smith/Agon/mystuff/agon-utils/examples/slideshow/palettes/Agon64.gpl'))
    parser.add_argument('--out', type=Path, required=True)
    args = parser.parse_args()
    if args.out.exists(): parser.error('Output exists; preserve candidates and hand edits')
    params = json.loads(args.params.read_text())
    assert params['simplify_passes'] == 1
    palette = []
    for line in args.palette.read_text().splitlines():
        words = line.split()
        if len(words) >= 3 and all(w.isdecimal() for w in words[:3]): palette.append(list(map(int, words[:3])))
    palette = np.array(palette, dtype=np.uint8)
    assert len(palette) == 64 and len(set(map(tuple, palette))) == 64 and not np.any(palette % 85)
    source, ref, out = args.mask.resolve(), args.reference.resolve(), args.out.resolve()
    hashes = {str(p): sha(p) for p in (source, ref, args.palette.resolve())}
    prefs = Path.home() / '.config/inkscape/preferences.xml'
    pref_hash = sha(prefs) if prefs.exists() else None
    binary = np.array(Image.open(source).convert('RGB'))
    rgb = np.array(Image.open(ref).convert('RGB'))
    assert binary.shape == rgb.shape
    assert set(map(tuple, np.unique(binary.reshape(-1, 3), axis=0))) == {(0, 0, 0), (255, 255, 255)}
    height, width = binary.shape[:2]
    target = params['target_size']
    assert width * target[1] == height * target[0]
    mask = np.all(binary == params['foreground_rgb'], axis=2)
    labels, count = ndi.label(mask, np.ones((3, 3)))
    out.mkdir(parents=True)
    for script in ('colorize_shapes.py', 'cairo_flat_svg.py', 'potrace_bridge.py'):
        shutil.copyfile(ROOT / script, out / script)
    shutil.copyfile(args.palette, out / 'Agon64.gpl')
    save_json(out / 'parameters.json', params)
    root = ET.Element(SVG + 'svg', {'width': str(target[0]), 'height': str(target[1]),
                                  'viewBox': f'0 0 {width} {height}'})
    ET.SubElement(root, SVG + 'title').text = 'Predominant original-art color per traced white shape'
    ET.SubElement(root, SVG + 'rect', {'id': 'background', 'width': str(width), 'height': str(height),
                                     'fill': hex_color(params['background_rgb'])})
    records = []
    holes = 0
    source_flat = np.zeros_like(rgb)
    for label, box in enumerate(ndi.find_objects(labels), 1):
        y, x = box
        component = labels[box] == label
        sample = sample_color(rgb[box], component, params, palette)
        paths = trace(component, params['alphamax'], params['opttolerance'])
        assert sum(p['sign'] == '+' for p in paths) == 1
        holes += sum(p['sign'] == '-' for p in paths)
        identifier = f'white-{label:04d}'
        node = ET.fromstring(svg_groups(paths, identifier, sample['fill']))
        node.tag = SVG + 'path'
        node.set('id', identifier)
        node.set('transform', f'translate({x.start},{y.start})')
        root.append(node)
        source_flat[box][component] = sample['fill_rgb']
        records.append({'id': identifier, 'label': label, 'source_box': [x.start, y.start, x.stop, y.stop],
                        'source_area': int(component.sum()), 'holes': sum(p['sign'] == '-' for p in paths), **sample})
    traced = out / 'traced-colors.svg'
    ET.ElementTree(root).write(traced, encoding='utf-8', xml_declaration=True)
    indexed_png(source_flat, palette, out / 'sampled-source-regions.png')
    save_json(out / 'shapes.json', records)
    print(f'Traced and sampled {count} shapes, {holes} holes.', flush=True)
    profile = out / 'inkscape-profile'; profile.mkdir()
    profile.joinpath('preferences.xml').write_text('<inkscape version="1"><group id="options">'
        f'<group id="simplifythreshold" value="{params["simplify_threshold"]}"/>'
        '</group></inkscape>')
    # Select each shape separately so the tolerance uses its own bounds, not
    # the whole interface's bounding box. Background rectangle is excluded.
    actions = ';'.join(f'select-clear;select-by-id:{r["id"]};path-simplify' for r in records)
    simplified = out / 'colored-shapes.svg'
    argv = ['inkscape', str(traced), f'--actions={actions}', '--export-type=svg',
            '--export-plain-svg', f'--export-filename={simplified}']
    proc = subprocess.run(argv, env=dict(os.environ, INKSCAPE_PROFILE_DIR=str(profile)),
                          capture_output=True, text=True, timeout=120, check=True)
    save_json(out / 'simplification-command.json', {'argv': argv, 'stderr': proc.stderr.strip(),
              'threshold': params['simplify_threshold'], 'passes_per_shape': 1})
    smoothed = ET.parse(simplified).getroot()
    assert {p.get('id') for p in smoothed.iter(SVG + 'path')} == {r['id'] for r in records}
    print('Headless Inkscape simplification complete.', flush=True)
    aa = aa_probe(out)
    renderer = render(simplified, out / 'cairo-render.png', tuple(target))
    render(traced, out / 'cairo-traced.png', tuple(target))
    final = np.array(Image.open(out / 'cairo-render.png').convert('RGB'))
    indexed_png(final, palette, out / 'preview.png')
    Image.fromarray(final).resize((target[0] * 4, target[1] * 4), Image.Resampling.NEAREST).save(out / 'preview-4x.png')
    ink_command = inkscape_export(simplified, out / 'inkscape-export.png', profile, target)
    ink_rgb = np.array(Image.open(out / 'inkscape-export.png').convert('RGB'))
    reference_small = Image.fromarray(rgb).resize(tuple(target), Image.Resampling.NEAREST)
    reference_small.save(out / 'reference-nearest.png')
    with (out / 'shape-colors.csv').open('w', newline='') as f:
        writer = csv.writer(f)
        writer.writerow(['id', 'area', 'sample_count', 'mode_fraction', 'original_rgb', 'agon_rgb', 'palette_index'])
        for r in records: writer.writerow([r['id'], r['source_area'], r['sample_count'], r['winning_bin_fraction'], r['representative_rgb'], r['fill_rgb'], r['palette_index']])
    report = {'source_mask': str(source), 'color_reference': str(ref), 'input_sha256': hashes,
              'size': target, 'source_size': [width, height], 'white_shapes': count, 'holes': holes,
              'fill_colors': sorted(set(r['fill'] for r in records)),
              'visible_colors': len(np.unique(final.reshape(-1, 3), axis=0)),
              'renderer': renderer, 'inkscape': subprocess.check_output(['inkscape', '--version'], text=True).strip(),
              'potrace': library().potrace_version().decode(), 'antialias_probe': aa,
              'inkscape_full_export': ink_command,
              'inkscape_full_off_palette_pixels': int(np.any(ink_rgb % 85, axis=2).sum()),
              'final_off_palette_pixels': int(np.any(final % 85, axis=2).sum()),
              'source_unchanged': all(sha(Path(p)) == h for p, h in hashes.items()),
              'user_preferences_unchanged': (sha(prefs) if prefs.exists() else None) == pref_hash,
              'preview_sha256': sha(out / 'preview.png'), 'scope': params['scope']}
    assert report['source_unchanged'] and report['user_preferences_unchanged'] and report['final_off_palette_pixels'] == 0
    save_json(out / 'report.json', report)
    write_review(out, report)
    print(json.dumps({k: report[k] for k in ('white_shapes', 'holes', 'visible_colors', 'final_off_palette_pixels', 'inkscape_full_off_palette_pixels')}), flush=True)
    print('Saved', out, flush=True)


def write_review(out, report):
    (out / 'README.md').write_text(f'''# Full-image sampled flat-color candidate

Open [preview.png](preview.png): exactly 512x384, indexed PNG with the 64-color
Agon palette embedded. [Gallery](index.html), [editable SVG](colored-shapes.svg),
[4x nearest-neighbor view](preview-4x.png), [color table](shape-colors.csv).

The script traced all {report['white_shapes']} white components from the supplied
binary source. For each original component it samples a two-source-pixel inset
(falling back to the whole component if empty), finds the most populated
16x16x16 RGB histogram bin, and takes that bin's median original RGB. It then
selects the nearest Agon color by squared RGB distance. Ties use the lowest
bin/palette index. See shapes.json for areas, samples, confidence and colors.
Sampling uses the matching unquantized flat-outline master, without registration
or resizing. The inset affects color sampling only, not the shape geometry.

Potrace uses the pilot's 0.55 corner threshold and 0.2 source-pixel tolerance,
with speck suppression disabled. Inkscape simplifies each shape separately
once, at 0.0003, preserving IDs. Per-shape bounds keep small text from inheriting
the whole image's simplification scale. This is a full-image extension, not a
reuse of the four cropped pilot vectors. Earlier pilots are unchanged.

## Rasterization

Inkscape {report['inkscape']} exported {report['inkscape_full_off_palette_pixels']}
off-palette pixels. This installed CLI does not expose the PNG antialias option;
the crispEdges hint, zero extension preference and document flag also failed
the saved curved/diagonal export probes. Evidence is in antialias-probe/.
The later command-line switch is described in the
[Inkscape 1.4 notes](https://wiki.inkscape.org/wiki/Release_notes/1.4#Command_line).

The final PNG instead renders the same simplified SVG paths through the already
installed libcairo with CAIRO_ANTIALIAS_NONE. cairo_flat_svg.py deliberately
supports only our flat path/rectangle subset and rejects unsupported effects.
It draws directly at 512x384. There is no image resize, dithering or palette
repair after rendering; the indexed conversion is an exact lookup and fails
on any off-palette pixel. The final PNG has {report['visible_colors']} visible
colors and zero off-palette pixels. The Cairo antialias setting is documented
in the [Cairo manual](https://www.cairographics.org/manual/cairo-cairo-t.html#cairo-antialias-t).

## Limits and next review

This assigns one color to each existing white region. Black mask regions remain
black, including darker decorative features merged into them by thresholding.
It cannot recover those missing boundaries. No gradient, bevel, material-role
inference or manual color correction is included. Sample text is traced as
part of the concept image; it is not an application font or functional screen.
Native rasterization can lose tiny components or narrow gaps. Review the saved
native image before further work; source-resolution topology is not a guarantee
of final-screen detail. Sources and user Inkscape preferences were unchanged.

## Reproduce

From the project root, choose a new output directory:

```bash
.venv/bin/python {out.relative_to(Path.cwd())}/colorize_shapes.py \\
  --mask docs/tasks/SKIN-013/source-test-01/flat-outline-master_bw_threshold.png \\
  --reference docs/tasks/SKIN-013/source-test-01/flat-outline-master.png \\
  --params {out.relative_to(Path.cwd())}/parameters.json \\
  --out docs/tasks/SKIN-013/another-flat-color-candidate
```

The script produces all review assets and measurements. It refuses to overwrite
an output directory. This experiment adds no production dependency and does not
change application assets, emulator deployment or AGNB packaging.
''')
    (out / 'index.html').write_text('''<!doctype html><html lang="en"><meta charset="utf-8">
<title>Sampled flat-color skin</title><style>
body{background:#222;color:#eee;font:16px system-ui;margin:24px}a{color:#ffd580}
nav{position:sticky;top:0;background:#222;padding:12px}img{image-rendering:pixelated;display:block;width:calc(512px * var(--z,1));height:calc(384px * var(--z,1))}
.row{display:flex;gap:20px;overflow:auto}figure{margin:0}figcaption{padding:10px}button{padding:8px}
</style><h1>Predominant color per shape</h1><p>512×384. One sampled Agon color per white shape. Black regions remain black.</p>
<p><a href="preview.png">Final indexed PNG</a> · <a href="colored-shapes.svg">Editable SVG</a> · <a href="README.md">Method and limits</a> · <a href="shape-colors.csv">Color table</a></p>
<nav>Zoom <button data-z="1">1×</button> <button data-z="2">2×</button> <button data-z="4">4×</button></nav>
<div class="row"><figure><figcaption>Source reference, nearest-neighbor preview (unrestricted colors)</figcaption><img src="reference-nearest.png" alt="Source reference"></figure>
<figure><figcaption>Sampled flat fills, simplified vectors, antialiasing off</figcaption><img src="preview.png" alt="Final 512 by 384 Agon palette image"></figure></div>
<p><a href="cairo-traced.png">Initial vectors before Inkscape simplification</a> · <a href="sampled-source-regions.png">Sampled colors on original region masks</a> · <a href="inkscape-export.png">Inkscape export with unwanted antialiasing</a></p>
<script>document.querySelectorAll('[data-z]').forEach(b=>b.onclick=()=>document.documentElement.style.setProperty('--z',b.dataset.z));</script></html>''')


if __name__ == '__main__':
    main()

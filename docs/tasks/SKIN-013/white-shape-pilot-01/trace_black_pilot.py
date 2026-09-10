"""Extract near-neutral black ink at source resolution and trace a bounded pilot.

Usage: .venv/bin/python docs/tasks/SKIN-013/trace_black_pilot.py --out NEW_FOLDER
No image-generation, source editing, color tracing, shading or runtime changes.
"""
import argparse
import hashlib
import html
import json
from pathlib import Path
import platform
import shutil
import subprocess
import tempfile

import numpy as np
from PIL import Image, ImageDraw, __version__ as pillow_version
import scipy
from scipy import ndimage as ndi

from potrace_bridge import library, trace, svg_document, svg_groups

ROOT = Path(__file__).resolve().parent
INK_CONNECTIVITY = np.ones((3, 3), dtype=bool)
BACKGROUND_CONNECTIVITY = ndi.generate_binary_structure(2, 1)


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def save_json(path, data):
    path.write_text(json.dumps(data, indent=2) + '\n')


def mask_image(mask):
    return Image.fromarray(np.where(mask, 0, 255).astype('uint8')).convert('RGB')


def select_black(rgb, threshold):
    a = rgb.astype(np.int16)
    maximum = a.max(axis=2)
    return ((maximum <= threshold['max_channel']) &
            ((maximum - a.min(axis=2)) <= threshold['max_spread']))


def topology(mask):
    _, components = ndi.label(mask, INK_CONNECTIVITY)
    background, _ = ndi.label(~mask, BACKGROUND_CONNECTIVITY)
    exterior = set(np.unique(np.concatenate([background[0], background[-1],
                                             background[:, 0], background[:, -1]])))
    holes = len(set(np.unique(background)) - exterior - {0})
    return dict(ink_pixels=int(mask.sum()), components=components, holes=holes)


def clean_candidates(mask, rgb, params):
    cleaned = mask.copy()
    records = []
    for kind, selection, connectivity in [('island', mask, INK_CONNECTIVITY),
                                           ('hole', ~mask, BACKGROUND_CONNECTIVITY)]:
        labels, _ = ndi.label(selection, connectivity)
        areas = np.bincount(labels.ravel())
        objects = ndi.find_objects(labels)
        limit = params['max_island_area' if kind == 'island' else 'max_hole_area']
        for label, slices in enumerate(objects, 1):
            if slices is None or areas[label] > limit:
                continue
            sy, sx = slices
            if min(sy.start, sx.start) == 0 or sy.stop == mask.shape[0] or sx.stop == mask.shape[1]:
                continue  # Cropped boundaries are not evidence of noise.
            if max(sy.stop - sy.start, sx.stop - sx.start) > params['max_extent']:
                continue
            local = labels[slices] == label
            samples = rgb[slices][local].astype(np.int16)
            if kind == 'hole' and (samples.max() > params['hole_max_channel'] or
                    np.max(samples.max(axis=1) - samples.min(axis=1)) > params['hole_max_spread']):
                continue  # Do not fill bright/colored miniature highlights.
            cleaned[slices][local] = kind == 'hole'
            records.append(dict(kind=kind, box=[sx.start, sy.start, sx.stop, sy.stop],
                                source_pixels=int(areas[label])))
    return cleaned, records


def render_svg(svg, png, size):
    args = ['inkscape', str(svg.resolve()), '--export-area-page', '--export-type=png',
            f'--export-filename={png.resolve()}', '--export-background-opacity=0',
            f'--export-width={size[0]}', f'--export-height={size[1]}']
    result = subprocess.run(args, capture_output=True, text=True, timeout=45)
    if result.returncode:
        raise RuntimeError(result.stderr or result.stdout)
    with Image.open(png) as im:
        assert im.size == tuple(size)
        ink = np.array(im.convert('RGBA'))[:, :, 3] >= 128
    return ink


def adapter_checks(folder):
    """Independent renderer catches word packing, orientation and hole errors."""
    cases = []
    for width in (63, 64, 65):
        m = np.zeros((31, width), dtype=bool)
        m[2:23, 2:width-3] = True
        m[5:12, 6:18] = False
        m[8:10, 10:13] = True  # Nested ink island inside a hole.
        m[26:29, width-7:width-2] = True  # Asymmetric bottom-right landmark.
        cases.append((f'word-{width}', m))
    cases.append(('empty', np.zeros((13, 17), dtype=bool)))
    passed = []
    for name, mask in cases:
        paths = trace(mask, alphamax=0, opttolerance=0)
        svg = folder / f'{name}.svg'
        svg.write_text(svg_document(paths, mask.shape[1], mask.shape[0], name))
        actual = render_svg(svg, folder / f'{name}.png', mask.shape[::-1])
        assert np.array_equal(actual, mask), f'Adapter/raster check failed: {name}'
        passed.append(name)
    return passed


def comparison_sheet(rows, captions, path):
    cell_width = max(im.width for _, ims in rows for im in ims) + 20
    heights = [max(im.height for im in ims) + 52 for _, ims in rows]
    sheet = Image.new('RGB', (cell_width * len(captions), sum(heights) + 30), '#dddddd')
    draw = ImageDraw.Draw(sheet)
    for j, caption in enumerate(captions):
        draw.text((j * cell_width + 10, 8), caption, fill='black')
    top = 30
    for (name, images), height in zip(rows, heights):
        for j, im in enumerate(images):
            draw.text((j * cell_width + 10, top + 6), name, fill='black')
            sheet.paste(im, (j * cell_width + 10, top + 28))
        top += height
    sheet.save(path)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--params', type=Path, default=ROOT / 'black-trace-parameters.json')
    parser.add_argument('--source', type=Path, help='Explicit source for replaying a saved script snapshot')
    parser.add_argument('--out', type=Path, required=True)
    args = parser.parse_args()
    params = json.loads(args.params.read_text())
    out = args.out.resolve()
    if out.exists():
        parser.error('Output exists; preserve earlier results and hand edits')
    source = args.source.resolve() if args.source else ROOT / params['source']
    assert sha(source) == params['source_sha256']
    source_image = Image.open(source).convert('RGB')
    assert list(source_image.size) == params['canvas']
    assert shutil.which('inkscape')
    out.mkdir(parents=True)
    (out / 'elements').mkdir()
    (out / 'checks').mkdir()
    with tempfile.TemporaryDirectory(prefix='skin013-trace-check-') as tmp:
        adapter = adapter_checks(Path(tmp))
    shutil.copyfile(args.params, out / 'parameters.json')
    for file in ['trace_black_pilot.py', 'potrace_bridge.py']:
        shutil.copyfile(ROOT / file, out / file)
    selection = source_image.copy()
    selection_draw = ImageDraw.Draw(selection)
    report = dict(source=str(source), source_sha256=sha(source), stage='black-region pilot',
                  scope=params['notice'], source_size=params['canvas'], target_size=params['target_canvas'],
                  toolchain=dict(potrace=library().potrace_version().decode(),
                      inkscape=subprocess.check_output(['inkscape', '--version'], text=True).strip(),
                      python=platform.python_version(), numpy=np.__version__, scipy=scipy.__version__,
                      pillow=pillow_version), adapter_checks=adapter, regions=[])
    source_colors = np.unique(np.array(source_image).reshape(-1, 3), axis=0)
    report['source_color_count'] = len(source_colors)
    report['source_is_agon_palette'] = bool((source_colors % 85 == 0).all())
    libpath = Path('/lib/x86_64-linux-gnu/libpotrace.so.0')
    if libpath.exists():
        report['toolchain']['libpotrace_file'] = str(libpath.resolve())
        report['toolchain']['libpotrace_sha256'] = sha(libpath)
    threshold_rows, comparison_rows, placements = [], [], []
    for region in params['regions']:
        name, box = region['name'], region['box']
        x0, y0, x1, y1 = box
        assert 0 <= x0 < x1 <= source_image.width and 0 <= y0 < y1 <= source_image.height
        folder = out / 'elements' / name
        folder.mkdir()
        crop = source_image.crop(box)
        crop.save(folder / 'source.png')
        rgb = np.array(crop)
        masks = {t['name']: select_black(rgb, t) for t in params['thresholds']}
        for key, mask in masks.items():
            mask_image(mask).save(folder / f'mask-{key}.png')
        raw = masks[params['selected_threshold']]
        clean, changes = clean_candidates(raw, rgb, params['cleanup'])
        mask_image(clean).save(folder / 'mask-cleaned.png')
        noise = rgb.copy()
        noise[raw & ~clean] = [255, 0, 0]
        noise[clean & ~raw] = [0, 255, 0]
        Image.fromarray(noise).save(folder / 'cleanup-overlay.png')
        rec = dict(name=name, source_box=box, source_size=list(crop.size),
                   thresholds={k: topology(v) for k, v in masks.items()},
                   cleaned=topology(clean), cleanup_candidates=changes,
                   cleanup_removed_pixels=int((raw & ~clean).sum()),
                   cleanup_added_pixels=int((clean & ~raw).sum()), variants=[])
        variants = [('raw-faithful', raw, params['trace_variants'][0])]
        variants += [(v['name'], clean, v) for v in params['trace_variants']]
        rendered = {}
        for variant_name, mask, settings in variants:
            paths = trace(mask, settings['alphamax'], settings['opttolerance'])
            svg = folder / f'{variant_name}.svg'
            svg.write_text(svg_document(paths, crop.width, crop.height, name))
            save_json(folder / f'{variant_name}-paths.json', paths)
            actual = render_svg(svg, folder / f'{variant_name}-render.png', crop.size)
            mask_image(actual).save(folder / f'{variant_name}-black-white.png')
            rendered[variant_name] = actual
            border = actual ^ ndi.binary_erosion(actual)
            overlay = rgb.copy()
            overlay[border] = [0, 255, 255]
            Image.fromarray(overlay).save(folder / f'{variant_name}-overlay.png')
            difference = np.full_like(rgb, 255)
            difference[mask & actual] = [0, 0, 0]
            difference[mask & ~actual] = [255, 0, 0]
            difference[actual & ~mask] = [0, 170, 0]
            Image.fromarray(difference).save(folder / f'{variant_name}-differences.png')
            union = int((mask | actual).sum())
            rec['variants'].append(dict(name=variant_name, curves=len(paths),
                ink_shapes=sum(p['sign'] == '+' for p in paths),
                holes=sum(p['sign'] == '-' for p in paths),
                segments=sum(len(p['segments']) for p in paths),
                svg_bytes=svg.stat().st_size, xor_pixels=int((mask ^ actual).sum()),
                ink_iou=float((mask & actual).sum() / union) if union else 1,
                rendered_topology=topology(actual), settings=settings))
            if variant_name == 'faithful':
                placements.append(f'<g transform="translate({x0},{y0})">{svg_groups(paths, name)}</g>')
        # No hidden speck removal in Potrace: signed contour counts are retained.
        for mask, variant in [(raw, rec['variants'][0]), (clean, rec['variants'][1])]:
            topo = topology(mask)
            assert variant['ink_shapes'] == topo['components'], (name, topo, variant)
            assert variant['holes'] == topo['holes'], (name, topo, variant)
        save_json(folder / 'region.json', rec)
        report['regions'].append(rec)
        threshold_rows.append((name, [crop] + [mask_image(masks[t['name']]) for t in params['thresholds']]))
        comparison_rows.append((name, [crop, mask_image(raw), mask_image(clean),
                                      mask_image(rendered['faithful']),
                                      Image.open(folder / 'faithful-overlay.png').copy()]))
        selection_draw.rectangle((x0, y0, x1 - 1, y1 - 1), outline='#00ffff', width=3)
        selection_draw.text((x0 + 5, y0 + 5), name, fill='white', stroke_width=2, stroke_fill='black')
        print(name, 'traced:', rec['variants'][1]['curves'], 'contours;',
              rec['cleanup_added_pixels'] + rec['cleanup_removed_pixels'], 'cleanup pixels', flush=True)
    selection.save(out / 'pilot-regions.png')
    comparison_sheet(threshold_rows, ['Source'] + [t['name'] for t in params['thresholds']], out / 'threshold-comparison.png')
    comparison_sheet(comparison_rows, ['Source', 'Selected black mask', 'Tiny cleanup', 'Vector render', 'Contour overlay'], out / 'comparison.png')
    w, h = params['canvas']
    tw, th = params['target_canvas']
    svg = out / 'pilot-outlines.svg'
    svg.write_text(f'<svg xmlns="http://www.w3.org/2000/svg" width="{tw}" height="{th}" '
                   f'viewBox="0 0 {w} {h}"><title>Black outline pilot placements only</title>' +
                   ''.join(placements) + '</svg>\n')
    native = render_svg(svg, out / 'pilot-outlines-antialiased.png', (tw, th))
    mask_image(native).save(out / 'pilot-outlines-512x384.png')
    report['source_unchanged'] = sha(source) == params['source_sha256']
    assert report['source_unchanged']
    save_json(out / 'report.json', report)
    print('Saved', out, flush=True)


if __name__ == '__main__':
    main()

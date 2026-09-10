"""Verify a saved colorized candidate, including its independent SVG renderer."""
import argparse
import hashlib
import json
import os
from pathlib import Path
import subprocess
import sys
import tempfile

import numpy as np
from PIL import Image
from scipy import ndimage as ndi

from cairo_flat_svg import render


def digest(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def bounds(svg, env):
    rows = subprocess.check_output(['inkscape', str(svg), '--query-all'], text=True, env=env).splitlines()
    result = {}
    for row in rows:
        cols = row.split(',')
        if cols[0].startswith('white-'):
            x, y, w, h = map(float, cols[1:])
            result[cols[0]] = np.array([x, y, x + w, y + h])
    return result


def renderer_fixture(folder):
    # Equivalent absolute and shorthand/relative cubic paths; asymmetric
    # placement and an enclosed hole exercise transforms and fill direction.
    variants = [
        ('translate(3,4)', 'M0,0 L25,0 L25,22 L0,22 Z M5,5 L5,17 L20,17 L20,5 Z M30,0 C35,0 35,8 40,8 C45,8 45,0 50,0 L50,20 L30,20 Z'),
        ('matrix(1,0,0,1,3,4)', 'm0,0 h25 v22 h-25 z m5,5 v12 h15 v-12 z M30,0 c5,0 5,8 10,8 s5,-8 10,-8 v20 h-20 z')]
    images = []
    for i, (transform, path) in enumerate(variants):
        svg, png = folder / f'fixture-{i}.svg', folder / f'fixture-{i}.png'
        svg.write_text(f'<svg xmlns="http://www.w3.org/2000/svg" width="60" height="32" viewBox="0 0 60 32"><path fill="#ffaa00" transform="{transform}" d="{path}"/></svg>')
        render(svg, png, (60, 32))
        images.append(np.array(Image.open(png).convert('RGB')))
    assert np.array_equal(*images)
    image = images[0]
    assert tuple(image[5, 4]) == (255, 170, 0)
    assert tuple(image[12, 12]) == (0, 0, 0)
    assert tuple(image[1, 1]) == (0, 0, 0)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('candidate', type=Path)
    parser.add_argument('--repeat', action='store_true')
    args = parser.parse_args()
    p = args.candidate.resolve()
    report = json.loads((p / 'report.json').read_text())
    assert all(digest(Path(name)) == sha for name, sha in report['input_sha256'].items())
    assert digest(p / 'preview.png') == report['preview_sha256']
    with Image.open(p / 'preview.png') as image:
        assert image.size == (512, 384) and image.mode == 'P' and len(image.getpalette()) == 192
        rgba = np.array(image.convert('RGBA'))
    rgb = rgba[:, :, :3]
    assert not np.any(rgb % 85) and np.all(rgba[:, :, 3] == 255)
    env = dict(os.environ, INKSCAPE_PROFILE_DIR=str(p / 'inkscape-profile'))
    before, after = bounds(p / 'traced-colors.svg', env), bounds(p / 'colored-shapes.svg', env)
    assert before.keys() == after.keys()
    movement = max(float(np.abs(before[k] - after[k]).max()) for k in before)
    assert movement <= 1.0, f'Simplification moved a bounding edge {movement} target pixels'
    ink = np.array(Image.open(p / 'inkscape-export.png').convert('RGB'))
    uniform = np.all(ndi.minimum_filter(ink, size=(3, 3, 1)) == ndi.maximum_filter(ink, size=(3, 3, 1)), axis=2)
    uniform &= ~np.any(ink % 85, axis=2)
    assert np.array_equal(rgb[uniform], ink[uniform])
    with tempfile.TemporaryDirectory(prefix='skin013-color-verify-') as temp:
        temp = Path(temp)
        renderer_fixture(temp)
        repeated = None
        if args.repeat:
            command = [sys.executable, str(p / 'colorize_shapes.py'), '--mask', report['source_mask'],
                       '--reference', report['color_reference'], '--params', str(p / 'parameters.json'),
                       '--out', str(temp / 'repeat')]
            subprocess.run(command, check=True, capture_output=True, text=True, timeout=180)
            repeated = digest(temp / 'repeat/preview.png') == digest(p / 'preview.png')
            assert repeated
            rejected = subprocess.run(command, capture_output=True, text=True)
            assert rejected.returncode != 0 and 'Output exists' in rejected.stderr
            assert digest(temp / 'repeat/preview.png') == digest(p / 'preview.png')
    checks = {'passed': True, 'source_hashes_unchanged': True, 'size': [512, 384],
              'indexed_palette_entries': 64, 'visible_colors': len(np.unique(rgb.reshape(-1, 3), axis=0)),
              'partial_alpha_pixels': 0, 'off_palette_pixels': 0,
              'max_simplified_bbox_edge_movement_target_pixels': movement,
              'inkscape_agrees_on_uniform_interior_pixels': int(uniform.sum()),
              'renderer_relative_curve_transform_hole_fixture': 'pass',
              'repeat_png_byte_identical': repeated, 'existing_output_refused': repeated}
    output = p / 'verification.json'
    if not output.exists():
        output.write_text(json.dumps(checks, indent=2) + '\n')
    print(json.dumps(checks, indent=2))


if __name__ == '__main__':
    main()

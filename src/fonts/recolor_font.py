#!/usr/bin/env python3
"""Recolor a grayscale font atlas for exact Agon foreground/background pairs.

Uses agon-utils for palette conversion and RGBA2222 encoding/decoding. No font
editor imports, resizing, thresholding, dithering or runtime installation.
"""
from __future__ import annotations

import argparse
import hashlib
import io
import json
from pathlib import Path
import re
import tempfile
import xml.etree.ElementTree as ET

import numpy as np
from PIL import Image
import agonutils as au

PROJECT = Path(__file__).resolve().parents[2]
DEFAULT_PALETTE = PROJECT.parent / 'agon-utils/examples/palettes/Agon64.gpl'
DEFAULT_VARIANTS = ('normal=FFFFAA,000000', 'selected=000000,FFAA55')
DENOMINATOR = 255 * 255


def digest(data):
    return hashlib.sha256(data).hexdigest()


def rgb(value):
    text = value.removeprefix('#')
    if not re.fullmatch(r'[0-9a-fA-F]{6}', text):
        raise ValueError(f'Expected RRGGBB or #RRGGBB, got {value!r}')
    color = tuple(int(text[i:i + 2], 16) for i in (0, 2, 4))
    if any(c % 85 for c in color):
        raise ValueError(f'{value}: foreground/background must be exact Agon64 colors (channels 0, 85, 170, 255)')
    return color


def variants_from_strings(values):
    result = []
    for value in values:
        match = re.fullmatch(r'([a-z][a-z0-9-]*)=([^,]+),([^,]+)', value)
        if not match:
            raise ValueError('Variant syntax: name=RRGGBB,RRGGBB (foreground,background)')
        name, fg, bg = match.groups()
        if any(v['name'] == name for v in result):
            raise ValueError(f'Duplicate variant name: {name}')
        result.append({'name': name, 'foreground': rgb(fg), 'background': rgb(bg)})
    if not result:
        raise ValueError('At least one color variant is required')
    return result


def palette_bytes(path):
    data = path.read_bytes()
    colors = []
    for line in data.decode().splitlines():
        match = re.match(r'^\s*(\d+)\s+(\d+)\s+(\d+)(?:\s|$)', line)
        if match:
            colors.append(tuple(map(int, match.groups())))
    cube = {(r, g, b) for r in (0, 85, 170, 255)
            for g in (0, 85, 170, 255) for b in (0, 85, 170, 255)}
    if len(colors) != 64 or set(colors) != cube:
        raise ValueError('Palette must contain each of the 64 Agon RGB colors exactly once')
    return data


def coverage_from_image(image, channel='gray', invert=False):
    """Integer coverage / 65025 preserves grayscale × alpha without early rounding."""
    rgba = np.asarray(image.convert('RGBA')).astype(np.uint32)
    if channel == 'gray':
        visible = rgba[:, :, 3] != 0
        if np.any((rgba[:, :, :3] != rgba[:, :, :1]) & visible[:, :, None]):
            raise ValueError('Gray-mask mode requires grayscale pixels; use --mask-channel alpha for an alpha-only mask')
        gray = 255 - rgba[:, :, 0] if invert else rgba[:, :, 0]
        return gray * rgba[:, :, 3]
    if channel == 'alpha':
        alpha = 255 - rgba[:, :, 3] if invert else rgba[:, :, 3]
        return alpha * 255
    raise ValueError(f'Unknown mask channel: {channel}')


def write_metadata(path, png, name, variant, cell, columns, rows, first_char):
    # Serialize the editor's established XML schema; no dependency on its
    # actively changing rendering code or shared temporary files.
    width, height = cell
    settings = {
        'original_font_path': str(png.resolve()), 'font_name': name,
        'font_variant': variant['name'], 'font_width': width, 'font_height': height,
        'font_width_mod': width, 'font_height_mod': height, 'point_size': height,
        'offset_left': 0, 'offset_top': 0, 'offset_width': 0, 'offset_height': 0,
        'scale_width': 0, 'scale_height': 0, 'raster_type': 'palette',
        'threshold': 128, 'palette': 'Agon64',
        'fg_color': ', '.join(map(str, (*variant['foreground'], 255))),
        'bg_color': ', '.join(map(str, (*variant['background'], 255))),
        'ascii_start': first_char, 'ascii_end': first_char + columns * rows - 1,
        'chars_per_row': columns,
    }
    root = ET.Element('settings')
    for key, value in settings.items():
        ET.SubElement(root, 'setting', name=key, value=str(value))
    ET.indent(root, space='  ')
    ET.ElementTree(root).write(path, encoding='utf-8', xml_declaration=True)


def build(source, output, *, cell=(6, 12), columns=16, rows=16, first_char=0,
          variant_specs=DEFAULT_VARIANTS, mask_channel='gray', invert=False,
          palette=DEFAULT_PALETTE):
    source, output, palette = Path(source).resolve(), Path(output).resolve(), Path(palette).resolve()
    variants = variants_from_strings(variant_specs)
    if len(cell) != 2 or any(n <= 0 for n in (*cell, columns, rows)):
        raise ValueError('Cell and grid dimensions must be positive')
    if not 0 <= first_char <= first_char + columns * rows - 1 <= 255:
        raise ValueError('The grid must fit within character slots 0–255')
    data = source.read_bytes()
    with Image.open(io.BytesIO(data)) as original:
        if original.format != 'PNG' or original.mode not in ('1', 'L', 'LA', 'P', 'RGB', 'RGBA'):
            raise ValueError('Input must be an 8-bit, indexed or binary PNG mask')
        expected = (cell[0] * columns, cell[1] * rows)
        if original.size != expected:
            raise ValueError(f'PNG is {original.size}; expected {expected} for {columns}×{rows} cells of {cell}. No automatic resizing.')
        coverage = coverage_from_image(original, mask_channel, invert)
    palette_data = palette_bytes(palette)
    levels, indices, inverse, counts = np.unique(coverage, return_index=True,
                                                return_inverse=True, return_counts=True)
    output.mkdir(parents=True, exist_ok=False)
    report = {
        'source': str(source), 'source_sha256': digest(data), 'size': list(expected),
        'cell': list(cell), 'columns': columns, 'rows': rows, 'first_char': first_char,
        'mask_channel': mask_channel, 'invert': invert, 'coverage_denominator': DENOMINATOR,
        'coverage_levels': len(levels),
        'input_has_intermediate_coverage': bool(np.any((coverage > 0) & (coverage < DENOMINATOR))),
        'blend': 'foreground * coverage + background * (1 - coverage), in RGB code values; round once to RGB8',
        'palette_method': 'agonutils RGB nearest color', 'dithering': False,
        'alpha': 'opaque; background is baked into each variant',
        'palette_sha256': digest(palette_data),
        'tool_sha256': {'recolor_font.py': digest(Path(__file__).read_bytes()),
                        'agonutils': digest(Path(au.__file__).read_bytes())},
        'variants': [],
    }
    # Snapshot palette data so a concurrent edit in another project cannot
    # change one variant but leave another using the earlier palette.
    with tempfile.TemporaryDirectory(prefix='font-color-') as directory:
        temp = Path(directory)
        local_palette = temp / 'Agon64.gpl'
        local_palette.write_bytes(palette_data)
        for variant in variants:
            fg = np.asarray(variant['foreground'], dtype=np.uint32)
            bg = np.asarray(variant['background'], dtype=np.uint32)
            mixed = ((coverage[:, :, None] * fg + (DENOMINATOR - coverage[:, :, None]) * bg
                      + DENOMINATOR // 2) // DENOMINATOR).astype(np.uint8)
            blend_file, raw_file = temp / 'blend.png', temp / 'atlas.rgba2'
            Image.fromarray(mixed).save(blend_file)
            # Reuse canonical palette conversion AND byte packing. The raw file
            # is a temporary row-major atlas, not a glyph-major .font payload.
            au.img_to_rgba2(str(blend_file), str(raw_file), str(local_palette), 'RGB', None)
            if raw_file.stat().st_size != expected[0] * expected[1]:
                raise RuntimeError('Unexpected RGBA2222 atlas byte count')
            png = output / f'{source.stem}-{variant["name"]}.png'
            au.rgba2_to_img(str(raw_file), str(png), *expected)
            with Image.open(png) as result:
                rgba = np.asarray(result.convert('RGBA'))
            if np.any(rgba[:, :, :3] % 85) or np.any(rgba[:, :, 3] != 255):
                raise RuntimeError('Converter output is not opaque Agon64')
            # A coverage value must map to one color everywhere in the sheet.
            # This also catches accidental spatial dithering in the converter.
            mapped = rgba.reshape(-1, 4)[indices]
            if not np.array_equal(mapped[inverse.reshape(-1)].reshape(rgba.shape), rgba):
                raise RuntimeError('Inconsistent mapping of identical coverage values')
            for level, endpoint in [(0, bg), (DENOMINATOR, fg)]:
                if np.any(rgba[:, :, :3][coverage == level] != endpoint):
                    raise RuntimeError('Foreground/background endpoint changed')
            xml = png.with_suffix('.png.xml')
            write_metadata(xml, png, source.stem, variant, cell, columns, rows, first_char)
            report['variants'].append({**variant, 'png': png.name, 'metadata': xml.name,
                'png_sha256': digest(png.read_bytes()),
                'visible_colors': len(np.unique(rgba.reshape(-1, 4), axis=0)),
                'coverage_to_rgb': [
                    {'numerator': int(level), 'pixels': int(count), 'rgb': list(map(int, color[:3]))}
                    for level, count, color in zip(levels, counts, mapped)],
            })
    if source.read_bytes() != data:
        raise RuntimeError('Source changed during conversion; rerun using a stable saved PNG')
    report['source_unchanged'] = True
    (output / 'colors.json').write_text(json.dumps(report, indent=2) + '\n')
    return report


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('source', type=Path, help='Grayscale or explicit alpha-mask PNG font sheet')
    parser.add_argument('--output', required=True, type=Path, help='New output directory; existing directories are rejected')
    parser.add_argument('--cell', nargs=2, type=int, default=(6, 12), metavar=('WIDTH', 'HEIGHT'))
    parser.add_argument('--columns', type=int, default=16)
    parser.add_argument('--rows', type=int, default=16)
    parser.add_argument('--first-char', type=int, default=0)
    parser.add_argument('--variant', action='append', metavar='NAME=FG,BG',
                        help='Repeatable; replaces normal/selected defaults. Colors are RRGGBB or #RRGGBB.')
    parser.add_argument('--mask-channel', choices=('gray', 'alpha'), default='gray',
                        help='gray: white is ink, black is background, multiplied by alpha; alpha: ignore RGB')
    parser.add_argument('--invert', action='store_true', help='Invert grayscale before applying alpha, or invert the alpha-only mask')
    parser.add_argument('--palette', type=Path, default=DEFAULT_PALETTE)
    args = parser.parse_args()
    try:
        result = build(args.source, args.output, cell=tuple(args.cell), columns=args.columns,
                       rows=args.rows, first_char=args.first_char,
                       variant_specs=args.variant or DEFAULT_VARIANTS,
                       mask_channel=args.mask_channel, invert=args.invert, palette=args.palette)
    except (OSError, ValueError, RuntimeError) as error:
        parser.exit(1, f'Font recoloring failed: {error}\n')
    print(f'Saved {len(result["variants"])} color variants in {args.output}')
    print(f'{result["size"][0]}×{result["size"][1]} pixels; {result["coverage_levels"]} source coverage levels; exact Agon64, opaque, no dithering.')
    if not result['input_has_intermediate_coverage']:
        print('Source has no intermediate coverage; antialiasing cannot be recovered from a binary export.')


if __name__ == '__main__':
    main()

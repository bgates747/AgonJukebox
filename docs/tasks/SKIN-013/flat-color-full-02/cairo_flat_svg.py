"""Render our flat path SVG subset with installed libcairo and antialiasing off.

This deliberately rejects unsupported SVG features. It is not a general SVG
renderer. Our generated documents contain solid-filled paths and rectangles,
simple affine transforms, and a viewBox. Inkscape's simplified cubic paths are
supported, including relative/shorthand commands. No raster post-quantization.
"""
import ctypes as C
import ctypes.util
import re
import xml.etree.ElementTree as ET

import numpy as np
from PIL import Image

TOKEN = re.compile(r'[A-Za-z]|[-+]?(?:\d*\.\d+|\d+\.?\d*)(?:[eE][-+]?\d+)?')


class Matrix(C.Structure):
    _fields_ = [(n, C.c_double) for n in ('xx', 'yx', 'xy', 'yy', 'x0', 'y0')]


def api():
    lib = C.CDLL(ctypes.util.find_library('cairo'))
    p, d, i = C.c_void_p, C.c_double, C.c_int
    specs = {
        'image_surface_create': (p, [i, i, i]), 'create': (p, [p]),
        'destroy': (None, [p]), 'surface_destroy': (None, [p]),
        'set_antialias': (None, [p, i]), 'set_fill_rule': (None, [p, i]),
        'set_source_rgb': (None, [p, d, d, d]), 'paint': (None, [p]),
        'scale': (None, [p, d, d]), 'translate': (None, [p, d, d]),
        'transform': (None, [p, C.POINTER(Matrix)]),
        'save': (None, [p]), 'restore': (None, [p]), 'new_path': (None, [p]),
        'move_to': (None, [p, d, d]), 'line_to': (None, [p, d, d]),
        'curve_to': (None, [p, d, d, d, d, d, d]),
        'close_path': (None, [p]), 'fill': (None, [p]),
        'rectangle': (None, [p, d, d, d, d]),
        'status': (i, [p]), 'surface_status': (i, [p]),
        'surface_write_to_png': (i, [p, C.c_char_p]),
        'version_string': (C.c_char_p, []),
    }
    for name, (result, args) in specs.items():
        fn = getattr(lib, 'cairo_' + name)
        fn.restype, fn.argtypes = result, args
    return lib


def append_path(lib, ctx, data):
    tokens = TOKEN.findall(data)
    arity = dict(M=2, L=2, H=1, V=1, C=6, S=4, Q=4, T=2)
    pos = start = (0., 0.)
    cubic = quadratic = None
    previous, command, index = '', None, 0
    while index < len(tokens):
        if tokens[index].isalpha():
            command = tokens[index]
            index += 1
            if command.upper() == 'Z':
                lib.cairo_close_path(ctx)
                pos, previous, cubic, quadratic = start, 'Z', None, None
                command = None
                continue
        if command is None or command.upper() not in arity:
            raise ValueError(f'Unsupported SVG path command: {command}')
        kind = command.upper()
        n = arity[kind]
        vals = list(map(float, tokens[index:index + n]))
        if len(vals) != n:
            raise ValueError('Truncated SVG path')
        index += n
        def point(x, y):
            return (x + pos[0], y + pos[1]) if command.islower() else (x, y)
        end = None
        if kind in ('M', 'L'):
            end = point(*vals)
            (lib.cairo_move_to if kind == 'M' else lib.cairo_line_to)(ctx, *end)
            if kind == 'M':
                start = end
                command = 'l' if command.islower() else 'L'
        elif kind in ('H', 'V'):
            value = vals[0] + (pos[0 if kind == 'H' else 1] if command.islower() else 0)
            end = (value, pos[1]) if kind == 'H' else (pos[0], value)
            lib.cairo_line_to(ctx, *end)
        elif kind in ('C', 'S'):
            if kind == 'C':
                c1, c2, end = point(*vals[:2]), point(*vals[2:4]), point(*vals[4:])
            else:
                c1 = tuple(2 * p - c for p, c in zip(pos, cubic)) if previous in ('C', 'S') else pos
                c2, end = point(*vals[:2]), point(*vals[2:])
            lib.cairo_curve_to(ctx, *c1, *c2, *end)
            cubic = c2
        elif kind in ('Q', 'T'):
            if kind == 'Q':
                control, end = point(*vals[:2]), point(*vals[2:])
            else:
                control = tuple(2 * p - c for p, c in zip(pos, quadratic)) if previous in ('Q', 'T') else pos
                end = point(*vals)
            c1 = tuple(p + 2 * (q - p) / 3 for p, q in zip(pos, control))
            c2 = tuple(e + 2 * (q - e) / 3 for e, q in zip(end, control))
            lib.cairo_curve_to(ctx, *c1, *c2, *end)
            quadratic = control
        if kind not in ('C', 'S'): cubic = None
        if kind not in ('Q', 'T'): quadratic = None
        pos, previous = end, kind


def render(svg, output, size=(512, 384)):
    lib = api()
    root = ET.parse(svg).getroot()
    view = list(map(float, root.get('viewBox').split()))
    surface = lib.cairo_image_surface_create(0, *size)  # ARGB32
    ctx = lib.cairo_create(surface)
    try:
        lib.cairo_set_antialias(ctx, 1)  # CAIRO_ANTIALIAS_NONE
        lib.cairo_set_source_rgb(ctx, 0, 0, 0)
        lib.cairo_paint(ctx)
        lib.cairo_scale(ctx, size[0] / view[2], size[1] / view[3])
        lib.cairo_translate(ctx, -view[0], -view[1])
        for node in root:
            tag = node.tag.rsplit('}', 1)[-1]
            if tag in ('title', 'desc', 'metadata', 'namedview'): continue
            if tag == 'defs' and not len(node): continue
            if tag not in ('path', 'rect'):
                raise ValueError(f'Unsupported SVG element: {tag}')
            style = dict(x.split(':', 1) for x in node.get('style', '').split(';') if ':' in x)
            attrs = dict(node.attrib, **style)
            for attr in ('filter', 'clip-path', 'mask', 'stroke'):
                if attrs.get(attr, 'none') != 'none': raise ValueError(f'Unsupported {attr}')
            for attr in ('opacity', 'fill-opacity'):
                if float(attrs.get(attr, '1')) != 1: raise ValueError(f'Unsupported {attr}')
            fill = attrs.get('fill', '#000000')
            if not re.fullmatch(r'#[0-9a-fA-F]{6}', fill): raise ValueError(f'Unsupported fill: {fill}')
            color = tuple(int(fill[j:j + 2], 16) for j in (1, 3, 5))
            lib.cairo_save(ctx)
            transform = node.get('transform', '')
            if transform:
                match = re.fullmatch(r'(translate|matrix)\(([^)]+)\)', transform)
                if not match: raise ValueError(f'Unsupported transform: {transform}')
                vals = list(map(float, re.split(r'[ ,]+', match[2].strip())))
                if match[1] == 'translate': lib.cairo_translate(ctx, vals[0], vals[1] if len(vals) == 2 else 0)
                elif len(vals) == 6: lib.cairo_transform(ctx, C.byref(Matrix(*vals)))
                else: raise ValueError('Malformed affine transform')
            lib.cairo_new_path(ctx)
            rule = attrs.get('fill-rule', 'nonzero')
            if rule not in ('nonzero', 'evenodd'): raise ValueError(rule)
            lib.cairo_set_fill_rule(ctx, int(rule == 'evenodd'))
            lib.cairo_set_source_rgb(ctx, *(v / 255 for v in color))
            if tag == 'path': append_path(lib, ctx, node.get('d', ''))
            else:
                if node.get('rx') or node.get('ry'): raise ValueError('Rounded rectangle unsupported')
                lib.cairo_rectangle(ctx, *(float(node.get(k, '0')) for k in ('x', 'y', 'width', 'height')))
            lib.cairo_fill(ctx)
            lib.cairo_restore(ctx)
        assert lib.cairo_status(ctx) == lib.cairo_surface_status(surface) == 0
        assert lib.cairo_surface_write_to_png(surface, str(output).encode()) == 0
    finally:
        lib.cairo_destroy(ctx)
        lib.cairo_surface_destroy(surface)
    rgb = np.array(Image.open(output).convert('RGB'))
    if np.any(rgb % 85): raise ValueError('Raster contains off-palette colors')
    return {'renderer': 'libcairo', 'version': lib.cairo_version_string().decode(),
            'antialias': 'CAIRO_ANTIALIAS_NONE', 'post_render_quantization': False}

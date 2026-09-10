"""Small ctypes adapter for the already installed Potrace 1.16 library.

ABI verified against the official 1.16 src/potracelib.h and library API:
https://potrace.sourceforge.net/potracelib.pdf
No tracing algorithm is reimplemented here. Masks use a top-left origin;
input rows and SVG coordinates consistently use that convention.
"""
import ctypes as C
import ctypes.util

import numpy as np


class Point(C.Structure):
    _fields_ = [('x', C.c_double), ('y', C.c_double)]


class Curve(C.Structure):
    _fields_ = [('n', C.c_int), ('tag', C.POINTER(C.c_int)),
                ('c', C.POINTER(Point * 3))]


class TracePath(C.Structure):
    pass


TracePath._fields_ = [('area', C.c_int), ('sign', C.c_int), ('curve', Curve),
                     ('next', C.POINTER(TracePath)),
                     ('childlist', C.POINTER(TracePath)),
                     ('sibling', C.POINTER(TracePath)), ('priv', C.c_void_p)]


class State(C.Structure):
    _fields_ = [('status', C.c_int), ('plist', C.POINTER(TracePath)),
                ('priv', C.c_void_p)]


class Progress(C.Structure):
    _fields_ = [('callback', C.c_void_p), ('data', C.c_void_p),
                ('min', C.c_double), ('max', C.c_double), ('epsilon', C.c_double)]


class Parameters(C.Structure):
    _fields_ = [('turdsize', C.c_int), ('turnpolicy', C.c_int),
                ('alphamax', C.c_double), ('opticurve', C.c_int),
                ('opttolerance', C.c_double), ('progress', Progress)]


class Bitmap(C.Structure):
    _fields_ = [('w', C.c_int), ('h', C.c_int), ('dy', C.c_int),
                ('map', C.POINTER(C.c_ulong))]


def library():
    name = ctypes.util.find_library('potrace')
    if not name:
        raise RuntimeError('The installed libpotrace library is required')
    lib = C.CDLL(name)
    lib.potrace_version.restype = C.c_char_p
    lib.potrace_param_default.restype = C.POINTER(Parameters)
    lib.potrace_param_default.argtypes = []
    lib.potrace_param_free.argtypes = [C.POINTER(Parameters)]
    lib.potrace_param_free.restype = None
    lib.potrace_trace.argtypes = [C.POINTER(Parameters), C.POINTER(Bitmap)]
    lib.potrace_trace.restype = C.POINTER(State)
    lib.potrace_state_free.argtypes = [C.POINTER(State)]
    lib.potrace_state_free.restype = None
    return lib


def trace(mask, alphamax=1.0, opttolerance=0.2):
    lib = library()
    mask = np.asarray(mask, dtype=bool)
    h, w = mask.shape
    word_bytes = C.sizeof(C.c_ulong)
    bits = word_bytes * 8
    dy = (w + bits - 1) // bits
    padded = np.pad(mask, ((0, 0), (0, dy * bits - w)))
    packed = np.packbits(padded, axis=1, bitorder='big')
    words = np.ascontiguousarray(packed.view(f'>u{word_bytes}').astype(f'u{word_bytes}'))
    bitmap = Bitmap(w, h, dy, words.ctypes.data_as(C.POINTER(C.c_ulong)))
    params = lib.potrace_param_default()
    if not params:
        raise MemoryError('Potrace parameter allocation failed')
    state = None
    try:
        params.contents.turdsize = 0  # All cleanup is explicit outside the tracer.
        params.contents.turnpolicy = 0  # BLACK: retain diagonal ink connections.
        params.contents.alphamax = alphamax
        params.contents.opticurve = 1
        params.contents.opttolerance = opttolerance
        state = lib.potrace_trace(params, C.byref(bitmap))
        if not state or state.contents.status != 0:
            raise RuntimeError('Potrace did not complete')
        pointers, node = [], state.contents.plist
        while node:
            pointers.append(node)
            node = node.contents.next
        ids = {C.addressof(p.contents): i for i, p in enumerate(pointers)}
        result = []
        for i, pointer in enumerate(pointers):
            p = pointer.contents
            points = []
            for j in range(p.curve.n):
                tag = p.curve.tag[j]
                if tag not in (1, 2):
                    raise ValueError('Unexpected Potrace segment tag')
                # Corner c[0] is undefined and must not be read.
                use = range(3) if tag == 1 else range(1, 3)
                points.append({'kind': 'C' if tag == 1 else 'L',
                               'points': [[p.curve.c[j][k].x, p.curve.c[j][k].y]
                                          for k in use]})
            children, child = [], p.childlist
            while child:
                children.append(ids[C.addressof(child.contents)])
                child = child.contents.sibling
            result.append(dict(id=i, sign=chr(p.sign), area=p.area,
                               children=children, segments=points))
        return result
    finally:
        if state:
            lib.potrace_state_free(state)
        lib.potrace_param_free(params)


def path_data(path):
    def xy(point):
        return f'{point[0]:.5f},{point[1]:.5f}'
    commands = ['M' + xy(path['segments'][-1]['points'][-1])]
    for segment in path['segments']:
        commands.append(segment['kind'] + ' '.join(xy(p) for p in segment['points']))
    return ' '.join(commands) + ' Z'


def svg_groups(paths, prefix='ink', fill='#000000'):
    """One editable compound path per ink component, with its immediate holes."""
    from html import escape
    result = []
    for path in paths:
        if path['sign'] != '+':
            continue
        members = [path] + [paths[i] for i in path['children']]
        assert all(p['sign'] == '-' for p in members[1:])
        data = ' '.join(path_data(p) for p in members)
        result.append(f'<path id="{escape(prefix)}-{path["id"]:03d}" '
                      f'fill="{escape(fill)}" fill-rule="nonzero" d="{data}"/>')
    return '\n'.join(result)


def svg_document(paths, width, height, prefix='ink', background=False, fill='#000000'):
    bg = f'<rect width="{width}" height="{height}" fill="#ffffff"/>' if background else ''
    return (f'<svg xmlns="http://www.w3.org/2000/svg" width="{width}" height="{height}" '
            f'viewBox="0 0 {width} {height}"><title>{prefix}: traced filled regions</title>'
            f'{bg}{svg_groups(paths, prefix, fill)}</svg>\n')

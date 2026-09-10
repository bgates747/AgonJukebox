"""Make a separate, non-overwriting GIMP review packet from the v6 proof.

This only extracts/copies pixels; it does not refine, resample or quantize them.
Run with the project .venv. An existing destination is deliberately refused.
"""

import argparse
import hashlib
import html
import json
from pathlib import Path
import shutil

import numpy as np
from PIL import Image


ROOT = Path(__file__).resolve().parent
PALETTE = Path('/home/smith/Agon/mystuff/agon-utils/examples/slideshow/palettes/Agon64.gpl')


def digest(data):
    return hashlib.sha256(data).hexdigest()


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--proof', type=Path, default=ROOT / 'review-v6')
    parser.add_argument('--output', type=Path, default=ROOT / 'element-review')
    args = parser.parse_args()
    proof, out = args.proof.resolve(), args.output.resolve()
    if out.exists():
        parser.error(f'Refusing to overwrite potential hand edits in {out}')
    manifest = json.loads((proof / 'manifest.json').read_text())
    params = json.loads((proof / 'resolved-parameters.json').read_text())
    static = Image.open(proof / 'static.png').convert('RGB')
    colors = []
    for line in PALETTE.read_text().splitlines():
        words = line.split()
        if len(words) >= 3 and all(w.isdecimal() for w in words[:3]):
            colors.append(tuple(map(int, words[:3])))
    assert len(colors) == len(set(colors)) == 64
    assert set(colors) == {(r, g, b) for r in range(0, 256, 85)
                           for g in range(0, 256, 85) for b in range(0, 256, 85)}
    lookup = {rgb: i for i, rgb in enumerate(colors)}
    out.mkdir()
    (out / 'components').mkdir()
    (out / 'tiles').mkdir()
    shutil.copyfile(PALETTE, out / 'Agon64.gpl')
    shutil.copyfile(proof / 'preview.png', out / 'reference.png')
    shutil.copyfile(proof / 'static.png', out / 'static-reference.png')

    entries = []

    def save(image, file, title, **metadata):
        image = image.convert('RGB')
        # Exact lookup, not nearest-color quantization. Off-palette input fails.
        indices = bytes(lookup[rgb] for rgb in image.get_flattened_data())
        indexed = Image.frombytes('P', image.size, indices)
        indexed.putpalette([channel for color in colors for channel in color])
        indexed.save(out / file, optimize=False)
        with Image.open(out / file) as loaded:
            assert loaded.mode == 'P' and loaded.size == image.size
            assert len(loaded.getpalette()) == 64 * 3
            assert loaded.convert('RGB').tobytes() == image.tobytes()
        entry = dict(file=file, title=title, size=list(image.size),
                     initial_png_sha256=digest((out / file).read_bytes()),
                     initial_rgb_sha256=digest(image.tobytes()), **metadata)
        entries.append(entry)
        return entry

    # Larger, named review units retain surrounding context for hand editing.
    # Some intentionally overlap (e.g. complete control row and separate frames).
    crops = []
    for side, x in [('left', 0), ('right', 444)]:
        for name, y0, y1 in [
            ('fan-and-cap', 0, 83), ('upper-column-transition', 83, 135),
            ('column-shaft', 135, 236), ('lower-column-end', 236, 313),
            ('column-plaque', 313, 347),
        ]:
            crops.append((f'{side}-{name}', [x, y0, x + 68, y1]))
    crown = next(p for p in params['parts'] if p['name'] == 'central-crown-and-title')
    crops.extend([
        ('central-crown-and-title', crown['box']),
        ('upper-left-stepped-border', [68, 0, 133, 73]),
        ('upper-right-stepped-border', [380, 0, 444, 73]),
        ('browser-frame-and-headings', [68, 70, 444, 240]),
        ('now-playing-frame-and-fans', [68, 228, 444, 302]),
        ('complete-transport-row', [68, 302, 444, 347]),
        ('footer-left-panel', [0, 347, 151, 384]),
        ('footer-central-jewel-and-wings', [151, 347, 363, 384]),
        ('footer-right-panel', [363, 347, 512, 384]),
    ])
    for number, (name, box) in enumerate(crops, 1):
        save(static.crop(box), f'components/{number:02d}-{name}.png',
             name.replace('-', ' ').title(), kind='screen-crop', screen_box=box,
             source_image='static-reference.png')

    tile_paths = {}
    for asset in manifest['assets']:
        uses = [op for op in manifest['operations'] if op.get('asset') == asset['name']]
        regions = sorted({op['region'] for op in uses})
        name = regions[0] if len(regions) == 1 else 'shared-' + asset['kind']
        file = f"tiles/{asset['name']}-{name}-{asset['kind']}.png"
        tile_paths[asset['name']] = file
        image = Image.open(proof / asset['png']).convert('RGB')
        save(image, file, f"{asset['name']} · {name} · {asset['kind']}",
             kind='reusable-asset', asset=asset['name'], regions=regions,
             placements=uses, derive=asset.get('derive'),
             source_png=asset['png'])
        # Expose the useful complete frames and symbols alongside large pieces.
        if asset['kind'] in ('frame', 'icon'):
            number = sum(e['file'].startswith('components/') for e in entries) + 1
            save(image, f'components/{number:02d}-{name}-{asset["kind"]}.png',
                 f'{name} {asset["kind"]}'.replace('-', ' ').title(),
                 kind='reusable-asset', asset=asset['name'], regions=regions,
                 placements=uses, same_pixels_as=file)

    # Check that the editable tile copies still reconstruct the static image.
    rebuilt = Image.new('RGB', static.size)
    for op in manifest['operations']:
        if op['op'] == 'fill':
            rebuilt.paste(tuple(op['color']), tuple(op['box']))
        else:
            tile = Image.open(out / tile_paths[op['asset']]).convert('RGB')
            for i in range(op.get('count', 1)):
                x, y = op['at']
                dx, dy = op.get('step', [0, 0])
                rebuilt.paste(tile, (x + i * dx, y + i * dy))
    assert rebuilt.tobytes() == static.tobytes()
    # Review crops collectively cover the original canvas, including overlaps.
    coverage = np.zeros((static.height, static.width), dtype=bool)
    for _, (x0, y0, x1, y1) in crops:
        coverage[y0:y1, x0:x1] = True
    assert coverage.all()

    packet = dict(format='skin012-editable-review-1', source_proof=str(proof),
                  source_manifest_sha256=digest((proof / 'manifest.json').read_bytes()),
                  canvas_size=list(static.size), palette=colors,
                  box_convention='[left, top, right-exclusive, bottom-exclusive]',
                  operations=manifest['operations'], tile_files=tile_paths, elements=entries)
    (out / 'index.json').write_text(json.dumps(packet, indent=2) + '\n')
    counts = {group: sum(e['file'].startswith(group + '/') for e in entries)
              for group in ('components', 'tiles')}
    report = dict(passed=True, **counts, indexed_palette_entries=64,
                  every_export_matches_source_pixels=True, static_reassembly_exact=True,
                  complete_component_coverage=True, refinement_applied=False)
    (out / 'export-checks.json').write_text(json.dumps(report, indent=2) + '\n')

    readme = f'''# Art Deco elements for review and GIMP editing

Start with [the visual gallery](index.html) or open **components/** in GIMP.
These are copies of the current `review-v6` proof, exported after the Author
reported remaining dirt/ragged edges. No further cleanup was applied.

1. **components/** — {counts['components']} named pieces: both columns in sections,
   crown/title, stepped borders, browser frame, now-playing surround, transport
   row, footer panels, and individual button surrounds and symbols.
2. **tiles/** — all {counts['tiles']} exact reusable bitmap assets, with descriptive
   filenames and their original part IDs. Repeated strips and fallback patches
   are here, as well as the frames, icons and ornaments.
3. **reference.png** shows the complete composition; **static-reference.png**
   shows the art without sample filenames, timings and other changing content.
4. **index.json** records native dimensions, original pixel/file hashes,
   screen coordinates, sharing, repeat placements and mirrored derivations.

All editable PNGs are native-size, opaque indexed images with the complete
64-color Agon palette embedded. Pixel colors are unchanged: exact palette
lookup only, no resampling or dithering. **Agon64.gpl** is also included for
GIMP's palette dock. The gallery enlarges only the display, using nearest pixels.

You can edit an individual PNG and export back to the same filename, or save
an XCF beside it and export a PNG when ready. Keep its dimensions for direct
reassembly. Filenames make convenient references for feedback.

The larger pieces are convenient review/edit regions; some overlap. Separate
control PNGs duplicate the corresponding tile for convenience. Their mapping
is recorded so changes can be reconciled in a later refinement pass. Editing
a shared tile can affect several placements; the gallery lists those uses.
The right top fan is currently derived by mirroring the left one, with both
orientations supplied for inspection. No edits are automatically imported.

The original source, v6 proof and AGNB container are preserved. This exporter
refuses to write into an existing destination, protecting subsequent hand edits.
To create another fresh packet from the project root:

```bash
.venv/bin/python docs/tasks/SKIN-012/export_elements.py --output /path/to/new-folder
```

Export checks: all {len(entries)} editable PNGs match their input pixels;
the {counts['tiles']} tiles reconstruct `static-reference.png` exactly. Larger
review crops collectively cover the entire canvas.
'''
    (out / 'README.md').write_text(readme)
    sections = []
    for group in ('components', 'tiles'):
        cards = []
        for entry in entries:
            if not entry['file'].startswith(group + '/'):
                continue
            w, h = entry['size']
            detail = f'{w} × {h} px'
            if 'screen_box' in entry:
                detail += ' · screen box ' + str(entry['screen_box'])
            if 'regions' in entry:
                detail += ' · ' + ', '.join(entry['regions'])
            if entry.get('derive'):
                detail += ' · mirrored from ' + entry['derive']['source']
            if 'placements' in entry:
                detail += ' · ' + str(sum(p.get('count', 1) for p in entry['placements'])) + ' placements'
            cards.append(f'<article><h3>{html.escape(entry["title"])}</h3>'
                         f'<p>{html.escape(detail)}</p><a href="{entry["file"]}">'
                         f'<img src="{entry["file"]}" width="{w}" height="{h}" '
                         f'style="--w:{w};--h:{h}" alt="{html.escape(entry["title"])}"></a>'
                         f'<p><a href="{entry["file"]}">{entry["file"].split("/")[-1]}</a></p></article>')
        sections.append(f'<section id="{group}"><h2>{group.title()} ({counts[group]})</h2>'
                        f'<div class="gallery">{"".join(cards)}</div></section>')
    (out / 'index.html').write_text('''<!doctype html><html lang="en"><meta charset="utf-8">
<meta name="viewport" content="width=device-width, initial-scale=1">
<title>Art Deco element review</title><style>
:root{--zoom:2;color-scheme:dark}body{font:16px system-ui;margin:24px;background:#202020;color:#eee}
a{color:#f5cf78}nav{position:sticky;top:0;background:#202020;padding:12px 0;z-index:1}
button{margin:0 5px;padding:5px 12px}button[aria-pressed=true]{outline:2px solid #f5cf78}
.gallery{display:flex;flex-wrap:wrap;gap:16px;align-items:flex-start}
article{border:1px solid #666;padding:12px;max-width:calc(100vw - 76px);overflow:auto}
h3{margin:0}p{font-size:13px}article img{image-rendering:pixelated;
width:calc(var(--w)*var(--zoom)*1px);height:calc(var(--h)*var(--zoom)*1px)}
</style><h1>Art Deco elements</h1>
<p>Native-size indexed Agon PNGs. Open a linked file in GIMP to edit it.
Display zoom does not alter the files. <a href="README.md">Editing notes</a> ·
<a href="reference.png">Full composition</a> · <a href="static-reference.png">Static art</a></p>
<nav><a href="#components">Complete pieces</a> · <a href="#tiles">Reusable tiles</a> · Zoom:
<button data-zoom="1" aria-pressed="false">1×</button>
<button data-zoom="2" aria-pressed="true">2×</button>
<button data-zoom="4" aria-pressed="false">4×</button>
<button data-zoom="8" aria-pressed="false">8×</button></nav>
''' + '\n'.join(sections) + '''<script>
document.querySelectorAll('[data-zoom]').forEach(button=>button.addEventListener('click',()=>{
document.documentElement.style.setProperty('--zoom',button.dataset.zoom);
document.querySelectorAll('[data-zoom]').forEach(b=>b.setAttribute('aria-pressed',b===button));
}));</script></html>\n''')
    print(json.dumps({'output': str(out), **report}, indent=2))


if __name__ == '__main__':
    main()

# Basic Art Deco authoring

`source.png` and `source.svg` are unchanged copies of the full-color draft
accepted for testing on 2026-09-10 (SKIN-013, commit d470d32). The 512×384 PNG
is indexed to Agon's palette. The matching editable SVG retains the traced
shapes. These inputs and the selected font all live under `src`.

`build.py` clears baked sample information, chooses fixed live-field locations,
derives opaque state widgets and deduplicates exact 32×32 decorative tiles.
It uses the existing Tkinter editor's font reader and the canonical agon-utils
image conversion, AGNB writer, manifest validator and independent parser.
There is no image generation, dithering, resampling or custom font converter.

From the project root, using the local environment with Pillow and the
canonical editable agon-utils installation:

```bash
.venv/bin/python src/skins/artdeco/build.py
```

The authoring tools are read from the sibling `agon-utils` checkout. Their
hashes are recorded in `generated/build.json`. Normal assembly uses the
checked-in outputs and has no sibling-repository dependency.

Generated outputs are `skins/artdeco/`, `src/ui/artdeco/`, this directory's
`generated/` previews/build metadata, and `tests/fixtures/artdeco/`. Regeneration
overwrites those derived files. Keep manual source edits separately. For an
isolated repeat build, pass `--output-root /tmp/artdeco-repeat`; all input
assets still come from this checkout. Do not edit the accepted source files
in place; the builder verifies the PNG's accepted hash.

The background reconstructs exactly from 142 distinct tiles placed in 192
positions. Twenty-one state images bring the container to 163 records and
183,710 pixel bytes (191,580 bytes with AGNB overhead), plus 5,120 font bytes.
The first 128 records use printed bitmap characters in context 2; the remaining
decorative tiles use direct plots. Context 1 selects Lat7 Terminus 6×12 for the ten playlist rows (58 cells,
six-pixel advance) and Neutrino 5×8 for the remaining fields. Static drawing commands occupy 1,541 bytes. Live packets
remain at most 96 bytes; selecting a row still redraws just two rows.
These figures describe asset/command bytes, not a measured VDP memory limit.

The generated [preview](generated/preview.png) uses illustrative player values.
[build.json](generated/build.json) records exact field rectangles, asset IDs,
placements, source hashes and checks. The independent target comparison uses
6,975 pixels, including native glyph strokes/spacing and both normal/selected
rows, against the paused state of the shared functional suite. Elapsed/progress
positions are excluded from that fixed comparison because host timing varies;
the functional suite separately exercises clock, pause, seek and EOF behavior.

Information placement is provisional. The Author delegated placement and
requested a working skin before further visual feedback. Control legends are
omitted. A small F1 hint with a stylized modal help panel is recorded as a
future possibility, not displayed or implemented here.

# Basic Art Deco authoring

`source.png` is the accepted second-mask Art Deco application composite, with
colors sampled from the smooth concept art. It preserves the preceding toolbar
and repairs the baked selection arrow's border; sprite 0 supplies the moving
pointer. `source.svg` retains the 564 traced source shapes before those raster
compositing edits. Both use the Agon palette at 512×384 without dithering.
The source art, application composite and provenance are retained in
`candidates/smooth-color-02/`. This hardware-tested checkpoint remains an
incomplete skin: color choices and decorative refinement are still provisional.

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

The default playlist font is `concept-02`. To rebuild the first contender for
comparison, pass `--playlist-font concept-01`; both source sets remain under
`src/fonts`. Use a separate `--output-root` to keep the current package intact.
The selected font is recorded in `generated/build.json` and in the package's
`skin.cfg`. Concept 02's saved 6×12 PNG supplies the visible pixels; its loose
metrics font is generated with the existing editor's monochrome writer using
the PNG's normalized bitmap metadata. Source crop/scale settings are not
applied again.

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
183,710 pixel bytes (191,580 bytes with AGNB overhead). A separate font AGNB
adds 190 exact 6×12 glyph images, 13,680 pixel bytes and 22,824 bytes including
AGNB overhead. Loose monochrome fonts total 5,120 bytes.
The first 128 records use printed bitmap characters in context 2; the remaining
decorative tiles use direct plots. Context 1 selects Neutrino 5×8 for small
fields. Contexts 3/4 map ASCII 32–126 to normal/selected Art Deco bitmaps while
the loose Art Deco font supplies 6×12 metrics. The glyph inputs are the accepted
PNGs in `src/fonts/art-deco-concept-02/color-01`; their hashes, positions and
colors are checked without resampling. Other input bytes display as `?`.
Ten playlist rows retain 58 cells and six-pixel advance. Static drawing commands
occupy 1,541 bytes. Each row packet is still 94 bytes; a highlight move redraws
two rows for 188 bytes. All live packets remain at most 96 bytes.
These figures describe asset/command bytes, not a measured VDP memory limit.

The generated [preview](generated/preview.png) uses illustrative player values.
[build.json](generated/build.json) records exact field rectangles, asset IDs,
placements, source hashes and checks. The independent target comparison uses
6,975 pixels, including native glyph strokes/spacing and both normal/selected
rows, against the paused state of the shared functional suite. A separate
startup probe prints all 95 characters consecutively in both font contexts
and checks 7,110 pixels for Concept 02, including every shade in each glyph and
cell corners (7,136 for Concept 01).
It proves the antialiased colors, character mappings and six-pixel advance;
the later widget comparison also checks small-text/art context isolation.
Elapsed/progress
positions are excluded from that fixed comparison because host timing varies;
the functional suite separately exercises clock, pause, seek and EOF behavior.

Information placement is provisional. The Author delegated placement and
requested a working skin before further visual feedback. Control legends are
omitted. A small F1 hint with a stylized modal help panel is recorded as a
future possibility, not displayed or implemented here.

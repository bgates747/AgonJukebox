# Basic Art Deco authoring

`source.png` is the accepted second-mask Art Deco application composite, with
colors sampled from the smooth concept art. It preserves the preceding toolbar
and repairs the baked selection arrow's border; sprite 0 supplies the moving
pointer. `source.svg` retains the 564 traced source shapes before those raster
compositing edits. Both use the Agon palette at 512×384 without dithering.
The source art, application composite and provenance are retained in
`candidates/smooth-color-02/`. This hardware-tested checkpoint remains an
incomplete skin: color choices and decorative refinement are still provisional.

`skin.json` now describes the prepared artwork, fonts and live widget layout.
`build.py` is a thin entry point into the shared compiler documented in
[skin authoring](../../../docs/skin-authoring.md). The compiler validates and
packs the prepared inputs without rescaling or reapplying extraction recipes.
`prepared/provenance.json` records their lossless recovery from accepted output.

```sh
.venv/bin/python src/skins/artdeco/build.py
```

Use `--output-root /tmp/artdeco-repeat` for isolated output. The former
`--playlist-font` switch is replaced by explicit prepared-font inputs in the
skin definition; both historical font source sets are preserved. The build no
longer depends on the font editor's host API.

The accepted runtime output is unchanged: 162 graphics records, 189,604 AGNB
bytes, 190 playlist glyph records and 5,120 loose font bytes. Ten 58-cell rows
use 94-byte packets. Buffer ownership, context separation and cleanup retain
the accepted behavior. `generated/build.json` is the current resource inventory.

The generated [preview](generated/preview.png) uses illustrative player values.
[build.json](generated/build.json) records exact field rectangles, asset IDs,
placements, source hashes and checks. The independent target comparison uses
6,975 pixels, including native glyph strokes/spacing and both normal/selected
rows, against the paused state of the shared functional suite. A separate
startup probe prints all 95 characters consecutively in both font contexts
and checks 7,124 pixels for Concept 02, including every shade in each glyph and
cell corners.
It proves the antialiased colors, character mappings and six-pixel advance;
the later widget comparison also checks small-text/art context isolation.
Elapsed/progress
positions are excluded from that fixed comparison because host timing varies;
the functional suite separately exercises clock, pause, seek and EOF behavior.

Information placement is provisional. The Author delegated placement and
requested a working skin before further visual feedback. Control legends are
omitted. A small F1 hint with a stylized modal help panel is recorded as a
future possibility, not displayed or implemented here.

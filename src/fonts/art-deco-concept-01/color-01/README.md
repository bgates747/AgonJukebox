# Art Deco 6×12 color variants

The Author's [source PNG](../ArtDeco_Concept_6x12.png) and accompanying XML are
preserved unchanged. It is a 96×192 sheet of 16×16 cells, each 6×12, with all
94 visible printable ASCII characters in their correct slots. Its four gray
levels are 0, 85, 170 and 255; 1,768 pixels carry intermediate coverage.

## Review files

1. [Normal rows](ArtDeco_Concept_6x12-normal.png): cream #FFFFAA on black #000000.
2. [Selected row](ArtDeco_Concept_6x12-selected.png): black #000000 on gold #FFAA55.
3. [4× comparison](comparison-4x.png): normal on the left, selected on the right;
   printable ASCII followed by short text samples. Enlargement uses nearest
   neighbor. [Native comparison](comparison-native.png) retains actual pixels.

The two full font sheets have normalized `.png.xml` metadata beside them,
pointing to their finished PNGs with 6×12 cells and zero offsets/scaling.
The comparison images are review aids, not import sheets.

The supplied source XML contains both the high-resolution editing recipe and
a separate normalized bitmap section. The recoloring command uses the finished
PNG directly, so the original offsets and scaling are not applied a second
time. This preserves the Author's final letter positions and proportions.

## Reproduce

From the project root, choose a new output directory:

```bash
.venv/bin/python -B src/fonts/recolor_font.py \
  src/fonts/art-deco-concept-01/ArtDeco_Concept_6x12.png \
  --output /tmp/artdeco-font-colors
```

See [the script documentation](../../../../docs/font-coloring.md) for other
foreground/background pairs. The command reproduces the two sheets, sidecars
and colors.json; the comparison images and validation.json are review evidence.

## Validation

[colors.json](colors.json) records exact coverage-to-color mappings and hashes.
[validation.json](validation.json) records checks against the real source.
Each variant uses four exact Agon64 colors and opaque backgrounds. Every one
of its 18,432 pixels matches the expected mapping of its source gray value.
There is no dithering, resizing, thresholding or position change.

PNG and report bytes match a separate repeat build. XML is identical after
normalizing only its output path. Both supplied source files retain their
hashes. The PNG SHA-256 is
`9f80c750a70b7aa814d6e586eaf8607efbe2268ab7c575d0b5a03289bd568921`;
its XML SHA-256 is
`dc6ec75fbe79ab2dfb1243cbea389b13e655c4eb03f8256630d87600b00ac76c`.

These are source assets for review. Multi-color runtime font creation and
packaging remain subsequent work; the application still uses its current fonts.

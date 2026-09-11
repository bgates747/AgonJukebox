# Coloring antialiased font sheets

[recolor_font.py](../src/fonts/recolor_font.py) turns a grayscale PNG font sheet
into separate foreground/background color variants. It keeps cell placement
and antialiasing levels until the final Agon palette conversion. It does not
resize or threshold the source. Output is opaque, with each background baked
into its corresponding variant.

From the project root, using the Author's supplied 6×12 PNG:

```bash
.venv/bin/python -B src/fonts/recolor_font.py \
  src/fonts/art-deco-concept-01/ArtDeco_Concept_6x12.png \
  --output /tmp/artdeco-font-colors
```

The default input is a 96×192 sheet: 16×16 cells of 6×12, covering character
slots 0–255. It produces normal and selected PNGs, a `.png.xml` sidecar for
each, and `colors.json` containing source/output hashes, geometry, parameters
and the exact coverage-to-color mapping. The output directory must be new;
the script refuses to overwrite prior results or hand edits.

The prepared [Art Deco color-01 review](../src/fonts/art-deco-concept-01/color-01/README.md)
contains both variants and a nearest-neighbor comparison preview. Its supplied
source has all four expected gray levels and 94 visible printable ASCII glyphs.

## Default colors

| Variant | Foreground | Background |
| --- | --- | --- |
| Normal playlist row | `#FFFFAA` | `#000000` |
| Selected playlist row | `#000000` | `#FFAA55` |

These match the Art Deco builder's current playlist colors. To choose different
colors, supply one or more `--variant` arguments, replacing the defaults:

```bash
.venv/bin/python -B src/fonts/recolor_font.py source.png --output color-test \
  --variant 'normal=FFFFAA,000000' \
  --variant 'selected=000000,FFAA55'
```

Foreground and background must be exact Agon64 colors: each RGB channel is
0, 85, 170 or 255. Names use lowercase letters, digits and hyphens. A leading
`#` on colors is optional. Other supported options are `--cell WIDTH HEIGHT`,
`--columns`, `--rows`, `--first-char`, `--invert` and `--mask-channel alpha`.
Run `--help` for defaults. Grid dimensions must match the PNG exactly.

## How coverage becomes color

In the default gray-mask mode, white means full foreground and black means
background. Intermediate grays represent intermediate coverage. For an opaque
pixel with gray value `g`, the blend is:

```text
color = foreground × (g / 255) + background × (1 − g / 255)
```

PNG alpha, if present, multiplies that coverage. Gray and alpha are kept as an
integer product with denominator 65,025, avoiding early 8-bit rounding. RGB is
rounded once after blending. No automatic normalization or gamma adjustment is
applied to the mask levels. `--invert` reverses gray before applying alpha.

Gray mode rejects colored visible pixels instead of guessing their coverage.
Use `--mask-channel alpha` for an alpha-only mask; that mode ignores RGB and
uses opacity as coverage. Its `--invert` option reverses the alpha mask.

The existing agon-utils converter selects the nearest Agon64 RGB color with
its nondithered `RGB` method. Its RGBA2222 encoder and decoder produce the final
opaque PNG. A temporary row-major atlas is used for that conversion; it is not
a glyph-major font payload. All temporary files belong to this script's own
temporary directory.

For a four-level opaque mask, the defaults produce:

| Mask gray | Normal RGB | Selected RGB |
| --- | --- | --- |
| 0 | `#000000` | `#FFAA55` |
| 85 | `#555555` | `#AA5555` |
| 170 | `#AAAA55` | `#555500` |
| 255 | `#FFFFAA` | `#000000` |

Nearby coverage levels can merge at the final 64-color palette limit. The report
shows every input level and its resulting color; no levels are discarded by a
monochrome export first. A binary source remains binary and is reported as such.

## Metadata and dependencies

Sidecars use the font maker's existing schema, with actual cell dimensions,
zero offsets/scaling, matching foreground/background colors and `raster_type`
set to `palette`. They reference their output PNG using the editor's current
absolute-path convention; update that path if the directory moves. PNG import
support belongs to the editor; saving through a monochrome `.font` path cannot
retain these colors.

This optional authoring tool uses Pillow, NumPy and the canonical agon-utils
extension in the project `.venv`. The default palette is the shared
`agon-utils/examples/palettes/Agon64.gpl`, beside this checkout; `--palette` can
point to another copy containing all 64 colors. The font editor's Python code,
preferences and shared temporary files are not used.

Focused verification:

```bash
.venv/bin/python -B -m unittest discover -s tests -p test_font_recolor.py -v
```

The tests cover known antialiasing levels and both color pairs, glyph placement,
alpha/inversion, palette/opacity, metadata, source and output protection, and
repeatability. Runtime multi-color font creation and asset packaging are separate
from this source-image preparation tool.

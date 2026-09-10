# SKIN-012 host proof and review

Status: Author reviewed v6 and requested further refinement of remaining dirt
and ragged quantized edges. Isolated elements are prepared for individual review
and optional hand editing; the appearance is not yet accepted.
Started: 2026-09-09 14:13 EDT. Specification/source freeze: `f2f252d` on `skins`.
The approved requirements are [SKIN-012](../SKIN-012.md). This proof has not been
installed in the application or run on the VDP.

The [2026-09-10 checkpoint notes](checkpoint-2026-09-10.md) record the current
results and limitations before planning an alternative vector workflow.

## Review files

Start with the new [element review folder](element-review/README.md) and its
[zoomable gallery](element-review/index.html): 30 named complete pieces and
individual controls, plus all 96 reusable tiles. These are native-size indexed
Agon PNGs, with their coordinates, shared placements and initial hashes saved
for later reassembly. They preserve v6 pixels exactly; no additional cleanup
has been applied. `export_elements.py` reproduces the packet into a new folder
and refuses to overwrite existing review files or hand edits.

1. [Preferred native preview](review-v6/preview.png): 512x384, 27 Agon colors.
2. [Original / reconstruction / changed pixels](review-v6/comparison.png):
   three native-size panels; magenta marks intentional differences.
3. [Column comparison at 3x](review-v6/column-comparison.png) and
   [named reusable components](components-v6.png).
4. [All extracted assets](review-v6/asset-sheet.png),
   [static skin without demonstration content](review-v6/static.png),
   [placement/derivation manifest](review-v6/manifest.json), and
   [canonical AGNB container](review-v6/graphics.agnb).
5. [Resolved geometry and parameters](review-v6/resolved-parameters.json),
   [detailed report](review-v6/report.json),
   [reproduction result](reproducibility-v6.json), and
   [strip-size tradeoffs](strip-tradeoffs-v6.json).

The review image is reconstructed from the actual AGNB pixel records plus
explicit mirrored-buffer recipes and a host-only demonstration overlay. The
overlay supplies sample filenames, time, selection, progress, volume levels,
path and file count. It is deliberately excluded from the runtime artwork
container; application fonts and changing-widget behavior remain integration
work. The screenshot's exact layout is not a newly frozen product contract.

## What changed

1. Each long column shaft uses three fitted bands. Within a band, a categorical
   cross-section is represented by piecewise-linear RGB ramps whose quantized
   samples exactly reproduce that profile. The left middle/lower bands coalesce
   where identical. Turquoise inserts, curved end transitions, and multiple
   cream/white highlight bands are preserved. The left 56x101 shaft section
   needs 1,176 unique pixel bytes instead of 5,656; the corresponding right
   section needs 1,595. Shorter tail strips are included in those counts.
2. The two lower column plaques and gold transport surrounds use geometric
   contour distance plus orientation-dependent shading. Discrete depth bands
   are learned from the source, including distinct lit and shaded faces.
   The common gold button model is fitted once and reused. The previous,
   pause, next and shuffle buttons now share exactly one 41x28 surround;
   repeat retains its different width. Symbols are separate assets.
3. The paired top fans use one canonical ornament and a horizontal reflection.
   Radial highlights mirror with the fan, while the two shaft profiles and
   lower plaques retain independently fitted shading. The mirrored fan would
   be copied/reversed on the VDP at loading: it saves 4,224 uploaded pixel
   bytes but still needs 4,224 resident bytes for its second orientation.
4. The crown/title is retained as one larger ornament. Long repeats, uniform
   fills, tight background trimming, and exact deduplication handle the rest.
   Irregular artwork has bounded patch fallbacks; this is not a forced
   whole-screen 8x8 tile map or a fully generalized skin authoring system.

There are 2,756 changed screen pixels (1.402%). Every change is inside a declared
refinement or reflection region. All original light-colored transport symbol
pixels in the protected face regions are verified unchanged. The source PNG's
SHA256 still equals the frozen specification. No image generation or dithering
was used.

## Iteration decisions

1. `v1` established the column profiles with 406 changed pixels and retained
   their dimensional shading.
2. `v2` added plaque bevels, the mirrored fans, and separate symbols. `v3`
   improved exact background trimming and refined the fan's horizontal rail.
3. `v4` tried explicit nine-slice button frames: 155 uploaded records and a
   modeled 3,573-byte static drawing sequence. Its modest pixel saving did not
   justify the fragmentation for these small buttons.
4. `v5` retained shared whole surrounds: 95 uploaded records and a 2,063-byte
   modeled sequence. These are more practical at the current dimensions.
5. Asset-sheet inspection caught antialiased icon fringes outside initial
   bounds. `review-v6` detects complete light-pixel bounds within protected face
   regions, pads them, and verifies the full source foreground independently.
   This fixes residual glyph pixels in surrounds and restores 99 source pixels
   relative to v5. It is the selected result; earlier directories are evidence.

Historical iteration outputs and their script hashes are retained. The selected
`review-v6/scripts/` directory additionally freezes the exact reproducible code
and dependency lock. `control-v6` runs the same final detector, region split,
and extractor with all intentional art changes disabled, yielding the original
image exactly. It is the fair comparison for refinement-specific savings.

## Cost evidence

| Quantity | Unrefined extraction control | Preferred proof |
| --- | ---: | ---: |
| Unique uploaded RGBA2222 pixel bytes | 136,481 | 120,373 |
| AGNB image records uploaded | 94 | 95 |
| Modeled asset setup/upload TX bytes | 139,599 | 123,556 |
| Modeled static drawing sequence bytes | 1,909 | 2,063 |

Refinement saves 11.80% of pixel data against the same unrefined extraction.
The full static raster baseline is 196,608 bytes; the selected dictionary saves
38.78% against that baseline. The AGNB file is 125,024 bytes, including 4,651
container overhead bytes. Container headers stay on the MOS/file side; they
are not counted as VDP pixel traffic.

The candidate needs 96 resident bitmap buffers, including the mirrored fan,
and 124,597 bytes of pixel storage. A stored static command sequence adds one
buffer and 2,063 bytes, for 126,660 bytes before VDP allocation/object metadata,
font/context storage, and common setup. Loading that sequence is modeled as
2,077 further TX bytes; calling it for a static redraw is six TX bytes. None
of these are measured VDP timing or audio-performance results.

The 8-pixel repeat dimension uses 148 bitmap placements. One-pixel repeats
would reduce pixel payload to 116,893 bytes but need 628 placements; 16-pixel
repeats use 123,797 bytes and 106 placements. Eight is the current compromise.
No character codes are assigned by this study: three horizontal strip assets
are identified as potential printed-character candidates. Existing live text
and widget rendering is not replaced by this static-art proof.

## Reproduction and checks

From the project root, choose a new output directory; builds refuse overwrite:

```bash
.venv/bin/python docs/tasks/SKIN-012/review-v6/scripts/build.py \
  --params docs/tasks/SKIN-012/parameters-v6.json \
  --out docs/tasks/SKIN-012/rebuild-review
.venv/bin/python docs/tasks/SKIN-012/review-v6/scripts/verify.py \
  docs/tasks/SKIN-012/rebuild-review \
  --source docs/tasks/SKIN-006/art-deco-2026-09-09/art-deco-scaled-palettized.png
```

The defaults use the existing canonical agon-utils checkout. `--utils PATH`
can locate that dependency elsewhere. Exact converter/writer/parser/palette
hashes and Python dependency versions are checked against `toolchain.json`.
The Agon tools are unchanged at commit
`434bf734a9f5a4cf84b4428f6a6be24d2bfc7b33`; no matching gradient/bevel extractor
was present in the inspected image API. Existing RGB conversion, RGBA2222
encoding, AGNB writing and AGNB parsing are reused. The sample preparation
script's Floyd dithering/default resizing path is intentionally not invoked.

Independent reconstruction reads canonical AGNB records, decodes packed pixels,
applies explicit mirror recipes, fills and placements, then compares the result
with the review PNG. Checks cover bounds, complete coverage, saved palette,
binary alpha, preserved source symbols, idempotent refinement, and unchanged
source hashes. Deliberately corrupted AGNB pixels and out-of-bounds placements
are rejected. A separate build from the frozen script snapshot reproduced all
206 generated PNG/RGBA2222/AGNB/JSON artifacts byte for byte.

The protocol model uses the pinned public AGNB API's 8,192-byte stream buffer
and the stock VDP copy/reverse implementation inspected locally. It excludes
common graphics state/context setup and VDP metadata. Mirrored recipes and the
study manifest are not yet supported by the application's current skin loader;
integration and target qualification belong to SKIN-004/006/007 after visual
review. The next decision is whether to accept or refine this reconstructed
appearance, especially the symmetric fans and uniform button bevels.

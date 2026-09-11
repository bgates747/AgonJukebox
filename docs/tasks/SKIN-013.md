# SKIN-013 — Explore vector tracing before downscaling Art Deco artwork

## State

- Status: Smooth-reference recoloring ready for review; geometry preserved
- Started: 2026-09-10 14:49 EDT
- Finished: --
- Registered: 2026-09-10, at the Author's request after discussing edge/noise
  detection, flat cel shading, stronger outlines and vectorization before
  downscaling.
- Authorization: The Author accepted the regenerated source as a better starting
  point and requested vector extraction next. Subsequent steering selected the
  supplied thresholded image and white filled regions, with headless Inkscape
  smoothing. This bounded four-element pilot stops before shading or extension
  to the full composition.
- Current instruction: The Author accepted full-color candidate 02 as a
  "good-enough draft to test with" and requested committing it. Freeze the
  scripts, parameters, draft image, editable vectors and supporting evidence.
  This acceptance does not select further processing or deployment.
- Baseline checkpoint: `439a75b` on `skins`, following the source/specification
  freeze `f2f252d`.

## Purpose

Explore an alternative authoring workflow that derives clean vector shapes
from the larger artwork before rasterizing at 512x384. Use flat color regions,
discrete highlight/shadow bands and explicit outline widths to reduce the
ragged boundaries and small quantization artifacts remaining in SKIN-012.

Retain the current raster workflow as a comparison and fallback. This study
must establish whether cleaner geometry can preserve the Art Deco design's
depth and ornament, and whether the resulting pieces remain practical to
reuse on the Agon. A successful trace is not automatically a better picture.

## Inputs and baseline

1. Composition reference and fallback tracing input: the existing [smooth master](SKIN-006/art-deco-2026-09-09/art-deco-smooth-master.png),
   at its original 1448x1086 resolution. Work from this larger image; enlarging
   the quantized 512x384 image cannot recover the original shape boundaries.
   Preserve its SHA256 `c97f6ee2d6322de2c0b26f5573656e21e2b85880aa8f5044a2768822a0aa93b8`.
2. Author-selected native reference: [undithered palettized image](SKIN-006/art-deco-2026-09-09/art-deco-scaled-palettized.png).
   Its SHA256 is `178e443dfcc3a47a4ebfbf3df6385a57b75b8c54533d9595d96101756197ef55`.
   It remains the reference for composition, palette and desired shading.
3. Existing method: [SKIN-012 checkpoint notes](SKIN-012/checkpoint-2026-09-10.md),
   [v6 preview](SKIN-012/review-v6/preview.png), [static art](SKIN-012/review-v6/static.png),
   and [editable element packet](SKIN-012/element-review/README.md).
   Preserve these files and any subsequent hand edits. Reuse their semantic
   names and placements when appropriate without assuming their raster edges
   are the correct geometry to trace.
4. First source test: [flat-outline master](SKIN-013/source-test-01/flat-outline-master.png),
   regenerated with the built-in imagegen tool at the Author's explicit request.
   Its [prompt](SKIN-013/source-test-01/prompt.md),
   [provenance](SKIN-013/source-test-01/generation.json) and
   [review notes](SKIN-013/source-test-01/README.md) are retained separately.
   The prompt requests solid base fills and bold continuous outlines, leaving
   gradients and bevel shading to later programs. This is an unprocessed
   1448x1086 RGB candidate, not an exact-palette or vector deliverable.
   Deterministic processing still owns final geometry, dimensions and palette.
5. Author-supplied source variants: [six-color Agon image](SKIN-013/source-test-01/flat-outline-master_agon64.png)
   (SHA256 `e26f95ddfed55de1fa59a779c26421f7c64db7b9c25d0c63854ebfe70b90933f`)
   and the currently selected [black/white threshold image](SKIN-013/source-test-01/flat-outline-master_bw_threshold.png)
   (SHA256 `524125a99a8a9cf9033b9dd79303e090db317d18ad30e61bf8d991d1fdddec6b`).
   Both retain the 1448x1086 source dimensions. Select exact white pixels from
   the binary image without additional thresholding or cleanup. Preserve the
   color sources for later material assignment; the binary mask loses some
   original color distinctions.

## Incremental review sequence

1. **Source concept:** generated and accepted as a better starting point.
   The actual PNG, prompt and subsequent Author-supplied variants are retained.
2. **Region/noise pilot:** on the selected source, examine a small group of
   representative elements and display proposed boundaries and noise changes.
   Review the diagnosis before investing in vector reconstruction.
3. **Vector pilot:** trace and simplify those elements, preserving important
   holes, corners and highlights; review isolated editable vectors and their
   native-scale outline variants before extending the method.
4. **Shading pilot:** add column gradients and directional bevels
   programmatically, constrain output to the Agon palette, and compare at
   native resolution. Review whether depth and edge quality both improve.
5. **Full alternative:** after the pilots pass visual review, extend to the
   complete composition, reusable asset extraction and AGNB cost/reconstruction
   checks. Each stage has a review stop; a poor result triggers a bounded
   revision instead of an automatic run through the remaining stages.

The Author's request to try vector extraction, followed by white-region and
Inkscape steering, combined the initial region and vector investigation into
the bounded pilot below. Native-scale width/gap normalization remains open;
the current comparison is at source resolution.

## Current pilot — 2026-09-10

Review [white-shape-pilot-02/index.html](SKIN-013/white-shape-pilot-02/index.html),
the [comparison sheet](SKIN-013/white-shape-pilot-02/comparison.png), and
[methods, reproduction and limits](SKIN-013/white-shape-pilot-02/README.md).
The left fan, left column, previous button and footer jewel provide 79 separate
white filled SVG objects with two enclosed holes. Individual initial and
simplified shapes are saved in each element folder. Diagnostic colors identify
objects without proposing final material colors.

The installed Potrace 1.16 library traced the masks with speck suppression
disabled. One headless Inkscape 1.2.2 simplification pass at threshold 0.0003
reduced SVG segments from 835 to 598 (28.4%). Object and subpath counts stayed
unchanged; independently rendered component/hole counts match the source for
both vector versions. Source artwork and user Inkscape preferences remain
unchanged. These checks establish structural preservation at source resolution,
not visual acceptance or final-screen legibility.

All earlier black-region candidates and white pilot 01 remain as evidence.
Pilot 02 corrects a column crop that included two truncated, one-pixel-high
fragments of the neighboring fan rail. It performs no source cleanup or noise
deletion. The source-coordinate SVGs retain explicit crop bounds and the common
64/181 target transform; final-pixel geometry treatment is deferred.

No new dependency was installed. No shading, full-image tracing, AGNB packaging,
application change or deployment was performed. The Author responded positively
and requested a progress commit. See the [checkpoint index](SKIN-013/README.md).

## Shading possibilities — recorded, not selected

The [shading and lighting note](SKIN-013/shading-possibilities.md) records linear,
radial and mesh gradients, contour-following bevels/inset bands, drop and inner
shadows, and diffuse/specular directional lighting. It distinguishes available
Inkscape mechanisms from proposed scripting and Agon palette treatments.

Possible comparison: one column and one button with a common light direction,
using smooth shading followed by controlled palette mapping versus explicit
Agon-colored bands. Native-scale flat controls would reveal geometry and gap
issues before attributing them to shading. These are discussion options;
material colors, geometry adjustments and lighting treatment remain undecided.

## Full-image flat-color experiment — 2026-09-10

The Author requested a more ambitious scripted pass: sample predominant colors
per shape from the original artwork, quantize to Agon64 and produce 512x384
without antialiasing. They confirmed the matching unquantized flat-outline
master as the color reference. This authorization extends tracing to the full
image while keeping fills flat; gradient/lighting options remain unselected.

Current result: [flat-color-full-02/preview.png](SKIN-013/flat-color-full-02/preview.png),
[gallery](SKIN-013/flat-color-full-02/index.html),
[reproduction and limits](SKIN-013/flat-color-full-02/README.md), and
[script](SKIN-013/colorize_shapes.py). All 554 white components were traced,
including 111 enclosed holes. Sample each component's interior, choose its
most populated coarse RGB histogram bin, take the original-color median within
that bin and select the nearest Agon color. Areas, samples and chosen colors
are recorded by stable shape ID. The final indexed PNG uses 14 visible colors.

Inkscape 1.2.2's tested command-line exports retain antialiasing despite
crispEdges, extension preferences and the document flag. Keep those probe
results. The final script uses Inkscape for path simplification and the installed
libcairo for direct 512x384 rasterization with CAIRO_ANTIALIAS_NONE; exact indexed
conversion rejects off-palette colors instead of repairing them afterward.

Candidate 01 is retained as a failed simplification experiment: rapidly
repeated Simplify commands activate Inkscape's time-based strength increase.
Candidate 02 uses one invocation for all selected paths, with the verified
simplifyindividualpaths preference so tolerance uses each path's own bounds.
Its maximum bounding-edge movement is 0.203 target pixels. Independent renderer
checks agree on 78,782 uniform interior pixels; relative curve/transform/hole
fixtures, source hashes, palette/alpha/dimensions, output overwrite rejection
and byte-identical PNG reproduction all pass. See
[verification](SKIN-013/flat-color-full-02/verification.json).

This is a flat-color concept preview, including traced sample text. White-region
tracing cannot recover dark decorations merged into black by thresholding;
those regions remain black. No runtime packaging or deployment was changed.
Author review: accepted on 2026-09-10 as a good-enough draft for testing, with
the scripts and evidence frozen in a progress commit. The broader authoring
exploration remains open; this is not final-art or runtime qualification.

## Proposed workflow

1. **Establish coordinates and a representative pilot.** Select one column
   shaft with its transition/cap, a beveled button surround, a curved fan and
   a small jewel or accent. These exercise straight edges, rounded shading,
   nested contours, thin details and symmetry. Record source/target bounds,
   source hashes and a common coordinate transform. Use a 512x384 vector
   coordinate system so widths and tolerances are expressed in final pixels.
   The existing master and first source candidate scale uniformly by 64/181;
   one target pixel spans 181/64 source pixels. Derive this transform from the
   selected input's actual dimensions. Keep the agent responsible for crop
   and mask creation.
2. **Find regions and boundaries at source resolution.** Compare color-region
   segmentation with segmentation constrained by strong image edges. An edge
   map is supporting evidence; derive closed, labeled regions with explicit
   adjacency and holes before tracing. Fit a small set of flat shades per
   material, initially comparing roughly two to four main shading bands where
   appropriate, while retaining gold, cream, cyan and ruby accents. Record
   preprocessing, thresholds and connectivity. Do not trace every source
   antialiasing color into a separate vector island.
3. **Identify likely noise before removing it.** Measure connected-region area,
   local thickness, extent, boundary protrusions and color/context agreement
   with neighbors. Express size thresholds in target pixels/pixel area, not
   arbitrary source-pixel counts. Show proposed merges/removals as overlays
   and a region table. Size is evidence rather than the sole deletion rule:
   protect thin continuous outlines, ordered shading bands, repeated accents,
   intentional holes and isolated jewel highlights. Prefer merging an artifact
   into an appropriate adjacent region over cutting a hole in the artwork.
4. **Trace and simplify geometry.** Convert retained regions to editable SVG
   paths with stable element IDs, fill roles and nesting. Fit straight or
   stepped Art Deco segments and restrained curves, with simplification error
   bounded in target-pixel units. Compare a small set of recorded tolerances
   rather than one aggressive global smoothing setting. Preserve corners,
   holes and region adjacency; identify shared boundaries so independently
   simplified neighbors cannot create cracks. Use symmetry only where it
   preserves intended shape and lighting. Avoid double outlines where two
   filled shapes share one boundary.
5. **Specify outlines and shading explicitly.** Give structural outlines at
   least a one-target-pixel vector width; compare 1, 1.5 and 2 pixels in the
   pilot to assess legibility and crowding. Specify joins, corners, caps and
   stroke placement. Thicker strokes must not consume content space or close
   intentional gaps. Represent rounded-column highlights and bevel depth as
   nested or adjacent flat shade shapes, with separate lit/shadow faces when
   needed. Decorative highlight fills are not all forced into thick outlines.
   Preserve the dimensional effect through discrete bands rather than copying
   every irregular color patch from the raster input.
6. **Rasterize under final-screen constraints.** Snap suitable horizontal and
   vertical edges to the pixel grid using an explicit stroke-center convention.
   Rasterize the vectors directly at target size with controlled, recorded
   fill/coverage rules. Begin with unblended flat fills and outlines. Map final
   colors to the Agon palette without dithering, fractional alpha or blended
   fringe colors. A nominal one-pixel SVG stroke does not guarantee a continuous
   raster border: inspect continuity, actual thickness, joins and diagonals in
   the saved native PNGs. Permit internal floating-point geometry; enforce the
   final pixel constraints after saving. Retain useful candidate variants.
7. **Compare the pilot and extend the useful method.** Produce native and
   integer-zoom comparisons of the Author's reference, v6 and vector candidates,
   together with changed-region overlays. Choose parameters based on visible
   edge quality, preserved depth and surviving detail. Extend the preferred
   treatment to the full composition if the pilot supports it. Any retained
   raster ornament or untouched area must be labeled as such in the manifest
   and review notes. If tracing damages the characteristic geometry or requires
   excessive exceptions, retain that evidence and propose a bounded hybrid
   result rather than claiming a successful full-vector reconstruction.
8. **Reuse pieces and package a comparable host proof.** Export named SVG
   components, indexed Agon PNGs, repeatable strips/tiles and placements into
   the new task directory. Deduplicate after rasterization, account for mirrored
   variants, and separate sample text/dynamic content from static artwork.
   Reuse the established canonical RGBA2222/AGNB conversion and validation
   tools. Reconstruct the full 512x384 review image from the emitted assets and
   placements so seams and missing regions remain visible. Compare costs and
   appearance with the preserved v6 workflow using equivalent static content.

## Constraints and tradeoffs

1. Keep all new processing and candidates in `docs/tasks/SKIN-013/`, with
   separate input references, scripts, parameters, diagnostics, SVGs and
   raster outputs. Use new iteration directories and protect edited files.
   Do not regenerate or overwrite SKIN-012 or the supplied source artwork.
2. This is a host authoring workflow. SVG is an editable intermediate; the
   application still loads raster bitmap assets through AGNB. Retain the
   printed-character UI decision and existing loose `.font` exception.
   No vector renderer, firmware extension, or runtime loader change is part
   of this task. Existing WAV-only behavior and the no-EQ decision stand.
3. Every complete preview is exactly 512x384. Component dimensions and
   placements are explicit integers. Every visible final pixel has RGB channels
   in `{0, 85, 170, 255}`; exported transparency, if needed, is binary. Indexed
   PNGs embed the Agon palette for later GIMP editing. SVGs should use explicit
   fills/strokes and avoid raster embeds or external fonts/assets in pieces
   presented as vectorized; retain text separately where appropriate.
4. A clean outline may require moving a boundary or enlarging a feature. Record
   those intentional changes. Preserve composition and useful depth rather than
   treating pixel equality to the noisy source as the aesthetic objective.
   Do not claim that thicker outlines or fewer regions are always preferable.
5. Use local deterministic tools through the project `.venv` where applicable.
   Inspect installed/canonical capabilities before choosing tracing and SVG
   rasterization tools; record selected versions and options. This plan does
   not require installing a new dependency or selecting a particular tracer
   before the first implementation investigation.

## Deliverables and evaluation

1. Reproducible commands and recorded parameters for segmentation, candidate
   noise classification, tracing, outline treatment, rasterization, extraction
   and AGNB reconstruction. Preserve source hashes and per-stage provenance.
2. A diagnostic packet showing source boundaries, labeled regions, candidate
   noise, retained/protected details, simplified contours and rasterized edges.
   Supply named editable elements in their own folder and a visual index.
3. Native 512x384 comparison images and integer magnifications. Show remaining
   raggedness, broken borders, lost holes, crowded details and tile seams, not
   only successful crops. Distinguish a pilot composite, hybrid and full traced
   result explicitly. Record why the preferred candidate was selected.
4. Checks for saved dimensions, palette/alpha, source immutability, repeatable
   output, exact reconstruction from emitted assets, and valid canonical AGNB.
   Check representative structural outline continuity/thickness and protected
   small features. Quantify tiny regions and contour complexity before/after,
   but do not use a single noise score as the acceptance criterion.
5. Compare unique RGBA2222 bytes, AGNB record/file overhead, resident bitmap
   memory, modeled upload traffic and repeated draw traffic against v6 and a
   full raster. SVG file size and compressed PNG size are not UART savings.
   Identify host measurements versus protocol estimates; avoid runtime timing
   claims without target testing in the appropriate task.
6. Present the preferred result and limitations for Author review. Acceptance
   means the Author considers this a useful alternative workflow, or accepts
   a documented negative/hybrid finding. Do not replace SKIN-012, declare the
   finished reference skin, or promote/deploy this experiment automatically.

## Relationship to other work

1. [SKIN-012](SKIN-012.md) remains the preserved raster-processing alternative.
   This task does not silently expand or rewrite its frozen specification.
2. [SKIN-005](SKIN-005.md) owns promotion of reusable authoring tools;
   [SKIN-006](SKIN-006.md) owns selection of the final reference artwork.
3. [SKIN-001](SKIN-001.md), [SKIN-004](SKIN-004.md) and [SKIN-007](SKIN-007.md)
   retain package/layout contracts, application integration and target resource/
   audio qualification. Existing contracts constrain eventual integration,
   while this host exploration can proceed without freezing a new layout.

The full-image flat-color draft is accepted for testing. Preserve this baseline
and await the next instruction before integration, gradients or refinement.

## Smooth-reference recoloring — 2026-09-10

The Author requested a rollback commit, then one predominant source-art color
per surviving shape. They explicitly selected the earlier smooth master when
asked which reference to use. Checkpoint fd3bb2c freezes the CRT-reviewed
Concept 02 application and prior assets. Preserve the existing simplified SVG
paths, IDs, transforms and black background. Reuse the established inset/mode
color sampler and Agon64 mapping against the smooth master's corresponding
source coordinates; both images are 1448×1086. Render 512×384 with the existing
Cairo antialias-free renderer. Keep the new SVG/PNG as a separate review
candidate. The Author will handle regions lost to thresholding later.

Review: `SKIN-013/smooth-color-01/README.md`, `preview.png` and `colored-shapes.svg`. 372 fills changed; 20 Agon colors. 27 paths sample to black because source details differ; all geometry remains editable. Palette, opacity, coverage, source hashes, non-fill SVG structure and byte-identical repeat checks pass. No runtime deployment.

## Second threshold-mask pass — 2026-09-10

The Author supplied source-test-01/flat-outline-master_bw_threshold_2.png and
authorized the exact tracing/simplification/sampling pipeline through smooth
master color assignment. The existing frozen scripts and parameters produced
smooth-color-02: 564 shapes, 117 holes, 24 visible Agon colors, 512×384 without
antialiasing or dithering. White source coverage grows 13.83%. Reproducibility,
palette/opacity, source immutability, bounds and independent-renderer checks
pass. Preview, editable SVG and previous-left/new-right comparison are in
SKIN-013/smooth-color-02; see its README and verification.json. Existing artwork,
application assets and the Author's in-progress Concept 02 font edits are
preserved. No production integration, deployment or commit. Await visual review.

## Smooth-color-02 live application review — 2026-09-10

The Author requested application integration while preserving previous art,
retaining controls/volume bar, moving the triangle with selection, and using
their updated Concept 02 font (old font derivatives may be replaced). Built an
isolated fd3bb2c-based candidate in .emulator/smooth-color-02-work; new artwork
and app composite/preview/provenance are vendored in
src/skins/artdeco/candidates/smooth-color-02. Canonical AGNB build retains all
21 existing control-state payloads exactly; the toolbar is preserved. The
baked marker is removed and a 10×12 AGNB bitmap on sprite 0 follows selection,
hides for empty listings, and is cleaned up on exit. Move packet is 17 bytes.
The Author's updated PNG/XML and regenerated normal/selected color-01 variants
are used; no rescaling of the finished sheet. Graphics: 162 records, 189,604 B.

26 scenarios, 6,975 widget pixels and 7,124 font pixels pass. One old fixed
frame-color expectation was updated from the generated new backdrop; existing
control expectations remain. Input/audio scheduling is unchanged; this does
not qualify or fix SKIN-017 hardware responsiveness. Binary 51,591 bytes, SHA256
6ccc3e884029b54266c37d0a9ef241b6250fa22ac6df2645d13caadff44fbcf0.

Previous deployment saved in .emulator/live-test/before-smooth-color-02; new
binary/package installed in that profile, retaining config/autoexec/music map.
Launched through ./fab-agon-emulator; SKIN_ASSETS_READY logged. Receipt/log/PID
use smooth-color-02 prefix. Await Author visual/moving-sprite review. Default
production assembly/artwork remain unchanged; do not rebuild/deploy them over
this candidate accidentally. No physical card, firmware, commit or push changes.
Details/scripts: docs/tasks/SKIN-013/app-smooth-color-02/README.md.

## Accepted Art Deco progress checkpoint — 2026-09-10

The Author confirms hardware responsiveness returned and explicitly authorizes
committing this successful but incomplete Art Deco advance, then stopping.
SKIN-017 is complete and removed from TODO. Promote the exact tested
.emulator/skin017-fix-work source/runtime assets into public application space;
preserve shared builder discovery of sibling agon-utils. Keep further skin
refinement open. Separate root that-70s-skin artwork is unrelated and untouched.
No push or further development is authorized.

# White shape tracing and headless Inkscape smoothing — review stop

The selected source is the Author's full-resolution thresholded image:
`../source-test-01/flat-outline-master_bw_threshold.png` (1448x1086, exact black
and white), SHA256 `524125a99a8a9cf9033b9dd79303e090db317d18ad30e61bf8d991d1fdddec6b`.
The source was read without filtering, resizing or further thresholding.

Start with the [zoomable gallery](index.html) or [comparison sheet](comparison.png).
The **shape-map** images use diagnostic colors to show independent filled
objects. Every element folder contains its original crop, initial and simplified
SVGs, rendered PNGs, difference/contour overlays, and individual SVG shapes.

## What was tested

1. Selected exact RGB(255,255,255), then traced each connected white region as
   a filled vector shape with any enclosed hole. The SVGs use white fills and
   transparent backgrounds, without outline strokes or embedded raster images.
   Separate object IDs make later fill/material assignment possible.
2. Used the installed Potrace 1.16 library for initial contours with corner
   threshold 0.55 and optimization tolerance 0.2 source pixels. Automatic
   speck suppression was disabled; no source components were deleted.
3. Ran one actual headless Inkscape 1.2.2 `path-simplify` pass on those SVGs,
   exporting to separate files. The selected threshold was 0.0003 in an
   isolated profile. Each component group has its own profile under `profiles/`;
   the user's Inkscape preferences were verified unchanged.
4. Saved individual paths under each element's `shapes/` and
   `simplified-shapes/` directories. These retain the element's coordinate
   system so they can be placed back exactly; they are not tightly recropped.
   The gallery's colored map shows the simplified shapes together.

## Results

| Element | Filled shapes | Initial segments | Simplified segments | Simplified/source overlap (IoU) |
| --- | ---: | ---: | ---: | ---: |
| left-fan | 24 | 260 | 207 | 98.68% |
| left-column | 39 | 408 | 256 | 99.68% |
| previous-button | 3 | 47 | 32 | 98.97% |
| footer-jewel | 13 | 120 | 103 | 99.06% |

There are **79 separately editable filled shapes**, with two enclosed holes.
One conservative simplification pass reduced SVG line/curve segments from
**835 to 598 (28.4%)**. Object and subpath counts stayed unchanged, and both
vector versions retain the source component/hole counts when rendered back
at source resolution. The comparison shows cleaner boundaries while retaining
recognizable shape. Visual acceptance remains with the Author.

Counts describe SVG path segments, including implicit command repetitions and
excluding close-path operations. Overlap measures masks at source resolution;
it is not a measure of beauty, native-screen legibility or runtime performance.

## Important limits

1. White is currently a mask role, not the final material color. Thresholding
   can merge originally different colors or turn darker details into the
   background. Use the preserved color reference when assigning materials;
   do not assume all original colored features can be recovered from this mask.
2. Simplification changes geometry. It does not automatically impose straight
   columns, equal spacing, symmetry, or a minimum final-pixel gap. Those need
   a later bounded geometry review before gradients/bevels or full-skin work.
3. The first white pilot included two one-pixel-high fragments of the adjacent
   fan rail at the column crop boundary. This second packet starts that crop
   at y=188 rather than y=187, excluding the truncated neighboring pieces.
   All prior packets are preserved. Crop closures are not semantic borders.
4. This is a four-element pilot, not a complete tracing of the interface.
   No gradients, bevels, AGNB packaging, application changes or deployment
   were performed. Stop here for Author review.

## Reproduce

From the project root, use a new output directory:

```bash
.venv/bin/python docs/tasks/SKIN-013/white-shape-pilot-02/trace_white_pilot.py \
  --source docs/tasks/SKIN-013/source-test-01/flat-outline-master_bw_threshold.png \
  --params docs/tasks/SKIN-013/white-shape-pilot-02/parameters.json \
  --out docs/tasks/SKIN-013/another-white-pilot
```

The saved builder reproduces masks, SVGs, individual shapes, rendered
comparisons and measurements. The README/gallery/diagnostic color maps are
presentation files. See [report.json](report.json), [parameters.json](parameters.json)
and [verification.json](verification.json). The exact CLI and profile used
for each simplification are recorded in its `region.json`.

The underlying command is:

```bash
INKSCAPE_PROFILE_DIR=/path/to/isolated-profile inkscape input.svg \
  --actions='select-all:all;path-simplify' \
  --export-type=svg --export-plain-svg --export-filename=output.svg
```

Profile preferences contain:

```xml
<inkscape version="1"><group id="options">
  <group id="simplifythreshold" value="0.0003"/>
</group></inkscape>
```

References: [Inkscape command-line actions](https://wiki.inkscape.org/wiki/Using_the_Command_Line),
[isolated profile setting](https://wiki.inkscape.org/wiki/Environment_variables),
and [Potrace library API](https://potrace.sourceforge.net/potracelib.pdf).
Installed `inkscape --action-list` confirmed `path-simplify`; the tests above
verify actual SVG changes and rendered results rather than relying on the docs.

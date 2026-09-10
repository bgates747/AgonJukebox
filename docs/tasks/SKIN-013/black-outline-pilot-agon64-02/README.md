# Exact-black vector pilot — supplied Agon palette image

Status: four-element pilot ready for Author review. No whole-skin tracing,
color reconstruction, gradient/bevel synthesis or runtime integration yet.

Start with the [zoomable gallery](index.html), [comparison sheet](comparison.png)
or [individual elements](elements/). Each named folder contains the source crop,
exact black mask, editable SVGs, rendered PNGs, contour overlays and measurements.
The gallery compares the closer `faithful.svg` fit with `smooth.svg`.

## Input and method

1. The Author redirected this experiment to
   `../source-test-01/flat-outline-master_agon64.png`: 1448x1086, six exact Agon
   colors, SHA256 `e26f95ddfed55de1fa59a779c26421f7c64db7b9c25d0c63854ebfe70b90933f`.
   The source is preserved. Selection is exactly RGB(0,0,0); no threshold
   tuning, downsampling, blur or new quantization was necessary.
2. Background navy has become black in this input, so the traced shapes include
   panel backgrounds as well as outlines. Colored regions enclosed by black
   become holes. These are filled-region vectors, not inferred centerline
   strokes or a semantic model of all six colors.
3. The installed Potrace 1.16 library supplies curves and corners through a
   small ctypes adapter, following its [official library API](https://potrace.sourceforge.net/potracelib.pdf)
   and [1.16 source header](https://potrace.sourceforge.net/download/1.16/potrace-1.16.tar.gz).
   Separate compound SVG paths retain each black component and its holes.
   There are no embedded raster images. Inkscape 1.2.2 independently renders
   the saved SVGs for comparison. No new dependency was installed.
4. The tiny-island/hole cleanup proposal changed **zero pixels** in these four
   crops. Raw and cleaned masks are identical. Potrace's own speck suppression
   is disabled. The differences shown come from curve fitting/rasterization.
5. `faithful` uses corner threshold 0.55 and curve optimization tolerance 0.2
   source pixels. `smooth` uses corner threshold 1.0 with the same tolerance.
   These are tracer controls, not a guaranteed maximum displacement. The
   closest fit is the default review candidate; both are retained.

## Results

| Element | Source pixels | Contours | Segments | Ink overlap (IoU) |
| --- | --- | ---: | ---: | ---: |
| left-fan | 192×182 | 19 | 181 | 97.78% |
| left-column | 173×592 | 39 | 312 | 94.86% |
| previous-button | 126×92 | 5 | 28 | 99.61% |
| footer-jewel | 119×115 | 4 | 100 | 97.89% |

The faithful traces retain all six connected black regions and all 61 enclosed
holes across the four crops, including after rendering back at source size.
The source column contains especially thin, irregular edges; its fit still
needs visual judgment. Overlap percentages measure binary masks at source
resolution and do not establish aesthetic acceptance or geometric identity.

## Review details and limits

1. The contact sheet shows source, exact black mask, unchanged cleanup mask,
   vector render and cyan contour overlay. `*-differences.png` uses red for
   removed black pixels and green for added black pixels. Diagnostic images
   may contain annotation colors; they are not finished skin assets.
2. `pilot-outlines.svg` positions only the four traced pieces in the full
   canvas. Its 512x384 PNG is a two-color outline diagnostic. Stroke thickness
   has not been normalized: narrow source lines may still disappear at native
   resolution. The next review should decide whether to model/simplify these
   boundaries before adding controlled widths, color regions or shading.
3. The first exact-palette crop accidentally included a one-pixel-wide strip
   of the adjacent panel alongside the column. This second packet corrects
   the crop from x=190 to x=188; the original is retained as evidence in
   `../black-outline-pilot-agon64-01/`. Crop-edge closures remain crop boundaries,
   not automatically standalone ornament geometry.
4. The earlier RGB-threshold pilot completed before the source redirection and
   remains in `../black-outline-pilot-01/`. It is not the selected input/result.
5. No image generation or further source editing was used in this step.
   This packet is an intermediate review, not the final Art Deco skin.

## Reproduction and checks

From the project root, choose an output folder that does not already exist:

```bash
.venv/bin/python docs/tasks/SKIN-013/black-outline-pilot-agon64-02/trace_black_pilot.py \
  --source docs/tasks/SKIN-013/source-test-01/flat-outline-master_agon64.png \
  --params docs/tasks/SKIN-013/black-outline-pilot-agon64-02/parameters.json \
  --out docs/tasks/SKIN-013/another-black-pilot
```

The saved builder reproduces the masks, SVGs, raster diagnostics and report;
this README and gallery are review presentation files. The script refuses to
write over an existing output. See [report.json](report.json) for recorded
versions, library hash, parameters and per-region measurements, and
[verification.json](checks/verification.json) for the final checks.

Independent adapter checks cover widths 63, 64 and 65 around a native-word
boundary, asymmetric placement, an enclosed hole with a nested ink island,
and an empty mask. They render the resulting SVGs and compare exact fixture
pixels, checking word packing, orientation, nesting and transparency.

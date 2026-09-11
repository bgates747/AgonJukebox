# Art Deco aligned font-sheet draft

Open [ArtDeco_Concept_64x128.png](ArtDeco_Concept_64x128.png) in GIMP or the
font maker. The [XML sidecar](ArtDeco_Concept_64x128.png.xml) supplies its import
settings. [Editable SVG](ArtDeco_Concept_64x128.svg),
[printable-character preview](printable-preview.png), and
[text specimen](specimen.png) are also available.

## Import settings

| Setting | Value |
| --- | --- |
| Full sheet | 1024 × 2048 pixels |
| Grid | 16 columns × 16 rows |
| Horizontal pitch / cell width | 64 pixels |
| Vertical pitch / cell height | 128 pixels |
| First / last slot | ASCII 0 / 255 |
| Visible glyphs | ASCII 33–126, all 94 present |
| Empty slots | 0–32 and 127–255; space is intentionally blank |
| Baseline | 100 pixels down from each cell's top edge |
| Offsets and scale adjustments | All zero |
| Foreground / background | White / opaque black |
| Raster | 1-bit PNG; no antialiasing or dithering |

The first two rows of the full sheet are intentionally empty. Import the full
sheet, rather than printable-preview.png or specimen.png. The XML's
original_font_path is absolute, following the editor's current convention;
update it if you move this folder. Opening the PNG or XML through the existing
reader reproduced every output pixel and split the sheet into the correct 256
cells. The desktop editor and its recent-file preferences were not changed.

These generous source-art dimensions are for further editing and eventual
conversion. The working application still uses its existing fonts.

## Geometry and processing

The Author's unchanged 887 × 1774 thresholded source contains six occupied rows
and sixteen character columns. Projection gaps give black-only extraction
seams. All 79,037 white source pixels are assigned to their ASCII glyph, including
disconnected dots, punctuation and percent-sign parts. No size filter, blur,
morphological cleanup or new character design was applied.

Potrace 1.16 traces white filled regions with alphamax 0.55, opttolerance 0.2
and speck removal disabled. One headless Inkscape 1.2.2 simplification invocation
uses threshold 0.0003 and individual-path bounds in an isolated preferences
directory. The paths retain 104 filled components and 30 enclosed holes.
Drawing segments, including closure segments, fall from 2,428 to 1,975 (18.7%).
The original trace and simplified SVG are retained in source coordinates.

Each glyph receives the same 1.3× geometric scale and is centered horizontally
by its ink bounding box. Baselines are estimated from representative characters
in each source row: 596, 690, 787, 883, 980 and 1073. Each row is translated to
the common target baseline. Vertical placement within a row is preserved,
including punctuation, accents, ascenders and descenders; glyphs are not
individually stretched or snapped to their bottommost pixel. This preserves
small source-art irregularities for later design review.

The final SVG uses named ASCII paths and uniform affine transforms. Cairo 1.18.0
renders it with CAIRO_ANTIALIAS_NONE. The actual raster is checked for pure black
and white before lossless 1-bit packing; there is no post-render quantization.
Inkscape remains the geometry editor, rather than the final PNG exporter.

## Validation and provenance

See [report.json](report.json), [glyph-map.json](glyph-map.json), and
[parameters.json](parameters.json). Every glyph retains its component/hole
counts in both source-resolution renders and the aligned output. All glyphs
have black margins inside their assigned cells. Unused cells are empty.
At source resolution, the trace changes 713 source pixels and the simplified
paths change 702; these are edge adjustments, not pixel-identical tracing.

Ten artwork/mapping files reproduce byte-for-byte in a separate build. Metadata
differs only where its absolute destination path changes. Existing output
directories are rejected. Both source images and the user's Inkscape preferences
are unchanged. The PNG SHA-256 is
`29e3ed0459dad26c31e7a5fcdb2c302abfdffe7770a42c96b998638af63f6330`.

This is a technically checked design draft awaiting visual acceptance.
Conservative smoothing retains some irregularities in the generated artwork;
final small-font legibility and pixel fitting remain later work.

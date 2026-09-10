# Full-image sampled flat-color candidate

Open [preview.png](preview.png): exactly 512x384, indexed PNG with the 64-color
Agon palette embedded. [Gallery](index.html), [editable SVG](colored-shapes.svg),
[4x nearest-neighbor view](preview-4x.png), [color table](shape-colors.csv).

The script traced all 554 white components from the supplied
binary source. For each original component it samples a two-source-pixel inset
(falling back to the whole component if empty), finds the most populated
16x16x16 RGB histogram bin, and takes that bin's median original RGB. It then
selects the nearest Agon color by squared RGB distance. Ties use the lowest
bin/palette index. See shapes.json for areas, samples, confidence and colors.
Sampling uses the matching unquantized flat-outline master, without registration
or resizing. The inset affects color sampling only, not the shape geometry.

Potrace uses the pilot's 0.55 corner threshold and 0.2 source-pixel tolerance,
with speck suppression disabled. Inkscape simplifies each shape separately
once, at 0.0003, preserving IDs. Per-shape bounds keep small text from inheriting
the whole image's simplification scale. This is a full-image extension, not a
reuse of the four cropped pilot vectors. Earlier pilots are unchanged.

## Rasterization

Inkscape Inkscape 1.2.2 (b0a8486541, 2022-12-01) exported 44091
off-palette pixels. This installed CLI does not expose the PNG antialias option;
the crispEdges hint, zero extension preference and document flag also failed
the saved curved/diagonal export probes. Evidence is in antialias-probe/.
The later command-line switch is described in the
[Inkscape 1.4 notes](https://wiki.inkscape.org/wiki/Release_notes/1.4#Command_line).

The final PNG instead renders the same simplified SVG paths through the already
installed libcairo with CAIRO_ANTIALIAS_NONE. cairo_flat_svg.py deliberately
supports only our flat path/rectangle subset and rejects unsupported effects.
It draws directly at 512x384. There is no image resize, dithering or palette
repair after rendering; the indexed conversion is an exact lookup and fails
on any off-palette pixel. The final PNG has 14 visible
colors and zero off-palette pixels. The Cairo antialias setting is documented
in the [Cairo manual](https://www.cairographics.org/manual/cairo-cairo-t.html#cairo-antialias-t).

## Limits and next review

This assigns one color to each existing white region. Black mask regions remain
black, including darker decorative features merged into them by thresholding.
It cannot recover those missing boundaries. No gradient, bevel, material-role
inference or manual color correction is included. Sample text is traced as
part of the concept image; it is not an application font or functional screen.
Native rasterization can lose tiny components or narrow gaps. Review the saved
native image before further work; source-resolution topology is not a guarantee
of final-screen detail. Sources and user Inkscape preferences were unchanged.

## Reproduce

From the project root, choose a new output directory:

```bash
.venv/bin/python docs/tasks/SKIN-013/flat-color-full-01/colorize_shapes.py \
  --mask docs/tasks/SKIN-013/source-test-01/flat-outline-master_bw_threshold.png \
  --reference docs/tasks/SKIN-013/source-test-01/flat-outline-master.png \
  --params docs/tasks/SKIN-013/flat-color-full-01/parameters.json \
  --out docs/tasks/SKIN-013/another-flat-color-candidate
```

The script produces all review assets and measurements. It refuses to overwrite
an output directory. This experiment adds no production dependency and does not
change application assets, emulator deployment or AGNB packaging.

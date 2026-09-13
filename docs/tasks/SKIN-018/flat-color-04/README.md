# 70s skin: flat Agon64 color review

Open index.html. Suggested result: candidate 3, consistent source families.
All three numbered candidates are Agon64-only. Original art and unquantized
reference views are explicitly labeled. No dithering or gradients.

The accepted 4-connected mask has 174 remaining white regions after state-text
removal. Candidate 1 reuses the Art Deco two-pixel inset / 16-wide RGB histogram
sampler and nearest-RGB mapping. Candidate 2 adds a provisional dark backdrop
mask identified by explicit source-color rules (report.json).

Candidate 3 retains all foreground geometry, groups source colors into eight
visually identified families and uses weighted Oklab distance to choose actual
Agon64 colors. Seeds, fitted source medians, weights, palette mapping and every
region assignment are in color-families.json. This is a source-specific manual
art-direction refinement; it is not claimed to generalize automatically to new
skins. Fine playlist rules are assigned the cream label color. Expanded cleared
text fields remove original text shadows from the supplemental backdrop.

Eight visible colors in candidate 3. Dark brown maps to #550000 and orange to
#AA5500: visible palette compromises, not exact source matches. Original teal
is retained as #005555. All binary-mask black regions without supplemental
backdrop remain black. Earlier flat-color-01/02/03 are preserved development
iterations; 04 is the current worksheet.

Source-size indexed PNGs, 512x384 nearest-neighbor previews and integer zooms
are included. There is no vector smoothing yet. Labels and color records retain
independent regions for future gradient experiments. Source file and accepted
mask are unchanged. No application/runtime or deployment changes.

Reproduce from the project root:

.venv/bin/python docs/tasks/SKIN-018/flat_colors.py --out NEW_DIRECTORY

The saved flat_colors.py is a provenance snapshot; run the parent script because
its source paths are relative to its working location. Existing Art Deco helpers
remain in SKIN-013. Palette: flat-color-full-02/Agon64.gpl. Oklab matrices and
reference implementation: https://bottosson.github.io/posts/oklab/ (Björn Ottosson).

Validation is in verification.json: all 25 generated outputs reproduce exactly,
all numbered candidate PNGs have only Agon64 colors, shape geometry is unchanged,
label/color reconstruction passes, supplemental backdrop is disjoint, source
hashes remain exact and local gallery links resolve. Await Author color review
before a gradient study. Broad rainbow bands and side rails are likely first
small experiments; no gradient technique is selected yet.

# Grayscale threshold ranking experiment

Run from the project root:

```sh
.venv/bin/python docs/tasks/SKIN-018/rank_masks.py that-70s-skin.png \
  --out docs/tasks/SKIN-018/review-01 \
  --reference-source docs/tasks/SKIN-013/source-test-01/flat-outline-master.png \
  --reference-mask docs/tasks/SKIN-018/artdeco-reference-mask.png
```

Output must be new. Requires NumPy, Pillow and SciPy in project .venv.
The script saves binary source-resolution masks, region maps, grayscale inputs,
a nearest-neighbor 512×384 comparison, HTML gallery, complete scores and provenance.
No blur, cleanup, morphology, tracing, recoloring or deployment is applied.
The erosion/filter operations measure quality only; they never change saved masks.

Grayscale candidates are Pillow L (encoded Rec.601 luma), encoded Rec.709 luma,
and linear-light Rec.709 luminance encoded back through the sRGB transfer curve.
Inputs are treated as sRGB RGB values; embedded profiles are not transformed.
Transparency is rejected. Threshold convention: white iff gray > threshold.

Reference fitting searches all 256 thresholds and reports all tied minima.
It only estimates settings: profiles, editor rounding and manual edits can leave
mismatches. Reference fitting does not train or tune the heuristic weights, or
force the old threshold onto a different image.

Ranking sweeps thresholds 4–252 in steps of four, plus the fitted reference
threshold for each method. White shapes use 4-connectivity. Useful shapes have
at least two target-pixel-equivalents of source area (16 pixels for this source).
Tiny shapes remain intact; they are not necessarily noise. Score weights are
30% white-mask IoU across ±4 levels, 25% useful component-count stability,
20% boundary contrast across a 5×5 window, 15% non-tiny component proportion,
10% avoidance of a dominant merged white region. Extreme coverage is penalized;
shortlist admits 12–85% white. Five masks are chosen in score order, each at
least 2.5% different in source pixels from every previously selected mask.

These are explicit provisional heuristics. Component-count stability can miss
simultaneous merges and splits; text can dominate counts; large valid panels
can look like merged blobs. Equal-luminance colors and dark details can vanish.
The method does not identify semantic objects or prove closed intended contours.
Human selection remains necessary. Region-map colors are diagnostic only.

Validation: focused fixtures cover exact reference recovery, noise penalties,
4-connected diagonals, uniform-image rejection, alpha rejection and overwrite
protection. Source hashes and saved binary dimensions are checked for each run.

## First review results

[Open gallery](review-01/index.html). First suggested mask is Pillow L > 80:
394 useful regions, three tiny regions, 43.6% white. Visual inspection of the
comparison retains flowers, record labels and colored bands in this candidate.
Higher-threshold choices lose many colored ornaments, exposing a limitation of
cleanliness/stability scores. Scores are relative heuristics, not probabilities.

The second accepted Art Deco mask was absent from the Mac migration. Its unchanged
PNG was retrieved from Linux into artdeco-reference-mask.png (SHA256
fef71d576bb930fbf478e2e00259b9a0b742f7cb97123c881f88e77440246d33).
Best reconstruction: linear-luminance-srgb > 65, 393 differing pixels out of
1,572,528 (99.9750% agreement). See artdeco-reconstructed.png and
artdeco-differences.png (orange = differing pixels). This does not establish
GIMP's exact original setting. Pillow L > 62 differs by 1,540 pixels.

All 24 review outputs reproduce byte-for-byte, including full sweep scores.
All five saved masks independently match their stated threshold operation.
Three focused tests pass. See verification.json. Await Author visual selection.

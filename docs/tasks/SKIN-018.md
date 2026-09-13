# SKIN-018 — Rank grayscale threshold masks for shape extraction

Author request: script grayscale/threshold processing and suggest useful shape masks,
using the successful Art Deco mask as evidence. Scope: recover best matching
thresholds under explicit grayscale conventions, evaluate source-resolution masks,
and provide a small varied shortlist for the new 70s artwork. Preserve originals.
No cleanup, tracing, runtime integration or deployment. Ranking is heuristic;
human review owns shape/semantic quality. Implementation and evidence in SKIN-018/.

Implementation complete for first review. See SKIN-018/README.md and review-01/index.html. Candidate 1 is suggested; acceptance pending. All outputs repeat exactly.

## Author review — 2026-09-12

Author accepts candidate 1 for GUI element shapes (Pillow L > 80) and prefers
candidate 4's displayed color scheme. Candidate 4's region-map colors are
arbitrary connected-component diagnostic colors, not source-color sampling or
an Agon palette conversion. Treat its appearance as an art-direction reference;
do not substitute its threshold geometry for accepted candidate 1. No color
transfer or runtime integration requested yet. Candidate 4 region map contains
193 distinct RGB colors, only black belongs to Agon64.

## State-text removal worksheet — 2026-09-12

Author withdraws the diagnostic-color preference. Next color iteration must
use actual Agon colors; do not transfer candidate 4's region colors.
Current authorized step: manually inspect accepted candidate 1 and remove
obvious application-state text, preserving static GUI labels. Create a new
browser worksheet before any color iteration. Retain original mask and source.
Use explicit reviewed source-pixel regions; preserve nontext controls and art.

## SKIN-018 state-text excision — 2026-09-12

Author withdrew diagnostic-color preference; subsequent color candidates must
use Agon colors. Current request completed as manual inspection and scripted
source-pixel text removal on accepted candidate 1. Browser worksheet:
docs/tasks/SKIN-018/state-text-02/index.html. 34 regions / 49,107 changed pixels;
all outside pixels unchanged. Static headings and nontext widgets/art retained.
First pass's two underscore remnants caught by visual QA and corrected in 02.
Repeat build, saved pixel checks, protected static regions and worksheet links
pass. Original PNG/mask intact. No runtime changes, commit or push. Await review.

## 70s flat-color study — 2026-09-12

Author shifts the reference-skin exploration temporarily to the simpler 70s art.
Use original flat source colors and the cleaned accepted mask to derive real
Agon64 fills; prepare browser review, then consider gradients on selected pieces.
Keep Art Deco and prior source/worksheets intact. No runtime deployment.

## Brown palette preference — 2026-09-12

Author explicitly accepts dark reds as substitutes for source browns and dislikes
brown-to-green/olive shifts. Preserve warm brown/red families in future palette
mapping and gradient ramps; avoid automatic nearest-color choices that turn
brown regions green. Current candidate 3 backdrop #550000 follows this direction.
This preference is not blanket acceptance of the complete color worksheet.

## 70s flat-color worksheet — 2026-09-12

Current review: docs/tasks/SKIN-018/flat-color-04/index.html, opened in browser.
Three actual-Agon candidates; suggested 3 uses eight visually identified source
color families with fitted medians and weighted Oklab mapping. 174 original mask
regions preserved. Explicit supplementary brown backdrop mask recovers dark
regions discarded by threshold; all additions are separately saved. Eight visible
colors; brown maps to dark red #550000, orange to ochre #AA5500. These compromises
need Author review. Source-family swatches and original reference are shown.

Plain RGB candidate caused teal gray / inconsistent petals; automatic eight-cluster
trial merged teal and green. Preserved trials 01–03; 04 contains refined manual
source-family initialization. Full source, original mask and Art Deco untouched.
All generated outputs reproduce byte-for-byte, Agon palette and independent
label/color reconstruction checks pass. No runtime, deployment, commit or push.
Gradients remain the next study after base-color review; consider broad rails
or rainbow bands first. Source script and limits in SKIN-018/flat_colors.py and
flat-color-04/README.md. Browser gallery is the requested review interface.

## Closed into implementation — 2026-09-12

Author authorizes making/deploying the 70s skin from the reviewed packet. SKIN-018
experiment complete; remaining implementation/gradient review belongs to SKIN-019.
Removed SKIN-018 from TODO to avoid competing active tasks. Current baseline is
flat-color-04 candidate 3; source and prior candidates remain frozen evidence.

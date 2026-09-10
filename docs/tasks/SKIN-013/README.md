# SKIN-013 vector workflow checkpoint

Start with the [white-shape pilot 02 gallery](white-shape-pilot-02/index.html)
and its [methods, results and reproduction](white-shape-pilot-02/README.md).
The [task specification](../SKIN-013.md) owns scope and the incremental review
sequence. [Shading possibilities](shading-possibilities.md) records options
discussed after the pilot; none has been implemented here.

## Preserved progress

1. [Source test 01](source-test-01/README.md): generated flat-outline source,
   prompt and provenance, plus the Author's Agon64 and binary variants.
2. `black-outline-pilot-01/`: initial black-region pilot on the generated RGB
   source. Historical threshold and cleanup exploration.
3. `black-outline-pilot-agon64-01/` and
   [black-outline-pilot-agon64-02](black-outline-pilot-agon64-02/README.md):
   exact-black tracing of the supplied six-color source. The second corrects
   the column crop to exclude a neighboring panel fragment.
4. `white-shape-pilot-01/`: first exact-white filled-shape trace and actual
   headless Inkscape simplification on the supplied binary source.
5. [White-shape pilot 02](white-shape-pilot-02/README.md): current selected
   result, correcting the column crop to exclude two truncated neighboring
   rail fragments. It contains 79 filled objects and two holes; simplification
   reduces SVG segments from 835 to 598 while retaining source-resolution
   rendered component/hole counts. Individual editable SVGs are included.

All earlier candidates are evidence, not competing current recommendations.
Source images and saved candidates are preserved; use a new output directory
for another iteration. Root scripts/parameters reflect the latest work, while
each pilot retains the scripts and parameters used to generate it.

## Checkpoint scope — 2026-09-10

The Author requested recording the shading options, committing progress and
stopping to discuss next steps. This checkpoint includes the task, its source
art, scripts, parameters, candidate vectors, comparisons and verification.
It makes a scoped exception to the private task ignore rule, as did the previous
Art Deco checkpoint. General agent records, Python caches, incidental Inkscape
extension logs and emulator state remain private/ignored. Minimal isolated
Inkscape preference files are retained as experiment parameters.

The Author responded positively to the white-region result. This remains a
four-element source-resolution experiment, not acceptance of a finished skin
or proof of 512x384 legibility. Color/material assignment, geometric refinement,
shading, full-composition tracing and runtime integration remain open.
There are no application or deployment changes in this checkpoint.

The existing [pilot verification](white-shape-pilot-02/verification.json) records
the successful geometry checks. The [checkpoint audit](checkpoint-verification.json)
records file readability, source hashes and checks of the saved selected pilot.
No candidate was regenerated for the checkpoint.

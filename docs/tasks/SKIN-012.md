# SKIN-012 — Extract and refine reusable Art Deco skin elements programmatically

## State

- Status: Specification accepted and frozen for implementation; implementation not started
- Started: --
- Finished: --
- Registration: Requested by the Author after reviewing the smooth Art Deco
  master and supplying an undithered, scaled, palettized version.
- Approval: 2026-09-09; the Author requested a specification/art commit followed
  by implementation. The scoped frozen snapshot is an explicit exception to
  the usual private-task tracking policy.

## Intent and scope

Reconstruct the supplied 512x384 Art Deco design from reusable bitmap elements
and simple fills. Preserve its dimensional shading, fine outlines, ornament,
and readable composition while reducing unique pixel data sent to the VDP.
The agent owns image analysis, region selection, scripted extraction,
algorithmic refinement, and iteration. The Author reviews the resulting
appearance and tradeoffs; manual chopping, masks, or coordinate entry by the
Author are not prerequisites.

This is a host-side authoring study feeding SKIN-006. Image analysis and gradient
construction run offline, not during playback on the eZ80 or VDP. The Author
reviewed this specification and authorized implementation after its freeze
commit. Subsequent progress and results live in `SKIN-012/`; keep the accepted
requirements in this document stable.

## Inputs and authority

1. Primary source: [Author's scaled, palettized PNG](SKIN-006/art-deco-2026-09-09/art-deco-scaled-palettized.png).
   At registration it is 512x384, with 27 distinct colors, all RGB222.
   SHA256: `178e443dfcc3a47a4ebfbf3df6385a57b75b8c54533d9595d96101756197ef55`.
   The Author deliberately omitted dithering to retain coherent color regions
   and regular gradient bands. Preserve this file unchanged.
2. [Smooth master](SKIN-006/art-deco-2026-09-09/art-deco-smooth-master.png)
   provides reference for intended shading and shape. It is not a replacement
   for the Author's chosen native-resolution baseline.
3. [SKIN-006](SKIN-006.md) owns the reference skin and visual qualification;
   [SKIN-005](SKIN-005.md) owns eventual reusable authoring tools;
   [SKIN-007](SKIN-007.md) owns runtime resource and audio qualification.
4. [SKIN-001](SKIN-001.md) owns final geometry/resource contracts. This art study
   can inform them without freezing a new application layout or adopting the
   generated screenshot's sample text and controls as product requirements.
5. Retain the [printed-character rendering decision](../decisions/ADR-0001-character-based-ui-rendering.md)
   and [command-traffic study](SKIN-000/command-traffic-study.md). Runtime bitmap
   assets remain AGNB; loose `.font` files retain their existing exception.

## Required methods and constraints

1. Use deterministic local scripts and recorded parameters. Do not use the
   imagegen skill, image-generation tools, or generative image editing for this
   task. Existing generated art is input only. Use the project `.venv/bin/python`
   and inspect relevant existing agon-utils capabilities before duplicating them.
2. Every reconstructed skin preview must be exactly 512x384. Every component
   must have explicit integer dimensions and placement. All visible output
   pixels must use RGB channels drawn from `{0, 85, 170, 255}`. Do not introduce
   dithering, fractional-alpha edge blending, or off-palette antialiasing.
   Internal fitting calculations may use continuous values; raster output must
   be explicitly mapped to the allowed palette and verified after saving.
3. Preserve interesting gradients. Repetition is a means of efficient
   construction, not a reason to flatten deliberate highlights and shadows.
   Refine accidental variation within selected regions while retaining intended
   bands, line widths, silhouettes, corner shapes, jewels, and accent inserts.
4. Select boundaries and masks through agent inspection and scripted analysis.
   Agent-authored coordinates and exceptions are acceptable when recorded in
   parameters and reproducible; do not require a universal automatic segmenter
   or force the entire artwork onto one tile grid.
5. Keep inputs immutable, preserve iteration outputs, and record which changes
   are intentional. Keep scripts, parameters, masks, assets, and evidence in
   ignored `docs/tasks/SKIN-012/` until accepted for promotion.

## Gradient treatment

1. **Axis-based gradients for columns and rails.** Fit color profiles along a
   chosen horizontal or vertical axis, with explicit shadow/highlight stops.
   For a vertical column, shading usually varies across its width while a long
   portion repeats down its height. Support several piecewise-linear ramps to
   preserve rounded or fluted metal/glass effects; do not force an entire
   highlight-and-shadow profile into one monotonic ramp. Quantize to explicit
   palette ramps with controlled band boundaries. Preserve meaningful changes
   along the column through separate bands or inserts.
2. **Contour-following bevel gradients.** Use a shape mask and distance from its
   boundary to define bevel depth/width and inset color bands. Where the source
   implies directional lighting, combine that distance with local boundary
   orientation (or normals derived from a distance/height field) to distinguish
   lit edges from shaded edges. Handle inner and outer borders deliberately.
   Distance alone creates an edge-following band; directional shading supplies
   the raised/recessed appearance. Fit parameters to the existing artwork.
3. Preserve straight and stepped Art Deco geometry and sharp facets when
   constructing bevel masks. A geometric distance field or recorded contour
   simplification may be preferable to blindly following raster irregularities.
   Keep all final bands palette-constrained and coherent at native resolution.
4. Use modal cross-sections, small-region cleanup, or boundary straightening
   only within suitable masks. Protect fine outlines and intentional isolated
   highlights. Global blur, majority filtering, and indiscriminate island
   removal are unsuitable defaults.

## Work

1. Record a reproducible baseline and identify candidate regions: column caps,
   shafts, accent bands, panel corners, straight edges, button surrounds,
   ornaments, flat fills, and dynamic-content areas. Measure exact and near
   repetition, symmetry alignment, and gradient profiles. Prior read-only
   analysis found 94.8% agreement with a modal row in the 53x118 left-shaft
   region `(7,112)-(60,230)` using exclusive upper bounds; this is a lead to
   recheck, not permission to discard every differing pixel. The prior whole
   image 8x8 split yielded 2,070 unique tiles, including text.
2. Build a first proof around one column: preserve its caps and accent inserts,
   regularize the shaft's shading, and reconstruct it from repeatable strips.
   Include an adjacent bevel-bearing cap or frame to exercise both gradient
   methods. Choose strip sizes from geometry and cost; a one-pixel analytic
   profile need not become one draw command per screen row.
3. Reconstruct and inspect each iteration at native resolution and integer
   magnification. Compare against the original with changed-pixel overlays and
   per-region statistics. Refine scripts and parameters autonomously, retaining
   useful candidates and recording why changes were made. Judge dimensional
   shading, seams, silhouette, and ornament alongside numerical error.
4. Extend the successful methods to mirrored decorations, corners/edges/centers
   of frames, common button surrounds, and separate symbols. Align pairs before
   selecting a canonical member. Preserve asymmetric details where they add
   value; mirroring geometry must not silently reverse a required lighting
   direction. Allow distinct shading variants when needed. Keep elaborate
   nonrepeating ornaments as larger bitmaps.
5. Extract an asset dictionary and placement/repetition manifest, with explicit
   dimensions, masks, symmetry variants, and region ownership. Deduplicate exact
   matches after refinement; use approximate matching only to propose recorded
   visual changes. Separate filenames, times, selection, and other changing
   information from reusable backgrounds. A demonstration text overlay may
   reproduce the screenshot for comparison but is not a dynamic runtime asset.
6. Rebuild the full 512x384 proof from the emitted assets and manifest. This
   reconstruction must be the review image, so extraction mistakes, omitted
   regions, overlaps, and tile seams are visible. Verify an independent render
   from the saved assets reproduces the chosen candidate pixel for pixel.
7. Produce a cost report and candidate AGNB packaging using the canonical
   tooling. Count unique RGBA2222 pixel payload, packaging/definition overhead,
   initial UART traffic, resident VDP memory, buffer/character-map use, and
   recurring draw-command traffic separately. Compare measured host sizes and
   explicitly modeled protocol costs against an unreduced baseline. Do not
   equate compressed PNG size with bytes uploaded to the VDP.
8. Present the preferred reconstruction, first-column study, asset sheet,
   difference views, parameters, reproduction command, and cost report for
   Author review. Feed accepted results into SKIN-005/006/007. Application
   integration, emulator deployment, runtime timing claims, and final art/tool
   promotion remain with those tasks and their existing validation gates.

## VDP construction considerations

1. Upload shared pixel data once through AGNB. Favor mapped-character runs for
   suitable repeated UI pieces, simple fills for uniform areas, and larger
   bitmaps for decorative pieces when their cost is justified. Evaluate stored
   drawing sequences or VDP-side assembly of larger strips where they reduce
   recurring UART commands. Count their storage and execution costs separately.
2. The stock [buffer API](https://agonplatform.github.io/agon-docs/vdp/Buffered-Commands-API/)
   provides copy and row-wise reversal operations. Evaluate generating mirrored
   variants on the VDP at load time to avoid uploading duplicate pixels; account
   for the extra resident memory if both copies are retained. Before proposing
   runtime changes, verify semantics against the pinned VDP 2.16.0 source and
   qualify them through the normal implementation tasks.
3. Resource savings do not justify excessive tile fragmentation or degradation
   of the accepted shading. Record the tradeoff among upload size, memory,
   redraw traffic, and appearance; do not invent a percentage-savings acceptance
   target before measuring the first proof.

## Validation and acceptance

1. A documented command reproduces the selected assets and full preview from
   unchanged inputs and recorded parameters, using versioned dependencies.
2. Saved output dimensions and palette membership pass pixel-level checks;
   outputs contain no dithering or fractional-alpha edges. Source hashes remain
   unchanged, and saved-asset reconstruction matches the reviewed candidate.
3. The agent completes region selection, extraction, and iterative refinement
   without requiring the Author to prepare crops or masks.
4. Review demonstrates preservation of useful axis-based and contour-following
   shading, readable fine borders, and seam-free repetition at 512x384. Intentional
   differences and approximate matches are exposed for review rather than
   described as lossless extraction.
5. The cost report distinguishes asset/upload savings from resident memory and
   recurring traffic. AGNB validation passes; host estimates are not presented
   as measured emulator or hardware performance.
6. The Author accepts the visual result and tradeoffs before the task is closed
   or its artwork is treated as the finished reference skin. Registration alone
   does not authorize implementation or claim acceptance.

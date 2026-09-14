# AgonJukebox TODO

This is the single authoritative index of unfinished work on this branch.
Task IDs remain stable. Detailed working notes and experimental skin assets
are local-only; finished skin documentation and tools will be published when
ready for distribution.

## First priority — Existing-skin UI correctness and consistency

7. [ ] **SKIN-007 — Qualify skinning and establish resource limits**
   - Started: 2026-09-14 (cross-skin UI review)
   - Finished: --
   - Status: First priority: review Art Deco, Seventies, PCB and Nineties against one control/state and text-layout matrix; correct each skin and align shared behavior where practical. Check play/pause/stop feedback, navigation, shuffle/loop/volume, dynamic text and transitions. Coordinate directory placement with SKIN-024; preserve each skin’s visual identity. Existing pixel tests are supporting evidence, not visual acceptance. Extended resource/hardware qualification remains in this same task.

This review takes precedence over new skins, gradients, custom fonts and cosmetic
expansion. Review worksheets and focused automated checks precede uninterrupted
human emulator review; use one patched-beta session and leave it untouched.

## Emulator preparation

1. [ ] **EMU-001 — Prepare and qualify the dedicated tagged-release emulator**
   - Started: 2026-09-08 13:49 EDT
   - Finished: --
   - Status: Mac project-local Fab 1.2.4/MOS 3.0.2 setup passed Author emulator checks on 2026-09-12. Original tagged-release qualification and large-file omission remain separate; 70s prototype accepted on hardware on 2026-09-13.

2. [ ] **EMU-002 — Review Fab Agon Emulator v1.2.5-beta1 on Mac**
   - Status: Author reports clean application exit and apparent audio improvement. Use 1.2.5-beta1 for several more review cycles to assess exit exceptions; preserve 1.2.4 for comparison.

3. [ ] **EMU-003 — Correct emulator host-filesystem large-file size truncation**
   - Status: Patched isolated beta build passes native 16 MiB boundary tests and Rumours validation; Author confirmed Rumours works and playback is clean; upstream PR #85 submitted, Tom is addressing f_truncate with a shared _poke32.

## Skinning

The first live skin milestone passed functional emulator testing and is
promoted into the application tree. Configuration, AGNB loading, live widgets
and playback are integrated. Remaining work covers the complete skin contracts,
authoring-tool refinements, artwork, resource qualification and release packaging.
The shared runtime loader, discovery and recovery chooser are accepted.

24. [ ] **SKIN-024 — Review directory placement across all skins**
   - Started: 2026-09-14
   - Status: Seventies implemented: 6×12 status text, 56-cell directory plaque and geometric SVG; native checks pass; Author considers the redraw a visual regression, refinement deferred. Directory placement and text-layout findings feed the first-priority SKIN-007 review; other skins remain pending review.

23. [ ] **SKIN-023 — Prepare the Nineties rack-stereo skin**
   - Started: 2026-09-14
   - Status: Author selected option 2 colors and requested a fresh geometric SVG redraw with better black/two-grey material treatment; Geometric Nineties implemented with shared 6×12 status support and independent message line; 52 native scenarios / 28,749 pixel checks and font-switch lifecycle checks pass; graphical emulator launched, awaiting Author review. Custom fonts deferred.

22. [ ] **SKIN-022 — Prepare the PCB concept for visual review**
   - Started: 2026-09-14
   - Status: Candidate 2 implemented and deployed to an isolated graphical emulator; 26 scenarios and 13,899 pixel checks pass. Await Author visual/audio acceptance before commit.


1. [ ] **SKIN-001 — Resolve and document the v1 skin contracts**
   - Started: 2026-09-07 20:49 EDT
   - Finished: --
   - Status: Authoring schema and bounded runtime layout/package contracts accepted (SKIN-020/021); reconcile the remaining decision register and resource qualification before release.
5. [ ] **SKIN-005 — Build reproducible skin authoring and validation tools**
   - Started: 2026-09-13
   - Status: SKIN-020 supplies the bounded shared compiler, strict validation and review generation; general authoring/resource/tool promotion remains.
   - Finished: --
6. [ ] **SKIN-006 — Design and build the rich reference skin**
   - Started: 2026-09-10
   - Finished: --
   - Status: Art Deco hardware-tested progress checkpoint 0a09cee preserved. 70s flat-color prototype accepted on hardware (SKIN-019 complete); gradients and extended qualification remain open.
8. [ ] **SKIN-008 — Package and document the skin-enabled release**
   - Started: --
   - Finished: --
9. [ ] **SKIN-009 — Package and qualify Classic (deferred)**
   - Started: --
   - Finished: --
   - Status: Deferred until the new skin runs with live player state; retain familiar styling within the shared layout.
11. [ ] **SKIN-011 — Investigate PB2000 as a possible skin**
   - Started: --
   - Finished: --
   - Status: Candidate steampunk-like skin vendored in [vendor/skins/pb2000.wsz](vendor/skins/pb2000.wsz); investigate suitability for AgonJukebox.
12. [ ] **SKIN-012 — Extract and refine reusable Art Deco skin elements programmatically**
   - Started: 2026-09-09 14:13 EDT
   - Finished: --
   - Status: Scripted extraction and AGNB host proof pass checks; Author found remaining dirt and ragged edges. Current workflow retained for comparison, with isolated editable elements; visual acceptance remains open.
13. [ ] **SKIN-013 — Explore vector tracing before downscaling Art Deco artwork**
   - Started: 2026-09-10 14:49 EDT
   - Finished: --
   - Status: Full-image 512x384 flat-color draft accepted for testing and committed: 554 sampled shapes, 14 Agon colors, antialiasing off, reproducible scripts and checks. Second threshold-mask artwork running in the local emulator with preserved controls/volume bar, updated Concept 02 font, and a moving selection sprite. 26 scenarios and 14,099 pixel checks pass. Hardware responsiveness restored and progress checkpoint accepted; color/refinement and final skin completion remain open.
14. [ ] **SKIN-014 — Trace and align the Art Deco font concept for font-maker import**
   - Started: 2026-09-10
   - Finished: --
   - Status: Aligned Art Deco font draft ready for review: 1024×2048 PNG, 64×128 ASCII cells, editable SVG and font-maker metadata. All 94 visible glyphs preserved; import and repeat-build checks pass. Assets: src/fonts/art-deco-concept-01/aligned-01.
15. [ ] **SKIN-015 — Recolor antialiased font PNGs for the Agon palette**
   - Started: 2026-09-10
   - Finished: --
   - Status: Real 6×12 PNG processed; normal/selected variants each retain four Agon colors and all 94 glyphs. Pixel mapping and repeat-build checks pass. Review: src/fonts/art-deco-concept-01/color-01.

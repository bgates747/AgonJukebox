# AgonJukebox TODO

This is the single authoritative index of unfinished work on this branch.
Task IDs remain stable. Detailed working notes and experimental skin assets
are local-only; finished skin documentation and tools will be published when
ready for distribution.

## Emulator preparation

1. [ ] **EMU-001 — Prepare and qualify the dedicated tagged-release emulator**
   - Started: 2026-09-08 13:49 EDT
   - Finished: --
   - Status: Mac project-local Fab 1.2.4/MOS 3.0.2 setup passed Author emulator checks on 2026-09-12. Original tagged-release qualification and large-file omission remain separate; 70s prototype accepted on hardware on 2026-09-13.

## Skinning

The first live skin milestone passed functional emulator testing and is
promoted into the application tree. Configuration, AGNB loading, live widgets
and playback are integrated. Remaining work covers the complete skin contracts,
chooser/switching, authoring tools, resource limits and release qualification.


1. [ ] **SKIN-001 — Resolve and document the v1 skin contracts**
   - Started: 2026-09-07 20:49 EDT
   - Finished: --
   - Status: In progress; printed bitmap characters and Winamp artwork import accepted. Import proof complete; layout, package and resource contracts remain to be finalized.
3. [ ] **SKIN-003 — Implement configuration, discovery, and recovery chooser**
   - Started: --
   - Finished: --
4. [ ] **SKIN-004 — Load external assets and render the new skin**
   - Started: 2026-09-08 16:32 EDT
   - Finished: --
   - Status: First native render and live integration accepted; complete loader/switching work remains.
5. [ ] **SKIN-005 — Build reproducible skin authoring and validation tools**
   - Started: --
   - Finished: --
6. [ ] **SKIN-006 — Design and build the rich reference skin**
   - Started: 2026-09-10
   - Finished: --
   - Status: Art Deco hardware-tested progress checkpoint 0a09cee preserved. 70s flat-color prototype accepted on hardware (SKIN-019 complete); gradients and extended qualification remain open.
7. [ ] **SKIN-007 — Qualify skinning and establish resource limits**
   - Started: --
   - Finished: --
   - Status: First functional emulator milestone accepted; extended timing/resource and hardware qualification remain.
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

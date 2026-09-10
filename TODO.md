# AgonJukebox TODO

This is the single authoritative index of unfinished work on this branch.
Task IDs remain stable. Detailed working notes and experimental skin assets
are local-only; finished skin documentation and tools will be published when
ready for distribution.

## Emulator preparation

1. [ ] **EMU-001 — Prepare and qualify the dedicated tagged-release emulator**
   - Started: 2026-09-08 13:49 EDT
   - Finished: --
   - Status: Usable samples validated; Fab 1.2.4 restored. Large-file omission deferred in main TODO.md (ccd2e46).

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
   - Started: --
   - Finished: --
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
   - Status: Full-image 512x384 flat-color draft accepted for testing and committed: 554 sampled shapes, 14 Agon colors, antialiasing off, reproducible scripts and checks. Further authoring exploration remains open.

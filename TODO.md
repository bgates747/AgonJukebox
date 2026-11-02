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
   - Started: 2026-09-10
   - Finished: --
   - Status: Basic Art Deco concept accepted in 49511a6. Concept 02 antialiased 6×12 font passes 26 scenarios and 14,085 target pixels; the owner reviewed it on hardware with a CRT and authorized its checkpoint. Extended qualification remains open.
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
18. [ ] **SKIN-018 — Diagnose intermittent VDP reset during startup**
   - Started: 2026-10-31
   - Finished: --
   - Status: Latest accepted runtime baseline pinned; full logging player deployed to AGONC8. Startup logs append to /JBSTART.LOG; awaiting hardware failure evidence.

## Audio playback engines

1. [ ] **AMP-001 — Evaluate agonAMP and reusable tracker-music hooks**
   - Started: 2026-10-31
   - Finished: --
   - Status: Plan committed/pushed; unchanged agonAMP and four native ZXArt formats pass Pi5 headless playback/control/relaunch checks. Deployed to AGONC8 /others/pollito/agonAMP; awaiting hardware feedback before integration research.

## UART transport experiments

1. [ ] **UART-001 — Explore runtime-selectable MOS UART0 transport**
   - Started: 2026-11-01
   - Finished: --
   - Status: CTS1 prototype passes Pi5 qualification; Author provisionally reports sustained hardware playback, fewer directory-navigation skips and snappy keys. Returned snapshot confirms CTS1, zero errors and all 95902 packets released; installed firmware identity remains unconfirmed. Progress checkpoint accepted; full runtime switching and logging remain incomplete. UART-002 is the next focused test.

2. [ ] **UART-002 — Test explicit batch16 OTIRX playback**
   - Started: 2026-11-01
   - Status: Separate batch16 build explicitly sets/queries16; five Pi5 checks pass, 799359 PCM bytes match source exactly. CTS1 and normal runtime binaries unchanged. Deployed in place at /test/jukebox/jukebox-async.bin after archiving CTS1 report/build on PCs. Author reports sustained clean playback with pre-existing sample-boundary pops; last run was not quit normally, so final stats/effective16 confirmation are unavailable. Installed firmware identity remains unconfirmed.

## Analyzer distribution

1. [ ] **AUD-002 — Ship a stock-transport analyzer build on skins**
   - Started: 2026-11-02
   - Status: Promote the accepted PCM analyzer without experimental UART APIs; qualify on stock firmware and prepare a lean source/executable/skins/config ZIP.

## Repository and releases

1. [ ] **REL-001 — Separate private development and public versioned releases**
   - Requested: 2026-11-02
   - Status: REL-001-S01 and S02 complete (2026-11-02). Pending development checkpoints committed/pushed; skins 01bce04 and Classic v0.11.0-beta pinned with byte-identical rebuilds. Next: REL-001-S03, sanitized publication trees. No repository migration authorized yet.

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

Immediate milestone: run the accepted Winamp-derived skin in the emulator.
The startup configuration reader is validated. The native skin
preview is visually accepted; target pixel and asset-loading checks pass. Next,
connect live player updates (SKIN-002/006) and validate playback (SKIN-007).
Classic, the chooser and complete authoring tools do not block this milestone.


1. [ ] **SKIN-001 — Resolve and document the v1 skin contracts**
   - Started: 2026-09-07 20:49 EDT
   - Finished: --
   - Status: In progress; printed bitmap characters and Winamp artwork import accepted. Import proof complete; layout, package and resource contracts remain to be finalized.
2. [ ] **SKIN-002 — Separate player state from rendering**
   - Started: --
   - Finished: --
3. [ ] **SKIN-003 — Implement configuration, discovery, and recovery chooser**
   - Started: --
   - Finished: --
4. [ ] **SKIN-004 — Load external assets and render the new skin**
   - Started: 2026-09-08 16:32 EDT
   - Finished: --
   - Status: First native render accepted; 4,424 sampled pixels match approved previews. Live integration is next.
5. [ ] **SKIN-005 — Build reproducible skin authoring and validation tools**
   - Started: --
   - Finished: --
6. [ ] **SKIN-006 — Design and build the rich reference skin**
   - Started: --
   - Finished: --
7. [ ] **SKIN-007 — Qualify skinning and establish resource limits**
   - Started: --
   - Finished: --
8. [ ] **SKIN-008 — Package and document the skin-enabled release**
   - Started: --
   - Finished: --
9. [ ] **SKIN-009 — Package and qualify Classic (deferred)**
   - Started: --
   - Finished: --
   - Status: Deferred until the new skin runs with live player state; retain familiar styling within the shared layout.

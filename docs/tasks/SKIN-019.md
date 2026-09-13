# SKIN-019 — Build and qualify the 70s skin

## Authorization and sequencing

2026-09-12: Author requests “make the skin and deploy an emulator with it”,
update tasks, then freeze everything before coding. This document and the full
SKIN-018 input/review/tool packet are the pre-code checkpoint. Implementation
starts only after its commit. No push. Runtime/emulator changes after that
checkpoint remain uncommitted until explicit human test and commit approval.

## Accepted implementation baseline

1. Original source: root that-70s-skin.png, unchanged 1448×1086 PNG.
2. Shape source: SKIN-018/state-text-02/clean-mask.png, accepted candidate 1
   with manually removed state text. Preserve static title/headings and controls.
3. Flat-color basis: SKIN-018/flat-color-04/candidate-3-consistent-families.png.
   Eight Agon64 colors; keep source-color families consistent. Author accepts
   warm dark red for brown and dislikes brown-to-green/olive substitution.
4. Retain arrow as separate sprite art and remove its baked instance in the
   runtime background. Current Art Deco sprite 0 tracks browser selection,
   not necessarily the playing file. Preserve that behavior. Hardware-sprite
   enablement and buffered visual-effects programs remain subsequent work.
5. Keep Art Deco source, output package, current binary and review profile.

## First playable scope

1. Create a reproducible 70s authoring builder and external skin package, using
   canonical AGNB functions and existing font assets/tools. Produce 512×384
   exact-Agon artwork and opaque dynamic widget states; no dithering/gradients.
2. Add a separate compile-time 70s application/test profile sharing the existing
   WAV player, browser, loader, keyboard scheduling and cleanup. General dynamic
   discovery/switching and a final skin ABI stay under SKIN-001/003/004.
3. Fit ten browser rows, live selection, track identity, elapsed/total time,
   progress, path/page/count and playback/mode/volume feedback into the artwork.
   Adapt font metrics and bounded fields as necessary. Reuse a legible existing
   playlist font; no new font design is required. Preserve static GUI labels
   where supported; no baked fake state. Cache row durations during existing
   directory validation if needed for the TIME column, avoiding redraw-time I/O.
4. Make minimal shared layout/data changes for the additional profile. Keep the
   hardware-accepted blocking input/timer/interrupt architecture unchanged.
   Preserve Base and Art Deco behavior, checking builds against 0a09cee where
   unchanged and running relevant regressions where shared behavior changes.
5. Prepare a new isolated profile under .emulator using the canonical generator,
   official installed Fab 1.2.4 and pinned MOS 3.0.2. Copy the new binary/config/
   external assets; map existing host music without modifying its content.
6. Launch its generated profile-local wrapper for Author visual/audio review.
   Also open a browser worksheet with source/compiled preview comparisons,
   fit/native/source zoom, actual palette swatches and review notes.

## Validation and completion

1. Deterministic asset rebuild, exact Agon palette, canonical AGNB record/payload
   validation, no state-text leftovers, sprite restoration/hiding/cleanup.
2. Assemble application and functional variants with Mac ez80asm 2.2; use short
   temporary paths. Verify memory bounds and bounded widget command sizes.
3. Exercise shared 26-scenario harness and newly generated widget/font pixel
   expectations on the stock emulator. Report host checks separately from real
   emulator results and human listening; preserve any failures/retries.
4. Keep checkpoint art and previous skin output intact; record deployment hashes
   and exact launch/profile identity. No hardware SD deployment or firmware edits.
5. Task stays open until Author review. After base acceptance, investigate a
   small gradient study on broad rails/rainbow bands; do not add effects now.

## Review delivery

Browser worksheets are the Author's preferred interface. Include numbered
candidates, original/mask comparisons, fit/512×384/100%/enlarged zoom, changed
pixels when relevant, and source-to-Agon color swatches. Open them for review.

## Implementation and review handoff — 2026-09-13

Pre-code freeze committed as 5e7abb5 before runtime edits. Implemented separate
app_seventies profile, canonical AGNB package, 6×12 Terminus playlist, cached
WAV durations, ten rows, count/path/status and existing selection sprite path.
Art Deco/base application and functional binaries compare byte-for-byte with
freeze baseline (baseline-build-check.json). No input/timer architecture change.

Validation: nine WAV checks and six assembly variants pass. All 19 generated
files reproduce exactly. Stock Fab/MOS run 70check03 passes 26 scenarios,
6,978 widget pixels and 6,922 font pixels; functional-pass.log preserved.
Earlier failures retained in .emulator/seventies-functional and 70check02:
corrected test frame coordinate and expected clipped path ellipsis. These were
expectation corrections, not runtime masking. The existing path field displays
the browser path buffer, clipped to 15 characters with ellipsis.

Graphical .emulator/seventies-review/jukebox launched via generated wrapper;
Cocoa startup reports SKIN_ASSETS_READY. deployment.json records PID, package
hashes and unchanged host music mapping. Browser index.html opened for review
with comparisons, zoom and actual palette. Preview is illustrative, not a native
screenshot. Human visual/audio acceptance remains pending. Runtime changes are
uncommitted/unpushed; no hardware deployment.

Remaining: Author review of this playable candidate; address feedback, then
explicit commit approval. After flat skin acceptance, SKIN-006 gradient study
on broad rails/bands. Hardware sprite/effects work remains deferred.

## Audio review follow-up — 2026-09-13

Author reports choppy audio; visual/functional tests do not establish listening
acceptance. Found agent-launched headless seventies-functional emulator PID414
left alive, using 77.4% CPU at inspection. Stopped this test process and launched
only the graphical seventies-review wrapper again, log review-audio-retry.log.
No application, asset or firmware change made for this retry. Audio reader,
playback loop and timer sources are unchanged; changed skin drawing workload
still requires consideration if choppiness persists. Host contention is a
plausible contributor, not a confirmed diagnosis. Prior graphical review log
ends in libc++ mutex error; timing/cause relative to window closure unknown.
Await isolated playback listening result before proposing runtime changes.

2026-09-13: Author confirms isolated 70s audio remains choppy. At explicit request, restored accepted Art Deco binary, config and full skin package directly from commit 0a09cee into main .emulator profile (eight files verified), launched generated wrapper. No other Fab process was running. Receipt .emulator/known-good-deployment.json; log known-good-review.log. 70s candidate remains unaccepted and preserved; await comparative listening result.

2026-09-13: Physical SD deployment completed: all eight runtime/launch files verified by staged and active readbacks; hashes in SKIN-019/hardware-deployment.json. Binary 52032 bytes SHA256 8ed30b1e62238f0f26770fcfc8f35eb74e53a3e1cb7b0f3abecaafd8d80016d0 at /mystuff/jukebox/jukebox.bin; config /bin/jukebox.cfg points to /mystuff/jukebox/seventies and existing /jukebox/tgt/music. Old /jukebox/tgt and /bin executables unchanged. Exited final sdserve, typed EXEC /mystuff/jukebox/play70.txt (finite LOAD/RUN batch), allowed startup, sent 0 (Albums), right (page2), 3 (Fleetwood Mac Rumours, sorted index13). Album header verified PCM mono8 48000Hz. Keyboard emission/release confirmed; actual screen/playback and audio quality await Author observation. No firmware/reset/startup edits; all source remains uncommitted.

## Prototype accepted — 2026-09-13

Author confirms 100% correct hardware execution, praises the skin, and explicitly
authorizes committing it as a good prototype. SKIN-019 complete; removed from
unfinished TODO. SKIN-006 retains gradients and wider reference-skin work.
At Author request, sent a single Escape press held 0.2 seconds and released it;
keyboard status confirms pending=0 held=0. Finite LOAD/RUN batch returns to MOS
on exit. No subsequent bench operations; control released for the other agent.
Acceptance evidence promoted to tests/seventies-evidence; original runtime and
music preserved. No push requested.

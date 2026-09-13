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

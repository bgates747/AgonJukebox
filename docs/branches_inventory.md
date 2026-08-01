# Branch inventory

This inventory was refreshed on 2026-08-01 from the live branch heads on the
`origin` remote and the local branches. Commit summaries are based on the
commit subjects and changed files. Counts relative to local `master` use
`git rev-list --left-right --count master...<branch>`.

## Overview

| Branch | Location | Head | Relative to `master` | Main line of work |
|---|---|---|---|---|
| `wavonly` | local, active | `a1bed2b` plus working tree | 0 behind, 0 committed unique | Uncommitted stock-VDP WAV-only candidate |
| `master` | local; remote at `0915ef8` | `a1bed2b` | reference branch; 1 ahead of remote | Current documentation/environment line before WAV-only reduction |
| `main` | local and remote | `bcb49da` | 20 behind, 0 unique | Jukebox audio controls and 16 kHz MIDI/audio work |
| `working_32` | remote only | `539f3b8` | 44 behind, 0 unique | Orchestral MIDI playback and memory-efficient sampled instruments |
| `agz` | remote only | `a8f1075` | 71 behind, 0 unique | Early AGM timing work followed by the first functioning MIDI player |
| `agm` | remote only | `39e800c` | 126 behind, 0 unique | AGM video pipeline and SZIP experiments |
| `alpha64` | remote only | `cd39a29` | 127 behind, 1 unique | Non-working 64-symbol SZIP experiment branched from AGM work |
| `dev` | remote only | `4f76371` | 186 behind, 0 unique | Jukebox v0.9.4/v0.9.5-era WAV conversion, UI, and seeking |

Except for `alpha64`, every historical remote head is an ancestor of local
`master`. They are therefore useful as named milestones, but contain no commits
absent from the current line. `alpha64` contains one explicitly unsuccessful
experiment that was not merged. `wavonly` has no committed divergence yet; its
candidate exists in the working tree.

## `wavonly`

Current active branch. It was created from local `master` at `a1bed2b` and has
no upstream branch. Its uncommitted working tree contains the WAV-only
stock-VDP reduction and rebuilt binary. Until that work is committed, the five
most recent commits are identical to `master` below.

## `master`

Current reference branch. Local `master` is at `a1bed2b`, one commit ahead of
`origin/master` at `0915ef8`. Its recent history records the recovered project,
canonical environment adoption, and media tooling.

1. `a1bed2b` (2026-08-01), **Use canonical agon-utils checkout** — removes the
   embedded dependency workflow and points setup, verification, and editor
   configuration at the canonical user-owned `agon-utils` checkout.
2. `0915ef8` (2026-08-01), **Record Agon environment and API review** — records
   the canonical development/emulator setup and the relevant stock MOS/VDP API
   findings.
3. `9fdc26b` (2026-08-01), **Document Jukebox branch and build archaeology** —
   inventories branches and records the deployed v0.9.6-beta binary's likely
   uncommitted Oryx provenance plus the WAV-only recovery recommendation.
4. `04ac655` (2026-08-01), **Update media build scripts** — adds a standalone
   YouTube-to-Agon WAV pipeline with optional trimming, compression,
   normalization, filtering, and resampling; clears old extracted frames before
   rebuilding AGM video; and changes the default AGM playback sample.
5. `e712219` (2026-07-25), **Add project-specific Codex handoff** — adds the
   repository entry point and AgonVideo-specific workflow handoff, delegating
   shared environment guidance to `agon-dev-env` and documenting the local
   virtual environment, pinned `agon-utils`, and technical references.

## `main`

Historical Jukebox integration head. It is fully contained in `master`; the 20
later commits on `master` continue from this exact head.

1. `bcb49da` (2025-05-31), **implement audio limiter vdu functions and app
   controls** — adds VDP sound limiter command support and corresponding player
   controls, tests, and rebuilt Jukebox binary.
2. `5d24caf` (2025-05-31), **Star Wars Theme with all samples at 16000 Hz** —
   replaces the published Star Wars MIDI sample archive with a 16 kHz version.
3. `5562200` (2025-05-31), **jukebox sets master audio sample rate...** — makes
   playback adopt each song/video sample rate, displays that rate, restores the
   user's volume after the global-rate command resets it, and gives signed
   decimal printing a private buffer. Parallel MIDI player code was updated too.
4. `1db69dd` (2025-05-31), **"make album" feature added to make_wav.py** — adds
   batch track preparation and concatenation into an album WAV, changes example
   download targets, moves orchestral sample generation toward 16 kHz, and
   expands the compression-curve comparison tool.
5. `359dbea` (2025-05-27), **add volume control to jukebox player** — introduces
   keyboard master-volume adjustment, stored volume state, a volume viewport and
   legend, and a refreshed v0.9.6-beta title screen.

## `working_32`

Late-stage orchestral MIDI branch, fully contained in `master`. The name likely
reflects the preceding 32 kHz work, while its last commit actively reduces
sample rates and lengths to save memory.

1. `539f3b8` (2025-05-16), **sample rates lower for low notes...** — generates
   variable-rate samples based on pitch, bounds sample length by actual
   instrument note durations, adds EOF handling for a clean return to MOS, and
   records a small hardware-only end-of-song glitch.
2. `2d35cbe` (2025-05-16), **more samples... instrument volume control ×
   velocity** — expands the orchestral sample set and combines per-instrument
   volume with MIDI velocity for more natural dynamics.
3. `76af860` (2025-05-16), **full orchestral star wars theme working** — reaches
   working orchestral playback of the Star Wars theme, reorganizes tunable
   sample assets, and adds/generated instrument definitions and player data.
4. `1bbdaa7` (2025-05-16), **lots and lots of new tunable samples...** — adds
   broad multi-instrument sampled-note sets and updates the player and sound
   includes to select and tune them.
5. `4ce4eb7` (2025-05-15), **progress save... before implementing tuneable loop
   samples with volume envelopes** — checkpoints SoundFont extraction,
   singleton/loop sample experiments, ADSR work, generated piano samples, and
   the MIDI assembly player before the tunable-loop implementation.

## `agz`

Bridge between AGM experiments and MIDI development, fully contained in
`master`. Its recent commits show the MIDI player becoming functional and then
absorbing reusable playback code from the main Jukebox.

1. `a8f1075` (2025-05-10), **play.inc and wav.inc to midi from main program** —
   imports the Jukebox WAV/playback includes into the MIDI area for reuse.
2. `59765fc` (2025-05-09), **synth piano samples from organ repository** — adds a
   large piano sample set and supporting arithmetic, debug, font, buffered VDU,
   plotting, and sound infrastructure while updating the MIDI application.
3. `0f613d1` (2025-05-09), **progress save on midi player** — advances MIDI
   conversion and generated event data, updates the MIDI assembly application,
   and produces a Moonlight Sonata player binary.
4. `ff09ca6` (2025-05-09), **midi player working** — introduces the initial
   functioning MIDI conversion pipeline, event tables, assembly player, timer,
   MOS/VDP support, and output binary.
5. `4ab4e0d` (2025-03-11), **tweaking timing of play samples vs draw frames...**
   — experiments with the scheduling balance between AGM frame drawing and
   sample playback, without finding a satisfactory improvement.

## `agm`

Historical AGM/SZIP development head, fully contained in `master`. The last
few commits preserve a working SZIP-based AGM path after unsuccessful image
compression experiments.

1. `39e800c` (2025-02-15), **restore szip to 256 alphabetsize** — restores the
   packaged SZIP build to a 256-symbol alphabet after the `alpha64` experiment.
2. `56e4467` (2025-02-15), **restore youtube_video to 320 px wide** — returns
   downloaded/staged video processing to the 320-pixel-wide target.
3. `cfea0d4` (2025-02-15), **abortive attempt at jpg grayscale compression** —
   adds experimental grayscale-JPEG generation and AGM playback paths, but the
   commit itself records that direction as unsuccessful.
4. `0126f2b` (2025-02-15), **working szip agm** — establishes a functioning AGM
   pipeline using SZIP across frame preparation, compression, playback, SZIP
   sources/binaries, and the assembly-side AGM format/decoder code.
5. `0f9477d` (2025-02-13), **restore szip code to original. gray png from rgba2
   script** — resets SZIP toward its original implementation and adds an
   RGBA2-to-grayscale PNG experiment, along with refreshed SZIP tools and a
   Jukebox binary.

## `alpha64`

One-commit experimental branch from the same parent used by `agm`. Its head is
the only live branch commit not present in `master`.

1. `cd39a29` (2025-02-15), **ALPHABETSIZE 64 experiment, non-working** — changes
   SZIP sources, build files, binaries, and archives to test a 64-symbol
   alphabet; explicitly documented as non-working.
2. `56e4467` (2025-02-15), **restore youtube_video to 320 px wide** — shared with
   `agm`; restores the 320-pixel video target.
3. `cfea0d4` (2025-02-15), **abortive attempt at jpg grayscale compression** —
   shared unsuccessful grayscale-JPEG experiment.
4. `0126f2b` (2025-02-15), **working szip agm** — shared working SZIP AGM
   milestone.
5. `0f9477d` (2025-02-13), **restore szip code to original. gray png from rgba2
   script** — shared SZIP reset and grayscale-PNG experiment.

## `dev`

Early Jukebox release-development head, fully contained in `master`. This line
was focused on WAV preparation, UI polish, and smoother seeking before the AGM
and MIDI branches developed further.

1. `4f76371` (2025-01-27), **update gitignore for agon-utils** — adjusts ignored
   paths for the utility workflow used at the time.
2. `89e1235` (2025-01-27), **Kensei-gan logo** — updates the source logo and
   converted RGBA2 asset, adds its editable XCF source, and rebuilds the player.
3. `a11cdf0` (2025-01-27), **tweek seek for smoother operation. bump version to
   9.5** — modifies input, layout, and playback assembly to smooth seeking and
   advances the displayed/release version.
4. `c896cc1` (2025-01-27), **make_wave.py preserves original codec...** — keeps
   the source codec through intermediate WAV-processing stages and skips
   resampling when the source already has the target rate.
5. `36a90f7` (2025-01-26), **update docs, screenshot and make_wav.py for
   v0.9.4-beta release** — prepares the v0.9.4-beta README, screenshot sources,
   and WAV conversion script for release.

## Likely work chronology

The branch heads suggest this progression:

1. `dev`: stabilize and release the WAV Jukebox.
2. `agm` / `alpha64`: explore AGM video encoding and SZIP compression, retaining
   the 256-symbol SZIP path and abandoning the 64-symbol variant.
3. `agz`: continue AGM timing work, then build a functioning MIDI player.
4. `working_32`: expand MIDI into sampled orchestral playback while reducing
   memory use.
5. `main`: integrate user-facing volume, sample-rate, and limiter controls.
6. `master`: recover the development environment and documentation, restore the
   AGM tools, document WAV streaming, and resume media-build work.

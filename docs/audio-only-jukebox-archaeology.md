# Audio-only Jukebox archaeology and recovery direction

## Purpose

This document reconstructs the provenance of the AgonJukebox build currently
used on physical hardware, records what source material survives, separates the
audio player from the later AGM video, MIDI, and experimental VDP limiter work,
and recommends a maintainable audio-only direction.

It is an archaeological and design record, not a claim that the historical
binary can be reproduced from the current repository. The source of that exact
binary is presently missing.

## Desired product boundary

The intended application is a WAV Jukebox for a stock Agon VDP. It should retain
the mature file browser and audio-player behavior while excluding:

- AGM video recognition, decoding, buffering, and playback;
- MIDI playback, instrument synthesis, and MIDI asset generation;
- experimental audio-output limiter selection and tuning commands that require
  a non-upstream VDP firmware modification; and
- production dependencies on video-only state, buffers, channels, or dispatch
  mechanisms.

The desired result is best described as a v0.9.6 audio-only Jukebox: the proven
v0.9.5 WAV feature set plus stock-firmware volume and sample-rate handling.

## Repository history

The full live-branch survey is in [branches_inventory.md](branches_inventory.md).
The history relevant to the audio-only recovery is:

1. Remote branch `dev`, head `4f76371` (2025-01-27), is the last branch head
   before AGM work began. Its last production source/binary change was
   `89e1235`; the later `dev` head only adjusted ignored utility paths.
2. Commit `bf3e34d` (2025-01-27), `initial agm commit`, begins AGM development
   immediately after the `dev` line.
3. AGM development repeatedly refactored shared WAV code from January through
   March 2025. Some of those refactors are useful independent of video, but the
   branch no longer represents a clean audio-only application.
4. Commit `359dbea` (2025-05-27) added user-facing master-volume control and the
   v0.9.6-beta UI.
5. Commit `5562200` (2025-05-31) added global sample-rate selection from the
   current media header, sample-rate display, and restoration of the user's
   volume after the global-rate command. It also included the first unfinished
   limiter routines and a signed-decimal helper; those parts are not required
   by the audio-only application.
6. Commit `bcb49da` (2025-05-31) added the experimental VDP audio-limiter
   commands and application controls. This is the head of remote `main` and is
   fully contained in `master`.
7. Current `master` continues 17 commits beyond `main`, mainly with environment
   setup, documentation recovery, AGM tool restoration, and later media-build
   script work. It does not contain later production assembly changes.

`master` was created in July 2026 with the new root commit `c0a09eb`, then
merged the pre-existing `agonjukebox/main` history at `a1030fc`. This explains
why both `main` and `master` exist: `main` preserves the old application head,
while `master` became the current documentation and recovery line.

## Surviving hardware binary

The binary currently used on the physical Agon is:

```text
/media/smith/AGON/jukebox/tgt/jukebox.bin
```

Observed identity:

| Property | Value |
|---|---|
| Size | 31,475 bytes |
| SHA-256 | `917994cee578754bfd31c9a0e0b885440880312d449694b54a6982f6954b4ee5` |
| Filesystem timestamp | 2025-06-01 14:47:44 EDT |
| Embedded version | `v0.9.6-beta` |

The timestamp is evidence of when the file was written to its current
filesystem, not definitive proof of compilation time.

The hardware binary was compared against every committed `tgt/jukebox.bin`
reachable from all seven live remote branches. No committed binary matches it.
The clone's unreachable Git blobs were also checked; none has the same hash or
contains the distinctive missing UI text.

The nearest committed binary is from `bcb49da`:

| Property | Value |
|---|---|
| Size | 31,095 bytes |
| SHA-256 | `29a87a9be1ab011f5559195d97289efc1ad9f4101d651224693fe8304a2863cd` |

At the time of the provenance comparison, assembling `bcb49da`'s source with
the installed `ez80asm` reproduced that committed 31,095-byte binary exactly.
The hardware artifact was therefore not a result of assembler-version drift or
nondeterministic output. The current `wavonly` source is intentionally smaller
and no longer reproduces this historical binary.

## Uncommitted Oryx Pro enhancements

The hardware binary is 380 bytes larger than the `bcb49da` binary and contains
UI strings absent from all committed production binaries and source revisions:

```text
Audio sample rate:
Audio limit method: Default
Log compress
Constant divisor
Active channels
[C]     [D] Divisor
[V]     [F] Makeup gain
[B]     [G] Curve shaping factor
```

The most strongly supported provenance is:

1. The source was based on or followed `bcb49da`, which introduced the limiter
   command implementations and keyboard controls.
2. Additional local work added a complete limiter status/settings UI.
3. That local tree was assembled and the resulting binary was copied to the SD
   card on or before 2025-06-01 14:47:44 EDT.
4. The additional source and binary were never committed or pushed.

The exact source cannot be reconstructed from the binary with confidence. The
binary nevertheless proves the behavior and provides a byte-for-byte oracle if
the historical working tree is recovered from the old development machine.

The relevant development machine is a 2018 System76 Oryx Pro, almost certainly
model `oryp4`, originally configured with a 512 GB NVMe SSD and a 2 TB 2.5-inch
SSHD. It now runs an unknown Linux Lite version and has recently shown hangs and
a kernel panic referring to a failed interrupt. Professional data recovery is
the chosen course. The missing limiter UI is not required for the planned
audio-only application, so recovery is valuable historical preservation rather
than a blocker for current development.

## SD-card source investigation

The hardware card contains an older source tree at:

```text
/media/smith/AGON/jukebox/src
```

That tree was copied to an isolated temporary directory and assembled because
the mounted SD source directory was not writable enough for `ez80asm` temporary
files. Its result was:

| Property | Value |
|---|---|
| Size | 29,576 bytes |
| SHA-256 | `501034115bfcafa15178729eddce3332eb71c141a78ea77639c6d294bba57e90` |
| Embedded version | `v0.9.5-beta` |

It does not match the running hardware binary and predates the May/June audio
enhancements. The card does not contain
`/media/smith/AGON/mystuff/AgonJukebox`, nor another immediately apparent
Jukebox checkout under `/mystuff`. A card-wide text search found no source,
listing, or backup containing the distinctive limiter UI strings.

## Proven audio-only baseline

Remote `agonjukebox/dev` at `4f76371` is the clean historical baseline. Its
v0.9.5-beta application already provides:

1. Fixed-format Agon WAV validation for 8-bit unsigned PCM mono input.
2. Directory browsing restricted to subdirectories and accepted WAV files.
3. Alphabetical listing, ten-entry paging, highlighted selection, arrow-key
   navigation, numeric selection, and parent-directory navigation.
4. Immediate random selection from the displayed page.
5. One-second audio buffering divided into 60 SD-card reads per second.
6. Two alternating VDP command/data buffer pairs so one sample plays while the
   next is filled.
7. Sample rate read from each WAV header and embedded in the create-sample
   commands.
8. Play/pause, loop, shuffle, automatic next-song, previous-song, next-song,
   and random-song policies.
9. Forward and backward seeking with selectable 1, 5, 10, 15, 30, 60, 120, and
   240-second increments and wraparound.
10. Current filename, duration, playhead, seek rate, loop state, and shuffle
    state display.
11. Timer and file shutdown followed by restoration of the screen state on
    return to MOS.

This baseline does not include the later volume UI or global sample-rate
restoration, but otherwise contains the user-facing core of the current WAV
player.

## Later changes to retain

### Master-volume control from `359dbea`

Retain the stock-VDP volume feature:

- `,` decreases and `.` increases a stored logical volume from 0 through 11;
- the logical value is scaled by 12 and sent as global VDP channel volume;
- the current value appears in the control legend; and
- the v0.9.6-beta title/UI layout is retained.

This feature is strictly audio playback and does not require custom firmware.

### Selected sample-rate work from `5562200`

Retain:

- displaying the selected WAV's sample rate;
- embedding the WAV rate explicitly in both VDP create-sample commands;
- applying the user's selected master volume on each song;
- the reusable `ps_adjust_volume` routine; and
- the private `printDec8` buffer, which avoids sharing mutable print storage.

Do not port the commit mechanically. Its channel-silencing loop depends on the
AGM symbol `pv_loaded_segments_max`, and its additions to `vdu_sound.inc`
introduce unfinished limiter commands. An audio-only implementation should stop
or silence only the two WAV channels it owns, if explicit silencing remains
necessary.

The `printDecS8` helper has no current production caller outside the lost
limiter-display direction and is not part of the required audio-only feature
set.

Interactive stock-emulator testing on 2026-08-01 corrected the original
recommendation to retain the global sample-rate command. After playing the
65,535 Hz test track first, subsequent 44,100 Hz and 48,000 Hz tracks shared
the same incorrect pitch behavior. Inspection of the upstream Console8
implementation showed that global value 65,535 is a sentinel for restoring the
16,384 Hz default, not a literal underlying output rate. The exact intermediate
rate was not measured, so the global command/reset interaction is the supported
cause rather than a claim that the system literally remained at 65,535 Hz. The
WAV command buffers already create every sample with its own explicit header
rate, making the global mutation redundant and harmful. The WAV-only
implementation therefore displays and embeds the rate per sample while leaving
the VDP's global audio-system rate alone. A corrected emulator run starting
with a non-65,535 Hz track produced the intended pitch, as confirmed by the
user.

## Changes to reject

### AGM video

Remove from the production application:

- the `agm.inc` include and AGM header definitions;
- AGM recognition and `verify_agm` dispatch from the WAV verifier;
- `ps_media_type`, `media_type_wav`, and `media_type_agm`;
- the `agm_play` branch;
- frame, segment, video-command, decompression, and prebuffer state;
- AGM-specific RAM regions and VDP buffers;
- video-oriented UI and diagnostics; and
- production dependencies on AGM test programs or generated media.

### Generic media dispatch introduced for AGM

Remove `read_media_routine` from the audio-only build. The timer interrupt can
call `ps_read_sample` directly, as it did before combined-media dispatch was
needed. This eliminates a function pointer and the associated `CALL_HL`
indirection without changing WAV behavior.

### Custom-firmware audio limiter

Reject all of `bcb49da`'s limiter feature and the unfinished limiter additions
from `5562200`:

- F1 through F5 limiter-method selection;
- `C`, `D`, `V`, `F`, `B`, and `G` limiter parameter controls;
- `vdu_audio_limit_*` state and constants;
- default, none, logarithmic, constant-divisor, and active-channel limiter
  command emitters;
- divisor, makeup-gain, and curve-shaping state; and
- limiter UI/status text.

These commands depended on experimental VDP firmware changes that were never
intended as a deliverable dependency and were not expected to be accepted
upstream. Retaining them would make the Jukebox falsely appear compatible with
stock firmware.

### MIDI

Do not import code or assets from the MIDI application, orchestral sample
branches, SoundFont tools, APR event player, or MIDI-specific rate/velocity
work. The WAV Jukebox has no runtime dependency on them.

## AGM-era WAV internals worth retaining

The recommended direction is not a literal reset to `dev`. Several shared-code
refactors made during AGM work are useful for a WAV-only implementation:

- separate browser-side and playback-side WAV open wrappers;
- closing the browser's temporary file after validation;
- preserving `IY` across browser validation;
- using one shared WAV-header validation implementation;
- retaining the mature command/data double-buffer implementation; and
- retaining current arithmetic/macro corrections that are independent of AGM.

These should be simplified back to WAV-only return semantics. A WAV validator
does not need to return media type 1 or 2, inspect an AGM format marker, or call
`verify_agm`.

Those shared internals have now been retained without retaining the AGM media
type. The separate WAV questions found during archaeology were resolved in the
2026-08-01 standard-reader pass: FatFS results and short reads are checked,
format fields are validated, `fmt ` and `data` are discovered dynamically, and
streaming is bounded by the declared `data` size. The resulting contract is in
`docs/wav-reader-reference.md`; the decision evidence is in
`docs/development-log.md`.

## 2026-08-01 implementation closure

The recovery recommendation produced commit `a6fc8bf`, the first stock-VDP
WAV-only rollback, followed by the pruned standard-WAV `v0.10.0-beta` release.
The current source keeps the mature browser, double buffering, playlist modes,
wrapped seeking, per-file rate, and volume. It removes AGM dispatch, MIDI,
experimental codecs, private-firmware output controls, and their build/test
trees.

The standard-input decision was deliberately broader than the historical
player. Existing test media produced by compliant tools begins at byte 78, and
current FFmpeg extensible PCM can begin at byte 102; neither should be rewritten
to the old byte-76 layout. The player now scans bounded RIFF chunks and accepts
both ordinary PCM and extensible PCM in its supported mono unsigned 8-bit
subset. Exact 60 Hz rate scheduling, declared-payload EOF handling, partial-tail
drain, dynamic-offset seeking, and safe return through the timer interrupt were
corrected at the same time.

The repository was then reduced from the proved compile and WAV-tool closures.
It removed 287 tracked paths and 93,755,362 bytes, including the complete MIDI,
AGM/video, and compression experiment trees. Git history and the branch names
in `docs/branches_inventory.md` remain the recovery mechanism for those files.
The missing Oryx source remains forensically interesting, but its known
uncommitted enhancements are not prerequisites for the desired audio-only,
stock-firmware product.

The static recovery objective is therefore complete. The standard-WAV candidate
also passed its complete stock-emulator gate: playback, browsing, volume,
pause/resume, multiple seek steps with forward and backward wraparound, EOF
progression, and final-to-first progression within the current directory slice.
The exact candidate also received baseline physical-hardware approval, with
better sound and fewer timer-related pops than the emulator. Extended long-form,
cross-rate, cleanup, and VDP-memory policy tests remain useful non-blocking
characterization recorded in `docs/development-log.md`.

## Original recommended implementation strategy

The following was the archaeology-driven recommendation. It is retained as the
rationale for the implemented `wavonly` direction rather than as a second
active work list.

| Recommendation | Disposition |
|---|---|
| Start from the current line rather than resetting literally to `dev`, preserving the mature browser, WAV player, timer, volume, rate, and arithmetic fixes. | Implemented in `wavonly`. |
| Remove AGM recognition, generic media dispatch, video state, limiter controls, and private-firmware commands. | Implemented in `a6fc8bf`; the remaining source/assets were pruned in the current candidate. |
| Keep MIDI outside the production application and build path. | Implemented; the tracked MIDI tree was removed. |
| Constrain normal cleanup to the two audio channels and four WAV buffers owned by the application. | Implemented provisionally; startup memory pressure remains a hardware policy decision. |
| Assemble reproducibly, compare behavior with known artifacts, and update the normative reference and log. | Build, documentation, stock-emulator qualification, and baseline physical-hardware approval are complete. |

This preserved later fixes while producing a smaller application with an
honest stock-firmware contract.

Final implementation review exposed a separate startup policy hidden by the
historical code: `ui_init` cleared every VDP buffer. The scoped candidate clears
only its WAV, font, and logo buffers, but the user confirmed that clear-all had
been intentional to reclaim VDP memory for this demanding application. Treat
the scoped variant as an explicit hardware experiment. Test it after populating
VDP memory with unrelated buffers; if allocation or sustained streaming fails,
retain intentional clear-all at startup and keep exit cleanup scoped. Optional
player modules merged later must inherit whichever base-player policy wins that
test.

## Acceptance criteria derived from the archaeology

The archaeology established that a replacement needs a reproducible build, no
production AGM/MIDI/limiter/private-command dependency, correct standard-WAV
browsing and playback, stable controls and volume, accurate cross-rate
transitions, continuous long-form playback, clean exit state, and a deliberate
VDP-memory policy. Static criteria are recorded as evidence in the development
log. Baseline emulator and physical-hardware acceptance are complete; extended
characterization remains recorded there rather than tracked in this historical
document.

The original recovery recommendation was to preserve the surviving hardware
binary in durable archival storage, identified by its SHA-256, before any
SD-card deployment replaced it.

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

Assembling current `src/asm/app.asm` with `ez80asm` reproduces that committed
31,095-byte binary exactly. The hardware artifact is therefore not a result of
assembler-version drift or nondeterministic output.

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
- setting the stock VDP global sample rate from the WAV header;
- restoring the user's selected master volume after the global sample-rate
  command resets it;
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

The current WAV reference also records validation questions that remain
separate from removing AGM: unchecked `FRESULT` values, incomplete header-read
handling, limited header-field validation, and EOF inferred from a zero-byte
read rather than `data_size`. Those questions remain owned by `docs/TODO.md`.

## Recommended implementation strategy

Use current `master` as the source and documentation baseline rather than
resetting the branch to `dev`. Perform a deliberate audio-only reduction:

1. Preserve the current WAV reader, browser, player, timer, buffer, volume, and
   sample-rate behavior.
2. Remove AGM recognition and playback while simplifying the shared interfaces
   back to WAV-only contracts.
3. Remove every limiter control, state variable, command emitter, and UI
   reference.
4. Remove the generic media function pointer and directly invoke the WAV reader
   from the timer interrupt.
5. Remove production dependence on video channel counts; constrain cleanup to
   the two audio channels and four VDP buffers owned by the WAV player.
6. Keep MIDI outside the production application and build path.
7. Assemble and compare behavior against the known v0.9.5 and v0.9.6 artifacts,
   using physical hardware as the functional and timing authority.
8. Update the normative WAV reference and development log after the reduced
   build is tested and accepted.

This approach preserves later fixes and current documentation while producing
a smaller application with an honest stock-firmware contract.

## Validation criteria for the future reduction

The eventual implementation should demonstrate all of the following before it
replaces the current hardware binary:

1. It assembles reproducibly with the repository's documented `ez80asm` setup.
2. No production symbol or include refers to AGM, MIDI, limiter methods, or
   custom VDP commands.
3. Directory browsing accepts the supported WAV contract and rejects unrelated
   files.
4. Long-form WAV playback remains continuous on physical hardware.
5. Play/pause, loop, shuffle, random selection, automatic progression, and
   seeking behave as documented.
6. Volume persists across song changes.
7. Files with different supported sample rates play correctly and report the
   selected rate.
8. Exiting restores the screen, timer, interrupt, file, audio, and VDP state
   sufficiently that a subsequent stock application exits cleanly.
9. The result is tested on physical hardware before being treated as the new
   production binary.

The surviving hardware binary should be copied to durable archival storage and
identified by its SHA-256 before any SD-card deployment replaces it.

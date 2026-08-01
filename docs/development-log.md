# Development log

This is the active running record for AgonJukebox. It captures work performed,
important discoveries, decisions, unresolved issues, and the most useful next
steps. Earlier entries are archived in `docs/development-log-20260718.md`.

## Current status

Last updated: 2026-08-01

- `uv` 0.11.29 and `uvx` are installed persistently in `~/.local/bin`.
- POSIX login-shell and interactive Bash startup resolve the persistent `uv`
  binary without referencing `/tmp/agonvideo-uv`.
- The project consumes the canonical editable `agonutils` checkout at
  `/home/smith/Agon/mystuff/agon-utils`; the former embedded-submodule workflow
  is retired.
- Branch `wavonly` contains an assembled WAV-only candidate for stock VDP
  firmware. A non-65,535 Hz cold-start pitch check and the interactive control
  matrix passed in the emulator. In-session cross-rate transitions and the
  physical-hardware gates remain pending.

## 2026-08-01 — WAV-only stock-VDP candidate synthesized

Implemented the deliberate reduction specified in
`docs/audio-only-jukebox-archaeology.md` without resetting to the historical
`dev` branch. The candidate retains the mature browser, prefix WAV validation,
fixed-offset streaming, 60 Hz double buffering, playlist modes, seeking,
sample-rate display/selection, and persistent user volume.

The candidate include graph no longer includes or dispatches to AGM. WAV header
offsets and current buffer pointers are WAV-owned, and the timer calls
`ps_read_sample` directly. Removed all custom-firmware limiter keys, state,
command emitters, and the unused signed 8-bit print helper. Song transitions
and exit now reset only stock channels 0 and 1; exit clears only WAV buffers
`0x3000` through `0x3003`.

The first interactive emulator pass exposed a rate-transition regression in
the retained global sample-rate command: after Africa was selected first, the
44,100 Hz and 48,000 Hz files shared the same incorrect pitch behavior. Source
inspection then showed that Console8 treats global value 65,535 as a sentinel
that restores its 16,384 Hz default, not as a literal output rate. The exact
intermediate rate was not measured; the global command/reset interaction is
the supported cause of the observed transition failure. The mutation was
removed. Each command buffer already creates its VDP sample with the WAV
header's explicit rate, so playback now relies exclusively on that per-buffer
contract while continuing to display the rate and apply stored volume.
The corrected candidate was relaunched with a non-65,535 Hz track first, and
the user confirmed the intended pitch. In a subsequent emulator session, the
user exercised the playback controls and reported that everything behaved
correctly. This closes the general emulator control gate. Because the corrected
run did not explicitly record an in-session transition among the 65,535,
44,100, and 48,000 Hz fixtures, that transition matrix remains an explicit
hardware check rather than being inferred from the cold-start pitch result.

Final review found that `ui_init` still issued the historical clear-all VDP
buffer command. It has been replaced in this candidate with explicit cleanup
of the four WAV buffers, the jukebox font buffer, and the logo buffer; exit is
likewise scoped to resources the application owns. The user clarified that the
old clear-all was intentional resource reclamation because the player puts
substantial pressure on VDP memory. The scoped policy is therefore not blessed
by emulator success alone. Hardware must launch the player from a deliberately
nonempty VDP-buffer state and sustain Africa at 65,535 Hz for the
allocation-pressure check. The Lynyrd Skynyrd album is a separate long-form
continuity test. If allocation, UI, or streaming fails under pressure, restore
clear-all at startup while retaining scoped cleanup on exit. This base-player
decision must also be inherited by any optional modules later merged back into
the player. The authoritative gates are `PLAY-001` through `PLAY-003` and
`VDP-001` in `docs/TODO.md`.

`ez80asm` 2.1 produced a 28,889-byte `tgt/jukebox.bin` with SHA-256
`efa3e80837ae37e6a10e79a3a1e595477c1d00f72a12018de88106ad6ba35949`.
An isolated second assembly was byte-identical. The generated candidate
symbol table and binary strings contain no AGM, MIDI, limiter, media-dispatch,
or signed-print symbols. `src/asm/app.lst` was regenerated from the reduced
source.

The ignored stock-emulator test set currently contains:

| File | Rate | Duration | PCM payload offset |
|---|---:|---:|---:|
| `Africa_65535.wav` | 65,535 Hz | 4:55.94 | 78 bytes |
| `Lynyrd_Skynyrd__Gold_and_Platinum.wav` | 44,100 Hz | 1:37:42.76 | 78 bytes |
| `Rhiannon.wav` | 48,000 Hz | 4:12.77 | 78 bytes |
| `Wild_Flower.wav` | 48,000 Hz | 3:39.25 | 78 bytes |

All are 8-bit unsigned PCM mono, and packet/header inspection places every PCM
payload at byte 78. They expose the known fixed-header limitation: the current
reader assumes byte 76 and therefore begins playback with the final two bytes
of the `data` size field. Parser hardening remains a separate TODO rather than
part of this archaeology-driven reduction. The candidate is intentionally
uncommitted pending the cross-rate, long-form, state-restoration, and VDP-memory
pressure checks on physical hardware.

## 2026-08-01 — Canonical agon-utils workflow adopted

The canonical cross-project instructions superseded AgonJukebox's older pinned
`external/agon-utils` submodule workflow. Removed the submodule and its Git
configuration. Updated the Python bootstrap, setup guide, project handoff,
Pylance path, and remaining utility paths to use the user-owned canonical
checkout at `/home/smith/Agon/mystuff/agon-utils`.

Environment verification now rejects an `agonutils` import that resolves
outside the canonical checkout. Historical entries below retain the old
submodule work as provenance; they are no longer current instructions.

## 2026-07-20 — Development environment startup

### Non-persistent `uv` installation discovered

Shell startup failed with:

```text
/bin/sh: 29: cannot open /tmp/agonvideo-uv/env: No such file
```

The `uv` installation had been placed under `/tmp/agonvideo-uv`, and startup
configuration attempted to source environment files from that location. Since
`/tmp` is ephemeral, the referenced file did not survive, leaving persistent
shell configuration pointing at a missing temporary file.

Affected configuration was found in:

- `~/.profile`, which sourced `/tmp/agonvideo-uv/env`;
- `~/.bashrc`, which sourced `/tmp/agonvideo-uv/env`;
- `~/.config/fish/conf.d/uv.env.fish`, which sourced
  `/tmp/agonvideo-uv/env.fish`; and
- `~/.config/uv/uv-receipt.json`, which still records
  `/tmp/agonvideo-uv` as the installation prefix.

The user initially restored shell startup by commenting out the three
shell-source lines. The durable remediation then installed the same `uv`
version, 0.11.29, into `~/.local/bin`. Its receipt now records
`/home/smith/.local/bin` as the installation prefix rather than the temporary
directory.

Startup configuration now uses the persistent location directly:

- `~/.profile` retains its existing conditional addition of `~/.local/bin`;
- `~/.bashrc` exports `~/.local/bin` onto `PATH`; and
- `~/.config/fish/conf.d/uv.env.fish` calls `fish_add_path` for
  `~/.local/bin`.

No startup configuration references `/tmp/agonvideo-uv` anymore. Clean POSIX
login-shell and interactive Bash checks both resolved `uv` to
`/home/smith/.local/bin/uv` and reported version 0.11.29. Fish is not installed
on this system, so its startup file could not be exercised with the Fish
interpreter; the configuration uses Fish's standard `fish_add_path` builtin.

### Immediate next actions

1. Restart the user's normal session and confirm startup is clean.
2. If Fish will be used, validate its startup configuration after Fish is
   installed or on the target system where it is available.

### Pylance `agonutils` import resolution

VS Code continued to report that `agonutils` could not be resolved in
`build/scripts/agm_make.py` and other importers even though those scripts ran
successfully under the project virtual environment.

The discrepancy was traced to the editable installation mechanism. The
project's `.venv` contains a generated `__editable__` import finder that maps
`agonutils` to the native extension built at
`external/agon-utils/agonutils.cpython-314-x86_64-linux-gnu.so`. Python executes
that finder at runtime, while Pylance's static module discovery does not rely on
the runtime import hook.

Added `${workspaceFolder}/external/agon-utils` to
`python.analysis.extraPaths` in `.vscode/settings.json`. This exposes the
extension module's real directory to Pylance without changing Python's working
editable installation.

### Reusable Agon platform overview

Created a root-level `project-overview.md` containing only the general Agon
platform facts from `docs/project-overview.md` that are relevant across assembly
projects. It records the eZ80/ESP32-PICO-D4 architecture, the high-speed UART
link, the VDP's display, audio, and keyboard responsibilities, and stock frame
swapping. AgonVideo-specific application, media, codec, Python, and `agonutils`
details were deliberately excluded.

## 2026-07-22 — Official documentation and AGNB loading review

Reviewed the official documentation checkout at
`/home/smith/Agon/agon-docs` commit `f9806bd` and cross-referenced its MOS,
FatFS, VDU, buffered-command, bitmap, audio, memory, and timing contracts
against the production and test assembly in `src/asm`.

Created `docs/agon-assembly-and-agnb-precis.md`. It documents the working
eZ80-to-VDP data path, identifies existing routines suitable for reuse, and
maps the draft RIFF-based AGNB structures to a bounded single-pass assembly
reader.

Important implementation findings include:

- AGNB can reuse the existing MOS/FatFS read and buffered VDP upload patterns,
  but needs strict 32-bit RIFF/list/chunk boundary accounting and short-read
  checks.
- Repeated buffered writes append blocks; image records must be consolidated
  before bitmap creation, while audio samples may remain multi-block.
- Asset preload block size and the measured 1/60-second real-time UART budget
  are separate constraints.
- Initial AGNB parsing and loading should run outside the peripheral-timer
  interrupt; future real-time work should keep interrupt operations bounded.
- The 2023 local `mos_api.inc` is not a complete current MOS 3 definition and
  should be extended deliberately if newer APIs are adopted.
- Official documentation specifies `RST.LIS` for MOS handlers while the working
  project consistently uses `RST.LIL`; this requires a targeted assembler and
  firmware compatibility check before any suffix changes.

Added the précis to the documentation index. No assembly behavior was changed
as part of this review.

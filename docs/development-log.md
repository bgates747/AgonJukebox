# Development log

This is the active running record for AgonVideo. It captures work performed,
important discoveries, decisions, unresolved issues, and the most useful next
steps. Earlier entries are archived in `docs/development-log-20260718.md`.

## Current status

Last updated: 2026-07-22

- `uv` 0.11.29 and `uvx` are installed persistently in `~/.local/bin`.
- POSIX login-shell and interactive Bash startup resolve the persistent `uv`
  binary without referencing `/tmp/agonvideo-uv`.
- VS Code/Pylance can resolve the editable native `agonutils` module through an
  explicit analysis path.

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

# AgonVideo Project Handoff

Read `/home/smith/Agon/mystuff/agon-dev-env/codex/AGENTS.md` first. This file
contains only AgonVideo-specific guidance.

## Project

AgonVideo contains AgonJukebox, an eZ80 WAV player, and experimental video
codec/playback work. Start with `docs/project-overview.md`,
`docs/development-log.md`, and the task-relevant technical reference.

The current working tree may contain active application experiments. Inspect
status before every edit or commit and never stage unrelated assembly, Python,
media, editor, or generated changes.

## Python and agon-utils

Use `.venv/bin/python` explicitly. The supported bootstrap is:

```bash
python3.14 scripts/setup_python.py
```

AgonVideo embeds `external/agon-utils` as a pinned Git submodule. Treat it as
read-only during ordinary application work. Deliberate utility changes require
a branch and commit inside the submodule first, followed by a separate parent
commit updating the submodule pointer. See `docs/development-setup.md`.

Verify the application environment with:

```bash
.venv/bin/python scripts/verify_environment.py
```

## Technical references

- `docs/agonvideo-wav-reader-reference.md` maps the production WAV path.
- `docs/codec-and-throughput.md` records transport limits and codec work.
- `docs/agon-assembly-and-agnb-precis.md` maps official MOS/VDP contracts to
  this application's routines.
- `docs/TODO.md` contains current actionable WAV-reader work.

AgonJukebox may leave the VDP in a state that causes a later application to
Guru Meditate on exit. Wolf3D exits cleanly after a fresh boot; investigate
this as an AgonVideo/Jukebox state-restoration issue.

Machine environment scripts and emulator profiles belong in
`/home/smith/Agon/mystuff/agon-dev-env`, not in this repository.

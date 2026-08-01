# AgonJukebox Project Handoff

Read `/home/smith/Agon/mystuff/agon-dev-env/codex/AGENTS.md` first. This file
contains only AgonJukebox-specific guidance.

## Project

AgonJukebox is an eZ80 WAV player for stock upstream VDP firmware. Historical
AGM, video-codec, and MIDI work is retained outside the WAV-only candidate
include graph. Start with `docs/project-overview.md`,
`docs/development-log.md`, and the task-relevant technical reference.

The current working tree may contain active application experiments. Inspect
status before every edit or commit and never stage unrelated assembly, Python,
media, editor, or generated changes.

## Python and agon-utils

Use `.venv/bin/python` explicitly. The supported bootstrap is:

```bash
python3.14 scripts/setup_python.py
```

Install the canonical user-owned `agon-utils` checkout from
`/home/smith/Agon/mystuff/agon-utils` in editable mode. Do not create an
application-local copy or submodule. Deliberate utility changes belong in the
canonical repository on their own branch and commit. See
`docs/development-setup.md`.

Verify the application environment with:

```bash
.venv/bin/python scripts/verify_environment.py
```

## Technical references

- `docs/agonvideo-wav-reader-reference.md` maps the candidate WAV path.
- `docs/codec-and-throughput.md` records transport limits and codec work.
- `docs/audio-only-jukebox-archaeology.md` records the recovery rationale and
  intended product boundary.
- `docs/agon-assembly-and-agnb-precis.md` is a historical video-container
  reference, not the current implementation direction.
- `docs/TODO.md` is the authoritative list of current reader work and candidate
  acceptance gates.

The WAV-only candidate resets channels 0 and 1 and clears its four audio
buffers on exit. Its scoped startup clear is an unblessed alternative to the
historical intentional clear-all. Do not treat the candidate as accepted until
the physical gates `PLAY-001` through `PLAY-003` and `VDP-001` in
`docs/TODO.md` are resolved.

Machine environment scripts and emulator profiles belong in
`/home/smith/Agon/mystuff/agon-dev-env`, not in this repository.

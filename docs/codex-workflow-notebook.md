# AgonJukebox project handoff

Read `/home/smith/Agon/mystuff/agon-dev-env/codex/AGENTS.md` first. This file
contains only AgonJukebox-specific guidance.

## Product boundary

AgonJukebox is an eZ80 WAV player for standard upstream Console8 VDP firmware.
The production tree is deliberately limited to WAV playback; AGM video, MIDI,
experimental codecs, and private-firmware output controls are not part of this
branch.

Start with `docs/project-overview.md`, `docs/development-log.md`, and the
task-relevant section of `docs/wav-reader-reference.md`. Historical recovery
context lives in `docs/audio-only-jukebox-archaeology.md` and
`docs/branches_inventory.md`.

## Build and Python checks

Use `.venv/bin/python` explicitly. The project has no `agonutils` dependency.
The supported bootstrap and verification commands are:

```bash
python3 scripts/setup_python.py
.venv/bin/python scripts/verify_environment.py
```

The native requirements are `ez80asm`, `ffmpeg`, and `ffprobe`. Assemble from
`src/asm` without `-l` for routine checks; listing files are generated output
and are ignored:

```bash
cd src/asm
ez80asm app.asm ../../tgt/jukebox.bin
```

Qualification evidence and non-blocking follow-up characterization belong in
`docs/development-log.md`.

## Emulator and hardware gates

The isolated Fab Agon profile is owned by the canonical environment repository
at `/home/smith/Agon/mystuff/agon-dev-env/emulators/jukebox`. Do not add the
emulator, its SD tree, or test media to this repository.

Any candidate binary or emulator-profile change remains uncommitted and
unpushed until the user explicitly validates it. Record emulator and hardware
results in `docs/development-log.md` before promotion.

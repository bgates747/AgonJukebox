# Development setup

## Prerequisites

The production build and WAV toolchain require:

- Python 3.10 or newer;
- `ez80asm`;
- `ffmpeg`; and
- `ffprobe`.

URL downloads additionally use the pinned `yt-dlp` Python package. The project
does not use `agonutils`, native Python extensions, FFmpeg development headers,
or image/video libraries.

Check native programs without changing the system:

```bash
python3 scripts/check_native_deps.py
```

## Project environment

Create or refresh the ignored project-local environment with:

```bash
python3 scripts/setup_python.py
```

The script creates `.venv`, installs its pinned `yt-dlp` dependency, runs the
WAV tests, and assembles a temporary binary. Thereafter use the selected
interpreter explicitly:

```bash
.venv/bin/python scripts/verify_environment.py
```

VS Code-compatible editors select the same interpreter through the tracked
`.vscode/settings.json`.

## Assemble

From the repository root:

```bash
cd src/asm
ez80asm app.asm ../../tgt/jukebox.bin
```

Do not use `-l` for routine builds. Assembly listings are generated artifacts
and `src/asm/*.lst` is ignored.

## Prepare WAV files

Show the complete converter interface with:

```bash
.venv/bin/python scripts/make_wav.py --help
```

Examples:

```bash
.venv/bin/python scripts/make_wav.py song.flac -o tgt/audio/song.wav
.venv/bin/python scripts/make_wav.py album/ -o tgt/audio/
.venv/bin/python scripts/make_wav.py album/ --album tgt/audio/album.wav
.venv/bin/python scripts/make_wav.py URL -o tgt/audio/track.wav
```

The converter emits ordinary FFmpeg RIFF/WAVE output. It controls the audio
encoding—mono unsigned 8-bit PCM and a rate no greater than 65,535 Hz—but does
not manufacture a fixed metadata layout or payload offset.

## Emulator

The isolated Fab Agon instance and copyrighted test media live outside this
repository at
`/home/smith/Agon/mystuff/agon-dev-env/emulators/jukebox`. Follow the canonical
environment documentation for launching and updating that profile. Emulator
changes and candidate binaries require explicit human validation before any
related repository work is committed or pushed.

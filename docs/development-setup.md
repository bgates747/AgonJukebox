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

The checked-in assembly inputs include the qualified UI command packets and
an unchanged, pinned copy of the canonical AGNB API in `vendor/agnb`. No private
task directory, image converter, emulator or sibling checkout is needed to
build. `src/ui/README.md` describes the UI inputs. The configuration, AGNB
container and loose fonts remain external runtime files.

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

For emulator testing, copy `tgt/jukebox.bin` to the virtual SD card's `bin`
directory, `config/jukebox.cfg` to `bin/jukebox.cfg`, and the contents of
`skins/base` to `jukebox/skins/base`. Put compatible WAV files in a `music`
directory on that card, or edit `music_dir` in the configuration.
To start the player there automatically, use these lines in `autoexec.txt`
with CRLF line endings:

```text
SET KEYBOARD 1
cd /music
jukebox
```

Keep local emulator runtimes, virtual SD cards and media in the ignored
`.emulator/` directory. Build and media conversion do not require a local
emulator or any sibling repository.

Use MOS 3.0.2 Arthur and VDP 2.16.0 Bistromathics for the qualified skin build.
Override the MOS shipped with an emulator when necessary. The public
[functional test suite](../tests/README.md) uses the same application with
scripted target-side checks and a separate generated SD tree.

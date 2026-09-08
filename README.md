# AgonJukebox

AgonJukebox is a WAV music player written in eZ80 assembly for the Agon Light
family. It streams audio from the SD card into alternating VDP buffers while
providing a paged file browser, seeking, playlists, and volume control. This
WAV-only branch runs on the standard upstream Console8 VDP firmware; it does
not require private firmware commands.

## Supported WAV files

The player accepts standard RIFF/WAVE files with:

- one channel (mono);
- unsigned 8-bit integer PCM;
- a sample rate from 1 through 65,535 Hz; and
- either legacy `WAVE_FORMAT_PCM` or `WAVE_FORMAT_EXTENSIBLE` with the PCM
  subtype and eight valid bits.

The reader walks the RIFF chunk sequence, checks container and chunk bounds,
and honors the pad byte after every odd-sized chunk. A supported `fmt ` chunk
must precede the first `data` chunk. Other chunks—such as `LIST`, `JUNK`,
`bext`, or `fact`—may occur before, between, or after them; the player locates
the PCM payload dynamically and streams only its declared length.

## Install or build

The current skin-enabled build is [tgt/jukebox.bin](tgt/jukebox.bin). Install
these files on the SD card:

| Repository file/directory | SD card location |
| --- | --- |
| `tgt/jukebox.bin` | `/bin/jukebox.bin` |
| `config/jukebox.cfg` | `/bin/jukebox.cfg` |
| Contents of `skins/base/` | `/jukebox/skins/base/` |

Edit `/bin/jukebox.cfg` to select the skin and initial music directories, then
run `jukebox` from MOS. The example uses `/music`; create that directory or
change the setting to an existing directory. Graphics load from an AGNB
container; fonts are separate `.font` files. No command-line arguments are
required. See [configuration and skin loading](docs/configuration.md).

This functional milestone was tested with MOS **3.0.2 Arthur**, VDP **2.16.0
Bistromathics**, and Fab **1.2.4**. The package schema remains provisional;
skin discovery, switching, and Classic styling are still under development.

To assemble it, install `ez80asm`, then run:

```bash
cd src/asm
ez80asm app.asm ../../tgt/jukebox.bin
```

## Controls

| Key | Action |
|---|---|
| Up / Down | Move the highlighted entry |
| Left / Right | Previous / next directory page |
| `U` | Move to the parent directory |
| Enter | Open the highlighted directory or play the highlighted WAV |
| `0`–`9` | Open or play the corresponding entry on the current page |
| `R` | Play a random WAV from the current page |
| `P` | Pause or resume playback |
| `L` | Toggle loop mode |
| `S` | Toggle shuffle mode |
| `[` / `]` | Seek backward / forward by the displayed seek interval |
| `-` / `=` | Decrease / increase the seek interval |
| `,` / `.` | Decrease / increase master volume |
| Esc or `Q` | Quit to MOS |

Seek intervals cycle through 1, 5, 10, 15, 30, 60, 120, and 240 seconds.
Seeking wraps within the current track. With loop and shuffle disabled,
playback advances through the current directory page automatically, skipping
directory entries and wrapping from the last playable WAV to the first. The
selected volume persists across song changes.

## Prepare compatible WAV files

The sole media-preparation tool is
[scripts/make_wav.py](scripts/make_wav.py). It requires Python
3.10 or newer plus `ffmpeg` and `ffprobe`; URL input additionally uses the
pinned `yt-dlp` package. Set up the local environment and inspect the complete
interface with:

```bash
python3 scripts/setup_python.py
.venv/bin/python scripts/make_wav.py --help
```

Examples:

```bash
# Convert one local file.
.venv/bin/python scripts/make_wav.py song.flac -o tgt/audio/song.wav

# Convert every supported file immediately inside a directory.
.venv/bin/python scripts/make_wav.py album/ -o tgt/audio/

# Convert and concatenate a directory into one album-length WAV.
.venv/bin/python scripts/make_wav.py album/ --album tgt/audio/album.wav

# Download one URL and convert its best available audio stream.
.venv/bin/python scripts/make_wav.py "https://www.youtube.com/watch?v=VIDEO_ID" -o tgt/audio/track.wav
```

The command accepts one or more local files or directories, or one HTTP(S)
URL. Its options are:

| Option | Purpose |
|---|---|
| `-o`, `--output` | Output file or directory; defaults to `tgt/audio` |
| `--album OUTPUT_WAV` | Concatenate expanded local sources into one WAV |
| `--sample-rate RATE` | Select 1–65,535 Hz; `-1` preserves the source rate |
| `--trim-start TIME` | Begin at an FFmpeg-compatible time offset |
| `--trim-duration SECONDS` | Limit output duration |
| `--compress` | Apply dynamic-range compression |
| `--normalize`, `--no-normalize` | Enable or disable loudness normalization; enabled by default |
| `--extra-af FILTERS` | Append an FFmpeg audio-filter chain |
| `--keep-temp` | Retain intermediate files for inspection |

Every result is converted to mono `pcm_u8` and validated against the same WAV
contract used by the application before it is installed at the destination.

## Documentation

- [Project overview](docs/project-overview.md)
- [WAV reader and streaming reference](docs/wav-reader-reference.md)
- [Development setup](docs/development-setup.md)
- [Configuration and skin loading](docs/configuration.md)
- [Functional test milestone](tests/README.md)

## License

AgonJukebox is released into the public domain under the
[UNLICENSE](LICENSE). Imported artwork retains its original provenance;
see [the reference skin notes](skins/base/README.md). The vendored AGNB API
retains its [upstream license](vendor/agnb/LICENSE).

## Acknowledgements

- Steve Sims and the Console8 contributors for the Agon VDP and MOS firmware.
- Jeroen Venema for `ez80asm` and its Agon-compatible assembly examples.
- Tom Morton for `fab-agon-emulator` and the peripheral-timer interrupt example
  at the heart of the streaming loop.
- Richard Turnnidge for Agon assembly tutorials and example programs.
- Shawn Sijnstra for the 24-bit arithmetic routines, and `@calc84maniac` for
  sorting and mathematics optimizations.
- Dean Belfield for the Agon BBC BASIC ADL floating-point library on which the
  large-file seek calculations are based.
- `@Triplefox`, `@rafd_electrotux`, and the wider Agon community for audio
  guidance, testing, and feedback.

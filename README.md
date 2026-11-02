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

The default [tgt/jukebox.bin](tgt/jukebox.bin) is the runtime skin player with
an optional PCM analyzer. It uses standard MOS output only; no experimental
UART transport or private firmware is required.

Install `tgt/jukebox.bin` as `/bin/jukebox.bin`, `config/jukebox.cfg` as
`/bin/jukebox.cfg`, and the four directories under `skins/runtime/` as
`/jukebox/skins/`. The example config selects Nineties and `/music`; edit it
for your existing paths. Run `jukebox` from MOS. The K chooser changes skins.
Nineties opts into measured PCM bars through `spectrum.bin` and `spectrum.agnb`.

Build with `sh scripts/build_player.sh`, or assemble `src/asm/app.asm` to
`tgt/jukebox.bin` using ez80asm. All assembler dependencies are vendored/generated;
image or font authoring tools are not needed to build the player. The old static
Art Deco entry remains `src/asm/app_artdeco.asm`; other static profiles remain.

Generate a lean source/player/skin distribution with:

```bash
python3 scripts/package_player.py
```

The ZIP excludes repository history, private working notes, source artwork,
test captures and unused skin previews. See [PCM analyzer](docs/pcm-spectrum.md).
**Visualization design credit: Pollito / SanPollo — Nick J. Date, agonAMP**, for
paced incremental drawing, desired/displayed state and falling bars. Copyright
and upstream license are retained in `vendor/agonamp-visualization/LICENSE`.

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
| `K` | Choose a runtime skin |
| `V` | Toggle analyzer when supported by the skin |
| `L` | Toggle loop mode |
| `S` | Toggle shuffle mode |
| `[` / `]` | Seek backward / forward by the current seek interval |
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

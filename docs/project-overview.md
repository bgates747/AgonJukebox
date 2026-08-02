# Project overview

## Platform and product

AgonJukebox is an eZ80 assembly application for the Agon Light family. It
streams audio from the SD card to the ESP32-based VDP and requires only standard
upstream Console8 firmware.

The product boundary is intentionally narrow: filesystem browsing and WAV
playback. AGM video, MIDI synthesis/playback, compression experiments, and
commands tied to private VDP firmware are not part of the application or its
toolchain.

## Established functionality

- filtered, sorted directory browsing with ten-entry pages;
- two alternating VDP audio buffers filled over 60 timer ticks per second;
- play/pause, loop, shuffle, random selection, and automatic progression;
- wrapped forward/backward seeking at selectable 1–240 second increments;
- filename, duration, elapsed time, sample rate, mode, seek, and volume display;
- per-file sample rates from 1 through 65,535 Hz; and
- persistent logical master volume across song changes.

## WAV contract

The reader accepts standard RIFF/WAVE files whose audio is mono, unsigned
8-bit integer PCM. Both legacy `WAVE_FORMAT_PCM` and
`WAVE_FORMAT_EXTENSIBLE` with the PCM subtype are supported. Metadata chunks
and padding may vary: the reader locates `fmt ` and `data` dynamically and
streams only the declared `data` payload.

See [wav-reader-reference.md](wav-reader-reference.md) for the normative
contract and known size limits.

## Repository shape

- `src/asm/` contains the complete production assembly closure.
- `src/fonts/Lat2-VGA8_8x8.font.inc` and `src/images/logo.rgba2` are direct
  assembly inputs.
- `scripts/make_wav.py` is the sole media-preparation tool.
- `scripts/test_make_wav.py` exercises the host-side WAV contract.
- `tgt/jukebox.bin` is the distributable binary.

The historical video, MIDI, and codec trees were removed from `wavonly` after
their absence from the compile/tool closure was proven. Git history and the
branch inventory preserve their archaeology.

## Qualification state

The dynamic standard-WAV reader, exact rate scheduler, bounded EOF handling,
and pruned candidate passed interactive playback, browsing, seeking, volume,
and pause/resume checks in the stock emulator. Forward/backward seek wrapping,
EOF progression, and final-to-first progression within the current directory
slice also passed. The same candidate has baseline physical-hardware approval;
the user observed better sound and fewer timing-related pops than in the
emulator. Extended cross-rate, long-form, cleanup, and VDP-memory-pressure
characterization remains optional follow-up work recorded in the development
log. This qualified WAV-only transition is released as `v0.10.0-beta` on
`wavonly`.

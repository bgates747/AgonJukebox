# Passing functional milestone — 2026-09-08

The project owner tested the live skin in Fab 1.2.4 with MOS 3.0.2 Arthur and
VDP 2.16.0 Bistromathics, reported all tested functionality working, and approved
promotion and commit. `functional-checkpoint.json` records the accepted binary
hashes and automated evidence. The normal application and test variant were
reassembled from their public locations and matched the reviewed binaries
byte for byte. Hardware qualification of this skin build remains separate.

The target test uses the same `src/asm/jukebox.inc` as `app.asm`, with scripted
hooks enabled. Its 26 scenarios cover empty/out-of-range input, directory/page
navigation, two-row selection redraws, playback/pause, volume, seeking, modes,
selected versus playing filenames, EOF progression, Loop precedence and random
selection. It reads 1,327 expected widget pixels through the actual MOS/VDP API
and records read accounting for a 65,535 Hz WAV with a partial final second.
The expected pixels in `fixtures/skin/widget-samples.bin` are u16 x, u16 y,
u8 R/G/B records sampled independently from the accepted package PNGs/fonts.

## Reproduction

The ordinary environment check assembles both variants and runs the host WAV
tests without launching an emulator:

```bash
.venv/bin/python scripts/verify_environment.py
```

Prepare a **new** isolated virtual SD tree; the command refuses an existing
destination and never changes your normal SD card or emulator profile:

```bash
.venv/bin/python tests/functional.py prepare /tmp/jukebox-functional-sd
```

From a configured project-local emulator profile, launch its generated wrapper
with the tagged MOS override and that test SD tree. For example, from
`.emulator/live-test`:

```bash
SDL_VIDEODRIVER=dummy SDL_AUDIODRIVER=dummy ./fab-agon-emulator \
  --firmware platform --mos ./mos_platform.bin \
  --sdcard /tmp/jukebox-functional-sd --renderer sw > functional.log 2>&1
```

The harness emits `LIVE_WIDGET_PIXELS_PASS` and `LIVE_TEST_PASS` to host stdout
via Fab's diagnostic port, then returns to MOS. Stop the test emulator with
Ctrl-C after those markers appear in the log, then from the repository root
validate the log:

```bash
.venv/bin/python tests/functional.py check .emulator/live-test/functional.log
```

Automation with dummy audio checks player state and scheduling; listening and
visual inspection accompany milestone acceptance. An early expanded run timed
out on its startup pixel reply; the final suite passed twice, followed by the
owner's successful interactive review. This evidence does not establish all
hardware timing or VDP resource limits.

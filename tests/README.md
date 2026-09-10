# Passing functional milestone — 2026-09-08

## Art Deco candidate — 2026-09-10

The basic Art Deco profile runs the same 26 scenarios through
`tests/asm/artdeco_check.asm`, with 5,307 expected pixels for its native 5×8
font, field geometry, decorative frame and widget states. The automated test
passes; the project owner accepted the candidate as a good working concept
on 2026-09-10 and authorized a checkpoint commit. Base's
accepted checkpoint below remains separate.

Prepare a new SD tree and check its log with:

```bash
.venv/bin/python tests/functional.py prepare /tmp/artdeco-sd --skin artdeco
# Launch using the profile-local wrapper described below, with /tmp/artdeco-sd.
.venv/bin/python tests/functional.py check /path/to/artdeco.log --skin artdeco
```

The Art Deco fixture comes from the selected artwork and the font editor's
native glyphs via `src/skins/artdeco/build.py`. It samples actual glyph strokes,
spacing, row backgrounds and control states. Fixed comparisons exclude moving
elapsed/progress pixels; pause, scheduling, seeking and EOF are exercised by
the functional scenarios. See `src/skins/artdeco/README.md` for regeneration.

## Accepted Base checkpoint

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

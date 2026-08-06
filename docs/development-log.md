# Development log

This is the current decision and evidence record for AgonJukebox. It includes
qualification evidence and any non-blocking follow-up characterization; the
project does not maintain a separate documentation TODO.

## 2026-08-01 — Standard-WAV reader and WAV-only repository closure

Status: implemented, fully validated in the stock emulator, approved on
physical hardware, and prepared as `v0.10.0-beta` on `wavonly`.

The product boundary is now explicit: a stock-VDP filesystem browser and WAV
player, plus one WAV preparation tool. AGM video, MIDI, private-firmware audio
controls, and compression experiments are recoverable from Git history but are
not part of this branch's build or toolchain.

### Standard WAV decision

The earlier rollback inherited a private fixed-offset assumption: it read 76
bytes and treated byte 76 as PCM. Real, standards-compliant output already in
the emulator used byte 78, while current FFmpeg can use byte 102 for
`WAVE_FORMAT_EXTENSIBLE`. Requiring Audacity, FFmpeg, or another compliant tool
to reproduce one metadata layout would have made the application needlessly
fragile.

The target reader now walks RIFF chunks, honors odd-byte padding, skips unknown
metadata, locates `fmt ` and `data` dynamically, and streams from the actual
payload offset. It accepts mono unsigned 8-bit integer PCM in either legacy
`WAVE_FORMAT_PCM` or extensible PCM form, with a rate from 1 through 65,535 Hz.
It checks container/chunk arithmetic against both the RIFF boundary and the
FatFS object size.

This resolves the former WAV investigations:

| Decision | Resolution |
|---|---|
| `WAV-001` — FatFS results | Every parser read/seek/open path checks `FRESULT`; failure closes the owned file. |
| `WAV-002` — short reads | Preamble, chunk-header, and format reads must return their exact requested lengths. |
| `WAV-003` — format validation | Format tag/subtype, mono channel count, rate range, byte rate, block alignment, valid bits, and sample depth are enforced. |
| `WAV-004` — payload layout | The first valid `data` chunk after `fmt ` supplies dynamic 32-bit offset and size; fixed byte 76 is gone. |

The normalized parser state reuses the previous 76-byte RAM allocations, so no
memory-map expansion was needed. The normative behavior is recorded in
[wav-reader-reference.md](wav-reader-reference.md).

### Streaming, EOF, and seek corrections

The timer still fills alternating one-second VDP sample buffers over 60 ticks,
but read sizes are now exact for every supported rate. The player computes
`rate / 60` and distributes `rate mod 60` bytes across the ticks. This removes
pitch/duration drift for rates not divisible by 60 and correctly handles the
65,535 Hz boundary and even rates below 60 Hz.

Streaming is bounded by the declared `data` size, so a RIFF pad or later chunk
cannot become audio. Duration is rounded up from the PCM byte count. The last
partial sample buffer receives a calculated drain interval before automatic
progression resets its channel, avoiding a clipped tail.

Seeking now uses the dynamic payload offset and a Euclidean modulo target, so
large backward steps wrap correctly on short tracks. The zero-based target is
preserved before the display increments its one-based playhead. Initial
prebuffering, where the display still reads zero, is handled separately so an
immediate seek is not one second early. Remaining bytes, fractional scheduling,
and EOF/drain state are all reset at the new position.

Automatic progression runs from the timer interrupt. A continuation flag now
causes the tail-jumped `get_input` to return through the interrupt call site,
allowing the handler to restore registers and execute `RETI` instead of
escaping its epilogue.

### Host WAV tool

All retained media preparation is consolidated in
`scripts/make_wav.py`. The script accepts local files, shallow directory
expansion, album concatenation, or one URL through `yt-dlp`; it supports trim,
normalization, compression, an explicit sample rate, and additional FFmpeg
filters. FFmpeg emits an ordinary mono `pcm_u8` WAV. The validator scans headers
and seeks over payloads rather than loading album-sized audio into memory.

The Python environment is intentionally small: Python 3.10 or newer, pinned
`yt-dlp`, and system `ffmpeg`/`ffprobe`. The assembly build additionally needs
`ez80asm`. There is no `agonutils`, native-extension, image, video, or codec
library dependency.

### Repository reduction

The production include closure and host-tool closure were proved before
removal. The pruning pass removed 287 tracked paths totaling 93,755,362
bytes—99.529% of the previous tracked byte count. The removed material comprised
the entire `midi/` and `frames/` trees; AGM/AGZ/video/compression scripts and
tests; unused AGM/debug/test assembly and listings; editable/generated image
and font sources not consumed by the assembler; target image experiments; and
obsolete video-oriented documentation.

One live `printHexA` routine was moved from the otherwise unused `debug.inc`
into `functions.inc` before deletion. The retained closure consists of the
production assembly includes, compiled font and logo inputs, the distributable
binary, one WAV converter, its tests, current documentation, and
setup/verification scripts. Historical branch names and deleted paths
remain documented in [branches_inventory.md](branches_inventory.md), and all
deleted sources remain reachable through Git history.

The required assembly includes were also trimmed conservatively: unused
buffer compression/decompression commands, generic image and SFX loaders,
MIDI-style sound helpers, font/plot helpers, debug directory output, a broken
unused previous-song routine, and unused viewport/sort state were removed only
after reference checks. Shared arithmetic, timer, and FPP libraries remain
intact where minimizing them would become a separate core-library rewrite.

### Verification evidence

Nine host tests pass. They cover minimal byte-44 PCM, variable metadata and
padding, trailing chunks, extensible PCM, invalid extensible subtype, ordering,
duplicates, empty/missing chunks, malformed fields, truncation, and real FFmpeg
output at 65,535 Hz. A synthetic source converted successfully to extensible
PCM with its payload at byte 102.

The four ignored emulator fixtures validate without rewriting:

| File | Sample rate | PCM bytes | Payload offset |
|---|---:|---:|---:|
| `Africa_65535.wav` | 65,535 Hz | 19,394,319 | 78 |
| `Lynyrd_Skynyrd__Gold_and_Platinum.wav` | 44,100 Hz | 258,547,712 | 78 |
| `Rhiannon.wav` | 48,000 Hz | 12,133,120 | 78 |
| `Wild_Flower.wav` | 48,000 Hz | 10,524,213 | 78 |

The first emulator launch exposed a target-only flag-contract error: successful
parser helpers loaded `A = 1`, but `LD` did not clear a zero flag left by the
preceding exact-length comparison. The browser therefore rejected every valid
WAV. Explicit `OR A` instructions now establish the documented nonzero return
condition on all parser success paths. A follow-up audit found no additional
fixture-specific or MOS/FatFS calling-convention error.

The corrected pre-version build is 27,716 bytes with SHA-256
`8793be268dc9507ce4960323e66351caf8e9a7559487d8b70a9d45f5e03e515d`.
The complete environment verifier passes: native dependencies, Python package
integrity, all nine host WAV tests, and assembly.

The user then completed the core interactive pass in the stock Fab Agon profile.
The supplied legacy WAVs and generated extensible fixture appeared and played;
directory browsing, volume control, ordinary seeking, and pause/resume behaved
as expected. Static review separately confirmed parser bounds, exact scheduling,
the data-size boundary, partial-buffer drain, signed seek wrapping, interrupt
continuation, and the target's MOS/FatFS register and `FIL` layout assumptions.

The user then completed the remaining `EMUL-001` edge cases. Multiple seek
steps worked correctly, including forward wrap from the end to the beginning
and backward wrap from the beginning to the end. Reaching EOF advanced to the
next song, and reaching the final song wrapped correctly to the first song in
the current directory slice. This completes the stock-emulator gate.

### Physical-hardware approval

The exact 27,716-byte candidate above was copied to the Agon SD card and
verified byte-for-byte after the write. The user approved it on physical
hardware. Playback sounded better than in Fab Agon, and the user observed that
the real interrupt timing queues the next one-second chunk more accurately,
producing fewer pops. This is the baseline hardware acceptance for the WAV-only
application. Longer cross-rate, full-album, cleanup, and VDP-memory-pressure
experiments remain useful non-blocking characterization work.

### Release consolidation and version

Final repository housekeeping moved the converter and its nine-case regression
suite together under `scripts/`, removed the obsolete `build/` and `tests/`
directories, and folded the sole Python dependency pin
(`yt-dlp==2026.7.4`) into `scripts/setup_python.py` before deleting
`requirements.txt`. The redundant documentation index and completed TODO were
removed; the hand-written root `README.md` remains the canonical user-facing
document, with the surviving `docs/` files providing focused references and
history.

The release is named `v0.10.0-beta`. Reusing `v0.9.6-beta` would conflate this
reproducible stock-VDP build with the unreproducible Oryx-era artifact, while a
new minor version records both the deliberate WAV-only scope reset and the
standard-WAV, scheduler, EOF, and seek improvements. The only source change
after physical approval was the UI label and its one-column spacing adjustment.
The user confirmed the new label in the stock emulator.

The final 27,716-byte binary has SHA-256
`b5d63d76abd5ac442851db1036c7895710c6545ad99d3b2d50f336a769aec550`.
The full verifier still passes: native dependency checks, Python package
integrity, all nine WAV tests, and isolated assembly. The transition is committed
and tagged on `wavonly`; GitHub's live default branch remains `main`, so any
promotion to the default branch is a separate decision.

## 2026-08-03 — Standardized deployment scheme

The `skins` branch now contains the standardized project deployment interface
merged from `dev`. Root `deploy.py` delegates to the canonical
`agon-dev-env/scripts/agon_deploy.py` engine, while `deploy.toml` declares one
Jukebox application bundle containing only the already-built
`tgt/jukebox.bin`. Deployment and building remain separate operations.

The currently active manifest destination is the safe owned directory
`/mystuff/agonjukebox/apps/jukebox`. The intended public installation is
instead the single file `/bin/jukebox.bin`, placing this non-MOSlet application
on MOS's command path so it can be invoked as `jukebox` from any working
directory. Its requested managed startup block is:

```text
cd /mystuff/music
jukebox
```

That direct-file destination remains a documented pending configuration, not
an active field. The shared engine currently owns and atomically exchanges
bundle directories; treating `/bin` as the owned destination would endanger a
shared system directory. Canonical direct-file ownership must stage, verify,
adopt, recover, and replace only `/bin/jukebox.bin`, with uniquely named sibling
metadata, before this compatibility layout is enabled.

The executable is already self-contained. The 2,048-byte compiled font and
9,600-byte RGBA2222 logo are assembled into `jukebox.bin`; neither is opened by
pathname at runtime. The environment verifier now rejects those UI assets if
they appear in `tgt` and proves both byte payloads occur in a fresh temporary
assembly. The full verifier passed with all nine WAV tests and the unchanged
27,716-byte binary. No standardized emulator or physical-card deployment has
yet been qualified from this branch.

## 2026-08-03 — Legacy `dev` preservation warning

**IMPORTANT: FAST-FORWARDING `dev` TO THE CLEAN WAV-ONLY `main` TREE MUST NOT
BE INTERPRETED AS A FINDING THAT EVERY FILE REMOVED SINCE THE OLD `dev` TIP WAS
VALUELESS.** The cleanup was correct for the supported application, but some
historical development assets may remain useful as references or source
material for future work.

The former `dev` tip is commit `4f76371` (`update gitignore for agon-utils`).
Its potentially useful material includes the Gnumeric design spreadsheets in
`build/data/`, GIMP `.xcf` image sources in `src/images/`, font and logo source
assets, older media/build utilities in `build/scripts/`, and experimental
keyboard, debug, and test assembly. These files remain recoverable individually
with commands such as `git show 4f76371:<path>` or by inspecting that commit in
a temporary worktree. Recover or evaluate specific artifacts deliberately;
do not merge the old tree wholesale into the qualified WAV-only application.

At this point `dev` contained no commits absent from `main`: it was an ancestor
of `main`, which was 189 commits ahead. Advancing `dev` therefore preserves the
clean production tree and its deletion history while making `dev` a usable
development branch again.

## 2026-08-01 — Stock-VDP rollback milestone

Commit `a6fc8bf` established the first deliberate WAV-only rollback from the
larger recovered codebase. It removed AGM dispatch and private-firmware limiter
controls while retaining browsing, double-buffered audio, seeking, playlists,
sample-rate display, and stored volume. It also stopped mutating the VDP global
audio-system rate: each created sample already carries its own explicit rate,
and the upstream global value 65,535 is a sentinel rather than a literal rate.

The user confirmed correct pitch when a non-65,535 Hz fixture was played first
and subsequently exercised the controls successfully in the stock emulator.
That evidence belongs to the fixed-header rollback; it does not pre-approve the
new standard-WAV implementation above.

Startup cleanup was narrowed from the historical clear-all operation to the
buffers owned by the application. The user clarified that clear-all had been
intentional VDP-memory reclamation for a demanding player. The scoped behavior
therefore remains a hardware experiment, not a settled policy.

## Recovery and provenance context

The v0.9.6-beta binary formerly used on hardware could be identified but not
reproduced from a clean commit. The best evidence indicates that it was built
from uncommitted work on a 2018 System76 Oryx Pro. That machine may contain AGM
and experimental output-control enhancements, but those features are outside
the desired stock-VDP audio product and are not required for this rollback.

The SD card retained a build tree and binary, but not the missing
`/mystuff/AgonJukebox` source checkout. The complete forensic record, artifact
hashes, branch comparison, Oryx details, rejected feature sets, and recovery
recommendations are preserved in
[audio-only-jukebox-archaeology.md](audio-only-jukebox-archaeology.md).

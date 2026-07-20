# Development log

This is the durable running record for AgonVideo. It captures work performed,
important discoveries, decisions, unresolved issues, and the most useful next
steps. Design details should eventually move into focused documents; this log
retains the chronology and explains why those documents changed.

## Current status

Last updated: 2026-07-19

- The complete AgonJukebox repository and all 303 upstream commits have been
  merged into this repository.
- The existing source already contains an unfinished AGM video player, media
  builder, compression experiments, and PC-side test players.
- Initial project and codec documentation exists under `docs/`.
- A project-local Python 3.14.6 runtime and `.venv` are available.
- Most ordinary Python dependencies have been installed and import-tested.
- Pygame, `sf2utils`, and `agonutils` are not installed. The `agonutils` source
  is pinned as an AgonVideo submodule.
- No codec implementation has been modified yet.
- The custom VDP/MOS source and current VDP documentation are not yet available
  in the local working context.

## 2026-07-19 — Project recovery and setup

### Established project goals

- Extend the existing eZ80 WAV jukebox into a synchronized audio/video player.
- Treat UART throughput and ESP32 decompression speed as the first feasibility
  gates; defer seeking design until those gates are passed.
- Retain stock VDP behavior except for custom decompression firmware.
- Use VDP frame swapping during playback.
- Target approximately 300x200 RGBA2222 video at 15 fps with 16 kHz, 8-bit mono
  audio.

### Initial throughput estimate

- At 1,152,000 baud with assumed 8N1 framing, theoretical UART payload is
  115,200 bytes/second.
- Audio consumes 16,000 bytes/second at the target rate.
- At most 99,200 bytes/second remains for video and protocol overhead.
- Raw 300x200 video at 15 fps is 900,000 bytes/second, requiring about 9.1:1
  video compression before allowing a safety margin.

The assumptions and full calculation are recorded in
`docs/codec-and-throughput.md`.

### Existing codec pipeline recalled

The historical video pipeline was described as:

1. Convert to RGBA2222 with Bayer-matrix dithering.
2. Replace pixels matching the same location in the preceding frame with zero
   (called "delta framing" in this project).
3. Compress the result with RLE2.
4. Compress the RLE2 output with SZIP.

The combined method produced promising sizes, but SZIP decompression on the
ESP32 became the performance bottleneck. The two optimization goals are to
improve the first-stage representation and to make second-stage decompression
cheaper without losing too much compression.

### Documentation created

Created:

- `docs/README.md`
- `docs/project-overview.md`
- `docs/codec-and-throughput.md`

These initially relied on discussion and explicitly distinguished facts from
assumptions. They now need a source-backed revision after the imported code is
mapped in detail.

### AgonJukebox source recovered

The public `bgates747/AgonJukebox` repository was first inspected read-only and
then merged at the user's request. Its complete 303-commit history is retained
under the `agonjukebox/main` remote-tracking branch. The local documentation was
committed as a separate root before joining both histories with a merge commit.

Important discoveries:

- `src/asm/agm.inc` defines the AGM container and an interrupt-driven playback
  implementation.
- `build/scripts/agm_make.py` builds one-second audio/video segments and supports
  raw, TurboVega, SZIP, and combined RLE2+SZIP compression.
- The player maintains three seconds/segments of audio buffering and a related
  ring of video-frame buffers.
- The repository contains extensive codec comparisons, generated samples, and
  PC-side playback/validation scripts.
- The `midi/` tree is a substantial sample-synthesis and multichannel playback
  laboratory, not a minor utility.

RLE2's byte grammar was recovered from `build/agz/rlecompress.cpp` and
`build/agz/rledecompress.cpp`:

- alpha class `00`: native transparent/delta pixel;
- class `01`: transparent run;
- class `10`: opaque literal or opaque run-length command; and
- class `11`: opaque color byte following a run command.

This preserves a one-byte representation for isolated pixels and uses two bytes
for an opaque run of up to 64 pixels.

The repository does not contain the actual SZIP source or custom ESP32 decoder.
`build/scripts/copy_szip_src.py` points to historical sibling paths:

- `/home/smith/Agon/szip`
- `/home/smith/Agon/os/agon-vdp/video/szip`

A possible format bug or stale-definition mismatch was found: the SZIP and
TurboVega compression-mask values are reversed between `src/asm/agm.inc` and
`build/scripts/agm_make.py`. This must be checked against the VDP implementation
and known-good AGM files before changing either definition.

### Python environment

Python 3.14.6 was installed as an ignored project-local runtime under `.python/`.
The virtual environment is `.venv/`, with pip 26.1.2. Activate it with:

```bash
source .venv/bin/activate
```

Installed and import-tested packages:

- NumPy 2.5.1
- SciPy 1.18.0
- Pillow 12.3.0
- pandas 3.0.3
- Matplotlib 3.11.1
- pydub 0.25.1
- SoundFile 0.14.0
- PrettyMIDI 0.2.11
- pyFluidSynth 1.4.0
- audioop-lts 0.2.2 (needed by pydub on Python 3.14)

Pygame 2.6.1 did not install because no Python 3.14 wheel was available and a
source build could not find SDL2/Freetype development libraries. It is needed by
the PC-side reference video player, but will be handled separately.

Other missing or external dependencies:

- `sf2utils` — source location being recovered;
- `agonutils` — source location being recovered;
- FFmpeg executable — pydub imports, but warns that FFmpeg is unavailable; and
- FluidSynth native runtime — the Python module imports, but actual synthesis
  still needs an end-to-end check against the native library and a soundfont.

The installed Python environment is not yet represented by a requirements or
project metadata file, so it is functional but not fully reproducible.

### External agon-utils repository cloned

Cloned `bgates747/agon-utils` as an independent sibling repository:

- Local path: `/home/smith/Projects/agon-utils`
- Branch: `main`
- Commit: `a3a2d2d47d962ce010b70d2adfaa2e3dd7dda220`
- Commit date: 2025-04-17

The clone was clean after checkout. It contains `src/agonutils.c` and a
`setup.py`, so the historical `agonutils` Python extension can now be examined
and built separately. It has not yet been installed into AgonVideo's `.venv`.

### agonutils installation process reviewed

Reviewed the top-level scripts and package metadata in the sibling `agon-utils`
repository. The intended historical workflow was to compile a native CPython
extension and either install a wheel or install the source tree in editable
mode. For AgonVideo, the interpreter running pip must be AgonVideo's
`.venv/bin/python`; otherwise the extension will be built for and installed into
the wrong Python environment.

The extension currently compiles these sources:

- `src/agonutils.c`
- `src/images.c`
- `src/agm.c`
- `src/rle.c`
- `src/simz.c`

It links against FFmpeg's `libavformat`, `libavcodec`, `libswscale`, and
`libavutil`, plus libpng. The machine has a C compiler and the project-local
Python 3.14 headers, but the FFmpeg/libpng development packages and FFmpeg
executable are absent. These native prerequisites must be installed before the
extension can build.

Packaging issues found:

- `project.toml` contains valid build-system content but is misnamed; Python
  packaging expects `pyproject.toml`, so current tools ignore it.
- `dev_install_agon-utils.py` hardcodes an obsolete macOS path and must not be
  used here.
- The build helper scripts depend on whichever `sys.executable` launches them;
  running them outside AgonVideo's activated environment installs into the wrong
  interpreter.
- The README's `python setup.py install` workflow is obsolete; pip wheel or
  editable installation is preferable.
- The destructive cleanup logic in `build_and_install.py` is unnecessary for a
  first installation and searches site-package locations more broadly than
  needed.
- `src/szip.c` and `src/szip.h` are present, recovering a historical SZIP source
  copy, but `setup.py` does not compile `szip.c` into `agonutils`.
- `src/simz.c` is compiled, but its `simz_*` Python functions are not registered
  in the method table in `src/agonutils.c`; tests expecting methods such as
  `agonutils.simz_decode_bytes` will therefore require reconciliation.

Recommended eventual installation sequence:

1. Correct and modernize the packaging metadata in the `agon-utils` repository.
2. Install the required native development libraries.
3. Build/install from AgonVideo with
   `.venv/bin/python -m pip install -e /home/smith/Projects/agon-utils` for active
   development, or build a wheel for a fixed reproducible installation.
4. Verify the imported extension path, exported methods, linked libraries, and
   representative image/AGM/SIMZ operations.

No source was modified and `agonutils` remains uninstalled pending those fixes.

### agon-utils submodule introduced

Added `bgates747/agon-utils` at `external/agon-utils` as a Git submodule, pinned
to commit `a3a2d2d47d962ce010b70d2adfaa2e3dd7dda220`. The submodule source is clean
and matches the previously inspected sibling checkout. No `agon-utils` source
was modified.

The inherited `.gitignore` contained unanchored `agon-utils` rules, which caused
Git to reject the first submodule-add attempt before making changes. Those
obsolete rules were removed and the submodule was then added normally without
forcing ignored content.

Created `docs/development-setup.md` with fresh-clone, existing-clone, status, and
safe submodule-development instructions. The sibling checkout at
`/home/smith/Projects/agon-utils` remains untouched as a temporary fallback.

Validated the documented fresh-checkout path with a separate recursive clone in
`/tmp`: Git registered the submodule, cloned it from GitHub, and checked out the
expected pinned commit successfully.

### Standardized Python and agonutils setup implemented

Created branch `agonvideo/modern-python-build` in the `agon-utils` submodule and
committed the following changes as `6f076d3`:

- renamed the ignored `project.toml` metadata to the standard
  `pyproject.toml`;
- made missing `pkg-config`, FFmpeg, and libpng build dependencies fail with
  explicit messages;
- removed hardcoded Linux/macOS include and library paths in favor of portable
  `pkg-config` flags;
- updated package metadata and installation documentation;
- exposed the existing SIMZ file and in-memory entry points through the Python
  module; and
- added a SIMZ byte round-trip test.

The legacy installation scripts were retained for downstream compatibility but
are no longer part of the recommended workflow.

Added the following AgonVideo-owned setup components:

- `requirements.txt` with reviewed, pinned ordinary Python dependencies;
- `scripts/check_native_deps.py` for read-only native prerequisite checks;
- `scripts/setup_python.py` for submodule, virtual-environment, dependency, and
  editable-extension setup; and
- `scripts/verify_environment.py` for import, API, native dependency, and SIMZ
  round-trip verification.

Python syntax validation passes, and the dependency checker correctly reports
the currently missing FFmpeg/libpng prerequisites. Automatic system installation
was attempted, but `sudo` requires the user's password in an interactive
terminal. Full extension build and environment verification remain pending that
one manual system-package installation step.

## Decisions

- Preserve AgonJukebox history rather than copying only its current files.
- Keep external MOS, VDP, and documentation repositories as siblings rather than
  merging their histories into AgonVideo.
- Use repository documentation as persistent context across coding sessions.
- Keep the existing BBC BASIC floating-point seeking implementation until
  measurements justify replacing it.
- Optimize for decoded frames per second and reliable audio, not compression
  ratio alone.
- Handle Pygame separately from the remaining Python dependencies.

## Immediate next steps

1. Inspect and install the recovered `agonutils` extension; locate `sf2utils`,
   the historical SZIP source, and the custom VDP decoder.
2. Clone or identify local paths for current Agon VDP documentation, VDP source,
   and MOS source; record their exact commits.
3. Create a repository map distinguishing production, generated, experimental,
   archival, and MIDI-specific material.
4. Reconcile the AGM compression-mask mismatch against VDP source and test data.
5. Make the Python environment reproducible with reviewed dependency metadata.
6. Restore the PC reference player, including Pygame, and establish a known-good
   decode/playback baseline.
7. Profile the current ESP32 SZIP and RLE2 decoders before designing replacements.

## Log maintenance convention

For each meaningful work session, append a dated section containing:

- work completed;
- evidence or measurements;
- decisions and their rationale;
- blockers or newly discovered risks; and
- the next concrete actions.

Minor edits need not be logged individually; commits remain the detailed record
of file-level changes.

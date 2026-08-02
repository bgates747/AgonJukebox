# AgonJukebox skinning architecture proposal

## Status and intent

This document proposes a structured, data-only skinning system for a future
AgonJukebox release. It is an architecture proposal, not an implementation or
an asset-design pass. No images need to be generated to evaluate it.

The contracts and numeric assignments below are intentionally provisional.
They sketch a broad framework and expose useful implementation possibilities;
they may change as visual design, loader measurements, and hardware testing
produce better information.

The first skin should be visually rich. The current interface should be
retrospectively packaged as a `classic` skin rather than permanently embedded
as a second full UI implementation. The executable should retain only enough
compiled-in presentation to report a broken skin and open the skin chooser.

## Decisions already made

- The v1 skin contract targets Console8 VDP mode 20:
  `512x384`, 64 colours, 60 Hz, single-buffered.
- Logical coordinate scaling remains disabled. Skin rendering therefore uses
  native pixels with `(0,0)` at the top-left.
- The interaction model and major screen regions are fixed in v1. Skins alter
  presentation, not application behavior or arbitrary geometry.
- Skins are external packages below `/jukebox/skins/`.
- Skin selection is performed in the application and persisted in a small,
  human-readable `.cfg` file. JSON is explicitly out of scope.
- Skins contain data and declarative metadata only. They cannot provide code or
  VDU command streams.
- Rendering uses a hybrid model: pixel coordinates for freely positioned
  graphics and text/glyph operations where the character grid is convenient.
- Skin graphics are packed into Agon Buffer Container (`.agnb`) files for a
  single-open, sequential, bounded streaming load.
- Lengthy repeatable screen operations should be retained as
  application-authored VDP buffered command sequences and invoked with small
  buffered API calls during playback.
- Standard upstream Console8 firmware remains the sole firmware target.
- Mode 0 (`640x480x16`, single-buffered) may support a later minimalist layout,
  but it is not part of the v1 contract. A skin must never silently change the
  screen mode.

Mode 20 gives an `8x8` font a `64x48` character grid, but the new renderer
should use pixels as its primary coordinate system. Text-cell coordinates are
an implementation detail of text widgets rather than the layout system.

## Goals

1. Let users install, preview, select, and persist a visual style without
   rebuilding the application.
2. Make skins safe and predictable on real hardware: bounded files, bounded VDP
   buffer ownership, no executable content, and deterministic fallback.
3. Separate player state and behavior from presentation so a skin cannot alter
   browsing, playback, seeking, or interrupt behavior.
4. Support a rich first-party skin using backgrounds, panels, a custom font,
   logos, iconography, and role-based colours.
5. Preserve the current interface as an external `classic` compatibility skin.
6. Keep skin authoring reproducible with a host-side validator and packer.
7. Avoid full-screen redraws during playback, since the display is
   single-buffered and VDP traffic competes with time-sensitive audio work.

## Non-goals for v1

- Arbitrary user-defined layouts or coordinates.
- Scripts, plugins, macros, or executable VDU command buffers in skin packages.
- Per-track album art or metadata extraction.
- Animated full-screen backgrounds, transitions, or video.
- Runtime screen-mode switching.
- Transparent access to arbitrary VDP buffer IDs.
- Loading skins from archives directly on the Agon.
- Supporting every possible font size or bitmap encoding.
- Making a bad or incomplete skin partially usable.

These restrictions are deliberate. They create a stable skin contract before
layout scripting, alternative resolutions, animation, or album art are
considered.

## Proposed package layout

The SD-card structure should be:

```text
/jukebox/
    jukebox.bin
    jukebox.cfg
    skins/
        classic/
            skin.cfg
            font.bin
            graphics.agnb
        velvet-hifi/
            skin.cfg
            font.bin
            graphics.agnb
    music/
        ...
```

Only `skin.cfg` is mandatory inside a skin directory. Container and font
filenames are declared by the manifest; the names above are conventions, not
hard-coded requirements. A skin ID is its directory name and should be limited
to ASCII letters, digits, hyphens, and underscores.

First-party skin packages may be tracked in the repository because they are
application assets. Emulator profiles, copyrighted test music, and user skin
collections remain outside the repository.

Future releases should ship a ready-to-copy directory or ZIP containing the
binary, the default configuration, and at least one complete skin. The binary
by itself should still be capable of presenting the recovery chooser, but it
need not contain the full Classic UI.

## Configuration format

### Global selection

`/jukebox/jukebox.cfg` should use a deliberately small `key=value` grammar:

```ini
# AgonJukebox user configuration
format=1
skin=velvet-hifi
```

Rules:

- UTF-8 or ASCII text without a byte-order mark.
- One `key=value` pair per line.
- Leading and trailing whitespace is ignored.
- Blank lines and lines beginning with `#` or `;` are comments.
- Keys are ASCII and case-insensitive; IDs and filenames are case-preserving.
- Duplicate keys, overlong lines, embedded control characters, absolute asset
  paths, and `..` path components are errors.
- Unknown keys produce a non-fatal warning so newer configuration can survive
  an older application.
- An unsupported `format` value is fatal for that file.

The chooser writes only the selected skin and current format version. It should
write a temporary file and rename it into place so interruption cannot leave a
half-written configuration. Failure to persist a choice must not prevent the
selected skin from being used for the current session.

### Skin manifest

Each package contains a manifest using the same grammar:

```ini
# Example only; values are not yet a frozen specification.
format=1
id=velvet-hifi
name=Velvet Hi-Fi
author=Example Author
layout=jukebox-v1
screen_mode=20

font.file=font.bin
font.width=8
font.height=8

graphics.file=graphics.agnb

glyphs.first=128
glyphs.count=64

colour.screen=0x00
colour.panel=0x05
colour.panel_alt=0x09
colour.text=0x3f
colour.text_muted=0x2a
colour.highlight=0x3c
colour.highlight_text=0x00
colour.progress=0x30
colour.warning=0x33
```

Colour values in v1 are physical RGB222 colour numbers from `0x00` through
`0x3f`, matching mode 20's 64-colour model. Named roles keep renderer logic
independent of a particular palette. The final role list should be frozen as
part of `format=1`; missing optional roles inherit documented defaults.

The manifest declares container files and semantic capabilities, but never
arbitrary drawing commands or positions. AGNB `BHDR` records necessarily carry
exact destination buffer IDs; those IDs are generated from the same fixed
semantic buffer map used to assemble the application. A skin cannot choose
IDs outside the declared visual ranges.

## Asset contract

V1 should support a deliberately small set of asset types:

| Asset | Format | Notes |
|---|---|---|
| Font | Raw Agon font data | Initially exactly 256 glyphs at `8x8`, 2,048 bytes |
| Graphics pack | AGNB 0.1 image container | One or more `BHDR/IMAG/DATA` records, loaded sequentially |
| Bitmap | RGBA2222 `IMAG` record | One byte per pixel; dimensions travel with the record |
| Multicolour glyph | RGBA2222 `IMAG` record | One bitmap per mapped character; normally 8x8 |
| Icon or atlas | RGBA2222 `IMAG` record | Either separate semantic icons or a plotted atlas |
| Text | Manifest strings | Short labels only; no arbitrary text-file inclusion in v1 |

RGBA2222 matches the current logo path and preserves the full mode-20 colour
range plus transparency semantics. A complete 512x384 background is 196,608
bytes before any other visual resources, so dimensions and total byte counts
must be checked before data is sent to the VDP.

AGNB is the deployment container rather than a replacement image encoding. It
packages many independently addressable VDP buffers into one file, eliminating
repeated MOS pathname lookup while retaining separate bitmap identities. The
loader opens the container once, validates metadata before each payload, and
streams it in bounded blocks without holding the container in eZ80 memory.

The 65,534 generally available VDP buffer IDs are not a scarce resource for
this design. Multicolour characters may therefore use one buffer and bitmap
definition per glyph. The real limits are shared VDP memory, initial UART
traffic, and load duration. Ordinary text can still use a compact monochrome
font, while selected character ranges map to coloured bitmaps through
`VDU 23,0,&92` for borders, icons, ornaments, and stylized headings.

The first implementation should not revive the experimental compression API.
Uncompressed assets are simpler to validate and eliminate decompression
behavior from the trusted target-side loader. Compression can be reconsidered
only after startup time and VDP memory are measured on hardware.

The host packer should reject:

- dimensions that do not match file length;
- assets outside the mode-20 canvas;
- unsupported font geometry or bitmap formats;
- path traversal or filename collisions;
- missing mandatory roles or assets;
- an asset total above the configured compatibility budget; and
- colour data that cannot be represented as RGBA2222.
- AGNB records with duplicate, reserved, or out-of-range buffer IDs.

An initial engineering target of roughly 384 KiB for all visual assets is
reasonable for planning, not yet a compatibility guarantee. The actual v1 cap
must be chosen after measuring startup transfer time, VDP allocation behavior,
and simultaneous maximum-rate audio buffers on physical hardware.

## Fixed layout contract

`jukebox-v1` should define named rectangles on the 512x384 canvas. Exact pixel
boundaries can be adjusted during mockup work, but once released they become
part of the layout ABI. A plausible starting division is:

| Region | Initial bounds | Purpose |
|---|---:|---|
| Canvas/chrome | `0,0,512,384` | Static background and outer decoration |
| Brand/header | `16,12,480,80` | Logo, title, or decorative hero area |
| Path/page header | `16,100,480,24` | Current directory and page count |
| Browser panel | `16,128,480,160` | Ten fixed 16-pixel rows |
| Now-playing panel | `16,296,480,44` | Filename, elapsed time, and duration |
| Playback status | `16,344,480,24` | Mode, seek step, sample rate, and volume |
| Message/footer | `16,372,480,12` | Compact prompts or errors |

These are design inputs, not final artwork. The important architectural point
is that code owns the rectangles and semantics. A skin supplies the visual
treatment within them.

Each region is rendered by a widget with a stable state contract:

- `brand`
- `directory_path`
- `page_counter`
- `browser_row[0..9]`
- `selection`
- `now_playing`
- `elapsed_time`
- `duration`
- `progress`
- `sample_rate`
- `playback_mode`
- `seek_step`
- `volume`
- `message`

Skins may hide an optional widget with a manifest flag only where the layout
contract explicitly permits it. They may not reassign controls, change list
length, alter paging, or redefine widget meaning.

## Runtime architecture

### 1. Player state remains authoritative

Browsing and playback code should expose presentation-neutral state. It must
not know colours, coordinates, fonts, bitmaps, or skin filenames. Existing
direct calls to `vp_*`, text colour routines, and ad hoc redraw functions should
gradually become renderer events.

Suggested events include:

```text
UI_FULL_REDRAW
UI_DIRECTORY_CHANGED
UI_PAGE_CHANGED
UI_SELECTION_CHANGED
UI_TRACK_CHANGED
UI_TIME_CHANGED
UI_PLAYBACK_MODE_CHANGED
UI_SEEK_STEP_CHANGED
UI_VOLUME_CHANGED
UI_MESSAGE_CHANGED
```

### 2. Fixed-layout renderer

The renderer maps those events to `jukebox-v1` widgets and dirty rectangles.
It knows the layout geometry but obtains fonts, bitmaps, icons, and colour roles
from the active skin. Player code calls the renderer; it never calls a skin.

The renderer may position assets at arbitrary native pixel coordinates or use
the text cursor and glyph grid. Window borders are particularly suitable for
glyph construction: monochrome font characters provide inexpensive simple
chrome, while character-to-bitmap mappings provide multicolour corners,
edges, separators, and embedded icons using the normal print path.

### 3. Skin manager

The skin manager owns:

- discovery of skin directories;
- parsing and validation of both configuration files;
- selection and persistence;
- asset preflight and loading;
- the active role table and logical asset registry;
- unloading only resources owned by the active skin; and
- fallback to recovery mode.

### 4. Asset loader

The loader consumes the canonical AGNB image format. Each `BHDR` carries the
exact VDP buffer ID generated from the application/packer contract; the loader
validates that it belongs to the skin-owned range and uses it unchanged. Each
`IMAG` record is streamed, consolidated, and finalized as a bitmap before the
single file-open traversal continues. Files are never loaded into eZ80 RAM in
their entirety.

### 5. Recovery shell

The executable retains a tiny skin-independent shell using the VDP's ordinary
font and a few built-in colours. It is not a second production UI. It only needs
to display:

- the application name and version;
- the skin-load error;
- discovered valid skins; and
- controls to select a skin or quit to MOS.

This removes the requirement to compile the entire current text UI while
ensuring a missing SD directory cannot make the program unusable.

## VDP buffer ownership

Buffer allocation must be centralized. Current audio streaming owns
`0x3000` through `0x3003`; skins must never touch those IDs. The present UI uses
other scattered IDs for its logo and font, which should be replaced by one
documented visual range and a logical registry.

A possible v1 map is:

```text
0x2100          background
0x2101          logo
0x2102          icon atlas
0x2110-0x211f   optional panel and decoration assets
0x21f0          active font
0x2200-0x22ff   multicolour mapped-character bitmaps
0x2300-0x23ff   application-authored UI command sequences
0x3000-0x3003   audio command/data buffers (reserved; not skin-owned)
```

The exact range must be checked against upstream conventions before
implementation. The invariants matter more than these provisional numbers:

1. A manifest cannot name or alias a buffer; the trusted AGNB packer emits IDs
   from the shared semantic map.
2. Every loaded visual buffer is recorded in the skin registry.
3. Switching or exiting clears exactly the registered visual buffers and font.
4. Audio cleanup and skin cleanup remain independent.
5. No skin path may issue clear-all.

## Rendering on a single-buffered display

Mode 20 is single-buffered, so avoiding visible construction and flicker is a
renderer responsibility.

- Skin activation may perform one controlled full-screen draw.
- Static chrome and decorative background are drawn once.
- Dynamic information is confined to opaque or reproducible panel regions.
- A widget update first restores its panel background, then redraws content.
- Selection changes redraw only the old and new rows.
- Elapsed time and progress redraw at their natural low frequency, not every
  timer interrupt.
- Repeated widget drawing sequences may use application-authored buffered VDU
  commands, but skin packages cannot provide command buffers.
- Full-screen animation and continuous background effects are excluded from
  v1.

Buffered command sequences are a primary playback-time optimization, not an
incidental implementation option. Static chrome, panel restoration, glyph
borders, browser-row bases, selection treatments, and other involved repeated
updates can be uploaded once and retained on the VDP. The eZ80 then invokes a
callable buffer with a six-byte buffered API call instead of rebuilding and
retransmitting the full VDU stream while audio is active.

Dynamic filenames, times, values, and cursor positions remain small eZ80-side
updates. Where worthwhile, application code may patch trusted command operands
with buffered command 5 or enter a shared sequence at an offset with command
11. Call graphs must remain shallow and acyclic because excessive nesting or a
looping command sequence can hang the VDP.

Performance budgets should distinguish four costs: one-time skin loading
traffic, VDP memory occupied by assets and commands, routine playback-time
UART traffic, and worst-case redraw traffic during streaming. The principal
renderer metric is the number of bytes that must cross from the eZ80 after the
skin has been prepared.

VDP asset transfers share a path with audio commands. Applying a new skin while
streaming could therefore cause audible disruption. V1 should permit browsing
the chooser at any time but apply a skin only through a controlled transition:
pause or stop playback, load and draw the skin, reset scheduler state as
necessary, and then resume only if that sequence proves glitch-free. The first
implementation may instead require playback to be stopped when a skin is
applied. This behavior needs an explicit emulator and hardware decision.

## Skin discovery and chooser

The chooser should be a fixed application screen rendered by the recovery shell
or active skin. A proposed `T` key opens it (`T` for theme); the final key is a
UI decision.

Discovery scans only direct child directories of `/jukebox/skins`. For each
candidate it reads enough of `skin.cfg` to validate `format`, `id`, `name`,
`layout`, and `screen_mode`. Invalid entries remain visible with a concise error
instead of silently disappearing. This makes hand-edited manifests debuggable.

Selection flow:

1. Highlight a discovered skin.
2. Preflight its entire manifest and every declared asset.
3. If valid, begin the controlled apply transition.
4. Load resources into application-owned buffers.
5. Render a complete frame.
6. Mark the new registry active and release the old skin's resources.
7. Persist the new ID to `/jukebox/jukebox.cfg`.

Where VDP memory does not permit old and new assets to coexist, the transition
may need to release the old skin before loading the new one. In that case the
recovery shell must remain available without skin buffers, and any failure
returns there rather than leaving a half-rendered player.

## Failure behavior

Failure handling is part of the format contract:

| Condition | Required behavior |
|---|---|
| `jukebox.cfg` absent | Use the packaged default if known; otherwise open chooser |
| Selected directory absent | Show error and chooser |
| Manifest malformed or unsupported | Do not load any assets; show exact reason |
| Asset absent, oversized, or wrong length | Reject package before activation |
| Read error during load | Clear partial skin buffers and enter recovery shell |
| Config write failure | Keep current-session skin and report that it was not saved |
| No valid skins | Recovery shell offers Quit and Retry |
| VDP mode request fails | Remain in recovery shell and do not start the player UI |

There should be no silent fallback that makes a broken custom skin look like a
different valid skin. The user should know what failed and be able to choose a
replacement.

## Retrofitting the current UI as Classic

The existing UI can become the first conformance fixture:

- externalize the current `8x8` font as `font.bin`;
- package the current logo as RGBA2222;
- render the ASCII title as either normal widget text or a prebuilt bitmap;
- map the current dark blue, white, and highlight choices to colour roles;
- reproduce the ten-row browser and existing status fields in `jukebox-v1`;
  and
- compare emulator screenshots and hardware behavior with `v0.10.0-beta`.

Classic parity is valuable even if the fancy skin is the eventual default. It
proves that presentation has been separated without changing player behavior,
and it provides a low-complexity diagnostic skin for future regressions.

The Classic package, not the executable, should own its full visual identity.
Only the recovery shell remains compiled in.

## Host-side authoring and validation

A future `scripts/make_skin.py` should orchestrate the existing `agonutils`
image conversion and canonical AGNB writer/validator rather than defining a
new container or RIFF implementation. Authoring artwork can be decoded and
converted deterministically to RGBA2222, then emitted as explicit-ID `IMAG`
records in the skin's graphics container.

The tool should:

- parse the exact target-side configuration grammar;
- validate IDs, paths, dimensions, roles, and byte budgets;
- convert source artwork to RGBA2222 without dithering unless requested;
- verify that transparent pixels and RGB222 quantization are intentional;
- build or validate the `8x8` font payload;
- generate an icon atlas and stable semantic icon map;
- generate individual bitmap records for mapped multicolour glyphs;
- emit and validate the AGNB graphics container;
- emit a package directory and optional distributable ZIP;
- print per-asset and total VDP byte usage; and
- provide a `--validate-only` mode for downloaded skins.

Authoring source files may use richer formats, but an installed skin contains
only the minimal target package.

## Testing and qualification

### Host tests

- Configuration grammar, comments, whitespace, duplicates, and limits.
- Path traversal and malformed filename rejection.
- Manifest version and required-field handling.
- Exact RGBA2222 size calculations and conversions.
- AGNB structure, explicit buffer ranges, record uniqueness, and alignment.
- Font-size and icon-atlas validation.
- Multicolour character bitmap and mapping-table validation.
- Total asset-budget enforcement.
- Golden-package validation for Classic and the first fancy skin.
- Config rewrite behavior, including interrupted/temp-file cases.

### Target and emulator tests

- Missing global config, missing selected skin, and no-skins cases.
- Every malformed package class returns to the recovery chooser.
- Repeated switching does not leak VDP buffers.
- Directory browsing and all player controls behave identically across skins.
- Dirty-region redraws leave no remnants from previous values or selections.
- Classic parity against the current interface.
- Fancy-skin visual review at native 512x384 output.

### Physical-hardware tests

- Startup and skin-switch transfer time.
- Memory pressure with maximum-rate audio buffers and the largest valid skin.
- Continuous audio while ordinary widgets update.
- Audible behavior during the chosen skin-apply transition.
- Repeated switch/quit/relaunch cycles and scoped buffer cleanup.
- Monitor compatibility with mode 20 and scaling disabled.

As with the player release, human emulator and physical-hardware approval must
precede promotion of skin-loader or emulator-coupled changes.

## Phased implementation

### Phase 1: Presentation boundary

Introduce the UI event interface and fixed `jukebox-v1` renderer while keeping
the current embedded assets. Behavior and appearance should remain unchanged.

### Phase 2: Configuration and recovery shell

Implement the bounded `key=value` parser, global selection file, skin discovery,
manifest preflight, recovery shell, and chooser. Test failure paths before
loading external graphics.

### Phase 3: External asset loader and Classic

Centralize visual buffer IDs, stream bounded external assets, implement scoped
cleanup, and package the current interface as the external Classic skin. Remove
the full embedded Classic assets only after parity and recovery testing pass.

### Phase 4: Fancy reference skin

Design and build the first rich mode-20 skin against the frozen layout and role
contracts. Establish the actual asset budget and switch behavior through
emulator and hardware measurements.

### Phase 5: Authoring and distribution

Add the deterministic host packer/validator, package both first-party skins,
document third-party authoring, and ship a ready-to-copy release archive.

### Later possibilities

- A separate fixed `jukebox-minimal-640` layout for mode 0 at `640x480x16`.
- Additional fixed layouts negotiated by manifest version.
- More font geometries.
- Optional compressed assets after a standard-firmware performance study.
- Per-track artwork through a separate media-metadata contract.
- Carefully bounded animation primitives authored by the application, not
  arbitrary skin commands.

## Decisions still required before implementation

1. Freeze the exact `jukebox-v1` rectangle boundaries after mockup review.
2. Choose the skin chooser key and whether it appears in the normal legend.
3. Decide whether applying a skin stops playback or attempts pause/load/resume.
4. Establish the visual asset cap from physical VDP memory and transfer tests.
5. Decide whether unknown manifest keys warn visibly or only in a diagnostic
   screen/log.
6. Define the required minimum packaged skin and first-run behavior when
   `jukebox.cfg` is absent.
7. Decide which fancy skin becomes the default after Classic proves parity.

## Recommendation

Proceed with one fixed mode-20 layout, a tiny compiled recovery shell, external
data-only packages, and Classic as the first conformance skin. Build the fancy
skin only after the event boundary, manifest parser, failure behavior, buffer
registry, and Classic parity are working. This sequence makes the ambitious
visual redesign possible without allowing presentation work to destabilize the
hardware-qualified audio player.

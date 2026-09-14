# Runtime skins candidate

`app_runtime.asm` builds one executable that loads Art Deco, Seventies, PCB or Nineties from
external packages. Press **k** to stop playback and open the MOS text chooser.
Choose a numbered package; **r** rescans, and **q/Escape** returns to MOS. Switching
keeps the current music directory and starts with playback stopped. The choice
lasts for this session; `/bin/jukebox.cfg` determines the next startup selection.

Build and export from the project root:

```sh
.venv/bin/python scripts/skin_schema/runtime.py
(cd src/asm && ez80asm app_runtime.asm ../../tgt/jukebox-runtime.bin)
```

Install `tgt/jukebox-runtime.bin` as `/bin/jukebox.bin`, the contents of
`skins/runtime/` as `/jukebox/skins/`, and `config/jukebox-runtime.cfg` as
`/bin/jukebox.cfg`. Adjust `music_dir` for the target card. The supplied configuration
starts Seventies. Each runtime package contains its own `skin.cfg`, `layout.bin`,
AGNB artwork and fonts. The compiled prototype packages remain separately available.

The chooser scans the configured skin directory's parent, including when that
package is missing or invalid. Missing/invalid global configuration uses
`/jukebox/skins/`. It lists the first ten visible subdirectories containing
`skin.cfg`, in filesystem order. Validation occurs when selected; a bad package
returns to the chooser. An unavailable music directory leaves the current directory
in use with a notice. An unreadable discovery directory returns to MOS with a notice.

## Runtime-v1 data contract

The manifest has the existing five keys and `format=jukebox-runtime1`. Its layout
leaf is always `layout.bin`. The exact 1,389-byte little-endian descriptor contains:

| Offset | Bytes | Meaning |
|---|---:|---|
| 0 | 8 | `JBSKIN1` followed by NUL |
| 8 | 1 | Image count, 22–214 |
| 9–14 | 6 | Path/track widths, filename offset/width, duration offset (255 disables), pointer enabled |
| 15–19 | 5 | Normal background/foreground, selected background/foreground, progress span |
| 20 | 2 | Pointer X |
| 22 | 1 | Status font: 0 = legacy 5×8, 1 = playlist 6×12 |
| 23–31 | 9 | Reserved, all zero |
| 32 | 285 | 19 text roles, 15 bytes each |
| 317 | 24 | Six art origins, two u16 coordinates each |
| 341 | 856 | 214 image width/height pairs; unused pairs zero |
| 1197 | 192 | 16×12 backdrop tile references; 255 is a black tile |

A text role contains six u16 values (text X/Y, rectangle left/top/right/bottom),
then byte-sized cell count and two stock mode-20 palette indexes. Rectangle ends
are inclusive. An omitted count role is fifteen zero bytes. The exact role order
is declared by `TEXT` and `ART` in `scripts/skin_schema/runtime.py`.

The first 22 images follow the canonical role order: idle/pause/play, shuffle
off/on, loop off/on, twelve volume states, progress track/marker, selection pointer.
Decorative images follow, each 32×32. Runtime export rejects another control order;
reorder the authoring assets and rebuild before exporting. `--skin ID` exports
another already compiled definition within these bounds. Runtime support does
not require another executable or a change to player logic.

All image dimensions are bounded to 512×64; total main bitmap payload is at most
256 KiB. The pointer is 10×12. Playlist glyphs retain the fixed 190-image 6×12
contract; loose fonts are exactly 2,048 and 3,072 bytes. The target validates all
coordinates, text extents/widths, palette indexes, optional fields, row ordering,
control-state dimensions, tile references and marker travel before issuing VDP
commands. It constructs commands from fixed templates; layout files contain no
CPU pointers or executable command streams. Header/length failures are 0x60;
invalid descriptor values are 0x61. Existing file/AGNB errors remain applicable.

Resource ownership: main images 0x2100–0x21D5, fonts 0x21F0/0x21F1, static commands
0x2200, mode callback 0x2201, playlist images 0x2300–0x235E and 0x2400–0x245E,
contexts 1–4 and sprite 0. Teardown removes the callback, releases the complete
owned bank, restores the previous display mode and waits for its mode reply.
The selection arrow uses the established VDP sprite path; hardware sprite mode
and playback effects remain separate work.

## Qualification

```sh
PATH="$HOME/.local/bin:$PATH" TMPDIR=/tmp .venv/bin/python tests/runtime_contract.py .emulator/runtime-contract-new
PATH="$HOME/.local/bin:$PATH" TMPDIR=/tmp .venv/bin/python tests/run_emulator.py .emulator/runtime-70-new --skin seventies --runtime
PATH="$HOME/.local/bin:$PATH" TMPDIR=/tmp .venv/bin/python tests/run_emulator.py .emulator/runtime-deco-new --skin artdeco --runtime
```

Use fresh destinations. The target contract suite includes malformed descriptors,
real MOS chooser input, cwd preservation, K dispatch and alternating load/cleanup
cycles. Each skin also runs the existing 26 playback scenarios and native pixel
checks. Results are retained in `tests/runtime-skin-evidence/`. Listening review
is separate from functional timing/accounting checks. No hardware deployment was
performed for this increment. The Author accepted emulator launch and skin
switching on 2026-09-14 and authorized commit and push. Hardware qualification
and broader audio-performance characterization remain separate work.

## Status-font extension

Descriptor byte 22 chooses the status font for all non-list text roles. Existing
packages leave it zero and retain 5×8. Nineties sets it to one and reuses the
existing normal 6×12 playlist glyph bank/context; no additional glyph memory or
font files are needed. The compiler derives this value from the widgets' `cell`
values. All status roles must agree; 6×12 colors must match normal playlist
glyphs. Target validation checks the selected width/height and rejects invalid
font values and mismatched glyph colors before drawing. Older executables reject
these new packages because the previously reserved byte is nonzero; use the
updated executable. Existing package bytes and typography remain unchanged.

# Configuration and skin loading

Jukebox reads **`/bin/jukebox.cfg`** regardless of its executable location or
launch directory. MOS command lookup selects `jukebox.bin`; the adjacent
`.cfg` file is data. The example configuration is:

```ini
format=1
skin_dir=/jukebox/skins/artdeco
music_dir=/music
```

| Key | Requirement | Meaning |
| --- | --- | --- |
| `format` | Required, exactly `1` | Configuration version |
| `skin_dir` | Required absolute SD path | Directory containing `skin.cfg` and its assets |
| `music_dir` | Optional absolute SD path | Initial browser directory; omit to preserve the launch directory |

Directories must exist. Missing or invalid configuration/assets produce a
readable error and return to MOS. There is no automatic fallback or recovery
chooser in this milestone. Asset lookup does not change directory; `music_dir`
is applied explicitly after skin loading.

## Text format

1. Use ASCII without a BOM, with LF or CRLF line endings. The final newline
   is optional. Blank lines and full-line comments starting `#` or `;` are
   accepted. Bare CR, NUL, DEL and non-ASCII bytes are errors.
2. Use one `key=value` per line. Spaces/tabs around the key/value are trimmed.
   Keys are case-insensitive; path case and embedded spaces are preserved.
   There are no quotes, escapes or inline comments. Values must be nonempty.
3. Duplicate keys are rejected. Unknown global keys are ignored and counted
   by the parser; the current application does not display that warning count.
4. A global configuration may contain at most 4,096 bytes, 32 distinct keys,
   255 bytes per logical line and 31 bytes per key.
5. Paths may contain at most 239 bytes and must start with `/`. A trailing
   slash is removed except at the root. Empty components, `.`/`..`, leading
   or trailing component spaces, trailing component dots and FAT-forbidden
   punctuation (`\ : * ? " < > |`) are rejected.

## Art Deco test manifest

The ordinary `app.asm` build now uses the bounded Art Deco profile:

```ini
format=artdeco-test3
graphics.file=graphics.agnb
font.file=fonts/neutrino_5x8.font
playlist.font.file=fonts/ArtDeco_Concept_02_6x12.font
playlist.graphics.file=fonts/ArtDeco_Concept_02_6x12.agnb
```

All five keys are required and unique; unknown keys are rejected. File and
path grammar/limits are the same as the Base manifest below. The compiled
profile uses Neutrino 5×8 for small fields (2,048 bytes) and the ArtDeco Concept 02
6×12 monochrome export for playlist metrics (3,072 bytes), each with 256
byte-indexed slots. The visible playlist glyphs come from the color AGNB.
The playlist has ten rows of 58 characters. Width cannot be inferred from
payload length; the compiled geometry is explicit. The manifest version
rejects older Art Deco and Base packages that lack the required font assets.

The graphics AGNB requires exactly 163 RGBA2222 records at IDs 0x2100–0x21A2,
matching `src/ui/artdeco/image-meta.bin`. The playlist AGNB requires 190 opaque
6×12 RGBA2222 records matching `src/ui/artdeco/playlist-meta.bin`: ASCII 32–126
in normal colors at IDs 0x2300–0x235E and selected colors at 0x2400–0x245E.
Each container's record metadata, payload boundaries and exact end are checked.
Missing, malformed or substituted assets cause an error and return to MOS.

Small text uses font buffer 0x21F0 in context 1. Normal and selected playlist
rows use contexts 3/4, both with font 0x21F1 supplying six-pixel advance and
12-pixel height. Their separate bitmap-character maps contain preblended Agon64
glyphs; changing the highlight selects a context and prints the row normally.
Bytes outside printable ASCII display as `?`. Art uses context 2; static
application commands use 0x2200. The first 128 decorative images map to printed
characters in the art context; the remaining tiles use direct plots. Cleanup
retires all four owned contexts, fonts and both sets of bitmap buffers.

This is a basic test profile with provisional information placement and no
on-screen control legends. F1/modal help is a possible later addition. General
runtime layout selection remains open: using the Base skin requires assembling
`app_base.asm` and selecting its matching package/configuration.

## Retained Base manifest

The accepted Base profile's directory contains:

```ini
format=skin004-proof1
graphics.file=graphics.agnb
font8.file=fonts/body8x8.font
font14.file=fonts/body8x14.font
```

This provisional manifest is preserved from the accepted functional test. All
four keys are required and unique; unknown keys are rejected. It follows the
same ASCII/comment/whitespace rules, with a 1,024-byte file limit and 255-byte
line limit. Filenames are relative to `skin_dir`, at most 127 bytes, without
traversal. Each joined path must fit the global 239-byte bound.

Graphics load exclusively through an AGNB 0.1 image container. The present
Base consumer requires exactly 67 RGBA2222 records at IDs 0x2100–0x2142, with the
dimensions and lengths recorded in `src/ui/image-meta.bin`. It checks metadata
before uploading each payload and rejects extra, missing or substituted
records. Fonts are currently permitted as loose files: exactly 2,048 bytes
for 8x8 and 3,584 bytes for 8x14, at IDs 0x21F0 and 0x21F1.

The renderer uses contexts 1/2 and application drawing buffer 0x2200. Audio
owns 0x3000–0x3003 separately. Cleanup releases those owned resources without
clearing unrelated buffers. Skin discovery, switching, arbitrary layouts and
a final public package ABI remain unfinished.

## Assembly interface

`src/asm/jukebox_cfg.inc` supplies `jcfg_load`, `jcfg_parse`, `jcfg_init`,
`jcfg_check_skin`, `jcfg_manifest_path` and `jcfg_apply_music`. Public routines
preserve BC, DE, HL, IX and IY, return A=0/Z on success or A=status/NZ on failure,
and set `jcfg_error`. They are synchronous, non-reentrant foreground operations.
The module owns its buffers and file/directory structures. Failed close calls
retain the object and pending flag so a later reset/load can retry safely.

Global errors 1–18 distinguish missing/open/read/close failures, text and path
validation, missing settings and directory failures. Skin-loader errors also
include AGNB validation and the consumer's 0x41–0x53 file/metadata/VDP errors.
The displayed hexadecimal code identifies the failing operation; correct the
configuration or package and run `jukebox` again.

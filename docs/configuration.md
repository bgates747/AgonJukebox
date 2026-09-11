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
format=artdeco-test2
graphics.file=graphics.agnb
font.file=fonts/neutrino_5x8.font
playlist.font.file=fonts/Lat7-Terminus12x6_6x12.font
```

All four keys are required and unique; unknown keys are rejected. File and
path grammar/limits are the same as the Base manifest below. The compiled
profile uses Neutrino 5×8 for small fields (2,048 bytes) and Lat7 Terminus
6×12 for playlist rows (3,072 bytes), each with 256 byte-indexed slots.
The playlist has ten rows of 58 characters. Width cannot be inferred from
payload length; the compiled geometry is explicit. The manifest version
prevents loading older one-font Art Deco or Base packages with this layout.

The AGNB consumer requires exactly 163 RGBA2222 records at IDs 0x2100–0x21A2,
matching `src/ui/artdeco/image-meta.bin`. Metadata and payload boundaries are
validated before upload. Small text uses font buffer 0x21F0 and the playlist
uses 0x21F1. Text and art contexts are
1/2; static application commands use 0x2200. The first 128 images map to printed
characters in the art context; the remaining decorative tiles use direct plots.

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

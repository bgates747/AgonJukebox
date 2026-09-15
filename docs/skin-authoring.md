# Declarative skin authoring v1

The shared compiler reads a `skin.json` and prepared artwork. Art Deco and
Seventies use this path; their original artwork, accepted runtime packages and
player behavior are preserved. A new definition generates its own application
entry point without edits to shared player assembly. This is a **compile-time
layout contract**, not runtime skin switching or a final portable skin ABI.

## Build and review

Use the project `.venv` with Pillow and editable canonical `agon-utils`:

```sh
.venv/bin/python scripts/skin_schema/compile.py src/skins/seventies/skin.json
```

The old per-skin `build.py` paths are thin compatibility entry points. Use
`--output-root /tmp/skin-repeat` to isolate generated outputs. Inputs are resolved
relative to the definition and cannot escape that directory through traversal
or symlinks. Normal assembly needs only the checked-in generated output.
The compiler uses the sibling AGNB writer/validator/parser and Agon image
conversion. It no longer depends on the font editor's Python API at build time.

Outputs are `skins/<id>`, `src/ui/<id>`, `src/skins/<id>/generated`, and
`tests/fixtures/<id>`. New IDs also generate `src/asm/app_<id>.asm` and
`tests/asm/<id>_check.asm`. For normal project-root output, assemble the generated
entry from `src/asm`. An isolated output root contains generated artifacts;
assembly also needs the shared runtime source and vendor includes.

Open `src/skins/<id>/generated/index.html` in a browser. It provides source,
prepared-background, compiled-preview and test-state comparisons, previous-view
toggling, target/source-sized/pixel zoom and actual output swatches. Previews
are host renders, not screenshots. Full images are linked.

## Definition and validation

[skin.schema.json](../scripts/skin_schema/skin.schema.json) is the structural
JSON Schema. [validate.py](../scripts/skin_schema/validate.py) is the mandatory
semantic validator: it also checks files, pixels, role completeness, state
sizes, text bounds, font backgrounds, field overlap and marker travel.
Unknown or duplicate keys, unsafe names/paths and invalid definitions fail.

| Field | Meaning |
| --- | --- |
| `schema_version` | Authoring contract version, currently 1 |
| `id` | Safe output namespace, independent of the artwork |
| `runtime_format` | Existing package compatibility tag; new IDs use `schema-test1` |
| `source` | Preserved reference image for review; not reprocessed during compilation |
| `backdrop` | Prepared static artwork, with application state removed |
| `fonts` | Exported small/playlist font bytes and normal/selected RGBA glyph sheets |
| `palette` | Normal and selected playlist backgrounds/foregrounds, all Agon64 |
| `assets` | Named opaque control states plus the transparent selection arrow |
| `widgets` | Semantic roles, position, font cell, field length and restoration rectangle |
| `playlist` | Filename offset/width and optional eight-character duration column |
| `selection` | Optional arrow visibility and horizontal position; row positions supply Y |
| `progress_span` | Bounded marker travel in pixels |
| `review` | Illustrative and test text/state plus timing-sensitive pixel exclusions |

A text widget declares `name`, `kind`, `x`, `y`, `n`, `bg`, `fg`, `rect`, `cell`
and `slot`. `rect` is `[x,y,width,height]`; the text must fit inside it. An art
widget declares `name`, `kind`, `x`, `y`, `asset`. The required roles are the ten
`w_row0`–`w_row9` entries, path/page, track/message, elapsed/duration, detail,
volume text and play/shuffle/loop/volume/progress/marker art. `w_count` is optional.
Rows are ordered and do not overlap; they need a blank restoration margin to
the left for qualification. State assets use the existing fixed semantic names
(`idle`, `play`, `pause`, on/off shuffle and loop, twelve volume levels, progress
track/marker and selection pointer). State variants have identical dimensions.

Small fonts contain 256 glyphs × eight MSB-first bytes. Playlist metric fonts
contain 256 × twelve bytes. Visible playlist glyphs come from 96×192 RGBA sheets,
16 columns of 6×12 cells, ASCII 32–126. The space glyph's pixels must agree with
its playlist background. The compiler never rescales fonts or reapplies source
crop recipes. Other preparation tools may produce these inputs.

## What remains deliberately bounded

1. Screen: 512×384; ten rows, 58 columns, 6×12 playlist; status roles select a common 5×8 or 6×12 cell.
2. Rows may have different Y positions, but their origins remain within 0–255
   because the retained sprite packet updates one Y byte. Pointer is 10×12.
3. Fixed playback vocabulary and twelve volume levels. Message/detail/volume
   text and time widths retain their existing formatting contracts. Filename
   fields leave at least six characters after the directory prefix.
4. Packets are at most 96 bytes. Compiler-assigned IDs preserve the existing
   context/font/buffer ownership, with exact metadata and payload validation.
5. A skin definition does not introduce executable scripting, a new widget
   type, runtime discovery/switching, gradients or hardware-sprite enablement.
6. Review test fields must describe the shared harness's paused state; arbitrary
   geometry changes may require updated expected text and exclusion rectangles.
   These are test data, not claims that the runtime is automatically observed.

## Prepared-art provenance

The two migrated skins' `prepared/provenance.json` records exact input hashes
and accepted commit `5df71d5`. Their control PNGs and glyph sheets were decoded
losslessly from accepted AGNB files; backgrounds/font bytes were copied unchanged.
This makes the compiler independent of the earlier per-artwork cleanup recipes.
Original sources remain in place; those recipes remain recoverable from Git at
that commit and the earlier review packets. Preparing a new source picture is
still an authoring/review step; the schema does not infer state text or shapes.
The previous `--playlist-font concept-01` switch is replaced by choosing prepared
font inputs in a definition; historical font source files are preserved.

## Qualification

```sh
.venv/bin/python -m unittest scripts.skin_schema.test_schema -v
.venv/bin/python scripts/skin_schema/prove_third.py /tmp/third-skin
.venv/bin/python scripts/skin_schema/compile.py /tmp/third-skin/skin.json
```

The third proof changes rows, path/track widths, filename layout and progress
span, and omits the duration column/count/visible arrow using only definition
changes. The generated `schema_proof_check.asm` runs the same 26-scenario harness.
Use `tests/functional.py prepare ... --skin schema_proof` with a fresh SD tree.
Use `tests/run_emulator.py .emulator/new-schema-check --skin schema_proof` to
run that suite in a fresh canonical headless profile. The runner terminates its
emulator at completion. Never run it against hardware as part of authoring validation.

`check_regression.py --baseline 5df71d5 --output PATH` verifies both accepted
packages, six pixel-identical previews/backgrounds and all six byte-identical
application/test binaries, including Base. `TMPDIR=/tmp` and ez80asm 2.2 on PATH
are required on this Mac. Exact image file compression may differ with Pillow;
the regression checks decoded pixels as well as exact runtime bytes.

## Runtime package export

After compiling a definition, use `scripts/skin_schema/runtime.py --skin ID`
to export its bounded runtime-v1 package for the shared executable. See
[runtime skins](runtime-skins.md) for the additional package/resource bounds,
installation and chooser controls. The accepted authoring schema is unchanged.

Status fields may now all use `cell: [6,12]` to share the normal playlist glyph
bank, or retain `[5,8]`. Mixed status metrics are rejected in this bounded
version. Shared 6×12 text must use the normal playlist foreground/background.
Increase restoration rectangles to the actual cell extents; changing the cell
alone is insufficient. Existing definitions require no edits. Custom per-skin
fonts remain a later authoring step; glyph reuse is implemented now.

The message widget `w_message` is optional, like the count field. Omit it from
the authoring widget list and preview states to suppress the strip entirely.
Runtime descriptors encode absence as fifteen zero bytes in text record 13;
nonzero geometry with zero width is rejected. Existing packages are unchanged,
and older loaders reject absent-message packages safely. The updated loader
builds a zero-length send for an absent message; the compile-time generator
retains a non-rendering producer slot.

Status widgets may independently select 5×8 or normal-bank 6×12 cells. Runtime
byte 22 preserves the all-large default; bytes 23..25 hold a little-endian mask
indexed by text-record number. Only status bits 0..2 and 13..18 are valid;
playlist/unused bits are rejected. A set bit selects 6×12. Export retains old
bytes for uniform-font definitions. Earlier loaders safely reject mixed packages.
RATE (`w_detail`) may display 13..23 cells; its producer still has 23 bytes of
storage, with compile-time padding excluded from the VDU send length.

Numeric volume status (`w_voltext`) may also be omitted: text record 18 must
then be all zero. The volume control/indicator remains required and functional.

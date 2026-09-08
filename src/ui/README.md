# Application UI inputs

These are the frozen drawing inputs of the functional milestone accepted on
2026-09-08. They assemble into application commands, not bitmap/font payloads.

| File | Contents |
| --- | --- |
| `static.vdu` | 4,103 bytes of frames, branding and fixed instructions, installed in VDP buffer 0x2200 |
| `contexts.vdu` | Text/art contexts, font selection and printed bitmap mappings |
| `cleanup.vdu` | Scoped retirement of application skin resources |
| `image-meta.bin` | 67 expected records: u16 ID, u16 width, u16 height, u8 format, u32 payload size |

`src/asm/ui_widgets.inc` holds the corresponding mutable widget packets,
field offsets and character-role constants. `src/asm/layout.inc` supplies live
state values and emits complete packets of at most 96 bytes. A selection
move redraws two rows (192 bytes); an elapsed/progress update costs 81 bytes.
Those counts cover outgoing UI commands, excluding audio and VDP replies.

The approved geometry is 512x384, ten 8x14 text rows, screen blue #0000AA and
separate text/art contexts. Runtime graphics and fonts are in `skins/base`.
These checked-in inputs make the normal build reproducible without private
generation scripts. A general skin authoring tool and package ABI remain
separate unfinished work.

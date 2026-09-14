# Seventies vector candidate — 2026-09-14

Human visual/audio review pending; no hardware access or commit.

The native functional run passes 26 scenarios, 7,905 widget pixels and 6,922
font pixels. Fractional playback accounting remains exact. The runtime executable
is unchanged from the Nineties status-font candidate.

The native contract run passes 46 descriptor cases, two partial-load cleanup
cases, chooser behavior and four Nineties/Seventies/Art Deco/Nineties load cycles.
It additionally exercises production ui_copy with short, exactly 56-character
and deeply nested overlong paths, comparing all 56 cells plus a guard byte.
Overflow uses the existing trailing ellipsis. The legacy malformed-descriptor
baseline is frozen in tests/fixtures/runtime-legacy-layout.bin so artwork/layout
redesigns do not invalidate those independent rejection cases.

22 compiler outputs and the SVG authoring outputs reproduce byte-for-byte.
Original concept, previous source PNG and font bytes are preserved. Eight exact
Agon colors; SVG contains outlined lettering and geometric paths, no raster.
Art provenance and deployment/runtime hash are recorded alongside the logs.

An initial functional attempt used an output path too long for the assembler;
the short isolated sv01 profile completed successfully. Fab's known shutdown
mutex diagnostic occurs after PASS and is preserved. These results do not
establish audio quality; listening review remains separate.

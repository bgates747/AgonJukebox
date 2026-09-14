# Nineties rack-stereo prototype

Original concept in source.png; Author-approved coordinate-authored geometry in
nineties-redraw.svg and approved-redraw.png. The lower center panel stays plain grey.
Prepared artwork accommodates ten 58-column rows and 6×12 Terminus status text.
The top meter uses the full display height; this skin omits the optional message
strip. The directory icon and 53-column current path occupy the former NOW PLAYING
heading, with RATE in the vacated footer. Long paths retain trailing ellipsis.
The mock CD deck duplicates the tape deck’s two keys and single inset LED.
The meter/LED artwork is decorative; it does not claim signal analysis.

A single 93×30 state bitmap spans both play and pause buttons: idle has white
symbols, playing has a green triangle and white pause bars, paused has a white
triangle and green bars. Legacy asset role names identify the offered action,
so `pause.png` is selected while playing and `play.png` while paused.

Build with the common compiler and export for the updated runtime:

```sh
.venv/bin/python src/skins/nineties/build.py
.venv/bin/python scripts/skin_schema/runtime.py --skin nineties
```

Use the new jukebox-runtime.bin: descriptor byte 22 requests 6×12 status glyphs.
Old executables correctly reject this package. Other packages retain their selected status fonts.
Normal/selected playlist glyphs and status glyphs share the existing font banks;
no new font memory is needed. Prepared inputs suffice for repeat compilation;
private source-art recipes and provenance remain in SKIN-023.

Emulator qualification is recorded under tests/nineties-evidence. Author review
of this deployed candidate is pending. Custom fonts and animated meter behavior
are deferred. No hardware deployment is authorized or claimed.

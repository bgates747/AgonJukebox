# Nineties rack-stereo prototype

Original concept in source.png; Author-approved coordinate-authored geometry in
nineties-redraw.svg and approved-redraw.png. The lower center panel stays plain grey.
Prepared artwork accommodates ten 58-column rows and 6×12 Terminus status text.
A separate message line sits below the condensed top meter. The meter/LED artwork
is illustrative; it does not claim signal analysis or animation.

Build with the common compiler and export for the updated runtime:

```sh
.venv/bin/python src/skins/nineties/build.py
.venv/bin/python scripts/skin_schema/runtime.py --skin nineties
```

Use the new jukebox-runtime.bin: descriptor byte 22 requests 6×12 status glyphs.
Old executables correctly reject this package. Existing skins retain 5×8 status.
Normal/selected playlist glyphs and status glyphs share the existing font banks;
no new font memory is needed. Prepared inputs suffice for repeat compilation;
private source-art recipes and provenance remain in SKIN-023.

Emulator qualification is recorded under tests/nineties-evidence. Author review
of this deployed candidate is pending. Custom fonts and animated meter behavior
are deferred. No hardware deployment is authorized or claimed.

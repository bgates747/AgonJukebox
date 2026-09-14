# PCB prototype

Candidate 2 (bright traces / warm gold) selected by the Author on 2026-09-14.
`source.png` preserves the original concept; `candidate-2.png` preserves the
selected 512×384 color review. `prepared/` contains the static backing, original
font bytes, recolored glyph sheets and complete control-state inputs.

```sh
.venv/bin/python src/skins/pcb/build.py
.venv/bin/python scripts/skin_schema/runtime.py --skin pcb
```

Uses the shared runtime executable unchanged. Install `skins/runtime/pcb` beside
the other runtime skins and select it with K, or configure its directory at startup.
The normal state is black/cream; selection and enabled modes use bright green.
Source playlist rules are cleared for the existing ten-row 58-column font layout.
The baked arrow and progress fill are replaced with independent dynamic assets.
The arrow uses the existing VDP sprite path; hardware sprite mode is not enabled.

The private authoring record retains the source segmentation and preparation
recipes. `prepared/provenance.json` records source and selected-candidate hashes.
Prepared assets and skin.json are sufficient for normal reproducible compilation.
Graphical/audio acceptance remains pending; no hardware qualification claimed.

# PCB prototype

Candidate 2 supplies the original board artwork and Agon palette. The approved
selective revision preserves its capacitors, ICs, traces, resistor leads and
NOW PLAYING banner. Four symmetric resistor bodies and the central information
panel are replaced with manually authored shapes in `selective-overlays.svg`.
The earlier full redraw in `pcb-vector-candidate.svg` is historical, not active.

`prepared/` contains the final backing, glyph sheets and complete control states;
`skin.json` defines the layout. These inputs are sufficient to reproduce the
compiled skin without the private review scripts.

```sh
.venv/bin/python src/skins/pcb/build.py
.venv/bin/python scripts/skin_schema/runtime.py --skin pcb
```

The central panel uses normal 6×12 text: a 37-cell directory path, a 40-cell
track/status line and separate elapsed/duration fields. The runtime's existing
PLAYING/PAUSED prefix remains on the track line. File count and pagination occupy
separate footer lines; RATE uses 13 cells. Numeric volume and message are omitted.

Transport geometry comes from `../shared/transport.svg`, recolored cream/copper
with black neutral ink and green active ink. Both play and pause symbols remain
visible; only the active state is green. Shuffle/repeat retain separate on/off
states; the volume indicator has eleven segments. Progress uses a 240×3 track
and a 3×3 moving marker. Input behavior is unchanged.

Install `skins/runtime/pcb` beside the other runtime skins and select it with K,
or configure its directory at startup. The selection arrow remains on the
existing VDP sprite path; hardware sprite mode is not enabled.

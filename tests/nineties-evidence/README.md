# Nineties and shared status-font qualification

Nineties uses the approved geometric artwork and 6x12 status font, reusing the
normal playlist glyphs. The runtime executable gains a validated font-selection
byte; previous package bytes remain unchanged.

- Nineties: 26 playback scenarios, 7,927 widget pixels and 6,922 font pixels pass.
- Legacy Seventies on new executable: 26 scenarios, 6,978 widget and 6,922 font pixels pass.
- Host schema tests: six methods, including large-font extent, mixed-font and
  glyph-color rejection, pass.
- Contract: 46 descriptors, partial asset failure cleanup, discovery, real MOS
  chooser refresh/select/cancel, cwd/mode restoration and four load cycles pass.
- All 24 Nineties compiler outputs repeat byte-for-byte.

The initial Nineties run failed step 0B while the prior graphical PCB emulator
was still running. Isolated rerun passes without changing assertions or timing.
Both logs retained; cause is not proven. The initial contract run passed its 46
descriptors then found four packages while the historical assertion expected
two. Discovery setup now explicitly installs its two intended fixtures instead
of copying every local package; the full rerun passes.

Logs retain the known Fab mutex diagnostic after successful app/test shutdown.
Listening and graphical review are separate. No hardware access occurred.

Reproduce with fresh paths:
```sh
PATH="$HOME/.local/bin:$PATH" TMPDIR=/tmp .venv/bin/python tests/run_emulator.py .emulator/new-nineties --skin nineties --runtime
PATH="$HOME/.local/bin:$PATH" TMPDIR=/tmp .venv/bin/python tests/runtime_contract.py .emulator/new-nineties-contract
```

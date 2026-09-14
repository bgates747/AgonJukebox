# PCB candidate qualification

2026-09-14: stock local Fab/MOS, unchanged runtime executable, PCB external package.
All 26 functional scenarios, 6,977 widget pixels and 6,922 font pixels passed.
Exact fractional sample accounting passed. 24 generated compiler outputs reproduce
byte-for-byte in an independent output directory; deployed package/binary bytes match.

The log retains Fab's known mutex diagnostic after successful PASS and application
shutdown. This does not establish listening quality; Author emulator review is pending.

```sh
PATH="$HOME/.local/bin:$PATH" TMPDIR=/tmp .venv/bin/python tests/run_emulator.py .emulator/pcb-functional-new --skin pcb --runtime
```

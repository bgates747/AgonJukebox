# Runtime skins candidate evidence

Author accepted runtime launch and switching on 2026-09-14 and authorized commit
and push. Baseline schema commit is 166a5ed. `candidate.json` records exact production/package hashes and
repeat-build verification. Production binary: 62,622 bytes; end below 0x06FF00.

1. `seventies-functional.log`: all 26 scenarios, 6,978 widget pixels and 6,922
   font pixels pass. Exact fractional read accounting passes.
2. `artdeco-functional.log`: all 26 scenarios, 6,975 widget pixels and 7,124
   font pixels pass. Exact fractional read accounting passes.
3. `contract.json` / `contract.log`: 40 descriptor cases (two valid and 38
   malformed), cleanup after two partial asset failures, discovery/cwd checks,
   chooser refresh/select/cancel through MOS input, K dispatch, and four
   alternating skin load/cleanup cycles pass with mode restoration.
4. `baseline.json`: all 27 accepted package/fixture files, six rendered images
   and six compiled prototype app/test binaries retain their accepted bytes or
   pixels. Five existing schema test methods also pass.

Reproduction is in docs/runtime-skins.md. All runs use the canonical profile
wrapper, stock Fab 1.2.4, MOS 3.0.2 and VDP 2.16.0. Each functional harness binds
its own expected image samples; runtime player code is shared. The contract
binary loads both packages in one process. The production review uses one
app_runtime binary and external packages.

Earlier local attempts remain in .emulator/runtime-*: Art Deco initially exposed
an overly restrictive page-width check, then an unbracketed assembler expression
in pointer validation. Both were corrected without changing expected artwork or
assertions. Runtime-deco-03 hit a relative-branch assembly limit during diagnostic
instrumentation; runtime-contract-01 used an overlong assembler output path.
Final source uses explicit bounds, a wide branch and a short relative build path.
Temporary diagnostics were removed before final qualification.

Fab emits its existing libc++ mutex shutdown diagnostic after PASS when the test
runner terminates it. This is retained in raw logs. Listening performance is not
established by these automated checks; no hardware access or deployment occurred.

Published text logs normalize line endings to LF and trim trailing whitespace;
original byte streams remain in the corresponding local emulator profiles.

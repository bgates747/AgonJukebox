# WAV reader TODO

These items are deliberately separate from the WAV reader reference. They are
open validation questions to evaluate against AgonVideo's controlled WAV input
contract, not assertions that the current implementation is defective.

- [ ] Decide whether `verify_wav` should check the `FRESULT` returned by
  `ffs_fopen` and `ffs_fread`, and verify that the initial read returned all 76
  header bytes before inspecting the header buffer.

- [ ] Decide whether the controlled input contract is sufficient, or whether
  `verify_wav` should explicitly validate any of: 8-bit depth, `fmt_size`, the
  `data` marker, `data_size`, block alignment, and byte rate.

- [ ] Decide whether streaming should remain zero-byte-read terminated or stop
  at the declared WAV `data_size`. Consider how either choice should behave for
  truncated files, trailing chunks, and read errors.

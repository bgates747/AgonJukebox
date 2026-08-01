# AgonJukebox TODO

This is the authoritative list of unfinished promoted work. WAV items are
deliberately separate from the normative reader reference; player items are
acceptance gates for the current `wavonly` candidate.

## WAV format and reader

Observed on 2026-08-01: all four WAVs in the ignored emulator test profile have
their PCM payload at byte 78. `Africa_65535.wav` and the Lynyrd Skynyrd file
carry a 14-byte `ISFT` value; `Rhiannon.wav` and `Wild_Flower.wav` carry a
13-byte value plus its alignment pad. In both layouts, the `data` header begins
at byte 70 and its payload at byte 78. The current reader accepts the files but
begins streaming at byte 76, prefixing the final two bytes of `data_size` to the
audio stream. This makes the input-contract question below concrete; the
WAV-only reduction deliberately does not resolve it.

- [ ] **WAV-001:** Decide whether `verify_wav` should check the `FRESULT`
  returned by `ffs_fopen` and `ffs_fread`, and verify that the initial read
  returned all 76 header bytes before inspecting the header buffer.

- [ ] **WAV-002:** Decide whether the controlled input contract is sufficient,
  or whether `verify_wav` should explicitly validate any of: 8-bit depth,
  `fmt_size`, the `data` marker, `data_size`, block alignment, and byte rate.

- [ ] **WAV-003:** Decide whether streaming should remain zero-byte-read
  terminated or stop at the declared WAV `data_size`. Consider how either
  choice should behave for truncated files, trailing chunks, and read errors.

- [ ] **WAV-004:** Choose one canonical payload-offset policy: normalize input
  files to the player's assumed byte-76 layout, or locate and parse the `data`
  chunk dynamically. Validating a fixed `data` marker alone will not correct
  the two-byte skew in the current emulator fixtures.

## WAV-only candidate acceptance

- [ ] **PLAY-001:** On physical hardware, test an in-session rate sequence of
  `Africa_65535.wav` (65,535 Hz), the Lynyrd Skynyrd file (44,100 Hz), one of
  the 48,000 Hz files, and then Africa again. Confirm intended pitch and the
  displayed rate after every transition.

- [ ] **PLAY-002:** Play the full Lynyrd Skynyrd album fixture on physical
  hardware through EOF and automatic progression. Confirm continuous audio,
  stable timing, and no one-second gap/repeat artifacts for the entire
  long-form run.

- [ ] **PLAY-003:** Quit the candidate on physical hardware, launch and exit a
  separate stock-VDP application, and confirm normal screen, keyboard, timer,
  and audio behavior with no stuck channel.

- [ ] **VDP-001:** Pre-populate one or more non-jukebox VDP buffers with a known
  sentinel payload, then launch the candidate without resetting the VDP. Play
  `Africa_65535.wav` long enough to exercise repeated swaps of both 65,535-byte
  audio buffers; confirm the font/logo render, audio remains continuous, and
  the sentinel survives after exit. Increase the unrelated allocation until a
  meaningful memory-pressure boundary is established. If any jukebox
  allocation or streaming path fails, restore intentional clear-all at startup
  while retaining scoped cleanup on exit. Record the winning base-player
  policy so later optional modules inherit it.

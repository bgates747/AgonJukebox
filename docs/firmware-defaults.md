# Firmware defaults

Use these firmware defaults for current Jukebox testing and deployment. They
identify the intended environment; they do not certify a candidate or authorize
a test, flash, deployment or hardware checkout. The selection comes from the
Author's 2026-11-08 instruction and its published async-r1 amendment.

1. **Alexe, Olimex and Console8: VDPlet v0.1.2-alpha.** Use the versioned
   `vdp-vdplet-0.1.2-alpha.bin` release asset and check the release SHA256SUMS.
   Selection: **0.1.2-alpha-async-r1**. Size: 1,115,568 bytes. SHA256:
   `dc43ecb8b1c324ffd1a032e6cc0c56d8c05dd33a355ce170c23adb35ffb533ab`.
   [Release](https://github.com/bgates747/agon-vdplet/releases/tag/v0.1.2-alpha).
2. **Alexe and Console8: Eirene MOS 3.1.0_uart0_rc_3.** Extract `mos-rc3.bin`
   from the versioned release ZIP. Size: 100,879 bytes. SHA256:
   `d7a51147f3381cd68d56f3fbe4605434a897dfae1b049269afeba09ec2b7eb50`.
   [Release](https://github.com/bgates747/eirene-mos/releases/tag/3.1.0_uart0_rc_3).
3. **Olimex: latest approved integrated EMOS, maintained by its scheduling
   owner.** The audited selection is Eirene r04, full ROM 131,072 bytes, SHA256
   `a25f1612f4aaa542c5488cf3266d968ad3d1d61e9df3b5ce2c680650f5d7a2ca`.
   That snapshot includes RFC25 output and excludes old RC2 42h/43h. Read the
   owner's current selector before scheduling; this snapshot is not a reason
   to pin an obsolete EMOS after the owner approves an update.

The same tag/URL was amended: source now resolves to
`60e5b4ebafa3e1c8bb740e45260d78cdb6125e30`. Re-download the release assets and
verify current SHA256SUMS; a cached version label alone cannot identify them.
The old 1,100,304-byte `b004570b…` image is superseded, not requalified.

The current release retains UART RX recovery, pixels, text96, borrowed rows and
READ_BYTES, and now enables ordinary async OPEN/SUBMIT/PUBLISH/STATUS/STOP/CLOSE
(ABI1.7, capability799; earlier finite ABI0..6 views retained). Ordinary async
still has its exact320×240 double-buffer/context/lifetime constraints; it is not
a general arbitrary-resolution async interface. Worker-only COMPUTE restrictions
remain. Private384-byte witnesses, quiet polling, counted return and PCM sink/
queues remain excluded. Current Jukebox uses standard buffered PCM commands;
this update does not add a Jukebox async-rendering or audio-streaming feature.
The combined image has no new Jukebox hardware/emulator qualification.

A required firmware exception must be named and justified in the scheduling
request. RC2-only and private experimental MOS clients need an explicit ABI
exception; a vanilla UART1-owning application is not safe on an EMOS-owned port.
Never replace Olimex EMOS with bare MOS as an implicit workaround. The current
RFC player also needs EMOS admission-status handling: an ignored refusal can
leave its callback wait hanging. Bare RC3 has different A-return semantics.
See the audit before treating the same binary as qualified for both.

Existing emulator profiles and frozen packages may still contain older firmware.
Review their exact composition before reuse. Native emulator VDP modules must
be prepared from the matching release source/features; an ESP32 `.bin` cannot
be substituted for a host `.so`. Profile changes retain their human-review gate.
Historical passing runs keep their original firmware identities.

The RX recovery change concerns the mainboard VDP's UART receive path. It does
not establish a fix for the Console8 ESP8266/UART1 baud-confirmation failure.
The network receiver still needs that diagnosis and manual review.

See [machine-readable pins](firmware-defaults.json) and the
[compatibility audit](firmware-compatibility-audit.md).

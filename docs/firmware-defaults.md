# Firmware defaults

Use these firmware defaults for current Jukebox testing and deployment. They
identify the intended environment; they do not certify a candidate or authorize
a test, flash, deployment or hardware checkout. The selection comes from the
Author's 2026-11-08 instruction and remains in force until changed.

1. **Alexe, Olimex and Console8: VDPlet v0.1.2-alpha.** Use the versioned
   `vdp-vdplet-0.1.2-alpha.bin` release asset and check the release SHA256SUMS.
   Size: 1,100,304 bytes. SHA256:
   `b004570b607b45bbd6e87a3c704b65b23d3221981db3aac6cf2578aa22d766e3`.
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

The VDP release includes UART RX-full recovery, pixels, text96, borrowed rows
and READ_BYTES. Its public ABI/wire versions are unchanged. Optional async
worker, counted return and PCM sink are disabled. The current Jukebox players
use standard buffered PCM commands and do not require those optional features.

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

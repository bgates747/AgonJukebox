# FW-001 — Audit Jukebox candidates against pinned firmware

Audit current production and test candidates against the required firmware
defaults before further testing or deployment. Identify which candidates fit
the public interfaces, which require explicit exceptions, and which need new
qualification. Existing hardware and emulator permissions remain unchanged.
This task authorizes the audit; it does not resume unrelated development.

## Required defaults — Author instruction, 2026-11-08

1. Alexe, Olimex and Console8: release **VDPlet v0.1.2-alpha**, verified against
   the release SHA256SUMS. Includes the UART RX recovery fix.
   Release: https://github.com/bgates747/agon-vdplet/releases/tag/v0.1.2-alpha
2. Alexe and Console8: release **Eirene MOS 3.1.0_uart0_rc_3**, using
   `mos-rc3.bin` from the release ZIP, exactly 100879 bytes, SHA256
   `d7a51147f3381cd68d56f3fbe4605434a897dfae1b049269afeba09ec2b7eb50`.
   Release: https://github.com/bgates747/eirene-mos/releases/tag/3.1.0_uart0_rc_3
3. Olimex: scheduling owner maintains this VDPlet release and latest approved
   EMOS incorporating current Eirene enhancements. Resolve exact approved
   identity through the owner; do not substitute a random build.
4. Any required exception must be explicitly identified and justified in its
   scheduling request. Prior results keep their actual firmware identities.

## Execution sequence

- [ ] **FW-001-S01 — Inventory candidates.** Include production Classic/skins,
  current runtime/RFC players, live UART/network/agonAMP tests, release
  packages and relevant deployment/emulator defaults. Distinguish active
  candidates from archived negative controls. Preserve dirty work.
- [ ] **FW-001-S02 — Verify firmware identities.** Retrieve official release
  metadata/assets, verify VDP firmware SHA256SUMS and exact ZIP MOS member.
  Record source/release identities and resolve approved Olimex EMOS defaults.
- [ ] **FW-001-S03 — Audit source contracts.** Inspect MOS calls, callbacks,
  vector/UART ownership, VDP commands/assets and version guards. Identify
  firmware-specific assumptions and explicit exceptions.
- [ ] **FW-001-S04 — Audit packaging and default drift.** Compare shipped or
  prepared firmware copies and maintained deployment/profile settings with
  the pins. Correct project guidance and safe packaging references; leave
  unreviewed executable/profile changes separate from this audit.
- [ ] **FW-001-S05 — Assess validation evidence.** Reuse exact source/build/
  returned-test evidence and run only checks already authorized. Static
  compatibility is distinct from execution against the new pins. No device
  flash, hardware run or emulator launch follows from this task alone.
- [ ] **FW-001-S06 — Publish dispositions.** Record a candidate matrix, actual
  firmware/checksum bindings, exceptions, unresolved failures and the next
  qualification needed. Update the authoritative TODO and local handoff.

## Acceptance

Every current candidate has a source/binary identity, compatibility disposition,
firmware exception if required, and an honest statement of remaining evidence.
Release assets are checksum-verified. Default instructions reflect the new pins.
No historical result is relabeled, unrelated development resumed, or execution
permission inferred from the firmware announcement.

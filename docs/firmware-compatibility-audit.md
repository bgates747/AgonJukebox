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

- [x] **FW-001-S01 — Inventory candidates.** Include production Classic/skins,
  current runtime/RFC players, live UART/network/agonAMP tests, release
  packages and relevant deployment/emulator defaults. Distinguish active
  candidates from archived negative controls. Preserve dirty work.
- [x] **FW-001-S02 — Verify firmware identities.** Retrieve official release
  metadata/assets, verify VDP firmware SHA256SUMS and exact ZIP MOS member.
  Record source/release identities and resolve approved Olimex EMOS defaults.
- [x] **FW-001-S03 — Audit source contracts.** Inspect MOS calls, callbacks,
  vector/UART ownership, VDP commands/assets and version guards. Identify
  firmware-specific assumptions and explicit exceptions.
- [x] **FW-001-S04 — Audit packaging and default drift.** Compare shipped or
  prepared firmware copies and maintained deployment/profile settings with
  the pins. Correct project guidance and safe packaging references; leave
  unreviewed executable/profile changes separate from this audit.
- [x] **FW-001-S05 — Assess validation evidence.** Reuse exact source/build/
  returned-test evidence and run only checks already authorized. Static
  compatibility is distinct from execution against the new pins. No device
  flash, hardware run or emulator launch follows from this task alone.
- [x] **FW-001-S06 — Publish dispositions.** Record a candidate matrix, actual
  firmware/checksum bindings, exceptions, unresolved failures and the next
  qualification needed. Update the authoritative TODO and local handoff.

## Acceptance

Every current candidate has a source/binary identity, compatibility disposition,
firmware exception if required, and an honest statement of remaining evidence.
Release assets are checksum-verified. Default instructions reflect the new pins.
No historical result is relabeled, unrelated development resumed, or execution
permission inferred from the firmware announcement.

## Published release amendment — async-r1

The VDP owner published Smith's directed amendment after the original audit:
the **same v0.1.2-alpha tag and URL now select 0.1.2-alpha-async-r1**. Future
fixtures/defaults use the replacement bytes. The earlier audit below remains a
record of the image actually inspected at that time.

- **FW-001-A01 — Verified replacement.** Downloaded the current release firmware
  and metadata. Firmware is1,115,568 bytes, SHA256
  `dc43ecb8b1c324ffd1a032e6cc0c56d8c05dd33a355ce170c23adb35ffb533ab`;
  source `60e5b4ebafa3e1c8bb740e45260d78cdb6125e30`. Current SHA256SUMS has SHA256
  `52438920e70480cd1c0f0c9543fbf2e0f7771ce937b92f422ef2f6ea394f79ba`.
  Firmware plus nine downloaded records match its entries; all eleven downloaded
  release assets also match GitHub sizes/digests. Debug ELF/map archives were not
  downloaded. Superseded records and original evidence are retained separately.
- **FW-001-A02 — Feature correction.** Ordinary async rendering is now enabled,
  ABI1.7/capability799, with earlier finite ABI0..6 views retained. Exact320×240
  double-buffer/context/ownership/lifetime requirements and restricted worker
  COMPUTE callbacks remain. Private384-byte witnesses, quiet polling, counted
  return and PCM sink/queues remain excluded. The old image's async-disabled
  statement is historical; it must not constrain future fixtures using async-r1.
- **FW-001-A03 — Consumer disposition.** Current Jukebox candidates do not use
  the newly enabled async-rendering API. Their ordinary-interface source findings
  remain applicable, with exact amended-pair execution still pending. The RFC
  EMOS admission gap, RC2/private-service exceptions and vanilla UART1 ownership
  conflict remain open. This release change does not diagnose the ESP baud fault.
  The larger firmware/changed static footprint and dynamic async allocations
  have not been qualified with Jukebox; do not infer performance acceptance.
- **FW-001-A04 — Scope and records.** Updated public/current pins and local
  handoffs; old firmware/downloads/audit ZIPs remain intact. No application source,
  emulator/profile, target firmware, service, SD contents or active custody changed.
  MOS/EMOS selections are unchanged. Network development remains paused.

Current defaults and exact hashes are in
[firmware-defaults.json](firmware-defaults.json). Tag/version equality is
insufficient to distinguish this amendment from the original release.

## Original audit results — 2026-11-08 (superseded VDP identity)

**Audit complete; execution against the newly selected firmware remains pending.**
The task specification was frozen and pushed as `a40ae7d519be44b280c99c97c0b838864e775aad`
before inspection. Existing dirty network receiver work was preserved. This was
release verification, source review, retained-evidence review and packaging
validation: no compilation, emulator launch, device access, deployment or flash.

The important exception is the RFC player's EMOS return handling. Its current
binary fits bare RC3's interface, but can wait forever after an EMOS refusal.
This audit records the required adaptation; it does not change the executable.

### Verified firmware bindings

| Selection | Identity and verification |
| --- | --- |
| VDPlet v0.1.2-alpha | Release source `b6c7c58331bf4cbbd54dbc4a1301c124e5963622`; firmware 1,100,304 bytes, SHA256 `b004570b607b45bbd6e87a3c704b65b23d3221981db3aac6cf2578aa22d766e3`. Firmware plus six downloaded release records match SHA256SUMS; GitHub asset digests also match. Debug ELF/map archives were not downloaded. |
| Eirene 3.1.0_uart0_rc_3 | Release source `97311c437093e416342a6c836cf9914f2ced027d`; ZIP SHA256 `9c8a9a28b0f597e6a9294d806491ffca3902c16cf1876b092ae8944f65368061` matches its published checksum. Extracted `mos-rc3.bin`: 100,879 bytes, SHA256 `d7a51147f3381cd68d56f3fbe4605434a897dfae1b049269afeba09ec2b7eb50`, exactly the Author's pin. |
| Approved Olimex EMOS snapshot | Owner selector names `agon-emos-eirene-r04-b2026-11-06-09-02-21Z`, source `2c79c6006d6bcb0c2b3f9d8d6aae3ef4b36c730a`; 131,072-byte ROM SHA256 `a25f1612f4aaa542c5488cf3266d968ad3d1d61e9df3b5ce2c680650f5d7a2ca`. `EMOS_UART0_RFC25=1`, `network_parallel=false`. Owner confirmed the caller disposition below from that exact source. This is an approved-image binding, not a fresh physical readback. |

The originally audited VDP image retains its public ABI/wire versions. Pixels, text96, borrowed
rows, READ_BYTES and the UART RX repair are enabled; optional async worker,
counted return and PCM sink are disabled. Current Jukebox audio uses ordinary
buffered PCM commands and needs none of those disabled extensions. The release
records identify the linked repaired UART provider, rather than an accidental
stock SDK driver. Its publication checks are release evidence, not a Jukebox
hardware test of this exact pairing.

The mainboard VDP RX repair does not establish a fix for the independent
ESP8266/UART1 baud-confirmation failure.

### Candidate dispositions

“Source compatible” below means the reviewed interfaces fit. It does not mean
this audit executed the candidate on the new firmware. Binary identities follow
in the appendix; retained controls and older builds are grouped by interface.

| Candidate | Bare RC3 + VDPlet 0.1.2 | Approved EMOS + VDPlet 0.1.2 | Evidence and next requirement |
| --- | --- | --- | --- |
| Classic v0.11.0-beta / main | Source compatible | Source compatible through ordinary MOS/VDP calls | Release and main binary match. Playback/navigation/exit qualification on the new pair remains. |
| Current skins + PCM analyzer; earlier synchronous runtime/control variants | Source compatible | Source compatible | Ordinary synchronous MOS output, standard buffered audio, AGNB and loose fonts. Four-skin loading, playback/analyzer/input/exit qualification remains. |
| SKIN-018 current startup logger | Source compatible | Source compatible | Ordinary file logging added to the runtime. Historical successful starts do not prove the startup fault fixed. Repeat startup review under the selected pair when authorized. |
| Current RFC25 skinned player | Source contract fits exact released RC3 | **Conditional: admission handling required** | Hours of Console8 playback passed on RC3 with earlier VDPlet 0.1.0-alpha. No new-pair execution. EMOS refusal can hang this binary; see below. |
| RC2 42h/43h player | **Incompatible ABI** | **Incompatible ABI** | Requires a specifically justified RC2 firmware exception or a port. The common RC2 build does not necessarily have the earlier fixture's ROM refusal guard. |
| UART-001/002 private UTX1 CTS1/batch16 prototypes | Private async service unavailable | Private async service unavailable | Exact private-MOS exception needed to reproduce the async test. Guarded synchronous fallback exists, but its execution on the new defaults is unqualified. Preserve the original firmware-specific comparisons. |
| NET-001 vanilla U1 receiver | Fits public MOS hooks only with exclusive unused UART1 and the required ESP hardware | **Excluded: resident UART1 ownership conflict** | 115200 receive integrity passed previously. Active 230400 candidate failed before TCP/PCM; prepared 1152000 candidate is unrun. Both remain unresolved/unqualified. An EMOS-owned-port adapter is separate work, not a reason to replace EMOS silently. |
| Pi PCM server / desktop listening client | Firmware independent | Firmware independent | Accepted full desktop listening test remains host evidence only. No service restarted during audit. |
| Frozen agonAMP tracker evaluation binary | Source compatible | Ordinary interfaces fit; execution unqualified | Uses standard MOS/VDP audio and timer ticks, no private async transport. Retain exact frozen source/binary, not a moving upstream checkout; new-pair playback/controls/exit review remains. |

Older `experimental`, `agm`, `wavonly` and archived negative-control fixtures
are not newly promoted production candidates. Earlier ordinary players share
the synchronous interface family above. Fixed-ROM guards, vector-address probes
and startup-failure fixtures retain their exact historical firmware identity;
they cannot be relabeled as qualification of the new defaults.

### RFC25: bare RC3 and EMOS differ

The current sender prearms a completion flag, submits a positive immutable packet
through syscall25h, then waits for the callback and UART0 TEMT before competing
output or exit. Actual MB0/ADL/EI and one producer are prerequisites. Callback
completion releases source reads; it is not receiver execution or wire-empty
acknowledgment. Bare RC3's returned A is not a reliable admission status.

The approved EMOS instead returns **A=0 for admission and a nonzero named refusal
without changing callback, descriptor or IER state**. The current sender ignores
A and waits unconditionally, so refusal can leave it waiting forever. Native
Legacy, MB0/ADL/EI and sole-producer intent do not guarantee acceptance. Its gates
also cover normal admitted RUN context, non-Core/non-MOSlet admission, the full
source and callback spans inside `0x040000..0x0AFFFF`, Legacy backend0, no owned
async source or TEMT tail, UART permission and the UART handover phase.

An EMOS-aware consumer must retain the returned status and handle refusal without
replaying/falling back, while preserving source and wire ownership. Do not impose
that interpretation on bare RC3. No private context/gateway manipulation is
required: normal admitted MOS RUN provides the dispatch context. This is an
outstanding UART-004 adaptation/qualification item, not a MOS patch selected by
this audit. Source disposition supplied by the Extender owner in durable mail
`2026-11-08_23-19-10_linux-extender_audit012-default-source-return-5`.

RC3's released target-library interrupt table is at `0xBC386`, whereas an older
development fixture used `0xBC389`. Use the exact release map for future fixture
rebinding; keep the old fixture evidence intact. RC3's startup correction is
already in the verified release.

### Packaging and profile drift

- Fifteen maintained local emulator wrappers were inventoried: ten Arthur3.0.2,
  three private startup-safe MOS, one RC2, and one Arthur negative control.
  None selects the required RC3 image. These profiles require reviewed migration
  or an explicitly justified historical exception before reuse; none was changed
  or run. This inventory is not a live Oryx or hardware firmware observation.
- Existing native VDP receiver modules also retain historical identities. A host
  `.so` must come from the appropriate release source/features; an ESP32 firmware
  `.bin` cannot replace it.
- The frozen skins/analyzer ZIP contains the expected 65,048-byte synchronous
  binary but still describes Arthur/Bistromathics. It bundles no firmware.
  Preserve that historical archive. Future stock packages now include the current
  firmware guidance and pins, with corrected README text.
- Prepared RFC/NET copies of the released RC3 MOS match the required image.
  The verified VDP release was retained as audit evidence, not deployed to a card.
  Historical deployment records retain their original application/firmware labels.
- Current development instructions, RFC test notes and test-index guidance now
  point to the selected defaults. No executable, autoexec, SD image or launcher
  setting was altered.

### Evidence limits and disposition

The audit closes FW-001; it does not close SKIN-007, UART-004 or NET-001. Current
source-compatible candidates need qualification against the exact new pair.
RC2/private-ROM experiments require explicit scheduling exceptions. The RFC
EMOS admission gap and vanilla UART1 ownership conflict must be addressed before
claiming those applications support the Olimex default.

NET-001 remains paused for supervision. Its 30-second 115200 test returned
213,760 exact PCM bytes with no receive errors and clean close, about 7.12kPCM
bytes/s on the nominal timer. The subsequent 230400 test failed at baud-confirm
with one received byte and line-error aggregate0x8a, before any TCP/PCM. It does
not establish sustained throughput or the cause of the transition failure.
The 1152000 candidate remains prepared, undeployed and unexecuted.

Existing firmware/test/hardware gates remain. No new lease, target activity or
service operation was needed to complete this audit.

### Audit validation

Python syntax and the synchronous package inventory passed. A review ZIP was
assembled from existing artifacts, without rebuilding: its manifest covers the
unchanged 65,048-byte synchronous player, skins/config/source and current firmware
documents. Private task/agent files and the unfinished receiver are excluded.
Selected firmware sizes/hashes were rechecked against downloaded assets; the
EMOS snapshot matches the owner's current selector. New public firmware documents
contain no personal absolute paths. Diff whitespace checks passed. These checks
do not execute the application or qualify any firmware pairing.

### Audited executable identities

SHA256 values below identify bytes inspected, not a new release or rebuild.
Worktree HEAD alone does not describe the pre-existing dirty RFC/receiver work;
these binary hashes and retained build records bind those candidates.

| Candidate | Bytes | SHA256 |
| --- | ---: | --- |
| Classic main/tag | 27,957 | `23a6c624e65857b7e7e1394edad7a878c4005dfbb900fb1b47dd2a75ef81d32c` |
| Skins analyzer | 65,048 | `1469e437a5ba6c80a32de71cfa079906cdd43e8c03a2b214019348a6fa376ec3` |
| Earlier standard player | 51,655 | `ec0c1d8cdcb142f2fb08f1da856a33e68fa444523973e1bf35143890489e15f0` |
| Seventies variant | 52,032 | `8ed30b1e62238f0f26770fcfc8f35eb74e53a3e1cb7b0f3abecaafd8d80016d0` |
| Earlier runtime control | 62,799 | `3dc34ba639c39b1fe7fa32e873225d91cda393a0995cbb65dfdca0ac362ee0e5` |
| RFC25 | 65,602 | `7c7539656fd801e94690f4f33fc3ede87aa6701bf5dfeb201bf9e13042ef5e04` |
| RC2 | 65,563 | `f906ff83d1a79d7c8217975732f53f1af9a7909ef0a77ddae071404253434dd1` |
| Private CTS1 | 64,242 | `0c2efac1883fd6aa2b639c12a720d99f1a046fa23628460588c2e1751caa53b2` |
| Private batch16 | 64,349 | `00ae74af38946d01eeff9e83a7856c8cc52023e628555040db7f2abfb21c22cd` |
| NET active 230400 | 22,558 | `4675a542c43b211234255e7e14aec6611d38f1aa5f8821f44d73852684269ca1` |
| SKIN-018 current logger | 64,834 | `73e009bee0432b0fae2f98c5821e10eb17a9b7e7889536534f5e3a412687bdb3` |
| Frozen agonAMP | 47,399 | `122e0864a2009591f76230a25b336dc58ebdad97b5cbbc75405c814adc02c5ce` |
| NET prepared 1152000 | 22,573 | `f0f1ca82fb3e9badaa5be64fbb6a03cce83b36837ec8d9d755d54c4fbbe96ef7` |

Source anchors: Classic tag `9edfba629a2a2934f4bc66ee415d73fe2f32b75f`
(main `91281f2255639d0c864b2842f9df7c8ff2faf66b` has identical executable);
skins `aca76249d83096332123eabe3cf66ead1c3bd2bf`; private UART prototypes
`acee1fdafbed4b2b23a22fb9f8a195f3d2c2c560`; current logger baseline
`f3cd5925a14778f8c5ed4666bac10b2e109731b3`; RFC/NET retained source and
build records on `codex/net-001-pcm-stream` (including pre-existing dirty work).
Frozen agonAMP uses upstream tag1.1, commit
`91ef401bcb7f636e7593ad1ba176508344deebb9`, with its retained local build
records binding the inspected binary. The NET receiver vendors unchanged U1 source
`823bb91dd4c1af5a1488e3d3361648646b601445`, library SHA256
`b7870dff9c979b5051aec6bdd4e177dbfa29f7b6e42c1a52992fca9e4b246831`.

Machine-readable selected defaults are in [firmware-defaults.json](firmware-defaults.json).
Detailed local inventories, downloaded release records and verification output
are retained under the private FW-001 task evidence directory.

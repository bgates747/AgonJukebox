# Eirene RC3 / RFC asynchronous Jukebox player

The pinned MOS is our published fork prerelease `3.1.0_uart0_rc_3`, source
`97311c437093e416342a6c836cf9914f2ced027d`, incorporating Tom's RFC sender and
UART's startup correction. CRC32 `B08C80B8`; exact SHA/size are in FIRMWARE.json.
This is not an upstream stable release. Original application-model evidence
keeps its original firmware identity and does not qualify the new RC3 pairing.

RC3's original target library places its interrupt table at `0xBC386`; use the
bundled image's map when preparing vector snapshots. The earlier development
ROM used `0xBC389`. These addresses belong to fixtures, not application code.

The call passes HL=packet address, BC=positive byte count and DE=raw completion
callback to syscall25h. The application uses neither RC2's42h/43h interface nor
a firmware checksum gate. A startup-only correction needs no player rebuild;
recheck the owner's final interface before coupling the artifacts.

This complete skinned player uses Tom Morton's proposed syscall25h at RFC base
ffab9c9c84a31535d1ec976b7e6f23b2579ecb80. Firmware compatibility is an explicit
installation prerequisite, as with the common RC2 player. There is no ROM hash
allowlist, discovery service, RC2 fallback or per-EMOS executable. The same app
is intended for compatible MOS and EMOS native Legacy mode. Hardware deployment
requires the tested startup correction supplied by the firmware owner.

## Sender and ownership

Only PCM buffered-write packets use25h: eight-byte VDU header plus strictly
positive PCM, one immutable2048-byte staging area at092000. Ordinary UI/audio
control commands stay synchronous. State is prearmed; raw assembly callback
only posts a flag, touching AF, with no output/MOS/index/alternate-register use.
The app uses ADL1 and checks actual MBASE0 before setup. MOS owns UART interrupts.

The callback means last source read/FIFO load, not wire empty or VDP execution.
Foreground waits for source flag then observes UART0 LSR TEMT before releasing
its active state. No43h/finish syscall, invented status/cancel or UART-register
writes are used. Ignore the RFC's unimplemented documented A=0 return. Positive
single-producer submissions avoid its unchecked zero/null/overlap cases.

Conservative TEMT applies before EVERY next packet and competing synchronous
output/quit. This deliberately forgoes final-FIFO-tail overlap; it is a prototype
policy, not a claimed API requirement. Keep borrowed storage/callback code alive
until complete. A stuck wait does not authorize freeing it. ISR CTS spinning
can still delay timers/input. No performance gain or stall-proof claim.

Existing chunk/remainder/EOF arithmetic, scheduler, controls, four skins, loose
fonts and AGNB assets are preserved. Analyzer compute may overlap transmission,
rendering waits. PRT1 vector0Ch is installed before enable and stopped/restored
on teardown. The pre-existing one-second sample-boundary behavior is unchanged.

## Build, installation and evidence

    sh scripts/build_rfc_player.sh

Set EZ80ASM if needed; output tgt/jukebox-rfc.bin. All source/generated UI/vendor
code needed to build is included. See README/install guide for config and assets.
Firmware source/map/hash identification belongs to deployment; never invoke this
explicit RFC build on stock or released RC2 firmware that lacks the required ABI.
No script flashes firmware, changes autoexec or modifies other player versions.

QUALIFICATION.json in the test package describes the actual compiled candidate
and retained model checks. Original guarded-F00 tests are archived separately;
removing that experimental ROM gate requires a distinct final build/test record.
Original RFC startup initializes defaults before BSS clearing; that known defect
is retained in original-ROM development evidence, not presented as corrected or
hardware-ready. A startup-only patch must be verified separately by UART/deployer.
Model uses the named receiver-fixed native derivative, not asserted stock hardware.
Frontend may require bounded TERM/KILL after normal app return; record it.

## Fixed diagnostic reports

Normal teardown writes52-byte /JRFC.DAT. Header JRFC, version1, selected25h,
error, sampled due high; elevenLEu32 fields: submissions, observed callbacks,
payload bytes, pending polls, compute service entries, local drains, play barriers,
serviced ticks, sessions, timer restorations and TEMT-only polls. Counts do not
measure CPU utilization, exact ISR timestamps or audible underruns. No growing log.

    python3 scripts/decode_rfc_stats.py JRFC.DAT
    python3 scripts/pcm_spectrum_report.py JSPEC.DAT

JSPEC remains fixed28bytes. Reset/power loss does not save reports. Decoder and
source preserve transport/source/wire/receiver distinctions.

## Credits

Async sender and API: **Tom Morton and Eirene/MOS upstream contributors**.
Visualization techniques: **Nick J. Date (Pollito / SanPollo), agonAMP**.
The independent PCM analyzer and upstream license/attribution files are retained.

# Common Eirene RC2 Jukebox test

This single application tests the same RC2 asynchronous UART0 API on published
Eirene MOS and Eirene-based EMOS in native Legacy mode. The executable contains
no whole-ROM checksum, firmware allowlist or EMOS-specific target. Firmware/API
identification belongs to deployment preparation. The unchanged application
binary on both machines is the compatibility experiment. Hardware observations
and limitations are recorded in [the debrief](eirene-rc2-debrief.md). The normal stock-firmware player remains unchanged.

## Firmware prerequisite and optional manual flashing

Requires the RC2 submit42h/finish43h API and ordinary native UART0/VDU routing.
Published reference: tag3.1.0_uart0_rc_2, source
825eaf77176247f5b5ba2f940ae73fcace34e7e5. Optional included mos-eirene-rc2.bin:
100950bytes, CRC32 9E08D539, SHA256
a47130d78b70fa1e0e54aa61e4340831036d766a0c59e2738935bd9d04b94a3a.
https://github.com/bgates747/eirene-mos/releases/tag/3.1.0_uart0_rc_2

On Console8 only, if that MOS installation is wanted, from the directory
containing the firmware file run:

    flash mos mos-eirene-rc2.bin

The existing /mos/flash.bin performs the update and confirmation. Copying the
file does not flash it; no automatic flashing or autoexec change is provided.
Do not replace the Olimex bench's working EMOS with this plain MOS image:
EMOS supplies that bench's Extender input/services and already includes the
RC2 sender. Its source16ec1f78/full131072-byte ROMf62eed7f has passed the
upstream RC2 functional fixture; Jukebox compatibility is still to be tested.

The published RC2 reference inherits the documented dormant-IRQ-table
initialization defect. The EMOS image includes the separate correction. The
bundled reference is the exact requested published artifact, not a substituted
locally fixed ROM. Intended Console8 VDP is Bistromathics2.16.0; identify the
actual Olimex native derivative separately. No VDP firmware is installed here.

## Generic installation

1. Copy tgt/jukebox-rc2.bin to /bin/jukebox-rc2.bin.
2. Copy config/jukebox.cfg to /bin/jukebox.cfg and adjust paths if needed.
3. Copy skins/ to /jukebox/skins/. Assets remain AGNB and loose fonts.
4. Put compatible WAVs in /music, or set music_dir.
5. On a machine with the RC2 API, run jukebox-rc2. There is no firmware
   discovery/fallback in this explicitly selected test executable.

The physical fixture uses the established /test/jukebox/jukebox-async.bin
filename instead, with its own included skins and a matching global cfg. That
filename selects this common RC2 build, not the older custom-MOS UART prototype.
Its readme.txt gives the exact deployed commands and paths.

Arrows/Enter browse/play; U goes up; P pauses; comma/period change volume;
brackets seek; L/S loop/shuffle; K chooses a skin; V toggles Nineties analysis;
Q/Esc quits. Let a newly selected skin finish drawing before selecting a song.
One-second sample-boundary pops are unchanged.

## Build and ownership

Run sh scripts/build_rc2_player.sh with ez80asm in PATH, or set EZ80ASM.
All assembly/dependency sources and generated UI data are included. No Python,
Pillow, font editor or image conversion is needed to build/run.

The only behavioral change from the previously qualified candidate is removal
of its ROM-dependent startup gate; scheduler, submit/finish, packet construction,
callback and analyzer bodies are unchanged. The diagnostics header is version2.
One immutable2048-byte packet is borrowed at a time. Completion is armed before
submit; callback only posts a flag/count. Finish before synchronous output,
control traffic, vector restoration or exit. Pending analysis is compute-only.
Source release, transmitter empty and VDP execution are distinct events.

## Fixed diagnostics

Normal teardown overwrites /JRC2.DAT48bytes; no continuously growing log.
Header: ASCII JRC2, version2, requested RC2 transport1, error, sampled due high.
The requested-transport byte does not attest firmware identity or API success.
Ten LEu32 counters: submissions, callbacks, PCM bytes, finish busy polls, pending
compute-service entries, successful finishes, sample-play barriers, serviced
ticks, sessions, timer restorations. Decoder accepts historical version1 too.

    python3 scripts/decode_rc2_stats.py JRC2.DAT
    python3 scripts/pcm_spectrum_report.py JSPEC.DAT

Quit normally to save reports. The analyzer report remains28bytes. Power loss
or a reset does not save them. A contract fault retains uncertain storage in a
stopped loop; this fixture does not invent cancellation or print into a packet.

## Qualification boundary

Common build65563bytes SHA256
f906ff83d1a79d7c8217975732f53f1af9a7909ef0a77ddae071404253434dd1.
Native assembly, unchanged stock-control hash and packaged source reproduction
pass. Smith has manually run the common build on Console8 and Olimex. Console8
feedback is positive; Olimex playback is judged about even against the standard
app, with async controls feeling more responsive. No common-build emulator run
or quantitative physical timing claim. See the dated debrief for confounders.

Earlier gated build4a696d94 passed native playback/controls/analyzer and
1,985,086 source-exact PCM bytes, including fractional EOF and65535Hz. Those
results belong to that older executable. All skins loaded, but additional-skin
playback was unconfirmed after an immediate Enter at READY. Two collector
errors and the original evidence remain on the host. Native model used a pinned
receiver-fixed VDP; frontend needed bounded TERM/KILL after normal app return.
Those model checks make no physical audio, CPU utilization, clean host-exit or
pop-free claim; the separate hardware listening observations are in the debrief.

## Credits

UART0 API: Eirene/MOS, Tom Morton and upstream contributors.
VISUALIZATION DESIGN CREDIT: Pollito / SanPollo — Nick J. Date, agonAMP.
Paced incremental rendering, desired/displayed state and falling bars inspired
this independently written PCM visualization. See docs/pcm-spectrum.md and
vendor/agnb/LICENSE and vendor/agonamp-visualization/LICENSE.

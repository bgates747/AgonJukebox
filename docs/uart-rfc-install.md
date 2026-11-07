# AgonJukebox — Eirene RC3 / RFC player test

A complete skinned WAV player using Tom Morton's RFC syscall25h. This package
includes buildable source, executable, four runtime skins/AGNB assets/fonts,
configuration and diagnostic decoders. It requires compatible startup-corrected
RFC firmware supplying syscall25h; released Eirene RC2 is a different ABI.
FIRMWARE.json records the requirement and identifies an optional bundled image.
See QUALIFICATION.json for completed checks and remaining physical-test limits.

The pinned MOS is our Eirene fork prerelease `3.1.0_uart0_rc_3`, source commit
`97311c437093e416342a6c836cf9914f2ced027d`, with Tom's RFC sender and UART's
startup correction. RC3 keeps the RFC25h ABI, which differs from RC2's42h/43h
API. This is a fork prerelease, not an upstream stable release. The MOS file is
100879 bytes, CRC32 `B08C80B8`, SHA256
`d7a51147f3381cd68d56f3fbe4605434a897dfae1b049269afeba09ec2b7eb50`.
FIRMWARE.json records the exact bundled image; QUALIFICATION.json retains the
earlier application model's original firmware identity. Those runs are not RC3
pairing tests. Subsequent Console8 listening with RC3 and VDPlet 0.1.0-alpha
was reported flawless over hours. That operator result does not establish
stock-VDP compatibility or measured latency/throughput.

## Console8 installation

1. Put the package on your SD card. Keep its source and firmware reference for
   reproducibility. No script here flashes firmware or changes autoexec.
2. Install UART’s tested startup-corrected RFC MOS using your normal flash
   procedure when ready. If bundled, its filename is mos-eirene-rc3.bin. Firmware installation and
   hardware listening remain human actions; this is not an official MOS release.
3. Copy tgt/jukebox-rfc.bin to /bin/jukebox-rfc.bin.
4. Copy the four directories under skins/ to /jukebox/skins/.
5. Copy config/jukebox.cfg to /bin/jukebox.cfg. It selects the Nineties skin and
   /music; edit skin_dir/music_dir for your SD layout. Assets remain outside bin.
6. Run jukebox-rfc once compatible firmware is installed. Firmware identity is
   checked during deployment; the player has no ROM allowlist or RC2 fallback.

To put the executable in another directory, LOAD its complete path then RUN.
It always reads /bin/jukebox.cfg. Existing standard and RC2 builds are separate
baselines; this package changes neither automatically.

## Use and diagnostics

Arrows/Enter browse/play; U parent; P pause/resume; comma/period volume;
brackets seek; minus/equals seek interval; L loop; S shuffle; R random;
K skin chooser; V Nineties analyzer; Q/Esc normal quit. Allow skin redraw to
settle before selecting a track. No control legends are added to decorated skins.
Unsigned8-bit mono WAV,1..65535Hz, PCM or supported PCM-extensible RIFF.
The existing one-second sample-boundary behavior is unchanged.

Normal quit writes fixed-size /JRFC.DAT and /JSPEC.DAT; logging cannot grow
indefinitely. Decode with scripts/decode_rfc_stats.py and pcm_spectrum_report.py.
Reports identify errors, packet/callback/drain counts and due backlog, not
physical audible-underrun timestamps or CPU utilization.

## Rebuild

Install ez80asm, then run sh scripts/build_rfc_player.sh from the extracted
folder (or set EZ80ASM). Sources, generated UI and vendor dependencies are
included; no sibling checkout, font editor or image conversion is needed.
The same executable works across compatible RFC MOS/EMOS Legacy builds; a
startup-only firmware patch requires no application rebuild. Verify the actual
firmware API/source at deployment rather than relying on its banner. The app
requires ADL mode/MBASE0 and native UART0 routing. MANIFEST.json identifies files.

## Credits

UART API and sender: **Tom Morton and Eirene/MOS upstream contributors**.
Visualization techniques: **Nick J. Date (Pollito / SanPollo), agonAMP**.
Existing project and vendored license/attribution files are included.

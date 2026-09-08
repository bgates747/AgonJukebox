# TODO

1. [ ] **EMU-001 — Investigate large WAV files omitted by Jukebox in Fab HostFS**

   Reported 2026-09-08. Deferred: enough smaller playable samples are available
   to continue skinning work.

   **Symptoms:** Published Jukebox `v0.10.0-beta`, installed as
   `/bin/jukebox.bin`, omits large WAV files from its browser in the local Fab
   emulator. Files that appear are playable. MOS can list the omitted files
   and reports apparently accurate full sizes. Root directories are visible,
   and the corrected music symlink resolves to the intended host directory.
   The Author routinely plays album-length files on hardware and reports that
   these worked in an earlier emulator setup; this is not an established
   16 MB limitation of the player.

   In the retained `/jukebox/music` fixture directory, the visible/playable
   files are `AgonJukebox_Extensible_65535.wav` (13,210 bytes), `Rhiannon.wav`
   (12,133,198 bytes), and `Wild_Flower.wav` (10,524,292 bytes). Missing files
   include `Africa_65535.wav` (19,394,398 bytes) and
   `Lynyrd_Skynyrd__Gold_and_Platinum.wav` (258,547,790 bytes).

   **Troubleshooting performed:**

   - Prepared a dedicated, gitignored project `.emulator/` profile using the
     canonical setup tool. Verified the published release matches its tagged
     binary, retained MOS v3.0.2, and used CRLF startup commands:
     `SET KEYBOARD 1`, `cd /music`, `jukebox`.
   - Corrected the initial mapping of host `music/Albums` directly as `/music`
     to the Author's intended `/home/smith/Agon/mystuff/music` as `/music`.
     Albums is now `/music/Albums`. The Author confirmed the link is correct;
     this did not resolve the missing large files.
   - Checked directory navigation and the separate `/jukebox/music` fixtures.
     Root directories display normally; the original Albums target itself
     contained WAVs and no subdirectories. A general directory-recursion
     failure has not been demonstrated.
   - Built official Fab 1.2.4 with its pinned submodules, then built and selected
     official 1.2.3 at the Author's request to test whether 1.2.4's HostFS
     current-directory reset fix introduced the problem. Large files remain
     omitted on both versions, so reverting did not fix it. No emulator
     source patch was applied.
   - Inspected WAV headers and RIFF lengths. A diagnostic on 1.2.4 observed
     full directory-entry sizes but truncated open-file sizes, consistent
     with its HostFS code writing only 24 bits to the opened file's size
     field. Jukebox compares RIFF length against that field before listing a
     WAV. Its audio-duration calculation uses the 32-bit RIFF data length.
     MOS's accurate directory listing does not establish the size returned
     by the separate file-open API. This is a lead, not a validated fix;
     the Author paused deeper emulator investigation to continue skin work.

   **When resumed:** Trace the exact rejection of one omitted WAV, comparing
   directory-entry size, opened-file size and RIFF length in the same run.
   Establish the cause and validate any correction with both small and
   album-length files before changing production player behavior.

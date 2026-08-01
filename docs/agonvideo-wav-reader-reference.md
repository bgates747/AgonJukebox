# AgonJukebox WAV reader and streaming reference

This document inventories the WAV-specific implementation in
`/home/smith/Agon/mystuff/AgonJukebox/src/asm/`. It is a reference for file
opening, RIFF-style validation, streaming reads, VDP buffer management, and
audio playback. The WAV-only candidate include graph targets stock VDP
firmware.

## Source map

- `wav.inc`: opens files and validates selected fields in the WAV prefix.
- `play.inc`: initializes WAV playback, streams PCM data, alternates VDP
  buffers, and builds the buffered VDP sound command sequences.
- `files.inc`: assigns RAM addresses for the FatFS structures, copied
  `FILINFO`, WAV header, and streaming data.
- `timer_jukebox.inc`: drives streaming at 60 interrupts per second.
- `vdu_buffered_api.inc`: writes, calls, and clears VDP buffers.
- `vdu_sound.inc`: stock sound commands used during playback and cleanup.
- `input.inc`: seeking and playlist selection around the WAV stream.
- `browse.inc`: discovers directory entries and calls the WAV verifier.
- `layout.inc` and `logo.inc`: initialize and release the app-owned font/logo
  buffers around the user interface.
- `mos_api.inc`: `FFSCALL`/`MOSCALL` definitions and FatFS structure offsets.

## WAV layout assumed by streaming and seeking

The reader does not walk arbitrary RIFF chunks. It reads a 76-byte prefix, and
the streaming and seek paths assume the following fixed map. Most entries are
named source constants but are not enforced by `verify_wav`:

| Symbol | Offset | Size | Meaning |
|---|---:|---:|---|
| `wav_riff` | 0 | 4 | `RIFF` identifier |
| `wav_file_size` | 4 | 4 | RIFF size: physical size minus 8 |
| `wav_wave` | 8 | 4 | `WAVE` form identifier |
| `wav_fmt_marker` | 12 | 4 | `fmt ` chunk identifier |
| `wav_fmt_size` | 16 | 4 | Format payload size; expected PCM value is 16 |
| `wav_audio_format` | 20 | 2 | Audio format; PCM is 1 |
| `wav_num_channels` | 22 | 2 | Channel count; playback expects mono |
| `wav_sample_rate` | 24 | 4 | Samples per second |
| `wav_byte_rate` | 28 | 4 | Bytes per second |
| `wav_block_align` | 32 | 2 | Bytes per sample frame |
| `wav_bits_per_sample` | 34 | 2 | Sample bit depth |
| `wav_list_marker` | 36 | 4 | Assumed `LIST` chunk identifier |
| `wav_list_size` | 40 | 4 | Assumed LIST payload size |
| `wav_info_marker` | 44 | 4 | Assumed `INFO` list type |
| `wav_isft_marker` | 48 | 4 | Assumed `ISFT` metadata identifier |
| `wav_isft_size` | 52 | 4 | Assumed ISFT payload-size field |
| `wav_isft_data` | 56 | 12 | Assumed span for ISFT payload and RIFF alignment pad |
| `wav_data_marker` | 68 | 4 | Assumed `data` chunk identifier |
| `wav_data_size` | 72 | 4 | Assumed PCM payload size |
| `wav_data_start` | 76 | — | Assumed first PCM byte |

`wav_header_size` is therefore fixed at 76. These are the application's assumed
offsets, not offsets dynamically discovered from the file. This is an
intentional streaming assumption, not an attempt to implement a general
RIFF/WAVE parser. The verifier does not enforce the LIST/ISFT/data portion of
this map. Input preparation is currently expected to supply the assumed layout;
whether to enforce that contract or parse `data` dynamically is tracked as
`WAV-004` in `docs/TODO.md`.

## Open and validation routines

### `bf_verify_wav`

Browser-side wrapper used while classifying directory entries.

- Preserves the caller's `IY`.
- Points `IY` at `bf_wav_header`.
- Calls `verify_wav` using the caller-supplied `HL` FIL pointer and `DE`
  filename pointer.
- Always closes the browser FIL with `ffs_fclose` after validation.
- Restores the verifier's `A` value and zero flag.

### `ps_open_wav`

Playback-side open wrapper.

- Calls `bf_get_filinfo_from_pg_idx` to obtain the selected entry in `IY`.
- Sets `DE = IY + filinfo_fname` and `HL = ps_fil_struct`.
- Points `IY` at `ps_wav_header` and calls `verify_wav`.
- Leaves a valid file open for streaming.
- Closes `ps_fil_struct` only when validation fails.
- Returns `A=1`, NZ for WAV, or `A=0`, Z for failure.

### `verify_wav`

Shared open/read/validate routine.

Inputs:

- `HL`: caller-owned FatFS `FIL` structure.
- `DE`: zero-terminated filename.
- `IY`: destination for the 76-byte header.

Operation:

1. Clears `wav_header_size` bytes at `IY`.
2. Opens the file read-only with `ffs_fopen`.
3. Reads 76 bytes with `ffs_fread`.
4. Checks the low three bytes of `RIFF` against `RIF`.
5. Checks the low three bytes of `WAVE` against `WAV`.
6. Compares three bytes beginning at `wav_audio_format` with `0x010001`,
   effectively requiring PCM format 1 and mono channel count 1 in the bytes
   inspected.
7. Checks the low three bytes of the format marker against `fmt`.
8. Returns `A=1`, NZ for WAV or `A=0`, Z for failure.

The routine preserves `BC`, `DE`, `HL`, and `IX`; its comments declare `AF`
destroyed.

## Playback and streaming routines

### `play_song`

Top-level setup and dispatch routine. Its WAV path:

1. Calls `ps_close_file` to stop the timer, reset WAV channels 0 and 1, and
   close prior playback state.
2. Resets the 60-tick chunk counter.
3. Calls `ps_open_wav` and reports invalid input on failure.
4. Copies the selected directory `FILINFO` into `ps_filinfo_struct` for the
   persistent filename and display metadata.
5. Displays the selected WAV sample rate. The same rate is embedded separately
   in each create-sample command when the command buffers are built; the player
   does not mutate the VDP's global audio-system rate. In the upstream Console8
   implementation, global value 65,535 is a sentinel for its 16,384 Hz default,
   which is another reason not to mirror a file's rate through that command.
6. Applies the user's stored global volume.
7. Computes approximate duration as RIFF file size divided by sample rate.
8. Computes `ps_wav_chunk_size = sample_rate / 60`.
9. Builds the two audio command buffers with `ps_load_audio_cmd_buffers`.
10. Selects and clears the first data buffer with `ps_set_audio_buffers`.
11. Marks playback active and starts the PRT timer at 60 Hz.

### `ps_read_sample`

The interrupt-time WAV reader.

- Calls `ffs_fread` with:
  - `HL = ps_fil_struct`
  - `DE = ps_wav_data`
  - `BC = ps_wav_chunk_size`
- Treats a zero-byte read as EOF, closes the file, and dispatches
  `ps_song_over`.
- Uploads each nonempty read into the current VDP sample buffer via
  `vdu_load_buffer`/`vdu_write_block_to_buffer` semantics.
- Decrements `ps_wav_chunk_counter` for each block.
- After 60 blocks, resets the counter and jumps to `ps_play_sample`.

At 8-bit mono, `sample_rate / 60` bytes per read and 60 reads produce one
second of audio in the VDP buffer.

### `ps_play_sample`

- Updates the elapsed-time UI through `ps_update_playbar`.
- Calls the current VDP command buffer with `vdu_call_buffer`.
- Calls `ps_set_audio_buffers` to alternate channels and prepare the next data
  buffer.

### `ps_set_audio_buffers`

- Toggles `ps_channel` between 0 and 1.
- Maps the channel to command buffer `0x3000` or `0x3001`.
- Maps the channel to sample buffer `0x3002` or `0x3003`.
- Clears the newly selected sample buffer before more blocks are appended.

This is the double-buffering mechanism: one one-second sample may play while
the other VDP buffer is filled.

### `ps_clear_audio_buffers`

Clears only the four VDP buffers owned by WAV playback (`0x3000` through
`0x3003`). It is called during application initialization and exit, not during
each streaming tick.

### UI buffer cleanup

`ui_clear_buffers` deletes/clears the jukebox font at buffer `0xFA10` and clears
the logo at buffer `0x2000`. Initialization now clears these UI resources and
the four WAV buffers instead of issuing buffer ID 65,535 (clear all). Exit also
releases the same app-owned resources.

This scoped startup policy is a hardware-validation candidate, not yet a final
resource decision (`VDP-001` in `docs/TODO.md`). Clear-all was historically
intentional to reclaim scarce VDP memory before a demanding stream. The
hardware pressure test must begin
with substantial pre-existing VDP allocations and verify that the font, logo,
command buffers, and one-second audio buffers can still be created and played.
If not, startup should intentionally clear all buffers while exit remains
scoped. At the 65,535 Hz boundary, the app-owned buffer payloads alone can
reach about 142,788 bytes: two 65,535-byte audio buffers, a 9,600-byte logo, a
2,048-byte font, and two 35-byte command buffers, before VDP object overhead.

### `ps_close_file`

- Stops the PRT timer with `ps_prt_stop`.
- Resets stock sound channels 0 and 1, which immediately stops in-flight
  samples without touching channels owned by another application.
- Calls `ffs_fclose` on `ps_fil_struct`.

### `ps_load_audio_cmd_buffers`

Builds two callable VDP command buffers, one per channel/sample-buffer pair.
For each pair it emits commands to:

1. Consolidate the uploaded blocks in the sample buffer.
2. Convert the buffer to an 8-bit unsigned PCM mono sample using the WAV
   sample rate.
3. Set the corresponding sound channel's waveform to that sample buffer.
4. Play the complete sample once at volume 127.

The command templates are `ps_cmd0`/`ps_cmd1`; `ps_sr0`/`ps_sr1` are patched
with the low 16 bits of the WAV sample rate before upload. The explicit VDP
field is 16-bit, so the candidate's representable per-buffer range ends at
65,535 Hz; the 32-bit WAV field is not currently validated against that limit.

### Playlist/UI helpers in `play.inc`

These surround WAV streaming but are not required by a minimal loader:

- `ps_update_playbar`: updates elapsed time and the graphical playbar.
- `ps_song_over`: applies loop/shuffle/next-song behavior.
- `ps_play_next_song`, `ps_play_prev_song`, `ps_play_random`: select another
  browser entry and call `play_song`.

### Seeking — `input.inc:405` onward

- `ps_seek_back` and `ps_seek_fwd` stop the PRT timer and select a signed seek
  delta.
- `ps_seek` calculates a wrapped playhead position, multiplies seconds by the
  WAV sample rate, adds the fixed 76-byte header, and calls `ffs_flseek` on
  `ps_fil_struct`.
- It rebuilds/selects the audio buffers and restarts the timer.

The seek calculation shares the fixed-header and one-byte-per-sample
assumptions of the streaming path.

## Timer-driven streaming

The WAV path uses these routines from `timer_jukebox.inc`:

- `ps_prt_start`: programs timer 1 for continuous interrupts. The reload is
  `72000 / ps_chunks_per_second`, with `ps_chunks_per_second = 60`.
- `ps_prt_stop`: disables timer 1 and its interrupt.
- `ps_prt_irq_init`: installs `ps_prt_irq_handler` in interrupt vector table 2.
- `ps_prt_irq_handler`: saves alternate register sets, ignores ticks while
  paused, and directly calls `ps_read_sample`.

The handler also clears `sysvar_keyascii` through `mos_sysvars` on every tick.

## VDP helper routines used by the WAV path

From `vdu.inc`:

- `vdu_load_buffer` (`vdu.inc:496`): appends each RAM-resident PCM block to the
  currently selected VDP sample buffer using buffered command 0.

From `vdu_buffered_api.inc`:

- `vdu_write_block_to_buffer`: uploads the prebuilt sound-command templates to
  the two callable command buffers.
- `vdu_call_buffer`: buffered command 1; executes the prebuilt sound-command
  sequence.
- `vdu_clear_buffer`: buffered command 2; resets a command or sample buffer.

From `vdu_sound.inc`:

- `vdu_channel_volume`: sets the user's global playback volume.
- `vdu_reset_channel`: resets owned channels 0 and 1 during transitions and
  exit, using stock enhanced-audio command 10.

The core create-sample, set-waveform, and play-note messages are encoded
directly in `ps_cmd0` and `ps_cmd1`, rather than calling
`vdu_buffer_to_sound`, `vdu_channel_waveform`, or `vdu_play_note` at runtime.

All VDP command blocks are sent with `RST.LIL $18`.

## MOS and FatFS calls

| Call | Use in WAV path |
|---|---|
| `FFSCALL ffs_fopen` | Open a caller-owned `FIL` using a filename and `fa_read` |
| `FFSCALL ffs_fread` | Read the 76-byte header and subsequent PCM blocks |
| `FFSCALL ffs_fclose` | Close browser verification files, failed opens, EOF, and stopped playback |
| `FFSCALL ffs_flseek` | Seek to `76 + sample_rate * seconds` |
| `FFSCALL ffs_dread` | Populate browser `FILINFO` records before WAV verification |
| `MOSCALL mos_sysvars` | Access and clear `sysvar_keyascii` in the timer interrupt |
| `RST.LIL $18` | Send VDP buffered and sound command sequences |

The playback code uses the direct FatFS API and caller-owned `FIL` structures,
not the simpler handle-based `mos_fopen`/`mos_fread` interface used by unrelated
test harnesses.

## Data structures and state

### FatFS `FIL`

The declared offsets are:

| Field | Offset | Size |
|---|---:|---:|
| `fil_obj` | 0 | 15 |
| `fil_flag` | 15 | 1 |
| `fil_err` | 16 | 1 |
| `fil_fptr` | 17 | 4 |
| `fil_clust` | 21 | 4 |
| `fil_sect` | 25 | 4 |
| `fil_dir_sect` | 29 | 4 |
| `fil_dir_ptr` | 33 | 3 |

`files.inc` reserves two fixed 36-byte regions:

- `bf_fil_struct = 0x06FF00`: temporary browser validation.
- `ps_fil_struct = 0x090000`: persistent playback/streaming file.

### FatFS `FILINFO`

The structure is 278 bytes:

| Field | Offset | Size |
|---|---:|---:|
| `filinfo_fsize` | 0 | 4 |
| `filinfo_fdate` | 4 | 2 |
| `filinfo_ftime` | 6 | 2 |
| `filinfo_fattrib` | 8 | 1 |
| `filinfo_altname` | 9 | 13 |
| `filinfo_fname` | 22 | 256 |

The browser owns many directory `FILINFO` records. `play_song` copies the
selected record to `ps_filinfo_struct = 0x090100`, primarily to retain and
display the filename. The actual streaming reads use `ps_fil_struct`, not
`ps_filinfo_struct`.

### WAV RAM regions

- `bf_wav_header = 0x081C00`: 76-byte temporary browser-validation header.
- `ps_wav_header = 0x090300`: 76-byte active playback header.
- `ps_wav_data = 0x09034C`: streaming PCM staging area immediately after the
  playback header; described as virtually unlimited in the source map.

### Playback state

- `ps_wav_chunk_size`: bytes read per 60 Hz tick.
- `ps_wav_chunk_counter`: ticks remaining before playing the accumulated
  one-second sample.
- `ps_channel`: selects channel/buffer pair 0 or 1.
- `ps_wav_cmd_buffer`: current callable command-buffer ID.
- `ps_wav_data_buffer`: current sample-data buffer ID.
- `ps_mode`: playing, loop, and shuffle bits.
- `ps_playhead`, `ps_song_duration`, `ps_seek_rate`: UI and seek state.

### VDP buffers

| Symbol | bufferId | Purpose |
|---|---:|---|
| `ps_wav_cmd_bufferId0` | `0x3000` | Callable command sequence for channel 0 |
| `ps_wav_cmd_bufferId1` | `0x3001` | Callable command sequence for channel 1 |
| `ps_wav_data_bufferId0` | `0x3002` | PCM sample blocks for channel 0 |
| `ps_wav_data_bufferId1` | `0x3003` | PCM sample blocks for channel 1 |
| `BUF_UI_LOGO` | `0x2000` | Jukebox logo bitmap data |
| `Lat2_VGA8_8x8` | `0xFA10` | Custom UI font data/font ID |

## End-to-end WAV flow

```text
directory scan -> FILINFO
      |
      v
bf_verify_wav -> verify_wav -> open/read 76 bytes -> close browser FIL
      |
      v
play_song -> ps_open_wav -> verify_wav -> leave playback FIL open
      |
      +-> calculate sample_rate/60
      +-> build two callable VDP sound-command buffers
      +-> start 60 Hz PRT interrupt
      |
      v
ps_prt_irq_handler -> ps_read_sample -> ffs_fread PCM block
      |
      +-> append block to current VDP sample buffer
      +-> after 60 blocks, call command buffer and swap buffer/channel
      |
      v
EOF -> ps_close_file -> loop/shuffle/next-song policy
```

## Deliberate format constraints and remaining cautions

Two behaviors are conscious design decisions in the current candidate:

- The streaming and seek paths assume PCM begins at byte 76 and do not walk
  arbitrary RIFF chunks. The verifier itself checks only selected early-prefix
  fields and does not enforce the rest of the assumed map.
- `RIFF`, `WAVE`, and `fmt ` comparisons inspect their low three bytes because
  the eZ80's native ADL registers are 24-bit. Under the controlled input-format
  contract, this avoids more cumbersome 32-bit comparison code. The fourth
  byte is intentionally not checked.

The following are separate implementation assumptions or matters to keep in
mind when reusing the code:

- It does not validate `fmt_size`, `data` marker, `data_size`, block alignment,
  or byte rate.
- The four WAVs in the 2026-08-01 emulator fixture set all place PCM at byte
  78. The fixed-layout reader accepts them but starts at byte 76, so the final
  two bytes of their `data_size` field precede the PCM stream. This observed
  mismatch is tracked as parser/input-contract work, not hidden by this
  reference's description of the code.
- It does not check `FRESULT` or verify that the initial header read returned
  all 76 bytes before inspecting memory.
- It requires PCM mono through a compact three-byte comparison, but does not
  explicitly validate 8-bit samples.
- The sample rate is read from a 32-bit WAV field and used in 24-bit chunk/seek
  arithmetic, but the explicit create-sample command carries only 16 bits. No
  validation rejects rates above 65,535 Hz.
- The stream and seek calculations assume 8-bit mono: one sample equals one
  byte, so bytes per second equals sample rate.
- Duration uses the RIFF size divided by sample rate and deliberately ignores
  the 76-byte header.
- EOF is inferred from a zero-byte read rather than bounded by `data_size`.
- Standard 8-bit PCM WAV stores samples as **unsigned** values. The Agon VDP's
  default sample interpretation is the opposite—8-bit **signed** PCM—so the
  player must explicitly request unsigned format `1`. The command templates do
  this correctly with format byte `1+8` (`1` = unsigned, `8` = explicit sample
  rate). The source comment and operative command bytes therefore consistently
  specify 8-bit unsigned PCM mono.

AGM, MIDI, and codec tooling remains historical source material outside the
WAV-only candidate include graph. None of it participates in this WAV reader
or the assembled candidate binary.

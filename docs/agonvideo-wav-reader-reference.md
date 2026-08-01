# AgonVideo WAV reader and streaming reference

This document inventories the WAV-specific implementation in
`/home/smith/Agon/mystuff/AgonVideo/src/asm/`. It is a reference for file opening,
RIFF-style validation, streaming reads, VDP buffer management, and audio
playback. AGM video structures and video-unit processing are intentionally
excluded except where the shared WAV entry point branches to AGM.

## Source map

- `wav.inc`: opens files and validates the fixed WAV header.
- `play.inc`: initializes WAV playback, streams PCM data, alternates VDP
  buffers, and builds the buffered VDP sound command sequences.
- `files.inc`: assigns RAM addresses for the FatFS structures, copied
  `FILINFO`, WAV header, and streaming data.
- `timer_jukebox.inc`: drives streaming at 60 interrupts per second.
- `vdu_buffered_api.inc`: writes, calls, and clears VDP buffers.
- `vdu_sound.inc`: direct sound commands used during playback setup.
- `input.inc`: seeking and playlist selection around the WAV stream.
- `browse.inc`: discovers directory entries and calls the WAV verifier.
- `mos_api.inc`: `FFSCALL`/`MOSCALL` definitions and FatFS structure offsets.
- `agm.inc`: contains the shared `wav_*` header offsets at its beginning; the
  later AGM definitions are outside this document's scope.

## WAV layout required by the application

The reader does not walk arbitrary RIFF chunks. It reads and interprets one
fixed 76-byte header with these offsets:

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
| `wav_list_marker` | 36 | 4 | Required `LIST` chunk |
| `wav_list_size` | 40 | 4 | Required LIST payload size |
| `wav_info_marker` | 44 | 4 | Required `INFO` list type |
| `wav_isft_marker` | 48 | 4 | Required `ISFT` metadata chunk |
| `wav_isft_data` | 52 | 14 | Required software-string position |
| `wav_isft_padding` | 66 | 2 | Required padding/terminator position |
| `wav_data_marker` | 68 | 4 | Required `data` chunk identifier |
| `wav_data_size` | 72 | 4 | PCM payload size |
| `wav_data_start` | 76 | — | First PCM byte |

`wav_header_size` is therefore fixed at 76. This is an intentional application
format contract, not an attempt to implement a general RIFF/WAVE parser.
AgonVideo's release guidance requires WAV files prepared for the Agon to use
this exact chunk order and layout; otherwise-valid WAV variants with different
optional chunks or `data` offsets are deliberately outside the supported
format.

## Open and validation routines

### `bf_verify_wav` — `wav.inc:1`

Browser-side wrapper used while classifying directory entries.

- Preserves the caller's `IY`.
- Points `IY` at `bf_wav_header`.
- Calls `verify_wav` using the caller-supplied `HL` FIL pointer and `DE`
  filename pointer.
- Always closes the browser FIL with `ffs_fclose` after validation.
- Restores the verifier's `A` value and zero flag.

### `ps_open_wav` — `wav.inc:12`

Playback-side open wrapper.

- Calls `bf_get_filinfo_from_pg_idx` to obtain the selected entry in `IY`.
- Sets `DE = IY + filinfo_fname` and `HL = ps_fil_struct`.
- Points `IY` at `ps_wav_header` and calls `verify_wav`.
- Leaves a valid file open for streaming.
- Closes `ps_fil_struct` only when validation fails.
- Returns `A=1` for WAV, `A=2` for AGM, or `A=0` with Z set for failure.

### `verify_wav` — `wav.inc:38`

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
8. Returns `A=1`, NZ for WAV. The alternate `agm` branch calls `verify_agm` and
   is not relevant to a WAV-only reader.

The routine preserves `BC` and `IX`, but its comments declare `AF` destroyed.

## Playback and streaming routines

### `play_song` — `play.inc:39`

Top-level setup and dispatch routine. Its WAV path:

1. Calls `ps_close_file` to stop the timer and close prior playback state.
2. Resets the 60-tick chunk counter.
3. Calls `ps_open_wav` and reports invalid input on failure.
4. Copies the selected directory `FILINFO` into `ps_filinfo_struct` for the
   persistent filename and display metadata.
5. Sets the VDP's global sample rate from `wav_sample_rate` using
   `vdu_set_sample_rate` with channel `-1`.
6. Sets `read_media_routine = ps_read_sample` for the interrupt handler.
7. Computes approximate duration as RIFF file size divided by sample rate.
8. Computes `ps_wav_chunk_size = sample_rate / 60`.
9. Builds the two audio command buffers with `ps_load_audio_cmd_buffers`.
10. Selects and clears the first data buffer with `ps_set_audio_buffers`.
11. Marks playback active and starts the PRT timer at 60 Hz.

### `ps_read_sample` — `play.inc:151`

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

### `ps_play_sample` — `play.inc:225`

- Updates the elapsed-time UI through `ps_update_playbar`.
- Calls the current VDP command buffer with `vdu_call_buffer`.
- Calls `ps_set_audio_buffers` to alternate channels and prepare the next data
  buffer.

### `ps_set_audio_buffers` — `play.inc:236`

- Toggles `ps_channel` between 0 and 1.
- Maps the channel to command buffer `0x3000` or `0x3001`.
- Maps the channel to sample buffer `0x3002` or `0x3003`.
- Clears the newly selected sample buffer before more blocks are appended.

This is the double-buffering mechanism: one one-second sample may play while
the other VDP buffer is filled.

### `ps_close_file` — `play.inc:253`

- Stops the PRT timer with `ps_prt_stop`.
- Calls `ffs_fclose` on `ps_fil_struct`.

### `ps_load_audio_cmd_buffers` — `play.inc:353`

Builds two callable VDP command buffers, one per channel/sample-buffer pair.
For each pair it emits commands to:

1. Consolidate the uploaded blocks in the sample buffer.
2. Convert the buffer to an 8-bit unsigned PCM mono sample using the WAV
   sample rate.
3. Set the corresponding sound channel's waveform to that sample buffer.
4. Play the complete sample once at volume 127.

The command templates are `ps_cmd0`/`ps_cmd1`; `ps_sr0`/`ps_sr1` are patched
with the WAV sample rate before upload.

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
  paused, and calls the function pointer in `read_media_routine`. For WAV this
  pointer is `ps_read_sample`.

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

- `vdu_channel_volume`: silences/restores channels during song setup.
- `vdu_set_sample_rate`: sets the global sound sample rate when called with
  channel `-1`.

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
not the simpler handle-based `mos_fopen`/`mos_fread` interface used by the AGNB
loose-image test harness.

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
- `read_media_routine`: interrupt-time function pointer; WAV sets it to
  `ps_read_sample`.
- `ps_mode`: playing, loop, and shuffle bits.
- `ps_playhead`, `ps_song_duration`, `ps_seek_rate`: UI and seek state.

### VDP buffers

| Symbol | bufferId | Purpose |
|---|---:|---|
| `ps_wav_cmd_bufferId0` | `0x3000` | Callable command sequence for channel 0 |
| `ps_wav_cmd_bufferId1` | `0x3001` | Callable command sequence for channel 1 |
| `ps_wav_data_bufferId0` | `0x3002` | PCM sample blocks for channel 0 |
| `ps_wav_data_bufferId1` | `0x3003` | PCM sample blocks for channel 1 |

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

Two behaviors are conscious design decisions in AgonVideo:

- The reader accepts only the documented 76-byte Agon WAV layout and does not
  walk arbitrary RIFF chunks. Input preparation is responsible for producing
  that exact format.
- `RIFF`, `WAVE`, and `fmt ` comparisons inspect their low three bytes because
  the eZ80's native ADL registers are 24-bit. Under the controlled input-format
  contract, this avoids more cumbersome 32-bit comparison code. The fourth
  byte is intentionally not checked.

The following are separate implementation assumptions or matters to keep in
mind when reusing the code:

- It does not validate `fmt_size`, `data` marker, `data_size`, block alignment,
  or byte rate.
- It does not check `FRESULT` or verify that the initial header read returned
  all 76 bytes before inspecting memory.
- It requires PCM mono through a compact three-byte comparison, but does not
  explicitly validate 8-bit samples.
- The stream and seek calculations assume 8-bit mono: one sample equals one
  byte, so bytes per second equals sample rate.
- Duration uses the RIFF size divided by sample rate and deliberately ignores
  the 76-byte header.
- EOF is inferred from a zero-byte read rather than bounded by `data_size`.
- Standard 8-bit PCM WAV stores samples as **unsigned** values. The Agon VDP's
  default sample interpretation is the opposite—8-bit **signed** PCM—so the
  player must explicitly request unsigned format `1`. The command templates do
  this correctly with format byte `1+8` (`1` = unsigned, `8` = explicit sample
  rate). The `play.inc` introductory comment requiring signed PCM is therefore
  stale; AgonVideo's release documentation and operative command bytes both
  specify 8-bit unsigned PCM mono.

The most reusable ideas for AGNB are the caller-owned `FIL`, explicit header
buffer, separate streaming staging area, bounded read cadence, double-buffered
VDP upload, and prebuilt callable VDP command buffers. AGNB validation should
retain its metadata-first and enclosing-bound checks because AGNB has its own
container contract; it should not infer that AgonVideo's deliberately fixed WAV
layout is intended as a generic RIFF parsing strategy.

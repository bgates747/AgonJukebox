# WAV reader and streaming reference

This is the normative media contract for the `wavonly` AgonJukebox. The player
targets standard upstream Console8 VDP firmware and consumes ordinary
RIFF/WAVE files; it does not require a converter-specific metadata layout or a
fixed PCM offset.

## Accepted WAV subset

A playable file must satisfy all of these conditions:

- little-endian `RIFF` with `WAVE` form type;
- a complete `fmt ` chunk before the first `data` chunk;
- one channel;
- 8 bits per sample;
- one-byte block alignment;
- byte rate equal to sample rate;
- a nonzero sample rate from 1 through 65,535 Hz;
- a nonempty `data` chunk wholly contained in the declared RIFF container; and
- either `WAVE_FORMAT_PCM` (`wFormatTag = 1`) or
  `WAVE_FORMAT_EXTENSIBLE` (`wFormatTag = 0xFFFE`) with 8 valid bits and the
  `KSDATAFORMAT_SUBTYPE_PCM` GUID.

Eight-bit integer PCM in a WAVE file is unsigned, which matches the VDP sample
format used by the player. Stereo, signed/raw PCM, floating point, compressed
codecs, and sample rates above 65,535 Hz are rejected.

The reader scans chunks and observes RIFF word padding. Unknown chunks such as
`LIST`, `JUNK`, `bext`, and `fact` may appear before the audio data. Their
contents and sizes may vary. The PCM payload may therefore begin at any valid
offset; common byte-44, byte-78, and byte-102 files all use the same path.

## Parser contract

`src/asm/wav.inc` owns file opening and validation. `verify_wav` receives a
FatFS `FIL`, filename, and 76-byte state area. On success it returns nonzero,
leaves the file open, and leaves the FatFS pointer at the first PCM byte. On
failure it returns zero and closes any file it opened.

The parser:

1. reads and validates the 12-byte RIFF/WAVE preamble;
2. converts the RIFF size to an absolute container end and proves that it does
   not exceed the FatFS object size;
3. walks eight-byte chunk headers with 32-bit overflow, RIFF-boundary, and odd
   padding checks;
4. reads the common 16-byte `fmt ` prefix and, for extensible PCM, the required
   24-byte tail;
5. skips unsupported metadata chunks with `ffs_flseek`;
6. records the first supported `data` chunk's dynamic offset and declared
   payload size; and
7. rejects every FatFS error or short read encountered during parsing.

More than one `fmt ` chunk before `data` is rejected. A `data` chunk before a
supported `fmt ` chunk is rejected. Once the first supported `data` chunk is
found, playback begins there; later chunks are neither parsed nor streamed.

Browser probes use `bf_verify_wav`, which preserves `IY` and closes a valid
probe file after classification. Playback uses `ps_open_wav`, which retains
the successful file handle at the PCM payload.

## Normalized state

The old 76-byte header allocations remain at `bf_wav_header` and
`ps_wav_header`, but they now hold normalized parser state rather than a copied
file prefix.

| Offset | Symbol | Size | Meaning |
|---:|---|---:|---|
| 0 | `wav_riff_end` | 4 | Absolute end of the declared RIFF container |
| 4 | `wav_sample_rate` | 4 | Validated rate, with high bytes normalized |
| 8 | `wav_data_size` | 4 | Declared PCM byte count |
| 12 | `wav_data_offset` | 4 | Absolute first PCM byte |
| 16 | `wav_fmt_found` | 1 | Supported format was parsed |
| 17 | `wav_chunk_size` | 4 | Current chunk payload length |
| 21 | `wav_chunk_end` | 4 | Current padded chunk end |
| 25 | `wav_scratch` | 51 | Preamble, chunk header, and format scratch |

## Streaming schedule and data boundary

`src/asm/play.inc` streams one byte per mono sample into alternating VDP data
buffers `0x3002` and `0x3003`. Callable command buffers `0x3000` and `0x3001`
consolidate each sample buffer, create unsigned 8-bit PCM at that file's
explicit rate, assign it to stock sound channel 0 or 1, and play it once.

Timer 1 calls `ps_read_sample` 60 times per second. For sample rate `R`, the
base read size is `R / 60`; the remainder `R mod 60` is distributed across the
60 ticks. This quotient/remainder schedule uploads exactly `R` bytes per full
second, including rates not divisible by 60 and rates below 60 Hz. It does not
change the VDP global audio-system rate.

`ps_wav_bytes_remaining` is initialized from `wav_data_size`. Every request is
clamped to that 32-bit remainder, and the actual FatFS byte count is
subtracted. Playback therefore never consumes the RIFF pad or a chunk following
`data`. A FatFS failure or a zero-byte read before the declared boundary ends
the track as truncated input.

Duration is `ceil(data_size / sample_rate)`. If the final buffer contains less
than one second, `ps_prepare_eof_drain` computes
`ceil(60 * final_bytes / sample_rate)` timer ticks and allows that sample to
finish before automatic progression resets the channel.

## Seeking

The displayed playhead is one-based once a buffer starts. Seeking first derives
a zero-based target using Euclidean modulo:

```text
(displayed_playhead + signed_delta - 1) mod duration
```

During initial prebuffering the displayed playhead is still zero, so that
single state is already zero-based and omits the subtraction. This preserves
correct forward and backward wraparound even before the first sample begins.

The target byte is `target_second * sample_rate`, and the FatFS seek position
is `wav_data_offset + target_byte`. The remaining-byte count is recomputed from
`wav_data_size - target_byte`; scheduler, EOF, and drain state are reset before
streaming resumes. The display routine receives the same target and performs
its normal one-based increment independently.

## Interrupt and cleanup behavior

The timer handler saves its register sets, calls `ps_read_sample`, restores the
registers, and exits with `RETI`. Automatic playlist transitions historically
tail-jump through `play_song` and `get_input`; `ps_irq_transition` makes the
terminal input routine return once through the original call site so the
interrupt epilogue is not bypassed.

Song changes and exit reset stock sound channels 0 and 1. The candidate clears
only its four WAV buffers plus its font and logo resources. Whether startup
must instead reclaim all VDP buffers under real hardware memory pressure is an
explicit hardware decision whose context is recorded in `development-log.md`.

## Host-side converter

`scripts/make_wav.py` is the sole media-generation tool. It uses FFmpeg
to emit ordinary mono `pcm_u8` WAV files, optionally preserving or overriding
the source rate. It supports local files, shallow directory expansion, album
concatenation, a single URL through `yt-dlp`, trimming, normalization,
compression, and additional FFmpeg audio filters.

The converter validates output by scanning the RIFF file rather than loading
the PCM payload into memory. It accepts the same legacy and extensible PCM
representations as the target reader and reports the actual payload offset; it
does not rewrite the file into a private header layout.

## Practical limits

- The container and chunk fields are RIFF32, so RF64/Wave64 are unsupported.
- The VDP per-sample rate field limits playback to 65,535 Hz.
- The current UI and seek path use 24-bit duration/display arithmetic.
- The floating-point seek multiplication should be treated cautiously near or
  above the signed 2 GiB range until exercised on hardware.
- The player is mono and deliberately owns only channels 0 and 1.

Hardware qualification evidence is maintained in `development-log.md`.

## Current verification evidence

Host tests cover byte-44 PCM, arbitrary metadata and odd padding, trailing
chunks, byte-102 extensible PCM, invalid subtype and field combinations,
ordering and duplicate-format failures, truncation, empty data, and actual
FFmpeg output at the 65,535 Hz boundary. Existing emulator fixtures at 44,100,
48,000, and 65,535 Hz validate successfully at their natural byte-78 offsets.
The corrected assembly closes at 27,716 bytes in an isolated build. The user
also confirmed playback of the legacy and extensible fixtures plus directory
browsing, seeking, volume, and pause/resume behavior in the stock emulator.

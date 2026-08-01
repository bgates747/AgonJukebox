# Agon assembly programming and AGNB loading précis

## Scope and sources

This précis distils the official Agon documentation that bears directly on the
assembly code in this repository and on future eZ80 routines for consuming
Agon Buffer Container (`.agnb`) files. It is a design aid, not a replacement
for the command-by-command references.

The official documentation reviewed is the checkout at
`/home/smith/Agon/agon-docs`, commit
`f9806bd3cbff6ed5d1c08bef1d51fed11764b86b` (2026-07-16). The most relevant
files are:

- `docs/Theory-of-operation.md` and `docs/MOS.md` for architecture, memory, and
  program conventions;
- `docs/mos/API.md` for MOS calls, FatFS calls, sysvars, and status codes;
- `docs/VDP.md` and `docs/vdp/System-Commands.md` for the VDU stream, VDP
  protocol, VSync, and screen swapping;
- `docs/vdp/Buffered-Commands-API.md` for VDP buffer creation, upload,
  consolidation, calls, and decompression;
- `docs/vdp/Bitmaps-API.md` for turning a buffer into a bitmap; and
- `docs/vdp/Enhanced-Audio-API.md` for turning a buffer into a sample.

The local cross-reference concentrates on `src/asm/app.asm`, `mos_api.inc`,
`files.inc`, `vdu.inc`, `vdu_buffered_api.inc`, `vdu_sound.inc`, `wav.inc`,
`play.inc`, `agm.inc`, `timer_jukebox.inc`, and `test_uart.asm`.

The draft AGNB layout consulted for the implementation implications is
`/home/smith/Agon/mystuff/agon-utils/examples/agnb/docs/agon-buffer-file-format-specification.md`.

## The programming model

The Agon is a two-processor system without shared memory. The eZ80 executes the
application and accesses the SD card; the ESP32-PICO-D4 VDP owns display,
audio, keyboard, mouse, and its own asset memory. The processors communicate
over a UART running at 1,152,000 baud on MOS/VDP 1.03 and later (384,000 baud
before 1.03). An eZ80 program cannot write VDP memory or screen memory directly:
it sends a byte stream of VDU commands and data, and MOS receives VDP response
packets into its sysvars.

This separation determines the loader architecture. File bytes travel from SD
card to eZ80 RAM and then across the UART into a named VDP buffer. Buffering is
not merely an optimization: it packetises potentially long assets so unrelated
VDU commands are not mistaken for asset bytes.

## Executable, addressing, memory, and stack

`src/asm/app.asm` follows the normal standalone-program convention:

- `assume adl=1` selects 24-bit ADL operation;
- `org 0x040000` uses MOS's default standalone load address;
- execution jumps over an aligned `"MOS", 0, 1` executable header; and
- the entry point preserves registers and returns an exit status in `HL`.

The official MOS memory map assigns `0x040000` through `0x0AFFFF` to ordinary
user RAM, `0x0B0000` through `0x0B7FFF` to moslets/modules, and
`0xB7E000` through `0xB7FFFF` to the eZ80's 8 KiB internal fast RAM. The
project's application structures through the `0x090000` region are within the
normal user range, while `filedata` at `0xB7E000` intentionally uses the fast
8 KiB RAM as a transfer block.

MOS supplies the ADL stack. The program must balance every push/pop and must not
replace or corrupt `SPL`, because the same stack remains important to MOS after
the program returns. Z80-mode programs have a separate, undefined `SPS`, but
that is not the mode used here.

The official API reference says MOS reset handlers assume `RST.LIS`; this
project's includes consistently emit `RST.LIL`. The existing binaries work, so
this should be treated as an assembler/firmware compatibility point to verify
against the exact `ez80asm` and target MOS versions before mechanically
changing suffixes. New code should follow one verified project convention.

## MOS and VDP entry points

The project uses the three essential MOS reset services:

| Entry | Official contract | Use in this project |
| --- | --- | --- |
| `RST 08h` | Put the MOS/FatFS function number in `A`; other registers are API-specific. | `MOSCALL` and `FFSCALL` wrap file, keyboard, directory, and sysvar operations. |
| `RST 10h` | Send the single byte in `A` to the VDP. | Text and single VDU controls. |
| `RST 18h` | Send `BC` bytes from `HL(U)`, or a delimited stream when `BC=0`; requires MOS 1.03+. | All multi-byte VDU commands and bulk buffer data. |

In ADL mode pointers passed to MOS are 24-bit and `MB` must be zero. Calls often
return a status in `A`, where zero means success; FatFS calls return the closely
related `FRESULT`. New parsing code should check failures and short reads at
every structural boundary rather than relying only on an eventual zero-byte
read.

`mos_sysvars` returns a 24-bit pointer in `IX`. The project uses this for screen
mode, keyboard state, and timing. VDP responses are asynchronous: for commands
that return information, clear the relevant VDP-protocol flag before sending
the request, then wait for it and inspect the associated sysvar. MOS 3 provides
`mos_clearvdpflags` and `mos_waitforvdpflags`; older-compatible code can poll the
sysvars carefully.

The local `mos_api.inc` dates from 2023. Its early API numbers remain useful,
but it is not a complete current MOS 3 definition: among other differences, the
official sysvar layout now includes mouse fields and an eight-byte RTC region,
and MOS 3 adds pointer-based 32-bit seek calls. Any new dependency on later MOS
features should update or locally extend the definitions from the official API,
with an explicit minimum MOS version.

## File I/O choices

The official documentation now recommends MOS handle-based file calls for
ordinary I/O because MOS 3 resolves system variables and path prefixes. FatFS
calls require fully resolved paths and caller-owned `FIL` structures. An open
method and close method must not be mixed.

This repository demonstrates both valid styles:

- `vdu_load_buffer_from_file` uses `mos_fopen`, `mos_fread`, and `mos_fclose`
  with a one-byte handle; and
- the browser, WAV, AGM, and UART-test paths use `ffs_fopen`, `ffs_fread`,
  `ffs_flseek`, and `ffs_fclose` with fixed `FIL` structures.

For a new sequential AGNB loader, MOS handles are the smaller and more
future-facing interface. Reusing the existing FatFS path is also reasonable if
integration with the browser requires an already-open `FIL`. The choice should
be made once at the loader boundary. If random access is later required, MOS 3's
pointer-based `mos_flseek_p`/`ffs_flseek_p` avoids the older split-register
32-bit convention.

AGNB sizes are unsigned 32-bit values, but an ADL pointer or native count is
only 24 bits. The reader therefore needs explicit 32-bit remaining-length
state. It must reject unsupported sizes rather than truncate their high byte,
and it must verify that every `8 + align4(payload_size)` calculation stays
within both the enclosing `LIST` and top-level RIFF boundary.

## The VDU stream and VDP buffers

The VDP consumes an unframed, variable-length command stream. Once a command
prefix announces a payload length, exactly that many payload bytes must follow
without an intervening text, drawing, audio, or debugging command. Losing byte
alignment can cause all subsequent bytes to be misinterpreted.

The Buffered Commands API avoids this for large assets. Its common prefix is:

```text
23, 0, 0xA0, bufferId(lo), bufferId(hi), command, ...
```

Buffer IDs are 16-bit and little-endian. ID `65535` is reserved. Buffers are
not guaranteed to be empty when an application starts, so an application must
clear each owned buffer before its first write. Command 0 appends one block;
repeated writes to the same ID accumulate blocks automatically. An individual
block is limited to 65,535 bytes, while a buffer may contain multiple blocks
and exceed that size.

`vdu_clear_buffer`, `vdu_load_buffer`, `vdu_consolidate_buffer`, and
`vdu_call_buffer` in the project correctly model commands 2, 0, 14, and 1.
`vdu_load_buffer` sends the command header and then the announced bytes with a
second `RST 18h`; that pair must remain uninterrupted.

The official documentation recommends transfer blocks around 1 KiB or less to
avoid long UI stalls, but this is responsiveness guidance, not a protocol
limit. The project's `filedata` routine uses 8 KiB blocks for preload, while
`test_uart.asm` records 960 bytes as the safe payload within one 1/60-second
real-time slot. These are different constraints:

- preloading may use larger blocks if temporary blocking is acceptable; and
- playback-time streaming must obey the measured per-tick UART and decoder
  budget, including command overhead.

The VDP has roughly 4 MiB available for buffers, commands, bitmaps, and sound
samples in the documented firmware. Allocation failures for buffered commands
generally are not reported back to MOS, so buffer ranges and peak memory use
must be planned and tested. Clearing buffer `65535` clears every VDP buffer and
can destroy assets owned by another component; prefer clearing only the
application's declared range.

## Bitmap and audio finalization

An uploaded buffer is raw data until it is given a form-specific meaning.

For a bitmap:

1. Clear its buffer.
2. Append all pixel blocks with buffered command 0.
3. Consolidate command 14, because bitmap data must occupy one contiguous VDP
   block.
4. Select the 16-bit buffer with `VDU 23, 27, 0x20, bufferId;`.
5. Create the bitmap with `VDU 23, 27, 0x21, width; height; format`.

The existing `vdu_load_img` follows exactly this pattern. Supported public
formats are RGBA8888 (`0`), RGBA2222 (`1`), and monochrome/mask (`2`). For
RGBA2222 the component order is alpha, blue, green, red from high to low bits;
any nonzero alpha is treated as fully visible rather than blended.

For audio, multiple VDP blocks are acceptable and consolidation is unnecessary.
Enhanced Audio command 5, subcommand 2 creates a sample from a buffer, with
format `0` for signed 8-bit or `1` for unsigned 8-bit. Bit `8` indicates that a
16-bit sample rate follows. A waveform-selection command then associates that
sample buffer with a channel. The project's `vdu_buffer_to_sound` and command
buffers already embody this flow. AGNB draft 0.1 deliberately leaves `AUDI`
undefined, so a version-0.1 reader must skip/reject it rather than guess its
metadata.

## Timing, interrupts, and presentation

`VDU 23, 0, 0xC3` swaps buffers at the next VSync in a double-buffered mode, or
waits for VSync in a single-buffered mode. That is the correct presentation
primitive for tear-free frame updates. The current `vdu_vblank` helper instead
polls the MOS centisecond sysvar until it changes; because that value is updated
at VBlank it is useful for rough synchronization, but it is not itself the VDP
screen-swap command.

`timer_jukebox.inc` installs a 60 Hz peripheral-timer interrupt and currently
allows media reads and VDU transfers to occur from its handler. That existing
design is useful evidence but should not automatically become the AGNB loader
model. Initial AGNB asset loading belongs outside the interrupt handler. For
later real-time consumption, the interrupt should ideally update state or
perform a bounded buffer handoff, with SD-card reads, structural parsing, and
large UART transfers scheduled cooperatively in foreground code. This limits
interrupt latency and makes incomplete VDU payloads less likely.

## AGNB reader mapped to existing routines

The draft format is naturally compatible with the Agon APIs and this codebase:

| AGNB element | Reader action | Existing foundation |
| --- | --- | --- |
| `RIFF`/`AGNB`, `VERS` | Read fixed headers, compare FourCCs and supported major version. | `verify_wav`/`verify_agm` show fixed-header reads and byte comparisons. |
| Generic chunk header | Read 8 bytes; maintain a 32-bit payload and enclosing-end boundary. | `agm_read_*_hdr` provides the small-header pattern, but needs stronger status/short-read checks. |
| Unknown chunk | Seek or read-discard `align4(size)` bytes without escaping its parent. | Existing seek and chunk loops are reusable concepts. |
| `LIST BUFR` | Establish a nested end boundary and require `BHDR`, one supported descriptor, then `DATA`. | New state machine required. |
| `BHDR` | Read the exact little-endian 16-bit destination ID; validate ownership/range. | VDP helpers already accept the ID in `HL`. |
| `IMAG` | Retain the five-byte width/height/format payload for direct VDP use after transfer. | `vdu_buff_select` and `vdu_bmp_create`. |
| `DATA` | Clear once, then loop: read bounded eZ80 block, append it to the VDP buffer, decrement 32-bit remaining count. | `vdu_load_buffer_from_file` is the closest implementation template. |
| End of image record | Validate `width * height == DATA size` for RGBA2222, consolidate, select, create bitmap. | `vdu_load_img`. |

The AGNB metadata was intentionally laid out in VDP byte order. `BHDR` can feed
the 16-bit buffer argument directly, and the five `IMAG` bytes match the
width/height/format arguments after the bitmap-create prefix. A parser still
needs to validate them before transmission.

## Recommended implementation shape

Keep the first reader small and explicit:

1. Open once and record the physical file size if available.
2. Read and validate the 12-byte RIFF header and two-byte `VERS` payload.
3. Track absolute 32-bit ends for RIFF, the current `LIST BUFR`, and the current
   chunk.
4. Dispatch known FourCCs through a compact state machine; skip unknown chunks
   using their declared aligned size.
5. For a supported `IMAG` record, validate metadata, clear its declared buffer,
   and stream exactly `DATA.size` bytes through a fixed eZ80 transfer buffer.
6. Treat any API error, zero/short read before the declared end, arithmetic
   overflow, order violation, duplicate required chunk, or boundary escape as a
   hard malformed-file error.
7. Consolidate and create the bitmap only after the complete validated payload
   arrives.
8. Close the file on every success and failure path and return a meaningful MOS
   status to the caller.

For a trusted, build-generated asset pack, duplicate buffer IDs may be rejected
by the packer and omitted from the target's runtime tracking to save RAM. The
reader should still enforce an application-owned buffer-ID range or table so a
malformed file cannot clear or overwrite unrelated VDP buffers.

## Decisions to settle before coding

- Minimum MOS and VDP firmware versions. MOS 1.03 covers the current bulk I/O
  and buffered path; newer APIs may justify a higher declared floor.
- MOS handles versus the existing FatFS `FIL` integration point.
- The application-owned VDP buffer-ID ranges and collision policy.
- Maximum accepted RIFF, record, and `DATA` sizes, especially where 32-bit disk
  values exceed 24-bit eZ80 quantities.
- Preload transfer size and, separately, any real-time transfer budget.
- Whether malformed-file diagnostics are numeric MOS statuses, screen messages,
  or both.
- Whether compressed AGNB records will later use stock TurboVega command 65 or
  a custom decoder. Stock command 65 expects a complete compressed stream and
  produces one decompressed block; the draft format currently defines only
  verbatim `DATA`.

These choices can be isolated behind the parser's file-read, buffer-write, and
record-finalize routines, allowing the on-disk state machine to remain stable
as loading and compression strategies evolve.

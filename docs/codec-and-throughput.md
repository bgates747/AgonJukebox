# Codec and throughput

## Hard transport budget

The newer Agon firmware uses a UART rate of 1,152,000 bits per second between
the eZ80 and VDP. Assuming 8N1 framing, each payload byte consumes ten serial
bits, giving a theoretical ceiling of 115,200 bytes per second.

At 16 kHz and eight bits per mono sample, audio consumes 16,000 bytes per second.
That leaves at most 99,200 bytes per second for video, framing, commands, and
other protocol overhead.

At 300x200, an unpacked frame is 60,000 bytes. Fifteen raw frames per second are
900,000 bytes, so video must average no more than about 6,613 bytes per frame
before overhead. This is approximately 9.1:1 compression. A practical codec
target should be lower than 99,200 video bytes per second to retain transport
margin; 95,000 bytes per second is a useful initial test threshold, not yet a
formal requirement.

These calculations depend on the assumed UART framing and exclude any flow
control or VDP-command overhead. Measurements on the final protocol supersede
them.

## Existing compression pipeline

The known conceptual pipeline is:

1. Convert frames to the 300x200, 64-color target representation.
2. Apply Bayer-matrix dithering. Its deterministic patterns improve spatial and
   temporal repetition.
3. Apply "delta framing": compare each pixel with the pixel at the same location
   in the previous frame, replacing a match with zero.
4. Compress the resulting stream with RLE2.
5. Compress the RLE2 output with SZIP.

Despite its name, delta framing does not encode a numeric difference. Zero is a
same-as-previous-frame sentinel. The combination of stable Bayer patterns and
this sentinel produces runs that RLE2 can exploit.

RLE2 has a useful worst-case property: a frame containing no compressible runs
can be encoded at exactly the original image size. The precise command grammar,
including how literal zero and transparent pixels interact with the sentinel,
must be recovered from code or the format specification.

SZIP substantially reduces the intermediate stream, making the UART bandwidth
promising, but its ESP32 decompressor is computationally expensive. Decoder
throughput, rather than compressed size alone, became the observed bottleneck.

## Optimization problem

The codec must be judged on both transmitted size and VDP work. Saving UART
bytes is counterproductive if the ESP32 cannot decode and display frames in real
time while also servicing audio.

The two current lines of investigation are:

### Improve the first stage

Potential experiments, not design decisions, include:

- directly coding unchanged spans rather than materializing zero bytes;
- distinct commands for skipped, repeated-color, and literal spans;
- inexpensive prediction from the previous frame, preceding pixel, or preceding
  scanline;
- byte-aligned short forms for common commands and run lengths; and
- six-bit packing for literal opaque colors if the savings outweigh unpacking
  cost.

### Improve or replace SZIP decoding

The existing source must first be profiled. Candidate changes should favor
bounded, linear operations, predictable branches, and byte-aligned input. A
somewhat larger stream is acceptable if it produces materially cheaper decoding
and remains within the UART budget.

No replacement algorithm has been selected. In particular, sophisticated
entropy coding should not be assumed beneficial until decompression cost is
measured on the ESP32.

## Benchmark requirements

Codec comparisons should use representative converted footage and report:

- total and average video bytes per second;
- bytes in each one-second window;
- average and worst encoded frame size;
- average and worst ESP32 decode time;
- time spent copying, reconstructing, and swapping framebuffers;
- audio-buffer underruns and video frames missed; and
- working-memory usage.

The worst one-second window matters more than whole-file average because the
available buffering must absorb locally complex scenes. Tests should include
static imagery, modest motion, scene cuts, scrolling or camera motion, animation,
and noisy live-action footage.

## Unresolved questions

- What exactly are the RLE2 and SZIP bitstream grammars?
- Which SZIP operations dominate ESP32 decode time?
- Does the decoder reconstruct into a fresh buffer, alternate persistent
  buffers, or copy a reference frame before applying changes?
- What are the actual free heap, largest allocatable block, and stable buffer
  sizes in the custom VDP build?
- How much UART and command overhead exists in the real playback protocol?
- Is transparency required during video playback, or can all transported colors
  be treated as opaque?
- What source material defines the expected visual-quality and compression
  workload?
- How is synchronization currently signaled between audio chunks, video frames,
  and frame swaps?


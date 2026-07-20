# Project overview

## Platform

The Agon Light is a standalone computer built around an eZ80 main processor and
an ESP32-PICO-D4 VDP. The eZ80 communicates with the VDP over a high-speed UART.
The VDP handles VGA output, audio, and keyboard input.

AgonVideo targets a mostly stock VDP environment, augmented with custom firmware
for video decompression. The stock VDP can frame-swap, which is essential to the
proposed player.

## Existing audio player

The existing application is written in eZ80 assembly and plays compatible
8-bit PCM WAV files. It already provides:

- browsing of the Agon's normal filesystem;
- rejection of unsupported WAV encodings and unrelated file types;
- alphabetization and display of playable files in a selection menu;
- streaming of audio to the VDP over UART in one-second chunks; and
- forward and backward seeking in one-second increments, with larger jumps up
  to 240 seconds.

This application is the base onto which synchronized video playback will be
added. Audio and video will share the eZ80-to-VDP UART.

## Intended video characteristics

The current target is:

- 300 by 200 pixels;
- approximately 15 frames per second;
- RGBA2222 source pixels, one byte per pixel and 64 possible RGB colors;
- binary transparency: alpha zero is transparent and any nonzero alpha value is
  opaque; and
- 16 kHz, 8-bit audio.

Because opacity is binary, a logical pixel requires seven bits when transparency
is retained, or six bits when transparency is irrelevant. RLE2 uses the two
alpha bits as control information so a literal single pixel can be represented
without expanding an incompressible frame beyond its original byte-per-pixel
size.

The ESP32 has enough usable memory to buffer roughly one second of video and
audio at the target settings. Approximately 4 MB is believed to be the practical
upper boundary, although operation becomes unreliable or difficult near that
amount. This must be measured against the actual firmware build rather than
treated as a guaranteed capacity.

## Container

A custom media-file format already exists and is described as detailed and
extensible. Its header borrows RIFF/WAV idioms, and provision was made for future
header information. Frame-level video metadata is also believed to be
extensible, but this needs confirmation from the original specification or
source.

The file deliberately resembles an 8-bit, mono PCM WAV closely enough that a
standard WAV player can interpret its contents as a PCM stream, although the
video data naturally sounds like noise. Compatibility details and chunk layout
remain to be recovered.

Seeking and indexing for combined media are intentionally deferred until the
throughput and decoder-performance problems are solved.

## Immediate goals

1. Recover and document the existing file format, encoder, RLE2, and SZIP.
2. Determine whether the video stream can fit through the UART with safe margin.
3. Improve the first compression stage.
4. Reduce VDP decompression cost without sacrificing excessive compression.
5. Only after real-time playback is feasible, design combined-media seeking.


# AgonVideo documentation

AgonVideo is an eZ80/ESP32 video player for the Agon Light family of
retrocomputers. It builds on an existing eZ80 assembly application that plays
8-bit PCM WAV files through the Agon VDP.

This directory records the design as it is recovered and developed. Statements
marked as assumptions or proposals are not yet part of the file format or
implementation.

## Documents

- [Development log](development-log.md) — chronological record, current status,
  decisions, blockers, and immediate next steps.
- [Development setup](development-setup.md) — cloning, submodules, Python
  environment, and dependency setup.
- [Project overview](project-overview.md) — existing application, target system,
  and intended video extension.
- [Codec and throughput](codec-and-throughput.md) — current video pipeline,
  bandwidth budget, optimization goals, and open experiments.
- [Agon assembly and AGNB loading précis](agon-assembly-and-agnb-precis.md) —
  official MOS/VDP contracts cross-referenced against the existing assembly,
  with an implementation map for a streaming AGNB reader.

## Working vocabulary

- **VDP** — the ESP32 coprocessor responsible for video, audio, and input.
- **RLE2** — the project's first-stage run-length encoding scheme. The origin of
  the suffix `2` has not yet been recovered.
- **SZIP** — the project's second-stage compressor. Its precise algorithm and
  provenance will be documented after the original source is imported.
- **Delta framing** — the project's informal name for replacing a pixel with
  zero when it matches the pixel at the same position in the previous frame.

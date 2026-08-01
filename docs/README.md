# AgonJukebox documentation

AgonJukebox is an eZ80 WAV player for the Agon Light family of retrocomputers.
The WAV-only candidate targets stock upstream VDP firmware. Historical video,
codec, AGM, and MIDI work remains documented but is outside the intended
product boundary.

This directory records the design as it is recovered and developed. Statements
marked as assumptions or proposals are not yet part of the file format or
implementation.

## Documents

- [Development log](development-log.md) — chronological record, current status,
  decisions, blockers, and immediate next steps.
- [Development setup](development-setup.md) — cloning, the Python environment,
  and canonical `agon-utils` dependency setup.
- [Project overview](project-overview.md) — existing application, target system,
  and current WAV-only product boundary.
- [Audio-only archaeology](audio-only-jukebox-archaeology.md) — branch and
  deployed-binary provenance, lost Oryx work, and the reduction rationale.
- [WAV reader reference](agonvideo-wav-reader-reference.md) — prefix checks,
  fixed-offset streaming assumptions, buffers, controls, and cleanup behavior.
- [Branch inventory](branches_inventory.md) — a dated snapshot of branch
  purposes and recent history.
- [Codec and throughput](codec-and-throughput.md) — historical video pipeline,
  bandwidth budget, optimization goals, and open historical experiments.
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

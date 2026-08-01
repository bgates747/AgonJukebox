# Project overview

## Platform

The Agon Light is a standalone computer built around an eZ80 main processor and
an ESP32-PICO-D4 VDP. The eZ80 communicates with the VDP over a high-speed UART;
the VDP handles video output, audio, and keyboard input.

AgonJukebox's intended target is the standard upstream Console8 VDP. The
WAV-only candidate does not require bespoke firmware.

## Application

AgonJukebox is an eZ80 assembly application for compatible 8-bit unsigned PCM
mono WAV files. Its established functionality includes:

- filesystem browsing with filtering, sorting, ten-entry pages, and highlighted
  selection;
- two alternating one-second VDP audio buffers filled by 60 SD-card reads per
  second;
- play/pause, loop, shuffle, random selection, and automatic progression;
- forward and backward seeking at selectable 1–240 second increments;
- filename, duration, elapsed time, rate, mode, seek, and volume display;
- per-file sample-rate selection; and
- persistent logical master volume across song changes.

The fixed-offset assumptions and unresolved input-contract decision are
documented in
`docs/agonvideo-wav-reader-reference.md`.

## Intended product boundary

The candidate binary is intentionally WAV-only. AGM video playback, MIDI
playback and synthesis, and experimental output-limiter commands are excluded.
The limiter depended on a private VDP firmware modification that is not part of
the intended product contract.

Historical AGM, video-codec, MIDI, and media-generation sources remain in the
repository as archaeological material and possible future research. They are
not included by `src/asm/app.asm` and are not required to build or run the
Jukebox.

## Current direction

The `wavonly` branch reconstructs the clean audio application from the current
documentation line: the proven v0.9.5 WAV core plus the stock-compatible
v0.9.6-beta volume and sample-rate display. The v0.9.5 core already embeds the
file rate per buffer; the later global-rate mutation is explicitly excluded.
Basic pitch and interactive controls have passed emulator checks. Cross-rate
transitions, long-form continuity, final state restoration, and the scoped
VDP-buffer policy must be confirmed on physical hardware before this candidate
replaces the deployed binary.

# Experimental PCM meter

**Visualization design credit: Pollito / SanPollo — Nick J. Date, author of
agonAMP.** Its paced, incremental changed-cell rendering inspired this meter's
bounded changed-column updates, bar decay and desired/displayed state. See
https://github.com/SanPollo/agonAMP/blob/tag1.1/src/spectrum.asm at91ef401 and
vendor/agonamp-visualization/LICENSE. The implementation here is independently
written for bitmap skins. The PCM filter bank is separate from agonAMP's AY
frequency/volume/harmonic estimates; it measures the samples Jukebox uploads.

The default app.asm / app_runtime.asm build uses only standard MOS synchronous
VDU output. There is no UART extension discovery, session or batch setting.
A short PRT1 handler posts audio due work; the foreground loop handles audio,
UI, keys and optional analysis. This changes audio scheduling from the legacy
ISR player, but introduces no custom firmware dependency. A1024-byte window feeds a ten-level pair-average/
absolute-difference (Haar-like) analysis. Bars show mean absolute detail at ten
scales, low-to-high. They are broad, overlapping, sample-rate-dependent responses,
not calibrated rectangular frequency bands or FFT power. Two-tap averaging has
limited stopband rejection; no strong antialiasing claim is made. Constant/DC
input gives zero. Tones move the strongest response across the columns as
frequency changes. LED levels are log2-like steps; falls are one LED per frame.

Work is bounded to32 pairs per foreground slice, with no MOS, VDU or IRQ work
inside the analysis core. Audio ticks and key polling precede optional service.
The fixed1024-byte scratch window is separate from WAV staging and the MOS-
borrowed packet. At most one window starts per6 audio feed ticks. Low rates
need longer windows and produce fewer updates. Incomplete windows/jobs at a
VDP sample boundary are discarded instead of delaying playback.

Each result belongs to a100ms slot of the VDP sample being built. At sample
play, those envelopes are copied to the display timeline; uploading the next
second does not advance the displayed analysis. Pause freezes that logical timeline;
track/seek/skin reset it. The existing player can let its currently playing
one-second VDP sample finish after pause; this experiment does not change that
audio behavior or promise sample-accurate pause/resume visual synchronization. These are application command/timer boundaries, not
receiver acknowledgements or microsecond-accurate audible synchronization.
Window placement introduces up to1024/sample_rate seconds of temporal blur.
Short end fragments may have no complete window and show no new measurement.

Nineties opts in with spectrum.bin and spectrum.agnb. Other skins keep their
static artwork and incur no DSP/drawing work. The16-byte descriptor is:
SPC1, x/u16, y/u16, pitch/u8, width26, height41, columns10, levels6, zero3.
Coordinates/pitch are checked against512x384. The seven shared26x41 RGBA2222
bitmaps use IDs2800..2806, outside current skin/font/audio IDs. All bitmap data
is loaded/validated through canonical AGNB. Optional malformed assets disable
this feature with a diagnostic; they never become executable skin commands.

A changed column is one16-byte ordered compatibility packet; at most ten
columns per100ms display frame, maximum1600 bytes/audio-second, plus up to160 bytes per lifecycle clear. Bitmap states use7462 VDP pixel bytes. V toggles analysis off/on
for review; paused bars freeze. Re-enabling discards the partial current
upload and reacquires the real next sample boundary before collecting, so
there may be up to two seconds before fresh measured bars return. The report /JSPEC.DAT is written after normal
quit, never continuously during playback. Format: SPM1, version1, enabled,
error, reserved0, then five LEu32 counters: completed windows, DSP slices,
columns plotted, spectrum UART bytes, jobs discarded at sample handoff.
No experimental /JUART.DAT transport report is produced. V is a prototype review control.

Pure core checks execute the assembled eZ80 instructions against an independent
host reference. Model cycles/instructions describe that core without hardware
wait states, ISR preemption, capture, renderer, SD or UART costs; they are not
proof of physical spare CPU cycles or audio continuity. The analyzer was functionally accepted on hardware in the earlier prototype.
This stock-only integration is independently qualified; physical review of the
new executable and calibrated hardware timing remain separate.

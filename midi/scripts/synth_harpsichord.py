#!/usr/bin/env python3
"""
Additive-synthesis harpsichord sample generator
----------------------------------------------

• Generates one 16 384 Hz, 8-bit mono WAV per MIDI note (inclusive range).
• Pure additive: each note = sum of harmonic partials with per-partial envelopes.
• Dual 8′ courses (two strings) with slight detune for natural shimmer.
• Optional 4′ stop (octave-up) can be enabled with a single flag.

Output directory: midi/tgt/harpsichord
Output file naming: <midi_note:03d>.wav  (e.g. 024.wav … 072.wav)
"""

import os
import numpy as np
import soundfile as sf

# -------------------------------------------------------------------- #
#  Fixed synthesis constants
# -------------------------------------------------------------------- #
SAMPLE_RATE      = 16384        # Hz
NYQUIST          = SAMPLE_RATE / 2
DURATION         = 1.0           # seconds per note
FADE_MS          = 300           # safety fade-out
NUM_PARTIALS     = 32            # additive harmonics (clipped by Nyquist)
DETUNE_CENTS     = 2.0           # cents between the two 8′ strings
FOUR_FOOT        = True          # True → include 4′ stop (octave up) @ 50 %
NOISE_CLICK_DB   = -18           # level of 2 ms quill click (dB)

OUTPUT_DIR       = "midi/tgt/harpsichord"
MIDI_START       = 21
MIDI_END         = 88

np.random.seed(0)                # repeatable shimmer


# -------------------------------------------------------------------- #
#  Helper functions
# -------------------------------------------------------------------- #
def db_to_amp(db):          # convert dB to linear amplitude
    return 10 ** (db / 20.0)


def midi_to_freq(m):        # equal-tempered A4 = 440 Hz
    return 440.0 * 2 ** ((m - 69) / 12)


def additive_harpsichord(freq, partials=NUM_PARTIALS):
    """
    Return a 1-D float32 array (−1…+1) of a single harpsichord note.

    Implementation notes:
    • each partial gets its own exponential decay:  τ_k = τ_base / k
    • τ_base scales with pitch so bass notes ring slightly longer
    • amplitude roll-off  ~ 1/k  (bright)
    • two detuned strings (8′ & 8′ detuned)  + optional 4′ string
    • 2 ms broadband click mixed at note onset
    """
    n_samples = int(SAMPLE_RATE * DURATION)
    t = np.linspace(0, DURATION, n_samples, endpoint=False, dtype=np.float32)
    out = np.zeros_like(t)

    # base decay constant: lower notes longer
    midi_note = 69 + 12 * np.log2(freq / 440.0)
    octave_diff = (60 - midi_note) / 12.0
    tau_base = 1.2 * (2 ** octave_diff)        # ~1.2 s around middle C

    # loop over harmonic numbers
    for k in range(1, partials + 1):
        f_k = k * freq
        if f_k >= NYQUIST - 50:          # leave margin
            break

        # amplitude roll-off and per-partial envelope
        amp = 1.0 / k
        env = np.exp(-t / (tau_base / k))

        # two 8′ strings
        cents_shift = DETUNE_CENTS / 2
        phases = np.random.uniform(0, 2*np.pi, 2)
        for sign, ph in zip((-1, +1), phases):
            detune = 2 ** (sign * cents_shift / 1200.0)
            out += 0.5 * amp * env * np.sin(2 * np.pi * f_k * detune * t + ph)

        # optional 4′ course (octave up) at half amplitude
        if FOUR_FOOT and f_k*2 < NYQUIST - 50:
            out += 0.25 * amp * env * np.sin(2 * np.pi * f_k*2 * t + phases[0])

    # add 2 ms quill click
    click_len = int(0.002 * SAMPLE_RATE)
    click_env = np.linspace(1, 0, click_len, dtype=np.float32)
    click_noise = db_to_amp(NOISE_CLICK_DB) * np.random.randn(click_len).astype(np.float32)
    out[:click_len] += click_noise * click_env

    # normalise
    peak = np.max(np.abs(out))
    if peak > 0:
        out /= peak

    # linear fade-out
    fade_n = int(FADE_MS / 1000 * SAMPLE_RATE)
    if fade_n > 0:
        out[-fade_n:] *= np.linspace(1.0, 0.0, fade_n, dtype=np.float32)

    return out.astype(np.float32)


def save_u8_mono(waveform: np.ndarray, filename: str):
    """Write float32 (−1…+1) to unsigned 8-bit PCM WAV."""
    os.makedirs(os.path.dirname(filename), exist_ok=True)
    sf.write(filename, waveform, SAMPLE_RATE, subtype="PCM_U8")
    print("saved", filename)


# -------------------------------------------------------------------- #
#  Batch generation
# -------------------------------------------------------------------- #
def generate_bank(midi_lo=MIDI_START, midi_hi=MIDI_END):
    # clear old files
    if os.path.isdir(OUTPUT_DIR):
        for f in os.listdir(OUTPUT_DIR):
            p = os.path.join(OUTPUT_DIR, f)
            if os.path.isfile(p):
                os.remove(p)

    for m in range(midi_lo, midi_hi + 1):
        w = additive_harpsichord(midi_to_freq(m))
        save_u8_mono(w, os.path.join(OUTPUT_DIR, f"{m:03d}.wav"))


# -------------------------------------------------------------------- #
if __name__ == "__main__":
    generate_bank()
    print("Done.")

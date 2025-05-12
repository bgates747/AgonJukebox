#!/usr/bin/env python3
"""
Harpsichord Sample Generator (additive, 8' + 4' choirs)

Derived from the earlier piano‐synthesis script but with parameter tweaks
and octave-doubling to approximate the two choirs of a harpsichord.
"""

import os
import numpy as np
import soundfile as sf
from pydub import AudioSegment
from pydub.playback import play


# ---------------------------------------------------------------------------
# Utility: fixed 2-choir voice count (8-foot + 4-foot courses)
# ---------------------------------------------------------------------------
def get_harpsichord_voice_count(_: int) -> int:
    """Harpsichords typically have 2 choirs for most keys."""
    return 2


# ---------------------------------------------------------------------------
# Core synthesis
# ---------------------------------------------------------------------------
def generate_harpsichord_note(
    base_freq: float,
    midi_note: int,
    sample_rate: int,
    duration: float,
    num_partials: int,
    inharmonicity: float,
    detune_cents: float,
    attack_time: float,
    octave_decay_factor: float,
    spectral_rolloff: float,
    partial_decay_constant: float,
    loudness_exponent: float,
    pitch_randomness_cents: float,
    fade_time_ms: float
):
    """
    Return a harpsichord note as a float32 numpy array in −1…+1.

    Two courses:
      * first voice: 8′ (base pitch)
      * second voice: 4′ (one octave up) at 50 % amplitude

    All parameters mirror the earlier piano function so therest of the
    codebase remains unchanged.
    """
    N = int(sample_rate * duration)
    t = np.linspace(0.0, duration, N, endpoint=False, dtype=np.float32)
    signal = np.zeros(N, dtype=np.float32)

    unison_voices = get_harpsichord_voice_count(midi_note)  # =2

    # shorter overall decay than piano
    octave_diff = (60 - midi_note) / 12.0        # C4 reference
    tau_base = duration * 0.5 * (octave_decay_factor ** octave_diff)

    for k in range(1, num_partials + 1):
        # stretched-string inharmonicity (tiny for harpsichord)
        fk = k * base_freq * np.sqrt(1 + inharmonicity * k * k)
        tau_k = tau_base / k

        # fast attack, single-slope decay
        env = np.minimum(t / attack_time, 1.0) * np.exp(
            -np.maximum(t - attack_time, 0.0) / tau_k
        )

        # bright spectrum, gentle HF taper
        amp0 = (1.0 / (k ** spectral_rolloff)) * np.exp(-k / partial_decay_constant)
        amp0 *= 1.0 / (k ** loudness_exponent)  # loudness compensation (usually 0)

        for i in range(unison_voices):          # 0 = 8′, 1 = 4′
            # 8-foot base, 4-foot octave-up
            octave_mul = 1.0 if i == 0 else 2.0
            freq = fk * octave_mul

            # no deliberate detune, just tiny randomness
            cents_jitter = np.random.uniform(-pitch_randomness_cents,
                                             pitch_randomness_cents)
            freq *= 2 ** (cents_jitter / 1200.0)

            voice_amp = amp0 * (0.5 if i == 1 else 1.0) / unison_voices
            signal += voice_amp * env * np.sin(2 * np.pi * freq * t)

    # normalise
    peak = np.max(np.abs(signal))
    if peak != 0:
        signal /= peak

    # linear fade-out
    fade_samples = int(sample_rate * (fade_time_ms / 1000.0))
    if 0 < fade_samples < N:
        signal[-fade_samples:] *= np.linspace(1.0, 0.0, fade_samples, dtype=np.float32)

    # optional: 2 ms plectrum click (-20 dB)
    click_len = int(sample_rate * 0.002)
    click = 0.1 * np.random.randn(click_len).astype(np.float32)
    click *= np.linspace(1.0, 0.0, click_len, dtype=np.float32)
    signal[:click_len] += click

    # re-normalise (click may add headroom)
    peak = np.max(np.abs(signal))
    if peak > 1e-6:
        signal /= peak

    return signal


# ---------------------------------------------------------------------------
# I/O helpers
# ---------------------------------------------------------------------------
def save_waveform(waveform, sample_rate, filename):
    os.makedirs(os.path.dirname(filename), exist_ok=True)
    sf.write(filename, waveform.astype(np.float32), sample_rate,
             subtype="PCM_U8")
    print("Saved", filename)


def numpy_to_audio_segment(waveform, sample_rate):
    return AudioSegment(
        np.int16(waveform * 32767).tobytes(),
        frame_rate=sample_rate,
        sample_width=2,
        channels=1,
    )


# ---------------------------------------------------------------------------
# Batch generation
# ---------------------------------------------------------------------------
def generate_all_notes(
    midi_start: int,
    midi_end: int,
    sample_rate: int,
    duration: float,
    num_partials: int,
    inharmonicity: float,
    detune_cents: float,
    attack_time: float,
    octave_decay_factor: float,
    spectral_rolloff: float,
    partial_decay_constant: float,
    loudness_exponent: float,
    pitch_randomness_cents: float,
    output_dir: str,
    fade_time_ms: float,
):
    # clear directory
    if os.path.isdir(output_dir):
        for fname in os.listdir(output_dir):
            fp = os.path.join(output_dir, fname)
            if os.path.isfile(fp):
                os.remove(fp)

    for midi_note in range(midi_start, midi_end + 1):
        base_freq = 440.0 * 2 ** ((midi_note - 69) / 12.0)
        note = generate_harpsichord_note(
            base_freq,
            midi_note,
            sample_rate,
            duration,
            num_partials,
            inharmonicity,
            detune_cents,
            attack_time,
            octave_decay_factor,
            spectral_rolloff,
            partial_decay_constant,
            loudness_exponent,
            pitch_randomness_cents,
            fade_time_ms,
        )
        out_name = os.path.join(output_dir, f"{midi_note:03d}.wav")
        save_waveform(note, sample_rate, out_name)


# ---------------------------------------------------------------------------
# Main / parameter block
# ---------------------------------------------------------------------------
if __name__ == "__main__":
    output_dir                = "midi/tgt/harpsichord"
    midi_start                = 24          # C1
    midi_end                  = 72          # C5

    # synthesis parameters tweaked for harpsichord
    sample_rate               = 16384
    duration                  = 3.0         # shorter note
    num_partials              = 36
    inharmonicity             = 5e-5
    detune_cents              = 0.0
    pitch_randomness_cents    = 0.2
    attack_time               = 0.001       # 1 ms snap
    octave_decay_factor       = 1.2
    spectral_rolloff          = 1.0
    partial_decay_constant    = 4.0
    loudness_exponent         = 0.0
    fade_time_ms              = 200.0       # safety tail-off

    generate_all_notes(
        midi_start,
        midi_end,
        sample_rate,
        duration,
        num_partials,
        inharmonicity,
        detune_cents,
        attack_time,
        octave_decay_factor,
        spectral_rolloff,
        partial_decay_constant,
        loudness_exponent,
        pitch_randomness_cents,
        output_dir,
        fade_time_ms,
    )

    print("Done generating harpsichord range.")


    # # Single test note
    # test_midi_note            = 48 
    # base_freq = 440.0 * 2 ** ((test_midi_note - 69) / 12.0)
    # note = generate_piano_note(base_freq,test_midi_note,sample_rate,duration,partials,inharmonicity,detune,attack,decay_factor,spectral_rolloff,partial_decay_constant,loudness_exponent,pitch_randomness_cents,fade_time)
    # filename = os.path.join(output_dir,f"piano_{test_midi_note:03d}.wav")
    # save_waveform(note, sample_rate, filename)
    # play(numpy_to_audio_segment(note, sample_rate))

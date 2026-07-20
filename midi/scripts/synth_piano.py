import os
import numpy as np
import soundfile as sf
from pydub import AudioSegment

"""ChatGPT substantially generated the code below using its Deep Research functionality. A copy of its report can be found at https://chatgpt.com/s/dr_6820d8410f50819192892182d6fc7fbb or a .pdf of the report is in this directory as well, but the maths formatting did not come thorough correctly.
"""

def get_realistic_voice_count(midi_note):
    if midi_note <= 27 or midi_note >= 100:
        return 1
    elif 89 <= midi_note < 100:
        return 2
    elif 40 <= midi_note < 89:
        return 3
    else:
        return 2

def generate_piano_note(base_freq, midi_note, sample_rate, duration, num_partials, inharmonicity, detune_cents, attack_time, octave_decay_factor, spectral_rolloff, partial_decay_constant, loudness_exponent, fade_time):
    N = int(sample_rate * duration)
    t = np.linspace(0, duration, N, endpoint=False)
    signal = np.zeros(N, dtype=np.float32)

    unison_voices = get_realistic_voice_count(midi_note)
    octave_diff = (60 - midi_note) / 12.0
    tau_base = duration * (octave_decay_factor ** octave_diff)

    for k in range(1, num_partials + 1):
        fk = k * base_freq * np.sqrt(1 + inharmonicity * (k**2))
        tau_k = tau_base / k

        env = np.minimum(t / attack_time, 1.0)
        env *= np.exp(-np.maximum(t - attack_time, 0.0) / tau_k)

        amp0 = (1.0 / (k ** spectral_rolloff)) * np.exp(-k / partial_decay_constant)
        amp0 *= (1.0 / (k ** loudness_exponent))

        for i in range(unison_voices):
            if unison_voices > 1:
                base_off = ((i - (unison_voices - 1)/2) * (2 * detune_cents / (unison_voices - 1)))
            else:
                base_off = 0.0

            cents = base_off
            freq = fk * (2 ** (cents / 1200.0))
            signal += (amp0 / unison_voices) * env * np.sin(2*np.pi*freq*t)

    signal /= np.max(np.abs(signal))

    fade_samples = int(sample_rate * fade_time / 1000.0)
    if 0 < fade_samples < N:
        fade_curve = np.linspace(1.0, 0.0, fade_samples)
        signal[-fade_samples:] *= fade_curve

    return signal

def save_waveform(waveform, sample_rate, filename):
    os.makedirs(os.path.dirname(filename), exist_ok=True)
    sf.write(filename, waveform.astype(np.float32), sample_rate, subtype='PCM_U8')
    print(f"Saved: {filename}")

def numpy_to_audio_segment(waveform, sample_rate):
    pcm16 = np.int16(waveform * 32767)
    return AudioSegment(
        pcm16.tobytes(),
        frame_rate=sample_rate,
        sample_width=pcm16.dtype.itemsize,
        channels=1
    )

def generate_all_notes(midi_start, midi_end, sample_rate, duration, num_partials, inharmonicity, detune_cents, attack_time, octave_decay_factor, spectral_rolloff, partial_decay_constant, loudness_exponent, output_dir, fade_time):
    for filename in os.listdir(output_dir):
        file_path = os.path.join(output_dir, filename)
        try:
            if os.path.isfile(file_path):
                os.remove(file_path)
        except Exception as e:
            print(f"Error deleting file {file_path}: {e}")

    for midi_note in range(midi_start, midi_end + 1):
        base_freq = 440.0 * 2 ** ((midi_note - 69) / 12.0)
        note = generate_piano_note(
            base_freq, midi_note, sample_rate, duration, num_partials,
            inharmonicity, detune_cents, attack_time, octave_decay_factor,
            spectral_rolloff, partial_decay_constant, loudness_exponent,
            fade_time
        )
        filename = os.path.join(output_dir, f"{midi_note:03d}.wav")
        save_waveform(note, sample_rate, filename)

if __name__ == "__main__":
    output_dir                = "midi/tgt/piano"
    midi_start                = 25
    midi_end                  = 102

    sample_rate               = 13684  # Hz
    duration                  = 3.0    # seconds
    partials                  = 20
    inharmonicity             = 1e-4
    detune                    = 2.0
    attack                    = 0.01   # seconds
    decay_factor              = 2.0
    spectral_rolloff          = 1.5
    partial_decay_constant    = 10.0
    loudness_exponent         = 0.001
    fade_time                 = 500.0  # ms

    generate_all_notes(midi_start, midi_end, sample_rate, duration, partials, inharmonicity, detune, attack, decay_factor,spectral_rolloff, partial_decay_constant,loudness_exponent, output_dir, fade_time)
    print("Done generating range.")

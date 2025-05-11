import os
import numpy as np
import soundfile as sf
from pydub import AudioSegment
from pydub.playback import play


def get_realistic_voice_count(midi_note):
    """
    Return realistic number of unison strings (voices) for a given MIDI note.
    """
    if midi_note <= 27 or midi_note >= 100:
        return 1
    elif 89 <= midi_note < 100:
        return 2
    elif 40 <= midi_note < 89:
        return 3
    else:
        return 2


def generate_piano_note(base_freq, midi_note, sample_rate, duration, num_partials, inharmonicity, detune_cents, attack_time, octave_decay_factor, spectral_rolloff, partial_decay_constant, loudness_exponent, pitch_randomness_cents):
    """
    Synthesize one piano-like note by summing inharmonic partials
    with individual attack/decay envelopes, realistic unison voices,
    high-frequency tapering, perceptual loudness compensation,
    and small random pitch variations for humanization.

    pitch_randomness_cents: max random detune per voice in cents
    """
    N = int(sample_rate * duration)
    t = np.linspace(0, duration, N, endpoint=False)
    signal = np.zeros(N, dtype=np.float32)

    # Determine number of unison voices based on MIDI note
    unison_voices = get_realistic_voice_count(midi_note)

    # Compute pitch-dependent base decay time: C4=MIDI60 reference
    octave_diff = (60 - midi_note) / 12.0
    tau_base = duration * (octave_decay_factor ** octave_diff)

    for k in range(1, num_partials + 1):
        # inharmonic partial frequency
        fk = k * base_freq * np.sqrt(1 + inharmonicity * (k**2))
        # per-partial decay time constant
        tau_k = tau_base / k

        # envelope: attack then exponential decay
        env = np.minimum(t / attack_time, 1.0)
        env *= np.exp(-np.maximum(t - attack_time, 0.0) / tau_k)

        # amplitude roll-off + extra HF tapering
        amp0 = (1.0 / (k ** spectral_rolloff)) * np.exp(-k / partial_decay_constant)

        # perceptual loudness: boost lower partials via power law
        amp0 *= (1.0 / (k ** loudness_exponent))

        # generate unison voices with slight detuning and randomness
        for i in range(unison_voices):
            if unison_voices > 1:
                base_offset = (
                    (i - (unison_voices - 1) / 2)
                    * (2 * detune_cents / max(unison_voices - 1, 1))
                )
            else:
                base_offset = 0.0
            rand_offset = np.random.uniform(-pitch_randomness_cents, pitch_randomness_cents)
            total_cents = base_offset + rand_offset
            freq = fk * (2 ** (total_cents / 1200.0))
            voice_amp = amp0 / unison_voices
            signal += voice_amp * env * np.sin(2 * np.pi * freq * t)

    # normalize to -1…+1
    signal /= np.max(np.abs(signal))
    return signal


def save_waveform(waveform, sample_rate, filename):
    """Write a float32 waveform (-1…+1) as 8-bit PCM WAV via soundfile."""
    os.makedirs(os.path.dirname(filename), exist_ok=True)
    sf.write(filename, waveform.astype(np.float32), sample_rate, subtype='PCM_U8')
    print(f"Saved: {filename}")


def numpy_to_audio_segment(waveform, sample_rate):
    """Convert float32 waveform (-1…+1) to a playable AudioSegment."""
    pcm16 = np.int16(waveform * 32767)
    return AudioSegment(
        pcm16.tobytes(),
        frame_rate=sample_rate,
        sample_width=pcm16.dtype.itemsize,
        channels=1
    )


def generate_all_notes(midi_start,midi_end,sample_rate,duration,num_partials,inharmonicity,detune_cents,attack_time,octave_decay_factor,spectral_rolloff,partial_decay_constant,loudness_exponent,pitch_randomness_cents,output_dir):
    # delete all files in output_dir
    for filename in os.listdir(output_dir):
        file_path = os.path.join(output_dir, filename)
        try:
            if os.path.isfile(file_path):
                os.remove(file_path)
        except Exception as e:
            print(f"Error deleting file {file_path}: {e}")
    """
    Batch-generate piano samples for all MIDI notes in [midi_start, midi_end].
    """
    for midi_note in range(midi_start, midi_end + 1):
        base_freq = 440.0 * 2 ** ((midi_note - 69) / 12.0)
        note = generate_piano_note(base_freq,midi_note,sample_rate,duration,num_partials,inharmonicity,detune_cents,attack_time,octave_decay_factor,spectral_rolloff,partial_decay_constant,loudness_exponent,pitch_randomness_cents)
        filename = os.path.join(output_dir,f"piano_{midi_note:03d}.wav")
        save_waveform(note, sample_rate, filename)


if __name__ == "__main__":
    output_dir                = "midi/tgt/samples"

    # Synthesis parameters
    sample_rate               = 16384
    duration                  = 5.0    # seconds
    test_midi_note            = 60     # Middle C
    partials                  = 20
    inharmonicity             = 1e-4   # inharmonicity factor
    detune                    = 2.0    # cents between unison voices
    pitch_randomness_cents    = 0.5    # cents random detune per voice
    attack                    = 0.01   # seconds
    decay_factor              = 2.0    # octave decay scaling
    spectral_rolloff          = 1.5    # exponent for 1/k^rolloff
    partial_decay_constant    = 10.0   # controls extra HF tapering
    loudness_exponent         = 0.001  # boosts low partials (power law)
    midi_start                = 24
    midi_end                  = 72

    generate_all_notes(midi_start,midi_end,sample_rate,duration,partials,inharmonicity,detune,attack,decay_factor,spectral_rolloff,partial_decay_constant,loudness_exponent,pitch_randomness_cents,output_dir)
    print("Done generating range.")

    # # Single test note
    # base_freq = 440.0 * 2 ** ((test_midi_note - 69) / 12.0)
    # note = generate_piano_note(base_freq,test_midi_note,sample_rate,duration,partials,inharmonicity,detune,attack,decay_factor,spectral_rolloff,partial_decay_constant,loudness_exponent,pitch_randomness_cents)
    # filename = os.path.join(output_dir,f"piano_{test_midi_note:03d}.wav")
    # save_waveform(note, sample_rate, filename)
    # play(numpy_to_audio_segment(note, sample_rate))

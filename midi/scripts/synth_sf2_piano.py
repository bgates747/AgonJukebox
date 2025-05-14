#!/usr/bin/env python3
import os
import numpy as np
import soundfile as sf
import fluidsynth

# ── Helper ─────────────────────────────────────────────────────────────────────

def render_note_to_wav(fs, midi_note, filename):
    num_samples = int(SAMPLE_RATE * DURATION)

    # Trigger note-on
    fs.noteon(0, midi_note, 127)

    # Pull raw samples (float32 in [-1..1]); may be stereo interleaved
    raw = fs.get_samples(num_samples)

    # Note-off (won't affect the grabbed buffer)
    fs.noteoff(0, midi_note)

    # Convert to numpy array
    arr = np.array(raw, dtype=np.float32)

    # If stereo (length == num_samples*2), reshape & mix
    if arr.size == num_samples * 2:
        arr = arr.reshape(-1, 2)
        mono = arr.mean(axis=1)
    else:
        mono = arr

    # Normalize
    peak = np.max(np.abs(mono))
    if peak > 0:
        mono /= peak

    # Ensure directory exists
    os.makedirs(os.path.dirname(filename), exist_ok=True)

    # Write 8-bit PCM (unsigned) mono WAV
    sf.write(filename, mono, SAMPLE_RATE, subtype="PCM_U8")
    print(f"  → {filename}")

# ── Configuration ───────────────────────────────────────────────────────────────

SF2_PATH = (
    "/home/smith/Agon/mystuff/assets/sound/sf2/"
    "Top 18 Free Piano Soundfonts/Full Grand.sf2"
)

# SF2_PATH = "/home/smith/Agon/mystuff/assets/sound/sf2/Top 23 Free Strings Soundfonts/RolandMarcatoStrings.sf2"

OUTPUT_DIR = "midi/tgt/piano_sf2"

MIDI_START  = 25
MIDI_END    = 105

SAMPLE_RATE = 16384    # Hz
DURATION    = 3.0      # seconds

# ── Main ────────────────────────────────────────────────────────────────────────

if __name__ == "__main__":
    # Clean out any old files
    if os.path.isdir(OUTPUT_DIR):
        for fn in os.listdir(OUTPUT_DIR):
            path = os.path.join(OUTPUT_DIR, fn)
            if os.path.isfile(path):
                os.remove(path)
    else:
        os.makedirs(OUTPUT_DIR)

    # Initialize FluidSynth
    fs = fluidsynth.Synth(samplerate=SAMPLE_RATE)
    sfid = fs.sfload(SF2_PATH)
    fs.program_select(0, sfid, bank=0, preset=0)

    print(f"Rendering MIDI notes {MIDI_START}–{MIDI_END} at {SAMPLE_RATE} Hz...")
    for note in range(MIDI_START, MIDI_END + 1):
        out_path = os.path.join(OUTPUT_DIR, f"{note:03d}.wav")
        render_note_to_wav(fs, note, out_path)

    # Tear down
    fs.delete()
    print("Done.")
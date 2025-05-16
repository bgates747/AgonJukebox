#!/usr/bin/env python3
import os
import tempfile
import subprocess
import re

import pretty_midi
import soundfile as sf
import numpy as np
import shutil

def midi_note_number(note_name, octave):
    """Return MIDI note number for note name and octave (e.g., 'A', 2)."""
    note_base = dict(C=0, Cs=1, D=2, Ds=3, E=4, F=5, Fs=6, G=7, Gs=8, A=9, As=10, B=11)
    # Allow both 'A#' or 'As' for A sharp
    if len(note_name) > 1 and note_name[1] in ['#', 's']:
        key = note_name[0] + 's'
    else:
        key = note_name[0]
    return 12 * (octave + 1) + note_base[key]

def build_single_note_midi(midi_pitch, duration, velocity, program, bank=0, is_drum=False):
    """Create a PrettyMIDI object with a single note."""
    pm = pretty_midi.PrettyMIDI()
    instrument = pretty_midi.Instrument(program=program, is_drum=is_drum)
    instrument.bank = bank
    note = pretty_midi.Note(velocity=velocity, pitch=midi_pitch, start=0, end=duration)
    instrument.notes.append(note)
    pm.instruments.append(instrument)
    return pm

def render_with_fluidsynth(sf2_path, midi_path, wav_path, sample_rate, output_gain, duration_s):
    """
    Render MIDI to WAV via FluidSynth (mono, 8-bit unsigned PCM), 
    forcibly truncating to the specified duration (in seconds).
    """
    # 1. Render stereo (default fluidsynth output)
    cmd = [
        "fluidsynth", "-ni",
        sf2_path, midi_path,
        "-F", wav_path,
        "-r", str(sample_rate),
        "-g", str(output_gain),
    ]
    subprocess.run(cmd, check=True)

    # 2. Load, downmix to mono if needed
    data, sr = sf.read(wav_path)
    if data.ndim > 1:
        data = data.mean(axis=1)
    # 3. Truncate to the desired number of samples
    nsamp = int(round(duration_s * sr))
    data = data[:nsamp]

    # 4. Write to temp file as 8-bit unsigned PCM
    with tempfile.NamedTemporaryFile(suffix=".wav", delete=False) as tmp:
        temp_wav = tmp.name
    sf.write(temp_wav, data, sr, subtype='PCM_U8')
    shutil.move(temp_wav, wav_path)


def sanitize_folder_name(name):
    return re.sub(r'[^A-Za-z0-9_\-]', '_', name)

def main():
    sf2_path = "/home/smith/Agon/mystuff/assets/sound/sf2/FluidR3_GM/FluidR3_GM.sf2"
    sample_rate = 32000
    wav_folder = "midi/tgt"
    duration = 4.0
    velocity = 127
    output_gain = 4.0

    instrument_defs = [
        (0, 1, "Yamaha"),
        (0, 70, "Bassoon"),
        (0, 73, "Flute"),
        (0, 56, "Trumpet"),
        (0, 57, "Trombone"),
        (0, 6,  "Harpsichord"),
        (0, 48, "Strings"),
    ]

    note_names = ["A"]
    octaves = range(0, 8) 

    # Build list of all MIDI numbers for all note names/octaves
    midi_numbers = []
    for note in note_names:
        for octv in octaves:
            midi_numbers.append(midi_note_number(note, octv))
    print("Rendering MIDI notes:", midi_numbers)

    for bank, preset, name in instrument_defs:
        folder = os.path.join(wav_folder, sanitize_folder_name(name))
        os.makedirs(folder, exist_ok=True)
        # Remove any existing files in the folder
        for f in os.listdir(folder):
            f_path = os.path.join(folder, f)
            if os.path.isfile(f_path):
                os.remove(f_path)
        print(f"Rendering samples for {name} (bank {bank}, preset {preset}) → {folder}")
        for midi_pitch in midi_numbers:
            pm = build_single_note_midi(
                midi_pitch, duration, velocity, program=preset, bank=bank, is_drum=False
            )
            with tempfile.NamedTemporaryFile(suffix=".mid", delete=False) as tmp:
                midi_path = tmp.name
            pm.write(midi_path)
            out_wav = os.path.join(folder, f"{midi_pitch:03d}.wav")
            render_with_fluidsynth(sf2_path, midi_path, out_wav, sample_rate, output_gain, duration)
            os.remove(midi_path)
            print(f"  {out_wav} written.")
    print("All samples rendered.")

if __name__ == "__main__":
    main()

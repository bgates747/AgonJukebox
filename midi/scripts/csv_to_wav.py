#!/usr/bin/env python3
import os
import tempfile
import subprocess
import pretty_midi
import soundfile as sf
import numpy as np
import shutil
import re
import csv
from io import StringIO

# ── Helpers ─────────────────────────────────────────────────────────────────────

def extract_instrument_notes(csv_path, inst_idx):
    """
    Read the CSV and return a list of (start, end, pitch, velocity) tuples
    for the given instrument index.
    """
    notes = []
    with open(csv_path, 'r') as f:
        lines = f.readlines()

    in_section = False
    for raw in lines:
        line = raw.strip()
        if not line:
            continue

        # start of the desired instrument section
        if line.startswith(f"# Instrument {inst_idx}:"):
            in_section = True
            continue

        # once we hit the next instrument header, we're done
        if in_section and line.startswith("# Instrument"):
            break

        if in_section:
            # skip the CSV column header
            if line.startswith("Note #"):
                continue
            # skip any other comment
            if line.startswith("#"):
                continue

            parts = [p.strip() for p in line.split(",")]
            if len(parts) < 8:
                continue

            # index mapping:
            # parts[1] = Start (s)
            # parts[2] = End (s)
            # parts[4] = Pitch
            # parts[6] = Note-on Velocity
            start = float(parts[1])
            end   = float(parts[2])
            pitch = int(parts[4])
            vel   = int(parts[6])

            notes.append((start, end, pitch, vel))

    return notes

def build_midi(notes, program, is_drum=False, velocity_override=None, tempo=120.0):
    """
    Create a PrettyMIDI object containing a single instrument track.
    Optionally overrides note velocity.
    """
    pm = pretty_midi.PrettyMIDI(initial_tempo=tempo)
    inst = pretty_midi.Instrument(program=program, is_drum=is_drum)
    for start, end, pitch, vel in notes:
        v = velocity_override if velocity_override is not None else vel
        inst.notes.append(pretty_midi.Note(
            velocity=v, pitch=pitch, start=start, end=end
        ))
    pm.instruments.append(inst)
    return pm

def render_with_fluidsynth(sf2_path, midi_path, wav_path, sample_rate, to_pcm_u8=True):
    """
    Render MIDI to WAV via FluidSynth.
    Ensures output is mono. Optionally converts to 8-bit unsigned PCM (PCM_16).
    Overwrites wav_path in place.
    """
    cmd = [
        "fluidsynth", "-ni",
        sf2_path, midi_path,
        "-F", wav_path,
        "-r", str(sample_rate)
    ]
    subprocess.run(cmd, check=True)

    data, sr = sf.read(wav_path)
    if data.ndim > 1:
        data = data.mean(axis=1)
    with tempfile.NamedTemporaryFile(suffix=".wav", delete=False) as tmp:
        temp_wav = tmp.name
    if to_pcm_u8:
        sf.write(temp_wav, data, sr, subtype='PCM_16')
    else:
        sf.write(temp_wav, data, sr)
    shutil.move(temp_wav, wav_path)

def combine_instrument_wavs(wav_folder, instrument_rows, base_name, sample_rate):
    """
    Mix individual instrument WAVs into one mono 8-bit PCM WAV.
    - instrument_rows: list of Dicts from CSV.
    """
    tracks = []
    max_len = 0
    for row in instrument_rows:
        inst_idx = row["instrument_number"]
        path = os.path.join(wav_folder, f"{base_name}_{inst_idx}.wav")
        data, sr = sf.read(path)
        if sr != sample_rate:
            raise RuntimeError(f"Sample rate mismatch in {path}: {sr} != {sample_rate}")
        if data.ndim > 1:
            data = data.mean(axis=1)
        tracks.append(data)
        max_len = max(max_len, data.shape[0])

    # Mix (sum) with zero‐padding
    mix = np.zeros(max_len, dtype=np.float32)
    for track in tracks:
        mix[:track.shape[0]] += track

    peak = np.max(np.abs(mix))
    if peak > 0:
        mix /= peak

    out_path = os.path.join(wav_folder, f"{base_name}.wav")
    sf.write(out_path, mix, sample_rate, subtype='PCM_16')
    print(f"Wrote combined mix to {out_path}")

def parse_instrument_defs_csv(csv_string):
    """
    Parse the multiline CSV string, return a list of dicts (one per row).
    Skips lines beginning with # and empty lines.
    """
    lines = [
        l for l in csv_string.strip().splitlines()
        if l.strip() and not l.strip().startswith("#")
    ]
    # Use csv.DictReader on cleaned lines
    reader = csv.DictReader(lines)
    rows = []
    for row in reader:
        # Coerce fields
        row["instrument_number"] = row["instrument_number"].strip()
        row["bank"] = int(row["bank"])
        row["preset"] = int(row["preset"])
        row["is_drum"] = (row["is_drum"].strip().upper() == "TRUE")
        row["velocity"] = int(row["velocity"])
        row["sample_rate"] = int(row["sample_rate"])
        row["sf2_path"] = row["sf2_path"].strip()
        rows.append(row)
    return rows

def main(csv_path, inst_row, base_name, wav_folder):
    inst_idx    = inst_row["instrument_number"]
    bank        = inst_row["bank"]
    preset      = inst_row["preset"]
    is_drum     = inst_row["is_drum"]
    name        = inst_row["midi_instrument_name"]
    velocity    = inst_row["velocity"]
    sample_rate = inst_row["sample_rate"]
    sf2_path    = inst_row["sf2_path"]

    print(f"Instrument {inst_idx}: bank={bank}, preset={preset}, name='{name}', velocity={velocity}, is_drum={is_drum}")

    # Extract notes from the CSV
    notes = extract_instrument_notes(csv_path, inst_idx)
    if not notes:
        raise RuntimeError(f"No notes found for Instrument {inst_idx} in {csv_path}")

    # Build a temporary MIDI file
    pm = build_midi(notes, program=preset, is_drum=is_drum, velocity_override=velocity)
    with tempfile.NamedTemporaryFile(suffix=".mid", delete=False) as tmp:
        midi_path = tmp.name
    pm.write(midi_path)

    # Output path
    output_wav = os.path.join(wav_folder, f"{base_name}_{inst_idx}.wav")
    os.makedirs(os.path.dirname(output_wav), exist_ok=True)

    print(f"Rendering to {output_wav} at {sample_rate} Hz…")
    render_with_fluidsynth(sf2_path, midi_path, output_wav, sample_rate)

    os.remove(midi_path)
    print("Done.")

# ── Configuration & Invocation ─────────────────────────────────────────────────

if __name__ == "__main__":
    instrument_defs = """
instrument_number,midi_instrument_name,bank,preset,is_drum,sf_instrument_name,velocity,sample_rate,sf2_path
1,Piccolo,0,72,FALSE,Piccolo,127,32000,midi/sf2/FluidR3_GM/FluidR3_GM.sf2
2,Flute,0,73,FALSE,Flute,127,32000,midi/sf2/FluidR3_GM/FluidR3_GM.sf2
3,Oboe,0,68,FALSE,Oboe,127,32000,midi/sf2/FluidR3_GM/FluidR3_GM.sf2
4,Clarinet in A,0,71,FALSE,Clarinet,127,32000,midi/sf2/FluidR3_GM/FluidR3_GM.sf2
5,Bassoon I,0,70,FALSE,Bassoon,127,32000,midi/sf2/FluidR3_GM/FluidR3_GM.sf2
6,Bassoon II,0,70,FALSE,Bassoon,127,32000,midi/sf2/FluidR3_GM/FluidR3_GM.sf2
7,Horn in E I,0,60,FALSE,French Horns,127,32000,midi/sf2/FluidR3_GM/FluidR3_GM.sf2
8,Horn in E II,0,60,FALSE,French Horns,127,32000,midi/sf2/FluidR3_GM/FluidR3_GM.sf2
9,Trumpet in E,0,56,FALSE,Trumpet,127,32000,midi/sf2/FluidR3_GM/FluidR3_GM.sf2
10,Timpani,0,47,FALSE,Timpani,127,32000,midi/sf2/FluidR3_GM/FluidR3_GM.sf2
11,Trombone I,0,57,FALSE,Trombone,127,32000,midi/sf2/FluidR3_GM/FluidR3_GM.sf2
12,Trombone II,0,57,FALSE,Trombone,127,32000,midi/sf2/FluidR3_GM/FluidR3_GM.sf2
13,Tuba,0,58,FALSE,Tuba,127,32000,midi/sf2/FluidR3_GM/FluidR3_GM.sf2
# 14,Bass Drum,128,0,TRUE,Standard,127,32000,midi/sf2/FluidR3_GM/FluidR3_GM.sf2
# 15,Cymbal,128,0,TRUE,Standard,127,32000,midi/sf2/FluidR3_GM/FluidR3_GM.sf2
16,Violin I,0,40,FALSE,Violin,127,32000,midi/sf2/FluidR3_GM/FluidR3_GM.sf2
17,Violin II,0,40,FALSE,Violin,127,32000,midi/sf2/FluidR3_GM/FluidR3_GM.sf2
18,Viola,0,41,FALSE,Viola,127,32000,midi/sf2/FluidR3_GM/FluidR3_GM.sf2
19,Cello,0,42,FALSE,Cello,127,32000,midi/sf2/FluidR3_GM/FluidR3_GM.sf2
20,Contrabass,0,43,FALSE,Contrabass,127,32000,midi/sf2/FluidR3_GM/FluidR3_GM.sf2
"""

    csv_folder = "midi/out"
    wav_folder = "midi/wav"
    base_name = "Mountain_King"
    csv_path = os.path.join(csv_folder, f"{base_name}.csv")

    # Parse the instrument defs CSV
    instrument_rows = parse_instrument_defs_csv(instrument_defs)

    # Render each instrument
    for row in instrument_rows:
        main(csv_path, row, base_name, wav_folder)

    # Use sample rate of the first instrument (or override as needed)
    sample_rate = instrument_rows[0]["sample_rate"] if instrument_rows else 32000
    combine_instrument_wavs(wav_folder, instrument_rows, base_name, sample_rate)
    print("All instruments rendered and combined.")

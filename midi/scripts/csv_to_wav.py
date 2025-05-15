#!/usr/bin/env python3
import os
import tempfile
import subprocess

import pretty_midi
import soundfile as sf

# ── Helpers ─────────────────────────────────────────────────────────────────────

import re

def parse_instrument_line(line):
    """
    Parse a line like:
      "Instrument 7: Bank 0, Preset 1: Bright Yamaha Grand"
      or
      "Instrument 3: Preset 60: French Horns"
    Returns:
      inst_idx (int),
      bank (int, defaults to 0 if unspecified),
      preset (int),
      name (str)
    """
    # Regex with optional Bank group
    m = re.match(
        r"Instrument\s+(\d+)\s*:\s*(?:Bank\s*(\d+)\s*,\s*)?Preset\s*(\d+)\s*:\s*(.+)",
        line
    )
    if not m:
        raise ValueError(f"Cannot parse instrument line: {line!r}")
    inst_idx = int(m.group(1))
    bank     = int(m.group(2)) if m.group(2) is not None else 0
    preset   = int(m.group(3))
    name     = m.group(4).strip()
    return inst_idx, bank, preset, name



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
            # expect at least 8 fields: Note#, Start, End, Duration, Pitch, NoteName, Velocity, OnVel, OffVel
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


def build_midi(notes, program, is_drum=False, tempo=120.0):
    """
    Create a PrettyMIDI object containing a single instrument track.
    """
    pm = pretty_midi.PrettyMIDI(initial_tempo=tempo)
    inst = pretty_midi.Instrument(program=program, is_drum=is_drum)
    for start, end, pitch, vel in notes:
        inst.notes.append(pretty_midi.Note(
            velocity=vel, pitch=pitch, start=start, end=end
        ))
    pm.instruments.append(inst)
    return pm

def render_with_fluidsynth(sf2_path, midi_path, wav_path, sample_rate, to_pcm_u8=True):
    """
    Render MIDI to WAV via FluidSynth.
    Ensures output is mono. Optionally converts to 8-bit unsigned PCM (PCM_U8).
    Overwrites wav_path in place.
    """
    import soundfile as sf
    import numpy as np
    import tempfile
    import shutil

    # 1. Render stereo (default fluidsynth output)
    cmd = [
        "fluidsynth", "-ni",
        sf2_path, midi_path,
        "-F", wav_path,
        "-r", str(sample_rate)
    ]
    subprocess.run(cmd, check=True)

    # 2. Load, downmix to mono if needed
    data, sr = sf.read(wav_path)
    if data.ndim > 1:
        data = data.mean(axis=1)
    
    # 3. Write to temp file, converting to 8-bit unsigned PCM if requested
    with tempfile.NamedTemporaryFile(suffix=".wav", delete=False) as tmp:
        temp_wav = tmp.name
    if to_pcm_u8:
        sf.write(temp_wav, data, sr, subtype='PCM_U8')
    else:
        sf.write(temp_wav, data, sr)
    # 4. Overwrite original file with the converted version
    shutil.move(temp_wav, wav_path)

def combine_instrument_wavs(wav_folder, instrument_lines, base_name, sample_rate):
    """
    Mix individual instrument WAVs into one mono 8-bit PCM WAV.
    
    - wav_folder: directory containing per-instrument files named
      "{base_name}_{inst_idx}.wav"
    - instrument_lines: list of instrument header strings ("Instrument N: …")
    - base_name: common prefix for files
    - sample_rate: expected sample rate (Hz)
    """
    import os
    import numpy as np
    import soundfile as sf

    # Load each instrument's wav
    tracks = []
    max_len = 0
    for line in instrument_lines:
        inst_idx = line.split(':')[0].split()[1]
        path = os.path.join(wav_folder, f"{base_name}_{inst_idx}.wav")
        data, sr = sf.read(path)
        if sr != sample_rate:
            raise RuntimeError(f"Sample rate mismatch in {path}: {sr} != {sample_rate}")
        # ensure mono
        if data.ndim > 1:
            data = data.mean(axis=1)
        tracks.append(data)
        max_len = max(max_len, data.shape[0])

    # Mix (sum) with zero‐padding
    mix = np.zeros(max_len, dtype=np.float32)
    for track in tracks:
        mix[:track.shape[0]] += track

    # Normalize to [-1..1]
    peak = np.max(np.abs(mix))
    if peak > 0:
        mix /= peak

    # Write out as 8-bit unsigned PCM mono
    out_path = os.path.join(wav_folder, f"{base_name}.wav")
    sf.write(out_path, mix, sample_rate, subtype='PCM_U8')
    print(f"Wrote combined mix to {out_path}")


def main(csv_path, instrument_line, sf2_path, sample_rate, output_wav):
    # Parse the instrument header
    inst_idx, bank, preset, name = parse_instrument_line(instrument_line)
    print(f"Instrument {inst_idx}: bank={bank}, preset={preset}, name='{name}'")

    # Extract notes from the CSV
    notes = extract_instrument_notes(csv_path, inst_idx)
    if not notes:
        raise RuntimeError(f"No notes found for Instrument {inst_idx} in {csv_path}")

    # Build a temporary MIDI file
    pm = build_midi(notes, program=preset, is_drum=False)
    with tempfile.NamedTemporaryFile(suffix=".mid", delete=False) as tmp:
        midi_path = tmp.name
    pm.write(midi_path)

    # Ensure output directory exists
    os.makedirs(os.path.dirname(output_wav), exist_ok=True)

    # Render to WAV
    print(f"Rendering to {output_wav} at {sample_rate} Hz…")
    render_with_fluidsynth(sf2_path, midi_path, output_wav, sample_rate)

    # Clean up
    os.remove(midi_path)
    print("Done.")

# ── Configuration & Invocation ─────────────────────────────────────────────────

if __name__ == "__main__":
    sf2_path = "/home/smith/Agon/mystuff/assets/sound/sf2/FluidR3_GM/FluidR3_GM.sf2"
    sample_rate = 16384  # Hz
    csv_folder = "midi/out"
    wav_folder = "midi/wav"
    base_name = "Williams__Star_Wars_Theme"
    csv_path = os.path.join(csv_folder, f"{base_name}.csv")

    instrument_lines = [
        "Instrument 1: Bank 0, Preset 70: Bassoon",
        "Instrument 2: Bank 0, Preset 73: Flute",
        "Instrument 3: Preset 60: French Horns",
        "Instrument 4: Bank 0, Preset 56: Trumpet",
        "Instrument 5: Bank 0, Preset 57: Trombone",
        "Instrument 6: Bank 0, Preset 6: Harpsichord",
        "Instrument 7: Bank 0, Preset 1: Bright Yamaha Grand",
        "Instrument 8: Bank 0, Preset 48: Strings",
        "Instrument 9: Bank 0, Preset 48: Strings",
        "Instrument 10: Bank 0, Preset 48: Strings",
        "Instrument 11: Bank 0, Preset 47: Timpani",
        "Instrument 12: Bank 8, Preset 116: Concert Bass Drum",
    ]

    for instrument_line in instrument_lines:
        output_wav = os.path.join(wav_folder, f"{base_name}_{instrument_line.split(':')[0].split()[1]}.wav")
        main(csv_path, instrument_line, sf2_path, sample_rate, output_wav)

    # Combine all instrument WAVs into one
    combine_instrument_wavs(wav_folder, instrument_lines, base_name, sample_rate)
    print("All instruments rendered and combined.")

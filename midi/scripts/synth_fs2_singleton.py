#!/usr/bin/env python3
import os
import tempfile
import subprocess
import re
import pretty_midi
import soundfile as sf
import numpy as np
import shutil

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

def build_single_note_midi(pitch, velocity, duration_ms, program, is_drum=False, tempo=120.0):
    """
    Create a PrettyMIDI object containing a single note.
    
    Args:
        pitch: MIDI note number (0-127)
        velocity: Note velocity (0-127)
        duration_ms: Note duration in milliseconds
        program: MIDI program number
        is_drum: Whether this is a drum track
        tempo: Tempo in BPM
        
    Returns:
        A PrettyMIDI object
    """
    # Convert milliseconds to seconds for pretty_midi
    duration_sec = duration_ms / 1000.0
    
    pm = pretty_midi.PrettyMIDI(initial_tempo=tempo)
    inst = pretty_midi.Instrument(program=program, is_drum=is_drum)
    
    # Create a single note starting at time 0
    note = pretty_midi.Note(
        velocity=velocity,
        pitch=pitch,
        start=0,
        end=duration_sec
    )
    
    inst.notes.append(note)
    pm.instruments.append(inst)
    return pm

def render_with_fluidsynth(sf2_path, midi_path, wav_path, sample_rate, duration_ms):
    """
    Render MIDI to WAV via FluidSynth.
    Ensures output is mono and normalized, saved as 32-bit float.
    Truncates the output to the exact specified duration.
    
    Args:
        sf2_path: Path to the soundfont file
        midi_path: Path to the MIDI file
        wav_path: Path to write the WAV file
        sample_rate: Sample rate in Hz
        duration_ms: Duration in milliseconds to truncate the output
    """
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
    
    # 3. Calculate exact number of samples for the specified duration
    samples_needed = int((duration_ms / 1000.0) * sample_rate)
    
    # 4. Truncate data to exactly the specified duration
    if len(data) > samples_needed:
        data = data[:samples_needed]
    elif len(data) < samples_needed:
        # If the rendered audio is shorter than requested, pad with zeros
        data = np.pad(data, (0, samples_needed - len(data)), 'constant')
    
    # 5. Normalize the audio
    peak = np.max(np.abs(data))
    if peak > 0:
        data = data / peak
    
    # 6. Write to temp file as 32-bit float
    with tempfile.NamedTemporaryFile(suffix=".wav", delete=False) as tmp:
        temp_wav = tmp.name
    sf.write(temp_wav, data, sr, subtype='FLOAT')
    
    # 7. Overwrite original file with the normalized version
    shutil.move(temp_wav, wav_path)

def generate_single_note(pitch, velocity, duration_ms, instrument_line, sf2_path, sample_rate, output_folder):
    """
    Generate a single note WAV file for the specified instrument.
    
    Args:
        pitch: MIDI note number (0-127)
        velocity: Note velocity (0-127)
        duration_ms: Note duration in milliseconds
        instrument_line: Instrument specification string
        sf2_path: Path to the soundfont file
        sample_rate: Sample rate in Hz
        output_folder: Folder to save the WAV file
    """
    # Parse the instrument header
    inst_idx, bank, preset, name = parse_instrument_line(instrument_line)
    
    # Sanitize instrument name for filename
    sanitized_name = re.sub(r'[^\w\-]', '_', name)
    
    # Create output filename
    output_filename = f"{pitch}_{velocity}_{bank}_{preset}_{sanitized_name}.wav"
    output_path = os.path.join(output_folder, output_filename)
    
    print(f"Generating {output_path}...")
    
    # Build a temporary MIDI file with a single note
    pm = build_single_note_midi(pitch, velocity, duration_ms, program=preset, is_drum=(bank==128))
    with tempfile.NamedTemporaryFile(suffix=".mid", delete=False) as tmp:
        midi_path = tmp.name
    pm.write(midi_path)

    # Ensure output directory exists
    os.makedirs(output_folder, exist_ok=True)

    # Render to WAV
    render_with_fluidsynth(sf2_path, midi_path, output_path, sample_rate, duration_ms)

    # Clean up
    os.remove(midi_path)
    
    return output_path

def analyze_wav_amplitude(wav_path, bucket_interval_ms):
    """
    Analyze a WAV file and output a CSV file with amplitude data in time buckets.
    Uses logarithmic scaling for perceptually accurate velocities.
    
    Args:
        wav_path: Path to the WAV file
        bucket_interval_ms: Size of each bucket in milliseconds
        
    Returns:
        Path to the generated CSV file
    """
    # Create output CSV path with same name as WAV but .csv extension
    csv_path = os.path.splitext(wav_path)[0] + '.csv'
    
    # Load the audio file
    data, sample_rate = sf.read(wav_path)
    
    # Ensure data is mono
    if data.ndim > 1:
        data = data.mean(axis=1)
    
    # Calculate bucket size in samples
    samples_per_bucket = int((bucket_interval_ms / 1000.0) * sample_rate)
    
    # Number of complete buckets
    num_buckets = len(data) // samples_per_bucket
    
    # Initialize results
    bucket_rms_values = []
    time_points = []
    
    # First pass: Calculate RMS for each bucket
    for i in range(num_buckets):
        start_sample = i * samples_per_bucket
        end_sample = start_sample + samples_per_bucket
        bucket_data = data[start_sample:end_sample]
        
        # Calculate time in ms for this bucket
        time_ms = (i * samples_per_bucket * 1000.0) / sample_rate
        time_points.append(time_ms)
        
        # Calculate RMS amplitude
        rms = np.sqrt(np.mean(np.square(bucket_data)))
        bucket_rms_values.append(rms)
    
    # Convert to logarithmic scale (decibels)
    # First filter out zeros to avoid log(0)
    db_values = []
    for rms in bucket_rms_values:
        if rms > 0:
            # Convert to decibels (standard formula: 20 * log10(amplitude))
            db = 20 * np.log10(rms)
            db_values.append(db)
        else:
            db_values.append(-100)  # Very low dB for zero amplitude
    
    # Find the maximum dB value
    max_db = max(db_values) if db_values else -100
    
    # Choose a noise floor (-60dB is typical for 16-bit audio, adjust as needed)
    noise_floor_db = -60
    
    # Normalize and scale to MIDI velocity range
    results = []
    for i in range(len(db_values)):
        db = db_values[i]
        rms = bucket_rms_values[i]
        time_ms = time_points[i]
        
        # Clamp to noise floor
        db = max(db, noise_floor_db)
        
        # Map decibel range to MIDI velocity (0-127)
        # Typically -60dB to 0dB would map to 0-127
        db_range = max_db - noise_floor_db
        if db_range > 0:
            velocity = int(min(127, max(0, 127 * (db - noise_floor_db) / db_range)))
        else:
            velocity = 0 if db <= noise_floor_db else 127
        
        results.append((time_ms, rms, velocity))
    
    # Write results to CSV
    with open(csv_path, 'w') as f:
        f.write("time_ms,amplitude,velocity\n")
        for time_ms, rms, velocity in results:
            f.write(f"{time_ms:.2f},{rms:.6f},{velocity}\n")
    
    print(f"Wrote amplitude analysis to {csv_path} (using logarithmic scaling)")
    return csv_path

def analyze_all_instrument_wavs(instrument_lines, pitch, velocity, output_folder, bucket_interval_ms):
    """
    Analyze all WAV files generated for the specified instruments.
    
    Args:
        instrument_lines: List of instrument specification strings
        pitch: MIDI note number used when generating the WAVs
        velocity: MIDI velocity used when generating the WAVs
        output_folder: Folder containing the WAV files
        bucket_interval_ms: Size of each bucket in milliseconds
    """
    csv_files = []
    
    for line in instrument_lines:
        # Parse the instrument info
        inst_idx, bank, preset, name = parse_instrument_line(line)
        
        # Sanitize instrument name for filename
        sanitized_name = re.sub(r'[^\w\-]', '_', name)
        
        # Recreate the filename format used for the WAV
        filename = f"{pitch}_{velocity}_{bank}_{preset}_{sanitized_name}.wav"
        wav_path = os.path.join(output_folder, filename)
        
        if os.path.exists(wav_path):
            csv_path = analyze_wav_amplitude(wav_path, bucket_interval_ms)
            csv_files.append(csv_path)
        else:
            print(f"Warning: WAV file not found: {wav_path}")
    
    print(f"Generated {len(csv_files)} CSV files with amplitude analysis")
    return csv_files
    

def main(instrument_lines, pitch, velocity, duration_ms, sf2_path, sample_rate, output_folder):
    """
    Generate single-note WAV files for all instruments.
    
    Args:
        pitch: MIDI note number (0-127)
        velocity: Note velocity (0-127)
        duration_ms: Note duration in milliseconds
        sf2_path: Path to the soundfont file
        sample_rate: Sample rate in Hz
        output_folder: Folder to save the WAV files
    """
    
    output_files = []
    
    for instrument_line in instrument_lines:
        output_file = generate_single_note(
            pitch, velocity, duration_ms, 
            instrument_line, sf2_path, sample_rate, output_folder
        )
        output_files.append(output_file)
    
    print(f"Generated {len(output_files)} singleton note files in {output_folder}")

if __name__ == "__main__":
    # Configuration
    sf2_path = "midi/sf2/FluidR3_GM/FluidR3_GM.sf2"
    sample_rate = 32000  # Hz
    output_folder = "midi/sf2/singletons"

    instrument_lines = [
        # "Instrument 1: Bank 0, Preset 70: Bassoon",
        # "Instrument 2: Bank 0, Preset 73: Flute",
        # "Instrument 3: Preset 60: French Horns",
        # "Instrument 4: Bank 0, Preset 56: Trumpet",
        # "Instrument 5: Bank 0, Preset 57: Trombone",
        # "Instrument 6: Bank 0, Preset 6: Harpsichord",
        "Instrument 7: Bank 0, Preset 1: Bright Yamaha Grand",
        # "Instrument 8: Bank 0, Preset 48: Strings",
        # "Instrument 9: Bank 0, Preset 48: Strings",
        # "Instrument 10: Bank 0, Preset 48: Strings",
        # "Instrument 11: Bank 0, Preset 47: Timpani",
        # "Instrument 12: Bank 8, Preset 116: Concert Bass Drum",
    ]
    
    # Note parameters
    pitch = 38
    velocity = 127
    duration_ms = 4000
    
    main(instrument_lines, pitch, velocity, duration_ms, sf2_path, sample_rate, output_folder)

# Analysis parameters
    bucket_interval_ms = 10  # 50 milliseconds per bucket
    
    # Analyze the generated WAV files
    analyze_all_instrument_wavs(instrument_lines, pitch, velocity, output_folder, bucket_interval_ms)
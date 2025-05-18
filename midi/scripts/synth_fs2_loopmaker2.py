#!/usr/bin/env python3
import os
import sys
import numpy as np
import json
import soundfile as sf
from sf2utils.sf2parse import Sf2File

def extract_mono_samples_and_loops(sf2_path, output_dir):
    """
    Extract piano samples and loops as mono files:
    1. For stereo samples (L/R), combine into mono
    2. Normalize each sample/loop
    3. Save full samples to samples/ and loops to loops/
    """
    # Create output directories
    os.makedirs(output_dir, exist_ok=True)
    samples_dir = os.path.join(output_dir, "samples")
    loops_dir = os.path.join(output_dir, "loops")
    os.makedirs(samples_dir, exist_ok=True)
    os.makedirs(loops_dir, exist_ok=True)
    
    print(f"Opening SF2 file: {sf2_path}")
    try:
        with open(sf2_path, "rb") as sf2_file:
            sf2 = Sf2File(sf2_file)
            
            # Dictionary to store piano samples by MIDI note and channel
            piano_samples = {}
            
            # First pass: identify piano samples by name and group by note
            for i, sample in enumerate(sf2.samples):
                # Skip terminal/EOS samples
                if sample.name.lower().startswith("eot") or sample.name.lower().startswith("eow"):
                    continue
                
                # Check if this is a piano sample
                if "P200 Piano" in sample.name:
                    try:
                        # Extract the actual note from the sample name
                        name_parts = sample.name.split("Piano ")[1].split("(")[0]
                        note_name = name_parts.strip()
                        
                        # Calculate actual MIDI note from name (e.g., "D2" -> MIDI note 38)
                        midi_note = note_name_to_midi(note_name)
                        
                        # Skip if we can't determine the note
                        if midi_note is None:
                            print(f"Warning: Could not determine MIDI note for {sample.name}, skipping.")
                            continue
                    except (IndexError, ValueError):
                        print(f"Warning: Could not parse note name from {sample.name}, using original_pitch.")
                        midi_note = sample.original_pitch
                        note_name = midi_to_note_name(midi_note)
                    
                    # Get channel (L or R)
                    channel = "L" if "(L)" in sample.name else "R" if "(R)" in sample.name else "M"
                    
                    # Store by MIDI note and channel
                    if midi_note not in piano_samples:
                        piano_samples[midi_note] = {"L": None, "R": None, "M": None, "name": note_name}
                    
                    piano_samples[midi_note][channel] = {"index": i, "sample": sample}
            
            # Second pass: process each note
            processed_notes = []
            sample_info = []
            
            print("\nProcessing piano samples and loops...")
            for midi_note in sorted(piano_samples.keys()):
                note_data = piano_samples[midi_note]
                note_name = note_data["name"]
                
                # Create filenames
                base_filename = f"{midi_note:03d}_{note_name}"
                sample_filename = f"{base_filename}.wav"
                loop_filename = f"{base_filename}_loop.wav"
                sample_path = os.path.join(samples_dir, sample_filename)
                loop_path = os.path.join(loops_dir, loop_filename)
                
                # Track success
                full_sample_success = False
                loop_success = False
                
                # First try stereo samples
                if note_data["L"] is not None and note_data["R"] is not None:
                    sample_l = note_data["L"]["sample"]
                    sample_r = note_data["R"]["sample"]
                    
                    # Get full audio for both channels
                    try:
                        audio_l = extract_audio(sample_l)
                        audio_r = extract_audio(sample_r)
                        
                        # Ensure both samples are the same length
                        min_length = min(len(audio_l), len(audio_r))
                        audio_l = audio_l[:min_length]
                        audio_r = audio_r[:min_length]
                        
                        # Mix down to mono
                        audio_mono = (audio_l + audio_r) / 2
                        
                        # Normalize full sample
                        peak = np.max(np.abs(audio_mono))
                        if peak > 0:
                            audio_mono = audio_mono / peak
                            
                        # Save full sample
                        sf.write(sample_path, audio_mono, sample_l.sample_rate, subtype="FLOAT")
                        full_sample_success = True
                        
                        # Process loop if available
                        if (sample_l.start_loop < sample_l.end_loop and 
                            sample_r.start_loop < sample_r.end_loop):
                            
                            # Extract loop portions
                            loop_l = audio_l[sample_l.start_loop:sample_l.end_loop]
                            loop_r = audio_r[sample_r.start_loop:sample_r.end_loop]
                            
                            # Ensure loops are same length
                            min_loop_length = min(len(loop_l), len(loop_r))
                            loop_l = loop_l[:min_loop_length]
                            loop_r = loop_r[:min_loop_length]
                            
                            # Mix down to mono
                            loop_mono = (loop_l + loop_r) / 2
                            
                            # Normalize loop
                            loop_peak = np.max(np.abs(loop_mono))
                            if loop_peak > 0:
                                loop_mono = loop_mono / loop_peak
                            
                            # Save loop
                            sf.write(loop_path, loop_mono, sample_l.sample_rate, subtype="FLOAT")
                            loop_success = True
                    except Exception as e:
                        print(f"  Error processing stereo sample for {note_name}: {e}")
                
                # Try mono sample if stereo failed
                if not full_sample_success and note_data["M"] is not None:
                    sample = note_data["M"]["sample"]
                    try:
                        # Get full audio
                        audio = extract_audio(sample)
                        
                        # Normalize
                        peak = np.max(np.abs(audio))
                        if peak > 0:
                            audio = audio / peak
                        
                        # Save
                        sf.write(sample_path, audio, sample.sample_rate, subtype="FLOAT")
                        full_sample_success = True
                        
                        # Process loop if available
                        if sample.start_loop < sample.end_loop:
                            loop = audio[sample.start_loop:sample.end_loop]
                            sf.write(loop_path, loop, sample.sample_rate, subtype="FLOAT")
                            loop_success = True
                    except Exception as e:
                        print(f"  Error processing mono sample for {note_name}: {e}")
                
                # Try single channel if needed
                if not full_sample_success:
                    for channel in ["L", "R"]:
                        if note_data[channel] is not None:
                            sample = note_data[channel]["sample"]
                            try:
                                # Get full audio
                                audio = extract_audio(sample)
                                
                                # Normalize
                                peak = np.max(np.abs(audio))
                                if peak > 0:
                                    audio = audio / peak
                                
                                # Save
                                sf.write(sample_path, audio, sample.sample_rate, subtype="FLOAT")
                                full_sample_success = True
                                
                                # Process loop if available
                                if sample.start_loop < sample.end_loop:
                                    loop = audio[sample.start_loop:sample.end_loop]
                                    sf.write(loop_path, loop, sample.sample_rate, subtype="FLOAT")
                                    loop_success = True
                                
                                break
                            except Exception as e:
                                print(f"  Error processing {channel} channel for {note_name}: {e}")
                
                # Report results
                if full_sample_success:
                    print(f"  Processed MIDI note {midi_note} ({note_name}):")
                    print(f"    - Full sample: {sample_filename}")
                    if loop_success:
                        print(f"    - Loop: {loop_filename}")
                    
                    processed_notes.append({
                        "midi": midi_note,
                        "note": note_name,
                        "sample": sample_filename if full_sample_success else None,
                        "loop": loop_filename if loop_success else None
                    })
                    
                    # Add to sample info
                    sample_info.append({
                        "midi": midi_note,
                        "note": note_name,
                        "sample_file": sample_filename,
                        "loop_file": loop_filename if loop_success else None
                    })
                else:
                    print(f"  Failed to process MIDI note {midi_note} ({note_name})")
            
            # Write info file
            info_path = os.path.join(output_dir, "piano_samples_info.json")
            with open(info_path, "w") as f:
                json.dump({
                    "source": sf2_path,
                    "sample_rate": 32000,  # Most piano samples use this rate
                    "samples": sample_info
                }, f, indent=2)
            
            print(f"\nSuccessfully processed {len(processed_notes)} piano samples")
            print(f"Detailed info saved to: {info_path}")
            return True
            
    except Exception as e:
        print(f"Error processing SF2 file: {e}")
        import traceback
        traceback.print_exc()
        return False

def extract_audio(sample):
    """Extract audio data from a sample as float32 array"""
    raw_data = sample.raw_sample_data
    
    # Convert to float32 array based on sample width
    if sample.sample_width == 2:  # 16-bit
        return np.frombuffer(raw_data, dtype="<i2").astype(np.float32) / 32768.0
    else:  # 8-bit
        return (np.frombuffer(raw_data, dtype=np.uint8).astype(np.float32) - 128.0) / 128.0

def note_name_to_midi(note_name):
    """Convert a note name like 'C4' or 'F#2' to a MIDI note number"""
    try:
        note = note_name.strip()
        if len(note) < 2:
            return None
            
        # Extract note and octave
        if len(note) >= 2 and note[1] in ['#', 'b']:
            pitch_class = note[0:2]
            octave = int(note[2:])
        else:
            pitch_class = note[0]
            octave = int(note[1:])
        
        # Map pitch classes to semitone values
        pitch_classes = {
            'C': 0, 'C#': 1, 'Db': 1, 'D': 2, 'D#': 3, 'Eb': 3,
            'E': 4, 'F': 5, 'F#': 6, 'Gb': 6, 'G': 7, 'G#': 8,
            'Ab': 8, 'A': 9, 'A#': 10, 'Bb': 10, 'B': 11
        }
        
        # Calculate MIDI note
        return pitch_classes[pitch_class] + (octave + 1) * 12
    except (ValueError, KeyError, IndexError):
        return None

def midi_to_note_name(midi_number):
    """Convert MIDI note number to note name (e.g., 60 -> C4)"""
    notes = ['C', 'C#', 'D', 'D#', 'E', 'F', 'F#', 'G', 'G#', 'A', 'A#', 'B']
    octave = (midi_number // 12) - 1
    note = notes[midi_number % 12]
    return f"{note}{octave}"

def main():
    # Default values
    default_sf2_path = "midi/sf2/FluidR3_GM/FluidR3_GM.sf2"
    default_output_dir = "midi/sf2"
    
    import argparse
    parser = argparse.ArgumentParser(description='Extract mono piano samples and loops')
    parser.add_argument('--sf2', default=default_sf2_path, help='Path to the SF2 file')
    parser.add_argument('--output', default=default_output_dir, help='Output directory')
    
    args = parser.parse_args()
    
    success = extract_mono_samples_and_loops(args.sf2, args.output)
    if not success:
        sys.exit(1)

if __name__ == '__main__':
    main()
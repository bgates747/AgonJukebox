#!/usr/bin/env python3
"""
MIDI to CSV Converter - Extracts MIDI data to CSV format
Specifically designed for piano roll files from Stanford's collection
"""

import os
import csv
import pretty_midi
from pathlib import Path

def midi_to_csv(input_file, output_file):
    """
    Convert a MIDI file to CSV format with detailed information about notes, 
    including timing, pitch, velocity (volume), and duration.
    
    Parameters:
    -----------
    input_file : str
        Path to the input MIDI file
    output_file : str
        Path to the output CSV file
    """
    try:
        # Load the MIDI file
        midi_data = pretty_midi.PrettyMIDI(input_file)
        
        # Get some basic information about the MIDI file
        tempo_changes = midi_data.get_tempo_changes()
        time_signature_changes = midi_data.time_signature_changes
        key_signature_changes = midi_data.key_signature_changes
        
        # Create the output directory if it doesn't exist
        os.makedirs(os.path.dirname(output_file), exist_ok=True)
        
        # Open the CSV file for writing
        with open(output_file, 'w', newline='') as csv_file:
            writer = csv.writer(csv_file)
            
            # Write header information
            writer.writerow(['# MIDI File Information'])
            writer.writerow(['Filename', os.path.basename(input_file)])
            writer.writerow(['Duration (seconds)', f"{midi_data.get_end_time():.2f}"])
            writer.writerow(['Resolution (ticks/beat)', midi_data.resolution])
            
            # Write tempo changes
            writer.writerow([])
            writer.writerow(['# Tempo Changes'])
            writer.writerow(['Time (seconds)', 'Tempo (BPM)'])
            for time, tempo in zip(*tempo_changes):
                writer.writerow([f"{time:.4f}", f"{tempo:.2f}"])
            
            # Write time signature changes if any
            if time_signature_changes:
                writer.writerow([])
                writer.writerow(['# Time Signature Changes'])
                writer.writerow(['Time (seconds)', 'Numerator', 'Denominator'])
                for ts in time_signature_changes:
                    writer.writerow([f"{ts.time:.4f}", ts.numerator, ts.denominator])
            
            # Write key signature changes if any
            if key_signature_changes:
                writer.writerow([])
                writer.writerow(['# Key Signature Changes'])
                writer.writerow(['Time (seconds)', 'Key', 'Mode'])
                for ks in key_signature_changes:
                    writer.writerow([f"{ks.time:.4f}", ks.key_number, ks.mode])
            
            # Write information for each instrument
            for i, instrument in enumerate(midi_data.instruments):
                writer.writerow([])
                writer.writerow([f"# Instrument {i+1}: {instrument.name if instrument.name else 'Unnamed'} {'(Drum)' if instrument.is_drum else ''}"])
                writer.writerow(['Note #', 'Start (s)', 'End (s)', 'Duration (s)', 'Pitch', 'Note Name', 'Velocity', 'Note-on Velocity', 'Note-off Velocity'])
                
                # Sort notes by start time for better readability
                sorted_notes = sorted(instrument.notes, key=lambda x: x.start)
                
                for j, note in enumerate(sorted_notes):
                    # Convert MIDI pitch number to note name (e.g., 60 -> C4)
                    note_name = pretty_midi.note_number_to_name(note.pitch)
                    
                    # Write note data
                    writer.writerow([
                        j+1,
                        f"{note.start:.4f}",
                        f"{note.end:.4f}",
                        f"{note.end - note.start:.4f}",
                        note.pitch,
                        note_name,
                        note.velocity,
                        note.velocity,  # Note-on velocity
                        0  # Note-off velocity (pretty_midi doesn't store this separately)
                    ])
                
                # Write control changes for this instrument
                if instrument.control_changes:
                    writer.writerow([])
                    writer.writerow([f"# Control Changes for Instrument {i+1}"])
                    writer.writerow(['Time (s)', 'Control Number', 'Control Name', 'Value'])
                    
                    # Get all control changes and sort by time
                    ctrl_changes = sorted(instrument.control_changes, key=lambda x: x.time)
                    
                    for cc in ctrl_changes:
                        # Map some common control numbers to names
                        ctrl_name = {
                            1: 'Modulation',
                            7: 'Volume',
                            10: 'Pan',
                            64: 'Sustain Pedal',
                            91: 'Reverb',
                            93: 'Chorus'
                        }.get(cc.number, f"Control {cc.number}")
                        
                        writer.writerow([
                            f"{cc.time:.4f}",
                            cc.number,
                            ctrl_name,
                            cc.value
                        ])
            
            # Write a summary of the MIDI data
            writer.writerow([])
            writer.writerow(['# Summary'])
            writer.writerow(['Total Instruments', len(midi_data.instruments)])
            total_notes = sum(len(instrument.notes) for instrument in midi_data.instruments)
            writer.writerow(['Total Notes', total_notes])
            
            print(f"Successfully converted {input_file} to {output_file}")
            print(f"Total notes: {total_notes}")
            print(f"Duration: {midi_data.get_end_time():.2f} seconds")
            
    except Exception as e:
        print(f"Error converting {input_file}: {e}")
        return False
        
    return True

def main(input_file, output_file=None):
    # If output file is not specified, use the input filename with .csv extension
    if not output_file:
        input_path = Path(input_file)
        output_dir = Path('midi/out')
        output_dir.mkdir(parents=True, exist_ok=True)
        output_file = str(output_dir / (input_path.stem + '.csv'))
    
    midi_to_csv(input_file, output_file)

if __name__ == '__main__':
    # Directly specify the input and output paths
    input_file = 'midi/in/xm993qd2681-exp-tempo95.mid'
    main(input_file)
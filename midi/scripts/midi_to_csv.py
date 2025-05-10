#!/usr/bin/env python3
"""
MIDI Processing Pipeline - Converts MIDI to CSV and then to ez80 assembly
Specifically designed for piano roll files from Stanford's collection
Includes tempo adjustment feature for playback speed correction
"""

import os
import csv
import pretty_midi
from pathlib import Path
from csv_to_inc import csv_to_inc

def midi_to_csv(midi_file, csv_file, tempo_factor=1.0):
    """
    Complete MIDI processing pipeline:
    1. Converts MIDI to CSV with tempo adjustment
    2. Converts CSV to ez80 assembly include file
    
    Parameters:
    -----------
    midi_file : str
        Path to the input MIDI file
    csv_file : str
        Path to the output CSV file
    tempo_factor : float
        Factor to adjust playback speed (e.g., 1.5 = 50% faster, 2.0 = double-speed)
    """
    try:
        # Load the MIDI file
        midi_data = pretty_midi.PrettyMIDI(midi_file)
        
        # Get some basic information about the MIDI file
        tempo_changes = midi_data.get_tempo_changes()
        time_signature_changes = midi_data.time_signature_changes
        key_signature_changes = midi_data.key_signature_changes
        
        # Open the CSV file for writing
        with open(csv_file, 'w', newline='') as csv_file_obj:
            writer = csv.writer(csv_file_obj)
            
            # Write header information
            writer.writerow(['# MIDI File Information'])
            writer.writerow(['Filename', os.path.basename(midi_file)])
            writer.writerow(['Duration (seconds)', f"{midi_data.get_end_time()/tempo_factor:.2f}"])
            writer.writerow(['Tempo Adjustment Factor', f"{tempo_factor:.2f}"])
            writer.writerow(['Resolution (ticks/beat)', midi_data.resolution])
            
            # Write tempo changes
            writer.writerow([])
            writer.writerow(['# Tempo Changes'])
            writer.writerow(['Time (seconds)', 'Tempo (BPM)'])
            for time, tempo in zip(*tempo_changes):
                # Apply tempo adjustment to time value
                adjusted_time = time / tempo_factor
                writer.writerow([f"{adjusted_time:.4f}", f"{tempo:.2f}"])
            
            # Write time signature changes if any
            if time_signature_changes:
                writer.writerow([])
                writer.writerow(['# Time Signature Changes'])
                writer.writerow(['Time (seconds)', 'Numerator', 'Denominator'])
                for ts in time_signature_changes:
                    # Apply tempo adjustment to time value
                    adjusted_time = ts.time / tempo_factor
                    writer.writerow([f"{adjusted_time:.4f}", ts.numerator, ts.denominator])
            
            # Write key signature changes if any
            if key_signature_changes:
                writer.writerow([])
                writer.writerow(['# Key Signature Changes'])
                writer.writerow(['Time (seconds)', 'Key', 'Mode'])
                for ks in key_signature_changes:
                    # Apply tempo adjustment to time value
                    adjusted_time = ks.time / tempo_factor
                    writer.writerow([f"{adjusted_time:.4f}", ks.key_number, ks.mode])
            
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
                    
                    # Apply tempo adjustment to timing values
                    adjusted_start = note.start / tempo_factor
                    adjusted_end = note.end / tempo_factor
                    adjusted_duration = (note.end - note.start) / tempo_factor
                    
                    # Write note data
                    writer.writerow([
                        j+1,
                        f"{adjusted_start:.4f}",
                        f"{adjusted_end:.4f}",
                        f"{adjusted_duration:.4f}",
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
                        # Apply tempo adjustment to time value
                        adjusted_time = cc.time / tempo_factor
                        
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
                            f"{adjusted_time:.4f}",
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
        

        print(f"MIDI processing complete!")
        print(f"MIDI file: {midi_file}")
        print(f"CSV file: {csv_file}")
        print(f"Tempo adjustment factor: {tempo_factor:.2f}")
        print(f"Original duration: {midi_data.get_end_time():.2f} seconds")
        print(f"Adjusted duration: {midi_data.get_end_time()/tempo_factor:.2f} seconds")
        print(f"Total notes: {total_notes}")
            
    except Exception as e:
        print(f"Error processing {midi_file}: {e}")
        return False
        
    return True

if __name__ == '__main__':
    # Define directories
    in_dir = 'midi/in'
    out_dir = 'midi/out'
    
    # Define base filename
    base_name = 'dx555xv9093-exp-tempo95'
    
    # Build file paths
    midi_file = f"{in_dir}/{base_name}.mid"
    csv_file = f"{out_dir}/{base_name}.csv"
    inc_file = f"{out_dir}/{base_name}.inc"
    
    # Set tempo adjustment factor:
    # 1.0 = original tempo
    # 1.5 = 50% faster
    # 2.0 = twice as fast
    # 0.5 = half speed
    tempo_factor = 1.5  # Adjust this value based on the specific roll
    
    # Process the MIDI file
    midi_to_csv(midi_file, csv_file, tempo_factor)
    csv_to_inc(csv_file, inc_file, tempo_factor)
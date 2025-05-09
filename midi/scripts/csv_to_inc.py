#!/usr/bin/env python3
"""
CSV to Assembly Converter for ez80
Converts a MIDI CSV file to an ez80 assembly language include file.
Converts MIDI pitch values to frequency in Hz.
"""

import os
import re

def midi_to_freq(pitch):
    """
    Convert MIDI pitch (0-127) to frequency in Hz.
    MIDI pitch 69 = A4 = 440 Hz
    Each semitone is a factor of 2^(1/12)
    """
    freq = 440.0 * (2.0 ** ((pitch - 69) / 12.0))
    # Round to nearest integer
    return round(freq)

def read_csv_to_notes(csv_file):
    """
    Read a CSV file containing MIDI notes data and extract notes for each instrument.
    
    Returns a list of (instrument_number, instrument_name, notes) tuples.
    """
    instruments = []
    current_instrument = None
    current_instr_number = None
    current_instr_name = None
    current_notes = []
    
    with open(csv_file, 'r') as f:
        lines = f.readlines()
    
    print(f"Total lines in file: {len(lines)}")
    print(f"First few lines: {lines[:5]}")
    
    i = 0
    while i < len(lines):
        line = lines[i].strip()
        
        # Check for instrument header
        if line.startswith('# Instrument'):
            # If we already have an instrument, save it before starting a new one
            if current_instrument is not None:
                instruments.append((current_instr_number, current_instr_name, current_notes))
                current_notes = []
            
            # Extract instrument number and name
            parts = line.split(':', 1)
            instr_header = parts[0].strip()
            
            # More robust extraction of instrument number - search for digits in the string
            num_match = re.search(r'\d+', instr_header)
            if num_match:
                current_instr_number = int(num_match.group())
            else:
                # If no number found, use a counter
                current_instr_number = len(instruments) + 1
                
            current_instr_name = parts[1].strip() if len(parts) > 1 else "Unknown"
            current_instrument = current_instr_number
            
            # Debug message
            print(f"Found instrument: {current_instr_number} - {current_instr_name}")
            
            # Skip the header line (Note #, Start, etc.)
            i += 1
            
        # Check if we've hit a data line (starts with a number)
        elif line and line[0].isdigit():
            # Split by comma and extract fields - handle both CSV and simple comma-separated text
            fields = line.split(',')
            if len(fields) >= 8:
                try:
                    note_num = int(fields[0])
                    start = float(fields[1])
                    end = float(fields[2])
                    duration = float(fields[3])
                    pitch = int(fields[4])
                    note_name = fields[5]
                    velocity = int(fields[6])
                    
                    # Add note to current instrument
                    current_notes.append({
                        'note_num': note_num,
                        'start': start,
                        'duration': duration,
                        'pitch': pitch,
                        'note_name': note_name,
                        'velocity': velocity,
                        'instrument': current_instr_number
                    })
                except (ValueError, IndexError) as e:
                    print(f"Error parsing line: {line}")
                    print(f"Fields: {fields}")
                    print(f"Exception: {e}")
                    # Continue with next line
                    i += 1
                    continue
        
        i += 1
    
    # Add the last instrument if there is one
    if current_instrument is not None and current_notes:
        instruments.append((current_instr_number, current_instr_name, current_notes))
    
    return instruments

def convert_to_assembly(instruments, output_file, tempo_factor=1.0):
    """
    Convert instruments and their notes to ez80 assembly format and write to output file.
    
    Parameters:
    -----------
    instruments : list of tuples
        List of (instrument_number, instrument_name, notes) tuples
    output_file : str
        Path to the output assembly include file
    """
    # Merge all notes from all instruments and sort by start time
    all_notes = []
    for instr_num, instr_name, notes in instruments:
        for note in notes:
            note['instrument'] = instr_num
            # Convert MIDI pitch to frequency
            note['freq_hz'] = midi_to_freq(note['pitch'])
            all_notes.append(note)
    
    all_notes.sort(key=lambda x: x['start'])
    
    # Calculate delta times between consecutive notes
    for i in range(len(all_notes)-1):
        delta_seconds = all_notes[i+1]['start'] - all_notes[i]['start']
        # Round to nearest millisecond
        all_notes[i]['delta_ms'] = round(delta_seconds * 1000)
    
    # The last note has no next note, so set delta to 0
    if all_notes:
        all_notes[-1]['delta_ms'] = 0
    
    # Open output file for writing
    with open(output_file, 'w') as f:
        # Write assembly comments with instrument information
        f.write("; MIDI Note Data in ez80 Assembly Format\n")
        f.write("; Generated from CSV file\n\n")
        
        # Enumerate all instruments
        f.write("; Instruments:\n")
        for instr_num, instr_name, _ in instruments:
            f.write(f"; Instrument {instr_num}: {instr_name}\n")
        f.write("\n")
        
        # Write field descriptions as a comment
        f.write("; Format of each note record:\n")
        f.write(";    tnext_lo:    equ 0     ; 1 byte. Time to next note in milliseconds (low byte)\n")
        f.write(";    tnext_hi:    equ 1     ; 1 byte. Time to next note in milliseconds (high byte)\n")
        f.write(";    duration_lo: equ 2     ; 1 byte. Length of time to sound note in milliseconds (low byte)\n")
        f.write(";    duration_hi: equ 3     ; 1 byte. Length of time to sound note in milliseconds (high byte)\n")
        f.write(";    freq_lo:     equ 4     ; 1 byte. Frequency in Hz (low byte)\n")
        f.write(";    freq_hi:     equ 5     ; 1 byte. Frequency in Hz (high byte)\n")
        f.write(";    velocity:    equ 6     ; 1 byte. Loudness of the note to sound (0-127)\n")
        f.write(";    instrument:  equ 7     ; 1 byte. Instrument used to sound note (1-255)\n")
        f.write("\n")
        
        # Write a comment showing total notes count and tempo factor
        f.write(f"; Tempo factor: {tempo_factor}\n\n")
        f.write(f"; Total notes: {len(all_notes)}\n")
      
        # Track maximum values for information
        max_delta = 0
        max_duration = 0
        max_freq = 0
        min_freq = float('inf')
        
        for i, note in enumerate(all_notes):
            # Calculate duration in milliseconds (as 16-bit value)
            duration_ms = round(note['duration'] * 1000)
            max_duration = max(max_duration, duration_ms)
            
            # Split into low and high bytes (little-endian)
            duration_lo = duration_ms & 0xFF
            duration_hi = (duration_ms >> 8) & 0xFF
            
            # Get delta time as 16-bit value
            delta_ms = note['delta_ms']
            max_delta = max(max_delta, delta_ms)
            
            # Split into low and high bytes (little-endian)
            delta_lo = delta_ms & 0xFF
            delta_hi = (delta_ms >> 8) & 0xFF
            
            # Get frequency in Hz (as 16-bit value)
            freq_hz = note['freq_hz']
            max_freq = max(max_freq, freq_hz)
            min_freq = min(min_freq, freq_hz)
            
            # Split into low and high bytes (little-endian)
            freq_lo = freq_hz & 0xFF
            freq_hi = (freq_hz >> 8) & 0xFF
            
            # Write the note data
            f.write(f"    db {delta_lo}, {delta_hi}, {duration_lo}, {duration_hi}, {freq_lo}, {freq_hi}, {note['velocity']}, {note['instrument']}  ; Note {i+1}: {note['note_name']} = {freq_hz} Hz\n")
        
        # Add information about maximum values
        f.write(f"\n; Information:\n")
        f.write(f"; Maximum delta time: {max_delta} ms ({max_delta/1000:.2f} seconds)\n")
        f.write(f"; Maximum note duration: {max_duration} ms ({max_duration/1000:.2f} seconds)\n")
        f.write(f"; Frequency range: {min_freq} Hz to {max_freq} Hz\n")

def csv_to_inc(input_file, output_file, tempo_factor=1.0):
    # Check if file exists
    if not os.path.exists(input_file):
        print(f"Error: Input file '{input_file}' not found.")
        print(f"Current working directory: {os.getcwd()}")
        print(f"Files in directory: {os.listdir(os.path.dirname(input_file) or '.')}")
        return
    
    # Create output directory if it doesn't exist
    output_dir = os.path.dirname(output_file)
    os.makedirs(output_dir, exist_ok=True)
    
    # Read instruments and notes from CSV
    instruments = read_csv_to_notes(input_file)
    
    # Convert to assembly format and write to output file
    convert_to_assembly(instruments, output_file, tempo_factor)
    
    print(f"Conversion complete! Assembly file written to {output_file}")
    
    # Print some basic statistics
    total_notes = sum(len(notes) for _, _, notes in instruments)
    print(f"Total instruments: {len(instruments)}")
    print(f"Total notes: {total_notes}")

if __name__ == '__main__':
    out_dir = 'midi/out'
    base_name = 'dx555xv9093-exp-tempo95'
    csv_file = f"{out_dir}/{base_name}.csv"
    inc_file = f"{out_dir}/{base_name}.inc"
    
    # Set tempo adjustment factor:
    # 1.0 = original tempo
    # 1.5 = 50% faster
    # 2.0 = twice as fast
    # 0.5 = half speed
    tempo_factor = 1.5  # Adjust this value based on the specific roll
    
    # Process the csv file
    csv_to_inc(csv_file, inc_file, tempo_factor)
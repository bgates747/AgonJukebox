#!/usr/bin/env python3
"""
CSV to Assembly Converter for ez80
Converts a MIDI CSV file to an ez80 assembly language include file.
Converts MIDI pitch values to frequency in Hz.
Processes sustain and soft pedal effects.
"""

import os
import re
from collections import defaultdict

def read_csv_with_pedals(csv_file):
    """
    Read a CSV file containing MIDI notes data and extract notes and pedal events for each instrument.
    
    Returns:
    - instruments: list of (instrument_number, instrument_name, notes) tuples
    - pedal_events: dict mapping instrument_number to list of pedal events
    """
    instruments = []
    pedal_events = defaultdict(list)
    
    current_instrument = None
    current_instr_number = None
    current_instr_name = None
    current_notes = []
    reading_control_changes = False
    
    with open(csv_file, 'r') as f:
        lines = f.readlines()
    
    print(f"Total lines in file: {len(lines)}")
    
    i = 0
    while i < len(lines):
        line = lines[i].strip()
        
        # Check for instrument header
        if line.startswith('# Instrument'):
            # If we already have an instrument, save it before starting a new one
            if current_instrument is not None:
                instruments.append((current_instr_number, current_instr_name, current_notes))
                current_notes = []
                reading_control_changes = False
            
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
            
            # Skip the header line (Note #, Start, etc.)
            i += 1
            reading_control_changes = False
            
        # Check if we've reached the control changes section
        elif line.startswith('# Control Changes'):
            reading_control_changes = True
            i += 2  # Skip header lines
            continue
            
        # Check if we're reading control changes
        elif reading_control_changes and line and line[0].isdigit():
            fields = line.split(',')
            if len(fields) >= 4:
                try:
                    time = float(fields[0])
                    control_num = int(fields[1])
                    control_name = fields[2]
                    value = int(fields[3])
                    
                    # Only capture sustain pedal (64) and soft pedal (67) events
                    if control_num == 64 or control_num == 67:
                        pedal_events[current_instr_number].append({
                            'time': time,
                            'control_num': control_num,
                            'value': value
                        })
                except (ValueError, IndexError) as e:
                    print(f"Error parsing control change: {line}")
                    print(f"Exception: {e}")
            
        # Check if we've hit a note data line (starts with a number) and not in control changes
        elif not reading_control_changes and line and line[0].isdigit():
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
                        'end': end,
                        'duration': duration,
                        'pitch': pitch,
                        'note_name': note_name,
                        'velocity': velocity,
                        'instrument': current_instr_number
                    })
                except (ValueError, IndexError) as e:
                    print(f"Error parsing note: {line}")
                    print(f"Exception: {e}")
        
        i += 1
    
    # Add the last instrument if there is one
    if current_instrument is not None and current_notes:
        instruments.append((current_instr_number, current_instr_name, current_notes))
    
    return instruments, pedal_events

def process_pedal_effects(instruments, pedal_events, soft_pedal_factor, sustain_threshold):
    """
    Process pedal effects for each instrument's notes.
    
    Parameters:
    - instruments: list of (instrument_number, instrument_name, notes) tuples
    - pedal_events: dict mapping instrument_number to list of pedal events
    - soft_pedal_factor: how much the soft pedal reduces velocity (0.3 = 30% reduction)
    - sustain_threshold: minimum value for pedal to be considered "on" (typically 1)
    
    Returns:
    - processed_notes: list of notes with adjusted durations and velocities
    """
    all_processed_notes = []
    all_pedal_events = []  # For tracking all pedal events for comments
    
    # Process each instrument
    for instr_num, instr_name, notes in instruments:
        # Get pedal events for this instrument
        instrument_pedal_events = pedal_events.get(instr_num, [])
        
        # Sort pedal events by time
        instrument_pedal_events.sort(key=lambda x: x['time'])
        
        # Initialize pedal state trackers
        sustain_state = []  # List of {time, value} for sustain pedal
        soft_state = []     # List of {time, value} for soft pedal
        
        # Separate sustain and soft pedal events
        for event in instrument_pedal_events:
            if event['control_num'] == 64:  # Sustain pedal
                sustain_state.append({'time': event['time'], 'value': event['value'], 'type': 'sustain', 'instrument': instr_num})
                all_pedal_events.append({'time': event['time'], 'value': event['value'], 'type': 'sustain', 'instrument': instr_num})
            elif event['control_num'] == 67:  # Soft pedal
                soft_state.append({'time': event['time'], 'value': event['value'], 'type': 'soft', 'instrument': instr_num})
                all_pedal_events.append({'time': event['time'], 'value': event['value'], 'type': 'soft', 'instrument': instr_num})
        
        print(f"Instrument {instr_num}: {len(sustain_state)} sustain events, {len(soft_state)} soft pedal events")
        
        # Process each note
        for note in notes:
            processed_note = note.copy()
            
            # Track original values for comments
            processed_note['original_velocity'] = note['velocity']
            processed_note['original_duration'] = note['duration']
            processed_note['velocity_modified'] = False
            processed_note['duration_modified'] = False
            
            # Apply soft pedal effect (velocity reduction)
            # Find the soft pedal state at the start of the note
            soft_pedal_active = False
            for event in soft_state:
                if event['time'] <= note['start']:
                    soft_pedal_active = event['value'] >= sustain_threshold
                elif event['time'] > note['start']:
                    break
            
            # Apply velocity reduction if soft pedal is active
            if soft_pedal_active:
                processed_note['velocity'] = max(1, int(note['velocity'] * (1 - soft_pedal_factor)))
                processed_note['velocity_modified'] = True
            
            # Apply sustain pedal effect (duration extension)
            # First check if the note is affected by sustain pedal
            sustain_on_time = None
            sustain_off_time = None
            
            # Find sustain state at end of note
            for event in sustain_state:
                if event['time'] <= note['end']:
                    if event['value'] >= sustain_threshold:
                        sustain_on_time = event['time']
                    else:
                        sustain_off_time = event['time']
                        sustain_on_time = None  # Reset if pedal was released before note end
                elif event['time'] > note['end']:
                    if sustain_on_time is not None and event['value'] < sustain_threshold:
                        # This is the pedal release after note end
                        sustain_off_time = event['time']
                        break
            
            # Extend note duration if sustained
            if sustain_on_time is not None and sustain_on_time <= note['end']:
                # Find the first pedal release after the note ends
                for event in sustain_state:
                    if event['time'] > note['end'] and event['value'] < sustain_threshold:
                        sustain_off_time = event['time']
                        break
                
                if sustain_off_time is not None:
                    processed_note['end'] = sustain_off_time
                    processed_note['duration'] = sustain_off_time - note['start']
                    processed_note['duration_modified'] = True
            
            all_processed_notes.append(processed_note)
    
    # Sort all notes by start time
    all_processed_notes.sort(key=lambda x: x['start'])
    
    # Sort all pedal events by time for comments
    all_pedal_events.sort(key=lambda x: x['time'])
    
    return all_processed_notes, all_pedal_events

def convert_to_assembly(processed_notes, all_pedal_events, output_file, max_duration):
    # Calculate delta times between consecutive notes
    for i in range(len(processed_notes)-1):
        delta_seconds = processed_notes[i+1]['start'] - processed_notes[i]['start']
        # Round to nearest millisecond
        processed_notes[i]['delta_ms'] = round(delta_seconds * 1000)
    
    # The last note has no next note, so set delta to 0
    if processed_notes:
        processed_notes[-1]['delta_ms'] = 0
    
    # Merge notes and pedal events into a unified timeline
    timeline = []
    
    # Add notes to timeline
    for note in processed_notes:
        timeline.append({
            'type': 'note',
            'time': note['start'],
            'data': note
        })
    
    # Add pedal events to timeline
    for event in all_pedal_events:
        timeline.append({
            'type': 'pedal',
            'time': event['time'],
            'data': event
        })
    
    # Sort timeline by time
    timeline.sort(key=lambda x: x['time'])
    
    # Open output file for writing
    with open(output_file, 'w') as f:
        # Write assembly comments with information
        f.write("; MIDI Note Data in ez80 Assembly Format\n")
        f.write("; Generated from CSV file with pedal effects applied\n\n")
        
        # Write information about pedal processing
        f.write("; Pedal Effects:\n")
        f.write(";   - Sustain pedal (CC 64) extends note durations\n")
        f.write(";   - Soft pedal (CC 67) reduces note velocities\n")
        f.write("\n")
        
        # Write field descriptions as a comment
        f.write("; Format of each note record:\n")
        f.write(";    tnext_lo:    equ 0     ; 1 byte. Time to next note in milliseconds (low byte)\n")
        f.write(";    tnext_hi:    equ 1     ; 1 byte. Time to next note in milliseconds (high byte)\n")
        f.write(";    duration_lo: equ 2     ; 1 byte. Length of time to sound note in milliseconds (low byte)\n")
        f.write(";    duration_hi: equ 3     ; 1 byte. Length of time to sound note in milliseconds (high byte)\n")
        f.write(";    pitch:       equ 4     ; 1 byte. MIDI pitch\n")
        f.write(";    velocity:    equ 5     ; 1 byte. Loudness of the note to sound (0-127)\n")
        f.write(";    instrument:  equ 6     ; 1 byte. Instrument used to sound note (1-255)\n")
        f.write("\n")
        
        # Write a comment showing total notes count
        f.write(f"; Total notes: {len(processed_notes)}\n\n")
      
        f.write("midi_data:\n")

        note_index = 0
        
        # Process the timeline to output notes and pedal event comments
        for item in timeline:
            if item['type'] == 'pedal':
                pedal = item['data']
                pedal_type = "Sustain" if pedal['type'] == 'sustain' else "Soft"
                f.write(f"; t {pedal['time']:.4f} {pedal_type} {pedal['value']} (Instrument {pedal['instrument']})\n")
            else:  # Note event
                note = item['data']
                note_index += 1
                
                # Calculate duration in milliseconds (as 16-bit value)
                duration_ms = round(note['duration'] * 1000)
                duration_ms = min(max_duration, duration_ms)
                
                # Split into low and high bytes (little-endian)
                duration_lo = duration_ms & 0xFF
                duration_hi = (duration_ms >> 8) & 0xFF
                
                # Get delta time as 16-bit value
                delta_ms = note['delta_ms']
                
                # Split into low and high bytes (little-endian)
                delta_lo = delta_ms & 0xFF
                delta_hi = (delta_ms >> 8) & 0xFF
                
                # Build comment with enhanced information
                comment = f"t {note['start']:.4f} {note['note_name']}, tn={delta_ms}, d={duration_ms}"
                
                # Add velocity modification info if applicable
                if note.get('velocity_modified', False):
                    comment += f", soft {note['original_velocity']}->{note['velocity']}"
                
                # Add duration modification info if applicable
                if note.get('duration_modified', False):
                    orig_dur_ms = round(note['original_duration'] * 1000)
                    comment += f", sust {orig_dur_ms}->{duration_ms}"
                
                # Write the note data
                f.write(f"    db {delta_lo},{delta_hi},{duration_lo},{duration_hi},{note['pitch']},{note['velocity']},{note['instrument']} ; n {note_index}: {comment}\n")
        
        # Add end marker
        f.write("    db 255,255,255,255,255,255,255,255  ; End marker\n")

def csv_to_inc(input_file, output_file, soft_pedal_factor, sustain_threshold, max_duration):
    # Check if file exists
    if not os.path.exists(input_file):
        print(f"Error: Input file '{input_file}' not found.")
        print(f"Current working directory: {os.getcwd()}")
        print(f"Files in directory: {os.listdir(os.path.dirname(input_file) or '.')}")
        return
    
    # Create output directory if it doesn't exist
    output_dir = os.path.dirname(output_file)
    os.makedirs(output_dir, exist_ok=True)
    
    # Read instruments and pedal events from CSV
    instruments, pedal_events = read_csv_with_pedals(input_file)
    
    # Process pedal effects
    processed_notes, all_pedal_events = process_pedal_effects(instruments, pedal_events, soft_pedal_factor, sustain_threshold)
    
    # Convert to assembly format and write to output file
    convert_to_assembly(processed_notes, all_pedal_events, output_file, max_duration)
    
    print(f"Conversion complete! Assembly file written to {output_file}")
    print(f"Pedal effects applied: Soft pedal factor = {soft_pedal_factor}, Sustain threshold = {sustain_threshold}")
    
    # Print basic statistics
    print(f"Total instruments: {len(instruments)}")
    print(f"Total notes after processing: {len(processed_notes)}")
    print(f"Total pedal events: {len(all_pedal_events)}")

if __name__ == '__main__':
    out_dir = 'midi/out'
    base_name = 'dx555xv9093-exp-tempo95' # Moonlight Sonata
    base_name = 'tx437pj1389-exp-tempo95' # Brahms Sonata F minor, op. 5. 2nd mvt.
    base_name = 'yb187qn0290-exp-tempo95' # Sonate cis-Moll : (Mondschein). I. und II. Teil
    base_name = 'Arbeau_Thoinot_-_Pavana'
    base_name = 'Beethoven__Ode_to_Joy'
    base_name = 'Bach__Harpsichord_Concerto_1_in_D_minor'

    csv_file = f"{out_dir}/{base_name}.csv"
    inc_file = f"{out_dir}/{base_name}.inc"
    
    # Set parameters
    soft_pedal_factor = 0.3     # How much soft pedal reduces velocity (30%)
    sustain_threshold = 1       # Minimum value for pedal to be considered "on"
    max_duration = 2998 # in milliseconds

    
    # Process the csv file
    csv_to_inc(csv_file, inc_file, soft_pedal_factor, sustain_threshold, max_duration)
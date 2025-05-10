#!/usr/bin/env python3
"""
CSV to Assembly Converter for ez80
Converts a MIDI CSV file to an ez80 assembly language include file.
Converts MIDI pitch values to frequency in Hz.
Processes sustain and soft pedal effects.
Adds piano overtones for richer sound synthesis.
"""

import os
import re
import math
from collections import defaultdict

def midi_to_freq(pitch):
    """
    Convert MIDI pitch (0-127) to frequency in Hz.
    MIDI pitch 69 = A4 = 440 Hz
    Each semitone is a factor of 2^(1/12)
    """
    freq = 440.0 * (2.0 ** ((pitch - 69) / 12.0))
    # Round to nearest integer
    return round(freq)

def clamp_volume(volume, curve_steepness=1.0):
    """
    Clamp volume using logistic curve between 0 and 127
    
    Parameters:
    -----------
    volume : float
        Input volume value (can be outside 0-127 range)
    curve_steepness : float
        Controls how quickly the curve saturates at extremes
        
    Returns:
    --------
    int: Clamped volume value between 0-127
    """
    # Normalize volume to range appropriate for logistic function
    normalized = volume / 127.0 * 12.0 - 6.0  # Map 0-127 to -6 to 6
    # Apply logistic function: 1/(1+e^-x)
    logistic = 1.0 / (1.0 + math.exp(-curve_steepness * normalized))
    # Map 0-1 back to 0-127
    return min(127, max(1, round(logistic * 127.0)))

def determine_register(pitch):
    """
    Determine which register a note belongs to based on pitch
    
    Returns: "bass", "mid", or "high"
    """
    if pitch < 48:  # Below C3
        return "bass"
    elif pitch < 72:  # C3 to B4
        return "mid"
    else:  # C5 and above
        return "high"

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
            
            # Debug message
            print(f"Found instrument: {current_instr_number} - {current_instr_name}")
            
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
                        print(f"Found pedal event: Instrument {current_instr_number}, Time {time}, Control {control_num}, Value {value}")
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

def process_pedal_effects(instruments, pedal_events, soft_pedal_factor=0.3, sustain_threshold=1):
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
            processed_note['is_root'] = True  # Flag to indicate this is a root note, not an overtone
            
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
                print(f"Applied soft pedal to note at {note['start']}: {note['velocity']} -> {processed_note['velocity']}")
            
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
                    print(f"Extended note at {note['start']} from {note['duration']} to {processed_note['duration']}")
            
            # Convert MIDI pitch to frequency
            processed_note['freq_hz'] = midi_to_freq(note['pitch'])
            
            all_processed_notes.append(processed_note)
    
    # Sort all notes by start time
    all_processed_notes.sort(key=lambda x: x['start'])
    
    # Sort all pedal events by time for comments
    all_pedal_events.sort(key=lambda x: x['time'])
    
    return all_processed_notes, all_pedal_events

def add_overtones(processed_notes, overtone_config):
    """
    Add overtones to processed notes based on their register.
    
    Parameters:
    -----------
    processed_notes : list of dicts
        List of notes with processed durations and velocities
    overtone_config : dict
        Configuration with overtone parameters per register
        
    Returns:
    --------
    list: Expanded list of notes with overtones
    """
    notes_with_overtones = []
    
    for note in processed_notes:
        # Determine which register this note belongs to
        register = determine_register(note['pitch'])
        
        # Get the overtone configuration for this register
        config = overtone_config[register]
        
        # The root note is the original note, but we'll add it last
        root_note = note.copy()
        
        # Create a list for this note's overtones
        current_overtones = []
        
        # Add overtones based on register configuration
        for i, (freq_mult, vol_mult) in enumerate(config['overtones']):
            # Skip if volume multiplier is 0 (no overtone)
            if vol_mult == 0:
                continue
                
            # Create a new note for this overtone
            overtone = note.copy()
            
            # Set the frequency based on the multiplier
            overtone['freq_hz'] = round(note['freq_hz'] * freq_mult)
            
            # Apply the volume multiplier and master volume
            scaled_velocity = note['velocity'] * vol_mult * config['master_volume']
            
            # Apply logistic curve clamping to the velocity
            overtone['velocity'] = clamp_volume(scaled_velocity, config['curve_steepness'])
            
            # Set as non-root (overtone)
            overtone['is_root'] = False
            
            # Ensure overtones of the same note have time to next = 0
            overtone['delta_ms'] = 0
            
            # Add a label to indicate which overtone this is
            overtone['overtone_num'] = i + 1
            
            # Set a custom note name for the comment
            overtone['overtone_name'] = f"{note['note_name']} OT{i+1}"
            
            current_overtones.append(overtone)
        
        # Apply master volume to the root note as well
        scaled_root_velocity = root_note['velocity'] * config['master_volume']
        root_note['velocity'] = clamp_volume(scaled_root_velocity, config['curve_steepness'])
        
        # Add overtones in reverse order (highest to lowest) 
        # followed by the root note for proper playback
        # This ensures the time to next note is respected
        current_overtones.reverse()
        
        # Add all overtones to the output list
        notes_with_overtones.extend(current_overtones)
        
        # Finally add the root note
        notes_with_overtones.append(root_note)
    
    # Sort all notes and overtones by start time
    notes_with_overtones.sort(key=lambda x: x['start'])
    
    # Recalculate delta times for all notes
    for i in range(len(notes_with_overtones)-1):
        # If this is not a root note, time to next is 0 (play immediately)
        if not notes_with_overtones[i]['is_root']:
            notes_with_overtones[i]['delta_ms'] = 0
        else:
            # For root notes, calculate delta to the next note's start time
            # unless the next one is an overtone of this note
            next_start = notes_with_overtones[i+1]['start']
            current_start = notes_with_overtones[i]['start']
            delta_seconds = next_start - current_start
            notes_with_overtones[i]['delta_ms'] = round(delta_seconds * 1000)
    
    # The last note has no next note, so set delta to 0
    if notes_with_overtones:
        notes_with_overtones[-1]['delta_ms'] = 0
    
    return notes_with_overtones

def convert_to_assembly(processed_notes, all_pedal_events, output_file, tempo_factor=1.0):
    """
    Convert processed notes to ez80 assembly format and write to output file.
    
    Parameters:
    -----------
    processed_notes : list of dicts
        List of notes with processed durations and velocities
    all_pedal_events : list of dicts
        List of all pedal events for comments
    output_file : str
        Path to the output assembly include file
    tempo_factor : float
        Tempo adjustment factor
    """
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
        f.write("; Generated from CSV file with pedal effects and piano overtones applied\n\n")
        
        # Write information about pedal processing
        f.write("; Pedal Effects:\n")
        f.write(";   - Sustain pedal (CC 64) extends note durations\n")
        f.write(";   - Soft pedal (CC 67) reduces note velocities\n")
        f.write("\n")
        
        # Write information about overtones
        f.write("; Piano Overtones:\n")
        f.write(";   - Bass register (below C3): Fundamental + up to 3 overtones\n")
        f.write(";   - Mid register (C3-B4): Fundamental + up to 2 overtones\n")
        f.write(";   - High register (C5+): Fundamental + 1 overtone\n")
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
        f.write(f"; Total notes: {len(processed_notes)}\n\n")
      
        # Track maximum values for information
        max_delta = 0
        max_duration = 0
        max_freq = 0
        min_freq = float('inf')
        note_index = 0
        
        # Process the timeline to output notes and pedal event comments
        for item in timeline:
            if item['type'] == 'pedal':
                pedal = item['data']
                pedal_type = "Sustain" if pedal['type'] == 'sustain' else "Soft"
                f.write(f"; T {pedal['time']:.4f} {pedal_type} {pedal['value']} (Instrument {pedal['instrument']})\n")
            else:  # Note event
                note = item['data']
                note_index += 1
                
                # Skip overtones that don't exist in the original data
                # but continue the note index counting
                if not note.get('is_root', True) and note.get('velocity', 0) <= 0:
                    continue
                
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
                
                # Build comment with enhanced information
                if note.get('is_root', True):
                    display_name = note['note_name']
                    comment = f"T {note['start']:.4f} {display_name} = {freq_hz} Hz, tnext={delta_ms}, dur={duration_ms}"
                else:
                    display_name = note['overtone_name']
                    comment = f"T {note['start']:.4f} {display_name} = {freq_hz} Hz, tnext={delta_ms}, dur={duration_ms}, overtone"
                
                # Add velocity modification info if applicable
                if note.get('velocity_modified', False):
                    comment += f", soft {note['original_velocity']} -> {note['velocity']}"
                
                # Add duration modification info if applicable
                if note.get('duration_modified', False):
                    orig_dur_ms = round(note['original_duration'] * 1000)
                    comment += f", sustain {orig_dur_ms} -> {duration_ms}"
                
                # Write the note data
                f.write(f"    db {delta_lo}, {delta_hi}, {duration_lo}, {duration_hi}, {freq_lo}, {freq_hi}, {note['velocity']}, {note['instrument']}  ; Note {note_index}: {comment}\n")
        
        # Add end marker
        f.write("    db 255, 255, 255, 255, 255, 255, 255, 255  ; End marker\n")
        
        # Add information about maximum values
        f.write(f"\n; Information:\n")
        f.write(f"; Maximum delta time: {max_delta} ms ({max_delta/1000:.2f} seconds)\n")
        f.write(f"; Maximum note duration: {max_duration} ms ({max_duration/1000:.2f} seconds)\n")
        f.write(f"; Frequency range: {min_freq} Hz to {max_freq} Hz\n")

def csv_to_inc(input_file, output_file, tempo_factor=1.0, soft_pedal_factor=0.3, sustain_threshold=1, overtone_config=None):
    """
    Convert CSV file to assembly include file with pedal processing and overtones.
    
    Parameters:
    -----------
    input_file : str
        Path to the input CSV file
    output_file : str
        Path to the output assembly include file
    tempo_factor : float
        Tempo adjustment factor
    soft_pedal_factor : float
        How much the soft pedal reduces velocity (0.3 = 30% reduction)
    sustain_threshold : int
        Minimum value for pedal to be considered "on" (typically 1)
    overtone_config : dict
        Configuration for overtones per register
    """
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
    
    # Add overtones if configuration is provided
    if overtone_config:
        processed_notes = add_overtones(processed_notes, overtone_config)
        print(f"Added overtones: {len(processed_notes)} total notes after adding overtones")
    
    # Convert to assembly format and write to output file
    convert_to_assembly(processed_notes, all_pedal_events, output_file, tempo_factor)
    
    print(f"Conversion complete! Assembly file written to {output_file}")
    print(f"Pedal effects applied: Soft pedal factor = {soft_pedal_factor}, Sustain threshold = {sustain_threshold}")
    
    # Print basic statistics
    print(f"Total instruments: {len(instruments)}")
    print(f"Total notes after processing: {len(processed_notes)}")
    print(f"Total pedal events: {len(all_pedal_events)}")

if __name__ == '__main__':
    out_dir = 'midi/out'
    base_name = 'dx555xv9093-exp-tempo95'
    csv_file = f"{out_dir}/{base_name}.csv"
    inc_file = f"{out_dir}/{base_name}.inc"
    
    # Set parameters
    tempo_factor = 1.5          # Adjust this value based on the specific roll
    soft_pedal_factor = 0.3     # How much soft pedal reduces velocity (30%)
    sustain_threshold = 1       # Minimum value for pedal to be considered "on"

    clamping_exponent = 0.5  # Steepness of the logistic curve for clamping volume
    master_volume = 2.5  # Master volume multiplier for all overtones
    
    # Piano overtone configuration
    # Structure: frequency multiplier, volume multiplier pairs
    # Use [(1.0, 1.0)] to disable overtones
    overtone_config = {
        "bass": {
            # Overtones for bass register (below C3)
            "overtones": [
                (2.0, 0.5),  # 2nd harmonic at 50% volume
                (3.0, 0.25), # 3rd harmonic at 25% volume
                (4.0, 0.12)  # 4th harmonic at 12% volume
            ],
            "master_volume": master_volume,       # Overall volume multiplier
            "curve_steepness": clamping_exponent      # Logistic curve steepness
        },
        "mid": {
            # Overtones for middle register (C3-B4)
            "overtones": [
                (2.0, 0.4),   # 2nd harmonic at 40% volume
                (3.0, 0.15)   # 3rd harmonic at 15% volume
            ],
            "master_volume": master_volume,
            "curve_steepness": clamping_exponent
        },
        "high": {
            # Overtones for high register (C5 and above)
            "overtones": [
                (2.0, 0.25)   # 2nd harmonic at 25% volume
            ],
            "master_volume": master_volume,
            "curve_steepness": clamping_exponent
        }
    }
    
    # Process the csv file
    csv_to_inc(csv_file, inc_file, tempo_factor, soft_pedal_factor, sustain_threshold, overtone_config)
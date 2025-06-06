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
import wave

def list_sample_pitches_and_durations(samples_dir):
    """
    Scans the given samples_dir for .wav files named with three-digit MIDI pitch numbers,
    and returns a list of (midi_pitch, duration_ms) tuples.
    """
    results = []
    for fname in os.listdir(samples_dir):
        if fname.lower().endswith('.wav'):
            match = re.match(r'(\d{3})\.wav$', fname)
            if match:
                midi_pitch = int(match.group(1))
                wav_path = os.path.join(samples_dir, fname)
                try:
                    with wave.open(wav_path, 'rb') as wf:
                        frames = wf.getnframes()
                        rate = wf.getframerate()
                        duration_ms = int(1000 * frames / rate)
                        results.append((midi_pitch, duration_ms))
                except Exception as e:
                    print(f"Error reading {wav_path}: {e}")
    return results

def find_closest_sample(sample_info, midi_pitch):
    """
    Given a list of (midi_pitch, duration_ms) tuples and a target midi_pitch,
    returns (sample_pitch, sample_duration_ms) of the closest sample.
    If two samples are equally close, the lower pitch is preferred.
    """
    if not sample_info:
        raise ValueError("Sample info list is empty.")
    closest = min(
        sample_info,
        key=lambda s: (abs(s[0] - midi_pitch), s[0])
    )
    return closest  # (sample_pitch, sample_duration_ms)


def read_csv_with_pedals(csv_file):
    """
    Read a CSV file containing MIDI notes data and extract notes and pedal events for each instrument.
    
    Returns:
    - instruments: list of (instrument_number, midi_instrument_name, notes) tuples
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
    - instruments: list of (instrument_number, midi_instrument_name, notes) tuples
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

def convert_to_assembly(processed_notes, all_pedal_events, output_file, sample_info, num_channels):
    """
    Write ez80 assembly from processed_notes + pedal events,
    using dynamic channel assignment (up to 32 channels).
    Each note record is 10 bytes:
      tnext_lo, tnext_hi,
      duration_lo, duration_hi,
      sample_pitch, velocity, instrument, channel,
      freq_lo, freq_hi
    Comments include timestamp, computed/truncated duration, velocity mod, duration mod.
    Durations are clamped to [1, min(global max, pitch-adjusted sample max)].
    """
    processed_notes.sort(key=lambda n: n['start'])
    for i in range(len(processed_notes) - 1):
        dt_s = processed_notes[i+1]['start'] - processed_notes[i]['start']
        processed_notes[i]['delta_ms'] = round(dt_s * 1000)
    if processed_notes:
        processed_notes[-1]['delta_ms'] = 0

    # Build unified timeline
    timeline = []
    for note in processed_notes:
        timeline.append({'type': 'note', 'time': note['start'], 'data': note})
    for ev in all_pedal_events:
        timeline.append({'type': 'pedal', 'time': ev['time'], 'data': ev})
    timeline.sort(key=lambda x: x['time'])

    # Channel state
    chan_remain = [0] * num_channels
    chan_pitch  = [None] * num_channels

    with open(output_file, 'w') as f:
        # Header
        f.write("; Piano note data with dynamic channel assignment\n\n")
        f.write("; Field offsets:\n")
        f.write(";   tnext_lo    equ 0    ; next-note dt low byte\n")
        f.write(";   tnext_hi    equ 1    ; next-note dt high byte\n")
        f.write(";   duration_lo equ 2    ; duration low byte\n")
        f.write(";   duration_hi equ 3    ; duration high byte\n")
        f.write(";   sample_pitch equ 4   ; MIDI pitch of sample file\n")
        f.write(";   velocity    equ 5    ; MIDI velocity\n")
        f.write(";   instrument  equ 6    ; instrument ID\n")
        f.write(";   channel     equ 7    ; Agon channel (0–31)\n")
        f.write(";   freq_lo     equ 8    ; note frequency low byte\n")
        f.write(";   freq_hi     equ 9    ; note frequency high byte\n\n")
        f.write(f"; Total notes: {len(processed_notes)}\n\n")
        f.write("midi_data:\n")

        note_idx = 0
        for item in timeline:
            if item['type'] == 'pedal':
                ev = item['data']
                ptype = "Sustain" if ev['type'] == 'sustain' else "Soft"
                f.write(f"; t {ev['time']:.4f} {ptype} {ev['value']} "
                        f"(Instr {ev['instrument']})\n")
            else:
                note = item['data']
                note_idx += 1
                dt_ms = note['delta_ms']
                note_pitch = note['pitch']
                vel     = note['velocity']
                inst    = note['instrument']
                start_s = note['start']

                # --- Find closest sample and its base duration ---
                sample_pitch, sample_duration = find_closest_sample(sample_info, note_pitch)

                # --- Compute pitch shift factor and adjusted max duration ---
                pitch_factor = 2 ** ((sample_pitch - note_pitch) / 12)
                sample_max_dur = max(1, int(sample_duration * pitch_factor))  # always at least 1ms
                dur_ms = int(note['duration'] * 1000)
                dur_ms = min(dur_ms, sample_max_dur)


                # --- Truncate note duration (never exceed repitched sample) ---
                dur_ms = int(note['duration'] * 1000)
                dur_ms = min(dur_ms, sample_max_dur)

                # --- Frequency (rounded) ---
                freq = round(440 * 2 ** ((note_pitch - 69) / 12))
                freq_lo = freq & 0xFF
                freq_hi = (freq >> 8) & 0xFF

                # --- Channel assignment logic as before ---
                for ch in range(num_channels):
                    chan_remain[ch] = max(0, chan_remain[ch] - dt_ms)
                chosen = next((ch for ch, p in enumerate(chan_pitch) if p == sample_pitch), None)
                if chosen is None:
                    chosen = next((ch for ch in range(num_channels) if chan_remain[ch] == 0), None)
                if chosen is None:
                    chosen = min(range(num_channels), key=lambda ch: chan_remain[ch])
                chan_pitch[chosen] = sample_pitch
                chan_remain[chosen] = dur_ms

                # --- Build comment ---
                comment = f"t={start_s:.3f}s dur={dur_ms}ms"
                if note.get('velocity_modified'):
                    ov = note['original_velocity']
                    nv = note['velocity']
                    comment += f", vel {ov}->{nv}"
                if note.get('duration_modified'):
                    od = round(note['original_duration'] * 1000)
                    comment += f", sust {od}->{dur_ms}"
                comment += f", freq={freq}Hz, sample={sample_pitch}"

                # --- Emit record + comment (10 bytes) ---
                f.write(
                    f"    db {dt_ms & 0xFF},{(dt_ms>>8)&0xFF},"
                    f"{dur_ms & 0xFF},{(dur_ms>>8)&0xFF},"
                    f"{sample_pitch},{vel},{inst},{chosen},"
                    f"{freq_lo},{freq_hi}  ; n{note_idx} {comment}\n"
                )

        f.write("    db 255,255,255,255,255,255,255,255,255,255  ; End marker\n")

def csv_to_inc(input_file, output_file, soft_pedal_factor, sustain_threshold, samples_dir, num_channels):
    # 1) Check input exists
    if not os.path.exists(input_file):
        print(f"Error: Input file '{input_file}' not found.")
        print(f" CWD: {os.getcwd()}")
        print(f" Files: {os.listdir(os.path.dirname(input_file) or '.')}")
        return

    # 2) Ensure output dir
    os.makedirs(os.path.dirname(output_file), exist_ok=True)

    # 3) Read & process
    instruments, pedal_events = read_csv_with_pedals(input_file)

    all_pitches = [n['pitch'] for _, _, notes in instruments for n in notes]
    if all_pitches:
        mn, mx = min(all_pitches), max(all_pitches)
        print(f"MIDI pitch range: {mn} to {mx}")
    else:
        print("No notes found; cannot report pitch range.")

    processed_notes, all_pedal_events = process_pedal_effects(
        instruments, pedal_events, soft_pedal_factor, sustain_threshold
    )

    # 4) Gather sample info and pass to convert_to_assembly
    sample_info = list_sample_pitches_and_durations(samples_dir)

    convert_to_assembly(processed_notes, all_pedal_events, output_file, sample_info, num_channels)

    print(f"Conversion complete! Assembly written to {output_file}")
    print(f"Soft pedal factor = {soft_pedal_factor}, Sustain threshold = {sustain_threshold}")
    print(f" Total instruments: {len(instruments)}")
    print(f" Total notes after processing: {len(processed_notes)}")
    print(f" Total pedal events: {len(all_pedal_events)}")


if __name__ == '__main__':
    out_dir = 'midi/out'
    samples_dir = 'midi/tgt/piano_yamaha'

    base_name = 'Beethoven__Moonlight_Sonata_v1'
    # base_name = 'Beethoven__Moonlight_Sonata_v2'
    # base_name = 'Beethoven__Moonlight_Sonata_3rd_mvt'
    # base_name = 'Beethoven__Ode_to_Joy'
    # base_name = 'Brahms__Sonata_F_minor'
    # base_name = 'STARWARSTHEME'
    # base_name = 'Williams__Star_Wars_Theme'

    csv_file = f"{out_dir}/{base_name}.csv"
    inc_file = f"{out_dir}/{base_name}.inc"
    
    # Set parameters
    soft_pedal_factor = 0.3     # How much soft pedal reduces velocity (30%)
    sustain_threshold = 1       # Minimum value for pedal to be considered "on"
    num_channels = 32

    # Process the csv file
    csv_to_inc(csv_file, inc_file, soft_pedal_factor, sustain_threshold, samples_dir, num_channels)
#!/usr/bin/env python3
"""
CSV to Assembly Converter for ez80 (Pitch-Based)
Converts a MIDI CSV file to an ez80 assembly language include file.
Writes MIDI pitch values instead of frequency in Hz.
Processes sustain and soft pedal effects.
"""

import os
import re
from collections import defaultdict

def read_csv_with_pedals(csv_file):
    instruments = []
    pedal_events = defaultdict(list)
    
    current_instrument = None
    current_instr_number = None
    current_instr_name = None
    current_notes = []
    reading_control_changes = False
    
    with open(csv_file, 'r') as f:
        lines = f.readlines()
    
    i = 0
    while i < len(lines):
        line = lines[i].strip()
        
        if line.startswith('# Instrument'):
            if current_instrument is not None:
                instruments.append((current_instr_number, current_instr_name, current_notes))
                current_notes = []
                reading_control_changes = False
            
            parts = line.split(':', 1)
            instr_header = parts[0].strip()
            num_match = re.search(r'\d+', instr_header)
            if num_match:
                current_instr_number = int(num_match.group())
            else:
                current_instr_number = len(instruments) + 1
                
            current_instr_name = parts[1].strip() if len(parts) > 1 else "Unknown"
            current_instrument = current_instr_number
            i += 1
            reading_control_changes = False

        elif line.startswith('# Control Changes'):
            reading_control_changes = True
            i += 2
            continue

        elif reading_control_changes and line and line[0].isdigit():
            fields = line.split(',')
            if len(fields) >= 4:
                try:
                    time = float(fields[0])
                    control_num = int(fields[1])
                    control_name = fields[2]
                    value = int(fields[3])
                    if control_num in (64, 67):
                        pedal_events[current_instr_number].append({
                            'time': time,
                            'control_num': control_num,
                            'value': value
                        })
                except Exception:
                    pass

        elif not reading_control_changes and line and line[0].isdigit():
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
                except Exception:
                    pass
        i += 1
    
    if current_instrument is not None and current_notes:
        instruments.append((current_instr_number, current_instr_name, current_notes))
    
    return instruments, pedal_events

def process_pedal_effects(instruments, pedal_events, soft_pedal_factor=0.3, sustain_threshold=1):
    all_processed_notes = []
    all_pedal_events = []

    for instr_num, instr_name, notes in instruments:
        events = pedal_events.get(instr_num, [])
        events.sort(key=lambda e: e['time'])

        sustain = []
        soft = []
        for e in events:
            if e['control_num'] == 64:
                sustain.append({'time': e['time'], 'value': e['value'], 'type': 'sustain', 'instrument': instr_num})
                all_pedal_events.append(sustain[-1])
            elif e['control_num'] == 67:
                soft.append({'time': e['time'], 'value': e['value'], 'type': 'soft', 'instrument': instr_num})
                all_pedal_events.append(soft[-1])

        for note in notes:
            processed = note.copy()
            processed['original_velocity'] = note['velocity']
            processed['original_duration'] = note['duration']
            processed['velocity_modified'] = False
            processed['duration_modified'] = False

            # Soft pedal (velocity reduction)
            soft_active = False
            for e in soft:
                if e['time'] <= note['start']:
                    soft_active = e['value'] >= sustain_threshold
                else:
                    break
            if soft_active:
                processed['velocity'] = max(1, int(note['velocity'] * (1 - soft_pedal_factor)))
                processed['velocity_modified'] = True

            # Sustain pedal (duration extension)
            sustain_on = None
            sustain_off = None
            for e in sustain:
                if e['time'] <= note['end']:
                    if e['value'] >= sustain_threshold:
                        sustain_on = e['time']
                    else:
                        sustain_on = None
                elif sustain_on is not None and e['value'] < sustain_threshold:
                    sustain_off = e['time']
                    break

            if sustain_on is not None and sustain_off:
                processed['end'] = sustain_off
                processed['duration'] = sustain_off - note['start']
                processed['duration_modified'] = True

            all_processed_notes.append(processed)

    all_processed_notes.sort(key=lambda x: x['start'])
    all_pedal_events.sort(key=lambda x: x['time'])
    return all_processed_notes, all_pedal_events

def load_samples(samples_dir):
    """
    Scan 'samples_dir' for .wav files named *_PPP.wav, where PPP is pitch.
    Returns two lists of assembly lines: sample_dictionary and sample_filenames.
    """
    import os, re

    files = sorted(f for f in os.listdir(samples_dir) if f.lower().endswith('.wav'))
    sample_dictionary = []
    sample_filenames = []
    for fname in files:
        m = re.search(r'_(\d{3})\.wav$', fname)
        if not m:
            continue
        ppp = m.group(1)
        # dictionary entry: dl fn_PPP, db PPP
        sample_dictionary.append(f"    dl fn_{ppp}")
        sample_dictionary.append(f"    db {int(ppp)}")
        # filename entry with label: fn_PPP: asciz "samples/<fname>"
        sample_filenames.append(f"    fn_{ppp}:    asciz \"samples/{fname}\"")
    return sample_dictionary, sample_filenames

def convert_to_assembly(processed_notes, all_pedal_events, output_file, tempo_factor=1.0, soft_pedal_factor=0.3, sustain_threshold=1):
    for i in range(len(processed_notes) - 1):
        delta = processed_notes[i + 1]['start'] - processed_notes[i]['start']
        processed_notes[i]['delta_ms'] = round(delta * 1000 * tempo_factor)
    if processed_notes:
        processed_notes[-1]['delta_ms'] = 0

    with open(output_file, 'w') as f:
        f.write("; MIDI Note Data in ez80 Assembly Format (7-byte records)\n")
        f.write("; Field offsets:\n")
        f.write(";    tnext_lo:    equ 0     ; time to next note, low byte\n")
        f.write(";    tnext_hi:    equ 1     ; time to next note, high byte\n")
        f.write(";    duration_lo: equ 2     ; note duration, low byte\n")
        f.write(";    duration_hi: equ 3     ; note duration, high byte\n")
        f.write(";    pitch:       equ 4     ; MIDI pitch (0–127)\n")
        f.write(";    velocity:    equ 5     ; MIDI velocity (0–127)\n")
        f.write(";    instrument:  equ 6     ; instrument ID (1–255)\n\n")
        f.write(f"; Tempo factor: {tempo_factor}\n\n")
        f.write(f"; Total notes: {len(processed_notes)}\n\n")
        f.write("midi_data:\n")

        max_delta = 0
        max_dur = 0
        for idx, note in enumerate(processed_notes):
            duration_ms = round(note['duration'] * 1000)
            delta_ms = note['delta_ms']
            max_dur = max(max_dur, duration_ms)
            max_delta = max(max_delta, delta_ms)

            d_lo, d_hi = duration_ms & 0xFF, (duration_ms >> 8) & 0xFF
            t_lo, t_hi = delta_ms & 0xFF, (delta_ms >> 8) & 0xFF
            pitch = note['pitch'] & 0x7F
            vel = note['velocity'] & 0x7F
            inst = note['instrument'] & 0xFF

            comment = f"T {note['start']:.4f} {note['note_name']} pitch={pitch}, tnext={delta_ms}, dur={duration_ms}"
            if note.get('velocity_modified'): comment += f", soft {note['original_velocity']}->{note['velocity']}"
            if note.get('duration_modified'): comment += f", sustain {round(note['original_duration']*1000)}->{duration_ms}"

            comment = "" # DEBUG

            f.write(f"    db {t_lo}, {t_hi}, {d_lo}, {d_hi}, {pitch}, {vel}, {inst}  ; Note {idx+1}: {comment}\n")

        f.write("    db 255,255,255,255,255,255,255  ; End marker\n\n")
        f.write(f"; Maximum delta: {max_delta} ms\n")
        f.write(f"; Maximum duration: {max_dur} ms\n")

        # Pedal summary
        f.write(f"\n; Pedal effects applied: Soft pedal factor = {soft_pedal_factor}, Sustain threshold = {sustain_threshold}\n")
        f.write(f"; Total instruments: {len(set(n['instrument'] for n in processed_notes))}\n")
        f.write(f"; Total notes after processing: {len(processed_notes)}\n")
        f.write(f"; Total pedal events: {len(all_pedal_events)}\n")

        # Append sample table
        sample_dictionary, sample_filenames = load_samples("midi/tgt/samples")
        f.write(f"\nnum_samples:    equ {len(sample_filenames)}\n\n")

        f.write("; Sample dictionary (pointer, bufferId)\n")
        f.write("sample_dictionary:\n")
        for line in sample_dictionary:
            f.write(f"{line}\n")

        f.write("\n; Sample filename strings\n")
        f.write("sample_filenames:\n")
        for line in sample_filenames:
            f.write(f"{line}\n")

def csv_to_inc(input_file, output_file, tempo_factor=1.0, soft_pedal_factor=0.3, sustain_threshold=1):
    if not os.path.exists(input_file):
        print(f"Error: file not found: {input_file}")
        return
    os.makedirs(os.path.dirname(output_file), exist_ok=True)

    instruments, pedal_events = read_csv_with_pedals(input_file)
    processed_notes, all_pedals = process_pedal_effects(instruments, pedal_events, soft_pedal_factor, sustain_threshold)
    convert_to_assembly(processed_notes, all_pedals, output_file, tempo_factor, soft_pedal_factor, sustain_threshold)

    print(f"Conversion complete! Assembly file written to {output_file}")
    print(f"Pedal effects applied: Soft pedal factor = {soft_pedal_factor}, Sustain threshold = {sustain_threshold}")
    print(f"Total instruments: {len(instruments)}")
    print(f"Total notes after processing: {len(processed_notes)}")
    print(f"Total pedal events: {len(all_pedals)}")

if __name__ == '__main__':
    out_dir = 'midi/out'
    base_name = 'dx555xv9093-exp-tempo95'
    csv_file = f"{out_dir}/{base_name}.csv"
    inc_file = f"{out_dir}/{base_name}.inc"

    tempo_factor = 1.5
    soft_pedal_factor = 0.3
    sustain_threshold = 1

    csv_to_inc(csv_file, inc_file, tempo_factor, soft_pedal_factor, sustain_threshold)

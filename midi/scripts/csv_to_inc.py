import os
import re

def read_csv_to_notes(csv_file):
    """
    Read a CSV file containing MIDI notes data and extract notes for each instrument.
    Returns a list of (instrument_number, instrument_name, notes).
    """
    instruments = []
    current_instr_number = None
    current_instr_name = None
    current_notes = []

    with open(csv_file, 'r') as f:
        lines = f.readlines()

    i = 0
    while i < len(lines):
        line = lines[i].strip()
        if line.startswith('# Instrument'):
            if current_instr_number is not None:
                instruments.append((current_instr_number, current_instr_name, current_notes))
                current_notes = []
            parts = line.split(':', 1)
            num_match = re.search(r'\d+', parts[0])
            current_instr_number = int(num_match.group()) if num_match else len(instruments)+1
            current_instr_name = parts[1].strip() if len(parts)>1 else 'Unknown'
            i += 1
        elif line and line[0].isdigit():
            fields = line.split(',')
            if len(fields) >= 7:
                try:
                    note_num = int(fields[0])
                    start = float(fields[1])
                    duration = float(fields[2]) / tempo_factor
                    duration = min(duration,max_duration)
                    pitch = int(fields[4])
                    velocity = int(fields[6])
                    current_notes.append({
                        'start': start,
                        'duration': duration,
                        'pitch': pitch,
                        'velocity': velocity,
                        'instrument': current_instr_number
                    })
                except Exception:
                    pass
        i += 1
    if current_instr_number is not None and current_notes:
        instruments.append((current_instr_number, current_instr_name, current_notes))
    return instruments

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


def convert_to_assembly(instruments, output_file, tempo_factor=1.0):
    """
    Convert instruments and their notes to ez80 assembly format and write to output file.
    Now writes pitch (1 byte) instead of frequency (2 bytes).
    Record format: 7 bytes per note.
    """
    all_notes = []
    for instr_num, instr_name, notes in instruments:
        for note in notes:
            note['instrument'] = instr_num
            all_notes.append(note)
    all_notes.sort(key=lambda x: x['start'])

    # Delta ms between consecutive notes
    for idx in range(len(all_notes)-1):
        dt = (all_notes[idx+1]['start'] - all_notes[idx]['start']) * tempo_factor
        all_notes[idx]['delta_ms'] = round(dt * 1000)
    if all_notes:
        all_notes[-1]['delta_ms'] = 0

    with open(output_file, 'w') as f:
        f.write('; MIDI Note Data in ez80 Assembly Format (7-byte records)\n')
        f.write('; Record offsets and field descriptions:\n')
        f.write(';    tnext_lo:    equ 0     ; 1 byte. Time to next note in ms (low byte)\n')
        f.write(';    tnext_hi:    equ 1     ; 1 byte. Time to next note in ms (high byte)\n')
        f.write(';    duration_lo: equ 2     ; 1 byte. Note duration in ms (low byte)\n')
        f.write(';    duration_hi: equ 3     ; 1 byte. Note duration in ms (high byte)\n')
        f.write(';    pitch:       equ 4     ; 1 byte. MIDI pitch value (0–127)\n')
        f.write(';    velocity:    equ 5     ; 1 byte. Note velocity (0–127)\n')
        f.write(';    instrument:  equ 6     ; 1 byte. Instrument number (1–255)\n')
        f.write(f'; Tempo factor: {tempo_factor}\n')
        f.write(f'; Total notes: {len(all_notes)}\n\n')

        f.write("midi_data:\n")

        for i, note in enumerate(all_notes):
            dur = round(note['duration'] * 1000)
            d_lo = dur & 0xFF; d_hi = (dur>>8)&0xFF
            dt = note['delta_ms']; dt_lo = dt&0xFF; dt_hi=(dt>>8)&0xFF
            pitch = note['pitch'] & 0x7F
            vel = note['velocity'] & 0x7F
            inst = note['instrument'] & 0xFF
            f.write(f"    db {dt_lo}, {dt_hi}, {d_lo}, {d_hi}, {pitch}, {vel}, {inst}  ; Note {i+1}\n")

        # Footer info
        f.write(f"\n; Max delta: {max(n['delta_ms'] for n in all_notes)} ms\n")
        f.write(f"; Max duration: {max(round(n['duration']*1000) for n in all_notes)} ms\n")

        # --- append sample tables ---
        # load sample definitions from disk
        sample_dictionary, sample_filenames = load_samples("midi/tgt/samples")

        # number of samples
        f.write(f"\nnum_samples:    equ {len(sample_filenames)}\n")

        # write dictionary pointers
        f.write("\n; Sample dictionary (pointer, bufferId)\n")
        f.write("sample_dictionary:\n")
        for entry in sample_dictionary:
            f.write(f"    {entry}\n")

        # write filename strings
        f.write("\n; Sample filename strings\n")
        f.write("sample_filenames:\n")
        for entry in sample_filenames:
            f.write(f"    {entry}\n")

def csv_to_inc(input_file, output_file, tempo_factor=1.0):
    if not os.path.exists(input_file):
        print(f"Input file not found: {input_file}")
        return
    os.makedirs(os.path.dirname(output_file), exist_ok=True)
    instruments = read_csv_to_notes(input_file)
    convert_to_assembly(instruments, output_file, tempo_factor)
    print(f"Wrote assembly to {output_file}")

if __name__ == '__main__':
    out_dir = 'midi/out'
    base = 'dx555xv9093-exp-tempo95'
    csv_file = f"{out_dir}/{base}.csv"
    inc_file = f"{out_dir}/{base}.inc"
    tempo_factor = 1.8
    max_duration = 5000 # milliseconds
    csv_to_inc(csv_file, inc_file, tempo_factor)

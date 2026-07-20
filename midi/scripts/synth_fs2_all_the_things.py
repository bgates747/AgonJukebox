#!/usr/bin/env python3
"""
Agon Music Production Pipeline: Sample Export & Assembly Track Generator

- Generates tuned .wav samples for each soundfont.
- Produces samples.inc with filename/buffer ID tables.
- Converts MIDI CSV with pedals into .inc assembly, mapping to correct buffer IDs.
- All mapping/grouping is handled via instrument_defs CSV.
"""

import os
import re
import tempfile
import subprocess
import shutil
import wave
import csv
from io import StringIO
import pretty_midi
import soundfile as sf
from collections import defaultdict
import bisect

#####################
# General Utilities #
#####################

NOTE_NAMES = ['C', 'C#', 'D', 'D#', 'E', 'F', 'F#', 'G', 'G#', 'A', 'A#', 'B']

def midi_to_hz(midi_pitch):
    return 440.0 * (2.0 ** ((midi_pitch - 69) / 12.0))

def midi_to_note_name(midi_pitch):
    octave = (midi_pitch // 12) - 1
    note = NOTE_NAMES[midi_pitch % 12]
    return f"{note}{octave}"

def midi_note_number(note_name, octave):
    note_base = dict(C=0, Cs=1, D=2, Ds=3, E=4, F=5, Fs=6, G=7, Gs=8, A=9, As=10, B=11)
    if len(note_name) > 1 and note_name[1] in ['#', 's']:
        key = note_name[0] + 's'
    else:
        key = note_name[0]
    return 12 * (octave + 1) + note_base[key]

def sanitize_folder_name(name):
    return re.sub(r'[^A-Za-z0-9_\-]', '_', name)

#####################################
# Instrument Defs Parsing/Grouping  #
#####################################

class InstrumentDefs:
    """
    Parses and centralizes all mappings:
      - instrument_number <-> sf_instrument_name
      - sf_instrument_name <-> min instrument_number (buffer pool)
      - sf_instrument_name <-> canonical row (for params)
    """
    def __init__(self, csv_content):
        self.rows = list(csv.DictReader(StringIO(csv_content.strip())))
        self.instnum_to_sf = {}
        self.sf_to_min_instnum = {}
        self.sf_to_row = {}
        for row in self.rows:
            instr_num = int(row["instrument_number"])
            sfn = row["sf_instrument_name"]
            self.instnum_to_sf[instr_num] = sfn
            if sfn not in self.sf_to_min_instnum or instr_num < self.sf_to_min_instnum[sfn]:
                self.sf_to_min_instnum[sfn] = instr_num
                self.sf_to_row[sfn] = row

    def pooled_soundfonts(self):
        """Yield each unique soundfont row once (first encountered)."""
        seen = set()
        for row in self.rows:
            sfn = row["sf_instrument_name"]
            if sfn not in seen:
                seen.add(sfn)
                yield row

    def params_for_sf(self, sfn):
        """Canonical parameters for a pooled soundfont."""
        return self.sf_to_row[sfn]

    def buffer_id(self, sample_pitch, sfn):
        """Low: midi_pitch, Hi: min instrument_number for the pool."""
        return (self.sf_to_min_instnum[sfn] << 8) | (sample_pitch & 0xFF)

    def buffer_id_bytes(self, sample_pitch, sfn):
        val = self.buffer_id(sample_pitch, sfn)
        return val & 0xFF, (val >> 8) & 0xFF

    def folder_for_sf(self, base_dir, sfn):
        return os.path.join(base_dir, sanitize_folder_name(sfn))

######################
# Sample Export Tool #
######################

def build_single_note_midi(midi_pitch, duration, velocity, program, bank=0, is_drum=False):
    pm = pretty_midi.PrettyMIDI()
    instrument = pretty_midi.Instrument(program=program, is_drum=is_drum)
    instrument.bank = bank
    note = pretty_midi.Note(velocity=velocity, pitch=midi_pitch, start=0, end=duration)
    instrument.notes.append(note)
    pm.instruments.append(instrument)
    return pm

def render_with_fluidsynth(sf2_path, midi_path, wav_path, sample_rate, output_gain, duration_s):
    cmd = [
        "fluidsynth", "-ni", sf2_path, midi_path,
        "-F", wav_path, "-r", str(sample_rate), "-g", str(output_gain),
    ]
    subprocess.run(cmd, check=True)
    data, sr = sf.read(wav_path)
    if data.ndim > 1:
        data = data.mean(axis=1)
    nsamp = int(round(duration_s * sr))
    data = data[:nsamp]
    with tempfile.NamedTemporaryFile(suffix=".wav", delete=False) as tmp:
        temp_wav = tmp.name
    sf.write(temp_wav, data, sr, subtype='PCM_U8')
    shutil.move(temp_wav, wav_path)

def make_tunable_samples(note_names, octaves, instrument_defs_csv, samples_base_dir):
    defs = InstrumentDefs(instrument_defs_csv)
    midi_numbers = [midi_note_number(note, octv) for note in note_names for octv in octaves]
    print("Rendering MIDI notes:", midi_numbers)
    for row in defs.pooled_soundfonts():
        folder = defs.folder_for_sf(samples_base_dir, row['sf_instrument_name'])
        os.makedirs(folder, exist_ok=True)
        for f in os.listdir(folder):
            f_path = os.path.join(folder, f)
            if os.path.isfile(f_path): os.remove(f_path)
        print(f"Rendering samples for {row['sf_instrument_name']} (bank {row['bank']}, preset {row['preset']}) → {folder}")
        bank = int(row['bank'])
        preset = int(row['preset'])
        duration = float(row['duration'])
        velocity = int(row['velocity'])
        output_gain = float(row['output_gain'])
        sample_rate = int(row['sample_rate'])
        sf2_path = row['sf2_path']
        for midi_pitch in midi_numbers:
            pm = build_single_note_midi(midi_pitch, duration, velocity, preset, bank, False)
            with tempfile.NamedTemporaryFile(suffix=".mid", delete=False) as tmp:
                midi_path = tmp.name
            pm.write(midi_path)
            out_wav = os.path.join(folder, f"{midi_pitch:03d}.wav")
            render_with_fluidsynth(sf2_path, midi_path, out_wav, sample_rate, output_gain, duration)
            os.remove(midi_path)
            print(f"  {out_wav} written.")
    print("All samples rendered.")

def list_sample_pitches_and_durations(samples_dir):
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
    return min(sample_info, key=lambda s: (abs(s[0] - midi_pitch), s[0]))

def write_samples_inc(defs, samples_base_dir, samples_inc_file, asm_samples_dir):
    sample_dictionary = []
    sample_filenames = []
    count = 0
    for sfn, row in defs.sf_to_row.items():
        folder = defs.folder_for_sf(samples_base_dir, sfn)
        header_comment = (
            f"\n; ---- Instrument {row['instrument_number']}: {row['midi_instrument_name']} ----\n"
            f"; Bank: {row['bank']}  Preset: {row['preset']}  SoundFont: {sfn}\n"
            f"; Duration: {row['duration']}  Velocity: {row['velocity']}  Sample Rate: {row['sample_rate']}\n"
            f"; Folder: {folder}"
        )
        sample_dictionary.append(header_comment)
        sample_filenames.append(header_comment)
        instr_min = defs.sf_to_min_instnum[sfn]
        files = sorted(f for f in os.listdir(folder) if f.lower().endswith('.wav'))
        for fname in files:
            m = re.search(r'(\d{3})\.wav$', fname)
            if not m: continue
            midi_pitch = int(m.group(1))
            frequency = int(round(midi_to_hz(midi_pitch)))
            buffer_id = defs.buffer_id(midi_pitch, sfn)
            buffer_id_hex = f"{buffer_id:04x}"
            sample_dictionary.append(
                f"    dl fn_{buffer_id_hex}, {frequency}, 0x{buffer_id_hex} ; pitch={midi_pitch} ({midi_to_note_name(midi_pitch)})"
            )
            sample_filenames.append(
                f'    fn_{buffer_id_hex}: asciz "{asm_samples_dir}/{sanitize_folder_name(sfn)}/{fname}"'
            )
            count += 1
    with open(samples_inc_file, 'w') as f:
        f.write(f"\nnum_samples: equ {count}\n\n")
        f.write("; Format: filename pointer, frequency, bufferId\n")
        f.write("sample_dictionary:\n")
        for line in sample_dictionary: f.write(f"{line}\n")
        f.write("\n; Sample filename strings\n")
        f.write("sample_filenames:\n")
        for line in sample_filenames: f.write(f"{line}\n")

###########################################
# CSV Track Assembly
###########################################

def parse_control_changes(csv_lines):
    """
    Parses control change sections for all instruments.
    Returns: 
        {instr_num: {control_num: [(time, value), ...]}}
    """
    control_changes = defaultdict(lambda: defaultdict(list))
    current_instr = None
    in_control_section = False
    for line in csv_lines:
        line = line.strip()
        if line.startswith('# Instrument'):
            parts = line.split(':', 1)
            num_match = re.search(r'\d+', parts[0])
            if num_match:
                current_instr = int(num_match.group())
            else:
                current_instr = None
            in_control_section = False
        elif line.startswith('# Control Changes'):
            in_control_section = True
            continue
        elif in_control_section and line and line[0].isdigit():
            fields = line.split(',')
            if len(fields) >= 4:
                try:
                    time = float(fields[0])
                    control_num = int(fields[1])
                    value = int(fields[3])
                    control_changes[current_instr][control_num].append((time, value))
                except Exception:
                    pass
        elif line.startswith('#') or not line:
            in_control_section = False
    # Sort each control change list by time (for binary search)
    for instr_dict in control_changes.values():
        for cc_list in instr_dict.values():
            cc_list.sort()
    return control_changes

def get_controller_value_at_time(cc_list, t, default=127):
    """
    cc_list: [(time, value), ...] sorted by time
    Returns value at time `t` (or default if before first event).
    """
    if not cc_list:
        return default
    idx = bisect.bisect_right(cc_list, (t, float('inf'))) - 1
    if idx >= 0:
        return cc_list[idx][1]
    return default

def read_csv_with_pedals_and_control_changes(song_csv_file):
    """
    Returns:
        - instruments: list of (instr_num, instr_name, notes)
        - pedal_events: dict of sustain/soft events
        - control_changes: {instr_num: {cc_num: [(time, value), ...]}}
    """
    instruments, pedal_events = [], defaultdict(list)
    current_instrument = None
    current_instr_number = None
    current_instr_name = None
    current_notes = []
    reading_control_changes = False
    csv_lines = []
    with open(song_csv_file, 'r') as f:
        lines = f.readlines()
    csv_lines = lines[:]  # For parse_control_changes later

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
                    value = int(fields[3])
                    # Only collect pedal events here for backward compat
                    if control_num in (64, 67):
                        pedal_events[current_instr_number].append({
                            'time': time, 'control_num': control_num, 'value': value
                        })
                except (ValueError, IndexError):
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
                        'note_num': note_num, 'start': start, 'end': end,
                        'duration': duration, 'pitch': pitch, 'note_name': note_name,
                        'velocity': velocity, 'instrument': current_instr_number
                    })
                except (ValueError, IndexError):
                    pass
        i += 1
    if current_instrument is not None and current_notes:
        instruments.append((current_instr_number, current_instr_name, current_notes))

    # Parse all control changes (for all CC types, all instruments)
    control_changes = parse_control_changes(csv_lines)
    return instruments, pedal_events, control_changes

def apply_velocity_with_global(note_velocity, volume, global_volume, global_volume_exp_fact):
    # Standard linear: out = round(volume * note_velocity / 127 * global_volume)
    # Exponential curve for "more natural" gain (optional):
    pre_clip = (volume * note_velocity / 127)
    boosted = pre_clip * (global_volume ** global_volume_exp_fact)
    # Clamp and round to nearest int in MIDI range
    return int(min(round(boosted), 127))

def process_pedal_and_volume_effects(
        instruments, pedal_events, control_changes, 
        soft_pedal_factor, sust_pedal_thresh
    ):
    """
    Processes both pedals and velocity*volume logic.
    Returns processed_notes, all_pedal_events.
    Each processed_note includes the adjusted velocity.
    """
    all_processed_notes = []
    all_pedal_events = []

    for instr_num, instr_name, notes in instruments:
        # --- Build pedal event lists for sustain/soft (legacy) ---
        sustain_state = []
        soft_state = []
        for event in pedal_events.get(instr_num, []):
            if event['control_num'] == 64:
                sustain_state.append({'time': event['time'], 'value': event['value'], 'type': 'sustain', 'instrument': instr_num})
                all_pedal_events.append({'time': event['time'], 'value': event['value'], 'type': 'sustain', 'instrument': instr_num})
            elif event['control_num'] == 67:
                soft_state.append({'time': event['time'], 'value': event['value'], 'type': 'soft', 'instrument': instr_num})
                all_pedal_events.append({'time': event['time'], 'value': event['value'], 'type': 'soft', 'instrument': instr_num})

        # --- Build controller lists (including volume: CC7) ---
        volume_cc = control_changes[instr_num].get(7, [])  # CC7 = Volume
        # Other controllers (pan etc) can be fetched the same way

        # --- Process notes ---
        for note in notes:
            processed_note = note.copy()
            processed_note['original_velocity'] = note['velocity']
            processed_note['original_duration'] = note['duration']
            processed_note['velocity_modified'] = False
            processed_note['duration_modified'] = False

            # Soft pedal effect
            soft_pedal_active = False
            for event in soft_state:
                if event['time'] <= note['start']:
                    soft_pedal_active = event['value'] >= sust_pedal_thresh
                elif event['time'] > note['start']:
                    break
            if soft_pedal_active:
                processed_note['velocity'] = max(1, int(note['velocity'] * (1 - soft_pedal_factor)))
                processed_note['velocity_modified'] = True

            # Volume × Velocity dynamic (use latest volume at note start)
            # Both in range [0,127], result should also be 0..127 (rounded, clamped)
            cc_volume = get_controller_value_at_time(volume_cc, note['start'], default=127)
            combined_vel = int(round((note['velocity'] * cc_volume) / 127))
            combined_vel = max(1, min(127, combined_vel))  # Clamp
            processed_note['velocity'] = combined_vel

            # Sustain pedal effect
            sustain_on_time = None
            sustain_off_time = None
            for event in sustain_state:
                if event['time'] <= note['end']:
                    if event['value'] >= sust_pedal_thresh:
                        sustain_on_time = event['time']
                    else:
                        sustain_off_time = event['time']
                        sustain_on_time = None
                elif event['time'] > note['end']:
                    if sustain_on_time is not None and event['value'] < sust_pedal_thresh:
                        sustain_off_time = event['time']
                        break
            if sustain_on_time is not None and sustain_on_time <= note['end']:
                for event in sustain_state:
                    if event['time'] > note['end'] and event['value'] < sust_pedal_thresh:
                        sustain_off_time = event['time']
                        break
                if sustain_off_time is not None:
                    processed_note['end'] = sustain_off_time
                    processed_note['duration'] = sustain_off_time - note['start']
                    processed_note['duration_modified'] = True

            all_processed_notes.append(processed_note)

    all_processed_notes.sort(key=lambda x: x['start'])
    all_pedal_events.sort(key=lambda x: x['time'])
    return all_processed_notes, all_pedal_events

def build_sample_info_map(defs, base_samples_dir):
    sf_to_samples = {}
    for sfn in defs.sf_to_row:
        folder = defs.folder_for_sf(base_samples_dir, sfn)
        sf_to_samples[sfn] = list_sample_pitches_and_durations(folder)
    return sf_to_samples

def convert_to_assembly(processed_notes, all_pedal_events, output_file, defs, sf_to_samples,num_channels, min_duration_ms, decay_ms, ctrl_events, global_volume, global_volume_exp_fact):
    processed_notes.sort(key=lambda n: n['start'])
    for i in range(len(processed_notes) - 1):
        dt_s = processed_notes[i+1]['start'] - processed_notes[i]['start']
        processed_notes[i]['delta_ms'] = round(dt_s * 1000)
    if processed_notes:
        processed_notes[-1]['delta_ms'] = 0

    timeline = [{'type': 'note', 'time': note['start'], 'data': note} for note in processed_notes]
    timeline += [{'type': 'pedal', 'time': ev['time'], 'data': ev} for ev in all_pedal_events]
    timeline.sort(key=lambda x: x['time'])

    channel_release_time = [0.0] * num_channels
    channel_note_start = [None] * num_channels

    with open(output_file, 'w') as f:
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
        f.write(";   freq_hi     equ 9    ; note frequency high byte\n")
        f.write(";   buffer_id_lo equ 10  ; buffer ID low byte (sample pitch)\n")
        f.write(";   buffer_id_hi equ 11  ; buffer ID hi byte (sample pool instr#)\n\n")
        f.write(f"; Total notes: {len(processed_notes)}\n\n")
        f.write("midi_data:\n")
        note_idx = 0
        for item in timeline:
            if item['type'] == 'pedal':
                ev = item['data']
                ptype = "Sustain" if ev['type'] == 'sustain' else "Soft"
                f.write(f"; t {ev['time']:.4f} {ptype} {ev['value']} (Instr {ev['instrument']})\n")
            else:
                note = item['data']
                note_idx += 1
                dt_ms = note['delta_ms']
                note_pitch = note['pitch']
                inst = note['instrument']
                start_s = note['start']
                sf_instrument_name = defs.instnum_to_sf[inst]
                sample_info = sf_to_samples[sf_instrument_name]
                sample_pitch, sample_duration = find_closest_sample(sample_info, note_pitch)
                pitch_factor = 2 ** ((sample_pitch - note_pitch) / 12)
                sample_max_dur = max(1, int(sample_duration * pitch_factor))
                dur_ms = int(note['duration'] * 1000)
                dur_ms = min(dur_ms, sample_max_dur)
                dur_ms = max(dur_ms, min_duration_ms)
                occupy_ms = dur_ms + decay_ms
                freq = round(440 * 2 ** ((note_pitch - 69) / 12))
                freq_lo = freq & 0xFF
                freq_hi = (freq >> 8) & 0xFF
                note_start_time = note['start'] * 1000

                # === Get volume control (CC7) at note time, default to 127 ===
                volume = 127
                if inst in ctrl_events and 7 in ctrl_events[inst]:
                    volume = get_controller_value_at_time(ctrl_events[inst][7], note['start'])

                # === Apply velocity, volume, and global multiplier with exponent ===
                raw_vel = note['velocity']
                base = raw_vel * volume / 127
                boosted = base * (global_volume ** global_volume_exp_fact)
                vel_final = int(round(min(max(boosted, 0), 127)))

                # Channel allocation
                found_channel = None
                earliest_free_time = float('inf')
                for ch in range(num_channels):
                    if channel_release_time[ch] <= note_start_time:
                        found_channel = ch
                        break
                    elif channel_release_time[ch] < earliest_free_time:
                        earliest_free_time = channel_release_time[ch]
                        oldest_channel = ch
                trunc_comment = ""
                if found_channel is None:
                    ch = oldest_channel
                    prev_start = channel_note_start[ch]
                    trunc_time = note_start_time
                    trunc_comment = f" [TRUNCATE prev:ch{ch} @ {prev_start:.1f} ms -> {trunc_time:.1f} ms]"
                    print(f"TRUNCATED: Channel {ch} note started at {prev_start:.1f} ms, cut by new note at {trunc_time:.1f} ms")
                else:
                    ch = found_channel
                channel_release_time[ch] = note_start_time + occupy_ms
                channel_note_start[ch] = note_start_time
                buffer_id_lo, buffer_id_hi = defs.buffer_id_bytes(sample_pitch, sf_instrument_name)
                comment = f"t={start_s:.3f}s dur={dur_ms}ms"
                if note.get('velocity_modified'):
                    ov = note['original_velocity']
                    nv = note['velocity']
                    comment += f", vel {ov}->{nv}"
                if note.get('duration_modified'):
                    od = round(note['original_duration'] * 1000)
                    comment += f", sust {od}->{dur_ms}"
                comment += f", freq={freq}Hz, sample={sample_pitch}, buffer_id={buffer_id_hi:02X}:{buffer_id_lo:02X}{trunc_comment}"
                f.write(
                    f"    db {dt_ms & 0xFF},{(dt_ms>>8)&0xFF},"
                    f"{dur_ms & 0xFF},{(dur_ms>>8)&0xFF},"
                    f"{sample_pitch},{vel_final},{inst},{ch},"
                    f"{freq_lo},{freq_hi},{buffer_id_lo},{buffer_id_hi}  ; n{note_idx} {comment}\n"
                )
        f.write("    db 255,255,255,255,255,255,255,255,255,255,255,255  ; End marker\n")


def csv_to_inc(song_csv_file, output_file, soft_pedal_factor, sust_pedal_thresh, base_samples_dir, instrument_defs_csv, num_channels, min_duration_ms, decay_ms, global_volume, global_volume_exp_fact):
    if not os.path.exists(song_csv_file):
        print(f"Error: Input file '{song_csv_file}' not found.")
        print(f" CWD: {os.getcwd()}")
        print(f" Files: {os.listdir(os.path.dirname(song_csv_file) or '.')}")
        return
    os.makedirs(os.path.dirname(output_file), exist_ok=True)
    instruments, pedal_events, control_changes = read_csv_with_pedals_and_control_changes(song_csv_file)
    processed_notes, all_pedal_events = process_pedal_and_volume_effects(
        instruments, pedal_events, control_changes, soft_pedal_factor, sust_pedal_thresh
    )
    defs = InstrumentDefs(instrument_defs_csv)
    sf_to_samples = build_sample_info_map(defs, base_samples_dir)
    convert_to_assembly(processed_notes, all_pedal_events, output_file, defs, sf_to_samples,num_channels, min_duration_ms, decay_ms, control_changes, global_volume, global_volume_exp_fact)
    print(f"Conversion complete! Assembly written to {output_file}")
    print(f"Soft pedal factor = {soft_pedal_factor}, Sustain threshold = {sust_pedal_thresh}")
    print(f" Total instruments: {len(instruments)}")
    print(f" Total notes after processing: {len(processed_notes)}")
    print(f" Total pedal events: {len(all_pedal_events)}")



################
# MAIN         #
################

if __name__ == "__main__":
    # Config
    samples_base_dir = "midi/tgt/Samples"
    asm_samples_dir = "Samples"
    samples_inc_file = "midi/src/asm/samples.inc"
    midi_out_dir = 'midi/out'

    instrument_defs = """
instrument_number,midi_instrument_name,bank,preset,sf_instrument_name,duration,velocity,output_gain,sample_rate,sf2_path
1,Bassoon,0,70,Bassoon,2,127,1,16000,midi/sf2/FluidR3_GM/FluidR3_GM.sf2
2,Flute,0,73,Flute,2,127,1,16000,midi/sf2/FluidR3_GM/FluidR3_GM.sf2
3,French_Horns,0,60,French Horns,2,127,1,16000,midi/sf2/FluidR3_GM/FluidR3_GM.sf2
4,Trumpet,0,56,Trumpet,2,127,1,16000,midi/sf2/FluidR3_GM/FluidR3_GM.sf2
5,Trombone,0,57,Trombone,2,127,1,16000,midi/sf2/FluidR3_GM/FluidR3_GM.sf2
6,Orchestral Harp,0,46,Harp,2,127,1,16000,midi/sf2/FluidR3_GM/FluidR3_GM.sf2
7,Bright Acoustic Piano,0,1,Bright Yamaha Grand,2,127,1,16000,midi/sf2/FluidR3_GM/FluidR3_GM.sf2
8,String Ensemble 1,0,48,Strings,2,127,1,16000,midi/sf2/FluidR3_GM/FluidR3_GM.sf2
9,String Ensemble 1,0,50,Synth Strings 1,2,127,1,16000,midi/sf2/FluidR3_GM/FluidR3_GM.sf2
10,Tremolo Strings,0,44,Tremolo,2,127,1,16000,midi/sf2/FluidR3_GM/FluidR3_GM.sf2
11,Timpani,0,47,Timpani,2,127,1,16000,midi/sf2/FluidR3_GM/FluidR3_GM.sf2
    """

    note_names = ["A"]
    octaves = range(0, 8)
    make_tunable_samples(note_names, octaves, instrument_defs, samples_base_dir)

    defs = InstrumentDefs(instrument_defs)
    write_samples_inc(defs, samples_base_dir, samples_inc_file, asm_samples_dir)

    # song_base_name = 'Beethoven__Moonlight_Sonata_v1'
    # song_base_name = 'Beethoven__Moonlight_Sonata_v2'
    # song_base_name = 'Beethoven__Moonlight_Sonata_3rd_mvt'
    # song_base_name = 'Beethoven__Ode_to_Joy'
    # song_base_name = 'Brahms__Sonata_F_minor'
    # song_base_name = 'STARWARSTHEME'
    # song_base_name = 'Williams__Star_Wars_Theme'
    song_base_name = 'Williams__Star_Wars_Theme_mod'
    song_csv_file = f"{midi_out_dir}/{song_base_name}.csv"
    song_inc_file = f"{midi_out_dir}/{song_base_name}.inc"
    soft_pedal_factor = 0.3
    sust_pedal_thresh = 1
    num_channels = 32
    min_duration_ms = 1
    decay_ms = 200
    global_volume = 1.0
    global_volume_exp_fact = 1.0
    csv_to_inc(song_csv_file, song_inc_file, soft_pedal_factor, sust_pedal_thresh, samples_base_dir, instrument_defs, num_channels, min_duration_ms, decay_ms, global_volume, global_volume_exp_fact)

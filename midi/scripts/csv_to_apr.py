#!/usr/bin/env python3
import os
import re
import csv
import numpy as np
from io import StringIO
from scipy.signal import resample_poly, firwin, lfilter
from collections import defaultdict
import bisect
import math
import soundfile as sf
import pretty_midi
import tempfile
import subprocess
import shutil
import tarfile

# ------------------- Utilities -------------------
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

# ------------------ InstrumentDefs ------------------
class InstrumentDefs:
    """
    Parses and centralizes all mappings:
      - instrument_number <-> sf_instrument_name
      - sf_instrument_name <-> min instrument_number (buffer pool)
      - sf_instrument_name <-> canonical row (for params)
    """
    def __init__(self, instrument_defs):
        self.rows = []
        self.instnum_to_sf = {}
        self.sf_to_min_instnum = {}
        self.sf_to_row = {}
        for row in csv.DictReader(StringIO(instrument_defs.strip())):
            instr_num_raw = row["instrument_number"].strip()
            if not instr_num_raw or instr_num_raw.startswith('#') or not instr_num_raw.isdigit():
                continue  # Skip comment lines or blanks
            instr_num = int(instr_num_raw)
            sfn = row["sf_instrument_name"]
            row["is_drum"] = row["is_drum"].strip().upper() == "TRUE"
            self.rows.append(row)
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

# ------------------ Audio Pipeline ------------------

def compute_required_sample_rates_and_durations(note_events_sum, max_harmonic, min_interval, max_interval, defs):
    results = {}

    for instr, pitch_map in note_events_sum.items():
        if not pitch_map:
            results[instr] = []
            continue

        # Detect is_drum for this instrument
        sfn = defs.instnum_to_sf.get(instr)
        is_drum = False
        if sfn:
            params = defs.params_for_sf(sfn)
            is_drum = params.get('is_drum', False)

        if is_drum:
            # For drums: one sample per pitch, always at instrument_defs sample_rate
            plan = []
            drum_sr = int(params.get('sample_rate', 16000))
            for p, rec in pitch_map.items():
                note_name = rec['note_name'] if rec['note_name'] else f"Drum{p}"
                dur_ms = rec['max_dur_ms']
                req_sr = drum_sr
                plan.append((p, note_name, dur_ms, req_sr))
            results[instr] = plan
            continue

        # Melodic
        usage = {p: rec['count'] for p, rec in pitch_map.items()}
        root0 = max(usage, key=usage.get)
        roots = [root0]
        # upward recursion
        current = root0
        top = max(usage)
        while True:
            candidates = {
                p: usage[p]
                for p in usage
                if current + min_interval <= p <= current + max_interval
            }
            if not candidates:
                break
            nxt = max(candidates, key=candidates.get)
            roots.append(nxt)
            current = nxt
            if current >= top:
                break
        # downward recursion
        current = root0
        bottom = min(usage)
        while True:
            candidates = {
                p: usage[p]
                for p in usage
                if current - max_interval <= p <= current - min_interval
            }
            if not candidates:
                break
            nxt = max(candidates, key=candidates.get)
            roots.append(nxt)
            current = nxt
            if current <= bottom:
                break
        roots = sorted(set(roots))
        groups = {r: [] for r in roots}
        for p, rec in pitch_map.items():
            dur_ms = rec['max_dur_ms']
            closest = min(roots, key=lambda r: (abs(r - p), r))
            groups[closest].append((p, dur_ms))
        plan = []
        for r in roots:
            assigned = groups[r]
            if not assigned:
                continue
            max_p = max(p for p, _ in assigned)
            freq  = midi_to_hz(max_p)
            req_sr = int(2 * freq * max_harmonic)
            req_dur = 0
            for p, ms in assigned:
                factor = 2 ** ((r - p) / 12.0)
                need = int(round(ms * factor))
                if need > req_dur:
                    req_dur = need
            plan.append((r, midi_to_note_name(r), req_dur, req_sr))
        results[instr] = plan

    return results

def print_sample_plan(sample_plan, instruments):
    for instr, specs in sample_plan.items():
        name = instruments.get(instr, "<Unknown>")
        print(f"Instrument {instr}: {name}")
        for base_pitch, base_name, req_dur, req_sr in specs:
            print(f"  Sample {base_pitch} ({base_name}): dur={req_dur}ms, sr={req_sr}Hz")
        print()

def aggregate_sample_plan_by_soundfont(sample_plan, defs):
    sf_aggregate = {}

    # initialize containers per soundfont
    for row in defs.pooled_soundfonts():
        sfn = row['sf_instrument_name']
        sf_aggregate[sfn] = {
            'samples': {},  # pitch -> dict of aggregated values
            'sample_rate': int(row['sample_rate'])
        }

    # combine per-instrument plans
    for instr, entries in sample_plan.items():
        sfn = defs.instnum_to_sf.get(instr)
        if sfn is None:
            continue
        pool = sf_aggregate[sfn]
        # Drums: just assign each pitch, don't group or pool
        params = defs.params_for_sf(sfn)
        is_drum = params.get('is_drum', False)
        for pitch, note_name, dur_ms, req_sr in entries:
            rec = pool['samples'].get(pitch)
            if rec is None:
                pool['samples'][pitch] = {
                    'note_name': note_name,
                    'required_duration_ms': dur_ms,
                    'required_sample_rate': req_sr
                }
            else:
                rec['required_duration_ms'] = max(rec['required_duration_ms'], dur_ms)
                rec['required_sample_rate'] = max(rec['required_sample_rate'], req_sr)
        pool['sample_rate'] = max(pool['sample_rate'], int(params['sample_rate']))

    for sfn, data in sf_aggregate.items():
        samples = data['samples']
        data['samples'] = [
            {
                'pitch': pitch,
                'note_name': samples[pitch]['note_name'],
                'required_duration_ms': samples[pitch]['required_duration_ms'],
                'required_sample_rate': samples[pitch]['required_sample_rate']
            }
            for pitch in sorted(samples)
        ]

    return sf_aggregate

def print_sf_plan(sf_plan, defs):
    for sfn, data in sf_plan.items():
        # use the pool’s min instrument_number as the “Instrument” ID
        pool_id = defs.sf_to_min_instnum[sfn]
        print(f"Instrument {pool_id}: {sfn}")

        samples = data['samples']
        if samples:
            for samp in samples:
                p   = samp['pitch']
                nm  = samp['note_name']
                dur = samp['required_duration_ms']
                sr  = samp['required_sample_rate']
                print(f"  Sample {p} ({nm}): dur={dur}ms, sr={sr}Hz")
        else:
            print("  Samples: None")

        # echo the chosen pool-level parameters
        print(f"  Sample Rate: {data['sample_rate']}Hz\n")

def render_sample(sf2_path, midi_pm, sample_rate, output_gain):
    # 1) Write the MIDI to a temp file
    with tempfile.NamedTemporaryFile(suffix=".mid", delete=False) as tmp_mid:
        midi_path = tmp_mid.name
        midi_pm.write(midi_path)

    # 2) Render to a temp WAV via fluidsynth
    with tempfile.NamedTemporaryFile(suffix=".wav", delete=False) as tmp_wav:
        wav_path = tmp_wav.name

    try:
        cmd = [
            "fluidsynth", "-ni",
            sf2_path, midi_path,
            "-F", wav_path,
            "-r", str(sample_rate),
            "-g", str(output_gain),
        ]
        # Suppress all fluidsynth console output
        subprocess.run(cmd, check=True, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)

        # 3) Read back the WAV as float32
        data, sr = sf.read(wav_path, dtype='float32')
        if data.ndim > 1:
            data = data.mean(axis=1)

        # 4) Trim to the exact longest note duration
        duration_s = max(n.end for inst in midi_pm.instruments for n in inst.notes)
        nsamp = int(round(duration_s * sr))
        data = data[:nsamp]

    finally:
        # Clean up temp files
        os.remove(midi_path)
        os.remove(wav_path)

    return data, sample_rate

def resample_audio(data, orig_sr, target_sr):
    if orig_sr == target_sr:
        return data, orig_sr
    from math import gcd
    g = gcd(orig_sr, target_sr)
    up, down = target_sr // g, orig_sr // g
    out = resample_poly(data, up, down)
    return out, target_sr


def lowpass_audio(data, sr, cutoff, numtaps=255):
    nyq = sr / 2
    min_cut = nyq * 0.2
    margin = max(50, nyq * 0.05)
    cutoff = max(min_cut, min(cutoff, nyq - margin))
    taps = firwin(numtaps, cutoff / nyq)
    return lfilter(taps, 1.0, data)


def normalize_audio(data, peak=0.99):
    m = np.max(np.abs(data))
    return data * (peak / m) if m > 0 else data

def make_single_note_pm(pitch, duration_s, velocity, preset, bank=0, is_drum=False):
    pm = pretty_midi.PrettyMIDI()
    inst = pretty_midi.Instrument(program=preset, is_drum=is_drum)
    inst.bank = bank
    inst.notes.append(pretty_midi.Note(velocity=velocity,pitch=pitch,start=0,end=duration_s))
    pm.instruments.append(inst)
    return pm

def choose_sample_rate(freq, min_sample_rate, max_sample_rate, max_harmonic=8):
    """
    Choose a sample rate for a given fundamental frequency:
      - Attempts to cover up to `max_harmonic` harmonics (sample_rate = 2 * freq * harmonics)
      - Never returns a rate below min_sample_rate or above max_sample_rate
      - If min > max, clamps both to max_sample_rate
    Returns: (sample_rate, harmonics_used)
    """
    freq = max(freq, 1.0)
    min_sample_rate = int(min_sample_rate)
    max_sample_rate = int(max_sample_rate)
    if min_sample_rate > max_sample_rate:
        min_sample_rate = max_sample_rate

    h = max_harmonic
    sample_rate = int(2 * freq * h)

    # Clamp down: reduce harmonics if above max_sample_rate
    while sample_rate > max_sample_rate and h > 1:
        h -= 1
        sample_rate = int(2 * freq * h)

    # Clamp up: increase harmonics if below min_sample_rate (up to limit)
    while sample_rate < min_sample_rate and h < 128:
        h += 1
        sample_rate = int(2 * freq * h)

    # Final clamp: never exceed bounds (always, always)
    sample_rate = max(min_sample_rate, min(sample_rate, max_sample_rate))
    return sample_rate, h

def envelope_trim(wav, head_threshold=0.01, tail_threshold=0.03, window_ms=5, sr=16000):
    """
    Trims both head and tail using *separate* thresholds for each.
    Finds first/last envelope crossings and trims to nearest zero-crossing.
    """
    window_len = int(window_ms * sr / 1000)
    if window_len < 1:
        window_len = 1
    abs_wav = np.abs(wav)
    env = np.convolve(abs_wav, np.ones(window_len) / window_len, mode='same')
    peak = np.max(env)
    head_gate = head_threshold * peak
    tail_gate = tail_threshold * peak

    idx_head = np.where(env > head_gate)[0]
    idx_tail = np.where(env > tail_gate)[0]
    if len(idx_head) == 0 or len(idx_tail) == 0:
        return wav[:1]  # All silence

    start_idx = idx_head[0]
    end_idx   = idx_tail[-1]

    def find_zero_cross(arr, from_idx, direction):
        i = from_idx
        if direction < 0:  # search backward
            while i > 0:
                if arr[i-1]*arr[i] <= 0:
                    return i-1 if abs(arr[i-1]) < abs(arr[i]) else i
                i -= 1
            return 0
        else:  # search forward
            while i < len(arr)-1:
                if arr[i]*arr[i+1] <= 0:
                    return i if abs(arr[i]) < abs(arr[i+1]) else i+1
                i += 1
            return len(arr) - 1

    # Trim head: find zero-crossing backward from first loud sample
    head_zc = find_zero_cross(wav, start_idx, -1)
    # Trim tail: find zero-crossing forward from last loud sample
    tail_zc = find_zero_cross(wav, end_idx, +1)

    return wav[head_zc:tail_zc+1]

def generate_and_save_samples(sf_plan, defs, samples_base_dir, min_sample_rate, max_harmonic, min_trial_duration, do_generate_samples):
    instrument_sample_counts = {}
    instrument_file_sizes = {}
    header_printed = False
    
    if do_generate_samples:
        # Clean up files and folders in samples_base_dir
        if os.path.exists(samples_base_dir):
            shutil.rmtree(samples_base_dir)
        os.makedirs(samples_base_dir, exist_ok=True)
        
        for sfn, pool in sf_plan.items():
            params     = defs.params_for_sf(sfn)
            sf2_path   = params['sf2_path']
            bank       = int(params['bank'])
            preset     = int(params['preset'])
            velocity   = int(params['velocity'])
            native_sr  = int(params['sample_rate'])
            inst_num   = int(params['instrument_number'])

            # Initialize tracking for this instrument
            if inst_num not in instrument_sample_counts:
                instrument_sample_counts[inst_num] = 0
                instrument_file_sizes[inst_num] = 0

            out_folder = defs.folder_for_sf(samples_base_dir, sfn)
            os.makedirs(out_folder, exist_ok=True)

            is_drum = params['is_drum'] if 'is_drum' in params else False

            for samp in pool['samples']:
                pitch = samp['pitch']
                dur_ms = max(samp['required_duration_ms'], min_trial_duration)
                dur_s = dur_ms / 1000.0

                # Always render at the instrument's sample rate
                sr = native_sr
                req_sr = native_sr

                pm = make_single_note_pm(pitch, dur_s, velocity, preset, bank, is_drum=is_drum)
                wav, _ = render_sample(sf2_path, pm, sr, output_gain=3.0)

                if not is_drum:
                    freq = midi_to_hz(pitch)
                    # Compute requested sample rate, clamped to [min_sample_rate, native_sr]
                    req_sr, harmonics = choose_sample_rate(freq, min_sample_rate, native_sr, max_harmonic)
                    req_sr = max(min_sample_rate, min(req_sr, native_sr))   # <<< always clamp!
                    if req_sr != sr:
                        wav, _ = resample_audio(wav, sr, req_sr)
                        cutoff = req_sr / 2 - 500
                        wav = lowpass_audio(wav, req_sr, cutoff)
                        sr = req_sr

                # Envelope trim always uses the actual sample rate after resampling
                trimmed_wav = envelope_trim(wav, head_threshold=0.03, tail_threshold=0.03, window_ms=5, sr=sr)
                trimmed_len = len(trimmed_wav) / sr
                if trimmed_len > 0:
                    wav = trimmed_wav
                else:
                    trimmed_len = len(wav) / sr

                # Add the trimmed duration (ms) and output filename to the sample dict
                samp['trimmed_sample_duration_ms'] = int(round(trimmed_len * 1000))
                out_path = os.path.join(out_folder, f"{pitch:03d}.wav")
                samp['filename'] = out_path

                # <<< assert for debugging!
                assert min_sample_rate <= sr <= native_sr, f"Sample rate {sr} not in [{min_sample_rate}, {native_sr}]"

                # print(f"Trimmed sample pitch {pitch}: {dur_s:.3f}s → {trimmed_len:.3f}s")
                sf.write(out_path, wav, sr, subtype='PCM_U8')
                
                # Track file size and sample count
                file_size = os.path.getsize(out_path)
                instrument_sample_counts[inst_num] += 1
                instrument_file_sizes[inst_num] += file_size
                
                # print(f"Wrote {out_path} (sr={sr}Hz, dur≈{len(wav)/sr:.3f}s, is_drum={is_drum})")
            
            # Print header if this is the first instrument
            if not header_printed:
                print("\n" + "="*60)
                print("SAMPLE GENERATION SUMMARY")
                print("="*60)
                header_printed = True
            
            # Print summary for this instrument
            sample_count = instrument_sample_counts[inst_num]
            size_bytes = instrument_file_sizes[inst_num]
            size_mb = size_bytes / (1024 * 1024)
            
            # Get instrument name
            inst_name = params.get('midi_instrument_name', f"Instr{inst_num}")
            
            print(f"Instrument {inst_num:2d} ({inst_name:20s}): {sample_count:3d} samples, {size_mb:7.3f} MB")
        
        # Print total at the end
        if header_printed:
            total_samples = sum(instrument_sample_counts.values())
            total_size_bytes = sum(instrument_file_sizes.values())
            total_size_mb = total_size_bytes / (1024 * 1024)
            print("-" * 60)
            print(f"{'TOTAL':25s}: {total_samples:3d} samples, {total_size_mb:7.3f} MB")
            print("="*60 + "\n")
    
    return sf_plan

# ------------------ Song CSV Parsing and Metadata Generation ------------------

def parse_song_csv(csv_file):
    """
    Parses a song CSV and returns three structures:
      instruments:    dict[instr_num] = instr_name
      note_events:    list of {instrument, note_num, start, …}
      control_events: list of {instrument, time, control_num, control_name, value}
    """
    instruments    = {}
    note_events    = []
    control_events = []

    current_instr   = None
    in_ctrl_section = False

    with open(csv_file) as f:
        for raw in f:
            ln = raw.strip()

            # --- Instrument header ---
            if ln.startswith('# Instrument'):
                m = re.match(r'# Instrument\s*(\d+):?\s*(.*)', ln)
                if m:
                    current_instr           = int(m.group(1))
                    instruments[current_instr] = m.group(2).strip() or f"Instr{current_instr}"
                else:
                    current_instr = None
                in_ctrl_section = False
                continue

            # --- Enter control section ---
            if ln.startswith('# Control Changes'):
                in_ctrl_section = True
                continue

            # --- Control rows ---
            if in_ctrl_section:
                # skip blank lines
                if not ln:
                    in_ctrl_section = False
                    continue
                # skip column-header
                if ln.lower().startswith('time'):
                    continue
                # parse numeric CC rows
                if ln[0].isdigit():
                    parts = ln.split(',')
                    if len(parts) >= 4 and current_instr is not None:
                        try:
                            t    = float(parts[0])
                            cc   = int(parts[1])
                            name = parts[2].strip()
                            val  = int(parts[3])
                            control_events.append({
                                'instrument':   current_instr,
                                'time':         t,
                                'control_num':  cc,
                                'control_name': name,
                                'value':        val
                            })
                            continue
                        except ValueError:
                            pass
                # anything else ends the control section
                in_ctrl_section = False

            # --- Note rows (only when not in ctrl section) ---
            if ln and ln[0].isdigit() and current_instr is not None:
                parts = ln.split(',')
                if len(parts) >= 8:
                    try:
                        note_events.append({
                            'instrument': current_instr,
                            'note_num':   int(parts[0]),
                            'start':      float(parts[1]),
                            'end':        float(parts[2]),
                            'duration':   float(parts[3]),
                            'pitch':      int(parts[4]),
                            'note_name':  parts[5],
                            'velocity':   int(parts[6]),
                        })
                    except ValueError:
                        pass

    return instruments, note_events, control_events

def sustain_pedal_mod_durations(note_events, control_events, sustain_threshold):
    # Build per‐instrument sorted list of sustain events
    sustain_map = defaultdict(list)
    for ev in control_events:
        if ev['control_num'] == 64:
            sustain_map[ev['instrument']].append((ev['time'], ev['value']))
    for lst in sustain_map.values():
        lst.sort(key=lambda x: x[0])
        # separate times for bisect
        # we'll rebuild times on the fly

    new_notes = []
    for note in note_events:
        instr = note['instrument']
        start = note['start']
        end   = note['end']
        dur   = note['duration']

        sustain_list = sustain_map.get(instr, [])
        times = [t for t,_ in sustain_list]

        # Find last sustain event at or before note end
        idx = bisect.bisect_right(times, end) - 1
        if idx >= 0 and sustain_list[idx][1] >= sustain_threshold:
            # Pedal was down at note end → find next off
            off_time = None
            for t, val in sustain_list[idx+1:]:
                if val < sustain_threshold:
                    off_time = t
                    break
            if off_time is not None:
                # Extend note
                new_end  = off_time
                new_dur  = new_end - start
                note_mod = note.copy()
                note_mod['end']      = new_end
                note_mod['duration'] = new_dur
                new_notes.append(note_mod)
                continue

        # No sustain effect → copy original
        new_notes.append(note.copy())

    return new_notes

def summarize_instruments_and_controls(note_events, control_events):
    # --- Build note_events_sum with min, max, and count ---
    note_events_sum = defaultdict(lambda: defaultdict(lambda: {
        'note_name':  None,
        'min_dur_ms': math.inf,
        'max_dur_ms': 0,
        'count':      0
    }))
    for note in note_events:
        instr    = note['instrument']
        pitch    = note['pitch']
        dur_ms   = int(round(note['duration'] * 1000))
        rec      = note_events_sum[instr][pitch]
        rec['note_name'] = note['note_name']
        rec['count']    += 1
        rec['max_dur_ms'] = max(rec['max_dur_ms'], dur_ms)
        rec['min_dur_ms'] = min(rec['min_dur_ms'], dur_ms)

    # Convert any infinite mins back to 0
    for instr in note_events_sum:
        for pitch, rec in note_events_sum[instr].items():
            if rec['min_dur_ms'] == math.inf:
                rec['min_dur_ms'] = 0

    # --- Build control_events_sum ---
    control_events_sum = defaultdict(set)
    for ev in control_events:
        control_events_sum[ev['instrument']].add((ev['control_num'], ev['control_name']))

    return note_events_sum, control_events_sum

def print_instruments_and_controls_summary(instruments, note_events_sum, control_events_sum):
    """
    Pretty-prints the summaries produced by summarize_instruments_and_controls.
    """
    for instr_num, instr_name in instruments.items():
        print(f"Instrument {instr_num}: {instr_name}")

        # Notes
        notes = note_events_sum.get(instr_num, {})
        if notes:
            print("  Notes: Pitch, Note, Count, Min Duration(ms), Max Duration(ms)")
            for pitch in sorted(notes):
                rec = notes[pitch]
                name     = rec['note_name']
                count    = rec['count']
                min_dur  = rec['min_dur_ms']
                max_dur  = rec['max_dur_ms']
                print(f"      {pitch}, {name}, {count}, {min_dur}, {max_dur}")
        else:
            print("  Notes: None")

        # Controls
        ctrls = control_events_sum.get(instr_num)
        if ctrls:
            print("  Controls:")
            for cc, name in sorted(ctrls, key=lambda x: x[0]):
                print(f"    {cc}, {name}")
        else:
            print("  Controls: None")

        print()

def purge_undefined_instruments(defs, instruments, note_events, control_events):
    valid = set(defs.instnum_to_sf.keys())

    filtered_instruments = {
        num: name
        for num, name in instruments.items()
        if num in valid
    }

    filtered_note_events = [
        ev for ev in note_events
        if ev.get('instrument') in valid
    ]

    filtered_control_events = [
        ev for ev in control_events
        if ev.get('instrument') in valid
    ]

    return filtered_instruments, filtered_note_events, filtered_control_events

def find_closest_sample(sample_info, target_pitch):
    """
    Given:
      sample_info: list of (sample_pitch: int, duration_ms: int)
      target_pitch: MIDI pitch to match

    Returns:
      (closest_pitch, duration_ms) tuple for the sample whose pitch is
      nearest to target_pitch (ties broken by higher sample_pitch).
    """
    if not sample_info:
        raise ValueError("sample_info is empty; no samples to choose from")

    # key: (absolute distance, sample_pitch) → picks smallest distance, then lower pitch
    return min(
        sample_info,
        key=lambda s: (abs(s[0] - target_pitch), s[0])
    )

def get_controller_value_at_time(cc_list, t, default=127):
    """
    Given:
      cc_list: sorted list of (time: float, value: int) control-change events
      t:       time in seconds at which to query the controller
      default: value to return if t is before the first event

    Returns the most recent controller value at or before time t.
    """
    if not cc_list:
        return default

    # Extract times for bisect
    times = [ev[0] for ev in cc_list]
    idx = bisect.bisect_right(times, t) - 1
    if idx >= 0:
        return cc_list[idx][1]
    return default

# ------------------ Sample INC Writer ------------------

def write_samples_inc(defs, sf_plan, asm_samples_dir, inc_file):
    entries = []
    filenames = []
    count = 0

    for sfn, row in defs.sf_to_row.items():
        # header
        header = (
            f"; ---- Instrument {row['instrument_number']}: {row['midi_instrument_name']} ----\n"
            f"; SoundFont: {sfn}, Bank: {row['bank']}, Preset: {row['preset']}"
        )
        entries.append(header)
        filenames.append(header)

        # fetch sample list for this soundfont
        pool = sf_plan.get(sfn, {})
        samples = pool.get('samples', [])

        # each entry is a dict with 'pitch'
        for samp in samples:
            pitch = samp['pitch']
            buf_lo, buf_hi = defs.buffer_id_bytes(pitch, sfn)
            freq = int(round(midi_to_hz(pitch)))
            hexid = f"{(buf_hi<<8|buf_lo):04x}"
            entries.append(
                f"    dl fn_{hexid}, {freq}, 0x{hexid} ; pitch={pitch} ({midi_to_note_name(pitch)})"
            )
            filenames.append(
                f'    fn_{hexid}: asciz "{asm_samples_dir}/{sanitize_folder_name(sfn)}/{pitch:03d}.wav"'
            )
            count += 1

    with open(inc_file, 'w') as f:
        f.write(f"num_samples: equ {count}\n\n")
        f.write("; Format: filename pointer, frequency, bufferId\n")
        f.write("sample_dictionary:\n")
        f.write("\n".join(entries) + "\n\n")
        f.write("; Sample filename strings\n")
        f.write("sample_filenames:\n")
        f.write("\n".join(filenames) + "\n\n")


def extract_pedal_events(control_events):
    pedal_types = {64: 'sustain', 67: 'soft'}
    pedal_events = [
        {
            'time': ev['time'],
            'value': ev['value'],
            'type': pedal_types[ev['control_num']],
            'instrument': ev['instrument']
        }
        for ev in control_events if ev['control_num'] in pedal_types
    ]
    return pedal_events

def build_controller_map(control_events):
    ctrl_map = defaultdict(lambda: defaultdict(list))
    for ev in control_events:
        instr, cc = ev['instrument'], ev['control_num']
        ctrl_map[instr][cc].append((ev['time'], ev['value']))
    for instr_dict in ctrl_map.values():
        for lst in instr_dict.values():
            lst.sort(key=lambda x: x[0])
    return ctrl_map

def compute_note_deltas(notes):
    notes = sorted(notes, key=lambda n: n['start'])
    for i in range(len(notes) - 1):
        dt = notes[i+1]['start'] - notes[i]['start']
        notes[i]['delta_ms'] = round(dt * 1000)
    if notes:
        notes[-1]['delta_ms'] = 0
    return notes

def build_unified_timeline(notes, pedal_events):
    timeline = (
        [{'type': 'note',  'time': n['start'],  'data': n} for n in notes] +
        [{'type': 'pedal', 'time': e['time'],   'data': e} for e in pedal_events]
    )
    timeline.sort(key=lambda x: x['time'])
    return timeline

def build_sample_lookup(sf_plan):
    return {
        sfn: [(s['pitch'], s['required_duration_ms']) for s in pool['samples']]
        for sfn, pool in sf_plan.items()
    }

def choose_channel(start_ms, sfn, sample_pitch, min_duration_ms, num_channels, state):
    """
    state: dict containing current channel state:
        - 'release_time', 'note_start', 'current_sfn', 'current_pitch'
    Returns: (chosen_channel, trunc_comment)
    """
    free_chs, stealable_chs = [], []
    for ch in range(num_channels):
        if state['current_sfn'][ch] != sfn or state['current_pitch'][ch] != sample_pitch:
            if state['release_time'][ch] <= start_ms:
                free_chs.append(ch)
            continue
        elapsed_ms = start_ms - state['note_start'][ch]
        if elapsed_ms >= min_duration_ms:
            stealable_chs.append(ch)
        elif state['release_time'][ch] <= start_ms:
            free_chs.append(ch)
    if free_chs:
        return free_chs[0], ""
    elif stealable_chs:
        oldest = min(stealable_chs, key=lambda c: state['note_start'][c])
        trunc = f" [TRUNCATE prev:ch{oldest} @{state['note_start'][oldest]:.1f}ms -> {start_ms:.1f}ms]"
        return oldest, trunc
    else:
        oldest = min(range(num_channels), key=lambda c: state['note_start'][c])
        trunc = f" [TRUNCATE prev:ch{oldest} @{state['note_start'][oldest]:.1f}ms -> {start_ms:.1f}ms]"
        return oldest, trunc

def write_note_record(f, idx, note, dt_ms, dur_ms, sample_pitch, vel_final, inst, ch, freq, lo, hi, comment):
    freq_lo, freq_hi = freq & 0xFF, (freq >> 8) & 0xFF
    f.write(
        f"    db {dt_ms & 0xFF},{(dt_ms >> 8) & 0xFF},"
        f"{dur_ms & 0xFF},{(dur_ms >> 8) & 0xFF},"
        f"{sample_pitch},{vel_final},{inst},{ch},"
        f"{freq_lo},{freq_hi},{lo},{hi}  ; n{idx} {comment}\n"
    )

def write_notes_inc(notes, control_events, sf_plan, defs, output_file, num_channels, min_duration_ms, release_ms):
    pedal_events = extract_pedal_events(control_events)
    ctrl_map     = build_controller_map(control_events)
    notes        = compute_note_deltas(notes)
    timeline     = build_unified_timeline(notes, pedal_events)
    sf_to_samples = build_sample_lookup(sf_plan)

    # Channel state
    state = {
        'release_time':  [0.0] * num_channels,
        'note_start':    [0.0] * num_channels,
        'current_sfn':   [None] * num_channels,
        'current_pitch': [None] * num_channels,
    }

    with open(output_file, 'a') as f:
        f.write("; Format of each note record:\n")
        f.write(";     tnext_lo:     equ 0     ; next-note time low byte\n")
        f.write(";     tnext_hi:     equ 1     ; next-note time high byte\n")
        f.write(";     duration_lo:  equ 2     ; duration low byte\n")
        f.write(";     duration_hi:  equ 3     ; duration high byte\n")
        f.write(";     pitch:        equ 4     ; MIDI pitch (0-127)\n")
        f.write(";     velocity:     equ 5     ; MIDI velocity (0-127)\n")
        f.write(";     instrument:   equ 6     ; instrument number (1-255)\n")
        f.write(";     channel:      equ 7     ; channel number (0-31)\n")
        f.write(";     freq_lo:      equ 8     ; frequency low byte\n")
        f.write(";     freq_hi:      equ 9     ; frequency high byte\n")
        f.write(";     buffer_id_lo: equ 10    ; buffer ID low byte\n")
        f.write(";     buffer_id_hi: equ 11    ; buffer ID high byte\n")
        f.write(";     bytes_per_note: equ 12  ; total fields per note\n\n")

        f.write(f"total_notes: equ {len(notes)}\n")
        f.write("midi_data:\n")

        note_idx = 0
        for item in timeline:
            if item['type'] == 'pedal':
                ev = item['data']
                ptype = "Sustain" if ev['type'] == 'sustain' else "Soft"
                f.write(f"; t {ev['time']:.4f} {ptype} {ev['value']} (Instr {ev['instrument']})\n")
                continue

            note = item['data']
            note_idx += 1
            dt_ms     = note['delta_ms']
            pitch     = note['pitch']
            inst      = note['instrument']
            start_ms  = note['start'] * 1000

            # Sample lookup
            sfn = defs.instnum_to_sf[inst]
            sample_info = sf_to_samples[sfn]
            sample_pitch, sample_duration = find_closest_sample(sample_info, pitch)

            # Durations
            factor = 2 ** ((sample_pitch - pitch) / 12)
            sample_max = max(1, int(sample_duration * factor))
            dur_ms = int(note['duration'] * 1000)
            dur_ms = min(dur_ms, sample_max)
            dur_ms = max(dur_ms, min_duration_ms)
            occupy_ms = dur_ms + release_ms

            freq = round(440 * 2 ** ((pitch - 69) / 12))

            cc7_list = ctrl_map[inst].get(7, [])
            volume = get_controller_value_at_time(cc7_list, note['start'], default=127)
            vel_final = volume

            # Channel selection
            ch, trunc = choose_channel(
                start_ms, sfn, sample_pitch, min_duration_ms, num_channels, state
            )

            # Update channel state
            state['release_time'][ch]  = start_ms + occupy_ms
            state['note_start'][ch]    = start_ms
            state['current_sfn'][ch]   = sfn
            state['current_pitch'][ch] = sample_pitch

            lo, hi = defs.buffer_id_bytes(sample_pitch, sfn)

            comment = f"t={note['start']:.3f}s dur={dur_ms}ms"
            if note.get('velocity_modified'):
                ov = note['original_velocity']
                nv = note['velocity']
                comment += f", vel {ov}->{nv}"
            if note.get('duration_modified'):
                od = round(note['original_duration'] * 1000)
                comment += f", sust {od}->{dur_ms}"
            comment += f", freq={freq}Hz, sample={sample_pitch}, buffer_id={hi:02X}:{lo:02X}{trunc}"

            write_note_record(
                f, note_idx, note, dt_ms, dur_ms, sample_pitch, vel_final, inst, ch, freq, lo, hi, comment
            )

        # End marker
        f.write("    db 255,255,255,255,255,255,255,255,255,255,255,255  ; End marker\n")

def assemble_app(defs, sf_plan, note_events, control_events, asm_samples_dir, inc_file, num_channels, min_duration_ms, release_ms, app_asm_file):
    """
    Writes samples.inc and notes data to inc_file, modifies app_asm_file to include the song,
    then assembles app.asm in midi/src/asm, outputs play.bin to midi/tgt, 
    and always restores the original working directory.
    """
    # Write samples data to the head of inc_file
    write_samples_inc(defs, sf_plan, asm_samples_dir, inc_file)
    
    # Append notes data to inc_file
    write_notes_inc(note_events, control_events, sf_plan, defs, inc_file, num_channels, min_duration_ms, release_ms)
    
    # Extract song name from inc_file
    song = os.path.splitext(os.path.basename(inc_file))[0]
    
    # Modify app_asm_file to include the correct song file
    with open(app_asm_file, 'r') as f:
        lines = f.readlines()
    
    # Find the line beginning with "; Song include file:" and replace the next line
    for i, line in enumerate(lines):
        if line.strip().startswith('; Song include file:'):
            if i + 1 < len(lines):
                lines[i + 1] = f'    include "../../out/{song}.inc"\n'
            break
    
    # Write the modified file back
    with open(app_asm_file, 'w') as f:
        f.writelines(lines)
    
    # Now assemble
    original_dir = os.getcwd()
    try:
        asm_dir = os.path.join("midi", "src", "asm")
        os.chdir(asm_dir)
        cmd = ["ez80asm", "app.asm", "../../tgt/play.bin"]
        subprocess.run(cmd, check=False)
    finally:
        os.chdir(original_dir)

def package_song(samples_base_dir, song, csv_file, inc_file, pub_dir, midi_in_dir):
    """
    Packages up all the files for a given song into a tar.gz archive for publishing.
    Output: <pub_dir>/<song>.tar.gz
    """
    song_dir = os.path.join(pub_dir, song)
    samples_dst_dir = os.path.join(song_dir, "Samples")
    src_dir = os.path.join(song_dir, "src")
    os.makedirs(src_dir, exist_ok=True)

    # 1. Recursively copy all files/folders from samples_base_dir to Samples/ in song_dir
    if os.path.exists(samples_dst_dir):
        shutil.rmtree(samples_dst_dir)
    shutil.copytree(samples_base_dir, samples_dst_dir)

    # 2. Copy samples_inc_file, csv_file, inc_file, scripts into src/
    files_to_copy = [
        csv_file,
        inc_file,
        os.path.join("midi", "src", "asm", "app.asm"),
        os.path.join("midi", "src", "asm", "apr.inc"),
        os.path.join("midi", "src", "asm", "timer.inc"),
        os.path.join("midi", "scripts", "midi_to_csv.py"),
        os.path.join("midi", "scripts", "csv_to_apr.py"),
    ]
    for fpath in files_to_copy:
        if os.path.isfile(fpath):
            shutil.copy2(fpath, src_dir)

    # 3. Copy midi/in/<song>.mid to <song_dir>/src/<song>.mid
    midi_path = os.path.join(midi_in_dir, f"{song}.mid")
    midi_dst = os.path.join(src_dir, f"{song}.mid")
    if os.path.isfile(midi_path):
        shutil.copy2(midi_path, midi_dst)

    # 4. Copy midi/tgt/play.bin to <song_dir>/play.bin
    midi_bin = os.path.join("midi", "tgt", "play.bin")
    play_bin = os.path.join(song_dir, "play.bin")
    if os.path.isfile(midi_bin):
        shutil.copy2(midi_bin, play_bin)

    # 5. Tar.gz the song_dir to pub_dir
    archive_path = os.path.join(pub_dir, f"{song}.tar.gz")
    with tarfile.open(archive_path, "w:gz") as tar:
        tar.add(song_dir, arcname=song)  # Top-level dir inside archive

    # 6. Clean up: remove the unarchived song_dir
    shutil.rmtree(song_dir)

    print(f"Packaged: {archive_path}")

# ------------------ RENDER TO .WAV WITH FLUIDSYNTH ------------------
def apply_release_to_notes(notes, release_ms):
    """
    For each note (start, end, pitch, velocity), extend end by release_ms.
    """
    release_s = release_ms / 1000.0
    return [
        (start, end + release_s, pitch, velocity)
        for (start, end, pitch, velocity) in notes
    ]

def render_instrument_wavs(instruments, note_events, defs, wav_dir, base_name, release_ms, sample_rate):
    """
    For each instrument in `instruments`, render its notes (with release)
    into wav_dir/base_name_<inst_num>.wav
    """
    os.makedirs(wav_dir, exist_ok=True)
    for fname in os.listdir(wav_dir):
        if fname.startswith(base_name) and fname.endswith('.wav'):
            os.remove(os.path.join(wav_dir, fname))

    for inst_num in instruments:
        # lookup soundfont params
        sfn = defs.instnum_to_sf.get(inst_num)
        if not sfn:
            continue
        params   = defs.params_for_sf(sfn)
        preset   = int(params["preset"])
        is_drum  = params["is_drum"]
        velocity = int(params["velocity"])
        name     = params.get("midi_instrument_name", f"Instr{inst_num}")

        # collect and extend notes
        raw_notes = [
            (n["start"], n["end"], n["pitch"], n["velocity"])
            for n in note_events if n["instrument"] == inst_num
        ]
        if not raw_notes:
            continue
        notes = apply_release_to_notes(raw_notes, release_ms)

        # build a single‐track PrettyMIDI
        pm = pretty_midi.PrettyMIDI(initial_tempo=120.0)
        inst = pretty_midi.Instrument(program=preset, is_drum=is_drum, name=name)
        for start, end, pitch, vel in notes:
            v = velocity if velocity is not None else vel
            inst.notes.append(pretty_midi.Note(
                velocity=v, pitch=pitch, start=start, end=end
            ))
        pm.instruments.append(inst)

        # render to WAV
        wav_path = os.path.join(wav_dir, f"{base_name}_{inst_num}.wav")
        data, sr = render_sample(params["sf2_path"], pm, sample_rate, output_gain=0.5)
        if data.ndim > 1:
            data = data.mean(axis=1)
        sf.write(wav_path, data, sr, subtype="PCM_16")
        print(f"Wrote instrument WAV: {wav_path}")

def make_wav(instruments, note_events, defs, wav_dir, base_name, release_ms, sample_rate):
    """
    1) render each instrument into its own WAV under wav_dir
    2) mix them all into wav_dir/base_name.wav with peak normalization
    """
    # Step 1: per-instrument renders
    render_instrument_wavs(instruments, note_events, defs, wav_dir, base_name, release_ms, sample_rate)

    # Step 2: collect and mix
    tracks = []
    max_len = 0
    for inst_num in instruments:
        path = os.path.join(wav_dir, f"{base_name}_{inst_num}.wav")
        if not os.path.isfile(path):
            continue
        data, sr = sf.read(path, dtype="float32")
        if sr != sample_rate:
            raise RuntimeError(f"SR mismatch: {path} is {sr}, expected {sample_rate}")
        if data.ndim > 1:
            data = data.mean(axis=1)
        tracks.append(data)
        max_len = max(max_len, len(data))

    # sum & normalize
    mix = np.zeros(max_len, dtype=np.float32)
    for t in tracks:
        mix[: len(t)] += t
    peak = np.max(np.abs(mix))
    if peak > 0:
        mix /= peak
    mix = np.clip(mix, -0.98, 0.98)  # headroom

    out_path = os.path.join(wav_dir, f"{base_name}.wav")
    sf.write(out_path, mix, sample_rate, subtype="PCM_16")
    print(f"Wrote combined mix to {out_path}")

# ------------------ MAIN ------------------
def main(do_print_instrument_summary, do_print_sample_plan, do_generate_samples, do_print_sf_plan, do_assemble_song, do_package_song, do_make_wav):

    # ---- Configuration and Metadata ----
    samples_base_dir = 'midi/tgt/Samples'
    asm_samples_dir = 'Samples'
    midi_in_dir = 'midi/in'
    midi_out_dir = 'midi/out'
    pub_dir = 'midi/tgt/pub'
    wav_dir = 'midi/wav'
    app_asm_file = 'midi/src/asm/app.asm'

    sustain_threshold = 1
    max_harmonic = 8
    min_interval = 1
    max_interval = 12
    min_sample_rate = 16000
    min_trial_duration = 500

    num_channels = 14
    min_duration_ms = 100
    release_ms = 200

    song = 'Williams__Star_Wars_Theme'

    instrument_defs = """
instrument_number,midi_instrument_name,bank,preset,is_drum,sf_instrument_name,velocity,sample_rate,sf2_path
1,Bassoon,0,70,FALSE,Bassoon,127,16000,midi/sf2/FluidR3_GM/FluidR3_GM.sf2
2,Flute,0,73,FALSE,Flute,127,16000,midi/sf2/FluidR3_GM/FluidR3_GM.sf2
3,French Horn,0,60,FALSE,French Horns,127,16000,midi/sf2/FluidR3_GM/FluidR3_GM.sf2
4,Trumpet,0,56,FALSE,Trumpet,127,16000,midi/sf2/FluidR3_GM/FluidR3_GM.sf2
5,Trombone,0,57,FALSE,Trombone,127,16000,midi/sf2/FluidR3_GM/FluidR3_GM.sf2
6,Orchestral Harp,0,46,FALSE,Harp,127,16000,midi/sf2/FluidR3_GM/FluidR3_GM.sf2
7,Bright Acoustic Piano,0,1,FALSE,Bright Yamaha Grand,127,16000,midi/sf2/FluidR3_GM/FluidR3_GM.sf2
8,String Ensemble 1,0,48,FALSE,Strings,127,16000,midi/sf2/FluidR3_GM/FluidR3_GM.sf2
9,String Ensemble 1,0,48,FALSE,Strings,127,16000,midi/sf2/FluidR3_GM/FluidR3_GM.sf2
10,Tremolo Strings,0,44,FALSE,Tremolo,127,16000,midi/sf2/FluidR3_GM/FluidR3_GM.sf2
# 11,Timpani,0,47,FALSE,Timpani,127,16000,midi/sf2/FluidR3_GM/FluidR3_GM.sf2
# 12,Drum Kit,128,0,TRUE,Standard,127,16000,midi/sf2/FluidR3_GM/FluidR3_GM.sf2
"""

    csv_file = f"{midi_out_dir}/{song}.csv"
    inc_file = f"{midi_out_dir}/{song}.inc"

    defs = InstrumentDefs(instrument_defs)

    instruments, note_events, control_events = parse_song_csv(csv_file)
    instruments, note_events, control_events = purge_undefined_instruments(defs, instruments, note_events, control_events)
    note_events = sustain_pedal_mod_durations(note_events, control_events, sustain_threshold)
    note_events_sum, control_events_sum = summarize_instruments_and_controls(note_events, control_events)

    if do_print_instrument_summary:
        print_instruments_and_controls_summary(instruments, note_events_sum, control_events_sum)

    sample_plan = compute_required_sample_rates_and_durations(note_events_sum, max_harmonic, min_interval, max_interval, defs)

    if do_print_sample_plan:
        print_sample_plan(sample_plan, instruments)

    sf_plan = aggregate_sample_plan_by_soundfont(sample_plan, defs)

    sf_plan = generate_and_save_samples(sf_plan, defs, samples_base_dir, min_sample_rate, max_harmonic, min_trial_duration, do_generate_samples)

    if do_print_sf_plan:
        print_sf_plan(sf_plan, defs)

    if do_assemble_song:
        assemble_app(defs, sf_plan, note_events, control_events, asm_samples_dir, inc_file, num_channels, min_duration_ms, release_ms, app_asm_file)

    if do_package_song:
        package_song(samples_base_dir, song, csv_file, inc_file, pub_dir, midi_in_dir)

    if do_make_wav:
        make_wav(instruments, note_events, defs, wav_dir, song, release_ms, min_sample_rate)

if __name__ == '__main__':

    do_print_instrument_summary = False
    do_print_sample_plan = False
    do_generate_samples = False
    do_print_sf_plan = False
    do_assemble_song = False
    do_package_song = False
    do_make_wav = False

    # do_print_instrument_summary = True
    # do_print_sample_plan = True
    do_generate_samples = True
    # do_print_sf_plan = True
    do_assemble_song = True
    do_package_song = True
    # do_make_wav = True

    main(do_print_instrument_summary, do_print_sample_plan, do_generate_samples, do_print_sf_plan, do_assemble_song, do_package_song, do_make_wav)
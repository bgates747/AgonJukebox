#!/usr/bin/env python3
import os
import re
import csv
import numpy as np
from io import StringIO
from scipy.signal import resample_poly, firwin, lfilter
from fluidsynth import Synth
from collections import defaultdict
import bisect
import math
import soundfile as sf
import pretty_midi
import sys
import contextlib
import tempfile
import subprocess

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
      - instrument_number <-> soundfont_name
      - soundfont_name <-> min instrument_number (buffer pool)
      - soundfont_name <-> canonical row (for params)
    """
    def __init__(self, instrument_defs):
        self.rows = list(csv.DictReader(StringIO(instrument_defs.strip())))
        self.instnum_to_sf = {}
        self.sf_to_min_instnum = {}
        self.sf_to_row = {}
        for row in self.rows:
            instr_num = int(row["instrument_number"])
            sfn = row["soundfont_name"]
            self.instnum_to_sf[instr_num] = sfn
            if sfn not in self.sf_to_min_instnum or instr_num < self.sf_to_min_instnum[sfn]:
                self.sf_to_min_instnum[sfn] = instr_num
                self.sf_to_row[sfn] = row

    def pooled_soundfonts(self):
        """Yield each unique soundfont row once (first encountered)."""
        seen = set()
        for row in self.rows:
            sfn = row["soundfont_name"]
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
def compute_required_sample_rates_and_durations(note_events_sum, max_harmonic, min_interval, max_interval):
    results = {}

    for instr, pitch_map in note_events_sum.items():
        if not pitch_map:
            results[instr] = []
            continue

        # 1) usage by count
        usage = {p: rec['count'] for p, rec in pitch_map.items()}

        # 2) primary root
        root0 = max(usage, key=usage.get)
        roots = [root0]

        # 3) upward recursion
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

        # 4) downward recursion
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

        # 5) group pitches by nearest root
        groups = {r: [] for r in roots}
        for p, rec in pitch_map.items():
            dur_ms = rec['max_dur_ms']
            closest = min(roots, key=lambda r: (abs(r - p), r))
            groups[closest].append((p, dur_ms))

        # 6) compute plan
        plan = []
        for r in roots:
            assigned = groups[r]
            if not assigned:
                continue

            # sample rate: Nyquist for highest pitch
            max_p = max(p for p, _ in assigned)
            freq  = midi_to_hz(max_p)
            req_sr = int(2 * freq * max_harmonic)

            # duration: stretch the longest
            req_dur = 0
            for p, ms in assigned:
                factor = 2 ** ((r - p) / 12.0)
                need = int(round(ms * factor))
                if need > req_dur:
                    req_dur = need

            plan.append((r, midi_to_note_name(r), req_dur, req_sr))

        results[instr] = plan

    return results

def aggregate_sample_plan_by_soundfont(sample_plan, defs):
    sf_aggregate = {}

    # initialize containers per soundfont
    for row in defs.pooled_soundfonts():
        sfn = row['soundfont_name']
        sf_aggregate[sfn] = {
            'samples': {},  # pitch -> dict of aggregated values
            'output_gain': float(row['output_gain']),
            'sample_rate': int(row['sample_rate'])
        }

    # combine per-instrument plans
    for instr, entries in sample_plan.items():
        sfn = defs.instnum_to_sf.get(instr)
        if sfn is None:
            continue
        pool = sf_aggregate[sfn]
        for pitch, note_name, dur_ms, req_sr in entries:
            rec = pool['samples'].get(pitch)
            if rec is None:
                pool['samples'][pitch] = {
                    'note_name': note_name,
                    'required_duration_ms': dur_ms,
                    'required_sample_rate': req_sr
                }
            else:
                # take maxima
                rec['required_duration_ms'] = max(rec['required_duration_ms'], dur_ms)
                rec['required_sample_rate'] = max(rec['required_sample_rate'], req_sr)
        # also update output_gain and sample_rate if higher
        params = defs.params_for_sf(sfn)
        pool['output_gain'] = max(pool['output_gain'], float(params['output_gain']))
        pool['sample_rate'] = max(pool['sample_rate'], int(params['sample_rate']))

    # convert sample dicts to sorted lists
    for sfn, data in sf_aggregate.items():
        samples = data['samples']
        # sorted by MIDI pitch
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


@contextlib.contextmanager
def suppress_stderr():
    # Flush Python-level stderr
    sys.stderr.flush()
    saved_fd = os.dup(2)
    devnull  = os.open(os.devnull, os.O_WRONLY)
    os.dup2(devnull, 2)
    try:
        yield
    finally:
        # restore stderr
        os.dup2(saved_fd, 2)
        os.close(devnull)
        os.close(saved_fd)

# def render_sample(sf2_path, midi_pm, sample_rate, output_gain):
#     # ——— Create and start the synth with no stderr noise ———
#     with suppress_stderr():
#         fs = Synth(samplerate=sample_rate)
#         fs.start()                     # warnings suppressed
#         sfid = fs.sfload(sf2_path)     # also suppress any warnings

#     # Select and play the notes
#     instr = midi_pm.instruments[0]
#     fs.program_select(0, sfid, instr.bank, instr.program)
#     for note in instr.notes:
#         fs.noteon(0, note.pitch, note.velocity)

#     # Render
#     duration_s   = max(n.end for n in instr.notes)
#     total_frames = int(round(duration_s * sample_rate))
#     raw = fs.get_samples(total_frames)

#     fs.delete()

#     # Convert to mono NumPy array
#     data = np.array(raw, dtype=np.float32)
#     if data.ndim > 1:
#         data = data.mean(axis=1)

#     # Apply gain
#     if output_gain != 1.0:
#         data *= output_gain

#     return data, sample_rate

def render_sample(sf2_path, midi_pm, sample_rate, output_gain):
    """
    Render a PrettyMIDI object via FluidSynth CLI into a float32 NumPy array.
    Returns (data_mono: np.ndarray (float32), sample_rate: int).
    """
    # 1) Dump the PrettyMIDI to a temporary .mid file
    with tempfile.NamedTemporaryFile(suffix=".mid", delete=False) as tmp_mid:
        midi_path = tmp_mid.name
        midi_pm.write(midi_path)

    # 2) Render via fluidsynth CLI into a temp WAV
    with tempfile.NamedTemporaryFile(suffix=".wav", delete=False) as tmp_wav:
        wav_path = tmp_wav.name

    try:
        cmd = [
            "fluidsynth", "-ni", sf2_path, midi_path,
            "-F", wav_path, "-r", str(sample_rate), "-g", str(output_gain),
        ]
        subprocess.run(cmd, check=True)

        # 3) Read back the WAV as float32
        data, sr = sf.read(wav_path, dtype='float32')
        if data.ndim > 1:
            data = data.mean(axis=1)

        # 4) Trim exactly to the longest note duration
        duration_s = max(n.end for inst in midi_pm.instruments for n in inst.notes)
        nsamp = int(round(duration_s * sr))
        data = data[:nsamp]

    finally:
        # Clean up the temporary MIDI and WAV files
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
    inst.notes.append(pretty_midi.Note(velocity=velocity,
                                       pitch=pitch,
                                       start=0,
                                       end=duration_s))
    pm.instruments.append(inst)
    return pm

def choose_sample_rate(freq, min_sample_rate, max_sample_rate, max_harmonic=8):
    """
    Choose an optimal sample rate for rendering a fundamental frequency.
    - Ensures at least max_harmonic are preserved, but clamps to [min, max].
    - If max_sample_rate is too low, reduces harmonics until it fits.
    - If min_sample_rate is too high, increases harmonics until it exceeds min.
    Returns: (sample_rate, harmonics_used)
    """
    # Guard against 0Hz
    freq = max(freq, 1.0)
    harmonics = max_harmonic
    sample_rate = int(2 * freq * harmonics)

    # Clamp down if above max_sample_rate by reducing harmonics
    if sample_rate > max_sample_rate:
        for h in range(harmonics, 0, -1):
            sr = int(2 * freq * h)
            if sr <= max_sample_rate:
                return sr, h
        # If even 1 harmonic exceeds max_sample_rate, just use max_sample_rate and 1
        return max_sample_rate, 1

    # Clamp up if below min_sample_rate by increasing harmonics
    if sample_rate < min_sample_rate:
        h = harmonics
        while True:
            h += 1
            sr = int(2 * freq * h)
            if sr >= min_sample_rate or h > 128:  # avoid infinite loop
                return max(sr, min_sample_rate), h
    # Already in range
    return sample_rate, harmonics

def generate_and_save_samples(sf_plan, defs, samples_base_dir, min_sample_rate, max_harmonic):
    for sfn, pool in sf_plan.items():
        params     = defs.params_for_sf(sfn)
        sf2_path   = params['sf2_path']
        bank       = int(params['bank'])
        preset     = int(params['preset'])
        velocity   = int(params['velocity'])
        native_sr  = int(params['sample_rate'])
        gain       = pool['output_gain']

        out_folder = defs.folder_for_sf(samples_base_dir, sfn)
        os.makedirs(out_folder, exist_ok=True)

        for samp in pool['samples']:
            pitch = samp['pitch']
            dur_s  = samp['required_duration_ms'] / 1000.0
            freq   = midi_to_hz(pitch)

            # clamp sample rate between min and native_sr using your helper
            req_sr, harmonics = choose_sample_rate(freq, min_sample_rate, native_sr, max_harmonic)

            # render at native rate
            pm, sr = make_single_note_pm(pitch, dur_s, velocity, preset, bank), native_sr
            wav, _ = render_sample(sf2_path, pm, sr, gain)

            # downsample+filter if needed
            if req_sr != sr:
                wav, _ = resample_audio(wav, sr, req_sr)
                cutoff = req_sr/2 - 500
                wav     = lowpass_audio(wav, req_sr, cutoff)
                wav     = normalize_audio(wav)
                sr      = req_sr

            out_path = os.path.join(out_folder, f"{pitch:03d}.wav")
            sf.write(out_path, wav, sr, subtype='PCM_U8')
            print(f"Wrote {out_path} (sr={sr}Hz, dur≈{len(wav)/sr:.3f}s, harm={harmonics})")

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
    """
    Parses the song CSV and returns three summary objects:
      instruments_sum:    dict[instr_num] = instr_name
      note_events_sum:    dict[instr_num][pitch] = {
                             'note_name': str,
                             'min_dur_ms': int,
                             'max_dur_ms': int,
                             'count':     int
                           }
      control_events_sum: dict[instr_num] = set((control_num, control_name))
    """
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

def write_samples_inc(defs, sf_plan, asm_samples_dir, samples_inc_file):
    entries = []
    filenames = []
    count = 0

    for sfn, row in defs.sf_to_row.items():
        # header
        header = (
            f"; ---- Instrument {row['instrument_number']}: {row['instrument_name']} ----\n"
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

    with open(samples_inc_file, 'w') as f:
        f.write(f"num_samples: equ {count}\n\n")
        f.write("; Format: filename pointer, frequency, bufferId\n")
        f.write("sample_dictionary:\n")
        f.write("\n".join(entries) + "\n\n")
        f.write("; Sample filename strings\n")
        f.write("sample_filenames:\n")
        f.write("\n".join(filenames) + "\n")

def convert_to_assembly(
    notes,
    control_events,
    sf_plan,
    defs,
    output_file,
    num_channels,
    min_duration_ms,
    decay_ms
):
    """
    Convert processed note events into an .inc assembly track using pooled samples.
    """
    # 1) Build pedal events
    all_pedal_events = []
    for ev in control_events:
        if ev['control_num'] == 64:
            type_ = 'sustain'
        elif ev['control_num'] == 67:
            type_ = 'soft'
        else:
            continue
        all_pedal_events.append({
            'time': ev['time'],
            'value': ev['value'],
            'type': type_,
            'instrument': ev['instrument']
        })

    # 2) Build control map for CC7
    from collections import defaultdict
    ctrl_map = defaultdict(lambda: defaultdict(list))
    for ev in control_events:
        instr = ev['instrument']
        cc    = ev['control_num']
        ctrl_map[instr][cc].append((ev['time'], ev['value']))
    for instr_dict in ctrl_map.values():
        for lst in instr_dict.values():
            lst.sort(key=lambda x: x[0])

    # 3) Sort notes and compute delta_ms
    processed = sorted(notes, key=lambda n: n['start'])
    for i in range(len(processed)-1):
        dt_s = processed[i+1]['start'] - processed[i]['start']
        processed[i]['delta_ms'] = round(dt_s * 1000)
    if processed:
        processed[-1]['delta_ms'] = 0

    # 4) Build timeline
    timeline = (
        [{'type':'note','time':n['start'],'data':n} for n in processed] +
        [{'type':'pedal','time':e['time'],'data':e} for e in all_pedal_events]
    )
    timeline.sort(key=lambda x: x['time'])

    # 5) Prepare sample lookup
    sf_to_samples = {
        sfn: [(s['pitch'], s['required_duration_ms']) for s in pool['samples']]
        for sfn, pool in sf_plan.items()
    }

    # 6) Channel tracking
    channel_release_time = [0.0] * num_channels
    channel_note_start   = [None] * num_channels

    # 7) Write .inc
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
        f.write(";   buffer_id_hi equ 11  ; buffer ID hi byte (sample pool instr#)\n")
        f.write(";   bytes_per_note equ 12\n\n")
        f.write(f"total_notes: equ {len(processed)}\n")
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
                pitch = note['pitch']
                inst  = note['instrument']
                start_s = note['start']

                # locate sample
                sfn = defs.instnum_to_sf[inst]
                sample_info = sf_to_samples[sfn]
                sample_pitch, sample_duration = find_closest_sample(sample_info, pitch)

                # duration and occupy
                factor = 2 ** ((sample_pitch - pitch) / 12)
                sample_max = max(1, int(sample_duration * factor))
                dur_ms = int(note['duration'] * 1000)
                dur_ms = min(dur_ms, sample_max)
                dur_ms = max(dur_ms, min_duration_ms)
                occupy_ms = dur_ms + decay_ms

                # frequency bytes
                freq = round(440 * 2 ** ((pitch - 69) / 12))
                freq_lo, freq_hi = freq & 0xFF, (freq >> 8) & 0xFF
                note_time_ms = start_s * 1000

                # volume via CC7
                cc7_list = ctrl_map[inst].get(7, [])
                volume = get_controller_value_at_time(cc7_list, start_s, default=127)
                vel_final = int(round((note['velocity'] * volume) / 127))

                # channel allocation
                found = None
                oldest = 0
                earliest = float('inf')
                for ch in range(num_channels):
                    rel = channel_release_time[ch]
                    if rel <= note_time_ms:
                        found = ch
                        break
                    if rel < earliest:
                        earliest = rel
                        oldest = ch
                if found is None:
                    ch = oldest
                    prev = channel_note_start[ch]
                    trunc = f" [TRUNCATE prev:ch{ch} @ {prev:.1f} ms -> {note_time_ms:.1f} ms]"
                else:
                    ch = found
                    trunc = ""

                channel_release_time[ch] = note_time_ms + occupy_ms
                channel_note_start[ch] = note_time_ms

                # buffer ID
                lo, hi = defs.buffer_id_bytes(sample_pitch, sfn)

                # comment
                comment = f"t={start_s:.3f}s dur={dur_ms}ms"
                if note.get('velocity_modified'):
                    comment += f", vel {note['original_velocity']}->{note['velocity']}"
                if note.get('duration_modified'):
                    od = round(note['original_duration'] * 1000)
                    comment += f", sust {od}->{dur_ms}"
                comment += f", freq={freq}Hz, sample={sample_pitch}, buffer_id={hi:02X}:{lo:02X}{trunc}"

                f.write(
                    f"    db {dt_ms & 0xFF},{(dt_ms >> 8) & 0xFF},"
                    f"{dur_ms & 0xFF},{(dur_ms >> 8) & 0xFF},"
                    f"{sample_pitch},{vel_final},{inst},{ch},"
                    f"{freq_lo},{freq_hi},{lo},{hi}  ; n{note_idx} {comment}\n"
                )

        f.write("    db 255,255,255,255,255,255,255,255,255,255,255,255  ; End marker\n")

# ------------------ MAIN ------------------
if __name__ == '__main__':
    # ---- Configuration and Metadata ----
    samples_base_dir = 'midi/tgt/Samples'
    asm_samples_dir = 'Samples'
    samples_inc_file = 'midi/src/asm/samples.inc'
    midi_out_dir = 'midi/out'

    # CSV→Assembly conversion
    song = 'Williams__Star_Wars_Theme'
    # song = 'Beethoven__Moonlight_Sonata_v1'
    csv_file = f"{midi_out_dir}/{song}.csv"
    inc_file = f"{midi_out_dir}/{song}.inc"
    sustain_threshold = 1 # value at which to consider the sustain pedal "on"

    # Parse notes & controls
    instruments, note_events, control_events = parse_song_csv(csv_file)

    # Only useful for songs with sustain pedal events, but can be either included or skipped as desired
    note_events = sustain_pedal_mod_durations(note_events, control_events, sustain_threshold)

    note_events_sum, control_events_sum = summarize_instruments_and_controls(note_events, control_events)

    # print_instruments_and_controls_summary(instruments, note_events_sum, control_events_sum)

    instrument_defs = """
instrument_number,instrument_name,bank,preset,soundfont_name,velocity,output_gain,sample_rate,sf2_path
1,Bassoon,0,70,Bassoon,127,1,32000,/home/smith/Agon/mystuff/assets/sound/sf2/FluidR3_GM/FluidR3_GM.sf2
2,Flute,0,73,Flute,127,1,32000,/home/smith/Agon/mystuff/assets/sound/sf2/FluidR3_GM/FluidR3_GM.sf2
3,French_Horns,0,60,French Horns,127,1,32000,/home/smith/Agon/mystuff/assets/sound/sf2/FluidR3_GM/FluidR3_GM.sf2
4,Trumpet,0,56,Trumpet,127,1,32000,/home/smith/Agon/mystuff/assets/sound/sf2/FluidR3_GM/FluidR3_GM.sf2
5,Trombone,0,57,Trombone,127,1,32000,/home/smith/Agon/mystuff/assets/sound/sf2/FluidR3_GM/FluidR3_GM.sf2
6,Orchestral Harp,0,46,Harp,127,1,32000,/home/smith/Agon/mystuff/assets/sound/sf2/FluidR3_GM/FluidR3_GM.sf2
7,Bright Acoustic Piano,0,1,Bright Yamaha Grand,127,1,32000,/home/smith/Agon/mystuff/assets/sound/sf2/FluidR3_GM/FluidR3_GM.sf2
8,String Ensemble 1,0,50,Synth Strings 1,127,1,32000,/home/smith/Agon/mystuff/assets/sound/sf2/FluidR3_GM/FluidR3_GM.sf2
9,String Ensemble 1,0,50,Synth Strings 1,127,1,32000,/home/smith/Agon/mystuff/assets/sound/sf2/FluidR3_GM/FluidR3_GM.sf2
10,Tremolo Strings,0,50,Synth Strings 1,127,1,32000,/home/smith/Agon/mystuff/assets/sound/sf2/FluidR3_GM/FluidR3_GM.sf2
11,Timpani,0,47,Timpani,127,1,32000,/home/smith/Agon/mystuff/assets/sound/sf2/FluidR3_GM/FluidR3_GM.sf2
    """

    defs = InstrumentDefs(instrument_defs)

    instruments, note_events, control_events = purge_undefined_instruments(defs, instruments, note_events, control_events)

    max_harmonic = 8
    min_interval = 12
    max_interval = 12
    sample_plan = compute_required_sample_rates_and_durations(note_events_sum, max_harmonic, min_interval, max_interval)

    # for instr, specs in sample_plan.items():
    #     name = instruments.get(instr, "<Unknown>")
    #     print(f"Instrument {instr}: {name}")
    #     for base_pitch, base_name, req_dur, req_sr in specs:
    #         print(f"  Sample {base_pitch} ({base_name}): dur={req_dur}ms, sr={req_sr}Hz")
    #     print()


    sf_plan = aggregate_sample_plan_by_soundfont(sample_plan, defs)

    # for sfn, data in sf_plan.items():
    #     # use the pool’s min instrument_number as the “Instrument” ID
    #     pool_id = defs.sf_to_min_instnum[sfn]
    #     print(f"Instrument {pool_id}: {sfn}")

    #     samples = data['samples']
    #     if samples:
    #         for samp in samples:
    #             p   = samp['pitch']
    #             nm  = samp['note_name']
    #             dur = samp['required_duration_ms']
    #             sr  = samp['required_sample_rate']
    #             print(f"  Sample {p} ({nm}): dur={dur}ms, sr={sr}Hz")
    #     else:
    #         print("  Samples: None")

    #     # echo the chosen pool-level parameters
    #     print(f"  Output Gain: {data['output_gain']}, Sample Rate: {data['sample_rate']}Hz\n")

    min_sample_rate = 16000

    generate_and_save_samples(sf_plan, defs, samples_base_dir, min_sample_rate, max_harmonic)

    write_samples_inc(defs, sf_plan, asm_samples_dir, samples_inc_file)

    convert_to_assembly(
        note_events,
        control_events,
        sf_plan,
        defs,
        inc_file,
        num_channels=32,
        min_duration_ms=1,
        decay_ms=200
    )

# from io import StringIO
# import subprocess

# def test_render_sample_for_instrument(
#     instrument_defs_line: str,
#     midi_pitch: int,
#     duration_s: float = 1.0,
#     samples_base_dir: str = 'midi/tgt/Samples'
# ):
#     """
#     Quickly render and save a single note for testing.

#     Args:
#       instrument_defs_line: One CSV row (without header) defining:
#         instrument_number,instrument_name,bank,preset,soundfont_name,velocity,output_gain,sample_rate,sf2_path
#       midi_pitch:          MIDI note number to render
#       duration_s:          Note length in seconds
#       samples_base_dir:    Base folder to save the test .wav
#     """
#     # 1) Build a minimal CSV and defs
#     header = "instrument_number,instrument_name,bank,preset,soundfont_name,velocity,output_gain,sample_rate,sf2_path"
#     csv_content = f"{header}\n{instrument_defs_line.strip()}\n"
#     defs = InstrumentDefs(csv_content)

#     # 2) Extract parameters
#     row    = defs.rows[0]
#     sfn    = row['soundfont_name']
#     bank   = int(row['bank'])
#     preset = int(row['preset'])
#     vel    = int(row['velocity'])
#     gain   = float(row['output_gain'])
#     native_sr = int(row['sample_rate'])
#     sf2_path  = row['sf2_path']

#     # 3) Build a single-note PrettyMIDI
#     pm = make_single_note_pm(
#         midi_pitch,
#         duration_s,
#         vel,
#         preset,
#         bank=bank,
#         is_drum=False
#     )

#     # 4) Render via FluidSynth
#     wav, sr = render_sample(sf2_path, pm, native_sr, gain)

#     # 5) Save to the normal samples folder
#     out_dir = defs.folder_for_sf(samples_base_dir, sfn)
#     os.makedirs(out_dir, exist_ok=True)
#     out_path = os.path.join(out_dir, f"{midi_pitch:03d}.wav")
#     sf.write(out_path, wav, sr, subtype='PCM_U8')
#     print(f"Test sample written to {out_path} (sr={sr}Hz, dur≈{len(wav)/sr:.3f}s)")

#     # 6) Play it back (requires 'aplay' or similar on your system)
#     try:
#         subprocess.run(['aplay', out_path], check=True)
#     except FileNotFoundError:
#         print("Playback skipped: 'aplay' not found. You can manually play the file.")

# instrument_defs_line = ("""
# 8,String Ensemble 1,8,80,Sine Wave,127,1,16000,/home/smith/Agon/mystuff/assets/sound/sf2/FluidR3_GM/FluidR3_GM.sf2
# """)
# midi_pitch = 31
# test_render_sample_for_instrument(instrument_defs_line, midi_pitch)

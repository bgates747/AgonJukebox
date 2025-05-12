#!/usr/bin/env python3
"""
INC → WAV Converter for ez80 Harpsichord Output
Reads an assembly .inc file with:
  • sample_filenames: mapping buffer IDs (MIDI pitches) to .wav files
  • midi_data: timed note records (dt, duration, pitch, velocity, instrument, channel)
Renders a single 8-bit PCM monaural .wav by mixing the samples per schedule.
"""

import os
import re
import numpy as np
import soundfile as sf

SAMPLE_RATE = 16384  # Hz

def parse_inc(inc_file, sample_dir):
    """
    Parses inc_file for midi_data, and builds sample_map from sample_dir.
    Returns:
      sample_map: {pitch:full_filepath}
      events: list of {start_ms, duration_ms, pitch, velocity}
    """
    import os, re

    # — build sample_map from sample_dir itself —
    sample_map = {}
    for fname in os.listdir(sample_dir):
        if not fname.lower().endswith('.wav'):
            continue
        m = re.match(r'(\d{3})\.wav$', fname)
        if m:
            pitch = int(m.group(1))
            sample_map[pitch] = os.path.join(sample_dir, fname)
    if not sample_map:
        raise RuntimeError(f"No .wav samples found in {sample_dir}")

    # — now parse midi_data from the .inc —
    events = []
    with open(inc_file, 'r') as f:
        lines = f.readlines()

    in_midi = False
    time_ms = 0
    for ln in lines:
        if ln.strip().startswith("midi_data:"):
            in_midi = True
            continue
        if not in_midi:
            continue
        text = ln.strip()
        if not text or text.startswith(";"):
            continue

        m = re.match(r'db\s+([\d, ]+)', text)
        if not m:
            continue
        vals = [int(x) for x in m.group(1).split(',')]
        if all(v == 255 for v in vals[:8]):
            break

        dt_lo, dt_hi, d_lo, d_hi, pitch, velocity, instr, channel = vals[:8]
        dt_ms  = dt_lo + (dt_hi << 8)
        dur_ms = d_lo  + (d_hi  << 8)

        events.append({
            "start_ms":    time_ms,
            "duration_ms": dur_ms,
            "pitch":       pitch,
            "velocity":    velocity
        })
        time_ms += dt_ms

    return sample_map, events


def render_events_to_buffer(events, sample_map):
    """
    Mixes all scheduled events into a single float32 buffer.
    Returns: numpy array in range [-1,1].
    """
    # determine total length
    end_times = [e["start_ms"] + e["duration_ms"] for e in events]
    total_ms = max(end_times) if end_times else 0
    total_samples = int(np.ceil(total_ms * SAMPLE_RATE / 1000))
    buffer = np.zeros(total_samples, dtype=np.float32)

    # cache samples
    sample_cache = {}

    for e in events:
        p = e["pitch"]
        velocity = e["velocity"] / 127.0
        start_idx = int(e["start_ms"] * SAMPLE_RATE / 1000)
        dur_samples = int(e["duration_ms"] * SAMPLE_RATE / 1000)

        # load sample if needed
        if p not in sample_cache:
            path = sample_map.get(p)
            if not path or not os.path.exists(path):
                raise FileNotFoundError(f"No sample for pitch {p} at {path}")
            data, sr = sf.read(path, dtype='float32')
            # resample if needed
            if sr != SAMPLE_RATE:
                raise ValueError(f"Sample {path} has rate {sr}, expected {SAMPLE_RATE}")
            sample_cache[p] = data
        sample = sample_cache[p]

        # trim or pad sample to dur_samples
        clip = sample[:dur_samples]
        if len(clip) < dur_samples:
            clip = np.pad(clip, (0, dur_samples - len(clip)))

        # mix into buffer
        end_idx = start_idx + dur_samples
        buffer[start_idx:end_idx] += clip * velocity

    # normalize to avoid clipping
    max_amp = np.max(np.abs(buffer)) or 1.0
    buffer /= max_amp

    return buffer

def inc_to_wav(inc_file, wav_file, sample_dir):
    sample_map, events = parse_inc(inc_file, sample_dir)
    print(f"Loaded {len(sample_map)} samples, {len(events)} events.")
    buf = render_events_to_buffer(events, sample_map)
    # write 8-bit PCM unsigned
    os.makedirs(os.path.dirname(wav_file), exist_ok=True)
    sf.write(wav_file, buf, SAMPLE_RATE, subtype='PCM_U8')
    print(f"Wrote {wav_file}")

if __name__ == '__main__':
    out_dir    = 'midi/out'
    instrument = 'piano'
    sample_dir=f'midi/tgt/{instrument}'
    base_name  = 'yb187qn0290-exp-tempo95'  # Sonate cis-Moll : (Mondschein). I. und II. Teil
    inc_file   = f"{out_dir}/{base_name}.inc"

    wav_dir    = 'tgt/music/Synth'
    wav_file   = f"{wav_dir}/{base_name}.wav"

    # ensure output directory exists
    os.makedirs(wav_dir, exist_ok=True)

    inc_to_wav(inc_file, wav_file, sample_dir)

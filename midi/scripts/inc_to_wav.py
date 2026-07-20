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

SAMPLE_RATE = 44100  # Hz

def parse_inc(inc_file, sample_dir):
    """
    Parses inc_file for midi_data, and builds sample_map from sample_dir.
    Returns:
      sample_map: {pitch:full_filepath}
      events: list of dicts with keys:
        start_ms, duration_ms, pitch, velocity, channel
    """
    import os, re

    # build sample_map from sample_dir
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

    # parse midi_data
    events = []
    time_ms = 0
    in_midi = False
    with open(inc_file, 'r') as f:
        for ln in f:
            txt = ln.strip()
            if txt.startswith("midi_data:"):
                in_midi = True
                continue
            if not in_midi:
                continue
            if not txt or txt.startswith(";"):
                continue
            m = re.match(r'db\s+([\d, ]+)', txt)
            if not m:
                continue
            vals = [int(x) for x in m.group(1).split(',')]
            # end marker
            if all(v == 255 for v in vals[:8]):
                break

            dt_lo, dt_hi, d_lo, d_hi, pitch, velocity, instr, channel = vals[:8]
            dt_ms  = dt_lo + (dt_hi << 8)
            dur_ms = d_lo  + (d_hi  << 8)

            events.append({
                "start_ms":    time_ms,
                "duration_ms": dur_ms,
                "pitch":       pitch,
                "velocity":    velocity,
                "channel":     channel
            })
            time_ms += dt_ms

    return sample_map, events

def render_events_to_buffer(events, sample_map, num_channels=32):
    """
    Mixes all scheduled events into per-channel buffers, restarting
    a channel whenever a new event on it begins, then sums to one buffer.
    Returns a float32 array in [-1,1].
    """
    import numpy as np
    import soundfile as sf
    import os

    # figure out total length
    end_times = [e["start_ms"] + e["duration_ms"] for e in events]
    total_ms = max(end_times) if end_times else 0
    total_samples = int(np.ceil(total_ms * SAMPLE_RATE / 1000))

    # per‐channel buffers
    chans = np.zeros((num_channels, total_samples), dtype=np.float32)

    sample_cache = {}

    for e in events:
        p = e["pitch"]
        vel = e["velocity"] / 127.0
        ch  = e["channel"]
        start = int(e["start_ms"] * SAMPLE_RATE / 1000)
        length = int(e["duration_ms"] * SAMPLE_RATE / 1000)
        end = start + length

        # load sample
        if p not in sample_cache:
            path = sample_map.get(p)
            if path is None or not os.path.exists(path):
                raise FileNotFoundError(f"No sample for pitch {p} at path {path!r}")
            data, sr = sf.read(path, dtype="float32")
            if sr != SAMPLE_RATE:
                raise ValueError(f"Sample {path} rate {sr}, expected {SAMPLE_RATE}")
            sample_cache[p] = data
        data = sample_cache[p]

        # slice or pad
        clip = data[:length]
        if clip.shape[0] < length:
            clip = np.pad(clip, (0, length-clip.shape[0]))

        # write into channel buffer, overwriting any prior content
        if 0 <= ch < num_channels:
            chans[ch, start:end] = clip * vel

    # mixdown
    mix = chans.sum(axis=0)
    # normalize
    peak = np.max(np.abs(mix)) or 1.0
    mix /= peak
    return mix

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
    wav_dir    = 'tgt/music/Synth'
    os.makedirs(wav_dir, exist_ok=True)

    instrument = 'piano'
    sample_dir=f'midi/tgt/{instrument}'
    base_name = 'Beethoven__Moonlight_Sonata_v1'
    inc_file   = f"{out_dir}/{base_name}.inc"
    wav_file   = f"{wav_dir}/{base_name}.wav"
    inc_to_wav(inc_file, wav_file, sample_dir)

    instrument = 'piano'
    sample_dir=f'midi/tgt/{instrument}'
    base_name  = 'Beethoven__Moonlight_Sonata_v2'
    inc_file   = f"{out_dir}/{base_name}.inc"
    wav_file   = f"{wav_dir}/{base_name}.wav"
    inc_to_wav(inc_file, wav_file, sample_dir)

    instrument = 'piano'
    sample_dir=f'midi/tgt/{instrument}'
    base_name  = 'Beethoven__Moonlight_Sonata_3rd_mvt'
    inc_file   = f"{out_dir}/{base_name}.inc"
    wav_file   = f"{wav_dir}/{base_name}.wav"
    inc_to_wav(inc_file, wav_file, sample_dir)

    instrument = 'piano'
    sample_dir=f'midi/tgt/{instrument}'
    base_name  = 'Beethoven__Ode_to_Joy'
    inc_file   = f"{out_dir}/{base_name}.inc"
    wav_file   = f"{wav_dir}/{base_name}.wav"
    inc_to_wav(inc_file, wav_file, sample_dir)

    instrument = 'piano'
    sample_dir=f'midi/tgt/{instrument}'
    base_name  = 'Brahms__Sonata_F_minor'
    inc_file   = f"{out_dir}/{base_name}.inc"
    wav_file   = f"{wav_dir}/{base_name}.wav"
    inc_to_wav(inc_file, wav_file, sample_dir)

    instrument = 'harpsichord'
    sample_dir=f'midi/tgt/{instrument}'
    base_name  = 'Bach__Harpsichord_Concerto_1_in_D_minor'
    inc_file   = f"{out_dir}/{base_name}.inc"
    wav_file   = f"{wav_dir}/{base_name}.wav"
    inc_to_wav(inc_file, wav_file, sample_dir)

    instrument = 'harpsichord'
    sample_dir=f'midi/tgt/{instrument}'
    base_name  = 'Thoinot__Pavana'
    inc_file   = f"{out_dir}/{base_name}.inc"
    wav_file   = f"{wav_dir}/{base_name}.wav"
    inc_to_wav(inc_file, wav_file, sample_dir)
#!/usr/bin/env python3
"""
BBC BASIC → PrettyMIDI-style CSV
--------------------------------
Parses DATA lines of form: <line#> DATA D,N0,N1,N2,N3
where D = duration in ms, Ni = BBC pitch (0 = rest).
midi = round((bbc-1)/4 + 47)
Each BBC channel → separate instrument (1-4).
Consecutive lines with the same pitch on the same channel
are merged into one longer note.
"""

import os, csv

def bbc_to_midi(bbc):
    return int(round((bbc - 1) / 4.0 + 47))

def note_name(midi):
    names = ["C","C#","D","D#","E","F","F#","G","G#","A","A#","B"]
    octave = midi // 12 - 1
    return names[midi % 12] + str(octave)

def parse_basic_lines(lines):
    """
    Return list of (duration_ms, [n0,n1,n2,n3]) from DATA lines.
    Now treats DATA‐D as centiseconds → converts to milliseconds.
    """
    import re
    recs = []
    pat = re.compile(r'^\s*\d+\s+DATA\s+(.+)$', re.I)

    for ln in lines:
        m = pat.match(ln)
        if not m:
            continue
        payload = m.group(1)
        nums = [int(tok) for tok in re.split(r'[,\s]+', payload) if tok]

        # terminator when second field == -1
        if len(nums) > 1 and nums[1] == -1:
            break

        # pad/truncate to exactly 5 values: D + 4 pitches
        nums += [0] * (5 - len(nums))
        dur_cs, *pitches = nums[:5]

        # convert centiseconds to milliseconds
        dur_ms = dur_cs * 60

        recs.append((dur_ms, pitches[:4]))

    return recs

def group_notes(records):
    """
    From records of (dur_ms, [bbc0, bbc1, bbc2, bbc3]), produce per-channel notes.
    
    Rules:
      • If all four bbc values == 0, that record “breaks” every channel:
        clear any ongoing note grouping, advance time by dur_ms, no notes added.
      • Otherwise, for each channel ch:
        – bbc > 0: convert to MIDI; if it matches last_pitch[ch] and last_end[ch]
          == current_time, extend that note; else start a new note.
        – bbc == 0: silence on that channel → break grouping for ch only.
      • After handling all channels, advance current_time by dur_ms.
    
    Returns:
      notes_per_chan: { ch: [ {instrument:ch, start_ms, end_ms, pitch}, … ] }
    """
    notes_per_chan = {ch: [] for ch in range(4)}
    last_pitch = [None] * 4    # pitch of the note currently grouped on each channel
    last_end   = [None] * 4    # end_ms of that grouped note
    current_time = 0

    for dur_ms, pitches in records:
        # 1) all-zero → break every channel, rest for dur_ms
        if all(bbc == 0 for bbc in pitches):
            last_pitch = [None] * 4
            last_end   = [None] * 4
            current_time += dur_ms
            continue

        # 2) per-channel handling
        for ch, bbc in enumerate(pitches):
            if bbc > 0:
                midi = bbc_to_midi(bbc)
                chan = notes_per_chan[ch]
                # extend if same pitch & contiguous
                if last_pitch[ch] == midi and last_end[ch] == current_time:
                    chan[-1]["end_ms"] += dur_ms
                    last_end[ch]       += dur_ms
                else:
                    # start new note
                    chan.append({
                        "instrument": ch,
                        "start_ms":   current_time,
                        "end_ms":     current_time + dur_ms,
                        "pitch":      midi
                    })
                    last_pitch[ch] = midi
                    last_end[ch]   = current_time + dur_ms
            else:
                # silence on this channel → break its grouping
                last_pitch[ch] = None
                last_end[ch]   = None

        # 3) advance time
        current_time += dur_ms

    return notes_per_chan

def write_pretty_csv(notes_per_chan, out_csv):
    with open(out_csv, "w", newline="") as f:
        w = csv.writer(f)
        note_counter = 0
        for ch in range(4):
            instr_notes = notes_per_chan[ch]
            if not instr_notes:
                continue
            w.writerow([f"# Instrument {ch+1}: Unnamed"])   # header line
            w.writerow(["Note #","Start (s)","End (s)","Duration (s)","Pitch",
                        "Note Name","Velocity","Note-on Velocity","Note-off Velocity"])
            for idx, n in enumerate(instr_notes, 1):
                start = n["start_ms"]/1000.0
                end   = n["end_ms"]/1000.0
                dur   = end - start
                pitch = n["pitch"]
                w.writerow([idx,f"{start:.4f}",f"{end:.4f}",f"{dur:.4f}",
                            pitch,note_name(pitch),127,127,0])
                note_counter += 1
            w.writerow([])  # blank line between instruments
    return note_counter

if __name__ == "__main__":
    in_dir  = 'midi/in'
    out_dir = 'midi/out'
    base    = 'STARWARSTHEME'

    basic_path = os.path.join(in_dir,  f"{base}.BAS")
    csv_path   = os.path.join(out_dir, f"{base}.csv")
    os.makedirs(out_dir, exist_ok=True)

    with open(basic_path, encoding="utf-8") as f:
        lines = f.readlines()

    records = parse_basic_lines(lines)
    notes_per_chan = group_notes(records)
    total = write_pretty_csv(notes_per_chan, csv_path)

    print(f"Wrote {total} notes across {len([n for n in notes_per_chan.values() if n])} instruments → {csv_path}")

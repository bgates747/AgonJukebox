#!/usr/bin/env python3
"""
CSV → ez80 assembly (harpsichord, dynamic channel assignment)
• No pedal processing.
• Ignores MIDI note duration; every note length = max_duration_ms.
• Dynamically assigns up to 32 Agon channels per note to avoid phase cancellation.
• Outputs 8-byte records:
    tnext_lo, tnext_hi,
    duration_lo, duration_hi,
    pitch, velocity, instrument, channel
"""

import os
import re


def read_csv_notes(csv_path):
    """
    Parse CSV (exported by midi_to_csv.py).
    Returns list of (instr_num, instr_name, notes) and
    prints min/max MIDI pitches found.
    """
    instruments = []
    current_notes = []
    instr_num = None
    instr_name = "Unknown"

    with open(csv_path, 'r') as f:
        for line in f:
            line = line.strip()
            # instrument header
            if line.startswith("# Instrument"):
                if instr_num is not None and current_notes:
                    instruments.append((instr_num, instr_name, current_notes))
                    current_notes = []
                m = re.search(r'# Instrument\s*(\d+)\s*:\s*(.+)', line)
                if m:
                    instr_num = int(m.group(1))
                    instr_name = m.group(2).strip()
                else:
                    instr_num = len(instruments) + 1
                    instr_name = "Unknown"
                continue

            # skip comments and control changes
            if not line or line.startswith("#") or not line[0].isdigit():
                continue

            # note line
            parts = line.split(',')
            if len(parts) < 7:
                continue
            start    = float(parts[1])
            pitch    = int(parts[4])
            note_name= parts[5]
            velocity = int(parts[6])
            current_notes.append({
                "start": start,
                "pitch": pitch,
                "note_name": note_name,
                "velocity": velocity,
                "instrument": instr_num
            })

    # append last instrument
    if instr_num is not None and current_notes:
        instruments.append((instr_num, instr_name, current_notes))

    # compute min/max pitch
    all_pitches = [n["pitch"] for _,_,notes in instruments for n in notes]
    if all_pitches:
        mn, mx = min(all_pitches), max(all_pitches)
        print(f"Min MIDI pitch: {mn}, Max MIDI pitch: {mx}")
    else:
        print("No notes found.")

    return instruments


def write_inc(instruments, out_path, max_duration_ms):
    """
    Write assembly with dynamic channel assignment.
    """
    # flatten and sort by start time
    all_notes = []
    for instr_num, instr_name, notes in instruments:
        all_notes.extend(notes)
    all_notes.sort(key=lambda n: n["start"])

    # compute delta_ms
    for i in range(len(all_notes)-1):
        dt = all_notes[i+1]["start"] - all_notes[i]["start"]
        all_notes[i]["delta_ms"] = max(0, round(dt * 1000))
    if all_notes:
        all_notes[-1]["delta_ms"] = 0

    # prepare channel state: remaining time & last pitch
    num_channels = 12
    chan_remain = [0] * num_channels
    chan_pitch  = [None] * num_channels

    with open(out_path, 'w') as f:
        f.write("; Harpsichord note data with dynamic channel assignment\n\n")
        f.write("; Field offsets:\n")
        f.write(";   tnext_lo    equ 0\n")
        f.write(";   tnext_hi    equ 1\n")
        f.write(";   duration_lo equ 2\n")
        f.write(";   duration_hi equ 3\n")
        f.write(";   pitch       equ 4\n")
        f.write(";   velocity    equ 5\n")
        f.write(";   instrument  equ 6\n")
        f.write(";   channel     equ 7\n\n")
        f.write(f"; Total notes: {len(all_notes)}\n\n")
        f.write("midi_data:\n")

        for idx, note in enumerate(all_notes, 1):
            dt = note["delta_ms"]
            dur = max_duration_ms

            # update channel timers by subtracting dt
            for ch in range(num_channels):
                chan_remain[ch] = max(0, chan_remain[ch] - dt)

            pitch = note["pitch"]
            vel   = note["velocity"]
            inst  = note["instrument"]

            # 1) reuse channel that last played this pitch
            chosen = None
            for ch in range(num_channels):
                if chan_pitch[ch] == pitch:
                    chosen = ch
                    break

            # 2) else find first free channel
            if chosen is None:
                for ch in range(num_channels):
                    if chan_remain[ch] == 0:
                        chosen = ch
                        break

            # 3) else steal the channel with smallest remaining time (oldest note)
            if chosen is None:
                chosen = min(range(num_channels), key=lambda ch: chan_remain[ch])

            # assign this note to chosen channel
            chan_pitch[chosen] = pitch
            chan_remain[chosen] = dur

            # write record
            f.write(
                f"    db {dt&0xFF},{dt>>8&0xFF},"
                f"{dur&0xFF},{dur>>8&0xFF},"
                f"{pitch},{vel},{inst},{chosen} "
                f"; n{idx} t={note['start']:.3f} {note['note_name']}\n"
            )

        # end marker: 8 bytes of 255
        f.write("    db 255,255,255,255,255,255,255,255  ; end\n")


if __name__ == '__main__':
    CSV_DIR   = "midi/out"
    MAX_DUR   = 1000   # ms per note

    BASE_NAME = "Bach__Harpsichord_Concerto_1_in_D_minor"
    BASE_NAME = 'Thoinot__Pavana'

    csv_path = os.path.join(CSV_DIR, BASE_NAME + ".csv")
    inc_path = os.path.join(CSV_DIR, BASE_NAME + ".inc")

    if not os.path.exists(csv_path):
        raise FileNotFoundError(csv_path)

    instruments = read_csv_notes(csv_path)
    write_inc(instruments, inc_path, MAX_DUR)

    print("Wrote", inc_path)
    print("Instruments:", len(instruments))
    total_notes = sum(len(n) for _,_,n in instruments)
    print("Notes     :", total_notes)
    used_pitches = sorted({n["pitch"] for _,_,notes in instruments for n in notes})
    print(f"Pitches   : {len(used_pitches)} ({used_pitches[0]}–{used_pitches[-1]})")

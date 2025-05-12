#!/usr/bin/env python3
"""
CSV → ez80 assembly (harpsichord version)
• No pedal processing (harpsichords have none).
• Ignores MIDI note duration; every note length = max_duration.
• Outputs 7-byte records: delta_lo, delta_hi, duration_lo, duration_hi,
  pitch, velocity, instrument.
"""

import os
import re
from collections import defaultdict


# ------------------------------------------------------------------ #
#  CSV reader  (notes only, no pedals)
# ------------------------------------------------------------------ #
def read_csv_notes(csv_path):
    """
    Parse CSV exported by midi_to_csv.py.
    Returns: list of (instr_num, instr_name, notes) tuples.
    Each note: dict with start, pitch, velocity, etc.
    """
    instruments = []
    current = None
    notes = []
    instr_no = 0
    instr_name = "Unknown"

    with open(csv_path) as f:
        for ln in f:
            line = ln.strip()
            if line.startswith("# Instrument"):
                # flush previous instrument
                if current is not None and notes:
                    instruments.append((instr_no, instr_name, notes))
                    notes = []
                # extract number / name
                num = re.search(r"\d+", line)
                instr_no = int(num.group()) if num else len(instruments) + 1
                instr_name = line.split(":", 1)[1].strip() if ":" in line else "Unknown"
                current = instr_no
                continue

            # skip headers / empty / control-change sections
            if not line or line.startswith("#") or not line[0].isdigit():
                continue

            # note data line
            fields = line.split(",")
            if len(fields) < 7:
                continue
            note_num   = int(fields[0])
            start      = float(fields[1])
            pitch      = int(fields[4])
            note_name  = fields[5]
            velocity   = int(fields[6])

            notes.append({
                "note_num": note_num,
                "start": start,
                "pitch": pitch,
                "note_name": note_name,
                "velocity": velocity,
                "instrument": instr_no
            })

    if current is not None and notes:
        instruments.append((instr_no, instr_name, notes))

    return instruments


# ------------------------------------------------------------------ #
#  Assembly writer
# ------------------------------------------------------------------ #
def write_inc(instruments, out_path, max_duration_ms):
    # flatten + sort by start
    all_notes = []
    for instr_no, name, notes in instruments:
        for n in notes:
            all_notes.append(n)
    all_notes.sort(key=lambda n: n["start"])

    # delta to next note
    for i in range(len(all_notes) - 1):
        dt = all_notes[i + 1]["start"] - all_notes[i]["start"]
        all_notes[i]["delta_ms"] = max(0, round(dt * 1000))
    if all_notes:
        all_notes[-1]["delta_ms"] = 0

    with open(out_path, "w") as f:
        f.write("; Harpsichord note data (7-byte records)\n\n")
        f.write("; field offsets:\n")
        f.write(";   tnext_lo     equ 0\n")
        f.write(";   tnext_hi     equ 1\n")
        f.write(";   duration_lo  equ 2\n")
        f.write(";   duration_hi  equ 3\n")
        f.write(";   pitch        equ 4\n")
        f.write(";   velocity     equ 5\n")
        f.write(";   instrument   equ 6\n\n")
        f.write(f"; Total notes: {len(all_notes)}\n\n")
        f.write("midi_data:\n")

        for idx, n in enumerate(all_notes, 1):
            dt = n["delta_ms"]
            dur = max_duration_ms  # force constant length
            f.write(
                f"    db {dt & 0xFF},{dt>>8 & 0xFF},"
                f"{dur & 0xFF},{dur>>8 & 0xFF},"
                f"{n['pitch']},{n['velocity']},{n['instrument']} "
                f"; n{idx} t={n['start']:.3f} {n['note_name']}\n"
            )

        f.write("    db 255,255,255,255,255,255,255  ; end\n")


# ------------------------------------------------------------------ #
#  CLI / parameter block
# ------------------------------------------------------------------ #
if __name__ == "__main__":
    CSV_DIR   = "midi/out"
    BASE_NAME = "Bach__Harpsichord_Concerto_1_in_D_minor"
    MAX_DUR   = 1000             # ms for every note

    csv_path = f"{CSV_DIR}/{BASE_NAME}.csv"
    inc_path = f"{CSV_DIR}/{BASE_NAME}.inc"

    if not os.path.exists(csv_path):
        raise FileNotFoundError(csv_path)

    instruments = read_csv_notes(csv_path)
    write_inc(instruments, inc_path, MAX_DUR)

    print("Wrote", inc_path)
    print("   Instruments:", len(instruments))
    print("   Notes      :", sum(len(n) for _, _, n in instruments))

import re

def summarize_song_csv(csv_path):
    with open(csv_path, 'r') as f:
        lines = f.readlines()

    idx = 0
    N = len(lines)
    instrument_blocks = []

    while idx < N:
        line = lines[idx].strip()
        # Find instrument header
        if line.startswith("# Instrument"):
            m = re.match(r"# Instrument (\d+):\s*(.*)", line)
            instr_num = int(m.group(1))
            instr_name = m.group(2).strip()
            # Find note CSV header
            idx += 1
            while idx < N and not lines[idx].startswith("Note #"):
                idx += 1
            if idx >= N:
                break
            note_header = [h.strip() for h in lines[idx].strip().split(",")]
            # Read note rows
            note_rows = []
            idx += 1
            while idx < N and lines[idx].strip() and not lines[idx].startswith("#"):
                fields = lines[idx].strip().split(",")
                if len(fields) == len(note_header):
                    note_rows.append(dict(zip(note_header, fields)))
                idx += 1
            instrument_blocks.append({
                'number': instr_num,
                'name': instr_name,
                'notes': note_rows,
            })
        else:
            idx += 1

    print("\n====== Instrument Usage Summary ======\n")

    for block in instrument_blocks:
        notes = block['notes']
        if not notes:
            continue

        # Extract and cast relevant fields
        durations = [float(n['Duration (s)']) for n in notes]
        starts    = [float(n['Start (s)']) for n in notes]
        ends      = [float(n['End (s)']) for n in notes]
        pitches   = [int(n['Pitch']) for n in notes]
        note_names = [n['Note Name'] for n in notes]

        min_duration = min(durations)
        max_duration = max(durations)
        avg_duration = sum(durations) / len(durations)
        min_pitch = min(pitches)
        max_pitch = max(pitches)
        num_notes = len(notes)
        min_pitch_name = note_names[pitches.index(min_pitch)]
        max_pitch_name = note_names[pitches.index(max_pitch)]

        # Time between *start* times, ignoring 0s
        starts_sorted = sorted(starts)
        gaps = [s2 - s1 for s1, s2 in zip(starts_sorted, starts_sorted[1:]) if (s2 - s1) > 0]
        min_gap = min(gaps) if gaps else 0

        # Polyphony: sweep line to count overlapping notes
        time_points = []
        for s, e in zip(starts, ends):
            time_points.append((s, +1))
            time_points.append((e, -1))
        time_points.sort()
        curr_poly = 0
        max_poly = 0
        for t, delta in time_points:
            curr_poly += delta
            if curr_poly > max_poly:
                max_poly = curr_poly

        print(f"Instrument {block['number']}: {block['name']}")
        print(f"  Notes: {num_notes}")
        print(f"  Duration (s): min={min_duration:.4f}  max={max_duration:.4f}  avg={avg_duration:.4f}")
        print(f"  Pitch: min={min_pitch} ({min_pitch_name}), max={max_pitch} ({max_pitch_name})")
        print(f"  Minimum time between notes: {min_gap:.4f} s")
        print(f"  Max notes sounding simultaneously: {max_poly}\n")

    print("\n====== Instrument Definitions CSV ======\n")
    print("instrument_number,instrument_name")
    for block in instrument_blocks:
        print(f'{block["number"]},"{block["name"]}"')


if __name__ == "__main__":
    midi_out_dir = 'midi/out'
    song_base_name = 'Williams__Raiders_of_the_Lost_Ark'
    csv_path = f"{midi_out_dir}/{song_base_name}.csv"
    summarize_song_csv(csv_path)

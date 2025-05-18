#!/usr/bin/env python3
"""
MIDI Processing Pipeline - Converts MIDI to CSV and then to ez80 assembly
Specifically designed for piano roll files from Stanford's collection
Includes tempo adjustment feature for playback speed correction
"""

import os
import csv
import pretty_midi

def extract_bank_and_preset(instrument):
    """
    Extracts bank and preset from control changes and program number.
    Bank = (CC#0 << 7) | CC#32
    """
    msb = 0
    lsb = 0
    for cc in instrument.control_changes:
        if cc.number == 0:
            msb = cc.value
        elif cc.number == 32:
            lsb = cc.value
    bank = (msb << 7) | lsb
    preset = instrument.program
    return bank, preset

def get_drum_kit_bank_and_preset(instrument):
    """
    Returns (bank, preset, name) for drum instruments.
    Defaults to (128, 0, 'Standard') unless a program/bank change is found.
    """
    # Look for a program/bank change event among control_changes (rare)
    # Note: PrettyMIDI stores only program number at instrument.program, and control_changes as a list of CC events.
    bank = 128
    preset = 0
    prog_name = "Standard"

    # Attempt to extract program/bank change events from control_changes
    # Not all MIDI libraries store this; in PrettyMIDI, program change is at instrument.program, but almost always 0 for drums.
    # However, let's check for any anomalies anyway:
    if hasattr(instrument, 'program'):
        # Some rare MIDI files do set program/preset for drums
        if getattr(instrument, "program", 0) != 0:
            preset = instrument.program
            # Name is ambiguous for drum kits except Standard, but FluidR3_GM.sf2 uses generic names
            # You might have a mapping here, but fallback is just to use preset number.
            prog_name = f"Drum Kit Preset {preset}"
    # You could also try to parse control_changes for bank select (CC #0, CC #32), but this is *extremely* rare for drums.
    return bank, preset, prog_name

def midi_to_csv(midi_file, csv_file, tempo_factor, volume_multiplier):
    """
    MIDI → CSV pipeline with robust drum handling:
      - For is_drum instruments, defaults to Bank 128, Preset 0 ("Standard"), unless overridden by a program change.
    """
    try:
        midi_data = pretty_midi.PrettyMIDI(midi_file)

        with open(csv_file, 'w', newline='') as csv_fh:
            writer = csv.writer(csv_fh)

            # --- File metadata ---
            writer.writerow(['# MIDI File Information'])
            writer.writerow(['Filename', os.path.basename(midi_file)])
            writer.writerow(['Duration (seconds)', f"{midi_data.get_end_time() / tempo_factor:.2f}"])
            writer.writerow(['Tempo Adjustment Factor', f"{tempo_factor:.2f}"])
            writer.writerow(['Resolution (ticks/beat)', midi_data.resolution])

            # --- Tempo changes ---
            times, tempos = midi_data.get_tempo_changes()
            writer.writerow([])
            writer.writerow(['# Tempo Changes'])
            writer.writerow(['Time (s)', 'Tempo (BPM)'])
            for t, bpm in zip(times, tempos):
                writer.writerow([f"{t / tempo_factor:.4f}", f"{bpm:.2f}"])

            # --- Time signature changes ---
            if midi_data.time_signature_changes:
                writer.writerow([])
                writer.writerow(['# Time Signature Changes'])
                writer.writerow(['Time (s)', 'Numerator', 'Denominator'])
                for ts in midi_data.time_signature_changes:
                    writer.writerow([
                        f"{ts.time / tempo_factor:.4f}",
                        ts.numerator,
                        ts.denominator
                    ])

            # --- Key signature changes (key number only) ---
            if midi_data.key_signature_changes:
                writer.writerow([])
                writer.writerow(['# Key Signature Changes'])
                writer.writerow(['Time (s)', 'Key Number'])
                for ks in midi_data.key_signature_changes:
                    writer.writerow([
                        f"{ks.time / tempo_factor:.4f}",
                        ks.key_number
                    ])

            # --- Instrument sections (minimal header) ---
            for idx, instrument in enumerate(midi_data.instruments, start=1):
                # Name logic: prefer .name, then program name, then Drum Kit
                if instrument.name:
                    inst_name = instrument.name
                elif instrument.is_drum:
                    inst_name = "Drum Kit"
                else:
                    inst_name = pretty_midi.program_to_instrument_name(instrument.program)
                
                if instrument.is_drum:
                    # For drums: default to 128/0 unless overridden
                    bank, preset, prog_name = get_drum_kit_bank_and_preset(instrument)
                else:
                    bank, preset = extract_bank_and_preset(instrument)
                    prog = instrument.program
                    prog_name = pretty_midi.program_to_instrument_name(prog)

                is_drum = instrument.is_drum

                writer.writerow([])
                writer.writerow([f"# Instrument {idx}: {inst_name}"])
                writer.writerow(['Bank', 'Program', 'Program Name', 'Is Drum'])
                writer.writerow([bank, preset, prog_name, str(is_drum)])

                # --- Notes ---
                writer.writerow([
                    'Note #', 'Start (s)', 'End (s)', 'Duration (s)',
                    'Pitch', 'Note Name', 'Velocity',
                    'Original Velocity', 'Note-off Velocity'
                ])
                sorted_notes = sorted(instrument.notes, key=lambda n: n.start)
                for j, note in enumerate(sorted_notes, start=1):
                    name = pretty_midi.note_number_to_name(note.pitch)
                    start = note.start / tempo_factor
                    end = note.end / tempo_factor
                    dur = (note.end - note.start) / tempo_factor
                    on_vel = max(1, min(127, int(round(note.velocity * volume_multiplier))))
                    writer.writerow([
                        j,
                        f"{start:.4f}",
                        f"{end:.4f}",
                        f"{dur:.4f}",
                        note.pitch,
                        name,
                        on_vel,
                        note.velocity,
                        0
                    ])

                # --- Control Changes (unchanged) ---
                if instrument.control_changes:
                    writer.writerow([])
                    writer.writerow([f"# Control Changes for Instrument {idx}"])
                    writer.writerow(['Time (s)', 'Control Number', 'Control Name', 'Value'])
                    for cc in sorted(instrument.control_changes, key=lambda c: c.time):
                        t = cc.time / tempo_factor
                        name = {
                            1: 'Modulation',
                            7: 'Volume',
                            10: 'Pan',
                            64: 'Sustain Pedal',
                            91: 'Reverb',
                            93: 'Chorus'
                        }.get(cc.number, f"Control {cc.number}")
                        writer.writerow([f"{t:.4f}", cc.number, name, cc.value])

            # --- Summary section ---
            writer.writerow([])
            writer.writerow(['# Summary'])
            writer.writerow(['Total Instruments', len(midi_data.instruments)])
            total_notes = sum(len(inst.notes) for inst in midi_data.instruments)
            writer.writerow(['Total Notes', total_notes])

        print("MIDI processing complete!")
        print(f"  MIDI file:     {midi_file}")
        print(f"  CSV file:      {csv_file}")
        print(f"  Tempo factor:  {tempo_factor:.2f}")
        print(f"  Orig duration: {midi_data.get_end_time():.2f} s")
        print(f"  Adj duration:  {midi_data.get_end_time() / tempo_factor:.2f} s")
        print(f"  Total notes:   {total_notes}")

    except Exception as e:
        print(f"Error processing {midi_file}: {e}")
        return False

    return True

if __name__ == '__main__':
    # Define directories
    in_dir = 'midi/in'
    out_dir = 'midi/out'
    
    base_name = 'Beethoven__Moonlight_Sonata_v1'
    base_name = 'Beethoven__Moonlight_Sonata_v2'
    base_name = 'Beethoven__Moonlight_Sonata_3rd_mvt'
    base_name = 'Beethoven__Ode_to_Joy'
    base_name = 'Brahms__Sonata_F_minor'
    base_name = 'Williams__Star_Wars_Theme'
    # base_name = 'Over_the_Rainbow'
    # base_name = 'Williams__Raiders_of_the_Lost_Ark'

    # base_name = 'Bach__Harpsichord_Concerto_1_in_D_minor'
    # base_name = 'Thoinot__Pavana'

    # Build file paths
    midi_file = f"{in_dir}/{base_name}.mid"
    csv_file = f"{out_dir}/{base_name}.csv"
    
    # Set tempo adjustment factor:
    # 1.0 = original tempo
    # 1.5 = 50% faster
    # 2.0 = twice as fast
    # 0.5 = half speed

    tempo_factor = 1.0
    volume_multiplier = 1.0
    
    # Process the MIDI file
    midi_to_csv(midi_file, csv_file, tempo_factor, volume_multiplier)

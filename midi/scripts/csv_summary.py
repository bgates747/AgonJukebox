import os
import re
from sf2utils.sf2parse import Sf2File

def extract_sf2_preset_map(sf2_path):
    with open(sf2_path, "rb") as f:
        sf2 = Sf2File(f)
        presets = [
            p for p in sf2.presets
            if getattr(p, "name", "") != "EOP"
        ]
        return {
            (p.bank, p.preset): p.name
            for p in presets
        }

def parse_instruments_from_csv(csv_path):
    """
    Parses the new minimalist instrument blocks:
    # Instrument 1: Bassoon
    Bank,Program,Program Name,Is Drum
    0,70,Bassoon,False
    """
    with open(csv_path, "r") as f:
        lines = f.readlines()

    instruments = []
    idx = 0
    N = len(lines)

    while idx < N:
        line = lines[idx].strip()
        if line.startswith("# Instrument"):
            m = re.match(r"# Instrument (\d+):\s*(.*)", line)
            instr_num = int(m.group(1))
            instr_name = m.group(2).strip()

            # Expect the next line to be the header, and then the values
            idx += 1
            while idx < N and not lines[idx].strip().startswith("Bank,Program,Program Name,Is Drum"):
                idx += 1
            if idx < N:
                idx += 1  # move to value row
                if idx < N:
                    parts = [x.strip() for x in lines[idx].strip().split(",")]
                    if len(parts) >= 4:
                        try:
                            bank = int(parts[0])
                            preset = int(parts[1])
                            # program_name = parts[2]  # can be included if needed
                            is_drum = parts[3].strip().lower() == "true"
                        except Exception:
                            bank = 0
                            preset = 0
                            is_drum = False
                    else:
                        bank = 0
                        preset = 0
                        is_drum = False
                else:
                    bank = 0
                    preset = 0
                    is_drum = False
            else:
                bank = 0
                preset = 0
                is_drum = False

            instruments.append({
                'number': instr_num,
                'name': instr_name,
                'bank': bank,
                'preset': preset,
                'is_drum': is_drum,
            })
        idx += 1
    return instruments

def summarize_song_csv(csv_path, sf2_path):
    preset_map = extract_sf2_preset_map(sf2_path)
    instruments = parse_instruments_from_csv(csv_path)

    print("\n====== Instrument Definitions CSV ======\n")
    print("instrument_number,midi_instrument_name,bank,preset,is_drum,sf_instrument_name")
    for inst in instruments:
        key = (inst['bank'], inst['preset'])
        sf_inst_name = preset_map.get(key, "Not Found")
        print(f'{inst["number"]},"{inst["name"]}",{inst["bank"]},{inst["preset"]},{inst["is_drum"]},{sf_inst_name}')

if __name__ == "__main__":
    midi_out_dir   = 'midi/out'
    song_base_name = 'Valkyries'
    csv_path       = f"{midi_out_dir}/{song_base_name}.csv"
    # sf2_path       = 'midi/sf2/FluidR3_GM/FluidR3_GM.sf2'
    sf2_path       = 'midi/sf2/GeneralUser-GS/GeneralUser-GS.sf2'
    summarize_song_csv(csv_path, sf2_path)

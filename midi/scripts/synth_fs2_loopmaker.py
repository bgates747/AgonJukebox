import os
import re
import numpy as np
import soundfile as sf
from sf2utils.sf2parse import Sf2File

def extract_matching_zones(txt_path, key, velocity):
    matches, block = [], []
    capturing = applies = False

    with open(txt_path) as f:
        for raw in f:
            line = raw.rstrip()
            if line.startswith("Bag #") or line.startswith("Preset["):
                if capturing and applies:
                    matches.append('\n'.join(block))
                block, capturing, applies = [line], True, False
                continue

            if capturing:
                block.append(line)
                m = re.search(r'keys:\s*\[?(\d+),\s*(\d+)\]?', line)
                if m and int(m.group(1)) <= key <= int(m.group(2)):
                    applies = True
                m = re.search(r'velocity range\s*\[?(\d+),\s*(\d+)\]?', line)
                if m and int(m.group(1)) <= velocity <= int(m.group(2)):
                    applies = True

        if capturing and applies:
            matches.append('\n'.join(block))
    return matches

def build_sample_map(txt_path, key, velocity):
    """
    Returns a dict { sample_idx: override_root_key_or_None } for all
    samples that apply to this key/velocity.
    """
    zones = extract_matching_zones(txt_path, key, velocity)
    smap = {}
    for block in zones:
        # find sample index
        m = re.search(r'sample #(\d+)', block)
        if not m:
            continue
        idx = int(m.group(1))

        # look for a root-key override in this block
        rk = None
        for L in block.splitlines():
            m2 = re.search(r'(?:MIDI )?root key override\s*(\d+)', L, re.IGNORECASE)
            if m2:
                rk = int(m2.group(1))
                break

        # record override only if not seen before
        if idx not in smap:
            smap[idx] = rk
    return smap

def extract_and_save_samples(sf2_path, sample_map, output_dir):
    """
    sample_map: { sample_idx: override_root_key_or_None }
    """
    os.makedirs(output_dir, exist_ok=True)
    sf2_file = open(sf2_path, "rb")
    sf2 = Sf2File(sf2_file)

    for idx, override_key in sample_map.items():
        s = sf2.samples[idx]

        # decode raw bytes → float32
        raw = s.raw_sample_data
        if s.sample_width == 2:
            arr = np.frombuffer(raw, dtype="<i2")
            audio = arr.astype(np.float32) / 32768.0
            subtype = "PCM_16"
        else:
            arr = np.frombuffer(raw, dtype=np.uint8)
            audio = (arr.astype(np.float32) - 128.0) / 128.0
            subtype = "PCM_U8"
        sr = s.sample_rate

        print(f"--- Sample #{idx} ---")
        # 1) write full sample
        full_path = os.path.join(output_dir, f"{idx}.wav")
        sf.write(full_path, audio, sr, subtype=subtype)
        print(f" • Wrote full → {idx}.wav")

        # 2) loop portion
        if s.start_loop < s.end_loop:
            loop = audio[s.start_loop:s.end_loop]
            # normalize
            pk = np.max(np.abs(loop))
            if pk>0: loop /= pk

            # choose root key: override > metadata
            midi = override_key if override_key is not None else s.original_pitch

            loop_name = f"{midi}_{idx}.wav"
            loop_path = os.path.join(output_dir, loop_name)
            sf.write(loop_path, loop, sr, subtype=subtype)
            print(f" • Wrote loop → {loop_name}")
        else:
            print(" ⚠ No loop defined")

    sf2_file.close()

if __name__ == "__main__":
    sf2_path   = "/home/smith/Agon/mystuff/assets/sound/sf2/FluidR3_GM/FluidR3_GM.sf2"
    txt_path   = "midi/sf2/FluidR3_GM.txt"
    out_dir    = "midi/sf2/samples"
    key, vel   = 69, 64

    # Build map of sample→root
    sample_map = build_sample_map(txt_path, key, vel)
    print("Will extract samples:", sample_map)

    # Extract & save
    extract_and_save_samples(sf2_path, sample_map, out_dir)

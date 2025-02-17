#!/usr/bin/env python3
import sys
import os
import re
import shutil
import numpy as np
from PIL import Image

import agonutils as au

NO_DIFF_COLOR = 0xF3  # Pure magenta in our RGBA2222 format (11110011)

def parse_frame_index(filename):
    """
    Given a filename like 'frame_00010.png', return the integer 10.
    Assumes there's a recognizable pattern in the name: 'frame_(digits).png'.
    """
    m = re.search(r'frame_(\d+)', filename.lower())
    if not m:
        raise ValueError(f"Cannot parse frame index from '{filename}'")
    return int(m.group(1))

def reuse_dithering_with_lookback(
    oldNo:      bytes, 
    newNo:      bytes,
    oldDither:  bytes,
    newDither:  bytes,
    unchanged_count: np.ndarray,
    T: int
) -> bytes:
    """
    Extended version of 'reuse dithering' that includes a "lookback" threshold T:
      - If oldNo[i] == newNo[i], we increment unchanged_count[i].
      - Otherwise, we reset unchanged_count[i] to 0.

      Then, if unchanged_count[i] < T, do normal reuse:
         final[i] = (unchanged? oldDither[i] : newDither[i])
      Else (unchanged_count[i] >= T), we force adopting newDither[i].

    All four input arrays are 8-bit palette data (same length).
    'unchanged_count' is an integer array tracking consecutive unchanged frames.
    Returns the final dithered frame as a 'bytes' object of length len(oldNo).
    """
    size = len(oldNo)
    assert len(newNo) == size
    assert len(oldDither) == size
    assert len(newDither) == size
    assert unchanged_count.shape[0] == size

    # Convert the byte arrays to NumPy uint8 arrays (views).
    arr_oldNo    = np.frombuffer(oldNo,    dtype=np.uint8)
    arr_newNo    = np.frombuffer(newNo,    dtype=np.uint8)
    arr_oldDith  = np.frombuffer(oldDither,dtype=np.uint8)
    arr_newDith  = np.frombuffer(newDither,dtype=np.uint8)

    final_arr = np.empty(size, dtype=np.uint8)

    # 1) Check which pixels are 'unchanged' in no-dither sense
    same_mask = (arr_oldNo == arr_newNo)

    # 2) Update unchanged_count
    unchanged_count[same_mask] += 1
    unchanged_count[~same_mask] = 0

    # 3) Reuse dithering logic with a forced refresh after T consecutive frames
    #    (a) Start final_arr as a copy of oldDith
    final_arr[:] = arr_oldDith

    #    (b) For those pixels that have reached T => forcibly adopt newDither
    force_mask = (unchanged_count >= T)
    final_arr[force_mask] = arr_newDith[force_mask]

    #    (c) For pixels below T but changed => newDither
    changed_mask = (unchanged_count < T) & (~same_mask)
    final_arr[changed_mask] = arr_newDith[changed_mask]

    return final_arr.tobytes()

def compute_frame_difference(oldFinal: bytes, newFinal: bytes) -> bytes:
    """
    8-bit difference: if the pixel is unchanged (oldFinal[i] == newFinal[i]),
    encode that pixel as the reserved "no difference" color (pure magenta, 0xF3).
    Otherwise, use the new pixel value.
    """
    assert len(oldFinal) == len(newFinal)
    size = len(oldFinal)
    diff = bytearray(size)
    for i in range(size):
        diff[i] = NO_DIFF_COLOR if (oldFinal[i] == newFinal[i]) else newFinal[i]
    return bytes(diff)

def dither_diff_test(
    start_png      = '/home/smith/Agon/mystuff/assets/video/frames/frame_00010.png',
    end_png        = '/home/smith/Agon/mystuff/assets/video/frames/frame_00020.png',
    working_dir    = '/home/smith/Agon/mystuff/assets/video/working',
    diff_dir       = '/home/smith/Agon/mystuff/assets/video/diffs',
    noDitherMethod = 'bayer',   # e.g. "bayer" or "RGB"
    dither_method  = 'floyd',   # e.g. "floyd", "bayer", etc.
    T              = 5          # # consecutive frames before forcing new dither
):
    """
    Reads frames from the directory containing start_png and end_png, 
    from start index to end index inclusive. For each .png:
      - Convert to 8-bit "no-dither" => noDither.rgba2 (using noDitherMethod)
      - Convert to user-specified dithering => dithered.rgba2
      - Reuse dithering with T-frame lookback => finalDither
      - Compute difference vs. old final => difference array, where unchanged pixels
        are encoded as pure magenta (NO_DIFF_COLOR).
      - Convert the difference array to a .png in diff_dir.
    """

    os.makedirs(working_dir, exist_ok=True)
    os.makedirs(diff_dir, exist_ok=True)

    # Clear diff_dir of old files so we don't mix old & new runs
    for filename in os.listdir(diff_dir):
        path = os.path.join(diff_dir, filename)
        if os.path.isfile(path):
            os.remove(path)

    # 1) Determine directory & numeric range
    src_dir = os.path.dirname(start_png) or "."
    start_idx = parse_frame_index(os.path.basename(start_png))
    end_idx   = parse_frame_index(os.path.basename(end_png))
    if start_idx > end_idx:
        start_idx, end_idx = end_idx, start_idx  # swap

    # 2) Gather only original .png frames in [start_idx .. end_idx]
    #    ignoring anything with "_nodither", "_dithered", or "_diff"
    png_files = [
        f for f in os.listdir(src_dir)
        if f.lower().endswith(".png")
        and ("_nodither" not in f.lower())
        and ("_dithered" not in f.lower())
        and ("_diff" not in f.lower())
    ]

    indexed = []
    for f in png_files:
        try:
            n = parse_frame_index(f)
            if start_idx <= n <= end_idx:
                indexed.append((n, f))
        except ValueError:
            pass
    indexed.sort(key=lambda x: x[0])  # sort by frame index

    if not indexed:
        print("No .png files found in the given range!")
        return

    print(f"Found {len(indexed)} frames from {start_idx} to {end_idx} in: {src_dir}")

    # We'll store oldNoDither, oldFinalDither as bytearrays (once we know the size).
    oldNo    = None
    oldFinal = None
    unchanged_count = None  # will be a NumPy array

    # Helper: read a .png => produce "noDither" & "dithered" arrays
    def get_no_and_dither_arrays(pngpath, paletteFile, noDitherMethod, ditherMethod):
        """
        Returns (noDither, dithered) as bytes of length (width*height).
        We do:
          - Copy => noDither.png => palette(noDitherMethod) => noDither.rgba2 => read
          - Copy => dithered.png => palette(ditherMethod)   => dithered.rgba2 => read
        Store them in `working_dir`.
        """
        base = os.path.splitext(os.path.basename(pngpath))[0]

        no_png     = os.path.join(working_dir, f"{base}_nodither.png")
        no_rgba2   = os.path.join(working_dir, f"{base}_nodither.rgba2")
        dith_png   = os.path.join(working_dir, f"{base}_{ditherMethod}.png")
        dith_rgba2 = os.path.join(working_dir, f"{base}_{ditherMethod}.rgba2")

        shutil.copyfile(pngpath, no_png)
        au.convert_to_palette(no_png, no_png, paletteFile, noDitherMethod, (0,0,0,0))
        au.img_to_rgba2(no_png, no_rgba2)

        shutil.copyfile(pngpath, dith_png)
        au.convert_to_palette(dith_png, dith_png, paletteFile, ditherMethod, (0,0,0,0))
        au.img_to_rgba2(dith_png, dith_rgba2)

        with open(no_rgba2, "rb") as f_no:
            no_data = f_no.read()
        with open(dith_rgba2, "rb") as f_dith:
            dither_data = f_dith.read()

        return no_data, dither_data

    # 3) Main loop
    palette_file = "/home/smith/Agon/mystuff/assets/images/palettes/Agon63.gpl"  # 63-color palette missing pure magenta!
    frame_count = 0

    for (fidx, fname) in indexed:
        fullpath = os.path.join(src_dir, fname)
        print(f"Processing frame {fidx}: {fname}")

        # a) produce noDither & dithered arrays
        noDither_bytes, dithered_bytes = get_no_and_dither_arrays(
            fullpath, palette_file, noDitherMethod, dither_method
        )

        # b) if first time => initialize oldNo, oldFinal, and unchanged_count
        if oldNo is None:
            oldNo    = bytearray(len(noDither_bytes))  # all zeros
            oldFinal = bytearray(len(noDither_bytes))  # all zeros
            unchanged_count = np.zeros(len(noDither_bytes), dtype=np.uint16)

        # c) reuse dithering with lookback
        finalDither = reuse_dithering_with_lookback(
            oldNo, noDither_bytes,
            oldFinal, dithered_bytes,
            unchanged_count, T
        )

        # d) diff & convert => .png
        diff = compute_frame_difference(oldFinal, finalDither)
        # Leave NO_DIFF_COLOR (magenta) pixels as is.
        diff_rgba2 = os.path.join(diff_dir, f"frame_{fidx:05d}_diff.rgba2")
        with open(diff_rgba2, "wb") as tmpf:
            tmpf.write(diff)

        diff_png = os.path.join(diff_dir, f"frame_{fidx:05d}_diff.png")
        with Image.open(fullpath) as testimg:
            w, h = testimg.size
        au.rgba2_to_img(diff_rgba2, diff_png, w, h)

        # e) update oldNo, oldFinal
        oldNo[:]    = noDither_bytes
        oldFinal[:] = finalDither

        frame_count += 1

    print(f"\nAll done. Produced {frame_count} difference images in '{diff_dir}'.")


if __name__ == "__main__":
    start_png      = '/home/smith/Agon/mystuff/assets/video/frames/frame_00000.png'
    end_png        = '/home/smith/Agon/mystuff/assets/video/frames/frame_99999.png'
    working_dir    = '/home/smith/Agon/mystuff/assets/video/working'
    noDitherMethod = 'RGB'   # e.g. "bayer" or "RGB"
    dither_method  = 'bayer'  # final dithering
    diff_dir       = f'/home/smith/Agon/mystuff/assets/video/diffs_{noDitherMethod}_{dither_method}'
    T              = 5        # frames to wait before forced refresh

    dither_diff_test(start_png, end_png, working_dir, diff_dir, noDitherMethod, dither_method, T)

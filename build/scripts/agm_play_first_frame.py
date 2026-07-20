#!/usr/bin/env python3
import os
import struct
import subprocess
import tempfile
from io import BytesIO
import agonutils as au

WAV_HEADER_SIZE = 76
AGM_HEADER_SIZE = 68
SEGMENT_HEADER_SIZE = 8  # (lastSegmentSize, thisSegmentSize) => 8 bytes total

def hexdump_file(file_path, num_bytes=16):
    """Print a hexdump of the first `num_bytes` of a file."""
    with open(file_path, "rb") as f:
        data = f.read(num_bytes)
    hex_output = " ".join(f"{b:02X}" for b in data)
    print(f"[HEXDUMP] {file_path} (First {num_bytes} bytes): {hex_output}")

def decompress_szip(input_bytes):
    """Decompress SZIP data using `szip -d`."""
    with tempfile.NamedTemporaryFile(delete=False) as temp_in:
        temp_in_name = temp_in.name
        temp_in.write(input_bytes)
        temp_in.close()

    with tempfile.NamedTemporaryFile(delete=False) as temp_out:
        temp_out_name = temp_out.name

    print(f"[INFO] SZIP compressed data written to: {temp_in_name} (Size: {len(input_bytes)} bytes)")
    hexdump_file(temp_in_name)

    try:
        subprocess.run(["szip", "-d", temp_in_name, temp_out_name], check=True)
        with open(temp_out_name, "rb") as f_out:
            decompressed_data = f_out.read()
    finally:
        # Commented out cleanup so files remain for inspection
        # os.remove(temp_in_name)
        # os.remove(temp_out_name)
        pass

    return decompressed_data

def decompress_rle2(input_bytes):
    """Decompress RLE2 data using `rle2 -d`."""
    with tempfile.NamedTemporaryFile(delete=False) as temp_in:
        temp_in_name = temp_in.name
        temp_in.write(input_bytes)
        temp_in.close()

    with tempfile.NamedTemporaryFile(delete=False) as temp_out:
        temp_out_name = temp_out.name

    print(f"[INFO] RLE2 compressed data written to: {temp_in_name} (Size: {len(input_bytes)} bytes)")

    try:
        subprocess.run(["rle2", "-d", temp_in_name, temp_out_name], check=True)
        with open(temp_out_name, "rb") as f_out:
            decompressed_data = f_out.read()
    finally:
        # Commented out cleanup so files remain for inspection
        # os.remove(temp_in_name)
        # os.remove(temp_out_name)
        pass

    return decompressed_data

def extract_first_second(agm_path):
    """
    Extract the first full second of video frames from an AGM file.
    For each frame in the first second, output:
      - frame_fffff.rgba2 (raw decompressed frame data)
      - frame_fffff.png   (converted PNG using agonutils)
    All output files will be written to the same directory as the input AGM file.
    """
    # Get the directory and basename of the AGM file.
    agm_dir = os.path.dirname(os.path.abspath(agm_path))
    agm_basename = os.path.basename(agm_path)

    # --- Read the first segment from the AGM file ---
    with open(agm_path, "rb") as f:
        # Skip WAV header + AGM header.
        f.seek(WAV_HEADER_SIZE + AGM_HEADER_SIZE)

        # Read the first segment header.
        seg_header_offset = f.tell()
        seg_header = f.read(SEGMENT_HEADER_SIZE)
        if len(seg_header) < SEGMENT_HEADER_SIZE:
            print("Error: AGM file does not contain a valid segment header.")
            return

        _, seg_size = struct.unpack("<II", seg_header)
        print(f"[INFO] Segment header found at offset {seg_header_offset}, size={seg_size} bytes")

        segment_offset = f.tell()
        segment_data = f.read(seg_size)
        print(f"[INFO] Segment data starts at offset {segment_offset}")

    # --- Extract the compressed video unit ---
    seg_stream = BytesIO(segment_data)
    unit_mask_offset = segment_offset + seg_stream.tell()
    unit_mask = seg_stream.read(1)[0]

    if not (unit_mask & 0x80):
        print("Error: First unit is not a video unit.")
        return

    print(f"[INFO] Video unit mask found at offset {unit_mask_offset}: 0x{unit_mask:02X}")

    compressed_data = b""
    while True:
        chunk_size_data = seg_stream.read(4)
        if len(chunk_size_data) < 4:
            break
        chunk_size = struct.unpack("<I", chunk_size_data)[0]
        if chunk_size == 0:
            break
        compressed_data += seg_stream.read(chunk_size)

    print(f"[INFO] SZIP compressed data size: {len(compressed_data)} bytes")
    if not compressed_data:
        print("Error: No compressed frame data found.")
        return

    # --- Decompress the video unit ---
    szip_file = os.path.join(agm_dir, f"{agm_basename}.szip")
    with open(szip_file, "wb") as fszip:
        fszip.write(compressed_data)
    print(f"[INFO] SZIP compressed data saved to: {szip_file}")

    rle_file = os.path.join(agm_dir, f"{agm_basename}.rle")
    subprocess.run(["szip", "-d", szip_file, rle_file], check=True)
    print(f"[INFO] SZIP decompressed data saved to: {rle_file}")

    output_rgba2 = os.path.join(agm_dir, f"{agm_basename}.rgba2")
    subprocess.run(["rle2", "-d", rle_file, output_rgba2], check=True)
    print(f"[INFO] RLE2 decompressed data saved to: {output_rgba2}")

    # --- Read AGM header for frame dimensions and frame rate ---
    with open(agm_path, "rb") as f:
        f.seek(WAV_HEADER_SIZE)
        agm_header_data = f.read(AGM_HEADER_SIZE)
        if len(agm_header_data) < AGM_HEADER_SIZE:
            print("Error: Could not read full AGM header.")
            return
        agm_header_fmt = "<6sBHHBII48x"
        try:
            magic, version, width, height, frame_rate, total_frames, total_secs = struct.unpack(agm_header_fmt, agm_header_data)
        except struct.error as e:
            print("Error: Failed to parse AGM header:", e)
            return

    print(f"[INFO] Frame dimensions: {width}x{height}, Frame rate: {frame_rate} fps")
    frame_size = width * height

    # --- Read the full decompressed RGBA2 data ---
    with open(output_rgba2, "rb") as f:
        full_second_data = f.read()
    # Do not remove output_rgba2 so that it remains for inspection
    # os.remove(output_rgba2)

    expected_frames = frame_rate  # Expect one second's worth of frames.
    if len(full_second_data) < expected_frames * frame_size:
        print(f"Warning: Data size {len(full_second_data)} bytes is less than expected {expected_frames * frame_size} bytes.")
        expected_frames = len(full_second_data) // frame_size

    print(f"[INFO] Extracting {expected_frames} frames from the first second.")

    # --- Split the data into individual frames and convert each ---
    for i in range(expected_frames):
        frame_data = full_second_data[i * frame_size : (i + 1) * frame_size]
        frame_rgba2_file = os.path.join(agm_dir, f"frame_{i:05d}.rgba2")
        frame_png_file = os.path.join(agm_dir, f"frame_{i:05d}.png")
        with open(frame_rgba2_file, "wb") as f_out:
            f_out.write(frame_data)
        print(f"[INFO] Written {frame_rgba2_file} ({len(frame_data)} bytes)")
        # Convert the .rgba2 file to PNG.
        au.rgba2_to_img(frame_rgba2_file, frame_png_file, width, height)
        print(f"[INFO] Converted {frame_rgba2_file} to PNG: {frame_png_file}")

    # --- Clean up intermediate files (optional; commented out for inspection) ---
    # os.remove(szip_file)
    # os.remove(rle_file)

if __name__ == "__main__":
    agm_file = "tgt/video/Star_Wars__Battle_of_Yavin_bayer.agm"
    if not os.path.exists(agm_file):
        print(f"Error: AGM file not found at '{agm_file}'")
    else:
        extract_first_second(agm_file)

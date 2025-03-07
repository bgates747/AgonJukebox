#!/usr/bin/env python3
import os
import struct
import subprocess
import tempfile
import math
from io import BytesIO

# ------------------- Unit Header Mask Definitions -------------------
AGM_UNIT_TYPE      = 0b10000000  # Bit 7: 1 = video; 0 = audio
AGM_UNIT_GCOL      = 0b00000111  # Bits 0-2: GCOL plotting mode (set to 0)
AGM_UNIT_CMP_TVC   = 0b00010000  # Bit 4: TurboVega compression (bit 4 set)

# Final video unit mask: video type OR TurboVega compression.
VIDEO_MASK = AGM_UNIT_TYPE | AGM_UNIT_CMP_TVC
# --------------------------------------------------------------------

def extract_first_video_unit(agm_file_path):
    """
    Extracts the first video unit from the AGM file.
    Returns the raw compressed video unit data as bytes.
    """
    with open(agm_file_path, "rb") as f:
        # Skip WAV header (76 bytes) and AGM header (68 bytes)
        f.seek(76 + 68)
        # Read the segment header (8 bytes)
        seg_header = f.read(8)
        if len(seg_header) < 8:
            raise ValueError("Segment header not found")
        # The segment header: two 4-byte integers (lastSegmentSize, thisSegmentSize)
        # thisSegmentSize already includes the 8-byte header.
        _, seg_size = struct.unpack("<II", seg_header)
        # Calculate payload size (segment data excluding header)
        payload_size = seg_size - 8
        seg_payload = f.read(payload_size)
        if len(seg_payload) < payload_size:
            raise ValueError("Incomplete segment payload")

    # The first unit in the segment payload is expected to be a video unit.
    stream = BytesIO(seg_payload)
    unit_header = stream.read(1)
    if not unit_header:
        raise ValueError("No unit header found in segment payload")
    unit_mask = unit_header[0]
    if not (unit_mask & 0x80):
        raise ValueError("The first unit is not a video unit")
    
    # Read chunks until a zero-length chunk is encountered.
    video_unit_data = bytearray()
    while True:
        chunk_size_bytes = stream.read(4)
        if len(chunk_size_bytes) < 4:
            break
        chunk_size = struct.unpack("<I", chunk_size_bytes)[0]
        if chunk_size == 0:
            break
        chunk_data = stream.read(chunk_size)
        video_unit_data.extend(chunk_data)
    return bytes(video_unit_data)

def hexdump_first_32(file_path):
    """
    Reads the first 32 bytes of the given file and prints a hexdump similar to `hexdump -C`.
    """
    with open(file_path, "rb") as f:
        data = f.read(32)
    for i in range(0, len(data), 16):
        line = data[i:i+16]
        hex_bytes = " ".join(f"{b:02x}" for b in line)
        ascii_str = "".join(chr(b) if 32 <= b < 127 else "." for b in line)
        print(f"{i:08x}  {hex_bytes:<48}  {ascii_str}")

def main():
    # Source AGM file.
    agm_file_path = "tgt/video/Star_Wars__Battle_of_Yavin_bayer.agm"
    if not os.path.exists(agm_file_path):
        print(f"AGM file not found: {agm_file_path}")
        return

    # Get the directory for output.
    base_dir = os.path.dirname(agm_file_path)
    szip_file = os.path.join(base_dir, "frame.rgba2.szip")
    rle2_file = os.path.join(base_dir, "frame.rgba2.rle2")
    final_file = os.path.join(base_dir, "frame.rgba2")

    # Extract the first video unit and write to frame.rgba2.szip.
    video_unit = extract_first_video_unit(agm_file_path)
    with open(szip_file, "wb") as f:
        f.write(video_unit)
    print("Saved first video unit as:", szip_file)

    # Decompress using szip -d to get frame.rgba2.rle2.
    subprocess.run(["szip", "-d", szip_file, rle2_file], check=True)
    print("Decompressed with szip to:", rle2_file)

    # Decompress using rle2 -d to get frame.rgba2.
    subprocess.run(["rle2", "-d", rle2_file, final_file], check=True)
    print("Decompressed with rle2 to:", final_file)

    # Re-read the AGM header to get frame resolution.
    with open(agm_file_path, "rb") as f:
        f.seek(76)  # skip WAV header
        agm_header = f.read(68)
    agm_header_fmt = "<6sBHHBII48x"
    try:
        magic, version, width, height, fps, total_frames, audio_secs = struct.unpack(agm_header_fmt, agm_header)
    except struct.error as e:
        print("Error parsing AGM header:", e)
        return
    expected_size = width * height  # 1 byte per pixel

    final_size = os.path.getsize(final_file)
    if final_size == expected_size:
        print(f"Final decompressed frame size is correct: {final_size} bytes")
    else:
        print(f"Warning: Final decompressed frame size is {final_size} bytes, expected {expected_size} bytes")

    # Print hexdump for the first 32 bytes of each file.
    for file in [szip_file, rle2_file, final_file]:
        print(f"\nHexdump of first 32 bytes of {os.path.basename(file)}:")
        hexdump_first_32(file)

if __name__ == "__main__":
    main()

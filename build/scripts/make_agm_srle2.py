#!/usr/bin/env python3
import os
import struct
import subprocess
import tempfile
import math
from io import BytesIO

# ------------------- Unit Header Mask Definitions -------------------
# Bit definitions (using binary for clarity):
AGM_UNIT_TYPE       = 0b10000000  # Bit 7: 1 = video; 0 = audio
AGM_UNIT_GCOL       = 0b00000111  # Bits 0-2: GCOL plotting mode (set to 0 here)
AGM_UNIT_CMP_SRLE2  = 0b00011000  # Bits 3-4: srle2 compression (bits 3,4 set)

# Final video unit mask: video type OR TurboVega compression.
VIDEO_MASK = AGM_UNIT_TYPE | AGM_UNIT_CMP_SRLE2
# --------------------------------------------------------------------

def compress_frame_data(frame_bytes, frame_idx, total_frames):
    """
    Compress the raw frame data using an external compressor.
    
    Parameters:
      frame_bytes (bytes): The raw frame data.
      frame_idx (int): Index of the frame (for status printing).
      total_frames (int): Total number of frames (for status printing).
      
    Returns:
      bytes: The compressed frame data.
    """
    # Create a temporary file for the raw data.
    temp_raw = tempfile.NamedTemporaryFile(delete=False)
    try:
        temp_raw.write(frame_bytes)
        temp_raw.close()
        raw_path = temp_raw.name

        # Create temporary files for the intermediate and final outputs.
        temp_rle2 = tempfile.NamedTemporaryFile(delete=False)
        temp_rle2.close()
        temp_rle2_path = temp_rle2.name

        temp_srle2 = tempfile.NamedTemporaryFile(delete=False)
        temp_srle2.close()
        temp_srle2_path = temp_srle2.name

        # Run the compression commands.
        subprocess.run(["rle2", "-c", raw_path, temp_rle2_path], check=True)
        subprocess.run(["szip", "-b41o3", temp_rle2_path, temp_srle2_path], check=True)

        compressed_size = os.path.getsize(temp_srle2_path)
        original_size = len(frame_bytes)
        compression_ratio = 100.0 * compressed_size / original_size if original_size > 0 else 0.0

        print(
            f"\rsrle2ped segment ending with frame {frame_idx + 1} of {total_frames}, "
            f"{original_size} bytes -> {compressed_size} bytes, "
            f"{compression_ratio:.1f}%",
            end="",
            flush=True
        )

        with open(temp_srle2_path, "rb") as f_in:
            compressed_bytes = f_in.read()

    finally:
        # Clean up temporary files.
        if os.path.exists(temp_raw.name):
            os.remove(temp_raw.name)
        if os.path.exists(temp_srle2_path):
            os.remove(temp_srle2_path)

    return compressed_bytes

def make_agm_srle2(
    frames_file,
    target_audio_path,
    target_agm_path,
    target_width,
    target_height,
    frame_rate,
    target_sample_rate,
    chunksize
):
    """
    Creates an AGM file with the following structure:
      - 76-byte WAV header (with 'agm' marker at offset 12..14).
      - 68-byte AGM header.
      - For each video frame:
          - 8-byte segment header (lastSegmentSize, thisSegmentSize).
          - Video unit: 1 byte mask (bit7=1), then a single compressed block representing
            the frame, written in chunks:
              * <I=chunk_size> + chunk_data
              * A 0 for chunk_size indicates end of video unit.
          - Audio unit: 1 byte mask (bit7=0), then multiple:
              * <I=chunk_size> + chunk_data
              * A 0 for chunk_size indicates end of audio unit.
              
    Additionally, writes a CSV file recording aggregated per-second video data.
    The CSV file will have a file header with frame_size, frame_rate, and audio_rate,
    and then for each second, a row with time (sec) and the aggregated compressed video unit size.
    The CSV file is named: <agm_basename>.agm_<frame_rate:03d>.csv in the same directory.
    
    Note: Although the AGM header’s total_secs is computed as the ceiling of the
    total movie duration in seconds (total_frames/frame_rate), the file is now segmented per frame,
    while the CSV data remains aggregated by whole seconds.
    """
    WAV_HEADER_SIZE = 76
    AGM_HEADER_SIZE = 68
    # Using 16-bit width/height ("H") instead of 8-bit ("B") for each.
    agm_header_fmt  = "<6sBHHBII48x"

    # Masks (bit7=1 => video; bit7=0 => audio)
    AUDIO_MASK = 0x00  # 0b00000000

    # 1) Gather frames from the .frames file.
    if not os.path.exists(frames_file):
        raise RuntimeError(f"Frames file not found: {frames_file}")
    with open(frames_file, "rb") as f:
        frames_data = f.read()
    frame_size = target_width * target_height
    total_frames = len(frames_data) // frame_size
    print("-------------------------------------------------")
    print(f"make_agm: Found {total_frames} frames in {frames_file}")

    # 2) Read audio + fix header
    with open(target_audio_path, "rb") as wf:
        wav_header = wf.read(WAV_HEADER_SIZE)  # 76 bytes
        # Insert "agm" marker at offset 12..14
        wav_header = wav_header[:12] + b"agm" + wav_header[15:]
        audio_data = wf.read()

    audio_data_size = len(audio_data)
    audio_secs_float = audio_data_size / float(target_sample_rate)

    # 3) Determine overall duration in seconds.
    video_secs_float = total_frames / float(frame_rate)
    total_secs = int(math.ceil(max(video_secs_float, audio_secs_float)))
    print(
        f"Video ~{video_secs_float:.2f}s, Audio ~{audio_secs_float:.2f}s => "
        f"Merging {total_frames} frames total."
    )

    # 4) Create AGM header (68 bytes)
    version       = 1
    total_frames_ = total_frames
    total_secs_   = total_secs  # overall duration in seconds (ceiled)
    agm_header = struct.pack(
        agm_header_fmt,
        b"AGNMOV",       # magic (6 bytes)
        version,         # 1 byte
        target_width,    # 16-bit unsigned (2 bytes)
        target_height,   # 16-bit unsigned (2 bytes)
        frame_rate,      # 1 byte
        total_frames_,   # 4 bytes
        total_secs_      # 4 bytes
    )

    # Prepare output file paths in the target directory.
    target_agm_dir = os.path.dirname(target_agm_path)
    target_agm_basename = os.path.basename(target_agm_path).split(".")[0]
    target_agm_path = os.path.join(target_agm_dir, f"{target_agm_basename}.agm")
    csv_filename = os.path.join(target_agm_dir, f"{target_agm_basename}.agm_{frame_rate:03d}.csv")
    
    print(f"Writing AGM to: {target_agm_path}")
    print(f"Writing CSV data to: {csv_filename}")

    # Prepare a list to aggregate video compressed sizes per second.
    aggregated_video_bytes = [0] * total_secs

    # Open the CSV file and write header.
    with open(csv_filename, "w") as csv_file:
        csv_file.write("frame_size,frame_rate,audio_rate\n")
        csv_file.write(f"{target_width * target_height},{frame_rate},{target_sample_rate}\n")
        csv_file.write("time_sec,compressed_video_bytes\n")

        # 5) Write .agm file
        with open(target_agm_path, "wb") as agm_file:
            # Write WAV header + AGM header.
            agm_file.write(wav_header)
            agm_file.write(agm_header)

            segment_size_last = 0

            # Calculate number of audio samples per frame.
            samples_per_frame = target_sample_rate // frame_rate

            # Process each frame.
            for frame_index in range(total_frames):
                seg_buffer = BytesIO()

                # ---------------- VIDEO UNIT (with compression) ----------------
                seg_buffer.write(struct.pack("<B", VIDEO_MASK))
                start = frame_index * frame_size
                end = start + frame_size
                frame_bytes = frames_data[start:end]

                # Compress the single frame.
                compressed_frame_bytes = compress_frame_data(frame_bytes, frame_index, total_frames)
                
                # Write compressed video data in chunks.
                off = 0
                while off < len(compressed_frame_bytes):
                    chunk = compressed_frame_bytes[off: off + chunksize]
                    off += len(chunk)
                    seg_buffer.write(struct.pack("<I", len(chunk)))
                    seg_buffer.write(chunk)
                seg_buffer.write(struct.pack("<I", 0))  # zero-length chunk

                # ---------------- AUDIO UNIT ----------------
                seg_buffer.write(struct.pack("<B", AUDIO_MASK))
                start_aud = frame_index * samples_per_frame
                end_aud   = start_aud + samples_per_frame
                unit_audio = audio_data[start_aud:end_aud]
                if len(unit_audio) < samples_per_frame:
                    unit_audio += b"\x00" * (samples_per_frame - len(unit_audio))
                offset = 0
                while offset < len(unit_audio):
                    chunk = unit_audio[offset: offset + chunksize]
                    offset += len(chunk)
                    seg_buffer.write(struct.pack("<I", len(chunk)))
                    seg_buffer.write(chunk)
                seg_buffer.write(struct.pack("<I", 0))  # zero-length chunk

                # Finalize segment.
                segment_data = seg_buffer.getvalue()
                segment_size_this = len(segment_data)
                agm_file.write(struct.pack("<II", segment_size_last, segment_size_this))
                agm_file.write(segment_data)
                segment_size_last = segment_size_this

                # Accumulate compressed video size into the corresponding second.
                second_index = frame_index // frame_rate
                if second_index < total_secs:
                    aggregated_video_bytes[second_index] += len(compressed_frame_bytes)

        # Write CSV rows aggregated by second.
        for sec in range(total_secs):
            csv_file.write(f"{sec},{aggregated_video_bytes[sec]}\n")

    print("AGM file creation complete.\n")
    print(f"CSV data written to: {csv_filename}")

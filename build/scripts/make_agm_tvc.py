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

def compress_frame_data(frame_bytes, frame_idx, total_frames):
    """
    Compress the raw frame data using the tvc compressor.
    
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

        # Create a temporary file for the tvc output.
        temp_tvc = tempfile.NamedTemporaryFile(delete=False)
        temp_tvc.close()
        temp_tvc_path = temp_tvc.name

        # Run the tvc compression command.
        subprocess.run(["tvc", "-c", raw_path, temp_tvc_path], check=True)

        compressed_size = os.path.getsize(temp_tvc_path)
        original_size = len(frame_bytes)
        compression_ratio = 100.0 * compressed_size / original_size if original_size > 0 else 0.0

        print(
            f"\ttvc'd frame {frame_idx + 1} of {total_frames}: "
            f"{original_size} bytes -> {compressed_size} bytes, "
            f"{compression_ratio:.1f}%",
            end="",
            flush=True
        )

        with open(temp_tvc_path, "rb") as f_in:
            compressed_bytes = f_in.read()
    finally:
        # Clean up temporary files.
        if os.path.exists(temp_raw.name):
            os.remove(temp_raw.name)
        if os.path.exists(temp_tvc_path):
            os.remove(temp_tvc_path)

    return compressed_bytes

def make_agm_tvc(
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
    Creates an AGM file using TurboVega compression.
    
    Structure:
      - 76-byte WAV header (with 'agm' marker at offset 12..14).
      - 68-byte AGM header.
      - For each video frame:
          - 8-byte segment header (previous segment size, current segment size).
          - Video unit: 1-byte mask, then one compressed block (written in chunks)
            representing the single frame.
          - Audio unit: 1-byte mask, then audio data for that frame (written in chunks).
    
    The CSV report aggregates the per-frame compressed video sizes into 1-second intervals.
    """
    WAV_HEADER_SIZE = 76
    AGM_HEADER_SIZE = 68
    # AGM header: magic (6s), version (B), width (H), height (H), frame_rate (B),
    # total_frames (I), total_secs (I), and 48 bytes reserved.
    agm_header_fmt = "<6sBHHBII48x"

    AUDIO_MASK = 0x00  # Audio unit mask (bit7=0)

    # 1) Load frames.
    if not os.path.exists(frames_file):
        raise RuntimeError(f"Frames file not found: {frames_file}")
    with open(frames_file, "rb") as f:
        frames_data = f.read()
    frame_size = target_width * target_height
    total_frames = len(frames_data) // frame_size
    print("-------------------------------------------------")
    print(f"make_agm_tvc: Found {total_frames} frames in {frames_file}")

    # 2) Read and fix audio header.
    with open(target_audio_path, "rb") as wf:
        wav_header = wf.read(WAV_HEADER_SIZE)
        # Insert "agm" marker at offset 12..14.
        wav_header = wav_header[:12] + b"agm" + wav_header[15:]
        audio_data = wf.read()

    audio_data_size = len(audio_data)
    audio_secs_float = audio_data_size / float(target_sample_rate)

    # 3) Determine overall duration.
    video_secs_float = total_frames / float(frame_rate)
    total_secs = int(math.ceil(max(video_secs_float, audio_secs_float)))
    print(
        f"Video ~{video_secs_float:.2f}s, Audio ~{audio_secs_float:.2f}s => "
        f"Merging {total_frames} frames total."
    )

    # 4) Create AGM header.
    version = 1
    total_frames_ = total_frames
    total_secs_ = total_secs
    agm_header = struct.pack(
        agm_header_fmt,
        b"AGNMOV",      # Magic
        version,        # Version
        target_width,   # Width
        target_height,  # Height
        frame_rate,     # Frame rate
        total_frames_,  # Total frames
        total_secs_     # Total seconds
    )

    # Prepare output paths.
    target_agm_dir = os.path.dirname(target_agm_path)
    target_agm_basename = os.path.basename(target_agm_path).split(".")[0]
    target_agm_path = os.path.join(target_agm_dir, f"{target_agm_basename}.agm")
    csv_filename = os.path.join(target_agm_dir, f"{target_agm_basename}.agm_{frame_rate:03d}.csv")
    
    print(f"Writing AGM to: {target_agm_path}")
    print(f"Writing CSV data to: {csv_filename}")

    # Prepare aggregation list for CSV (per-second compressed video sizes).
    aggregated_video_bytes = [0] * total_secs

    # Calculate the number of audio samples per frame.
    samples_per_frame = target_sample_rate // frame_rate

    # 5) Write AGM file and CSV report.
    with open(target_agm_path, "wb") as agm_file, open(csv_filename, "w") as csv_file:
        # Write CSV header.
        csv_file.write("frame_size,frame_rate,audio_rate\n")
        csv_file.write(f"{target_width * target_height},{frame_rate},{target_sample_rate}\n")
        csv_file.write("time_sec,compressed_video_bytes\n")

        # Write WAV and AGM headers.
        agm_file.write(wav_header)
        agm_file.write(agm_header)

        segment_size_last = 0

        # Process each frame.
        for frame_index in range(total_frames):
            seg_buffer = BytesIO()

            # ---------------- VIDEO UNIT ----------------
            seg_buffer.write(struct.pack("<B", VIDEO_MASK))
            start = frame_index * frame_size
            end = start + frame_size
            frame_bytes = frames_data[start:end]

            # Compress the single frame.
            compressed_frame_bytes = compress_frame_data(frame_bytes, frame_index, total_frames)

            # Write the compressed video data in chunks.
            off = 0
            while off < len(compressed_frame_bytes):
                chunk = compressed_frame_bytes[off: off + chunksize]
                off += len(chunk)
                seg_buffer.write(struct.pack("<I", len(chunk)))
                seg_buffer.write(chunk)
            # Terminate the video unit with a zero-length chunk.
            seg_buffer.write(struct.pack("<I", 0))

            # ---------------- AUDIO UNIT ----------------
            seg_buffer.write(struct.pack("<B", AUDIO_MASK))
            start_aud = frame_index * samples_per_frame
            end_aud = start_aud + samples_per_frame
            unit_audio = audio_data[start_aud:end_aud]
            if len(unit_audio) < samples_per_frame:
                unit_audio += b"\x00" * (samples_per_frame - len(unit_audio))
            offset = 0
            while offset < len(unit_audio):
                chunk = unit_audio[offset: offset + chunksize]
                offset += len(chunk)
                seg_buffer.write(struct.pack("<I", len(chunk)))
                seg_buffer.write(chunk)
            # Terminate the audio unit.
            seg_buffer.write(struct.pack("<I", 0))

            # Finalize segment.
            segment_data = seg_buffer.getvalue()
            segment_size_this = len(segment_data)
            agm_file.write(struct.pack("<II", segment_size_last, segment_size_this))
            agm_file.write(segment_data)
            segment_size_last = segment_size_this

            # Aggregate compressed video size for CSV.
            second_index = frame_index // frame_rate
            if second_index < total_secs:
                aggregated_video_bytes[second_index] += len(compressed_frame_bytes)

        # Write aggregated CSV rows.
        for sec in range(total_secs):
            csv_file.write(f"{sec},{aggregated_video_bytes[sec]}\n")

    print("AGM file creation complete.\n")
    print(f"CSV data written to: {csv_filename}")

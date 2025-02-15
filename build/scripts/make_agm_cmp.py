import os
import struct
import subprocess
import tempfile
import math
from io import BytesIO

# ------------------- Unit Header Mask Definitions -------------------
# Bit definitions:
AGM_UNIT_TYPE     = 0b10000000  # Bit 7: 1 = video, 0 = audio
AGM_UNIT_GCOL     = 0b00000111  # Bits 0-2: GCOL plotting mode => 0
AGM_UNIT_CMP_TBV  = 0b00001000  # Bits 3 => 01 => TurboVega

# Combine: Video type + TurboVega => 0x80 | 0x08 => 0x88
VIDEO_MASK = AGM_UNIT_TYPE | AGM_UNIT_CMP_TBV  # => 0x88

def compress_frame_data(frame_bytes, frame_idx, total_frames):
    """
    Compress the raw frame data using an external 'compress' tool
    for TurboVega compression.
    
    Parameters:
      frame_bytes (bytes): The raw frame data.
      frame_idx (int): Index of the current frame (for status printing).
      total_frames (int): Total number of frames (for status printing).
      
    Returns:
      bytes: The compressed frame data.
    """
    # 1) Write raw frame to a temp file
    temp_raw = tempfile.NamedTemporaryFile(delete=False)
    try:
        temp_raw.write(frame_bytes)
        temp_raw.close()
        raw_path = temp_raw.name

        # 2) Prepare temporary output for compressed data
        temp_compressed = tempfile.NamedTemporaryFile(delete=False)
        temp_compressed.close()
        compressed_path = temp_compressed.name

        # 3) Run the external compression tool
        #    e.g. ./build/utils/compress <in> <out>
        result = subprocess.run(
            ["compress", raw_path, compressed_path],
            capture_output=True,
            text=True,
            check=True
        )

        # Optional: parse tool output
        output_lines = result.stdout.split("\n")
        if len(output_lines) > 1:
            compression_info = output_lines[1].strip()
        else:
            compression_info = "No additional compression info"
        print(f"[Frame {frame_idx + 1}/{total_frames}] {compression_info}", end="\r", flush=True)

        # 4) Read the compressed file
        with open(compressed_path, "rb") as f_in:
            compressed_bytes = f_in.read()

    finally:
        # Clean up temp files
        if os.path.exists(temp_raw.name):
            os.remove(temp_raw.name)
        if os.path.exists(compressed_path):
            os.remove(compressed_path)

    return compressed_bytes

def make_agm_cmp(
    frames_directory,
    target_audio_path,
    target_agm_path,
    target_width,
    target_height,
    frame_rate,
    target_sample_rate,
    chunksize
):
    """
    Creates an AGM file with TurboVega-compressed video frames.

    Structure:
      - 76-byte WAV header (with 'agm' marker at offset 12..14).
      - 68-byte AGM header (version=1, 16-bit width/height, etc.).
      - For each 1-second segment (there are `total_secs` of them):
          1) VIDEO unit (1-byte mask = 0x88 for "video + TBV compression")
             * multiple chunks => <I=chunk_size> + chunk_data
             * ends with chunk_size=0
          2) AUDIO unit (1-byte mask = 0x00)
             * chunked => <I=chunk_size> + chunk_data
             * ends with chunk_size=0
          3) Segment header => 8 bytes: (lastSegmentSize, thisSegmentSize)
    """
    WAV_HEADER_SIZE = 76
    AGM_HEADER_SIZE = 68
    # Format with 16-bit width/height, 48 bytes reserved
    agm_header_fmt  = "<6sBHHBII48x"

    # Masks
    AUDIO_MASK = 0x00  # bit7=0, no compression
    # VIDEO_MASK from above => 0x88

    # 1) Gather frames
    frame_files = sorted(f for f in os.listdir(frames_directory) if f.endswith(".rgba2"))
    total_frames = len(frame_files)
    print("-------------------------------------------------")
    print(f"make_agm_cmp: Found {total_frames} frames in {frames_directory}")

    # 2) Read audio + fix header
    with open(target_audio_path, "rb") as wf:
        wav_header = wf.read(WAV_HEADER_SIZE)  # 76 bytes
        # Insert "agm" marker at offset 12..14
        wav_header = wav_header[:12] + b"agm" + wav_header[15:]
        audio_data = wf.read()

    audio_data_size = len(audio_data)
    audio_secs_float = audio_data_size / float(target_sample_rate)

    # 3) Determine total_secs
    video_secs_float = total_frames / float(frame_rate)
    total_secs = int(math.ceil(max(video_secs_float, audio_secs_float)))
    print(
        f"Video ~{video_secs_float:.2f}s, Audio ~{audio_secs_float:.2f}s => "
        f"Merging up to {total_secs}s total."
    )

    # 4) Create AGM header (68 bytes)
    version       = 1
    total_frames_ = total_frames
    total_secs_   = total_secs
    agm_header = struct.pack(
        agm_header_fmt,
        b"AGNMOV",       # magic 6 bytes
        version,         # 1 byte
        target_width,    # 2 bytes, LE
        target_height,   # 2 bytes, LE
        frame_rate,      # 1 byte
        total_frames_,   # 4 bytes
        total_secs_      # 4 bytes
    )

    # 5) Write .agm file
    target_agm_dir = os.path.dirname(target_agm_path)
    target_agm_basename = os.path.basename(target_agm_path).split(".")[0]
    target_agm_path = os.path.join(target_agm_dir, f"{target_agm_basename}.agm")
    print(f"Writing AGM to: {target_agm_path}")

    with open(target_agm_path, "wb") as agm_file:
        # Write WAV header + AGM header
        agm_file.write(wav_header)
        agm_file.write(agm_header)

        segment_size_last = 0
        frame_idx = 0

        # For each second
        for sec in range(total_secs):
            seg_buffer = BytesIO()

            # ================= VIDEO UNIT (TurboVega) =================
            # 1) Write unit mask => 0x88 (video + TBV)
            seg_buffer.write(struct.pack("<B", VIDEO_MASK))

            # 2) For each frame in this second
            for _ in range(frame_rate):
                if frame_idx < total_frames:
                    frame_path = os.path.join(frames_directory, frame_files[frame_idx])
                    with open(frame_path, "rb") as f_in:
                        frame_bytes = f_in.read()
                    frame_idx += 1
                else:
                    # No frames left => blank
                    frame_bytes = b"\x00" * (target_width * target_height)

                # Compress using the external TurboVega tool
                compressed_frame_bytes = compress_frame_data(frame_bytes, frame_idx - 1, total_frames)

                # Chunk the compressed data
                off = 0
                while off < len(compressed_frame_bytes):
                    chunk = compressed_frame_bytes[off : off + chunksize]
                    off += len(chunk)
                    seg_buffer.write(struct.pack("<I", len(chunk)))
                    seg_buffer.write(chunk)

            # End of video unit => size=0
            seg_buffer.write(struct.pack("<I", 0))

            # ================= AUDIO UNIT =================
            # 1) Write unit mask => bit7=0 => 0x00
            seg_buffer.write(struct.pack("<B", AUDIO_MASK))

            # 2) One second of audio
            start_aud = sec * target_sample_rate
            end_aud   = start_aud + target_sample_rate
            unit_audio = audio_data[start_aud:end_aud]

            if len(unit_audio) < target_sample_rate:
                unit_audio += b"\x00" * (target_sample_rate - len(unit_audio))

            # 3) Chunk the audio data
            offset = 0
            while offset < len(unit_audio):
                chunk = unit_audio[offset : offset + chunksize]
                offset += len(chunk)
                seg_buffer.write(struct.pack("<I", len(chunk)))
                seg_buffer.write(chunk)

            # End of audio unit => size=0
            seg_buffer.write(struct.pack("<I", 0))

            # ============== FINALIZE SEGMENT ==============
            segment_data = seg_buffer.getvalue()
            segment_size_this = len(segment_data)

            # 8-byte header: (segment_size_last, segment_size_this)
            agm_file.write(struct.pack("<II", segment_size_last, segment_size_this))
            agm_file.write(segment_data)

            segment_size_last = segment_size_this

        print("AGM file creation complete.\n")

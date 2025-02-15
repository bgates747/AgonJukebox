import os
import math
import struct
from io import BytesIO

def make_agm(
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
    Creates an AGM file with this structure:
      - 76-byte WAV header (with 'agm' marker inserted at offset 12..14).
      - 68-byte AGM header:
          * b"AGNMOV" (6 bytes)
          * version (1 byte)
          * width (2 bytes, little-endian)
          * height (2 bytes, little-endian)
          * frame_rate (1 byte)
          * total_frames (4 bytes, little-endian)
          * total_secs (4 bytes, little-endian)
          * 48-byte reserved padding
      - Then, for each 1-second segment:
          * 8-byte segment header (<II: lastSegmentSize, thisSegmentSize)
          * AUDIO unit (mask bit7=0 => 0x00)
             - multiple chunks: <I=chunk_size> + chunk_data
             - ends with chunk_size=0
          * VIDEO unit (mask bit7=1 => 0x80, no compression => bits3-4=0, bits0-2=0 => gcol=0)
             - multiple frames in this second (either real or blank)
             - each frame chunked: <I=chunk_size> + chunk_data
             - ends with chunk_size=0
    """

    WAV_HEADER_SIZE = 76
    AGM_HEADER_SIZE = 68

    # Updated AGM header with 16-bit width/height
    agm_header_fmt  = "<6sBHHBII48x"

    # -----------------------------------------
    #  Mask Format (agm_unit_mask):
    #    bit7 = 0 => audio, 1 => video
    #    bits3..4 => compression type
    #       00 => no compression
    #       01 => TurboVega
    #       10 => RLE
    #       11 => Szip
    #    bits0..2 => GCOL mode (for video)
    # -----------------------------------------
    AUDIO_MASK = 0x00  # (bit7=0, no compression=0, gcol=0 => 0)
    VIDEO_MASK = 0x80  # (bit7=1, no compression=0, gcol=0 => 0x80)

    # 1) Gather frames
    frame_files = sorted(f for f in os.listdir(frames_directory) if f.endswith(".rgba2"))
    total_frames = len(frame_files)
    print("-------------------------------------------------")
    print(f"make_agm: Found {total_frames} frames in {frames_directory}")

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
        b"AGNMOV",       # magic (6 bytes)
        version,         # 1 byte
        target_width,    # 16-bit unsigned (2 bytes)
        target_height,   # 16-bit unsigned (2 bytes)
        frame_rate,      # 1 byte
        total_frames_,   # 4 bytes
        total_secs_      # 4 bytes
    )

    # 5) Write .agm file
    print(f"Writing AGM to: {target_agm_path}")
    with open(target_agm_path, "wb") as agm_file:
        # Write WAV header + AGM header
        agm_file.write(wav_header)
        agm_file.write(agm_header)

        segment_size_last = 0
        frame_idx = 0

        # For each 1-second segment
        for sec in range(total_secs):
            seg_buffer = BytesIO()

            # ================ AUDIO UNIT ================
            # 1) Write 1-byte audio mask (bit7=0 => 0x00)
            seg_buffer.write(struct.pack("<B", AUDIO_MASK))

            # 2) Extract/pad the audio for this second
            start_aud = sec * target_sample_rate
            end_aud   = start_aud + target_sample_rate
            unit_audio = audio_data[start_aud:end_aud]

            if len(unit_audio) < target_sample_rate:
                unit_audio += b"\x00" * (target_sample_rate - len(unit_audio))

            # 3) Write chunks
            offset = 0
            while offset < len(unit_audio):
                chunk = unit_audio[offset : offset + chunksize]
                offset += len(chunk)
                # 4-byte chunk size
                seg_buffer.write(struct.pack("<I", len(chunk)))
                # chunk data
                seg_buffer.write(chunk)

            # End audio unit => chunk_size=0
            seg_buffer.write(struct.pack("<I", 0))

            # ================ VIDEO UNIT ================
            # 1) Write 1-byte video mask (bit7=1 => 0x80, no compression => bits3..4=0)
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

                # 3) Chunk the frame
                off = 0
                while off < len(frame_bytes):
                    chunk = frame_bytes[off : off + chunksize]
                    off += len(chunk)
                    seg_buffer.write(struct.pack("<I", len(chunk)))
                    seg_buffer.write(chunk)

            # End video unit => chunk_size=0
            seg_buffer.write(struct.pack("<I", 0))

            # ========== FINALIZE SEGMENT ==========
            segment_data = seg_buffer.getvalue()
            segment_size_this = len(segment_data)

            # 8-byte segment header: (lastSegmentSize, thisSegmentSize)
            agm_file.write(struct.pack("<II", segment_size_last, segment_size_this))
            agm_file.write(segment_data)

            segment_size_last = segment_size_this

        print("AGM file creation complete.\n")

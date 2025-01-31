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
    Creates an AGM file with the following structure:
      - 76-byte WAV header (with 'agm' marker at offset 12..14).
      - 68-byte AGM header.
      - For each 1-second segment:
          - 8-byte segment header (lastSegmentSize, thisSegmentSize).
          - Audio unit: 1 byte mask (bit7=0), then multiple:
              * <I=chunk_size> + chunk_data
              * A 0 for chunk_size indicates end of audio unit.
          - Video unit: 1 byte mask (bit7=1), then multiple:
              * <I=chunk_size> + chunk_data
              * A 0 for chunk_size indicates end of video unit.
    """
    WAV_HEADER_SIZE = 76
    AGM_HEADER_SIZE = 68
    agm_header_fmt  = "<6sBBBBII50x"

    # Masks (bit7=1 => video; bit7=0 => audio)
    AUDIO_MASK = 0x00  # 0b00000000
    VIDEO_MASK = 0x80  # 0b10000000

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
        target_width,    # 1 byte
        target_height,   # 1 byte
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

            # ---------------- AUDIO UNIT ----------------
            # 1) Write 1 byte mask => audio = bit7=0 => 0x00
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
                # 4-byte size, then chunk data
                seg_buffer.write(struct.pack("<I", len(chunk)))
                seg_buffer.write(chunk)

            # 4) End of audio unit => size=0
            seg_buffer.write(struct.pack("<I", 0))

            # ---------------- VIDEO UNIT ----------------
            # 1) Write 1 byte mask => video = bit7=1 => 0x80
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

            # 4) End of video unit => size=0
            seg_buffer.write(struct.pack("<I", 0))

            # -------------- FINALIZE SEGMENT --------------
            segment_data = seg_buffer.getvalue()
            segment_size_this = len(segment_data)

            # Write 8-byte segment header first
            agm_file.write(struct.pack("<II", segment_size_last, segment_size_this))
            # Then the segment data
            agm_file.write(segment_data)

            # Update for next
            segment_size_last = segment_size_this

        print("AGM file creation complete.\n")

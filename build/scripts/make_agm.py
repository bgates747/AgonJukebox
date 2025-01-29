import os
import math
import struct

# ============================================================
#              AGM HEADER CONSTANTS
# ============================================================
AGM_HEADER_SIZE = 68
WAV_HEADER_SIZE = 76
TOTAL_HEADER_SIZE = AGM_HEADER_SIZE + WAV_HEADER_SIZE  # 144

# This format uses (example) offsets:
#   0..5:  magic "AGNMOV"
#   6:     version (1 byte)
#   7:     width   (1 byte)
#   8:     height  (1 byte)
#   9:     framerate (1 byte)
#   10..13: total_frames (4 bytes)
#   14..17: total_audio_seconds (4 bytes) -- integer or float
#   18..67: reserved (50 bytes)
# total = 68 bytes
agm_header_fmt = "<6sBBBBII50x"

# ============================================================
#          MERGE VIDEO & AUDIO INTO .AGM (new approach)
# ============================================================
def make_agm(
    frames_directory,
    target_audio_path,
    target_agm_path,
    target_width,
    target_height,
    frame_rate,
    target_sample_rate
):
    """
    Creates an AGM file with:
      - 76-byte WAV header
      - 68-byte AGM header
      - 144 bytes total header
      - Then data for each full second:
         1) The entire audio for that second (target_sample_rate bytes)
         2) The video frames for that second (frame_rate frames)
      - If audio or video runs out early, we pad with silence or blank frames
        up to total_secs.
    """
    # ---------------------------
    # 1) Read frames
    # ---------------------------
    frame_files = sorted(
        f for f in os.listdir(frames_directory) if f.endswith(".rgba2")
    )
    total_frames = len(frame_files)

    print("-------------------------------------------------")
    print(f"make_agm: Found {total_frames} frames in {frames_directory}")

    # Each frame in .rgba2 is exactly width*height bytes in your 8bpp format
    frame_bytes_per_frame = target_width * target_height

    # ---------------------------
    # 2) Read audio + fix header
    # ---------------------------
    with open(target_audio_path, "rb") as wf:
        wav_header = wf.read(WAV_HEADER_SIZE)  # 76 bytes
        # Modify the WAV format marker (12 byte offset) to "agm" in little-endian order
        # just as your prior code did:
        wav_header = wav_header[:12] + b"agm" + wav_header[15:]
        audio_data = wf.read()  # The rest is raw PCM data

    audio_data_size = len(audio_data)

    # We assume 8-bit mono => 1 byte per sample => length in bytes is #samples
    audio_secs_float = audio_data_size / float(target_sample_rate)

    # ---------------------------
    # 3) Determine total_secs
    # ---------------------------
    video_secs_float = total_frames / float(frame_rate)
    total_secs = int(math.ceil(max(video_secs_float, audio_secs_float)))

    print(
        f"Video ~{video_secs_float:.2f}s, Audio ~{audio_secs_float:.2f}s => "
        f"Merging up to {total_secs}s total."
    )

    # ---------------------------
    # 4) AGM header
    # ---------------------------
    version = 1
    agm_header = struct.pack(
        agm_header_fmt,
        b"AGNMOV",           # magic (6s)
        version,             # 1 byte
        target_width,        # 1 byte
        target_height,       # 1 byte
        frame_rate,          # 1 byte
        total_frames,        # 4 bytes
        total_secs,          # 4 bytes (storing as int)
        # plus 50x reserved (that's handled by 50x in struct)
    )

    # ---------------------------
    # 5) Write .agm file
    # ---------------------------
    print(f"Writing AGM to: {target_agm_path}")

    with open(target_agm_path, "wb") as agm_file:
        # (a) Write the 76-byte WAV header
        if len(wav_header) != WAV_HEADER_SIZE:
            raise ValueError("WAV header is not 76 bytes as expected.")
        agm_file.write(wav_header)

        # (b) Write the 68-byte AGM header
        if len(agm_header) != AGM_HEADER_SIZE:
            raise ValueError("AGM header is not 68 bytes as expected.")
        agm_file.write(agm_header)

        # (c) Interleave data in 1-second blocks
        #     For each second:
        #       1) Write target_sample_rate bytes of audio
        #       2) Write frame_rate frames (video data)

        # We'll keep track of which frames we've used so far:
        frame_idx = 0

        # We'll write audio in 1-second chunks
        #   audio for second s => audio_data[s * target_sample_rate : (s+1)*target_sample_rate]
        # if short, pad with zeroes
        for sec in range(total_secs):
            # ---- AUDIO chunk for this second ----
            start_aud = sec * target_sample_rate
            end_aud = start_aud + target_sample_rate
            chunk = audio_data[start_aud:end_aud]

            if len(chunk) < target_sample_rate:
                # pad with silence
                chunk += b"\x00" * (target_sample_rate - len(chunk))

            agm_file.write(chunk)

            # ---- VIDEO frames for this second ----
            # We expect `frame_rate` frames in each second
            for _ in range(frame_rate):
                if frame_idx < total_frames:
                    frame_path = os.path.join(
                        frames_directory, frame_files[frame_idx]
                    )
                    with open(frame_path, "rb") as f_in:
                        frame_bytes = f_in.read()
                    if len(frame_bytes) != frame_bytes_per_frame:
                        raise ValueError(
                            f"Frame {frame_idx} has unexpected size {len(frame_bytes)}"
                        )
                    frame_idx += 1
                else:
                    # If no more frames, write blank (fully black) frames
                    frame_bytes = b"\x00" * frame_bytes_per_frame

                agm_file.write(frame_bytes)

        print("AGM file creation complete.\n")

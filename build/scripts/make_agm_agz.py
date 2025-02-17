import os
import struct
import subprocess
import tempfile
import math
from io import BytesIO

# Masks for the AGM container format
AGM_UNIT_TYPE    = 0b10000000  # bit 7 => video
AGM_UNIT_CMP_AGZ = 0b00010000  # bit4 => "AGZ" => bits3..4=2
VIDEO_MASK       = AGM_UNIT_TYPE | AGM_UNIT_CMP_AGZ  # => 0x80 | 0x10 => 0x90

def run_agz_diff(
    old_no, new_no,
    old_dither, new_dither,
    out_tmp
):
    """
    Calls the external 'agz' tool to do difference-based compression:
      agz <oldNoDither> <newNoDither> <oldDithered> <newDithered> <outCompressed>
    The tool merges old & new dithering in unchanged areas, then RLE-diffs
    vs. old_dither, writing 'out_tmp'.
    """
    cmd = [
        "agz",
        old_no,
        new_no,
        old_dither,
        new_dither,
        out_tmp
    ]
    subprocess.run(cmd, check=True)

def make_agm_agz(
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
    Creates an AGM file with chunked audio/video, but ensures the per-frame
    difference is continuous from the first frame (which is differenced against
    an all-zero file) up through the last frame—i.e., we do NOT re-init at each
    1-second chunk boundary.
    """
    WAV_HEADER_SIZE = 76
    AGM_HEADER_SIZE = 68
    # We'll store our custom AGM header with 16-bit width/height:
    agm_header_fmt = "<6sBHHBII48x"

    AUDIO_MASK = 0x00  # bit7=0 => audio

    # 1) Gather nodither + dithered frames
    nodither_files = sorted(f for f in os.listdir(frames_directory) if f.endswith("_nodither.rgba2"))
    dithered_files = sorted(f for f in os.listdir(frames_directory) if f.endswith("_dithered.rgba2"))

    if len(nodither_files) != len(dithered_files):
        print("Error: mismatch between nodither and dithered frame counts.")
        return

    total_frames = len(nodither_files)
    print("-------------------------------------------------")
    print(f"make_agm_agz: Found {total_frames} no-dither frames in {frames_directory}")

    # 2) Read WAV + fix header
    with open(target_audio_path, "rb") as wf:
        wav_header = wf.read(WAV_HEADER_SIZE)  # 76 bytes
        # Insert "agm" marker at offset 12..14 (to identify the file as .agm)
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
        b"AGNMOV",    # magic 6 bytes
        version,      # 1 byte
        target_width, # 16-bit unsigned
        target_height,# 16-bit unsigned
        frame_rate,   # 1 byte
        total_frames_,# 4 bytes
        total_secs_   # 4 bytes
    )

    # 5) Write .agm file
    target_agm_dir = os.path.dirname(target_agm_path)
    base_name      = os.path.splitext(os.path.basename(target_agm_path))[0]
    outpath        = os.path.join(target_agm_dir, f"{base_name}.agm")
    print(f"Writing AGM to: {outpath}")

    with open(outpath, "wb") as agm_file:
        # Write WAV header + AGM header
        agm_file.write(wav_header)
        agm_file.write(agm_header)

        # --------------------------------------------------------------------
        # Set up zero-frame for the first difference (oldNoDither & oldDithered).
        # We'll create an all-zero file the same size as one .rgba2 frame.
        # This ensures the first real frame is differenced vs. an all-zero array.
        # We won't re-init these across chunk boundaries => continuity is preserved.
        # --------------------------------------------------------------------
        size_test = os.path.getsize(os.path.join(frames_directory, nodither_files[0]))
        zero_frame = os.path.join(frames_directory, "zeroframe.rgba2")
        if not os.path.exists(zero_frame):
            with open(zero_frame, "wb") as zf:
                zf.write(bytes(size_test))  # all 0x00

        old_no_path     = zero_frame
        old_dither_path = zero_frame

        segment_size_last = 0
        frame_idx = 0

        # For each 1-second segment
        for sec in range(total_secs):
            seg_buffer = BytesIO()

            # ---------------- VIDEO UNIT (compressed by 'agz') ----------------
            seg_buffer.write(struct.pack("<B", (VIDEO_MASK)))  # 1-byte unit header

            # For each frame in this second:
            for _ in range(frame_rate):
                if frame_idx < total_frames:
                    new_no_path     = os.path.join(frames_directory, nodither_files[frame_idx])
                    new_dither_path = os.path.join(frames_directory, dithered_files[frame_idx])

                    # 1) Run 'agz' tool => difference-based compression
                    with tempfile.NamedTemporaryFile(delete=False) as tmpout:
                        tmp_compressed = tmpout.name

                    run_agz_diff(
                        old_no_path,       # e.g. "zeroframe.rgba2" for first frame
                        new_no_path,
                        old_dither_path,   # also "zeroframe.rgba2" for first frame
                        new_dither_path,
                        tmp_compressed
                    )

                    # 2) read difference data
                    with open(tmp_compressed, "rb") as f_in:
                        compressed_frame_bytes = f_in.read()
                    os.remove(tmp_compressed)

                    # 3) update "old" => we keep continuity across chunk boundaries
                    old_no_path     = new_no_path
                    old_dither_path = new_dither_path

                    frame_idx += 1
                else:
                    # No frames left => use empty difference
                    compressed_frame_bytes = b""

                # 4) chunk the difference data for the .agm container
                off = 0
                while off < len(compressed_frame_bytes):
                    chunk = compressed_frame_bytes[off : off + chunksize]
                    off += len(chunk)
                    seg_buffer.write(struct.pack("<I", len(chunk)))  # 4-byte chunk size
                    seg_buffer.write(chunk)

            # End of video unit => zero-length chunk
            seg_buffer.write(struct.pack("<I", 0))

            # ---------------- AUDIO UNIT ----------------
            seg_buffer.write(struct.pack("<B", AUDIO_MASK))  # 1-byte => audio
            start_aud = sec * target_sample_rate
            end_aud   = start_aud + target_sample_rate
            unit_audio = audio_data[start_aud:end_aud]

            # Pad if short
            if len(unit_audio) < target_sample_rate:
                unit_audio += b"\x00" * (target_sample_rate - len(unit_audio))

            offset = 0
            while offset < len(unit_audio):
                chunk = unit_audio[offset : offset + chunksize]
                offset += len(chunk)
                seg_buffer.write(struct.pack("<I", len(chunk)))  # chunk size
                seg_buffer.write(chunk)

            # End of audio unit
            seg_buffer.write(struct.pack("<I", 0))

            # -------------- FINALIZE SEGMENT --------------
            segment_data = seg_buffer.getvalue()
            segment_size_this = len(segment_data)
            agm_file.write(struct.pack("<II", segment_size_last, segment_size_this))
            agm_file.write(segment_data)

            segment_size_last = segment_size_this

        print("AGM file creation complete.\n")

#!/usr/bin/env python3
import os
import pygame
import struct
from struct import unpack
from io import BytesIO
import subprocess
import tempfile
import numpy as np

import agonutils as au  # for rgba2_to_img, etc.

WAV_HEADER_SIZE = 76
AGM_HEADER_SIZE = 68
SEGMENT_HEADER_SIZE = 8  # (lastSegmentSize, thisSegmentSize) => 8 bytes total

# For convenience, define compression bit masks (bits 3..4)
# 0b00 = 0 => no compression
# 0b01 = 1 => TurboVega
# 0b10 = 2 => AGZ
# 0b11 = 3 => Szip
COMP_NONE = 0
COMP_TBV  = 1
COMP_AGZ  = 2
COMP_SZIP = 3

def parse_agm_header(header_bytes):
    """
    Parse the 68-byte AGM header with 16-bit width/height fields:
      "<6sBHHBII48x"
        - "AGNMOV" (6 bytes)
        - version (1 byte)
        - width (H = 2 bytes)
        - height (H = 2 bytes)
        - frame_rate (1 byte)
        - total_frames (I = 4 bytes)
        - audio_secs (I = 4 bytes)
        - 48 bytes reserved
    """
    if len(header_bytes) != AGM_HEADER_SIZE:
        raise ValueError(f"AGM header is {len(header_bytes)} bytes, expected {AGM_HEADER_SIZE}")
    fmt = "<6sBHHBII48x"
    magic, version, width, height, fps, total_frames, audio_secs = unpack(fmt, header_bytes)
    if magic != b"AGNMOV":
        raise ValueError("Invalid AGM magic.")
    return {
        "version": version,
        "width": width,
        "height": height,
        "frame_rate": fps,
        "total_frames": total_frames,
        "audio_secs": audio_secs,
    }

def parse_sample_rate_from_wav_header(wav_header_bytes):
    """
    Extract the sample rate from a 76-byte WAV header (with 'agm' at offset 12..14).
    Byte offset 24..27 = sample rate (little-endian).
    """
    if len(wav_header_bytes) != WAV_HEADER_SIZE:
        raise ValueError("WAV header not 76 bytes.")
    if wav_header_bytes[12:15] != b"agm":
        raise ValueError("WAV header does not contain 'agm' marker at offset 12..14.")
    return int.from_bytes(wav_header_bytes[24:28], byteorder='little', signed=False)

def create_wav_file(audio_data, sample_rate, filename):
    """
    Create a temporary PCM WAV file for playback using pygame.mixer.
    8-bit mono => setnchannels(1), setsampwidth(1).
    """
    import wave
    with wave.open(filename, "wb") as wf:
        wf.setnchannels(1)
        wf.setsampwidth(1)  # 8-bit = 1 byte/sample
        wf.setframerate(sample_rate)
        wf.writeframesraw(audio_data)

def decompress_szip_to_ram(compressed_data):
    """
    Decompress entire buffer (which may contain multiple concatenated
    SZIP streams) by calling 'szip -d' in a subprocess.
    Returns the raw decompressed bytes.
    """
    with tempfile.NamedTemporaryFile(delete=False) as tmp_in:
        tmp_in_name = tmp_in.name
        tmp_in.write(compressed_data)

    with tempfile.NamedTemporaryFile(delete=False) as tmp_out:
        tmp_out_name = tmp_out.name

    # Run external szip decompression
    try:
        subprocess.run(["szip", "-d", tmp_in_name, tmp_out_name], check=True)
        with open(tmp_out_name, "rb") as f_out:
            raw = f_out.read()
    finally:
        if os.path.exists(tmp_in_name):
            os.remove(tmp_in_name)
        if os.path.exists(tmp_out_name):
            os.remove(tmp_out_name)

    return raw

def decompress_turbovega_to_ram(compressed_data):
    """
    Decompress TurboVega-compressed frames using an external 'decompress' tool.

    This function takes compressed frame data and passes it to an external
    `decompress` binary to produce raw frame data.

    Parameters:
      compressed_data (bytes): The TurboVega-compressed frame data.

    Returns:
      bytes: The raw decompressed frame data.
    """
    with tempfile.NamedTemporaryFile(delete=False) as tmp_in:
        tmp_in_name = tmp_in.name
        tmp_in.write(compressed_data)

    with tempfile.NamedTemporaryFile(delete=False) as tmp_out:
        tmp_out_name = tmp_out.name

    # Run external TurboVega decompression
    try:
        subprocess.run(["decompress", tmp_in_name, tmp_out_name], check=True)
        with open(tmp_out_name, "rb") as f_out:
            raw = f_out.read()
    finally:
        if os.path.exists(tmp_in_name):
            os.remove(tmp_in_name)
        if os.path.exists(tmp_out_name):
            os.remove(tmp_out_name)

    return raw

def apply_agz_diff_inplace(prev_frame_data, diff_frame_data):
    """
    Interprets 'diff_frame_data' (8-bit palette indexes) as a difference:
       - 0 => unchanged => keep old pixel
       - nonzero => new pixel => override old pixel
    We do this in-place on 'prev_frame_data', using numpy for speed.
    """
    # Both are width*height in size
    arr_prev = np.frombuffer(prev_frame_data, dtype=np.uint8)  # read/write view
    arr_diff = np.frombuffer(diff_frame_data, dtype=np.uint8)   # read-only
    mask = (arr_diff != 0)
    arr_prev[mask] = arr_diff[mask]
    # Now prev_frame_data is updated in-place with the new final frame.


def play_agm(filepath):
    """
    Playback an .agm file chunk by chunk, capturing audio + video frames.
    For the AGZ compression (bits3..4 == 3), we interpret the data as
    difference frames, applying zeros as transparent (no change).
    """
    pygame.init()
    clock = pygame.time.Clock()
    temp_wav = "temp_audio.wav"

    with open(filepath, "rb") as f:
        # 1) Read WAV header & AGM header
        wav_header = f.read(WAV_HEADER_SIZE)
        agm_header = f.read(AGM_HEADER_SIZE)

        # 2) Parse relevant info
        meta = parse_agm_header(agm_header)
        width, height = meta["width"], meta["height"]
        fps          = meta["frame_rate"]
        total_frames = meta["total_frames"]
        audio_secs   = meta["audio_secs"]

        sample_rate = parse_sample_rate_from_wav_header(wav_header)

        print(f"=== AGM HEADER ===\n"
              f"File: {filepath}\n"
              f"Resolution: {width}x{height}\n"
              f"Frame Rate: {fps} fps\n"
              f"Total Frames: {total_frames}\n"
              f"Audio Secs: {audio_secs}\n"
              f"Sample Rate: {sample_rate} Hz\n")

        # Initialize pygame window
        screen = pygame.display.set_mode((width * SCALE_FACTOR, height * SCALE_FACTOR))
        pygame.display.set_caption("AGM Video Player")

        # We'll store the "fully reconstructed" 8-bit frame here
        # (width * height). Start with all zeros => black/empty.
        prev_frame_data = bytearray(width * height)

        frame_idx = 0
        # 3) Read segments until we run out
        while True:
            seg_header = f.read(SEGMENT_HEADER_SIZE)
            if len(seg_header) < SEGMENT_HEADER_SIZE:
                print("End of file (no more segment headers).")
                break

            seg_size_last, seg_size_this = struct.unpack("<II", seg_header)
            if seg_size_this == 0:
                print(f"\nSegment size=0 => skipping or end.")
                continue

            print(f"\nSegment: lastSize={seg_size_last}, thisSize={seg_size_this}")

            segment_data = f.read(seg_size_this)
            if len(segment_data) < seg_size_this:
                print("File ended unexpectedly in the middle of a segment.")
                break

            seg_stream = BytesIO(segment_data)

            # Typically: 1 video unit + 1 audio unit in each segment
            while seg_stream.tell() < seg_size_this:
                unit_mask_b = seg_stream.read(1)
                if not unit_mask_b:
                    break
                unit_mask = unit_mask_b[0]

                is_video = bool(unit_mask & 0x80)
                comp_type = (unit_mask & 0x18) >> 3  # bits3..4

                if is_video:
                    print(f"Unit: VIDEO (mask=0x{unit_mask:02X}), comp_type={comp_type}")
                    video_unit_buffer = b""
                    # Gather chunk data until chunk_size=0
                    while True:
                        csize_data = seg_stream.read(4)
                        if len(csize_data) < 4:
                            print("Ran out of data reading VIDEO chunk size.")
                            break
                        csize = struct.unpack("<I", csize_data)[0]
                        if csize == 0:
                            print("End of VIDEO unit.\n")
                            break

                        chunk_data = seg_stream.read(csize)
                        if len(chunk_data) < csize:
                            # truncated => pad
                            chunk_data += b"\x00" * (csize - len(chunk_data))

                        video_unit_buffer += chunk_data

                    # Decompress or interpret
                    frame_size = width * height
                    if comp_type == COMP_NONE:
                        # raw frames => for demonstration, we assume 1-second chunk => fps frames
                        # each frame is exactly 'frame_size' bytes
                        raw_frames = video_unit_buffer
                    elif comp_type == COMP_TBV:
                        # example: old TurboVega path
                        raw_frames = decompress_turbovega_to_ram(video_unit_buffer)
                    elif comp_type == COMP_SZIP:
                        # example: old SZIP path
                        raw_frames = decompress_szip_to_ram(video_unit_buffer)
                    elif comp_type == COMP_AGZ:
                        # We'll treat "bits3..4 == 3" as AGZ difference frames
                        # In many .agm encoders, each "frame" might be stored sequentially,
                        # so we can read them in multiples of 'frame_size' from the decompressed data.
                        # HOWEVER, your "AGZ" isn't standard; you've stored difference data *directly*
                        # in the .agm. If so, there's no separate decompress step. It's already RLE
                        # expanded. For a minimal approach, we'll assume 'video_unit_buffer' is *already*
                        # the raw difference frames (width*height * fps).
                        # In a real design, you'd do RLE decode here if your AGZ was truly compressed data.
                        
                        # For demonstration, let's assume your 'agz' tool left them as raw difference frames:
                        raw_frames = video_unit_buffer
                    else:
                        print("Unknown compression type, ignoring video.")
                        raw_frames = b""

                    # Now parse out 'fps' frames from 'raw_frames'
                    offset = 0
                    for _ in range(fps):
                        if (offset + frame_size) > len(raw_frames):
                            print("No more frames to extract from video data.")
                            break
                        diff_frame = raw_frames[offset: offset + frame_size]
                        offset += frame_size

                        # If comp_type == AGZ => interpret 'diff_frame' as a difference
                        #  - For each pixel: if diff_frame[i] != 0 => override old pixel
                        # We do that in a single numpy operation:
                        if comp_type == COMP_AGZ:
                            apply_agz_diff_inplace(prev_frame_data, diff_frame)
                        else:
                            # If no difference approach => we just treat it as the new final
                            prev_frame_data[:] = diff_frame

                        # Now 'prev_frame_data' is the final frame (8-bit indexes) we want to display.
                        # Convert to .rgba2 => PNG => load into pygame
                        rgba2_path = "temp_frame.rgba2"
                        with open(rgba2_path, "wb") as tmpf:
                            tmpf.write(prev_frame_data)

                        png_out = "temp_frame.png"
                        au.rgba2_to_img(rgba2_path, png_out, width, height)
                        os.remove(rgba2_path)

                        frame_surface = pygame.image.load(png_out)
                        os.remove(png_out)

                        # Show in pygame
                        screen.blit(
                            pygame.transform.scale(frame_surface, (width * SCALE_FACTOR, height * SCALE_FACTOR)),
                            (0, 0)
                        )
                        pygame.display.flip()

                        frame_idx += 1
                        if frame_idx >= total_frames:
                            print("Reached total_frames => stopping video playback.")
                            break

                        for event in pygame.event.get():
                            if event.type == pygame.QUIT:
                                pygame.quit()
                                if os.path.exists(temp_wav):
                                    os.remove(temp_wav)
                                return

                        clock.tick(fps)

                        if frame_idx >= total_frames:
                            break

                else:
                    # Audio unit
                    print(f"Unit: AUDIO (mask=0x{unit_mask:02X})")
                    audio_buffer = b""
                    while True:
                        csize_data = seg_stream.read(4)
                        if len(csize_data) < 4:
                            print("Ran out of data reading AUDIO chunk size.")
                            break
                        csize = struct.unpack("<I", csize_data)[0]
                        if csize == 0:
                            print("End of AUDIO unit.\n")
                            break

                        chunk_data = seg_stream.read(csize)
                        if len(chunk_data) < csize:
                            chunk_data += b"\x00" * (csize - len(chunk_data))
                        audio_buffer += chunk_data

                    # That is up to 1 second of audio => sample_rate bytes
                    if audio_buffer:
                        create_wav_file(audio_buffer[:sample_rate], sample_rate, temp_wav)
                        snd = pygame.mixer.Sound(temp_wav)
                        snd.play()

            if frame_idx >= total_frames:
                print("Displayed all frames. Stopping.")
                break

        print("\nPlayback completed.")

    pygame.quit()
    if os.path.exists(temp_wav):
        os.remove(temp_wav)

SCALE_FACTOR = 1

# Quick test if needed
if __name__ == "__main__":
    agm_path = "tgt/video/Star_Wars__Battle_of_Yavin_floyd_agz.agm"
    # agm_path = "tgt/video/Star_Wars__Battle_of_Yavin_bayer.agm"
    # agm_path = "tgt/video/Star_Wars__Battle_of_Yavin_RGB.agm"
    if not os.path.exists(agm_path):
        print(f"Error: AGM file not found at '{agm_path}'")
    else:
        print(f"Playing: {agm_path}")
        play_agm(agm_path)

#!/usr/bin/env python3
import os
import pygame
import struct
from struct import unpack
from io import BytesIO
import subprocess
import tempfile

import agonutils as au  # for rgba2_to_img, etc.

WAV_HEADER_SIZE = 76
AGM_HEADER_SIZE = 68
SEGMENT_HEADER_SIZE = 8  # (lastSegmentSize, thisSegmentSize) => 8 bytes total

# For convenience, define compression bit masks (bits 3..4)
# 0b00 = 0 => no compression
# 0b01 = 1 => TurboVega
# 0b10 = 2 => RLE
# 0b11 = 3 => Szip
COMP_NONE = 0
COMP_TBV  = 1
COMP_RLE  = 2
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

def decompress_rle_to_ram(compressed_data):
    """
    Stub for RLE decompression.
    For now, raise NotImplementedError.
    """
    raise NotImplementedError("RLE decompression not yet implemented.")

def play_agm(filepath):
    """
    Reads the .agm file with units:
      - WAV header (76 bytes) + "agm" marker
      - AGM header (68 bytes)
      - Multiple segments:
         * 8-byte segment header <II>
         * Audio unit (mask bit7=0), chunked data => chunk_size=0 ends
         * Video unit (mask bit7=1), chunked data => chunk_size=0 ends
           - Check bits3..4 for compression type:
             00 => no compression
             01 => TurboVega
             10 => RLE
             11 => Szip
    Then parse frames from either raw or decompressed data.
    """
    pygame.init()
    clock = pygame.time.Clock()
    temp_wav = "temp_audio.wav"

    # Open .agm file
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
        screen = pygame.display.set_mode((width * 4, height * 4))
        pygame.display.set_caption("AGM Video Player")

        frame_idx = 0

        # 3) Read segments until we run out
        while True:
            # Read next segment header (8 bytes)
            seg_header = f.read(SEGMENT_HEADER_SIZE)
            if len(seg_header) < SEGMENT_HEADER_SIZE:
                print("End of file (no more segment headers).")
                break

            seg_size_last, seg_size_this = struct.unpack("<II", seg_header)
            if seg_size_this == 0:
                # Usually signals no more segments or abnormal data
                print(f"\nSegment size=0 => skipping.")
                continue

            print(f"\nSegment: lastSize={seg_size_last}, thisSize={seg_size_this}")

            # Read this segment's data
            segment_data = f.read(seg_size_this)
            if len(segment_data) < seg_size_this:
                print("File ended unexpectedly in the middle of a segment.")
                break

            seg_stream = BytesIO(segment_data)

            # There should be 2 units each segment: audio + video (but we'll parse generically)
            while seg_stream.tell() < seg_size_this:
                unit_mask_b = seg_stream.read(1)
                if not unit_mask_b:
                    # no more data in this segment
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
                            # End of video unit
                            print("End of VIDEO unit.\n")
                            break

                        chunk_data = seg_stream.read(csize)
                        if len(chunk_data) < csize:
                            # File truncated or segment malformed, pad with zeros
                            chunk_data += b"\x00" * (csize - len(chunk_data))

                        video_unit_buffer += chunk_data

                    if len(video_unit_buffer) > 0:
                        # Decompress if needed
                        if comp_type == COMP_NONE:
                            # No compression => raw RGBA2 frames
                            raw_frames = video_unit_buffer
                        elif comp_type == COMP_TBV:
                            print("TurboVega compression stub.")
                            raw_frames = decompress_turbovega_to_ram(video_unit_buffer)
                        elif comp_type == COMP_RLE:
                            print("RLE compression stub.")
                            raw_frames = decompress_rle_to_ram(video_unit_buffer)
                        elif comp_type == COMP_SZIP:
                            print("SZIP compression => calling szip -d externally.")
                            raw_frames = decompress_szip_to_ram(video_unit_buffer)
                        else:
                            raw_frames = b""

                        # Each frame = width * height bytes
                        offset = 0
                        frame_size = width * height
                        for _ in range(fps):
                            if offset + frame_size > len(raw_frames):
                                print("No more frames to extract from video data.")
                                break
                            one_frame = raw_frames[offset : offset + frame_size]
                            offset += frame_size

                            # Convert RGBA2 raw to a PNG or surface
                            rgba2_path = "temp_frame.rgba2"
                            with open(rgba2_path, "wb") as tmpf:
                                tmpf.write(one_frame)

                            png_out = "temp_frame.png"
                            au.rgba2_to_img(rgba2_path, png_out, width, height)

                            os.remove(rgba2_path)
                            frame_surface = pygame.image.load(png_out)
                            os.remove(png_out)

                            # Scale 4x, display
                            screen.blit(
                                pygame.transform.scale(frame_surface, (width * 4, height * 4)), 
                                (0, 0)
                            )
                            pygame.display.flip()

                            frame_idx += 1
                            if frame_idx >= total_frames:
                                print("Reached total_frames => stopping video playback.")
                                break

                            # Allow quit
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
                            # End of audio unit
                            print("End of AUDIO unit.\n")
                            break

                        chunk_data = seg_stream.read(csize)
                        if len(chunk_data) < csize:
                            chunk_data += b"\x00" * (csize - len(chunk_data))

                        audio_buffer += chunk_data

                    # Now play that second of audio
                    # The encoder wrote up to 1 second => sample_rate bytes
                    if audio_buffer:
                        create_wav_file(audio_buffer[:sample_rate], sample_rate, temp_wav)
                        snd = pygame.mixer.Sound(temp_wav)
                        snd.play()

            if frame_idx >= total_frames:
                print("Displayed all frames. Stopping.")
                break

        print("\nPlayback completed.")
        f.close()

    pygame.quit()
    if os.path.exists(temp_wav):
        os.remove(temp_wav)

# Quick test if needed
if __name__ == "__main__":
    agm_path = "tgt/video/Star_Wars__Battle_of_Yavin_floyd.agm"
    if not os.path.exists(agm_path):
        print(f"Error: AGM file not found at '{agm_path}'")
    else:
        print(f"Playing: {agm_path}")
        play_agm(agm_path)

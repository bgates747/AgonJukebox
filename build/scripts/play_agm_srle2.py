#!/usr/bin/env python3
import os
import struct
import subprocess
import tempfile
from io import BytesIO
import pygame
import concurrent.futures
import time

import agonutils as au  # for rgba2_to_img, etc.

WAV_HEADER_SIZE = 76
AGM_HEADER_SIZE = 68
SEGMENT_HEADER_SIZE = 8  # (lastSegmentSize, thisSegmentSize)

# Compression type constants
COMP_NONE  = 0
COMP_SRLE2 = 3

# Video unit mask (SRLE2 compression)
AGM_UNIT_TYPE      = 0b10000000  # Bit 7: video unit
AGM_UNIT_CMP_SRLE2 = 0b00011000  # Bits 3-4: SRLE2 compression (should equal 3)
VIDEO_MASK = AGM_UNIT_TYPE | AGM_UNIT_CMP_SRLE2

SCALE_FACTOR = 1

def parse_agm_header(header_bytes):
    """
    Parse the 68-byte AGM header with 16-bit width/height fields:
      Format: "<6sBHHBII48x"
    """
    if len(header_bytes) != AGM_HEADER_SIZE:
        raise ValueError(f"AGM header is {len(header_bytes)} bytes, expected {AGM_HEADER_SIZE}")
    fmt = "<6sBHHBII48x"
    magic, version, width, height, fps, total_frames, audio_secs = struct.unpack(fmt, header_bytes)
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
    """
    if len(wav_header_bytes) != WAV_HEADER_SIZE:
        raise ValueError("WAV header not 76 bytes.")
    if wav_header_bytes[12:15] != b"agm":
        raise ValueError("WAV header does not contain 'agm' marker at offset 12..14.")
    return int.from_bytes(wav_header_bytes[24:28], byteorder='little', signed=False)

def create_wav_file(audio_data, sample_rate, filename):
    """
    Create a temporary PCM WAV file for playback using pygame.mixer.
    """
    import wave
    with wave.open(filename, "wb") as wf:
        wf.setnchannels(1)
        wf.setsampwidth(1)  # 8-bit
        wf.setframerate(sample_rate)
        wf.writeframesraw(audio_data)

def decompress_srle2_to_ram(compressed_data):
    """
    Decompress the SRLE2-compressed block in two steps:
      1. Run szip -d on the entire compressed block.
      2. Run rle2 -d on the resulting file.
    Returns the final uncompressed frame data.
    """
    with tempfile.NamedTemporaryFile(delete=False) as tmp_in:
        tmp_in.write(compressed_data)
        tmp_in_name = tmp_in.name

    with tempfile.NamedTemporaryFile(delete=False) as tmp_szip:
        tmp_szip_name = tmp_szip.name

    try:
        subprocess.run(["szip", "-d", tmp_in_name, tmp_szip_name], check=True)
    except subprocess.CalledProcessError as e:
        os.remove(tmp_in_name)
        os.remove(tmp_szip_name)
        raise e

    with open(tmp_szip_name, "rb") as f:
        szip_data = f.read()
    os.remove(tmp_in_name)
    os.remove(tmp_szip_name)
    rle2_input_data = szip_data

    with tempfile.NamedTemporaryFile(delete=False) as tmp_rle2_in:
        tmp_rle2_in.write(rle2_input_data)
        tmp_rle2_in_name = tmp_rle2_in.name

    with tempfile.NamedTemporaryFile(delete=False) as tmp_rle2_out:
        tmp_rle2_out_name = tmp_rle2_out.name

    try:
        subprocess.run(["rle2", "-d", tmp_rle2_in_name, tmp_rle2_out_name], check=True)
    except subprocess.CalledProcessError as e:
        os.remove(tmp_rle2_in_name)
        os.remove(tmp_rle2_out_name)
        raise e

    os.remove(tmp_rle2_in_name)
    with open(tmp_rle2_out_name, "rb") as f_out:
        final_data = f_out.read()
    os.remove(tmp_rle2_out_name)
    return final_data

def read_next_segment(f):
    """
    Reads the next segment header and segment data from file f.
    Returns the segment data as bytes (or None if no complete segment is found).
    """
    seg_header = f.read(SEGMENT_HEADER_SIZE)
    if not seg_header or len(seg_header) < SEGMENT_HEADER_SIZE:
        return None
    _, seg_size = struct.unpack("<II", seg_header)
    seg_data = f.read(seg_size)
    if len(seg_data) < seg_size:
        return None
    return seg_data

def process_segment(segment_data, width, height, fps):
    """
    Process one segment (assumed to represent one second of video & audio).
    Unpacks the video unit, decompresses it, and splits it into individual frames.
    Also extracts the audio unit data.
    Returns (frames, audio_data) where frames is a list of bytes (each frame is width*height bytes).
    """
    seg_stream = BytesIO(segment_data)
    # --- Process video unit ---
    unit_mask = seg_stream.read(1)[0]
    comp_type = (unit_mask & 0x18) >> 3
    video_unit_buffer = b""
    while True:
        csize_data = seg_stream.read(4)
        if len(csize_data) < 4:
            break
        csize = struct.unpack("<I", csize_data)[0]
        if csize == 0:
            break
        video_unit_buffer += seg_stream.read(csize)
    if comp_type == COMP_NONE:
        raw_video_data = video_unit_buffer
    elif comp_type == COMP_SRLE2:
        raw_video_data = decompress_srle2_to_ram(video_unit_buffer)
    else:
        print("Unsupported video compression type.")
        raw_video_data = b""
    frame_size = width * height
    frames = []
    total_bytes = len(raw_video_data)
    expected_bytes = fps * frame_size
    if total_bytes < expected_bytes:
        num_frames = total_bytes // frame_size
    else:
        num_frames = fps
    for i in range(num_frames):
        start = i * frame_size
        end = start + frame_size
        frames.append(raw_video_data[start:end])
    # --- Process audio unit ---
    # Read next byte: should be the audio unit mask.
    audio_unit_mask_byte = seg_stream.read(1)
    audio_buffer = b""
    if audio_unit_mask_byte:
        # Normally, audio unit mask is 0x00.
        while True:
            csize_data = seg_stream.read(4)
            if len(csize_data) < 4:
                break
            csize = struct.unpack("<I", csize_data)[0]
            if csize == 0:
                break
            audio_buffer += seg_stream.read(csize)
    return frames, audio_buffer

def play_agm(filepath):
    """
    Play an AGM file using the new segment logic:
      - For each segment (one second of video/audio):
          * Unpack and decompress the entire video unit into individual frames.
          * Extract the audio unit.
      - Start audio playback immediately and display the video frames at the correct frame rate.
      - While one segment is playing, prefetch and process the next segment in a background thread.
    """
    pygame.init()
    clock = pygame.time.Clock()
    temp_wav = "temp_audio.wav"

    with open(filepath, "rb") as f:
        # Read WAV header & AGM header.
        wav_header = f.read(WAV_HEADER_SIZE)
        agm_header = f.read(AGM_HEADER_SIZE)
        meta = parse_agm_header(agm_header)
        width = meta["width"]
        height = meta["height"]
        fps = meta["frame_rate"]
        total_frames = meta["total_frames"]
        audio_secs = meta["audio_secs"]
        sample_rate = parse_sample_rate_from_wav_header(wav_header)

        print(f"=== AGM HEADER ===\n"
              f"File: {filepath}\n"
              f"Resolution: {width}x{height}\n"
              f"Frame Rate: {fps} fps\n"
              f"Total Frames: {total_frames}\n"
              f"Audio Secs: {audio_secs}\n"
              f"Sample Rate: {sample_rate} Hz\n")

        screen = pygame.display.set_mode((width * SCALE_FACTOR, height * SCALE_FACTOR))
        pygame.display.set_caption("AGM Video Player")

        # Create a ThreadPoolExecutor for pre-processing segments.
        executor = concurrent.futures.ThreadPoolExecutor(max_workers=1)

        def read_and_process_next_segment():
            seg_data = read_next_segment(f)
            if seg_data is None:
                return None
            return process_segment(seg_data, width, height, fps)

        # Prefetch the first segment.
        current_result = read_and_process_next_segment()
        if current_result is None:
            print("No segments found.")
            return
        # Start prefetching the next segment concurrently.
        future = executor.submit(read_and_process_next_segment)

        running = True
        while running and current_result is not None:
            frames, audio_data = current_result
            # Start audio playback immediately (if audio data exists).
            if audio_data:
                create_wav_file(audio_data, sample_rate, temp_wav)
                snd = pygame.mixer.Sound(temp_wav)
                snd.play()

            # Display each frame for 1/fps seconds.
            for frame_data in frames:
                # Convert raw frame (RGBA2 format) to an image.
                temp_rgba2 = "temp_frame.rgba2"
                with open(temp_rgba2, "wb") as tf:
                    tf.write(frame_data)
                temp_png = "temp_frame.png"
                au.rgba2_to_img(temp_rgba2, temp_png, width, height)
                os.remove(temp_rgba2)
                frame_surface = pygame.image.load(temp_png)
                os.remove(temp_png)

                scaled = pygame.transform.scale(frame_surface, (width * SCALE_FACTOR, height * SCALE_FACTOR))
                screen.blit(scaled, (0, 0))
                pygame.display.flip()
                clock.tick(fps)

                # Process events.
                for event in pygame.event.get():
                    if event.type == pygame.QUIT:
                        running = False
                        break
                if not running:
                    break

            # Wait for the next segment to finish processing.
            try:
                current_result = future.result(timeout=5)
            except Exception as e:
                print("Error processing next segment:", e)
                break
            # Start prefetching the subsequent segment.
            if current_result is not None:
                future = executor.submit(read_and_process_next_segment)

        print("Playback complete.")
    pygame.quit()
    if os.path.exists(temp_wav):
        os.remove(temp_wav)

if __name__ == "__main__":
    agm_path = "tgt/video/Star_Wars__Battle_of_Yavin_bayer.agm"
    if not os.path.exists(agm_path):
        print(f"Error: AGM file not found at '{agm_path}'")
    else:
        print(f"Playing: {agm_path}")
        play_agm(agm_path)

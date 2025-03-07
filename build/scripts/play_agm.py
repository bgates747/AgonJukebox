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
COMP_NONE   = 0
COMP_TVC    = 2
COMP_SRLE2  = 3

# Video unit mask (SRLE2 compression by default, though unit headers determine compression)
AGM_UNIT_TYPE      = 0b10000000  # Bit 7: video unit if set; audio unit otherwise
AGM_UNIT_CMP_SRLE2 = 0b00011000  # Bits 3-4: SRLE2 compression (should equal 3)
AGM_UNIT_CMP_TVC   = 0b00010000  # Bit 4: TurboVega compression (bit 4 set)
VIDEO_MASK = AGM_UNIT_TYPE | AGM_UNIT_CMP_SRLE2

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

def decompress_tvc_to_ram(compressed_data):
    """
    Decompress the TVC-compressed block.
    Returns the final uncompressed frame data.
    """
    with tempfile.NamedTemporaryFile(delete=False) as tmp_in:
        tmp_in.write(compressed_data)
        tmp_in_name = tmp_in.name

    with tempfile.NamedTemporaryFile(delete=False) as tmp_tvc:
        tmp_tvc_name = tmp_tvc.name

    try:
        subprocess.run(["tvc", "-d", tmp_in_name, tmp_tvc_name], check=True)
    except subprocess.CalledProcessError as e:
        os.remove(tmp_in_name)
        os.remove(tmp_tvc_name)
        raise e

    with open(tmp_tvc_name, "rb") as f:
        final_data = f.read()

    os.remove(tmp_in_name)
    os.remove(tmp_tvc_name)
    return final_data

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

    # The seg_size ALREADY INCLUDES the header size (8 bytes),
    # so subtract SEGMENT_HEADER_SIZE to read only the payload.
    payload_size = seg_size - SEGMENT_HEADER_SIZE

    seg_data = f.read(payload_size)
    if len(seg_data) < payload_size:
        return None
    return seg_data

def process_segment(segment_data, width, height, fps):
    """
    Process one segment by reading all unit headers and their associated chunk data.
    A segment may contain multiple video units (each with its own unit header and chunks)
    and one (or more) audio unit.
    
    For each unit:
      - Read 1 byte header.
      - Read chunks (each chunk: 4-byte size then chunk data) until a zero-length chunk.
      - For video units (header with bit 7 set), decompress if needed and extract a frame.
      - For audio units (header with bit 7 clear), accumulate the audio data.
    
    Returns a tuple (video_frames, audio_data) where video_frames is a list of raw frames,
    and audio_data is the accumulated audio bytes for the segment.
    """
    seg_stream = BytesIO(segment_data)
    video_frames = []
    audio_buffer = b""
    
    while seg_stream.tell() < len(segment_data):
        # Read the unit header (1 byte). If none available, break.
        unit_header_data = seg_stream.read(1)
        if not unit_header_data:
            break
        unit_mask = unit_header_data[0]
        comp_type = (unit_mask & 0x18) >> 3  # Extract compression bits

        # Read all chunks for this unit.
        unit_data = b""
        while True:
            csize_data = seg_stream.read(4)
            if len(csize_data) < 4:
                break
            chunk_size = struct.unpack("<I", csize_data)[0]
            if chunk_size == 0:
                break
            unit_data += seg_stream.read(chunk_size)

        # Process based on the unit type.
        if unit_mask & 0x80:  # Video unit
            if comp_type == COMP_NONE:
                raw_video_data = unit_data
            elif comp_type == COMP_TVC:
                raw_video_data = decompress_tvc_to_ram(unit_data)
            elif comp_type == COMP_SRLE2:
                raw_video_data = decompress_srle2_to_ram(unit_data)
            else:
                print("Unsupported video compression type.")
                raw_video_data = b""
            frame_size = width * height
            # Ensure we have a full frame; pad if needed.
            if len(raw_video_data) < frame_size:
                frame_data = raw_video_data + b"\x00" * (frame_size - len(raw_video_data))
            else:
                frame_data = raw_video_data[:frame_size]
            video_frames.append(frame_data)
        else:
            # Audio unit (assumed uncompressed in AGM files)
            audio_buffer += unit_data

    return video_frames, audio_buffer

def play_agm(filepath):
    """
    Play an AGM file using the updated segment logic:
      - For each segment, read and process all unit headers to accumulate the full video and audio data.
      - Once a full segment is accumulated, start audio playback (if any) and display the video frames sequentially.
      - Prefetch and process the next segment concurrently.
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
            video_frames, audio_data = current_result

            # Start audio playback immediately (if audio data exists).
            if audio_data:
                create_wav_file(audio_data, sample_rate, temp_wav)
                snd = pygame.mixer.Sound(temp_wav)
                snd.play()

            # Display each video frame for 1/fps seconds.
            for frame_data in video_frames:
                # Convert raw frame (assumed to be in RGBA2 format) to an image.
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

SCALE_FACTOR = 2

if __name__ == "__main__":
    agm_path = "tgt/video/Star_Wars__Battle_of_Yavin_floyd.agm"
    agm_path = "tgt/video/Star_Wars__Battle_of_Yavin_bayer.agm"
    # agm_path = "tgt/video/Star_Wars__Battle_of_Yavin_rgb.agm"
    if not os.path.exists(agm_path):
        print(f"Error: AGM file not found at '{agm_path}'")
    else:
        print(f"Playing: {agm_path}")
        play_agm(agm_path)

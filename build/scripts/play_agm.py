#!/usr/bin/env python3
import os
import pygame
from struct import unpack
import math

import agonutils as au  # for rgba2_to_img, etc.

WAV_HEADER_SIZE = 76
AGM_HEADER_SIZE = 68
TOTAL_HEADER_SIZE = AGM_HEADER_SIZE + WAV_HEADER_SIZE  # 144 bytes


def parse_agm_header(header_bytes):
    """
    Parse the 68-byte AGM header.
      offset layout:
      0..5:   "AGNMOV"
      6:      version (1 byte)
      7:      width   (1 byte)
      8:      height  (1 byte)
      9:      fps     (1 byte)
      10..13: total_frames (4 bytes)
      14..17: audio_secs   (4 bytes, integer)
      18..67: reserved
    """
    if len(header_bytes) != AGM_HEADER_SIZE:
        raise ValueError(f"AGM header is {len(header_bytes)} bytes, expected {AGM_HEADER_SIZE}")
    fmt = "<6sBBBBII50x"
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
    Expects a 76-byte 'WAV' header (with 'agm' at offset 12..14).
    Extracts the sample rate at offset 24..27 (4 bytes, little-endian).
    """
    if len(wav_header_bytes) != 76:
        raise ValueError("WAV header not 76 bytes.")
    if wav_header_bytes[12:15] != b"agm":
        raise ValueError("WAV header does not contain 'agm' marker at offset 12..14.")
    sample_rate = int.from_bytes(wav_header_bytes[24:28], byteorder='little', signed=False)
    return sample_rate


def create_1sec_wav_file(audio_data, sample_rate, filename):
    """
    Given up to 1 second of 8-bit mono audio_data (length <= sample_rate),
    create a small PCM WAV file so Pygame can load & play it.
    """
    import wave
    with wave.open(filename, "wb") as wf:
        wf.setnchannels(1)
        wf.setsampwidth(1)        # 8-bit = 1 byte/sample
        wf.setframerate(sample_rate)
        wf.writeframesraw(audio_data)


def play_agm(filepath):
    """
    Reads the .agm file in 1-second blocks:
      1) sample_rate bytes of audio
      2) frame_rate frames, each width*height bytes (RGBA2)
    Decodes & displays frames in real-time, playing audio via pygame.
    """
    pygame.init()
    clock = pygame.time.Clock()

    temp_wav = "tgt/temp_audio.wav"

    with open(filepath, "rb") as f:
        # 1) Read headers
        wav_header = f.read(WAV_HEADER_SIZE)
        agm_header = f.read(AGM_HEADER_SIZE)

        meta = parse_agm_header(agm_header)
        width       = meta["width"]
        height      = meta["height"]
        fps         = meta["frame_rate"]
        total_frames= meta["total_frames"]
        audio_secs  = meta["audio_secs"]  # total length (integer seconds)
        sample_rate = parse_sample_rate_from_wav_header(wav_header)

        print("=== AGM HEADER ===")
        print(f"File:         {filepath}")
        print(f"Resolution:   {width}x{height}")
        print(f"Frame Rate:   {fps} fps")
        print(f"Total Frames: {total_frames}")
        print(f"Audio Secs:   {audio_secs}")
        print(f"Sample Rate:  {sample_rate} bytes/s (8-bit mono)\n")

        # For safety, compute how many seconds we must play from the header:
        total_secs = audio_secs
        # Each frame is width*height bytes in your RGBA2 data:
        frame_size = width * height

        # Prepare the Pygame window
        scale_factor = 4
        screen = pygame.display.set_mode((width * scale_factor, height * scale_factor))
        pygame.display.set_caption("AGM Video Player")

        frame_idx = 0  # which frame are we on in the entire video?

        # 2) Read data one second at a time
        for sec_idx in range(total_secs):
            print(f"\rPlaying second {sec_idx+1}/{total_secs}...", end="")

            # -- (a) Read 1 second of audio (sample_rate bytes) --
            audio_chunk = f.read(sample_rate)
            if len(audio_chunk) < sample_rate:
                # If short, pad with silence
                audio_chunk += b"\x00" * (sample_rate - len(audio_chunk))

            # Write to a small .wav so pygame can handle it
            create_1sec_wav_file(audio_chunk[:sample_rate], sample_rate, temp_wav)

            # Play it immediately
            sound = pygame.mixer.Sound(temp_wav)
            sound.play()

            # -- (b) Display frames for this second (fps frames) --
            for _ in range(fps):
                # Handle events (allow user to quit)
                for event in pygame.event.get():
                    if event.type == pygame.QUIT:
                        pygame.quit()
                        if os.path.exists(temp_wav):
                            os.remove(temp_wav)
                        return

                # If we've run out of frames, display a blank frame
                if frame_idx >= total_frames:
                    # Just fill screen with black
                    screen.fill((0, 0, 0))
                    pygame.display.flip()
                else:
                    # Read frame_size bytes from the file
                    frame_data = f.read(frame_size)
                    if len(frame_data) < frame_size:
                        # If short, pad with zeros => black
                        frame_data += b"\x00" * (frame_size - len(frame_data))

                    # Write a temp .rgba2, convert => display
                    rgba2_path = "temp_frame.rgba2"
                    with open(rgba2_path, "wb") as tmpf:
                        tmpf.write(frame_data)

                    png_out = "temp_frame.png"
                    au.rgba2_to_img(rgba2_path, png_out, width, height)

                    frame_surface = pygame.image.load(png_out)

                    os.remove(rgba2_path)
                    os.remove(png_out)

                    # Scale up the frame for display
                    scaled_surface = pygame.transform.scale(
                        frame_surface, (width * scale_factor, height * scale_factor)
                    )
                    screen.blit(scaled_surface, (0, 0))
                    pygame.display.flip()

                    frame_idx += 1

                # Wait enough time to space frames out over 1 second => 1000/fps
                clock.tick(fps)

        print("\nPlayback completed.")
        f.close()

    pygame.quit()
    if os.path.exists(temp_wav):
        os.remove(temp_wav)

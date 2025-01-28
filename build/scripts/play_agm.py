#!/usr/bin/env python3
import os
import pygame
from struct import unpack

import agonutils as au  # for rgba2_to_img, etc.

AGM_HEADER_SIZE = 68
WAV_HEADER_SIZE = 76
TOTAL_HEADER_SIZE = AGM_HEADER_SIZE + WAV_HEADER_SIZE

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
      14..17: audio_secs   (4 bytes)
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
    """Reads sample rate from standard WAV header offset 24..27."""
    if len(wav_header_bytes) != WAV_HEADER_SIZE:
        raise ValueError("WAV header not 76 bytes.")
    return int.from_bytes(wav_header_bytes[24:28], byteorder='little', signed=False)

def create_1sec_wav_file(audio_data, sample_rate, filename="temp_1sec.wav"):
    """
    Given 1 second of 8-bit mono audio_data (length == sample_rate),
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
    Reads the .agm in 60 lumps/second, accumulates 1 second of audio lumps,
    then writes/plays a 1-second WAV via Pygame. Video frames are scaled 4×.
    No interpolation is used (nearest neighbor).
    """
    pygame.init()
    clock = pygame.time.Clock()

    with open(filepath, "rb") as f:
        # 1) Read headers
        agm_header = f.read(AGM_HEADER_SIZE)
        wav_header = f.read(WAV_HEADER_SIZE)

        meta = parse_agm_header(agm_header)

        width       = meta["width"]
        height      = meta["height"]
        fps         = meta["frame_rate"]
        total_frames= meta["total_frames"]
        audio_secs  = meta["audio_secs"]  # total length in integer seconds
        sample_rate = parse_sample_rate_from_wav_header(wav_header)

        print("=== AGM HEADER ===")
        print(f"File:        {filepath}")
        print(f"Resolution:  {width}x{height}")
        print(f"Frame Rate:  {fps} fps")
        print(f"Total Frames:{total_frames}")
        print(f"Audio Secs:  {audio_secs}")
        print(f"Sample Rate: {sample_rate} bytes/s (8-bit mono)\n")

        # 2) Data layout: 60 lumps/sec
        lumps_per_second = 60
        lumps_per_frame = lumps_per_second // fps  # must be integer if your format is correct

        frame_bytes       = width * height
        frames_per_second = fps
        video_bytes_per_sec = frame_bytes * frames_per_second
        audio_bytes_per_sec = sample_rate
        total_bytes_per_sec = video_bytes_per_sec + audio_bytes_per_sec

        chunk_size = total_bytes_per_sec // lumps_per_second  # must be integer
        frame_bytes_per_frame = frame_bytes
        frame_bytes_per_lump  = frame_bytes_per_frame // lumps_per_frame
        audio_bytes_per_lump  = audio_bytes_per_sec  // lumps_per_second

        print("--- Computed Data Layout ---")
        print(f"lumps_per_second:    {lumps_per_second}")
        print(f"lumps_per_frame:     {lumps_per_frame}")
        print(f"chunk_size:          {chunk_size}")
        print(f"frame_bytes_per_sec: {video_bytes_per_sec}")
        print(f"audio_bytes_per_sec: {audio_bytes_per_sec}")
        print(f"frame_bytes_per_lump:{frame_bytes_per_lump}")
        print(f"audio_bytes_per_lump:{audio_bytes_per_lump}")
        print("--------------------------------")

        # 3) Prepare Pygame window, scaled 4× with no interpolation
        scale_factor = 3
        screen = pygame.display.set_mode((width * scale_factor, height * scale_factor))
        pygame.display.set_caption("AGM Video Player (4x nearest)")

        total_secs = audio_secs
        lumps_total = total_secs * lumps_per_second

        frame_index = 0
        lumps_in_current_frame = 0
        partial_frame_data = bytearray()

        # We'll read in "one second" increments, 60 lumps each.
        for second_idx in range(total_secs):
            print(f"\rElapsed time: {second_idx+1}/{total_secs}", end="")
            audio_buffer = bytearray()  # store 1 second of audio lumps

            for lump_i in range(lumps_per_second):
                # Check quit
                for event in pygame.event.get():
                    if event.type == pygame.QUIT:
                        pygame.quit()
                        return

                lump = f.read(chunk_size)
                if len(lump) < chunk_size:
                    print("End of file or incomplete lump.")
                    break

                video_part = lump[:frame_bytes_per_lump]
                audio_part = lump[frame_bytes_per_lump:]

                # Accumulate video data
                partial_frame_data += video_part
                lumps_in_current_frame += 1

                # Accumulate audio lumps
                audio_buffer += audio_part

                # If we've reached lumps_per_frame => we have a complete frame
                if lumps_in_current_frame == lumps_per_frame:
                    if frame_index < total_frames:
                        rgba2_path = "temp_frame.rgba2"
                        with open(rgba2_path, "wb") as tmpf:
                            tmpf.write(partial_frame_data)

                        # Convert RGBA2 -> RGBA -> PNG => load in Pygame
                        png_out = "temp_frame.png"
                        au.rgba2_to_img(rgba2_path, png_out, width, height)

                        frame_surface = pygame.image.load(png_out)
                        os.remove(rgba2_path)
                        os.remove(png_out)

                        # Scale the surface 4× using nearest neighbor
                        scaled_surface = pygame.transform.scale(
                            frame_surface,
                            (width * scale_factor, height * scale_factor)
                        )

                        # Blit the scaled image
                        screen.blit(scaled_surface, (0, 0))
                        pygame.display.flip()

                    frame_index += 1
                    partial_frame_data = bytearray()
                    lumps_in_current_frame = 0

                # Tick at 60 lumps per second
                clock.tick(60)

            # We have 1 second of audio in audio_buffer => write & play
            if len(audio_buffer) < audio_bytes_per_sec:
                needed = audio_bytes_per_sec - len(audio_buffer)
                audio_buffer += b"\x00" * needed

            temp_wav = "temp_1sec.wav"
            create_1sec_wav_file(audio_buffer[:audio_bytes_per_sec], sample_rate, temp_wav)

            # Play with Pygame
            sound = pygame.mixer.Sound(temp_wav)
            sound.play()

            # A small wait so the chunk starts playing (not strictly necessary)
            pygame.time.wait(50)

        print("\nPlayback completed. Cleaning up.")
        f.close()

    pygame.quit()
    # remove last temp wav
    if os.path.exists("temp_1sec.wav"):
        os.remove("temp_1sec.wav")


if __name__ == "__main__":
    # Example test
    # agm_filepath = "tgt/video/a-ha_-_Take_On_Me_Official_Video_Remastered_in_4K.agm"
    agm_filepath = "tgt/video/Bad_Apple_PV.agm"
    # agm_filepath = "tgt/video/Michael_Jackson_-_Thriller_Official_4K_Video.agm"
    play_agm(agm_filepath)

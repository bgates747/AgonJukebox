#!/usr/bin/env python3
import os
import pygame
import struct
from struct import unpack
from io import BytesIO

import agonutils as au  # for rgba2_to_img, etc.

WAV_HEADER_SIZE = 76
AGM_HEADER_SIZE = 68
SEGMENT_HEADER_SIZE = 8  # 4 bytes: last segment size, 4 bytes: this segment size

def parse_agm_header(header_bytes):
    """ Parse the 68-byte AGM header. """
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
    """ Extracts the sample rate from a 76-byte WAV header. """
    if len(wav_header_bytes) != WAV_HEADER_SIZE:
        raise ValueError("WAV header not 76 bytes.")
    if wav_header_bytes[12:15] != b"agm":
        raise ValueError("WAV header does not contain 'agm' marker at offset 12..14.")
    return int.from_bytes(wav_header_bytes[24:28], byteorder='little', signed=False)

def create_wav_file(audio_data, sample_rate, filename):
    """ Create a temporary PCM WAV file for playback. """
    import wave
    with wave.open(filename, "wb") as wf:
        wf.setnchannels(1)
        wf.setsampwidth(1)  # 8-bit = 1 byte/sample
        wf.setframerate(sample_rate)
        wf.writeframesraw(audio_data)

def play_agm(filepath):
    """
    Reads the new .agm file format:
      * 8-byte segment header
      * Then for each segment, typically two units:
         (a) Audio Unit => 1-byte mask=0x00, chunked data until chunk_size=0
         (b) Video Unit => 1-byte mask=0x80, chunked data until chunk_size=0
      * Each chunk = 4-byte chunk_size + chunk_data
      * chunk_size=0 => end of that unit

    For audio, we accumulate the entire unit and play it once per segment.
    For video, we accumulate chunk_data until we have enough for a full frame.
    Then we display that frame immediately, and repeat if there's leftover data.
    """
    pygame.init()
    clock = pygame.time.Clock()
    temp_wav = "tgt/temp_audio.wav"

    # Open the .agm file
    with open(filepath, "rb") as f:
        # 1) Read the WAV header & the AGM header
        wav_header = f.read(WAV_HEADER_SIZE)
        agm_header = f.read(AGM_HEADER_SIZE)

        # 2) Parse relevant info
        meta = parse_agm_header(agm_header)
        width, height = meta["width"], meta["height"]
        fps, total_frames, audio_secs = (
            meta["frame_rate"],
            meta["total_frames"],
            meta["audio_secs"]
        )
        sample_rate = parse_sample_rate_from_wav_header(wav_header)

        print(f"=== AGM HEADER ===\n"
              f"File: {filepath}\n"
              f"Resolution: {width}x{height}\n"
              f"Frame Rate: {fps} fps\n"
              f"Total Frames: {total_frames}\n"
              f"Audio Secs: {audio_secs}\n"
              f"Sample Rate: {sample_rate} Hz\n")

        screen = pygame.display.set_mode((width * 4, height * 4))
        pygame.display.set_caption("AGM Video Player")

        frame_idx = 0  # how many frames we've displayed so far

        # 3) Loop over the file reading segments
        while True:
            seg_header = f.read(SEGMENT_HEADER_SIZE)
            if len(seg_header) < SEGMENT_HEADER_SIZE:
                print("End of file (no more segment headers).")
                break

            # Unpack the segment header
            seg_size_last, seg_size_this = unpack("<II", seg_header)
            print(f"\nSegment: last={seg_size_last}, this={seg_size_this}")

            if seg_size_this == 0:
                print("Segment size=0 => skipping.")
                continue

            # Read exactly seg_size_this bytes of segment data
            segment_data = f.read(seg_size_this)
            if len(segment_data) < seg_size_this:
                print("File ended unexpectedly in middle of segment.")
                break

            seg_stream = BytesIO(segment_data)
            seg_consumed = 0

            # We typically expect exactly 2 units: audio + video
            # but let's parse "units" in a loop until we exhaust the segment
            while True:
                if seg_stream.tell() >= seg_size_this:
                    # done with this segment
                    break

                # 4) Read the 1-byte unit mask
                unit_mask_b = seg_stream.read(1)
                if not unit_mask_b:
                    print("Ran out of data reading unit mask. Corrupt segment?")
                    break

                unit_mask = unit_mask_b[0]
                is_video = bool(unit_mask & 0x80)

                if is_video:
                    print("Unit: VIDEO (mask=0x%02X)" % unit_mask)
                else:
                    print("Unit: AUDIO (mask=0x%02X)" % unit_mask)

                # 5) Read chunks until chunk_size=0
                if is_video:
                    video_buffer = b""
                    while True:
                        # read 4 bytes => chunk_size
                        chunk_size_data = seg_stream.read(4)
                        if len(chunk_size_data) < 4:
                            print("Ran out of data reading video chunk size.")
                            break
                        chunk_size = struct.unpack("<I", chunk_size_data)[0]
                        if chunk_size == 0:
                            # End of video unit
                            print("End of VIDEO unit.\n")
                            break

                        chunk_data = seg_stream.read(chunk_size)
                        if len(chunk_data) < chunk_size:
                            # pad with black
                            chunk_data += b"\x00" * (chunk_size - len(chunk_data))

                        # Accumulate in video_buffer
                        video_buffer += chunk_data

                        # Each frame is width*height bytes
                        frame_bytes_needed = width * height
                        # Keep extracting frames from video_buffer
                        while len(video_buffer) >= frame_bytes_needed:
                            one_frame = video_buffer[:frame_bytes_needed]
                            video_buffer = video_buffer[frame_bytes_needed:]
                            # Decode & display
                            rgba2_path = "temp_frame.rgba2"
                            with open(rgba2_path, "wb") as tmpf:
                                tmpf.write(one_frame)

                            png_out = "temp_frame.png"
                            au.rgba2_to_img(rgba2_path, png_out, width, height)
                            frame_surface = pygame.image.load(png_out)

                            os.remove(rgba2_path)
                            os.remove(png_out)

                            # Scale & blit
                            screen.blit(pygame.transform.scale(frame_surface, (width*4, height*4)), (0, 0))
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

                            # Use clock to maintain approximate FPS
                            clock.tick(fps)

                            if frame_idx >= total_frames:
                                break

                        if frame_idx >= total_frames:
                            # no need to parse further video
                            break

                else:
                    # AUDIO unit
                    audio_buffer = b""
                    while True:
                        chunk_size_data = seg_stream.read(4)
                        if len(chunk_size_data) < 4:
                            print("Ran out of data reading audio chunk size.")
                            break
                        chunk_size = struct.unpack("<I", chunk_size_data)[0]
                        if chunk_size == 0:
                            # End of audio unit
                            print("End of AUDIO unit.\n")
                            break

                        chunk_data = seg_stream.read(chunk_size)
                        if len(chunk_data) < chunk_size:
                            # pad with silence
                            chunk_data += b"\x00" * (chunk_size - len(chunk_data))

                        audio_buffer += chunk_data

                    # Once we finish reading all chunks for the audio unit,
                    # we have (up to) 1 second of audio in `audio_buffer`.
                    # Let's play that second:
                    if len(audio_buffer) > 0:
                        # We'll limit playback to just 1 second => sample_rate bytes
                        # to avoid drifting if there's leftover
                        create_wav_file(audio_buffer[:sample_rate], sample_rate, temp_wav)
                        pygame.mixer.Sound(temp_wav).play()

        print("Playback completed.")
        f.close()

    pygame.quit()
    if os.path.exists(temp_wav):
        os.remove(temp_wav)

# Test / main
if __name__ == "__main__":
    agm_path = "tgt/video/a_ha__Take_On_Me_short_120x90x4.agm"
    if not os.path.exists(agm_path):
        print(f"Error: AGM file not found at '{agm_path}'")
    else:
        print(f"Playing: {agm_path}")
        play_agm(agm_path)

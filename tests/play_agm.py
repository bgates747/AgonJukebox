#!/usr/bin/env python3
import sys
import struct
import pygame
import agonutils as au

# ----- Metadata for the movie -----
VIDEO_FILE = "/home/smith/Agon/mystuff/assets/video/staging/a_ha__Take_On_Me_short_rle.agm"
WIDTH = 320
HEIGHT = 240
FRAME_RATE = 30
SCALING_FACTOR = 1.0

# ----- Helper function to parse .agm and load frames -----
def load_movie_frames(filename):
    """
    Pre-load all frames from the .agm file. Each frame is assumed to be stored as:
      [4-byte little-endian length][RLE-encoded data].
    We RLE-decode to get raw RGBA2 of size WIDTH*HEIGHT per frame.

    Returns a list of RGBA2 frames (each a bytes object).
    """
    try:
        with open(filename, "rb") as f:
            data = f.read()
    except IOError as e:
        print(f"Error opening {filename}: {e}")
        sys.exit(1)

    frames = []
    offset = 0
    total_size = len(data)
    frame_count = 0

    while True:
        # If not enough bytes for a frame header, we're done.
        if offset + 4 > total_size:
            break

        # Read the 4-byte frame length (little-endian)
        frame_len = struct.unpack_from("<I", data, offset)[0]
        offset += 4

        # If not enough bytes left for the frame data, break
        if offset + frame_len > total_size:
            break

        # Extract the RLE-compressed data
        compressed_frame = data[offset:offset + frame_len]
        offset += frame_len

        # Decode RLE to get the raw RGBA2 data
        rgba2_data = au.rle_decode(compressed_frame)
        frames.append(rgba2_data)
        frame_count += 1

        # Print progress on a single line
        percent = (offset / total_size) * 100.0
        sys.stderr.write(f"\rLoaded frame {frame_count} ({percent:.2f}%)")
        sys.stderr.flush()

    sys.stderr.write("\n")

    if not frames:
        print("No frames found in the .agm file!")
        sys.exit(1)

    print(f"Loaded {len(frames)} frames from {filename}")
    return frames

# ----- Convert RGBA2 -> RGBA32 (existing logic) -----
def convert_rgba2_to_rgba32(frame_data, width, height):
    """
    Convert RGBA2 data (packed, 1 byte/pixel) to 32-bit RGBA using agonutils.
    """
    return au.rgba2_to_rgba32_bytes(frame_data, width, height)

# ----- Main player function -----
def main():
    # Init pygame
    pygame.init()
    window_width = int(WIDTH * SCALING_FACTOR)
    window_height = int(HEIGHT * SCALING_FACTOR)
    screen = pygame.display.set_mode((window_width, window_height))
    pygame.display.set_caption("Agonutils Video Player")

    # Pre-load frames (RLE decode => RGBA2).
    frames = load_movie_frames(VIDEO_FILE)
    
    clock = pygame.time.Clock()
    running = True
    frame_index = 0
    total_frames = len(frames)

    while running:
        # Process events
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False
        
        # Convert from RGBA2 to RGBA32
        raw_frame = frames[frame_index]
        rgba32_bytes = convert_rgba2_to_rgba32(raw_frame, WIDTH, HEIGHT)

        # Create a pygame surface
        try:
            frame_surface = pygame.image.frombuffer(rgba32_bytes, (WIDTH, HEIGHT), "RGBA")
        except Exception as e:
            print(f"Error creating surface for frame {frame_index+1}: {e}")
            running = False
            continue
        
        # Scale if needed
        if SCALING_FACTOR != 1.0:
            frame_surface = pygame.transform.scale(frame_surface, (window_width, window_height))
        
        # Blit & update display
        screen.blit(frame_surface, (0, 0))
        pygame.display.flip()
        
        # Control frame rate
        clock.tick(FRAME_RATE)

        # Next frame
        frame_index = (frame_index + 1) % total_frames
    
    pygame.quit()

if __name__ == '__main__':
    main()

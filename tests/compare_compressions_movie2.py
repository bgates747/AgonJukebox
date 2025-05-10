#!/usr/bin/env python3
import os
import re

def load_sorted_frames(directory):
    """
    Returns a sorted list of full paths to .rgba2 files in 'directory',
    sorted by the frame number extracted from filenames of the form 'frame_XXXXX.rgba2'.
    """
    files = [f for f in os.listdir(directory) if f.lower().endswith(".rgba2")]
    def frame_index(filename):
        m = re.search(r'frame_(\d+)', filename.lower())
        return int(m.group(1)) if m else 0
    files.sort(key=frame_index)
    return [os.path.join(directory, f) for f in files]

def compare_frames(prev_frame, curr_frame):
    """
    Compare two byte arrays (of equal length). For each pixel in the current frame:
      - If it differs from the corresponding pixel in the previous frame, output the current pixel as is.
      - Otherwise, output 0.
    Returns a new bytes object representing the differenced frame.
    """
    return bytes((curr if curr != prev else 0) for prev, curr in zip(prev_frame, curr_frame))

def combine_frames(output_file, original_frame_rate, target_frame_rate):
    frame_files = load_sorted_frames(frames_dir)
    if not frame_files:
        print("No .rgba2 files found in", frames_dir)
        return

    # Calculate the skip factor (for 30/30, skip is 1 so every frame is used)
    skip = original_frame_rate // target_frame_rate

    # Create a dummy "previous" frame (full-alpha black) using the size of the first frame.
    dummy_size = os.path.getsize(frame_files[0])
    prev_frame = bytes([0xC0] * dummy_size)

    with open(output_file, "wb") as outfile:
        # Process only every 'skip'-th frame.
        for count, idx in enumerate(range(0, len(frame_files), skip), start=1):
            frame_path = frame_files[idx]
            print(f"\rProcessing frame {count} of {len(range(0, len(frame_files), skip))}", end="")
            with open(frame_path, "rb") as infile:
                current_frame = infile.read()
            # Create a differenced frame using compare_frames.
            diff_frame = compare_frames(prev_frame, current_frame)
            # Update previous frame for next comparison.
            prev_frame = current_frame
            # Write the differenced frame to the output file.
            outfile.write(diff_frame)
    print("\r\nAll frames combined into", output_file)

if __name__ == "__main__":
    frames_dir = "/home/smith/Agon/mystuff/assets/video/frames/"
    original_frame_rate = 30  # frames per second in the source
    target_frame_rate = 30    # desired sampling rate
    output_file = f'{frames_dir}/all_frames'
    combine_frames(output_file, original_frame_rate, target_frame_rate)

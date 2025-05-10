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

def combine_frames(output_file):
    frame_files = load_sorted_frames(frames_dir)
    if not frame_files:
        print("No .rgba2 files found in", frames_dir)
        return
    with open(output_file, "wb") as outfile:
        for frame in frame_files:
            print("Appending", frame)
            with open(frame, "rb") as infile:
                outfile.write(infile.read())
    print("All frames combined into", output_file)

if __name__ == "__main__":
    frames_dir = "/home/smith/Agon/mystuff/assets/video/frames/"
    output_file = f'{frames_dir}_all_frames'
    combine_frames(output_file)

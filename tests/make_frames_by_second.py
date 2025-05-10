#!/usr/bin/env python3
import os
import re
import sys

### Helper Functions ###
def load_sorted_frames(directory):
    """
    Return a sorted list of full paths to .rgba2 files in 'directory',
    sorted by frame number extracted from filenames like 'frame_XXXXX.rgba2'.
    """
    files = [f for f in os.listdir(directory) if f.lower().endswith(".rgba2")]
    def frame_index(filename):
        m = re.search(r'frame_(\d+)', filename.lower())
        return int(m.group(1)) if m else 0
    files.sort(key=frame_index)
    return [os.path.join(directory, f) for f in files]

def read_frame(file_path):
    with open(file_path, "rb") as f:
        return f.read()

def sequential_concat(frames):
    """Concatenate a list of frames in order."""
    return b"".join(frames)

def interleave_frames(frames):
    """
    Given a list of frames (as bytes), interleave them byte-by-byte.
    Assumes all frames have equal length.
    """
    if not frames:
        return b""
    frame_len = len(frames[0])
    interleaved = bytearray()
    for i in range(frame_len):
        for frame in frames:
            interleaved.append(frame[i])
    return bytes(interleaved)

def main():
    global raw_frames_dir, diffed_frames_dir, START_SECOND, ORIGINAL_FRAME_RATE, TARGET_FRAME_RATE

    # Compute the starting index in the sorted frame list.
    start_index = START_SECOND * ORIGINAL_FRAME_RATE
    skip = ORIGINAL_FRAME_RATE // TARGET_FRAME_RATE

    # Load sorted frames from both raw and diffed directories.
    raw_frame_files = load_sorted_frames(raw_frames_dir)
    diffed_frame_files = load_sorted_frames(diffed_frames_dir)

    # Sanity checks
    if not raw_frame_files or not diffed_frame_files:
        print("No .rgba2 files found in one or both directories.")
        sys.exit(1)
    
    total_frames = len(raw_frame_files)
    if len(diffed_frame_files) != total_frames:
        print("Warning: Mismatch between raw and diffed frame counts!")

    # Check if enough frames exist
    if start_index + (TARGET_FRAME_RATE - 1) * skip >= total_frames:
        print(f"Not enough frames available from start_index {start_index} with skip {skip}.")
        sys.exit(1)

    # Select frames for both raw and diffed sequences
    selected_raw_files = [raw_frame_files[start_index + i * skip] for i in range(TARGET_FRAME_RATE)]
    selected_diffed_files = [diffed_frame_files[start_index + i * skip] for i in range(TARGET_FRAME_RATE)]
    
    # ---- Read the selected frames.
    raw_frames = [read_frame(f) for f in selected_raw_files]
    diffed_frames = [read_frame(f) for f in selected_diffed_files]

    # ---- Create Combined Data Blobs.
    seq_nodiff = sequential_concat(raw_frames)
    seq_diffed = sequential_concat(diffed_frames)
    
    inter_nodiff = interleave_frames(raw_frames)
    inter_diffed = interleave_frames(diffed_frames)
    
    # ---- Construct output filenames.
    base_name = f"{START_SECOND}sec_{TARGET_FRAME_RATE}fps"
    output_seq_nodiff = f"frames/output_seq_nodiff_{base_name}.dat"
    output_seq_diffed = f"frames/output_seq_diffed_{base_name}.dat"
    output_inter_nodiff = f"frames/output_inter_nodiff_{base_name}.dat"
    output_inter_diffed = f"frames/output_inter_diffed_{base_name}.dat"
    
    # ---- Write Output Files.
    with open(output_seq_nodiff, "wb") as f:
        f.write(seq_nodiff)
    with open(output_seq_diffed, "wb") as f:
        f.write(seq_diffed)
    with open(output_inter_nodiff, "wb") as f:
        f.write(inter_nodiff)
    with open(output_inter_diffed, "wb") as f:
        f.write(inter_diffed)
    
    print("Files written:")
    print("  Sequential nondiffed:", output_seq_nodiff)
    print("  Sequential diffed:    ", output_seq_diffed)
    print("  Interleaved nondiffed:", output_inter_nodiff)
    print("  Interleaved diffed:   ", output_inter_diffed)

if __name__ == "__main__":
    # ----- Configuration -----
    raw_frames_dir = "/home/smith/Agon/mystuff/assets/video/frames/" 
    diffed_frames_dir = "/home/smith/Agon/mystuff/assets/video/diffs_RGB_bayer"
    START_SECOND = 0    # Start at s seconds into the video
    ORIGINAL_FRAME_RATE = 30  # Source frame rate (frames per second)
    TARGET_FRAME_RATE = 10    # Number of frames to pack into one second's worth of output

    main()

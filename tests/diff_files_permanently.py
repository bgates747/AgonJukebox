#!/usr/bin/env python3
import os
import glob

# --- Configuration ---
SOURCE_DIR = "/home/smith/Agon/mystuff/assets/video/frames/"
TARGET_DIR = "/home/smith/Agon/mystuff/assets/video/diffs_RGB_bayer/"

# --- Diffing function ---
def compute_diff_frame(prev_frame, curr_frame):
    """
    Computes a difference frame:
      - If prev_frame is None, returns curr_frame (first frame stored raw).
      - Otherwise, outputs the current pixel value if it differs from the previous frame,
        otherwise outputs 0.
    """
    if prev_frame is None:
        return curr_frame
    return bytes(curr if curr != prev else 0 for prev, curr in zip(prev_frame, curr_frame))

def clear_target_directory(directory):
    """Deletes all files in the target directory before writing new ones."""
    if not os.path.exists(directory):
        os.makedirs(directory)
    else:
        for file in glob.glob(os.path.join(directory, "*")):
            os.remove(file)

def process_frames():
    """Processes all .rgba2 files, sorts them, computes diffs, and writes them to the target directory."""
    # Ensure target directory is empty
    clear_target_directory(TARGET_DIR)

    # Get all .rgba2 files and sort by filename
    files = sorted(glob.glob(os.path.join(SOURCE_DIR, "*.rgba2")))

    prev_frame = None  # No previous frame initially

    for file in files:
        # Read current frame
        with open(file, "rb") as f:
            curr_frame = f.read()

        # Compute diffed frame
        diff_frame = compute_diff_frame(prev_frame, curr_frame)

        # Determine output path (same filename, different directory)
        output_path = os.path.join(TARGET_DIR, os.path.basename(file))

        # Write the diffed frame
        with open(output_path, "wb") as f:
            f.write(diff_frame)

        # Update prev_frame for the next iteration
        prev_frame = curr_frame

    print(f"Processed {len(files)} frames. Diffed frames saved to {TARGET_DIR}")

if __name__ == "__main__":
    process_frames()

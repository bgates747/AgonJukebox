#!/usr/bin/env python3
import os
import re
import csv
import subprocess

# ----- Helper Functions -----

def get_file_size(path):
    return os.path.getsize(path)

def compress_with_simz(input_file):
    """Compress using simz, writing output to a temp file."""
    temp_file = "temp.simz"
    subprocess.run(["simz", "-c", input_file, temp_file],
                   check=True, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    size = os.path.getsize(temp_file)
    os.remove(temp_file)
    return size

def compress_with_szip(input_file):
    """Compress using szip, writing output to a temp file."""
    temp_file = "temp.szip"
    subprocess.run(["szip", input_file, temp_file],
                   check=True, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    size = os.path.getsize(temp_file)
    os.remove(temp_file)
    return size

def compress_with_tbv(input_file):
    """Compress using tbv compression, writing output to a temp file."""
    temp_file = "temp.tbv"
    subprocess.run(["compress", input_file, temp_file],
                   check=True, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    size = os.path.getsize(temp_file)
    os.remove(temp_file)
    return size

def compress_with_rle(input_file):
    """Compress using rlecompression, writing output to a temp file."""
    temp_file = "temp.rle"
    subprocess.run(["rlecompress", input_file, temp_file],
                   check=True, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    size = os.path.getsize(temp_file)
    os.remove(temp_file)
    return size

def load_sorted_frames(directory):
    """
    Returns a sorted list of full paths to .rgba2 files in 'directory',
    sorted by frame number extracted from filenames of the form 'frame_XXXXX.rgba2'.
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

# ----- Main Compression Testing Function -----

def main():
    # Configuration: all constants defined in main.
    frames_dir = "/home/smith/Agon/mystuff/assets/video/frames/"
    original_frame_rate = 30
    target_frame_rate = 10  # Modify as needed.
    output_csv = f"tests/compare_compressions_movie_{target_frame_rate:02d}_nodiff.csv"

    # Load and sort all .rgba2 frame files.
    frame_files = load_sorted_frames(frames_dir)
    if not frame_files:
        print("No .rgba2 files found in", frames_dir)
        return
    total_frames = len(frame_files)

    # Select frames based on the target frame rate.
    selected_frames = frame_files[::original_frame_rate // target_frame_rate]

    stats = []  # Will hold rows: [frame number, original_bytes, szip_bytes, simz_bytes, rle_bytes, tbv_bytes]

    for idx, frame_path in enumerate(selected_frames, start=1):
        # Read the current frame as-is.
        current_frame = read_frame(frame_path)

        # Write frame to a temporary file (for the compression utilities).
        temp_frame = "temp_nodiff.rgba2"
        with open(temp_frame, "wb") as f:
            f.write(current_frame)

        original_bytes = len(current_frame)
        simz_bytes = compress_with_simz(temp_frame)
        szip_bytes = compress_with_szip(temp_frame)
        tbv_bytes = compress_with_tbv(temp_frame)
        rle_bytes = compress_with_rle(temp_frame)

        os.remove(temp_frame)

        stats.append([idx, original_bytes, szip_bytes, simz_bytes, rle_bytes, tbv_bytes])

        # Update progress on a single line.
        print(f"\rFrame {idx} of {len(selected_frames)} processed", end="", flush=True)

    print("\nWriting CSV data...")
    os.makedirs(os.path.dirname(output_csv), exist_ok=True)
    with open(output_csv, "w", newline="") as csvfile:
        writer = csv.writer(csvfile)
        writer.writerow(["frame", "original_bytes", "szip_bytes", "simz_bytes", "rle_bytes", "tbv_bytes"])
        writer.writerows(stats)
    print("CSV written to", output_csv)

if __name__ == "__main__":
    main()

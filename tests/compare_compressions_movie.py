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

def compress_with_tvc(input_file):
    """Compress using tvc compression, writing output to a temp file."""
    temp_file = "temp.tvc"
    subprocess.run(["tvcompress", input_file, temp_file],
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

def compress_with_mskz(input_file):
    """Compress using mskz, writing output to a temp file."""
    temp_file = "temp.mskz"
    subprocess.run(["mskz", "-c", input_file, temp_file],
                   check=True, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    size = os.path.getsize(temp_file)
    os.remove(temp_file)
    return size

def compress_with_snappy(input_file):
    """Compress using snappy, writing output to a temp file."""
    temp_file = "temp.snpz"
    subprocess.run(["scmd", "-c", input_file, temp_file],
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

def compare_frames(prev_frame, curr_frame):
    """
    Compare two byte arrays (of equal length). For each pixel in the current frame:
      - If it differs from the corresponding pixel in the previous frame, output the current pixel as is.
      - Otherwise, output 0 (black, zero alpha).
    Returns a new bytes object.
    """
    return bytes((curr if curr != prev else 0) for prev, curr in zip(prev_frame, curr_frame))

# ----- Main Testing Function -----
def main(frames_dir, original_frame_rate, target_frame_rate):
    skip = original_frame_rate // target_frame_rate  # e.g., 30/6 = 5

    # CSV filenames include target frame rate (zero-padded to 2 digits)
    output_csv_diffed = os.path.join("tests", f"compare_compressions_movie_{target_frame_rate:02d}_diffed.csv")
    output_csv_nodiff = os.path.join("tests", f"compare_compressions_movie_{target_frame_rate:02d}_nodiff.csv")

    # Load and sort all .rgba2 frame files.
    frame_files = load_sorted_frames(frames_dir)
    if not frame_files:
        print("No .rgba2 files found in", frames_dir)
        return
    total_frames = len(frame_files)

    # Create a dummy "previous frame" (full-alpha black) using the size of the first frame.
    dummy_size = get_file_size(frame_files[0])
    prev_frame = bytes([0xC0] * dummy_size)

    stats_diffed = []
    stats_nodiff = []

    # Process only every 'skip'-th frame.
    selected_indices = list(range(0, total_frames, skip))
    for count, idx in enumerate(selected_indices, start=1):
        frame_path = frame_files[idx]
        current_frame = read_frame(frame_path)

        # ---- DIFFERENCED (diffed) frame ----
        delta_frame = compare_frames(prev_frame, current_frame)
        temp_delta = "temp_delta.rgba2"
        with open(temp_delta, "wb") as f:
            f.write(delta_frame)
        original_bytes_diffed = len(delta_frame)
        szip_bytes_diffed = compress_with_szip(temp_delta)
        mskz_bytes_diffed = compress_with_mskz(temp_delta)
        rle_bytes_diffed = compress_with_rle(temp_delta)
        snpz_bytes_diffed = compress_with_snappy(temp_delta)
        os.remove(temp_delta)
        stats_diffed.append([idx, original_bytes_diffed, szip_bytes_diffed, mskz_bytes_diffed, rle_bytes_diffed, snpz_bytes_diffed])

        # ---- NON-DIFFERENCED (nodiff) frame ----
        temp_nodiff = "temp_nodiff.rgba2"
        with open(temp_nodiff, "wb") as f:
            f.write(current_frame)
        original_bytes_nodiff = len(current_frame)
        szip_bytes_nodiff = compress_with_szip(temp_nodiff)
        mskz_bytes_nodiff = compress_with_mskz(temp_nodiff)
        rle_bytes_nodiff = compress_with_rle(temp_nodiff)
        snpz_bytes_nodiff = compress_with_snappy(temp_nodiff)
        os.remove(temp_nodiff)
        stats_nodiff.append([idx, original_bytes_nodiff, szip_bytes_nodiff, mskz_bytes_nodiff, rle_bytes_nodiff, snpz_bytes_nodiff])

        # Set current frame as previous for the next iteration (for diffed processing).
        prev_frame = current_frame

        # Update progress on a single line.
        print(f"\rFrame {count} of {len(selected_indices)} processed", end="", flush=True)

    print("\nWriting CSV data...")
    os.makedirs(os.path.dirname(output_csv_diffed), exist_ok=True)
    with open(output_csv_diffed, "w", newline="") as csvfile:
        writer = csv.writer(csvfile)
        writer.writerow(["frame", "original_bytes", "szip_bytes", "mskz_bytes", "rle_bytes", "snpz_bytes"])
        writer.writerows(stats_diffed)
    print("CSV written to", output_csv_diffed)

    with open(output_csv_nodiff, "w", newline="") as csvfile:
        writer = csv.writer(csvfile)
        writer.writerow(["frame", "original_bytes", "szip_bytes", "mskz_bytes", "rle_bytes", "snpz_bytes"])
        writer.writerows(stats_nodiff)
    print("CSV written to", output_csv_nodiff)

if __name__ == "__main__":
    # frames_dir = "/home/smith/Agon/mystuff/assets/video/frames/"
    frames_dir = "/home/smith/Agon/mystuff/assets/video/diffs_RGB_bayer/"
    original_frame_rate = 30  # frames per second in the source
    target_frame_rate = 30     # desired sampling rate

    main(frames_dir, original_frame_rate, target_frame_rate)
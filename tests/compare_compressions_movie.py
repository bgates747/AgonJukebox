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
    """Compress using rlecompress, writing output to a temp file."""
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

def subtract_frames(prev_frame, curr_frame):
    """
    Subtract each pixel in prev_frame from the corresponding pixel in curr_frame.
    The subtraction is done modulo 256 (i.e. negative differences wrap around).
    Returns a new bytes object representing the difference image.
    """
    return bytes(((curr - prev) & 0xFF) for prev, curr in zip(prev_frame, curr_frame))

# ----- Main Testing Function -----
def main(frames_dir, original_frame_rate, target_frame_rate):
    skip = original_frame_rate // target_frame_rate  # e.g., 30/6 = 5
    frames_per_second = target_frame_rate  # Frames in each 1-second chunk

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

    # Temporary storage for accumulating 1-second chunks.
    # Order of accumulated values:
    # [original_bytes, rle_bytes, szip_bytes, snpz_bytes, tvc_bytes]
    sum_diffed = [0] * 5
    sum_nodiff = [0] * 5

    # Process only every 'skip'-th frame.
    selected_indices = list(range(0, total_frames, skip))
    for count, idx in enumerate(selected_indices, start=1):
        frame_path = frame_files[idx]
        current_frame = read_frame(frame_path)

        # ---- DIFFERENCED (diffed) frame ----
        # Using pure subtraction differencing.
        delta_frame = compare_frames(prev_frame, current_frame)
        prev_frame = current_frame
        temp_delta = "temp_delta.rgba2"
        with open(temp_delta, "wb") as f:
            f.write(delta_frame)
        original_bytes_diffed = len(delta_frame)
        # Apply each compression algorithm to the differenced frame.
        rle_bytes_diffed = compress_with_rle(temp_delta)
        szip_bytes_diffed = compress_with_szip(temp_delta)
        snpz_bytes_diffed = compress_with_snappy(temp_delta)
        tvc_bytes_diffed = compress_with_tvc(temp_delta)
        os.remove(temp_delta)

        # Accumulate bytes for this second in the order:
        # original, rle, szip, snpz, tvc.
        sum_diffed[0] += original_bytes_diffed
        sum_diffed[1] += rle_bytes_diffed
        sum_diffed[2] += szip_bytes_diffed
        sum_diffed[3] += snpz_bytes_diffed
        sum_diffed[4] += tvc_bytes_diffed

        # ---- NON-DIFFERENCED (nodiff) frame ----
        temp_nodiff = "temp_nodiff.rgba2"
        with open(temp_nodiff, "wb") as f:
            f.write(current_frame)
        original_bytes_nodiff = len(current_frame)
        rle_bytes_nodiff = compress_with_rle(temp_nodiff)
        szip_bytes_nodiff = compress_with_szip(temp_nodiff)
        snpz_bytes_nodiff = compress_with_snappy(temp_nodiff)
        tvc_bytes_nodiff = compress_with_tvc(temp_nodiff)
        os.remove(temp_nodiff)

        sum_nodiff[0] += original_bytes_nodiff
        sum_nodiff[1] += rle_bytes_nodiff
        sum_nodiff[2] += szip_bytes_nodiff
        sum_nodiff[3] += snpz_bytes_nodiff
        sum_nodiff[4] += tvc_bytes_nodiff

        # If we've processed a full second's worth of frames, store the accumulated sums.
        if count % frames_per_second == 0:
            second_index = count // frames_per_second
            stats_diffed.append([second_index] + sum_diffed)
            stats_nodiff.append([second_index] + sum_nodiff)
            sum_diffed = [0] * 5
            sum_nodiff = [0] * 5

        print(f"\rFrame {count} of {len(selected_indices)} processed", end="", flush=True)

    print("\nWriting CSV data...")
    os.makedirs(os.path.dirname(output_csv_diffed), exist_ok=True)
    with open(output_csv_diffed, "w", newline="") as csvfile:
        writer = csv.writer(csvfile)
        writer.writerow(["second", "original_bytes", "rle_bytes", "szip_bytes", "snpz_bytes", "tvc_bytes"])
        writer.writerows(stats_diffed)
    print("CSV written to", output_csv_diffed)

    with open(output_csv_nodiff, "w", newline="") as csvfile:
        writer = csv.writer(csvfile)
        writer.writerow(["second", "original_bytes", "rle_bytes", "szip_bytes", "snpz_bytes", "tvc_bytes"])
        writer.writerows(stats_nodiff)
    print("CSV written to", output_csv_nodiff)

if __name__ == "__main__":
    frames_dir = "/home/smith/Agon/mystuff/assets/video/frames/"
    original_frame_rate = 30  # frames per second in the source
    target_frame_rate = 30     # desired sampling rate

    main(frames_dir, original_frame_rate, target_frame_rate)

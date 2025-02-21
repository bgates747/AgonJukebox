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

def xor_frames(frame1, frame2):
    """
    XOR two byte arrays (of equal length) and force the top two bits to 1.
    Returns a new bytes object.
    """
    return bytes(((a ^ b) | 0xC0) for a, b in zip(frame1, frame2))

# ----- Main Testing Function -----

def main():
    # Configuration: all constants defined in main.
    frames_dir = "/home/smith/Agon/mystuff/assets/video/frames/"
    original_frame_rate = 30  # frames per second in the source
    target_frame_rate = 10     # desired sampling rate
    skip = original_frame_rate // target_frame_rate  # e.g., 30/6 = 5

    # CSV filename includes target frame rate (zero-padded to 2 digits)
    output_csv = os.path.join("tests", f"compare_compressions_movie_{target_frame_rate:02d}_xored.csv")

    # Load and sort all .rgba2 frame files.
    frame_files = load_sorted_frames(frames_dir)
    if not frame_files:
        print("No .rgba2 files found in", frames_dir)
        return
    total_frames = len(frame_files)

    # Create a dummy "previous frame" (full-alpha black) using the size of the first frame.
    dummy_size = get_file_size(frame_files[0])
    prev_frame = bytes([0xC0] * dummy_size)

    stats = []  # Rows: [frame number, original_bytes, szip_bytes, simz_bytes, rle_bytes, tbv_bytes]

    # Process only every 'skip'-th frame.
    selected_indices = list(range(0, total_frames, skip))
    for count, idx in enumerate(selected_indices, start=1):
        frame_path = frame_files[idx]
        # Read current frame.
        current_frame = read_frame(frame_path)

        # Compute delta frame: XOR current with previous, forcing full alpha.
        delta_frame = xor_frames(current_frame, prev_frame)

        # Write delta_frame to a temporary file.
        temp_delta = "temp_delta.rgba2"
        with open(temp_delta, "wb") as f:
            f.write(delta_frame)

        original_bytes = len(delta_frame)
        simz_bytes = compress_with_simz(temp_delta)
        szip_bytes = compress_with_szip(temp_delta)
        tbv_bytes = compress_with_tbv(temp_delta)
        rle_bytes = compress_with_rle(temp_delta)

        os.remove(temp_delta)

        stats.append([idx, original_bytes, szip_bytes, simz_bytes, rle_bytes, tbv_bytes])

        # Set current frame as previous for the next iteration.
        prev_frame = current_frame

        # Update progress on a single line.
        print(f"\rFrame {count} of {len(selected_indices)} processed", end="", flush=True)

    print("\nWriting CSV data...")
    os.makedirs(os.path.dirname(output_csv), exist_ok=True)
    with open(output_csv, "w", newline="") as csvfile:
        writer = csv.writer(csvfile)
        writer.writerow(["frame", "original_bytes", "szip_bytes", "simz_bytes", "rle_bytes", "tbv_bytes"])
        writer.writerows(stats)
    print("CSV written to", output_csv)

if __name__ == "__main__":
    main()

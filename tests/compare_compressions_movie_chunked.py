#!/usr/bin/env python3
import os
import re
import csv
import subprocess
import math

# ----- Helper Functions with Optional Output File -----

def get_file_size(path):
    return os.path.getsize(path)

def compress_with_simz(input_file, output_file=None):
    """Compress using simz. If output_file is None, use a temp file."""
    if output_file is None:
        output_file = "temp.simz"
        remove_after = True
    else:
        remove_after = False
    subprocess.run(["simz", "-c", input_file, output_file],
                   check=True, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    size = os.path.getsize(output_file)
    if remove_after:
        os.remove(output_file)
    return size

def compress_with_szip_b41o3(input_file, output_file=None):
    """Compress using szip -b41o3."""
    if output_file is None:
        output_file = "temp.szip"
        remove_after = True
    else:
        remove_after = False
    subprocess.run(["szip", "-b41o3", input_file, output_file],
                   check=True, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    size = os.path.getsize(output_file)
    if remove_after:
        os.remove(output_file)
    return size

def compress_with_szip_b41o0(input_file, output_file=None):
    """Compress using szip -b41o0."""
    if output_file is None:
        output_file = "temp.szip"
        remove_after = True
    else:
        remove_after = False
    subprocess.run(["szip", "-b41o0", input_file, output_file],
                   check=True, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    size = os.path.getsize(output_file)
    if remove_after:
        os.remove(output_file)
    return size

def compress_with_tvc(input_file, output_file=None):
    """Compress using tvcompress."""
    if output_file is None:
        output_file = "temp.tvc"
        remove_after = True
    else:
        remove_after = False
    subprocess.run(["tvcompress", input_file, output_file],
                   check=True, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    size = os.path.getsize(output_file)
    if remove_after:
        os.remove(output_file)
    return size

def compress_with_rle2(input_file, output_file=None):
    """Compress using rle2."""
    if output_file is None:
        output_file = "temp.rle2"
        remove_after = True
    else:
        remove_after = False
    subprocess.run(["rle2", "-c", input_file, output_file],
                   check=True, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    size = os.path.getsize(output_file)
    if remove_after:
        os.remove(output_file)
    return size

def compress_with_srle2(input_file, output_file=None):
    """
    Compress using a two-step process:
      1. Compress with rle2 to generate an intermediate file.
      2. Compress the intermediate file with szip -b41o3.
    """
    # Use temporary filenames if not provided.
    intermediate = "temp.rle2"
    if output_file is None:
        output_file = "temp.srle2"
        remove_after = True
    else:
        remove_after = False
    subprocess.run(["rle2", "-c", input_file, intermediate],
                   check=True, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    subprocess.run(["szip", "-b41o3", intermediate, output_file],
                   check=True, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    size = os.path.getsize(output_file)
    os.remove(intermediate)
    if remove_after:
        os.remove(output_file)
    return size

def compress_with_snappy(input_file, output_file=None):
    """Compress using snappy (scmd)."""
    if output_file is None:
        output_file = "temp.snpz"
        remove_after = True
    else:
        remove_after = False
    subprocess.run(["scmd", "-c", input_file, output_file],
                   check=True, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    size = os.path.getsize(output_file)
    if remove_after:
        os.remove(output_file)
    return size

def compress_with_rle2_data(input_file):
    """
    Compress using rle2 and return the compressed data as bytes.
    Writes to a temporary file, reads its content, then deletes it.
    """
    temp_file = "temp.rle2"
    subprocess.run(["rle2", "-c", input_file, temp_file],
                   check=True, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    with open(temp_file, "rb") as f:
        data = f.read()
    os.remove(temp_file)
    return data

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
    Compare two byte arrays (of equal length). For each byte in the current frame:
      - If it differs from the corresponding byte in the previous frame, output the current byte.
      - Otherwise, output 0.
    Returns a new bytes object.
    """
    return bytes((curr if curr != prev else 0) for prev, curr in zip(prev_frame, curr_frame))

# ----- Main Testing Function -----
def main(frames_dir, original_frame_rate, target_frame_rate):
    skip = original_frame_rate // target_frame_rate  # e.g., 30/30 = 1; if 30/6, then 5.
    frames_per_second = target_frame_rate  # Number of frames per 1-second bucket.

    # CSV output filename includes the target frame rate.
    output_csv = os.path.join("tests", f"compare_compressions_movie_{target_frame_rate:02d}.csv")

    # Load and sort all .rgba2 frame files.
    frame_files = load_sorted_frames(frames_dir)
    if not frame_files:
        print("No .rgba2 files found in", frames_dir)
        return
    total_frames = len(frame_files)

    # Create a dummy "previous frame" (full-alpha black) using the size of the first frame.
    dummy_size = get_file_size(frame_files[0])
    prev_frame = bytes([0xC0] * dummy_size)

    # Prepare accumulators for each 1-second bucket.
    # For individual tests (using SRLE2):
    indiv_orig_sum = 0          # Sum of original (raw) frame sizes.
    indiv_diffed_sum = 0        # Sum of diffed frames compressed individually.
    indiv_nodiff_sum = 0        # Sum of nondiffed frames compressed individually.
    # For combined tests:
    combined_diffed_data = bytearray()  # Accumulate RLE2-compressed diffed data.
    combined_nodiff_data = bytearray()    # Accumulate RLE2-compressed nondiffed data.

    # We'll record one row per 1-second bucket.
    stats = []  # Each row: [second, orig_total, diffed_indiv, nodiff_indiv, diffed_combined, nodiff_combined]

    selected_indices = list(range(0, total_frames, skip))
    for count, idx in enumerate(selected_indices, start=1):
        frame_path = frame_files[idx]
        current_frame = read_frame(frame_path)
        frame_size = len(current_frame)
        indiv_orig_sum += frame_size

        # --- DIFFERENCED (diffed) variant ---
        diffed_frame = compare_frames(prev_frame, current_frame)
        prev_frame = current_frame  # Update for next iteration

        # Write diffed frame to a temporary file, compress individually using SRLE2.
        temp_diffed = "temp_diffed.rgba2"
        with open(temp_diffed, "wb") as f:
            f.write(diffed_frame)
        diffed_indiv_size = compress_with_srle2(temp_diffed)
        os.remove(temp_diffed)
        indiv_diffed_sum += diffed_indiv_size

        # For combined test, compress diffed frame with RLE2 and append.
        temp_for_rle_diffed = "temp_for_rle_diffed.rgba2"
        with open(temp_for_rle_diffed, "wb") as f:
            f.write(diffed_frame)
        diffed_rle2_data = compress_with_rle2_data(temp_for_rle_diffed)
        combined_diffed_data.extend(diffed_rle2_data)

        # --- NON-DIFFERENCED (nodiff) variant ---
        temp_nodiff = "temp_nodiff.rgba2"
        with open(temp_nodiff, "wb") as f:
            f.write(current_frame)
        nodiff_indiv_size = compress_with_srle2(temp_nodiff)
        os.remove(temp_nodiff)
        indiv_nodiff_sum += nodiff_indiv_size

        # For combined test, compress nondiffed frame with RLE2 and append.
        temp_for_rle_nodiff = "temp_for_rle_nodiff.rgba2"
        with open(temp_for_rle_nodiff, "wb") as f:
            f.write(current_frame)
        nodiff_rle2_data = compress_with_rle2_data(temp_for_rle_nodiff)
        combined_nodiff_data.extend(nodiff_rle2_data)

        # Once we've processed a full second's worth of frames, run the combined test.
        if count % frames_per_second == 0:
            second_index = count // frames_per_second

            # Combined diffed: compress the concatenated RLE2 data with SZIP.
            temp_combined_diffed = "temp_combined_diffed.rgba2"
            with open(temp_combined_diffed, "wb") as f:
                f.write(combined_diffed_data)
            combined_diffed_size = compress_with_szip_b41o3(temp_combined_diffed)
            os.remove(temp_combined_diffed)

            # Combined nondiffed: compress the concatenated RLE2 data with SZIP.
            temp_combined_nodiff = "temp_combined_nodiff.rgba2"
            with open(temp_combined_nodiff, "wb") as f:
                f.write(combined_nodiff_data)
            combined_nodiff_size = compress_with_szip_b41o3(temp_combined_nodiff)
            os.remove(temp_combined_nodiff)

            stats.append([second_index,
                          indiv_orig_sum,
                          indiv_diffed_sum,
                          indiv_nodiff_sum,
                          combined_diffed_size,
                          combined_nodiff_size])
            # Reset accumulators for next 1-second bucket.
            indiv_orig_sum = 0
            indiv_diffed_sum = 0
            indiv_nodiff_sum = 0
            combined_diffed_data = bytearray()
            combined_nodiff_data = bytearray()

        print(f"\rProcessed frame {count} of {len(selected_indices)}", end="", flush=True)

    print("\nWriting CSV data...")
    os.makedirs(os.path.dirname(output_csv), exist_ok=True)
    with open(output_csv, "w", newline="") as csvfile:
        writer = csv.writer(csvfile)
        writer.writerow(["second", "original_bytes", "diffed_indiv_bytes", "nodiff_indiv_bytes",
                         "diffed_combined_bytes", "nodiff_combined_bytes"])
        writer.writerows(stats)
    print("CSV written to", output_csv)

if __name__ == "__main__":
    frames_dir = "/home/smith/Agon/mystuff/assets/video/frames/"
    original_frame_rate = 30  # frames per second in the source
    target_frame_rate = 6    # desired sampling rate (i.e. 1-second buckets)
    main(frames_dir, original_frame_rate, target_frame_rate)

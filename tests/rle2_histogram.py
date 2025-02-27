#!/usr/bin/env python3
import os
import glob
import csv
import subprocess
from collections import defaultdict
import pandas as pd
import matplotlib.pyplot as plt

# Constants
HEADER_SIZE = 14
TEMP_RLE_FILE = "temp_rle2.rle2"
TEMP_DIFF_FILE = "temp_diff.rgba2"

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

def compress_to_rle2(input_file, output_file):
    """
    Compresses an .rgba2 file to an .rle2 file using the `rle2 -c` command.
    """
    try:
        subprocess.run(["rle2", "-c", input_file, output_file],
                       check=True, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
        return True
    except subprocess.CalledProcessError:
        print(f"Error compressing {input_file} to RLE2 format.")
        return False

def parse_rle2_file(filename):
    """
    Parses an RLE2-encoded file and returns:
      - total_pixels: total number of decoded pixels.
      - run_hist: a dict mapping run_length to count.
    """
    with open(filename, "rb") as f:
        data = f.read()

    if len(data) < HEADER_SIZE:
        print(f"Skipping {filename}: too small to be valid.")
        return None

    i = HEADER_SIZE
    total_pixels = 0
    run_hist = defaultdict(int)
    while i < len(data):
        cmd = data[i]
        if cmd & 0x80:
            total_pixels += 1
            run_hist[1] += 1
            i += 1
        else:
            run_length = (cmd & 0x7F) + 3
            total_pixels += run_length
            run_hist[run_length] += 1
            i += 2
    return {"total_pixels": total_pixels, "run_hist": dict(run_hist)}

def process_frame_diffed(curr_frame, prev_frame):
    """
    Computes diff from previous frame, writes to a temp file, compresses, analyzes, and deletes.
    Returns analysis (augmented with original and compressed file sizes) and updates prev_frame.
    """
    diff_frame = compute_diff_frame(prev_frame, curr_frame)
    orig_size = len(diff_frame)

    with open(TEMP_DIFF_FILE, "wb") as f:
        f.write(diff_frame)

    if not compress_to_rle2(TEMP_DIFF_FILE, TEMP_RLE_FILE):
        os.remove(TEMP_DIFF_FILE)
        return None, curr_frame  # still update prev_frame

    comp_size = os.path.getsize(TEMP_RLE_FILE)
    analysis = parse_rle2_file(TEMP_RLE_FILE)
    if analysis is not None:
        analysis["orig_size"] = orig_size
        analysis["comp_size"] = comp_size

    os.remove(TEMP_DIFF_FILE)
    os.remove(TEMP_RLE_FILE)
    return analysis, curr_frame

def process_frame_nondiffed(filename):
    """
    Processes a nondiffed .rgba2 frame: compresses it via rle2, parses, then deletes the temp file.
    Returns the analysis (augmented with original and compressed file sizes).
    """
    orig_size = os.path.getsize(filename)
    if not compress_to_rle2(filename, TEMP_RLE_FILE):
        return None

    comp_size = os.path.getsize(TEMP_RLE_FILE)
    analysis = parse_rle2_file(TEMP_RLE_FILE)
    if analysis is not None:
        analysis["orig_size"] = orig_size
        analysis["comp_size"] = comp_size

    os.remove(TEMP_RLE_FILE)
    return analysis

def load_sorted_files(directory):
    """
    Returns a sorted list of full paths to .rgba2 files in the directory.
    Sorted by filename.
    """
    files = glob.glob(os.path.join(directory, "*.rgba2"))
    files.sort()
    return files

def combine_analysis(analyses):
    """
    Combines a list of analysis dictionaries into a single summary,
    summing up total_pixels, run_hist, original sizes, and compressed sizes.
    """
    total_pixels = 0
    run_hist = defaultdict(int)
    total_orig_size = 0
    total_comp_size = 0
    for a in analyses:
        total_pixels += a["total_pixels"]
        total_orig_size += a.get("orig_size", 0)
        total_comp_size += a.get("comp_size", 0)
        for run_length, count in a["run_hist"].items():
            run_hist[run_length] += count
    return {"total_pixels": total_pixels,
            "run_hist": dict(run_hist),
            "orig_size": total_orig_size,
            "comp_size": total_comp_size}

def write_csv_report(groups, output_file):
    """
    Writes a CSV file (rows: each run length) with columns: Run Length, Diffed Count, Nondiffed Count.
    """
    os.makedirs(os.path.dirname(output_file), exist_ok=True)
    all_run_lengths = set()
    for group in groups.values():
        for analysis in group:
            all_run_lengths.update(analysis["run_hist"].keys())
    sorted_run_lengths = sorted(all_run_lengths)
    
    # Combine analysis for each group
    diffed_combined = combine_analysis(groups["diffed"]) if groups["diffed"] else {"run_hist": {}}
    nondiffed_combined = combine_analysis(groups["nondiffed"]) if groups["nondiffed"] else {"run_hist": {}}
    
    with open(output_file, "w", newline="") as csvfile:
        writer = csv.writer(csvfile)
        writer.writerow(["Run Length", "Diffed Count", "Nondiffed Count"])
        for rl in sorted_run_lengths:
            writer.writerow([
                rl,
                diffed_combined["run_hist"].get(rl, 0),
                nondiffed_combined["run_hist"].get(rl, 0)
            ])

def analyze_directory(directory, start_frame, num_frames):
    """
    Scans .rgba2 files in the given directory, compresses each one, analyzes it,
    and groups results into "diffed" and "nondiffed" categories.

    - If start_frame > 0, we preload the previous frame (start_frame-1) into `prev_frame`,
      so the first processed frame (start_frame) will be properly diffed.
    - We then only *process* frames in [start_frame : start_frame + num_frames].
    """
    all_files = load_sorted_files(directory)
    # Quick print to confirm which directory and frames
    print(f"Analyzing frames in {directory}")

    # Safety check if out of range
    if start_frame >= len(all_files):
        print("Error: start_frame is beyond the number of available files.")
        return {"diffed": [], "nondiffed": []}

    # Preload prev_frame if start_frame > 0
    prev_frame = None
    if start_frame > 0:
        # Read the frame at index (start_frame - 1) for diff reference
        with open(all_files[start_frame - 1], "rb") as f:
            prev_frame = f.read()

    # Slice the frames we actually want to *process*
    files = all_files[start_frame : start_frame + num_frames]

    groups = {"diffed": [], "nondiffed": []}
    for fn in files:
        with open(fn, "rb") as f:
            curr_frame = f.read()

        # Diffed analysis
        analysis_diffed, prev_frame = process_frame_diffed(curr_frame, prev_frame)
        if analysis_diffed:
            groups["diffed"].append(analysis_diffed)

        # Nondiffed analysis
        analysis_nondiffed = process_frame_nondiffed(fn)
        if analysis_nondiffed:
            groups["nondiffed"].append(analysis_nondiffed)

    return groups

def main():
    global output_csv

    # Run analysis and generate CSV data
    groups = analyze_directory(frames_dir, start_frame, num_frames)
    write_csv_report(groups, output_csv)
    print(f"Histogram written to {output_csv}")

    # Combine for compression metrics
    diffed_combined = combine_analysis(groups["diffed"]) if groups["diffed"] else {"orig_size": 0, "comp_size": 0}
    nondiffed_combined = combine_analysis(groups["nondiffed"]) if groups["nondiffed"] else {"orig_size": 0, "comp_size": 0}

    # Compute compression ratios
    compression_ratio_diffed = 0
    compression_ratio_nondiffed = 0
    if diffed_combined["orig_size"] > 0:
        compression_ratio_diffed = (diffed_combined["comp_size"] / diffed_combined["orig_size"]) * 100
    if nondiffed_combined["orig_size"] > 0:
        compression_ratio_nondiffed = (nondiffed_combined["comp_size"] / nondiffed_combined["orig_size"]) * 100

    print("\n=== Compression Effectiveness Metrics ===")
    print(f"Diffed Frames - Original Size: {diffed_combined['orig_size']} bytes, "
          f"Compressed Size: {diffed_combined['comp_size']} bytes, "
          f"Compression Ratio: {compression_ratio_diffed:.2f}%")
    print(f"Nondiffed Frames - Original Size: {nondiffed_combined['orig_size']} bytes, "
          f"Compressed Size: {nondiffed_combined['comp_size']} bytes, "
          f"Compression Ratio: {compression_ratio_nondiffed:.2f}%")

    # Create a bar chart (log y-axis)
    df = pd.read_csv(output_csv)
    plt.figure(figsize=(10, 6))
    ax = df.plot.bar(
        x="Run Length",
        y=["Diffed Count", "Nondiffed Count"],
        log=True,
        figsize=(10, 6),
        width=0.7
    )
    ax.set_title("Run Length Histogram (Log Scale on Counts)")
    ax.set_ylabel("Count (log scale)")
    ax.set_xlabel("Run Length")
    plt.xticks(rotation=0)
    plt.tight_layout()

    plot_filename = output_csv.replace(".csv", ".png")
    plt.savefig(plot_filename)
    print(f"Histogram plot saved as {plot_filename}")
    # plt.show()

    # # Print descriptive stats
    # print("\n=== Descriptive Statistics for Diffed Count ===")
    # print(df["Diffed Count"].describe())
    # print("\n=== Descriptive Statistics for Nondiffed Count ===")
    # print(df["Nondiffed Count"].describe())

if __name__ == "__main__":
    # --- Configuration ---
    frames_dir = "/home/smith/Agon/mystuff/assets/video/frames/" 
    frames_dir = "/home/smith/Agon/mystuff/assets/video/diffs_RGB_bayer"
    start_frame = 1
    num_frames = 1799

    # Make output filename dynamic
    output_csv = f"frames/rle2_histogram_start{start_frame}_count{num_frames}.csv"
    os.makedirs(os.path.dirname(output_csv), exist_ok=True)

    main()

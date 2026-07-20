#!/usr/bin/env python3
import os
import re
import csv
import subprocess
import math

### Helper Compression Functions ###
def get_file_size(path):
    return os.path.getsize(path)

def compress_with_szip_b41o3(input_file, output_file=None):
    """Compress file using: szip -b41o3 <input_file> <output_file>.
    If output_file is None, uses a temporary file and deletes it."""
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

def compress_with_rle2_data(input_file):
    """
    Compress input_file with rle2 (-c) and return the compressed data as bytes.
    """
    temp_file = "temp.rle2"
    subprocess.run(["rle2", "-c", input_file, temp_file],
                   check=True, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    with open(temp_file, "rb") as f:
        data = f.read()
    os.remove(temp_file)
    return data

def compress_bytes_szip(data):
    """
    Write 'data' to a temporary file, compress with SZIP (-b41o3), and return compressed size.
    """
    temp_in = "temp_data.bin"
    with open(temp_in, "wb") as f:
        f.write(data)
    size = compress_with_szip_b41o3(temp_in)
    os.remove(temp_in)
    return size

def compress_bytes_rle_szip(data):
    """
    Write 'data' to a temporary file, compress it with RLE2 to get intermediate bytes,
    then compress those bytes with SZIP (-b41o3) and return the final size.
    """
    temp_in = "temp_data.bin"
    with open(temp_in, "wb") as f:
        f.write(data)
    rle_data = compress_with_rle2_data(temp_in)
    os.remove(temp_in)
    temp_rle = "temp_rle.bin"
    with open(temp_rle, "wb") as f:
        f.write(rle_data)
    size = compress_with_szip_b41o3(temp_rle)
    os.remove(temp_rle)
    return size

### Frame Processing Helpers ###
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

def compare_frames(prev_frame, curr_frame):
    """
    For each byte in curr_frame, if it differs from the corresponding byte in prev_frame,
    output the current byte; otherwise output 0.
    Returns a new bytes object.
    """
    return bytes((curr if curr != prev else 0) for prev, curr in zip(prev_frame, curr_frame))

def interleave_frames(frames):
    """
    Given a list of bytes objects (frames), return a new bytes object with the data interleaved.
    Assumes all frames have the same length.
    """
    if not frames:
        return b""
    frame_len = len(frames[0])
    interleaved = bytearray()
    for i in range(frame_len):
        for frame in frames:
            interleaved.append(frame[i])
    return bytes(interleaved)

def sequential_concat(frames):
    """
    Concatenate a list of frames (bytes objects) in order.
    """
    return b"".join(frames)

### Main Testing Function ###
def main(frames_dir, original_frame_rate, target_frame_rate):
    # Determine how many source frames to skip to achieve target frame rate.
    skip = original_frame_rate // target_frame_rate  # e.g., if 30 -> 10 fps, skip = 3.
    frames_per_bucket = target_frame_rate  # Each bucket represents 1 second.
    
    output_csv = os.path.join("tests", f"compare_compressions_interleaved_{target_frame_rate:02d}.csv")

    # Load sorted .rgba2 frames.
    frame_files = load_sorted_frames(frames_dir)
    if not frame_files:
        print("No .rgba2 files found in", frames_dir)
        return
    total_frames = len(frame_files)
    
    # Initialize a dummy previous frame (full-alpha black) for diffing.
    dummy_size = get_file_size(frame_files[0])
    prev_frame = bytes([0xC0] * dummy_size)
    
    # Prepare accumulators per bucket.
    # We'll accumulate lists of frames (diffed and nondiffed) for combined tests,
    # and also sum individual compressed sizes.
    bucket_idx = 0
    orig_sum = 0
    indiv_diffed_sum = 0
    indiv_nodiff_sum = 0
    
    # Lists to accumulate raw frames (for combined tests)
    diffed_frames_list = []
    nodiff_frames_list = []
    
    # Results: one row per bucket.
    # Columns: bucket, original_bytes, indiv_diffed, indiv_nodiff,
    # sequential_diffed, sequential_nodiff,
    # interleaved_diffed, interleaved_nodiff,
    # interleaved_rle_diffed, interleaved_rle_nodiff.
    stats = []
    
    # Select frames based on skipping.
    selected_indices = list(range(0, total_frames, skip))
    for count, idx in enumerate(selected_indices, start=1):
        frame_path = frame_files[idx]
        current_frame = read_frame(frame_path)
        frame_size = len(current_frame)
        orig_sum += frame_size
        
        # --- Diffed variant ---
        diffed_frame = compare_frames(prev_frame, current_frame)
        prev_frame = current_frame  # update for next iteration
        # Compress diffed frame individually with SZIP.
        temp_diffed = "temp_diffed.rgba2"
        with open(temp_diffed, "wb") as f:
            f.write(diffed_frame)
        diffed_indiv_size = compress_with_szip_b41o3(temp_diffed)
        os.remove(temp_diffed)
        indiv_diffed_sum += diffed_indiv_size
        diffed_frames_list.append(diffed_frame)
        
        # --- Non-diffed (raw) variant ---
        temp_nodiff = "temp_nodiff.rgba2"
        with open(temp_nodiff, "wb") as f:
            f.write(current_frame)
        nodiff_indiv_size = compress_with_szip_b41o3(temp_nodiff)
        os.remove(temp_nodiff)
        indiv_nodiff_sum += nodiff_indiv_size
        nodiff_frames_list.append(current_frame)
        
        # When a full bucket (1 second) is collected:
        if count % frames_per_bucket == 0:
            bucket_idx += 1
            
            # Sequential combined: simply concatenate the frames.
            seq_diffed = sequential_concat(diffed_frames_list)
            seq_nodiff = sequential_concat(nodiff_frames_list)
            sequential_diffed_size = compress_bytes_szip(seq_diffed)
            sequential_nodiff_size = compress_bytes_szip(seq_nodiff)
            
            # Interleaved combined: interleave the bucket's frames.
            inter_diffed = interleave_frames(diffed_frames_list)
            inter_nodiff = interleave_frames(nodiff_frames_list)
            interleaved_diffed_size = compress_bytes_szip(inter_diffed)
            interleaved_nodiff_size = compress_bytes_szip(inter_diffed)  # Oops! Should be nodiff.
            interleaved_nodiff_size = compress_bytes_szip(interleave_frames(nodiff_frames_list))
            
            # Interleaved with RLE precompression.
            interleaved_rle_diffed_size = compress_bytes_rle_szip(inter_diffed)
            interleaved_rle_nodiff_size = compress_bytes_rle_szip(interleave_frames(nodiff_frames_list))
            
            stats.append([bucket_idx,
                          orig_sum,
                          indiv_diffed_sum,
                          indiv_nodiff_sum,
                          sequential_diffed_size,
                          sequential_nodiff_size,
                          interleaved_diffed_size,
                          interleaved_nodiff_size,
                          interleaved_rle_diffed_size,
                          interleaved_rle_nodiff_size])
            
            # Reset accumulators for next bucket.
            orig_sum = 0
            indiv_diffed_sum = 0
            indiv_nodiff_sum = 0
            diffed_frames_list = []
            nodiff_frames_list = []
            
        print(f"\rProcessed frame {count} of {len(selected_indices)}", end="", flush=True)
    
    print("\nWriting CSV data...")
    os.makedirs(os.path.dirname(output_csv), exist_ok=True)
    with open(output_csv, "w", newline="") as csvfile:
        writer = csv.writer(csvfile)
        writer.writerow(["bucket",
                         "original_bytes",
                         "indiv_diffed_bytes",
                         "indiv_nodiff_bytes",
                         "sequential_diffed_bytes",
                         "sequential_nodiff_bytes",
                         "interleaved_diffed_bytes",
                         "interleaved_nodiff_bytes",
                         "interleaved_rle_diffed_bytes",
                         "interleaved_rle_nodiff_bytes"])
        writer.writerows(stats)
    print("CSV written to", output_csv)

if __name__ == "__main__":
    # Adjust the following paths and frame rates as needed.
    frames_dir = "/home/smith/Agon/mystuff/assets/video/frames/"
    original_frame_rate = 30  # frames per second in source
    target_frame_rate = 30    # desired frames per second (1-second buckets)
    main(frames_dir, original_frame_rate, target_frame_rate)

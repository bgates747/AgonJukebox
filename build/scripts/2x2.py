#!/usr/bin/env python3
import os
import glob
import csv
import numpy as np
from PIL import Image

#!/usr/bin/env python3
import os
import glob
import csv
import numpy as np
from PIL import Image

def main():
   
    # Get a sorted list of all .rgba2 files.
    rgba2_files = sorted(glob.glob(os.path.join(frames_dir, "*.rgba2")))
    total_frames = len(rgba2_files)
    
    # Determine image dimensions from a sample PNG (we assume all frames have the same dimensions).
    with Image.open(png_path) as img:
        width, height = img.size
    total_pixels = width * height
    print(f"Detected image dimensions: {width} x {height} (total pixels: {total_pixels})")
    
    # We'll group every 4 pixels. Each pixel is 6 bits (values 0–63), so 4 pixels pack into 24 bits (3 bytes).
    group_size = 4
    results = []
    
    for idx, file in enumerate(rgba2_files, start=1):
        print(f"\rProcessing frame {idx} of {total_frames}", end="", flush=True)
        data = np.fromfile(file, dtype=np.uint8)
        if data.size != total_pixels:
            print(f"\nWarning: File {file} size mismatch (expected {total_pixels} bytes, got {data.size}).")
            continue
        
        # Ensure the number of pixels is divisible by group_size.
        num_complete_groups = data.size // group_size
        if data.size % group_size != 0:
            print(f"\nWarning: File {file} pixel count not divisible by {group_size}, ignoring trailing pixels.")
        
        # Reshape into groups of 4 consecutive pixels.
        groups = data[:num_complete_groups * group_size].reshape(num_complete_groups, group_size)
        
        # Mask each pixel to its lower 6 bits (values 0-63).
        groups = groups & 0x3F
        
        # Pack the 4 pixels into one 24-bit integer.
        # We assign 6 bits per pixel:
        #   pixel0 occupies the top 6 bits (bits 18-23)
        #   pixel1 occupies bits 12-17
        #   pixel2 occupies bits 6-11
        #   pixel3 occupies bits 0-5
        packed = (
            (groups[:, 0].astype(np.uint32) << 18) |
            (groups[:, 1].astype(np.uint32) << 12) |
            (groups[:, 2].astype(np.uint32) << 6)  |
            groups[:, 3].astype(np.uint32)
        )
        
        # Count the number of unique packed values.
        unique_packed = np.unique(packed)
        unique_count = unique_packed.size
        
        results.append((os.path.basename(file), unique_count))
    
    print("")
    
    # Write the results to a CSV file.
    with open(csv_path, "w", newline="") as csvfile:
        writer = csv.writer(csvfile)
        writer.writerow(["Frame", "Unique Packed Groups"])
        writer.writerows(results)
    
    print(f"CSV data written to {csv_path}")

if __name__ == "__main__":
    csv_path = "/home/smith/Agon/mystuff/AgonJukebox/assets/video/packed.txt"

    frames_dir = "/home/smith/Agon/mystuff/AgonJukebox/assets/video/diffs_RGB_bayer"
    png_path = os.path.join(frames_dir, "frame_00000_diff.png")

    # frames_dir = "/home/smith/Agon/mystuff/AgonJukebox/assets/video/frames"
    # png_path = os.path.join(frames_dir, "frame_00000.png")
    main()

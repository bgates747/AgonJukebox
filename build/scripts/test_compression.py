import os
import csv
import subprocess
import time
from pathlib import Path

def main():
    # Define the directory with the asset frames
    frames_dir = Path("assets/video/frames")
    # Get all files ending with .rgba2 in the directory
    rgba2_files = list(frames_dir.glob("*.rgba2"))
    
    # Define the CSV file path in the same directory
    csv_path = frames_dir / "compression_results.csv"
    
    # Open the CSV file for writing and write the header row.
    with open(csv_path, "w", newline="") as csvfile:
        csv_writer = csv.writer(csvfile)
        # CSV headers: filename, original size, compress size, compress time, szip size, szip time.
        csv_writer.writerow(["filename", "original_size", "compress_size", "compress_time", "szip_size", "szip_time"])
        
        # Process each file.
        for file in rgba2_files:
            # Get the original file size.
            orig_size = file.stat().st_size
            
            # -------------------------------
            # Run the compress command.
            # Output file is <filename>.rgba2.cmp
            cmp_file = file.parent / (file.name + ".cmp")
            start_time = time.perf_counter()
            subprocess.run(["compress", str(file), str(cmp_file)], check=True)
            compress_time = time.perf_counter() - start_time
            # Get the size of the compressed file.
            compress_size = cmp_file.stat().st_size if cmp_file.exists() else 0
            
            # -------------------------------
            # Run the szip command.
            # Output file is <filename>.rgba2.szip
            szip_file = file.parent / (file.name + ".szip")
            start_time = time.perf_counter()
            subprocess.run(["szip", str(file), str(szip_file)], check=True)
            szip_time = time.perf_counter() - start_time
            # Get the size of the compressed file.
            szip_size = szip_file.stat().st_size if szip_file.exists() else 0
            
            # Write the result row to the CSV file.
            csv_writer.writerow([
                file.name,
                orig_size,
                compress_size,
                f"{compress_time:.6f}",
                szip_size,
                f"{szip_time:.6f}"
            ])

if __name__ == "__main__":
    main()

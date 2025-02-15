import os
import glob
import subprocess
import time

# Define compression parameters
SZIP_OPTIONS = [
    ["-b1", "-o6", "-r1"],  # Baseline (default)
    # ["-b10", "-o6", "-r1"],  # Larger block size (better compression, more RAM)
    # ["-b1", "-o10", "-r1"],  # Higher order (better compression, slower)
    ["-b1", "-o0", "-r1"],  # BWT mode (max compression)
    # ["-b1", "-o6", "-r3"],  # Larger record size (for RGB)
    # ["-b1", "-o6", "-r1", "-i"],  # Incremental mode
]

NUM_TRIALS = 1  # Number of times to run each test
RESULTS_FILE = "compression_results.txt"  # Output file

def benchmark_rgba2_files(dir_path):
    """Runs multiple compression methods with timing benchmarks and logs results to a file."""
    files = [f for f in glob.glob(os.path.join(dir_path, "*.rgba2")) if not f.endswith(".rgba2.szip.rgba2")]

    results_path = os.path.join(dir_path, RESULTS_FILE)

    with open(results_path, "w") as results_file:
        # Write header
        results_file.write(f"{'File':<30}{'Method':<25}{'Avg Comp Time (s)':<18}{'Avg Decomp Time (s)':<20}{'Compressed Size':<15}{'Compression Ratio':<10}\n")
        results_file.write("=" * 130 + "\n")

        for file_path in files:
            file_name = os.path.basename(file_path)
            original_size = os.path.getsize(file_path)
            print(f"Processing: {file_name} (Size: {original_size} bytes)")

            for options in SZIP_OPTIONS:
                compressed_file = f"{file_path}.szip"

                # Run compression trials
                start_time = time.time()
                for _ in range(NUM_TRIALS):
                    subprocess.run(["szip"] + options + [file_path, compressed_file], check=True, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
                total_comp_time = time.time() - start_time
                avg_comp_time = total_comp_time / NUM_TRIALS

                compressed_size = os.path.getsize(compressed_file)

                # Run decompression trials
                decompressed_file = f"{file_path}.decompressed"
                start_time = time.time()
                for _ in range(NUM_TRIALS):
                    subprocess.run(["szip","-d", compressed_file, decompressed_file], check=True, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
                total_decomp_time = time.time() - start_time
                avg_decomp_time = total_decomp_time / NUM_TRIALS

                compression_ratio = round(compressed_size / original_size, 4)

                # Write results to file
                results_file.write(f"{file_name:<30}{'Szip ' + ' '.join(options):<25}{avg_comp_time:<18.5f}{avg_decomp_time:<20.5f}{compressed_size:<15}{compression_ratio:<10}\n")

                # Clean up
                os.remove(compressed_file)
                os.remove(decompressed_file)

        print("\nProcessing complete. Results saved to:", results_path)

# def do_compression(dir_path):
#     # Find all .rgba2 files, excluding those ending in .rgba2.szip.rgba2
#     files = [f for f in glob.glob(os.path.join(dir_path, "*.rgba2")) if not f.endswith(".rgba2.szip.rgba2")]

#     for file_path in files:
#         file_name = os.path.basename(file_path)
#         print(f"Processing: {file_name}")

#         # # Generate hex dump of original file
#         # with open(f"{file_path}.txt", "w") as hex_out:
#         #     subprocess.run(["xxd", "-g1", "-C", file_path], stdout=hex_out, check=True)

#         # Compress file using chosen szip options
#         compressed_file = f"{file_path}.szip"
#         compress_rgba2_file(("szip", "-b1", "-o0", "-r1"), file_path, compressed_file)

#         # # Generate hex dump of compressed file
#         # with open(f"{compressed_file}.txt", "w") as hex_out:
#         #     subprocess.run(["xxd", "-g1", "-C", compressed_file], stdout=hex_out, check=True)

#         # # Decompress file using szip
#         # decompressed_file = f"{compressed_file}.rgba2"
#         # subprocess.run(["szip", "-d", compressed_file, decompressed_file], check=True)

#         # # Generate hex dump of decompressed file
#         # with open(f"{decompressed_file}.txt", "w") as hex_out:
#         #     subprocess.run(["xxd", "-g1", "-C", decompressed_file], stdout=hex_out, check=True)

#         # Compress file using TurboVega compression
#         compressed_file = f"{file_path}.tvc"
#         compress_rgba2_file(("compress",), file_path, compressed_file)

#         print(f"Finished: {file_name}")


def compress_and_measure(command, file_path, compressed_file):
    """Run compression command and measure time and file size."""
    start_time = time.time()
    subprocess.run(command, check=True, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    elapsed_time = time.time() - start_time
    compressed_size = os.path.getsize(compressed_file) if os.path.exists(compressed_file) else 0
    return elapsed_time, compressed_size

def compress_rgba2_file(command, file_path, compressed_file):
    # Run compression with measurement
    elapsed_time, compressed_size = compress_and_measure(list(command) + [file_path, compressed_file], file_path, compressed_file)

    # Compute compression ratio
    original_size = os.path.getsize(file_path)
    compression_ratio = ((compressed_size / original_size)) * 100

    # Extract the compression method name from the first element of the command tuple
    compression_method = os.path.basename(command[0])

    # Output formatted message
    print(f"{compression_method} compressed {os.path.basename(file_path)} from {original_size} to {compressed_size} bytes "
          f"({compression_ratio:.2f}%) in {elapsed_time:.4f} seconds.")
    
def do_compression(dir_path):
    # Find all .rgba2 files, excluding those ending in .rgba2.szip.rgba2
    files = [f for f in glob.glob(os.path.join(dir_path, "*.rgba2")) if not f.endswith(".rgba2.szip.rgba2")]

    for file_path in files:
        # Compress file using chosen szip options
        compressed_file = f"{file_path}.szip"
        # compress_rgba2_file(("szip", "-b1", "-o0", "-r1"), file_path, compressed_file)
        compress_rgba2_file(("szip", "-b1", "-o6", "-r1"), file_path, compressed_file)

        # # Compress file using TurboVega compression
        # compressed_file = f"{file_path}.tvc"
        # compress_rgba2_file(("compress",), file_path, compressed_file)


if __name__ == "__main__":
    # dir_path = "tgt/video"
    dir_path = "assets/video/frames"
    do_compression(dir_path)
    # benchmark_rgba2_files(dir_path)
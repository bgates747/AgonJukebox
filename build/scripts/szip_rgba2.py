import os
import subprocess
import glob

def process_rgba2_files(dir_path):
    # Find all .rgba2 files, excluding those ending in .rgba2.szip.rgba2
    files = [f for f in glob.glob(os.path.join(dir_path, "*.rgba2")) if not f.endswith(".rgba2.szip.rgba2")]

    for file_path in files:
        file_name = os.path.basename(file_path)
        print(f"Processing: {file_name}")

        # # Generate hex dump of original file
        # with open(f"{file_path}.txt", "w") as hex_out:
        #     subprocess.run(["xxd", "-g1", "-C", file_path], stdout=hex_out, check=True)

        # # Compress file using szip
        compressed_file = f"{file_path}.szip"
        subprocess.run(["szip", "-b1", "-v0", "-r1", file_path, compressed_file], check=True)

        # # Generate hex dump of compressed file
        # with open(f"{compressed_file}.txt", "w") as hex_out:
        #     subprocess.run(["xxd", "-g1", "-C", compressed_file], stdout=hex_out, check=True)

        # # Decompress file using szip
        # decompressed_file = f"{compressed_file}.rgba2"
        # subprocess.run(["szip", "-d", "-v0", compressed_file, decompressed_file], check=True)

        # # Generate hex dump of decompressed file
        # with open(f"{decompressed_file}.txt", "w") as hex_out:
        #     subprocess.run(["xxd", "-g1", "-C", decompressed_file], stdout=hex_out, check=True)

        # Compress file using TurboVega compression
        compressed_file = f"{file_path}.tvc"
        subprocess.run(["compress", file_path, compressed_file], check=True)

        print(f"Finished: {file_name}")

if __name__ == "__main__":
    dir_path = "tgt/images"
    process_rgba2_files(dir_path)

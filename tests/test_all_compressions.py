#!/usr/bin/env python3
import agonutils as au
import os
import subprocess
from PIL import Image

def report_compression(compression_type, original_file, compressed_file):
    """Report the compression percentage for a file."""
    compressed_size = os.path.getsize(compressed_file)
    uncompressed_size = os.path.getsize(original_file)
    compression_percentage = (compressed_size / uncompressed_size) * 100
    print(f'{compression_type} percentage: {compression_percentage:.2f}%')

def main():
    # Convert PNG to palette-based RGBA2 file
    pil_img = Image.open(src_png_file)
    pil_img = au.convert_to_palette(pil_img, 64, palette_conversion_method, transparent_color)
    au.img_to_rgba2(pil_img, tgt_rgba2_file)

    subprocess.run(["szip", tgt_rgba2_file], check=True, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    report_compression("SZIP", tgt_rgba2_file, tgt_szip_file)

    # # Compress files using PC command-line tools
    # subprocess.run(["simz", "-c", tgt_rgba2_file, tgt_simz_file], check=True, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    # report_compression("SIMZ", tgt_rgba2_file, tgt_simz_file)

    # subprocess.run(["compress", tgt_rgba2_file, tgt_tvc_file], check=True, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    # report_compression("TVC", tgt_rgba2_file, tgt_tvc_file)
    
    # subprocess.run(["rlecompress", tgt_rgba2_file, f"{tgt_rgba2_file}.rle"], check=True, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    # report_compression("RLE", tgt_rgba2_file, f"{tgt_rgba2_file}.rle")

if __name__ == '__main__':
    # Set file paths
    base_file = "/home/smith/Agon/mystuff/AgonJukebox/tgt/images/rainbow_swirl"
    src_png_file = f"{base_file}.png"
    tgt_rgba2_file = f"{base_file}.rgba2"
    tgt_tvc_file = f"{tgt_rgba2_file}.tvc"
    tgt_szip_file = f"{tgt_rgba2_file}.szip"
    tgt_simz_file = f"{tgt_rgba2_file}.simz"

    palette_conversion_method = 'floyd'
    transparent_color = None

    main()



    # in_file = 'utils/rngcod13/frame_00005.rgba2'
    # out_file = f'{in_file}.simz'
    # un_zipped_file = f'{in_file}.rgba2'  # Decompressed file

    # print("=== Testing file-based simz_encode/simz_decode ===")

    # # Compress the file using the Python package functions
    # au.simz_encode(in_file, out_file)

    # # Decompress the file using the Python package functions
    # au.simz_decode(out_file, un_zipped_file)

    # # Compute compression percentage
    # compressed_size = os.path.getsize(out_file)
    # uncompressed_size = os.path.getsize(un_zipped_file)
    # compression_percentage = (compressed_size / uncompressed_size) * 100
    # print(f'Compression percentage: {compression_percentage:.2f}%')

    # # Compare original and decompressed files using diff
    # diff_result = os.system(f'diff {un_zipped_file} {in_file}')
    # print("File-based encode/decode:", "PASS" if diff_result == 0 else "FAIL")

    # print("\n=== Testing in-memory simz_encode_bytes/simz_decode_bytes ===")

    # # Read input file into a bytes buffer
    # with open(in_file, "rb") as f:
    #     input_bytes = f.read()

    # # Compress in-memory using package functions
    # compressed_bytes = au.simz_encode_bytes(input_bytes)

    # # Read compressed file and compare with in-memory compression output
    # with open(out_file, "rb") as f:
    #     file_compressed_bytes = f.read()

    # if compressed_bytes == file_compressed_bytes:
    #     print("In-memory compression matches file compression: PASS")
    # else:
    #     print("In-memory compression differs from file compression: FAIL")

    # # Decompress in-memory using package functions
    # decompressed_bytes = au.simz_decode_bytes(compressed_bytes)

    # # Compare with original input
    # if decompressed_bytes == input_bytes:
    #     print("In-memory decompression matches original input: PASS")
    # else:
    #     print("In-memory decompression differs from original input: FAIL")

    # print("\n=== Testing PC command-line simz tool ===")
    # # Test the PC command-line version by invoking it via subprocess.
    # # First, compress using the PC command-line tool.
    # subprocess.run(["simz", "-c", in_file, out_file], check=True, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    # # Then, decompress using the PC command-line tool.
    # subprocess.run(["simz", "-d", out_file, un_zipped_file], check=True, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    
    # # Compute compression percentage for PC command-line output
    # compressed_size = os.path.getsize(out_file)
    # uncompressed_size = os.path.getsize(un_zipped_file)
    # compression_percentage = (compressed_size / uncompressed_size) * 100
    # print(f'PC Command-line Compression percentage: {compression_percentage:.2f}%')
    
    # # Compare original and decompressed files using diff
    # diff_result = os.system(f'diff {un_zipped_file} {in_file}')
    # print("PC Command-line encode/decode:", "PASS" if diff_result == 0 else "FAIL")

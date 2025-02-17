#!/usr/bin/env python3
import numpy as np

def compress_file(input_file, output_file):
    """
    Compress a .rgba2 file using a dictionary of 4-pixel (24-bit) groups.
    Each pixel is 6 bits (bottom 6 bits of each byte).
    
    Output file layout:
      Header: 2 bytes = dictionary size (number of unique groups, as a 16-bit big-endian int)
              4 bytes = number of groups (32-bit big-endian int)
      Dictionary: For each unique group, 3 bytes (24 bits, big-endian)
      Encoded stream: Each group is replaced by a 12-bit index.
                      The 12-bit indices are packed consecutively (2 indices per 24-bit word).
    """
    # Read raw data from input_file
    with open(input_file, "rb") as f:
        raw = f.read()
    # Interpret data as unsigned bytes
    data = np.frombuffer(raw, dtype=np.uint8)
    # Mask out the top two bits (retain only 6 bits per pixel)
    data = data & 0x3F

    # Ensure the number of pixels is a multiple of 4; pad with zeros if necessary.
    num_pixels = len(data)
    if num_pixels % 4 != 0:
        pad = 4 - (num_pixels % 4)
        data = np.concatenate([data, np.zeros(pad, dtype=np.uint8)])
    num_pixels = len(data)
    
    # Group every 4 pixels (each group is 24 bits total)
    num_groups = num_pixels // 4
    groups = data.reshape(num_groups, 4)
    # Pack 4 pixels into a 24-bit integer:
    # p0 in bits 18-23, p1 in bits 12-17, p2 in bits 6-11, p3 in bits 0-5.
    group_values = ((groups[:, 0].astype(np.uint32) << 18) |
                    (groups[:, 1].astype(np.uint32) << 12) |
                    (groups[:, 2].astype(np.uint32) << 6)  |
                     groups[:, 3].astype(np.uint32))
    
    # Build a dictionary of unique group values.
    unique_groups, inverse_indices = np.unique(group_values, return_inverse=True)
    dict_size = unique_groups.shape[0]
    # For our scheme we expect dict_size <= 4096 (i.e. indices fit in 12 bits)
    if dict_size > 4096:
        raise ValueError(f"Too many unique groups: {dict_size} (exceeds 4096)")
    
    # inverse_indices now maps each group to its dictionary index (each fits in 12 bits)
    indices = inverse_indices  # numpy array of length num_groups, values in 0..dict_size-1

    # Pack these 12-bit indices into a byte stream.
    total_bits = num_groups * 12
    num_bytes = (total_bits + 7) // 8
    bit_buffer = 0
    bits_in_buffer = 0
    encoded_bytes = bytearray()
    for idx in indices:
        bit_buffer = (bit_buffer << 12) | int(idx)
        bits_in_buffer += 12
        # Extract whole bytes from the bit buffer.
        while bits_in_buffer >= 8:
            bits_in_buffer -= 8
            byte = (bit_buffer >> bits_in_buffer) & 0xFF
            encoded_bytes.append(byte)
    # If any bits remain, pad to complete the last byte.
    if bits_in_buffer > 0:
        byte = (bit_buffer << (8 - bits_in_buffer)) & 0xFF
        encoded_bytes.append(byte)
    
    # Build header: dictionary size (2 bytes, big-endian) and number of groups (4 bytes, big-endian).
    header = dict_size.to_bytes(2, byteorder="big") + num_groups.to_bytes(4, byteorder="big")
    
    # Build dictionary bytes: each unique group is stored as 3 bytes (24 bits, big-endian).
    dict_bytes = bytearray()
    for value in unique_groups:
        dict_bytes.extend(int(value).to_bytes(3, byteorder="big"))
    
    # Write header, dictionary, and encoded stream to output_file.
    with open(output_file, "wb") as f:
        f.write(header)
        f.write(dict_bytes)
        f.write(encoded_bytes)
    print(f"Compression complete: {input_file} -> {output_file}")
    print(f"  Number of groups: {num_groups}")
    print(f"  Dictionary size: {dict_size}")

def decompress_file(input_file, output_file):
    """
    Decompress a file produced by compress_file().
    
    Reads the header, reconstructs the dictionary, unpacks the 12-bit indices,
    and rebuilds the original 24-bit group values (and hence the 4 pixels per group).

    For each decompressed 6-bit pixel:
      1) Force alpha bits to 11 by OR with 0xC0.
      2) If the result == 0xF3 (pure magenta), store 0x00 (fully transparent).
    """
    with open(input_file, "rb") as f:
        data = f.read()
    # Header is the first 6 bytes.
    if len(data) < 6:
        raise ValueError("Input file too short (missing header)")
    dict_size = int.from_bytes(data[0:2], byteorder="big")
    num_groups = int.from_bytes(data[2:6], byteorder="big")
    
    # Next dict_size * 3 bytes are the dictionary entries.
    dict_bytes_len = dict_size * 3
    if len(data) < 6 + dict_bytes_len:
        raise ValueError("Input file too short (missing dictionary)")
    dict_bytes = data[6:6+dict_bytes_len]
    unique_groups = []
    for i in range(dict_size):
        value = int.from_bytes(dict_bytes[i*3 : i*3+3], byteorder="big")
        unique_groups.append(value)
    
    # The rest is the encoded pixel stream.
    encoded_bytes = data[6+dict_bytes_len:]
    
    # Unpack 12-bit indices from the encoded_bytes.
    indices = []
    bit_buffer = 0
    bits_in_buffer = 0
    for byte in encoded_bytes:
        bit_buffer = (bit_buffer << 8) | byte
        bits_in_buffer += 8
        while bits_in_buffer >= 12 and len(indices) < num_groups:
            bits_in_buffer -= 12
            idx = (bit_buffer >> bits_in_buffer) & 0xFFF
            indices.append(idx)
    if len(indices) != num_groups:
        raise ValueError("Mismatch in expected number of groups during decoding.")
    
    # Reconstruct the original group values using the dictionary.
    group_values = [unique_groups[idx] for idx in indices]
    
    # Unpack each 24-bit group into 4 pixels (each 6 bits).
    # p0 = bits 18-23, p1 = bits 12-17, p2 = bits 6-11, p3 = bits 0-5.
    # 1) Force alpha (bits 7-6 = 11) => OR with 0xC0.
    # 2) If == 0xF3 => store 0x00 (fully transparent).
    pixels = []
    for value in group_values:
        # Extract 6-bit channels
        p0_6 = (value >> 18) & 0x3F
        p1_6 = (value >> 12) & 0x3F
        p2_6 = (value >> 6)  & 0x3F
        p3_6 = value & 0x3F
        
        # Convert to 8-bit with alpha forced to 11
        p0_8 = p0_6 | 0xC0
        p1_8 = p1_6 | 0xC0
        p2_8 = p2_6 | 0xC0
        p3_8 = p3_6 | 0xC0
        
        # If the pixel is pure magenta w/ alpha => 0xF3, then store 0x00
        # i.e. fully transparent in our .rgba2 representation.
        if p0_8 == 0xF3:
            p0_8 = 0x00
        if p1_8 == 0xF3:
            p1_8 = 0x00
        if p2_8 == 0xF3:
            p2_8 = 0x00
        if p3_8 == 0xF3:
            p3_8 = 0x00
        
        pixels.extend([p0_8, p1_8, p2_8, p3_8])
    
    pixel_data = bytes(pixels)
    
    with open(output_file, "wb") as f:
        f.write(pixel_data)
    print(f"Decompression complete: {input_file} -> {output_file}")
    print(f"  Reconstructed {len(pixel_data)} pixels.")


# Example usage:
if __name__ == "__main__":
    in_file = "/home/smith/Agon/mystuff/assets/video/diffs_RGB_bayer/frame_00001_diff.rgba2"
    comp_file = f"{in_file}.agz"
    decomp_file = f"{comp_file}.rgba2"
    
    compress_file(in_file, comp_file)
    decompress_file(comp_file, decomp_file)

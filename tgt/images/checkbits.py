import sys
from collections import Counter

def count_top_bits(file_path):
    """Count occurrences of top two bits (bits 7 and 6) in a binary file."""
    counts = Counter()

    try:
        with open(file_path, "rb") as f:
            while (byte := f.read(1)):
                value = ord(byte)  # Get byte as integer
                top_bits = (value >> 6) & 0b11  # Extract bits 7 and 6
                counts[top_bits] += 1

    except FileNotFoundError:
        print(f"Error: File {file_path} not found.")
        sys.exit(1)

    # Display results
    print("Top two bits count:")
    print(f"  00 (Transparent)  : {counts[0b00]}")
    print(f"  01 (Unexpected)   : {counts[0b01]}")
    print(f"  10 (Unexpected)   : {counts[0b10]}")
    print(f"  11 (Opaque)       : {counts[0b11]}")

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python check_top_bits.py <file>")
        sys.exit(1)

    count_top_bits(sys.argv[1])

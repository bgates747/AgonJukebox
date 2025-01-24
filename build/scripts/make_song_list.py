import os

def write_raw_song_list(input_file, output_file):
    """
    Reads song names from a text file and writes them as raw bytes, padded to 256 characters, to a binary file.
    """
    # Ensure the output directory exists
    os.makedirs(os.path.dirname(output_file), exist_ok=True)

    # Read the input file
    with open(input_file, "r") as f_in:
        song_names = f_in.readlines()

    # Open the output file for writing in binary mode
    with open(output_file, "wb") as f_out:
        for song in song_names:
            # Strip leading/trailing whitespace and encode as ASCII
            ascii_values = [ord(c) for c in song.strip()]

            # Pad the ASCII values to 256 characters with zeroes
            padded_values = ascii_values + [0] * (256 - len(ascii_values))

            # Write the padded values as raw bytes to the file
            f_out.write(bytes(padded_values))

if __name__ == "__main__":
    # Input and output file paths
    input_path = "src/asm/song_list.txt"
    output_path = "src/asm/song_list.dat"

    # Write the raw song list to the binary file
    write_raw_song_list(input_path, output_path)

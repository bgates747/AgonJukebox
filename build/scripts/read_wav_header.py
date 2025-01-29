import struct

def read_wav_header(file_path):
    """Reads and parses the header of a WAV file according to the specified format."""
    with open(file_path, "rb") as f:
        header = f.read(44)  # WAV header is 44 bytes

    # Parse fields from the header
    riff = header[0:4].decode('ascii')
    file_size = struct.unpack('<I', header[4:8])[0]  # Little-endian unsigned int
    wave = header[8:12].decode('ascii')

    fmt = header[12:16].decode('ascii')
    fmt_chunk_size = struct.unpack('<I', header[16:20])[0]
    audio_format = struct.unpack('<H', header[20:22])[0]  # 2-byte unsigned short
    num_channels = struct.unpack('<H', header[22:24])[0]

    sample_rate = struct.unpack('<I', header[24:28])[0]
    byte_rate = struct.unpack('<I', header[28:32])[0]
    block_align = struct.unpack('<H', header[32:34])[0]
    bits_per_sample = struct.unpack('<H', header[34:36])[0]

    data_marker = header[36:40].decode('ascii')
    data_size = struct.unpack('<I', header[40:44])[0]

    # Print results
    print("RIFF Header:        ", riff)
    print("File Size:          ", file_size)
    print("WAVE Header:        ", wave)
    print("Format Marker:      ", fmt)
    print("Format Chunk Size:  ", fmt_chunk_size)
    print("Audio Format:       ", audio_format, "(1 = PCM)")
    print("Number of Channels: ", num_channels)
    print("Sample Rate:        ", sample_rate)
    print("Byte Rate:          ", byte_rate)
    print("Block Align:        ", block_align)
    print("Bits Per Sample:    ", bits_per_sample)
    print("Data Marker:        ", data_marker)
    print("Data Size:          ", data_size)

# Test the function with the given file path
file_path = 'tgt/music/Africa.wav'
print(f"{file_path}:")
read_wav_header(file_path)
print("\r\n")

file_path = 'tgt/music/Africa_48000.wav'
print(f"{file_path}:")
read_wav_header(file_path)
print("\r\n")
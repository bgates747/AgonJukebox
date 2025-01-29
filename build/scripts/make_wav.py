import os
import shutil
import subprocess
import re
import json

def compress_dynamic_range(input_path, output_path, codec):
    """
    Applies dynamic range compression to the audio file.
    """
    print("Compressing dynamic range...")
    subprocess.run([
        'ffmpeg',
        '-hide_banner',
        '-loglevel', 'error',
        '-y',                                  # Overwrite output file
        '-i', input_path,                      # Input file
        '-ac', '1',                            # Ensure mono output
        '-af', 'acompressor=threshold=-20dB:ratio=3:attack=5:release=50:makeup=2.5',
        '-acodec', codec,                      # Preserve original codec
        output_path                            # Output file
    ], check=True)

def normalize_audio(input_path, output_path, codec):
    """
    Normalizes the audio file to a consistent loudness level.
    """
    print("Normalizing audio...")
    subprocess.run([
        'ffmpeg',
        '-hide_banner',
        '-loglevel', 'error',
        '-y',                                   # Overwrite output file
        '-i', input_path,                       # Input file
        '-ac', '1',                             # Ensure mono output
        '-af', 'loudnorm=I=-20:TP=-2:LRA=11',   # Normalize settings
        '-acodec', codec,                       # Preserve original codec
        output_path                             # Output file
    ], check=True)

def get_audio_metadata(file_path):
    """
    Extracts metadata including sample rate and codec of the audio file using `ffprobe`.
    """
    result = subprocess.run([
        'ffprobe',
        '-hide_banner',
        '-loglevel', 'error',
        '-v', 'error',
        '-select_streams', 'a:0',
        '-show_entries', 'stream=sample_rate,sample_fmt',
        '-of', 'json',
        file_path
    ],
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        text=True,
        check=True
    )
    metadata = json.loads(result.stdout)
    sample_rate = int(metadata['streams'][0]['sample_rate'])
    sample_fmt = metadata['streams'][0]['sample_fmt']
    codec_map = {
        'u8': 'pcm_u8',
        's16': 'pcm_s16le',
        's24': 'pcm_s24le',
        's32': 'pcm_s32le',
        'flt': 'pcm_f32le'
    }
    codec = codec_map.get(sample_fmt, 'pcm_s16le')  # Default to 16-bit PCM if unknown
    print(f"Sample rate: {sample_rate} Hz, Format: {sample_fmt}, Codec: {codec}")
    return sample_rate, codec

def convert_to_wav(input_path, output_path, codec):
    """
    Converts a file to `.wav` format while preserving the closest codec.
    """
    print(f"Converting {input_path} to WAV format...")
    subprocess.run([
        'ffmpeg',
        '-hide_banner',
        '-loglevel', 'error',
        '-y',
        '-i', input_path,
        '-ac', '1',                # Ensure mono output
        '-acodec', codec,          # Use the codec derived from the original format
        output_path
    ], check=True)

def resample_wav(input_path, output_path, sample_rate, codec):
    """
    Resamples the audio file to the specified sample rate.
    """
    print("Resampling audio...")
    subprocess.run([
        'ffmpeg',
        '-hide_banner',
        '-loglevel', 'error',
        '-y',
        '-i', input_path,
        '-ac', '1',
        '-ar', str(sample_rate),
        '-acodec', codec,          # Preserve original codec
        output_path
    ], check=True)

def convert_to_unsigned_pcm_wav(src_path, tgt_path, sample_rate):
    """
    Converts an audio file directly to 8-bit unsigned PCM `.wav` file.
    """
    print("Converting to 8-bit unsigned PCM WAV...")
    subprocess.run([
        'ffmpeg',
        '-hide_banner',
        '-loglevel', 'error',
        '-y',
        '-i', src_path,
        '-ac', '1',
        '-ar', str(sample_rate),
        '-acodec', 'pcm_u8',       # Convert to unsigned 8-bit PCM
        tgt_path
    ], check=True)

def fix_wav_header_if_extensible(file_path):
    """
    Reads a .wav file, checks if the fmt chunk is in WAVEFORMATEXTENSIBLE form,
    and if so, rewrites it to a standard PCM (AudioFormat=1) with a fmt chunk
    size of 16 bytes, removing the extra extension bytes.

    NOTE:
      - This assumes 'fmt ' is the first chunk after the WAVE header.
      - It also assumes standard ordering and no unusual chunks
        preceding 'fmt '.
    """

    with open(file_path, 'rb') as f:
        data = f.read()

    # Minimum size for a valid WAV with standard PCM header is 44 bytes.
    if len(data) < 44:
        print("Not a valid or too-short WAV file:", file_path)
        return

    # Check the RIFF and WAVE headers:
    #   - "RIFF" at offset 0
    #   - overall file size at offset 4
    #   - "WAVE" at offset 8
    if data[0:4] != b'RIFF' or data[8:12] != b'WAVE':
        print("Not a standard RIFF/WAVE file:", file_path)
        return

    # The first chunk after "WAVE" normally starts at offset 12.
    # We expect "fmt " at data[12:16], the chunk size at data[16:20].
    if data[12:16] != b'fmt ':
        print("Did not find 'fmt ' chunk where expected:", file_path)
        return

    fmt_chunk_size = int.from_bytes(data[16:20], byteorder='little')

    # If fmt_chunk_size == 16, it's already standard PCM — do nothing.
    if fmt_chunk_size == 16:
        return

    # For an extensible WAV, typically fmt_chunk_size is 40 (sometimes 18 or other).
    # We'll forcibly convert to standard PCM (chunk_size=16, wFormatTag=1).
    # The "extended" part begins right after the first 16 bytes of the fmt structure.

    # Start of the 'fmt ' data is at offset 20.
    # The standard 16-byte WAVEFORMATEX portion covers offsets 20..35 (inclusive).
    # Then the extension is from offset (20+16) up to (20 + fmt_chunk_size).

    extension_start = 20 + 16
    extension_end = 20 + fmt_chunk_size

    # Make a mutable copy of the entire file content.
    new_data = bytearray(data)

    # 1) Force AudioFormat to 1 (PCM) in bytes 20..21:
    new_data[20:22] = (1).to_bytes(2, byteorder='little')

    # 2) Remove the extra extension bytes from the file.
    #    That means everything in new_data[extension_start:extension_end] goes away.
    del new_data[extension_start:extension_end]

    # 3) Set the fmt chunk size to 16 in offset 16..19:
    new_data[16:20] = (16).to_bytes(4, byteorder='little')

    # 4) Update the overall RIFF chunk size at offset 4..7:
    #    new RIFF size = total length of the file (minus 8 bytes).
    new_riff_size = len(new_data) - 8
    new_data[4:8] = new_riff_size.to_bytes(4, byteorder='little')

    # Write the modified file back.
    with open(file_path, 'wb') as f:
        f.write(new_data)

    print("Converted WAVEFORMATEXTENSIBLE to standard PCM for:", file_path)


def make_sfx(src_dir, tgt_dir, sample_rate, do_compression, do_normalization):
    """
    Processes audio files from the source directory and converts them into
    8-bit unsigned PCM `.wav` files in the target directory with intermediate steps.
    """
    os.makedirs(tgt_dir, exist_ok=True)

    for filename in sorted(os.listdir(src_dir)):
        if filename.lower().endswith(('.wav', '.mp3', '.flac')):
            filename_base = re.sub(r'[^a-zA-Z0-9]', '_', os.path.splitext(filename)[0])
            src_path = os.path.join(src_dir, filename)
            tgt_path = os.path.join(tgt_dir, filename_base + '.wav')
            temp_path = os.path.join(tgt_dir, "temp.wav")

            print(f"\nProcessing: {filename}")
            if os.path.exists(temp_path):
                os.remove(temp_path)

            # Get metadata for sample rate and codec
            source_rate, codec = get_audio_metadata(src_path)

            # If sample_rate is -1, use the source file's sample rate
            if sample_rate == -1:
                target_rate = source_rate
            else:
                target_rate = sample_rate

            # Convert to `.wav` if not already in `.wav` format
            if not filename.lower().endswith('.wav'):
                convert_to_wav(src_path, temp_path, codec)
                shutil.copy(temp_path, tgt_path)
                os.remove(temp_path)
            else:
                shutil.copy(src_path, tgt_path)

            # Apply dynamic range compression (optional)
            if do_compression:
                shutil.copy(tgt_path, temp_path)
                compress_dynamic_range(temp_path, tgt_path, codec)
                os.remove(temp_path)

            # Apply loudness normalization (optional)
            if do_normalization:
                shutil.copy(tgt_path, temp_path)
                normalize_audio(temp_path, tgt_path, codec)
                os.remove(temp_path)

            # Resample the audio (if needed)
            if source_rate != target_rate:
                shutil.copy(tgt_path, temp_path)
                resample_wav(temp_path, tgt_path, target_rate, codec)
                os.remove(temp_path)
            else:
                print("Skipping resampling: Source and target sample rates are the same.")

            # Convert to 8-bit unsigned PCM
            shutil.copy(tgt_path, temp_path)
            convert_to_unsigned_pcm_wav(temp_path, tgt_path, target_rate)
            os.remove(temp_path)

            # Fix the WAV header if it's in WAVEFORMATEXTENSIBLE format
            fix_wav_header_if_extensible(tgt_path)

            print(f"Finished processing: {tgt_path}")

if __name__ == '__main__':
## Note: because the player streams audio data to VDP 60 times per second,
## optimal sample rate will be even multiples of 60.
    # sample_rate = 48000 # Typical YouTube audio quality
    # sample_rate = 44100 # Typical CD quality
    # sample_rate = 16384 # 'native' rate
    # sample_rate = 15360 # (256*60)
    # sample_rate = -1 # Use the source file's sample rate
    sample_rate = 6000
    src_dir = 'assets/sound/music/staging'
    tgt_dir = 'tgt/music'

    do_compression = True
    do_normalization = True

    # Generate sound effects with intermediate steps directly in the target directory
    make_sfx(src_dir, tgt_dir, sample_rate, do_compression, do_normalization)
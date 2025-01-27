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

            print(f"Finished processing: {tgt_path}")

if __name__ == '__main__':
## Note: because the player streams audio data to VDP 60 times per second,
## optimal sample rate will be even multiples of 60.
    # sample_rate = 48000 # Typical YouTube audio quality
    # sample_rate = 44100 # Typical CD quality
    # sample_rate = 16384 # 'native' rate
    # sample_rate = 15360 # (256*60)
    sample_rate = -1 # Use the source file's sample rate
    src_dir = 'assets/sound/music/staging'
    tgt_dir = 'tgt/music'

    do_compression = True
    do_normalization = True

    # Generate sound effects with intermediate steps directly in the target directory
    make_sfx(src_dir, tgt_dir, sample_rate, do_compression, do_normalization)
import os
import shutil
import subprocess
import re
import json

def compress_dynamic_range(input_path, output_path):
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
        output_path                            # Output file
    ], check=True)

def normalize_audio(input_path, output_path):
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
        output_path                             # Output file
    ], check=True)

def get_sample_rate(file_path):
    """
    Extracts and returns the sample rate of the audio file from `ffprobe` metadata.
    """
    result = subprocess.run([
            'ffprobe',
            '-hide_banner',
            '-loglevel', 'error',
            '-v', 'error',                     # Suppress non-error messages
            '-select_streams', 'a:0',          # Focus on the first audio stream
            '-show_entries', 'stream=sample_rate', 
            '-of', 'json',                     # Output in JSON format
            file_path
        ],
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        text=True,
        check=True
    )
    metadata = json.loads(result.stdout)
    sample_rate = metadata['streams'][0]['sample_rate']
    print(f"Sample rate: {sample_rate} Hz")
    return int(sample_rate)

def convert_to_unsigned_pcm_wav(src_path, tgt_path, sample_rate):
    """
    Converts an audio file directly to an 8-bit unsigned PCM `.wav` file.
    Ensures the sample rate and mono output are explicitly set.
    """
    print("Converting to 8-bit unsigned PCM WAV...")
    subprocess.run([
        'ffmpeg',
        '-hide_banner',
        '-loglevel', 'error',
        '-y',                      # Overwrite output file if it exists
        '-i', src_path,            # Input file
        '-ac', '1',                # Ensure mono output
        '-ar', str(sample_rate),   # Explicitly set the sample rate
        '-acodec', 'pcm_u8',       # Audio codec: unsigned 8-bit PCM
        tgt_path                   # Output file (8-bit unsigned PCM `.wav`)
    ], check=True)

def resample_wav(input_path, output_path, sample_rate):
    """
    Resamples the audio file to the specified sample rate.
    """
    print("Resampling audio...")
    subprocess.run([
        'ffmpeg',
        '-hide_banner',
        '-loglevel', 'error',
        '-y',                      # Overwrite output file
        '-i', input_path,          # Input file
        '-ac', '1',                # Ensure mono output
        '-ar', str(sample_rate),   # Set sample rate
        output_path                # Output file
    ], check=True)

def make_sfx(src_dir, tgt_dir, sample_rate):
    """
    Processes audio files from the source directory and converts them into
    8-bit unsigned PCM `.wav` files in the target directory with intermediate steps.
    """
    # Ensure the target directory exists
    os.makedirs(tgt_dir, exist_ok=True)

    # For each source file, apply all transformations
    for filename in sorted(os.listdir(src_dir)):
        if filename.lower().endswith(('.wav', '.mp3', '.flac')):
            filename_base = os.path.splitext(filename)[0]
            filename_base = filename_base.replace('_', ' ')  # Replace underscores with spaces
            filename_base = re.sub(r'[^a-zA-Z0-9\s]', '', filename_base)  # Remove non-alphanumeric
            filename_base = filename_base.replace(' ', '_') # Replace spaces with underscores
            tgt_path = os.path.join(tgt_dir, filename_base + '.wav')
            src_path = os.path.join(src_dir, filename)
            temp_path = os.path.join(tgt_dir, "temp.wav")

            print(f"\nProcessing: {filename}")
            if os.path.exists(temp_path):
                os.remove(temp_path)

            if sample_rate == -1:
                current_sample_rate = get_sample_rate(src_path)
            else:
                current_sample_rate = sample_rate

            shutil.copy(src_path, temp_path)
            compress_dynamic_range(temp_path, tgt_path)
            os.remove(temp_path)

            if os.path.exists(temp_path):
                os.remove(temp_path)
            shutil.copy(tgt_path, temp_path)
            normalize_audio(temp_path, tgt_path)
            os.remove(temp_path)

            if os.path.exists(temp_path):
                os.remove(temp_path)
            shutil.copy(tgt_path, temp_path)
            resample_wav(temp_path, tgt_path, current_sample_rate)
            os.remove(temp_path)

            if os.path.exists(temp_path):
                os.remove(temp_path)
            shutil.copy(tgt_path, temp_path)
            convert_to_unsigned_pcm_wav(temp_path, tgt_path, current_sample_rate)
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
    tgt_dir = 'tgt/music/Classical'

    # Generate sound effects with intermediate steps directly in the target directory
    make_sfx(src_dir, tgt_dir, sample_rate)
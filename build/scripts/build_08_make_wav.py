import os
import shutil
import subprocess
import re
from tempfile import NamedTemporaryFile
import tarfile

def copy_to_temp(file_path):
    """
    Copy a file to a temporary file.
    """
    temp_file = NamedTemporaryFile(delete=False, suffix=os.path.splitext(file_path)[1])
    shutil.copy(file_path, temp_file.name)
    return temp_file.name

def convert_to_unsigned_pcm_wav(src_path, tgt_path, sample_rate):
    """
    Converts an audio file directly to an 8-bit unsigned PCM `.wav` file.
    Ensures the sample rate and mono output are explicitly set.
    """
    subprocess.run([
        'ffmpeg',
        '-y',                      # Overwrite output file if it exists
        '-i', src_path,            # Input file
        '-ac', '1',                # Ensure mono output
        '-ar', str(sample_rate),   # Explicitly set the sample rate
        '-acodec', 'pcm_u8',       # Audio codec: unsigned 8-bit PCM
        tgt_path                   # Output file (8-bit unsigned PCM `.wav`)
    ], check=True)

def compress_dynamic_range(input_path, output_path):
    """
    Applies dynamic range compression to the audio file.
    """
    subprocess.run([
        'ffmpeg',
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
    subprocess.run([
        'ffmpeg',
        '-y',                                  # Overwrite output file
        '-i', input_path,                      # Input file
        '-ac', '1',                            # Ensure mono output
        '-af', 'loudnorm=I=-20:TP=-2:LRA=11',  # Normalize settings
        output_path                            # Output file
    ], check=True)

def resample_wav(input_path, output_path, sample_rate):
    """
    Resamples the audio file to the specified sample rate.
    """
    subprocess.run([
        'ffmpeg',
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
    for filename in sorted(os.listdir(src_dir)):
        if filename.endswith(('.wav', '.mp3')):
            # Process filenames
            filename_base = os.path.splitext(filename)[0]
            filename_base = re.sub(r'[^a-zA-Z0-9\s]', '', filename_base)  # Remove non-alphanumeric characters
            filename_base = filename_base.title().replace(' ', '_')       # Proper Case and replace spaces with underscores
            tgt_path = os.path.join(tgt_dir, filename_base + '.wav')

            src_path = os.path.join(src_dir, filename)

            # Compress dynamic range
            temp_path = copy_to_temp(src_path)
            compress_dynamic_range(temp_path, tgt_path)
            os.remove(temp_path)

            # Normalize audio
            temp_path = copy_to_temp(tgt_path)
            normalize_audio(temp_path, tgt_path)
            os.remove(temp_path)

            # Resample .wav file to the specified frame rate
            temp_path = copy_to_temp(tgt_path)
            resample_wav(temp_path, tgt_path, sample_rate)
            os.remove(temp_path)

            # Convert to unsigned 8-bit PCM `.wav`
            temp_path = copy_to_temp(tgt_path)
            convert_to_unsigned_pcm_wav(temp_path, tgt_path, sample_rate)
            os.remove(temp_path)

def create_tar_gz(src_dir, output_dir, sample_rate):
    """
    Creates a compressed tar.gz archive of the processed files.
    """
    archive_name = os.path.join(output_dir, f"jukebox{sample_rate}.tar.gz")

    # Remove existing archive if it exists
    if os.path.exists(archive_name):
        os.remove(archive_name)

    # Create the tar.gz archive
    with tarfile.open(archive_name, "w:gz") as tar:
        tar.add(src_dir, arcname=os.path.basename(src_dir))

    print(f"Archive created: {archive_name}")

if __name__ == '__main__':
    sample_rate = 32768
    sample_rate = 44100
    sample_rate = 16384
    src_dir = 'assets/sound/music/staging'
    tgt_dir = 'tgt/music'

    # Generate sound effects with intermediate steps directly in the target directory
    make_sfx(src_dir, tgt_dir, sample_rate)

    # # Optionally create a compressed archive of the processed files
    # output_dir = 'tgt'
    # create_tar_gz(tgt_dir, output_dir, sample_rate)

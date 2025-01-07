import os
import shutil
import subprocess
from tempfile import NamedTemporaryFile
import math
import re

def make_tbl_08_sfx(conn, cursor):
    """Create the database table for sound effects."""
    cursor.execute("DROP TABLE IF EXISTS tbl_08_sfx;")
    conn.commit()
    cursor.execute("""
        CREATE TABLE IF NOT EXISTS tbl_08_sfx (
            sfx_id INTEGER,
            size INTEGER,
            duration INTEGER,
            filename TEXT,
            PRIMARY KEY (sfx_id)
        );
    """)
    conn.commit()

def copy_to_temp(file_path):
    """Copy a file to a temporary file."""
    temp_file = NamedTemporaryFile(delete=False, suffix=os.path.splitext(file_path)[1])
    shutil.copy(file_path, temp_file.name)
    return temp_file.name

def extract_audio_metadata(file_path):
    """
    Extract metadata from the audio file using FFmpeg.
    Determines the actual format, channels, sample rate, and duration.
    """
    import json
    result = subprocess.run(
        [
            'ffprobe', '-v', 'error', '-show_entries',
            'format=format_name,format_long_name',  # Include format info
            '-show_entries', 'stream=channels,sample_rate,duration',
            '-of', 'json', file_path
        ],
        capture_output=True,
        text=True
    )
    metadata = json.loads(result.stdout)
    format_data = metadata.get('format', {})
    stream = metadata.get('streams', [{}])[0]
    return {
        'format_name': format_data.get('format_name', 'unknown'),  # Short format name (e.g., "wav", "mp3")
        'format_long_name': format_data.get('format_long_name', 'Unknown format'),  # Detailed format name
        'channels': int(stream.get('channels', 0)),
        'sample_rate': int(stream.get('sample_rate', 0)),
        'duration': float(stream.get('duration', 0))
    }

def convert_to_wav(src_path, tgt_path):
    """
    Converts the source audio file to `.wav` format if it isn't already.
    """
    subprocess.run([
        'ffmpeg', '-y',                # Overwrite output file
        '-i', src_path,                # Input file
        '-ac', '1',                    # Ensure mono output
        tgt_path                       # Output .wav file
    ], check=True)

def resample_wav(src_path, tgt_path, sample_rate):
    """
    Resamples the `.wav` file to the specified frame rate.
    """
    subprocess.run([
        'ffmpeg', '-y',                # Overwrite output file
        '-i', src_path,                # Input file
        '-ac', '1',                    # Ensure mono output
        '-ar', str(sample_rate),       # Set new frame rate
        tgt_path                       # Output file
    ], check=True)

def lowpass_filter(input_path, output_path, sample_rate):
    # compute cutoff frequency as a fraction of the Nyquist frequency
    cutoff = 0.5 * sample_rate / 2
    subprocess.run([
        'ffmpeg', '-y', '-i', input_path,
        '-ac', '1',                    # Ensure mono output
        '-af', f"lowpass=f={cutoff}", output_path
    ], check=True)

def compress_dynamic_range(input_path, output_path):
        subprocess.run([
            'ffmpeg',
            '-y',                                  # Overwrite output file
            '-i', input_path,                      # Input file
            '-ac', '1',                    # Ensure mono output
            '-af', 'acompressor=threshold=-20dB:ratio=3:attack=5:release=50:makeup=2.5',  # Compression settings
            output_path                              # Output file
        ], check=True)

def normalize_audio(input_path, output_path):
        subprocess.run([
            'ffmpeg',
            '-y',                                  # Overwrite output file
            '-i', input_path,                      # Input file
            '-ac', '1',                    # Ensure mono output
            # '-af', 'loudnorm=I=-24:TP=-2:LRA=11', # Normalize loudness (default)
            # '-af', 'loudnorm=I=-18:TP=-1:LRA=11',  # Adjusted normalization (louder)
            '-af', 'loudnorm=I=-20:TP=-2:LRA=11', # Normalize loudness (splitting the middle)
            output_path                              # Output file
        ], check=True)

def noise_gate(input_path, output_path):
    # Hardcoded parameters in dB
    # chat-gpt's suggestions
    threshold_db = -25
    range_db = -24
    # rather too aggressive but does stomp on a lot of static in silent parts after percussion-dominated sections
    # threshold_db = -20
    # range_db = -30

    # Compute normalized values for FFmpeg
    threshold_norm = math.pow(10, threshold_db / 20)  # Convert dB to linear scale
    range_norm = math.pow(10, range_db / 20)         # Convert dB to linear scale

    # Generate FFmpeg command
    subprocess.run([
        'ffmpeg',
        '-y',                                  # Overwrite output file
        '-i', input_path,                      # Input file
        '-ac', '1',                    # Ensure mono output
        '-af', (
            f'agate=threshold={threshold_norm}:'
            f'range={range_norm}:'
            'attack=10:'                       # Attack time in ms
            'release=100'                      # Release time in ms
        ),
        output_path                            # Output file
    ], check=True)

def convert_to_unsigned_pcm_with_dither(src_path, tgt_path, sample_rate):
    """
    Converts an audio file to 8-bit unsigned PCM using FFmpeg with dithering enabled.
    """
    subprocess.run([
        'ffmpeg', '-y',                # Overwrite output file
        '-i', src_path,                # Input file
        '-ac', '1',                    # Ensure mono output
        '-ar', str(sample_rate),       # Set the sample rate
        '-acodec', 'pcm_u8',           # Convert to unsigned 8-bit PCM
        '-dither_scale', '1',          # Enable dithering
        tgt_path                       # Output file
    ], check=True)

def convert_to_unsigned_pcm(src_path, tgt_path, sample_rate):
    """
    Converts a `.wav` file to 8-bit unsigned PCM with the specified sample rate.
    """
    subprocess.run([
        'ffmpeg', '-y',                # Overwrite output file
        '-i', src_path,                # Input file
        '-ac', '1',                    # Ensure mono output
        '-ar', str(sample_rate),       # Set the sample rate
        '-acodec', 'pcm_u8',           # Convert to unsigned 8-bit PCM
        tgt_path                       # Output file
    ], check=True)

def convert_to_unsigned_raw(src_path, tgt_path, sample_rate):
    """
    Converts an audio file directly to unsigned 8-bit PCM `.raw` format.
    Ensures the sample rate and mono output are explicitly set.
    """
    subprocess.run([
        'ffmpeg',
        '-y',                       # Overwrite output file if it exists
        '-i', src_path,             # Input file
        '-ac', '1',                 # Ensure mono output
        '-ar', str(sample_rate),    # Explicitly set the sample rate
        '-f', 'u8',                 # Output format: unsigned 8-bit PCM
        '-acodec', 'pcm_u8',        # Audio codec: unsigned 8-bit PCM
        tgt_path                    # Output file (raw binary)
    ], check=True)


def convert_to_signed_raw(src_path, tgt_path, sample_rate):
    """
    Converts an unsigned 8-bit PCM `.wav` file to signed 8-bit PCM `.raw` using FFmpeg.
    Ensures the sample rate remains unchanged.
    """
    subprocess.run([
        'ffmpeg',
        '-y',                       # Overwrite output file if it exists
        '-i', src_path,           # Input file (unsigned 8-bit PCM `.wav`)
        '-ac', '1',                 # Ensure mono output
        '-ar', str(sample_rate),    # Explicitly set the sample rate
        '-f', 's8',                 # Output format: signed 8-bit PCM
        '-acodec', 'pcm_s8',        # Audio codec: signed 8-bit PCM
        tgt_path                 # Output file (raw binary)
    ], check=True)

def make_sfx_wav(src_dir, proc_dir, sample_rate):
    """
    Processes all audio files in the source directory and combines them into a single `.wav` file.
    """
    if os.path.exists(proc_dir):
        shutil.rmtree(proc_dir)
    os.makedirs(proc_dir)

    # Prepare list of files to process
    sfxs = []
    for filename in sorted(os.listdir(src_dir)):
        if filename.endswith(('.wav', '.mp3')):
            # Process filenames
            filename_base = os.path.splitext(filename)[0]
            filename_base = re.sub(r'[^a-zA-Z0-9\s]', '', filename_base)  # Remove non-alphanumeric characters
            filename_base = filename_base.title().replace(' ', '_')       # Proper Case and replace spaces with underscores
            filename_wav = filename_base + '.wav'
            sfxs.append((filename, filename_wav))

    for original_filename, wav_filename in sfxs:
        src_path = os.path.join(src_dir, original_filename)
        proc_path = os.path.join(proc_dir, wav_filename)

        # Convert source file to .wav without modifying frame rate or codec
        convert_to_wav(src_path, proc_path)

        # Compress dynamic range
        temp_path = copy_to_temp(proc_path)
        compress_dynamic_range(temp_path, proc_path)
        os.remove(temp_path)

        # Normalize audio
        temp_path = copy_to_temp(proc_path)
        normalize_audio(temp_path, proc_path)
        os.remove(temp_path)

        # Resample .wav file to the specified frame rate
        temp_path = copy_to_temp(proc_path)
        resample_wav(temp_path, proc_path, sample_rate)
        os.remove(temp_path)

def rename_files_to_sequence(directory, extension="wav"):
    """
    Renames all files in the given directory to a sequential numeric format (e.g., 01.wav, 02.wav).
    
    Args:
        directory (str): The directory containing the files to rename.
        extension (str): The extension of files to rename (default is "wav").
    """
    # Get all files in the directory with the specified extension
    files = sorted(f for f in os.listdir(directory) if f.endswith(f".{extension}"))
    
    # Rename files to sequential names
    for i, filename in enumerate(files, start=1):
        old_path = os.path.join(directory, filename)
        new_filename = f"{i:02d}.{extension}"
        new_path = os.path.join(directory, new_filename)
        os.rename(old_path, new_path)
        print(f"Renamed {old_path} to {new_path}")

def concatenate_to_raw(proc_dir, tgt_filepath):
    """
    Concatenate all `.wav` files in the `proc_dir` into a single `.raw` file.

    Args:
        proc_dir (str): Directory containing processed `.wav` files.
        tgt_filepath (str): Path to save the final `.raw` file.
    """
    # Ensure the target directory exists
    tgt_dir = os.path.dirname(tgt_filepath)
    os.makedirs(tgt_dir, exist_ok=True)

    # Temporary concatenation `.wav` file
    concat_temp_wav = os.path.join(tgt_dir, "temp_concat.wav")

    # Generate file list for FFmpeg
    file_list_path = os.path.join(proc_dir, "file_list.txt")
    with open(file_list_path, "w") as file_list:
        for filename in sorted(os.listdir(proc_dir)):
            if filename.endswith(".wav"):
                filepath = os.path.abspath(os.path.join(proc_dir, filename))
                file_list.write(f"file '{filepath}'\n")  # Use absolute paths to avoid duplication issues

    # Use FFmpeg to concatenate `.wav` files
    try:
        subprocess.run([
            "ffmpeg", "-y", "-f", "concat", "-safe", "0",
            "-i", file_list_path, "-c", "copy", concat_temp_wav
        ], check=True)

        # Convert concatenated `.wav` to 8-bit unsigned PCM `.raw`
        subprocess.run([
            "ffmpeg", "-y", "-i", concat_temp_wav, "-f", "u8", tgt_filepath
        ], check=True)

    finally:
        # Clean up temporary files
        if os.path.exists(concat_temp_wav):
            os.remove(concat_temp_wav)
        if os.path.exists(file_list_path):
            os.remove(file_list_path)


if __name__ == '__main__':
    sample_rate = 32768 
    src_dir = 'assets/sound/music/elton'
    proc_dir = 'assets/sound/music/processed'
    tgt_filepath = 'assets/sound/music/staging/Goodbye Yellow Brick Road.wav'
    # make_sfx_wav(src_dir, proc_dir, sample_rate)
    # rename_files_to_sequence(proc_dir)
    concatenate_to_raw(proc_dir, tgt_filepath)
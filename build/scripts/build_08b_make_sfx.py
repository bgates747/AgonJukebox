from build_98_asm_sfx import make_asm_sfx, assemble_jukebox

import os
import sqlite3
import shutil
import subprocess
from tempfile import NamedTemporaryFile
import math
import tarfile
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



def make_sfx(db_path, src_dir, proc_dir, tgt_dir, sample_rate):
    """
    Workflow:
    1. Convert source file to unsigned 8-bit PCM `.wav`.
    2. Process `.wav` files iteratively.
    3. Convert the final `.wav` to signed 8-bit PCM `.raw`.
    """
    conn = sqlite3.connect(db_path)
    cursor = conn.cursor()

    make_tbl_08_sfx(conn, cursor)

    # Create processing and target directories
    for directory in (proc_dir, tgt_dir):
        if os.path.exists(directory):
            shutil.rmtree(directory)
        os.makedirs(directory)

    sfxs = []
    for filename in sorted(os.listdir(src_dir)):
        if filename.endswith(('.wav', '.mp3')):
            # Process filenames
            filename_base = os.path.splitext(filename)[0]
            filename_base = re.sub(r'[^a-zA-Z0-9\s]', '', filename_base)  # Remove non-alphanumeric characters
            filename_base = filename_base.title().replace(' ', '_')       # Proper Case and replace spaces with underscores
            filename_wav = filename_base + '.wav'
            filename_raw = filename_base + '.raw'
            sfxs.append((len(sfxs), filename, filename_wav, filename_raw))

    for sfx in sfxs:
        sfx_id, original_filename, wav_filename, raw_filename = sfx
        src_path = os.path.join(src_dir, original_filename)
        proc_path = os.path.join(proc_dir, wav_filename)
        tgt_path = os.path.join(tgt_dir, raw_filename)

        # Extract metadata (optional debugging/logging)
        metadata = extract_audio_metadata(src_path)

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

        # # Apply lowpass filter
        # temp_path = copy_to_temp(proc_path)
        # lowpass_filter(temp_path, proc_path, sample_rate)
        # os.remove(temp_path)

        # Resample .wav file to the specified frame rate
        temp_path = copy_to_temp(proc_path)
        resample_wav(temp_path, proc_path, sample_rate)
        os.remove(temp_path)

        # # Apply noise gate
        # temp_path = copy_to_temp(proc_path)
        # noise_gate(temp_path, proc_path)
        # os.remove(temp_path)

        # FINAL STEP: Convert .wav file to signed 8-bit PCM .raw
        convert_to_signed_raw(proc_path, tgt_path, sample_rate)

        # Calculate size and duration
        size = os.path.getsize(tgt_path)
        duration = int(metadata['duration'] * 1000)  # Convert to ms and ensure it's an integer
        cursor.execute("""
            INSERT INTO tbl_08_sfx (sfx_id, size, duration, filename)
            VALUES (?, ?, ?, ?);
        """, (sfx_id, size, duration, raw_filename))

    conn.commit()
    conn.close()

    # Delete the processing directory
    shutil.rmtree(proc_dir)

def create_tar_gz(src_dir, output_dir, sample_rate):
    # Create the archive name with the sample rate
    archive_name = os.path.join(output_dir, f"jukebox{sample_rate}.tar.gz")

    # Remove existing archive if it exists
    if os.path.exists(archive_name):
        os.remove(archive_name)

    # Create the tar.gz archive
    with tarfile.open(archive_name, "w:gz") as tar:
        tar.add(src_dir, arcname=os.path.basename(src_dir))

    print(f"Archive created: {archive_name}")

if __name__ == '__main__':
    # sample_rate = 44100 # standard high quality audio
    # sample_rate = 44100 // 2 # powers of two are good
    # sample_rate = 16384 # default rate for Agon
    sample_rate = 32768 # a nice power of two of bytes/sec if she'll take it
    # sample_rate = 16000 # A standard Audacity option
    # sample_rate = 15360 # for 8-bit PCM this is 256 bytes per 1/60th of a second
    # sample_rate = 15360*2 # for 8-bit PCM this is 512 bytes per 1/60th of a second
    db_path = 'build/data/build.db'
    src_dir = 'assets/sound/music/staging'
    proc_dir = 'assets/sound/music/processed'
    tgt_dir = 'tgt/music'
    make_sfx(db_path, src_dir, proc_dir, tgt_dir, sample_rate)

    asm_tgt_dir = 'music'
    sfx_inc_path = f"src/asm/music.inc"
    next_buffer_id = 0x3000
    make_asm_sfx(db_path, sfx_inc_path, asm_tgt_dir, next_buffer_id, sample_rate)
    assemble_jukebox()

    tar_src_dir = "tgt"  # Source directory to compress
    tar_output_dir = "."  # Directory to save the archive

    create_tar_gz(tar_src_dir, tar_output_dir, sample_rate)
import os
import sqlite3
import shutil
import subprocess
from tempfile import NamedTemporaryFile
from build_98_asm_sfx import make_asm_sfx, assemble_jukebox
import numpy as np
from scipy.io import wavfile
import math
from scipy.signal import savgol_filter
import wave

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
        '-ar', str(sample_rate),       # Set new frame rate
        tgt_path                       # Output file
    ], check=True)

def convert_to_unsigned_pcm(src_path, tgt_path):
    """
    Converts a `.wav` file to 8-bit unsigned PCM.
    """
    subprocess.run([
        'ffmpeg', '-y',                # Overwrite output file
        '-i', src_path,                # Input file
        '-acodec', 'pcm_u8',           # Convert to unsigned 8-bit PCM
        tgt_path                       # Output file
    ], check=True)

def convert_to_unsigned_pcm_with_smoothing(input_path, output_path):
    window_length = 31  # Window length for Savitzky-Golay filter
    polyorder = 2       # Polynomial order for Savitzky-Golay filter
    
    # Read input WAV file
    sample_rate, data = wavfile.read(input_path)
    
    # Normalize the data to -1.0 to 1.0 range
    data = data / np.max(np.abs(data))
    
    # Apply Savitzky-Golay filter for smoothing
    smoothed_data = savgol_filter(data, window_length, polyorder)
    
    # Scale to 8-bit unsigned PCM range (0-255)
    data_8bit = np.round((smoothed_data + 1.0) * 127.5).astype(np.uint8)
    
    # Write as a valid WAV file
    with wave.open(output_path, 'wb') as wf:
        wf.setnchannels(1)                # Mono
        wf.setsampwidth(1)                # 8-bit unsigned PCM
        wf.setframerate(sample_rate)      # Original sample rate
        wf.writeframes(data_8bit.tobytes())


def lowpass_filter(input_path, output_path, sample_rate):
    # compute cutoff frequency as a fraction of the Nyquist frequency
    cutoff = 0.5 * sample_rate / 2
    subprocess.run([
        'ffmpeg', '-y', '-i', input_path,
        '-af', f"lowpass=f={cutoff}", output_path
    ], check=True)

def convert_to_signed_raw(input_path, output_path):
    """
    Converts an unsigned 8-bit PCM `.wav` file to signed 8-bit PCM `.raw`.
    """
    _, data = wavfile.read(input_path)

    # Convert unsigned 8-bit (0-255) to signed 8-bit (-128 to 127)
    data_signed = (data - 128).astype(np.int8)

    # Save as raw binary
    with open(output_path, 'wb') as f:
        f.write(data_signed.tobytes())

def compress_dynamic_range(input_path, output_path):
        subprocess.run([
            'ffmpeg',
            '-y',                                  # Overwrite output file
            '-i', input_path,                      # Input file
            '-af', 'acompressor=threshold=-20dB:ratio=3:attack=5:release=50:makeup=2.5',  # Compression settings
            output_path                              # Output file
        ], check=True)

def normalize_audio(input_path, output_path):
        subprocess.run([
            'ffmpeg',
            '-y',                                  # Overwrite output file
            '-i', input_path,                      # Input file
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
        '-af', (
            f'agate=threshold={threshold_norm}:'
            f'range={range_norm}:'
            'attack=10:'                       # Attack time in ms
            'release=100'                      # Release time in ms
        ),
        output_path                            # Output file
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
            filename_wav = os.path.splitext(filename)[0] + '.wav'
            filename_raw = os.path.splitext(filename)[0] + '.raw'
            sfxs.append((len(sfxs), filename, filename_wav, filename_raw))

    for sfx in sfxs:
        sfx_id, original_filename, wav_filename, raw_filename = sfx
        src_path = os.path.join(src_dir, original_filename)
        proc_path = os.path.join(proc_dir, wav_filename)
        tgt_path = os.path.join(tgt_dir, raw_filename)

        # Convert source file to .wav without modifying frame rate or codec
        convert_to_wav(src_path, proc_path)

        # # Apply lowpass filter
        # temp_path = copy_to_temp(proc_path)
        # lowpass_filter(temp_path, proc_path, sample_rate)
        # os.remove(temp_path)

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

        # Apply noise gate
        temp_path = copy_to_temp(proc_path)
        noise_gate(temp_path, proc_path)
        os.remove(temp_path)

        # Convert .wav file to unsigned 8-bit PCM
        temp_path = copy_to_temp(proc_path)
        convert_to_unsigned_pcm(temp_path, proc_path)
        # convert_to_unsigned_pcm_with_smoothing(temp_path, proc_path)
        # convert_to_unsigned_pcm_with_dither(temp_path, proc_path)
        os.remove(temp_path)

        # FINAL STEP: Convert .wav file to signed 8-bit PCM .raw
        convert_to_signed_raw(proc_path, tgt_path)

        # Calculate size and duration
        size = os.path.getsize(tgt_path)
        duration = size // (sample_rate / 1000)  # In ms for 8-bit mono PCM
        cursor.execute("""
            INSERT INTO tbl_08_sfx (sfx_id, size, duration, filename)
            VALUES (?, ?, ?, ?);
        """, (sfx_id, size, duration, raw_filename))

    conn.commit()
    conn.close()

def convert_to_unsigned_pcm_with_dither(input_path, output_path):
    """
    Converts an audio file to 8-bit unsigned PCM using FFmpeg with dithering enabled.
    """
    subprocess.run([
        'ffmpeg',
        '-y',                                  # Overwrite output file
        '-i', input_path,                      # Input file
        '-acodec', 'pcm_u8',                   # Convert to 8-bit unsigned PCM
        '-dither_scale', '2',                  # Enable dithering
        output_path                            # Output file
    ], check=True)


if __name__ == '__main__':
    # sample_rate = 44100 # standard high quality audio
    # sample_rate = 16384 # default rate for Agon
    # sample_rate = 16000 # A standard Audacity option
    sample_rate = 15360 # for 8-bit PCM this is 256 bytes per 1/60th of a second
    db_path = 'build/data/build.db'
    src_dir = 'assets/sound/music/trimmed'
    proc_dir = 'assets/sound/music/processed'
    tgt_dir = 'tgt/music'
    make_sfx(db_path, src_dir, proc_dir, tgt_dir, sample_rate)

    asm_tgt_dir = 'music'
    sfx_inc_path = f"src/asm/music.inc"
    next_buffer_id = 0x3000
    make_asm_sfx(db_path, sfx_inc_path, asm_tgt_dir, next_buffer_id, sample_rate)
    assemble_jukebox()
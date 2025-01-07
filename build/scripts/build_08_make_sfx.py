import os
import sqlite3
import shutil
import subprocess
from tempfile import NamedTemporaryFile

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

def make_sfx(db_path, src_dir, tgt_dir, proc_dir, sample_rate):
    conn = sqlite3.connect(db_path)
    cursor = conn.cursor()

    make_tbl_08_sfx(conn, cursor)

    # Create target and processed directories
    for directory in (tgt_dir, proc_dir):
        if os.path.exists(directory):
            shutil.rmtree(directory)
        os.makedirs(directory)

    sfxs = []
    for filename in sorted(os.listdir(src_dir)):
        if filename.endswith(('.wav', '.mp3')):
            filename_raw = os.path.splitext(filename)[0] + '.raw'
            sfxs.append((len(sfxs), filename, filename_raw))

    for sfx in sfxs:
        sfx_id, original_filename, raw_filename = sfx
        src_path = os.path.join(src_dir, original_filename)  # Original source file
        tgt_path = os.path.join(tgt_dir, raw_filename)       # Final .raw target file
        proc_path = os.path.join(proc_dir, os.path.splitext(original_filename)[0] + '.wav')

        # Step 1: Convert to .wav if necessary
        if original_filename.endswith('.mp3'):
            temp_path = copy_to_temp(src_path)
            subprocess.run([
                'ffmpeg',
                '-y',                      # Overwrite output file
                '-i', temp_path,           # Input file
                '-ac', '1',                # Set audio channels to mono
                proc_path                  # Output file
            ], check=True)
            os.remove(temp_path)
        else:
            shutil.copy(src_path, proc_path)

        # Step 2: Apply compression to reduce dynamic range
        temp_path = copy_to_temp(proc_path)
        subprocess.run([
            'ffmpeg',
            '-y',                                  # Overwrite output file
            '-i', temp_path,                      # Input file
            '-ac', '1',                           # Set audio channels to mono
            # '-af', 'acompressor=threshold=-20dB:ratio=3:attack=5:release=50:makeup=5',  # Compression settings
            '-af', 'acompressor=threshold=-20dB:ratio=3:attack=5:release=50',  # Compression settings
            proc_path                              # Output file
        ], check=True)
        os.remove(temp_path)

        # Step 3: Normalize the audio to prevent clipping
        temp_path = copy_to_temp(proc_path)
        subprocess.run([
            'ffmpeg',
            '-y',                                  # Overwrite output file
            '-i', temp_path,                      # Input file
            '-ac', '1',                           # Set audio channels to mono
            '-af', 'loudnorm=I=-24:TP=-2:LRA=11', # Normalize loudness
            proc_path                              # Output file
        ], check=True)
        os.remove(temp_path)

        # Step 4: Resample the audio to 16 kHz
        temp_path = copy_to_temp(proc_path)
        subprocess.run([
            'ffmpeg',
            '-y',                                  # Overwrite output file
            '-i', temp_path,                      # Input file
            '-ac', '1',                           # Set audio channels to mono
            '-ar', f'{sample_rate}',                       # Resample rate in Hz
            proc_path                              # Output file
        ], check=True)
        os.remove(temp_path)

        # Step 5: Convert the audio to signed 8-bit PCM
        subprocess.run([
            'ffmpeg',
            '-y',                                  # Overwrite output file
            '-i', proc_path,                      # Input file
            '-ac', '1',                           # Set audio channels to mono
            '-f', 's8',                           # Format: signed 8-bit PCM
            '-acodec', 'pcm_s8',                  # Codec: PCM signed 8-bit
            tgt_path                              # Final .raw output file
        ], check=True)

        # Calculate size and duration
        size = os.path.getsize(tgt_path)
        duration = size // (sample_rate / 1000)  # in milliseconds for 8-bit mono PCM at sample_rate in Hz
        cursor.execute("""
            INSERT INTO tbl_08_sfx (sfx_id, size, duration, filename)
            VALUES (?, ?, ?, ?);""", (sfx_id, size, duration, raw_filename))

    conn.commit()
    conn.close()

if __name__ == '__main__':
    # sample_rate = 44100 # standard high quality audio
    sample_rate = 16384 # default rate for Agon
    # sample_rate = 15360/4 # for 8-bit PCM this is 256 bytes per 1/60th of a second
    db_path = 'build/data/build.db'
    src_dir = 'assets/sound/music/trimmed'
    proc_dir = 'assets/sound/music/processed'
    tgt_dir = 'tgt/music'

    make_sfx(db_path, src_dir, tgt_dir, proc_dir, sample_rate)

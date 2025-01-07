import os
import shutil
import subprocess

def trim_wav_files(src_dir, tgt_dir):
    """
    Trims the first 10 seconds of .wav files in the source directory
    and saves them to the target directory.
    """

    # Remove and recreate the target directory
    if os.path.exists(tgt_dir):
        shutil.rmtree(tgt_dir)
    os.makedirs(tgt_dir)

    trimmed_files = []
    for filename in sorted(os.listdir(src_dir)):
        if filename.endswith('.wav') or filename.endswith('.mp3'):
            src_path = os.path.join(src_dir, filename)
            tgt_path = os.path.join(tgt_dir, filename)

            # Construct the ffmpeg command for trimming the first 10 seconds
            command = [
                'ffmpeg',
                '-i', src_path,              # Input file
                '-t', '10',                  # Duration (first 10 seconds)
                '-c', 'copy',                # Copy codec to avoid re-encoding
                tgt_path                     # Output file
            ]

            # Execute the command
            subprocess.run(command, check=True)

            # Save metadata for the trimmed file
            size = os.path.getsize(tgt_path)
            trimmed_files.append((filename, size))


if __name__ == '__main__':
    src_dir = 'assets/sound/music/original'
    tgt_dir = 'assets/sound/music/trimmed'
    trim_wav_files(src_dir, tgt_dir)
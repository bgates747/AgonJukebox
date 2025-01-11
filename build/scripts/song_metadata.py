import subprocess
import json


def get_sample_rate(file_path):
    """
    Extracts and prints the sample rate of the audio file from `ffprobe` metadata.
    """
    print(f"Getting sample rate for: {file_path}")
    try:
        result = subprocess.run(
            [
                'ffprobe',
                '-v', 'error',             # Suppress non-error messages
                '-select_streams', 'a:0',  # Focus on the first audio stream
                '-show_entries', 'stream=sample_rate',  # Get sample_rate field
                '-of', 'json',             # Output in JSON format
                file_path
            ],
            stdout=subprocess.PIPE,
            stderr=subprocess.DEVNULL,
            text=True,
            check=True
        )
        metadata = json.loads(result.stdout)
        sample_rate = metadata['streams'][0]['sample_rate']
        print(f"Sample rate: {sample_rate} Hz")
        return int(sample_rate)
    except subprocess.CalledProcessError as e:
        print(f"Error running ffprobe: {e.stderr}")
    except (KeyError, IndexError):
        print("Sample rate not found in ffprobe output.")

if __name__ == "__main__":
    file_name = 'assets/sound/music/staging/Africa.mp3'
    get_sample_rate(file_name)
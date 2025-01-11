import subprocess
import json


def get_metadata(file_path):
    """
    Extracts and prints all metadata of the audio file from `ffprobe`.
    """
    print(f"Getting metadata for: {file_path}")
    try:
        result = subprocess.run(
            [
                'ffprobe',
                '-v', 'error',             # Suppress non-error messages
                '-show_format',            # Show format metadata
                '-show_streams',           # Show streams metadata
                '-of', 'json',             # Output in JSON format
                file_path
            ],
            stdout=subprocess.PIPE,
            stderr=subprocess.DEVNULL,
            text=True,
            check=True
        )
        metadata = json.loads(result.stdout)
        print(json.dumps(metadata, indent=4))
        return metadata
    except subprocess.CalledProcessError as e:
        print(f"Error running ffprobe: {e.stderr}")
    except json.JSONDecodeError:
        print("Error decoding ffprobe output.")

if __name__ == "__main__":
    file_name = 'assets/sound/music/boston/1 - Boston - More Than a Feeling (Official HD Video).mp3'
    get_metadata(file_name)
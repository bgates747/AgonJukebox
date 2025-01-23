import os
import subprocess

def get_youtube_audio(url, output_dir):
    """
    Downloads a YouTube video's audio as separate MP3 files for each chapter if chapters are present.
    If no chapters are present, downloads the entire audio as a single MP3 file.

    Args:
        url (str): The URL of the YouTube video.
        output_dir (str): Directory to save the MP3 files.

    Returns:
        list: List of paths to the saved MP3 files.
    """
    # Ensure output directory exists
    os.makedirs(output_dir, exist_ok=True)

    # Define the output template
    output_template = os.path.join(output_dir, "%(title)s_%(section_title)s.%(ext)s")

    # yt-dlp command to download and split by chapters
    command = [
        "yt-dlp",
        "-x",  # Extract audio
        "--audio-format", "mp3",  # Convert to MP3
        "--restrict-filenames",  # Sanitize filenames
        "--split-chapters",  # Split audio by chapters
        "--output", output_template,  # Define output file template
        url,
    ]

    print(f"Downloading and converting: {url}")
    try:
        subprocess.run(command, check=True)

        # List all downloaded MP3 files
        downloaded_files = [
            os.path.join(output_dir, file) for file in os.listdir(output_dir) if file.endswith(".mp3")
        ]
        print("Downloaded files:")
        for file in downloaded_files:
            print(f"  - {file}")

        return downloaded_files
    except subprocess.CalledProcessError as e:
        print(f"An error occurred: {e}")
        raise

if __name__ == "__main__":
    youtube_url = 'https://youtu.be/VThrx5MRJXA'
    output_directory = 'assets/sound/music/staging'
    get_youtube_audio(youtube_url, output_directory)

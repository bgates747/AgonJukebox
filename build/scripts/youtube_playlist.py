import os
import subprocess

def download_youtube_playlist(playlist_url, output_dir):
    """
    Downloads all the songs from a YouTube playlist as MP3 files using yt-dlp.

    Args:
        playlist_url (str): The URL of the YouTube playlist.
        output_dir (str): Directory to save the MP3 files.
    """
    # Ensure output directory exists
    os.makedirs(output_dir, exist_ok=True)

    # yt-dlp command to download the entire playlist
    command = [
        "yt-dlp",
        "-x",  # Extract audio
        "--audio-format", "mp3",  # Convert to MP3
        "--yes-playlist",  # Download the entire playlist
        "--output", os.path.join(output_dir, "%(playlist_index)s - %(title)s.%(ext)s"),  # Output file template
        playlist_url,
    ]

    print(f"Downloading playlist: {playlist_url}")
    try:
        subprocess.run(command, check=True)
        print(f"Playlist downloaded successfully to: {output_dir}")
    except subprocess.CalledProcessError as e:
        print(f"An error occurred: {e}")
        raise

if __name__ == "__main__":
    playlist_url = "https://www.youtube.com/playlist?list=OLAK5uy_nIa5hnaHDjHpT76qUwvQaAgxpeu8XoSkk"
    output_directory = "assets/sound/music/boston"
    try:
        download_youtube_playlist(playlist_url, output_directory)
    except Exception as e:
        print(f"An error occurred: {e}")

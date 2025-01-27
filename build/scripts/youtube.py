import os
import subprocess

def get_youtube_audio_sections(url, output_dir):
    os.makedirs(output_dir, exist_ok=True)
    output_template = os.path.join(output_dir, "%(title)s_%(section_title)s.%(ext)s")

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
    subprocess.run(command, check=True)

def get_youtube_audio_single(url, output_dir):
    os.makedirs(output_dir, exist_ok=True)
    output_template = os.path.join(output_dir, "%(title)s.%(ext)s")

    command = [
        "yt-dlp",
        "-x",  # Extract audio
        "--audio-format", "wav",  # Convert to wav
        "--restrict-filenames",  # Sanitize filenames
        "--output", output_template,  # Define output file template
        url,
    ]

    print(f"Downloading and converting: {url}")
    subprocess.run(command, check=True)

if __name__ == "__main__":
    # youtube_url = 'https://youtu.be/VThrx5MRJXA' # 10 Hours of Classical Music
    # youtube_url = 'https://www.youtube.com/playlist?list=PL0ILEW7Puee34Winu4AFAUeLNMgAHBsAf'
    # youtube_url = 'https://youtu.be/RKexLWM33SI'
    # youtube_url = 'https://soundcloud.com/tonedef71/the-divided-states-of-america'
    youtube_url = 'https://youtu.be/FEacDWPWfJU'
    output_directory = 'assets/sound/music/staging'
    # get_youtube_audio_sections(youtube_url, output_directory)
    get_youtube_audio_single(youtube_url, output_directory)

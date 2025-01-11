import os
import subprocess
import unicodedata

def sanitize_filename(name):
    """
    Converts a string to ASCII, removes diacritics, and replaces spaces with underscores.
    
    Args:
        name (str): Original name with potential diacritics.
        
    Returns:
        str: Sanitized ASCII string.
    """
    name = unicodedata.normalize("NFKD", name).encode("ascii", "ignore").decode("ascii")
    return name.replace(" ", "_")

def download_youtube_audio(url, output_dir, final_filename):
    """
    Downloads a YouTube video's audio as an MP3 file using yt-dlp and renames it to a sanitized filename.
    
    Args:
        url (str): The URL of the YouTube video.
        output_dir (str): Directory to save the MP3 file.
        final_filename (str): Desired sanitized filename (without extension).
        
    Returns:
        str: Path to the saved MP3 file.
    """
    # Ensure output directory exists
    os.makedirs(output_dir, exist_ok=True)

    # Define the output path for the audio
    output_template = os.path.join(output_dir, "%(title)s.%(ext)s")

    # yt-dlp command to download and convert to MP3
    command = [
        "yt-dlp",
        "-x",  # Extract audio
        "--audio-format", "mp3",  # Convert to MP3
        "--output", output_template,  # Define output file template
        url,
    ]

    print(f"Downloading and converting: {url}")
    try:
        subprocess.run(command, check=True)

        # Find the downloaded file and rename it
        for file in os.listdir(output_dir):
            if file.endswith(".mp3") and file.startswith(final_filename):
                current_path = os.path.join(output_dir, file)
                sanitized_path = os.path.join(output_dir, f"{sanitize_filename(final_filename)}.mp3")
                os.rename(current_path, sanitized_path)
                print(f"File renamed to: {sanitized_path}")
                return sanitized_path
    except subprocess.CalledProcessError as e:
        print(f"An error occurred: {e}")
        raise

if __name__ == "__main__":
    songs = [
        # {"title": "Un Millon De Primaveras", "artist": "Vicente Fernandez", "url": "https://youtu.be/yvEtkdpRls8"},
        # {"title": "Cielito Lindo", "artist": "Pedro Infante", "url": "https://youtu.be/41xqsorstKQ"},
        # {"title": "Cucurrucucu Paloma", "artist": "Lola Beltran", "url": "https://youtu.be/wFV1IwmnhEU"},
        # {"title": "El Rey", "artist": "Jose Alfredo Jimenez", "url": "https://youtu.be/ZipzeNiBe_E"},
        # {"title": "La Malaguena", "artist": "Javier Solis", "url": "https://youtu.be/CeilXN6100M"},
        # {"title": "Sombras Nada Mas", "artist": "Javier Solis", "url": "https://youtu.be/UasiMOoMz1o"},
        # {"title": "Amor Eterno", "artist": "Rocio Durcal", "url": "https://youtu.be/BzLFsD0Wi6I"},
        # {"title": "Mi Ranchito", "artist": "Antonio Aguilar", "url": "https://youtu.be/hejohIYQ5cs"},
        # {"title": "Paloma Negra", "artist": "Chavela Vargas", "url": "https://youtu.be/bUqzNlbuyD0"},
        # {"title": "Volver Volver", "artist": "Luis Miguel", "url": "https://youtu.be/us-pj-m3Xlw"},
        # {"title": "Dire Straits", "artist": "Dire Straits", "url": "https://youtu.be/4Y8kJGK2C0Y"},
        # {"title": "The Dark Side of the Moon", "artist": "Pink Floyd", "url": "https://youtu.be/k9ynZnEBtvw"},
        # {"title": "Abbey Road", "artist": "The Beatles", "url": "https://youtu.be/VpV53LqcuhU"},
        # {"title": "Rumours", "artist": "Fleetwood Mac", "url": "https://youtu.be/lrltGatijXc"},
        # {"title": "Physical Graffiti", "artist": "Led Zeppelin", "url": "https://youtu.be/D2HC0G4T74Y"},
        # {"title": "Led Zeppelin I", "artist": "Led Zeppelin", "url": "https://youtu.be/LKbDC3lNVPQ"},
        # {"title": "Led Zeppelin II", "artist": "Led Zeppelin", "url": "https://youtu.be/W2bxOJX-E3M"},
        {"title": "Owner of a Lonely Heart", "artist": "Yes", "url": "https://youtu.be/AY7ktU1Db2A"}
    ]

    output_directory = "assets/sound/music/staging"

    for song in songs:
        try:
            print(f"Downloading: {song['title']} by {song['artist']}")
            mp3_path = download_youtube_audio(song["url"], output_directory, song["title"])
            print(f"MP3 file saved at: {mp3_path}")
        except Exception as e:
            print(f"An error occurred while downloading {song['title']} by {song['artist']}: {e}")
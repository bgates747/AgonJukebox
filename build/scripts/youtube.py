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
        {"title": "Un Millon De Primaveras", "artist": "Vicente Fernandez", "url": "https://youtu.be/yvEtkdpRls8"},
        {"title": "Cielito Lindo", "artist": "Pedro Infante", "url": "https://youtu.be/41xqsorstKQ"},
        {"title": "Cucurrucucu Paloma", "artist": "Lola Beltran", "url": "https://youtu.be/wFV1IwmnhEU"},
        {"title": "El Rey", "artist": "Jose Alfredo Jimenez", "url": "https://youtu.be/ZipzeNiBe_E"},
        {"title": "La Malaguena", "artist": "Javier Solis", "url": "https://youtu.be/CeilXN6100M"},
        {"title": "Sombras Nada Mas", "artist": "Javier Solis", "url": "https://youtu.be/UasiMOoMz1o"},
        {"title": "Amor Eterno", "artist": "Rocio Durcal", "url": "https://youtu.be/BzLFsD0Wi6I"},
        {"title": "Mi Ranchito", "artist": "Antonio Aguilar", "url": "https://youtu.be/hejohIYQ5cs"},
        {"title": "Paloma Negra", "artist": "Chavela Vargas", "url": "https://youtu.be/bUqzNlbuyD0"},
        {"title": "Volver Volver", "artist": "Luis Miguel", "url": "https://youtu.be/us-pj-m3Xlw"}
    ]

    output_directory = "assets/sound/music"

    for song in songs:
        try:
            print(f"Downloading: {song['title']} by {song['artist']}")
            mp3_path = download_youtube_audio(song["url"], output_directory, song["title"])
            print(f"MP3 file saved at: {mp3_path}")
        except Exception as e:
            print(f"An error occurred while downloading {song['title']} by {song['artist']}: {e}")


    # Example usage
    # youtube_url = "https://youtu.be/0xGPi-Al3zQ" # Rhiannon by Fleetwood Mac
    # youtube_url = "https://youtu.be/Epj84QVw2rc" # Come Undone by Duran Duran
    # youtube_url = "https://youtu.be/Kb7lAMjFuA0" # Africa by Toto
    # youtube_url = "https://youtu.be/6cucosmPj-A"  # Every Breath You Take by The Police
    # youtube_url = "https://youtu.be/GUBOgWYMBwo"  # Take a Ride by Don Felder
    # youtube_url = "https://youtu.be/VdOkQ6THDVw"  # Barracuda by Heart
    # youtube_url = "https://youtu.be/88T131rQCUc"  # Anytime by Journey
    # youtube_url = "https://youtu.be/bLxApTwMLJI" # Wildflower by The Cult
    # youtube_url = "https://youtu.be/W_TOsFvnmeQ" # Jukebox Hero by Foreigner
    # youtube_url = "https://youtu.be/Jtb10ZwbReY" # Won't Get Fooled Again by The Who
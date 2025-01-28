import os
import subprocess
import glob
from make_wav import convert_to_wav, resample_wav, convert_to_unsigned_pcm_wav, make_sfx, compress_dynamic_range, normalize_audio, get_audio_metadata
import agonutils as au

def download_youtube_video(url, staging_directory):
    """
    Downloads the entire video from YouTube.
    """
    os.makedirs(staging_directory, exist_ok=True)
    output_template = os.path.join(staging_directory, "%(title)s.%(ext)s")

    command = [
        "yt-dlp",
        "--restrict-filenames",  # Sanitize filenames
        "--format", "mp4",
        "--output", output_template,  # Define output file template
        url,
    ]

    print(f"Downloading full video: {url}")
    subprocess.run(command, check=True)
    print("Download completed.")


def extract_audio_from_video(input_file, processed_directory):
    """
    Extracts audio from a video file with minimal processing and saves it as MP3.
    """
    os.makedirs(processed_directory, exist_ok=True)
    base_name = os.path.splitext(os.path.basename(input_file))[0]
    output_file = os.path.join(processed_directory, f"{base_name}_audio.mp3")

    command = [
        "ffmpeg",
        "-i", input_file,         # Input file
        "-vn",                    # Disable video processing
        "-c:a", "libmp3lame",     # Encode audio as MP3
        output_file,
    ]

    print(f"Extracting audio to {output_file}")
    subprocess.run(command, check=True)
    print("Audio extraction completed.")

def extract_and_resize_video(input_file, processed_directory, target_directory, target_width, target_height):
    """
    Extracts and resizes video to the specified resolution.
    """
    os.makedirs(processed_directory, exist_ok=True)
    os.makedirs(target_directory, exist_ok=True)

    base_name = os.path.splitext(os.path.basename(input_file))[0]
    resized_file = os.path.join(processed_directory, f"{base_name}.mp4")

    # Resize the video
    print(f"Resizing video: {input_file}")
    subprocess.run([
        "ffmpeg",
        "-i", input_file,
        "-an",                     # Disable audio processing
        "-vf", f"scale={target_width}:{target_height}",  # Resize to target resolution
        "-c:v", "libx264",         # Use H.264 codec for compatibility
        resized_file,
    ], check=True)
    print(f"Video resized to {resized_file}")

def extract_frames(input_file, target_directory, target_width, target_height, frame_rate):
    """
    Extracts video frames at the specified frame rate, resizes them, and saves as PNG files.
    """
    os.makedirs(target_directory, exist_ok=True)
    # Delete all files in the frames directory
    files = glob.glob(f"{target_directory}/*")
    for f in files:
        os.remove(f)

    # Define the frame extraction pattern
    output_pattern = os.path.join(target_directory, "frame_%04d.png")

    # Extract frames using FFmpeg
    print(f"Extracting frames from {input_file} at {frame_rate} FPS...")
    subprocess.run([
        "ffmpeg",
        "-i", input_file,           # Input video
        "-vf", f"fps={frame_rate},scale={target_width}:{target_height}",  # Set frame rate and resolution
        "-pix_fmt", "rgba",         # Ensure RGBA format for PNG
        "-start_number", "0",       # Start numbering frames from 0
        output_pattern,             # Output pattern for PNG files
    ], check=True)
    print(f"Frames saved to {target_directory}")

def process_frames(frames_directory, palette_filepath, transparent_rgb, palette_conversion_method):
    # Scan the directory for all .png files and sort them
    filenames = sorted([f for f in os.listdir(frames_directory) if f.endswith('.png')])
    total_frames = len(filenames)
    print(f"Found {total_frames} frames to process.")
    for i, input_image_filename in enumerate(filenames, start=1):
        input_image_path = os.path.join(frames_directory, input_image_filename)
        base_filename = os.path.splitext(input_image_filename)[0]
        rgba_filepath = f'{frames_directory}/{base_filename}.rgba2'
        print(f"Processing frame {i}/{total_frames}: {input_image_filename}...", end='', flush=True)
        au.convert_to_palette(input_image_path, input_image_path, palette_filepath, palette_conversion_method, transparent_rgb)
        au.img_to_rgba2(input_image_path, rgba_filepath)
        print("\r" + f"Frame {i}/{total_frames} processed: {input_image_filename}", end='', flush=True)
    print("\nDone processing all frames.")

def process_all_videos(staging_directory, processed_directory, frames_directory, target_directory, target_width, target_height, frame_rate, palette_filepath, transparent_rgb, palette_conversion_method):
    """
    Processes all video files in the staging directory.
    """
    video_files = glob.glob(os.path.join(staging_directory, "*.mp4"))
    if not video_files:
        print("No video files found in the staging directory.")
        return

    for video_file in video_files:
        print(f"\nProcessing: {video_file}")
        # extract_audio_from_video(video_file, processed_directory)
        # extract_and_resize_video(video_file, processed_directory, target_directory, target_width, target_height)
        # extract_frames(video_file, frames_directory, target_width, target_height, frame_rate)
        process_frames(frames_directory, palette_filepath, transparent_rgb, palette_conversion_method)

if __name__ == "__main__":
    # Define directories
    staging_directory = "assets/video/staging"
    processed_directory = "assets/video/processed"
    frames_directory = "assets/video/frames"
    target_directory = "tgt/video"
    palette_filepath =      'assets/images/palettes/Agon64.gpl'
    transparent_rgb = (0, 0, 0, 0)
    palette_conversion_method = 'floyd'

    # Define target video resolution
    target_width = 128
    target_height = 96
    frame_rate = 4
    sample_rate = 10848
    do_compression = True
    do_normalization = True

    # YouTube URL
    youtube_url = "https://youtu.be/QrjC_GTF18o"  # Heavy Metal B-17 Flying Fortress Scene
    youtube_url = "https://youtu.be/djV11Xbc914" # Ah Ha - Take on Me

    # Step 1: Download video
    # download_youtube_video(youtube_url, staging_directory)

    # Step 2: Process all videos in the staging directory
    process_all_videos(staging_directory, processed_directory, frames_directory, target_directory, target_width, target_height, frame_rate, palette_filepath, transparent_rgb, palette_conversion_method)

    # Step 3: Process audio files
    # make_sfx(processed_directory, target_directory, sample_rate, do_compression, do_normalization)
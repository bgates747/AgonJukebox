#!/usr/bin/env python3
import os
import subprocess
import glob
import shutil
import json
from PIL import Image
import re
import sys
from make_agm import make_agm
from make_agm_cmp import make_agm_cmp
from make_agm_dif import make_agm_dif
from make_agm_rle import make_agm_rle
from make_agm_szip import make_agm_szip
from make_agm_jpeg import make_agm_jpeg

# -------------------------------------------------------------------
# External utilities:
#   "yt-dlp" for YouTube downloads
#   "ffmpeg" for audio/video extraction
# And your Python modules:
#   make_wav.py (with compress_dynamic_range, etc.)
#   agonutils.py (with palette conversion, etc.)
#
# Adjust as needed to import your local modules.
# -------------------------------------------------------------------
from make_wav import (
    compress_dynamic_range,
    normalize_audio,
    get_audio_metadata,
    resample_wav,
    convert_to_unsigned_pcm_wav,
)
import agonutils as au

# from play_agm import play_agm

# ============================================================
#              YOUTUBE DOWNLOADER
# ============================================================

def download_video():
    if os.path.exists(staged_video_path):
        os.remove(staged_video_path)

    print("-------------------------------------------------")
    print(f"download_video: {youtube_url} To: {staged_video_path}")

    # Download video-only stream (video only; audio to be downloaded separately)
    command = [
        "yt-dlp",
        "--restrict-filenames",
        # "--format", f"bestvideo[height<={max_height}]",  # video only, no audio
        "--format", "mp4",
        "--output", staged_video_path,
        youtube_url,
    ]
    subprocess.run(command, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL, check=True)

    if not os.path.exists(staged_video_path):
        raise RuntimeError(f"Download failed: {staged_video_path} was not created.")

    file_size = os.path.getsize(staged_video_path)
    file_size_mb = f"{file_size / (1024 * 1024):.2f}MiB"
    print(f"Download completed. Size: {file_size_mb}")
    print("")


# ============================================================
#              AUDIO EXTRACTION
# ============================================================

def download_audio():
    """
    Downloads audio from the YouTube video as 16-bit PCM WAV in mono,
    capping the sample rate at 48000 Hz.
    """
    os.makedirs(processed_directory, exist_ok=True)

    # Remove any existing file first.
    if os.path.exists(staged_audio_path):
        os.remove(staged_audio_path)

    print("-------------------------------------------------")
    print(f"download_audio to {staged_audio_path}")

    # Download audio-only stream and convert to WAV using yt-dlp.
    # This command tells yt-dlp to extract audio, convert it to WAV,
    command = [
        "yt-dlp",
        "--restrict-filenames",
        "--extract-audio",
        "--audio-format", "wav",
        "--audio-quality", "0",  # best quality
        "--postprocessor-args", "-ac 1 -ar 16000",
        "--output", staged_audio_path,
        youtube_url,
    ]
    
    subprocess.run(command, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL, check=True)

    if not os.path.exists(staged_audio_path):
        raise RuntimeError(f"Audio extraction failed: {staged_audio_path} was not created.")

    file_size = os.path.getsize(staged_audio_path)
    file_size_mb = f"{file_size / (1024 * 1024):.2f}MiB"

    print(f"Audio download completed. Sample rate capped at 16000Hz Size: {file_size_mb}")
    print("")

def preprocess_audio():
    """
    Performs optional processing on the staged_audio_path file:
      - If do_compression is True, applies dynamic range compression.
      - If do_normalization is True, applies loudness normalization.
    
    This function operates on the file specified by staged_audio_path and uses a
    temporary file located in staging_directory ("temp.wav").
    """
    # Define codec as 16-bit PCM little-endian signed.
    codec = "pcm_s16le"

    if do_compression or do_normalization:
        temp_path = os.path.join(staging_directory, "temp.wav")

        # Remove any existing temporary file.
        if os.path.exists(temp_path):
            os.remove(temp_path)

        # Dynamic Range Compression
        if do_compression:
            print("Applying dynamic range compression...")
            shutil.copy(staged_audio_path, temp_path)
            compress_dynamic_range(temp_path, staged_audio_path, codec)
            os.remove(temp_path)

            # Report status after compression
            compressed_sample_rate, compressed_codec = get_audio_metadata(staged_audio_path)
            print(f"After compression - Sample rate: {compressed_sample_rate} Hz, Codec: {compressed_codec}")

        # Loudness Normalization
        if do_normalization:
            print("Applying loudness normalization...")
            shutil.copy(staged_audio_path, temp_path)
            normalize_audio(temp_path, staged_audio_path, codec)
            os.remove(temp_path)

            # Report status after normalization
            normalized_sample_rate, normalized_codec = get_audio_metadata(staged_audio_path)
            print(f"After normalization - Sample rate: {normalized_sample_rate} Hz, Codec: {normalized_codec}")

    print("")

# ============================================================
#              AUDIO CONVERSION
# ============================================================
def convert_audio():
    """
    Converts an audio file (e.g. MP3) into 8-bit unsigned PCM `.wav`.
    Resamples to `target_sample_rate` if needed, optionally compresses & normalizes.
    """
    temp_path = os.path.join(staging_directory, "temp.wav")

    print("-------------------------------------------------")
    print(f"convert_audio: {staged_audio_path}")
    if os.path.exists(temp_path):
        os.remove(temp_path)

    # 1) Get metadata
    _, codec = get_audio_metadata(staged_audio_path)

    # 2) Resample
    shutil.copy(staged_audio_path, temp_path)
    resample_wav(temp_path, target_audio_path, target_sample_rate, codec)
    os.remove(temp_path)

    # 3) Convert to 8-bit unsigned PCM
    shutil.copy(target_audio_path, temp_path)
    convert_to_unsigned_pcm_wav(temp_path, target_audio_path, target_sample_rate)
    os.remove(temp_path)

    print(f"Finished audio processing: {target_audio_path}")
    print("")


# -------------------------------------------------------------------
# 1. Extract Frames Without Resizing
# -------------------------------------------------------------------
def extract_frames():
    """
    Extracts frames from the intermediate MP4 at the desired FPS and saves them as PNG files.
    Only the first minute of video is extracted.
    No scaling is applied—this ensures that the full-resolution frames are available for later processing.
    """

    # Clear out old frames
    for f in glob.glob(os.path.join(frames_directory, "*")):
        os.remove(f)
    
    output_pattern = os.path.join(frames_directory, "frame_%05d.png")
    print("-------------------------------------------------")
    print(f"Extracting frames at {frame_rate} FPS to {frames_directory}")

    # Use ffmpeg to extract only the first minute (-t 60) at the given FPS without any scaling.
    process = subprocess.Popen(
        [
            "ffmpeg",
            "-i", processed_video_path,
            "-t", "60",                  # Limit extraction to the first 60 seconds
            "-vf", f"fps={frame_rate}",
            "-pix_fmt", "rgba",
            "-start_number", "0",
            "-y",                        # Overwrite output files without prompting
            output_pattern,
        ],
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        text=True
    )

    # (Optional) Show progress by reading ffmpeg stderr output.
    frame_pattern = re.compile(r"frame=\s*\d+")
    for line in iter(process.stderr.readline, ''):
        match = frame_pattern.search(line)
        if match:
            sys.stdout.write(f"\r{match.group(0)}")
            sys.stdout.flush()
    process.wait()

    print("\nFrame extraction complete.\n")


# -------------------------------------------------------------------
# 2. Process Frames: Crop, Resize, Palette Convert, and Convert to .rgba2
# -------------------------------------------------------------------
def process_frames():
    """
    Processes the previously extracted PNG frames by:
      1) Removing letterboxing if detected.
      2) Cropping or resizing the image to exactly target_width x target_height.
      3) Converting the processed image to a custom palette.
      4) Converting the palette-based PNG to a .rgba2 (8bpp) file.
    
    This separation lets you experiment with different cropping/resizing and palette conversion
    parameters without re-extracting the frames (as long as the frame rate remains unchanged).
    
    Note: Letterbox detection is done on each PNG individually.
          (If the first few frames are blank, detection might fail. In that case you may need
           to either adjust the threshold/min_crop_ratio parameters in remove_letterbox() or
           sample a frame further into the video.)
    """
    filenames = sorted([f for f in os.listdir(frames_directory) if f.endswith('.png')])
    total_frames = len(filenames)

    print("-------------------------------------------------")
    print(f"process_frames: Processing {total_frames} frames in {frames_directory}.")

    for i, pngfile in enumerate(filenames, start=1):
        pngpath = os.path.join(frames_directory, pngfile)
        base = os.path.splitext(pngfile)[0]
        rgba2_path = os.path.join(frames_directory, base + ".rgba2")

        # --- 1) Load the extracted frame ---
        content_img = Image.open(pngpath)

        # --- 2) Remove letterbox (black borders) if present ---
        if do_remove_letterbox: content_img = remove_letterbox(content_img)

        # --- 3) Adjust image to target dimensions ---
        cw, ch = content_img.size
        if cw >= target_width and ch >= target_height:
            final_img = center_crop(content_img, target_width, target_height)
        else:
            # If the content is smaller than desired, upscale it
            final_img = content_img.resize((target_width, target_height), Image.LANCZOS)
        # Optionally, overwrite the PNG with the processed image
        final_img.save(pngpath)

        # --- 4) Convert to your custom palette (in-place) ---
        au.convert_to_palette(
            pngpath,                  # src
            pngpath,                  # output (overwrite)
            palette_filepath,
            palette_conversion_method,
            transparent_rgb
        )

        # --- 5) Convert palette-based PNG to .rgba2 (8bpp) ---
        au.img_to_rgba2(pngpath, rgba2_path)

        print(f"Frame {i}/{total_frames} processed: {pngfile}", end='\r')
    print("\nAll frames processed to .rgba2.\n")

def remove_letterbox(img):
    """
    Center-crops the image vertically so that its aspect ratio matches
    the desired ratio (target_width:target_height). It keeps the full
    horizontal width and crops the top and bottom equally.
    """
    width, height = img.size
    # Compute desired aspect ratio (width / height)
    desired_aspect = target_width / target_height
    # Calculate the new height using the full width
    new_height = int(width / desired_aspect)
    
    # If the computed new height exceeds the image height, return the original
    if new_height > height:
        return img

    top = (height - new_height) // 2
    bottom = top + new_height
    return img.crop((0, top, width, bottom))


def center_crop(img, final_width, final_height):
    """
    Center-crops 'img' to final_width x final_height.
    """
    width, height = img.size
    left = (width - final_width) // 2
    top = (height - final_height) // 2
    right = left + final_width
    bottom = top + final_height
    return img.crop((left, top, right, bottom))


def delete_frames():
    print("-------------------------------------------------")
    print("delete_frames working...")

    n = 0  # Counter for deleted files

    for file in glob.glob(os.path.join(frames_directory, "*.rgba2")) + glob.glob(os.path.join(frames_directory, "*.png")):
        os.remove(file)
        n += 1  # Increment counter

    print(f"Deleted {n} .png and .rgba2 files in {frames_directory}.")
    print("")

def delete_processed_files():
    print("-------------------------------------------------")
    print("delete_processed_files working...")

    n = 0  # Counter for deleted files

    for file in [processed_video_path]:  # List of files to delete
        if os.path.exists(file):
            os.remove(file)
            n += 1  # Increment counter
            print(f"Deleted: {file}")

    print(f"{n} files deleted.")
    print("")


def do_all_the_things():
    if do_download_video:
        download_video()

    if do_download_audio:
        download_audio()

    if do_compression or do_normalization:
        preprocess_audio()

    if do_convert_audio:
        convert_audio()

    if do_extract_frames:
        extract_frames()

    if do_process_frames:
        process_frames()

    if do_make_agm:
        # make_agm(frames_directory, target_audio_path, target_agm_path, target_width, target_height, frame_rate, target_sample_rate, chunksize)
        # make_agm_cmp(frames_directory, target_audio_path, target_agm_path, target_width, target_height, frame_rate, target_sample_rate, chunksize)
        # make_agm_dif(frames_directory, target_audio_path, target_agm_path, target_width, target_height, frame_rate, target_sample_rate, chunksize)
        # make_agm_rle(frames_directory, target_audio_path, target_agm_path, target_width, target_height, frame_rate, target_sample_rate, chunksize)
        make_agm_szip(frames_directory, target_audio_path, target_agm_path, target_width, target_height, frame_rate, target_sample_rate, chunksize)
        # make_agm_jpeg(frames_directory,target_audio_path,target_agm_path,target_width,target_height,frame_rate,target_sample_rate,chunksize,quality,optimize)

    if do_delete_frames:
        delete_frames()

    if do_delete_processed_files:
        delete_processed_files()

    # if do_play_agm:
    #     play_agm(target_agm_path)

# ============================================================
#              EXAMPLE USAGE
# ============================================================
if __name__ == "__main__":
    do_download_video = False
    do_download_audio = False
    do_convert_audio = False
    do_compression   = False
    do_normalization = False
    do_extract_frames = False
    do_process_frames = False
    do_make_agm = False
    do_delete_frames = False
    do_delete_processed_files = False
    do_play_agm = False

    # Example usage with your chosen directories:
    staging_directory   = "/home/smith/Agon/mystuff/assets/video/staging"
    processed_directory = "/home/smith/Agon/mystuff/assets/video/processed"
    frames_directory    = "/home/smith/Agon/mystuff/assets/video/frames"
    target_directory    = "tgt/video"

    target_width  = 320
    do_remove_letterbox = True

    # For jpeg encoding only
    quality = 50
    optimize = True
    
    # target_height = int(target_width * 0.75)  # 4:3 aspect ratio

    # youtube_url = "https://youtu.be/djV11Xbc914" # A Ha Take On Me
    # video_base_name = f'a_ha__Take_On_Me'

    # youtube_url = "https://youtu.be/FtutLA63Cp8" # Bad Apple
    # video_base_name = f'Bad_Apple'

    # youtube_url = "https://youtu.be/sOnqjkJTMaA" # Michael Jackson Thriller


    target_height = int(target_width / 2.35) 

    youtube_url = "https://youtu.be/3yWrXPck6SI" # Star Wars Battle of Yavin
    video_base_name = f'Star_Wars__Battle_of_Yavin'

    # youtube_url = "https://youtu.be/evyyr24r1F8" # Battle of Hoth Part 1
    # video_base_name = f'Star_Wars__Battle_of_Hoth_Part_1'

    # youtube_url = "https://youtu.be/6Q_jdg1gQms" # Top Gun Danger Zone
    # youtube_url = "https://youtu.be/oJguy6wSYyI" # Star Wars Opening Crawl

    # youtube_url = "https://youtu.be/vrHeuwO5agw" # The Terminator
    # video_base_name = f'The_Terminator'

    palette_filepath = '/home/smith/Agon/mystuff/assets/images/palettes/Agon63.gpl'
    transparent_rgb = (0, 0, 0, 0)
    palette_conversion_method = 'bayer'

    # For your *no-rounding* design example:
    max_height = 720 
    frame_rate    = 30
    bytes_per_sec = 60000
    target_sample_rate = 16000
    chunksize = bytes_per_sec // 60
    
    video_target_name = f'{video_base_name}' #_{target_width}x{target_height}x{frame_rate}' # x{target_sample_rate}'
    staged_video_path = os.path.join(staging_directory, f"{video_base_name}.mp4")
    processed_video_path = os.path.join(processed_directory, f"{video_target_name}.mp4")
    staged_audio_path = os.path.join(staging_directory, f"{video_base_name}.wav")
    target_audio_path = os.path.join(target_directory, f"{video_target_name}.wav")
    target_agm_path = os.path.join(target_directory, f"{video_target_name}_{palette_conversion_method}.agm")

# ============================================================
# # Download group
#     do_download_video = True
#     do_download_audio = True

# # Extract audio group
#     do_compression   = True
#     do_normalization = True
#     do_convert_audio = True

# # Extract video group
    do_extract_frames = True
    do_process_frames = True

# # Make AGM group
#     do_make_agm = True

# # Clean up group
#     do_delete_frames = True
#     do_delete_processed_files = True

# Play AGM group
    # do_play_agm = True

    do_all_the_things()

#!/usr/bin/env python3
import os
import subprocess
import glob
import shutil
from PIL import Image
import re
import sys
from make_agm_srl2 import make_agm_srle2

from make_wav import (
    compress_dynamic_range,
    normalize_audio,
    get_audio_metadata,
    resample_wav,
    convert_to_unsigned_pcm_wav,
)
import agonutils as au

# ============================================================
#              YOUTUBE DOWNLOADER
# ============================================================

def download_video(staged_video_path):
    if os.path.exists(staged_video_path):
        os.remove(staged_video_path)

    print("-------------------------------------------------")
    print(f"download_video: {youtube_url} To: {staged_video_path}")

    command = [
        "yt-dlp",
        "--restrict-filenames",
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

def download_audio(staged_audio_path, audio_sample_rate):
    os.makedirs(processed_directory, exist_ok=True)

    # Remove any existing file first.
    if os.path.exists(staged_audio_path):
        os.remove(staged_audio_path)

    print("-------------------------------------------------")
    print(f"download_audio to {staged_audio_path}")

    command = [
        "yt-dlp",
        "--restrict-filenames",
        "--extract-audio",
        "--audio-format", "wav",
        "--audio-quality", "0",  # best quality
        "--postprocessor-args", f"-ac 1 -ar {audio_sample_rate}",
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

def preprocess_audio(staged_audio_path):
    # Define codec as 16-bit PCM little-endian signed.
    codec = "pcm_s16le"

    temp_path = os.path.join(staging_directory, "temp.wav")

    # Remove any existing temporary file.
    if os.path.exists(temp_path):
        os.remove(temp_path)

    # Dynamic Range Compression
    print("Applying dynamic range compression...")
    shutil.copy(staged_audio_path, temp_path)
    compress_dynamic_range(temp_path, staged_audio_path, codec)
    os.remove(temp_path)

    # Report status after compression
    compressed_sample_rate, compressed_codec = get_audio_metadata(staged_audio_path)
    print(f"After compression - Sample rate: {compressed_sample_rate} Hz, Codec: {compressed_codec}")

    # Loudness Normalization
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

def convert_audio(staged_audio_path, target_audio_path):
    # First, trim the full audio to the desired segment using ffmpeg.
    trimmed_audio_path = os.path.join(staging_directory, "trimmed.wav")
    if os.path.exists(trimmed_audio_path):
        os.remove(trimmed_audio_path)
    print("-------------------------------------------------")
    print(f"Trimming audio from {staged_audio_path} starting at {seek_time} for duration {duration}")
    command = [
        "ffmpeg",
        "-y",
        "-ss", seek_time,
        "-t", f"{duration}",
        "-i", staged_audio_path,
        trimmed_audio_path
    ]
    subprocess.run(command, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL, check=True)
    
    # Now process the trimmed audio.
    temp_path = os.path.join(staging_directory, "temp.wav")
    print(f"convert_audio: {trimmed_audio_path}")
    if os.path.exists(temp_path):
        os.remove(temp_path)

    # 1) Get metadata from the trimmed audio.
    _, codec = get_audio_metadata(trimmed_audio_path)

    # 2) Resample the trimmed audio.
    shutil.copy(trimmed_audio_path, temp_path)
    resample_wav(temp_path, target_audio_path, target_sample_rate, codec)
    os.remove(temp_path)

    # 3) Convert to 8-bit unsigned PCM.
    shutil.copy(target_audio_path, temp_path)
    convert_to_unsigned_pcm_wav(temp_path, target_audio_path, target_sample_rate)
    os.remove(temp_path)

    print(f"Finished audio processing: {target_audio_path}")
    print("")


# -------------------------------------------------------------------
# 1. Extract Frames Without Resizing
# -------------------------------------------------------------------
def extract_frames(staged_video_path, seek_time, duration, frame_rate):
    # Clear out old frames
    for f in glob.glob(os.path.join(frames_directory, "*")):
        os.remove(f)
    
    output_pattern = os.path.join(frames_directory, "frame_%05d.png")
    print("-------------------------------------------------")
    print(f"Extracting frames at {frame_rate} FPS to {frames_directory}")

    process = subprocess.Popen(
        [
            "ffmpeg",
            "-ss", seek_time,
            "-i", staged_video_path,
            "-t", f"{duration}",
            "-vf", f"fps={frame_rate}",
            "-pix_fmt", "rgba",
            "-start_number", "0",
            "-y",  # Overwrite output files without prompting
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
    filenames = sorted([f for f in os.listdir(frames_directory) if f.endswith('.png')])
    total_frames = len(filenames)

    print("-------------------------------------------------")
    print(f"process_frames: Processing {total_frames} frames in {frames_directory}.")

    for i, pngfile in enumerate(filenames, start=1):
        pngpath = os.path.join(frames_directory, pngfile)
        base = os.path.splitext(pngfile)[0]
        rgba2_path = os.path.join(frames_directory, base + ".rgba2")

        # 1) Load the extracted frame.
        content_img = Image.open(pngpath)

        # 2) If letterbox removal is enabled, remove letterboxing;
        #    otherwise assume the image already has the proper aspect ratio.
        if do_remove_letterbox:
            content_img = remove_letterbox(content_img)

        # 3) Resize directly to the target dimensions without cropping.
        final_img = content_img.resize((target_width, target_height), Image.LANCZOS)
        final_img.save(pngpath)

        # 4) Convert to your custom palette (in-place).
        au.convert_to_palette(
            pngpath,                  # src
            pngpath,                  # output (overwrite)
            palette_filepath,
            palette_conversion_method,
            transparent_rgb
        )

        # 5) Convert the palette-based PNG to .rgba2 (8bpp).
        au.img_to_rgba2(pngpath, rgba2_path)

        print(f"Frame {i}/{total_frames} processed: {pngfile}", end='\r')
    print("\nAll frames processed to .rgba2.\n")

def remove_letterbox(img):
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

def delete_frames():
    print("-------------------------------------------------")
    print("delete_frames working...")

    n = 0  # Counter for deleted files

    for file in glob.glob(os.path.join(frames_directory, "*.rgba2")) + glob.glob(os.path.join(frames_directory, "*.png")):
        os.remove(file)
        n += 1  # Increment counter

    print(f"Deleted {n} .png and .rgba2 files in {frames_directory}.")
    print("")


def do_all_the_things():
    video_target_name = f'{video_base_name}'
    staged_video_path = os.path.join(staging_directory, f"{video_base_name}.mp4")
    staged_audio_path = os.path.join(staging_directory, f"{video_base_name}.wav")
    target_audio_path = os.path.join(target_directory, f"{video_target_name}.wav")
    target_agm_path = os.path.join(target_directory, f"{video_target_name}_{palette_conversion_method}.agm")

    # download_video(staged_video_path)
    # download_audio(staged_audio_path, target_sample_rate)

    preprocess_audio(staged_audio_path)
    convert_audio(staged_audio_path, target_audio_path)

    extract_frames(staged_video_path, seek_time, duration, frame_rate)
    process_frames()

    make_agm_srle2(frames_directory, target_audio_path, target_agm_path, target_width, target_height, frame_rate, target_sample_rate, chunksize)
    
    # delete_frames()

# ============================================================
#              EXAMPLE USAGE
# ============================================================
if __name__ == "__main__":
    staging_directory   = "/home/smith/Agon/mystuff/assets/video/staging"
    processed_directory = "/home/smith/Agon/mystuff/assets/video/processed"
    frames_directory    = "/home/smith/Agon/mystuff/assets/video/frames"
    target_directory    = "tgt/video"

    palette_filepath = '/home/smith/Agon/mystuff/assets/images/palettes/Agon64.gpl'
    transparent_rgb = (0, 0, 0, 0)
    palette_conversion_method = 'floyd'

    bytes_per_sec = 60000
    target_sample_rate = 16000
    chunksize = bytes_per_sec // 60

    youtube_url = "https://youtu.be/3yWrXPck6SI"
    video_base_name = f'Star_Wars__Battle_of_Yavin'
    target_width  = 320
    target_height = int(target_width / 2.35) 
    do_remove_letterbox = True

    seek_time = "00:05:00"
    duration  = 60
    frame_rate    = 30


    do_all_the_things()

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

from play_agm import play_agm

# ============================================================
#              YOUTUBE DOWNLOADER
# ============================================================

def download_video():
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
    
    width, height = get_video_dimensions(staged_video_path)
    file_size = os.path.getsize(staged_video_path)
    file_size_mb = f"{file_size / (1024 * 1024):.2f}MiB"  # Convert bytes to MB
    print(f"Download completed. Video dimensions: {width}x{height} Size: {file_size_mb}")
    print("")

# ============================================================
#              AUDIO EXTRACTION
# ============================================================

def extract_audio():
    """
    Extracts audio from a video file as 16-bit PCM WAV in mono,
    preserving the original sample rate but capping it at 48000 Hz.
    """
    os.makedirs(processed_directory, exist_ok=True)

    # Ensure any existing file is removed before extraction
    if os.path.exists(staged_audio_path):
        os.remove(staged_audio_path)

    print("-------------------------------------------------")
    print(f"extract_audio to {staged_audio_path}")

    # Get source sample rate and codec
    source_sample_rate, codec = get_audio_metadata(staged_video_path)

    # Cap the sample rate at 48000 Hz
    if source_sample_rate > 48000:
        source_sample_rate = 48000

    # FFmpeg command: Convert to 16-bit PCM WAV with mono audio, applying sample rate cap
    command = [
        "ffmpeg",
        "-i", staged_video_path,  # Input file
        "-vn",                    # Disable video
        "-acodec", "pcm_s16le",   # Use WAV format (16-bit PCM)
        "-ar", str(source_sample_rate),  # Apply capped sample rate
        "-ac", "1",               # Convert to mono
        "-y",                     # Overwrite existing files without prompt
        staged_audio_path,
    ]

    # Run FFmpeg silently
    subprocess.run(command, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL, check=True)

    # Ensure the file was successfully created
    if not os.path.exists(staged_audio_path):
        raise RuntimeError(f"Audio extraction failed: {staged_audio_path} was not created.")

    # Get final file size
    file_size = os.path.getsize(staged_audio_path)
    file_size_mb = f"{file_size / (1024 * 1024):.2f}MiB"

    # Print summary
    print(f"Audio extraction completed. Sample rate: {source_sample_rate}Hz Size: {file_size_mb}")

    # Optional processing: Compression & Normalization
    if do_compression or do_normalization:
        temp_path = os.path.join(staging_directory, "temp.wav")

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

# ============================================================
#              VIDEO RESIZING & FRAME EXTRACTION
# ============================================================
def get_video_dimensions(input_file):
    """
    Returns (width, height) as integers using ffprobe.
    """
    cmd = [
        'ffprobe',
        '-v', 'error',  # Suppress all but errors
        '-select_streams', 'v:0',
        '-show_entries', 'stream=width,height',
        '-of', 'json',
        input_file
    ]
    proc = subprocess.run(cmd, capture_output=True, text=True)
    if proc.returncode != 0:
        raise RuntimeError(f"ffprobe failed on {input_file}: {proc.stderr}")

    info = json.loads(proc.stdout)
    streams = info.get('streams')
    if not streams:
        raise ValueError("No video streams found.")
    
    w, h = int(streams[0].get('width')), int(streams[0].get('height'))
    return w, h

def extract_video():
    """
    Resizes video while preserving aspect ratio, displaying frame progress.
    - Extracts frame count from FFmpeg output and updates progress dynamically.
    """

    # -- Get original aspect --
    orig_w, orig_h = get_video_dimensions(staged_video_path)
    if orig_h == 0:
        raise ValueError("extract_video Original video height is 0?")

    orig_aspect = orig_w / orig_h
    target_aspect = target_width / target_height

    # -- Decide how to scale in FFmpeg --
    if orig_aspect > target_aspect:
        # Original is "wider" => fix height, auto width
        scale_filter = f"scale=-2:{target_height}"
    else:
        # Original is "taller" or narrower => fix width, auto height
        scale_filter = f"scale={target_width}:-2"

    print("-------------------------------------------------")
    print(f"extract_video Resizing: {orig_w}x{orig_h} -> {target_width}x{target_height} (Preserving aspect)")

    # Start FFmpeg process
    process = subprocess.Popen(
        [
            "ffmpeg",
            "-i", staged_video_path,
            "-an",  # Disable audio
            "-vf", scale_filter,
            "-c:v", "libx264",
            "-crf", "28",
            "-preset", "fast",
            "-y",  # Overwrite output
            processed_video_path,
        ],
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        text=True
    )

    # Regex pattern to extract frame count from FFmpeg logs
    frame_pattern = re.compile(r"frame=\s*(\d+)")

    # Read FFmpeg output in real-time
    for line in iter(process.stderr.readline, ''):
        match = frame_pattern.search(line)
        if match:
            frame_count = match.group(1)
            sys.stdout.write(f"\rProcessing frame: {frame_count}")  # Overwrite the same line
            sys.stdout.flush()

    process.wait()  # Ensure FFmpeg completes

    print(f"\nProcessed video saved: {processed_video_path}") 
    print("")

def extract_frames():
    """
    Extract frames from the intermediate MP4 at the desired FPS.
    - Does NOT scale further (assumes intermediate aspect-corrected size).
    - Saves PNG frames while displaying real-time progress.
    """

    # Clear out old frames
    for f in glob.glob(f"{frames_directory}/*"):
        os.remove(f)

    output_pattern = os.path.join(frames_directory, "frame_%05d.png")
    print("-------------------------------------------------")
    print(f"extract_frames: Extracting frames at {frame_rate} FPS => {frames_directory}")

    # Start FFmpeg process
    process = subprocess.Popen(
        [
            "ffmpeg",
            "-i", processed_video_path,
            "-vf", f"fps={frame_rate}",
            "-pix_fmt", "rgba",
            "-start_number", "0",
            "-y",
            output_pattern,
        ],
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        text=True
    )

    # Regex pattern to extract frame count from FFmpeg logs
    frame_pattern = re.compile(r"frame=\s*\d+.*fps=.*")

    # Read FFmpeg output in real-time
    for line in iter(process.stderr.readline, ''):
        match = frame_pattern.search(line)
        if match:
            sys.stdout.write(f"\r{match.group(0)}")  # Overwrite the same line
            sys.stdout.flush()

    process.wait()  # Ensure FFmpeg completes

    print("\nFrame extraction complete.") 
    print("")


# ============================================================
#       FRAME CROPPING AND COLOR PROCESSING (MODIFIED)
# ============================================================
#
# In the original code each frame was simply center‐cropped to the
# target dimensions. That fails to remove letterboxing (or pillarboxing)
# – i.e. the black bars that pad a 4:3 image to 16:9.
#
# Below we add a helper function, remove_letterbox(), that uses a simple
# threshold method to detect and remove large black borders. Then we
# either center‐crop (if the remaining content is larger than the target)
# or resize to force the final output to be exactly target_width x target_height.
#

def remove_letterbox(img, threshold=10, min_crop_ratio=0.9):
    """
    Detects and removes letterbox (black borders) from 'img'.
    It converts the image to grayscale, thresholds it, and computes the bounding
    box of non‑black pixels. If that bounding box is significantly smaller than the
    full image (i.e. black bars are present), it crops to that region.
    """
    gray = img.convert("L")
    # Create a binary image: pixels brighter than threshold become white
    binary = gray.point(lambda p: 255 if p > threshold else 0)
    bbox = binary.getbbox()
    if bbox:
        crop_width = bbox[2] - bbox[0]
        crop_height = bbox[3] - bbox[1]
        # Only crop if the detected content is significantly smaller than the full image.
        if crop_width < img.width * min_crop_ratio or crop_height < img.height * min_crop_ratio:
            return img.crop(bbox)
    return img

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

def process_frames():
    """
    1) For each PNG frame, remove letterbox (i.e. black borders) if present,
       then adjust the image so that its final dimensions are exactly
       target_width x target_height (by center cropping or resizing).
    2) Convert to custom palette (in-place).
    3) Convert to .rgba2 (8bpp).
    """
    filenames = sorted([f for f in os.listdir(frames_directory) if f.endswith('.png')])
    total_frames = len(filenames)

    print("-------------------------------------------------")
    print(f"process_frames found {total_frames} frames to process.")

    for i, pngfile in enumerate(filenames, start=1):
        pngpath = os.path.join(frames_directory, pngfile)
        base = os.path.splitext(pngfile)[0]
        rgba2_path = os.path.join(frames_directory, base + ".rgba2")

        # --- 1) Load the frame ---
        img = Image.open(pngpath)

        # --- Remove letterbox (black borders) if present ---
        content_img = remove_letterbox(img)

        # --- Adjust image to target dimensions ---
        cw, ch = content_img.size
        if cw >= target_width and ch >= target_height:
            final_img = center_crop(content_img, target_width, target_height)
        else:
            # If the content is smaller than desired, upscale it
            final_img = content_img.resize((target_width, target_height), Image.LANCZOS)
        final_img.save(pngpath)  # Overwrite the PNG with the processed image

        # --- 2) Convert to your custom palette in-place ---
        au.convert_to_palette(
            pngpath,                  # src
            pngpath,                  # overwrite the same file
            palette_filepath,
            palette_conversion_method,
            transparent_rgb
        )

        # --- 3) Convert that palette-based PNG to RGBA2 (8bpp) => .rgba2 ---
        au.img_to_rgba2(pngpath, rgba2_path)

        print(f"Frame {i}/{total_frames} processed: {pngfile}", end='\r')

    print("\nAll frames processed to .rgba2.")
    print("")

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

    if do_extract_audio:
        extract_audio()

    if do_convert_audio:
        convert_audio()

    if do_extract_video:
        extract_video()

    if do_extract_frames:
        extract_frames()

    if do_process_frames:
        process_frames()

    if do_make_agm:
        make_agm(frames_directory, target_audio_path, target_agm_path, target_width, target_height, frame_rate, target_sample_rate, chunksize)

    if do_delete_frames:
        delete_frames()

    if do_delete_processed_files:
        delete_processed_files()

    if do_play_agm:
        play_agm(target_agm_path)

# ============================================================
#              EXAMPLE USAGE
# ============================================================
if __name__ == "__main__":
    # Example usage with your chosen directories:
    staging_directory   = "assets/video/staging"
    processed_directory = "assets/video/processed"
    frames_directory    = "assets/video/frames"
    target_directory    = "tgt/video"

    palette_filepath = 'assets/images/palettes/Agon64.gpl'
    transparent_rgb = (0, 0, 0, 0)
    palette_conversion_method = 'floyd'

    # For your *no-rounding* design example:
    target_width  = 512
    target_height = int(target_width / 2.35)  
    frame_rate    = 1
    bytes_per_sec = 60000
    target_sample_rate = 16000
    chunksize = bytes_per_sec // 60

    # youtube_url = "https://youtu.be/djV11Xbc914" # A Ha Take On Me
    # video_base_name = f'a_ha__Take_On_Me'

    youtube_url = "https://youtu.be/3yWrXPck6SI" # Star Wars Battle of Yavin
    video_base_name = f'Star_Wars__Battle_of_Yavin'

    # youtube_url = "https://youtu.be/evyyr24r1F8" # Battle of Hoth Part 1
    # video_base_name = f'Star_Wars__Battle_of_Hoth_Part_1'

    # youtube_url = "https://youtu.be/FtutLA63Cp8" # Bad Apple
    # video_base_name = f'Bad_Apple'

    # youtube_url = "https://youtu.be/sOnqjkJTMaA" # Michael Jackson Thriller

    # youtube_url = "https://youtu.be/6Q_jdg1gQms" # Top Gun Danger Zone
    # youtube_url = "https://youtu.be/oJguy6wSYyI" # Star Wars Opening Crawl
    
    video_target_name = f'{video_base_name}' #_{target_width}x{target_height}x{frame_rate}' # x{target_sample_rate}'
    staged_video_path = os.path.join(staging_directory, f"{video_base_name}.mp4")
    processed_video_path = os.path.join(processed_directory, f"{video_target_name}.mp4")
    staged_audio_path = os.path.join(staging_directory, f"{video_base_name}.wav")
    target_audio_path = os.path.join(target_directory, f"{video_target_name}.wav")
    target_agm_path = os.path.join(target_directory, f"{video_target_name}.agm")


    do_download_video = False
    do_extract_audio = False
    do_convert_audio = False
    do_compression   = False
    do_normalization = False
    do_extract_video = False
    do_extract_frames = False
    do_process_frames = False
    do_make_agm = False
    do_delete_frames = False
    do_delete_processed_files = False
    do_play_agm = False

# ============================================================
# # Download and extract audio group
#     do_download_video = True
#     do_extract_audio = True
#     do_compression   = True
#     do_normalization = True

# # Convert audio and extract video group
#     do_convert_audio = True
    do_extract_video = True
    do_extract_frames = True
    do_process_frames = True

# Make AGM group
    do_make_agm = True

# Clean up group
    # do_delete_frames = True
    # do_delete_processed_files = True

# Play AGM group
    do_play_agm = True

    do_all_the_things()

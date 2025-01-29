#!/usr/bin/env python3
import os
import subprocess
import glob
import math
import struct
import shutil
import json
from PIL import Image

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
    convert_to_wav,
    resample_wav,
    convert_to_unsigned_pcm_wav,
)
import agonutils as au

from play_agm import play_agm

# ============================================================
#              YOUTUBE DOWNLOADER
# ============================================================

def download_video():
    os.makedirs(staging_directory, exist_ok=True)

    # Define the output file path explicitly
    output_file = os.path.join(staging_directory, f"{video_base_name}.mp4")

    # Download command
    command = [
        "yt-dlp",
        "--restrict-filenames",  # Sanitize filenames
        "--format", "mp4",        # Ensure MP4 format
        "--output", output_file,  # Use fixed filename
        youtube_url,
    ]

    print(f"Downloading video: {youtube_url} -> {output_file}")
    subprocess.run(command, check=True)
    print("Download completed.")

# ============================================================
#              AUDIO EXTRACTION
# ============================================================
def extract_audio():
    """
    Extracts audio from a video file with minimal processing and saves it as MP3.
    """
    os.makedirs(processed_directory, exist_ok=True)

    command = [
        "ffmpeg",
        "-i", staged_video_path, # Input file
        "-vn",                    # Disable video
        "-c:a", "libmp3lame",     # Encode audio as MP3
        "-y",                     # Overwrite output files without asking
        staged_audio_path,
    ]

    print(f"Extracting audio to {staged_audio_path}")
    subprocess.run(command, check=True)
    print("Audio extraction completed.")

# ============================================================
#              AUDIO CONVERSION
# ============================================================
def convert_audio():
    """
    Converts an audio file (e.g. MP3) into 8-bit unsigned PCM `.wav`.
    Resamples to `sample_rate` if needed, optionally compresses & normalizes.
    """
    temp_path = os.path.join(staging_directory, "temp.wav")

    print(f"\nProcessing audio: {staged_audio_path}")
    if os.path.exists(temp_path):
        os.remove(temp_path)

    # 1) Get metadata
    source_rate, codec = get_audio_metadata(staged_audio_path)

    if sample_rate == -1:
        target_rate = source_rate
    else:
        target_rate = sample_rate

    # 2) Convert to WAV if not already .wav
    if not staged_audio_path.lower().endswith('.wav'):
        convert_to_wav(staged_audio_path, temp_path, codec)
        shutil.copy(temp_path, target_audio_path)
        os.remove(temp_path)
    else:
        shutil.copy(staged_audio_path, target_audio_path)

    # 3) Dynamic range compression (optional)
    if do_compression:
        shutil.copy(target_audio_path, temp_path)
        compress_dynamic_range(temp_path, target_audio_path, codec)
        os.remove(temp_path)

    # 4) Loudness normalization (optional)
    if do_normalization:
        shutil.copy(target_audio_path, temp_path)
        normalize_audio(temp_path, target_audio_path, codec)
        os.remove(temp_path)

    # 5) Resample if needed
    if source_rate != target_rate:
        shutil.copy(target_audio_path, temp_path)
        resample_wav(temp_path, target_audio_path, target_rate, codec)
        os.remove(temp_path)
    else:
        print("Skipping resampling: Source and target sample rates match.")

    # 6) Convert to 8-bit unsigned PCM
    shutil.copy(target_audio_path, temp_path)
    convert_to_unsigned_pcm_wav(temp_path, target_audio_path, target_rate)
    os.remove(temp_path)

    print(f"Finished audio processing: {target_audio_path}")

# ============================================================
#              VIDEO RESIZING & FRAME EXTRACTION
# ============================================================

def get_video_dimensions(input_file):
    """
    Returns (width, height) from ffprobe as integers.
    """
    cmd = [
        'ffprobe',
        '-v', 'error',
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
    w = streams[0].get('width')
    h = streams[0].get('height')
    return int(w), int(h)

def extract_video():
    """
    1) Probes the original video to find aspect ratio.
    2) If original is 'wider' than target, we fix the target height & let width auto-scale.
       If original is 'taller' (or narrower), we fix the target width & let height auto-scale.
    3) Outputs an MP4 in the 'processed_directory' that maintains original aspect,
       but ensures either height == target_height or width == target_width.
    """

    # -- Get original aspect --
    orig_w, orig_h = get_video_dimensions(staged_video_path)
    if orig_h == 0:
        raise ValueError("Original video height is 0?")
    orig_aspect = orig_w / orig_h
    target_aspect = target_width / target_height

    # -- Decide how to scale in FFmpeg --
    # We'll either fix the width or fix the height, letting the other dimension auto-scale.
    if orig_aspect > target_aspect:
        # Original is "wider" => fix height, auto width
        # (When aspect is bigger, we end up with something like scale=-2:target_height)
        scale_filter = f"scale=-2:{target_height}"
    else:
        # Original is "taller" or basically narrower => fix width, auto height
        scale_filter = f"scale={target_width}:-2"

    print(f"Resizing video while preserving aspect: {staged_video_path}")
    print(f"  Using filter: {scale_filter}")

    subprocess.run([
        "ffmpeg",
        "-i", staged_video_path,
        "-an",  # Disable audio
        "-vf", scale_filter,
        "-c:v", "libx264",
        "-crf", "28",
        "-preset", "fast",
        "-y",  # Overwrite output
        processed_video_path,
    ], check=True)

    print(f"Intermediate video saved to {processed_video_path}")

def extract_frames():
    """
    Extract frames from the intermediate MP4 at the desired FPS.
    Does NOT scale further, because it's already at intermediate aspect-corrected size.
    Saves PNG frames.
    """
    # Clear out old frames
    for f in glob.glob(f"{frames_directory}/*"):
        os.remove(f)

    output_pattern = os.path.join(frames_directory, "frame_%05d.png")
    print(f"Extracting frames at {frame_rate} FPS => {frames_directory}")

    subprocess.run([
        "ffmpeg",
        "-i", processed_video_path,
        "-vf", f"fps={frame_rate}",
        "-pix_fmt", "rgba",
        "-start_number", "0",
        "-y",
        output_pattern,
    ], check=True)
    print("Frame extraction complete.")

# ============================================================
#              FRAME CROPPING AND COLOR PROCESSING
# ============================================================

def crop_frames(img, final_width, final_height):
    """
    Center-crops 'img' to final_width x final_height.
    If the image is already the same size or smaller in either dimension,
    watch out for edge cases (we typically assume the image is at least as big).
    """
    width, height = img.size

    # If no crop needed, just return
    if width == final_width and height == final_height:
        return img

    left = (width - final_width) // 2
    top = (height - final_height) // 2
    right = left + final_width
    bottom = top + final_height

    return img.crop((left, top, right, bottom))

def process_frames():
    """
    1) For each PNG frame, do a center crop to exactly target_width x target_height.
    2) Convert to custom palette (in-place).
    3) Convert to .rgba2 (8bpp).
    """
    filenames = sorted([f for f in os.listdir(frames_directory) if f.endswith('.png')])
    total_frames = len(filenames)
    print(f"Found {total_frames} frames to process.")

    for i, pngfile in enumerate(filenames, start=1):
        pngpath = os.path.join(frames_directory, pngfile)
        base = os.path.splitext(pngfile)[0]
        rgba2_path = os.path.join(frames_directory, base + ".rgba2")

        # --- 1) Load the frame, center crop to final dimension ---
        img = Image.open(pngpath)
        cropped_img = crop_frames(img, target_width, target_height)
        cropped_img.save(pngpath)  # Overwrite the PNG with the cropped version

        # --- 2) Convert to your custom palette in-place ---
        au.convert_to_palette(
            pngpath,                  # src
            pngpath,                  # overwrite the same file
            palette_filepath,
            palette_conversion_method,
            transparent_rgb
        )

        # --- 3) Convert that palette-based PNG to RGBA2 (8bpp) => .rgba2
        au.img_to_rgba2(pngpath, rgba2_path)

        print(f"Frame {i}/{total_frames} processed: {pngfile}", end='\r')

    print("\nAll frames processed to .rgba2.")

# ============================================================
#              AGM HEADER CONSTANTS
# ============================================================
AGM_HEADER_SIZE = 68
WAV_HEADER_SIZE = 76
TOTAL_HEADER_SIZE = AGM_HEADER_SIZE + WAV_HEADER_SIZE  # 144

# This format uses (example) offsets:
#   0..5:  magic "AGNMOV"
#   6:     version (1 byte)
#   7:     width   (1 byte)
#   8:     height  (1 byte)
#   9:     framerate (1 byte)
#   10..13: total_frames (4 bytes)
#   14..17: total_audio_seconds (4 bytes) -- integer or float
#   18..67: reserved (50 bytes)
# total = 68 bytes
agm_header_fmt = "<6sBBBBII50x"

# ============================================================
#          MERGE VIDEO & AUDIO INTO .AGM (60 slices/sec)
# ============================================================
def make_agm():
    """
    Creates an AGM file with:
      - 76-byte WAV header
      - 68-byte AGM header
      - 144 bytes total header
      - Then data arranged in 60 lumps per second,
        each lump is (video portion + audio portion).
      - 4 fps example => each second has 4 frames => each frame is
        split across lumps_per_frame lumps, etc.
    """
    # ---------------------------
    # 1) Read frames
    # ---------------------------
    frame_files = sorted(f for f in os.listdir(frames_directory) if f.endswith('.rgba2'))
    total_frames = len(frame_files)
    print(f"merge_video_audio_agm: Found {total_frames} frames in {frames_directory}")

    # Each frame is width*height bytes in .rgba2
    frame_bytes_per_frame = target_width * target_height

    # ---------------------------
    # 2) Read audio
    # ---------------------------
    with open(target_audio_path, "rb") as wf:
        wav_header = wf.read(WAV_HEADER_SIZE)  # 76 bytes
        # Modify the WAV format marker (12 byte offset) to "agm" in little-endian order
        wav_header = wav_header[:12] + b"agm" + wav_header[15:]
        audio_data = wf.read()                 # The rest is raw PCM data

    audio_data_size = len(audio_data)
    # Audio duration in seconds (assuming 8-bit mono => 1 byte/sample)
    # We'll do an integer second count. If it's not an exact match, you
    # can enforce “no rounding,” but let's be safe to do ceiling if mismatched.
    audio_secs_float = audio_data_size / float(sample_rate)
    # ---------------------------
    # 3) Compute total secs
    # video_secs = total_frames / frame_rate
    # audio_secs = audio_data_size / sample_rate
    video_secs_float = total_frames / float(frame_rate)

    total_secs = int(math.ceil(max(video_secs_float, audio_secs_float)))
    print(f"Video is ~{video_secs_float:.2f}s, Audio is ~{audio_secs_float:.2f}s => merging up to {total_secs}s total")

    # ---------------------------
    # 4) 60 lumps per second
    #    lumps_per_frame = 60 // frame_rate  (MUST be integer)
    # ---------------------------
    lumps_per_second = 60
    if (lumps_per_second % frame_rate) != 0:
        raise ValueError(
            f"Cannot evenly split {lumps_per_second} lumps among {frame_rate} fps. They must divide exactly."
        )

    lumps_per_frame = lumps_per_second // frame_rate
    # For example, 4 fps => lumps_per_frame=15

    # -- total lumps for the entire video
    total_lumps = total_secs * lumps_per_second

    # Each second we must store:
    #   frame_rate frames => frame_rate * frame_bytes_per_frame
    # + sample_rate bytes of audio
    # = total_bytes_per_sec
    total_video_bytes_per_sec = frame_rate * frame_bytes_per_frame
    total_audio_bytes_per_sec = sample_rate
    total_bytes_per_sec = total_video_bytes_per_sec + total_audio_bytes_per_sec

    # Each second is broken into lumps_per_second lumps => each lump is chunk_size
    # e.g. 60 lumps => chunk_size = total_bytes_per_sec / 60
    # Must be integer, no rounding
    if total_bytes_per_sec % lumps_per_second != 0:
        raise ValueError(
            f"Cannot split {total_bytes_per_sec} bytes/sec into {lumps_per_second} lumps. Must divide evenly!"
        )

    chunk_size = total_bytes_per_sec // lumps_per_second
    print(f" -> Each second = {total_bytes_per_sec} bytes, split into {lumps_per_second} lumps => chunk_size={chunk_size}")

    # In one frame, we have frame_bytes_per_frame bytes. That frame is spread across lumps_per_frame lumps => each lump has:
    #   frame_bytes_per_lump = frame_bytes_per_frame / lumps_per_frame
    if frame_bytes_per_frame % lumps_per_frame != 0:
        raise ValueError(
            f"Frame of {frame_bytes_per_frame} bytes won't split evenly into {lumps_per_frame} lumps_per_frame."
        )
    frame_bytes_per_lump = frame_bytes_per_frame // lumps_per_frame

    # Also, each second has sample_rate audio bytes => audio_bytes_per_lump = sample_rate / lumps_per_second
    if sample_rate % lumps_per_second != 0:
        raise ValueError(
            f"Audio sample_rate={sample_rate} doesn't split evenly into lumps_per_second={lumps_per_second}."
        )
    audio_bytes_per_lump = sample_rate // lumps_per_second

    print(f" -> Each frame is {frame_bytes_per_frame} bytes => {frame_bytes_per_lump} per lump")
    print(f" -> Audio is {sample_rate} bytes/sec => {audio_bytes_per_lump} per lump")

    # Summation check:
    #   chunk_size = frame_bytes_per_lump + audio_bytes_per_lump
    # must hold. If you want e.g. 720 + 280 = 1000, it should match:
    if (frame_bytes_per_lump + audio_bytes_per_lump) != chunk_size:
        raise ValueError("Mismatch: frame+audio lumps do not add up to chunk_size.")

    # ---------------------------
    # 5) Build 68-byte AGN header
    # ---------------------------
    # For your offsets:
    # 0..5: 'AGNMOV'
    # 6:    version=1
    # 7:    width (1 byte)
    # 8:    height (1 byte)
    # 9:    frame_rate (1 byte)
    # 10..13: total_frames
    # 14..17: total_audio_seconds (int)
    # 18..67: reserved
    version = 1
    agm_header = struct.pack(
        agm_header_fmt,
        b"AGNMOV",            # magic (6s)
        version,              # 1 byte
        target_width,                # 1 byte
        target_height,               # 1 byte
        frame_rate,           # 1 byte
        total_frames,         # 4 bytes
        total_secs,           # 4 bytes: store audio seconds as int
        # plus 50x reserved
    )

    # ---------------------------
    # 6) Write .agm file
    # ---------------------------
    print(f"Writing AGM to: {target_agm_path}")
    with open(target_agm_path, "wb") as agm_file:
        # (a) WAV header (76 bytes)
        if len(wav_header) != WAV_HEADER_SIZE:
            raise ValueError("WAV header is not 76 bytes as expected.")
        agm_file.write(wav_header)
        # (b) AGN header (68 bytes)
        agm_file.write(agm_header)

        # (c) Interleave data in lumps (60 lumps/sec)
        frame_idx = 0
        audio_idx = 0
        # We will read .rgba2 for each frame from disk as we go.

        # To remain consistent, we can proceed second by second:
        for sec in range(total_secs):
            for fr in range(frame_rate):
                # If we have run out of actual frames, we will use blank frames
                if frame_idx < total_frames:
                    frame_path = os.path.join(frames_directory, frame_files[frame_idx])
                    with open(frame_path, "rb") as f_in:
                        frame_bytes = f_in.read()
                    if len(frame_bytes) != frame_bytes_per_frame:
                        raise ValueError(f"Frame {frame_idx} has unexpected size {len(frame_bytes)}")
                else:
                    # blank frame if no more frames
                    frame_bytes = b"\x00" * frame_bytes_per_frame

                frame_idx += 1

                # Now we slice this frame into lumps_per_frame lumps
                # Each lump includes:
                #   first frame_bytes_per_lump from our frame,
                #   plus audio_bytes_per_lump from the audio data
                offset_in_frame = 0
                for _lump in range(lumps_per_frame):
                    # 1) slice of video
                    video_chunk = frame_bytes[offset_in_frame : offset_in_frame + frame_bytes_per_lump]
                    offset_in_frame += frame_bytes_per_lump

                    # 2) slice of audio
                    start_audio = audio_idx
                    end_audio   = audio_idx + audio_bytes_per_lump
                    audio_chunk = audio_data[start_audio:end_audio]
                    audio_idx  += audio_bytes_per_lump

                    # If audio_chunk is short (past end), pad with zeros
                    if len(audio_chunk) < audio_bytes_per_lump:
                        audio_chunk += b"\x00" * (audio_bytes_per_lump - len(audio_chunk))

                    # 3) write them out as a single lump
                    agm_file.write(video_chunk)
                    agm_file.write(audio_chunk)

        print("AGM file creation complete.")

    # (Optional) Clean up frames if you like
    for file in glob.glob(os.path.join(frames_directory, "*.rgba2")) + glob.glob(os.path.join(frames_directory, "*.png")):
        os.remove(file)
    print("Deleted all .rgba2 files in the frames directory.")

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
        make_agm()

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
    target_width  = 240
    target_height = 96
    frame_rate    = 1
    bytes_per_sec = 60000
    sample_rate   = bytes_per_sec - (target_width * target_height * frame_rate)

    # youtube_url = "https://youtu.be/djV11Xbc914" # A Ha Take On Me
    # youtube_url = "https://youtu.be/FtutLA63Cp8" # Bad Apple
    # youtube_url = "https://youtu.be/sOnqjkJTMaA" # Michael Jackson Thriller
    youtube_url = "https://youtu.be/3yWrXPck6SI" # Star Wars Battle of Yavin
    # youtube_url = "https://youtu.be/6Q_jdg1gQms" # Top Gun Danger Zone
    # youtube_url = "https://youtu.be/oJguy6wSYyI" # Star Wars Opening Crawl
    # youtube_url = "https://youtu.be/evyyr24r1F8" # Battle of Hoth Part 1
    
    video_base_name = f'Star_Wars__Battle_of_Yavin'
    video_target_name = f'{video_base_name}_{target_width}x{target_height}x{frame_rate}x{sample_rate}'
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
    do_play_agm = False

# ============================================================
    # do_download_video = True

    # do_extract_audio = True
    
    do_convert_audio = True
    do_compression   = True
    do_normalization = True
    
    do_extract_video = True
    do_extract_frames = True
    do_process_frames = True
    
    do_make_agm = True
    do_delete_frames = True

    do_play_agm = True

    do_all_the_things()

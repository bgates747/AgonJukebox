#!/usr/bin/env python3
import os
import subprocess
import glob
import math
import struct
import shutil

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

# ============================================================
#              YOUTUBE DOWNLOADER
# ============================================================
def download_youtube_video(url, staging_directory):
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

# ============================================================
#              AUDIO EXTRACTION
# ============================================================
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
        "-vn",                    # Disable video
        "-c:a", "libmp3lame",     # Encode audio as MP3
        "-y",                     # Overwrite output files without asking
        output_file,
    ]

    print(f"Extracting audio to {output_file}")
    subprocess.run(command, check=True)
    print("Audio extraction completed.")
    return output_file  # Return the path of the extracted audio

# ============================================================
#              AUDIO CONVERSION
# ============================================================
def make_audio(src_path, tgt_dir, sample_rate, do_compression, do_normalization):
    """
    Converts an audio file (e.g. MP3) into 8-bit unsigned PCM `.wav`.
    Resamples to `sample_rate` if needed, optionally compresses & normalizes.
    """
    filename = os.path.basename(src_path)
    base_filename = os.path.splitext(filename)[0]
    tgt_path = os.path.join(tgt_dir, base_filename + '.wav')
    temp_path = os.path.join(tgt_dir, "temp.wav")

    print(f"\nProcessing audio: {src_path}")
    if os.path.exists(temp_path):
        os.remove(temp_path)

    # 1) Get metadata
    source_rate, codec = get_audio_metadata(src_path)

    if sample_rate == -1:
        target_rate = source_rate
    else:
        target_rate = sample_rate

    # 2) Convert to WAV if not already .wav
    if not filename.lower().endswith('.wav'):
        convert_to_wav(src_path, temp_path, codec)
        shutil.copy(temp_path, tgt_path)
        os.remove(temp_path)
    else:
        shutil.copy(src_path, tgt_path)

    # 3) Dynamic range compression (optional)
    if do_compression:
        shutil.copy(tgt_path, temp_path)
        compress_dynamic_range(temp_path, tgt_path, codec)
        os.remove(temp_path)

    # 4) Loudness normalization (optional)
    if do_normalization:
        shutil.copy(tgt_path, temp_path)
        normalize_audio(temp_path, tgt_path, codec)
        os.remove(temp_path)

    # 5) Resample if needed
    if source_rate != target_rate:
        shutil.copy(tgt_path, temp_path)
        resample_wav(temp_path, tgt_path, target_rate, codec)
        os.remove(temp_path)
    else:
        print("Skipping resampling: Source and target sample rates match.")

    # 6) Convert to 8-bit unsigned PCM
    shutil.copy(tgt_path, temp_path)
    convert_to_unsigned_pcm_wav(temp_path, tgt_path, target_rate)
    os.remove(temp_path)

    print(f"Finished audio processing: {tgt_path}")
    return tgt_path  # Return the final .wav path

# ============================================================
#              VIDEO RESIZING & FRAME EXTRACTION
# ============================================================
def extract_and_resize_video(input_file, processed_directory, target_directory, target_width, target_height):
    """
    Resizes the video to the specified resolution, saving as MP4.
    """
    os.makedirs(processed_directory, exist_ok=True)
    os.makedirs(target_directory, exist_ok=True)

    base_name = os.path.splitext(os.path.basename(input_file))[0]
    resized_file = os.path.join(processed_directory, f"{base_name}.mp4")

    print(f"Resizing video to {target_width}x{target_height}: {input_file}")
    subprocess.run([
        "ffmpeg",
        "-i", input_file,
        "-an",                     # Disable audio
        "-vf", f"scale={target_width}:{target_height}",
        "-c:v", "libx264",
        "-crf", "28",
        "-preset", "fast",
        "-y",                     # Overwrite output files without asking
        resized_file,
    ], check=True)
    print(f"Video resized to {resized_file}")
    return resized_file

def extract_frames(input_file, frames_directory, target_width, target_height, frame_rate):
    """
    Extract frames from the resized MP4 at the desired FPS and resolution.
    Saves them as PNG.
    """
    os.makedirs(frames_directory, exist_ok=True)
    # Clear out old frames
    for f in glob.glob(f"{frames_directory}/*"):
        os.remove(f)

    output_pattern = os.path.join(frames_directory, "frame_%05d.png")
    print(f"Extracting frames at {frame_rate} FPS => {frames_directory}")
    subprocess.run([
        "ffmpeg",
        "-i", input_file,
        "-vf", f"fps={frame_rate},scale={target_width}:{target_height}",
        "-pix_fmt", "rgba",
        "-start_number", "0",
        "-y",                     # Overwrite output files without asking
        output_pattern,
    ], check=True)
    print("Frame extraction complete.")

# ============================================================
#              FRAME COLOR PROCESSING
# ============================================================
def process_frames(frames_directory, palette_filepath, transparent_rgb, palette_conversion_method):
    """
    Converts extracted PNG frames to a palette, then .rgba2 for final use.
    """
    filenames = sorted([f for f in os.listdir(frames_directory) if f.endswith('.png')])
    total_frames = len(filenames)
    print(f"Found {total_frames} frames to process.")
    for i, pngfile in enumerate(filenames, start=1):
        pngpath = os.path.join(frames_directory, pngfile)
        base = os.path.splitext(pngfile)[0]
        rgba2_path = os.path.join(frames_directory, base + ".rgba2")

        # 1) Convert to your custom palette in-place
        au.convert_to_palette(pngpath, pngpath, palette_filepath, palette_conversion_method, transparent_rgb)
        # 2) Then to RGBA2 (which is your 8bpp format) => .rgba2
        au.img_to_rgba2(pngpath, rgba2_path)

        print(f"Frame {i}/{total_frames} processed: {pngfile}", end='\r')
    print("All frames processed to .rgba2.")

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
def merge_video_audio_agm(
    rgba_directory,      # where .rgba2 frames live
    wav_path,            # path to final 8-bit PCM WAV
    output_path,         # output .agm
    width,
    height,
    frame_rate,
    sample_rate
):
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
    frame_files = sorted(f for f in os.listdir(rgba_directory) if f.endswith('.rgba2'))
    total_frames = len(frame_files)
    print(f"merge_video_audio_agm: Found {total_frames} frames in {rgba_directory}")

    # Each frame is width*height bytes in .rgba2
    frame_bytes_per_frame = width * height

    # ---------------------------
    # 2) Read audio
    # ---------------------------
    with open(wav_path, "rb") as wf:
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
        width,                # 1 byte
        height,               # 1 byte
        frame_rate,           # 1 byte
        total_frames,         # 4 bytes
        total_secs,           # 4 bytes: store audio seconds as int
        # plus 50x reserved
    )

    # ---------------------------
    # 6) Write .agm file
    # ---------------------------
    print(f"Writing AGM to: {output_path}")
    with open(output_path, "wb") as agm_file:
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
                    frame_path = os.path.join(rgba_directory, frame_files[frame_idx])
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
    for file in glob.glob(os.path.join(rgba_directory, "*.rgba2")) + glob.glob(os.path.join(rgba_directory, "*.png")):
        os.remove(file)
    print("Deleted all .rgba2 files in the frames directory.")


# ============================================================
#          MAIN PIPELINE: PROCESS ALL VIDEOS
# ============================================================
def process_all_videos(
    staging_directory,
    processed_directory,
    frames_directory,
    target_directory,
    target_width,
    target_height,
    frame_rate,
    palette_filepath,
    transparent_rgb,
    palette_conversion_method,
    sample_rate,
    do_compression,
    do_normalization
):
    """
    1) For each .mp4 in staging, extract audio -> MP3 -> 8-bit WAV, extract frames -> .rgba2,
    2) Merge to .agm with your 60-lumps-per-second logic.
    """
    video_files = glob.glob(os.path.join(staging_directory, "*.mp4"))
    if not video_files:
        print("No MP4 video files found in staging.")
        return

    os.makedirs(target_directory, exist_ok=True)

    for video_file in video_files:
        print(f"\n=== PROCESSING: {video_file} ===")
        base_filename = os.path.splitext(os.path.basename(video_file))[0]

        # Step A: Extract audio, convert to 8-bit PCM
        audio_mp3 = extract_audio_from_video(video_file, processed_directory)
        final_wav = make_audio(audio_mp3, target_directory, sample_rate, do_compression, do_normalization)

        # Step B: Resize video => extract frames => palette => .rgba2
        resized_video = extract_and_resize_video(video_file, processed_directory, target_directory, target_width, target_height)
        extract_frames(resized_video, frames_directory, target_width, target_height, frame_rate)
        process_frames(frames_directory, palette_filepath, transparent_rgb, palette_conversion_method)

        # Step C: Merge
        agm_out = os.path.join(target_directory, f"{base_filename}.agm")
        merge_video_audio_agm(
            rgba_directory=frames_directory,
            wav_path=final_wav,
            output_path=agm_out,
            width=target_width,
            height=target_height,
            frame_rate=frame_rate,
            sample_rate=sample_rate
        )
        print(f"Done creating: {agm_out}")


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
    target_width  = 120
    target_height = 90
    frame_rate    = 4
    sample_rate   = 16800

    do_compression   = True
    do_normalization = True

    # 1) Download from YouTube
    # youtube_url = "https://youtu.be/djV11Xbc914" # A Ha Take On Me
    # youtube_url = "https://youtu.be/FtutLA63Cp8" # Bad Apple
    # youtube_url = "https://youtu.be/sOnqjkJTMaA" # Michael Jackson Thriller
    # download_youtube_video(youtube_url, staging_directory)

    # 2) Process the downloaded videos => .agm
    process_all_videos(
        staging_directory,
        processed_directory,
        frames_directory,
        target_directory,
        target_width,
        target_height,
        frame_rate,
        palette_filepath,
        transparent_rgb,
        palette_conversion_method,
        sample_rate,
        do_compression,
        do_normalization
    )
    print("All done!")

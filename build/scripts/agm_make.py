#!/usr/bin/env python3
import os
import struct
import subprocess
import tempfile
import math
from io import BytesIO
import re
import glob
import shutil
import sys
from PIL import Image
from make_wav import (
    compress_dynamic_range,
    normalize_audio,
    get_audio_metadata,
    resample_wav,
    convert_to_unsigned_pcm_wav,
)
import agonutils as au

# ------------------- Unit Header Mask Definitions -------------------
AGM_UNIT_TYPE       = 0b10000000  # Bit 7: 1 = video; 0 = audio
AGM_UNIT_GCOL       = 0b00000111  # Bits 0-2: GCOL plotting mode (set to 0 here)
AGM_UNIT_CMP_RAW    = 0b00000000  # No compression
AGM_UNIT_CMP_SZIP   = 0b00001000  # SZIP compression
AGM_UNIT_CMP_TVC    = 0b00010000  # TVC TurboVega Compression 
AGM_UNIT_CMP_SRLE2  = 0b00011000  # SRLE2 compression (RLE2 + SZIP)

# --------------------------------------------------------------------

def create_temp_file():
    """Create a temporary file and return its path."""
    temp_file = tempfile.NamedTemporaryFile(delete=False)
    temp_file.close()
    return temp_file.name

def remove_temp_files(*file_paths):
    """Remove temporary files if they exist."""
    for file_path in file_paths:
        if os.path.exists(file_path):
            os.remove(file_path)

def compress_with_tvc(input_path, output_path):
    """Compress a file using tvc."""
    subprocess.run(
        ["tvc", "-c", input_path, output_path],
        stdout=subprocess.DEVNULL,
        stderr=subprocess.DEVNULL,
        check=True
    )

def compress_with_rle2(input_path, output_path):
    """Compress a file using rle2."""
    subprocess.run(
        ["rle2", "-c", input_path, output_path],
        stdout=subprocess.DEVNULL,
        stderr=subprocess.DEVNULL,
        check=True
    )

def compress_with_szip(input_path, output_path):
    """Compress a file using szip."""
    subprocess.run(
        ["szip", "-b41o3", input_path, output_path],
        stdout=subprocess.DEVNULL,
        stderr=subprocess.DEVNULL,
        check=True
    )

def compress_frame_data(frame_bytes, frame_idx, total_frames, compression_type):
    """
    Compress the raw frame data using the specified compression type.

    Parameters:
      frame_bytes (bytes): The raw frame data.
      frame_idx (int): Index of the frame (for status printing).
      total_frames (int): Total number of frames (for status printing).
      compression_type (str): "tvc", "srle2" (rle2 + szip), "szip", or "raw" (no compression).

    Returns:
      bytes: The compressed frame data.
    """
    # Create a temporary file for the raw data.
    temp_raw_path = create_temp_file()
    try:
        with open(temp_raw_path, "wb") as temp_raw:
            temp_raw.write(frame_bytes)

        # Handle "raw" case (no compression)
        if compression_type == "raw":
            with open(temp_raw_path, "rb") as f_in:
                return f_in.read()

        # Create output file path for the final compressed data.
        temp_compressed_path = create_temp_file()

        if compression_type == "tvc":
            compress_with_tvc(temp_raw_path, temp_compressed_path)
        elif compression_type == "szip":
            compress_with_szip(temp_raw_path, temp_compressed_path)
        elif compression_type == "srle2":  # Apply rle2 followed by szip
            temp_rle2_path = create_temp_file()
            compress_with_rle2(temp_raw_path, temp_rle2_path)
            compress_with_szip(temp_rle2_path, temp_compressed_path)
            remove_temp_files(temp_rle2_path)  # Cleanup intermediate file
        else:
            raise ValueError(f"Unknown compression type: {compression_type}")

        compressed_size = os.path.getsize(temp_compressed_path)
        original_size = len(frame_bytes)
        compression_ratio = 100.0 * compressed_size / original_size if original_size > 0 else 0.0

        print(
            f"\r\033[K{compression_type}ped frame {frame_idx + 1} of {total_frames}: "
            f"{original_size} bytes -> {compressed_size} bytes, "
            f"{compression_ratio:.1f}%",
            end="",
            flush=True
        )

        with open(temp_compressed_path, "rb") as f_in:
            compressed_bytes = f_in.read()
    
    finally:
        # Cleanup all temporary files.
        remove_temp_files(temp_raw_path, temp_compressed_path)

    return compressed_bytes

def make_agm(
    frames_file,
    target_audio_path,
    target_agm_path,
    target_width,
    target_height,
    frame_rate,
    target_sample_rate,
    chunksize,
    compression_type
):
    """
    Creates an AGM file with the specified compression type.

    Structure:
      - 76-byte WAV header (with 'agm' marker at offset 12..14).
      - 68-byte AGM header.
      - For each 1-second segment:
          - 8-byte segment header (previous segment size, current segment size).
          - For each frame in the segment: a video unit consisting of a 1-byte mask
            and the compressed frame data (written in chunks).
          - One audio unit: a 1-byte mask followed by the audio data for that second (written in chunks).
    """
    WAV_HEADER_SIZE = 76
    AGM_HEADER_SIZE = 68
    agm_header_fmt = "<6sBHHBII48x"

    AUDIO_MASK = 0x00  # Audio unit mask (bit7=0)

    # Determine the correct compression mask for video units.
    if compression_type == "tvc":
        compression_mask = AGM_UNIT_CMP_TVC
    elif compression_type == "srle2":
        compression_mask = AGM_UNIT_CMP_SRLE2
    elif compression_type == "szip":
        compression_mask = AGM_UNIT_CMP_SZIP
    elif compression_type == "raw":
        compression_mask = AGM_UNIT_CMP_RAW
    else:
        raise ValueError(f"Unknown compression type: {compression_type}")

    # Note: The video unit header must always have the video type bit set.
    video_mask = AGM_UNIT_TYPE | compression_mask

    # 1) Load frames.
    if not os.path.exists(frames_file):
        raise RuntimeError(f"Frames file not found: {frames_file}")
    with open(frames_file, "rb") as f:
        frames_data = f.read()
    frame_size = target_width * target_height
    total_frames = len(frames_data) // frame_size
    print("-------------------------------------------------")
    print(f"make_agm: Found {total_frames} frames in {frames_file}")

    # 2) Read and fix audio header.
    with open(target_audio_path, "rb") as wf:
        wav_header = wf.read(WAV_HEADER_SIZE)
        # Insert "agm" marker at offset 12..14.
        wav_header = wav_header[:12] + b"agm" + wav_header[15:]
        audio_data = wf.read()

    audio_data_size = len(audio_data)
    audio_secs_float = audio_data_size / float(target_sample_rate)

    # 3) Determine overall duration.
    video_secs_float = total_frames / float(frame_rate)
    total_secs = int(math.ceil(max(video_secs_float, audio_secs_float)))
    print(
        f"Video ~{video_secs_float:.2f}s, Audio ~{audio_secs_float:.2f}s => "
        f"Merging {total_frames} frames total."
    )

    # 4) Create AGM header.
    version = 1
    agm_header = struct.pack(
        agm_header_fmt,
        b"AGNMOV",      # Magic
        version,        # Version
        target_width,   # Width
        target_height,  # Height
        frame_rate,     # Frame rate
        total_frames,   # Total frames
        total_secs      # Total seconds
    )

    # Prepare output paths.
    target_agm_dir = os.path.dirname(target_agm_path)
    target_agm_basename = os.path.basename(target_agm_path).split(".")[0]
    target_agm_path = os.path.join(target_agm_dir, f"{target_agm_basename}.agm")
    csv_filename = os.path.join(target_agm_dir, f"{target_agm_basename}.agm_{frame_rate:03d}.csv")
    
    print(f"Writing AGM to: {target_agm_path}")
    print(f"Writing CSV data to: {csv_filename}")

    aggregated_video_bytes = [0] * total_secs
    samples_per_sec = target_sample_rate
    frames_per_segment = frame_rate

    segment_size_last = 0
    frame_index = 0

    # 5) Write AGM file and CSV report.
    with open(target_agm_path, "wb") as agm_file, open(csv_filename, "w") as csv_file:
        csv_file.write("frame_size,frame_rate,audio_rate\n")
        csv_file.write(f"{target_width * target_height},{frame_rate},{target_sample_rate}\n")
        csv_file.write("time_sec,compressed_video_bytes\n")

        # Write WAV and AGM headers.
        agm_file.write(wav_header)
        agm_file.write(agm_header)

        for segment_idx in range(total_secs):
            seg_buffer = BytesIO()

            # ---------------- VIDEO UNITS (multiple per segment) ----------------
            for i in range(frames_per_segment):
                if frame_index >= total_frames:
                    break

                start = frame_index * frame_size
                end = start + frame_size
                frame_bytes = frames_data[start:end]

                # Write video unit header (must be video unit; bit 7 set)
                seg_buffer.write(struct.pack("<B", video_mask))

                # Compress the frame using the chosen method.
                compressed_frame_bytes = compress_frame_data(
                    frame_bytes, frame_index, total_frames, compression_type
                )

                # Write the compressed video data in chunks.
                off = 0
                while off < len(compressed_frame_bytes):
                    chunk = compressed_frame_bytes[off: off + chunksize]
                    off += len(chunk)
                    seg_buffer.write(struct.pack("<I", len(chunk)))
                    seg_buffer.write(chunk)
                # Terminate the video unit.
                seg_buffer.write(struct.pack("<I", 0))

                aggregated_video_bytes[segment_idx] += len(compressed_frame_bytes)
                frame_index += 1

            # ---------------- AUDIO UNIT (once per segment) ----------------
            seg_buffer.write(struct.pack("<B", AUDIO_MASK))
            start_aud = segment_idx * samples_per_sec
            end_aud = start_aud + samples_per_sec
            unit_audio = audio_data[start_aud:end_aud]
            if len(unit_audio) < samples_per_sec:
                unit_audio += b"\x00" * (samples_per_sec - len(unit_audio))
            offset = 0
            while offset < len(unit_audio):
                chunk = unit_audio[offset: offset + chunksize]
                offset += len(chunk)
                seg_buffer.write(struct.pack("<I", len(chunk)))
                seg_buffer.write(chunk)
            seg_buffer.write(struct.pack("<I", 0))

            # ---------------- SEGMENT HEADER ----------------
            segment_data = seg_buffer.getvalue()
            segment_size_this = len(segment_data) + 8  # Include 8-byte header
            agm_file.write(struct.pack("<II", segment_size_last, segment_size_this))
            agm_file.write(segment_data)
            segment_size_last = segment_size_this

        # Write CSV rows aggregated by second.
        for sec in range(total_secs):
            csv_file.write(f"{sec},{aggregated_video_bytes[sec]}\n")

    print("AGM file creation complete.\n")
    print(f"CSV data written to: {csv_filename}")


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

    print(f"Audio download completed. Sample rate capped at {audio_sample_rate}Hz Size: {file_size_mb}")
    print("")

def preprocess_audio(staged_audio_path):
    # Define codec as 16-bit PCM little-endian signed.
    codec = "pcm_s16le"
    temp_path = os.path.join(staging_directory, "temp.wav")
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
# 1. Process Frames
# -------------------------------------------------------------------

def extract_and_process_frames(staged_video_path, seek_time, duration, frame_rate):
    """
    Extract frames from the video (using ffmpeg) and process each frame:
      - Optionally remove letterboxing.
      - Resize to target dimensions.
      - Convert to the custom palette.
      - Convert to RGBA2 format.
    The resulting RGBA2 data from all frames is concatenated into a single .frames file 
    in staging_directory. The naming convention follows the target_agm_path (using 
    video_base_name and palette_conversion_method) but placed in staging_directory.
    
    Intermediate .png files are created temporarily and then deleted.
    """
    # Clear out any existing files in the frames_directory.
    for f in glob.glob(os.path.join(frames_directory, "*")):
        os.remove(f)
    
    # Extract frames as PNG images in frames_directory.
    output_pattern = os.path.join(frames_directory, "frame_%05d.png")
    print("-------------------------------------------------")
    print(f"Extracting frames at {frame_rate} FPS to temporary folder: {frames_directory}")
    
    process = subprocess.Popen(
        [
            "ffmpeg",
            "-ss", seek_time,
            "-i", staged_video_path,
            "-t", str(duration),

            "-vf", f"fps={frame_rate}",
            # "-vf", f"tblend=all_mode=lighten,tmix=frames=3:weights='1 2 1',fps={frame_rate}",
            # "-vf", f"tblend=all_mode=lighten,tmix=frames=2:weights='1 1',fps={frame_rate}",
            # "-vf", f"mpdecimate,removegrain=4,tmedian=3,fps={frame_rate}",
            
            "-pix_fmt", "rgba",
            "-start_number", "0",
            "-y",  # Overwrite without prompting
            output_pattern,
        ],
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        text=True
    )

    # Optional: Show progress from ffmpeg stderr.
    frame_pattern = re.compile(r"frame=\s*\d+")
    for line in iter(process.stderr.readline, ''):
        match = frame_pattern.search(line)
        if match:
            sys.stdout.write(f"\r{match.group(0)}")
            sys.stdout.flush()
    process.wait()
    print("\nFrame extraction complete.\n")
    
    # Prepare output .frames file in staging_directory.
    output_frames_path = os.path.join(staging_directory, f"{video_base_name}_{palette_conversion_method}.frames")
    filenames = sorted([f for f in os.listdir(frames_directory) if f.endswith('.png')])
    total_frames = len(filenames)
    
    with open(output_frames_path, "wb") as out_file:
        print(f"Processing {total_frames} frames and writing to {output_frames_path}")
        for i, pngfile in enumerate(filenames, start=1):
            pngpath = os.path.join(frames_directory, pngfile)
            # Load the extracted frame.
            content_img = Image.open(pngpath)
            
            # Remove letterbox if enabled.
            if do_remove_letterbox:
                content_img = remove_letterbox(content_img)
            
            # Resize directly to the target dimensions.
            final_img = content_img.resize((target_width, target_height), Image.LANCZOS)
            
            # Save the processed image to a temporary .png file.
            temp_png_path = os.path.join(staging_directory, "temp_frame.png")
            final_img.save(temp_png_path)
            
            # Convert the temporary PNG to the custom palette.
            au.convert_to_palette(
                temp_png_path,      # src
                temp_png_path,      # output (overwrite)
                palette_filepath,
                palette_conversion_method,
                transparent_rgb
            )
            
            # Convert the palette-based PNG to a temporary .rgba2 file.
            temp_rgba2_path = os.path.join(staging_directory, "temp_frame.rgba2")
            au.img_to_rgba2(temp_png_path, temp_rgba2_path, palette_filepath, palette_conversion_method, transparent_rgb)
            
            # Read the RGBA2 data and append it to the output file.
            with open(temp_rgba2_path, "rb") as f_rgba2:
                rgba2_data = f_rgba2.read()
            out_file.write(rgba2_data)
            
            # Update message on a single line without linefeeds.
            print(f"\r\033[KFrame {i}/{total_frames} processed: {pngfile}", end="", flush=True)            
            # Clean up temporary files.
            os.remove(temp_png_path)
            os.remove(temp_rgba2_path)
            os.remove(pngpath)
    
    print(f"\nAll frames processed and combined into {output_frames_path}.")


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

if __name__ == "__main__":
    staging_directory   = "/home/smith/Agon/mystuff/assets/video/staging"
    frames_directory    = "/home/smith/Agon/mystuff/assets/video/frames"
    target_directory    = "tgt/video"
    palette_filepath = '/home/smith/Agon/mystuff/assets/images/palettes/Agon64.gpl'
    transparent_rgb = (0, 0, 0, 0)
    bytes_per_sec = 57600  # 60*960
    target_sample_rate = 15360  # 16*960 
    chunksize = bytes_per_sec // 60

    youtube_url = "https://youtu.be/3yWrXPck6SI"
    video_base_name = f'Star_Wars__Battle_of_Yavin'
    seek_time = "00:00:00"
    do_remove_letterbox = True
    
    duration  = 60 * 99
    frame_rate    = 10

    palette_conversion_method = 'bayer'
    compression_type = 'srle2'
    target_width  = 240

    # palette_conversion_method = 'bayer'
    # compression_type = 'tvc'
    # target_width  = 144

    target_height = int(target_width / 2.35)
    target_height = (target_height + 2) & ~2

    video_target_name = f'{video_base_name}'
    staged_video_path = os.path.join(staging_directory, f"{video_base_name}.mp4")
    staged_audio_path = os.path.join(staging_directory, f"{video_base_name}.wav")
    target_audio_path = os.path.join(target_directory, f"{video_target_name}.wav")
    target_agm_path = os.path.join(target_directory, f"{video_target_name}_{compression_type}_{palette_conversion_method}_{frame_rate:02d}_{target_width}.agm")
    output_frames_path = os.path.join(staging_directory, f"{video_base_name}_{palette_conversion_method}.frames")

    # download_video(staged_video_path)
    # download_audio(staged_audio_path, target_sample_rate)

    # preprocess_audio(staged_audio_path)
    convert_audio(staged_audio_path, target_audio_path)

    extract_and_process_frames(staged_video_path, seek_time, duration, frame_rate)

    make_agm(output_frames_path, target_audio_path, target_agm_path, target_width, target_height, frame_rate, target_sample_rate, chunksize, compression_type)
    
    # delete_frames()
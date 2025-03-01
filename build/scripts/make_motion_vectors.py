#!/usr/bin/env python3
import os
import sys
import subprocess
import tempfile
import json
import agonutils as au

def make_mp4():
    """
    Creates an MP4 video from the .frames file.
    Each frame is assumed to be stored as raw RGBA2 data.
    A GOP length is specified to force inter-frame prediction, ensuring motion vectors
    are generated.
    """
    # Each frame is assumed to be stored as raw RGBA2 data (8bpp)
    frame_size = target_width * target_height

    # Compute target MP4 file path by replacing .frames with .mp4
    if not frames_file_path.endswith(".frames"):
        print("Error: Input file must have a .frames extension.")
        sys.exit(1)
    target_mp4_path = frames_file_path.rsplit(".", 1)[0] + ".mp4"

    # Read the entire frames file
    try:
        with open(frames_file_path, "rb") as f:
            frames_data = f.read()
    except Exception as e:
        print(f"Error reading frames file: {e}")
        sys.exit(1)

    total_frames = len(frames_data) // frame_size
    print(f"Total frames found: {total_frames}")

    # Create a temporary directory for storing the intermediate PNG images
    with tempfile.TemporaryDirectory() as temp_dir:
        print(f"Using temporary directory: {temp_dir}")
        # Process each frame
        for i in range(total_frames):
            start = i * frame_size
            end = start + frame_size
            frame_bytes = frames_data[start:end]
            
            # Save the raw RGBA2 data to a temporary file
            temp_rgba2_path = os.path.join(temp_dir, "temp_frame.rgba2")
            with open(temp_rgba2_path, "wb") as temp_rgba2_file:
                temp_rgba2_file.write(frame_bytes)
            
            # Define output PNG filename for this frame (zero-padded)
            frame_png_filename = f"frame_{i:06d}.png"
            frame_png_path = os.path.join(temp_dir, frame_png_filename)
            
            # Convert the RGBA2 file to a PNG image using your conversion function
            au.rgba2_to_img(temp_rgba2_path, frame_png_path, target_width, target_height)
            
            print(f"Processed frame {i+1}/{total_frames}", end="\r")
        
        print("\nAll frames converted to PNG images.")
        
        # Use ffmpeg to create an MP4 video from the PNG image sequence.
        # Adding "-g 30" forces a GOP length of 30 frames (adjustable as needed)
        ffmpeg_cmd = [
            "ffmpeg",
            "-y",
            "-framerate", str(frame_rate),
            "-i", os.path.join(temp_dir, "frame_%06d.png"),
            "-c:v", "libx264",
            "-g", "30",
            "-pix_fmt", "yuv420p",
            target_mp4_path
        ]
        print("Running ffmpeg to create video...")
        subprocess.run(ffmpeg_cmd, check=True)
        print(f"Video created: {target_mp4_path}")

import os
import sys
import json
import subprocess

def extract_motion_vectors(frames_file_path):
    """
    Extracts all motion vectors from an MP4 video using ffprobe and saves them to a `.vectors` file.
    This function captures **all available motion vectors**, regardless of block size.
    
    The resulting `.vectors` file is saved in JSON format, containing:
    - **frame_index**: Frame number.
    - **motion_vectors**: List of motion vectors with full details.
    - **raw_side_data**: Full `side_data_list` for debugging.

    If `motion_vectors` are missing, this function **logs the full side_data_list** for debugging.
    """
    # Derive MP4 path and vectors file path.
    if not frames_file_path.endswith(".frames"):
        print("Error: Input file must have a .frames extension.")
        sys.exit(1)

    mp4_path = frames_file_path.rsplit(".", 1)[0] + ".mp4"
    vectors_path = frames_file_path.rsplit(".", 1)[0] + ".vectors"
    
    # Ensure the MP4 exists.
    if not os.path.exists(mp4_path):
        print(f"Error: MP4 file not found at '{mp4_path}'. Please generate it first.")
        sys.exit(1)

    # Run ffprobe with export_mvs enabled to extract motion vectors.
    ffprobe_cmd = [
        "ffprobe",
        "-flags2", "+export_mvs",
        "-select_streams", "v:0",
        "-show_frames",
        "-print_format", "json",
        mp4_path
    ]
    try:
        result = subprocess.run(ffprobe_cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE, check=True, text=True)
    except subprocess.CalledProcessError as e:
        print("Error running ffprobe:", e.stderr)
        sys.exit(1)

    try:
        probe_data = json.loads(result.stdout)
    except json.JSONDecodeError as e:
        print("Error parsing ffprobe output:", e)
        sys.exit(1)

    frames_out = []
    # Loop through each frame entry.
    for frame in probe_data.get("frames", []):
        frame_index = int(frame.get("coded_picture_number", -1))
        mvs = []
        raw_side_data = []  # Store the entire side_data_list for debugging

        # Extract all side_data_list entries
        for side in frame.get("side_data_list", []):
            raw_side_data.append(side)  # Save raw side-data for debugging
            
            if side.get("side_data_type") == "Motion vectors":
                for mv in side.get("motion_vectors", []):
                    # Capture **all** motion vector properties, without filtering by size.
                    mv_entry = {
                        "src_x": mv.get("src_x"),
                        "src_y": mv.get("src_y"),
                        "dst_x": mv.get("dst_x"),
                        "dst_y": mv.get("dst_y"),
                        "w": mv.get("w"),  # Width of the block
                        "h": mv.get("h"),  # Height of the block
                        "motion_x": mv.get("motion_x"),  # Motion vector X component
                        "motion_y": mv.get("motion_y"),  # Motion vector Y component
                        "flags": mv.get("flags")  # Flags (if available)
                    }
                    mvs.append(mv_entry)

        # Save frame data, including motion vectors and raw side data.
        frames_out.append({
            "frame_index": frame_index,
            "motion_vectors": mvs,
            "raw_side_data": raw_side_data  # Include full side-data list for debugging
        })

    # Write the collected motion vectors to a `.vectors` file (JSON format)
    try:
        with open(vectors_path, "w") as f_out:
            json.dump(frames_out, f_out, indent=2)
    except Exception as e:
        print("Error writing vectors file:", e)
        sys.exit(1)

    print(f"Motion vector data written to: {vectors_path}")


if __name__ == "__main__":
    # Input parameters
    frames_file_path = "/home/smith/Agon/mystuff/assets/video/staging/Star_Wars__Battle_of_Yavin_rgb.frames"
    frame_rate    = 10
    
    # Set target dimensions; both width and height are rounded up to the nearest multiple of 8.
    target_width  = 320
    target_height = int(target_width / 2.35)
    target_width  = (target_width  + 7) & ~7  # Round up to nearest multiple of 8
    target_height = (target_height + 7) & ~7  # Same for height

    make_mp4()
    extract_motion_vectors(frames_file_path)

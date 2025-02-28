import os
import struct
import subprocess
import tempfile
import math
from io import BytesIO

# ------------------- Unit Header Mask Definitions -------------------
# Bit definitions (using binary for clarity):
AGM_UNIT_TYPE       = 0b10000000  # Bit 7: 1 = video, 0 = audio
AGM_UNIT_GCOL       = 0b00000111  # Bits 0-2: GCOL plotting mode (set to 0 here)
AGM_UNIT_CMP_SRLE2  = 0b00011000  # Bits 3-4: srle2 compression (bits 3,4 set)

# Final video unit mask: video type OR TurboVega compression.
VIDEO_MASK = AGM_UNIT_TYPE | AGM_UNIT_CMP_SRLE2
# --------------------------------------------------------------------

def compress_frame_data(frame_bytes, frame_idx, total_frames):
    """
    Compress the raw frame data using an external compressor.
    
    Parameters:
      frame_bytes (bytes): The raw frame data.
      frame_idx (int): Index of the current frame (for status printing).
      total_frames (int): Total number of frames (for status printing).
      
    Returns:
      bytes: The compressed frame data.
    """
    # Create a temporary file for the raw frame.
    temp_raw = tempfile.NamedTemporaryFile(delete=False)
    try:
        temp_raw.write(frame_bytes)
        temp_raw.close()
        raw_path = temp_raw.name

        # Create temporary files for the intermediate and final outputs.
        temp_rle2 = tempfile.NamedTemporaryFile(delete=False)
        temp_rle2.close()
        temp_rle2_path = temp_rle2.name

        temp_srle2 = tempfile.NamedTemporaryFile(delete=False)
        temp_srle2.close()
        temp_srle2_path = temp_srle2.name

        # Run the compression commands.
        subprocess.run(["rle2", "-c", raw_path, temp_rle2_path], check=True)
        subprocess.run(["szip", "-b41o3", temp_rle2_path, temp_srle2_path], check=True)

        compressed_size = os.path.getsize(temp_srle2_path)
        original_size = len(frame_bytes)
        compression_ratio = 100.0 * compressed_size / original_size if original_size > 0 else 0.0

        print(
            f"\rsrle2ped frame {frame_idx + 1} of {total_frames}, "
            f"{original_size} bytes -> {compressed_size} bytes, "
            f"{compression_ratio:.1f}%",
            end="",
            flush=True
        )

        with open(temp_srle2_path, "rb") as f_in:
            compressed_bytes = f_in.read()

    finally:
        # Clean up temporary files.
        if os.path.exists(temp_raw.name):
            os.remove(temp_raw.name)
        if os.path.exists(temp_srle2_path):
            os.remove(temp_srle2_path)

    return compressed_bytes

def make_agm_srle2(
    frames_directory,
    target_audio_path,
    target_agm_path,
    target_width,
    target_height,
    frame_rate,
    target_sample_rate,
    chunksize,
    nth_frame=0  # New parameter: zero-based frame index to process.
):
    """
    Creates a simplified AGM file that contains:
      - A 76-byte WAV header with an 'agm' marker.
      - A 68-byte AGM header.
      - A single segment with a video unit containing one frame.
      
    Parameters:
      frames_directory (str): Directory containing .rgba2 frame files.
      target_audio_path (str): (Ignored in this simplified version.)
      target_agm_path (str): Path to write the output AGM file.
      target_width (int): Video frame width.
      target_height (int): Video frame height.
      frame_rate (int): Frame rate (stored in header; not used for multiple frames).
      target_sample_rate (int): (Ignored in this simplified version.)
      chunksize (int): Chunk size for video compression data.
      nth_frame (int): Zero-based index of the frame to process.
    """
    # Create a dummy 76-byte WAV header with "agm" inserted at offset 12.
    wav_header = b'\x00' * 12 + b"agm" + b'\x00' * (76 - 15)
    
    # AGM header format: "<6sBHHBII48x"
    agm_header_fmt = "<6sBHHBII48x"
    version = 1
    # For this simplified version, total_frames and total_secs are set to 1.
    agm_header = struct.pack(
        agm_header_fmt,
        b"AGNMOV",      # Magic (6 bytes)
        version,        # 1 byte version
        target_width,   # 16-bit unsigned width
        target_height,  # 16-bit unsigned height
        frame_rate,     # 1 byte (stored but not used for multiple frames)
        1,              # total_frames = 1
        1               # total_secs = 1
    )
    
    # Ensure the output file gets a .agm extension.
    target_agm_dir = os.path.dirname(target_agm_path)
    target_agm_basename = os.path.basename(target_agm_path).split(".")[0]
    target_agm_path = os.path.join(target_agm_dir, f"{target_agm_basename}.agm")
    print(f"Writing simplified AGM to: {target_agm_path}")
    
    with open(target_agm_path, "wb") as agm_file:
        # Write WAV header and AGM header.
        agm_file.write(wav_header)
        agm_file.write(agm_header)
        
        # Create a segment that contains a single video frame.
        seg_buffer = BytesIO()
        # Write the 1-byte video unit header mask.
        seg_buffer.write(struct.pack("<B", VIDEO_MASK))
        
        # Gather frame files.
        frame_files = sorted(f for f in os.listdir(frames_directory) if f.endswith(".rgba2"))
        if nth_frame < 0 or nth_frame >= len(frame_files):
            raise ValueError(f"nth_frame {nth_frame} is out of range. Found {len(frame_files)} frames.")
        
        frame_path = os.path.join(frames_directory, frame_files[nth_frame])
        with open(frame_path, "rb") as f_in:
            frame_bytes = f_in.read()
        
        # Compress the selected frame.
        compressed_frame_bytes = compress_frame_data(frame_bytes, nth_frame, 1)
        
        # Write the compressed frame data in chunks.
        off = 0
        while off < len(compressed_frame_bytes):
            chunk = compressed_frame_bytes[off : off + chunksize]
            off += len(chunk)
            seg_buffer.write(struct.pack("<I", len(chunk)))
            seg_buffer.write(chunk)
        
        # Write the end-of-video-unit marker.
        seg_buffer.write(struct.pack("<I", 0))
        
        segment_data = seg_buffer.getvalue()
        segment_size_this = len(segment_data)
        segment_size_last = 0  # Only one segment
        
        # Write an 8-byte segment header (previous segment size, current segment size) then the segment.
        agm_file.write(struct.pack("<II", segment_size_last, segment_size_this))
        agm_file.write(segment_data)
        
    print("AGM file creation complete.\n")

if __name__ == "__main__":
    # Set parameters for AGM creation.
    frames_directory = "/home/smith/Agon/mystuff/assets/video/frames/"
    target_audio_path = ""  # Ignored in this simplified version.
    target_agm_path = "/home/smith/Agon/mystuff/assets/video/output.agm"
    target_width = 320      # Example width.
    target_height = 200     # Example height.
    frame_rate = 1          # Only one frame is processed.
    target_sample_rate = 44100  # Ignored.
    chunksize = 1024        # Example chunk size.
    nth_frame = 0           # Zero-based index of the frame to process.
    
    make_agm_srle2(
        frames_directory,
        target_audio_path,
        target_agm_path,
        target_width,
        target_height,
        frame_rate,
        target_sample_rate,
        chunksize,
        nth_frame
    )

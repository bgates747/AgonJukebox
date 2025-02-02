#!/usr/bin/env python3
import os
import sys
import struct
import io
import numpy as np
import matplotlib.pyplot as plt

# -------------------------------------------------------------------
# Constants for header sizes
WAV_HEADER_SIZE = 76
AGM_HEADER_SIZE = 68
SEGMENT_HEADER_SIZE = 8  # Two 4-byte integers

# -------------------------------------------------------------------
# Helper: Parse WAV header to get audio sample rate.
def parse_wav_header(wav_header_bytes):
    if len(wav_header_bytes) < WAV_HEADER_SIZE:
        raise ValueError("WAV header too short.")
    # Check that bytes 12-14 contain the marker "agm"
    if wav_header_bytes[12:15] != b"agm":
        raise ValueError("WAV header does not contain 'agm' marker at offset 12..14.")
    # Sample rate is stored at offset 24-27 (little-endian)
    sample_rate = int.from_bytes(wav_header_bytes[24:28], byteorder='little', signed=False)
    return sample_rate

# -------------------------------------------------------------------
# Helper: Parse AGM header.
def parse_agm_header(agm_header_bytes):
    if len(agm_header_bytes) != AGM_HEADER_SIZE:
        raise ValueError(f"AGM header is {len(agm_header_bytes)} bytes; expected {AGM_HEADER_SIZE}.")
    # Format: 6s B H H B I I 48x  => magic (6 bytes), version (B),
    # width (H), height (H), frame_rate (B), total_frames (I), audio_secs (I), 48 bytes reserved.
    unpacked = struct.unpack("<6sBHHBII48x", agm_header_bytes)
    magic, version, width, height, frame_rate, total_frames, audio_secs = unpacked
    if magic != b"AGNMOV":
        raise ValueError("Invalid AGM magic.")
    return {
        "version": version,
        "width": width,
        "height": height,
        "frame_rate": frame_rate,
        "total_frames": total_frames,
        "audio_secs": audio_secs,
    }

# -------------------------------------------------------------------
# Read entire file into memory.
def read_agm_file(filepath):
    with open(filepath, "rb") as f:
        data = f.read()
    return data

# -------------------------------------------------------------------
# Extract per-segment data sizes from the AGM file.
def extract_segment_data(agm_data):
    """
    Iterates over the segments in the AGM file (each representing one second)
    and returns a list of dictionaries with keys:
       - 'audio_bytes': total audio data bytes in the segment
       - 'video_bytes': total video data bytes in the segment
    """
    segments = []
    offset = WAV_HEADER_SIZE + AGM_HEADER_SIZE
    data_len = len(agm_data)
    while offset + SEGMENT_HEADER_SIZE <= data_len:
        # Read 8-byte segment header.
        seg_header = agm_data[offset: offset + SEGMENT_HEADER_SIZE]
        offset += SEGMENT_HEADER_SIZE
        last_seg_size, this_seg_size = struct.unpack("<II", seg_header)
        if offset + this_seg_size > data_len:
            break
        seg_data = agm_data[offset: offset + this_seg_size]
        offset += this_seg_size

        seg_stream = io.BytesIO(seg_data)

        # --- Audio Unit ---
        # Read 1-byte unit mask (should indicate audio: bit7=0).
        seg_stream.read(1)
        audio_total = 0
        while True:
            chunk_size_data = seg_stream.read(4)
            if len(chunk_size_data) < 4:
                break
            chunk_size = struct.unpack("<I", chunk_size_data)[0]
            if chunk_size == 0:
                break
            audio_total += chunk_size
            seg_stream.read(chunk_size)  # Skip chunk data

        # --- Video Unit ---
        # Read 1-byte unit mask (should indicate video: bit7=1).
        seg_stream.read(1)
        video_total = 0
        while True:
            chunk_size_data = seg_stream.read(4)
            if len(chunk_size_data) < 4:
                break
            chunk_size = struct.unpack("<I", chunk_size_data)[0]
            if chunk_size == 0:
                break
            video_total += chunk_size
            seg_stream.read(chunk_size)
        segments.append({
            "audio_bytes": audio_total,
            "video_bytes": video_total
        })
    return segments

# -------------------------------------------------------------------
# Compute basic statistics (min, max, avg, std dev)
def compute_stats(values):
    arr = np.array(values)
    return {
        "min": float(np.min(arr)),
        "max": float(np.max(arr)),
        "avg": float(np.mean(arr)),
        "std": float(np.std(arr))
    }

# -------------------------------------------------------------------
# Main function: read AGM file, extract header info and segment stats, then plot.
def main():
    agm_filepath = "tgt/video/Star_Wars__Battle_of_Yavin_RGB_cmp.agm"
    if not os.path.exists(agm_filepath):
        print(f"File {agm_filepath} not found.")
        sys.exit(1)

    agm_data = read_agm_file(agm_filepath)

    # Extract headers.
    wav_header = agm_data[:WAV_HEADER_SIZE]
    agm_header = agm_data[WAV_HEADER_SIZE: WAV_HEADER_SIZE + AGM_HEADER_SIZE]

    audio_sample_rate = parse_wav_header(wav_header)
    header_info = parse_agm_header(agm_header)

    # Display header info.
    print("=== AGM Header Information ===")
    print(f"File: {agm_filepath}")
    print(f"Version: {header_info['version']}")
    print(f"Video dimensions: {header_info['width']} x {header_info['height']}")
    print(f"Frame rate: {header_info['frame_rate']} fps")
    print(f"Total frames: {header_info['total_frames']}")
    print(f"Audio duration: {header_info['audio_secs']} seconds")
    print(f"Audio sample rate: {audio_sample_rate} Hz")
    duration = header_info['audio_secs']  # AGM file duration in seconds.
    print(f"Duration: {duration} seconds")
    print("")

    # Extract per-segment audio/video data sizes.
    segments = extract_segment_data(agm_data)
    num_segments = len(segments)
    print(f"Total segments (seconds): {num_segments}")

    audio_bytes = [seg["audio_bytes"] for seg in segments]
    video_bytes = [seg["video_bytes"] for seg in segments]
    total_bytes = [a + v for a, v in zip(audio_bytes, video_bytes)]

    video_stats = compute_stats(video_bytes)
    print("\nVideo Data Statistics per Segment (bytes):")
    print(f"  Min: {video_stats['min']}")
    print(f"  Max: {video_stats['max']}")
    print(f"  Avg: {video_stats['avg']:.2f}")
    print(f"  Std Dev: {video_stats['std']:.2f}")
    print("")

    # Compute the maximum theoretical bytes per segment.
    # For audio: assume 1 byte per sample => audio_sample_rate bytes per second.
    # For video: assume uncompressed 8-bit per pixel, so width*height*frame_rate bytes per second.
    max_theoretical = audio_sample_rate + (header_info['width'] * header_info['height'] * header_info['frame_rate'])
    
    # Compute percentage values per segment.
    audio_pct = np.array(audio_bytes) / max_theoretical * 100
    video_pct = np.array(video_bytes) / max_theoretical * 100
    total_pct = audio_pct + video_pct  # Should be <= 100%

    segments_x = np.arange(1, num_segments + 1)

    # Plot stacked bar chart in percentages.
    fig, ax1 = plt.subplots(figsize=(10,6))
    # Plot audio and video percentages as stacked bars.
    bar1 = ax1.bar(segments_x, audio_pct, label="Audio (%)", color="skyblue")
    bar2 = ax1.bar(segments_x, video_pct, bottom=audio_pct, label="Video (%)", color="salmon")
    ax1.set_xlabel("Segment (seconds)")
    ax1.set_ylabel("Data per segment (% of theoretical max)")
    ax1.set_ylim(0, 100)
    ax1.set_title("AGM Compression: Data per Segment as % of Theoretical Maximum")

    # Create a second y-axis for absolute bytes.
    ax2 = ax1.twinx()
    # Map 100% on the left axis to max_theoretical bytes on the right.
    ax2.set_ylim(0, max_theoretical)
    ax2.set_ylabel("Data per segment (bytes)")
    # Adjust tick labels on the right to show corresponding percentage values.
    yticks = np.linspace(0, max_theoretical, 6)
    ax2.set_yticks(yticks)
    # Format the tick labels as integers.
    ax2.set_yticklabels([f"{int(y)}" for y in yticks])

    ax1.legend(loc="upper left")
    plt.tight_layout()
    plt.show()

if __name__ == '__main__':
    main()

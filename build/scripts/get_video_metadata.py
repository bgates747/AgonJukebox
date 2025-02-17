#!/usr/bin/env python3

import subprocess
import json
import sys

def get_video_metadata(video_path):
    """
    Uses ffprobe to get metadata of a video file and returns it as a dict.
    """
    # Build the ffprobe command to produce JSON output
    cmd = [
        'ffprobe',
        '-v', 'error',
        '-show_entries', 'format=duration:format_tags=*:stream=codec_type,codec_name,width,height',
        '-print_format', 'json',
        video_path
    ]

    # Run ffprobe and capture JSON output
    result = subprocess.run(cmd, capture_output=True, text=True)
    if result.returncode != 0:
        print(f"Error running ffprobe: {result.stderr}")
        sys.exit(result.returncode)

    # Parse JSON output
    metadata_json = result.stdout
    metadata = json.loads(metadata_json)

    return metadata

def pretty_print_metadata(metadata, video_path):
    """
    Nicely formats and prints metadata from ffprobe.
    """
    print(f"\nMetadata for file: {video_path}")
    print("=" * (len(video_path) + 18))

    # Print basic format info
    format_info = metadata.get('format', {})
    tags = format_info.get('tags', {})
    duration = format_info.get('duration', 'N/A')

    print(f"Duration: {duration} seconds")

    # Print format tags (title, artist, etc.) if present
    if tags:
        print("\nFormat Tags:")
        for key, value in tags.items():
            print(f"  {key}: {value}")

    # Print stream details
    streams = metadata.get('streams', [])
    if streams:
        print("\nStreams:")
        for i, stream in enumerate(streams, start=1):
            codec_type = stream.get('codec_type', 'unknown')
            codec_name = stream.get('codec_name', 'unknown')

            print(f"  Stream #{i}:")
            print(f"    Codec Type: {codec_type}")
            print(f"    Codec Name: {codec_name}")

            if codec_type == 'video':
                width = stream.get('width', 'N/A')
                height = stream.get('height', 'N/A')
                print(f"    Resolution: {width}x{height}")
    print()

def main():
    video_path = "/home/smith/Agon/mystuff/assets/video/staging/Star_Wars__Battle_of_Yavin.mp4"
    metadata = get_video_metadata(video_path)
    pretty_print_metadata(metadata, video_path)

if __name__ == "__main__":
    main()

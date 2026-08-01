#!/usr/bin/env python3
"""
Download audio from YouTube and convert it to an Agon-ready WAV.

Agon-ready WAV in this project means:
- RIFF/WAVE
- PCM, mono
- 8-bit unsigned samples (pcm_u8)

Pipeline:
1) Download best audio from URL via yt-dlp and extract WAV.
2) Optional trim.
3) Optional dynamic-range compression.
4) Optional loudness normalization (ffmpeg loudnorm).
5) Optional DC removal + peak normalization (soundfile/numpy).
6) Optional custom ffmpeg audio filter chain.
7) Optional resample (default: keep source sample rate).
8) Convert to 8-bit unsigned PCM WAV.
9) Rewrite WAVEFORMATEXTENSIBLE headers to plain PCM if needed.
"""

import argparse
import glob
import json
import os
import re
import shutil
import subprocess
import sys
import tempfile
from pathlib import Path

import numpy as np
import soundfile as sf


def run_cmd(cmd):
    subprocess.run(cmd, check=True)


def sanitize_base_name(name: str) -> str:
    safe = re.sub(r"[^a-zA-Z0-9._-]", "_", name).strip("._-")
    return safe or "audio"


def get_audio_metadata(file_path: str):
    result = subprocess.run(
        [
            "ffprobe",
            "-hide_banner",
            "-loglevel",
            "error",
            "-v",
            "error",
            "-select_streams",
            "a:0",
            "-show_entries",
            "stream=sample_rate,sample_fmt",
            "-of",
            "json",
            file_path,
        ],
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        text=True,
        check=True,
    )
    metadata = json.loads(result.stdout)
    sample_rate = int(metadata["streams"][0]["sample_rate"])
    sample_fmt = metadata["streams"][0]["sample_fmt"]
    codec_map = {
        "u8": "pcm_u8",
        "s16": "pcm_s16le",
        "s24": "pcm_s24le",
        "s32": "pcm_s32le",
        "flt": "pcm_f32le",
    }
    codec = codec_map.get(sample_fmt, "pcm_s16le")
    return sample_rate, sample_fmt, codec


def ffmpeg_audio_stage(src: str, dst: str, extra_args):
    run_cmd([
        "ffmpeg",
        "-hide_banner",
        "-loglevel",
        "error",
        "-y",
        "-i",
        src,
        *extra_args,
        dst,
    ])


def compress_dynamic_range(src: str, dst: str, codec: str):
    ffmpeg_audio_stage(
        src,
        dst,
        [
            "-ac",
            "1",
            "-af",
            "acompressor=threshold=-20dB:ratio=3:attack=5:release=50:makeup=2.5",
            "-acodec",
            codec,
        ],
    )


def loudness_normalize(src: str, dst: str, codec: str):
    ffmpeg_audio_stage(
        src,
        dst,
        [
            "-ac",
            "1",
            "-af",
            "loudnorm=I=-20:TP=-2:LRA=11",
            "-acodec",
            codec,
        ],
    )


def normalize_audio_peak_dc(src: str, dst: str):
    data, sr = sf.read(src, dtype="float32")
    if data.ndim > 1:
        data = data.mean(axis=1)

    data = data - np.mean(data)
    peak = np.max(np.abs(data))
    if peak > 0:
        data = data / peak

    sf.write(dst, data, sr, subtype="PCM_16")


def apply_custom_filter(src: str, dst: str, codec: str, filter_expr: str):
    ffmpeg_audio_stage(
        src,
        dst,
        ["-ac", "1", "-af", filter_expr, "-acodec", codec],
    )


def resample_wav(src: str, dst: str, sample_rate: int, codec: str):
    ffmpeg_audio_stage(
        src,
        dst,
        ["-ac", "1", "-ar", str(sample_rate), "-acodec", codec],
    )


def convert_to_unsigned_pcm_wav(src: str, dst: str, sample_rate: int):
    ffmpeg_audio_stage(
        src,
        dst,
        ["-ac", "1", "-ar", str(sample_rate), "-acodec", "pcm_u8"],
    )


def fix_wav_header_if_extensible(file_path: str):
    with open(file_path, "rb") as f:
        data = f.read()

    if len(data) < 44:
        return
    if data[0:4] != b"RIFF" or data[8:12] != b"WAVE":
        return
    if data[12:16] != b"fmt ":
        return

    fmt_chunk_size = int.from_bytes(data[16:20], byteorder="little")
    if fmt_chunk_size == 16:
        return

    extension_start = 20 + 16
    extension_end = 20 + fmt_chunk_size
    new_data = bytearray(data)
    new_data[20:22] = (1).to_bytes(2, byteorder="little")
    del new_data[extension_start:extension_end]
    new_data[16:20] = (16).to_bytes(4, byteorder="little")

    new_riff_size = len(new_data) - 8
    new_data[4:8] = new_riff_size.to_bytes(4, byteorder="little")

    with open(file_path, "wb") as f:
        f.write(new_data)


def download_audio_wav(youtube_url: str, work_dir: str) -> str:
    output_template = os.path.join(work_dir, "%(title)s.%(ext)s")
    cmd = [
        sys.executable,
        "-m",
        "yt_dlp",
        "--restrict-filenames",
        "--extract-audio",
        "--audio-format",
        "wav",
        "--audio-quality",
        "0",
        "--output",
        output_template,
        youtube_url,
    ]
    run_cmd(cmd)

    wav_files = sorted(glob.glob(os.path.join(work_dir, "*.wav")))
    if not wav_files:
        raise RuntimeError("yt-dlp did not produce a WAV file.")
    return max(wav_files, key=os.path.getmtime)


def trim_audio(src: str, dst: str, start: str, duration):
    cmd = [
        "ffmpeg",
        "-hide_banner",
        "-loglevel",
        "error",
        "-y",
        "-ss",
        start,
        "-i",
        src,
    ]
    if duration is not None:
        cmd.extend(["-t", str(duration)])
    cmd.append(dst)
    run_cmd(cmd)


def ensure_tools_available():
    missing = []
    for exe in ("ffmpeg", "ffprobe"):
        if shutil.which(exe) is None:
            missing.append(exe)
    if shutil.which("yt-dlp") is None:
        # Accept python -m yt_dlp path if installed module exists.
        try:
            subprocess.run(
                [sys.executable, "-m", "yt_dlp", "--version"],
                stdout=subprocess.DEVNULL,
                stderr=subprocess.DEVNULL,
                check=True,
            )
        except subprocess.CalledProcessError:
            missing.append("yt-dlp (or python module yt_dlp)")

    if missing:
        raise RuntimeError(f"Missing required tools: {', '.join(missing)}")


def stage_copy(src: str, dst: str):
    shutil.copy(src, dst)


def build_parser():
    parser = argparse.ArgumentParser(
        description="Download YouTube audio and generate an Agon-ready 8-bit PCM mono WAV."
    )
    parser.add_argument("url", help="YouTube URL")
    parser.add_argument(
        "-o",
        "--output",
        default="tgt/audio",
        help="Output .wav file or output directory (default: tgt/audio)",
    )
    parser.add_argument(
        "--sample-rate",
        type=int,
        default=-1,
        help="Target sample rate in Hz. Use -1 to keep source sample rate (default).",
    )
    parser.add_argument(
        "--trim-start",
        default="00:00:00",
        help="Trim start offset (ffmpeg time format, default: 00:00:00)",
    )
    parser.add_argument(
        "--trim-duration",
        type=float,
        default=None,
        help="Optional trim duration in seconds.",
    )
    parser.add_argument(
        "--compress",
        action=argparse.BooleanOptionalAction,
        default=False,
        help="Apply dynamic range compression (default: off).",
    )
    parser.add_argument(
        "--loudnorm",
        action=argparse.BooleanOptionalAction,
        default=False,
        help="Apply ffmpeg loudnorm filter (default: off).",
    )
    parser.add_argument(
        "--normalize",
        action=argparse.BooleanOptionalAction,
        default=True,
        help="Apply DC removal + peak normalization (default: on).",
    )
    parser.add_argument(
        "--extra-af",
        default="",
        help="Extra ffmpeg -af filter chain, for example 'highpass=f=80,lowpass=f=7000'.",
    )
    parser.add_argument(
        "--keep-temp",
        action="store_true",
        help="Keep temp working directory for inspection.",
    )
    return parser


def parse_args(argv=None):
    parser = build_parser()
    return parser.parse_args(argv)


def resolve_output_path(output_arg: str, input_wav_path: str) -> str:
    out = Path(output_arg)
    input_base = sanitize_base_name(Path(input_wav_path).stem) + ".wav"

    if out.suffix.lower() == ".wav":
        out.parent.mkdir(parents=True, exist_ok=True)
        return str(out)

    out.mkdir(parents=True, exist_ok=True)
    return str(out / input_base)


def main(args):
    ensure_tools_available()

    temp_dir = tempfile.mkdtemp(prefix="agon_wav_")

    try:
        print(f"Downloading audio from: {args.url}")
        downloaded_wav = download_audio_wav(args.url, temp_dir)
        print(f"Downloaded WAV: {downloaded_wav}")

        output_path = resolve_output_path(args.output, downloaded_wav)
        print(f"Final output: {output_path}")

        staged = os.path.join(temp_dir, "stage.wav")
        temp = os.path.join(temp_dir, "temp.wav")

        print("Trimming audio...")
        trim_audio(downloaded_wav, staged, args.trim_start, args.trim_duration)

        source_rate, sample_fmt, codec = get_audio_metadata(staged)
        target_rate = source_rate if args.sample_rate == -1 else args.sample_rate
        print(f"Source sample rate: {source_rate} Hz ({sample_fmt}), target: {target_rate} Hz")

        if args.compress:
            print("Applying dynamic range compression...")
            stage_copy(staged, temp)
            compress_dynamic_range(temp, staged, codec)

        if args.loudnorm:
            print("Applying loudness normalization...")
            stage_copy(staged, temp)
            loudness_normalize(temp, staged, codec)

        if args.normalize:
            print("Applying DC removal + peak normalization...")
            stage_copy(staged, temp)
            normalize_audio_peak_dc(temp, staged)

        if args.extra_af.strip():
            print(f"Applying extra ffmpeg filter chain: {args.extra_af}")
            stage_copy(staged, temp)
            apply_custom_filter(temp, staged, codec, args.extra_af)

        if source_rate != target_rate:
            print("Resampling...")
            stage_copy(staged, temp)
            resample_wav(temp, staged, target_rate, codec)
        else:
            print("Skipping resample (source and target rates match).")

        print("Converting to 8-bit unsigned PCM mono WAV...")
        stage_copy(staged, temp)
        convert_to_unsigned_pcm_wav(temp, output_path, target_rate)

        print("Fixing WAV header if needed...")
        fix_wav_header_if_extensible(output_path)

        final_rate, _, _ = get_audio_metadata(output_path)
        print("Done.")
        print(f"Agon-ready WAV written: {output_path}")
        print(f"Output sample rate: {final_rate} Hz")

    finally:
        if args.keep_temp:
            print(f"Temp files kept at: {temp_dir}")
        else:
            shutil.rmtree(temp_dir, ignore_errors=True)


if __name__ == "__main__":
    # IDE preset mode. When running from the editor with no CLI args,
    # this preset is used automatically.
    USE_IDE_PRESET_WHEN_NO_ARGS = True

    # Edit values below for a quick run without CLI arguments.
    IDE_PRESET = {
        "url": "https://youtu.be/yAQWs-aBy1E",
        "output": "tgt/audio",
        "sample_rate": -1,
        "trim_start": "00:00:00",
        "trim_duration": None,
        "compress": False,
        "loudnorm": False,
        "normalize": True,
        "extra_af": "",
        "keep_temp": False,
    }

    if len(sys.argv) > 1:
        args = parse_args()
    elif USE_IDE_PRESET_WHEN_NO_ARGS:
        args = argparse.Namespace(**IDE_PRESET)
    else:
        args = parse_args()

    main(args)

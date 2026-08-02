#!/usr/bin/env python3
"""Generate standard AgonJukebox-compatible WAV files."""

from __future__ import annotations

import argparse
import json
from pathlib import Path
import re
import shutil
import struct
import subprocess
import sys
import tempfile
from typing import BinaryIO
from urllib.parse import urlparse


MIN_SAMPLE_RATE = 1
MAX_SAMPLE_RATE = 65_535
PCM_SUBFORMAT_GUID = bytes.fromhex("0100000000001000800000aa00389b71")
SUPPORTED_INPUT_SUFFIXES = {
    ".aac",
    ".aiff",
    ".flac",
    ".m4a",
    ".mp3",
    ".ogg",
    ".opus",
    ".wav",
    ".wma",
}


class WavToolError(RuntimeError):
    """A user-facing conversion or validation failure."""


def run_command(command: list[str], *, cwd: Path | None = None) -> None:
    subprocess.run(command, cwd=cwd, check=True)


def validate_sample_rate(sample_rate: int) -> int:
    if not MIN_SAMPLE_RATE <= sample_rate <= MAX_SAMPLE_RATE:
        raise WavToolError(
            f"sample rate must be {MIN_SAMPLE_RATE}..{MAX_SAMPLE_RATE} Hz; "
            f"got {sample_rate}"
        )
    return sample_rate


def is_url(value: str) -> bool:
    parsed = urlparse(value)
    return parsed.scheme in {"http", "https"} and bool(parsed.netloc)


def sanitize_name(value: str) -> str:
    safe = re.sub(r"[^a-zA-Z0-9._-]", "_", value).strip("._-")
    return safe or "audio"


def require_native_tools(*, needs_downloader: bool) -> None:
    missing = [name for name in ("ffmpeg", "ffprobe") if shutil.which(name) is None]
    if needs_downloader:
        result = subprocess.run(
            [sys.executable, "-m", "yt_dlp", "--version"],
            stdout=subprocess.DEVNULL,
            stderr=subprocess.DEVNULL,
            check=False,
        )
        if result.returncode:
            missing.append("the yt-dlp Python module")
    if missing:
        raise WavToolError(f"missing required tool(s): {', '.join(missing)}")


def probe_sample_rate(source: Path) -> int:
    result = subprocess.run(
        [
            "ffprobe",
            "-v",
            "error",
            "-select_streams",
            "a:0",
            "-show_entries",
            "stream=sample_rate",
            "-of",
            "json",
            str(source),
        ],
        text=True,
        stdout=subprocess.PIPE,
        check=True,
    )
    payload = json.loads(result.stdout)
    streams = payload.get("streams", [])
    if not streams:
        raise WavToolError(f"no audio stream found in {source}")
    return int(streams[0]["sample_rate"])


def read_exact(stream: BinaryIO, size: int, description: str) -> bytes:
    payload = stream.read(size)
    if len(payload) != size:
        raise WavToolError(f"truncated {description}")
    return payload


def iter_riff_chunks(stream: BinaryIO, riff_end: int):
    offset = 12
    while offset < riff_end:
        if offset + 8 > riff_end:
            raise WavToolError("incomplete WAV chunk header")
        stream.seek(offset)
        header = read_exact(stream, 8, "WAV chunk header")
        chunk_id = header[:4]
        chunk_size = struct.unpack_from("<I", header, 4)[0]
        payload_start = offset + 8
        payload_end = payload_start + chunk_size
        padded_end = payload_end + (chunk_size & 1)
        if padded_end > riff_end:
            raise WavToolError(f"truncated {chunk_id!r} WAV chunk")
        yield chunk_id, chunk_size, payload_start
        offset = padded_end


def validate_agon_wav(path: Path) -> dict[str, int]:
    """Validate the standard-WAV subset consumed by AgonJukebox."""

    fmt_payload: bytes | None = None
    data_size: int | None = None
    payload_offset: int | None = None
    with path.open("rb") as stream:
        preamble = read_exact(stream, 12, "RIFF/WAVE preamble")
        if preamble[:4] != b"RIFF" or preamble[8:12] != b"WAVE":
            raise WavToolError(f"{path} is not RIFF/WAVE")
        riff_end = struct.unpack_from("<I", preamble, 4)[0] + 8
        if riff_end > path.stat().st_size:
            raise WavToolError(f"{path} has a truncated RIFF/WAVE container")

        for chunk_id, chunk_size, offset in iter_riff_chunks(stream, riff_end):
            if chunk_id == b"fmt ":
                if fmt_payload is not None:
                    raise WavToolError(f"{path} has more than one fmt chunk")
                if chunk_size < 16:
                    raise WavToolError(f"{path} has an incomplete fmt chunk")
                stream.seek(offset)
                fmt_payload = read_exact(
                    stream, min(chunk_size, 40), "fmt chunk payload"
                )
            elif chunk_id == b"data" and data_size is None:
                if fmt_payload is None:
                    raise WavToolError(f"{path} places data before fmt")
                data_size = chunk_size
                payload_offset = offset

    if fmt_payload is None or len(fmt_payload) < 16:
        raise WavToolError(f"{path} has no complete fmt chunk")
    if data_size is None or payload_offset is None:
        raise WavToolError(f"{path} has no data chunk")
    if data_size == 0:
        raise WavToolError(f"{path} has an empty data chunk")

    audio_format, channels, sample_rate, byte_rate, block_align, bit_depth = (
        struct.unpack_from("<HHIIHH", fmt_payload)
    )
    if audio_format == 0xFFFE:
        if len(fmt_payload) < 40:
            raise WavToolError(f"{path} has an incomplete extensible fmt chunk")
        extension_size, valid_bits = struct.unpack_from("<HH", fmt_payload, 16)
        if extension_size != 22 or valid_bits != 8:
            raise WavToolError(f"{path} has an unsupported extensible PCM format")
        if fmt_payload[24:40] != PCM_SUBFORMAT_GUID:
            raise WavToolError(f"{path} is not extensible PCM")
    elif audio_format != 1:
        raise WavToolError(f"{path} is not integer PCM")
    validate_sample_rate(sample_rate)
    if (channels, byte_rate, block_align, bit_depth) != (
        1,
        sample_rate,
        1,
        8,
    ):
        raise WavToolError(f"{path} is not 8-bit unsigned PCM mono")
    return {
        "sample_rate": sample_rate,
        "data_size": data_size,
        "payload_offset": payload_offset,
    }


def build_filter_chain(args: argparse.Namespace) -> str:
    filters: list[str] = []
    if args.compress:
        filters.append(
            "acompressor=threshold=-20dB:ratio=3:attack=5:release=50:makeup=2.5"
        )
    if args.normalize:
        filters.append("loudnorm=I=-20:TP=-2:LRA=11")
    if args.extra_af:
        filters.append(args.extra_af)
    return ",".join(filters)


def convert_track(
    source: Path,
    destination: Path,
    sample_rate: int,
    args: argparse.Namespace,
    work_dir: Path,
) -> None:
    intermediate = work_dir / f"ffmpeg_{sanitize_name(destination.stem)}.wav"
    command = [
        "ffmpeg",
        "-hide_banner",
        "-loglevel",
        "error",
        "-y",
        "-i",
        str(source),
    ]
    if args.trim_start != "00:00:00":
        command.extend(["-ss", args.trim_start])
    if args.trim_duration is not None:
        command.extend(["-t", str(args.trim_duration)])
    command.extend(["-map", "0:a:0", "-vn", "-sn", "-dn", "-ac", "1"])
    command.extend(["-ar", str(validate_sample_rate(sample_rate))])
    filter_chain = build_filter_chain(args)
    if filter_chain:
        command.extend(["-af", filter_chain])
    command.extend(["-c:a", "pcm_u8", str(intermediate)])
    run_command(command)
    validate_agon_wav(intermediate)
    destination.parent.mkdir(parents=True, exist_ok=True)
    intermediate.replace(destination)


def download_url(url: str, work_dir: Path) -> Path:
    template = work_dir / "download.%(ext)s"
    run_command(
        [
            sys.executable,
            "-m",
            "yt_dlp",
            "--no-playlist",
            "--restrict-filenames",
            "--format",
            "bestaudio/best",
            "--output",
            str(template),
            url,
        ]
    )
    candidates = sorted(work_dir.glob("download.*"))
    if not candidates:
        raise WavToolError("yt-dlp did not produce an audio file")
    return max(candidates, key=lambda item: item.stat().st_mtime_ns)


def expand_local_sources(values: list[str]) -> list[Path]:
    sources: list[Path] = []
    for value in values:
        path = Path(value).expanduser().resolve()
        if not path.exists():
            raise WavToolError(f"input does not exist: {path}")
        if path.is_dir():
            sources.extend(
                item
                for item in sorted(path.iterdir())
                if item.is_file() and item.suffix.lower() in SUPPORTED_INPUT_SUFFIXES
            )
        elif path.is_file():
            sources.append(path)
        else:
            raise WavToolError(f"unsupported input: {path}")
    if not sources:
        raise WavToolError("no supported audio files found")
    return sources


def output_path_for(source: Path, output: Path, *, multiple: bool) -> Path:
    if multiple or output.suffix.lower() != ".wav":
        output.mkdir(parents=True, exist_ok=True)
        return output / f"{sanitize_name(source.stem)}.wav"
    output.parent.mkdir(parents=True, exist_ok=True)
    return output


def make_album(
    sources: list[Path],
    destination: Path,
    sample_rate: int,
    args: argparse.Namespace,
    work_dir: Path,
) -> None:
    tracks_dir = work_dir / "album_tracks"
    tracks_dir.mkdir()
    converted: list[Path] = []
    for index, source in enumerate(sources):
        track = tracks_dir / f"track_{index:04d}.wav"
        convert_track(source, track, sample_rate, args, work_dir)
        converted.append(track)

    concat_file = work_dir / "album.ffconcat"
    concat_file.write_text(
        "ffconcat version 1.0\n"
        + "".join(f"file '{track.as_posix()}'\n" for track in converted),
        encoding="utf-8",
    )
    intermediate = work_dir / "album_ffmpeg.wav"
    run_command(
        [
            "ffmpeg",
            "-hide_banner",
            "-loglevel",
            "error",
            "-y",
            "-f",
            "concat",
            "-safe",
            "0",
            "-i",
            str(concat_file),
            "-c:a",
            "copy",
            str(intermediate),
        ]
    )
    validate_agon_wav(intermediate)
    destination.parent.mkdir(parents=True, exist_ok=True)
    intermediate.replace(destination)


def build_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(
        description=(
            "Convert local audio, directories, or one URL to AgonJukebox's "
            "8-bit unsigned PCM mono WAV format."
        )
    )
    parser.add_argument("sources", nargs="+", help="audio file(s), directory, or one URL")
    parser.add_argument(
        "-o",
        "--output",
        default="tgt/audio",
        help="output WAV or directory for individual tracks (default: tgt/audio)",
    )
    parser.add_argument(
        "--album",
        metavar="OUTPUT_WAV",
        help="concatenate all expanded local sources into this WAV",
    )
    parser.add_argument(
        "--sample-rate",
        type=int,
        default=-1,
        help="1..65535 Hz; -1 preserves each source (album uses the first source)",
    )
    parser.add_argument("--trim-start", default="00:00:00", help="ffmpeg start time")
    parser.add_argument("--trim-duration", type=float, help="duration in seconds")
    parser.add_argument("--compress", action="store_true", help="apply audio compression")
    parser.add_argument(
        "--normalize",
        action=argparse.BooleanOptionalAction,
        default=True,
        help="apply loudness normalization (default: enabled)",
    )
    parser.add_argument("--extra-af", default="", help="additional ffmpeg audio filters")
    parser.add_argument("--keep-temp", action="store_true", help="retain temporary files")
    return parser


def main(argv: list[str] | None = None) -> int:
    args = build_parser().parse_args(argv)
    url_values = [value for value in args.sources if is_url(value)]
    if url_values and (len(args.sources) != 1 or args.album):
        raise WavToolError("a URL must be the only source and cannot be used in album mode")

    require_native_tools(needs_downloader=bool(url_values))
    work_dir = Path(tempfile.mkdtemp(prefix="agonjukebox_wav_"))
    try:
        if url_values:
            sources = [download_url(url_values[0], work_dir)]
        else:
            sources = expand_local_sources(args.sources)

        if args.album:
            sample_rate = (
                probe_sample_rate(sources[0]) if args.sample_rate == -1 else args.sample_rate
            )
            sample_rate = validate_sample_rate(sample_rate)
            destination = Path(args.album).expanduser().resolve()
            destination.parent.mkdir(parents=True, exist_ok=True)
            make_album(sources, destination, sample_rate, args, work_dir)
            metadata = validate_agon_wav(destination)
            print(
                f"Wrote {destination} ({metadata['sample_rate']} Hz, "
                f"PCM offset {metadata['payload_offset']})"
            )
            return 0

        output = Path(args.output).expanduser().resolve()
        multiple = len(sources) > 1
        if multiple and output.suffix.lower() == ".wav":
            raise WavToolError("multiple sources require an output directory")

        for source in sources:
            sample_rate = (
                probe_sample_rate(source) if args.sample_rate == -1 else args.sample_rate
            )
            sample_rate = validate_sample_rate(sample_rate)
            destination = output_path_for(source, output, multiple=multiple)
            convert_track(source, destination, sample_rate, args, work_dir)
            metadata = validate_agon_wav(destination)
            print(
                f"Wrote {destination} ({metadata['sample_rate']} Hz, "
                f"PCM offset {metadata['payload_offset']})"
            )
        return 0
    finally:
        if args.keep_temp:
            print(f"Temporary files retained at {work_dir}")
        else:
            shutil.rmtree(work_dir)


if __name__ == "__main__":
    try:
        raise SystemExit(main())
    except (OSError, ValueError, WavToolError, subprocess.CalledProcessError) as exc:
        print(f"error: {exc}", file=sys.stderr)
        raise SystemExit(2) from exc

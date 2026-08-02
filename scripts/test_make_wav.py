#!/usr/bin/env python3
"""Regression tests for the RIFF/WAV subset accepted by AgonJukebox."""

from __future__ import annotations

import importlib.util
from pathlib import Path
import shutil
import struct
import subprocess
import tempfile
import unittest


MODULE_PATH = Path(__file__).resolve().parents[1] / "scripts" / "make_wav.py"
SPEC = importlib.util.spec_from_file_location("agon_make_wav_under_test", MODULE_PATH)
assert SPEC is not None and SPEC.loader is not None
wavtool = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(wavtool)


def fmt_payload(
    *,
    audio_format: int = 1,
    channels: int = 1,
    sample_rate: int = 48_000,
    byte_rate: int | None = None,
    block_align: int = 1,
    bit_depth: int = 8,
    extension: bytes = b"",
) -> bytes:
    if byte_rate is None:
        byte_rate = sample_rate
    return struct.pack(
        "<HHIIHH",
        audio_format,
        channels,
        sample_rate,
        byte_rate,
        block_align,
        bit_depth,
    ) + extension


def extensible_pcm_fmt(*, guid: bytes = wavtool.PCM_SUBFORMAT_GUID) -> bytes:
    extension = struct.pack("<HHI", 22, 8, 4) + guid
    return fmt_payload(audio_format=0xFFFE, extension=extension)


def chunk(chunk_id: bytes, payload: bytes, *, include_pad: bool = True) -> bytes:
    assert len(chunk_id) == 4
    encoded = chunk_id + struct.pack("<I", len(payload)) + payload
    if include_pad and len(payload) & 1:
        encoded += b"\x00"
    return encoded


def riff_wave(chunks: list[bytes], *, physical_trailer: bytes = b"") -> bytes:
    body = b"WAVE" + b"".join(chunks)
    return b"RIFF" + struct.pack("<I", len(body)) + body + physical_trailer


class WavValidatorTests(unittest.TestCase):
    def setUp(self) -> None:
        self.temp_dir = tempfile.TemporaryDirectory(prefix="agon-wav-tests-")
        self.root = Path(self.temp_dir.name)

    def tearDown(self) -> None:
        self.temp_dir.cleanup()

    def write(self, name: str, data: bytes) -> Path:
        path = self.root / name
        path.write_bytes(data)
        return path

    def assert_invalid(self, name: str, data: bytes) -> None:
        with self.assertRaises(wavtool.WavToolError):
            wavtool.validate_agon_wav(self.write(name, data))

    def test_minimal_legacy_pcm_has_payload_at_byte_44(self) -> None:
        raw = riff_wave([chunk(b"fmt ", fmt_payload()), chunk(b"data", b"\x80\x81")])
        self.assertEqual(
            wavtool.validate_agon_wav(self.write("minimal.wav", raw)),
            {"sample_rate": 48_000, "data_size": 2, "payload_offset": 44},
        )

    def test_metadata_padding_and_trailing_chunks_do_not_fix_the_offset(self) -> None:
        chunks = [
            chunk(b"JUNK", b"x"),
            chunk(b"fmt ", fmt_payload(extension=b"\x00\x00")),
            chunk(b"LIST", b"INFO-odd!"),
            chunk(b"data", b"\x80\x81\x82"),
            chunk(b"cue ", b"trailing"),
        ]
        raw = riff_wave(chunks, physical_trailer=b"outside RIFF is ignored")
        result = wavtool.validate_agon_wav(self.write("metadata.wav", raw))
        self.assertEqual(result["payload_offset"], raw.index(b"data") + 8)
        self.assertEqual(result["data_size"], 3)

    def test_extensible_pcm_at_byte_102_is_supported(self) -> None:
        raw = riff_wave(
            [
                chunk(b"JUNK", b"x" * 25),
                chunk(b"fmt ", extensible_pcm_fmt()),
                chunk(b"data", b"\x80"),
            ]
        )
        result = wavtool.validate_agon_wav(self.write("extensible.wav", raw))
        self.assertEqual(result["sample_rate"], 48_000)
        self.assertEqual(result["payload_offset"], 102)

    def test_non_pcm_extensible_subtype_is_rejected(self) -> None:
        bad_guid = bytes.fromhex("0300000000001000800000aa00389b71")
        self.assert_invalid(
            "extensible-float.wav",
            riff_wave(
                [
                    chunk(b"fmt ", extensible_pcm_fmt(guid=bad_guid)),
                    chunk(b"data", b"\x80"),
                ]
            ),
        )

    def test_fmt_must_precede_data_and_may_not_repeat(self) -> None:
        self.assert_invalid(
            "data-first.wav",
            riff_wave([chunk(b"data", b"\x80"), chunk(b"fmt ", fmt_payload())]),
        )
        self.assert_invalid(
            "duplicate-fmt.wav",
            riff_wave(
                [
                    chunk(b"fmt ", fmt_payload()),
                    chunk(b"fmt ", fmt_payload()),
                    chunk(b"data", b"\x80"),
                ]
            ),
        )

    def test_empty_or_missing_required_chunks_are_rejected(self) -> None:
        self.assert_invalid(
            "empty-data.wav",
            riff_wave([chunk(b"fmt ", fmt_payload()), chunk(b"data", b"")]),
        )
        self.assert_invalid("no-fmt.wav", riff_wave([chunk(b"data", b"\x80")]))
        self.assert_invalid("no-data.wav", riff_wave([chunk(b"fmt ", fmt_payload())]))
        self.assert_invalid(
            "short-fmt.wav",
            riff_wave([chunk(b"fmt ", fmt_payload()[:15]), chunk(b"data", b"\x80")]),
        )

    def test_invalid_audio_fields_are_rejected(self) -> None:
        variants = {
            "format": fmt_payload(audio_format=3),
            "channels": fmt_payload(channels=2, byte_rate=96_000, block_align=2),
            "rate-zero": fmt_payload(sample_rate=0, byte_rate=0),
            "rate-wide": fmt_payload(sample_rate=65_536, byte_rate=65_536),
            "byte-rate": fmt_payload(byte_rate=47_999),
            "align": fmt_payload(block_align=2),
            "depth": fmt_payload(bit_depth=16, block_align=2, byte_rate=96_000),
        }
        for name, fmt in variants.items():
            with self.subTest(name=name):
                self.assert_invalid(
                    f"bad-{name}.wav",
                    riff_wave([chunk(b"fmt ", fmt), chunk(b"data", b"\x80")]),
                )

    def test_bad_or_truncated_containers_are_rejected(self) -> None:
        valid = riff_wave([chunk(b"fmt ", fmt_payload()), chunk(b"data", b"\x80")])
        self.assert_invalid("short.wav", valid[:11])
        self.assert_invalid("not-riff.wav", b"NOPE" + valid[4:])
        self.assert_invalid("not-wave.wav", valid[:8] + b"NOPE" + valid[12:])

        truncated_riff = bytearray(valid)
        struct.pack_into("<I", truncated_riff, 4, len(valid) + 20)
        self.assert_invalid("truncated-riff.wav", bytes(truncated_riff))

        malformed_data = b"data" + struct.pack("<I", 20) + b"\x80"
        self.assert_invalid(
            "truncated-data.wav",
            riff_wave([chunk(b"fmt ", fmt_payload()), malformed_data]),
        )
        self.assert_invalid(
            "partial-header.wav",
            riff_wave([chunk(b"fmt ", fmt_payload()), chunk(b"data", b"\x80\x81"), b"JUNK"]),
        )
        self.assert_invalid(
            "missing-pad.wav",
            riff_wave(
                [
                    chunk(b"fmt ", fmt_payload()),
                    chunk(b"data", b"\x80\x81"),
                    chunk(b"JUNK", b"x", include_pad=False),
                ]
            ),
        )

    @unittest.skipUnless(shutil.which("ffmpeg"), "ffmpeg is unavailable")
    def test_ordinary_ffmpeg_max_rate_output(self) -> None:
        path = self.root / "ffmpeg.wav"
        subprocess.run(
            [
                "ffmpeg",
                "-hide_banner",
                "-loglevel",
                "error",
                "-y",
                "-f",
                "lavfi",
                "-i",
                "sine=frequency=440:duration=0.02",
                "-ac",
                "1",
                "-ar",
                "65535",
                "-c:a",
                "pcm_u8",
                str(path),
            ],
            check=True,
        )
        result = wavtool.validate_agon_wav(path)
        self.assertEqual(result["sample_rate"], 65_535)
        self.assertGreater(result["data_size"], 0)
        with path.open("rb") as stream:
            stream.seek(result["payload_offset"] - 8)
            self.assertEqual(stream.read(4), b"data")


if __name__ == "__main__":
    unittest.main()

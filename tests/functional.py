"""Prepare an isolated MOS functional-test SD tree or validate its host log."""
from __future__ import annotations

import argparse
import json
import math
from pathlib import Path
import re
import shutil
import subprocess
import wave

PROJECT = Path(__file__).resolve().parents[1]


def prepare(destination: Path) -> None:
    # Require a new destination so existing SD contents cannot be overwritten.
    destination.mkdir(parents=True, exist_ok=False)
    (destination / "bin").mkdir()
    subprocess.run(
        ["ez80asm", "../../tests/asm/livecheck.asm", str(destination / "bin/livecheck.bin")],
        cwd=PROJECT / "src/asm", check=True,
    )
    shutil.copytree(PROJECT / "skins/base", destination / "jukebox/skins/base")
    (destination / "bin/jukebox.cfg").write_text(
        "format=1\nskin_dir=/jukebox/skins/base\n", encoding="ascii"
    )
    media = destination / "qualification"
    (media / "Empty").mkdir(parents=True)
    (media / "Play").mkdir()
    for index in range(12):
        rate = 65535 if index == 0 else 8000
        count = rate * 3 + rate // 4 if index == 0 else 2000
        filename = f"{index:02d}_" + ("Long_65535.wav" if index == 0 else "Short_8000.wav")
        with wave.open(str(media / "Play" / filename), "wb") as output:
            output.setparams((1, 1, rate, count, "NONE", "not compressed"))
            output.writeframes(bytes(
                128 + int(20 * math.sin(2 * math.pi * 440 * sample / rate))
                for sample in range(count)
            ))
    (destination / "autoexec.txt").write_bytes(b"SET KEYBOARD 1\r\nlivecheck\r\n")
    print(f"Functional-test SD tree: {destination}")


def check(log: Path) -> None:
    output = log.read_text(errors="replace")
    if "LIVE_TEST_PASS" not in output or "LIVE_TEST_FAIL" in output:
        raise ValueError("target functional scenarios did not pass")
    if "LIVE_WIDGET_PIXELS_PASS" not in output:
        raise ValueError("target widget pixels did not pass")
    match = re.search(r"SCHEDULE ([0-9A-F]{16})", output)
    if match is None:
        raise ValueError("missing target scheduling evidence")
    data = bytes.fromhex(match[1])
    elapsed = int.from_bytes(data[:3], "little")
    counter = data[3]
    remaining = int.from_bytes(data[4:], "little")
    ticks = elapsed * 60 + 60 - counter
    expected = (65535 * 3 + 65535 // 4) - ticks * 65535 // 60
    if remaining != expected:
        raise ValueError(f"read accounting: expected {expected}, got {remaining}")
    print(json.dumps({
        "result": "PASS", "scenarios": 26, "widget_pixels": 1327,
        "rate_hz": 65535, "read_ticks": ticks, "bytes_remaining": remaining,
        "audio_output": "listening review is separate",
    }, indent=2))


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    commands = parser.add_subparsers(dest="command", required=True)
    commands.add_parser("prepare", help="create a new SD tree").add_argument("destination", type=Path)
    commands.add_parser("check", help="validate a completed emulator log").add_argument("log", type=Path)
    args = parser.parse_args()
    if args.command == "prepare":
        prepare(args.destination.resolve())
    else:
        check(args.log)


if __name__ == "__main__":
    main()

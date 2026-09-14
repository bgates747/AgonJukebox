"""Prepare an isolated MOS functional-test SD tree or validate its host log."""
from __future__ import annotations

import argparse
import json
import math
import os
from pathlib import Path
import re
import shutil
import subprocess
import wave

PROJECT = Path(__file__).resolve().parents[1]


def prepare(destination: Path, skin: str = "base", runtime: bool = False) -> None:
    if not re.fullmatch(r"[a-z][a-z0-9_]{0,23}",skin):
        raise ValueError("Invalid skin id")
    # Require a new destination so existing SD contents cannot be overwritten.
    destination.mkdir(parents=True, exist_ok=False)
    (destination / "bin").mkdir()
    subprocess.run(
        ["ez80asm", "../../tests/asm/" + (f"runtime_{skin}_check.asm" if runtime else {"artdeco":"artdeco_check.asm","seventies":"seventies_check.asm"}.get(skin,"livecheck.asm" if skin=="base" else skin+"_check.asm")),
         os.path.relpath(destination / "bin/livecheck.bin", PROJECT / "src/asm")],
        cwd=PROJECT / "src/asm", check=True,
    )
    shutil.copytree(PROJECT / "skins" / ("runtime/" + skin if runtime else skin), destination / "jukebox/skins" / skin)
    (destination / "bin/jukebox.cfg").write_text(
        f"format=1\nskin_dir=/jukebox/skins/{skin}\n", encoding="ascii"
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


def check(log: Path, skin: str = "base") -> None:
    output = log.read_text(errors="replace")
    if "LIVE_TEST_PASS" not in output or "LIVE_TEST_FAIL" in output:
        raise ValueError("target functional scenarios did not pass")
    if "LIVE_WIDGET_PIXELS_PASS" not in output:
        raise ValueError("target widget pixels did not pass")
    if skin != "base" and "LIVE_FONT_PIXELS_PASS" not in output:
        raise ValueError("antialiased glyph/context pixels did not pass")
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
    pixels = 1327
    if skin != "base":
        pixels = (PROJECT / f"tests/fixtures/{skin}/widget-samples.bin").stat().st_size // 7
    result = {
        "result": "PASS", "skin": skin, "scenarios": 26, "widget_pixels": pixels,
        "rate_hz": 65535, "read_ticks": ticks, "bytes_remaining": remaining,
        "audio_output": "listening review is separate",
    }
    if skin != "base":
        result['font_pixels'] = (PROJECT / f'tests/fixtures/{skin}/font-samples.bin').stat().st_size // 7
    print(json.dumps(result, indent=2))


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    commands = parser.add_subparsers(dest="command", required=True)
    prepare_cmd = commands.add_parser("prepare", help="create a new SD tree")
    prepare_cmd.add_argument("destination", type=Path)
    prepare_cmd.add_argument("--skin", default="base")
    check_cmd = commands.add_parser("check", help="validate a completed emulator log")
    check_cmd.add_argument("log", type=Path)
    check_cmd.add_argument("--skin", default="base")
    args = parser.parse_args()
    if args.command == "prepare":
        prepare(args.destination.resolve(), args.skin)
    else:
        check(args.log, args.skin)


if __name__ == "__main__":
    main()

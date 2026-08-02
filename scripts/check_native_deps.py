#!/usr/bin/env python3
"""Check native programs required to build and prepare AgonJukebox audio."""

from __future__ import annotations

import shutil


REQUIRED_TOOLS = ("ez80asm", "ffmpeg", "ffprobe")


def main() -> int:
    missing = [name for name in REQUIRED_TOOLS if shutil.which(name) is None]
    if missing:
        print("Missing native tools:", ", ".join(missing))
        print("FFmpeg supplies ffmpeg and ffprobe; install ez80asm separately.")
        return 1

    print("Native dependency check passed:", ", ".join(REQUIRED_TOOLS))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())

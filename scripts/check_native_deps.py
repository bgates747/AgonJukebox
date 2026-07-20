#!/usr/bin/env python3
"""Check native tools and libraries required by the Agon media toolchain."""

from __future__ import annotations

import shutil
import subprocess
import sys


PKG_CONFIG_PACKAGES = (
    "libavformat",
    "libavcodec",
    "libswscale",
    "libavutil",
    "libpng",
)

DEBIAN_INSTALL_COMMAND = (
    "sudo apt-get install -y pkg-config ffmpeg libavformat-dev "
    "libavcodec-dev libswscale-dev libavutil-dev libpng-dev"
)


def main() -> int:
    missing_tools = [name for name in ("cc", "pkg-config", "ffmpeg") if not shutil.which(name)]
    missing_packages: list[str] = []

    if shutil.which("pkg-config"):
        for package in PKG_CONFIG_PACKAGES:
            result = subprocess.run(
                ["pkg-config", "--exists", package],
                check=False,
            )
            if result.returncode != 0:
                missing_packages.append(package)
    else:
        missing_packages.extend(PKG_CONFIG_PACKAGES)

    if missing_tools:
        print("Missing native tools:", ", ".join(missing_tools))
    if missing_packages:
        print("Missing pkg-config packages:", ", ".join(missing_packages))

    if missing_tools or missing_packages:
        if sys.platform.startswith("linux"):
            print("Install the Debian/Ubuntu prerequisites with:")
            print(f"  {DEBIAN_INSTALL_COMMAND}")
        return 1

    print("Native dependency check passed.")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())


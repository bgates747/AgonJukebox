#!/usr/bin/env python3
"""Verify AgonVideo's Python and native media-development environment."""

from __future__ import annotations

import importlib
import os
from pathlib import Path
import subprocess
import sys
import tempfile


PROJECT_ROOT = Path(__file__).resolve().parents[1]
EXPECTED_MODULES = (
    "numpy",
    "scipy",
    "PIL",
    "pandas",
    "matplotlib",
    "pydub",
    "soundfile",
    "pretty_midi",
    "fluidsynth",
    "pygame",
    "agonutils",
)
EXPECTED_AGONUTILS_API = (
    "convert_to_palette",
    "img_to_rgba2",
    "rgba8_to_img",
    "rgba2_to_img",
    "csv_to_palette",
    "simz_encode",
    "simz_decode",
    "simz_encode_bytes",
    "simz_decode_bytes",
)


def main() -> int:
    os.environ.setdefault("MPLCONFIGDIR", tempfile.mkdtemp(prefix="agonvideo-matplotlib-"))

    failures: list[str] = []
    print(f"Python: {sys.version.split()[0]}")
    print(f"Interpreter: {sys.executable}")

    for name in EXPECTED_MODULES:
        try:
            module = importlib.import_module(name)
            print(f"PASS import {name}: {getattr(module, '__file__', '<built-in>')}")
        except Exception as exc:  # Report all failures in one run.
            failures.append(f"import {name}: {type(exc).__name__}: {exc}")

    try:
        agonutils = importlib.import_module("agonutils")
        for name in EXPECTED_AGONUTILS_API:
            if not hasattr(agonutils, name):
                failures.append(f"agonutils is missing {name}")

        source = bytes(range(256)) * 16
        encoded = agonutils.simz_encode_bytes(source)
        decoded = agonutils.simz_decode_bytes(encoded)
        if decoded != source:
            failures.append("agonutils SIMZ byte round trip changed the input")
        else:
            print(f"PASS SIMZ round trip: {len(source)} -> {len(encoded)} -> {len(decoded)} bytes")
    except Exception as exc:
        failures.append(f"agonutils API verification: {type(exc).__name__}: {exc}")

    native_check = subprocess.run(
        [sys.executable, str(PROJECT_ROOT / "scripts" / "check_native_deps.py")],
        check=False,
    )
    if native_check.returncode:
        failures.append("native dependency check failed")

    if failures:
        print("\nEnvironment verification failed:")
        for failure in failures:
            print(f"- {failure}")
        return 1

    print("\nEnvironment verification passed.")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())

#!/usr/bin/env python3
"""Verify the WAV-only Python, native-tool, test, and assembly environment."""

from __future__ import annotations

import importlib
from pathlib import Path
import re
import subprocess
import sys
import tempfile


PROJECT_ROOT = Path(__file__).resolve().parents[1]
VENV_DIR = PROJECT_ROOT / ".venv"
EMBEDDED_UI_ASSETS = (
    PROJECT_ROOT / "src" / "fonts" / "Lat2-VGA8_8x8.font.inc",
    PROJECT_ROOT / "src" / "images" / "logo.rgba2",
)
FORBIDDEN_STAGED_UI_ASSETS = (
    PROJECT_ROOT / "tgt" / "Lat2-VGA8_8x8.font",
    PROJECT_ROOT / "tgt" / "Lat2-VGA8_8x8.font.inc",
    PROJECT_ROOT / "tgt" / "logo.png",
    PROJECT_ROOT / "tgt" / "logo.rgba2",
)


def run(command: list[str], *, cwd: Path = PROJECT_ROOT) -> bool:
    print("+", " ".join(command), flush=True)
    return subprocess.run(command, cwd=cwd, check=False).returncode == 0


def main() -> int:
    failures: list[str] = []
    print(f"Python: {sys.version.split()[0]}")
    print(f"Interpreter: {sys.executable}")

    if Path(sys.prefix).resolve() != VENV_DIR.resolve():
        failures.append(f"interpreter is not from {VENV_DIR}")

    try:
        module = importlib.import_module("yt_dlp")
        print(f"PASS import yt_dlp: {module.__file__}")
    except Exception as exc:
        failures.append(f"import yt_dlp: {type(exc).__name__}: {exc}")

    if not run([sys.executable, str(PROJECT_ROOT / "scripts" / "check_native_deps.py")]):
        failures.append("native dependency check failed")
    if not run([sys.executable, "-m", "pip", "check"]):
        failures.append("pip dependency check failed")
    if not run(
        [sys.executable, "-B", "-m", "unittest", "-v", "scripts.test_make_wav"]
    ):
        failures.append("WAV tool tests failed")

    staged_assets = [path for path in FORBIDDEN_STAGED_UI_ASSETS if path.exists()]
    if staged_assets:
        failures.append(
            "embedded UI assets must not be staged in tgt: "
            + ", ".join(str(path.relative_to(PROJECT_ROOT)) for path in staged_assets)
        )
    else:
        print("PASS package: embedded UI assets are absent from tgt")

    with tempfile.TemporaryDirectory(prefix="agonjukebox-build-") as temp_dir:
        binary = Path(temp_dir) / "jukebox.bin"
        if not run(
            ["ez80asm", "app.asm", str(binary)],
            cwd=PROJECT_ROOT / "src" / "asm",
        ):
            failures.append("application assembly failed")
        elif not binary.is_file() or binary.stat().st_size == 0:
            failures.append("assembler did not produce a nonempty binary")
        else:
            print(f"PASS assembly: {binary.stat().st_size} bytes")
            binary_data = binary.read_bytes()
            for asset in EMBEDDED_UI_ASSETS:
                if asset.suffix == ".inc":
                    asset_data = bytes(
                        int(value, 2)
                        for value in re.findall(
                            r"%([01]{8})", asset.read_text(encoding="utf-8")
                        )
                    )
                else:
                    asset_data = asset.read_bytes()
                if not asset_data or asset_data not in binary_data:
                    failures.append(
                        f"assembled binary does not contain {asset.relative_to(PROJECT_ROOT)}"
                    )
                else:
                    print(f"PASS embedded asset: {asset.relative_to(PROJECT_ROOT)}")

    if failures:
        print("\nEnvironment verification failed:")
        for failure in failures:
            print(f"- {failure}")
        return 1

    print("\nEnvironment verification passed.")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())

#!/usr/bin/env python3
"""Create and verify AgonJukebox's project-local Python environment."""

from __future__ import annotations

from pathlib import Path
import subprocess
import sys


PROJECT_ROOT = Path(__file__).resolve().parents[1]
VENV_DIR = PROJECT_ROOT / ".venv"
PYTHON_REQUIREMENTS = ("yt-dlp==2026.7.4",)


def run(*args: object) -> None:
    command = [str(arg) for arg in args]
    print("+", " ".join(command), flush=True)
    subprocess.run(command, cwd=PROJECT_ROOT, check=True)


def venv_python() -> Path:
    if sys.platform == "win32":
        return VENV_DIR / "Scripts" / "python.exe"
    return VENV_DIR / "bin" / "python"


def main() -> int:
    if not VENV_DIR.exists():
        if sys.version_info < (3, 10):
            print("Python 3.10 or newer is required.", file=sys.stderr)
            return 1
        run(sys.executable, "-m", "venv", VENV_DIR)

    python = venv_python()
    run(python, PROJECT_ROOT / "scripts" / "check_native_deps.py")
    run(python, "-m", "pip", "install", "--upgrade", "pip")
    run(python, "-m", "pip", "install", *PYTHON_REQUIREMENTS)
    run(python, PROJECT_ROOT / "scripts" / "verify_environment.py")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())

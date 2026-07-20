#!/usr/bin/env python3
"""Create and populate AgonVideo's project-local Python environment."""

from __future__ import annotations

from pathlib import Path
import subprocess
import sys


PROJECT_ROOT = Path(__file__).resolve().parents[1]
VENV_DIR = PROJECT_ROOT / ".venv"


def run(*args: object) -> None:
    command = [str(arg) for arg in args]
    print("+", " ".join(command), flush=True)
    subprocess.run(command, cwd=PROJECT_ROOT, check=True)


def venv_python() -> Path:
    if sys.platform == "win32":
        return VENV_DIR / "Scripts" / "python.exe"
    return VENV_DIR / "bin" / "python"


def main() -> int:
    run("git", "submodule", "update", "--init", "--recursive")

    if not VENV_DIR.exists():
        if sys.version_info < (3, 14):
            print(
                "Python 3.14 or newer is required to create the preferred "
                "development environment. Run this script with Python 3.14.",
                file=sys.stderr,
            )
            return 1
        run(sys.executable, "-m", "venv", VENV_DIR)

    python = venv_python()
    run(python, PROJECT_ROOT / "scripts" / "check_native_deps.py")
    run(python, "-m", "pip", "install", "--upgrade", "pip", "setuptools", "wheel")
    run(python, "-m", "pip", "install", "-r", PROJECT_ROOT / "requirements.txt")
    run(python, "-m", "pip", "install", "-e", PROJECT_ROOT / "external" / "agon-utils")
    run(python, PROJECT_ROOT / "scripts" / "verify_environment.py")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())


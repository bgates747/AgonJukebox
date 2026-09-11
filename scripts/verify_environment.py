#!/usr/bin/env python3
"""Verify the WAV-only Python, native-tool, test, and assembly environment."""

from __future__ import annotations

import importlib
from pathlib import Path
import subprocess
import sys
import tempfile


PROJECT_ROOT = Path(__file__).resolve().parents[1]
VENV_DIR = PROJECT_ROOT / ".venv"
RUNTIME_SKIN_ASSETS = (
    PROJECT_ROOT / "skins/artdeco/graphics.agnb",
    PROJECT_ROOT / "skins/artdeco/fonts/neutrino_5x8.font",
    PROJECT_ROOT / "skins/base/graphics.agnb",
    PROJECT_ROOT / "skins/base/fonts/body8x8.font",
    PROJECT_ROOT / "skins/base/fonts/body8x14.font",
)


def run(command: list[str], *, cwd: Path = PROJECT_ROOT) -> bool:
    print("+", " ".join(command), flush=True)
    return subprocess.run(command, cwd=cwd, check=False).returncode == 0


def main() -> int:
    failures: list[str] = []
    runtime_assets = list(RUNTIME_SKIN_ASSETS)
    # Both authoring candidates have the same geometry and loader contract.
    # Verify the actual playlist assets selected by the generated manifest.
    try:
        package = PROJECT_ROOT / "skins/artdeco"
        manifest = dict(line.split("=", 1) for line in
                        (package / "skin.cfg").read_text().splitlines() if "=" in line)
        runtime_assets.extend(package / manifest[key] for key in
                              ("playlist.font.file", "playlist.graphics.file"))
    except (OSError, KeyError, ValueError) as exc:
        failures.append(f"cannot find playlist assets in skin manifest: {exc}")
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

    for asset in runtime_assets:
        if not asset.is_file():
            failures.append(f"missing runtime skin asset: {asset.relative_to(PROJECT_ROOT)}")
    for filename in ["config/jukebox.cfg", "skins/base/skin.cfg", "skins/artdeco/skin.cfg"]:
        if not (PROJECT_ROOT / filename).is_file():
            failures.append(f"missing configuration: {filename}")

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
            if len(binary_data) + 0x40000 >= 0x6FF00:
                failures.append("application overlaps fixed browser memory")
            for asset in runtime_assets:
                if not asset.is_file():
                    continue
                asset_data = asset.read_bytes()
                if not asset_data or asset_data in binary_data:
                    failures.append(
                        f"skin asset must be external and nonempty: {asset.relative_to(PROJECT_ROOT)}"
                    )
                else:
                    print(f"PASS external asset: {asset.relative_to(PROJECT_ROOT)}")

        if not run(
            ["ez80asm", "../../tests/asm/livecheck.asm", str(Path(temp_dir) / "livecheck.bin")],
            cwd=PROJECT_ROOT / "src/asm",
        ):
            failures.append("functional test assembly failed")
        for source, target in [("app_base.asm", "base.bin"),
                               ("../../tests/asm/artdeco_check.asm", "artcheck.bin")]:
            if not run(["ez80asm", source, str(Path(temp_dir) / target)],
                       cwd=PROJECT_ROOT / "src/asm"):
                failures.append(f"assembly failed: {source}")

    if failures:
        print("\nEnvironment verification failed:")
        for failure in failures:
            print(f"- {failure}")
        return 1

    print("\nEnvironment verification passed.")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())

#!/usr/bin/env python3
"""Deploy this project's declared Agon software bundles."""

from pathlib import Path
import sys

PROJECT_ROOT = Path(__file__).resolve().parent
ENGINE_ROOT = Path.home() / "Agon/mystuff/agon-dev-env/scripts"
if not (ENGINE_ROOT / "agon_deploy.py").is_file():
    raise SystemExit(
        "Canonical deployment engine is missing: "
        f"{ENGINE_ROOT / 'agon_deploy.py'}"
    )
sys.path.insert(0, str(ENGINE_ROOT))
from agon_deploy import DeploymentError, main  # noqa: E402

try:
    raise SystemExit(main(project_root=PROJECT_ROOT))
except DeploymentError as error:
    print(f"deployment refused: {error}", file=sys.stderr)
    raise SystemExit(2)

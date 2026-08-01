# Development setup

## Clone the project

Clone AgonJukebox normally. It has no Git submodules:

```bash
git clone <AgonJukebox repository URL>
```

The project consumes the canonical user-owned `agon-utils` checkout at:

```text
/home/smith/Agon/mystuff/agon-utils
```

Do not create an application-local copy or submodule. Utility development is
committed in the canonical repository on its own branch; AgonJukebox consumes
that live checkout through an editable Python installation.

## Python environment

The preferred setup command is:

```bash
python3.14 scripts/setup_python.py
```

It creates `.venv` when necessary, checks native dependencies, installs the
pinned packages in `requirements.txt`, installs the canonical `agonutils`
checkout in editable mode, and verifies the resulting environment. When
`.venv` already exists, it is reused.

The local virtual environment is intentionally ignored by Git. It can be
activated manually with:

```bash
source .venv/bin/activate
python --version
```

The current development environment uses Python 3.14.6. Ordinary Python
dependencies are pinned in `requirements.txt`.

VS Code-compatible editors are configured through `.vscode/settings.json` to
use `${workspaceFolder}/.venv/bin/python`, activate that environment in new
integrated terminals, and inspect the canonical `agon-utils` checkout. Reload
the editor window after initially creating `.venv` if its analyzer still
reports missing imports.

For direct terminal execution, either activate the environment first:

```bash
source .venv/bin/activate
python build/scripts/test_differencing_playback.py
```

or invoke its interpreter explicitly:

```bash
.venv/bin/python build/scripts/test_differencing_playback.py
```

### Native prerequisites

The media pipeline and `agonutils` require a C compiler, `pkg-config`, FFmpeg,
the FFmpeg development libraries, and libpng development headers. Check them
without changing the system:

```bash
.venv/bin/python scripts/check_native_deps.py
```

On Debian or Ubuntu, install them with:

```bash
sudo apt-get update
sudo apt-get install -y \
  pkg-config ffmpeg libavformat-dev libavcodec-dev \
  libswscale-dev libavutil-dev libpng-dev
```

The bootstrap uses the canonical editable-install command:

```bash
.venv/bin/python -m pip install --no-build-isolation --no-deps \
  -e /home/smith/Agon/mystuff/agon-utils
```

Verify dependency consistency, the canonical module location, the expected
`agonutils` API, native dependencies, and a SIMZ in-memory round trip with:

```bash
.venv/bin/python -m pip check
.venv/bin/python scripts/verify_environment.py
```

Run the utility checkout's own test with the consumer interpreter:

```bash
cd /home/smith/Agon/mystuff/agon-utils
/home/smith/Agon/mystuff/AgonJukebox/.venv/bin/python tests/test_agonutils.py
```

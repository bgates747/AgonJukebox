# Development setup

## Clone the complete project

AgonVideo uses `agon-utils` as a Git submodule pinned to a tested revision. For
a new checkout, clone the project and its submodules together:

```bash
git clone --recurse-submodules <AgonVideo repository URL>
```

If AgonVideo has already been cloned, populate or restore its submodules with:

```bash
git submodule update --init --recursive
```

The expected utility source location is:

```text
external/agon-utils/
```

Check the recorded and checked-out revisions with:

```bash
git submodule status
git diff --submodule
```

The parent repository records an exact `agon-utils` commit. Updating files in
the submodule does not automatically update that recorded commit.

## Working safely in the submodule

The normal AgonVideo workflow treats `external/agon-utils` as read-only. Before
making a deliberate utility change, create a branch inside the submodule:

```bash
cd external/agon-utils
git switch -c agonvideo/<change-name>
```

Commit utility changes inside `external/agon-utils` first. Then return to the
AgonVideo root and commit the new submodule pointer separately. Never assume
that an AgonVideo commit includes uncommitted files inside the submodule.

Useful checks are:

```bash
git status
git -C external/agon-utils status
```

Do not use cleanup, reset, or checkout commands on a modified submodule without
first determining whether it contains uncommitted work.

## Python environment

The preferred setup command is:

```bash
python3.14 scripts/setup_python.py
```

It initializes submodules, creates `.venv` when necessary, checks native
dependencies, installs the pinned packages in `requirements.txt`, installs
`agonutils` from the repo-relative submodule, and verifies the resulting
environment. When `.venv` already exists, it is reused.

The local virtual environment is intentionally ignored by Git. It can be
activated manually with:

```bash
source .venv/bin/activate
python --version
```

The current development environment uses Python 3.14.6. Ordinary Python
dependencies are pinned in `requirements.txt`.

VS Code-compatible editors are configured through `.vscode/settings.json` to
use `${workspaceFolder}/.venv/bin/python` and activate the environment in new
integrated terminals. After initially creating `.venv`, reload the editor window
if its Python analyzer still reports missing imports.

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

The bootstrap installs `agonutils` in editable mode explicitly with AgonVideo's
Python. The equivalent standalone command is:

```bash
.venv/bin/python -m pip install -e external/agon-utils
```

Verify all imports, the expected `agonutils` API, native dependencies, and a
SIMZ in-memory round trip with:

```bash
.venv/bin/python scripts/verify_environment.py
```

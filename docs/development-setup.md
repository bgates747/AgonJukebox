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

The local virtual environment is intentionally ignored by Git:

```bash
source .venv/bin/activate
python --version
```

The current development environment uses Python 3.14.6. The installed package
set has not yet been captured as reviewed dependency metadata, so environment
creation is not yet fully reproducible.

`agonutils` is a native CPython extension and is not installed yet. Its eventual
editable-development command will be run explicitly with AgonVideo's Python:

```bash
.venv/bin/python -m pip install -e external/agon-utils
```

Do not run this until the native FFmpeg/libpng development dependencies and the
known `agon-utils` packaging issues have been addressed.


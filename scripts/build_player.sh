#!/bin/sh
set -eu
project_dir=$(CDPATH= cd -- "$(dirname -- "$0")/.." && pwd)
mkdir -p "$project_dir/tgt"
cd "$project_dir/src/asm"
"${EZ80ASM:-ez80asm}" app.asm ../../tgt/jukebox.bin

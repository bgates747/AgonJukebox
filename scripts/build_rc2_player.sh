#!/bin/sh
set -eu
cd "$(dirname "$0")/../src/asm"
"${EZ80ASM:-ez80asm}" app_eirene_rc2.asm ../../tgt/jukebox-rc2.bin

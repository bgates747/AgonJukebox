#!/bin/sh
set -eu
cd "$(dirname "$0")/../src/asm"
"${EZ80ASM:-ez80asm}" app_uart_rfc.asm ../../tgt/jukebox-rfc.bin

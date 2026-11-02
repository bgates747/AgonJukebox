; UART-002: same foreground prototype, explicit verified CTS batch16.
uart_proto: equ 1
uart_batch_size: equ 16
skin_runtime: equ 1
skin_custom: equ 1
skin_artdeco: equ 1
skin_seventies: equ 0
live_test_mode: equ 0
    include "../ui/runtime/profile.inc"
    include "jukebox_modules.inc"
    include "../ui/runtime/widgets.inc"
    include "skin_runtime.inc"
    include "skin_chooser.inc"
    include "runtime_start.inc"

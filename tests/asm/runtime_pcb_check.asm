; One executable for every bounded runtime-v1 skin package.
skin_runtime: equ 1
skin_custom: equ 1
skin_artdeco: equ 1
skin_seventies: equ 0
live_test_mode: equ 1
    include "../ui/runtime/profile.inc"
    include "jukebox_modules.inc"
    include "../ui/runtime/widgets.inc"
    include "skin_runtime.inc"
    include "skin_chooser.inc"
lt_font_draw: incbin "../../tests/fixtures/pcb/font-probe.vdu"
lt_font_draw_end:
lt_font_samples: incbin "../../tests/fixtures/pcb/font-samples.bin"
lt_font_samples_end:
lt_samples: incbin "../../tests/fixtures/pcb/widget-samples.bin"
lt_samples_end:
    include "../ui/pcb/test-meta.inc"
lt_schema_frame_pixel:
    ld bc,0
    ld de,0
    ld a,0
    ld (lt_rgb+0),a
    ld a,0
    ld (lt_rgb+1),a
    ld a,0
    ld (lt_rgb+2),a
    jp lt_pixel
lt_schema_row0:
    ld bc,80
    ld de,90
    ld a,0
    ld (lt_rgb+0),a
    ld a,0
    ld (lt_rgb+1),a
    ld a,0
    ld (lt_rgb+2),a
    jp lt_pixel
lt_schema_row1:
    ld bc,80
    ld de,103
    ld a,170
    ld (lt_rgb+0),a
    ld a,255
    ld (lt_rgb+1),a
    ld a,85
    ld (lt_rgb+2),a
    jp lt_pixel
    include "runtime_start.inc"

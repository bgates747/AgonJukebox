; Shared application body; assemble app.asm from src/asm.
    assume adl=1
    org 0x040000
    jp start
    align 64
    db "MOS",0,1

    include "mos_api.inc"
    include "macros.inc"
    include "functions.inc"
    include "arith24.inc"
    include "maths.inc"
    include "fixed168.inc"
    include "time.inc"
    include "timer.inc"
    include "vdu.inc"
    include "vdu_buffered_api.inc"
    include "vdu_fonts.inc"
    include "vdu_plot.inc"
    include "vdu_sound.inc"
    include "fpp.inc"
    include "fpp_ext.inc"
    include "browse.inc"
    include "input.inc"
    include "play.inc"
    include "sort.inc"
    include "timer_jukebox.inc"
    include "wav.inc"
    include "jukebox_cfg.inc"
    include "../../vendor/agnb/agnb_api.inc"
    include "agnb_vdu.inc"
    include "skin_assets.inc"
    include "layout.inc"
    include "ui_widgets.inc"
    if live_test_mode
    include "../../tests/asm/livecheck.inc"
    else
live_test_init:
    ret
live_test_step:
    ret
    endif

start:
    push af
    push bc
    push de
    push ix
    push iy
    call sa_skin_assets_init
    jp nz,start_failed
    call jcfg_apply_music
    jp nz,start_failed
    call live_test_init
    call bf_get_dir
    xor a
    ld (bf_file_idx),a
    call ui_init
    call ps_clear_audio_buffers
    call ps_prt_irq_init
    call get_input
    di
    call ps_close_file
    call ps_clear_audio_buffers
    ei
    call sa_restore
    ld hl,exit_message
    call sa_puts
    jp app_exit
start_failed:
    ld (sa_error_code),a
    call sa_restore
    ld hl,sa_error_text
    call sa_puts
    ld a,(sa_error_code)
    call sa_print_hex
    ld hl,sa_error_end
    call sa_puts
app_exit:
    pop iy
    pop ix
    pop de
    pop bc
    pop af
    ld hl,0
    ret
exit_message: asciz "Jukebox skin candidate closed.\r\n"
    include "files.inc"

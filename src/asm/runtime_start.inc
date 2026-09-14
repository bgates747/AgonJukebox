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
    call jcfg_load
    jr nz,@recover_config
    call rt_set_root
    call jcfg_apply_music
    jr z,rt_start_skin
    ld hl,rt_music_warning
    call sa_puts
    jr rt_start_skin
@recover_config:
    call rt_set_root
    jp rt_start_chooser
rt_start_skin:
    xor a
    ld (rt_switch),a
    ld (ps_error),a
    call sa_skin_assets_init
    jp nz,rt_start_failed
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
    call ui_shutdown
    if live_test_mode
    call live_test_shutdown
    endif
    ei
    call sa_restore
    jp nz,rt_restore_failed
    ld a,(rt_switch)
    or a
    jr nz,rt_start_chooser
    jp rt_app_exit
rt_start_failed:
    ld (sa_error_code),a
    call sa_restore
    jp nz,rt_restore_failed
    ld hl,sa_error_text
    call sa_puts
    ld a,(sa_error_code)
    call sa_print_hex
    ld hl,rt_newline
    call sa_puts
rt_start_chooser:
    call rt_choose
    jp z,rt_start_skin
    jp rt_app_exit
rt_restore_failed:
    ld hl,rt_restore_warning
    call sa_puts
rt_app_exit:
    call rt_discovery_close
    call jcfg_init
    ld hl,rt_exit_message
    call sa_puts
    pop iy
    pop ix
    pop de
    pop bc
    pop af
    ld hl,0
    ret
rt_exit_message: asciz "Jukebox closed.\r\n"
rt_restore_warning: asciz "Display restoration failed; returning to MOS.\r\n"
rt_music_warning: asciz "Music directory unavailable; using current directory.\r\n"
    include "files.inc"

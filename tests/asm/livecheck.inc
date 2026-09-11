; Real target scenarios; compiled inert in the interactive candidate.
live_test_init:
    ld a,live_test_mode
    or a
    ret z
    if skin_artdeco
    call lt_font_probe
    endif
    ld hl,lt_dir
    MOSCALL mos_cd
    or a
    jp nz,lt_fail
    MOSCALL mos_sysvars
    ld hl,(ix+sysvar_time)
    ld (lt_last_time),hl
    jp lt_timer_init

live_test_step:
    ld a,live_test_mode
    or a
    ret z
    MOSCALL mos_sysvars
    ld hl,(ix+sysvar_time)
    ld de,(lt_last_time)
    or a
    sbc hl,de
    push hl
    ld hl,0
    ld a,(lt_step)
    ld l,a
    ld de,6
    call umul24
    ld de,lt_table
    add hl,de
    ld iy,0
    push hl
    pop iy
    ld de,(iy)
    pop hl
    or a
    sbc hl,de
    ret c
    ld hl,(ix+sysvar_time)
    ld (lt_last_time),hl
    ld a,(lt_step)
    call sa_debug_hex
    ld hl,lt_newline
    call sa_debug_puts
    ld hl,(iy+3)
    ld a,(lt_step)
    inc a
    ld (lt_step),a
    jp (hl)

; Queue a test key for the independent timer. Injecting it here, before
; mos_getkey starts waiting, would test a different acquisition path.
lt_key:
    ld (lt_pending_key),a
    ret

; Test-only 60 Hz wakeups let the existing foreground assertions run while
; production waits in the real blocking MOS API. A zero key wakes but does not
; dispatch a player command. The test IRQ never renders or runs assertions.
lt_timer_init:
    di
    ld hl,lt_timer_irq
    ld e,0x0e
    MOSCALL mos_setintvector
    ld (lt_old_vector),hl
    ld hl,1200
    out0 (TMR2_CTL+TMR_RES_LOW),l
    out0 (TMR2_CTL+TMR_RES_HIGH),h
    ld a,IRQ_EN_1|PRT_MODE_1|CLK_DIV_256|RST_EN_1|PRT_EN_1
    out0 (TMR2_CTL),a
    ei
    ret

live_test_shutdown:
    xor a
    out0 (TMR2_CTL),a
    ld hl,(lt_old_vector)
    ld e,0x0e
    MOSCALL mos_setintvector
    ret

lt_timer_irq:
    di
    push af
    push bc
    push de
    push hl
    push ix
    in0 a,(TMR2_CTL)
    MOSCALL mos_sysvars
    ld a,(lt_pending_key)
    ld (ix+sysvar_keyascii),a
    xor a
    ld (lt_pending_key),a
    ld (ix+sysvar_vkeydown),1
    inc (ix+sysvar_vkeycount)
    pop ix
    pop hl
    pop de
    pop bc
    pop af
    ei
    reti.l

lt_pending_key: db 0
lt_old_vector: dl 0

lt_blue_pixel:
    if skin_artdeco
    ld a,255
    ld (lt_rgb),a
    ld a,170
    ld (lt_rgb+1),a
    ld a,85
    ld (lt_rgb+2),a
    jr lt_pixel
    else
    xor a
    ld (lt_rgb),a
    ld (lt_rgb+1),a
    ld a,170
    ld (lt_rgb+2),a
    jr lt_pixel
    endif
lt_frame_pixel:
    if skin_artdeco
    ld bc,74
    ld de,110
    ld a,255
    ld (lt_rgb),a
    ld a,170
    ld (lt_rgb+1),a
    xor a
    ld (lt_rgb+2),a
    jp lt_pixel
    else
    ld bc,502
    ld de,158
    ld a,85
    jp lt_grey_pixel
    endif
lt_grey_pixel:
    ld (lt_rgb),a
    ld (lt_rgb+1),a
    ld (lt_rgb+2),a
lt_pixel:
    ld a,c
    ld (sa_pixel_command+3),a
    ld a,b
    ld (sa_pixel_command+4),a
    ld a,e
    ld (sa_pixel_command+5),a
    ld a,d
    ld (sa_pixel_command+6),a
    MOSCALL mos_sysvars
    res 2,(ix+4)
    ld hl,sa_pixel_command
    ld bc,7
    call ui_send
    ld b,2
    call sa_wait_packet
    jp nz,lt_fail
    ld hl,lt_rgb
    ld a,(ix+0x0a)
    cp (hl)
    jp nz,lt_pixel_fail
    inc hl
    ld a,(ix+0x0b)
    cp (hl)
    jp nz,lt_pixel_fail
    inc hl
    ld a,(ix+0x0c)
    cp (hl)
    jp nz,lt_pixel_fail
    ret
lt_pixel_fail:
    if skin_artdeco
    ld hl,sa_pixel_command+3
    ld b,4
    call lt_dump
    ld hl,lt_rgb
    ld b,3
    call lt_dump
    endif
    ld a,(ix+0x0a)
    call sa_debug_hex
    ld a,(ix+0x0b)
    call sa_debug_hex
    ld a,(ix+0x0c)
    call sa_debug_hex
    jp lt_fail

lt_dump:
    ld a,(hl)
    call sa_debug_hex
    inc hl
    djnz lt_dump
    ret
lt_widget_pixels:
    ld hl,lt_samples
    ld (lt_sample_ptr),hl
    ld hl,lt_sample_count
    ld (lt_samples_left),hl
    if skin_artdeco
    call lt_check_pixels
    ld hl,lt_pixels_pass
    jp sa_debug_puts
lt_check_pixels:
    endif
@pixel:
    ld hl,(lt_sample_ptr)
    ld de,sa_pixel_command+3
    ld bc,4
    ldir
    ld de,lt_rgb
    ld bc,3
    ldir
    ld (lt_sample_ptr),hl
    MOSCALL mos_sysvars
    res 2,(ix+4)
    ld hl,sa_pixel_command
    ld bc,7
    call ui_send
    ld b,2
    call sa_wait_packet
    jp nz,lt_fail
    ld hl,lt_rgb
    ld a,(ix+0x0a)
    cp (hl)
    jp nz,lt_pixel_fail
    inc hl
    ld a,(ix+0x0b)
    cp (hl)
    jp nz,lt_pixel_fail
    inc hl
    ld a,(ix+0x0c)
    cp (hl)
    jp nz,lt_pixel_fail
    ld hl,(lt_samples_left)
    dec hl
    ld (lt_samples_left),hl
    ld de,0
    or a
    sbc hl,de
    jp nz,@pixel
    if skin_artdeco
    ret

lt_font_probe:
    ld hl,lt_font_draw
    ld bc,lt_font_draw_end-lt_font_draw
    call ui_send
    ld hl,lt_font_samples
    ld (lt_sample_ptr),hl
    ld hl,lt_font_sample_count
    ld (lt_samples_left),hl
    call lt_check_pixels
    ld hl,lt_font_pass
    jp sa_debug_puts
lt_font_pass: asciz "LIVE_FONT_PIXELS_PASS\r\n"
lt_font_draw: incbin "../../tests/fixtures/artdeco/font-probe.vdu"
lt_font_draw_end:
lt_font_samples: incbin "../../tests/fixtures/artdeco/font-samples.bin"
    else
    ld hl,lt_pixels_pass
    jp sa_debug_puts
    endif
lt_fail:
    call sa_debug_hex
    ld a,(ix+4)
    call sa_debug_hex
    ld hl,bf_dir_path
    call sa_debug_puts
    ld a,(bf_files_cur_pg)
    call sa_debug_hex
    ld a,(ps_active)
    call sa_debug_hex
    ld hl,lt_failure
    call sa_debug_puts
    ld a,(lt_step)
    call sa_debug_hex
    ld hl,lt_newline
    call sa_debug_puts
    di
    call ps_close_file
    call ui_shutdown
    call live_test_shutdown
    ei
    call sa_restore
@halt:
    jr @halt
lt_exit:
    pop hl ; discard live_test_step return to get_input
    di
    ld a,'q'
    jp input_dispatch

lt_dir: asciz "/qualification"
lt_pass: asciz "LIVE_TEST_PASS\r\n"
lt_failure: asciz "LIVE_TEST_FAIL step="
lt_schedule: asciz "SCHEDULE "
lt_newline: asciz "\r\n"
lt_last_time: dl 0
lt_saved_rows: dl 0
lt_saved_time: dl 0
lt_loop_name: db 0
lt_step: db 0
lt_rgb: db 0,0,0
lt_pixels_pass: asciz "LIVE_WIDGET_PIXELS_PASS\r\n"
lt_sample_ptr: dl 0
lt_samples_left: dl 0
    if skin_artdeco
lt_samples: incbin "../../tests/fixtures/artdeco/widget-samples.bin"
    else
lt_samples: incbin "../../tests/fixtures/skin/widget-samples.bin"
    endif
lt_table:

    dl 30,lt_case0
    dl 30,lt_case1
    dl 20,lt_case2
    dl 20,lt_case3
    dl 30,lt_case4
    dl 30,lt_case5
    dl 30,lt_case6
    dl 30,lt_case7
    dl 20,lt_case8
    dl 30,lt_case9
    dl 180,lt_case10
    dl 30,lt_case11
    dl 110,lt_case12
    dl 20,lt_case13
    dl 20,lt_case14
    dl 20,lt_case15
    dl 20,lt_case16
    dl 30,lt_case17
    dl 30,lt_case18
    dl 20,lt_case19
    dl 20,lt_case20
    dl 20,lt_case21
    dl 400,lt_case22
    dl 30,lt_case23
    dl 250,lt_case24
    dl 30,lt_case25
lt_case0:

    ld a,(bf_files_cur_pg)
    cp 2
    jp nz,lt_fail

    ld a,(ps_active)
    cp 0
    jp nz,lt_fail

    call lt_frame_pixel

    ld a,13
    call lt_key

    ret

lt_case1:

    ld a,(bf_files_cur_pg)
    cp 0
    jp nz,lt_fail

    ld a,'9'
    call lt_key

    ret

lt_case2:

    ld a,(bf_file_idx)
    cp 0
    jp nz,lt_fail

    ld a,(ps_active)
    cp 0
    jp nz,lt_fail

    ld a,'p'
    call lt_key

    ret

lt_case3:

    ld a,(ps_active)
    cp 0
    jp nz,lt_fail

    ld a,'u'
    call lt_key

    ret

lt_case4:

    ld a,(bf_files_cur_pg)
    cp 2
    jp nz,lt_fail

    ld hl,(ui_row_draws)
    ld (lt_saved_rows),hl

    ld a,10
    call lt_key

    ret

lt_case5:

    ld a,(bf_file_idx)
    cp 1
    jp nz,lt_fail

    ld hl,(ui_row_draws)
    ld de,(lt_saved_rows)
    or a
    sbc hl,de
    ld de,2
    or a
    sbc hl,de
    jp nz,lt_fail
    if skin_artdeco
    ld bc,81
    ld de,89
    else
    ld bc,10
    ld de,151
    endif
    xor a
    call lt_grey_pixel
    if skin_artdeco
    ld bc,81
    ld de,101
    else
    ld bc,10
    ld de,165
    endif
    call lt_blue_pixel

    ld a,13
    call lt_key

    ret

lt_case6:

    ld a,(bf_files_cur_pg)
    cp 10
    jp nz,lt_fail

    ld a,(bf_dir_num_pages)
    cp 2
    jp nz,lt_fail

    ld a,21
    call lt_key

    ret

lt_case7:

    ld a,(bf_page_cur)
    cp 1
    jp nz,lt_fail

    ld a,(bf_files_cur_pg)
    cp 2
    jp nz,lt_fail

    ld a,'9'
    call lt_key

    ret

lt_case8:

    ld a,(bf_file_idx)
    cp 0
    jp nz,lt_fail

    ld a,8
    call lt_key

    ret

lt_case9:

    ld a,(bf_page_cur)
    cp 0
    jp nz,lt_fail

    ld a,(bf_files_cur_pg)
    cp 10
    jp nz,lt_fail

    ld a,'0'
    call lt_key

    ret

lt_case10:

    ld a,(ps_active)
    cp 1
    jp nz,lt_fail

    ld a,(ps_song_duration)
    cp 4
    jp nz,lt_fail

    ld a,(ps_playhead)
    or a
    jp z,lt_fail
    ld a,(ps_mode)
    and 1
    jp z,lt_fail
    call lt_frame_pixel

    ld a,'p'
    call lt_key

    ret

lt_case11:

    ld a,(ps_mode)
    cp 0
    jp nz,lt_fail

    ld hl,(ps_playhead)
    ld (lt_saved_time),hl
    ld hl,lt_schedule
    call sa_debug_puts
    ld hl,ps_playhead
    ld b,3
    call lt_dump
    ld hl,ps_wav_chunk_counter
    ld b,1
    call lt_dump
    ld hl,ps_wav_bytes_remaining
    ld b,4
    call lt_dump
    ld hl,lt_newline
    call sa_debug_puts

    ret

lt_case12:

    ld hl,(ps_playhead)
    ld de,(lt_saved_time)
    or a
    sbc hl,de
    jp nz,lt_fail

    ld a,','
    call lt_key

    ret

lt_case13:

    ld a,(ps_volume)
    cp 10
    jp nz,lt_fail

    ld a,'s'
    call lt_key

    ret

lt_case14:

    ld a,(ps_mode)
    cp 4
    jp nz,lt_fail

    ld a,'l'
    call lt_key

    ret

lt_case15:

    ld a,(ps_mode)
    cp 6
    jp nz,lt_fail

    ld a,(w_shuffle_code)
    cp art_shuffle_on
    jp nz,lt_fail

    ld a,(w_loop_code)
    cp art_loop_on
    jp nz,lt_fail

    ld a,'='
    call lt_key

    ret

lt_case16:

    ld a,(ps_seek_rate)
    cp 5
    jp nz,lt_fail

    call lt_widget_pixels

    ld a,']'
    call lt_key

    ret

lt_case17:

    ld a,(ps_active)
    cp 1
    jp nz,lt_fail

    ld a,(ps_mode)
    cp 6
    jp nz,lt_fail

    ld a,(ps_playhead)
    or a
    jp z,lt_fail
    cp 5
    jp nc,lt_fail

    ld a,10
    call lt_key

    ret

lt_case18:

    ld a,(bf_file_idx)
    cp 1
    jp nz,lt_fail

    ld a,(ps_filinfo_fname+1)
    cp '0'
    jp nz,lt_fail

    ld a,(w_track_text+9)
    cp '0'
    jp nz,lt_fail

    ld a,11
    call lt_key

    ret

lt_case19:

    ld a,(bf_file_idx)
    cp 0
    jp nz,lt_fail

    ld a,'l'
    call lt_key

    ret

lt_case20:

    ld a,(ps_mode)
    cp 4
    jp nz,lt_fail

    ld a,'s'
    call lt_key

    ret

lt_case21:

    ld a,(ps_mode)
    cp 0
    jp nz,lt_fail

    ld a,'p'
    call lt_key

    ret

lt_case22:

    ld a,(ps_active)
    cp 1
    jp nz,lt_fail

    ld a,(ps_filinfo_fname+1)
    cp '0'
    jp z,lt_fail
    call lt_frame_pixel
    ld a,(sa_mode_changed)
    cp 1
    jp nz,lt_fail

    ld a,'l'
    call lt_key

    ret

lt_case23:

    ld a,(ps_mode)
    cp 3
    jp nz,lt_fail

    ld a,(ps_filinfo_fname+1)
    ld (lt_loop_name),a

    ld a,'s'
    call lt_key

    ret

lt_case24:

    ld a,(ps_mode)
    cp 7
    jp nz,lt_fail

    ld a,(ps_filinfo_fname+1)
    ld hl,lt_loop_name
    cp (hl)
    jp nz,lt_fail

    ld a,'r'
    call lt_key

    ret

lt_case25:

    ld a,(ps_active)
    cp 1
    jp nz,lt_fail

    ld a,(ps_filinfo_fname+1)
    ld hl,lt_loop_name
    cp (hl)
    jp z,lt_fail
    ld hl,lt_pass
    call sa_debug_puts
    jp lt_exit

    ret

    if skin_artdeco
    include "../ui/artdeco/test-meta.inc"
    else
lt_sample_count: equ 1327
    endif

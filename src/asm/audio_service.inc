; Foreground WAV service using only standard MOS services and VDU output.
; No experimental UART discovery, session, policy, descriptor or transmit API.
; PRT1 posts due work; foreground services audio, UI, keys, then optional DSP.
fg_reset:
    xor a
    ld (fg_due),a
    ld (fg_overflow),a
    MOSCALL mos_sysvars
    ld (fg_sysvars),ix
    ret
fg_begin:
    if fg_audio-2
    else
    ld hl,er_sessions
    call sp_inc32
    endif
    ld ix,(fg_sysvars)
    ld a,(ix+sysvar_vkeycount)
    ld (fg_keycount),a
    xor a
    ld (fg_due),a
    ret
fg_irq_init:
    ld hl,fg_irq
    ld e,0x0c
    MOSCALL mos_setintvector
    ld (fg_old_vector),hl
    ret
fg_irq:
    di
    push af
    push hl
    in0 a,(TMR1_CTL+TMR_REG_CTL)
    ld a,(ps_mode)
    bit ps_mode_playing,a
    jr z,@done
    ld hl,fg_due
    ld a,(hl)
    cp 255
    jr z,@overflow
    inc (hl)
    jr @done
@overflow:
    ld a,1
    ld (fg_overflow),a
@done:
    pop hl
    pop af
    ei
    reti.l
fg_input:
    ei
    if fg_audio-2
    else
    ld a,(fg_due)
    ld hl,er_due_high
    cp (hl)
    jr c,@high_ready
    ld (hl),a
@high_ready:
    call er_poll
    jr z,@released
    call er_compute
    jr fg_input
@released:
    endif
    di
    ld a,(fg_due)
    or a
    jr z,@no_tick
    dec a
    ld (fg_due),a
    ei
    if fg_audio-2
    else
    ld hl,er_served
    call sp_inc32
    endif
    ld a,(ps_mode)
    bit ps_mode_playing,a
    jr z,@draw
    if pcm_spectrum
    call sp_tick
    endif
    call ps_read_sample
    if fg_audio-2
    jr @draw
    else
    jp fg_input ; pending upload must finish before any UI/keyboard output
    endif
@no_tick:
    ei
@draw:
    call ui_flush
    di
    ld ix,(fg_sysvars)
    ld a,(ix+sysvar_vkeycount)
    ld hl,fg_keycount
    cp (hl)
    jr z,@none
    ld (hl),a
    ld a,(ix+sysvar_vkeydown)
    or a
    jr z,@none
    ld a,(ix+sysvar_keyascii)
    ei
    jp input_dispatch
@none:
    ei
    if pcm_spectrum
    call sp_service
    endif
    jr fg_input
fg_finish:
    if fg_audio-2
    else
    call er_wait
    endif
    call ps_prt_stop
    ld hl,(fg_old_vector)
    ld e,0x0c
    MOSCALL mos_setintvector
    if fg_audio-2
    else
    ld de,fg_irq
    or a
    sbc hl,de
    jr nz,@different_owner
    ld hl,er_restored
    call sp_inc32
    jr @report
@different_owner:
    ld a,0xe4
    ld (er_error),a
@report:
    call er_report
    endif
    ret
fg_ready_message: asciz "JUKEBOX_READY\r\n"
fg_due: db 0
fg_overflow: db 0
fg_keycount: db 0
fg_sysvars: dl 0
fg_old_vector: dl 0

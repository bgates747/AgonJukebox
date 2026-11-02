; UART-001 first prototype. Foreground only, default per-byte CTS, one borrowed
; complete packet. Graphics retain MOS's ordered synchronous compatibility path.
; All named pointer/count RAM fields below are dl (ADL 24-bit), metrics dw32.
; Packet RAM is beyond WAV staging and inside the MOS API's application range.
ua_packet: equ 0x092000
ua_capacity: equ 2048

ua_reset:
    xor a
    ld (ua_state),a
    ld hl,ua_state
    ld de,ua_state+1
    ld bc,ua_state_end-ua_state-1
    ldir
    ld (ua_stats_data),a
    ld hl,ua_stats_data
    ld de,ua_stats_data+1
    ld bc,ua_stats_end-ua_stats_data-1
    ldir
    MOSCALL mos_sysvars
    ld (ua_sysvars),ix
    ld a,(ix+sysvar_vkeycount)
    ld (ua_keycount),a
    ld hl,(ix+sysvar_time)
    ld (ua_started),hl
    ret

ua_begin:
    ei
    ld ix,(ua_sysvars)
    ld a,(ix+sysvar_vkeycount)
    ld (ua_keycount),a
    xor a
    ld (ua_effective),a
    ld b,0x13
    ld c,0
    ld a,0x50
    rst.lil 0x08
    or a
    ret nz
    ld de,0
    or a
    sbc hl,de
    ret z
    call ua_jump_hl
    push hl
    pop ix
    ld a,(ix+0)
    cp 'U'
    ret nz
    ld a,(ix+1)
    cp 'T'
    ret nz
    ld a,(ix+2)
    cp 'X'
    ret nz
    ld a,(ix+3)
    cp '1'
    ret nz
    ld a,(ix+4)
    cp 1
    ret nz
    ld a,(ix+5)
    cp 2
    ret c
    ld a,(ix+6)
    cp 54
    ret c
    bit 3,(ix+7)
    ret z
    bit 0,(ix+52)
    ret z
    ld hl,(ix+13)
    ld (ua_open+1),hl
    ld hl,(ix+16)
    ld (ua_reserve+1),hl
    ld hl,(ix+19)
    ld (ua_publish+1),hl
    ld hl,(ix+22)
    ld (ua_status+1),hl
    ld hl,(ix+25)
    ld (ua_cancel+1),hl
    ld hl,(ix+28)
    ld (ua_reap+1),hl
    ld hl,(ix+31)
    ld (ua_drain+1),hl
    ld hl,(ix+34)
    ld (ua_close+1),hl
    ld hl,(ix+49)
    ld (ua_get_batch+1),hl
    ld a,1
    ld (ua_capable),a
    ld ix,(ua_sysvars)
    ld hl,(ix+sysvar_time)
    ld (ua_open_time),hl
@open:
    call ua_open
    ld (ua_open_status),a
    or a
    jr z,@opened
    cp 1
    ret nz
    ld hl,ua_busy
    call ua_inc32
    ld ix,(ua_sysvars)
    ld hl,(ix+sysvar_time)
    ld de,(ua_open_time)
    or a
    sbc hl,de
    ld de,200
    or a
    sbc hl,de
    ret nc
    nop ; first prototype keeps foreground polling interruptible
    jr @open
@opened:
    ld a,1
    ld (ua_active),a
    call ua_get_batch
    or a
    jp nz,ua_fail
    ld a,b
    cp 1
    ld a,2
    jp nz,ua_fail
    ld a,1
    ld (ua_effective),a
    ret

ua_jump_hl:
    jp (hl)
; Patching JP's exact three-byte operand avoids corrupting publish arguments.
ua_open:    jp 0
ua_reserve: jp 0
ua_publish: jp 0
ua_status:  jp 0
ua_cancel:  jp 0
ua_reap:    jp 0
ua_drain:   jp 0
ua_close:   jp 0
ua_get_batch: jp 0

ua_irq_init:
    ld hl,ua_irq
    ld e,0x0c
    MOSCALL mos_setintvector
    ld (ua_old_vector),hl
    ret

ua_irq:
    di
    push af
    push hl
    in0 a,(TMR1_CTL+TMR_REG_CTL)
    ld hl,ua_ticks
    call ua_inc32
    ld a,(ps_mode)
    bit ps_mode_playing,a
    jr z,@done
    ld a,(ua_due)
    cp 255
    jr nz,@post
    ld hl,ua_overflows
    call ua_inc32
    jr @done
@post:
    inc a
    ld (ua_due),a
    ld hl,ua_highwater
    cp (hl)
    jr c,@done
    ld (hl),a
@done:
    pop hl
    pop af
    ei
    reti.l

; The only timer producer changes due/ticks. All SD, VDU and async work runs
; here with interrupts enabled. Check keys after every feed, even during catchup.
ua_input:
    ei
    call ua_poll
    ld a,(ua_abort)
    or a
    ret nz
    di
    ld a,(ua_due)
    or a
    jr z,@no_tick
    dec a
    ld (ua_due),a
    ei
    ld a,(ps_mode)
    bit ps_mode_playing,a
    jr z,@draw
    ld hl,ua_served
    call ua_inc32
    call ps_read_sample
    jr @draw
@no_tick:
    ei
@draw:
    call ui_flush
    di
    ld ix,(ua_sysvars)
    ld a,(ix+sysvar_vkeycount)
    ld hl,ua_keycount
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
    ; A polling prototype avoids a lost wakeup between sampling key state and
    ; sleeping; retain interruptible foreground service even while idle.
    jr ua_input

; HL -> four-byte little-endian counter. AF/HL scratch only; usable in IRQ.
ua_inc32:
    inc (hl)
    ret nz
    inc hl
    inc (hl)
    ret nz
    inc hl
    inc (hl)
    ret nz
    inc hl
    inc (hl)
    ret

; Add unsigned DE24 to a u32 counter at HL. AF/BC/DE/HL scratch.
ua_add32:
    ld bc,(hl)
    ex de,hl
    add hl,bc
    ex de,hl
    ld (hl),de
    ret nc
    inc hl
    inc hl
    inc hl
    inc (hl)
    ret

ua_poll:
    ei
    ld de,(ua_ticket)
    ld hl,0
    or a
    sbc hl,de
    ret z
    call ua_status
    or a
    jp nz,ua_fail
    ld a,b
    cp 4
    ret nz
    ld de,(ua_ticket)
    call ua_reap
    or a
    jp nz,ua_fail
    ld hl,0
    ld (ua_ticket),hl
    ld hl,ua_released
    jp ua_inc32

ua_wait:
    call ua_poll
    ld a,(ua_abort)
    or a
    ret nz
    ld hl,(ua_ticket)
    ld de,0
    or a
    sbc hl,de
    ret z
    ld hl,ua_waits
    call ua_inc32
    ei
    nop ; first prototype keeps foreground polling interruptible
    jr ua_wait

ua_upload:
    ld (ua_source),de
    ld (ua_length),bc
    ld (ua_buffer),hl
    ei
    call ua_wait
    ld a,(ua_abort)
    or a
    ret nz
    ld hl,(ua_length)
    ld de,0
    or a
    sbc hl,de
    ld a,2
    jp z,ua_fail
    ld hl,ua_capacity-8
    ld de,(ua_length)
    or a
    sbc hl,de
    ld a,2
    jp c,ua_fail
    ld hl,(ua_source)
    ld de,ua_packet+8
    ld bc,(ua_length)
    ldir
    ld hl,ua_packet
    ld (hl),23
    inc hl
    ld (hl),0
    inc hl
    ld (hl),0xa0
    inc hl
    ld de,(ua_buffer)
    ld (hl),e
    inc hl
    ld (hl),d
    inc hl
    ld (hl),0
    inc hl
    ld de,(ua_length)
    ld (hl),e
    inc hl
    ld (hl),d
@reserve:
    call ua_reserve
    or a
    jr z,@reserved
    cp 1
    jp nz,ua_fail
    ld hl,ua_busy
    call ua_inc32
    ei
    nop ; first prototype keeps foreground polling interruptible
    jr @reserve
@reserved:
    ld (ua_ticket),hl
    ld a,1
    ld (ua_reserved),a
@publish:
    ld de,(ua_ticket)
    ld hl,ua_packet
    ld bc,(ua_length)
    inc bc
    inc bc
    inc bc
    inc bc
    inc bc
    inc bc
    inc bc
    inc bc
    call ua_publish
    or a
    jr z,@published
    cp 1
    jp nz,ua_fail
    ld hl,ua_busy
    call ua_inc32
    ei
    nop ; first prototype keeps foreground polling interruptible
    jr @publish
@published:
    xor a
    ld (ua_reserved),a
    ld hl,ua_packets
    call ua_inc32
    ld de,(ua_length)
    ld hl,ua_payload
    call ua_add32
    ld de,(ua_length)
    ld hl,8
    add hl,de
    ex de,hl
    ld hl,ua_submitted
    jp ua_add32

ua_fail:
    ld (ua_error),a
    ld a,1
    ld (ua_abort),a
    ret

ua_finish:
    ei
    call ps_prt_stop
    ld a,(ua_active)
    or a
    jr z,@restore
    ld a,(ua_reserved)
    or a
    jr z,@wait
    ld de,(ua_ticket)
    call ua_cancel
    or a
    jr nz,@close_error
    ld de,(ua_ticket)
    call ua_reap
    or a
    jr nz,@close_error
    ld hl,0
    ld (ua_ticket),hl
    xor a
    ld (ua_reserved),a
@wait:
    ; Ignore the abort request for teardown: borrowed storage remains protected.
    call ua_poll
    ld hl,(ua_ticket)
    ld de,0
    or a
    sbc hl,de
    jr z,@drain
    nop ; first prototype keeps foreground polling interruptible
    jr @wait
@drain:
    call ua_drain
    or a
    jr z,@close
    cp 1
    jr nz,@close_error
    nop ; first prototype keeps foreground polling interruptible
    jr @drain
@close:
    call ua_close
    or a
    jr nz,@close_error
    xor a
    ld (ua_active),a
@restore:
    ld hl,(ua_old_vector)
    ld e,0x0c
    MOSCALL mos_setintvector
    ld ix,(ua_sysvars)
    ld hl,(ix+sysvar_time)
    ld de,(ua_started)
    or a
    sbc hl,de
    ld (ua_elapsed),hl
    jp ua_report
@close_error:
    ld (ua_error),a
    ; Do not free borrowed RAM or claim safe return after a failed teardown.
    ei
    nop ; first prototype keeps foreground polling interruptible
    jr @drain

; Snapshot is written only after audio has stopped and async has closed.
; No continuous logging or UART0 telemetry in the playing path.
ua_report:
    ld hl,ua_report_name
    ld c,fa_write|fa_create_always
    MOSCALL mos_fopen
    or a
    jr z,@failed
    ld (ua_report_handle),a
    ld c,a
    ld hl,ua_stats
    ld de,ua_stats_end-ua_stats
    MOSCALL mos_fwrite
    ld hl,ua_stats_end-ua_stats
    or a
    sbc hl,de
    jr z,@close
    ld a,1
    ld (ua_report_failed),a
@close:
    ld a,(ua_report_handle)
    ld c,a
    MOSCALL mos_fclose
    ret
@failed:
    ld a,1
    ld (ua_report_failed),a
    ret

ua_print_result:
    ld hl,ua_sync_message
    ld a,(ua_effective)
    or a
    jr z,@message
    ld hl,ua_async_message
@message:
    call sa_puts
    ld a,(ua_error)
    call sa_print_hex
    ld hl,ua_result_end
    call sa_puts
    ld a,(ua_report_failed)
    or a
    ret z
    ld hl,ua_report_warning
    jp sa_puts
ua_report_name: asciz "/JUART.DAT"
ua_ready_message: asciz "UART_PROTO_READY\r\n"
ua_sync_message: asciz "UART prototype: synchronous fallback; status "
ua_async_message: asciz "UART prototype: async CTS1; status "
ua_result_end: asciz ". Metrics: /JUART.DAT\r\n"
ua_report_warning: asciz "Metrics file could not be written completely.\r\n"

ua_state:
ua_active: db 0
ua_abort: db 0
ua_reserved: db 0
ua_due: db 0
ua_keycount: db 0
ua_report_handle: db 0
ua_report_failed: db 0
ua_sysvars: dl 0
ua_started: dl 0
ua_open_time: dl 0
ua_old_vector: dl 0
ua_ticket: dl 0
ua_source: dl 0
ua_length: dl 0
ua_buffer: dl 0
ua_state_end:

; Binary result schema: magic4/version1, five u8 fields, elapsed u24, nine u32.
ua_stats: db "JUA1",1
ua_stats_data:
ua_effective: db 0 ; 0 foreground synchronous fallback, 1 async CTS1
ua_capable: db 0
ua_open_status: db 0
ua_error: db 0
ua_highwater: db 0
ua_elapsed: dl 0 ; MOS centiseconds modulo 2^24
ua_ticks: dw32 0
ua_served: dw32 0
ua_overflows: dw32 0
ua_busy: dw32 0
ua_waits: dw32 0
ua_packets: dw32 0
ua_released: dw32 0
ua_payload: dw32 0
ua_submitted: dw32 0
ua_stats_end:

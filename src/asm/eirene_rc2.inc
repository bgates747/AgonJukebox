; UART-003: Eirene UART0 RC2, Tom Morton / upstream MOS contributors.
; Published tag 3.1.0_uart0_rc_2, source825eaf7; see docs/eirene-rc2-test.md.
; One immutable complete packet. MOS owns TX/CTS interrupts; no direct UART IO.
; Foreground ADL1/MBASE0/EI, normal UART0 and sole writer are preconditions.
er_packet: equ 0x092000 ; separate from WAV staging and analyzer0x094000
er_capacity: equ 2048

; Firmware identity is checked by deployment tooling, never by application ROM
; bytes. The same binary uses RC2 APIs on published MOS and EMOS Legacy.
; Require compatible42h/43h services before invoking this opt-in test app.
er_init:
    xor a
    ld (er_active),a
    ld (er_done),a
    ld hl,er_stats+5
    ld de,er_stats+6
    ld bc,er_stats_end-er_stats-6
    ld (hl),a
    ldir
    ld a,1
    ld (er_transport),a ; selected RC2 transport, NOT a firmware attestation
    ret

; A=0/Z: no outstanding source or wire tail; A=1/NZ: still borrowed/busy.
; Success restores stock UART0 RX before any ordinary output may execute.
er_poll:
    ld a,(er_active)
    or a
    ret z
    MOSCALL 0x43
    or a
    jr z,@finished
    cp 1
    jp nz,er_fault
    ld hl,er_busy
    call sp_inc32
    ld a,1
    or a
    ret
@finished:
    ld a,(er_done)
    or a
    ld a,0xe1
    jp z,er_fault ; accepted callback must have completed before finish succeeds
    xor a
    ld (er_active),a
    ld hl,er_finished
    call sp_inc32
    xor a
    ret

; The existing service's compute path is output-free while pb_active is1.
; IRQs/callbacks never change pb_active. Never enter its renderer while borrowed.
er_compute:
    ld a,(pb_active)
    or a
    ret z
    ld a,(fg_due)
    or a
    ret nz
    ld hl,er_work
    call sp_inc32
    jp sp_service
er_wait:
    call er_poll
    ret z
    call er_compute
    jr er_wait

; HL=VDP buffer ID, DE=PCM, BC=count. Same eight-byte buffered-write header as
; vdu_load_buffer, followed by exact PCM. Only this packet uses async output.
er_upload:
    push hl
    push de
    push bc
    call er_wait
    pop bc
    pop de
    pop hl
    ld (er_header_id),hl
    xor a
    ld (er_header_id+2),a
    ld (er_header_length),bc
    ld (er_length),bc
    ld (er_source),de
    ld hl,er_capacity-8
    or a
    sbc hl,bc
    ld a,0xe2
    jp c,er_fault
    ld hl,er_header
    ld de,er_packet
    ld bc,8
    ldir
    ld hl,(er_source)
    ld de,er_packet+8
    ld bc,(er_length)
    ldir
    xor a
    ld (er_done),a ; arm BEFORE submit: callback may precede next instruction
    inc a
    ld (er_active),a
    ld hl,(er_length)
    ld de,8
    add hl,de
    push hl
    pop bc
    ld hl,er_packet
    ld de,er_callback
    MOSCALL 0x42
    or a
    jp nz,er_fault
    ld hl,er_submitted
    call sp_inc32
    ld hl,(er_payload)
    ld de,(er_length)
    add hl,de
    ld (er_payload),hl
    ld a,(er_payload+3)
    adc a,0
    ld (er_payload+3),a
    ret
er_callback:
    ; MOS ISR saves AF/BC/DE/HL. This raw callback touches no indexes/shadows.
    ld a,1
    ld (er_done),a
    ld hl,er_callbacks
    jp sp_inc32

; Never return/free uncertain borrowed storage or print into an unfinished
; packet on a contract fault. The finite host fixture times out and retains it.
er_fault:
    ld (er_error),a
@hold:
    ei
    halt
    jr @hold

; Fixed48-byte report, written only after session teardown/finish, no callback.
er_report:
    call er_wait
    ld a,(fg_overflow)
    or a
    jr z,@open
    ld a,0xe3
    ld (er_error),a
@open:
    ld hl,er_report_name
    ld c,fa_write|fa_create_always
    MOSCALL mos_fopen
    or a
    ret z
    ld (er_handle),a
    ld c,a
    ld hl,er_stats
    ld de,er_stats_end-er_stats
    MOSCALL mos_fwrite
    ld a,(er_handle)
    ld c,a
    MOSCALL mos_fclose
    ret
er_active: db 0
er_done: db 0
er_handle: db 0
er_length: dl 0
er_source: dl 0
er_report_name: asciz "/JRC2.DAT"
er_header: db 23,0,0xa0
er_header_id: dw 0
    db 0
er_header_length: dw 0
    db 0 ; absorbs ADL store; not part of header
er_stats: db "JRC2",2
er_transport: db 0
er_error: db 0
er_due_high: db 0
er_submitted: dw32 0
er_callbacks: dw32 0
er_payload: dw32 0
er_busy: dw32 0
er_work: dw32 0
er_finished: dw32 0
er_barriers: dw32 0
er_served: dw32 0
er_sessions: dw32 0
er_restored: dw32 0
er_stats_end:

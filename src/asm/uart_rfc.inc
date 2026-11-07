; UART-004: Tom Morton / upstream RFC ffab9c9, syscall25h.
; Shared er_* seam intentionally preserves the RC2 scheduler implementation.
; See docs/uart-rfc-test.md. No42h/43h calls; no RC2 status semantics.
; One immutable positive-length packet. MOS owns TX; client only observes LSR.
; Foreground ADL1/MBASE0/EI, normal UART0 and sole writer are preconditions.
er_packet: equ 0x092000 ; separate from WAV staging and analyzer0x094000
er_capacity: equ 2048

; Installation must provide the RFC25h ABI. Firmware identity belongs to
; deployment qualification, as with the common RC2 client. No per-ROM variant.
; Actual MBASE0 is required because this RFC selects callback mode from MB.
er_init:
    call rfc_guard
    ret nz
    xor a
    ld (er_active),a
    ld (er_done),a
    ld hl,er_stats+5
    ld de,er_stats+6
    ld bc,er_stats_end-er_stats-6
    ld (hl),a
    ldir
    ld a,0x25
    ld (er_transport),a ; selected syscall; not a performance measurement
    xor a
    ret

; A=0/Z: source callback observed and local UART TEMT; no receiver ack.
; Callback has returned through firmware ISR before foreground resumes here.
er_poll:
    ld a,(er_active)
    or a
    ret z
    ld a,(er_done)
    or a
    jr z,@busy
    in0 a,(0xc5) ; UART0 LSR: observe only, never write UART control state
    bit 6,a
    jr z,@tail
    xor a
    ld (er_active),a
    ld hl,er_callbacks ; account observed flag once, outside callback
    call sp_inc32
    ld hl,er_finished ; local drain barriers, NOT a finish syscall count
    call sp_inc32
    xor a
    ret
@tail:
    ld hl,rfc_tail_polls
    call sp_inc32
@busy:
    ld hl,er_busy
    call sp_inc32
    ld a,1
    or a
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
    push hl
    ld hl,0
    or a
    sbc hl,bc
    pop hl
    ld a,0xe5
    jp z,er_fault ; never expose RFC zero-count OTIRX behavior
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
    MOSCALL 0x25
    ; RFC does not implement its documented A=0 return; do not interpret it.
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
    ret ; flag only, touches AF; indexes/alternate context untouched

; Never return/free uncertain borrowed storage or print into an unfinished
; packet on a contract fault. The finite host fixture times out and retains it.
er_fault:
    ld (er_error),a
@hold:
    ei
    halt
    jr @hold

; Fixed52-byte report, written only after session teardown/finish, no callback.
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
er_report_name: asciz "/JRFC.DAT"
er_header: db 23,0,0xa0
er_header_id: dw 0
    db 0
er_header_length: dw 0
    db 0 ; absorbs ADL store; not part of header
er_stats: db "JRFC",1
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
rfc_tail_polls: dw32 0
er_stats_end:

rfc_guard:
    ld a,mb
    or a
    ret ; Z only for the supported ADL1/MBASE0 execution environment
rfc_refuse:
    ; start saved these registers; no config, display, timer or packet touched.
    pop iy
    pop ix
    pop de
    pop bc
    pop af
    ld hl,1
    ret

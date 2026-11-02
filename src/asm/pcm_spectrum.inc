; AUD-001 experimental PCM visualization.
; Paced, incremental changed-column rendering follows the approach in agonAMP
; by Nick J. Date (Pollito / SanPollo), src/spectrum.asm, tag1.1 91ef401.
; This implementation is independently written for bitmap skins; its PCM
; filter bank is independent of agonAMP's AY tone/harmonic estimates.
; Attribution and upstream license are in docs/pcm-spectrum.md.
    include "pcm_bands.inc"
sp_init:
    xor a
    ld (sp_enabled),a
    ld (sp_want),a
    ld (sp_loaded),a
    ld (sp_error),a
    ld hl,sp_stats_data
    ld de,sp_stats_data+1
    ld bc,sp_stats_end-sp_stats_data-1
    ld (hl),a
    ldir
    call sp_clear
    ld hl,sp_desc_leaf
    call sa_join_asset
    ret nz
    ld bc,16
    call sa_read_small
    ret nz ; absent optional descriptor: static artwork, no DSP
    ld hl,(sa_small_count)
    ld de,16
    or a
    sbc hl,de
    jp nz,sp_bad
    ld hl,sa_small_data
    ld de,sp_magic
    ld b,4
@magic:
    ld a,(de)
    cp (hl)
    jp nz,sp_bad
    inc de
    inc hl
    djnz @magic
    ld ix,sa_small_data+4
    call rt_word
    ld (sp_x),hl
    call rt_word
    ld (sp_y),hl
    ld a,(sa_small_data+8)
    cp 26
    jp c,sp_bad
    cp 52
    jp nc,sp_bad
    ld (sp_pitch),a
    ld de,0
    ld e,a
    ld d,9
    mlt de
    ld hl,(sp_x)
    add hl,de
    ld de,26
    add hl,de
    ld de,513
    or a
    sbc hl,de
    jp nc,sp_bad
    ld hl,(sp_y)
    ld de,344
    or a
    sbc hl,de
    jp nc,sp_bad
    ld hl,sa_small_data+9
    ld de,sp_scalars
    ld b,7
@scalars:
    ld a,(de)
    cp (hl)
    jp nz,sp_bad
    inc hl
    inc de
    djnz @scalars
    ld hl,sp_assets_leaf
    call sa_join_asset
    jp nz,sp_bad
    ld a,1
    ld (sp_loaded),a
    ld hl,sp_image_meta
    ld a,7
    call sa_load_agnb_images
    jp nz,sp_bad
    ld a,1
    ld (sp_enabled),a
    ld (sp_want),a
    ld hl,sp_ready
    call sa_debug_puts
    ret
sp_bad:
    ld a,0x62
    ld (sp_error),a
    ld hl,sp_failed
    jp sa_debug_puts

; Clear only visualization state. Called on track/seek/close, never by IRQ.
sp_clear:
    xor a
    ld (pb_active),a
    ld (sp_collecting),a
    ld (sp_wait_boundary),a
    ld (sp_count),a
    ld (sp_count+1),a
    ld (sp_count+2),a
    ld (sp_cooldown),a
    ld (sp_build_tick),a
    ld (sp_play_tick),a
    ld (sp_frame),a
    ld hl,sp_build
    ld de,sp_build+1
    ld bc,210-1 ; build100 + play100 + target10
    ld (hl),a
    ldir
    ld a,255
    ld (sp_last_frame),a
    ld hl,sp_shown
    ld b,10
@shown:
    ld (hl),255
    inc hl
    djnz @shown
    xor a
    ld (sp_next),a
    ld hl,sp_valid
    ld de,sp_valid+1
    ld bc,19 ; valid10 + fill10
    ld (hl),a
    ldir
    ret

; One call per playing audio feed tick. Pause does not advance the display.
sp_tick:
    ld a,(sp_want)
    or a
    ret z
    ld hl,sp_build_tick
    ld a,(hl)
    cp 60
    jr nc,@cooldown
    inc (hl)
@cooldown:
    ld hl,sp_cooldown
    ld a,(hl)
    or a
    jr z,@play
    dec (hl)
@play:
    ld a,(sp_play_tick)
    inc a
    cp 6
    jr c,@save
    xor a
    ld hl,sp_frame
    ld c,a
    ld a,(hl)
    cp 9
    jr nc,@restore
    inc (hl)
@restore:
    ld a,c
@save:
    ld (sp_play_tick),a
    ret

; Capture contiguous bytes only after their unchanged packet was submitted.
; BC=actual PCM count, DE=source. A 1024-byte window at most once per6 ticks.
sp_capture:
    ld a,(sp_want)
    or a
    ret z
    ld a,(sp_wait_boundary)
    or a
    ret nz
    ld a,(pb_active)
    or a
    ret nz
    ld a,(sp_collecting)
    or a
    jr nz,@copy
    ld a,(sp_cooldown)
    or a
    ret nz
    ld a,6
    ld (sp_cooldown),a
    ld a,(sp_build_tick)
    dec a
    ld l,0
@frame:
    cp 6
    jr c,@got_frame
    sub 6
    inc l
    jr @frame
@got_frame:
    ld a,l
    cp 10
    ret nc
    ld (sp_job_frame),a
    ld hl,0
    ld (sp_count),hl
    ld a,1
    ld (sp_collecting),a
@copy:
    ld (sp_source),de
    ld (sp_length),bc
    ld hl,1024
    ld de,(sp_count)
    or a
    sbc hl,de
    ld de,(sp_length)
    or a
    sbc hl,de
    jr nc,@length
    ld hl,1024
    ld de,(sp_count)
    or a
    sbc hl,de
    ld (sp_length),hl
@length:
    ld hl,pb_window
    ld de,(sp_count)
    add hl,de
    ex de,hl
    ld hl,(sp_source)
    ld bc,(sp_length)
    ldir
    ld hl,(sp_count)
    ld de,(sp_length)
    add hl,de
    ld (sp_count),hl
    ld de,1024
    or a
    sbc hl,de
    ret nz
    xor a
    ld (sp_collecting),a
    jp pb_start

; Snapshot analyzed envelopes when this VDP sample is commanded to play.
; Incomplete/stale jobs are dropped, not allowed to delay the sound handoff.
sp_on_play:
    ld a,(sp_enabled)
    or a
    ret z
    ld a,(pb_active)
    ld b,a
    ld a,(sp_collecting)
    or b
    jr z,@copy
    ld hl,sp_skipped
    call sp_inc32
@copy:
    call sp_fill_gaps
    ld hl,sp_build
    ld de,sp_play
    ld bc,100
    ldir
    xor a
    ld hl,sp_build
    ld de,sp_build+1
    ld bc,99
    ld (hl),a
    ldir
    ld (pb_active),a
    ld (sp_collecting),a
    ld hl,0
    ld (sp_count),hl
    ld (sp_build_tick),a
    ld (sp_play_tick),a
    ld (sp_frame),a
    ld (sp_cooldown),a
    ld (sp_wait_boundary),a
    ld hl,sp_valid
    ld de,sp_valid+1
    ld bc,19
    ld (hl),a
    ldir
    ld a,255
    ld (sp_last_frame),a
    ret

; Low-rate files can yield fewer than10 complete windows per second. Hold the
; latest measured envelope in unmeasured slots; explicit silence remains zero.
sp_fill_gaps:
    ld hl,sp_build
    ld ix,sp_valid
    ld b,10
@slot:
    push bc
    push hl
    ld de,sp_fill
    ld a,(ix+0)
    inc ix
    or a
    jr z,@hold
    ld bc,10
    ldir
    jr @next
@hold:
    ld b,10
@byte:
    ld a,(de)
    ld (hl),a
    inc de
    inc hl
    djnz @byte
@next:
    pop hl
    ld de,10
    add hl,de
    pop bc
    djnz @slot
    ret

; Called after key polling. A due audio tick always preempts optional work.
; One slice <=32 pairs OR one changed column (16 UART bytes), never both.
sp_service:
    ld a,(sp_enabled)
    or a
    ret z
    ld a,(fg_due)
    or a
    ret nz
    ld a,(pb_active)
    or a
    jr z,@display
    ld hl,sp_steps
    call sp_inc32
    call pb_step
    ld a,(pb_active)
    or a
    ret nz
    ld hl,sp_windows
    call sp_inc32
    ld a,(sp_job_frame)
    ld hl,0
    ld l,a
    ld de,sp_valid
    add hl,de
    ld (hl),1
    ld a,(sp_job_frame)
    ld de,0
    ld d,10
    ld e,a
    mlt de
    ld hl,sp_build
    add hl,de
    ex de,hl
    ld hl,pb_result
    ld b,10
@quantize:
    ld a,(hl)
    ld c,0
    or a
    jr z,@level
@log:
    inc c
    srl a
    jr nz,@log
    ld a,c
    cp 7
    jr c,@level
    ld c,6
@level:
    ld a,c
    ld (de),a
    inc de
    inc hl
    djnz @quantize
    ret
@display:
    ld a,(sp_frame)
    ld hl,sp_last_frame
    cp (hl)
    jr z,@column
    ld (hl),a
    ld de,0
    ld d,10
    ld e,a
    mlt de
    ld hl,sp_play
    add hl,de
    ld de,sp_target
    ld bc,10
    ldir
    xor a
    ld (sp_next),a
@column:
    ld a,(sp_next)
    cp 10
    ret nc
    ld hl,0
    ld l,a
    ld de,sp_target
    add hl,de
    ld a,(hl)
    ld (sp_wanted),a
    ld hl,0
    ld a,(sp_next)
    ld l,a
    ld de,sp_shown
    add hl,de
    ld a,(sp_wanted)
    cp (hl)
    jr z,@next
    ld b,a
    ld a,(hl)
    cp 255
    jr z,@set_height
    cp b
    jr c,@set_height
    jr z,@set_height
    dec a ; fall at most one LED per display frame
    ld b,a
@set_height:
    ld a,b
    ld (hl),a
    ; bitmap2800 + quantized height
    ld (sp_plot_id),a
    ld a,(sp_next)
    ld de,0
    ld e,a
    ld a,(sp_pitch)
    ld d,a
    mlt de
    ld hl,(sp_x)
    add hl,de
    ld (sp_plot_x),hl
    ld hl,(sp_y)
    ld (sp_plot_y),hl
    ld hl,sp_plot
    ld bc,sp_plot_end-sp_plot
    call ui_send
    ld hl,sp_draws
    call sp_inc32
    ld de,16
    ld hl,sp_bytes
    call sp_add32
@next:
    ld hl,sp_next
    inc (hl)
    ret

; Post-quit fixed-size report; no playback file logging or VDU telemetry.
sp_toggle:
    ld a,(sp_enabled)
    or a
    jp z,get_input
    ld a,(sp_want)
    xor 1
    ld (sp_want),a
    call sp_clear
    ld a,(sp_want)
    ld (sp_wait_boundary),a ; reacquire at the next true sample boundary
    jp get_input

sp_finish:
    ld hl,sp_report_name
    ld c,fa_write|fa_create_always
    MOSCALL mos_fopen
    or a
    ret z
    ld (sp_handle),a
    ld c,a
    ld hl,sp_stats
    ld de,sp_stats_end-sp_stats
    MOSCALL mos_fwrite
    ld a,(sp_handle)
    ld c,a
    MOSCALL mos_fclose
    ret

sp_shutdown:
    ld a,(sp_loaded)
    or a
    ret z
    ld hl,0x2800
    ld b,7
@clear:
    push bc
    push hl
    call vdu_clear_buffer
    pop hl
    pop bc
    inc hl
    djnz @clear
    xor a
    ld (sp_loaded),a
    ret

sp_plot:
    db 23,0,0xc8,0,0 ; full-screen context0, no font/context churn
    db 23,27,0x20
sp_plot_id: dw 0x2800
sp_plot_opcode: db 25,0xed
sp_plot_x: dw 0
sp_plot_y: dw 0
sp_plot_end: db 0 ; absorbs ADL y store, not sent
sp_ready: asciz "PCM_SPECTRUM_READY\r\n"
sp_failed: asciz "PCM spectrum disabled: invalid optional descriptor/assets.\r\n"
sp_desc_leaf: asciz "spectrum.bin"
sp_assets_leaf: asciz "spectrum.agnb"
sp_report_name: asciz "/JSPEC.DAT"
sp_magic: db "SPC1"
sp_scalars: db 26,41,10,6,0,0,0
sp_image_meta:
    dw 0x2800,26,41
    db 1
    dw32 1066
    dw 0x2801,26,41
    db 1
    dw32 1066
    dw 0x2802,26,41
    db 1
    dw32 1066
    dw 0x2803,26,41
    db 1
    dw32 1066
    dw 0x2804,26,41
    db 1
    dw32 1066
    dw 0x2805,26,41
    db 1
    dw32 1066
    dw 0x2806,26,41
    db 1
    dw32 1066
sp_x: dl 0
sp_y: dl 0
sp_pitch: db 0
sp_want: db 0
sp_loaded: db 0
sp_wait_boundary: db 0
sp_count: dl 0
sp_source: dl 0
sp_length: dl 0
sp_collecting: db 0
sp_cooldown: db 0
sp_build_tick: db 0
sp_play_tick: db 0
sp_frame: db 0
sp_last_frame: db 255
sp_job_frame: db 0
sp_next: db 0
sp_wanted: db 0
sp_handle: db 0
sp_build: blkb 100,0
sp_play: blkb 100,0
sp_target: blkb 10,0
sp_shown: blkb 10,255
sp_valid: blkb 10,0
sp_fill: blkb 10,0
sp_stats: db "SPM1",1
sp_enabled: db 0
sp_error: db 0
    db 0
sp_stats_data:
sp_windows: dw32 0
sp_steps: dw32 0
sp_draws: dw32 0
sp_bytes: dw32 0
sp_skipped: dw32 0
sp_stats_end:

; Bounded little-endian u32 diagnostics helpers; no transport dependency.
sp_inc32:
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
sp_add32:
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

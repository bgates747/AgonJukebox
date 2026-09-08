; Player -> renderer event boundary. Producers run with interrupts disabled;
; every entry preserves all registers/flags. No producer sends VDU bytes.
ui_event_browser:
    push af
    ld a,(ui_pending)
    or 1
    jr ui_post
ui_event_track:
    push af
    ld a,(ui_pending)
    or 2
    jr ui_post
ui_event_time:
    push af
    ld a,(ui_pending)
    or 4
    jr ui_post
ui_event_modes:
    push af
    ld a,(ui_pending)
    or 8
    jr ui_post
ui_event_volume:
    push af
    ld a,(ui_pending)
    or 16
    jr ui_post
ui_event_detail:
    push af
    ld a,(ui_pending)
    or 32
    jr ui_post
ui_event_directory:
    push af
    ld a,(ui_pending)
    or 65
ui_post:
    ld (ui_pending),a
    pop af
    ret

ui_init:
    ld hl,0x2200
    call vdu_clear_buffer
    ld hl,0x2200
    ld de,ui_static
    ld bc,ui_static_end-ui_static
    call vdu_load_buffer
    ld hl,0x2200
    call vdu_call_buffer
    ld a,127
    ld (ui_pending),a
    ld hl,-1
    ld (ui_last_page),hl
    ld a,255
    ld (ui_last_row),a
    MOSCALL mos_sysvars
    ld a,(ix+sysvar_vkeycount)
    ld (ui_key_count),a
    ret

; Foreground-only complete bounded packets. Audio can interrupt between calls,
; never inside a command, text run, or printed-bitmap run. The largest packet
; is 96 bytes. No live UI code calls the audio buffer upload helper.
ui_send:
    push af
    push bc
    push de
    push hl
    push ix
    push iy
    di
    push hl
    ld hl,(ui_tx_bytes)
    add hl,bc
    ld (ui_tx_bytes),hl
    pop hl
    rst.lil 0x18
    ei
    pop iy
    pop ix
    pop hl
    pop de
    pop bc
    pop af
    ret

ui_flush:
    di
    ld a,(ui_pending)
    ld (ui_batch),a
    xor a
    ld (ui_pending),a
    ld hl,(ps_playhead)
    ld (ui_elapsed),hl
    ei
    ld a,(ui_batch)
    or a
    ret z
    bit 6,a
    call nz,ui_directory
    ld a,(ui_batch)
    bit 0,a
    call nz,ui_browser
    ld a,(ui_batch)
    bit 1,a
    call nz,ui_track
    ld a,(ui_batch)
    bit 2,a
    call nz,ui_time
    ld a,(ui_batch)
    bit 3,a
    call nz,ui_modes
    ld a,(ui_batch)
    bit 4,a
    call nz,ui_volume
    ld a,(ui_batch)
    bit 5,a
    call nz,ui_detail
    ret

; Copy bounded printable text and pad the entire field, preventing filenames
; from becoming VDU commands or leaving old pixels. HL source, DE target, B len.
ui_copy:
    ld a,(hl)
    or a
    jr z,@pad
    inc hl
    cp 32
    jr c,@replace
    cp 127
    jr c,@put
@replace:
    ld a,'?'
@put:
    ld (de),a
    inc de
    djnz ui_copy
    ld a,(hl)
    or a
    ret z
; All text fields are at least six cells wide. Mark clipped names explicitly.
    ld a,'.'
    dec de
    ld (de),a
    dec de
    ld (de),a
    dec de
    ld (de),a
    ret
@pad:
    ld a,' '
    ld (de),a
    inc de
    djnz @pad
    ret

; HL number, DE destination, B fixed decimal width, zero-filled.
; Division helpers are register-only and may also be called by the ISR.
ui_decimal:
    ld (ui_num_dest),de
    ld a,b
    ld (ui_num_width),a
    ld de,0
    ld e,b
    push hl
    ld hl,(ui_num_dest)
    add hl,de
    ld (ui_num_dest),hl
    pop hl
@digit:
    ld de,10
    call udiv24
    ld a,l
    add a,'0'
    ld hl,(ui_num_dest)
    dec hl
    ld (hl),a
    ld (ui_num_dest),hl
    ex de,hl
    ld a,(ui_num_width)
    dec a
    ld (ui_num_width),a
    jr nz,@digit
    ret

ui_directory:
    ld hl,-1
    ld (ui_last_page),hl
    ld hl,bf_dir_path
    ld de,w_path_text
    ld b,48
    call ui_copy
    call w_path_send
    jp ui_message

ui_browser:
    ld hl,(bf_page_cur)
    ld de,(ui_last_page)
    or a
    sbc hl,de
    jr nz,@full
    ld a,(ui_last_row)
    ld hl,bf_file_idx
    cp (hl)
    ret z
    cp 10
    call c,ui_row
    ld a,(bf_file_idx)
    cp 10
    call c,ui_row
    jr @remember
@full:
    ld hl,(bf_page_cur)
    inc hl
    ld de,w_page_text
    ld b,2
    call ui_decimal
    ld hl,ui_of
    ld de,w_page_text+2
    ld b,4
    call ui_copy
    ld hl,(bf_dir_num_pages)
    ld de,w_page_text+6
    ld b,2
    call ui_decimal
    call w_page_send
    xor a
@row:
    push af
    call ui_row
    pop af
    inc a
    cp 10
    jr c,@row
@remember:
    ld hl,(bf_page_cur)
    ld (ui_last_page),hl
    ld a,(bf_file_idx)
    ld (ui_last_row),a
    ret

ui_row:
    ld (ui_row_index),a
    ld hl,0
    ld l,a
    ld de,6
    call umul24
    ld de,ui_rows
    add hl,de
    ld ix,(hl)
    lea hl,ix+w_row0_text-w_row0
    ld (ui_row_text),hl
    ex de,hl
    ld hl,ui_empty
    ld b,60
    call ui_copy
    xor a
    ld (ix+w_row0_bg-w_row0),a
    ld a,10
    ld (ix+w_row0_fg-w_row0),a
    ld a,(ui_row_index)
    ld hl,bf_files_cur_pg
    cp (hl)
    jr c,@entry
    or a
    jr nz,@send
    ld hl,ui_no_entries
    ld de,(ui_row_text)
    ld b,60
    call ui_copy
    jr @send
@entry:
    ld hl,bf_file_idx
    cp (hl)
    jr nz,@normal
    ld (ix+w_row0_bg-w_row0),4
    ld (ix+w_row0_fg-w_row0),15
@normal:
    ld hl,(ui_row_text)
    ld (hl),'0'
    inc hl
    add a,'0'
    ld (hl),a
    ld hl,(bf_page_cur)
    ld de,30
    call umul24
    ld de,0
    ld a,(ui_row_index)
    ld e,a
    add hl,de
    add hl,de
    add hl,de
    ld de,bf_filinfo_ptrs
    add hl,de
    ld iy,(hl)
    ld hl,(ui_row_text)
    ld de,3
    add hl,de
    ex de,hl
    ld b,57
    bit AM_DIR,(iy+filinfo_fattrib)
    jr z,@filename
    push de
    ld hl,ui_dir_prefix
    ld b,6
    call ui_copy
    pop de
    ld hl,6
    add hl,de
    ex de,hl
    ld b,51
@filename:
    lea hl,iy+filinfo_fname
    call ui_copy
@send:
    push ix
    pop hl
    ld bc,w_row0_len
    call ui_send
    ld hl,(ui_row_draws)
    inc hl
    ld (ui_row_draws),hl
    ret

ui_track:
    ld a,(ps_active)
    or a
    ld hl,ui_idle
    ld a,' '
    ld (w_mode_code),a
    ld (w_play_code),a
    jr z,@name
    ld a,(ps_mode)
    and 1
    ld a,art_playing
    ld (w_mode_code),a
    ld a,art_pause
    ld (w_play_code),a
    ld hl,ui_playing
    jr nz,@prefix
    ld a,art_paused
    ld (w_mode_code),a
    ld a,art_play
    ld (w_play_code),a
    ld hl,ui_paused
@prefix:
    ld de,w_track_text
    ld b,8
    call ui_copy
    ld hl,ps_filinfo_fname
    ld de,w_track_text+8
    ld b,36
    call ui_copy
    jr @send
@name:
    ld de,w_track_text
    ld b,44
    call ui_copy
@send:
    call w_track_send
    call w_mode_send
    call w_play_send
    ld hl,ui_enter
    ld a,(ps_active)
    or a
    jr z,@hint
    ld hl,ui_pause
    ld a,(ps_mode)
    and 1
    jr nz,@hint
    ld hl,ui_resume
@hint:
    ld de,w_hint_text
    ld b,15
    call ui_copy
    call w_hint_send
    ld hl,0
    ld a,(ps_active)
    or a
    jr z,@duration
    ld hl,(ps_song_duration)
@duration:
    ld de,w_duration_digits
    call ui_digits
    call w_duration_send
    call ui_time
    call ui_detail
    call ui_message
    ret

; Convert the time string to a printed bitmap run: 8 characters, 8 VDU9 gaps.
ui_digits:
    push de
    call seconds_to_hhmmss
    pop de
    ld b,8
@digit:
    ld a,(hl)
    inc hl
    cp ':'
    jr z,@colon
    sub '0'
    add a,art_digit_0
    jr @store
@colon:
    ld a,art_colon
@store:
    ld (de),a
    inc de
    inc de
    djnz @digit
    ret

ui_time:
    ld hl,0
    ld a,(ps_active)
    or a
    jr z,@time
    ld hl,(ui_elapsed)
@time:
    ld de,w_elapsed_digits
    call ui_digits
    call w_elapsed_send
    call w_progress_send
    ld a,(ps_active)
    or a
    ret z
; Floor(216 * elapsed / duration), without overflowing a 24-bit product.
; Repeated modular addition is bounded at 216 iterations once per second.
; Carry accounts for the 25th bit when adding two large 24-bit values.
    ld hl,(ui_elapsed)
    ld de,(ps_song_duration)
    or a
    sbc hl,de
    ld bc,(ps_song_duration)
    jr nc,@clamped
    ld de,(ui_elapsed)
@clamped:
    xor a
    ld (ui_progress_pixel),a
    ld hl,0
    ld a,216
@fraction:
    push af
    add hl,de
    jr c,@carried
    or a
    sbc hl,bc
    jr nc,@advance
    add hl,bc
    jr @next
@carried:
    or a
    sbc hl,bc
@advance:
    ld a,(ui_progress_pixel)
    inc a
    ld (ui_progress_pixel),a
@next:
    pop af
    dec a
    jr nz,@fraction
    ld de,0
    ld a,(ui_progress_pixel)
    ld e,a
@position:
    ld hl,16
    add hl,de
    ld a,l
    ld (w_marker_x),a
    ld a,h
    ld (w_marker_x+1),a
    call w_marker_send
    ret

ui_modes:
    ld a,(ps_mode)
    and 4
    ld a,art_shuffle_off
    jr z,@shuffle
    ld a,art_shuffle_on
@shuffle:
    ld (w_shuffle_code),a
    call w_shuffle_send
    ld a,(ps_mode)
    and 2
    ld a,art_loop_off
    jr z,@loop
    ld a,art_loop_on
@loop:
    ld (w_loop_code),a
    call w_loop_send
    jp ui_message

ui_message:
    ld hl,ui_ready
    ld a,(ps_error)
    or a
    jr z,@normal
    ld hl,ui_invalid
    jr @send
@normal:
    ld a,(bf_files_cur_pg)
    or a
    jr nz,@mode
    ld hl,ui_empty_dir
    jr @send
@mode:
    ld a,(ps_mode)
    and 2
    jr z,@send
    ld hl,ui_loop_msg
@send:
    ld de,w_message_text
    ld b,48
    call ui_copy
    jp w_message_send

ui_volume:
    ld de,0
    ld a,(ps_volume)
    ld e,a
    ld hl,ui_volume_codes
    add hl,de
    ld a,(hl)
    ld (w_volume_code),a
    ld hl,ui_volume_x
    add hl,de
    ld e,(hl)
    ld hl,312
    add hl,de
    ld a,l
    ld (w_thumb_x),a
    ld a,h
    ld (w_thumb_x+1),a
    call w_volume_send
    call w_thumb_send
    ld hl,ui_vol
    ld de,w_voltext_text
    ld b,13
    call ui_copy
    ld hl,0
    ld a,(ps_volume)
    ld l,a
    ld de,w_voltext_text+4
    ld b,2
    call ui_decimal
    jp w_voltext_send

ui_detail:
    ld hl,ui_rate
    ld de,w_detail_text
    ld b,48
    call ui_copy
    ld hl,0
    ld a,(ps_active)
    or a
    jr z,@rate
    ld hl,(ps_wav_header+wav_sample_rate)
@rate:
    ld de,w_detail_text+5
    ld b,5
    call ui_decimal
    ld hl,(ps_seek_rate)
    ld de,w_detail_text+26
    ld b,3
    call ui_decimal
    jp w_detail_send

ui_pending: db 0
ui_batch: db 0
ui_key_count: db 0
ui_elapsed: dl 0
ui_last_page: dl -1
ui_last_row: db 255
ui_row_index: db 0
ui_row_text: dl 0
ui_num_dest: dl 0
ui_num_width: db 0
ui_tx_bytes: dl 0
ui_row_draws: dl 0
ui_progress_pixel: db 0
ui_empty: asciz ""
ui_no_entries: asciz "No entries"
ui_dir_prefix: asciz "<DIR> "
ui_of: asciz " OF "
ui_idle: asciz "IDLE"
ui_playing: asciz "PLAYING "
ui_paused: asciz "PAUSED  "
ui_enter: asciz "ENTER TO PLAY"
ui_pause: asciz "P PAUSE"
ui_resume: asciz "P RESUME"
ui_ready: asciz "Ready"
ui_invalid: asciz "Invalid .wav file selected, try again."
ui_empty_dir: asciz "No playable files or directories"
ui_loop_msg: asciz "Loop current song; Shuffle setting retained"
ui_vol: asciz "VOL 00"
ui_rate: asciz "RATE 00000 Hz   SEEK STEP 000s"

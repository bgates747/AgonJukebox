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
    call ui_mode_filter_init
    ld hl,0x2200
    call vdu_clear_buffer
    ld hl,0x2200
    ld de,ui_static
    if skin_runtime
    ld bc,(rt_static_len)
    else
    ld bc,ui_static_end-ui_static
    endif
    call vdu_load_buffer
    ld hl,0x2200
    call vdu_call_buffer
    ld a,127
    ld (ui_pending),a
    ld hl,-1
    ld (ui_last_page),hl
    ld a,255
    ld (ui_last_row),a
    ret

; Send one complete packet, preserving the caller's interrupt state. In normal
; use both command dispatch and timer-driven rendering enter with interrupts
; disabled. Test/setup callers that enter enabled must still receive replies.
; Packet byte counts do not bound CTS wait time on physical hardware.
ui_send:
    push af
    push bc
    push de
    push hl
    push ix
    push iy
    ld a,i
    push af
    di
    push hl
    ld hl,(ui_tx_bytes)
    add hl,bc
    ld (ui_tx_bytes),hl
    pop hl
    rst.lil 0x18
    pop af
    jp po,@disabled
    ei
@disabled:
    pop iy
    pop ix
    pop hl
    pop de
    pop bc
    pop af
    ret

ui_flush:
; Rendering runs either after a command or from the audio timer. Serialize the
; entire formatting/drawing pass, and never enable interrupts inside an ISR.
    push af
    ld a,i
    push af
    di
    ld a,(ui_pending)
    ld (ui_batch),a
    xor a
    ld (ui_pending),a
    ld hl,(ps_playhead)
    ld (ui_elapsed),hl
    ld a,(ui_batch)
    or a
    jr z,@done
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
@done:
    pop af
    jp po,@disabled
    ei
@disabled:
    pop af
    ret

; VDP 2.16 callback 0x0106 runs immediately before a mode packet is sent.
; Its seven-byte buffer suppresses that one packet only. Callback buffer calls
; do not process queued keyboard events, so a key packet cannot consume the
; suppression flag between this callback and sendModeInformation's send_packet.
; Suppressing all output, or a generic 'suppress next' before a UI packet,
; would also risk dropping keyboard events and is deliberately not used.
; 0x2200 is the static UI command buffer; 0x2201 is owned by this callback.
ui_mode_filter_init:
    ld hl,0x2201
    call vdu_clear_buffer
    ld hl,0x2201
    ld de,ui_mode_filter_body
    ld bc,7
    call vdu_load_buffer
    ld hl,ui_mode_filter_add
    ld bc,8
    jp ui_send

ui_shutdown:
; Remove only our callback before restoring MOS's context/font/mode. Keep all
; other applications' callbacks and all keyboard/pixel reply types intact.
    ld hl,ui_mode_filter_remove
    ld bc,8
    call ui_send
    ld hl,0x2201
    jp vdu_clear_buffer

ui_mode_filter_body: db 23,0,0xf8,3,1,1,0
ui_mode_filter_add: db 23,0,0xa0,1,0x22,0x50,6,1
ui_mode_filter_remove: db 23,0,0xa0,1,0x22,0x51,6,1

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
    if skin_runtime
    ld a,(rt_path_columns)
    ld b,a
    else
    ld b,ui_path_columns
    endif
    call ui_copy
    call w_path_send
    if ui_has_count
    ld hl,(bf_dir_num_files)
    ld de,w_count_text
    ld b,3
    call ui_decimal
    ld hl,ui_count_suffix
    ld de,w_count_text+3
    ld b,10
    call ui_copy
    call w_count_send
    endif
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
    call ui_selection_pointer
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
    ld b,ui_row_columns
    call ui_copy
    if skin_runtime
    ld a,(rt_normal_bg_value)
    endif
    if ui_normal_bg_value
    ld a,ui_normal_bg_value
    endif
    if skin_runtime+ui_normal_bg_value
    else
    xor a
    endif
    ld (ix+w_row0_bg-w_row0),a
    if skin_runtime
    ld a,(rt_normal_fg)
    else
    ld a,ui_normal_fg
    endif
    ld (ix+w_row0_fg-w_row0),a
    if skin_artdeco
    ld (ix+w_row0_context-w_row0),ui_normal_context
    endif
    ld a,(ui_row_index)
    ld hl,bf_files_cur_pg
    cp (hl)
    jr c,@entry
    or a
    if ui_row_wide_jumps
    jp nz,@send
    else
    jr nz,@send
    endif
    ld hl,ui_no_entries
    ld de,(ui_row_text)
    ld b,ui_row_columns
    call ui_copy
    if ui_row_wide_jumps
    jp @send
    else
    jr @send
    endif
@entry:
    ld hl,bf_file_idx
    cp (hl)
    jr nz,@normal
    if skin_runtime
    ld a,(rt_selected_bg)
    ld (ix+w_row0_bg-w_row0),a
    ld a,(rt_selected_fg)
    ld (ix+w_row0_fg-w_row0),a
    ld a,(ui_row_index)
    else
    ld (ix+w_row0_bg-w_row0),ui_selected_bg
    ld (ix+w_row0_fg-w_row0),ui_selected_fg
    endif
    if skin_artdeco
    ld (ix+w_row0_context-w_row0),ui_selected_context
    endif
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
    if skin_runtime
    ld de,0
    ld a,(rt_filename_offset)
    ld e,a
    else
    ld de,ui_filename_offset
    endif
    add hl,de
    ex de,hl
    if skin_runtime
    ld a,(rt_filename_columns)
    ld b,a
    else
    ld b,ui_filename_columns
    endif
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
    if skin_runtime
    ld a,(rt_filename_columns)
    sub 6
    ld b,a
    else
    ld b,ui_filename_columns-6
    endif
@filename:
    lea hl,iy+filinfo_fname
    call ui_copy
    if skin_runtime
    ld a,(rt_duration_offset)
    cp 255
    jp z,@send
    endif
    if ui_has_row_duration
    bit AM_DIR,(iy+filinfo_fattrib)
    jp nz,@send
    push ix
    ld hl,(ui_row_text)
    endif
    if skin_runtime
    ld de,0
    ld a,(rt_duration_offset)
    ld e,a
    endif
    if ui_has_row_duration-skin_runtime
    ld de,ui_duration_offset
    endif
    if ui_has_row_duration
    add hl,de
    ex de,hl
    ld hl,(iy+filinfo_altname) ; ADL24 OK: cached u24 seconds.
    call ui_digits
    pop ix
    endif
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
    ld a,ui_idle_play_code
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
    if skin_runtime
    ld a,(rt_track_columns)
    sub 8
    ld b,a
    else
    ld b,ui_track_columns-8
    endif
    call ui_copy
    jr @send
@name:
    ld de,w_track_text
    if skin_runtime
    ld a,(rt_track_columns)
    ld b,a
    else
    ld b,ui_track_columns
    endif
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

; Art Deco uses eight ordinary 5x8 characters; Base uses mapped digits + gaps.
ui_digits:
    push de
    call seconds_to_hhmmss
    pop de
    ld b,8
@digit:
    ld a,(hl)
    inc hl
    if 1-skin_artdeco
    cp ':'
    jr z,@colon
    sub '0'
    add a,art_digit_0
    jr @store
@colon:
    ld a,art_colon
@store:
    endif
    ld (de),a
    inc de
    if 1-skin_artdeco
    inc de
    endif
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
    if skin_runtime
    ld a,(rt_progress_span)
    else
    ld a,ui_progress_span
    endif
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
    if skin_runtime
    ld hl,(rt_progress_origin)
    else
    ld hl,ui_progress_origin
    endif
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
    if skin_artdeco
    ld b,23
    else
    ld b,48
    endif
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
    if 1-skin_artdeco
    ld hl,(ps_seek_rate)
    ld de,w_detail_text+26
    ld b,3
    call ui_decimal
    endif
    jp w_detail_send

ui_pending: db 0
ui_batch: db 0
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
    if skin_artdeco
ui_rate: asciz "RATE 00000 Hz"
    else
ui_rate: asciz "RATE 00000 Hz   SEEK STEP 000s"
    endif

; SKIN-013 candidate: AGNB bitmap on sprite 0, following the browser selection.
; Foreground only; move/show/refresh is one complete 17-byte packet.
ui_selection_pointer:
    if skin_runtime
    ld a,(rt_pointer_enabled)
    or a
    jp z,@hide
    endif
    if 1-ui_pointer_enabled
    jp @hide
    endif
    ld a,(bf_files_cur_pg)
    or a
    jr z,@hide
    ld a,(bf_file_idx)
    ld hl,bf_files_cur_pg
    cp (hl)
    jr nc,@hide
    if ui_pointer_table
    ld hl,ui_selection_y
    ld de,0
    ld e,a
    add hl,de
    ld a,(hl)
    else
    add a,a
    ld b,a
    add a,a
    add a,b
    add a,a
    add a,88
    endif
    ld (ui_selection_packet+9),a
    ld hl,ui_selection_packet
    ld bc,17
    jp ui_send
@hide:
    ld hl,ui_selection_hide
    ld bc,10
    jp ui_send
ui_selection_packet:
    db 23,27,4,0,23,27,13
    dw ui_pointer_x
    db ui_pointer_initial_y,0,23,27,11,23,27,15
ui_selection_hide:
    db 23,27,4,0,23,27,12,23,27,15

    if ui_has_count
ui_count_suffix: asciz " FILES"
    endif

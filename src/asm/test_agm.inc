; inputs:
;     iy = pointer to a filinfo struct
;     hl = pointer to a fil struct
;     de = pointer to a zero-terminated filename
; returns:
;     a=2 and zero flag reset if good .agm file (a=1 if good .wav)
;     hl points to ps_fil_struct
;     iy points to ps_filinfo_struct, 
;     ps_wav_header and ps_agm_header structs populated
;     if success, an open file with read cursor set to first block of data, otherwise file closed
ps_play_agm:
; verify valid .wav or .agm file
    push iy
    ld iy,ps_wav_header
    call verify_wav
    jp nz,@done ; is good file so return without closing

; not a good file so close it and return failure
    push af ; save zero flag and a
    FFSCALL ffs_fclose ; close the file
    pop af ; restore zero flag and a for return
@done:
    pop iy
    ret
; end test_agm_open_file

segment_counter: db 0

ps_read_agm:
    jp @big ; DEBUG

; set screen mode according to video dimensions
    ld de,(ps_wav_header+agm_width)
    dec de
    inc.s de ; clears ude

    ld hl,512
    or a ; clear carry
    sbc hl,de
    jp m,@bigger

    ld hl,320
    or a ; clear carry
    sbc hl,de
    jp m,@big
    
    ld hl,320
    ld (screen_width),hl
    ld hl,240
    ld (screen_height),hl
    ld a,8 ; 320x240x64 60Hz single-buffered
    jp @start
@bigger:
    ld hl,640
    ld (screen_width),hl
    ld hl,480
    ld (screen_height),hl
    xor a ; 640x480x16 60Hz single-buffered
    jp @start
@big:
    ld hl,512
    ld (screen_width),hl
    ld hl,384
    ld (screen_height),hl
    ld a,20 ; 512x384x64 60Hz single-buffered
@start: 
; initialize screen
    call vdu_set_screen_mode
    xor a
    call vdu_set_scaling
    call vdu_cursor_off
; set graphics mode
    ; ld a,3 ; mode xor
    xor a ; regular gcol mode
    ld c,c_blue_dk+128 ; can be any foreground 
    call vdu_gcol
    call vdu_clg
; initialize command and data buffers
    call ps_load_audio_cmd_buffers
    call pv_load_video_cmd_buffers
@next_segment:
; set up a frame timer
    ld hl,120
    ld a,(ps_wav_header+agm_frame_rate)
    ld de,0
    ld e,a
    call udiv24
    ex de,hl
    ld iy,tmr_test
    call tmr_set

; read the next segment header
    ld hl,ps_fil_struct
    ld bc,agm_segment_hdr_size ; bytes to read
    ld de,ps_agm_segment_hdr   ; target address
    FFSCALL ffs_fread
    call print_segment_hdr ; DEBUG

; check for end of file
    push bc ; bytes read
    pop hl
    SIGN_HLU
    jp z,@done

    ld a,(ps_wav_header+agm_frame_rate)
    inc a ; include audio unit
@unit_loop:
    ld (segment_counter),a ; save the segment loop counter

; read the next unit header
    ld hl,ps_fil_struct
    ld bc,agm_unit_hdr_size ; bytes to read
    ld de,ps_agm_unit_hdr   ; target address
    FFSCALL ffs_fread
    ; call print_unit_hdr ; DEBUG

; set data and command bufferIds based on the unit type
    ld a,(ps_agm_unit_hdr+agm_unit_mask)
    and agm_unit_type
    jp nz,@is_video
    call ps_set_audio_buffers ; audio unit
    jp @chunk_loop
@is_video:
    call pv_set_video_buffers ; video unit
@chunk_loop:
; read the next chunk header
    ld hl,ps_fil_struct
    ld bc,agm_chunk_hdr_size ; bytes to read
    ld de,ps_agm_chunk_hdr   ; target address
    FFSCALL ffs_fread
    ; call print_chunk_hdr ; DEBUG

; check chunk size for zero
    ld hl,(ps_agm_chunk_hdr+agm_chunk_size) ; bytes to load
    SIGN_HLU
    jp z,@next_unit
; read the next chunk of data from the SD card to RAM
    push hl
    pop bc ; bc = bytes to read
    ld hl,ps_fil_struct
    ld de,ps_agm_data
    FFSCALL ffs_fread
; load the data buffer with the data read (bc already has bytes to load)
    ld hl,(ps_agm_data_bufferId) ; bufferId
    ld de,ps_agm_data ; source address
    call vdu_load_buffer
    jp @chunk_loop
@next_unit:
; execute the unit command buffer
    ld hl,(ps_agm_cmd_bufferId) ; bufferId
    call vdu_call_buffer

; bump the unit counter
    ld a,(segment_counter)
    dec a
    jp nz,@unit_loop

@wait_here:
; check for escape keypress
    MOSCALL mos_getkbmap
; 113 Escape
    bit 0,(ix+14)
    jp z,@F
    jp @done
@@:
    ld iy,tmr_test
    call tmr_get
    jp z,@next_segment
    jp m,@next_segment
    jp @wait_here

@done: ; close the file
    ld hl,ps_fil_struct
    FFSCALL ffs_fclose
    ret
; end ps_read_agm


; ; set graphics mode
;     ld a,3 ; mode xor
;     ld c,c_black ; can be any foreground 
;     call vdu_gcol

print_segment_hdr:
    PUSH_ALL
    call vdu_home_cursor
    ; ; call vdu_cls
    ld ix,ps_agm_segment_hdr
    ; call printInline
    ; asciz "agm_segment_size_last: "
    ; ld hl,(ix+agm_segment_size_last)
    ; call printDec
    ; call printNewLine
    ; call printInline
    ; asciz "agm_segment_size_this: "
    ld hl,(ix+agm_segment_size_this)
    call printDec
    call printNewLine
    ; call DEBUG_WAITKEYPRESS
    POP_ALL
    ret
; end print_segment_hdr

print_unit_hdr:
    PUSH_ALL
    call printInline
    asciz "agm_unit_mask:         "
    ld a,(ps_agm_unit_hdr+agm_unit_mask)
    call printBin8
    call printNewLine
    ; call DEBUG_WAITKEYPRESS
    POP_ALL
    ret
; end print_unit_hdr

print_buffers:
    PUSH_ALL
    ; call vdu_home_cursor
    call printInline
    asciz "ps_agm_cmd_bufferId:     "
    ld hl,(ps_agm_cmd_bufferId)
    call printHex24
    call printNewLine
    CALL printInline
    asciz "ps_agm_data_bufferId:    "
    ld hl,(ps_agm_data_bufferId)
    call printHex24
    call printNewLine
    ; call DEBUG_WAITKEYPRESS
    POP_ALL
    ret
; end print_chunk_hdr

print_chunk_hdr:
    PUSH_ALL
    ld ix,ps_agm_chunk_hdr
    call printInline
    asciz "agm_chunk_size:        "
    ld hl,(ix+agm_chunk_size)
    call printDec
    call printNewLine
    ; call DEBUG_WAITKEYPRESS
    POP_ALL
    ret
; end print_chunk_hdr
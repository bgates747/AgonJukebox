test_fn: asciz "a_ha__Take_On_Me_short_120x90x4.agm"

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

ps_read_agm:
    call ps_load_audio_cmd_buffers
    call pv_load_video_cmd_buffers
@segment_loop:
; read the next segment header
    ld hl,ps_fil_struct
    ld bc,agm_segment_hdr_size ; bytes to read
    ld de,ps_agm_segment_hdr   ; target address
    FFSCALL ffs_fread

; DEBUG
    call vdu_home_cursor
    ld ix,ps_agm_segment_hdr
    call printInline
    asciz "agm_segment_size_last: "
    ld hl,(ix+agm_segment_size_last)
    call printDec
    call printNewLine
    call printInline
    asciz "agm_segment_size_this: "
    ld hl,(ix+agm_segment_size_this)
    call printDec
    call printNewLine
    ; call DEBUG_WAITKEYPRESS
; END DEBUG

@unit_loop:
; read the next unit header
    ld hl,ps_fil_struct
    ld bc,agm_unit_hdr_size ; bytes to read
    ld de,ps_agm_unit_hdr   ; target address
    FFSCALL ffs_fread

; DEBUG
    ld ix,ps_agm_unit_hdr
    call printInline
    asciz "agm_unit_mask:         "
    ld a,(ix+agm_unit_mask)
    call printBin8
    call printNewLine
    ; call DEBUG_WAITKEYPRESS
; END DEBUG

; set data and command bufferId's based on the unit type
    ld a,(ps_agm_segment_hdr+agm_unit_mask)
    and agm_unit_type
    call z,ps_set_audio_buffers ; audio unit
; DEBUG
    call printInline
    asciz "ps_agm_cmd_bufferId:   "
    ld hl,(ps_agm_cmd_bufferId)
    call printHex24
    call printNewLine
    CALL printInline
    asciz "ps_agm_data_bufferId:  "
    ld hl,(ps_agm_data_bufferId)
    call printHex24
    call printNewLine
    ; call DEBUG_WAITKEYPRESS
; END DEBUG

    jp @chunk_loop
    call pv_set_video_buffers ; video unit
@chunk_loop:
; read the next chunk header
    ld hl,ps_fil_struct
    ld bc,agm_chunk_hdr_size ; bytes to read
    ld de,ps_agm_chunk_hdr   ; target address
    FFSCALL ffs_fread

; DEBUG
    ld ix,ps_agm_chunk_hdr
    call printInline
    asciz "agm_chunk_size:        "
    ld hl,(ix+agm_chunk_size)
    call printDec
    call printNewLine
    ; call DEBUG_WAITKEYPRESS
; END DEBUG

; read the next chunk of data from the SD card to RAM
    ld hl,ps_fil_struct
    ld bc,(ps_agm_chunk_hdr+agm_chunk_size)
    ld de,ps_agm_data
    FFSCALL ffs_fread
; check chunk size for zero
    ld hl,(ps_agm_chunk_hdr+agm_chunk_size) ; bytes to load
    SIGN_HLU
    jp z,@next_unit
; load the data buffer with the data read
    push hl ; stack chunk size
    pop bc ; bc = bytes to load
    ld hl,(ps_agm_data_bufferId) ; bufferId
    ld de,ps_agm_data ; source address
    call vdu_load_buffer
    jp @chunk_loop
@next_unit:
; execute the unit command buffer
    ld hl,(ps_agm_cmd_bufferId) ; bufferId

; DEBUG
    CALL dumpRegistersHex
    CALL printNewLine
    CALL DEBUG_WAITKEYPRESS
; END DEBUG

    call vdu_call_buffer


    jp @done ; DEBUG

    jp @unit_loop













    ; call vdu_home_cursor ; DEBUG






; ; clear the image buffer
;     ld hl,test_image_buffer
;     call vdu_clear_buffer

; ; set the frame timer
;     ld hl,test_frame_timer
;     ld iy,tmr_test
;     call tmr_set

; ; read how many bytes in the next chunk
;     ld hl,ps_fil_struct
;     ld bc,4 ; bytes to read
;     ld de,ps_agm_data ; target address
;     FFSCALL ffs_fread
;     ld hl,(ps_agm_data) ; number of bytes to read this frame
;     ld (test_bytes_to_read),hl
;     push bc

;     CALL printDec ; DEBUG; print the number of bytes to read

;     pop hl
;     SIGN_HLU
;     jp z,@done

; ; compute number of chunks to load
;     ld hl,(test_bytes_to_read)
;     ld de,test_chunksize
;     call udiv24 ; de = number of whole chunks, hl = remaining bytes
;     push hl ; save remaining bytes

;     ex de,hl ; hl = number of whole chunks
;     SIGN_HLU
;     jp z,@load_remain ; no bytes to load so skip ahead

;     ld b,l ; loop counter
; @load_loop:
;     push bc ; save loop counter

; ; read the next chunk from the file
;     ld bc,test_chunksize ; bytes to read
;     ld hl,ps_fil_struct
;     ld de,ps_agm_data ; target address
;     FFSCALL ffs_fread

; ; load buffer with the data read
;     ld hl,test_image_buffer ; bufferId
;     ld bc,test_chunksize ; bytes to load
;     call vdu_load_buffer

; ; bump loop counter
;     pop bc ; restore loop counter
;     djnz @load_loop

; @load_remain: ; check for remaining bytes to load
;     pop hl ; restore remaining bytes
;     SIGN_HLU
;     jp z,@decompress ; no bytes left to load so skip ahead

; ; read the final chunk from the file
;     push hl
;     pop bc ; remaining bytes
;     ld hl,ps_fil_struct
;     ld de,ps_agm_data ; target address
;     FFSCALL ffs_fread

; ; load buffer with the data read
;     ld hl,test_image_buffer ; bufferId
;     ld bc,test_chunksize ; bytes to load
;     call vdu_load_buffer

; @decompress: ; decompress the loaded buffer
;     ; ld hl,test_image_buffer ; sourceBufferId
;     ; ld de,test_image_buffer ; targetBufferId
;     ; call vdu_decompress_buffer

; ; make an image from the buffer
;     ld hl,test_image_buffer ; bufferId
;     call vdu_consolidate_buffer
;     ld hl,test_image_buffer ; bufferId
;     call vdu_buff_select
;     ld a,1 ; rgba2222
;     ld bc,test_width ; width
;     ld de,test_height ; height
; 	call vdu_bmp_create

; ; check the frame timer
; @wait_here:
;     ld iy,tmr_test
;     call tmr_get
;     jp z,@F
;     jp m,@F
;     jp @wait_here

; @@: ; plot the image
;     ld bc,[screen_width-test_width]/2 ; x
;     ld de,[screen_height-test_height]/2 ; y
;     call vdu_plot_bmp

; ; ; print the frame number
; ;     call vdu_home_cursor
; ;     ld hl,(test_frame_number)
; ;     inc hl
; ;     ld (test_frame_number),hl
; ;     call printDec

; ; loop back to play_loop
;     jp @play_loop

@done: ; close the file
    ld hl,ps_fil_struct
    FFSCALL ffs_fclose

    ret
; end ps_read_agm


; ; set graphics mode
;     ld a,3 ; mode xor
;     ld c,c_black ; can be any foreground 
;     call vdu_gcol

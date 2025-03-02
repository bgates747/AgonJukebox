; WAV File Structure Offsets and Descriptions
wav_riff:          EQU 0    ; 4 bytes: "RIFF" identifier
wav_file_size:     EQU 4    ; 4 bytes: Total file size minus 8 bytes for RIFF header
wav_wave:          EQU 8    ; 4 bytes: "WAVE" identifier
wav_fmt_marker:    EQU 12   ; 4 bytes: "fmt " subchunk marker for .wav, "agm" for .agm
wav_fmt_size:      EQU 16   ; 4 bytes: Format chunk size (16 for PCM)
wav_audio_format:  EQU 20   ; 2 bytes: Audio format (1 = PCM)
wav_num_channels:  EQU 22   ; 2 bytes: Number of channels (1 = mono, 2 = stereo)
wav_sample_rate:   EQU 24   ; 4 bytes: Sample rate in Hz (e.g., 32768)
wav_byte_rate:     EQU 28   ; 4 bytes: Bytes per second (SampleRate * NumChannels * BitsPerSample / 8)
wav_block_align:   EQU 32   ; 2 bytes: Bytes per sample block (NumChannels * BitsPerSample / 8)
wav_bits_per_sample: EQU 34 ; 2 bytes: Bits per sample (e.g., 8 or 16)

; LIST Chunk (Extra Metadata)
wav_list_marker:   EQU 36   ; 4 bytes: "LIST" marker
wav_list_size:     EQU 40   ; 4 bytes: Size of the LIST chunk (e.g., 26)
wav_info_marker:   EQU 44   ; 4 bytes: "INFO" marker
wav_isft_marker:   EQU 48   ; 4 bytes: "ISFT" marker (software identifier)
wav_isft_data:     EQU 52   ; 14 bytes: Software info string (e.g., "Lavf59.27.100")
wav_isft_padding:  EQU 66   ; 2 bytes: Padding/NULL terminator for alignment

; Data Chunk
wav_data_marker:   EQU 68   ; 4 bytes: "data" subchunk marker
wav_data_size:     EQU 72   ; 4 bytes: Size of the audio data in bytes
wav_data_start:    EQU 76   ; Start of audio data
wav_header_size:   EQU wav_data_start ; Total Header Size: 76 bytes

; AGON Movie (.agm) Header Structure Offsets and Descriptions
; The first 76 bytes are the size and layout of a standard .wav header
agm_magic:         EQU 0+76    ; 6 bytes: "AGNMOV" identifier (offset 76-81)
agm_version:       EQU 6+76    ; 1 byte: File format version (offset 82)
agm_width:         EQU 7+76    ; 2 bytes: Video width in pixels (offsets 83-84)
agm_height:        EQU 9+76    ; 2 bytes: Video height in pixels (offsets 85-86)
agm_frame_rate:    EQU 11+76   ; 1 byte: Frames per second (offset 87)
agm_total_frames:  EQU 12+76   ; 4 bytes: Total number of frames (offsets 88-91)
agm_audio_seconds: EQU 16+76   ; 4 bytes: Total seconds of audio (offsets 92-95)
agm_reserved:      EQU 20+76   ; 48 bytes: Reserved for future features (offsets 96-143)
agm_header_size:   EQU 144     ; Total .agm Header size


; agm segment header
agm_segment_size_last: equ 0 ; 4 bytes: size of previous segment (including unit and chunk headers)
agm_segment_size_this: equ 4  ; 4 bytes: size of this segment (including unit and chunk headers)
agm_segment_hdr_size: equ 8 ; size of the segment header

; unit header contains metadata about the next unit being read
agm_unit_mask:     equ 0              ; 1 byte: encodes what to do with the unit with the following masks
agm_unit_hdr_size: equ 1              ; size of the unit header

agm_unit_type:     equ %10000000  ; bit 7, 0 = audio, 1 = video
agm_unit_gcol:     equ %00000111  ; bits 0-2, set gcol plotting mode for video frames, see 'GCOL paint modes' in vdu_plot.inc
agm_unit_cmp_typ:  equ %00011000  ; bits 3-4, compression type with the following types
agm_unit_cmp_non:  equ %00000000  ; no compression (bits 3,4 clear)
agm_unit_cmp_tbv:  equ %00001000  ; TurboVega compression (bit 3 set)
agm_unit_cmp_rle:  equ %00010000  ; Run-Length Encoding (bit 4 set)
agm_unit_cmp_szp:  equ %00011000  ; Szip compression (bits 3,4 set)

; chunk header (for each chunk of a unit)
agm_chunk_size: equ 0        ; 4 bytes: size of the chunk (excluding chunk header); 0 = end of unit
agm_chunk_hdr_size: equ 4    ; size of the chunk header

; verify that a file is an .agm file
; inputs: hl = pointer to fil struct, de = pointer to filename
; returns: zero flag set,   a = 0 if not a file we can read
;          zero flag reset, a = 2 if .agm file
; destroys: if called from verify_wav as usual it doesn't matter
;           otherwise, af, hl, de, iy
verify_agm:
; clear the .agm header buffer
    push hl
    push de
    ld bc,agm_header_size
    lea hl,iy+0 ; bf or ps agm_header
    call clear_mem
    pop de
    pop hl

; seek back to beginning of the file
    ld de,0
    ld c,0
    FFSCALL ffs_flseek

; read the header
    ld bc,agm_header_size
    lea de,iy+0 ; bf or ps agm_header
    FFSCALL ffs_fread

; verify the .agm header magic number 'AGNMOV'
    ld hl,(iy+agm_magic)
    ld de,0x4E4741 ; ascii for AGN in little-endian order
    or a ; clear carry
    sbc hl,de
    jr nz,@not_agm 

    ld hl,(iy+agm_magic+3)
    ld de,0x564F4D ; ascii for MOV in little-endian order
    or a ; clear carry
    sbc hl,de
    jr nz,@not_agm 

; check the version number and reject if not 0x01
    ld a,(iy+agm_version)
    cp 0x01
    jr nz,@not_agm

; looks good so fall through to @is_agm
@is_agm:
    ld a,1
    inc a ; reset zero flag and a = 2 indicating .agm file
    ret
@not_agm:
    xor a ; set zero flag and a = 0 indicating unreadable file
    ret
; end verify_agm

pv_frame_rate_last: db 1 ; last frame rate
pv_frame_counter: db 1 ; frame counter (1-based)
pv_set_video_buffers:
    ld hl,pv_cmd_base_buffer
    ld a,(pv_frame_counter)
    ld l,a ; low byte = frame n (1-based)
    ld (ps_agm_cmd_bufferId),hl
    inc h
    ld (ps_agm_data_bufferId),hl
    call vdu_clear_buffer
    ret
; end pv_set_video_buffers

pv_load_video_cmd_buffers:   
    ld hl,pv_cmd_base_buffer
    ld a,(pv_frame_rate_last)
    ld l,a ; low byte = frame n (1-based)
@clear_cmd_loop:
    push hl ; save cmd buffer high byte and loop counter
    call vdu_clear_buffer
    pop hl
    dec l ; dec loop counter
    jr nz,@clear_cmd_loop

    ld hl,pv_img_base_buffer
    ld a,(pv_frame_rate_last)
    ld l,a ; low byte = frame n (1-based)
@clear_img_loop:
    push hl ; save img buffer high byte and loop counter
    call vdu_clear_buffer
    pop hl
    dec l ; dec loop counter
    jr nz,@clear_img_loop

    ld de,(ps_wav_header+agm_width)
    ld (pv_cmd_width),de
    dec de
    inc.s de ; clears ude
    ld hl,(screen_width)
    or a ; clear carry
    sbc hl,de
    call hlu_div2
    ld (pv_cmd_x0),hl

    ld de,(ps_wav_header+agm_height)
    ld (pv_cmd_height),de
    ld a,1 ; format 1 = RGBA2222
    ld (pv_cmd_height+2),a
    dec de
    inc.s de ; clears ude
    ld hl,(screen_height)
    or a ; clear carry
    sbc hl,de
    call hlu_div2
    ld (pv_cmd_y0),hl

    ld a,(ps_wav_header+agm_frame_rate)
    ld (pv_frame_rate_last),a
    ld hl,pv_img_base_buffer
    ld l,a

@load_loop:
    push hl ; save command bufferId high byte and loop counter

    ld (pv_img_buffer_0),a
    ld (pv_img_buffer_1),a
    ld (pv_img_buffer_2),a
    ld (pv_img_buffer_3),a

    ld a,h
    ld (pv_img_buffer_0+1),a
    ld (pv_img_buffer_1+1),a
    ld (pv_img_buffer_2+1),a
    ld (pv_img_buffer_3+1),a

    dec h ; hl = cmd bufferId
    ld de,pv_cmd_draw
    ld bc,pv_cmd_draw_end-pv_cmd_draw
    call vdu_load_buffer

    pop hl ; restore current command bufferId
    dec l ; dec loop counter
    jr nz,@load_loop

    ret 
; end pv_load_video_cmd_buffers


pv_cmd_base_buffer: equ 0x4000
pv_img_base_buffer: equ 0x4100

pv_cmd_draw:
; Command 65: Decompress a buffer
; VDU 23, 0, &A0, targetBufferId; 65, sourceBufferId;
                    db 23,0,0xA0
pv_img_buffer_0:    dw 0x0000
                    ; db 65 ; decompress buffer (TurboVega)
                    db 67 ; decompress buffer (szip)
pv_img_buffer_1:    dw 0x0000

; Command 14: Consolidate blocks in a buffer
; VDU 23, 0, &A0, bufferId; 14
                    db 23,0,0xA0 ; vdu buffered api command header
pv_img_buffer_2:    dw 0x0000
                    db 14 ; consolidate blocks command

; VDU 23, 27, &20, bufferId; : Select bitmap (using a buffer ID)
; inputs: hl=bufferId
                    db 23,27,0x20
pv_img_buffer_3:    dw 0x0000

; VDU 23, 27, &21, w; h; format: Create bitmap from selected buffer
; 1 	RGBA2222 (1-bytes per pixel)
                    db 23,27,0x21
pv_cmd_width:       dw 0x0000
pv_cmd_height:      dw 0x0000
                    db 1 ; format

; VDU 25, mode, x; y;: PLOT command
                    db 25
                    db plot_bmp+dr_abs_fg ; 0xED
pv_cmd_x0: 	        dw 0x0000
pv_cmd_y0: 	        dw 0x0000
pv_cmd_draw_end:    db 0x00 ; padding

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
    jp z,@bad

; good file so set up to play it
; initialize command and data buffers
    call ps_load_audio_cmd_buffers
    call pv_load_video_cmd_buffers

; initialize frame counters


; setup done so return success
    ld a,1
    inc a ; .agm file is 2, resets zero flag
    jp @done

@bad: ; not a good file so close it and return failure
    push af ; save zero flag and a
    FFSCALL ffs_fclose ; close the file
    pop af ; restore zero flag and a for return
@done:
    pop iy
    ret
; end test_agm_open_file

unit_counter: db 0 ; number of units remaining to read in the current segment

ps_read_agm:
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
    jp get_input

@next_unit:
; execute the unit command buffer
    ld hl,(ps_agm_cmd_bufferId) ; bufferId
    call vdu_call_buffer
; bump the unit counter
    ld a,(unit_counter)
    dec a
    jp z,@next_segment
    ld (unit_counter),a
; read the unit header
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
    jp ps_read_agm
@is_video:
    call pv_set_video_buffers ; video unit
    jp ps_read_agm

@next_segment:
; read the next segment header
    ld hl,ps_fil_struct
    ld bc,agm_segment_hdr_size ; bytes to read
    ld de,ps_agm_segment_hdr   ; target address
    FFSCALL ffs_fread
    ; call print_segment_hdr ; DEBUG
; check for end of file
    push bc ; bytes read
    pop hl
    SIGN_HLU
    jp z,@done
; more to play so reset the unit counter and read the next chunk
    ld a,(ps_wav_header+agm_frame_rate)
    inc a ; include audio unit
    ld (unit_counter),a
    jp ps_read_agm
@done: ; close the file
    ld hl,ps_fil_struct
    FFSCALL ffs_fclose
    jp get_input
; end ps_read_agm



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
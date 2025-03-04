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
agm_segment_hdr_size: equ 8 ; size of the segment header
agm_segment_hdr: blkb agm_segment_hdr_size,0
agm_segment_size_last: equ 0 ; 4 bytes: size of previous segment (including unit and chunk headers)
agm_segment_size_this: equ 4  ; 4 bytes: size of this segment (including unit and chunk headers)

; unit header contains metadata about the next unit being read
agm_unit_hdr_size: equ 1              ; size of the unit header
agm_unit_hdr: blkb agm_unit_hdr_size,0
agm_unit_mask:     equ 0              ; 1 byte: encodes what to do with the unit with the following masks
agm_unit_type:     equ %10000000  ; bit 7, 0 = audio, 1 = video
agm_unit_gcol:     equ %00000111  ; bits 0-2, set gcol plotting mode for video frames, see 'GCOL paint modes' in vdu_plot.inc
agm_unit_cmp_typ:  equ %00011000  ; bits 3-4, compression type with the following types
agm_unit_cmp_non:  equ %00000000  ; no compression (bits 3,4 clear)
agm_unit_cmp_tbv:  equ %00001000  ; TurboVega compression (bit 3 set)
agm_unit_cmp_rle:  equ %00010000  ; Run-Length Encoding (bit 4 set)
agm_unit_cmp_szp:  equ %00011000  ; Szip compression (bits 3,4 set)

; chunk header (for each chunk of a unit)
agm_chunk_hdr_size: equ 4    ; size of the chunk header
agm_chunk_hdr: blkb agm_chunk_hdr_size,0
agm_chunk_size: equ 0        ; 4 bytes: size of the chunk (excluding chunk header); 0 = end of unit

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

pv_load_video_cmd_buffers:   
    ld hl,pv_cmd_base_buffer
    ld a,(ps_wav_header+agm_frame_rate)
    ld l,a ; low byte = frame n (1-based)
@clear_cmd_loop:
    push hl ; save cmd buffer high byte and loop counter
    call vdu_clear_buffer
    pop hl
    dec l ; dec loop counter
    jr nz,@clear_cmd_loop

    ld hl,pv_img_base_buffer
    ld a,(ps_wav_header+agm_frame_rate)
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
    ld hl,pv_img_base_buffer
    ld l,a

@load_loop:
    push hl ; save command bufferId high byte and loop counter
    ld (pv_img_buffer0),a

    ld a,h
    ld (pv_img_buffer0+1),a

    dec h ; hl = cmd bufferId
    ld de,pv_cmd_draw
    ld bc,pv_cmd_draw_end-pv_cmd_draw
    call vdu_load_buffer

    pop hl ; restore current command bufferId
    dec l ; dec loop counter
    jr nz,@load_loop

    ret 
; end pv_load_video_cmd_buffers

; | WAV HEADER (76 bytes) |
; | AGM HEADER (68 bytes) |
; -----------------------------------
; | Segment Header (8 bytes) |
; |   Unit Header (1 byte) → Video  |
; |     Chunk Header (4 bytes)      |
; |     Video Data (chunk_size)     |
; |     Chunk Header (4 bytes)      |
; |     Video Data (chunk_size)     |
; |     (Repeat until chunk_size = 0) |
; -----------------------------------
; |   Unit Header (1 byte) → Audio  |
; |     Chunk Header (4 bytes)      |
; |     Audio Data (chunk_size)     |
; |     (Repeat until chunk_size = 0) |
; -----------------------------------
; | Segment Header (8 bytes) |  ← Next Frame
; | (Repeat for all frames)  |
; -----------------------------------
pv_cmd_base_buffer: equ 0x4000
pv_img_base_buffer: equ 0x4100
pv_cmd_buffer: dl 0 ; Points to the next video command buffer to be called.
pv_img_buffer: dl 0 ; Points to the next video frame buffer to be loaded.
pv_draw_counter: db 0 ; Counts down from 60 / frame_rate.
pv_segment_counter: db 0 ; Increments when no full segment is ready after 60 ticks.
pv_loaded_frames: db 0 ; Tracks buffered frames (max fps * 5).

ps_cmd_base_buffer: equ 0x4200
ps_dat_base_buffer: equ 0x4300
ps_cmd_buffer: dl 0 ; Points to the next audio command buffer to be called.
ps_dat_buffer: dl 0 ; Points to the next audio data buffer to be loaded.
ps_loaded_samples: db 0 ; Tracks buffered audio samples (max 5).

pv_unit_type: db 0 ; 0 = audio, 1 = video

; inputs:
;     iy = pointer to a filinfo struct
;     hl = pointer to a fil struct
;     de = pointer to a zero-terminated filename
;     a  = (ps_media_type)
agm_play:
; verify valid .wav or .agm file
    cp media_type_agm ; a was set by play_song
    jp nz,agm_close_file
; set read_media_routine
    ld hl,agm_read_chunk
    ld (read_media_routine),hl
; compute the song duration in hh:mm:ss format and print it
    call vp_duration ; set viewport to duration window
    ld hl,(ps_wav_header+agm_audio_seconds) ; ls 24 bits of duration is sufficient and all we're prepared for
    call seconds_to_hhmmss ; hl pointer to string representation of HH:MM:SS
    call printString ; print the duration
; initialize command and data buffers
    call ps_load_audio_cmd_buffers
    call pv_load_video_cmd_buffers
; reset the playbar counter to zero
    ld hl,0
    ld (ps_playhead),hl
 ; this is crucial so that the next sound played is at new position
    call ps_set_audio_buffers        
; set ps_mode_playing
    ld hl,ps_mode
    set ps_mode_playing,(hl)
; enable interrupts and start the PRT timer
    call ps_prt_start
; jump to user input loop (enables interrupts)
; the play sample interrupt will return to there
; and exit app will return to main from there as well
    jp get_input
; fall through to agm_next_segment
; end agm_play

agm_next_segment:
; read the next segment header
    ld hl,ps_fil_struct
    ld bc,agm_segment_hdr_size ; bytes to read
    ld de,agm_segment_hdr   ; target address
    FFSCALL ffs_fread
    ; call agm_print_segment_hdr ; DEBUG
; check for end of file
    push bc ; bytes read
    pop hl
    SIGN_HLU
    jp z,agm_close_file
; more to play

; fall through to agm_next_unit
; end agm_next_segment

agm_next_unit:
; read the unit header
    ld hl,ps_fil_struct
    ld bc,agm_unit_hdr_size ; bytes to read
    ld de,agm_unit_hdr   ; target address
    FFSCALL ffs_fread
    ; call agm_print_unit_hdr ; DEBUG
; set data and command bufferIds based on the unit type
    ld a,(agm_unit_hdr+agm_unit_mask)
    and agm_unit_type
    jp nz,@is_video
    ; call ps_set_audio_buffers ; audio unit TODO: implement
    jp agm_read_chunk
@is_video:
    ; call pv_set_video_buffers ; video unit TODO: implement
; fall through to agm_read_chunk
; end agm_next_unit

agm_read_chunk:
; read the next chunk header
    ld hl,ps_fil_struct
    ld bc,agm_chunk_hdr_size ; bytes to read
    ld de,agm_chunk_hdr   ; target address
    FFSCALL ffs_fread
    ; call agm_print_chunk_hdr ; DEBUG
; check chunk size for zero, indicating end of unit
    ld hl,(agm_chunk_hdr+agm_chunk_size) ; bytes to load
    SIGN_HLU
    jp nz,@read_chunk
; end of unit so check type to determine if we're at end of segment
    ld a,(pv_unit_type)
    and a
    jp nz,agm_next_unit ; video unit so more in this segment to read
    jp agm_next_segment ; end of segment so read the next one
@read_chunk: ; read the next chunk of data from the SD card to RAM
    push hl
    pop bc ; bc = bytes to read
    ld hl,ps_fil_struct
    ld de,ps_agm_data
    FFSCALL ffs_fread
; load the data buffer with the data read (bc already has bytes to load)
    ld hl,(pv_img_buffer) ; bufferId
    ld de,ps_agm_data ; source address
    call vdu_load_buffer
    jp get_input

agm_close_file: 
; close the file
    ld hl,ps_fil_struct
    FFSCALL ffs_fclose
    jp get_input

pv_cmd_draw:
; VDU 23, 27, &20, bufferId; : Select bitmap (using a buffer ID)
; inputs: hl=bufferId
                    db 23,27,0x20
pv_img_buffer0:      dw 0x0000

; VDU 23, 27, &21, w; h; format: Create bitmap from selected buffer
; 1 	RGBA2222 (1-bytes per pixel)
                    db 23,27,0x21
pv_cmd_width:       dw 0x0000
pv_cmd_height:      dw 0x0000
                    db 1 ; format

; VDU 25, mode, x; y;: PLOT command
                    db 25
                    db plot_bmp+dr_abs_fg ; 0xED
pv_cmd_x0:          dw 0x0000
pv_cmd_y0:          dw 0x0000
pv_cmd_draw_end:    db 0x00 ; padding

agm_print_segment_hdr:
    PUSH_ALL
    call vdu_home_cursor
    ; ; call vdu_cls
    ld ix,agm_segment_hdr
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
; end agm_print_segment_hdr

agm_print_unit_hdr:
    PUSH_ALL
    call printInline
    asciz "agm_unit_mask:         "
    ld a,(agm_unit_hdr+agm_unit_mask)
    call printBin8
    call printNewLine
    ; call DEBUG_WAITKEYPRESS
    POP_ALL
    ret
; end agm_print_unit_hdr

agm_print_buffers:
    PUSH_ALL
    ; call vdu_home_cursor
    call printInline
    asciz "pv_cmd_buffer:     "
    ld hl,(pv_cmd_buffer)
    call printHex24
    call printNewLine
    CALL printInline
    asciz "pv_img_buffer:    "
    ld hl,(pv_img_buffer)
    call printHex24
    call printNewLine
    ; call DEBUG_WAITKEYPRESS
    POP_ALL
    ret
; end agm_print_chunk_hdr

agm_print_chunk_hdr:
    PUSH_ALL
    ld ix,agm_chunk_hdr
    call printInline
    asciz "agm_chunk_size:        "
    ld hl,(ix+agm_chunk_size)
    call printDec
    call printNewLine
    ; call DEBUG_WAITKEYPRESS
    POP_ALL
    ret
; end agm_print_chunk_hdr
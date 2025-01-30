; AGON Movie (.agm) Header Structure Offsets and Descriptions
; the first 76 bytes are the size and layout of a standard .wav header
agm_magic:         EQU 0+76    ; 6 bytes: "AGNMOV" identifier
agm_version:       EQU 6+76    ; 1 byte: File format version (e.g., 0x01)
agm_width:         EQU 7+76    ; 1 byte: Video width in pixels (e.g., 128)
agm_height:        EQU 8+76    ; 1 byte: Video height in pixels (e.g., 96)
agm_frame_rate:    EQU 9+76    ; 1 byte: Frames per second (e.g., 4)
agm_total_frames:  EQU 10+76   ; 4 bytes: Total number of frames (32-bit integer)
agm_audio_seconds: EQU 14+76   ; 4 bytes: Total seconds of audio (32-bit float or int)
agm_reserved:      EQU 18+76   ; 52 bytes: Reserved for future features (compression, metadata, etc.)
agm_header_size:   EQU 144   ; Total .agm Header size

pv_agm_width: db 0 ; video width in pixels (0 = 256)
pv_agm_height: db 0 ; video height in pixels (0 = 256)
pv_agm_frame_size: dl 0 ; size of a frame in bytes
pv_agm_frame_rate: db 0 ; frames per second (1-60)
pv_agm_frame_counter: db 0 ; init to frames/sec, when hits zero we load the next audio sample
pv_agm_chunks_per_frame: db 0 ; chunk size per frame (frame size / chunks per second)
pv_agm_frame_load_counter: db 0 ; init to chunks/frame, when hits zero plot the frame
pv_agm_chunks_per_sample: db 0 ; chunks per 1 second audio sample (sample rate / chunk size)
pv_wav_chunk_counter: db 0 ; init to chunks/sample, when hits zero play the loaded audio buffer

ps_read_agm:
; branch on the state of the wav chunk counter
    ld a,(pv_wav_chunk_counter)
    dec a
    ld (pv_wav_chunk_counter),a
    jp m,@F ; we're in the load and draw frames phase
    jp z,ps_play_sample ; sample buffer is loaded so play it

@@: ; branch on the state of the frame load counter
    ld a,(pv_agm_frame_load_counter)
    dec a
    ld (pv_agm_frame_load_counter),a
    jp z,draw_frame ; load the next frame
    jp get_input ; not time to load next frame
; end ps_read_agm

draw_frame:
; plot the image
    ld hl,pv_cmd_buffer
    call vdu_call_buffer

; reset the frame load counter
    ld a,(pv_agm_frame_rate)
    ld (pv_agm_frame_load_counter),a

; bump frame draw counters and branch on results
    ld a,(pv_agm_frame_counter)
    dec a
    jp nz,@F ; not time to load next sample

; reset the wav chunk counter
    ld a,(pv_agm_chunks_per_sample)
    ld (pv_wav_chunk_counter),a

; reset the frame counter
    ld a,(pv_agm_frame_rate)

@@:
; save the frame counter
    ld (pv_agm_frame_counter),a

; jump to user input
    jp get_input
; end draw_frame

play_agm:
; copy metadata to local variables
    ld a,(ps_wav_header+agm_width)
    ld (pv_agm_width),a
    ld a,(ps_wav_header+agm_height)
    ld (pv_agm_height),a
    ld a, (ps_wav_header+agm_frame_rate)
    ld (pv_agm_frame_rate),a

; compute frame statistics
    ld hl,(ps_wav_header+agm_width) ; l = width, h = height, hlu we don't care
    mlt hl ; hl = width * height
    ld (pv_agm_frame_size),hl ; save the frame size
    ld de,ps_chunks_per_second
    call udiv24 ; e = chunks per frame
    ld a,e
    ld (pv_agm_chunks_per_frame),a ; save the chunks per frame
    ld (pv_agm_frame_load_counter),a ; reset the frame chunk counter

; compute sample statistics
    ld hl,(ps_wav_header+wav_sample_rate)
    ld de,ps_chunks_per_second
    call udiv24 ; e = sample rate / chunks per second
    ld a,e
    ld (pv_agm_chunks_per_sample),a ; save the chunks per sample
    ld (pv_wav_chunk_counter),a ; reset the chunk counter
    ld (ps_wav_chunk_counter),a ; reset the chunk counter

; load the command buffer and return to play_agm
    call pv_load_command_buffer
    jp play_agm_return
; end play_agm

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

pv_cmd_buffer: equ 0x3004
pv_img_buffer: equ 0x3005

pv_load_command_buffer:
    ld a,(pv_agm_width)
    ld (pv_cmd_width),a    
    ld a,(pv_agm_height)
    ld (pv_cmd_height),a
    ld a,32
    ld (pv_cmd_x0),a
    ld (pv_cmd_y0),a
    ld hl,pv_cmd_buffer
    ld bc,pv_cmd_draw_end-pv_cmd_draw
    ld de,pv_cmd_draw
    call vdu_write_block_to_buffer
    ret
; end pv_load_command_buffer

pv_cmd_draw:
; Command 14: Consolidate blocks in a buffer
; VDU 23, 0, &A0, bufferId; 14
                    db 23,0,0xA0 ; vdu buffered api command header
                    dw pv_img_buffer
                    db 14 ; consolidate blocks command

; VDU 23, 27, &20, bufferId; : Select bitmap (using a buffer ID)
; inputs: hl=bufferId
                    db 23,27,0x20
                    dw pv_img_buffer

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
pv_cmd_draw_end:
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
    ld a,(ps_agm_width)
    ld (pv_cmd_width),a    
    ld a,(ps_agm_height)
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
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
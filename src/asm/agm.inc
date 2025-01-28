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
;           otherwise, af, hl, de, ix
verify_agm:
; DEBUG
    PUSH_ALL
    CALL vp_messages
    CALL vdu_cls
    POP_ALL
; END DEBUG

; clear the .agm header buffer
    push hl
    push de
    ld bc,agm_header_size
    ld hl,bf_agm_header
    call clear_mem
    pop de
    pop hl

; open the file 
    ld c,fa_read
    FFSCALL ffs_fopen

; read the header
    ld bc,agm_header_size
    ld de,bf_agm_header
    FFSCALL ffs_fread

; close the file
    FFSCALL ffs_fclose

; verify the .agm header magic number
    ld ix,bf_agm_header
    
    ld hl,(ix+agm_magic)
    ld de,0x4D4E41  ; ascii for "AGN" in little-endian order
    or a ; clear carry
    sbc hl,de
    jr nz,@not_agm 

    ld hl,(ix+agm_magic+3)
    ld de,0x564F4D  ; ascii for "MOV" in little-endian order
    or a ; clear carry
    sbc hl,de
    jr nz,@not_agm 

; check the version number and reject if not 0x01
    ld a,(ix+agm_version)
    cp 0x01
    jr nz,@not_agm

; looks good so fall through to @is_agm
@is_agm:
    ld a,1
    inc a ; reset zero flag and a = 2 indicating .agm file

; DEBUG
    CALL dumpFlags
    CALL dumpRegistersHex
; END DEBUG

    ret
@not_agm:
    xor a ; set zero flag and a = 0 indicating unreadable file

; DEBUG
    CALL dumpFlags
    CALL dumpRegistersHex
; END DEBUG

    ret
; end verify_agm
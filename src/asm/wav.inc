bf_verify_wav:
    push iy ; callers want iy back unmolested
    ld iy,bf_wav_header
    call verify_wav
    push af ; save zero flag and a
    FFSCALL ffs_fclose ; close the file
    pop af ; restore zero flag and a for return
    pop iy ; send her home how she came in
    ret
; end bf_verify_wav

ps_open_wav:
; get filinfo and fil struct pointers to currently selected file
    call bf_get_filinfo_from_pg_idx ; iy = pointer to filinfo struct
    lea de,iy+filinfo_fname ; de = pointer to filename
    ld hl,ps_fil_struct

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
; end ps_open_wav

; verify that a file is a .wav or .agm file
; inputs: hl = pointer to fil struct, de = pointer to filename
; returns: a = 0 and zero flag set if not a file we can read
;          zero flag reset and a = 1 if .wav file, a = 2 if .agm file
; destroys: af
verify_wav:
; back up registers
    push bc
    push ix

; we need the input registers for checking .agm files
    push hl
    push de

; clear the .wav header buffer
    push hl
    push de
    ld bc,wav_header_size
    lea hl,iy+0 ; bf or ps wav_header
    call clear_mem
    pop de
    pop hl

; open the file 
    ld c,fa_read
    FFSCALL ffs_fopen

; read the header
    ld bc,wav_header_size
    lea de,iy+0 ; bf or ps wav_header
    FFSCALL ffs_fread

; verify the .wav header
    
    ld hl,(iy+wav_riff)
    ld de,0x464952  ; ascii for "RIF" in little-endian order
    or a ; clear carry
    sbc hl,de
    jr nz,@not_wav 

    ld hl,(iy+wav_wave)
    ld de,0x564157  ; ascii for "WAV" in little-endian order
    or a ; clear carry
    sbc hl,de
    jr nz,@not_wav 

    ld hl,(iy+wav_audio_format)
    ld de,0x010001  ; PCM format, 1-channel
    or a ; clear carry
    sbc hl,de 
    jr nz,@not_wav 

    ld hl,(iy+wav_fmt_marker)
    ld de,0x746D66  ; ascii for "fmt" in little-endian order
    or a ; clear carry
    sbc hl,de
    jr z,@is_wav ; valid .wav file
    
    ; otherwise valid .wav header, so now check for valid .agm header
    ld hl,(iy+wav_fmt_marker)
    ld de,0x6D6761 ; ascii for "agm" in little-endian order
    or a ; clear carry
    sbc hl,de
    jr nz,@not_wav ; not valid .wav or .agm

    ; so far has valid .wav header, now check for valid .agm header
    pop de ; restore pointer to filename
    pop hl ; restore pointer to fil struct
    push hl ; and back them up
    push de ; again to balance stack
    call verify_agm ; a = 2, zero flag reset if .agm, otherwise zero flag set and a = 0
    ; fall through to @done
@done:
; restore registers and return
    pop de
    pop hl
    pop ix
    pop bc
    ret
@is_wav:
    xor a
    inc a ; reset zero flag and a = 1 indicating .wav file
    jr @done
@not_wav:
    xor a ; set zero flag and a = 0 indicating unreadable file
    jr @done
; end verify_wav
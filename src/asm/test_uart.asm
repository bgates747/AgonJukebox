bytes_per_chunk: equ 1024-64 ; 960 bytes max can be safely loaded in 1/60th of a second

    assume adl=1 
    org 0x040000 
    jp start 
    align 64 
    db "MOS" 
    db 00h 
    db 01h 

start: 
    push af
    push bc
    push de
    push ix
    push iy

    call init
    call main

exit:
    pop iy
    pop ix
    pop de
    pop bc
    pop af
    ld hl,0

    ret

; API INCLUDES
    include "mos_api.inc"
    include "macros.inc"
    include "functions.inc"
    include "arith24.inc"
    include "maths.inc"
    include "font.inc"
    include "fixed168.inc"
    include "time.inc"
    include "timer.inc"
    include "vdu.inc"
    include "vdu_buffered_api.inc"
    include "vdu_fonts.inc"
    include "vdu_plot.inc"
    include "vdu_sound.inc"

    include "fpp.inc"
    include "fpp_ext.inc"

; APPLICATION INCLUDES
    include "agm.inc"
    include "layout.inc"
    include "browse.inc"
    include "input.inc"
    include "logo.inc"
    include "play.inc"
    include "sort.inc"
    include "timer_jukebox.inc"
    include "wav.inc"
    include "debug.inc"

    include "test_agm_srle2.inc"

; --- MAIN PROGRAM FILE ---
init:
    
    ret
; end init

main:
    call ps_load_agm
    ret z ; file no good so exit

    call vdu_vblank ; sync up to for accurate timing
    call stopwatch_set ; start a stopwatch

    ld b,60 ; loop counter
@loop:
    push bc ; save loop counter

; read the next 1 KiB block of data
    ld hl,ps_fil_struct
    ld bc,bytes_per_chunk ; bytes to read
    ld de,ps_agm_data   ; target address
    FFSCALL ffs_fread

; load the data into the buffer
    ld hl,256 ; bufferId
    ld bc,bytes_per_chunk ; bytes to load
    ld de,ps_agm_data ; pointer to file data (max 8 KiB)
    call vdu_load_buffer ; push data across UART

; do the loopage
    pop bc
    djnz @loop 

; compute elapsed time
    call stopwatch_get ; hl = elapsed time in 1/120th seconds
    hlu_mul256 ; hl -> 16.8 fixed point
    ld de,120*256 ; 120 seconds in 16.8 fixed point
    call udiv168 ; de = hl / de
    ex de,hl
    call print_s168 ; print the result

; close the file and return to MOS
    ld hl,ps_fil_struct
    FFSCALL ffs_fclose

    ret ; back to MOS
; end main

test_fn_2: asciz "Star_Wars__Battle_of_Yavin_bayer.agm"
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
ps_load_agm:
; a=2 and zero flag reset if good .agm file (a=1 if good .wav)
; hl points to ps_fil_struct
; iy points to ps_filinfo_struct, 
; ps_wav_header and ps_agm_header structs populated
    ld iy,ps_filinfo_struct
    ld hl,ps_fil_struct
    ld de,test_fn_2

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

; must be final include in program so file data does not stomp on program code or other data
    include "files.inc"
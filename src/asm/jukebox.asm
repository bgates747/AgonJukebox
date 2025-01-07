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
    include "files.inc"
    include "fixed168.inc"
    include "timer.inc"
    include "vdu.inc"
    include "vdu_buffered_api.inc"
    include "vdu_fonts.inc"
    include "vdu_plot.inc"
    include "vdu_sound.inc"

; APPLICATION INCLUDES
    include "input.inc"
    include "music.inc"
    include "play.inc"
    include "debug.inc"

; --- MAIN PROGRAM FILE ---
init:
; load play sample command buffers
    call load_command_buffer
; initialize input timer
    ld iy,tmr_input
    ld hl,100 ; 1 second
    call tmr_set
    ret
; end init

main:
    call printNewLine
; point to first song in the index
    ld hl,SFX_filename_index
    ld hl,(hl) ; pointer to first song filename
    call play_song
    ret
; end main

; buffer for sound data
; (must be last so buffer doesn't overwrite other program code or data)
song_data:
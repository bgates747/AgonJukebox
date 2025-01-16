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
    include "fonts.inc"
    include "fonts_list.inc"
    include "fixed168.inc"
    include "time.inc"
    include "timer.inc"
    include "vdu.inc"
    include "vdu_buffered_api.inc"
    include "vdu_fonts.inc"
    include "vdu_plot.inc"
    include "vdu_sound.inc"

; APPLICATION INCLUDES
    include "layout.inc"
    include "ascii.inc"
    include "input.inc"
    include "play.inc"
    include "timer_jukebox.inc"
    include "wav.inc"
    include "debug.inc"

; --- MAIN PROGRAM FILE ---
init:

    ret
; end init

main:
    call printNewLine

    ; ld a,0x00
    ; ld ix,8275270
    ; ld de,48000

    ld a,0x19
    ld ix,0xCAC880
    ld de,48000

    call udiv3223
    ld (ps_song_duration),ix ; duration low long word
    ld (ps_song_duration+3),a ; duration high byte
    ld hl,(ps_song_duration) ; ls 24 bits of duration is sufficient and all we're prepared for

    call seconds_to_hhmmss ; hl pointer to string representation of HH:MM:SS
    call printString ; print the duration
    call printNewLine
    ret

; end main

; must be final include in program so file data does not stomp on program code or other data
    include "files.inc"
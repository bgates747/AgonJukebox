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
original_screen_mode: db 0

init:
    ret
; end init

str_dashes: asciz "------------------------------"
str_thick_dashes: asciz "=============================="

main:
    ld b,25 ; loop counter
@loop:
    push bc
    call rand_8
    call printHexA
    ld h,a
    ld l,10 ; modulo 10
    call udiv8 ; h = quotient, a = remainder, l = divisor
    call printHexHL
    call printHexA
    call printNewLine
    pop bc
    djnz @loop
    ret


    ld hl,406
    ld de,10
    push hl
    push de
    call hlu_floor
    call printDec
    call printNewLine

    pop de
    pop hl
    call hlu_ceiling
    call printDec
    call printNewLine

    ret ; back to MOS
; end main

; must be final include in program so file data does not stomp on program code or other data
    include "files.inc"
    assume adl=1 
    org 0x040000 
    jp start 
    align 64 
    db "MOS" 
    db 00h 
    db 01h 

start: 
    ; push af
    ; push bc
    ; push de
    ; push ix
    ; push iy

    ; call init
    ; call main

    jp main

exit:
    ; pop iy
    ; pop ix
    ; pop de
    ; pop bc
    ; pop af
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
    ld bc,0
    ld (@stack_pointer),sp
    ld hl,(@stack_pointer)
    call printHexUHL
    call printNewLine
    ex de,hl
@loop:
    inc bc
    push bc
    ld (@stack_pointer),sp
    ld hl,(@stack_pointer)
    call printHexUHL
    call printNewLine
    or a ; clear carry
    sbc hl,de
    SIGN_HLU
    jp nz,@loop
    ld hl,(@stack_pointer)
    call printHexUHL
    push bc
    pop hl
    call printHexUHL
    call printNewLine
    call DEBUG_WAITKEYPRESS
@stack_pointer: dl 0
; end main

; must be final include in program so file data does not stomp on program code or other data
    include "files.inc"
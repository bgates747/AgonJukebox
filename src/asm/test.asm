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

test_buffer: dl 0xff1234
; --- MAIN PROGRAM FILE ---
init:


    ret
; end init
main:
    LD_HL_mn test_buffer
    call printHex24
    call printNewLine

    LD_BC_mn test_buffer
    push bc
    pop hl
    call printHex24
    call printNewLine

    LD_DE_mn test_buffer
    ex de,hl
    call printHex24
    call printNewLine

    LD_IX_mn test_buffer
    push ix
    pop hl
    call printHex24
    call printNewLine

    LD_IY_mn test_buffer
    push iy
    pop hl
    call printHex24
    call printNewLine

    ret ; back to MOS
; end main

; must be final include in program so file data does not stomp on program code or other data
    include "files.inc"
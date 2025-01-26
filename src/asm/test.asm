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
    include "layout.inc"
    include "browse.inc"
    include "input.inc"
    include "logo.inc"
    include "play.inc"
    include "sort.inc"
    include "timer_jukebox.inc"
    include "wav.inc"
    include "debug.inc"

; --- MAIN PROGRAM FILE ---
str_seconds: asciz "600"
str_sample_rate: asciz "4800"

str_arg1: asciz "3600"
str_arg2: asciz "48000"

fpp_arg1: blkb 5,0 ; 32-bit float
fpp_arg2: blkb 5,0 ; 32-bit float

int_seconds: blkb 4,0 ; 32-bit integer
int_sample_rate: blkb 4,0 ; 32-bit integer
init:
    ret
; end init
main:
    call printNewLine
    
    ld hl,-105
    ld de,100
    SIGN_HLU
    jp z,@print
    jp p,@mod
    add hl,de
    jp p,@print
    call neg_hlu
    jp @print
@mod:
    call udiv24
@print:
    call printDec
    call printNewLine

    ret ; back to MOS
; end main

; must be final include in program so file data does not stomp on program code or other data
    include "files.inc"
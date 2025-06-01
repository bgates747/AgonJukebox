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

;     include "fpp.inc"
;     include "fpp_ext.inc"

; ; APPLICATION INCLUDES
;     include "agm.inc"
;     include "layout.inc"
;     include "browse.inc"
;     include "input.inc"
;     include "logo.inc"
;     include "play.inc"
;     include "sort.inc"
;     include "timer_jukebox.inc"
;     include "wav.inc"
    
    ; include "debug.inc"

test_buffer: dl 0xff1234
; --- MAIN PROGRAM FILE ---
init:


    ret
; end init
main:
    MOSCALL mos_getkey ; a = ascii code of key pressed
    cp '\e' ; escape
    ret z 

    or a ; will be zero if function, alt, ctl, caps lock, or shift keys pressed
    jr z,@check_fkeys
    call printDec8
    call printNewLine
    jr main

@check_fkeys:
    MOSCALL mos_getkbmap ; ix points to vdp-gl virtual keys map
; 114 F1
    bit 1,(ix+14)
    jr z,@F
    call printInline
    asciz "F1\r\n"
    jr main
@@:
; 115 F2
    bit 2,(ix+14)
    jr z,@F
    call printInline
    asciz "F2\r\n"
    jr main
@@:
; 116 F3
    bit 3,(ix+14)
    jr z,@F
    call printInline
    asciz "F3\r\n"
    jr main
@@:
; 21 F4
    bit 4,(ix+2)
    jr z,@F
    call printInline
    asciz "F4\r\n"
    jr main
@@:
; 117 F5
    bit 4,(ix+14)
    jr z,@F
    call printInline
    asciz "F5\r\n"
    jr main
@@:
    jr main
; end main

; must be final include in program so file data does not stomp on program code or other data
    include "files.inc"
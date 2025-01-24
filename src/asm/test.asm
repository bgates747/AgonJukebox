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

; APPLICATION INCLUDES
    include "layout.inc"
    ; include "ascii.inc"
    include "browse.inc"
    include "input.inc"
    include "logo.inc"
    include "play.inc"
    include "timer_jukebox.inc"
    include "wav.inc"
    include "debug.inc"

; --- MAIN PROGRAM FILE ---
init:

    ret
; end init
main:
    call load_ui_images
    ld hl,BUF_UI_LOGO
    call vdu_buff_select
    ld bc,128
    ld de,128
    call vdu_plot_bmp
    ret ; back to MOS
; end main

; must be final include in program so file data does not stomp on program code or other data
    include "files.inc"
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

; --- MAIN PROGRAM FILE ---
init:
    xor a
    call vdu_set_scaling
    call vdu_vblank
    ld iy,tmr_test
    ld hl,1200 ; 1/120ths of a second
    call tmr_set
    ld bc,0 ; counter
    ret
; end init
main:
    push bc ; save counter

; load an image
    ld a,1 ; rgba2222
    ld bc,120 ; width
    ld de,90 ; height
    ld l,c
    ld h,b
    mlt hl
    push hl
    pop ix ; file size
    ld iy,fn_image
    ld hl,4000 ; bufferId
    call vdu_load_img

; plot the image
    ; ld hl,4000 ; bufferId
    ; call vdu_buff_select
    ld bc,128 ; x
    ld de,128 ; y
    call vdu_plot_bmp

; bump counter
    pop bc
    inc bc

; check timer
    ld iy,tmr_test
    call tmr_get
    jp z,@done
    jp m,@done

    jr main ; loop

@done:
    push bc
    pop hl
    call printDec
    call printNewLine
    ret ; back to MOS
; end main

fn_image: asciz "../images/rainbow_swirl.rgba2"

; must be final include in program so file data does not stomp on program code or other data
    include "files.inc"
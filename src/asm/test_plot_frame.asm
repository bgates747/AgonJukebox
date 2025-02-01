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
; load an image
; inputs: hl = bufferId; iy = pointer to filename
    ld hl,pv_img_buffer
    ld iy,fn_image
    call vdu_load_buffer_from_file

; load image plot command buffer
    ld a,240
    ld (agm_width),a
    ld a,180
    ld (agm_height),a
    call pv_load_video_cmd_buffers

; set up screen
    ld a,8
    call vdu_set_screen_mode
    call vdu_cls
    xor a
    call vdu_set_scaling

; set up timer
    call vdu_vblank ; sync to vblank
    ld iy,tmr_test
    ld hl,1200 ; 1/120ths of a second
    call tmr_set
    ld bc,0 ; counter

    ret
; end init
main:
    push bc ; save counter

; plot the image
    ld hl,pv_cmd_buffer
    call vdu_call_buffer

; bump counter
    pop bc
    inc bc

    ; ret ; DEBUG

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

fn_image: asciz "images/rainbow_swirl.rgba2"

; must be final include in program so file data does not stomp on program code or other data
    include "files.inc"
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

    include "test_agm.inc"

; --- MAIN PROGRAM FILE ---
init:
; set up display
    ; ld a,8 ; 320x240x64 single-buffered
    ld a,20 ; 512x384x64 single-buffered
    call vdu_set_screen_mode
    xor a
    call vdu_set_scaling
    call vdu_cursor_off
    
    ret
; end init

; test_fn_1: asciz "a_ha__Take_On_Me_floyd.agm"
; test_fn_2: asciz "Bad_Apple_floyd.agm"
; test_fn_3: asciz "Star_Wars__Battle_of_Yavin_floyd.agm"

test_file: asciz "frame_00004.rgba2"

main:
    call vdu_cls

    ld a,1 ; rgba2
    ld bc,160 ; width
    ld de,68 ; height
    ld hl,pv_img_base_buffer ; bufferId
    ld iy,test_file
    call vdu_load_img

    ld bc,120 ; x
    ld de,32 ; y
    call vdu_plot_bmp

    ld hl,pv_img_base_buffer ; bufferId
    ld de,pv_img_base_buffer ; bufferId
    call vdu_compress_buffer_tvc

    ld hl,pv_img_base_buffer

    ld a,l
    ld (pv_img_buffer_0),a
    ld (pv_img_buffer_1),a
    ld (pv_img_buffer_2),a
    ld (pv_img_buffer_3),a

    ld a,h
    ld (pv_img_buffer_0+1),a
    ld (pv_img_buffer_1+1),a
    ld (pv_img_buffer_2+1),a
    ld (pv_img_buffer_3+1),a

    ld hl,160
    ld (pv_cmd_width),hl
    ld hl,68
    ld (pv_cmd_height),hl
    ld a,1
    ld (pv_cmd_height+2),a

    ld hl,120
    ld (pv_cmd_x0),hl
    ld hl,32+68+8
    ld (pv_cmd_y0),hl

    ; ld hl,pv_cmd_draw
    ; ld bc,pv_cmd_draw_end-pv_cmd_draw
    ; rst.lil 18h

    ld hl,pv_cmd_base_buffer
    ld de,pv_cmd_draw
    ld bc,pv_cmd_draw_end-pv_cmd_draw
    call vdu_load_buffer

    ld hl,pv_cmd_base_buffer
    call vdu_call_buffer

@main_end:
; return display to normal
    call vdu_cursor_on

    ret ; back to MOS
; end main

; must be final include in program so file data does not stomp on program code or other data
    include "files.inc"
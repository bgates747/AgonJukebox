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
    ld a,8 ; 320x240x64 single-buffered
    ; ld a,20 ; 512x384x64 single-buffered
    call vdu_set_screen_mode
    xor a
    call vdu_set_scaling
    call vdu_cursor_off
    
    ret
; end init

; test_fn_1: asciz "a_ha__Take_On_Me_floyd.agm"
; test_fn_2: asciz "Bad_Apple_floyd.agm"
; test_fn_3: asciz "Star_Wars__Battle_of_Yavin_floyd.agm"

test_file: asciz "lines.rgba2"
test_file_szip: asciz "lines.rgba2.szip"

main:
    call vdu_cls

; ; test uncompressed
;     ld a,1 ; rgba2
;     ld bc,8 ; width
;     ld de,8 ; height
;     ld hl,pv_img_base_buffer ; bufferId
;     ld iy,test_file
;     call vdu_load_img
;     ld bc,120 ; x
;     ld de,120 ; y
;     call vdu_plot_bmp

; test compressed
    ld hl,pv_img_base_buffer ; bufferId
    call vdu_clear_buffer
    ld hl,pv_img_base_buffer ; bufferId
    ld iy,test_file_szip
    call vdu_load_buffer_from_file

    ld hl,pv_img_base_buffer ; source bufferId
    ld de,pv_img_base_buffer ; target bufferId
    call vdu_decompress_buffer_szip

    ld hl,pv_img_base_buffer ; bufferId
    call vdu_consolidate_buffer

    ld hl,pv_img_base_buffer ; bufferId
    call vdu_buff_select

    ld a,1 ; rgba2
    ld bc,8 ; width
    ld de,8 ; height
    ld hl,pv_img_base_buffer ; bufferId
    call vdu_bmp_create

    ld bc,128 ; x
    ld de,128 ; y
    call vdu_plot_bmp

@main_end:
; return display to normal
    call vdu_cursor_on

    ret ; back to MOS
; end main

; must be final include in program so file data does not stomp on program code or other data
    include "files.inc"
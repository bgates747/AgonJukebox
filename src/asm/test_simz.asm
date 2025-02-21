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
    ; include "font.inc"
    ; include "fixed168.inc"
    ; include "time.inc"
    ; include "timer.inc"
    include "vdu.inc"
    include "vdu_buffered_api.inc"
    ; include "vdu_fonts.inc"
    include "vdu_plot.inc"
    ; include "vdu_sound.inc"

    ; include "fpp.inc"
    ; include "fpp_ext.inc"

; APPLICATION INCLUDES
    ; include "agm.inc"
    ; include "layout.inc"
    ; include "browse.inc"
    ; include "input.inc"
    ; include "logo.inc"
    ; include "play.inc"
    ; include "sort.inc"
    ; include "timer_jukebox.inc"
    ; include "wav.inc"
    ; include "debug.inc"

    ; include "test_agm.inc"

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

image_width: equ 240
image_height: equ 180

test_file: asciz "rainbow_swirl.rgba2"
test_file_tvc: asciz "rainbow_swirl.rgba2.tvc"
test_file_szip: asciz "rainbow_swirl.rgba2.szip"
test_file_simz: asciz "rainbow_swirl.rgba2.simz"
img_bufferId: equ 256
tvc_bufferId: equ 257
simz_bufferId_dat: equ 259 ; equ 258
simz_bufferId: equ 259
szip_bufferId: equ 260

main:
    call vdu_cls

; test uncompressed
    ld a,1 ; rgba2
    ld bc,image_width
    ld de,image_height
    ld hl,img_bufferId 
    ld iy,test_file
    call vdu_load_img
    ld bc,0 ; x
    ld de,8 ; y
    call vdu_plot_bmp

@test_tvc:
    ld hl,tvc_bufferId 
    call vdu_clear_buffer
    ld hl,tvc_bufferId 
    ld iy,test_file_tvc
    call vdu_load_buffer_from_file

    ld hl,tvc_bufferId ; source bufferId
    ld de,tvc_bufferId ; target bufferId
    call vdu_decompress_buffer_tvc

    ld hl,tvc_bufferId 
    call vdu_buff_select

    ld a,1 ; rgba2
    ld bc,image_width
    ld de,image_height
    ld hl,tvc_bufferId 
    call vdu_bmp_create

    ld bc,512-image_width-1 ; x
    ld de,8 ; y
    call vdu_plot_bmp

@test_simz:
    ld hl,simz_bufferId_dat 
    call vdu_clear_buffer
    ld hl,simz_bufferId_dat 
    ld iy,test_file_simz
    call vdu_load_buffer_from_file

    ld hl,simz_bufferId_dat ; source bufferId
    ld de,simz_bufferId ; target bufferId
    call vdu_decompress_buffer_simz

    ld hl,simz_bufferId 
    call vdu_buff_select

    ld a,1 ; rgba2
    ld bc,image_width
    ld de,image_height
    ld hl,simz_bufferId 
    call vdu_bmp_create

    ld bc,0 ; x
    ld de,384-image_height-1 ; y
    call vdu_plot_bmp

@test_szip:
    ld hl,szip_bufferId 
    call vdu_clear_buffer
    ld hl,szip_bufferId 
    ld iy,test_file_szip
    call vdu_load_buffer_from_file

    ld hl,szip_bufferId ; source bufferId
    ld de,szip_bufferId ; target bufferId
    call vdu_decompress_buffer_szip

    ld hl,szip_bufferId 
    call vdu_buff_select

    ld a,1 ; rgba2
    ld bc,image_width
    ld de,image_height
    ld hl,szip_bufferId 
    call vdu_bmp_create

    ld bc,512-image_width-1 ; x
    ld de,384-image_height-1 ; y
    call vdu_plot_bmp

@main_end:
; return display to normal
    call vdu_cursor_on

    ret ; back to MOS
; end main

; must be final include in program so file data does not stomp on program code or other data
    include "files.inc"
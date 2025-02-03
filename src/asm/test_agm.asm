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
; ; set up display
;     ; ld a,8 ; 320x240x64 single-buffered
;     ld a,20 ; 512x384x64 single-buffered
;     call vdu_set_screen_mode
;     xor a
;     call vdu_set_scaling
;     call vdu_cursor_off
    
    ret
; end init

test_fn_1: asciz "a_ha__Take_On_Me_floyd.agm"
test_fn_2: asciz "Bad_Apple_floyd.agm"
test_fn_3: asciz "Star_Wars__Battle_of_Yavin_floyd.agm"

main:
    call vdu_cls

    call printInline
    asciz "Press a number key to play a file\r\n1: "
    ld hl,test_fn_1
    call printString

    call printInline
    asciz "\r\n2: "
    ld hl,test_fn_2
    call printString

    call printInline
    asciz "\r\n3: "
    ld hl,test_fn_3
    call printString

@getkey:
    call waitKeypress
    cp '1'
    jp z,@play_1
    cp '2'
    jp z,@play_2
    cp '3'
    jp z,@play_3
    jp @getkey

@play_1:
    ld de,test_fn_1
    jp @play

@play_2:
    ld de,test_fn_2
    jp @play

@play_3:
    ld de,test_fn_3
@play:
; a=2 and zero flag reset if good .agm file (a=1 if good .wav)
; hl points to ps_fil_struct
; iy points to ps_filinfo_struct, 
; ps_wav_header and ps_agm_header structs populated
    ld iy,ps_filinfo_struct
    ld hl,ps_fil_struct
    ; ld de,test_fn ; de set above at @getkey
    call ps_play_agm 

; ; DEBUG
;     call dumpFlags
;     call dumpRegistersHex
;     call printNewLine
; ; DEBUG

    jr z,@main_end
    cp 2
    call z,ps_read_agm

@main_end:
; return display to normal
    call vdu_cursor_on

    ret ; back to MOS
; end main

; must be final include in program so file data does not stomp on program code or other data
    include "files.inc"
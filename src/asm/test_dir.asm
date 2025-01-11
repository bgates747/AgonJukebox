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
    include "fonts.inc"
    include "fonts_list.inc"
    include "fixed168.inc"
    include "timer.inc"
    include "vdu.inc"
    include "vdu_buffered_api.inc"
    include "vdu_fonts.inc"
    include "vdu_plot.inc"
    include "vdu_sound.inc"

; APPLICATION INCLUDES
    include "layout.inc"
    include "ascii.inc"
    include "input_dir.inc"
    include "play_dir.inc"
    include "timer_jukebox.inc"
    include "wav.inc"
    include "debug.inc"

; --- MAIN PROGRAM FILE ---
original_screen_mode: db 0

init:
    ret
; end init

cmd_cd_music: asciz "cd music"
cmd_cd_up: asciz "cd .."
str_dashes: asciz "------------------------------"
str_thick_dashes: asciz "=============================="

main:
; test keypress
    call waitKeypress
    cp '\e' ; escape key
    ret z ; exit if escape key pressed
    call printHexA
    call printNewLine
    jp main


; change directory to music
    ld hl,cmd_cd_music
    MOSCALL mos_oscli

; initialize the current directory
    call ps_get_dir

; list the first page of the directory
    call printInline
    asciz "\r\nPage 0\r\n"
    ld hl,0
    ld (ps_page_cur),hl
    call ps_fill_page_fn_ptrs
    call ps_print_dir_page

; ; get random songs
;     call printNewLine
;     ld b,40 ; loop counter
; @loop:
;     push bc ; save loop counter
; ; get a song from an index
;     call rand_8
;     ld h,a
;     ld l,10 ; modulo 10
;     call udiv8
;     call printHexA
;     ld (ps_song_idx_cur),a
;     call ps_get_song_fn_from_pg_idx
;     call printString
;     call printNewLine
;     pop bc ; restore loop counter
;     djnz @loop

; ; list the second page of the directory
;     call printInline
;     asciz "\r\nPage 1\r\n"
;     ld hl,1
;     ld (ps_page_cur),hl
;     call ps_fill_page_fn_ptrs
;     call ps_print_dir_page

; ; list the third page of the directory
;     call printInline
;     asciz "\r\nPage 2\r\n"
;     ld hl,2
;     ld (ps_page_cur),hl
;     call ps_fill_page_fn_ptrs
;     call ps_print_dir_page

; change back to directory containing the program
    ld hl,cmd_cd_up
    MOSCALL mos_oscli
    ret ; back to MOS
; end main

; must be final include in program so file data does not stomp on program code or other data
    include "files.inc"
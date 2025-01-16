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
    include "time.inc"
    include "timer.inc"
    include "vdu.inc"
    include "vdu_buffered_api.inc"
    include "vdu_fonts.inc"
    include "vdu_plot.inc"
    include "vdu_sound.inc"

; APPLICATION INCLUDES
    include "layout.inc"
    include "ascii.inc"
    include "input.inc"
    include "play.inc"
    include "timer_jukebox.inc"
    include "wav.inc"
    include "debug.inc"

; --- MAIN PROGRAM FILE ---
dir_up: asciz "cd .."
init:
    ld a,19 ; 1024  768   4     60hz
    call vdu_set_screen_mode
    call printNewLine
    ret
; end init
main:
    call ps_get_dir_test
    call printNewLine

    ld hl,dir_up
    MOSCALL mos_oscli

    call ps_get_dir_test
    
    ret ; back to MOS
; end main

ps_get_dir_test:
; memdump directory buffer prior to populating
    ld hl,ps_dir_path
    ld a,32
    call dumpMemoryHex
    call printNewLine

; initialize pointers to store directory info and print directory name
    ld hl,ps_dir_path  ; where to store result
    ld bc,1          ; max length (final byte is zero terminator)
    xor a ; zero-terminate the string
    MOSCALL ffs_getcwd ; MOS api get current working directory
; print the directory path (ffs_getcwd preserves hl)
    call printString
    call printNewLine
    
; memdump directory buffer after populating
    ld hl,ps_dir_path
    ld a,32
    call dumpMemoryHex
    call printNewLine
    ret
; end ps_get_dir_test

; must be final include in program so file data does not stomp on program code or other data
    include "files.inc"
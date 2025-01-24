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
    call bf_get_dir
    ret
; end init
main:
    call bf_print_dir
    call printNewLine
    ret ; back to MOS
; end main


bf_print_dir:
; set pointer to the correct index in the fileinfo pointer table
    ld ix,bf_filinfo_ptrs ; get the pointer to the fileinfo pointer table
; loop through the fileinfo pointer table and print out the filenames
    ld a,(bf_dir_num_files)
    ld b,a ; loop counter
    and a ; check for zero files in the directory
    ret z ; nothing to see here, move along
    xor a ; song index
@loop:
    push bc ; save loop counter
    push af ; save song index
    call printHexA ; print the song index
    ld iy,(ix) ; iy points to filinfo struct
    call bf_print_dir_or_file
@bump_counters:
    lea ix,ix+3 ; bump the filename pointer
    pop af ; restore song index
    inc a ; increment the song index
    pop bc ; restore loop counter
    dec b
    jp z,@done ; if zero, we're done
    call printNewLine
    jp @loop
@done:
    ret
; end bf_print_dir

; must be final include in program so file data does not stomp on program code or other data
    include "files.inc"
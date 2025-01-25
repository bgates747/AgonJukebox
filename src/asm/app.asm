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
    call ui_init
    call ps_prt_irq_init
    ret
; end init
main:
; call the change directory routine and jp to user input
    call get_input

; we come back here when user wants to quit app
; shut down everytyhing and gracefully exit to MOS
    call ps_close_file ; close any playing file and stop the PRT timer
    ei ; interrupts were disabled by get_input
; restore original screen mode
    ld a,(original_screen_mode)
    call vdu_set_screen_mode
    call vdu_reset_viewports
    call vdu_cls
; print thanks for playing message
    call printInline
    asciz "Thank you for using\r\n"
    ld hl,agon_jukebox_ascii
    call printString
; set cursor behaviuor
    call vdu_cursor_on
    ld h,%00010000 ; bit 4 controls cursor scroll at bottom of screen
    ld l,%00000000 ; bit 4 reset means cursor scrolls screen
    call vdu_cursor_behaviour
    ret ; back to MOS
; end main

; must be final include in program so file data does not stomp on program code or other data
    include "files.inc"
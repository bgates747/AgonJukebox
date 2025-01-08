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
    include "files.inc"
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
    include "ascii.inc"
    include "input.inc"
    include "music.inc"
    include "play.inc"
    include "timer_jukebox.inc"
    include "debug.inc"

; --- MAIN PROGRAM FILE ---
original_screen_mode: db 0

init:
; get current screen mode and save it so we can return to it on exit
    call vdu_get_screen_mode
    ld (original_screen_mode),a
; set up display for gameplay
    ld a,20
    call vdu_set_screen_mode
    xor a
    call vdu_set_scaling
; set text background color
    ld a,c_blue_dk+128
    call vdu_colour_text
; set text foreground color
    ld a,c_white
    call vdu_colour_text
; set the cursor off
    call vdu_cursor_off
; clear the screen
    call vdu_cls
; clear all buffers
    call vdu_clear_all_buffers
; load fonts
	call fonts_load
; select font
    ld hl,Lat7_VGA8_8x8
    ld a,1 ; flags
    call vdu_font_select
; print ascii art splash screen
    call vdu_cls
    ld c,0 ; x
    ld b,4 ; y
    call vdu_move_cursor
    call printInline
    asciz "Welcome to\r\n"
    ld hl,agon_jukebox_ascii
    call printString
    call printInline
    asciz "Press keys 0-9 to play a song...\r\n"
; load play sample command buffers
    call load_command_buffer
; initialize play sample timer interrupt handler
    call ps_prt_irq_init
    ret
; end init

main:
; ; point to first song in the index
;     ld hl,SFX_filename_index
;     ld hl,(hl) ; pointer to first song filename
;     call play_song

; call get_input to play first song
    call get_input

; shut down everytyhing and gracefully exit to MOS
    call ps_prt_stop ; stop the PRT timer
    ei ; interrupts were disabled by input handler
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
    call vdu_cursor_on
    ret ; back to MOS
; end main

; buffer for sound data
; (must be last so buffer doesn't overwrite other program code or data)
song_data:
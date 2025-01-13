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
    include "input.inc"
    include "play.inc"
    include "timer_jukebox.inc"
    include "wav.inc"
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
; print loading message
    call printInline
    asciz "Loading fonts...\r\n"
; clear all buffers
    call vdu_clear_all_buffers
; load fonts
	call fonts_load
; select font
    ld hl,Lat2_VGA8_8x8
    ld a,1 ; flags
    call vdu_font_select
; print ascii art splash screen
    call vdu_cls
    ld c,0 ; x
    ld b,4 ; y
    call vdu_move_cursor
    call printInline
    asciz "Welcome to...\r\n"
    ld hl,agon_jukebox_ascii
    call printString
; call directory page listing
    call ps_get_dir

; ; DEBUG
;     call printNewLine
;     call printInline
;     asciz "Number of files: "
;     ld hl,(ps_dir_num_files)
;     call printHexUHL

;     call printNewLine
;     call printInline
;     asciz "Number of pages: "
;     ld hl,(ps_dir_num_pages)
;     call printHexUHL

;     call printNewLine
;     call printInline
;     asciz "Number of files on last page: "
;     ld hl,(ps_pagelast_num_files)
;     call printHexUHL
;     call printNewLine

;     call DEBUG_WAITKEYPRESS
; ; END DEBUG

; print out current directory path
    call printNewLine
    ld hl,str_thick_dashes
    call printString
    call printInline
    asciz "\r\nOur current directory is:\r\n"
    ld hl,ps_dir_path
    call printString
    call printNewLine
    ld hl,str_thick_dashes
    call printString
; print instructions
    call printInline
    asciz "\r\nPress keys 0-9 to play a song:\r\n"
    ld hl,str_dashes
    call printString
; print first 10 files in the directory
    xor a ; song index to 0
    ld (ps_song_idx_cur),a
    call printNewLine
    call ps_print_dir_page
    ; call print_dir_border_bottom
; initialize play sample timer interrupt handler
    call ps_prt_irq_init
    ret
; end init

str_dashes: asciz "---------------------------------------------------------------"
str_thick_dashes: asciz "==============================================================="

main:
; call get_input to start player
    call get_input
; user pressed ESC to quit so shut down everytyhing and gracefully exit to MOS
    call ps_prt_stop ; stop the PRT timer
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
    call vdu_cursor_on
    ret ; back to MOS
; end main

; must be final include in program so file data does not stomp on program code or other data
    include "files.inc"
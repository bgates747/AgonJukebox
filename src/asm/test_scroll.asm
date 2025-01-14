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
; ; print loading message
;     call printInline
;     asciz "Loading fonts...\r\n"
; clear all buffers
    call vdu_clear_all_buffers
; load fonts
	call fonts_load
; select font
    ld hl,Lat2_VGA8_8x8
    ld a,1 ; flags
    call vdu_font_select
    ret
; end init

str_dashes_thin: asciz  "----------------------------------------------------------------"
str_dashes_thick: asciz "================================================================"

str_comfortably_numb: asciz "Hello, is there anybody in there? Just nod if you can hear me. Is there anyone at home?"
str_text_at_text_cursor: asciz "This should be printed at the text cursor location."

main:
; set a gfx viewport to a single text line
    ld bc,0*8 ; x0
    ld de,10*8 ; y0
    ld ix,[63*8]-1 ; x1
    ld iy,[11*8]-1 ; y1
    call vdu_set_gfx_viewport

; set gfx cursor to carry on off edge of viewport
    ld h,%01000000 ; mask to change value of bit 6
    ld l,%01000000 ; bit 6 set is carry on
    call vdu_cursor_behaviour

; print a test string wider than screen
    ld bc,0*8 ; x
    ld de,10*8 ; y
    ld hl,str_comfortably_numb
    call vdu_print_to_gfx_location

; move text cursor and print a test string at the text cursor location
    ld c,10 ; x
    ld b,5 ; y
    ld hl,str_text_at_text_cursor
    call vdu_print_to_text_location

    call waitKeypress

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

; ; put screen back to regular operation
;     ld h,%00000001 ; mask to change value of bit 0 (scroll protection)
;     ld l,%00000000 ; bit 0 reset is scroll protection off
;     call vdu_cursor_behaviour ; set scroll protection off

    call vdu_cursor_on
    ret ; back to MOS
; end main

; must be final include in program so file data does not stomp on program code or other data
    include "files.inc"
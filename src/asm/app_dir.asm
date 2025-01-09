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
    include "ascii.inc"
    include "input.inc"
    include "music.inc"
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
    call printInline
    asciz "Press keys 0-9 to play a song.\r\n"
; initialize play sample timer interrupt handler
    call ps_prt_irq_init
    ret
; end init

cmd_cd_music: asciz "cd music"
cmd_cd_up: asciz "cd .."
main:
; ; call get_input to start player
;     call get_input
; change directory to music
    ld hl,cmd_cd_music
    MOSCALL mos_oscli
; call directory listing test
    call get_dir
    call print_dir
; user pressed ESC to quit so shut down everytyhing and gracefully exit to MOS
    call ps_prt_stop ; stop the PRT timer
    ei ; interrupts were disabled by get_input
; ; restore original screen mode
;     ld a,(original_screen_mode)
;     call vdu_set_screen_mode
;     call vdu_reset_viewports
;     call vdu_cls
; change back to directory containing the program
    ld hl,cmd_cd_up
    MOSCALL mos_oscli
; print thanks for playing message
    call printInline
    asciz "Thank you for using\r\n"
    ld hl,agon_jukebox_ascii
    call printString
    call vdu_cursor_on
    ret ; back to MOS
; end main

get_dir:
; reset filecounter
    ld hl,0
    ld (ps_dir_num_files),hl

; initialize pointers to store directory info
    ld hl,ps_dir_path  ; where to store result
    ld bc,255          ; max length
    MOSCALL ffs_getcwd ; MOS api get current working directory

; print out current directory path
    call printInline
    asciz "Our current directory is:\r\n"
    ld hl,ps_dir_path
    call printString
    call printNewLine

; now get dir info
    ld hl,ps_dir_struct ; define where to store directory info
    ld de,ps_dir_path   ; this is pointer to the path to the directory
    MOSCALL ffs_dopen   ; open dir

_readFileInfo:               ; we will loop here until all files have been processed
    ld hl,ps_dir_struct      ; HL is where to get directory info
    ld de,ps_filinfo_struct  ; define where to store current file info
    MOSCALL ffs_dread        ; read next item from dir

    ld a,(ps_filinfo_fname)  ; get first char of file name
    cp 0                     ; if 0 then we are at the end of the listing
    jr z,_allDone

    ld de,(ps_dir_num_files) ; get the current file counter
    ld hl,256 ; bytes per filename
    call umul24 ; hl = offset into the filename table
    inc de                  ; increment the counter
    ld (ps_dir_num_files),de
    ld de,ps_dir_fil_list ; get the address of the filename table
    add hl,de ; add the offset to the base address
    ex de,hl ; de is the destination address to copy the filename
    ld hl,ps_filinfo_fname   ; this is pointer to the name of current file
    ld bc,256 ; bytes per filename
    ldir ; copy the filename to the filename table

    jr _readFileInfo         ; loop around to check next entry

_allDone:
    ld hl,ps_dir_struct      ; load H: with address of the DIR struct
    MOSCALL ffs_dclose       ; close dir
    ret
; end get_dir

print_dir:
; loop through the filename table and print out the filenames
    ld ix,ps_dir_fil_list      ; get the address of the filename table
    ld hl,(ps_dir_num_files)   ; get the number of files 
    push hl ; save loop counter
_print_loop:
    push ix
    pop hl ; get the address of the filename
    call printString
    call printNewLine
    lea ix,ix+127 ; bump the pointer
    lea ix,ix+127 ; to the next file
    lea ix,ix+2   ; 256 bytes
    pop hl ; get the loop counter
    dec hl ; decrement the loop counter
    push hl ; save loop counter
    SIGN_HLU ; check for zero
    jr nz,_print_loop
    pop hl ; dummy pop to balance stack
    ret
; end print_dir


; THIS MUST BE LAST INCLUDE SO FILE DATA DOES NOT OVERWRITE OTHER CODE OR DATA
    include "files.inc"

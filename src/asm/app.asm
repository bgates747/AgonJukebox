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

; JukeBox Structure (JB)
;
; Indexes into JukeBox structure
jb_filehandle:          EQU 0          ;   1: File handle
jb_file_idx:            EQU jb_filehandle+1  ;   1: Current file index in the directory page
jb_filename:            EQU jb_file_idx+1    ;   3: Pointer to current file filename
jb_dir_num_files:       EQU jb_filename+3    ;   3: Number of files/directories in the directory (virtually unlimited)
jb_pagelast_num_files:  EQU jb_dir_num_files+3  ;   3: Mod(jb_dir_num_files, 10)
jb_page_cur:            EQU jb_pagelast_num_files+3  ;   3: Current directory page number
jb_dir_num_pages:       EQU jb_page_cur+3    ;   3: Number of pages in the directory (virtually unlimited)
jb_filename_ptrs:       EQU jb_dir_num_pages+3  ;  30: List of filename pointers in the current directory page (10*3)
jb_dir_path:            EQU jb_filename_ptrs+30 ; 256: Path of the current directory
jb_struct_size:         EQU jb_dir_path+256  ; Total size of the JB structure

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
    include "ascii.inc"
    include "input.inc"
    include "play.inc"
    include "timer_jukebox.inc"
    include "wav.inc"
    include "debug.inc"

; --- MAIN PROGRAM FILE ---
init:
    call ui_init
    call ps_get_dir
    call ps_prt_irq_init
    ret
; end init
main:
; call the change directory routine and jp to user input
    call ps_get_dir
    call get_input

; we come back here when user wants to quit app
; shut down everytyhing and gracefully exit to MOS
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
; set cursor behaviuor
    call vdu_cursor_on
    ld h,%00010000 ; bit 4 controls cursor scroll at bottom of screen
    ld l,%00000000 ; bit 4 reset means cursor scrolls screen
    call vdu_cursor_behaviour
    ret ; back to MOS
; end main

; must be final include in program so file data does not stomp on program code or other data
    include "files.inc"
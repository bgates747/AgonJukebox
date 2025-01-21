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
jb_pagelast_num_files:  EQU jb_dir_num_files+3  ;   3: Mod(jb_dir_num_files, bf_num_files_pg)
jb_page_cur:            EQU jb_pagelast_num_files+3  ;   3: Current directory page number
jb_dir_num_pages:       EQU jb_page_cur+3    ;   3: Number of pages in the directory (virtually unlimited)
jb_filinfo_ptrs:       EQU jb_dir_num_pages+3  ;  30: List of filename pointers in the current directory page (bf_num_files_pg*3)
jb_dir_path:            EQU jb_filinfo_ptrs+30 ; 256: Path of the current directory
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
    ; include "ascii.inc"
    include "browse.inc"
    include "input.inc"
    include "play.inc"
    include "timer_jukebox.inc"
    include "wav.inc"
    include "debug.inc"

; --- MAIN PROGRAM FILE ---
init:

    ret
; end init
main:
    ld ix,ix_data
    ld hl,0x012345
    ld (ix),hl

    ld iy,iy_data

    call DEBUG_PRINT

    ld iy,(ix) ; this was the bug

    call DEBUG_PRINT

    ret ; back to MOS
; end main

ix_data: dl 0
iy_data: dl 0

; must be final include in program so file data does not stomp on program code or other data
    include "files.inc"
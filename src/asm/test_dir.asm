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
    ret
; end init

cmd_cd_music: asciz "cd music"
cmd_cd_up: asciz "cd .."
str_dashes: asciz "------------------------------"
str_thick_dashes: asciz "=============================="

main:
; change directory to music
    ld hl,cmd_cd_music
    MOSCALL mos_oscli

; initialize the current directory
    call get_dir

; list all the files in the directory
    call printInline
    asciz "\r\nFiles in directory\r\n"
    call print_dir

; change back to directory containing the program
    ld hl,cmd_cd_up
    MOSCALL mos_oscli
    ret ; back to MOS
; end main

get_dir:
; reset filecounter
    ld hl,0
    ld (ps_dir_num_files),hl
; initialize pointers to store directory info
    ld hl,ps_dir_path  ; where to store result
    ld bc,255          ; max length (final byte is zero terminator)
    MOSCALL ffs_getcwd ; MOS api get current working directory
; now get dir info
    ld hl,ps_dir_struct ; define where to store directory info
    ld de,ps_dir_path   ; this is pointer to the path to the directory
    MOSCALL ffs_dopen   ; open dir
@readFileInfo:               ; we will loop here until all files have been processed
    ld hl,ps_dir_struct      ; HL is where to get directory info
    ld de,ps_file_struct  ; define where to store current file info
    MOSCALL ffs_dread        ; read next item from dir
    ld a,(ps_file_fname)  ; get first char of file name
    or a                     ; if zero then we are at the end of the listing
    jp z,@allDone
    ld de,(ps_dir_num_files) ; get the current file counter
    ld hl,filinfo_struct_size ; bytes per filename
    call umul24 ; hl = offset into the fileinfo table
    inc de                  ; increment the counter
    ld (ps_dir_num_files),de
    ld de,ps_dir_fil_list+filinfo_fname ; get the address of the fileinfo table plus the offset to the filename
    add hl,de ; add the offset to the base address
    ex de,hl ; de is the destination address to copy the filename
    ld hl,ps_file_fname   ; this is pointer to the name of current file
    ld bc,filinfo_struct_size ; bytes per filename
    ldir ; copy the filename to the fileinfo table
    jp @readFileInfo         ; loop around to check next entry
@allDone:
; compute page statistics
    ld hl,(ps_dir_num_files) ; get the number of files
    ld de,10 ; max files per page
    call udiv24 ; de = hl/10, hl = mod(hl,10)
    SIGN_HLU ; check remainder for zero
    jp z,@F ; if zero then we have exactly 10 files
    inc de ; bump the page count
@@:
    ld (ps_dir_num_pages),de ; save the number of pages
    ld (ps_pagelast_num_files),hl ; save the number of files on the last page
; reset the song index and page to zero and populate the page filename pointers
    xor a
    ld (ps_song_idx_cur),a
    ld hl,0 
    ld (ps_page_cur),hl
    call ps_fill_page_fn_ptrs
; close the directory
    ld hl,ps_dir_struct      ; load H: with address of the DIR struct
    MOSCALL ffs_dclose       ; close dir
    ret
; end get_dir

print_dir:
; loop through the fileinfo table and print out the filenames
    ld ix,ps_dir_fil_list
    ld hl,(ps_dir_num_files)
@print_loop:
    push hl ; loop counter
    ld a,(ix+filinfo_fattrib)
    call printHexA

    lea ix,ix+filinfo_fname ; point to filinfo_fname
    push ix
    pop hl ; get the address of the filename
    call printString
    call printNewLine

    ld de,256 ; length of filename
    add ix,de ; bump pointer to next filinfo record
    pop hl 
    dec hl ; decrement the loop counter
    SIGN_HLU ; check for zero
    jp nz,@print_loop
    ret
; end print_dir


; print_dir:
; ; loop through the fileinfo table and print out the filenames
;     ld ix,ps_dir_fil_list+filinfo_fname ; address of the fileinfo table plus the offset to the filename
;     ld hl,(ps_dir_num_files)   ; get the number of files 
;     push hl ; save loop counter
; @print_loop:
;     ld a,(ix+filinfo_fattrib)
;     or a ; if zero, is a directory
;     jp nz,@F
;     call printInline
;     asciz "<DIR> "
; @@:
;     push ix
;     pop hl ; get the address of the filename
;     call printString
;     call printNewLine
;     ld de,filinfo_struct_size ; length of filename record
;     add ix,de ; bump pointer to next filename
;     pop hl ; get the loop counter
;     dec hl ; decrement the loop counter
;     push hl ; save loop counter
;     SIGN_HLU ; check for zero
;     jp nz,@print_loop
;     pop hl ; dummy pop to balance stack
;     ret
; ; end print_dir

; must be final include in program so file data does not stomp on program code or other data
    include "files.inc"
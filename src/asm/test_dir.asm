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
str_dashes_thin: asciz "------------------------------"
str_dashes_thick: asciz "=============================="

main:
; initialize the current directory
    call get_dir

; list all the files in the directory
    call printInline
    asciz "\r\nFiles in directory\r\n"
    call print_dir
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
; set up pointers
    ld ix,ps_dir_fil_list ; this is the pointer to the fileinfo table
@readFileInfo:               ; we will loop here until all files have been processed
    ld hl,ps_dir_struct      ; HL is where to get directory info
    push ix
    pop de ; where to store current file info
    MOSCALL ffs_dread        ; read next item from dir

    ld a,(ix+filinfo_fname)  ; get first char of file name
    or a                     ; if zero then we are at the end of the listing
    jp z,@allDone

    ld a,(ix+filinfo_fattrib) ; get the file attribute
    res 5,a ; clear bit 5 (archive) see: https://discord.com/channels/1158535358624039014/1158536667670511726/1328466726098309173
    or a ; if zero this is a file
    jp nz,@F ; not zero so this is some other file type
    set 5,a ; set bit 5 (archive) so will be consistent btw emulator and hardware
    ld (ix+filinfo_fattrib),a ; update so we don't have to do this every time downstream

@@: ; skip over writing hidden and system files
    and AM_HID ; hidden file
    jp nz,@readFileInfo
    and AM_SYS ; system file
    jp nz,@readFileInfo

; valid file or directory
    ld hl,(ps_dir_num_files) ; get the current file counter
    inc hl                  ; increment the counter
    ld (ps_dir_num_files),hl
    ld de,filinfo_struct_size ; length of fileinfo record
    add ix,de ; point to next fileinfo record

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

; DEBUG
    call printNewLine
    call printInline
    asciz "Number of files: "
    ld hl,(ps_dir_num_files)
    call printHexUHL

    call printNewLine
    call printInline
    asciz "Number of pages: "
    ld hl,(ps_dir_num_pages)
    call printHexUHL

    call printNewLine
    call printInline
    asciz "Number of files on last page: "
    ld hl,(ps_pagelast_num_files)
    call printHexUHL
    call printNewLine
; END DEBUG
    ret
; end get_dir

print_dir:
; test whether there are any files in the directory
    ld hl,(ps_dir_num_files)
    SIGN_HLU
    ret z ; if zero, no files in the directory
; loop through the fileinfo table and print out the filenames
    ld ix,ps_dir_fil_list
    ld hl,(ps_dir_num_files)
@print_loop:
    push hl ; loop counter
; branch on the file attribute
    ld a,(ix+filinfo_fattrib)
; DEBUG
    PUSH_ALL
    call printBin8
    ld a,' '
    rst.lil 10h
    POP_ALL
; END DEBUG
    cp AM_DIR ; if zero, is directory
    jp nz,@print_file ; not directory so just write filename
    call printInline
    asciz "<DIR> "
@print_file:
    lea ix,ix+filinfo_fname ; point to filinfo_fname
    push ix
    pop hl ; get the address of the filename
    call printString
    call printNewLine
    ld de,256 ; length of filename
    add ix,de ; bump pointer to next filinfo record
@dec_loop_counter:
    pop hl 
    dec hl ; decrement the loop counter
    SIGN_HLU ; check for zero
    jp nz,@print_loop
    ret
@skip_file:
    ld de,filinfo_struct_size 
    add ix,de ; bump pointer to next filinfo record
    jp @dec_loop_counter
; end print_dir

; must be final include in program so file data does not stomp on program code or other data
    include "files.inc"
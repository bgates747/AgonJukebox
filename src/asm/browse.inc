bf_files_per_pg: equ 10 ; number of directories / files to display per page

bf_get_dir:
; initialize counters
    ld hl,0
    ld (bf_dir_num_files),hl

; initialize pointers to store directory info and print directory name
    ld hl,bf_dir_path  ; where to store result
    ld bc,255          ; max length (final byte is zero terminator) [has no effect]
    FFSCALL ffs_getcwd ; MOS api get current working directory

; get dir info
    ld hl,bf_dir_struct ; define where to store directory info
    ld de,bf_dir_path   ; this is pointer to the path to the directory
    xor a               ; tell MOS to expect zero-terminated string
    FFSCALL ffs_dopen   ; open dir

; set up pointers
    ld ix,bf_dir_fil_list ; this is the pointer to the filinfo structs
    ld iy,bf_filinfo_ptrs ; where to store pointers to filinfo structs

@readFileInfo:               ; we will loop here until all files have been processed
    ld hl,bf_dir_struct      ; HL is where to get directory info
    lea de,ix                ; DE is where to store filinfo struct
    FFSCALL ffs_dread        ; read next item from dir into filinfo struct

    ld a,(ix+filinfo_fname)  ; get first char of file name
    or a                     ; if zero then we are at the end of the listing
    jp z,@allDone

    ld a,(ix+filinfo_fattrib) ; get the file attribute
    res AM_ARC,a ; clear bit 5 (archive) see: https://discord.com/channels/1158535358624039014/1158536667670511726/1328466726098309173
    or a ; if zero this is a file
    jp nz,@F ; not zero so this is some other file type
    set AM_ARC,a ; set bit 5 (archive) so will be consistent btw emulator and hardware
    ld (ix+filinfo_fattrib),a ; update so we don't have to do this every time downstream
    
@@: ; skip over writing hidden and system files
    bit AM_HID,a ; hidden file
    jp nz,@readFileInfo
    bit AM_SYS,a ; system file
    jp nz,@readFileInfo

; check for valid directory
    bit AM_DIR,a ; directory
    jp nz,@goodPath ; is directory so skip .wav file check

; is file so check for valid .wav format
    ld hl,bf_fil_struct ; hl = pointer to fil struct
    lea de,ix+filinfo_fname ; de = pointer to filename
    call verify_wav
    jp nz,@readFileInfo ; not a .wav file, so skip it

@goodPath:
; valid file or directory
    ld (iy),ix ; store pointer to filinfo struct
    ld hl,(bf_dir_num_files) ; get the current file counter
    inc hl                  ; increment the counter
    ld (bf_dir_num_files),hl
; bump pointers
    lea iy,iy+3 
    ld de,filinfo_struct_size ; length of filinfo record
    add ix,de 
    jp @readFileInfo         ; loop around to check next entry
@allDone: 
; compute page statistics
    ld de,bf_files_per_pg    ; number of files per page
    ld hl,(bf_dir_num_files) ; get the number of files
    SIGN_HLU ; check for zero
    jp nz,@not_zero
    ld de,0 ; number of pages, will increment by 1 later
    ld hl,0 ; number of files on last page
    jp @write_stats
@not_zero:
    call udiv24 ; de = hl/bf_files_per_pg, hl = mod(hl,bf_files_per_pg)
    SIGN_HLU ; check remainder for zero
    jp nz,@write_stats
    ld hl,bf_files_per_pg ; if zero then we have exactly bf_files_per_pg files on the last page ...
    dec de ; ... and we don't need an additional page for the remainder
@write_stats:
    ld (bf_files_last_pg),hl ; save the number of files on the last page
    inc de ; bump the page count
    ld (bf_dir_num_pages),de ; save the number of pages
    ld hl,0 ; reset the page number
    ld (bf_page_cur),hl
; close the directory
    ld hl,bf_dir_struct      ; load H: with address of the DIR struct
    FFSCALL ffs_dclose       ; close dir
; fall through to bf_get_page_num_files

bf_get_page_num_files:
; check whether we're at last page
    ld hl,(bf_page_cur)
    ld de,(bf_dir_num_pages)
    dec de ; zero-based
    or a ; clear carry
    sbc hl,de
    ld a,bf_files_per_pg ; a = default number of files per page
    jp nz,@F ; not the last page
    ld a,(bf_files_last_pg) ; get the number of files on the last page
@@:
    ld (bf_files_cur_pg),a ; save the number of files on the page
    ret
; end bf_get_page_num_files
; end bf_get_dir

bf_print_dir_page:
; set text viewport for directory listing
    call vp_dir
    call vdu_cls
; check for zero files in directory
    ld hl,(bf_dir_num_files)
    SIGN_HLU
    ret z ; no files to display so we're done
; set pointer to the correct index in the fileinfo pointer table
    ld hl,(bf_page_cur) ; get the current page
    ld de,bf_files_per_pg*3 ; number of files per page * 3 bytes per pointer
    call umul24 ; hl = page * num_files_per_page
    ex de,hl ; can't add ix,hl ...
    ld ix,bf_filinfo_ptrs ; get the pointer to the fileinfo pointer table
    add ix,de ; ix points to the correct index in the fileinfo pointer table
; loop through the fileinfo pointer table and print out the filenames
    ld a,(bf_files_cur_pg)
    ld b,a ; loop counter
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
    or a,1 ; reset zero flag indicating there were files to display
    ret
; end bf_print_dir_page

bf_highlight_file:
; refresh the directory listing
    call bf_print_dir_page
    ret z ; no files to display so we're done
; highlight the song being played in the directory listing
    ld a,(bf_file_idx)
    ld d,vp_dir_top
    add a,d
    ld c,text_left
    ld d,a
    ld e,text_right
    ld b,a
    call vdu_set_txt_viewport
    call vdu_cls
; set text colours to inverse
    call set_text_colours_inverse
; print the index and song filename
    ld a,(bf_file_idx)
    call printHexA
    call bf_get_filinfo_from_pg_idx ; iy = pointer to the filinfo struct
    call bf_print_dir_or_file
; set text colours to normal
    call set_text_colours_normal
    ret
; end bf_highlight_file

bf_check_dir_or_file:
    ld a,(iy+filinfo_fattrib)
    bit AM_DIR,a ; if not zero, is directory
    ret
; end bf_check_dir_or_file

bf_print_dir_or_file:
    call bf_check_dir_or_file
    jp z,@print_file ; not directory so just write filename
    call printInline
    asciz "<DIR> "
@print_file:
    lea hl,iy+filinfo_fname
    call printString ; print the filename
    ret
; end bf_print_dir_or_file

bf_print_dir_name:
    call vp_dir_name
    call vdu_cls
    ld hl,bf_dir_path
    call printString
    ret
; end bf_print_dir_name
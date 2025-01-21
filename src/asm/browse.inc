
bf_get_dir:
; set text viewport to directory name and clear it
    call vp_dir_name
    call vdu_cls
; reset filecounter
    ld hl,0
    ld (bf_dir_num_files),hl
; reset the song index and page number to 0
    xor a
    ld (bf_file_idx),a
    ld hl,0
    ld (bf_page_cur),hl
; initialize pointers to store directory info and print directory name
    ld hl,bf_dir_path  ; where to store result
; note: setting bc has no apparent effect, but we leave it for consistency with docs
; https://agonconsole8.github.io/agon-docs/MOS-API/#0x9e-ffs_getcwd
    ld bc,255          ; max length (final byte is zero terminator)
    MOSCALL ffs_getcwd ; MOS api get current working directory
; print the directory path (ffs_getcwd preserves hl)
    call printString
; now get dir info
    ld hl,bf_dir_struct ; define where to store directory info
    ld de,bf_dir_path   ; this is pointer to the path to the directory
    xor a               ; tell MOS to expect zero-terminated string
    MOSCALL ffs_dopen   ; open dir
; set up pointers
    ld ix,bf_dir_fil_list ; this is the pointer to the fileinfo table
@readFileInfo:               ; we will loop here until all files have been processed
    ld hl,bf_dir_struct      ; HL is where to get directory info
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
    ld hl,(bf_dir_num_files) ; get the current file counter
    inc hl                  ; increment the counter
    ld (bf_dir_num_files),hl
    ld de,filinfo_struct_size ; length of fileinfo record
    add ix,de ; point to next fileinfo record

    jp @readFileInfo         ; loop around to check next entry
@allDone:
; compute page statistics
    ld hl,(bf_dir_num_files) ; get the number of files
    ld de,10 ; max files per page
    call udiv24 ; de = hl/10, hl = mod(hl,10)
    SIGN_HLU ; check remainder for zero
    jp nz,@F 
    ld hl,10 ; if zero then we have exactly 10 files on the last page ...
    dec de ; ... and we don't need an additional page for the remainder
@@:
    ld (bf_dir_num_files_lp),hl ; save the number of files on the last page
    inc de ; bump the page count
    ld (bf_dir_num_pages),de ; save the number of pages
; reset the song index and page to zero  
    xor a
    ld (bf_file_idx),a
    ld hl,0 
    ld (bf_page_cur),hl
; and populate the page filename pointers and print the page
    call bf_fill_page_fn_ptrs
    call bf_print_dir_page
; close the directory
    ld hl,bf_dir_struct      ; load H: with address of the DIR struct
    MOSCALL ffs_dclose       ; close dir
    ret
; end bf_get_dir

; populate the page filename pointers for the current directory page
; inputs: bf_page_cur
; prerequisites: bf_get_dir called on a valid directory
; outputs: a populated filename pointer list for the current page
; destroys: a, hl, bc, de, ix
bf_fill_page_fn_ptrs:
    ld hl,(bf_page_cur) ; get the current page number
    ld de,10*filinfo_struct_size ; records/page * bytes/record
    call umul24 ; hl = offset into the fileinfo table
    ld de,bf_dir_fil_list ; base address of fileinfo table
    add hl,de ; add the offset to the base address
    ld ix,bf_filinfo_ptrs ; get the address of the page fileinfo pointer table
    ld de,filinfo_struct_size ; bytes per filename record
    ld b,10 ; number of files per page
@loop:
    ld (ix),hl ; store the filename pointer
    lea ix,ix+3 ; bump the index pointer
    add hl,de ; add the record size to the filename pointer
    djnz @loop
    ret
; end bf_fill_page_fn_ptrs

bf_get_page_num_files:
; check whether we're at last page
    ld hl,(bf_page_cur)
    ld de,(bf_dir_num_pages)
    dec de ; zero-based
    or a ; clear carry
    sbc hl,de
    ld b,10 ; b = default number of files per page
    ret nz ; not the last page
    ld a,(bf_dir_num_files_lp) ; get the number of files on the last page
    ld b,a ; b = number of files on the last page
    ret
; end bf_get_page_num_files

bf_print_dir_page:
; set text viewport for directory listing
    call vp_dir
    call vdu_cls
; loop through the fileinfo pointer table and print out the filenames
    call bf_get_page_num_files ; b = loop counter
    xor a ; song index
    ld ix,bf_filinfo_ptrs
@loop:
    push bc ; save loop counter
    push af ; save song index
    call printHexA ; print the song index
; branch on the file attribute
    ld hl,(ix) ; get the filename pointer
    ld bc,filinfo_fattrib
    add hl,bc ; hl points to the file attribute
    ld a,(hl)
    cp AM_DIR ; if zero, is directory
    jp nz,@print_file ; not directory so just write filename
    push hl
    call printInline
    asciz "<DIR> "
    pop hl
@print_file:
    ld bc,filinfo_fname-filinfo_fattrib ; offset to the filename
    add hl,bc ; hl points to the filename
    call printString ; print the filename
@bump_counters:
    lea ix,ix+3 ; bump the filename pointer
    pop af ; restore song index
    inc a ; increment the song index
    pop bc ; restore loop counter
    dec b
    ret z ; if zero, we're done
    call printNewLine
    jp @loop
    ret
; end bf_print_dir_page
bf_highlight_song:
; refresh the directory listing
    call bf_print_dir_page
; highlight the song being played in the directory listing
    ld a,(bf_file_idx)
    ld d,vp_dir_top
    add a,d
    ld c,text_left
    ld d,a
    ld e,text_right
    ld b,a
    call vdu_set_txt_viewport
    call vdu_home_cursor
; set text colours to inverse
    call set_text_colours_inverse
; print the index and song filename
    ld a,(bf_file_idx)
    call printHexA
    ld hl,bf_filinfo_fname
    call printString
; set text colours to normal
    call set_text_colours_normal
    ret
; end bf_highlight_song

; change directory one level up
; inputs: none
bf_up_dir:
    ld hl,@str_up_dir
    MOSCALL mos_cd ; change to the directory
    call bf_get_dir ; get directory listing
    jp get_input ; back to main loop
@str_up_dir: asciz ".."
; end bf_up_dir

bf_dir_next_page:
; advance the page number
    ld hl,(bf_page_cur) ; get the current page number
    inc hl ; increment the page number
    ld de,(bf_dir_num_pages) ; get the number of pages
    call udiv24 ; hl = mod(bf_page_cur+1,bf_dir_num_pages)
    ld (bf_page_cur),hl ; save the new page number
; populate the page filename pointers
    call bf_fill_page_fn_ptrs
; print the new page
    call bf_print_dir_page
; enable interrupts and jump back to the user input loop
    ei
    jp get_input
; end bf_dir_next_page

bf_dir_prev_page:
; decrement the page number
    ld hl,(bf_page_cur) ; get the current page number
    dec hl ; decrement the page number
    SIGN_HLU ; check for zero
    jp p,@F ; >= 0 so we're good
    ld hl,(bf_dir_num_pages) ; get the number of pages
    dec hl ; zero-based
@@:
    ld (bf_page_cur),hl ; save the new page number
; populate the page filename pointers
    call bf_fill_page_fn_ptrs
; print the new page and
    call bf_print_dir_page
; enable interrupts and jump back to the user input loop
    ei
    jp get_input
; end bf_dir_prev_page

; get the filename of the song at the current index
; inputs: a = song index
; returns: carry set if song index in range, new filemame in hl and bf_file_idx, bf_filinfo_fname set to new index, a = file attribute
;          carry reset if song index out of range, current filename in hl, bf_file_idx, bf_filinfo_fname unchanged, a = requested song index
; destroys: af, bc, de
bf_get_file_from_pg_idx:
    push af ; save song index
    call bf_get_page_num_files ; b = number of files on the page
    pop af ; restore song index
    cp b ; compare song index to number of files on the page
    ld hl,bf_filinfo_fname ; get the current song filename
    ret nc ; requested song index is out of range so return current filename and no carry








    
    ld (bf_file_idx),a ; save the song index
    ld ix,bf_filinfo_ptrs ; get the address of the page fileinfo pointer table
    ld b,a ; song index
    ld c,3 ; 3 bytes per filename pointer
    mlt bc ; index into the fileinfo pointer table
    add ix,bc ; hl points to the fileinfo pointer

    ld hl,(ix) ; hl points to the fileinfo
    ld bc,filinfo_fattrib ; offset to the file attribute
    add hl,bc ; hl points to the file attribute
    ld a,(hl) ; get the file attribute for determining file vs. directory

    ld hl,(ix) ; hl points to the fileinfo
    ld bc,filinfo_fname ; offset to the filename
    add hl,bc ; hl points to the filename
    ; ld bf_filinfo_fname,hl ; save the new song filename DEPRECATED:
    scf ; set carry to indicate success
    ret
; end bf_get_file_from_pg_idx
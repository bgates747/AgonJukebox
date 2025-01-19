bs_get_dir:
    ld iy,bs_jukebox_struct
; reset filecounter
    ld hl,0
    ld (iy+jb_dir_num_files),hl
; initialize pointers to store directory info and print directory name
    push iy
    pop hl
    ld de,jb_dir_path
    add hl,de ; where to store the result
; note: setting bc has no apparent effect, but we leave it for consistency with docs
; https://agonconsole8.github.io/agon-docs/MOS-API/#0x9e-ffs_getcwd
    ld bc,255          ; max length (final byte is zero terminator)
    FFSCALL ffs_getcwd ; MOS api get current working directory
; now get dir info
    push iy
    pop hl
    ld de,jb_dir_path
    add hl,de 
    ex de,hl ; de points to the directory path
    ld hl,(iy+jb_dir_struct)      ; HL is where to store directory info
    xor a               ; tell MOS to expect zero-terminated string
    FFSCALL ffs_dopen   ; open dir
; set up pointers
    ld ix,(iy+jb_dir_fil_list) ; this is the pointer to the fileinfo table
@readFileInfo:               ; we will loop here until all files have been processed
    ld hl,(iy+jb_dir_struct)      ; HL is where to get directory info
    push ix
    pop de ; where to store current file info
    FFSCALL ffs_dread        ; read next item from dir
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
    ld hl,(iy+jb_dir_num_files) ; get the current file counter
    inc hl                  ; increment the counter
    ld (iy+jb_dir_num_files),hl
    ld de,filinfo_struct_size ; length of fileinfo record
    add ix,de ; point to next fileinfo record

    jp @readFileInfo         ; loop around to check next entry
@allDone:
; compute page statistics
    ld hl,(iy+jb_dir_num_files) ; get the number of files
    ld de,10 ; max files per page
    call udiv24 ; de = hl/10, hl = mod(hl,10)
    SIGN_HLU ; check remainder for zero
    jp nz,@F 
    ld hl,10 ; if zero then we have exactly 10 files on the last page ...
    dec de ; ... and we don't need an additional page for the remainder
@@:
    ld (iy+jb_pagelast_num_files),hl ; save the number of files on the last page
    inc de ; bump the page count
    ld (iy+jb_dir_num_pages),de ; save the number of pages
; reset the file index and page to zero  
    xor a
    ld (iy+jb_file_idx),a
    ld hl,0 
    ld (iy+jb_page_cur),hl
; ; populate the page filename pointers
;   call bs_fill_page_fn_ptrs
;    call bs_print_dir_page
; close the directory
    ld hl,(iy+jb_dir_struct)      ; load H: with address of the DIR struct
    FFSCALL ffs_dclose       ; close dir
    ret
; end bs_get_dir

; populate the page filename pointers for the current directory page
; inputs: none
; prerequisites: bs_get_dir called on a valid directory
; outputs: a populated filename pointer list for the current page
; destroys: a, hl, bc, de, ix
bs_fill_page_fn_ptrs:
    ld iy,bs_jukebox_struct
    ld hl,(iy+jb_page_cur) ; get the current page number
    ld de,10*filinfo_struct_size ; records/page * bytes/record
    call umul24 ; hl = offset into the fileinfo table
    ld de,(iy+jb_dir_fil_list) ; base address of fileinfo table
    add hl,de ; add the offset to the base address
    ; ld ix,iy+jb_filename_ptrs ; get the address of the page fileinfo pointer table
    ld ix,0
    lea ix,iy+jb_filename_ptrs 
    ld de,filinfo_struct_size ; bytes per filename record
    ld b,10 ; number of files per page
@loop:
    ld (ix),hl ; store the filename pointer
    lea ix,ix+3 ; bump the index pointer
    add hl,de ; add the record size to the filename pointer
    djnz @loop
    ret
; end bs_fill_page_fn_ptrs

ps_get_page_num_files:
    ld iy,ps_jukebox_struct
jb_get_page_num_files:
; check whether we're at last page
    ld hl,(iy+jb_page_cur)
    ld de,(iy+jb_dir_num_pages)
    dec de ; zero-based
    or a ; clear carry
    sbc hl,de
    ld b,10 ; b = default number of files per page
    ret nz ; not the last page
    ld a,(iy+jb_pagelast_num_files) ; get the number of files on the last page
    ld b,a ; b = number of files on the last page
    ret
; end jb_get_page_num_files

bs_print_dir_page:
    ld iy,bs_jukebox_struct
    jp bs_print_dir_page
ps_print_dir_page:
    ld iy,ps_jukebox_struct
bs_print_dir_page:
; populate the page filename pointers
    call bs_fill_page_fn_ptrs
; set text viewport for directory listing
    call vp_dir
    call vdu_cls
; loop through the fileinfo pointer table and print out the filenames
    call jb_get_page_num_files ; b = loop counter
    xor a ; song index
    ld ix,0
    lea ix,iy+jb_filename_ptrs
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
; end bs_print_dir_page

bs_highlight_song:
    ld iy,bs_jukebox_struct
    jp jb_highlight_song
ps_highlight_song:
    ld iy,ps_jukebox_struct
jb_highlight_song:
; refresh the directory listing
    call bs_print_dir_page
; highlight the song being played in the directory listing
    ld a,(iy+jb_file_idx)
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
    ld a,(iy+jb_file_idx)
    call printHexA
    ld hl,(iy+jb_filename)
    call printString
; set text colours to normal
    call set_text_colours_normal
    ret
; end jb_highlight_song

; change directory one level up
; inputs: none
bs_up_dir:
    ld iy,bs_jukebox_struct
    ld a,1 ; set the directory changed flag
    ld (jb_dir_changed),a
    ld hl,@str_up_dir
    MOSCALL mos_cd ; change to the directory
    call bs_get_dir ; get directory listing
    call bs_print_dir_page
    jp get_input ; back to main loop
@str_up_dir: asciz ".."
; end ps_up_dir

bs_dir_next_page:
    ld iy,bs_jukebox_struct
    ld a,1 ; set the directory changed flag
    ld (jb_dir_changed),a
; advance the page number
    ld hl,(iy+jb_page_cur) ; get the current page number
    inc hl ; increment the page number
    ld de,(iy+jb_dir_num_pages) ; get the number of pages
    call udiv24 ; hl = mod(iy+jb_page_cur+1,iy+jb_dir_num_pages)
    ld (iy+jb_page_cur),hl ; save the new page number
; ; populate the page filename pointers
;   call bs_fill_page_fn_ptrs
; print the new page
    call bs_print_dir_page
; enable interrupts and jump back to the user input loop
    ei
    jp get_input
; end bs_dir_next_page

bs_dir_prev_page:
    ld iy,bs_jukebox_struct
jb_dir_prev_page:
    ld a,1 ; set the directory changed flag
    ld (jb_dir_changed),a
; decrement the page number
    ld hl,(iy+jb_page_cur) ; get the current page number
    dec hl ; decrement the page number
    SIGN_HLU ; check for zero
    jp p,@F ; >= 0 so we're good
    ld hl,(iy+jb_dir_num_pages) ; get the number of pages
    dec hl ; zero-based
@@:
    ld (iy+jb_page_cur),hl ; save the new page number
; ; populate the page filename pointers
;   call bs_fill_page_fn_ptrs
; print the new page and
    call bs_print_dir_page
; enable interrupts and jump back to the user input loop
    ei
    jp get_input
; end bs_dir_prev_page


ps_get_song_fn_from_pg_idx:
    ld iy,ps_jukebox_struct

; get the filename of the song at the current index
; inputs: a = song index
; returns: carry set if song index in range, new filemame in hl and iy+jb_file_idx, iy+jb_filename set to new index, a = file attribute
;          carry reset if song index out of range, current filename in hl, iy+jb_file_idx, iy+jb_filename unchanged, a = requested song index
; destroys: af, bc, de
jb_get_song_fn_from_pg_idx:
    push af ; save song index
    call jb_get_page_num_files ; b = number of files on the page
    pop af ; restore song index
    cp b ; compare song index to number of files on the page
    ld hl,(iy+jb_filename) ; get the current song filename
    ret nc ; requested song index is out of range so return current filename and no carry
    ld (iy+jb_file_idx),a ; save the song index
    ; ld ix,iy+jb_filename_ptrs ; get the address of the page fileinfo pointer table
    ld ix,0
    lea ix,iy+jb_filename_ptrs ; get the address of the page fileinfo pointer table
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
    ld (iy+jb_filename),hl ; save the new song filename
    scf ; set carry to indicate success
    ret
; end jb_get_song_fn_from_pg_idx

; dummy pushes to keep the ide happy
    push bc
bs_get_next_file:
    ld iy,bs_jukebox_struct
    ld a,(iy+jb_file_idx) ; get the current song index
    ld b,10 ; number of songs per page
@next_file:
    push bc ; save loop counter
    inc a ; increment the song index
    ld (@songIdx),a ; save the new song index
    call jb_get_song_fn_from_pg_idx ; hl points to file, carry set indicates success, a has file attribute
    jp c,@good_fname ; filename is valid
    ld a,-1 ; invalid filename means we went past the end of the list, so reset ...
    pop bc ; restore loop counter
    djnz @next_file ; ... and try again
    jp get_input ; no valid song found so return to the main loop
@good_fname:
    pop bc ; dummy pop to balance stack
    ld a,(@songIdx) ; get the new song index
    ld (iy+jb_file_idx),a ; save the new song index
    call bs_highlight_song
    jp get_input
@songIdx: db 0
; end bs_get_next_file

; dummy pushes to keep the ide happy
    push bc
    push bc
ps_get_next_song:
    ld iy,ps_jukebox_struct
    ld a,(iy+jb_file_idx) ; get the current song index
    ld b,10 ; number of songs per page
@next_file:
    push bc ; save loop counter
    inc a ; increment the song index
    ld (@songIdx),a ; save the new song index
    call jb_get_song_fn_from_pg_idx ; hl points to file, carry set indicates success, a has file attribute
    jp c,@good_fname ; filename is valid
    ld a,-1 ; invalid filename means we went past the end of the list, so reset ...
    pop bc ; restore loop counter
    djnz @next_file ; ... and try again
    jp get_input ; no valid song found so return to the main loop

@good_fname:
    cp AM_DIR ; file attribute check for directory
    jp nz,@is_file ; not a directory so check for valid .wav file
    pop bc ; restore loop counter
    djnz @next_file ; is a directory so try the next file
    jp get_input ; no valid song found so return to the main loop
@is_file:
    pop bc ; dummy pop to balance stack
    ld a,(@songIdx) ; get the new song index
    ld (iy+jb_file_idx),a ; save the new song index
    jp play_song
@songIdx: db 0
; end ps_get_next_song

; dummy pushes to keep the ide happy
    push bc
    push bc
ps_get_prev_song:
    ld iy,ps_jukebox_struct
    ld a,(iy+jb_file_idx) ; get the current song index
    ld b,10 ; number of songs per page
@prev_file:
    push bc ; save loop counter
    dec a ; decrement the song index
    ld (@songIdx),a ; save the new song index
    call jb_get_song_fn_from_pg_idx ; hl points to file, carry set indicates success, a has file attribute
    jp c,@good_fname ; filename is valid
    call jb_get_page_num_files ; invalid filename means we went past the beginning of the list,
    ld a,b ;  so reset ...
    pop bc ; restore loop counter
    djnz @prev_file ; ... and try again
    jp get_input ; no valid song found so return to the main loop

@good_fname:
    cp AM_DIR ; file attribute check for directory
    jp nz,@is_file ; not a directory so check for valid .wav file
    pop bc ; restore loop counter
    djnz @prev_file ; is a directory so try the previous file
    jp get_input ; no valid song found so return to the main loop
@is_file:
    pop bc ; dummy pop to balance stack
    ld a,(@songIdx) ; get the new song index
    ld (iy+jb_file_idx),a ; save the new song index
    jp play_song

@songIdx: db 0
; end ps_get_prev_song

; dummy pushes to keep the ide happy
    push bc
bs_get_prev_file:
    ld iy,bs_jukebox_struct
    ld a,(iy+jb_file_idx) ; get the current song index
    ld b,10 ; number of songs per page
@prev_file:
    push bc ; save loop counter
    dec a ; decrement the song index
    ld (@songIdx),a ; save the new song index
    call jb_get_song_fn_from_pg_idx ; hl points to file, carry set indicates success, a has file attribute
    jp c,@good_fname ; filename is valid
    call jb_get_page_num_files ; invalid filename means we went past the beginning of the list,
    ld a,b ;  so reset ...
    pop bc ; restore loop counter
    djnz @prev_file ; ... and try again
    jp get_input ; no valid song found so return to the main loop
@good_fname:
    pop bc ; dummy pop to balance stack
    ld a,(@songIdx) ; get the new song index
    ld (iy+jb_file_idx),a ; save the new song index
    call bs_highlight_song
    jp get_input
@songIdx: db 0
; end bs_get_prev_file

ps_read_wav_header:
    ld iy,ps_jukebox_struct
jb_read_wav_header:
; Read a block of data from a file
;   C: Filehandle
; HLU: Pointer to where to write the data to
; DEU: Number of bytes to read
; Returns:
; DEU: Number of bytes read
    ld a,(iy+jb_filehandle)
    ld c,a
    ld hl,(iy+jb_wav_header)
    ld de,wav_header_size
    MOSCALL mos_fread
; test de for zero bytes read
    ld hl,0
    xor a ; clear carry
    sbc hl,de ; hl = 0-chunksize
    ret z ; no data read so return zero to caller
; test for valid .wav header
    call verify_wav
    jp z,@F ; valid .wav header so continue
    xor a ; invalid .wav header so return zero to caller
    ret
; data read so initialize song variables
; load play sample command buffers (namely the sample rate for now)
@@:
    call ps_load_command_buffers
    ret
; end jb_read_wav_header

; copy the browse song super-struct to the play song super-struct
; inputs: none
; outputs: ps_jukebox_struct = bs_jukebox_struct
; destroys: f, hl, bc, de
jb_copy_bs_to_ps:
    ld hl,bs_jukebox_struct
    ld de,ps_jukebox_struct
    ld bc,jb_struct_size
    ldir

    ld hl,bs_dir_struct
    ld de,ps_dir_struct
    ld bc,dir_struct_size
    ldir

    ld hl,bs_dir_fil_list
    ld de,ps_dir_fil_list
    ld bc,dir_fil_list_size
    ldir

    ret
; end jb_copy_bs_to_ps
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
    jp nz,@isDir ; is directory so skip .wav file check

; is file so check for valid .wav format
    ld hl,bf_fil_struct ; hl = pointer to fil struct
    lea de,ix+filinfo_fname ; de = pointer to filename
    call bf_verify_wav
    jp z,@readFileInfo ; not a .wav file, so skip it
; set the last byte of filinfo_faltname to 1 to indicate this is a file for filename sorting
    ld a,'1'
    ld (ix+filinfo_fname-1),a
    jp @goodPath
@isDir:
; set the last byte of filinfo_faltname to 0 to indicate this is a directory for filename sorting
    ld a,'0'
    ld (ix+filinfo_fname-1),a
    ; fall through to @goodPath
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
    SIGN_UHL ; check for zero
    jp nz,@not_zero
    ld de,0 ; number of pages, will increment by 1 later
    ld hl,0 ; number of files on last page
    jp @write_stats
@not_zero:
    call udiv24 ; de = hl/bf_files_per_pg, hl = mod(hl,bf_files_per_pg)
    SIGN_UHL ; check remainder for zero
    jp nz,@write_stats
    ld hl,bf_files_per_pg ; if zero then we have exactly bf_files_per_pg files on the last page ...
    dec de ; ... and we don't need an additional page for the remainder
@write_stats:
    ld (bf_files_last_pg),hl ; save the number of files on the last page
    inc de ; bump the page count
    ld (bf_dir_num_pages),de ; save the number of pages
    ld hl,0 ; reset the page number
    ld (bf_page_cur),hl
; sort the filenames
    ld iy,bf_filinfo_ptrs ; get the pointer to the fileinfo pointer table
    ld a,(bf_dir_num_files) ; get the number of files
    ld b,a ; loop counter
    call selection_sort_asc_filinfo ; sort the filenames
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

; Presentation events. Callers run with interrupts disabled.
bf_print_dir_page:
bf_update_pages_ui:
bf_highlight_file:
    jp ui_event_browser

bf_check_dir_or_file:
    ld a,(iy+filinfo_fattrib)
    bit AM_DIR,a ; if not zero, is directory
    ret
; end bf_check_dir_or_file

bf_print_dir_name:
    jp ui_event_directory

    .assume adl=1                       ; ez80 ADL memory mode
    .org $40000                         ; load code here

    jp start_here                       ; jump to start of code

    .align 64                           ; MOS header
    .db "MOS",0,1     

    include "mos_api.inc"               ; include the MOS API
start_here:
            
    push af                             ; store all the registers
    push bc
    push de
    push ix
    push iy

; ------------------
                                        

    ld hl, ps_dir_path                      ; where to store result
    ld bc, 255                          ; max length
    MOSCALL ffs_getcwd                  ; MOS api get current working directory

    ld hl, printDirHeading              ; Sending initial text message
    call printString

    ld hl, ps_dir_path                ; get pointer to the path
    call printString

    ld hl, printCR                      ; address of string
    call printString                    ; print lf/cr 


                                        ; now get dir info

    ld hl, ps_dir_struct                   ; define where to store directory info
    ld de, ps_dir_path                ; this is pointer to the path to the directory
    MOSCALL ffs_dopen                         ; open dir


@readFileInfo:                          ; we will loop here until all files have been processed

    ld hl, ps_dir_struct                   ; HL is where to get directory info
    ld de, ps_filinfo_struct               ; define where to store current file info
    MOSCALL ffs_dread                         ; read next item from dir

    ld a, (ps_filinfo_fname)                       ; get first char of file name
    cp 0                                ; if 0 then we are at the end of the listing
    jr z, @allDone

    ld hl, ps_filinfo_fname                        ; this is pointer to the name of current file
    ld bc, 0
    ld a, 0                             ; name will end with a 0
    rst.lil $18                         ; print to screen

    ld hl, printCR                      ; now print a carriage retrun before the next entry
    call printString

    jr @readFileInfo                    ; loop around to check next entry

@allDone:


    ld hl, ps_dir_struct                   ; load H: with address of the DIR struct
    MOSCALL ffs_dclose                         ; close dir


; ------------------
; This is where we exit the program

    pop iy                              ; Pop all registers back from the stack
    pop ix
    pop de
    pop bc
    pop af
    ld hl,0                             ; Load the MOS API return code (0) for no errors.
    ret                                 ; Return to MOS

; ------------------
; Some data stored here

printDirHeading:
    .db     "Our current directory is:\r\n",0       ; text to print

printCR:
    .db     "\r\n",0                                ; text to print

; ps_dir_path:    .blkb     256,0                           ; 256 x 0 bytes allocated for path name

; ------------------
; Routine to print zero terminated string

printString:                                    
    ld a,(hl)
    or a
    ret z
    RST.LIL 10h
    inc hl
    jr printString


    include "files.inc"



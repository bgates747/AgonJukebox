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

    MACRO HLU_TO_A
    dec sp ; 1 cycle
    push hl ; 4 cycles
    inc sp ; 1 cycle
    pop af ; 4 cycles
    ; 10 cycles total
    ENDMACRO

	MACRO	MOSCALL	function
			LD	A, function
			RST.LIL	08h
	ENDMACRO 	

mos_cd:				EQU	03h
mos_oscli:			EQU	10h
ffs_getcwd:			EQU	9Eh
ffs_dopen:			EQU	91h
ffs_dclose:			EQU	92h

; --- MAIN PROGRAM FILE ---
dir_up: asciz "cd .." ; command to go up one directory
dir_dots: asciz ".." ; directory name for parent directory
ps_dir_path: blkb 256,0x7f ; buffer to hold directory path (7f chosen to verify where ffs_getcwd writes the zero terminator)

; play_song directory info
ps_dir_struct:             
ps_dptr:       blkb  4,0   ; Current read/write offset
ps_clust:      blkb  4,0   ; Current cluster
ps_sect:       blkb  4,0   ; Current sector (0:Read operation has terminated)
ps_dir:        blkb  3,0   ; Pointer to the directory item in the win[]
ps_fn:         blkb  12,0  ; SFN (in/out) {body[8],ext[3],status[1]}
ps_blk_ofs:    blkb  4,0   ; Offset of current entry block being processed (0xFFFFFFFF:Invalid)

init:
    ld a,19 ; 1024  768   4     60hz
    call vdu_set_screen_mode
    call printNewLine
    ret
; end init
main:
; memdump directory buffer to verify initial state (256 7f's)
    ld hl,ps_dir_path
    ld a,32
    call dumpMemoryHex
    call printNewLine
    call printNewLine

; print current working directory
    call ps_get_dir_test

; ; up one level and print (works, inserts zero-terminator as expected)
;     ld hl,dir_up
;     MOSCALL mos_oscli
;     call ps_get_dir_test

; ; up another level and print (does not work, zero-terminator not written for the second time)
;     ld hl,dir_up
;     MOSCALL mos_oscli
;     call ps_get_dir_test

; FIX IS TO USE mos_cd INSTEAD OF mos_oscli
; up one level and print
    ld hl,dir_dots
    MOSCALL mos_cd
    call ps_get_dir_test

; up another level and print
    ld hl,dir_dots
    MOSCALL mos_cd
    call ps_get_dir_test
    
    ret ; back to MOS
; end main

ps_get_dir_test:
; ; clear the directory path buffer (doesn't help and shouldn't be required as confirmed by writing 7f's to directory buffer)
;     ld hl,ps_dir_path
;     ld a,0
;     ld bc,255
;     call clear_mem

; initialize pointers to store directory info and print directory name
    ld hl,ps_dir_path  ; where to store result
    ld bc,255          ; max length (final byte is zero terminator)
    xor a ; zero-terminate the string (doesn't matter on first call, doesn't work on second call)
    MOSCALL ffs_getcwd ; MOS api get current working directory

; now get dir info (makes no difference whether this is included or excluded)
    ld hl,ps_dir_struct ; define where to store directory info
    ld de,ps_dir_path   ; this is pointer to the path to the directory
    xor a               ; tell MOS to expect zero-terminated string
    MOSCALL ffs_dopen   ; open dir

; print the directory path
    ld hl,ps_dir_path
    call printString
    call printNewLine
    
; memdump directory buffer after populating
    ld hl,ps_dir_path
    ld a,32
    call dumpMemoryHex
    call printNewLine
    call printNewLine

; close the directory (makes no difference on the first call, doesn't help on the second)
    ld hl,ps_dir_struct      ; load H: with address of the DIR struct
    MOSCALL ffs_dclose       ; close dir
    ret
; end ps_get_dir_test

vdu_set_screen_mode:
	ld (@arg),a        
	ld hl,@cmd         
	ld bc,@end-@cmd    
	rst.lil $18         
	ret
@cmd: db 22 ; set screen mode
@arg: db 0  ; screen mode parameter
@end:

printNewLine:
    push af ; for some reason rst.lil 10h sets carry flag
    LD A, '\r'
    RST.LIL 10h
    LD A, '\n'
    RST.LIL 10h
    pop af
    RET

printString:
    PUSH BC
    LD BC,0
    LD A,0
    RST.LIL 18h
    POP BC
    RET

dumpMemoryHex:
; save registers to the stack
    push bc
    push hl
    push af
; print the address and separator
    call printHex24
    ld a,':'
    rst.lil 10h
    ld a,' '
    rst.lil 10h
; set b to be our loop counter
    pop af
    ld b,a
    pop hl
    push hl
    push af
@loop:
; print the byte
    ld a,(hl)
    call printHex8
; print a space
    ld a,' '
    rst.lil 10h
    inc hl
    djnz @loop
; restore everything
    pop af
    pop hl
    pop bc

; all done
    ret


printHex24:
    HLU_TO_A
    CALL printHex8
printHex16:
    LD A,H
    CALL printHex8
    LD A,L
printHex8:
    LD C,A
    RRA 
    RRA 
    RRA 
    RRA 
    CALL @F
    LD A,C
@@:
    AND 0Fh
    ADD A,90h
    DAA
    ADC A,40h
    DAA
    RST.LIL 10h
    RET

clear_mem:
    dec bc ; we do this because we will increment de before writing the first byte
    ld (hl),a
    push hl
    pop de
    inc de ; target address
    ldir
    ret
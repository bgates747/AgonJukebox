printHexA:
    push af
    push bc
    call printHex8
    ld a,' '
    rst.lil 10h
    pop bc
    pop af
    ret

printHexHL:
    push af
    push bc
    call printHex16
    ld a,' '
    rst.lil 10h
    pop bc
    pop af
    ret

printHexUHL:
    push af
    push bc
    call printHex24
    ld a,' '
    rst.lil 10h
    pop bc
    pop af
    ret

printHexAUHL:
    push af
    push bc
    call printHex8
    ld a,'.'
    rst.lil 10h
    call printHex24
    ld a,' '
    rst.lil 10h
    pop bc
    pop af
    ret

printHexABHL:
; preserve registers
    push bc ; b will be ok c will not
    push af ; will get totally destroyed
; print a
    call printHex8 
; print b
    ld a,b
    call printHex8
; print hl
    call printHex16
; restore registers
    pop af
    pop bc
    ret

printHexBHL:
; preserve registers
    push bc ; b will be ok c will not
    push af ; will get totally destroyed
; print b
    ld a,b
    call printHex8
; print hl
    call printHex16
; restore registers
    pop af
    pop bc
    ret

printHexCDE:
; preserve registers
    push bc ; b will be ok c will not
    push af ; will get totally destroyed
; print c
    ld a,c
    call printHex8
; print de
    ex de,hl
    call printHex16
    ex de,hl
; restore registers
    pop af
    pop bc
    ret

printHexUIX:
; store everything in scratch
    ld (uhl),hl
    ld (ubc),bc
    ld (ude),de
    ld (uix),ix
    ld (uiy),iy
    push af ; fml

    ld hl,str_ixu
    call printString
    ld hl,(uix)
    call printHex24
    call printNewLine

; restore everything
    ld hl, (uhl)
    ld bc, (ubc)
    ld de, (ude)
    ld ix, (uix)
    ld iy, (uiy)
    pop af
; all done
    ret


; print registers to screen in hexidecimal format
; inputs: none
; outputs: values of every register printed to screen
;    values of each register in global scratch memory
; destroys: nothing
stepRegistersHex:
; store everything in scratch
    ld (uhl),hl
    ld (ubc),bc
    ld (ude),de
    ld (uix),ix
    ld (uiy),iy
    push af ; fml
    pop hl ; thanks, zilog
    ld (uaf),hl
    push af ; dammit

; home the cursor
    ; call vdu_home_cursor

; print each register
    ld hl,str_afu
    call printString
    ld hl,(uaf)
    call printHex24
    call printNewLine

    ld hl,str_hlu
    call printString
    ld hl,(uhl)
    call printHex24
    call printNewLine

    ld hl,str_bcu
    call printString
    ld hl,(ubc)
    call printHex24
    call printNewLine

    ld hl,str_deu
    call printString
    ld hl,(ude)
    call printHex24
    call printNewLine

    ld hl,str_ixu
    call printString
    ld hl,(uix)
    call printHex24
    call printNewLine

    ld hl,str_iyu
    call printString
    ld hl,(uiy)
    call printHex24
    call printNewLine

    ; call vsync

    call printNewLine

; check for right shift key and quit if pressed
    MOSCALL mos_getkbmap
@stayhere:
; 7 RightShift
    bit 6,(ix+0)
    jr nz,@RightShift
    jr @stayhere
@RightShift:
    res 0,(ix+14) ; debounce the key (hopefully)
    ld a,%10000000
    ; call multiPurposeDelay

; restore everything
    ld hl, (uhl)
    ld bc, (ubc)
    ld de, (ude)
    ld ix, (uix)
    ld iy, (uiy)
    pop af
; all done
    ret

; print registers to screen in hexidecimal format
; inputs: none
; outputs: values of every register printed to screen
;    values of each register in global scratch memory
; destroys: nothing
dumpRegistersHex:
; store everything in scratch
    ld (uhl),hl
    ld (ubc),bc
    ld (ude),de
    ld (uix),ix
    ld (uiy),iy
    push af ; fml
    pop hl ; thanks, zilog
    ld (uaf),hl
    push af ; dammit

; home the cursor
    ; call vdu_home_cursor
    ; call printNewLine

; print each register
    ld hl,str_afu
    call printString
    ld hl,(uaf)
    call printHex24
    call printNewLine

    ld hl,str_hlu
    call printString
    ld hl,(uhl)
    call printHex24
    call printNewLine

    ld hl,str_bcu
    call printString
    ld hl,(ubc)
    call printHex24
    call printNewLine

    ld hl,str_deu
    call printString
    ld hl,(ude)
    call printHex24
    call printNewLine

    ld hl,str_ixu
    call printString
    ld hl,(uix)
    call printHex24
    call printNewLine

    ld hl,str_iyu
    call printString
    ld hl,(uiy)
    call printHex24
    
    call printNewLine
    call printNewLine
; restore everything
    ld hl, (uhl)
    ld bc, (ubc)
    ld de, (ude)
    ld ix, (uix)
    ld iy, (uiy)
    pop af
; all done
    ret
    
dumpRegistersHexPrime:
    exx
    ex af,af'
    call dumpRegistersHex
    ex af,af'
    exx
    ret

; additionally dump prime registers
; inputs: none
; outputs: values of every register printed to screen
; destroys: nothing
dumpRegistersHexAll:
    call dumpRegistersHex
    ex af,af'
    exx
    call dumpRegistersHex
    ex af,af'
    exx
    ret

; print hlu to screen in hexidecimal format
; inputs: none
; destroys: nothing
print_hex_hl:
    push af
    push hl
    ld hl,str_hlu
    call printString
    pop hl
    push hl
    call printHex24
    ld a,' '
    rst.lil 10h
    pop hl
    pop af
    ret

; print bcu to screen in hexidecimal format
; inputs: none
; destroys: nothing
print_hex_bc:
    push af
    push hl
    push bc
    ld hl,str_bcu
    call printString
    pop hl
    push hl
    call printHex24
    ld a,' '
    rst.lil 10h
    pop bc
    pop hl
    pop af
    ret

; print deu to screen in hexidecimal format
; inputs: none
; destroys: nothing
print_hex_de:
    push af
    push hl
    push de
    ld hl,str_deu
    call printString
    pop hl
    push hl
    call printHex24
    ld a,' '
    rst.lil 10h
    pop de
    pop hl
    pop af
    ret


; inputs: whatever is in the flags register
; outputs: binary representation of flags
;          with a header so we know which is what
; destroys: nothing
; preserves: everything
dumpFlags:
; first we curse zilog for not giving direct access to flags
    push af ; this is so we can send it back unharmed
    push af ; this is so we can pop it to hl
; store everything in scratch
    ld (uhl),hl
    ld (ubc),bc
    ld (ude),de
    ld (uix),ix
    ld (uiy),iy
; next we print the header 
    ld hl,@header
    call printString
    pop hl ; flags are now in l
    ld a,l ; flags are now in a
    call printBin8
    call printNewLine
; restore everything
    ld hl, (uhl)
    ld bc, (ubc)
    ld de, (ude)
    ld ix, (uix)
    ld iy, (uiy)
    pop af ; send her home the way she came
    ret
; Bit 7 (S): Sign flag
; Bit 6 (Z): Zero flag
; Bit 5 (5): Reserved (copy of bit 5 of the result)
; Bit 4 (H): Half Carry flag
; Bit 3 (3): Reserved (copy of bit 3 of the result)
; Bit 2 (PV): Parity/Overflow flag
; Bit 1 (N): Subtract flag
; Bit 0 (C): Carry flag
@header: db "SZxHxPNC\r\n",0 ; cr/lf and 0 terminator


; print bytes from an address to the screen in hexidecimal format
; inputs: hl = address of first byte to print, a = number of bytes to print
; outputs: values of each byte printed to screen separated by spaces
; destroys: nothing
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
    call printNewLine

; restore everything
    pop af
    pop hl
    pop bc

; all done
    ret


; print bytes from an address to the screen in binary format
; inputs: hl = address of first byte to print, a = number of bytes to print
; outputs: values of each byte printed to screen separated by spaces
; destroys: nothing
dumpMemoryBin:
; save all registers to the stack
    push af
    push bc
    push de
    push hl
    push ix
    push iy

; set b to be our loop counter
    ld b,a
@loop:
; print the byte
    ld a,(hl)
    push hl
    push bc
    call printBin8
    pop bc
; print a space
    ld a,' '
    rst.lil 10h
    pop hl
    inc hl
    djnz @loop
    call printNewLine

; restore everything
    pop iy
    pop ix
    pop hl
    pop de
    pop bc
    pop af
; all done
    ret

; print bytes from an address to the screen in binary format
; with the bits of each byte in reverse order (lsb first)
; inputs: hl = address of first byte to print, a = number of bytes to print
; outputs: values of each byte printed to screen separated by spaces
; destroys: nothing
dumpMemoryBinRev:
; save all registers to the stack
    push af
    push bc
    push de
    push hl
    push ix
    push iy

; set b to be our loop counter
    ld b,a
@loop:
; print the byte
    ld a,(hl)
    push hl
    push bc
    call printBin8Rev
    pop bc
; print a space
    ld a,' '
    rst.lil 10h
    pop hl
    inc hl
    djnz @loop
    call printNewLine

; restore everything
    pop iy
    pop ix
    pop hl
    pop de
    pop bc
    pop af
; all done
    ret

DEBUG_PRINT:
    PUSH_ALL
    ; ld c,0 ; X
    ; ld b,0 ; Y
    ; call vdu_move_cursor
    call printNewLine
    POP_ALL
    PUSH_ALL
    call dumpFlags
    POP_ALL
    PUSH_ALL
    call dumpRegistersHex
    ; call waitKeypress
    call printNewLine
    POP_ALL
    ret
DEBUG_WAITKEYPRESS:
    PUSH_ALL
    call waitKeypress
    POP_ALL
    RET

dumpVduCmdStr:
    PUSH_ALL
    ld a,c
    call dumpMemoryHex
    call waitKeypress
    POP_ALL
    ret
; end dumpVduCmdStr
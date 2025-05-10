; https://github.com/envenomator/Agon/blob/master/ez80asm%20examples%20(annotated)/functions.s
; Print a zero-terminated string
; HL: Pointer to string
printString:
	PUSH	BC
	LD		BC,0
	LD 	 	A,0
	RST.LIL 18h
	POP		BC
	RET
; print a VDU sequence
; HL: Pointer to VDU sequence - <1 byte length> <data>
sendVDUsequence:
	PUSH	BC
	LD		BC, 0
	LD		C, (HL)
	RST.LIL	18h
	POP		BC
	RET
; Print Newline sequence to VDP
printNewline:
	LD	A, '\r'
	RST.LIL 10h
	LD	A, '\n'
	RST.LIL 10h
	RET
; Print a 24-bit HEX number
; HLU: Number to print
printHex24:
	PUSH	HL
	LD		HL, 2
	ADD		HL, SP
	LD		A, (HL)
	POP		HL
	CALL	printHex8
; Print a 16-bit HEX number
; HL: Number to print
printHex16:
	LD		A,H
	CALL	printHex8
	LD		A,L
; Print an 8-bit HEX number
; A: Number to print
printHex8:
	LD		C,A
	RRA 
	RRA 
	RRA 
	RRA 
	CALL	@F
	LD		A,C
@@:
	AND		0Fh
	ADD		A,90h
	DAA
	ADC		A,40h
	DAA
	RST.LIL	10h
	RET

; Print a 0x HEX prefix
DisplayHexPrefix:
	LD	A, '0'
	RST.LIL 10h
	LD	A, 'x'
	RST.LIL 10h
	RET

; Prints the decimal value in HL without leading zeroes
; HL : Value to print
printDec:
	LD	 DE, _printDecBuffer
	CALL Num2String
	LD	 HL, _printDecBuffer
	CALL printString
	RET
_printDecBuffer: blkb 9,0 ; nine bytes full of zeroes

; This routine converts the value from HL into it's ASCII representation, 
; starting to memory location pointing by DE, in decimal form and with trailing zeroes 
; so it will allways be 5 characters length
; HL : Value to convert to string
; DE : pointer to buffer, at least 8 byte + 0
Num2String:
	LD	 BC,-10000000
	CALL OneDigit
	LD	 BC,-1000000
	CALL OneDigit
	LD	 BC,-100000
	CALL OneDigit
	LD   BC,-10000
	CALL OneDigit
	LD   BC,-1000
	CALL OneDigit
	LD   BC,-100
	CALL OneDigit
	LD   C,-10
	CALL OneDigit
	LD   C,B
OneDigit:
	LD   A,'0'-1
DivideMe:
	INC  A
	ADD  HL,BC
	JR   C,DivideMe
	SBC  HL,BC
	LD   (DE),A
	INC  DE
	RET

; #### new functions added by Brandon R. Gates ####

; print the binary representation of the 8-bit value in a
; destroys a, hl, bc
printBin8:
    ld b,8      ; loop counter for 8 bits
    ld hl,@cmd  ; set hl to the low byte of the output string
                ; (which will be the high bit of the value in a)
@loop:
    rlca ; put the next highest bit into carry
    jr c,@one
    ld (hl),'0'
    jr @next_bit
@one:
    ld (hl),'1'
@next_bit:
    inc hl
    djnz @loop
; print it
	ld hl,@cmd         
	ld bc,@end-@cmd    
	rst.lil $18         
	ret
@cmd: ds 8 ; eight bytes for eight bits
@end:

; print the binary representation of the 8-bit value in a
; in reverse order (lsb first)
; destroys a, hl, bc
printBin8Rev:
    ld b,8      ; loop counter for 8 bits
    ld hl,@cmd  ; set hl to the low byte of the output string
                ; (which will be the high bit of the value in a)
@loop:
    rrca ; put the next lowest bit into carry
    jr c,@one
    ld (hl),'0'
    jr @next_bit
@one:
    ld (hl),'1'
@next_bit:
    inc hl
    djnz @loop
; print it
	ld hl,@cmd         
	ld bc,@end-@cmd    
	rst.lil $18         
	ret
@cmd: ds 8 ; eight bytes for eight bits
@end:

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
    pop hl  ; thanks, zilog
    ld (uaf),hl
    push af ; dammit

; home the cursor
    ; call vdu_home_cursor

; print each register
    ld hl,str_afu
    call printString
    ld hl,(uaf)
    call printHex24
    call printNewline

    ld hl,str_hlu
    call printString
    ld hl,(uhl)
    call printHex24
    call printNewline

    ld hl,str_bcu
    call printString
    ld hl,(ubc)
    call printHex24
    call printNewline

    ld hl,str_deu
    call printString
    ld hl,(ude)
    call printHex24
    call printNewline

    ld hl,str_ixu
    call printString
    ld hl,(uix)
    call printHex24
    call printNewline

    ld hl,str_iyu
    call printString
    ld hl,(uiy)
    call printHex24
    call printNewline

    call printNewline
; restore everything
    ld hl, (uhl)
    ld bc, (ubc)
    ld de, (ude)
    ld ix, (uix)
    ld iy, (uiy)
    pop af
; all done
    ret

str_afu: db "af=",0
str_hlu: db "hl=",0
str_bcu: db "bc=",0
str_deu: db "de=",0
str_ixu: db "ix=",0
str_iyu: db "iy=",0

; print udeuhl to screen in hexidecimal format
; inputs: none
; outputs: concatenated hexidecimal udeuhl 
; destroys: nothing
dumpUDEUHLHex:
; store everything in scratch
    ld (uhl),hl
    ld (ubc),bc
    ld (ude),de
    ld (uix),ix
    ld (uiy),iy
    push af

; print each register

    ld hl,str_udeuhl
    call printString
    ld hl,(ude)
    call printHex24
	ld a,'.'	; print a dot to separate the values
	rst.lil 10h
    ld hl,(uhl)
    call printHex24
    call printNewline

; restore everything
    ld hl, (uhl)
    ld bc, (ubc)
    ld de, (ude)
    ld ix, (uix)
    ld iy, (uiy)
    pop af
; all done
    ret

str_udeuhl: db "ude.uhl=",0

; global scratch memory for registers
uaf: dl 0
uhl: dl 0
ubc: dl 0
ude: dl 0
uix: dl 0
uiy: dl 0
usp: dl 0
upc: dl 0

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
	call printNewline
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

; set all the bits in the flag register
; more of an academic exercise than anything useful
; inputs; none
; outputs; a=0,f=255
; destroys: flags, hl
; preserves: a, because why not
setAllFlags:
    ld hl,255
    ld h,a ; four cycles to preserve a is cheap
    push hl
    pop af
    ret

; reset all the bits in the flag register
; unlike its inverse counterpart, this may actually be useful
; inputs; none
; outputs; a=0,f=0
; destroys: flags, hl
; preserves: a, because why not
resetAllFlags:
    ld hl,0
    ld h,a ; four cycles to preserve a is cheap
    push hl
    pop af
    ret


; print bytes from an address to the screen in hexidecimal format
; inputs: hl = address of first byte to print, a = number of bytes to print
; outputs: values of each byte printed to screen separated by spaces
; destroys: nothing
dumpMemoryHex:
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
    call printHex8
; print a space
    ld a,' '
    rst.lil 10h
    inc hl
    djnz @loop
    call printNewline

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
    call printNewline

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
    call printNewline

; restore everything
    pop iy
    pop ix
    pop hl
    pop de
    pop bc
    pop af
; all done
    ret
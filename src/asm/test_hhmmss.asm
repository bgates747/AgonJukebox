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

    call main

exit:
    pop iy
    pop ix
    pop de
    pop bc
    pop af
    ld hl,0

    ret

; --- MAIN PROGRAM FILE ---

main:
    ld hl,359999 ; 99:59:59
    call seconds_to_hhmmss
    ld hl,hhmmss
    call printString
    ld a,'\r'
    rst.lil 10h
    ld a,'\n'
    rst.lil 10h
    ret

; Convert seconds to HH:MM:SS format.
; inputs: hl = seconds
; outputs: hl = pointer to zero-terminated string representation of HH:MM:SS
; destroys: a,bc,de
seconds_to_hhmmss:
; Divide the total seconds into hours, minutes, and seconds.
; Hours = Total seconds ÷ 3600.
    ld de,3600
    call udiv24 ; de = hours, hl = remaining seconds
    push hl ; save remainder
    ex de,hl ; hl = hours
    ld de,@bin2asc
    call u8_to_ascii ; answer in @bin2asc
    ld a,(@bin2asc+2)
    ld (hhmmss+0),a
    ld a,(@bin2asc+3)
    ld (hhmmss+1),a
; Minutes = Remaining seconds ÷ 60.
    pop hl ; restore remainder
    ld de,60
    call udiv24 ; de = minutes, hl = remaining seconds
    push hl ; save remainder
    ex de,hl ; hl = minutes
    ld de,@bin2asc
    call u8_to_ascii ; answer in @bin2asc
    ld a,(@bin2asc+2)
    ld (hhmmss+3),a
    ld a,(@bin2asc+3)
    ld (hhmmss+4),a
; Seconds = Remaining seconds.
    pop hl ; restore remainder
    call u8_to_ascii ; answer in @bin2asc
    ld a,(@bin2asc+2)
    ld (hhmmss+6),a
    ld a,(@bin2asc+3)
    ld (hhmmss+7),a
    ret
@bin2asc: blkw 4,0 ; scratch space for binary to ascii decimal conversion
hhmmss: asciz "00:00:00" ; buffer for output string
; end seconds_to_hhmmss

; following code stolen from / inspired by:
; https://github.com/envenomator/Agon/blob/master/ez80asm%20examples%20(annotated)/functions.s

; This routine converts the unsigned 16-bit value in HL into its ASCII representation, 
; starting to memory location pointing by DE, in decimal form and with leading zeroes 
; so it will allways be 3 characters length
; HL : Value to convert to string, must be <= 999 decimal for correct representation
; DE : pointer to 4-byte buffer (3-digits + 0 terminator for printing)
u8_to_ascii:
    CALL one_digit
    LD BC,-100
    CALL one_digit
    LD C,-10
    CALL one_digit
    LD C,B
one_digit:
    LD A,'0'-1
@divide_me:
    INC A
    ADD HL,BC
    JR C,@divide_me
    SBC HL,BC
    LD (DE),A
    INC DE
    RET
; end u24_to_ascii

; Print a zero-terminated string
; HL: Pointer to string
; returns: hl pointed to character after string terminator
; destroys: af, hl
printString:
    PUSH BC
    LD BC,0
    LD A,0
    RST.LIL 18h
    POP BC
    RET
; end printString

; following code ripped directly from:
; https://github.com/sijnstra/agon-projects/blob/main/calc24/arith24.asm
;------------------------------------------------------------------------
;  arith24.asm 
;  24-bit ez80 arithmetic routines
;  Copyright (c) Shawn Sijnstra 2024
;  MIT license
;
;  This library was created as a tool to help make ez80
;  24-bit native assembly routines for simple mathematical problems
;  more widely available.
;  
;------------------------------------------------------------------------

;------------------------------------------------------------------------
; udiv24
; Unsigned 24-bit division
; Divides HLU by DEU. Gives result in DEU (and BC), remainder in HLU.
; 
; Uses AF BC DE HL
; Uses Restoring Division algorithm
;------------------------------------------------------------------------

udiv24:
	push	hl
	pop		bc	;move dividend to BCU
	ld		hl,0	;result
	and		a
	sbc		hl,de	;test for div by 0
	ret		z		;it's zero, carry flag is clear
	add		hl,de	;HL is 0 again
	ld		a,24	;number of loops through.
udiv1:
	push	bc	;complicated way of doing this because of lack of access to top bits
	ex		(sp),hl
	scf
	adc	hl,hl
	ex	(sp),hl
	pop	bc		;we now have bc = (bc * 2) + 1

	adc	hl,hl
	and	a		;is this the bug
	sbc	hl,de
	jr	nc,udiv2
	add	hl,de
;	dec	c
	dec	bc
udiv2:
	dec	a
	jr	nz,udiv1
	scf		;flag used for div0 error
	push	bc
	pop		de	;remainder
	ret
; end udiv24
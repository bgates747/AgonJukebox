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
; umul24:	HL = HL*DE (unsigned)
; Preserves AF, BC, DE
; Uses a fast multiply routine.
;------------------------------------------------------------------------
umul24:
	push	DE 
	push	BC
	push	AF	
	push	HL
	pop		BC
    ld	 	a, 24 ; No. of bits to process 
    ld	 	hl, 0 ; Result
umul24_lp:
	add	hl,hl
	ex	de,hl
	add	hl,hl
	ex	de,hl
	jr	nc,umul24_nc
	add	hl,bc
umul24_nc: 
	dec	a
	jr	nz,umul24_lp
	pop	af
	pop	bc
	pop	de
	ret


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



;------------------------------------------------------------------------
; neg24
; Returns: HLU = 0-HLU
; preserves all other registers
;------------------------------------------------------------------------
neg24:
	push	de
	ex		de,hl
	ld		hl,0
	or		a
	sbc		hl,de
	pop		de
	ret

;------------------------------------------------------------------------
; or_hlu_deu: 24 bit bitwise OR
; Returns: hlu = hlu OR deu
; preserves all other registers
;------------------------------------------------------------------------
or_hlu_deu:
	ld	(bitbuf1),hl
	ld	(bitbuf2),de
	push	de	;preserve DEU
	push	bc	;preserve BCU
	ld		b,3
	ld	hl,bitbuf1
	ld	de,bitbuf1
orloop_24:
	ld	a,(de)
	or	(hl)
	ld	(de),a
	inc	de
	inc	hl
	djnz	orloop_24
	ld	hl,(bitbuf2)
	pop		bc	;restore BC
	pop		de	;restore DE

;------------------------------------------------------------------------
; and_hlu_deu: 24 bit bitwise AND
; Returns: hlu = hlu AND deu
; preserves all other registers
;------------------------------------------------------------------------
and_hlu_deu:
	ld	(bitbuf1),hl
	ld	(bitbuf2),de
	push	de	;preserve DEU
	push	bc	;preserve BCU
	ld		b,3
	ld	hl,bitbuf1
	ld	de,bitbuf1
andloop_24:
	ld	a,(de)
	and	(hl)
	ld	(de),a
	inc	de
	inc	hl
	djnz	andloop_24
	ld	hl,(bitbuf2)
	pop		bc	;restore BC
	pop		de	;restore DE

;------------------------------------------------------------------------
; xor_hlu_deu: 24 bit bitwise XOR
; Returns: hlu = hlu XOR deu
; preserves all other registers
;------------------------------------------------------------------------
xor_hlu_deu:
	ld	(bitbuf1),hl
	ld	(bitbuf2),de
	push	de	;preserve DEU
	push	bc	;preserve BCU
	ld		b,3
	ld	hl,bitbuf1
	ld	de,bitbuf1
xorloop_24:
	ld	a,(de)
	xor	(hl)
	ld	(de),a
	inc	de
	inc	hl
	djnz	xorloop_24
	ld	hl,(bitbuf2)
	pop		bc	;restore BC
	pop		de	;restore DE

;------------------------------------------------------------------------
; shl_hlu: 24 bit shift left hlu by a positions
; Returns: hlu = hlu << a
;		   a = 0
; NOTE: only considers a up to 16 bits. 
; preserves all other registers
; modified by Brandon R. Gates to use a instead of de
;------------------------------------------------------------------------
shl_hlu:
	or a
	ret		z		;we're done
	add		hl,hl	;shift HLU left
	dec a
	jr		shl_hlu

;------------------------------------------------------------------------
; shr_hlu: 24 bit shift right hlu by a positions
; Returns: hlu = hlu >> a
;		   a = 0
; NOTE: only considers a up to 16 bits. 
; preserves all other registers
; modified by Brandon R. Gates to use a instead of de
;------------------------------------------------------------------------
shr_hlu:
	ld		(bitbuf1),hl
	ld		hl,bitbuf1+2
@shr_loop:
	or a
	jr		z,@shr_done		;we're done
;carry is clear from or instruction
	rr		(hl)
	dec		hl
	rr		(hl)
	dec		hl
	rr		(hl)
	inc		hl
	inc		hl
	dec a
	jr		@shr_loop
@shr_done:
	ld		hl,(bitbuf1)	;collect result
	ret

;------------------------------------------------------------------------
; Scratch area for calculations
;------------------------------------------------------------------------
bitbuf1:	dw24	0	;bit manipulation buffer 1
bitbuf2:	dw24	0	;bit manipulation buffer 2

; -----------------------------------------------------------------------
; Functions added by Brandon R. Gates
; -----------------------------------------------------------------------

;------------------------------------------------------------------------
; shr_hlu_div: Quick division by powers of two based on log2 of A
;              Determines the LSB of A and shifts HLU accordingly.
;              HLU = HLU >> LSB(A)
; Returns: HLU = HLU >> LSB(A)
; Destroys: af
;------------------------------------------------------------------------
shr_hlu_log2a:
	or a    ; check for zero
	ret z   ; nothing to shift so we're done
	push 	bc ; preserve
	ld		b,0 ; clear b
@find_bit:
	rrca ; bit 0 to carry
	jp c,@found_bit
	inc b ; next bit
	jp @find_bit
@found_bit:
	ld a,b
	call shr_hlu
	pop 	bc ; restore
	ret
; end shr_hlu_log2a

;------------------------------------------------------------------------
; shl_hlu_log2a: Quick multiplication by powers of two based on log2 of A
;                Determines the LSB of A and shifts HLU accordingly.
;                HLU = HLU << LSB(A)
; Returns: HLU = HLU << LSB(A)
; Destroys: af
;------------------------------------------------------------------------
shl_hlu_log2a:
	or a    ; check for zero
	ret z   ; nothing to shift so we're done
	push 	bc ; preserve
	ld		b,0 ; clear b
@find_bit:
	rrca ; bit 0 to carry
	jp c,@found_bit
	inc b ; next bit
	jp @find_bit
@found_bit:
	ld a,b
	call shl_hlu
	pop 	bc ; restore
	ret
; end shl_hlu_log2a


; UHL / UDE --> UDE (signed), remainder UHL (unsigned)
push af ; dummy push to make IDE happy
sdiv24:
; make everything positive and store sign flags
    call hlu_abs
    push af
    ex de,hl
    call hlu_abs
    ex de,hl
    push af
; do the division
    call udiv24 ; de = quotient, hl = remainder
; adjust sign of result
    pop af ; sign de
    jp m,@de_neg
    pop af ; sign hl
    ret p ; both positive, nothing to do
@hl_neg:
    ex de,hl ; quotient to hl for sign adjustment
    call neg_hlu ; de pos, hl neg, result is negative
    ex de,hl ; negated quotient to de
    ret
@de_neg:
    pop af
    ret m ; both negative, nothing to do
    ex de,hl ; quotient to hl for sign adjustment
    call neg_hlu ; result is negative
    ex de,hl ; negated quotient to de
    ret
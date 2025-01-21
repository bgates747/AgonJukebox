;------------------------------------------------------------------------
; Scratch area for calculations
;------------------------------------------------------------------------
scratch1: dw24 0 ;bit manipulation buffer 1
scratch2: dw24 0 ;bit manipulation buffer 2

; absolute value of hlu
; returns: abs(hlu), flags set according to the incoming sign of hlu:
;         s1,z0,pv0,n1,c0 if hlu was negative
;         s0,z1,pv0,n1,c0 if hlu was zero
;         s0,z0,pv0,n1,c0 if hlu was positive
; destroys: a
hlu_abs:
    add hl,de
    or a
    sbc hl,de 
    jp m,@is_neg
    ret ; hlu is positive or zero so we're done
@is_neg:
    push af ; otherwise, save current flags for return
    call neg_hlu ; negate hlu
    pop af ; get back flags
    ret

; flip the sign of hlu
; inputs: hlu
; returns: 0-hlu, flags set appropriately for the result:
;         s1,z0,pv0,n1,c1 if result is negative
;         s0,z1,pv0,n1,c0 if result is zero
;         s0,z0,pv0,n1,c1 if result is positive
; destroys a
neg_hlu:
    push de ; save de
    ex de,hl ; put hl into de
    ld hl,0 ; clear hl
    xor a ; clear carry
    sbc hl,de ; 0-hlu = -hlu
    pop de ; get de back
    ret ; easy peasy

;------------------------------------------------------------------------
; divide hlu by 2, inspired by above
;------------------------------------------------------------------------
hlu_div2:
    ld (scratch1),hl
    ld hl,scratch1+2
    rr (hl)
    dec hl
    rr (hl)
    dec hl
    rr (hl)
    inc hl
    inc hl
    ld hl,(scratch1)
    ret

; this is my little hack to divide by 16
hlu_div16:
    xor a
    add hl,hl
    rla
    add hl,hl
    rla
    add hl,hl
    rla
    add hl,hl
    rla
    ld (@scratch),hl
    ld (@scratch+3),a
    ld hl,(@scratch+1) 
    ret
@scratch: ds 4

; hlu signed division by 256
; returns: hlu / 256
; destroys: af
hlu_sdiv256:
    xor a ; assume hl is positive
    ld (@buffer),hl
    SIGN_HLU
    jp p,@hl_pos
    dec a
@hl_pos:
    ld (@buffer+3),a
    ld hl,(@buffer+1)
    ret
@buffer: ds 4

; hlu 1 byte right shift, unsigned
; returns: hlu / 256, fractional portion in a
; destroys: af
hlu_udiv256:
    xor a
    ld (@buffer+3),a
    ld a,l ; save the fractional portion
    ld (@buffer),hl
    ld hl,(@buffer+1)
    ret
@buffer: ds 4

; floor(value,n)
; inputs: hl = value to floor, de = n
; outputs: hl = value floored to n
; destroys: af, hl, bc, de
hlu_floor:
    push de ; save n
    call udiv24 ; de = quotient, hl = remainder
    pop hl ; get n back (was de)
    call umul24 ; hl = n * quotient
    ret
; end hlu_floor

; ceil(value,n)
; inputs: hl = value to ceil, de = n
; outputs: hl = value ceiled to n
; destroys: af, hl, bc, de
hlu_ceiling:
    push de ; save n
    call udiv24 ; de = quotient, hl = remainder
    SIGN_HLU ; test remaider for zero
    jp z,@F ; if zero, nothing to add
    inc de ; add 1 to quotient for the ceiling
@@:
    pop hl ; get n back (was de)
    call umul24 ; hl = n * quotient    
    ret
; end hlu_ceiling

    ret

add_bcd_arg1: db #00,#00,#00,#00
add_bcd_arg2: db #00,#00,#00,#00

; set bcd values in a scratch memory address from registers bcde
; input: hl; scratch address,bcde; 8-place bcd number
; destroys ; hl
set_bcd:
    ld (hl),e
    inc hl
    ld (hl),d
    inc hl
    ld (hl),c
    inc hl
    ld (hl),b
    ret

; load bcd values from a scratch memory address to bcde
; input: hl; scratch address
; output: bcde; 8-place bcd number
; destroys: hl
get_bcd:
    ld e,(hl)
    inc hl
    ld d,(hl)
    inc hl
    ld c,(hl)
    inc hl
    ld b,(hl)
    ret

; BCD addition
; inputs: (hl) and (de) point to BCD numbers of equal length (divisible by 2)
;       a is the number of bytes holding each number (number of places/2)
; outputs: (hl) + (de) --> (hl)
; destroys: a,b,de,hl
add_bcd:
    ld b,a ; loop counter
    xor a ; reset a, clear carry flag
adcec: 
    ld a,(de) ; addend to acc
    adc a,(hl) ; add (hl) to acc
    daa ; adjust result to bcd
    ld (hl),a ; store result
    inc hl ; advance memory pointers
    inc de
    djnz adcec ; loop until b == 0
    ret 

; BCD subtraction
; inputs: (hl) and (de) point to BCD numbers of equal length (divisible by 2)
;       a is the number of bytes holding each number (number of places/2)
; outputs: (hl) - (de) --> (hl)
; destroys: a,b,de,hl
sub_bcd:
    ld b,a ; loop counter
    xor a ; reset a,clear carry flag
subdec: 
    ld a,(de) ; subtrahend to acc
    sbc a,(hl) ; subtract (hl) from acc
    daa ; adjust result to bcd
    ld (hl),a ; store result
    inc hl ; advance memory pointers
    inc de
    djnz subdec ; loop until b == 0
    ret 

; http://www.z80.info/pseudo-random.txt
rand_8:
    push bc
    ld a,(r_seed)
    ld c,a 

    rrca ; multiply by 32
    rrca
    rrca
    xor 0x1f

    add a,c
    sbc a,255 ; carry

    ld (r_seed),a
    pop bc
    ret
r_seed: defb $50

; https://www.omnimaga.org/asm-language/ez80-optimized-routines/msg399325/#msg399325
prng24:
;;Expects ADL mode.
;;Output: HL
;;50cc
;;33 bytes
;;cycle length: 281,474,959,933,440 (about 2.8 trillion)
    ld de,(seed1)
    or a
    sbc hl,hl
    add hl,de
    add hl,hl
    add hl,hl
    inc l
    add hl,de
    ld (seed1),hl
    ld hl,(seed2)
    add hl,hl
    sbc a,a
    and %00011011
    xor l
    ld l,a
    ld (seed2),hl
    add hl,de
    ret
seed1: dl 0
seed2: dl 0


; https://map.grauw.nl/sources/external/z80bits.html#2.1
; h / l -> h, remain a
; 2.1 Restoring 8-bit / 8-bit Unsigned
; Input: H = Dividend, L = Divisor, A = 0
; Output: H = Quotient, A = Remainder, L = Divisor (unchanged)
udiv8:
    xor a
    ld b,8
@loop:
    sla h
    rla
    cp l
    jr c,$+4
    sub l
    inc h
    djnz @loop
    ret

; https://www.omnimaga.org/asm-language/(z80)-32-bit-by-16-bits-division-and-32-bit-square-root/msg406903/#msg406903
; This divides HLIX by BC
; The result is stored in HLIX, the remainder in DE
; BC is unmodified
; A is 0
udiv3216:
    ld de,0		; 10
    ld a,32		; 7
@loop:
    add.s ix,ix		; 15
    adc.s hl,hl		; 15
    ex de,hl		; 4
    adc.s hl,hl		; 15
    or a			; 4
    sbc.s hl,bc		; 15
    inc.s ix		; 10
    jr nc,@cansub		; 12/7
    add.s hl,bc		; 11
    dec.s ix		; 10
@cansub:
    ex de,hl		; 4
    dec a		; 4
    jr nz,@loop	; 12/7
    ret			; 10
; end udiv3216

; https://discord.com/channels/1158535358624039014/1282290921815408681/1329274504022720512
; calc84maniac's 32-bit by 23-bit division routine
; This divides AUIX by UDE (maximum 23 bits)
; The result is stored in AUIX, the remainder in UHL
; UDE, C are unmodified
; B is 0
udiv3223:
    or a,a         ; 1
    sbc hl,hl      ; 2
    ld b,32        ; 2
@loop:
    add ix,ix      ; 2
    adc a,a        ; 1
    adc hl,hl      ; 2
    sbc hl,de      ; 2
    inc ix         ; 2
    jr nc,@cansub  ; 2/4
    add hl,de      ; 1
    dec ix         ; 2
@cansub:
    djnz @loop     ; 2/4
    ret            ; 10
; end udiv3223

; calc84maniac https://discord.com/channels/1158535358624039014/1282290921815408681/1330991583369101322
; add uhl to signed integer a
add_uhl_a_signed:
    push de    ; 4 cycles
    ex de, hl  ; 1 cycle  UDE = UHL
    rlca       ; 1 cycle  CF = signbit(A)
    sbc hl, hl ; 2 cycles UHL = -signbit(A)
    rrca       ; 1 cycle  Restore A
    ld l, a    ; 1 cycle  UHL = signext(A)
    add hl, de ; 1 cycle  UHL = UDE + signext(A)
    pop de     ; 4 cycles
               ; 15 cycles total
    ret
; end hlu_add_a_signed

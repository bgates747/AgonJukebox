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

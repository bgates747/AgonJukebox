; multiply a signed 24-bit number by an unsigned 8-bit number giving a signed 24-bit result
; uses EZ80 MLT instruction for speed
; operation: UHL * A --> UHL
; destroys: AF, HL
smul24x8:
; make hl positive and store sign flag
    call hlu_abs
    push af
; do the division
    call mul24x8 ; hl = product
; adjust sign of result
    pop af ; sign de
    ret p ; hl was positive, nothing to do
    call neg_hlu ; result is negative
    ret

; unsigned multiplication of a 24-bit and 8-bit number giving a 32-bit result
; uses EZ80 MLT instruction for speed
; operation: UHL * A --> AUHL
; destroys: AF, HL
mul24x8:
    push de ; preserve de
; low byte
    ld e,l
    ld d,a
    mlt de
    ld l,e ; product low byte
    ex af,af' ; save multiplier
    ld a,d ; carry
    ex af,af' ; save carry, restore multiplier
; high byte
    ld e,h
    ld d,a
    mlt de
    ex af,af' ; save multiplier, restore carry
    add a,e ; add carry
    ld h,a ; product middle byte
    ld a,d ; carry
    ex af,af' ; save carry, restore multiplier
; upper byte
    ld (@scratch),hl ; 7 cycles
    ld e,a
    ld a,(@scratch+2)
    ld d,a
    mlt de
    ex af,af' ; restore carry
    adc a,e ; add carry
    ld (@scratch+2),a ; 5 cycles
    ld hl,(@scratch) ; 7 cycles
; highest byte
    ld a,0 ; preserve carry flag
    adc a,d ; product highest byte
    pop de ; restore de
    ret
@scratch: ds 3

mul24out: blkb 6,0

; unsigned multiplication of two 24-bit numbers giving a 48-bit result
; operation: UHL * UDE --> mul24out
mul24:
    push ix ; preserve
; point to output buffer and clear it
    ld ix,mul24out
    push bc
    ld bc,0
    ld (ix),bc
    ld (ix+3),bc
    pop bc
; STEP 1: UHL * E
    ld a,e
    push hl
    call mul24x8
    ld (ix+0),hl
    ld (ix+3),a
; STEP 2: UHL * D
    pop hl
    push hl
    ld a,d
    call mul24x8
    call @accumulate
; STEP 3: UHL * DEU
    pop hl
    ld (@de),de
    ld a,(@de+2)
    call mul24x8
    call @accumulate
; all done
    pop ix ; restore
    ret
@accumulate:
    inc ix
; highest byte of product to carry
    ld (ix+3),a
; low byte of product
    ld a,l
    add a,(ix+0)
    ld (ix+0),a
; high byte of product
    ld a,h
    adc a,(ix+1)
    ld (ix+1),a
; uppper byte of product
    ld (@hl),hl
    ld a,(@hl+2)
    adc a,(ix+2)
    ld (ix+2),a
; carry
    ld a,0 ; preserve flags
    adc a,(ix+3)
    ld (ix+3),a
    ret

@ix: dl 0
@hl: dl 0
@de: dl 0

; ; UHL * UDE --> UHL (unsigned)
; umul24:
;     call mul24
;     ld hl,(mul24out)
;     ret

; UH.L = UH.L*UD.E (unsigned)
umul168:
    call mul24
    ld hl,(mul24out+1)
    ret

; UH.L * UD.E --> UH.L (signed)
smul168:
; make everything positive and store sign flags
    call hlu_abs
    push af
    ex de,hl
    call hlu_abs
    ex de,hl
    push af
; do the division
    call umul168 ; hl = product
; adjust sign of result
    pop af ; sign de
    jp m,@de_neg
    pop af ; sign hl
    ret p ; both positive, nothing to do
@hl_neg:
    call neg_hlu ; de pos, hl neg, result is negative
    ret
@de_neg:
    pop af
    ret m ; both negative, nothing to do
    call neg_hlu ; result is negative
    ret

; UH.L / UD.E --> UD.E rem UHL (unsigned)
; perform unsigned division of 16.8 fixed place values
; with an unsigned 16.8 fixed place result and 24-bit remainder
udiv168:
; back up divisor
    ld (@ude),de
; get the 16-bit integer part of the quotient
    call udiv24 ; de = quotient, hl = remainder
; load quotient to upper three bytes of output
    ld (div168_out+1),de
@div256:
; multiply remainder by 256
    hlu_mul256
; skip fractional computation if remainder is zero
    SIGN_HLU
    jr nz,@div_frac
    xor a
    jr @write_frac
; now divide the shifted remainder by the divisor
@div_frac:
    ld de,(@ude) ; get back divisor
    call udiv24 ; de = quotient, hl = remainder
; load low byte of quotient to low byte of output
    ld a,e
@write_frac:
    ld (div168_out),a
; load de with return value
    ld de,(div168_out)
; load a with any overflow
    ld a,(div168_out+3)
    ret ; ud.e is the 16.8 result
@ude: ds 6
div168_out: ds 4 ; the extra byte is for overflow

; UH.L / UD.E --> UD.E (signed) rem UHL (unsigned)
; perform signed division of 16.8 fixed place values
; with a signed 16.8 fixed place result and unsigned 24-bit remainder
sdiv168:
; make everything positive and store sign flags
    call hlu_abs
    push af
    ex de,hl
    call hlu_abs
    ex de,hl
    push af
; do the division
    call udiv168 ; de = quotient, hl = remainder
; adjust sign of result
    pop af ; sign de
    jp m,@de_neg
    pop af ; sign hl
    ret p ; both positive, nothing to do
@hl_neg:
    ex de,hl ; hl = quotient, de = remainder
    call neg_hlu ; de pos, hl neg, result is negative
    ex de,hl ; de = negated quotient, hl = remainder
    ret
@de_neg:
    pop af
    ret m ; both negative, nothing to do
    ex de,hl ; hl = quotient, de = remainder
    call neg_hlu ; result is negative
    ex de,hl ; de = negated quotient, hl = remainder
    ret

; convert signed angles from a 360 to 256 degree circle
; inputs: uh.l is the angle360 in 16.8 fixed format
; outputs: uh.l is the angle256 in 16.8 fixed format
; destroys: TODO
deg_360_to_256:
    push de ; preserve de
; make angle positive and store sign flag
    call hlu_abs
    push af
; multiply by coversion factor of 256/360
    ld de,0x0000B6 ; 0.711
    call umul168 ; uh.l = uh.l * 0.711
; restore sign flag and adjust output accordingly
    pop af
    jp p,@pos ; positive number
    call neg_hlu
@pos:
; restore de and return uh.l as the result
    pop de
    ret

; convert signed angles from a 256 to 360 degree circle
; inputs: uh.l is the angle256 in 16.8 fixed format
; outputs: uh.l is the angle360 in 16.8 fixed format
; destroys: TODO
deg_256_to_360:
    push de ; preserve de
; make angle positive and store sign flag
    call hlu_abs
    push af
; multiply by coversion factor of 360/256
    ld de,0x000168 ; 1.406
    call umul168 ; uh.l = uh.l * 1.406
; restore sign flag and adjust output accordingly
    pop af
    jp p,@pos ; positive number
    call neg_hlu
@pos:
; restore de and return uh.l as the result
    pop de
    ret

; fixed 16.8 routine
; cos(uh.l) --> uh.l
; destroys: f, hl
cos168:
    push de ; preserve de
; for cos we simply increment the angle by 90 degrees
; or 0x004000 in 16.8 degrees256
; which makes it a sin problem
    ld de,0x004000
    add hl,de ; modulo 256 happens below
    pop de ; restore de
; fall through to sin168

; ---------------------
; fixed 16.8 routine
; sin(uh.l) --> uh.l
; destroys: f, hl
sin168:
    push de
; handle negative angles appropriately
    call hlu_abs
    jp p,@F
    ld de,-256*256
    add hl,de
@@:
    ld l,3 ; multiply by 3 to get our lookup index
    mlt hl
    ld de,sin_lut_168 ; grab the lut address
    add hl,de ; bump hl by the index
    ld hl,(hl) ; don't try this on a z80!
    pop de
    ret

; 16.8 fixed inputs / outputs
; takes: uh.l as angle in degrees 256
;        ud.e as radius
; returns ub.c as dx, ud.e as dy, uh.l as radius
;        displacements from origin (0,0)
; destroys: everything except indexes
polar_to_cartesian:
; back up input parameters
    ld (@angle), hl
    ld (@radius), de
; compute dx = sin(uh.l) * ud.e
    call sin168 ; uh.l = sin(uh.l)
    ld de,(@radius)
    call smul168 ; uh.l = dx
    push hl
; compute dy = -cos(uh.l) * ud.e
    ld hl,(@angle)
    call cos168 ; uh.l = cos(uh.l)
    ld de,(@radius)
    call smul168 ; uh.l = dy
    call neg_hlu ; invert dy for screen coords convention
    ex de,hl ; de = dy for output
    pop bc ; bc = dx for output
; and out
    ret
@angle: ds 3
@radius: ds 3

; 16.8 fixed inputs / outputs
; inputs: ub.c as dx, ud.e as dy
;        displacements from origin (0,0)
; returns: uh.l as angle in degrees 256
;        ud.e as radius
; destroys: everything except indexes
cartesian_to_polar:
    ld (dx168),bc ; dx argument for distance168
    ld (dy168),de ; dy argument for distance168
; compute radius
    call distance168 ; uh.l = radius
    push hl ; save radius
; compute angle
    ld bc,(dx168) ; dx argument for atan2_168fast
    ld de,(dy168) ; dy argument for atan2_168fast
    call atan2_168fast ; uh.l = angle
; return result
    pop de ; de = radius (was hl)
    ret
; end cartesian_to_polar

; 16.8 fixed inputs / outputs
; inputs: ub.c as dx, ud.e as dy
;        displacements from origin (0,0)
; returns: uh.l as angle in degrees 256
;        ud.e as radius
; destroys: everything except indexes
; note: uses distance168sm which is more accurate for small deltas
cartesian_to_polar_sm:
    ld (dx168),bc ; dx argument for distance168
    ld (dy168),de ; dy argument for distance168
; compute radius
    call distance168sm ; uh.l = radius
    push hl ; save radius
; compute angle
    ld bc,(dx168) ; dx argument for atan2_168fast
    ld de,(dy168) ; dy argument for atan2_168fast
    call atan2_168fast ; uh.l = angle
; return result
    pop de ; de = radius (was hl)
    ret
; end cartesian_to_polar

; inputs: ub.c and ud.e are x0 and y0 in 16.8 fixed format
;         ui.x and ui.y are x1 and y1 in 16.8 fixed format
; output: ub.c and ud.e are dx and dy in 16.8 fixed format
;         also populates scratch locations dx168 and dy168
; destroys: a,hl,bc,de
dxy168:
; compute dx = x1-x0
    xor a ; clear carry
    push ix ; move ix to hl via the stack
    pop hl ; hl = x1
    sbc hl,bc ; hl = dx
    ld (dx168),hl ; dx to scratch
; compute dy = y1-y0
    xor a ; clear carry
    push iy ; move iy to hl via the stack
    pop hl ; hl = y1
    sbc hl,de ; hl = dy
    ld (dy168),hl ; dy to scratch
; populate output registers and return
    ex de,hl ; ud.e = dy
    ld bc,(dx168) ; ub.c = dx
    ret
dx168: blkb 6,0
dy168: blkb 6,0

; compute the euclidian distance between two cartesian coordinates
; using the formula d = sqrt(dx^2+dy^2)
; inputs: dx168 and dy168 are dx and dy in 16.8 fixed format
; output; uh.l is the 16.8 fixed format distance
;         also populates scratch locations dx168 and dy168
; destroys: a,hl,bc,de
; NOTE: rounds both deltas down to the nearest integer to avoid overflow when squaring,
;       thus the result will always be an integer, albeit in 16.8 format
distance168:
; compute dy^2
    ld hl,(dy168)
    call hlu_abs
    ; call hlu_udiv256 ; make integer to avoid overflow
    SRL_UHL ; make integer to avoid overflow
    push hl
    pop de
    call umul24 ; hl = dy^2
    push hl ; save dy^2
; compute dx^2
    ld hl,(dx168)
    call hlu_abs
    ; call hlu_udiv256 ; make integer to avoid overflow
    SRL_UHL ; make integer to avoid overflow
    push hl
    pop de
    call umul24 ; hl = dx^2
; add dx^2 and dy^2
    pop de ; de = dy^2 (was hl)
    add hl,de ; hl = dx^2 + dy^2
; compute the square root
    call sqrt24 ; de = sqrt(dx^2 + dy^2)
    ex de,hl ; hl = distance
    hlu_mul256 ; convert back to 16.8 fixed
    ret

; compute the euclidian distance between two cartesian coordinates
; using the formula d = sqrt(dx^2+dy^2)
; inputs: dx168 and dy168 are dx and dy in 16.8 fixed format
; output; uh.l is the 16.8 fixed format distance
;         also populates scratch locations dx168 and dy168
; destroys: a,hl,bc,de
; NOTE: sm means 'small' because it doesn't round down the deltas
;       making it more accurate for small deltas, 
;       but will overflow if used for screen-sized deltas
distance168sm:
; compute dy^2
    ld hl,(dy168)
    call hlu_abs
    push hl
    pop de
    call umul24 ; hl = dy^2
    push hl ; save dy^2
; compute dx^2
    ld hl,(dx168)
    call hlu_abs
    push hl
    pop de
    call umul24 ; hl = dx^2
; add dx^2 and dy^2
    pop de ; de = dy^2 (was hl)
    add hl,de ; hl = dx^2 + dy^2
; compute the square root
    call sqrt24 ; de = sqrt(dx^2 + dy^2)
    ex de,hl ; hl = distance
    ret

; atan2_(ub.c,ud.e) --> uh.l
; inputs: ub.c and ud.e are dx and dy in 16.8 fixed format
;   whether inputs are integers or fractional doesn't matter
;   so long as the sign bit of the upper byte is correct
; output: uh.l is the 16.8 fixed angle in degrees 256
; angles are COMPASS HEADINGS based on
; screen coordinate conventions,where the y axis is flipped
; #E0 224      0       32 #20
;        -x,-y | +x,-y
; #C0 192------+------ 64 #40
;        -x,+y | +x,+y
; #A0 160   128 #80   96 #60
atan2_168fast:
; get signs and make everything positive
; get abs(x) and store its original sign
    push bc
    pop hl
    call hlu_abs ; if x was negative this also sets the sign flag
    push hl ; store abs(x)
    pop bc ; bc = abs(x)
    push af ; store sign of x
; get abs(y) and store its original sign
    ex de,hl ; hl = y
    call hlu_abs ; if y was negative this also sets the sign flag
    ex de,hl ; de = abs(y)
    push af ; store sign of y
; if abs(bc) < abs(de),then we do bc/de,otherwise de/bc
; this ensures that our lookup value is between 0 and 1 inclusive
    xor a ; clear the carry flag
    push de
    pop hl
    sbc hl,bc
    push af ; save sign of de - bc
    jp p,@1 ; bc <= de, so we skip ahead
; otherwise we swap bc and de
    push bc
    pop hl
    ex de,hl
    push hl
    pop bc
@1:
; now we're ready to snag our preliminary result
    push bc
    pop hl
    call atan_168fast ; uh.l comes back with prelim result
; now we adjust uh.l based on sign of de - bc
    pop af
    jp p,@2 ; bc <= de,so we skip ahead
    ex de,hl
    ld hl,64*256 ; subtract from 64 (90) degrees
    xor a ; clear the carry flag
    sbc hl,de
@2:
; adjust the result based on quadrant
; #E0 224      0       32 #20
;        -x,-y | +x,-y
; #C0 192------+------ 64 #40
;        -x,+y | +x,+y
; #A0 160   128 #80   96 #60
    pop af ; sign of y
    jp z,@y_zero
    jp p,@y_pos
; y neg,check x
    pop af ; sign of x
    jp z,@y_neg_x_zero
    jp p,@y_neg_x_pos
; y neg,x neg
; angle is 128 to 256 (270 to 360)
; negating the intermediate does the trick
    call neg_hlu
    jr @zero_hlu

@y_neg_x_zero:
; y neg,x zero
; angle is 0
    ld hl,0
    ret
@y_neg_x_pos:
; y neg,x pos
; angle is 0 to 64 (0 to 90)
; so we're good
    ret

@y_pos:
    pop af ; sign of x
    jp z,@y_pos_x_zero
    jp p,@y_pos_x_pos
; y pos,x neg
; angle is 128 to 192 (180-270)
; so we add 128 to intermediate
    ld de,128*256
    add hl,de
    jr @zero_hlu
@y_pos_x_zero:
; y pos,x zero
; angle is 128 (180)
    ld hl,128*256
    ret
@y_pos_x_pos:
; y pos,x pos
; angle is 64 to 128 (90 to 180)
; neg the intermediate and add 180 degrees
    call neg_hlu
    ld de,128*256
    add hl,de
    jr @zero_hlu

@y_zero:
    pop af ; sign of x
    jp m,@y_zero_x_neg
; y zero,x pos
; angle is 64 (90),nothing to do
    ret
@y_zero_x_neg:
; y zero ,x neg
; angle is 192 (270)
    ld hl,192*256
    ret
@zero_hlu:
    xor a
    ld (@scratch),hl
    ld (@scratch+2),a
    ld hl,(@scratch)
    ret
@scratch: ds 6

; inputs: ub.c and ud.e are dx and dy in 16.8 fixed format
; output: uh.l is the 16.8 fixed format angle in degrees 256
; destroys: a,hl,bc,de
; note: only works for angles from 0 to 32 (45) degrees
;   use atan2_168fast (which calls this proc) to handle the full 256 (360) degrees
atan_168fast:
; because we use compass headings instead of geometric angles
; we compute dx/dy which is 1/tan(theta) in the maths world
; we can do faster unsigned division here because we know dx and dy are positive
    call udiv168 ; ud.e = dx/dy
    ex de,hl ; uh.l = dx/dy
; test uh.l for 0
    add hl,de
    or a
    sbc hl,de
    jr z,@is_zero
; test uh.l for 1
    xor a ; clear carry
    ex de,hl
    ld hl,1*256 ; 1 in 16.8 fixed format
    sbc hl,de
    jr z,@is_45
    ex de,hl
; no special cases so we move on
; l contains the fractional portion of tan(uh.l)
; we multiply it by three to get our lookup table index
    ld h,3
    mlt hl ; index into lut
    ld de,0 ; clear deu
    ld d,h ; copy hl to de
    ld e,l ; de contains our index
    ld hl,atan_lut_168 ; grab the lut address
    add hl,de ; bump hl by the index
    ld hl,(hl) ; don't try this on a z80!
    ret ; and out
@is_45:
    ld hl,32*256
    ret
; for the case tan(0)
@is_zero:
    ld hl,0*256
    ret

; Expects  ADL mode
; Inputs:  UH.L
; Outputs: UH.L is the 16.8 square root
;          UDE is the integer difference inputHL-DE^2
sqrt168:
    call sqrt24
    ex de,hl
    add hl,hl
    add hl,hl
    add hl,hl
    add hl,hl
    ret

; credit: xeda112358
; https://www.cemetech.net/forum/viewtopic.php?t=11178&postdays=0&postorder=asc&start=0
sqrt24:
; Expects ADL mode
; Inputs: HL
; Outputs: DE is the integer square root
;  HL is the difference inputHL-DE^2
;  c flag reset
    ld bc,0 ; clear bcu
    ld de,0 ; clear deu
    xor a
    ld b,l
    push bc
    ld b,a
    ld l,a
; Iteration 1
    add hl,hl
    rl c
    add hl,hl
    rl c
    sub c
    jr nc,$+6
    inc e
    inc e
    cpl
    ld c,a
; Iteration 2
    add hl,hl
    rl c
    add hl,hl
    rl c
    rl e
    ld a,e
    sub c
    jr nc,$+6
    inc e
    inc e
    cpl
    ld c,a
; Iteration 3
    add hl,hl
    rl c
    add hl,hl
    rl c
    rl e
    ld a,e
    sub c
    jr nc,$+6
    inc e
    inc e
    cpl
    ld c,a
; Iteration 4
    add hl,hl
    rl c
    add hl,hl
    rl c
    rl e
    ld a,e
    sub c
    jr nc,$+6
    inc e
    inc e
    cpl
    ld c,a
; Iteration 5
    add hl,hl
    rl c
    add hl,hl
    rl c
    rl e
    ld a,e
    sub c
    jr nc,$+6
    inc e
    inc e
    cpl
    ld c,a
; Iteration 6
    add hl,hl
    rl c
    add hl,hl
    rl c
    rl e
    ld a,e
    sub c
    jr nc,$+6
    inc e
    inc e
    cpl
    ld c,a
; Iteration 7
    add hl,hl
    rl c
    add hl,hl
    rl c
    rl b
    ex de,hl
    add hl,hl
    push hl
    sbc hl,bc
    jr nc,$+8
    ld a,h
    cpl
    ld b,a
    ld a,l
    cpl
    ld c,a
    pop hl
    jr nc,$+4
    inc hl
    inc hl
    ex de,hl
; Iteration 8
    add hl,hl
    ld l,c
    ld h,b
    adc hl,hl
    adc hl,hl
    ex de,hl
    add hl,hl
    sbc hl,de
    add hl,de
    ex de,hl
    jr nc,$+6
    sbc hl,de
    inc de
    inc de
; Iteration 9
    pop af
    rla
    adc hl,hl
    rla
    adc hl,hl
    ex de,hl
    add hl,hl
    sbc hl,de
    add hl,de
    ex de,hl
    jr nc,$+6
    sbc hl,de
    inc de
    inc de
; Iteration 10
    rla
    adc hl,hl
    rla
    adc hl,hl
    ex de,hl
    add hl,hl
    sbc hl,de
    add hl,de
    ex de,hl
    jr nc,$+6
    sbc hl,de
    inc de
    inc de
; Iteration 11
    rla
    adc hl,hl
    rla
    adc hl,hl
    ex de,hl
    add hl,hl
    sbc hl,de
    add hl,de
    ex de,hl
    jr nc,$+6
    sbc hl,de
    inc de
    inc de
; Iteration 12
    rla
    adc hl,hl
    rla
    adc hl,hl
    ex de,hl
    add hl,hl
    sbc hl,de
    add hl,de
    ex de,hl
    jr nc,$+6
    sbc hl,de
    inc de
    inc de
    rr d
    rr e
    ret

sin_lut_168:
    dl 0x000000 ; 0.000 00, 0.000
    dl 0x000006 ; 1.406 01, 0.025
    dl 0x00000C ; 2.813 02, 0.049
    dl 0x000012 ; 4.219 03, 0.074
    dl 0x000019 ; 5.625 04, 0.098
    dl 0x00001F ; 7.031 05, 0.122
    dl 0x000025 ; 8.438 06, 0.147
    dl 0x00002B ; 9.844 07, 0.171
    dl 0x000031 ; 11.250 08, 0.195
    dl 0x000038 ; 12.656 09, 0.219
    dl 0x00003E ; 14.063 0A, 0.243
    dl 0x000044 ; 15.469 0B, 0.267
    dl 0x00004A ; 16.875 0C, 0.290
    dl 0x000050 ; 18.281 0D, 0.314
    dl 0x000056 ; 19.688 0E, 0.337
    dl 0x00005C ; 21.094 0F, 0.360
    dl 0x000061 ; 22.500 10, 0.383
    dl 0x000067 ; 23.906 11, 0.405
    dl 0x00006D ; 25.313 12, 0.428
    dl 0x000073 ; 26.719 13, 0.450
    dl 0x000078 ; 28.125 14, 0.471
    dl 0x00007E ; 29.531 15, 0.493
    dl 0x000083 ; 30.938 16, 0.514
    dl 0x000088 ; 32.344 17, 0.535
    dl 0x00008E ; 33.750 18, 0.556
    dl 0x000093 ; 35.156 19, 0.576
    dl 0x000098 ; 36.563 1A, 0.596
    dl 0x00009D ; 37.969 1B, 0.615
    dl 0x0000A2 ; 39.375 1C, 0.634
    dl 0x0000A7 ; 40.781 1D, 0.653
    dl 0x0000AB ; 42.188 1E, 0.672
    dl 0x0000B0 ; 43.594 1F, 0.690
    dl 0x0000B5 ; 45.000 20, 0.707
    dl 0x0000B9 ; 46.406 21, 0.724
    dl 0x0000BD ; 47.813 22, 0.741
    dl 0x0000C1 ; 49.219 23, 0.757
    dl 0x0000C5 ; 50.625 24, 0.773
    dl 0x0000C9 ; 52.031 25, 0.788
    dl 0x0000CD ; 53.438 26, 0.803
    dl 0x0000D1 ; 54.844 27, 0.818
    dl 0x0000D4 ; 56.250 28, 0.831
    dl 0x0000D8 ; 57.656 29, 0.845
    dl 0x0000DB ; 59.063 2A, 0.858
    dl 0x0000DE ; 60.469 2B, 0.870
    dl 0x0000E1 ; 61.875 2C, 0.882
    dl 0x0000E4 ; 63.281 2D, 0.893
    dl 0x0000E7 ; 64.688 2E, 0.904
    dl 0x0000EA ; 66.094 2F, 0.914
    dl 0x0000EC ; 67.500 30, 0.924
    dl 0x0000EE ; 68.906 31, 0.933
    dl 0x0000F1 ; 70.313 32, 0.942
    dl 0x0000F3 ; 71.719 33, 0.950
    dl 0x0000F4 ; 73.125 34, 0.957
    dl 0x0000F6 ; 74.531 35, 0.964
    dl 0x0000F8 ; 75.938 36, 0.970
    dl 0x0000F9 ; 77.344 37, 0.976
    dl 0x0000FB ; 78.750 38, 0.981
    dl 0x0000FC ; 80.156 39, 0.985
    dl 0x0000FD ; 81.563 3A, 0.989
    dl 0x0000FE ; 82.969 3B, 0.992
    dl 0x0000FE ; 84.375 3C, 0.995
    dl 0x0000FF ; 85.781 3D, 0.997
    dl 0x0000FF ; 87.188 3E, 0.999
    dl 0x0000FF ; 88.594 3F, 1.000
    dl 0x000100 ; 90.000 40, 1.000
    dl 0x0000FF ; 91.406 41, 1.000
    dl 0x0000FF ; 92.813 42, 0.999
    dl 0x0000FF ; 94.219 43, 0.997
    dl 0x0000FE ; 95.625 44, 0.995
    dl 0x0000FE ; 97.031 45, 0.992
    dl 0x0000FD ; 98.438 46, 0.989
    dl 0x0000FC ; 99.844 47, 0.985
    dl 0x0000FB ; 101.250 48, 0.981
    dl 0x0000F9 ; 102.656 49, 0.976
    dl 0x0000F8 ; 104.063 4A, 0.970
    dl 0x0000F6 ; 105.469 4B, 0.964
    dl 0x0000F4 ; 106.875 4C, 0.957
    dl 0x0000F3 ; 108.281 4D, 0.950
    dl 0x0000F1 ; 109.688 4E, 0.942
    dl 0x0000EE ; 111.094 4F, 0.933
    dl 0x0000EC ; 112.500 50, 0.924
    dl 0x0000EA ; 113.906 51, 0.914
    dl 0x0000E7 ; 115.313 52, 0.904
    dl 0x0000E4 ; 116.719 53, 0.893
    dl 0x0000E1 ; 118.125 54, 0.882
    dl 0x0000DE ; 119.531 55, 0.870
    dl 0x0000DB ; 120.938 56, 0.858
    dl 0x0000D8 ; 122.344 57, 0.845
    dl 0x0000D4 ; 123.750 58, 0.831
    dl 0x0000D1 ; 125.156 59, 0.818
    dl 0x0000CD ; 126.563 5A, 0.803
    dl 0x0000C9 ; 127.969 5B, 0.788
    dl 0x0000C5 ; 129.375 5C, 0.773
    dl 0x0000C1 ; 130.781 5D, 0.757
    dl 0x0000BD ; 132.188 5E, 0.741
    dl 0x0000B9 ; 133.594 5F, 0.724
    dl 0x0000B5 ; 135.000 60, 0.707
    dl 0x0000B0 ; 136.406 61, 0.690
    dl 0x0000AB ; 137.813 62, 0.672
    dl 0x0000A7 ; 139.219 63, 0.653
    dl 0x0000A2 ; 140.625 64, 0.634
    dl 0x00009D ; 142.031 65, 0.615
    dl 0x000098 ; 143.438 66, 0.596
    dl 0x000093 ; 144.844 67, 0.576
    dl 0x00008E ; 146.250 68, 0.556
    dl 0x000088 ; 147.656 69, 0.535
    dl 0x000083 ; 149.063 6A, 0.514
    dl 0x00007E ; 150.469 6B, 0.493
    dl 0x000078 ; 151.875 6C, 0.471
    dl 0x000073 ; 153.281 6D, 0.450
    dl 0x00006D ; 154.688 6E, 0.428
    dl 0x000067 ; 156.094 6F, 0.405
    dl 0x000061 ; 157.500 70, 0.383
    dl 0x00005C ; 158.906 71, 0.360
    dl 0x000056 ; 160.313 72, 0.337
    dl 0x000050 ; 161.719 73, 0.314
    dl 0x00004A ; 163.125 74, 0.290
    dl 0x000044 ; 164.531 75, 0.267
    dl 0x00003E ; 165.938 76, 0.243
    dl 0x000038 ; 167.344 77, 0.219
    dl 0x000031 ; 168.750 78, 0.195
    dl 0x00002B ; 170.156 79, 0.171
    dl 0x000025 ; 171.563 7A, 0.147
    dl 0x00001F ; 172.969 7B, 0.122
    dl 0x000019 ; 174.375 7C, 0.098
    dl 0x000012 ; 175.781 7D, 0.074
    dl 0x00000C ; 177.188 7E, 0.049
    dl 0x000006 ; 178.594 7F, 0.025
    dl 0x000000 ; 180.000 80, 0.000
    dl 0xFFFFFA ; 181.406 81, -0.025
    dl 0xFFFFF4 ; 182.813 82, -0.049
    dl 0xFFFFEE ; 184.219 83, -0.074
    dl 0xFFFFE7 ; 185.625 84, -0.098
    dl 0xFFFFE1 ; 187.031 85, -0.122
    dl 0xFFFFDB ; 188.438 86, -0.147
    dl 0xFFFFD5 ; 189.844 87, -0.171
    dl 0xFFFFCF ; 191.250 88, -0.195
    dl 0xFFFFC8 ; 192.656 89, -0.219
    dl 0xFFFFC2 ; 194.063 8A, -0.243
    dl 0xFFFFBC ; 195.469 8B, -0.267
    dl 0xFFFFB6 ; 196.875 8C, -0.290
    dl 0xFFFFB0 ; 198.281 8D, -0.314
    dl 0xFFFFAA ; 199.688 8E, -0.337
    dl 0xFFFFA4 ; 201.094 8F, -0.360
    dl 0xFFFF9F ; 202.500 90, -0.383
    dl 0xFFFF99 ; 203.906 91, -0.405
    dl 0xFFFF93 ; 205.313 92, -0.428
    dl 0xFFFF8D ; 206.719 93, -0.450
    dl 0xFFFF88 ; 208.125 94, -0.471
    dl 0xFFFF82 ; 209.531 95, -0.493
    dl 0xFFFF7D ; 210.938 96, -0.514
    dl 0xFFFF78 ; 212.344 97, -0.535
    dl 0xFFFF72 ; 213.750 98, -0.556
    dl 0xFFFF6D ; 215.156 99, -0.576
    dl 0xFFFF68 ; 216.563 9A, -0.596
    dl 0xFFFF63 ; 217.969 9B, -0.615
    dl 0xFFFF5E ; 219.375 9C, -0.634
    dl 0xFFFF59 ; 220.781 9D, -0.653
    dl 0xFFFF55 ; 222.188 9E, -0.672
    dl 0xFFFF50 ; 223.594 9F, -0.690
    dl 0xFFFF4B ; 225.000 A0, -0.707
    dl 0xFFFF47 ; 226.406 A1, -0.724
    dl 0xFFFF43 ; 227.813 A2, -0.741
    dl 0xFFFF3F ; 229.219 A3, -0.757
    dl 0xFFFF3B ; 230.625 A4, -0.773
    dl 0xFFFF37 ; 232.031 A5, -0.788
    dl 0xFFFF33 ; 233.438 A6, -0.803
    dl 0xFFFF2F ; 234.844 A7, -0.818
    dl 0xFFFF2C ; 236.250 A8, -0.831
    dl 0xFFFF28 ; 237.656 A9, -0.845
    dl 0xFFFF25 ; 239.063 AA, -0.858
    dl 0xFFFF22 ; 240.469 AB, -0.870
    dl 0xFFFF1F ; 241.875 AC, -0.882
    dl 0xFFFF1C ; 243.281 AD, -0.893
    dl 0xFFFF19 ; 244.688 AE, -0.904
    dl 0xFFFF16 ; 246.094 AF, -0.914
    dl 0xFFFF14 ; 247.500 B0, -0.924
    dl 0xFFFF12 ; 248.906 B1, -0.933
    dl 0xFFFF0F ; 250.313 B2, -0.942
    dl 0xFFFF0D ; 251.719 B3, -0.950
    dl 0xFFFF0C ; 253.125 B4, -0.957
    dl 0xFFFF0A ; 254.531 B5, -0.964
    dl 0xFFFF08 ; 255.938 B6, -0.970
    dl 0xFFFF07 ; 257.344 B7, -0.976
    dl 0xFFFF05 ; 258.750 B8, -0.981
    dl 0xFFFF04 ; 260.156 B9, -0.985
    dl 0xFFFF03 ; 261.563 BA, -0.989
    dl 0xFFFF02 ; 262.969 BB, -0.992
    dl 0xFFFF02 ; 264.375 BC, -0.995
    dl 0xFFFF01 ; 265.781 BD, -0.997
    dl 0xFFFF01 ; 267.188 BE, -0.999
    dl 0xFFFF01 ; 268.594 BF, -1.000
    dl 0xFFFF00 ; 270.000 C0, -1.000
    dl 0xFFFF01 ; 271.406 C1, -1.000
    dl 0xFFFF01 ; 272.813 C2, -0.999
    dl 0xFFFF01 ; 274.219 C3, -0.997
    dl 0xFFFF02 ; 275.625 C4, -0.995
    dl 0xFFFF02 ; 277.031 C5, -0.992
    dl 0xFFFF03 ; 278.438 C6, -0.989
    dl 0xFFFF04 ; 279.844 C7, -0.985
    dl 0xFFFF05 ; 281.250 C8, -0.981
    dl 0xFFFF07 ; 282.656 C9, -0.976
    dl 0xFFFF08 ; 284.063 CA, -0.970
    dl 0xFFFF0A ; 285.469 CB, -0.964
    dl 0xFFFF0C ; 286.875 CC, -0.957
    dl 0xFFFF0D ; 288.281 CD, -0.950
    dl 0xFFFF0F ; 289.688 CE, -0.942
    dl 0xFFFF12 ; 291.094 CF, -0.933
    dl 0xFFFF14 ; 292.500 D0, -0.924
    dl 0xFFFF16 ; 293.906 D1, -0.914
    dl 0xFFFF19 ; 295.313 D2, -0.904
    dl 0xFFFF1C ; 296.719 D3, -0.893
    dl 0xFFFF1F ; 298.125 D4, -0.882
    dl 0xFFFF22 ; 299.531 D5, -0.870
    dl 0xFFFF25 ; 300.938 D6, -0.858
    dl 0xFFFF28 ; 302.344 D7, -0.845
    dl 0xFFFF2C ; 303.750 D8, -0.831
    dl 0xFFFF2F ; 305.156 D9, -0.818
    dl 0xFFFF33 ; 306.563 DA, -0.803
    dl 0xFFFF37 ; 307.969 DB, -0.788
    dl 0xFFFF3B ; 309.375 DC, -0.773
    dl 0xFFFF3F ; 310.781 DD, -0.757
    dl 0xFFFF43 ; 312.188 DE, -0.741
    dl 0xFFFF47 ; 313.594 DF, -0.724
    dl 0xFFFF4B ; 315.000 E0, -0.707
    dl 0xFFFF50 ; 316.406 E1, -0.690
    dl 0xFFFF55 ; 317.813 E2, -0.672
    dl 0xFFFF59 ; 319.219 E3, -0.653
    dl 0xFFFF5E ; 320.625 E4, -0.634
    dl 0xFFFF63 ; 322.031 E5, -0.615
    dl 0xFFFF68 ; 323.438 E6, -0.596
    dl 0xFFFF6D ; 324.844 E7, -0.576
    dl 0xFFFF72 ; 326.250 E8, -0.556
    dl 0xFFFF78 ; 327.656 E9, -0.535
    dl 0xFFFF7D ; 329.063 EA, -0.514
    dl 0xFFFF82 ; 330.469 EB, -0.493
    dl 0xFFFF88 ; 331.875 EC, -0.471
    dl 0xFFFF8D ; 333.281 ED, -0.450
    dl 0xFFFF93 ; 334.688 EE, -0.428
    dl 0xFFFF99 ; 336.094 EF, -0.405
    dl 0xFFFF9F ; 337.500 F0, -0.383
    dl 0xFFFFA4 ; 338.906 F1, -0.360
    dl 0xFFFFAA ; 340.313 F2, -0.337
    dl 0xFFFFB0 ; 341.719 F3, -0.314
    dl 0xFFFFB6 ; 343.125 F4, -0.290
    dl 0xFFFFBC ; 344.531 F5, -0.267
    dl 0xFFFFC2 ; 345.938 F6, -0.243
    dl 0xFFFFC8 ; 347.344 F7, -0.219
    dl 0xFFFFCF ; 348.750 F8, -0.195
    dl 0xFFFFD5 ; 350.156 F9, -0.171
    dl 0xFFFFDB ; 351.563 FA, -0.147
    dl 0xFFFFE1 ; 352.969 FB, -0.122
    dl 0xFFFFE7 ; 354.375 FC, -0.098
    dl 0xFFFFEE ; 355.781 FD, -0.074
    dl 0xFFFFF4 ; 357.188 FE, -0.049
    dl 0xFFFFFA ; 358.594 FF, -0.025
    dl 0x000000 ; 0.000 00, 0.000 for interpolation

atan_lut_168:
    dl 0x000000 ; 000000, 0.000
    dl 0x000028 ; 000001, 0.224
    dl 0x000051 ; 000002, 0.448
    dl 0x00007A ; 000003, 0.671
    dl 0x0000A2 ; 000004, 0.895
    dl 0x0000CB ; 000005, 1.119
    dl 0x0000F4 ; 000006, 1.343
    dl 0x00011D ; 000007, 1.566
    dl 0x000145 ; 000008, 1.790
    dl 0x00016E ; 000009, 2.013
    dl 0x000197 ; 00000A, 2.237
    dl 0x0001BF ; 00000B, 2.460
    dl 0x0001E8 ; 00000C, 2.684
    dl 0x000211 ; 00000D, 2.907
    dl 0x000239 ; 00000E, 3.130
    dl 0x000262 ; 00000F, 3.353
    dl 0x00028B ; 000010, 3.576
    dl 0x0002B3 ; 000011, 3.799
    dl 0x0002DC ; 000012, 4.022
    dl 0x000304 ; 000013, 4.245
    dl 0x00032D ; 000014, 4.467
    dl 0x000355 ; 000015, 4.690
    dl 0x00037E ; 000016, 4.912
    dl 0x0003A6 ; 000017, 5.134
    dl 0x0003CE ; 000018, 5.356
    dl 0x0003F7 ; 000019, 5.578
    dl 0x00041F ; 00001A, 5.799
    dl 0x000448 ; 00001B, 6.021
    dl 0x000470 ; 00001C, 6.242
    dl 0x000498 ; 00001D, 6.463
    dl 0x0004C0 ; 00001E, 6.684
    dl 0x0004E8 ; 00001F, 6.905
    dl 0x000511 ; 000020, 7.125
    dl 0x000539 ; 000021, 7.345
    dl 0x000561 ; 000022, 7.565
    dl 0x000589 ; 000023, 7.785
    dl 0x0005B1 ; 000024, 8.005
    dl 0x0005D9 ; 000025, 8.224
    dl 0x000601 ; 000026, 8.443
    dl 0x000628 ; 000027, 8.662
    dl 0x000650 ; 000028, 8.881
    dl 0x000678 ; 000029, 9.099
    dl 0x0006A0 ; 00002A, 9.317
    dl 0x0006C7 ; 00002B, 9.535
    dl 0x0006EF ; 00002C, 9.752
    dl 0x000716 ; 00002D, 9.970
    dl 0x00073E ; 00002E, 10.187
    dl 0x000765 ; 00002F, 10.403
    dl 0x00078D ; 000030, 10.620
    dl 0x0007B4 ; 000031, 10.836
    dl 0x0007DB ; 000032, 11.051
    dl 0x000803 ; 000033, 11.267
    dl 0x00082A ; 000034, 11.482
    dl 0x000851 ; 000035, 11.697
    dl 0x000878 ; 000036, 11.911
    dl 0x00089F ; 000037, 12.125
    dl 0x0008C6 ; 000038, 12.339
    dl 0x0008ED ; 000039, 12.553
    dl 0x000913 ; 00003A, 12.766
    dl 0x00093A ; 00003B, 12.978
    dl 0x000961 ; 00003C, 13.191
    dl 0x000987 ; 00003D, 13.403
    dl 0x0009AE ; 00003E, 13.614
    dl 0x0009D4 ; 00003F, 13.825
    dl 0x0009FB ; 000040, 14.036
    dl 0x000A21 ; 000041, 14.247
    dl 0x000A47 ; 000042, 14.457
    dl 0x000A6D ; 000043, 14.666
    dl 0x000A94 ; 000044, 14.876
    dl 0x000ABA ; 000045, 15.085
    dl 0x000AE0 ; 000046, 15.293
    dl 0x000B05 ; 000047, 15.501
    dl 0x000B2B ; 000048, 15.709
    dl 0x000B51 ; 000049, 15.916
    dl 0x000B77 ; 00004A, 16.123
    dl 0x000B9C ; 00004B, 16.329
    dl 0x000BC2 ; 00004C, 16.535
    dl 0x000BE7 ; 00004D, 16.740
    dl 0x000C0C ; 00004E, 16.945
    dl 0x000C32 ; 00004F, 17.150
    dl 0x000C57 ; 000050, 17.354
    dl 0x000C7C ; 000051, 17.558
    dl 0x000CA1 ; 000052, 17.761
    dl 0x000CC6 ; 000053, 17.964
    dl 0x000CEB ; 000054, 18.166
    dl 0x000D0F ; 000055, 18.368
    dl 0x000D34 ; 000056, 18.569
    dl 0x000D58 ; 000057, 18.770
    dl 0x000D7D ; 000058, 18.970
    dl 0x000DA1 ; 000059, 19.170
    dl 0x000DC6 ; 00005A, 19.370
    dl 0x000DEA ; 00005B, 19.569
    dl 0x000E0E ; 00005C, 19.767
    dl 0x000E32 ; 00005D, 19.965
    dl 0x000E56 ; 00005E, 20.163
    dl 0x000E7A ; 00005F, 20.360
    dl 0x000E9E ; 000060, 20.556
    dl 0x000EC1 ; 000061, 20.752
    dl 0x000EE5 ; 000062, 20.947
    dl 0x000F08 ; 000063, 21.142
    dl 0x000F2C ; 000064, 21.337
    dl 0x000F4F ; 000065, 21.531
    dl 0x000F72 ; 000066, 21.724
    dl 0x000F95 ; 000067, 21.917
    dl 0x000FB8 ; 000068, 22.109
    dl 0x000FDB ; 000069, 22.301
    dl 0x000FFE ; 00006A, 22.493
    dl 0x001021 ; 00006B, 22.683
    dl 0x001044 ; 00006C, 22.874
    dl 0x001066 ; 00006D, 23.063
    dl 0x001089 ; 00006E, 23.253
    dl 0x0010AB ; 00006F, 23.441
    dl 0x0010CD ; 000070, 23.629
    dl 0x0010EF ; 000071, 23.817
    dl 0x001111 ; 000072, 24.004
    dl 0x001133 ; 000073, 24.191
    dl 0x001155 ; 000074, 24.376
    dl 0x001177 ; 000075, 24.562
    dl 0x001199 ; 000076, 24.747
    dl 0x0011BA ; 000077, 24.931
    dl 0x0011DC ; 000078, 25.115
    dl 0x0011FD ; 000079, 25.298
    dl 0x00121E ; 00007A, 25.481
    dl 0x00123F ; 00007B, 25.663
    dl 0x001260 ; 00007C, 25.844
    dl 0x001281 ; 00007D, 26.025
    dl 0x0012A2 ; 00007E, 26.206
    dl 0x0012C3 ; 00007F, 26.386
    dl 0x0012E4 ; 000080, 26.565
    dl 0x001304 ; 000081, 26.744
    dl 0x001325 ; 000082, 26.922
    dl 0x001345 ; 000083, 27.100
    dl 0x001365 ; 000084, 27.277
    dl 0x001385 ; 000085, 27.453
    dl 0x0013A5 ; 000086, 27.629
    dl 0x0013C5 ; 000087, 27.805
    dl 0x0013E5 ; 000088, 27.979
    dl 0x001405 ; 000089, 28.154
    dl 0x001424 ; 00008A, 28.327
    dl 0x001444 ; 00008B, 28.501
    dl 0x001463 ; 00008C, 28.673
    dl 0x001483 ; 00008D, 28.845
    dl 0x0014A2 ; 00008E, 29.017
    dl 0x0014C1 ; 00008F, 29.187
    dl 0x0014E0 ; 000090, 29.358
    dl 0x0014FF ; 000091, 29.527
    dl 0x00151E ; 000092, 29.697
    dl 0x00153C ; 000093, 29.865
    dl 0x00155B ; 000094, 30.033
    dl 0x001579 ; 000095, 30.201
    dl 0x001598 ; 000096, 30.368
    dl 0x0015B6 ; 000097, 30.534
    dl 0x0015D4 ; 000098, 30.700
    dl 0x0015F2 ; 000099, 30.865
    dl 0x001610 ; 00009A, 31.030
    dl 0x00162E ; 00009B, 31.194
    dl 0x00164C ; 00009C, 31.357
    dl 0x00166A ; 00009D, 31.520
    dl 0x001687 ; 00009E, 31.682
    dl 0x0016A5 ; 00009F, 31.844
    dl 0x0016C2 ; 0000A0, 32.005
    dl 0x0016DF ; 0000A1, 32.166
    dl 0x0016FC ; 0000A2, 32.326
    dl 0x001719 ; 0000A3, 32.486
    dl 0x001736 ; 0000A4, 32.645
    dl 0x001753 ; 0000A5, 32.803
    dl 0x001770 ; 0000A6, 32.961
    dl 0x00178C ; 0000A7, 33.118
    dl 0x0017A9 ; 0000A8, 33.275
    dl 0x0017C5 ; 0000A9, 33.431
    dl 0x0017E2 ; 0000AA, 33.587
    dl 0x0017FE ; 0000AB, 33.742
    dl 0x00181A ; 0000AC, 33.896
    dl 0x001836 ; 0000AD, 34.050
    dl 0x001852 ; 0000AE, 34.203
    dl 0x00186E ; 0000AF, 34.356
    dl 0x00188A ; 0000B0, 34.509
    dl 0x0018A5 ; 0000B1, 34.660
    dl 0x0018C1 ; 0000B2, 34.811
    dl 0x0018DC ; 0000B3, 34.962
    dl 0x0018F7 ; 0000B4, 35.112
    dl 0x001913 ; 0000B5, 35.262
    dl 0x00192E ; 0000B6, 35.410
    dl 0x001949 ; 0000B7, 35.559
    dl 0x001964 ; 0000B8, 35.707
    dl 0x00197F ; 0000B9, 35.854
    dl 0x001999 ; 0000BA, 36.001
    dl 0x0019B4 ; 0000BB, 36.147
    dl 0x0019CE ; 0000BC, 36.293
    dl 0x0019E9 ; 0000BD, 36.438
    dl 0x001A03 ; 0000BE, 36.582
    dl 0x001A1D ; 0000BF, 36.726
    dl 0x001A37 ; 0000C0, 36.870
    dl 0x001A51 ; 0000C1, 37.013
    dl 0x001A6B ; 0000C2, 37.155
    dl 0x001A85 ; 0000C3, 37.297
    dl 0x001A9F ; 0000C4, 37.439
    dl 0x001AB9 ; 0000C5, 37.579
    dl 0x001AD2 ; 0000C6, 37.720
    dl 0x001AEC ; 0000C7, 37.859
    dl 0x001B05 ; 0000C8, 37.999
    dl 0x001B1E ; 0000C9, 38.137
    dl 0x001B37 ; 0000CA, 38.276
    dl 0x001B50 ; 0000CB, 38.413
    dl 0x001B69 ; 0000CC, 38.550
    dl 0x001B82 ; 0000CD, 38.687
    dl 0x001B9B ; 0000CE, 38.823
    dl 0x001BB4 ; 0000CF, 38.959
    dl 0x001BCC ; 0000D0, 39.094
    dl 0x001BE5 ; 0000D1, 39.228
    dl 0x001BFD ; 0000D2, 39.362
    dl 0x001C16 ; 0000D3, 39.496
    dl 0x001C2E ; 0000D4, 39.629
    dl 0x001C46 ; 0000D5, 39.762
    dl 0x001C5E ; 0000D6, 39.894
    dl 0x001C76 ; 0000D7, 40.025
    dl 0x001C8E ; 0000D8, 40.156
    dl 0x001CA5 ; 0000D9, 40.286
    dl 0x001CBD ; 0000DA, 40.416
    dl 0x001CD5 ; 0000DB, 40.546
    dl 0x001CEC ; 0000DC, 40.675
    dl 0x001D04 ; 0000DD, 40.803
    dl 0x001D1B ; 0000DE, 40.931
    dl 0x001D32 ; 0000DF, 41.059
    dl 0x001D49 ; 0000E0, 41.186
    dl 0x001D60 ; 0000E1, 41.312
    dl 0x001D77 ; 0000E2, 41.438
    dl 0x001D8E ; 0000E3, 41.564
    dl 0x001DA5 ; 0000E4, 41.689
    dl 0x001DBB ; 0000E5, 41.814
    dl 0x001DD2 ; 0000E6, 41.938
    dl 0x001DE9 ; 0000E7, 42.061
    dl 0x001DFF ; 0000E8, 42.184
    dl 0x001E15 ; 0000E9, 42.307
    dl 0x001E2C ; 0000EA, 42.429
    dl 0x001E42 ; 0000EB, 42.551
    dl 0x001E58 ; 0000EC, 42.672
    dl 0x001E6E ; 0000ED, 42.793
    dl 0x001E84 ; 0000EE, 42.913
    dl 0x001E99 ; 0000EF, 43.033
    dl 0x001EAF ; 0000F0, 43.152
    dl 0x001EC5 ; 0000F1, 43.271
    dl 0x001EDA ; 0000F2, 43.390
    dl 0x001EF0 ; 0000F3, 43.508
    dl 0x001F05 ; 0000F4, 43.625
    dl 0x001F1B ; 0000F5, 43.742
    dl 0x001F30 ; 0000F6, 43.859
    dl 0x001F45 ; 0000F7, 43.975
    dl 0x001F5A ; 0000F8, 44.091
    dl 0x001F6F ; 0000F9, 44.206
    dl 0x001F84 ; 0000FA, 44.321
    dl 0x001F99 ; 0000FB, 44.435
    dl 0x001FAD ; 0000FC, 44.549
    dl 0x001FC2 ; 0000FD, 44.662
    dl 0x001FD7 ; 0000FE, 44.775
    dl 0x001FEB ; 0000FF, 44.888
    dl 0x002000 ; 000100, 45.000 only needed for interpolation

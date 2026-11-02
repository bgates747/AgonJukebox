; AUD-001 coarse real-PCM octave-like analysis. No VDU, MOS or IRQ operations.
; 1024 unsigned samples in pb_window; ten low-to-high detail magnitudes in
; pb_result. Pair averages remain unsigned; absolute differences reject DC.
; Mean absolute detail, not RMS/FFT power. Two-tap filters overlap and alias.
; pb_start starts a job. pb_step performs <=32 pairs; pb_active=0 when done.
; Scratch AF/BC/DE/HL/IX/IY. Foreground owner keeps window immutable while busy.
pb_window: equ 0x094000
pb_result: equ 0x094400
pb_start:
    ld hl,pb_window
    ld (pb_read),hl
    ld (pb_write),hl
    ld hl,512
    ld (pb_left),hl
    ld (pb_pairs),hl
    ld hl,0
    ld (pb_sum),hl
    ld a,9
    ld (pb_level),a
    ld (pb_shift),a
    ld a,1
    ld (pb_active),a
    ret
pb_step:
    ld a,(pb_active)
    or a
    ret z
    ld hl,(pb_read)
    ld de,(pb_write)
    ld ix,(pb_left)
    ld iy,(pb_sum)
    ld a,ixh
    or a
    ld a,32
    jr nz,@budget
    ld a,ixl
    cp 32
    jr c,@budget
    ld a,32
@budget:
    ld (pb_budget),a
    ld bc,0
@pair:
    ld b,(hl)
    inc hl
    ld c,(hl)
    inc hl
    ld a,b
    add a,c
    rra
    ld (de),a
    inc de
    ld a,b
    sub c
    jr nc,@positive
    neg
@positive:
    ld c,a
    ld b,0
    add iy,bc
    dec ix
    ld a,(pb_budget)
    dec a
    ld (pb_budget),a
    jr nz,@pair
    ld (pb_read),hl
    ld (pb_write),de
    ld (pb_left),ix
    ld (pb_sum),iy
    ld a,ixh
    or ixl
    ret nz
    ld a,(pb_shift)
    or a
    jr z,@normalized
    ld b,a
@halve_sum:
    ld hl,pb_sum+2
    srl (hl)
    dec hl
    rr (hl)
    dec hl
    rr (hl)
    djnz @halve_sum
@normalized:
    ld a,(pb_level)
    ld hl,0
    ld l,a
    ld de,pb_result
    add hl,de
    ld a,(pb_sum)
    ld (hl),a
    ld a,(pb_level)
    or a
    jr z,@done
    dec a
    ld (pb_level),a
    ld (pb_shift),a
    ld hl,(pb_pairs)
    srl h
    rr l
    ld (pb_pairs),hl
    ld (pb_left),hl
    ld hl,pb_window
    ld (pb_read),hl
    ld (pb_write),hl
    ld hl,0
    ld (pb_sum),hl
    ret
@done:
    xor a
    ld (pb_active),a
    ret
pb_active: db 0
pb_level: db 0
pb_shift: db 0
pb_budget: db 0
pb_read: dl 0
pb_write: dl 0
pb_left: dl 0
pb_pairs: dl 0
pb_sum: dl 0

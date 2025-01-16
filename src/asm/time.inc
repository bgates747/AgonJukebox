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
    ld de,@bin2asc
    call u8_to_ascii ; answer in @bin2asc
    ld a,(@bin2asc+2)
    ld (hhmmss+6),a
    ld a,(@bin2asc+3)
    ld (hhmmss+7),a
    ld hl,hhmmss
    ret
@bin2asc: blkw 5,0 ; scratch space for binary to ascii decimal conversion
hhmmss: asciz "00:00:00" ; buffer for output string
; end seconds_to_hhmmss
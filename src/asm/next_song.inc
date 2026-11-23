; Select the next WAV in listing order, crossing pages and wrapping at the end.
; Z: no WAV, leave selection unchanged. NZ: selected page/row/count updated.
bf_select_next_song:
    ld hl,(bf_dir_num_files)
    SIGN_UHL
    ret z
    ld (bf_next_remaining),hl
    ld hl,(bf_page_cur)
    ld de,bf_files_per_pg
    call umul24
    ld de,0
    ld a,(bf_file_idx)
    ld e,a
    add hl,de
@scan:
    inc hl
    push hl
    ld de,(bf_dir_num_files)
    or a
    sbc hl,de
    pop hl
    jr c,@in_range
    ld hl,0
@in_range:
    push hl
    push hl
    pop de
    add hl,hl
    add hl,de
    ld de,bf_filinfo_ptrs
    add hl,de
    push hl
    pop ix
    ld iy,(ix)
    pop hl
    bit AM_DIR,(iy+filinfo_fattrib)
    jr z,@selected
    ld de,(bf_next_remaining)
    dec de
    ld (bf_next_remaining),de
    ex de,hl
    SIGN_UHL
    ex de,hl
    jr nz,@scan
    ret ; Z, no playable files
@selected:
    ld de,bf_files_per_pg
    call udiv24
    ld (bf_page_cur),de
    ld a,l
    ld (bf_file_idx),a
    call bf_get_page_num_files
    or a,1
    ret
bf_next_remaining: dl 0

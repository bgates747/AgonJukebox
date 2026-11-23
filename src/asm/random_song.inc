; Select a WAV across the entire open listing, not just its visible page.
; Z: no playable files, selection unchanged. NZ: page/row and page count updated.
; The listing already contains only directories and validated WAV files.
bf_select_random_song:
    ld hl,(bf_page_cur)
    ld de,bf_files_per_pg
    call umul24
    ld de,0
    ld a,(bf_file_idx)
    ld e,a
    add hl,de
    ld (bf_random_previous),hl
    xor a
    ld (bf_random_skip_previous),a
    ld ix,bf_filinfo_ptrs
    ld bc,(bf_dir_num_files)
    ld hl,0
@count:
    push hl
    ld hl,0
    add hl,bc
    SIGN_UHL
    pop hl
    jr z,@counted
    ld iy,(ix)
    bit AM_DIR,(iy+filinfo_fattrib)
    jr nz,@count_next
    inc hl
@count_next:
    lea ix,ix+3
    dec bc
    jr @count
@counted:
    SIGN_UHL
    ret z
    ; With one song, allow selecting it again. Otherwise omit the selected WAV.
    dec hl
    SIGN_UHL
    jr z,@include_previous
    push hl
    call bf_get_filinfo_from_pg_idx
    bit AM_DIR,(iy+filinfo_fattrib)
    pop hl
    jr nz,@include_previous
    ld a,1
    ld (bf_random_skip_previous),a
    jr @pick
@include_previous:
    inc hl
@pick:
    push hl
    call prng24
    pop de
    call udiv24 ; HL = random rank among eligible songs
    ld (bf_random_rank),hl
    ld ix,bf_filinfo_ptrs
    ld hl,0 ; absolute listing index
@scan:
    ld iy,(ix)
    bit AM_DIR,(iy+filinfo_fattrib)
    jr nz,@next
    ld a,(bf_random_skip_previous)
    or a
    jr z,@eligible
    push hl
    ld de,(bf_random_previous)
    or a
    sbc hl,de
    pop hl
    jr z,@next
@eligible:
    ld de,(bf_random_rank)
    ex de,hl
    SIGN_UHL
    ex de,hl
    jr z,@selected
    dec de
    ld (bf_random_rank),de
@next:
    inc hl
    lea ix,ix+3
    jr @scan
@selected:
    ld de,bf_files_per_pg
    call udiv24 ; DE = page, HL = row
    ld (bf_page_cur),de
    ld a,l
    ld (bf_file_idx),a
    call bf_get_page_num_files
    or a,1
    ret
bf_random_previous: dl 0
bf_random_rank: dl 0
bf_random_skip_previous: db 0

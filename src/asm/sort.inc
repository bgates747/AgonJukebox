; Determines the ascending lexical order of two zero-terminated strings
; Inputs: HL, DE = pointers to strings
; Returns: 
;   - HL points to the lexically smaller string, DE to the larger (swapped if HL > DE).
; Flags: 
;   - Z set,   C reset: Strings are equal.
;   - Z reset, C reset: DE is lexically larger than HL.
;   - Z reset, C set: DE is lexically smaller than HL.
; Destroys: A
; Notes: 
;   - Comparisons are based on ASCII values: punctuation/numbers < uppercase < lowercase.
alpha_asc:
    push hl
    push de
@loop:
    ld a,(de)
    cp a,(hl)
    jr nz,@done
    inc de
    inc hl
    or a,a
    jr nz,@loop
@done:
    pop de
    pop hl
    ret nc
    ex de,hl
    ret
; end alpha_asc

; Sorts a list of pointers to zero-terminated strings in ascending lexical order
; using the selection sort algorithm, which is in-place and stable.
; Inputs:
;   - IY: Pointer to the list of string pointers.
;   - B: Number of items in the list (max 255).
; Outputs:
;   - Sorted list of pointers in ascending lexical order.
; Destroys:
;   - A, BC, DE, HL, IX.
; Notes:
;   - Strings are compared using an unsigned comparison (ASCII-based).
;   - The algorithm assumes all strings are properly null-terminated.
;   - The sorting is performed in-place by swapping pointers in the list.
selection_sort_asc:
    and a,b                  ; Check if B is zero
    ret z                    ; No need to sort an empty list
    dec b                    ; We only need to do n-1 loops
    ret z                    ; No need to sort a single item
    push iy                  ; Save pointer to the list of pointers
@outer_loop:
    lea ix,iy+3              ; IX = pointer to the next string in the list
    push bc                  ; Save the outer loop counter
@inner_loop:
    push bc                  ; Save the inner loop counter
    ld hl,(iy)               ; HL = address of the current string
    ld de,(ix)               ; DE = address of the next string to compare
    call alpha_asc           ; Compare (HL) and (DE)
    jr nc,@skip_swap         ; If (HL) <= (DE), skip swapping the strings
    ld (iy),hl               ; alpha_asc already did the swap ...
    ld (ix),de               ; ... so we just load as is
@skip_swap:
    lea ix,ix+3              ; Move to the next pointer
    pop bc                   ; Restore the inner loop counter
    djnz @inner_loop         ; Continue the inner loop
    lea iy,iy+3              ; Move to the next pointer in the list
    pop bc                   ; Restore the outer loop counter
    djnz @outer_loop         ; Continue the outer loop
    pop iy                   ; Restore pointer to the list of pointers
    ret
; end selection_sort_asc

; same as selection_sort_asc, but for sorting fileinfo structs by filename
selection_sort_asc_filinfo:
    and a,b                  ; Check if B is zero
    ret z                    ; No need to sort an empty list
    dec b                    ; We only need to do n-1 loops
    ret z                    ; No need to sort a single item
    push iy                  ; Save pointer to the list of pointers
@outer_loop:
    lea ix,iy+3              ; IX = pointer to the next string in the list
    push bc                  ; Save the outer loop counter
@inner_loop:
    push bc                  ; Save the inner loop counter
    ld hl,(iy)               ; HL = address of the current string
    ld de,filinfo_fname      ; offset to the filename in the FILINFO struct
    add hl,de                ; HL = address of the filename
    push hl                  ; Save the address of the filename
    ld hl,(ix)               ; HL = address of the next string to compare
    add hl,de                ; HL = address of the filename (DE already has the offset) 
    ex de,hl                 ; DE = address of the filename
    pop hl                   ; HL = address of the current filename
    call alpha_asc           ; Compare (HL) and (DE)
    jr nc,@skip_swap         ; If (HL) <= (DE), skip swapping the strings
    ld bc,-filinfo_fname     ; -offset to the filename in the FILINFO struct
    add hl,bc                ; HL = address of the FILINFO struct
    ld (iy),hl
    ex de,hl                 ; HL = address of the filename
    add hl,bc                ; HL = address of the FILINFO struct
    ld (ix),hl
@skip_swap:
    lea ix,ix+3              ; Move to the next pointer
    pop bc                   ; Restore the inner loop counter
    djnz @inner_loop         ; Continue the inner loop
    lea iy,iy+3              ; Move to the next pointer in the list
    pop bc                   ; Restore the outer loop counter
    djnz @outer_loop         ; Continue the outer loop
    pop iy                   ; Restore pointer to the list of pointers
    ret
; end selection_sort_asc_filinfo

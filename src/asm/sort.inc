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
;
; Inputs:
;   - IY: Pointer to the list of string pointers.
;   - B: Number of items in the list (0 = 256).
;
; Outputs:
;   - Sorted list of pointers in ascending lexical order.
;
; Destroys:
;   - A, BC, DE, HL, IX.
;
; Notes:
;   - Strings are compared using an unsigned comparison (ASCII-based).
;   - The algorithm assumes all strings are properly null-terminated.
;   - The sorting is performed in-place by swapping pointers in the list.
selection_sort_asc:
    push iy                  ; Save pointer to the list of pointers
    dec b                    ; We only need to do n-1 loops
@outer_loop:
    lea ix,iy+3              ; IX = pointer to the next string in the list
    push bc                  ; Save the outer loop counter
@inner_loop:
    push bc                  ; Save the inner loop counter
    ld hl,(iy)               ; HL = address of the current string
    ld de,(ix)               ; DE = address of the next string to compare
    call alpha_asc           ; Compare HL and DE
    jr nc,@skip_swap         ; If HL <= DE, skip swapping the strings
    ld (iy),hl
    ld (ix),de
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

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

alpha_asc_print:
    call alpha_asc
    call DEBUG_PRINT
    push de
    call printString
    call printNewLine
    pop hl
    call printString
    call printNewLine
    call printNewLine
    ret
; end alpha_asc_print

selection_sort_asc:
    push iy                  ; Save pointer to the list of pointers
    ld a,b                   ; Load the number of items in the list
    dec a                    ; Outer loop runs for (b - 1) iterations
    ld b,a                   ; Update B for the outer loop counter
@outer_loop:
    lea ix,iy+3              ; IX = pointer to the next element in the list
    ld (@current_min),iy     ; Assume the first element is the minimum
    push bc                  ; Save the outer loop counter
    ld c,b                   ; Inner loop runs for remaining items
@inner_loop:
    push bc                  ; Save the inner loop counter
    ld hl,(iy)               ; HL = address of the current minimum string
    ld de,(ix)               ; DE = address of the next string to compare
    call alpha_asc           ; Compare HL and DE
    jr nc,@skip_update        ; If HL <= DE, skip updating the minimum pointer
    ld (@current_min),ix     ; Update the pointer to the current minimum
@skip_update:
    lea ix,ix+3              ; Move to the next pointer
    pop bc                   ; Restore the inner loop counter
    djnz @inner_loop         ; Continue the inner loop

    ; Swap pointers in the list
    ld ix,(@current_min)     ; IX = pointer to the current minimum
    ld hl,(ix)               ; HL = address of the minimum string
    ld de,(iy)               ; DE = address of the current string
    ld (iy),hl               ; Store the minimum string's address at the current position
    ld (ix),de               ; Store the current string's address at the minimum position

    lea iy,iy+3              ; Move to the next pointer in the list
    pop bc                   ; Restore the outer loop counter
    djnz @outer_loop         ; Continue the outer loop

    pop iy                   ; Restore pointer to the list of pointers
    ret

@current_min: dl 0           ; Pointer to the current minimum string
; end selection_sort_asc


; Determines the ascending lexical order of two zero-terminated strings
; Inputs: HL, DE = pointers to strings; B = max characters to compare (0-255, 0 = 256)
; Returns: 
;   - HL points to the lexically smaller string, DE to the larger (swapped if HL > DE).
; Flags: 
;   - Z set,   S pos: Strings are equal.
;   - Z reset, S pos: DE is lexically larger than HL.
;   - Z reset, S neg: DE is lexically smaller than HL.
; Destroys: A, B
; Notes: 
;   - Comparisons are based on ASCII values: punctuation/numbers < uppercase < lowercase.
alpha_asc:
    push hl
    push de
@loop:
    ld a,(de)
    cp (hl)
    jr nz,@done
    or a
    jr z,@done
    inc de
    inc hl
    djnz @loop
@done:
    pop de
    pop hl
    ret p
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

; sort a list of pointers to zero-terminated strings in ascending lexical order
; uses the selection sort algorithm, which is in-place and stable
; inputs: iy = pointer to list of pointers; 
;         c = max number of chars to search (0 = 256);
;         b = number of items in the list (0 = 256)
; outputs: sorted list of pointers
; destroys: everything except iy, which will be pointed at the top of the sorted list
selection_sort_asc:
    push iy ; save pointer to list of pointers
@outer_loop:
    lea ix,iy+3
    ld (@current_min),iy ; assume first element is minimum
    ld a,c ; a = max number of chars to search
    push bc ; save outer loop counter
@inner_loop:
    push bc ; save inner loop counter
    ld hl,(@current_min) ; hl points to the current minimum string
    ld de,(ix) ; de points to the next string to compare
    call alpha_asc ; hl points to the lexically smaller string
    ld (@current_min),hl ; update the current minimum string

    lea ix,ix+3 ; move to the next string
    pop bc ; restore inner loop counter
    ld a,c ; a = max number of chars to search
    djnz @inner_loop

    ld hl,(@current_min) ; hl points to the current minimum string
    ld de,(iy) ; de points to the first string in the list
    call alpha_asc ; hl points to the lexically smaller string, de the larger
    ld (iy),hl ; lexically smaller string is moved to the front of the list
    ld (ix),de ; lexically larger string is moved to the current position

    lea iy,iy+3 ; move to the next string
    pop bc ; restore outer loop counter
    djnz @outer_loop

    pop iy ; restore pointer to list of pointers
    ret
@current_min: dl 0 ; pointer to the current minimum string
; end selection_sort_asc
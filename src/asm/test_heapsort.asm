    assume adl=0
    org 0x0000 
    jp start 
    align 64 
    db "MOS" 
    db 00h 
    db 01h 

start: 
    push af
    push bc
    push de
    push ix
    push iy

    call init
    call main

exit:
    pop iy
    pop ix
    pop de
    pop bc
    pop af
    ld hl,0

    ret

    include "../heapsort/heapsortb.inc"

; --- MAIN PROGRAM FILE ---
init:

    ret
; end init
main:
; ===============================================================================
;  5.1. Demonstrating `HeapSortB'
; -------------------------------------------------------------------------------
; Sort an array of 10 unsigned byte values in ascending order

        ld      hl, array       ; Load pointer to array
        ld      bc, 10          ; Load array dimension
        ld      ix, bytecmp_cb  ; Load pointer to callback
        call    HeapSortB       ; Invoke

    ret ; back to MOS
; end main

bytecmp_cb:                     ; Callback function
        ld      a, (de)         ; Load one element
        cp      (hl)            ; Compare to other element
        ret                     ; End
array:  .db     89, 74, 62, 124, 40, 230, 145, 73, 172, 208
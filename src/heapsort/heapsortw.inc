HeapSortW:
; ### HEAPSORTW ###############################################################
; HL = Address of array start
; BC = Size of array (in elements)
; IX = Address of callback:
;   HL -> first
;   DE -> second
;   Returns CF = 1 if (HL) precedes (DE), CF = 0 if (HL) follows (DE)
;   Can destroy A, DE, HL; must preserve BC, IX

    dec     hl
    dec     hl

; ### Build heap ##############################################################
    push    bc

    ld      bc, 1
@buildHeapLoopStart:
    push    bc

@buildHeapInnerLoopStart:
    push    hl
    sra     b
    rr      c
    jr      z, @buildHeapEnd

    ld      d, h
    ld      e, l
    ld      hl, 0
    adc     hl, bc
    add     hl, bc
    add     hl, hl
    add     hl, de
    ex      de, hl

    add     hl, bc
    add     hl, bc

    push    hl
    push    de
    call    call_ix
    pop     de
    pop     hl
    jr      c, @swapHeapElements

    ld      a, (de)
    push    af
    ld      a, (hl)
    ld      (de), a
    pop     af
    ld      (hl), a
    inc     hl
    inc     de
    ld      a, (de)
    push    af
    ld      a, (hl)
    ld      (de), a
    pop     af
    ld      (hl), a

    dec     de
    pop     hl

    jr      @buildHeapInnerLoopStart
@swapHeapElements:
    pop     hl

    pop     bc
    inc     bc
    ex      (sp), hl
    ld      a, b
    cp      h
    jr      nz, @buildHeapLoopContinue
    ld      a, c
    cp      l
@buildHeapLoopContinue:
    ex      (sp), hl
    jr      c, @buildHeapLoopStart
@buildHeapEnd:
    pop     bc

; ### Sort ####################################################################
    ld      d, h
    ld      e, l
    add     hl, bc
    add     hl, bc
    ld      b, h
    ld      c, l
    ld      h, d
    ld      l, e

@sortOuterLoopStart:
    inc     hl
    inc     hl
    ld      a, h
    cp      b
    jr      nz, @sortOuterLoopEnd
    ld      a, l
    cp      c
@sortOuterLoopEnd:
    jr      nc, @sortComplete
    dec     hl
    dec     hl

    ld      d, h
    ld      e, l
    inc     de
    inc     de

    ld      a, (bc)
    push    af
    ld      a, (de)
    ld      (bc), a
    pop     af
    ld      (de), a
    inc     de
    inc     bc
    ld      a, (bc)
    push    af
    ld      a, (de)
    ld      (bc), a
    pop     af
    ld      (de), a
    dec     de
    dec     bc
    dec     bc
    dec     bc

@sortInnerLoopStart:
    push    hl
    xor     a
    sub     l
    ld      l, a
    ld      a, 0
    sbc     a, h
    ld      h, a
    add     hl, de
    add     hl, de

    ld      a, h
    cp      b
    jr      nz, @sortInnerLoopEnd
    ld      a, l
    cp      c
@sortInnerLoopEnd:
    jr      z, @skipSortInnerCheck
    jr      nc, @sortInnerLoopComplete

    push    de
    ld      d, h
    ld      e, l
    inc     hl
    inc     hl
    push    hl
    call    call_ix
    pop     hl
    pop     de
    jr      c, @swapSortElements
    dec     hl
    dec     hl

@swapSortElements:
    push    hl
    push    de
    call    call_ix
    pop     de
    pop     hl
    jr      nc, @sortInnerLoopComplete

    ld      a, (hl)
    push    af
    ld      a, (de)
    ld      (hl), a
    pop     af
    ld      (de), a
    inc     hl
    inc     de
    ld      a, (hl)
    push    af
    ld      a, (de)
    ld      (hl), a
    pop     af
    ld      (de), a
    dec     hl

    ld      d, h
    ld      e, l

    pop     hl
    jp      @sortInnerLoopStart

@sortInnerLoopComplete:
    pop     hl
    jp      @sortOuterLoopStart

@skipSortInnerCheck:
    ret

@sortComplete:
    ret

@call_ix: jp (ix)
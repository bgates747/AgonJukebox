;Copyright (c) 2006, Sean McLaughlin. All rights reserved.
;Redistribution and use in source and binary forms, with or without modification, are
;permitted provided that the following conditions are met:
;
;Redistributions of source code must retain the above copyright notice, this list of
;conditions and the following disclaimer.
;
;Redistributions in binary form must reproduce the above copyright notice, this list of
;conditions and the following disclaimer in the documentation and/or other materials
;provided with the distribution.
;
;THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
;"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
;TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
;PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE REGENTS OR
;CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
;EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
;ROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
;PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
;OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
;NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
;SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

HeapSortB:
; ### HEAPSORTB ################################################################
; HL = Address of array start
; BC = Size of array
; IX = Address of callback:
;   HL -> first
;   DE -> second
;   Returns CF = 1 if (HL) precedes (DE), CF = 0 if (HL) follows (DE)
;   Can destroy A, DE, HL, IY, must preserve BC, IX

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
    adc     hl, bc
    add     hl, bc
    ex      de, hl

    add     hl, bc

    push    hl
    push    de
    call    @call_ix
    pop     de
    pop     hl
    jr      c, @swapHeapElements

    ld      a, (de)
    push    af
    ld      a, (hl)
    ld      (de), a
    pop     af
    ld      (hl), a
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
    ld      b, h
    ld      c, l
    ld      h, d
    ld      l, e

@sortOuterLoopStart:
    inc     hl
    ld      a, h
    cp      b
    jr      nz, @sortOuterLoopEnd
    ld      a, l
    cp      c
@sortOuterLoopEnd:
    jr      nc, @sortComplete
    dec     hl

    ld      d, h
    ld      e, l
    inc     de

    ld      a, (bc)
    push    af
    ld      a, (de)
    ld      (bc), a
    pop     af
    ld      (de), a

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
    push    hl
    call    @call_ix
    pop     hl
    pop     de
    jr      c, @swapSortElements
    dec     hl

@swapSortElements:
    push    hl
    push    de
    call    @call_ix
    pop     de
    pop     hl
    jr      nc, @sortInnerLoopComplete

    ld      a, (hl)
    push    af
    ld      a, (de)
    ld      (hl), a
    pop     af
    ld      (de), a

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
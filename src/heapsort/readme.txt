###############################################################################
                            HeapSort for the Z80 CPU
###############################################################################

 0.  Table of Contents
===============================================================================
 1.  Overview
 2.  Manifest
 3.  Using
 4.  Notes
 5.  Sample Usage
 6.  Contact Information
 7.  Licensing

 1.  Overview
===============================================================================
HeapSort is just about the fastest algorithm there is for sorting arrays. The
time complexity for HeapSort is O(n lg n)--where `lg' is the base-2 logarithm
function--in the average and worst cases (i.e. when sorting an array that is
random and an array that is already in order respectively). Compare this to
QuickSort and TreeSort, which are O(n lg n) in the best case, but degenerate to
O(n^2) when the array is nearly sorted. MergeSort also exhibits O(n lg n) in
all cases, however it is a recursive algorithm, where HeapSort is iterative.
This results in HeapSort's lower-order complexity terms being lower, as well as
not having a stack overflow consideration.

This package contains an implementation of the HeapSort algorithm for the Z80
CPU.

 2.  Manifest
===============================================================================
 *  history.txt     Release history.
 *  readme.txt      Usage information.
 *  heapsort.z80    HeapSort implementation.

 3.  Using
===============================================================================
There are two procedures defined in the file `heapsort.z80': `HeapSortB' is an
implementation of the HeapSort algorithm that operates on an array of elements
that are one byte in size. `HeapSortW' is an implementation that operates on
an array of elements that are each two bytes in size.

Both procedures have a common interface:

Registers on entry:
    HL        Address of the start of the array.
    BC        Array dimension, given in elements.
    IX        Address of a callback function to determine sorting order:

              Registers on entry:
                  HL        Pointer to element 1.
                  DE        Pointer to element 2.

              Registers on exit:
                  A, DE, HL, and the alternate registers may be destroyed.
                  BC, IX, and SP must be preserved.

              Flags on exit:
                  CF        Set if element 1 precedes element 2, clear if
                            element 1 follows element 2.

Registers on exit:
    AF, BC, DE, and HL are destroyed.

 4. Notes
===============================================================================
 *  `HeapSortW' is particularly useful for sorting arrays of pointers. This
    lets you sort arrays where the elements are large, or especially variable,
    in size.

 *  The routine only cares about the carry flag when invoking the callback;
    detecting equality between elements is not necessary. Thus, you may test
    esoteric relationships between elements, and use SCF/CCF to note the
    result.

 5. Sample Usage
===============================================================================
 5.1. Demonstrating `HeapSortB'
-------------------------------------------------------------------------------
; Sort an array of 10 unsigned byte values in ascending order

        ld      hl, array       ; Load pointer to array
        ld      bc, 10          ; Load array dimension
        ld      ix, bytecmp_cb  ; Load pointer to callback
        call    HeapSortB       ; Invoke
        ...
bytecmp_cb:                     ; Callback function
        ld      a, (de)         ; Load one element
        cp      (hl)            ; Compare to other element
        ret                     ; End
        ...
array:  .db     89, 74, 62, 124, 40, 230, 145, 73, 172, 208

 5.2. Demonstrating `HeapSortW'
-------------------------------------------------------------------------------
; Sort an array of pointers to unsigned 32-bit values in descending order

        ld      hl, array       ; Load pointer to array
        ld      bc, 6           ; Load array dimension
        ld      ix, pdwcmp_cb   ; Load pointer to callback
        call    HeapSortW       ; Invoke
        ...
pdwcmp_cb:                      ; Callback function
        push    bc              ; Preserve BC
        ld      bc, 3

        ld      a, (hl)         ; Load effective address of first element
        inc     hl
        ld      h, (hl)
        ld      l, a
        add     hl, bc          ; Offset to MSB of value

        ex      de, hl          ; Load effective address of second element
        ld      a, (hl)
        inc     hl
        ld      h, (hl)
        ld      l, a
        add     hl, bc          ; Offset to MSB of value

loop:   ld      b, 4            ; Compare four bytes
        ld      a, (de)
        cp      (hl)
        dec     hl
        dec     de
        jr      nz, break
        djnz    loop

break:  pop     bc              ; Restore BC
        ret                     ; End
        ...
array:  .dw     val_1, val_2, val_3, val_4, val_5, val_6
val1:   .db     $0A, $5B, $AC, $52      ; = $52AC5B0A
val2:   .db     $46, $AB, $E1, $77      ; = $77E1AB46
val3:   .db     $C0, $B2, $A3, $EF      ; = $EFA3B2C0
val4:   .db     $5A, $23, $E5, $B1      ; = $B1E5235A
val5:   .db     $BC, $46, $DB, $F1      ; = $F1DB46BC
val6:   .db     $D7, $9F, $0D, $E8      ; = $E80D9FD7

 6. Contact Information
===============================================================================
E-mail: sigma <UNDERSCORE> zk <AT> yahoo <DOT> com

 7. Licensing
===============================================================================
Copyright (c) 2006, Sean McLaughlin. All rights reserved.
Redistribution and use in source and binary forms, with or without modification, are
permitted provided that the following conditions are met:

Redistributions of source code must retain the above copyright notice, this list of
conditions and the following disclaimer.

Redistributions in binary form must reproduce the above copyright notice, this list of
conditions and the following disclaimer in the documentation and/or other materials
provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE REGENTS OR
CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
ROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.


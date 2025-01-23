    assume adl=1 
    org 0x040000 
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

; API INCLUDES
    include "mos_api.inc"
    include "macros.inc"
    include "functions.inc"
    include "arith24.inc"
    include "maths.inc"
    include "font.inc"
    include "fixed168.inc"
    include "time.inc"
    include "timer.inc"
    include "vdu.inc"
    include "vdu_buffered_api.inc"
    include "vdu_fonts.inc"
    include "vdu_plot.inc"
    include "vdu_sound.inc"

; APPLICATION INCLUDES
    include "layout.inc"
    ; include "ascii.inc"
    include "browse.inc"
    include "input.inc"
    include "logo.inc"
    include "play.inc"
    include "sort.inc"
    include "timer_jukebox.inc"
    include "wav.inc"
    include "debug.inc"

; --- MAIN PROGRAM FILE ---
init:
    ; ld a,18 ;    1024  768   2     60hz
    ; call vdu_set_screen_mode
    ret
; end init

; str0: asciz "AB"
;     blkb 256,0xff
; str1: asciz "ABC"
;     blkb 256,0xff
; str2: asciz "ab"
;     blkb 256,0xff
; str3: asciz "abc"
;     blkb 256,0xff
; str4: asciz "XY"
;     blkb 256,0xff
; str5: asciz "XYZ"
;     blkb 256,0xff

main:
    ld iy,song_list
    ld b,160 ; number of songs to sort (0 = 256)
    push bc  ; save number of songs to sort

    call selection_sort_asc
    
    pop bc ; restore number of songs to sort
    ld iy,song_list
@loop:
    push bc
    ld hl,(iy)
    call printHex24
    ld a,':'
    rst.lil 10h
    call printString
    call printNewLine
    lea iy,iy+3
    pop bc
    ld a,b
    dec a
    and a,%00011111 ; mod 32
    jp nz,@F
    PUSH_ALL
    call DEBUG_WAITKEYPRESS
    CALL vdu_cls
    POP_ALL

@@:
    djnz @loop

    ret ; back to MOS
; end main
    align 2048

    incbin "song_list.dat"


song_list:
    dl 0x046000
    dl 0x046100
    dl 0x046200
    dl 0x046300
    dl 0x046400
    dl 0x046500
    dl 0x046600
    dl 0x046700
    dl 0x046800
    dl 0x046900
    dl 0x046A00
    dl 0x046B00
    dl 0x046C00
    dl 0x046D00
    dl 0x046E00
    dl 0x046F00
    dl 0x047000
    dl 0x047100
    dl 0x047200
    dl 0x047300
    dl 0x047400
    dl 0x047500
    dl 0x047600
    dl 0x047700
    dl 0x047800
    dl 0x047900
    dl 0x047A00
    dl 0x047B00
    dl 0x047C00
    dl 0x047D00
    dl 0x047E00
    dl 0x047F00
    dl 0x048000
    dl 0x048100
    dl 0x048200
    dl 0x048300
    dl 0x048400
    dl 0x048500
    dl 0x048600
    dl 0x048700
    dl 0x048800
    dl 0x048900
    dl 0x048A00
    dl 0x048B00
    dl 0x048C00
    dl 0x048D00
    dl 0x048E00
    dl 0x048F00
    dl 0x049000
    dl 0x049100
    dl 0x049200
    dl 0x049300
    dl 0x049400
    dl 0x049500
    dl 0x049600
    dl 0x049700
    dl 0x049800
    dl 0x049900
    dl 0x049A00
    dl 0x049B00
    dl 0x049C00
    dl 0x049D00
    dl 0x049E00
    dl 0x049F00
    dl 0x04A000
    dl 0x04A100
    dl 0x04A200
    dl 0x04A300
    dl 0x04A400
    dl 0x04A500
    dl 0x04A600
    dl 0x04A700
    dl 0x04A800
    dl 0x04A900
    dl 0x04AA00
    dl 0x04AB00
    dl 0x04AC00
    dl 0x04AD00
    dl 0x04AE00
    dl 0x04AF00
    dl 0x04B000
    dl 0x04B100
    dl 0x04B200
    dl 0x04B300
    dl 0x04B400
    dl 0x04B500
    dl 0x04B600
    dl 0x04B700
    dl 0x04B800
    dl 0x04B900
    dl 0x04BA00
    dl 0x04BB00
    dl 0x04BC00
    dl 0x04BD00
    dl 0x04BE00
    dl 0x04BF00
    dl 0x04C000
    dl 0x04C100
    dl 0x04C200
    dl 0x04C300
    dl 0x04C400
    dl 0x04C500
    dl 0x04C600
    dl 0x04C700
    dl 0x04C800
    dl 0x04C900
    dl 0x04CA00
    dl 0x04CB00
    dl 0x04CC00
    dl 0x04CD00
    dl 0x04CE00
    dl 0x04CF00
    dl 0x04D000
    dl 0x04D100
    dl 0x04D200
    dl 0x04D300
    dl 0x04D400
    dl 0x04D500
    dl 0x04D600
    dl 0x04D700
    dl 0x04D800
    dl 0x04D900
    dl 0x04DA00
    dl 0x04DB00
    dl 0x04DC00
    dl 0x04DD00
    dl 0x04DE00
    dl 0x04DF00
    dl 0x04E000
    dl 0x04E100
    dl 0x04E200
    dl 0x04E300
    dl 0x04E400
    dl 0x04E500
    dl 0x04E600
    dl 0x04E700
    dl 0x04E800
    dl 0x04E900
    dl 0x04EA00
    dl 0x04EB00
    dl 0x04EC00
    dl 0x04ED00
    dl 0x04EE00
    dl 0x04EF00
    dl 0x04F000
    dl 0x04F100
    dl 0x04F200
    dl 0x04F300
    dl 0x04F400
    dl 0x04F500
    dl 0x04F600
    dl 0x04F700
    dl 0x04F800
    dl 0x04F900
    dl 0x04FA00
    dl 0x04FB00
    dl 0x04FC00
    dl 0x04FD00
    dl 0x04FE00
    dl 0x04FF00
    dl 0x050000
    dl 0x050100
    dl 0x050200
    dl 0x050300
    dl 0x050400
    dl 0x050500
    dl 0x050600
    dl 0x050700
    dl 0x050800
    dl 0x050900
    dl 0x050A00
    dl 0x050B00
    dl 0x050C00
    dl 0x050D00
    dl 0x050E00
    dl 0x050F00
    dl 0x051000
    dl 0x051100
    dl 0x051200
    dl 0x051300
    dl 0x051400
    dl 0x051500
    dl 0x051600
    dl 0x051700
    dl 0x051800
    dl 0x051900
    dl 0x051A00
    dl 0x051B00
    dl 0x051C00
    dl 0x051D00
    dl 0x051E00
    dl 0x051F00
    dl 0x052000
    dl 0x052100
    dl 0x052200
    dl 0x052300
    dl 0x052400
    dl 0x052500
    dl 0x052600
    dl 0x052700
    dl 0x052800
    dl 0x052900
    dl 0x052A00
    dl 0x052B00
    dl 0x052C00
    dl 0x052D00
    dl 0x052E00
    dl 0x052F00
    dl 0x053000
    dl 0x053100
    dl 0x053200
    dl 0x053300
    dl 0x053400
    dl 0x053500
    dl 0x053600
    dl 0x053700
    dl 0x053800
    dl 0x053900
    dl 0x053A00
    dl 0x053B00
    dl 0x053C00
    dl 0x053D00
    dl 0x053E00
    dl 0x053F00
    dl 0x054000
    dl 0x054100
    dl 0x054200
    dl 0x054300
    dl 0x054400
    dl 0x054500
    dl 0x054600
    dl 0x054700
    dl 0x054800
    dl 0x054900
    dl 0x054A00
    dl 0x054B00
    dl 0x054C00
    dl 0x054D00
    dl 0x054E00
    dl 0x054F00
    dl 0x055000
    dl 0x055100
    dl 0x055200
    dl 0x055300
    dl 0x055400
    dl 0x055500
    dl 0x055600
    dl 0x055700
    dl 0x055800
    dl 0x055900
    dl 0x055A00
    dl 0x055B00
    dl 0x055C00
    dl 0x055D00
    dl 0x055E00
    dl 0x055F00

; must be final include in program so file data does not stomp on program code or other data
    include "files.inc"
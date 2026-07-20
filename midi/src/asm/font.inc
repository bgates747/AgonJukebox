Lat2_VGA8_8x8: equ 64016
font_data:
    ; incbin "../assets/fonts/Lat2-VGA8_8x8.font"
    include "../fonts/Lat2-VGA8_8x8.font.inc"
    ; incbin "../fonts/Lat2-VGA8_8x8.font"
font_data_end:
font_load:
; load font into a buffer
    ld hl,Lat2_VGA8_8x8
    ld de,font_data
    ld bc,font_data_end-font_data
    call vdu_load_buffer
; create font from buffer
    ld hl,Lat2_VGA8_8x8
    ld e,8
    ld d,8
    ld a,0 ; flags
    call vdu_font_create
; all done
    ret
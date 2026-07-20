; select font
; inputs: hl = bufferId, a = font flags
; Flags:
; Bit	Description
; 0	Adjust cursor position to ensure text baseline is aligned
;   0: Do not adjust cursor position (best for changing font on a new line)
;   1: Adjust cursor position (best for changing font in the middle of a line)
; 1-7	Reserved for future use
; VDU 23, 0, &95, 0, bufferId; flags: Select font
vdu_font_select:
    ld (@bufferId),hl
    ld (@flags),a
    ld hl,@cmd
    ld bc,@end-@cmd
    rst.lil $18
    ret
@cmd: db 23, 0, 0x95, 0
@bufferId: dw 0x0000
@flags: db 0x00
@end:

; create font from buffer
; inputs: hl = bufferId, e = width, d = height, d = ascent, a = flags
; VDU 23, 0, &95, 1, bufferId; width, height, ascent, flags: Create font from buffer
vdu_font_create:
    ld (@bufferId),hl
    ld (@width),de ; also loads height
    ld (@flags),a
    ld a,d ; height
    ld (@ascent),a ; ascent = height
; consolidate buffer
    call vdu_consolidate_buffer
; create font
    ld hl,@cmd
    ld bc,@end-@cmd
    rst.lil $18
    ret
@cmd: db 23, 0, 0x95, 1
@bufferId: dw 0x0000
@width: db 0x00
@height: db 0x00
@ascent: db 0x00
@flags: db 0x00
@end:

; set or adjust font property
; inputs: hl = bufferId, a = field, de = value
; VDU 23, 0, &95, 2, bufferId; field, value;: Set or adjust font property
vdu_font_property:
    ld (@bufferId),hl
    ld (@field),a
    ld (@value),de
    ld hl,@cmd
    ld bc,@end-@cmd
    rst.lil $18
    ret
@cmd: db 23, 0, 0x95, 2
@bufferId: dw 0x0000
@field: db 0x00
@value: dw 0x0000
@end: db 0x00 ; padding

; VDU 23, 0, &95, 3, bufferId; [<args>]: Reserved

; Clear/Delete font
; inputs: hl = bufferId
; VDU 23, 0, &95, 4, bufferId;: Clear/Delete font
vdu_font_clear:
    ld (@bufferId),hl
    ld hl,@cmd
    ld bc,@end-@cmd
    rst.lil $18
    ret
@cmd: db 23, 0, 0x95, 4
@bufferId: dw 0x0000
@end: db 0x00 ; padding

; Copy system font to buffer
; inputs: hl = bufferId
; VDU 23, 0, &95, 5, bufferId;: Copy system font to buffer
vdu_font_copy_system:
    ld (@bufferId),hl
    ld hl,@cmd
    ld bc,@end-@cmd
    rst.lil $18
    ret
@cmd: db 23, 0, 0x95, 5
@bufferId: dw 0x0000
@end: db 0x00 ; padding
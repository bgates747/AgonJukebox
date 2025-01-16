    ; AGON LIGHT
    ; CONTEXT example
    ; Richard Turnnidge 2025
    ; with thanks to Brandon for his sample to build upon
    ;
    ; this example has two text boxes, each with different colour text and backgrounds

; ---------------------------------------------
;
;   MACROS
;
; ---------------------------------------------

    macro MOSCALL function
    ld a, function
    rst.lil $08
    endmacro

; ---------------------------------------------

    macro SETMODE mode
    ld a, 22
    rst.lil $10
    ld a, mode
    rst.lil $10
    endmacro

; ---------------------------------------------

    macro TEXTCOLOUR n
    ld a, 17  
    rst.lil $10    
    ld a, n  
    rst.lil $10      
    endmacro

; ---------------------------------------------

    macro TEXTBGCOLOUR n
    ld a, 17  
    rst.lil $10    
    ld a, n + 128
    rst.lil $10      
    endmacro

; ---------------------------------------------

    macro CLS
    ld a, 12
    rst.lil $10
    endmacro

; ---------------------------------------------

    macro SETCURSOR value       ; to set cursor visible or not [0 or 1]
    push af
    ld a, 23
    rst.lil $10
    ld a, 1
    rst.lil $10
    ld a, value
    rst.lil $10                 ; VDU 23,1,value [0 off, 1 on]
    pop af
    endmacro

; ---------------------------------------------
;
;   CONSTANTS
;
; ---------------------------------------------

; some colours
c_white:            equ 15
c_black:            equ 0
c_dark_blue:        equ 4
c_yellow:           equ 11
c_dark_red:         equ 1

mos_getkey:         equ $00         ; MOS value


; contextId constants and state variables
contextId_default:  equ 0
contextId_left:     equ 1
contextId_right:    equ 2


; ---------------------------------------------
;
;   GET READY
;
; ---------------------------------------------

    .assume adl=1       ; big memory mode
    .org $40000         ; load code here

    jp start_here       ; jump to start of code

    .align 64           ; MOS header
    .db "MOS",0,1

; ---------------------------------------------
;
;   START
;
; ---------------------------------------------

start_here: 
    push af
    push bc
    push de
    push ix
    push iy

    SETMODE 8

    ld hl, loadFont                 ; address of string to use
    ld bc, endFont - loadFont       ; length of string
    rst.lil $18  

    TEXTBGCOLOUR c_dark_red
    CLS                             ; set screen mode and clear screen ready to start

    ld hl, contextId_default
    call vdu_select_context_stack
    call vdu_save_context           ; save current context as default (0)


    call defineLeftContext          ; configure the left context
    call defineRightContext         ; configure the right context

    ld hl,contextId_left
    ld (contextId_current), hl
    call vdu_select_context_stack   ; set the current context to left ID



main:                               ; wait for user input and branch on key pressed

    call waitKeypress               ; a = ascii code of key pressed

    cp '\e'                         ; check for ESC key
    jp z, exit_here                 ; exit if ESC key pressed

    cp '\t'                         ; check for TAB key
    jp z, switch_context

    cp $15                         ; check for RIGHT ARROW (NAK)
    jp nz, not_nak
    ld a, $09                       ; fore a NKA to be TAB right

not_nak:
    cp '\r'                         ; check for ENTER key
    jp nz, @standard_key           ; any other key just print the ascii char

    rst.lil 0x10                    ; print the carriage return
    ld a,'\n'                       ; then we follow with a newline character to end up with '\r\n'

@standard_key:
    rst.lil 0x10                    ; print the ascii code of the key pressed

    ;call debugInst
    jp main                         ; just loop round until exit


; ---------------------------------------------

; wait until user presses a key ascii code returned in a

waitKeypress:
    MOSCALL mos_getkey
    ret

; ---------------------------------------------

exit_here:

    call revertFont

    ld hl, contextId_default        ; ID 0
    call vdu_select_context_stack   ; reset the context to default
    TEXTBGCOLOUR c_black            ; reset background colour
    CLS                             ; clear screen on exit

    pop iy
    pop ix
    pop de
    pop bc
    pop af
    ld hl,0                         ; restore registers

    ret                             ; back to MOS


; ---------------------------------------------

debugInst:          ; debug A to screen as HEX byte pair at current pos
    push bc 
    push af 
    ld (debug_char), a  ; store A
                ; first, print 'A=' at TAB 36,0

    ld a, (debug_char)  ; get A from store, then split into two nibbles
    and 11110000b       ; get higher nibble
    rra
    rra
    rra
    rra         ; move across to lower nibble
    add a,48        ; increase to ascii code range 0-9
    cp 58           ; is A less than 10? (58+)
    jr c, nextin1       ; carry on if less
    add a, 7        ; add to get 'A' char if larger than 10
nextin1:    
    rst.lil $10     ; print the A char

    ld a, (debug_char)  ; get A back again
    and 00001111b       ; now just get lower nibble
    add a,48        ; increase to ascii code range 0-9
    cp 58           ; is A less than 10 (58+)
    jp c, nextin2       ; carry on if less
    add a, 7        ; add to get 'A' char if larger than 10 
nextin2:    
    rst.lil $10     ; print the A char
    
    ld a, ' '
    rst.lil $10     ; print the SPACE char
    
    ld a, (debug_char)
    pop af 
    pop bc
    ret         ; head back

debug_char:     .db 0

; ---------------------------------------------
;
; CONTEXT SETUP ROUTINES
;
; ---------------------------------------------

; define left half of screen

defineLeftContext:

    ld hl,contextId_left
    call vdu_delete_context_stack   ; make sure context is clear
;    call vdu_select_context_stack   ; select context by ID (left = 1)

    ld hl,contextId_left
    call vdu_select_context_stack   ; select context by ID (left = 1)
;     ld a,00011111b
;     call vdu_reset_context          ; reset context
;                                     ; Bit - Description
;                                     ; 0 Reset graphics painting options
;                                     ; 1 Reset graphics positioning settings, including graphics viewport and coordinate system
;                                     ; 2 Reset text painting options
;                                     ; 3 Reset text cursor visual settings, including text viewport
;                                     ; 4 Reset text cursor behaviour


    ld hl, setFont                 ; address of string to use
    ld bc, endSetFont - setFont       ; length of string
    rst.lil $18  

    TEXTBGCOLOUR c_white            ; set text background to white
    TEXTCOLOUR c_black              ; set text foreground to black

    ld c,1                          ; left
    ld d,1                          ; top
    ld e,19                         ; right
    ld b,20                         ; bottom
    call vdu_set_txt_viewport       ; define a text viewport

    SETCURSOR 1                     ; set cursor on     

    CLS                             ; clear the screen's viewport to apply text bg colour

    call vdu_save_context           ; save the context

    ret

setFont:

    .db     23,0,$95 , 0                ; select font (VDU 23, 0, &95, 0, bufferId; flags)
    .dw     1000                        ; ID (word)
    .db     0                           ; flags

endSetFont:

; ---------------------------------------------
; define right half of screen

defineRightContext:

    ld hl,contextId_right
    call vdu_delete_context_stack   ; make sure context is clear

;     ld a,%00011111 
;     call vdu_reset_context          ; reset context

    ld hl,contextId_right
    call vdu_select_context_stack   ; select context by ID (right = 2)

    ld hl, setFont2                 ; address of string to use
    ld bc, endSetFont2 - setFont2       ; length of string
    rst.lil $18  

    TEXTBGCOLOUR c_dark_blue        ; set text background to dark blue
    TEXTCOLOUR c_yellow             ; set text foreground to yellow

    ld c,1                         ; left
    ld d, 11                         ; top
    ld e,38                         ; right
    ld b,13                         ; bottom
    call vdu_set_txt_viewport       ; set a text viewport
 
    SETCURSOR 1                     ; set cursor on

    CLS                             ; clear the screen's viewport to apply text bg colour

    call vdu_save_context           ; save the context

    ret

setFont2:

    .db     23,0,$95 , 0                ; select font (VDU 23, 0, &95, 0, bufferId; flags)
    .dw     1001                        ; ID (word)
    .db     0                           ; flags

endSetFont2:

; ---------------------------------------------

; switch to a new context. Here, we just flip from ID 1 to 2, or vice versa

switch_context:
    ld a, (contextId_current)       ; get LSB of contextId_current as we only use 0, 1 or 2 in this example
    cp contextId_left               ; compare with leftID
    jp z, @set_right                ; if currently left, then set new context id to right

    ld hl, contextId_left           ; else set new context id to left
    jp @switch

@set_right:
    ld hl,contextId_right           ; set new context id to right

@switch:
    ld (contextId_current), hl      ; set the context we will switch to
    call vdu_select_context_stack   ; switch the context
    jp main                         ; done, to head back to main loop

; ---------------------------------------------
;
;   CONTEXT API FUNCTIONS
;
;   https://agonconsole8.github.io/agon-docs/vdp/Context-Management-API/
;   for further info and additional commands
;
; ---------------------------------------------

; VDU 23, 0, $C8, 0, contextId: Select context stack
; inputs: hl = contextId
; outputs: nothing
; prerequisites: none
; destroys: af, bc, hl

vdu_select_context_stack:
    ld (@contextId),hl
    ld hl, @cmd
    ld bc, @end-@cmd
    rst.lil $18
    ret
@cmd:       .db 23, 0, $C8, 0                       ; just send this string of bytes
@contextId: .dw 0x0000                              ; plus the ID in this word
@end:       .db 0x00                                ; padding to work in ADL mode

; ---------------------------------------------

; VDU 23, 0, $C8, 1, contextId: Delete context stack
; inputs: hl = contextId
; outputs: nothing
; prerequisites: none
; destroys: af, bc, hl
vdu_delete_context_stack:
    ld (@contextId),hl
    ld hl,@cmd
    ld bc,@end-@cmd
    rst.lil $18
    ret
@cmd:           .db 23, 0, $C8, 1               ; just send this string of bytes
@contextId:     .dw 0x0000                      ; plus the ID in this word
@end:           .db 0x00                        ; padding to work in ADL mode

; ---------------------------------------------

; VDU 23, 0, $C8, 3: Save context
; inputs: none
; outputs: nothing
; prerequisites: vdu_select_context_stack
; destroys: af, bc, hl

vdu_save_context:
    ld hl, @cmd
    ld bc, @end-@cmd
    rst.lil $18
    ret
@cmd:       .db 23, 0, $C8, 3       ; just send this string of bytes
@end:

; ---------------------------------------------
;
; --- VDU HELPER FUNCTIONS ---
;
; ---------------------------------------------

; VDU 28, left, bottom, right, top: Set text viewport
; inputs: c=left, b=bottom, e=right, d=top
; outputs; nothing
; destroys: af, hl, bc, de

vdu_set_txt_viewport:
    ld (@lb), bc
	ld (@rt), de
	ld hl, @cmd
	ld bc, @end-@cmd
	rst.lil $18
	ret
@cmd:   .db 28               ; set text viewport command
@lb: 	.dw 0x0000           ; bottom left set by bc
@rt: 	.dw 0x0000           ; top right set by de
@end:   .db 0x00	         ; padding to work in ADL mode

; ---------------------------------------------
;
;   FONT DATA
;
; ---------------------------------------------

loadFont:

    .db     23, 0, $A0                  ; buffer command
    .dw     -1                          ; ID (word): -1 in this case is ALL
    .db     2                           ; 2 = clear (all buffers)

    ; 1st font - load the buffer

    .db     23,0,$A0                    ; buffer command
    .dw     1000                        ; ID (word)
    .db     0                           ; 'write' command
    .dw     2048                        ; full 8x8 font is 16 bytes x 256 = 2048 

   ; incbin "8x8_fonts/latin.bin"

    include "8x8_fonts/Beachball.asm"
    ; create 1st font from buffer (VDU 23, 0, &95, 1, bufferId; width, height, ascent, flags)

    .db     23,0,$95 , 1                ; create font
    .dw     1000                        ; ID (word)
    .db     8,8                         ; 8x8 font in this example
    .db     8,0                         ; ascent, flags


    ; 2nd font - load the buffer

    .db     23,0,$A0                    ; write block
    .dw     1001                        ; ID (word)
    .db     0                           ; 'write' command
    .dw     4096                        ; full 8x8 font is 8 bytes x 256 = 2048
            
            
    include "labyrinthFont.asm"
 ;   incbin "8x16_fonts/iso-8x16.font"

    ; create font from buffer
    ; VDU 23, 0, &95, 1, bufferId; width, height, ascent, flags

    .db     23,0,$95 , 1                ; create font
    .dw     1001                        ; ID (word)
    .db     8,16                            ; 8x8 font in this example
    .db     16,0                        ; ascent, flags

    ; select the font 
    ; VDU 23, 0, &95, 0, bufferId; flags

;     .db     23,0,$95 , 0                ; select font
;     .dw     1001                        ; ID (word)
;     .db     1                           ; flags

endFont:


revertFont:
    ld hl, resetFont                 ; address of string to use
    ld bc, endResetFont - resetFont       ; length of string
    rst.lil $18  

    ret 


resetFont:
    .db     23,0,$95 , 0                ; select font
    .dw     -1                         ; ID (word)
    .db     0                           ; flags
endResetFont:

; ---------------------------------------------
;
;   VARIABLES
;
; ---------------------------------------------

contextId_current: dl 0

; ---------------------------------------------
;
;   END
;
; ---------------------------------------------
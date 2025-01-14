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

; --- MACROS AND EQUS ---
c_white: equ 15
c_black: equ 0
c_blue_dk: equ 4
c_yellow: equ 11
mos_getkey:	EQU	00h

; Macro for calling the MOS API
; Parameters:
; - function: One of the function numbers listed above
;
	MACRO	MOSCALL	function
			LD	A, function
			RST.LIL	08h
	ENDMACRO

; test the sign of HL
; inputs: HL obviously
; outputs: sign flag set if HL is negative, zero flag set if HL is zero
; destroys: flags    
    MACRO SIGN_HLU
    add hl,de ; 1 cycle
    or a ; clear flags ; 1 cycle
    sbc hl,de ; 2 cycles
    ; 4 cycles total
    ENDMACRO

; --- MAIN PROGRAM ---
; contextId constants and state variables
contextId_default: equ 0
contextId_left: equ 1
contextId_right: equ 2
contextId_current: dl 0

init:
; clear the screen
    call vdu_cls

; save current context as default
    ld hl,contextId_default
    call vdu_select_context_stack
    call vdu_save_context

; define left half of screen
; ---------------------------
; select contextId
    ld hl,contextId_left
    call vdu_select_context_stack
; reset context
; flags:
; Bit	Description
; 0	Reset graphics painting options
; 1	Reset graphics positioning settings, including graphics viewport and coordinate system
; 2	Reset text painting options
; 3	Reset text cursor visual settings, including text viewport
; 4	Reset text cursor behaviour
    ld a,%00011111
    call vdu_reset_context
; set text colours
    ld a,c_white+128 ; text background to white
    call vdu_colour_text
    ld a,c_black ; text foreground to black
    call vdu_colour_text
; set a text viewport
    ld c,1 ; left
    ld d,1 ; top
    ld e,23 ; right
    ld b,40 ; bottom
    call vdu_set_txt_viewport
; set cursor on (but for some reason cursor doesn't flash after switching context until a key is pressed)
    call vdu_cursor_on
; clear the screen to apply text bg colour
    call vdu_cls
; save the context
    call vdu_save_context

; define right half of screen
; ---------------------------
; select contextId
    ld hl,contextId_right
    call vdu_select_context_stack
; reset context
    ld a,%00011111 
    call vdu_reset_context
; set text colours
    ld a,c_blue_dk+128 ; text background to dark blue
    call vdu_colour_text
    ld a,c_yellow ; text foreground to yellow
    call vdu_colour_text
; set a text viewport
    ld c,25 ; left
    ld d,1 ; top
    ld e,47 ; right
    ld b,40 ; bottom
    call vdu_set_txt_viewport
; set cursor on (but for some reason cursor doesn't flash after switching context until a key is pressed)
    call vdu_cursor_on 
; clear the screen to apply text bg colour
    call vdu_cls
; save the context
    call vdu_save_context

; set the current context to left
    ld hl,contextId_left
    ld (contextId_current),hl
    call vdu_select_context_stack

    ret
; end init

main:
; wait for user input and branch on key pressed
    call waitKeypress ; a = ascii code of key pressed
    cp '\e' ; ESC key
    jp z,@main_end ; exit if ESC key pressed
    cp '\t' ; TAB key
    jp z,switch_context
    cp '\r' ; ENTER key
    jp nz,@F
    rst.lil 0x10 ; print the carriage return
    ld a,'\n' ; load newline character
@@:
    rst.lil 0x10 ; print the ascii code of the key pressed
    jp main

@main_end:
; reset the context to default
    ld hl,contextId_default
    call vdu_select_context_stack
; move cursor below the text viewports
    ld c,0 ; x
    ld b,41 ; y
    call vdu_move_cursor

    ret ; back to MOS
; end main

switch_context:
    ld hl,(contextId_current)
    ld de,contextId_left
    or a ; clear carry
    sbc hl,de
    SIGN_HLU
    jp z,@to_right
    ld hl,contextId_left
    jp @switch
@to_right:
    ld hl,contextId_right
@switch:
    ld (contextId_current),hl
    call vdu_select_context_stack
    ; call vdu_cursor_on ; not sure why this is needed but it is
    jp main
; end switch_context

; --- CONTEXT API FUNCTIONS ---

; https://agonconsole8.github.io/agon-docs/vdp/Context-Management-API/

; VDU 23, 0, $C8, 0, contextId: Select context stack
; inputs: hl = contextId
; outputs: nothing
; prerequisites: none
; destroys: af, bc, hl
vdu_select_context_stack:
    ld (@contextId),hl
    ld hl,@cmd
    ld bc,@end-@cmd
    rst.lil $18
    ret
@cmd: db 23, 0, $C8, 0
@contextId: dw 0x0000
@end: db 0x00 ; padding
; end vdu_select_context_stack

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
@cmd: db 23, 0, $C8, 1
@contextId: dw 0x0000
@end: db 0x00 ; padding
; end vdu_delete_context_stack

; VDU 23, 0, $C8, 2, flags: Reset the current context
; inputs: a = flags
; outputs: nothing
; prerequisites: vdu_select_context_stack
; destroys: af, hl, bc
; flags:
; Bit	Description
; 0	Reset graphics painting options
; 1	Reset graphics positioning settings, including graphics viewport and coordinate system
; 2	Reset text painting options
; 3	Reset text cursor visual settings, including text viewport
; 4	Reset text cursor behaviour
; 5	Reset currently selected fonts
; 6	Reset character to bitmap mappings
; 7	Reserved for future use
vdu_reset_context:
    ld (@flags),a
    ld hl,@cmd
    ld bc,@end-@cmd
    rst.lil $18
    ret
@cmd: db 23, 0, $C8, 2
@flags: db 0x00
@end:
; end vdu_reset_context

; VDU 23, 0, $C8, 3: Save context
; inputs: none
; outputs: nothing
; prerequisites: vdu_select_context_stack
; destroys: af, bc, hl
vdu_save_context:
    ld hl,@cmd
    ld bc,@end-@cmd
    rst.lil $18
    ret
@cmd: db 23, 0, $C8, 3
@end:
; end vdu_save_context

; VDU 23, 0, $C8, 4: Restore context
; inputs: none
; outputs: nothing
; prerequisites: vdu_select_context_stack
; destroys: af, bc, hl
vdu_restore_context:
    ld hl,@cmd
    ld bc,@end-@cmd
    rst.lil $18
    ret
@cmd: db 23, 0, $C8, 4
@end:
; end vdu_restore_context

; VDU 23, 0, $C8, 5, contextId: Save and select a copy of a context
; inputs: hl = contextId
; outputs: nothing
; prerequisites: graphics / text context in the state to save
vdu_select_and_save_context:
    ld (@contextId),hl
    ld hl,@cmd
    ld bc,@end-@cmd
    rst.lil $18
    ret
@cmd: db 23, 0, $C8, 5
@contextId: dw 0x0000
@end: db 0x00 ; padding
; end vdu_select_and_save_context

; VDU 23, 0, $C8, 6: Restore all contexts
; inputs: none
; outputs: nothing
; prerequisites: none
; destroys: af, bc, hl
vdu_restore_all_contexts:
    ld hl,@cmd
    ld bc,@end-@cmd
    rst.lil $18
    ret
@cmd: db 23, 0, $C8, 6
@end:
; end vdu_restore_all_contexts

; VDU 23, 0, $C8, 7: Clear stack
; inputs: none
; outputs: nothing
; prerequisites: none
; destroys: af, bc, hl
vdu_clear_context_stack:
    ld hl,@cmd
    ld bc,@end-@cmd
    rst.lil $18
    ret
@cmd: db 23, 0, $C8, 7
@end:
; end vdu_clear_context_stack

; --- HELPER FUNCTIONS ---

; VDU 12: Clear text area (CLS)
vdu_cls:
    ld a,12
	rst.lil $10  
	ret
; end vdu_cls

; VDU 17, colour: Define text colour (COLOUR)
vdu_colour_text:
	ld (@arg),a        
	ld hl,@cmd         
	ld bc,@end-@cmd    
	rst.lil $18         
	ret
@cmd: db 17
@arg: db 0 
@end:
; end vdu_colour_text

; VDU 23, 1, 1: Set cursor on
vdu_cursor_on:
	ld hl,@cmd
	ld bc,@end-@cmd
	rst.lil $18
	ret
@cmd:
	db 23,1,1
@end:

; VDU 28, left, bottom, right, top: Set text viewport **
; inputs: c=left,b=bottom,e=right,d=top
; outputs; nothing
; destroys: af, hl, bc, de
vdu_set_txt_viewport:
    ld (@lb),bc
	ld (@rt),de
	ld hl,@cmd
	ld bc,@end-@cmd
	rst.lil $18
	ret
@cmd:   db 28 ; set text viewport command
@lb: 	dw 0x0000 ; set by bc
@rt: 	dw 0x0000 ; set by de
@end:   db 0x00	  ; padding
; end vdu_set_txt_viewport

; VDU 31, x, y: Move text cursor to x, y text position (TAB(x, y))
; inputs: c=x, b=y 8-bit unsigned integers
vdu_move_cursor:
    ld (@x0),bc
	ld hl,@cmd         
	ld bc,@end-@cmd    
	rst.lil $18         
	ret
@cmd: 	db 31
@x0:	db 0
@y0: 	db 0
@end: 	db 0 ; padding

; wait until user presses a key
; inputs: none
; outputs: ascii code of key pressed in a
; destroys: af,ix
waitKeypress:
    MOSCALL mos_getkey
    ret
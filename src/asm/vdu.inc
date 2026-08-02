    MACRO VDU_BEEP
    ld a,7
    rst.lil $10
    ENDMACRO

; VDU 30: Home cursor
vdu_home_cursor:
    ld a,30
	rst.lil $10  
	ret

vdu_cursor_on:
	ld hl,@cmd
	ld bc,@end-@cmd
	rst.lil $18
	ret
@cmd:
	db 23,1,1
@end:

vdu_cursor_off:	
	ld hl,@cmd
	ld bc,@end-@cmd
	rst.lil $18
	ret
@cmd:
	db 23,1,0
@end:

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

; https://agonconsole8.github.io/agon-docs/vdp/VDU-Commands/#vdu-23-1-n-cursor-control
; VDU 23, 16, setting, mask: Define cursor movement behaviour
; inputs: l = setting, h = mask
; new_setting = (current_setting AND mask) EOR setting
; in English: mask controls which bit to turn on or off, setting is the value of the bits to set or reset
vdu_cursor_behaviour:
    ld (@setting),hl ; little-endian!
    ld hl,@cmd
    ld bc,@end-@cmd
    rst.lil $18
    ret
@cmd: db 23,16
@setting: db 0
@mask: db 0
@end: db 0 ; padding

; VDU 12: Clear text area (CLS)
vdu_cls:
    ld a,12
	rst.lil $10  
	ret

; COLOUR MODES
; Mode	Effect
; 0	Set on-screen pixel to target colour value
; 1	OR value with the on-screen pixel
; 2	AND value with the on-screen pixel
; 3	XOR value with the on-screen pixel
; 4	Invert the on-screen pixel
; 5	No operation
; 6	AND the inverse of the specified colour with the on-screen pixel
; 7	OR the inverse of the specified colour with the on-screen pixel

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

; VDU 28, left, bottom, right, top: Set text viewport **
; MIND THE LITTLE-ENDIANESS
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

; Wait for VBLANK interrupt
vdu_vblank:		
    PUSH 	IX			
		MOSCALL	mos_sysvars
		LD	A, (IX + sysvar_time + 0)
@wait:		
		CP 	A, (IX + sysvar_time + 0)
		JR	Z, @wait
		POP	IX
		RET

; VDU 26: Reset graphics and text viewports
vdu_reset_viewports:
    ld a,26
    rst.lil $10  
    ret

; SCREEN MODES
; ===============================
; Mode  Horz  Vert  Cols  Refresh
; ---   ----  ----  ----  -------
; 11    320   240   2     60hz
; 139   320   240   2     60hz
; 23    512   384   2     60hz
; 151   512   384   2     60hz
; 6     640   240   2     60hz
; 134   640   240   2     60hz
; 2     640   480   2     60hz
; 130   640   480   2     60hz
; 17    800   600   2     60hz
; 145   800   600   2     60hz
; 18    1024  768   2     60hz
; 146   1024  768   2     60hz
; ---   ----  ----  ----  -------
; 10    320   240   4     60hz
; 138   320   240   4     60hz
; 22    512   384   4     60hz
; 150   512   384   4     60hz
; 5     640   240   4     60hz
; 133   640   240   4     60hz
; 1     640   480   4     60hz
; 129   640   480   4     60hz
; 16    800   600   4     60hz
; 19    1024  768   4     60hz
; ---   ----  ----  ----  -------
; 9     320   240   16    60hz
; 137   320   240   16    60hz
; 21    512   384   16    60hz
; 149   512   384   16    60hz
; 4     640   240   16    60hz
; 132   640   240   16    60hz
; 0     640   480   16    60hz
; 7     n/a   n/a   16    60hz
; ---   ----  ----  ----  -------
; 8     320   240   64    60hz
; 136   320   240   64    60hz
; 20    512   384   64    60hz
; 3     640   240   64    60hz
; ---   ----  ----  ----  -------
vdu_set_screen_mode:
	ld (@arg),a        
	ld hl,@cmd         
	ld bc,@end-@cmd    
	rst.lil $18         
	ret
@cmd: db 22 ; set screen mode
@arg: db 0  ; screen mode parameter
@end:

; get the current screen mode
; inputs: none
; outputs: a=screen mode
; destroys: af, ix
vdu_get_screen_mode:
    MOSCALL mos_sysvars
    ld a,(IX+sysvar_scrMode)
    ret
; end vdu_get_screen_mode

; VDU 23, 0, &C0, n: Turn logical screen scaling on and off *
; inputs: a is scaling mode, 1=on, 0=off
; note: default setting on boot is scaling ON
vdu_set_scaling:
	ld (@arg),a        
	ld hl,@cmd         
	ld bc,@end-@cmd    
	rst.lil $18         
	ret
@cmd: db 23,0,0xC0
@arg: db 0  ; scaling on/off
@end: 

; VDU 23, 27, &20, bufferId; : Select bitmap (using a buffer ID)
; inputs: hl=bufferId
vdu_buff_select:
	ld (@bufferId),hl
	ld hl,@cmd
	ld bc,@end-@cmd
	rst.lil $18
	ret
@cmd: db 23,27,0x20
@bufferId: dw 0x0000
@end: db 0x00 ; padding

; VDU 23, 27, &21, w; h; format: Create bitmap from selected buffer
; inputs: a=format; bc=width; de=height
; prerequisites: buffer selected by vdu_bmp_select or vdu_buff_select
; formats: https://agonconsole8.github.io/agon-docs/VDP---Bitmaps-API.html
; 0 	RGBA8888 (4-bytes per pixel)
; 1 	RGBA2222 (1-bytes per pixel)
; 2 	Mono/Mask (1-bit per pixel)
; 3 	Reserved for internal use by VDP (“native” format)
vdu_bmp_create:
    ld (@width),bc
    ld (@height),de
    ld (@fmt),a
	ld hl,@cmd
	ld bc,@end-@cmd
	rst.lil $18
	ret
@cmd:       db 23,27,0x21
@width:     dw 0x0000
@height:    dw 0x0000
@fmt:       db 0x00
@end:

; load a vdu buffer from local memory
; inputs: hl = bufferId ; bc = length ; de = pointer to data
vdu_load_buffer:
    ld (@length),bc
    push de ; save data pointer
; send the vdu command string
    ld a,l
    ld (@bufferId),a
    ld a,h
    ld (@bufferId+1),a
    ld hl,@cmd
    ld bc,@end-@cmd
    rst.lil $18
; send the buffer data
    pop hl ; pointer to data
    ld bc,(@length)
    rst.lil $18 ; send it
    ret
; Upload data :: VDU 23, 0 &A0, bufferId; 0, length; <buffer-data>
@cmd:       db 23,0,0xA0
@bufferId:	dw 0x0000
		    db 0 ; load buffer
@length:	dw 0x0000
@end: db 0 ; padding

; Command 14: Consolidate blocks in a buffer
vdu_consolidate_buffer:
; set parameters for vdu call
    ld a,l
    ld (@bufferId),a
    ld a,h
    ld (@bufferId+1),a
    ld hl,@beg
    ld bc,@end-@beg
    rst.lil $18
    ret
; VDU 23, 0, &A0, bufferId; 14
@beg: db 23,0,0xA0
@bufferId: dw 0x0000
           db 14
@end:

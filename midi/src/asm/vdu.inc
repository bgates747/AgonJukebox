; VDU 4: Write text at text cursor
;     This causes text to be written at the current text cursor position. 
;     This is the default mode for text display.
;     Text is written using the current text foreground and background colours.
; inputs: a is the character to write to the screen
; prerequisites: the text cursor at the intended position on screen
; outputs: prints the character and moves text cursor right one position
; destroys: a, hl, bc
vdu_char_to_text_cursor:
	ld (@arg),a        
	ld hl,@cmd         
	ld bc,@end-@cmd    
	rst.lil $18         
	ret
@cmd: db 4
@arg: db 0 
@end:

; VDU 5: Write text at graphics cursor
;     This causes text to be written at the current graphics cursor position.
;     Using this, characters may be positioned at any graphics coordinate within 
;     the graphics viewport. This is useful for positioning text over graphics, 
;     or for positioning text at a specific location on the screen.
;     Characters are plotted using the current graphics foreground colour, 
;     using the current graphics foreground plotting mode (see VDU 18).
;     The character background is transparent, and will not overwrite any 
;     graphics that are already present at the character’s location. 
;     The exception to this is VDU 27, the “delete” character, which backspaces 
;     and deletes as per its usual behaviour, but will erase using the current 
;     graphics background colour.
; inputs: a is the character to write to the screen
; prerequisites: the graphics cursor at the intended position on screen
; outputs: see the name of the function
; destroys: a, hl, bc
vdu_char_to_gfx_cursor:
	ld (@arg),a        
	ld hl,@cmd         
	ld bc,@end-@cmd    
	rst.lil $18         
	ret
@cmd: db 5
@arg: db 0 
@end:

; VDU 6: Enable screen (opposite of VDU 21) §§
;     This enables the screen, and re-enables VDU command processing, 
;     reversing the effect of VDU 21.
; inputs: none
; outputs: a functioning screen and VDU
; destroys: a
vdu_enable_screen:
    ld a,6
	rst.lil $10  
	ret

; PASSES
; VDU 7: Make a short beep (BEL)
;     Plays a short beep sound on audio channel 0. If the audio channel 
;     is already in use, or has been disabled, then this command will have no effect.
; inputs: none
; outputs: an unpleasant but thankfully short-lived audio tone
; destroys: a
vdu_beep:
    ld a,7
	rst.lil $10  
	ret

; VDU 8: Move cursor back one character
;     Moves the text cursor one character in the negative “X” direction. 
;     By default, when at the start of a line it will move to the end of 
;     the previous line (as defined by the current text viewport). 
;     If the cursor is also at the top of the screen then the viewport will scroll down. 
;     The cursor remains constrained to the current text viewport.
;     When in VDU 5 mode and the graphics cursor is active, the viewport will not scroll. 
;     The cursor is just moved left by one character width.
;     Further behaviour of the cursor can be controlled using the VDU 23,16 command.
;     It should be noted that as of Console8 VDP 2.5.0, the cursor system does not 
;     support adjusting the direction of the cursor’s X axis, so this command 
;     will move the cursor to the left. This is likely to change in the future.
vdu_cursor_back:
    ld a,8
	rst.lil $10  
	ret

; VDU 9: Move cursor forward one character
vdu_cursor_forward:
    ld a,9
	rst.lil $10  
	ret

; VDU 10: Move cursor down one line
vdu_cursor_down:
    ld a,10
	rst.lil $10  
	ret

; VDU 11: Move cursor up one line
vdu_cursor_up:
    ld a,11
	rst.lil $10  
	ret

; VDU 12: Clear text area (CLS)
vdu_cls:
    ld a,12
	rst.lil $10  
	ret

; VDU 13: Carriage return
vdu_cr:
    ld a,13
	rst.lil $10  
	ret

; VDU 14: Page mode On *
vdu_page_on:
    ld a,14
	rst.lil $10  
	ret

; VDU 15: Page mode Off *
vdu_page_off:
    ld a,15
	rst.lil $10  
	ret

; VDU 16: Clear graphics area (CLG)
vdu_clg:
    ld a,16
	rst.lil $10  
	ret

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

; VDU 18, mode, colour: Set graphics colour (GCOL mode, colour)
; inputs: a is the plotting mode, c is the colour
; outputs: a VDU set to put pixels on the screen with the selected mode/colour
vdu_gcol_fg:
; This command will set both the current graphics colour, 
; and the current graphics plotting mode.
; As with VDU 17 the colour number will set the foreground colour 
; if it is in the range 0-127, or the background colour if it is 
; in the range 128-255, and will be interpreted in the same manner.
; Support for different plotting modes on Agon is currently very limited. 
; The only fully supported mode is mode 0, which is the default mode. 
; This mode will plot the given colour at the given graphics coordinate, 
; and will overwrite any existing graphics at that coordinate. There is 
; very limited support for mode 4, which will invert the colour of any 
; existing graphics at the given coordinate, but this is not fully supported 
; and may not work as expected.
; Support for other plotting modes, matching those provided by Acorn’s 
; original VDU system, may be added in the future.
; This command is identical to the BASIC GCOL keyword.
	ld (@mode),a
    ld a,c
    ld (@col),a   
	ld hl,@cmd         
	ld bc,@end-@cmd    
	rst.lil $18         
	ret
@cmd: db 18
@mode: db 0
@col: db 0 
@end:

vdu_gcol_bg:
	ld (@mode),a
    ld a,c
    add a,128 
    ld (@col),a   
	ld hl,@cmd         
	ld bc,@end-@cmd    
	rst.lil $18         
	ret
@cmd:  db 18
@mode: db 0
@col:  db 0 
@end:

; VDU 19, l, p, r, g, b: Define logical colour (COLOUR l, p / COLOUR l, r, g, b)
;     This command sets the colour palette, by mapping a logical colour 
;     to a physical colour. This is useful for defining custom colours, 
;     or for redefining the default colours.
;     If the physical colour number is given as 255 then the colour will 
;     be defined using the red, green, and blue values given. If the physical 
;     colour number is given as any other value then the colour will be defined 
;     using the colour palette entry given by that number, up to colour number 63.
;     If the physical colour is not 255 then the red, green, and blue values 
;     must still be provided, but will be ignored.
;     The values for red, green and blue must be given in the range 0-255. 
;     You should note that the physical Agon hardware only supports 64 colours, 
;     so the actual colour displayed may not be exactly the same as the colour 
;     requested. The nearest colour will be chosen.
;     This command is equivalent to the BASIC COLOUR keyword.
; inputs: a=physcial colour, b=logical colour, chl=r,g,b
vdu_def_log_colour:
	ld (@physical),a
    ld b,a
    ld (@logical),a
    ld a,c
    ld (@red),a
    ld a,h
    ld (@green),a
    ld a,l
    ld (@blue),a
	ld hl,@cmd         
	ld bc,@end-@cmd    
	rst.lil $18         
	ret
@cmd: db 19
@logical: db 0 
@physical: db 0
@red: db 0
@green: db 0
@blue: db 0
@end:

; VDU 20: Reset palette and text/graphics colours and drawing modes §§
vdu_reset_gfx:
    ld a,20
	rst.lil $10  
	ret

; VDU 21: Disable screen (turns off VDU command processing, 
; except for VDU 1 and VDU 6) §§
vdu_disable_screen:
    ld a,21
	rst.lil $10  
	ret

; VDU 22, n: Select screen mode (MODE n)
; Inputs: a, screen mode (8-bit unsigned integer), in the following list:
; https://agonconsole8.github.io/agon-docs/VDP---Screen-Modes.html
; Screen modes
; Modes over 128 are double-buffered
; From Version 1.04 or greater
; Mode 	Horz 	Vert 	Cols 	Refresh
; 0 	640 	480 	16 	    60hz
; * 1 	640 	480 	4 	    60hz
; 2 	640 	480 	2 	    60hz
; 3 	640 	240 	64 	    60hz
; 4 	640 	240 	16 	    60hz
; 5 	640 	240 	4 	    60hz
; 6 	640 	240 	2 	    60hz
; ** 7 	n/a 	n/a 	16 	    60hz
; 8 	320 	240 	64 	    60hz
; 9 	320 	240 	16 	    60hz
; 10 	320 	240 	4 	    60hz
; 11 	320 	240 	2 	    60hz
; 12 	320 	200 	64 	    70hz
; 13 	320 	200 	16 	    70hz
; 14 	320 	200 	4 	    70hz
; 15 	320 	200 	2 	    70hz
; 16 	800 	600 	4 	    60hz
; 17 	800 	600 	2 	    60hz
; 18 	1024 	768 	2 	    60hz
; 129 	640 	480 	4 	    60hz
; 130 	640 	480 	2 	    60hz
; 132 	640 	240 	16 	    60hz
; 133 	640 	240 	4 	    60hz
; 134 	640 	240 	2 	    60hz
; 136 	320 	240 	64 	    60hz
; 137 	320 	240 	16 	    60hz
; 138 	320 	240 	4 	    60hz
; 139 	320 	240 	2 	    60hz
; 140 	320 	200 	64 	    70hz
; 141 	320 	200 	16 	    70hz
; 142 	320 	200 	4 	    70hz
; 143 	320 	200 	2 	    70hz
; * Mode 1 is the “default” mode, and is the mode that the system will use on startup. 
; It is also the mode that the system will fall back to use if it was not possible to 
; change to the requested mode.
; ** Mode 7 is the “Teletext” mode, and essentially works in a very similar manner to 
; the BBC Micro’s Teletext mode, which was also mode 7.
vdu_set_screen_mode:
	ld (@arg),a        
	ld hl,@cmd         
	ld bc,@end-@cmd    
	rst.lil $18         
	ret
@cmd: db 22 ; set screen mode
@arg: db 0  ; screen mode parameter
@end:

; VDU 23, n: Re-program display character / System Commands
; inputs: a, ascii code; hl, pointer to bitmask data
vdu_define_character:
	ld (@ascii),a
	ld de,@data
	ld b,8 ; loop counter for 8 bytes of data
@loop:
	ld a,(hl)
	ld (de),a
	inc hl
	inc de
	djnz @loop
	ld hl,@cmd
	ld bc,@end-@cmd
	rst.lil $18
	ret
@cmd:   db 23 
@ascii: db 0 
@data:  ds 8
@end: 

; VDU 24, left; bottom; right; top;: Set graphics viewport 
; NOTE: the order of the y-coordinate parameters are inverted
; 	because we have turned off logical screen scaling
; inputs: bc=x0,de=y0,ix=x1,iy=y1
; outputs; nothing
; destroys: a might make it out alive
vdu_set_gfx_viewport:
    ld (@x0),bc
    ld (@y1),iy
	ld (@x1),ix
	ld (@y0),de
	ld hl,@cmd
	ld bc,@end-@cmd
	rst.lil $18
	ret
@cmd:   db 24 ; set graphics viewport command
@x0: 	dw 0x0000 ; set by bc
@y1: 	dw 0x0000 ; set by iy
@x1: 	dw 0x0000 ; set by ix
@y0: 	dw 0x0000 ; set by de
@end:   db 0x00	  ; padding

; VDU 25, mode, x; y;: PLOT command
; Implemented in vdu_plot.asm

; VDU 26: Reset graphics and text viewports **
vdu_reset_txt_gfx_view:
    ld a,26
	rst.lil $10  
	ret

; PASSES
; VDU 27, char: Output character to screen §
; inputs: a is the ascii code of the character to draw
vdu_draw_char:
	ld (@arg),a        
	ld hl,@cmd         
	ld bc,@end-@cmd    
	rst.lil $18         
	ret
@cmd: db 27 
@arg: db 0  ; ascii code of character to draw
@end:

; VDU 28, left, bottom, right, top: Set text viewport **
; MIND THE LITTLE-ENDIANESS
; inputs: c=left,b=bottom,e=right,d=top
; outputs; nothing
; destroys: a might make it out alive
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

; PASSES
; VDU 29, x; y;: Set graphics origin
; inputs: bc,de x,y coordinates
vdu_set_gfx_origin:
    ld (@x0),bc
    ld (@y0),de
	ld hl,@cmd         
	ld bc,@end-@cmd    
	rst.lil $18         
	ret
@cmd:	db 29
@x0: 	dw 0 
@y0: 	dw 0
@end: 	db 0 ; padding

; PASSES
; VDU 30: Home cursor
vdu_home_cursor:
    ld a,30
	rst.lil $10  
	ret

; PASSES
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


; VDU 127: Backspace
vdu_bksp:
    ld a,127
	rst.lil $10  
	ret

; activate a bitmap in preparation to draw it
; inputs: a holding the bitmap index 
vdu_bmp_select:
	ld (@bmp),a
	ld hl,@cmd
	ld bc,@end-@cmd
	rst.lil $18
	ret
@cmd: db 23,27,0 
@bmp: db 0 
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

; Draw a bitmap on the screen
; inputs: bc, x-coordinate; de, y-coordinate
; prerequisite: bitmap index set by e.g. vdu_bmp_select
vdu_bmp_draw:
    ld (@x0),bc
    ld (@y0),de
	ld hl,@cmd
	ld bc,@end-@cmd
	rst.lil $18
	ret
@cmd: db 23,27,3
@x0:  dw 0x0000
@y0:  dw 0x0000
@end: db 0x00 ; padding

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

; VDU 23, 0, &C3: Swap the screen buffer and/or wait for VSYNC **
; 	Swap the screen buffer (double-buffered modes only) or wait for VSYNC 
; 	(all modes).

; 	This command will swap the screen buffer, if the current screen mode 
; 	is double-buffered, doing so at the next VSYNC. If the current screen 
; 	mode is not double-buffered then this command will wait for the next 
; 	VSYNC signal before returning. This can be used to synchronise the 
; 	screen with the vertical refresh rate of the monitor.

; 	Waiting for VSYNC can be useful for ensuring smooth graphical animation, 
; 	as it will prevent tearing of the screen.
; inputs: none
; outputs: none
; destroys: hl, bc
vdu_flip:       
	ld hl,@cmd         
	ld bc,@end-@cmd    
	rst.lil $18         
	ret
@cmd: db 23,0,0xC3
@end:

; #### from vdp.asm ####

; https://github.com/breakintoprogram/agon-docs/wiki/VDP
; VDU 23, 7: Scrolling
;     VDU 23, 7, extent, direction, speed: Scroll the screen
; inputs: a, extent; l, direction; h; speed
vdu_scroll_down:
	ld (@extent),a
	ld (@dir),hl ; implicitly populates @speed
	ld hl,@cmd
	ld bc,@end-@cmd
	rst.lil $18     ;; Sending command to VDP
	ret
@cmd:       db 23,7
@extent:    db 0x00 ; 0 current text window, 1 entire screen, 2 curr gfx viewport
@dir:       db 0x00 ; 0 right, 1 left, 2 down, 3 up
@speed:     db 0x00 ; pixels
@end:		db 0x00 ; padding

cursor_on:
	ld hl,@cmd
	ld bc,@end-@cmd
	rst.lil $18
	ret
@cmd:
	db 23,1,1
@end:

cursor_off:	
	ld hl,@cmd
	ld bc,@end-@cmd
	rst.lil $18
	ret
@cmd:
	db 23,1,0
@end:

vdu_vblank:		PUSH 	IX			; Wait for VBLANK interrupt
			MOSCALL	mos_sysvars		; Fetch pointer to system variables
			LD	A, (IX + sysvar_time + 0)
@wait:			CP 	A, (IX + sysvar_time + 0)
			JR	Z, @wait
			POP	IX
			RET

; #### from vdu_plot.asm ####
; https://agonconsole8.github.io/agon-docs/VDP---PLOT-Commands.html
; PLOT code 	(Decimal) 	Effect
; &00-&07 	0-7 	Solid line, includes both ends
plot_sl_both: equ 0x00

; &08-&0F 	8-15 	Solid line, final point omitted
plot_sl_first: equ 0x08

; &10-&17 	16-23 	Not supported (Dot-dash line, includes both ends, pattern restarted)
; &18-&1F 	24-31 	Not supported (Dot-dash line, first point omitted, pattern restarted)

; &20-&27 	32-39 	Solid line, first point omitted
plot_sl_last: equ 0x20

; &28-&2F 	40-47 	Solid line, both points omitted
plot_sl_none: equ 0x28

; &30-&37 	48-55 	Not supported (Dot-dash line, first point omitted, pattern continued)
; &38-&3F 	56-63 	Not supported (Dot-dash line, both points omitted, pattern continued)

; &40-&47 	64-71 	Point plot
plot_pt: equ 0x40

; &48-&4F 	72-79 	Line fill left and right to non-background §§
plot_lf_lr_non_bg: equ 0x48

; &50-&57 	80-87 	Triangle fill
plot_tf: equ 0x50

; &58-&5F 	88-95 	Line fill right to background §§
plot_lf_r_bg: equ 0x58

; &60-&67 	96-103 	Rectangle fill
plot_rf: equ 0x60

; &68-&6F 	104-111 	Line fill left and right to foreground §§
plot_lf_lr_fg: equ 0x60

; &70-&77 	112-119 	Parallelogram fill
plot_pf: equ 0x70

; &78-&7F 	120-127 	Line fill right to non-foreground §§
plot_lf_r_non_fg: equ 0x78

; &80-&87 	128-135 	Not supported (Flood until non-background)
; &88-&8F 	136-143 	Not supported (Flood until foreground)

; &90-&97 	144-151 	Circle outline
plot_co: equ 0x90

; &98-&9F 	152-159 	Circle fill
plot_cf: equ 0x98

; &A0-&A7 	160-167 	Not supported (Circular arc)
; &A8-&AF 	168-175 	Not supported (Circular segment)
; &B0-&B7 	176-183 	Not supported (Circular sector)

; &B8-&BF 	184-191 	Rectangle copy/move
plot_rcm: equ 0xB8

; &C0-&C7 	192-199 	Not supported (Ellipse outline)
; &C8-&CF 	200-207 	Not supported (Ellipse fill)
; &D0-&D7 	208-215 	Not defined
; &D8-&DF 	216-223 	Not defined
; &E0-&E7 	224-231 	Not defined

; &E8-&EF 	232-239 	Bitmap plot §
plot_bmp: equ 0xE8

; &F0-&F7 	240-247 	Not defined
; &F8-&FF 	248-255 	Not defined

; § Support added in Agon Console8 VDP 2.1.0 §§ Support added in 
; Agon Console8 VDP 2.2.0

; Within each group of eight plot codes, the effects are as follows:
; Plot code 	Effect
; 0 	Move relative
mv_rel: equ 0

; 1 	Plot relative in current foreground colour
dr_rel_fg: equ 1

; 2 	Not supported (Plot relative in logical inverse colour)
; 3 	Plot relative in current background colour
dr_rel_bg: equ 3

; 4 	Move absolute
mv_abs: equ 4

; 5 	Plot absolute in current foreground colour
dr_abs_fg: equ 5

; 6 	Not supported (Plot absolute in logical inverse colour)
; 7 	Plot absolute in current background colour
dr_abs_bg: equ 7

; Codes 0-3 use the position data provided as part of the command 
; as a relative position, adding the position given to the current 
; graphical cursor position. Codes 4-7 use the position data provided 
; as part of the command as an absolute position, setting the current 
; graphical cursor position to the position given.

; Codes 2 and 6 on Acorn systems plot using a logical inverse of the 
; current pixel colour. These operations cannot currently be supported 
; by the graphics system the Agon VDP uses, so these codes are not 
; supported. Support for these codes may be added in a future version 
; of the VDP firmware.

; 16 colour palette constants
c_black: equ 0
c_red_dk: equ 1
c_green_dk: equ 2
c_yellow_dk: equ 3
c_blue_dk: equ 4
c_magenta_dk: equ 5
c_cyan_dk: equ 6
c_grey: equ 7
c_grey_dk: equ 8
c_red: equ 9
c_green: equ 10
c_yellow: equ 11
c_blue: equ 12
c_magenta: equ 13
c_cyan: equ 14
c_white: equ 15

; VDU 25, mode, x; y;: PLOT command
; inputs: a=mode, bc=x0, de=y0
vdu_plot:
    ld (@mode),a
    ld (@x0),bc
    ld (@y0),de
	ld hl,@cmd
	ld bc,@end-@cmd
	rst.lil $18
	ret
@cmd:   db 25
@mode:  db 0
@x0: 	dw 0
@y0: 	dw 0
@end:   db 0 ; extra byte to soak up deu

; https://agonconsole8.github.io/agon-docs/VDP---PLOT-Commands.html
; &E8-&EF 	232-239 	Bitmap plot §
; VDU 25, mode, x; y;: PLOT command
; inputs: bc=x0, de=y0
; prerequisites: vdu_buff_select
vdu_plot_bmp:
    ld (@x0),bc
    ld (@y0),de
	ld hl,@cmd
	ld bc,@end-@cmd
	rst.lil $18
	ret
@cmd:   db 25
@mode:  db plot_bmp+dr_abs_fg ; 0xED
@x0: 	dw 0x0000
@y0: 	dw 0x0000
@end:   db 0x00 ; padding

; https://agonconsole8.github.io/agon-docs/VDP---PLOT-Commands.html
; &E8-&EF 	232-239 	Bitmap plot §
; VDU 25, mode, x; y;: PLOT command
; inputs: bc=x0, de=y0
; USING 16.8 FIXED POINT COORDINATES
; inputs: ub.c is x coordinate, ud.e is y coordinate
;   the fractional portiion of the inputs are truncated
;   leaving only the 16-bit integer portion
; prerequisites: vdu_buff_select
vdu_plot_bmp168:
; populate in the reverse of normal to keep the 
; inputs from stomping on each other
    ld (@y0-1),de
    ld (@x0-1),bc
    ld a,plot_bmp+dr_abs_fg ; 0xED
    ld (@mode),a ; restore the mode byte that got stomped on by bcu
	ld hl,@cmd
	ld bc,@end-@cmd
	rst.lil $18
	ret
@cmd:   db 25
@mode:  db plot_bmp+dr_abs_fg ; 0xED
@x0: 	dw 0x0000
@y0: 	dw 0x0000
@end:  ; no padding required b/c we shifted de right

; draw a filled rectangle
vdu_plot_rf:
    ld (@x0),bc
    ld (@y0),de
    ld (@x1),ix
    ld (@y1),iy
    ld a,25 ; we have to reload the 2nd plot command
    ld (@cmd1),a ; because the 24-bit y0 load stomped on it
	ld hl,@cmd0 
	ld bc,@end-@cmd0 
	rst.lil $18
    ret
@cmd0:  db 25 ; plot
@arg0:  db plot_sl_both+mv_abs
@x0:    dw 0x0000
@y0:    dw 0x0000
@cmd1:  db 25 ; plot
@arg1:  db plot_rf+dr_abs_fg
@x1:    dw 0x0000
@y1:    dw 0x0000
@end:   db 0x00 ; padding

; draw a filled circle
vdu_plot_cf:
    ld (@x0),bc
    ld (@y0),de
    ld (@x1),ix
    ld (@y1),iy
    ld a,25 ; we have to reload the 2nd plot command
    ld (@cmd1),a ; because the 24-bit y0 load stomped on it
	ld hl,@cmd0 
	ld bc,@end-@cmd0 
	rst.lil $18
    ret
@cmd0:  db 25 ; plot
@arg0:  db plot_sl_both+mv_abs
@x0:    dw 0x0000
@y0:    dw 0x0000
@cmd1:  db 25 ; plot
@arg1:  db plot_cf+dr_abs_fg
@x1:    dw 0x0000
@y1:    dw 0x0000
@end:   db 0x00 ; padding


; VDU 23, 27, 4, n: Select sprite n
; inputs: a is the 8-bit sprite id
vdu_sprite_select:
    ld (@sprite),a        
    ld hl,@cmd         
    ld bc,@end-@cmd    
    rst.lil $18         
    ret
@cmd:    db 23,27,4
@sprite: db 0x00
@end:

; VDU 23, 27, 5: Clear frames in current sprite
; inputs: none
; prerequisites: vdu_sprite_select
vdu_sprite_clear_frames:
    ld hl,@cmd         
    ld bc,@end-@cmd    
    rst.lil $18         
    ret
@cmd: db 23,27,5
@end:

; VDU 23, 27, 6, n: Add bitmap n as a frame to current sprite (where bitmap's buffer ID is 64000+n)
; inputs: a is the 8-bit bitmap number
; prerequisites: vdu_sprite_select
vdu_sprite_add_bmp:
    ld (@bmp),a        
    ld hl,@cmd         
    ld bc,@end-@cmd    
    rst.lil $18         
    ret
@cmd: db 23,27,6
@bmp: db 0x00
@end:

; VDU 23, 27, 7, n: Activate n sprites
; inputs: a is the number of sprites to activate
vdu_sprite_activate:
    ld (@num),a        
    ld hl,@cmd         
    ld bc,@end-@cmd    
    rst.lil $18         
    ret
@cmd: db 23,27,7
@num: db 0x00
@end:

; VDU 23, 27, 8: Select next frame of current sprite
; inputs: none
; prerequisites: vdu_sprite_select
vdu_sprite_next_frame:
    ld hl,@cmd         
    ld bc,@end-@cmd    
    rst.lil $18         
    ret
@cmd: db 23,27,8
@end:

; VDU 23, 27, 9: Select previous frame of current sprite
; inputs: none
; prerequisites: vdu_sprite_select
vdu_sprite_prev_frame:
    ld hl,@cmd         
    ld bc,@end-@cmd    
    rst.lil $18         
    ret
@cmd: db 23,27,9
@end:

; VDU 23, 27, 10, n: Select the nth frame of current sprite
; inputs: a is frame number to select
; prerequisites: vdu_sprite_select
vdu_sprite_select_frame:
    ld (@frame),a        
    ld hl,@cmd         
    ld bc,@end-@cmd    
    rst.lil $18         
    ret
@cmd:    db 23,27,10
@frame:  db 0x00
@end:

; VDU 23, 27, 11: Show current sprite
; inputs: none
; prerequisites: vdu_sprite_select
vdu_sprite_show:
    ld hl,@cmd         
    ld bc,@end-@cmd    
    rst.lil $18         
    ret
@cmd: db 23,27,11
@end:

; VDU 23, 27, 12: Hide current sprite
; inputs: none
; prerequisites: vdu_sprite_select
vdu_sprite_hide:
    ld hl,@cmd         
    ld bc,@end-@cmd    
    rst.lil $18         
    ret
@cmd: db 23,27,12
@end:

; VDU 23, 27, 13, x; y;: Move current sprite to pixel position x, y
; inputs: bc is x coordinate, de is y coordinate
; prerequisites: vdu_sprite_select
vdu_sprite_move_abs:
    ld (@xpos),bc
    ld (@ypos),de
    ld hl,@cmd         
    ld bc,@end-@cmd    
    rst.lil $18         
    ret
@cmd:  db 23,27,13
@xpos: dw 0x0000
@ypos: dw 0x0000
@end:  db 0x00 ; padding

; VDU 23, 27, 14, x; y;: Move current sprite by x, y pixels
; inputs: bc is x coordinate, de is y coordinate
; prerequisites: vdu_sprite_select
vdu_sprite_move_rel:
    ld (@dx),bc
    ld (@dy),de
    ld hl,@cmd         
    ld bc,@end-@cmd    
    rst.lil $18         
    ret
@cmd: db 23,27,14
@dx:  dw 0x0000
@dy:  dw 0x0000
@end: db 0x00 ; padding

; VDU 23, 27, 13, x; y;: Move current sprite to pixel position x, y
; USING 16.8 FIXED POINT COORDINATES
; inputs: ub.c is x coordinate, ud.e is y coordinate
;   the fractional portiion of the inputs are truncated
;   leaving only the 16-bit integer portion
; prerequisites: vdu_sprite_select
vdu_sprite_move_abs168:
; populate in the reverse of normal to keep the 
; inputs from stomping on each other
    ld (@ypos-1),de
    ld (@xpos-1),bc
    ld a,13       ; restore the final byte of the command
    ld (@cmd+2),a ; string that got stomped on by bcu
    ld hl,@cmd         
    ld bc,@end-@cmd    
    rst.lil $18         
    ret
@cmd:  db 23,27,13
@xpos: dw 0x0000
@ypos: dw 0x0000
@end:  ; no padding required b/c we shifted de right

; VDU 23, 27, 14, x; y;: Move current sprite by x, y pixels
; USING 16.8 FIXED POINT COORDINATES
; inputs: ub.c is dx, ud.e is dy
;   the fractional portiion of the inputs are truncated
;   leaving only the 16-bit integer portion
; prerequisites: vdu_sprite_select
vdu_sprite_move_rel168:
; populate in the reverse of normal to keep the 
; inputs from stomping on each other
    ld (@dy-1),de
    ld (@dx-1),bc
    ld a,14       ; restore the final byte of the command
    ld (@cmd+2),a ; string that got stomped on by bcu
    ld hl,@cmd         
    ld bc,@end-@cmd    
    rst.lil $18         
    ret
@cmd:  db 23,27,14
@dx: dw 0x0000
@dy: dw 0x0000
@end:  ; no padding required b/c we shifted de right

; VDU 23, 27, 15: Update the sprites in the GPU
; inputs: none
vdu_sprite_update:
    ld hl,@cmd         
    ld bc,@end-@cmd    
    rst.lil $18         
    ret
@cmd: db 23,27,15
@end:

; VDU 23, 27, 16: Reset bitmaps and sprites and clear all data
; inputs: none
vdu_sprite_bmp_reset:
    ld hl,@cmd         
    ld bc,@end-@cmd    
    rst.lil $18         
    ret
@cmd: db 23,27,16
@end:

; VDU 23, 27, 17: Reset sprites (only) and clear all data
; inputs: none
vdu_sprite_reset:
    ld hl,@cmd         
    ld bc,@end-@cmd    
    rst.lil $18         
    ret
@cmd: db 23,27,17
@end:

; VDU 23, 27, 18, n: Set the current sprite GCOL paint mode to n **
; inputs: a is the GCOL paint mode
; prerequisites: vdu_sprite_select
vdu_sprite_set_gcol:
    ld (@mode),a        
    ld hl,@cmd         
    ld bc,@end-@cmd    
    rst.lil $18         
    ret
@cmd:  db 23,27,18
@mode: db 0x00 
@end:

; VDU 23, 27, &26, n;: Add bitmap bufferId 
;     as a frame to current sprite using a 16-bit buffer ID
; inputs: hl=bufferId
; prerequisites: vdu_sprite_select
vdu_sprite_add_buff:
    ld (@bufferId),hl
    ld hl,@cmd         
    ld bc,@end-@cmd    
    rst.lil $18         
    ret
@cmd:      db 23,27,0x26
@bufferId: dw 0x0000
@end:      db 0x00 ; padding
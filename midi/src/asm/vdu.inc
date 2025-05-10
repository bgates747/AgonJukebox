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

; VDU 4: Write text at text cursor
; This causes text to be written at th current text cursor position. This is the default mode for text display.
; inputs: none
; prerequisites: the text cursor at the intended position on screen
; outputs: none
; destroys: af
vdu_text_to_text_cursor:
    ld a,4
    rst.lil $10   
    ret
; end vdu_text_to_text_cursor

; set the text cursor to a specified location and print a string there
; inputs: hl = address of string to print, c,b = x,y text coordinates
; outputs: text
; destroys: af, bc, hl
; affects: moves text cursor to position after final char printed by default
;          unless overridden by VDU 23, 16 cursor control command settings
;          all subsequent print commands (rst.lil $10 or $18) will go to the text cursor
vdu_print_to_text_location:
    push hl ; preserve string pointer
    ld a,4 ; VDU 4 char to text cursor
    rst.lil $10   
    call vdu_move_cursor
    pop hl ; restore string pointer
    call printString
    ret
; end vdu_print_at_text_location

; VDU 5: Write text at graphics cursor
; inputs: none
; prerequisites: the graphics cursor at the intended position on screen
; outputs: none
; destroys: af
vdu_text_to_gfx_cursor:
    ld a,5
	rst.lil $10   
	ret
; end vdu_char_to_gfx_cursor

; set the graphics cursor to a specified location and print a string there
; inputs: hl = address of string to print, bc,de = x,y graphics coordinates
; outputs: text
; destroys: af, bc, de, hl
; affects: moves graphics cursor to position after final char printed by default 
;          unless overridden by setting bit 6 of the cursor control register (VDU 23, 16)
;          all subsequent print commands (rst.lil $10 or $18) will go to the graphics cursor
vdu_print_to_gfx_location:
    push hl ; preserve string pointer
    ld a,plot_pt+mv_abs
    call vdu_plot ; moves the graphics cursor to the specified location
    ld a,5 ; VDU 5 char to gfx cursor
    rst.lil $10 
    pop hl ; restore string pointer
    ld bc,0
    ld a,0
    rst.lil $18 ; print the string
    ret
; end vdu_print_at_gfx_location

; VDU 8: Move cursor back one character
vdu_cursor_back:
    ld a,8
    rst.lil $10  
    ret
; end vdu_cursor_back

; VDU 9: Move cursor forward one character
vdu_cursor_forward:
    ld a,9
	rst.lil $10  
	ret
; end vdu_cursor_forward

; VDU 10: Move cursor down one line
vdu_cursor_down:
    ld a,10
    rst.lil $10  
    ret
; end vdu_cursor_down

; VDU 11: Move cursor up one line
vdu_cursor_up:
    ld a,11
    rst.lil $10  
    ret
; end vdu_cursor_up


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

vdu_flip:       
	ld hl,@cmd         
	ld bc,@end-@cmd    
	rst.lil $18         
	ret
@cmd: db 23,0,0xC3
@end:

; VDU 16: Clear graphics area (CLG)
vdu_clg:
    ld a,16
	rst.lil $10  
	ret

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

; VDU 18, mode, colour: Set graphics colour (GCOL mode, colour)
; inputs: a=mode, c=colour (add 128 to set background colour)
vdu_gcol:
	ld (@mode),a
    ld a,c
    ld (@col),a   
	ld hl,@cmd         
	ld bc,@end-@cmd    
	rst.lil $18         
	ret
@cmd:  db 18
@mode: db 0
@col:  db 0 
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

; VDU 29, x; y;: Set graphics origin
; This command sets the graphics origin. 
; The origin is the point on the screen where the coordinates (0,0) are located.
; inputs: bc=x0,de=y0
; outputs; nothing
; destroys: a might make it out alive
vdu_set_gfx_origin:
    ld (@x0),bc
    ld (@y0),de
    ld hl,@cmd
    ld bc,@end-@cmd
    rst.lil $18
    ret
@cmd:   db 29 ; set graphics origin command
@x0: 	dw 0x0000 ; set by bc
@y0: 	dw 0x0000 ; set by de
@end:   db 0x00	  ; padding

; VDU 24, left; bottom; right; top;: Set graphics viewport 
; NOTE: the order of the y-coordinate parameters are inverted
; 	because we have turned off logical screen scaling
; NOTE: coordinates are relative to current gfx origin
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

; load an rgba2222 image file to a working buffer and make it an rgba8888 bitmap in a target buffer
; inputs: bc,de image width,height ; hl = targetBufferId ; ix = file size ; iy = pointer to filename
vdu_load_img_rgba2_to_8:
; backup the target buffer id and image dimensions
    push hl
    push de
    push bc
; load the rgba2 image to working buffer 65534
    ld hl,65534 ; temporary working buffer id
	call vdu_load_buffer_from_file
; restore the image dimensions and target buffer id
    pop bc
    pop de
    pop hl
; fall through to vdu_rgba2_to_8

; https://discord.com/channels/1158535358624039014/1158536711148675072/1257757461729771771
; ok, so the "expand bitmap" can be used, when coupled with a "reverse" - the expanded bitmap _doesn't_ come out "right" otherwise, cos of endian-ness
; the "expand bitmap" command is:
; VDU 23,0,&A0,targetBufferID%;&48,2,sourceBufferId%;0,&7F,&BF,&FF
; and then to reverse the byte order to fix endian-ness:
; VDU 23,0,&A0,targetBufferID%;24,4,4;
; finally you'd need to set that buffer to be an RGBA8888 format bitmap:
; VDU 23,27,&20,targetBufferID%;
; VDU 23,27,&21,width%;height%;0
; -------------------------------------------------------------------
; inputs: bc,de image width,height ; hl = targetBufferId
; prerequisites: rgba2 image data loaded into workingBufferId 65534
vdu_rgba2_to_8:
; load the image dimensions and buffer id parameters
    ld (@width),bc
    ld (@height),de
    ld (@bufferId0),hl
    ld (@bufferId2),hl
    ld (@bufferId1),hl
; clean up bytes that got stomped on by the ID loads
    ld a,0x48
    ld (@bufferId0+2),a
    ld a,23
    ld (@bufferId1+2),a
    ld a,24
    ld (@bufferId2+2),a
    xor a
    ld (@height+2),a
; send the vdu command strings
    ld hl,@beg
    ld bc,@end-@beg
    rst.lil $18
    ret
@beg:
; Command 14: Consolidate blocks in a buffer
; VDU 23, 0, &A0, bufferId; 14
    db 23,0,0xA0
    dw 65534 ; workingBufferId
    db 14 ; consolidate blocks
; the "expand bitmap" command is:
; VDU 23,0,&A0,targetBufferID%;&48,2,sourceBufferId%;0,&7F,&BF,&FF
    db 23,0,0xA0
@bufferId0: dw 0x0000 ; targetBufferId
    db 0x48 ; given as decimal command 72 in the docs
    db 2 ; options mask: %00000011 is the number of bits per pixel in the source bitmap
    dw 65534 ; sourceBufferId
    db 0x00,0x7F,0xBF,0xFF ; expanding to bytes by bit-shifting?
; reverse the byte order to fix endian-ness:
; Command 24: Reverse the order of data of blocks within a buffer
; VDU 23, 0, &A0, bufferId; 24, options, [valueSize;] [chunkSize;]
; VDU 23,0,&A0,targetBufferID%;24,4,4;
    db 23,0,0xA0
@bufferId2:    dw 0x0000 ; targetBufferId
    db 24 ; reverse byte order
    db 4 ; option: Reverse data of the value size within chunk of data of the specified size
    dw 4 ; size (4 bytes)
; finally you'd need to set that buffer to be an RGBA8888 format bitmap:
; VDU 23,27,&20,targetBufferID%;
    db 23,27,0x20 ; select bitmap
@bufferId1: dw 0x0000 ; targetBufferId
; VDU 23,27,&21,width%;height%;0
    db 23,27,0x21 ; create bitmap from buffer
@width: dw 0x0000
@height: dw 0x0000
    db 0x00 ; rgba8888 format
@end:

; scratch variables 
bufferId0: dl 0x000000
bufferId1: dl 0x000000

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

; load an image file to a buffer and make it a bitmap
; inputs: a = image format ; bc,de image width,height ; hl = bufferId ; iy = pointer to filename
; formats: https://agonconsole8.github.io/agon-docs/VDP---Bitmaps-API.html
; 0 	RGBA8888 (4-bytes per pixel)
; 1 	RGBA2222 (1-bytes per pixel)
; 2 	Mono/Mask (1-bit per pixel)
; 3 	Reserved for internal use by VDP (“native” format)
vdu_load_img:
; back up image type and dimension parameters
    ld (bufferId0),hl
    push af
	push bc
	push de
; load the image
	call vdu_load_buffer_from_file
; now make it a bitmap
    ld hl,(bufferId0)
    call vdu_consolidate_buffer
    ld hl,(bufferId0)
    call vdu_buff_select
	pop de ; image height
	pop bc ; image width
	pop af ; image type
	jp vdu_bmp_create ; will return to caller from there

; inputs: hl = bufferId; iy = pointer to filename
vdu_load_buffer_from_file:
    ld (bufferId0),hl

; clear target buffer
    call vdu_clear_buffer

; open the file in read mode
; Open a file
; HLU: Filename
;   C: Mode
; Returns:
;   A: Filehandle, or 0 if couldn't open
	push iy ; pointer to filename
	pop hl
	ld c,fa_read
    MOSCALL mos_fopen
    ld (@filehandle),a

@read_file:
; Read a block of data from a file
;   C: Filehandle
; HLU: Pointer to where to write the data to
; DEU: Number of bytes to read
; Returns:
; DEU: Number of bytes read
    ld a,(@filehandle)
    ld c,a
    ld hl,filedata
    ld de,8192 ; max we can read into onboard sram at one time
    MOSCALL mos_fread

; test de for zero bytes read
    ld hl,0
    xor a ; clear carry
    sbc hl,de
    jp z,@close_file

; load a vdu buffer from local memory
; inputs: hl = bufferId ; bc = length ; de = pointer to data
    ld hl,(bufferId0)
    push de ; chunksize
    pop bc
    ld de,filedata
    call vdu_load_buffer

; read the next block
    jp @read_file

; close the file
@close_file:
    ld a,(@filehandle)
    MOSCALL mos_fclose
    ret ; vdu_load_buffer_from_file

@filehandle: db 0 ; file handle
@fil: dl 0 ; pointer to FIL struct

@chunkpointer: dl 0 ; pointer to current chunk

; File information structure (FILINFO)
@filinfo:
@filinfo_fsize:    blkb 4, 0   ; File size (4 bytes)
@filinfo_fdate:    blkb 2, 0   ; Modified date (2 bytes)
@filinfo_ftime:    blkb 2, 0   ; Modified time (2 bytes)
@filinfo_fattrib:  blkb 1, 0   ; File attribute (1 byte)
@filinfo_altname:  blkb 13, 0  ; Alternative file name (13 bytes)
@filinfo_fname:    blkb 256, 0 ; Primary file name (256 bytes)
; ; https://github.com/AgonConsole8/agon-docs/blob/main/VDP---Bitmaps-API.md
; the VDP can support up to 256 sprites. They must be defined 
; contiguously, and so the first sprite is sprite 0. 
; (In contrast, bitmaps can have any ID from 0 to 65534.) 
; Once a selection of sprites have been defined, you can activate 
; them using the VDU 23, 27, 7, n command, where n is the number 
; of sprites to activate. This will activate the first n sprites, 
; starting with sprite 0. All sprites from 0 to n-1 must be defined.

; A single sprite can have multiple "frames", referring to 
; different bitmaps. 
; (These bitmaps do not need to be the same size.) 
; This allows a sprite to include an animation sequence, 
; which can be stepped through one frame at a time, or picked 
; in any order.

; Any format of bitmap can be used as a sprite frame. It should 
; be noted however that "native" format bitmaps are not 
; recommended for use as sprite frames, as they cannot get 
; erased from the screen. (As noted above, the "native" bitmap 
; format is not really intended for general use.) This is part 
; of why from Agon Console8 VDP 2.6.0 bitmaps captured from the 
; screen are now stored in RGBA2222 format.

; An "active" sprite can be hidden, so it will stop being drawn, 
; and then later shown again.

; Moving sprites around the screen is done by changing the 
; position of the sprite. This can be done either by setting 
; the absolute position of the sprite, or by moving the sprite 
; by a given number of pixels. (Sprites are positioned using 
; pixel coordinates, and not by the logical OS coordinate system.) 
; In the current sprite system, sprites will not update their 
; position on-screen until either another drawing operation is 
; performed or an explicit VDU 23, 27, 15 command is performed.

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
; prerequisites: each sprite activated must have at least one frame attached to it
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
; offset inputs by the gfx origin
; y coordinate
    ld hl,origin_top*256
    add hl,de
    ld (@ypos-1),hl
; x coordinate
    ld hl,origin_left*256
    add hl,bc
    ld (@xpos-1),hl
; prepare vdu command
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

; VDU 23, 27, &26, n;: Add bitmap n as a frame to current sprite using a 16-bit buffer ID
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
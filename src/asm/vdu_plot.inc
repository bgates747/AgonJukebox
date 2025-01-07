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
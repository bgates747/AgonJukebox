; Bitmap indices:
BUF_UI_LOGO: equ 0x2000

; Import .rgba2 bitmap files and load them into VDP buffers
load_ui_images:

	ld hl,F_UI_logo
	ld de,filedata
	ld bc,65536
	ld a,mos_load
	RST.LIL 08h
	ld hl,BUF_UI_LOGO
	ld bc,80
	ld de,120
	ld ix,9600
	call vdu_load_img
	LD A, '.'
	RST.LIL 10h

	ret

F_UI_logo: db "ui/logo.rgba2",0

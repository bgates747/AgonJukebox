; Bitmap indices:
BUF_UI_LOGO: equ 0x2000

; Import .rgba2 bitmap files and load them into VDP buffers
load_ui_images:
; load a vdu buffer from local memory
    ld hl,BUF_UI_LOGO
    ld de,F_UI_logo
    ld bc,F_UI_logo_end-F_UI_logo
    call vdu_load_buffer
; now make it a bitmap
	ld hl,BUF_UI_LOGO
    call vdu_consolidate_buffer
	ld hl,BUF_UI_LOGO
    call vdu_buff_select
	ld bc,80
	ld de,120
	ld a,1 ; image type 1 = rgba2222
	jp vdu_bmp_create

F_UI_logo: 
    incbin "../images/logo.rgba2"
F_UI_logo_end:

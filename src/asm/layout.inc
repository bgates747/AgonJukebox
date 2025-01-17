text_top: equ 0
text_left: equ 0
text_bottom: equ 47      ; 48 rows, zero-based
text_right: equ 63       ; 64 columns, zero-based

original_screen_mode: db 0 ; screen mode when app started so we can return to it on exit

str_dashes_thin: asciz  "----------------------------------------------------------------"
str_dashes_thick: asciz "================================================================"

; set text viewport for current playing song
vp_now_playing_top: equ 34
vp_now_playing:
    ld c, text_left
    ld d, vp_now_playing_top
    ld e, text_right
    ld b, vp_now_playing_top
    call vdu_set_txt_viewport
    ret
; end vp_now_playing

; set text viewport for elapsed time
vp_elapsed_top: equ vp_now_playing_top+1
vp_elapsed_right: equ text_left+7 ; 8 chars for HH:MM:SS
vp_elapsed:
    ld c, text_left
    ld d, vp_elapsed_top
    ld e, vp_elapsed_right
    ld b, vp_elapsed_top
    call vdu_set_txt_viewport
    ret
; end vp_elapsed

; set text viewport for song duration
vp_duration_left: equ text_right-7 ; 8 chars for HH:MM:SS
vp_duration_top: equ vp_now_playing_top+1
vp_duration:
    ld c, vp_duration_left
    ld d, vp_duration_top
    ld e, text_right
    ld b, vp_duration_top
    call vdu_set_txt_viewport
    ret
; end vp_duration

; set text viewport for playing breadcrumbs
vp_playhead_left: equ vp_elapsed_right+1 ; leave room for left arrow
vp_playhead_top: equ vp_now_playing_top+1
vp_playhead_right: equ vp_duration_left-1 ; leave room for right arrow
vp_playhead:
    ld c, vp_playhead_left
    ld d, vp_playhead_top
    ld e, vp_playhead_right
    ld b, vp_playhead_top
    call vdu_set_txt_viewport
    ret
; end vp_playhead

vp_dir_hdr_top: equ 20
vp_dir_hdr:
    ld c,text_left
    ld d,vp_dir_hdr_top
    ld e,text_right
    ld b,vp_dir_hdr_top
    call vdu_set_txt_viewport
    ret

vp_dir_name_top: equ vp_dir_hdr_top+1
vp_dir_name:
    ld c,text_left
    ld d,vp_dir_name_top
    ld e,text_right
    ld b,vp_dir_name_top
    call vdu_set_txt_viewport
    ret

; set text viewport for directory listing
vp_dir_top: equ vp_dir_hdr_top+3
vp_dir_bottom: equ vp_dir_top+9
vp_dir:
    ld c,text_left
    ld d,vp_dir_top
    ld e,text_right
    ld b,vp_dir_bottom
    call vdu_set_txt_viewport
    ret

vp_legend_top: equ vp_playhead_top+2
vp_legend:
    ld c,text_left
    ld d,vp_legend_top
    ld e,text_right
    ld b,vp_legend_top+2
    call vdu_set_txt_viewport
    ret

vp_legend_shuffle_top: equ vp_legend_top+1
vp_legend_shuffle_left: equ text_left+33
vp_legend_shuffle:
    ld c,vp_legend_shuffle_left
    ld d,vp_legend_shuffle_top
    ld e,vp_legend_shuffle_left+2
    ld b,vp_legend_shuffle_top
    call vdu_set_txt_viewport
    ret

vp_legend_loop_top: equ vp_legend_top+1
vp_legend_loop_left: equ text_left+51
vp_legend_loop:
    ld c,vp_legend_loop_left
    ld d,vp_legend_loop_top
    ld e,vp_legend_loop_left+2
    ld b,vp_legend_loop_top
    call vdu_set_txt_viewport
    ret

vp_messages_top: equ vp_playhead_top+6
vp_messages_bottom: equ text_bottom
; set text viewport for messages
vp_messages:
    ld c,text_left
    ld d,vp_messages_top
    ld e,text_right
    ld b,vp_messages_bottom
    call vdu_set_txt_viewport
    ret

set_text_colours_normal:
; set text background color
    ld a,c_blue_dk+128
    call vdu_colour_text
; set text foreground color
    ld a,c_white
    call vdu_colour_text
    ret
; end set_text_colours_normal

set_text_colours_inverse:
; set text background color
    ld a,c_white+128
    call vdu_colour_text
; set text foreground color
    ld a,c_blue_dk
    call vdu_colour_text
    ret
; end set_text_colours_inverse

ui_init:
; get current screen mode and save it so we can return to it on exit
    call vdu_get_screen_mode
    ld (original_screen_mode),a
; set up display
    ld a,20 ; 512x384x64 single-buffered
    call vdu_set_screen_mode
    xor a
    call vdu_set_scaling
; load fonts and select one
    call vdu_clear_all_buffers
	call fonts_load
    ld hl,Lat2_VGA8_8x8
    ld a,1
    call vdu_font_select
; set text fg and bg colours to normal
    call set_text_colours_normal
; set cursor behaviuor
    call vdu_cursor_off
    ld h,%00010000 ; bit 4 controls cursor scroll at bottom of screen
    ld l,%00010000 ; bit 4 set means cursor wraps to top of screen
    call vdu_cursor_behaviour
; reset text viewports and clear the screen
    call vdu_reset_viewports
    call vdu_cls

; tippy top border
    ld c,text_left ; x
    ld b,text_top ; y
    call vdu_move_cursor
    ld hl,str_dashes_thick
    call printString

; print ascii art splash screen
    ld c,text_left ; x
    ld b,text_top+1 ; y
    call vdu_move_cursor
    ld hl,agon_jukebox_ascii
    call printString

; below logo border
    ld c,text_left ; x
    ld b,vp_dir_hdr_top-1 ; y
    call vdu_move_cursor
    ld hl,str_dashes_thick
    call printString

; print the directory header
    ld c,text_left ; x
    ld b,vp_dir_hdr_top ; y
    call vdu_move_cursor
    call printInline
    asciz "Our current directory is:"

; file list top border
    ld c,text_left ; x
    ld b,vp_dir_top-1 ; y
    call vdu_move_cursor
    ld hl,str_dashes_thin
    call printString

; file list bottom border
    ld c,text_left ; x
    ld b,vp_dir_bottom+1 ; y
    call vdu_move_cursor
    ld hl,str_dashes_thin
    call printString

; below the breadcrumbs border
    ld c,text_left ; x
    ld b,vp_playhead_top+1 ; y
    call vdu_move_cursor
    ld hl,str_dashes_thick
    call printString

; print the navigation and song control instructions
    ld c,text_left ; x
    ld b,vp_playhead_top+2 ; y
    call vdu_move_cursor
    call printInline
    db " Song \e",24," \e",25," or 0-9    | Page \e",27," \e",26,"           | [U]p directory\r\n"
    db " [R]andom song      | [S]huffle: OFF     | [L]oop: OFF\r\n"
    db " [ESC] or [Q]uit    |                    |\r\n"
    db 0 ; null terminator

; below the detailed instructions / status border
    ld c,text_left ; x
    ld b,vp_playhead_top+5 ; y
    call vdu_move_cursor
    ld hl,str_dashes_thick
    call printString
    
    ret
; end ui_init
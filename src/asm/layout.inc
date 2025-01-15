text_top: equ 0
text_left: equ 0
text_bottom: equ 47      ; 48 rows, zero-based
text_right: equ 63       ; 64 columns, zero-based

; set text viewport for current playing song
vp_now_playing_left: equ text_left
vp_now_playing_top: equ 34
vp_now_playing_right: equ text_right
vp_now_playing_bottom: equ vp_now_playing_top+1

vp_now_playing:
    ld c, vp_now_playing_left
    ld d, vp_now_playing_top
    ld e, vp_now_playing_right
    ld b, vp_now_playing_bottom
    call vdu_set_txt_viewport
    ret
; end vp_now_playing

; set text viewport for playing breadcrumbs
vp_breadcrumbs_left: equ text_left
vp_breadcrumbs_top: equ vp_now_playing_bottom
vp_breadcrumbs_right: equ text_right
vp_breadcrumbs_bottom: equ vp_breadcrumbs_top

vp_breadcrumbs:
    ld c, vp_breadcrumbs_left
    ld d, vp_breadcrumbs_top
    ld e, vp_breadcrumbs_right
    ld b, vp_breadcrumbs_bottom
    call vdu_set_txt_viewport
    ret
; end vp_breadcrumbs

vp_dir_hdr_left: equ text_left
vp_dir_hdr_top: equ 19
vp_dir_hdr_right: equ text_right
vp_dir_hdr_bottom: equ vp_dir_hdr_top
vp_dir_hdr:
    ld c,vp_dir_hdr_left
    ld d,vp_dir_hdr_top
    ld e,vp_dir_hdr_right
    ld b,vp_dir_hdr_bottom
    call vdu_set_txt_viewport
    ret

vp_dir_name_left: equ text_left
vp_dir_name_top: equ vp_dir_hdr_top+1
vp_dir_name_right: equ text_right
vp_dir_name_bottom: equ vp_dir_name_top
vp_dir_name:
    ld c,vp_dir_name_left
    ld d,vp_dir_name_top
    ld e,vp_dir_name_right
    ld b,vp_dir_name_bottom
    call vdu_set_txt_viewport
    ret

; set text viewport for directory listing
vp_dir_left: equ text_left
vp_dir_top: equ vp_dir_hdr_top+4
vp_dir_right: equ text_right
vp_dir_bottom: equ vp_dir_top+9
vp_dir:
    ld c,vp_dir_left
    ld d,vp_dir_top
    ld e,vp_dir_right
    ld b,vp_dir_bottom
    call vdu_set_txt_viewport
    ret

vp_messages_left: equ text_left
vp_messages_top: equ vp_dir_bottom+1
vp_messages_right: equ text_right
vp_messages_bottom: equ text_bottom
; set text viewport for messages
vp_messages:
    ld c,vp_messages_left
    ld d,vp_messages_top
    ld e,vp_messages_right
    ld b,vp_messages_bottom
    call vdu_set_txt_viewport
    ret

ui_init:
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

; print the directory header
    ld c,vp_dir_hdr_left ; x
    ld b,vp_dir_hdr_top ; y
    call vdu_move_cursor
    call printInline
    asciz "Page 1 of n in directory:"

; print play song instructions
    ld c,text_left ; x
    ld b,vp_dir_hdr_bottom+2
    call vdu_move_cursor
    call printInline
    asciz "Press keys 0-9 to play a song or enter directory:"

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
    ld b,vp_breadcrumbs_bottom+1 ; y
    call vdu_move_cursor
    ld hl,str_dashes_thin
    call printString

; print the navigation and song control instructions
    ld c,text_left ; x
    ld b,vp_breadcrumbs_bottom+2 ; y
    call vdu_move_cursor
    call printInline
    db "Song \e",24," \e",25," space  | Page [ ]        | (D)ir up\r\n"
    db "(S)huffle: OFF  | (L)oop: OFF\r\n"
    db "(R)andom song   | [ESC] or (Q)uit\r\n"
    db 0 ; null terminator

; below the detailed instructions / status border
    ld c,text_left ; x
    ld b,vp_breadcrumbs_bottom+5 ; y
    call vdu_move_cursor
    ld hl,str_dashes_thick
    call printString
    
    ret
; end ui_init
text_right: equ 63       ; 64 columns, zero-based
text_bottom: equ 47      ; 48 rows, zero-based

; set text viewport for current playing song
vp_now_playing_left: equ 0
vp_now_playing_top: equ 0
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
vp_breadcrumbs_left: equ 0
vp_breadcrumbs_top: equ 1
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

; set text viewport for directory listing
vp_dir_left: equ 0
vp_dir_top: equ 30
vp_dir_right: equ text_right
vp_dir_bottom: equ vp_dir_top+10
vp_dir:
    ld c,vp_dir_left
    ld d,vp_dir_top
    ld e,vp_dir_right
    ld b,vp_dir_bottom
    call vdu_set_txt_viewport
    ret

; print bottom border of directory listing
print_dir_border_bottom:
    ld c,vp_dir_left
    ld d,vp_dir_bottom
    ld e,text_right
    ld b,vp_dir_bottom
    call vdu_set_txt_viewport
    ld hl,str_thick_dashes
    call printString
    ret
; end vp_dir_border

vp_messages_left: equ 0
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
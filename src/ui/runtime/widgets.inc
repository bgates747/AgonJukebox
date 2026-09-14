; Generated fixed slots; runtime geometry is read from layout.bin.
w_path: blkb 96,32
w_path_size: dl 0
w_path_len: equ 0
w_path_context: equ w_path+4
w_path_bg: equ w_path+14
w_path_fg: equ w_path+29
w_path_text: equ w_path+36
w_path_digits: equ w_path+36
w_path_send:
    ld hl,w_path
    ld bc,(w_path_size)
    ld a,b
    or c
    ret z
    jp ui_send
w_page: blkb 96,32
w_page_size: dl 0
w_page_len: equ 0
w_page_context: equ w_page+4
w_page_bg: equ w_page+14
w_page_fg: equ w_page+29
w_page_text: equ w_page+36
w_page_digits: equ w_page+36
w_page_send:
    ld hl,w_page
    ld bc,(w_page_size)
    ld a,b
    or c
    ret z
    jp ui_send
w_count: blkb 96,32
w_count_size: dl 0
w_count_len: equ 0
w_count_context: equ w_count+4
w_count_bg: equ w_count+14
w_count_fg: equ w_count+29
w_count_text: equ w_count+36
w_count_digits: equ w_count+36
w_count_send:
    ld hl,w_count
    ld bc,(w_count_size)
    ld a,b
    or c
    ret z
    jp ui_send
w_row0: blkb 96,32
w_row0_size: dl 0
w_row0_len: equ 94
w_row0_context: equ w_row0+4
w_row0_bg: equ w_row0+14
w_row0_fg: equ w_row0+29
w_row0_text: equ w_row0+36
w_row0_digits: equ w_row0+36
w_row0_send:
    ld hl,w_row0
    ld bc,(w_row0_size)
    ld a,b
    or c
    ret z
    jp ui_send
w_row1: blkb 96,32
w_row1_size: dl 0
w_row1_len: equ 94
w_row1_context: equ w_row1+4
w_row1_bg: equ w_row1+14
w_row1_fg: equ w_row1+29
w_row1_text: equ w_row1+36
w_row1_digits: equ w_row1+36
w_row1_send:
    ld hl,w_row1
    ld bc,(w_row1_size)
    ld a,b
    or c
    ret z
    jp ui_send
w_row2: blkb 96,32
w_row2_size: dl 0
w_row2_len: equ 94
w_row2_context: equ w_row2+4
w_row2_bg: equ w_row2+14
w_row2_fg: equ w_row2+29
w_row2_text: equ w_row2+36
w_row2_digits: equ w_row2+36
w_row2_send:
    ld hl,w_row2
    ld bc,(w_row2_size)
    ld a,b
    or c
    ret z
    jp ui_send
w_row3: blkb 96,32
w_row3_size: dl 0
w_row3_len: equ 94
w_row3_context: equ w_row3+4
w_row3_bg: equ w_row3+14
w_row3_fg: equ w_row3+29
w_row3_text: equ w_row3+36
w_row3_digits: equ w_row3+36
w_row3_send:
    ld hl,w_row3
    ld bc,(w_row3_size)
    ld a,b
    or c
    ret z
    jp ui_send
w_row4: blkb 96,32
w_row4_size: dl 0
w_row4_len: equ 94
w_row4_context: equ w_row4+4
w_row4_bg: equ w_row4+14
w_row4_fg: equ w_row4+29
w_row4_text: equ w_row4+36
w_row4_digits: equ w_row4+36
w_row4_send:
    ld hl,w_row4
    ld bc,(w_row4_size)
    ld a,b
    or c
    ret z
    jp ui_send
w_row5: blkb 96,32
w_row5_size: dl 0
w_row5_len: equ 94
w_row5_context: equ w_row5+4
w_row5_bg: equ w_row5+14
w_row5_fg: equ w_row5+29
w_row5_text: equ w_row5+36
w_row5_digits: equ w_row5+36
w_row5_send:
    ld hl,w_row5
    ld bc,(w_row5_size)
    ld a,b
    or c
    ret z
    jp ui_send
w_row6: blkb 96,32
w_row6_size: dl 0
w_row6_len: equ 94
w_row6_context: equ w_row6+4
w_row6_bg: equ w_row6+14
w_row6_fg: equ w_row6+29
w_row6_text: equ w_row6+36
w_row6_digits: equ w_row6+36
w_row6_send:
    ld hl,w_row6
    ld bc,(w_row6_size)
    ld a,b
    or c
    ret z
    jp ui_send
w_row7: blkb 96,32
w_row7_size: dl 0
w_row7_len: equ 94
w_row7_context: equ w_row7+4
w_row7_bg: equ w_row7+14
w_row7_fg: equ w_row7+29
w_row7_text: equ w_row7+36
w_row7_digits: equ w_row7+36
w_row7_send:
    ld hl,w_row7
    ld bc,(w_row7_size)
    ld a,b
    or c
    ret z
    jp ui_send
w_row8: blkb 96,32
w_row8_size: dl 0
w_row8_len: equ 94
w_row8_context: equ w_row8+4
w_row8_bg: equ w_row8+14
w_row8_fg: equ w_row8+29
w_row8_text: equ w_row8+36
w_row8_digits: equ w_row8+36
w_row8_send:
    ld hl,w_row8
    ld bc,(w_row8_size)
    ld a,b
    or c
    ret z
    jp ui_send
w_row9: blkb 96,32
w_row9_size: dl 0
w_row9_len: equ 94
w_row9_context: equ w_row9+4
w_row9_bg: equ w_row9+14
w_row9_fg: equ w_row9+29
w_row9_text: equ w_row9+36
w_row9_digits: equ w_row9+36
w_row9_send:
    ld hl,w_row9
    ld bc,(w_row9_size)
    ld a,b
    or c
    ret z
    jp ui_send
w_message: blkb 96,32
w_message_size: dl 0
w_message_len: equ 0
w_message_context: equ w_message+4
w_message_bg: equ w_message+14
w_message_fg: equ w_message+29
w_message_text: equ w_message+36
w_message_digits: equ w_message+36
w_message_send:
    ld hl,w_message
    ld bc,(w_message_size)
    ld a,b
    or c
    ret z
    jp ui_send
w_track: blkb 96,32
w_track_size: dl 0
w_track_len: equ 0
w_track_context: equ w_track+4
w_track_bg: equ w_track+14
w_track_fg: equ w_track+29
w_track_text: equ w_track+36
w_track_digits: equ w_track+36
w_track_send:
    ld hl,w_track
    ld bc,(w_track_size)
    ld a,b
    or c
    ret z
    jp ui_send
w_elapsed: blkb 96,32
w_elapsed_size: dl 0
w_elapsed_len: equ 0
w_elapsed_context: equ w_elapsed+4
w_elapsed_bg: equ w_elapsed+14
w_elapsed_fg: equ w_elapsed+29
w_elapsed_text: equ w_elapsed+36
w_elapsed_digits: equ w_elapsed+36
w_elapsed_send:
    ld hl,w_elapsed
    ld bc,(w_elapsed_size)
    ld a,b
    or c
    ret z
    jp ui_send
w_duration: blkb 96,32
w_duration_size: dl 0
w_duration_len: equ 0
w_duration_context: equ w_duration+4
w_duration_bg: equ w_duration+14
w_duration_fg: equ w_duration+29
w_duration_text: equ w_duration+36
w_duration_digits: equ w_duration+36
w_duration_send:
    ld hl,w_duration
    ld bc,(w_duration_size)
    ld a,b
    or c
    ret z
    jp ui_send
w_detail: blkb 96,32
w_detail_size: dl 0
w_detail_len: equ 0
w_detail_context: equ w_detail+4
w_detail_bg: equ w_detail+14
w_detail_fg: equ w_detail+29
w_detail_text: equ w_detail+36
w_detail_digits: equ w_detail+36
w_detail_send:
    ld hl,w_detail
    ld bc,(w_detail_size)
    ld a,b
    or c
    ret z
    jp ui_send
w_voltext: blkb 96,32
w_voltext_size: dl 0
w_voltext_len: equ 0
w_voltext_context: equ w_voltext+4
w_voltext_bg: equ w_voltext+14
w_voltext_fg: equ w_voltext+29
w_voltext_text: equ w_voltext+36
w_voltext_digits: equ w_voltext+36
w_voltext_send:
    ld hl,w_voltext
    ld bc,(w_voltext_size)
    ld a,b
    or c
    ret z
    jp ui_send
w_play: blkb 96,32
w_play_size: dl 0
w_play_len: equ 0
w_play_x: equ w_play+7
w_play_code: equ w_play+11
w_play_send:
    ld hl,w_play
    ld bc,(w_play_size)
    ld a,b
    or c
    ret z
    jp ui_send
w_shuffle: blkb 96,32
w_shuffle_size: dl 0
w_shuffle_len: equ 0
w_shuffle_x: equ w_shuffle+7
w_shuffle_code: equ w_shuffle+11
w_shuffle_send:
    ld hl,w_shuffle
    ld bc,(w_shuffle_size)
    ld a,b
    or c
    ret z
    jp ui_send
w_loop: blkb 96,32
w_loop_size: dl 0
w_loop_len: equ 0
w_loop_x: equ w_loop+7
w_loop_code: equ w_loop+11
w_loop_send:
    ld hl,w_loop
    ld bc,(w_loop_size)
    ld a,b
    or c
    ret z
    jp ui_send
w_volume: blkb 96,32
w_volume_size: dl 0
w_volume_len: equ 0
w_volume_x: equ w_volume+7
w_volume_code: equ w_volume+11
w_volume_send:
    ld hl,w_volume
    ld bc,(w_volume_size)
    ld a,b
    or c
    ret z
    jp ui_send
w_progress: blkb 96,32
w_progress_size: dl 0
w_progress_len: equ 0
w_progress_x: equ w_progress+7
w_progress_code: equ w_progress+11
w_progress_send:
    ld hl,w_progress
    ld bc,(w_progress_size)
    ld a,b
    or c
    ret z
    jp ui_send
w_marker: blkb 96,32
w_marker_size: dl 0
w_marker_len: equ 0
w_marker_x: equ w_marker+7
w_marker_code: equ w_marker+11
w_marker_send:
    ld hl,w_marker
    ld bc,(w_marker_size)
    ld a,b
    or c
    ret z
    jp ui_send
rt_widget_table:
    dl w_path
    dl w_page
    dl w_count
    dl w_row0
    dl w_row1
    dl w_row2
    dl w_row3
    dl w_row4
    dl w_row5
    dl w_row6
    dl w_row7
    dl w_row8
    dl w_row9
    dl w_message
    dl w_track
    dl w_elapsed
    dl w_duration
    dl w_detail
    dl w_voltext
    dl w_play
    dl w_shuffle
    dl w_loop
    dl w_volume
    dl w_progress
    dl w_marker
ui_rows:
    dl w_row0,w_row0_text
    dl w_row1,w_row1_text
    dl w_row2,w_row2_text
    dl w_row3,w_row3_text
    dl w_row4,w_row4_text
    dl w_row5,w_row5_text
    dl w_row6,w_row6_text
    dl w_row7,w_row7_text
    dl w_row8,w_row8_text
    dl w_row9,w_row9_text
w_hint_text: blkb 15,32
w_hint_send: ret
w_mode_code: db 0
w_mode_send: ret
w_thumb_x: dw 0
w_thumb_send: ret
ui_volume_x: blkb 12,0
ui_volume_codes: db 135,136,137,138,139,140,141,142,143,144,145,146
ui_selection_y: blkb 10,0
sa_image_meta: blkb 2354,0
ui_static: blkb 2200,0
rt_static_len: dl 0
rt_descriptor: blkb rt_size,0
rt_progress_origin: dl 0
rt_image_count: equ rt_descriptor+8
rt_path_columns: equ rt_descriptor+9
rt_track_columns: equ rt_descriptor+10
rt_filename_offset: equ rt_descriptor+11
rt_filename_columns: equ rt_descriptor+12
rt_duration_offset: equ rt_descriptor+13
rt_pointer_enabled: equ rt_descriptor+14
rt_normal_bg_value: equ rt_descriptor+15
rt_normal_fg: equ rt_descriptor+16
rt_selected_bg: equ rt_descriptor+17
rt_selected_fg: equ rt_descriptor+18
rt_progress_span: equ rt_descriptor+19
rt_text_template: db 23,0,200,0,1,23,0,149,0,240,33,0,18,0,0,25,4,0,0,0,0,25,101,0,0,0,0,18,0,0,25,4,0,0,0,0
rt_art_template: db 23,0,200,0,2,25,4,0,0,0,0,128,23,0,200,0,1
sa_contexts: incbin "../ui/runtime/contexts.vdu"
sa_contexts_end:
sa_cleanup: incbin "../ui/runtime/cleanup.vdu"
sa_cleanup_end:
sa_playlist_image_meta: incbin "../ui/runtime/playlist-meta.bin"
sa_playlist_image_meta_end:

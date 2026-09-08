; Qualified widget packets and patch offsets; see ../ui/README.md.
w_track:
    db 23,0,200,0,1,23,0,149,0,240,33,0,18,0,0,25,4,40,0,40,0,25,101,135
    db 1,47,0,18,0,10,25,4,40,0,40,0,32,32,32,32,32,32,32,32,32,32,32,32
    db 32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32
    db 32,32,32,32,32,32,32,32
w_track_end:
w_track_len: equ 80
w_track_bg: equ w_track+14
w_track_fg: equ w_track+29
w_track_text: equ w_track+36
w_track_send:
    ld hl,w_track
    ld bc,w_track_len
    jp ui_send
w_message:
    db 23,0,200,0,1,23,0,149,0,240,33,0,18,0,0,25,4,16,0,56,0,25,101,143
    db 1,63,0,18,0,15,25,4,16,0,56,0,32,32,32,32,32,32,32,32,32,32,32,32
    db 32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32
    db 32,32,32,32,32,32,32,32,32,32,32,32
w_message_end:
w_message_len: equ 84
w_message_bg: equ w_message+14
w_message_fg: equ w_message+29
w_message_text: equ w_message+36
w_message_send:
    ld hl,w_message
    ld bc,w_message_len
    jp ui_send
w_hint:
    db 23,0,200,0,1,23,0,149,0,240,33,0,18,0,0,25,4,24,1,96,0,25,101,143
    db 1,103,0,18,0,10,25,4,24,1,96,0,32,32,32,32,32,32,32,32,32,32,32,32
    db 32,32,32
w_hint_end:
w_hint_len: equ 51
w_hint_bg: equ w_hint+14
w_hint_fg: equ w_hint+29
w_hint_text: equ w_hint+36
w_hint_send:
    ld hl,w_hint
    ld bc,w_hint_len
    jp ui_send
w_detail:
    db 23,0,200,0,1,23,0,149,0,240,33,0,18,0,4,25,4,16,0,120,0,25,101,143
    db 1,127,0,18,0,15,25,4,16,0,120,0,32,32,32,32,32,32,32,32,32,32,32,32
    db 32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32
    db 32,32,32,32,32,32,32,32,32,32,32,32
w_detail_end:
w_detail_len: equ 84
w_detail_bg: equ w_detail+14
w_detail_fg: equ w_detail+29
w_detail_text: equ w_detail+36
w_detail_send:
    ld hl,w_detail
    ld bc,w_detail_len
    jp ui_send
w_path:
    db 23,0,200,0,1,23,0,149,0,240,33,0,18,0,4,25,4,8,0,136,0,25,101,135
    db 1,143,0,18,0,15,25,4,8,0,136,0,32,32,32,32,32,32,32,32,32,32,32,32
    db 32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32
    db 32,32,32,32,32,32,32,32,32,32,32,32
w_path_end:
w_path_len: equ 84
w_path_bg: equ w_path+14
w_path_fg: equ w_path+29
w_path_text: equ w_path+36
w_path_send:
    ld hl,w_path
    ld bc,w_path_len
    jp ui_send
w_page:
    db 23,0,200,0,1,23,0,149,0,240,33,0,18,0,4,25,4,144,1,136,0,25,101,247
    db 1,143,0,18,0,15,25,4,144,1,136,0,32,32,32,32,32,32,32,32,32,32,32,32
    db 32
w_page_end:
w_page_len: equ 49
w_page_bg: equ w_page+14
w_page_fg: equ w_page+29
w_page_text: equ w_page+36
w_page_send:
    ld hl,w_page
    ld bc,w_page_len
    jp ui_send
w_row0:
    db 23,0,200,0,1,23,0,149,0,241,33,0,18,0,0,25,4,10,0,150,0,25,101,245
    db 1,163,0,18,0,10,25,4,16,0,150,0,32,32,32,32,32,32,32,32,32,32,32,32
    db 32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32
    db 32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32
w_row0_end:
w_row0_len: equ 96
w_row0_bg: equ w_row0+14
w_row0_fg: equ w_row0+29
w_row0_text: equ w_row0+36
w_row0_send:
    ld hl,w_row0
    ld bc,w_row0_len
    jp ui_send
w_row1:
    db 23,0,200,0,1,23,0,149,0,241,33,0,18,0,0,25,4,10,0,164,0,25,101,245
    db 1,177,0,18,0,10,25,4,16,0,164,0,32,32,32,32,32,32,32,32,32,32,32,32
    db 32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32
    db 32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32
w_row1_end:
w_row1_len: equ 96
w_row1_bg: equ w_row1+14
w_row1_fg: equ w_row1+29
w_row1_text: equ w_row1+36
w_row1_send:
    ld hl,w_row1
    ld bc,w_row1_len
    jp ui_send
w_row2:
    db 23,0,200,0,1,23,0,149,0,241,33,0,18,0,0,25,4,10,0,178,0,25,101,245
    db 1,191,0,18,0,10,25,4,16,0,178,0,32,32,32,32,32,32,32,32,32,32,32,32
    db 32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32
    db 32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32
w_row2_end:
w_row2_len: equ 96
w_row2_bg: equ w_row2+14
w_row2_fg: equ w_row2+29
w_row2_text: equ w_row2+36
w_row2_send:
    ld hl,w_row2
    ld bc,w_row2_len
    jp ui_send
w_row3:
    db 23,0,200,0,1,23,0,149,0,241,33,0,18,0,0,25,4,10,0,192,0,25,101,245
    db 1,205,0,18,0,10,25,4,16,0,192,0,32,32,32,32,32,32,32,32,32,32,32,32
    db 32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32
    db 32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32
w_row3_end:
w_row3_len: equ 96
w_row3_bg: equ w_row3+14
w_row3_fg: equ w_row3+29
w_row3_text: equ w_row3+36
w_row3_send:
    ld hl,w_row3
    ld bc,w_row3_len
    jp ui_send
w_row4:
    db 23,0,200,0,1,23,0,149,0,241,33,0,18,0,0,25,4,10,0,206,0,25,101,245
    db 1,219,0,18,0,10,25,4,16,0,206,0,32,32,32,32,32,32,32,32,32,32,32,32
    db 32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32
    db 32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32
w_row4_end:
w_row4_len: equ 96
w_row4_bg: equ w_row4+14
w_row4_fg: equ w_row4+29
w_row4_text: equ w_row4+36
w_row4_send:
    ld hl,w_row4
    ld bc,w_row4_len
    jp ui_send
w_row5:
    db 23,0,200,0,1,23,0,149,0,241,33,0,18,0,0,25,4,10,0,220,0,25,101,245
    db 1,233,0,18,0,10,25,4,16,0,220,0,32,32,32,32,32,32,32,32,32,32,32,32
    db 32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32
    db 32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32
w_row5_end:
w_row5_len: equ 96
w_row5_bg: equ w_row5+14
w_row5_fg: equ w_row5+29
w_row5_text: equ w_row5+36
w_row5_send:
    ld hl,w_row5
    ld bc,w_row5_len
    jp ui_send
w_row6:
    db 23,0,200,0,1,23,0,149,0,241,33,0,18,0,0,25,4,10,0,234,0,25,101,245
    db 1,247,0,18,0,10,25,4,16,0,234,0,32,32,32,32,32,32,32,32,32,32,32,32
    db 32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32
    db 32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32
w_row6_end:
w_row6_len: equ 96
w_row6_bg: equ w_row6+14
w_row6_fg: equ w_row6+29
w_row6_text: equ w_row6+36
w_row6_send:
    ld hl,w_row6
    ld bc,w_row6_len
    jp ui_send
w_row7:
    db 23,0,200,0,1,23,0,149,0,241,33,0,18,0,0,25,4,10,0,248,0,25,101,245
    db 1,5,1,18,0,10,25,4,16,0,248,0,32,32,32,32,32,32,32,32,32,32,32,32
    db 32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32
    db 32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32
w_row7_end:
w_row7_len: equ 96
w_row7_bg: equ w_row7+14
w_row7_fg: equ w_row7+29
w_row7_text: equ w_row7+36
w_row7_send:
    ld hl,w_row7
    ld bc,w_row7_len
    jp ui_send
w_row8:
    db 23,0,200,0,1,23,0,149,0,241,33,0,18,0,0,25,4,10,0,6,1,25,101,245
    db 1,19,1,18,0,10,25,4,16,0,6,1,32,32,32,32,32,32,32,32,32,32,32,32
    db 32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32
    db 32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32
w_row8_end:
w_row8_len: equ 96
w_row8_bg: equ w_row8+14
w_row8_fg: equ w_row8+29
w_row8_text: equ w_row8+36
w_row8_send:
    ld hl,w_row8
    ld bc,w_row8_len
    jp ui_send
w_row9:
    db 23,0,200,0,1,23,0,149,0,241,33,0,18,0,0,25,4,10,0,20,1,25,101,245
    db 1,33,1,18,0,10,25,4,16,0,20,1,32,32,32,32,32,32,32,32,32,32,32,32
    db 32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32
    db 32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32
w_row9_end:
w_row9_len: equ 96
w_row9_bg: equ w_row9+14
w_row9_fg: equ w_row9+29
w_row9_text: equ w_row9+36
w_row9_send:
    ld hl,w_row9
    ld bc,w_row9_len
    jp ui_send
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
w_elapsed:
    db 23,0,200,0,2,18,0,0,25,4,16,0,72,0,25,101,143,0,87,0,25,4,16,0
    db 80,0,132,9,132,9,142,9,132,9,132,9,142,9,132,9,132,9,23,0,200,0,1
w_elapsed_end:
w_elapsed_len: equ 47
w_elapsed_digits: equ w_elapsed+26
w_elapsed_send:
    ld hl,w_elapsed
    ld bc,w_elapsed_len
    jp ui_send
w_duration:
    db 23,0,200,0,2,18,0,0,25,4,8,1,72,0,25,101,135,1,87,0,25,4,8,1
    db 80,0,132,9,132,9,142,9,132,9,132,9,142,9,132,9,132,9,23,0,200,0,1
w_duration_end:
w_duration_len: equ 47
w_duration_digits: equ w_duration+26
w_duration_send:
    ld hl,w_duration
    ld bc,w_duration_len
    jp ui_send
w_progress:
    db 23,0,200,0,2,25,4,16,0,104,0,147,23,0,200,0,1
w_progress_end:
w_progress_len: equ 17
w_progress_x: equ w_progress+7
w_progress_code: equ w_progress+11
w_progress_send:
    ld hl,w_progress
    ld bc,w_progress_len
    jp ui_send
w_marker:
    db 23,0,200,0,2,25,4,16,0,104,0,148,23,0,200,0,1
w_marker_end:
w_marker_len: equ 17
w_marker_x: equ w_marker+7
w_marker_code: equ w_marker+11
w_marker_send:
    ld hl,w_marker
    ld bc,w_marker_len
    jp ui_send
w_mode:
    db 23,0,200,0,2,18,0,0,25,4,16,0,32,0,25,101,31,0,47,0,25,4,16,0
    db 40,0,130,23,0,200,0,1
w_mode_end:
w_mode_len: equ 32
w_mode_x: equ w_mode+22
w_mode_code: equ w_mode+26
w_mode_send:
    ld hl,w_mode
    ld bc,w_mode_len
    jp ui_send
w_play:
    db 23,0,200,0,2,18,0,0,25,4,16,0,48,1,25,101,39,0,71,1,25,4,16,0
    db 64,1,128,23,0,200,0,1
w_play_end:
w_play_len: equ 32
w_play_x: equ w_play+22
w_play_code: equ w_play+26
w_play_send:
    ld hl,w_play
    ld bc,w_play_len
    jp ui_send
w_shuffle:
    db 23,0,200,0,2,25,4,128,0,56,1,143,23,0,200,0,1
w_shuffle_end:
w_shuffle_len: equ 17
w_shuffle_x: equ w_shuffle+7
w_shuffle_code: equ w_shuffle+11
w_shuffle_send:
    ld hl,w_shuffle
    ld bc,w_shuffle_len
    jp ui_send
w_loop:
    db 23,0,200,0,2,25,4,224,0,56,1,145,23,0,200,0,1
w_loop_end:
w_loop_len: equ 17
w_loop_x: equ w_loop+7
w_loop_code: equ w_loop+11
w_loop_send:
    ld hl,w_loop
    ld bc,w_loop_len
    jp ui_send
w_volume:
    db 23,0,200,0,2,25,4,56,1,56,1,149,23,0,200,0,1
w_volume_end:
w_volume_len: equ 17
w_volume_x: equ w_volume+7
w_volume_code: equ w_volume+11
w_volume_send:
    ld hl,w_volume
    ld bc,w_volume_len
    jp ui_send
w_thumb:
    db 23,0,200,0,2,25,4,56,1,56,1,161,23,0,200,0,1
w_thumb_end:
w_thumb_len: equ 17
w_thumb_x: equ w_thumb+7
w_thumb_code: equ w_thumb+11
w_thumb_send:
    ld hl,w_thumb
    ld bc,w_thumb_len
    jp ui_send
w_voltext:
    db 23,0,200,0,1,23,0,149,0,240,33,0,18,0,0,25,4,136,1,48,1,25,101,239
    db 1,55,1,18,0,10,25,4,136,1,48,1,32,32,32,32,32,32,32,32,32,32,32,32
    db 32
w_voltext_end:
w_voltext_len: equ 49
w_voltext_bg: equ w_voltext+14
w_voltext_fg: equ w_voltext+29
w_voltext_text: equ w_voltext+36
w_voltext_send:
    ld hl,w_voltext
    ld bc,w_voltext_len
    jp ui_send
ui_volume_codes: db 149,150,151,152,153,154,155,156,157,158,159,160
ui_volume_x: db 0,5,9,14,19,24,28,33,38,43,47,52
art_play: equ 128
art_pause: equ 129
art_playing: equ 130
art_paused: equ 131
art_digit_0: equ 132
art_digit_1: equ 133
art_digit_2: equ 134
art_digit_3: equ 135
art_digit_4: equ 136
art_digit_5: equ 137
art_digit_6: equ 138
art_digit_7: equ 139
art_digit_8: equ 140
art_digit_9: equ 141
art_colon: equ 142
art_shuffle_off: equ 143
art_shuffle_on: equ 144
art_loop_off: equ 145
art_loop_on: equ 146
art_progress_track: equ 147
art_progress_marker: equ 148
art_volume_0: equ 149
art_volume_1: equ 150
art_volume_2: equ 151
art_volume_3: equ 152
art_volume_4: equ 153
art_volume_5: equ 154
art_volume_6: equ 155
art_volume_7: equ 156
art_volume_8: equ 157
art_volume_9: equ 158
art_volume_10: equ 159
art_volume_11: equ 160
art_volume_thumb: equ 161
art_edge_top: equ 162
art_edge_bottom: equ 163
art_edge_left: equ 164
art_edge_right: equ 165
art_blank: equ 166
art_selected_blank: equ 167
art_heading_A: equ 168
art_heading_B: equ 169
art_heading_C: equ 170
art_heading_D: equ 171
art_heading_E: equ 172
art_heading_F: equ 173
art_heading_G: equ 174
art_heading_H: equ 175
art_heading_I: equ 176
art_heading_J: equ 177
art_heading_K: equ 178
art_heading_L: equ 179
art_heading_M: equ 180
art_heading_N: equ 181
art_heading_O: equ 182
art_heading_P: equ 183
art_heading_Q: equ 184
art_heading_R: equ 185
art_heading_S: equ 186
art_heading_T: equ 187
art_heading_U: equ 188
art_heading_V: equ 189
art_heading_W: equ 190
art_heading_X: equ 191
art_heading_Y: equ 192
art_heading_Z: equ 193
sa_image_count: equ 67
sa_image_meta: incbin "../ui/image-meta.bin"
sa_contexts: incbin "../ui/contexts.vdu"
sa_contexts_end:
sa_cleanup: incbin "../ui/cleanup.vdu"
sa_cleanup_end:
ui_static: incbin "../ui/static.vdu"
ui_static_end:

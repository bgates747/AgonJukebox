; Bounded runtime-v1 loader. All external bytes are data, never VDU opcodes.
; Error 60: size/magic; 61: scalar/geometry/reference outside ABI bounds.
rt_load:
    ld hl,rt_layout_leaf
    call sa_join_asset
    ret nz
    ld bc,rt_size
    call sa_read_small
    ret nz
    ld hl,(sa_small_count)
    ld de,rt_size
    or a
    sbc hl,de
    jp nz,rt_bad_header
    ld hl,sa_small_data
    ld de,rt_magic
    ld b,8
@magic:
    ld a,(de)
    cp (hl)
    jp nz,rt_bad_header
    inc hl
    inc de
    djnz @magic
    ld hl,sa_small_data
    ld de,rt_descriptor
    ld bc,rt_size
    ldir
    call rt_validate
    ret nz
    call rt_make_metadata
    call rt_make_widgets
    call rt_make_static
    xor a
    ret
rt_bad_header:
    ld a,0x60
    or a
    ret
rt_bad_data:
    ld a,0x61
    or a
    ret
rt_validate:
    ld a,(rt_image_count)
    cp 22
    jp c,rt_bad_data
    cp 215
    jp nc,rt_bad_data
    ld a,(rt_path_columns)
    cp 6
    jp c,rt_bad_data
    cp 61
    jp nc,rt_bad_data
    ld a,(rt_track_columns)
    cp 14
    jp c,rt_bad_data
    cp 61
    jp nc,rt_bad_data
    ld a,(rt_filename_offset)
    cp 3
    jp c,rt_bad_data
    cp 41
    jp nc,rt_bad_data
    ld b,a
    ld a,(rt_filename_columns)
    cp 12
    jp c,rt_bad_data
    cp 56
    jp nc,rt_bad_data
    add a,b
    cp 59
    jp nc,rt_bad_data
    ld b,a
    ld a,(rt_duration_offset)
    cp 255
    jr z,@duration_ok
    cp 51
    jp nc,rt_bad_data
    cp b
    jp c,rt_bad_data
@duration_ok:
    ld a,(rt_pointer_enabled)
    cp 2
    jp nc,rt_bad_data
    ld hl,rt_normal_bg_value
    ld b,4
@palette:
    ld a,(hl)
    cp 64
    jp nc,rt_bad_data
    inc hl
    djnz @palette
    ld a,(rt_progress_span)
    or a
    jp z,rt_bad_data
    ld ix,rt_descriptor+20
    call rt_word
    ld de,503
    or a
    sbc hl,de
    jp nc,rt_bad_data
    ld a,(ix) ; status font: legacy 5x8 or playlist 6x12
    cp 2
    jp nc,rt_bad_data
    inc ix
    ld b,9
@reserved:
    ld a,(ix)
    or a
    jp nz,rt_bad_data
    inc ix
    djnz @reserved
    ld ix,rt_descriptor+rt_geometry
    xor a
    ld (rt_index),a
@widget:
    ld a,(rt_index)
    cp 2
    jr nz,@required
    ld a,(ix+12)
    or a
    jr nz,@required
    push ix
    ld b,15
@absent:
    ld a,(ix)
    or a
    jp nz,rt_bad_data_pop
    inc ix
    djnz @absent
    pop ix
    jp @next_widget
@required:
    ; Six coordinate words: text x/y, rectangle left/top/right/bottom.
    push ix
    ld b,3
@coords:
    call rt_word
    ld de,512
    or a
    sbc hl,de
    jp nc,rt_bad_data_pop
    call rt_word
    ld de,384
    or a
    sbc hl,de
    jp nc,rt_bad_data_pop
    djnz @coords
    pop ix
    ld a,(ix+13)
    cp 64
    jp nc,rt_bad_data
    ld a,(ix+14)
    cp 64
    jp nc,rt_bad_data
    ld a,(rt_index)
    cp 1
    jr nz,@fixed_width
    ld a,(ix+12)
    cp 8
    jp c,rt_bad_data
    cp 61
    jp nc,rt_bad_data
    jr @width_ok
@fixed_width:
    ; Per-role lengths are fixed except page/path/track; count can be absent.
    ld hl,rt_text_widths
    ld de,0
    ld a,(rt_index)
    ld e,a
    add hl,de
    ld a,(hl)
    cp 255
    jr nz,@width
    ld a,(rt_path_columns)
    ld c,a
    ld a,(rt_index)
    or a
    ld a,c
    jr z,@width
    ld a,(rt_track_columns)
@width:
    cp (ix+12)
    jr z,@width_ok
    ld a,(rt_index)
    cp 2
    jp nz,rt_bad_data
    ld a,(ix+12)
    or a
    jp nz,rt_bad_data
@width_ok:
    ; Text must fit its rectangle. Inclusive ends; all words are zero-extended.
    push ix
    call rt_word
    ld (rt_x),hl
    call rt_word
    ld (rt_y),hl
    call rt_word
    ld de,(rt_x)
    or a
    sbc hl,de
    jp p,@left_compare
    jr @left_ok
@left_compare:
    jp nz,rt_bad_data_pop
@left_ok:
    call rt_word
    ld de,(rt_y)
    or a
    sbc hl,de
    jp p,@top_compare
    jr @top_ok
@top_compare:
    jp nz,rt_bad_data_pop
@top_ok:
    call rt_word
    ld (rt_right),hl
    call rt_word
    ld (rt_bottom),hl
    pop ix
    ld hl,0
    ld l,(ix+12)
    ld de,5
    ld a,(rt_descriptor+22)
    or a
    jr z,@status_width_ready
    ld de,6
    ld a,(rt_normal_bg_value)
    cp (ix+13)
    jp nz,rt_bad_data
    ld a,(rt_normal_fg)
    cp (ix+14)
    jp nz,rt_bad_data
@status_width_ready:
    ld a,(rt_index)
    cp 3
    jr c,@small
    cp 13
    jr nc,@small
    ld a,(ix+1)
    or a
    ; Y is restricted to a byte for the selection sprite's row table.
    ld a,(ix+3)
    or a
    jp nz,rt_bad_data
    ld a,(rt_normal_bg_value)
    cp (ix+13)
    jp nz,rt_bad_data
    ld a,(rt_normal_fg)
    cp (ix+14)
    jp nz,rt_bad_data
    ld de,6
@small:
    call umul24
    ld de,(rt_x)
    add hl,de
    dec hl
    ld de,(rt_right)
    or a
    sbc hl,de
    jp p,@right_compare
    jr @right_ok
@right_compare:
    jp nz,rt_bad_data
@right_ok:
    ld hl,(rt_y)
    ld de,7
    ld a,(rt_descriptor+22)
    or a
    jr z,@status_height_ready
    ld de,11
@status_height_ready:
    ld a,(rt_index)
    cp 3
    jr c,@height
    cp 13
    jr nc,@height
    ld de,11
@height:
    add hl,de
    ld de,(rt_bottom)
    or a
    sbc hl,de
    jp p,@bottom_compare
    jr @bottom_ok
@bottom_compare:
    jp nz,rt_bad_data
@bottom_ok:
@next_widget:
    lea ix,ix+15
    ld a,(rt_index)
    inc a
    ld (rt_index),a
    cp 19
    jp c,@widget
    ; Art origins must be on screen. Image dimensions checked below.
    ld b,6
@art:
    call rt_word
    ld de,512
    or a
    sbc hl,de
    jp nc,rt_bad_data
    call rt_word
    ld de,384
    or a
    sbc hl,de
    jp nc,rt_bad_data
    djnz @art
    xor a
    ld (rt_index),a
    ld hl,0
    ld (rt_bitmap_total),hl
@image:
    call rt_word
    ld (rt_x),hl
    ld de,513
    or a
    sbc hl,de
    jp nc,rt_bad_data
    call rt_word
    ld (rt_y),hl
    ld de,65
    or a
    sbc hl,de
    jp nc,rt_bad_data
    ld a,(rt_index)
    ld hl,rt_image_count
    cp (hl)
    jr nc,@unused
    ld hl,(rt_x)
    ld de,0
    or a
    sbc hl,de
    jp z,rt_bad_data
    ld hl,(rt_y)
    or a
    sbc hl,de
    jp z,rt_bad_data
    ld a,(rt_index)
    cp 22
    jr c,@next_image
    ld hl,(rt_x)
    ld de,32
    or a
    sbc hl,de
    jp nz,rt_bad_data
    ld hl,(rt_y)
    or a
    sbc hl,de
    jp nz,rt_bad_data
    jr @next_image
@unused:
    ld hl,(rt_x)
    ld de,(rt_y)
    add hl,de
    ld de,0
    or a
    sbc hl,de
    jp nz,rt_bad_data
@next_image:
    ld hl,(rt_x)
    ld de,(rt_y)
    call umul24
    ld de,(rt_bitmap_total)
    add hl,de
    ld (rt_bitmap_total),hl
    ld de,262145
    or a
    sbc hl,de
    jp nc,rt_bad_data
    ld a,(rt_index)
    inc a
    ld (rt_index),a
    cp 214
    jp c,@image
    ld b,192
@tile:
    ld a,(ix)
    inc ix
    cp 255
    jr z,@tile_ok
    cp 22
    jp c,rt_bad_data
    ld hl,rt_image_count
    cp (hl)
    jp nc,rt_bad_data
@tile_ok:
    djnz @tile
    ; Pointer dimensions are part of the v1 sprite contract.
    ld ix,rt_descriptor+rt_images+[21*4]
    call rt_word
    ld de,10
    or a
    sbc hl,de
    jp nz,rt_bad_data
    call rt_word
    ld de,12
    or a
    sbc hl,de
    jp nz,rt_bad_data
    ; Every state of a control must have the same dimensions.
    ld ix,rt_descriptor+rt_images
    ld b,2
    call rt_equal_sizes
    ret nz
    ld b,1
    call rt_equal_sizes
    ret nz
    ld b,1
    call rt_equal_sizes
    ret nz
    ld b,11
    call rt_equal_sizes
    ret nz
    ; Check all art rectangles, including the marker's maximum travel.
    ld ix,rt_descriptor+rt_art
    xor a
    ld (rt_index),a
@art_bounds:
    call rt_word
    ld (rt_x),hl
    call rt_word
    ld (rt_y),hl
    ld a,(rt_index)
    ld hl,0
    ld l,a
    ld de,rt_art_codes
    add hl,de
    ld a,(hl)
    sub 128
    ld hl,0
    ld l,a
    add hl,hl
    add hl,hl
    ld de,rt_descriptor+rt_images
    add hl,de
    push ix
    push hl
    pop ix
    call rt_word
    ld de,(rt_x)
    add hl,de
    ld a,(rt_index)
    cp 5
    jr nz,@no_travel
    ld a,(rt_progress_span)
    ld de,0
    ld e,a
    add hl,de
@no_travel:
    ld de,513
    or a
    sbc hl,de
    jp nc,rt_bad_data_pop
    call rt_word
    ld de,(rt_y)
    add hl,de
    ld de,385
    or a
    sbc hl,de
    jp nc,rt_bad_data_pop
    pop ix
    ld a,(rt_index)
    inc a
    ld (rt_index),a
    cp 6
    jp c,@art_bounds
    ; Progress marker remains inside its restoration track throughout travel.
    ld ix,rt_descriptor+rt_art+16
    call rt_word
    ld (rt_x),hl
    call rt_word
    ld (rt_y),hl
    ld ix,rt_descriptor+rt_images+76
    call rt_word
    ld de,(rt_x)
    add hl,de
    ld (rt_right),hl
    call rt_word
    ld de,(rt_y)
    add hl,de
    ld (rt_bottom),hl
    ld ix,rt_descriptor+rt_art+20
    call rt_word
    ld (rt_marker_x),hl
    ld de,(rt_x)
    or a
    sbc hl,de
    jp c,rt_bad_data
    call rt_word
    ld (rt_marker_y),hl
    ld de,(rt_y)
    or a
    sbc hl,de
    jp c,rt_bad_data
    ld ix,rt_descriptor+rt_images+80
    call rt_word
    ld de,(rt_marker_x)
    add hl,de
    ld a,(rt_progress_span)
    ld de,0
    ld e,a
    add hl,de
    dec hl
    ld de,(rt_right)
    or a
    sbc hl,de
    jp nc,rt_bad_data
    call rt_word
    ld de,(rt_marker_y)
    add hl,de
    dec hl
    ld de,(rt_bottom)
    or a
    sbc hl,de
    jp nc,rt_bad_data
    ; Ordered rows and their left restoration margins match authoring v1.
    ld ix,rt_descriptor+rt_geometry+45
    ld b,10
    ld hl,0
    ld (rt_y),hl
@rows:
    push ix
    call rt_word
    ld (rt_x),hl
    call rt_word
    ld de,(rt_y)
    or a
    sbc hl,de
    jp c,rt_bad_data_pop
    add hl,de
    ld de,12
    add hl,de
    ld (rt_y),hl
    call rt_word
    ld de,(rt_x)
    or a
    sbc hl,de
    jp nc,rt_bad_data_pop
    pop ix
    lea ix,ix+15
    djnz @rows
    xor a
    ret
; IX first state, B number of additional states. Advance to next control.
rt_equal_sizes:
    push ix
    pop hl
    lea ix,ix+4
@state:
    push hl
    push bc
    ld b,4
@byte:
    ld a,(hl)
    cp (ix)
    jr nz,@bad
    inc hl
    inc ix
    djnz @byte
    pop bc
    pop hl
    djnz @state
    xor a
    ret
@bad:
    pop bc
    pop hl
    jp rt_bad_data
rt_bad_data_pop:
    pop ix
    jp rt_bad_data
; Read exact u16, zero-extend to ADL24, advance IX. BC/DE preserved.
rt_word:
    ld hl,0
    ld l,(ix)
    ld h,(ix+1)
    inc ix
    inc ix
    ret
rt_make_metadata:
    ld ix,rt_descriptor+rt_images
    ld iy,sa_image_meta
    ld a,(rt_image_count)
    ld (rt_index),a
    ld bc,0x2100
@image:
    ld (iy),c
    ld (iy+1),b
    inc bc
    call rt_word
    ld (iy+2),l
    ld (iy+3),h
    push hl
    call rt_word
    ld (iy+4),l
    ld (iy+5),h
    ex de,hl
    pop hl
    push bc
    call umul24
    pop bc
    ld (iy+6),1
    ld (iy+7),hl ; ADL24 OK: three low bytes of u32 size.
    ld (iy+10),0
    lea iy,iy+11
    ld a,(rt_index)
    dec a
    ld (rt_index),a
    jr nz,@image
    ret
rt_make_widgets:
    ld ix,rt_descriptor+rt_geometry
    ld hl,rt_widget_table
    ld (rt_table),hl
    xor a
    ld (rt_index),a
@text:
    ld hl,(rt_table)
    ld iy,(hl) ; ADL24 OK: table of dl pointers.
    inc hl
    inc hl
    inc hl
    ld (rt_table),hl
    push iy
    pop de
    ld hl,rt_text_template
    ld bc,36
    ldir
    ld a,(rt_descriptor+22)
    or a
    jr z,@status_font_ready
    ld (iy+4),3
    ld (iy+9),0xf1
@status_font_ready:
    push ix
    call rt_word
    ld (iy+32),l
    ld (iy+33),h
    call rt_word
    ld (iy+34),l
    ld (iy+35),h
    call rt_word
    ld (iy+17),l
    ld (iy+18),h
    call rt_word
    ld (iy+19),l
    ld (iy+20),h
    call rt_word
    ld (iy+23),l
    ld (iy+24),h
    call rt_word
    ld (iy+25),l
    ld (iy+26),h
    pop ix
    ld hl,0
    ld l,(ix+12)
    ld de,36
    add hl,de
    ld a,(ix+12)
    or a
    jr nz,@present
    ld hl,0
@present:
    ld (iy+96),hl ; ADL24 OK: dl packet length after 96-byte slot.
    ld a,(ix+13)
    ld (iy+14),a
    ld a,(ix+14)
    ld (iy+29),a
    ld a,(rt_index)
    cp 3
    jr c,@next_text
    cp 13
    jr nc,@next_text
    ld (iy+4),3
    ld (iy+9),0xf1
    sub 3
    ld de,0
    ld e,a
    ld hl,ui_selection_y
    add hl,de
    ld a,(ix+2)
    ld (hl),a
@next_text:
    lea ix,ix+15
    ld a,(rt_index)
    inc a
    ld (rt_index),a
    cp 19
    jp c,@text
    xor a
    ld (rt_index),a
@art:
    ld hl,(rt_table)
    ld iy,(hl)
    inc hl
    inc hl
    inc hl
    ld (rt_table),hl
    push iy
    pop de
    ld hl,rt_art_template
    ld bc,17
    ldir
    call rt_word
    ld (iy+7),l
    ld (iy+8),h
    ld a,(rt_index)
    cp 5
    jr nz,@not_marker
    ld (rt_progress_origin),hl
@not_marker:
    call rt_word
    ld (rt_y),hl
    ld de,0
    ld a,(rt_index)
    ld e,a
    ld hl,rt_art_codes
    add hl,de
    ld a,(hl)
    ld (iy+11),a
    sub 128
    ld hl,0
    ld l,a
    add hl,hl
    add hl,hl
    ld de,rt_descriptor+rt_images+2
    add hl,de
    ld de,0
    ld e,(hl) ; height <=64, upper byte already validated zero.
    ld hl,(rt_y)
    add hl,de
    ld de,8
    or a
    sbc hl,de
    ld (iy+9),l
    ld (iy+10),h
    ld hl,17
    ld (iy+96),hl
    ld a,(rt_index)
    inc a
    ld (rt_index),a
    cp 6
    jp c,@art
    ld a,(rt_descriptor+20)
    ld (ui_selection_packet+7),a
    ld a,(rt_descriptor+21)
    ld (ui_selection_packet+8),a
    ret
rt_make_static:
    ld hl,rt_static_prefix
    ld de,ui_static
    ld bc,rt_static_prefix_end-rt_static_prefix
    ldir
    ld ix,rt_descriptor+rt_tiles
    ld hl,0
    ld (rt_x),hl
    ld (rt_y),hl
    ld b,192
@tile:
    ld a,(ix)
    inc ix
    cp 255
    jr z,@skip
    push bc
    push de
    ld (rt_plot+3),a
    ld hl,(rt_x)
    ld a,l
    ld (rt_plot+7),a
    ld a,h
    ld (rt_plot+8),a
    ld hl,(rt_y)
    ld a,l
    ld (rt_plot+9),a
    ld a,h
    ld (rt_plot+10),a
    pop de
    ld hl,rt_plot
    ld bc,11
    ldir
    pop bc
@skip:
    ld hl,(rt_x)
    push de
    ld de,32
    add hl,de
    ld (rt_x),hl
    ld de,512
    or a
    sbc hl,de
    jr nz,@next
    ld (rt_x),hl
    ld hl,(rt_y)
    ld de,32
    add hl,de
    ld (rt_y),hl
@next:
    pop de
    djnz @tile
    ld hl,rt_static_suffix
    ld bc,rt_static_suffix_end-rt_static_suffix
    ldir
    ex de,hl
    ld de,ui_static
    or a
    sbc hl,de
    ld (rt_static_len),hl
    ret
rt_magic: db "JBSKIN1",0
rt_layout_leaf: asciz "layout.bin"
rt_text_widths: db 255,8,13,58,58,58,58,58,58,58,58,58,58,48,255,8,8,23,13
rt_art_codes: db 128,131,133,146,147,148
rt_plot: db 23,27,32,0,0x21,25,237,0,0,0,0
rt_static_prefix: db 23,0,200,0,1,18,0,0,25,4,0,0,0,0,25,101,255,1,127,1,23,0,200,0,2
rt_static_prefix_end:
rt_static_suffix: db 23,0,200,0,1,23,0,149,0,240,33,0,23,27,4,0,23,27,5,23,27,38,21,33,23,27,7,1,23,27,12,23,27,15
rt_static_suffix_end:
rt_index: db 0
rt_x: dl 0
rt_y: dl 0
rt_right: dl 0
rt_bottom: dl 0
rt_table: dl 0

rt_bitmap_total: dl 0
rt_marker_x: dl 0
rt_marker_y: dl 0

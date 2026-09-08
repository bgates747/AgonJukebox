sa_skin_assets_init:
    ld a,8
    rst.lil 8
    ld a,(ix+0x27)
    ld (sa_old_mode),a
    xor a
    ld (sa_mode_changed),a
    ld (sa_small_open),a
    call jcfg_load
    ret nz
    call jcfg_check_skin
    ret nz
    call jcfg_manifest_path
    ret nz
    ld de,jcfg_manifest
    ld bc,1024
    call sa_read_small
    ret nz
    call sa_parse_manifest
    ret nz
    ; Mode changes reset all saved sa_contexts. Wait for MOS mode reply.
    ld a,8
    rst.lil 8
    res 4,(ix+4)
    ld a,1
    ld (sa_mode_changed),a
    ld hl,sa_mode20
    ld bc,2
    rst.lil 0x18
    ld b,4
    call sa_wait_packet
    ret nz
    ld a,(ix+0x27)
    cp 20
    ld a,0x50
    ret nz
    ld a,1
    ld (sa_mode_changed),a
    ld hl,sa_initial
    ld bc,sa_initial_end-sa_initial
    rst.lil 0x18
    ld hl,sa_graphics_file
    call sa_join_asset
    ret nz
    call sa_load_images
    ret nz
    ld hl,sa_font8_file
    call sa_join_asset
    ret nz
    ld bc,2048
    call sa_read_small
    ret nz
    ld hl,(sa_small_count)
    ld de,2048
    or a
    sbc hl,de
    ld a,0x51
    ret nz
    ld hl,0x21f0
    call vdu_clear_buffer
    ld hl,0x21f0
    ld de,sa_small_data
    ld bc,2048
    call vdu_load_buffer
    ld hl,sa_font8_create
    ld bc,10
    rst.lil 0x18
    ld hl,sa_font14_file
    call sa_join_asset
    ret nz
    ld bc,3584
    call sa_read_small
    ret nz
    ld hl,(sa_small_count)
    ld de,3584
    or a
    sbc hl,de
    ld a,0x51
    ret nz
    ld hl,0x21f1
    call vdu_clear_buffer
    ld hl,0x21f1
    ld de,sa_small_data
    ld bc,3584
    call vdu_load_buffer
    ld hl,sa_font14_create
    ld bc,10
    rst.lil 0x18
    ld hl,sa_contexts
    ld bc,sa_contexts_end-sa_contexts
    rst.lil 0x18
    ld hl,sa_ready
    call sa_debug_puts
    xor a
    ret
sa_restore:
    call agnb_close
    call sa_close_small
    call jcfg_init
    ld a,(sa_mode_changed)
    or a
    ret z
    ld hl,sa_cleanup
    ld bc,sa_cleanup_end-sa_cleanup
    rst.lil 0x18
    ld a,(sa_old_mode)
    ld (sa_restore_mode+1),a
    ld hl,sa_restore_mode
    ld bc,sa_restore_end-sa_restore_mode
    rst.lil 0x18
    ret

; Small-file reader, DE=path, BC=maximum; returns count and sentinel-terminated
; private data. No destination string or payload is uploaded before validation.
sa_read_small:
    ld (sa_small_max),bc
    ld hl,sa_small_fil
    ld c,fa_read
    FFSCALL ffs_fopen
    or a
    jp nz,sa_small_open_error
    ld a,1
    ld (sa_small_open),a
    ld hl,sa_small_fil
    ld de,sa_small_data
    ld bc,(sa_small_max)
    inc bc
    FFSCALL ffs_fread
    ld (sa_small_count),bc
    push af
    call sa_close_small
    ld (sa_small_close_error),a
    pop af
    or a
    jp nz,sa_small_read_error
    ld a,(sa_small_close_error)
    or a
    ret nz
    ld hl,(sa_small_max)
    ld de,(sa_small_count)
    or a
    sbc hl,de
    ld a,0x43
    jp c,sa_small_error
    ld hl,sa_small_data
    add hl,de
    ld (hl),0
    xor a
    ret
sa_close_small:
    ld a,(sa_small_open)
    or a
    ret z
    ld hl,sa_small_fil
    FFSCALL ffs_fclose
    or a
    jp nz,sa_small_close_failed
    ld (sa_small_open),a
    ret
sa_small_close_failed:
    ld a,0x44
    or a
    ret
sa_small_open_error:
    ld a,0x41
    jp sa_small_error
sa_small_read_error:
    ld a,0x42
sa_small_error:
    or a
    ret

; Minimal private manifest: strict ASCII key=value, LF/CRLF, four required keys.
; Reuses the validated config lexical string helpers. Full schema stays SKIN-003.
sa_parse_manifest:
    ld hl,sa_small_data
    ld bc,(sa_small_count)
sa_manifest_ascii:
    ld a,b
    or c
    jp z,sa_manifest_ascii_done
    ld a,(hl)
    cp 9
    jp z,sa_manifest_ascii_next
    cp 10
    jp z,sa_manifest_ascii_next
    cp 13
    jp z,sa_manifest_ascii_next
    cp 32
    jp c,sa_manifest_bad
    cp 127
    jp nc,sa_manifest_bad
sa_manifest_ascii_next:
    inc hl
    dec bc
    jp sa_manifest_ascii
sa_manifest_ascii_done:
    xor a
    ld (sa_manifest_seen),a
    ld hl,sa_small_data
    ld (sa_manifest_cursor),hl
sa_manifest_line:
    ld hl,(sa_manifest_cursor)
    ld a,(hl)
    or a
    jp z,sa_manifest_done
    ld (sa_line_start),hl
    ld b,0
sa_manifest_scan:
    ld a,(hl)
    or a
    jp z,sa_manifest_line_end
    cp 10
    jp z,sa_manifest_line_end
    cp 13
    jp z,sa_manifest_cr
    cp 9
    jp z,sa_manifest_char
    cp 32
    jp c,sa_manifest_bad
    cp 127
    jp nc,sa_manifest_bad
sa_manifest_char:
    inc b
    jp z,sa_manifest_bad
    inc hl
    jp sa_manifest_scan
sa_manifest_cr:
    ld (hl),0
    inc hl
    ld a,(hl)
    cp 10
    jp nz,sa_manifest_bad
sa_manifest_line_end:
    ld a,(hl)
    ld (hl),0
    or a
    jp z,sa_manifest_last
    inc hl
sa_manifest_last:
    ld (sa_manifest_cursor),hl
    ld hl,(sa_line_start)
    call jcfg_trim
    ld a,(hl)
    or a
    jp z,sa_manifest_line
    cp '#'
    jp z,sa_manifest_line
    cp ';'
    jp z,sa_manifest_line
    ld (sa_key_ptr),hl
sa_manifest_equal:
    ld a,(hl)
    or a
    jp z,sa_manifest_bad
    cp '='
    jp z,sa_manifest_value
    ; fold key only
    cp 'A'
    jp c,sa_manifest_key_next
    cp 'Z'+1
    jp nc,sa_manifest_key_next
    add a,32
    ld (hl),a
sa_manifest_key_next:
    inc hl
    jp sa_manifest_equal
sa_manifest_value:
    ld (hl),0
    inc hl
    call jcfg_trim
    ld (sa_value_ptr),hl
    ld a,(hl)
    or a
    jp z,sa_manifest_bad
    ld hl,(sa_key_ptr)
    call jcfg_trim
    ld (sa_key_ptr),hl
    ld ix,sa_manifest_keys
    ld b,4
    ld c,1
sa_manifest_match:
    push bc
    ld hl,(sa_key_ptr)
    ld de,(ix+0)
    call jcfg_equal_strings
    pop bc
    jp z,sa_manifest_matched
    lea ix,ix+6
    sla c
    djnz sa_manifest_match
    jp sa_manifest_bad
sa_manifest_matched:
    ld a,(sa_manifest_seen)
    and c
    jp nz,sa_manifest_bad
    ld a,(sa_manifest_seen)
    or c
    ld (sa_manifest_seen),a
    ld a,c
    cp 1
    jp nz,sa_manifest_filename
    ld hl,(sa_value_ptr)
    ld de,sa_manifest_version
    call jcfg_equal_strings
    jp nz,sa_manifest_bad
    jp sa_manifest_line
sa_manifest_filename:
    ld hl,(sa_value_ptr)
    ld a,(hl)
    cp '/'
    jp z,sa_manifest_bad
    ; Relative leaf length <=127, joined global path <=239.
    push hl
    ld b,0
sa_manifest_length:
    ld a,(hl)
    or a
    jp z,sa_manifest_length_done
    inc b
    ld a,b
    cp 128
    jp nc,sa_manifest_pop_bad
    inc hl
    jp sa_manifest_length
sa_manifest_length_done:
    pop hl
    push ix
    call sa_join_asset
    pop ix
    jp nz,sa_manifest_bad
    ld hl,(sa_value_ptr)
    ld de,(ix+3)
    call jcfg_copy_string
    jp sa_manifest_line
sa_manifest_pop_bad:
    pop hl
sa_manifest_bad:
    ld a,0x45
    or a
    ret
sa_manifest_done:
    ld a,(sa_manifest_seen)
    cp 15
    jp nz,sa_manifest_bad
    xor a
    ret

; HL=relative asset name. Join without changing cwd; validate whole absolute path.
sa_join_asset:
    ld (sa_asset_leaf),hl
    ld hl,jcfg_skin_dir
    ld de,sa_asset_path
    call jcfg_copy_string
    dec de
    dec hl
    dec hl
    ld a,(hl)
    cp '/'
    jp z,sa_join_copy
    ld a,'/'
    ld (de),a
    inc de
sa_join_copy:
    ld hl,(sa_asset_leaf)
    ; Bounds established before copying: directory <=239, leaf <=127, plus
    ; slash and NUL fit 368 bytes. Then enforce the shared 239-byte path cap.
    call jcfg_copy_string
    ld hl,sa_asset_path
    call jcfg_validate_path
    ret nz
    ld de,sa_asset_path
    xor a
    ret

; Use canonical AGNB parser/stream/finalize primitives once per record. This
; application layer checks the complete 11-byte expected metadata before DATA.
sa_load_images:
    call agnb_open
    ret nz
    call agnb_read_riff_header
    jp nz,sa_images_failed
    call agnb_read_vers
    jp nz,sa_images_failed
    ld hl,sa_image_meta
    ld (sa_meta_ptr),hl
    ld a,sa_image_count
    ld (sa_images_left),a
sa_image_next:
    call agnb_read_buffer_list
    jp nz,sa_images_failed
    ld hl,agnb_metadata
    ld de,(sa_meta_ptr)
    ld b,11
sa_metadata_compare:
    ld a,(de)
    cp (hl)
    jp nz,sa_wrong_image
    inc de
    inc hl
    djnz sa_metadata_compare
    ld (sa_meta_ptr),de
    call agnb_stream_data
    jp nz,sa_images_failed
    call agnb_finalize_image
    jp nz,sa_images_failed
    call agnb_finish_buffer_list
    jp nz,sa_images_failed
    ld a,(sa_images_left)
    dec a
    ld (sa_images_left),a
    jp nz,sa_image_next
    ld hl,agnb_state+agnb_state_file_offset
    ld de,agnb_state+agnb_state_riff_end
    ld b,4
sa_images_end_check:
    ld a,(de)
    cp (hl)
    jp nz,sa_wrong_image
    inc hl
    inc de
    djnz sa_images_end_check
    jp agnb_close
sa_wrong_image:
    ld a,0x46
sa_images_failed:
    push af
    call agnb_close
    pop af
    or a
    ret

sa_wait_packet:
    ld a,1
sa_wait_mask:
    sla a
    djnz sa_wait_mask
    ld (sa_wait_flag),a
    ld hl,(ix+0)
    ld (sa_wait_start),hl
sa_wait_reply:
    ld a,(sa_wait_flag)
    and (ix+4)
    jp nz,sa_packet_ready
    ld hl,(ix+0)
    ld de,(sa_wait_start)
    or a
    sbc hl,de
    ld de,200
    or a
    sbc hl,de
    jp c,sa_wait_reply
    ld a,0x53
    or a
    ret
sa_packet_ready:
    xor a
    ret

sa_puts:
    push hl
    ld bc,0
    xor a
    rst.lil 0x18
    pop hl
sa_debug_puts:
    ld a,(hl)
    or a
    ret z
    out0 (0x30),a
    inc hl
    jp sa_debug_puts
sa_print_hex:
    push af
    rrca
    rrca
    rrca
    rrca
    call sa_screen_nibble
    pop af
sa_screen_nibble:
    and 15
    add a,'0'
    cp '9'+1
    jp c,sa_screen_hex
    add a,7
sa_screen_hex:
    out0 (0x30),a
    rst.lil 0x10
    ret
sa_debug_hex:
    push af
    rrca
    rrca
    rrca
    rrca
    call sa_debug_nibble
    pop af
sa_debug_nibble:
    and 15
    add a,'0'
    cp '9'+1
    jp c,sa_debug_digit
    add a,7
sa_debug_digit:
    out0 (0x30),a
    ret

sa_mode20: db 22,20
sa_initial: db 23,0,0xc0,0,23,1,0
sa_initial_end:
sa_restore_mode: db 22,0
    db 4,23,1,1,12
sa_restore_end:
sa_font8_create: db 23,0,0x95,1,0xf0,0x21,8,8,8,0
sa_font14_create: db 23,0,0x95,1,0xf1,0x21,8,14,14,0
sa_pixel_command: db 23,0,0x84,0,0,0,0
sa_wait_flag: db 0
sa_wait_start: dl 0
sa_old_mode: db 0
sa_mode_changed: db 0
sa_state: db 0
sa_error_code: db 0
sa_small_open: db 0
sa_small_close_error: db 0
sa_small_max: dl 0
sa_small_count: dl 0
sa_small_fil: blkb fil_dir_ptr+3,0
sa_small_data: blkb 4098,0
sa_manifest_seen: db 0
sa_manifest_cursor: dl 0
sa_line_start: dl 0
sa_key_ptr: dl 0
sa_value_ptr: dl 0
sa_asset_leaf: dl 0
sa_meta_ptr: dl 0
sa_images_left: db 0
sa_sample_ptr: dl 0
sa_samples_left: dl 0
sa_pixel_failures: dl 0
sa_asset_path: blkb 368,0
sa_graphics_file: blkb 128,0
sa_font8_file: blkb 128,0
sa_font14_file: blkb 128,0
sa_manifest_keys: dl sa_key_version,0,sa_key_graphics,sa_graphics_file,sa_key_font8,sa_font8_file,sa_key_font14,sa_font14_file
sa_key_version: asciz "format"
sa_key_graphics: asciz "graphics.file"
sa_key_font8: asciz "font8.file"
sa_key_font14: asciz "font14.file"
sa_manifest_version: asciz "skin004-proof1"
sa_ready: asciz "SKIN_ASSETS_READY\r\n"
sa_error_text: asciz "Jukebox skin/config error 0x"
sa_error_end: asciz ". Check /bin/jukebox.cfg and assets.\r\n"

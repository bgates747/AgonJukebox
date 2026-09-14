; Recovery UI uses only MOS text. No cwd changes; selection is session-only.
rt_request_switch:
    ld a,1
    ld (rt_switch),a
    ret
rt_set_root:
    ld hl,jcfg_skin_dir
    ld a,(hl)
    or a
    jr z,@default
    ld de,rt_root
    call jcfg_copy_string
    dec de
    dec de
    ld a,(de)
    cp '/'
    jr nz,@scan
    ld hl,rt_root
    or a
    sbc hl,de
    ret z
    dec de
@scan:
    ld a,(de)
    cp '/'
    jr z,@found
    dec de
    jr @scan
@found:
    inc de
    xor a
    ld (de),a
    ret
@default:
    ld hl,rt_default_root
    ld de,rt_root
    jp jcfg_copy_string
rt_choose:
    call rt_discover
    or a
    jr z,@show
    ld hl,rt_discovery_error
    call sa_puts
    ld a,1
    or a
    ret
@show:
    ld hl,rt_chooser_title
    call sa_puts
    ld hl,rt_root
    call sa_puts
    ld hl,rt_newline
    call sa_puts
    xor a
    ld (rt_choice_index),a
@list:
    ld a,(rt_choice_index)
    ld hl,rt_choice_count
    cp (hl)
    jr nc,@prompt
    add a,'0'
    rst.lil 0x10
    ld hl,rt_choice_separator
    call sa_puts
    ld a,(rt_choice_index)
    call rt_choice_address
    call sa_puts
    ld hl,rt_newline
    call sa_puts
    ld a,(rt_choice_index)
    inc a
    ld (rt_choice_index),a
    jr @list
@prompt:
    ld hl,rt_chooser_prompt
    ld a,(rt_choice_count)
    or a
    jr nz,@puts
    ld hl,rt_chooser_empty
@puts:
    call sa_puts
@key:
    MOSCALL mos_getkey
    cp 27
    jr z,@quit
    cp 'q'
    jr z,@quit
    cp 'r'
    jp z,rt_choose
    sub '0'
    jr c,@key
    ld hl,rt_choice_count
    cp (hl)
    jr nc,@key
    call rt_choice_address
    ld de,jcfg_skin_dir
    call jcfg_copy_string
    ld a,1
    ld (jcfg_valid),a
    xor a
    ret
@quit:
    ld a,1
    or a
    ret
rt_choice_address:
    ld hl,0
    ld l,a
    ld de,240
    call umul24
    ld de,rt_choices
    add hl,de
    ret
rt_discover:
    call rt_discovery_close
    ret nz
    xor a
    ld (rt_choice_count),a
    ld hl,rt_choice_dir
    ld de,rt_root
    FFSCALL ffs_dopen
    or a
    ret nz
    ld a,1
    ld (rt_dir_open),a
@next:
    ld hl,rt_choice_dir
    ld de,rt_choice_info
    FFSCALL ffs_dread
    or a
    jp nz,@failed
    ld a,(rt_choice_info+filinfo_fname)
    or a
    jp z,@done
    cp '.'
    jr z,@next
    ld a,(rt_choice_info+filinfo_fattrib)
    bit AM_DIR,a
    jr z,@next
    bit AM_HID,a
    jr nz,@next
    bit AM_SYS,a
    jr nz,@next
    ld hl,rt_root
    ld de,rt_choice_path
    ld b,240
    call rt_append
    jr nz,@next
    dec de
    inc b
    ld hl,rt_choice_info+filinfo_fname
    call rt_append
    jr nz,@next
    ld hl,rt_choice_path
    ld de,rt_choice_manifest
    call jcfg_copy_string
    dec de
    ld hl,rt_manifest_suffix
    call jcfg_copy_string
    ld hl,rt_choice_fil
    ld de,rt_choice_manifest
    ld c,fa_read
    FFSCALL ffs_fopen
    or a
    jr nz,@next
    ld a,1
    ld (rt_probe_open),a
    call rt_close_probe
    or a
    jr nz,@failed
    ld a,(rt_choice_count)
    call rt_choice_address
    ex de,hl
    ld hl,rt_choice_path
    call jcfg_copy_string
    ld a,(rt_choice_count)
    inc a
    ld (rt_choice_count),a
    cp 10
    jp c,@next
@done:
    jp rt_discovery_close
@failed:
    call rt_discovery_close
    ld a,1
    or a
    ret
rt_append:
    ld a,(hl)
    inc hl
    or a
    jr z,@nul
    cp 32
    jr c,@bad
    cp 127
    jr nc,@bad
    ld (de),a
    inc de
    djnz rt_append
@bad:
    ld a,1
    or a
    ret
@nul:
    ld (de),a
    inc de
    dec b
    xor a
    ret
rt_switch: db 0
rt_choice_count: db 0
rt_choice_index: db 0
rt_default_root: asciz "/jukebox/skins/"
rt_root: blkb 240,0
rt_choices: blkb 2400,0
rt_choice_path: blkb 240,0
rt_choice_manifest: blkb 256,0
rt_choice_dir: blkb dir_struct_size,0
rt_choice_info: blkb filinfo_struct_size,0
rt_choice_fil: blkb fil_dir_ptr+3,0
rt_manifest_suffix: asciz "/skin.cfg"
rt_newline: asciz "\r\n"
rt_choice_separator: asciz ") "
rt_chooser_title: asciz "\r\nJukebox skins (first ten packages)\r\n"
rt_chooser_prompt: asciz "0-9 choose | r refresh | q/Esc return to MOS\r\n"
rt_chooser_empty: asciz "No skin packages found. r refresh | q/Esc return to MOS\r\n"
rt_discovery_error: asciz "Cannot read skin directory. Returning to MOS.\r\n"

; Keep failed-close structures owned and retry before any reuse or exit.
rt_close_probe:
    ld a,(rt_probe_open)
    or a
    ret z
    ld hl,rt_choice_fil
    FFSCALL ffs_fclose
    or a
    ret nz
    ld (rt_probe_open),a
    ret
rt_discovery_close:
    call rt_close_probe
    ld (rt_close_error),a
    ld a,(rt_dir_open)
    or a
    jr z,@result
    ld hl,rt_choice_dir
    FFSCALL ffs_dclose
    or a
    ret nz
    ld (rt_dir_open),a
@result:
    ld a,(rt_close_error)
    or a
    ret
rt_probe_open: db 0
rt_dir_open: db 0
rt_close_error: db 0

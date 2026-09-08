; Jukebox global config reader. See docs/configuration.md for the contract.
; ADL=1; consumer supplies FFSCALL and standard MOS/FatFS constants.
; Public entry points preserve BC, DE, HL, IX, IY; return A=status, Z=success.
; Synchronous, non-reentrant; no VDU output, writes, asset loads or implicit cd.

jcfg_max_file: equ 4096
jcfg_max_line: equ 255
jcfg_max_path: equ 239
jcfg_max_keys: equ 32
jcfg_ok: equ 0
jcfg_missing: equ 1
jcfg_open_error: equ 2
jcfg_read_error: equ 3
jcfg_close_error: equ 4
jcfg_file_long: equ 5
jcfg_encoding: equ 6
jcfg_line_long: equ 7
jcfg_syntax: equ 8
jcfg_duplicate: equ 9
jcfg_version: equ 10
jcfg_required: equ 11
jcfg_path_error: equ 12
jcfg_keys_full: equ 13
jcfg_key_long: equ 14
jcfg_not_ready: equ 15
jcfg_skin_error: equ 16
jcfg_music_error: equ 17
jcfg_dir_close_error: equ 18

jcfg_filename: asciz "/bin/jukebox.cfg"
jcfg_key_format: asciz "format"
jcfg_key_skin: asciz "skin_dir"
jcfg_key_music: asciz "music_dir"
jcfg_manifest_leaf: asciz "skin.cfg"

jcfg_load:
    push bc
    push de
    push hl
    push ix
    push iy
    ld de,jcfg_filename
    call jcfg_load_core
    jp jcfg_return

; HL=data, BC=length. Buffer need not have a terminator and is never modified.
jcfg_parse:
    push bc
    push de
    push hl
    push ix
    push iy
    push hl
    push bc
    call jcfg_reset
    pop bc
    pop hl
    jp nz,jcfg_return
    call jcfg_parse_core
    jp jcfg_return

jcfg_init:
    push bc
    push de
    push hl
    push ix
    push iy
    call jcfg_reset
jcfg_return:
    pop iy
    pop ix
    pop hl
    pop de
    pop bc
    or a
    ret

jcfg_reset:
    call jcfg_release_pending
    ret nz
    ld hl,jcfg_state
    ld de,jcfg_state+1
    ld bc,jcfg_state_end-jcfg_state-1
    xor a
    ld (hl),a
    ldir
    ret

; Internal DE=filename entry also exercised by the file-fixture harness.
jcfg_load_core:
    push de
    call jcfg_reset
    pop de
    ret nz
    ld hl,jcfg_fil
    ld c,fa_read
    FFSCALL ffs_fopen
    or a
    jp z,jcfg_opened
    ld (jcfg_io_error),a
    cp 4                         ; FR_NO_FILE
    jp z,jcfg_no_file
    cp 5                         ; FR_NO_PATH
    jp z,jcfg_no_file
    ld a,jcfg_open_error
    jp jcfg_fail
jcfg_no_file:
    ld a,jcfg_missing
    jp jcfg_fail
jcfg_opened:
    ld a,1
    ld (jcfg_file_open),a
    ld hl,jcfg_fil
    ld de,jcfg_input
    ld bc,jcfg_max_file+1         ; sentinel byte detects overflow without FIL size
    FFSCALL ffs_fread
    ld (jcfg_read_count),bc      ; ADL24 OK: dl byte count
    ld (jcfg_read_result),a
    ld hl,jcfg_fil
    FFSCALL ffs_fclose           ; close attempt; retain handle on failure
    ld (jcfg_close_result),a
    or a
    jp nz,jcfg_close_attempted
    xor a
    ld (jcfg_file_open),a
jcfg_close_attempted:
    ld a,(jcfg_read_result)
    or a
    jp z,jcfg_read_ok
    ld (jcfg_io_error),a
    ld a,jcfg_read_error
    jp jcfg_fail
jcfg_read_ok:
    ld a,(jcfg_close_result)
    or a
    jp z,jcfg_closed
    ld (jcfg_io_error),a
    ld a,jcfg_close_error
    jp jcfg_fail
jcfg_closed:
    ld hl,jcfg_input
    ld bc,(jcfg_read_count)      ; ADL24 OK: dl byte count
    jp jcfg_parse_core

jcfg_parse_core:
    ld (jcfg_source),hl         ; ADL24 OK: dl pointer
    ld (jcfg_remaining),bc      ; ADL24 OK: dl count
    ld hl,jcfg_max_file
    or a
    sbc hl,bc
    ld a,jcfg_file_long
    jp c,jcfg_fail
    ld hl,1
    ld (jcfg_line),hl           ; ADL24 OK: dl line number
jcfg_next_line:
    ld hl,0
    ld (jcfg_line_length),hl    ; ADL24 OK: dl count
    ld hl,jcfg_line_buffer
    ld (jcfg_line_write),hl     ; ADL24 OK: dl pointer
jcfg_next_char:
    call jcfg_get_char
    jp c,jcfg_end_input
    cp 10
    jp z,jcfg_end_line
    cp 13
    jp z,jcfg_cr
    cp 9
    jp z,jcfg_append
    cp 32
    jp c,jcfg_bad_encoding
    cp 127
    jp nc,jcfg_bad_encoding
jcfg_append:
    ld hl,(jcfg_line_length)    ; ADL24 OK: dl count
    ld de,jcfg_max_line
    or a
    sbc hl,de
    jp z,jcfg_long_line
    ld hl,(jcfg_line_length)
    inc hl
    ld (jcfg_line_length),hl
    ld hl,(jcfg_line_write)
    ld (hl),a
    inc hl
    ld (jcfg_line_write),hl
    jp jcfg_next_char
jcfg_cr:
    call jcfg_get_char
    jp c,jcfg_bad_encoding
    cp 10
    jp nz,jcfg_bad_encoding
jcfg_end_line:
    call jcfg_process_line
    jp nz,jcfg_fail
    ld hl,(jcfg_line)
    inc hl
    ld (jcfg_line),hl
    jp jcfg_next_line
jcfg_end_input:
    call jcfg_process_line
    jp nz,jcfg_fail
    ld a,(jcfg_seen)
    and 3
    cp 3
    ld a,jcfg_required
    jp nz,jcfg_fail
    ld a,1
    ld (jcfg_valid),a
    xor a
    ld (jcfg_error),a
    ld hl,0
    ld (jcfg_line),hl
    ret
jcfg_bad_encoding:
    ld a,jcfg_encoding
    jp jcfg_fail
jcfg_long_line:
    ld a,jcfg_line_long
    jp jcfg_fail

; Carry=eof, otherwise A=byte. Other working registers clobbered.
jcfg_get_char:
    ld hl,(jcfg_remaining)
    ld a,h
    or l                        ; remaining has been bounded to <=4096
    scf
    ret z
    dec hl
    ld (jcfg_remaining),hl
    ld hl,(jcfg_source)
    ld a,(hl)
    inc hl
    ld (jcfg_source),hl
    or a                        ; clear carry, including for NUL
    ret

jcfg_process_line:
    ld hl,(jcfg_line_write)
    ld (hl),0
    ld hl,jcfg_line_buffer
    call jcfg_trim
    ld a,(hl)
    or a
    ret z
    cp '#'
    jp z,jcfg_empty_line
    cp ';'
    jp z,jcfg_empty_line
    ld (jcfg_key_ptr),hl
jcfg_find_equal:
    ld a,(hl)
    or a
    jp z,jcfg_bad_syntax
    cp '='
    jp z,jcfg_equal
    inc hl
    jp jcfg_find_equal
jcfg_equal:
    ld (hl),0
    inc hl
    call jcfg_trim
    ld a,(hl)
    or a
    jp z,jcfg_bad_syntax
    ld (jcfg_value_ptr),hl
    ld hl,(jcfg_key_ptr)
    call jcfg_trim
    ld (jcfg_key_ptr),hl
    ld a,(hl)
    or a
    jp z,jcfg_bad_syntax
    ld b,0
jcfg_key_scan:
    ld a,(hl)
    or a
    jp z,jcfg_key_done
    inc b
    ld a,b
    cp 32
    jp nc,jcfg_long_key
    ld a,(hl)
    cp 'A'
    jp c,jcfg_key_lower
    cp 'Z'+1
    jp nc,jcfg_key_lower
    add a,32
    ld (hl),a
jcfg_key_lower:
    cp '_'
    jp z,jcfg_key_char_ok
    cp 'a'
    jp c,jcfg_key_digit
    cp 'z'+1
    jp c,jcfg_key_char_ok
jcfg_key_digit:
    cp '0'
    jp c,jcfg_bad_syntax
    cp '9'+1
    jp nc,jcfg_bad_syntax
    ld a,b
    cp 1
    jp z,jcfg_bad_syntax
jcfg_key_char_ok:
    inc hl
    jp jcfg_key_scan
jcfg_key_done:
    call jcfg_register_key
    ret nz
    ld hl,(jcfg_key_ptr)
    ld de,jcfg_key_format
    call jcfg_equal_strings
    jp z,jcfg_format_value
    ld hl,(jcfg_key_ptr)
    ld de,jcfg_key_skin
    call jcfg_equal_strings
    jp z,jcfg_skin_value
    ld hl,(jcfg_key_ptr)
    ld de,jcfg_key_music
    call jcfg_equal_strings
    jp z,jcfg_music_value
    ld a,(jcfg_warnings)
    inc a
    ld (jcfg_warnings),a
    cp 1
    jp nz,jcfg_empty_line
    ld hl,(jcfg_line)
    ld (jcfg_warning_line),hl
jcfg_empty_line:
    xor a
    ret
jcfg_bad_syntax:
    ld a,jcfg_syntax
    or a
    ret
jcfg_long_key:
    ld a,jcfg_key_long
    or a
    ret

; Lowercased key must be unique, including unknown keys. Slots are 32 bytes.
jcfg_register_key:
    ld a,(jcfg_key_count)
    ld b,a
    ld de,jcfg_keys
    or a
    jp z,jcfg_store_key
jcfg_key_loop:
    push bc
    push de
    ld hl,(jcfg_key_ptr)
    call jcfg_equal_strings
    pop de
    pop bc
    jp z,jcfg_dup_key
    ld hl,32
    add hl,de
    ex de,hl
    djnz jcfg_key_loop
jcfg_store_key:
    ld a,(jcfg_key_count)
    cp jcfg_max_keys
    jp z,jcfg_too_many_keys
    inc a
    ld (jcfg_key_count),a
    ld hl,(jcfg_key_ptr)
    call jcfg_copy_string
    xor a
    ret
jcfg_dup_key:
    ld a,jcfg_duplicate
    or a
    ret
jcfg_too_many_keys:
    ld a,jcfg_keys_full
    or a
    ret

jcfg_format_value:
    ld hl,(jcfg_value_ptr)
    ld a,(hl)
    cp '1'
    jp nz,jcfg_bad_version
    inc hl
    ld a,(hl)
    or a
    jp nz,jcfg_bad_version
    ld a,(jcfg_seen)
    or 1
    ld (jcfg_seen),a
    xor a
    ret
jcfg_bad_version:
    ld a,jcfg_version
    or a
    ret
jcfg_skin_value:
    ld hl,(jcfg_value_ptr)
    call jcfg_validate_path
    ret nz
    ld hl,(jcfg_value_ptr)
    ld de,jcfg_skin_dir
    call jcfg_copy_string
    ld a,(jcfg_seen)
    or 2
    ld (jcfg_seen),a
    xor a
    ret
jcfg_music_value:
    ld hl,(jcfg_value_ptr)
    call jcfg_validate_path
    ret nz
    ld hl,(jcfg_value_ptr)
    ld de,jcfg_music_dir
    call jcfg_copy_string
    xor a
    ret

; ASCII absolute FAT path, <=239 bytes. Normalize one trailing slash.
; Reject empty components, dot components, trailing dot/space and FAT wildcards.
jcfg_validate_path:
    ld a,(hl)
    cp '/'
    jp nz,jcfg_bad_path
    ld b,0
    push hl
jcfg_path_length:
    ld a,(hl)
    or a
    jp z,jcfg_path_measured
    inc b
    ld a,b
    cp jcfg_max_path+1
    jp nc,jcfg_path_pop_error
    inc hl
    jp jcfg_path_length
jcfg_path_measured:
    pop hl
    inc hl
    ld a,(hl)
    or a
    ret z                       ; root is valid
jcfg_component:
    ld a,(hl)
    cp '/'
    jp z,jcfg_bad_path
    ld c,a                      ; previous char; component cannot begin with space
    cp ' '
    jp z,jcfg_bad_path
jcfg_path_char:
    ld a,(hl)
    or a
    jp z,jcfg_path_component_end
    cp '/'
    jp z,jcfg_path_component_end
    cp 32
    jp c,jcfg_bad_path
    cp 127
    jp nc,jcfg_bad_path
    cp 92                       ; backslash
    jp z,jcfg_bad_path
    cp ':'
    jp z,jcfg_bad_path
    cp '*'
    jp z,jcfg_bad_path
    cp '?'
    jp z,jcfg_bad_path
    cp 34                       ; double quote
    jp z,jcfg_bad_path
    cp '<'
    jp z,jcfg_bad_path
    cp '>'
    jp z,jcfg_bad_path
    cp '|'
    jp z,jcfg_bad_path
    ld c,a
    inc hl
    jp jcfg_path_char
jcfg_path_component_end:
    ld a,c
    cp '.'                      ; also rejects . and .. components
    jp z,jcfg_bad_path
    cp ' '
    jp z,jcfg_bad_path
    ld a,(hl)
    or a
    ret z
    inc hl
    ld a,(hl)
    or a
    jp nz,jcfg_component
    dec hl
    ld (hl),0                   ; strip trailing separator (except root)
    xor a
    ret
jcfg_path_pop_error:
    pop hl
jcfg_bad_path:
    ld a,jcfg_path_error
    or a
    ret

; Trim space/tab in place, return HL=start. Source is private line buffer only.
jcfg_trim:
    ld a,(hl)
    cp ' '
    jp z,jcfg_trim_lead
    cp 9
    jp nz,jcfg_trim_start
jcfg_trim_lead:
    inc hl
    jp jcfg_trim
jcfg_trim_start:
    push hl
jcfg_trim_scan:
    ld a,(hl)
    or a
    jp z,jcfg_trim_tail
    inc hl
    jp jcfg_trim_scan
jcfg_trim_tail:
    pop de
    push de
jcfg_trim_back:
    or a
    push hl
    sbc hl,de
    pop hl
    jp z,jcfg_trim_done
    dec hl
    ld a,(hl)
    cp ' '
    jp z,jcfg_trim_zero
    cp 9
    jp nz,jcfg_trim_done
jcfg_trim_zero:
    ld (hl),0
    jp jcfg_trim_back
jcfg_trim_done:
    pop hl
    ret

jcfg_equal_strings:
    ld a,(de)
    cp (hl)
    ret nz
    or a
    ret z
    inc hl
    inc de
    jp jcfg_equal_strings
jcfg_copy_string:
    ld a,(hl)
    ld (de),a
    inc hl
    inc de
    or a
    jp nz,jcfg_copy_string
    ret

; Error clears all exposed settings; diagnostics and warning count remain.
jcfg_fail:
    ld (jcfg_error),a
    push af
    xor a
    ld (jcfg_valid),a
    ld hl,jcfg_outputs
    ld de,jcfg_outputs+1
    ld bc,jcfg_outputs_end-jcfg_outputs-1
    ld (hl),a
    ldir
    pop af
    or a
    ret

; Construct skin_dir + /skin.cfg in jcfg_manifest. No filesystem side effects.
jcfg_manifest_path:
    push bc
    push de
    push hl
    push ix
    push iy
    call jcfg_require_valid
    jp nz,jcfg_helper_return
    ld hl,jcfg_skin_dir
    ld de,jcfg_manifest
    call jcfg_copy_string
    dec de
    dec hl
    dec hl
    ld a,(hl)
    cp '/'
    jp z,jcfg_join_leaf
    ld a,'/'
    ld (de),a
    inc de
jcfg_join_leaf:
    ld hl,jcfg_manifest_leaf
    call jcfg_copy_string      ; <=239+1+8+1 =249 bytes in 256-byte buffer
    xor a
    jp jcfg_helper_return

; Check skin directory can be opened without changing cwd. Does not parse skin.cfg.
jcfg_check_skin:
    push bc
    push de
    push hl
    push ix
    push iy
    call jcfg_require_valid
    jp nz,jcfg_helper_return
    call jcfg_release_pending
    jp nz,jcfg_helper_return
    ld hl,jcfg_dir
    ld de,jcfg_skin_dir
    FFSCALL ffs_dopen
    or a
    jp z,jcfg_skin_open
    ld (jcfg_io_error),a
    ld a,jcfg_skin_error
    jp jcfg_helper_return
jcfg_skin_open:
    ld a,1
    ld (jcfg_dir_open),a
    call jcfg_release_pending
    jp jcfg_helper_return

; Never overwrite an unresolved handle. A later init/load/parse retries close.
; Failure invalidates outputs and retains the structure and open flag.
jcfg_release_pending:
    ld a,(jcfg_file_open)
    or a
    jp z,jcfg_release_dir
    ld hl,jcfg_fil
    FFSCALL ffs_fclose
    ld (jcfg_close_result),a
    or a
    jp z,jcfg_file_released
    ld (jcfg_io_error),a
    ld a,jcfg_close_error
    jp jcfg_fail
jcfg_file_released:
    xor a
    ld (jcfg_file_open),a
jcfg_release_dir:
    ld a,(jcfg_dir_open)
    or a
    ret z
    ld hl,jcfg_dir
    FFSCALL ffs_dclose
    or a
    jp z,jcfg_dir_released
    ld (jcfg_io_error),a
    ld a,jcfg_dir_close_error
    jp jcfg_fail
jcfg_dir_released:
    xor a
    ld (jcfg_dir_open),a
    ret

; Explicit opt-in cd: omitted music is a no-op. Failure reported to the caller.
jcfg_apply_music:
    push bc
    push de
    push hl
    push ix
    push iy
    call jcfg_require_valid
    jp nz,jcfg_helper_return
    ld a,(jcfg_music_dir)
    or a
    jp z,jcfg_helper_return
    ld hl,jcfg_music_dir
    FFSCALL ffs_chdir
    or a
    jp z,jcfg_helper_return
    ld (jcfg_io_error),a
    ld a,jcfg_music_error
jcfg_helper_return:
    ld (jcfg_error),a
    jp jcfg_return
jcfg_require_valid:
    xor a
    ld (jcfg_io_error),a
    ld a,(jcfg_valid)
    or a
    jp nz,jcfg_is_valid
    ld a,jcfg_not_ready
    or a
    ret
jcfg_is_valid:
    xor a
    ret

; Every wide memory access in this include targets dl storage, except the
; documented byte buffers passed to LDIR and the MOS-owned FIL/DIR structures.
jcfg_state:
jcfg_error: db 0
jcfg_valid: db 0
jcfg_io_error: db 0
jcfg_warnings: db 0
jcfg_warning_line: dl 0
jcfg_line: dl 0
jcfg_file_open: db 0
jcfg_dir_open: db 0
jcfg_read_result: db 0
jcfg_close_result: db 0
jcfg_read_count: dl 0
jcfg_seen: db 0
jcfg_key_count: db 0
jcfg_key_ptr: dl 0
jcfg_value_ptr: dl 0
jcfg_source: dl 0
jcfg_remaining: dl 0
jcfg_line_length: dl 0
jcfg_line_write: dl 0
jcfg_outputs:
jcfg_skin_dir: blkb 240,0
jcfg_music_dir: blkb 240,0
jcfg_manifest: blkb 256,0
jcfg_outputs_end:
jcfg_fil: blkb fil_dir_ptr+3,0
jcfg_dir: blkb dir_struct_size,0
jcfg_keys: blkb 1024,0
jcfg_line_buffer: blkb 256,0
jcfg_state_end:
jcfg_input: blkb jcfg_max_file+1,0

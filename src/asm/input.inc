get_input:
; wait for the user to push a button
    ei ; enable interrupts
    MOSCALL mos_getkey ; a = ascii code of key pressed
    di ; disable interrupts

; RETURN TO MAIN, which re-enables interrupts and exits app
    cp '\e' ; escape
    ret z 
    cp 'q' ; quit
    ret z

; CHECK FOR FUNCTION KEYS
    or a ; will be zero if function, alt, ctl, caps lock, or shift keys pressed
    jp z,@check_fkeys

; FILE BROWSER COMMANDS
    cp 0x0B ; up arrow
    jp z,bf_prev_file
    cp 0x0A ; down arrow
    jp z,bf_next_file
    cp 0x15 ; right arrow
    jp z,bf_next_page
    cp 0x08 ; left arrow
    jp z,bf_prev_page
    cp 'u' ; go up one directory
    jp z,bf_up_dir

; SONG PLAYING COMMANDS
; set volume commands
    cp '.' ; increase volume
    jp z,ps_volume_up
    cp ',' ; decrease volume
    jp z,ps_volume_down
; set seek speed commands
    cp '-' ; slow down
    jp z,ps_seek_slow
    cp '=' ; speed up (means +)
    jp z,ps_seek_fast
; seek back / forward
    cp '['
    jp z,ps_seek_back
    cp ']'
    jp z,ps_seek_fwd
; toggle play / pause
    cp 'p'
    jp z,ps_toggle_pause
; toggle loop 
    cp 'l'
    jp z,ps_toggle_loop
; toggle shuffle 
    cp 's'
    jp z,ps_toggle_shuffle
; play random song
    cp 'r'
    jp z,ps_play_random
; select song or directory
    cp '\r' ; ENTER key
    jp z,bf_select_file
; audio limit update commands
    cp 'd'
    jp z,ps_set_audio_limit_settings
    cp 'c'
    jp z,ps_set_audio_limit_settings
    cp 'f'
    jp z,ps_set_audio_limit_settings
    cp 'v'
    jp z,ps_set_audio_limit_settings
    cp 'g'
    jp z,ps_set_audio_limit_settings
    cp 'b'
    jp z,ps_set_audio_limit_settings
; number key selections
    cp '0'
    jp c,@no_cmd ; not a song command
    cp '9'+1
    jp nc,@no_cmd ; not a song command
; select song or directory
    sub '0' ; a = file index
    ld (bf_file_idx),a
    jp bf_select_file
@no_cmd: ; no valid commands so go back to user input
    jp get_input

@check_fkeys:
    MOSCALL mos_getkbmap ; ix points to vdp-gl virtual keys map

; check for audio limit update commands
; 114 F1
    bit 1,(ix+14)
    jr z,@F
    ld a,vdu_audio_limit_default
    jp ps_set_audio_limit_method
@@:
; 115 F2
    bit 2,(ix+14)
    jr z,@F
    ld a,vdu_audio_limit_none
    jp ps_set_audio_limit_method
@@:
; 116 F3
    bit 3,(ix+14)
    jr z,@F
    ld a,vdu_audio_limit_log_compress
    jp ps_set_audio_limit_method
@@:
; 21 F4
    bit 4,(ix+2)
    jr z,@F
    ld a,vdu_audio_limit_constant_divisor
    jp ps_set_audio_limit_method
@@:
; 117 F5
    bit 4,(ix+14)
    jr z,@F
    ld a,vdu_audio_limit_active_channels
    jp ps_set_audio_limit_method
@@:
    jp get_input ; no valid function key pressed, return to input loop

@play_song:
    call bf_highlight_file ; highlight the selected file
    jp play_song ; play the song
; end get_input

get_rand_file_idx:
    ld a,(bf_files_cur_pg)
    or a
    ret z ; no files on page
    ld l,a
    call rand_8 ; a = 0-255
    ld h,a
    call udiv8 ; a = mod(a,bf_files_per_pg)
    ld (bf_file_idx),a
    ret

get_prev_file_idx:
; get number of files on current page
    ld a,(bf_files_cur_pg)
    ld b,a
; decrement the file index
    ld a,(bf_file_idx)
    dec a
    cp b
    jp c,@F ; check for wraparound
    ld a,b ; get the number of files this page
    dec a ; zero-based
@@:
    ld (bf_file_idx),a
    ret
; end get_prev_file_idx

bf_prev_file:
    call get_prev_file_idx
    call bf_highlight_file ; highlight the file
    jp get_input
; end bf_prev_file

get_next_file_idx:
; get number of files on current page
    ld a,(bf_files_cur_pg)
    ld b,a
; increment the file index
    ld a,(bf_file_idx)
    inc a
    cp b
    jp c,@F ; check for wraparound
    xor a ; wrap around to the first file
@@:
    ld (bf_file_idx),a
    ret
; end get_next_file_idx

bf_next_file:
    call get_next_file_idx
    call bf_highlight_file ; highlight the file
    jp get_input
; end bf_next_file

bf_next_page:
; advance the page number
    ld de,(bf_page_cur) ; get the current page number
    inc de ; increment the page number
    ld hl,(bf_dir_num_pages) ; get the number of pages
    dec hl ; zero-based
    or a ; clear carry
    sbc hl,de
    jp p,@F ; not the last page
    ld de,0 ; wrap around to the first page
@@:
; print the new page
    ld (bf_page_cur),de
    xor a
    ld (bf_file_idx),a ; reset the file index
    call bf_get_page_num_files ; get the number of files on the new page and store it
    call bf_highlight_file ; highlight the first file    
    jp get_input
; end bf_next_page

bf_prev_page:
; decrement the page number
    ld hl,(bf_page_cur) ; get the current page number
    dec hl ; decrement the page number
    SIGN_UHL
    jp p,@F ; not time to wrap around
    ld hl,(bf_dir_num_pages) ; get the number of pages
    dec hl ; zero-based
@@:
; print the new page
    ld (bf_page_cur),hl 
    xor a
    ld (bf_file_idx),a ; reset the file index
    call bf_get_page_num_files ; get the number of files on the new page and store it
    call bf_highlight_file ; highlight the first file
    jp get_input
; end bf_prev_page

str_up_dir: asciz ".."
; change directory one level up
; inputs: none
bf_up_dir:
    ld hl,str_up_dir
; change directory
; inputs: hl = pointer to directory name
bf_change_dir:
    MOSCALL mos_cd ; change to the directory
; stop the PRT timer and disable interrupts
    call ps_prt_stop ; stop the PRT timer
 ; get directory listing
    call bf_get_dir
    ld hl,0
    ld (bf_page_cur),hl ; reset the page number
    xor a
    ld (bf_file_idx),a ; reset the file index
    call bf_highlight_file ; highlight the first file
    call bf_print_dir_name ; print the directory name
; restart the PRT timer
    call ps_prt_start ; start the PRT timer
    jp get_input ; back to main loop (will re-enable interrupts)
; end bf_change_dir
; end bf_up_dir

bf_select_file:
; set up pointers to the fileinfo struct and filename
    call bf_get_filinfo_from_pg_idx ; iy = pointer to filinfo struct
    ld hl,bf_fil_struct ; hl = pointer to fil struct
    lea de,iy+filinfo_fname ; de = pointer to filename
    call bf_verify_wav
    lea hl,iy+filinfo_fname ; hl = pointer to filename
    jp z,bf_change_dir ; not a .wav file, so must be a directory
; play the .wav file
    call bf_highlight_file ; highlight the selected file
    jp play_song
; end bf_select_file

; get a pointer to a filinfo struct from a directory page index
; inputs: none
; outputs: iy = pointer to the filinfo struct
bf_get_filinfo_from_pg_idx:
; get the fileinfo pointer from the fileinfo pointer table
    ld hl,(bf_page_cur) ; get the current page number
    ld de,bf_files_per_pg*3 ; number of files per page * 3 bytes per pointer
    call umul24 ; hl = page * num_files_per_page
    ld a,(bf_file_idx) ; get the file index
    ld e,a ; file index
    ld d,3 ; 3 bytes per pointer
    mlt de ; de = file index * 3
    add hl,de
    ex de,hl ; can't add iy,hl ...
    ld iy,bf_filinfo_ptrs ; get the pointer to the fileinfo pointer table
    add iy,de ; iy points to the first fileinfo pointer in the current page
    ld iy,(iy) ; iy points to the filinfo record
    ret
; end bf_get_filinfo_from_pg_idx

ps_volume_up:
    ld a,(ps_volume)
    cp 11 ; max volume
    jp z,get_input ; already at max volume so return to input
    inc a ; increase volume
    ld (ps_volume),a
    call ps_adjust_volume
    jp get_input
; end ps_volume_up

ps_volume_down:
    ld a,(ps_volume)
    or a ; zero check for min volume
    jp z,get_input ; already at min volume so return to input
    dec a ; decrease volume
    ld (ps_volume),a
    call ps_adjust_volume
    jp get_input
; end ps_volume_down

; adjust master volume
; inputs: a = new volume (0-11)
; outputs: prints the new volume to the screen
; destroys: af, hl, bc
ps_adjust_volume:
; save the new volume and set the volume for all channels
    ld b,a ; volume
    ld c,12
    mlt bc
    ld b,c ; b = volume * 12
    ld c,-1 ; channel -1 = global volume
    call vdu_channel_volume
; print the new volume
    call vp_legend_volume
    call vdu_cls
    ld a,(ps_volume)
    call printDec8 ; print the volume
; restore the '<' character that got stomped on
    call vdu_home_cursor
    ld a,'<'
    rst.lil 10h ; print the '<' character
    ret
; end ps_adjust_volume

ps_toggle_pause:
    call vp_now_playing
    call vdu_cls
    ld hl,ps_mode
    bit ps_mode_playing,(hl)
    jp nz,@playing
    set ps_mode_playing,(hl)
    call printInline
    asciz "(P)laying "
    jp @print
@playing:
    res ps_mode_playing,(hl)
    call printInline
    asciz "(P)aused  "
@print:
    ld hl,ps_filinfo_fname
    call printString ; print the song filename
    jp get_input
; end ps_toggle_pause

ps_toggle_shuffle:
    call vp_legend_shuffle
    call vdu_cls
    ld hl,ps_mode
    bit ps_mode_shuffle,(hl)
    jp nz,@shuffling
    call set_text_colours_inverse
    ld hl,ps_mode
    set ps_mode_shuffle,(hl)
    call printInline
    asciz "ON"
    call set_text_colours_normal
    jp get_input
@shuffling:
    res ps_mode_shuffle,(hl)
    call printInline
    asciz "OFF"
    jp get_input
; end ps_toggle_shuffle

ps_toggle_loop:
    call vp_legend_loop
    call vdu_cls
    ld hl,ps_mode
    bit ps_mode_loop,(hl)
    jp nz,@looping
    call set_text_colours_inverse
    ld hl,ps_mode
    set ps_mode_loop,(hl)
    call printInline
    asciz "ON"
    call set_text_colours_normal
    jp get_input
@looping:
    res ps_mode_loop,(hl)
    call printInline
    asciz "OFF"
    jp get_input
; end ps_toggle_loop

ps_seek_slow:
    ld a,(ps_seek_rate_idx)
    dec a
    jp ps_set_seek_rate
; end ps_seek_slow

ps_seek_fast:
    ld a,(ps_seek_rate_idx)
    inc a
; fall through to ps_seek_rate
; end ps_seek_fast

ps_set_seek_rate:
    and 7 ; mod 8
    ld (ps_seek_rate_idx),a
    ld hl,ps_seek_rate_idx+1
    ld de,0
    ld e,a
    add hl,de
    ld a,(hl)
    ld (ps_seek_rate),a
    call vp_seek_rate
    call vdu_cls
    ld a,(ps_seek_rate)
    call printDec8
    jp get_input
; end ps_set_seek_rate

ps_seek_back:
; stop the PRT timer and disable interrupts
    call ps_prt_stop ; stop the PRT timer
; negate seek rate
    ld de,(ps_seek_rate)
    ld hl,0
    or a ; clear carry
    sbc hl,de ; hl -seek_rate
    jp ps_seek
; end ps_seek_back

ps_seek_fwd:
; stop the PRT timer and disable interrupts
    call ps_prt_stop ; stop the PRT timer
; seek forward
    ld hl,(ps_seek_rate)
; fall through to ps_seek
; end ps_seek_fwd

ps_seek:
; compute new playhead position and update the playbar
    ld de,(ps_playhead)
    add hl,de ; hl = playhead + seek_rate
    dec hl ; to offset an inc we get further down somewhere
; handle wraparound 
    ld de,(ps_song_duration)
    SIGN_UHL
    jp z,@print
    jp p,@mod
    or a ; clear carry for adc because
    adc hl,de ; add doesn't set sign flag
    jp p,@print
    call neg_hlu
    jp @print
@mod:
    call udiv24
@print:
; save new playhead position and update the playbar
    ld (ps_playhead),hl 
    call ps_update_playbar
; reset the chunk counter
    ld a,ps_chunks_per_second
    ld (ps_wav_chunk_counter),a
; multiply new playhead position by sample rate
    ld ix,ps_wav_header+wav_sample_rate
    call fetch_int_nor
    ld ix,ps_playhead
    call fetch_int_alt
    ld a,fmul
    call FPP ; HLH'L' = seek position from start of file in bytes less .wav header
    call SWAP
    ld hl,76 ; wav header size
    call hlu2float
    ld a,fadd
    call FPP ; HLH'L' = seek position from start of file in bytes
    ld ix,@seek_pos
    call store_int_nor
; seek to new position and load the next block of data
    ld hl,ps_fil_struct
    ld de,(@seek_pos) ; low 3 bytes of seek position
    ld a,(@seek_pos+3) ; high byte of seek position
    ld c,a
    FFSCALL ffs_flseek
; flip the command and sample buffers and read the first block of data at the new position
    call ps_load_audio_cmd_buffers ; TODO: we should only have to do this on app init, 
                                 ; but if we don't do it here, only one audio buffer 
                                 ; is loaded or/and played
    call ps_set_audio_buffers         ; this is crucial so that the next sound played is at new position
; restart the PRT timer
    call ps_prt_start ; start the PRT timer
    jp get_input ; will reenable interrupts
@seek_pos: dw32 0 ; temp buffer for seek position
; end ps_seek

; set the audio limit method
; inputs: a = value to set vdu_audio_limit_method
; outputs: sets vdu_audio_limit_method
; destroys: af, hl, bc
ps_set_audio_limit_method:
; update the audio limit method
    ld (vdu_audio_limit_method),a
; set the audio limit method to default
    cp vdu_audio_limit_default
    jr nz,@F
    call vdu_set_audio_limit_default
    jp get_input
@@:
; set the audio limit method to none
    cp vdu_audio_limit_none
    jr nz,@F
    call vdu_set_audio_limit_none
    jp get_input
@@:
; set the audio limit method to log compress
    cp vdu_audio_limit_log_compress
    jr nz,@F
    call vdu_set_audio_limit_log_compress
    jp get_input
@@:
; set the audio limit method to constant divisor
    cp vdu_audio_limit_constant_divisor
    jr nz,@F
    call vdu_set_audio_limit_constant_divisor
    jp get_input
; set the audio limit method to active channels
@@:
    cp vdu_audio_limit_active_channels
    call z,vdu_set_audio_limit_active_channels
    jp get_input
; end ps_set_audio_limit_method


; set an audio limit parameter
; inputs: a = ascii value of a valid audio limit control keypress
; outputs: sets any of the vdu_audio_limit_* variables depending on the key pressed
;          and the current value of vdu_audio_limit_method
; destroys: always b, possibly af, hl, c depending on branch taken
ps_set_audio_limit_settings:
    ld b,a ; save the key pressed
    ld a,(vdu_audio_limit_method) ; get the current audio limit method
; branch on the method
    cp vdu_audio_limit_log_compress
    jr z,@log_compress
    cp vdu_audio_limit_constant_divisor
    jp nz,get_input ; no settings for any other method

; set the constant divisor
    ld a,b ; restore the key pressed
    cp 'd' ; increase constant divisor
    jr nz,@F
    ld a,(vdu_audio_limit_constant_divisor_A) ; get the current constant divisor
    cp 0xFF ; max value
    jp z,get_input ; already at max value
    inc a ; increase constant divisor
    jr @set_divisor
@@:
    cp 'c' ; decrease constant divisor
    jp nz,get_input ; no other settings for this method
    ld a,(vdu_audio_limit_constant_divisor_A) ; get the current constant divisor
    or a ; zero check
    jp z,get_input ; already at min value
    dec a ; decrease constant divisor
    ; fall through to @set_divisor
@set_divisor:
    ld (vdu_audio_limit_constant_divisor_A),a
    call vdu_set_audio_limit_constant_divisor
    jp get_input

@log_compress:
    ld a,b ; restore the key pressed
    cp 'd' ; increase normalization factor
    jr nz,@F
    ld a,(vdu_audio_limit_log_compress_A) ; get the current normalization factor
    cp 0xFF ; max value
    jp z,get_input ; already at max value
    inc a ; increase normalization factor
    jr @set_log_compress_A
@@:
    cp 'c' ; decrease normalization factor
    jr nz,@F
    ld a,(vdu_audio_limit_log_compress_A) ; get the current normalization factor
    or a ; zero check
    jp z,get_input ; already at min value
    dec a ; decrease normalization factor
    jr @set_log_compress_A
@@:
    cp 'f' ; increase makeup gain
    jr nz,@F
    ld a,(vdu_audio_limit_log_compress_B) ; get the current makeup gain
    cp 0xFF ; max value
    jp z,get_input ; already at max value
    inc a ; increase makeup gain
    jr @set_log_compress_B
@@:
    cp 'v' ; decrease makeup gain
    jr nz,@F
    ld a,(vdu_audio_limit_log_compress_B) ; get the current makeup gain
    or a ; zero check
    jp z,get_input ; already at min value
    dec a ; decrease makeup gain
    jr @set_log_compress_B
@@:
    cp 'b' ; increase compression curve shaping factor (decreases compression -- less loudness)
    jr nz,@F
    ld a,(vdu_audio_limit_log_compress_C) ; get the current compression curve shaping factor
    cp 0xFF ; max value
    jp z,get_input ; already at max value
    inc a ; increase compression curve shaping factor
    jr @set_log_compress_C
@@:
    cp 'g' ; decrease compression curve shaping factor (increases compression -- more loudness)
    jp nz,get_input ; no other settings for this method
    ld a,(vdu_audio_limit_log_compress_C) ; get the current compression curve shaping factor
    or a ; zero check
    jp z,get_input ; already at min value
    dec a ; decrease compression curve shaping factor
    ; fall through to @set_log_compress_C

@set_log_compress_C:
    ld (vdu_audio_limit_log_compress_C),a
    call vdu_set_audio_limit_log_compress
    jp get_input

@set_log_compress_A:
    ld (vdu_audio_limit_log_compress_A),a
    call vdu_set_audio_limit_log_compress
    jp get_input

@set_log_compress_B:
    ld (vdu_audio_limit_log_compress_B),a
    call vdu_set_audio_limit_log_compress
    jp get_input

; end ps_set_audio_limit_settings
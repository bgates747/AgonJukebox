get_input:
@loop:
; wait for the user to push a button
    MOSCALL mos_getkey ; a = ascii code of key pressed
    di ; disable interrupts
    ; rst.lil 10h ; print the key pressed
; app control commands
    cp '\e' ; escape
    ret z ; returns to main, which re-enables interrupts and exits app
; prt time tweaking
    cp '[' ; decrease PRT timer reload value
    jp nz,@F
    ld hl,(ps_prt_reload)
    ld de,-72 ; 1 ms
    add hl,de
    ld (ps_prt_reload),hl
    call vp_prt_reload
    call vp_breadcrumbs
    call ps_prt_start
    ei 
    jp @loop
@@: 
    cp ']' ; increase PRT timer reload value
    jp nz,@F
    ld hl,(ps_prt_reload)
    ld de,72 ; 1 ms
    add hl,de
    ld (ps_prt_reload),hl
    call vp_prt_reload
    call vp_breadcrumbs
    call ps_prt_start
    ei 
    jp @loop
; DIRECTORY PAGING
@@:
    cp 0x15 ; right arrow
    jp z,ps_dir_next_page
    cp 0x08 ; left arrow
    jp z,ps_dir_prev_page
; SONG PLAYING COMMANDS
; toggle pause playback
    cp 'p'
    jp nz,@F
    ld a,ps_mode_playing
    ld hl,ps_mode
    xor a,(hl)
    ld (hl),a
    jp @loop
; toggle loop play
    cp 'l'
    jp nz,@F
    ld a,ps_mode_loop
    ld hl,ps_mode
    xor a,(hl)
    ld (hl),a
    jp @loop
; toggle shuffle play
    cp 's'
    jp nz,@F
    ld a,ps_mode_shuffle
    ld hl,ps_mode
    xor a,(hl)
    ld (hl),a
    jp @loop
; play random song
    cp 'r'
    jp nz,@F
    ld a,ps_mode_shuffle
    ld hl,ps_mode
    or a,(hl)
    ld (hl),a
    jp ps_play_random
; 0-9 play song keys
@@: 
    cp '0'
    jp c,@no_cmd ; not a song command
    cp '9'+1
    jp nc,@no_cmd ; not a song command
    push af ; preserve keypress
    call ps_close_file
    pop af ; restore keypress
; get pointer to song filename and play it
    sub '0' ; a = index into filename lut
    call ps_get_song_fn_from_pg_idx ; carry set indicates success
    jp c,play_song ; re-enables interrupts and jp's to get_input when finished
@no_cmd: ; no valid commands so loop
    ei ; reenable interrupts
    jp @loop
; end get_input
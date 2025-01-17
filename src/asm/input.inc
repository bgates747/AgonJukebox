get_input:
; wait for the user to push a button
    ei ; enable interrupts
    MOSCALL mos_getkey ; a = ascii code of key pressed
    di ; disable interrupts

; DEBUG
; clear sysvar_keyascii
    ld l,a ; store for a sec
	MOSCALL mos_sysvars
	xor a
	ld (IX+sysvar_keyascii),a
    ld a,l ; restore a
; DEBUG

; app control commands
    cp '\e' ; escape
    ret z ; returns to main, which re-enables interrupts and exits app
; DIRECTORY PAGING
    cp 0x15 ; right arrow
    jp z,ps_dir_next_page
    cp 0x08 ; left arrow
    jp z,ps_dir_prev_page
; SONG PLAYING COMMANDS
; toggle pause playback
    cp 'p'
    jp z,ps_toggle_pause
; toggle loop play
    cp 'l'
    jp z,ps_toggle_loop
; toggle shuffle play
    cp 's'
    jp z,ps_toggle_shuffle
; play random song
    cp 'r'
    jp z,ps_play_random
; go up one directory
    cp 'u'
    jp z,ps_up_dir
; 0-9 play song keys
@@: 
    cp '0'
    jp c,@no_cmd ; not a song command
    cp '9'+1
    jp nc,@no_cmd ; not a song command
; get pointer to song filename and play it
    sub '0' ; a = index into filename lut
    call ps_get_song_fn_from_pg_idx ; carry set indicates success
    jp c,ps_play_or_chg_dir ; re-enables interrupts and jp's to get_input when finished
@no_cmd: ; no valid commands so loop
    jp get_input
; end get_input

; play or song or change directory when user issues a play song command
; inputs: hl pointer to the filename, a = file attribute
ps_play_or_chg_dir:
    cp AM_DIR ; file attribute check for directory
    jp nz,play_song ; not a directory so play the song
; otherwise change to the directory
    MOSCALL mos_cd ; change to the directory
    call ps_get_dir ; get directory listing
    call ps_stop ; TEMPORARY until we have separate buffers for playback and browsing
    jp get_input ; back to main loop
; end ps_play_or_chg_dir

; change directory one level up
; inputs: none
ps_up_dir:
    call ps_stop ; TEMPORARY until we have separate buffers for playback and browsing
    ld hl,@str_up_dir
    MOSCALL mos_cd ; change to the directory
    call ps_get_dir ; get directory listing
    jp get_input ; back to main loop
@str_up_dir: asciz ".."
; end ps_up_dir

; TEMPORARY until we have separate buffers for playback and browsing
ps_stop:
    ld hl,ps_mode
    res ps_mode_playing,(hl)
    call vp_now_playing
    call vdu_cls
    call printInline
    asciz "Stopped due to directory change. Select a new song to resume."
    ret
; end ps_stop

ps_toggle_pause:
    call vp_now_playing
    call vdu_cls

    ld hl,ps_mode
    bit ps_mode_playing,(hl)
    jp nz,@playing

    set ps_mode_playing,(hl)
    call printInline
    asciz "(P)laying "
    jp @F

@playing:
    res ps_mode_playing,(hl)
    call printInline
    asciz "(P)aused  "

@@:
    ld hl,(ps_song_fn_cur)
    call printString ; print the song filename

    jp get_input
; end ps_toggle_pause

ps_toggle_shuffle:

    jp get_input
; end ps_toggle_shuffle

ps_toggle_loop:

    jp get_input
; end ps_toggle_loop
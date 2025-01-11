get_input:
@loop:
; wait for the user to push a button
    MOSCALL mos_getkey ; a = ascii code of key pressed
    di ; disable interrupts
    ; rst.lil 10h ; print the key pressed
; app control commands
    cp '\e' ; escape
    ret z ; returns to main, which re-enables interrupts and exits app
; song playing commands
    cp 'r' ; random song
    jp z,ps_play_random
    cp '0'
    jp c,@other ; not a song command
    cp '9'+1
    jp nc,@other ; not a song command
; new song requested so stop playing current one
    push af ; preserve keypress
    call ps_close_file
    pop af ; restore keypress
; get pointer to song filename and play it
    sub '0' ; a = index into filename lut
    call ps_get_song_fn_from_pg_idx ; carry set indicates success
    jp c,play_song ; re-enables interrupts and jp's to get_input when finished
@other: ; TODO: other commands
    ei ; reenable interrupts
    jp @loop ; no valid commmand so loop
; end get_input
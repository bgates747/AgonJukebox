get_input:
@loop:
; wait for the user to push a button
    MOSCALL mos_getkey ; a = ascii code of key pressed
    di ; disable interrupts
; DEBUG
    call printNewLine
    rst.lil 10h ; print the key pressed
; END DEBUG
; app control commands
    cp '\e' ; escape
    ret z ; return from main, which exits app
; song playing commands
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
    ld d,a
    ld e,3 ; three bytes per filename index
    mlt de ; index into the filename table
    ld hl,SFX_filename_index
    add hl,de ; hl points to the filename index
    ld hl,(hl) ; hl is pointer to song filename
    ld (current_song),hl ; save song request
    jp play_song ; re-enables interrupts and jp's to get_input when finished
@other: ; TODO: other commands
    ei ; reenable interrupts
    jp @loop ; no valid commmand so loop
; end get_input
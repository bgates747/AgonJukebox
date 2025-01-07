get_input:
@loop:
; check play timer expired
    ld iy,tmr_play
    call tmr_get
    jp z,get_input_return ; yes, so return
    jp m,get_input_return ; way expired, so return

; check input timer expired
    ld iy,tmr_input
    call tmr_get
    jp p,@loop ; no, so loop until time to read keyboard

; check for keyboard input
    MOSCALL mos_getkbmap ; IX points to keyboard map
; 113 Escape - quit program
    bit 0,(ix+14)
    jp z,@F
    ret ; from *main*, which ends program
@@:
; user didn't quit so check whether they requested a new song
    ld hl,0 ; clear hl
; 49 Num1
    bit 0,(ix+6)
    jp z,@F
    ld hl,SFX_filename_index+[3*0]
@@:
; 50 Num2
    bit 1,(ix+6)
    jp z,@F
    ld hl,SFX_filename_index+[3*1]
@@:
; 18 Num3
    bit 1,(ix+2)
    jp z,@F
    ld hl,SFX_filename_index+[3*2]
@@:
; 19 Num4
    bit 2,(ix+2)
    jp z,@F
    ld hl,SFX_filename_index+[3*3]
@@:
; 20 Num5
    bit 3,(ix+2)
    jp z,@F
    ld hl,SFX_filename_index+[3*4]
@@:
; 53 Num6
    bit 4,(ix+6)
    jp z,@F
    ld hl,SFX_filename_index+[3*5]
@@:
; 37 Num7
    bit 4,(ix+4)
    jp z,@F
    ld hl,SFX_filename_index+[3*6]
@@:
; 22 Num8
    bit 5,(ix+2)
    jp z,@F
    ld hl,SFX_filename_index+[3*7]
@@:
; 39 Num9
    bit 6,(ix+4)
    jp z,@F
    ld hl,SFX_filename_index+[3*8]
@@:
; 40 Num0
    bit 7,(ix+4)
    jp z,@F
    ld hl,SFX_filename_index+[3*9]
@@:
; if hl is non-zero we have a song request
    SIGN_HLU
    jp z,@loop ; no request so loop

; get pointer to song filename and save it
    ld hl,(hl) ; hl is pointer to song filename
    ld (current_song),hl ; save song request

; reset input timer
    ld iy,tmr_input
    ld hl,120 ; 1 second
    call tmr_set

; now finally play the dratted thing
    ld hl,(current_song)
    jp play_song
; end get_input

tmr_play: ds 6 ; play timer buffer
tmr_input: ds 6 ; input timer buffer
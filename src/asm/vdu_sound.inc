; ############################################################
; VDU SOUND API
; ############################################################
; Command 0: Play note
; VDU 23, 0, &85, channel, 0, volume, frequency; duration;
    MACRO PLAY_NOTE channel, volume, frequency, duration
    ld hl, @PLAY_NOTE_CMD        ; Start of command block
    ld bc, @PLAY_NOTE_END - @PLAY_NOTE_CMD  ; Command block size
    rst.lil $18
    jr @PLAY_NOTE_END  
@PLAY_NOTE_CMD:  db 23, 0, 0x85               ; Command header
                 db channel                  ; Channel, 0 (commented out)
                 db 0                        ; Play note command
                 db volume                   ; Volume
                 dw frequency                ; Frequency
                 dw duration                 ; Duration
@PLAY_NOTE_END: 
    ENDMACRO

    MACRO MUTE_CHANNEL channel
    ld hl, @MUTE_CHANNEL_CMD     ; Start of command block
    ld bc, @MUTE_CHANNEL_END - @MUTE_CHANNEL_CMD  ; Command block size
    rst.lil $18
    jr @MUTE_CHANNEL_END
@MUTE_CHANNEL_CMD: db 23, 0, 0x85             ; Command header
                   db channel                ; Channel, 0 (commented out)
                   db 2                      ; Set volume command
                   db 0                      ; Volume (mute)
@MUTE_CHANNEL_END: 
    ENDMACRO

; VDU 23, 0, &85, channel, 2, volume
; inputs: c = channel, b = volume
; Sets the volume of the specified channel. The volume is a value from 0 to 127, where 0 is silent and 127 is full volume. Values over 127 will be treated as 127 (with one exception described later).

; Specifying a channel of -1 (or 255) will set the global sound system volume level. (Requires Console8 VDP 2.5.0 or later.)

; Using this command provides more direct control over a channel than the play note command. It can be used to adjust the volume of a channel that is already playing a note.
vdu_channel_volume:
    ld a,c
    ld (@channel),a
    ld a,b
    ld (@volume),a
    ld hl,@cmd         
    ld bc,@end-@cmd    
    rst.lil $18         
    ret
@cmd:       db 23, 0, 0x85
@channel:   db 0x00
            db 0x02 ; set volume command
@volume:    db 0x00
@end:

; Command 10: Reset channel
; VDU 23, 0, &85, channel, 10
; inputs: c = channel
vdu_reset_channel:
    ld a,c
    ld (@channel),a
    ld hl,@cmd
    ld bc,@end-@cmd
    rst.lil $18
    ret
@cmd:       db 23, 0, 0x85
@channel:   db 0x00
            db 10 ; reset channel command
@end:

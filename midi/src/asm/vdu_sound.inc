; enable sound channels
; inputs: a = total num channels to be enabled
; returns: nothing
; destroys: af, bc, hl
vdu_enable_channels:
    dec a ; channels are zero-based
@loop:
    ld (@channel),a
    ld hl,@beg
    ld bc,@end-@beg
    push af
    rst.lil $18
    pop af
    dec a
    jp nz,@loop
    ret
@beg:
            db 23, 0, $85
@channel:   db 0
            db 8 ; command 8: enable channel
@end:

; disable all but the three default sound channels
; inputs: max_channels set
; outputs: none
; destroys: ah,hl,bc
vdu_disable_channels:
    ld a,max_channels
    sub 3 ; subtract number of default channels already enabled
    jp p,@loop
    ret
    ld a,3 ; first non-default channel
@loop:
    ld (@channel),a
    ld hl,@beg
    ld bc,@end-@beg
    push af
    rst.lil $18
    pop af
    inc a
    cp max_channels
    jp nz,@loop
    ret
@beg:
    db 23, 0, $85
@channel: db 0
    db 9 ; command 9: disable channel
@end:


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

; inputs: c = channel, b = volume, hl = frequency; de = duration;
vdu_play_note:
    ld a,c
    ld (@channel),a
    ld a,b
    ld (@volume),a
    ld (@frequency),hl
    ld (@duration),de
    ld hl,@cmd         
    ld bc,@end-@cmd    
    rst.lil $18         
    ret
@cmd:       db 23, 0, 0x85
@channel:   db 0x00
            db 0x00 ; play note command
@volume:    db 0x00
@frequency: dw 0x0000
@duration:  dw 0x0000
@end:       db 0x00 ; padding

; Command 1: Status
; VDU 23, 0, &85, channel, 1
; inputs: a = channel
; Returns a bit mask indicating the status of the specified channel, or 255 if the channel is not valid, or has been disabled. The bit mask is as follows:
; Bit 	Name 	Meaning
; 0 	Active 	When set this indicates the channel is in use (has an active waveform)
; 1 	Playing 	Indicates the channel is actively playing a note, and thus will reject calls to play a new note
; 2 	Indefinite 	Set if the channel is playing an indefinite duration note
; 3 	Has Volume Envelope 	Set if the channel has a volume envelope
; 4 	Has Frequency Envelope 	Set if the channel has a frequency envelope

; Bits 5-7 are reserved for future use and, for enabled channels, will currently always be zero.
vdu_channel_status:
    ld (@channel),a
    ld hl,@cmd         
    ld bc,@end-@cmd    
    rst.lil $18         
    ret
@cmd:       db 23, 0, 0x85
@channel:   db 0x00
            db 0x01 ; get channel status command
@end:

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

; VDU 23, 0, &85, channel, 3, frequency;

; Sets the frequency of the specified channel. The frequency is a 16-bit value specifying in Hz the frequency of the note to be played.

; Using this command provides more direct control over a channel than the play note command. It can be used to adjust the frequency of a channel that is already playing a note.

; Returns 1 on success, 0 for failure.
vdu_channel_frequency:
    ld a,c
    ld (@channel),a
    ld (@frequency),de
    ld hl,@cmd         
    ld bc,@end-@cmd    
    rst.lil $18         
    ret
@cmd:       db 23, 0, 0x85
@channel:   db 0x00
            db 0x03 ; set frequency command
@frequency: dw 0x0000
@end:       db 0x00 ; padding


; VDU 23, 0, &85, channel, 4, waveformOrSample, [bufferId;]
; inputs: c = channel, b = waveformOrSample, [hl = bufferId]
; Sets the waveform type for a channel to use. The waveformOrSample value is a single byte treated as a signed value.

; Using a negative value for the waveform indicates that a sample should be used instead. For more information see the documentation for the sample command.

; By default a channel is set to use waveform 0 (square wave).

; Valid waveform values are as follows:
; Value 	Waveform
; 0 	Square wave
; 1 	Triangle wave
; 2 	Sawtooth wave
; 3 	Sine wave
; 4 	Noise (simple white noise with no frequency support)
; 5 	VIC Noise (emulates a VIC6561; supports frequency)
; 8 	Sample (specifying a 16-bit buffer ID for sample data)

vdu_channel_waveform:
    ld a,c
    ld (@channel),a
    ld a,b
    ld (@waveform),a
    cp 8 ; check if the waveform is a sample
    jr z, @sample       
    ld bc,@bufferId-@cmd   
    jr @sendToVdu
@sample:
    ld (@bufferId),hl
    ld bc,@end-@cmd
@sendToVdu: 
    ld hl,@cmd  
    rst.lil $18         
    ret
@cmd:       db 23, 0, 0x85
@channel:   db 0x00
            db 0x04 ; set waveform command
@waveform:  db 0x00
@bufferId:  dw 0x0000
@end:       db 0x00 ; padding

; VDU 23, 0, &85, channel (ignored), 5, 2, bufferId; format, [sampleRate;]
; inputs: hl = bufferId; a = format, de = sample rate in Hz
; The format is a single byte giving the format of the sample data. The following formats are supported:
; Value	Description
; 0	8-bit signed
; 1	8-bit unsigned
; The format value can also have modifier bits set to modify the behaviour of the sample. The following modifier bits are supported:
; Value	Description
; 8	sample rate is sent in the next 16-bits
; 16	sample is tuneable
; The default sample rate for samples on the VDP is 16kHz (actually 16.384kHz to be precise).
vdu_buffer_to_sound:
    ld (@bufferId),hl
    add a,8 ; modify format byte to indicate sample rate argument is given
    ld (@format),a
    ld (@sampleRate),de
    ld hl,@cmd         
    ld bc,@end-@cmd    
    rst.lil $18         
    ret
@cmd:       db 23, 0, 0x85
@channel:   db 0x00 ; ignored
            db 0x05 ; buffer to sound command
            db 0x02 ; command 2 create sample
@bufferId:  dw 0x0000
@format:    db 0x00
@sampleRate: dw 0x0000
@end:       db 0x00 ; padding

; Command 13: Set sample rate
; VDU 23, 0, &85, channel, 13, sampleRate;
; inputs: c = channel, hl = sampleRate (Hz)
vdu_set_sample_rate:
    ld a,c
    ld (@channel),a
    ld (@sampleRate),hl
    ld hl,@cmd         
    ld bc,@end-@cmd    
    rst.lil $18         
    ret
@cmd:       db 23, 0, 0x85
@channel:   db 0x00
            db 13 ; set sample rate command
@sampleRate: dw 0x0000
@end:       db 0x00 ; padding

; load a sound file to a buffer
; inputs: hl = bufferId ; de = sampleRate in Hz ; iy = pointer to filename
vdu_load_sfx:
; back up input parameters
    push hl ; bufferId
    push de ; sample rate
; load the sound
    call vdu_load_buffer_from_file
; now make the buffer a sound sample
    pop de ; sample rate
    pop hl ; bufferId
    xor a ; zero is the magic number for mono 8-bit signed PCM
    call vdu_buffer_to_sound 
    ret


last_channel: db 0
max_channels: equ 1

; play a sound effect from an already loaded buffer
; inputs: hl = bufferId ; bc = duration in milliseconds
vdu_play_sfx:
    ld (@bufferId),hl
    ld (@duration),bc
    ld a,23
    ld (@bufferId+2),a
    ld a,(last_channel)
    inc a
    ; and 31 ; modulo 32
    cp max_channels
    jp nz,@load_channel
    xor a
@load_channel:
    ld (last_channel),a
    ld (@channel0),a
    ld (@channel1),a
    ld hl, @sample
    ld bc, @sample_end - @sample
    rst.lil $18
    ret 
@sample: 
; Command 4: Set waveform
; VDU 23, 0, &85, channel, 4, waveformOrSample, [bufferId;]
    .db 23,0,$85                        ; do sound
@channel0:   
    .db 0,4,8 ; channel, command, waveform
@bufferId:    
    .dw 0x0000
; Command 0: Play note
; VDU 23, 0, &85, channel, 0, volume, frequency; duration;
    .db 23,0,$85                        ; do sound
@channel1:    
    .db 0,0,127                ; channel, volume
    .dw 0 
@duration:                              ; freq (tuneable samples only)
    .dw 0x0000                        ; duration
@sample_end:
    .db 0x00 ; padding

; inputs: c = channel, b = volume, de = sample rate; hl = bufferId;
vdu_play_sample:
    ; populate input parameters
    ld a,c
    ld (@channel0),a
    ld (@channel1),a
    ld (@channel2),a
    ld a,b
    ld (@volume),a
    ld (@sampleRate),de
    ld (@bufferId),hl
    ld a,23 
    ld (@cmd1),a 
    ld (@cmd2),a
    ; prep the vdu command string
    ld hl, @cmd0
    ld bc, @end - @cmd0
    rst.lil $18
    ret 
; set waveform command
@cmd0:       db 23, 0, 0x85
@channel0:   db 0x00
             db 0x04 ; set waveform command
@waveform:   db 0x08 ; sample
@bufferId:   dw 0x0000
; set sample rate command
@cmd1:       db 23, 0, 0x85
@channel1:   db 0x00
            db 13 ; set sample rate command
@sampleRate: dw 0x0000
; play note command
@cmd2:       db 23, 0, 0x85
@channel2:   db 0x00
             db 0x00 ; play note command
@volume:     db 0x00
@frequency:  dw 0x00 ; no effect unless buffer has been set to tuneable sample
@duration:   dw 0x0000 ; milliseconds: set to -1 to loop indefinitely, 0 to play full duration once
@end:        db 0x00 ; padding
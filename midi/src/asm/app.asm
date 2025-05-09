    include "mos_api.inc"
    include "macros.inc"

; Command 4: Set waveform
; VDU 23, 0, &85, channel, 4, 8, bufferId;
    MACRO WAVEFORM_SAMPLE channel, buffer_id
    ld hl, @startChannel
    ld bc, @endChannel - @startChannel
    rst.lil $18
    jr @endChannel 
@startChannel: 
    .db 23,0,$85    ; do sound
    .db channel,4,8 ; channel, command, waveform
    .dw buffer_id
@endChannel:
    ENDMACRO

;MOS INITIALIATION 
    .assume adl=1   
    .org 0x040000    

    jp start       

    .align 64      
    .db "MOS"       
    .db 00h         
    .db 01h  

str_version: db "0.0.1.alpha",0

start:              
    push af
    push bc
    push de
    push ix
    push iy

; ###############################################
	call	init			; Initialization code
	call 	main			; Call the main function
; ###############################################

    call cursor_on

exit:
    pop iy                              ; Pop all registers back from the stack
    pop ix
    pop de
    pop bc
    pop af
    ld hl,0                             ; Load the MOS API return code (0) for no errors.

    ret                                 ; Return MOS

; ###############################################
; Initialization
; ###############################################
init:
; enable all the channels
    ld hl, enable_channels_cmd
    ld bc, enable_channels_end - enable_channels_cmd
    rst.lil $18
    jp enable_channels_end
enable_channels_cmd:
    db 23, 0, $85, 3, 8
    db 23, 0, $85, 4, 8
    db 23, 0, $85, 5, 8
    db 23, 0, $85, 6, 8
    db 23, 0, $85, 7, 8
    db 23, 0, $85, 8, 8
    db 23, 0, $85, 9, 8
    db 23, 0, $85, 10, 8
    db 23, 0, $85, 11, 8
    db 23, 0, $85, 12, 8
    db 23, 0, $85, 13, 8
    db 23, 0, $85, 14, 8
    db 23, 0, $85, 15, 8
    db 23, 0, $85, 16, 8
    db 23, 0, $85, 17, 8
    db 23, 0, $85, 18, 8
    db 23, 0, $85, 19, 8
    db 23, 0, $85, 20, 8
    db 23, 0, $85, 21, 8
    db 23, 0, $85, 22, 8
    db 23, 0, $85, 23, 8
    db 23, 0, $85, 24, 8
    db 23, 0, $85, 25, 8
    db 23, 0, $85, 26, 8
    db 23, 0, $85, 27, 8
    db 23, 0, $85, 28, 8
    db 23, 0, $85, 29, 8
    db 23, 0, $85, 30, 8
    db 23, 0, $85, 31, 8
enable_channels_end:

waveform_square: equ 0 ; square wave
waveform_triangle: equ 1 ; triangle wave
waveform_sawtooth: equ 2 ; sawtooth wave
waveform_sine: equ 3 ; sine wave
waveform_noise: equ 4 ; noise wave
waveform_vic_noise: equ 5 ; VIC noise wave
waveform_sample: equ 8 ; PCM sound sample 

waveform: equ waveform_square

; set waveform for all channels
    ld hl, waveform_channels_cmd
    ld bc, waveform_channels_end - waveform_channels_cmd
    rst.lil $18
    jp waveform_channels_end
waveform_channels_cmd:
    db 23, 0, $85, 0, 4, waveform
    db 23, 0, $85, 1, 4, waveform
    db 23, 0, $85, 2, 4, waveform
    db 23, 0, $85, 3, 4, waveform
    db 23, 0, $85, 4, 4, waveform
    db 23, 0, $85, 5, 4, waveform
    db 23, 0, $85, 6, 4, waveform
    db 23, 0, $85, 7, 4, waveform
    db 23, 0, $85, 8, 4, waveform
    db 23, 0, $85, 9, 4, waveform
    db 23, 0, $85, 10, 4, waveform
    db 23, 0, $85, 11, 4, waveform
    db 23, 0, $85, 12, 4, waveform
    db 23, 0, $85, 13, 4, waveform
    db 23, 0, $85, 14, 4, waveform
    db 23, 0, $85, 15, 4, waveform
    db 23, 0, $85, 16, 4, waveform
    db 23, 0, $85, 17, 4, waveform
    db 23, 0, $85, 18, 4, waveform
    db 23, 0, $85, 19, 4, waveform
    db 23, 0, $85, 20, 4, waveform
    db 23, 0, $85, 21, 4, waveform
    db 23, 0, $85, 22, 4, waveform
    db 23, 0, $85, 23, 4, waveform
    db 23, 0, $85, 24, 4, waveform
    db 23, 0, $85, 25, 4, waveform
    db 23, 0, $85, 26, 4, waveform
    db 23, 0, $85, 27, 4, waveform
    db 23, 0, $85, 28, 4, waveform
    db 23, 0, $85, 29, 4, waveform
    db 23, 0, $85, 30, 4, waveform
    db 23, 0, $85, 31, 4, waveform
waveform_channels_end:

    ld a,3
    call vdu_set_screen_mode

    call cursor_off
    call vdu_cls

    call vdu_home_cursor
    ld hl,str_version
    call printString
    call printNewline

    ret

current_channel: db 0
note_counter: dl 0

; Format of each note record:
    tnext_lo:    equ 0     ; 1 byte. Time to next note in milliseconds (low byte)
    tnext_hi:    equ 1     ; 1 byte. Time to next note in milliseconds (high byte)
    duration_lo: equ 2     ; 1 byte. Length of time to sound note in milliseconds (low byte)
    duration_hi: equ 3     ; 1 byte. Length of time to sound note in milliseconds (high byte)
    freq_lo:     equ 4     ; 1 byte. Frequency in Hz (low byte)
    freq_hi:     equ 5     ; 1 byte. Frequency in Hz (high byte)
    velocity:    equ 6     ; 1 byte. Loudness of the note to sound (0-127)
    instrument:  equ 7     ; 1 byte. Instrument used to sound note (1-255)

bytes_per_note: equ 8
play_note:
; ; stop the timer
;     call prt_stop

; reset the note counter
    ld l,(iy+tnext_lo) ; low byte
    ld h,(iy+tnext_hi) ; high byte
    ld (note_counter),hl ; set the note counter

; play the note
    ld a,(current_channel)
    inc a
    and 31 ; mod 32
    ld (current_channel),a
    ld c,a ; channel

    ld e,(iy+duration_lo) ; duration low byte
    ld d,(iy+duration_hi) ; duration high byte

    ld l,(iy+freq_lo) ; frequency low byte
    ld h,(iy+freq_hi) ; frequency high byte

    ld b,(iy+velocity) ; volume

    call vdu_play_note
    lea iy,iy+bytes_per_note ; move to next note

; ; restart the timer
;     call prt_start

    ret

    include "functions.inc"
    include "timer.inc"
    include "maths.inc"
    include "vdu.inc"
    include "vdu_sound.inc"

; ###############################################
; Main loop
; ###############################################

main:
    ld iy,MidiData
    call prt_irq_init
    call prt_start
    call get_input

; cleanup and exit
    call prt_stop
    ei 
    ld a,0
    call vdu_set_screen_mode
    ret

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
    
    jr get_input ; if not escape or q, continue


MidiData:
    include "../../out/dx555xv9093-exp-tempo95.inc"
    include "../../out/xm993qd2681-exp-tempo95.inc"
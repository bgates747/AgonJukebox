    include "mos_api.inc"
    include "macros.inc"

    assume adl=1   
    org 0x040000    
    jp start       
    align 64      
    db "MOS"       
    db 00h         
    db 01h  
start:              
    push af
    push bc
    push de
    push ix
    push iy
	call	init
	call 	main
exit:
    pop iy
    pop ix
    pop de
    pop bc
    pop af
    ld hl,0
    ret

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
    ret
; end init

    include "debug.inc"
    include "functions.inc"
    include "timer.inc"

    include "arith24.inc"
    include "maths.inc"
    include "vdu.inc"
    include "vdu_buffered_api.inc"
    include "vdu_plot.inc"
    include "vdu_sound.inc"

    include "apr.inc"

; ###############################################
; Main loop
; ###############################################
main:
    ld hl, sound_cmd_start
    ld bc, sound_cmd_end - sound_cmd_start
    rst.lil $18

    ret
; end main

sound_cmd_start:

pure_square_cmd:
; —————————————————————————————————————————————————————————————————
; Command 4: Set waveform
; VDU 23,0,&85, channel, 4, waveform
; —————————————————————————————————————————————————————————————————
    db 23,0,0x85      ; VDU sound command header
    db 0              ; channel 0
    db 4              ; cmd 4 = set waveform
    db 0              ; waveform 0 = square wave

; ; —————————————————————————————————————————————————————————————————
; ; Command 14: Set duty cycle
; ; VDU 23,0,&85, channel, 14, parameter, value
; ; —————————————————————————————————————————————————————————————————
;     db 23,0,0x85      ; VDU sound command header (23, 0, &85)
;     db 0              ; channel 0
;     db 14             ; cmd 14 = set waveform parameter
;     db 0              ; param byte: 0 = duty cycle
;     db 64             ; 8-bit duty value (128/256 = 50%)

pure_square_cmd_end:


; -------------------------------------------------------------
; freq_env_cmd:
;   Command 7: Stepped Frequency Envelope on channel 0
;
;  VDU 23,0,&85, channel, 7, 
;        type, phaseCount, controlByte, 
;        stepLength; 
;        [phase1Adj; phase1Steps; phase2Adj; phase2Steps; …]
; 
;  – type          = 1  (stepped freq envelope)
;  – phaseCount    = 2  (two sub-phases)
;  – controlByte   = 1  (bit0=1 → repeat on each note)
;  – stepLength    = 30 ms
;  – phase1Adj     = +40 Hz
;  – phase1Steps   = 6
;  – phase2Adj     = –30 Hz
;  – phase2Steps   = 4
; -------------------------------------------------------------
freq_env_cmd:
    db 23,0,0x85      ; VDU sound header (23,0,&85)
    db 0              ; channel = 0
    db 7              ; cmd 7 = frequency envelope

    db 1              ; type = 1 (stepped envelope)
    db 2              ; phaseCount
    db 1              ; controlByte = 0b00000001 (repeat)
    dw 1000 / 60      ; stepLength ms

    dw 40             ; phase1 adjustment Hz
    dw 4              ; phase1 steps

    dw -40            ; phase2 adjustment Hz
    dw 4              ; phase2 steps

freq_env_cmd_end:

play_note_cmd:
; —————————————————————————————————————————————————————————————————
; Command 0: Play note
; VDU 23,0,&85, channel, 0, volume, frequency; duration;
; —————————————————————————————————————————————————————————————————
    db 23,0,0x85      ; VDU sound command header
    db 0              ; channel 0
    db 0              ; cmd 0 = play note
    db 15             ; volume
    dw 440            ; frequency Hz
    dw -1           ; duration ms
play_note_cmd_end:

sound_cmd_end:



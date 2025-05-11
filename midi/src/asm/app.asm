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

    call vdu_cursor_on

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
    ld a,3
    call vdu_set_screen_mode

    call vdu_cursor_off
    call vdu_cls

    ret

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
    include "samples.inc"
    include "../../out/dx555xv9093-exp-tempo95.inc"

; ###############################################
; Main loop
; ###############################################

main:
    call printInline
    asciz "Loading samples "
; load samples
    ld ix,sample_dictionary ; pointer to the sample dictionary
    ld b,num_samples ; loop counter
    xor a
    ld (last_channel),a
@sample_loop:
    push ix
    push bc
    ld de,(ix)
    ld h,0
    ld l,(ix+3) ; bufferId
    call pp_load_sample
    ld a,'.'
    rst.lil $10

; ; DEBUG
;     ld a,(last_channel)
;     inc a
;     and 31 ; mod 32
;     ld (last_channel),a
;     ld c,a ; channel
;     ld b,30 ; volume
;     ld de,1500 ; duration
;     ld h,0
;     ld l,(ix+3) ; bufferId
; ; populate input parameters
;     ld a,c
;     ld (@channel0),a
;     ld (@channel1),a
;     ld (@channel2),a
;     ld a,b
;     ld (@volume),a
;     ld (@bufferId),hl
;     ld (@duration),de
;     ld a,23 
;     ld (@cmd1),a 
;     ld (@cmd2),a
; ; prep the vdu command string
;     ld hl, @cmd0
;     ld bc, @end - @cmd0
;     rst.lil $18
;     jr @end+1 
; ; set waveform command
;     @cmd0:       db 23, 0, 0x85
;     @channel0:   db 0x00
;                  db 0x04 ; set waveform command
;     @waveform:   db 0x08 ; sample
;     @bufferId:   dw 0x0000
; ; set sample rate command
;     @cmd1:       db 23, 0, 0x85
;     @channel1:   db 0x00
;                  db 13 ; set sample rate command
;     @sampleRate: dw 16384
; ; play note command
;     @cmd2:       db 23, 0, 0x85
;     @channel2:   db 0x00
;                  db 0x00 ; play note command
;     @volume:     db 0x00
;     @frequency:  dw 0x00 ; no effect unless buffer has been set to tuneable sample
;     @duration:   dw 0x0000 ; milliseconds: set to -1 to loop indefinitely, 0 to play full duration once
;     @end:        db 0x00 ; padding
; ; END DEBUG

; advance the file pointer and loop
    pop bc
    pop ix
    lea ix,ix+4
    djnz @sample_loop

; play the midi file
    ld iy,midi_data
    call prt_irq_init
    call prt_start
    call get_input

; cleanup and exit
    call prt_stop
    ei 
    ; ld a,0
    ; call vdu_set_screen_mode
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
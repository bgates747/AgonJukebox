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

    ; include "../../out/Beethoven__Moonlight_Sonata_v1.inc"
    ; include "../../out/Beethoven__Moonlight_Sonata_v2.inc" 
    ; include "../../out/Beethoven__Moonlight_Sonata_3rd_mvt.inc"
    ; include "../../out/Beethoven__Ode_to_Joy.inc"
    ; include "../../out/Brahms__Sonata_F_minor.inc" 
    ; include "../../out/STARWARSTHEME.inc"
    include "../../out/Williams__Star_Wars_Theme.inc"
    ; include "../../out/Over_the_Rainbow.inc"
    ; include "../../out/Williams__Raiders_of_the_Lost_Ark.inc"

    ; include "../../out/Bach__Harpsichord_Concerto_1_in_D_minor.inc"
    ; include "../../out/Thoinot__Pavana.inc"

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
    ld de,(ix) ; pointer to the filename
    ld bc,(ix+3) ; sample frequency
    ld hl,(ix+6) ; bufferId
    call pp_load_sample
    ld a,'.'
    rst.lil $10
; advance the file pointer and loop
    pop bc
    pop ix
    lea ix,ix+9
    djnz @sample_loop
; play the midi file
    ld hl,0
    ld (notes_played),hl
    call vdu_cls
    ld iy,midi_data
    call prt_irq_init
    call prt_start
    call get_input
; cleanup and exit
    call prt_stop
    ei 
    call vdu_cls
    ret
; end main

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
; end get_input
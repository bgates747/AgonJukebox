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

    call init
    call main

exit:
    pop iy
    pop ix
    pop de
    pop bc
    pop af
    ld hl,0

    ret

; API INCLUDES
    include "mos_api.inc"
    include "macros.inc"
    include "functions.inc"
    include "arith24.inc"
    include "maths.inc"
    include "font.inc"
    include "fixed168.inc"
    include "time.inc"
    include "timer.inc"
    include "vdu.inc"
    include "vdu_buffered_api.inc"
    include "vdu_fonts.inc"
    include "vdu_plot.inc"
    include "vdu_sound.inc"

    include "fpp.inc"
    include "fpp_ext.inc"

; APPLICATION INCLUDES
    include "agm.inc"
    include "layout.inc"
    include "browse.inc"
    include "input.inc"
    include "logo.inc"
    include "play.inc"
    include "sort.inc"
    include "timer_jukebox.inc"
    include "wav.inc"
    
    include "debug.inc"

fname: asciz "Star_Wars__Battle_of_Yavin.wav"

; --- MAIN PROGRAM FILE ---
init:
    ld a,5
    call vdu_enable_channels
    ret
; end init
main:

    ld hl,ps_fil_struct
    ld de,fname
    ld iy,ps_wav_header
    call verify_wav
    call dumpFlags

    ld hl,ps_fil_struct
    ld de,ps_wav_data
    ld bc,(ps_wav_header+wav_sample_rate)
    FFSCALL ffs_fread ; read the file
    call dumpRegistersHex

    ld hl,ps_dat_base_buffer
    ld de,ps_wav_data
    ld bc,(ps_wav_header+wav_sample_rate)
    call vdu_load_buffer

    call pv_load_audio_cmd_buffers
    ld hl,ps_cmd_base_buffer
    call vdu_call_buffer

    ; ld hl,ps_dat_base_buffer
    ; ld a,1 ; 8 = sample rate next, 1 = 8-bit unsigned
    ; ld de,(ps_wav_header+wav_sample_rate)
    ; call vdu_buffer_to_sound

    ; ld hl,ps_dat_base_buffer
    ; ld c,0 ; channel
    ; ld b,8 ; waveform = sample
    ; call vdu_channel_waveform

    ; ld c,0
    ; ld b,127
    ; ld hl,0
    ; ld de,0
    ; call vdu_play_note

    ld hl,ps_fil_struct
    FFSCALL ffs_fclose ; close the file
    ret ; back to MOS
; end main

; must be final include in program so file data does not stomp on program code or other data
    include "files.inc"
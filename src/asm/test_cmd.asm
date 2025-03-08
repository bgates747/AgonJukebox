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
imgname: asciz "../images/frame_01200.rgba2.tvc"

; --- MAIN PROGRAM FILE ---
init:
    ld a,20
    call vdu_set_screen_mode
    xor a
    call vdu_set_scaling
    call vdu_cls

    ret
; end init
main:
    ; ld hl,pv_img_base_buffer
    ; ld iy,imgname
    ; call vdu_load_buffer_from_file

    ; ld hl,pv_img_base_buffer ; source bufferId
    ; ld de,pv_img_base_buffer ; target bufferId
    ; call vdu_decompress_buffer

    ; ld hl,pv_img_base_buffer ; source bufferId
    ; call vdu_buff_select

    ; ld a,1 ; format = rgba2222
    ; ld bc,320 ; width
    ; ld de,136 ; height
    ; ld hl,pv_img_base_buffer
    ; call vdu_bmp_create

    ; ld bc,63
    ; ld de,63
    ; call vdu_plot_bmp

    ld hl,512
    ld (screen_width),hl
    ld hl,384
    ld (screen_height),hl
    ld hl,320 ; width
    ld (ps_wav_header+agm_width),hl
    ld hl,136 ; height
    ld (ps_wav_header+agm_height),hl
    ld a,50 ; max loaded frames
    ld (pv_loaded_frames_max),a
    call pv_load_video_cmd_buffers
    ; call test_video_cmd

    ld hl,pv_img_base_buffer
    ld iy,imgname
    call vdu_load_buffer_from_file

    ld hl,pv_img_base_buffer ; source bufferId
    ld de,pv_img_base_buffer ; target bufferId
    call vdu_decompress_buffer

    ld hl,pv_cmd_base_buffer
    call vdu_call_buffer

    ret ; back to MOS
; end main

test_video_cmd:
    ld hl,pv_cmd_base_buffer
    ld a,(pv_loaded_frames_max)
    dec a ; zero-based
    ld l,a
@clear_cmd_loop:
    push hl ; save cmd buffer high byte and loop counter
    call vdu_clear_buffer
    pop hl
    dec l ; dec loop counter
    jp p,@clear_cmd_loop

    ld hl,pv_img_base_buffer
    ld a,(pv_loaded_frames_max)
    dec a ; zero-based
    ld l,a
@clear_img_loop:
    push hl ; save img buffer high byte and loop counter
    call vdu_clear_buffer
    pop hl
    dec l ; dec loop counter
    jp p,@clear_img_loop

    ld de,(ps_wav_header+agm_width)
    ld (@width),de
    dec de
    inc.s de ; clears ude
    ld hl,(screen_width)
    or a ; clear carry
    sbc hl,de
    call hlu_div2
    ld (@x),hl

    ld de,(ps_wav_header+agm_height)
    ld (@height),de
    ld a,1 ; format 1 = RGBA2222
    ld (@height+2),a
    dec de
    inc.s de ; clears ude
    ld hl,(screen_height)
    or a ; clear carry
    sbc hl,de
    call hlu_div2
    ld (@y),hl

    ld hl,pv_cmd_base_buffer
    ld a,(pv_loaded_frames_max)
    dec a ; zero-based
    ld l,a
@load_loop:
    push hl ; save command bufferId high byte and loop counter
    ld (@bufferId),a ; only need to load the low byte

    ld de,@cmd_start
    ld bc,@cmd_end-@cmd_start
    call vdu_load_buffer

    pop hl ; restore current command bufferId
    dec l ; dec loop counter
    jp p,@load_loop

    ret 
@cmd_start:
; VDU 23, 27, &20, bufferId; : Select bitmap (using a buffer ID)
; inputs: hl=bufferId
            db 23,27,0x20
@bufferId:  dw pv_img_base_buffer

; VDU 23, 27, &21, w; h; format: Create bitmap from selected buffer
            db 23,27,0x21
@width:     dw 0x0000
@height:    dw 0x0000
            db 1 ; format 1 = RGBA2222 (1-bytes per pixel)

; VDU 25, mode, x; y;: PLOT command
            db 25
            db plot_bmp+dr_abs_fg ; 0xED
@x:         dw 0x0000
@y:         dw 0x0000
@cmd_end:   db 0x00 ; padding
; end test_video_cmd

test_audio:
    ld a,ps_loaded_samples_max
    call vdu_enable_channels

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

    ret
; end test_audio

; must be final include in program so file data does not stomp on program code or other data
    include "files.inc"
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

fname: asciz "Star_Wars__Battle_of_Yavin_bayer.agm"

; --- MAIN PROGRAM FILE ---
init:
    ld a,20
    call vdu_set_screen_mode
    xor a
    call vdu_set_scaling
    call vdu_cls

    call vp_messages

    ret
; end init
main:

; set up pointers to the fileinfo struct and filename
    ld hl,ps_fil_struct ; hl = pointer to fil struct
    ld de,fname; de = pointer to filename
    ld c,fa_read ; c = read mode
    FFSCALL ffs_fopen ; open the file

    ld hl,ps_filinfo_struct ; hl = pointer to fil struct
    ld de,fname; de = pointer to filename
    FFSCALL ffs_stat ; get file info

    ld hl,ps_filinfo_fname ; hl = pointer to filename
    call printString
    call printNewLine

; read the header of the .agm file
    ld hl,ps_fil_struct ; hl = pointer to fil struct
    ld de,ps_wav_header ; de = pointer to header
    ld bc,agm_header_size ; bc = size of header
    FFSCALL ffs_fread ; read the header of the .agm file

; read the header of the .agm file
    call print_agm_header

; BEGIN NORMAL INITIALIZATION
; initalize counters and flags
    ld a,60
    ld (pv_sample_counter),a
    ld hl,(ps_wav_header+agm_frame_rate) ; l = frame rate
    ld h,a ; h = 60
    call udiv8 ; h = 60 / frame rate
    ld a,h
    ld (pv_draw_counter_reset),a
    ld (pv_draw_counter),a
    ld hl,ps_wav_header+agm_frame_rate
    ld d,(hl) ; d = frame rate
    ld e,5
    mlt de
    ld a,e
    ld (pv_loaded_frames_max),a
    xor a
    ld (ps_loaded_samples),a
    ld (pv_loaded_frames),a
; initialize command and data buffers
    call pv_load_audio_cmd_buffers
    call pv_load_video_cmd_buffers
    ld hl,ps_cmd_base_buffer
    ld (ps_cmd_buffer),hl
    ld hl,ps_dat_base_buffer
    ld (ps_dat_buffer),hl
    ld hl,pv_cmd_base_buffer
    ld (pv_cmd_buffer),hl
    ld hl,pv_img_base_buffer
    ld (pv_img_buffer),hl

; END NORMAL INITIALIZATION

@read_segment:
; read the next segment header
    ld hl,ps_fil_struct
    ld bc,agm_segment_hdr_size ; bytes to read
    ld de,agm_segment_hdr   ; target address
    FFSCALL ffs_fread
    call print_segment_header

@read_unit:
; read the unit header
    ld hl,ps_fil_struct
    ld bc,agm_unit_hdr_size ; bytes to read
    ld de,agm_unit_hdr   ; target address
    FFSCALL ffs_fread
    call print_unit_header

@read_chunk:
; read the chunk header
    ld hl,ps_fil_struct
    ld bc,agm_chunk_hdr_size ; bytes to read
    ld de,agm_chunk_hdr   ; target address
    FFSCALL ffs_fread
    call print_chunk_header
; check chunk size for zero, indicating end of unit
    ld hl,(agm_chunk_hdr+agm_chunk_size) ; bytes to load
    SIGN_HLU 
    jr z,@agm_next_unit ; jr z,agm_next_unit
; read the next chunk of data from the SD card to RAM
    push hl
    pop bc ; bc = bytes to read
    ld hl,ps_fil_struct
    ld de,ps_agm_data
    FFSCALL ffs_fread
; load the data buffer with the data read (bc already has bytes to load)
    ld hl,(pv_img_buffer) ; bufferId
    ld de,ps_agm_data ; source address
    call vdu_load_buffer
; DEBUG
    call vdu_vblank
; END DEBUG
    jp @read_chunk ; jp get_input

@agm_next_unit:
; decompress buffer
    ld hl,(pv_img_buffer) ; source bufferId
    ld de,(pv_img_buffer) ; target bufferId
    call vdu_decompress_buffer
; call the video command buffer
    ld hl,(pv_cmd_buffer)
    call vdu_call_buffer 

    ret ; back to MOS
; end main

; must be final include in program so file data does not stomp on program code or other data
    include "files.inc"
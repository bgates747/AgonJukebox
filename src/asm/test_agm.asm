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

fname: asciz "Star_Wars__Battle_of_Yavin_tvc.agm"

; --- MAIN PROGRAM FILE ---
init:
    ld a,20
    call vdu_set_screen_mode
    xor a
    call vdu_set_scaling
    call vdu_cls

    ; call vp_messages

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

    ; ld hl,ps_filinfo_fname ; hl = pointer to filename
    ; call printString
    ; call printNewLine

; read the header of the .agm file
    ld hl,ps_fil_struct ; hl = pointer to fil struct
    ld de,ps_wav_header ; de = pointer to header
    ld bc,agm_header_size ; bc = size of header
    FFSCALL ffs_fread ; read the header of the .agm file

; read the header of the .agm file
    ; call print_agm_header

; BEGIN NORMAL INITIALIZATION
; enable audio channels
    ld a,ps_loaded_samples_max
    call vdu_enable_channels
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
    ld e,ps_loaded_samples_max
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

; DEBUG
    ; ret

    call print_agm_header
; END DEBUG

@read_segment:
; read the next segment header
    ld hl,ps_fil_struct
    ld bc,agm_segment_hdr_size ; bytes to read
    ld de,agm_segment_hdr   ; target address
    FFSCALL ffs_fread
    ; call print_segment_header ; DEBUG

@read_unit:
; read the unit header
    ld hl,ps_fil_struct
    ld bc,agm_unit_hdr_size ; bytes to read
    ld de,agm_unit_hdr   ; target address
    FFSCALL ffs_fread
    ; call print_unit_header ; DEBUG
; check unit type
    ld hl,(pv_img_buffer) ; default since most are video units
    ld a,(agm_unit_hdr+agm_unit_mask)
    and a,agm_unit_type
    jr nz,@F ; is video so skip ahead
    ld hl,(ps_dat_buffer) ; audio buffer
@@:
    ld (pv_chunk_buffer),hl

@read_chunk:
; check video playback timer
    ld a,(pv_draw_counter)
    dec a
    jr nz,@F
    ld a,(pv_draw_counter_reset)
@@:
    ld (pv_draw_counter),a
    call z,pv_draw_frame
; check audio playback timer
    ld a,(pv_sample_counter)
    dec a
    jr nz,@F
    ld a,60
@@:
    ld (pv_sample_counter),a
    call z,pv_play_sample
; check unit type
    ld a,(agm_unit_hdr+agm_unit_mask)
    and agm_unit_type
    jr z,@F ; audio
; check for max amount of video data loaded
    ld hl,pv_loaded_frames
    ld a,(pv_loaded_frames_max)
    cp a,(hl)
    jp z,@read_chunk ; jp z,get_input
    jr @read
@@: ; check for max amount of audio data loaded
    ld hl,ps_loaded_samples
    ld a,ps_loaded_samples_max
    cp a,(hl)
    jp z,@read_chunk ; jp z,get_input
@read: ; read the chunk header
    ld hl,ps_fil_struct
    ld bc,agm_chunk_hdr_size ; bytes to read
    ld de,agm_chunk_hdr   ; target address
    FFSCALL ffs_fread
    ; call print_chunk_header ; DEBUG
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
    ld hl,(pv_chunk_buffer) ; bufferId
    ld de,ps_agm_data ; source address
    call vdu_load_buffer
; DEBUG
    call vdu_vblank
; END DEBUG
    jp @read_chunk ; jp get_input

@agm_next_unit:
; check unit type
    ld hl,agm_unit_hdr+agm_unit_mask
    ld a,agm_unit_type
    and (hl)
    jr z,@audio
; decompress buffer
    ld hl,(pv_img_buffer) ; source bufferId
    ld de,(pv_img_buffer) ; target bufferId
    call vdu_decompress_buffer
; decompress again if srle2
    ld a,(agm_unit_hdr+agm_unit_mask)
    and agm_unit_cmp_typ
    cp agm_unit_cmp_srle2
    jr nz,@F
    ld hl,(pv_img_buffer) ; source bufferId
    ld de,(pv_img_buffer) ; target bufferId
    call vdu_decompress_buffer
@@: ; increment number of frames loaded
    ld hl,pv_loaded_frames
    inc (hl)
; increment the image buffer
    ld a,(pv_img_buffer) ; only need the low byte
    inc a
    ld hl,pv_loaded_frames_max
    cp a,(hl)
    jr nz,@F
    xor a
@@:
    ld (pv_img_buffer),a

    jp @read_unit

@audio:
; increment the audio data buffer
    ld a,(ps_dat_buffer) ; only need the low byte
    inc a
    cp ps_loaded_samples_max
    jr nz,@F
    xor a
@@:
    ld (ps_dat_buffer),a
; increment the number of samples loaded
    ld hl,ps_loaded_samples
    inc (hl)

    ; call waitKeypress

    jp @read_segment

    ret ; back to MOS
; end main

pv_draw_frame:
; check whether enough frames have been loaded for playback
    ld a,(pv_loaded_frames)
    ld hl,ps_wav_data+agm_frame_rate
    cp a,(hl)
    ret m ; not enough frames loaded
; decrement frames loaded
    dec a
    ld (pv_loaded_frames),a
; call the video command buffer
    ld hl,(pv_cmd_buffer)
    call vdu_call_buffer 
; increment the command buffer
    ld a,(pv_cmd_buffer) ; only need the low byte
    inc a
    ld hl,pv_loaded_frames_max
    cp a,(hl)
    jr nz,@F
    xor a
@@:
    ld (pv_cmd_buffer),a
    ret
; end pv_draw_frame

pv_play_sample:
; check whether enough frames have been loaded for playback
    ld a,(pv_loaded_frames)
    ld hl,ps_wav_data+agm_frame_rate
    cp a,(hl)
    ret m ; not enough frames loaded
; ; check whether enough samples have been loaded for playback
;     ld a,(ps_loaded_samples)
;     dec a
;     ret m ; not enough samples loaded
; decrement samples loaded
    ld a,(ps_loaded_samples)
    dec a
    ld (ps_loaded_samples),a
; call the audio command buffer
    ld hl,(ps_cmd_buffer)
    call vdu_call_buffer
; increment the command buffer
    ld a,(ps_cmd_buffer) ; only need the low byte
    inc a
    cp ps_loaded_samples_max
    jr nz,@F
    xor a
@@:
    ld (ps_cmd_buffer),a
    ret
; end pv_play_sample

    ; call waitKeypress

; must be final include in program so file data does not stomp on program code or other data
    include "files.inc"
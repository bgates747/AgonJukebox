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

test_width: equ 200
test_height: equ 150
test_bytes_to_read: dl 0 ; number of bytes read

test_image_buffer: equ 4000
test_frame_number: dl 0

test_frames_per_second: equ 6
test_frame_timer: equ 120/test_frames_per_second

test_chunksize: equ 48000/60

screen_width: equ 512
screen_height: equ 384


; agm segment header
agm_segment_size_last: db 0 ; 4 bytes: size of previous segment (including unit and chunk headers)
agm_segment_size_this: db 4  ; 4 bytes: size of this segment (including unit and chunk headers)

; unit header contains metadata about the next unit being read
agm_unit_mask:     equ 0              ; 1 byte: encodes what to do with the unit with the following masks
agm_unit_type:     equ %10000000  ; bit 7, 0 = audio, 1 = video
agm_unit_gcol:     equ %00000111  ; bits 0-2, set gcol plotting mode for video frames, see 'GCOL paint modes' in vdu_plot.inc
agm_unit_cmp_typ:  equ %00011000  ; bits 3-4, compression type with the following types
agm_unit_cmp_non:  equ %00000000  ; no compression (bits 3,4 clear)
agm_unit_cmp_tbv:  equ %00001000  ; TurboVega compression (bit 3 set)
agm_unit_cmp_rle:  equ %00010000  ; Run-Length Encoding (bit 4 set)
agm_unit_cmp_res:  equ %00011000  ; Reserved for future use (bits 3,4 set)

; chunk header (for each chunk of a unit)
agm_chunk_size: equ 0        ; 4 bytes: size of the chunk (excluding chunk header); 0 = end of unit



; --- MAIN PROGRAM FILE ---
init:
; set up display
    ; ld a,8 ; 320x240x64 single-buffered
    ld a,20 ; 512x384x64 single-buffered
    call vdu_set_screen_mode
    xor a
    call vdu_set_scaling
    call vdu_cursor_off

; set graphics mode to xor
    ld a,3 ; mode xor
    ld c,c_black
    call vdu_gcol
    call vdu_clg

; open the file
    ld hl,ps_fil_struct
    ld de,test_fn
    ld c,fa_read
    FFSCALL ffs_fopen

; skip the .agm header for now
    ld hl,ps_fil_struct
    ld de,68 ; low 3 bytes of seek position
    ld c,0 ; high byte of seek position
    FFSCALL ffs_flseek
    ret
; end init
main:
    ld hl,0
    ld (test_frame_number),hl

@play_loop:
    call vdu_home_cursor ; DEBUG

; clear the image buffer
    ld hl,test_image_buffer
    call vdu_clear_buffer

; set the frame timer
    ld hl,test_frame_timer
    ld iy,tmr_test
    call tmr_set

; read how many bytes in the next chunk
    ld hl,ps_fil_struct
    ld bc,4 ; bytes to read
    ld de,ps_agm_data ; target address
    FFSCALL ffs_fread
    ld hl,(ps_agm_data) ; number of bytes to read this frame
    ld (test_bytes_to_read),hl
    push bc

    CALL printDec ; DEBUG; print the number of bytes to read

    pop hl
    SIGN_HLU
    jp z,@done

; compute number of chunks to load
    ld hl,(test_bytes_to_read)
    ld de,test_chunksize
    call udiv24 ; de = number of whole chunks, hl = remaining bytes
    push hl ; save remaining bytes

    ex de,hl ; hl = number of whole chunks
    SIGN_HLU
    jp z,@load_remain ; no bytes to load so skip ahead

    ld b,l ; loop counter
@load_loop:
    push bc ; save loop counter

; read the next chunk from the file
    ld bc,test_chunksize ; bytes to read
    ld hl,ps_fil_struct
    ld de,ps_agm_data ; target address
    FFSCALL ffs_fread

; load buffer with the data read
    ld hl,test_image_buffer ; bufferId
    ld bc,test_chunksize ; bytes to load
    call vdu_load_buffer

; bump loop counter
    pop bc ; restore loop counter
    djnz @load_loop

@load_remain: ; check for remaining bytes to load
    pop hl ; restore remaining bytes
    SIGN_HLU
    jp z,@decompress ; no bytes left to load so skip ahead

; read the final chunk from the file
    push hl
    pop bc ; remaining bytes
    ld hl,ps_fil_struct
    ld de,ps_agm_data ; target address
    FFSCALL ffs_fread

; load buffer with the data read
    ld hl,test_image_buffer ; bufferId
    ld bc,test_chunksize ; bytes to load
    call vdu_load_buffer

@decompress: ; decompress the loaded buffer
    ; ld hl,test_image_buffer ; sourceBufferId
    ; ld de,test_image_buffer ; targetBufferId
    ; call vdu_decompress_buffer

; make an image from the buffer
    ld hl,test_image_buffer ; bufferId
    call vdu_consolidate_buffer
    ld hl,test_image_buffer ; bufferId
    call vdu_buff_select
    ld a,1 ; rgba2222
    ld bc,test_width ; width
    ld de,test_height ; height
	call vdu_bmp_create

; check the frame timer
@wait_here:
    ld iy,tmr_test
    call tmr_get
    jp z,@F
    jp m,@F
    jp @wait_here

@@: ; plot the image
    ld bc,[screen_width-test_width]/2 ; x
    ld de,[screen_height-test_height]/2 ; y
    call vdu_plot_bmp

; ; print the frame number
;     call vdu_home_cursor
;     ld hl,(test_frame_number)
;     inc hl
;     ld (test_frame_number),hl
;     call printDec

; loop back to play_loop
    jp @play_loop

@done: ; close the file
    ld hl,ps_fil_struct
    FFSCALL ffs_fclose

; return display to normal
    call vdu_cursor_on

    ret ; back to MOS
; end main

; must be final include in program so file data does not stomp on program code or other data
    include "files.inc"

; test_fn: asciz "a_ha__Take_On_Me_240x180x2_cmp.agm"
; test_fn: asciz "a_ha__Take_On_Me_512x384x1_cmp.agm"
; test_fn: asciz "a_ha__Take_On_Me_320x240x4_cmp.agm"
; test_fn: asciz "a_ha__Take_On_Me_160x120x6_cmp.agm"
test_fn: asciz "a_ha__Take_On_Me_200x150x6.agm"

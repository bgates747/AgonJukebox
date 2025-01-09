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
    include "files.inc"
    include "fonts.inc"
    include "fonts_list.inc"
    include "fixed168.inc"
    include "timer.inc"
    include "vdu.inc"
    include "vdu_buffered_api.inc"
    include "vdu_fonts.inc"
    include "vdu_plot.inc"
    include "vdu_sound.inc"

; APPLICATION INCLUDES
    include "ascii.inc"
    include "input.inc"
    include "music.inc"
    include "play.inc"
    include "timer_jukebox.inc"
    include "wav.inc"
    include "debug.inc"

; --- MAIN PROGRAM FILE ---
original_screen_mode: db 0

init:
; get current screen mode and save it so we can return to it on exit
    call vdu_get_screen_mode
    ld (original_screen_mode),a
; set up display for gameplay
    ld a,20
    call vdu_set_screen_mode
    xor a
    call vdu_set_scaling
; set text background color
    ld a,c_blue_dk+128
    call vdu_colour_text
; set text foreground color
    ld a,c_white
    call vdu_colour_text
; set the cursor off
    call vdu_cursor_off
; clear the screen
    call vdu_cls
; clear all buffers
    call vdu_clear_all_buffers
; load fonts
	call fonts_load
; select font
    ld hl,Lat2_VGA8_8x8
    ld a,1 ; flags
    call vdu_font_select
; print ascii art splash screen
    call vdu_cls
    ld c,0 ; x
    ld b,4 ; y
    call vdu_move_cursor
    call printInline
    asciz "Welcome to...\r\n"
    ld hl,agon_jukebox_ascii
    call printString
    call printInline
    asciz "Press keys 0-9 to play a song.\r\n"
; initialize play sample timer interrupt handler
    call ps_prt_irq_init
    ret
; end init

main:
; call get_input to start player
    call get_input
; user pressed ESC to quit so shut down everytyhing and gracefully exit to MOS
    call ps_prt_stop ; stop the PRT timer
    ei ; interrupts were disabled by get_input
; restore original screen mode
    ld a,(original_screen_mode)
    call vdu_set_screen_mode
    call vdu_reset_viewports
    call vdu_cls
; print thanks for playing message
    call printInline
    asciz "Thank you for using\r\n"
    ld hl,agon_jukebox_ascii
    call printString
    call vdu_cursor_on
    ret ; back to MOS
; end main

ps_wav_header: ; marker for top of the wav file header and song data
; (must be last so buffer doesn't overwrite other program code or data)
; .wav header data
; WAV File Structure in Memory with LIST Chunk
ps_wav_riff:          blkb 4,0   ; 4 bytes: "RIFF" identifier
ps_wav_file_size:     blkb 4,0   ; 4 bytes: Total file size minus 8 bytes for RIFF header
ps_wav_wave:          blkb 4,0   ; 4 bytes: "WAVE" identifier
ps_wav_fmt_marker:    blkb 4,0   ; 4 bytes: "fmt " subchunk marker
ps_wav_fmt_size:      blkb 4,0   ; 4 bytes: Format chunk size (16 for PCM)
ps_wav_audio_format:  blkb 2,0   ; 2 bytes: Audio format (1 = PCM)
ps_wav_num_channels:  blkb 2,0   ; 2 bytes: Number of channels (1 = mono, 2 = stereo)
ps_wav_sample_rate:   blkb 4,0   ; 4 bytes: Sample rate in Hz (e.g., 32768)
ps_wav_byte_rate:     blkb 4,0   ; 4 bytes: Bytes per second (SampleRate * NumChannels * BitsPerSample / 8)
ps_wav_block_align:   blkb 2,0   ; 2 bytes: Bytes per sample block (NumChannels * BitsPerSample / 8)
ps_wav_bits_per_sample: blkb 2,0 ; 2 bytes: Bits per sample (e.g., 8 or 16)

; LIST Chunk (Extra Metadata)
ps_wav_list_marker:   blkb 4,0   ; 4 bytes: "LIST" marker
ps_wav_list_size:     blkb 4,0   ; 4 bytes: Size of the LIST chunk (e.g., 26)
ps_wav_info_marker:   blkb 4,0   ; 4 bytes: "INFO" marker
ps_wav_isft_marker:   blkb 4,0   ; 4 bytes: "ISFT" marker (software identifier)
ps_wav_isft_data:     blkb 14,0  ; 14 bytes: Software info string (e.g., "Lavf59.27.100")
ps_wav_isft_padding:  blkb 2,0   ; 2 bytes: Padding/NULL terminator for alignment

; Data Chunk
ps_wav_data_marker:   blkb 4,0   ; 4 bytes: "data" subchunk marker
ps_wav_data_size:     blkb 4,0   ; 4 bytes: Size of the audio data in bytes
; Total Header Size: 76 bytes
;
; buffer for sound data
ps_wav_data_start:    blkb 0,0   ; Start of audio data
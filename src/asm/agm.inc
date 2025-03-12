; WAV File Structure Offsets and Descriptions
wav_riff:          EQU 0    ; 4 bytes: "RIFF" identifier
wav_file_size:     EQU 4    ; 4 bytes: Total file size minus 8 bytes for RIFF header
wav_wave:          EQU 8    ; 4 bytes: "WAVE" identifier
wav_fmt_marker:    EQU 12   ; 4 bytes: "fmt " subchunk marker for .wav, "agm" for .agm
wav_fmt_size:      EQU 16   ; 4 bytes: Format chunk size (16 for PCM)
wav_audio_format:  EQU 20   ; 2 bytes: Audio format (1 = PCM)
wav_num_channels:  EQU 22   ; 2 bytes: Number of channels (1 = mono, 2 = stereo)
wav_sample_rate:   EQU 24   ; 4 bytes: Sample rate in Hz (e.g., 32768)
wav_byte_rate:     EQU 28   ; 4 bytes: Bytes per second (SampleRate * NumChannels * BitsPerSample / 8)
wav_block_align:   EQU 32   ; 2 bytes: Bytes per sample block (NumChannels * BitsPerSample / 8)
wav_bits_per_sample: EQU 34 ; 2 bytes: Bits per sample (e.g., 8 or 16)

; LIST Chunk (Extra Metadata)
wav_list_marker:   EQU 36   ; 4 bytes: "LIST" marker
wav_list_size:     EQU 40   ; 4 bytes: Size of the LIST chunk (e.g., 26)
wav_info_marker:   EQU 44   ; 4 bytes: "INFO" marker
wav_isft_marker:   EQU 48   ; 4 bytes: "ISFT" marker (software identifier)
wav_isft_data:     EQU 52   ; 14 bytes: Software info string (e.g., "Lavf59.27.100")
wav_isft_padding:  EQU 66   ; 2 bytes: Padding/NULL terminator for alignment

; Data Chunk
wav_data_marker:   EQU 68   ; 4 bytes: "data" subchunk marker
wav_data_size:     EQU 72   ; 4 bytes: Size of the audio data in bytes
wav_data_start:    EQU 76   ; Start of audio data
wav_header_size:   EQU wav_data_start ; Total Header Size: 76 bytes

; AGON Movie (.agm) Header Structure Offsets and Descriptions
; The first 76 bytes are the size and layout of a standard .wav header
agm_magic:         EQU 0+76    ; 6 bytes: "AGNMOV" identifier (offset 76-81)
agm_version:       EQU 6+76    ; 1 byte: File format version (offset 82)
agm_width:         EQU 7+76    ; 2 bytes: Video width in pixels (offsets 83-84)
agm_height:        EQU 9+76    ; 2 bytes: Video height in pixels (offsets 85-86)
agm_frame_rate:    EQU 11+76   ; 1 byte: Frames per second (offset 87)
agm_total_frames:  EQU 12+76   ; 4 bytes: Total number of frames (offsets 88-91)
agm_audio_seconds: EQU 16+76   ; 4 bytes: Total seconds of audio (offsets 92-95)
agm_reserved:      EQU 20+76   ; 48 bytes: Reserved for future features (offsets 96-143)
agm_header_size:   EQU 144     ; Total .agm Header size

; | WAV HEADER (76 bytes) |
; | AGM HEADER (68 bytes) |
; -----------------------------------
; | Segment Header (8 bytes) |
; |   Unit Header (1 byte) → Video  |
; |     Chunk Header (4 bytes)      |
; |     Video Data (chunk_size)     |
; |     Chunk Header (4 bytes)      |
; |     Video Data (chunk_size)     |
; |     (Repeat until chunk_size = 0) |
; -----------------------------------
; |   Unit Header (1 byte) → Audio  |
; |     Chunk Header (4 bytes)      |
; |     Audio Data (chunk_size)     |
; |     (Repeat until chunk_size = 0) |
; -----------------------------------
; | Segment Header (8 bytes) |  ← Next Frame
; | (Repeat for all frames)  |
; -----------------------------------

; agm segment header
agm_segment_hdr_size: equ 8 ; size of the segment header
agm_segment_hdr: blkb agm_segment_hdr_size,0
agm_segment_size_last: equ 0 ; 4 bytes: size of previous segment (including unit and chunk headers)
agm_segment_size_this: equ 4  ; 4 bytes: size of this segment (including unit and chunk headers)

; unit header contains metadata about the next unit being read
agm_unit_hdr_size: equ 1              ; size of the unit header
agm_unit_hdr: blkb agm_unit_hdr_size,0
agm_unit_mask:     equ 0              ; 1 byte: encodes what to do with the unit with the following masks
agm_unit_type:     equ %10000000  ; bit 7, 0 = audio, 1 = video
agm_unit_gcol:     equ %00000111  ; bits 0-2, set gcol plotting mode for video frames, see 'GCOL paint modes' in vdu_plot.inc
agm_unit_cmp_typ:  equ %00011000  ; bits 3-4, compression type with the following types
agm_unit_cmp_non:  equ %00000000  ; no compression (bits 3,4 clear)
agm_unit_cmp_tbv:  equ %00001000  ; TurboVega compression (bit 3 set)
agm_unit_cmp_szip:  equ %00010000  ; szip compression (bit 4 set)
agm_unit_cmp_srle2:  equ %00011000  ; rle2 + szip compression (bits 3,4 set)

; chunk header (for each chunk of a unit)
agm_chunk_hdr_size: equ 4    ; size of the chunk header
agm_chunk_hdr: blkb agm_chunk_hdr_size,0
agm_chunk_size: equ 0        ; 4 bytes: size of the chunk (excluding chunk header); 0 = end of unit
agm_unit_load_started: db 0 ; flag to indicate the unit load has started

pv_cmd_base_buffer: equ 0x4000
pv_img_base_buffer: equ 0x4100
pv_cmd_buffer: dl pv_cmd_base_buffer ; Points to the current video command buffer to be called.
pv_img_buffer: dl pv_img_base_buffer ; Points to the current video frame buffer to be loaded.
pv_draw_counter_reset: db 0 ; 60 / frame_rate.
pv_draw_counter: db 0 ; Counts down from pv_draw_counter_reset, triggering video frame draw at zero
pv_sample_counter: db 0 ; Counts down from 60, triggering audio playback and first frame draw of segment.
pv_loaded_frames: db 0 ; Tracks buffered frames (fps * pv_loaded_segments_max).
pv_loaded_frames_max: db 0 ; Maximum number of buffered frames (fps * pv_loaded_segments_max).
pv_loaded_segments_max: equ 3 ; max number of segments to buffer.

ps_cmd_load_base_buffer: equ 0x4200
ps_cmd_play_base_buffer: equ 0x4300
ps_dat_base_buffer: equ 0x4400
ps_cmd_load_buffer: dl ps_cmd_load_base_buffer
ps_cmd_play_buffer: dl ps_cmd_play_base_buffer ; Points to the current audio command buffer to be called.
ps_dat_buffer: dl ps_dat_base_buffer ; Points to the current audio data buffer to be loaded.
ps_loaded_samples: db 0 ; Tracks buffered audio samples (max pv_loaded_segments_max).
pv_chunk_buffer: dl 0 ; target bufferId of the current chunk being read
pv_bytes_read: dw32 0 ; Number of bytes read from the file


agm_window_left: equ 0
agm_window_top: equ 8
agm_window_right: equ 43*8-1
agm_window_bottom: equ 19*8-1
agm_window_width: equ agm_window_right-agm_window_left+1
agm_window_height: equ agm_window_bottom-agm_window_top+1

; inputs:
;     iy = pointer to a filinfo struct
;     hl = pointer to a fil struct
;     de = pointer to a zero-terminated filename
;     a  = (ps_media_type)
agm_play:
; verify valid .wav or .agm file
    cp media_type_agm ; a was set by play_song
    jp nz,ps_close_file

; ; clear all buffers and switch screen mode
;     call vdu_clear_all_buffers
;     ld a,8 ; 320x240x64 60Hz single-buffered
;     call vdu_set_screen_mode
; ; set text fg and bg colours to normal
;     call set_text_colours_normal
; ; set cursor behaviuor
;     call vdu_cursor_off
;     ld h,%00010000 ; bit 4 controls cursor scroll at bottom of screen
;     ld l,%00010000 ; bit 4 set means cursor wraps to top of screen
;     call vdu_cursor_behaviour
; ; reset text viewports and clear the screen
;     call vdu_reset_viewports
;     call vdu_cls

    call print_agm_header

; enable audio channels
    ld a,pv_loaded_segments_max
    call vdu_enable_channels
; initalize counters and flags
    ld a,1 ; play audio first tick after buffering is complete
    ld (pv_sample_counter),a
    ld a,60
    ld hl,(ps_wav_header+agm_frame_rate) ; l = frame rate
    ld h,a ; h = 60
    call udiv8 ; h = 60 / frame rate
    ld a,h
    ld (pv_draw_counter_reset),a
    ; srl a ; divide draw counter by 2 so frame drawing is offset by 1/2 frame from audio playback
    ld (pv_draw_counter),a
    ld hl,ps_wav_header+agm_frame_rate
    ld d,(hl) ; d = frame rate
    ld e,pv_loaded_segments_max
    mlt de
    ld a,e
    ld (pv_loaded_frames_max),a
; initialize command and data buffers
    call pv_load_audio_cmd_buffers
    call pv_play_audio_cmd_buffers
    call pv_load_video_cmd_buffers
    xor a
    ld (ps_cmd_load_buffer),a
    ld (ps_cmd_play_buffer),a
    ld (ps_dat_buffer),a
    ld (pv_cmd_buffer),a
    ld (pv_img_buffer),a
    ld (ps_loaded_samples),a
    ld (pv_loaded_frames),a
; set read_media_routine
    ld hl,agm_do
    ld (read_media_routine),hl
; compute the song duration in hh:mm:ss format and print it
    call vp_duration ; set viewport to duration window
    ld hl,(ps_wav_header+agm_audio_seconds) ; ls 24 bits of duration is sufficient and all we're prepared for
    call seconds_to_hhmmss ; hl pointer to string representation of HH:MM:SS
    call printString ; print the duration
; reset the playbar counter and pv_bytes_read to zero
    ld hl,0
    ld (ps_playhead),hl
    ld (pv_bytes_read),hl
    ld (pv_bytes_read+2),hl
; draw a filled rectangle in the video window to clear it
    ld a,gcol_mode_col
    ld c,c_blue_dk
    call vdu_gcol
    ld bc,agm_window_left
    ld de,agm_window_top
    ld ix,agm_window_right
    ld iy,agm_window_bottom
    call vdu_plot_rf
; set ps_mode_playing
    ld hl,ps_mode
    set ps_mode_playing,(hl)

; read the first segmment header
    call agm_read_segment_hdr
; read the first unit header
    call agm_read_unit_hdr
; preload buffers to max capacity (also starts the PRT timer)
    call agm_load_buffers

; jump to user input (also enables interrupts)
    jp get_input
; end agm_play

agm_load_buffers:
    call ps_prt_stop
@loop:
    call agm_read_chunk
    call print_num_buffered
    call printInline
    asciz " BUFFERING ..."
    ld a,(ps_loaded_samples)
    cp pv_loaded_segments_max
    jr nz,@loop
    call vdu_cls
    call ps_prt_start
    ret
; end agm_load_buffers

agm_read_segment_hdr:
; read the next segment header
    ld hl,ps_fil_struct
    ld bc,agm_segment_hdr_size ; bytes to read
    ld de,agm_segment_hdr   ; target address
    FFSCALL ffs_fread
    ; call print_segment_header ; DEBUG
    ret
; end agm_read_segment_hdr

agm_read_unit_hdr:
    xor a
    ld (agm_unit_load_started),a
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
    ; call vdu_clear_buffer
    ret
; end agm_read_unit_hdr

; this is the main playback and media loading function called by the PRT interrupt timer
; which is set to fire every 1/60th of a second
agm_do:
; check audio playback timer
    ld a,(pv_sample_counter)
    dec a
    jr nz,@F
    ld a,60
@@:
    ld (pv_sample_counter),a
    call z,pv_play_sample
; check video playback timer
    ld a,(pv_draw_counter)
    dec a
    jr nz,@F
    ld a,(pv_draw_counter_reset)
@@:
    ld (pv_draw_counter),a
    call z,pv_draw_frame
agm_read_chunk:
    ; call print_num_buffered ; DEBUG
; check unit type
    ld a,(agm_unit_hdr+agm_unit_mask)
    and agm_unit_type
    jr z,@audio ; audio
; check for max amount of video data loaded
    ld hl,pv_loaded_frames
    ld a,(pv_loaded_frames_max)
    cp a,(hl)
    ret z ; to interrupt handler
    jr @check_first
@audio: ; check for max amount of audio data loaded
    ld hl,ps_loaded_samples
    ld a,pv_loaded_segments_max
    cp a,(hl)
    ret z ; to interrupt handler
@check_first: 
; check whether this is the first load of the unit
    ld a,(agm_unit_load_started)
    and a ; check for first load
    jp nz,@read
    inc a
    ld (agm_unit_load_started),a
    ld hl,(pv_chunk_buffer) ; bufferId
    call vdu_clear_buffer
@read: 
; read the chunk header
    ld hl,ps_fil_struct
    ld bc,agm_chunk_hdr_size ; bytes to read
    ld de,agm_chunk_hdr   ; target address
    FFSCALL ffs_fread
    ; call print_chunk_header ; DEBUG
; check chunk size for zero, indicating end of unit
    ld hl,(agm_chunk_hdr+agm_chunk_size) ; bytes to load
    SIGN_HLU 
    jr z,agm_next_unit
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
; done
    ret ; to interrupt handler
; end agm_do

agm_next_unit:

    ; call print_num_buffered ; DEBUG

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
    jr nz,@decomp2
    ld hl,(pv_img_buffer) ; source bufferId
    ld de,(pv_img_buffer) ; target bufferId
    call vdu_decompress_buffer
@decomp2: ; increment number of frames loaded
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
    call agm_read_unit_hdr

    ; call print_num_buffered ; DEBUG

    jp agm_read_chunk ; returns to interrupt handler from there
@audio:
; call the command load buffer
    ld hl,(ps_cmd_load_buffer)
    call vdu_call_buffer
; increment the command load buffer
    ld a,(ps_cmd_load_buffer) ; only need the low byte
    inc a
    cp pv_loaded_segments_max
    jr nz,@F
    xor a
@@: ld (ps_cmd_load_buffer),a
; increment the audio data buffer
    ld a,(ps_dat_buffer) ; only need the low byte
    inc a
    cp pv_loaded_segments_max
    jr nz,@F
    xor a
@@: ld (ps_dat_buffer),a
; increment the number of samples loaded
    ld hl,ps_loaded_samples
    inc (hl)

    call agm_read_segment_hdr
    call agm_read_unit_hdr
    jp agm_read_chunk ; returns to interrupt handler from there
; end main

pv_draw_frame:
    ; call print_num_buffered
; check whether enough frames have been loaded for playback
    ld a,(pv_loaded_frames)
    dec a
    jp p,@F ; enough frames loaded
    call agm_load_buffers ; refill the buffers
; reset a to max loaded frames -1
    ld a,(pv_loaded_frames_max)
    dec a
@@: ; update frames loaded
    ld (pv_loaded_frames),a
; call the video command buffer
    ld hl,(pv_cmd_buffer)
    call vdu_call_buffer 
@@: ; increment the command buffer
    ld a,(pv_cmd_buffer) ; only need the low byte
    inc a
    ld hl,pv_loaded_frames_max
    cp a,(hl)
    jr nz,@F
    xor a
@@:
    ld (pv_cmd_buffer),a
    ret ; to agm_do
; end pv_draw_frame

pv_play_sample:
    ; call print_num_buffered
; check whether enough samples have been loaded for playback
    ld a,(ps_loaded_samples)
    dec a
    jp p,@F ; enough samples loaded
    call agm_load_buffers ; refill the buffers
; reset a to max loaded segments -1
    ld a,pv_loaded_segments_max-1
@@: ; update samples loaded
    ld (ps_loaded_samples),a
; call the audio command buffer
    ld hl,(ps_cmd_play_buffer)
    call vdu_call_buffer
; increment the command buffer
    ld a,(ps_cmd_play_buffer) ; only need the low byte
    inc a
    cp pv_loaded_segments_max
    jr nz,@F
    xor a
@@:
    ld (ps_cmd_play_buffer),a
    ret ; to agm_do
; end pv_play_sample

; verify that a file is an .agm file
; inputs: hl = pointer to fil struct, de = pointer to filename
; returns: zero flag set,   a = 0 if not a file we can read
;          zero flag reset, a = 2 if .agm file
; destroys: if called from verify_wav as usual it doesn't matter
;           otherwise, af, hl, de, iy
verify_agm:
; clear the .agm header buffer
    push hl
    push de
    ld bc,agm_header_size
    lea hl,iy+0 ; bf or ps agm_header
    call clear_mem
    pop de
    pop hl

; seek back to beginning of the file
    ld de,0
    ld c,0
    FFSCALL ffs_flseek

; read the header
    ld bc,agm_header_size
    lea de,iy+0 ; bf or ps agm_header
    FFSCALL ffs_fread

; verify the .agm header magic number 'AGNMOV'
    ld hl,(iy+agm_magic)
    ld de,0x4E4741 ; ascii for AGN in little-endian order
    or a ; clear carry
    sbc hl,de
    jr nz,@not_agm 

    ld hl,(iy+agm_magic+3)
    ld de,0x564F4D ; ascii for MOV in little-endian order
    or a ; clear carry
    sbc hl,de
    jr nz,@not_agm 

; check the version number and reject if not 0x01
    ld a,(iy+agm_version)
    cp 0x01
    jr nz,@not_agm

; looks good so fall through to @is_agm
@is_agm:
    ld a,1
    inc a ; reset zero flag and a = 2 indicating .agm file
    ret
@not_agm:
    xor a ; set zero flag and a = 0 indicating unreadable file
    ret
; end verify_agm

pv_load_video_cmd_buffers:   
    ld hl,pv_img_base_buffer
    ld a,(pv_loaded_frames_max)
    ld b,a
@clear_dat_loop:
    push bc ; save loop counter
    push hl ; save cmd buffer high byte and loop counter
    call vdu_clear_buffer
    pop hl
    inc l ; bump bufferId
    pop bc ; restore loop counter
    djnz @clear_dat_loop

    ld hl,pv_cmd_base_buffer
    ld a,(pv_loaded_frames_max)
    ld b,a
@clear_cmd_loop:
    push bc ; save loop counter
    push hl ; save cmd buffer high byte and loop counter
    call vdu_clear_buffer
    pop hl
    inc l ; bump bufferId
    pop bc ; restore loop counter
    djnz @clear_cmd_loop

    ld de,(ps_wav_header+agm_width)
    ld (@width),de
    dec de
    inc.s de ; clears ude
    ld hl,agm_window_width
    or a ; clear carry
    sbc hl,de
    ld de,agm_window_left
    add hl,de
    call hlu_div2
    ld a,l
    ld (@x),a
    ld a,h
    ld (@x+1),a

    ld de,(ps_wav_header+agm_height)
    ld (@height),de
    ld a,1 ; format 1 = RGBA2222
    ld (@height+2),a
    dec de
    inc.s de ; clears ude
    ld hl,agm_window_height
    or a ; clear carry
    sbc hl,de
    call hlu_div2
    ld de,agm_window_top
    add hl,de
    ld a,l
    ld (@y),a
    ld a,h
    ld (@y+1),a

    ld hl,pv_cmd_base_buffer
    ld a,(pv_loaded_frames_max)
    ld b,a
@load_cmd_loop:
    push bc ; save loop counter
    push hl ; save command bufferId
    ld a,l ; only need to load the low bytes of img bufferIds
    ld (@bufferId0),a 

    ld de,@cmd_start
    ld bc,@cmd_end-@cmd_start
    call vdu_load_buffer

    pop hl ; restore current command bufferId
    inc l ; bump bufferId
    pop bc ; restore loop counter
    djnz @load_cmd_loop

    ret 
@cmd_start:
; VDU 23, 27, &20, bufferId; : Select bitmap (using a buffer ID)
; inputs: hl=bufferId
            db 23,27,0x20
@bufferId0:  dw pv_img_base_buffer

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
; end pv_load_video_cmd_buffers

pv_load_audio_cmd_buffers:
    ld hl,ps_dat_base_buffer
    ld b,pv_loaded_segments_max
@clear_dat_loop:
    push bc ; save loop counter
    push hl ; save cmd buffer high byte and loop counter
    call vdu_clear_buffer
    pop hl
    inc l ; bump bufferId
    pop bc ; restore loop counter
    djnz @clear_dat_loop

    ld hl,ps_cmd_load_base_buffer
    ld b,pv_loaded_segments_max
@clear_cmd_loop:
    push bc ; save loop counter
    push hl ; save cmd buffer high byte and loop counter
    call vdu_clear_buffer
    pop hl
    inc l ; bump bufferId
    pop bc ; restore loop counter
    djnz @clear_cmd_loop

    ld hl,ps_cmd_load_base_buffer
    ld b,pv_loaded_segments_max
@load_cmd_loop:
    push bc ; save loop counter
    push hl ; save command bufferId
    ld a,l ; only need to load the low bytes of dat bufferIds
    ld (@bufferId0),a 
    ld (@bufferId1),a
    ld (@bufferId2),a

    ld (@channel0),a

    ld a,(ps_wav_header+wav_sample_rate)
    ld (@sample_rate),a
    ld a,(ps_wav_header+wav_sample_rate+1)
    ld (@sample_rate+1),a

    ld de,@cmd_start
    ld bc,@cmd_end-@cmd_start
    call vdu_load_buffer

    pop hl ; restore current command bufferId
    inc l ; bump bufferId
    pop bc ; restore loop counter
    djnz @load_cmd_loop
    ret
@cmd_start:
; Command 14: Consolidate blocks in a buffer
; VDU 23, 0, &A0, bufferId; 14
    db 23,0,0xA0 ; vdu buffered api command header
@bufferId0: dw ps_dat_base_buffer
    db 14 ; consolidate blocks command
; vdu_buffer_to_sound command string
; Command 2: Buffer to sound
; VDU 23, 0, &85, channel (ignored), 5, 2, bufferId; format, [sampleRate;]
    db 23,0,0x85 ; vdu sound command header
    db 0x00 ; channel (ignored)
    db 0x05 ; buffer to sound command
    db 0x02 ; command 2 create sample
@bufferId1: dw ps_dat_base_buffer
    db 1+8 ; 1 = 8-bit unsigned PCM mono, 8 = sample rate argument follows
@sample_rate: dw 0x0000 ; sample rate Hz
; Command 4: Set waveform
; VDU 23, 0, &85, channel, 4, waveformOrSample, [bufferId;]
    db 23,0,$85 ; vdu sound command header  
@channel0: db 0 ; channel
    db 4 ; set waveform command
    db 8 ; waveform 8 = sample
@bufferId2: dw ps_dat_base_buffer ; sample bufferId
@cmd_end:
; end pv_load_audio_cmd_buffers

pv_play_audio_cmd_buffers:
    ld hl,ps_cmd_play_base_buffer
    ld b,pv_loaded_segments_max
@clear_cmd_loop:
    push bc ; save loop counter
    push hl ; save cmd buffer high byte and loop counter
    call vdu_clear_buffer
    pop hl
    inc l ; bump bufferId
    pop bc ; restore loop counter
    djnz @clear_cmd_loop

    ld hl,ps_cmd_play_base_buffer
    ld b,pv_loaded_segments_max
@load_cmd_loop:
    push bc ; save loop counter
    push hl ; save command bufferId
    ld a,l ; only need to load the low bytes of dat bufferIds

    ld (@channel1),a

    ld de,@cmd_start
    ld bc,@cmd_end-@cmd_start
    call vdu_load_buffer

    pop hl ; restore current command bufferId
    inc l ; bump bufferId
    pop bc ; restore loop counter
    djnz @load_cmd_loop
    ret
@cmd_start:
; Command 0: Play note
; VDU 23, 0, &85, channel, 0, volume, frequency; duration;
    db 23,0,$85 ; vdu sound command header
@channel1: db 0 ; channel
    db 0 ; play note command
    db 127  ; volume 127 = max
    dw 0 ; frequency (relevant only for tuneable samples)
    dw 0 ; duration (ms), zero means play one time in full
@cmd_end:
; end ps_load_audio_cmd_buffers


print_segment_header:
    call vp_debug
    call vdu_cls
    call printInline
    asciz "S:"
    ; ld hl,(agm_segment_hdr+agm_segment_size_last)
    ; call printDec
    ld hl,(agm_segment_hdr+agm_segment_size_this)
    call printDec
    call printNewLine

    ld de,-agm_segment_hdr_size
    add hl,de
    ld (agm_segment_hdr+agm_segment_size_this),hl
    ret
; end print_segment_header

print_unit_header:
    ld hl,(agm_segment_hdr+agm_segment_size_this)
    ld de,-agm_unit_hdr_size
    add hl,de
    ld (agm_segment_hdr+agm_segment_size_this),hl

    call printInline
    asciz "Unit: "

    ld a,(agm_unit_hdr+agm_unit_mask)
    and agm_unit_type
    jr z,@audio

    call printInline
    asciz "video img:"
    ld hl,(pv_img_buffer)
    call printHex16
    call printInline
    asciz " cmd:"
    ld hl,(pv_cmd_buffer)
    call printHex16

    ld a,(agm_unit_hdr+agm_unit_mask)
    and agm_unit_cmp_typ
    cp agm_unit_cmp_non
    jr z,@no_compression
    cp agm_unit_cmp_tbv
    jr z,@tbv_compression
    cp agm_unit_cmp_szip
    jr z,@szip_compression
    call printInline
    asciz " srle2\r\n"
    ret
@tbv_compression:
    call printInline
    asciz " tbv\r\n"
    ret
@szip_compression:
    call printInline
    asciz " szip\r\n"
    ret
@no_compression:
    call printInline
    asciz " raw\r\n"
    ret
@audio:
    call printInline
    asciz "audio dat:"
    ld hl,(ps_dat_buffer)
    call printHex16
    call printInline
    asciz " cmd:"
    ld hl,(ps_cmd_play_buffer)
    call printHex16
    call printNewLine

    ret
; end print_unit_header

print_chunk_header:
    ld hl,(agm_segment_hdr+agm_segment_size_this)
    ld de,-agm_chunk_hdr_size
    add hl,de
    ld (agm_segment_hdr+agm_segment_size_this),hl

    call printInline
    asciz "Chunk:"
    ld hl,(agm_chunk_hdr+agm_chunk_size)
    call printDec

    ld de,(agm_segment_hdr+agm_segment_size_this)
    ex de,hl
    or a ; clear carry
    sbc hl,de
    ld (agm_segment_hdr+agm_segment_size_this),hl
    call printDec

    call printNewLine
    ret
; end print_chunk_header

print_num_buffered:
    call vp_num_buffered
    call vdu_cls
    call printInline
    asciz "Frames: "
    ld a,(pv_loaded_frames)
    call printHex8
    call printInline
    asciz " Samples: "
    ld a,(ps_loaded_samples)
    call printHex8
    ret

print_agm_header:
    call vp_agm_header
    call vdu_cls

    call printInline
    asciz "sz:"
    ld hl,(ps_wav_header+agm_width)
    dec hl
    inc.s hl ; zeroes hlu
    call printDec
    call printInline
    asciz "x"
    ld hl,(ps_wav_header+agm_height)
    dec hl
    inc.s hl ; zeroes hlu
    call printDec
    call printInline
    asciz " fps:"
    ld a,(ps_wav_header+agm_frame_rate)
    call printHexA
    call printInline
    asciz " n:"
    ld hl,(ps_wav_header+agm_total_frames)
    call printDec
    call printInline
    asciz " s:"
    ld hl,(ps_wav_header+agm_audio_seconds)
    call printDec
    ret

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

pv_cmd_base_buffer: equ 0x4000
pv_img_base_buffer: equ 0x4100
pv_cmd_buffer: dl 0 ; Points to the current video command buffer to be called.
pv_img_buffer: dl 0 ; Points to the current video frame buffer to be loaded.
pv_draw_counter_reset: db 0 ; 60 / frame_rate.
pv_draw_counter: db 0 ; Counts down from pv_draw_counter_reset, triggering video frame draw at zero
pv_sample_counter: db 0 ; Counts down from 60, triggering audio playback and first frame draw of segment.
pv_loaded_frames: db 0 ; Tracks buffered frames (fps * ps_loaded_samples_max).
pv_loaded_frames_max: db 0 ; Maximum number of buffered frames (fps * ps_loaded_samples_max).

ps_cmd_base_buffer: equ 0x4200
ps_dat_base_buffer: equ 0x4300
ps_cmd_buffer: dl ps_cmd_base_buffer ; Points to the current audio command buffer to be called.
ps_dat_buffer: dl ps_dat_base_buffer ; Points to the current audio data buffer to be loaded.
ps_loaded_samples_max: equ 4 ; Number of segments to buffer (max 4).
ps_loaded_samples: db 0 ; Tracks buffered audio samples (max ps_loaded_samples_max).
pv_chunk_buffer: dl 0 ; target bufferId of the current chunk being read
pv_bytes_read: dw32 0 ; Number of bytes read from the file

; inputs:
;     iy = pointer to a filinfo struct
;     hl = pointer to a fil struct
;     de = pointer to a zero-terminated filename
;     a  = (ps_media_type)
agm_play:
; verify valid .wav or .agm file
    cp media_type_agm ; a was set by play_song
    jp nz,ps_close_file

    call print_agm_header ; DEBUG

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
; set read_media_routine
    ld hl,agm_read_chunk
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
; set ps_mode_playing
    ld hl,ps_mode
    set ps_mode_playing,(hl)
; read the first segmment header
    call agm_read_segment_hdr
    jp z,ps_close_file
; read the first unit header
    call agm_read_unit_hdr
; enable interrupts, start the PRT timer, and jump to user input
    call ps_prt_start
    jp get_input
; fall through to agm_read_segment_hdr
; end agm_play

agm_read_segment_hdr:
; read the next segment header
    ld hl,ps_fil_struct
    ld bc,agm_segment_hdr_size ; bytes to read
    ld de,agm_segment_hdr   ; target address
    FFSCALL ffs_fread
; check for end of file
    push bc ; bytes read
    pop hl
    SIGN_HLU
; return to caller with zero flag set with eof status
    ret
; end agm_read_segment_hdr

agm_read_unit_hdr:
; read the unit header
    ld hl,ps_fil_struct
    ld bc,agm_unit_hdr_size ; bytes to read
    ld de,agm_unit_hdr   ; target address
    FFSCALL ffs_fread
; check unit type and clear appropriate buffer
    ld a,(agm_unit_hdr+agm_unit_mask)
    and a,agm_unit_type
    jr z,@audio
    ld hl,(pv_img_buffer)
    call vdu_clear_buffer
    ret
@audio:
    ld hl,(ps_dat_buffer)
    call vdu_clear_buffer
    ret
; end agm_read_unit_hdr

agm_read_chunk:
; first check whether it is time to play the next audio sample
    ld hl,pv_sample_counter
    dec (hl)
    call z,agm_play_sample
; next check whether it is time to draw the next video frame
    ld hl,pv_draw_counter
    dec (hl)
    call z,agm_draw_frame
; now determine whether the video or audio buffers have room for data
    ld hl,agm_unit_hdr+agm_unit_mask
    ld a,agm_unit_type
    and (hl)
    jr nz,@video
; audio:
    ld a,ps_loaded_samples_max
    ld hl,ps_loaded_samples
    cp a,(hl)
    ret z
    jr @read
@video:
    ld a,(pv_loaded_frames_max)
    ld hl,pv_loaded_frames
    cp a,(hl)
    ret z
@read: ; finally, read the chunk header
    ld hl,ps_fil_struct
    ld bc,agm_chunk_hdr_size ; bytes to read
    ld de,agm_chunk_hdr   ; target address
    FFSCALL ffs_fread
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
    ld hl,(pv_img_buffer) ; bufferId
    ld de,ps_agm_data ; source address
    call vdu_load_buffer
    jp get_input
; end agm_read_chunk

agm_next_unit:
    ; call agm_print_all_hdrs ; DEBUG
    ; call DEBUG_WAITKEYPRESS ; DEBUG
; check unit type
    ld hl,agm_unit_hdr+agm_unit_mask
    ld a,agm_unit_type
    and (hl)
    jr z,@audio
; is video unit so check compression type
    ld a,agm_unit_cmp_typ
    and (hl)
    jr z,@next_video_buffer
; decompress buffer
    ld hl,(pv_img_buffer) ; source bufferId
    ld de,(pv_img_buffer) ; target bufferId
    call vdu_decompress_buffer
@next_video_buffer: ; advance the video data buffer
    ld a,(pv_img_buffer) ; only need the low byte
    inc a
    ld hl,pv_loaded_frames_max
    cp a,(hl)
    jr nz,@not_max_frames
    xor a
@not_max_frames:
    ld (pv_img_buffer),a
; increment frames loaded
    ld hl,pv_loaded_frames
    inc (hl)
; read the next unit header and return to user input
    ; jp agm_read_unit_hdr
    call agm_read_unit_hdr
    jp get_input
@audio: ; advance the audio data buffer
    ld a,(ps_dat_buffer) ; only need the low byte
    inc a
    cp ps_loaded_samples_max
    jr nz,@not_max_samples
    xor a
@not_max_samples:
    ld (ps_dat_buffer),a
; clear the buffer
    ld hl,(ps_dat_buffer)
    call vdu_clear_buffer
; update pv_bytes_read
    ld hl,(pv_bytes_read)
    ld de,(agm_segment_size_this)
    add hl,de
    ld (pv_bytes_read),hl
    ; ld a,(pv_bytes_read+3)
    ; adc a,0
    ; ld (pv_bytes_read+3),a
; read the next segment header
    call agm_read_segment_hdr
    jp z,ps_close_file
; read the next unit header and return to user input
    ; jp agm_read_unit_hdr
    call agm_read_unit_hdr
    jp get_input
; end agm_next_unit

agm_play_sample:
    ; call agm_print_all_hdrs ; DEBUG
    ; call DEBUG_WAITKEYPRESS ; DEBUG
; reset the sample counter
    ld a,60
    ld (hl),a ; hl = pv_sample_counter, was set by agm_read_chunk
; check whether there is a full audio buffer
    ld a,(ps_loaded_samples)
    and a
    ret z ; no samples to play
; update the playbar counter and display the time elapsed
    call ps_update_playbar
; call the play sample command buffer
    ld hl,(ps_cmd_buffer)
    call vdu_call_buffer 
; increment the command buffer
    ld a,(ps_cmd_buffer) ; only need the low byte
    inc a
    cp ps_loaded_samples_max ; max buffers
    jr nz,@not_max
    xor a
@not_max:
    ld (ps_cmd_buffer),a ; only need to set the low byte
    ret 
; end agm_play_sample

agm_draw_frame:
    ; call agm_print_all_hdrs ; DEBUG
    ; call DEBUG_WAITKEYPRESS ; DEBUG
; reset the draw counter
    ld a,(pv_draw_counter_reset)
    ld (hl),a
; check whether enough frames are buffered
    ld hl,ps_wav_header+agm_frame_rate
    ld a,(pv_loaded_frames)
    cp a,(hl)
    ret m ; not enough frames
 ; decrement loaded frames
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
    jr nz,@not_max
    xor a
@not_max:
    ld (pv_cmd_buffer),a
    ret
; end agm_draw_frame

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
    ; dec de
    ; inc.s de ; clears ude
    ; ld hl,(screen_width)
    ; or a ; clear carry
    ; sbc hl,de
    ; call hlu_div2
    ; ld (@x),hl

    ld de,(ps_wav_header+agm_height)
    ld (@height),de
    ld a,1 ; format 1 = RGBA2222
    ld (@height+2),a
    ; dec de
    ; inc.s de ; clears ude
    ; ld hl,(screen_height)
    ; or a ; clear carry
    ; sbc hl,de
    ; call hlu_div2
    ; ld (@y),hl

    ld hl,pv_cmd_base_buffer
    ld a,(pv_loaded_frames_max)
    ld b,a
@load_cmd_loop:
    push bc ; save loop counter
    push hl ; save command bufferId
    ld a,l ; only need to load the low bytes of img bufferIds
    ld (@bufferId0),a 
    ld (@bufferId1),a 

    ld de,@cmd_start
    ld bc,@cmd_end-@cmd_start
    call vdu_load_buffer

    pop hl ; restore current command bufferId
    inc l ; bump bufferId
    pop bc ; restore loop counter
    djnz @load_cmd_loop

    ret 
@cmd_start:
    ; DB 7 ; BEEP DEBUG

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

; Command 2: Clear a buffer
; VDU 23, 0 &A0, bufferId; 2
            db 23,0,0xA0
@bufferId1: dw pv_img_base_buffer
           db 2 ; clear buffer
@cmd_end:   db 0x00 ; padding
; end pv_load_video_cmd_buffers

pv_load_audio_cmd_buffers:
    ld hl,ps_dat_base_buffer
    ld b,ps_loaded_samples_max
@clear_dat_loop:
    push bc ; save loop counter
    push hl ; save cmd buffer high byte and loop counter
    call vdu_clear_buffer
    pop hl
    inc l ; bump bufferId
    pop bc ; restore loop counter
    djnz @clear_dat_loop

    ld hl,ps_cmd_base_buffer
    ld b,ps_loaded_samples_max
@clear_cmd_loop:
    push bc ; save loop counter
    push hl ; save cmd buffer high byte and loop counter
    call vdu_clear_buffer
    pop hl
    inc l ; bump bufferId
    pop bc ; restore loop counter
    djnz @clear_cmd_loop

    ld hl,ps_cmd_base_buffer
    ld b,ps_loaded_samples_max
@load_cmd_loop:
    push bc ; save loop counter
    push hl ; save command bufferId
    ld a,l ; only need to load the low bytes of dat bufferIds
    ld (@bufferId0),a 
    ld (@bufferId1),a
    ld (@bufferId2),a
    ld (@bufferId3),a

    ld (@channel0),a
    ld (@channel1),a

    ld a,(ps_wav_header+wav_sample_rate)
    ld (@sample_rate),a
    ld a,(ps_wav_header+wav_sample_rate+1)
    ld (@sample_rate+1),a

    ld de,@cmd_start
    ld bc,@cmd_end-@cmd_start
    call vdu_load_buffer

; DEBUG
    call printNewLine
    ld hl,(@bufferId0)
    dec hl
    inc.s hl
    call printHex24

; END DEBUG

    pop hl ; restore current command bufferId
    inc l ; bump bufferId
    pop bc ; restore loop counter
    djnz @load_cmd_loop

    call printNewLine ; DEBUG
    
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
; vdu_play_sfx command string
; Command 4: Set waveform
; VDU 23, 0, &85, channel, 4, waveformOrSample, [bufferId;]
    db 23,0,$85 ; vdu sound command header  
@channel0: db 0 ; channel
    db 4 ; set waveform command
    db 8 ; waveform 8 = sample
@bufferId2: dw ps_dat_base_buffer ; sample bufferId
; Command 0: Play note
; VDU 23, 0, &85, channel, 0, volume, frequency; duration;
    db 23,0,$85 ; vdu sound command header
@channel1: db 0 ; channel
    db 0 ; play note command
    db 127  ; volume 127 = max
    dw 0 ; frequency (relevant only for tuneable samples)
    dw 0 ; duration (ms), zero means play one time in full

; Command 2: Clear a buffer
; VDU 23, 0 &A0, bufferId; 2
            db 23,0,0xA0
@bufferId3: dw ps_dat_base_buffer
           db 2 ; clear buffer
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
    ld hl,(ps_cmd_buffer)
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

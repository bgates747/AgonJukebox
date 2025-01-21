; stream a song from the SD card
; inputs: hl = pointer to filename
; requirements: the file must be 8-bit signed PCM mono
; uses: sound channels 0 and 1, buffers 0x3000 and 0x3001
; play_song constants
ch0_buffer: equ 0x3000
ch1_buffer: equ 0x3001
cmd0_buffer: equ 0x3002
cmd1_buffer: equ 0x3003

; ps_mode bits
ps_mode_playing: equ 0 ; 0 = paused 1 = playing, p key toggles
ps_mode_loop:    equ 1 ; 0 = no loop 1 = loop (overrides ps_mode_shuffle if on), l key toggles
ps_mode_shuffle: equ 2 ; 0 = shuffle off 1 = on, s key toggles

; play_song state variables
; current active channel and bufferId's
ps_mode: db 0 ; playback mode bitmask
ps_channel: db 0 ; channel number
ps_cmdId: dl 0 ; command bufferId
ps_sampleId: dl 0 ; sample bufferId
ps_chunkpointer: dl 0 ; pointer to current chunk
ps_playhead: dl 0 ; current playhead position in the song in seconds from the start
ps_song_duration: blkb 5,0 ; duration of the current song in seconds (32-bit word plus a padding byte)

play_song:
; stop the PRT timer and close any currently playing file
    call ps_close_file
    call ps_prt_stop
; tell the user what they've won
    call vp_now_playing
    call vdu_cls
    call printInline
    asciz "(P)laying "
    ld hl,ps_filinfo_fname
    call printString ; print the song filename
; highlight the song being played
    call ps_highlight_song
; open the file in read mode
; Open a file
; HLU: Filename
;   C: Mode
; Returns:
;   A: Filehandle, or 0 if couldn't open
    ld hl,ps_filinfo_fname
	ld c,fa_read
    MOSCALL mos_fopen
    ld (ps_filehandle),a
; read the .wav header data and copy it to the buffer
    call ps_read_wav_header
; compute the song duration from the file size and sample rate and print it
; technically we should account for the .wav header, but at 76 bytes it's negligible
    call vp_duration ; set viewport to duration window
    ld a,(ps_wav_header+wav_file_size+3) ; upper byte
    ld ix,(ps_wav_header+wav_file_size+0) ; lower word
    ld de,(ps_wav_header+wav_sample_rate)
    call udiv3223 ; auix = duration in seconds
    ld (ps_song_duration),ix ; duration low word
    ld (ps_song_duration+3),a ; duration high byte
    ld hl,(ps_song_duration) ; ls 24 bits of duration is sufficient and all we're prepared for
    call seconds_to_hhmmss ; hl pointer to string representation of HH:MM:SS
    call printString ; print the duration
; reset the playhead counter to zer0
    ld hl,0
    ld (ps_playhead),hl
; read the first block of data
    call ps_read_file
; set ps_mode_playing
    ld hl,ps_mode
    set ps_mode_playing,(hl)
; enable interrupts and start the PRT timer
    ei
    call ps_prt_start
; jump to user input loop:
; the play sample interrupt will return to there
; and exit app will return to main from there as well
    jp get_input
; end play_song

; read the next 1-second's worth of sound data from the file
; and upload it to the sample buffer
ps_read_file:
; disable interrupts so load is guaranteed to complete
    di
; Read a block of data from a file
;   C: Filehandle
; HLU: Pointer to where to write the data to
; DEU: Number of bytes to read
; Returns:
; DEU: Number of bytes read
    ld a,(ps_filehandle)
    ld c,a
    ld hl,ps_wav_data_start
    ld de,(ps_wav_header+wav_sample_rate)
    MOSCALL mos_fread
; test de for zero bytes read
    ld hl,0
    xor a ; clear carry
    sbc hl,de ; hl = 0-chunksize
    jp nz,@load ; we read some data
; no data read so close file and play a random song
    call ps_close_file
    jp ps_song_over
; load a vdu buffer from local memory
; inputs: hl = bufferId ; bc = length ; de = pointer to data
@load:
    ld a,(ps_channel)
    inc a
    and 1
    ld (ps_channel),a
    ld hl,ch0_buffer
    ld l,a
    ld (ps_sampleId),hl
    call vdu_clear_buffer
    ld hl,(ps_sampleId)
    push de ; chunksize
    pop bc ; how much data to load
    ld de,ps_wav_data_start ; pointer to data
    call vdu_load_buffer
; update the playhead counter and display the time elapsed
    call vp_elapsed
    ld hl,(ps_playhead)
    inc hl
    ld (ps_playhead),hl
    call seconds_to_hhmmss ; hl pointer to string representation of HH:MM:SS
    call printString ; print the playhead position
; print a playing breadcrumb
    call vp_playhead
    ld a,'.'
    rst.lil 10h
    ret
; end ps_read_file

; this is called by the PRT timer interrupt
ps_play_sample:
; call the command buffer to play the sound
    ld hl,(ps_sampleId)
    inc l
    inc l
    ld (ps_cmdId),hl ; TODO: perhaps not needed
    call vdu_call_buffer
; load the next chunk of data
    call ps_read_file
; reenable interrupts and return to the user input loop
    ei
    ret
; end ps_play_sample

; close the file
ps_close_file:
    call ps_prt_stop ; stop the PRT timer
    ld a,(ps_filehandle)
    MOSCALL mos_fclose
    ret
; end ps_close_file

ps_song_over:
; get playback mode
    ld hl,ps_mode

; are we in loop mode?
    bit ps_mode_loop,(hl)
    jp z,@F ; no so check next mode
    ld hl,ps_filinfo_fname ; get current song filename
    jp play_song ; and play it again, Sam

@@: ; are we in shuffle mode?
    bit ps_mode_shuffle,(hl)
    jp nz,ps_play_random ; yes so play a random song

; loop and shuffle are off so play next song
    jp ps_play_next_song
; end ps_song_over

ps_play_next_song:
    ld a,(bf_file_idx) ; get the current song index
@next_file:
    inc a ; increment the song index
    ld (@songIdx),a ; save the new song index
    call ps_get_song_fn_from_pg_idx ; hl points to file, carry set indicates success, a has file attribute
    jp c,@good_fname ; filename is valid
    ld a,-1 ; invalid filename means we went past the end of the list, so reset ...
    jp @next_file ; ... and try again

@good_fname:
    cp AM_DIR ; file attribute check for directory
    jp nz,@is_file ; not a directory so check for valid .wav file
    jp @next_file ; is a directory so try the next file

@is_file:
    ld a,(@songIdx) ; get the new song index
    ld (bf_file_idx),a ; save the new song index
    jp play_song
@songIdx: db 0
; end ps_play_next_song

ps_play_prev_song:
    ld a,(bf_file_idx) ; get the current song index
@prev_file:
    dec a ; decrement the song index
    ld (@songIdx),a ; save the new song index
    call ps_get_song_fn_from_pg_idx ; hl points to file, carry set indicates success, a has file attribute
    jp c,@good_fname ; filename is valid
    call ps_get_page_num_files ; invalid filename means we went past the beginning of the list,
    ld a,b ;  so reset ...
    jp @prev_file ; ... and try again

@good_fname:
    cp AM_DIR ; file attribute check for directory
    jp nz,@is_file ; not a directory so check for valid .wav file
    jp @prev_file ; is a directory so try the previous file

@is_file:
    ld a,(@songIdx) ; get the new song index
    ld (bf_file_idx),a ; save the new song index
    jp play_song

@songIdx: db 0
; end ps_play_prev_song

; queue a random song on the current page to play next
ps_play_random:
; back up current song index
    ld hl,ps_filinfo_fname
    ld (@songFn),hl
; get the number of songs in the current directory
    call ps_get_page_num_files
; get a random song index
    call rand_8 ; a = 0-255
    ld h,a
    ld l,10 ; modulo 10
    call udiv8 ; a = mod(a,10)
    call ps_get_song_fn_from_pg_idx
    ex de,hl ; setting up cp hl,de
    ld hl,(@songFn) ; don't play the same song twice in a row
    or a ; clear carry
    sbc hl,de
    jp z,ps_play_random ; same song, try again
    ex de,hl ; pointer back to hl
    jp play_song ; hit it
@songFn: dl 0
; end ps_play_random

ps_read_wav_header:
    ld a,(ps_filehandle)
    ld hl,ps_wav_header
    call jb_read_wav_header
    call nz,ps_load_command_buffers
    ret
; end ps_read_wav_header
bf_read_wav_header:
    ld a,(bf_filehandle)
    ld hl,bf_wav_header
; determine whether a file is a playable .wav file
; inputs: a = filhandle of the file to check, hl = pointer to the file's header
; prerequisites: file must be open for reading, and its read head at the beginning of its data
; returns: zero flag set if not a valid .wav file (or is a directory)
jb_read_wav_header:
; Read a block of data from a file
;   C: Filehandle
; HLU: Pointer to where to write the data to
; DEU: Number of bytes to read
; Returns:
; DEU: Number of bytes read
    ld c,a
    ld de,wav_header_size
    MOSCALL mos_fread
; test de for zero bytes read
    ld hl,0
    xor a ; clear carry
    sbc hl,de ; hl = 0-chunksize
    ret z ; no data read so return zero to caller
; test for valid .wav header
    call verify_wav
    jp z,@F ; valid .wav header so continue
    xor a ; invalid .wav header so return zero to caller
    ret
@@: ; valid .wav header
    xor a
    inc a ; reset zero flag indicating valid .wav file
    ret
; end ps_read_wav_header
; end bf_read_wav_header

ps_load_command_buffers:
    ld hl,cmd0_buffer
    call vdu_clear_buffer
    ld hl,(ps_wav_header+wav_sample_rate)
    ld (ps_sr0),hl
    ld a,23
    ld (ps_sr0+2),a
    ld hl,cmd0_buffer
    ld bc,ps_cmd0_end-ps_cmd0
    ld de,ps_cmd0
    call vdu_write_block_to_buffer

    ld hl,cmd1_buffer
    call vdu_clear_buffer
    ld hl,(ps_wav_header+wav_sample_rate)
    ld (ps_sr1),hl
    ld a,23
    ld (ps_sr1+2),a
    ld hl,cmd1_buffer
    ld bc,ps_cmd1_end-ps_cmd1
    ld de,ps_cmd1
    call vdu_write_block_to_buffer
    ret
ps_cmd0:
; vdu_buffer_to_sound command string
; Command 5: Buffer to sound
; VDU 23, 0, &85, channel (ignored), 5, 2, bufferId; format, [sampleRate;]
    db 23,0,0x85 ; vdu sound command header
    db 0x00 ; channel (ignored)
    db 0x05 ; buffer to sound command
    db 0x02 ; command 2 create sample
    dw ch0_buffer
    db 1+8 ; 8-bit unsigned PCM mono, 8 = sample rate argument follows
ps_sr0:
    dw 0x0000 ; sample rate Hz
; vdu_play_sfx command string
; Command 4: Set waveform
; VDU 23, 0, &85, channel, 4, waveformOrSample, [bufferId;]
    db 23,0,$85 ; vdu sound command header  
    db 0 ; channel
    db 4 ; set waveform command
    db 8 ; waveform 8 = sample
    dw ch0_buffer ; sample bufferId
; Command 0: Play note
; VDU 23, 0, &85, channel, 0, volume, frequency; duration;
    db 23,0,$85 ; vdu sound command header
    db 0 ; channel
    db 0 ; play note command
    db 127  ; volume 127 = max
    dw 0 ; frequency (relevant only for tuneable samples)
    dw 0 ; duration (ms), zero means play one time in full
ps_cmd0_end:

ps_cmd1:
; vdu_buffer_to_sound command string
; Command 5: Buffer to sound
; VDU 23, 0, &85, channel (ignored), 5, 2, bufferId; format, [sampleRate;]
    db 23,0,0x85 ; vdu sound command header
    db 0x00 ; channel (ignored)
    db 0x05 ; buffer to sound command
    db 0x02 ; command 2 create sample
    dw ch1_buffer
    db 1+8 ; 8-bit unsigned PCM mono, 8 = sample rate argument follows    
ps_sr1:
    dw 0x0000 ; sample rate Hz
; vdu_play_sfx command string
; Command 4: Set waveform
; VDU 23, 0, &85, channel, 4, waveformOrSample, [bufferId;]
    db 23,0,$85 ; vdu sound command header  
    db 1 ; channel
    db 4 ; set waveform command
    db 8 ; waveform 8 = sample
    dw ch1_buffer ; sample bufferId
; Command 0: Play note
; VDU 23, 0, &85, channel, 0, volume, frequency; duration;
    db 23,0,$85 ; vdu sound command header
    db 1 ; channel
    db 0 ; play note command
    db 127  ; volume 127 = max
    dw 0 ; frequency (relevant only for tuneable samples)
    dw 0 ; duration (ms), zero means play one time in full
ps_cmd1_end:
; end ps_load_command_buffers
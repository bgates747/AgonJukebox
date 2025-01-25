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
ps_playhead: dw32 0 ; current playhead position in seconds from the start (32-bit integer)
ps_song_duration: blkb 5,0 ; duration of the current song in seconds (32-bit integer plus a padding byte)
ps_seek_rate: dw32 1 ; seek rate in seconds per keypress (32-bit integer)
ps_seek_rate_idx: db 0 ; seek rate index
    db 1,5,10,15,30,60,120,240 ; seek rates in seconds per keypress

play_song:
; stop the PRT timer and close any currently playing file
    call ps_close_file ; also stops prt timer

; clear now playing viewport
    call vp_now_playing
    call vdu_cls

; open the file and verify it's a playable .wav file
    call open_wav
    jp z,@F ; valid .wav file so continue
    call printInline
    asciz "Invalid .wav file selected, try again."
    jp get_input ; return to user input loop

@@: ; copy the directory filinfo struct to ps_filinfo_struct
    lea hl,iy ; open_wav set iy to the directory's filinfo struct
    ld de,ps_filinfo_struct ; destination address
    ld bc,filinfo_struct_size
    ldir

; tell the user what they've won
    call printInline
    asciz "(P)laying "
    ld hl,ps_filinfo_fname
    call printString ; print the song filename

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
; reset the playbar counter to zero
    ld hl,0
    ld (ps_playhead),hl
; load the command buffers and read the first block of data
    call ps_load_command_buffers
    call ps_read_sample
; set ps_mode_playing
    ld hl,ps_mode
    set ps_mode_playing,(hl)
; enable interrupts and start the PRT timer
    call ps_prt_start
; jump to user input loop (enables interrupts)
; the play sample interrupt will return to there
; and exit app will return to main from there as well
    jp get_input
; end play_song

; read the next 1-second's worth of sound data from the file
; and upload it to the sample buffer
ps_read_sample:
; disable interrupts so load is guaranteed to complete
    di

; 0x82: ffs_fread
; Read from a file (Requires MOS 1.03 or above)
; Parameters:
; HL(U): Pointer to a FIL structure
; DE(U): Pointer to a buffer to store the data in
; BC(U): Number of bytes to read (typically the size of the buffer)
; Preserves: HL(U), DE(U)
; Returns:
; BC(U): Number of bytes read
; A: FRESULT
    ld hl,ps_fil_struct
    ld de,ps_wav_data
    ld bc,(ps_wav_header+wav_sample_rate)
    FFSCALL ffs_fread

; test bc for zero bytes read
    ld hl,0
    xor a ; clear carry
    sbc hl,bc ; hl = 0-chunksize
    jp nz,@load ; we read some data

; no data read so close file and play next song
    call ps_close_file
    jp ps_song_over

; load a vdu buffer from local memory
; inputs: hl = bufferId ; bc = length ; de = pointer to data
@load:
    push bc ; save how much data to load
    ld a,(ps_channel)
    inc a
    and 1
    ld (ps_channel),a
    ld hl,ch0_buffer
    ld l,a
    ld (ps_sampleId),hl
    call vdu_clear_buffer
    ld hl,(ps_sampleId)
    pop bc ; restore how much data to load
    ld de,ps_wav_data ; pointer to data
    call vdu_load_buffer
; update the playbar counter and display the time elapsed
    call ps_update_playbar

; ; DEBUG
;     call vp_messages
;     call vdu_cls
;     ld ix,ps_fil_fptr
;     call fetch_int_nor
;     call print_float_dec
; ; END DEBUG

    ret
; end ps_read_sample
ps_update_playbar:
; set viewport to playbar
    call vp_elapsed
; increment the playbar counter
    ld hl,(ps_playhead)
    inc hl
    ld (ps_playhead),hl
; convert the playbar counter to HH:MM:SS and print it
    call seconds_to_hhmmss ; hl pointer to string representation of HH:MM:SS
    call printString ; print the playhead position

; print a playing breadcrumb
    call vp_playbar
    call vdu_cls

    ld hl,[vp_playbar_right-vp_playbar_left]*256 ; leave room for cursor
    ld de,(ps_song_duration) ; ls 24-bits is sufficient and all we're prepared for
    call udiv168 ; de = breadcrumbs / second in 8.16 fixed point

    ld hl,(ps_playhead)
    call umul24 ; uhl is the breadcrumb position
    HLU_TO_A ; a = breadcrumb position
    and a
    jp z,@done ; if zero, we're done
    ld b,a
@loop:
    ld a,'.'
    rst.lil 10h
    djnz @loop
@done:
    ld a,219 ; cursor
    rst.lil 10h
    ret
; end ps_update_playbar

; this is called by the PRT timer interrupt
ps_play_sample:
; call the command buffer to play the sound
    ld hl,(ps_sampleId)
    inc l
    inc l
    ld (ps_cmdId),hl ; TODO: perhaps not needed
    call vdu_call_buffer
; load the next chunk of data
    call ps_read_sample
; return to the interrupt handler
    ret
; end ps_play_sample

; close the file
ps_close_file:
    call ps_prt_stop ; stop the PRT timer
; 0x81: ffs_fclose
; Close a file (Requires MOS 1.03 or above)
; Parameters:
; HL(U): Pointer to a FIL structure
; Preserves: HL(U)
; Returns:
; A: FRESULT
    ld hl,ps_fil_struct
    FFSCALL ffs_fclose
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
    ld a,(bf_files_cur_pg)
    or a ; check for zero files
    jp z,get_input ; no files to play so return to user input loop
    ld b,a ; loop counter
@next_file:
    push bc ; save loop counter
    call get_next_file_idx ; (bf_file_idx)++ with wraparound
    call bf_get_filinfo_from_pg_idx ; iy points to filinfo struct
    call bf_check_dir_or_file ; if zero then it's a song
    pop bc ; restore loop counter
    jp z,@play_song ; is a file so play song
    djnz @next_file ; try the next file
    jp get_input ; no files in this directory so return to user input loop
@play_song:
    call bf_highlight_file ; highlight the selected file
    jp play_song
; end ps_play_next_song

ps_play_prev_song:
    ld a,(bf_files_cur_pg)
    or a ; check for zero files
    jp z,get_input ; no files to play so return to user input loop
    ld b,a ; loop counter
@next_file:
    push bc ; save loop counter
    call get_next_file_idx ; (bf_file_idx)++ with wraparound
    call bf_get_filinfo_from_pg_idx ; iy points to filinfo struct
    call bf_check_dir_or_file ; if zero then it's a song
    pop bc ; restore loop counter
    jp z,@play_song ; is a file so play song
    djnz @next_file ; try the next file
    jp get_input ; no files in this directory so return to user input loop
@play_song:
    call bf_highlight_file ; highlight the selected file
    jp play_song
; end ps_play_prev_song

; queue a random song on the current page to play next
ps_play_random:
    ld a,(bf_files_cur_pg)
    or a ; check for zero files
    jp z,get_input ; no files to play so return to user input loop
    ld b,a ; loop counter
    ld a,(bf_file_idx) ; save current song index
    ld (@file_idx),a
@next_file:
    push bc ; save loop counter
    call get_rand_file_idx ; a->(bf_file_idx)
    ld hl,@file_idx
    cp (hl) ; check for same song
    jp z,@same ; same song so try again
    call bf_get_filinfo_from_pg_idx ; iy points to filinfo struct
    call bf_check_dir_or_file ; if zero then it's a song
@bump_counter:
    pop bc ; restore loop counter
    jp z,@play_song ; is a file so play song
    djnz @next_file ; try the next file
    jp get_input ; no files in this directory so return to user input loop
@same:
    or a,1 ; reset zero flag
    jp @bump_counter
@play_song:
    call bf_highlight_file ; highlight the selected file
    jp play_song
@file_idx: db 0
; end ps_play_random

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
; stream a song from the SD card
; inputs: hl = pointer to filename
; requirements: the file must be 8-bit signed PCM mono
; uses: sound channels 0 and 1, buffers 0x3000 and 0x3001
ch0_buffer: equ 0x3000
ch1_buffer: equ 0x3001
cmd0_buffer: equ 0x3002
cmd1_buffer: equ 0x3003
ps_song_fn_cur: dl 0 ; pointer to current song filename
play_song:
    ld (ps_song_fn_cur),hl
; stop the PRT timer
    call ps_prt_stop
; tell the user what they've won
    ld c,0 ; left
    ld d,0 ; top
    ld e,62 ; right
    ld b,1; bottom
    call vdu_set_txt_viewport
    call vdu_cls
    ld hl,(ps_song_fn_cur)
    call printInline
    asciz "Playing song: "
    ld hl,(ps_song_fn_cur)
    call printString ; print the song filename
; reset text viewport for playing breadcrumbs
    ld c,0 ; left
    ld d,1 ; top
    ld e,62 ; right
    ld b,1; bottom
    call vdu_set_txt_viewport
; open the file in read mode
; Open a file
; HLU: Filename
;   C: Mode
; Returns:
;   A: Filehandle, or 0 if couldn't open
    ld hl,(ps_song_fn_cur)
	ld c,fa_read
    MOSCALL mos_fopen
    ld (ps_filehandle_cur),a
; read the .wav header data and copy it to the buffer
    call ps_read_wav_header
; read the first block of data
    call ps_read_file
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
; print a playing breadcrumb
    ld a,'.'
    rst.lil 10h
; Read a block of data from a file
;   C: Filehandle
; HLU: Pointer to where to write the data to
; DEU: Number of bytes to read
; Returns:
; DEU: Number of bytes read
    ld a,(ps_filehandle_cur)
    ld c,a
    ld hl,ps_wav_data_start
    ld de,(ps_wav_sample_rate)
    MOSCALL mos_fread
; test de for zero bytes read
    ld hl,0
    xor a ; clear carry
    sbc hl,de ; hl = 0-chunksize
    jp nz,@load ; we read some data
; no data read so close file and play a random song
    call ps_close_file
    jp ps_play_random 
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
    ld a,(ps_filehandle_cur)
    MOSCALL mos_fclose
    ret
; end ps_close_file

; queue a random song to play next
ps_play_random:
    call rand_8 ; a = 0-255
    and 7 ; mod 8
    ld d,a
    ld e,3 ; three bytes per filename index
    mlt de ; index into the filename table
    ld hl,SFX_filename_index
    add hl,de ; hl points to the filename index
    ld hl,(hl) ; hl points to the filename
    ex de,hl ; setting up cp hl,de
    ld hl,(ps_song_fn_cur) ; don't play the same song twice in a row
    or a ; clear carry
    sbc hl,de
    jp z,ps_play_random ; same song, try again
    ex de,hl ; pointer back to hl
    call play_song ; hit it
    ret
; end ps_play_random

ps_read_wav_header:
; Read a block of data from a file
;   C: Filehandle
; HLU: Pointer to where to write the data to
; DEU: Number of bytes to read
; Returns:
; DEU: Number of bytes read
    ld a,(ps_filehandle_cur)
    ld c,a
    ld hl,ps_wav_header
    ld de,wav_header_size
    MOSCALL mos_fread
; test de for zero bytes read
    ld hl,0
    xor a ; clear carry
    sbc hl,de ; hl = 0-chunksize
    ret z ; no data read so return zero to caller
; data read so initialize song variables
; load play sample command buffers (namely the sample rate for now)
    call load_command_buffers
    ret
; end ps_read_wav_header

; current active channel and bufferId's
ps_channel: db 0 ; channel number
ps_cmdId: dl 0 ; command bufferId
ps_sampleId: dl 0 ; sample bufferId

; end play_song

load_command_buffers:
    ld hl,cmd0_buffer
    call vdu_clear_buffer
    ld hl,(ps_wav_sample_rate)
    ld (ps_sr0),hl
    ld a,23
    ld (ps_sr0+2),a
    ld hl,cmd0_buffer
    ld bc,ps_cmd0_end-ps_cmd0
    ld de,ps_cmd0
    call vdu_write_block_to_buffer

    ld hl,cmd1_buffer
    call vdu_clear_buffer
    ld hl,(ps_wav_sample_rate)
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
; end load_command_buffers


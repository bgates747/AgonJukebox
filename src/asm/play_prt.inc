; stream a song from the SD card
; inputs: hl = pointer to filename
; requirements: the file must be 8-bit signed PCM mono
; uses: sound channels 0 and 1, buffers 0x3000 and 0x3001
ch0_buffer: equ 0x3000
ch1_buffer: equ 0x3001
cmd0_buffer: equ 0x3002
cmd1_buffer: equ 0x3003
current_song: dl 0 ; pointer to current song filename
play_song:
; stop the PRT timer
    call ps_prt_stop

; tell the user what they've won
    ld (current_song),hl
    call printInline
    asciz "Playing song: "
    ld hl,(current_song)
    call printString ; print the song filename
    call printNewLine

; open the file in read mode
; Open a file
; HLU: Filename
;   C: Mode
; Returns:
;   A: Filehandle, or 0 if couldn't open
    ld hl,(current_song)
	ld c,fa_read
    MOSCALL mos_fopen
    ld (ps_filehandle),a

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
; DEBUG
    ld a,'.'
    rst.lil 10h
; END DEBUG
; Read a block of data from a file
;   C: Filehandle
; HLU: Pointer to where to write the data to
; DEU: Number of bytes to read
; Returns:
; DEU: Number of bytes read
    ld a,(ps_filehandle)
    ld c,a
    ld hl,song_data
    ld de,sample_rate
    MOSCALL mos_fread

; test de for zero bytes read
    ld hl,0
    xor a ; clear carry
    sbc hl,de ; hl = 0-chunksize
    jp nz,@load ; we read some data
    call ps_close_file
    jp ps_play_random ; no data, play a random song

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
    ld de,song_data ; pointer to data
    call vdu_load_buffer

; call the command buffer to play the sound
    ld hl,(ps_sampleId)
    inc l
    inc l
    ld (ps_cmdId),hl ; TODO: perhaps not needed
    call vdu_call_buffer

; reenable interrupts and return to the user input loop
    ei
    ret
; end ps_read_file

; close the file
ps_close_file:
    call ps_prt_stop ; stop the PRT timer
    ld a,(ps_filehandle)
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
    ld hl,(current_song) ; don't play the same song twice in a row
    or a ; clear carry
    sbc hl,de
    jp z,ps_play_random ; same song, try again
    ex de,hl ; pointer back to hl
    call play_song ; hit it
    ret
; end ps_play_random

; current active channel and bufferId's
ps_channel: db 0 ; channel number
ps_cmdId: dl 0 ; command bufferId
ps_sampleId: dl 0 ; sample bufferId

; song file info
ps_filehandle: db 0 ; file handle
ps_fil: dl 0 ; pointer to FIL struct
ps_chunkpointer: dl 0 ; pointer to current chunk
; File information structure (FILINFO)
ps_filinfo:
ps_filinfo_fsize:    blkb 4, 0   ; File size (4 bytes)
ps_filinfo_fdate:    blkb 2, 0   ; Modified date (2 bytes)
ps_filinfo_ftime:    blkb 2, 0   ; Modified time (2 bytes)
ps_filinfo_fattrib:  blkb 1, 0   ; File attribute (1 byte)
ps_filinfo_altname:  blkb 13, 0  ; Alternative file name (13 bytes)
ps_filinfo_fname:    blkb 256, 0 ; Primary file name (256 bytes)
; end play_song

load_command_buffer:
    ld hl,cmd0_buffer
    call vdu_clear_buffer
    ld hl,cmd0_buffer
    ld bc,ps_cmd0_end-ps_cmd0
    ld de,ps_cmd0
    call vdu_write_block_to_buffer

    ld hl,cmd1_buffer
    call vdu_clear_buffer
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
    db 0+8 ; 0 = 8-bit signed PCM mono, 8 = sample rate argument follows
    dw sample_rate ; Hz
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
    db 0+8 ; 0 = 8-bit signed PCM mono, 8 = sample rate argument follows
    dw sample_rate ; Hz
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


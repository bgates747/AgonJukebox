; stream a song from the SD card
; inputs: hl = pointer to filename
; requirements: the file must be 8-bit signed PCM mono
; uses: sound channels 0 and 1, buffers 0x3000 and 0x3001
; play_song constants
ch0_buffer: equ 0x3000
ch1_buffer: equ 0x3001
cmd0_buffer: equ 0x3002
cmd1_buffer: equ 0x3003

; play_song state variables
; current active channel and bufferId's
ps_channel: db 0 ; channel number
ps_cmdId: dl 0 ; command bufferId
ps_sampleId: dl 0 ; sample bufferId
ps_dir_path:   blkw 256,0 ; path of the current directory
ps_dir_num_files: dl 0 ; number of files/directories in the directory (virtually unlimited)
ps_page_num_files: dl 0 ; number of files/directories in the current directory page (max 10)
ps_page_cur: dl 0 ; current directory page number
ps_song_idx_cur: db 0 ; current song index in the directory page
ps_song_fn_cur: dl 0 ; pointer to current song filename

; play_song directory info
ps_dir_struct:             
ps_dptr:       blkb  4,0   ; Current read/write offset
ps_clust:      blkb  4,0   ; Current cluster
ps_sect:       blkb  4,0   ; Current sector (0:Read operation has terminated)
ps_dir:        blkb  3,0   ; Pointer to the directory item in the win[]
ps_fn:         blkb  12,0  ; SFN (in/out) {body[8],ext[3],status[1]}
ps_blk_ofs:    blkb  4,0   ; Offset of current entry block being processed (0xFFFFFFFF:Invalid)

; play_song file info
ps_filehandle_cur: db 0 ; file handle
ps_chunkpointer: dl 0 ; pointer to current chunk
; File information structure (FILINFO)
ps_filinfo_struct:
ps_filinfo_fsize:    blkb 4, 0   ; File size (4 bytes)
ps_filinfo_fdate:    blkb 2, 0   ; Modified date (2 bytes)
ps_filinfo_ftime:    blkb 2, 0   ; Modified time (2 bytes)
ps_filinfo_fattrib:  blkb 1, 0   ; File attribute (1 byte)
ps_filinfo_altname:  blkb 13, 0  ; Alternative file name (13 bytes)
ps_filinfo_fname:    blkb 256, 0 ; Primary file name (256 bytes)

; buffer for play_song sound data
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
    ld hl,0 ; clear hlu and h
    ld l,a
    ld de,(ps_dir_num_files)
    call udiv24 ; hl = mod(hl,num_files)
    ld de,256 ; 256 bytes per filename record
    call umul24 ; hl = index into the filename table
    ld de,ps_dir_fil_list
    add hl,de ; hl points to the filename
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
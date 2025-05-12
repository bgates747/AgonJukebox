    filedata: equ 0xB7E000 ; address of onboard 8k sram

; AGON Piano Roll (.apr) Header Structure Offsets and Descriptions
; The first 76 bytes are the size and layout of a standard .wav header
    apr_magic:         EQU 0    ; 6 bytes: "AGNPNR" identifier
    apr_version:       EQU 6    ; 1 byte: File format version

    apr_header_size:   EQU 144     ; Total .apr Header size

; WAV File Structure Offsets and Descriptions
    pp_wav_riff:          EQU 0    ; 4 bytes: "RIFF" identifier
    pp_wav_file_size:     EQU 4    ; 4 bytes: Total file size minus 8 bytes for RIFF header
    pp_wav_wave:          EQU 8    ; 4 bytes: "WAVE" identifier
    pp_wav_fmt_marker:    EQU 12   ; 4 bytes: "fmt " subchunk marker for .wav, "agm" for .agm
    pp_wav_fmt_size:      EQU 16   ; 4 bytes: Format chunk size (16 for PCM)
    pp_wav_audio_format:  EQU 20   ; 2 bytes: Audio format (1 = PCM)
    pp_wav_num_channels:  EQU 22   ; 2 bytes: Number of channels (1 = mono, 2 = stereo)
    pp_wav_sample_rate:   EQU 24   ; 4 bytes: Sample rate in Hz (e.g., 32768)
    pp_wav_byte_rate:     EQU 28   ; 4 bytes: Bytes per second (SampleRate * NumChannels * BitsPerSample / 8)
    pp_wav_block_align:   EQU 32   ; 2 bytes: Bytes per sample block (NumChannels * BitsPerSample / 8)
    pp_wav_bits_per_sample: EQU 34 ; 2 bytes: Bits per sample (e.g., 8 or 16)
    pp_wav_data_marker:   EQU 36   ; 4 bytes: "data" subchunk marker
    pp_wav_data_size:     EQU 40   ; 4 bytes: Size of the audio data in bytes
    pp_wav_data_start:    EQU 44   ; Start of audio data
    pp_wav_header_size:   EQU pp_wav_data_start ; Total Header Size: 76 bytes


    pp_fil_struct: equ 0x090000 ; 
    pp_fil_obj: equ 0x090000 ; 15 bytes: Object identifier
    pp_fil_flag: equ 0x09000F ; 1 bytes: File status flags
    pp_fil_err: equ 0x090010 ; 1 bytes: Abort flag (error code)
    pp_fil_fptr: equ 0x090011 ; 4 bytes: File read/write pointer (Zeroed on file open)
    pp_fil_clust: equ 0x090015 ; 4 bytes: Current cluster of fpter (invalid when fptr is 0)
    pp_fil_sect: equ 0x090019 ; 4 bytes: Sector number appearing in buf[] (0
    pp_fil_dir_sect: equ 0x09001D ; 4 bytes: Sector number containing the directory entry
    pp_fil_dir_ptr: equ 0x090021 ; 3 bytes: Pointer to the directory entry in the win[]

    pp_filinfo_struct: equ 0x090100 ; 
    pp_filinfo_fsize: equ 0x090100 ; 4 bytes: File size
    pp_filinfo_fdate: equ 0x090104 ; 2 bytes: Modified date
    pp_filinfo_ftime: equ 0x090106 ; 2 bytes: Modified time
    pp_filinfo_fattrib: equ 0x090108 ; 1 bytes: File attribute
    pp_filinfo_altname: equ 0x090109 ; 13 bytes: Alternative file name
    pp_filinfo_fname: equ 0x090116 ; 256 bytes: Primary file name

    pp_wav_header: equ 0x090300 ; 76 bytes: piano player sample .wav file header
    pp_wav_data: equ 0x09034C ; virtually unlimited bytes: 


    pp_apr_header: equ 0x09034C ; 144 bytes: 
    pp_apr_data: equ 0x0903DC ; virtually unlimited bytes: 

    pp_max_chunk_size: equ 32768 ; max size of a chunk

    note_counter: dl 0

; Format of each note record:
    tnext_lo:    equ 0     ; 1 byte. Time to next note in ms (low byte)
    tnext_hi:    equ 1     ; 1 byte. Time to next note in ms (high byte)
    duration_lo: equ 2     ; 1 byte. Note duration in ms (low byte)
    duration_hi: equ 3     ; 1 byte. Note duration in ms (high byte)
    pitch:       equ 4     ; 1 byte. MIDI pitch value (0–127)
    velocity:    equ 5     ; 1 byte. Note velocity (0–127)
    instrument:  equ 6     ; 1 byte. Instrument number (1–255)
    channel:     equ 7     ; 1 byte. Channel number (0-31)
    bytes_per_note: equ 8

play_note:
; ; stop the timer
;     call prt_stop
; reset the note counter
    ld l,(iy+tnext_lo) ; low byte
    ld h,(iy+tnext_hi) ; high byte
    ld (note_counter),hl ; set the note counter

; play the note
    ld a,(iy+channel)
    ld (@channel0),a
    ld (@channel1),a
    ld (@channel2),a
    ld (@channel3),a

    ld a,(iy+duration_lo)
    ld (@duration),a
    ld a,(iy+duration_hi) 
    ld (@duration+1),a

    ld a,(iy+pitch)
    ld (@bufferId),a

    ld a,(iy+velocity)
    ld (@volume),a 

    ld a,(pp_wav_header+pp_wav_sample_rate)
    ld (@sampleRate),a
    ld a,(pp_wav_header+pp_wav_sample_rate+1)
    ld (@sampleRate+1),a

    ld hl,@cmd0
    ld bc, @end-@cmd0
    rst.lil $18
    jr @end+1
; set volume to zero to stop any current note playing on channel
; Command 2: Set volume
; VDU 23, 0, &85, channel, 2, volume
    @cmd0:       db 23,0,0x85
    @channel0:   db 0x00
                 db 2    ; set volume command
                 db 0x00 ; volume (mute)
; set waveform command
                 db 23,0,0x85
    @channel1:   db 0x00
                 db 4    ; set waveform command
                 db 8    ; waveform type: sample
    @bufferId:   dw 0x0000
; set sample rate command
                 db 23,0,0x85
    @channel2:   db 0x00
                 db 13 ; set sample rate command
    @sampleRate: dw 0x0000
; play note command
                 db 23,0,0x85
    @channel3:   db 0x00
                 db 0x00 ; play note command
    @volume:     db 0x00
                 dw 0x0000 ; frequency: no effect unless buffer has been set to tuneable sample
    @duration:   dw 0x0000 ; milliseconds: set to -1 to loop indefinitely, 0 to play full duration once
    @end:        db 0x00 ; padding

    lea iy,iy+bytes_per_note ; move to next note

; ; restart the timer
;     call prt_start

    ret

pp_load_sample:
    push hl ; save the bufferId
; 0x80: ffs_fopen
; Parameters:
;     HL(U): Pointer to an empty FIL structure
;     DE(U): Pointer to a C (zero-terminated) filename string
;     C: File open mode
    ld hl,pp_fil_struct
    ld c,fa_read | fa_open_existing
    FFSCALL ffs_fopen

    ld iy,pp_wav_header ; point to the wav header
; clear the target buffer
    call vdu_clear_buffer
; read the .wav header
    ld hl,pp_fil_struct
    ld de,pp_wav_header
    ld bc,pp_wav_header_size
    FFSCALL ffs_fread
@read_loop:
; read the next chunk of sound data from the file
    ld hl,(iy+pp_wav_data_size)
    ld bc,pp_max_chunk_size ; max size of a chunk
    or a ; clear carry
    sbc hl,bc ; subtract max chunk size from the remaining bytes
    ld (iy+pp_wav_data_size),hl ; save remaining bytes to read
    jp p,@read_chunk ; if positive, read the chunk
    ld bc,pp_max_chunk_size ; max size of a chunk
    add hl,bc ; hl is remaining bytes to read
    push hl
    pop bc ; bc = bytes to read
@read_chunk:
    ld hl,pp_fil_struct
    ld de,pp_wav_data
    FFSCALL ffs_fread
; load a vdu buffer from local memory
; inputs: hl = bufferId ; bc = length ; de = pointer to data
; load the chunk to the current sample buffer
    pop hl ; pop the bufferId
    push hl ; and put it right back
    ld de,pp_wav_data ; pointer to data
    call vdu_load_buffer
    ld hl,(iy+pp_wav_data_size)
    SIGN_UHL
    jr z,@make_sample
    jr nc,@read_loop ; read the next chunk
@make_sample:
    pop hl ; pop the bufferId
    ld de,(iy+pp_wav_sample_rate)
    ld a,1 ; unsigned 8-bit PCM
    call vdu_buffer_to_sound
; close the file
    ld hl,pp_fil_struct
    FFSCALL ffs_fclose
    ret
; end pp_read_sample
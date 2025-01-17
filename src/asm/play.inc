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
ps_dir_path:   blkb 256,0 ; path of the current directory
ps_dir_num_files: dl 0 ; number of files/directories in the directory (virtually unlimited)
ps_dir_num_pages: dl 0 ; number of pages in the directory (virtually unlimited)
ps_page_num_files: dl 0 ; number of files/directories in the current directory page (max 10)
ps_pagelast_num_files: dl 0 ; mod(ps_dir_num_files,10)
ps_page_cur: dl 0 ; current directory page number
ps_song_idx_cur: db 0 ; current song index in the directory page
ps_song_fn_cur: dl 0 ; pointer to current song filename
ps_song_duration: blkw 5,0 ; duration of the current song in seconds (32-bit word plus a padding byte)
ps_playhead: dl 0 ; current playhead position in the song in seconds from the start
ps_page_fn_ptrs: blkw 10*3,0 ; list of filename pointers in the current directory page

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
ps_file_struct:
ps_file_fsize:    blkb 4, 0   ; File size (4 bytes)
ps_file_fdate:    blkb 2, 0   ; Modified date (2 bytes)
ps_file_ftime:    blkb 2, 0   ; Modified time (2 bytes)
ps_file_fattrib:  blkb 1, 0   ; File attribute (1 byte)
ps_file_altname:  blkb 13, 0  ; Alternative file name (13 bytes)
ps_file_fname:    blkb 256, 0 ; Primary file name (256 bytes)

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
; save pointer to requested song file
    ld (ps_song_fn_cur),hl
; stop the PRT timer and close any currently playing file
    call ps_close_file
    call ps_prt_stop
; tell the user what they've won
    call vp_now_playing
    call vdu_cls
    ld hl,(ps_song_fn_cur)
    call printInline
    asciz "(P)laying "
    ld hl,(ps_song_fn_cur)
    call printString ; print the song filename
; highlight the song being played
    call ps_highlight_song
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
; compute the song duration from the file size and sample rate and print it
; technically we should account for the .wav header, but at 76 bytes it's negligible
    call vp_duration ; set viewport to duration window
    ld a,(ps_wav_file_size+3) ; upper byte
    ld ix,(ps_wav_file_size+0) ; lower word
    ld de,(ps_wav_sample_rate)
    call udiv3223 ; auix = duration in seconds
    ld (ps_song_duration),ix ; duration low word
    ld (ps_song_duration+3),a ; duration high word
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
    ld a,(ps_filehandle_cur)
    MOSCALL mos_fclose
    ret
; end ps_close_file

ps_get_dir:
; set text viewport to directory name and clear it
    call vp_dir_name
    call vdu_cls
; reset filecounter
    ld hl,0
    ld (ps_dir_num_files),hl
; reset the song index and page number to 0
    xor a
    ld (ps_song_idx_cur),a
    ld hl,0
    ld (ps_page_cur),hl
; initialize pointers to store directory info and print directory name
    ld hl,ps_dir_path  ; where to store result
; note: setting bc has no apparent effect, but we leave it for consistency with docs
; https://agonconsole8.github.io/agon-docs/MOS-API/#0x9e-ffs_getcwd
    ld bc,255          ; max length (final byte is zero terminator)
    MOSCALL ffs_getcwd ; MOS api get current working directory
; print the directory path (ffs_getcwd preserves hl)
    call printString
; now get dir info
    ld hl,ps_dir_struct ; define where to store directory info
    ld de,ps_dir_path   ; this is pointer to the path to the directory
    xor a               ; tell MOS to expect zero-terminated string
    MOSCALL ffs_dopen   ; open dir
; set up pointers
    ld ix,ps_dir_fil_list ; this is the pointer to the fileinfo table
@readFileInfo:               ; we will loop here until all files have been processed
    ld hl,ps_dir_struct      ; HL is where to get directory info
    push ix
    pop de ; where to store current file info
    MOSCALL ffs_dread        ; read next item from dir

    ld a,(ix+filinfo_fname)  ; get first char of file name
    or a                     ; if zero then we are at the end of the listing
    jp z,@allDone

    ld a,(ix+filinfo_fattrib) ; get the file attribute
    res 5,a ; clear bit 5 (archive) see: https://discord.com/channels/1158535358624039014/1158536667670511726/1328466726098309173
    or a ; if zero this is a file
    jp nz,@F ; not zero so this is some other file type
    set 5,a ; set bit 5 (archive) so will be consistent btw emulator and hardware
    ld (ix+filinfo_fattrib),a ; update so we don't have to do this every time downstream

@@: ; skip over writing hidden and system files
    and AM_HID ; hidden file
    jp nz,@readFileInfo
    and AM_SYS ; system file
    jp nz,@readFileInfo

; valid file or directory
    ld hl,(ps_dir_num_files) ; get the current file counter
    inc hl                  ; increment the counter
    ld (ps_dir_num_files),hl
    ld de,filinfo_struct_size ; length of fileinfo record
    add ix,de ; point to next fileinfo record

    jp @readFileInfo         ; loop around to check next entry
@allDone:
; compute page statistics
    ld hl,(ps_dir_num_files) ; get the number of files
    ld de,10 ; max files per page
    call udiv24 ; de = hl/10, hl = mod(hl,10)
    SIGN_HLU ; check remainder for zero
    jp nz,@F 
    ld hl,10 ; if zero then we have exactly 10 files on the last page ...
    dec de ; ... and we don't need an additional page for the remainder
@@:
    ld (ps_pagelast_num_files),hl ; save the number of files on the last page
    inc de ; bump the page count
    ld (ps_dir_num_pages),de ; save the number of pages
; reset the song index and page to zero  
    xor a
    ld (ps_song_idx_cur),a
    ld hl,0 
    ld (ps_page_cur),hl
; and populate the page filename pointers and print the page
    call ps_fill_page_fn_ptrs
    call ps_print_dir_page
; close the directory
    ld hl,ps_dir_struct      ; load H: with address of the DIR struct
    MOSCALL ffs_dclose       ; close dir
    ret
; end ps_get_dir

; populate the page filename pointers for the current directory page
; inputs: ps_page_cur
; prerequisites: ps_get_dir called on a valid directory
; outputs: a populated filename pointer list for the current page
; destroys: a, hl, bc, de, ix
ps_fill_page_fn_ptrs:
    ld hl,(ps_page_cur) ; get the current page number
    ld de,10*filinfo_struct_size ; records/page * bytes/record
    call umul24 ; hl = offset into the fileinfo table
    ld de,ps_dir_fil_list ; base address of fileinfo table
    add hl,de ; add the offset to the base address
    ld ix,ps_page_fn_ptrs ; get the address of the page fileinfo pointer table
    ld de,filinfo_struct_size ; bytes per filename record
    ld b,10 ; number of files per page
@loop:
    ld (ix),hl ; store the filename pointer
    lea ix,ix+3 ; bump the index pointer
    add hl,de ; add the record size to the filename pointer
    djnz @loop
    ret
; end ps_fill_page_fn_ptrs

ps_get_page_num_files:
; check whether we're at last page
    ld hl,(ps_page_cur)
    ld de,(ps_dir_num_pages)
    dec de ; zero-based
    or a ; clear carry
    sbc hl,de
    ld b,10 ; b = default number of files per page
    ret nz ; not the last page
    ld a,(ps_pagelast_num_files) ; get the number of files on the last page
    ld b,a ; b = number of files on the last page
    ret
; end ps_get_page_num_files

ps_print_dir_page:
; set text viewport for directory listing
    call vp_dir
    call vdu_cls
; loop through the fileinfo pointer table and print out the filenames
    call ps_get_page_num_files ; b = loop counter
    xor a ; song index
    ld ix,ps_page_fn_ptrs
@loop:
    push bc ; save loop counter
    push af ; save song index
    call printHexA ; print the song index
; branch on the file attribute
    ld hl,(ix) ; get the filename pointer
    ld bc,filinfo_fattrib
    add hl,bc ; hl points to the file attribute
    ld a,(hl)
    cp AM_DIR ; if zero, is directory
    jp nz,@print_file ; not directory so just write filename
    push hl
    call printInline
    asciz "<DIR> "
    pop hl
@print_file:
    ld bc,filinfo_fname-filinfo_fattrib ; offset to the filename
    add hl,bc ; hl points to the filename
    call printString ; print the filename
@bump_counters:
    lea ix,ix+3 ; bump the filename pointer
    pop af ; restore song index
    inc a ; increment the song index
    pop bc ; restore loop counter
    dec b
    ret z ; if zero, we're done
    call printNewLine
    jp @loop
    ret
; end ps_print_dir_page

ps_print_dir:
; test whether there are any files in the directory
    ld hl,(ps_dir_num_files)
    SIGN_HLU
    ret z ; if zero, no files in the directory
; loop through the fileinfo table and print out the filenames
    ld ix,ps_dir_fil_list
    ld hl,(ps_dir_num_files)
@print_loop:
    push hl ; loop counter
; branch on the file attribute
    ld a,(ix+filinfo_fattrib)
    cp AM_DIR ; if zero, is directory
    jp nz,@print_file ; not directory so just write filename
    call printInline
    asciz "<DIR> "
@print_file:
    lea ix,ix+filinfo_fname ; point to filinfo_fname
    push ix
    pop hl ; get the address of the filename
    call printString
    call printNewLine
    ld de,256 ; length of filename
    add ix,de ; bump pointer to next filinfo record
@dec_loop_counter:
    pop hl 
    dec hl ; decrement the loop counter
    SIGN_HLU ; check for zero
    jp nz,@print_loop
    ret
@skip_file:
    ld de,filinfo_struct_size 
    add ix,de ; bump pointer to next filinfo record
    jp @dec_loop_counter
; end ps_print_dir

ps_highlight_song:
; refresh the directory listing
    call ps_print_dir_page
; highlight the song being played in the directory listing
    ld a,(ps_song_idx_cur)
    ld d,vp_dir_top
    add a,d
    ld c,text_left
    ld d,a
    ld e,text_right
    ld b,a
    call vdu_set_txt_viewport
    call vdu_home_cursor
; set text colours to inverse
    call set_text_colours_inverse
; print the index and song filename
    ld a,(ps_song_idx_cur)
    call printHexA
    ld hl,(ps_song_fn_cur)
    call printString
; set text colours to normal
    call set_text_colours_normal
    ret
; end ps_highlight_song

ps_dir_next_page:
; advance the page number
    ld hl,(ps_page_cur) ; get the current page number
    inc hl ; increment the page number
    ld de,(ps_dir_num_pages) ; get the number of pages
    call udiv24 ; hl = mod(ps_page_cur+1,ps_dir_num_pages)
    ld (ps_page_cur),hl ; save the new page number
; populate the page filename pointers
    call ps_fill_page_fn_ptrs
; print the new page
    call ps_print_dir_page
; enable interrupts and jump back to the user input loop
    ei
    jp get_input
; end ps_dir_next_page

ps_dir_prev_page:
; decrement the page number
    ld hl,(ps_page_cur) ; get the current page number
    dec hl ; decrement the page number
    SIGN_HLU ; check for zero
    jp p,@F ; >= 0 so we're good
    ld hl,(ps_dir_num_pages) ; get the number of pages
    dec hl ; zero-based
@@:
    ld (ps_page_cur),hl ; save the new page number
; populate the page filename pointers
    call ps_fill_page_fn_ptrs
; print the new page and
    call ps_print_dir_page
; enable interrupts and jump back to the user input loop
    ei
    jp get_input
; end ps_dir_prev_page

; get the filename of the song at the current index
; inputs: a = song index
; returns: carry set if song index in range, new filemame in hl and ps_song_idx_cur, ps_song_fn_cur set to new index, a = file attribute
;          carry reset if song index out of range, current filename in hl, ps_song_idx_cur, ps_song_fn_cur unchanged, a = requested song index
; destroys: af, bc, de
ps_get_song_fn_from_pg_idx:
    push af ; save song index
    call ps_get_page_num_files ; b = number of files on the page
    pop af ; restore song index
    cp b ; compare song index to number of files on the page
    ld hl,(ps_song_fn_cur) ; get the current song filename
    ret nc ; requested song index is out of range so return current filename and no carry
    ld (ps_song_idx_cur),a ; save the song index
    ld ix,ps_page_fn_ptrs ; get the address of the page fileinfo pointer table
    ld b,a ; song index
    ld c,3 ; 3 bytes per filename pointer
    mlt bc ; index into the fileinfo pointer table
    add ix,bc ; hl points to the fileinfo pointer

    ld hl,(ix) ; hl points to the fileinfo
    ld bc,filinfo_fattrib ; offset to the file attribute
    add hl,bc ; hl points to the file attribute
    ld a,(hl) ; get the file attribute for determining file vs. directory

    ld hl,(ix) ; hl points to the fileinfo
    ld bc,filinfo_fname ; offset to the filename
    add hl,bc ; hl points to the filename
    ld (ps_song_fn_cur),hl ; save the new song filename
    scf ; set carry to indicate success
    ret
; end ps_get_song_fn_from_pg_idx

ps_song_over:
; get playback mode
    ld hl,ps_mode

; are we in loop mode?
    bit ps_mode_loop,(hl)
    jp z,@F ; no so check next mode
    ld hl,(ps_song_fn_cur) ; get current song filename
    jp play_song ; and play it again, Sam

@@: ; are we in shuffle mode?
    bit ps_mode_shuffle,(hl)
    jp nz,ps_play_random ; yes so play a random song

; loop and shuffle are off so play next song
    jp ps_play_next_song
; end ps_song_over

ps_play_next_song:
    ld a,(ps_song_idx_cur) ; get the current song index
@next_song:
    inc a ; increment the song index
    ld (@songIdx),a ; save the new song index
    call ps_get_song_fn_from_pg_idx ; hl points to file, carry set indicates success, a has file attribute
    jp c,@good_file ; filename is valid
    ld a,-1 ; invalid filename means we went past the end of the list, so reset ...
    jp @next_song ; ... and try again

@good_file:
    cp AM_DIR ; file attribute check for directory
    jp nz,@play_song ; not a directory so play the song
    jp @next_song ; is a directory so try the next file

@play_song:
    ld a,(@songIdx) ; get the new song index
    ld (ps_song_idx_cur),a ; save the new song index
    jp play_song
@songIdx: db 0
; end ps_play_next_song

ps_play_prev_song:
    ld a,(ps_song_idx_cur) ; get the current song index
@prev_song:
    dec a ; decrement the song index
    ld (@songIdx),a ; save the new song index
    call ps_get_song_fn_from_pg_idx ; hl points to file, carry set indicates success, a has file attribute
    jp c,@good_file ; filename is valid
    ld a,10 ; invalid filename means we went past the beginning of the list, so reset ...
    jp @prev_song ; ... and try again

@good_file:
    cp AM_DIR ; file attribute check for directory
    jp nz,@play_song ; not a directory so play the song
    jp @prev_song ; is a directory so try the previous file

@play_song:
    ld a,(@songIdx) ; get the new song index
    ld (ps_song_idx_cur),a ; save the new song index
    jp play_song

@songIdx: db 0
; end ps_play_prev_song

; queue a random song on the current page to play next
ps_play_random:
; back up current song index
    ld hl,(ps_song_fn_cur)
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
    call ps_load_command_buffers
    ret
; end ps_read_wav_header

ps_load_command_buffers:
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
; end ps_load_command_buffers
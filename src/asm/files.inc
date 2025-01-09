; load to onboard 8k sram
filedata: equ 0xB7E000

ps_dir_path:   blkw 256,0 ; path of the current directory
ps_dir_struct:             
ps_dptr:       blkb  4,0   ; Current read/write offset
ps_clust:      blkb  4,0   ; Current cluster
ps_sect:       blkb  4,0   ; Current sector (0:Read operation has terminated)
ps_dir:        blkb  3,0   ; Pointer to the directory item in the win[]
ps_fn:         blkb  12,0  ; SFN (in/out) {body[8],ext[3],status[1]}
ps_blk_ofs:    blkb  4,0   ; Offset of current entry block being processed (0xFFFFFFFF:Invalid)

; song file info
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

; buffer for sound data
; must be in the final include of the program
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
ps_wav_data_start:    equ $   ; Start of audio data
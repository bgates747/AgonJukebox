; browse_song state variables
; current active channel and bufferId's
bs_dir_path:   blkb 256,0 ; path of the current directory
bs_dir_num_files: dl 0 ; number of files/directories in the directory (virtually unlimited)
bs_dir_num_pages: dl 0 ; number of pages in the directory (virtually unlimited)
bs_page_num_files: dl 0 ; number of files/directories in the current directory page (max 10)
bs_pagelast_num_files: dl 0 ; mod(bs_dir_num_files,10)
bs_page_cur: dl 0 ; current directory page number
bs_song_idx_cur: db 0 ; current song index in the directory page
bs_song_fn_cur: dl 0 ; pointer to current song filename
bs_song_duration: blkw 5,0 ; duration of the current song in seconds (32-bit word plus a padding byte)
bs_playhead: dl 0 ; current playhead position in the song in seconds from the start
bs_page_fn_ptrs: blkw 10*3,0 ; list of filename pointers in the current directory page

; browse_song directory info
bs_dir_struct:             
bs_dptr:       blkb  4,0   ; Current read/write offset
bs_clust:      blkb  4,0   ; Current cluster
bs_sect:       blkb  4,0   ; Current sector (0:Read operation has terminated)
bs_dir:        blkb  3,0   ; Pointer to the directory item in the win[]
bs_fn:         blkb  12,0  ; SFN (in/out) {body[8],ext[3],status[1]}
bs_blk_ofs:    blkb  4,0   ; Offset of current entry block being processed (0xFFFFFFFF:Invalid)

; browse_song file info
bs_filehandle_cur: db 0 ; file handle
bs_chunkpointer: dl 0 ; pointer to current chunk
; File information structure (FILINFO)
bs_file_struct:
bs_file_fsize:    blkb 4, 0   ; File size (4 bytes)
bs_file_fdate:    blkb 2, 0   ; Modified date (2 bytes)
bs_file_ftime:    blkb 2, 0   ; Modified time (2 bytes)
bs_file_fattrib:  blkb 1, 0   ; File attribute (1 byte)
bs_file_altname:  blkb 13, 0  ; Alternative file name (13 bytes)
bs_file_fname:    blkb 256, 0 ; Primary file name (256 bytes)

; buffer for browse_song sound data
bs_wav_header: ; marker for top of the wav file header and song data
; (must be last so buffer doesn't overwrite other program code or data)
; .wav header data
; WAV File Structure in Memory with LIST Chunk
bs_wav_riff:          blkb 4,0   ; 4 bytes: "RIFF" identifier
bs_wav_file_size:     blkb 4,0   ; 4 bytes: Total file size minus 8 bytes for RIFF header
bs_wav_wave:          blkb 4,0   ; 4 bytes: "WAVE" identifier
bs_wav_fmt_marker:    blkb 4,0   ; 4 bytes: "fmt " subchunk marker
bs_wav_fmt_size:      blkb 4,0   ; 4 bytes: Format chunk size (16 for PCM)
bs_wav_audio_format:  blkb 2,0   ; 2 bytes: Audio format (1 = PCM)
bs_wav_num_channels:  blkb 2,0   ; 2 bytes: Number of channels (1 = mono, 2 = stereo)
bs_wav_sample_rate:   blkb 4,0   ; 4 bytes: Sample rate in Hz (e.g., 32768)
bs_wav_byte_rate:     blkb 4,0   ; 4 bytes: Bytes per second (SampleRate * NumChannels * BitsPerSample / 8)
bs_wav_block_align:   blkb 2,0   ; 2 bytes: Bytes per sample block (NumChannels * BitsPerSample / 8)
bs_wav_bits_per_sample: blkb 2,0 ; 2 bytes: Bits per sample (e.g., 8 or 16)

; LIST Chunk (Extra Metadata)
bs_wav_list_marker:   blkb 4,0   ; 4 bytes: "LIST" marker
bs_wav_list_size:     blkb 4,0   ; 4 bytes: Size of the LIST chunk (e.g., 26)
bs_wav_info_marker:   blkb 4,0   ; 4 bytes: "INFO" marker
bs_wav_isft_marker:   blkb 4,0   ; 4 bytes: "ISFT" marker (software identifier)
bs_wav_isft_data:     blkb 14,0  ; 14 bytes: Software info string (e.g., "Lavf59.27.100")
bs_wav_isft_padding:  blkb 2,0   ; 2 bytes: Padding/NULL terminator for alignment

; Data Chunk
bs_wav_data_marker:   blkb 4,0   ; 4 bytes: "data" subchunk marker
bs_wav_data_size:     blkb 4,0   ; 4 bytes: Size of the audio data in bytes
; Total Header Size: 76 bytes

; THIS MUST BE LAST INCLUDE SO FILE DATA DOES NOT OVERWRITE OTHER CODE OR DATA

; buffer for loading files unrelated to audio
; e.g.: fonts, sprites, etc. (limited to 8k)
filedata: equ 0xB7E000 ; address of onboard 8k sram

bs_dir_struct: equ $ ; browsing song directory info
bs_filinfo_struct: equ bs_dir_struct+dir_struct_size ; browsing song file info
bs_wav_header: equ bs_filinfo_struct+filinfo_struct_size ; browsing song .wav file header

ps_dir_struct: equ bs_wav_header+wav_header_size ; playing song directory info
ps_wav_header: equ ps_dir_struct+dir_struct_size ; playing song .wav file header
ps_wav_data_start: equ 0x050000 ; playing song .wav file data buffer

; this list can grow as large as necessary to hold all the files in the directory
; each entry will be 278 bytes (filinfo_struct_size)
ps_dir_fil_list: equ ps_wav_data_start+65536 ; max file data we can load in one chunk is 64k
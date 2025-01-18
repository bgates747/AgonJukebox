; THIS MUST BE LAST INCLUDE SO FILE DATA DOES NOT OVERWRITE OTHER CODE OR DATA

; buffer for loading files unrelated to audio
; e.g.: fonts, sprites, etc. (limited to 8k)
filedata: equ 0xB7E000 ; address of onboard 8k sram

; JukeBox Structure (JB)
;
; Indexes into JukeBox structure
jb_filehandle:          EQU 0          ;   1: File handle
jb_file_idx:            EQU jb_filehandle+1  ;   1: Current file index in the directory page
jb_filename:            EQU jb_file_idx+1    ;   3: Pointer to current file filename
jb_dir_num_files:       EQU jb_filename+3    ;   3: Number of files/directories in the directory (virtually unlimited)
jb_pagelast_num_files:  EQU jb_dir_num_files+3  ;   3: Mod(jb_dir_num_files, 10)
jb_page_cur:            EQU jb_pagelast_num_files+3  ;   3: Current directory page number
jb_dir_num_pages:       EQU jb_page_cur+3    ;   3: Number of pages in the directory (virtually unlimited)
jb_dir_struct:          EQU jb_dir_num_pages+3  ;  3: Pointer to Directory object structure (DIR) struct
jb_dir_fil_list:        EQU jb_dir_struct+3  ;  3: Pointer to the file list in the current directory page 
jb_wav_header:          EQU jb_dir_fil_list+3  ;  3: Pointer to the .wav header data buffer
jb_filename_ptrs:       EQU jb_wav_header+3  ;  30: List of filename pointers in the current directory page (10*3)
jb_dir_path:            EQU jb_filename_ptrs+30 ; 256: Path of the current directory
jb_struct_size:         EQU jb_dir_path+256  ; Total size of the JB structure

bs_jukebox_struct: equ $ ; browsing song jukebox info
bs_dir_struct: equ bs_jukebox_struct+jb_struct_size ; browsing song directory info
bs_dir_fil_list: equ bs_dir_struct+dir_struct_size ; browsing song directory file list
bs_dir_fil_list_size: equ 256*filinfo_struct_size ; 256 files max per directory
bs_wav_header: equ bs_dir_fil_list+bs_dir_fil_list_size ; browsing song .wav file header

ps_jukebox_struct: equ bs_wav_header+wav_header_size ; playing song jukebox info
ps_dir_struct: equ ps_jukebox_struct+jb_struct_size ; playing song directory info
ps_dir_fil_list: equ ps_dir_struct+dir_struct_size ; playing song directory file list
ps_dir_fil_list_size: equ 256*filinfo_struct_size ; 256 files max per directory
ps_wav_header: equ ps_dir_fil_list+ps_dir_fil_list_size ; playing song .wav file header

ps_wav_data_start: equ ps_wav_header+wav_header_size ; playing song .wav file data buffer
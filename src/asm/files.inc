; THIS MUST BE LAST INCLUDE SO FILE DATA DOES NOT OVERWRITE OTHER CODE OR DATA

; buffer for loading files unrelated to audio
; e.g.: fonts, sprites, etc. (limited to 8k)
filedata: equ 0xB7E000 ; address of onboard 8k sram

; directory and file browsing data
bf_struct: equ 0x050000 ; browsing song jukebox info
bf_filehandle: equ 0x050000 ; 1 bytes: File handle
bf_file_idx: equ 0x050001 ; 1 bytes: Current file index in the directory page
bf_dir_num_files: equ 0x050002 ; 3 bytes: Number of files/directories in the directory (virtually unlimited)
bf_dir_num_files_lp: equ 0x050005 ; 3 bytes: Mod(jb_dir_num_files, 10)
bf_page_cur: equ 0x050008 ; 3 bytes: Current directory page number
bf_dir_num_pages: equ 0x05000B ; 3 bytes: Number of pages in the directory (virtually unlimited)
bf_dir_path: equ 0x05000E ; 256 bytes: Path of the current directory

bf_dir_struct: equ 0x050200 ; browsing song directory info
bf_dir_obj: equ 0x050200 ; 15 bytes: Object identifier
bf_dir_dptr: equ 0x05020F ; 4 bytes: Current read/write offset
bf_dir_clust: equ 0x050213 ; 4 bytes: Current cluster
bf_dir_sect: equ 0x050217 ; 4 bytes: Current sector (0:Read operation has terminated)
bf_dir_dir: equ 0x05021B ; 3 bytes: Pointer to the directory item in the win[]
bf_dir_fn: equ 0x05021E ; 12 bytes: SFN (in/out) {body[8],ext[3],status[1]}
bf_dir_blk_ofs: equ 0x05022A ; 4 bytes: Offset of current entry block being processed (0xFFFFFFFF:Invalid)

bf_filinfo_ptrs: equ 0x050300 ; 768 bytes: List of filename pointers in the current directory page (256*3)

bf_dir_fil_list: equ 0x050600 ; 71168 bytes: browsing song directory file list

bf_filinfo_struct: equ 0x061C00 ; 
bf_filinfo_fsize: equ 0x061C00 ; 4 bytes: File size
bf_filinfo_fdate: equ 0x061C04 ; 2 bytes: Modified date
bf_filinfo_ftime: equ 0x061C06 ; 2 bytes: Modified time
bf_filinfo_fattrib: equ 0x061C08 ; 1 bytes: File attribute
bf_filinfo_altname: equ 0x061C09 ; 13 bytes: Alternative file name
bf_filinfo_fname: equ 0x061C16 ; 256 bytes: Primary file name

bf_wav_header: equ 0x061E00 ; 76 bytes: browsing song .wav file header

; playing song data
ps_filinfo_struct: equ 0x070000 ; 
ps_filinfo_fsize: equ 0x070000 ; 4 bytes: File size
ps_filinfo_fdate: equ 0x070004 ; 2 bytes: Modified date
ps_filinfo_ftime: equ 0x070006 ; 2 bytes: Modified time
ps_filinfo_fattrib: equ 0x070008 ; 1 bytes: File attribute
ps_filinfo_altname: equ 0x070009 ; 13 bytes: Alternative file name
ps_filinfo_fname: equ 0x070016 ; 256 bytes: Primary file name

ps_wav_header: equ 0x070200 ; 76 bytes: playing song .wav file header
ps_wav_data: equ 0x070300 ; virtually unlimited bytes
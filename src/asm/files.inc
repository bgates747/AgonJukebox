; THIS MUST BE LAST INCLUDE SO FILE DATA DOES NOT OVERWRITE OTHER CODE OR DATA

; buffer for loading files unrelated to audio
; e.g.: fonts, sprites, etc. (limited to 8k)
filedata: equ 0xB7E000 ; address of onboard 8k sram

bf_fil_struct: equ 0x06FF00 ; 
bf_fil_obj: equ 0x06FF00 ; 15 bytes: Object identifier
bf_fil_flag: equ 0x06FF0F ; 1 bytes: File status flags
bf_fil_err: equ 0x06FF10 ; 1 bytes: Abort flag (error code)
bf_fil_fptr: equ 0x06FF11 ; 4 bytes: File read/write pointer (Zeroed on file open)
bf_fil_clust: equ 0x06FF15 ; 4 bytes: Current cluster of fpter (invalid when fptr is 0)
bf_fil_sect: equ 0x06FF19 ; 4 bytes: Sector number appearing in buf[] (0
bf_fil_dir_sect: equ 0x06FF1D ; 4 bytes: Sector number containing the directory entry
bf_fil_dir_ptr: equ 0x06FF21 ; 3 bytes: Pointer to the directory entry in the win[]


bf_struct: equ 0x070000 ; browsing song jukebox info
bf_file_idx: equ 0x070000 ; 1 bytes: Current file index in the directory page
bf_dir_num_files: equ 0x070001 ; 3 bytes: Number of files/directories in the directory (virtually unlimited)
bf_files_cur_pg: equ 0x070004 ; 3 bytes: Number of files/directories of the current directory page
bf_files_last_pg: equ 0x070007 ; 3 bytes: Number of files/directories of the last directory page
bf_page_cur: equ 0x07000A ; 3 bytes: Current directory page number
bf_dir_num_pages: equ 0x07000D ; 3 bytes: Number of pages in the directory (virtually unlimited)
bf_dir_path: equ 0x070010 ; 256 bytes: Path of the current directory
bf_struct_size: equ 512

bf_dir_struct: equ 0x070200 ; browsing song directory info
bf_dir_obj: equ 0x070200 ; 15 bytes: Object identifier
bf_dir_dptr: equ 0x07020F ; 4 bytes: Current read/write offset
bf_dir_clust: equ 0x070213 ; 4 bytes: Current cluster
bf_dir_sect: equ 0x070217 ; 4 bytes: Current sector (0:Read operation has terminated)
bf_dir_dir: equ 0x07021B ; 3 bytes: Pointer to the directory item in the win[]
bf_dir_fn: equ 0x07021E ; 12 bytes: SFN (in/out) {body[8],ext[3],status[1]}
bf_dir_blk_ofs: equ 0x07022A ; 4 bytes: Offset of current entry block being processed (0xFFFFFFFF:Invalid)

bf_filinfo_ptrs: equ 0x070300 ; 768 bytes: List of filename pointers in the current directory page (256*3)
bf_filinfo_ptrs_size: equ 768

bf_dir_fil_list: equ 0x070600 ; 71168 bytes: browsing song directory file list
bf_dir_fil_list_size: equ 71168

bf_wav_header: equ 0x081C00 ; 76 bytes: browsing song .wav file header
bf_agm_header: equ 0x081C4C ; 144 bytes: browsing song .agm file header

ps_fil_struct: equ 0x090000 ; 
ps_fil_obj: equ 0x090000 ; 15 bytes: Object identifier
ps_fil_flag: equ 0x09000F ; 1 bytes: File status flags
ps_fil_err: equ 0x090010 ; 1 bytes: Abort flag (error code)
ps_fil_fptr: equ 0x090011 ; 4 bytes: File read/write pointer (Zeroed on file open)
ps_fil_clust: equ 0x090015 ; 4 bytes: Current cluster of fpter (invalid when fptr is 0)
ps_fil_sect: equ 0x090019 ; 4 bytes: Sector number appearing in buf[] (0
ps_fil_dir_sect: equ 0x09001D ; 4 bytes: Sector number containing the directory entry
ps_fil_dir_ptr: equ 0x090021 ; 3 bytes: Pointer to the directory entry in the win[]

ps_filinfo_struct: equ 0x090100 ; 
ps_filinfo_fsize: equ 0x090100 ; 4 bytes: File size
ps_filinfo_fdate: equ 0x090104 ; 2 bytes: Modified date
ps_filinfo_ftime: equ 0x090106 ; 2 bytes: Modified time
ps_filinfo_fattrib: equ 0x090108 ; 1 bytes: File attribute
ps_filinfo_altname: equ 0x090109 ; 13 bytes: Alternative file name
ps_filinfo_fname: equ 0x090116 ; 256 bytes: Primary file name

ps_wav_header: equ 0x090300 ; 76 bytes: playing song .wav file header
ps_wav_data: equ 0x09034C ; virtually unlimited bytes: 

ps_agm_header: equ 0x09034C ; 144 bytes: 
ps_agm_data: equ 0x0903DC ; virtually unlimited bytes: 
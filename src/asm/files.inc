; THIS MUST BE LAST INCLUDE SO FILE DATA DOES NOT OVERWRITE OTHER CODE OR DATA

; buffer for loading files unrelated to audio
; e.g.: fonts, sprites, etc. (limited to 8k)
filedata: equ 0xB7E000 ; address of onboard 8k sram

;     align 256 ; make things nice for indexing into especially ps_dir_fil_list
; ; buffer for sound data
ps_wav_data_start: equ 0x050000 ;    equ $   ; (042E00) Start of audio data

; this list can grow as large as necessary to hold all the files in the directory
; each entry will be 256 bytes long, the max filename size MOS/FFS supports
ps_dir_fil_list: equ 0x060000 ; equ ps_wav_data_start+65536 ; (052E00) max file data we can load in one chunk is 64k
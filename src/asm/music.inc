; This file is created by build_98_asm_sfx.py, do not edit it!

SFX_num_buffers: equ 10
sample_rate: equ 32768

; File name lookup index:
SFX_filename_index:
	dl FN_Africa
	dl FN_Anytime
	dl FN_Barracuda
	dl FN_Come_Undone
	dl FN_Every_Breath_You_Take
	dl FN_Jukebox_Hero
	dl FN_Rhiannon
	dl FN_Take_A_Ride
	dl FN_Wild_Flower
	dl FN_Wont_Get_Fooled_Again

; File name lookups:
FN_Africa: db "music/Africa.raw",0
FN_Anytime: db "music/Anytime.raw",0
FN_Barracuda: db "music/Barracuda.raw",0
FN_Come_Undone: db "music/Come_Undone.raw",0
FN_Every_Breath_You_Take: db "music/Every_Breath_You_Take.raw",0
FN_Jukebox_Hero: db "music/Jukebox_Hero.raw",0
FN_Rhiannon: db "music/Rhiannon.raw",0
FN_Take_A_Ride: db "music/Take_A_Ride.raw",0
FN_Wild_Flower: db "music/Wild_Flower.raw",0
FN_Wont_Get_Fooled_Again: db "music/Wont_Get_Fooled_Again.raw",0

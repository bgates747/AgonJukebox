; This file is created by build_98_asm_sfx.py, do not edit it!

SFX_num_buffers: equ 10
sample_rate: equ 32768


; File name lookup index:
SFX_filename_index:
	dl FN_Abbey_Road
	dl FN_Barracuda
	dl FN_Dire_Straits
	dl FN_Goodbye_Yellow_Brick_Road_1
	dl FN_Goodbye_Yellow_Brick_Road_2
	dl FN_Jukebox_Hero
	dl FN_Rhiannon
	dl FN_The_Dark_Side_Of_The_Moon
	dl FN_Wild_Flower
	dl FN_Wont_Get_Fooled_Again

; File name lookups:
FN_Abbey_Road: db "music/Abbey_Road.raw",0
FN_Barracuda: db "music/Barracuda.raw",0
FN_Dire_Straits: db "music/Dire_Straits.raw",0
FN_Goodbye_Yellow_Brick_Road_1: db "music/Goodbye_Yellow_Brick_Road_1.raw",0
FN_Goodbye_Yellow_Brick_Road_2: db "music/Goodbye_Yellow_Brick_Road_2.raw",0
FN_Jukebox_Hero: db "music/Jukebox_Hero.raw",0
FN_Rhiannon: db "music/Rhiannon.raw",0
FN_The_Dark_Side_Of_The_Moon: db "music/The_Dark_Side_Of_The_Moon.raw",0
FN_Wild_Flower: db "music/Wild_Flower.raw",0
FN_Wont_Get_Fooled_Again: db "music/Wont_Get_Fooled_Again.raw",0

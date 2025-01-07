; This file is created by build_98_asm_sfx.py, do not edit it!

SFX_num_buffers: equ 10
sample_rate: equ 32768

; File name lookup index:
SFX_filename_index:
	dl FN_Abbey_Road
	dl FN_Dire_Straits
	dl FN_Electric
	dl FN_Goodbye_Yellow_Brick_Road_1
	dl FN_Goodbye_Yellow_Brick_Road_2
	dl FN_Led_Zeppelin_I
	dl FN_Led_Zeppelin_Ii
	dl FN_Rumours
	dl FN_The_Dark_Side_Of_The_Moon
	dl FN_Whos_Next

; File name lookups:
FN_Abbey_Road: db "music/Abbey_Road.raw",0
FN_Dire_Straits: db "music/Dire_Straits.raw",0
FN_Electric: db "music/Electric.raw",0
FN_Goodbye_Yellow_Brick_Road_1: db "music/Goodbye_Yellow_Brick_Road_1.raw",0
FN_Goodbye_Yellow_Brick_Road_2: db "music/Goodbye_Yellow_Brick_Road_2.raw",0
FN_Led_Zeppelin_I: db "music/Led_Zeppelin_I.raw",0
FN_Led_Zeppelin_Ii: db "music/Led_Zeppelin_Ii.raw",0
FN_Rumours: db "music/Rumours.raw",0
FN_The_Dark_Side_Of_The_Moon: db "music/The_Dark_Side_Of_The_Moon.raw",0
FN_Whos_Next: db "music/Whos_Next.raw",0

; This file is created by build_98_asm_sfx.py, do not edit it!

SFX_num_buffers: equ 10
sample_rate: equ 32768


; File name lookup index:
SFX_filename_index:
	dl FN_Africa
	dl FN_Anytime
	dl FN_Barracuda
	dl FN_Comeundone
	dl FN_Everybreathyoutake
	dl FN_Jukeboxhero
	dl FN_Rhiannon
	dl FN_Takearide
	dl FN_Wildflower
	dl FN_Wontgetfooledagain

; File name lookups:
FN_Africa: db "music/Africa.raw",0
FN_Anytime: db "music/Anytime.raw",0
FN_Barracuda: db "music/Barracuda.raw",0
FN_Comeundone: db "music/Comeundone.raw",0
FN_Everybreathyoutake: db "music/Everybreathyoutake.raw",0
FN_Jukeboxhero: db "music/Jukeboxhero.raw",0
FN_Rhiannon: db "music/Rhiannon.raw",0
FN_Takearide: db "music/Takearide.raw",0
FN_Wildflower: db "music/Wildflower.raw",0
FN_Wontgetfooledagain: db "music/Wontgetfooledagain.raw",0

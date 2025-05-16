
num_samples: equ 8

; Sample dictionary (pointer, frequency/pitch)
; Format: pointer, 0xPPFFFF (PP=MIDI pitch, FFFF=frequency in Hz)
sample_dictionary:
 dl fn_021, 0x15001C ; freq=28 Hz, pitch=21 (A0)
 dl fn_033, 0x210037 ; freq=55 Hz, pitch=33 (A1)
 dl fn_045, 0x2D006E ; freq=110 Hz, pitch=45 (A2)
 dl fn_057, 0x3900DC ; freq=220 Hz, pitch=57 (A3)
 dl fn_069, 0x4501B8 ; freq=440 Hz, pitch=69 (A4)
 dl fn_081, 0x510370 ; freq=880 Hz, pitch=81 (A5)
 dl fn_093, 0x5D06E0 ; freq=1760 Hz, pitch=93 (A6)
 dl fn_105, 0x690DC0 ; freq=3520 Hz, pitch=105 (A7)

; Sample filename strings
sample_filenames:
 fn_021: asciz "Yamaha/021.wav"
 fn_033: asciz "Yamaha/033.wav"
 fn_045: asciz "Yamaha/045.wav"
 fn_057: asciz "Yamaha/057.wav"
 fn_069: asciz "Yamaha/069.wav"
 fn_081: asciz "Yamaha/081.wav"
 fn_093: asciz "Yamaha/093.wav"
 fn_105: asciz "Yamaha/105.wav"

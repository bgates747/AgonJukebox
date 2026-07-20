
num_samples: equ 20

; Sample dictionary (pointer, frequency/pitch)
; Format: pointer, 0xPPFFFF (PP=MIDI pitch, FFFF=frequency in Hz)
sample_dictionary:
 dl fn_038, 0x260049 ; freq=73 Hz, pitch=38 (D2)
 dl fn_042, 0x2A005C ; freq=92 Hz, pitch=42 (F#2)
 dl fn_046, 0x2E0075 ; freq=117 Hz, pitch=46 (A#2)
 dl fn_050, 0x320093 ; freq=147 Hz, pitch=50 (D3)
 dl fn_054, 0x3600B9 ; freq=185 Hz, pitch=54 (F#3)
 dl fn_058, 0x3A00E9 ; freq=233 Hz, pitch=58 (A#3)
 dl fn_062, 0x3E0126 ; freq=294 Hz, pitch=62 (D4)
 dl fn_066, 0x420172 ; freq=370 Hz, pitch=66 (F#4)
 dl fn_070, 0x4601D2 ; freq=466 Hz, pitch=70 (A#4)
 dl fn_074, 0x4A024B ; freq=587 Hz, pitch=74 (D5)
 dl fn_078, 0x4E02E4 ; freq=740 Hz, pitch=78 (F#5)
 dl fn_082, 0x5203A4 ; freq=932 Hz, pitch=82 (A#5)
 dl fn_086, 0x560497 ; freq=1175 Hz, pitch=86 (D6)
 dl fn_090, 0x5A05C8 ; freq=1480 Hz, pitch=90 (F#6)
 dl fn_096, 0x60082D ; freq=2093 Hz, pitch=96 (C7)
 dl fn_102, 0x660B90 ; freq=2960 Hz, pitch=102 (F#7)
 dl fn_106, 0x6A0E91 ; freq=3729 Hz, pitch=106 (A#7)
 dl fn_111, 0x6F1372 ; freq=4978 Hz, pitch=111 (D#8)
 dl fn_128, 0x8033EA ; freq=13290 Hz, pitch=128 (G#9)
 dl fn_132, 0x844168 ; freq=16744 Hz, pitch=132 (C10)

; Sample filename strings
sample_filenames:
 fn_038: asciz "piano_yamaha/038.wav"
 fn_042: asciz "piano_yamaha/042.wav"
 fn_046: asciz "piano_yamaha/046.wav"
 fn_050: asciz "piano_yamaha/050.wav"
 fn_054: asciz "piano_yamaha/054.wav"
 fn_058: asciz "piano_yamaha/058.wav"
 fn_062: asciz "piano_yamaha/062.wav"
 fn_066: asciz "piano_yamaha/066.wav"
 fn_070: asciz "piano_yamaha/070.wav"
 fn_074: asciz "piano_yamaha/074.wav"
 fn_078: asciz "piano_yamaha/078.wav"
 fn_082: asciz "piano_yamaha/082.wav"
 fn_086: asciz "piano_yamaha/086.wav"
 fn_090: asciz "piano_yamaha/090.wav"
 fn_096: asciz "piano_yamaha/096.wav"
 fn_102: asciz "piano_yamaha/102.wav"
 fn_106: asciz "piano_yamaha/106.wav"
 fn_111: asciz "piano_yamaha/111.wav"
 fn_128: asciz "piano_yamaha/128.wav"
 fn_132: asciz "piano_yamaha/132.wav"

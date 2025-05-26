num_samples: equ 110

; Format: filename pointer, frequency, bufferId
sample_dictionary:
; ---- Instrument 1: Piccolo ----
; SoundFont: Piccolo, Bank: 0, Preset: 72
    dl fn_015a, 1480, 0x015a ; pitch=90 (F#6)
    dl fn_015c, 1661, 0x015c ; pitch=92 (G#6)
    dl fn_015e, 1865, 0x015e ; pitch=94 (A#6)
    dl fn_0161, 2217, 0x0161 ; pitch=97 (C#7)
    dl fn_0162, 2349, 0x0162 ; pitch=98 (D7)
    dl fn_0163, 2489, 0x0163 ; pitch=99 (D#7)
; ---- Instrument 2: Flute ----
; SoundFont: Flute, Bank: 0, Preset: 73
    dl fn_024e, 740, 0x024e ; pitch=78 (F#5)
    dl fn_0255, 1109, 0x0255 ; pitch=85 (C#6)
    dl fn_0256, 1175, 0x0256 ; pitch=86 (D6)
    dl fn_025a, 1480, 0x025a ; pitch=90 (F#6)
    dl fn_025e, 1865, 0x025e ; pitch=94 (A#6)
    dl fn_025f, 1976, 0x025f ; pitch=95 (B6)
; ---- Instrument 3: Oboe ----
; SoundFont: Oboe, Bank: 0, Preset: 68
    dl fn_033b, 247, 0x033b ; pitch=59 (B3)
    dl fn_033e, 294, 0x033e ; pitch=62 (D4)
    dl fn_0342, 370, 0x0342 ; pitch=66 (F#4)
    dl fn_0347, 494, 0x0347 ; pitch=71 (B4)
    dl fn_0349, 554, 0x0349 ; pitch=73 (C#5)
    dl fn_034a, 587, 0x034a ; pitch=74 (D5)
    dl fn_034e, 740, 0x034e ; pitch=78 (F#5)
    dl fn_0355, 1109, 0x0355 ; pitch=85 (C#6)
    dl fn_0356, 1175, 0x0356 ; pitch=86 (D6)
    dl fn_0357, 1245, 0x0357 ; pitch=87 (D#6)
; ---- Instrument 4: Clarinet in A ----
; SoundFont: Clarinet, Bank: 0, Preset: 71
    dl fn_043b, 247, 0x043b ; pitch=59 (B3)
    dl fn_043d, 277, 0x043d ; pitch=61 (C#4)
    dl fn_043e, 294, 0x043e ; pitch=62 (D4)
    dl fn_0442, 370, 0x0442 ; pitch=66 (F#4)
    dl fn_0446, 466, 0x0446 ; pitch=70 (A#4)
    dl fn_0449, 554, 0x0449 ; pitch=73 (C#5)
    dl fn_044a, 587, 0x044a ; pitch=74 (D5)
    dl fn_044e, 740, 0x044e ; pitch=78 (F#5)
    dl fn_0451, 880, 0x0451 ; pitch=81 (A5)
    dl fn_0453, 988, 0x0453 ; pitch=83 (B5)
    dl fn_0455, 1109, 0x0455 ; pitch=85 (C#6)
; ---- Instrument 5: Bassoon I ----
; SoundFont: Bassoon, Bank: 0, Preset: 70
    dl fn_0523, 62, 0x0523 ; pitch=35 (B1)
    dl fn_052a, 92, 0x052a ; pitch=42 (F#2)
    dl fn_052f, 123, 0x052f ; pitch=47 (B2)
    dl fn_0531, 139, 0x0531 ; pitch=49 (C#3)
    dl fn_0532, 147, 0x0532 ; pitch=50 (D3)
    dl fn_0536, 185, 0x0536 ; pitch=54 (F#3)
    dl fn_053d, 277, 0x053d ; pitch=61 (C#4)
    dl fn_053e, 294, 0x053e ; pitch=62 (D4)
    dl fn_0542, 370, 0x0542 ; pitch=66 (F#4)
    dl fn_0546, 466, 0x0546 ; pitch=70 (A#4)
; ---- Instrument 7: Horn in E I ----
; SoundFont: French Horns, Bank: 0, Preset: 60
    dl fn_072d, 110, 0x072d ; pitch=45 (A2)
    dl fn_0736, 185, 0x0736 ; pitch=54 (F#3)
    dl fn_0739, 220, 0x0739 ; pitch=57 (A3)
    dl fn_073a, 233, 0x073a ; pitch=58 (A#3)
    dl fn_073b, 247, 0x073b ; pitch=59 (B3)
    dl fn_073d, 277, 0x073d ; pitch=61 (C#4)
    dl fn_073e, 294, 0x073e ; pitch=62 (D4)
    dl fn_0742, 370, 0x0742 ; pitch=66 (F#4)
    dl fn_0744, 415, 0x0744 ; pitch=68 (G#4)
    dl fn_0747, 494, 0x0747 ; pitch=71 (B4)
; ---- Instrument 9: Trumpet in E ----
; SoundFont: Trumpet, Bank: 0, Preset: 56
    dl fn_0941, 349, 0x0941 ; pitch=65 (F4)
    dl fn_0942, 370, 0x0942 ; pitch=66 (F#4)
    dl fn_094e, 740, 0x094e ; pitch=78 (F#5)
; ---- Instrument 11: Trombone I ----
; SoundFont: Trombone, Bank: 0, Preset: 57
    dl fn_0b2a, 92, 0x0b2a ; pitch=42 (F#2)
    dl fn_0b2f, 123, 0x0b2f ; pitch=47 (B2)
    dl fn_0b31, 139, 0x0b31 ; pitch=49 (C#3)
    dl fn_0b32, 147, 0x0b32 ; pitch=50 (D3)
    dl fn_0b35, 175, 0x0b35 ; pitch=53 (F3)
    dl fn_0b36, 185, 0x0b36 ; pitch=54 (F#3)
    dl fn_0b3a, 233, 0x0b3a ; pitch=58 (A#3)
    dl fn_0b3b, 247, 0x0b3b ; pitch=59 (B3)
    dl fn_0b3d, 277, 0x0b3d ; pitch=61 (C#4)
    dl fn_0b3e, 294, 0x0b3e ; pitch=62 (D4)
    dl fn_0b42, 370, 0x0b42 ; pitch=66 (F#4)
; ---- Instrument 13: Tuba ----
; SoundFont: Tuba, Bank: 0, Preset: 58
    dl fn_0d1e, 46, 0x0d1e ; pitch=30 (F#1)
    dl fn_0d23, 62, 0x0d23 ; pitch=35 (B1)
    dl fn_0d2a, 92, 0x0d2a ; pitch=42 (F#2)
    dl fn_0d2b, 98, 0x0d2b ; pitch=43 (G2)
    dl fn_0d2f, 123, 0x0d2f ; pitch=47 (B2)
; ---- Instrument 16: Violin I ----
; SoundFont: Violin, Bank: 0, Preset: 40
    dl fn_103b, 247, 0x103b ; pitch=59 (B3)
    dl fn_103d, 277, 0x103d ; pitch=61 (C#4)
    dl fn_103e, 294, 0x103e ; pitch=62 (D4)
    dl fn_1041, 349, 0x1041 ; pitch=65 (F4)
    dl fn_1042, 370, 0x1042 ; pitch=66 (F#4)
    dl fn_1045, 440, 0x1045 ; pitch=69 (A4)
    dl fn_1046, 466, 0x1046 ; pitch=70 (A#4)
    dl fn_1049, 554, 0x1049 ; pitch=73 (C#5)
    dl fn_104a, 587, 0x104a ; pitch=74 (D5)
    dl fn_104e, 740, 0x104e ; pitch=78 (F#5)
    dl fn_1055, 1109, 0x1055 ; pitch=85 (C#6)
    dl fn_1056, 1175, 0x1056 ; pitch=86 (D6)
    dl fn_1057, 1245, 0x1057 ; pitch=87 (D#6)
    dl fn_105a, 1480, 0x105a ; pitch=90 (F#6)
    dl fn_1061, 2217, 0x1061 ; pitch=97 (C#7)
    dl fn_1062, 2349, 0x1062 ; pitch=98 (D7)
    dl fn_1063, 2489, 0x1063 ; pitch=99 (D#7)
; ---- Instrument 18: Viola ----
; SoundFont: Viola, Bank: 0, Preset: 41
    dl fn_1230, 131, 0x1230 ; pitch=48 (C3)
    dl fn_1231, 139, 0x1231 ; pitch=49 (C#3)
    dl fn_1236, 185, 0x1236 ; pitch=54 (F#3)
    dl fn_1242, 370, 0x1242 ; pitch=66 (F#4)
    dl fn_1249, 554, 0x1249 ; pitch=73 (C#5)
    dl fn_124a, 587, 0x124a ; pitch=74 (D5)
    dl fn_124b, 622, 0x124b ; pitch=75 (D#5)
; ---- Instrument 19: Cello ----
; SoundFont: Cello, Bank: 0, Preset: 42
    dl fn_1329, 87, 0x1329 ; pitch=41 (F2)
    dl fn_132a, 92, 0x132a ; pitch=42 (F#2)
    dl fn_132f, 123, 0x132f ; pitch=47 (B2)
    dl fn_1336, 185, 0x1336 ; pitch=54 (F#3)
    dl fn_133b, 247, 0x133b ; pitch=59 (B3)
    dl fn_133e, 294, 0x133e ; pitch=62 (D4)
    dl fn_1342, 370, 0x1342 ; pitch=66 (F#4)
; ---- Instrument 20: Contrabass ----
; SoundFont: Contrabass, Bank: 0, Preset: 43
    dl fn_141e, 46, 0x141e ; pitch=30 (F#1)
    dl fn_1421, 55, 0x1421 ; pitch=33 (A1)
    dl fn_1423, 62, 0x1423 ; pitch=35 (B1)
    dl fn_142a, 92, 0x142a ; pitch=42 (F#2)
    dl fn_142f, 123, 0x142f ; pitch=47 (B2)
    dl fn_1432, 147, 0x1432 ; pitch=50 (D3)
    dl fn_1436, 185, 0x1436 ; pitch=54 (F#3)

; Sample filename strings
sample_filenames:
; ---- Instrument 1: Piccolo ----
; SoundFont: Piccolo, Bank: 0, Preset: 72
    fn_015a: asciz "Samples/Piccolo/090.wav"
    fn_015c: asciz "Samples/Piccolo/092.wav"
    fn_015e: asciz "Samples/Piccolo/094.wav"
    fn_0161: asciz "Samples/Piccolo/097.wav"
    fn_0162: asciz "Samples/Piccolo/098.wav"
    fn_0163: asciz "Samples/Piccolo/099.wav"
; ---- Instrument 2: Flute ----
; SoundFont: Flute, Bank: 0, Preset: 73
    fn_024e: asciz "Samples/Flute/078.wav"
    fn_0255: asciz "Samples/Flute/085.wav"
    fn_0256: asciz "Samples/Flute/086.wav"
    fn_025a: asciz "Samples/Flute/090.wav"
    fn_025e: asciz "Samples/Flute/094.wav"
    fn_025f: asciz "Samples/Flute/095.wav"
; ---- Instrument 3: Oboe ----
; SoundFont: Oboe, Bank: 0, Preset: 68
    fn_033b: asciz "Samples/Oboe/059.wav"
    fn_033e: asciz "Samples/Oboe/062.wav"
    fn_0342: asciz "Samples/Oboe/066.wav"
    fn_0347: asciz "Samples/Oboe/071.wav"
    fn_0349: asciz "Samples/Oboe/073.wav"
    fn_034a: asciz "Samples/Oboe/074.wav"
    fn_034e: asciz "Samples/Oboe/078.wav"
    fn_0355: asciz "Samples/Oboe/085.wav"
    fn_0356: asciz "Samples/Oboe/086.wav"
    fn_0357: asciz "Samples/Oboe/087.wav"
; ---- Instrument 4: Clarinet in A ----
; SoundFont: Clarinet, Bank: 0, Preset: 71
    fn_043b: asciz "Samples/Clarinet/059.wav"
    fn_043d: asciz "Samples/Clarinet/061.wav"
    fn_043e: asciz "Samples/Clarinet/062.wav"
    fn_0442: asciz "Samples/Clarinet/066.wav"
    fn_0446: asciz "Samples/Clarinet/070.wav"
    fn_0449: asciz "Samples/Clarinet/073.wav"
    fn_044a: asciz "Samples/Clarinet/074.wav"
    fn_044e: asciz "Samples/Clarinet/078.wav"
    fn_0451: asciz "Samples/Clarinet/081.wav"
    fn_0453: asciz "Samples/Clarinet/083.wav"
    fn_0455: asciz "Samples/Clarinet/085.wav"
; ---- Instrument 5: Bassoon I ----
; SoundFont: Bassoon, Bank: 0, Preset: 70
    fn_0523: asciz "Samples/Bassoon/035.wav"
    fn_052a: asciz "Samples/Bassoon/042.wav"
    fn_052f: asciz "Samples/Bassoon/047.wav"
    fn_0531: asciz "Samples/Bassoon/049.wav"
    fn_0532: asciz "Samples/Bassoon/050.wav"
    fn_0536: asciz "Samples/Bassoon/054.wav"
    fn_053d: asciz "Samples/Bassoon/061.wav"
    fn_053e: asciz "Samples/Bassoon/062.wav"
    fn_0542: asciz "Samples/Bassoon/066.wav"
    fn_0546: asciz "Samples/Bassoon/070.wav"
; ---- Instrument 7: Horn in E I ----
; SoundFont: French Horns, Bank: 0, Preset: 60
    fn_072d: asciz "Samples/French_Horns/045.wav"
    fn_0736: asciz "Samples/French_Horns/054.wav"
    fn_0739: asciz "Samples/French_Horns/057.wav"
    fn_073a: asciz "Samples/French_Horns/058.wav"
    fn_073b: asciz "Samples/French_Horns/059.wav"
    fn_073d: asciz "Samples/French_Horns/061.wav"
    fn_073e: asciz "Samples/French_Horns/062.wav"
    fn_0742: asciz "Samples/French_Horns/066.wav"
    fn_0744: asciz "Samples/French_Horns/068.wav"
    fn_0747: asciz "Samples/French_Horns/071.wav"
; ---- Instrument 9: Trumpet in E ----
; SoundFont: Trumpet, Bank: 0, Preset: 56
    fn_0941: asciz "Samples/Trumpet/065.wav"
    fn_0942: asciz "Samples/Trumpet/066.wav"
    fn_094e: asciz "Samples/Trumpet/078.wav"
; ---- Instrument 11: Trombone I ----
; SoundFont: Trombone, Bank: 0, Preset: 57
    fn_0b2a: asciz "Samples/Trombone/042.wav"
    fn_0b2f: asciz "Samples/Trombone/047.wav"
    fn_0b31: asciz "Samples/Trombone/049.wav"
    fn_0b32: asciz "Samples/Trombone/050.wav"
    fn_0b35: asciz "Samples/Trombone/053.wav"
    fn_0b36: asciz "Samples/Trombone/054.wav"
    fn_0b3a: asciz "Samples/Trombone/058.wav"
    fn_0b3b: asciz "Samples/Trombone/059.wav"
    fn_0b3d: asciz "Samples/Trombone/061.wav"
    fn_0b3e: asciz "Samples/Trombone/062.wav"
    fn_0b42: asciz "Samples/Trombone/066.wav"
; ---- Instrument 13: Tuba ----
; SoundFont: Tuba, Bank: 0, Preset: 58
    fn_0d1e: asciz "Samples/Tuba/030.wav"
    fn_0d23: asciz "Samples/Tuba/035.wav"
    fn_0d2a: asciz "Samples/Tuba/042.wav"
    fn_0d2b: asciz "Samples/Tuba/043.wav"
    fn_0d2f: asciz "Samples/Tuba/047.wav"
; ---- Instrument 16: Violin I ----
; SoundFont: Violin, Bank: 0, Preset: 40
    fn_103b: asciz "Samples/Violin/059.wav"
    fn_103d: asciz "Samples/Violin/061.wav"
    fn_103e: asciz "Samples/Violin/062.wav"
    fn_1041: asciz "Samples/Violin/065.wav"
    fn_1042: asciz "Samples/Violin/066.wav"
    fn_1045: asciz "Samples/Violin/069.wav"
    fn_1046: asciz "Samples/Violin/070.wav"
    fn_1049: asciz "Samples/Violin/073.wav"
    fn_104a: asciz "Samples/Violin/074.wav"
    fn_104e: asciz "Samples/Violin/078.wav"
    fn_1055: asciz "Samples/Violin/085.wav"
    fn_1056: asciz "Samples/Violin/086.wav"
    fn_1057: asciz "Samples/Violin/087.wav"
    fn_105a: asciz "Samples/Violin/090.wav"
    fn_1061: asciz "Samples/Violin/097.wav"
    fn_1062: asciz "Samples/Violin/098.wav"
    fn_1063: asciz "Samples/Violin/099.wav"
; ---- Instrument 18: Viola ----
; SoundFont: Viola, Bank: 0, Preset: 41
    fn_1230: asciz "Samples/Viola/048.wav"
    fn_1231: asciz "Samples/Viola/049.wav"
    fn_1236: asciz "Samples/Viola/054.wav"
    fn_1242: asciz "Samples/Viola/066.wav"
    fn_1249: asciz "Samples/Viola/073.wav"
    fn_124a: asciz "Samples/Viola/074.wav"
    fn_124b: asciz "Samples/Viola/075.wav"
; ---- Instrument 19: Cello ----
; SoundFont: Cello, Bank: 0, Preset: 42
    fn_1329: asciz "Samples/Cello/041.wav"
    fn_132a: asciz "Samples/Cello/042.wav"
    fn_132f: asciz "Samples/Cello/047.wav"
    fn_1336: asciz "Samples/Cello/054.wav"
    fn_133b: asciz "Samples/Cello/059.wav"
    fn_133e: asciz "Samples/Cello/062.wav"
    fn_1342: asciz "Samples/Cello/066.wav"
; ---- Instrument 20: Contrabass ----
; SoundFont: Contrabass, Bank: 0, Preset: 43
    fn_141e: asciz "Samples/Contrabass/030.wav"
    fn_1421: asciz "Samples/Contrabass/033.wav"
    fn_1423: asciz "Samples/Contrabass/035.wav"
    fn_142a: asciz "Samples/Contrabass/042.wav"
    fn_142f: asciz "Samples/Contrabass/047.wav"
    fn_1432: asciz "Samples/Contrabass/050.wav"
    fn_1436: asciz "Samples/Contrabass/054.wav"

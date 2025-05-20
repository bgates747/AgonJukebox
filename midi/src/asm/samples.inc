num_samples: equ 88

; Format: filename pointer, frequency, bufferId
sample_dictionary:
; ---- Instrument 1: Tuba ----
; SoundFont: Tuba, Bank: 0, Preset: 58
    dl fn_011f, 49, 0x011f ; pitch=31 (G1)
    dl fn_0124, 65, 0x0124 ; pitch=36 (C2)
    dl fn_012b, 98, 0x012b ; pitch=43 (G2)
; ---- Instrument 2: String Ensemble 1 ----
; SoundFont: Strings, Bank: 0, Preset: 48
    dl fn_021d, 44, 0x021d ; pitch=29 (F1)
    dl fn_0222, 58, 0x0222 ; pitch=34 (A#1)
    dl fn_0224, 65, 0x0224 ; pitch=36 (C2)
    dl fn_0229, 87, 0x0229 ; pitch=41 (F2)
    dl fn_022b, 98, 0x022b ; pitch=43 (G2)
    dl fn_022d, 110, 0x022d ; pitch=45 (A2)
    dl fn_022f, 123, 0x022f ; pitch=47 (B2)
    dl fn_0230, 131, 0x0230 ; pitch=48 (C3)
    dl fn_0232, 147, 0x0232 ; pitch=50 (D3)
    dl fn_0234, 165, 0x0234 ; pitch=52 (E3)
    dl fn_0235, 175, 0x0235 ; pitch=53 (F3)
    dl fn_0238, 208, 0x0238 ; pitch=56 (G#3)
    dl fn_023a, 233, 0x023a ; pitch=58 (A#3)
    dl fn_023b, 247, 0x023b ; pitch=59 (B3)
    dl fn_023c, 262, 0x023c ; pitch=60 (C4)
    dl fn_023d, 277, 0x023d ; pitch=61 (C#4)
    dl fn_023f, 311, 0x023f ; pitch=63 (D#4)
    dl fn_0241, 349, 0x0241 ; pitch=65 (F4)
    dl fn_0242, 370, 0x0242 ; pitch=66 (F#4)
    dl fn_0243, 392, 0x0243 ; pitch=67 (G4)
    dl fn_0247, 494, 0x0247 ; pitch=71 (B4)
    dl fn_0248, 523, 0x0248 ; pitch=72 (C5)
    dl fn_0249, 554, 0x0249 ; pitch=73 (C#5)
    dl fn_024b, 622, 0x024b ; pitch=75 (D#5)
    dl fn_024f, 784, 0x024f ; pitch=79 (G5)
    dl fn_0254, 1047, 0x0254 ; pitch=84 (C6)
    dl fn_0256, 1175, 0x0256 ; pitch=86 (D6)
    dl fn_025b, 1568, 0x025b ; pitch=91 (G6)
; ---- Instrument 4: French Horn ----
; SoundFont: French Horns, Bank: 0, Preset: 60
    dl fn_042b, 98, 0x042b ; pitch=43 (G2)
    dl fn_0432, 147, 0x0432 ; pitch=50 (D3)
    dl fn_0437, 196, 0x0437 ; pitch=55 (G3)
    dl fn_043c, 262, 0x043c ; pitch=60 (C4)
    dl fn_0441, 349, 0x0441 ; pitch=65 (F4)
    dl fn_0446, 466, 0x0446 ; pitch=70 (A#4)
; ---- Instrument 5: Trumpet ----
; SoundFont: Trumpet, Bank: 0, Preset: 56
    dl fn_053e, 294, 0x053e ; pitch=62 (D4)
    dl fn_0543, 392, 0x0543 ; pitch=67 (G4)
    dl fn_0548, 523, 0x0548 ; pitch=72 (C5)
    dl fn_054d, 698, 0x054d ; pitch=77 (F5)
    dl fn_0551, 880, 0x0551 ; pitch=81 (A5)
; ---- Instrument 14: Trombone ----
; SoundFont: Trombone, Bank: 0, Preset: 57
    dl fn_0e2b, 98, 0x0e2b ; pitch=43 (G2)
    dl fn_0e32, 147, 0x0e32 ; pitch=50 (D3)
    dl fn_0e37, 196, 0x0e37 ; pitch=55 (G3)
    dl fn_0e3c, 262, 0x0e3c ; pitch=60 (C4)
    dl fn_0e41, 349, 0x0e41 ; pitch=65 (F4)
    dl fn_0e46, 466, 0x0e46 ; pitch=70 (A#4)
; ---- Instrument 16: Flute ----
; SoundFont: Flute, Bank: 0, Preset: 73
    dl fn_1041, 349, 0x1041 ; pitch=65 (F4)
    dl fn_1049, 554, 0x1049 ; pitch=73 (C#5)
    dl fn_104d, 698, 0x104d ; pitch=77 (F5)
    dl fn_1054, 1047, 0x1054 ; pitch=84 (C6)
    dl fn_1059, 1397, 0x1059 ; pitch=89 (F6)
    dl fn_105e, 1865, 0x105e ; pitch=94 (A#6)
; ---- Instrument 17: Piccolo ----
; SoundFont: Piccolo, Bank: 0, Preset: 72
    dl fn_114f, 784, 0x114f ; pitch=79 (G5)
    dl fn_1155, 1109, 0x1155 ; pitch=85 (C#6)
    dl fn_115c, 1661, 0x115c ; pitch=92 (G#6)
    dl fn_1160, 2093, 0x1160 ; pitch=96 (C7)
    dl fn_1165, 2794, 0x1165 ; pitch=101 (F7)
    dl fn_116a, 3729, 0x116a ; pitch=106 (A#7)
; ---- Instrument 18: Clarinet ----
; SoundFont: Clarinet, Bank: 0, Preset: 71
    dl fn_1235, 175, 0x1235 ; pitch=53 (F3)
    dl fn_1241, 349, 0x1241 ; pitch=65 (F4)
    dl fn_1246, 466, 0x1246 ; pitch=70 (A#4)
    dl fn_124d, 698, 0x124d ; pitch=77 (F5)
    dl fn_1251, 880, 0x1251 ; pitch=81 (A5)
; ---- Instrument 19: Bassoon ----
; SoundFont: Bassoon, Bank: 0, Preset: 70
    dl fn_1324, 65, 0x1324 ; pitch=36 (C2)
    dl fn_1329, 87, 0x1329 ; pitch=41 (F2)
    dl fn_1333, 156, 0x1333 ; pitch=51 (D#3)
    dl fn_1337, 196, 0x1337 ; pitch=55 (G3)
    dl fn_133c, 262, 0x133c ; pitch=60 (C4)
    dl fn_1343, 392, 0x1343 ; pitch=67 (G4)
; ---- Instrument 20: Glockenspiel ----
; SoundFont: Glockenspiel, Bank: 0, Preset: 9
    dl fn_144b, 622, 0x144b ; pitch=75 (D#5)
    dl fn_144f, 784, 0x144f ; pitch=79 (G5)
    dl fn_1454, 1047, 0x1454 ; pitch=84 (C6)
    dl fn_145b, 1568, 0x145b ; pitch=91 (G6)
    dl fn_1465, 2794, 0x1465 ; pitch=101 (F7)
; ---- Instrument 22: Orchestral Harp ----
; SoundFont: Orchestral Harp, Bank: 0, Preset: 46
    dl fn_1624, 65, 0x1624 ; pitch=36 (C2)
    dl fn_1629, 87, 0x1629 ; pitch=41 (F2)
    dl fn_162e, 117, 0x162e ; pitch=46 (A#2)
    dl fn_1633, 156, 0x1633 ; pitch=51 (D#3)
    dl fn_163a, 233, 0x163a ; pitch=58 (A#3)
    dl fn_1646, 466, 0x1646 ; pitch=70 (A#4)
    dl fn_164b, 622, 0x164b ; pitch=75 (D#5)
    dl fn_164f, 784, 0x164f ; pitch=79 (G5)
    dl fn_1654, 1047, 0x1654 ; pitch=84 (C6)
    dl fn_1658, 1319, 0x1658 ; pitch=88 (E6)
    dl fn_165d, 1760, 0x165d ; pitch=93 (A6)
    dl fn_1662, 2349, 0x1662 ; pitch=98 (D7)

; Sample filename strings
sample_filenames:
; ---- Instrument 1: Tuba ----
; SoundFont: Tuba, Bank: 0, Preset: 58
    fn_011f: asciz "Samples/Tuba/031.wav"
    fn_0124: asciz "Samples/Tuba/036.wav"
    fn_012b: asciz "Samples/Tuba/043.wav"
; ---- Instrument 2: String Ensemble 1 ----
; SoundFont: Strings, Bank: 0, Preset: 48
    fn_021d: asciz "Samples/Strings/029.wav"
    fn_0222: asciz "Samples/Strings/034.wav"
    fn_0224: asciz "Samples/Strings/036.wav"
    fn_0229: asciz "Samples/Strings/041.wav"
    fn_022b: asciz "Samples/Strings/043.wav"
    fn_022d: asciz "Samples/Strings/045.wav"
    fn_022f: asciz "Samples/Strings/047.wav"
    fn_0230: asciz "Samples/Strings/048.wav"
    fn_0232: asciz "Samples/Strings/050.wav"
    fn_0234: asciz "Samples/Strings/052.wav"
    fn_0235: asciz "Samples/Strings/053.wav"
    fn_0238: asciz "Samples/Strings/056.wav"
    fn_023a: asciz "Samples/Strings/058.wav"
    fn_023b: asciz "Samples/Strings/059.wav"
    fn_023c: asciz "Samples/Strings/060.wav"
    fn_023d: asciz "Samples/Strings/061.wav"
    fn_023f: asciz "Samples/Strings/063.wav"
    fn_0241: asciz "Samples/Strings/065.wav"
    fn_0242: asciz "Samples/Strings/066.wav"
    fn_0243: asciz "Samples/Strings/067.wav"
    fn_0247: asciz "Samples/Strings/071.wav"
    fn_0248: asciz "Samples/Strings/072.wav"
    fn_0249: asciz "Samples/Strings/073.wav"
    fn_024b: asciz "Samples/Strings/075.wav"
    fn_024f: asciz "Samples/Strings/079.wav"
    fn_0254: asciz "Samples/Strings/084.wav"
    fn_0256: asciz "Samples/Strings/086.wav"
    fn_025b: asciz "Samples/Strings/091.wav"
; ---- Instrument 4: French Horn ----
; SoundFont: French Horns, Bank: 0, Preset: 60
    fn_042b: asciz "Samples/French_Horns/043.wav"
    fn_0432: asciz "Samples/French_Horns/050.wav"
    fn_0437: asciz "Samples/French_Horns/055.wav"
    fn_043c: asciz "Samples/French_Horns/060.wav"
    fn_0441: asciz "Samples/French_Horns/065.wav"
    fn_0446: asciz "Samples/French_Horns/070.wav"
; ---- Instrument 5: Trumpet ----
; SoundFont: Trumpet, Bank: 0, Preset: 56
    fn_053e: asciz "Samples/Trumpet/062.wav"
    fn_0543: asciz "Samples/Trumpet/067.wav"
    fn_0548: asciz "Samples/Trumpet/072.wav"
    fn_054d: asciz "Samples/Trumpet/077.wav"
    fn_0551: asciz "Samples/Trumpet/081.wav"
; ---- Instrument 14: Trombone ----
; SoundFont: Trombone, Bank: 0, Preset: 57
    fn_0e2b: asciz "Samples/Trombone/043.wav"
    fn_0e32: asciz "Samples/Trombone/050.wav"
    fn_0e37: asciz "Samples/Trombone/055.wav"
    fn_0e3c: asciz "Samples/Trombone/060.wav"
    fn_0e41: asciz "Samples/Trombone/065.wav"
    fn_0e46: asciz "Samples/Trombone/070.wav"
; ---- Instrument 16: Flute ----
; SoundFont: Flute, Bank: 0, Preset: 73
    fn_1041: asciz "Samples/Flute/065.wav"
    fn_1049: asciz "Samples/Flute/073.wav"
    fn_104d: asciz "Samples/Flute/077.wav"
    fn_1054: asciz "Samples/Flute/084.wav"
    fn_1059: asciz "Samples/Flute/089.wav"
    fn_105e: asciz "Samples/Flute/094.wav"
; ---- Instrument 17: Piccolo ----
; SoundFont: Piccolo, Bank: 0, Preset: 72
    fn_114f: asciz "Samples/Piccolo/079.wav"
    fn_1155: asciz "Samples/Piccolo/085.wav"
    fn_115c: asciz "Samples/Piccolo/092.wav"
    fn_1160: asciz "Samples/Piccolo/096.wav"
    fn_1165: asciz "Samples/Piccolo/101.wav"
    fn_116a: asciz "Samples/Piccolo/106.wav"
; ---- Instrument 18: Clarinet ----
; SoundFont: Clarinet, Bank: 0, Preset: 71
    fn_1235: asciz "Samples/Clarinet/053.wav"
    fn_1241: asciz "Samples/Clarinet/065.wav"
    fn_1246: asciz "Samples/Clarinet/070.wav"
    fn_124d: asciz "Samples/Clarinet/077.wav"
    fn_1251: asciz "Samples/Clarinet/081.wav"
; ---- Instrument 19: Bassoon ----
; SoundFont: Bassoon, Bank: 0, Preset: 70
    fn_1324: asciz "Samples/Bassoon/036.wav"
    fn_1329: asciz "Samples/Bassoon/041.wav"
    fn_1333: asciz "Samples/Bassoon/051.wav"
    fn_1337: asciz "Samples/Bassoon/055.wav"
    fn_133c: asciz "Samples/Bassoon/060.wav"
    fn_1343: asciz "Samples/Bassoon/067.wav"
; ---- Instrument 20: Glockenspiel ----
; SoundFont: Glockenspiel, Bank: 0, Preset: 9
    fn_144b: asciz "Samples/Glockenspiel/075.wav"
    fn_144f: asciz "Samples/Glockenspiel/079.wav"
    fn_1454: asciz "Samples/Glockenspiel/084.wav"
    fn_145b: asciz "Samples/Glockenspiel/091.wav"
    fn_1465: asciz "Samples/Glockenspiel/101.wav"
; ---- Instrument 22: Orchestral Harp ----
; SoundFont: Orchestral Harp, Bank: 0, Preset: 46
    fn_1624: asciz "Samples/Orchestral_Harp/036.wav"
    fn_1629: asciz "Samples/Orchestral_Harp/041.wav"
    fn_162e: asciz "Samples/Orchestral_Harp/046.wav"
    fn_1633: asciz "Samples/Orchestral_Harp/051.wav"
    fn_163a: asciz "Samples/Orchestral_Harp/058.wav"
    fn_1646: asciz "Samples/Orchestral_Harp/070.wav"
    fn_164b: asciz "Samples/Orchestral_Harp/075.wav"
    fn_164f: asciz "Samples/Orchestral_Harp/079.wav"
    fn_1654: asciz "Samples/Orchestral_Harp/084.wav"
    fn_1658: asciz "Samples/Orchestral_Harp/088.wav"
    fn_165d: asciz "Samples/Orchestral_Harp/093.wav"
    fn_1662: asciz "Samples/Orchestral_Harp/098.wav"

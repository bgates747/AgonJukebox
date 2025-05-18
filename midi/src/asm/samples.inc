num_samples: equ 255

; Format: filename pointer, frequency, bufferId
sample_dictionary:
; ---- Instrument 1: Tuba ----
; SoundFont: Tuba, Bank: 0, Preset: 58
    dl fn_011d, 44, 0x011d ; pitch=29 (F1)
    dl fn_011f, 49, 0x011f ; pitch=31 (G1)
    dl fn_0120, 52, 0x0120 ; pitch=32 (G#1)
    dl fn_0122, 58, 0x0122 ; pitch=34 (A#1)
    dl fn_0124, 65, 0x0124 ; pitch=36 (C2)
    dl fn_0125, 69, 0x0125 ; pitch=37 (C#2)
    dl fn_0127, 78, 0x0127 ; pitch=39 (D#2)
    dl fn_0129, 87, 0x0129 ; pitch=41 (F2)
    dl fn_012b, 98, 0x012b ; pitch=43 (G2)
    dl fn_012d, 110, 0x012d ; pitch=45 (A2)
    dl fn_012e, 117, 0x012e ; pitch=46 (A#2)
; ---- Instrument 2: String Ensemble 1 ----
; SoundFont: Strings, Bank: 0, Preset: 48
    dl fn_021d, 44, 0x021d ; pitch=29 (F1)
    dl fn_021f, 49, 0x021f ; pitch=31 (G1)
    dl fn_0220, 52, 0x0220 ; pitch=32 (G#1)
    dl fn_0222, 58, 0x0222 ; pitch=34 (A#1)
    dl fn_0224, 65, 0x0224 ; pitch=36 (C2)
    dl fn_0225, 69, 0x0225 ; pitch=37 (C#2)
    dl fn_0227, 78, 0x0227 ; pitch=39 (D#2)
    dl fn_0229, 87, 0x0229 ; pitch=41 (F2)
    dl fn_022b, 98, 0x022b ; pitch=43 (G2)
    dl fn_022d, 110, 0x022d ; pitch=45 (A2)
    dl fn_0230, 131, 0x0230 ; pitch=48 (C3)
    dl fn_0231, 139, 0x0231 ; pitch=49 (C#3)
    dl fn_0232, 147, 0x0232 ; pitch=50 (D3)
    dl fn_0233, 156, 0x0233 ; pitch=51 (D#3)
    dl fn_0235, 175, 0x0235 ; pitch=53 (F3)
    dl fn_0237, 196, 0x0237 ; pitch=55 (G3)
    dl fn_0238, 208, 0x0238 ; pitch=56 (G#3)
    dl fn_0239, 220, 0x0239 ; pitch=57 (A3)
    dl fn_023a, 233, 0x023a ; pitch=58 (A#3)
    dl fn_023b, 247, 0x023b ; pitch=59 (B3)
    dl fn_023c, 262, 0x023c ; pitch=60 (C4)
    dl fn_023d, 277, 0x023d ; pitch=61 (C#4)
    dl fn_023e, 294, 0x023e ; pitch=62 (D4)
    dl fn_023f, 311, 0x023f ; pitch=63 (D#4)
    dl fn_0240, 330, 0x0240 ; pitch=64 (E4)
    dl fn_0241, 349, 0x0241 ; pitch=65 (F4)
    dl fn_0242, 370, 0x0242 ; pitch=66 (F#4)
    dl fn_0243, 392, 0x0243 ; pitch=67 (G4)
    dl fn_0244, 415, 0x0244 ; pitch=68 (G#4)
    dl fn_0245, 440, 0x0245 ; pitch=69 (A4)
    dl fn_0246, 466, 0x0246 ; pitch=70 (A#4)
    dl fn_0247, 494, 0x0247 ; pitch=71 (B4)
    dl fn_0248, 523, 0x0248 ; pitch=72 (C5)
    dl fn_0249, 554, 0x0249 ; pitch=73 (C#5)
    dl fn_024a, 587, 0x024a ; pitch=74 (D5)
    dl fn_024b, 622, 0x024b ; pitch=75 (D#5)
    dl fn_024c, 659, 0x024c ; pitch=76 (E5)
    dl fn_024d, 698, 0x024d ; pitch=77 (F5)
    dl fn_024e, 740, 0x024e ; pitch=78 (F#5)
    dl fn_024f, 784, 0x024f ; pitch=79 (G5)
    dl fn_0251, 880, 0x0251 ; pitch=81 (A5)
    dl fn_0252, 932, 0x0252 ; pitch=82 (A#5)
    dl fn_0253, 988, 0x0253 ; pitch=83 (B5)
    dl fn_0254, 1047, 0x0254 ; pitch=84 (C6)
    dl fn_0255, 1109, 0x0255 ; pitch=85 (C#6)
    dl fn_0256, 1175, 0x0256 ; pitch=86 (D6)
    dl fn_0257, 1245, 0x0257 ; pitch=87 (D#6)
    dl fn_0259, 1397, 0x0259 ; pitch=89 (F6)
    dl fn_025b, 1568, 0x025b ; pitch=91 (G6)
    dl fn_025d, 1760, 0x025d ; pitch=93 (A6)
    dl fn_025e, 1865, 0x025e ; pitch=94 (A#6)
; ---- Instrument 3: Pizzicato Strings ----
; SoundFont: Pizzicato Section, Bank: 0, Preset: 45
    dl fn_031f, 49, 0x031f ; pitch=31 (G1)
    dl fn_0321, 55, 0x0321 ; pitch=33 (A1)
    dl fn_0322, 58, 0x0322 ; pitch=34 (A#1)
    dl fn_0324, 65, 0x0324 ; pitch=36 (C2)
    dl fn_0325, 69, 0x0325 ; pitch=37 (C#2)
    dl fn_0327, 78, 0x0327 ; pitch=39 (D#2)
    dl fn_0329, 87, 0x0329 ; pitch=41 (F2)
    dl fn_032b, 98, 0x032b ; pitch=43 (G2)
    dl fn_032d, 110, 0x032d ; pitch=45 (A2)
    dl fn_032e, 117, 0x032e ; pitch=46 (A#2)
    dl fn_032f, 123, 0x032f ; pitch=47 (B2)
    dl fn_0336, 185, 0x0336 ; pitch=54 (F#3)
    dl fn_0338, 208, 0x0338 ; pitch=56 (G#3)
    dl fn_033a, 233, 0x033a ; pitch=58 (A#3)
    dl fn_033b, 247, 0x033b ; pitch=59 (B3)
    dl fn_033d, 277, 0x033d ; pitch=61 (C#4)
    dl fn_033f, 311, 0x033f ; pitch=63 (D#4)
; ---- Instrument 4: French Horn ----
; SoundFont: French Horns, Bank: 0, Preset: 60
    dl fn_042b, 98, 0x042b ; pitch=43 (G2)
    dl fn_042d, 110, 0x042d ; pitch=45 (A2)
    dl fn_042f, 123, 0x042f ; pitch=47 (B2)
    dl fn_0431, 139, 0x0431 ; pitch=49 (C#3)
    dl fn_0432, 147, 0x0432 ; pitch=50 (D3)
    dl fn_0433, 156, 0x0433 ; pitch=51 (D#3)
    dl fn_0435, 175, 0x0435 ; pitch=53 (F3)
    dl fn_0437, 196, 0x0437 ; pitch=55 (G3)
    dl fn_0438, 208, 0x0438 ; pitch=56 (G#3)
    dl fn_043a, 233, 0x043a ; pitch=58 (A#3)
    dl fn_043b, 247, 0x043b ; pitch=59 (B3)
    dl fn_043c, 262, 0x043c ; pitch=60 (C4)
    dl fn_043d, 277, 0x043d ; pitch=61 (C#4)
    dl fn_043e, 294, 0x043e ; pitch=62 (D4)
    dl fn_043f, 311, 0x043f ; pitch=63 (D#4)
    dl fn_0441, 349, 0x0441 ; pitch=65 (F4)
    dl fn_0443, 392, 0x0443 ; pitch=67 (G4)
    dl fn_0444, 415, 0x0444 ; pitch=68 (G#4)
    dl fn_0446, 466, 0x0446 ; pitch=70 (A#4)
    dl fn_0448, 523, 0x0448 ; pitch=72 (C5)
; ---- Instrument 5: Trumpet ----
; SoundFont: Trumpet, Bank: 0, Preset: 56
    dl fn_053c, 262, 0x053c ; pitch=60 (C4)
    dl fn_053e, 294, 0x053e ; pitch=62 (D4)
    dl fn_0540, 330, 0x0540 ; pitch=64 (E4)
    dl fn_0541, 349, 0x0541 ; pitch=65 (F4)
    dl fn_0543, 392, 0x0543 ; pitch=67 (G4)
    dl fn_0545, 440, 0x0545 ; pitch=69 (A4)
    dl fn_0546, 466, 0x0546 ; pitch=70 (A#4)
    dl fn_0548, 523, 0x0548 ; pitch=72 (C5)
    dl fn_054a, 587, 0x054a ; pitch=74 (D5)
    dl fn_054b, 622, 0x054b ; pitch=75 (D#5)
    dl fn_054d, 698, 0x054d ; pitch=77 (F5)
    dl fn_054e, 740, 0x054e ; pitch=78 (F#5)
    dl fn_054f, 784, 0x054f ; pitch=79 (G5)
    dl fn_0550, 831, 0x0550 ; pitch=80 (G#5)
    dl fn_0551, 880, 0x0551 ; pitch=81 (A5)
    dl fn_0552, 932, 0x0552 ; pitch=82 (A#5)
; ---- Instrument 6: Tremolo Strings ----
; SoundFont: Synth Strings 3, Bank: 8, Preset: 50
    dl fn_0634, 165, 0x0634 ; pitch=52 (E3)
    dl fn_0635, 175, 0x0635 ; pitch=53 (F3)
    dl fn_063c, 262, 0x063c ; pitch=60 (C4)
    dl fn_063d, 277, 0x063d ; pitch=61 (C#4)
    dl fn_0643, 392, 0x0643 ; pitch=67 (G4)
    dl fn_0644, 415, 0x0644 ; pitch=68 (G#4)
; ---- Instrument 14: Trombone ----
; SoundFont: Trombone, Bank: 0, Preset: 57
    dl fn_0e2a, 92, 0x0e2a ; pitch=42 (F#2)
    dl fn_0e2b, 98, 0x0e2b ; pitch=43 (G2)
    dl fn_0e2d, 110, 0x0e2d ; pitch=45 (A2)
    dl fn_0e2f, 123, 0x0e2f ; pitch=47 (B2)
    dl fn_0e30, 131, 0x0e30 ; pitch=48 (C3)
    dl fn_0e32, 147, 0x0e32 ; pitch=50 (D3)
    dl fn_0e34, 165, 0x0e34 ; pitch=52 (E3)
    dl fn_0e35, 175, 0x0e35 ; pitch=53 (F3)
    dl fn_0e37, 196, 0x0e37 ; pitch=55 (G3)
    dl fn_0e39, 220, 0x0e39 ; pitch=57 (A3)
    dl fn_0e3a, 233, 0x0e3a ; pitch=58 (A#3)
    dl fn_0e3c, 262, 0x0e3c ; pitch=60 (C4)
    dl fn_0e3e, 294, 0x0e3e ; pitch=62 (D4)
    dl fn_0e3f, 311, 0x0e3f ; pitch=63 (D#4)
    dl fn_0e41, 349, 0x0e41 ; pitch=65 (F4)
    dl fn_0e42, 370, 0x0e42 ; pitch=66 (F#4)
    dl fn_0e43, 392, 0x0e43 ; pitch=67 (G4)
    dl fn_0e44, 415, 0x0e44 ; pitch=68 (G#4)
    dl fn_0e46, 466, 0x0e46 ; pitch=70 (A#4)
    dl fn_0e48, 523, 0x0e48 ; pitch=72 (C5)
; ---- Instrument 16: Flute ----
; SoundFont: Flute, Bank: 0, Preset: 73
    dl fn_1041, 349, 0x1041 ; pitch=65 (F4)
    dl fn_1043, 392, 0x1043 ; pitch=67 (G4)
    dl fn_1045, 440, 0x1045 ; pitch=69 (A4)
    dl fn_1046, 466, 0x1046 ; pitch=70 (A#4)
    dl fn_1048, 523, 0x1048 ; pitch=72 (C5)
    dl fn_1049, 554, 0x1049 ; pitch=73 (C#5)
    dl fn_104b, 622, 0x104b ; pitch=75 (D#5)
    dl fn_104d, 698, 0x104d ; pitch=77 (F5)
    dl fn_104f, 784, 0x104f ; pitch=79 (G5)
    dl fn_1050, 831, 0x1050 ; pitch=80 (G#5)
    dl fn_1052, 932, 0x1052 ; pitch=82 (A#5)
    dl fn_1054, 1047, 0x1054 ; pitch=84 (C6)
    dl fn_1056, 1175, 0x1056 ; pitch=86 (D6)
    dl fn_1058, 1319, 0x1058 ; pitch=88 (E6)
    dl fn_1059, 1397, 0x1059 ; pitch=89 (F6)
    dl fn_105b, 1568, 0x105b ; pitch=91 (G6)
    dl fn_105c, 1661, 0x105c ; pitch=92 (G#6)
    dl fn_105e, 1865, 0x105e ; pitch=94 (A#6)
; ---- Instrument 17: Piccolo ----
; SoundFont: Piccolo, Bank: 0, Preset: 72
    dl fn_1152, 932, 0x1152 ; pitch=82 (A#5)
    dl fn_1153, 988, 0x1153 ; pitch=83 (B5)
    dl fn_1154, 1047, 0x1154 ; pitch=84 (C6)
    dl fn_1155, 1109, 0x1155 ; pitch=85 (C#6)
    dl fn_1157, 1245, 0x1157 ; pitch=87 (D#6)
    dl fn_1159, 1397, 0x1159 ; pitch=89 (F6)
    dl fn_115a, 1480, 0x115a ; pitch=90 (F#6)
    dl fn_115c, 1661, 0x115c ; pitch=92 (G#6)
    dl fn_115e, 1865, 0x115e ; pitch=94 (A#6)
    dl fn_1160, 2093, 0x1160 ; pitch=96 (C7)
    dl fn_1162, 2349, 0x1162 ; pitch=98 (D7)
    dl fn_1163, 2489, 0x1163 ; pitch=99 (D#7)
    dl fn_1165, 2794, 0x1165 ; pitch=101 (F7)
    dl fn_1167, 3136, 0x1167 ; pitch=103 (G7)
    dl fn_1168, 3322, 0x1168 ; pitch=104 (G#7)
    dl fn_116a, 3729, 0x116a ; pitch=106 (A#7)
; ---- Instrument 18: Clarinet ----
; SoundFont: Clarinet, Bank: 0, Preset: 71
    dl fn_123c, 262, 0x123c ; pitch=60 (C4)
    dl fn_123e, 294, 0x123e ; pitch=62 (D4)
    dl fn_123f, 311, 0x123f ; pitch=63 (D#4)
    dl fn_1241, 349, 0x1241 ; pitch=65 (F4)
    dl fn_1243, 392, 0x1243 ; pitch=67 (G4)
    dl fn_1244, 415, 0x1244 ; pitch=68 (G#4)
    dl fn_1246, 466, 0x1246 ; pitch=70 (A#4)
    dl fn_1247, 494, 0x1247 ; pitch=71 (B4)
    dl fn_1248, 523, 0x1248 ; pitch=72 (C5)
    dl fn_1249, 554, 0x1249 ; pitch=73 (C#5)
    dl fn_124a, 587, 0x124a ; pitch=74 (D5)
    dl fn_124c, 659, 0x124c ; pitch=76 (E5)
    dl fn_124d, 698, 0x124d ; pitch=77 (F5)
    dl fn_124f, 784, 0x124f ; pitch=79 (G5)
    dl fn_1250, 831, 0x1250 ; pitch=80 (G#5)
    dl fn_1251, 880, 0x1251 ; pitch=81 (A5)
    dl fn_1252, 932, 0x1252 ; pitch=82 (A#5)
; ---- Instrument 19: Bassoon ----
; SoundFont: Bassoon, Bank: 0, Preset: 70
    dl fn_1324, 65, 0x1324 ; pitch=36 (C2)
; ---- Instrument 20: Glockenspiel ----
; SoundFont: Glockenspiel, Bank: 0, Preset: 9
    dl fn_144b, 622, 0x144b ; pitch=75 (D#5)
    dl fn_144d, 698, 0x144d ; pitch=77 (F5)
    dl fn_144f, 784, 0x144f ; pitch=79 (G5)
    dl fn_1451, 880, 0x1451 ; pitch=81 (A5)
    dl fn_1452, 932, 0x1452 ; pitch=82 (A#5)
    dl fn_1454, 1047, 0x1454 ; pitch=84 (C6)
    dl fn_1456, 1175, 0x1456 ; pitch=86 (D6)
    dl fn_1457, 1245, 0x1457 ; pitch=87 (D#6)
    dl fn_1459, 1397, 0x1459 ; pitch=89 (F6)
    dl fn_145b, 1568, 0x145b ; pitch=91 (G6)
    dl fn_145d, 1760, 0x145d ; pitch=93 (A6)
    dl fn_145e, 1865, 0x145e ; pitch=94 (A#6)
    dl fn_1460, 2093, 0x1460 ; pitch=96 (C7)
    dl fn_1462, 2349, 0x1462 ; pitch=98 (D7)
    dl fn_1464, 2637, 0x1464 ; pitch=100 (E7)
    dl fn_1465, 2794, 0x1465 ; pitch=101 (F7)
    dl fn_1466, 2960, 0x1466 ; pitch=102 (F#7)
; ---- Instrument 21: Timpani ----
; SoundFont: Timpani, Bank: 0, Preset: 47
    dl fn_1529, 87, 0x1529 ; pitch=41 (F2)
    dl fn_152b, 98, 0x152b ; pitch=43 (G2)
    dl fn_152d, 110, 0x152d ; pitch=45 (A2)
    dl fn_152e, 117, 0x152e ; pitch=46 (A#2)
    dl fn_1530, 131, 0x1530 ; pitch=48 (C3)
    dl fn_1531, 139, 0x1531 ; pitch=49 (C#3)
    dl fn_1533, 156, 0x1533 ; pitch=51 (D#3)
; ---- Instrument 22: Orchestral Harp ----
; SoundFont: Distortion Guitar, Bank: 0, Preset: 30
    dl fn_1624, 65, 0x1624 ; pitch=36 (C2)
    dl fn_1626, 73, 0x1626 ; pitch=38 (D2)
    dl fn_1627, 78, 0x1627 ; pitch=39 (D#2)
    dl fn_1628, 82, 0x1628 ; pitch=40 (E2)
    dl fn_1629, 87, 0x1629 ; pitch=41 (F2)
    dl fn_162b, 98, 0x162b ; pitch=43 (G2)
    dl fn_162d, 110, 0x162d ; pitch=45 (A2)
    dl fn_162e, 117, 0x162e ; pitch=46 (A#2)
    dl fn_1630, 131, 0x1630 ; pitch=48 (C3)
    dl fn_1632, 147, 0x1632 ; pitch=50 (D3)
    dl fn_1633, 156, 0x1633 ; pitch=51 (D#3)
    dl fn_1635, 175, 0x1635 ; pitch=53 (F3)
    dl fn_1637, 196, 0x1637 ; pitch=55 (G3)
    dl fn_1639, 220, 0x1639 ; pitch=57 (A3)
    dl fn_163a, 233, 0x163a ; pitch=58 (A#3)
    dl fn_163c, 262, 0x163c ; pitch=60 (C4)
    dl fn_163e, 294, 0x163e ; pitch=62 (D4)
    dl fn_163f, 311, 0x163f ; pitch=63 (D#4)
    dl fn_1641, 349, 0x1641 ; pitch=65 (F4)
    dl fn_1643, 392, 0x1643 ; pitch=67 (G4)
    dl fn_1645, 440, 0x1645 ; pitch=69 (A4)
    dl fn_1646, 466, 0x1646 ; pitch=70 (A#4)
    dl fn_1648, 523, 0x1648 ; pitch=72 (C5)
    dl fn_164a, 587, 0x164a ; pitch=74 (D5)
    dl fn_164b, 622, 0x164b ; pitch=75 (D#5)
    dl fn_164d, 698, 0x164d ; pitch=77 (F5)
    dl fn_164f, 784, 0x164f ; pitch=79 (G5)
    dl fn_1651, 880, 0x1651 ; pitch=81 (A5)
    dl fn_1652, 932, 0x1652 ; pitch=82 (A#5)
    dl fn_1654, 1047, 0x1654 ; pitch=84 (C6)
    dl fn_1656, 1175, 0x1656 ; pitch=86 (D6)
    dl fn_1658, 1319, 0x1658 ; pitch=88 (E6)
    dl fn_1659, 1397, 0x1659 ; pitch=89 (F6)
    dl fn_165b, 1568, 0x165b ; pitch=91 (G6)
    dl fn_165d, 1760, 0x165d ; pitch=93 (A6)
    dl fn_165e, 1865, 0x165e ; pitch=94 (A#6)
    dl fn_1660, 2093, 0x1660 ; pitch=96 (C7)
    dl fn_1662, 2349, 0x1662 ; pitch=98 (D7)

; Sample filename strings
sample_filenames:
; ---- Instrument 1: Tuba ----
; SoundFont: Tuba, Bank: 0, Preset: 58
    fn_011d: asciz "Samples/Tuba/029.wav"
    fn_011f: asciz "Samples/Tuba/031.wav"
    fn_0120: asciz "Samples/Tuba/032.wav"
    fn_0122: asciz "Samples/Tuba/034.wav"
    fn_0124: asciz "Samples/Tuba/036.wav"
    fn_0125: asciz "Samples/Tuba/037.wav"
    fn_0127: asciz "Samples/Tuba/039.wav"
    fn_0129: asciz "Samples/Tuba/041.wav"
    fn_012b: asciz "Samples/Tuba/043.wav"
    fn_012d: asciz "Samples/Tuba/045.wav"
    fn_012e: asciz "Samples/Tuba/046.wav"
; ---- Instrument 2: String Ensemble 1 ----
; SoundFont: Strings, Bank: 0, Preset: 48
    fn_021d: asciz "Samples/Strings/029.wav"
    fn_021f: asciz "Samples/Strings/031.wav"
    fn_0220: asciz "Samples/Strings/032.wav"
    fn_0222: asciz "Samples/Strings/034.wav"
    fn_0224: asciz "Samples/Strings/036.wav"
    fn_0225: asciz "Samples/Strings/037.wav"
    fn_0227: asciz "Samples/Strings/039.wav"
    fn_0229: asciz "Samples/Strings/041.wav"
    fn_022b: asciz "Samples/Strings/043.wav"
    fn_022d: asciz "Samples/Strings/045.wav"
    fn_0230: asciz "Samples/Strings/048.wav"
    fn_0231: asciz "Samples/Strings/049.wav"
    fn_0232: asciz "Samples/Strings/050.wav"
    fn_0233: asciz "Samples/Strings/051.wav"
    fn_0235: asciz "Samples/Strings/053.wav"
    fn_0237: asciz "Samples/Strings/055.wav"
    fn_0238: asciz "Samples/Strings/056.wav"
    fn_0239: asciz "Samples/Strings/057.wav"
    fn_023a: asciz "Samples/Strings/058.wav"
    fn_023b: asciz "Samples/Strings/059.wav"
    fn_023c: asciz "Samples/Strings/060.wav"
    fn_023d: asciz "Samples/Strings/061.wav"
    fn_023e: asciz "Samples/Strings/062.wav"
    fn_023f: asciz "Samples/Strings/063.wav"
    fn_0240: asciz "Samples/Strings/064.wav"
    fn_0241: asciz "Samples/Strings/065.wav"
    fn_0242: asciz "Samples/Strings/066.wav"
    fn_0243: asciz "Samples/Strings/067.wav"
    fn_0244: asciz "Samples/Strings/068.wav"
    fn_0245: asciz "Samples/Strings/069.wav"
    fn_0246: asciz "Samples/Strings/070.wav"
    fn_0247: asciz "Samples/Strings/071.wav"
    fn_0248: asciz "Samples/Strings/072.wav"
    fn_0249: asciz "Samples/Strings/073.wav"
    fn_024a: asciz "Samples/Strings/074.wav"
    fn_024b: asciz "Samples/Strings/075.wav"
    fn_024c: asciz "Samples/Strings/076.wav"
    fn_024d: asciz "Samples/Strings/077.wav"
    fn_024e: asciz "Samples/Strings/078.wav"
    fn_024f: asciz "Samples/Strings/079.wav"
    fn_0251: asciz "Samples/Strings/081.wav"
    fn_0252: asciz "Samples/Strings/082.wav"
    fn_0253: asciz "Samples/Strings/083.wav"
    fn_0254: asciz "Samples/Strings/084.wav"
    fn_0255: asciz "Samples/Strings/085.wav"
    fn_0256: asciz "Samples/Strings/086.wav"
    fn_0257: asciz "Samples/Strings/087.wav"
    fn_0259: asciz "Samples/Strings/089.wav"
    fn_025b: asciz "Samples/Strings/091.wav"
    fn_025d: asciz "Samples/Strings/093.wav"
    fn_025e: asciz "Samples/Strings/094.wav"
; ---- Instrument 3: Pizzicato Strings ----
; SoundFont: Pizzicato Section, Bank: 0, Preset: 45
    fn_031f: asciz "Samples/Pizzicato_Section/031.wav"
    fn_0321: asciz "Samples/Pizzicato_Section/033.wav"
    fn_0322: asciz "Samples/Pizzicato_Section/034.wav"
    fn_0324: asciz "Samples/Pizzicato_Section/036.wav"
    fn_0325: asciz "Samples/Pizzicato_Section/037.wav"
    fn_0327: asciz "Samples/Pizzicato_Section/039.wav"
    fn_0329: asciz "Samples/Pizzicato_Section/041.wav"
    fn_032b: asciz "Samples/Pizzicato_Section/043.wav"
    fn_032d: asciz "Samples/Pizzicato_Section/045.wav"
    fn_032e: asciz "Samples/Pizzicato_Section/046.wav"
    fn_032f: asciz "Samples/Pizzicato_Section/047.wav"
    fn_0336: asciz "Samples/Pizzicato_Section/054.wav"
    fn_0338: asciz "Samples/Pizzicato_Section/056.wav"
    fn_033a: asciz "Samples/Pizzicato_Section/058.wav"
    fn_033b: asciz "Samples/Pizzicato_Section/059.wav"
    fn_033d: asciz "Samples/Pizzicato_Section/061.wav"
    fn_033f: asciz "Samples/Pizzicato_Section/063.wav"
; ---- Instrument 4: French Horn ----
; SoundFont: French Horns, Bank: 0, Preset: 60
    fn_042b: asciz "Samples/French_Horns/043.wav"
    fn_042d: asciz "Samples/French_Horns/045.wav"
    fn_042f: asciz "Samples/French_Horns/047.wav"
    fn_0431: asciz "Samples/French_Horns/049.wav"
    fn_0432: asciz "Samples/French_Horns/050.wav"
    fn_0433: asciz "Samples/French_Horns/051.wav"
    fn_0435: asciz "Samples/French_Horns/053.wav"
    fn_0437: asciz "Samples/French_Horns/055.wav"
    fn_0438: asciz "Samples/French_Horns/056.wav"
    fn_043a: asciz "Samples/French_Horns/058.wav"
    fn_043b: asciz "Samples/French_Horns/059.wav"
    fn_043c: asciz "Samples/French_Horns/060.wav"
    fn_043d: asciz "Samples/French_Horns/061.wav"
    fn_043e: asciz "Samples/French_Horns/062.wav"
    fn_043f: asciz "Samples/French_Horns/063.wav"
    fn_0441: asciz "Samples/French_Horns/065.wav"
    fn_0443: asciz "Samples/French_Horns/067.wav"
    fn_0444: asciz "Samples/French_Horns/068.wav"
    fn_0446: asciz "Samples/French_Horns/070.wav"
    fn_0448: asciz "Samples/French_Horns/072.wav"
; ---- Instrument 5: Trumpet ----
; SoundFont: Trumpet, Bank: 0, Preset: 56
    fn_053c: asciz "Samples/Trumpet/060.wav"
    fn_053e: asciz "Samples/Trumpet/062.wav"
    fn_0540: asciz "Samples/Trumpet/064.wav"
    fn_0541: asciz "Samples/Trumpet/065.wav"
    fn_0543: asciz "Samples/Trumpet/067.wav"
    fn_0545: asciz "Samples/Trumpet/069.wav"
    fn_0546: asciz "Samples/Trumpet/070.wav"
    fn_0548: asciz "Samples/Trumpet/072.wav"
    fn_054a: asciz "Samples/Trumpet/074.wav"
    fn_054b: asciz "Samples/Trumpet/075.wav"
    fn_054d: asciz "Samples/Trumpet/077.wav"
    fn_054e: asciz "Samples/Trumpet/078.wav"
    fn_054f: asciz "Samples/Trumpet/079.wav"
    fn_0550: asciz "Samples/Trumpet/080.wav"
    fn_0551: asciz "Samples/Trumpet/081.wav"
    fn_0552: asciz "Samples/Trumpet/082.wav"
; ---- Instrument 6: Tremolo Strings ----
; SoundFont: Synth Strings 3, Bank: 8, Preset: 50
    fn_0634: asciz "Samples/Synth_Strings_3/052.wav"
    fn_0635: asciz "Samples/Synth_Strings_3/053.wav"
    fn_063c: asciz "Samples/Synth_Strings_3/060.wav"
    fn_063d: asciz "Samples/Synth_Strings_3/061.wav"
    fn_0643: asciz "Samples/Synth_Strings_3/067.wav"
    fn_0644: asciz "Samples/Synth_Strings_3/068.wav"
; ---- Instrument 14: Trombone ----
; SoundFont: Trombone, Bank: 0, Preset: 57
    fn_0e2a: asciz "Samples/Trombone/042.wav"
    fn_0e2b: asciz "Samples/Trombone/043.wav"
    fn_0e2d: asciz "Samples/Trombone/045.wav"
    fn_0e2f: asciz "Samples/Trombone/047.wav"
    fn_0e30: asciz "Samples/Trombone/048.wav"
    fn_0e32: asciz "Samples/Trombone/050.wav"
    fn_0e34: asciz "Samples/Trombone/052.wav"
    fn_0e35: asciz "Samples/Trombone/053.wav"
    fn_0e37: asciz "Samples/Trombone/055.wav"
    fn_0e39: asciz "Samples/Trombone/057.wav"
    fn_0e3a: asciz "Samples/Trombone/058.wav"
    fn_0e3c: asciz "Samples/Trombone/060.wav"
    fn_0e3e: asciz "Samples/Trombone/062.wav"
    fn_0e3f: asciz "Samples/Trombone/063.wav"
    fn_0e41: asciz "Samples/Trombone/065.wav"
    fn_0e42: asciz "Samples/Trombone/066.wav"
    fn_0e43: asciz "Samples/Trombone/067.wav"
    fn_0e44: asciz "Samples/Trombone/068.wav"
    fn_0e46: asciz "Samples/Trombone/070.wav"
    fn_0e48: asciz "Samples/Trombone/072.wav"
; ---- Instrument 16: Flute ----
; SoundFont: Flute, Bank: 0, Preset: 73
    fn_1041: asciz "Samples/Flute/065.wav"
    fn_1043: asciz "Samples/Flute/067.wav"
    fn_1045: asciz "Samples/Flute/069.wav"
    fn_1046: asciz "Samples/Flute/070.wav"
    fn_1048: asciz "Samples/Flute/072.wav"
    fn_1049: asciz "Samples/Flute/073.wav"
    fn_104b: asciz "Samples/Flute/075.wav"
    fn_104d: asciz "Samples/Flute/077.wav"
    fn_104f: asciz "Samples/Flute/079.wav"
    fn_1050: asciz "Samples/Flute/080.wav"
    fn_1052: asciz "Samples/Flute/082.wav"
    fn_1054: asciz "Samples/Flute/084.wav"
    fn_1056: asciz "Samples/Flute/086.wav"
    fn_1058: asciz "Samples/Flute/088.wav"
    fn_1059: asciz "Samples/Flute/089.wav"
    fn_105b: asciz "Samples/Flute/091.wav"
    fn_105c: asciz "Samples/Flute/092.wav"
    fn_105e: asciz "Samples/Flute/094.wav"
; ---- Instrument 17: Piccolo ----
; SoundFont: Piccolo, Bank: 0, Preset: 72
    fn_1152: asciz "Samples/Piccolo/082.wav"
    fn_1153: asciz "Samples/Piccolo/083.wav"
    fn_1154: asciz "Samples/Piccolo/084.wav"
    fn_1155: asciz "Samples/Piccolo/085.wav"
    fn_1157: asciz "Samples/Piccolo/087.wav"
    fn_1159: asciz "Samples/Piccolo/089.wav"
    fn_115a: asciz "Samples/Piccolo/090.wav"
    fn_115c: asciz "Samples/Piccolo/092.wav"
    fn_115e: asciz "Samples/Piccolo/094.wav"
    fn_1160: asciz "Samples/Piccolo/096.wav"
    fn_1162: asciz "Samples/Piccolo/098.wav"
    fn_1163: asciz "Samples/Piccolo/099.wav"
    fn_1165: asciz "Samples/Piccolo/101.wav"
    fn_1167: asciz "Samples/Piccolo/103.wav"
    fn_1168: asciz "Samples/Piccolo/104.wav"
    fn_116a: asciz "Samples/Piccolo/106.wav"
; ---- Instrument 18: Clarinet ----
; SoundFont: Clarinet, Bank: 0, Preset: 71
    fn_123c: asciz "Samples/Clarinet/060.wav"
    fn_123e: asciz "Samples/Clarinet/062.wav"
    fn_123f: asciz "Samples/Clarinet/063.wav"
    fn_1241: asciz "Samples/Clarinet/065.wav"
    fn_1243: asciz "Samples/Clarinet/067.wav"
    fn_1244: asciz "Samples/Clarinet/068.wav"
    fn_1246: asciz "Samples/Clarinet/070.wav"
    fn_1247: asciz "Samples/Clarinet/071.wav"
    fn_1248: asciz "Samples/Clarinet/072.wav"
    fn_1249: asciz "Samples/Clarinet/073.wav"
    fn_124a: asciz "Samples/Clarinet/074.wav"
    fn_124c: asciz "Samples/Clarinet/076.wav"
    fn_124d: asciz "Samples/Clarinet/077.wav"
    fn_124f: asciz "Samples/Clarinet/079.wav"
    fn_1250: asciz "Samples/Clarinet/080.wav"
    fn_1251: asciz "Samples/Clarinet/081.wav"
    fn_1252: asciz "Samples/Clarinet/082.wav"
; ---- Instrument 19: Bassoon ----
; SoundFont: Bassoon, Bank: 0, Preset: 70
    fn_1324: asciz "Samples/Bassoon/036.wav"
; ---- Instrument 20: Glockenspiel ----
; SoundFont: Glockenspiel, Bank: 0, Preset: 9
    fn_144b: asciz "Samples/Glockenspiel/075.wav"
    fn_144d: asciz "Samples/Glockenspiel/077.wav"
    fn_144f: asciz "Samples/Glockenspiel/079.wav"
    fn_1451: asciz "Samples/Glockenspiel/081.wav"
    fn_1452: asciz "Samples/Glockenspiel/082.wav"
    fn_1454: asciz "Samples/Glockenspiel/084.wav"
    fn_1456: asciz "Samples/Glockenspiel/086.wav"
    fn_1457: asciz "Samples/Glockenspiel/087.wav"
    fn_1459: asciz "Samples/Glockenspiel/089.wav"
    fn_145b: asciz "Samples/Glockenspiel/091.wav"
    fn_145d: asciz "Samples/Glockenspiel/093.wav"
    fn_145e: asciz "Samples/Glockenspiel/094.wav"
    fn_1460: asciz "Samples/Glockenspiel/096.wav"
    fn_1462: asciz "Samples/Glockenspiel/098.wav"
    fn_1464: asciz "Samples/Glockenspiel/100.wav"
    fn_1465: asciz "Samples/Glockenspiel/101.wav"
    fn_1466: asciz "Samples/Glockenspiel/102.wav"
; ---- Instrument 21: Timpani ----
; SoundFont: Timpani, Bank: 0, Preset: 47
    fn_1529: asciz "Samples/Timpani/041.wav"
    fn_152b: asciz "Samples/Timpani/043.wav"
    fn_152d: asciz "Samples/Timpani/045.wav"
    fn_152e: asciz "Samples/Timpani/046.wav"
    fn_1530: asciz "Samples/Timpani/048.wav"
    fn_1531: asciz "Samples/Timpani/049.wav"
    fn_1533: asciz "Samples/Timpani/051.wav"
; ---- Instrument 22: Orchestral Harp ----
; SoundFont: Distortion Guitar, Bank: 0, Preset: 30
    fn_1624: asciz "Samples/Distortion_Guitar/036.wav"
    fn_1626: asciz "Samples/Distortion_Guitar/038.wav"
    fn_1627: asciz "Samples/Distortion_Guitar/039.wav"
    fn_1628: asciz "Samples/Distortion_Guitar/040.wav"
    fn_1629: asciz "Samples/Distortion_Guitar/041.wav"
    fn_162b: asciz "Samples/Distortion_Guitar/043.wav"
    fn_162d: asciz "Samples/Distortion_Guitar/045.wav"
    fn_162e: asciz "Samples/Distortion_Guitar/046.wav"
    fn_1630: asciz "Samples/Distortion_Guitar/048.wav"
    fn_1632: asciz "Samples/Distortion_Guitar/050.wav"
    fn_1633: asciz "Samples/Distortion_Guitar/051.wav"
    fn_1635: asciz "Samples/Distortion_Guitar/053.wav"
    fn_1637: asciz "Samples/Distortion_Guitar/055.wav"
    fn_1639: asciz "Samples/Distortion_Guitar/057.wav"
    fn_163a: asciz "Samples/Distortion_Guitar/058.wav"
    fn_163c: asciz "Samples/Distortion_Guitar/060.wav"
    fn_163e: asciz "Samples/Distortion_Guitar/062.wav"
    fn_163f: asciz "Samples/Distortion_Guitar/063.wav"
    fn_1641: asciz "Samples/Distortion_Guitar/065.wav"
    fn_1643: asciz "Samples/Distortion_Guitar/067.wav"
    fn_1645: asciz "Samples/Distortion_Guitar/069.wav"
    fn_1646: asciz "Samples/Distortion_Guitar/070.wav"
    fn_1648: asciz "Samples/Distortion_Guitar/072.wav"
    fn_164a: asciz "Samples/Distortion_Guitar/074.wav"
    fn_164b: asciz "Samples/Distortion_Guitar/075.wav"
    fn_164d: asciz "Samples/Distortion_Guitar/077.wav"
    fn_164f: asciz "Samples/Distortion_Guitar/079.wav"
    fn_1651: asciz "Samples/Distortion_Guitar/081.wav"
    fn_1652: asciz "Samples/Distortion_Guitar/082.wav"
    fn_1654: asciz "Samples/Distortion_Guitar/084.wav"
    fn_1656: asciz "Samples/Distortion_Guitar/086.wav"
    fn_1658: asciz "Samples/Distortion_Guitar/088.wav"
    fn_1659: asciz "Samples/Distortion_Guitar/089.wav"
    fn_165b: asciz "Samples/Distortion_Guitar/091.wav"
    fn_165d: asciz "Samples/Distortion_Guitar/093.wav"
    fn_165e: asciz "Samples/Distortion_Guitar/094.wav"
    fn_1660: asciz "Samples/Distortion_Guitar/096.wav"
    fn_1662: asciz "Samples/Distortion_Guitar/098.wav"

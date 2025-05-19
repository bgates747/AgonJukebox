num_samples: equ 67

; Format: filename pointer, frequency, bufferId
sample_dictionary:
; ---- Instrument 1: Bassoon ----
; SoundFont: Bassoon, Bank: 0, Preset: 70
    dl fn_013f, 311, 0x013f ; pitch=63 (D#4)
    dl fn_0144, 415, 0x0144 ; pitch=68 (G#4)
    dl fn_0149, 554, 0x0149 ; pitch=73 (C#5)
    dl fn_0152, 932, 0x0152 ; pitch=82 (A#5)
; ---- Instrument 2: Flute ----
; SoundFont: Flute, Bank: 0, Preset: 73
    dl fn_0250, 831, 0x0250 ; pitch=80 (G#5)
; ---- Instrument 3: French Horn ----
; SoundFont: French Horns, Bank: 0, Preset: 60
    dl fn_0335, 175, 0x0335 ; pitch=53 (F3)
    dl fn_033a, 233, 0x033a ; pitch=58 (A#3)
    dl fn_033f, 311, 0x033f ; pitch=63 (D#4)
    dl fn_0345, 440, 0x0345 ; pitch=69 (A4)
    dl fn_034a, 587, 0x034a ; pitch=74 (D5)
; ---- Instrument 4: Trumpet ----
; SoundFont: Trumpet, Bank: 0, Preset: 56
    dl fn_043a, 233, 0x043a ; pitch=58 (A#3)
    dl fn_0441, 349, 0x0441 ; pitch=65 (F4)
    dl fn_0446, 466, 0x0446 ; pitch=70 (A#4)
    dl fn_044b, 622, 0x044b ; pitch=75 (D#5)
    dl fn_0451, 880, 0x0451 ; pitch=81 (A5)
    dl fn_0456, 1175, 0x0456 ; pitch=86 (D6)
    dl fn_045d, 1760, 0x045d ; pitch=93 (A6)
; ---- Instrument 5: Trombone ----
; SoundFont: Trombone, Bank: 0, Preset: 57
    dl fn_052a, 92, 0x052a ; pitch=42 (F#2)
    dl fn_0532, 147, 0x0532 ; pitch=50 (D3)
    dl fn_0537, 196, 0x0537 ; pitch=55 (G3)
    dl fn_053f, 311, 0x053f ; pitch=63 (D#4)
    dl fn_0545, 440, 0x0545 ; pitch=69 (A4)
    dl fn_054a, 587, 0x054a ; pitch=74 (D5)
    dl fn_054f, 784, 0x054f ; pitch=79 (G5)
    dl fn_0556, 1175, 0x0556 ; pitch=86 (D6)
; ---- Instrument 6: Orchestral Harp ----
; SoundFont: Harp, Bank: 0, Preset: 46
    dl fn_062a, 92, 0x062a ; pitch=42 (F#2)
    dl fn_0634, 165, 0x0634 ; pitch=52 (E3)
    dl fn_0639, 220, 0x0639 ; pitch=57 (A3)
    dl fn_0641, 349, 0x0641 ; pitch=65 (F4)
    dl fn_0646, 466, 0x0646 ; pitch=70 (A#4)
    dl fn_064d, 698, 0x064d ; pitch=77 (F5)
    dl fn_0652, 932, 0x0652 ; pitch=82 (A#5)
    dl fn_0659, 1397, 0x0659 ; pitch=89 (F6)
; ---- Instrument 7: Bright Acoustic Piano ----
; SoundFont: Bright Yamaha Grand, Bank: 0, Preset: 1
    dl fn_0741, 349, 0x0741 ; pitch=65 (F4)
    dl fn_0748, 523, 0x0748 ; pitch=72 (C5)
    dl fn_074d, 698, 0x074d ; pitch=77 (F5)
    dl fn_0752, 932, 0x0752 ; pitch=82 (A#5)
    dl fn_0757, 1245, 0x0757 ; pitch=87 (D#6)
; ---- Instrument 8: String Ensemble 1 ----
; SoundFont: Strings, Bank: 0, Preset: 48
    dl fn_0819, 35, 0x0819 ; pitch=25 (C#1)
    dl fn_081f, 49, 0x081f ; pitch=31 (G1)
    dl fn_0826, 73, 0x0826 ; pitch=38 (D2)
    dl fn_082b, 98, 0x082b ; pitch=43 (G2)
    dl fn_0832, 147, 0x0832 ; pitch=50 (D3)
    dl fn_0835, 175, 0x0835 ; pitch=53 (F3)
    dl fn_0837, 196, 0x0837 ; pitch=55 (G3)
    dl fn_083a, 233, 0x083a ; pitch=58 (A#3)
    dl fn_083f, 311, 0x083f ; pitch=63 (D#4)
    dl fn_0841, 349, 0x0841 ; pitch=65 (F4)
    dl fn_0846, 466, 0x0846 ; pitch=70 (A#4)
    dl fn_0848, 523, 0x0848 ; pitch=72 (C5)
    dl fn_084d, 698, 0x084d ; pitch=77 (F5)
    dl fn_0852, 932, 0x0852 ; pitch=82 (A#5)
    dl fn_0857, 1245, 0x0857 ; pitch=87 (D#6)
    dl fn_085e, 1865, 0x085e ; pitch=94 (A#6)
    dl fn_0864, 2637, 0x0864 ; pitch=100 (E7)
    dl fn_0869, 3520, 0x0869 ; pitch=105 (A7)
; ---- Instrument 10: Tremolo Strings ----
; SoundFont: Tremolo, Bank: 0, Preset: 44
    dl fn_0a19, 35, 0x0a19 ; pitch=25 (C#1)
    dl fn_0a1f, 49, 0x0a1f ; pitch=31 (G1)
    dl fn_0a26, 73, 0x0a26 ; pitch=38 (D2)
    dl fn_0a2f, 123, 0x0a2f ; pitch=47 (B2)
    dl fn_0a35, 175, 0x0a35 ; pitch=53 (F3)
    dl fn_0a3b, 247, 0x0a3b ; pitch=59 (B3)
    dl fn_0a41, 349, 0x0a41 ; pitch=65 (F4)
; ---- Instrument 11: Timpani ----
; SoundFont: Timpani, Bank: 0, Preset: 47
    dl fn_0b1d, 44, 0x0b1d ; pitch=29 (F1)
    dl fn_0b29, 87, 0x0b29 ; pitch=41 (F2)
    dl fn_0b2e, 117, 0x0b2e ; pitch=46 (A#2)
    dl fn_0b34, 165, 0x0b34 ; pitch=52 (E3)

; Sample filename strings
sample_filenames:
; ---- Instrument 1: Bassoon ----
; SoundFont: Bassoon, Bank: 0, Preset: 70
    fn_013f: asciz "Samples/Bassoon/063.wav"
    fn_0144: asciz "Samples/Bassoon/068.wav"
    fn_0149: asciz "Samples/Bassoon/073.wav"
    fn_0152: asciz "Samples/Bassoon/082.wav"
; ---- Instrument 2: Flute ----
; SoundFont: Flute, Bank: 0, Preset: 73
    fn_0250: asciz "Samples/Flute/080.wav"
; ---- Instrument 3: French Horn ----
; SoundFont: French Horns, Bank: 0, Preset: 60
    fn_0335: asciz "Samples/French_Horns/053.wav"
    fn_033a: asciz "Samples/French_Horns/058.wav"
    fn_033f: asciz "Samples/French_Horns/063.wav"
    fn_0345: asciz "Samples/French_Horns/069.wav"
    fn_034a: asciz "Samples/French_Horns/074.wav"
; ---- Instrument 4: Trumpet ----
; SoundFont: Trumpet, Bank: 0, Preset: 56
    fn_043a: asciz "Samples/Trumpet/058.wav"
    fn_0441: asciz "Samples/Trumpet/065.wav"
    fn_0446: asciz "Samples/Trumpet/070.wav"
    fn_044b: asciz "Samples/Trumpet/075.wav"
    fn_0451: asciz "Samples/Trumpet/081.wav"
    fn_0456: asciz "Samples/Trumpet/086.wav"
    fn_045d: asciz "Samples/Trumpet/093.wav"
; ---- Instrument 5: Trombone ----
; SoundFont: Trombone, Bank: 0, Preset: 57
    fn_052a: asciz "Samples/Trombone/042.wav"
    fn_0532: asciz "Samples/Trombone/050.wav"
    fn_0537: asciz "Samples/Trombone/055.wav"
    fn_053f: asciz "Samples/Trombone/063.wav"
    fn_0545: asciz "Samples/Trombone/069.wav"
    fn_054a: asciz "Samples/Trombone/074.wav"
    fn_054f: asciz "Samples/Trombone/079.wav"
    fn_0556: asciz "Samples/Trombone/086.wav"
; ---- Instrument 6: Orchestral Harp ----
; SoundFont: Harp, Bank: 0, Preset: 46
    fn_062a: asciz "Samples/Harp/042.wav"
    fn_0634: asciz "Samples/Harp/052.wav"
    fn_0639: asciz "Samples/Harp/057.wav"
    fn_0641: asciz "Samples/Harp/065.wav"
    fn_0646: asciz "Samples/Harp/070.wav"
    fn_064d: asciz "Samples/Harp/077.wav"
    fn_0652: asciz "Samples/Harp/082.wav"
    fn_0659: asciz "Samples/Harp/089.wav"
; ---- Instrument 7: Bright Acoustic Piano ----
; SoundFont: Bright Yamaha Grand, Bank: 0, Preset: 1
    fn_0741: asciz "Samples/Bright_Yamaha_Grand/065.wav"
    fn_0748: asciz "Samples/Bright_Yamaha_Grand/072.wav"
    fn_074d: asciz "Samples/Bright_Yamaha_Grand/077.wav"
    fn_0752: asciz "Samples/Bright_Yamaha_Grand/082.wav"
    fn_0757: asciz "Samples/Bright_Yamaha_Grand/087.wav"
; ---- Instrument 8: String Ensemble 1 ----
; SoundFont: Strings, Bank: 0, Preset: 48
    fn_0819: asciz "Samples/Strings/025.wav"
    fn_081f: asciz "Samples/Strings/031.wav"
    fn_0826: asciz "Samples/Strings/038.wav"
    fn_082b: asciz "Samples/Strings/043.wav"
    fn_0832: asciz "Samples/Strings/050.wav"
    fn_0835: asciz "Samples/Strings/053.wav"
    fn_0837: asciz "Samples/Strings/055.wav"
    fn_083a: asciz "Samples/Strings/058.wav"
    fn_083f: asciz "Samples/Strings/063.wav"
    fn_0841: asciz "Samples/Strings/065.wav"
    fn_0846: asciz "Samples/Strings/070.wav"
    fn_0848: asciz "Samples/Strings/072.wav"
    fn_084d: asciz "Samples/Strings/077.wav"
    fn_0852: asciz "Samples/Strings/082.wav"
    fn_0857: asciz "Samples/Strings/087.wav"
    fn_085e: asciz "Samples/Strings/094.wav"
    fn_0864: asciz "Samples/Strings/100.wav"
    fn_0869: asciz "Samples/Strings/105.wav"
; ---- Instrument 10: Tremolo Strings ----
; SoundFont: Tremolo, Bank: 0, Preset: 44
    fn_0a19: asciz "Samples/Tremolo/025.wav"
    fn_0a1f: asciz "Samples/Tremolo/031.wav"
    fn_0a26: asciz "Samples/Tremolo/038.wav"
    fn_0a2f: asciz "Samples/Tremolo/047.wav"
    fn_0a35: asciz "Samples/Tremolo/053.wav"
    fn_0a3b: asciz "Samples/Tremolo/059.wav"
    fn_0a41: asciz "Samples/Tremolo/065.wav"
; ---- Instrument 11: Timpani ----
; SoundFont: Timpani, Bank: 0, Preset: 47
    fn_0b1d: asciz "Samples/Timpani/029.wav"
    fn_0b29: asciz "Samples/Timpani/041.wav"
    fn_0b2e: asciz "Samples/Timpani/046.wav"
    fn_0b34: asciz "Samples/Timpani/052.wav"

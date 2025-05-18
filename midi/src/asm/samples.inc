num_samples: equ 30

; Format: filename pointer, frequency, bufferId
sample_dictionary:
; ---- Instrument 1: Bassoon ----
; SoundFont: Bassoon, Bank: 0, Preset: 70
    dl fn_013f, 311, 0x013f ; pitch=63 (D#4)
    dl fn_014b, 622, 0x014b ; pitch=75 (D#5)
; ---- Instrument 2: Flute ----
; SoundFont: Flute, Bank: 0, Preset: 73
    dl fn_0250, 831, 0x0250 ; pitch=80 (G#5)
; ---- Instrument 3: French_Horns ----
; SoundFont: French Horns, Bank: 0, Preset: 60
    dl fn_0333, 156, 0x0333 ; pitch=51 (D#3)
    dl fn_033f, 311, 0x033f ; pitch=63 (D#4)
; ---- Instrument 4: Trumpet ----
; SoundFont: Trumpet, Bank: 0, Preset: 56
    dl fn_043a, 233, 0x043a ; pitch=58 (A#3)
    dl fn_0446, 466, 0x0446 ; pitch=70 (A#4)
    dl fn_0452, 932, 0x0452 ; pitch=82 (A#5)
; ---- Instrument 5: Trombone ----
; SoundFont: Trombone, Bank: 0, Preset: 57
    dl fn_0537, 196, 0x0537 ; pitch=55 (G3)
    dl fn_0543, 392, 0x0543 ; pitch=67 (G4)
    dl fn_054f, 784, 0x054f ; pitch=79 (G5)
; ---- Instrument 6: Orchestral Harp ----
; SoundFont: Harp, Bank: 0, Preset: 46
    dl fn_0635, 175, 0x0635 ; pitch=53 (F3)
    dl fn_0641, 349, 0x0641 ; pitch=65 (F4)
    dl fn_064d, 698, 0x064d ; pitch=77 (F5)
    dl fn_0659, 1397, 0x0659 ; pitch=89 (F6)
; ---- Instrument 7: Bright Acoustic Piano ----
; SoundFont: Bright Yamaha Grand, Bank: 0, Preset: 1
    dl fn_0741, 349, 0x0741 ; pitch=65 (F4)
    dl fn_074d, 698, 0x074d ; pitch=77 (F5)
    dl fn_0759, 1397, 0x0759 ; pitch=89 (F6)
; ---- Instrument 8: String Ensemble 1 ----
; SoundFont: Synth Strings 1, Bank: 0, Preset: 50
    dl fn_081f, 49, 0x081f ; pitch=31 (G1)
    dl fn_0829, 87, 0x0829 ; pitch=41 (F2)
    dl fn_082b, 98, 0x082b ; pitch=43 (G2)
    dl fn_0835, 175, 0x0835 ; pitch=53 (F3)
    dl fn_0837, 196, 0x0837 ; pitch=55 (G3)
    dl fn_0841, 349, 0x0841 ; pitch=65 (F4)
    dl fn_0843, 392, 0x0843 ; pitch=67 (G4)
    dl fn_084d, 698, 0x084d ; pitch=77 (F5)
    dl fn_0859, 1397, 0x0859 ; pitch=89 (F6)
; ---- Instrument 11: Timpani ----
; SoundFont: Timpani, Bank: 0, Preset: 47
    dl fn_0b1d, 44, 0x0b1d ; pitch=29 (F1)
    dl fn_0b29, 87, 0x0b29 ; pitch=41 (F2)
    dl fn_0b35, 175, 0x0b35 ; pitch=53 (F3)

; Sample filename strings
sample_filenames:
; ---- Instrument 1: Bassoon ----
; SoundFont: Bassoon, Bank: 0, Preset: 70
    fn_013f: asciz "Samples/Bassoon/063.wav"
    fn_014b: asciz "Samples/Bassoon/075.wav"
; ---- Instrument 2: Flute ----
; SoundFont: Flute, Bank: 0, Preset: 73
    fn_0250: asciz "Samples/Flute/080.wav"
; ---- Instrument 3: French_Horns ----
; SoundFont: French Horns, Bank: 0, Preset: 60
    fn_0333: asciz "Samples/French_Horns/051.wav"
    fn_033f: asciz "Samples/French_Horns/063.wav"
; ---- Instrument 4: Trumpet ----
; SoundFont: Trumpet, Bank: 0, Preset: 56
    fn_043a: asciz "Samples/Trumpet/058.wav"
    fn_0446: asciz "Samples/Trumpet/070.wav"
    fn_0452: asciz "Samples/Trumpet/082.wav"
; ---- Instrument 5: Trombone ----
; SoundFont: Trombone, Bank: 0, Preset: 57
    fn_0537: asciz "Samples/Trombone/055.wav"
    fn_0543: asciz "Samples/Trombone/067.wav"
    fn_054f: asciz "Samples/Trombone/079.wav"
; ---- Instrument 6: Orchestral Harp ----
; SoundFont: Harp, Bank: 0, Preset: 46
    fn_0635: asciz "Samples/Harp/053.wav"
    fn_0641: asciz "Samples/Harp/065.wav"
    fn_064d: asciz "Samples/Harp/077.wav"
    fn_0659: asciz "Samples/Harp/089.wav"
; ---- Instrument 7: Bright Acoustic Piano ----
; SoundFont: Bright Yamaha Grand, Bank: 0, Preset: 1
    fn_0741: asciz "Samples/Bright_Yamaha_Grand/065.wav"
    fn_074d: asciz "Samples/Bright_Yamaha_Grand/077.wav"
    fn_0759: asciz "Samples/Bright_Yamaha_Grand/089.wav"
; ---- Instrument 8: String Ensemble 1 ----
; SoundFont: Synth Strings 1, Bank: 0, Preset: 50
    fn_081f: asciz "Samples/Synth_Strings_1/031.wav"
    fn_0829: asciz "Samples/Synth_Strings_1/041.wav"
    fn_082b: asciz "Samples/Synth_Strings_1/043.wav"
    fn_0835: asciz "Samples/Synth_Strings_1/053.wav"
    fn_0837: asciz "Samples/Synth_Strings_1/055.wav"
    fn_0841: asciz "Samples/Synth_Strings_1/065.wav"
    fn_0843: asciz "Samples/Synth_Strings_1/067.wav"
    fn_084d: asciz "Samples/Synth_Strings_1/077.wav"
    fn_0859: asciz "Samples/Synth_Strings_1/089.wav"
; ---- Instrument 11: Timpani ----
; SoundFont: Timpani, Bank: 0, Preset: 47
    fn_0b1d: asciz "Samples/Timpani/029.wav"
    fn_0b29: asciz "Samples/Timpani/041.wav"
    fn_0b35: asciz "Samples/Timpani/053.wav"

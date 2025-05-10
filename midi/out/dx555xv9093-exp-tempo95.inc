; MIDI Note Data in ez80 Assembly Format
; Generated from CSV file with pedal effects applied

; Pedal Effects:
;   - Sustain pedal (CC 64) extends note durations
;   - Soft pedal (CC 67) reduces note velocities

; Format of each note record:
;    tnext_lo:    equ 0     ; 1 byte. Time to next note in milliseconds (low byte)
;    tnext_hi:    equ 1     ; 1 byte. Time to next note in milliseconds (high byte)
;    duration_lo: equ 2     ; 1 byte. Length of time to sound note in milliseconds (low byte)
;    duration_hi: equ 3     ; 1 byte. Length of time to sound note in milliseconds (high byte)
;    freq_lo:     equ 4     ; 1 byte. Frequency in Hz (low byte)
;    freq_hi:     equ 5     ; 1 byte. Frequency in Hz (high byte)
;    velocity:    equ 6     ; 1 byte. Loudness of the note to sound (0-127)
;    instrument:  equ 7     ; 1 byte. Instrument used to sound note (1-255)

; Tempo factor: 1.5

; Total notes: 2048

; T 0.0000 Soft 127 (Instrument 1)
; T 0.0000 Soft 127 (Instrument 2)
    db 13, 0, 31, 17, 69, 0, 27, 1  ; Note 1: T 0.8351 C#2 = 69 Hz, tnext=13, dur=4383, soft 39 -> 27, sustain 1843 -> 4383
    db 21, 0, 18, 17, 139, 0, 27, 1  ; Note 2: T 0.8480 C#3 = 139 Hz, tnext=21, dur=4370, soft 39 -> 27, sustain 2414 -> 4370
    db 149, 1, 253, 16, 208, 0, 27, 1  ; Note 3: T 0.8690 G#3 = 208 Hz, tnext=405, dur=4349, soft 39 -> 27, sustain 818 -> 4349
; T 0.8994 Sustain 127 (Instrument 1)
; T 0.8994 Sustain 127 (Instrument 2)
    db 105, 1, 105, 15, 21, 1, 23, 1  ; Note 4: T 1.2737 C#4 = 277 Hz, tnext=361, dur=3945, soft 34 -> 23, sustain 440 -> 3945
    db 130, 1, 255, 13, 74, 1, 23, 1  ; Note 5: T 1.6351 E4 = 330 Hz, tnext=386, dur=3583, soft 33 -> 23, sustain 491 -> 3583
    db 128, 1, 125, 12, 208, 0, 23, 1  ; Note 6: T 2.0211 G#3 = 208 Hz, tnext=384, dur=3197, soft 33 -> 23, sustain 772 -> 3197
    db 61, 1, 254, 10, 21, 1, 23, 1  ; Note 7: T 2.4047 C#4 = 277 Hz, tnext=317, dur=2814, soft 33 -> 23, sustain 381 -> 2814
    db 110, 1, 193, 9, 74, 1, 23, 1  ; Note 8: T 2.7216 E4 = 330 Hz, tnext=366, dur=2497, soft 33 -> 23, sustain 560 -> 2497
    db 102, 1, 83, 8, 208, 0, 23, 1  ; Note 9: T 3.0877 G#3 = 208 Hz, tnext=358, dur=2131, soft 33 -> 23, sustain 777 -> 2131
    db 91, 1, 237, 6, 21, 1, 23, 1  ; Note 10: T 3.4456 C#4 = 277 Hz, tnext=347, dur=1773, soft 33 -> 23, sustain 396 -> 1773
    db 117, 1, 145, 5, 74, 1, 23, 1  ; Note 11: T 3.7930 E4 = 330 Hz, tnext=373, dur=1425, soft 33 -> 23, sustain 739 -> 1425
    db 115, 1, 28, 4, 208, 0, 23, 1  ; Note 12: T 4.1661 G#3 = 208 Hz, tnext=371, dur=1052, soft 33 -> 23, sustain 773 -> 1052
    db 81, 1, 170, 2, 21, 1, 23, 1  ; Note 13: T 4.5367 C#4 = 277 Hz, tnext=337, dur=682, soft 33 -> 23, sustain 408 -> 682
    db 216, 0, 188, 1, 74, 1, 23, 1  ; Note 14: T 4.8734 E4 = 330 Hz, tnext=216, dur=444, soft 33 -> 23
    db 11, 0, 225, 17, 62, 0, 28, 1  ; Note 15: T 5.0897 B1 = 62 Hz, tnext=11, dur=4577, soft 41 -> 28, sustain 1893 -> 4577
    db 132, 0, 214, 17, 123, 0, 28, 1  ; Note 16: T 5.1002 B2 = 123 Hz, tnext=132, dur=4566, soft 41 -> 28, sustain 2374 -> 4566
; T 5.2183 Sustain 0 (Instrument 1)
; T 5.2183 Sustain 0 (Instrument 2)
    db 124, 1, 82, 17, 208, 0, 23, 1  ; Note 17: T 5.2323 G#3 = 208 Hz, tnext=380, dur=4434, soft 33 -> 23, sustain 949 -> 4434
; T 5.5468 Sustain 127 (Instrument 1)
; T 5.5468 Sustain 127 (Instrument 2)
    db 123, 1, 214, 15, 21, 1, 23, 1  ; Note 18: T 5.6123 C#4 = 277 Hz, tnext=379, dur=4054, soft 33 -> 23, sustain 465 -> 4054
    db 90, 1, 91, 14, 74, 1, 23, 1  ; Note 19: T 5.9911 E4 = 330 Hz, tnext=346, dur=3675, soft 33 -> 23, sustain 792 -> 3675
; T 6.1548 Soft 0 (Instrument 1)
; T 6.1548 Soft 0 (Instrument 2)
    db 145, 1, 1, 13, 208, 0, 33, 1  ; Note 20: T 6.3372 G#3 = 208 Hz, tnext=401, dur=3329, sustain 972 -> 3329
    db 84, 1, 112, 11, 21, 1, 33, 1  ; Note 21: T 6.7382 C#4 = 277 Hz, tnext=340, dur=2928, sustain 488 -> 2928
    db 109, 1, 28, 10, 74, 1, 33, 1  ; Note 22: T 7.0784 E4 = 330 Hz, tnext=365, dur=2588, sustain 769 -> 2588
    db 117, 1, 175, 8, 208, 0, 33, 1  ; Note 23: T 7.4432 G#3 = 208 Hz, tnext=373, dur=2223, sustain 969 -> 2223
    db 101, 1, 58, 7, 21, 1, 33, 1  ; Note 24: T 7.8161 C#4 = 277 Hz, tnext=357, dur=1850, sustain 485 -> 1850
    db 153, 1, 214, 5, 74, 1, 33, 1  ; Note 25: T 8.1727 E4 = 330 Hz, tnext=409, dur=1494, sustain 1050 -> 1494
    db 96, 1, 61, 4, 208, 0, 33, 1  ; Note 26: T 8.5818 G#3 = 208 Hz, tnext=352, dur=1085, sustain 589 -> 1085
    db 140, 1, 221, 2, 21, 1, 33, 1  ; Note 27: T 8.9336 C#4 = 277 Hz, tnext=396, dur=733, sustain 666 -> 733
    db 235, 0, 146, 2, 74, 1, 34, 1  ; Note 28: T 9.3298 E4 = 330 Hz, tnext=235, dur=658
    db 34, 0, 189, 9, 55, 0, 37, 1  ; Note 29: T 9.5647 A1 = 55 Hz, tnext=34, dur=2493, sustain 1439 -> 2493
    db 137, 0, 155, 9, 110, 0, 37, 1  ; Note 30: T 9.5985 A2 = 110 Hz, tnext=137, dur=2459, sustain 1354 -> 2459
; T 9.6663 Sustain 0 (Instrument 1)
; T 9.6663 Sustain 0 (Instrument 2)
    db 139, 1, 18, 9, 220, 0, 36, 1  ; Note 31: T 9.7353 A3 = 220 Hz, tnext=395, dur=2322, sustain 851 -> 2322
    db 151, 1, 135, 7, 21, 1, 33, 1  ; Note 32: T 10.1303 C#4 = 277 Hz, tnext=407, dur=1927, sustain 483 -> 1927
; T 10.1361 Sustain 127 (Instrument 1)
; T 10.1361 Sustain 127 (Instrument 2)
    db 96, 1, 240, 5, 74, 1, 33, 1  ; Note 33: T 10.5370 E4 = 330 Hz, tnext=352, dur=1520, sustain 622 -> 1520
    db 102, 1, 145, 4, 220, 0, 33, 1  ; Note 34: T 10.8887 A3 = 220 Hz, tnext=358, dur=1169, sustain 831 -> 1169
    db 161, 1, 43, 3, 21, 1, 33, 1  ; Note 35: T 11.2463 C#4 = 277 Hz, tnext=417, dur=811, sustain 542 -> 811
    db 42, 1, 216, 1, 74, 1, 33, 1  ; Note 36: T 11.6636 E4 = 330 Hz, tnext=298, dur=472
    db 20, 0, 54, 10, 46, 0, 35, 1  ; Note 37: T 11.9616 F#1 = 46 Hz, tnext=20, dur=2614, sustain 1102 -> 2614
    db 83, 0, 34, 10, 92, 0, 35, 1  ; Note 38: T 11.9814 F#2 = 92 Hz, tnext=83, dur=2594, sustain 1106 -> 2594
; T 12.0574 Sustain 0 (Instrument 1)
; T 12.0574 Sustain 0 (Instrument 2)
    db 153, 1, 207, 9, 220, 0, 34, 1  ; Note 39: T 12.0644 A3 = 220 Hz, tnext=409, dur=2511, sustain 512 -> 2511
    db 126, 1, 54, 8, 38, 1, 33, 1  ; Note 40: T 12.4734 D4 = 294 Hz, tnext=382, dur=2102, sustain 442 -> 2102
; T 12.5529 Sustain 127 (Instrument 1)
; T 12.5529 Sustain 127 (Instrument 2)
; T 12.6055 Soft 127 (Instrument 1)
; T 12.6055 Soft 127 (Instrument 2)
    db 166, 1, 184, 6, 114, 1, 23, 1  ; Note 41: T 12.8555 F#4 = 370 Hz, tnext=422, dur=1720, soft 33 -> 23, sustain 889 -> 1720
    db 142, 1, 18, 5, 220, 0, 23, 1  ; Note 42: T 13.2772 A3 = 220 Hz, tnext=398, dur=1298, soft 33 -> 23, sustain 488 -> 1298
    db 169, 1, 132, 3, 38, 1, 23, 1  ; Note 43: T 13.6756 D4 = 294 Hz, tnext=425, dur=900, soft 33 -> 23, sustain 458 -> 900
    db 106, 1, 218, 1, 114, 1, 23, 1  ; Note 44: T 14.1008 F#4 = 370 Hz, tnext=362, dur=474, soft 33 -> 23, sustain 472 -> 474
    db 14, 0, 66, 10, 52, 0, 24, 1  ; Note 45: T 14.4629 G#1 = 52 Hz, tnext=14, dur=2626, soft 35 -> 24, sustain 2376 -> 2626
    db 89, 0, 52, 10, 104, 0, 24, 1  ; Note 46: T 14.4769 G#2 = 104 Hz, tnext=89, dur=2612, soft 35 -> 24, sustain 2326 -> 2612
    db 162, 1, 221, 1, 208, 0, 23, 1  ; Note 47: T 14.5657 G#3 = 208 Hz, tnext=418, dur=477, soft 34 -> 23
; T 14.5751 Sustain 0 (Instrument 1)
; T 14.5751 Sustain 0 (Instrument 2)
    db 153, 1, 242, 4, 6, 1, 23, 1  ; Note 48: T 14.9839 C4 = 262 Hz, tnext=409, dur=1266, soft 33 -> 23, sustain 474 -> 1266
; T 15.1113 Sustain 127 (Instrument 1)
; T 15.1113 Sustain 127 (Instrument 2)
    db 123, 1, 89, 3, 114, 1, 23, 1  ; Note 49: T 15.3928 F#4 = 370 Hz, tnext=379, dur=857, soft 33 -> 23, sustain 435 -> 857
    db 170, 1, 38, 5, 208, 0, 23, 1  ; Note 50: T 15.7713 G#3 = 208 Hz, tnext=426, dur=1318, soft 33 -> 23, sustain 961 -> 1318
    db 124, 1, 123, 3, 21, 1, 23, 1  ; Note 51: T 16.1977 C#4 = 277 Hz, tnext=380, dur=891, soft 33 -> 23, sustain 499 -> 891
; T 16.2503 Sustain 0 (Instrument 1)
; T 16.2503 Sustain 0 (Instrument 2)
    db 125, 1, 0, 2, 74, 1, 23, 1  ; Note 52: T 16.5773 E4 = 330 Hz, tnext=381, dur=512, soft 33 -> 23, sustain 510 -> 512
; T 16.5937 Sustain 127 (Instrument 1)
; T 16.5937 Sustain 127 (Instrument 2)
    db 13, 0, 128, 12, 52, 0, 24, 1  ; Note 53: T 16.9581 G#1 = 52 Hz, tnext=13, dur=3200, soft 35 -> 24, sustain 2769 -> 3200
    db 47, 0, 115, 12, 104, 0, 24, 1  ; Note 54: T 16.9710 G#2 = 104 Hz, tnext=47, dur=3187, soft 35 -> 24, sustain 2815 -> 3187
    db 210, 1, 155, 5, 208, 0, 24, 1  ; Note 55: T 17.0177 G#3 = 208 Hz, tnext=466, dur=1435, soft 35 -> 24, sustain 1164 -> 1435
; T 17.0889 Sustain 0 (Instrument 1)
; T 17.0889 Sustain 0 (Instrument 2)
    db 225, 1, 33, 2, 21, 1, 23, 1  ; Note 56: T 17.4836 C#4 = 277 Hz, tnext=481, dur=545, soft 33 -> 23
    db 234, 1, 43, 2, 55, 1, 23, 1  ; Note 57: T 17.9647 D#4 = 311 Hz, tnext=490, dur=555, soft 33 -> 23
; T 18.0301 Sustain 127 (Instrument 1)
; T 18.0301 Sustain 127 (Instrument 2)
; T 18.4528 Sustain 0 (Instrument 1)
; T 18.4528 Sustain 0 (Instrument 2)
    db 12, 2, 167, 6, 185, 0, 23, 1  ; Note 58: T 18.4551 F#3 = 185 Hz, tnext=524, dur=1703, soft 33 -> 23, sustain 1420 -> 1703
; T 18.6735 Sustain 127 (Instrument 1)
; T 18.6735 Sustain 127 (Instrument 2)
    db 48, 2, 44, 2, 6, 1, 23, 1  ; Note 59: T 18.9795 C4 = 262 Hz, tnext=560, dur=556, soft 33 -> 23
; T 19.0460 Sustain 0 (Instrument 1)
; T 19.0460 Sustain 0 (Instrument 2)
    db 8, 2, 106, 2, 55, 1, 23, 1  ; Note 60: T 19.5400 D#4 = 311 Hz, tnext=520, dur=618, soft 33 -> 23, sustain 286 -> 618
; T 19.6054 Sustain 127 (Instrument 1)
; T 19.6054 Sustain 127 (Instrument 2)
    db 27, 0, 108, 22, 69, 0, 23, 1  ; Note 61: T 20.0596 C#2 = 69 Hz, tnext=27, dur=5740, soft 33 -> 23, sustain 1682 -> 5740
    db 0, 0, 81, 22, 104, 0, 23, 1  ; Note 62: T 20.0865 G#2 = 104 Hz, tnext=0, dur=5713, soft 33 -> 23, sustain 1911 -> 5713
    db 100, 0, 81, 22, 139, 0, 23, 1  ; Note 63: T 20.0865 C#3 = 139 Hz, tnext=100, dur=5713, soft 33 -> 23, sustain 2400 -> 5713
; T 20.1577 Sustain 0 (Instrument 1)
; T 20.1577 Sustain 0 (Instrument 2)
    db 193, 1, 236, 21, 165, 0, 23, 1  ; Note 64: T 20.1869 E3 = 165 Hz, tnext=449, dur=5612, soft 33 -> 23, sustain 522 -> 5612
; T 20.6283 Sustain 127 (Instrument 1)
; T 20.6283 Sustain 127 (Instrument 2)
    db 174, 1, 43, 20, 208, 0, 23, 1  ; Note 65: T 20.6364 G#3 = 208 Hz, tnext=430, dur=5163, soft 33 -> 23, sustain 534 -> 5163
    db 148, 1, 125, 18, 21, 1, 23, 1  ; Note 66: T 21.0662 C#4 = 277 Hz, tnext=404, dur=4733, soft 33 -> 23, sustain 529 -> 4733
    db 172, 1, 233, 16, 208, 0, 23, 1  ; Note 67: T 21.4700 G#3 = 208 Hz, tnext=428, dur=4329, soft 33 -> 23, sustain 906 -> 4329
    db 156, 1, 61, 15, 21, 1, 23, 1  ; Note 68: T 21.8984 C#4 = 277 Hz, tnext=412, dur=3901, soft 33 -> 23, sustain 916 -> 3901
    db 129, 1, 161, 13, 74, 1, 23, 1  ; Note 69: T 22.3105 E4 = 330 Hz, tnext=385, dur=3489, soft 33 -> 23, sustain 519 -> 3489
    db 193, 1, 32, 12, 208, 0, 23, 1  ; Note 70: T 22.6956 G#3 = 208 Hz, tnext=449, dur=3104, soft 33 -> 23, sustain 872 -> 3104
    db 149, 1, 94, 10, 21, 1, 23, 1  ; Note 71: T 23.1450 C#4 = 277 Hz, tnext=405, dur=2654, soft 33 -> 23, sustain 1049 -> 2654
    db 34, 2, 201, 8, 74, 1, 23, 1  ; Note 72: T 23.5501 E4 = 330 Hz, tnext=546, dur=2249, soft 33 -> 23, sustain 637 -> 2249
    db 12, 0, 167, 6, 208, 0, 27, 1  ; Note 73: T 24.0963 G#3 = 208 Hz, tnext=12, dur=1703, soft 39 -> 27, sustain 878 -> 1703
    db 53, 2, 155, 6, 159, 1, 34, 2  ; Note 74: T 24.1080 G#4 = 415 Hz, tnext=565, dur=1691, soft 49 -> 34, sustain 1045 -> 1691
    db 181, 1, 102, 4, 21, 1, 23, 1  ; Note 75: T 24.6730 C#4 = 277 Hz, tnext=437, dur=1126, soft 33 -> 23, sustain 515 -> 1126
    db 191, 1, 178, 2, 74, 1, 23, 1  ; Note 76: T 25.1095 E4 = 330 Hz, tnext=447, dur=690, soft 33 -> 23, sustain 162 -> 690
    db 227, 0, 243, 0, 159, 1, 30, 2  ; Note 77: T 25.5565 G#4 = 415 Hz, tnext=227, dur=243, soft 44 -> 30, sustain 155 -> 243
    db 1, 0, 220, 14, 159, 1, 32, 2  ; Note 78: T 25.7840 G#4 = 415 Hz, tnext=1, dur=3804, soft 47 -> 32, sustain 3337 -> 3804
    db 7, 0, 135, 20, 131, 0, 28, 1  ; Note 79: T 25.7851 C3 = 131 Hz, tnext=7, dur=5255, soft 40 -> 28, sustain 4473 -> 5255
    db 0, 0, 211, 14, 208, 0, 28, 1  ; Note 80: T 25.7921 G#3 = 208 Hz, tnext=0, dur=3795, soft 40 -> 28, sustain 1010 -> 3795
    db 7, 0, 128, 20, 65, 0, 28, 1  ; Note 81: T 25.7921 C2 = 65 Hz, tnext=7, dur=5248, soft 40 -> 28, sustain 4488 -> 5248
    db 210, 1, 121, 20, 104, 0, 28, 1  ; Note 82: T 25.7991 G#2 = 104 Hz, tnext=466, dur=5241, soft 40 -> 28, sustain 4508 -> 5241
; T 25.7991 Sustain 0 (Instrument 1)
; T 25.7991 Sustain 0 (Instrument 2)
    db 194, 1, 251, 12, 55, 1, 24, 1  ; Note 83: T 26.2647 D#4 = 311 Hz, tnext=450, dur=3323, soft 35 -> 24, sustain 902 -> 3323
; T 26.2915 Sustain 127 (Instrument 1)
; T 26.2915 Sustain 127 (Instrument 2)
    db 119, 1, 56, 11, 114, 1, 23, 1  ; Note 84: T 26.7151 F#4 = 370 Hz, tnext=375, dur=2872, soft 33 -> 23, sustain 837 -> 2872
    db 144, 1, 194, 9, 208, 0, 23, 1  ; Note 85: T 27.0896 G#3 = 208 Hz, tnext=400, dur=2498, soft 33 -> 23, sustain 909 -> 2498
    db 154, 1, 50, 8, 55, 1, 23, 1  ; Note 86: T 27.4898 D#4 = 311 Hz, tnext=410, dur=2098, soft 33 -> 23, sustain 872 -> 2098
    db 115, 1, 152, 6, 114, 1, 23, 1  ; Note 87: T 27.8994 F#4 = 370 Hz, tnext=371, dur=1688, soft 33 -> 23, sustain 863 -> 1688
    db 180, 1, 37, 5, 208, 0, 23, 1  ; Note 88: T 28.2704 G#3 = 208 Hz, tnext=436, dur=1317, soft 33 -> 23, sustain 886 -> 1317
    db 143, 1, 113, 3, 55, 1, 23, 1  ; Note 89: T 28.7068 D#4 = 311 Hz, tnext=399, dur=881, soft 33 -> 23, sustain 657 -> 881
    db 220, 1, 14, 2, 114, 1, 23, 1  ; Note 90: T 29.1058 F#4 = 370 Hz, tnext=476, dur=526, soft 33 -> 23
    db 21, 0, 178, 5, 159, 1, 33, 2  ; Note 91: T 29.5818 G#4 = 415 Hz, tnext=21, dur=1458, soft 48 -> 33, sustain 864 -> 1458
; T 29.5876 Sustain 0 (Instrument 1)
; T 29.5876 Sustain 0 (Instrument 2)
    db 192, 1, 157, 5, 208, 0, 26, 1  ; Note 92: T 29.6028 G#3 = 208 Hz, tnext=448, dur=1437, soft 38 -> 26, sustain 753 -> 1437
; T 29.9504 Sustain 127 (Instrument 1)
; T 29.9504 Sustain 127 (Instrument 2)
    db 171, 1, 221, 3, 55, 1, 23, 1  ; Note 93: T 30.0507 D#4 = 311 Hz, tnext=427, dur=989, soft 33 -> 23, sustain 436 -> 989
    db 16, 1, 50, 2, 114, 1, 23, 1  ; Note 94: T 30.4775 F#4 = 370 Hz, tnext=272, dur=562, soft 33 -> 23, sustain 322 -> 562
    db 248, 0, 34, 1, 159, 1, 28, 2  ; Note 95: T 30.7493 G#4 = 415 Hz, tnext=248, dur=290, soft 40 -> 28, sustain 168 -> 290
    db 7, 0, 39, 10, 208, 0, 25, 1  ; Note 96: T 30.9977 G#3 = 208 Hz, tnext=7, dur=2599, soft 36 -> 25, sustain 1024 -> 2599
    db 5, 0, 32, 10, 139, 0, 25, 1  ; Note 97: T 31.0047 C#3 = 139 Hz, tnext=5, dur=2592, soft 36 -> 25, sustain 927 -> 2592
    db 3, 0, 27, 10, 159, 1, 30, 2  ; Note 98: T 31.0094 G#4 = 415 Hz, tnext=3, dur=2587, soft 44 -> 30, sustain 1244 -> 2587
    db 192, 1, 23, 10, 69, 0, 25, 1  ; Note 99: T 31.0129 C#2 = 69 Hz, tnext=448, dur=2583, soft 36 -> 25, sustain 1297 -> 2583
; T 31.0397 Sustain 0 (Instrument 1)
; T 31.0397 Sustain 0 (Instrument 2)
; T 31.4269 Sustain 127 (Instrument 1)
; T 31.4269 Sustain 127 (Instrument 2)
    db 220, 1, 88, 8, 21, 1, 23, 1  ; Note 100: T 31.4608 C#4 = 277 Hz, tnext=476, dur=2136, soft 33 -> 23, sustain 938 -> 2136
    db 122, 1, 124, 6, 74, 1, 23, 1  ; Note 101: T 31.9366 E4 = 330 Hz, tnext=378, dur=1660, soft 34 -> 23, sustain 491 -> 1660
    db 181, 1, 2, 5, 208, 0, 25, 1  ; Note 102: T 32.3145 G#3 = 208 Hz, tnext=437, dur=1282, soft 36 -> 25, sustain 1034 -> 1282
    db 152, 1, 230, 3, 21, 1, 23, 1  ; Note 103: T 32.7519 C#4 = 277 Hz, tnext=408, dur=998, soft 34 -> 23
    db 85, 1, 2, 2, 74, 1, 26, 1  ; Note 104: T 33.1601 E4 = 330 Hz, tnext=341, dur=514, soft 38 -> 26
    db 47, 0, 39, 11, 46, 0, 29, 1  ; Note 105: T 33.5007 F#1 = 46 Hz, tnext=47, dur=2855, soft 42 -> 29, sustain 1312 -> 2855
    db 104, 0, 249, 10, 92, 0, 30, 1  ; Note 106: T 33.5473 F#2 = 92 Hz, tnext=104, dur=2809, soft 43 -> 30, sustain 1264 -> 2809
; T 33.5963 Sustain 0 (Instrument 1)
; T 33.5963 Sustain 0 (Instrument 2)
    db 13, 0, 145, 10, 220, 0, 30, 1  ; Note 107: T 33.6511 A3 = 220 Hz, tnext=13, dur=2705, soft 44 -> 30, sustain 1021 -> 2705
    db 179, 1, 132, 10, 184, 1, 42, 2  ; Note 108: T 33.6639 A4 = 440 Hz, tnext=435, dur=2692, soft 61 -> 42, sustain 1234 -> 2692
    db 221, 1, 209, 8, 21, 1, 27, 1  ; Note 109: T 34.0988 C#4 = 277 Hz, tnext=477, dur=2257, soft 39 -> 27, sustain 937 -> 2257
; T 34.1687 Sustain 127 (Instrument 1)
; T 34.1687 Sustain 127 (Instrument 2)
    db 175, 1, 244, 6, 114, 1, 23, 1  ; Note 110: T 34.5756 F#4 = 370 Hz, tnext=431, dur=1780, soft 33 -> 23, sustain 952 -> 1780
    db 147, 1, 69, 5, 220, 0, 23, 1  ; Note 111: T 35.0070 A3 = 220 Hz, tnext=403, dur=1349, soft 33 -> 23, sustain 1034 -> 1349
    db 213, 1, 177, 3, 21, 1, 23, 1  ; Note 112: T 35.4104 C#4 = 277 Hz, tnext=469, dur=945, soft 33 -> 23, sustain 701 -> 945
    db 30, 2, 221, 1, 114, 1, 23, 1  ; Note 113: T 35.8790 F#4 = 370 Hz, tnext=542, dur=477, soft 33 -> 23, sustain 259 -> 477
; T 36.3559 Sustain 0 (Instrument 1)
; T 36.3559 Sustain 0 (Instrument 2)
    db 5, 0, 206, 10, 62, 0, 25, 1  ; Note 114: T 36.4212 B1 = 62 Hz, tnext=5, dur=2766, soft 37 -> 25, sustain 2091 -> 2766
    db 7, 0, 201, 10, 123, 0, 25, 1  ; Note 115: T 36.4258 B2 = 123 Hz, tnext=7, dur=2761, soft 37 -> 25, sustain 979 -> 2761
    db 5, 0, 194, 10, 208, 0, 25, 1  ; Note 116: T 36.4328 G#3 = 208 Hz, tnext=5, dur=2754, soft 37 -> 25, sustain 965 -> 2754
    db 194, 1, 190, 10, 159, 1, 32, 2  ; Note 117: T 36.4375 G#4 = 415 Hz, tnext=450, dur=2750, soft 46 -> 32, sustain 1362 -> 2750
; T 36.7499 Sustain 127 (Instrument 1)
; T 36.7499 Sustain 127 (Instrument 2)
    db 182, 1, 252, 8, 247, 0, 23, 1  ; Note 118: T 36.8875 B3 = 247 Hz, tnext=438, dur=2300, soft 33 -> 23, sustain 982 -> 2300
    db 189, 1, 69, 7, 74, 1, 23, 1  ; Note 119: T 37.3259 E4 = 330 Hz, tnext=445, dur=1861, soft 33 -> 23, sustain 951 -> 1861
    db 151, 1, 136, 5, 208, 0, 23, 1  ; Note 120: T 37.7712 G#3 = 208 Hz, tnext=407, dur=1416, soft 33 -> 23, sustain 823 -> 1416
    db 232, 1, 241, 3, 247, 0, 23, 1  ; Note 121: T 38.1780 B3 = 247 Hz, tnext=488, dur=1009, soft 33 -> 23, sustain 663 -> 1009
    db 55, 1, 9, 2, 74, 1, 23, 1  ; Note 122: T 38.6663 E4 = 330 Hz, tnext=311, dur=521, soft 33 -> 23, sustain 223 -> 521
    db 73, 0, 77, 13, 62, 0, 23, 1  ; Note 123: T 38.9774 B1 = 62 Hz, tnext=73, dur=3405, soft 33 -> 23, sustain 732 -> 3405
    db 118, 0, 4, 13, 123, 0, 23, 1  ; Note 124: T 39.0508 B2 = 123 Hz, tnext=118, dur=3332, soft 33 -> 23, sustain 676 -> 3332
    db 26, 0, 142, 12, 220, 0, 25, 1  ; Note 125: T 39.1686 A3 = 220 Hz, tnext=26, dur=3214, soft 36 -> 25, sustain 400 -> 3214
; T 39.1872 Sustain 0 (Instrument 1)
; T 39.1872 Sustain 0 (Instrument 2)
    db 176, 1, 116, 12, 114, 1, 28, 1  ; Note 126: T 39.1942 F#4 = 370 Hz, tnext=432, dur=3188, soft 40 -> 28, sustain 1023 -> 3188
; T 39.4657 Sustain 127 (Instrument 1)
; T 39.4657 Sustain 127 (Instrument 2)
    db 188, 1, 196, 10, 247, 0, 23, 1  ; Note 127: T 39.6266 B3 = 247 Hz, tnext=444, dur=2756, soft 33 -> 23, sustain 448 -> 2756
    db 33, 2, 8, 9, 55, 1, 23, 1  ; Note 128: T 40.0706 D#4 = 311 Hz, tnext=545, dur=2312, soft 33 -> 23, sustain 562 -> 2312
    db 33, 0, 231, 6, 220, 0, 25, 1  ; Note 129: T 40.6160 A3 = 220 Hz, tnext=33, dur=1767, soft 36 -> 25, sustain 624 -> 1767
    db 251, 1, 198, 6, 238, 1, 30, 2  ; Note 130: T 40.6486 B4 = 494 Hz, tnext=507, dur=1734, soft 44 -> 30, sustain 360 -> 1734
    db 114, 2, 203, 4, 247, 0, 23, 1  ; Note 131: T 41.1555 B3 = 247 Hz, tnext=626, dur=1227, soft 33 -> 23, sustain 242 -> 1227
    db 118, 2, 89, 2, 55, 1, 23, 1  ; Note 132: T 41.7814 D#4 = 311 Hz, tnext=630, dur=601, soft 33 -> 23, sustain 220 -> 601
; T 42.3826 Sustain 0 (Instrument 1)
; T 42.3826 Sustain 0 (Instrument 2)
    db 1, 0, 135, 18, 165, 0, 23, 1  ; Note 133: T 42.4117 E3 = 165 Hz, tnext=1, dur=4743, soft 34 -> 23, sustain 1999 -> 4743
    db 27, 0, 134, 18, 82, 0, 23, 1  ; Note 134: T 42.4128 E2 = 82 Hz, tnext=27, dur=4742, soft 34 -> 23, sustain 1652 -> 4742
    db 12, 0, 107, 18, 208, 0, 25, 1  ; Note 135: T 42.4396 G#3 = 208 Hz, tnext=12, dur=4715, soft 36 -> 25, sustain 927 -> 4715
    db 162, 1, 96, 18, 74, 1, 26, 1  ; Note 136: T 42.4513 E4 = 330 Hz, tnext=418, dur=4704, soft 38 -> 26, sustain 545 -> 4704
; T 42.6971 Sustain 127 (Instrument 1)
; T 42.6971 Sustain 127 (Instrument 2)
    db 145, 1, 189, 16, 247, 0, 23, 1  ; Note 137: T 42.8695 B3 = 247 Hz, tnext=401, dur=4285, soft 33 -> 23, sustain 821 -> 4285
    db 105, 1, 45, 15, 74, 1, 23, 1  ; Note 138: T 43.2702 E4 = 330 Hz, tnext=361, dur=3885, soft 33 -> 23, sustain 902 -> 3885
    db 144, 1, 196, 13, 208, 0, 23, 1  ; Note 139: T 43.6313 G#3 = 208 Hz, tnext=400, dur=3524, soft 33 -> 23, sustain 984 -> 3524
    db 155, 1, 52, 12, 247, 0, 23, 1  ; Note 140: T 44.0309 B3 = 247 Hz, tnext=411, dur=3124, soft 33 -> 23, sustain 874 -> 3124
    db 113, 1, 153, 10, 74, 1, 23, 1  ; Note 141: T 44.4421 E4 = 330 Hz, tnext=369, dur=2713, soft 33 -> 23, sustain 928 -> 2713
    db 162, 1, 39, 9, 208, 0, 23, 1  ; Note 142: T 44.8114 G#3 = 208 Hz, tnext=418, dur=2343, soft 33 -> 23, sustain 978 -> 2343
    db 163, 1, 133, 7, 247, 0, 23, 1  ; Note 143: T 45.2296 B3 = 247 Hz, tnext=419, dur=1925, soft 33 -> 23, sustain 897 -> 1925
    db 145, 1, 226, 5, 74, 1, 23, 1  ; Note 144: T 45.6490 E4 = 330 Hz, tnext=401, dur=1506, soft 33 -> 23, sustain 1152 -> 1506
    db 145, 1, 81, 4, 208, 0, 23, 1  ; Note 145: T 46.0497 G#3 = 208 Hz, tnext=401, dur=1105, soft 33 -> 23, sustain 698 -> 1105
    db 158, 1, 41, 3, 247, 0, 23, 1  ; Note 146: T 46.4504 B3 = 247 Hz, tnext=414, dur=809, soft 33 -> 23
    db 213, 0, 13, 2, 74, 1, 25, 1  ; Note 147: T 46.8649 E4 = 330 Hz, tnext=213, dur=525, soft 37 -> 25
    db 14, 0, 148, 20, 165, 0, 27, 1  ; Note 148: T 47.0780 E3 = 165 Hz, tnext=14, dur=5268, soft 39 -> 27, sustain 4730 -> 5268
    db 153, 0, 134, 20, 82, 0, 27, 1  ; Note 149: T 47.0920 E2 = 82 Hz, tnext=153, dur=5254, soft 39 -> 27, sustain 4786 -> 5254
; T 47.1549 Sustain 0 (Instrument 1)
; T 47.1549 Sustain 0 (Instrument 2)
    db 132, 1, 37, 14, 196, 0, 32, 1  ; Note 150: T 47.2445 G3 = 196 Hz, tnext=388, dur=3621, soft 47 -> 32, sustain 934 -> 3621
; T 47.4704 Sustain 127 (Instrument 1)
; T 47.4704 Sustain 127 (Instrument 2)
    db 149, 1, 161, 12, 247, 0, 23, 1  ; Note 151: T 47.6323 B3 = 247 Hz, tnext=405, dur=3233, soft 33 -> 23, sustain 857 -> 3233
    db 145, 1, 12, 11, 74, 1, 23, 1  ; Note 152: T 48.0375 E4 = 330 Hz, tnext=401, dur=2828, soft 33 -> 23, sustain 994 -> 2828
    db 145, 1, 124, 9, 196, 0, 23, 1  ; Note 153: T 48.4381 G3 = 196 Hz, tnext=401, dur=2428, soft 33 -> 23, sustain 882 -> 2428
    db 111, 1, 235, 7, 247, 0, 23, 1  ; Note 154: T 48.8387 B3 = 247 Hz, tnext=367, dur=2027, soft 33 -> 23, sustain 815 -> 2027
    db 156, 1, 124, 6, 74, 1, 23, 1  ; Note 155: T 49.2055 E4 = 330 Hz, tnext=412, dur=1660, soft 33 -> 23, sustain 983 -> 1660
    db 147, 1, 224, 4, 196, 0, 23, 1  ; Note 156: T 49.6177 G3 = 196 Hz, tnext=403, dur=1248, soft 33 -> 23, sustain 819 -> 1248
    db 94, 1, 113, 3, 247, 0, 23, 1  ; Note 157: T 50.0206 B3 = 247 Hz, tnext=350, dur=881, soft 33 -> 23
    db 228, 1, 33, 2, 74, 1, 23, 1  ; Note 158: T 50.3711 E4 = 330 Hz, tnext=484, dur=545, soft 34 -> 23
    db 15, 0, 211, 5, 136, 1, 33, 2  ; Note 159: T 50.8553 G4 = 392 Hz, tnext=15, dur=1491, soft 48 -> 33, sustain 1007 -> 1491
; T 50.8658 Sustain 0 (Instrument 1)
; T 50.8658 Sustain 0 (Instrument 2)
    db 4, 2, 196, 5, 196, 0, 28, 1  ; Note 160: T 50.8705 G3 = 196 Hz, tnext=516, dur=1476, soft 41 -> 28, sustain 916 -> 1476
    db 176, 1, 192, 3, 247, 0, 23, 1  ; Note 161: T 51.3861 B3 = 247 Hz, tnext=432, dur=960, soft 34 -> 23, sustain 573 -> 960
; T 51.4001 Sustain 127 (Instrument 1)
; T 51.4001 Sustain 127 (Instrument 2)
    db 30, 1, 16, 2, 74, 1, 23, 1  ; Note 162: T 51.8180 E4 = 330 Hz, tnext=286, dur=528, soft 33 -> 23, sustain 346 -> 528
    db 19, 1, 242, 0, 136, 1, 31, 2  ; Note 163: T 52.1043 G4 = 392 Hz, tnext=275, dur=242, soft 45 -> 31, sustain 151 -> 242
; T 52.3464 Sustain 0 (Instrument 1)
; T 52.3464 Sustain 0 (Instrument 2)
    db 7, 0, 132, 15, 147, 0, 27, 1  ; Note 164: T 52.3790 D3 = 147 Hz, tnext=7, dur=3972, soft 39 -> 27
    db 6, 0, 91, 14, 136, 1, 34, 2  ; Note 165: T 52.3860 G4 = 392 Hz, tnext=6, dur=3675, soft 49 -> 34, sustain 1457 -> 3675
    db 8, 0, 215, 15, 73, 0, 27, 1  ; Note 166: T 52.3918 D2 = 73 Hz, tnext=8, dur=4055, soft 39 -> 27
    db 205, 1, 77, 14, 196, 0, 28, 1  ; Note 167: T 52.3999 G3 = 196 Hz, tnext=461, dur=3661, soft 40 -> 28, sustain 911 -> 3661
; T 52.8423 Sustain 127 (Instrument 1)
; T 52.8423 Sustain 127 (Instrument 2)
    db 143, 1, 128, 12, 247, 0, 23, 1  ; Note 168: T 52.8609 B3 = 247 Hz, tnext=399, dur=3200, soft 34 -> 23, sustain 786 -> 3200
    db 94, 1, 241, 10, 93, 1, 23, 1  ; Note 169: T 53.2601 F4 = 349 Hz, tnext=350, dur=2801, soft 33 -> 23, sustain 412 -> 2801
    db 128, 1, 147, 9, 196, 0, 23, 1  ; Note 170: T 53.6105 G3 = 196 Hz, tnext=384, dur=2451, soft 33 -> 23, sustain 810 -> 2451
    db 131, 1, 19, 8, 247, 0, 23, 1  ; Note 171: T 53.9946 B3 = 247 Hz, tnext=387, dur=2067, soft 33 -> 23, sustain 843 -> 2067
    db 135, 1, 144, 6, 93, 1, 23, 1  ; Note 172: T 54.3811 F4 = 349 Hz, tnext=391, dur=1680, soft 33 -> 23, sustain 455 -> 1680
    db 166, 1, 9, 5, 196, 0, 23, 1  ; Note 173: T 54.7721 G3 = 196 Hz, tnext=422, dur=1289, soft 33 -> 23, sustain 831 -> 1289
    db 122, 1, 162, 3, 247, 0, 23, 1  ; Note 174: T 55.1945 B3 = 247 Hz, tnext=378, dur=930, soft 33 -> 23
    db 230, 1, 23, 2, 93, 1, 23, 1  ; Note 175: T 55.5726 F4 = 349 Hz, tnext=486, dur=535, soft 33 -> 23
    db 28, 0, 80, 5, 196, 0, 24, 1  ; Note 176: T 56.0590 G3 = 196 Hz, tnext=28, dur=1360, soft 35 -> 24, sustain 745 -> 1360
; T 56.0613 Sustain 0 (Instrument 1)
; T 56.0613 Sustain 0 (Instrument 2)
    db 169, 1, 52, 5, 136, 1, 32, 2  ; Note 177: T 56.0869 G4 = 392 Hz, tnext=425, dur=1332, soft 47 -> 32, sustain 789 -> 1332
; T 56.4499 Sustain 127 (Instrument 1)
; T 56.4499 Sustain 127 (Instrument 2)
    db 100, 1, 139, 3, 247, 0, 23, 1  ; Note 178: T 56.5116 B3 = 247 Hz, tnext=356, dur=907, soft 33 -> 23, sustain 525 -> 907
    db 6, 1, 39, 2, 93, 1, 23, 1  ; Note 179: T 56.8676 F4 = 349 Hz, tnext=262, dur=551, soft 33 -> 23, sustain 333 -> 551
    db 49, 1, 34, 1, 136, 1, 32, 2  ; Note 180: T 57.1294 G4 = 392 Hz, tnext=305, dur=290, soft 46 -> 32, sustain 174 -> 290
; T 57.4191 Sustain 0 (Instrument 1)
; T 57.4191 Sustain 0 (Instrument 2)
    db 8, 0, 254, 4, 131, 0, 25, 1  ; Note 181: T 57.4342 C3 = 131 Hz, tnext=8, dur=1278, soft 36 -> 25, sustain 962 -> 1278
    db 5, 0, 245, 4, 196, 0, 25, 1  ; Note 182: T 57.4424 G3 = 196 Hz, tnext=5, dur=1269, soft 36 -> 25, sustain 901 -> 1269
    db 11, 0, 10, 15, 136, 1, 35, 2  ; Note 183: T 57.4470 G4 = 392 Hz, tnext=11, dur=3850, soft 50 -> 35, sustain 3468 -> 3850
    db 169, 1, 230, 4, 65, 0, 25, 1  ; Note 184: T 57.4575 C2 = 65 Hz, tnext=425, dur=1254, soft 36 -> 25, sustain 1160 -> 1254
    db 152, 1, 62, 3, 6, 1, 23, 1  ; Note 185: T 57.8822 C4 = 262 Hz, tnext=408, dur=830, soft 33 -> 23, sustain 482 -> 830
; T 57.8857 Soft 0 (Instrument 1)
; T 57.8857 Soft 0 (Instrument 2)
; T 57.9427 Sustain 127 (Instrument 1)
; T 57.9427 Sustain 127 (Instrument 2)
    db 136, 1, 180, 3, 74, 1, 33, 1  ; Note 186: T 58.2906 E4 = 330 Hz, tnext=392, dur=948
    db 1, 0, 89, 5, 123, 0, 37, 1  ; Note 187: T 58.6827 B2 = 123 Hz, tnext=1, dur=1369, sustain 901 -> 1369
    db 12, 0, 88, 5, 62, 0, 37, 1  ; Note 188: T 58.6839 B1 = 62 Hz, tnext=12, dur=1368, sustain 935 -> 1368
    db 197, 1, 76, 5, 196, 0, 37, 1  ; Note 189: T 58.6955 G3 = 196 Hz, tnext=453, dur=1356, sustain 916 -> 1356
; T 58.7118 Sustain 0 (Instrument 1)
; T 58.7118 Sustain 0 (Instrument 2)
    db 129, 1, 136, 3, 6, 1, 33, 1  ; Note 190: T 59.1480 C4 = 262 Hz, tnext=385, dur=904, sustain 394 -> 904
; T 59.2887 Sustain 127 (Instrument 1)
; T 59.2887 Sustain 127 (Instrument 2)
    db 178, 1, 100, 2, 74, 1, 33, 1  ; Note 191: T 59.5329 E4 = 330 Hz, tnext=434, dur=612
    db 6, 0, 191, 10, 58, 0, 38, 1  ; Note 192: T 59.9668 A#1 = 58 Hz, tnext=6, dur=2751, sustain 2185 -> 2751
    db 69, 0, 185, 10, 117, 0, 38, 1  ; Note 193: T 59.9726 A#2 = 117 Hz, tnext=69, dur=2745, sustain 2163 -> 2745
; T 59.9947 Soft 127 (Instrument 1)
; T 59.9947 Soft 127 (Instrument 2)
    db 181, 1, 232, 4, 196, 0, 26, 1  ; Note 194: T 60.0412 G3 = 196 Hz, tnext=437, dur=1256, soft 38 -> 26, sustain 870 -> 1256
; T 60.0517 Sustain 0 (Instrument 1)
; T 60.0517 Sustain 0 (Instrument 2)
    db 130, 1, 150, 3, 21, 1, 23, 1  ; Note 195: T 60.4785 C#4 = 277 Hz, tnext=386, dur=918, soft 33 -> 23
; T 60.5111 Sustain 127 (Instrument 1)
; T 60.5111 Sustain 127 (Instrument 2)
    db 158, 1, 249, 1, 74, 1, 23, 1  ; Note 196: T 60.8647 E4 = 330 Hz, tnext=414, dur=505, soft 33 -> 23
    db 81, 0, 159, 5, 185, 0, 23, 1  ; Note 197: T 61.2787 F#3 = 185 Hz, tnext=81, dur=1439, soft 33 -> 23, sustain 1205 -> 1439
; T 61.2973 Sustain 0 (Instrument 1)
; T 61.2973 Sustain 0 (Instrument 2)
    db 172, 1, 77, 5, 114, 1, 30, 1  ; Note 198: T 61.3601 F#4 = 370 Hz, tnext=428, dur=1357, soft 43 -> 30, sustain 999 -> 1357
; T 61.7637 Sustain 127 (Instrument 1)
; T 61.7637 Sustain 127 (Instrument 2)
    db 209, 1, 161, 3, 21, 1, 23, 1  ; Note 199: T 61.7881 C#4 = 277 Hz, tnext=465, dur=929, soft 33 -> 23, sustain 660 -> 929
    db 191, 1, 208, 1, 74, 1, 23, 1  ; Note 200: T 62.2533 E4 = 330 Hz, tnext=447, dur=464, soft 33 -> 23, sustain 154 -> 464
    db 9, 0, 226, 9, 185, 0, 23, 1  ; Note 201: T 62.7000 F#3 = 185 Hz, tnext=9, dur=2530, soft 33 -> 23, sustain 1000 -> 2530
    db 5, 0, 217, 9, 62, 0, 23, 1  ; Note 202: T 62.7093 B1 = 62 Hz, tnext=5, dur=2521, soft 33 -> 23, sustain 1640 -> 2521
    db 59, 0, 212, 9, 123, 0, 23, 1  ; Note 203: T 62.7139 B2 = 123 Hz, tnext=59, dur=2516, soft 33 -> 23, sustain 1627 -> 2516
; T 62.7174 Sustain 0 (Instrument 1)
; T 62.7174 Sustain 0 (Instrument 2)
    db 154, 1, 153, 9, 114, 1, 28, 1  ; Note 204: T 62.7732 F#4 = 370 Hz, tnext=410, dur=2457, soft 40 -> 28, sustain 1468 -> 2457
; T 63.1186 Sustain 127 (Instrument 1)
; T 63.1186 Sustain 127 (Instrument 2)
    db 176, 1, 254, 7, 247, 0, 23, 1  ; Note 205: T 63.1837 B3 = 247 Hz, tnext=432, dur=2046, soft 33 -> 23, sustain 921 -> 2046
    db 135, 1, 78, 6, 38, 1, 23, 1  ; Note 206: T 63.6162 D4 = 294 Hz, tnext=391, dur=1614, soft 33 -> 23, sustain 495 -> 1614
    db 171, 1, 199, 4, 185, 0, 23, 1  ; Note 207: T 64.0068 F#3 = 185 Hz, tnext=427, dur=1223, soft 33 -> 23, sustain 978 -> 1223
    db 163, 1, 28, 3, 247, 0, 23, 1  ; Note 208: T 64.4335 B3 = 247 Hz, tnext=419, dur=796, soft 33 -> 23, sustain 578 -> 796
    db 30, 1, 250, 1, 38, 1, 23, 1  ; Note 209: T 64.8520 D4 = 294 Hz, tnext=286, dur=506, soft 33 -> 23
    db 142, 0, 227, 5, 82, 0, 25, 1  ; Note 210: T 65.1380 E2 = 82 Hz, tnext=142, dur=1507, soft 36 -> 25, sustain 1449 -> 1507
; T 65.2299 Sustain 0 (Instrument 1)
; T 65.2299 Sustain 0 (Instrument 2)
    db 26, 0, 85, 5, 196, 0, 23, 1  ; Note 211: T 65.2799 G3 = 196 Hz, tnext=26, dur=1365, soft 34 -> 23, sustain 825 -> 1365
    db 197, 1, 59, 5, 136, 1, 31, 2  ; Note 212: T 65.3054 G4 = 392 Hz, tnext=453, dur=1339, soft 45 -> 31, sustain 736 -> 1339
; T 65.6414 Sustain 127 (Instrument 1)
; T 65.6414 Sustain 127 (Instrument 2)
    db 175, 1, 121, 3, 247, 0, 23, 1  ; Note 213: T 65.7589 B3 = 247 Hz, tnext=431, dur=889, soft 33 -> 23
    db 56, 1, 235, 1, 21, 1, 23, 1  ; Note 214: T 66.1902 C#4 = 277 Hz, tnext=312, dur=491, soft 33 -> 23
    db 81, 0, 239, 5, 98, 0, 23, 1  ; Note 215: T 66.5018 G2 = 98 Hz, tnext=81, dur=1519, soft 33 -> 23, sustain 1434 -> 1519
    db 76, 0, 158, 5, 165, 0, 23, 1  ; Note 216: T 66.5831 E3 = 165 Hz, tnext=76, dur=1438, soft 33 -> 23, sustain 890 -> 1438
; T 66.6448 Sustain 0 (Instrument 1)
; T 66.6448 Sustain 0 (Instrument 2)
    db 182, 1, 82, 5, 74, 1, 29, 1  ; Note 217: T 66.6587 E4 = 330 Hz, tnext=438, dur=1362, soft 42 -> 29, sustain 876 -> 1362
; T 67.0482 Sustain 127 (Instrument 1)
; T 67.0482 Sustain 127 (Instrument 2)
    db 208, 1, 156, 3, 247, 0, 23, 1  ; Note 218: T 67.0970 B3 = 247 Hz, tnext=464, dur=924, soft 33 -> 23, sustain 742 -> 924
    db 197, 1, 204, 1, 21, 1, 23, 1  ; Note 219: T 67.5607 C#4 = 277 Hz, tnext=453, dur=460, soft 33 -> 23, sustain 310 -> 460
    db 14, 0, 37, 11, 185, 0, 23, 1  ; Note 220: T 68.0140 F#3 = 185 Hz, tnext=14, dur=2853, soft 33 -> 23, sustain 1128 -> 2853
; T 68.0209 Sustain 0 (Instrument 1)
; T 68.0209 Sustain 0 (Instrument 2)
    db 74, 0, 23, 11, 92, 0, 23, 1  ; Note 221: T 68.0279 F#2 = 92 Hz, tnext=74, dur=2839, soft 33 -> 23, sustain 1902 -> 2839
    db 175, 1, 205, 10, 114, 1, 28, 1  ; Note 222: T 68.1023 F#4 = 370 Hz, tnext=431, dur=2765, soft 41 -> 28, sustain 2372 -> 2765
; T 68.4323 Sustain 127 (Instrument 1)
; T 68.4323 Sustain 127 (Instrument 2)
    db 192, 1, 30, 9, 247, 0, 23, 1  ; Note 223: T 68.5334 B3 = 247 Hz, tnext=448, dur=2334, soft 33 -> 23, sustain 976 -> 2334
    db 134, 1, 94, 7, 38, 1, 23, 1  ; Note 224: T 68.9809 D4 = 294 Hz, tnext=390, dur=1886, soft 33 -> 23, sustain 1017 -> 1886
    db 175, 1, 216, 5, 185, 0, 23, 1  ; Note 225: T 69.3713 F#3 = 185 Hz, tnext=431, dur=1496, soft 33 -> 23, sustain 1131 -> 1496
    db 176, 1, 41, 4, 247, 0, 23, 1  ; Note 226: T 69.8025 B3 = 247 Hz, tnext=432, dur=1065, soft 33 -> 23, sustain 659 -> 1065
    db 240, 1, 120, 2, 38, 1, 23, 1  ; Note 227: T 70.2348 D4 = 294 Hz, tnext=496, dur=632, soft 33 -> 23, sustain 228 -> 632
    db 28, 0, 111, 12, 46, 0, 23, 1  ; Note 228: T 70.7310 F#1 = 46 Hz, tnext=28, dur=3183, soft 33 -> 23, sustain 1768 -> 3183
    db 7, 0, 83, 12, 185, 0, 23, 1  ; Note 229: T 70.7589 F#3 = 185 Hz, tnext=7, dur=3155, soft 33 -> 23, sustain 1102 -> 3155
    db 69, 0, 76, 12, 92, 0, 23, 1  ; Note 230: T 70.7659 F#2 = 92 Hz, tnext=69, dur=3148, soft 33 -> 23, sustain 1752 -> 3148
    db 218, 1, 8, 12, 114, 1, 28, 1  ; Note 231: T 70.8345 F#4 = 370 Hz, tnext=474, dur=3080, soft 41 -> 28, sustain 1626 -> 3080
; T 70.8670 Sustain 0 (Instrument 1)
; T 70.8670 Sustain 0 (Instrument 2)
; T 71.1750 Sustain 127 (Instrument 1)
; T 71.1750 Sustain 127 (Instrument 2)
    db 224, 1, 46, 10, 233, 0, 23, 1  ; Note 232: T 71.3086 A#3 = 233 Hz, tnext=480, dur=2606, soft 33 -> 23, sustain 1025 -> 2606
    db 172, 1, 78, 8, 21, 1, 23, 1  ; Note 233: T 71.7884 C#4 = 277 Hz, tnext=428, dur=2126, soft 33 -> 23, sustain 620 -> 2126
    db 247, 1, 162, 6, 185, 0, 23, 1  ; Note 234: T 72.2159 F#3 = 185 Hz, tnext=503, dur=1698, soft 33 -> 23, sustain 560 -> 1698
    db 191, 1, 171, 4, 233, 0, 23, 1  ; Note 235: T 72.7189 A#3 = 233 Hz, tnext=447, dur=1195, soft 33 -> 23, sustain 684 -> 1195
    db 64, 2, 236, 2, 21, 1, 23, 1  ; Note 236: T 73.1661 C#4 = 277 Hz, tnext=576, dur=748, soft 33 -> 23, sustain 265 -> 748
    db 13, 0, 245, 29, 62, 0, 23, 1  ; Note 237: T 73.7423 B1 = 62 Hz, tnext=13, dur=7669, soft 33 -> 23, sustain 5820 -> 7669
    db 55, 0, 232, 29, 123, 0, 24, 1  ; Note 238: T 73.7551 B2 = 123 Hz, tnext=55, dur=7656, soft 35 -> 24, sustain 5824 -> 7656
    db 0, 2, 251, 9, 247, 0, 30, 1  ; Note 239: T 73.8097 B3 = 247 Hz, tnext=512, dur=2555, soft 43 -> 30, sustain 986 -> 2555
; T 73.9142 Sustain 0 (Instrument 1)
; T 73.9142 Sustain 0 (Instrument 2)
; T 74.2465 Sustain 127 (Instrument 1)
; T 74.2465 Sustain 127 (Instrument 2)
    db 160, 1, 251, 7, 38, 1, 23, 1  ; Note 240: T 74.3220 D4 = 294 Hz, tnext=416, dur=2043, soft 33 -> 23, sustain 551 -> 2043
    db 142, 1, 91, 6, 114, 1, 23, 1  ; Note 241: T 74.7379 F#4 = 370 Hz, tnext=398, dur=1627, soft 33 -> 23, sustain 516 -> 1627
    db 127, 1, 205, 4, 247, 0, 23, 1  ; Note 242: T 75.1363 B3 = 247 Hz, tnext=383, dur=1229, soft 33 -> 23, sustain 892 -> 1229
    db 149, 1, 77, 3, 38, 1, 23, 1  ; Note 243: T 75.5197 D4 = 294 Hz, tnext=405, dur=845, soft 33 -> 23, sustain 710 -> 845
    db 146, 1, 8, 2, 114, 1, 23, 1  ; Note 244: T 75.9249 F#4 = 370 Hz, tnext=402, dur=520, soft 33 -> 23
; T 76.0248 Soft 0 (Instrument 1)
; T 76.0248 Soft 0 (Instrument 2)
    db 200, 1, 86, 5, 247, 0, 33, 1  ; Note 245: T 76.3267 B3 = 247 Hz, tnext=456, dur=1366, sustain 992 -> 1366
; T 76.3650 Sustain 0 (Instrument 1)
; T 76.3650 Sustain 0 (Instrument 2)
; T 76.6263 Sustain 127 (Instrument 1)
; T 76.6263 Sustain 127 (Instrument 2)
    db 140, 1, 141, 3, 55, 1, 33, 1  ; Note 246: T 76.7831 D#4 = 311 Hz, tnext=396, dur=909, sustain 563 -> 909
    db 212, 1, 1, 2, 114, 1, 36, 1  ; Note 247: T 77.1790 F#4 = 370 Hz, tnext=468, dur=513, sustain 158 -> 513
    db 2, 0, 156, 5, 238, 1, 58, 2  ; Note 248: T 77.6470 B4 = 494 Hz, tnext=2, dur=1436, sustain 989 -> 1436
    db 246, 1, 154, 5, 247, 0, 42, 1  ; Note 249: T 77.6493 B3 = 247 Hz, tnext=502, dur=1434, sustain 990 -> 1434
; T 77.6923 Sustain 0 (Instrument 1)
; T 77.6923 Sustain 0 (Instrument 2)
; T 78.0267 Sustain 127 (Instrument 1)
; T 78.0267 Sustain 127 (Instrument 2)
    db 168, 1, 165, 3, 55, 1, 36, 1  ; Note 250: T 78.1509 D#4 = 311 Hz, tnext=424, dur=933, sustain 495 -> 933
    db 145, 1, 253, 1, 114, 1, 38, 1  ; Note 251: T 78.5748 F#4 = 370 Hz, tnext=401, dur=509, sustain 92 -> 509
    db 19, 0, 132, 9, 247, 0, 50, 1  ; Note 252: T 78.9754 B3 = 247 Hz, tnext=19, dur=2436, sustain 987 -> 2436
    db 209, 1, 249, 14, 11, 2, 59, 2  ; Note 253: T 78.9940 C5 = 523 Hz, tnext=465, dur=3833, sustain 2737 -> 3833
; T 79.0834 Sustain 0 (Instrument 1)
; T 79.0834 Sustain 0 (Instrument 2)
; T 79.3632 Sustain 127 (Instrument 1)
; T 79.3632 Sustain 127 (Instrument 2)
    db 162, 1, 160, 7, 74, 1, 52, 1  ; Note 254: T 79.4585 E4 = 330 Hz, tnext=418, dur=1952, sustain 721 -> 1952
    db 248, 0, 254, 5, 136, 1, 49, 2  ; Note 255: T 79.8764 G4 = 392 Hz, tnext=248, dur=1534, sustain 392 -> 1534
    db 4, 0, 6, 5, 82, 0, 53, 1  ; Note 256: T 80.1248 E2 = 82 Hz, tnext=4, dur=1286, sustain 936 -> 1286
    db 78, 0, 3, 5, 165, 0, 53, 1  ; Note 257: T 80.1283 E3 = 165 Hz, tnext=78, dur=1283, sustain 916 -> 1283
    db 156, 1, 181, 4, 247, 0, 54, 1  ; Note 258: T 80.2061 B3 = 247 Hz, tnext=412, dur=1205, sustain 893 -> 1205
    db 125, 1, 60, 3, 74, 1, 49, 1  ; Note 259: T 80.6181 E4 = 330 Hz, tnext=381, dur=828
    db 20, 1, 156, 1, 136, 1, 38, 2  ; Note 260: T 80.9989 G4 = 392 Hz, tnext=276, dur=412, sustain 360 -> 412
    db 13, 0, 16, 6, 98, 0, 52, 1  ; Note 261: T 81.2751 G2 = 98 Hz, tnext=13, dur=1552, sustain 705 -> 1552
    db 56, 0, 3, 6, 196, 0, 52, 1  ; Note 262: T 81.2879 G3 = 196 Hz, tnext=56, dur=1539, sustain 571 -> 1539
; T 81.3181 Soft 127 (Instrument 1)
; T 81.3181 Soft 127 (Instrument 2)
    db 227, 1, 203, 5, 247, 0, 25, 1  ; Note 263: T 81.3436 B3 = 247 Hz, tnext=483, dur=1483, soft 37 -> 25, sustain 1192 -> 1483
; T 81.4109 Sustain 0 (Instrument 1)
; T 81.4109 Sustain 0 (Instrument 2)
; T 81.6640 Sustain 127 (Instrument 1)
; T 81.6640 Sustain 127 (Instrument 2)
    db 189, 1, 0, 4, 74, 1, 23, 1  ; Note 264: T 81.8265 E4 = 330 Hz, tnext=445, dur=1024, soft 33 -> 23
    db 172, 1, 44, 2, 136, 1, 27, 2  ; Note 265: T 82.2710 G4 = 392 Hz, tnext=428, dur=556, soft 39 -> 27, sustain 441 -> 556
    db 60, 0, 248, 4, 82, 0, 25, 1  ; Note 266: T 82.6993 E2 = 82 Hz, tnext=60, dur=1272, soft 36 -> 25, sustain 787 -> 1272
    db 14, 0, 69, 1, 165, 0, 25, 1  ; Note 267: T 82.7597 E3 = 165 Hz, tnext=14, dur=325, soft 36 -> 25
    db 5, 0, 174, 4, 247, 0, 24, 1  ; Note 268: T 82.7736 B3 = 247 Hz, tnext=5, dur=1198, soft 35 -> 24, sustain 792 -> 1198
    db 158, 1, 169, 4, 210, 1, 32, 2  ; Note 269: T 82.7783 A#4 = 466 Hz, tnext=414, dur=1193, soft 46 -> 32, sustain 864 -> 1193
; T 82.8270 Sustain 0 (Instrument 1)
; T 82.8270 Sustain 0 (Instrument 2)
; T 83.0870 Sustain 127 (Instrument 1)
; T 83.0870 Sustain 127 (Instrument 2)
    db 134, 1, 49, 3, 74, 1, 23, 1  ; Note 270: T 83.1926 E4 = 330 Hz, tnext=390, dur=817, soft 33 -> 23
    db 7, 1, 170, 1, 136, 1, 26, 2  ; Note 271: T 83.5827 G4 = 392 Hz, tnext=263, dur=426, soft 38 -> 26
    db 10, 0, 101, 27, 62, 0, 25, 1  ; Note 272: T 83.8461 B1 = 62 Hz, tnext=10, dur=7013, soft 37 -> 25, sustain 5369 -> 7013
    db 96, 0, 90, 27, 123, 0, 25, 1  ; Note 273: T 83.8566 B2 = 123 Hz, tnext=96, dur=7002, soft 37 -> 25, sustain 5364 -> 7002
    db 31, 0, 214, 13, 247, 0, 25, 1  ; Note 274: T 83.9529 B3 = 247 Hz, tnext=31, dur=3542, soft 36 -> 25, sustain 925 -> 3542
; T 83.9715 Sustain 0 (Instrument 1)
; T 83.9715 Sustain 0 (Instrument 2)
    db 162, 1, 183, 13, 238, 1, 30, 2  ; Note 275: T 83.9842 B4 = 494 Hz, tnext=418, dur=3511, soft 43 -> 30, sustain 3224 -> 3511
; T 84.3172 Sustain 127 (Instrument 1)
; T 84.3172 Sustain 127 (Instrument 2)
    db 99, 1, 21, 12, 55, 1, 23, 1  ; Note 276: T 84.4019 D#4 = 311 Hz, tnext=355, dur=3093, soft 33 -> 23, sustain 799 -> 3093
    db 116, 1, 178, 10, 114, 1, 23, 1  ; Note 277: T 84.7570 F#4 = 370 Hz, tnext=372, dur=2738, soft 33 -> 23, sustain 448 -> 2738
; T 84.9832 Soft 0 (Instrument 1)
; T 84.9832 Soft 0 (Instrument 2)
    db 127, 1, 62, 9, 247, 0, 33, 1  ; Note 278: T 85.1294 B3 = 247 Hz, tnext=383, dur=2366, sustain 839 -> 2366
    db 114, 1, 191, 7, 55, 1, 33, 1  ; Note 279: T 85.5123 D#4 = 311 Hz, tnext=370, dur=1983, sustain 801 -> 1983
    db 111, 1, 77, 6, 114, 1, 36, 1  ; Note 280: T 85.8824 F#4 = 370 Hz, tnext=367, dur=1613, sustain 396 -> 1613
    db 112, 1, 222, 4, 247, 0, 41, 1  ; Note 281: T 86.2491 B3 = 247 Hz, tnext=368, dur=1246, sustain 955 -> 1246
    db 108, 1, 110, 3, 55, 1, 42, 1  ; Note 282: T 86.6169 D#4 = 311 Hz, tnext=364, dur=878, sustain 703 -> 878
    db 168, 1, 2, 2, 114, 1, 37, 1  ; Note 283: T 86.9812 F#4 = 370 Hz, tnext=424, dur=514, sustain 371 -> 514
    db 9, 0, 174, 4, 238, 1, 54, 2  ; Note 284: T 87.4047 B4 = 494 Hz, tnext=9, dur=1198, sustain 783 -> 1198
    db 141, 1, 165, 4, 247, 0, 42, 1  ; Note 285: T 87.4140 B3 = 247 Hz, tnext=397, dur=1189, sustain 769 -> 1189
; T 87.4952 Sustain 0 (Instrument 1)
; T 87.4952 Sustain 0 (Instrument 2)
    db 100, 1, 24, 3, 55, 1, 41, 1  ; Note 286: T 87.8108 D#4 = 311 Hz, tnext=356, dur=792, sustain 399 -> 792
; T 87.8178 Sustain 127 (Instrument 1)
; T 87.8178 Sustain 127 (Instrument 2)
    db 77, 1, 180, 1, 114, 1, 36, 1  ; Note 287: T 88.1670 F#4 = 370 Hz, tnext=333, dur=436, sustain 68 -> 436
    db 19, 0, 55, 9, 247, 0, 40, 1  ; Note 288: T 88.4998 B3 = 247 Hz, tnext=19, dur=2359, sustain 1004 -> 2359
    db 168, 1, 160, 14, 11, 2, 56, 2  ; Note 289: T 88.5184 C5 = 523 Hz, tnext=424, dur=3744, sustain 2695 -> 3744
; T 88.6031 Sustain 0 (Instrument 1)
; T 88.6031 Sustain 0 (Instrument 2)
    db 162, 1, 124, 7, 74, 1, 39, 1  ; Note 290: T 88.9429 E4 = 330 Hz, tnext=418, dur=1916, sustain 662 -> 1916
; T 88.9719 Sustain 127 (Instrument 1)
; T 88.9719 Sustain 127 (Instrument 2)
    db 7, 1, 219, 5, 136, 1, 40, 2  ; Note 291: T 89.3604 G4 = 392 Hz, tnext=263, dur=1499, sustain 392 -> 1499
    db 7, 0, 211, 4, 165, 0, 42, 1  ; Note 292: T 89.6237 E3 = 165 Hz, tnext=7, dur=1235, sustain 909 -> 1235
    db 72, 0, 204, 4, 82, 0, 43, 1  ; Note 293: T 89.6307 E2 = 82 Hz, tnext=72, dur=1228, sustain 919 -> 1228
    db 87, 1, 132, 4, 247, 0, 43, 1  ; Note 294: T 89.7026 B3 = 247 Hz, tnext=343, dur=1156, sustain 921 -> 1156
    db 149, 1, 45, 3, 74, 1, 38, 1  ; Note 295: T 90.0459 E4 = 330 Hz, tnext=405, dur=813, sustain 806 -> 813
    db 35, 1, 20, 7, 136, 1, 38, 2  ; Note 296: T 90.4506 G4 = 392 Hz, tnext=291, dur=1812, sustain 1098 -> 1812
    db 12, 0, 240, 5, 98, 0, 40, 1  ; Note 297: T 90.7418 G2 = 98 Hz, tnext=12, dur=1520, sustain 691 -> 1520
    db 55, 0, 229, 5, 196, 0, 42, 1  ; Note 298: T 90.7534 G3 = 196 Hz, tnext=55, dur=1509, sustain 495 -> 1509
    db 182, 1, 174, 5, 247, 0, 40, 1  ; Note 299: T 90.8079 B3 = 247 Hz, tnext=438, dur=1454, sustain 1168 -> 1454
; T 90.8589 Sustain 0 (Instrument 1)
; T 90.8589 Sustain 0 (Instrument 2)
; T 91.1593 Sustain 127 (Instrument 1)
; T 91.1593 Sustain 127 (Instrument 2)
    db 195, 1, 48, 4, 74, 1, 33, 1  ; Note 300: T 91.2463 E4 = 330 Hz, tnext=451, dur=1072
    db 163, 1, 66, 2, 136, 1, 40, 2  ; Note 301: T 91.6974 G4 = 392 Hz, tnext=419, dur=578
    db 41, 0, 250, 4, 82, 0, 39, 1  ; Note 302: T 92.1161 E2 = 82 Hz, tnext=41, dur=1274, sustain 1245 -> 1274
    db 60, 0, 210, 4, 165, 0, 38, 1  ; Note 303: T 92.1567 E3 = 165 Hz, tnext=60, dur=1234, sustain 584 -> 1234
    db 15, 0, 149, 4, 210, 1, 47, 2  ; Note 304: T 92.2170 A#4 = 466 Hz, tnext=15, dur=1173, sustain 868 -> 1173
    db 154, 1, 134, 4, 247, 0, 37, 1  ; Note 305: T 92.2321 B3 = 247 Hz, tnext=410, dur=1158, sustain 801 -> 1158
; T 92.2623 Sustain 0 (Instrument 1)
; T 92.2623 Sustain 0 (Instrument 2)
; T 92.5301 Sustain 127 (Instrument 1)
; T 92.5301 Sustain 127 (Instrument 2)
    db 132, 1, 75, 3, 74, 1, 33, 1  ; Note 306: T 92.6425 E4 = 330 Hz, tnext=388, dur=843
    db 239, 0, 205, 1, 136, 1, 39, 2  ; Note 307: T 93.0309 G4 = 392 Hz, tnext=239, dur=461
    db 27, 0, 79, 10, 62, 0, 39, 1  ; Note 308: T 93.2697 B1 = 62 Hz, tnext=27, dur=2639, sustain 1911 -> 2639
    db 125, 0, 52, 10, 123, 0, 39, 1  ; Note 309: T 93.2964 B2 = 123 Hz, tnext=125, dur=2612, sustain 1806 -> 2612
; T 93.3903 Sustain 0 (Instrument 1)
; T 93.3903 Sustain 0 (Instrument 2)
    db 5, 0, 183, 9, 247, 0, 37, 1  ; Note 310: T 93.4216 B3 = 247 Hz, tnext=5, dur=2487, sustain 1022 -> 2487
    db 180, 1, 178, 9, 238, 1, 44, 2  ; Note 311: T 93.4262 B4 = 494 Hz, tnext=436, dur=2482, sustain 1498 -> 2482
; T 93.7404 Sustain 127 (Instrument 1)
; T 93.7404 Sustain 127 (Instrument 2)
    db 165, 1, 254, 7, 55, 1, 33, 1  ; Note 312: T 93.8622 D#4 = 311 Hz, tnext=421, dur=2046, sustain 893 -> 2046
    db 165, 1, 89, 6, 114, 1, 38, 1  ; Note 313: T 94.2830 F#4 = 370 Hz, tnext=421, dur=1625, sustain 483 -> 1625
    db 154, 1, 181, 4, 247, 0, 33, 1  ; Note 314: T 94.7038 B3 = 247 Hz, tnext=410, dur=1205, sustain 892 -> 1205
    db 160, 1, 26, 3, 55, 1, 33, 1  ; Note 315: T 95.1143 D#4 = 311 Hz, tnext=416, dur=794, sustain 523 -> 794
    db 185, 0, 192, 1, 114, 1, 37, 1  ; Note 316: T 95.5305 F#4 = 370 Hz, tnext=185, dur=448
    db 60, 0, 83, 10, 52, 0, 39, 1  ; Note 317: T 95.7160 G#1 = 52 Hz, tnext=60, dur=2643, sustain 1672 -> 2643
    db 151, 0, 22, 10, 104, 0, 39, 1  ; Note 318: T 95.7762 G#2 = 104 Hz, tnext=151, dur=2582, sustain 1290 -> 2582
; T 95.9084 Sustain 0 (Instrument 1)
; T 95.9084 Sustain 0 (Instrument 2)
    db 2, 0, 128, 9, 238, 1, 52, 2  ; Note 319: T 95.9270 B4 = 494 Hz, tnext=2, dur=2432, sustain 1991 -> 2432
    db 160, 1, 125, 9, 247, 0, 37, 1  ; Note 320: T 95.9293 B3 = 247 Hz, tnext=416, dur=2429, sustain 913 -> 2429
; T 96.3374 Sustain 127 (Instrument 1)
; T 96.3374 Sustain 127 (Instrument 2)
    db 121, 1, 221, 7, 38, 1, 33, 1  ; Note 321: T 96.3455 D4 = 294 Hz, tnext=377, dur=2013, sustain 825 -> 2013
    db 133, 1, 100, 6, 93, 1, 33, 1  ; Note 322: T 96.7221 F4 = 349 Hz, tnext=389, dur=1636, sustain 487 -> 1636
    db 147, 1, 223, 4, 247, 0, 33, 1  ; Note 323: T 97.1115 B3 = 247 Hz, tnext=403, dur=1247, sustain 732 -> 1247
    db 145, 1, 76, 3, 38, 1, 33, 1  ; Note 324: T 97.5148 D4 = 294 Hz, tnext=401, dur=844, sustain 518 -> 844
    db 220, 0, 187, 1, 93, 1, 33, 1  ; Note 325: T 97.9158 F4 = 349 Hz, tnext=220, dur=443, sustain 134 -> 443
    db 32, 0, 94, 10, 44, 0, 36, 1  ; Note 326: T 98.1360 F1 = 44 Hz, tnext=32, dur=2654, sustain 2121 -> 2654
    db 167, 0, 61, 10, 87, 0, 36, 1  ; Note 327: T 98.1684 F2 = 87 Hz, tnext=167, dur=2621, sustain 977 -> 2621
    db 13, 0, 150, 9, 247, 0, 34, 1  ; Note 328: T 98.3353 B3 = 247 Hz, tnext=13, dur=2454, sustain 954 -> 2454
    db 155, 1, 138, 9, 238, 1, 42, 2  ; Note 329: T 98.3481 B4 = 494 Hz, tnext=411, dur=2442, sustain 1261 -> 2442
; T 98.3585 Sustain 0 (Instrument 1)
; T 98.3585 Sustain 0 (Instrument 2)
    db 160, 1, 238, 7, 21, 1, 33, 1  ; Note 330: T 98.7595 C#4 = 277 Hz, tnext=416, dur=2030, sustain 528 -> 2030
; T 98.7803 Sustain 127 (Instrument 1)
; T 98.7803 Sustain 127 (Instrument 2)
    db 148, 1, 78, 6, 159, 1, 38, 2  ; Note 331: T 99.1755 G#4 = 415 Hz, tnext=404, dur=1614, sustain 1085 -> 1614
    db 101, 1, 186, 4, 247, 0, 33, 1  ; Note 332: T 99.5799 B3 = 247 Hz, tnext=357, dur=1210, sustain 858 -> 1210
    db 153, 1, 142, 3, 21, 1, 33, 1  ; Note 333: T 99.9369 C#4 = 277 Hz, tnext=409, dur=910
    db 234, 0, 211, 1, 159, 1, 43, 2  ; Note 334: T 100.3460 G#4 = 415 Hz, tnext=234, dur=467
    db 54, 0, 90, 10, 46, 0, 37, 1  ; Note 335: T 100.5801 F#1 = 46 Hz, tnext=54, dur=2650, sustain 1843 -> 2650
    db 144, 0, 36, 10, 92, 0, 38, 1  ; Note 336: T 100.6345 F#2 = 92 Hz, tnext=144, dur=2596, sustain 704 -> 2596
    db 10, 0, 148, 9, 220, 0, 39, 1  ; Note 337: T 100.7782 A3 = 220 Hz, tnext=10, dur=2452, sustain 993 -> 2452
    db 148, 1, 138, 9, 184, 1, 48, 2  ; Note 338: T 100.7886 A4 = 440 Hz, tnext=404, dur=2442, sustain 1110 -> 2442
; T 100.7897 Sustain 0 (Instrument 1)
; T 100.7897 Sustain 0 (Instrument 2)
    db 174, 1, 246, 7, 21, 1, 33, 1  ; Note 339: T 101.1929 C#4 = 277 Hz, tnext=430, dur=2038, sustain 934 -> 2038
; T 101.2253 Sustain 127 (Instrument 1)
; T 101.2253 Sustain 127 (Instrument 2)
    db 158, 1, 72, 6, 114, 1, 33, 1  ; Note 340: T 101.6226 F#4 = 370 Hz, tnext=414, dur=1608, sustain 948 -> 1608
    db 146, 1, 170, 4, 220, 0, 33, 1  ; Note 341: T 102.0362 A3 = 220 Hz, tnext=402, dur=1194, sustain 882 -> 1194
    db 105, 1, 128, 3, 21, 1, 33, 1  ; Note 342: T 102.4382 C#4 = 277 Hz, tnext=361, dur=896
    db 0, 1, 7, 2, 114, 1, 33, 1  ; Note 343: T 102.7996 F#4 = 370 Hz, tnext=256, dur=519
    db 39, 0, 219, 10, 62, 0, 36, 1  ; Note 344: T 103.0556 B1 = 62 Hz, tnext=39, dur=2779, sustain 2275 -> 2779
    db 142, 0, 179, 10, 123, 0, 35, 1  ; Note 345: T 103.0950 B2 = 123 Hz, tnext=142, dur=2739, sustain 1194 -> 2739
; T 103.2305 Sustain 0 (Instrument 1)
; T 103.2305 Sustain 0 (Instrument 2)
    db 12, 0, 37, 10, 196, 0, 33, 1  ; Note 346: T 103.2375 G3 = 196 Hz, tnext=12, dur=2597, sustain 956 -> 2597
    db 176, 1, 25, 10, 136, 1, 44, 2  ; Note 347: T 103.2491 G4 = 392 Hz, tnext=432, dur=2585, sustain 1358 -> 2585
    db 170, 1, 105, 8, 247, 0, 33, 1  ; Note 348: T 103.6812 B3 = 247 Hz, tnext=426, dur=2153, sustain 894 -> 2153
; T 103.8109 Sustain 127 (Instrument 1)
; T 103.8109 Sustain 127 (Instrument 2)
    db 156, 1, 191, 6, 38, 1, 33, 1  ; Note 349: T 104.1075 D4 = 294 Hz, tnext=412, dur=1727, sustain 495 -> 1727
    db 168, 1, 34, 5, 196, 0, 33, 1  ; Note 350: T 104.5199 G3 = 196 Hz, tnext=424, dur=1314, sustain 863 -> 1314
; T 104.9391 Soft 127 (Instrument 1)
; T 104.9391 Soft 127 (Instrument 2)
    db 139, 1, 122, 3, 247, 0, 23, 1  ; Note 351: T 104.9438 B3 = 247 Hz, tnext=395, dur=890, soft 33 -> 23, sustain 586 -> 890
    db 36, 1, 240, 1, 38, 1, 23, 1  ; Note 352: T 105.3386 D4 = 294 Hz, tnext=292, dur=496, soft 33 -> 23, sustain 227 -> 496
    db 63, 0, 188, 11, 65, 0, 23, 1  ; Note 353: T 105.6304 C2 = 65 Hz, tnext=63, dur=3004, soft 33 -> 23, sustain 1156 -> 3004
    db 67, 0, 125, 11, 131, 0, 23, 1  ; Note 354: T 105.6930 C3 = 131 Hz, tnext=67, dur=2941, soft 33 -> 23, sustain 1941 -> 2941
    db 46, 0, 58, 11, 185, 0, 23, 1  ; Note 355: T 105.7601 F#3 = 185 Hz, tnext=46, dur=2874, soft 33 -> 23, sustain 1173 -> 2874
    db 239, 1, 12, 11, 114, 1, 27, 1  ; Note 356: T 105.8064 F#4 = 370 Hz, tnext=495, dur=2828, soft 39 -> 27, sustain 1959 -> 2828
; T 105.8342 Sustain 0 (Instrument 1)
; T 105.8342 Sustain 0 (Instrument 2)
; T 106.0925 Sustain 127 (Instrument 1)
; T 106.0925 Sustain 127 (Instrument 2)
    db 216, 1, 29, 9, 220, 0, 23, 1  ; Note 357: T 106.3009 A3 = 220 Hz, tnext=472, dur=2333, soft 33 -> 23, sustain 966 -> 2333
    db 133, 1, 69, 7, 55, 1, 23, 1  ; Note 358: T 106.7733 D#4 = 311 Hz, tnext=389, dur=1861, soft 33 -> 23, sustain 466 -> 1861
    db 192, 1, 192, 5, 185, 0, 23, 1  ; Note 359: T 107.1624 F#3 = 185 Hz, tnext=448, dur=1472, soft 33 -> 23, sustain 1077 -> 1472
    db 234, 1, 0, 4, 220, 0, 23, 1  ; Note 360: T 107.6105 A3 = 220 Hz, tnext=490, dur=1024, soft 33 -> 23, sustain 670 -> 1024
    db 16, 2, 22, 2, 55, 1, 23, 1  ; Note 361: T 108.1003 D#4 = 311 Hz, tnext=528, dur=534, soft 33 -> 23, sustain 193 -> 534
    db 8, 0, 230, 10, 139, 0, 23, 1  ; Note 362: T 108.6284 C#3 = 139 Hz, tnext=8, dur=2790, soft 33 -> 23, sustain 1060 -> 2790
; T 108.6342 Sustain 0 (Instrument 1)
; T 108.6342 Sustain 0 (Instrument 2)
    db 39, 0, 222, 10, 69, 0, 23, 1  ; Note 363: T 108.6365 C#2 = 69 Hz, tnext=39, dur=2782, soft 33 -> 23, sustain 1001 -> 2782
    db 236, 1, 182, 10, 21, 1, 25, 1  ; Note 364: T 108.6759 C#4 = 277 Hz, tnext=492, dur=2742, soft 36 -> 25, sustain 1357 -> 2742
; T 109.0151 Sustain 127 (Instrument 1)
; T 109.0151 Sustain 127 (Instrument 2)
    db 154, 1, 202, 8, 185, 0, 23, 1  ; Note 365: T 109.1679 F#3 = 185 Hz, tnext=410, dur=2250, soft 33 -> 23, sustain 969 -> 2250
    db 177, 1, 48, 7, 220, 0, 23, 1  ; Note 366: T 109.5776 A3 = 220 Hz, tnext=433, dur=1840, soft 33 -> 23, sustain 671 -> 1840
; T 109.8786 Soft 127 (Instrument 1)
; T 109.8786 Soft 127 (Instrument 2)
    db 168, 1, 128, 5, 139, 0, 23, 1  ; Note 367: T 110.0105 C#3 = 139 Hz, tnext=424, dur=1408, soft 33 -> 23, sustain 1002 -> 1408
    db 170, 1, 216, 3, 185, 0, 23, 1  ; Note 368: T 110.4342 F#3 = 185 Hz, tnext=426, dur=984, soft 33 -> 23, sustain 626 -> 984
    db 20, 2, 46, 2, 220, 0, 23, 1  ; Note 369: T 110.8601 A3 = 220 Hz, tnext=532, dur=558, soft 33 -> 23, sustain 179 -> 558
    db 5, 0, 146, 12, 69, 0, 23, 1  ; Note 370: T 111.3926 C#2 = 69 Hz, tnext=5, dur=3218, soft 33 -> 23, sustain 2391 -> 3218
    db 2, 0, 22, 6, 139, 0, 23, 1  ; Note 371: T 111.3972 C#3 = 139 Hz, tnext=2, dur=1558, soft 33 -> 23, sustain 1051 -> 1558
    db 39, 0, 140, 12, 35, 0, 23, 1  ; Note 372: T 111.3995 C#1 = 35 Hz, tnext=39, dur=3212, soft 33 -> 23, sustain 2351 -> 3212
; T 111.4181 Sustain 0 (Instrument 1)
; T 111.4181 Sustain 0 (Instrument 2)
    db 215, 1, 236, 5, 21, 1, 25, 1  ; Note 373: T 111.4389 C#4 = 277 Hz, tnext=471, dur=1516, soft 37 -> 25, sustain 955 -> 1516
; T 111.8880 Sustain 127 (Instrument 1)
; T 111.8880 Sustain 127 (Instrument 2)
    db 200, 1, 21, 4, 185, 0, 23, 1  ; Note 374: T 111.9100 F#3 = 185 Hz, tnext=456, dur=1045, soft 33 -> 23, sustain 526 -> 1045
    db 13, 2, 147, 2, 208, 0, 23, 1  ; Note 375: T 112.3660 G#3 = 208 Hz, tnext=525, dur=659, soft 33 -> 23
    db 15, 0, 184, 6, 139, 0, 23, 1  ; Note 376: T 112.8915 C#3 = 139 Hz, tnext=15, dur=1720, soft 33 -> 23, sustain 905 -> 1720
    db 34, 2, 168, 6, 21, 1, 24, 1  ; Note 377: T 112.9066 C#4 = 277 Hz, tnext=546, dur=1704, soft 35 -> 24, sustain 1304 -> 1704
; T 112.9552 Sustain 0 (Instrument 1)
; T 112.9552 Sustain 0 (Instrument 2)
    db 40, 2, 134, 4, 175, 0, 23, 1  ; Note 378: T 113.4528 F3 = 175 Hz, tnext=552, dur=1158, soft 33 -> 23, sustain 444 -> 1158
; T 113.4875 Sustain 127 (Instrument 1)
; T 113.4875 Sustain 127 (Instrument 2)
    db 157, 1, 94, 2, 208, 0, 23, 1  ; Note 379: T 114.0047 G#3 = 208 Hz, tnext=413, dur=606, soft 33 -> 23, sustain 228 -> 606
    db 14, 0, 106, 21, 92, 0, 23, 1  ; Note 380: T 114.4177 F#2 = 92 Hz, tnext=14, dur=5482, soft 33 -> 23, sustain 1471 -> 5482
    db 40, 0, 92, 21, 46, 0, 23, 1  ; Note 381: T 114.4316 F#1 = 46 Hz, tnext=40, dur=5468, soft 34 -> 23, sustain 2091 -> 5468
    db 27, 2, 52, 21, 185, 0, 28, 1  ; Note 382: T 114.4721 F#3 = 185 Hz, tnext=539, dur=5428, soft 41 -> 28, sustain 679 -> 5428
; T 114.6110 Sustain 0 (Instrument 1)
; T 114.6110 Sustain 0 (Instrument 2)
; T 114.8690 Sustain 127 (Instrument 1)
; T 114.8690 Sustain 127 (Instrument 2)
    db 167, 1, 25, 19, 220, 0, 23, 1  ; Note 383: T 115.0113 A3 = 220 Hz, tnext=423, dur=4889, soft 33 -> 23, sustain 432 -> 4889
    db 162, 1, 113, 17, 21, 1, 23, 1  ; Note 384: T 115.4348 C#4 = 277 Hz, tnext=418, dur=4465, soft 33 -> 23, sustain 400 -> 4465
    db 123, 1, 207, 15, 220, 0, 23, 1  ; Note 385: T 115.8525 A3 = 220 Hz, tnext=379, dur=4047, soft 33 -> 23, sustain 394 -> 4047
    db 91, 1, 84, 14, 21, 1, 23, 1  ; Note 386: T 116.2320 C#4 = 277 Hz, tnext=347, dur=3668, soft 33 -> 23, sustain 425 -> 3668
    db 166, 1, 249, 12, 114, 1, 23, 1  ; Note 387: T 116.5791 F#4 = 370 Hz, tnext=422, dur=3321, soft 33 -> 23, sustain 471 -> 3321
    db 147, 1, 82, 11, 21, 1, 23, 1  ; Note 388: T 117.0014 C#4 = 277 Hz, tnext=403, dur=2898, soft 33 -> 23, sustain 931 -> 2898
    db 166, 1, 192, 9, 114, 1, 23, 1  ; Note 389: T 117.4040 F#4 = 370 Hz, tnext=422, dur=2496, soft 33 -> 23, sustain 1093 -> 2496
    db 217, 1, 26, 8, 184, 1, 26, 2  ; Note 390: T 117.8261 A4 = 440 Hz, tnext=473, dur=2074, soft 38 -> 26, sustain 636 -> 2074
    db 65, 0, 65, 6, 21, 1, 23, 1  ; Note 391: T 118.2992 C#4 = 277 Hz, tnext=65, dur=1601, soft 33 -> 23, sustain 1347 -> 1601
    db 222, 1, 0, 6, 42, 2, 35, 2  ; Note 392: T 118.3639 C#5 = 554 Hz, tnext=478, dur=1536, soft 51 -> 35, sustain 948 -> 1536
    db 185, 1, 34, 4, 114, 1, 23, 1  ; Note 393: T 118.8416 F#4 = 370 Hz, tnext=441, dur=1058, soft 33 -> 23, sustain 503 -> 1058
    db 104, 1, 106, 2, 184, 1, 26, 2  ; Note 394: T 119.2822 A4 = 440 Hz, tnext=360, dur=618, soft 38 -> 26, sustain 615 -> 618
    db 117, 0, 2, 1, 42, 2, 29, 2  ; Note 395: T 119.6419 C#5 = 554 Hz, tnext=117, dur=258, soft 42 -> 29, sustain 120 -> 258
    db 22, 0, 255, 19, 87, 0, 25, 1  ; Note 396: T 119.7587 F2 = 87 Hz, tnext=22, dur=5119, soft 36 -> 25, sustain 4428 -> 5119
    db 42, 0, 233, 19, 139, 0, 25, 1  ; Note 397: T 119.7807 C#3 = 139 Hz, tnext=42, dur=5097, soft 36 -> 25, sustain 4440 -> 5097
    db 31, 0, 191, 19, 175, 0, 25, 1  ; Note 398: T 119.8224 F3 = 175 Hz, tnext=31, dur=5055, soft 36 -> 25, sustain 4376 -> 5055
    db 22, 0, 63, 14, 42, 2, 36, 2  ; Note 399: T 119.8536 C#5 = 554 Hz, tnext=22, dur=3647, soft 52 -> 36, sustain 3219 -> 3647
    db 105, 1, 41, 14, 21, 1, 25, 1  ; Note 400: T 119.8756 C#4 = 277 Hz, tnext=361, dur=3625, soft 37 -> 25, sustain 856 -> 3625
; T 119.8999 Sustain 0 (Instrument 1)
; T 119.8999 Sustain 0 (Instrument 2)
    db 172, 1, 192, 12, 159, 1, 26, 2  ; Note 401: T 120.2364 G#4 = 415 Hz, tnext=428, dur=3264, soft 38 -> 26, sustain 813 -> 3264
; T 120.3278 Sustain 127 (Instrument 1)
; T 120.3278 Sustain 127 (Instrument 2)
    db 94, 1, 20, 11, 238, 1, 26, 2  ; Note 402: T 120.6643 B4 = 494 Hz, tnext=350, dur=2836, soft 38 -> 26, sustain 923 -> 2836
    db 177, 1, 182, 9, 21, 1, 23, 1  ; Note 403: T 121.0148 C#4 = 277 Hz, tnext=433, dur=2486, soft 33 -> 23, sustain 928 -> 2486
    db 139, 1, 5, 8, 159, 1, 26, 2  ; Note 404: T 121.4473 G#4 = 415 Hz, tnext=395, dur=2053, soft 38 -> 26, sustain 903 -> 2053
    db 150, 1, 122, 6, 238, 1, 26, 2  ; Note 405: T 121.8427 B4 = 494 Hz, tnext=406, dur=1658, soft 38 -> 26, sustain 963 -> 1658
    db 143, 1, 228, 4, 21, 1, 23, 1  ; Note 406: T 122.2485 C#4 = 277 Hz, tnext=399, dur=1252, soft 33 -> 23, sustain 853 -> 1252
    db 85, 1, 94, 3, 159, 1, 26, 2  ; Note 407: T 122.6474 G#4 = 415 Hz, tnext=341, dur=862, soft 38 -> 26
    db 223, 1, 28, 2, 238, 1, 26, 2  ; Note 408: T 122.9884 B4 = 494 Hz, tnext=479, dur=540, soft 38 -> 26
    db 12, 0, 130, 5, 21, 1, 25, 1  ; Note 409: T 123.4670 C#4 = 277 Hz, tnext=12, dur=1410, soft 37 -> 25, sustain 766 -> 1410
    db 216, 1, 119, 5, 42, 2, 33, 2  ; Note 410: T 123.4786 C#5 = 554 Hz, tnext=472, dur=1399, soft 48 -> 33, sustain 828 -> 1399
; T 123.5006 Sustain 0 (Instrument 1)
; T 123.5006 Sustain 0 (Instrument 2)
; T 123.7526 Sustain 127 (Instrument 1)
; T 123.7526 Sustain 127 (Instrument 2)
    db 98, 1, 159, 3, 159, 1, 26, 2  ; Note 411: T 123.9503 G#4 = 415 Hz, tnext=354, dur=927, soft 38 -> 26, sustain 431 -> 927
    db 35, 1, 61, 2, 238, 1, 26, 2  ; Note 412: T 124.3041 B4 = 494 Hz, tnext=291, dur=573, soft 38 -> 26, sustain 348 -> 573
    db 147, 0, 26, 1, 42, 2, 29, 2  ; Note 413: T 124.5954 C#5 = 554 Hz, tnext=147, dur=282, soft 42 -> 29, sustain 161 -> 282
    db 20, 0, 160, 9, 92, 0, 25, 1  ; Note 414: T 124.7422 F#2 = 92 Hz, tnext=20, dur=2464, soft 36 -> 25, sustain 1337 -> 2464
    db 87, 0, 141, 9, 185, 0, 25, 1  ; Note 415: T 124.7619 F#3 = 185 Hz, tnext=87, dur=2445, soft 37 -> 25, sustain 1585 -> 2445
    db 7, 0, 54, 9, 42, 2, 37, 2  ; Note 416: T 124.8486 C#5 = 554 Hz, tnext=7, dur=2358, soft 54 -> 37, sustain 1990 -> 2358
    db 129, 1, 47, 9, 21, 1, 25, 1  ; Note 417: T 124.8555 C#4 = 277 Hz, tnext=385, dur=2351, soft 37 -> 25, sustain 838 -> 2351
; T 124.8775 Sustain 0 (Instrument 1)
; T 124.8775 Sustain 0 (Instrument 2)
; T 125.2185 Sustain 127 (Instrument 1)
; T 125.2185 Sustain 127 (Instrument 2)
    db 131, 1, 174, 7, 114, 1, 23, 1  ; Note 418: T 125.2405 F#4 = 370 Hz, tnext=387, dur=1966, soft 33 -> 23, sustain 817 -> 1966
    db 118, 1, 43, 6, 184, 1, 26, 2  ; Note 419: T 125.6278 A4 = 440 Hz, tnext=374, dur=1579, soft 38 -> 26, sustain 430 -> 1579
    db 165, 1, 180, 4, 21, 1, 23, 1  ; Note 420: T 126.0022 C#4 = 277 Hz, tnext=421, dur=1204, soft 33 -> 23, sustain 899 -> 1204
; T 126.0115 Soft 0 (Instrument 1)
; T 126.0115 Soft 0 (Instrument 2)
    db 144, 1, 77, 3, 114, 1, 33, 1  ; Note 421: T 126.4229 F#4 = 370 Hz, tnext=400, dur=845
    db 247, 0, 175, 1, 184, 1, 41, 2  ; Note 422: T 126.8227 A4 = 440 Hz, tnext=247, dur=431
    db 32, 0, 69, 5, 78, 0, 39, 1  ; Note 423: T 127.0700 D#2 = 78 Hz, tnext=32, dur=1349, sustain 1274 -> 1349
    db 123, 0, 36, 5, 156, 0, 39, 1  ; Note 424: T 127.1024 D#3 = 156 Hz, tnext=123, dur=1316, sustain 884 -> 1316
; T 127.2064 Sustain 0 (Instrument 1)
; T 127.2064 Sustain 0 (Instrument 2)
    db 2, 0, 170, 4, 11, 2, 46, 2  ; Note 425: T 127.2249 C5 = 523 Hz, tnext=2, dur=1194, sustain 793 -> 1194
    db 167, 1, 168, 4, 6, 1, 37, 1  ; Note 426: T 127.2272 C4 = 262 Hz, tnext=423, dur=1192, sustain 820 -> 1192
; T 127.5750 Sustain 127 (Instrument 1)
; T 127.5750 Sustain 127 (Instrument 2)
    db 90, 1, 24, 3, 114, 1, 33, 1  ; Note 427: T 127.6502 F#4 = 370 Hz, tnext=346, dur=792
    db 254, 0, 190, 1, 184, 1, 39, 2  ; Note 428: T 127.9957 A4 = 440 Hz, tnext=254, dur=446
    db 13, 0, 136, 5, 69, 0, 37, 1  ; Note 429: T 128.2499 C#2 = 69 Hz, tnext=13, dur=1416, sustain 960 -> 1416
    db 123, 0, 123, 5, 139, 0, 37, 1  ; Note 430: T 128.2627 C#3 = 139 Hz, tnext=123, dur=1403, sustain 926 -> 1403
    db 3, 0, 0, 5, 21, 1, 36, 1  ; Note 431: T 128.3852 C#4 = 277 Hz, tnext=3, dur=1280, sustain 837 -> 1280
    db 174, 1, 253, 4, 42, 2, 44, 2  ; Note 432: T 128.3886 C#5 = 554 Hz, tnext=430, dur=1277, sustain 819 -> 1277
; T 128.4187 Sustain 0 (Instrument 1)
; T 128.4187 Sustain 0 (Instrument 2)
    db 124, 1, 79, 3, 114, 1, 33, 1  ; Note 433: T 128.8185 F#4 = 370 Hz, tnext=380, dur=847, sustain 444 -> 847
; T 128.8405 Sustain 127 (Instrument 1)
; T 128.8405 Sustain 127 (Instrument 2)
    db 32, 1, 225, 1, 184, 1, 39, 2  ; Note 434: T 129.1987 A4 = 440 Hz, tnext=288, dur=481
; T 129.2773 Soft 0 (Instrument 1)
; T 129.2773 Soft 0 (Instrument 2)
    db 7, 0, 217, 13, 65, 0, 36, 1  ; Note 435: T 129.4865 C2 = 65 Hz, tnext=7, dur=3545, sustain 1517 -> 3545
    db 0, 0, 210, 13, 104, 0, 36, 1  ; Note 436: T 129.4934 G#2 = 104 Hz, tnext=0, dur=3538, sustain 1669 -> 3538
    db 114, 0, 210, 13, 131, 0, 36, 1  ; Note 437: T 129.4934 C3 = 131 Hz, tnext=114, dur=3538, sustain 2058 -> 3538
    db 2, 0, 96, 13, 110, 2, 44, 2  ; Note 438: T 129.6078 D#5 = 622 Hz, tnext=2, dur=3424, sustain 1702 -> 3424
    db 153, 1, 94, 13, 55, 1, 35, 1  ; Note 439: T 129.6101 D#4 = 311 Hz, tnext=409, dur=3422, sustain 865 -> 3422
; T 129.6656 Sustain 0 (Instrument 1)
; T 129.6656 Sustain 0 (Instrument 2)
    db 69, 1, 197, 11, 114, 1, 33, 1  ; Note 440: T 130.0191 F#4 = 370 Hz, tnext=325, dur=3013, sustain 509 -> 3013
; T 130.0642 Sustain 127 (Instrument 1)
; T 130.0642 Sustain 127 (Instrument 2)
    db 121, 1, 128, 10, 159, 1, 38, 2  ; Note 441: T 130.3437 G#4 = 415 Hz, tnext=377, dur=2688, sustain 499 -> 2688
    db 122, 1, 7, 9, 55, 1, 33, 1  ; Note 442: T 130.7203 D#4 = 311 Hz, tnext=378, dur=2311, sustain 878 -> 2311
    db 99, 1, 142, 7, 114, 1, 33, 1  ; Note 443: T 131.0981 F#4 = 370 Hz, tnext=355, dur=1934, sustain 829 -> 1934
    db 150, 1, 43, 6, 159, 1, 38, 2  ; Note 444: T 131.4527 G#4 = 415 Hz, tnext=406, dur=1579, sustain 496 -> 1579
    db 64, 1, 150, 4, 55, 1, 33, 1  ; Note 445: T 131.8582 D#4 = 311 Hz, tnext=320, dur=1174, sustain 688 -> 1174
    db 142, 1, 97, 3, 114, 1, 33, 1  ; Note 446: T 132.1782 F#4 = 370 Hz, tnext=398, dur=865
    db 255, 0, 204, 1, 159, 1, 38, 2  ; Note 447: T 132.5767 G#4 = 415 Hz, tnext=255, dur=460
    db 7, 0, 225, 5, 65, 0, 36, 1  ; Note 448: T 132.8320 C2 = 65 Hz, tnext=7, dur=1505, sustain 806 -> 1505
    db 39, 0, 218, 5, 104, 0, 36, 1  ; Note 449: T 132.8389 G#2 = 104 Hz, tnext=39, dur=1498, sustain 806 -> 1498
    db 96, 0, 179, 5, 131, 0, 35, 1  ; Note 450: T 132.8782 C3 = 131 Hz, tnext=96, dur=1459, sustain 752 -> 1459
    db 37, 0, 83, 5, 55, 1, 34, 1  ; Note 451: T 132.9741 D#4 = 311 Hz, tnext=37, dur=1363, sustain 716 -> 1363
    db 169, 1, 46, 5, 110, 2, 51, 2  ; Note 452: T 133.0110 D#5 = 622 Hz, tnext=425, dur=1326, sustain 890 -> 1326
; T 133.0318 Sustain 0 (Instrument 1)
; T 133.0318 Sustain 0 (Instrument 2)
; T 133.3068 Sustain 127 (Instrument 1)
; T 133.3068 Sustain 127 (Instrument 2)
    db 91, 1, 133, 3, 114, 1, 33, 1  ; Note 453: T 133.4361 F#4 = 370 Hz, tnext=347, dur=901, sustain 520 -> 901
; T 133.5967 Soft 127 (Instrument 1)
; T 133.5967 Soft 127 (Instrument 2)
    db 62, 1, 42, 2, 159, 1, 26, 2  ; Note 454: T 133.7827 G#4 = 415 Hz, tnext=318, dur=554, soft 38 -> 26, sustain 188 -> 554
    db 47, 0, 102, 10, 69, 0, 25, 1  ; Note 455: T 134.1003 C#2 = 69 Hz, tnext=47, dur=2662, soft 36 -> 25, sustain 1881 -> 2662
    db 122, 0, 54, 10, 139, 0, 25, 1  ; Note 456: T 134.1476 C#3 = 139 Hz, tnext=122, dur=2614, soft 36 -> 25, sustain 1226 -> 2614
    db 45, 0, 188, 9, 74, 1, 24, 1  ; Note 457: T 134.2700 E4 = 330 Hz, tnext=45, dur=2492, soft 35 -> 24, sustain 960 -> 2492
    db 132, 1, 143, 9, 147, 2, 33, 2  ; Note 458: T 134.3151 E5 = 659 Hz, tnext=388, dur=2447, soft 48 -> 33, sustain 1491 -> 2447
; T 134.3370 Sustain 0 (Instrument 1)
; T 134.3370 Sustain 0 (Instrument 2)
    db 192, 1, 11, 8, 159, 1, 26, 2  ; Note 459: T 134.7031 G#4 = 415 Hz, tnext=448, dur=2059, soft 38 -> 26, sustain 919 -> 2059
; T 134.8035 Sustain 127 (Instrument 1)
; T 134.8035 Sustain 127 (Instrument 2)
    db 126, 1, 75, 6, 42, 2, 26, 2  ; Note 460: T 135.1511 C#5 = 554 Hz, tnext=382, dur=1611, soft 38 -> 26, sustain 984 -> 1611
    db 157, 1, 205, 4, 74, 1, 23, 1  ; Note 461: T 135.5333 E4 = 330 Hz, tnext=413, dur=1229, soft 33 -> 23, sustain 905 -> 1229
    db 156, 1, 47, 3, 159, 1, 26, 2  ; Note 462: T 135.9467 G#4 = 415 Hz, tnext=412, dur=815, soft 38 -> 26, sustain 728 -> 815
    db 6, 1, 230, 1, 42, 2, 26, 2  ; Note 463: T 136.3589 C#5 = 554 Hz, tnext=262, dur=486, soft 38 -> 26
    db 53, 0, 163, 5, 46, 0, 25, 1  ; Note 464: T 136.6210 F#1 = 46 Hz, tnext=53, dur=1443, soft 36 -> 25, sustain 968 -> 1443
    db 115, 0, 110, 5, 92, 0, 25, 1  ; Note 465: T 136.6742 F#2 = 92 Hz, tnext=115, dur=1390, soft 36 -> 25, sustain 878 -> 1390
; T 136.7619 Sustain 0 (Instrument 1)
; T 136.7619 Sustain 0 (Instrument 2)
    db 24, 0, 251, 4, 55, 1, 23, 1  ; Note 466: T 136.7896 D#4 = 311 Hz, tnext=24, dur=1275, soft 34 -> 23, sustain 957 -> 1275
    db 166, 1, 227, 4, 110, 2, 36, 2  ; Note 467: T 136.8139 D#5 = 622 Hz, tnext=422, dur=1251, soft 52 -> 36, sustain 828 -> 1251
; T 137.1199 Sustain 127 (Instrument 1)
; T 137.1199 Sustain 127 (Instrument 2)
    db 149, 1, 61, 3, 114, 1, 23, 1  ; Note 468: T 137.2354 F#4 = 370 Hz, tnext=405, dur=829, soft 33 -> 23, sustain 559 -> 829
    db 20, 1, 245, 1, 184, 1, 26, 2  ; Note 469: T 137.6407 A4 = 440 Hz, tnext=276, dur=501, soft 38 -> 26
    db 41, 0, 253, 5, 49, 0, 25, 1  ; Note 470: T 137.9166 G1 = 49 Hz, tnext=41, dur=1533, soft 36 -> 25, sustain 914 -> 1533
    db 119, 0, 212, 5, 98, 0, 24, 1  ; Note 471: T 137.9571 G2 = 98 Hz, tnext=119, dur=1492, soft 35 -> 24, sustain 892 -> 1492
; T 138.0644 Sustain 0 (Instrument 1)
; T 138.0644 Sustain 0 (Instrument 2)
    db 3, 0, 94, 5, 42, 2, 30, 2  ; Note 472: T 138.0760 C#5 = 554 Hz, tnext=3, dur=1374, soft 43 -> 30, sustain 1098 -> 1374
    db 244, 1, 90, 5, 21, 1, 23, 1  ; Note 473: T 138.0794 C#4 = 277 Hz, tnext=500, dur=1370, soft 34 -> 23, sustain 1104 -> 1370
; T 138.4084 Sustain 127 (Instrument 1)
; T 138.4084 Sustain 127 (Instrument 2)
    db 206, 1, 107, 3, 74, 1, 23, 1  ; Note 474: T 138.5792 E4 = 330 Hz, tnext=462, dur=875, soft 33 -> 23
    db 55, 1, 244, 1, 210, 1, 26, 2  ; Note 475: T 139.0409 A#4 = 466 Hz, tnext=311, dur=500, soft 38 -> 26
    db 27, 0, 124, 17, 52, 0, 27, 1  ; Note 476: T 139.3514 G#1 = 52 Hz, tnext=27, dur=4476, soft 39 -> 27, sustain 4020 -> 4476
    db 97, 0, 97, 17, 104, 0, 27, 1  ; Note 477: T 139.3780 G#2 = 104 Hz, tnext=97, dur=4449, soft 39 -> 27, sustain 3985 -> 4449
; T 139.4495 Sustain 0 (Instrument 1)
; T 139.4495 Sustain 0 (Instrument 2)
    db 108, 1, 145, 4, 11, 2, 32, 2  ; Note 478: T 139.4749 C5 = 523 Hz, tnext=364, dur=1169, soft 47 -> 32, sustain 478 -> 1169
; T 139.7693 Sustain 127 (Instrument 1)
; T 139.7693 Sustain 127 (Instrument 2)
    db 97, 1, 38, 3, 6, 1, 23, 1  ; Note 479: T 139.8385 C4 = 262 Hz, tnext=353, dur=806, soft 33 -> 23, sustain 485 -> 806
    db 112, 1, 217, 1, 55, 1, 23, 1  ; Note 480: T 140.1917 D#4 = 311 Hz, tnext=368, dur=473, soft 33 -> 23
    db 135, 1, 116, 4, 159, 1, 30, 2  ; Note 481: T 140.5599 G#4 = 415 Hz, tnext=391, dur=1140, soft 43 -> 30
; T 140.6442 Sustain 0 (Instrument 1)
; T 140.6442 Sustain 0 (Instrument 2)
; T 140.8901 Sustain 127 (Instrument 1)
; T 140.8901 Sustain 127 (Instrument 2)
    db 112, 1, 236, 2, 6, 1, 25, 1  ; Note 482: T 140.9512 C4 = 262 Hz, tnext=368, dur=748, soft 36 -> 25, sustain 439 -> 748
    db 67, 1, 140, 1, 55, 1, 23, 1  ; Note 483: T 141.3194 D#4 = 311 Hz, tnext=323, dur=396, soft 33 -> 23
    db 147, 1, 203, 4, 184, 1, 33, 2  ; Note 484: T 141.6426 A4 = 440 Hz, tnext=403, dur=1227, soft 48 -> 33, sustain 1125 -> 1227
; T 141.6992 Sustain 0 (Instrument 1)
; T 141.6992 Sustain 0 (Instrument 2)
    db 151, 1, 56, 3, 6, 1, 23, 1  ; Note 485: T 142.0455 C4 = 262 Hz, tnext=407, dur=824, soft 33 -> 23, sustain 567 -> 824
; T 142.1263 Sustain 127 (Instrument 1)
; T 142.1263 Sustain 127 (Instrument 2)
    db 64, 1, 223, 1, 55, 1, 23, 1  ; Note 486: T 142.4528 D#4 = 311 Hz, tnext=320, dur=479, soft 34 -> 23
    db 67, 1, 31, 4, 114, 1, 30, 1  ; Note 487: T 142.7724 F#4 = 370 Hz, tnext=323, dur=1055, soft 44 -> 30, sustain 880 -> 1055
; T 142.8693 Sustain 0 (Instrument 1)
; T 142.8693 Sustain 0 (Instrument 2)
    db 89, 1, 220, 2, 6, 1, 23, 1  ; Note 488: T 143.0955 C4 = 262 Hz, tnext=345, dur=732, soft 33 -> 23, sustain 382 -> 732
; T 143.1497 Sustain 127 (Instrument 1)
; T 143.1497 Sustain 127 (Instrument 2)
    db 43, 1, 131, 1, 55, 1, 23, 1  ; Note 489: T 143.4405 D#4 = 311 Hz, tnext=299, dur=387, soft 33 -> 23, sustain 234 -> 387
    db 2, 0, 186, 16, 104, 0, 25, 1  ; Note 490: T 143.7393 G#2 = 104 Hz, tnext=2, dur=4282, soft 37 -> 25, sustain 3784 -> 4282
    db 74, 1, 184, 16, 52, 0, 25, 1  ; Note 491: T 143.7416 G#1 = 52 Hz, tnext=330, dur=4280, soft 37 -> 25, sustain 3775 -> 4280
; T 143.8270 Sustain 0 (Instrument 1)
; T 143.8270 Sustain 0 (Instrument 2)
; T 144.0485 Sustain 127 (Instrument 1)
; T 144.0485 Sustain 127 (Instrument 2)
    db 89, 1, 239, 2, 6, 1, 23, 1  ; Note 492: T 144.0716 C4 = 262 Hz, tnext=345, dur=751, soft 33 -> 23
    db 79, 1, 150, 5, 55, 1, 23, 1  ; Note 493: T 144.4166 D#4 = 311 Hz, tnext=335, dur=1430, soft 34 -> 23, sustain 697 -> 1430
    db 145, 1, 71, 4, 208, 0, 30, 1  ; Note 494: T 144.7512 G#3 = 208 Hz, tnext=401, dur=1095, soft 44 -> 30, sustain 800 -> 1095
; T 144.7650 Sustain 0 (Instrument 1)
; T 144.7650 Sustain 0 (Instrument 2)
; T 144.9889 Sustain 127 (Instrument 1)
; T 144.9889 Sustain 127 (Instrument 2)
    db 64, 1, 181, 2, 6, 1, 23, 1  ; Note 495: T 145.1527 C4 = 262 Hz, tnext=320, dur=693, soft 33 -> 23, sustain 433 -> 693
    db 64, 1, 38, 2, 55, 1, 23, 1  ; Note 496: T 145.4723 D#4 = 311 Hz, tnext=320, dur=550, soft 33 -> 23
    db 117, 1, 103, 4, 220, 0, 33, 1  ; Note 497: T 145.7919 A3 = 220 Hz, tnext=373, dur=1127, soft 48 -> 33, sustain 748 -> 1127
; T 145.8461 Sustain 0 (Instrument 1)
; T 145.8461 Sustain 0 (Instrument 2)
; T 146.0757 Sustain 127 (Instrument 1)
; T 146.0757 Sustain 127 (Instrument 2)
    db 90, 1, 242, 2, 6, 1, 23, 1  ; Note 498: T 146.1646 C4 = 262 Hz, tnext=346, dur=754, soft 33 -> 23, sustain 497 -> 754
    db 95, 1, 180, 1, 55, 1, 23, 1  ; Note 499: T 146.5107 D#4 = 311 Hz, tnext=351, dur=436, soft 33 -> 23
    db 173, 1, 136, 4, 185, 0, 28, 1  ; Note 500: T 146.8613 F#3 = 185 Hz, tnext=429, dur=1160, soft 40 -> 28, sustain 991 -> 1160
; T 146.9189 Sustain 0 (Instrument 1)
; T 146.9189 Sustain 0 (Instrument 2)
; T 147.1842 Sustain 127 (Instrument 1)
; T 147.1842 Sustain 127 (Instrument 2)
    db 140, 1, 219, 2, 6, 1, 23, 1  ; Note 501: T 147.2903 C4 = 262 Hz, tnext=396, dur=731, soft 33 -> 23, sustain 616 -> 731
    db 230, 0, 80, 1, 55, 1, 23, 1  ; Note 502: T 147.6859 D#4 = 311 Hz, tnext=230, dur=336, soft 33 -> 23, sustain 247 -> 336
    db 21, 0, 233, 15, 52, 0, 24, 1  ; Note 503: T 147.9154 G#1 = 52 Hz, tnext=21, dur=4073, soft 35 -> 24, sustain 3588 -> 4073
    db 108, 0, 212, 15, 104, 0, 25, 1  ; Note 504: T 147.9362 G#2 = 104 Hz, tnext=108, dur=4052, soft 36 -> 25, sustain 3558 -> 4052
; T 148.0215 Sustain 0 (Instrument 1)
; T 148.0215 Sustain 0 (Instrument 2)
    db 55, 1, 202, 11, 165, 0, 25, 1  ; Note 505: T 148.0446 E3 = 165 Hz, tnext=311, dur=3018, soft 37 -> 25, sustain 301 -> 3018
; T 148.2361 Sustain 127 (Instrument 1)
; T 148.2361 Sustain 127 (Instrument 2)
    db 50, 1, 147, 10, 74, 1, 23, 1  ; Note 506: T 148.3560 E4 = 330 Hz, tnext=306, dur=2707, soft 33 -> 23, sustain 159 -> 2707
    db 99, 1, 97, 9, 159, 1, 26, 2  ; Note 507: T 148.6616 G#4 = 415 Hz, tnext=355, dur=2401, soft 38 -> 26, sustain 548 -> 2401
    db 84, 1, 254, 7, 42, 2, 35, 2  ; Note 508: T 149.0169 C#5 = 554 Hz, tnext=340, dur=2046, soft 50 -> 35, sustain 1069 -> 2046
    db 22, 1, 170, 6, 74, 1, 23, 1  ; Note 509: T 149.3571 E4 = 330 Hz, tnext=278, dur=1706, soft 33 -> 23, sustain 377 -> 1706
    db 118, 1, 148, 5, 159, 1, 26, 2  ; Note 510: T 149.6350 G#4 = 415 Hz, tnext=374, dur=1428, soft 38 -> 26, sustain 465 -> 1428
    db 31, 1, 30, 4, 147, 2, 34, 2  ; Note 511: T 150.0087 E5 = 659 Hz, tnext=287, dur=1054, soft 49 -> 34, sustain 722 -> 1054
    db 74, 1, 9, 3, 74, 1, 23, 1  ; Note 512: T 150.2959 E4 = 330 Hz, tnext=330, dur=777, soft 33 -> 23
    db 131, 1, 244, 1, 159, 1, 26, 2  ; Note 513: T 150.6257 G#4 = 415 Hz, tnext=387, dur=500, soft 38 -> 26
    db 53, 1, 207, 3, 42, 2, 35, 2  ; Note 514: T 151.0131 C#5 = 554 Hz, tnext=309, dur=975, soft 51 -> 35, sustain 736 -> 975
; T 151.0627 Sustain 0 (Instrument 1)
; T 151.0627 Sustain 0 (Instrument 2)
; T 151.2748 Sustain 127 (Instrument 1)
; T 151.2748 Sustain 127 (Instrument 2)
    db 33, 1, 154, 2, 74, 1, 23, 1  ; Note 515: T 151.3221 E4 = 330 Hz, tnext=289, dur=666, soft 33 -> 23, sustain 368 -> 666
    db 16, 1, 121, 1, 159, 1, 26, 2  ; Note 516: T 151.6114 G#4 = 415 Hz, tnext=272, dur=377, soft 38 -> 26, sustain 192 -> 377
    db 20, 0, 11, 15, 52, 0, 25, 1  ; Note 517: T 151.8835 G#1 = 52 Hz, tnext=20, dur=3851, soft 36 -> 25, sustain 3484 -> 3851
    db 44, 1, 248, 14, 104, 0, 25, 1  ; Note 518: T 151.9031 G#2 = 104 Hz, tnext=300, dur=3832, soft 36 -> 25, sustain 3456 -> 3832
; T 151.9884 Sustain 0 (Instrument 1)
; T 151.9884 Sustain 0 (Instrument 2)
    db 2, 1, 80, 6, 165, 0, 23, 1  ; Note 519: T 152.2028 E3 = 165 Hz, tnext=258, dur=1616, soft 33 -> 23, sustain 730 -> 1616
; T 152.2248 Sustain 127 (Instrument 1)
; T 152.2248 Sustain 127 (Instrument 2)
    db 112, 1, 78, 5, 208, 0, 23, 1  ; Note 520: T 152.4611 G#3 = 208 Hz, tnext=368, dur=1358, soft 34 -> 23, sustain 521 -> 1358
    db 71, 1, 222, 3, 21, 1, 31, 1  ; Note 521: T 152.8289 C#4 = 277 Hz, tnext=327, dur=990, soft 45 -> 31
    db 3, 1, 151, 2, 165, 0, 23, 1  ; Note 522: T 153.1563 E3 = 165 Hz, tnext=259, dur=663, soft 33 -> 23, sustain 621 -> 663
    db 83, 1, 148, 1, 208, 0, 23, 1  ; Note 523: T 153.4157 G#3 = 208 Hz, tnext=339, dur=404, soft 33 -> 23, sustain 398 -> 404
    db 112, 1, 129, 4, 74, 1, 28, 1  ; Note 524: T 153.7546 E4 = 330 Hz, tnext=368, dur=1153, soft 40 -> 28, sustain 706 -> 1153
; T 153.8192 Sustain 0 (Instrument 1)
; T 153.8192 Sustain 0 (Instrument 2)
; T 154.0636 Sustain 127 (Instrument 1)
; T 154.0636 Sustain 127 (Instrument 2)
    db 25, 1, 17, 3, 165, 0, 23, 1  ; Note 525: T 154.1224 E3 = 165 Hz, tnext=281, dur=785, soft 33 -> 23, sustain 726 -> 785
    db 126, 1, 248, 1, 208, 0, 23, 1  ; Note 526: T 154.4037 G#3 = 208 Hz, tnext=382, dur=504, soft 33 -> 23, sustain 473 -> 504
    db 97, 1, 182, 3, 21, 1, 28, 1  ; Note 527: T 154.7852 C#4 = 277 Hz, tnext=353, dur=950, soft 40 -> 28, sustain 763 -> 950
; T 154.9074 Sustain 0 (Instrument 1)
; T 154.9074 Sustain 0 (Instrument 2)
; T 155.0918 Sustain 127 (Instrument 1)
; T 155.0918 Sustain 127 (Instrument 2)
    db 44, 1, 85, 2, 165, 0, 23, 1  ; Note 528: T 155.1379 E3 = 165 Hz, tnext=300, dur=597, soft 33 -> 23, sustain 377 -> 597
    db 178, 0, 41, 1, 208, 0, 23, 1  ; Note 529: T 155.4375 G#3 = 208 Hz, tnext=178, dur=297, soft 33 -> 23, sustain 180 -> 297
    db 39, 0, 148, 14, 52, 0, 25, 1  ; Note 530: T 155.6150 G#1 = 52 Hz, tnext=39, dur=3732, soft 36 -> 25, sustain 1182 -> 3732
    db 114, 0, 109, 14, 104, 0, 25, 1  ; Note 531: T 155.6542 G#2 = 104 Hz, tnext=114, dur=3693, soft 36 -> 25, sustain 1495 -> 3693
; T 155.7348 Sustain 0 (Instrument 1)
; T 155.7348 Sustain 0 (Instrument 2)
    db 16, 1, 251, 13, 156, 0, 32, 1  ; Note 532: T 155.7682 D#3 = 156 Hz, tnext=272, dur=3579, soft 47 -> 32, sustain 626 -> 3579
; T 155.9734 Sustain 127 (Instrument 1)
; T 155.9734 Sustain 127 (Instrument 2)
; T 156.0287 Soft 0 (Instrument 1)
; T 156.0287 Soft 0 (Instrument 2)
    db 62, 1, 235, 12, 220, 0, 36, 1  ; Note 533: T 156.0402 A3 = 220 Hz, tnext=318, dur=3307, sustain 727 -> 3307
    db 64, 1, 173, 11, 185, 0, 38, 1  ; Note 534: T 156.3583 F#3 = 185 Hz, tnext=320, dur=2989, sustain 403 -> 2989
    db 48, 1, 109, 10, 6, 1, 34, 1  ; Note 535: T 156.6786 C4 = 262 Hz, tnext=304, dur=2669, sustain 293 -> 2669
    db 38, 1, 60, 9, 220, 0, 38, 1  ; Note 536: T 156.9829 A3 = 220 Hz, tnext=294, dur=2364, sustain 561 -> 2364
    db 10, 1, 23, 8, 55, 1, 42, 1  ; Note 537: T 157.2768 D#4 = 311 Hz, tnext=266, dur=2071, sustain 404 -> 2071
    db 97, 1, 12, 7, 6, 1, 45, 1  ; Note 538: T 157.5430 C4 = 262 Hz, tnext=353, dur=1804, sustain 439 -> 1804
    db 2, 1, 172, 5, 114, 1, 45, 1  ; Note 539: T 157.8956 F#4 = 370 Hz, tnext=258, dur=1452, sustain 171 -> 1452
    db 33, 1, 170, 4, 55, 1, 49, 1  ; Note 540: T 158.1537 D#4 = 311 Hz, tnext=289, dur=1194, sustain 544 -> 1194
    db 27, 1, 136, 3, 184, 1, 51, 2  ; Note 541: T 158.4430 A4 = 440 Hz, tnext=283, dur=904, sustain 491 -> 904
    db 23, 1, 109, 2, 114, 1, 44, 1  ; Note 542: T 158.7265 F#4 = 370 Hz, tnext=279, dur=621, sustain 384 -> 621
    db 160, 0, 86, 1, 11, 2, 49, 2  ; Note 543: T 159.0053 C5 = 523 Hz, tnext=160, dur=342, sustain 83 -> 342
    db 40, 0, 64, 13, 52, 0, 44, 1  ; Note 544: T 159.1654 G#1 = 52 Hz, tnext=40, dur=3392, sustain 1246 -> 3392
    db 114, 0, 24, 13, 104, 0, 45, 1  ; Note 545: T 159.2057 G#2 = 104 Hz, tnext=114, dur=3352, sustain 1291 -> 3352
    db 11, 1, 166, 12, 165, 0, 55, 1  ; Note 546: T 159.3198 E3 = 165 Hz, tnext=267, dur=3238, sustain 331 -> 3238
; T 159.3474 Sustain 0 (Instrument 1)
; T 159.3474 Sustain 0 (Instrument 2)
; T 159.5778 Sustain 127 (Instrument 1)
; T 159.5778 Sustain 127 (Instrument 2)
    db 252, 0, 155, 11, 21, 1, 39, 1  ; Note 547: T 159.5870 C#4 = 277 Hz, tnext=252, dur=2971, sustain 253 -> 2971
    db 19, 1, 159, 10, 208, 0, 43, 1  ; Note 548: T 159.8393 G#3 = 208 Hz, tnext=275, dur=2719, sustain 313 -> 2719
    db 36, 1, 139, 9, 74, 1, 46, 1  ; Note 549: T 160.1146 E4 = 330 Hz, tnext=292, dur=2443, sustain 576 -> 2443
    db 248, 0, 104, 8, 21, 1, 42, 1  ; Note 550: T 160.4061 C#4 = 277 Hz, tnext=248, dur=2152, sustain 344 -> 2152
    db 15, 1, 112, 7, 159, 1, 47, 2  ; Note 551: T 160.6537 G#4 = 415 Hz, tnext=271, dur=1904, sustain 238 -> 1904
    db 15, 1, 97, 6, 74, 1, 36, 1  ; Note 552: T 160.9244 E4 = 330 Hz, tnext=271, dur=1633, sustain 453 -> 1633
    db 12, 1, 83, 5, 42, 2, 49, 2  ; Note 553: T 161.1952 C#5 = 554 Hz, tnext=268, dur=1363, sustain 453 -> 1363
    db 12, 1, 70, 4, 159, 1, 53, 2  ; Note 554: T 161.4636 G#4 = 415 Hz, tnext=268, dur=1094, sustain 485 -> 1094
    db 10, 1, 58, 3, 147, 2, 56, 2  ; Note 555: T 161.7320 E5 = 659 Hz, tnext=266, dur=826, sustain 317 -> 826
    db 240, 0, 48, 2, 42, 2, 53, 2  ; Note 556: T 161.9981 C#5 = 554 Hz, tnext=240, dur=560, sustain 303 -> 560
    db 172, 0, 64, 1, 159, 1, 53, 2  ; Note 557: T 162.2377 G#4 = 415 Hz, tnext=172, dur=320, sustain 119 -> 320
; T 162.3701 Soft 0 (Instrument 1)
; T 162.3701 Soft 0 (Instrument 2)
    db 26, 0, 168, 11, 52, 0, 38, 1  ; Note 558: T 162.4093 G#1 = 52 Hz, tnext=26, dur=2984, sustain 1315 -> 2984
    db 95, 0, 141, 11, 104, 0, 38, 1  ; Note 559: T 162.4358 G#2 = 104 Hz, tnext=95, dur=2957, sustain 1300 -> 2957
    db 236, 0, 47, 11, 21, 1, 39, 1  ; Note 560: T 162.5303 C#4 = 277 Hz, tnext=236, dur=2863, sustain 447 -> 2863
; T 162.5579 Sustain 0 (Instrument 1)
; T 162.5579 Sustain 0 (Instrument 2)
; T 162.7653 Sustain 127 (Instrument 1)
; T 162.7653 Sustain 127 (Instrument 2)
    db 244, 0, 67, 10, 136, 1, 59, 2  ; Note 561: T 162.7664 G4 = 392 Hz, tnext=244, dur=2627, sustain 434 -> 2627
    db 248, 0, 78, 9, 74, 1, 43, 1  ; Note 562: T 163.0106 E4 = 330 Hz, tnext=248, dur=2382, sustain 307 -> 2382
    db 227, 0, 87, 8, 210, 1, 55, 2  ; Note 563: T 163.2582 A#4 = 466 Hz, tnext=227, dur=2135, sustain 250 -> 2135
    db 218, 0, 116, 7, 136, 1, 58, 2  ; Note 564: T 163.4850 G4 = 392 Hz, tnext=218, dur=1908, sustain 330 -> 1908
    db 254, 0, 154, 6, 42, 2, 61, 2  ; Note 565: T 163.7027 C#5 = 554 Hz, tnext=254, dur=1690, sustain 405 -> 1690
    db 249, 0, 156, 5, 210, 1, 64, 2  ; Note 566: T 163.9571 A#4 = 466 Hz, tnext=249, dur=1436, sustain 307 -> 1436
    db 254, 0, 163, 4, 147, 2, 61, 2  ; Note 567: T 164.2059 E5 = 659 Hz, tnext=254, dur=1187, sustain 156 -> 1187
    db 207, 0, 165, 3, 42, 2, 61, 2  ; Note 568: T 164.4603 C#5 = 554 Hz, tnext=207, dur=933, sustain 294 -> 933
    db 218, 0, 213, 2, 16, 3, 64, 2  ; Note 569: T 164.6676 G5 = 784 Hz, tnext=218, dur=725, sustain 303 -> 725
    db 200, 0, 252, 1, 147, 2, 67, 2  ; Note 570: T 164.8852 E5 = 659 Hz, tnext=200, dur=508, sustain 240 -> 508
    db 143, 0, 51, 1, 164, 3, 69, 2  ; Note 571: T 165.0856 A#5 = 932 Hz, tnext=143, dur=307, sustain 88 -> 307
    db 12, 0, 96, 33, 52, 0, 55, 1  ; Note 572: T 165.2284 G#1 = 52 Hz, tnext=12, dur=8544, sustain 8064 -> 8544
    db 121, 0, 84, 33, 104, 0, 55, 1  ; Note 573: T 165.2399 G#2 = 104 Hz, tnext=121, dur=8532, sustain 8051 -> 8532
    db 222, 0, 124, 25, 114, 1, 54, 1  ; Note 574: T 165.3608 F#4 = 370 Hz, tnext=222, dur=6524, sustain 319 -> 6524
; T 165.3930 Sustain 0 (Instrument 1)
; T 165.3930 Sustain 0 (Instrument 2)
    db 198, 0, 158, 24, 11, 2, 70, 2  ; Note 575: T 165.5830 C5 = 523 Hz, tnext=198, dur=6302, sustain 256 -> 6302
; T 165.6326 Sustain 127 (Instrument 1)
; T 165.6326 Sustain 127 (Instrument 2)
    db 224, 0, 216, 23, 184, 1, 70, 2  ; Note 576: T 165.7811 A4 = 440 Hz, tnext=224, dur=6104, sustain 267 -> 6104
    db 229, 0, 248, 22, 110, 2, 70, 2  ; Note 577: T 166.0056 D#5 = 622 Hz, tnext=229, dur=5880, sustain 205 -> 5880
    db 170, 0, 18, 22, 11, 2, 70, 2  ; Note 578: T 166.2348 C5 = 523 Hz, tnext=170, dur=5650, sustain 254 -> 5650
    db 251, 0, 104, 21, 228, 2, 70, 2  ; Note 579: T 166.4052 F#5 = 740 Hz, tnext=251, dur=5480, sustain 322 -> 5480
    db 196, 0, 109, 20, 110, 2, 70, 2  ; Note 580: T 166.6562 D#5 = 622 Hz, tnext=196, dur=5229, sustain 213 -> 5229
    db 196, 0, 169, 19, 112, 3, 70, 2  ; Note 581: T 166.8520 A5 = 880 Hz, tnext=196, dur=5033, sustain 98 -> 5033
    db 213, 0, 230, 18, 228, 2, 70, 2  ; Note 582: T 167.0477 F#5 = 740 Hz, tnext=213, dur=4838, sustain 164 -> 4838
    db 204, 0, 17, 18, 23, 4, 70, 2  ; Note 583: T 167.2607 C6 = 1047 Hz, tnext=204, dur=4625, sustain 241 -> 4625
    db 190, 0, 69, 17, 112, 3, 70, 2  ; Note 584: T 167.4644 A5 = 880 Hz, tnext=190, dur=4421, sustain 228 -> 4421
    db 205, 0, 135, 16, 221, 4, 70, 2  ; Note 585: T 167.6544 D#6 = 1245 Hz, tnext=205, dur=4231, sustain 154 -> 4231
    db 221, 0, 186, 15, 23, 4, 67, 2  ; Note 586: T 167.8592 C6 = 1047 Hz, tnext=221, dur=4026, sustain 188 -> 4026
    db 173, 0, 221, 14, 228, 2, 64, 2  ; Note 587: T 168.0802 F#5 = 740 Hz, tnext=173, dur=3805, sustain 144 -> 3805
    db 240, 0, 48, 14, 112, 3, 62, 2  ; Note 588: T 168.2529 A5 = 880 Hz, tnext=240, dur=3632, sustain 297 -> 3632
    db 201, 0, 64, 13, 110, 2, 59, 2  ; Note 589: T 168.4934 D#5 = 622 Hz, tnext=201, dur=3392, sustain 266 -> 3392
    db 226, 0, 118, 12, 228, 2, 57, 2  ; Note 590: T 168.6949 F#5 = 740 Hz, tnext=226, dur=3190, sustain 270 -> 3190
    db 204, 0, 149, 11, 11, 2, 54, 2  ; Note 591: T 168.9205 C5 = 523 Hz, tnext=204, dur=2965, sustain 221 -> 2965
    db 203, 0, 201, 10, 110, 2, 51, 2  ; Note 592: T 169.1242 D#5 = 622 Hz, tnext=203, dur=2761, sustain 224 -> 2761
    db 203, 0, 255, 9, 184, 1, 49, 2  ; Note 593: T 169.3268 A4 = 440 Hz, tnext=203, dur=2559, sustain 267 -> 2559
    db 218, 0, 52, 9, 11, 2, 46, 2  ; Note 594: T 169.5294 C5 = 523 Hz, tnext=218, dur=2356, sustain 226 -> 2356
    db 213, 0, 90, 8, 114, 1, 38, 1  ; Note 595: T 169.7469 F#4 = 370 Hz, tnext=213, dur=2138, sustain 243 -> 2138
    db 227, 0, 133, 7, 184, 1, 41, 2  ; Note 596: T 169.9599 A4 = 440 Hz, tnext=227, dur=1925, sustain 254 -> 1925
    db 223, 0, 163, 6, 55, 1, 33, 1  ; Note 597: T 170.1866 D#4 = 311 Hz, tnext=223, dur=1699, sustain 287 -> 1699
    db 225, 0, 195, 5, 114, 1, 33, 1  ; Note 598: T 170.4099 F#4 = 370 Hz, tnext=225, dur=1475, sustain 352 -> 1475
    db 243, 0, 227, 4, 6, 1, 33, 1  ; Note 599: T 170.6344 C4 = 262 Hz, tnext=243, dur=1251, sustain 265 -> 1251
    db 236, 0, 240, 3, 55, 1, 33, 1  ; Note 600: T 170.8772 D#4 = 311 Hz, tnext=236, dur=1008, sustain 273 -> 1008
    db 197, 0, 4, 3, 220, 0, 33, 1  ; Note 601: T 171.1132 A3 = 220 Hz, tnext=197, dur=772, sustain 253 -> 772
    db 215, 0, 63, 2, 6, 1, 33, 1  ; Note 602: T 171.3100 C4 = 262 Hz, tnext=215, dur=575, sustain 206 -> 575
    db 223, 0, 104, 1, 185, 0, 33, 1  ; Note 603: T 171.5252 F#3 = 185 Hz, tnext=223, dur=360, sustain 260 -> 360
    db 29, 1, 109, 4, 220, 0, 33, 1  ; Note 604: T 171.7484 A3 = 220 Hz, tnext=285, dur=1133, sustain 606 -> 1133
; T 171.8853 Sustain 0 (Instrument 1)
; T 171.8853 Sustain 0 (Instrument 2)
    db 76, 1, 80, 3, 156, 0, 38, 1  ; Note 605: T 172.0337 D#3 = 156 Hz, tnext=332, dur=848, sustain 614 -> 848
; T 172.1419 Sustain 127 (Instrument 1)
; T 172.1419 Sustain 127 (Instrument 2)
    db 133, 1, 4, 2, 185, 0, 33, 1  ; Note 606: T 172.3662 F#3 = 185 Hz, tnext=389, dur=516, sustain 301 -> 516
    db 105, 0, 249, 3, 220, 0, 34, 1  ; Note 607: T 172.7551 A3 = 220 Hz, tnext=105, dur=1017, sustain 407 -> 1017
    db 51, 1, 144, 3, 139, 0, 41, 1  ; Note 608: T 172.8598 C#3 = 139 Hz, tnext=307, dur=912, sustain 506 -> 912
; T 172.8817 Sustain 0 (Instrument 1)
; T 172.8817 Sustain 0 (Instrument 2)
; T 173.1210 Sustain 127 (Instrument 1)
; T 173.1210 Sustain 127 (Instrument 2)
    db 7, 1, 93, 2, 185, 0, 33, 1  ; Note 609: T 173.1670 F#3 = 185 Hz, tnext=263, dur=605, sustain 396 -> 605
    db 160, 0, 190, 2, 220, 0, 33, 1  ; Note 610: T 173.4305 A3 = 220 Hz, tnext=160, dur=702
    db 44, 0, 125, 15, 52, 0, 35, 1  ; Note 611: T 173.5904 G#1 = 52 Hz, tnext=44, dur=3965, sustain 3461 -> 3965
    db 123, 0, 82, 15, 104, 0, 35, 1  ; Note 612: T 173.6341 G#2 = 104 Hz, tnext=123, dur=3922, sustain 3429 -> 3922
    db 49, 1, 163, 6, 131, 0, 40, 1  ; Note 613: T 173.7573 C3 = 131 Hz, tnext=305, dur=1699, sustain 1363 -> 1699
; T 173.7722 Sustain 0 (Instrument 1)
; T 173.7722 Sustain 0 (Instrument 2)
    db 246, 0, 114, 5, 185, 0, 34, 1  ; Note 614: T 174.0622 F#3 = 185 Hz, tnext=246, dur=1394, sustain 372 -> 1394
; T 174.1335 Sustain 127 (Instrument 1)
; T 174.1335 Sustain 127 (Instrument 2)
    db 252, 0, 124, 4, 208, 0, 34, 1  ; Note 615: T 174.3084 G#3 = 208 Hz, tnext=252, dur=1148, sustain 357 -> 1148
    db 27, 1, 128, 3, 220, 0, 34, 1  ; Note 616: T 174.5604 A3 = 220 Hz, tnext=283, dur=896, sustain 394 -> 896
    db 240, 0, 101, 2, 208, 0, 33, 1  ; Note 617: T 174.8434 G#3 = 208 Hz, tnext=240, dur=613, sustain 277 -> 613
    db 163, 1, 241, 1, 185, 0, 33, 1  ; Note 618: T 175.0839 F#3 = 185 Hz, tnext=419, dur=497
; T 175.4566 Sustain 0 (Instrument 1)
; T 175.4566 Sustain 0 (Instrument 2)
    db 151, 1, 2, 4, 156, 0, 40, 1  ; Note 619: T 175.5026 D#3 = 156 Hz, tnext=407, dur=1026, sustain 673 -> 1026
; T 175.8362 Sustain 127 (Instrument 1)
; T 175.8362 Sustain 127 (Instrument 2)
    db 33, 1, 107, 2, 185, 0, 33, 1  ; Note 620: T 175.9098 F#3 = 185 Hz, tnext=289, dur=619, sustain 347 -> 619
    db 50, 1, 127, 1, 220, 0, 33, 1  ; Note 621: T 176.1984 A3 = 220 Hz, tnext=306, dur=383
    db 111, 1, 27, 4, 139, 0, 40, 1  ; Note 622: T 176.5044 C#3 = 139 Hz, tnext=367, dur=1051, sustain 539 -> 1051
; T 176.5285 Sustain 0 (Instrument 1)
; T 176.5285 Sustain 0 (Instrument 2)
; T 176.8655 Sustain 127 (Instrument 1)
; T 176.8655 Sustain 127 (Instrument 2)
    db 13, 1, 172, 2, 185, 0, 33, 1  ; Note 623: T 176.8713 F#3 = 185 Hz, tnext=269, dur=684, sustain 448 -> 684
    db 209, 0, 199, 1, 220, 0, 33, 1  ; Note 624: T 177.1404 A3 = 220 Hz, tnext=209, dur=455
    db 55, 0, 242, 16, 52, 0, 35, 1  ; Note 625: T 177.3497 G#1 = 52 Hz, tnext=55, dur=4338, sustain 3982 -> 4338
    db 136, 0, 187, 16, 104, 0, 34, 1  ; Note 626: T 177.4049 G#2 = 104 Hz, tnext=136, dur=4283, sustain 3891 -> 4283
    db 151, 1, 125, 7, 131, 0, 36, 1  ; Note 627: T 177.5406 C3 = 131 Hz, tnext=407, dur=1917, sustain 1650 -> 1917
; T 177.5556 Sustain 0 (Instrument 1)
; T 177.5556 Sustain 0 (Instrument 2)
    db 2, 1, 87, 1, 185, 0, 34, 1  ; Note 628: T 177.9478 F#3 = 185 Hz, tnext=258, dur=343
    db 54, 1, 120, 1, 208, 0, 37, 1  ; Note 629: T 178.2054 G#3 = 208 Hz, tnext=310, dur=376
    db 37, 1, 153, 1, 220, 0, 39, 1  ; Note 630: T 178.5159 A3 = 220 Hz, tnext=293, dur=409
    db 14, 1, 137, 2, 208, 0, 35, 1  ; Note 631: T 178.8092 G#3 = 208 Hz, tnext=270, dur=649, sustain 294 -> 649
; T 178.9380 Soft 127 (Instrument 1)
; T 178.9380 Soft 127 (Instrument 2)
; T 179.0611 Sustain 127 (Instrument 1)
; T 179.0611 Sustain 127 (Instrument 2)
    db 229, 1, 60, 2, 185, 0, 23, 1  ; Note 632: T 179.0795 F#3 = 185 Hz, tnext=485, dur=572, soft 33 -> 23
; T 179.4579 Sustain 0 (Instrument 1)
; T 179.4579 Sustain 0 (Instrument 2)
    db 199, 1, 99, 4, 147, 0, 33, 1  ; Note 633: T 179.5648 D3 = 147 Hz, tnext=455, dur=1123, soft 48 -> 33, sustain 769 -> 1123
; T 179.9637 Sustain 127 (Instrument 1)
; T 179.9637 Sustain 127 (Instrument 2)
    db 11, 1, 156, 2, 185, 0, 23, 1  ; Note 634: T 180.0201 F#3 = 185 Hz, tnext=267, dur=668, soft 34 -> 23, sustain 384 -> 668
    db 61, 1, 145, 1, 220, 0, 23, 1  ; Note 635: T 180.2868 A3 = 220 Hz, tnext=317, dur=401, soft 33 -> 23, sustain 394 -> 401
    db 150, 1, 60, 4, 139, 0, 25, 1  ; Note 636: T 180.6041 C#3 = 139 Hz, tnext=406, dur=1084, soft 37 -> 25, sustain 815 -> 1084
; T 180.6880 Sustain 0 (Instrument 1)
; T 180.6880 Sustain 0 (Instrument 2)
    db 82, 1, 166, 2, 185, 0, 23, 1  ; Note 637: T 181.0099 F#3 = 185 Hz, tnext=338, dur=678, soft 33 -> 23, sustain 491 -> 678
; T 181.0444 Sustain 127 (Instrument 1)
; T 181.0444 Sustain 127 (Instrument 2)
    db 224, 0, 25, 2, 220, 0, 23, 1  ; Note 638: T 181.3479 A3 = 220 Hz, tnext=224, dur=537, soft 33 -> 23
    db 40, 0, 200, 8, 52, 0, 23, 1  ; Note 639: T 181.5721 G#1 = 52 Hz, tnext=40, dur=2248, soft 33 -> 23, sustain 1903 -> 2248
    db 136, 0, 159, 8, 104, 0, 23, 1  ; Note 640: T 181.6123 G#2 = 104 Hz, tnext=136, dur=2207, soft 33 -> 23, sustain 1848 -> 2207
; T 181.6882 Sustain 0 (Instrument 1)
; T 181.6882 Sustain 0 (Instrument 2)
    db 122, 1, 24, 8, 131, 0, 25, 1  ; Note 641: T 181.7480 C3 = 131 Hz, tnext=378, dur=2072, soft 36 -> 25, sustain 1802 -> 2072
    db 84, 1, 162, 1, 185, 0, 24, 1  ; Note 642: T 182.1262 F#3 = 185 Hz, tnext=340, dur=418, soft 35 -> 24
    db 65, 1, 128, 1, 208, 0, 23, 1  ; Note 643: T 182.4665 G#3 = 208 Hz, tnext=321, dur=384, soft 33 -> 23
    db 108, 1, 137, 1, 220, 0, 24, 1  ; Note 644: T 182.7873 A3 = 220 Hz, tnext=364, dur=393, soft 35 -> 24
    db 64, 1, 156, 2, 208, 0, 23, 1  ; Note 645: T 183.1517 G#3 = 208 Hz, tnext=320, dur=668, soft 33 -> 23, sustain 343 -> 668
; T 183.2552 Sustain 127 (Instrument 1)
; T 183.2552 Sustain 127 (Instrument 2)
    db 246, 0, 203, 1, 185, 0, 23, 1  ; Note 646: T 183.4713 F#3 = 185 Hz, tnext=246, dur=459, soft 33 -> 23
    db 21, 0, 105, 9, 55, 0, 24, 1  ; Note 647: T 183.7173 A1 = 55 Hz, tnext=21, dur=2409, soft 35 -> 24, sustain 1661 -> 2409
    db 147, 0, 84, 9, 110, 0, 24, 1  ; Note 648: T 183.7380 A2 = 110 Hz, tnext=147, dur=2388, soft 35 -> 24, sustain 1526 -> 2388
; T 183.8196 Sustain 0 (Instrument 1)
; T 183.8196 Sustain 0 (Instrument 2)
    db 151, 1, 193, 8, 139, 0, 25, 1  ; Note 649: T 183.8851 C#3 = 139 Hz, tnext=407, dur=2241, soft 37 -> 25, sustain 525 -> 2241
    db 99, 1, 42, 7, 165, 0, 23, 1  ; Note 650: T 184.2919 E3 = 165 Hz, tnext=355, dur=1834, soft 33 -> 23, sustain 432 -> 1834
; T 184.3253 Sustain 127 (Instrument 1)
; T 184.3253 Sustain 127 (Instrument 2)
    db 92, 1, 199, 5, 21, 1, 23, 1  ; Note 651: T 184.6470 C#4 = 277 Hz, tnext=348, dur=1479, soft 33 -> 23, sustain 769 -> 1479
    db 162, 1, 107, 4, 139, 0, 23, 1  ; Note 652: T 184.9952 C#3 = 139 Hz, tnext=418, dur=1131, soft 33 -> 23, sustain 441 -> 1131
    db 72, 1, 201, 2, 165, 0, 23, 1  ; Note 653: T 185.4135 E3 = 165 Hz, tnext=328, dur=713, soft 33 -> 23, sustain 342 -> 713
    db 22, 1, 245, 1, 21, 1, 23, 1  ; Note 654: T 185.7411 C#4 = 277 Hz, tnext=278, dur=501, soft 33 -> 23
    db 46, 0, 75, 10, 46, 0, 23, 1  ; Note 655: T 186.0192 F#1 = 46 Hz, tnext=46, dur=2635, soft 34 -> 23, sustain 1674 -> 2635
    db 147, 0, 29, 10, 92, 0, 24, 1  ; Note 656: T 186.0651 F#2 = 92 Hz, tnext=147, dur=2589, soft 35 -> 24, sustain 1715 -> 2589
; T 186.1260 Sustain 0 (Instrument 1)
; T 186.1260 Sustain 0 (Instrument 2)
    db 157, 1, 138, 9, 156, 0, 25, 1  ; Note 657: T 186.2122 D#3 = 156 Hz, tnext=413, dur=2442, soft 37 -> 25, sustain 495 -> 2442
; T 186.5282 Sustain 127 (Instrument 1)
; T 186.5282 Sustain 127 (Instrument 2)
    db 153, 1, 237, 7, 220, 0, 23, 1  ; Note 658: T 186.6248 A3 = 220 Hz, tnext=409, dur=2029, soft 33 -> 23, sustain 533 -> 2029
    db 143, 1, 84, 6, 21, 1, 23, 1  ; Note 659: T 187.0339 C#4 = 277 Hz, tnext=399, dur=1620, soft 33 -> 23, sustain 590 -> 1620
    db 164, 1, 197, 4, 156, 0, 23, 1  ; Note 660: T 187.4327 D#3 = 156 Hz, tnext=420, dur=1221, soft 33 -> 23, sustain 552 -> 1221
    db 148, 1, 33, 3, 220, 0, 23, 1  ; Note 661: T 187.8532 A3 = 220 Hz, tnext=404, dur=801, soft 33 -> 23, sustain 569 -> 801
    db 89, 1, 253, 1, 21, 1, 23, 1  ; Note 662: T 188.2576 C#4 = 277 Hz, tnext=345, dur=509, soft 33 -> 23
    db 67, 0, 10, 12, 52, 0, 23, 1  ; Note 663: T 188.6022 G#1 = 52 Hz, tnext=67, dur=3082, soft 34 -> 23, sustain 2586 -> 3082
; T 188.6539 Sustain 0 (Instrument 1)
; T 188.6539 Sustain 0 (Instrument 2)
    db 68, 0, 200, 11, 104, 0, 24, 1  ; Note 664: T 188.6688 G#2 = 104 Hz, tnext=68, dur=3016, soft 35 -> 24, sustain 2563 -> 3016
    db 148, 1, 106, 5, 156, 0, 25, 1  ; Note 665: T 188.7366 D#3 = 156 Hz, tnext=404, dur=1386, soft 36 -> 25, sustain 1099 -> 1386
; T 188.9273 Sustain 127 (Instrument 1)
; T 188.9273 Sustain 127 (Instrument 2)
    db 160, 1, 214, 3, 208, 0, 23, 1  ; Note 666: T 189.1410 G#3 = 208 Hz, tnext=416, dur=982, soft 33 -> 23, sustain 472 -> 982
; T 189.2696 Sustain 0 (Instrument 1)
; T 189.2696 Sustain 0 (Instrument 2)
    db 241, 1, 54, 2, 6, 1, 23, 1  ; Note 667: T 189.5568 C4 = 262 Hz, tnext=497, dur=566, soft 33 -> 23, sustain 300 -> 566
; T 189.5821 Sustain 127 (Instrument 1)
; T 189.5821 Sustain 127 (Instrument 2)
    db 215, 1, 94, 6, 156, 0, 25, 1  ; Note 668: T 190.0542 D#3 = 156 Hz, tnext=471, dur=1630, soft 36 -> 25, sustain 1349 -> 1630
; T 190.1231 Sustain 0 (Instrument 1)
; T 190.1231 Sustain 0 (Instrument 2)
    db 30, 2, 135, 4, 185, 0, 23, 1  ; Note 669: T 190.5252 F#3 = 185 Hz, tnext=542, dur=1159, soft 33 -> 23, sustain 720 -> 1159
; T 191.0306 Sustain 127 (Instrument 1)
; T 191.0306 Sustain 127 (Instrument 2)
    db 11, 2, 105, 2, 6, 1, 23, 1  ; Note 670: T 191.0674 C4 = 262 Hz, tnext=523, dur=617, soft 33 -> 23, sustain 294 -> 617
    db 6, 0, 201, 22, 69, 0, 23, 1  ; Note 671: T 191.5901 C#2 = 69 Hz, tnext=6, dur=5833, soft 34 -> 23, sustain 1225 -> 5833
    db 7, 0, 195, 22, 139, 0, 23, 1  ; Note 672: T 191.5958 C#3 = 139 Hz, tnext=7, dur=5827, soft 34 -> 23, sustain 2172 -> 5827
    db 19, 0, 188, 22, 104, 0, 24, 1  ; Note 673: T 191.6027 G#2 = 104 Hz, tnext=19, dur=5820, soft 35 -> 24, sustain 1687 -> 5820
    db 26, 2, 169, 22, 165, 0, 24, 1  ; Note 674: T 191.6222 E3 = 165 Hz, tnext=538, dur=5801, soft 35 -> 24, sustain 558 -> 5801
; T 191.6843 Sustain 0 (Instrument 1)
; T 191.6843 Sustain 0 (Instrument 2)
; T 192.1138 Sustain 127 (Instrument 1)
; T 192.1138 Sustain 127 (Instrument 2)
    db 176, 1, 143, 20, 208, 0, 23, 1  ; Note 675: T 192.1598 G#3 = 208 Hz, tnext=432, dur=5263, soft 33 -> 23, sustain 501 -> 5263
    db 149, 1, 223, 18, 21, 1, 23, 1  ; Note 676: T 192.5915 C#4 = 277 Hz, tnext=405, dur=4831, soft 33 -> 23, sustain 489 -> 4831
    db 208, 1, 74, 17, 208, 0, 23, 1  ; Note 677: T 192.9968 G#3 = 208 Hz, tnext=464, dur=4426, soft 33 -> 23, sustain 1001 -> 4426
    db 150, 1, 122, 15, 21, 1, 23, 1  ; Note 678: T 193.4607 C#4 = 277 Hz, tnext=406, dur=3962, soft 33 -> 23, sustain 543 -> 3962
    db 137, 1, 228, 13, 74, 1, 23, 1  ; Note 679: T 193.8672 E4 = 330 Hz, tnext=393, dur=3556, soft 33 -> 23, sustain 545 -> 3556
    db 213, 1, 91, 12, 208, 0, 23, 1  ; Note 680: T 194.2599 G#3 = 208 Hz, tnext=469, dur=3163, soft 33 -> 23, sustain 787 -> 3163
    db 175, 1, 135, 10, 21, 1, 23, 1  ; Note 681: T 194.7284 C#4 = 277 Hz, tnext=431, dur=2695, soft 33 -> 23, sustain 711 -> 2695
    db 226, 1, 216, 8, 74, 1, 23, 1  ; Note 682: T 195.1590 E4 = 330 Hz, tnext=482, dur=2264, soft 33 -> 23, sustain 614 -> 2264
    db 33, 0, 246, 6, 208, 0, 26, 1  ; Note 683: T 195.6413 G#3 = 208 Hz, tnext=33, dur=1782, soft 38 -> 26, sustain 904 -> 1782
    db 232, 1, 212, 6, 159, 1, 33, 2  ; Note 684: T 195.6746 G#4 = 415 Hz, tnext=488, dur=1748, soft 48 -> 33, sustain 1141 -> 1748
    db 37, 2, 236, 4, 21, 1, 23, 1  ; Note 685: T 196.1626 C#4 = 277 Hz, tnext=549, dur=1260, soft 33 -> 23, sustain 691 -> 1260
    db 217, 1, 200, 2, 74, 1, 23, 1  ; Note 686: T 196.7113 E4 = 330 Hz, tnext=473, dur=712, soft 33 -> 23, sustain 200 -> 712
    db 2, 1, 239, 0, 159, 1, 30, 2  ; Note 687: T 197.1842 G#4 = 415 Hz, tnext=258, dur=239, soft 44 -> 30, sustain 157 -> 239
; T 197.4229 Sustain 0 (Instrument 1)
; T 197.4229 Sustain 0 (Instrument 2)
    db 6, 0, 201, 20, 65, 0, 27, 1  ; Note 688: T 197.4424 C2 = 65 Hz, tnext=6, dur=5321, soft 39 -> 27, sustain 4526 -> 5321
    db 0, 0, 40, 15, 208, 0, 27, 1  ; Note 689: T 197.4481 G#3 = 208 Hz, tnext=0, dur=3880, soft 39 -> 27, sustain 957 -> 3880
    db 14, 0, 196, 20, 104, 0, 27, 1  ; Note 690: T 197.4481 G#2 = 104 Hz, tnext=14, dur=5316, soft 39 -> 27, sustain 4456 -> 5316
    db 5, 0, 182, 20, 131, 0, 27, 1  ; Note 691: T 197.4619 C3 = 131 Hz, tnext=5, dur=5302, soft 39 -> 27, sustain 4437 -> 5302
    db 207, 1, 22, 15, 159, 1, 32, 2  ; Note 692: T 197.4665 G#4 = 415 Hz, tnext=463, dur=3862, soft 47 -> 32, sustain 3349 -> 3862
; T 197.8946 Sustain 127 (Instrument 1)
; T 197.8946 Sustain 127 (Instrument 2)
    db 157, 1, 71, 13, 55, 1, 23, 1  ; Note 693: T 197.9291 D#4 = 311 Hz, tnext=413, dur=3399, soft 33 -> 23, sustain 885 -> 3399
    db 165, 1, 170, 11, 114, 1, 23, 1  ; Note 694: T 198.3423 F#4 = 370 Hz, tnext=421, dur=2986, soft 33 -> 23, sustain 878 -> 2986
    db 124, 1, 5, 10, 208, 0, 25, 1  ; Note 695: T 198.7635 G#3 = 208 Hz, tnext=380, dur=2565, soft 36 -> 25, sustain 874 -> 2565
    db 178, 1, 137, 8, 55, 1, 23, 1  ; Note 696: T 199.1435 D#4 = 311 Hz, tnext=434, dur=2185, soft 33 -> 23, sustain 939 -> 2185
    db 125, 1, 215, 6, 114, 1, 23, 1  ; Note 697: T 199.5773 F#4 = 370 Hz, tnext=381, dur=1751, soft 33 -> 23, sustain 912 -> 1751
    db 172, 1, 90, 5, 208, 0, 24, 1  ; Note 698: T 199.9584 G#3 = 208 Hz, tnext=428, dur=1370, soft 35 -> 24, sustain 965 -> 1370
    db 168, 1, 175, 3, 55, 1, 23, 1  ; Note 699: T 200.3865 D#4 = 311 Hz, tnext=424, dur=943, soft 33 -> 23
    db 217, 1, 39, 2, 114, 1, 23, 1  ; Note 700: T 200.8110 F#4 = 370 Hz, tnext=473, dur=551, soft 33 -> 23
    db 1, 0, 200, 5, 159, 1, 33, 2  ; Note 701: T 201.2837 G#4 = 415 Hz, tnext=1, dur=1480, soft 48 -> 33, sustain 924 -> 1480
    db 255, 1, 199, 5, 208, 0, 25, 1  ; Note 702: T 201.2849 G#3 = 208 Hz, tnext=511, dur=1479, soft 36 -> 25, sustain 756 -> 1479
; T 201.3285 Sustain 0 (Instrument 1)
; T 201.3285 Sustain 0 (Instrument 2)
; T 201.6451 Sustain 127 (Instrument 1)
; T 201.6451 Sustain 127 (Instrument 2)
    db 147, 1, 200, 3, 55, 1, 23, 1  ; Note 703: T 201.7954 D#4 = 311 Hz, tnext=403, dur=968, soft 33 -> 23, sustain 454 -> 968
    db 42, 1, 54, 2, 114, 1, 23, 1  ; Note 704: T 202.1981 F#4 = 370 Hz, tnext=298, dur=566, soft 33 -> 23, sustain 396 -> 566
    db 192, 0, 11, 1, 159, 1, 30, 2  ; Note 705: T 202.4965 G#4 = 415 Hz, tnext=192, dur=267, soft 44 -> 30, sustain 180 -> 267
    db 39, 0, 140, 10, 69, 0, 27, 1  ; Note 706: T 202.6881 C#2 = 69 Hz, tnext=39, dur=2700, soft 39 -> 27, sustain 1025 -> 2700
    db 42, 0, 101, 10, 139, 0, 27, 1  ; Note 707: T 202.7271 C#3 = 139 Hz, tnext=42, dur=2661, soft 39 -> 27, sustain 699 -> 2661
; T 202.7638 Sustain 0 (Instrument 1)
; T 202.7638 Sustain 0 (Instrument 2)
    db 10, 0, 59, 10, 208, 0, 26, 1  ; Note 708: T 202.7695 G#3 = 208 Hz, tnext=10, dur=2619, soft 38 -> 26, sustain 956 -> 2619
    db 205, 1, 49, 10, 159, 1, 33, 2  ; Note 709: T 202.7799 G#4 = 415 Hz, tnext=461, dur=2609, soft 48 -> 33, sustain 1120 -> 2609
; T 203.1344 Sustain 127 (Instrument 1)
; T 203.1344 Sustain 127 (Instrument 2)
    db 151, 1, 99, 8, 21, 1, 23, 1  ; Note 710: T 203.2411 C#4 = 277 Hz, tnext=407, dur=2147, soft 33 -> 23, sustain 912 -> 2147
    db 140, 1, 204, 6, 74, 1, 23, 1  ; Note 711: T 203.6484 E4 = 330 Hz, tnext=396, dur=1740, soft 33 -> 23, sustain 498 -> 1740
    db 195, 1, 64, 5, 208, 0, 24, 1  ; Note 712: T 204.0442 G#3 = 208 Hz, tnext=451, dur=1344, soft 35 -> 24, sustain 964 -> 1344
    db 184, 1, 221, 3, 21, 1, 23, 1  ; Note 713: T 204.4951 C#4 = 277 Hz, tnext=440, dur=989, soft 33 -> 23
    db 82, 1, 10, 2, 74, 1, 23, 1  ; Note 714: T 204.9355 E4 = 330 Hz, tnext=338, dur=522, soft 33 -> 23
    db 13, 0, 33, 11, 46, 0, 28, 1  ; Note 715: T 205.2738 F#1 = 46 Hz, tnext=13, dur=2849, soft 40 -> 28, sustain 1128 -> 2849
    db 102, 0, 20, 11, 92, 0, 28, 1  ; Note 716: T 205.2864 F#2 = 92 Hz, tnext=102, dur=2836, soft 40 -> 28, sustain 1395 -> 2836
    db 18, 0, 174, 10, 220, 0, 26, 1  ; Note 717: T 205.3885 A3 = 220 Hz, tnext=18, dur=2734, soft 38 -> 26, sustain 1076 -> 2734
; T 205.3885 Sustain 0 (Instrument 1)
; T 205.3885 Sustain 0 (Instrument 2)
    db 246, 1, 156, 10, 184, 1, 36, 2  ; Note 718: T 205.4069 A4 = 440 Hz, tnext=502, dur=2716, soft 52 -> 36, sustain 1440 -> 2716
; T 205.8496 Sustain 127 (Instrument 1)
; T 205.8496 Sustain 127 (Instrument 2)
    db 189, 1, 166, 8, 21, 1, 23, 1  ; Note 719: T 205.9092 C#4 = 277 Hz, tnext=445, dur=2214, soft 33 -> 23, sustain 973 -> 2214
    db 244, 1, 233, 6, 114, 1, 23, 1  ; Note 720: T 206.3542 F#4 = 370 Hz, tnext=500, dur=1769, soft 33 -> 23, sustain 1066 -> 1769
    db 194, 1, 244, 4, 220, 0, 24, 1  ; Note 721: T 206.8543 A3 = 220 Hz, tnext=450, dur=1268, soft 35 -> 24, sustain 940 -> 1268
    db 134, 1, 51, 3, 21, 1, 23, 1  ; Note 722: T 207.3038 C#4 = 277 Hz, tnext=390, dur=819, soft 33 -> 23, sustain 758 -> 819
    db 70, 1, 80, 2, 114, 1, 23, 1  ; Note 723: T 207.6938 F#4 = 370 Hz, tnext=326, dur=592, soft 33 -> 23
    db 38, 0, 135, 11, 62, 0, 25, 1  ; Note 724: T 208.0195 B1 = 62 Hz, tnext=38, dur=2951, soft 36 -> 25, sustain 1335 -> 2951
    db 129, 0, 97, 11, 123, 0, 25, 1  ; Note 725: T 208.0573 B2 = 123 Hz, tnext=129, dur=2913, soft 36 -> 25, sustain 1214 -> 2913
; T 208.1227 Sustain 0 (Instrument 1)
; T 208.1227 Sustain 0 (Instrument 2)
    db 2, 0, 225, 10, 159, 1, 30, 2  ; Note 726: T 208.1858 G#4 = 415 Hz, tnext=2, dur=2785, soft 44 -> 30, sustain 1300 -> 2785
    db 237, 1, 222, 10, 208, 0, 25, 1  ; Note 727: T 208.1881 G#3 = 208 Hz, tnext=493, dur=2782, soft 36 -> 25, sustain 1023 -> 2782
; T 208.6422 Sustain 127 (Instrument 1)
; T 208.6422 Sustain 127 (Instrument 2)
    db 179, 1, 241, 8, 247, 0, 23, 1  ; Note 728: T 208.6812 B3 = 247 Hz, tnext=435, dur=2289, soft 33 -> 23, sustain 982 -> 2289
    db 223, 1, 63, 7, 74, 1, 23, 1  ; Note 729: T 209.1157 E4 = 330 Hz, tnext=479, dur=1855, soft 33 -> 23, sustain 1025 -> 1855
    db 151, 1, 96, 5, 208, 0, 24, 1  ; Note 730: T 209.5949 G#3 = 208 Hz, tnext=407, dur=1376, soft 35 -> 24, sustain 660 -> 1376
    db 178, 1, 201, 3, 247, 0, 23, 1  ; Note 731: T 210.0019 B3 = 247 Hz, tnext=434, dur=969, soft 33 -> 23, sustain 594 -> 969
    db 63, 1, 22, 2, 74, 1, 23, 1  ; Note 732: T 210.4364 E4 = 330 Hz, tnext=319, dur=534, soft 33 -> 23, sustain 193 -> 534
    db 107, 0, 239, 13, 62, 0, 25, 1  ; Note 733: T 210.7551 B1 = 62 Hz, tnext=107, dur=3567, soft 36 -> 25, sustain 780 -> 3567
    db 113, 0, 132, 13, 123, 0, 25, 1  ; Note 734: T 210.8617 B2 = 123 Hz, tnext=113, dur=3460, soft 36 -> 25, sustain 719 -> 3460
; T 210.9706 Sustain 0 (Instrument 1)
; T 210.9706 Sustain 0 (Instrument 2)
    db 2, 0, 19, 13, 114, 1, 25, 1  ; Note 735: T 210.9752 F#4 = 370 Hz, tnext=2, dur=3347, soft 37 -> 25, sustain 886 -> 3347
    db 236, 1, 17, 13, 220, 0, 25, 1  ; Note 736: T 210.9775 A3 = 220 Hz, tnext=492, dur=3345, soft 37 -> 25, sustain 407 -> 3345
; T 211.2137 Sustain 127 (Instrument 1)
; T 211.2137 Sustain 127 (Instrument 2)
    db 244, 1, 37, 11, 247, 0, 23, 1  ; Note 737: T 211.4693 B3 = 247 Hz, tnext=500, dur=2853, soft 33 -> 23, sustain 381 -> 2853
    db 233, 1, 49, 9, 55, 1, 23, 1  ; Note 738: T 211.9692 D#4 = 311 Hz, tnext=489, dur=2353, soft 33 -> 23, sustain 383 -> 2353
    db 31, 0, 71, 7, 220, 0, 25, 1  ; Note 739: T 212.4587 A3 = 220 Hz, tnext=31, dur=1863, soft 36 -> 25, sustain 815 -> 1863
    db 96, 2, 41, 7, 238, 1, 33, 2  ; Note 740: T 212.4896 B4 = 494 Hz, tnext=608, dur=1833, soft 48 -> 33, sustain 347 -> 1833
    db 118, 2, 201, 4, 247, 0, 23, 1  ; Note 741: T 213.0971 B3 = 247 Hz, tnext=630, dur=1225, soft 33 -> 23, sustain 352 -> 1225
    db 183, 1, 83, 2, 55, 1, 23, 1  ; Note 742: T 213.7273 D#4 = 311 Hz, tnext=439, dur=595, soft 33 -> 23, sustain 249 -> 595
    db 59, 0, 120, 21, 82, 0, 25, 1  ; Note 743: T 214.1662 E2 = 82 Hz, tnext=59, dur=5496, soft 36 -> 25, sustain 4821 -> 5496
    db 88, 0, 62, 21, 165, 0, 24, 1  ; Note 744: T 214.2247 E3 = 165 Hz, tnext=88, dur=5438, soft 35 -> 24, sustain 4741 -> 5438
    db 41, 0, 103, 15, 208, 0, 23, 1  ; Note 745: T 214.3129 G#3 = 208 Hz, tnext=41, dur=3943, soft 34 -> 23, sustain 594 -> 3943
; T 214.3221 Sustain 0 (Instrument 1)
; T 214.3221 Sustain 0 (Instrument 2)
    db 218, 1, 61, 15, 74, 1, 25, 1  ; Note 746: T 214.3542 E4 = 330 Hz, tnext=474, dur=3901, soft 37 -> 25, sustain 579 -> 3901
; T 214.6189 Sustain 127 (Instrument 1)
; T 214.6189 Sustain 127 (Instrument 2)
    db 115, 1, 99, 13, 247, 0, 23, 1  ; Note 747: T 214.8286 B3 = 247 Hz, tnext=371, dur=3427, soft 33 -> 23, sustain 461 -> 3427
    db 151, 1, 240, 11, 74, 1, 23, 1  ; Note 748: T 215.1999 E4 = 330 Hz, tnext=407, dur=3056, soft 33 -> 23, sustain 502 -> 3056
    db 144, 1, 89, 10, 247, 0, 23, 1  ; Note 749: T 215.6067 B3 = 247 Hz, tnext=400, dur=2649, soft 33 -> 23, sustain 771 -> 2649
    db 160, 1, 201, 8, 74, 1, 23, 1  ; Note 750: T 216.0067 E4 = 330 Hz, tnext=416, dur=2249, soft 33 -> 23, sustain 576 -> 2249
    db 199, 1, 41, 7, 159, 1, 26, 2  ; Note 751: T 216.4227 G#4 = 415 Hz, tnext=455, dur=1833, soft 38 -> 26, sustain 659 -> 1833
    db 177, 1, 98, 5, 247, 0, 23, 1  ; Note 752: T 216.8776 B3 = 247 Hz, tnext=433, dur=1378, soft 33 -> 23, sustain 576 -> 1378
    db 156, 1, 177, 3, 74, 1, 23, 1  ; Note 753: T 217.3106 E4 = 330 Hz, tnext=412, dur=945, soft 33 -> 23, sustain 926 -> 945
    db 227, 1, 48, 2, 159, 1, 26, 2  ; Note 754: T 217.7230 G#4 = 415 Hz, tnext=483, dur=560, soft 38 -> 26
    db 13, 0, 176, 5, 247, 0, 26, 1  ; Note 755: T 218.2064 B3 = 247 Hz, tnext=13, dur=1456, soft 38 -> 26, sustain 910 -> 1456
    db 225, 1, 163, 5, 238, 1, 35, 2  ; Note 756: T 218.2190 B4 = 494 Hz, tnext=481, dur=1443, soft 51 -> 35, sustain 955 -> 1443
; T 218.2556 Sustain 0 (Instrument 1)
; T 218.2556 Sustain 0 (Instrument 2)
; T 218.6394 Sustain 127 (Instrument 1)
; T 218.6394 Sustain 127 (Instrument 2)
    db 155, 1, 194, 3, 74, 1, 23, 1  ; Note 757: T 218.7001 E4 = 330 Hz, tnext=411, dur=962, soft 33 -> 23, sustain 482 -> 962
; T 218.7837 Soft 127 (Instrument 1)
; T 218.7837 Soft 127 (Instrument 2)
    db 22, 1, 39, 2, 159, 1, 28, 2  ; Note 758: T 219.1113 G#4 = 415 Hz, tnext=278, dur=551, soft 40 -> 28, sustain 315 -> 551
    db 151, 0, 17, 1, 238, 1, 30, 2  ; Note 759: T 219.3897 B4 = 494 Hz, tnext=151, dur=273, soft 43 -> 30, sustain 179 -> 273
    db 32, 0, 141, 19, 78, 0, 28, 1  ; Note 760: T 219.5409 D#2 = 78 Hz, tnext=32, dur=5005, soft 40 -> 28, sustain 4394 -> 5005
    db 59, 0, 108, 19, 156, 0, 28, 1  ; Note 761: T 219.5730 D#3 = 156 Hz, tnext=59, dur=4972, soft 40 -> 28, sustain 4301 -> 4972
    db 9, 0, 42, 14, 238, 1, 37, 2  ; Note 762: T 219.6325 B4 = 494 Hz, tnext=9, dur=3626, soft 53 -> 37, sustain 3201 -> 3626
    db 124, 1, 33, 14, 247, 0, 27, 1  ; Note 763: T 219.6417 B3 = 247 Hz, tnext=380, dur=3617, soft 39 -> 27, sustain 951 -> 3617
; T 219.6623 Sustain 0 (Instrument 1)
; T 219.6623 Sustain 0 (Instrument 2)
    db 147, 1, 164, 12, 114, 1, 23, 1  ; Note 764: T 220.0220 F#4 = 370 Hz, tnext=403, dur=3236, soft 34 -> 23, sustain 630 -> 3236
; T 220.0896 Sustain 127 (Instrument 1)
; T 220.0896 Sustain 127 (Instrument 2)
    db 124, 1, 17, 11, 184, 1, 26, 2  ; Note 765: T 220.4252 A4 = 440 Hz, tnext=380, dur=2833, soft 38 -> 26, sustain 623 -> 2833
    db 157, 1, 149, 9, 247, 0, 23, 1  ; Note 766: T 220.8056 B3 = 247 Hz, tnext=413, dur=2453, soft 33 -> 23, sustain 1037 -> 2453
    db 108, 1, 247, 7, 114, 1, 23, 1  ; Note 767: T 221.2189 F#4 = 370 Hz, tnext=364, dur=2039, soft 33 -> 23, sustain 823 -> 2039
    db 168, 1, 139, 6, 184, 1, 26, 2  ; Note 768: T 221.5831 A4 = 440 Hz, tnext=424, dur=1675, soft 38 -> 26, sustain 874 -> 1675
    db 137, 1, 228, 4, 247, 0, 23, 1  ; Note 769: T 222.0067 B3 = 247 Hz, tnext=393, dur=1252, soft 33 -> 23, sustain 916 -> 1252
    db 108, 1, 91, 3, 114, 1, 23, 1  ; Note 770: T 222.3995 F#4 = 370 Hz, tnext=364, dur=859, soft 33 -> 23, sustain 617 -> 859
    db 181, 1, 4, 2, 184, 1, 26, 2  ; Note 771: T 222.7636 A4 = 440 Hz, tnext=437, dur=516, soft 38 -> 26
    db 15, 0, 64, 5, 238, 1, 34, 2  ; Note 772: T 223.2010 B4 = 494 Hz, tnext=15, dur=1344, soft 49 -> 34, sustain 839 -> 1344
    db 196, 1, 49, 5, 247, 0, 25, 1  ; Note 773: T 223.2159 B3 = 247 Hz, tnext=452, dur=1329, soft 36 -> 25, sustain 726 -> 1329
; T 223.2583 Sustain 0 (Instrument 1)
; T 223.2583 Sustain 0 (Instrument 2)
; T 223.5892 Sustain 127 (Instrument 1)
; T 223.5892 Sustain 127 (Instrument 2)
    db 128, 1, 109, 3, 114, 1, 23, 1  ; Note 774: T 223.6682 F#4 = 370 Hz, tnext=384, dur=877, soft 33 -> 23, sustain 406 -> 877
    db 235, 0, 238, 1, 184, 1, 26, 2  ; Note 775: T 224.0518 A4 = 440 Hz, tnext=235, dur=494, soft 38 -> 26, sustain 285 -> 494
    db 128, 0, 3, 1, 238, 1, 28, 2  ; Note 776: T 224.2866 B4 = 494 Hz, tnext=128, dur=259, soft 41 -> 28, sustain 117 -> 259
    db 40, 0, 5, 10, 82, 0, 25, 1  ; Note 777: T 224.4148 E2 = 82 Hz, tnext=40, dur=2565, soft 37 -> 25, sustain 1549 -> 2565
    db 80, 0, 221, 9, 165, 0, 25, 1  ; Note 778: T 224.4549 E3 = 165 Hz, tnext=80, dur=2525, soft 36 -> 25, sustain 1769 -> 2525
    db 1, 0, 141, 9, 238, 1, 39, 2  ; Note 779: T 224.5350 B4 = 494 Hz, tnext=1, dur=2445, soft 57 -> 39, sustain 2002 -> 2445
    db 157, 1, 140, 9, 247, 0, 24, 1  ; Note 780: T 224.5362 B3 = 247 Hz, tnext=413, dur=2444, soft 35 -> 24, sustain 992 -> 2444
; T 224.5454 Sustain 0 (Instrument 1)
; T 224.5454 Sustain 0 (Instrument 2)
    db 145, 1, 238, 7, 74, 1, 23, 1  ; Note 781: T 224.9496 E4 = 330 Hz, tnext=401, dur=2030, soft 33 -> 23, sustain 579 -> 2030
; T 224.9770 Sustain 127 (Instrument 1)
; T 224.9770 Sustain 127 (Instrument 2)
    db 157, 1, 94, 6, 159, 1, 26, 2  ; Note 782: T 225.3502 G#4 = 415 Hz, tnext=413, dur=1630, soft 38 -> 26, sustain 878 -> 1630
    db 121, 1, 193, 4, 247, 0, 23, 1  ; Note 783: T 225.7634 B3 = 247 Hz, tnext=377, dur=1217, soft 33 -> 23, sustain 514 -> 1217
    db 133, 1, 72, 3, 74, 1, 23, 1  ; Note 784: T 226.1400 E4 = 330 Hz, tnext=389, dur=840, soft 33 -> 23, sustain 728 -> 840
; T 226.3815 Soft 0 (Instrument 1)
; T 226.3815 Soft 0 (Instrument 2)
    db 27, 1, 217, 1, 159, 1, 40, 2  ; Note 785: T 226.5291 G#4 = 415 Hz, tnext=283, dur=473
    db 13, 0, 102, 5, 78, 0, 39, 1  ; Note 786: T 226.8118 D#2 = 78 Hz, tnext=13, dur=1382, sustain 1288 -> 1382
    db 123, 0, 89, 5, 156, 0, 39, 1  ; Note 787: T 226.8244 D#3 = 156 Hz, tnext=123, dur=1369, sustain 884 -> 1369
    db 11, 0, 222, 4, 6, 1, 40, 1  ; Note 788: T 226.9469 C4 = 262 Hz, tnext=11, dur=1246, sustain 877 -> 1246
    db 176, 1, 211, 4, 11, 2, 58, 2  ; Note 789: T 226.9583 C5 = 523 Hz, tnext=432, dur=1235, sustain 837 -> 1235
; T 226.9801 Sustain 0 (Instrument 1)
; T 226.9801 Sustain 0 (Instrument 2)
; T 227.3303 Sustain 127 (Instrument 1)
; T 227.3303 Sustain 127 (Instrument 2)
    db 119, 1, 35, 3, 114, 1, 40, 1  ; Note 790: T 227.3899 F#4 = 370 Hz, tnext=375, dur=803, sustain 473 -> 803
    db 235, 0, 213, 1, 159, 1, 41, 2  ; Note 791: T 227.7653 G#4 = 415 Hz, tnext=235, dur=469
    db 30, 0, 109, 6, 69, 0, 46, 1  ; Note 792: T 227.9999 C#2 = 69 Hz, tnext=30, dur=1645, sustain 958 -> 1645
    db 135, 0, 79, 6, 139, 0, 46, 1  ; Note 793: T 228.0297 C#3 = 139 Hz, tnext=135, dur=1615, sustain 920 -> 1615
    db 8, 0, 200, 5, 42, 2, 60, 2  ; Note 794: T 228.1648 C#5 = 554 Hz, tnext=8, dur=1480, sustain 965 -> 1480
    db 214, 1, 192, 5, 21, 1, 44, 1  ; Note 795: T 228.1728 C#4 = 277 Hz, tnext=470, dur=1472, sustain 804 -> 1472
; T 228.1934 Sustain 0 (Instrument 1)
; T 228.1934 Sustain 0 (Instrument 2)
    db 175, 1, 233, 3, 74, 1, 38, 1  ; Note 796: T 228.6432 E4 = 330 Hz, tnext=431, dur=1001, sustain 502 -> 1001
; T 228.6844 Sustain 127 (Instrument 1)
; T 228.6844 Sustain 127 (Instrument 2)
; T 229.0518 Soft 127 (Instrument 1)
; T 229.0518 Soft 127 (Instrument 2)
    db 220, 1, 58, 2, 159, 1, 26, 2  ; Note 797: T 229.0747 G#4 = 415 Hz, tnext=476, dur=570, soft 38 -> 26, sustain 173 -> 570
    db 86, 0, 99, 11, 65, 0, 25, 1  ; Note 798: T 229.5507 C2 = 65 Hz, tnext=86, dur=2915, soft 36 -> 25, sustain 1888 -> 2915
    db 0, 0, 13, 11, 104, 0, 25, 1  ; Note 799: T 229.6365 G#2 = 104 Hz, tnext=0, dur=2829, soft 36 -> 25, sustain 771 -> 2829
    db 94, 0, 13, 11, 131, 0, 25, 1  ; Note 800: T 229.6365 C3 = 131 Hz, tnext=94, dur=2829, soft 36 -> 25, sustain 1773 -> 2829
; T 229.6445 Sustain 0 (Instrument 1)
; T 229.6445 Sustain 0 (Instrument 2)
    db 2, 0, 176, 10, 110, 2, 32, 2  ; Note 801: T 229.7303 D#5 = 622 Hz, tnext=2, dur=2736, soft 47 -> 32, sustain 1358 -> 2736
    db 201, 1, 173, 10, 55, 1, 24, 1  ; Note 802: T 229.7326 D#4 = 311 Hz, tnext=457, dur=2733, soft 35 -> 24, sustain 960 -> 2733
; T 230.0427 Sustain 127 (Instrument 1)
; T 230.0427 Sustain 127 (Instrument 2)
    db 134, 1, 229, 8, 114, 1, 23, 1  ; Note 803: T 230.1891 F#4 = 370 Hz, tnext=390, dur=2277, soft 33 -> 23, sustain 900 -> 2277
    db 179, 1, 95, 7, 159, 1, 26, 2  ; Note 804: T 230.5793 G#4 = 415 Hz, tnext=435, dur=1887, soft 38 -> 26, sustain 565 -> 1887
    db 170, 1, 172, 5, 55, 1, 23, 1  ; Note 805: T 231.0141 D#4 = 311 Hz, tnext=426, dur=1452, soft 33 -> 23, sustain 744 -> 1452
; T 231.3081 Soft 127 (Instrument 1)
; T 231.3081 Soft 127 (Instrument 2)
    db 144, 1, 2, 4, 114, 1, 23, 1  ; Note 806: T 231.4397 F#4 = 370 Hz, tnext=400, dur=1026, soft 33 -> 23, sustain 605 -> 1026
    db 130, 1, 114, 2, 159, 1, 27, 2  ; Note 807: T 231.8401 G#4 = 415 Hz, tnext=386, dur=626, soft 39 -> 27, sustain 231 -> 626
    db 72, 0, 0, 11, 69, 0, 27, 1  ; Note 808: T 232.2257 C#2 = 69 Hz, tnext=72, dur=2816, soft 39 -> 27, sustain 1225 -> 2816
    db 148, 0, 184, 10, 139, 0, 26, 1  ; Note 809: T 232.2978 C#3 = 139 Hz, tnext=148, dur=2744, soft 38 -> 26, sustain 1493 -> 2744
    db 24, 0, 36, 10, 74, 1, 25, 1  ; Note 810: T 232.4454 E4 = 330 Hz, tnext=24, dur=2596, soft 36 -> 25, sustain 1071 -> 2596
; T 232.4660 Sustain 0 (Instrument 1)
; T 232.4660 Sustain 0 (Instrument 2)
    db 175, 1, 12, 10, 147, 2, 39, 2  ; Note 811: T 232.4694 E5 = 659 Hz, tnext=431, dur=2572, soft 56 -> 39, sustain 756 -> 2572
; T 232.7280 Sustain 127 (Instrument 1)
; T 232.7280 Sustain 127 (Instrument 2)
    db 227, 1, 93, 8, 159, 1, 26, 2  ; Note 812: T 232.9008 G#4 = 415 Hz, tnext=483, dur=2141, soft 38 -> 26, sustain 962 -> 2141
    db 135, 1, 122, 6, 42, 2, 26, 2  ; Note 813: T 233.3835 C#5 = 554 Hz, tnext=391, dur=1658, soft 38 -> 26, sustain 921 -> 1658
    db 131, 1, 243, 4, 74, 1, 23, 1  ; Note 814: T 233.7747 E4 = 330 Hz, tnext=387, dur=1267, soft 33 -> 23, sustain 947 -> 1267
    db 225, 1, 34, 4, 159, 1, 26, 2  ; Note 815: T 234.1612 G#4 = 415 Hz, tnext=481, dur=1058, soft 38 -> 26
    db 245, 0, 43, 2, 42, 2, 26, 2  ; Note 816: T 234.6427 C#5 = 554 Hz, tnext=245, dur=555, soft 38 -> 26
    db 66, 0, 189, 11, 46, 0, 28, 1  ; Note 817: T 234.8875 F#1 = 46 Hz, tnext=66, dur=3005, soft 41 -> 28, sustain 1109 -> 3005
    db 161, 0, 123, 11, 92, 0, 28, 1  ; Note 818: T 234.9538 F#2 = 92 Hz, tnext=161, dur=2939, soft 40 -> 28, sustain 1089 -> 2939
; T 235.0419 Sustain 0 (Instrument 1)
; T 235.0419 Sustain 0 (Instrument 2)
    db 8, 0, 218, 10, 75, 2, 38, 2  ; Note 819: T 235.1151 D5 = 587 Hz, tnext=8, dur=2778, soft 55 -> 38, sustain 1045 -> 2778
    db 236, 1, 210, 10, 38, 1, 26, 1  ; Note 820: T 235.1231 D4 = 294 Hz, tnext=492, dur=2770, soft 38 -> 26, sustain 1066 -> 2770
; T 235.5211 Sustain 127 (Instrument 1)
; T 235.5211 Sustain 127 (Instrument 2)
    db 233, 1, 230, 8, 114, 1, 23, 1  ; Note 821: T 235.6149 F#4 = 370 Hz, tnext=489, dur=2278, soft 33 -> 23, sustain 1129 -> 2278
    db 200, 1, 253, 6, 184, 1, 26, 2  ; Note 822: T 236.1043 A4 = 440 Hz, tnext=456, dur=1789, soft 38 -> 26, sustain 572 -> 1789
    db 173, 1, 52, 5, 38, 1, 23, 1  ; Note 823: T 236.5607 D4 = 294 Hz, tnext=429, dur=1332, soft 33 -> 23, sustain 940 -> 1332
    db 209, 1, 135, 3, 114, 1, 23, 1  ; Note 824: T 236.9896 F#4 = 370 Hz, tnext=465, dur=903, soft 33 -> 23, sustain 603 -> 903
    db 77, 1, 37, 2, 184, 1, 26, 2  ; Note 825: T 237.4550 A4 = 440 Hz, tnext=333, dur=549, soft 38 -> 26
    db 67, 0, 139, 11, 52, 0, 24, 1  ; Note 826: T 237.7877 G#1 = 52 Hz, tnext=67, dur=2955, soft 35 -> 24, sustain 868 -> 2955
    db 106, 0, 72, 11, 104, 0, 24, 1  ; Note 827: T 237.8551 G#2 = 104 Hz, tnext=106, dur=2888, soft 35 -> 24, sustain 1000 -> 2888
; T 237.8929 Sustain 0 (Instrument 1)
; T 237.8929 Sustain 0 (Instrument 2)
    db 5, 0, 221, 10, 6, 1, 23, 1  ; Note 828: T 237.9614 C4 = 262 Hz, tnext=5, dur=2781, soft 34 -> 23, sustain 1047 -> 2781
    db 248, 1, 217, 10, 11, 2, 36, 2  ; Note 829: T 237.9660 C5 = 523 Hz, tnext=504, dur=2777, soft 52 -> 36, sustain 1163 -> 2777
; T 238.3238 Sustain 127 (Instrument 1)
; T 238.3238 Sustain 127 (Instrument 2)
    db 173, 1, 225, 8, 114, 1, 23, 1  ; Note 830: T 238.4702 F#4 = 370 Hz, tnext=429, dur=2273, soft 33 -> 23, sustain 991 -> 2273
    db 165, 1, 52, 7, 159, 1, 26, 2  ; Note 831: T 238.8989 G#4 = 415 Hz, tnext=421, dur=1844, soft 38 -> 26, sustain 1098 -> 1844
    db 205, 1, 143, 5, 6, 1, 23, 1  ; Note 832: T 239.3196 C4 = 262 Hz, tnext=461, dur=1423, soft 33 -> 23, sustain 955 -> 1423
    db 160, 1, 195, 3, 114, 1, 23, 1  ; Note 833: T 239.7803 F#4 = 370 Hz, tnext=416, dur=963, soft 33 -> 23, sustain 566 -> 963
    db 108, 1, 34, 2, 159, 1, 26, 2  ; Note 834: T 240.1965 G#4 = 415 Hz, tnext=364, dur=546, soft 38 -> 26, sustain 264 -> 546
    db 55, 0, 155, 28, 69, 0, 25, 1  ; Note 835: T 240.5600 C#2 = 69 Hz, tnext=55, dur=7323, soft 36 -> 25, sustain 5754 -> 7323
    db 119, 0, 101, 28, 139, 0, 24, 1  ; Note 836: T 240.6149 C#3 = 139 Hz, tnext=119, dur=7269, soft 35 -> 24, sustain 5712 -> 7269
    db 15, 0, 119, 14, 42, 2, 30, 2  ; Note 837: T 240.7338 C#5 = 554 Hz, tnext=15, dur=3703, soft 43 -> 30, sustain 2785 -> 3703
; T 240.7429 Sustain 0 (Instrument 1)
; T 240.7429 Sustain 0 (Instrument 2)
    db 159, 1, 231, 9, 21, 1, 23, 1  ; Note 838: T 240.7486 C#4 = 277 Hz, tnext=415, dur=2535, soft 34 -> 23, sustain 951 -> 2535
; T 241.0299 Sustain 127 (Instrument 1)
; T 241.0299 Sustain 127 (Instrument 2)
    db 161, 1, 72, 8, 74, 1, 23, 1  ; Note 839: T 241.1636 E4 = 330 Hz, tnext=417, dur=2120, soft 33 -> 23, sustain 974 -> 2120
    db 132, 1, 167, 6, 159, 1, 26, 2  ; Note 840: T 241.5809 G#4 = 415 Hz, tnext=388, dur=1703, soft 38 -> 26, sustain 516 -> 1703
; T 241.8768 Soft 0 (Instrument 1)
; T 241.8768 Soft 0 (Instrument 2)
    db 153, 1, 34, 5, 21, 1, 38, 1  ; Note 841: T 241.9694 C#4 = 277 Hz, tnext=409, dur=1314, sustain 1070 -> 1314
    db 167, 1, 137, 3, 74, 1, 38, 1  ; Note 842: T 242.3785 E4 = 330 Hz, tnext=423, dur=905, sustain 527 -> 905
    db 131, 1, 226, 1, 159, 1, 42, 2  ; Note 843: T 242.8013 G#4 = 415 Hz, tnext=387, dur=482, sustain 471 -> 482
    db 141, 1, 224, 4, 21, 1, 37, 1  ; Note 844: T 243.1887 C#4 = 277 Hz, tnext=397, dur=1248, sustain 854 -> 1248
; T 243.2836 Sustain 0 (Instrument 1)
; T 243.2836 Sustain 0 (Instrument 2)
; T 243.4847 Sustain 127 (Instrument 1)
; T 243.4847 Sustain 127 (Instrument 2)
    db 151, 1, 83, 3, 93, 1, 33, 1  ; Note 845: T 243.5853 F4 = 349 Hz, tnext=407, dur=851, sustain 814 -> 851
    db 109, 1, 189, 1, 159, 1, 43, 2  ; Note 846: T 243.9921 G#4 = 415 Hz, tnext=365, dur=445, sustain 441 -> 445
    db 5, 0, 56, 5, 21, 1, 43, 1  ; Note 847: T 244.3567 C#4 = 277 Hz, tnext=5, dur=1336, sustain 769 -> 1336
    db 190, 1, 51, 5, 42, 2, 59, 2  ; Note 848: T 244.3612 C#5 = 554 Hz, tnext=446, dur=1331, sustain 802 -> 1331
; T 244.4366 Sustain 0 (Instrument 1)
; T 244.4366 Sustain 0 (Instrument 2)
; T 244.6583 Sustain 127 (Instrument 1)
; T 244.6583 Sustain 127 (Instrument 2)
    db 111, 1, 118, 3, 93, 1, 41, 1  ; Note 849: T 244.8069 F4 = 349 Hz, tnext=367, dur=886, sustain 443 -> 886
    db 159, 1, 7, 2, 159, 1, 38, 2  ; Note 850: T 245.1737 G#4 = 415 Hz, tnext=415, dur=519, sustain 130 -> 519
    db 17, 0, 158, 13, 75, 2, 59, 2  ; Note 851: T 245.5886 D5 = 587 Hz, tnext=17, dur=3486, sustain 2712 -> 3486
    db 197, 1, 230, 8, 21, 1, 46, 1  ; Note 852: T 245.6057 C#4 = 277 Hz, tnext=453, dur=2278, sustain 1155 -> 2278
; T 245.6925 Sustain 0 (Instrument 1)
; T 245.6925 Sustain 0 (Instrument 2)
; T 246.0021 Sustain 127 (Instrument 1)
; T 246.0021 Sustain 127 (Instrument 2)
    db 168, 1, 32, 7, 114, 1, 41, 1  ; Note 853: T 246.0592 F#4 = 370 Hz, tnext=424, dur=1824, sustain 653 -> 1824
    db 249, 0, 120, 5, 184, 1, 38, 2  ; Note 854: T 246.4830 A4 = 440 Hz, tnext=249, dur=1400, sustain 404 -> 1400
    db 34, 0, 127, 4, 92, 0, 42, 1  ; Note 855: T 246.7320 F#2 = 92 Hz, tnext=34, dur=1151, sustain 750 -> 1151
    db 73, 0, 93, 4, 185, 0, 45, 1  ; Note 856: T 246.7663 F#3 = 185 Hz, tnext=73, dur=1117, sustain 668 -> 1117
    db 74, 1, 20, 4, 21, 1, 44, 1  ; Note 857: T 246.8394 C#4 = 277 Hz, tnext=330, dur=1044, sustain 1032 -> 1044
    db 149, 1, 53, 3, 114, 1, 39, 1  ; Note 858: T 247.1695 F#4 = 370 Hz, tnext=405, dur=821
    db 246, 0, 220, 5, 184, 1, 38, 2  ; Note 859: T 247.5750 A4 = 440 Hz, tnext=246, dur=1500, sustain 678 -> 1500
    db 0, 0, 230, 4, 220, 0, 44, 1  ; Note 860: T 247.8206 A3 = 220 Hz, tnext=0, dur=1254, sustain 542 -> 1254
    db 88, 0, 230, 4, 110, 0, 44, 1  ; Note 861: T 247.8206 A2 = 110 Hz, tnext=88, dur=1254, sustain 637 -> 1254
; T 247.8366 Soft 127 (Instrument 1)
; T 247.8366 Soft 127 (Instrument 2)
; T 247.8835 Sustain 0 (Instrument 1)
; T 247.8835 Sustain 0 (Instrument 2)
    db 148, 1, 142, 4, 21, 1, 23, 1  ; Note 862: T 247.9086 C#4 = 277 Hz, tnext=404, dur=1166, soft 33 -> 23, sustain 817 -> 1166
; T 248.0914 Sustain 127 (Instrument 1)
; T 248.0914 Sustain 127 (Instrument 2)
    db 119, 1, 82, 3, 114, 1, 23, 1  ; Note 863: T 248.3130 F#4 = 370 Hz, tnext=375, dur=850, soft 33 -> 23
    db 44, 1, 220, 1, 184, 1, 27, 2  ; Note 864: T 248.6877 A4 = 440 Hz, tnext=300, dur=476, soft 39 -> 27
    db 0, 0, 252, 4, 185, 0, 28, 1  ; Note 865: T 248.9881 F#3 = 185 Hz, tnext=0, dur=1276, soft 40 -> 28, sustain 560 -> 1276
    db 77, 0, 252, 4, 92, 0, 28, 1  ; Note 866: T 248.9881 F#2 = 92 Hz, tnext=77, dur=1276, soft 40 -> 28, sustain 634 -> 1276
    db 30, 0, 175, 4, 11, 2, 34, 2  ; Note 867: T 249.0646 C5 = 523 Hz, tnext=30, dur=1199, soft 49 -> 34, sustain 893 -> 1199
; T 249.0749 Sustain 0 (Instrument 1)
; T 249.0749 Sustain 0 (Instrument 2)
    db 173, 1, 145, 4, 21, 1, 23, 1  ; Note 868: T 249.0943 C#4 = 277 Hz, tnext=429, dur=1169, soft 33 -> 23, sustain 824 -> 1169
; T 249.3856 Sustain 127 (Instrument 1)
; T 249.3856 Sustain 127 (Instrument 2)
    db 114, 1, 228, 2, 114, 1, 23, 1  ; Note 869: T 249.5238 F#4 = 370 Hz, tnext=370, dur=740, soft 33 -> 23, sustain 427 -> 740
    db 15, 1, 206, 1, 184, 1, 26, 2  ; Note 870: T 249.8939 A4 = 440 Hz, tnext=271, dur=462, soft 38 -> 26
    db 14, 0, 214, 26, 139, 0, 25, 1  ; Note 871: T 250.1645 C#3 = 139 Hz, tnext=14, dur=6870, soft 37 -> 25, sustain 5310 -> 6870
    db 115, 0, 201, 26, 69, 0, 25, 1  ; Note 872: T 250.1782 C#2 = 69 Hz, tnext=115, dur=6857, soft 37 -> 25, sustain 5317 -> 6857
; T 250.2638 Sustain 0 (Instrument 1)
; T 250.2638 Sustain 0 (Instrument 2)
    db 19, 0, 149, 13, 21, 1, 25, 1  ; Note 873: T 250.2935 C#4 = 277 Hz, tnext=19, dur=3477, soft 36 -> 25, sustain 832 -> 3477
    db 136, 1, 130, 13, 42, 2, 30, 2  ; Note 874: T 250.3129 C#5 = 554 Hz, tnext=392, dur=3458, soft 44 -> 30, sustain 1342 -> 3458
; T 250.6463 Sustain 127 (Instrument 1)
; T 250.6463 Sustain 127 (Instrument 2)
    db 87, 1, 250, 11, 93, 1, 23, 1  ; Note 875: T 250.7046 F4 = 349 Hz, tnext=343, dur=3066, soft 33 -> 23, sustain 823 -> 3066
    db 143, 1, 163, 10, 159, 1, 26, 2  ; Note 876: T 251.0471 G#4 = 415 Hz, tnext=399, dur=2723, soft 38 -> 26, sustain 481 -> 2723
; T 251.4068 Soft 0 (Instrument 1)
; T 251.4068 Soft 0 (Instrument 2)
    db 100, 1, 21, 9, 21, 1, 33, 1  ; Note 877: T 251.4456 C#4 = 277 Hz, tnext=356, dur=2325, sustain 770 -> 2325
    db 115, 1, 177, 7, 93, 1, 33, 1  ; Note 878: T 251.8019 F4 = 349 Hz, tnext=371, dur=1969, sustain 824 -> 1969
    db 103, 1, 61, 6, 159, 1, 41, 2  ; Note 879: T 252.1730 G#4 = 415 Hz, tnext=359, dur=1597, sustain 435 -> 1597
    db 141, 1, 215, 4, 21, 1, 40, 1  ; Note 880: T 252.5316 C#4 = 277 Hz, tnext=397, dur=1239, sustain 830 -> 1239
    db 112, 1, 74, 3, 93, 1, 37, 1  ; Note 881: T 252.9289 F4 = 349 Hz, tnext=368, dur=842, sustain 600 -> 842
    db 155, 1, 218, 1, 159, 1, 40, 2  ; Note 882: T 253.2966 G#4 = 415 Hz, tnext=411, dur=474, sustain 434 -> 474
    db 7, 0, 193, 4, 42, 2, 58, 2  ; Note 883: T 253.7077 C#5 = 554 Hz, tnext=7, dur=1217, sustain 634 -> 1217
    db 120, 1, 186, 4, 21, 1, 42, 1  ; Note 884: T 253.7145 C#4 = 277 Hz, tnext=376, dur=1210, sustain 520 -> 1210
; T 253.7705 Sustain 0 (Instrument 1)
; T 253.7705 Sustain 0 (Instrument 2)
; T 254.0193 Sustain 127 (Instrument 1)
; T 254.0193 Sustain 127 (Instrument 2)
    db 142, 1, 66, 3, 93, 1, 37, 1  ; Note 885: T 254.0901 F4 = 349 Hz, tnext=398, dur=834, sustain 447 -> 834
    db 121, 1, 180, 1, 159, 1, 39, 2  ; Note 886: T 254.4884 G#4 = 415 Hz, tnext=377, dur=436, sustain 96 -> 436
    db 14, 0, 18, 13, 75, 2, 57, 2  ; Note 887: T 254.8651 D5 = 587 Hz, tnext=14, dur=3346, sustain 2443 -> 3346
    db 147, 1, 108, 8, 21, 1, 41, 1  ; Note 888: T 254.8788 C#4 = 277 Hz, tnext=403, dur=2156, sustain 1071 -> 2156
; T 254.9244 Sustain 0 (Instrument 1)
; T 254.9244 Sustain 0 (Instrument 2)
; T 255.2669 Sustain 127 (Instrument 1)
; T 255.2669 Sustain 127 (Instrument 2)
    db 157, 1, 217, 6, 114, 1, 36, 1  ; Note 889: T 255.2817 F#4 = 370 Hz, tnext=413, dur=1753, sustain 531 -> 1753
    db 213, 0, 60, 5, 184, 1, 38, 2  ; Note 890: T 255.6949 A4 = 440 Hz, tnext=213, dur=1340, sustain 388 -> 1340
    db 21, 0, 103, 4, 92, 0, 44, 1  ; Note 891: T 255.9083 F#2 = 92 Hz, tnext=21, dur=1127, sustain 735 -> 1127
    db 94, 0, 82, 4, 185, 0, 46, 1  ; Note 892: T 255.9289 F#3 = 185 Hz, tnext=94, dur=1106, sustain 640 -> 1106
    db 92, 1, 249, 3, 21, 1, 44, 1  ; Note 893: T 256.0225 C#4 = 277 Hz, tnext=348, dur=1017
    db 98, 1, 88, 3, 114, 1, 40, 1  ; Note 894: T 256.3706 F#4 = 370 Hz, tnext=354, dur=856
    db 10, 1, 207, 5, 184, 1, 38, 2  ; Note 895: T 256.7244 A4 = 440 Hz, tnext=266, dur=1487, sustain 718 -> 1487
    db 8, 0, 197, 4, 220, 0, 46, 1  ; Note 896: T 256.9904 A3 = 220 Hz, tnext=8, dur=1221, sustain 493 -> 1221
    db 99, 0, 189, 4, 110, 0, 46, 1  ; Note 897: T 256.9984 A2 = 110 Hz, tnext=99, dur=1213, sustain 582 -> 1213
; T 257.0349 Sustain 0 (Instrument 1)
; T 257.0349 Sustain 0 (Instrument 2)
    db 74, 1, 90, 4, 21, 1, 33, 1  ; Note 898: T 257.0977 C#4 = 277 Hz, tnext=330, dur=1114, sustain 754 -> 1114
; T 257.2769 Sustain 127 (Instrument 1)
; T 257.2769 Sustain 127 (Instrument 2)
    db 110, 1, 38, 3, 114, 1, 33, 1  ; Note 899: T 257.4275 F#4 = 370 Hz, tnext=366, dur=806
    db 2, 1, 176, 1, 184, 1, 38, 2  ; Note 900: T 257.7939 A4 = 440 Hz, tnext=258, dur=432
    db 26, 0, 252, 4, 185, 0, 47, 1  ; Note 901: T 258.0518 F#3 = 185 Hz, tnext=26, dur=1276, sustain 677 -> 1276
    db 91, 0, 225, 4, 92, 0, 46, 1  ; Note 902: T 258.0781 F#2 = 92 Hz, tnext=91, dur=1249, sustain 823 -> 1249
    db 2, 0, 134, 4, 11, 2, 51, 2  ; Note 903: T 258.1693 C5 = 523 Hz, tnext=2, dur=1158, sustain 838 -> 1158
    db 183, 1, 132, 4, 21, 1, 33, 1  ; Note 904: T 258.1716 C#4 = 277 Hz, tnext=439, dur=1156, sustain 809 -> 1156
; T 258.2116 Sustain 0 (Instrument 1)
; T 258.2116 Sustain 0 (Instrument 2)
; T 258.5253 Sustain 127 (Instrument 1)
; T 258.5253 Sustain 127 (Instrument 2)
; T 258.5881 Soft 127 (Instrument 1)
; T 258.5881 Soft 127 (Instrument 2)
    db 98, 1, 204, 2, 114, 1, 23, 1  ; Note 905: T 258.6109 F#4 = 370 Hz, tnext=354, dur=716, soft 33 -> 23, sustain 390 -> 716
    db 202, 0, 163, 1, 184, 1, 27, 2  ; Note 906: T 258.9646 A4 = 440 Hz, tnext=202, dur=419, soft 39 -> 27
    db 8, 0, 83, 10, 139, 0, 28, 1  ; Note 907: T 259.1665 C#3 = 139 Hz, tnext=8, dur=2643, soft 40 -> 28, sustain 1524 -> 2643
    db 171, 0, 75, 10, 69, 0, 28, 1  ; Note 908: T 259.1745 C#2 = 69 Hz, tnext=171, dur=2635, soft 41 -> 28, sustain 1166 -> 2635
; T 259.3274 Sustain 0 (Instrument 1)
; T 259.3274 Sustain 0 (Instrument 2)
    db 9, 0, 159, 9, 42, 2, 35, 2  ; Note 909: T 259.3457 C#5 = 554 Hz, tnext=9, dur=2463, soft 51 -> 35, sustain 1099 -> 2463
    db 192, 1, 150, 9, 21, 1, 27, 1  ; Note 910: T 259.3548 C#4 = 277 Hz, tnext=448, dur=2454, soft 39 -> 27, sustain 1017 -> 2454
; T 259.7769 Sustain 127 (Instrument 1)
; T 259.7769 Sustain 127 (Instrument 2)
    db 154, 1, 214, 7, 93, 1, 23, 1  ; Note 911: T 259.8032 F4 = 349 Hz, tnext=410, dur=2006, soft 33 -> 23, sustain 891 -> 2006
    db 158, 1, 60, 6, 159, 1, 26, 2  ; Note 912: T 260.2128 G#4 = 415 Hz, tnext=414, dur=1596, soft 38 -> 26, sustain 483 -> 1596
    db 154, 1, 158, 4, 21, 1, 23, 1  ; Note 913: T 260.6269 C#4 = 277 Hz, tnext=410, dur=1182, soft 33 -> 23, sustain 727 -> 1182
    db 71, 1, 5, 3, 93, 1, 23, 1  ; Note 914: T 261.0365 F4 = 349 Hz, tnext=327, dur=773, soft 33 -> 23, sustain 396 -> 773
    db 4, 1, 7, 2, 159, 1, 27, 2  ; Note 915: T 261.3640 G#4 = 415 Hz, tnext=260, dur=519, soft 39 -> 27
; T 261.4085 Soft 0 (Instrument 1)
; T 261.4085 Soft 0 (Instrument 2)
    db 39, 0, 212, 10, 46, 0, 38, 1  ; Note 916: T 261.6241 F#1 = 46 Hz, tnext=39, dur=2772, sustain 1589 -> 2772
    db 156, 0, 173, 10, 92, 0, 38, 1  ; Note 917: T 261.6629 F#2 = 92 Hz, tnext=156, dur=2733, sustain 1488 -> 2733
; T 261.8090 Sustain 0 (Instrument 1)
; T 261.8090 Sustain 0 (Instrument 2)
    db 30, 0, 16, 10, 42, 2, 51, 2  ; Note 918: T 261.8192 C#5 = 554 Hz, tnext=30, dur=2576, sustain 832 -> 2576
    db 199, 1, 243, 9, 21, 1, 36, 1  ; Note 919: T 261.8489 C#4 = 277 Hz, tnext=455, dur=2547, sustain 944 -> 2547
; T 262.1626 Sustain 127 (Instrument 1)
; T 262.1626 Sustain 127 (Instrument 2)
    db 161, 1, 44, 8, 114, 1, 33, 1  ; Note 920: T 262.3040 F#4 = 370 Hz, tnext=417, dur=2092, sustain 521 -> 2092
    db 190, 1, 138, 6, 184, 1, 38, 2  ; Note 921: T 262.7214 A4 = 440 Hz, tnext=446, dur=1674, sustain 883 -> 1674
    db 153, 1, 204, 4, 21, 1, 33, 1  ; Note 922: T 263.1674 C#4 = 277 Hz, tnext=409, dur=1228, sustain 725 -> 1228
    db 144, 1, 91, 3, 114, 1, 33, 1  ; Note 923: T 263.5768 F#4 = 370 Hz, tnext=400, dur=859
    db 249, 0, 216, 1, 184, 1, 39, 2  ; Note 924: T 263.9771 A4 = 440 Hz, tnext=249, dur=472
    db 6, 0, 170, 14, 78, 0, 39, 1  ; Note 925: T 264.2257 D#2 = 78 Hz, tnext=6, dur=3754, sustain 965 -> 3754
    db 146, 0, 164, 14, 156, 0, 39, 1  ; Note 926: T 264.2314 D#3 = 156 Hz, tnext=146, dur=3748, sustain 1171 -> 3748
    db 16, 0, 18, 14, 238, 1, 52, 2  ; Note 927: T 264.3774 B4 = 494 Hz, tnext=16, dur=3602, sustain 1673 -> 3602
    db 237, 1, 2, 14, 247, 0, 37, 1  ; Note 928: T 264.3934 B3 = 247 Hz, tnext=493, dur=3586, sustain 989 -> 3586
; T 264.3957 Sustain 0 (Instrument 1)
; T 264.3957 Sustain 0 (Instrument 2)
; T 264.8473 Sustain 127 (Instrument 1)
; T 264.8473 Sustain 127 (Instrument 2)
    db 115, 1, 21, 12, 114, 1, 33, 1  ; Note 929: T 264.8861 F#4 = 370 Hz, tnext=371, dur=3093, sustain 796 -> 3093
    db 120, 1, 163, 10, 184, 1, 38, 2  ; Note 930: T 265.2567 A4 = 440 Hz, tnext=376, dur=2723, sustain 766 -> 2723
    db 150, 1, 42, 9, 247, 0, 33, 1  ; Note 931: T 265.6331 B3 = 247 Hz, tnext=406, dur=2346, sustain 948 -> 2346
    db 113, 1, 148, 7, 114, 1, 33, 1  ; Note 932: T 266.0391 F#4 = 370 Hz, tnext=369, dur=1940, sustain 810 -> 1940
    db 143, 1, 35, 6, 184, 1, 38, 2  ; Note 933: T 266.4085 A4 = 440 Hz, tnext=399, dur=1571, sustain 590 -> 1571
    db 110, 1, 148, 4, 247, 0, 33, 1  ; Note 934: T 266.8075 B3 = 247 Hz, tnext=366, dur=1172, sustain 853 -> 1172
    db 125, 1, 105, 3, 114, 1, 33, 1  ; Note 935: T 267.1735 F#4 = 370 Hz, tnext=381, dur=873
    db 21, 1, 243, 1, 184, 1, 38, 2  ; Note 936: T 267.5543 A4 = 440 Hz, tnext=277, dur=499
    db 33, 0, 211, 5, 82, 0, 38, 1  ; Note 937: T 267.8313 E2 = 82 Hz, tnext=33, dur=1491, sustain 815 -> 1491
    db 114, 0, 178, 5, 165, 0, 38, 1  ; Note 938: T 267.8643 E3 = 165 Hz, tnext=114, dur=1458, sustain 726 -> 1458
    db 3, 0, 64, 5, 247, 0, 36, 1  ; Note 939: T 267.9784 B3 = 247 Hz, tnext=3, dur=1344, sustain 922 -> 1344
; T 267.9795 Sustain 0 (Instrument 1)
; T 267.9795 Sustain 0 (Instrument 2)
    db 209, 1, 61, 5, 238, 1, 52, 2  ; Note 940: T 267.9818 B4 = 494 Hz, tnext=465, dur=1341, sustain 896 -> 1341
; T 268.3922 Sustain 127 (Instrument 1)
; T 268.3922 Sustain 127 (Instrument 2)
    db 166, 1, 130, 3, 74, 1, 33, 1  ; Note 941: T 268.4469 E4 = 330 Hz, tnext=422, dur=898
    db 253, 0, 211, 1, 159, 1, 38, 2  ; Note 942: T 268.8687 G#4 = 415 Hz, tnext=253, dur=467
    db 6, 0, 150, 5, 69, 0, 39, 1  ; Note 943: T 269.1218 C#2 = 69 Hz, tnext=6, dur=1430, sustain 937 -> 1430
    db 149, 0, 144, 5, 139, 0, 39, 1  ; Note 944: T 269.1275 C#3 = 139 Hz, tnext=149, dur=1424, sustain 925 -> 1424
    db 17, 0, 250, 4, 220, 0, 37, 1  ; Note 945: T 269.2769 A3 = 220 Hz, tnext=17, dur=1274, sustain 913 -> 1274
    db 169, 1, 233, 4, 184, 1, 52, 2  ; Note 946: T 269.2940 A4 = 440 Hz, tnext=425, dur=1257, sustain 824 -> 1257
; T 269.3225 Sustain 0 (Instrument 1)
; T 269.3225 Sustain 0 (Instrument 2)
    db 107, 1, 79, 3, 74, 1, 33, 1  ; Note 947: T 269.7192 E4 = 330 Hz, tnext=363, dur=847
; T 269.7408 Sustain 127 (Instrument 1)
; T 269.7408 Sustain 127 (Instrument 2)
    db 25, 1, 228, 1, 159, 1, 38, 2  ; Note 948: T 270.0817 G#4 = 415 Hz, tnext=281, dur=484
    db 67, 0, 166, 5, 78, 0, 36, 1  ; Note 949: T 270.3632 D#2 = 78 Hz, tnext=67, dur=1446, sustain 812 -> 1446
    db 92, 0, 99, 5, 156, 0, 36, 1  ; Note 950: T 270.4305 D#3 = 156 Hz, tnext=92, dur=1379, sustain 661 -> 1379
    db 8, 0, 7, 5, 184, 1, 44, 2  ; Note 951: T 270.5228 A4 = 440 Hz, tnext=8, dur=1287, sustain 865 -> 1287
    db 161, 1, 255, 4, 220, 0, 34, 1  ; Note 952: T 270.5308 A3 = 220 Hz, tnext=417, dur=1279, sustain 851 -> 1279
; T 270.5513 Sustain 0 (Instrument 1)
; T 270.5513 Sustain 0 (Instrument 2)
    db 154, 1, 94, 3, 55, 1, 33, 1  ; Note 953: T 270.9478 D#4 = 311 Hz, tnext=410, dur=862, sustain 670 -> 862
; T 270.9490 Sustain 127 (Instrument 1)
; T 270.9490 Sustain 127 (Instrument 2)
    db 36, 1, 250, 1, 114, 1, 33, 1  ; Note 954: T 271.3581 F#4 = 370 Hz, tnext=292, dur=506
    db 40, 0, 206, 5, 65, 0, 36, 1  ; Note 955: T 271.6498 C2 = 65 Hz, tnext=40, dur=1486, sustain 852 -> 1486
    db 99, 0, 166, 5, 131, 0, 36, 1  ; Note 956: T 271.6897 C3 = 131 Hz, tnext=99, dur=1446, sustain 804 -> 1446
    db 5, 0, 67, 5, 208, 0, 35, 1  ; Note 957: T 271.7889 G#3 = 208 Hz, tnext=5, dur=1347, sustain 1007 -> 1347
    db 216, 1, 62, 5, 159, 1, 44, 2  ; Note 958: T 271.7934 G#4 = 415 Hz, tnext=472, dur=1342, sustain 962 -> 1342
; T 271.8094 Sustain 0 (Instrument 1)
; T 271.8094 Sustain 0 (Instrument 2)
; T 272.1535 Sustain 127 (Instrument 1)
; T 272.1535 Sustain 127 (Instrument 2)
; T 272.2618 Soft 127 (Instrument 1)
; T 272.2618 Soft 127 (Instrument 2)
    db 174, 1, 103, 3, 55, 1, 23, 1  ; Note 959: T 272.2652 D#4 = 311 Hz, tnext=430, dur=871, soft 33 -> 23, sustain 552 -> 871
    db 6, 1, 25, 2, 114, 1, 23, 1  ; Note 960: T 272.6948 F#4 = 370 Hz, tnext=262, dur=537, soft 33 -> 23
    db 32, 0, 78, 6, 69, 0, 24, 1  ; Note 961: T 272.9569 C#2 = 69 Hz, tnext=32, dur=1614, soft 35 -> 24, sustain 874 -> 1614
    db 134, 0, 46, 6, 139, 0, 24, 1  ; Note 962: T 272.9888 C#3 = 139 Hz, tnext=134, dur=1582, soft 35 -> 24, sustain 700 -> 1582
    db 25, 0, 167, 5, 208, 0, 23, 1  ; Note 963: T 273.1233 G#3 = 208 Hz, tnext=25, dur=1447, soft 33 -> 23, sustain 1135 -> 1447
; T 273.1358 Sustain 0 (Instrument 1)
; T 273.1358 Sustain 0 (Instrument 2)
    db 214, 1, 142, 5, 159, 1, 30, 2  ; Note 964: T 273.1484 G#4 = 415 Hz, tnext=470, dur=1422, soft 44 -> 30, sustain 1022 -> 1422
; T 273.4903 Sustain 127 (Instrument 1)
; T 273.4903 Sustain 127 (Instrument 2)
    db 201, 1, 185, 3, 21, 1, 23, 1  ; Note 965: T 273.6179 C#4 = 277 Hz, tnext=457, dur=953, soft 33 -> 23, sustain 680 -> 953
    db 93, 1, 104, 2, 74, 1, 23, 1  ; Note 966: T 274.0749 E4 = 330 Hz, tnext=349, dur=616, soft 33 -> 23
    db 19, 0, 57, 11, 55, 0, 24, 1  ; Note 967: T 274.4235 A1 = 55 Hz, tnext=19, dur=2873, soft 35 -> 24, sustain 804 -> 2873
    db 128, 0, 37, 11, 110, 0, 24, 1  ; Note 968: T 274.4429 A2 = 110 Hz, tnext=128, dur=2853, soft 35 -> 24, sustain 939 -> 2853
    db 44, 0, 166, 10, 185, 0, 23, 1  ; Note 969: T 274.5705 F#3 = 185 Hz, tnext=44, dur=2726, soft 33 -> 23, sustain 1097 -> 2726
; T 274.5705 Sustain 0 (Instrument 1)
; T 274.5705 Sustain 0 (Instrument 2)
    db 211, 1, 122, 10, 114, 1, 28, 1  ; Note 970: T 274.6149 F#4 = 370 Hz, tnext=467, dur=2682, soft 40 -> 28, sustain 878 -> 2682
; T 274.9726 Sustain 127 (Instrument 1)
; T 274.9726 Sustain 127 (Instrument 2)
    db 180, 1, 166, 8, 21, 1, 23, 1  ; Note 971: T 275.0819 C#4 = 277 Hz, tnext=436, dur=2214, soft 33 -> 23, sustain 706 -> 2214
    db 153, 1, 242, 6, 55, 1, 23, 1  ; Note 972: T 275.5182 D#4 = 311 Hz, tnext=409, dur=1778, soft 33 -> 23, sustain 594 -> 1778
    db 188, 1, 89, 5, 185, 0, 23, 1  ; Note 973: T 275.9272 F#3 = 185 Hz, tnext=444, dur=1369, soft 33 -> 23, sustain 931 -> 1369
    db 200, 1, 234, 3, 21, 1, 23, 1  ; Note 974: T 276.3714 C#4 = 277 Hz, tnext=456, dur=1002, soft 33 -> 23
    db 42, 1, 35, 2, 55, 1, 23, 1  ; Note 975: T 276.8271 D#4 = 311 Hz, tnext=298, dur=547, soft 33 -> 23
    db 24, 0, 219, 5, 52, 0, 25, 1  ; Note 976: T 277.1255 G#1 = 52 Hz, tnext=24, dur=1499, soft 36 -> 25, sustain 893 -> 1499
    db 140, 0, 195, 5, 104, 0, 25, 1  ; Note 977: T 277.1495 G#2 = 104 Hz, tnext=140, dur=1475, soft 36 -> 25, sustain 779 -> 1475
    db 8, 0, 55, 5, 159, 1, 30, 2  ; Note 978: T 277.2896 G#4 = 415 Hz, tnext=8, dur=1335, soft 44 -> 30, sustain 914 -> 1335
; T 277.2964 Sustain 0 (Instrument 1)
; T 277.2964 Sustain 0 (Instrument 2)
    db 185, 1, 47, 5, 208, 0, 23, 1  ; Note 979: T 277.2975 G#3 = 208 Hz, tnext=441, dur=1327, soft 34 -> 23, sustain 698 -> 1327
; T 277.5857 Sustain 127 (Instrument 1)
; T 277.5857 Sustain 127 (Instrument 2)
    db 181, 1, 118, 3, 21, 1, 23, 1  ; Note 980: T 277.7384 C#4 = 277 Hz, tnext=437, dur=886, soft 33 -> 23, sustain 781 -> 886
    db 47, 1, 243, 1, 55, 1, 23, 1  ; Note 981: T 278.1758 D#4 = 311 Hz, tnext=303, dur=499, soft 34 -> 23
    db 46, 0, 19, 7, 46, 0, 25, 1  ; Note 982: T 278.4788 F#1 = 46 Hz, tnext=46, dur=1811, soft 37 -> 25, sustain 1020 -> 1811
    db 120, 0, 229, 6, 92, 0, 26, 1  ; Note 983: T 278.5243 F#2 = 92 Hz, tnext=120, dur=1765, soft 38 -> 26, sustain 1001 -> 1765
; T 278.6245 Sustain 0 (Instrument 1)
; T 278.6245 Sustain 0 (Instrument 2)
    db 39, 0, 109, 6, 220, 0, 25, 1  ; Note 984: T 278.6439 A3 = 220 Hz, tnext=39, dur=1645, soft 37 -> 25, sustain 1149 -> 1645
    db 38, 2, 71, 6, 184, 1, 31, 2  ; Note 985: T 278.6826 A4 = 440 Hz, tnext=550, dur=1607, soft 45 -> 31, sustain 936 -> 1607
; T 279.2007 Sustain 127 (Instrument 1)
; T 279.2007 Sustain 127 (Instrument 2)
    db 2, 2, 33, 4, 21, 1, 23, 1  ; Note 986: T 279.2326 C#4 = 277 Hz, tnext=514, dur=1057, soft 33 -> 23, sustain 682 -> 1057
    db 113, 1, 31, 2, 55, 1, 23, 1  ; Note 987: T 279.7461 D#4 = 311 Hz, tnext=369, dur=543, soft 33 -> 23, sustain 204 -> 543
    db 47, 0, 59, 12, 52, 0, 25, 1  ; Note 988: T 280.1151 G#1 = 52 Hz, tnext=47, dur=3131, soft 36 -> 25, sustain 2544 -> 3131
    db 147, 0, 12, 12, 104, 0, 25, 1  ; Note 989: T 280.1617 G#2 = 104 Hz, tnext=147, dur=3084, soft 36 -> 25, sustain 2474 -> 3084
; T 280.2893 Sustain 0 (Instrument 1)
; T 280.2893 Sustain 0 (Instrument 2)
    db 8, 0, 122, 11, 159, 1, 30, 2  ; Note 990: T 280.3086 G#4 = 415 Hz, tnext=8, dur=2938, soft 43 -> 30, sustain 2622 -> 2938
    db 38, 2, 114, 11, 208, 0, 23, 1  ; Note 991: T 280.3166 G#3 = 208 Hz, tnext=550, dur=2930, soft 34 -> 23, sustain 1106 -> 2930
; T 280.7413 Sustain 127 (Instrument 1)
; T 280.7413 Sustain 127 (Instrument 2)
    db 190, 1, 76, 9, 21, 1, 23, 1  ; Note 992: T 280.8666 C#4 = 277 Hz, tnext=446, dur=2380, soft 33 -> 23, sustain 1073 -> 2380
    db 214, 1, 141, 7, 74, 1, 23, 1  ; Note 993: T 281.3129 E4 = 330 Hz, tnext=470, dur=1933, soft 33 -> 23, sustain 1082 -> 1933
    db 246, 1, 183, 5, 208, 0, 23, 1  ; Note 994: T 281.7832 G#3 = 208 Hz, tnext=502, dur=1463, soft 33 -> 23, sustain 1116 -> 1463
    db 155, 1, 193, 3, 21, 1, 23, 1  ; Note 995: T 282.2854 C#4 = 277 Hz, tnext=411, dur=961, soft 33 -> 23, sustain 653 -> 961
    db 110, 1, 38, 2, 74, 1, 23, 1  ; Note 996: T 282.6963 E4 = 330 Hz, tnext=366, dur=550, soft 33 -> 23, sustain 229 -> 550
    db 47, 0, 40, 12, 52, 0, 25, 1  ; Note 997: T 283.0628 G#1 = 52 Hz, tnext=47, dur=3112, soft 36 -> 25, sustain 2092 -> 3112
    db 132, 0, 249, 11, 104, 0, 25, 1  ; Note 998: T 283.1095 G#2 = 104 Hz, tnext=132, dur=3065, soft 36 -> 25, sustain 2092 -> 3065
    db 22, 0, 117, 11, 159, 1, 30, 2  ; Note 999: T 283.2415 G#4 = 415 Hz, tnext=22, dur=2933, soft 44 -> 30, sustain 2448 -> 2933
; T 283.2461 Sustain 0 (Instrument 1)
; T 283.2461 Sustain 0 (Instrument 2)
    db 202, 1, 95, 11, 185, 0, 24, 1  ; Note 1000: T 283.2632 F#3 = 185 Hz, tnext=458, dur=2911, soft 35 -> 24, sustain 996 -> 2911
; T 283.5398 Sustain 127 (Instrument 1)
; T 283.5398 Sustain 127 (Instrument 2)
    db 183, 1, 150, 9, 6, 1, 23, 1  ; Note 1001: T 283.7207 C4 = 262 Hz, tnext=439, dur=2454, soft 33 -> 23, sustain 1065 -> 2454
    db 214, 1, 223, 7, 55, 1, 23, 1  ; Note 1002: T 284.1601 D#4 = 311 Hz, tnext=470, dur=2015, soft 33 -> 23, sustain 633 -> 2015
    db 10, 2, 8, 6, 185, 0, 23, 1  ; Note 1003: T 284.6302 F#3 = 185 Hz, tnext=522, dur=1544, soft 33 -> 23, sustain 960 -> 1544
    db 6, 2, 254, 3, 6, 1, 23, 1  ; Note 1004: T 285.1526 C4 = 262 Hz, tnext=518, dur=1022, soft 33 -> 23, sustain 693 -> 1022
    db 106, 1, 248, 1, 55, 1, 23, 1  ; Note 1005: T 285.6705 D#4 = 311 Hz, tnext=362, dur=504, soft 33 -> 23, sustain 174 -> 504
    db 11, 0, 12, 22, 69, 0, 25, 1  ; Note 1006: T 286.0324 C#2 = 69 Hz, tnext=11, dur=5644, soft 36 -> 25, sustain 4807 -> 5644
    db 136, 0, 206, 15, 104, 0, 25, 1  ; Note 1007: T 286.0438 G#2 = 104 Hz, tnext=136, dur=4046, soft 36 -> 25, sustain 3630 -> 4046
; T 286.1747 Sustain 0 (Instrument 1)
; T 286.1747 Sustain 0 (Instrument 2)
    db 8, 0, 71, 15, 165, 0, 23, 1  ; Note 1008: T 286.1793 E3 = 165 Hz, tnext=8, dur=3911, soft 34 -> 23, sustain 551 -> 3911
    db 191, 1, 63, 15, 21, 1, 24, 1  ; Note 1009: T 286.1872 C#4 = 277 Hz, tnext=447, dur=3903, soft 35 -> 24, sustain 543 -> 3903
; T 286.5526 Sustain 127 (Instrument 1)
; T 286.5526 Sustain 127 (Instrument 2)
    db 198, 1, 127, 13, 208, 0, 23, 1  ; Note 1010: T 286.6345 G#3 = 208 Hz, tnext=454, dur=3455, soft 33 -> 23, sustain 578 -> 3455
    db 130, 1, 185, 11, 21, 1, 23, 1  ; Note 1011: T 287.0885 C#4 = 277 Hz, tnext=386, dur=3001, soft 33 -> 23, sustain 420 -> 3001
    db 193, 1, 56, 10, 208, 0, 23, 1  ; Note 1012: T 287.4742 G#3 = 208 Hz, tnext=449, dur=2616, soft 33 -> 23, sustain 1122 -> 2616
    db 165, 1, 118, 8, 21, 1, 23, 1  ; Note 1013: T 287.9236 C#4 = 277 Hz, tnext=421, dur=2166, soft 33 -> 23, sustain 539 -> 2166
    db 199, 1, 209, 6, 74, 1, 23, 1  ; Note 1014: T 288.3446 E4 = 330 Hz, tnext=455, dur=1745, soft 33 -> 23, sustain 944 -> 1745
    db 157, 1, 10, 5, 208, 0, 23, 1  ; Note 1015: T 288.7997 G#3 = 208 Hz, tnext=413, dur=1290, soft 33 -> 23, sustain 779 -> 1290
    db 162, 1, 109, 3, 21, 1, 23, 1  ; Note 1016: T 289.2127 C#4 = 277 Hz, tnext=418, dur=877, soft 33 -> 23, sustain 554 -> 877
    db 109, 1, 254, 7, 74, 1, 23, 1  ; Note 1017: T 289.6303 E4 = 330 Hz, tnext=365, dur=2046, soft 33 -> 23, sustain 1106 -> 2046
    db 189, 0, 145, 6, 104, 0, 30, 1  ; Note 1018: T 289.9955 G#2 = 104 Hz, tnext=189, dur=1681, soft 44 -> 30, sustain 809 -> 1681
; T 290.0899 Sustain 0 (Instrument 1)
; T 290.0899 Sustain 0 (Instrument 2)
    db 174, 1, 212, 5, 208, 0, 23, 1  ; Note 1019: T 290.1843 G#3 = 208 Hz, tnext=430, dur=1492, soft 33 -> 23, sustain 593 -> 1492
; T 290.4676 Sustain 127 (Instrument 1)
; T 290.4676 Sustain 127 (Instrument 2)
    db 165, 1, 38, 4, 21, 1, 24, 1  ; Note 1020: T 290.6144 C#4 = 277 Hz, tnext=421, dur=1062, soft 35 -> 24, sustain 509 -> 1062
    db 40, 1, 129, 2, 74, 1, 23, 1  ; Note 1021: T 291.0353 E4 = 330 Hz, tnext=296, dur=641, soft 34 -> 23, sustain 289 -> 641
    db 235, 0, 90, 1, 104, 0, 27, 1  ; Note 1022: T 291.3310 G#2 = 104 Hz, tnext=235, dur=346, soft 39 -> 27, sustain 216 -> 346
; T 291.4538 Soft 0 (Instrument 1)
; T 291.4538 Soft 0 (Instrument 2)
    db 98, 0, 112, 21, 65, 0, 35, 1  ; Note 1023: T 291.5664 C2 = 65 Hz, tnext=98, dur=5488, sustain 4685 -> 5488
    db 68, 0, 37, 15, 104, 0, 41, 1  ; Note 1024: T 291.6642 G#2 = 104 Hz, tnext=68, dur=3877, sustain 3506 -> 3877
; T 291.6767 Sustain 0 (Instrument 1)
; T 291.6767 Sustain 0 (Instrument 2)
    db 155, 1, 170, 3, 208, 0, 40, 1  ; Note 1025: T 291.7324 G#3 = 208 Hz, tnext=411, dur=938
    db 174, 1, 217, 1, 55, 1, 33, 1  ; Note 1026: T 292.1430 D#4 = 311 Hz, tnext=430, dur=473
    db 181, 1, 152, 11, 114, 1, 33, 1  ; Note 1027: T 292.5729 F#4 = 370 Hz, tnext=437, dur=2968, sustain 524 -> 2968
; T 292.6741 Sustain 127 (Instrument 1)
; T 292.6741 Sustain 127 (Instrument 2)
    db 174, 1, 227, 9, 208, 0, 33, 1  ; Note 1028: T 293.0096 G#3 = 208 Hz, tnext=430, dur=2531, sustain 991 -> 2531
    db 165, 1, 53, 8, 55, 1, 33, 1  ; Note 1029: T 293.4395 D#4 = 311 Hz, tnext=421, dur=2101, sustain 587 -> 2101
    db 164, 1, 145, 6, 114, 1, 33, 1  ; Note 1030: T 293.8603 F#4 = 370 Hz, tnext=420, dur=1681, sustain 819 -> 1681
    db 149, 1, 237, 4, 208, 0, 33, 1  ; Note 1031: T 294.2800 G#3 = 208 Hz, tnext=405, dur=1261, sustain 738 -> 1261
    db 159, 1, 88, 3, 55, 1, 33, 1  ; Note 1032: T 294.6849 D#4 = 311 Hz, tnext=415, dur=856, sustain 618 -> 856
    db 160, 1, 185, 1, 114, 1, 33, 1  ; Note 1033: T 295.0999 F#4 = 370 Hz, tnext=416, dur=441, sustain 422 -> 441
    db 105, 0, 2, 6, 104, 0, 44, 1  ; Note 1034: T 295.5159 G#2 = 104 Hz, tnext=105, dur=1538, sustain 768 -> 1538
; T 295.5410 Sustain 0 (Instrument 1)
; T 295.5410 Sustain 0 (Instrument 2)
    db 162, 1, 154, 5, 208, 0, 33, 1  ; Note 1035: T 295.6205 G#3 = 208 Hz, tnext=418, dur=1434, sustain 738 -> 1434
; T 296.0048 Sustain 127 (Instrument 1)
; T 296.0048 Sustain 127 (Instrument 2)
    db 189, 1, 247, 3, 55, 1, 33, 1  ; Note 1036: T 296.0389 D#4 = 311 Hz, tnext=445, dur=1015, sustain 521 -> 1015
    db 32, 1, 59, 2, 114, 1, 33, 1  ; Note 1037: T 296.4834 F#4 = 370 Hz, tnext=288, dur=571, sustain 516 -> 571
; T 296.6312 Soft 0 (Instrument 1)
; T 296.6312 Soft 0 (Instrument 2)
    db 194, 0, 27, 1, 104, 0, 41, 1  ; Note 1038: T 296.7710 G#2 = 104 Hz, tnext=194, dur=283, sustain 197 -> 283
    db 42, 0, 234, 17, 69, 0, 34, 1  ; Note 1039: T 296.9654 C#2 = 69 Hz, tnext=42, dur=4586, sustain 4062 -> 4586
    db 47, 0, 187, 12, 208, 0, 35, 1  ; Note 1040: T 297.0075 G#3 = 208 Hz, tnext=47, dur=3259, sustain 510 -> 3259
    db 158, 1, 140, 12, 104, 0, 40, 1  ; Note 1041: T 297.0541 G#2 = 104 Hz, tnext=414, dur=3212, sustain 2911 -> 3212
; T 297.0541 Sustain 0 (Instrument 1)
; T 297.0541 Sustain 0 (Instrument 2)
; T 297.4611 Sustain 127 (Instrument 1)
; T 297.4611 Sustain 127 (Instrument 2)
    db 125, 1, 238, 10, 74, 1, 33, 1  ; Note 1042: T 297.4679 E4 = 330 Hz, tnext=381, dur=2798, sustain 377 -> 2798
    db 85, 1, 114, 9, 21, 1, 37, 1  ; Note 1043: T 297.8488 C#4 = 277 Hz, tnext=341, dur=2418, sustain 473 -> 2418
    db 74, 1, 29, 8, 159, 1, 43, 2  ; Note 1044: T 298.1898 G#4 = 415 Hz, tnext=330, dur=2077, sustain 452 -> 2077
    db 152, 1, 211, 6, 74, 1, 37, 1  ; Note 1045: T 298.5195 E4 = 330 Hz, tnext=408, dur=1747, sustain 506 -> 1747
    db 72, 1, 59, 5, 42, 2, 40, 2  ; Note 1046: T 298.9276 C#5 = 554 Hz, tnext=328, dur=1339, sustain 231 -> 1339
    db 97, 1, 242, 3, 159, 1, 44, 2  ; Note 1047: T 299.2560 G#4 = 415 Hz, tnext=353, dur=1010, sustain 397 -> 1010
    db 83, 1, 145, 2, 147, 2, 41, 2  ; Note 1048: T 299.6094 E5 = 659 Hz, tnext=339, dur=657, sustain 409 -> 657
    db 40, 1, 15, 2, 42, 2, 42, 2  ; Note 1049: T 299.9481 C#5 = 554 Hz, tnext=296, dur=527
    db 222, 0, 28, 5, 104, 0, 44, 1  ; Note 1050: T 300.2436 G#2 = 104 Hz, tnext=222, dur=1308, sustain 802 -> 1308
; T 300.2663 Sustain 0 (Instrument 1)
; T 300.2663 Sustain 0 (Instrument 2)
    db 112, 1, 62, 4, 63, 3, 41, 2  ; Note 1051: T 300.4652 G#5 = 831 Hz, tnext=368, dur=1086, sustain 364 -> 1086
; T 300.8118 Sustain 127 (Instrument 1)
; T 300.8118 Sustain 127 (Instrument 2)
    db 61, 1, 206, 2, 147, 2, 38, 2  ; Note 1052: T 300.8333 E5 = 659 Hz, tnext=317, dur=718, sustain 353 -> 718
    db 164, 0, 177, 1, 42, 2, 38, 2  ; Note 1053: T 301.1504 C#5 = 554 Hz, tnext=164, dur=433
    db 168, 0, 237, 0, 104, 0, 47, 1  ; Note 1054: T 301.3140 G#2 = 104 Hz, tnext=168, dur=237, sustain 83 -> 237
    db 40, 0, 42, 18, 52, 0, 35, 1  ; Note 1055: T 301.4822 G#1 = 52 Hz, tnext=40, dur=4650, sustain 4113 -> 4650
    db 51, 0, 117, 12, 104, 0, 42, 1  ; Note 1056: T 301.5220 G#2 = 104 Hz, tnext=51, dur=3189, sustain 2709 -> 3189
; T 301.5515 Sustain 0 (Instrument 1)
; T 301.5515 Sustain 0 (Instrument 2)
    db 84, 1, 87, 1, 11, 2, 43, 2  ; Note 1057: T 301.5731 C5 = 523 Hz, tnext=340, dur=343
    db 71, 1, 166, 2, 110, 2, 40, 2  ; Note 1058: T 301.9129 D#5 = 622 Hz, tnext=327, dur=678, sustain 336 -> 678
; T 302.1822 Sustain 127 (Instrument 1)
; T 302.1822 Sustain 127 (Instrument 2)
    db 101, 1, 205, 1, 184, 1, 38, 2  ; Note 1059: T 302.2402 A4 = 440 Hz, tnext=357, dur=461
; T 302.5913 Sustain 0 (Instrument 1)
; T 302.5913 Sustain 0 (Instrument 2)
    db 66, 1, 124, 3, 11, 2, 38, 2  ; Note 1060: T 302.5970 C5 = 523 Hz, tnext=322, dur=892, sustain 351 -> 892
; T 302.7868 Sustain 127 (Instrument 1)
; T 302.7868 Sustain 127 (Instrument 2)
    db 71, 1, 58, 2, 114, 1, 34, 1  ; Note 1061: T 302.9186 F#4 = 370 Hz, tnext=327, dur=570, sustain 377 -> 570
    db 114, 1, 195, 1, 184, 1, 38, 2  ; Note 1062: T 303.2458 A4 = 440 Hz, tnext=370, dur=451
; T 303.4889 Sustain 0 (Instrument 1)
; T 303.4889 Sustain 0 (Instrument 2)
    db 88, 1, 71, 4, 55, 1, 33, 1  ; Note 1063: T 303.6161 D#4 = 311 Hz, tnext=344, dur=1095, sustain 435 -> 1095
; T 303.7149 Sustain 127 (Instrument 1)
; T 303.7149 Sustain 127 (Instrument 2)
    db 139, 1, 239, 2, 114, 1, 34, 1  ; Note 1064: T 303.9603 F#4 = 370 Hz, tnext=395, dur=751, sustain 435 -> 751
    db 128, 1, 159, 3, 220, 0, 36, 1  ; Note 1065: T 304.3556 A3 = 220 Hz, tnext=384, dur=927
; T 304.7112 Sustain 0 (Instrument 1)
; T 304.7112 Sustain 0 (Instrument 2)
    db 127, 0, 113, 5, 104, 0, 40, 1  ; Note 1066: T 304.7396 G#2 = 104 Hz, tnext=127, dur=1393, sustain 887 -> 1393
    db 159, 1, 241, 4, 6, 1, 38, 1  ; Note 1067: T 304.8668 C4 = 262 Hz, tnext=415, dur=1265, sustain 995 -> 1265
    db 134, 1, 83, 3, 208, 0, 36, 1  ; Note 1068: T 305.2814 G#3 = 208 Hz, tnext=390, dur=851, sustain 453 -> 851
; T 305.3836 Sustain 127 (Instrument 1)
; T 305.3836 Sustain 127 (Instrument 2)
    db 4, 1, 205, 1, 185, 0, 33, 1  ; Note 1069: T 305.6710 F#3 = 185 Hz, tnext=260, dur=461, sustain 440 -> 461
    db 216, 0, 201, 0, 104, 0, 37, 1  ; Note 1070: T 305.9312 G#2 = 104 Hz, tnext=216, dur=201, sustain 103 -> 201
; T 306.1322 Sustain 0 (Instrument 1)
; T 306.1322 Sustain 0 (Instrument 2)
    db 1, 0, 116, 1, 165, 0, 34, 1  ; Note 1071: T 306.1470 E3 = 165 Hz, tnext=1, dur=372
    db 6, 0, 154, 12, 104, 0, 34, 1  ; Note 1072: T 306.1481 G#2 = 104 Hz, tnext=6, dur=3226, sustain 2827 -> 3226
    db 1, 0, 149, 12, 21, 1, 34, 1  ; Note 1073: T 306.1538 C#4 = 277 Hz, tnext=1, dur=3221, sustain 538 -> 3221
    db 151, 1, 225, 17, 69, 0, 34, 1  ; Note 1074: T 306.1549 C#2 = 69 Hz, tnext=407, dur=4577, sustain 3892 -> 4577
; T 306.3196 Soft 127 (Instrument 1)
; T 306.3196 Soft 127 (Instrument 2)
    db 133, 1, 253, 10, 74, 1, 23, 1  ; Note 1075: T 306.5616 E4 = 330 Hz, tnext=389, dur=2813, soft 33 -> 23, sustain 300 -> 2813
; T 306.5809 Sustain 127 (Instrument 1)
; T 306.5809 Sustain 127 (Instrument 2)
    db 64, 1, 120, 9, 21, 1, 24, 1  ; Note 1076: T 306.9501 C#4 = 277 Hz, tnext=320, dur=2424, soft 35 -> 24, sustain 506 -> 2424
    db 80, 1, 56, 8, 159, 1, 30, 2  ; Note 1077: T 307.2704 G#4 = 415 Hz, tnext=336, dur=2104, soft 43 -> 30, sustain 807 -> 2104
    db 85, 1, 232, 6, 74, 1, 25, 1  ; Note 1078: T 307.6065 E4 = 330 Hz, tnext=341, dur=1768, soft 37 -> 25, sustain 452 -> 1768
    db 86, 1, 147, 5, 42, 2, 27, 2  ; Note 1079: T 307.9471 C#5 = 554 Hz, tnext=342, dur=1427, soft 39 -> 27, sustain 230 -> 1427
    db 105, 1, 61, 4, 159, 1, 26, 2  ; Note 1080: T 308.2889 G#4 = 415 Hz, tnext=361, dur=1085, soft 38 -> 26, sustain 418 -> 1085
    db 78, 1, 212, 2, 147, 2, 26, 2  ; Note 1081: T 308.6500 E5 = 659 Hz, tnext=334, dur=724, soft 38 -> 26, sustain 356 -> 724
    db 62, 1, 229, 1, 42, 2, 28, 2  ; Note 1082: T 308.9838 C#5 = 554 Hz, tnext=318, dur=485, soft 40 -> 28
    db 131, 0, 151, 5, 104, 0, 28, 1  ; Note 1083: T 309.3017 G#2 = 104 Hz, tnext=131, dur=1431, soft 41 -> 28, sustain 777 -> 1431
; T 309.3744 Sustain 0 (Instrument 1)
; T 309.3744 Sustain 0 (Instrument 2)
    db 182, 1, 20, 5, 63, 3, 31, 2  ; Note 1084: T 309.4323 G#5 = 831 Hz, tnext=438, dur=1300, soft 45 -> 31, sustain 483 -> 1300
; T 309.8002 Sustain 127 (Instrument 1)
; T 309.8002 Sustain 127 (Instrument 2)
    db 148, 1, 94, 3, 147, 2, 28, 2  ; Note 1085: T 309.8706 E5 = 659 Hz, tnext=404, dur=862, soft 40 -> 28, sustain 493 -> 862
    db 170, 0, 249, 1, 42, 2, 26, 2  ; Note 1086: T 310.2748 C#5 = 554 Hz, tnext=170, dur=505, soft 38 -> 26
    db 255, 0, 31, 1, 104, 0, 25, 1  ; Note 1087: T 310.4452 G#2 = 104 Hz, tnext=255, dur=287, soft 36 -> 25, sustain 70 -> 287
    db 15, 0, 252, 12, 104, 0, 24, 1  ; Note 1088: T 310.7006 G#2 = 104 Hz, tnext=15, dur=3324, soft 35 -> 24, sustain 2925 -> 3324
    db 22, 0, 250, 18, 52, 0, 24, 1  ; Note 1089: T 310.7154 G#1 = 52 Hz, tnext=22, dur=4858, soft 35 -> 24, sustain 4354 -> 4858
; T 310.7324 Sustain 0 (Instrument 1)
; T 310.7324 Sustain 0 (Instrument 2)
    db 113, 1, 91, 7, 11, 2, 28, 2  ; Note 1090: T 310.7370 C5 = 523 Hz, tnext=369, dur=1883, soft 41 -> 28, sustain 385 -> 1883
; T 311.0674 Sustain 127 (Instrument 1)
; T 311.0674 Sustain 127 (Instrument 2)
    db 91, 1, 234, 5, 110, 2, 26, 2  ; Note 1091: T 311.1060 D#5 = 622 Hz, tnext=347, dur=1514, soft 38 -> 26, sustain 381 -> 1514
    db 86, 1, 143, 4, 184, 1, 26, 2  ; Note 1092: T 311.4534 A4 = 440 Hz, tnext=342, dur=1167, soft 38 -> 26, sustain 431 -> 1167
    db 106, 1, 57, 3, 11, 2, 26, 2  ; Note 1093: T 311.7950 C5 = 523 Hz, tnext=362, dur=825, soft 38 -> 26, sustain 377 -> 825
    db 83, 1, 207, 1, 114, 1, 23, 1  ; Note 1094: T 312.1571 F#4 = 370 Hz, tnext=339, dur=463, soft 33 -> 23, sustain 384 -> 463
    db 116, 1, 248, 5, 184, 1, 26, 2  ; Note 1095: T 312.4965 A4 = 440 Hz, tnext=372, dur=1528, soft 38 -> 26, sustain 434 -> 1528
; T 312.6202 Sustain 0 (Instrument 1)
; T 312.6202 Sustain 0 (Instrument 2)
    db 112, 1, 132, 4, 55, 1, 23, 1  ; Note 1096: T 312.8687 D#4 = 311 Hz, tnext=368, dur=1156, soft 33 -> 23, sustain 450 -> 1156
; T 312.8687 Sustain 127 (Instrument 1)
; T 312.8687 Sustain 127 (Instrument 2)
    db 111, 1, 20, 3, 114, 1, 23, 1  ; Note 1097: T 313.2365 F#4 = 370 Hz, tnext=367, dur=788, soft 33 -> 23, sustain 421 -> 788
    db 146, 1, 227, 3, 220, 0, 23, 1  ; Note 1098: T 313.6031 A3 = 220 Hz, tnext=402, dur=995, soft 33 -> 23
    db 151, 0, 32, 6, 104, 0, 25, 1  ; Note 1099: T 314.0049 G#2 = 104 Hz, tnext=151, dur=1568, soft 37 -> 25, sustain 1057 -> 1568
; T 314.0242 Sustain 0 (Instrument 1)
; T 314.0242 Sustain 0 (Instrument 2)
    db 200, 1, 138, 5, 6, 1, 28, 1  ; Note 1100: T 314.1559 C4 = 262 Hz, tnext=456, dur=1418, soft 41 -> 28, sustain 1091 -> 1418
    db 136, 1, 193, 3, 208, 0, 23, 1  ; Note 1101: T 314.6121 G#3 = 208 Hz, tnext=392, dur=961, soft 33 -> 23, sustain 515 -> 961
; T 314.8743 Sustain 127 (Instrument 1)
; T 314.8743 Sustain 127 (Instrument 2)
    db 99, 1, 58, 2, 185, 0, 23, 1  ; Note 1102: T 315.0037 F#3 = 185 Hz, tnext=355, dur=570, soft 33 -> 23, sustain 293 -> 570
; T 315.0537 Soft 127 (Instrument 1)
; T 315.0537 Soft 127 (Instrument 2)
    db 129, 0, 214, 0, 104, 0, 23, 1  ; Note 1103: T 315.3590 G#2 = 104 Hz, tnext=129, dur=214, soft 33 -> 23, sustain 83 -> 214
    db 51, 0, 218, 32, 69, 0, 23, 1  ; Note 1104: T 315.4883 C#2 = 69 Hz, tnext=51, dur=8410, soft 34 -> 23, sustain 1102 -> 8410
    db 65, 0, 167, 32, 104, 0, 24, 1  ; Note 1105: T 315.5394 G#2 = 104 Hz, tnext=65, dur=8359, soft 35 -> 24, sustain 778 -> 8359
; T 315.5734 Sustain 0 (Instrument 1)
; T 315.5734 Sustain 0 (Instrument 2)
    db 9, 0, 102, 32, 165, 0, 25, 1  ; Note 1106: T 315.6040 E3 = 165 Hz, tnext=9, dur=8294, soft 36 -> 25, sustain 714 -> 8294
    db 125, 1, 93, 32, 21, 1, 25, 1  ; Note 1107: T 315.6131 C#4 = 277 Hz, tnext=381, dur=8285, soft 36 -> 25, sustain 463 -> 8285
; T 315.9342 Sustain 127 (Instrument 1)
; T 315.9342 Sustain 127 (Instrument 2)
    db 131, 1, 224, 30, 208, 0, 23, 1  ; Note 1108: T 315.9943 G#3 = 208 Hz, tnext=387, dur=7904, soft 33 -> 23, sustain 790 -> 7904
    db 103, 1, 93, 29, 21, 1, 23, 1  ; Note 1109: T 316.3812 C#4 = 277 Hz, tnext=359, dur=7517, soft 33 -> 23, sustain 537 -> 7517
    db 123, 1, 246, 27, 74, 1, 23, 1  ; Note 1110: T 316.7397 E4 = 330 Hz, tnext=379, dur=7158, soft 33 -> 23, sustain 455 -> 7158
    db 79, 1, 123, 26, 21, 1, 23, 1  ; Note 1111: T 317.1187 C#4 = 277 Hz, tnext=335, dur=6779, soft 33 -> 23, sustain 475 -> 6779
    db 98, 1, 45, 25, 208, 0, 23, 1  ; Note 1112: T 317.4534 G#3 = 208 Hz, tnext=354, dur=6445, soft 33 -> 23, sustain 232 -> 6445
    db 134, 1, 203, 23, 139, 0, 23, 1  ; Note 1113: T 317.8074 C#3 = 139 Hz, tnext=390, dur=6091, soft 33 -> 23, sustain 462 -> 6091
    db 89, 1, 68, 22, 165, 0, 23, 1  ; Note 1114: T 318.1977 E3 = 165 Hz, tnext=345, dur=5700, soft 33 -> 23, sustain 456 -> 5700
    db 80, 1, 235, 20, 208, 0, 23, 1  ; Note 1115: T 318.5426 G#3 = 208 Hz, tnext=336, dur=5355, soft 33 -> 23, sustain 454 -> 5355
    db 115, 1, 156, 19, 21, 1, 23, 1  ; Note 1116: T 318.8784 C#4 = 277 Hz, tnext=371, dur=5020, soft 33 -> 23, sustain 588 -> 5020
    db 126, 1, 41, 18, 208, 0, 23, 1  ; Note 1117: T 319.2494 G#3 = 208 Hz, tnext=382, dur=4649, soft 33 -> 23, sustain 465 -> 4649
    db 45, 1, 170, 16, 165, 0, 23, 1  ; Note 1118: T 319.6316 E3 = 165 Hz, tnext=301, dur=4266, soft 33 -> 23, sustain 189 -> 4266
    db 119, 1, 126, 15, 104, 0, 25, 1  ; Note 1119: T 319.9322 G#2 = 104 Hz, tnext=375, dur=3966, soft 37 -> 25, sustain 257 -> 3966
    db 183, 1, 6, 14, 139, 0, 23, 1  ; Note 1120: T 320.3076 C#3 = 139 Hz, tnext=439, dur=3590, soft 33 -> 23, sustain 939 -> 3590
    db 147, 1, 79, 12, 165, 0, 23, 1  ; Note 1121: T 320.7465 E3 = 165 Hz, tnext=403, dur=3151, soft 33 -> 23, sustain 582 -> 3151
    db 121, 1, 189, 10, 208, 0, 23, 1  ; Note 1122: T 321.1491 G#3 = 208 Hz, tnext=377, dur=2749, soft 33 -> 23, sustain 414 -> 2749
    db 153, 1, 68, 9, 165, 0, 23, 1  ; Note 1123: T 321.5256 E3 = 165 Hz, tnext=409, dur=2372, soft 33 -> 23, sustain 485 -> 2372
    db 192, 1, 171, 7, 139, 0, 23, 1  ; Note 1124: T 321.9351 C#3 = 139 Hz, tnext=448, dur=1963, soft 33 -> 23, sustain 564 -> 1963
    db 32, 2, 235, 5, 104, 0, 23, 1  ; Note 1125: T 322.3830 G#2 = 104 Hz, tnext=544, dur=1515, soft 33 -> 23, sustain 221 -> 1515
    db 9, 2, 203, 3, 139, 0, 23, 1  ; Note 1126: T 322.9274 C#3 = 139 Hz, tnext=521, dur=971, soft 33 -> 23, sustain 618 -> 971
    db 39, 2, 147, 2, 104, 0, 23, 1  ; Note 1127: T 323.4480 G#2 = 104 Hz, tnext=551, dur=659, soft 33 -> 23
; T 323.8980 Sustain 0 (Instrument 1)
; T 323.8980 Sustain 0 (Instrument 2)
    db 89, 2, 188, 2, 82, 0, 25, 1  ; Note 1128: T 323.9989 E2 = 82 Hz, tnext=601, dur=700, soft 36 -> 25
; T 324.1440 Sustain 127 (Instrument 1)
; T 324.1440 Sustain 127 (Instrument 2)
    db 236, 2, 29, 3, 104, 0, 23, 1  ; Note 1129: T 324.5998 G#2 = 104 Hz, tnext=748, dur=797, soft 33 -> 23
; T 324.6338 Sustain 0 (Instrument 1)
; T 324.6338 Sustain 0 (Instrument 2)
; T 324.9671 Sustain 127 (Instrument 1)
; T 324.9671 Sustain 127 (Instrument 2)
    db 158, 3, 221, 3, 82, 0, 23, 1  ; Note 1130: T 325.3480 E2 = 82 Hz, tnext=926, dur=989, soft 33 -> 23
; T 325.3763 Sustain 0 (Instrument 1)
; T 325.3763 Sustain 0 (Instrument 2)
; T 325.6121 Sustain 127 (Instrument 1)
; T 325.6121 Sustain 127 (Instrument 2)
    db 19, 11, 115, 66, 69, 0, 23, 1  ; Note 1131: T 326.2742 C#2 = 69 Hz, tnext=2835, dur=17011, soft 33 -> 23, sustain 1378 -> 17011
; T 326.2810 Sustain 0 (Instrument 1)
; T 326.2810 Sustain 0 (Instrument 2)
; T 327.2004 Sustain 127 (Instrument 1)
; T 327.2004 Sustain 127 (Instrument 2)
    db 6, 0, 96, 55, 69, 0, 24, 1  ; Note 1132: T 329.1089 C#2 = 69 Hz, tnext=6, dur=14176, soft 35 -> 24, sustain 451 -> 14176
    db 7, 0, 91, 55, 21, 1, 25, 1  ; Note 1133: T 329.1145 C#4 = 277 Hz, tnext=7, dur=14171, soft 36 -> 25, sustain 642 -> 14171
    db 0, 0, 84, 55, 139, 0, 25, 1  ; Note 1134: T 329.1213 C#3 = 139 Hz, tnext=0, dur=14164, soft 36 -> 25, sustain 530 -> 14164
    db 6, 0, 84, 55, 208, 0, 25, 1  ; Note 1135: T 329.1213 G#3 = 208 Hz, tnext=6, dur=14164, soft 36 -> 25, sustain 589 -> 14164
    db 0, 0, 78, 55, 104, 0, 25, 1  ; Note 1136: T 329.1270 G#2 = 104 Hz, tnext=0, dur=14158, soft 36 -> 25, sustain 496 -> 14158
    db 80, 13, 78, 55, 165, 0, 25, 1  ; Note 1137: T 329.1270 E3 = 165 Hz, tnext=3408, dur=14158, soft 36 -> 25, sustain 563 -> 14158
    db 6, 0, 254, 41, 69, 0, 24, 1  ; Note 1138: T 332.5353 C#2 = 69 Hz, tnext=6, dur=10750, soft 35 -> 24, sustain 1142 -> 10750
    db 12, 0, 248, 41, 104, 0, 24, 1  ; Note 1139: T 332.5410 G#2 = 104 Hz, tnext=12, dur=10744, soft 35 -> 24, sustain 1187 -> 10744
    db 0, 0, 236, 41, 139, 0, 24, 1  ; Note 1140: T 332.5534 C#3 = 139 Hz, tnext=0, dur=10732, soft 35 -> 24, sustain 1202 -> 10732
    db 1, 0, 236, 41, 21, 1, 24, 1  ; Note 1141: T 332.5534 C#4 = 277 Hz, tnext=1, dur=10732, soft 35 -> 24, sustain 1302 -> 10732
    db 0, 0, 235, 41, 165, 0, 24, 1  ; Note 1142: T 332.5546 E3 = 165 Hz, tnext=0, dur=10731, soft 35 -> 24, sustain 1253 -> 10731
    db 227, 51, 235, 41, 208, 0, 24, 1  ; Note 1143: T 332.5546 G#3 = 208 Hz, tnext=13283, dur=10731, soft 35 -> 24, sustain 1269 -> 10731
; T 343.2853 Sustain 0 (Instrument 1)
; T 343.2853 Sustain 0 (Instrument 2)
    db 7, 0, 148, 1, 93, 1, 23, 1  ; Note 1144: T 345.8380 F4 = 349 Hz, tnext=7, dur=404, soft 34 -> 23
    db 11, 0, 189, 0, 159, 1, 27, 2  ; Note 1145: T 345.8448 G#4 = 415 Hz, tnext=11, dur=189, soft 39 -> 27
    db 40, 1, 28, 1, 42, 2, 27, 2  ; Note 1146: T 345.8561 C#5 = 554 Hz, tnext=296, dur=284, soft 39 -> 27
; T 345.8685 Soft 0 (Instrument 1)
; T 345.8685 Soft 0 (Instrument 2)
    db 6, 0, 5, 2, 159, 1, 43, 2  ; Note 1147: T 346.1525 G#4 = 415 Hz, tnext=6, dur=517
    db 9, 0, 25, 2, 11, 2, 43, 2  ; Note 1148: T 346.1581 C5 = 523 Hz, tnext=9, dur=537
    db 240, 1, 24, 2, 55, 1, 38, 1  ; Note 1149: T 346.1672 D#4 = 311 Hz, tnext=496, dur=536
; T 346.5259 Soft 127 (Instrument 1)
; T 346.5259 Soft 127 (Instrument 2)
    db 18, 0, 91, 1, 21, 1, 23, 1  ; Note 1150: T 346.6628 C#4 = 277 Hz, tnext=18, dur=347, soft 33 -> 23
    db 6, 0, 12, 1, 136, 1, 26, 2  ; Note 1151: T 346.6809 G4 = 392 Hz, tnext=6, dur=268, soft 38 -> 26
    db 4, 1, 54, 1, 210, 1, 26, 2  ; Note 1152: T 346.6865 A#4 = 466 Hz, tnext=260, dur=310, soft 38 -> 26
    db 16, 0, 137, 0, 159, 1, 28, 2  ; Note 1153: T 346.9467 G#4 = 415 Hz, tnext=16, dur=137, soft 41 -> 28
    db 24, 0, 129, 0, 6, 1, 25, 1  ; Note 1154: T 346.9626 C4 = 262 Hz, tnext=24, dur=129, soft 36 -> 25
    db 235, 1, 115, 0, 110, 2, 29, 2  ; Note 1155: T 346.9863 D#5 = 622 Hz, tnext=491, dur=115, soft 42 -> 29
    db 25, 0, 116, 0, 139, 0, 23, 1  ; Note 1156: T 347.4774 C#3 = 139 Hz, tnext=25, dur=116, soft 34 -> 23
    db 8, 0, 102, 0, 93, 1, 23, 1  ; Note 1157: T 347.5023 F4 = 349 Hz, tnext=8, dur=102, soft 34 -> 23
    db 11, 0, 88, 0, 233, 0, 23, 1  ; Note 1158: T 347.5102 A#3 = 233 Hz, tnext=11, dur=88, soft 34 -> 23
    db 240, 0, 114, 0, 42, 2, 28, 2  ; Note 1159: T 347.5215 C#5 = 554 Hz, tnext=240, dur=114, soft 40 -> 28
    db 28, 0, 136, 0, 159, 1, 30, 2  ; Note 1160: T 347.7613 G#4 = 415 Hz, tnext=28, dur=136, soft 43 -> 30
    db 12, 0, 102, 0, 156, 0, 26, 1  ; Note 1161: T 347.7896 D#3 = 156 Hz, tnext=12, dur=102, soft 38 -> 26
    db 5, 0, 102, 0, 55, 1, 26, 1  ; Note 1162: T 347.8021 D#4 = 311 Hz, tnext=5, dur=102, soft 38 -> 26
    db 235, 1, 69, 0, 11, 2, 30, 2  ; Note 1163: T 347.8066 C5 = 523 Hz, tnext=491, dur=69, soft 43 -> 30
    db 1, 0, 121, 0, 210, 1, 26, 2  ; Note 1164: T 348.2975 A#4 = 466 Hz, tnext=1, dur=121, soft 38 -> 26
    db 0, 0, 109, 0, 156, 0, 24, 1  ; Note 1165: T 348.2986 D#3 = 156 Hz, tnext=0, dur=109, soft 35 -> 24
    db 15, 0, 135, 0, 136, 1, 26, 2  ; Note 1166: T 348.2986 G4 = 392 Hz, tnext=15, dur=135, soft 38 -> 26
    db 251, 0, 127, 0, 21, 1, 24, 1  ; Note 1167: T 348.3133 C#4 = 277 Hz, tnext=251, dur=127, soft 35 -> 24
    db 15, 0, 176, 0, 208, 0, 23, 1  ; Note 1168: T 348.5644 G#3 = 208 Hz, tnext=15, dur=176, soft 34 -> 23
    db 3, 0, 148, 0, 6, 1, 23, 1  ; Note 1169: T 348.5791 C4 = 262 Hz, tnext=3, dur=148, soft 34 -> 23
    db 15, 2, 131, 0, 159, 1, 26, 2  ; Note 1170: T 348.5825 G#4 = 415 Hz, tnext=527, dur=131, soft 38 -> 26
; T 348.6481 Soft 0 (Instrument 1)
; T 348.6481 Soft 0 (Instrument 2)
; T 349.0846 Sustain 127 (Instrument 1)
; T 349.0846 Sustain 127 (Instrument 2)
    db 0, 0, 92, 1, 42, 2, 40, 2  ; Note 1171: T 349.1095 C#5 = 554 Hz, tnext=0, dur=348, sustain 164 -> 348
    db 12, 0, 92, 1, 210, 1, 40, 2  ; Note 1172: T 349.1095 A#4 = 466 Hz, tnext=12, dur=348, sustain 329 -> 348
    db 19, 1, 80, 1, 228, 2, 40, 2  ; Note 1173: T 349.1219 F#5 = 740 Hz, tnext=275, dur=336, sustain 277 -> 336
    db 33, 0, 49, 2, 159, 1, 43, 2  ; Note 1174: T 349.3968 G#4 = 415 Hz, tnext=33, dur=561
    db 0, 0, 16, 2, 42, 2, 44, 2  ; Note 1175: T 349.4296 C#5 = 554 Hz, tnext=0, dur=528
    db 224, 1, 30, 2, 186, 2, 44, 2  ; Note 1176: T 349.4296 F5 = 698 Hz, tnext=480, dur=542
; T 349.4578 Sustain 0 (Instrument 1)
; T 349.4578 Sustain 0 (Instrument 2)
    db 18, 0, 73, 1, 114, 1, 33, 1  ; Note 1177: T 349.9091 F#4 = 370 Hz, tnext=18, dur=329
    db 13, 0, 107, 1, 110, 2, 38, 2  ; Note 1178: T 349.9272 D#5 = 622 Hz, tnext=13, dur=363
    db 32, 1, 218, 0, 11, 2, 38, 2  ; Note 1179: T 349.9407 C5 = 523 Hz, tnext=288, dur=218
; T 350.0991 Soft 127 (Instrument 1)
; T 350.0991 Soft 127 (Instrument 2)
    db 8, 0, 88, 0, 42, 2, 29, 2  ; Note 1180: T 350.2291 C#5 = 554 Hz, tnext=8, dur=88, soft 42 -> 29
    db 5, 0, 101, 0, 93, 1, 25, 1  ; Note 1181: T 350.2371 F4 = 349 Hz, tnext=5, dur=101, soft 36 -> 25
    db 253, 1, 95, 0, 63, 3, 29, 2  ; Note 1182: T 350.2416 G#5 = 831 Hz, tnext=509, dur=95, soft 42 -> 29
    db 19, 0, 144, 0, 185, 0, 23, 1  ; Note 1183: T 350.7505 F#3 = 185 Hz, tnext=19, dur=144, soft 34 -> 23
    db 2, 0, 189, 0, 228, 2, 28, 2  ; Note 1184: T 350.7697 F#5 = 740 Hz, tnext=2, dur=189, soft 40 -> 28
    db 3, 0, 87, 0, 55, 1, 23, 1  ; Note 1185: T 350.7720 D#4 = 311 Hz, tnext=3, dur=87, soft 34 -> 23
    db 26, 1, 157, 0, 210, 1, 28, 2  ; Note 1186: T 350.7754 A#4 = 466 Hz, tnext=282, dur=157, soft 40 -> 28
    db 2, 0, 138, 0, 159, 1, 30, 2  ; Note 1187: T 351.0570 G#4 = 415 Hz, tnext=2, dur=138, soft 43 -> 30
    db 11, 0, 110, 0, 208, 0, 26, 1  ; Note 1188: T 351.0593 G#3 = 208 Hz, tnext=11, dur=110, soft 38 -> 26
    db 6, 0, 77, 0, 42, 2, 30, 2  ; Note 1189: T 351.0706 C#5 = 554 Hz, tnext=6, dur=77, soft 43 -> 30
    db 247, 1, 104, 0, 186, 2, 30, 2  ; Note 1190: T 351.0762 F5 = 698 Hz, tnext=503, dur=104, soft 43 -> 30
    db 5, 0, 94, 0, 208, 0, 23, 1  ; Note 1191: T 351.5795 G#3 = 208 Hz, tnext=5, dur=94, soft 34 -> 23
    db 5, 0, 122, 0, 114, 1, 23, 1  ; Note 1192: T 351.5840 F#4 = 370 Hz, tnext=5, dur=122, soft 34 -> 23
    db 15, 0, 89, 0, 110, 2, 26, 2  ; Note 1193: T 351.5885 D#5 = 622 Hz, tnext=15, dur=89, soft 38 -> 26
    db 248, 0, 102, 0, 11, 2, 26, 2  ; Note 1194: T 351.6032 C5 = 523 Hz, tnext=248, dur=102, soft 38 -> 26
    db 17, 0, 250, 1, 21, 1, 25, 1  ; Note 1195: T 351.8509 C#4 = 277 Hz, tnext=17, dur=506, soft 36 -> 25, sustain 147 -> 506
    db 1, 0, 233, 1, 42, 2, 26, 2  ; Note 1196: T 351.8679 C#5 = 554 Hz, tnext=1, dur=489, soft 38 -> 26, sustain 141 -> 489
    db 191, 1, 232, 1, 93, 1, 25, 1  ; Note 1197: T 351.8690 F4 = 349 Hz, tnext=447, dur=488, soft 36 -> 25, sustain 101 -> 488
; T 351.8792 Sustain 127 (Instrument 1)
; T 351.8792 Sustain 127 (Instrument 2)
    db 15, 0, 47, 1, 175, 0, 23, 1  ; Note 1198: T 352.3156 F3 = 175 Hz, tnext=15, dur=303, soft 34 -> 23
    db 25, 0, 142, 0, 208, 0, 23, 1  ; Note 1199: T 352.3303 G#3 = 208 Hz, tnext=25, dur=142, soft 34 -> 23
    db 1, 0, 245, 1, 42, 2, 37, 2  ; Note 1200: T 352.3552 C#5 = 554 Hz, tnext=1, dur=501, soft 53 -> 37
    db 239, 0, 213, 1, 21, 1, 23, 1  ; Note 1201: T 352.3563 C#4 = 277 Hz, tnext=239, dur=469, soft 34 -> 23
; T 352.3574 Sustain 0 (Instrument 1)
; T 352.3574 Sustain 0 (Instrument 2)
; T 352.4637 Soft 0 (Instrument 1)
; T 352.4637 Soft 0 (Instrument 2)
    db 2, 0, 241, 1, 156, 0, 37, 1  ; Note 1202: T 352.5948 D#3 = 156 Hz, tnext=2, dur=497
    db 245, 0, 198, 1, 208, 0, 37, 1  ; Note 1203: T 352.5971 G#3 = 208 Hz, tnext=245, dur=454
    db 5, 0, 142, 0, 6, 1, 34, 1  ; Note 1204: T 352.8424 C4 = 262 Hz, tnext=5, dur=142
    db 201, 0, 201, 0, 11, 2, 47, 2  ; Note 1205: T 352.8469 C5 = 523 Hz, tnext=201, dur=201
    db 8, 0, 218, 0, 139, 0, 37, 1  ; Note 1206: T 353.0482 C#3 = 139 Hz, tnext=8, dur=218
    db 24, 0, 190, 0, 196, 0, 37, 1  ; Note 1207: T 353.0561 G3 = 196 Hz, tnext=24, dur=190
    db 8, 0, 21, 1, 210, 1, 50, 2  ; Note 1208: T 353.0798 A#4 = 466 Hz, tnext=8, dur=277
    db 201, 0, 82, 0, 233, 0, 37, 1  ; Note 1209: T 353.0877 A#3 = 233 Hz, tnext=201, dur=82
    db 0, 0, 69, 0, 131, 0, 35, 1  ; Note 1210: T 353.2890 C3 = 131 Hz, tnext=0, dur=69
    db 40, 0, 81, 0, 6, 1, 35, 1  ; Note 1211: T 353.2890 C4 = 262 Hz, tnext=40, dur=81
    db 216, 0, 207, 0, 55, 1, 40, 1  ; Note 1212: T 353.3285 D#4 = 311 Hz, tnext=216, dur=207
    db 209, 0, 6, 1, 110, 2, 47, 2  ; Note 1213: T 353.5445 D#5 = 622 Hz, tnext=209, dur=262
    db 7, 0, 148, 0, 139, 0, 37, 1  ; Note 1214: T 353.7536 C#3 = 139 Hz, tnext=7, dur=148
    db 31, 0, 67, 0, 233, 0, 37, 1  ; Note 1215: T 353.7604 A#3 = 233 Hz, tnext=31, dur=67
    db 0, 0, 181, 0, 93, 1, 37, 1  ; Note 1216: T 353.7909 F4 = 349 Hz, tnext=0, dur=181
    db 220, 0, 37, 1, 42, 2, 50, 2  ; Note 1217: T 353.7909 C#5 = 554 Hz, tnext=220, dur=293
    db 12, 0, 74, 0, 156, 0, 34, 1  ; Note 1218: T 354.0113 D#3 = 156 Hz, tnext=12, dur=74
    db 7, 0, 4, 1, 159, 1, 47, 2  ; Note 1219: T 354.0238 G#4 = 415 Hz, tnext=7, dur=260
    db 217, 0, 80, 0, 55, 1, 34, 1  ; Note 1220: T 354.0306 D#4 = 311 Hz, tnext=217, dur=80
    db 189, 0, 224, 0, 11, 2, 45, 2  ; Note 1221: T 354.2476 C5 = 523 Hz, tnext=189, dur=224
    db 12, 0, 155, 0, 21, 1, 36, 1  ; Note 1222: T 354.4364 C#4 = 277 Hz, tnext=12, dur=155
    db 27, 0, 171, 0, 156, 0, 36, 1  ; Note 1223: T 354.4489 D#3 = 156 Hz, tnext=27, dur=171
    db 12, 0, 129, 2, 136, 1, 48, 2  ; Note 1224: T 354.4760 G4 = 392 Hz, tnext=12, dur=641, sustain 368 -> 641
    db 175, 0, 117, 2, 210, 1, 48, 2  ; Note 1225: T 354.4884 A#4 = 466 Hz, tnext=175, dur=629, sustain 502 -> 629
    db 7, 0, 197, 1, 208, 0, 35, 1  ; Note 1226: T 354.6636 G#3 = 208 Hz, tnext=7, dur=453, sustain 168 -> 453
    db 240, 0, 191, 1, 6, 1, 35, 1  ; Note 1227: T 354.6704 C4 = 262 Hz, tnext=240, dur=447, sustain 123 -> 447
; T 354.7710 Sustain 127 (Instrument 1)
; T 354.7710 Sustain 127 (Instrument 2)
    db 236, 0, 207, 0, 159, 1, 43, 2  ; Note 1228: T 354.9101 G#4 = 415 Hz, tnext=236, dur=207, sustain 159 -> 207
; T 355.1170 Sustain 0 (Instrument 1)
; T 355.1170 Sustain 0 (Instrument 2)
    db 0, 0, 112, 0, 21, 1, 34, 1  ; Note 1229: T 355.1464 C#4 = 277 Hz, tnext=0, dur=112
    db 1, 0, 182, 1, 228, 2, 49, 2  ; Note 1230: T 355.1464 F#5 = 740 Hz, tnext=1, dur=438, sustain 357 -> 438
    db 0, 0, 130, 0, 233, 0, 34, 1  ; Note 1231: T 355.1475 A#3 = 233 Hz, tnext=0, dur=130
    db 226, 0, 180, 1, 114, 1, 34, 1  ; Note 1232: T 355.1475 F#4 = 370 Hz, tnext=226, dur=436, sustain 361 -> 436
    db 8, 0, 214, 1, 208, 0, 36, 1  ; Note 1233: T 355.3736 G#3 = 208 Hz, tnext=8, dur=470
    db 199, 0, 99, 1, 21, 1, 36, 1  ; Note 1234: T 355.3815 C#4 = 277 Hz, tnext=199, dur=355
; T 355.3826 Sustain 127 (Instrument 1)
; T 355.3826 Sustain 127 (Instrument 2)
    db 7, 0, 208, 0, 186, 2, 44, 2  ; Note 1235: T 355.5805 F5 = 698 Hz, tnext=7, dur=208
; T 355.5839 Sustain 0 (Instrument 1)
; T 355.5839 Sustain 0 (Instrument 2)
    db 186, 0, 128, 0, 93, 1, 33, 1  ; Note 1236: T 355.5873 F4 = 349 Hz, tnext=186, dur=128
    db 20, 0, 181, 0, 185, 0, 35, 1  ; Note 1237: T 355.7738 F#3 = 185 Hz, tnext=20, dur=181
    db 31, 0, 160, 0, 6, 1, 35, 1  ; Note 1238: T 355.7941 C4 = 262 Hz, tnext=31, dur=160
    db 2, 0, 227, 0, 110, 2, 47, 2  ; Note 1239: T 355.8247 D#5 = 622 Hz, tnext=2, dur=227
    db 175, 0, 87, 0, 55, 1, 36, 1  ; Note 1240: T 355.8269 D#4 = 311 Hz, tnext=175, dur=87
    db 1, 0, 90, 0, 93, 1, 34, 1  ; Note 1241: T 356.0022 F4 = 349 Hz, tnext=1, dur=90
    db 34, 0, 84, 0, 175, 0, 34, 1  ; Note 1242: T 356.0033 F3 = 175 Hz, tnext=34, dur=84
    db 207, 0, 237, 0, 159, 1, 45, 2  ; Note 1243: T 356.0372 G#4 = 415 Hz, tnext=207, dur=237
    db 220, 0, 58, 1, 63, 3, 42, 2  ; Note 1244: T 356.2440 G#5 = 831 Hz, tnext=220, dur=314
    db 23, 0, 136, 0, 185, 0, 35, 1  ; Note 1245: T 356.4644 F#3 = 185 Hz, tnext=23, dur=136
    db 16, 0, 94, 0, 55, 1, 36, 1  ; Note 1246: T 356.4870 D#4 = 311 Hz, tnext=16, dur=94
    db 7, 0, 49, 1, 228, 2, 45, 2  ; Note 1247: T 356.5028 F#5 = 740 Hz, tnext=7, dur=305
    db 197, 0, 218, 0, 210, 1, 45, 2  ; Note 1248: T 356.5096 A#4 = 466 Hz, tnext=197, dur=218
    db 10, 0, 116, 0, 208, 0, 34, 1  ; Note 1249: T 356.7062 G#3 = 208 Hz, tnext=10, dur=116
    db 55, 0, 125, 0, 159, 1, 44, 2  ; Note 1250: T 356.7164 G#4 = 415 Hz, tnext=55, dur=125
    db 185, 0, 246, 0, 42, 2, 43, 2  ; Note 1251: T 356.7717 C#5 = 554 Hz, tnext=185, dur=246
    db 206, 0, 19, 1, 186, 2, 42, 2  ; Note 1252: T 356.9571 F5 = 698 Hz, tnext=206, dur=275
    db 28, 0, 227, 0, 114, 1, 33, 1  ; Note 1253: T 357.1627 F#4 = 370 Hz, tnext=28, dur=227
    db 24, 0, 227, 0, 208, 0, 33, 1  ; Note 1254: T 357.1910 G#3 = 208 Hz, tnext=24, dur=227
    db 33, 0, 194, 0, 11, 2, 46, 2  ; Note 1255: T 357.2147 C5 = 523 Hz, tnext=33, dur=194
    db 155, 0, 19, 2, 110, 2, 46, 2  ; Note 1256: T 357.2475 D#5 = 622 Hz, tnext=155, dur=531, sustain 454 -> 531
    db 6, 0, 120, 1, 21, 1, 33, 1  ; Note 1257: T 357.4023 C#4 = 277 Hz, tnext=6, dur=376, sustain 341 -> 376
    db 226, 0, 115, 1, 93, 1, 33, 1  ; Note 1258: T 357.4079 F4 = 349 Hz, tnext=226, dur=371, sustain 275 -> 371
    db 242, 0, 222, 0, 42, 2, 43, 2  ; Note 1259: T 357.6340 C#5 = 554 Hz, tnext=242, dur=222
; T 357.6430 Sustain 127 (Instrument 1)
; T 357.6430 Sustain 127 (Instrument 2)
; T 357.7786 Sustain 0 (Instrument 1)
; T 357.7786 Sustain 0 (Instrument 2)
    db 17, 0, 102, 1, 21, 1, 36, 1  ; Note 1260: T 357.8758 C#4 = 277 Hz, tnext=17, dur=358
    db 1, 0, 190, 0, 42, 2, 46, 2  ; Note 1261: T 357.8927 C#5 = 554 Hz, tnext=1, dur=190
    db 252, 0, 167, 0, 93, 1, 36, 1  ; Note 1262: T 357.8939 F4 = 349 Hz, tnext=252, dur=167, sustain 94 -> 167
; T 357.8961 Sustain 127 (Instrument 1)
; T 357.8961 Sustain 127 (Instrument 2)
; T 358.0611 Sustain 0 (Instrument 1)
; T 358.0611 Sustain 0 (Instrument 2)
    db 66, 0, 71, 2, 233, 0, 40, 1  ; Note 1263: T 358.1459 A#3 = 233 Hz, tnext=66, dur=583, sustain 528 -> 583
    db 8, 0, 6, 2, 42, 2, 56, 2  ; Note 1264: T 358.2114 C#5 = 554 Hz, tnext=8, dur=518, sustain 303 -> 518
    db 164, 1, 254, 1, 93, 1, 40, 1  ; Note 1265: T 358.2193 F4 = 349 Hz, tnext=420, dur=510, sustain 207 -> 510
; T 358.2543 Sustain 127 (Instrument 1)
; T 358.2543 Sustain 127 (Instrument 2)
    db 64, 0, 59, 1, 208, 0, 34, 1  ; Note 1266: T 358.6397 G#3 = 208 Hz, tnext=64, dur=315
    db 9, 0, 144, 0, 42, 2, 53, 2  ; Note 1267: T 358.7041 C#5 = 554 Hz, tnext=9, dur=144
    db 173, 0, 88, 0, 93, 1, 35, 1  ; Note 1268: T 358.7131 F4 = 349 Hz, tnext=173, dur=88
; T 358.7290 Sustain 0 (Instrument 1)
; T 358.7290 Sustain 0 (Instrument 2)
    db 45, 0, 216, 1, 196, 0, 37, 1  ; Note 1269: T 358.8860 G3 = 196 Hz, tnext=45, dur=472, sustain 370 -> 472
    db 9, 0, 248, 0, 42, 2, 55, 2  ; Note 1270: T 358.9312 C#5 = 554 Hz, tnext=9, dur=248
    db 22, 1, 200, 0, 55, 1, 37, 1  ; Note 1271: T 358.9403 D#4 = 311 Hz, tnext=278, dur=200
; T 359.2126 Sustain 127 (Instrument 1)
; T 359.2126 Sustain 127 (Instrument 2)
    db 18, 0, 176, 0, 208, 0, 34, 1  ; Note 1272: T 359.2183 G#3 = 208 Hz, tnext=18, dur=176
    db 9, 0, 128, 0, 11, 2, 52, 2  ; Note 1273: T 359.2364 C5 = 523 Hz, tnext=9, dur=128
    db 189, 0, 114, 0, 55, 1, 33, 1  ; Note 1274: T 359.2454 D#4 = 311 Hz, tnext=189, dur=114
; T 359.3584 Sustain 0 (Instrument 1)
; T 359.3584 Sustain 0 (Instrument 2)
    db 24, 0, 52, 1, 238, 1, 50, 2  ; Note 1275: T 359.4341 B4 = 494 Hz, tnext=24, dur=308, sustain 268 -> 308
    db 6, 0, 29, 1, 208, 0, 33, 1  ; Note 1276: T 359.4579 G#3 = 208 Hz, tnext=6, dur=285, sustain 200 -> 285
    db 36, 1, 23, 1, 55, 1, 34, 1  ; Note 1277: T 359.4635 D#4 = 311 Hz, tnext=292, dur=279, sustain 215 -> 279
; T 359.5370 Sustain 127 (Instrument 1)
; T 359.5370 Sustain 127 (Instrument 2)
; T 359.7426 Sustain 0 (Instrument 1)
; T 359.7426 Sustain 0 (Instrument 2)
    db 44, 0, 127, 2, 208, 0, 37, 1  ; Note 1278: T 359.7551 G#3 = 208 Hz, tnext=44, dur=639, sustain 507 -> 639
    db 9, 0, 83, 2, 238, 1, 54, 2  ; Note 1279: T 359.7991 B4 = 494 Hz, tnext=9, dur=595, sustain 380 -> 595
    db 205, 1, 88, 0, 55, 1, 37, 1  ; Note 1280: T 359.8082 D#4 = 311 Hz, tnext=461, dur=88
; T 359.9415 Sustain 127 (Instrument 1)
; T 359.9415 Sustain 127 (Instrument 2)
    db 2, 0, 209, 0, 238, 1, 51, 2  ; Note 1281: T 360.2692 B4 = 494 Hz, tnext=2, dur=209
    db 14, 0, 123, 0, 55, 1, 34, 1  ; Note 1282: T 360.2714 D#4 = 311 Hz, tnext=14, dur=123, sustain 81 -> 123
    db 160, 0, 190, 0, 185, 0, 34, 1  ; Note 1283: T 360.2850 F#3 = 185 Hz, tnext=160, dur=190
; T 360.3945 Sustain 0 (Instrument 1)
; T 360.3945 Sustain 0 (Instrument 2)
    db 26, 0, 119, 1, 175, 0, 36, 1  ; Note 1284: T 360.4454 F3 = 175 Hz, tnext=26, dur=375
    db 64, 0, 93, 1, 21, 1, 37, 1  ; Note 1285: T 360.4714 C#4 = 277 Hz, tnext=64, dur=349, sustain 254 -> 349
    db 223, 0, 29, 1, 238, 1, 54, 2  ; Note 1286: T 360.5357 B4 = 494 Hz, tnext=223, dur=285, sustain 209 -> 285
; T 360.5933 Sustain 127 (Instrument 1)
; T 360.5933 Sustain 127 (Instrument 2)
    db 19, 0, 148, 0, 185, 0, 35, 1  ; Note 1287: T 360.7583 F#3 = 185 Hz, tnext=19, dur=148
    db 9, 0, 189, 0, 210, 1, 51, 2  ; Note 1288: T 360.7775 A#4 = 466 Hz, tnext=9, dur=189
    db 224, 0, 139, 0, 21, 1, 34, 1  ; Note 1289: T 360.7865 C#4 = 277 Hz, tnext=224, dur=139
; T 360.8204 Sustain 0 (Instrument 1)
; T 360.8204 Sustain 0 (Instrument 2)
    db 46, 0, 47, 1, 185, 0, 33, 1  ; Note 1290: T 361.0102 F#3 = 185 Hz, tnext=46, dur=303
    db 23, 0, 32, 1, 210, 1, 48, 2  ; Note 1291: T 361.0565 A#4 = 466 Hz, tnext=23, dur=288
; T 361.0768 Sustain 127 (Instrument 1)
; T 361.0768 Sustain 127 (Instrument 2)
    db 217, 0, 230, 0, 21, 1, 33, 1  ; Note 1292: T 361.0791 C#4 = 277 Hz, tnext=217, dur=230, sustain 106 -> 230
    db 19, 0, 209, 2, 156, 0, 36, 1  ; Note 1293: T 361.2960 D#3 = 156 Hz, tnext=19, dur=721, sustain 411 -> 721
; T 361.3095 Sustain 0 (Instrument 1)
; T 361.3095 Sustain 0 (Instrument 2)
    db 64, 0, 189, 2, 208, 0, 36, 1  ; Note 1294: T 361.3152 G#3 = 208 Hz, tnext=64, dur=701, sustain 453 -> 701
    db 15, 0, 125, 2, 11, 2, 52, 2  ; Note 1295: T 361.3795 C5 = 523 Hz, tnext=15, dur=637, sustain 354 -> 637
    db 90, 2, 110, 2, 114, 1, 37, 1  ; Note 1296: T 361.3942 F#4 = 370 Hz, tnext=602, dur=622, sustain 312 -> 622
; T 361.5343 Sustain 127 (Instrument 1)
; T 361.5343 Sustain 127 (Instrument 2)
    db 6, 0, 235, 1, 42, 2, 52, 2  ; Note 1297: T 361.9963 C#5 = 554 Hz, tnext=6, dur=491
    db 1, 0, 26, 1, 93, 1, 36, 1  ; Note 1298: T 362.0020 F4 = 349 Hz, tnext=1, dur=282
    db 7, 0, 226, 1, 139, 0, 36, 1  ; Note 1299: T 362.0031 C#3 = 139 Hz, tnext=7, dur=482
    db 155, 1, 74, 1, 208, 0, 36, 1  ; Note 1300: T 362.0099 G#3 = 208 Hz, tnext=411, dur=330
; T 362.0166 Sustain 0 (Instrument 1)
; T 362.0166 Sustain 0 (Instrument 2)
    db 43, 0, 28, 6, 131, 0, 42, 1  ; Note 1301: T 362.4210 C3 = 131 Hz, tnext=43, dur=1564
    db 17, 0, 113, 5, 208, 0, 47, 1  ; Note 1302: T 362.4640 G#3 = 208 Hz, tnext=17, dur=1393, sustain 1356 -> 1393
    db 1, 0, 96, 5, 110, 2, 61, 2  ; Note 1303: T 362.4809 D#5 = 622 Hz, tnext=1, dur=1376, sustain 767 -> 1376
    db 179, 4, 95, 5, 114, 1, 50, 1  ; Note 1304: T 362.4820 F#4 = 370 Hz, tnext=1203, dur=1375, sustain 846 -> 1375
; T 362.9700 Sustain 127 (Instrument 1)
; T 362.9700 Sustain 127 (Instrument 2)
; T 363.6546 Soft 127 (Instrument 1)
; T 363.6546 Soft 127 (Instrument 2)
    db 7, 0, 185, 2, 114, 1, 25, 1  ; Note 1305: T 363.6851 F#4 = 370 Hz, tnext=7, dur=697, soft 37 -> 25
    db 26, 1, 172, 2, 55, 1, 25, 1  ; Note 1306: T 363.6918 D#4 = 311 Hz, tnext=282, dur=684, soft 37 -> 25
; T 363.8568 Sustain 0 (Instrument 1)
; T 363.8568 Sustain 0 (Instrument 2)
    db 7, 0, 138, 2, 139, 0, 23, 1  ; Note 1307: T 363.9742 C#3 = 139 Hz, tnext=7, dur=650, soft 34 -> 23
    db 64, 1, 206, 1, 208, 0, 23, 1  ; Note 1308: T 363.9810 G#3 = 208 Hz, tnext=320, dur=462, soft 34 -> 23
    db 66, 0, 164, 0, 21, 1, 23, 1  ; Note 1309: T 364.3006 C#4 = 277 Hz, tnext=66, dur=164, soft 33 -> 23
    db 235, 0, 132, 1, 93, 1, 27, 1  ; Note 1310: T 364.3661 F4 = 349 Hz, tnext=235, dur=388, soft 39 -> 27
    db 114, 0, 193, 1, 92, 0, 24, 1  ; Note 1311: T 364.6010 F#2 = 92 Hz, tnext=114, dur=449, soft 35 -> 24
    db 12, 0, 142, 1, 185, 0, 25, 1  ; Note 1312: T 364.7150 F#3 = 185 Hz, tnext=12, dur=398, soft 36 -> 25
    db 99, 0, 235, 1, 233, 0, 25, 1  ; Note 1313: T 364.7274 A#3 = 233 Hz, tnext=99, dur=491, soft 37 -> 25
    db 221, 0, 251, 0, 210, 1, 31, 2  ; Note 1314: T 364.8268 A#4 = 466 Hz, tnext=221, dur=251, soft 45 -> 31
    db 15, 0, 163, 0, 114, 1, 23, 1  ; Note 1315: T 365.0481 F#4 = 370 Hz, tnext=15, dur=163, soft 34 -> 23
    db 172, 0, 243, 1, 156, 0, 23, 1  ; Note 1316: T 365.0628 D#3 = 156 Hz, tnext=172, dur=499, soft 34 -> 23, sustain 250 -> 499
    db 20, 0, 78, 1, 104, 0, 23, 1  ; Note 1317: T 365.2344 G#2 = 104 Hz, tnext=20, dur=334, soft 34 -> 23
    db 27, 0, 100, 1, 208, 0, 24, 1  ; Note 1318: T 365.2548 G#3 = 208 Hz, tnext=27, dur=356, soft 35 -> 24
    db 8, 0, 64, 1, 93, 1, 28, 1  ; Note 1319: T 365.2819 F4 = 349 Hz, tnext=8, dur=320, soft 40 -> 28
    db 23, 1, 16, 1, 21, 1, 28, 1  ; Note 1320: T 365.2898 C#4 = 277 Hz, tnext=279, dur=272, soft 41 -> 28, sustain 260 -> 272
; T 365.3033 Sustain 127 (Instrument 1)
; T 365.3033 Sustain 127 (Instrument 2)
; T 365.5619 Sustain 0 (Instrument 1)
; T 365.5619 Sustain 0 (Instrument 2)
    db 11, 0, 94, 0, 6, 1, 27, 1  ; Note 1321: T 365.5687 C4 = 262 Hz, tnext=11, dur=94, soft 39 -> 27
    db 212, 0, 77, 0, 55, 1, 27, 1  ; Note 1322: T 365.5799 D#4 = 311 Hz, tnext=212, dur=77, soft 39 -> 27
    db 1, 0, 163, 0, 208, 0, 29, 1  ; Note 1323: T 365.7922 G#3 = 208 Hz, tnext=1, dur=163, soft 42 -> 29
    db 47, 0, 154, 0, 175, 0, 29, 1  ; Note 1324: T 365.7934 F3 = 175 Hz, tnext=47, dur=154, soft 42 -> 29
    db 10, 0, 239, 0, 21, 1, 29, 1  ; Note 1325: T 365.8408 C#4 = 277 Hz, tnext=10, dur=239, soft 42 -> 29
    db 200, 0, 140, 0, 42, 2, 33, 2  ; Note 1326: T 365.8509 C#5 = 554 Hz, tnext=200, dur=140, soft 48 -> 33
    db 6, 0, 16, 2, 156, 0, 31, 1  ; Note 1327: T 366.0508 D#3 = 156 Hz, tnext=6, dur=528, soft 45 -> 31, sustain 497 -> 528
    db 64, 0, 11, 2, 208, 0, 31, 1  ; Note 1328: T 366.0564 G#3 = 208 Hz, tnext=64, dur=523, soft 45 -> 31, sustain 466 -> 523
    db 2, 0, 202, 1, 11, 2, 38, 2  ; Note 1329: T 366.1208 C5 = 523 Hz, tnext=2, dur=458, soft 55 -> 38, sustain 373 -> 458
    db 173, 1, 200, 1, 6, 1, 30, 1  ; Note 1330: T 366.1231 C4 = 262 Hz, tnext=429, dur=456, soft 44 -> 30, sustain 366 -> 456
; T 366.2789 Sustain 127 (Instrument 1)
; T 366.2789 Sustain 127 (Instrument 2)
    db 14, 0, 34, 1, 196, 0, 27, 1  ; Note 1331: T 366.5521 G3 = 196 Hz, tnext=14, dur=290, soft 39 -> 27
    db 25, 0, 236, 0, 139, 0, 28, 1  ; Note 1332: T 366.5657 C#3 = 139 Hz, tnext=25, dur=236, soft 40 -> 28
; T 366.5792 Sustain 0 (Instrument 1)
; T 366.5792 Sustain 0 (Instrument 2)
    db 14, 0, 68, 1, 210, 1, 35, 2  ; Note 1333: T 366.5905 A#4 = 466 Hz, tnext=14, dur=324, soft 50 -> 35
    db 0, 1, 77, 0, 233, 0, 28, 1  ; Note 1334: T 366.6041 A#3 = 233 Hz, tnext=256, dur=77, soft 40 -> 28
    db 12, 0, 80, 0, 131, 0, 28, 1  ; Note 1335: T 366.8604 C3 = 131 Hz, tnext=12, dur=80, soft 41 -> 28
    db 12, 0, 108, 0, 6, 1, 28, 1  ; Note 1336: T 366.8728 C4 = 262 Hz, tnext=12, dur=108, soft 41 -> 28
    db 10, 0, 108, 0, 55, 1, 28, 1  ; Note 1337: T 366.8852 D#4 = 311 Hz, tnext=10, dur=108, soft 41 -> 28
    db 188, 1, 96, 0, 110, 2, 37, 2  ; Note 1338: T 366.8954 D#5 = 622 Hz, tnext=444, dur=96, soft 53 -> 37
    db 19, 0, 121, 0, 139, 0, 28, 1  ; Note 1339: T 367.3392 C#3 = 139 Hz, tnext=19, dur=121, soft 41 -> 28
    db 19, 0, 81, 0, 233, 0, 29, 1  ; Note 1340: T 367.3584 A#3 = 233 Hz, tnext=19, dur=81, soft 42 -> 29
    db 6, 0, 24, 1, 93, 1, 29, 1  ; Note 1341: T 367.3775 F4 = 349 Hz, tnext=6, dur=280, soft 42 -> 29
    db 213, 0, 145, 1, 42, 2, 38, 2  ; Note 1342: T 367.3832 C#5 = 554 Hz, tnext=213, dur=401, soft 55 -> 38
    db 15, 0, 116, 0, 156, 0, 31, 1  ; Note 1343: T 367.5966 D#3 = 156 Hz, tnext=15, dur=116, soft 45 -> 31
    db 11, 0, 89, 0, 55, 1, 31, 1  ; Note 1344: T 367.6113 D#4 = 311 Hz, tnext=11, dur=89, soft 45 -> 31
    db 206, 0, 228, 0, 159, 1, 36, 2  ; Note 1345: T 367.6226 G#4 = 415 Hz, tnext=206, dur=228, soft 52 -> 36
    db 200, 0, 226, 0, 11, 2, 35, 2  ; Note 1346: T 367.8281 C5 = 523 Hz, tnext=200, dur=226, soft 50 -> 35
    db 24, 0, 139, 0, 21, 1, 28, 1  ; Note 1347: T 368.0279 C#4 = 277 Hz, tnext=24, dur=139, soft 40 -> 28
    db 19, 0, 110, 0, 156, 0, 28, 1  ; Note 1348: T 368.0516 D#3 = 156 Hz, tnext=19, dur=110, soft 41 -> 28
    db 8, 0, 103, 2, 210, 1, 37, 2  ; Note 1349: T 368.0708 A#4 = 466 Hz, tnext=8, dur=615, soft 53 -> 37, sustain 471 -> 615
    db 172, 0, 95, 2, 136, 1, 37, 2  ; Note 1350: T 368.0787 G4 = 392 Hz, tnext=172, dur=607, soft 54 -> 37, sustain 276 -> 607
    db 7, 0, 180, 1, 208, 0, 29, 1  ; Note 1351: T 368.2504 G#3 = 208 Hz, tnext=7, dur=436, soft 42 -> 29, sustain 140 -> 436
    db 220, 0, 173, 1, 6, 1, 29, 1  ; Note 1352: T 368.2571 C4 = 262 Hz, tnext=220, dur=429, soft 42 -> 29, sustain 118 -> 429
; T 368.3542 Sustain 127 (Instrument 1)
; T 368.3542 Sustain 127 (Instrument 2)
    db 203, 0, 209, 0, 159, 1, 34, 2  ; Note 1353: T 368.4772 G#4 = 415 Hz, tnext=203, dur=209, soft 49 -> 34, sustain 149 -> 209
; T 368.5009 Soft 0 (Instrument 1)
; T 368.5009 Soft 0 (Instrument 2)
    db 7, 0, 248, 0, 233, 0, 40, 1  ; Note 1354: T 368.6804 A#3 = 233 Hz, tnext=7, dur=248
; T 368.6860 Sustain 0 (Instrument 1)
; T 368.6860 Sustain 0 (Instrument 2)
    db 10, 0, 141, 0, 21, 1, 40, 1  ; Note 1355: T 368.6872 C#4 = 277 Hz, tnext=10, dur=141
    db 1, 0, 196, 0, 228, 2, 50, 2  ; Note 1356: T 368.6973 F#5 = 740 Hz, tnext=1, dur=196
    db 229, 0, 202, 0, 114, 1, 40, 1  ; Note 1357: T 368.6985 F#4 = 370 Hz, tnext=229, dur=202
    db 0, 0, 117, 1, 21, 1, 43, 1  ; Note 1358: T 368.9276 C#4 = 277 Hz, tnext=0, dur=373, sustain 367 -> 373
    db 11, 0, 226, 1, 208, 0, 43, 1  ; Note 1359: T 368.9276 G#3 = 208 Hz, tnext=11, dur=482
    db 20, 0, 119, 1, 186, 2, 53, 2  ; Note 1360: T 368.9389 F5 = 698 Hz, tnext=20, dur=375
    db 146, 1, 85, 1, 93, 1, 44, 1  ; Note 1361: T 368.9592 F4 = 349 Hz, tnext=402, dur=341, sustain 315 -> 341
; T 369.0337 Sustain 127 (Instrument 1)
; T 369.0337 Sustain 127 (Instrument 2)
; T 369.3001 Sustain 0 (Instrument 1)
; T 369.3001 Sustain 0 (Instrument 2)
    db 14, 0, 222, 0, 185, 0, 44, 1  ; Note 1362: T 369.3610 F#3 = 185 Hz, tnext=14, dur=222
    db 9, 0, 120, 0, 6, 1, 45, 1  ; Note 1363: T 369.3745 C4 = 262 Hz, tnext=9, dur=120
    db 10, 0, 176, 0, 110, 2, 48, 2  ; Note 1364: T 369.3836 D#5 = 622 Hz, tnext=10, dur=176
    db 173, 0, 107, 0, 55, 1, 45, 1  ; Note 1365: T 369.3937 D#4 = 311 Hz, tnext=173, dur=107
    db 20, 0, 224, 1, 175, 0, 46, 1  ; Note 1366: T 369.5664 F3 = 175 Hz, tnext=20, dur=480, sustain 175 -> 480
    db 19, 0, 203, 1, 21, 1, 46, 1  ; Note 1367: T 369.5867 C#4 = 277 Hz, tnext=19, dur=459, sustain 209 -> 459
    db 0, 0, 184, 1, 159, 1, 58, 2  ; Note 1368: T 369.6059 G#4 = 415 Hz, tnext=0, dur=440, sustain 209 -> 440
    db 189, 1, 184, 1, 63, 3, 58, 2  ; Note 1369: T 369.6059 G#5 = 831 Hz, tnext=445, dur=440, sustain 229 -> 440
; T 369.7007 Sustain 127 (Instrument 1)
; T 369.7007 Sustain 127 (Instrument 2)
; T 370.0461 Sustain 0 (Instrument 1)
; T 370.0461 Sustain 0 (Instrument 2)
    db 8, 0, 252, 1, 228, 2, 58, 2  ; Note 1370: T 370.0506 F#5 = 740 Hz, tnext=8, dur=508, sustain 344 -> 508
    db 1, 0, 244, 1, 114, 1, 48, 1  ; Note 1371: T 370.0585 F#4 = 370 Hz, tnext=1, dur=500, sustain 324 -> 500
    db 6, 0, 108, 0, 21, 1, 49, 1  ; Note 1372: T 370.0597 C#4 = 277 Hz, tnext=6, dur=108
    db 204, 0, 155, 0, 233, 0, 49, 1  ; Note 1373: T 370.0653 A#3 = 233 Hz, tnext=204, dur=155
    db 1, 0, 56, 1, 21, 1, 51, 1  ; Note 1374: T 370.2696 C#4 = 277 Hz, tnext=1, dur=312
    db 194, 0, 166, 1, 208, 0, 51, 1  ; Note 1375: T 370.2707 G#3 = 208 Hz, tnext=194, dur=422
; T 370.2888 Sustain 127 (Instrument 1)
; T 370.2888 Sustain 127 (Instrument 2)
    db 15, 0, 134, 0, 186, 2, 63, 2  ; Note 1376: T 370.4649 F5 = 698 Hz, tnext=15, dur=134
    db 172, 0, 100, 0, 93, 1, 49, 1  ; Note 1377: T 370.4795 F4 = 349 Hz, tnext=172, dur=100
; T 370.5585 Sustain 0 (Instrument 1)
; T 370.5585 Sustain 0 (Instrument 2)
    db 14, 0, 202, 0, 185, 0, 51, 1  ; Note 1378: T 370.6511 F#3 = 185 Hz, tnext=14, dur=202
    db 9, 0, 96, 0, 6, 1, 51, 1  ; Note 1379: T 370.6646 C4 = 262 Hz, tnext=9, dur=96
    db 29, 0, 176, 0, 110, 2, 61, 2  ; Note 1380: T 370.6737 D#5 = 622 Hz, tnext=29, dur=176
    db 106, 0, 116, 0, 55, 1, 52, 1  ; Note 1381: T 370.7030 D#4 = 311 Hz, tnext=106, dur=116
    db 69, 0, 241, 1, 175, 0, 53, 1  ; Note 1382: T 370.8091 F3 = 175 Hz, tnext=69, dur=497, sustain 232 -> 497
    db 50, 0, 172, 1, 21, 1, 54, 1  ; Note 1383: T 370.8780 C#4 = 277 Hz, tnext=50, dur=428, sustain 256 -> 428
    db 8, 0, 122, 1, 63, 3, 70, 2  ; Note 1384: T 370.9276 G#5 = 831 Hz, tnext=8, dur=378, sustain 291 -> 378
    db 164, 1, 114, 1, 159, 1, 70, 2  ; Note 1385: T 370.9355 G#4 = 415 Hz, tnext=420, dur=370, sustain 271 -> 370
; T 370.9931 Sustain 127 (Instrument 1)
; T 370.9931 Sustain 127 (Instrument 2)
; T 371.3057 Sustain 0 (Instrument 1)
; T 371.3057 Sustain 0 (Instrument 2)
    db 9, 0, 48, 1, 228, 2, 70, 2  ; Note 1386: T 371.3554 F#5 = 740 Hz, tnext=9, dur=304
    db 1, 0, 17, 1, 114, 1, 53, 1  ; Note 1387: T 371.3644 F#4 = 370 Hz, tnext=1, dur=273
    db 6, 0, 133, 0, 233, 0, 53, 1  ; Note 1388: T 371.3656 A#3 = 233 Hz, tnext=6, dur=133
    db 172, 0, 95, 0, 21, 1, 54, 1  ; Note 1389: T 371.3712 C#4 = 277 Hz, tnext=172, dur=95
    db 7, 0, 27, 2, 208, 0, 56, 1  ; Note 1390: T 371.5428 G#3 = 208 Hz, tnext=7, dur=539, sustain 375 -> 539
    db 185, 0, 21, 2, 21, 1, 56, 1  ; Note 1391: T 371.5495 C#4 = 277 Hz, tnext=185, dur=533, sustain 255 -> 533
; T 371.7008 Sustain 127 (Instrument 1)
; T 371.7008 Sustain 127 (Instrument 2)
    db 6, 0, 92, 1, 186, 2, 66, 2  ; Note 1392: T 371.7346 F5 = 698 Hz, tnext=6, dur=348, sustain 255 -> 348
    db 115, 0, 86, 1, 93, 1, 58, 1  ; Note 1393: T 371.7403 F4 = 349 Hz, tnext=115, dur=342, sustain 184 -> 342
    db 73, 0, 86, 3, 196, 0, 65, 1  ; Note 1394: T 371.8554 G3 = 196 Hz, tnext=73, dur=854
    db 34, 0, 83, 2, 21, 1, 65, 1  ; Note 1395: T 371.9288 C#4 = 277 Hz, tnext=34, dur=595
    db 109, 0, 69, 2, 74, 1, 65, 1  ; Note 1396: T 371.9626 E4 = 330 Hz, tnext=109, dur=581
    db 8, 0, 100, 5, 164, 3, 70, 2  ; Note 1397: T 372.0721 A#5 = 932 Hz, tnext=8, dur=1380
    db 155, 2, 183, 4, 210, 1, 70, 2  ; Note 1398: T 372.0800 A#4 = 466 Hz, tnext=667, dur=1207
; T 372.0823 Sustain 0 (Instrument 1)
; T 372.0823 Sustain 0 (Instrument 2)
; T 372.5179 Soft 127 (Instrument 1)
; T 372.5179 Soft 127 (Instrument 2)
    db 5, 0, 64, 4, 208, 0, 32, 1  ; Note 1399: T 372.7469 G#3 = 208 Hz, tnext=5, dur=1088, soft 46 -> 32
    db 14, 0, 17, 4, 21, 1, 32, 1  ; Note 1400: T 372.7514 C#4 = 277 Hz, tnext=14, dur=1041, soft 46 -> 32
    db 139, 2, 173, 3, 93, 1, 31, 1  ; Note 1401: T 372.7650 F4 = 349 Hz, tnext=651, dur=941, soft 45 -> 31
    db 1, 0, 92, 1, 63, 3, 37, 2  ; Note 1402: T 373.4159 G#5 = 831 Hz, tnext=1, dur=348, soft 53 -> 37
    db 171, 3, 85, 1, 159, 1, 37, 2  ; Note 1403: T 373.4171 G#4 = 415 Hz, tnext=939, dur=341, soft 53 -> 37
    db 58, 0, 12, 5, 52, 0, 24, 1  ; Note 1404: T 374.3558 G#1 = 52 Hz, tnext=58, dur=1292, soft 35 -> 24
    db 133, 0, 182, 4, 104, 0, 24, 1  ; Note 1405: T 374.4133 G#2 = 104 Hz, tnext=133, dur=1206, soft 35 -> 24
    db 27, 0, 56, 4, 185, 0, 25, 1  ; Note 1406: T 374.5464 F#3 = 185 Hz, tnext=27, dur=1080, soft 37 -> 25
    db 49, 3, 77, 3, 6, 1, 25, 1  ; Note 1407: T 374.5735 C4 = 262 Hz, tnext=817, dur=845, soft 37 -> 25
    db 200, 0, 222, 0, 55, 1, 25, 1  ; Note 1408: T 375.3904 D#4 = 311 Hz, tnext=200, dur=222, soft 37 -> 25
    db 153, 0, 240, 0, 21, 1, 24, 1  ; Note 1409: T 375.5901 C#4 = 277 Hz, tnext=153, dur=240, soft 35 -> 24
    db 38, 0, 229, 2, 69, 0, 23, 1  ; Note 1410: T 375.7435 C#2 = 69 Hz, tnext=38, dur=741, soft 33 -> 23, sustain 441 -> 741
    db 120, 0, 191, 2, 104, 0, 23, 1  ; Note 1411: T 375.7819 G#2 = 104 Hz, tnext=120, dur=703, soft 34 -> 23, sustain 415 -> 703
    db 7, 0, 71, 2, 21, 1, 24, 1  ; Note 1412: T 375.9015 C#4 = 277 Hz, tnext=7, dur=583, soft 35 -> 24, sustain 334 -> 583
    db 225, 3, 64, 2, 175, 0, 24, 1  ; Note 1413: T 375.9082 F3 = 175 Hz, tnext=993, dur=576, soft 35 -> 24, sustain 274 -> 576
; T 375.9624 Sustain 127 (Instrument 1)
; T 375.9624 Sustain 127 (Instrument 2)
; T 376.0707 Soft 0 (Instrument 1)
; T 376.0707 Soft 0 (Instrument 2)
; T 376.4847 Sustain 0 (Instrument 1)
; T 376.4847 Sustain 0 (Instrument 2)
    db 10, 0, 107, 3, 21, 1, 33, 1  ; Note 1414: T 376.9009 C#4 = 277 Hz, tnext=10, dur=875, sustain 453 -> 875
    db 28, 0, 97, 3, 42, 2, 44, 2  ; Note 1415: T 376.9110 C#5 = 554 Hz, tnext=28, dur=865, sustain 268 -> 865
; T 376.9245 Sustain 127 (Instrument 1)
; T 376.9245 Sustain 127 (Instrument 2)
    db 57, 1, 69, 3, 93, 1, 33, 1  ; Note 1416: T 376.9392 F4 = 349 Hz, tnext=313, dur=837, sustain 148 -> 837
    db 11, 0, 27, 2, 233, 0, 37, 1  ; Note 1417: T 377.2527 A#3 = 233 Hz, tnext=11, dur=539
    db 1, 0, 0, 2, 42, 2, 48, 2  ; Note 1418: T 377.2640 C#5 = 554 Hz, tnext=1, dur=512, sustain 289 -> 512
    db 242, 1, 255, 1, 93, 1, 37, 1  ; Note 1419: T 377.2651 F4 = 349 Hz, tnext=498, dur=511, sustain 107 -> 511
    db 11, 0, 19, 1, 208, 0, 36, 1  ; Note 1420: T 377.7636 G#3 = 208 Hz, tnext=11, dur=275
    db 8, 0, 194, 0, 42, 2, 43, 2  ; Note 1421: T 377.7749 C#5 = 554 Hz, tnext=8, dur=194
; T 377.7760 Sustain 0 (Instrument 1)
; T 377.7760 Sustain 0 (Instrument 2)
    db 220, 0, 114, 0, 93, 1, 37, 1  ; Note 1422: T 377.7828 F4 = 349 Hz, tnext=220, dur=114
    db 44, 0, 78, 1, 196, 0, 39, 1  ; Note 1423: T 378.0027 G3 = 196 Hz, tnext=44, dur=334
    db 9, 0, 234, 0, 42, 2, 47, 2  ; Note 1424: T 378.0467 C#5 = 554 Hz, tnext=9, dur=234
    db 245, 0, 134, 0, 55, 1, 40, 1  ; Note 1425: T 378.0557 D#4 = 311 Hz, tnext=245, dur=134
    db 25, 0, 169, 0, 208, 0, 37, 1  ; Note 1426: T 378.3005 G#3 = 208 Hz, tnext=25, dur=169
    db 2, 0, 108, 0, 11, 2, 44, 2  ; Note 1427: T 378.3253 C5 = 523 Hz, tnext=2, dur=108
    db 235, 0, 154, 0, 55, 1, 37, 1  ; Note 1428: T 378.3275 D#4 = 311 Hz, tnext=235, dur=154
; T 378.5362 Sustain 127 (Instrument 1)
; T 378.5362 Sustain 127 (Instrument 2)
    db 9, 0, 111, 3, 238, 1, 41, 2  ; Note 1429: T 378.5621 B4 = 494 Hz, tnext=9, dur=879, sustain 183 -> 879
    db 20, 0, 102, 3, 208, 0, 34, 1  ; Note 1430: T 378.5711 G#3 = 208 Hz, tnext=20, dur=870, sustain 156 -> 870
    db 10, 1, 81, 3, 55, 1, 34, 1  ; Note 1431: T 378.5914 D#4 = 311 Hz, tnext=266, dur=849, sustain 121 -> 849
    db 5, 0, 71, 2, 208, 0, 37, 1  ; Note 1432: T 378.8576 G#3 = 208 Hz, tnext=5, dur=583, sustain 492 -> 583
    db 10, 0, 67, 2, 238, 1, 45, 2  ; Note 1433: T 378.8621 B4 = 494 Hz, tnext=10, dur=579, sustain 371 -> 579
    db 200, 1, 56, 2, 55, 1, 37, 1  ; Note 1434: T 378.8722 D#4 = 311 Hz, tnext=456, dur=568, sustain 351 -> 568
    db 10, 0, 237, 0, 185, 0, 33, 1  ; Note 1435: T 379.3279 F#3 = 185 Hz, tnext=10, dur=237
    db 17, 0, 203, 0, 238, 1, 40, 2  ; Note 1436: T 379.3380 B4 = 494 Hz, tnext=17, dur=203
    db 167, 0, 86, 0, 55, 1, 34, 1  ; Note 1437: T 379.3549 D#4 = 311 Hz, tnext=167, dur=86, sustain 68 -> 86
; T 379.4406 Sustain 0 (Instrument 1)
; T 379.4406 Sustain 0 (Instrument 2)
    db 6, 0, 25, 1, 21, 1, 36, 1  ; Note 1438: T 379.5218 C#4 = 277 Hz, tnext=6, dur=281
    db 77, 0, 80, 1, 175, 0, 36, 1  ; Note 1439: T 379.5275 F3 = 175 Hz, tnext=77, dur=336
    db 203, 0, 190, 0, 238, 1, 43, 2  ; Note 1440: T 379.6042 B4 = 494 Hz, tnext=203, dur=190
    db 45, 0, 176, 0, 185, 0, 34, 1  ; Note 1441: T 379.8072 F#3 = 185 Hz, tnext=45, dur=176
    db 1, 0, 176, 0, 210, 1, 42, 2  ; Note 1442: T 379.8523 A#4 = 466 Hz, tnext=1, dur=176
    db 194, 0, 154, 0, 21, 1, 34, 1  ; Note 1443: T 379.8534 C#4 = 277 Hz, tnext=194, dur=154
    db 58, 0, 19, 1, 185, 0, 33, 1  ; Note 1444: T 380.0474 F#3 = 185 Hz, tnext=58, dur=275
    db 2, 0, 38, 1, 210, 1, 45, 2  ; Note 1445: T 380.1049 A#4 = 466 Hz, tnext=2, dur=294
    db 193, 0, 107, 0, 21, 1, 34, 1  ; Note 1446: T 380.1072 C#4 = 277 Hz, tnext=193, dur=107
    db 25, 0, 221, 2, 156, 0, 36, 1  ; Note 1447: T 380.3000 D#3 = 156 Hz, tnext=25, dur=733, sustain 437 -> 733
    db 104, 0, 196, 2, 208, 0, 37, 1  ; Note 1448: T 380.3248 G#3 = 208 Hz, tnext=104, dur=708, sustain 472 -> 708
    db 22, 0, 92, 2, 11, 2, 49, 2  ; Note 1449: T 380.4286 C5 = 523 Hz, tnext=22, dur=604, sustain 308 -> 604
    db 16, 2, 70, 2, 114, 1, 38, 1  ; Note 1450: T 380.4511 F#4 = 370 Hz, tnext=528, dur=582, sustain 260 -> 582
; T 380.5368 Sustain 127 (Instrument 1)
; T 380.5368 Sustain 127 (Instrument 2)
    db 3, 0, 223, 1, 42, 2, 51, 2  ; Note 1451: T 380.9787 C#5 = 554 Hz, tnext=3, dur=479
    db 20, 0, 216, 1, 139, 0, 38, 1  ; Note 1452: T 380.9821 C#3 = 139 Hz, tnext=20, dur=472
    db 4, 0, 25, 1, 208, 0, 39, 1  ; Note 1453: T 381.0024 G#3 = 208 Hz, tnext=4, dur=281
    db 151, 1, 248, 0, 93, 1, 39, 1  ; Note 1454: T 381.0069 F4 = 349 Hz, tnext=407, dur=248
; T 381.0328 Sustain 0 (Instrument 1)
; T 381.0328 Sustain 0 (Instrument 2)
    db 38, 0, 100, 6, 131, 0, 44, 1  ; Note 1455: T 381.4139 C3 = 131 Hz, tnext=38, dur=1636
    db 26, 0, 80, 5, 208, 0, 44, 1  ; Note 1456: T 381.4522 G#3 = 208 Hz, tnext=26, dur=1360
    db 3, 0, 44, 5, 114, 1, 45, 1  ; Note 1457: T 381.4781 F#4 = 370 Hz, tnext=3, dur=1324, sustain 790 -> 1324
    db 119, 4, 40, 5, 110, 2, 64, 2  ; Note 1458: T 381.4815 D#5 = 622 Hz, tnext=1143, dur=1320, sustain 732 -> 1320
; T 382.0148 Sustain 127 (Instrument 1)
; T 382.0148 Sustain 127 (Instrument 2)
    db 7, 0, 19, 3, 114, 1, 37, 1  ; Note 1459: T 382.6246 F#4 = 370 Hz, tnext=7, dur=787
    db 133, 1, 41, 3, 55, 1, 38, 1  ; Note 1460: T 382.6314 D#4 = 311 Hz, tnext=389, dur=809
; T 382.8016 Sustain 0 (Instrument 1)
; T 382.8016 Sustain 0 (Instrument 2)
; T 382.8772 Soft 127 (Instrument 1)
; T 382.8772 Soft 127 (Instrument 2)
    db 19, 0, 187, 2, 139, 0, 23, 1  ; Note 1461: T 383.0203 C#3 = 139 Hz, tnext=19, dur=699, soft 34 -> 23
    db 70, 1, 29, 2, 208, 0, 23, 1  ; Note 1462: T 383.0395 G#3 = 208 Hz, tnext=326, dur=541, soft 34 -> 23
    db 104, 0, 174, 0, 21, 1, 23, 1  ; Note 1463: T 383.3653 C#4 = 277 Hz, tnext=104, dur=174, soft 33 -> 23
    db 255, 0, 151, 1, 93, 1, 29, 1  ; Note 1464: T 383.4690 F4 = 349 Hz, tnext=255, dur=407, soft 42 -> 29
    db 98, 0, 124, 1, 92, 0, 24, 1  ; Note 1465: T 383.7238 F#2 = 92 Hz, tnext=98, dur=380, soft 35 -> 24
    db 8, 0, 47, 2, 233, 0, 25, 1  ; Note 1466: T 383.8219 A#3 = 233 Hz, tnext=8, dur=559, soft 36 -> 25
    db 77, 0, 98, 1, 185, 0, 25, 1  ; Note 1467: T 383.8298 F#3 = 185 Hz, tnext=77, dur=354, soft 36 -> 25
    db 209, 0, 238, 0, 210, 1, 30, 2  ; Note 1468: T 383.9064 A#4 = 466 Hz, tnext=209, dur=238, soft 43 -> 30
    db 38, 0, 65, 1, 156, 0, 23, 1  ; Note 1469: T 384.1150 D#3 = 156 Hz, tnext=38, dur=321, soft 33 -> 23
    db 221, 0, 26, 1, 114, 1, 26, 1  ; Note 1470: T 384.1533 F#4 = 370 Hz, tnext=221, dur=282, soft 38 -> 26
    db 20, 0, 224, 1, 104, 0, 23, 1  ; Note 1471: T 384.3743 G#2 = 104 Hz, tnext=20, dur=480, soft 34 -> 23
    db 92, 0, 47, 2, 208, 0, 24, 1  ; Note 1472: T 384.3946 G#3 = 208 Hz, tnext=92, dur=559, soft 35 -> 24
    db 6, 0, 105, 1, 21, 1, 28, 1  ; Note 1473: T 384.4870 C#4 = 277 Hz, tnext=6, dur=361, soft 40 -> 28
    db 91, 1, 156, 1, 93, 1, 28, 1  ; Note 1474: T 384.4926 F4 = 349 Hz, tnext=347, dur=412, soft 41 -> 28
    db 6, 0, 80, 0, 6, 1, 28, 1  ; Note 1475: T 384.8397 C4 = 262 Hz, tnext=6, dur=80, soft 40 -> 28
    db 239, 0, 95, 0, 55, 1, 28, 1  ; Note 1476: T 384.8454 D#4 = 311 Hz, tnext=239, dur=95, soft 40 -> 28
    db 7, 0, 195, 0, 175, 0, 26, 1  ; Note 1477: T 385.0843 F3 = 175 Hz, tnext=7, dur=195, soft 38 -> 26
    db 52, 0, 157, 0, 208, 0, 26, 1  ; Note 1478: T 385.0910 G#3 = 208 Hz, tnext=52, dur=157, soft 38 -> 26
    db 1, 0, 34, 1, 42, 2, 28, 2  ; Note 1479: T 385.1429 C#5 = 554 Hz, tnext=1, dur=290, soft 41 -> 28
    db 228, 0, 8, 1, 21, 1, 27, 1  ; Note 1480: T 385.1440 C#4 = 277 Hz, tnext=228, dur=264, soft 39 -> 27
    db 8, 0, 99, 2, 156, 0, 29, 1  ; Note 1481: T 385.3716 D#3 = 156 Hz, tnext=8, dur=611, soft 42 -> 29, sustain 541 -> 611
    db 71, 0, 91, 2, 208, 0, 29, 1  ; Note 1482: T 385.3795 G#3 = 208 Hz, tnext=71, dur=603, soft 42 -> 29, sustain 492 -> 603
    db 8, 0, 20, 2, 11, 2, 30, 2  ; Note 1483: T 385.4505 C5 = 523 Hz, tnext=8, dur=532, soft 44 -> 30, sustain 373 -> 532
    db 189, 1, 12, 2, 6, 1, 28, 1  ; Note 1484: T 385.4584 C4 = 262 Hz, tnext=445, dur=524, soft 41 -> 28, sustain 355 -> 524
; T 385.5508 Sustain 127 (Instrument 1)
; T 385.5508 Sustain 127 (Instrument 2)
; T 385.5868 Soft 0 (Instrument 1)
; T 385.5868 Soft 0 (Instrument 2)
    db 6, 0, 176, 0, 196, 0, 35, 1  ; Note 1485: T 385.9035 G3 = 196 Hz, tnext=6, dur=176
    db 1, 0, 18, 1, 210, 1, 40, 2  ; Note 1486: T 385.9091 A#4 = 466 Hz, tnext=1, dur=274
    db 0, 0, 74, 0, 233, 0, 35, 1  ; Note 1487: T 385.9103 A#3 = 233 Hz, tnext=0, dur=74
    db 245, 0, 122, 0, 139, 0, 35, 1  ; Note 1488: T 385.9103 C#3 = 139 Hz, tnext=245, dur=122
; T 385.9824 Sustain 0 (Instrument 1)
; T 385.9824 Sustain 0 (Instrument 2)
    db 13, 0, 82, 0, 131, 0, 33, 1  ; Note 1489: T 386.1548 C3 = 131 Hz, tnext=13, dur=82
    db 25, 0, 123, 0, 6, 1, 33, 1  ; Note 1490: T 386.1683 C4 = 262 Hz, tnext=25, dur=123
    db 2, 0, 114, 0, 110, 2, 43, 2  ; Note 1491: T 386.1931 D#5 = 622 Hz, tnext=2, dur=114
    db 156, 1, 101, 0, 55, 1, 33, 1  ; Note 1492: T 386.1954 D#4 = 311 Hz, tnext=412, dur=101
    db 6, 0, 120, 0, 139, 0, 34, 1  ; Note 1493: T 386.6078 C#3 = 139 Hz, tnext=6, dur=120
    db 44, 0, 87, 0, 233, 0, 34, 1  ; Note 1494: T 386.6134 A#3 = 233 Hz, tnext=44, dur=87
    db 1, 0, 129, 1, 42, 2, 45, 2  ; Note 1495: T 386.6574 C#5 = 554 Hz, tnext=1, dur=385
    db 197, 0, 246, 0, 93, 1, 34, 1  ; Note 1496: T 386.6585 F4 = 349 Hz, tnext=197, dur=246
    db 1, 0, 96, 0, 156, 0, 37, 1  ; Note 1497: T 386.8557 D#3 = 156 Hz, tnext=1, dur=96
    db 26, 0, 101, 0, 55, 1, 37, 1  ; Note 1498: T 386.8569 D#4 = 311 Hz, tnext=26, dur=101
    db 202, 0, 24, 1, 159, 1, 42, 2  ; Note 1499: T 386.8828 G#4 = 415 Hz, tnext=202, dur=280
    db 233, 0, 12, 1, 11, 2, 40, 2  ; Note 1500: T 387.0845 C5 = 523 Hz, tnext=233, dur=268
    db 1, 0, 169, 0, 156, 0, 34, 1  ; Note 1501: T 387.3178 D#3 = 156 Hz, tnext=1, dur=169
    db 10, 0, 134, 0, 21, 1, 34, 1  ; Note 1502: T 387.3189 C#4 = 277 Hz, tnext=10, dur=134
    db 15, 0, 200, 1, 210, 1, 43, 2  ; Note 1503: T 387.3290 A#4 = 466 Hz, tnext=15, dur=456
    db 180, 0, 248, 0, 136, 1, 43, 2  ; Note 1504: T 387.3437 G4 = 392 Hz, tnext=180, dur=248
    db 14, 0, 123, 0, 6, 1, 34, 1  ; Note 1505: T 387.5240 C4 = 262 Hz, tnext=14, dur=123
    db 178, 0, 161, 0, 208, 0, 33, 1  ; Note 1506: T 387.5375 G#3 = 208 Hz, tnext=178, dur=161
    db 220, 0, 169, 0, 159, 1, 39, 2  ; Note 1507: T 387.7155 G#4 = 415 Hz, tnext=220, dur=169
    db 18, 0, 232, 0, 233, 0, 35, 1  ; Note 1508: T 387.9353 A#3 = 233 Hz, tnext=18, dur=232
    db 8, 0, 188, 0, 228, 2, 40, 2  ; Note 1509: T 387.9533 F#5 = 740 Hz, tnext=8, dur=188
    db 13, 0, 101, 0, 21, 1, 35, 1  ; Note 1510: T 387.9612 C#4 = 277 Hz, tnext=13, dur=101
    db 192, 0, 186, 0, 114, 1, 35, 1  ; Note 1511: T 387.9747 F#4 = 370 Hz, tnext=192, dur=186
    db 7, 0, 142, 1, 21, 1, 38, 1  ; Note 1512: T 388.1663 C#4 = 277 Hz, tnext=7, dur=398, sustain 379 -> 398
    db 51, 0, 172, 1, 208, 0, 38, 1  ; Note 1513: T 388.1731 G#3 = 208 Hz, tnext=51, dur=428
    db 0, 0, 84, 1, 93, 1, 38, 1  ; Note 1514: T 388.2238 F4 = 349 Hz, tnext=0, dur=340, sustain 280 -> 340
    db 129, 1, 84, 1, 186, 2, 43, 2  ; Note 1515: T 388.2238 F5 = 698 Hz, tnext=385, dur=340, sustain 314 -> 340
; T 388.2914 Sustain 127 (Instrument 1)
; T 388.2914 Sustain 127 (Instrument 2)
; T 388.5641 Sustain 0 (Instrument 1)
; T 388.5641 Sustain 0 (Instrument 2)
    db 1, 0, 149, 0, 185, 0, 38, 1  ; Note 1516: T 388.6091 F#3 = 185 Hz, tnext=1, dur=149
    db 10, 0, 115, 0, 6, 1, 38, 1  ; Note 1517: T 388.6103 C4 = 262 Hz, tnext=10, dur=115
    db 3, 0, 176, 0, 110, 2, 39, 2  ; Note 1518: T 388.6204 D#5 = 622 Hz, tnext=3, dur=176
    db 164, 0, 127, 0, 55, 1, 38, 1  ; Note 1519: T 388.6238 D#4 = 311 Hz, tnext=164, dur=127
    db 37, 0, 240, 1, 175, 0, 40, 1  ; Note 1520: T 388.7882 F3 = 175 Hz, tnext=37, dur=496, sustain 212 -> 496
    db 18, 0, 203, 1, 21, 1, 41, 1  ; Note 1521: T 388.8254 C#4 = 277 Hz, tnext=18, dur=459, sustain 200 -> 459
    db 2, 0, 185, 1, 63, 3, 47, 2  ; Note 1522: T 388.8434 G#5 = 831 Hz, tnext=2, dur=441, sustain 234 -> 441
    db 213, 1, 182, 1, 159, 1, 47, 2  ; Note 1523: T 388.8457 G#4 = 415 Hz, tnext=469, dur=438, sustain 240 -> 438
; T 388.9043 Sustain 127 (Instrument 1)
; T 388.9043 Sustain 127 (Instrument 2)
; T 389.2839 Sustain 0 (Instrument 1)
; T 389.2839 Sustain 0 (Instrument 2)
    db 12, 0, 193, 1, 114, 1, 43, 1  ; Note 1524: T 389.3143 F#4 = 370 Hz, tnext=12, dur=449, sustain 315 -> 449
    db 2, 0, 181, 1, 228, 2, 56, 2  ; Note 1525: T 389.3267 F#5 = 740 Hz, tnext=2, dur=437, sustain 316 -> 437
    db 14, 0, 154, 0, 233, 0, 43, 1  ; Note 1526: T 389.3289 A#3 = 233 Hz, tnext=14, dur=154
    db 206, 0, 101, 0, 21, 1, 44, 1  ; Note 1527: T 389.3424 C#4 = 277 Hz, tnext=206, dur=101
; T 389.5215 Sustain 127 (Instrument 1)
; T 389.5215 Sustain 127 (Instrument 2)
    db 7, 0, 20, 1, 21, 1, 46, 1  ; Note 1528: T 389.5486 C#4 = 277 Hz, tnext=7, dur=276
    db 167, 0, 147, 1, 208, 0, 46, 1  ; Note 1529: T 389.5553 G#3 = 208 Hz, tnext=167, dur=403
    db 18, 0, 127, 0, 186, 2, 53, 2  ; Note 1530: T 389.7221 F5 = 698 Hz, tnext=18, dur=127
    db 183, 0, 89, 0, 93, 1, 44, 1  ; Note 1531: T 389.7401 F4 = 349 Hz, tnext=183, dur=89
; T 389.7637 Sustain 0 (Instrument 1)
; T 389.7637 Sustain 0 (Instrument 2)
    db 0, 0, 102, 0, 6, 1, 44, 1  ; Note 1532: T 389.9226 C4 = 262 Hz, tnext=0, dur=102
    db 11, 0, 176, 0, 185, 0, 44, 1  ; Note 1533: T 389.9226 F#3 = 185 Hz, tnext=11, dur=176
    db 9, 0, 148, 0, 110, 2, 56, 2  ; Note 1534: T 389.9338 D#5 = 622 Hz, tnext=9, dur=148
    db 125, 0, 108, 0, 55, 1, 44, 1  ; Note 1535: T 389.9428 D#4 = 311 Hz, tnext=125, dur=108
    db 41, 0, 213, 0, 175, 0, 46, 1  ; Note 1536: T 390.0679 F3 = 175 Hz, tnext=41, dur=213
    db 37, 0, 212, 0, 21, 1, 47, 1  ; Note 1537: T 390.1084 C#4 = 277 Hz, tnext=37, dur=212
    db 5, 0, 18, 1, 159, 1, 66, 2  ; Note 1538: T 390.1456 G#4 = 415 Hz, tnext=5, dur=274
    db 136, 1, 0, 1, 63, 3, 67, 2  ; Note 1539: T 390.1501 G#5 = 831 Hz, tnext=392, dur=256
    db 2, 0, 49, 1, 228, 2, 66, 2  ; Note 1540: T 390.5421 F#5 = 740 Hz, tnext=2, dur=305
    db 19, 0, 107, 0, 233, 0, 52, 1  ; Note 1541: T 390.5444 A#3 = 233 Hz, tnext=19, dur=107
    db 19, 0, 94, 0, 21, 1, 52, 1  ; Note 1542: T 390.5635 C#4 = 277 Hz, tnext=19, dur=94
    db 153, 0, 21, 1, 114, 1, 53, 1  ; Note 1543: T 390.5827 F#4 = 370 Hz, tnext=153, dur=277
    db 6, 0, 245, 1, 21, 1, 55, 1  ; Note 1544: T 390.7358 C#4 = 277 Hz, tnext=6, dur=501, sustain 303 -> 501
    db 196, 0, 240, 1, 208, 0, 54, 1  ; Note 1545: T 390.7415 G#3 = 208 Hz, tnext=196, dur=496, sustain 273 -> 496
    db 14, 0, 44, 1, 186, 2, 70, 2  ; Note 1546: T 390.9375 F5 = 698 Hz, tnext=14, dur=300, sustain 258 -> 300
    db 119, 0, 30, 1, 93, 1, 52, 1  ; Note 1547: T 390.9510 F4 = 349 Hz, tnext=119, dur=286, sustain 192 -> 286
; T 390.9589 Sustain 127 (Instrument 1)
; T 390.9589 Sustain 127 (Instrument 2)
    db 71, 0, 159, 3, 196, 0, 61, 1  ; Note 1548: T 391.0704 G3 = 196 Hz, tnext=71, dur=927
    db 33, 0, 142, 2, 21, 1, 62, 1  ; Note 1549: T 391.1414 C#4 = 277 Hz, tnext=33, dur=654
    db 105, 0, 176, 2, 74, 1, 62, 1  ; Note 1550: T 391.1740 E4 = 330 Hz, tnext=105, dur=688
; T 391.2371 Sustain 0 (Instrument 1)
; T 391.2371 Sustain 0 (Instrument 2)
    db 15, 0, 112, 6, 164, 3, 80, 2  ; Note 1551: T 391.2788 A#5 = 932 Hz, tnext=15, dur=1648
    db 183, 2, 228, 5, 210, 1, 83, 2  ; Note 1552: T 391.2934 A#4 = 466 Hz, tnext=695, dur=1508
; T 391.5818 Soft 127 (Instrument 1)
; T 391.5818 Soft 127 (Instrument 2)
    db 7, 0, 66, 5, 21, 1, 38, 1  ; Note 1553: T 391.9884 C#4 = 277 Hz, tnext=7, dur=1346, soft 55 -> 38
    db 3, 0, 114, 5, 208, 0, 38, 1  ; Note 1554: T 391.9952 G#3 = 208 Hz, tnext=3, dur=1394, soft 55 -> 38
    db 97, 3, 226, 4, 93, 1, 38, 1  ; Note 1555: T 391.9986 F4 = 349 Hz, tnext=865, dur=1250, soft 55 -> 38
    db 15, 0, 168, 1, 63, 3, 35, 2  ; Note 1556: T 392.8636 G#5 = 831 Hz, tnext=15, dur=424, soft 50 -> 35
    db 179, 4, 174, 1, 159, 1, 35, 2  ; Note 1557: T 392.8782 G#4 = 415 Hz, tnext=1203, dur=430, soft 50 -> 35
    db 26, 0, 90, 6, 52, 0, 23, 1  ; Note 1558: T 394.0808 G#1 = 52 Hz, tnext=26, dur=1626, soft 34 -> 23
    db 153, 0, 207, 5, 104, 0, 24, 1  ; Note 1559: T 394.1067 G#2 = 104 Hz, tnext=153, dur=1487, soft 35 -> 24
    db 8, 0, 1, 5, 185, 0, 25, 1  ; Note 1560: T 394.2598 F#3 = 185 Hz, tnext=8, dur=1281, soft 37 -> 25
    db 198, 3, 19, 4, 6, 1, 25, 1  ; Note 1561: T 394.2677 C4 = 262 Hz, tnext=966, dur=1043, soft 37 -> 25
    db 30, 1, 57, 1, 55, 1, 26, 1  ; Note 1562: T 395.2338 D#4 = 311 Hz, tnext=286, dur=313, soft 38 -> 26
    db 185, 0, 57, 1, 21, 1, 25, 1  ; Note 1563: T 395.5198 C#4 = 277 Hz, tnext=185, dur=313, soft 36 -> 25
    db 33, 0, 209, 3, 69, 0, 23, 1  ; Note 1564: T 395.7044 C#2 = 69 Hz, tnext=33, dur=977, soft 33 -> 23
    db 189, 0, 148, 3, 104, 0, 23, 1  ; Note 1565: T 395.7371 G#2 = 104 Hz, tnext=189, dur=916, soft 33 -> 23
    db 6, 0, 202, 2, 21, 1, 24, 1  ; Note 1566: T 395.9263 C#4 = 277 Hz, tnext=6, dur=714, soft 35 -> 24
    db 215, 5, 117, 2, 175, 0, 24, 1  ; Note 1567: T 395.9319 F3 = 175 Hz, tnext=1495, dur=629, soft 35 -> 24
; T 395.9679 Soft 0 (Instrument 1)
; T 395.9679 Soft 0 (Instrument 2)
    db 5, 0, 7, 4, 175, 0, 45, 1  ; Note 1568: T 397.4269 F3 = 175 Hz, tnext=5, dur=1031, sustain 717 -> 1031
    db 164, 1, 2, 4, 93, 1, 45, 1  ; Note 1569: T 397.4314 F4 = 349 Hz, tnext=420, dur=1026, sustain 717 -> 1026
; T 397.7713 Sustain 127 (Instrument 1)
; T 397.7713 Sustain 127 (Instrument 2)
    db 12, 0, 165, 3, 69, 0, 50, 1  ; Note 1570: T 397.8512 C#2 = 69 Hz, tnext=12, dur=933
    db 152, 2, 43, 11, 104, 0, 50, 1  ; Note 1571: T 397.8636 G#2 = 104 Hz, tnext=664, dur=2859
; T 398.4579 Sustain 0 (Instrument 1)
; T 398.4579 Sustain 0 (Instrument 2)
    db 8, 0, 149, 3, 114, 1, 55, 1  ; Note 1572: T 398.5277 F#4 = 370 Hz, tnext=8, dur=917, sustain 537 -> 917
    db 16, 1, 141, 3, 185, 0, 55, 1  ; Note 1573: T 398.5355 F#3 = 185 Hz, tnext=272, dur=909, sustain 520 -> 909
; T 398.7865 Sustain 127 (Instrument 1)
; T 398.7865 Sustain 127 (Instrument 2)
    db 94, 2, 242, 3, 78, 0, 55, 1  ; Note 1574: T 398.8079 D#2 = 78 Hz, tnext=606, dur=1010, sustain 848 -> 1010
    db 5, 0, 148, 1, 55, 1, 55, 1  ; Note 1575: T 399.4135 D#4 = 311 Hz, tnext=5, dur=404, sustain 378 -> 404
    db 214, 0, 143, 1, 110, 2, 52, 2  ; Note 1576: T 399.4180 D#5 = 622 Hz, tnext=214, dur=399, sustain 391 -> 399
; T 399.4450 Sustain 0 (Instrument 1)
; T 399.4450 Sustain 0 (Instrument 2)
    db 234, 0, 94, 2, 92, 0, 55, 1  ; Note 1577: T 399.6318 F#2 = 92 Hz, tnext=234, dur=606
; T 399.6374 Sustain 127 (Instrument 1)
; T 399.6374 Sustain 127 (Instrument 2)
; T 399.8175 Sustain 0 (Instrument 1)
; T 399.8175 Sustain 0 (Instrument 2)
    db 3, 0, 117, 0, 11, 2, 46, 2  ; Note 1578: T 399.8659 C5 = 523 Hz, tnext=3, dur=117
    db 212, 0, 123, 0, 6, 1, 55, 1  ; Note 1579: T 399.8693 C4 = 262 Hz, tnext=212, dur=123
; T 400.0100 Sustain 127 (Instrument 1)
; T 400.0100 Sustain 127 (Instrument 2)
; T 400.0393 Soft 127 (Instrument 1)
; T 400.0393 Soft 127 (Instrument 2)
    db 9, 0, 122, 0, 159, 1, 30, 2  ; Note 1580: T 400.0809 G#4 = 415 Hz, tnext=9, dur=122, soft 44 -> 30, sustain 115 -> 122
    db 117, 0, 113, 0, 208, 0, 38, 1  ; Note 1581: T 400.0899 G#3 = 208 Hz, tnext=117, dur=113, soft 55 -> 38, sustain 69 -> 113
; T 400.2025 Sustain 0 (Instrument 1)
; T 400.2025 Sustain 0 (Instrument 2)
    db 93, 0, 221, 1, 87, 0, 38, 1  ; Note 1582: T 400.2070 F2 = 87 Hz, tnext=93, dur=477, soft 55 -> 38
    db 13, 0, 173, 0, 42, 2, 32, 2  ; Note 1583: T 400.3004 C#5 = 554 Hz, tnext=13, dur=173, soft 47 -> 32
    db 232, 0, 127, 0, 21, 1, 38, 1  ; Note 1584: T 400.3139 C#4 = 277 Hz, tnext=232, dur=127, soft 55 -> 38
    db 12, 0, 81, 0, 186, 2, 30, 2  ; Note 1585: T 400.5457 F5 = 698 Hz, tnext=12, dur=81, soft 44 -> 30
    db 81, 1, 69, 0, 93, 1, 38, 1  ; Note 1586: T 400.5581 F4 = 349 Hz, tnext=337, dur=69, soft 55 -> 38
    db 4, 0, 246, 2, 175, 0, 38, 1  ; Note 1587: T 400.8946 F3 = 175 Hz, tnext=4, dur=758, soft 55 -> 38, sustain 616 -> 758
    db 189, 0, 242, 2, 93, 1, 38, 1  ; Note 1588: T 400.8991 F4 = 349 Hz, tnext=189, dur=754, soft 55 -> 38, sustain 641 -> 754
; T 400.9306 Soft 0 (Instrument 1)
; T 400.9306 Soft 0 (Instrument 2)
    db 17, 0, 85, 3, 69, 0, 55, 1  ; Note 1589: T 401.0881 C#2 = 69 Hz, tnext=17, dur=853
    db 48, 2, 85, 8, 104, 0, 55, 1  ; Note 1590: T 401.1050 G#2 = 104 Hz, tnext=560, dur=2133, sustain 1937 -> 2133
; T 401.1050 Sustain 127 (Instrument 1)
; T 401.1050 Sustain 127 (Instrument 2)
; T 401.6529 Sustain 0 (Instrument 1)
; T 401.6529 Sustain 0 (Instrument 2)
    db 21, 0, 162, 3, 114, 1, 55, 1  ; Note 1591: T 401.6653 F#4 = 370 Hz, tnext=21, dur=930, sustain 544 -> 930
    db 2, 1, 141, 3, 185, 0, 55, 1  ; Note 1592: T 401.6866 F#3 = 185 Hz, tnext=258, dur=909, sustain 519 -> 909
    db 22, 2, 45, 3, 78, 0, 55, 1  ; Note 1593: T 401.9443 D#2 = 78 Hz, tnext=534, dur=813
; T 402.0118 Sustain 127 (Instrument 1)
; T 402.0118 Sustain 127 (Instrument 2)
; T 402.4157 Soft 127 (Instrument 1)
; T 402.4157 Soft 127 (Instrument 2)
    db 2, 0, 247, 2, 228, 2, 35, 2  ; Note 1594: T 402.4787 F#5 = 740 Hz, tnext=2, dur=759, soft 50 -> 35, sustain 515 -> 759
    db 253, 0, 245, 2, 114, 1, 38, 1  ; Note 1595: T 402.4810 F#4 = 370 Hz, tnext=253, dur=757, soft 55 -> 38, sustain 525 -> 757
; T 402.5957 Sustain 0 (Instrument 1)
; T 402.5957 Sustain 0 (Instrument 2)
    db 255, 0, 121, 2, 52, 0, 38, 1  ; Note 1596: T 402.7341 G#1 = 52 Hz, tnext=255, dur=633, soft 55 -> 38
    db 9, 0, 249, 0, 164, 3, 30, 2  ; Note 1597: T 402.9895 A#5 = 932 Hz, tnext=9, dur=249, soft 44 -> 30, sustain 155 -> 249
; T 402.9940 Sustain 127 (Instrument 1)
; T 402.9940 Sustain 127 (Instrument 2)
    db 239, 0, 240, 0, 210, 1, 30, 2  ; Note 1598: T 402.9985 A#4 = 466 Hz, tnext=239, dur=240, soft 44 -> 30, sustain 181 -> 240
    db 66, 0, 116, 0, 104, 0, 38, 1  ; Note 1599: T 403.2370 G#2 = 104 Hz, tnext=66, dur=116, soft 55 -> 38
; T 403.2381 Sustain 0 (Instrument 1)
; T 403.2381 Sustain 0 (Instrument 2)
    db 5, 0, 102, 0, 6, 1, 38, 1  ; Note 1600: T 403.3034 C4 = 262 Hz, tnext=5, dur=102, soft 55 -> 38
    db 129, 0, 108, 0, 11, 2, 32, 2  ; Note 1601: T 403.3079 C5 = 523 Hz, tnext=129, dur=108, soft 46 -> 32
    db 31, 0, 96, 2, 69, 0, 38, 1  ; Note 1602: T 403.4373 C#2 = 69 Hz, tnext=31, dur=608, soft 55 -> 38, sustain 428 -> 608
    db 67, 0, 64, 2, 104, 0, 38, 1  ; Note 1603: T 403.4688 G#2 = 104 Hz, tnext=67, dur=576, soft 55 -> 38, sustain 366 -> 576
    db 10, 0, 253, 1, 55, 1, 38, 1  ; Note 1604: T 403.5363 D#4 = 311 Hz, tnext=10, dur=509, soft 55 -> 38, sustain 107 -> 509
    db 207, 0, 242, 1, 110, 2, 34, 2  ; Note 1605: T 403.5464 D#5 = 622 Hz, tnext=207, dur=498, soft 49 -> 34, sustain 179 -> 498
; T 403.6274 Sustain 127 (Instrument 1)
; T 403.6274 Sustain 127 (Instrument 2)
    db 10, 0, 35, 1, 21, 1, 38, 1  ; Note 1606: T 403.7534 C#4 = 277 Hz, tnext=10, dur=291, soft 55 -> 38, sustain 109 -> 291
    db 255, 0, 25, 1, 42, 2, 32, 2  ; Note 1607: T 403.7636 C#5 = 554 Hz, tnext=255, dur=281, soft 46 -> 32, sustain 89 -> 281
; T 403.8086 Soft 0 (Instrument 1)
; T 403.8086 Soft 0 (Instrument 2)
    db 5, 0, 83, 3, 175, 0, 55, 1  ; Note 1608: T 404.0190 F3 = 175 Hz, tnext=5, dur=851, sustain 665 -> 851
    db 7, 1, 78, 3, 93, 1, 55, 1  ; Note 1609: T 404.0235 F4 = 349 Hz, tnext=263, dur=846, sustain 659 -> 846
; T 404.0448 Sustain 0 (Instrument 1)
; T 404.0448 Sustain 0 (Instrument 2)
    db 5, 0, 18, 3, 69, 0, 55, 1  ; Note 1610: T 404.2867 C#2 = 69 Hz, tnext=5, dur=786
    db 38, 2, 118, 10, 104, 0, 55, 1  ; Note 1611: T 404.2912 G#2 = 104 Hz, tnext=550, dur=2678, sustain 2474 -> 2678
; T 404.3115 Sustain 127 (Instrument 1)
; T 404.3115 Sustain 127 (Instrument 2)
    db 15, 0, 244, 2, 114, 1, 55, 1  ; Note 1612: T 404.8414 F#4 = 370 Hz, tnext=15, dur=756, sustain 461 -> 756
    db 221, 0, 229, 2, 185, 0, 55, 1  ; Note 1613: T 404.8560 F#3 = 185 Hz, tnext=221, dur=741, sustain 435 -> 741
; T 404.8695 Sustain 0 (Instrument 1)
; T 404.8695 Sustain 0 (Instrument 2)
    db 14, 2, 158, 3, 78, 0, 55, 1  ; Note 1614: T 405.0775 D#2 = 78 Hz, tnext=526, dur=926, sustain 776 -> 926
; T 405.1540 Sustain 127 (Instrument 1)
; T 405.1540 Sustain 127 (Instrument 2)
; T 405.5971 Sustain 0 (Instrument 1)
; T 405.5971 Sustain 0 (Instrument 2)
    db 11, 0, 143, 1, 55, 1, 55, 1  ; Note 1615: T 405.6039 D#4 = 311 Hz, tnext=11, dur=399, sustain 315 -> 399
    db 215, 0, 132, 1, 110, 2, 51, 2  ; Note 1616: T 405.6151 D#5 = 622 Hz, tnext=215, dur=388, sustain 307 -> 388
; T 405.8164 Sustain 127 (Instrument 1)
; T 405.8164 Sustain 127 (Instrument 2)
    db 183, 0, 47, 2, 92, 0, 55, 1  ; Note 1617: T 405.8299 F#2 = 92 Hz, tnext=183, dur=559
; T 405.9446 Soft 127 (Instrument 1)
; T 405.9446 Soft 127 (Instrument 2)
; T 406.0031 Sustain 0 (Instrument 1)
; T 406.0031 Sustain 0 (Instrument 2)
    db 9, 0, 101, 0, 11, 2, 32, 2  ; Note 1618: T 406.0132 C5 = 523 Hz, tnext=9, dur=101, soft 46 -> 32
    db 223, 0, 107, 0, 6, 1, 38, 1  ; Note 1619: T 406.0222 C4 = 262 Hz, tnext=223, dur=107, soft 55 -> 38
    db 2, 0, 116, 0, 159, 1, 30, 2  ; Note 1620: T 406.2449 G#4 = 415 Hz, tnext=2, dur=116, soft 44 -> 30
    db 111, 0, 75, 0, 208, 0, 38, 1  ; Note 1621: T 406.2471 G#3 = 208 Hz, tnext=111, dur=75, soft 55 -> 38
    db 114, 0, 99, 2, 87, 0, 38, 1  ; Note 1622: T 406.3585 F2 = 87 Hz, tnext=114, dur=611, soft 55 -> 38, sustain 406 -> 611
    db 3, 0, 81, 0, 21, 1, 38, 1  ; Note 1623: T 406.4721 C#4 = 277 Hz, tnext=3, dur=81, soft 55 -> 38
    db 192, 0, 123, 0, 42, 2, 32, 2  ; Note 1624: T 406.4755 C#5 = 554 Hz, tnext=192, dur=123, soft 47 -> 32
; T 406.6295 Sustain 127 (Instrument 1)
; T 406.6295 Sustain 127 (Instrument 2)
    db 1, 0, 45, 1, 186, 2, 31, 2  ; Note 1625: T 406.6678 F5 = 698 Hz, tnext=1, dur=301, soft 45 -> 31, sustain 76 -> 301
    db 50, 1, 44, 1, 93, 1, 38, 1  ; Note 1626: T 406.6689 F4 = 349 Hz, tnext=306, dur=300, soft 55 -> 38, sustain 75 -> 300
; T 406.7892 Soft 0 (Instrument 1)
; T 406.7892 Soft 0 (Instrument 2)
; T 406.9692 Sustain 0 (Instrument 1)
; T 406.9692 Sustain 0 (Instrument 2)
    db 11, 0, 248, 2, 175, 0, 55, 1  ; Note 1627: T 406.9748 F3 = 175 Hz, tnext=11, dur=760, sustain 593 -> 760
    db 163, 0, 237, 2, 93, 1, 55, 1  ; Note 1628: T 406.9860 F4 = 349 Hz, tnext=163, dur=749, sustain 560 -> 749
    db 17, 0, 20, 3, 69, 0, 55, 1  ; Note 1629: T 407.1491 C#2 = 69 Hz, tnext=17, dur=788
    db 11, 2, 15, 8, 104, 0, 55, 1  ; Note 1630: T 407.1660 G#2 = 104 Hz, tnext=523, dur=2063, sustain 1803 -> 2063
; T 407.2065 Sustain 127 (Instrument 1)
; T 407.2065 Sustain 127 (Instrument 2)
    db 27, 0, 20, 3, 114, 1, 55, 1  ; Note 1631: T 407.6889 F#4 = 370 Hz, tnext=27, dur=788, sustain 444 -> 788
    db 226, 0, 249, 2, 185, 0, 55, 1  ; Note 1632: T 407.7159 F#3 = 185 Hz, tnext=226, dur=761, sustain 433 -> 761
; T 407.7350 Sustain 0 (Instrument 1)
; T 407.7350 Sustain 0 (Instrument 2)
    db 1, 2, 245, 2, 78, 0, 55, 1  ; Note 1633: T 407.9420 D#2 = 78 Hz, tnext=513, dur=757
; T 407.9971 Sustain 127 (Instrument 1)
; T 407.9971 Sustain 127 (Instrument 2)
    db 1, 0, 7, 3, 228, 2, 51, 2  ; Note 1634: T 408.4548 F#5 = 740 Hz, tnext=1, dur=775, sustain 512 -> 775
    db 248, 0, 6, 3, 114, 1, 55, 1  ; Note 1635: T 408.4559 F#4 = 370 Hz, tnext=248, dur=774, sustain 490 -> 774
; T 408.4773 Sustain 0 (Instrument 1)
; T 408.4773 Sustain 0 (Instrument 2)
    db 235, 0, 91, 2, 52, 0, 55, 1  ; Note 1636: T 408.7034 G#1 = 52 Hz, tnext=235, dur=603
; T 408.9147 Sustain 127 (Instrument 1)
; T 408.9147 Sustain 127 (Instrument 2)
    db 3, 0, 35, 1, 210, 1, 45, 2  ; Note 1637: T 408.9383 A#4 = 466 Hz, tnext=3, dur=291, sustain 166 -> 291
    db 241, 0, 32, 1, 164, 3, 45, 2  ; Note 1638: T 408.9417 A#5 = 932 Hz, tnext=241, dur=288, sustain 136 -> 288
    db 58, 0, 110, 0, 104, 0, 55, 1  ; Note 1639: T 409.1823 G#2 = 104 Hz, tnext=58, dur=110
; T 409.2295 Sustain 0 (Instrument 1)
; T 409.2295 Sustain 0 (Instrument 2)
    db 16, 0, 136, 0, 11, 2, 43, 2  ; Note 1640: T 409.2408 C5 = 523 Hz, tnext=16, dur=136
    db 119, 0, 75, 0, 6, 1, 55, 1  ; Note 1641: T 409.2565 C4 = 262 Hz, tnext=119, dur=75
    db 53, 0, 9, 2, 69, 0, 55, 1  ; Note 1642: T 409.3757 C#2 = 69 Hz, tnext=53, dur=521, sustain 314 -> 521
    db 50, 0, 212, 1, 104, 0, 55, 1  ; Note 1643: T 409.4285 G#2 = 104 Hz, tnext=50, dur=468, sustain 266 -> 468
    db 2, 0, 162, 1, 110, 2, 46, 2  ; Note 1644: T 409.4780 D#5 = 622 Hz, tnext=2, dur=418, sustain 155 -> 418
    db 203, 0, 160, 1, 55, 1, 55, 1  ; Note 1645: T 409.4802 D#4 = 311 Hz, tnext=203, dur=416, sustain 120 -> 416
; T 409.4858 Sustain 127 (Instrument 1)
; T 409.4858 Sustain 127 (Instrument 2)
; T 409.6545 Soft 127 (Instrument 1)
; T 409.6545 Soft 127 (Instrument 2)
    db 11, 0, 213, 0, 21, 1, 38, 1  ; Note 1646: T 409.6837 C#4 = 277 Hz, tnext=11, dur=213, soft 55 -> 38, sustain 96 -> 213
    db 35, 1, 201, 0, 42, 2, 33, 2  ; Note 1647: T 409.6949 C#5 = 554 Hz, tnext=291, dur=201, soft 48 -> 33, sustain 115 -> 201
; T 409.8962 Sustain 0 (Instrument 1)
; T 409.8962 Sustain 0 (Instrument 2)
    db 1, 0, 96, 3, 186, 2, 36, 2  ; Note 1648: T 409.9861 F5 = 698 Hz, tnext=1, dur=864, soft 52 -> 36, sustain 572 -> 864
    db 24, 1, 95, 3, 93, 1, 38, 1  ; Note 1649: T 409.9872 F4 = 349 Hz, tnext=280, dur=863, soft 55 -> 38, sustain 579 -> 863
    db 1, 0, 254, 2, 147, 0, 38, 1  ; Note 1650: T 410.2671 D3 = 147 Hz, tnext=1, dur=766, soft 55 -> 38
    db 10, 2, 133, 2, 208, 0, 38, 1  ; Note 1651: T 410.2683 G#3 = 208 Hz, tnext=522, dur=645, soft 55 -> 38
; T 410.3413 Sustain 127 (Instrument 1)
; T 410.3413 Sustain 127 (Instrument 2)
    db 34, 0, 67, 3, 210, 1, 33, 2  ; Note 1652: T 410.7899 A#4 = 466 Hz, tnext=34, dur=835, soft 48 -> 33, sustain 815 -> 835
    db 238, 0, 34, 3, 233, 0, 38, 1  ; Note 1653: T 410.8236 A#3 = 233 Hz, tnext=238, dur=802, soft 55 -> 38, sustain 782 -> 802
; T 410.8506 Sustain 0 (Instrument 1)
; T 410.8506 Sustain 0 (Instrument 2)
    db 7, 0, 16, 3, 139, 0, 38, 1  ; Note 1654: T 411.0619 C#3 = 139 Hz, tnext=7, dur=784, soft 55 -> 38
    db 42, 2, 192, 2, 196, 0, 38, 1  ; Note 1655: T 411.0687 G3 = 196 Hz, tnext=554, dur=704, soft 55 -> 38
; T 411.2733 Sustain 127 (Instrument 1)
; T 411.2733 Sustain 127 (Instrument 2)
    db 8, 0, 28, 3, 110, 2, 31, 2  ; Note 1656: T 411.6229 D#5 = 622 Hz, tnext=8, dur=796, soft 45 -> 31, sustain 535 -> 796
; T 411.6252 Sustain 0 (Instrument 1)
; T 411.6252 Sustain 0 (Instrument 2)
    db 211, 0, 20, 3, 55, 1, 38, 1  ; Note 1657: T 411.6308 D#4 = 311 Hz, tnext=211, dur=788, soft 55 -> 38, sustain 530 -> 788
    db 5, 0, 44, 3, 185, 0, 38, 1  ; Note 1658: T 411.8421 F#3 = 185 Hz, tnext=5, dur=812, soft 55 -> 38
    db 248, 1, 45, 3, 131, 0, 38, 1  ; Note 1659: T 411.8466 C3 = 131 Hz, tnext=504, dur=813, soft 55 -> 38
; T 411.9354 Sustain 127 (Instrument 1)
; T 411.9354 Sustain 127 (Instrument 2)
    db 15, 0, 194, 3, 159, 1, 30, 2  ; Note 1660: T 412.3503 G#4 = 415 Hz, tnext=15, dur=962, soft 43 -> 30, sustain 763 -> 962
    db 253, 0, 180, 3, 208, 0, 38, 1  ; Note 1661: T 412.3649 G#3 = 208 Hz, tnext=253, dur=948, soft 55 -> 38, sustain 762 -> 948
; T 412.4188 Sustain 0 (Instrument 1)
; T 412.4188 Sustain 0 (Instrument 2)
    db 7, 0, 183, 2, 123, 0, 38, 1  ; Note 1662: T 412.6178 B2 = 123 Hz, tnext=7, dur=695, soft 55 -> 38, sustain 417 -> 695
    db 7, 2, 176, 2, 175, 0, 38, 1  ; Note 1663: T 412.6246 F3 = 175 Hz, tnext=519, dur=688, soft 55 -> 38, sustain 382 -> 688
; T 412.7909 Sustain 127 (Instrument 1)
; T 412.7909 Sustain 127 (Instrument 2)
    db 6, 0, 224, 2, 21, 1, 38, 1  ; Note 1664: T 413.1438 C#4 = 277 Hz, tnext=6, dur=736, soft 55 -> 38, sustain 497 -> 736
    db 200, 0, 219, 2, 42, 2, 29, 2  ; Note 1665: T 413.1494 C#5 = 554 Hz, tnext=200, dur=731, soft 42 -> 29, sustain 490 -> 731
; T 413.3124 Sustain 0 (Instrument 1)
; T 413.3124 Sustain 0 (Instrument 2)
    db 20, 0, 185, 4, 117, 0, 38, 1  ; Note 1666: T 413.3495 A#2 = 117 Hz, tnext=20, dur=1209, soft 55 -> 38, sustain 835 -> 1209
    db 253, 1, 224, 10, 139, 0, 38, 1  ; Note 1667: T 413.3697 C#3 = 139 Hz, tnext=509, dur=2784, soft 55 -> 38
; T 413.5439 Sustain 127 (Instrument 1)
; T 413.5439 Sustain 127 (Instrument 2)
    db 6, 0, 168, 2, 185, 0, 38, 1  ; Note 1668: T 413.8787 F#3 = 185 Hz, tnext=6, dur=680, soft 55 -> 38, sustain 598 -> 680
; T 413.8799 Sustain 0 (Instrument 1)
; T 413.8799 Sustain 0 (Instrument 2)
    db 230, 0, 162, 2, 114, 1, 38, 1  ; Note 1669: T 413.8844 F#4 = 370 Hz, tnext=230, dur=674, soft 55 -> 38, sustain 603 -> 674
    db 198, 1, 190, 2, 104, 0, 38, 1  ; Note 1670: T 414.1147 G#2 = 104 Hz, tnext=454, dur=702, soft 55 -> 38
; T 414.1653 Sustain 127 (Instrument 1)
; T 414.1653 Sustain 127 (Instrument 2)
; T 414.5586 Sustain 0 (Instrument 1)
; T 414.5586 Sustain 0 (Instrument 2)
    db 19, 0, 70, 1, 175, 0, 38, 1  ; Note 1671: T 414.5687 F3 = 175 Hz, tnext=19, dur=326, soft 55 -> 38
    db 187, 0, 58, 1, 93, 1, 38, 1  ; Note 1672: T 414.5878 F4 = 349 Hz, tnext=187, dur=314, soft 55 -> 38
    db 190, 0, 58, 1, 69, 0, 38, 1  ; Note 1673: T 414.7744 C#2 = 69 Hz, tnext=190, dur=314, soft 55 -> 38
    db 28, 0, 46, 1, 87, 0, 38, 1  ; Note 1674: T 414.9643 F2 = 87 Hz, tnext=28, dur=302, soft 55 -> 38
    db 20, 0, 76, 1, 159, 1, 30, 2  ; Note 1675: T 414.9924 G#4 = 415 Hz, tnext=20, dur=332, soft 43 -> 30
    db 237, 0, 43, 1, 208, 0, 38, 1  ; Note 1676: T 415.0126 G#3 = 208 Hz, tnext=237, dur=299, soft 55 -> 38
    db 18, 0, 51, 1, 104, 0, 38, 1  ; Note 1677: T 415.2497 G#2 = 104 Hz, tnext=18, dur=307, soft 55 -> 38
    db 15, 0, 40, 2, 238, 1, 32, 2  ; Note 1678: T 415.2677 B4 = 494 Hz, tnext=15, dur=552, soft 46 -> 32
    db 28, 1, 14, 2, 247, 0, 38, 1  ; Note 1679: T 415.2823 B3 = 247 Hz, tnext=284, dur=526, soft 55 -> 38
    db 253, 0, 24, 3, 92, 0, 38, 1  ; Note 1680: T 415.5666 F#2 = 92 Hz, tnext=253, dur=792, soft 55 -> 38
    db 14, 0, 107, 0, 233, 0, 38, 1  ; Note 1681: T 415.8194 A#3 = 233 Hz, tnext=14, dur=107, soft 55 -> 38
    db 243, 0, 234, 0, 210, 1, 28, 2  ; Note 1682: T 415.8329 A#4 = 466 Hz, tnext=243, dur=234, soft 41 -> 28
    db 2, 0, 124, 1, 42, 2, 30, 2  ; Note 1683: T 416.0756 C#5 = 554 Hz, tnext=2, dur=380, soft 44 -> 30
    db 204, 0, 117, 1, 21, 1, 38, 1  ; Note 1684: T 416.0779 C#4 = 277 Hz, tnext=204, dur=373, soft 55 -> 38
    db 47, 0, 163, 3, 117, 0, 38, 1  ; Note 1685: T 416.2824 A#2 = 117 Hz, tnext=47, dur=931, soft 55 -> 38
    db 60, 2, 150, 12, 139, 0, 38, 1  ; Note 1686: T 416.3296 C#3 = 139 Hz, tnext=572, dur=3222, soft 55 -> 38, sustain 3116 -> 3222
    db 0, 0, 69, 3, 114, 1, 38, 1  ; Note 1687: T 416.9016 F#4 = 370 Hz, tnext=0, dur=837, soft 55 -> 38, sustain 731 -> 837
    db 14, 1, 69, 3, 185, 0, 38, 1  ; Note 1688: T 416.9016 F#3 = 185 Hz, tnext=270, dur=837, soft 55 -> 38, sustain 732 -> 837
    db 26, 2, 61, 3, 104, 0, 38, 1  ; Note 1689: T 417.1712 G#2 = 104 Hz, tnext=538, dur=829, soft 55 -> 38
; T 417.3374 Sustain 127 (Instrument 1)
; T 417.3374 Sustain 127 (Instrument 2)
    db 8, 0, 125, 3, 93, 1, 38, 1  ; Note 1690: T 417.7092 F4 = 349 Hz, tnext=8, dur=893, soft 55 -> 38, sustain 728 -> 893
    db 19, 1, 117, 3, 175, 0, 38, 1  ; Note 1691: T 417.7171 F3 = 175 Hz, tnext=275, dur=885, soft 55 -> 38, sustain 713 -> 885
; T 417.7384 Sustain 0 (Instrument 1)
; T 417.7384 Sustain 0 (Instrument 2)
    db 45, 2, 116, 3, 98, 0, 38, 1  ; Note 1692: T 417.9923 G2 = 98 Hz, tnext=557, dur=884, soft 55 -> 38
; T 418.1844 Sustain 127 (Instrument 1)
; T 418.1844 Sustain 127 (Instrument 2)
    db 11, 0, 234, 3, 74, 1, 38, 1  ; Note 1693: T 418.5494 E4 = 330 Hz, tnext=11, dur=1002, soft 55 -> 38, sustain 850 -> 1002
    db 18, 1, 223, 3, 165, 0, 38, 1  ; Note 1694: T 418.5607 E3 = 165 Hz, tnext=274, dur=991, soft 55 -> 38, sustain 642 -> 991
; T 418.6022 Sustain 0 (Instrument 1)
; T 418.6022 Sustain 0 (Instrument 2)
    db 37, 2, 102, 3, 104, 0, 38, 1  ; Note 1695: T 418.8348 G#2 = 104 Hz, tnext=549, dur=870, soft 55 -> 38
; T 418.8741 Soft 0 (Instrument 1)
; T 418.8741 Soft 0 (Instrument 2)
; T 418.9482 Sustain 127 (Instrument 1)
; T 418.9482 Sustain 127 (Instrument 2)
    db 0, 0, 156, 3, 175, 0, 55, 1  ; Note 1696: T 419.3840 F3 = 175 Hz, tnext=0, dur=924, sustain 760 -> 924
    db 21, 1, 178, 3, 93, 1, 55, 1  ; Note 1697: T 419.3840 F4 = 349 Hz, tnext=277, dur=946
; T 419.5514 Sustain 0 (Instrument 1)
; T 419.5514 Sustain 0 (Instrument 2)
    db 39, 0, 120, 4, 117, 0, 55, 1  ; Note 1698: T 419.6615 A#2 = 117 Hz, tnext=39, dur=1144
    db 88, 2, 16, 6, 139, 0, 55, 1  ; Note 1699: T 419.7008 C#3 = 139 Hz, tnext=600, dur=1552
; T 420.0131 Sustain 127 (Instrument 1)
; T 420.0131 Sustain 127 (Instrument 2)
    db 29, 0, 191, 4, 114, 1, 55, 1  ; Note 1700: T 420.3007 F#4 = 370 Hz, tnext=29, dur=1215
; T 420.3085 Sustain 0 (Instrument 1)
; T 420.3085 Sustain 0 (Instrument 2)
    db 183, 1, 106, 4, 185, 0, 55, 1  ; Note 1701: T 420.3299 F#3 = 185 Hz, tnext=439, dur=1130
; T 420.7387 Soft 127 (Instrument 1)
; T 420.7387 Soft 127 (Instrument 2)
    db 194, 2, 85, 6, 104, 0, 38, 1  ; Note 1702: T 420.7691 G#2 = 104 Hz, tnext=706, dur=1621, soft 55 -> 38, sustain 1176 -> 1621
    db 58, 0, 147, 3, 175, 0, 38, 1  ; Note 1703: T 421.4754 F3 = 175 Hz, tnext=58, dur=915, soft 55 -> 38, sustain 686 -> 915
    db 94, 1, 89, 3, 93, 1, 38, 1  ; Note 1704: T 421.5338 F4 = 349 Hz, tnext=350, dur=857, soft 55 -> 38, sustain 647 -> 857
    db 0, 2, 29, 6, 52, 0, 38, 1  ; Note 1705: T 421.8841 G#1 = 52 Hz, tnext=512, dur=1565, soft 55 -> 38, sustain 1248 -> 1565
; T 421.9223 Sustain 127 (Instrument 1)
; T 421.9223 Sustain 127 (Instrument 2)
; T 422.3905 Sustain 0 (Instrument 1)
; T 422.3905 Sustain 0 (Instrument 2)
    db 1, 0, 97, 1, 114, 1, 38, 1  ; Note 1706: T 422.3961 F#4 = 370 Hz, tnext=1, dur=353, soft 55 -> 38
    db 79, 2, 92, 1, 185, 0, 38, 1  ; Note 1707: T 422.3972 F#3 = 185 Hz, tnext=591, dur=348, soft 55 -> 38
    db 7, 0, 205, 1, 6, 1, 38, 1  ; Note 1708: T 422.9879 C4 = 262 Hz, tnext=7, dur=461, soft 55 -> 38, sustain 260 -> 461
    db 19, 0, 204, 1, 104, 0, 38, 1  ; Note 1709: T 422.9946 G#2 = 104 Hz, tnext=19, dur=460, soft 55 -> 38
    db 179, 1, 180, 1, 131, 0, 38, 1  ; Note 1710: T 423.0137 C3 = 131 Hz, tnext=435, dur=436, soft 55 -> 38, sustain 242 -> 436
; T 423.0462 Sustain 127 (Instrument 1)
; T 423.0462 Sustain 127 (Instrument 2)
    db 90, 0, 117, 2, 69, 0, 38, 1  ; Note 1711: T 423.4482 C#2 = 69 Hz, tnext=90, dur=629, soft 55 -> 38, sustain 334 -> 629
; T 423.4493 Sustain 0 (Instrument 1)
; T 423.4493 Sustain 0 (Instrument 2)
    db 0, 0, 27, 2, 139, 0, 38, 1  ; Note 1712: T 423.5380 C#3 = 139 Hz, tnext=0, dur=539, soft 55 -> 38, sustain 327 -> 539
    db 237, 2, 27, 2, 21, 1, 38, 1  ; Note 1713: T 423.5380 C#4 = 277 Hz, tnext=749, dur=539, soft 55 -> 38, sustain 338 -> 539
; T 423.6885 Sustain 127 (Instrument 1)
; T 423.6885 Sustain 127 (Instrument 2)
; T 423.8457 Soft 0 (Instrument 1)
; T 423.8457 Soft 0 (Instrument 2)
; T 424.0770 Sustain 0 (Instrument 1)
; T 424.0770 Sustain 0 (Instrument 2)
    db 1, 0, 36, 3, 186, 2, 44, 2  ; Note 1714: T 424.2870 F5 = 698 Hz, tnext=1, dur=804, sustain 500 -> 804
    db 238, 0, 35, 3, 93, 1, 55, 1  ; Note 1715: T 424.2881 F4 = 349 Hz, tnext=238, dur=803, sustain 500 -> 803
    db 1, 0, 221, 2, 147, 0, 55, 1  ; Note 1716: T 424.5261 D3 = 147 Hz, tnext=1, dur=733
    db 46, 2, 142, 2, 208, 0, 55, 1  ; Note 1717: T 424.5273 G#3 = 208 Hz, tnext=558, dur=654
; T 424.6003 Sustain 127 (Instrument 1)
; T 424.6003 Sustain 127 (Instrument 2)
    db 12, 0, 2, 3, 233, 0, 55, 1  ; Note 1718: T 425.0853 A#3 = 233 Hz, tnext=12, dur=770
; T 425.0909 Sustain 0 (Instrument 1)
; T 425.0909 Sustain 0 (Instrument 2)
    db 200, 0, 246, 2, 210, 1, 41, 2  ; Note 1719: T 425.0976 A#4 = 466 Hz, tnext=200, dur=758
    db 7, 0, 21, 3, 139, 0, 55, 1  ; Note 1720: T 425.2974 C#3 = 139 Hz, tnext=7, dur=789
    db 64, 2, 232, 2, 196, 0, 55, 1  ; Note 1721: T 425.3041 G3 = 196 Hz, tnext=576, dur=744
; T 425.4949 Sustain 127 (Instrument 1)
; T 425.4949 Sustain 127 (Instrument 2)
; T 425.8216 Sustain 0 (Instrument 1)
; T 425.8216 Sustain 0 (Instrument 2)
    db 2, 0, 205, 2, 55, 1, 55, 1  ; Note 1722: T 425.8799 D#4 = 311 Hz, tnext=2, dur=717, sustain 559 -> 717
    db 222, 0, 203, 2, 110, 2, 42, 2  ; Note 1723: T 425.8822 D#5 = 622 Hz, tnext=222, dur=715, sustain 556 -> 715
    db 5, 0, 18, 3, 131, 0, 55, 1  ; Note 1724: T 426.1044 C3 = 131 Hz, tnext=5, dur=786
    db 249, 1, 1, 3, 185, 0, 55, 1  ; Note 1725: T 426.1089 F#3 = 185 Hz, tnext=505, dur=769
; T 426.2200 Sustain 127 (Instrument 1)
; T 426.2200 Sustain 127 (Instrument 2)
; T 426.5971 Sustain 0 (Instrument 1)
; T 426.5971 Sustain 0 (Instrument 2)
    db 15, 0, 29, 3, 159, 1, 42, 2  ; Note 1726: T 426.6140 G#4 = 415 Hz, tnext=15, dur=797, sustain 767 -> 797
    db 3, 1, 14, 3, 208, 0, 55, 1  ; Note 1727: T 426.6286 G#3 = 208 Hz, tnext=259, dur=782, sustain 513 -> 782
    db 13, 0, 11, 2, 123, 0, 55, 1  ; Note 1728: T 426.8878 B2 = 123 Hz, tnext=13, dur=523, sustain 441 -> 523
    db 248, 1, 254, 1, 175, 0, 55, 1  ; Note 1729: T 426.9013 F3 = 175 Hz, tnext=504, dur=510, sustain 414 -> 510
; T 427.0270 Sustain 127 (Instrument 1)
; T 427.0270 Sustain 127 (Instrument 2)
    db 10, 0, 22, 3, 21, 1, 55, 1  ; Note 1730: T 427.4053 C#4 = 277 Hz, tnext=10, dur=790, sustain 538 -> 790
; T 427.4109 Sustain 0 (Instrument 1)
; T 427.4109 Sustain 0 (Instrument 2)
    db 209, 0, 12, 3, 42, 2, 43, 2  ; Note 1731: T 427.4154 C#5 = 554 Hz, tnext=209, dur=780, sustain 518 -> 780
    db 0, 0, 32, 3, 117, 0, 55, 1  ; Note 1732: T 427.6241 A#2 = 117 Hz, tnext=0, dur=800
    db 10, 2, 65, 10, 139, 0, 55, 1  ; Note 1733: T 427.6241 C#3 = 139 Hz, tnext=522, dur=2625
; T 427.7285 Sustain 127 (Instrument 1)
; T 427.7285 Sustain 127 (Instrument 2)
    db 7, 0, 219, 2, 114, 1, 55, 1  ; Note 1734: T 428.1460 F#4 = 370 Hz, tnext=7, dur=731, sustain 625 -> 731
    db 222, 0, 212, 2, 185, 0, 55, 1  ; Note 1735: T 428.1528 F#3 = 185 Hz, tnext=222, dur=724, sustain 607 -> 724
; T 428.1954 Sustain 0 (Instrument 1)
; T 428.1954 Sustain 0 (Instrument 2)
    db 217, 1, 202, 2, 104, 0, 55, 1  ; Note 1736: T 428.3750 G#2 = 104 Hz, tnext=473, dur=714
; T 428.3761 Soft 0 (Instrument 1)
; T 428.3761 Soft 0 (Instrument 2)
; T 428.5007 Sustain 127 (Instrument 1)
; T 428.5007 Sustain 127 (Instrument 2)
    db 12, 0, 210, 1, 175, 0, 55, 1  ; Note 1737: T 428.8475 F3 = 175 Hz, tnext=12, dur=466, sustain 315 -> 466
    db 174, 0, 197, 1, 93, 1, 55, 1  ; Note 1738: T 428.8599 F4 = 349 Hz, tnext=174, dur=453, sustain 302 -> 453
; T 428.8767 Sustain 0 (Instrument 1)
; T 428.8767 Sustain 0 (Instrument 2)
    db 211, 0, 38, 1, 69, 0, 55, 1  ; Note 1739: T 429.0338 C#2 = 69 Hz, tnext=211, dur=294
; T 429.0899 Sustain 127 (Instrument 1)
; T 429.0899 Sustain 127 (Instrument 2)
    db 26, 0, 29, 1, 87, 0, 55, 1  ; Note 1740: T 429.2448 F2 = 87 Hz, tnext=26, dur=285
    db 1, 0, 38, 1, 159, 1, 40, 2  ; Note 1741: T 429.2706 G#4 = 415 Hz, tnext=1, dur=294
    db 210, 0, 167, 0, 208, 0, 55, 1  ; Note 1742: T 429.2717 G#3 = 208 Hz, tnext=210, dur=167
; T 429.3132 Sustain 0 (Instrument 1)
; T 429.3132 Sustain 0 (Instrument 2)
    db 12, 0, 49, 1, 104, 0, 55, 1  ; Note 1743: T 429.4815 G#2 = 104 Hz, tnext=12, dur=305
    db 15, 0, 243, 1, 238, 1, 42, 2  ; Note 1744: T 429.4938 B4 = 494 Hz, tnext=15, dur=499
    db 224, 0, 97, 1, 247, 0, 55, 1  ; Note 1745: T 429.5084 B3 = 247 Hz, tnext=224, dur=353
    db 212, 0, 193, 2, 92, 0, 55, 1  ; Note 1746: T 429.7328 F#2 = 92 Hz, tnext=212, dur=705
    db 7, 0, 245, 0, 210, 1, 44, 2  ; Note 1747: T 429.9449 A#4 = 466 Hz, tnext=7, dur=245
    db 5, 1, 238, 0, 233, 0, 55, 1  ; Note 1748: T 429.9516 A#3 = 233 Hz, tnext=261, dur=238
    db 1, 0, 154, 1, 42, 2, 47, 2  ; Note 1749: T 430.2130 C#5 = 554 Hz, tnext=1, dur=410
    db 171, 0, 200, 1, 21, 1, 55, 1  ; Note 1750: T 430.2141 C#4 = 277 Hz, tnext=171, dur=456
    db 58, 0, 115, 3, 117, 0, 55, 1  ; Note 1751: T 430.3847 A#2 = 117 Hz, tnext=58, dur=883
    db 251, 1, 30, 12, 139, 0, 55, 1  ; Note 1752: T 430.4430 C#3 = 139 Hz, tnext=507, dur=3102
    db 7, 0, 90, 3, 185, 0, 55, 1  ; Note 1753: T 430.9501 F#3 = 185 Hz, tnext=7, dur=858, sustain 719 -> 858
    db 7, 1, 84, 3, 114, 1, 55, 1  ; Note 1754: T 430.9568 F#4 = 370 Hz, tnext=263, dur=852, sustain 725 -> 852
    db 10, 2, 78, 3, 104, 0, 55, 1  ; Note 1755: T 431.2194 G#2 = 104 Hz, tnext=522, dur=846
; T 431.3035 Sustain 127 (Instrument 1)
; T 431.3035 Sustain 127 (Instrument 2)
    db 18, 0, 125, 3, 175, 0, 55, 1  ; Note 1756: T 431.7411 F3 = 175 Hz, tnext=18, dur=893, sustain 878 -> 893
    db 56, 1, 112, 3, 93, 1, 55, 1  ; Note 1757: T 431.7590 F4 = 349 Hz, tnext=312, dur=880
; T 431.8084 Sustain 0 (Instrument 1)
; T 431.8084 Sustain 0 (Instrument 2)
    db 36, 2, 58, 3, 98, 0, 55, 1  ; Note 1758: T 432.0709 G2 = 98 Hz, tnext=548, dur=826
; T 432.2706 Sustain 127 (Instrument 1)
; T 432.2706 Sustain 127 (Instrument 2)
    db 18, 0, 59, 3, 74, 1, 55, 1  ; Note 1759: T 432.6184 E4 = 330 Hz, tnext=18, dur=827
; T 432.6342 Sustain 0 (Instrument 1)
; T 432.6342 Sustain 0 (Instrument 2)
    db 27, 1, 53, 3, 165, 0, 55, 1  ; Note 1760: T 432.6364 E3 = 165 Hz, tnext=283, dur=821
    db 38, 2, 89, 3, 104, 0, 55, 1  ; Note 1761: T 432.9191 G#2 = 104 Hz, tnext=550, dur=857
; T 433.0538 Sustain 127 (Instrument 1)
; T 433.0538 Sustain 127 (Instrument 2)
; T 433.3924 Sustain 0 (Instrument 1)
; T 433.3924 Sustain 0 (Instrument 2)
    db 0, 0, 200, 3, 175, 0, 55, 1  ; Note 1762: T 433.4687 F3 = 175 Hz, tnext=0, dur=968, sustain 652 -> 968
    db 42, 1, 200, 3, 93, 1, 55, 1  ; Note 1763: T 433.4687 F4 = 349 Hz, tnext=298, dur=968, sustain 663 -> 968
    db 19, 0, 38, 4, 117, 0, 55, 1  ; Note 1764: T 433.7670 A#2 = 117 Hz, tnext=19, dur=1062
    db 124, 2, 158, 4, 139, 0, 55, 1  ; Note 1765: T 433.7861 C#3 = 139 Hz, tnext=636, dur=1182
; T 433.8792 Sustain 127 (Instrument 1)
; T 433.8792 Sustain 127 (Instrument 2)
; T 433.9285 Soft 127 (Instrument 1)
; T 433.9285 Soft 127 (Instrument 2)
    db 20, 0, 76, 4, 114, 1, 38, 1  ; Note 1766: T 434.4220 F#4 = 370 Hz, tnext=20, dur=1100, soft 55 -> 38
; T 434.4366 Sustain 0 (Instrument 1)
; T 434.4366 Sustain 0 (Instrument 2)
    db 121, 1, 6, 4, 185, 0, 38, 1  ; Note 1767: T 434.4422 F#3 = 185 Hz, tnext=377, dur=1030, soft 55 -> 38
    db 184, 2, 141, 5, 104, 0, 38, 1  ; Note 1768: T 434.8190 G#2 = 104 Hz, tnext=696, dur=1421, soft 55 -> 38, sustain 1095 -> 1421
    db 11, 0, 212, 2, 175, 0, 38, 1  ; Note 1769: T 435.5154 F3 = 175 Hz, tnext=11, dur=724, soft 55 -> 38, sustain 504 -> 724
    db 90, 1, 201, 2, 93, 1, 38, 1  ; Note 1770: T 435.5266 F4 = 349 Hz, tnext=346, dur=713, soft 55 -> 38, sustain 491 -> 713
    db 176, 1, 119, 6, 52, 0, 38, 1  ; Note 1771: T 435.8721 G#1 = 52 Hz, tnext=432, dur=1655, soft 55 -> 38, sustain 1260 -> 1655
; T 435.9046 Sustain 127 (Instrument 1)
; T 435.9046 Sustain 127 (Instrument 2)
; T 436.2399 Sustain 0 (Instrument 1)
; T 436.2399 Sustain 0 (Instrument 2)
    db 19, 0, 11, 2, 185, 0, 38, 1  ; Note 1772: T 436.3038 F#3 = 185 Hz, tnext=19, dur=523, soft 55 -> 38, sustain 247 -> 523
    db 226, 1, 248, 1, 114, 1, 38, 1  ; Note 1773: T 436.3229 F#4 = 370 Hz, tnext=482, dur=504, soft 55 -> 38, sustain 186 -> 504
; T 436.4900 Sustain 127 (Instrument 1)
; T 436.4900 Sustain 127 (Instrument 2)
    db 113, 0, 210, 2, 104, 0, 38, 1  ; Note 1774: T 436.8052 G#2 = 104 Hz, tnext=113, dur=722, soft 55 -> 38, sustain 451 -> 722
; T 436.8265 Sustain 0 (Instrument 1)
; T 436.8265 Sustain 0 (Instrument 2)
    db 6, 0, 97, 2, 131, 0, 38, 1  ; Note 1775: T 436.9184 C3 = 131 Hz, tnext=6, dur=609, soft 55 -> 38, sustain 267 -> 609
    db 31, 2, 91, 2, 6, 1, 38, 1  ; Note 1776: T 436.9240 C4 = 262 Hz, tnext=543, dur=603, soft 55 -> 38, sustain 214 -> 603
; T 437.0833 Sustain 127 (Instrument 1)
; T 437.0833 Sustain 127 (Instrument 2)
    db 92, 0, 128, 2, 69, 0, 38, 1  ; Note 1777: T 437.4667 C#2 = 69 Hz, tnext=92, dur=640, soft 55 -> 38, sustain 371 -> 640
; T 437.5272 Sustain 0 (Instrument 1)
; T 437.5272 Sustain 0 (Instrument 2)
    db 7, 0, 36, 2, 139, 0, 38, 1  ; Note 1778: T 437.5586 C#3 = 139 Hz, tnext=7, dur=548, soft 55 -> 38, sustain 239 -> 548
    db 23, 5, 30, 2, 21, 1, 38, 1  ; Note 1779: T 437.5653 C#4 = 277 Hz, tnext=1303, dur=542, soft 55 -> 38, sustain 331 -> 542
; T 437.7357 Sustain 127 (Instrument 1)
; T 437.7357 Sustain 127 (Instrument 2)
; T 438.1068 Sustain 0 (Instrument 1)
; T 438.1068 Sustain 0 (Instrument 2)
    db 6, 0, 182, 0, 159, 1, 28, 2  ; Note 1780: T 438.8680 G#4 = 415 Hz, tnext=6, dur=182, soft 41 -> 28
    db 20, 0, 78, 1, 93, 1, 27, 1  ; Note 1781: T 438.8736 F4 = 349 Hz, tnext=20, dur=334, soft 39 -> 27
; T 438.8814 Soft 0 (Instrument 1)
; T 438.8814 Soft 0 (Instrument 2)
    db 23, 1, 31, 1, 42, 2, 41, 2  ; Note 1782: T 438.8938 C#5 = 554 Hz, tnext=279, dur=287
    db 26, 0, 19, 2, 159, 1, 45, 2  ; Note 1783: T 439.1729 G#4 = 415 Hz, tnext=26, dur=531
    db 2, 0, 6, 2, 11, 2, 45, 2  ; Note 1784: T 439.1987 C5 = 523 Hz, tnext=2, dur=518
    db 246, 1, 25, 2, 55, 1, 43, 1  ; Note 1785: T 439.2009 D#4 = 311 Hz, tnext=502, dur=537
    db 12, 0, 31, 1, 21, 1, 40, 1  ; Note 1786: T 439.7032 C#4 = 277 Hz, tnext=12, dur=287
    db 1, 0, 64, 1, 210, 1, 43, 2  ; Note 1787: T 439.7155 A#4 = 466 Hz, tnext=1, dur=320
    db 21, 1, 192, 0, 136, 1, 43, 2  ; Note 1788: T 439.7166 G4 = 392 Hz, tnext=277, dur=192
    db 20, 0, 120, 0, 159, 1, 41, 2  ; Note 1789: T 439.9935 G#4 = 415 Hz, tnext=20, dur=120
    db 11, 0, 108, 0, 6, 1, 38, 1  ; Note 1790: T 440.0137 C4 = 262 Hz, tnext=11, dur=108
    db 236, 1, 82, 0, 110, 2, 40, 2  ; Note 1791: T 440.0249 D#5 = 622 Hz, tnext=492, dur=82
    db 8, 0, 111, 0, 42, 2, 38, 2  ; Note 1792: T 440.5170 C#5 = 554 Hz, tnext=8, dur=111
    db 6, 0, 93, 0, 139, 0, 33, 1  ; Note 1793: T 440.5249 C#3 = 139 Hz, tnext=6, dur=93
    db 1, 0, 92, 0, 93, 1, 33, 1  ; Note 1794: T 440.5305 F4 = 349 Hz, tnext=1, dur=92
    db 254, 0, 80, 0, 233, 0, 33, 1  ; Note 1795: T 440.5316 A#3 = 233 Hz, tnext=254, dur=80
    db 28, 0, 141, 0, 159, 1, 41, 2  ; Note 1796: T 440.7861 G#4 = 415 Hz, tnext=28, dur=141
    db 3, 0, 106, 0, 55, 1, 37, 1  ; Note 1797: T 440.8141 D#4 = 311 Hz, tnext=3, dur=106
    db 9, 0, 121, 0, 11, 2, 42, 2  ; Note 1798: T 440.8175 C5 = 523 Hz, tnext=9, dur=121
    db 2, 2, 106, 0, 156, 0, 37, 1  ; Note 1799: T 440.8265 D#3 = 156 Hz, tnext=514, dur=106
    db 9, 0, 109, 0, 156, 0, 34, 1  ; Note 1800: T 441.3409 D#3 = 156 Hz, tnext=9, dur=109
    db 5, 0, 133, 0, 21, 1, 34, 1  ; Note 1801: T 441.3499 C#4 = 277 Hz, tnext=5, dur=133
    db 7, 0, 148, 0, 136, 1, 40, 2  ; Note 1802: T 441.3544 G4 = 392 Hz, tnext=7, dur=148
    db 246, 0, 148, 0, 210, 1, 40, 2  ; Note 1803: T 441.3611 A#4 = 466 Hz, tnext=246, dur=148
    db 11, 0, 160, 0, 208, 0, 34, 1  ; Note 1804: T 441.6076 G#3 = 208 Hz, tnext=11, dur=160
    db 15, 0, 141, 0, 159, 1, 38, 2  ; Note 1805: T 441.6188 G#4 = 415 Hz, tnext=15, dur=141
    db 224, 1, 154, 0, 6, 1, 33, 1  ; Note 1806: T 441.6334 C4 = 262 Hz, tnext=480, dur=154
    db 0, 0, 240, 0, 228, 2, 42, 2  ; Note 1807: T 442.1130 F#5 = 740 Hz, tnext=0, dur=240
    db 7, 0, 17, 1, 210, 1, 42, 2  ; Note 1808: T 442.1130 A#4 = 466 Hz, tnext=7, dur=273
    db 14, 1, 174, 0, 42, 2, 42, 2  ; Note 1809: T 442.1197 C#5 = 554 Hz, tnext=270, dur=174
    db 7, 0, 163, 1, 42, 2, 45, 2  ; Note 1810: T 442.3898 C#5 = 554 Hz, tnext=7, dur=419
    db 7, 0, 222, 1, 186, 2, 45, 2  ; Note 1811: T 442.3965 F5 = 698 Hz, tnext=7, dur=478
    db 201, 1, 197, 1, 159, 1, 45, 2  ; Note 1812: T 442.4032 G#4 = 415 Hz, tnext=457, dur=453
    db 18, 0, 38, 1, 114, 1, 33, 1  ; Note 1813: T 442.8604 F#4 = 370 Hz, tnext=18, dur=294
    db 0, 0, 157, 0, 11, 2, 43, 2  ; Note 1814: T 442.8784 C5 = 523 Hz, tnext=0, dur=157
    db 28, 1, 44, 1, 110, 2, 43, 2  ; Note 1815: T 442.8784 D#5 = 622 Hz, tnext=284, dur=300
    db 2, 0, 137, 0, 63, 3, 44, 2  ; Note 1816: T 443.1619 G#5 = 831 Hz, tnext=2, dur=137
    db 12, 0, 75, 0, 93, 1, 33, 1  ; Note 1817: T 443.1641 F4 = 349 Hz, tnext=12, dur=75
    db 243, 1, 83, 0, 42, 2, 44, 2  ; Note 1818: T 443.1765 C#5 = 554 Hz, tnext=499, dur=83
    db 52, 0, 176, 0, 185, 0, 33, 1  ; Note 1819: T 443.6751 F#3 = 185 Hz, tnext=52, dur=176
    db 0, 0, 102, 0, 210, 1, 38, 2  ; Note 1820: T 443.7267 A#4 = 466 Hz, tnext=0, dur=102
    db 2, 0, 162, 0, 228, 2, 38, 2  ; Note 1821: T 443.7267 F#5 = 740 Hz, tnext=2, dur=162
    db 14, 1, 67, 0, 55, 1, 33, 1  ; Note 1822: T 443.7289 D#4 = 311 Hz, tnext=270, dur=67
    db 7, 0, 133, 0, 159, 1, 42, 2  ; Note 1823: T 443.9990 G#4 = 415 Hz, tnext=7, dur=133
    db 0, 0, 140, 0, 186, 2, 42, 2  ; Note 1824: T 444.0057 F5 = 698 Hz, tnext=0, dur=140
    db 2, 0, 146, 0, 42, 2, 42, 2  ; Note 1825: T 444.0057 C#5 = 554 Hz, tnext=2, dur=146
    db 226, 1, 106, 0, 208, 0, 37, 1  ; Note 1826: T 444.0079 G#3 = 208 Hz, tnext=482, dur=106
    db 25, 0, 166, 0, 208, 0, 33, 1  ; Note 1827: T 444.4898 G#3 = 208 Hz, tnext=25, dur=166
    db 4, 0, 114, 0, 114, 1, 33, 1  ; Note 1828: T 444.5145 F#4 = 370 Hz, tnext=4, dur=114
    db 1, 0, 133, 0, 110, 2, 38, 2  ; Note 1829: T 444.5189 D#5 = 622 Hz, tnext=1, dur=133
    db 252, 0, 128, 0, 11, 2, 38, 2  ; Note 1830: T 444.5201 C5 = 523 Hz, tnext=252, dur=128
    db 0, 0, 252, 1, 93, 1, 33, 1  ; Note 1831: T 444.7722 F4 = 349 Hz, tnext=0, dur=508, sustain 119 -> 508
    db 3, 0, 252, 1, 21, 1, 33, 1  ; Note 1832: T 444.7722 C#4 = 277 Hz, tnext=3, dur=508, sustain 138 -> 508
    db 234, 1, 248, 1, 42, 2, 38, 2  ; Note 1833: T 444.7756 C#5 = 554 Hz, tnext=490, dur=504, sustain 173 -> 504
; T 444.7778 Sustain 127 (Instrument 1)
; T 444.7778 Sustain 127 (Instrument 2)
    db 0, 0, 116, 0, 208, 0, 34, 1  ; Note 1834: T 445.2652 G#3 = 208 Hz, tnext=0, dur=116
    db 11, 0, 249, 0, 175, 0, 34, 1  ; Note 1835: T 445.2652 F3 = 175 Hz, tnext=11, dur=249
    db 16, 0, 204, 1, 42, 2, 45, 2  ; Note 1836: T 445.2764 C#5 = 554 Hz, tnext=16, dur=460
; T 445.2798 Sustain 0 (Instrument 1)
; T 445.2798 Sustain 0 (Instrument 2)
    db 218, 0, 164, 1, 21, 1, 34, 1  ; Note 1837: T 445.2921 C#4 = 277 Hz, tnext=218, dur=420
    db 8, 0, 222, 1, 156, 0, 37, 1  ; Note 1838: T 445.5105 D#3 = 156 Hz, tnext=8, dur=478
    db 228, 0, 162, 1, 208, 0, 37, 1  ; Note 1839: T 445.5184 G#3 = 208 Hz, tnext=228, dur=418
    db 2, 0, 187, 0, 11, 2, 42, 2  ; Note 1840: T 445.7469 C5 = 523 Hz, tnext=2, dur=187
    db 204, 0, 114, 0, 6, 1, 34, 1  ; Note 1841: T 445.7491 C4 = 262 Hz, tnext=204, dur=114
    db 13, 0, 128, 0, 139, 0, 33, 1  ; Note 1842: T 445.9530 C#3 = 139 Hz, tnext=13, dur=128
    db 11, 0, 102, 0, 196, 0, 33, 1  ; Note 1843: T 445.9664 G3 = 196 Hz, tnext=11, dur=102
    db 10, 0, 13, 1, 210, 1, 45, 2  ; Note 1844: T 445.9776 A#4 = 466 Hz, tnext=10, dur=269
    db 197, 0, 74, 0, 233, 0, 33, 1  ; Note 1845: T 445.9877 A#3 = 233 Hz, tnext=197, dur=74
; T 445.9967 Soft 127 (Instrument 1)
; T 445.9967 Soft 127 (Instrument 2)
    db 7, 0, 82, 0, 131, 0, 25, 1  ; Note 1846: T 446.1848 C3 = 131 Hz, tnext=7, dur=82, soft 36 -> 25
    db 34, 0, 82, 0, 6, 1, 25, 1  ; Note 1847: T 446.1916 C4 = 262 Hz, tnext=34, dur=82, soft 36 -> 25
    db 220, 0, 205, 0, 55, 1, 25, 1  ; Note 1848: T 446.2252 D#4 = 311 Hz, tnext=220, dur=205, soft 36 -> 25
    db 199, 0, 199, 0, 110, 2, 32, 2  ; Note 1849: T 446.4447 D#5 = 622 Hz, tnext=199, dur=199, soft 46 -> 32
    db 33, 0, 115, 0, 139, 0, 24, 1  ; Note 1850: T 446.6441 C#3 = 139 Hz, tnext=33, dur=115, soft 35 -> 24
    db 3, 0, 75, 0, 233, 0, 25, 1  ; Note 1851: T 446.6766 A#3 = 233 Hz, tnext=3, dur=75, soft 36 -> 25
    db 2, 0, 43, 1, 42, 2, 40, 2  ; Note 1852: T 446.6800 C#5 = 554 Hz, tnext=2, dur=299, soft 58 -> 40
    db 236, 0, 42, 1, 93, 1, 25, 1  ; Note 1853: T 446.6822 F4 = 349 Hz, tnext=236, dur=298, soft 36 -> 25
    db 22, 0, 84, 0, 156, 0, 27, 1  ; Note 1854: T 446.9185 D#3 = 156 Hz, tnext=22, dur=84, soft 39 -> 27
    db 17, 0, 105, 0, 55, 1, 27, 1  ; Note 1855: T 446.9409 D#4 = 311 Hz, tnext=17, dur=105, soft 39 -> 27
    db 204, 0, 240, 0, 159, 1, 26, 2  ; Note 1856: T 446.9577 G#4 = 415 Hz, tnext=204, dur=240, soft 38 -> 26
    db 187, 0, 180, 0, 11, 2, 28, 2  ; Note 1857: T 447.1616 C5 = 523 Hz, tnext=187, dur=180, soft 41 -> 28
    db 1, 0, 161, 0, 156, 0, 23, 1  ; Note 1858: T 447.3487 D#3 = 156 Hz, tnext=1, dur=161, soft 34 -> 23
    db 43, 0, 127, 0, 21, 1, 23, 1  ; Note 1859: T 447.3498 C#4 = 277 Hz, tnext=43, dur=127, soft 34 -> 23
    db 1, 0, 112, 2, 210, 1, 30, 2  ; Note 1860: T 447.3924 A#4 = 466 Hz, tnext=1, dur=624, soft 44 -> 30, sustain 462 -> 624
    db 187, 0, 39, 1, 136, 1, 30, 2  ; Note 1861: T 447.3935 G4 = 392 Hz, tnext=187, dur=295, soft 44 -> 30
    db 6, 0, 180, 1, 6, 1, 23, 1  ; Note 1862: T 447.5806 C4 = 262 Hz, tnext=6, dur=436, soft 33 -> 23, sustain 168 -> 436
    db 206, 0, 174, 1, 208, 0, 23, 1  ; Note 1863: T 447.5862 G#3 = 208 Hz, tnext=206, dur=430, soft 33 -> 23, sustain 203 -> 430
; T 447.7060 Sustain 127 (Instrument 1)
; T 447.7060 Sustain 127 (Instrument 2)
    db 225, 0, 224, 0, 159, 1, 29, 2  ; Note 1864: T 447.7923 G#4 = 415 Hz, tnext=225, dur=224, soft 42 -> 29, sustain 179 -> 224
; T 448.0163 Sustain 0 (Instrument 1)
; T 448.0163 Sustain 0 (Instrument 2)
    db 0, 0, 133, 0, 21, 1, 25, 1  ; Note 1865: T 448.0174 C#4 = 277 Hz, tnext=0, dur=133, soft 36 -> 25
    db 19, 0, 140, 0, 233, 0, 25, 1  ; Note 1866: T 448.0174 A#3 = 233 Hz, tnext=19, dur=140, soft 36 -> 25
    db 4, 0, 120, 1, 114, 1, 25, 1  ; Note 1867: T 448.0365 F#4 = 370 Hz, tnext=4, dur=376, soft 36 -> 25
    db 199, 0, 90, 1, 228, 2, 36, 2  ; Note 1868: T 448.0409 F#5 = 740 Hz, tnext=199, dur=346, soft 52 -> 36
    db 7, 0, 114, 1, 21, 1, 26, 1  ; Note 1869: T 448.2403 C#4 = 277 Hz, tnext=7, dur=370, soft 38 -> 26
    db 205, 0, 148, 1, 208, 0, 26, 1  ; Note 1870: T 448.2470 G#3 = 208 Hz, tnext=205, dur=404, soft 38 -> 26
    db 6, 0, 171, 0, 186, 2, 34, 2  ; Note 1871: T 448.4520 F5 = 698 Hz, tnext=6, dur=171, soft 49 -> 34
    db 203, 0, 139, 0, 93, 1, 25, 1  ; Note 1872: T 448.4576 F4 = 349 Hz, tnext=203, dur=139, soft 37 -> 25
    db 0, 0, 160, 0, 6, 1, 27, 1  ; Note 1873: T 448.6604 C4 = 262 Hz, tnext=0, dur=160, soft 39 -> 27
    db 30, 0, 187, 0, 185, 0, 27, 1  ; Note 1874: T 448.6604 F#3 = 185 Hz, tnext=30, dur=187, soft 39 -> 27
    db 16, 0, 199, 0, 110, 2, 36, 2  ; Note 1875: T 448.6906 D#5 = 622 Hz, tnext=16, dur=199, soft 52 -> 36
    db 124, 0, 82, 0, 55, 1, 28, 1  ; Note 1876: T 448.7063 D#4 = 311 Hz, tnext=124, dur=82, soft 40 -> 28
    db 34, 0, 75, 0, 175, 0, 26, 1  ; Note 1877: T 448.8306 F3 = 175 Hz, tnext=34, dur=75, soft 38 -> 26
    db 31, 0, 78, 0, 93, 1, 26, 1  ; Note 1878: T 448.8642 F4 = 349 Hz, tnext=31, dur=78, soft 38 -> 26
    db 207, 0, 232, 0, 159, 1, 35, 2  ; Note 1879: T 448.8956 G#4 = 415 Hz, tnext=207, dur=232, soft 50 -> 35
    db 208, 0, 5, 1, 63, 3, 35, 2  ; Note 1880: T 449.1028 G#5 = 831 Hz, tnext=208, dur=261, soft 50 -> 35
    db 22, 0, 110, 0, 185, 0, 25, 1  ; Note 1881: T 449.3111 F#3 = 185 Hz, tnext=22, dur=110, soft 36 -> 25
    db 15, 0, 65, 1, 228, 2, 37, 2  ; Note 1882: T 449.3335 F#5 = 740 Hz, tnext=15, dur=321, soft 53 -> 37
    db 2, 0, 214, 0, 210, 1, 37, 2  ; Note 1883: T 449.3481 A#4 = 466 Hz, tnext=2, dur=214, soft 53 -> 37
    db 218, 0, 82, 0, 55, 1, 25, 1  ; Note 1884: T 449.3503 D#4 = 311 Hz, tnext=218, dur=82, soft 37 -> 25
    db 1, 0, 113, 0, 159, 1, 26, 2  ; Note 1885: T 449.5687 G#4 = 415 Hz, tnext=1, dur=113, soft 38 -> 26
    db 22, 0, 122, 0, 208, 0, 28, 1  ; Note 1886: T 449.5698 G#3 = 208 Hz, tnext=22, dur=122, soft 40 -> 28
    db 186, 0, 236, 0, 42, 2, 26, 2  ; Note 1887: T 449.5922 C#5 = 554 Hz, tnext=186, dur=236, soft 38 -> 26
    db 240, 0, 248, 0, 186, 2, 28, 2  ; Note 1888: T 449.7780 F5 = 698 Hz, tnext=240, dur=248, soft 41 -> 28
    db 7, 0, 212, 0, 208, 0, 25, 1  ; Note 1889: T 450.0177 G#3 = 208 Hz, tnext=7, dur=212, soft 36 -> 25
    db 16, 0, 190, 0, 114, 1, 25, 1  ; Note 1890: T 450.0244 F#4 = 370 Hz, tnext=16, dur=190, soft 36 -> 25
    db 9, 0, 206, 1, 110, 2, 30, 2  ; Note 1891: T 450.0401 D#5 = 622 Hz, tnext=9, dur=462, soft 44 -> 30
    db 204, 0, 252, 0, 11, 2, 30, 2  ; Note 1892: T 450.0490 C5 = 523 Hz, tnext=204, dur=252, soft 44 -> 30
    db 13, 0, 30, 1, 21, 1, 25, 1  ; Note 1893: T 450.2528 C#4 = 277 Hz, tnext=13, dur=286, soft 37 -> 25
    db 188, 0, 193, 0, 93, 1, 25, 1  ; Note 1894: T 450.2662 F4 = 349 Hz, tnext=188, dur=193, soft 36 -> 25
; T 450.3413 Soft 0 (Instrument 1)
; T 450.3413 Soft 0 (Instrument 2)
    db 246, 0, 148, 0, 42, 2, 39, 2  ; Note 1895: T 450.4543 C#5 = 554 Hz, tnext=246, dur=148
    db 11, 0, 112, 1, 21, 1, 33, 1  ; Note 1896: T 450.7007 C#4 = 277 Hz, tnext=11, dur=368
    db 1, 0, 15, 1, 42, 2, 39, 2  ; Note 1897: T 450.7119 C#5 = 554 Hz, tnext=1, dur=271
    db 52, 1, 124, 0, 93, 1, 33, 1  ; Note 1898: T 450.7130 F4 = 349 Hz, tnext=308, dur=124
    db 58, 0, 91, 2, 233, 0, 37, 1  ; Note 1899: T 451.0209 A#3 = 233 Hz, tnext=58, dur=603, sustain 363 -> 603
    db 3, 0, 33, 2, 93, 1, 38, 1  ; Note 1900: T 451.0791 F4 = 349 Hz, tnext=3, dur=545, sustain 74 -> 545
    db 255, 1, 30, 2, 42, 2, 43, 2  ; Note 1901: T 451.0825 C#5 = 554 Hz, tnext=511, dur=542, sustain 286 -> 542
; T 451.0993 Sustain 127 (Instrument 1)
; T 451.0993 Sustain 127 (Instrument 2)
    db 52, 0, 16, 1, 208, 0, 33, 1  ; Note 1902: T 451.5931 G#3 = 208 Hz, tnext=52, dur=272
; T 451.6244 Sustain 0 (Instrument 1)
; T 451.6244 Sustain 0 (Instrument 2)
    db 4, 0, 92, 0, 93, 1, 34, 1  ; Note 1903: T 451.6446 F4 = 349 Hz, tnext=4, dur=92
    db 208, 0, 174, 0, 42, 2, 39, 2  ; Note 1904: T 451.6491 C#5 = 554 Hz, tnext=208, dur=174
    db 26, 0, 253, 2, 196, 0, 36, 1  ; Note 1905: T 451.8573 G3 = 196 Hz, tnext=26, dur=765, sustain 339 -> 765
    db 24, 0, 167, 0, 55, 1, 37, 1  ; Note 1906: T 451.8831 D#4 = 311 Hz, tnext=24, dur=167
    db 254, 0, 207, 0, 42, 2, 42, 2  ; Note 1907: T 451.9066 C#5 = 554 Hz, tnext=254, dur=207
    db 10, 0, 205, 1, 208, 0, 34, 1  ; Note 1908: T 452.1608 G#3 = 208 Hz, tnext=10, dur=461, sustain 187 -> 461
    db 29, 0, 195, 1, 11, 2, 40, 2  ; Note 1909: T 452.1708 C5 = 523 Hz, tnext=29, dur=451, sustain 156 -> 451
; T 452.1854 Sustain 127 (Instrument 1)
; T 452.1854 Sustain 127 (Instrument 2)
    db 211, 0, 166, 1, 55, 1, 33, 1  ; Note 1910: T 452.2000 D#4 = 311 Hz, tnext=211, dur=422, sustain 122 -> 422
    db 4, 0, 238, 0, 208, 0, 33, 1  ; Note 1911: T 452.4105 G#3 = 208 Hz, tnext=4, dur=238
    db 17, 0, 220, 0, 238, 1, 38, 2  ; Note 1912: T 452.4149 B4 = 494 Hz, tnext=17, dur=220
    db 40, 1, 190, 0, 55, 1, 33, 1  ; Note 1913: T 452.4317 D#4 = 311 Hz, tnext=296, dur=190, sustain 186 -> 190
; T 452.6221 Sustain 0 (Instrument 1)
; T 452.6221 Sustain 0 (Instrument 2)
    db 3, 0, 145, 2, 55, 1, 37, 1  ; Note 1914: T 452.7273 D#4 = 311 Hz, tnext=3, dur=657, sustain 414 -> 657
    db 9, 0, 142, 2, 238, 1, 42, 2  ; Note 1915: T 452.7307 B4 = 494 Hz, tnext=9, dur=654, sustain 422 -> 654
    db 239, 1, 133, 2, 208, 0, 37, 1  ; Note 1916: T 452.7397 G#3 = 208 Hz, tnext=495, dur=645, sustain 527 -> 645
; T 452.8919 Sustain 127 (Instrument 1)
; T 452.8919 Sustain 127 (Instrument 2)
    db 10, 0, 209, 0, 238, 1, 39, 2  ; Note 1917: T 453.2346 B4 = 494 Hz, tnext=10, dur=209
    db 6, 0, 140, 0, 55, 1, 34, 1  ; Note 1918: T 453.2446 D#4 = 311 Hz, tnext=6, dur=140, sustain 95 -> 140
    db 185, 0, 234, 0, 185, 0, 34, 1  ; Note 1919: T 453.2502 F#3 = 185 Hz, tnext=185, dur=234
; T 453.3845 Sustain 0 (Instrument 1)
; T 453.3845 Sustain 0 (Instrument 2)
    db 1, 0, 109, 1, 21, 1, 36, 1  ; Note 1920: T 453.4349 C#4 = 277 Hz, tnext=1, dur=365, sustain 240 -> 365
    db 84, 0, 108, 1, 175, 0, 36, 1  ; Note 1921: T 453.4360 F3 = 175 Hz, tnext=84, dur=364, sustain 339 -> 364
    db 180, 0, 24, 1, 238, 1, 43, 2  ; Note 1922: T 453.5200 B4 = 494 Hz, tnext=180, dur=280, sustain 148 -> 280
; T 453.5670 Sustain 127 (Instrument 1)
; T 453.5670 Sustain 127 (Instrument 2)
    db 17, 0, 115, 0, 185, 0, 35, 1  ; Note 1923: T 453.7002 F#3 = 185 Hz, tnext=17, dur=115
    db 2, 0, 189, 0, 210, 1, 40, 2  ; Note 1924: T 453.7170 A#4 = 466 Hz, tnext=2, dur=189
    db 166, 0, 168, 0, 21, 1, 35, 1  ; Note 1925: T 453.7192 C#4 = 277 Hz, tnext=166, dur=168
; T 453.7998 Sustain 0 (Instrument 1)
; T 453.7998 Sustain 0 (Instrument 2)
    db 96, 0, 98, 1, 185, 0, 33, 1  ; Note 1926: T 453.8848 F#3 = 185 Hz, tnext=96, dur=354
    db 16, 0, 13, 1, 210, 1, 40, 2  ; Note 1927: T 453.9811 A#4 = 466 Hz, tnext=16, dur=269
    db 205, 0, 150, 0, 21, 1, 33, 1  ; Note 1928: T 453.9968 C#4 = 277 Hz, tnext=205, dur=150
    db 1, 0, 178, 2, 208, 0, 36, 1  ; Note 1929: T 454.2016 G#3 = 208 Hz, tnext=1, dur=690, sustain 458 -> 690
    db 91, 0, 176, 2, 156, 0, 36, 1  ; Note 1930: T 454.2027 D#3 = 156 Hz, tnext=91, dur=688, sustain 383 -> 688
    db 1, 0, 86, 2, 11, 2, 44, 2  ; Note 1931: T 454.2934 C5 = 523 Hz, tnext=1, dur=598, sustain 271 -> 598
    db 18, 2, 85, 2, 114, 1, 37, 1  ; Note 1932: T 454.2945 F#4 = 370 Hz, tnext=530, dur=597, sustain 257 -> 597
; T 454.3258 Sustain 127 (Instrument 1)
; T 454.3258 Sustain 127 (Instrument 2)
    db 3, 0, 136, 1, 139, 0, 34, 1  ; Note 1933: T 454.8250 C#3 = 139 Hz, tnext=3, dur=392
    db 3, 0, 150, 1, 42, 2, 45, 2  ; Note 1934: T 454.8284 C#5 = 554 Hz, tnext=3, dur=406
    db 7, 0, 9, 1, 208, 0, 34, 1  ; Note 1935: T 454.8317 G#3 = 208 Hz, tnext=7, dur=265
    db 93, 1, 41, 1, 93, 1, 34, 1  ; Note 1936: T 454.8384 F4 = 349 Hz, tnext=349, dur=297
; T 454.8911 Sustain 0 (Instrument 1)
; T 454.8911 Sustain 0 (Instrument 2)
    db 47, 0, 83, 5, 131, 0, 39, 1  ; Note 1937: T 455.1877 C3 = 131 Hz, tnext=47, dur=1363
    db 18, 0, 133, 4, 208, 0, 39, 1  ; Note 1938: T 455.2347 G#3 = 208 Hz, tnext=18, dur=1157
    db 1, 0, 54, 4, 110, 2, 51, 2  ; Note 1939: T 455.2526 D#5 = 622 Hz, tnext=1, dur=1078, sustain 631 -> 1078
    db 182, 3, 53, 4, 114, 1, 42, 1  ; Note 1940: T 455.2537 F#4 = 370 Hz, tnext=950, dur=1077, sustain 631 -> 1077
; T 455.5212 Sustain 127 (Instrument 1)
; T 455.5212 Sustain 127 (Instrument 2)
    db 21, 0, 221, 2, 114, 1, 36, 1  ; Note 1941: T 456.2039 F#4 = 370 Hz, tnext=21, dur=733
    db 100, 1, 30, 3, 55, 1, 37, 1  ; Note 1942: T 456.2252 D#4 = 311 Hz, tnext=356, dur=798
; T 456.3069 Soft 127 (Instrument 1)
; T 456.3069 Soft 127 (Instrument 2)
; T 456.3304 Sustain 0 (Instrument 1)
; T 456.3304 Sustain 0 (Instrument 2)
    db 30, 0, 120, 2, 139, 0, 23, 1  ; Note 1943: T 456.5811 C#3 = 139 Hz, tnext=30, dur=632, soft 33 -> 23
    db 35, 1, 175, 1, 208, 0, 23, 1  ; Note 1944: T 456.6113 G#3 = 208 Hz, tnext=291, dur=431, soft 33 -> 23
    db 121, 0, 184, 0, 21, 1, 23, 1  ; Note 1945: T 456.9024 C#4 = 277 Hz, tnext=121, dur=184, soft 34 -> 23
    db 167, 0, 37, 1, 93, 1, 29, 1  ; Note 1946: T 457.0232 F4 = 349 Hz, tnext=167, dur=293, soft 42 -> 29
    db 111, 0, 116, 1, 92, 0, 23, 1  ; Note 1947: T 457.1900 F#2 = 92 Hz, tnext=111, dur=372, soft 34 -> 23
    db 13, 0, 182, 1, 233, 0, 24, 1  ; Note 1948: T 457.3008 A#3 = 233 Hz, tnext=13, dur=438, soft 35 -> 24
    db 117, 0, 64, 1, 185, 0, 24, 1  ; Note 1949: T 457.3142 F#3 = 185 Hz, tnext=117, dur=320, soft 35 -> 24
    db 139, 0, 168, 0, 210, 1, 30, 2  ; Note 1950: T 457.4317 A#4 = 466 Hz, tnext=139, dur=168, soft 43 -> 30
    db 27, 0, 248, 0, 156, 0, 23, 1  ; Note 1951: T 457.5704 D#3 = 156 Hz, tnext=27, dur=248, soft 33 -> 23
    db 174, 0, 194, 0, 114, 1, 23, 1  ; Note 1952: T 457.5973 F#4 = 370 Hz, tnext=174, dur=194, soft 34 -> 23
    db 20, 0, 96, 1, 104, 0, 23, 1  ; Note 1953: T 457.7718 G#2 = 104 Hz, tnext=20, dur=352, soft 34 -> 23, sustain 322 -> 352
    db 68, 0, 85, 1, 208, 0, 23, 1  ; Note 1954: T 457.7919 G#3 = 208 Hz, tnext=68, dur=341, soft 34 -> 23
; T 457.8289 Sustain 127 (Instrument 1)
; T 457.8289 Sustain 127 (Instrument 2)
    db 2, 0, 8, 1, 93, 1, 26, 1  ; Note 1955: T 457.8602 F4 = 349 Hz, tnext=2, dur=264, soft 38 -> 26, sustain 258 -> 264
    db 255, 0, 6, 1, 21, 1, 26, 1  ; Note 1956: T 457.8624 C#4 = 277 Hz, tnext=255, dur=262, soft 38 -> 26, sustain 224 -> 262
    db 7, 0, 81, 0, 6, 1, 28, 1  ; Note 1957: T 458.1175 C4 = 262 Hz, tnext=7, dur=81, soft 40 -> 28
    db 232, 0, 95, 0, 55, 1, 28, 1  ; Note 1958: T 458.1242 D#4 = 311 Hz, tnext=232, dur=95, soft 40 -> 28
; T 458.1242 Sustain 0 (Instrument 1)
; T 458.1242 Sustain 0 (Instrument 2)
    db 6, 0, 178, 0, 175, 0, 26, 1  ; Note 1959: T 458.3558 F3 = 175 Hz, tnext=6, dur=178, soft 38 -> 26
    db 18, 0, 110, 0, 208, 0, 26, 1  ; Note 1960: T 458.3614 G#3 = 208 Hz, tnext=18, dur=110, soft 38 -> 26
    db 2, 0, 246, 0, 42, 2, 30, 2  ; Note 1961: T 458.3793 C#5 = 554 Hz, tnext=2, dur=246, soft 43 -> 30
    db 224, 0, 9, 1, 21, 1, 27, 1  ; Note 1962: T 458.3815 C#4 = 277 Hz, tnext=224, dur=265, soft 39 -> 27
    db 20, 0, 238, 1, 156, 0, 29, 1  ; Note 1963: T 458.6053 D#3 = 156 Hz, tnext=20, dur=494, soft 42 -> 29
    db 59, 0, 208, 1, 208, 0, 29, 1  ; Note 1964: T 458.6254 G#3 = 208 Hz, tnext=59, dur=464, soft 42 -> 29, sustain 430 -> 464
    db 3, 0, 149, 1, 6, 1, 28, 1  ; Note 1965: T 458.6847 C4 = 262 Hz, tnext=3, dur=405, soft 41 -> 28, sustain 362 -> 405
    db 171, 1, 146, 1, 11, 2, 31, 2  ; Note 1966: T 458.6881 C5 = 523 Hz, tnext=427, dur=402, soft 45 -> 31, sustain 351 -> 402
; T 458.7698 Sustain 127 (Instrument 1)
; T 458.7698 Sustain 127 (Instrument 2)
; T 459.0897 Sustain 0 (Instrument 1)
; T 459.0897 Sustain 0 (Instrument 2)
    db 1, 0, 49, 1, 210, 1, 29, 2  ; Note 1967: T 459.1155 A#4 = 466 Hz, tnext=1, dur=305, soft 42 -> 29
    db 7, 0, 174, 0, 196, 0, 26, 1  ; Note 1968: T 459.1166 G3 = 196 Hz, tnext=7, dur=174, soft 38 -> 26
    db 0, 0, 87, 0, 233, 0, 26, 1  ; Note 1969: T 459.1233 A#3 = 233 Hz, tnext=0, dur=87, soft 38 -> 26
    db 224, 0, 160, 0, 139, 0, 26, 1  ; Note 1970: T 459.1233 C#3 = 139 Hz, tnext=224, dur=160, soft 38 -> 26
    db 39, 0, 95, 0, 131, 0, 25, 1  ; Note 1971: T 459.3471 C3 = 131 Hz, tnext=39, dur=95, soft 37 -> 25
    db 27, 0, 108, 0, 6, 1, 25, 1  ; Note 1972: T 459.3862 C4 = 262 Hz, tnext=27, dur=108, soft 37 -> 25
    db 11, 0, 87, 0, 55, 1, 25, 1  ; Note 1973: T 459.4131 D#4 = 311 Hz, tnext=11, dur=87, soft 37 -> 25
    db 161, 1, 68, 0, 110, 2, 30, 2  ; Note 1974: T 459.4243 D#5 = 622 Hz, tnext=417, dur=68, soft 43 -> 30
    db 39, 0, 120, 0, 139, 0, 25, 1  ; Note 1975: T 459.8416 C#3 = 139 Hz, tnext=39, dur=120, soft 37 -> 25
    db 5, 0, 74, 0, 233, 0, 25, 1  ; Note 1976: T 459.8807 A#3 = 233 Hz, tnext=5, dur=74, soft 37 -> 25
    db 8, 0, 121, 1, 42, 2, 30, 2  ; Note 1977: T 459.8852 C#5 = 554 Hz, tnext=8, dur=377, soft 43 -> 30
    db 204, 0, 212, 0, 93, 1, 25, 1  ; Note 1978: T 459.8931 F4 = 349 Hz, tnext=204, dur=212, soft 37 -> 25
    db 19, 0, 94, 0, 156, 0, 26, 1  ; Note 1979: T 460.0967 D#3 = 156 Hz, tnext=19, dur=94, soft 38 -> 26
    db 8, 0, 246, 0, 159, 1, 28, 2  ; Note 1980: T 460.1157 G#4 = 415 Hz, tnext=8, dur=246, soft 41 -> 28
    db 203, 0, 101, 0, 55, 1, 25, 1  ; Note 1981: T 460.1235 D#4 = 311 Hz, tnext=203, dur=101, soft 37 -> 25
    db 191, 0, 213, 0, 11, 2, 27, 2  ; Note 1982: T 460.3260 C5 = 523 Hz, tnext=191, dur=213, soft 39 -> 27
    db 1, 0, 161, 0, 156, 0, 23, 1  ; Note 1983: T 460.5173 D#3 = 156 Hz, tnext=1, dur=161, soft 33 -> 23
    db 23, 0, 121, 0, 21, 1, 23, 1  ; Note 1984: T 460.5185 C#4 = 277 Hz, tnext=23, dur=121, soft 33 -> 23
    db 9, 0, 207, 1, 210, 1, 29, 2  ; Note 1985: T 460.5420 A#4 = 466 Hz, tnext=9, dur=463, soft 42 -> 29
    db 178, 0, 219, 0, 136, 1, 29, 2  ; Note 1986: T 460.5509 G4 = 392 Hz, tnext=178, dur=219, soft 42 -> 29
    db 7, 0, 121, 0, 6, 1, 24, 1  ; Note 1987: T 460.7288 C4 = 262 Hz, tnext=7, dur=121, soft 35 -> 24
    db 215, 0, 154, 0, 208, 0, 24, 1  ; Note 1988: T 460.7355 G#3 = 208 Hz, tnext=215, dur=154, soft 35 -> 24
    db 190, 0, 167, 0, 159, 1, 26, 2  ; Note 1989: T 460.9503 G#4 = 415 Hz, tnext=190, dur=167, soft 38 -> 26
    db 15, 0, 36, 1, 233, 0, 23, 1  ; Note 1990: T 461.1405 A#3 = 233 Hz, tnext=15, dur=292, soft 34 -> 23
    db 13, 0, 140, 0, 21, 1, 23, 1  ; Note 1991: T 461.1551 C#4 = 277 Hz, tnext=13, dur=140, soft 34 -> 23
    db 18, 0, 230, 0, 114, 1, 23, 1  ; Note 1992: T 461.1685 F#4 = 370 Hz, tnext=18, dur=230, soft 34 -> 23
; T 461.1819 Soft 0 (Instrument 1)
; T 461.1819 Soft 0 (Instrument 2)
    db 199, 0, 207, 0, 228, 2, 48, 2  ; Note 1993: T 461.1864 F#5 = 740 Hz, tnext=199, dur=207
    db 12, 0, 243, 1, 208, 0, 37, 1  ; Note 1994: T 461.3855 G#3 = 208 Hz, tnext=12, dur=499
    db 51, 0, 170, 1, 21, 1, 37, 1  ; Note 1995: T 461.3978 C#4 = 277 Hz, tnext=51, dur=426, sustain 394 -> 426
    db 27, 0, 119, 1, 186, 2, 47, 2  ; Note 1996: T 461.4492 F5 = 698 Hz, tnext=27, dur=375, sustain 333 -> 375
    db 111, 1, 92, 1, 93, 1, 38, 1  ; Note 1997: T 461.4761 F4 = 349 Hz, tnext=367, dur=348, sustain 287 -> 348
; T 461.5376 Sustain 127 (Instrument 1)
; T 461.5376 Sustain 127 (Instrument 2)
; T 461.8239 Sustain 0 (Instrument 1)
; T 461.8239 Sustain 0 (Instrument 2)
    db 5, 0, 115, 0, 6, 1, 36, 1  ; Note 1998: T 461.8429 C4 = 262 Hz, tnext=5, dur=115
    db 13, 0, 201, 0, 185, 0, 36, 1  ; Note 1999: T 461.8474 F#3 = 185 Hz, tnext=13, dur=201
    db 14, 0, 178, 0, 110, 2, 42, 2  ; Note 2000: T 461.8608 D#5 = 622 Hz, tnext=14, dur=178
    db 163, 0, 125, 0, 55, 1, 37, 1  ; Note 2001: T 461.8753 D#4 = 311 Hz, tnext=163, dur=125
    db 19, 0, 210, 1, 175, 0, 39, 1  ; Note 2002: T 462.0386 F3 = 175 Hz, tnext=19, dur=466, sustain 236 -> 466
    db 49, 0, 191, 1, 21, 1, 39, 1  ; Note 2003: T 462.0576 C#4 = 277 Hz, tnext=49, dur=447, sustain 218 -> 447
    db 10, 0, 142, 1, 63, 3, 47, 2  ; Note 2004: T 462.1068 G#5 = 831 Hz, tnext=10, dur=398, sustain 212 -> 398
    db 162, 1, 132, 1, 159, 1, 47, 2  ; Note 2005: T 462.1169 G#4 = 415 Hz, tnext=418, dur=388, sustain 197 -> 388
; T 462.1504 Sustain 127 (Instrument 1)
; T 462.1504 Sustain 127 (Instrument 2)
; T 462.5050 Sustain 0 (Instrument 1)
; T 462.5050 Sustain 0 (Instrument 2)
    db 6, 0, 146, 0, 233, 0, 39, 1  ; Note 2006: T 462.5352 A#3 = 233 Hz, tnext=6, dur=146
    db 1, 0, 186, 1, 114, 1, 39, 1  ; Note 2007: T 462.5408 F#4 = 370 Hz, tnext=1, dur=442, sustain 325 -> 442
    db 4, 0, 94, 0, 21, 1, 39, 1  ; Note 2008: T 462.5419 C#4 = 277 Hz, tnext=4, dur=94
    db 192, 0, 180, 1, 228, 2, 52, 2  ; Note 2009: T 462.5463 F#5 = 740 Hz, tnext=192, dur=436, sustain 320 -> 436
; T 462.7354 Sustain 127 (Instrument 1)
; T 462.7354 Sustain 127 (Instrument 2)
    db 1, 0, 207, 1, 208, 0, 42, 1  ; Note 2010: T 462.7387 G#3 = 208 Hz, tnext=1, dur=463
    db 196, 0, 60, 1, 21, 1, 42, 1  ; Note 2011: T 462.7398 C#4 = 277 Hz, tnext=196, dur=316
    db 14, 0, 134, 0, 93, 1, 40, 1  ; Note 2012: T 462.9355 F4 = 349 Hz, tnext=14, dur=134
    db 190, 0, 139, 0, 186, 2, 52, 2  ; Note 2013: T 462.9490 F5 = 698 Hz, tnext=190, dur=139
; T 462.9825 Sustain 0 (Instrument 1)
; T 462.9825 Sustain 0 (Instrument 2)
    db 20, 0, 115, 0, 185, 0, 37, 1  ; Note 2014: T 463.1391 F#3 = 185 Hz, tnext=20, dur=115
    db 24, 0, 186, 0, 6, 1, 37, 1  ; Note 2015: T 463.1592 C4 = 262 Hz, tnext=24, dur=186
    db 1, 0, 115, 0, 110, 2, 51, 2  ; Note 2016: T 463.1827 D#5 = 622 Hz, tnext=1, dur=115
    db 117, 0, 96, 0, 55, 1, 37, 1  ; Note 2017: T 463.1838 D#4 = 311 Hz, tnext=117, dur=96
    db 54, 0, 171, 1, 175, 0, 38, 1  ; Note 2018: T 463.3012 F3 = 175 Hz, tnext=54, dur=427, sustain 226 -> 427
    db 7, 0, 118, 1, 21, 1, 39, 1  ; Note 2019: T 463.3549 C#4 = 277 Hz, tnext=7, dur=374, sustain 220 -> 374
    db 12, 0, 111, 1, 159, 1, 54, 2  ; Note 2020: T 463.3616 G#4 = 415 Hz, tnext=12, dur=367, sustain 280 -> 367
    db 161, 1, 99, 1, 63, 3, 54, 2  ; Note 2021: T 463.3739 G#5 = 831 Hz, tnext=417, dur=355, sustain 260 -> 355
; T 463.4779 Sustain 127 (Instrument 1)
; T 463.4779 Sustain 127 (Instrument 2)
; T 463.7285 Sustain 0 (Instrument 1)
; T 463.7285 Sustain 0 (Instrument 2)
    db 13, 0, 157, 1, 114, 1, 44, 1  ; Note 2022: T 463.7911 F#4 = 370 Hz, tnext=13, dur=413, sustain 320 -> 413
    db 6, 0, 121, 0, 233, 0, 45, 1  ; Note 2023: T 463.8045 A#3 = 233 Hz, tnext=6, dur=121
    db 6, 0, 96, 0, 21, 1, 45, 1  ; Note 2024: T 463.8101 C#4 = 277 Hz, tnext=6, dur=96
    db 161, 0, 132, 1, 228, 2, 62, 2  ; Note 2025: T 463.8157 F#5 = 740 Hz, tnext=161, dur=388, sustain 296 -> 388
; T 463.9532 Sustain 127 (Instrument 1)
; T 463.9532 Sustain 127 (Instrument 2)
    db 8, 0, 154, 1, 208, 0, 47, 1  ; Note 2026: T 463.9767 G#3 = 208 Hz, tnext=8, dur=410
    db 211, 0, 54, 1, 21, 1, 47, 1  ; Note 2027: T 463.9846 C#4 = 277 Hz, tnext=211, dur=310
    db 3, 0, 118, 1, 93, 1, 49, 1  ; Note 2028: T 464.1959 F4 = 349 Hz, tnext=3, dur=374, sustain 254 -> 374
    db 145, 0, 114, 1, 186, 2, 61, 2  ; Note 2029: T 464.1993 F5 = 698 Hz, tnext=145, dur=370, sustain 298 -> 370
; T 464.2038 Sustain 0 (Instrument 1)
; T 464.2038 Sustain 0 (Instrument 2)
    db 86, 0, 119, 3, 196, 0, 58, 1  ; Note 2030: T 464.3447 G3 = 196 Hz, tnext=86, dur=887
; T 464.4051 Sustain 127 (Instrument 1)
; T 464.4051 Sustain 127 (Instrument 2)
    db 51, 0, 52, 2, 21, 1, 60, 1  ; Note 2031: T 464.4308 C#4 = 277 Hz, tnext=51, dur=564
    db 129, 0, 54, 2, 74, 1, 60, 1  ; Note 2032: T 464.4822 E4 = 330 Hz, tnext=129, dur=566
; T 464.5695 Sustain 0 (Instrument 1)
; T 464.5695 Sustain 0 (Instrument 2)
    db 12, 0, 151, 5, 210, 1, 70, 2  ; Note 2033: T 464.6108 A#4 = 466 Hz, tnext=12, dur=1431, sustain 1323 -> 1431
    db 118, 2, 139, 5, 164, 3, 70, 2  ; Note 2034: T 464.6231 A#5 = 932 Hz, tnext=630, dur=1419, sustain 1396 -> 1419
    db 6, 0, 132, 4, 208, 0, 40, 1  ; Note 2035: T 465.2528 G#3 = 208 Hz, tnext=6, dur=1156
    db 2, 0, 20, 4, 93, 1, 40, 1  ; Note 2036: T 465.2584 F4 = 349 Hz, tnext=2, dur=1044
    db 2, 3, 111, 4, 21, 1, 40, 1  ; Note 2037: T 465.2606 C#4 = 277 Hz, tnext=770, dur=1135
; T 465.7637 Sustain 127 (Instrument 1)
; T 465.7637 Sustain 127 (Instrument 2)
    db 12, 0, 89, 1, 159, 1, 40, 2  ; Note 2038: T 466.0309 G#4 = 415 Hz, tnext=12, dur=345
; T 466.0420 Sustain 0 (Instrument 1)
; T 466.0420 Sustain 0 (Instrument 2)
    db 20, 3, 63, 1, 63, 3, 40, 2  ; Note 2039: T 466.0432 G#5 = 831 Hz, tnext=788, dur=319
; T 466.0499 Soft 127 (Instrument 1)
; T 466.0499 Soft 127 (Instrument 2)
    db 45, 0, 245, 5, 52, 0, 23, 1  ; Note 2040: T 466.8313 G#1 = 52 Hz, tnext=45, dur=1525, soft 34 -> 23
    db 139, 0, 23, 15, 104, 0, 24, 1  ; Note 2041: T 466.8760 G#2 = 104 Hz, tnext=139, dur=3863, soft 35 -> 24, sustain 2110 -> 3863
    db 58, 0, 212, 4, 185, 0, 25, 1  ; Note 2042: T 467.0146 F#3 = 185 Hz, tnext=58, dur=1236, soft 37 -> 25
    db 157, 3, 217, 3, 6, 1, 25, 1  ; Note 2043: T 467.0728 C4 = 262 Hz, tnext=925, dur=985, soft 37 -> 25
    db 245, 0, 240, 0, 55, 1, 26, 1  ; Note 2044: T 467.9973 D#4 = 311 Hz, tnext=245, dur=240, soft 38 -> 26
    db 151, 0, 37, 1, 21, 1, 24, 1  ; Note 2045: T 468.2421 C#4 = 277 Hz, tnext=151, dur=293, soft 35 -> 24
    db 1, 1, 42, 9, 69, 0, 23, 1  ; Note 2046: T 468.3930 C#2 = 69 Hz, tnext=257, dur=2346, soft 34 -> 23, sustain 599 -> 2346
    db 8, 0, 41, 8, 175, 0, 23, 1  ; Note 2047: T 468.6501 F3 = 175 Hz, tnext=8, dur=2089, soft 34 -> 23, sustain 341 -> 2089
    db 0, 0, 33, 8, 21, 1, 23, 1  ; Note 2048: T 468.6580 C#4 = 277 Hz, tnext=0, dur=2081, soft 34 -> 23, sustain 349 -> 2081
; T 468.6792 Sustain 127 (Instrument 2)
; T 468.6859 Sustain 127 (Instrument 1)
; T 468.7206 Soft 0 (Instrument 2)
; T 468.7273 Soft 0 (Instrument 1)
; T 470.7389 Sustain 0 (Instrument 1)
; T 470.7892 Sustain 0 (Instrument 2)
    db 255, 255, 255, 255, 255, 255, 255, 255  ; End marker

; Information:
; Maximum delta time: 13283 ms (13.28 seconds)
; Maximum note duration: 17011 ms (17.01 seconds)
; Frequency range: 35 Hz to 1245 Hz

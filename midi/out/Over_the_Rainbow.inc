; Piano note data with dynamic channel assignment

; Format of each note record:
;     tnext_lo:     equ 0     ; next-note time low byte
;     tnext_hi:     equ 1     ; next-note time high byte
;     duration_lo:  equ 2     ; duration low byte
;     duration_hi:  equ 3     ; duration high byte
;     pitch:        equ 4     ; MIDI pitch (0–127)
;     velocity:     equ 5     ; MIDI velocity (0–127)
;     instrument:   equ 6     ; instrument number (1–255)
;     channel:      equ 7     ; channel number (0–31)
;     freq_lo:      equ 8     ; frequency low byte
;     freq_hi:      equ 9     ; frequency high byte
;     buffer_id_lo: equ 10    ; buffer ID low byte
;     buffer_id_hi: equ 11    ; buffer ID high byte
;     bytes_per_note: equ 12  ; total fields per note

total_notes: equ 581
midi_data:
    db 0,0,146,5,39,64,1,0,78,0,39,1  ; n1 t=2.824s dur=1426ms, freq=78Hz, sample=39, buffer_id=01:27
    db 0,0,146,5,63,64,1,1,55,1,63,1  ; n2 t=2.824s dur=1426ms, freq=311Hz, sample=63, buffer_id=01:3F
    db 0,0,72,5,70,35,2,2,210,1,70,2  ; n3 t=2.824s dur=1352ms, freq=466Hz, sample=70, buffer_id=02:46
    db 0,0,72,5,67,24,2,3,136,1,67,2  ; n4 t=2.824s dur=1352ms, freq=392Hz, sample=67, buffer_id=02:43
    db 0,0,72,5,63,30,2,4,55,1,63,2  ; n5 t=2.824s dur=1352ms, freq=311Hz, sample=63, buffer_id=02:3F
    db 100,1,122,5,39,39,3,5,78,0,39,3  ; n6 t=2.824s dur=1402ms, freq=78Hz, sample=39, buffer_id=03:27
; t 2.9029 Sustain 127 (Instr 1)
    db 91,1,46,4,46,54,1,6,117,0,46,1  ; n7 t=3.179s dur=1070ms, freq=117Hz, sample=46, buffer_id=01:2E
    db 97,1,211,2,51,51,1,7,156,0,51,1  ; n8 t=3.526s dur=723ms, freq=156Hz, sample=51, buffer_id=01:33
    db 65,1,114,1,55,54,1,8,196,0,55,1  ; n9 t=3.879s dur=370ms, freq=196Hz, sample=55, buffer_id=01:37
    db 3,0,220,5,39,39,3,5,65,0,39,3  ; n10 t=4.200s dur=1500ms, freq=65Hz, sample=39, buffer_id=03:27
    db 0,0,72,5,70,38,2,2,210,1,70,2  ; n11 t=4.203s dur=1352ms, freq=466Hz, sample=70, buffer_id=02:46
    db 0,0,72,5,67,31,2,3,136,1,67,2  ; n12 t=4.203s dur=1352ms, freq=392Hz, sample=67, buffer_id=02:43
    db 30,0,72,5,75,43,2,9,110,2,75,2  ; n13 t=4.203s dur=1352ms, freq=622Hz, sample=75, buffer_id=02:4B
    db 0,0,84,5,48,58,1,10,131,0,48,1  ; n14 t=4.232s dur=1364ms, freq=131Hz, sample=48, buffer_id=01:30
    db 94,1,84,5,75,58,1,11,110,2,75,1  ; n15 t=4.232s dur=1364ms, freq=622Hz, sample=75, buffer_id=01:4B
; t 4.2500 Sustain 0 (Instr 1)
; t 4.4324 Sustain 127 (Instr 1)
    db 100,1,246,3,55,43,1,0,196,0,55,1  ; n16 t=4.582s dur=1014ms, freq=196Hz, sample=55, buffer_id=01:37
    db 91,1,146,2,60,43,1,1,6,1,60,1  ; n17 t=4.938s dur=658ms, freq=262Hz, sample=60, buffer_id=01:3C
    db 70,1,55,1,63,46,1,4,55,1,63,1  ; n18 t=5.285s dur=311ms, freq=311Hz, sample=63, buffer_id=01:3F
; t 5.5971 Sustain 0 (Instr 1)
    db 3,0,31,11,43,33,3,6,98,0,43,3  ; n19 t=5.612s dur=2847ms, freq=98Hz, sample=43, buffer_id=03:2B
    db 0,0,10,8,67,28,2,3,136,1,67,2  ; n20 t=5.615s dur=2058ms, freq=392Hz, sample=67, buffer_id=02:43
    db 0,0,10,8,70,38,2,2,210,1,70,2  ; n21 t=5.615s dur=2058ms, freq=466Hz, sample=70, buffer_id=02:46
    db 24,0,10,8,74,39,2,7,75,2,74,2  ; n22 t=5.615s dur=2058ms, freq=587Hz, sample=74, buffer_id=02:4A
    db 0,0,48,11,43,58,1,8,98,0,43,1  ; n23 t=5.638s dur=2864ms, freq=98Hz, sample=43, buffer_id=01:2B
    db 100,1,48,11,74,58,1,12,75,2,74,1  ; n24 t=5.638s dur=2864ms, freq=587Hz, sample=74, buffer_id=01:4A
; t 5.7941 Sustain 127 (Instr 1)
    db 97,1,204,9,50,46,1,0,147,0,50,1  ; n25 t=5.994s dur=2508ms, freq=147Hz, sample=50, buffer_id=01:32
    db 97,1,107,8,70,57,1,1,210,1,70,1  ; n26 t=6.347s dur=2155ms, freq=466Hz, sample=70, buffer_id=01:46
    db 100,1,10,7,72,53,1,4,11,2,72,1  ; n27 t=6.700s dur=1802ms, freq=523Hz, sample=72, buffer_id=01:48
    db 97,1,167,5,74,59,1,12,75,2,74,1  ; n28 t=7.056s dur=1447ms, freq=587Hz, sample=74, buffer_id=01:4A
    db 73,1,70,4,58,43,1,5,233,0,58,1  ; n29 t=7.409s dur=1094ms, freq=233Hz, sample=58, buffer_id=01:3A
    db 0,0,135,2,70,34,2,2,210,1,70,2  ; n30 t=7.738s dur=647ms, freq=466Hz, sample=70, buffer_id=02:46
    db 3,0,135,2,67,28,2,3,136,1,67,2  ; n31 t=7.738s dur=647ms, freq=392Hz, sample=67, buffer_id=02:43
    db 21,0,135,2,72,44,2,9,42,2,72,2  ; n32 t=7.741s dur=647ms, freq=554Hz, sample=72, buffer_id=02:48
    db 97,1,229,2,75,59,1,10,110,2,75,1  ; n33 t=7.762s dur=741ms, freq=622Hz, sample=75, buffer_id=01:4B
    db 62,1,132,1,60,48,1,7,21,1,60,1  ; n34 t=8.115s dur=388ms, freq=277Hz, sample=60, buffer_id=01:3C
    db 6,0,81,11,44,39,3,11,104,0,44,3  ; n35 t=8.432s dur=2897ms, freq=104Hz, sample=44, buffer_id=03:2C
    db 3,0,72,5,63,32,2,13,55,1,63,2  ; n36 t=8.438s dur=1352ms, freq=311Hz, sample=63, buffer_id=02:3F
    db 3,0,72,5,72,34,2,9,11,2,72,2  ; n37 t=8.441s dur=1352ms, freq=523Hz, sample=72, buffer_id=02:48
    db 21,0,72,5,68,35,2,14,159,1,68,2  ; n38 t=8.444s dur=1352ms, freq=415Hz, sample=68, buffer_id=02:44
    db 3,0,210,10,44,60,1,15,104,0,44,1  ; n39 t=8.465s dur=2770ms, freq=104Hz, sample=44, buffer_id=01:2C
    db 97,1,207,10,63,60,1,16,55,1,63,1  ; n40 t=8.468s dur=2767ms, freq=311Hz, sample=63, buffer_id=01:3F
; t 8.5029 Sustain 0 (Instr 1)
; t 8.6853 Sustain 127 (Instr 1)
    db 94,1,110,9,51,54,1,0,156,0,51,1  ; n41 t=8.821s dur=2414ms, freq=156Hz, sample=51, buffer_id=01:33
    db 97,1,16,8,56,51,1,1,208,0,56,1  ; n42 t=9.171s dur=2064ms, freq=208Hz, sample=56, buffer_id=01:38
    db 70,1,175,6,60,51,1,2,6,1,60,1  ; n43 t=9.524s dur=1711ms, freq=262Hz, sample=60, buffer_id=01:3C
    db 0,0,72,5,72,31,2,9,11,2,72,2  ; n44 t=9.850s dur=1352ms, freq=523Hz, sample=72, buffer_id=02:48
    db 0,0,72,5,68,33,2,14,159,1,68,2  ; n45 t=9.850s dur=1352ms, freq=415Hz, sample=68, buffer_id=02:44
    db 24,0,72,5,63,35,2,13,55,1,63,2  ; n46 t=9.850s dur=1352ms, freq=311Hz, sample=63, buffer_id=02:3F
    db 94,1,81,5,72,60,1,3,11,2,72,1  ; n47 t=9.873s dur=1361ms, freq=523Hz, sample=72, buffer_id=01:48
    db 100,1,243,3,60,48,1,2,6,1,60,1  ; n48 t=10.223s dur=1011ms, freq=262Hz, sample=60, buffer_id=01:3C
    db 91,1,143,2,63,52,1,16,55,1,63,1  ; n49 t=10.579s dur=655ms, freq=311Hz, sample=63, buffer_id=01:3F
    db 73,1,52,1,68,52,1,4,159,1,68,1  ; n50 t=10.927s dur=308ms, freq=415Hz, sample=68, buffer_id=01:44
; t 11.2353 Sustain 0 (Instr 1)
    db 6,0,89,11,43,36,3,5,98,0,43,3  ; n51 t=11.256s dur=2905ms, freq=98Hz, sample=43, buffer_id=03:2B
    db 0,0,204,10,63,34,2,13,55,1,63,2  ; n52 t=11.262s dur=2764ms, freq=311Hz, sample=63, buffer_id=02:3F
    db 0,0,204,10,67,30,2,6,136,1,67,2  ; n53 t=11.262s dur=2764ms, freq=392Hz, sample=67, buffer_id=02:43
    db 21,0,204,10,70,39,2,7,210,1,70,2  ; n54 t=11.262s dur=2764ms, freq=466Hz, sample=70, buffer_id=02:46
    db 0,0,1,11,43,57,1,8,98,0,43,1  ; n55 t=11.282s dur=2817ms, freq=98Hz, sample=43, buffer_id=01:2B
    db 94,1,1,11,70,57,1,10,210,1,70,1  ; n56 t=11.282s dur=2817ms, freq=466Hz, sample=70, buffer_id=01:46
; t 11.4206 Sustain 127 (Instr 1)
    db 97,1,163,9,51,51,1,0,156,0,51,1  ; n57 t=11.632s dur=2467ms, freq=156Hz, sample=51, buffer_id=01:33
    db 97,1,66,8,55,52,1,1,196,0,55,1  ; n58 t=11.985s dur=2114ms, freq=196Hz, sample=55, buffer_id=01:37
    db 97,1,225,6,58,42,1,2,233,0,58,1  ; n59 t=12.338s dur=1761ms, freq=233Hz, sample=58, buffer_id=01:3A
    db 94,1,128,5,67,48,1,3,136,1,67,1  ; n60 t=12.691s dur=1408ms, freq=392Hz, sample=67, buffer_id=01:43
    db 100,1,34,4,58,36,1,2,233,0,58,1  ; n61 t=13.041s dur=1058ms, freq=233Hz, sample=58, buffer_id=01:3A
    db 91,1,190,2,63,43,1,4,55,1,63,1  ; n62 t=13.397s dur=702ms, freq=311Hz, sample=63, buffer_id=01:3F
    db 79,1,99,1,58,47,1,2,233,0,58,1  ; n63 t=13.744s dur=355ms, freq=233Hz, sample=58, buffer_id=01:3A
    db 3,0,22,11,44,41,3,9,104,0,44,3  ; n64 t=14.079s dur=2838ms, freq=104Hz, sample=44, buffer_id=03:2C
    db 0,0,72,5,60,30,2,11,6,1,60,2  ; n65 t=14.082s dur=1352ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 0,0,72,5,68,40,2,12,159,1,68,2  ; n66 t=14.082s dur=1352ms, freq=415Hz, sample=68, buffer_id=02:44
    db 24,0,72,5,63,28,2,13,55,1,63,2  ; n67 t=14.082s dur=1352ms, freq=311Hz, sample=63, buffer_id=02:3F
; t 14.1000 Sustain 0 (Instr 1)
    db 3,0,207,10,60,60,1,14,6,1,60,1  ; n68 t=14.106s dur=2767ms, freq=262Hz, sample=60, buffer_id=01:3C
    db 94,1,204,10,44,60,1,15,104,0,44,1  ; n69 t=14.109s dur=2764ms, freq=104Hz, sample=44, buffer_id=01:2C
; t 14.2971 Sustain 127 (Instr 1)
    db 94,1,110,9,51,45,1,0,156,0,51,1  ; n70 t=14.459s dur=2414ms, freq=156Hz, sample=51, buffer_id=01:33
    db 100,1,16,8,56,48,1,1,208,0,56,1  ; n71 t=14.809s dur=2064ms, freq=208Hz, sample=56, buffer_id=01:38
    db 73,1,172,6,60,56,1,14,6,1,60,1  ; n72 t=15.165s dur=1708ms, freq=262Hz, sample=60, buffer_id=01:3C
    db 0,0,72,5,63,24,2,13,55,1,63,2  ; n73 t=15.494s dur=1352ms, freq=311Hz, sample=63, buffer_id=02:3F
    db 0,0,72,5,68,37,2,12,159,1,68,2  ; n74 t=15.494s dur=1352ms, freq=415Hz, sample=68, buffer_id=02:44
    db 27,0,72,5,58,32,2,2,247,0,58,2  ; n75 t=15.494s dur=1352ms, freq=247Hz, sample=58, buffer_id=02:3A
    db 100,1,72,5,68,61,1,3,159,1,68,1  ; n76 t=15.521s dur=1352ms, freq=415Hz, sample=68, buffer_id=01:44
    db 94,1,228,3,58,54,1,4,247,0,58,1  ; n77 t=15.877s dur=996ms, freq=247Hz, sample=58, buffer_id=01:3A
    db 91,1,134,2,63,60,1,5,55,1,63,1  ; n78 t=16.227s dur=646ms, freq=311Hz, sample=63, buffer_id=01:3F
    db 65,1,44,1,68,56,1,3,159,1,68,1  ; n79 t=16.573s dur=300ms, freq=415Hz, sample=68, buffer_id=01:44
; t 16.8735 Sustain 0 (Instr 1)
    db 12,0,122,5,39,44,3,6,78,0,39,3  ; n80 t=16.894s dur=1402ms, freq=78Hz, sample=39, buffer_id=03:27
    db 0,0,72,5,67,38,2,7,136,1,67,2  ; n81 t=16.906s dur=1352ms, freq=392Hz, sample=67, buffer_id=02:43
    db 0,0,72,5,58,35,2,2,233,0,58,2  ; n82 t=16.906s dur=1352ms, freq=233Hz, sample=58, buffer_id=02:3A
    db 24,0,72,5,63,31,2,13,55,1,63,2  ; n83 t=16.906s dur=1352ms, freq=311Hz, sample=63, buffer_id=02:3F
    db 0,0,40,5,39,66,1,8,78,0,39,1  ; n84 t=16.929s dur=1320ms, freq=78Hz, sample=39, buffer_id=01:27
    db 94,1,40,5,67,66,1,10,136,1,67,1  ; n85 t=16.929s dur=1320ms, freq=392Hz, sample=67, buffer_id=01:43
; t 17.0588 Sustain 127 (Instr 1)
    db 97,1,202,3,46,56,1,0,117,0,46,1  ; n86 t=17.279s dur=970ms, freq=117Hz, sample=46, buffer_id=01:2E
    db 97,1,105,2,63,63,1,1,55,1,63,1  ; n87 t=17.632s dur=617ms, freq=311Hz, sample=63, buffer_id=01:3F
    db 59,1,8,1,65,60,1,3,93,1,65,1  ; n88 t=17.985s dur=264ms, freq=349Hz, sample=65, buffer_id=01:41
; t 18.2500 Sustain 0 (Instr 1)
    db 18,0,217,5,39,41,3,6,65,0,39,3  ; n89 t=18.300s dur=1497ms, freq=65Hz, sample=39, buffer_id=03:27
    db 0,0,72,5,67,32,2,7,136,1,67,2  ; n90 t=18.318s dur=1352ms, freq=392Hz, sample=67, buffer_id=02:43
    db 0,0,72,5,60,35,2,4,6,1,60,2  ; n91 t=18.318s dur=1352ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 24,0,72,5,63,35,2,13,74,1,63,2  ; n92 t=18.318s dur=1352ms, freq=330Hz, sample=63, buffer_id=02:3F
    db 0,0,181,5,67,65,1,10,136,1,67,1  ; n93 t=18.341s dur=1461ms, freq=392Hz, sample=67, buffer_id=01:43
    db 3,0,181,5,63,65,1,1,74,1,63,1  ; n94 t=18.341s dur=1461ms, freq=330Hz, sample=63, buffer_id=01:3F
    db 97,1,178,5,48,65,1,5,131,0,48,1  ; n95 t=18.344s dur=1458ms, freq=131Hz, sample=48, buffer_id=01:30
; t 18.4529 Sustain 127 (Instr 1)
    db 103,1,81,4,55,45,1,0,196,0,55,1  ; n96 t=18.697s dur=1105ms, freq=196Hz, sample=55, buffer_id=01:37
    db 100,1,234,2,68,62,1,2,159,1,68,1  ; n97 t=19.056s dur=746ms, freq=415Hz, sample=68, buffer_id=01:44
    db 53,1,135,1,58,57,1,3,233,0,58,1  ; n98 t=19.412s dur=391ms, freq=233Hz, sample=58, buffer_id=01:3A
    db 12,0,155,5,41,47,3,8,87,0,41,3  ; n99 t=19.721s dur=1435ms, freq=87Hz, sample=41, buffer_id=03:29
    db 0,0,72,5,57,30,2,9,220,0,57,2  ; n100 t=19.732s dur=1352ms, freq=220Hz, sample=57, buffer_id=02:39
    db 0,0,72,5,60,25,2,4,6,1,60,2  ; n101 t=19.732s dur=1352ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 35,0,72,5,65,38,2,11,93,1,65,2  ; n102 t=19.732s dur=1352ms, freq=349Hz, sample=65, buffer_id=02:41
    db 0,0,105,5,56,65,1,12,220,0,56,1  ; n103 t=19.768s dur=1385ms, freq=220Hz, sample=56, buffer_id=01:38
    db 0,0,105,5,41,65,1,14,87,0,41,1  ; n104 t=19.768s dur=1385ms, freq=87Hz, sample=41, buffer_id=01:29
    db 97,1,105,5,65,65,1,15,93,1,65,1  ; n105 t=19.768s dur=1385ms, freq=349Hz, sample=65, buffer_id=01:41
; t 19.8029 Sustain 0 (Instr 1)
; t 19.9735 Sustain 127 (Instr 1)
    db 97,1,8,4,48,54,1,0,131,0,48,1  ; n106 t=20.121s dur=1032ms, freq=131Hz, sample=48, buffer_id=01:30
    db 82,1,167,2,62,65,1,1,38,1,62,1  ; n107 t=20.474s dur=679ms, freq=294Hz, sample=62, buffer_id=01:3E
    db 64,1,85,1,63,64,1,2,55,1,63,1  ; n108 t=20.812s dur=341ms, freq=311Hz, sample=63, buffer_id=01:3F
    db 12,0,167,5,39,36,3,3,58,0,39,3  ; n109 t=21.132s dur=1447ms, freq=58Hz, sample=39, buffer_id=03:27
    db 0,0,72,5,65,36,2,11,93,1,65,2  ; n110 t=21.144s dur=1352ms, freq=349Hz, sample=65, buffer_id=02:41
    db 0,0,72,5,56,35,2,5,208,0,56,2  ; n111 t=21.144s dur=1352ms, freq=208Hz, sample=56, buffer_id=02:38
    db 29,0,72,5,62,30,2,6,38,1,62,2  ; n112 t=21.144s dur=1352ms, freq=294Hz, sample=62, buffer_id=02:3E
; t 21.1529 Sustain 0 (Instr 1)
    db 0,0,137,5,46,65,1,7,117,0,46,1  ; n113 t=21.174s dur=1417ms, freq=117Hz, sample=46, buffer_id=01:2E
    db 0,0,137,5,65,65,1,15,93,1,65,1  ; n114 t=21.174s dur=1417ms, freq=349Hz, sample=65, buffer_id=01:41
    db 91,1,137,5,62,65,1,1,38,1,62,1  ; n115 t=21.174s dur=1417ms, freq=294Hz, sample=62, buffer_id=01:3E
; t 21.3529 Sustain 127 (Instr 1)
    db 103,1,46,4,53,48,1,0,175,0,53,1  ; n116 t=21.521s dur=1070ms, freq=175Hz, sample=53, buffer_id=01:35
    db 94,1,199,2,67,64,1,2,136,1,67,1  ; n117 t=21.879s dur=711ms, freq=392Hz, sample=67, buffer_id=01:43
    db 56,1,105,1,56,53,1,4,208,0,56,1  ; n118 t=22.229s dur=361ms, freq=208Hz, sample=56, buffer_id=01:38
    db 12,0,46,9,39,46,3,3,78,0,39,3  ; n119 t=22.541s dur=2350ms, freq=78Hz, sample=39, buffer_id=03:27
    db 0,0,69,8,58,24,2,8,233,0,58,2  ; n120 t=22.553s dur=2117ms, freq=233Hz, sample=58, buffer_id=02:3A
    db 0,0,69,8,55,27,2,9,196,0,55,2  ; n121 t=22.553s dur=2117ms, freq=196Hz, sample=55, buffer_id=02:37
    db 32,0,69,8,63,37,2,10,55,1,63,2  ; n122 t=22.553s dur=2117ms, freq=311Hz, sample=63, buffer_id=02:3F
    db 0,0,228,9,39,62,1,12,78,0,39,1  ; n123 t=22.585s dur=2532ms, freq=78Hz, sample=39, buffer_id=01:27
    db 103,1,228,9,63,62,1,13,55,1,63,1  ; n124 t=22.585s dur=2532ms, freq=311Hz, sample=63, buffer_id=01:3F
; t 22.5912 Sustain 0 (Instr 1)
; t 22.8029 Sustain 127 (Instr 1)
    db 88,1,125,8,46,50,1,0,117,0,46,1  ; n125 t=22.944s dur=2173ms, freq=117Hz, sample=46, buffer_id=01:2E
    db 97,1,37,7,51,52,1,1,156,0,51,1  ; n126 t=23.288s dur=1829ms, freq=156Hz, sample=51, buffer_id=01:33
    db 109,1,196,5,55,50,1,2,196,0,55,1  ; n127 t=23.641s dur=1476ms, freq=196Hz, sample=55, buffer_id=01:37
    db 88,5,87,4,63,43,1,13,55,1,63,1  ; n128 t=24.006s dur=1111ms, freq=311Hz, sample=63, buffer_id=01:3F
; t 25.1176 Sustain 0 (Instr 1)
    db 6,0,61,5,39,45,3,0,78,0,39,3  ; n129 t=25.373s dur=1341ms, freq=78Hz, sample=39, buffer_id=03:27
    db 0,0,72,5,63,32,2,1,55,1,63,2  ; n130 t=25.379s dur=1352ms, freq=311Hz, sample=63, buffer_id=02:3F
    db 3,0,72,5,70,38,2,2,210,1,70,2  ; n131 t=25.379s dur=1352ms, freq=466Hz, sample=70, buffer_id=02:46
    db 15,0,72,5,67,27,2,3,136,1,67,2  ; n132 t=25.382s dur=1352ms, freq=392Hz, sample=67, buffer_id=02:43
    db 3,0,143,5,63,57,1,4,55,1,63,1  ; n133 t=25.397s dur=1423ms, freq=311Hz, sample=63, buffer_id=01:3F
    db 100,1,140,5,39,57,1,5,78,0,39,1  ; n134 t=25.400s dur=1420ms, freq=78Hz, sample=39, buffer_id=01:27
; t 25.4588 Sustain 127 (Instr 1)
    db 91,1,40,4,46,48,1,6,117,0,46,1  ; n135 t=25.756s dur=1064ms, freq=117Hz, sample=46, buffer_id=01:2E
    db 97,1,205,2,51,53,1,7,156,0,51,1  ; n136 t=26.103s dur=717ms, freq=156Hz, sample=51, buffer_id=01:33
    db 56,1,108,1,55,46,1,8,196,0,55,1  ; n137 t=26.456s dur=364ms, freq=196Hz, sample=55, buffer_id=01:37
    db 21,0,243,5,39,46,3,0,65,0,39,3  ; n138 t=26.768s dur=1523ms, freq=65Hz, sample=39, buffer_id=03:27
    db 0,0,72,5,67,27,2,3,136,1,67,2  ; n139 t=26.788s dur=1352ms, freq=392Hz, sample=67, buffer_id=02:43
    db 0,0,72,5,72,37,2,9,11,2,72,2  ; n140 t=26.788s dur=1352ms, freq=523Hz, sample=72, buffer_id=02:48
    db 24,0,72,5,75,39,2,10,110,2,75,2  ; n141 t=26.788s dur=1352ms, freq=622Hz, sample=75, buffer_id=02:4B
    db 6,0,102,5,75,54,1,11,110,2,75,1  ; n142 t=26.812s dur=1382ms, freq=622Hz, sample=75, buffer_id=01:4B
    db 91,1,96,5,48,54,1,12,131,0,48,1  ; n143 t=26.818s dur=1376ms, freq=131Hz, sample=48, buffer_id=01:30
; t 26.8206 Sustain 0 (Instr 1)
; t 27.0176 Sustain 127 (Instr 1)
    db 103,1,5,4,55,45,1,1,196,0,55,1  ; n144 t=27.165s dur=1029ms, freq=196Hz, sample=55, buffer_id=01:37
    db 94,1,158,2,60,52,1,2,6,1,60,1  ; n145 t=27.523s dur=670ms, freq=262Hz, sample=60, buffer_id=01:3C
    db 62,1,64,1,63,50,1,4,55,1,63,1  ; n146 t=27.873s dur=320ms, freq=311Hz, sample=63, buffer_id=01:3F
    db 12,0,101,11,43,38,3,5,98,0,43,3  ; n147 t=28.191s dur=2917ms, freq=98Hz, sample=43, buffer_id=03:2B
; t 28.1941 Sustain 0 (Instr 1)
    db 0,0,10,8,67,24,2,3,136,1,67,2  ; n148 t=28.203s dur=2058ms, freq=392Hz, sample=67, buffer_id=02:43
    db 0,0,10,8,74,39,2,6,75,2,74,2  ; n149 t=28.203s dur=2058ms, freq=587Hz, sample=74, buffer_id=02:4A
    db 24,0,10,8,70,33,2,7,210,1,70,2  ; n150 t=28.203s dur=2058ms, freq=466Hz, sample=70, buffer_id=02:46
    db 0,0,16,11,74,57,1,8,75,2,74,1  ; n151 t=28.227s dur=2832ms, freq=587Hz, sample=74, buffer_id=01:4A
    db 97,1,16,11,43,57,1,13,98,0,43,1  ; n152 t=28.227s dur=2832ms, freq=98Hz, sample=43, buffer_id=01:2B
; t 28.3647 Sustain 127 (Instr 1)
    db 94,1,175,9,50,46,1,0,147,0,50,1  ; n153 t=28.579s dur=2479ms, freq=147Hz, sample=50, buffer_id=01:32
    db 100,1,81,8,70,55,1,1,210,1,70,1  ; n154 t=28.929s dur=2129ms, freq=466Hz, sample=70, buffer_id=01:46
    db 94,1,237,6,72,51,1,2,11,2,72,1  ; n155 t=29.285s dur=1773ms, freq=523Hz, sample=72, buffer_id=01:48
    db 100,1,143,5,74,54,1,8,75,2,74,1  ; n156 t=29.635s dur=1423ms, freq=587Hz, sample=74, buffer_id=01:4A
    db 73,1,43,4,58,43,1,4,233,0,58,1  ; n157 t=29.991s dur=1067ms, freq=233Hz, sample=58, buffer_id=01:3A
    db 0,0,135,2,67,27,2,3,136,1,67,2  ; n158 t=30.321s dur=647ms, freq=392Hz, sample=67, buffer_id=02:43
    db 0,0,135,2,70,34,2,7,210,1,70,2  ; n159 t=30.321s dur=647ms, freq=466Hz, sample=70, buffer_id=02:46
    db 24,0,135,2,72,42,2,9,42,2,72,2  ; n160 t=30.321s dur=647ms, freq=554Hz, sample=72, buffer_id=02:48
    db 94,1,202,2,75,54,1,10,110,2,75,1  ; n161 t=30.344s dur=714ms, freq=622Hz, sample=75, buffer_id=01:4B
    db 71,1,108,1,60,46,1,6,21,1,60,1  ; n162 t=30.694s dur=364ms, freq=277Hz, sample=60, buffer_id=01:3C
    db 6,0,13,11,44,39,3,11,104,0,44,3  ; n163 t=31.021s dur=2829ms, freq=104Hz, sample=44, buffer_id=03:2C
    db 0,0,72,5,68,35,2,12,159,1,68,2  ; n164 t=31.026s dur=1352ms, freq=415Hz, sample=68, buffer_id=02:44
    db 6,0,72,5,72,34,2,9,11,2,72,2  ; n165 t=31.026s dur=1352ms, freq=523Hz, sample=72, buffer_id=02:48
    db 15,0,72,5,63,34,2,14,55,1,63,2  ; n166 t=31.032s dur=1352ms, freq=311Hz, sample=63, buffer_id=02:3F
    db 3,0,231,10,44,60,1,15,104,0,44,1  ; n167 t=31.047s dur=2791ms, freq=104Hz, sample=44, buffer_id=01:2C
    db 94,1,228,10,63,60,1,16,55,1,63,1  ; n168 t=31.050s dur=2788ms, freq=311Hz, sample=63, buffer_id=01:3F
; t 31.0588 Sustain 0 (Instr 1)
; t 31.2412 Sustain 127 (Instr 1)
    db 97,1,134,9,51,48,1,0,156,0,51,1  ; n169 t=31.400s dur=2438ms, freq=156Hz, sample=51, buffer_id=01:33
    db 103,1,37,8,56,51,1,1,208,0,56,1  ; n170 t=31.753s dur=2085ms, freq=208Hz, sample=56, buffer_id=01:38
    db 71,1,190,6,60,43,1,2,6,1,60,1  ; n171 t=32.112s dur=1726ms, freq=262Hz, sample=60, buffer_id=01:3C
    db 0,0,72,5,72,39,2,9,11,2,72,2  ; n172 t=32.438s dur=1352ms, freq=523Hz, sample=72, buffer_id=02:48
    db 3,0,72,5,68,25,2,12,159,1,68,2  ; n173 t=32.438s dur=1352ms, freq=415Hz, sample=68, buffer_id=02:44
    db 18,0,72,5,63,27,2,14,55,1,63,2  ; n174 t=32.441s dur=1352ms, freq=311Hz, sample=63, buffer_id=02:3F
    db 97,1,99,5,72,57,1,3,11,2,72,1  ; n175 t=32.459s dur=1379ms, freq=523Hz, sample=72, buffer_id=01:48
    db 97,1,2,4,60,43,1,2,6,1,60,1  ; n176 t=32.812s dur=1026ms, freq=262Hz, sample=60, buffer_id=01:3C
    db 91,1,161,2,63,53,1,16,55,1,63,1  ; n177 t=33.165s dur=673ms, freq=311Hz, sample=63, buffer_id=01:3F
    db 68,1,70,1,68,55,1,4,159,1,68,1  ; n178 t=33.512s dur=326ms, freq=415Hz, sample=68, buffer_id=01:44
    db 15,0,184,11,43,35,3,5,98,0,43,3  ; n179 t=33.835s dur=3000ms, freq=98Hz, sample=43, buffer_id=03:2B
; t 33.8382 Sustain 0 (Instr 1)
    db 0,0,204,10,63,35,2,14,55,1,63,2  ; n180 t=33.850s dur=2764ms, freq=311Hz, sample=63, buffer_id=02:3F
    db 0,0,204,10,70,38,2,6,210,1,70,2  ; n181 t=33.850s dur=2764ms, freq=466Hz, sample=70, buffer_id=02:46
    db 21,0,204,10,67,30,2,7,136,1,67,2  ; n182 t=33.850s dur=2764ms, freq=392Hz, sample=67, buffer_id=02:43
    db 0,0,239,10,43,59,1,8,98,0,43,1  ; n183 t=33.871s dur=2799ms, freq=98Hz, sample=43, buffer_id=01:2B
    db 97,1,239,10,70,59,1,10,210,1,70,1  ; n184 t=33.871s dur=2799ms, freq=466Hz, sample=70, buffer_id=01:46
; t 34.0353 Sustain 127 (Instr 1)
    db 97,1,143,9,51,48,1,0,156,0,51,1  ; n185 t=34.224s dur=2447ms, freq=156Hz, sample=51, buffer_id=01:33
    db 94,1,46,8,55,41,1,1,196,0,55,1  ; n186 t=34.577s dur=2094ms, freq=196Hz, sample=55, buffer_id=01:37
    db 97,1,208,6,58,42,1,2,233,0,58,1  ; n187 t=34.926s dur=1744ms, freq=233Hz, sample=58, buffer_id=01:3A
    db 100,1,111,5,67,48,1,3,136,1,67,1  ; n188 t=35.279s dur=1391ms, freq=392Hz, sample=67, buffer_id=01:43
    db 94,1,11,4,58,39,1,2,233,0,58,1  ; n189 t=35.635s dur=1035ms, freq=233Hz, sample=58, buffer_id=01:3A
    db 91,1,173,2,63,47,1,4,55,1,63,1  ; n190 t=35.985s dur=685ms, freq=311Hz, sample=63, buffer_id=01:3F
    db 85,1,82,1,58,45,1,2,233,0,58,1  ; n191 t=36.332s dur=338ms, freq=233Hz, sample=58, buffer_id=01:3A
; t 36.6706 Sustain 0 (Instr 1)
    db 0,0,72,5,60,33,2,9,6,1,60,2  ; n192 t=36.673s dur=1352ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 0,0,72,5,63,24,2,14,55,1,63,2  ; n193 t=36.673s dur=1352ms, freq=311Hz, sample=63, buffer_id=02:3F
    db 6,0,72,5,68,43,2,11,159,1,68,2  ; n194 t=36.673s dur=1352ms, freq=415Hz, sample=68, buffer_id=02:44
    db 9,0,1,11,44,44,3,12,104,0,44,3  ; n195 t=36.679s dur=2817ms, freq=104Hz, sample=44, buffer_id=03:2C
    db 6,0,25,11,60,59,1,13,6,1,60,1  ; n196 t=36.688s dur=2841ms, freq=262Hz, sample=60, buffer_id=01:3C
    db 91,1,19,11,44,59,1,15,104,0,44,1  ; n197 t=36.694s dur=2835ms, freq=104Hz, sample=44, buffer_id=01:2C
; t 36.8823 Sustain 127 (Instr 1)
    db 103,1,184,9,51,37,1,0,156,0,51,1  ; n198 t=37.041s dur=2488ms, freq=156Hz, sample=51, buffer_id=01:33
    db 100,1,81,8,56,45,1,1,208,0,56,1  ; n199 t=37.400s dur=2129ms, freq=208Hz, sample=56, buffer_id=01:38
    db 70,1,237,6,60,33,1,13,6,1,60,1  ; n200 t=37.756s dur=1773ms, freq=262Hz, sample=60, buffer_id=01:3C
    db 0,0,72,5,63,22,2,14,55,1,63,2  ; n201 t=38.082s dur=1352ms, freq=311Hz, sample=63, buffer_id=02:3F
    db 0,0,72,5,68,44,2,11,159,1,68,2  ; n202 t=38.082s dur=1352ms, freq=415Hz, sample=68, buffer_id=02:44
    db 27,0,72,5,58,33,2,2,247,0,58,2  ; n203 t=38.082s dur=1352ms, freq=247Hz, sample=58, buffer_id=02:3A
    db 100,1,140,5,68,58,1,3,159,1,68,1  ; n204 t=38.109s dur=1420ms, freq=415Hz, sample=68, buffer_id=01:44
    db 106,1,40,4,58,52,1,4,247,0,58,1  ; n205 t=38.465s dur=1064ms, freq=247Hz, sample=58, buffer_id=01:3A
    db 85,1,190,2,63,46,1,5,55,1,63,1  ; n206 t=38.827s dur=702ms, freq=311Hz, sample=63, buffer_id=01:3F
    db 68,1,105,1,68,51,1,3,159,1,68,1  ; n207 t=39.168s dur=361ms, freq=415Hz, sample=68, buffer_id=01:44
    db 6,0,214,5,39,48,3,6,78,0,39,3  ; n208 t=39.491s dur=1494ms, freq=78Hz, sample=39, buffer_id=03:27
    db 0,0,72,5,67,34,2,7,136,1,67,2  ; n209 t=39.497s dur=1352ms, freq=392Hz, sample=67, buffer_id=02:43
    db 0,0,72,5,58,30,2,2,233,0,58,2  ; n210 t=39.497s dur=1352ms, freq=233Hz, sample=58, buffer_id=02:3A
    db 29,0,72,5,63,27,2,14,55,1,63,2  ; n211 t=39.497s dur=1352ms, freq=311Hz, sample=63, buffer_id=02:3F
    db 9,0,99,5,67,61,1,8,136,1,67,1  ; n212 t=39.526s dur=1379ms, freq=392Hz, sample=67, buffer_id=01:43
; t 39.5294 Sustain 0 (Instr 1)
    db 94,1,90,5,39,61,1,9,78,0,39,1  ; n213 t=39.535s dur=1370ms, freq=78Hz, sample=39, buffer_id=01:27
; t 39.7147 Sustain 127 (Instr 1)
    db 103,1,252,3,46,53,1,0,117,0,46,1  ; n214 t=39.885s dur=1020ms, freq=117Hz, sample=46, buffer_id=01:2E
    db 94,1,149,2,63,57,1,1,55,1,63,1  ; n215 t=40.244s dur=661ms, freq=311Hz, sample=63, buffer_id=01:3F
    db 56,1,55,1,65,45,1,3,93,1,65,1  ; n216 t=40.594s dur=311ms, freq=349Hz, sample=65, buffer_id=01:41
    db 0,0,72,5,67,35,2,7,136,1,67,2  ; n217 t=40.906s dur=1352ms, freq=392Hz, sample=67, buffer_id=02:43
    db 0,0,72,5,60,29,2,4,6,1,60,2  ; n218 t=40.906s dur=1352ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 6,0,72,5,63,34,2,14,74,1,63,2  ; n219 t=40.906s dur=1352ms, freq=330Hz, sample=63, buffer_id=02:3F
; t 40.9059 Sustain 0 (Instr 1)
    db 32,0,199,5,39,43,3,6,65,0,39,3  ; n220 t=40.912s dur=1479ms, freq=65Hz, sample=39, buffer_id=03:27
    db 3,0,152,5,67,57,1,8,136,1,67,1  ; n221 t=40.944s dur=1432ms, freq=392Hz, sample=67, buffer_id=01:43
    db 3,0,149,5,63,48,1,1,74,1,63,1  ; n222 t=40.947s dur=1429ms, freq=330Hz, sample=63, buffer_id=01:3F
    db 97,1,146,5,48,41,1,5,131,0,48,1  ; n223 t=40.950s dur=1426ms, freq=131Hz, sample=48, buffer_id=01:30
; t 41.1088 Sustain 127 (Instr 1)
    db 88,1,49,4,55,43,1,0,196,0,55,1  ; n224 t=41.303s dur=1073ms, freq=196Hz, sample=55, buffer_id=01:37
    db 94,1,217,2,68,55,1,2,159,1,68,1  ; n225 t=41.647s dur=729ms, freq=415Hz, sample=68, buffer_id=01:44
    db 68,1,123,1,58,39,1,3,233,0,58,1  ; n226 t=41.997s dur=379ms, freq=233Hz, sample=58, buffer_id=01:3A
    db 0,0,72,5,57,28,2,9,220,0,57,2  ; n227 t=42.321s dur=1352ms, freq=220Hz, sample=57, buffer_id=02:39
    db 3,0,72,5,60,28,2,4,6,1,60,2  ; n228 t=42.321s dur=1352ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 3,0,72,5,65,42,2,10,93,1,65,2  ; n229 t=42.324s dur=1352ms, freq=349Hz, sample=65, buffer_id=02:41
    db 29,0,172,5,41,35,3,11,87,0,41,3  ; n230 t=42.326s dur=1452ms, freq=87Hz, sample=41, buffer_id=03:29
    db 0,0,72,5,56,37,1,12,220,0,56,1  ; n231 t=42.356s dur=1352ms, freq=220Hz, sample=56, buffer_id=01:38
    db 3,0,72,5,41,45,1,13,87,0,41,1  ; n232 t=42.356s dur=1352ms, freq=87Hz, sample=41, buffer_id=01:29
    db 94,1,69,5,65,60,1,15,93,1,65,1  ; n233 t=42.359s dur=1349ms, freq=349Hz, sample=65, buffer_id=01:41
; t 42.3764 Sustain 0 (Instr 1)
; t 42.5441 Sustain 127 (Instr 1)
    db 100,1,232,3,48,51,1,0,131,0,48,1  ; n234 t=42.709s dur=1000ms, freq=131Hz, sample=48, buffer_id=01:30
    db 88,1,132,2,62,54,1,1,38,1,62,1  ; n235 t=43.065s dur=644ms, freq=294Hz, sample=62, buffer_id=01:3E
    db 68,1,43,1,63,47,1,2,55,1,63,1  ; n236 t=43.409s dur=299ms, freq=311Hz, sample=63, buffer_id=01:3F
; t 43.7088 Sustain 0 (Instr 1)
    db 3,0,72,5,62,37,2,3,38,1,62,2  ; n237 t=43.732s dur=1352ms, freq=294Hz, sample=62, buffer_id=02:3E
    db 3,0,72,5,65,42,2,10,93,1,65,2  ; n238 t=43.735s dur=1352ms, freq=349Hz, sample=65, buffer_id=02:41
    db 9,0,184,5,39,32,3,5,58,0,39,3  ; n239 t=43.738s dur=1464ms, freq=58Hz, sample=39, buffer_id=03:27
    db 15,0,72,5,56,26,2,6,208,0,56,2  ; n240 t=43.747s dur=1352ms, freq=208Hz, sample=56, buffer_id=02:38
    db 0,0,143,5,65,59,1,15,93,1,65,1  ; n241 t=43.762s dur=1423ms, freq=349Hz, sample=65, buffer_id=01:41
    db 3,0,143,5,62,52,1,1,38,1,62,1  ; n242 t=43.762s dur=1423ms, freq=294Hz, sample=62, buffer_id=01:3E
    db 94,1,140,5,46,53,1,7,117,0,46,1  ; n243 t=43.765s dur=1420ms, freq=117Hz, sample=46, buffer_id=01:2E
; t 43.9088 Sustain 127 (Instr 1)
    db 100,1,46,4,53,38,1,0,175,0,53,1  ; n244 t=44.115s dur=1070ms, freq=175Hz, sample=53, buffer_id=01:35
    db 97,1,214,2,67,59,1,2,136,1,67,1  ; n245 t=44.471s dur=726ms, freq=392Hz, sample=67, buffer_id=01:43
    db 65,1,105,1,56,51,1,4,208,0,56,1  ; n246 t=44.824s dur=361ms, freq=208Hz, sample=56, buffer_id=01:38
    db 0,0,196,8,58,22,2,8,233,0,58,2  ; n247 t=45.144s dur=2244ms, freq=233Hz, sample=58, buffer_id=02:3A
    db 0,0,196,8,63,44,2,9,55,1,63,2  ; n248 t=45.144s dur=2244ms, freq=311Hz, sample=63, buffer_id=02:3F
    db 0,0,240,8,55,20,2,11,196,0,55,2  ; n249 t=45.144s dur=2288ms, freq=196Hz, sample=55, buffer_id=02:37
    db 29,0,96,9,39,41,3,5,78,0,39,3  ; n250 t=45.144s dur=2400ms, freq=78Hz, sample=39, buffer_id=03:27
    db 0,0,37,10,39,50,1,12,78,0,39,1  ; n251 t=45.173s dur=2597ms, freq=78Hz, sample=39, buffer_id=01:27
    db 103,1,37,10,63,53,1,13,55,1,63,1  ; n252 t=45.173s dur=2597ms, freq=311Hz, sample=63, buffer_id=01:3F
; t 45.1853 Sustain 0 (Instr 1)
; t 45.3559 Sustain 127 (Instr 1)
    db 91,1,190,8,46,43,1,0,117,0,46,1  ; n253 t=45.532s dur=2238ms, freq=117Hz, sample=46, buffer_id=01:2E
    db 97,1,99,7,51,43,1,1,156,0,51,1  ; n254 t=45.879s dur=1891ms, freq=156Hz, sample=51, buffer_id=01:33
    db 103,1,2,6,55,37,1,2,196,0,55,1  ; n255 t=46.232s dur=1538ms, freq=196Hz, sample=55, buffer_id=01:37
    db 38,4,155,4,63,43,1,13,55,1,63,1  ; n256 t=46.591s dur=1179ms, freq=311Hz, sample=63, buffer_id=01:3F
    db 62,1,91,1,70,55,1,3,210,1,70,1  ; n257 t=47.653s dur=347ms, freq=466Hz, sample=70, buffer_id=01:46
; t 47.7706 Sustain 0 (Instr 1)
    db 0,0,72,5,67,21,2,0,136,1,67,2  ; n258 t=47.971s dur=1352ms, freq=392Hz, sample=67, buffer_id=02:43
    db 0,0,72,5,63,28,2,1,55,1,63,2  ; n259 t=47.971s dur=1352ms, freq=311Hz, sample=63, buffer_id=02:3F
    db 6,0,72,5,70,29,2,2,210,1,70,2  ; n260 t=47.971s dur=1352ms, freq=466Hz, sample=70, buffer_id=02:46
    db 26,0,151,10,39,41,3,4,78,0,39,3  ; n261 t=47.976s dur=2711ms, freq=78Hz, sample=39, buffer_id=03:27
    db 3,0,195,10,67,50,1,5,136,1,67,1  ; n262 t=48.003s dur=2755ms, freq=392Hz, sample=67, buffer_id=01:43
    db 94,1,192,10,51,56,1,6,156,0,51,1  ; n263 t=48.006s dur=2752ms, freq=156Hz, sample=51, buffer_id=01:33
; t 48.0706 Sustain 127 (Instr 1)
    db 97,1,98,9,70,61,1,3,210,1,70,1  ; n264 t=48.356s dur=2402ms, freq=466Hz, sample=70, buffer_id=01:46
    db 0,0,2,8,67,60,1,5,136,1,67,1  ; n265 t=48.709s dur=2050ms, freq=392Hz, sample=67, buffer_id=01:43
    db 91,1,2,8,58,47,1,7,233,0,58,1  ; n266 t=48.709s dur=2050ms, freq=233Hz, sample=58, buffer_id=01:3A
    db 64,1,166,6,70,43,1,3,210,1,70,1  ; n267 t=49.056s dur=1702ms, freq=466Hz, sample=70, buffer_id=01:46
    db 0,0,72,5,67,31,2,0,136,1,67,2  ; n268 t=49.376s dur=1352ms, freq=392Hz, sample=67, buffer_id=02:43
    db 0,0,72,5,63,32,2,1,55,1,63,2  ; n269 t=49.376s dur=1352ms, freq=311Hz, sample=63, buffer_id=02:3F
    db 27,0,72,5,70,34,2,2,210,1,70,2  ; n270 t=49.376s dur=1352ms, freq=466Hz, sample=70, buffer_id=02:46
    db 6,0,75,5,67,53,1,5,136,1,67,1  ; n271 t=49.403s dur=1355ms, freq=392Hz, sample=67, buffer_id=01:43
    db 94,1,70,5,60,30,1,8,6,1,60,1  ; n272 t=49.409s dur=1350ms, freq=262Hz, sample=60, buffer_id=01:3C
    db 94,1,232,3,70,46,1,3,210,1,70,1  ; n273 t=49.759s dur=1000ms, freq=466Hz, sample=70, buffer_id=01:46
    db 0,0,137,2,58,41,1,7,233,0,58,1  ; n274 t=50.109s dur=649ms, freq=233Hz, sample=58, buffer_id=01:3A
    db 97,1,137,2,67,55,1,5,136,1,67,1  ; n275 t=50.109s dur=649ms, freq=392Hz, sample=67, buffer_id=01:43
    db 53,1,64,1,70,53,1,3,210,1,70,1  ; n276 t=50.462s dur=320ms, freq=466Hz, sample=70, buffer_id=01:46
; t 50.7588 Sustain 0 (Instr 1)
    db 18,0,134,8,41,36,3,9,87,0,41,3  ; n277 t=50.771s dur=2182ms, freq=87Hz, sample=41, buffer_id=03:29
    db 3,0,10,8,68,36,2,10,159,1,68,2  ; n278 t=50.788s dur=2058ms, freq=415Hz, sample=68, buffer_id=02:44
    db 0,0,10,8,65,31,2,11,93,1,65,2  ; n279 t=50.791s dur=2058ms, freq=349Hz, sample=65, buffer_id=02:41
    db 20,0,10,8,72,34,2,12,11,2,72,2  ; n280 t=50.791s dur=2058ms, freq=523Hz, sample=72, buffer_id=02:48
    db 3,0,187,10,68,60,1,13,159,1,68,1  ; n281 t=50.812s dur=2747ms, freq=415Hz, sample=68, buffer_id=01:44
    db 94,1,184,10,53,60,1,14,175,0,53,1  ; n282 t=50.815s dur=2744ms, freq=175Hz, sample=53, buffer_id=01:35
; t 50.9853 Sustain 127 (Instr 1)
    db 94,1,90,9,70,42,1,0,210,1,70,1  ; n283 t=51.165s dur=2394ms, freq=466Hz, sample=70, buffer_id=01:46
    db 3,0,252,7,68,54,1,13,159,1,68,1  ; n284 t=51.515s dur=2044ms, freq=415Hz, sample=68, buffer_id=01:44
    db 97,1,249,7,56,23,1,1,208,0,56,1  ; n285 t=51.518s dur=2041ms, freq=208Hz, sample=56, buffer_id=01:38
    db 91,1,152,6,70,43,1,0,210,1,70,1  ; n286 t=51.871s dur=1688ms, freq=466Hz, sample=70, buffer_id=01:46
    db 3,0,61,5,68,57,1,13,159,1,68,1  ; n287 t=52.218s dur=1341ms, freq=415Hz, sample=68, buffer_id=01:44
    db 94,1,58,5,58,43,1,2,233,0,58,1  ; n288 t=52.221s dur=1338ms, freq=233Hz, sample=58, buffer_id=01:3A
    db 68,1,220,3,70,53,1,0,210,1,70,1  ; n289 t=52.571s dur=988ms, freq=466Hz, sample=70, buffer_id=01:46
    db 12,0,64,3,39,40,3,3,58,0,39,3  ; n290 t=52.894s dur=832ms, freq=58Hz, sample=39, buffer_id=03:27
    db 0,0,135,2,68,35,2,10,159,1,68,2  ; n291 t=52.906s dur=647ms, freq=415Hz, sample=68, buffer_id=02:44
    db 3,0,135,2,70,41,2,4,210,1,70,2  ; n292 t=52.906s dur=647ms, freq=466Hz, sample=70, buffer_id=02:46
    db 15,0,135,2,65,22,2,11,93,1,65,2  ; n293 t=52.909s dur=647ms, freq=349Hz, sample=65, buffer_id=02:41
    db 6,0,123,2,68,61,1,13,159,1,68,1  ; n294 t=52.923s dur=635ms, freq=415Hz, sample=68, buffer_id=01:44
    db 88,1,117,2,62,61,1,5,38,1,62,1  ; n295 t=52.929s dur=629ms, freq=294Hz, sample=62, buffer_id=01:3E
    db 82,1,46,1,70,55,1,0,210,1,70,1  ; n296 t=53.273s dur=302ms, freq=466Hz, sample=70, buffer_id=01:46
; t 53.5588 Sustain 0 (Instr 1)
    db 0,0,72,5,63,34,2,6,55,1,63,2  ; n297 t=53.612s dur=1352ms, freq=311Hz, sample=63, buffer_id=02:3F
    db 0,0,72,5,72,36,2,7,11,2,72,2  ; n298 t=53.612s dur=1352ms, freq=523Hz, sample=72, buffer_id=02:48
    db 0,0,72,5,67,35,2,8,136,1,67,2  ; n299 t=53.612s dur=1352ms, freq=392Hz, sample=67, buffer_id=02:43
    db 24,0,13,11,39,43,3,3,78,0,39,3  ; n300 t=53.612s dur=2829ms, freq=78Hz, sample=39, buffer_id=03:27
    db 97,1,87,6,72,57,1,9,11,2,72,1  ; n301 t=53.635s dur=1623ms, freq=523Hz, sample=72, buffer_id=01:48
; t 53.9000 Sustain 127 (Instr 1)
    db 91,1,246,4,51,52,1,0,156,0,51,1  ; n302 t=53.988s dur=1270ms, freq=156Hz, sample=51, buffer_id=01:33
    db 97,1,155,3,55,34,1,1,196,0,55,1  ; n303 t=54.335s dur=923ms, freq=196Hz, sample=55, buffer_id=01:37
    db 79,1,58,2,58,43,1,2,233,0,58,1  ; n304 t=54.688s dur=570ms, freq=233Hz, sample=58, buffer_id=01:3A
    db 0,0,72,5,63,32,2,6,55,1,63,2  ; n305 t=55.023s dur=1352ms, freq=311Hz, sample=63, buffer_id=02:3F
    db 6,0,72,5,72,31,2,7,11,2,72,2  ; n306 t=55.023s dur=1352ms, freq=523Hz, sample=72, buffer_id=02:48
    db 12,0,72,5,67,35,2,8,136,1,67,2  ; n307 t=55.029s dur=1352ms, freq=392Hz, sample=67, buffer_id=02:43
    db 94,1,62,16,72,53,1,9,11,2,72,1  ; n308 t=55.041s dur=4158ms, freq=523Hz, sample=72, buffer_id=01:48
; t 55.2588 Sustain 0 (Instr 1)
    db 103,1,17,4,55,42,1,1,196,0,55,1  ; n309 t=55.391s dur=1041ms, freq=196Hz, sample=55, buffer_id=01:37
; t 55.5117 Sustain 127 (Instr 1)
    db 97,1,170,2,58,50,1,0,233,0,58,1  ; n310 t=55.750s dur=682ms, freq=233Hz, sample=58, buffer_id=01:3A
    db 65,1,73,1,63,38,1,2,55,1,63,1  ; n311 t=56.103s dur=329ms, freq=311Hz, sample=63, buffer_id=01:3F
    db 12,0,172,9,39,30,3,3,58,0,39,3  ; n312 t=56.423s dur=2476ms, freq=58Hz, sample=39, buffer_id=03:27
; t 56.4323 Sustain 0 (Instr 1)
    db 0,0,69,8,72,32,2,7,11,2,72,2  ; n313 t=56.435s dur=2117ms, freq=523Hz, sample=72, buffer_id=02:48
    db 3,0,69,8,68,40,2,4,159,1,68,2  ; n314 t=56.435s dur=2117ms, freq=415Hz, sample=68, buffer_id=02:44
    db 21,0,69,8,62,25,2,5,38,1,62,2  ; n315 t=56.438s dur=2117ms, freq=294Hz, sample=62, buffer_id=02:3E
    db 94,1,111,5,65,41,1,10,93,1,65,1  ; n316 t=56.459s dur=1391ms, freq=349Hz, sample=65, buffer_id=01:41
; t 56.7411 Sustain 127 (Instr 1)
    db 91,1,17,4,62,33,1,0,38,1,62,1  ; n317 t=56.809s dur=1041ms, freq=294Hz, sample=62, buffer_id=01:3E
    db 100,1,182,2,58,38,1,1,233,0,58,1  ; n318 t=57.156s dur=694ms, freq=233Hz, sample=58, buffer_id=01:3A
    db 103,1,82,1,56,42,1,2,208,0,56,1  ; n319 t=57.512s dur=338ms, freq=208Hz, sample=56, buffer_id=01:38
; t 57.8500 Sustain 0 (Instr 1)
    db 44,4,49,5,53,32,1,6,175,0,53,1  ; n320 t=57.871s dur=1329ms, freq=175Hz, sample=53, buffer_id=01:35
; t 58.0176 Sustain 127 (Instr 1)
    db 65,1,88,1,70,46,1,0,210,1,70,1  ; n321 t=58.938s dur=344ms, freq=466Hz, sample=70, buffer_id=01:46
; t 59.2000 Sustain 0 (Instr 1)
    db 6,0,216,10,39,41,3,1,78,0,39,3  ; n322 t=59.259s dur=2776ms, freq=78Hz, sample=39, buffer_id=03:27
    db 0,0,72,5,63,26,2,2,55,1,63,2  ; n323 t=59.265s dur=1352ms, freq=311Hz, sample=63, buffer_id=02:3F
    db 0,0,72,5,70,23,2,3,210,1,70,2  ; n324 t=59.265s dur=1352ms, freq=466Hz, sample=70, buffer_id=02:46
    db 26,0,72,5,67,14,2,4,136,1,67,2  ; n325 t=59.265s dur=1352ms, freq=392Hz, sample=67, buffer_id=02:43
    db 9,0,195,10,67,56,1,5,136,1,67,1  ; n326 t=59.291s dur=2755ms, freq=392Hz, sample=67, buffer_id=01:43
    db 88,1,187,10,51,48,1,7,156,0,51,1  ; n327 t=59.300s dur=2747ms, freq=156Hz, sample=51, buffer_id=01:33
; t 59.4441 Sustain 127 (Instr 1)
    db 94,1,98,9,70,46,1,0,210,1,70,1  ; n328 t=59.644s dur=2402ms, freq=466Hz, sample=70, buffer_id=01:46
    db 3,0,4,8,67,49,1,5,136,1,67,1  ; n329 t=59.994s dur=2052ms, freq=392Hz, sample=67, buffer_id=01:43
    db 97,1,1,8,58,49,1,6,233,0,58,1  ; n330 t=59.997s dur=2049ms, freq=233Hz, sample=58, buffer_id=01:3A
    db 67,1,160,6,70,42,1,0,210,1,70,1  ; n331 t=60.350s dur=1696ms, freq=466Hz, sample=70, buffer_id=01:46
    db 0,0,72,5,67,18,2,4,136,1,67,2  ; n332 t=60.673s dur=1352ms, freq=392Hz, sample=67, buffer_id=02:43
    db 0,0,72,5,70,27,2,3,210,1,70,2  ; n333 t=60.673s dur=1352ms, freq=466Hz, sample=70, buffer_id=02:46
    db 24,0,72,5,63,29,2,2,55,1,63,2  ; n334 t=60.673s dur=1352ms, freq=311Hz, sample=63, buffer_id=02:3F
    db 6,0,69,5,67,49,1,5,136,1,67,1  ; n335 t=60.697s dur=1349ms, freq=392Hz, sample=67, buffer_id=01:43
    db 85,1,64,5,60,49,1,8,6,1,60,1  ; n336 t=60.703s dur=1344ms, freq=262Hz, sample=60, buffer_id=01:3C
    db 94,1,234,3,70,47,1,0,210,1,70,1  ; n337 t=61.044s dur=1002ms, freq=466Hz, sample=70, buffer_id=01:46
    db 0,0,140,2,58,52,1,6,233,0,58,1  ; n338 t=61.394s dur=652ms, freq=233Hz, sample=58, buffer_id=01:3A
    db 100,1,140,2,67,47,1,5,136,1,67,1  ; n339 t=61.394s dur=652ms, freq=392Hz, sample=67, buffer_id=01:43
    db 62,1,40,1,70,47,1,0,210,1,70,1  ; n340 t=61.750s dur=296ms, freq=466Hz, sample=70, buffer_id=01:46
; t 62.0470 Sustain 0 (Instr 1)
    db 15,0,145,11,39,40,3,1,65,0,39,3  ; n341 t=62.068s dur=2961ms, freq=65Hz, sample=39, buffer_id=03:27
    db 0,0,72,5,65,30,2,9,114,1,65,2  ; n342 t=62.082s dur=1352ms, freq=370Hz, sample=65, buffer_id=02:41
    db 0,0,72,5,72,25,2,10,11,2,72,2  ; n343 t=62.082s dur=1352ms, freq=523Hz, sample=72, buffer_id=02:48
    db 21,0,72,5,68,27,2,11,184,1,68,2  ; n344 t=62.082s dur=1352ms, freq=440Hz, sample=68, buffer_id=02:44
    db 0,0,225,10,68,57,1,12,184,1,68,1  ; n345 t=62.103s dur=2785ms, freq=440Hz, sample=68, buffer_id=01:44
    db 100,1,54,12,48,57,1,13,131,0,48,1  ; n346 t=62.103s dur=3126ms, freq=131Hz, sample=48, buffer_id=01:30
; t 62.2735 Sustain 127 (Instr 1)
    db 91,1,210,10,72,46,1,0,11,2,72,1  ; n347 t=62.459s dur=2770ms, freq=523Hz, sample=72, buffer_id=01:48
    db 3,0,119,9,51,51,1,2,156,0,51,1  ; n348 t=62.806s dur=2423ms, freq=156Hz, sample=51, buffer_id=01:33
    db 97,1,116,9,68,59,1,12,184,1,68,1  ; n349 t=62.809s dur=2420ms, freq=440Hz, sample=68, buffer_id=01:44
    db 79,1,19,8,72,42,1,0,11,2,72,1  ; n350 t=63.162s dur=2067ms, freq=523Hz, sample=72, buffer_id=01:48
    db 0,0,72,5,68,31,2,11,184,1,68,2  ; n351 t=63.497s dur=1352ms, freq=440Hz, sample=68, buffer_id=02:44
    db 0,0,72,5,65,34,2,9,114,1,65,2  ; n352 t=63.497s dur=1352ms, freq=370Hz, sample=65, buffer_id=02:41
    db 18,0,72,5,72,41,2,10,11,2,72,2  ; n353 t=63.497s dur=1352ms, freq=523Hz, sample=72, buffer_id=02:48
    db 0,0,178,6,68,56,1,12,184,1,68,1  ; n354 t=63.515s dur=1714ms, freq=440Hz, sample=68, buffer_id=01:44
    db 91,1,178,6,53,56,1,3,185,0,53,1  ; n355 t=63.515s dur=1714ms, freq=185Hz, sample=53, buffer_id=01:35
    db 97,1,87,5,72,46,1,0,11,2,72,1  ; n356 t=63.862s dur=1367ms, freq=523Hz, sample=72, buffer_id=01:48
    db 3,0,246,3,68,58,1,12,184,1,68,1  ; n357 t=64.215s dur=1014ms, freq=440Hz, sample=68, buffer_id=01:44
    db 97,1,243,3,60,58,1,4,6,1,60,1  ; n358 t=64.218s dur=1011ms, freq=262Hz, sample=60, buffer_id=01:3C
    db 79,1,146,2,72,53,1,0,11,2,72,1  ; n359 t=64.571s dur=658ms, freq=523Hz, sample=72, buffer_id=01:48
    db 3,0,23,17,41,39,3,5,87,0,41,3  ; n360 t=64.906s dur=4375ms, freq=87Hz, sample=41, buffer_id=03:29
    db 0,0,72,5,74,42,2,6,75,2,74,2  ; n361 t=64.909s dur=1352ms, freq=587Hz, sample=74, buffer_id=02:4A
    db 3,0,72,5,65,34,2,9,93,1,65,2  ; n362 t=64.909s dur=1352ms, freq=349Hz, sample=65, buffer_id=02:41
    db 15,0,72,5,68,20,2,11,159,1,68,2  ; n363 t=64.912s dur=1352ms, freq=415Hz, sample=68, buffer_id=02:44
    db 94,1,225,6,74,62,1,7,75,2,74,1  ; n364 t=64.926s dur=1761ms, freq=587Hz, sample=74, buffer_id=01:4A
; t 65.2294 Sustain 0 (Instr 1)
    db 94,1,131,5,53,53,1,3,175,0,53,1  ; n365 t=65.276s dur=1411ms, freq=175Hz, sample=53, buffer_id=01:35
; t 65.5235 Sustain 127 (Instr 1)
    db 100,1,37,4,56,58,1,0,208,0,56,1  ; n366 t=65.626s dur=1061ms, freq=208Hz, sample=56, buffer_id=01:38
    db 79,1,193,2,60,53,1,1,6,1,60,1  ; n367 t=65.982s dur=705ms, freq=262Hz, sample=60, buffer_id=01:3C
    db 0,0,72,5,74,40,2,6,75,2,74,2  ; n368 t=66.318s dur=1352ms, freq=587Hz, sample=74, buffer_id=02:4A
    db 6,0,72,5,65,33,2,9,93,1,65,2  ; n369 t=66.318s dur=1352ms, freq=349Hz, sample=65, buffer_id=02:41
    db 15,0,72,5,68,20,2,11,159,1,68,2  ; n370 t=66.323s dur=1352ms, freq=415Hz, sample=68, buffer_id=02:44
    db 103,1,246,5,74,61,1,7,75,2,74,1  ; n371 t=66.338s dur=1526ms, freq=587Hz, sample=74, buffer_id=01:4A
; t 66.6882 Sustain 0 (Instr 1)
    db 94,1,91,1,56,54,1,0,208,0,56,1  ; n372 t=66.697s dur=347ms, freq=208Hz, sample=56, buffer_id=01:38
    db 100,1,49,3,60,50,1,1,6,1,60,1  ; n373 t=67.047s dur=817ms, freq=262Hz, sample=60, buffer_id=01:3C
; t 67.0558 Sustain 127 (Instr 1)
    db 73,1,205,1,63,52,1,0,55,1,63,1  ; n374 t=67.403s dur=461ms, freq=311Hz, sample=63, buffer_id=01:3F
    db 0,0,91,5,77,39,2,2,186,2,77,2  ; n375 t=67.732s dur=1371ms, freq=698Hz, sample=77, buffer_id=02:4D
    db 0,0,91,5,65,31,2,9,93,1,65,2  ; n376 t=67.732s dur=1371ms, freq=349Hz, sample=65, buffer_id=02:41
    db 23,0,91,5,68,20,2,11,159,1,68,2  ; n377 t=67.732s dur=1371ms, freq=415Hz, sample=68, buffer_id=02:44
    db 100,1,82,6,77,59,1,3,186,2,77,1  ; n378 t=67.756s dur=1618ms, freq=698Hz, sample=77, buffer_id=01:4D
; t 67.8647 Sustain 0 (Instr 1)
    db 94,1,238,4,65,43,1,0,93,1,65,1  ; n379 t=68.112s dur=1262ms, freq=349Hz, sample=65, buffer_id=01:41
; t 68.3000 Sustain 127 (Instr 1)
    db 101,1,144,3,63,50,1,1,55,1,63,1  ; n380 t=68.462s dur=912ms, freq=311Hz, sample=63, buffer_id=01:3F
    db 91,1,43,2,60,42,1,4,6,1,60,1  ; n381 t=68.819s dur=555ms, freq=262Hz, sample=60, buffer_id=01:3C
    db 0,0,59,6,72,38,2,6,11,2,72,2  ; n382 t=69.166s dur=1595ms, freq=523Hz, sample=72, buffer_id=02:48
    db 0,0,59,6,68,38,2,11,159,1,68,2  ; n383 t=69.166s dur=1595ms, freq=415Hz, sample=68, buffer_id=02:44
    db 9,0,59,6,65,27,2,9,93,1,65,2  ; n384 t=69.166s dur=1595ms, freq=349Hz, sample=65, buffer_id=02:41
    db 19,0,230,6,39,36,3,7,58,0,39,3  ; n385 t=69.176s dur=1766ms, freq=58Hz, sample=39, buffer_id=03:27
    db 127,1,180,6,72,56,1,8,11,2,72,1  ; n386 t=69.195s dur=1716ms, freq=523Hz, sample=72, buffer_id=01:48
; t 69.3745 Sustain 0 (Instr 1)
    db 155,1,165,1,58,43,1,0,233,0,58,1  ; n387 t=69.578s dur=421ms, freq=233Hz, sample=58, buffer_id=01:3A
    db 169,1,153,3,56,45,1,1,208,0,56,1  ; n388 t=69.989s dur=921ms, freq=208Hz, sample=56, buffer_id=01:38
; t 70.0066 Sustain 127 (Instr 1)
    db 176,1,241,1,53,45,1,0,175,0,53,1  ; n389 t=70.414s dur=497ms, freq=175Hz, sample=53, buffer_id=01:35
    db 0,0,206,5,63,24,2,2,55,1,63,2  ; n390 t=70.846s dur=1486ms, freq=311Hz, sample=63, buffer_id=02:3F
    db 0,0,206,5,70,31,2,3,210,1,70,2  ; n391 t=70.846s dur=1486ms, freq=466Hz, sample=70, buffer_id=02:46
    db 15,0,206,5,67,21,2,4,136,1,67,2  ; n392 t=70.846s dur=1486ms, freq=392Hz, sample=67, buffer_id=02:43
    db 8,0,143,5,39,48,3,7,78,0,39,3  ; n393 t=70.861s dur=1423ms, freq=78Hz, sample=39, buffer_id=03:27
    db 0,0,15,6,39,62,1,5,78,0,39,1  ; n394 t=70.869s dur=1551ms, freq=78Hz, sample=39, buffer_id=01:27
    db 208,1,15,6,63,62,1,10,55,1,63,1  ; n395 t=70.869s dur=1551ms, freq=311Hz, sample=63, buffer_id=01:3F
; t 70.9112 Sustain 0 (Instr 1)
; t 71.2471 Sustain 127 (Instr 1)
    db 110,1,63,4,46,53,1,0,117,0,46,1  ; n396 t=71.333s dur=1087ms, freq=117Hz, sample=46, buffer_id=01:2E
    db 100,1,208,2,51,54,1,1,156,0,51,1  ; n397 t=71.699s dur=720ms, freq=156Hz, sample=51, buffer_id=01:33
    db 59,1,108,1,55,48,1,6,196,0,55,1  ; n398 t=72.055s dur=364ms, freq=196Hz, sample=55, buffer_id=01:37
    db 21,0,240,5,39,42,3,7,65,0,39,3  ; n399 t=72.370s dur=1520ms, freq=65Hz, sample=39, buffer_id=03:27
    db 3,0,72,5,67,14,2,4,136,1,67,2  ; n400 t=72.391s dur=1352ms, freq=392Hz, sample=67, buffer_id=02:43
    db 0,0,72,5,72,36,2,8,11,2,72,2  ; n401 t=72.394s dur=1352ms, freq=523Hz, sample=72, buffer_id=02:48
    db 15,0,72,5,75,35,2,9,110,2,75,2  ; n402 t=72.394s dur=1352ms, freq=622Hz, sample=75, buffer_id=02:4B
    db 3,0,108,5,75,60,1,11,110,2,75,1  ; n403 t=72.408s dur=1388ms, freq=622Hz, sample=75, buffer_id=01:4B
    db 94,1,105,5,48,60,1,12,131,0,48,1  ; n404 t=72.411s dur=1385ms, freq=131Hz, sample=48, buffer_id=01:30
; t 72.4200 Sustain 0 (Instr 1)
; t 72.6436 Sustain 127 (Instr 1)
    db 100,1,11,4,55,45,1,0,196,0,55,1  ; n405 t=72.761s dur=1035ms, freq=196Hz, sample=55, buffer_id=01:37
    db 94,1,167,2,60,52,1,1,6,1,60,1  ; n406 t=73.117s dur=679ms, freq=262Hz, sample=60, buffer_id=01:3C
    db 67,1,73,1,63,42,1,2,55,1,63,1  ; n407 t=73.467s dur=329ms, freq=311Hz, sample=63, buffer_id=01:3F
    db 9,0,66,11,43,41,3,3,98,0,43,3  ; n408 t=73.791s dur=2882ms, freq=98Hz, sample=43, buffer_id=03:2B
; t 73.7965 Sustain 0 (Instr 1)
    db 3,0,10,8,70,38,2,5,210,1,70,2  ; n409 t=73.799s dur=2058ms, freq=466Hz, sample=70, buffer_id=02:46
    db 0,0,10,8,74,38,2,6,75,2,74,2  ; n410 t=73.802s dur=2058ms, freq=587Hz, sample=74, buffer_id=02:4A
    db 18,0,10,8,67,30,2,4,136,1,67,2  ; n411 t=73.802s dur=2058ms, freq=392Hz, sample=67, buffer_id=02:43
    db 3,0,211,6,74,57,1,10,75,2,74,1  ; n412 t=73.820s dur=1747ms, freq=587Hz, sample=74, buffer_id=01:4A
    db 97,1,208,6,43,57,1,13,98,0,43,1  ; n413 t=73.823s dur=1744ms, freq=98Hz, sample=43, buffer_id=01:2B
; t 74.0083 Sustain 127 (Instr 1)
    db 97,1,111,5,50,43,1,0,147,0,50,1  ; n414 t=74.176s dur=1391ms, freq=147Hz, sample=50, buffer_id=01:32
    db 97,1,14,4,70,58,1,1,210,1,70,1  ; n415 t=74.529s dur=1038ms, freq=466Hz, sample=70, buffer_id=01:46
    db 100,1,173,2,72,51,1,2,11,2,72,1  ; n416 t=74.882s dur=685ms, freq=523Hz, sample=72, buffer_id=01:48
    db 103,1,211,5,74,54,1,10,75,2,74,1  ; n417 t=75.238s dur=1491ms, freq=587Hz, sample=74, buffer_id=01:4A
; t 75.5671 Sustain 0 (Instr 1)
    db 67,1,108,4,58,47,1,7,233,0,58,1  ; n418 t=75.597s dur=1132ms, freq=233Hz, sample=58, buffer_id=01:3A
; t 75.9171 Sustain 127 (Instr 1)
    db 0,0,135,2,70,37,2,5,210,1,70,2  ; n419 t=75.920s dur=647ms, freq=466Hz, sample=70, buffer_id=02:46
    db 0,0,135,2,72,44,2,0,42,2,72,2  ; n420 t=75.920s dur=647ms, freq=554Hz, sample=72, buffer_id=02:48
    db 32,0,135,2,67,25,2,4,136,1,67,2  ; n421 t=75.920s dur=647ms, freq=392Hz, sample=67, buffer_id=02:43
    db 97,1,8,3,75,52,1,1,110,2,75,1  ; n422 t=75.952s dur=776ms, freq=622Hz, sample=75, buffer_id=01:4B
    db 53,1,167,1,60,45,1,2,21,1,60,1  ; n423 t=76.305s dur=423ms, freq=277Hz, sample=60, buffer_id=01:3C
    db 15,0,248,10,44,41,3,6,104,0,44,3  ; n424 t=76.614s dur=2808ms, freq=104Hz, sample=44, buffer_id=03:2C
    db 0,0,72,5,68,40,2,8,159,1,68,2  ; n425 t=76.629s dur=1352ms, freq=415Hz, sample=68, buffer_id=02:44
    db 0,0,72,5,63,41,2,9,55,1,63,2  ; n426 t=76.629s dur=1352ms, freq=311Hz, sample=63, buffer_id=02:3F
    db 29,0,72,5,72,40,2,0,11,2,72,2  ; n427 t=76.629s dur=1352ms, freq=523Hz, sample=72, buffer_id=02:48
    db 3,0,231,10,63,61,1,11,55,1,63,1  ; n428 t=76.658s dur=2791ms, freq=311Hz, sample=63, buffer_id=01:3F
    db 94,1,228,10,44,57,1,12,104,0,44,1  ; n429 t=76.661s dur=2788ms, freq=104Hz, sample=44, buffer_id=01:2C
; t 76.7289 Sustain 0 (Instr 1)
; t 76.9524 Sustain 127 (Instr 1)
    db 97,1,134,9,51,51,1,1,156,0,51,1  ; n430 t=77.011s dur=2438ms, freq=156Hz, sample=51, buffer_id=01:33
    db 97,1,37,8,56,53,1,2,208,0,56,1  ; n431 t=77.364s dur=2085ms, freq=208Hz, sample=56, buffer_id=01:38
    db 65,1,196,6,60,41,1,3,6,1,60,1  ; n432 t=77.717s dur=1732ms, freq=262Hz, sample=60, buffer_id=01:3C
    db 0,0,72,5,72,35,2,0,11,2,72,2  ; n433 t=78.038s dur=1352ms, freq=523Hz, sample=72, buffer_id=02:48
    db 0,0,72,5,63,35,2,9,55,1,63,2  ; n434 t=78.038s dur=1352ms, freq=311Hz, sample=63, buffer_id=02:3F
    db 23,0,72,5,68,36,2,8,159,1,68,2  ; n435 t=78.038s dur=1352ms, freq=415Hz, sample=68, buffer_id=02:44
    db 94,1,108,5,72,59,1,4,11,2,72,1  ; n436 t=78.061s dur=1388ms, freq=523Hz, sample=72, buffer_id=01:48
    db 94,1,14,4,60,43,1,3,6,1,60,1  ; n437 t=78.411s dur=1038ms, freq=262Hz, sample=60, buffer_id=01:3C
    db 100,1,176,2,63,54,1,11,55,1,63,1  ; n438 t=78.761s dur=688ms, freq=311Hz, sample=63, buffer_id=01:3F
    db 53,1,76,1,68,43,1,5,159,1,68,1  ; n439 t=79.117s dur=332ms, freq=415Hz, sample=68, buffer_id=01:44
    db 18,0,86,11,43,39,3,7,98,0,43,3  ; n440 t=79.426s dur=2902ms, freq=98Hz, sample=43, buffer_id=03:2B
    db 0,0,204,10,70,37,2,10,210,1,70,2  ; n441 t=79.444s dur=2764ms, freq=466Hz, sample=70, buffer_id=02:46
    db 0,0,204,10,67,28,2,13,136,1,67,2  ; n442 t=79.444s dur=2764ms, freq=392Hz, sample=67, buffer_id=02:43
    db 26,0,204,10,63,31,2,9,55,1,63,2  ; n443 t=79.444s dur=2764ms, freq=311Hz, sample=63, buffer_id=02:3F
; t 79.4494 Sustain 0 (Instr 1)
    db 0,0,28,11,43,53,1,14,98,0,43,1  ; n444 t=79.470s dur=2844ms, freq=98Hz, sample=43, buffer_id=01:2B
    db 97,1,28,11,70,57,1,15,210,1,70,1  ; n445 t=79.470s dur=2844ms, freq=466Hz, sample=70, buffer_id=01:46
; t 79.6906 Sustain 127 (Instr 1)
    db 97,1,187,9,51,46,1,0,156,0,51,1  ; n446 t=79.823s dur=2491ms, freq=156Hz, sample=51, buffer_id=01:33
    db 94,1,90,8,55,52,1,1,196,0,55,1  ; n447 t=80.176s dur=2138ms, freq=196Hz, sample=55, buffer_id=01:37
    db 106,1,252,6,58,43,1,2,233,0,58,1  ; n448 t=80.526s dur=1788ms, freq=233Hz, sample=58, buffer_id=01:3A
    db 94,1,146,5,67,43,1,3,136,1,67,1  ; n449 t=80.888s dur=1426ms, freq=392Hz, sample=67, buffer_id=01:43
    db 97,1,52,4,58,34,1,2,233,0,58,1  ; n450 t=81.238s dur=1076ms, freq=233Hz, sample=58, buffer_id=01:3A
    db 94,1,211,2,63,43,1,4,55,1,63,1  ; n451 t=81.591s dur=723ms, freq=311Hz, sample=63, buffer_id=01:3F
    db 53,1,117,1,58,41,1,2,233,0,58,1  ; n452 t=81.941s dur=373ms, freq=233Hz, sample=58, buffer_id=01:3A
    db 18,0,45,11,44,37,3,5,104,0,44,3  ; n453 t=82.249s dur=2861ms, freq=104Hz, sample=44, buffer_id=03:2C
    db 0,0,72,5,60,33,2,6,6,1,60,2  ; n454 t=82.267s dur=1352ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 0,0,72,5,63,27,2,9,55,1,63,2  ; n455 t=82.267s dur=1352ms, freq=311Hz, sample=63, buffer_id=02:3F
    db 29,0,72,5,68,42,2,8,159,1,68,2  ; n456 t=82.267s dur=1352ms, freq=415Hz, sample=68, buffer_id=02:44
    db 6,0,248,10,60,51,1,11,6,1,60,1  ; n457 t=82.296s dur=2808ms, freq=262Hz, sample=60, buffer_id=01:3C
    db 88,1,242,10,44,51,1,12,104,0,44,1  ; n458 t=82.302s dur=2802ms, freq=104Hz, sample=44, buffer_id=01:2C
; t 82.3141 Sustain 0 (Instr 1)
; t 82.5406 Sustain 127 (Instr 1)
    db 103,1,154,9,51,38,1,0,156,0,51,1  ; n459 t=82.647s dur=2458ms, freq=156Hz, sample=51, buffer_id=01:33
    db 94,1,51,8,56,46,1,1,208,0,56,1  ; n460 t=83.005s dur=2099ms, freq=208Hz, sample=56, buffer_id=01:38
    db 68,1,214,6,60,34,1,11,6,1,60,1  ; n461 t=83.355s dur=1750ms, freq=262Hz, sample=60, buffer_id=01:3C
    db 0,0,72,5,68,33,2,8,159,1,68,2  ; n462 t=83.679s dur=1352ms, freq=415Hz, sample=68, buffer_id=02:44
    db 0,0,72,5,63,27,2,9,55,1,63,2  ; n463 t=83.679s dur=1352ms, freq=311Hz, sample=63, buffer_id=02:3F
    db 29,0,72,5,58,34,2,2,247,0,58,2  ; n464 t=83.679s dur=1352ms, freq=247Hz, sample=58, buffer_id=02:3A
    db 103,1,117,5,68,56,1,3,159,1,68,1  ; n465 t=83.708s dur=1397ms, freq=415Hz, sample=68, buffer_id=01:44
    db 91,1,14,4,58,50,1,4,247,0,58,1  ; n466 t=84.067s dur=1038ms, freq=247Hz, sample=58, buffer_id=01:3A
    db 91,1,179,2,63,50,1,6,55,1,63,1  ; n467 t=84.414s dur=691ms, freq=311Hz, sample=63, buffer_id=01:3F
    db 53,1,88,1,68,50,1,3,159,1,68,1  ; n468 t=84.761s dur=344ms, freq=415Hz, sample=68, buffer_id=01:44
    db 18,0,205,5,43,38,3,7,98,0,43,3  ; n469 t=85.070s dur=1485ms, freq=98Hz, sample=43, buffer_id=03:2B
    db 3,0,72,5,67,37,2,10,136,1,67,2  ; n470 t=85.088s dur=1352ms, freq=392Hz, sample=67, buffer_id=02:43
    db 0,0,72,5,58,35,2,2,233,0,58,2  ; n471 t=85.091s dur=1352ms, freq=233Hz, sample=58, buffer_id=02:3A
    db 26,0,72,5,63,34,2,9,55,1,63,2  ; n472 t=85.091s dur=1352ms, freq=311Hz, sample=63, buffer_id=02:3F
; t 85.1053 Sustain 0 (Instr 1)
    db 3,0,81,5,67,54,1,13,136,1,67,1  ; n473 t=85.117s dur=1361ms, freq=392Hz, sample=67, buffer_id=01:43
    db 94,1,78,5,39,53,1,14,78,0,39,1  ; n474 t=85.120s dur=1358ms, freq=78Hz, sample=39, buffer_id=01:27
; t 85.3024 Sustain 127 (Instr 1)
    db 97,1,240,3,46,59,1,0,117,0,46,1  ; n475 t=85.470s dur=1008ms, freq=117Hz, sample=46, buffer_id=01:2E
    db 94,1,143,2,63,54,1,1,55,1,63,1  ; n476 t=85.823s dur=655ms, freq=311Hz, sample=63, buffer_id=01:3F
    db 59,1,49,1,65,41,1,3,93,1,65,1  ; n477 t=86.173s dur=305ms, freq=349Hz, sample=65, buffer_id=01:41
; t 86.4788 Sustain 0 (Instr 1)
    db 15,0,202,5,39,39,3,4,65,0,39,3  ; n478 t=86.488s dur=1482ms, freq=65Hz, sample=39, buffer_id=03:27
    db 0,0,72,5,67,23,2,10,136,1,67,2  ; n479 t=86.502s dur=1352ms, freq=392Hz, sample=67, buffer_id=02:43
    db 0,0,72,5,60,33,2,5,6,1,60,2  ; n480 t=86.502s dur=1352ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 26,0,72,5,63,24,2,9,74,1,63,2  ; n481 t=86.502s dur=1352ms, freq=330Hz, sample=63, buffer_id=02:3F
    db 3,0,152,5,67,53,1,13,136,1,67,1  ; n482 t=86.529s dur=1432ms, freq=392Hz, sample=67, buffer_id=01:43
    db 6,0,149,5,63,53,1,1,74,1,63,1  ; n483 t=86.532s dur=1429ms, freq=330Hz, sample=63, buffer_id=01:3F
    db 97,1,143,5,48,53,1,6,131,0,48,1  ; n484 t=86.538s dur=1423ms, freq=131Hz, sample=48, buffer_id=01:30
; t 86.6818 Sustain 127 (Instr 1)
    db 91,1,46,4,55,41,1,0,196,0,55,1  ; n485 t=86.891s dur=1070ms, freq=196Hz, sample=55, buffer_id=01:37
    db 97,1,211,2,68,50,1,2,159,1,68,1  ; n486 t=87.238s dur=723ms, freq=415Hz, sample=68, buffer_id=01:44
    db 62,1,114,1,58,50,1,3,233,0,58,1  ; n487 t=87.591s dur=370ms, freq=233Hz, sample=58, buffer_id=01:3A
    db 6,0,243,5,41,38,3,7,87,0,41,3  ; n488 t=87.908s dur=1523ms, freq=87Hz, sample=41, buffer_id=03:29
    db 3,0,72,5,65,37,2,8,93,1,65,2  ; n489 t=87.914s dur=1352ms, freq=349Hz, sample=65, buffer_id=02:41
    db 3,0,72,5,57,30,2,11,220,0,57,2  ; n490 t=87.917s dur=1352ms, freq=220Hz, sample=57, buffer_id=02:39
    db 24,0,72,5,60,19,2,5,6,1,60,2  ; n491 t=87.920s dur=1352ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 6,0,72,5,56,54,1,12,220,0,56,1  ; n492 t=87.944s dur=1352ms, freq=220Hz, sample=56, buffer_id=01:38
    db 3,0,67,5,65,55,1,14,93,1,65,1  ; n493 t=87.949s dur=1347ms, freq=349Hz, sample=65, buffer_id=01:41
    db 94,1,64,5,41,55,1,15,87,0,41,1  ; n494 t=87.952s dur=1344ms, freq=87Hz, sample=41, buffer_id=01:29
; t 87.9612 Sustain 0 (Instr 1)
; t 88.1465 Sustain 127 (Instr 1)
    db 100,1,226,3,48,43,1,0,131,0,48,1  ; n495 t=88.302s dur=994ms, freq=131Hz, sample=48, buffer_id=01:30
    db 88,1,126,2,62,36,1,1,38,1,62,1  ; n496 t=88.658s dur=638ms, freq=294Hz, sample=62, buffer_id=01:3E
    db 68,1,38,1,63,47,1,2,55,1,63,1  ; n497 t=89.002s dur=294ms, freq=311Hz, sample=63, buffer_id=01:3F
; t 89.2965 Sustain 0 (Instr 1)
    db 0,0,72,5,65,33,2,8,93,1,65,2  ; n498 t=89.326s dur=1352ms, freq=349Hz, sample=65, buffer_id=02:41
    db 6,0,72,5,56,35,2,3,208,0,56,2  ; n499 t=89.326s dur=1352ms, freq=208Hz, sample=56, buffer_id=02:38
    db 3,0,72,5,62,33,2,4,38,1,62,2  ; n500 t=89.332s dur=1352ms, freq=294Hz, sample=62, buffer_id=02:3E
    db 26,0,114,5,39,35,3,6,58,0,39,3  ; n501 t=89.335s dur=1394ms, freq=58Hz, sample=39, buffer_id=03:27
    db 0,0,132,5,46,56,1,9,117,0,46,1  ; n502 t=89.361s dur=1412ms, freq=117Hz, sample=46, buffer_id=01:2E
    db 0,0,132,5,65,30,1,14,93,1,65,1  ; n503 t=89.361s dur=1412ms, freq=349Hz, sample=65, buffer_id=01:41
    db 88,1,132,5,62,43,1,1,38,1,62,1  ; n504 t=89.361s dur=1412ms, freq=294Hz, sample=62, buffer_id=01:3E
; t 89.5406 Sustain 127 (Instr 1)
    db 100,1,43,4,53,39,1,0,175,0,53,1  ; n505 t=89.705s dur=1067ms, freq=175Hz, sample=53, buffer_id=01:35
    db 100,1,235,2,67,43,1,2,136,1,67,1  ; n506 t=90.061s dur=747ms, freq=392Hz, sample=67, buffer_id=01:43
    db 62,1,100,1,56,51,1,5,208,0,56,1  ; n507 t=90.417s dur=356ms, freq=208Hz, sample=56, buffer_id=01:38
    db 3,0,207,9,39,41,3,6,78,0,39,3  ; n508 t=90.735s dur=2511ms, freq=78Hz, sample=39, buffer_id=03:27
    db 0,0,180,8,58,19,2,7,233,0,58,2  ; n509 t=90.738s dur=2228ms, freq=233Hz, sample=58, buffer_id=02:3A
    db 0,0,180,8,55,25,2,10,196,0,55,2  ; n510 t=90.738s dur=2228ms, freq=196Hz, sample=55, buffer_id=02:37
    db 29,0,180,8,63,40,2,11,55,1,63,2  ; n511 t=90.738s dur=2228ms, freq=311Hz, sample=63, buffer_id=02:3F
    db 6,0,156,11,39,53,1,12,78,0,39,1  ; n512 t=90.767s dur=2972ms, freq=78Hz, sample=39, buffer_id=01:27
    db 95,1,150,11,63,53,1,13,55,1,63,1  ; n513 t=90.773s dur=2966ms, freq=311Hz, sample=63, buffer_id=01:3F
; t 90.7732 Sustain 0 (Instr 1)
; t 90.9897 Sustain 127 (Instr 1)
    db 107,1,55,10,46,41,1,0,117,0,46,1  ; n514 t=91.124s dur=2615ms, freq=117Hz, sample=46, buffer_id=01:2E
    db 120,1,203,8,51,50,1,1,156,0,51,1  ; n515 t=91.488s dur=2251ms, freq=156Hz, sample=51, buffer_id=01:33
    db 127,1,83,7,55,41,1,2,196,0,55,1  ; n516 t=91.864s dur=1875ms, freq=196Hz, sample=55, buffer_id=01:37
    db 116,4,213,5,63,43,1,13,55,1,63,1  ; n517 t=92.246s dur=1493ms, freq=311Hz, sample=63, buffer_id=01:3F
    db 78,1,97,1,70,45,1,3,210,1,70,1  ; n518 t=93.386s dur=353ms, freq=466Hz, sample=70, buffer_id=01:46
    db 13,0,28,11,39,49,3,4,78,0,39,3  ; n519 t=93.721s dur=2844ms, freq=78Hz, sample=39, buffer_id=03:27
    db 0,0,75,5,63,25,2,5,55,1,63,2  ; n520 t=93.733s dur=1355ms, freq=311Hz, sample=63, buffer_id=02:3F
    db 0,0,75,5,67,19,2,6,136,1,67,2  ; n521 t=93.733s dur=1355ms, freq=392Hz, sample=67, buffer_id=02:43
    db 35,0,75,5,70,27,2,7,210,1,70,2  ; n522 t=93.733s dur=1355ms, freq=466Hz, sample=70, buffer_id=02:46
; t 93.7396 Sustain 0 (Instr 1)
    db 6,0,234,10,67,45,1,8,136,1,67,1  ; n523 t=93.768s dur=2794ms, freq=392Hz, sample=67, buffer_id=01:43
    db 91,1,228,10,51,45,1,1,156,0,51,1  ; n524 t=93.774s dur=2788ms, freq=156Hz, sample=51, buffer_id=01:33
; t 93.9562 Sustain 127 (Instr 1)
    db 97,1,137,9,70,42,1,0,210,1,70,1  ; n525 t=94.121s dur=2441ms, freq=466Hz, sample=70, buffer_id=01:46
    db 3,0,40,8,67,48,1,8,136,1,67,1  ; n526 t=94.474s dur=2088ms, freq=392Hz, sample=67, buffer_id=01:43
    db 88,1,37,8,58,39,1,2,233,0,58,1  ; n527 t=94.477s dur=2085ms, freq=233Hz, sample=58, buffer_id=01:3A
    db 67,1,205,6,70,42,1,0,210,1,70,1  ; n528 t=94.821s dur=1741ms, freq=466Hz, sample=70, buffer_id=01:46
    db 0,0,72,5,70,31,2,7,210,1,70,2  ; n529 t=95.144s dur=1352ms, freq=466Hz, sample=70, buffer_id=02:46
    db 0,0,72,5,63,31,2,5,55,1,63,2  ; n530 t=95.144s dur=1352ms, freq=311Hz, sample=63, buffer_id=02:3F
    db 27,0,72,5,67,19,2,6,136,1,67,2  ; n531 t=95.144s dur=1352ms, freq=392Hz, sample=67, buffer_id=02:43
    db 3,0,111,5,67,48,1,8,136,1,67,1  ; n532 t=95.171s dur=1391ms, freq=392Hz, sample=67, buffer_id=01:43
    db 91,1,108,5,60,36,1,3,6,1,60,1  ; n533 t=95.174s dur=1388ms, freq=262Hz, sample=60, buffer_id=01:3C
    db 94,1,17,4,70,34,1,0,210,1,70,1  ; n534 t=95.521s dur=1041ms, freq=466Hz, sample=70, buffer_id=01:46
    db 3,0,179,2,58,43,1,2,233,0,58,1  ; n535 t=95.871s dur=691ms, freq=233Hz, sample=58, buffer_id=01:3A
    db 97,1,176,2,67,41,1,8,136,1,67,1  ; n536 t=95.874s dur=688ms, freq=392Hz, sample=67, buffer_id=01:43
    db 68,1,79,1,70,47,1,0,210,1,70,1  ; n537 t=96.227s dur=335ms, freq=466Hz, sample=70, buffer_id=01:46
    db 6,0,149,5,41,35,3,9,87,0,41,3  ; n538 t=96.550s dur=1429ms, freq=87Hz, sample=41, buffer_id=03:29
    db 0,0,72,5,72,27,2,10,11,2,72,2  ; n539 t=96.556s dur=1352ms, freq=523Hz, sample=72, buffer_id=02:48
    db 0,0,72,5,65,28,2,11,93,1,65,2  ; n540 t=96.556s dur=1352ms, freq=349Hz, sample=65, buffer_id=02:41
    db 21,0,72,5,68,31,2,12,159,1,68,2  ; n541 t=96.556s dur=1352ms, freq=415Hz, sample=68, buffer_id=02:44
; t 96.5621 Sustain 0 (Instr 1)
    db 3,0,163,10,68,58,1,13,159,1,68,1  ; n542 t=96.577s dur=2723ms, freq=415Hz, sample=68, buffer_id=01:44
    db 94,1,160,10,53,58,1,14,175,0,53,1  ; n543 t=96.580s dur=2720ms, freq=175Hz, sample=53, buffer_id=01:35
; t 96.7445 Sustain 127 (Instr 1)
    db 97,1,66,9,70,50,1,0,210,1,70,1  ; n544 t=96.930s dur=2370ms, freq=466Hz, sample=70, buffer_id=01:46
    db 0,0,225,7,68,60,1,13,159,1,68,1  ; n545 t=97.283s dur=2017ms, freq=415Hz, sample=68, buffer_id=01:44
    db 94,1,225,7,56,60,1,1,208,0,56,1  ; n546 t=97.283s dur=2017ms, freq=208Hz, sample=56, buffer_id=01:38
    db 76,1,131,6,70,52,1,0,210,1,70,1  ; n547 t=97.633s dur=1667ms, freq=466Hz, sample=70, buffer_id=01:46
    db 3,0,120,5,39,37,3,2,58,0,39,3  ; n548 t=97.965s dur=1400ms, freq=58Hz, sample=39, buffer_id=03:27
    db 0,0,72,5,68,35,2,12,159,1,68,2  ; n549 t=97.968s dur=1352ms, freq=415Hz, sample=68, buffer_id=02:44
    db 0,0,72,5,70,39,2,3,210,1,70,2  ; n550 t=97.968s dur=1352ms, freq=466Hz, sample=70, buffer_id=02:46
    db 21,0,72,5,65,27,2,11,93,1,65,2  ; n551 t=97.968s dur=1352ms, freq=349Hz, sample=65, buffer_id=02:41
    db 0,0,31,5,68,60,1,13,159,1,68,1  ; n552 t=97.989s dur=1311ms, freq=415Hz, sample=68, buffer_id=01:44
    db 100,1,31,5,58,60,1,4,233,0,58,1  ; n553 t=97.989s dur=1311ms, freq=233Hz, sample=58, buffer_id=01:3A
    db 91,1,187,3,70,53,1,0,210,1,70,1  ; n554 t=98.344s dur=955ms, freq=466Hz, sample=70, buffer_id=01:46
    db 9,0,96,2,72,58,1,5,11,2,72,1  ; n555 t=98.692s dur=608ms, freq=523Hz, sample=72, buffer_id=01:48
    db 94,1,190,2,56,59,1,1,208,0,56,1  ; n556 t=98.700s dur=702ms, freq=208Hz, sample=56, buffer_id=01:38
    db 59,1,79,1,74,52,1,6,75,2,74,1  ; n557 t=99.050s dur=335ms, freq=587Hz, sample=74, buffer_id=01:4A
; t 99.3004 Sustain 0 (Instr 1)
    db 15,0,21,19,39,39,3,2,78,0,39,3  ; n558 t=99.365s dur=4885ms, freq=78Hz, sample=39, buffer_id=03:27
    db 0,0,164,17,67,27,2,7,136,1,67,2  ; n559 t=99.380s dur=4516ms, freq=392Hz, sample=67, buffer_id=02:43
    db 0,0,164,17,75,36,2,8,110,2,75,2  ; n560 t=99.380s dur=4516ms, freq=622Hz, sample=75, buffer_id=02:4B
    db 23,0,164,17,70,14,2,3,210,1,70,2  ; n561 t=99.380s dur=4516ms, freq=466Hz, sample=70, buffer_id=02:46
    db 6,0,81,11,75,59,1,9,110,2,75,1  ; n562 t=99.403s dur=2897ms, freq=622Hz, sample=75, buffer_id=01:4B
    db 88,1,75,11,51,56,1,10,156,0,51,1  ; n563 t=99.409s dur=2891ms, freq=156Hz, sample=51, buffer_id=01:33
; t 99.5033 Sustain 127 (Instr 1)
    db 3,0,243,9,67,54,1,0,136,1,67,1  ; n564 t=99.753s dur=2547ms, freq=392Hz, sample=67, buffer_id=01:43
    db 88,1,240,9,58,54,1,1,233,0,58,1  ; n565 t=99.756s dur=2544ms, freq=233Hz, sample=58, buffer_id=01:3A
    db 3,0,152,8,70,57,1,4,210,1,70,1  ; n566 t=100.100s dur=2200ms, freq=466Hz, sample=70, buffer_id=01:46
    db 94,1,149,8,63,57,1,5,55,1,63,1  ; n567 t=100.103s dur=2197ms, freq=311Hz, sample=63, buffer_id=01:3F
    db 3,0,55,7,67,53,1,0,136,1,67,1  ; n568 t=100.454s dur=1847ms, freq=392Hz, sample=67, buffer_id=01:43
    db 96,1,52,7,75,56,1,9,110,2,75,1  ; n569 t=100.457s dur=1844ms, freq=622Hz, sample=75, buffer_id=01:4B
    db 0,0,211,5,79,60,1,6,16,3,79,1  ; n570 t=100.809s dur=1491ms, freq=784Hz, sample=79, buffer_id=01:4F
    db 109,1,211,5,70,60,1,4,210,1,70,1  ; n571 t=100.809s dur=1491ms, freq=466Hz, sample=70, buffer_id=01:46
    db 0,0,103,4,75,51,1,9,110,2,75,1  ; n572 t=101.174s dur=1127ms, freq=622Hz, sample=75, buffer_id=01:4B
    db 121,1,103,4,79,51,1,6,164,3,79,1  ; n573 t=101.174s dur=1127ms, freq=932Hz, sample=79, buffer_id=01:4F
    db 3,0,237,2,79,54,1,6,16,3,79,1  ; n574 t=101.551s dur=749ms, freq=784Hz, sample=79, buffer_id=01:4F
    db 119,1,234,2,79,54,1,6,221,4,79,1  ; n575 t=101.554s dur=746ms, freq=1245Hz, sample=79, buffer_id=01:4F
    db 6,0,115,1,79,50,1,6,32,6,79,1  ; n576 t=101.929s dur=371ms, freq=1568Hz, sample=79, buffer_id=01:4F
    db 119,1,109,1,79,50,1,6,164,3,79,1  ; n577 t=101.935s dur=365ms, freq=932Hz, sample=79, buffer_id=01:4F
; t 102.3009 Sustain 0 (Instr 1)
    db 7,0,234,2,79,56,1,6,32,6,79,1  ; n578 t=102.311s dur=746ms, freq=1568Hz, sample=79, buffer_id=01:4F
    db 0,0,171,3,79,56,1,6,221,4,79,1  ; n579 t=102.317s dur=939ms, freq=1245Hz, sample=79, buffer_id=01:4F
    db 10,0,115,2,79,56,1,6,73,7,79,1  ; n580 t=102.317s dur=627ms, freq=1865Hz, sample=79, buffer_id=01:4F
    db 0,0,213,1,79,56,1,6,185,9,79,1  ; n581 t=102.327s dur=469ms, freq=2489Hz, sample=79, buffer_id=01:4F
    db 255,255,255,255,255,255,255,255,255,255,255,255  ; End marker

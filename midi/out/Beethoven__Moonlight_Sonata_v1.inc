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

total_notes: equ 2048
midi_data:
; t 0.0000 Soft 127 (Instr 1)
; t 0.0000 Soft 127 (Instr 2)
    db 12,0,13,16,37,39,1,0,69,0,37,1  ; n1 t=0.783s dur=4109ms, freq=69Hz, sample=37, buffer_id=01:25
    db 20,0,1,16,49,39,1,1,139,0,49,1  ; n2 t=0.795s dur=4097ms, freq=139Hz, sample=49, buffer_id=01:31
    db 123,1,237,15,56,39,1,2,208,0,56,1  ; n3 t=0.815s dur=4077ms, freq=208Hz, sample=56, buffer_id=01:38
; t 0.8432 Sustain 127 (Instr 1)
; t 0.8432 Sustain 127 (Instr 2)
    db 83,1,114,14,61,34,1,3,21,1,61,1  ; n4 t=1.194s dur=3698ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 106,1,31,13,64,33,1,4,74,1,64,1  ; n5 t=1.533s dur=3359ms, freq=330Hz, sample=64, buffer_id=01:40
    db 104,1,181,11,56,33,1,2,208,0,56,1  ; n6 t=1.895s dur=2997ms, freq=208Hz, sample=56, buffer_id=01:38
    db 41,1,77,10,61,33,1,3,21,1,61,1  ; n7 t=2.254s dur=2637ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 87,1,36,9,64,33,1,4,74,1,64,1  ; n8 t=2.551s dur=2340ms, freq=330Hz, sample=64, buffer_id=01:40
    db 80,1,205,7,56,33,1,2,208,0,56,1  ; n9 t=2.895s dur=1997ms, freq=208Hz, sample=56, buffer_id=01:38
    db 70,1,125,6,61,33,1,3,21,1,61,1  ; n10 t=3.230s dur=1661ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 94,1,56,5,64,33,1,4,74,1,64,1  ; n11 t=3.556s dur=1336ms, freq=330Hz, sample=64, buffer_id=01:40
    db 91,1,218,3,56,33,1,2,208,0,56,1  ; n12 t=3.906s dur=986ms, freq=208Hz, sample=56, buffer_id=01:38
    db 60,1,127,2,61,33,1,3,21,1,61,1  ; n13 t=4.253s dur=639ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 203,0,160,1,64,33,1,4,74,1,64,1  ; n14 t=4.569s dur=416ms, freq=330Hz, sample=64, buffer_id=01:40
    db 10,0,194,16,35,41,1,5,62,0,35,1  ; n15 t=4.772s dur=4290ms, freq=62Hz, sample=35, buffer_id=01:23
    db 124,0,184,16,47,41,1,6,123,0,47,1  ; n16 t=4.782s dur=4280ms, freq=123Hz, sample=47, buffer_id=01:2F
; t 4.8922 Sustain 0 (Instr 1)
; t 4.8922 Sustain 0 (Instr 2)
    db 100,1,60,16,56,33,1,2,208,0,56,1  ; n17 t=4.905s dur=4156ms, freq=208Hz, sample=56, buffer_id=01:38
; t 5.2002 Sustain 127 (Instr 1)
; t 5.2002 Sustain 127 (Instr 2)
    db 99,1,216,14,61,33,1,0,21,1,61,1  ; n18 t=5.261s dur=3800ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 68,1,117,13,64,33,1,1,74,1,64,1  ; n19 t=5.617s dur=3445ms, freq=330Hz, sample=64, buffer_id=01:40
; t 5.7701 Soft 0 (Instr 1)
; t 5.7701 Soft 0 (Instr 2)
    db 120,1,49,12,56,33,1,2,208,0,56,1  ; n20 t=5.941s dur=3121ms, freq=208Hz, sample=56, buffer_id=01:38
    db 63,1,185,10,61,33,1,0,21,1,61,1  ; n21 t=6.317s dur=2745ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 86,1,122,9,64,33,1,1,74,1,64,1  ; n22 t=6.636s dur=2426ms, freq=330Hz, sample=64, buffer_id=01:40
    db 94,1,36,8,56,33,1,2,208,0,56,1  ; n23 t=6.978s dur=2084ms, freq=208Hz, sample=56, buffer_id=01:38
    db 78,1,198,6,61,33,1,0,21,1,61,1  ; n24 t=7.328s dur=1734ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 128,1,120,5,64,33,1,1,74,1,64,1  ; n25 t=7.662s dur=1400ms, freq=330Hz, sample=64, buffer_id=01:40
    db 74,1,248,3,56,33,1,2,208,0,56,1  ; n26 t=8.045s dur=1016ms, freq=208Hz, sample=56, buffer_id=01:38
    db 115,1,175,2,61,33,1,0,21,1,61,1  ; n27 t=8.375s dur=687ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 220,0,104,2,64,34,1,1,74,1,64,1  ; n28 t=8.747s dur=616ms, freq=330Hz, sample=64, buffer_id=01:40
    db 32,0,32,9,33,37,1,3,55,0,33,1  ; n29 t=8.967s dur=2336ms, freq=55Hz, sample=33, buffer_id=01:21
    db 128,0,1,9,45,37,1,4,110,0,45,1  ; n30 t=8.999s dur=2305ms, freq=110Hz, sample=45, buffer_id=01:2D
; t 9.0622 Sustain 0 (Instr 1)
; t 9.0622 Sustain 0 (Instr 2)
    db 114,1,129,8,57,36,1,7,220,0,57,1  ; n31 t=9.127s dur=2177ms, freq=220Hz, sample=57, buffer_id=01:39
    db 125,1,14,7,61,33,1,0,21,1,61,1  ; n32 t=9.497s dur=1806ms, freq=277Hz, sample=61, buffer_id=01:3D
; t 9.5026 Sustain 127 (Instr 1)
; t 9.5026 Sustain 127 (Instr 2)
    db 74,1,145,5,64,33,1,1,74,1,64,1  ; n33 t=9.878s dur=1425ms, freq=330Hz, sample=64, buffer_id=01:40
    db 79,1,71,4,57,33,1,7,220,0,57,1  ; n34 t=10.208s dur=1095ms, freq=220Hz, sample=57, buffer_id=01:39
    db 135,1,248,2,61,33,1,0,21,1,61,1  ; n35 t=10.543s dur=760ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 23,1,186,1,64,33,1,1,74,1,64,1  ; n36 t=10.935s dur=442ms, freq=330Hz, sample=64, buffer_id=01:40
    db 19,0,146,9,30,35,1,2,46,0,30,1  ; n37 t=11.214s dur=2450ms, freq=46Hz, sample=30, buffer_id=01:1E
    db 78,0,127,9,42,35,1,5,92,0,42,1  ; n38 t=11.233s dur=2431ms, freq=92Hz, sample=42, buffer_id=01:2A
; t 11.3038 Sustain 0 (Instr 1)
; t 11.3038 Sustain 0 (Instr 2)
    db 127,1,49,9,57,34,1,7,220,0,57,1  ; n39 t=11.310s dur=2353ms, freq=220Hz, sample=57, buffer_id=01:39
    db 102,1,178,7,62,33,1,0,38,1,62,1  ; n40 t=11.694s dur=1970ms, freq=294Hz, sample=62, buffer_id=01:3E
; t 11.7683 Sustain 127 (Instr 1)
; t 11.7683 Sustain 127 (Instr 2)
; t 11.8177 Soft 127 (Instr 1)
; t 11.8177 Soft 127 (Instr 2)
    db 139,1,76,6,66,33,1,1,114,1,66,1  ; n41 t=12.052s dur=1612ms, freq=370Hz, sample=66, buffer_id=01:42
    db 117,1,192,4,57,33,1,7,220,0,57,1  ; n42 t=12.447s dur=1216ms, freq=220Hz, sample=57, buffer_id=01:39
    db 143,1,75,3,62,33,1,0,38,1,62,1  ; n43 t=12.821s dur=843ms, freq=294Hz, sample=62, buffer_id=01:3E
    db 83,1,188,1,66,33,1,1,114,1,66,1  ; n44 t=13.220s dur=444ms, freq=370Hz, sample=66, buffer_id=01:42
    db 13,0,157,9,32,35,1,3,52,0,32,1  ; n45 t=13.559s dur=2461ms, freq=52Hz, sample=32, buffer_id=01:20
    db 83,0,144,9,44,35,1,4,104,0,44,1  ; n46 t=13.572s dur=2448ms, freq=104Hz, sample=44, buffer_id=01:2C
    db 136,1,190,1,56,34,1,6,208,0,56,1  ; n47 t=13.655s dur=446ms, freq=208Hz, sample=56, buffer_id=01:38
; t 13.6641 Sustain 0 (Instr 1)
; t 13.6641 Sustain 0 (Instr 2)
    db 127,1,163,4,60,33,1,0,6,1,60,1  ; n48 t=14.047s dur=1187ms, freq=262Hz, sample=60, buffer_id=01:3C
; t 14.1668 Sustain 127 (Instr 1)
; t 14.1668 Sustain 127 (Instr 2)
    db 99,1,35,3,66,33,1,1,114,1,66,1  ; n49 t=14.431s dur=803ms, freq=370Hz, sample=66, buffer_id=01:42
    db 144,1,211,4,56,33,1,2,208,0,56,1  ; n50 t=14.786s dur=1235ms, freq=208Hz, sample=56, buffer_id=01:38
    db 100,1,67,3,61,33,1,5,21,1,61,1  ; n51 t=15.185s dur=835ms, freq=277Hz, sample=61, buffer_id=01:3D
; t 15.2346 Sustain 0 (Instr 1)
; t 15.2346 Sustain 0 (Instr 2)
    db 101,1,223,1,64,33,1,0,74,1,64,1  ; n52 t=15.541s dur=479ms, freq=330Hz, sample=64, buffer_id=01:40
; t 15.5566 Sustain 127 (Instr 1)
; t 15.5566 Sustain 127 (Instr 2)
    db 12,0,183,11,32,35,1,3,52,0,32,1  ; n53 t=15.898s dur=2999ms, freq=52Hz, sample=32, buffer_id=01:20
    db 44,0,171,11,44,35,1,4,104,0,44,1  ; n54 t=15.910s dur=2987ms, freq=104Hz, sample=44, buffer_id=01:2C
    db 181,1,65,5,56,35,1,2,208,0,56,1  ; n55 t=15.954s dur=1345ms, freq=208Hz, sample=56, buffer_id=01:38
; t 16.0209 Sustain 0 (Instr 1)
; t 16.0209 Sustain 0 (Instr 2)
    db 195,1,255,1,61,33,1,0,21,1,61,1  ; n56 t=16.391s dur=511ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 204,1,8,2,63,33,1,1,55,1,63,1  ; n57 t=16.842s dur=520ms, freq=311Hz, sample=63, buffer_id=01:3F
; t 16.9032 Sustain 127 (Instr 1)
; t 16.9032 Sustain 127 (Instr 2)
; t 17.2995 Sustain 0 (Instr 1)
; t 17.2995 Sustain 0 (Instr 2)
    db 235,1,60,6,54,33,1,0,185,0,54,1  ; n58 t=17.302s dur=1596ms, freq=185Hz, sample=54, buffer_id=01:36
; t 17.5064 Sustain 127 (Instr 1)
; t 17.5064 Sustain 127 (Instr 2)
    db 14,2,9,2,60,33,1,1,6,1,60,1  ; n59 t=17.793s dur=521ms, freq=262Hz, sample=60, buffer_id=01:3C
; t 17.8556 Sustain 0 (Instr 1)
; t 17.8556 Sustain 0 (Instr 2)
    db 231,1,67,2,63,33,1,2,55,1,63,1  ; n60 t=18.319s dur=579ms, freq=311Hz, sample=63, buffer_id=01:3F
; t 18.3800 Sustain 127 (Instr 1)
; t 18.3800 Sustain 127 (Instr 2)
    db 25,0,4,21,37,33,1,1,69,0,37,1  ; n61 t=18.806s dur=5380ms, freq=69Hz, sample=37, buffer_id=01:25
    db 0,0,235,20,44,33,1,4,104,0,44,1  ; n62 t=18.831s dur=5355ms, freq=104Hz, sample=44, buffer_id=01:2C
    db 94,0,235,20,49,33,1,5,139,0,49,1  ; n63 t=18.831s dur=5355ms, freq=139Hz, sample=49, buffer_id=01:31
; t 18.8978 Sustain 0 (Instr 1)
; t 18.8978 Sustain 0 (Instr 2)
    db 165,1,141,20,52,33,1,6,165,0,52,1  ; n64 t=18.925s dur=5261ms, freq=165Hz, sample=52, buffer_id=01:34
; t 19.3390 Sustain 127 (Instr 1)
; t 19.3390 Sustain 127 (Instr 2)
    db 147,1,232,18,56,33,1,0,208,0,56,1  ; n65 t=19.347s dur=4840ms, freq=208Hz, sample=56, buffer_id=01:38
    db 123,1,85,17,61,33,1,2,21,1,61,1  ; n66 t=19.750s dur=4437ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 146,1,218,15,56,33,1,0,208,0,56,1  ; n67 t=20.128s dur=4058ms, freq=208Hz, sample=56, buffer_id=01:38
    db 130,1,72,14,61,33,1,2,21,1,61,1  ; n68 t=20.530s dur=3656ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 105,1,198,12,64,33,1,3,74,1,64,1  ; n69 t=20.916s dur=3270ms, freq=330Hz, sample=64, buffer_id=01:40
    db 165,1,93,11,56,33,1,0,208,0,56,1  ; n70 t=21.277s dur=2909ms, freq=208Hz, sample=56, buffer_id=01:38
    db 124,1,184,9,61,33,1,2,21,1,61,1  ; n71 t=21.698s dur=2488ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 0,2,60,8,64,33,1,3,74,1,64,1  ; n72 t=22.078s dur=2108ms, freq=330Hz, sample=64, buffer_id=01:40
    db 11,0,60,6,56,39,1,0,208,0,56,1  ; n73 t=22.590s dur=1596ms, freq=208Hz, sample=56, buffer_id=01:38
    db 18,2,49,6,68,49,2,7,159,1,68,1  ; n74 t=22.601s dur=1585ms, freq=415Hz, sample=68, buffer_id=01:44
    db 153,1,31,4,61,33,1,2,21,1,61,1  ; n75 t=23.131s dur=1055ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 163,1,134,2,64,33,1,3,74,1,64,1  ; n76 t=23.540s dur=646ms, freq=330Hz, sample=64, buffer_id=01:40
    db 213,0,227,0,68,44,2,7,159,1,68,1  ; n77 t=23.959s dur=227ms, freq=415Hz, sample=68, buffer_id=01:44
    db 1,0,237,13,68,47,2,7,159,1,68,1  ; n78 t=24.172s dur=3565ms, freq=415Hz, sample=68, buffer_id=01:44
    db 6,0,62,19,48,40,1,8,131,0,48,1  ; n79 t=24.174s dur=4926ms, freq=131Hz, sample=48, buffer_id=01:30
    db 0,0,230,13,56,40,1,0,208,0,56,1  ; n80 t=24.180s dur=3558ms, freq=208Hz, sample=56, buffer_id=01:38
    db 7,0,55,19,36,40,1,9,65,0,36,1  ; n81 t=24.180s dur=4919ms, freq=65Hz, sample=36, buffer_id=01:24
    db 181,1,49,19,44,40,1,4,104,0,44,1  ; n82 t=24.187s dur=4913ms, freq=104Hz, sample=44, buffer_id=01:2C
; t 24.1867 Sustain 0 (Instr 1)
; t 24.1867 Sustain 0 (Instr 2)
    db 166,1,43,12,63,35,1,1,55,1,63,1  ; n83 t=24.623s dur=3115ms, freq=311Hz, sample=63, buffer_id=01:3F
; t 24.6483 Sustain 127 (Instr 1)
; t 24.6483 Sustain 127 (Instr 2)
    db 95,1,132,10,66,33,1,2,114,1,66,1  ; n84 t=25.045s dur=2692ms, freq=370Hz, sample=66, buffer_id=01:42
    db 119,1,37,9,56,33,1,0,208,0,56,1  ; n85 t=25.396s dur=2341ms, freq=208Hz, sample=56, buffer_id=01:38
    db 128,1,174,7,63,33,1,1,55,1,63,1  ; n86 t=25.772s dur=1966ms, freq=311Hz, sample=63, buffer_id=01:3F
    db 92,1,46,6,66,33,1,2,114,1,66,1  ; n87 t=26.156s dur=1582ms, freq=370Hz, sample=66, buffer_id=01:42
    db 153,1,210,4,56,33,1,0,208,0,56,1  ; n88 t=26.503s dur=1234ms, freq=208Hz, sample=56, buffer_id=01:38
    db 118,1,57,3,63,33,1,1,55,1,63,1  ; n89 t=26.913s dur=825ms, freq=311Hz, sample=63, buffer_id=01:3F
    db 190,1,237,1,66,33,1,2,114,1,66,1  ; n90 t=27.287s dur=493ms, freq=370Hz, sample=66, buffer_id=01:42
    db 20,0,86,5,68,48,2,7,159,1,68,1  ; n91 t=27.733s dur=1366ms, freq=415Hz, sample=68, buffer_id=01:44
; t 27.7384 Sustain 0 (Instr 1)
; t 27.7384 Sustain 0 (Instr 2)
    db 164,1,67,5,56,38,1,0,208,0,56,1  ; n92 t=27.753s dur=1347ms, freq=208Hz, sample=56, buffer_id=01:38
; t 28.0785 Sustain 127 (Instr 1)
; t 28.0785 Sustain 127 (Instr 2)
    db 144,1,159,3,63,33,1,1,55,1,63,1  ; n93 t=28.172s dur=927ms, freq=311Hz, sample=63, buffer_id=01:3F
    db 255,0,14,2,66,33,1,2,114,1,66,1  ; n94 t=28.573s dur=526ms, freq=370Hz, sample=66, buffer_id=01:42
    db 233,0,16,1,68,40,2,7,159,1,68,1  ; n95 t=28.828s dur=272ms, freq=415Hz, sample=68, buffer_id=01:44
    db 6,0,132,9,56,36,1,0,208,0,56,1  ; n96 t=29.060s dur=2436ms, freq=208Hz, sample=56, buffer_id=01:38
    db 4,0,125,9,49,36,1,3,139,0,49,1  ; n97 t=29.067s dur=2429ms, freq=139Hz, sample=49, buffer_id=01:31
    db 3,0,121,9,68,44,2,7,159,1,68,1  ; n98 t=29.071s dur=2425ms, freq=415Hz, sample=68, buffer_id=01:44
    db 164,1,117,9,37,36,1,5,69,0,37,1  ; n99 t=29.075s dur=2421ms, freq=69Hz, sample=37, buffer_id=01:25
; t 29.0997 Sustain 0 (Instr 1)
; t 29.0997 Sustain 0 (Instr 2)
; t 29.4627 Sustain 127 (Instr 1)
; t 29.4627 Sustain 127 (Instr 2)
    db 190,1,210,7,61,33,1,1,21,1,61,1  ; n100 t=29.494s dur=2002ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 98,1,19,6,64,34,1,2,74,1,64,1  ; n101 t=29.941s dur=1555ms, freq=330Hz, sample=64, buffer_id=01:40
    db 154,1,177,4,56,36,1,0,208,0,56,1  ; n102 t=30.295s dur=1201ms, freq=208Hz, sample=56, buffer_id=01:38
    db 127,1,167,3,61,34,1,1,21,1,61,1  ; n103 t=30.705s dur=935ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 63,1,226,1,64,38,1,2,74,1,64,1  ; n104 t=31.088s dur=482ms, freq=330Hz, sample=64, buffer_id=01:40
    db 44,0,116,10,30,42,1,4,46,0,30,1  ; n105 t=31.407s dur=2676ms, freq=46Hz, sample=30, buffer_id=01:1E
    db 97,0,72,10,42,43,1,6,92,0,42,1  ; n106 t=31.451s dur=2632ms, freq=92Hz, sample=42, buffer_id=01:2A
; t 31.4965 Sustain 0 (Instr 1)
; t 31.4965 Sustain 0 (Instr 2)
    db 12,0,231,9,57,44,1,8,220,0,57,1  ; n107 t=31.548s dur=2535ms, freq=220Hz, sample=57, buffer_id=01:39
    db 152,1,219,9,69,61,2,9,184,1,69,1  ; n108 t=31.560s dur=2523ms, freq=440Hz, sample=69, buffer_id=01:45
    db 191,1,67,8,61,39,1,0,21,1,61,1  ; n109 t=31.968s dur=2115ms, freq=277Hz, sample=61, buffer_id=01:3D
; t 32.0332 Sustain 127 (Instr 1)
; t 32.0332 Sustain 127 (Instr 2)
    db 148,1,132,6,66,33,1,1,114,1,66,1  ; n110 t=32.415s dur=1668ms, freq=370Hz, sample=66, buffer_id=01:42
    db 122,1,240,4,57,33,1,8,220,0,57,1  ; n111 t=32.819s dur=1264ms, freq=220Hz, sample=57, buffer_id=01:39
    db 183,1,118,3,61,33,1,0,21,1,61,1  ; n112 t=33.197s dur=886ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 252,1,190,1,66,33,1,1,114,1,66,1  ; n113 t=33.637s dur=446ms, freq=370Hz, sample=66, buffer_id=01:42
; t 34.0836 Sustain 0 (Instr 1)
; t 34.0836 Sustain 0 (Instr 2)
    db 4,0,33,10,35,37,1,2,62,0,35,1  ; n114 t=34.145s dur=2593ms, freq=62Hz, sample=35, buffer_id=01:23
    db 7,0,28,10,47,37,1,3,123,0,47,1  ; n115 t=34.149s dur=2588ms, freq=123Hz, sample=47, buffer_id=01:2F
    db 4,0,22,10,56,37,1,5,208,0,56,1  ; n116 t=34.156s dur=2582ms, freq=208Hz, sample=56, buffer_id=01:38
    db 166,1,17,10,68,46,2,7,159,1,68,1  ; n117 t=34.160s dur=2577ms, freq=415Hz, sample=68, buffer_id=01:44
; t 34.4531 Sustain 127 (Instr 1)
; t 34.4531 Sustain 127 (Instr 2)
    db 155,1,107,8,59,33,1,0,247,0,59,1  ; n118 t=34.582s dur=2155ms, freq=247Hz, sample=59, buffer_id=01:3B
    db 161,1,208,6,64,33,1,1,74,1,64,1  ; n119 t=34.993s dur=1744ms, freq=330Hz, sample=64, buffer_id=01:40
    db 125,1,47,5,56,33,1,5,208,0,56,1  ; n120 t=35.410s dur=1327ms, freq=208Hz, sample=56, buffer_id=01:38
    db 202,1,178,3,59,33,1,0,247,0,59,1  ; n121 t=35.792s dur=946ms, freq=247Hz, sample=59, buffer_id=01:3B
    db 36,1,232,1,64,33,1,1,74,1,64,1  ; n122 t=36.250s dur=488ms, freq=330Hz, sample=64, buffer_id=01:40
    db 69,0,120,12,35,33,1,2,62,0,35,1  ; n123 t=36.541s dur=3192ms, freq=62Hz, sample=35, buffer_id=01:23
    db 110,0,51,12,47,33,1,3,123,0,47,1  ; n124 t=36.610s dur=3123ms, freq=123Hz, sample=47, buffer_id=01:2F
    db 24,0,197,11,57,36,1,4,220,0,57,1  ; n125 t=36.721s dur=3013ms, freq=220Hz, sample=57, buffer_id=01:39
; t 36.7380 Sustain 0 (Instr 1)
; t 36.7380 Sustain 0 (Instr 2)
    db 149,1,173,11,66,40,1,6,114,1,66,1  ; n126 t=36.745s dur=2989ms, freq=370Hz, sample=66, buffer_id=01:42
; t 36.9991 Sustain 127 (Instr 1)
; t 36.9991 Sustain 127 (Instr 2)
    db 160,1,23,10,59,33,1,0,247,0,59,1  ; n127 t=37.150s dur=2583ms, freq=247Hz, sample=59, buffer_id=01:3B
    db 255,1,119,8,63,33,1,1,55,1,63,1  ; n128 t=37.566s dur=2167ms, freq=311Hz, sample=63, buffer_id=01:3F
    db 31,0,120,6,57,36,1,4,220,0,57,1  ; n129 t=38.078s dur=1656ms, freq=220Hz, sample=57, buffer_id=01:39
    db 219,1,89,6,71,44,2,5,238,1,71,1  ; n130 t=38.108s dur=1625ms, freq=494Hz, sample=71, buffer_id=01:47
    db 75,2,126,4,59,33,1,0,247,0,59,1  ; n131 t=38.583s dur=1150ms, freq=247Hz, sample=59, buffer_id=01:3B
    db 79,2,51,2,63,33,1,1,55,1,63,1  ; n132 t=39.170s dur=563ms, freq=311Hz, sample=63, buffer_id=01:3F
; t 39.7336 Sustain 0 (Instr 1)
; t 39.7336 Sustain 0 (Instr 2)
    db 1,0,94,17,52,34,1,7,165,0,52,1  ; n133 t=39.761s dur=4446ms, freq=165Hz, sample=52, buffer_id=01:34
    db 25,0,93,17,40,34,1,8,82,0,40,1  ; n134 t=39.762s dur=4445ms, freq=82Hz, sample=40, buffer_id=01:28
    db 11,0,68,17,56,36,1,9,208,0,56,1  ; n135 t=39.787s dur=4420ms, freq=208Hz, sample=56, buffer_id=01:38
    db 136,1,57,17,64,38,1,10,74,1,64,1  ; n136 t=39.798s dur=4409ms, freq=330Hz, sample=64, buffer_id=01:40
; t 40.0285 Sustain 127 (Instr 1)
; t 40.0285 Sustain 127 (Instr 2)
    db 120,1,177,15,59,33,1,0,247,0,59,1  ; n137 t=40.190s dur=4017ms, freq=247Hz, sample=59, buffer_id=01:3B
    db 83,1,57,14,64,33,1,10,74,1,64,1  ; n138 t=40.566s dur=3641ms, freq=330Hz, sample=64, buffer_id=01:40
    db 119,1,231,12,56,33,1,9,208,0,56,1  ; n139 t=40.904s dur=3303ms, freq=208Hz, sample=56, buffer_id=01:38
    db 129,1,112,11,59,33,1,0,247,0,59,1  ; n140 t=41.279s dur=2928ms, freq=247Hz, sample=59, buffer_id=01:3B
    db 90,1,239,9,64,33,1,10,74,1,64,1  ; n141 t=41.664s dur=2543ms, freq=330Hz, sample=64, buffer_id=01:40
    db 136,1,149,8,56,33,1,9,208,0,56,1  ; n142 t=42.011s dur=2197ms, freq=208Hz, sample=56, buffer_id=01:38
    db 137,1,12,7,59,33,1,0,247,0,59,1  ; n143 t=42.403s dur=1804ms, freq=247Hz, sample=59, buffer_id=01:3B
    db 120,1,131,5,64,33,1,10,74,1,64,1  ; n144 t=42.796s dur=1411ms, freq=330Hz, sample=64, buffer_id=01:40
    db 120,1,12,4,56,33,1,9,208,0,56,1  ; n145 t=43.172s dur=1036ms, freq=208Hz, sample=56, buffer_id=01:38
    db 133,1,246,2,59,33,1,0,247,0,59,1  ; n146 t=43.547s dur=758ms, freq=247Hz, sample=59, buffer_id=01:3B
    db 200,0,236,1,64,37,1,10,74,1,64,1  ; n147 t=43.936s dur=492ms, freq=330Hz, sample=64, buffer_id=01:40
    db 13,0,75,19,52,39,1,7,165,0,52,1  ; n148 t=44.136s dur=4939ms, freq=165Hz, sample=52, buffer_id=01:34
    db 143,0,62,19,40,39,1,8,82,0,40,1  ; n149 t=44.149s dur=4926ms, freq=82Hz, sample=40, buffer_id=01:28
; t 44.2077 Sustain 0 (Instr 1)
; t 44.2077 Sustain 0 (Instr 2)
    db 108,1,67,13,55,47,1,1,196,0,55,1  ; n150 t=44.292s dur=3395ms, freq=196Hz, sample=55, buffer_id=01:37
; t 44.5035 Sustain 127 (Instr 1)
; t 44.5035 Sustain 127 (Instr 2)
    db 124,1,215,11,59,33,1,0,247,0,59,1  ; n151 t=44.655s dur=3031ms, freq=247Hz, sample=59, buffer_id=01:3B
    db 119,1,91,10,64,33,1,2,74,1,64,1  ; n152 t=45.035s dur=2651ms, freq=330Hz, sample=64, buffer_id=01:40
    db 120,1,228,8,55,33,1,1,196,0,55,1  ; n153 t=45.411s dur=2276ms, freq=196Hz, sample=55, buffer_id=01:37
    db 88,1,108,7,59,33,1,0,247,0,59,1  ; n154 t=45.786s dur=1900ms, freq=247Hz, sample=59, buffer_id=01:3B
    db 130,1,20,6,64,33,1,2,74,1,64,1  ; n155 t=46.130s dur=1556ms, freq=330Hz, sample=64, buffer_id=01:40
    db 122,1,146,4,55,33,1,1,196,0,55,1  ; n156 t=46.517s dur=1170ms, freq=196Hz, sample=55, buffer_id=01:37
    db 73,1,58,3,59,33,1,0,247,0,59,1  ; n157 t=46.894s dur=826ms, freq=247Hz, sample=59, buffer_id=01:3B
    db 198,1,254,1,64,34,1,2,74,1,64,1  ; n158 t=47.223s dur=510ms, freq=330Hz, sample=64, buffer_id=01:40
    db 14,0,117,5,67,48,2,3,136,1,67,1  ; n159 t=47.677s dur=1397ms, freq=392Hz, sample=67, buffer_id=01:43
; t 47.6867 Sustain 0 (Instr 1)
; t 47.6867 Sustain 0 (Instr 2)
    db 227,1,103,5,55,41,1,1,196,0,55,1  ; n160 t=47.691s dur=1383ms, freq=196Hz, sample=55, buffer_id=01:37
    db 149,1,132,3,59,34,1,0,247,0,59,1  ; n161 t=48.175s dur=900ms, freq=247Hz, sample=59, buffer_id=01:3B
; t 48.1876 Sustain 127 (Instr 1)
; t 48.1876 Sustain 127 (Instr 2)
    db 12,1,239,1,64,33,1,2,74,1,64,1  ; n162 t=48.579s dur=495ms, freq=330Hz, sample=64, buffer_id=01:40
    db 2,1,227,0,67,45,2,3,136,1,67,1  ; n163 t=48.848s dur=227ms, freq=392Hz, sample=67, buffer_id=01:43
; t 49.0748 Sustain 0 (Instr 1)
; t 49.0748 Sustain 0 (Instr 2)
    db 7,0,139,14,50,39,1,4,147,0,50,1  ; n164 t=49.105s dur=3723ms, freq=147Hz, sample=50, buffer_id=01:32
    db 5,0,117,13,67,49,2,3,136,1,67,1  ; n165 t=49.112s dur=3445ms, freq=392Hz, sample=67, buffer_id=01:43
    db 8,0,217,14,38,39,1,5,73,0,38,1  ; n166 t=49.117s dur=3801ms, freq=73Hz, sample=38, buffer_id=01:26
    db 176,1,104,13,55,40,1,1,196,0,55,1  ; n167 t=49.125s dur=3432ms, freq=196Hz, sample=55, buffer_id=01:37
; t 49.5396 Sustain 127 (Instr 1)
; t 49.5396 Sustain 127 (Instr 2)
    db 118,1,184,11,59,34,1,0,247,0,59,1  ; n168 t=49.557s dur=3000ms, freq=247Hz, sample=59, buffer_id=01:3B
    db 72,1,66,10,65,33,1,2,93,1,65,1  ; n169 t=49.931s dur=2626ms, freq=349Hz, sample=65, buffer_id=01:41
    db 104,1,249,8,55,33,1,1,196,0,55,1  ; n170 t=50.260s dur=2297ms, freq=196Hz, sample=55, buffer_id=01:37
    db 106,1,145,7,59,33,1,0,247,0,59,1  ; n171 t=50.620s dur=1937ms, freq=247Hz, sample=59, buffer_id=01:3B
    db 111,1,39,6,65,33,1,2,93,1,65,1  ; n172 t=50.982s dur=1575ms, freq=349Hz, sample=65, buffer_id=01:41
    db 140,1,184,4,55,33,1,1,196,0,55,1  ; n173 t=51.349s dur=1208ms, freq=196Hz, sample=55, buffer_id=01:37
    db 99,1,103,3,59,33,1,0,247,0,59,1  ; n174 t=51.745s dur=871ms, freq=247Hz, sample=59, buffer_id=01:3B
    db 200,1,245,1,65,33,1,2,93,1,65,1  ; n175 t=52.099s dur=501ms, freq=349Hz, sample=65, buffer_id=01:41
    db 26,0,251,4,55,35,1,1,196,0,55,1  ; n176 t=52.555s dur=1275ms, freq=196Hz, sample=55, buffer_id=01:37
; t 52.5575 Sustain 0 (Instr 1)
; t 52.5575 Sustain 0 (Instr 2)
    db 142,1,224,4,67,47,2,3,136,1,67,1  ; n177 t=52.581s dur=1248ms, freq=392Hz, sample=67, buffer_id=01:43
; t 52.9218 Sustain 127 (Instr 1)
; t 52.9218 Sustain 127 (Instr 2)
    db 78,1,82,3,59,33,1,0,247,0,59,1  ; n178 t=52.980s dur=850ms, freq=247Hz, sample=59, buffer_id=01:3B
    db 245,0,4,2,65,33,1,2,93,1,65,1  ; n179 t=53.313s dur=516ms, freq=349Hz, sample=65, buffer_id=01:41
    db 30,1,15,1,67,46,2,3,136,1,67,1  ; n180 t=53.559s dur=271ms, freq=392Hz, sample=67, buffer_id=01:43
; t 53.8304 Sustain 0 (Instr 1)
; t 53.8304 Sustain 0 (Instr 2)
    db 8,0,173,4,48,36,1,4,131,0,48,1  ; n181 t=53.845s dur=1197ms, freq=131Hz, sample=48, buffer_id=01:30
    db 4,0,166,4,55,36,1,1,196,0,55,1  ; n182 t=53.852s dur=1190ms, freq=196Hz, sample=55, buffer_id=01:37
    db 10,0,25,14,67,50,2,3,136,1,67,1  ; n183 t=53.857s dur=3609ms, freq=392Hz, sample=67, buffer_id=01:43
    db 142,1,151,4,36,36,1,5,65,0,36,1  ; n184 t=53.866s dur=1175ms, freq=65Hz, sample=36, buffer_id=01:24
    db 127,1,9,3,60,33,1,0,6,1,60,1  ; n185 t=54.265s dur=777ms, freq=262Hz, sample=60, buffer_id=01:3C
; t 54.2678 Soft 0 (Instr 1)
; t 54.2678 Soft 0 (Instr 2)
; t 54.3213 Sustain 127 (Instr 1)
; t 54.3213 Sustain 127 (Instr 2)
    db 112,1,120,3,64,33,1,2,74,1,64,1  ; n186 t=54.647s dur=888ms, freq=330Hz, sample=64, buffer_id=01:40
    db 1,0,3,5,47,37,1,6,123,0,47,1  ; n187 t=55.015s dur=1283ms, freq=123Hz, sample=47, buffer_id=01:2F
    db 11,0,2,5,35,37,1,7,62,0,35,1  ; n188 t=55.016s dur=1282ms, freq=62Hz, sample=35, buffer_id=01:23
    db 168,1,247,4,55,37,1,1,196,0,55,1  ; n189 t=55.027s dur=1271ms, freq=196Hz, sample=55, buffer_id=01:37
; t 55.0423 Sustain 0 (Instr 1)
; t 55.0423 Sustain 0 (Instr 2)
    db 105,1,79,3,60,33,1,0,6,1,60,1  ; n190 t=55.451s dur=847ms, freq=262Hz, sample=60, buffer_id=01:3C
; t 55.5832 Sustain 127 (Instr 1)
; t 55.5832 Sustain 127 (Instr 2)
    db 151,1,61,2,64,33,1,2,74,1,64,1  ; n191 t=55.812s dur=573ms, freq=330Hz, sample=64, buffer_id=01:40
    db 5,0,18,10,34,38,1,4,58,0,34,1  ; n192 t=56.219s dur=2578ms, freq=58Hz, sample=34, buffer_id=01:22
    db 64,0,13,10,46,38,1,5,117,0,46,1  ; n193 t=56.224s dur=2573ms, freq=117Hz, sample=46, buffer_id=01:2E
; t 56.2450 Soft 127 (Instr 1)
; t 56.2450 Soft 127 (Instr 2)
    db 154,1,153,4,55,38,1,1,196,0,55,1  ; n194 t=56.289s dur=1177ms, freq=196Hz, sample=55, buffer_id=01:37
; t 56.2984 Sustain 0 (Instr 1)
; t 56.2984 Sustain 0 (Instr 2)
    db 106,1,92,3,61,33,1,0,21,1,61,1  ; n195 t=56.699s dur=860ms, freq=277Hz, sample=61, buffer_id=01:3D
; t 56.7291 Sustain 127 (Instr 1)
; t 56.7291 Sustain 127 (Instr 2)
    db 132,1,217,1,64,33,1,2,74,1,64,1  ; n196 t=57.061s dur=473ms, freq=330Hz, sample=64, buffer_id=01:40
    db 76,0,68,5,54,33,1,6,185,0,54,1  ; n197 t=57.449s dur=1348ms, freq=185Hz, sample=54, buffer_id=01:36
; t 57.4662 Sustain 0 (Instr 1)
; t 57.4662 Sustain 0 (Instr 2)
    db 145,1,248,4,66,43,1,7,114,1,66,1  ; n198 t=57.525s dur=1272ms, freq=370Hz, sample=66, buffer_id=01:42
; t 57.9035 Sustain 127 (Instr 1)
; t 57.9035 Sustain 127 (Instr 2)
    db 180,1,103,3,61,33,1,0,21,1,61,1  ; n199 t=57.926s dur=871ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 163,1,179,1,64,33,1,1,74,1,64,1  ; n200 t=58.362s dur=435ms, freq=330Hz, sample=64, buffer_id=01:40
    db 9,0,67,9,54,33,1,6,185,0,54,1  ; n201 t=58.781s dur=2371ms, freq=185Hz, sample=54, buffer_id=01:36
    db 4,0,59,9,35,33,1,2,62,0,35,1  ; n202 t=58.790s dur=2363ms, freq=62Hz, sample=35, buffer_id=01:23
    db 56,0,54,9,47,33,1,3,123,0,47,1  ; n203 t=58.794s dur=2358ms, freq=123Hz, sample=47, buffer_id=01:2F
; t 58.7976 Sustain 0 (Instr 1)
; t 58.7976 Sustain 0 (Instr 2)
    db 129,1,255,8,66,40,1,7,114,1,66,1  ; n204 t=58.850s dur=2303ms, freq=370Hz, sample=66, buffer_id=01:42
; t 59.1737 Sustain 127 (Instr 1)
; t 59.1737 Sustain 127 (Instr 2)
    db 150,1,126,7,59,33,1,0,247,0,59,1  ; n205 t=59.235s dur=1918ms, freq=247Hz, sample=59, buffer_id=01:3B
    db 110,1,232,5,62,33,1,1,38,1,62,1  ; n206 t=59.640s dur=1512ms, freq=294Hz, sample=62, buffer_id=01:3E
    db 144,1,122,4,54,33,1,6,185,0,54,1  ; n207 t=60.006s dur=1146ms, freq=185Hz, sample=54, buffer_id=01:36
    db 136,1,234,2,59,33,1,0,247,0,59,1  ; n208 t=60.406s dur=746ms, freq=247Hz, sample=59, buffer_id=01:3B
    db 12,1,218,1,62,33,1,1,38,1,62,1  ; n209 t=60.799s dur=474ms, freq=294Hz, sample=62, buffer_id=01:3E
    db 133,0,132,5,40,36,1,4,82,0,40,1  ; n210 t=61.067s dur=1412ms, freq=82Hz, sample=40, buffer_id=01:28
; t 61.1530 Sustain 0 (Instr 1)
; t 61.1530 Sustain 0 (Instr 2)
    db 24,0,255,4,55,34,1,5,196,0,55,1  ; n211 t=61.200s dur=1279ms, freq=196Hz, sample=55, buffer_id=01:37
    db 169,1,231,4,67,45,2,8,136,1,67,1  ; n212 t=61.224s dur=1255ms, freq=392Hz, sample=67, buffer_id=01:43
; t 61.5388 Sustain 127 (Instr 1)
; t 61.5388 Sustain 127 (Instr 2)
    db 148,1,65,3,59,33,1,0,247,0,59,1  ; n213 t=61.649s dur=833ms, freq=247Hz, sample=59, buffer_id=01:3B
    db 36,1,204,1,61,33,1,1,21,1,61,1  ; n214 t=62.053s dur=460ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 76,0,144,5,43,33,1,2,98,0,43,1  ; n215 t=62.345s dur=1424ms, freq=98Hz, sample=43, buffer_id=01:2B
    db 71,0,67,5,52,33,1,3,165,0,52,1  ; n216 t=62.422s dur=1347ms, freq=165Hz, sample=52, buffer_id=01:34
; t 62.4795 Sustain 0 (Instr 1)
; t 62.4795 Sustain 0 (Instr 2)
    db 155,1,253,4,64,42,1,6,74,1,64,1  ; n217 t=62.492s dur=1277ms, freq=330Hz, sample=64, buffer_id=01:40
; t 62.8577 Sustain 127 (Instr 1)
; t 62.8577 Sustain 127 (Instr 2)
    db 179,1,98,3,59,33,1,0,247,0,59,1  ; n218 t=62.903s dur=866ms, freq=247Hz, sample=59, buffer_id=01:3B
    db 169,1,175,1,61,33,1,1,21,1,61,1  ; n219 t=63.338s dur=431ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 13,0,114,10,54,33,1,4,185,0,54,1  ; n220 t=63.763s dur=2674ms, freq=185Hz, sample=54, buffer_id=01:36
; t 63.7696 Sustain 0 (Instr 1)
; t 63.7696 Sustain 0 (Instr 2)
    db 70,0,101,10,42,33,1,5,92,0,42,1  ; n221 t=63.776s dur=2661ms, freq=92Hz, sample=42, buffer_id=01:2A
    db 148,1,31,10,66,41,1,7,114,1,66,1  ; n222 t=63.846s dur=2591ms, freq=370Hz, sample=66, buffer_id=01:42
; t 64.1553 Sustain 127 (Instr 1)
; t 64.1553 Sustain 127 (Instr 2)
    db 163,1,139,8,59,33,1,0,247,0,59,1  ; n223 t=64.250s dur=2187ms, freq=247Hz, sample=59, buffer_id=01:3B
    db 110,1,232,6,62,33,1,1,38,1,62,1  ; n224 t=64.669s dur=1768ms, freq=294Hz, sample=62, buffer_id=01:3E
    db 148,1,122,5,54,33,1,4,185,0,54,1  ; n225 t=65.036s dur=1402ms, freq=185Hz, sample=54, buffer_id=01:36
    db 149,1,229,3,59,33,1,0,247,0,59,1  ; n226 t=65.440s dur=997ms, freq=247Hz, sample=59, buffer_id=01:3B
    db 209,1,80,2,62,33,1,1,38,1,62,1  ; n227 t=65.845s dur=592ms, freq=294Hz, sample=62, buffer_id=01:3E
    db 26,0,168,11,30,33,1,2,46,0,30,1  ; n228 t=66.310s dur=2984ms, freq=46Hz, sample=30, buffer_id=01:1E
    db 7,0,142,11,54,33,1,4,185,0,54,1  ; n229 t=66.337s dur=2958ms, freq=185Hz, sample=54, buffer_id=01:36
    db 64,0,135,11,42,33,1,5,92,0,42,1  ; n230 t=66.343s dur=2951ms, freq=92Hz, sample=42, buffer_id=01:2A
    db 188,1,71,11,66,41,1,7,114,1,66,1  ; n231 t=66.407s dur=2887ms, freq=370Hz, sample=66, buffer_id=01:42
; t 66.4378 Sustain 0 (Instr 1)
; t 66.4378 Sustain 0 (Instr 2)
; t 66.7265 Sustain 127 (Instr 1)
; t 66.7265 Sustain 127 (Instr 2)
    db 194,1,138,9,58,33,1,0,233,0,58,1  ; n232 t=66.852s dur=2442ms, freq=233Hz, sample=58, buffer_id=01:3A
    db 145,1,201,7,61,33,1,1,21,1,61,1  ; n233 t=67.302s dur=1993ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 216,1,56,6,54,33,1,4,185,0,54,1  ; n234 t=67.702s dur=1592ms, freq=185Hz, sample=54, buffer_id=01:36
    db 163,1,96,4,58,33,1,0,233,0,58,1  ; n235 t=68.174s dur=1120ms, freq=233Hz, sample=58, buffer_id=01:3A
    db 28,2,189,2,61,33,1,1,21,1,61,1  ; n236 t=68.593s dur=701ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 12,0,21,28,35,33,1,3,62,0,35,1  ; n237 t=69.133s dur=7189ms, freq=62Hz, sample=35, buffer_id=01:23
    db 51,0,9,28,47,35,1,6,123,0,47,1  ; n238 t=69.145s dur=7177ms, freq=123Hz, sample=47, buffer_id=01:2F
    db 224,1,91,9,59,43,1,8,247,0,59,1  ; n239 t=69.197s dur=2395ms, freq=247Hz, sample=59, buffer_id=01:3B
; t 69.2946 Sustain 0 (Instr 1)
; t 69.2946 Sustain 0 (Instr 2)
; t 69.6061 Sustain 127 (Instr 1)
; t 69.6061 Sustain 127 (Instr 2)
    db 134,1,123,7,62,33,1,0,38,1,62,1  ; n240 t=69.677s dur=1915ms, freq=294Hz, sample=62, buffer_id=01:3E
    db 118,1,245,5,66,33,1,1,114,1,66,1  ; n241 t=70.067s dur=1525ms, freq=370Hz, sample=66, buffer_id=01:42
    db 103,1,127,4,59,33,1,8,247,0,59,1  ; n242 t=70.440s dur=1151ms, freq=247Hz, sample=59, buffer_id=01:3B
    db 124,1,24,3,62,33,1,0,38,1,62,1  ; n243 t=70.800s dur=792ms, freq=294Hz, sample=62, buffer_id=01:3E
    db 121,1,231,1,66,33,1,1,114,1,66,1  ; n244 t=71.180s dur=487ms, freq=370Hz, sample=66, buffer_id=01:42
; t 71.2732 Soft 0 (Instr 1)
; t 71.2732 Soft 0 (Instr 2)
    db 172,1,0,5,59,33,1,8,247,0,59,1  ; n245 t=71.556s dur=1280ms, freq=247Hz, sample=59, buffer_id=01:3B
; t 71.5922 Sustain 0 (Instr 1)
; t 71.5922 Sustain 0 (Instr 2)
; t 71.8371 Sustain 127 (Instr 1)
; t 71.8371 Sustain 127 (Instr 2)
    db 115,1,84,3,63,33,1,0,55,1,63,1  ; n246 t=71.984s dur=852ms, freq=311Hz, sample=63, buffer_id=01:3F
    db 183,1,225,1,66,36,1,1,114,1,66,1  ; n247 t=72.355s dur=481ms, freq=370Hz, sample=66, buffer_id=01:42
    db 2,0,66,5,71,58,2,2,238,1,71,1  ; n248 t=72.794s dur=1346ms, freq=494Hz, sample=71, buffer_id=01:47
    db 214,1,64,5,59,42,1,8,247,0,59,1  ; n249 t=72.796s dur=1344ms, freq=247Hz, sample=59, buffer_id=01:3B
; t 72.8365 Sustain 0 (Instr 1)
; t 72.8365 Sustain 0 (Instr 2)
; t 73.1500 Sustain 127 (Instr 1)
; t 73.1500 Sustain 127 (Instr 2)
    db 141,1,106,3,63,36,1,0,55,1,63,1  ; n250 t=73.266s dur=874ms, freq=311Hz, sample=63, buffer_id=01:3F
    db 120,1,220,1,66,38,1,1,114,1,66,1  ; n251 t=73.664s dur=476ms, freq=370Hz, sample=66, buffer_id=01:42
    db 17,0,235,8,59,50,1,8,247,0,59,1  ; n252 t=74.039s dur=2283ms, freq=247Hz, sample=59, buffer_id=01:3B
    db 179,1,9,14,72,59,2,4,11,2,72,1  ; n253 t=74.057s dur=3593ms, freq=523Hz, sample=72, buffer_id=01:48
; t 74.1407 Sustain 0 (Instr 1)
; t 74.1407 Sustain 0 (Instr 2)
; t 74.4030 Sustain 127 (Instr 1)
; t 74.4030 Sustain 127 (Instr 2)
    db 136,1,38,7,64,52,1,0,74,1,64,1  ; n254 t=74.492s dur=1830ms, freq=330Hz, sample=64, buffer_id=01:40
    db 233,0,158,5,67,49,2,1,136,1,67,1  ; n255 t=74.884s dur=1438ms, freq=392Hz, sample=67, buffer_id=01:43
    db 3,0,181,4,40,53,1,2,82,0,40,1  ; n256 t=75.117s dur=1205ms, freq=82Hz, sample=40, buffer_id=01:28
    db 73,0,178,4,52,53,1,5,165,0,52,1  ; n257 t=75.120s dur=1202ms, freq=165Hz, sample=52, buffer_id=01:34
    db 130,1,105,4,59,54,1,8,247,0,59,1  ; n258 t=75.193s dur=1129ms, freq=247Hz, sample=59, buffer_id=01:3B
    db 101,1,7,3,64,49,1,0,74,1,64,1  ; n259 t=75.579s dur=775ms, freq=330Hz, sample=64, buffer_id=01:40
    db 3,1,130,1,67,38,2,1,136,1,67,1  ; n260 t=75.936s dur=386ms, freq=392Hz, sample=67, buffer_id=01:43
    db 12,0,174,5,43,52,1,7,98,0,43,1  ; n261 t=76.195s dur=1454ms, freq=98Hz, sample=43, buffer_id=01:2B
    db 52,0,162,5,55,52,1,9,196,0,55,1  ; n262 t=76.207s dur=1442ms, freq=196Hz, sample=55, buffer_id=01:37
; t 76.2357 Soft 127 (Instr 1)
; t 76.2357 Soft 127 (Instr 2)
    db 197,1,110,5,59,37,1,8,247,0,59,1  ; n263 t=76.260s dur=1390ms, freq=247Hz, sample=59, buffer_id=01:3B
; t 76.3227 Sustain 0 (Instr 1)
; t 76.3227 Sustain 0 (Instr 2)
; t 76.5600 Sustain 127 (Instr 1)
; t 76.5600 Sustain 127 (Instr 2)
    db 161,1,191,3,64,33,1,0,74,1,64,1  ; n264 t=76.712s dur=959ms, freq=330Hz, sample=64, buffer_id=01:40
    db 146,1,9,2,67,39,2,1,136,1,67,1  ; n265 t=77.129s dur=521ms, freq=392Hz, sample=67, buffer_id=01:43
    db 57,0,168,4,40,36,1,2,82,0,40,1  ; n266 t=77.531s dur=1192ms, freq=82Hz, sample=40, buffer_id=01:28
    db 13,0,48,1,52,36,1,3,165,0,52,1  ; n267 t=77.587s dur=304ms, freq=165Hz, sample=52, buffer_id=01:34
    db 4,0,98,4,59,35,1,8,247,0,59,1  ; n268 t=77.600s dur=1122ms, freq=247Hz, sample=59, buffer_id=01:3B
    db 132,1,94,4,70,46,2,5,210,1,70,1  ; n269 t=77.605s dur=1118ms, freq=466Hz, sample=70, buffer_id=01:46
; t 77.6503 Sustain 0 (Instr 1)
; t 77.6503 Sustain 0 (Instr 2)
; t 77.8941 Sustain 127 (Instr 1)
; t 77.8941 Sustain 127 (Instr 2)
    db 110,1,254,2,64,33,1,0,74,1,64,1  ; n270 t=77.993s dur=766ms, freq=330Hz, sample=64, buffer_id=01:40
    db 247,0,143,1,67,38,2,1,136,1,67,1  ; n271 t=78.359s dur=399ms, freq=392Hz, sample=67, buffer_id=01:43
    db 10,0,174,25,35,37,1,3,62,0,35,1  ; n272 t=78.606s dur=6574ms, freq=62Hz, sample=35, buffer_id=01:23
    db 90,0,164,25,47,37,1,4,123,0,47,1  ; n273 t=78.616s dur=6564ms, freq=123Hz, sample=47, buffer_id=01:2F
    db 29,0,248,12,59,36,1,8,247,0,59,1  ; n274 t=78.706s dur=3320ms, freq=247Hz, sample=59, buffer_id=01:3B
; t 78.7233 Sustain 0 (Instr 1)
; t 78.7233 Sustain 0 (Instr 2)
    db 136,1,219,12,71,43,2,6,238,1,71,1  ; n275 t=78.735s dur=3291ms, freq=494Hz, sample=71, buffer_id=01:47
; t 79.0474 Sustain 127 (Instr 1)
; t 79.0474 Sustain 127 (Instr 2)
    db 77,1,83,11,63,33,1,0,55,1,63,1  ; n276 t=79.127s dur=2899ms, freq=311Hz, sample=63, buffer_id=01:3F
    db 93,1,7,10,66,33,1,1,114,1,66,1  ; n277 t=79.460s dur=2567ms, freq=370Hz, sample=66, buffer_id=01:42
; t 79.6718 Soft 0 (Instr 1)
; t 79.6718 Soft 0 (Instr 2)
    db 103,1,169,8,59,33,1,8,247,0,59,1  ; n278 t=79.809s dur=2217ms, freq=247Hz, sample=59, buffer_id=01:3B
    db 91,1,66,7,63,33,1,0,55,1,63,1  ; n279 t=80.168s dur=1858ms, freq=311Hz, sample=63, buffer_id=01:3F
    db 88,1,232,5,66,36,1,1,114,1,66,1  ; n280 t=80.515s dur=1512ms, freq=370Hz, sample=66, buffer_id=01:42
    db 89,1,144,4,59,41,1,8,247,0,59,1  ; n281 t=80.859s dur=1168ms, freq=247Hz, sample=59, buffer_id=01:3B
    db 86,1,55,3,63,42,1,0,55,1,63,1  ; n282 t=81.203s dur=823ms, freq=311Hz, sample=63, buffer_id=01:3F
    db 141,1,225,1,66,37,1,1,114,1,66,1  ; n283 t=81.545s dur=481ms, freq=370Hz, sample=66, buffer_id=01:42
    db 9,0,99,4,71,54,2,6,238,1,71,1  ; n284 t=81.942s dur=1123ms, freq=494Hz, sample=71, buffer_id=01:47
    db 116,1,90,4,59,42,1,8,247,0,59,1  ; n285 t=81.951s dur=1114ms, freq=247Hz, sample=59, buffer_id=01:3B
; t 82.0268 Sustain 0 (Instr 1)
; t 82.0268 Sustain 0 (Instr 2)
    db 78,1,230,2,63,41,1,0,55,1,63,1  ; n286 t=82.323s dur=742ms, freq=311Hz, sample=63, buffer_id=01:3F
; t 82.3292 Sustain 127 (Instr 1)
; t 82.3292 Sustain 127 (Instr 2)
    db 56,1,152,1,66,36,1,1,114,1,66,1  ; n287 t=82.656s dur=408ms, freq=370Hz, sample=66, buffer_id=01:42
    db 17,0,163,8,59,40,1,8,247,0,59,1  ; n288 t=82.969s dur=2211ms, freq=247Hz, sample=59, buffer_id=01:3B
    db 142,1,181,13,72,56,2,2,11,2,72,1  ; n289 t=82.986s dur=3509ms, freq=523Hz, sample=72, buffer_id=01:48
; t 83.0654 Sustain 0 (Instr 1)
; t 83.0654 Sustain 0 (Instr 2)
    db 135,1,4,7,64,39,1,0,74,1,64,1  ; n290 t=83.384s dur=1796ms, freq=330Hz, sample=64, buffer_id=01:40
; t 83.4111 Sustain 127 (Instr 1)
; t 83.4111 Sustain 127 (Instr 2)
    db 247,0,124,5,67,40,2,1,136,1,67,1  ; n291 t=83.775s dur=1404ms, freq=392Hz, sample=67, buffer_id=01:43
    db 7,0,134,4,52,42,1,5,165,0,52,1  ; n292 t=84.022s dur=1158ms, freq=165Hz, sample=52, buffer_id=01:34
    db 67,0,127,4,40,43,1,6,82,0,40,1  ; n293 t=84.029s dur=1151ms, freq=82Hz, sample=40, buffer_id=01:28
    db 66,1,60,4,59,43,1,8,247,0,59,1  ; n294 t=84.096s dur=1084ms, freq=247Hz, sample=59, buffer_id=01:3B
    db 123,1,250,2,64,38,1,0,74,1,64,1  ; n295 t=84.418s dur=762ms, freq=330Hz, sample=64, buffer_id=01:40
    db 17,1,162,6,67,38,2,1,136,1,67,1  ; n296 t=84.797s dur=1698ms, freq=392Hz, sample=67, buffer_id=01:43
    db 11,0,145,5,43,40,1,7,98,0,43,1  ; n297 t=85.070s dur=1425ms, freq=98Hz, sample=43, buffer_id=01:2B
    db 51,0,134,5,55,42,1,9,196,0,55,1  ; n298 t=85.081s dur=1414ms, freq=196Hz, sample=55, buffer_id=01:37
    db 155,1,83,5,59,40,1,8,247,0,59,1  ; n299 t=85.132s dur=1363ms, freq=247Hz, sample=59, buffer_id=01:3B
; t 85.1802 Sustain 0 (Instr 1)
; t 85.1802 Sustain 0 (Instr 2)
; t 85.4618 Sustain 127 (Instr 1)
; t 85.4618 Sustain 127 (Instr 2)
    db 167,1,236,3,64,33,1,0,74,1,64,1  ; n300 t=85.543s dur=1004ms, freq=330Hz, sample=64, buffer_id=01:40
    db 137,1,29,2,67,40,2,1,136,1,67,1  ; n301 t=85.966s dur=541ms, freq=392Hz, sample=67, buffer_id=01:43
    db 38,0,170,4,40,39,1,3,82,0,40,1  ; n302 t=86.359s dur=1194ms, freq=82Hz, sample=40, buffer_id=01:28
    db 57,0,132,4,52,38,1,4,165,0,52,1  ; n303 t=86.397s dur=1156ms, freq=165Hz, sample=52, buffer_id=01:34
    db 14,0,75,4,70,47,2,5,210,1,70,1  ; n304 t=86.454s dur=1099ms, freq=466Hz, sample=70, buffer_id=01:46
    db 129,1,61,4,59,37,1,8,247,0,59,1  ; n305 t=86.468s dur=1085ms, freq=247Hz, sample=59, buffer_id=01:3B
; t 86.4959 Sustain 0 (Instr 1)
; t 86.4959 Sustain 0 (Instr 2)
; t 86.7469 Sustain 127 (Instr 1)
; t 86.7469 Sustain 127 (Instr 2)
    db 108,1,22,3,64,33,1,0,74,1,64,1  ; n306 t=86.852s dur=790ms, freq=330Hz, sample=64, buffer_id=01:40
    db 224,0,176,1,67,39,2,1,136,1,67,1  ; n307 t=87.216s dur=432ms, freq=392Hz, sample=67, buffer_id=01:43
    db 25,0,169,9,35,39,1,2,62,0,35,1  ; n308 t=87.440s dur=2473ms, freq=62Hz, sample=35, buffer_id=01:23
    db 117,0,144,9,47,39,1,6,123,0,47,1  ; n309 t=87.465s dur=2448ms, freq=123Hz, sample=47, buffer_id=01:2F
; t 87.5534 Sustain 0 (Instr 1)
; t 87.5534 Sustain 0 (Instr 2)
    db 4,0,27,9,59,37,1,8,247,0,59,1  ; n310 t=87.583s dur=2331ms, freq=247Hz, sample=59, buffer_id=01:3B
    db 153,1,22,9,71,44,2,7,238,1,71,1  ; n311 t=87.587s dur=2326ms, freq=494Hz, sample=71, buffer_id=01:47
; t 87.8816 Sustain 127 (Instr 1)
; t 87.8816 Sustain 127 (Instr 2)
    db 138,1,126,7,63,33,1,0,55,1,63,1  ; n312 t=87.996s dur=1918ms, freq=311Hz, sample=63, buffer_id=01:3F
    db 139,1,243,5,66,38,1,1,114,1,66,1  ; n313 t=88.390s dur=1523ms, freq=370Hz, sample=66, buffer_id=01:42
    db 129,1,105,4,59,33,1,8,247,0,59,1  ; n314 t=88.785s dur=1129ms, freq=247Hz, sample=59, buffer_id=01:3B
    db 134,1,232,2,63,33,1,0,55,1,63,1  ; n315 t=89.170s dur=744ms, freq=311Hz, sample=63, buffer_id=01:3F
    db 174,0,163,1,66,37,1,1,114,1,66,1  ; n316 t=89.560s dur=419ms, freq=370Hz, sample=66, buffer_id=01:42
    db 56,0,173,9,32,39,1,3,52,0,32,1  ; n317 t=89.734s dur=2477ms, freq=52Hz, sample=32, buffer_id=01:20
    db 141,0,116,9,44,39,1,4,104,0,44,1  ; n318 t=89.790s dur=2420ms, freq=104Hz, sample=44, buffer_id=01:2C
; t 89.9141 Sustain 0 (Instr 1)
; t 89.9141 Sustain 0 (Instr 2)
    db 2,0,231,8,71,52,2,7,238,1,71,1  ; n319 t=89.931s dur=2279ms, freq=494Hz, sample=71, buffer_id=01:47
    db 134,1,229,8,59,37,1,8,247,0,59,1  ; n320 t=89.934s dur=2277ms, freq=247Hz, sample=59, buffer_id=01:3B
; t 90.3163 Sustain 127 (Instr 1)
; t 90.3163 Sustain 127 (Instr 2)
    db 97,1,95,7,62,33,1,0,38,1,62,1  ; n321 t=90.324s dur=1887ms, freq=294Hz, sample=62, buffer_id=01:3E
    db 109,1,254,5,65,33,1,1,93,1,65,1  ; n322 t=90.677s dur=1534ms, freq=349Hz, sample=65, buffer_id=01:41
    db 122,1,144,4,59,33,1,8,247,0,59,1  ; n323 t=91.042s dur=1168ms, freq=247Hz, sample=59, buffer_id=01:3B
    db 120,1,22,3,62,33,1,0,38,1,62,1  ; n324 t=91.420s dur=790ms, freq=294Hz, sample=62, buffer_id=01:3E
    db 206,0,159,1,65,33,1,1,93,1,65,1  ; n325 t=91.796s dur=415ms, freq=349Hz, sample=65, buffer_id=01:41
    db 30,0,183,9,29,36,1,2,44,0,29,1  ; n326 t=92.002s dur=2487ms, freq=44Hz, sample=29, buffer_id=01:1D
    db 157,0,153,9,41,36,1,5,87,0,41,1  ; n327 t=92.033s dur=2457ms, freq=87Hz, sample=41, buffer_id=01:29
    db 12,0,252,8,59,34,1,8,247,0,59,1  ; n328 t=92.189s dur=2300ms, freq=247Hz, sample=59, buffer_id=01:3B
    db 130,1,241,8,71,42,2,7,238,1,71,1  ; n329 t=92.201s dur=2289ms, freq=494Hz, sample=71, buffer_id=01:47
; t 92.2111 Sustain 0 (Instr 1)
; t 92.2111 Sustain 0 (Instr 2)
    db 134,1,111,7,61,33,1,0,21,1,61,1  ; n330 t=92.587s dur=1903ms, freq=277Hz, sample=61, buffer_id=01:3D
; t 92.6065 Sustain 127 (Instr 1)
; t 92.6065 Sustain 127 (Instr 2)
    db 123,1,233,5,68,38,2,1,159,1,68,1  ; n331 t=92.977s dur=1513ms, freq=415Hz, sample=68, buffer_id=01:44
    db 79,1,110,4,59,33,1,8,247,0,59,1  ; n332 t=93.356s dur=1134ms, freq=247Hz, sample=59, buffer_id=01:3B
    db 127,1,84,3,61,33,1,0,21,1,61,1  ; n333 t=93.691s dur=852ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 220,0,181,1,68,43,2,1,159,1,68,1  ; n334 t=94.074s dur=437ms, freq=415Hz, sample=68, buffer_id=01:44
    db 51,0,180,9,30,37,1,3,46,0,30,1  ; n335 t=94.294s dur=2484ms, freq=46Hz, sample=30, buffer_id=01:1E
    db 135,0,129,9,42,38,1,4,92,0,42,1  ; n336 t=94.345s dur=2433ms, freq=92Hz, sample=42, buffer_id=01:2A
    db 10,0,251,8,57,39,1,6,220,0,57,1  ; n337 t=94.480s dur=2299ms, freq=220Hz, sample=57, buffer_id=01:39
    db 123,1,241,8,69,48,2,9,184,1,69,1  ; n338 t=94.489s dur=2289ms, freq=440Hz, sample=69, buffer_id=01:45
; t 94.4904 Sustain 0 (Instr 1)
; t 94.4904 Sustain 0 (Instr 2)
    db 147,1,118,7,61,33,1,0,21,1,61,1  ; n339 t=94.868s dur=1910ms, freq=277Hz, sample=61, buffer_id=01:3D
; t 94.8987 Sustain 127 (Instr 1)
; t 94.8987 Sustain 127 (Instr 2)
    db 132,1,227,5,66,33,1,1,114,1,66,1  ; n340 t=95.271s dur=1507ms, freq=370Hz, sample=66, buffer_id=01:42
    db 121,1,95,4,57,33,1,6,220,0,57,1  ; n341 t=95.659s dur=1119ms, freq=220Hz, sample=57, buffer_id=01:39
    db 83,1,71,3,61,33,1,0,21,1,61,1  ; n342 t=96.036s dur=839ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 240,0,230,1,66,33,1,1,114,1,66,1  ; n343 t=96.375s dur=486ms, freq=370Hz, sample=66, buffer_id=01:42
    db 37,0,45,10,35,36,1,2,62,0,35,1  ; n344 t=96.615s dur=2605ms, freq=62Hz, sample=35, buffer_id=01:23
    db 133,0,7,10,47,35,1,5,123,0,47,1  ; n345 t=96.652s dur=2567ms, freq=123Hz, sample=47, buffer_id=01:2F
; t 96.7786 Sustain 0 (Instr 1)
; t 96.7786 Sustain 0 (Instr 2)
    db 11,0,130,9,55,33,1,7,196,0,55,1  ; n346 t=96.785s dur=2434ms, freq=196Hz, sample=55, buffer_id=01:37
    db 149,1,119,9,67,44,2,8,136,1,67,1  ; n347 t=96.796s dur=2423ms, freq=392Hz, sample=67, buffer_id=01:43
    db 144,1,226,7,59,33,1,0,247,0,59,1  ; n348 t=97.201s dur=2018ms, freq=247Hz, sample=59, buffer_id=01:3B
; t 97.3227 Sustain 127 (Instr 1)
; t 97.3227 Sustain 127 (Instr 2)
    db 131,1,82,6,62,33,1,1,38,1,62,1  ; n349 t=97.601s dur=1618ms, freq=294Hz, sample=62, buffer_id=01:3E
    db 141,1,208,4,55,33,1,7,196,0,55,1  ; n350 t=97.987s dur=1232ms, freq=196Hz, sample=55, buffer_id=01:37
; t 98.3804 Soft 127 (Instr 1)
; t 98.3804 Soft 127 (Instr 2)
    db 114,1,66,3,59,33,1,0,247,0,59,1  ; n351 t=98.385s dur=834ms, freq=247Hz, sample=59, buffer_id=01:3B
    db 17,1,208,1,62,33,1,1,38,1,62,1  ; n352 t=98.755s dur=464ms, freq=294Hz, sample=62, buffer_id=01:3E
    db 59,0,0,11,36,33,1,3,65,0,36,1  ; n353 t=99.028s dur=2816ms, freq=65Hz, sample=36, buffer_id=01:24
    db 63,0,197,10,48,33,1,4,131,0,48,1  ; n354 t=99.087s dur=2757ms, freq=131Hz, sample=48, buffer_id=01:30
    db 43,0,134,10,54,33,1,6,185,0,54,1  ; n355 t=99.150s dur=2694ms, freq=185Hz, sample=54, buffer_id=01:36
    db 208,1,90,10,66,39,1,9,114,1,66,1  ; n356 t=99.194s dur=2650ms, freq=370Hz, sample=66, buffer_id=01:42
; t 99.2196 Sustain 0 (Instr 1)
; t 99.2196 Sustain 0 (Instr 2)
; t 99.4617 Sustain 127 (Instr 1)
; t 99.4617 Sustain 127 (Instr 2)
    db 187,1,139,8,57,33,1,0,220,0,57,1  ; n357 t=99.657s dur=2187ms, freq=220Hz, sample=57, buffer_id=01:39
    db 109,1,208,6,63,33,1,1,55,1,63,1  ; n358 t=100.100s dur=1744ms, freq=311Hz, sample=63, buffer_id=01:3F
    db 164,1,99,5,54,33,1,6,185,0,54,1  ; n359 t=100.465s dur=1379ms, freq=185Hz, sample=54, buffer_id=01:36
    db 203,1,191,3,57,33,1,0,220,0,57,1  ; n360 t=100.885s dur=959ms, freq=220Hz, sample=57, buffer_id=01:39
    db 239,1,244,1,63,33,1,1,55,1,63,1  ; n361 t=101.344s dur=500ms, freq=311Hz, sample=63, buffer_id=01:3F
    db 8,0,55,10,49,33,1,2,139,0,49,1  ; n362 t=101.839s dur=2615ms, freq=139Hz, sample=49, buffer_id=01:31
; t 101.8445 Sustain 0 (Instr 1)
; t 101.8445 Sustain 0 (Instr 2)
    db 37,0,47,10,37,33,1,5,69,0,37,1  ; n363 t=101.847s dur=2607ms, freq=69Hz, sample=37, buffer_id=01:25
    db 205,1,10,10,61,36,1,7,21,1,61,1  ; n364 t=101.884s dur=2570ms, freq=277Hz, sample=61, buffer_id=01:3D
; t 102.2017 Sustain 127 (Instr 1)
; t 102.2017 Sustain 127 (Instr 2)
    db 128,1,61,8,54,33,1,0,185,0,54,1  ; n365 t=102.345s dur=2109ms, freq=185Hz, sample=54, buffer_id=01:36
    db 150,1,189,6,57,33,1,1,220,0,57,1  ; n366 t=102.729s dur=1725ms, freq=220Hz, sample=57, buffer_id=01:39
; t 103.0112 Soft 127 (Instr 1)
; t 103.0112 Soft 127 (Instr 2)
    db 141,1,39,5,49,33,1,2,139,0,49,1  ; n367 t=103.135s dur=1319ms, freq=139Hz, sample=49, buffer_id=01:31
    db 143,1,154,3,54,33,1,0,185,0,54,1  ; n368 t=103.532s dur=922ms, freq=185Hz, sample=54, buffer_id=01:36
    db 243,1,11,2,57,33,1,1,220,0,57,1  ; n369 t=103.931s dur=523ms, freq=220Hz, sample=57, buffer_id=01:39
    db 4,0,201,11,37,33,1,5,69,0,37,1  ; n370 t=104.431s dur=3017ms, freq=69Hz, sample=37, buffer_id=01:25
    db 2,0,180,5,49,33,1,2,139,0,49,1  ; n371 t=104.435s dur=1460ms, freq=139Hz, sample=49, buffer_id=01:31
    db 37,0,194,11,29,33,1,3,35,0,29,1  ; n372 t=104.437s dur=3010ms, freq=35Hz, sample=29, buffer_id=01:1D
; t 104.4544 Sustain 0 (Instr 1)
; t 104.4544 Sustain 0 (Instr 2)
    db 186,1,141,5,61,37,1,7,21,1,61,1  ; n373 t=104.474s dur=1421ms, freq=277Hz, sample=61, buffer_id=01:3D
; t 104.8950 Sustain 127 (Instr 1)
; t 104.8950 Sustain 127 (Instr 2)
    db 172,1,211,3,54,33,1,0,185,0,54,1  ; n374 t=104.916s dur=979ms, freq=185Hz, sample=54, buffer_id=01:36
    db 237,1,105,2,56,33,1,1,208,0,56,1  ; n375 t=105.343s dur=617ms, freq=208Hz, sample=56, buffer_id=01:38
    db 14,0,75,6,49,33,1,2,139,0,49,1  ; n376 t=105.836s dur=1611ms, freq=139Hz, sample=49, buffer_id=01:31
    db 0,2,61,6,61,35,1,7,21,1,61,1  ; n377 t=105.850s dur=1597ms, freq=277Hz, sample=61, buffer_id=01:3D
; t 105.8955 Sustain 0 (Instr 1)
; t 105.8955 Sustain 0 (Instr 2)
    db 5,2,61,4,53,33,1,0,175,0,53,1  ; n378 t=106.362s dur=1085ms, freq=175Hz, sample=53, buffer_id=01:35
; t 106.3945 Sustain 127 (Instr 1)
; t 106.3945 Sustain 127 (Instr 2)
    db 131,1,56,2,56,33,1,1,208,0,56,1  ; n379 t=106.879s dur=568ms, freq=208Hz, sample=56, buffer_id=01:38
    db 13,0,19,20,42,33,1,4,92,0,42,1  ; n380 t=107.267s dur=5139ms, freq=92Hz, sample=42, buffer_id=01:2A
    db 38,0,6,20,30,34,1,6,46,0,30,1  ; n381 t=107.280s dur=5126ms, freq=46Hz, sample=30, buffer_id=01:1E
    db 249,1,224,19,54,41,1,8,185,0,54,1  ; n382 t=107.318s dur=5088ms, freq=185Hz, sample=54, buffer_id=01:36
; t 107.4478 Sustain 0 (Instr 1)
; t 107.4478 Sustain 0 (Instr 2)
; t 107.6897 Sustain 127 (Instr 1)
; t 107.6897 Sustain 127 (Instr 2)
    db 141,1,230,17,57,33,1,0,220,0,57,1  ; n383 t=107.823s dur=4582ms, freq=220Hz, sample=57, buffer_id=01:39
    db 136,1,89,16,61,33,1,1,21,1,61,1  ; n384 t=108.220s dur=4185ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 100,1,210,14,57,33,1,0,220,0,57,1  ; n385 t=108.612s dur=3794ms, freq=220Hz, sample=57, buffer_id=01:39
    db 69,1,110,13,61,33,1,1,21,1,61,1  ; n386 t=108.968s dur=3438ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 140,1,41,12,66,33,1,2,114,1,66,1  ; n387 t=109.293s dur=3113ms, freq=370Hz, sample=66, buffer_id=01:42
    db 121,1,157,10,61,33,1,1,21,1,61,1  ; n388 t=109.689s dur=2717ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 140,1,35,9,66,33,1,2,114,1,66,1  ; n389 t=110.066s dur=2339ms, freq=370Hz, sample=66, buffer_id=01:42
    db 188,1,152,7,69,38,2,3,184,1,69,1  ; n390 t=110.462s dur=1944ms, freq=440Hz, sample=69, buffer_id=01:45
    db 61,0,220,5,61,33,1,1,21,1,61,1  ; n391 t=110.906s dur=1500ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 192,1,159,5,73,51,2,5,42,2,73,1  ; n392 t=110.966s dur=1439ms, freq=554Hz, sample=73, buffer_id=01:49
    db 157,1,224,3,66,33,1,2,114,1,66,1  ; n393 t=111.414s dur=992ms, freq=370Hz, sample=66, buffer_id=01:42
    db 81,1,66,2,69,38,2,3,184,1,69,1  ; n394 t=111.827s dur=578ms, freq=440Hz, sample=69, buffer_id=01:45
    db 109,0,241,0,73,42,2,5,42,2,73,1  ; n395 t=112.164s dur=241ms, freq=554Hz, sample=73, buffer_id=01:49
    db 21,0,190,18,41,36,1,7,87,0,41,1  ; n396 t=112.274s dur=4798ms, freq=87Hz, sample=41, buffer_id=01:29
    db 39,0,170,18,49,36,1,9,139,0,49,1  ; n397 t=112.294s dur=4778ms, freq=139Hz, sample=49, buffer_id=01:31
    db 29,0,131,18,53,36,1,10,175,0,53,1  ; n398 t=112.334s dur=4739ms, freq=175Hz, sample=53, buffer_id=01:35
    db 21,0,91,13,73,52,2,5,42,2,73,1  ; n399 t=112.363s dur=3419ms, freq=554Hz, sample=73, buffer_id=01:49
    db 82,1,70,13,61,37,1,1,21,1,61,1  ; n400 t=112.383s dur=3398ms, freq=277Hz, sample=61, buffer_id=01:3D
; t 112.4061 Sustain 0 (Instr 1)
; t 112.4061 Sustain 0 (Instr 2)
    db 145,1,244,11,68,38,2,0,159,1,68,1  ; n401 t=112.722s dur=3060ms, freq=415Hz, sample=68, buffer_id=01:44
; t 112.8073 Sustain 127 (Instr 1)
; t 112.8073 Sustain 127 (Instr 2)
    db 73,1,99,10,71,38,2,2,238,1,71,1  ; n402 t=113.123s dur=2659ms, freq=494Hz, sample=71, buffer_id=01:47
    db 149,1,26,9,61,33,1,1,21,1,61,1  ; n403 t=113.451s dur=2330ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 115,1,132,7,68,38,2,0,159,1,68,1  ; n404 t=113.857s dur=1924ms, freq=415Hz, sample=68, buffer_id=01:44
    db 124,1,18,6,71,38,2,2,238,1,71,1  ; n405 t=114.228s dur=1554ms, freq=494Hz, sample=71, buffer_id=01:47
    db 118,1,149,4,61,33,1,1,21,1,61,1  ; n406 t=114.608s dur=1173ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 64,1,40,3,68,38,2,0,159,1,68,1  ; n407 t=114.982s dur=808ms, freq=415Hz, sample=68, buffer_id=01:44
    db 193,1,250,1,71,38,2,2,238,1,71,1  ; n408 t=115.302s dur=506ms, freq=494Hz, sample=71, buffer_id=01:47
    db 11,0,42,5,61,37,1,1,21,1,61,1  ; n409 t=115.750s dur=1322ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 186,1,31,5,73,48,2,5,42,2,73,1  ; n410 t=115.761s dur=1311ms, freq=554Hz, sample=73, buffer_id=01:49
; t 115.7818 Sustain 0 (Instr 1)
; t 115.7818 Sustain 0 (Instr 2)
; t 116.0181 Sustain 127 (Instr 1)
; t 116.0181 Sustain 127 (Instr 2)
    db 76,1,101,3,68,38,2,0,159,1,68,1  ; n411 t=116.203s dur=869ms, freq=415Hz, sample=68, buffer_id=01:44
    db 17,1,25,2,71,38,2,2,238,1,71,1  ; n412 t=116.535s dur=537ms, freq=494Hz, sample=71, buffer_id=01:47
    db 138,0,8,1,73,42,2,5,42,2,73,1  ; n413 t=116.808s dur=264ms, freq=554Hz, sample=73, buffer_id=01:49
    db 18,0,6,9,42,36,1,3,92,0,42,1  ; n414 t=116.946s dur=2310ms, freq=92Hz, sample=42, buffer_id=01:2A
    db 81,0,243,8,54,37,1,4,185,0,54,1  ; n415 t=116.964s dur=2291ms, freq=185Hz, sample=54, buffer_id=01:36
    db 7,0,162,8,73,54,2,5,42,2,73,1  ; n416 t=117.046s dur=2210ms, freq=554Hz, sample=73, buffer_id=01:49
    db 105,1,155,8,61,37,1,1,21,1,61,1  ; n417 t=117.052s dur=2203ms, freq=277Hz, sample=61, buffer_id=01:3D
; t 117.0726 Sustain 0 (Instr 1)
; t 117.0726 Sustain 0 (Instr 2)
; t 117.3924 Sustain 127 (Instr 1)
; t 117.3924 Sustain 127 (Instr 2)
    db 107,1,51,7,66,33,1,0,114,1,66,1  ; n418 t=117.413s dur=1843ms, freq=370Hz, sample=66, buffer_id=01:42
    db 95,1,199,5,69,38,2,2,184,1,69,1  ; n419 t=117.776s dur=1479ms, freq=440Hz, sample=69, buffer_id=01:45
    db 138,1,104,4,61,33,1,1,21,1,61,1  ; n420 t=118.127s dur=1128ms, freq=277Hz, sample=61, buffer_id=01:3D
; t 118.1357 Soft 0 (Instr 1)
; t 118.1357 Soft 0 (Instr 2)
    db 119,1,24,3,66,33,1,0,114,1,66,1  ; n421 t=118.521s dur=792ms, freq=370Hz, sample=66, buffer_id=01:42
    db 232,0,148,1,69,41,2,2,184,1,69,1  ; n422 t=118.896s dur=404ms, freq=440Hz, sample=69, buffer_id=01:45
    db 30,0,240,4,39,39,1,6,78,0,39,1  ; n423 t=119.128s dur=1264ms, freq=78Hz, sample=39, buffer_id=01:27
    db 115,0,209,4,51,39,1,7,156,0,51,1  ; n424 t=119.159s dur=1233ms, freq=156Hz, sample=51, buffer_id=01:33
; t 119.2560 Sustain 0 (Instr 1)
; t 119.2560 Sustain 0 (Instr 2)
    db 2,0,95,4,72,46,2,8,11,2,72,1  ; n425 t=119.273s dur=1119ms, freq=523Hz, sample=72, buffer_id=01:48
    db 141,1,93,4,60,37,1,9,6,1,60,1  ; n426 t=119.275s dur=1117ms, freq=262Hz, sample=60, buffer_id=01:3C
; t 119.6016 Sustain 127 (Instr 1)
; t 119.6016 Sustain 127 (Instr 2)
    db 68,1,230,2,66,33,1,0,114,1,66,1  ; n427 t=119.672s dur=742ms, freq=370Hz, sample=66, buffer_id=01:42
    db 238,0,162,1,69,39,2,1,184,1,69,1  ; n428 t=119.996s dur=418ms, freq=440Hz, sample=69, buffer_id=01:45
    db 12,0,47,5,37,37,1,2,69,0,37,1  ; n429 t=120.234s dur=1327ms, freq=69Hz, sample=37, buffer_id=01:25
    db 115,0,35,5,49,37,1,3,139,0,49,1  ; n430 t=120.246s dur=1315ms, freq=139Hz, sample=49, buffer_id=01:31
    db 3,0,176,4,61,36,1,4,21,1,61,1  ; n431 t=120.361s dur=1200ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 147,1,173,4,73,44,2,5,42,2,73,1  ; n432 t=120.364s dur=1197ms, freq=554Hz, sample=73, buffer_id=01:49
; t 120.3925 Sustain 0 (Instr 1)
; t 120.3925 Sustain 0 (Instr 2)
    db 100,1,26,3,66,33,1,0,114,1,66,1  ; n433 t=120.767s dur=794ms, freq=370Hz, sample=66, buffer_id=01:42
; t 120.7879 Sustain 127 (Instr 1)
; t 120.7879 Sustain 127 (Instr 2)
    db 14,1,194,1,69,39,2,1,184,1,69,1  ; n434 t=121.124s dur=450ms, freq=440Hz, sample=69, buffer_id=01:45
; t 121.1975 Soft 0 (Instr 1)
; t 121.1975 Soft 0 (Instr 2)
    db 6,0,251,12,36,36,1,6,65,0,36,1  ; n435 t=121.394s dur=3323ms, freq=65Hz, sample=36, buffer_id=01:24
    db 0,0,245,12,44,36,1,7,104,0,44,1  ; n436 t=121.400s dur=3317ms, freq=104Hz, sample=44, buffer_id=01:2C
    db 107,0,245,12,48,36,1,8,131,0,48,1  ; n437 t=121.400s dur=3317ms, freq=131Hz, sample=48, buffer_id=01:30
    db 2,0,137,12,75,44,2,9,110,2,75,1  ; n438 t=121.507s dur=3209ms, freq=622Hz, sample=75, buffer_id=01:4B
    db 127,1,135,12,63,35,1,10,55,1,63,1  ; n439 t=121.510s dur=3207ms, freq=311Hz, sample=63, buffer_id=01:3F
; t 121.5615 Sustain 0 (Instr 1)
; t 121.5615 Sustain 0 (Instr 2)
    db 48,1,8,11,66,33,1,0,114,1,66,1  ; n440 t=121.893s dur=2824ms, freq=370Hz, sample=66, buffer_id=01:42
; t 121.9352 Sustain 127 (Instr 1)
; t 121.9352 Sustain 127 (Instr 2)
    db 97,1,216,9,68,38,2,1,159,1,68,1  ; n441 t=122.197s dur=2520ms, freq=415Hz, sample=68, buffer_id=01:44
    db 98,1,119,8,63,33,1,10,55,1,63,1  ; n442 t=122.550s dur=2167ms, freq=311Hz, sample=63, buffer_id=01:3F
    db 77,1,20,7,66,33,1,0,114,1,66,1  ; n443 t=122.904s dur=1812ms, freq=370Hz, sample=66, buffer_id=01:42
    db 124,1,200,5,68,38,2,1,159,1,68,1  ; n444 t=123.237s dur=1480ms, freq=415Hz, sample=68, buffer_id=01:44
    db 44,1,76,4,63,33,1,10,55,1,63,1  ; n445 t=123.617s dur=1100ms, freq=311Hz, sample=63, buffer_id=01:3F
    db 118,1,43,3,66,33,1,0,114,1,66,1  ; n446 t=123.917s dur=811ms, freq=370Hz, sample=66, buffer_id=01:42
    db 239,0,175,1,68,38,2,1,159,1,68,1  ; n447 t=124.291s dur=431ms, freq=415Hz, sample=68, buffer_id=01:44
    db 7,0,130,5,36,36,1,6,65,0,36,1  ; n448 t=124.530s dur=1410ms, freq=65Hz, sample=36, buffer_id=01:24
    db 37,0,124,5,44,36,1,7,104,0,44,1  ; n449 t=124.537s dur=1404ms, freq=104Hz, sample=44, buffer_id=01:2C
    db 90,0,87,5,48,35,1,8,131,0,48,1  ; n450 t=124.573s dur=1367ms, freq=131Hz, sample=48, buffer_id=01:30
    db 35,0,253,4,63,34,1,10,55,1,63,1  ; n451 t=124.663s dur=1277ms, freq=311Hz, sample=63, buffer_id=01:3F
    db 143,1,219,4,75,51,2,9,110,2,75,1  ; n452 t=124.698s dur=1243ms, freq=622Hz, sample=75, buffer_id=01:4B
; t 124.7173 Sustain 0 (Instr 1)
; t 124.7173 Sustain 0 (Instr 2)
; t 124.9751 Sustain 127 (Instr 1)
; t 124.9751 Sustain 127 (Instr 2)
    db 69,1,76,3,66,33,1,0,114,1,66,1  ; n453 t=125.096s dur=844ms, freq=370Hz, sample=66, buffer_id=01:42
; t 125.2469 Soft 127 (Instr 1)
; t 125.2469 Soft 127 (Instr 2)
    db 42,1,7,2,68,38,2,1,159,1,68,1  ; n454 t=125.421s dur=519ms, freq=415Hz, sample=68, buffer_id=01:44
    db 44,0,191,9,37,36,1,2,69,0,37,1  ; n455 t=125.719s dur=2495ms, freq=69Hz, sample=37, buffer_id=01:25
    db 115,0,146,9,49,36,1,3,139,0,49,1  ; n456 t=125.763s dur=2450ms, freq=139Hz, sample=49, buffer_id=01:31
    db 42,0,32,9,64,35,1,4,74,1,64,1  ; n457 t=125.878s dur=2336ms, freq=330Hz, sample=64, buffer_id=01:40
    db 108,1,245,8,76,48,2,5,147,2,76,1  ; n458 t=125.920s dur=2293ms, freq=659Hz, sample=76, buffer_id=01:4C
; t 125.9409 Sustain 0 (Instr 1)
; t 125.9409 Sustain 0 (Instr 2)
    db 164,1,138,7,68,38,2,0,159,1,68,1  ; n459 t=126.284s dur=1930ms, freq=415Hz, sample=68, buffer_id=01:44
; t 126.3783 Sustain 127 (Instr 1)
; t 126.3783 Sustain 127 (Instr 2)
    db 102,1,230,5,73,38,2,1,42,2,73,1  ; n460 t=126.704s dur=1510ms, freq=554Hz, sample=73, buffer_id=01:49
    db 132,1,127,4,64,33,1,4,74,1,64,1  ; n461 t=127.062s dur=1151ms, freq=330Hz, sample=64, buffer_id=01:40
    db 130,1,252,2,68,38,2,0,159,1,68,1  ; n462 t=127.450s dur=764ms, freq=415Hz, sample=68, buffer_id=01:44
    db 246,0,199,1,73,38,2,1,42,2,73,1  ; n463 t=127.837s dur=455ms, freq=554Hz, sample=73, buffer_id=01:49
    db 50,0,73,5,30,36,1,6,46,0,30,1  ; n464 t=128.082s dur=1353ms, freq=46Hz, sample=30, buffer_id=01:1E
    db 108,0,23,5,42,36,1,7,92,0,42,1  ; n465 t=128.132s dur=1303ms, freq=92Hz, sample=42, buffer_id=01:2A
; t 128.2143 Sustain 0 (Instr 1)
; t 128.2143 Sustain 0 (Instr 2)
    db 23,0,171,4,63,34,1,8,55,1,63,1  ; n466 t=128.240s dur=1195ms, freq=311Hz, sample=63, buffer_id=01:3F
    db 139,1,148,4,75,52,2,9,110,2,75,1  ; n467 t=128.263s dur=1172ms, freq=622Hz, sample=75, buffer_id=01:4B
; t 128.5499 Sustain 127 (Instr 1)
; t 128.5499 Sustain 127 (Instr 2)
    db 124,1,9,3,66,33,1,0,114,1,66,1  ; n468 t=128.658s dur=777ms, freq=370Hz, sample=66, buffer_id=01:42
    db 3,1,213,1,69,38,2,1,184,1,69,1  ; n469 t=129.038s dur=469ms, freq=440Hz, sample=69, buffer_id=01:45
    db 38,0,157,5,31,36,1,2,49,0,31,1  ; n470 t=129.297s dur=1437ms, freq=49Hz, sample=31, buffer_id=01:1F
    db 112,0,119,5,43,35,1,3,98,0,43,1  ; n471 t=129.335s dur=1399ms, freq=98Hz, sample=43, buffer_id=01:2B
; t 129.4354 Sustain 0 (Instr 1)
; t 129.4354 Sustain 0 (Instr 2)
    db 3,0,7,5,73,43,2,4,42,2,73,1  ; n472 t=129.446s dur=1287ms, freq=554Hz, sample=73, buffer_id=01:49
    db 213,1,4,5,61,34,1,5,21,1,61,1  ; n473 t=129.450s dur=1284ms, freq=277Hz, sample=61, buffer_id=01:3D
; t 129.7579 Sustain 127 (Instr 1)
; t 129.7579 Sustain 127 (Instr 2)
    db 177,1,52,3,64,33,1,0,74,1,64,1  ; n474 t=129.918s dur=820ms, freq=330Hz, sample=64, buffer_id=01:40
    db 35,1,212,1,70,38,2,1,210,1,70,1  ; n475 t=130.351s dur=468ms, freq=466Hz, sample=70, buffer_id=01:46
    db 25,0,99,16,32,39,1,6,52,0,32,1  ; n476 t=130.642s dur=4195ms, freq=52Hz, sample=32, buffer_id=01:20
    db 91,0,74,16,44,39,1,7,104,0,44,1  ; n477 t=130.667s dur=4170ms, freq=104Hz, sample=44, buffer_id=01:2C
; t 130.7339 Sustain 0 (Instr 1)
; t 130.7339 Sustain 0 (Instr 2)
    db 85,1,72,4,72,47,2,8,11,2,72,1  ; n478 t=130.758s dur=1096ms, freq=523Hz, sample=72, buffer_id=01:48
; t 131.0337 Sustain 127 (Instr 1)
; t 131.0337 Sustain 127 (Instr 2)
    db 75,1,243,2,60,33,1,0,6,1,60,1  ; n479 t=131.099s dur=755ms, freq=262Hz, sample=60, buffer_id=01:3C
    db 89,1,187,1,63,33,1,1,55,1,63,1  ; n480 t=131.430s dur=443ms, freq=311Hz, sample=63, buffer_id=01:3F
    db 111,1,45,4,68,43,2,2,159,1,68,1  ; n481 t=131.775s dur=1069ms, freq=415Hz, sample=68, buffer_id=01:44
; t 131.8539 Sustain 0 (Instr 1)
; t 131.8539 Sustain 0 (Instr 2)
; t 132.0844 Sustain 127 (Instr 1)
; t 132.0844 Sustain 127 (Instr 2)
    db 89,1,189,2,60,36,1,0,6,1,60,1  ; n482 t=132.142s dur=701ms, freq=262Hz, sample=60, buffer_id=01:3C
    db 47,1,115,1,63,33,1,1,55,1,63,1  ; n483 t=132.487s dur=371ms, freq=311Hz, sample=63, buffer_id=01:3F
    db 122,1,126,4,69,48,2,3,184,1,69,1  ; n484 t=132.790s dur=1150ms, freq=440Hz, sample=69, buffer_id=01:45
; t 132.8430 Sustain 0 (Instr 1)
; t 132.8430 Sustain 0 (Instr 2)
    db 126,1,4,3,60,33,1,0,6,1,60,1  ; n485 t=133.168s dur=772ms, freq=262Hz, sample=60, buffer_id=01:3C
; t 133.2434 Sustain 127 (Instr 1)
; t 133.2434 Sustain 127 (Instr 2)
    db 44,1,192,1,63,34,1,1,55,1,63,1  ; n486 t=133.549s dur=448ms, freq=311Hz, sample=63, buffer_id=01:3F
    db 47,1,220,3,66,44,1,2,114,1,66,1  ; n487 t=133.849s dur=988ms, freq=370Hz, sample=66, buffer_id=01:42
; t 133.9400 Sustain 0 (Instr 1)
; t 133.9400 Sustain 0 (Instr 2)
    db 67,1,173,2,60,33,1,0,6,1,60,1  ; n488 t=134.152s dur=685ms, freq=262Hz, sample=60, buffer_id=01:3C
; t 134.2029 Sustain 127 (Instr 1)
; t 134.2029 Sustain 127 (Instr 2)
    db 24,1,106,1,63,33,1,1,55,1,63,1  ; n489 t=134.475s dur=362ms, freq=311Hz, sample=63, buffer_id=01:3F
    db 2,0,174,15,44,37,1,7,104,0,44,1  ; n490 t=134.756s dur=4014ms, freq=104Hz, sample=44, buffer_id=01:2C
    db 53,1,172,15,32,37,1,6,52,0,32,1  ; n491 t=134.758s dur=4012ms, freq=52Hz, sample=32, buffer_id=01:20
; t 134.8378 Sustain 0 (Instr 1)
; t 134.8378 Sustain 0 (Instr 2)
; t 135.0455 Sustain 127 (Instr 1)
; t 135.0455 Sustain 127 (Instr 2)
    db 67,1,192,2,60,33,1,0,6,1,60,1  ; n492 t=135.067s dur=704ms, freq=262Hz, sample=60, buffer_id=01:3C
    db 58,1,60,5,63,34,1,1,55,1,63,1  ; n493 t=135.391s dur=1340ms, freq=311Hz, sample=63, buffer_id=01:3F
    db 121,1,2,4,56,44,1,2,208,0,56,1  ; n494 t=135.704s dur=1026ms, freq=208Hz, sample=56, buffer_id=01:38
; t 135.7172 Sustain 0 (Instr 1)
; t 135.7172 Sustain 0 (Instr 2)
; t 135.9271 Sustain 127 (Instr 1)
; t 135.9271 Sustain 127 (Instr 2)
    db 44,1,138,2,60,33,1,0,6,1,60,1  ; n495 t=136.081s dur=650ms, freq=262Hz, sample=60, buffer_id=01:3C
    db 44,1,4,2,63,33,1,1,55,1,63,1  ; n496 t=136.380s dur=516ms, freq=311Hz, sample=63, buffer_id=01:3F
    db 93,1,32,4,57,48,1,3,220,0,57,1  ; n497 t=136.680s dur=1056ms, freq=220Hz, sample=57, buffer_id=01:39
; t 136.7308 Sustain 0 (Instr 1)
; t 136.7308 Sustain 0 (Instr 2)
; t 136.9460 Sustain 127 (Instr 1)
; t 136.9460 Sustain 127 (Instr 2)
    db 69,1,195,2,60,33,1,0,6,1,60,1  ; n498 t=137.029s dur=707ms, freq=262Hz, sample=60, buffer_id=01:3C
    db 73,1,152,1,63,33,1,1,55,1,63,1  ; n499 t=137.354s dur=408ms, freq=311Hz, sample=63, buffer_id=01:3F
    db 146,1,63,4,54,40,1,2,185,0,54,1  ; n500 t=137.683s dur=1087ms, freq=185Hz, sample=54, buffer_id=01:36
; t 137.7365 Sustain 0 (Instr 1)
; t 137.7365 Sustain 0 (Instr 2)
; t 137.9852 Sustain 127 (Instr 1)
; t 137.9852 Sustain 127 (Instr 2)
    db 115,1,173,2,60,33,1,0,6,1,60,1  ; n501 t=138.085s dur=685ms, freq=262Hz, sample=60, buffer_id=01:3C
    db 215,0,58,1,63,33,1,1,55,1,63,1  ; n502 t=138.456s dur=314ms, freq=311Hz, sample=63, buffer_id=01:3F
    db 19,0,234,14,32,35,1,6,52,0,32,1  ; n503 t=138.671s dur=3818ms, freq=52Hz, sample=32, buffer_id=01:20
    db 102,0,214,14,44,36,1,7,104,0,44,1  ; n504 t=138.690s dur=3798ms, freq=104Hz, sample=44, buffer_id=01:2C
; t 138.7702 Sustain 0 (Instr 1)
; t 138.7702 Sustain 0 (Instr 2)
    db 36,1,13,11,52,37,1,3,165,0,52,1  ; n505 t=138.792s dur=2829ms, freq=165Hz, sample=52, buffer_id=01:34
; t 138.9713 Sustain 127 (Instr 1)
; t 138.9713 Sustain 127 (Instr 2)
    db 30,1,233,9,64,33,1,0,74,1,64,1  ; n506 t=139.084s dur=2537ms, freq=330Hz, sample=64, buffer_id=01:40
    db 77,1,202,8,68,38,2,1,159,1,68,1  ; n507 t=139.370s dur=2250ms, freq=415Hz, sample=68, buffer_id=01:44
    db 63,1,125,7,73,50,2,2,42,2,73,1  ; n508 t=139.703s dur=1917ms, freq=554Hz, sample=73, buffer_id=01:49
    db 5,1,62,6,64,33,1,0,74,1,64,1  ; n509 t=140.022s dur=1598ms, freq=330Hz, sample=64, buffer_id=01:40
    db 94,1,58,5,68,38,2,1,159,1,68,1  ; n510 t=140.283s dur=1338ms, freq=415Hz, sample=68, buffer_id=01:44
    db 13,1,219,3,76,49,2,4,147,2,76,1  ; n511 t=140.633s dur=987ms, freq=659Hz, sample=76, buffer_id=01:4C
    db 53,1,216,2,64,33,1,0,74,1,64,1  ; n512 t=140.902s dur=728ms, freq=330Hz, sample=64, buffer_id=01:40
    db 107,1,213,1,68,38,2,1,159,1,68,1  ; n513 t=141.212s dur=469ms, freq=415Hz, sample=68, buffer_id=01:44
    db 34,1,146,3,73,51,2,2,42,2,73,1  ; n514 t=141.575s dur=914ms, freq=554Hz, sample=73, buffer_id=01:49
; t 141.6212 Sustain 0 (Instr 1)
; t 141.6212 Sustain 0 (Instr 2)
; t 141.8201 Sustain 127 (Instr 1)
; t 141.8201 Sustain 127 (Instr 2)
    db 15,1,112,2,64,33,1,0,74,1,64,1  ; n515 t=141.864s dur=624ms, freq=330Hz, sample=64, buffer_id=01:40
    db 255,0,97,1,68,38,2,1,159,1,68,1  ; n516 t=142.136s dur=353ms, freq=415Hz, sample=68, buffer_id=01:44
    db 18,0,26,14,32,36,1,6,52,0,32,1  ; n517 t=142.391s dur=3610ms, freq=52Hz, sample=32, buffer_id=01:20
    db 25,1,8,14,44,36,1,7,104,0,44,1  ; n518 t=142.409s dur=3592ms, freq=104Hz, sample=44, buffer_id=01:2C
; t 142.4891 Sustain 0 (Instr 1)
; t 142.4891 Sustain 0 (Instr 2)
    db 242,0,235,5,52,33,1,0,165,0,52,1  ; n519 t=142.690s dur=1515ms, freq=165Hz, sample=52, buffer_id=01:34
; t 142.7107 Sustain 127 (Instr 1)
; t 142.7107 Sustain 127 (Instr 2)
    db 89,1,249,4,56,34,1,1,208,0,56,1  ; n520 t=142.932s dur=1273ms, freq=208Hz, sample=56, buffer_id=01:38
    db 51,1,160,3,61,45,1,2,21,1,61,1  ; n521 t=143.277s dur=928ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 243,0,109,2,52,33,1,0,165,0,52,1  ; n522 t=143.584s dur=621ms, freq=165Hz, sample=52, buffer_id=01:34
    db 62,1,122,1,56,33,1,1,208,0,56,1  ; n523 t=143.827s dur=378ms, freq=208Hz, sample=56, buffer_id=01:38
    db 89,1,56,4,64,40,1,3,74,1,64,1  ; n524 t=144.145s dur=1080ms, freq=330Hz, sample=64, buffer_id=01:40
; t 144.2055 Sustain 0 (Instr 1)
; t 144.2055 Sustain 0 (Instr 2)
; t 144.4346 Sustain 127 (Instr 1)
; t 144.4346 Sustain 127 (Instr 2)
    db 8,1,223,2,52,33,1,0,165,0,52,1  ; n525 t=144.490s dur=735ms, freq=165Hz, sample=52, buffer_id=01:34
    db 102,1,216,1,56,33,1,1,208,0,56,1  ; n526 t=144.754s dur=472ms, freq=208Hz, sample=56, buffer_id=01:38
    db 75,1,122,3,61,40,1,2,21,1,61,1  ; n527 t=145.111s dur=890ms, freq=277Hz, sample=61, buffer_id=01:3D
; t 145.2257 Sustain 0 (Instr 1)
; t 145.2257 Sustain 0 (Instr 2)
; t 145.3985 Sustain 127 (Instr 1)
; t 145.3985 Sustain 127 (Instr 2)
    db 25,1,47,2,52,33,1,0,165,0,52,1  ; n528 t=145.442s dur=559ms, freq=165Hz, sample=52, buffer_id=01:34
    db 166,0,22,1,56,33,1,1,208,0,56,1  ; n529 t=145.723s dur=278ms, freq=208Hz, sample=56, buffer_id=01:38
    db 37,0,171,13,32,36,1,6,52,0,32,1  ; n530 t=145.889s dur=3499ms, freq=52Hz, sample=32, buffer_id=01:20
    db 107,0,134,13,44,36,1,7,104,0,44,1  ; n531 t=145.926s dur=3462ms, freq=104Hz, sample=44, buffer_id=01:2C
; t 146.0014 Sustain 0 (Instr 1)
; t 146.0014 Sustain 0 (Instr 2)
    db 255,0,27,13,51,47,1,3,156,0,51,1  ; n532 t=146.033s dur=3355ms, freq=156Hz, sample=51, buffer_id=01:33
; t 146.2250 Sustain 127 (Instr 1)
; t 146.2250 Sustain 127 (Instr 2)
; t 146.2769 Soft 0 (Instr 1)
; t 146.2769 Soft 0 (Instr 2)
    db 42,1,28,12,57,36,1,0,220,0,57,1  ; n533 t=146.288s dur=3100ms, freq=220Hz, sample=57, buffer_id=01:39
    db 44,1,242,10,54,38,1,1,185,0,54,1  ; n534 t=146.586s dur=2802ms, freq=185Hz, sample=54, buffer_id=01:36
    db 29,1,198,9,60,34,1,2,6,1,60,1  ; n535 t=146.886s dur=2502ms, freq=262Hz, sample=60, buffer_id=01:3C
    db 19,1,168,8,57,38,1,0,220,0,57,1  ; n536 t=147.172s dur=2216ms, freq=220Hz, sample=57, buffer_id=01:39
    db 249,0,149,7,63,42,1,4,55,1,63,1  ; n537 t=147.447s dur=1941ms, freq=311Hz, sample=63, buffer_id=01:3F
    db 75,1,155,6,60,45,1,2,6,1,60,1  ; n538 t=147.696s dur=1691ms, freq=262Hz, sample=60, buffer_id=01:3C
    db 242,0,81,5,66,45,1,5,114,1,66,1  ; n539 t=148.027s dur=1361ms, freq=370Hz, sample=66, buffer_id=01:42
    db 15,1,95,4,63,49,1,4,55,1,63,1  ; n540 t=148.269s dur=1119ms, freq=311Hz, sample=63, buffer_id=01:3F
    db 10,1,79,3,69,51,2,8,184,1,69,1  ; n541 t=148.540s dur=847ms, freq=440Hz, sample=69, buffer_id=01:45
    db 5,1,70,2,66,44,1,5,114,1,66,1  ; n542 t=148.806s dur=582ms, freq=370Hz, sample=66, buffer_id=01:42
    db 150,0,64,1,72,49,2,9,11,2,72,1  ; n543 t=149.067s dur=320ms, freq=523Hz, sample=72, buffer_id=01:48
    db 38,0,108,12,32,44,1,6,52,0,32,1  ; n544 t=149.218s dur=3180ms, freq=52Hz, sample=32, buffer_id=01:20
    db 107,0,70,12,44,45,1,7,104,0,44,1  ; n545 t=149.255s dur=3142ms, freq=104Hz, sample=44, buffer_id=01:2C
    db 250,0,219,11,52,55,1,10,165,0,52,1  ; n546 t=149.362s dur=3035ms, freq=165Hz, sample=52, buffer_id=01:34
; t 149.3882 Sustain 0 (Instr 1)
; t 149.3882 Sustain 0 (Instr 2)
; t 149.6042 Sustain 127 (Instr 1)
; t 149.6042 Sustain 127 (Instr 2)
    db 237,0,225,10,61,39,1,0,21,1,61,1  ; n547 t=149.613s dur=2785ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 2,1,244,9,56,43,1,1,208,0,56,1  ; n548 t=149.849s dur=2548ms, freq=208Hz, sample=56, buffer_id=01:38
    db 17,1,242,8,64,46,1,2,74,1,64,1  ; n549 t=150.107s dur=2290ms, freq=330Hz, sample=64, buffer_id=01:40
    db 232,0,225,7,61,42,1,0,21,1,61,1  ; n550 t=150.381s dur=2017ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 254,0,249,6,68,47,2,3,159,1,68,1  ; n551 t=150.613s dur=1785ms, freq=415Hz, sample=68, buffer_id=01:44
    db 254,0,251,5,64,36,1,2,74,1,64,1  ; n552 t=150.867s dur=1531ms, freq=330Hz, sample=64, buffer_id=01:40
    db 252,0,253,4,73,49,2,4,42,2,73,1  ; n553 t=151.120s dur=1277ms, freq=554Hz, sample=73, buffer_id=01:49
    db 252,0,1,4,68,53,2,3,159,1,68,1  ; n554 t=151.372s dur=1025ms, freq=415Hz, sample=68, buffer_id=01:44
    db 249,0,6,3,76,56,2,5,147,2,76,1  ; n555 t=151.624s dur=774ms, freq=659Hz, sample=76, buffer_id=01:4C
    db 225,0,12,2,73,53,2,4,42,2,73,1  ; n556 t=151.873s dur=524ms, freq=554Hz, sample=73, buffer_id=01:49
    db 161,0,44,1,68,53,2,3,159,1,68,1  ; n557 t=152.098s dur=300ms, freq=415Hz, sample=68, buffer_id=01:44
; t 152.2220 Soft 0 (Instr 1)
; t 152.2220 Soft 0 (Instr 2)
    db 25,0,237,10,32,38,1,6,52,0,32,1  ; n558 t=152.259s dur=2797ms, freq=52Hz, sample=32, buffer_id=01:20
    db 88,0,212,10,44,38,1,7,104,0,44,1  ; n559 t=152.284s dur=2772ms, freq=104Hz, sample=44, buffer_id=01:2C
    db 221,0,123,10,61,39,1,0,21,1,61,1  ; n560 t=152.372s dur=2683ms, freq=277Hz, sample=61, buffer_id=01:3D
; t 152.3980 Sustain 0 (Instr 1)
; t 152.3980 Sustain 0 (Instr 2)
; t 152.5924 Sustain 127 (Instr 1)
; t 152.5924 Sustain 127 (Instr 2)
    db 229,0,158,9,67,59,2,8,136,1,67,1  ; n561 t=152.594s dur=2462ms, freq=392Hz, sample=67, buffer_id=01:43
    db 232,0,185,8,64,43,1,1,74,1,64,1  ; n562 t=152.822s dur=2233ms, freq=330Hz, sample=64, buffer_id=01:40
    db 213,0,209,7,70,55,2,2,210,1,70,1  ; n563 t=153.054s dur=2001ms, freq=466Hz, sample=70, buffer_id=01:46
    db 204,0,252,6,67,58,2,8,136,1,67,1  ; n564 t=153.267s dur=1788ms, freq=392Hz, sample=67, buffer_id=01:43
    db 239,0,48,6,73,61,2,3,42,2,73,1  ; n565 t=153.471s dur=1584ms, freq=554Hz, sample=73, buffer_id=01:49
    db 233,0,66,5,70,64,2,2,210,1,70,1  ; n566 t=153.710s dur=1346ms, freq=466Hz, sample=70, buffer_id=01:46
    db 239,0,88,4,76,61,2,4,147,2,76,1  ; n567 t=153.943s dur=1112ms, freq=659Hz, sample=76, buffer_id=01:4C
    db 194,0,106,3,73,61,2,3,42,2,73,1  ; n568 t=154.182s dur=874ms, freq=554Hz, sample=73, buffer_id=01:49
    db 204,0,168,2,79,64,2,5,16,3,79,1  ; n569 t=154.376s dur=680ms, freq=784Hz, sample=79, buffer_id=01:4F
    db 188,0,220,1,76,67,2,4,147,2,76,1  ; n570 t=154.580s dur=476ms, freq=659Hz, sample=76, buffer_id=01:4C
    db 134,0,32,1,82,69,2,9,164,3,82,1  ; n571 t=154.768s dur=288ms, freq=932Hz, sample=82, buffer_id=01:52
    db 11,0,73,31,32,55,1,6,52,0,32,1  ; n572 t=154.902s dur=8009ms, freq=52Hz, sample=32, buffer_id=01:20
    db 113,0,63,31,44,55,1,7,104,0,44,1  ; n573 t=154.912s dur=7999ms, freq=104Hz, sample=44, buffer_id=01:2C
    db 208,0,228,23,66,54,1,10,114,1,66,1  ; n574 t=155.026s dur=6116ms, freq=370Hz, sample=66, buffer_id=01:42
; t 155.0560 Sustain 0 (Instr 1)
; t 155.0560 Sustain 0 (Instr 2)
    db 186,0,20,23,72,70,2,11,11,2,72,1  ; n575 t=155.234s dur=5908ms, freq=523Hz, sample=72, buffer_id=01:48
; t 155.2805 Sustain 127 (Instr 1)
; t 155.2805 Sustain 127 (Instr 2)
    db 210,0,90,22,69,70,2,0,184,1,69,1  ; n576 t=155.420s dur=5722ms, freq=440Hz, sample=69, buffer_id=01:45
    db 215,0,136,21,75,70,2,1,110,2,75,1  ; n577 t=155.630s dur=5512ms, freq=622Hz, sample=75, buffer_id=01:4B
    db 160,0,177,20,72,70,2,11,11,2,72,1  ; n578 t=155.845s dur=5297ms, freq=523Hz, sample=72, buffer_id=01:48
    db 235,0,17,20,78,70,2,2,228,2,78,1  ; n579 t=156.005s dur=5137ms, freq=740Hz, sample=78, buffer_id=01:4E
    db 184,0,38,19,75,70,2,1,110,2,75,1  ; n580 t=156.240s dur=4902ms, freq=622Hz, sample=75, buffer_id=01:4B
    db 184,0,110,18,81,70,2,3,112,3,81,1  ; n581 t=156.424s dur=4718ms, freq=880Hz, sample=81, buffer_id=01:51
    db 200,0,183,17,78,70,2,2,228,2,78,1  ; n582 t=156.607s dur=4535ms, freq=740Hz, sample=78, buffer_id=01:4E
    db 191,0,112,13,82,70,2,4,23,4,82,1  ; n583 t=156.807s dur=3440ms, freq=1047Hz, sample=82, buffer_id=01:52
    db 178,0,48,16,81,70,2,3,112,3,81,1  ; n584 t=156.998s dur=4144ms, freq=880Hz, sample=81, buffer_id=01:51
    db 192,0,77,11,82,70,2,4,221,4,82,1  ; n585 t=157.176s dur=2893ms, freq=1245Hz, sample=82, buffer_id=01:52
    db 207,0,112,13,82,67,2,4,23,4,82,1  ; n586 t=157.368s dur=3440ms, freq=1047Hz, sample=82, buffer_id=01:52
    db 162,0,239,13,78,64,2,2,228,2,78,1  ; n587 t=157.575s dur=3567ms, freq=740Hz, sample=78, buffer_id=01:4E
    db 226,0,77,13,81,62,2,3,112,3,81,1  ; n588 t=157.737s dur=3405ms, freq=880Hz, sample=81, buffer_id=01:51
    db 189,0,107,12,75,59,2,1,110,2,75,1  ; n589 t=157.963s dur=3179ms, freq=622Hz, sample=75, buffer_id=01:4B
    db 212,0,175,11,78,57,2,2,228,2,78,1  ; n590 t=158.151s dur=2991ms, freq=740Hz, sample=78, buffer_id=01:4E
    db 191,0,219,10,72,54,2,11,11,2,72,1  ; n591 t=158.363s dur=2779ms, freq=523Hz, sample=72, buffer_id=01:48
    db 190,0,28,10,75,51,2,1,110,2,75,1  ; n592 t=158.554s dur=2588ms, freq=622Hz, sample=75, buffer_id=01:4B
    db 190,0,94,9,69,49,2,0,184,1,69,1  ; n593 t=158.744s dur=2398ms, freq=440Hz, sample=69, buffer_id=01:45
    db 204,0,160,8,72,46,2,11,11,2,72,1  ; n594 t=158.934s dur=2208ms, freq=523Hz, sample=72, buffer_id=01:48
    db 200,0,212,7,66,38,1,10,114,1,66,1  ; n595 t=159.138s dur=2004ms, freq=370Hz, sample=66, buffer_id=01:42
    db 213,0,13,7,69,41,2,0,184,1,69,1  ; n596 t=159.337s dur=1805ms, freq=440Hz, sample=69, buffer_id=01:45
    db 209,0,56,6,63,33,1,5,55,1,63,1  ; n597 t=159.550s dur=1592ms, freq=311Hz, sample=63, buffer_id=01:3F
    db 210,0,103,5,66,33,1,10,114,1,66,1  ; n598 t=159.759s dur=1383ms, freq=370Hz, sample=66, buffer_id=01:42
    db 228,0,148,4,60,33,1,8,6,1,60,1  ; n599 t=159.970s dur=1172ms, freq=262Hz, sample=60, buffer_id=01:3C
    db 221,0,177,3,63,33,1,5,55,1,63,1  ; n600 t=160.197s dur=945ms, freq=311Hz, sample=63, buffer_id=01:3F
    db 185,0,211,2,57,33,1,9,220,0,57,1  ; n601 t=160.419s dur=723ms, freq=220Hz, sample=57, buffer_id=01:39
    db 202,0,27,2,60,33,1,8,6,1,60,1  ; n602 t=160.603s dur=539ms, freq=262Hz, sample=60, buffer_id=01:3C
    db 209,0,81,1,54,33,1,12,185,0,54,1  ; n603 t=160.805s dur=337ms, freq=185Hz, sample=54, buffer_id=01:36
    db 11,1,38,4,57,33,1,9,220,0,57,1  ; n604 t=161.014s dur=1062ms, freq=220Hz, sample=57, buffer_id=01:39
; t 161.1424 Sustain 0 (Instr 1)
; t 161.1424 Sustain 0 (Instr 2)
    db 56,1,27,3,51,38,1,4,156,0,51,1  ; n605 t=161.282s dur=795ms, freq=156Hz, sample=51, buffer_id=01:33
; t 161.3830 Sustain 127 (Instr 1)
; t 161.3830 Sustain 127 (Instr 2)
    db 109,1,227,1,54,33,1,0,185,0,54,1  ; n606 t=161.593s dur=483ms, freq=185Hz, sample=54, buffer_id=01:36
    db 98,0,185,3,57,34,1,9,220,0,57,1  ; n607 t=161.958s dur=953ms, freq=220Hz, sample=57, buffer_id=01:39
    db 32,1,87,3,49,41,1,1,139,0,49,1  ; n608 t=162.056s dur=855ms, freq=139Hz, sample=49, buffer_id=01:31
; t 162.0766 Sustain 0 (Instr 1)
; t 162.0766 Sustain 0 (Instr 2)
; t 162.3009 Sustain 127 (Instr 1)
; t 162.3009 Sustain 127 (Instr 2)
    db 247,0,55,2,54,33,1,0,185,0,54,1  ; n609 t=162.344s dur=567ms, freq=185Hz, sample=54, buffer_id=01:36
    db 150,0,146,2,57,33,1,9,220,0,57,1  ; n610 t=162.591s dur=658ms, freq=220Hz, sample=57, buffer_id=01:39
    db 41,0,133,14,32,35,1,6,52,0,32,1  ; n611 t=162.741s dur=3717ms, freq=52Hz, sample=32, buffer_id=01:20
    db 115,0,92,14,44,35,1,7,104,0,44,1  ; n612 t=162.782s dur=3676ms, freq=104Hz, sample=44, buffer_id=01:2C
    db 30,1,57,6,48,40,1,2,131,0,48,1  ; n613 t=162.897s dur=1593ms, freq=131Hz, sample=48, buffer_id=01:30
; t 162.9115 Sustain 0 (Instr 1)
; t 162.9115 Sustain 0 (Instr 2)
    db 231,0,27,5,54,34,1,0,185,0,54,1  ; n614 t=163.183s dur=1307ms, freq=185Hz, sample=54, buffer_id=01:36
; t 163.2501 Sustain 127 (Instr 1)
; t 163.2501 Sustain 127 (Instr 2)
    db 236,0,52,4,56,34,1,1,208,0,56,1  ; n615 t=163.414s dur=1076ms, freq=208Hz, sample=56, buffer_id=01:38
    db 9,1,72,3,57,34,1,3,220,0,57,1  ; n616 t=163.650s dur=840ms, freq=220Hz, sample=57, buffer_id=01:39
    db 225,0,62,2,56,33,1,1,208,0,56,1  ; n617 t=163.916s dur=574ms, freq=208Hz, sample=56, buffer_id=01:38
    db 137,1,209,1,54,33,1,0,185,0,54,1  ; n618 t=164.141s dur=465ms, freq=185Hz, sample=54, buffer_id=01:36
; t 164.4906 Sustain 0 (Instr 1)
; t 164.4906 Sustain 0 (Instr 2)
    db 126,1,193,3,51,40,1,4,156,0,51,1  ; n619 t=164.534s dur=961ms, freq=156Hz, sample=51, buffer_id=01:33
; t 164.8464 Sustain 127 (Instr 1)
; t 164.8464 Sustain 127 (Instr 2)
    db 15,1,68,2,54,33,1,0,185,0,54,1  ; n620 t=164.915s dur=580ms, freq=185Hz, sample=54, buffer_id=01:36
    db 31,1,103,1,57,33,1,1,220,0,57,1  ; n621 t=165.186s dur=359ms, freq=220Hz, sample=57, buffer_id=01:39
    db 88,1,217,3,49,40,1,2,139,0,49,1  ; n622 t=165.473s dur=985ms, freq=139Hz, sample=49, buffer_id=01:31
; t 165.4955 Sustain 0 (Instr 1)
; t 165.4955 Sustain 0 (Instr 2)
; t 165.8114 Sustain 127 (Instr 1)
; t 165.8114 Sustain 127 (Instr 2)
    db 252,0,129,2,54,33,1,0,185,0,54,1  ; n623 t=165.817s dur=641ms, freq=185Hz, sample=54, buffer_id=01:36
    db 196,0,171,1,57,33,1,1,220,0,57,1  ; n624 t=166.069s dur=427ms, freq=220Hz, sample=57, buffer_id=01:39
    db 52,0,227,15,32,35,1,6,52,0,32,1  ; n625 t=166.265s dur=4067ms, freq=52Hz, sample=32, buffer_id=01:20
    db 127,0,175,15,44,34,1,7,104,0,44,1  ; n626 t=166.317s dur=4015ms, freq=104Hz, sample=44, buffer_id=01:2C
    db 126,1,5,7,48,36,1,3,131,0,48,1  ; n627 t=166.444s dur=1797ms, freq=131Hz, sample=48, buffer_id=01:30
; t 166.4584 Sustain 0 (Instr 1)
; t 166.4584 Sustain 0 (Instr 2)
    db 242,0,65,1,54,34,1,0,185,0,54,1  ; n628 t=166.826s dur=321ms, freq=185Hz, sample=54, buffer_id=01:36
    db 35,1,96,1,56,37,1,1,208,0,56,1  ; n629 t=167.068s dur=352ms, freq=208Hz, sample=56, buffer_id=01:38
    db 19,1,127,1,57,39,1,0,220,0,57,1  ; n630 t=167.359s dur=383ms, freq=220Hz, sample=57, buffer_id=01:39
    db 253,0,96,2,56,35,1,1,208,0,56,1  ; n631 t=167.634s dur=608ms, freq=208Hz, sample=56, buffer_id=01:38
; t 167.7544 Soft 127 (Instr 1)
; t 167.7544 Soft 127 (Instr 2)
; t 167.8698 Sustain 127 (Instr 1)
; t 167.8698 Sustain 127 (Instr 2)
    db 199,1,23,2,54,33,1,2,185,0,54,1  ; n632 t=167.887s dur=535ms, freq=185Hz, sample=54, buffer_id=01:36
; t 168.2417 Sustain 0 (Instr 1)
; t 168.2417 Sustain 0 (Instr 2)
    db 171,1,28,4,50,48,1,0,147,0,50,1  ; n633 t=168.342s dur=1052ms, freq=147Hz, sample=50, buffer_id=01:32
; t 168.7160 Sustain 127 (Instr 1)
; t 168.7160 Sustain 127 (Instr 2)
    db 250,0,114,2,54,34,1,1,185,0,54,1  ; n634 t=168.769s dur=626ms, freq=185Hz, sample=54, buffer_id=01:36
    db 41,1,120,1,57,33,1,2,220,0,57,1  ; n635 t=169.019s dur=376ms, freq=220Hz, sample=57, buffer_id=01:39
    db 124,1,248,3,49,37,1,3,139,0,49,1  ; n636 t=169.316s dur=1016ms, freq=139Hz, sample=49, buffer_id=01:31
; t 169.3950 Sustain 0 (Instr 1)
; t 169.3950 Sustain 0 (Instr 2)
    db 61,1,123,2,54,33,1,0,185,0,54,1  ; n637 t=169.697s dur=635ms, freq=185Hz, sample=54, buffer_id=01:36
; t 169.7291 Sustain 127 (Instr 1)
; t 169.7291 Sustain 127 (Instr 2)
    db 210,0,247,1,57,33,1,1,220,0,57,1  ; n638 t=170.014s dur=503ms, freq=220Hz, sample=57, buffer_id=01:39
    db 38,0,59,8,32,33,1,6,52,0,32,1  ; n639 t=170.224s dur=2107ms, freq=52Hz, sample=32, buffer_id=01:20
    db 127,0,21,8,44,33,1,7,104,0,44,1  ; n640 t=170.262s dur=2069ms, freq=104Hz, sample=44, buffer_id=01:2C
; t 170.3327 Sustain 0 (Instr 1)
; t 170.3327 Sustain 0 (Instr 2)
    db 99,1,150,7,48,36,1,2,131,0,48,1  ; n641 t=170.389s dur=1942ms, freq=131Hz, sample=48, buffer_id=01:30
    db 63,1,136,1,54,35,1,0,185,0,54,1  ; n642 t=170.743s dur=392ms, freq=185Hz, sample=54, buffer_id=01:36
    db 45,1,104,1,56,33,1,1,208,0,56,1  ; n643 t=171.062s dur=360ms, freq=208Hz, sample=56, buffer_id=01:38
    db 86,1,112,1,57,35,1,0,220,0,57,1  ; n644 t=171.363s dur=368ms, freq=220Hz, sample=57, buffer_id=01:39
    db 44,1,114,2,56,33,1,1,208,0,56,1  ; n645 t=171.705s dur=626ms, freq=208Hz, sample=56, buffer_id=01:38
; t 171.8017 Sustain 127 (Instr 1)
; t 171.8017 Sustain 127 (Instr 2)
    db 231,0,173,1,54,33,1,0,185,0,54,1  ; n646 t=172.004s dur=429ms, freq=185Hz, sample=54, buffer_id=01:36
    db 19,0,210,8,33,35,1,3,55,0,33,1  ; n647 t=172.235s dur=2258ms, freq=55Hz, sample=33, buffer_id=01:21
    db 138,0,190,8,45,35,1,4,110,0,45,1  ; n648 t=172.254s dur=2238ms, freq=110Hz, sample=45, buffer_id=01:2D
; t 172.3309 Sustain 0 (Instr 1)
; t 172.3309 Sustain 0 (Instr 2)
    db 125,1,52,8,49,37,1,5,139,0,49,1  ; n649 t=172.392s dur=2100ms, freq=139Hz, sample=49, buffer_id=01:31
    db 77,1,183,6,52,33,1,0,165,0,52,1  ; n650 t=172.774s dur=1719ms, freq=165Hz, sample=52, buffer_id=01:34
; t 172.8049 Sustain 127 (Instr 1)
; t 172.8049 Sustain 127 (Instr 2)
    db 70,1,106,5,61,33,1,1,21,1,61,1  ; n651 t=173.107s dur=1386ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 136,1,36,4,49,33,1,5,139,0,49,1  ; n652 t=173.433s dur=1060ms, freq=139Hz, sample=49, buffer_id=01:31
    db 51,1,156,2,52,33,1,0,165,0,52,1  ; n653 t=173.825s dur=668ms, freq=165Hz, sample=52, buffer_id=01:34
    db 5,1,213,1,61,33,1,1,21,1,61,1  ; n654 t=174.132s dur=469ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 43,0,165,9,30,34,1,2,46,0,30,1  ; n655 t=174.393s dur=2469ms, freq=46Hz, sample=30, buffer_id=01:1E
    db 138,0,122,9,42,35,1,6,92,0,42,1  ; n656 t=174.436s dur=2426ms, freq=92Hz, sample=42, buffer_id=01:2A
; t 174.4932 Sustain 0 (Instr 1)
; t 174.4932 Sustain 0 (Instr 2)
    db 131,1,240,8,51,37,1,7,156,0,51,1  ; n657 t=174.574s dur=2288ms, freq=156Hz, sample=51, buffer_id=01:33
; t 174.8702 Sustain 127 (Instr 1)
; t 174.8702 Sustain 127 (Instr 2)
    db 128,1,110,7,57,33,1,0,220,0,57,1  ; n658 t=174.961s dur=1902ms, freq=220Hz, sample=57, buffer_id=01:39
    db 118,1,238,5,61,33,1,1,21,1,61,1  ; n659 t=175.344s dur=1518ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 138,1,120,4,51,33,1,7,156,0,51,1  ; n660 t=175.718s dur=1144ms, freq=156Hz, sample=51, buffer_id=01:33
    db 123,1,238,2,57,33,1,0,220,0,57,1  ; n661 t=176.112s dur=750ms, freq=220Hz, sample=57, buffer_id=01:39
    db 67,1,221,1,61,33,1,1,21,1,61,1  ; n662 t=176.492s dur=477ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 62,0,73,11,32,34,1,3,52,0,32,1  ; n663 t=176.815s dur=2889ms, freq=52Hz, sample=32, buffer_id=01:20
; t 176.8630 Sustain 0 (Instr 1)
; t 176.8630 Sustain 0 (Instr 2)
    db 64,0,10,11,44,35,1,4,104,0,44,1  ; n664 t=176.877s dur=2826ms, freq=104Hz, sample=44, buffer_id=01:2C
    db 123,1,19,5,51,36,1,7,156,0,51,1  ; n665 t=176.941s dur=1299ms, freq=156Hz, sample=51, buffer_id=01:33
; t 177.1194 Sustain 127 (Instr 1)
; t 177.1194 Sustain 127 (Instr 2)
    db 134,1,152,3,56,33,1,0,208,0,56,1  ; n666 t=177.320s dur=920ms, freq=208Hz, sample=56, buffer_id=01:38
; t 177.4403 Sustain 0 (Instr 1)
; t 177.4403 Sustain 0 (Instr 2)
    db 210,1,18,2,60,33,1,1,6,1,60,1  ; n667 t=177.709s dur=530ms, freq=262Hz, sample=60, buffer_id=01:3C
; t 177.7332 Sustain 127 (Instr 1)
; t 177.7332 Sustain 127 (Instr 2)
    db 186,1,248,5,51,36,1,7,156,0,51,1  ; n668 t=178.176s dur=1528ms, freq=156Hz, sample=51, buffer_id=01:33
; t 178.2404 Sustain 0 (Instr 1)
; t 178.2404 Sustain 0 (Instr 2)
    db 252,1,62,4,54,33,1,0,185,0,54,1  ; n669 t=178.617s dur=1086ms, freq=185Hz, sample=54, buffer_id=01:36
; t 179.0912 Sustain 127 (Instr 1)
; t 179.0912 Sustain 127 (Instr 2)
    db 234,1,66,2,60,33,1,1,6,1,60,1  ; n670 t=179.126s dur=578ms, freq=262Hz, sample=60, buffer_id=01:3C
    db 5,0,92,21,37,34,1,2,69,0,37,1  ; n671 t=179.616s dur=5468ms, freq=69Hz, sample=37, buffer_id=01:25
    db 6,0,86,21,49,34,1,5,139,0,49,1  ; n672 t=179.621s dur=5462ms, freq=139Hz, sample=49, buffer_id=01:31
    db 18,0,80,21,44,35,1,4,104,0,44,1  ; n673 t=179.627s dur=5456ms, freq=104Hz, sample=44, buffer_id=01:2C
    db 248,1,62,21,52,35,1,6,165,0,52,1  ; n674 t=179.646s dur=5438ms, freq=165Hz, sample=52, buffer_id=01:34
; t 179.7040 Sustain 0 (Instr 1)
; t 179.7040 Sustain 0 (Instr 2)
; t 180.1067 Sustain 127 (Instr 1)
; t 180.1067 Sustain 127 (Instr 2)
    db 149,1,70,19,56,33,1,0,208,0,56,1  ; n675 t=180.150s dur=4934ms, freq=208Hz, sample=56, buffer_id=01:38
    db 124,1,177,17,61,33,1,1,21,1,61,1  ; n676 t=180.554s dur=4529ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 179,1,53,16,56,33,1,0,208,0,56,1  ; n677 t=180.935s dur=4149ms, freq=208Hz, sample=56, buffer_id=01:38
    db 125,1,130,14,61,33,1,1,21,1,61,1  ; n678 t=181.369s dur=3714ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 112,1,5,13,64,33,1,3,74,1,64,1  ; n679 t=181.750s dur=3333ms, freq=330Hz, sample=64, buffer_id=01:40
    db 183,1,149,11,56,33,1,0,208,0,56,1  ; n680 t=182.119s dur=2965ms, freq=208Hz, sample=56, buffer_id=01:38
    db 148,1,222,9,61,33,1,1,21,1,61,1  ; n681 t=182.558s dur=2526ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 196,1,74,8,64,33,1,3,74,1,64,1  ; n682 t=182.962s dur=2122ms, freq=330Hz, sample=64, buffer_id=01:40
    db 31,0,134,6,56,38,1,0,208,0,56,1  ; n683 t=183.414s dur=1670ms, freq=208Hz, sample=56, buffer_id=01:38
    db 201,1,103,6,68,48,2,7,159,1,68,1  ; n684 t=183.445s dur=1639ms, freq=415Hz, sample=68, buffer_id=01:44
    db 2,2,157,4,61,33,1,1,21,1,61,1  ; n685 t=183.902s dur=1181ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 187,1,155,2,64,33,1,3,74,1,64,1  ; n686 t=184.417s dur=667ms, freq=330Hz, sample=64, buffer_id=01:40
    db 242,0,223,0,68,44,2,7,159,1,68,1  ; n687 t=184.860s dur=223ms, freq=415Hz, sample=68, buffer_id=01:44
; t 185.0840 Sustain 0 (Instr 1)
; t 185.0840 Sustain 0 (Instr 2)
    db 5,0,124,19,36,39,1,8,65,0,36,1  ; n688 t=185.102s dur=4988ms, freq=65Hz, sample=36, buffer_id=01:24
    db 0,0,53,14,56,39,1,0,208,0,56,1  ; n689 t=185.108s dur=3637ms, freq=208Hz, sample=56, buffer_id=01:38
    db 13,0,119,19,44,39,1,4,104,0,44,1  ; n690 t=185.108s dur=4983ms, freq=104Hz, sample=44, buffer_id=01:2C
    db 4,0,106,19,48,39,1,9,131,0,48,1  ; n691 t=185.121s dur=4970ms, freq=131Hz, sample=48, buffer_id=01:30
    db 178,1,36,14,68,47,2,7,159,1,68,1  ; n692 t=185.125s dur=3620ms, freq=415Hz, sample=68, buffer_id=01:44
; t 185.5262 Sustain 127 (Instr 1)
; t 185.5262 Sustain 127 (Instr 2)
    db 131,1,114,12,63,33,1,1,55,1,63,1  ; n693 t=185.559s dur=3186ms, freq=311Hz, sample=63, buffer_id=01:3F
    db 139,1,239,10,66,33,1,2,114,1,66,1  ; n694 t=185.946s dur=2799ms, freq=370Hz, sample=66, buffer_id=01:42
    db 100,1,100,9,56,36,1,0,208,0,56,1  ; n695 t=186.341s dur=2404ms, freq=208Hz, sample=56, buffer_id=01:38
    db 151,1,0,8,63,33,1,1,55,1,63,1  ; n696 t=186.697s dur=2048ms, freq=311Hz, sample=63, buffer_id=01:3F
    db 101,1,105,6,66,33,1,2,114,1,66,1  ; n697 t=187.104s dur=1641ms, freq=370Hz, sample=66, buffer_id=01:42
    db 145,1,4,5,56,35,1,0,208,0,56,1  ; n698 t=187.461s dur=1284ms, freq=208Hz, sample=56, buffer_id=01:38
    db 142,1,116,3,63,33,1,1,55,1,63,1  ; n699 t=187.862s dur=884ms, freq=311Hz, sample=63, buffer_id=01:3F
    db 187,1,4,2,66,33,1,2,114,1,66,1  ; n700 t=188.260s dur=516ms, freq=370Hz, sample=66, buffer_id=01:42
    db 1,0,107,5,68,48,2,7,159,1,68,1  ; n701 t=188.703s dur=1387ms, freq=415Hz, sample=68, buffer_id=01:44
    db 223,1,106,5,56,36,1,0,208,0,56,1  ; n702 t=188.704s dur=1386ms, freq=208Hz, sample=56, buffer_id=01:38
; t 188.7454 Sustain 0 (Instr 1)
; t 188.7454 Sustain 0 (Instr 2)
; t 189.0423 Sustain 127 (Instr 1)
; t 189.0423 Sustain 127 (Instr 2)
    db 122,1,139,3,63,33,1,1,55,1,63,1  ; n703 t=189.183s dur=907ms, freq=311Hz, sample=63, buffer_id=01:3F
    db 24,1,18,2,66,33,1,2,114,1,66,1  ; n704 t=189.561s dur=530ms, freq=370Hz, sample=66, buffer_id=01:42
    db 180,0,250,0,68,44,2,7,159,1,68,1  ; n705 t=189.840s dur=250ms, freq=415Hz, sample=68, buffer_id=01:44
    db 36,0,227,9,37,39,1,3,69,0,37,1  ; n706 t=190.020s dur=2531ms, freq=69Hz, sample=37, buffer_id=01:25
    db 40,0,191,9,49,39,1,5,139,0,49,1  ; n707 t=190.057s dur=2495ms, freq=139Hz, sample=49, buffer_id=01:31
; t 190.0911 Sustain 0 (Instr 1)
; t 190.0911 Sustain 0 (Instr 2)
    db 10,0,151,9,56,38,1,0,208,0,56,1  ; n708 t=190.096s dur=2455ms, freq=208Hz, sample=56, buffer_id=01:38
    db 176,1,141,9,68,48,2,7,159,1,68,1  ; n709 t=190.106s dur=2445ms, freq=415Hz, sample=68, buffer_id=01:44
; t 190.4385 Sustain 127 (Instr 1)
; t 190.4385 Sustain 127 (Instr 2)
    db 126,1,221,7,61,33,1,1,21,1,61,1  ; n710 t=190.538s dur=2013ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 115,1,95,6,64,33,1,2,74,1,64,1  ; n711 t=190.920s dur=1631ms, freq=330Hz, sample=64, buffer_id=01:40
    db 167,1,236,4,56,35,1,0,208,0,56,1  ; n712 t=191.292s dur=1260ms, freq=208Hz, sample=56, buffer_id=01:38
    db 157,1,158,3,61,33,1,1,21,1,61,1  ; n713 t=191.714s dur=926ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 61,1,233,1,64,33,1,2,74,1,64,1  ; n714 t=192.127s dur=489ms, freq=330Hz, sample=64, buffer_id=01:40
    db 12,0,110,10,30,40,1,4,46,0,30,1  ; n715 t=192.444s dur=2670ms, freq=46Hz, sample=30, buffer_id=01:1E
    db 96,0,99,10,42,40,1,6,92,0,42,1  ; n716 t=192.456s dur=2659ms, freq=92Hz, sample=42, buffer_id=01:2A
    db 17,0,3,10,57,38,1,8,220,0,57,1  ; n717 t=192.552s dur=2563ms, freq=220Hz, sample=57, buffer_id=01:39
; t 192.5517 Sustain 0 (Instr 1)
; t 192.5517 Sustain 0 (Instr 2)
    db 215,1,242,9,69,52,2,9,184,1,69,1  ; n718 t=192.569s dur=2546ms, freq=440Hz, sample=69, buffer_id=01:45
; t 192.9840 Sustain 127 (Instr 1)
; t 192.9840 Sustain 127 (Instr 2)
    db 161,1,27,8,61,33,1,0,21,1,61,1  ; n719 t=193.040s dur=2075ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 213,1,122,6,66,33,1,1,114,1,66,1  ; n720 t=193.457s dur=1658ms, freq=370Hz, sample=66, buffer_id=01:42
    db 165,1,165,4,57,35,1,8,220,0,57,1  ; n721 t=193.926s dur=1189ms, freq=220Hz, sample=57, buffer_id=01:39
    db 110,1,255,2,61,33,1,0,21,1,61,1  ; n722 t=194.347s dur=767ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 49,1,42,2,66,33,1,1,114,1,66,1  ; n723 t=194.713s dur=554ms, freq=370Hz, sample=66, buffer_id=01:42
    db 35,0,206,10,35,36,1,2,62,0,35,1  ; n724 t=195.018s dur=2766ms, freq=62Hz, sample=35, buffer_id=01:23
    db 120,0,171,10,47,36,1,3,123,0,47,1  ; n725 t=195.054s dur=2731ms, freq=123Hz, sample=47, buffer_id=01:2F
; t 195.1151 Sustain 0 (Instr 1)
; t 195.1151 Sustain 0 (Instr 2)
    db 2,0,50,10,68,44,2,5,159,1,68,1  ; n726 t=195.174s dur=2610ms, freq=415Hz, sample=68, buffer_id=01:44
    db 206,1,48,10,56,36,1,7,208,0,56,1  ; n727 t=195.176s dur=2608ms, freq=208Hz, sample=56, buffer_id=01:38
; t 195.6021 Sustain 127 (Instr 1)
; t 195.6021 Sustain 127 (Instr 2)
    db 151,1,98,8,59,33,1,0,247,0,59,1  ; n728 t=195.639s dur=2146ms, freq=247Hz, sample=59, buffer_id=01:3B
    db 193,1,203,6,64,33,1,1,74,1,64,1  ; n729 t=196.046s dur=1739ms, freq=330Hz, sample=64, buffer_id=01:40
    db 126,1,9,5,56,35,1,7,208,0,56,1  ; n730 t=196.495s dur=1289ms, freq=208Hz, sample=56, buffer_id=01:38
    db 151,1,140,3,59,33,1,0,247,0,59,1  ; n731 t=196.877s dur=908ms, freq=247Hz, sample=59, buffer_id=01:3B
    db 43,1,244,1,64,33,1,1,74,1,64,1  ; n732 t=197.284s dur=500ms, freq=330Hz, sample=64, buffer_id=01:40
    db 100,0,16,13,35,36,1,2,62,0,35,1  ; n733 t=197.583s dur=3344ms, freq=62Hz, sample=35, buffer_id=01:23
    db 106,0,172,12,47,36,1,3,123,0,47,1  ; n734 t=197.683s dur=3244ms, freq=123Hz, sample=47, buffer_id=01:2F
; t 197.7849 Sustain 0 (Instr 1)
; t 197.7849 Sustain 0 (Instr 2)
    db 2,0,65,12,66,37,1,4,114,1,66,1  ; n735 t=197.789s dur=3137ms, freq=370Hz, sample=66, buffer_id=01:42
    db 205,1,63,12,57,37,1,6,220,0,57,1  ; n736 t=197.791s dur=3135ms, freq=220Hz, sample=57, buffer_id=01:39
; t 198.0128 Sustain 127 (Instr 1)
; t 198.0128 Sustain 127 (Instr 2)
    db 213,1,114,10,59,33,1,0,247,0,59,1  ; n737 t=198.252s dur=2674ms, freq=247Hz, sample=59, buffer_id=01:3B
    db 203,1,157,8,63,33,1,1,55,1,63,1  ; n738 t=198.721s dur=2205ms, freq=311Hz, sample=63, buffer_id=01:3F
    db 29,0,210,6,57,36,1,6,220,0,57,1  ; n739 t=199.180s dur=1746ms, freq=220Hz, sample=57, buffer_id=01:39
    db 58,2,181,6,71,48,2,5,238,1,71,1  ; n740 t=199.209s dur=1717ms, freq=494Hz, sample=71, buffer_id=01:47
    db 79,2,124,4,59,33,1,0,247,0,59,1  ; n741 t=199.779s dur=1148ms, freq=247Hz, sample=59, buffer_id=01:3B
    db 155,1,45,2,63,33,1,1,55,1,63,1  ; n742 t=200.369s dur=557ms, freq=311Hz, sample=63, buffer_id=01:3F
    db 55,0,32,20,40,36,1,7,82,0,40,1  ; n743 t=200.781s dur=5152ms, freq=82Hz, sample=40, buffer_id=01:28
    db 83,0,233,19,52,35,1,8,165,0,52,1  ; n744 t=200.836s dur=5097ms, freq=165Hz, sample=52, buffer_id=01:34
    db 39,0,112,14,56,34,1,9,208,0,56,1  ; n745 t=200.918s dur=3696ms, freq=208Hz, sample=56, buffer_id=01:38
; t 200.9270 Sustain 0 (Instr 1)
; t 200.9270 Sustain 0 (Instr 2)
    db 189,1,73,14,64,37,1,10,74,1,64,1  ; n746 t=200.957s dur=3657ms, freq=330Hz, sample=64, buffer_id=01:40
; t 201.2052 Sustain 127 (Instr 1)
; t 201.2052 Sustain 127 (Instr 2)
    db 92,1,140,12,59,33,1,0,247,0,59,1  ; n747 t=201.402s dur=3212ms, freq=247Hz, sample=59, buffer_id=01:3B
    db 125,1,48,11,64,33,1,10,74,1,64,1  ; n748 t=201.750s dur=2864ms, freq=330Hz, sample=64, buffer_id=01:40
    db 119,1,179,9,59,33,1,0,247,0,59,1  ; n749 t=202.131s dur=2483ms, freq=247Hz, sample=59, buffer_id=01:3B
    db 134,1,60,8,64,33,1,10,74,1,64,1  ; n750 t=202.506s dur=2108ms, freq=330Hz, sample=64, buffer_id=01:40
    db 170,1,182,6,68,38,2,1,159,1,68,1  ; n751 t=202.896s dur=1718ms, freq=415Hz, sample=68, buffer_id=01:44
    db 150,1,12,5,59,33,1,0,247,0,59,1  ; n752 t=203.323s dur=1292ms, freq=247Hz, sample=59, buffer_id=01:3B
    db 131,1,117,3,64,33,1,10,74,1,64,1  ; n753 t=203.729s dur=885ms, freq=330Hz, sample=64, buffer_id=01:40
    db 197,1,13,2,68,38,2,1,159,1,68,1  ; n754 t=204.115s dur=525ms, freq=415Hz, sample=68, buffer_id=01:44
    db 12,0,84,5,59,38,1,0,247,0,59,1  ; n755 t=204.569s dur=1364ms, freq=247Hz, sample=59, buffer_id=01:3B
    db 195,1,73,5,71,51,2,2,238,1,71,1  ; n756 t=204.580s dur=1353ms, freq=494Hz, sample=71, buffer_id=01:47
; t 204.6147 Sustain 0 (Instr 1)
; t 204.6147 Sustain 0 (Instr 2)
; t 204.9744 Sustain 127 (Instr 1)
; t 204.9744 Sustain 127 (Instr 2)
    db 130,1,134,3,64,33,1,1,74,1,64,1  ; n757 t=205.031s dur=902ms, freq=330Hz, sample=64, buffer_id=01:40
; t 205.1097 Soft 127 (Instr 1)
; t 205.1097 Soft 127 (Instr 2)
    db 5,1,4,2,68,40,2,3,159,1,68,1  ; n758 t=205.417s dur=516ms, freq=415Hz, sample=68, buffer_id=01:44
    db 142,0,255,0,71,43,2,2,238,1,71,1  ; n759 t=205.678s dur=255ms, freq=494Hz, sample=71, buffer_id=01:47
    db 30,0,83,18,39,40,1,4,78,0,39,1  ; n760 t=205.820s dur=4691ms, freq=78Hz, sample=39, buffer_id=01:27
    db 56,0,53,18,51,40,1,5,156,0,51,1  ; n761 t=205.850s dur=4661ms, freq=156Hz, sample=51, buffer_id=01:33
    db 9,0,71,13,71,53,2,2,238,1,71,1  ; n762 t=205.905s dur=3399ms, freq=494Hz, sample=71, buffer_id=01:47
    db 101,1,62,13,59,39,1,0,247,0,59,1  ; n763 t=205.914s dur=3390ms, freq=247Hz, sample=59, buffer_id=01:3B
; t 205.9334 Sustain 0 (Instr 1)
; t 205.9334 Sustain 0 (Instr 2)
    db 122,1,218,11,66,34,1,1,114,1,66,1  ; n764 t=206.271s dur=3034ms, freq=370Hz, sample=66, buffer_id=01:42
; t 206.3340 Sustain 127 (Instr 1)
; t 206.3340 Sustain 127 (Instr 2)
    db 101,1,96,10,69,38,2,3,184,1,69,1  ; n765 t=206.649s dur=2656ms, freq=440Hz, sample=69, buffer_id=01:45
    db 132,1,251,8,59,33,1,0,247,0,59,1  ; n766 t=207.005s dur=2299ms, freq=247Hz, sample=59, buffer_id=01:3B
    db 85,1,119,7,66,33,1,1,114,1,66,1  ; n767 t=207.393s dur=1911ms, freq=370Hz, sample=66, buffer_id=01:42
    db 141,1,34,6,69,38,2,3,184,1,69,1  ; n768 t=207.734s dur=1570ms, freq=440Hz, sample=69, buffer_id=01:45
    db 112,1,149,4,59,33,1,0,247,0,59,1  ; n769 t=208.131s dur=1173ms, freq=247Hz, sample=59, buffer_id=01:3B
    db 85,1,37,3,66,33,1,1,114,1,66,1  ; n770 t=208.500s dur=805ms, freq=370Hz, sample=66, buffer_id=01:42
    db 154,1,228,1,69,38,2,3,184,1,69,1  ; n771 t=208.841s dur=484ms, freq=440Hz, sample=69, buffer_id=01:45
    db 14,0,236,4,71,49,2,2,238,1,71,1  ; n772 t=209.251s dur=1260ms, freq=494Hz, sample=71, buffer_id=01:47
    db 168,1,222,4,59,36,1,0,247,0,59,1  ; n773 t=209.265s dur=1246ms, freq=247Hz, sample=59, buffer_id=01:3B
; t 209.3047 Sustain 0 (Instr 1)
; t 209.3047 Sustain 0 (Instr 2)
; t 209.6149 Sustain 127 (Instr 1)
; t 209.6149 Sustain 127 (Instr 2)
    db 104,1,54,3,66,33,1,1,114,1,66,1  ; n774 t=209.689s dur=822ms, freq=370Hz, sample=66, buffer_id=01:42
    db 220,0,206,1,69,38,2,3,184,1,69,1  ; n775 t=210.049s dur=462ms, freq=440Hz, sample=69, buffer_id=01:45
    db 120,0,242,0,71,41,2,2,238,1,71,1  ; n776 t=210.269s dur=242ms, freq=494Hz, sample=71, buffer_id=01:47
    db 38,0,100,9,40,37,1,6,82,0,40,1  ; n777 t=210.389s dur=2404ms, freq=82Hz, sample=40, buffer_id=01:28
    db 75,0,63,9,52,36,1,7,165,0,52,1  ; n778 t=210.427s dur=2367ms, freq=165Hz, sample=52, buffer_id=01:34
    db 1,0,244,8,71,57,2,2,238,1,71,1  ; n779 t=210.502s dur=2292ms, freq=494Hz, sample=71, buffer_id=01:47
    db 131,1,243,8,59,35,1,0,247,0,59,1  ; n780 t=210.503s dur=2291ms, freq=247Hz, sample=59, buffer_id=01:3B
; t 210.5113 Sustain 0 (Instr 1)
; t 210.5113 Sustain 0 (Instr 2)
    db 120,1,111,7,64,33,1,1,74,1,64,1  ; n781 t=210.890s dur=1903ms, freq=330Hz, sample=64, buffer_id=01:40
; t 210.9160 Sustain 127 (Instr 1)
; t 210.9160 Sustain 127 (Instr 2)
    db 131,1,247,5,68,38,2,3,159,1,68,1  ; n782 t=211.266s dur=1527ms, freq=415Hz, sample=68, buffer_id=01:44
    db 97,1,116,4,59,33,1,0,247,0,59,1  ; n783 t=211.653s dur=1140ms, freq=247Hz, sample=59, buffer_id=01:3B
    db 109,1,19,3,64,33,1,1,74,1,64,1  ; n784 t=212.006s dur=787ms, freq=330Hz, sample=64, buffer_id=01:40
; t 212.2326 Soft 0 (Instr 1)
; t 212.2326 Soft 0 (Instr 2)
    db 9,1,187,1,68,40,2,3,159,1,68,1  ; n785 t=212.371s dur=443ms, freq=415Hz, sample=68, buffer_id=01:44
    db 12,0,15,5,39,39,1,4,78,0,39,1  ; n786 t=212.636s dur=1295ms, freq=78Hz, sample=39, buffer_id=01:27
    db 115,0,3,5,51,39,1,5,156,0,51,1  ; n787 t=212.648s dur=1283ms, freq=156Hz, sample=51, buffer_id=01:33
    db 11,0,144,4,60,40,1,8,6,1,60,1  ; n788 t=212.763s dur=1168ms, freq=262Hz, sample=60, buffer_id=01:3C
    db 148,1,133,4,72,58,2,9,11,2,72,1  ; n789 t=212.774s dur=1157ms, freq=523Hz, sample=72, buffer_id=01:48
; t 212.7938 Sustain 0 (Instr 1)
; t 212.7938 Sustain 0 (Instr 2)
; t 213.1222 Sustain 127 (Instr 1)
; t 213.1222 Sustain 127 (Instr 2)
    db 96,1,241,2,66,40,1,0,114,1,66,1  ; n790 t=213.178s dur=753ms, freq=370Hz, sample=66, buffer_id=01:42
    db 220,0,184,1,68,41,2,1,159,1,68,1  ; n791 t=213.530s dur=440ms, freq=415Hz, sample=68, buffer_id=01:44
    db 28,0,5,6,37,46,1,2,69,0,37,1  ; n792 t=213.750s dur=1541ms, freq=69Hz, sample=37, buffer_id=01:25
    db 127,0,233,5,49,46,1,3,139,0,49,1  ; n793 t=213.778s dur=1513ms, freq=139Hz, sample=49, buffer_id=01:31
    db 7,0,107,5,73,60,2,6,42,2,73,1  ; n794 t=213.905s dur=1387ms, freq=554Hz, sample=73, buffer_id=01:49
    db 185,1,99,5,61,44,1,7,21,1,61,1  ; n795 t=213.912s dur=1379ms, freq=277Hz, sample=61, buffer_id=01:3D
; t 213.9313 Sustain 0 (Instr 1)
; t 213.9313 Sustain 0 (Instr 2)
    db 148,1,170,3,64,38,1,0,74,1,64,1  ; n796 t=214.353s dur=938ms, freq=330Hz, sample=64, buffer_id=01:40
; t 214.3916 Sustain 127 (Instr 1)
; t 214.3916 Sustain 127 (Instr 2)
; t 214.7361 Soft 127 (Instr 1)
; t 214.7361 Soft 127 (Instr 2)
    db 190,1,22,2,68,38,2,1,159,1,68,1  ; n797 t=214.757s dur=534ms, freq=415Hz, sample=68, buffer_id=01:44
    db 80,0,173,10,36,36,1,4,65,0,36,1  ; n798 t=215.204s dur=2733ms, freq=65Hz, sample=36, buffer_id=01:24
    db 0,0,92,10,44,36,1,5,104,0,44,1  ; n799 t=215.284s dur=2652ms, freq=104Hz, sample=44, buffer_id=01:2C
    db 88,0,92,10,48,36,1,8,131,0,48,1  ; n800 t=215.284s dur=2652ms, freq=131Hz, sample=48, buffer_id=01:30
; t 215.2917 Sustain 0 (Instr 1)
; t 215.2917 Sustain 0 (Instr 2)
    db 2,0,4,10,75,47,2,9,110,2,75,1  ; n801 t=215.372s dur=2564ms, freq=622Hz, sample=75, buffer_id=01:4B
    db 172,1,2,10,63,35,1,10,55,1,63,1  ; n802 t=215.374s dur=2562ms, freq=311Hz, sample=63, buffer_id=01:3F
; t 215.6650 Sustain 127 (Instr 1)
; t 215.6650 Sustain 127 (Instr 2)
    db 110,1,86,8,66,33,1,0,114,1,66,1  ; n803 t=215.802s dur=2134ms, freq=370Hz, sample=66, buffer_id=01:42
    db 152,1,232,6,68,38,2,1,159,1,68,1  ; n804 t=216.168s dur=1768ms, freq=415Hz, sample=68, buffer_id=01:44
    db 143,1,81,5,63,33,1,10,55,1,63,1  ; n805 t=216.576s dur=1361ms, freq=311Hz, sample=63, buffer_id=01:3F
; t 216.8513 Soft 127 (Instr 1)
; t 216.8513 Soft 127 (Instr 2)
    db 119,1,194,3,66,33,1,0,114,1,66,1  ; n806 t=216.975s dur=962ms, freq=370Hz, sample=66, buffer_id=01:42
    db 106,1,74,2,68,39,2,1,159,1,68,1  ; n807 t=217.350s dur=586ms, freq=415Hz, sample=68, buffer_id=01:44
    db 68,0,80,10,37,39,1,2,69,0,37,1  ; n808 t=217.712s dur=2640ms, freq=69Hz, sample=37, buffer_id=01:25
    db 138,0,12,10,49,38,1,3,139,0,49,1  ; n809 t=217.779s dur=2572ms, freq=139Hz, sample=49, buffer_id=01:31
    db 23,0,130,9,64,36,1,6,74,1,64,1  ; n810 t=217.917s dur=2434ms, freq=330Hz, sample=64, buffer_id=01:40
; t 217.9369 Sustain 0 (Instr 1)
; t 217.9369 Sustain 0 (Instr 2)
    db 148,1,107,9,76,56,2,7,147,2,76,1  ; n811 t=217.940s dur=2411ms, freq=659Hz, sample=76, buffer_id=01:4C
; t 218.1825 Sustain 127 (Instr 1)
; t 218.1825 Sustain 127 (Instr 2)
    db 196,1,215,7,68,38,2,0,159,1,68,1  ; n812 t=218.345s dur=2007ms, freq=415Hz, sample=68, buffer_id=01:44
    db 111,1,18,6,73,38,2,1,42,2,73,1  ; n813 t=218.797s dur=1554ms, freq=554Hz, sample=73, buffer_id=01:49
    db 106,1,163,4,64,33,1,6,74,1,64,1  ; n814 t=219.164s dur=1187ms, freq=330Hz, sample=64, buffer_id=01:40
    db 195,1,223,3,68,38,2,0,159,1,68,1  ; n815 t=219.526s dur=991ms, freq=415Hz, sample=68, buffer_id=01:44
    db 230,0,8,2,73,38,2,1,42,2,73,1  ; n816 t=219.977s dur=520ms, freq=554Hz, sample=73, buffer_id=01:49
    db 62,0,1,11,30,41,1,4,46,0,30,1  ; n817 t=220.207s dur=2817ms, freq=46Hz, sample=30, buffer_id=01:1E
    db 151,0,195,10,42,40,1,5,92,0,42,1  ; n818 t=220.269s dur=2755ms, freq=92Hz, sample=42, buffer_id=01:2A
; t 220.3517 Sustain 0 (Instr 1)
; t 220.3517 Sustain 0 (Instr 2)
    db 7,0,44,10,74,55,2,8,75,2,74,1  ; n819 t=220.420s dur=2604ms, freq=587Hz, sample=74, buffer_id=01:4A
    db 205,1,36,10,62,38,1,9,38,1,62,1  ; n820 t=220.428s dur=2596ms, freq=294Hz, sample=62, buffer_id=01:3E
; t 220.8010 Sustain 127 (Instr 1)
; t 220.8010 Sustain 127 (Instr 2)
    db 203,1,87,8,66,33,1,0,114,1,66,1  ; n821 t=220.889s dur=2135ms, freq=370Hz, sample=66, buffer_id=01:42
    db 172,1,140,6,69,38,2,1,184,1,69,1  ; n822 t=221.348s dur=1676ms, freq=440Hz, sample=69, buffer_id=01:45
    db 146,1,224,4,62,33,1,9,38,1,62,1  ; n823 t=221.776s dur=1248ms, freq=294Hz, sample=62, buffer_id=01:3E
    db 180,1,78,3,66,33,1,0,114,1,66,1  ; n824 t=222.178s dur=846ms, freq=370Hz, sample=66, buffer_id=01:42
    db 56,1,2,2,69,38,2,1,184,1,69,1  ; n825 t=222.614s dur=514ms, freq=440Hz, sample=69, buffer_id=01:45
    db 63,0,210,10,32,35,1,2,52,0,32,1  ; n826 t=222.926s dur=2770ms, freq=52Hz, sample=32, buffer_id=01:20
    db 100,0,147,10,44,35,1,3,104,0,44,1  ; n827 t=222.989s dur=2707ms, freq=104Hz, sample=44, buffer_id=01:2C
; t 223.0245 Sustain 0 (Instr 1)
; t 223.0245 Sustain 0 (Instr 2)
    db 4,0,47,10,60,34,1,6,6,1,60,1  ; n828 t=223.089s dur=2607ms, freq=262Hz, sample=60, buffer_id=01:3C
    db 217,1,43,10,72,52,2,7,11,2,72,1  ; n829 t=223.093s dur=2603ms, freq=523Hz, sample=72, buffer_id=01:48
; t 223.4286 Sustain 127 (Instr 1)
; t 223.4286 Sustain 127 (Instr 2)
    db 146,1,82,8,66,33,1,0,114,1,66,1  ; n830 t=223.566s dur=2130ms, freq=370Hz, sample=66, buffer_id=01:42
    db 138,1,192,6,68,38,2,1,159,1,68,1  ; n831 t=223.968s dur=1728ms, freq=415Hz, sample=68, buffer_id=01:44
    db 176,1,54,5,60,33,1,6,6,1,60,1  ; n832 t=224.362s dur=1334ms, freq=262Hz, sample=60, buffer_id=01:3C
    db 134,1,134,3,66,33,1,0,114,1,66,1  ; n833 t=224.794s dur=902ms, freq=370Hz, sample=66, buffer_id=01:42
    db 85,1,0,2,68,38,2,1,159,1,68,1  ; n834 t=225.184s dur=512ms, freq=415Hz, sample=68, buffer_id=01:44
    db 52,0,209,26,37,36,1,4,69,0,37,1  ; n835 t=225.525s dur=6865ms, freq=69Hz, sample=37, buffer_id=01:25
    db 111,0,158,26,49,35,1,5,139,0,49,1  ; n836 t=225.577s dur=6814ms, freq=139Hz, sample=49, buffer_id=01:31
    db 14,0,143,13,73,43,2,8,42,2,73,1  ; n837 t=225.688s dur=3471ms, freq=554Hz, sample=73, buffer_id=01:49
; t 225.6965 Sustain 0 (Instr 1)
; t 225.6965 Sustain 0 (Instr 2)
    db 133,1,72,9,61,34,1,9,21,1,61,1  ; n838 t=225.702s dur=2376ms, freq=277Hz, sample=61, buffer_id=01:3D
; t 225.9655 Sustain 127 (Instr 1)
; t 225.9655 Sustain 127 (Instr 2)
    db 135,1,195,7,64,33,1,0,74,1,64,1  ; n839 t=226.091s dur=1987ms, freq=330Hz, sample=64, buffer_id=01:40
    db 108,1,60,6,68,38,2,1,159,1,68,1  ; n840 t=226.482s dur=1596ms, freq=415Hz, sample=68, buffer_id=01:44
; t 226.7595 Soft 0 (Instr 1)
; t 226.7595 Soft 0 (Instr 2)
    db 128,1,208,4,61,38,1,9,21,1,61,1  ; n841 t=226.846s dur=1232ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 140,1,80,3,64,38,1,0,74,1,64,1  ; n842 t=227.230s dur=848ms, freq=330Hz, sample=64, buffer_id=01:40
    db 107,1,196,1,68,42,2,1,159,1,68,1  ; n843 t=227.626s dur=452ms, freq=415Hz, sample=68, buffer_id=01:44
    db 116,1,146,4,61,37,1,9,21,1,61,1  ; n844 t=227.989s dur=1170ms, freq=277Hz, sample=61, buffer_id=01:3D
; t 228.0784 Sustain 0 (Instr 1)
; t 228.0784 Sustain 0 (Instr 2)
; t 228.2669 Sustain 127 (Instr 1)
; t 228.2669 Sustain 127 (Instr 2)
    db 125,1,30,3,65,33,1,0,93,1,65,1  ; n845 t=228.361s dur=798ms, freq=349Hz, sample=65, buffer_id=01:41
    db 86,1,160,1,68,43,2,1,159,1,68,1  ; n846 t=228.743s dur=416ms, freq=415Hz, sample=68, buffer_id=01:44
    db 4,0,228,4,61,43,1,9,21,1,61,1  ; n847 t=229.084s dur=1252ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 162,1,224,4,73,59,2,8,42,2,73,1  ; n848 t=229.089s dur=1248ms, freq=554Hz, sample=73, buffer_id=01:49
; t 229.1594 Sustain 0 (Instr 1)
; t 229.1594 Sustain 0 (Instr 2)
; t 229.3672 Sustain 127 (Instr 1)
; t 229.3672 Sustain 127 (Instr 2)
    db 88,1,62,3,65,41,1,0,93,1,65,1  ; n849 t=229.506s dur=830ms, freq=349Hz, sample=65, buffer_id=01:41
    db 133,1,230,1,68,38,2,1,159,1,68,1  ; n850 t=229.850s dur=486ms, freq=415Hz, sample=68, buffer_id=01:44
    db 16,0,196,12,74,59,2,2,75,2,74,1  ; n851 t=230.239s dur=3268ms, freq=587Hz, sample=74, buffer_id=01:4A
    db 169,1,87,8,61,46,1,9,21,1,61,1  ; n852 t=230.255s dur=2135ms, freq=277Hz, sample=61, buffer_id=01:3D
; t 230.3367 Sustain 0 (Instr 1)
; t 230.3367 Sustain 0 (Instr 2)
; t 230.6269 Sustain 127 (Instr 1)
; t 230.6269 Sustain 127 (Instr 2)
    db 141,1,174,6,66,41,1,0,114,1,66,1  ; n853 t=230.680s dur=1710ms, freq=370Hz, sample=66, buffer_id=01:42
    db 233,0,33,5,69,38,2,1,184,1,69,1  ; n854 t=231.078s dur=1313ms, freq=440Hz, sample=69, buffer_id=01:45
    db 32,0,55,4,42,42,1,3,92,0,42,1  ; n855 t=231.311s dur=1079ms, freq=92Hz, sample=42, buffer_id=01:2A
    db 69,0,23,4,54,45,1,6,185,0,54,1  ; n856 t=231.343s dur=1047ms, freq=185Hz, sample=54, buffer_id=01:36
    db 53,1,210,3,61,44,1,9,21,1,61,1  ; n857 t=231.412s dur=978ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 124,1,2,3,66,39,1,0,114,1,66,1  ; n858 t=231.721s dur=770ms, freq=370Hz, sample=66, buffer_id=01:42
    db 230,0,126,5,69,38,2,1,184,1,69,1  ; n859 t=232.102s dur=1406ms, freq=440Hz, sample=69, buffer_id=01:45
    db 0,0,151,4,57,44,1,7,220,0,57,1  ; n860 t=232.332s dur=1175ms, freq=220Hz, sample=57, buffer_id=01:39
    db 82,0,151,4,45,44,1,8,110,0,45,1  ; n861 t=232.332s dur=1175ms, freq=110Hz, sample=45, buffer_id=01:2D
; t 232.3468 Soft 127 (Instr 1)
; t 232.3468 Soft 127 (Instr 2)
; t 232.3908 Sustain 0 (Instr 1)
; t 232.3908 Sustain 0 (Instr 2)
    db 123,1,69,4,61,33,1,9,21,1,61,1  ; n862 t=232.414s dur=1093ms, freq=277Hz, sample=61, buffer_id=01:3D
; t 232.5857 Sustain 127 (Instr 1)
; t 232.5857 Sustain 127 (Instr 2)
    db 95,1,28,3,66,33,1,0,114,1,66,1  ; n863 t=232.793s dur=796ms, freq=370Hz, sample=66, buffer_id=01:42
    db 26,1,190,1,69,39,2,1,184,1,69,1  ; n864 t=233.145s dur=446ms, freq=440Hz, sample=69, buffer_id=01:45
    db 0,0,171,4,54,40,1,3,185,0,54,1  ; n865 t=233.426s dur=1195ms, freq=185Hz, sample=54, buffer_id=01:36
    db 72,0,171,4,42,40,1,4,92,0,42,1  ; n866 t=233.426s dur=1195ms, freq=92Hz, sample=42, buffer_id=01:2A
    db 28,0,100,4,72,49,2,5,11,2,72,1  ; n867 t=233.498s dur=1124ms, freq=523Hz, sample=72, buffer_id=01:48
; t 233.5077 Sustain 0 (Instr 1)
; t 233.5077 Sustain 0 (Instr 2)
    db 147,1,72,4,61,33,1,9,21,1,61,1  ; n868 t=233.526s dur=1096ms, freq=277Hz, sample=61, buffer_id=01:3D
; t 233.7990 Sustain 127 (Instr 1)
; t 233.7990 Sustain 127 (Instr 2)
    db 91,1,181,2,66,33,1,0,114,1,66,1  ; n869 t=233.929s dur=693ms, freq=370Hz, sample=66, buffer_id=01:42
    db 254,0,177,1,69,38,2,1,184,1,69,1  ; n870 t=234.275s dur=433ms, freq=440Hz, sample=69, buffer_id=01:45
    db 13,0,41,25,49,37,1,2,139,0,49,1  ; n871 t=234.529s dur=6441ms, freq=139Hz, sample=49, buffer_id=01:31
    db 108,0,28,25,37,37,1,6,69,0,37,1  ; n872 t=234.542s dur=6428ms, freq=69Hz, sample=37, buffer_id=01:25
; t 234.6223 Sustain 0 (Instr 1)
; t 234.6223 Sustain 0 (Instr 2)
    db 18,0,187,12,61,36,1,9,21,1,61,1  ; n873 t=234.650s dur=3259ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 111,1,169,12,73,44,2,7,42,2,73,1  ; n874 t=234.668s dur=3241ms, freq=554Hz, sample=73, buffer_id=01:49
; t 234.9810 Sustain 127 (Instr 1)
; t 234.9810 Sustain 127 (Instr 2)
    db 65,1,58,11,65,33,1,0,93,1,65,1  ; n875 t=235.036s dur=2874ms, freq=349Hz, sample=65, buffer_id=01:41
    db 118,1,249,9,68,38,2,1,159,1,68,1  ; n876 t=235.357s dur=2553ms, freq=415Hz, sample=68, buffer_id=01:44
; t 235.6939 Soft 0 (Instr 1)
; t 235.6939 Soft 0 (Instr 2)
    db 78,1,131,8,61,33,1,9,21,1,61,1  ; n877 t=235.730s dur=2179ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 92,1,53,7,65,33,1,0,93,1,65,1  ; n878 t=236.064s dur=1845ms, freq=349Hz, sample=65, buffer_id=01:41
    db 80,1,217,5,68,41,2,1,159,1,68,1  ; n879 t=236.412s dur=1497ms, freq=415Hz, sample=68, buffer_id=01:44
    db 117,1,137,4,61,40,1,9,21,1,61,1  ; n880 t=236.748s dur=1161ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 89,1,20,3,65,37,1,0,93,1,65,1  ; n881 t=237.121s dur=788ms, freq=349Hz, sample=65, buffer_id=01:41
    db 129,1,188,1,68,40,2,1,159,1,68,1  ; n882 t=237.466s dur=444ms, freq=415Hz, sample=68, buffer_id=01:44
    db 7,0,116,4,73,58,2,7,42,2,73,1  ; n883 t=237.851s dur=1140ms, freq=554Hz, sample=73, buffer_id=01:49
    db 96,1,110,4,61,42,1,9,21,1,61,1  ; n884 t=237.857s dur=1134ms, freq=277Hz, sample=61, buffer_id=01:3D
; t 237.9098 Sustain 0 (Instr 1)
; t 237.9098 Sustain 0 (Instr 2)
; t 238.1431 Sustain 127 (Instr 1)
; t 238.1431 Sustain 127 (Instr 2)
    db 118,1,14,3,65,37,1,0,93,1,65,1  ; n885 t=238.209s dur=782ms, freq=349Hz, sample=65, buffer_id=01:41
    db 97,1,152,1,68,39,2,1,159,1,68,1  ; n886 t=238.583s dur=408ms, freq=415Hz, sample=68, buffer_id=01:44
    db 13,0,65,12,74,57,2,3,75,2,74,1  ; n887 t=238.936s dur=3137ms, freq=587Hz, sample=74, buffer_id=01:4A
    db 122,1,229,7,61,41,1,9,21,1,61,1  ; n888 t=238.949s dur=2021ms, freq=277Hz, sample=61, buffer_id=01:3D
; t 238.9917 Sustain 0 (Instr 1)
; t 238.9917 Sustain 0 (Instr 2)
; t 239.3127 Sustain 127 (Instr 1)
; t 239.3127 Sustain 127 (Instr 2)
    db 131,1,107,6,66,36,1,0,114,1,66,1  ; n889 t=239.327s dur=1643ms, freq=370Hz, sample=66, buffer_id=01:42
    db 200,0,232,4,69,38,2,1,184,1,69,1  ; n890 t=239.714s dur=1256ms, freq=440Hz, sample=69, buffer_id=01:45
    db 19,0,32,4,42,44,1,4,92,0,42,1  ; n891 t=239.914s dur=1056ms, freq=92Hz, sample=42, buffer_id=01:2A
    db 88,0,12,4,54,46,1,5,185,0,54,1  ; n892 t=239.933s dur=1036ms, freq=185Hz, sample=54, buffer_id=01:36
    db 70,1,185,3,61,44,1,9,21,1,61,1  ; n893 t=240.021s dur=953ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 76,1,34,3,66,40,1,0,114,1,66,1  ; n894 t=240.347s dur=802ms, freq=370Hz, sample=66, buffer_id=01:42
    db 249,0,114,5,69,38,2,1,184,1,69,1  ; n895 t=240.679s dur=1394ms, freq=440Hz, sample=69, buffer_id=01:45
    db 7,0,120,4,57,46,1,7,220,0,57,1  ; n896 t=240.929s dur=1144ms, freq=220Hz, sample=57, buffer_id=01:39
    db 93,0,113,4,45,46,1,8,110,0,45,1  ; n897 t=240.936s dur=1137ms, freq=110Hz, sample=45, buffer_id=01:2D
; t 240.9702 Sustain 0 (Instr 1)
; t 240.9702 Sustain 0 (Instr 2)
    db 53,1,20,4,61,33,1,9,21,1,61,1  ; n898 t=241.029s dur=1044ms, freq=277Hz, sample=61, buffer_id=01:3D
; t 241.1971 Sustain 127 (Instr 1)
; t 241.1971 Sustain 127 (Instr 2)
    db 88,1,243,2,66,33,1,0,114,1,66,1  ; n899 t=241.338s dur=755ms, freq=370Hz, sample=66, buffer_id=01:42
    db 242,0,149,1,69,38,2,1,184,1,69,1  ; n900 t=241.682s dur=405ms, freq=440Hz, sample=69, buffer_id=01:45
    db 25,0,171,4,54,47,1,2,185,0,54,1  ; n901 t=241.924s dur=1195ms, freq=185Hz, sample=54, buffer_id=01:36
    db 86,0,147,4,42,46,1,4,92,0,42,1  ; n902 t=241.948s dur=1171ms, freq=92Hz, sample=42, buffer_id=01:2A
    db 2,0,61,4,72,51,2,5,11,2,72,1  ; n903 t=242.034s dur=1085ms, freq=523Hz, sample=72, buffer_id=01:48
    db 156,1,59,4,61,33,1,9,21,1,61,1  ; n904 t=242.036s dur=1083ms, freq=277Hz, sample=61, buffer_id=01:3D
; t 242.0733 Sustain 0 (Instr 1)
; t 242.0733 Sustain 0 (Instr 2)
; t 242.3675 Sustain 127 (Instr 1)
; t 242.3675 Sustain 127 (Instr 2)
; t 242.4263 Soft 127 (Instr 1)
; t 242.4263 Soft 127 (Instr 2)
    db 76,1,159,2,66,33,1,0,114,1,66,1  ; n905 t=242.448s dur=671ms, freq=370Hz, sample=66, buffer_id=01:42
    db 189,0,136,1,69,39,2,1,184,1,69,1  ; n906 t=242.779s dur=392ms, freq=440Hz, sample=69, buffer_id=01:45
    db 7,0,173,9,49,40,1,3,139,0,49,1  ; n907 t=242.969s dur=2477ms, freq=139Hz, sample=49, buffer_id=01:31
    db 160,0,165,9,37,41,1,6,69,0,37,1  ; n908 t=242.976s dur=2469ms, freq=69Hz, sample=37, buffer_id=01:25
; t 243.1194 Sustain 0 (Instr 1)
; t 243.1194 Sustain 0 (Instr 2)
    db 9,0,5,9,73,51,2,7,42,2,73,1  ; n909 t=243.137s dur=2309ms, freq=554Hz, sample=73, buffer_id=01:49
    db 164,1,252,8,61,39,1,9,21,1,61,1  ; n910 t=243.145s dur=2300ms, freq=277Hz, sample=61, buffer_id=01:3D
; t 243.5409 Sustain 127 (Instr 1)
; t 243.5409 Sustain 127 (Instr 2)
    db 128,1,88,7,65,33,1,0,93,1,65,1  ; n911 t=243.565s dur=1880ms, freq=349Hz, sample=65, buffer_id=01:41
    db 132,1,216,5,68,38,2,1,159,1,68,1  ; n912 t=243.950s dur=1496ms, freq=415Hz, sample=68, buffer_id=01:44
    db 128,1,84,4,61,33,1,9,21,1,61,1  ; n913 t=244.338s dur=1108ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 51,1,212,2,65,33,1,0,93,1,65,1  ; n914 t=244.722s dur=724ms, freq=349Hz, sample=65, buffer_id=01:41
    db 244,0,230,1,68,39,2,1,159,1,68,1  ; n915 t=245.029s dur=486ms, freq=415Hz, sample=68, buffer_id=01:44
; t 245.0705 Soft 0 (Instr 1)
; t 245.0705 Soft 0 (Instr 2)
    db 36,0,38,10,30,38,1,2,46,0,30,1  ; n916 t=245.273s dur=2598ms, freq=46Hz, sample=30, buffer_id=01:1E
    db 147,0,1,10,42,38,1,4,92,0,42,1  ; n917 t=245.309s dur=2561ms, freq=92Hz, sample=42, buffer_id=01:2A
; t 245.4459 Sustain 0 (Instr 1)
; t 245.4459 Sustain 0 (Instr 2)
    db 28,0,111,9,73,51,2,7,42,2,73,1  ; n918 t=245.456s dur=2415ms, freq=554Hz, sample=73, buffer_id=01:49
    db 171,1,83,9,61,36,1,9,21,1,61,1  ; n919 t=245.483s dur=2387ms, freq=277Hz, sample=61, buffer_id=01:3D
; t 245.7774 Sustain 127 (Instr 1)
; t 245.7774 Sustain 127 (Instr 2)
    db 135,1,168,7,66,33,1,0,114,1,66,1  ; n920 t=245.910s dur=1960ms, freq=370Hz, sample=66, buffer_id=01:42
    db 162,1,33,6,69,38,2,1,184,1,69,1  ; n921 t=246.301s dur=1569ms, freq=440Hz, sample=69, buffer_id=01:45
    db 128,1,127,4,61,33,1,9,21,1,61,1  ; n922 t=246.719s dur=1151ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 119,1,37,3,66,33,1,0,114,1,66,1  ; n923 t=247.103s dur=805ms, freq=370Hz, sample=66, buffer_id=01:42
    db 233,0,186,1,69,39,2,1,184,1,69,1  ; n924 t=247.478s dur=442ms, freq=440Hz, sample=69, buffer_id=01:45
    db 5,0,191,13,39,39,1,3,78,0,39,1  ; n925 t=247.712s dur=3519ms, freq=78Hz, sample=39, buffer_id=01:27
    db 137,0,185,13,51,39,1,5,156,0,51,1  ; n926 t=247.717s dur=3513ms, freq=156Hz, sample=51, buffer_id=01:33
    db 15,0,48,13,71,52,2,6,238,1,71,1  ; n927 t=247.854s dur=3376ms, freq=494Hz, sample=71, buffer_id=01:47
    db 206,1,33,13,59,37,1,8,247,0,59,1  ; n928 t=247.869s dur=3361ms, freq=247Hz, sample=59, buffer_id=01:3B
; t 247.8709 Sustain 0 (Instr 1)
; t 247.8709 Sustain 0 (Instr 2)
; t 248.2944 Sustain 127 (Instr 1)
; t 248.2944 Sustain 127 (Instr 2)
    db 91,1,84,11,66,33,1,0,114,1,66,1  ; n929 t=248.331s dur=2900ms, freq=370Hz, sample=66, buffer_id=01:42
    db 97,1,248,9,69,38,2,1,184,1,69,1  ; n930 t=248.678s dur=2552ms, freq=440Hz, sample=69, buffer_id=01:45
    db 125,1,151,8,59,33,1,8,247,0,59,1  ; n931 t=249.031s dur=2199ms, freq=247Hz, sample=59, buffer_id=01:3B
    db 90,1,27,7,66,33,1,0,114,1,66,1  ; n932 t=249.412s dur=1819ms, freq=370Hz, sample=66, buffer_id=01:42
    db 118,1,192,5,69,38,2,1,184,1,69,1  ; n933 t=249.758s dur=1472ms, freq=440Hz, sample=69, buffer_id=01:45
    db 87,1,74,4,59,33,1,8,247,0,59,1  ; n934 t=250.132s dur=1098ms, freq=247Hz, sample=59, buffer_id=01:3B
    db 101,1,50,3,66,33,1,0,114,1,66,1  ; n935 t=250.475s dur=818ms, freq=370Hz, sample=66, buffer_id=01:42
    db 4,1,212,1,69,38,2,1,184,1,69,1  ; n936 t=250.832s dur=468ms, freq=440Hz, sample=69, buffer_id=01:45
    db 31,0,117,5,40,38,1,2,82,0,40,1  ; n937 t=251.092s dur=1397ms, freq=82Hz, sample=40, buffer_id=01:28
    db 107,0,86,5,52,38,1,4,165,0,52,1  ; n938 t=251.123s dur=1366ms, freq=165Hz, sample=52, buffer_id=01:34
    db 3,0,236,4,59,36,1,8,247,0,59,1  ; n939 t=251.230s dur=1260ms, freq=247Hz, sample=59, buffer_id=01:3B
; t 251.2308 Sustain 0 (Instr 1)
; t 251.2308 Sustain 0 (Instr 2)
    db 180,1,232,4,71,52,2,6,238,1,71,1  ; n940 t=251.233s dur=1256ms, freq=494Hz, sample=71, buffer_id=01:47
; t 251.6177 Sustain 127 (Instr 1)
; t 251.6177 Sustain 127 (Instr 2)
    db 139,1,74,3,64,33,1,0,74,1,64,1  ; n941 t=251.669s dur=842ms, freq=330Hz, sample=64, buffer_id=01:40
    db 237,0,182,1,68,38,2,1,159,1,68,1  ; n942 t=252.064s dur=438ms, freq=415Hz, sample=68, buffer_id=01:44
    db 5,0,60,5,37,39,1,3,69,0,37,1  ; n943 t=252.302s dur=1340ms, freq=69Hz, sample=37, buffer_id=01:25
    db 140,0,54,5,49,39,1,5,139,0,49,1  ; n944 t=252.307s dur=1334ms, freq=139Hz, sample=49, buffer_id=01:31
    db 16,0,170,4,57,37,1,7,220,0,57,1  ; n945 t=252.447s dur=1194ms, freq=220Hz, sample=57, buffer_id=01:39
    db 143,1,154,4,69,52,2,9,184,1,69,1  ; n946 t=252.463s dur=1178ms, freq=440Hz, sample=69, buffer_id=01:45
; t 252.4898 Sustain 0 (Instr 1)
; t 252.4898 Sustain 0 (Instr 2)
    db 84,1,26,3,64,33,1,0,74,1,64,1  ; n947 t=252.862s dur=794ms, freq=330Hz, sample=64, buffer_id=01:40
; t 252.8820 Sustain 127 (Instr 1)
; t 252.8820 Sustain 127 (Instr 2)
    db 8,1,198,1,68,38,2,1,159,1,68,1  ; n948 t=253.202s dur=454ms, freq=415Hz, sample=68, buffer_id=01:44
    db 63,0,75,5,39,36,1,2,78,0,39,1  ; n949 t=253.465s dur=1355ms, freq=78Hz, sample=39, buffer_id=01:27
    db 87,0,12,5,51,36,1,4,156,0,51,1  ; n950 t=253.529s dur=1292ms, freq=156Hz, sample=51, buffer_id=01:33
    db 7,0,182,4,69,44,2,9,184,1,69,1  ; n951 t=253.615s dur=1206ms, freq=440Hz, sample=69, buffer_id=01:45
    db 135,1,174,4,57,34,1,7,220,0,57,1  ; n952 t=253.623s dur=1198ms, freq=220Hz, sample=57, buffer_id=01:39
; t 253.6418 Sustain 0 (Instr 1)
; t 253.6418 Sustain 0 (Instr 2)
    db 129,1,39,3,63,33,1,0,55,1,63,1  ; n953 t=254.014s dur=807ms, freq=311Hz, sample=63, buffer_id=01:3F
; t 254.0147 Sustain 127 (Instr 1)
; t 254.0147 Sustain 127 (Instr 2)
    db 17,1,218,1,66,33,1,1,114,1,66,1  ; n954 t=254.398s dur=474ms, freq=370Hz, sample=66, buffer_id=01:42
    db 37,0,113,5,36,36,1,3,65,0,36,1  ; n955 t=254.672s dur=1393ms, freq=65Hz, sample=36, buffer_id=01:24
    db 93,0,75,5,48,36,1,5,131,0,48,1  ; n956 t=254.709s dur=1355ms, freq=131Hz, sample=48, buffer_id=01:30
    db 4,0,238,4,56,35,1,6,208,0,56,1  ; n957 t=254.802s dur=1262ms, freq=208Hz, sample=56, buffer_id=01:38
    db 186,1,234,4,68,44,2,8,159,1,68,1  ; n958 t=254.806s dur=1258ms, freq=415Hz, sample=68, buffer_id=01:44
; t 254.8213 Sustain 0 (Instr 1)
; t 254.8213 Sustain 0 (Instr 2)
; t 255.1439 Sustain 127 (Instr 1)
; t 255.1439 Sustain 127 (Instr 2)
; t 255.2454 Soft 127 (Instr 1)
; t 255.2454 Soft 127 (Instr 2)
    db 147,1,48,3,63,33,1,0,55,1,63,1  ; n959 t=255.249s dur=816ms, freq=311Hz, sample=63, buffer_id=01:3F
    db 246,0,247,1,66,33,1,1,114,1,66,1  ; n960 t=255.651s dur=503ms, freq=370Hz, sample=66, buffer_id=01:42
    db 30,0,232,5,37,35,1,2,69,0,37,1  ; n961 t=255.897s dur=1512ms, freq=69Hz, sample=37, buffer_id=01:25
    db 126,0,202,5,49,35,1,4,139,0,49,1  ; n962 t=255.927s dur=1482ms, freq=139Hz, sample=49, buffer_id=01:31
    db 24,0,76,5,56,33,1,6,208,0,56,1  ; n963 t=256.053s dur=1356ms, freq=208Hz, sample=56, buffer_id=01:38
; t 256.0649 Sustain 0 (Instr 1)
; t 256.0649 Sustain 0 (Instr 2)
    db 184,1,53,5,68,44,2,8,159,1,68,1  ; n964 t=256.077s dur=1333ms, freq=415Hz, sample=68, buffer_id=01:44
; t 256.3971 Sustain 127 (Instr 1)
; t 256.3971 Sustain 127 (Instr 2)
    db 172,1,125,3,61,33,1,0,21,1,61,1  ; n965 t=256.517s dur=893ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 71,1,65,2,64,33,1,1,74,1,64,1  ; n966 t=256.945s dur=577ms, freq=330Hz, sample=64, buffer_id=01:40
    db 18,0,133,10,33,35,1,3,55,0,33,1  ; n967 t=257.272s dur=2693ms, freq=55Hz, sample=33, buffer_id=01:21
    db 120,0,115,10,45,35,1,5,110,0,45,1  ; n968 t=257.290s dur=2675ms, freq=110Hz, sample=45, buffer_id=01:2D
    db 42,0,251,9,54,33,1,7,185,0,54,1  ; n969 t=257.410s dur=2555ms, freq=185Hz, sample=54, buffer_id=01:36
; t 257.4098 Sustain 0 (Instr 1)
; t 257.4098 Sustain 0 (Instr 2)
    db 182,1,209,9,66,40,1,9,114,1,66,1  ; n970 t=257.452s dur=2513ms, freq=370Hz, sample=66, buffer_id=01:42
; t 257.7868 Sustain 127 (Instr 1)
; t 257.7868 Sustain 127 (Instr 2)
    db 153,1,28,8,61,33,1,0,21,1,61,1  ; n971 t=257.889s dur=2076ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 127,1,131,6,63,33,1,1,55,1,63,1  ; n972 t=258.298s dur=1667ms, freq=311Hz, sample=63, buffer_id=01:3F
    db 161,1,3,5,54,33,1,7,185,0,54,1  ; n973 t=258.682s dur=1283ms, freq=185Hz, sample=54, buffer_id=01:36
    db 171,1,171,3,61,33,1,0,21,1,61,1  ; n974 t=259.098s dur=939ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 24,1,0,2,63,33,1,1,55,1,63,1  ; n975 t=259.525s dur=512ms, freq=311Hz, sample=63, buffer_id=01:3F
    db 22,0,125,5,32,36,1,2,52,0,32,1  ; n976 t=259.805s dur=1405ms, freq=52Hz, sample=32, buffer_id=01:20
    db 131,0,102,5,44,36,1,4,104,0,44,1  ; n977 t=259.828s dur=1382ms, freq=104Hz, sample=44, buffer_id=01:2C
    db 7,0,227,4,68,44,2,6,159,1,68,1  ; n978 t=259.959s dur=1251ms, freq=415Hz, sample=68, buffer_id=01:44
; t 259.9654 Sustain 0 (Instr 1)
; t 259.9654 Sustain 0 (Instr 2)
    db 157,1,220,4,56,34,1,8,208,0,56,1  ; n979 t=259.966s dur=1244ms, freq=208Hz, sample=56, buffer_id=01:38
; t 260.2366 Sustain 127 (Instr 1)
; t 260.2366 Sustain 127 (Instr 2)
    db 154,1,62,3,61,33,1,0,21,1,61,1  ; n980 t=260.380s dur=830ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 28,1,211,1,63,34,1,1,55,1,63,1  ; n981 t=260.790s dur=467ms, freq=311Hz, sample=63, buffer_id=01:3F
    db 43,0,161,6,30,37,1,3,46,0,30,1  ; n982 t=261.074s dur=1697ms, freq=46Hz, sample=30, buffer_id=01:1E
    db 112,0,118,6,42,38,1,5,92,0,42,1  ; n983 t=261.117s dur=1654ms, freq=92Hz, sample=42, buffer_id=01:2A
; t 261.2105 Sustain 0 (Instr 1)
; t 261.2105 Sustain 0 (Instr 2)
    db 36,0,6,6,57,37,1,7,220,0,57,1  ; n984 t=261.229s dur=1542ms, freq=220Hz, sample=57, buffer_id=01:39
    db 4,2,226,5,69,45,2,9,184,1,69,1  ; n985 t=261.265s dur=1506ms, freq=440Hz, sample=69, buffer_id=01:45
; t 261.7507 Sustain 127 (Instr 1)
; t 261.7507 Sustain 127 (Instr 2)
    db 225,1,222,3,61,33,1,0,21,1,61,1  ; n986 t=261.781s dur=990ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 90,1,253,1,63,33,1,1,55,1,63,1  ; n987 t=262.262s dur=509ms, freq=311Hz, sample=63, buffer_id=01:3F
    db 44,0,119,11,32,36,1,2,52,0,32,1  ; n988 t=262.608s dur=2935ms, freq=52Hz, sample=32, buffer_id=01:20
    db 138,0,75,11,44,36,1,4,104,0,44,1  ; n989 t=262.652s dur=2891ms, freq=104Hz, sample=44, buffer_id=01:2C
; t 262.7712 Sustain 0 (Instr 1)
; t 262.7712 Sustain 0 (Instr 2)
    db 7,0,193,10,68,43,2,6,159,1,68,1  ; n990 t=262.789s dur=2753ms, freq=415Hz, sample=68, buffer_id=01:44
    db 4,2,186,10,56,34,1,8,208,0,56,1  ; n991 t=262.797s dur=2746ms, freq=208Hz, sample=56, buffer_id=01:38
; t 263.1950 Sustain 127 (Instr 1)
; t 263.1950 Sustain 127 (Instr 2)
    db 162,1,182,8,61,33,1,0,21,1,61,1  ; n992 t=263.312s dur=2230ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 185,1,20,7,64,33,1,1,74,1,64,1  ; n993 t=263.731s dur=1812ms, freq=330Hz, sample=64, buffer_id=01:40
    db 215,1,91,5,56,33,1,8,208,0,56,1  ; n994 t=264.172s dur=1371ms, freq=208Hz, sample=56, buffer_id=01:38
    db 129,1,132,3,61,33,1,0,21,1,61,1  ; n995 t=264.642s dur=900ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 88,1,3,2,64,33,1,1,74,1,64,1  ; n996 t=265.028s dur=515ms, freq=330Hz, sample=64, buffer_id=01:40
    db 44,0,101,11,32,36,1,2,52,0,32,1  ; n997 t=265.371s dur=2917ms, freq=52Hz, sample=32, buffer_id=01:20
    db 124,0,57,11,44,36,1,4,104,0,44,1  ; n998 t=265.415s dur=2873ms, freq=104Hz, sample=44, buffer_id=01:2C
    db 20,0,189,10,68,44,2,6,159,1,68,1  ; n999 t=265.539s dur=2749ms, freq=415Hz, sample=68, buffer_id=01:44
; t 265.5432 Sustain 0 (Instr 1)
; t 265.5432 Sustain 0 (Instr 2)
    db 173,1,169,10,54,35,1,3,185,0,54,1  ; n1000 t=265.559s dur=2729ms, freq=185Hz, sample=54, buffer_id=01:36
; t 265.8185 Sustain 127 (Instr 1)
; t 265.8185 Sustain 127 (Instr 2)
    db 156,1,252,8,60,33,1,0,6,1,60,1  ; n1001 t=265.988s dur=2300ms, freq=262Hz, sample=60, buffer_id=01:3C
    db 185,1,96,7,63,33,1,1,55,1,63,1  ; n1002 t=266.400s dur=1888ms, freq=311Hz, sample=63, buffer_id=01:3F
    db 234,1,167,5,54,33,1,3,185,0,54,1  ; n1003 t=266.841s dur=1447ms, freq=185Hz, sample=54, buffer_id=01:36
    db 230,1,190,3,60,33,1,0,6,1,60,1  ; n1004 t=267.331s dur=958ms, freq=262Hz, sample=60, buffer_id=01:3C
    db 83,1,216,1,63,33,1,1,55,1,63,1  ; n1005 t=267.816s dur=472ms, freq=311Hz, sample=63, buffer_id=01:3F
    db 11,0,171,20,37,36,1,5,69,0,37,1  ; n1006 t=268.155s dur=5291ms, freq=69Hz, sample=37, buffer_id=01:25
    db 127,0,209,14,44,36,1,4,104,0,44,1  ; n1007 t=268.166s dur=3793ms, freq=104Hz, sample=44, buffer_id=01:2C
; t 268.2888 Sustain 0 (Instr 1)
; t 268.2888 Sustain 0 (Instr 2)
    db 7,0,82,14,52,34,1,7,165,0,52,1  ; n1008 t=268.293s dur=3666ms, freq=165Hz, sample=52, buffer_id=01:34
    db 163,1,74,14,61,35,1,8,21,1,61,1  ; n1009 t=268.300s dur=3658ms, freq=277Hz, sample=61, buffer_id=01:3D
; t 268.6431 Sustain 127 (Instr 1)
; t 268.6431 Sustain 127 (Instr 2)
    db 170,1,167,12,56,33,1,0,208,0,56,1  ; n1010 t=268.720s dur=3239ms, freq=208Hz, sample=56, buffer_id=01:38
    db 106,1,253,10,61,33,1,8,21,1,61,1  ; n1011 t=269.146s dur=2813ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 165,1,148,9,56,33,1,0,208,0,56,1  ; n1012 t=269.507s dur=2452ms, freq=208Hz, sample=56, buffer_id=01:38
    db 139,1,238,7,61,33,1,8,21,1,61,1  ; n1013 t=269.928s dur=2030ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 171,1,100,6,64,33,1,1,74,1,64,1  ; n1014 t=270.323s dur=1636ms, freq=330Hz, sample=64, buffer_id=01:40
    db 131,1,185,4,56,33,1,0,208,0,56,1  ; n1015 t=270.750s dur=1209ms, freq=208Hz, sample=56, buffer_id=01:38
    db 135,1,54,3,61,33,1,8,21,1,61,1  ; n1016 t=271.137s dur=822ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 86,1,126,7,64,33,1,1,74,1,64,1  ; n1017 t=271.528s dur=1918ms, freq=330Hz, sample=64, buffer_id=01:40
    db 177,0,40,6,44,44,1,4,104,0,44,1  ; n1018 t=271.871s dur=1576ms, freq=104Hz, sample=44, buffer_id=01:2C
; t 271.9593 Sustain 0 (Instr 1)
; t 271.9593 Sustain 0 (Instr 2)
    db 147,1,119,5,56,33,1,0,208,0,56,1  ; n1019 t=272.048s dur=1399ms, freq=208Hz, sample=56, buffer_id=01:38
; t 272.3134 Sustain 127 (Instr 1)
; t 272.3134 Sustain 127 (Instr 2)
    db 139,1,227,3,61,35,1,2,21,1,61,1  ; n1020 t=272.451s dur=995ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 21,1,89,2,64,34,1,1,74,1,64,1  ; n1021 t=272.846s dur=601ms, freq=330Hz, sample=64, buffer_id=01:40
    db 221,0,68,1,44,39,1,4,104,0,44,1  ; n1022 t=273.123s dur=324ms, freq=104Hz, sample=44, buffer_id=01:2C
; t 273.2379 Soft 0 (Instr 1)
; t 273.2379 Soft 0 (Instr 2)
    db 92,0,24,20,36,35,1,3,65,0,36,1  ; n1023 t=273.344s dur=5144ms, freq=65Hz, sample=36, buffer_id=01:24
    db 64,0,50,14,44,41,1,4,104,0,44,1  ; n1024 t=273.435s dur=3634ms, freq=104Hz, sample=44, buffer_id=01:2C
; t 273.4469 Sustain 0 (Instr 1)
; t 273.4469 Sustain 0 (Instr 2)
    db 129,1,111,3,56,40,1,0,208,0,56,1  ; n1025 t=273.499s dur=879ms, freq=208Hz, sample=56, buffer_id=01:38
    db 147,1,187,1,63,33,1,1,55,1,63,1  ; n1026 t=273.884s dur=443ms, freq=311Hz, sample=63, buffer_id=01:3F
    db 153,1,222,10,66,33,1,2,114,1,66,1  ; n1027 t=274.287s dur=2782ms, freq=370Hz, sample=66, buffer_id=01:42
; t 274.3820 Sustain 127 (Instr 1)
; t 274.3820 Sustain 127 (Instr 2)
    db 147,1,69,9,56,33,1,0,208,0,56,1  ; n1028 t=274.697s dur=2373ms, freq=208Hz, sample=56, buffer_id=01:38
    db 139,1,178,7,63,33,1,1,55,1,63,1  ; n1029 t=275.099s dur=1970ms, freq=311Hz, sample=63, buffer_id=01:3F
    db 137,1,39,6,66,33,1,2,114,1,66,1  ; n1030 t=275.494s dur=1575ms, freq=370Hz, sample=66, buffer_id=01:42
    db 124,1,158,4,56,33,1,0,208,0,56,1  ; n1031 t=275.887s dur=1182ms, freq=208Hz, sample=56, buffer_id=01:38
    db 133,1,34,3,63,33,1,1,55,1,63,1  ; n1032 t=276.267s dur=802ms, freq=311Hz, sample=63, buffer_id=01:3F
    db 134,1,157,1,66,33,1,2,114,1,66,1  ; n1033 t=276.656s dur=413ms, freq=370Hz, sample=66, buffer_id=01:42
    db 98,0,162,5,44,44,1,4,104,0,44,1  ; n1034 t=277.046s dur=1442ms, freq=104Hz, sample=44, buffer_id=01:2C
; t 277.0696 Sustain 0 (Instr 1)
; t 277.0696 Sustain 0 (Instr 2)
    db 136,1,63,5,56,33,1,0,208,0,56,1  ; n1035 t=277.144s dur=1343ms, freq=208Hz, sample=56, buffer_id=01:38
; t 277.5045 Sustain 127 (Instr 1)
; t 277.5045 Sustain 127 (Instr 2)
    db 161,1,183,3,63,33,1,1,55,1,63,1  ; n1036 t=277.536s dur=951ms, freq=311Hz, sample=63, buffer_id=01:3F
    db 14,1,23,2,66,33,1,2,114,1,66,1  ; n1037 t=277.953s dur=535ms, freq=370Hz, sample=66, buffer_id=01:42
; t 278.0917 Soft 0 (Instr 1)
; t 278.0917 Soft 0 (Instr 2)
    db 182,0,9,1,44,41,1,4,104,0,44,1  ; n1038 t=278.223s dur=265ms, freq=104Hz, sample=44, buffer_id=01:2C
    db 39,0,203,16,37,34,1,5,69,0,37,1  ; n1039 t=278.405s dur=4299ms, freq=69Hz, sample=37, buffer_id=01:25
    db 44,0,239,11,56,35,1,0,208,0,56,1  ; n1040 t=278.445s dur=3055ms, freq=208Hz, sample=56, buffer_id=01:38
    db 132,1,195,11,44,40,1,4,104,0,44,1  ; n1041 t=278.488s dur=3011ms, freq=104Hz, sample=44, buffer_id=01:2C
; t 278.4882 Sustain 0 (Instr 1)
; t 278.4882 Sustain 0 (Instr 2)
; t 278.8698 Sustain 127 (Instr 1)
; t 278.8698 Sustain 127 (Instr 2)
    db 101,1,63,10,64,33,1,1,74,1,64,1  ; n1042 t=278.876s dur=2623ms, freq=330Hz, sample=64, buffer_id=01:40
    db 64,1,218,8,61,37,1,2,21,1,61,1  ; n1043 t=279.233s dur=2266ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 53,1,154,7,68,43,2,3,159,1,68,1  ; n1044 t=279.553s dur=1946ms, freq=415Hz, sample=68, buffer_id=01:44
    db 127,1,101,6,64,37,1,1,74,1,64,1  ; n1045 t=279.862s dur=1637ms, freq=330Hz, sample=64, buffer_id=01:40
    db 52,1,230,4,73,40,2,6,42,2,73,1  ; n1046 t=280.245s dur=1254ms, freq=554Hz, sample=73, buffer_id=01:49
    db 75,1,179,3,68,44,2,3,159,1,68,1  ; n1047 t=280.553s dur=947ms, freq=415Hz, sample=68, buffer_id=01:44
    db 61,1,103,2,76,41,2,7,147,2,76,1  ; n1048 t=280.884s dur=615ms, freq=659Hz, sample=76, buffer_id=01:4C
    db 21,1,238,1,73,42,2,6,42,2,73,1  ; n1049 t=281.201s dur=494ms, freq=554Hz, sample=73, buffer_id=01:49
    db 208,0,202,4,44,44,1,4,104,0,44,1  ; n1050 t=281.478s dur=1226ms, freq=104Hz, sample=44, buffer_id=01:2C
; t 281.4996 Sustain 0 (Instr 1)
; t 281.4996 Sustain 0 (Instr 2)
    db 89,1,250,3,80,41,2,8,63,3,80,1  ; n1051 t=281.686s dur=1018ms, freq=831Hz, sample=80, buffer_id=01:50
; t 282.0110 Sustain 127 (Instr 1)
; t 282.0110 Sustain 127 (Instr 2)
    db 41,1,161,2,76,38,2,0,147,2,76,1  ; n1052 t=282.031s dur=673ms, freq=659Hz, sample=76, buffer_id=01:4C
    db 153,0,149,1,73,38,2,1,42,2,73,1  ; n1053 t=282.329s dur=405ms, freq=554Hz, sample=73, buffer_id=01:49
    db 158,0,222,0,44,47,1,4,104,0,44,1  ; n1054 t=282.482s dur=222ms, freq=104Hz, sample=44, buffer_id=01:2C
    db 37,0,7,17,32,35,1,2,52,0,32,1  ; n1055 t=282.640s dur=4359ms, freq=52Hz, sample=32, buffer_id=01:20
    db 48,0,173,11,44,42,1,4,104,0,44,1  ; n1056 t=282.677s dur=2989ms, freq=104Hz, sample=44, buffer_id=01:2C
; t 282.7046 Sustain 0 (Instr 1)
; t 282.7046 Sustain 0 (Instr 2)
    db 63,1,65,1,72,43,2,3,11,2,72,1  ; n1057 t=282.725s dur=321ms, freq=523Hz, sample=72, buffer_id=01:48
    db 51,1,123,2,75,40,2,0,110,2,75,1  ; n1058 t=283.043s dur=635ms, freq=622Hz, sample=75, buffer_id=01:4B
; t 283.2959 Sustain 127 (Instr 1)
; t 283.2959 Sustain 127 (Instr 2)
    db 79,1,176,1,69,38,2,1,184,1,69,1  ; n1059 t=283.350s dur=432ms, freq=440Hz, sample=69, buffer_id=01:45
; t 283.6794 Sustain 0 (Instr 1)
; t 283.6794 Sustain 0 (Instr 2)
    db 45,1,68,3,72,38,2,3,11,2,72,1  ; n1060 t=283.685s dur=836ms, freq=523Hz, sample=72, buffer_id=01:48
; t 283.8626 Sustain 127 (Instr 1)
; t 283.8626 Sustain 127 (Instr 2)
    db 51,1,22,2,66,34,1,0,114,1,66,1  ; n1061 t=283.986s dur=534ms, freq=370Hz, sample=66, buffer_id=01:42
    db 91,1,166,1,69,38,2,1,184,1,69,1  ; n1062 t=284.293s dur=422ms, freq=440Hz, sample=69, buffer_id=01:45
; t 284.5208 Sustain 0 (Instr 1)
; t 284.5208 Sustain 0 (Instr 2)
    db 67,1,2,4,63,33,1,5,55,1,63,1  ; n1063 t=284.640s dur=1026ms, freq=311Hz, sample=63, buffer_id=01:3F
; t 284.7328 Sustain 127 (Instr 1)
; t 284.7328 Sustain 127 (Instr 2)
    db 115,1,191,2,66,34,1,0,114,1,66,1  ; n1064 t=284.963s dur=703ms, freq=370Hz, sample=66, buffer_id=01:42
    db 104,1,101,3,57,36,1,1,220,0,57,1  ; n1065 t=285.333s dur=869ms, freq=220Hz, sample=57, buffer_id=01:39
; t 285.6667 Sustain 0 (Instr 1)
; t 285.6667 Sustain 0 (Instr 2)
    db 119,0,25,5,44,40,1,4,104,0,44,1  ; n1066 t=285.693s dur=1305ms, freq=104Hz, sample=44, buffer_id=01:2C
    db 133,1,162,4,60,38,1,3,6,1,60,1  ; n1067 t=285.813s dur=1186ms, freq=262Hz, sample=60, buffer_id=01:3C
    db 109,1,29,3,56,36,1,0,208,0,56,1  ; n1068 t=286.201s dur=797ms, freq=208Hz, sample=56, buffer_id=01:38
; t 286.2972 Sustain 127 (Instr 1)
; t 286.2972 Sustain 127 (Instr 2)
    db 244,0,176,1,54,33,1,1,185,0,54,1  ; n1069 t=286.567s dur=432ms, freq=185Hz, sample=54, buffer_id=01:36
    db 202,0,188,0,44,37,1,4,104,0,44,1  ; n1070 t=286.810s dur=188ms, freq=104Hz, sample=44, buffer_id=01:2C
; t 286.9990 Sustain 0 (Instr 1)
; t 286.9990 Sustain 0 (Instr 2)
    db 1,0,92,1,52,34,1,5,165,0,52,1  ; n1071 t=287.013s dur=348ms, freq=165Hz, sample=52, buffer_id=01:34
    db 5,0,208,11,44,34,1,4,104,0,44,1  ; n1072 t=287.014s dur=3024ms, freq=104Hz, sample=44, buffer_id=01:2C
    db 1,0,203,11,61,34,1,6,21,1,61,1  ; n1073 t=287.019s dur=3019ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 125,1,195,16,37,34,1,7,69,0,37,1  ; n1074 t=287.020s dur=4291ms, freq=69Hz, sample=37, buffer_id=01:25
; t 287.1747 Soft 127 (Instr 1)
; t 287.1747 Soft 127 (Instr 2)
    db 108,1,77,10,64,33,1,0,74,1,64,1  ; n1075 t=287.401s dur=2637ms, freq=330Hz, sample=64, buffer_id=01:40
; t 287.4196 Sustain 127 (Instr 1)
; t 287.4196 Sustain 127 (Instr 2)
    db 44,1,224,8,61,35,1,6,21,1,61,1  ; n1076 t=287.766s dur=2272ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 59,1,180,7,68,43,2,1,159,1,68,1  ; n1077 t=288.066s dur=1972ms, freq=415Hz, sample=68, buffer_id=01:44
    db 63,1,121,6,64,37,1,0,74,1,64,1  ; n1078 t=288.381s dur=1657ms, freq=330Hz, sample=64, buffer_id=01:40
    db 64,1,58,5,73,39,2,2,42,2,73,1  ; n1079 t=288.700s dur=1338ms, freq=554Hz, sample=73, buffer_id=01:49
    db 83,1,249,3,68,38,2,1,159,1,68,1  ; n1080 t=289.021s dur=1017ms, freq=415Hz, sample=68, buffer_id=01:44
    db 57,1,167,2,76,38,2,3,147,2,76,1  ; n1081 t=289.359s dur=679ms, freq=659Hz, sample=76, buffer_id=01:4C
    db 42,1,198,1,73,40,2,2,42,2,73,1  ; n1082 t=289.672s dur=454ms, freq=554Hz, sample=73, buffer_id=01:49
    db 122,0,61,5,44,41,1,4,104,0,44,1  ; n1083 t=289.970s dur=1341ms, freq=104Hz, sample=44, buffer_id=01:2C
; t 290.0385 Sustain 0 (Instr 1)
; t 290.0385 Sustain 0 (Instr 2)
    db 155,1,194,4,80,45,2,5,63,3,80,1  ; n1084 t=290.093s dur=1218ms, freq=831Hz, sample=80, buffer_id=01:50
; t 290.4377 Sustain 127 (Instr 1)
; t 290.4377 Sustain 127 (Instr 2)
    db 123,1,39,3,76,40,2,0,147,2,76,1  ; n1085 t=290.504s dur=807ms, freq=659Hz, sample=76, buffer_id=01:4C
    db 160,0,217,1,73,38,2,1,42,2,73,1  ; n1086 t=290.883s dur=473ms, freq=554Hz, sample=73, buffer_id=01:49
    db 240,0,13,1,44,36,1,4,104,0,44,1  ; n1087 t=291.042s dur=269ms, freq=104Hz, sample=44, buffer_id=01:2C
    db 14,0,43,12,44,35,1,4,104,0,44,1  ; n1088 t=291.282s dur=3115ms, freq=104Hz, sample=44, buffer_id=01:2C
    db 20,0,202,17,32,35,1,2,52,0,32,1  ; n1089 t=291.296s dur=4554ms, freq=52Hz, sample=32, buffer_id=01:20
; t 291.3117 Sustain 0 (Instr 1)
; t 291.3117 Sustain 0 (Instr 2)
    db 90,1,229,6,72,41,2,3,11,2,72,1  ; n1090 t=291.316s dur=1765ms, freq=523Hz, sample=72, buffer_id=01:48
; t 291.6257 Sustain 127 (Instr 1)
; t 291.6257 Sustain 127 (Instr 2)
    db 70,1,139,5,75,38,2,0,110,2,75,1  ; n1091 t=291.662s dur=1419ms, freq=622Hz, sample=75, buffer_id=01:4B
    db 64,1,69,4,69,38,2,1,184,1,69,1  ; n1092 t=291.988s dur=1093ms, freq=440Hz, sample=69, buffer_id=01:45
    db 83,1,5,3,72,38,2,3,11,2,72,1  ; n1093 t=292.308s dur=773ms, freq=523Hz, sample=72, buffer_id=01:48
    db 62,1,178,1,66,33,1,5,114,1,66,1  ; n1094 t=292.647s dur=434ms, freq=370Hz, sample=66, buffer_id=01:42
    db 93,1,152,5,69,38,2,1,184,1,69,1  ; n1095 t=292.965s dur=1432ms, freq=440Hz, sample=69, buffer_id=01:45
; t 293.0814 Sustain 0 (Instr 1)
; t 293.0814 Sustain 0 (Instr 2)
    db 89,1,59,4,63,33,1,0,55,1,63,1  ; n1096 t=293.314s dur=1083ms, freq=311Hz, sample=63, buffer_id=01:3F
; t 293.3144 Sustain 127 (Instr 1)
; t 293.3144 Sustain 127 (Instr 2)
    db 88,1,226,2,66,33,1,3,114,1,66,1  ; n1097 t=293.659s dur=738ms, freq=370Hz, sample=66, buffer_id=01:42
    db 121,1,165,3,57,33,1,5,220,0,57,1  ; n1098 t=294.003s dur=933ms, freq=220Hz, sample=57, buffer_id=01:39
    db 142,0,190,5,44,37,1,4,104,0,44,1  ; n1099 t=294.380s dur=1470ms, freq=104Hz, sample=44, buffer_id=01:2C
; t 294.3977 Sustain 0 (Instr 1)
; t 294.3977 Sustain 0 (Instr 2)
    db 172,1,49,5,60,41,1,6,6,1,60,1  ; n1100 t=294.521s dur=1329ms, freq=262Hz, sample=60, buffer_id=01:3C
    db 111,1,133,3,56,33,1,0,208,0,56,1  ; n1101 t=294.949s dur=901ms, freq=208Hz, sample=56, buffer_id=01:38
; t 295.1947 Sustain 127 (Instr 1)
; t 295.1947 Sustain 127 (Instr 2)
    db 77,1,22,2,54,33,1,1,185,0,54,1  ; n1102 t=295.316s dur=534ms, freq=185Hz, sample=54, buffer_id=01:36
; t 295.3628 Soft 127 (Instr 1)
; t 295.3628 Soft 127 (Instr 2)
    db 121,0,201,0,44,33,1,4,104,0,44,1  ; n1103 t=295.649s dur=201ms, freq=104Hz, sample=44, buffer_id=01:2C
    db 48,0,204,30,37,34,1,3,69,0,37,1  ; n1104 t=295.770s dur=7884ms, freq=69Hz, sample=37, buffer_id=01:25
    db 61,0,156,30,44,35,1,4,104,0,44,1  ; n1105 t=295.818s dur=7836ms, freq=104Hz, sample=44, buffer_id=01:2C
; t 295.8501 Sustain 0 (Instr 1)
; t 295.8501 Sustain 0 (Instr 2)
    db 8,0,95,30,52,36,1,5,165,0,52,1  ; n1106 t=295.879s dur=7775ms, freq=165Hz, sample=52, buffer_id=01:34
    db 101,1,87,30,61,36,1,7,21,1,61,1  ; n1107 t=295.887s dur=7767ms, freq=277Hz, sample=61, buffer_id=01:3D
; t 296.1883 Sustain 127 (Instr 1)
; t 296.1883 Sustain 127 (Instr 2)
    db 107,1,241,28,56,33,1,0,208,0,56,1  ; n1108 t=296.245s dur=7409ms, freq=208Hz, sample=56, buffer_id=01:38
    db 80,1,135,27,61,33,1,7,21,1,61,1  ; n1109 t=296.607s dur=7047ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 99,1,54,26,64,33,1,1,74,1,64,1  ; n1110 t=296.943s dur=6710ms, freq=330Hz, sample=64, buffer_id=01:40
    db 58,1,211,24,61,33,1,7,21,1,61,1  ; n1111 t=297.299s dur=6355ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 76,1,153,23,56,33,1,0,208,0,56,1  ; n1112 t=297.613s dur=6041ms, freq=208Hz, sample=56, buffer_id=01:38
    db 110,1,78,22,49,33,1,2,139,0,49,1  ; n1113 t=297.944s dur=5710ms, freq=139Hz, sample=49, buffer_id=01:31
    db 67,1,224,20,52,33,1,5,165,0,52,1  ; n1114 t=298.310s dur=5344ms, freq=165Hz, sample=52, buffer_id=01:34
    db 59,1,156,19,56,33,1,0,208,0,56,1  ; n1115 t=298.634s dur=5020ms, freq=208Hz, sample=56, buffer_id=01:38
    db 92,1,97,18,61,33,1,7,21,1,61,1  ; n1116 t=298.949s dur=4705ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 102,1,6,17,56,33,1,0,208,0,56,1  ; n1117 t=299.296s dur=4358ms, freq=208Hz, sample=56, buffer_id=01:38
    db 26,1,159,15,52,33,1,5,165,0,52,1  ; n1118 t=299.655s dur=3999ms, freq=165Hz, sample=52, buffer_id=01:34
    db 96,1,134,14,44,37,1,4,104,0,44,1  ; n1119 t=299.936s dur=3718ms, freq=104Hz, sample=44, buffer_id=01:2C
    db 155,1,37,13,49,33,1,2,139,0,49,1  ; n1120 t=300.288s dur=3365ms, freq=139Hz, sample=49, buffer_id=01:31
    db 121,1,138,11,52,33,1,5,165,0,52,1  ; n1121 t=300.700s dur=2954ms, freq=165Hz, sample=52, buffer_id=01:34
    db 97,1,17,10,56,33,1,0,208,0,56,1  ; n1122 t=301.077s dur=2577ms, freq=208Hz, sample=56, buffer_id=01:38
    db 128,1,176,8,52,33,1,5,165,0,52,1  ; n1123 t=301.430s dur=2224ms, freq=165Hz, sample=52, buffer_id=01:34
    db 164,1,48,7,49,33,1,2,139,0,49,1  ; n1124 t=301.814s dur=1840ms, freq=139Hz, sample=49, buffer_id=01:31
    db 254,1,140,5,44,33,1,4,104,0,44,1  ; n1125 t=302.234s dur=1420ms, freq=104Hz, sample=44, buffer_id=01:2C
    db 232,1,142,3,49,33,1,2,139,0,49,1  ; n1126 t=302.744s dur=910ms, freq=139Hz, sample=49, buffer_id=01:31
    db 5,2,105,2,44,33,1,4,104,0,44,1  ; n1127 t=303.233s dur=617ms, freq=104Hz, sample=44, buffer_id=01:2C
; t 303.6544 Sustain 0 (Instr 1)
; t 303.6544 Sustain 0 (Instr 2)
    db 51,2,143,2,40,36,1,6,82,0,40,1  ; n1128 t=303.749s dur=655ms, freq=82Hz, sample=40, buffer_id=01:28
; t 303.8850 Sustain 127 (Instr 1)
; t 303.8850 Sustain 127 (Instr 2)
    db 189,2,235,2,44,33,1,0,104,0,44,1  ; n1129 t=304.312s dur=747ms, freq=104Hz, sample=44, buffer_id=01:2C
; t 304.3442 Sustain 0 (Instr 1)
; t 304.3442 Sustain 0 (Instr 2)
; t 304.6566 Sustain 127 (Instr 1)
; t 304.6566 Sustain 127 (Instr 2)
    db 100,3,158,3,40,33,1,1,82,0,40,1  ; n1130 t=305.014s dur=926ms, freq=82Hz, sample=40, buffer_id=01:28
; t 305.0403 Sustain 0 (Instr 1)
; t 305.0403 Sustain 0 (Instr 2)
; t 305.2614 Sustain 127 (Instr 1)
; t 305.2614 Sustain 127 (Instr 2)
    db 98,10,75,62,37,33,1,0,69,0,37,1  ; n1131 t=305.882s dur=15947ms, freq=69Hz, sample=37, buffer_id=01:25
; t 305.8884 Sustain 0 (Instr 1)
; t 305.8884 Sustain 0 (Instr 2)
; t 306.7504 Sustain 127 (Instr 1)
; t 306.7504 Sustain 127 (Instr 2)
    db 5,0,234,51,37,35,1,0,69,0,37,1  ; n1132 t=308.540s dur=13290ms, freq=69Hz, sample=37, buffer_id=01:25
    db 6,0,229,51,61,36,1,1,21,1,61,1  ; n1133 t=308.545s dur=13285ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 0,0,222,51,49,36,1,2,139,0,49,1  ; n1134 t=308.551s dur=13278ms, freq=139Hz, sample=49, buffer_id=01:31
    db 5,0,222,51,56,36,1,3,208,0,56,1  ; n1135 t=308.551s dur=13278ms, freq=208Hz, sample=56, buffer_id=01:38
    db 0,0,217,51,44,36,1,4,104,0,44,1  ; n1136 t=308.557s dur=13273ms, freq=104Hz, sample=44, buffer_id=01:2C
    db 123,12,217,51,52,36,1,5,165,0,52,1  ; n1137 t=308.557s dur=13273ms, freq=165Hz, sample=52, buffer_id=01:34
    db 5,0,94,39,37,35,1,0,69,0,37,1  ; n1138 t=311.752s dur=10078ms, freq=69Hz, sample=37, buffer_id=01:25
    db 12,0,88,39,44,35,1,4,104,0,44,1  ; n1139 t=311.757s dur=10072ms, freq=104Hz, sample=44, buffer_id=01:2C
    db 0,0,77,39,49,35,1,2,139,0,49,1  ; n1140 t=311.769s dur=10061ms, freq=139Hz, sample=49, buffer_id=01:31
    db 1,0,77,39,61,35,1,1,21,1,61,1  ; n1141 t=311.769s dur=10061ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 0,0,76,39,52,35,1,5,165,0,52,1  ; n1142 t=311.770s dur=10060ms, freq=165Hz, sample=52, buffer_id=01:34
    db 165,48,76,39,56,35,1,3,208,0,56,1  ; n1143 t=311.770s dur=10060ms, freq=208Hz, sample=56, buffer_id=01:38
; t 321.8300 Sustain 0 (Instr 1)
; t 321.8300 Sustain 0 (Instr 2)
    db 6,0,122,1,65,34,1,0,93,1,65,1  ; n1144 t=324.223s dur=378ms, freq=349Hz, sample=65, buffer_id=01:41
    db 11,0,177,0,68,39,2,1,159,1,68,1  ; n1145 t=324.229s dur=177ms, freq=415Hz, sample=68, buffer_id=01:44
    db 22,1,10,1,73,39,2,2,42,2,73,1  ; n1146 t=324.240s dur=266ms, freq=554Hz, sample=73, buffer_id=01:49
; t 324.2517 Soft 0 (Instr 1)
; t 324.2517 Soft 0 (Instr 2)
    db 5,0,228,1,68,43,2,1,159,1,68,1  ; n1147 t=324.518s dur=484ms, freq=415Hz, sample=68, buffer_id=01:44
    db 8,0,247,1,72,43,2,3,11,2,72,1  ; n1148 t=324.523s dur=503ms, freq=523Hz, sample=72, buffer_id=01:48
    db 209,1,246,1,63,38,1,4,55,1,63,1  ; n1149 t=324.532s dur=502ms, freq=311Hz, sample=63, buffer_id=01:3F
; t 324.8680 Soft 127 (Instr 1)
; t 324.8680 Soft 127 (Instr 2)
    db 17,0,69,1,61,33,1,0,21,1,61,1  ; n1150 t=324.996s dur=325ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 5,0,251,0,67,38,2,2,136,1,67,1  ; n1151 t=325.013s dur=251ms, freq=392Hz, sample=67, buffer_id=01:43
    db 244,0,34,1,70,38,2,5,210,1,70,1  ; n1152 t=325.019s dur=290ms, freq=466Hz, sample=70, buffer_id=01:46
    db 15,0,128,0,68,41,2,1,159,1,68,1  ; n1153 t=325.263s dur=128ms, freq=415Hz, sample=68, buffer_id=01:44
    db 22,0,120,0,60,36,1,3,6,1,60,1  ; n1154 t=325.277s dur=120ms, freq=262Hz, sample=60, buffer_id=01:3C
    db 204,1,108,0,75,42,2,4,110,2,75,1  ; n1155 t=325.300s dur=108ms, freq=622Hz, sample=75, buffer_id=01:4B
    db 23,0,109,0,49,34,1,0,139,0,49,1  ; n1156 t=325.760s dur=109ms, freq=139Hz, sample=49, buffer_id=01:31
    db 7,0,95,0,65,34,1,1,93,1,65,1  ; n1157 t=325.783s dur=95ms, freq=349Hz, sample=65, buffer_id=01:41
    db 11,0,82,0,58,34,1,2,233,0,58,1  ; n1158 t=325.791s dur=82ms, freq=233Hz, sample=58, buffer_id=01:3A
    db 225,0,107,0,73,40,2,3,42,2,73,1  ; n1159 t=325.801s dur=107ms, freq=554Hz, sample=73, buffer_id=01:49
    db 26,0,127,0,68,43,2,4,159,1,68,1  ; n1160 t=326.026s dur=127ms, freq=415Hz, sample=68, buffer_id=01:44
    db 12,0,95,0,51,38,1,5,156,0,51,1  ; n1161 t=326.053s dur=95ms, freq=156Hz, sample=51, buffer_id=01:33
    db 4,0,95,0,63,38,1,6,55,1,63,1  ; n1162 t=326.064s dur=95ms, freq=311Hz, sample=63, buffer_id=01:3F
    db 204,1,64,0,72,43,2,7,11,2,72,1  ; n1163 t=326.069s dur=64ms, freq=523Hz, sample=72, buffer_id=01:48
    db 1,0,113,0,70,38,2,0,210,1,70,1  ; n1164 t=326.529s dur=113ms, freq=466Hz, sample=70, buffer_id=01:46
    db 0,0,101,0,51,35,1,1,156,0,51,1  ; n1165 t=326.530s dur=101ms, freq=156Hz, sample=51, buffer_id=01:33
    db 14,0,126,0,67,38,2,2,136,1,67,1  ; n1166 t=326.530s dur=126ms, freq=392Hz, sample=67, buffer_id=01:43
    db 235,0,118,0,61,35,1,3,21,1,61,1  ; n1167 t=326.544s dur=118ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 14,0,165,0,56,34,1,4,208,0,56,1  ; n1168 t=326.779s dur=165ms, freq=208Hz, sample=56, buffer_id=01:38
    db 3,0,138,0,60,34,1,5,6,1,60,1  ; n1169 t=326.793s dur=138ms, freq=262Hz, sample=60, buffer_id=01:3C
    db 238,1,123,0,68,38,2,6,159,1,68,1  ; n1170 t=326.796s dur=123ms, freq=415Hz, sample=68, buffer_id=01:44
; t 326.8576 Soft 0 (Instr 1)
; t 326.8576 Soft 0 (Instr 2)
; t 327.2668 Sustain 127 (Instr 1)
; t 327.2668 Sustain 127 (Instr 2)
    db 0,0,70,1,73,40,2,0,42,2,73,1  ; n1171 t=327.290s dur=326ms, freq=554Hz, sample=73, buffer_id=01:49
    db 12,0,70,1,70,40,2,1,210,1,70,1  ; n1172 t=327.290s dur=326ms, freq=466Hz, sample=70, buffer_id=01:46
    db 2,1,58,1,78,40,2,2,228,2,78,1  ; n1173 t=327.302s dur=314ms, freq=740Hz, sample=78, buffer_id=01:4E
    db 31,0,13,2,68,43,2,3,159,1,68,1  ; n1174 t=327.560s dur=525ms, freq=415Hz, sample=68, buffer_id=01:44
    db 0,0,239,1,73,44,2,0,42,2,73,1  ; n1175 t=327.590s dur=495ms, freq=554Hz, sample=73, buffer_id=01:49
    db 194,1,251,1,77,44,2,4,186,2,77,1  ; n1176 t=327.590s dur=507ms, freq=698Hz, sample=77, buffer_id=01:4D
; t 327.6167 Sustain 0 (Instr 1)
; t 327.6167 Sustain 0 (Instr 2)
    db 17,0,52,1,66,33,1,1,114,1,66,1  ; n1177 t=328.040s dur=308ms, freq=370Hz, sample=66, buffer_id=01:42
    db 13,0,84,1,75,38,2,2,110,2,75,1  ; n1178 t=328.057s dur=340ms, freq=622Hz, sample=75, buffer_id=01:4B
    db 14,1,204,0,72,38,2,5,11,2,72,1  ; n1179 t=328.069s dur=204ms, freq=523Hz, sample=72, buffer_id=01:48
; t 328.2179 Soft 127 (Instr 1)
; t 328.2179 Soft 127 (Instr 2)
    db 7,0,82,0,73,42,2,0,42,2,73,1  ; n1180 t=328.340s dur=82ms, freq=554Hz, sample=73, buffer_id=01:49
    db 4,0,94,0,65,36,1,3,93,1,65,1  ; n1181 t=328.347s dur=94ms, freq=349Hz, sample=65, buffer_id=01:41
    db 221,1,89,0,80,42,2,4,63,3,80,1  ; n1182 t=328.351s dur=89ms, freq=831Hz, sample=80, buffer_id=01:50
    db 18,0,134,0,54,34,1,0,185,0,54,1  ; n1183 t=328.829s dur=134ms, freq=185Hz, sample=54, buffer_id=01:36
    db 2,0,177,0,78,40,2,1,228,2,78,1  ; n1184 t=328.847s dur=177ms, freq=740Hz, sample=78, buffer_id=01:4E
    db 3,0,81,0,63,34,1,2,55,1,63,1  ; n1185 t=328.849s dur=81ms, freq=311Hz, sample=63, buffer_id=01:3F
    db 8,1,147,0,70,40,2,3,210,1,70,1  ; n1186 t=328.852s dur=147ms, freq=466Hz, sample=70, buffer_id=01:46
    db 2,0,129,0,68,43,2,4,159,1,68,1  ; n1187 t=329.116s dur=129ms, freq=415Hz, sample=68, buffer_id=01:44
    db 11,0,102,0,56,38,1,5,208,0,56,1  ; n1188 t=329.118s dur=102ms, freq=208Hz, sample=56, buffer_id=01:38
    db 5,0,72,0,73,43,2,6,42,2,73,1  ; n1189 t=329.129s dur=72ms, freq=554Hz, sample=73, buffer_id=01:49
    db 216,1,97,0,77,43,2,2,186,2,77,1  ; n1190 t=329.134s dur=97ms, freq=698Hz, sample=77, buffer_id=01:4D
    db 4,0,88,0,56,34,1,0,208,0,56,1  ; n1191 t=329.606s dur=88ms, freq=208Hz, sample=56, buffer_id=01:38
    db 4,0,114,0,66,34,1,1,114,1,66,1  ; n1192 t=329.610s dur=114ms, freq=370Hz, sample=66, buffer_id=01:42
    db 14,0,83,0,75,38,2,2,110,2,75,1  ; n1193 t=329.614s dur=83ms, freq=622Hz, sample=75, buffer_id=01:4B
    db 232,0,95,0,72,38,2,3,11,2,72,1  ; n1194 t=329.628s dur=95ms, freq=523Hz, sample=72, buffer_id=01:48
    db 16,0,218,1,61,36,1,4,21,1,61,1  ; n1195 t=329.860s dur=474ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 1,0,203,1,73,38,2,5,42,2,73,1  ; n1196 t=329.876s dur=459ms, freq=554Hz, sample=73, buffer_id=01:49
    db 163,1,201,1,65,36,1,6,93,1,65,1  ; n1197 t=329.877s dur=457ms, freq=349Hz, sample=65, buffer_id=01:41
; t 329.8867 Sustain 127 (Instr 1)
; t 329.8867 Sustain 127 (Instr 2)
    db 14,0,28,1,53,34,1,0,175,0,53,1  ; n1198 t=330.296s dur=284ms, freq=175Hz, sample=53, buffer_id=01:35
    db 23,0,133,0,56,34,1,1,208,0,56,1  ; n1199 t=330.310s dur=133ms, freq=208Hz, sample=56, buffer_id=01:38
    db 1,0,213,1,73,53,2,5,42,2,73,1  ; n1200 t=330.333s dur=469ms, freq=554Hz, sample=73, buffer_id=01:49
    db 224,0,183,1,61,34,1,4,21,1,61,1  ; n1201 t=330.334s dur=439ms, freq=277Hz, sample=61, buffer_id=01:3D
; t 330.3351 Sustain 0 (Instr 1)
; t 330.3351 Sustain 0 (Instr 2)
; t 330.4347 Soft 0 (Instr 1)
; t 330.4347 Soft 0 (Instr 2)
    db 2,0,210,1,51,37,1,2,156,0,51,1  ; n1202 t=330.558s dur=466ms, freq=156Hz, sample=51, buffer_id=01:33
    db 230,0,170,1,56,37,1,1,208,0,56,1  ; n1203 t=330.560s dur=426ms, freq=208Hz, sample=56, buffer_id=01:38
    db 4,0,133,0,60,34,1,0,6,1,60,1  ; n1204 t=330.790s dur=133ms, freq=262Hz, sample=60, buffer_id=01:3C
    db 189,0,188,0,72,47,2,3,11,2,72,1  ; n1205 t=330.794s dur=188ms, freq=523Hz, sample=72, buffer_id=01:48
    db 7,0,204,0,49,37,1,4,139,0,49,1  ; n1206 t=330.983s dur=204ms, freq=139Hz, sample=49, buffer_id=01:31
    db 22,0,178,0,55,37,1,6,196,0,55,1  ; n1207 t=330.990s dur=178ms, freq=196Hz, sample=55, buffer_id=01:37
    db 7,0,3,1,70,50,2,5,210,1,70,1  ; n1208 t=331.012s dur=259ms, freq=466Hz, sample=70, buffer_id=01:46
    db 189,0,77,0,58,37,1,7,233,0,58,1  ; n1209 t=331.020s dur=77ms, freq=233Hz, sample=58, buffer_id=01:3A
    db 0,0,64,0,48,35,1,0,131,0,48,1  ; n1210 t=331.208s dur=64ms, freq=131Hz, sample=48, buffer_id=01:30
    db 37,0,76,0,60,35,1,1,6,1,60,1  ; n1211 t=331.208s dur=76ms, freq=262Hz, sample=60, buffer_id=01:3C
    db 202,0,194,0,63,40,1,2,55,1,63,1  ; n1212 t=331.245s dur=194ms, freq=311Hz, sample=63, buffer_id=01:3F
    db 196,0,245,0,75,47,2,3,110,2,75,1  ; n1213 t=331.448s dur=245ms, freq=622Hz, sample=75, buffer_id=01:4B
    db 6,0,138,0,49,37,1,0,139,0,49,1  ; n1214 t=331.644s dur=138ms, freq=139Hz, sample=49, buffer_id=01:31
    db 29,0,62,0,58,37,1,1,233,0,58,1  ; n1215 t=331.650s dur=62ms, freq=233Hz, sample=58, buffer_id=01:3A
    db 0,0,169,0,65,37,1,2,93,1,65,1  ; n1216 t=331.679s dur=169ms, freq=349Hz, sample=65, buffer_id=01:41
    db 207,0,18,1,73,50,2,4,42,2,73,1  ; n1217 t=331.679s dur=274ms, freq=554Hz, sample=73, buffer_id=01:49
    db 12,0,68,0,51,34,1,5,156,0,51,1  ; n1218 t=331.886s dur=68ms, freq=156Hz, sample=51, buffer_id=01:33
    db 6,0,243,0,68,47,2,3,159,1,68,1  ; n1219 t=331.897s dur=243ms, freq=415Hz, sample=68, buffer_id=01:44
    db 203,0,75,0,63,34,1,6,55,1,63,1  ; n1220 t=331.904s dur=75ms, freq=311Hz, sample=63, buffer_id=01:3F
    db 177,0,209,0,72,45,2,0,11,2,72,1  ; n1221 t=332.107s dur=209ms, freq=523Hz, sample=72, buffer_id=01:48
    db 12,0,145,0,61,36,1,1,21,1,61,1  ; n1222 t=332.284s dur=145ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 25,0,160,0,51,36,1,2,156,0,51,1  ; n1223 t=332.296s dur=160ms, freq=156Hz, sample=51, buffer_id=01:33
    db 12,0,88,2,67,48,2,4,136,1,67,1  ; n1224 t=332.321s dur=600ms, freq=392Hz, sample=67, buffer_id=01:43
    db 164,0,77,2,70,48,2,5,210,1,70,1  ; n1225 t=332.333s dur=589ms, freq=466Hz, sample=70, buffer_id=01:46
    db 6,0,168,1,56,35,1,3,208,0,56,1  ; n1226 t=332.497s dur=424ms, freq=208Hz, sample=56, buffer_id=01:38
    db 225,0,162,1,60,35,1,6,6,1,60,1  ; n1227 t=332.503s dur=418ms, freq=262Hz, sample=60, buffer_id=01:3C
; t 332.5979 Sustain 127 (Instr 1)
; t 332.5979 Sustain 127 (Instr 2)
    db 221,0,193,0,68,43,2,0,159,1,68,1  ; n1228 t=332.728s dur=193ms, freq=415Hz, sample=68, buffer_id=01:44
; t 332.9222 Sustain 0 (Instr 1)
; t 332.9222 Sustain 0 (Instr 2)
    db 0,0,104,0,61,34,1,1,21,1,61,1  ; n1229 t=332.950s dur=104ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 1,0,154,1,78,49,2,2,228,2,78,1  ; n1230 t=332.950s dur=410ms, freq=740Hz, sample=78, buffer_id=01:4E
    db 0,0,121,0,58,34,1,7,233,0,58,1  ; n1231 t=332.951s dur=121ms, freq=233Hz, sample=58, buffer_id=01:3A
    db 212,0,153,1,66,34,1,8,114,1,66,1  ; n1232 t=332.951s dur=409ms, freq=370Hz, sample=66, buffer_id=01:42
    db 8,0,184,1,56,36,1,0,208,0,56,1  ; n1233 t=333.163s dur=440ms, freq=208Hz, sample=56, buffer_id=01:38
    db 186,0,76,1,61,36,1,1,21,1,61,1  ; n1234 t=333.170s dur=332ms, freq=277Hz, sample=61, buffer_id=01:3D
; t 333.1712 Sustain 127 (Instr 1)
; t 333.1712 Sustain 127 (Instr 2)
    db 6,0,195,0,77,44,2,3,186,2,77,1  ; n1235 t=333.357s dur=195ms, freq=698Hz, sample=77, buffer_id=01:4D
; t 333.3599 Sustain 0 (Instr 1)
; t 333.3599 Sustain 0 (Instr 2)
    db 175,0,119,0,65,33,1,4,93,1,65,1  ; n1236 t=333.363s dur=119ms, freq=349Hz, sample=65, buffer_id=01:41
    db 19,0,169,0,54,35,1,5,185,0,54,1  ; n1237 t=333.538s dur=169ms, freq=185Hz, sample=54, buffer_id=01:36
    db 29,0,150,0,60,35,1,6,6,1,60,1  ; n1238 t=333.557s dur=150ms, freq=262Hz, sample=60, buffer_id=01:3C
    db 2,0,213,0,75,47,2,2,110,2,75,1  ; n1239 t=333.586s dur=213ms, freq=622Hz, sample=75, buffer_id=01:4B
    db 164,0,81,0,63,36,1,7,55,1,63,1  ; n1240 t=333.588s dur=81ms, freq=311Hz, sample=63, buffer_id=01:3F
    db 1,0,84,0,65,34,1,1,93,1,65,1  ; n1241 t=333.752s dur=84ms, freq=349Hz, sample=65, buffer_id=01:41
    db 32,0,78,0,53,34,1,3,175,0,53,1  ; n1242 t=333.753s dur=78ms, freq=175Hz, sample=53, buffer_id=01:35
    db 194,0,222,0,68,45,2,4,159,1,68,1  ; n1243 t=333.785s dur=222ms, freq=415Hz, sample=68, buffer_id=01:44
    db 207,0,38,1,80,42,2,0,63,3,80,1  ; n1244 t=333.979s dur=294ms, freq=831Hz, sample=80, buffer_id=01:50
    db 21,0,127,0,54,35,1,1,185,0,54,1  ; n1245 t=334.185s dur=127ms, freq=185Hz, sample=54, buffer_id=01:36
    db 15,0,87,0,63,36,1,2,55,1,63,1  ; n1246 t=334.207s dur=87ms, freq=311Hz, sample=63, buffer_id=01:3F
    db 6,0,30,1,78,45,2,3,228,2,78,1  ; n1247 t=334.221s dur=286ms, freq=740Hz, sample=78, buffer_id=01:4E
    db 184,0,204,0,70,45,2,4,210,1,70,1  ; n1248 t=334.228s dur=204ms, freq=466Hz, sample=70, buffer_id=01:46
    db 10,0,109,0,56,34,1,5,208,0,56,1  ; n1249 t=334.412s dur=109ms, freq=208Hz, sample=56, buffer_id=01:38
    db 52,0,117,0,68,44,2,6,159,1,68,1  ; n1250 t=334.422s dur=117ms, freq=415Hz, sample=68, buffer_id=01:44
    db 174,0,231,0,73,43,2,0,42,2,73,1  ; n1251 t=334.474s dur=231ms, freq=554Hz, sample=73, buffer_id=01:49
    db 193,0,1,1,77,42,2,1,186,2,77,1  ; n1252 t=334.647s dur=257ms, freq=698Hz, sample=77, buffer_id=01:4D
    db 26,0,212,0,66,33,1,2,114,1,66,1  ; n1253 t=334.840s dur=212ms, freq=370Hz, sample=66, buffer_id=01:42
    db 22,0,212,0,56,33,1,3,208,0,56,1  ; n1254 t=334.866s dur=212ms, freq=208Hz, sample=56, buffer_id=01:38
    db 31,0,182,0,72,46,2,4,11,2,72,1  ; n1255 t=334.889s dur=182ms, freq=523Hz, sample=72, buffer_id=01:48
    db 145,0,241,1,75,46,2,0,110,2,75,1  ; n1256 t=334.920s dur=497ms, freq=622Hz, sample=75, buffer_id=01:4B
    db 5,0,96,1,61,33,1,5,21,1,61,1  ; n1257 t=335.065s dur=352ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 212,0,91,1,65,33,1,6,93,1,65,1  ; n1258 t=335.070s dur=347ms, freq=349Hz, sample=65, buffer_id=01:41
    db 227,0,207,0,73,43,2,1,42,2,73,1  ; n1259 t=335.282s dur=207ms, freq=554Hz, sample=73, buffer_id=01:49
; t 335.2903 Sustain 127 (Instr 1)
; t 335.2903 Sustain 127 (Instr 2)
; t 335.4174 Sustain 0 (Instr 1)
; t 335.4174 Sustain 0 (Instr 2)
    db 16,0,79,1,61,36,1,5,21,1,61,1  ; n1260 t=335.509s dur=335ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 1,0,178,0,73,46,2,1,42,2,73,1  ; n1261 t=335.524s dur=178ms, freq=554Hz, sample=73, buffer_id=01:49
    db 236,0,156,0,65,36,1,6,93,1,65,1  ; n1262 t=335.526s dur=156ms, freq=349Hz, sample=65, buffer_id=01:41
; t 335.5276 Sustain 127 (Instr 1)
; t 335.5276 Sustain 127 (Instr 2)
; t 335.6823 Sustain 0 (Instr 1)
; t 335.6823 Sustain 0 (Instr 2)
    db 61,0,34,2,58,40,1,0,233,0,58,1  ; n1263 t=335.762s dur=546ms, freq=233Hz, sample=58, buffer_id=01:3A
    db 7,0,229,1,73,56,2,1,42,2,73,1  ; n1264 t=335.823s dur=485ms, freq=554Hz, sample=73, buffer_id=01:49
    db 138,1,221,1,65,40,1,6,93,1,65,1  ; n1265 t=335.831s dur=477ms, freq=349Hz, sample=65, buffer_id=01:41
; t 335.8635 Sustain 127 (Instr 1)
; t 335.8635 Sustain 127 (Instr 2)
    db 60,0,39,1,56,34,1,2,208,0,56,1  ; n1266 t=336.225s dur=295ms, freq=208Hz, sample=56, buffer_id=01:38
    db 9,0,134,0,73,53,2,1,42,2,73,1  ; n1267 t=336.285s dur=134ms, freq=554Hz, sample=73, buffer_id=01:49
    db 162,0,82,0,65,35,1,6,93,1,65,1  ; n1268 t=336.294s dur=82ms, freq=349Hz, sample=65, buffer_id=01:41
; t 336.3084 Sustain 0 (Instr 1)
; t 336.3084 Sustain 0 (Instr 2)
    db 42,0,186,1,55,37,1,3,196,0,55,1  ; n1269 t=336.456s dur=442ms, freq=196Hz, sample=55, buffer_id=01:37
    db 9,0,232,0,73,55,2,1,42,2,73,1  ; n1270 t=336.498s dur=232ms, freq=554Hz, sample=73, buffer_id=01:49
    db 5,1,187,0,63,37,1,4,55,1,63,1  ; n1271 t=336.507s dur=187ms, freq=311Hz, sample=63, buffer_id=01:3F
; t 336.7618 Sustain 127 (Instr 1)
; t 336.7618 Sustain 127 (Instr 2)
    db 17,0,165,0,56,34,1,0,208,0,56,1  ; n1272 t=336.767s dur=165ms, freq=208Hz, sample=56, buffer_id=01:38
    db 8,0,119,0,72,52,2,2,11,2,72,1  ; n1273 t=336.784s dur=119ms, freq=523Hz, sample=72, buffer_id=01:48
    db 177,0,107,0,63,33,1,4,55,1,63,1  ; n1274 t=336.793s dur=107ms, freq=311Hz, sample=63, buffer_id=01:3F
; t 336.8985 Sustain 0 (Instr 1)
; t 336.8985 Sustain 0 (Instr 2)
    db 22,0,33,1,71,50,2,1,238,1,71,1  ; n1275 t=336.969s dur=289ms, freq=494Hz, sample=71, buffer_id=01:47
    db 5,0,10,1,56,33,1,0,208,0,56,1  ; n1276 t=336.992s dur=266ms, freq=208Hz, sample=56, buffer_id=01:38
    db 17,1,5,1,63,34,1,4,55,1,63,1  ; n1277 t=336.997s dur=261ms, freq=311Hz, sample=63, buffer_id=01:3F
; t 337.0659 Sustain 127 (Instr 1)
; t 337.0659 Sustain 127 (Instr 2)
; t 337.2587 Sustain 0 (Instr 1)
; t 337.2587 Sustain 0 (Instr 2)
    db 41,0,87,2,56,37,1,0,208,0,56,1  ; n1278 t=337.270s dur=599ms, freq=208Hz, sample=56, buffer_id=01:38
    db 9,0,46,2,71,54,2,1,238,1,71,1  ; n1279 t=337.312s dur=558ms, freq=494Hz, sample=71, buffer_id=01:47
    db 176,1,82,0,63,37,1,4,55,1,63,1  ; n1280 t=337.320s dur=82ms, freq=311Hz, sample=63, buffer_id=01:3F
; t 337.4452 Sustain 127 (Instr 1)
; t 337.4452 Sustain 127 (Instr 2)
    db 2,0,195,0,71,51,2,1,238,1,71,1  ; n1281 t=337.752s dur=195ms, freq=494Hz, sample=71, buffer_id=01:47
    db 13,0,115,0,63,34,1,2,55,1,63,1  ; n1282 t=337.754s dur=115ms, freq=311Hz, sample=63, buffer_id=01:3F
    db 150,0,177,0,54,34,1,3,185,0,54,1  ; n1283 t=337.767s dur=177ms, freq=185Hz, sample=54, buffer_id=01:36
; t 337.8699 Sustain 0 (Instr 1)
; t 337.8699 Sustain 0 (Instr 2)
    db 24,0,95,1,53,36,1,4,175,0,53,1  ; n1284 t=337.918s dur=351ms, freq=175Hz, sample=53, buffer_id=01:35
    db 60,0,71,1,61,37,1,5,21,1,61,1  ; n1285 t=337.942s dur=327ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 209,0,10,1,71,54,2,1,238,1,71,1  ; n1286 t=338.002s dur=266ms, freq=494Hz, sample=71, buffer_id=01:47
; t 338.0563 Sustain 127 (Instr 1)
; t 338.0563 Sustain 127 (Instr 2)
    db 18,0,138,0,54,35,1,0,185,0,54,1  ; n1287 t=338.211s dur=138ms, freq=185Hz, sample=54, buffer_id=01:36
    db 8,0,176,0,70,51,2,2,210,1,70,1  ; n1288 t=338.229s dur=176ms, freq=466Hz, sample=70, buffer_id=01:46
    db 210,0,130,0,61,34,1,5,21,1,61,1  ; n1289 t=338.237s dur=130ms, freq=277Hz, sample=61, buffer_id=01:3D
; t 338.2691 Sustain 0 (Instr 1)
; t 338.2691 Sustain 0 (Instr 2)
    db 43,0,27,1,54,33,1,0,185,0,54,1  ; n1290 t=338.447s dur=283ms, freq=185Hz, sample=54, buffer_id=01:36
    db 21,0,14,1,70,48,2,2,210,1,70,1  ; n1291 t=338.490s dur=270ms, freq=466Hz, sample=70, buffer_id=01:46
; t 338.5095 Sustain 127 (Instr 1)
; t 338.5095 Sustain 127 (Instr 2)
    db 203,0,216,0,61,33,1,5,21,1,61,1  ; n1292 t=338.512s dur=216ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 18,0,163,2,51,36,1,1,156,0,51,1  ; n1293 t=338.715s dur=675ms, freq=156Hz, sample=51, buffer_id=01:33
; t 338.7277 Sustain 0 (Instr 1)
; t 338.7277 Sustain 0 (Instr 2)
    db 60,0,145,2,56,36,1,3,208,0,56,1  ; n1294 t=338.733s dur=657ms, freq=208Hz, sample=56, buffer_id=01:38
    db 14,0,85,2,72,52,2,4,11,2,72,1  ; n1295 t=338.793s dur=597ms, freq=523Hz, sample=72, buffer_id=01:48
    db 52,2,71,2,66,37,1,6,114,1,66,1  ; n1296 t=338.807s dur=583ms, freq=370Hz, sample=66, buffer_id=01:42
; t 338.9384 Sustain 127 (Instr 1)
; t 338.9384 Sustain 127 (Instr 2)
    db 5,0,204,1,73,52,2,0,42,2,73,1  ; n1297 t=339.372s dur=460ms, freq=554Hz, sample=73, buffer_id=01:49
    db 1,0,8,1,65,36,1,2,93,1,65,1  ; n1298 t=339.377s dur=264ms, freq=349Hz, sample=65, buffer_id=01:41
    db 6,0,196,1,49,36,1,5,139,0,49,1  ; n1299 t=339.378s dur=452ms, freq=139Hz, sample=49, buffer_id=01:31
    db 129,1,53,1,56,36,1,3,208,0,56,1  ; n1300 t=339.384s dur=309ms, freq=208Hz, sample=56, buffer_id=01:38
; t 339.3906 Sustain 0 (Instr 1)
; t 339.3906 Sustain 0 (Instr 2)
    db 40,0,186,5,48,42,1,1,131,0,48,1  ; n1301 t=339.770s dur=1466ms, freq=131Hz, sample=48, buffer_id=01:30
    db 16,0,25,5,56,47,1,3,208,0,56,1  ; n1302 t=339.810s dur=1305ms, freq=208Hz, sample=56, buffer_id=01:38
    db 1,0,9,5,75,61,2,4,110,2,75,1  ; n1303 t=339.826s dur=1289ms, freq=622Hz, sample=75, buffer_id=01:4B
    db 104,4,8,5,66,50,1,6,114,1,66,1  ; n1304 t=339.827s dur=1288ms, freq=370Hz, sample=66, buffer_id=01:42
; t 340.2844 Sustain 127 (Instr 1)
; t 340.2844 Sustain 127 (Instr 2)
; t 340.9261 Soft 127 (Instr 1)
; t 340.9261 Soft 127 (Instr 2)
    db 6,0,141,2,66,37,1,6,114,1,66,1  ; n1305 t=340.955s dur=653ms, freq=370Hz, sample=66, buffer_id=01:42
    db 9,1,129,2,63,37,1,0,55,1,63,1  ; n1306 t=340.961s dur=641ms, freq=311Hz, sample=63, buffer_id=01:3F
; t 341.1157 Sustain 0 (Instr 1)
; t 341.1157 Sustain 0 (Instr 2)
    db 6,0,97,2,49,34,1,2,139,0,49,1  ; n1307 t=341.226s dur=609ms, freq=139Hz, sample=49, buffer_id=01:31
    db 44,1,177,1,56,34,1,3,208,0,56,1  ; n1308 t=341.232s dur=433ms, freq=208Hz, sample=56, buffer_id=01:38
    db 61,0,153,0,61,33,1,1,21,1,61,1  ; n1309 t=341.532s dur=153ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 220,0,108,1,65,39,1,4,93,1,65,1  ; n1310 t=341.593s dur=364ms, freq=349Hz, sample=65, buffer_id=01:41
    db 107,0,165,1,42,35,1,0,92,0,42,1  ; n1311 t=341.813s dur=421ms, freq=92Hz, sample=42, buffer_id=01:2A
    db 12,0,116,1,54,36,1,1,185,0,54,1  ; n1312 t=341.920s dur=372ms, freq=185Hz, sample=54, buffer_id=01:36
    db 93,0,204,1,58,37,1,3,233,0,58,1  ; n1313 t=341.932s dur=460ms, freq=233Hz, sample=58, buffer_id=01:3A
    db 207,0,235,0,70,45,2,5,210,1,70,1  ; n1314 t=342.025s dur=235ms, freq=466Hz, sample=70, buffer_id=01:46
    db 14,0,152,0,66,34,1,2,114,1,66,1  ; n1315 t=342.233s dur=152ms, freq=370Hz, sample=66, buffer_id=01:42
    db 161,0,211,1,51,34,1,4,156,0,51,1  ; n1316 t=342.246s dur=467ms, freq=156Hz, sample=51, buffer_id=01:33
    db 19,0,57,1,44,34,1,6,104,0,44,1  ; n1317 t=342.407s dur=313ms, freq=104Hz, sample=44, buffer_id=01:2C
    db 25,0,77,1,56,35,1,7,208,0,56,1  ; n1318 t=342.426s dur=333ms, freq=208Hz, sample=56, buffer_id=01:38
    db 7,0,43,1,65,40,1,0,93,1,65,1  ; n1319 t=342.452s dur=299ms, freq=349Hz, sample=65, buffer_id=01:41
    db 6,1,255,0,61,41,1,8,21,1,61,1  ; n1320 t=342.459s dur=255ms, freq=277Hz, sample=61, buffer_id=01:3D
; t 342.4719 Sustain 127 (Instr 1)
; t 342.4719 Sustain 127 (Instr 2)
; t 342.7143 Sustain 0 (Instr 1)
; t 342.7143 Sustain 0 (Instr 2)
    db 11,0,87,0,60,39,1,1,6,1,60,1  ; n1321 t=342.721s dur=87ms, freq=262Hz, sample=60, buffer_id=01:3C
    db 199,0,72,0,63,39,1,2,55,1,63,1  ; n1322 t=342.731s dur=72ms, freq=311Hz, sample=63, buffer_id=01:3F
    db 1,0,152,0,56,42,1,7,208,0,56,1  ; n1323 t=342.930s dur=152ms, freq=208Hz, sample=56, buffer_id=01:38
    db 44,0,144,0,53,42,1,3,175,0,53,1  ; n1324 t=342.931s dur=144ms, freq=175Hz, sample=53, buffer_id=01:35
    db 10,0,224,0,61,42,1,0,21,1,61,1  ; n1325 t=342.976s dur=224ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 187,0,131,0,73,48,2,4,42,2,73,1  ; n1326 t=342.985s dur=131ms, freq=554Hz, sample=73, buffer_id=01:49
    db 5,0,239,1,51,45,1,1,156,0,51,1  ; n1327 t=343.173s dur=495ms, freq=156Hz, sample=51, buffer_id=01:33
    db 60,0,234,1,56,45,1,7,208,0,56,1  ; n1328 t=343.178s dur=490ms, freq=208Hz, sample=56, buffer_id=01:38
    db 2,0,173,1,72,55,2,2,11,2,72,1  ; n1329 t=343.238s dur=429ms, freq=523Hz, sample=72, buffer_id=01:48
    db 146,1,171,1,60,44,1,5,6,1,60,1  ; n1330 t=343.240s dur=427ms, freq=262Hz, sample=60, buffer_id=01:3C
; t 343.3865 Sustain 127 (Instr 1)
; t 343.3865 Sustain 127 (Instr 2)
    db 13,0,16,1,55,39,1,0,196,0,55,1  ; n1331 t=343.643s dur=272ms, freq=196Hz, sample=55, buffer_id=01:37
    db 23,0,221,0,49,40,1,3,139,0,49,1  ; n1332 t=343.655s dur=221ms, freq=139Hz, sample=49, buffer_id=01:31
; t 343.6680 Sustain 0 (Instr 1)
; t 343.6680 Sustain 0 (Instr 2)
    db 13,0,47,1,70,50,2,4,210,1,70,1  ; n1333 t=343.679s dur=303ms, freq=466Hz, sample=70, buffer_id=01:46
    db 240,0,72,0,58,40,1,6,233,0,58,1  ; n1334 t=343.691s dur=72ms, freq=233Hz, sample=58, buffer_id=01:3A
    db 12,0,75,0,48,41,1,1,131,0,48,1  ; n1335 t=343.932s dur=75ms, freq=131Hz, sample=48, buffer_id=01:30
    db 12,0,101,0,60,41,1,2,6,1,60,1  ; n1336 t=343.943s dur=101ms, freq=262Hz, sample=60, buffer_id=01:3C
    db 10,0,101,0,63,41,1,5,55,1,63,1  ; n1337 t=343.955s dur=101ms, freq=311Hz, sample=63, buffer_id=01:3F
    db 160,1,90,0,75,53,2,6,110,2,75,1  ; n1338 t=343.964s dur=90ms, freq=622Hz, sample=75, buffer_id=01:4B
    db 18,0,113,0,49,41,1,0,139,0,49,1  ; n1339 t=344.380s dur=113ms, freq=139Hz, sample=49, buffer_id=01:31
    db 18,0,76,0,58,42,1,1,233,0,58,1  ; n1340 t=344.399s dur=76ms, freq=233Hz, sample=58, buffer_id=01:3A
    db 5,0,6,1,65,42,1,2,93,1,65,1  ; n1341 t=344.416s dur=262ms, freq=349Hz, sample=65, buffer_id=01:41
    db 200,0,119,1,73,55,2,3,42,2,73,1  ; n1342 t=344.422s dur=375ms, freq=554Hz, sample=73, buffer_id=01:49
    db 14,0,109,0,51,45,1,4,156,0,51,1  ; n1343 t=344.622s dur=109ms, freq=156Hz, sample=51, buffer_id=01:33
    db 11,0,83,0,63,45,1,5,55,1,63,1  ; n1344 t=344.636s dur=83ms, freq=311Hz, sample=63, buffer_id=01:3F
    db 193,0,213,0,68,52,2,6,159,1,68,1  ; n1345 t=344.646s dur=213ms, freq=415Hz, sample=68, buffer_id=01:44
    db 187,0,211,0,72,50,2,0,11,2,72,1  ; n1346 t=344.839s dur=211ms, freq=523Hz, sample=72, buffer_id=01:48
    db 22,0,130,0,61,40,1,1,21,1,61,1  ; n1347 t=345.026s dur=130ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 18,0,102,0,51,41,1,2,156,0,51,1  ; n1348 t=345.048s dur=102ms, freq=156Hz, sample=51, buffer_id=01:33
    db 7,0,64,2,70,53,2,3,210,1,70,1  ; n1349 t=345.066s dur=576ms, freq=466Hz, sample=70, buffer_id=01:46
    db 161,0,57,2,67,54,2,4,136,1,67,1  ; n1350 t=345.074s dur=569ms, freq=392Hz, sample=67, buffer_id=01:43
    db 6,0,152,1,56,42,1,5,208,0,56,1  ; n1351 t=345.235s dur=408ms, freq=208Hz, sample=56, buffer_id=01:38
    db 206,0,146,1,60,42,1,6,6,1,60,1  ; n1352 t=345.241s dur=402ms, freq=262Hz, sample=60, buffer_id=01:3C
; t 345.3321 Sustain 127 (Instr 1)
; t 345.3321 Sustain 127 (Instr 2)
    db 190,0,195,0,68,49,2,0,159,1,68,1  ; n1353 t=345.447s dur=195ms, freq=415Hz, sample=68, buffer_id=01:44
; t 345.4696 Soft 0 (Instr 1)
; t 345.4696 Soft 0 (Instr 2)
    db 6,0,232,0,58,40,1,1,233,0,58,1  ; n1354 t=345.638s dur=232ms, freq=233Hz, sample=58, buffer_id=01:3A
; t 345.6432 Sustain 0 (Instr 1)
; t 345.6432 Sustain 0 (Instr 2)
    db 10,0,132,0,61,40,1,2,21,1,61,1  ; n1355 t=345.644s dur=132ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 1,0,184,0,78,50,2,7,228,2,78,1  ; n1356 t=345.654s dur=184ms, freq=740Hz, sample=78, buffer_id=01:4E
    db 215,0,189,0,66,40,1,8,114,1,66,1  ; n1357 t=345.655s dur=189ms, freq=370Hz, sample=66, buffer_id=01:42
    db 0,0,93,1,61,43,1,2,21,1,61,1  ; n1358 t=345.870s dur=349ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 11,0,195,1,56,43,1,0,208,0,56,1  ; n1359 t=345.870s dur=451ms, freq=208Hz, sample=56, buffer_id=01:38
    db 19,0,95,1,77,53,2,3,186,2,77,1  ; n1360 t=345.880s dur=351ms, freq=698Hz, sample=77, buffer_id=01:4D
    db 121,1,63,1,65,44,1,4,93,1,65,1  ; n1361 t=345.899s dur=319ms, freq=349Hz, sample=65, buffer_id=01:41
; t 345.9691 Sustain 127 (Instr 1)
; t 345.9691 Sustain 127 (Instr 2)
; t 346.2188 Sustain 0 (Instr 1)
; t 346.2188 Sustain 0 (Instr 2)
    db 13,0,208,0,54,44,1,1,185,0,54,1  ; n1362 t=346.276s dur=208ms, freq=185Hz, sample=54, buffer_id=01:36
    db 9,0,112,0,60,45,1,5,6,1,60,1  ; n1363 t=346.289s dur=112ms, freq=262Hz, sample=60, buffer_id=01:3C
    db 10,0,165,0,75,48,2,6,110,2,75,1  ; n1364 t=346.297s dur=165ms, freq=622Hz, sample=75, buffer_id=01:4B
    db 162,0,100,0,63,45,1,7,55,1,63,1  ; n1365 t=346.307s dur=100ms, freq=311Hz, sample=63, buffer_id=01:3F
    db 19,0,193,1,53,46,1,2,175,0,53,1  ; n1366 t=346.469s dur=449ms, freq=175Hz, sample=53, buffer_id=01:35
    db 18,0,174,1,61,46,1,3,21,1,61,1  ; n1367 t=346.488s dur=430ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 0,0,156,1,68,58,2,4,159,1,68,1  ; n1368 t=346.506s dur=412ms, freq=415Hz, sample=68, buffer_id=01:44
    db 161,1,156,1,80,58,2,8,63,3,80,1  ; n1369 t=346.506s dur=412ms, freq=831Hz, sample=80, buffer_id=01:50
; t 346.5944 Sustain 127 (Instr 1)
; t 346.5944 Sustain 127 (Instr 2)
; t 346.9182 Sustain 0 (Instr 1)
; t 346.9182 Sustain 0 (Instr 2)
    db 7,0,220,1,78,58,2,0,228,2,78,1  ; n1370 t=346.923s dur=476ms, freq=740Hz, sample=78, buffer_id=01:4E
    db 1,0,212,1,66,48,1,1,114,1,66,1  ; n1371 t=346.930s dur=468ms, freq=370Hz, sample=66, buffer_id=01:42
    db 5,0,101,0,61,49,1,3,21,1,61,1  ; n1372 t=346.931s dur=101ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 192,0,145,0,58,49,1,5,233,0,58,1  ; n1373 t=346.936s dur=145ms, freq=233Hz, sample=58, buffer_id=01:3A
    db 1,0,36,1,61,51,1,3,21,1,61,1  ; n1374 t=347.128s dur=292ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 182,0,139,1,56,51,1,2,208,0,56,1  ; n1375 t=347.129s dur=395ms, freq=208Hz, sample=56, buffer_id=01:38
; t 347.1457 Sustain 127 (Instr 1)
; t 347.1457 Sustain 127 (Instr 2)
    db 14,0,125,0,77,63,2,4,186,2,77,1  ; n1376 t=347.311s dur=125ms, freq=698Hz, sample=77, buffer_id=01:4D
    db 161,0,94,0,65,49,1,5,93,1,65,1  ; n1377 t=347.325s dur=94ms, freq=349Hz, sample=65, buffer_id=01:41
; t 347.3986 Sustain 0 (Instr 1)
; t 347.3986 Sustain 0 (Instr 2)
    db 13,0,189,0,54,51,1,6,185,0,54,1  ; n1378 t=347.485s dur=189ms, freq=185Hz, sample=54, buffer_id=01:36
    db 8,0,89,0,60,51,1,7,6,1,60,1  ; n1379 t=347.498s dur=89ms, freq=262Hz, sample=60, buffer_id=01:3C
    db 28,0,165,0,75,61,2,8,110,2,75,1  ; n1380 t=347.507s dur=165ms, freq=622Hz, sample=75, buffer_id=01:4B
    db 99,0,109,0,63,52,1,9,55,1,63,1  ; n1381 t=347.534s dur=109ms, freq=311Hz, sample=63, buffer_id=01:3F
    db 65,0,209,1,53,53,1,0,175,0,53,1  ; n1382 t=347.634s dur=465ms, freq=175Hz, sample=53, buffer_id=01:35
    db 47,0,145,1,61,54,1,1,21,1,61,1  ; n1383 t=347.698s dur=401ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 7,0,98,1,80,70,2,2,63,3,80,1  ; n1384 t=347.745s dur=354ms, freq=831Hz, sample=80, buffer_id=01:50
    db 138,1,91,1,68,70,2,3,159,1,68,1  ; n1385 t=347.752s dur=347ms, freq=415Hz, sample=68, buffer_id=01:44
; t 347.8060 Sustain 127 (Instr 1)
; t 347.8060 Sustain 127 (Instr 2)
; t 348.0991 Sustain 0 (Instr 1)
; t 348.0991 Sustain 0 (Instr 2)
    db 9,0,28,1,78,70,2,4,228,2,78,1  ; n1386 t=348.146s dur=284ms, freq=740Hz, sample=78, buffer_id=01:4E
    db 1,0,0,1,66,53,1,5,114,1,66,1  ; n1387 t=348.154s dur=256ms, freq=370Hz, sample=66, buffer_id=01:42
    db 5,0,124,0,58,53,1,6,233,0,58,1  ; n1388 t=348.155s dur=124ms, freq=233Hz, sample=58, buffer_id=01:3A
    db 161,0,88,0,61,54,1,1,21,1,61,1  ; n1389 t=348.161s dur=88ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 6,0,249,1,56,56,1,0,208,0,56,1  ; n1390 t=348.321s dur=505ms, freq=208Hz, sample=56, buffer_id=01:38
    db 173,0,243,1,61,56,1,1,21,1,61,1  ; n1391 t=348.328s dur=499ms, freq=277Hz, sample=61, buffer_id=01:3D
; t 348.4695 Sustain 127 (Instr 1)
; t 348.4695 Sustain 127 (Instr 2)
    db 5,0,69,1,77,66,2,2,186,2,77,1  ; n1392 t=348.501s dur=325ms, freq=698Hz, sample=77, buffer_id=01:4D
    db 108,0,64,1,65,58,1,3,93,1,65,1  ; n1393 t=348.507s dur=320ms, freq=349Hz, sample=65, buffer_id=01:41
    db 69,0,32,3,55,65,1,5,196,0,55,1  ; n1394 t=348.615s dur=800ms, freq=196Hz, sample=55, buffer_id=01:37
    db 32,0,45,2,61,65,1,1,21,1,61,1  ; n1395 t=348.683s dur=557ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 103,0,32,2,64,65,1,4,74,1,64,1  ; n1396 t=348.715s dur=544ms, freq=330Hz, sample=64, buffer_id=01:40
    db 7,0,13,5,82,70,2,6,164,3,82,1  ; n1397 t=348.818s dur=1293ms, freq=932Hz, sample=82, buffer_id=01:52
    db 113,2,107,4,70,70,2,7,210,1,70,1  ; n1398 t=348.825s dur=1131ms, freq=466Hz, sample=70, buffer_id=01:46
; t 348.8271 Sustain 0 (Instr 1)
; t 348.8271 Sustain 0 (Instr 2)
; t 349.2355 Soft 127 (Instr 1)
; t 349.2355 Soft 127 (Instr 2)
    db 4,0,251,3,56,46,1,0,208,0,56,1  ; n1399 t=349.450s dur=1019ms, freq=208Hz, sample=56, buffer_id=01:38
    db 13,0,208,3,61,46,1,1,21,1,61,1  ; n1400 t=349.454s dur=976ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 98,2,114,3,65,45,1,2,93,1,65,1  ; n1401 t=349.467s dur=882ms, freq=349Hz, sample=65, buffer_id=01:41
    db 1,0,69,1,80,53,2,3,63,3,80,1  ; n1402 t=350.077s dur=325ms, freq=831Hz, sample=80, buffer_id=01:50
    db 112,3,63,1,68,53,2,4,159,1,68,1  ; n1403 t=350.079s dur=319ms, freq=415Hz, sample=68, buffer_id=01:44
    db 54,0,187,4,32,35,1,0,52,0,32,1  ; n1404 t=350.959s dur=1211ms, freq=52Hz, sample=32, buffer_id=01:20
    db 125,0,106,4,44,35,1,1,104,0,44,1  ; n1405 t=351.012s dur=1130ms, freq=104Hz, sample=44, buffer_id=01:2C
    db 25,0,244,3,54,37,1,2,185,0,54,1  ; n1406 t=351.137s dur=1012ms, freq=185Hz, sample=54, buffer_id=01:36
    db 254,2,24,3,60,37,1,3,6,1,60,1  ; n1407 t=351.163s dur=792ms, freq=262Hz, sample=60, buffer_id=01:3C
    db 187,0,208,0,63,37,1,4,55,1,63,1  ; n1408 t=351.928s dur=208ms, freq=311Hz, sample=63, buffer_id=01:3F
    db 144,0,225,0,61,35,1,5,21,1,61,1  ; n1409 t=352.116s dur=225ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 36,0,182,2,37,33,1,3,69,0,37,1  ; n1410 t=352.260s dur=694ms, freq=69Hz, sample=37, buffer_id=01:25
    db 112,0,146,2,44,34,1,1,104,0,44,1  ; n1411 t=352.296s dur=658ms, freq=104Hz, sample=44, buffer_id=01:2C
    db 6,0,34,2,61,35,1,5,21,1,61,1  ; n1412 t=352.408s dur=546ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 163,3,28,2,53,35,1,0,175,0,53,1  ; n1413 t=352.414s dur=540ms, freq=175Hz, sample=53, buffer_id=01:35
; t 352.4647 Sustain 127 (Instr 1)
; t 352.4647 Sustain 127 (Instr 2)
; t 352.5663 Soft 0 (Instr 1)
; t 352.5663 Soft 0 (Instr 2)
; t 352.9544 Sustain 0 (Instr 1)
; t 352.9544 Sustain 0 (Instr 2)
    db 10,0,52,3,61,33,1,0,21,1,61,1  ; n1414 t=353.345s dur=820ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 26,0,42,3,73,44,2,1,42,2,73,1  ; n1415 t=353.354s dur=810ms, freq=554Hz, sample=73, buffer_id=01:49
; t 353.3668 Sustain 127 (Instr 1)
; t 353.3668 Sustain 127 (Instr 2)
    db 38,1,16,3,65,33,1,2,93,1,65,1  ; n1416 t=353.380s dur=784ms, freq=349Hz, sample=65, buffer_id=01:41
    db 11,0,249,1,58,37,1,3,233,0,58,1  ; n1417 t=353.674s dur=505ms, freq=233Hz, sample=58, buffer_id=01:3A
    db 1,0,224,1,73,48,2,1,42,2,73,1  ; n1418 t=353.685s dur=480ms, freq=554Hz, sample=73, buffer_id=01:49
    db 211,1,222,1,65,37,1,2,93,1,65,1  ; n1419 t=353.686s dur=478ms, freq=349Hz, sample=65, buffer_id=01:41
    db 11,0,2,1,56,36,1,4,208,0,56,1  ; n1420 t=354.153s dur=258ms, freq=208Hz, sample=56, buffer_id=01:38
    db 7,0,181,0,73,43,2,1,42,2,73,1  ; n1421 t=354.164s dur=181ms, freq=554Hz, sample=73, buffer_id=01:49
; t 354.1650 Sustain 0 (Instr 1)
; t 354.1650 Sustain 0 (Instr 2)
    db 206,0,106,0,65,37,1,2,93,1,65,1  ; n1422 t=354.171s dur=106ms, freq=349Hz, sample=65, buffer_id=01:41
    db 41,0,57,1,55,39,1,0,196,0,55,1  ; n1423 t=354.377s dur=313ms, freq=196Hz, sample=55, buffer_id=01:37
    db 8,0,218,0,73,47,2,1,42,2,73,1  ; n1424 t=354.419s dur=218ms, freq=554Hz, sample=73, buffer_id=01:49
    db 229,0,125,0,63,40,1,3,55,1,63,1  ; n1425 t=354.427s dur=125ms, freq=311Hz, sample=63, buffer_id=01:3F
    db 23,0,158,0,56,37,1,2,208,0,56,1  ; n1426 t=354.657s dur=158ms, freq=208Hz, sample=56, buffer_id=01:38
    db 2,0,101,0,72,44,2,4,11,2,72,1  ; n1427 t=354.680s dur=101ms, freq=523Hz, sample=72, buffer_id=01:48
    db 220,0,144,0,63,37,1,3,55,1,63,1  ; n1428 t=354.682s dur=144ms, freq=311Hz, sample=63, buffer_id=01:3F
; t 354.8777 Sustain 127 (Instr 1)
; t 354.8777 Sustain 127 (Instr 2)
    db 8,0,55,3,71,41,2,0,238,1,71,1  ; n1429 t=354.902s dur=823ms, freq=494Hz, sample=71, buffer_id=01:47
    db 19,0,47,3,56,34,1,2,208,0,56,1  ; n1430 t=354.910s dur=815ms, freq=208Hz, sample=56, buffer_id=01:38
    db 249,0,28,3,63,34,1,3,55,1,63,1  ; n1431 t=354.930s dur=796ms, freq=311Hz, sample=63, buffer_id=01:3F
    db 4,0,34,2,56,37,1,2,208,0,56,1  ; n1432 t=355.179s dur=546ms, freq=208Hz, sample=56, buffer_id=01:38
    db 10,0,30,2,71,45,2,0,238,1,71,1  ; n1433 t=355.183s dur=542ms, freq=494Hz, sample=71, buffer_id=01:47
    db 171,1,20,2,63,37,1,3,55,1,63,1  ; n1434 t=355.193s dur=532ms, freq=311Hz, sample=63, buffer_id=01:3F
    db 10,0,222,0,54,33,1,1,185,0,54,1  ; n1435 t=355.620s dur=222ms, freq=185Hz, sample=54, buffer_id=01:36
    db 16,0,190,0,71,40,2,0,238,1,71,1  ; n1436 t=355.629s dur=190ms, freq=494Hz, sample=71, buffer_id=01:47
    db 156,0,80,0,63,34,1,3,55,1,63,1  ; n1437 t=355.645s dur=80ms, freq=311Hz, sample=63, buffer_id=01:3F
; t 355.7256 Sustain 0 (Instr 1)
; t 355.7256 Sustain 0 (Instr 2)
    db 5,0,7,1,61,36,1,4,21,1,61,1  ; n1438 t=355.802s dur=263ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 72,0,59,1,53,36,1,5,175,0,53,1  ; n1439 t=355.807s dur=315ms, freq=175Hz, sample=53, buffer_id=01:35
    db 190,0,177,0,71,43,2,0,238,1,71,1  ; n1440 t=355.879s dur=177ms, freq=494Hz, sample=71, buffer_id=01:47
    db 42,0,164,0,54,34,1,1,185,0,54,1  ; n1441 t=356.069s dur=164ms, freq=185Hz, sample=54, buffer_id=01:36
    db 1,0,164,0,70,42,2,2,210,1,70,1  ; n1442 t=356.111s dur=164ms, freq=466Hz, sample=70, buffer_id=01:46
    db 182,0,144,0,61,34,1,4,21,1,61,1  ; n1443 t=356.113s dur=144ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 54,0,2,1,54,33,1,1,185,0,54,1  ; n1444 t=356.294s dur=258ms, freq=185Hz, sample=54, buffer_id=01:36
    db 2,0,20,1,70,45,2,2,210,1,70,1  ; n1445 t=356.348s dur=276ms, freq=466Hz, sample=70, buffer_id=01:46
    db 181,0,100,0,61,34,1,4,21,1,61,1  ; n1446 t=356.351s dur=100ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 23,0,175,2,51,36,1,0,156,0,51,1  ; n1447 t=356.531s dur=687ms, freq=156Hz, sample=51, buffer_id=01:33
    db 97,0,151,2,56,37,1,3,208,0,56,1  ; n1448 t=356.555s dur=663ms, freq=208Hz, sample=56, buffer_id=01:38
    db 21,0,54,2,72,49,2,4,11,2,72,1  ; n1449 t=356.652s dur=566ms, freq=523Hz, sample=72, buffer_id=01:48
    db 239,1,33,2,66,38,1,5,114,1,66,1  ; n1450 t=356.673s dur=545ms, freq=370Hz, sample=66, buffer_id=01:42
; t 356.7533 Sustain 127 (Instr 1)
; t 356.7533 Sustain 127 (Instr 2)
    db 3,0,193,1,73,51,2,1,42,2,73,1  ; n1451 t=357.168s dur=449ms, freq=554Hz, sample=73, buffer_id=01:49
    db 19,0,186,1,49,38,1,2,139,0,49,1  ; n1452 t=357.171s dur=442ms, freq=139Hz, sample=49, buffer_id=01:31
    db 4,0,7,1,56,39,1,3,208,0,56,1  ; n1453 t=357.190s dur=263ms, freq=208Hz, sample=56, buffer_id=01:38
    db 125,1,232,0,65,39,1,6,93,1,65,1  ; n1454 t=357.194s dur=232ms, freq=349Hz, sample=65, buffer_id=01:41
; t 357.2183 Sustain 0 (Instr 1)
; t 357.2183 Sustain 0 (Instr 2)
    db 36,0,253,5,48,44,1,0,131,0,48,1  ; n1455 t=357.575s dur=1533ms, freq=131Hz, sample=48, buffer_id=01:30
    db 24,0,250,4,56,44,1,3,208,0,56,1  ; n1456 t=357.611s dur=1274ms, freq=208Hz, sample=56, buffer_id=01:38
    db 3,0,216,4,66,45,1,4,114,1,66,1  ; n1457 t=357.636s dur=1240ms, freq=370Hz, sample=66, buffer_id=01:42
    db 48,4,213,4,75,64,2,5,110,2,75,1  ; n1458 t=357.639s dur=1237ms, freq=622Hz, sample=75, buffer_id=01:4B
; t 358.1388 Sustain 127 (Instr 1)
; t 358.1388 Sustain 127 (Instr 2)
    db 6,0,225,2,66,37,1,4,114,1,66,1  ; n1459 t=358.711s dur=737ms, freq=370Hz, sample=66, buffer_id=01:42
    db 109,1,246,2,63,38,1,1,55,1,63,1  ; n1460 t=358.717s dur=758ms, freq=311Hz, sample=63, buffer_id=01:3F
; t 358.8765 Sustain 0 (Instr 1)
; t 358.8765 Sustain 0 (Instr 2)
; t 358.9473 Soft 127 (Instr 1)
; t 358.9473 Soft 127 (Instr 2)
    db 18,0,143,2,49,34,1,2,139,0,49,1  ; n1461 t=359.082s dur=655ms, freq=139Hz, sample=49, buffer_id=01:31
    db 49,1,251,1,56,34,1,3,208,0,56,1  ; n1462 t=359.099s dur=507ms, freq=208Hz, sample=56, buffer_id=01:38
    db 97,0,162,0,61,33,1,0,21,1,61,1  ; n1463 t=359.405s dur=162ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 239,0,125,1,65,42,1,5,93,1,65,1  ; n1464 t=359.502s dur=381ms, freq=349Hz, sample=65, buffer_id=01:41
    db 92,0,100,1,42,35,1,1,92,0,42,1  ; n1465 t=359.741s dur=356ms, freq=92Hz, sample=42, buffer_id=01:2A
    db 7,0,12,2,58,36,1,0,233,0,58,1  ; n1466 t=359.833s dur=524ms, freq=233Hz, sample=58, buffer_id=01:3A
    db 72,0,75,1,54,36,1,3,185,0,54,1  ; n1467 t=359.840s dur=331ms, freq=185Hz, sample=54, buffer_id=01:36
    db 195,0,223,0,70,43,2,4,210,1,70,1  ; n1468 t=359.912s dur=223ms, freq=466Hz, sample=70, buffer_id=01:46
    db 36,0,45,1,51,33,1,2,156,0,51,1  ; n1469 t=360.108s dur=301ms, freq=156Hz, sample=51, buffer_id=01:33
    db 207,0,8,1,66,38,1,5,114,1,66,1  ; n1470 t=360.144s dur=264ms, freq=370Hz, sample=66, buffer_id=01:42
    db 19,0,194,1,44,34,1,1,104,0,44,1  ; n1471 t=360.351s dur=450ms, freq=104Hz, sample=44, buffer_id=01:2C
    db 87,0,12,2,56,35,1,4,208,0,56,1  ; n1472 t=360.370s dur=524ms, freq=208Hz, sample=56, buffer_id=01:38
    db 5,0,82,1,61,40,1,3,21,1,61,1  ; n1473 t=360.457s dur=338ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 69,1,130,1,65,41,1,6,93,1,65,1  ; n1474 t=360.462s dur=386ms, freq=349Hz, sample=65, buffer_id=01:41
    db 5,0,75,0,60,40,1,0,6,1,60,1  ; n1475 t=360.787s dur=75ms, freq=262Hz, sample=60, buffer_id=01:3C
    db 224,0,88,0,63,40,1,2,55,1,63,1  ; n1476 t=360.793s dur=88ms, freq=311Hz, sample=63, buffer_id=01:3F
    db 6,0,182,0,53,38,1,1,175,0,53,1  ; n1477 t=361.017s dur=182ms, freq=175Hz, sample=53, buffer_id=01:35
    db 49,0,146,0,56,38,1,4,208,0,56,1  ; n1478 t=361.023s dur=146ms, freq=208Hz, sample=56, buffer_id=01:38
    db 1,0,15,1,73,41,2,0,42,2,73,1  ; n1479 t=361.071s dur=271ms, freq=554Hz, sample=73, buffer_id=01:49
    db 213,0,247,0,61,39,1,3,21,1,61,1  ; n1480 t=361.072s dur=247ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 7,0,60,2,51,42,1,2,156,0,51,1  ; n1481 t=361.286s dur=572ms, freq=156Hz, sample=51, buffer_id=01:33
    db 67,0,53,2,56,42,1,4,208,0,56,1  ; n1482 t=361.293s dur=565ms, freq=208Hz, sample=56, buffer_id=01:38
    db 7,0,242,1,72,44,2,5,11,2,72,1  ; n1483 t=361.360s dur=498ms, freq=523Hz, sample=72, buffer_id=01:48
    db 161,1,235,1,60,41,1,6,6,1,60,1  ; n1484 t=361.367s dur=491ms, freq=262Hz, sample=60, buffer_id=01:3C
; t 361.4539 Sustain 127 (Instr 1)
; t 361.4539 Sustain 127 (Instr 2)
; t 361.4877 Soft 0 (Instr 1)
; t 361.4877 Soft 0 (Instr 2)
    db 5,0,164,0,55,35,1,0,196,0,55,1  ; n1485 t=361.784s dur=164ms, freq=196Hz, sample=55, buffer_id=01:37
    db 1,0,0,1,70,40,2,1,210,1,70,1  ; n1486 t=361.790s dur=256ms, freq=466Hz, sample=70, buffer_id=01:46
    db 0,0,69,0,58,35,1,3,233,0,58,1  ; n1487 t=361.791s dur=69ms, freq=233Hz, sample=58, buffer_id=01:3A
    db 229,0,114,0,49,35,1,7,139,0,49,1  ; n1488 t=361.791s dur=114ms, freq=139Hz, sample=49, buffer_id=01:31
; t 361.8585 Sustain 0 (Instr 1)
; t 361.8585 Sustain 0 (Instr 2)
    db 13,0,77,0,48,33,1,8,131,0,48,1  ; n1489 t=362.020s dur=77ms, freq=131Hz, sample=48, buffer_id=01:30
    db 23,0,115,0,60,33,1,6,6,1,60,1  ; n1490 t=362.033s dur=115ms, freq=262Hz, sample=60, buffer_id=01:3C
    db 2,0,106,0,75,43,2,9,110,2,75,1  ; n1491 t=362.056s dur=106ms, freq=622Hz, sample=75, buffer_id=01:4B
    db 131,1,95,0,63,33,1,2,55,1,63,1  ; n1492 t=362.058s dur=95ms, freq=311Hz, sample=63, buffer_id=01:3F
    db 5,0,112,0,49,34,1,0,139,0,49,1  ; n1493 t=362.445s dur=112ms, freq=139Hz, sample=49, buffer_id=01:31
    db 41,0,81,0,58,34,1,1,233,0,58,1  ; n1494 t=362.450s dur=81ms, freq=233Hz, sample=58, buffer_id=01:3A
    db 1,0,105,1,73,45,2,2,42,2,73,1  ; n1495 t=362.491s dur=361ms, freq=554Hz, sample=73, buffer_id=01:49
    db 185,0,230,0,65,34,1,3,93,1,65,1  ; n1496 t=362.492s dur=230ms, freq=349Hz, sample=65, buffer_id=01:41
    db 1,0,89,0,51,37,1,4,156,0,51,1  ; n1497 t=362.677s dur=89ms, freq=156Hz, sample=51, buffer_id=01:33
    db 24,0,95,0,63,37,1,5,55,1,63,1  ; n1498 t=362.678s dur=95ms, freq=311Hz, sample=63, buffer_id=01:3F
    db 189,0,6,1,68,42,2,6,159,1,68,1  ; n1499 t=362.703s dur=262ms, freq=415Hz, sample=68, buffer_id=01:44
    db 219,0,251,0,72,40,2,0,11,2,72,1  ; n1500 t=362.892s dur=251ms, freq=523Hz, sample=72, buffer_id=01:48
    db 1,0,158,0,51,34,1,1,156,0,51,1  ; n1501 t=363.110s dur=158ms, freq=156Hz, sample=51, buffer_id=01:33
    db 10,0,125,0,61,34,1,2,21,1,61,1  ; n1502 t=363.111s dur=125ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 14,0,171,1,70,43,2,3,210,1,70,1  ; n1503 t=363.121s dur=427ms, freq=466Hz, sample=70, buffer_id=01:46
    db 169,0,232,0,67,43,2,4,136,1,67,1  ; n1504 t=363.135s dur=232ms, freq=392Hz, sample=67, buffer_id=01:43
    db 13,0,115,0,60,34,1,5,6,1,60,1  ; n1505 t=363.304s dur=115ms, freq=262Hz, sample=60, buffer_id=01:3C
    db 167,0,151,0,56,33,1,6,208,0,56,1  ; n1506 t=363.316s dur=151ms, freq=208Hz, sample=56, buffer_id=01:38
    db 206,0,158,0,68,39,2,0,159,1,68,1  ; n1507 t=363.483s dur=158ms, freq=415Hz, sample=68, buffer_id=01:44
    db 17,0,217,0,58,35,1,1,233,0,58,1  ; n1508 t=363.689s dur=217ms, freq=233Hz, sample=58, buffer_id=01:3A
    db 7,0,176,0,78,40,2,2,228,2,78,1  ; n1509 t=363.706s dur=176ms, freq=740Hz, sample=78, buffer_id=01:4E
    db 13,0,95,0,61,35,1,4,21,1,61,1  ; n1510 t=363.714s dur=95ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 180,0,174,0,66,35,1,5,114,1,66,1  ; n1511 t=363.726s dur=174ms, freq=370Hz, sample=66, buffer_id=01:42
    db 6,0,116,1,61,38,1,4,21,1,61,1  ; n1512 t=363.906s dur=372ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 48,0,145,1,56,38,1,0,208,0,56,1  ; n1513 t=363.912s dur=401ms, freq=208Hz, sample=56, buffer_id=01:38
    db 0,0,63,1,65,38,1,3,93,1,65,1  ; n1514 t=363.960s dur=319ms, freq=349Hz, sample=65, buffer_id=01:41
    db 105,1,63,1,77,43,2,6,186,2,77,1  ; n1515 t=363.960s dur=319ms, freq=698Hz, sample=77, buffer_id=01:4D
; t 364.0232 Sustain 127 (Instr 1)
; t 364.0232 Sustain 127 (Instr 2)
; t 364.2788 Sustain 0 (Instr 1)
; t 364.2788 Sustain 0 (Instr 2)
    db 1,0,139,0,54,38,1,1,185,0,54,1  ; n1516 t=364.321s dur=139ms, freq=185Hz, sample=54, buffer_id=01:36
    db 10,0,107,0,60,38,1,2,6,1,60,1  ; n1517 t=364.322s dur=107ms, freq=262Hz, sample=60, buffer_id=01:3C
    db 3,0,164,0,75,39,2,5,110,2,75,1  ; n1518 t=364.332s dur=164ms, freq=622Hz, sample=75, buffer_id=01:4B
    db 154,0,119,0,63,38,1,7,55,1,63,1  ; n1519 t=364.335s dur=119ms, freq=311Hz, sample=63, buffer_id=01:3F
    db 35,0,208,1,53,40,1,3,175,0,53,1  ; n1520 t=364.489s dur=464ms, freq=175Hz, sample=53, buffer_id=01:35
    db 17,0,173,1,61,41,1,0,21,1,61,1  ; n1521 t=364.524s dur=429ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 2,0,156,1,80,47,2,4,63,3,80,1  ; n1522 t=364.541s dur=412ms, freq=831Hz, sample=80, buffer_id=01:50
    db 183,1,154,1,68,47,2,6,159,1,68,1  ; n1523 t=364.543s dur=410ms, freq=415Hz, sample=68, buffer_id=01:44
; t 364.5977 Sustain 127 (Instr 1)
; t 364.5977 Sustain 127 (Instr 2)
; t 364.9536 Sustain 0 (Instr 1)
; t 364.9536 Sustain 0 (Instr 2)
    db 12,0,165,1,66,43,1,1,114,1,66,1  ; n1524 t=364.982s dur=421ms, freq=370Hz, sample=66, buffer_id=01:42
    db 2,0,153,1,78,56,2,2,228,2,78,1  ; n1525 t=364.994s dur=409ms, freq=740Hz, sample=78, buffer_id=01:4E
    db 13,0,144,0,58,43,1,5,233,0,58,1  ; n1526 t=364.996s dur=144ms, freq=233Hz, sample=58, buffer_id=01:3A
    db 193,0,95,0,61,44,1,0,21,1,61,1  ; n1527 t=365.009s dur=95ms, freq=277Hz, sample=61, buffer_id=01:3D
; t 365.1765 Sustain 127 (Instr 1)
; t 365.1765 Sustain 127 (Instr 2)
    db 6,0,2,1,61,46,1,0,21,1,61,1  ; n1528 t=365.202s dur=258ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 156,0,122,1,56,46,1,3,208,0,56,1  ; n1529 t=365.208s dur=378ms, freq=208Hz, sample=56, buffer_id=01:38
    db 17,0,119,0,77,53,2,4,186,2,77,1  ; n1530 t=365.364s dur=119ms, freq=698Hz, sample=77, buffer_id=01:4D
    db 171,0,83,0,65,44,1,5,93,1,65,1  ; n1531 t=365.381s dur=83ms, freq=349Hz, sample=65, buffer_id=01:41
; t 365.4035 Sustain 0 (Instr 1)
; t 365.4035 Sustain 0 (Instr 2)
    db 0,0,96,0,60,44,1,6,6,1,60,1  ; n1532 t=365.552s dur=96ms, freq=262Hz, sample=60, buffer_id=01:3C
    db 11,0,164,0,54,44,1,7,185,0,54,1  ; n1533 t=365.552s dur=164ms, freq=185Hz, sample=54, buffer_id=01:36
    db 8,0,138,0,75,56,2,8,110,2,75,1  ; n1534 t=365.563s dur=138ms, freq=622Hz, sample=75, buffer_id=01:4B
    db 117,0,101,0,63,44,1,9,55,1,63,1  ; n1535 t=365.571s dur=101ms, freq=311Hz, sample=63, buffer_id=01:3F
    db 38,0,199,0,53,46,1,0,175,0,53,1  ; n1536 t=365.689s dur=199ms, freq=175Hz, sample=53, buffer_id=01:35
    db 35,0,198,0,61,47,1,1,21,1,61,1  ; n1537 t=365.727s dur=198ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 4,0,0,1,68,66,2,2,159,1,68,1  ; n1538 t=365.762s dur=256ms, freq=415Hz, sample=68, buffer_id=01:44
    db 112,1,239,0,80,67,2,4,63,3,80,1  ; n1539 t=365.766s dur=239ms, freq=831Hz, sample=80, buffer_id=01:50
    db 2,0,30,1,78,66,2,0,228,2,78,1  ; n1540 t=366.133s dur=286ms, freq=740Hz, sample=78, buffer_id=01:4E
    db 18,0,100,0,58,52,1,1,233,0,58,1  ; n1541 t=366.135s dur=100ms, freq=233Hz, sample=58, buffer_id=01:3A
    db 18,0,87,0,61,52,1,3,21,1,61,1  ; n1542 t=366.153s dur=87ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 144,0,3,1,66,53,1,5,114,1,66,1  ; n1543 t=366.171s dur=259ms, freq=370Hz, sample=66, buffer_id=01:42
    db 5,0,213,1,61,55,1,3,21,1,61,1  ; n1544 t=366.315s dur=469ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 184,0,208,1,56,54,1,2,208,0,56,1  ; n1545 t=366.320s dur=464ms, freq=208Hz, sample=56, buffer_id=01:38
    db 13,0,24,1,77,70,2,1,186,2,77,1  ; n1546 t=366.504s dur=280ms, freq=698Hz, sample=77, buffer_id=01:4D
    db 112,0,12,1,65,52,1,4,93,1,65,1  ; n1547 t=366.517s dur=268ms, freq=349Hz, sample=65, buffer_id=01:41
; t 366.5240 Sustain 127 (Instr 1)
; t 366.5240 Sustain 127 (Instr 2)
    db 67,0,101,3,55,61,1,0,196,0,55,1  ; n1548 t=366.628s dur=869ms, freq=196Hz, sample=55, buffer_id=01:37
    db 31,0,101,2,61,62,1,3,21,1,61,1  ; n1549 t=366.695s dur=613ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 98,0,133,2,64,62,1,5,74,1,64,1  ; n1550 t=366.726s dur=645ms, freq=330Hz, sample=64, buffer_id=01:40
; t 366.7848 Sustain 0 (Instr 1)
; t 366.7848 Sustain 0 (Instr 2)
    db 14,0,8,6,82,80,2,6,164,3,82,1  ; n1551 t=366.824s dur=1544ms, freq=932Hz, sample=82, buffer_id=01:52
    db 140,2,133,5,70,83,2,7,210,1,70,1  ; n1552 t=366.838s dur=1413ms, freq=466Hz, sample=70, buffer_id=01:46
; t 367.1079 Soft 127 (Instr 1)
; t 367.1079 Soft 127 (Instr 2)
    db 6,0,237,4,61,55,1,3,21,1,61,1  ; n1553 t=367.489s dur=1261ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 3,0,27,5,56,55,1,1,208,0,56,1  ; n1554 t=367.495s dur=1307ms, freq=208Hz, sample=56, buffer_id=01:38
    db 43,3,147,4,65,55,1,2,93,1,65,1  ; n1555 t=367.499s dur=1171ms, freq=349Hz, sample=65, buffer_id=01:41
    db 14,0,142,1,80,50,2,0,63,3,80,1  ; n1556 t=368.310s dur=398ms, freq=831Hz, sample=80, buffer_id=01:50
    db 103,4,147,1,68,50,2,4,159,1,68,1  ; n1557 t=368.323s dur=403ms, freq=415Hz, sample=68, buffer_id=01:44
    db 24,0,244,5,32,34,1,0,52,0,32,1  ; n1558 t=369.451s dur=1524ms, freq=52Hz, sample=32, buffer_id=01:20
    db 144,0,114,5,44,35,1,1,104,0,44,1  ; n1559 t=369.475s dur=1394ms, freq=104Hz, sample=44, buffer_id=01:2C
    db 7,0,177,4,54,37,1,2,185,0,54,1  ; n1560 t=369.619s dur=1201ms, freq=185Hz, sample=54, buffer_id=01:36
    db 138,3,209,3,60,37,1,3,6,1,60,1  ; n1561 t=369.626s dur=977ms, freq=262Hz, sample=60, buffer_id=01:3C
    db 12,1,37,1,63,38,1,4,55,1,63,1  ; n1562 t=370.532s dur=293ms, freq=311Hz, sample=63, buffer_id=01:3F
    db 173,0,37,1,61,36,1,5,21,1,61,1  ; n1563 t=370.800s dur=293ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 31,0,148,3,37,33,1,3,69,0,37,1  ; n1564 t=370.973s dur=916ms, freq=69Hz, sample=37, buffer_id=01:25
    db 177,0,91,3,44,33,1,1,104,0,44,1  ; n1565 t=371.003s dur=859ms, freq=104Hz, sample=44, buffer_id=01:2C
    db 5,0,157,2,61,35,1,5,21,1,61,1  ; n1566 t=371.181s dur=669ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 122,5,78,2,53,35,1,0,175,0,53,1  ; n1567 t=371.186s dur=590ms, freq=175Hz, sample=53, buffer_id=01:35
; t 371.2199 Soft 0 (Instr 1)
; t 371.2199 Soft 0 (Instr 2)
    db 4,0,198,3,53,45,1,0,175,0,53,1  ; n1568 t=372.588s dur=966ms, freq=175Hz, sample=53, buffer_id=01:35
    db 138,1,194,3,65,45,1,1,93,1,65,1  ; n1569 t=372.592s dur=962ms, freq=349Hz, sample=65, buffer_id=01:41
; t 372.9106 Sustain 127 (Instr 1)
; t 372.9106 Sustain 127 (Instr 2)
    db 12,0,106,3,37,50,1,2,69,0,37,1  ; n1570 t=372.986s dur=874ms, freq=69Hz, sample=37, buffer_id=01:25
    db 111,2,120,10,44,50,1,3,104,0,44,1  ; n1571 t=372.997s dur=2680ms, freq=104Hz, sample=44, buffer_id=01:2C
; t 373.5543 Sustain 0 (Instr 1)
; t 373.5543 Sustain 0 (Instr 2)
    db 7,0,91,3,66,55,1,4,114,1,66,1  ; n1572 t=373.620s dur=859ms, freq=370Hz, sample=66, buffer_id=01:42
    db 255,0,84,3,54,55,1,5,185,0,54,1  ; n1573 t=373.627s dur=852ms, freq=185Hz, sample=54, buffer_id=01:36
; t 373.8624 Sustain 127 (Instr 1)
; t 373.8624 Sustain 127 (Instr 2)
    db 56,2,178,3,39,55,1,0,78,0,39,1  ; n1574 t=373.882s dur=946ms, freq=78Hz, sample=39, buffer_id=01:27
    db 4,0,122,1,63,55,1,1,55,1,63,1  ; n1575 t=374.450s dur=378ms, freq=311Hz, sample=63, buffer_id=01:3F
    db 201,0,118,1,75,52,2,2,110,2,75,1  ; n1576 t=374.454s dur=374ms, freq=622Hz, sample=75, buffer_id=01:4B
; t 374.4797 Sustain 0 (Instr 1)
; t 374.4797 Sustain 0 (Instr 2)
    db 219,0,55,2,42,55,1,6,92,0,42,1  ; n1577 t=374.655s dur=567ms, freq=92Hz, sample=42, buffer_id=01:2A
; t 374.6601 Sustain 127 (Instr 1)
; t 374.6601 Sustain 127 (Instr 2)
; t 374.8289 Sustain 0 (Instr 1)
; t 374.8289 Sustain 0 (Instr 2)
    db 3,0,109,0,72,46,2,4,11,2,72,1  ; n1578 t=374.874s dur=109ms, freq=523Hz, sample=72, buffer_id=01:48
    db 198,0,115,0,60,55,1,5,6,1,60,1  ; n1579 t=374.877s dur=115ms, freq=262Hz, sample=60, buffer_id=01:3C
; t 375.0094 Sustain 127 (Instr 1)
; t 375.0094 Sustain 127 (Instr 2)
; t 375.0368 Soft 127 (Instr 1)
; t 375.0368 Soft 127 (Instr 2)
    db 8,0,113,0,68,44,2,0,159,1,68,1  ; n1580 t=375.076s dur=113ms, freq=415Hz, sample=68, buffer_id=01:44
    db 110,0,105,0,56,55,1,1,208,0,56,1  ; n1581 t=375.084s dur=105ms, freq=208Hz, sample=56, buffer_id=01:38
; t 375.1898 Sustain 0 (Instr 1)
; t 375.1898 Sustain 0 (Instr 2)
    db 88,0,191,1,41,55,1,2,87,0,41,1  ; n1582 t=375.194s dur=447ms, freq=87Hz, sample=41, buffer_id=01:29
    db 13,0,162,0,73,47,2,4,42,2,73,1  ; n1583 t=375.282s dur=162ms, freq=554Hz, sample=73, buffer_id=01:49
    db 217,0,119,0,61,55,1,5,21,1,61,1  ; n1584 t=375.294s dur=119ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 12,0,76,0,77,44,2,0,186,2,77,1  ; n1585 t=375.512s dur=76ms, freq=698Hz, sample=77, buffer_id=01:4D
    db 60,1,64,0,65,55,1,1,93,1,65,1  ; n1586 t=375.523s dur=64ms, freq=349Hz, sample=65, buffer_id=01:41
    db 4,0,198,2,53,55,1,0,175,0,53,1  ; n1587 t=375.839s dur=710ms, freq=175Hz, sample=53, buffer_id=01:35
    db 177,0,194,2,65,55,1,1,93,1,65,1  ; n1588 t=375.843s dur=706ms, freq=349Hz, sample=65, buffer_id=01:41
; t 375.8724 Soft 0 (Instr 1)
; t 375.8724 Soft 0 (Instr 2)
    db 16,0,31,3,37,55,1,2,69,0,37,1  ; n1589 t=376.020s dur=799ms, freq=69Hz, sample=37, buffer_id=01:25
    db 13,2,207,7,44,55,1,3,104,0,44,1  ; n1590 t=376.036s dur=1999ms, freq=104Hz, sample=44, buffer_id=01:2C
; t 376.0359 Sustain 127 (Instr 1)
; t 376.0359 Sustain 127 (Instr 2)
; t 376.5496 Sustain 0 (Instr 1)
; t 376.5496 Sustain 0 (Instr 2)
    db 20,0,104,3,66,55,1,4,114,1,66,1  ; n1591 t=376.561s dur=872ms, freq=370Hz, sample=66, buffer_id=01:42
    db 242,0,84,3,54,55,1,5,185,0,54,1  ; n1592 t=376.581s dur=852ms, freq=185Hz, sample=54, buffer_id=01:36
    db 245,1,250,2,39,55,1,0,78,0,39,1  ; n1593 t=376.823s dur=762ms, freq=78Hz, sample=39, buffer_id=01:27
; t 376.8861 Sustain 127 (Instr 1)
; t 376.8861 Sustain 127 (Instr 2)
; t 377.2647 Soft 127 (Instr 1)
; t 377.2647 Soft 127 (Instr 2)
    db 2,0,199,2,78,50,2,1,228,2,78,1  ; n1594 t=377.324s dur=711ms, freq=740Hz, sample=78, buffer_id=01:4E
    db 237,0,197,2,66,55,1,4,114,1,66,1  ; n1595 t=377.326s dur=709ms, freq=370Hz, sample=66, buffer_id=01:42
; t 377.4335 Sustain 0 (Instr 1)
; t 377.4335 Sustain 0 (Instr 2)
    db 240,0,81,2,32,55,1,2,52,0,32,1  ; n1596 t=377.563s dur=593ms, freq=52Hz, sample=32, buffer_id=01:20
    db 8,0,233,0,82,44,2,0,164,3,82,1  ; n1597 t=377.803s dur=233ms, freq=932Hz, sample=82, buffer_id=01:52
; t 377.8069 Sustain 127 (Instr 1)
; t 377.8069 Sustain 127 (Instr 2)
    db 224,0,224,0,70,44,2,5,210,1,70,1  ; n1598 t=377.811s dur=224ms, freq=466Hz, sample=70, buffer_id=01:46
    db 62,0,108,0,44,55,1,3,104,0,44,1  ; n1599 t=378.035s dur=108ms, freq=104Hz, sample=44, buffer_id=01:2C
; t 378.0358 Sustain 0 (Instr 1)
; t 378.0358 Sustain 0 (Instr 2)
    db 4,0,96,0,60,55,1,6,6,1,60,1  ; n1600 t=378.097s dur=96ms, freq=262Hz, sample=60, buffer_id=01:3C
    db 121,0,101,0,72,46,2,7,11,2,72,1  ; n1601 t=378.101s dur=101ms, freq=523Hz, sample=72, buffer_id=01:48
    db 29,0,57,2,37,55,1,8,69,0,37,1  ; n1602 t=378.223s dur=569ms, freq=69Hz, sample=37, buffer_id=01:25
    db 63,0,27,2,44,55,1,3,104,0,44,1  ; n1603 t=378.252s dur=539ms, freq=104Hz, sample=44, buffer_id=01:2C
    db 10,0,220,1,63,55,1,0,55,1,63,1  ; n1604 t=378.315s dur=476ms, freq=311Hz, sample=63, buffer_id=01:3F
    db 194,0,211,1,75,49,2,1,110,2,75,1  ; n1605 t=378.325s dur=467ms, freq=622Hz, sample=75, buffer_id=01:4B
; t 378.4007 Sustain 127 (Instr 1)
; t 378.4007 Sustain 127 (Instr 2)
    db 10,0,17,1,61,55,1,2,21,1,61,1  ; n1606 t=378.519s dur=273ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 240,0,7,1,73,46,2,4,42,2,73,1  ; n1607 t=378.528s dur=263ms, freq=554Hz, sample=73, buffer_id=01:49
; t 378.5705 Soft 0 (Instr 1)
; t 378.5705 Soft 0 (Instr 2)
    db 4,0,29,3,53,55,1,5,175,0,53,1  ; n1608 t=378.768s dur=797ms, freq=175Hz, sample=53, buffer_id=01:35
    db 247,0,25,3,65,55,1,6,93,1,65,1  ; n1609 t=378.772s dur=793ms, freq=349Hz, sample=65, buffer_id=01:41
; t 378.7920 Sustain 0 (Instr 1)
; t 378.7920 Sustain 0 (Instr 2)
    db 4,0,225,2,37,55,1,0,69,0,37,1  ; n1610 t=379.019s dur=737ms, freq=69Hz, sample=37, buffer_id=01:25
    db 4,2,206,9,44,55,1,1,104,0,44,1  ; n1611 t=379.023s dur=2510ms, freq=104Hz, sample=44, buffer_id=01:2C
; t 379.0420 Sustain 127 (Instr 1)
; t 379.0420 Sustain 127 (Instr 2)
    db 14,0,196,2,66,55,1,2,114,1,66,1  ; n1612 t=379.539s dur=708ms, freq=370Hz, sample=66, buffer_id=01:42
    db 208,0,182,2,54,55,1,3,185,0,54,1  ; n1613 t=379.553s dur=694ms, freq=185Hz, sample=54, buffer_id=01:36
; t 379.5651 Sustain 0 (Instr 1)
; t 379.5651 Sustain 0 (Instr 2)
    db 237,1,99,3,39,55,1,4,78,0,39,1  ; n1614 t=379.760s dur=867ms, freq=78Hz, sample=39, buffer_id=01:27
; t 379.8319 Sustain 127 (Instr 1)
; t 379.8319 Sustain 127 (Instr 2)
; t 380.2473 Sustain 0 (Instr 1)
; t 380.2473 Sustain 0 (Instr 2)
    db 11,0,118,1,63,55,1,0,55,1,63,1  ; n1615 t=380.254s dur=374ms, freq=311Hz, sample=63, buffer_id=01:3F
    db 201,0,107,1,75,51,2,5,110,2,75,1  ; n1616 t=380.264s dur=363ms, freq=622Hz, sample=75, buffer_id=01:4B
; t 380.4529 Sustain 127 (Instr 1)
; t 380.4529 Sustain 127 (Instr 2)
    db 172,0,12,2,42,55,1,2,92,0,42,1  ; n1617 t=380.466s dur=524ms, freq=92Hz, sample=42, buffer_id=01:2A
; t 380.5731 Soft 127 (Instr 1)
; t 380.5731 Soft 127 (Instr 2)
; t 380.6279 Sustain 0 (Instr 1)
; t 380.6279 Sustain 0 (Instr 2)
    db 8,0,94,0,72,46,2,3,11,2,72,1  ; n1618 t=380.637s dur=94ms, freq=523Hz, sample=72, buffer_id=01:48
    db 209,0,100,0,60,55,1,6,6,1,60,1  ; n1619 t=380.646s dur=100ms, freq=262Hz, sample=60, buffer_id=01:3C
    db 2,0,108,0,68,44,2,0,159,1,68,1  ; n1620 t=380.855s dur=108ms, freq=415Hz, sample=68, buffer_id=01:44
    db 104,0,70,0,56,55,1,4,208,0,56,1  ; n1621 t=380.857s dur=70ms, freq=208Hz, sample=56, buffer_id=01:38
    db 107,0,60,2,41,55,1,3,87,0,41,1  ; n1622 t=380.961s dur=572ms, freq=87Hz, sample=41, buffer_id=01:29
    db 3,0,75,0,61,55,1,5,21,1,61,1  ; n1623 t=381.068s dur=75ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 180,0,114,0,73,47,2,6,42,2,73,1  ; n1624 t=381.071s dur=114ms, freq=554Hz, sample=73, buffer_id=01:49
; t 381.2152 Sustain 127 (Instr 1)
; t 381.2152 Sustain 127 (Instr 2)
    db 1,0,26,1,77,45,2,0,186,2,77,1  ; n1625 t=381.251s dur=282ms, freq=698Hz, sample=77, buffer_id=01:4D
    db 31,1,25,1,65,55,1,2,93,1,65,1  ; n1626 t=381.252s dur=281ms, freq=349Hz, sample=65, buffer_id=01:41
; t 381.3649 Soft 0 (Instr 1)
; t 381.3649 Soft 0 (Instr 2)
; t 381.5336 Sustain 0 (Instr 1)
; t 381.5336 Sustain 0 (Instr 2)
    db 10,0,200,2,53,55,1,4,175,0,53,1  ; n1627 t=381.539s dur=712ms, freq=175Hz, sample=53, buffer_id=01:35
    db 153,0,190,2,65,55,1,2,93,1,65,1  ; n1628 t=381.549s dur=702ms, freq=349Hz, sample=65, buffer_id=01:41
    db 16,0,227,2,37,55,1,5,69,0,37,1  ; n1629 t=381.702s dur=739ms, freq=69Hz, sample=37, buffer_id=01:25
    db 234,1,142,7,44,55,1,1,104,0,44,1  ; n1630 t=381.718s dur=1934ms, freq=104Hz, sample=44, buffer_id=01:2C
; t 381.7561 Sustain 127 (Instr 1)
; t 381.7561 Sustain 127 (Instr 2)
    db 25,0,227,2,66,55,1,0,114,1,66,1  ; n1631 t=382.208s dur=739ms, freq=370Hz, sample=66, buffer_id=01:42
    db 212,0,201,2,54,55,1,3,185,0,54,1  ; n1632 t=382.234s dur=713ms, freq=185Hz, sample=54, buffer_id=01:36
; t 382.2516 Sustain 0 (Instr 1)
; t 382.2516 Sustain 0 (Instr 2)
    db 225,1,197,2,39,55,1,6,78,0,39,1  ; n1633 t=382.446s dur=709ms, freq=78Hz, sample=39, buffer_id=01:27
; t 382.4973 Sustain 127 (Instr 1)
; t 382.4973 Sustain 127 (Instr 2)
    db 1,0,214,2,78,51,2,2,228,2,78,1  ; n1634 t=382.926s dur=726ms, freq=740Hz, sample=78, buffer_id=01:4E
    db 232,0,213,2,66,55,1,0,114,1,66,1  ; n1635 t=382.927s dur=725ms, freq=370Hz, sample=66, buffer_id=01:42
; t 382.9475 Sustain 0 (Instr 1)
; t 382.9475 Sustain 0 (Instr 2)
    db 220,0,52,2,32,55,1,3,52,0,32,1  ; n1636 t=383.159s dur=564ms, freq=52Hz, sample=32, buffer_id=01:20
; t 383.3576 Sustain 127 (Instr 1)
; t 383.3576 Sustain 127 (Instr 2)
    db 3,0,16,1,70,45,2,4,210,1,70,1  ; n1637 t=383.380s dur=272ms, freq=466Hz, sample=70, buffer_id=01:46
    db 226,0,13,1,82,45,2,5,164,3,82,1  ; n1638 t=383.383s dur=269ms, freq=932Hz, sample=82, buffer_id=01:52
    db 55,0,103,0,44,55,1,1,104,0,44,1  ; n1639 t=383.608s dur=103ms, freq=104Hz, sample=44, buffer_id=01:2C
; t 383.6527 Sustain 0 (Instr 1)
; t 383.6527 Sustain 0 (Instr 2)
    db 15,0,127,0,72,43,2,6,11,2,72,1  ; n1640 t=383.663s dur=127ms, freq=523Hz, sample=72, buffer_id=01:48
    db 112,0,70,0,60,55,1,7,6,1,60,1  ; n1641 t=383.678s dur=70ms, freq=262Hz, sample=60, buffer_id=01:3C
    db 50,0,231,1,37,55,1,8,69,0,37,1  ; n1642 t=383.790s dur=487ms, freq=69Hz, sample=37, buffer_id=01:25
    db 46,0,182,1,44,55,1,1,104,0,44,1  ; n1643 t=383.839s dur=438ms, freq=104Hz, sample=44, buffer_id=01:2C
    db 2,0,135,1,75,46,2,0,110,2,75,1  ; n1644 t=383.886s dur=391ms, freq=622Hz, sample=75, buffer_id=01:4B
    db 191,0,133,1,63,55,1,2,55,1,63,1  ; n1645 t=383.888s dur=389ms, freq=311Hz, sample=63, buffer_id=01:3F
; t 383.8930 Sustain 127 (Instr 1)
; t 383.8930 Sustain 127 (Instr 2)
; t 384.0511 Soft 127 (Instr 1)
; t 384.0511 Soft 127 (Instr 2)
    db 10,0,199,0,61,55,1,3,21,1,61,1  ; n1646 t=384.079s dur=199ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 17,1,188,0,73,48,2,4,42,2,73,1  ; n1647 t=384.089s dur=188ms, freq=554Hz, sample=73, buffer_id=01:49
; t 384.2776 Sustain 0 (Instr 1)
; t 384.2776 Sustain 0 (Instr 2)
    db 1,0,42,3,77,52,2,5,186,2,77,1  ; n1648 t=384.362s dur=810ms, freq=698Hz, sample=77, buffer_id=01:4D
    db 6,1,41,3,65,55,1,6,93,1,65,1  ; n1649 t=384.363s dur=809ms, freq=349Hz, sample=65, buffer_id=01:41
    db 1,0,205,2,50,55,1,0,147,0,50,1  ; n1650 t=384.625s dur=717ms, freq=147Hz, sample=50, buffer_id=01:32
    db 233,1,93,2,56,55,1,1,208,0,56,1  ; n1651 t=384.627s dur=605ms, freq=208Hz, sample=56, buffer_id=01:38
; t 384.6950 Sustain 127 (Instr 1)
; t 384.6950 Sustain 127 (Instr 2)
    db 32,0,15,3,70,48,2,2,210,1,70,1  ; n1652 t=385.115s dur=783ms, freq=466Hz, sample=70, buffer_id=01:46
    db 224,0,239,2,58,55,1,3,233,0,58,1  ; n1653 t=385.147s dur=751ms, freq=233Hz, sample=58, buffer_id=01:3A
; t 385.1724 Sustain 0 (Instr 1)
; t 385.1724 Sustain 0 (Instr 2)
    db 6,0,222,2,49,55,1,4,139,0,49,1  ; n1654 t=385.371s dur=734ms, freq=139Hz, sample=49, buffer_id=01:31
    db 8,2,147,2,55,55,1,5,196,0,55,1  ; n1655 t=385.377s dur=659ms, freq=196Hz, sample=55, buffer_id=01:37
; t 385.5687 Sustain 127 (Instr 1)
; t 385.5687 Sustain 127 (Instr 2)
    db 7,0,234,2,75,45,2,0,110,2,75,1  ; n1656 t=385.897s dur=746ms, freq=622Hz, sample=75, buffer_id=01:4B
; t 385.8986 Sustain 0 (Instr 1)
; t 385.8986 Sustain 0 (Instr 2)
    db 198,0,226,2,63,55,1,1,55,1,63,1  ; n1657 t=385.904s dur=738ms, freq=311Hz, sample=63, buffer_id=01:3F
    db 4,0,248,2,54,55,1,2,185,0,54,1  ; n1658 t=386.102s dur=760ms, freq=185Hz, sample=54, buffer_id=01:36
    db 216,1,250,2,48,55,1,3,131,0,48,1  ; n1659 t=386.106s dur=762ms, freq=131Hz, sample=48, buffer_id=01:30
; t 386.1895 Sustain 127 (Instr 1)
; t 386.1895 Sustain 127 (Instr 2)
    db 14,0,133,3,68,43,2,4,159,1,68,1  ; n1660 t=386.578s dur=901ms, freq=415Hz, sample=68, buffer_id=01:44
    db 237,0,120,3,56,55,1,5,208,0,56,1  ; n1661 t=386.592s dur=888ms, freq=208Hz, sample=56, buffer_id=01:38
; t 386.6427 Sustain 0 (Instr 1)
; t 386.6427 Sustain 0 (Instr 2)
    db 6,0,139,2,47,55,1,6,123,0,47,1  ; n1662 t=386.829s dur=651ms, freq=123Hz, sample=47, buffer_id=01:2F
    db 231,1,132,2,53,55,1,7,175,0,53,1  ; n1663 t=386.836s dur=644ms, freq=175Hz, sample=53, buffer_id=01:35
; t 386.9915 Sustain 127 (Instr 1)
; t 386.9915 Sustain 127 (Instr 2)
    db 5,0,178,2,61,55,1,0,21,1,61,1  ; n1664 t=387.322s dur=690ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 188,0,172,2,73,42,2,1,42,2,73,1  ; n1665 t=387.328s dur=684ms, freq=554Hz, sample=73, buffer_id=01:49
; t 387.4803 Sustain 0 (Instr 1)
; t 387.4803 Sustain 0 (Instr 2)
    db 19,0,109,4,46,55,1,2,117,0,46,1  ; n1666 t=387.515s dur=1133ms, freq=117Hz, sample=46, buffer_id=01:2E
    db 221,1,49,10,49,55,1,3,139,0,49,1  ; n1667 t=387.534s dur=2609ms, freq=139Hz, sample=49, buffer_id=01:31
; t 387.6974 Sustain 127 (Instr 1)
; t 387.6974 Sustain 127 (Instr 2)
    db 5,0,125,2,54,55,1,4,185,0,54,1  ; n1668 t=388.011s dur=637ms, freq=185Hz, sample=54, buffer_id=01:36
; t 388.0124 Sustain 0 (Instr 1)
; t 388.0124 Sustain 0 (Instr 2)
    db 216,0,120,2,66,55,1,5,114,1,66,1  ; n1669 t=388.017s dur=632ms, freq=370Hz, sample=66, buffer_id=01:42
    db 170,1,146,2,44,55,1,0,104,0,44,1  ; n1670 t=388.233s dur=658ms, freq=104Hz, sample=44, buffer_id=01:2C
; t 388.2800 Sustain 127 (Instr 1)
; t 388.2800 Sustain 127 (Instr 2)
; t 388.6487 Sustain 0 (Instr 1)
; t 388.6487 Sustain 0 (Instr 2)
    db 18,0,49,1,53,55,1,1,175,0,53,1  ; n1671 t=388.658s dur=305ms, freq=175Hz, sample=53, buffer_id=01:35
    db 175,0,37,1,65,55,1,6,93,1,65,1  ; n1672 t=388.676s dur=293ms, freq=349Hz, sample=65, buffer_id=01:41
    db 178,0,37,1,37,55,1,2,69,0,37,1  ; n1673 t=388.851s dur=293ms, freq=69Hz, sample=37, buffer_id=01:25
    db 26,0,27,1,41,55,1,4,87,0,41,1  ; n1674 t=389.029s dur=283ms, freq=87Hz, sample=41, buffer_id=01:29
    db 19,0,54,1,68,43,2,5,159,1,68,1  ; n1675 t=389.055s dur=310ms, freq=415Hz, sample=68, buffer_id=01:44
    db 222,0,24,1,56,55,1,7,208,0,56,1  ; n1676 t=389.074s dur=280ms, freq=208Hz, sample=56, buffer_id=01:38
    db 17,0,31,1,44,55,1,0,104,0,44,1  ; n1677 t=389.297s dur=287ms, freq=104Hz, sample=44, buffer_id=01:2C
    db 14,0,5,2,71,46,2,1,238,1,71,1  ; n1678 t=389.313s dur=517ms, freq=494Hz, sample=71, buffer_id=01:47
    db 11,1,237,1,59,55,1,6,247,0,59,1  ; n1679 t=389.327s dur=493ms, freq=247Hz, sample=59, buffer_id=01:3B
    db 237,0,230,2,42,55,1,2,92,0,42,1  ; n1680 t=389.594s dur=742ms, freq=92Hz, sample=42, buffer_id=01:2A
    db 13,0,100,0,58,55,1,0,233,0,58,1  ; n1681 t=389.831s dur=100ms, freq=233Hz, sample=58, buffer_id=01:3A
    db 228,0,219,0,70,41,2,4,210,1,70,1  ; n1682 t=389.843s dur=219ms, freq=466Hz, sample=70, buffer_id=01:46
    db 2,0,100,1,73,44,2,1,42,2,73,1  ; n1683 t=390.071s dur=356ms, freq=554Hz, sample=73, buffer_id=01:49
    db 192,0,93,1,61,55,1,5,21,1,61,1  ; n1684 t=390.073s dur=349ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 44,0,105,3,46,55,1,0,117,0,46,1  ; n1685 t=390.265s dur=873ms, freq=117Hz, sample=46, buffer_id=01:2E
    db 24,2,204,11,49,55,1,3,139,0,49,1  ; n1686 t=390.309s dur=3020ms, freq=139Hz, sample=49, buffer_id=01:31
    db 0,0,16,3,66,55,1,1,114,1,66,1  ; n1687 t=390.845s dur=784ms, freq=370Hz, sample=66, buffer_id=01:42
    db 253,0,16,3,54,55,1,2,185,0,54,1  ; n1688 t=390.845s dur=784ms, freq=185Hz, sample=54, buffer_id=01:36
    db 248,1,9,3,44,55,1,4,104,0,44,1  ; n1689 t=391.098s dur=777ms, freq=104Hz, sample=44, buffer_id=01:2C
; t 391.2538 Sustain 127 (Instr 1)
; t 391.2538 Sustain 127 (Instr 2)
    db 7,0,69,3,65,55,1,0,93,1,65,1  ; n1690 t=391.602s dur=837ms, freq=349Hz, sample=65, buffer_id=01:41
    db 2,1,61,3,53,55,1,5,175,0,53,1  ; n1691 t=391.610s dur=829ms, freq=175Hz, sample=53, buffer_id=01:35
; t 391.6298 Sustain 0 (Instr 1)
; t 391.6298 Sustain 0 (Instr 2)
    db 10,2,60,3,43,55,1,1,98,0,43,1  ; n1692 t=391.868s dur=828ms, freq=98Hz, sample=43, buffer_id=01:2B
; t 392.0478 Sustain 127 (Instr 1)
; t 392.0478 Sustain 127 (Instr 2)
    db 10,0,171,3,64,55,1,2,74,1,64,1  ; n1693 t=392.390s dur=939ms, freq=330Hz, sample=64, buffer_id=01:40
    db 1,1,160,3,52,55,1,4,165,0,52,1  ; n1694 t=392.401s dur=928ms, freq=165Hz, sample=52, buffer_id=01:34
; t 392.4396 Sustain 0 (Instr 1)
; t 392.4396 Sustain 0 (Instr 2)
    db 3,2,48,3,44,55,1,0,104,0,44,1  ; n1695 t=392.658s dur=816ms, freq=104Hz, sample=44, buffer_id=01:2C
; t 392.6944 Soft 0 (Instr 1)
; t 392.6944 Soft 0 (Instr 2)
; t 392.7639 Sustain 127 (Instr 1)
; t 392.7639 Sustain 127 (Instr 2)
    db 0,0,98,3,53,55,1,1,175,0,53,1  ; n1696 t=393.173s dur=866ms, freq=175Hz, sample=53, buffer_id=01:35
    db 4,1,118,3,65,55,1,5,93,1,65,1  ; n1697 t=393.173s dur=886ms, freq=349Hz, sample=65, buffer_id=01:41
; t 393.3295 Sustain 0 (Instr 1)
; t 393.3295 Sustain 0 (Instr 2)
    db 37,0,48,4,46,55,1,6,117,0,46,1  ; n1698 t=393.433s dur=1072ms, freq=117Hz, sample=46, buffer_id=01:2E
    db 50,2,175,5,49,55,1,3,139,0,49,1  ; n1699 t=393.469s dur=1455ms, freq=139Hz, sample=49, buffer_id=01:31
; t 393.7623 Sustain 127 (Instr 1)
; t 393.7623 Sustain 127 (Instr 2)
    db 27,0,115,4,66,55,1,0,114,1,66,1  ; n1700 t=394.032s dur=1139ms, freq=370Hz, sample=66, buffer_id=01:42
; t 394.0392 Sustain 0 (Instr 1)
; t 394.0392 Sustain 0 (Instr 2)
    db 156,1,35,4,54,55,1,2,185,0,54,1  ; n1701 t=394.059s dur=1059ms, freq=185Hz, sample=54, buffer_id=01:36
; t 394.4426 Soft 127 (Instr 1)
; t 394.4426 Soft 127 (Instr 2)
    db 150,2,240,5,44,55,1,1,104,0,44,1  ; n1702 t=394.471s dur=1520ms, freq=104Hz, sample=44, buffer_id=01:2C
    db 55,0,89,3,53,55,1,3,175,0,53,1  ; n1703 t=395.133s dur=857ms, freq=175Hz, sample=53, buffer_id=01:35
    db 72,1,35,3,65,55,1,4,93,1,65,1  ; n1704 t=395.188s dur=803ms, freq=349Hz, sample=65, buffer_id=01:41
    db 224,1,187,5,32,55,1,0,52,0,32,1  ; n1705 t=395.516s dur=1467ms, freq=52Hz, sample=32, buffer_id=01:20
; t 395.5521 Sustain 127 (Instr 1)
; t 395.5521 Sustain 127 (Instr 2)
; t 395.9911 Sustain 0 (Instr 1)
; t 395.9911 Sustain 0 (Instr 2)
    db 1,0,74,1,66,55,1,2,114,1,66,1  ; n1706 t=395.996s dur=330ms, freq=370Hz, sample=66, buffer_id=01:42
    db 42,2,70,1,54,55,1,5,185,0,54,1  ; n1707 t=395.997s dur=326ms, freq=185Hz, sample=54, buffer_id=01:36
    db 6,0,176,1,60,55,1,1,6,1,60,1  ; n1708 t=396.551s dur=432ms, freq=262Hz, sample=60, buffer_id=01:3C
    db 18,0,175,1,44,55,1,2,104,0,44,1  ; n1709 t=396.557s dur=431ms, freq=104Hz, sample=44, buffer_id=01:2C
    db 151,1,152,1,48,55,1,3,131,0,48,1  ; n1710 t=396.575s dur=408ms, freq=131Hz, sample=48, buffer_id=01:30
; t 396.6059 Sustain 127 (Instr 1)
; t 396.6059 Sustain 127 (Instr 2)
    db 84,0,77,2,37,55,1,4,69,0,37,1  ; n1711 t=396.983s dur=589ms, freq=69Hz, sample=37, buffer_id=01:25
; t 396.9838 Sustain 0 (Instr 1)
; t 396.9838 Sustain 0 (Instr 2)
    db 0,0,249,1,49,55,1,5,139,0,49,1  ; n1712 t=397.067s dur=505ms, freq=139Hz, sample=49, buffer_id=01:31
    db 190,2,249,1,61,55,1,6,21,1,61,1  ; n1713 t=397.067s dur=505ms, freq=277Hz, sample=61, buffer_id=01:3D
; t 397.2080 Sustain 127 (Instr 1)
; t 397.2080 Sustain 127 (Instr 2)
; t 397.3554 Soft 0 (Instr 1)
; t 397.3554 Soft 0 (Instr 2)
; t 397.5722 Sustain 0 (Instr 1)
; t 397.5722 Sustain 0 (Instr 2)
    db 1,0,241,2,77,44,2,0,186,2,77,1  ; n1714 t=397.769s dur=753ms, freq=698Hz, sample=77, buffer_id=01:4D
    db 223,0,240,2,65,55,1,1,93,1,65,1  ; n1715 t=397.770s dur=752ms, freq=349Hz, sample=65, buffer_id=01:41
    db 1,0,175,2,50,55,1,2,147,0,50,1  ; n1716 t=397.993s dur=687ms, freq=147Hz, sample=50, buffer_id=01:32
    db 11,2,101,2,56,55,1,3,208,0,56,1  ; n1717 t=397.994s dur=613ms, freq=208Hz, sample=56, buffer_id=01:38
; t 398.0627 Sustain 127 (Instr 1)
; t 398.0627 Sustain 127 (Instr 2)
    db 12,0,209,2,58,55,1,4,233,0,58,1  ; n1718 t=398.517s dur=721ms, freq=233Hz, sample=58, buffer_id=01:3A
; t 398.5227 Sustain 0 (Instr 1)
; t 398.5227 Sustain 0 (Instr 2)
    db 187,0,198,2,70,41,2,5,210,1,70,1  ; n1719 t=398.529s dur=710ms, freq=466Hz, sample=70, buffer_id=01:46
    db 6,0,227,2,49,55,1,6,139,0,49,1  ; n1720 t=398.716s dur=739ms, freq=139Hz, sample=49, buffer_id=01:31
    db 28,2,185,2,55,55,1,0,196,0,55,1  ; n1721 t=398.723s dur=697ms, freq=196Hz, sample=55, buffer_id=01:37
; t 398.9015 Sustain 127 (Instr 1)
; t 398.9015 Sustain 127 (Instr 2)
; t 399.2077 Sustain 0 (Instr 1)
; t 399.2077 Sustain 0 (Instr 2)
    db 2,0,160,2,63,55,1,1,55,1,63,1  ; n1722 t=399.262s dur=672ms, freq=311Hz, sample=63, buffer_id=01:3F
    db 208,0,158,2,75,42,2,2,110,2,75,1  ; n1723 t=399.264s dur=670ms, freq=622Hz, sample=75, buffer_id=01:4B
    db 4,0,224,2,48,55,1,3,131,0,48,1  ; n1724 t=399.473s dur=736ms, freq=131Hz, sample=48, buffer_id=01:30
    db 218,1,208,2,54,55,1,4,185,0,54,1  ; n1725 t=399.477s dur=720ms, freq=185Hz, sample=54, buffer_id=01:36
; t 399.5813 Sustain 127 (Instr 1)
; t 399.5813 Sustain 127 (Instr 2)
; t 399.9348 Sustain 0 (Instr 1)
; t 399.9348 Sustain 0 (Instr 2)
    db 14,0,235,2,68,42,2,0,159,1,68,1  ; n1726 t=399.951s dur=747ms, freq=415Hz, sample=68, buffer_id=01:44
    db 243,0,221,2,56,55,1,5,208,0,56,1  ; n1727 t=399.964s dur=733ms, freq=208Hz, sample=56, buffer_id=01:38
    db 13,0,234,1,47,55,1,1,123,0,47,1  ; n1728 t=400.207s dur=490ms, freq=123Hz, sample=47, buffer_id=01:2F
    db 216,1,221,1,53,55,1,2,175,0,53,1  ; n1729 t=400.220s dur=477ms, freq=175Hz, sample=53, buffer_id=01:35
; t 400.3378 Sustain 127 (Instr 1)
; t 400.3378 Sustain 127 (Instr 2)
    db 10,0,228,2,61,55,1,3,21,1,61,1  ; n1730 t=400.692s dur=740ms, freq=277Hz, sample=61, buffer_id=01:3D
; t 400.6977 Sustain 0 (Instr 1)
; t 400.6977 Sustain 0 (Instr 2)
    db 196,0,219,2,73,43,2,4,42,2,73,1  ; n1731 t=400.702s dur=731ms, freq=554Hz, sample=73, buffer_id=01:49
    db 0,0,238,2,46,55,1,0,117,0,46,1  ; n1732 t=400.898s dur=750ms, freq=117Hz, sample=46, buffer_id=01:2E
    db 233,1,156,9,49,55,1,1,139,0,49,1  ; n1733 t=400.898s dur=2460ms, freq=139Hz, sample=49, buffer_id=01:31
; t 400.9955 Sustain 127 (Instr 1)
; t 400.9955 Sustain 127 (Instr 2)
    db 6,0,173,2,66,55,1,2,114,1,66,1  ; n1734 t=401.387s dur=685ms, freq=370Hz, sample=66, buffer_id=01:42
    db 208,0,166,2,54,55,1,5,185,0,54,1  ; n1735 t=401.393s dur=678ms, freq=185Hz, sample=54, buffer_id=01:36
; t 401.4332 Sustain 0 (Instr 1)
; t 401.4332 Sustain 0 (Instr 2)
    db 187,1,157,2,44,55,1,6,104,0,44,1  ; n1736 t=401.602s dur=669ms, freq=104Hz, sample=44, buffer_id=01:2C
; t 401.6026 Soft 0 (Instr 1)
; t 401.6026 Soft 0 (Instr 2)
; t 401.7194 Sustain 127 (Instr 1)
; t 401.7194 Sustain 127 (Instr 2)
    db 12,0,180,1,53,55,1,0,175,0,53,1  ; n1737 t=402.045s dur=436ms, freq=175Hz, sample=53, buffer_id=01:35
    db 163,0,169,1,65,55,1,3,93,1,65,1  ; n1738 t=402.056s dur=425ms, freq=349Hz, sample=65, buffer_id=01:41
; t 402.0719 Sustain 0 (Instr 1)
; t 402.0719 Sustain 0 (Instr 2)
    db 198,0,19,1,37,55,1,4,69,0,37,1  ; n1739 t=402.219s dur=275ms, freq=69Hz, sample=37, buffer_id=01:25
; t 402.2718 Sustain 127 (Instr 1)
; t 402.2718 Sustain 127 (Instr 2)
    db 24,0,11,1,41,55,1,2,87,0,41,1  ; n1740 t=402.417s dur=267ms, freq=87Hz, sample=41, buffer_id=01:29
    db 1,0,19,1,68,40,2,5,159,1,68,1  ; n1741 t=402.441s dur=275ms, freq=415Hz, sample=68, buffer_id=01:44
    db 197,0,156,0,56,55,1,7,208,0,56,1  ; n1742 t=402.442s dur=156ms, freq=208Hz, sample=56, buffer_id=01:38
; t 402.4811 Sustain 0 (Instr 1)
; t 402.4811 Sustain 0 (Instr 2)
    db 12,0,30,1,44,55,1,6,104,0,44,1  ; n1743 t=402.639s dur=286ms, freq=104Hz, sample=44, buffer_id=01:2C
    db 14,0,212,1,71,42,2,8,238,1,71,1  ; n1744 t=402.651s dur=468ms, freq=494Hz, sample=71, buffer_id=01:47
    db 210,0,75,1,59,55,1,9,247,0,59,1  ; n1745 t=402.664s dur=331ms, freq=247Hz, sample=59, buffer_id=01:3B
    db 199,0,148,2,42,55,1,0,92,0,42,1  ; n1746 t=402.875s dur=660ms, freq=92Hz, sample=42, buffer_id=01:2A
    db 6,0,229,0,70,44,2,2,210,1,70,1  ; n1747 t=403.073s dur=229ms, freq=466Hz, sample=70, buffer_id=01:46
    db 245,0,223,0,58,55,1,3,233,0,58,1  ; n1748 t=403.080s dur=223ms, freq=233Hz, sample=58, buffer_id=01:3A
    db 1,0,127,1,73,47,2,4,42,2,73,1  ; n1749 t=403.325s dur=383ms, freq=554Hz, sample=73, buffer_id=01:49
    db 160,0,171,1,61,55,1,5,21,1,61,1  ; n1750 t=403.326s dur=427ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 55,0,59,3,46,55,1,6,117,0,46,1  ; n1751 t=403.486s dur=827ms, freq=117Hz, sample=46, buffer_id=01:2E
    db 219,1,92,11,49,55,1,1,139,0,49,1  ; n1752 t=403.540s dur=2908ms, freq=139Hz, sample=49, buffer_id=01:31
    db 6,0,36,3,54,55,1,0,185,0,54,1  ; n1753 t=404.016s dur=804ms, freq=185Hz, sample=54, buffer_id=01:36
    db 246,0,30,3,66,55,1,2,114,1,66,1  ; n1754 t=404.022s dur=798ms, freq=370Hz, sample=66, buffer_id=01:42
    db 233,1,25,3,44,55,1,3,104,0,44,1  ; n1755 t=404.268s dur=793ms, freq=104Hz, sample=44, buffer_id=01:2C
; t 404.3471 Sustain 127 (Instr 1)
; t 404.3471 Sustain 127 (Instr 2)
    db 17,0,69,3,53,55,1,4,175,0,53,1  ; n1756 t=404.757s dur=837ms, freq=175Hz, sample=53, buffer_id=01:35
    db 36,1,56,3,65,55,1,5,93,1,65,1  ; n1757 t=404.774s dur=824ms, freq=349Hz, sample=65, buffer_id=01:41
; t 404.8204 Sustain 0 (Instr 1)
; t 404.8204 Sustain 0 (Instr 2)
    db 1,2,6,3,43,55,1,0,98,0,43,1  ; n1758 t=405.067s dur=774ms, freq=98Hz, sample=43, buffer_id=01:2B
; t 405.2537 Sustain 127 (Instr 1)
; t 405.2537 Sustain 127 (Instr 2)
    db 17,0,7,3,64,55,1,2,74,1,64,1  ; n1759 t=405.580s dur=775ms, freq=330Hz, sample=64, buffer_id=01:40
; t 405.5945 Sustain 0 (Instr 1)
; t 405.5945 Sustain 0 (Instr 2)
    db 9,1,1,3,52,55,1,3,165,0,52,1  ; n1760 t=405.597s dur=769ms, freq=165Hz, sample=52, buffer_id=01:34
    db 3,2,35,3,44,55,1,4,104,0,44,1  ; n1761 t=405.862s dur=803ms, freq=104Hz, sample=44, buffer_id=01:2C
; t 405.9879 Sustain 127 (Instr 1)
; t 405.9879 Sustain 127 (Instr 2)
; t 406.3054 Sustain 0 (Instr 1)
; t 406.3054 Sustain 0 (Instr 2)
    db 0,0,139,3,53,55,1,0,175,0,53,1  ; n1762 t=406.377s dur=907ms, freq=175Hz, sample=53, buffer_id=01:35
    db 24,1,139,3,65,55,1,5,93,1,65,1  ; n1763 t=406.377s dur=907ms, freq=349Hz, sample=65, buffer_id=01:41
    db 18,0,227,3,46,55,1,1,117,0,46,1  ; n1764 t=406.657s dur=995ms, freq=117Hz, sample=46, buffer_id=01:2E
    db 84,2,84,4,49,55,1,2,139,0,49,1  ; n1765 t=406.675s dur=1108ms, freq=139Hz, sample=49, buffer_id=01:31
; t 406.7617 Sustain 127 (Instr 1)
; t 406.7617 Sustain 127 (Instr 2)
; t 406.8080 Soft 127 (Instr 1)
; t 406.8080 Soft 127 (Instr 2)
    db 19,0,7,4,66,55,1,3,114,1,66,1  ; n1766 t=407.271s dur=1031ms, freq=370Hz, sample=66, buffer_id=01:42
; t 407.2843 Sustain 0 (Instr 1)
; t 407.2843 Sustain 0 (Instr 2)
    db 97,1,197,3,54,55,1,4,185,0,54,1  ; n1767 t=407.289s dur=965ms, freq=185Hz, sample=54, buffer_id=01:36
    db 141,2,52,5,44,55,1,0,104,0,44,1  ; n1768 t=407.643s dur=1332ms, freq=104Hz, sample=44, buffer_id=01:2C
    db 10,0,167,2,53,55,1,1,175,0,53,1  ; n1769 t=408.296s dur=679ms, freq=175Hz, sample=53, buffer_id=01:35
    db 68,1,156,2,65,55,1,2,93,1,65,1  ; n1770 t=408.306s dur=668ms, freq=349Hz, sample=65, buffer_id=01:41
    db 149,1,15,6,32,55,1,3,52,0,32,1  ; n1771 t=408.630s dur=1551ms, freq=52Hz, sample=32, buffer_id=01:20
; t 408.6606 Sustain 127 (Instr 1)
; t 408.6606 Sustain 127 (Instr 2)
; t 408.9749 Sustain 0 (Instr 1)
; t 408.9749 Sustain 0 (Instr 2)
    db 18,0,233,1,54,55,1,4,185,0,54,1  ; n1772 t=409.035s dur=489ms, freq=185Hz, sample=54, buffer_id=01:36
    db 196,1,216,1,66,55,1,5,114,1,66,1  ; n1773 t=409.053s dur=472ms, freq=370Hz, sample=66, buffer_id=01:42
; t 409.2094 Sustain 127 (Instr 1)
; t 409.2094 Sustain 127 (Instr 2)
    db 106,0,165,2,44,55,1,0,104,0,44,1  ; n1774 t=409.505s dur=677ms, freq=104Hz, sample=44, buffer_id=01:2C
; t 409.5248 Sustain 0 (Instr 1)
; t 409.5248 Sustain 0 (Instr 2)
    db 5,0,58,2,48,55,1,1,131,0,48,1  ; n1775 t=409.611s dur=570ms, freq=131Hz, sample=48, buffer_id=01:30
    db 253,1,53,2,60,55,1,2,6,1,60,1  ; n1776 t=409.616s dur=565ms, freq=262Hz, sample=60, buffer_id=01:3C
; t 409.7656 Sustain 127 (Instr 1)
; t 409.7656 Sustain 127 (Instr 2)
    db 86,0,88,2,37,55,1,4,69,0,37,1  ; n1777 t=410.125s dur=600ms, freq=69Hz, sample=37, buffer_id=01:25
; t 410.1818 Sustain 0 (Instr 1)
; t 410.1818 Sustain 0 (Instr 2)
    db 6,0,1,2,49,55,1,5,139,0,49,1  ; n1778 t=410.211s dur=513ms, freq=139Hz, sample=49, buffer_id=01:31
    db 197,4,251,1,61,55,1,6,21,1,61,1  ; n1779 t=410.217s dur=507ms, freq=277Hz, sample=61, buffer_id=01:3D
; t 410.3772 Sustain 127 (Instr 1)
; t 410.3772 Sustain 127 (Instr 2)
; t 410.7251 Sustain 0 (Instr 1)
; t 410.7251 Sustain 0 (Instr 2)
    db 5,0,170,0,68,41,2,0,159,1,68,1  ; n1780 t=411.439s dur=170ms, freq=415Hz, sample=68, buffer_id=01:44
    db 19,0,57,1,65,39,1,1,93,1,65,1  ; n1781 t=411.444s dur=313ms, freq=349Hz, sample=65, buffer_id=01:41
; t 411.4513 Soft 0 (Instr 1)
; t 411.4513 Soft 0 (Instr 2)
    db 6,1,13,1,73,41,2,2,42,2,73,1  ; n1782 t=411.463s dur=269ms, freq=554Hz, sample=73, buffer_id=01:49
    db 24,0,242,1,68,45,2,0,159,1,68,1  ; n1783 t=411.725s dur=498ms, freq=415Hz, sample=68, buffer_id=01:44
    db 2,0,229,1,72,45,2,3,11,2,72,1  ; n1784 t=411.749s dur=485ms, freq=523Hz, sample=72, buffer_id=01:48
    db 215,1,247,1,63,43,1,4,55,1,63,1  ; n1785 t=411.751s dur=503ms, freq=311Hz, sample=63, buffer_id=01:3F
    db 12,0,13,1,61,40,1,1,21,1,61,1  ; n1786 t=412.222s dur=269ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 1,0,43,1,70,43,2,2,210,1,70,1  ; n1787 t=412.233s dur=299ms, freq=466Hz, sample=70, buffer_id=01:46
    db 4,1,179,0,67,43,2,5,136,1,67,1  ; n1788 t=412.234s dur=179ms, freq=392Hz, sample=67, buffer_id=01:43
    db 19,0,112,0,68,41,2,0,159,1,68,1  ; n1789 t=412.494s dur=112ms, freq=415Hz, sample=68, buffer_id=01:44
    db 10,0,100,0,60,38,1,3,6,1,60,1  ; n1790 t=412.513s dur=100ms, freq=262Hz, sample=60, buffer_id=01:3C
    db 205,1,76,0,75,40,2,4,110,2,75,1  ; n1791 t=412.523s dur=76ms, freq=622Hz, sample=75, buffer_id=01:4B
    db 7,0,104,0,73,38,2,0,42,2,73,1  ; n1792 t=412.985s dur=104ms, freq=554Hz, sample=73, buffer_id=01:49
    db 5,0,87,0,49,33,1,1,139,0,49,1  ; n1793 t=412.992s dur=87ms, freq=139Hz, sample=49, buffer_id=01:31
    db 1,0,86,0,65,33,1,2,93,1,65,1  ; n1794 t=412.997s dur=86ms, freq=349Hz, sample=65, buffer_id=01:41
    db 239,0,74,0,58,33,1,3,233,0,58,1  ; n1795 t=412.998s dur=74ms, freq=233Hz, sample=58, buffer_id=01:3A
    db 26,0,132,0,68,41,2,4,159,1,68,1  ; n1796 t=413.237s dur=132ms, freq=415Hz, sample=68, buffer_id=01:44
    db 3,0,99,0,63,37,1,5,55,1,63,1  ; n1797 t=413.263s dur=99ms, freq=311Hz, sample=63, buffer_id=01:3F
    db 8,0,113,0,72,42,2,6,11,2,72,1  ; n1798 t=413.266s dur=113ms, freq=523Hz, sample=72, buffer_id=01:48
    db 226,1,99,0,51,37,1,3,156,0,51,1  ; n1799 t=413.275s dur=99ms, freq=156Hz, sample=51, buffer_id=01:33
    db 8,0,101,0,51,34,1,0,156,0,51,1  ; n1800 t=413.757s dur=101ms, freq=156Hz, sample=51, buffer_id=01:33
    db 4,0,125,0,61,34,1,1,21,1,61,1  ; n1801 t=413.765s dur=125ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 6,0,138,0,67,40,2,2,136,1,67,1  ; n1802 t=413.770s dur=138ms, freq=392Hz, sample=67, buffer_id=01:43
    db 231,0,138,0,70,40,2,3,210,1,70,1  ; n1803 t=413.776s dur=138ms, freq=466Hz, sample=70, buffer_id=01:46
    db 11,0,150,0,56,34,1,4,208,0,56,1  ; n1804 t=414.007s dur=150ms, freq=208Hz, sample=56, buffer_id=01:38
    db 14,0,132,0,68,38,2,5,159,1,68,1  ; n1805 t=414.018s dur=132ms, freq=415Hz, sample=68, buffer_id=01:44
    db 194,1,143,0,60,33,1,6,6,1,60,1  ; n1806 t=414.031s dur=143ms, freq=262Hz, sample=60, buffer_id=01:3C
    db 0,0,224,0,78,42,2,0,228,2,78,1  ; n1807 t=414.481s dur=224ms, freq=740Hz, sample=78, buffer_id=01:4E
    db 6,0,0,1,70,42,2,1,210,1,70,1  ; n1808 t=414.481s dur=256ms, freq=466Hz, sample=70, buffer_id=01:46
    db 253,0,162,0,73,42,2,2,42,2,73,1  ; n1809 t=414.487s dur=162ms, freq=554Hz, sample=73, buffer_id=01:49
    db 6,0,136,1,73,45,2,2,42,2,73,1  ; n1810 t=414.740s dur=392ms, freq=554Hz, sample=73, buffer_id=01:49
    db 6,0,192,1,77,45,2,3,186,2,77,1  ; n1811 t=414.747s dur=448ms, freq=698Hz, sample=77, buffer_id=01:4D
    db 173,1,168,1,68,45,2,4,159,1,68,1  ; n1812 t=414.753s dur=424ms, freq=415Hz, sample=68, buffer_id=01:44
    db 17,0,19,1,66,33,1,0,114,1,66,1  ; n1813 t=415.182s dur=275ms, freq=370Hz, sample=66, buffer_id=01:42
    db 0,0,147,0,72,43,2,1,11,2,72,1  ; n1814 t=415.199s dur=147ms, freq=523Hz, sample=72, buffer_id=01:48
    db 10,1,25,1,75,43,2,5,110,2,75,1  ; n1815 t=415.199s dur=281ms, freq=622Hz, sample=75, buffer_id=01:4B
    db 2,0,128,0,80,44,2,2,63,3,80,1  ; n1816 t=415.464s dur=128ms, freq=831Hz, sample=80, buffer_id=01:50
    db 11,0,70,0,65,33,1,3,93,1,65,1  ; n1817 t=415.466s dur=70ms, freq=349Hz, sample=65, buffer_id=01:41
    db 212,1,77,0,73,44,2,4,42,2,73,1  ; n1818 t=415.478s dur=77ms, freq=554Hz, sample=73, buffer_id=01:49
    db 48,0,164,0,54,33,1,0,185,0,54,1  ; n1819 t=415.945s dur=164ms, freq=185Hz, sample=54, buffer_id=01:36
    db 0,0,95,0,70,38,2,1,210,1,70,1  ; n1820 t=415.994s dur=95ms, freq=466Hz, sample=70, buffer_id=01:46
    db 2,0,152,0,78,38,2,2,228,2,78,1  ; n1821 t=415.994s dur=152ms, freq=740Hz, sample=78, buffer_id=01:4E
    db 253,0,63,0,63,33,1,3,55,1,63,1  ; n1822 t=415.996s dur=63ms, freq=311Hz, sample=63, buffer_id=01:3F
    db 6,0,125,0,68,42,2,4,159,1,68,1  ; n1823 t=416.249s dur=125ms, freq=415Hz, sample=68, buffer_id=01:44
    db 0,0,131,0,77,42,2,5,186,2,77,1  ; n1824 t=416.255s dur=131ms, freq=698Hz, sample=77, buffer_id=01:4D
    db 2,0,136,0,73,42,2,6,42,2,73,1  ; n1825 t=416.255s dur=136ms, freq=554Hz, sample=73, buffer_id=01:49
    db 196,1,99,0,56,37,1,7,208,0,56,1  ; n1826 t=416.257s dur=99ms, freq=208Hz, sample=56, buffer_id=01:38
    db 23,0,155,0,56,33,1,0,208,0,56,1  ; n1827 t=416.709s dur=155ms, freq=208Hz, sample=56, buffer_id=01:38
    db 4,0,107,0,66,33,1,1,114,1,66,1  ; n1828 t=416.732s dur=107ms, freq=370Hz, sample=66, buffer_id=01:42
    db 1,0,125,0,75,38,2,2,110,2,75,1  ; n1829 t=416.736s dur=125ms, freq=622Hz, sample=75, buffer_id=01:4B
    db 236,0,119,0,72,38,2,3,11,2,72,1  ; n1830 t=416.738s dur=119ms, freq=523Hz, sample=72, buffer_id=01:48
    db 0,0,219,1,65,33,1,4,93,1,65,1  ; n1831 t=416.974s dur=475ms, freq=349Hz, sample=65, buffer_id=01:41
    db 3,0,219,1,61,33,1,5,21,1,61,1  ; n1832 t=416.974s dur=475ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 203,1,216,1,73,38,2,6,42,2,73,1  ; n1833 t=416.977s dur=472ms, freq=554Hz, sample=73, buffer_id=01:49
; t 416.9792 Sustain 127 (Instr 1)
; t 416.9792 Sustain 127 (Instr 2)
    db 0,0,109,0,56,34,1,0,208,0,56,1  ; n1834 t=417.436s dur=109ms, freq=208Hz, sample=56, buffer_id=01:38
    db 10,0,233,0,53,34,1,1,175,0,53,1  ; n1835 t=417.436s dur=233ms, freq=175Hz, sample=53, buffer_id=01:35
    db 15,0,175,1,73,45,2,6,42,2,73,1  ; n1836 t=417.447s dur=431ms, freq=554Hz, sample=73, buffer_id=01:49
; t 417.4498 Sustain 0 (Instr 1)
; t 417.4498 Sustain 0 (Instr 2)
    db 205,0,137,1,61,34,1,5,21,1,61,1  ; n1837 t=417.461s dur=393ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 7,0,192,1,51,37,1,2,156,0,51,1  ; n1838 t=417.666s dur=448ms, freq=156Hz, sample=51, buffer_id=01:33
    db 214,0,135,1,56,37,1,0,208,0,56,1  ; n1839 t=417.673s dur=391ms, freq=208Hz, sample=56, buffer_id=01:38
    db 2,0,175,0,72,42,2,1,11,2,72,1  ; n1840 t=417.888s dur=175ms, freq=523Hz, sample=72, buffer_id=01:48
    db 191,0,107,0,60,34,1,3,6,1,60,1  ; n1841 t=417.890s dur=107ms, freq=262Hz, sample=60, buffer_id=01:3C
    db 13,0,119,0,49,33,1,4,139,0,49,1  ; n1842 t=418.081s dur=119ms, freq=139Hz, sample=49, buffer_id=01:31
    db 10,0,95,0,55,33,1,5,196,0,55,1  ; n1843 t=418.094s dur=95ms, freq=196Hz, sample=55, buffer_id=01:37
    db 10,0,252,0,70,45,2,6,210,1,70,1  ; n1844 t=418.104s dur=252ms, freq=466Hz, sample=70, buffer_id=01:46
    db 185,0,69,0,58,33,1,7,233,0,58,1  ; n1845 t=418.113s dur=69ms, freq=233Hz, sample=58, buffer_id=01:3A
; t 418.1219 Soft 127 (Instr 1)
; t 418.1219 Soft 127 (Instr 2)
    db 6,0,76,0,48,36,1,0,131,0,48,1  ; n1846 t=418.298s dur=76ms, freq=131Hz, sample=48, buffer_id=01:30
    db 31,0,76,0,60,36,1,1,6,1,60,1  ; n1847 t=418.305s dur=76ms, freq=262Hz, sample=60, buffer_id=01:3C
    db 206,0,192,0,63,36,1,2,55,1,63,1  ; n1848 t=418.336s dur=192ms, freq=311Hz, sample=63, buffer_id=01:3F
    db 187,0,186,0,75,46,2,3,110,2,75,1  ; n1849 t=418.542s dur=186ms, freq=622Hz, sample=75, buffer_id=01:4B
    db 30,0,108,0,49,35,1,0,139,0,49,1  ; n1850 t=418.729s dur=108ms, freq=139Hz, sample=49, buffer_id=01:31
    db 3,0,70,0,58,36,1,1,233,0,58,1  ; n1851 t=418.759s dur=70ms, freq=233Hz, sample=58, buffer_id=01:3A
    db 2,0,24,1,73,58,2,2,42,2,73,1  ; n1852 t=418.762s dur=280ms, freq=554Hz, sample=73, buffer_id=01:49
    db 222,0,23,1,65,36,1,4,93,1,65,1  ; n1853 t=418.765s dur=279ms, freq=349Hz, sample=65, buffer_id=01:41
    db 21,0,78,0,51,39,1,3,156,0,51,1  ; n1854 t=418.986s dur=78ms, freq=156Hz, sample=51, buffer_id=01:33
    db 16,0,98,0,63,39,1,5,55,1,63,1  ; n1855 t=419.007s dur=98ms, freq=311Hz, sample=63, buffer_id=01:3F
    db 191,0,224,0,68,38,2,6,159,1,68,1  ; n1856 t=419.023s dur=224ms, freq=415Hz, sample=68, buffer_id=01:44
    db 175,0,169,0,72,41,2,0,11,2,72,1  ; n1857 t=419.214s dur=169ms, freq=523Hz, sample=72, buffer_id=01:48
    db 1,0,151,0,51,34,1,1,156,0,51,1  ; n1858 t=419.389s dur=151ms, freq=156Hz, sample=51, buffer_id=01:33
    db 40,0,118,0,61,34,1,2,21,1,61,1  ; n1859 t=419.390s dur=118ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 1,0,73,2,70,44,2,3,210,1,70,1  ; n1860 t=419.430s dur=585ms, freq=466Hz, sample=70, buffer_id=01:46
    db 175,0,20,1,67,44,2,4,136,1,67,1  ; n1861 t=419.431s dur=276ms, freq=392Hz, sample=67, buffer_id=01:43
    db 5,0,152,1,60,33,1,0,6,1,60,1  ; n1862 t=419.607s dur=408ms, freq=262Hz, sample=60, buffer_id=01:3C
    db 193,0,147,1,56,33,1,5,208,0,56,1  ; n1863 t=419.612s dur=403ms, freq=208Hz, sample=56, buffer_id=01:38
; t 419.7244 Sustain 127 (Instr 1)
; t 419.7244 Sustain 127 (Instr 2)
    db 211,0,210,0,68,42,2,1,159,1,68,1  ; n1864 t=419.805s dur=210ms, freq=415Hz, sample=68, buffer_id=01:44
; t 420.0153 Sustain 0 (Instr 1)
; t 420.0153 Sustain 0 (Instr 2)
    db 0,0,125,0,61,36,1,2,21,1,61,1  ; n1865 t=420.016s dur=125ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 18,0,131,0,58,36,1,4,233,0,58,1  ; n1866 t=420.016s dur=131ms, freq=233Hz, sample=58, buffer_id=01:3A
    db 4,0,96,1,66,36,1,6,114,1,66,1  ; n1867 t=420.034s dur=352ms, freq=370Hz, sample=66, buffer_id=01:42
    db 187,0,68,1,78,52,2,7,228,2,78,1  ; n1868 t=420.038s dur=324ms, freq=740Hz, sample=78, buffer_id=01:4E
    db 6,0,90,1,61,38,1,2,21,1,61,1  ; n1869 t=420.225s dur=346ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 192,0,123,1,56,38,1,0,208,0,56,1  ; n1870 t=420.232s dur=379ms, freq=208Hz, sample=56, buffer_id=01:38
    db 5,0,160,0,77,49,2,1,186,2,77,1  ; n1871 t=420.424s dur=160ms, freq=698Hz, sample=77, buffer_id=01:4D
    db 190,0,130,0,65,37,1,3,93,1,65,1  ; n1872 t=420.429s dur=130ms, freq=349Hz, sample=65, buffer_id=01:41
    db 0,0,150,0,60,39,1,4,6,1,60,1  ; n1873 t=420.619s dur=150ms, freq=262Hz, sample=60, buffer_id=01:3C
    db 28,0,175,0,54,39,1,5,185,0,54,1  ; n1874 t=420.619s dur=175ms, freq=185Hz, sample=54, buffer_id=01:36
    db 15,0,186,0,75,52,2,6,110,2,75,1  ; n1875 t=420.647s dur=186ms, freq=622Hz, sample=75, buffer_id=01:4B
    db 117,0,76,0,63,40,1,7,55,1,63,1  ; n1876 t=420.662s dur=76ms, freq=311Hz, sample=63, buffer_id=01:3F
    db 31,0,70,0,53,38,1,2,175,0,53,1  ; n1877 t=420.779s dur=70ms, freq=175Hz, sample=53, buffer_id=01:35
    db 29,0,73,0,65,38,1,1,93,1,65,1  ; n1878 t=420.810s dur=73ms, freq=349Hz, sample=65, buffer_id=01:41
    db 194,0,217,0,68,50,2,0,159,1,68,1  ; n1879 t=420.840s dur=217ms, freq=415Hz, sample=68, buffer_id=01:44
    db 195,0,244,0,80,50,2,3,63,3,80,1  ; n1880 t=421.034s dur=244ms, freq=831Hz, sample=80, buffer_id=01:50
    db 21,0,102,0,54,36,1,1,185,0,54,1  ; n1881 t=421.229s dur=102ms, freq=185Hz, sample=54, buffer_id=01:36
    db 14,0,45,1,78,53,2,2,228,2,78,1  ; n1882 t=421.250s dur=301ms, freq=740Hz, sample=78, buffer_id=01:4E
    db 2,0,200,0,70,53,2,0,210,1,70,1  ; n1883 t=421.264s dur=200ms, freq=466Hz, sample=70, buffer_id=01:46
    db 205,0,76,0,63,37,1,4,55,1,63,1  ; n1884 t=421.266s dur=76ms, freq=311Hz, sample=63, buffer_id=01:3F
    db 1,0,106,0,68,38,2,5,159,1,68,1  ; n1885 t=421.471s dur=106ms, freq=415Hz, sample=68, buffer_id=01:44
    db 21,0,114,0,56,40,1,6,208,0,56,1  ; n1886 t=421.472s dur=114ms, freq=208Hz, sample=56, buffer_id=01:38
    db 174,0,221,0,73,38,2,3,42,2,73,1  ; n1887 t=421.493s dur=221ms, freq=554Hz, sample=73, buffer_id=01:49
    db 225,0,232,0,77,41,2,0,186,2,77,1  ; n1888 t=421.667s dur=232ms, freq=698Hz, sample=77, buffer_id=01:4D
    db 6,0,198,0,56,36,1,1,208,0,56,1  ; n1889 t=421.892s dur=198ms, freq=208Hz, sample=56, buffer_id=01:38
    db 15,0,178,0,66,36,1,2,114,1,66,1  ; n1890 t=421.898s dur=178ms, freq=370Hz, sample=66, buffer_id=01:42
    db 8,0,177,1,75,44,2,4,110,2,75,1  ; n1891 t=421.913s dur=433ms, freq=622Hz, sample=75, buffer_id=01:4B
    db 191,0,236,0,72,44,2,3,11,2,72,1  ; n1892 t=421.921s dur=236ms, freq=523Hz, sample=72, buffer_id=01:48
    db 13,0,11,1,61,37,1,0,21,1,61,1  ; n1893 t=422.112s dur=267ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 176,0,180,0,65,36,1,5,93,1,65,1  ; n1894 t=422.125s dur=180ms, freq=349Hz, sample=65, buffer_id=01:41
; t 422.1949 Soft 0 (Instr 1)
; t 422.1949 Soft 0 (Instr 2)
    db 231,0,138,0,73,39,2,1,42,2,73,1  ; n1895 t=422.301s dur=138ms, freq=554Hz, sample=73, buffer_id=01:49
    db 10,0,89,1,61,33,1,0,21,1,61,1  ; n1896 t=422.532s dur=345ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 1,0,254,0,73,39,2,1,42,2,73,1  ; n1897 t=422.542s dur=254ms, freq=554Hz, sample=73, buffer_id=01:49
    db 33,1,116,0,65,33,1,2,93,1,65,1  ; n1898 t=422.543s dur=116ms, freq=349Hz, sample=65, buffer_id=01:41
    db 55,0,53,2,58,37,1,3,233,0,58,1  ; n1899 t=422.832s dur=565ms, freq=233Hz, sample=58, buffer_id=01:3A
    db 3,0,255,1,65,38,1,2,93,1,65,1  ; n1900 t=422.887s dur=511ms, freq=349Hz, sample=65, buffer_id=01:41
    db 223,1,252,1,73,43,2,1,42,2,73,1  ; n1901 t=422.890s dur=508ms, freq=554Hz, sample=73, buffer_id=01:49
; t 422.9056 Sustain 127 (Instr 1)
; t 422.9056 Sustain 127 (Instr 2)
    db 48,0,255,0,56,33,1,0,208,0,56,1  ; n1902 t=423.368s dur=255ms, freq=208Hz, sample=56, buffer_id=01:38
; t 423.3979 Sustain 0 (Instr 1)
; t 423.3979 Sustain 0 (Instr 2)
    db 4,0,86,0,65,34,1,2,93,1,65,1  ; n1903 t=423.417s dur=86ms, freq=349Hz, sample=65, buffer_id=01:41
    db 195,0,162,0,73,39,2,1,42,2,73,1  ; n1904 t=423.421s dur=162ms, freq=554Hz, sample=73, buffer_id=01:49
    db 24,0,204,2,55,36,1,3,196,0,55,1  ; n1905 t=423.616s dur=716ms, freq=196Hz, sample=55, buffer_id=01:37
    db 22,0,156,0,63,37,1,4,55,1,63,1  ; n1906 t=423.640s dur=156ms, freq=311Hz, sample=63, buffer_id=01:3F
    db 238,0,194,0,73,42,2,1,42,2,73,1  ; n1907 t=423.662s dur=194ms, freq=554Hz, sample=73, buffer_id=01:49
    db 10,0,176,1,56,34,1,0,208,0,56,1  ; n1908 t=423.901s dur=432ms, freq=208Hz, sample=56, buffer_id=01:38
    db 27,0,167,1,72,40,2,2,11,2,72,1  ; n1909 t=423.910s dur=423ms, freq=523Hz, sample=72, buffer_id=01:48
; t 423.9238 Sustain 127 (Instr 1)
; t 423.9238 Sustain 127 (Instr 2)
    db 197,0,139,1,63,33,1,4,55,1,63,1  ; n1910 t=423.938s dur=395ms, freq=311Hz, sample=63, buffer_id=01:3F
    db 4,0,223,0,56,33,1,0,208,0,56,1  ; n1911 t=424.135s dur=223ms, freq=208Hz, sample=56, buffer_id=01:38
    db 16,0,205,0,71,38,2,1,238,1,71,1  ; n1912 t=424.139s dur=205ms, freq=494Hz, sample=71, buffer_id=01:47
    db 21,1,178,0,63,33,1,4,55,1,63,1  ; n1913 t=424.155s dur=178ms, freq=311Hz, sample=63, buffer_id=01:3F
; t 424.3332 Sustain 0 (Instr 1)
; t 424.3332 Sustain 0 (Instr 2)
    db 3,0,104,2,63,37,1,4,55,1,63,1  ; n1914 t=424.432s dur=616ms, freq=311Hz, sample=63, buffer_id=01:3F
    db 8,0,100,2,71,42,2,1,238,1,71,1  ; n1915 t=424.435s dur=612ms, freq=494Hz, sample=71, buffer_id=01:47
    db 208,1,92,2,56,37,1,0,208,0,56,1  ; n1916 t=424.443s dur=604ms, freq=208Hz, sample=56, buffer_id=01:38
; t 424.5862 Sustain 127 (Instr 1)
; t 424.5862 Sustain 127 (Instr 2)
    db 9,0,196,0,71,39,2,1,238,1,71,1  ; n1917 t=424.907s dur=196ms, freq=494Hz, sample=71, buffer_id=01:47
    db 5,0,131,0,63,34,1,4,55,1,63,1  ; n1918 t=424.917s dur=131ms, freq=311Hz, sample=63, buffer_id=01:3F
    db 173,0,219,0,54,34,1,2,185,0,54,1  ; n1919 t=424.922s dur=219ms, freq=185Hz, sample=54, buffer_id=01:36
; t 425.0480 Sustain 0 (Instr 1)
; t 425.0480 Sustain 0 (Instr 2)
    db 1,0,86,1,61,36,1,3,21,1,61,1  ; n1920 t=425.095s dur=342ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 79,0,85,1,53,36,1,5,175,0,53,1  ; n1921 t=425.096s dur=341ms, freq=175Hz, sample=53, buffer_id=01:35
    db 169,0,6,1,71,43,2,1,238,1,71,1  ; n1922 t=425.175s dur=262ms, freq=494Hz, sample=71, buffer_id=01:47
; t 425.2190 Sustain 127 (Instr 1)
; t 425.2190 Sustain 127 (Instr 2)
    db 16,0,108,0,54,35,1,0,185,0,54,1  ; n1923 t=425.344s dur=108ms, freq=185Hz, sample=54, buffer_id=01:36
    db 2,0,177,0,70,40,2,2,210,1,70,1  ; n1924 t=425.360s dur=177ms, freq=466Hz, sample=70, buffer_id=01:46
    db 155,0,157,0,61,35,1,3,21,1,61,1  ; n1925 t=425.362s dur=157ms, freq=277Hz, sample=61, buffer_id=01:3D
; t 425.4373 Sustain 0 (Instr 1)
; t 425.4373 Sustain 0 (Instr 2)
    db 90,0,75,1,54,33,1,0,185,0,54,1  ; n1926 t=425.517s dur=331ms, freq=185Hz, sample=54, buffer_id=01:36
    db 15,0,251,0,70,40,2,2,210,1,70,1  ; n1927 t=425.607s dur=251ms, freq=466Hz, sample=70, buffer_id=01:46
    db 192,0,140,0,61,33,1,3,21,1,61,1  ; n1928 t=425.622s dur=140ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 1,0,134,2,56,36,1,1,208,0,56,1  ; n1929 t=425.814s dur=646ms, freq=208Hz, sample=56, buffer_id=01:38
    db 85,0,133,2,51,36,1,4,156,0,51,1  ; n1930 t=425.815s dur=645ms, freq=156Hz, sample=51, buffer_id=01:33
    db 1,0,48,2,72,44,2,5,11,2,72,1  ; n1931 t=425.900s dur=560ms, freq=523Hz, sample=72, buffer_id=01:48
    db 241,1,47,2,66,37,1,6,114,1,66,1  ; n1932 t=425.901s dur=559ms, freq=370Hz, sample=66, buffer_id=01:42
; t 425.9305 Sustain 127 (Instr 1)
; t 425.9305 Sustain 127 (Instr 2)
    db 3,0,111,1,49,34,1,0,139,0,49,1  ; n1933 t=426.399s dur=367ms, freq=139Hz, sample=49, buffer_id=01:31
    db 3,0,124,1,73,45,2,2,42,2,73,1  ; n1934 t=426.402s dur=380ms, freq=554Hz, sample=73, buffer_id=01:49
    db 6,0,248,0,56,34,1,1,208,0,56,1  ; n1935 t=426.405s dur=248ms, freq=208Hz, sample=56, buffer_id=01:38
    db 71,1,22,1,65,34,1,3,93,1,65,1  ; n1936 t=426.411s dur=278ms, freq=349Hz, sample=65, buffer_id=01:41
; t 426.4604 Sustain 0 (Instr 1)
; t 426.4604 Sustain 0 (Instr 2)
    db 44,0,254,4,48,39,1,4,131,0,48,1  ; n1937 t=426.738s dur=1278ms, freq=131Hz, sample=48, buffer_id=01:30
    db 17,0,61,4,56,39,1,1,208,0,56,1  ; n1938 t=426.783s dur=1085ms, freq=208Hz, sample=56, buffer_id=01:38
    db 1,0,242,3,75,51,2,5,110,2,75,1  ; n1939 t=426.799s dur=1010ms, freq=622Hz, sample=75, buffer_id=01:4B
    db 123,3,241,3,66,42,1,6,114,1,66,1  ; n1940 t=426.800s dur=1009ms, freq=370Hz, sample=66, buffer_id=01:42
; t 427.0511 Sustain 127 (Instr 1)
; t 427.0511 Sustain 127 (Instr 2)
    db 20,0,175,2,66,36,1,6,114,1,66,1  ; n1941 t=427.691s dur=687ms, freq=370Hz, sample=66, buffer_id=01:42
    db 78,1,236,2,63,37,1,0,55,1,63,1  ; n1942 t=427.711s dur=748ms, freq=311Hz, sample=63, buffer_id=01:3F
; t 427.7877 Soft 127 (Instr 1)
; t 427.7877 Soft 127 (Instr 2)
; t 427.8098 Sustain 0 (Instr 1)
; t 427.8098 Sustain 0 (Instr 2)
    db 28,0,80,2,49,33,1,2,139,0,49,1  ; n1943 t=428.045s dur=592ms, freq=139Hz, sample=49, buffer_id=01:31
    db 17,1,148,1,56,33,1,1,208,0,56,1  ; n1944 t=428.073s dur=404ms, freq=208Hz, sample=56, buffer_id=01:38
    db 113,0,172,0,61,34,1,3,21,1,61,1  ; n1945 t=428.346s dur=172ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 156,0,18,1,65,42,1,4,93,1,65,1  ; n1946 t=428.459s dur=274ms, freq=349Hz, sample=65, buffer_id=01:41
    db 104,0,92,1,42,34,1,5,92,0,42,1  ; n1947 t=428.616s dur=348ms, freq=92Hz, sample=42, buffer_id=01:2A
    db 13,0,154,1,58,35,1,0,233,0,58,1  ; n1948 t=428.719s dur=410ms, freq=233Hz, sample=58, buffer_id=01:3A
    db 110,0,44,1,54,35,1,1,185,0,54,1  ; n1949 t=428.732s dur=300ms, freq=185Hz, sample=54, buffer_id=01:36
    db 130,0,157,0,70,43,2,2,210,1,70,1  ; n1950 t=428.842s dur=157ms, freq=466Hz, sample=70, buffer_id=01:46
    db 25,0,232,0,51,33,1,3,156,0,51,1  ; n1951 t=428.972s dur=232ms, freq=156Hz, sample=51, buffer_id=01:33
    db 164,0,181,0,66,34,1,4,114,1,66,1  ; n1952 t=428.997s dur=181ms, freq=370Hz, sample=66, buffer_id=01:42
    db 19,0,74,1,44,34,1,6,104,0,44,1  ; n1953 t=429.161s dur=330ms, freq=104Hz, sample=44, buffer_id=01:2C
    db 64,0,63,1,56,34,1,5,208,0,56,1  ; n1954 t=429.180s dur=319ms, freq=208Hz, sample=56, buffer_id=01:38
; t 429.2146 Sustain 127 (Instr 1)
; t 429.2146 Sustain 127 (Instr 2)
    db 2,0,247,0,65,38,1,1,93,1,65,1  ; n1955 t=429.244s dur=247ms, freq=349Hz, sample=65, buffer_id=01:41
    db 239,0,245,0,61,38,1,2,21,1,61,1  ; n1956 t=429.246s dur=245ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 6,0,75,0,60,40,1,0,6,1,60,1  ; n1957 t=429.485s dur=75ms, freq=262Hz, sample=60, buffer_id=01:3C
    db 217,0,89,0,63,40,1,3,55,1,63,1  ; n1958 t=429.491s dur=89ms, freq=311Hz, sample=63, buffer_id=01:3F
; t 429.4915 Sustain 0 (Instr 1)
; t 429.4915 Sustain 0 (Instr 2)
    db 5,0,166,0,53,38,1,1,175,0,53,1  ; n1959 t=429.709s dur=166ms, freq=175Hz, sample=53, buffer_id=01:35
    db 17,0,102,0,56,38,1,2,208,0,56,1  ; n1960 t=429.714s dur=102ms, freq=208Hz, sample=56, buffer_id=01:38
    db 2,0,230,0,73,43,2,4,42,2,73,1  ; n1961 t=429.731s dur=230ms, freq=554Hz, sample=73, buffer_id=01:49
    db 210,0,248,0,61,39,1,5,21,1,61,1  ; n1962 t=429.733s dur=248ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 19,0,207,1,51,42,1,0,156,0,51,1  ; n1963 t=429.942s dur=463ms, freq=156Hz, sample=51, buffer_id=01:33
    db 55,0,179,1,56,42,1,2,208,0,56,1  ; n1964 t=429.961s dur=435ms, freq=208Hz, sample=56, buffer_id=01:38
    db 3,0,123,1,60,41,1,3,6,1,60,1  ; n1965 t=430.017s dur=379ms, freq=262Hz, sample=60, buffer_id=01:3C
    db 145,1,120,1,72,45,2,6,11,2,72,1  ; n1966 t=430.020s dur=376ms, freq=523Hz, sample=72, buffer_id=01:48
; t 430.0967 Sustain 127 (Instr 1)
; t 430.0967 Sustain 127 (Instr 2)
; t 430.3966 Sustain 0 (Instr 1)
; t 430.3966 Sustain 0 (Instr 2)
    db 1,0,30,1,70,42,2,1,210,1,70,1  ; n1967 t=430.421s dur=286ms, freq=466Hz, sample=70, buffer_id=01:46
    db 6,0,163,0,55,38,1,4,196,0,55,1  ; n1968 t=430.422s dur=163ms, freq=196Hz, sample=55, buffer_id=01:37
    db 0,0,81,0,58,38,1,5,233,0,58,1  ; n1969 t=430.428s dur=81ms, freq=233Hz, sample=58, buffer_id=01:3A
    db 210,0,150,0,49,38,1,7,139,0,49,1  ; n1970 t=430.428s dur=150ms, freq=139Hz, sample=49, buffer_id=01:31
    db 37,0,89,0,48,37,1,0,131,0,48,1  ; n1971 t=430.638s dur=89ms, freq=131Hz, sample=48, buffer_id=01:30
    db 25,0,101,0,60,37,1,2,6,1,60,1  ; n1972 t=430.675s dur=101ms, freq=262Hz, sample=60, buffer_id=01:3C
    db 11,0,81,0,63,37,1,3,55,1,63,1  ; n1973 t=430.700s dur=81ms, freq=311Hz, sample=63, buffer_id=01:3F
    db 135,1,64,0,75,43,2,5,110,2,75,1  ; n1974 t=430.710s dur=64ms, freq=622Hz, sample=75, buffer_id=01:4B
    db 37,0,112,0,49,37,1,0,139,0,49,1  ; n1975 t=431.101s dur=112ms, freq=139Hz, sample=49, buffer_id=01:31
    db 4,0,69,0,58,37,1,1,233,0,58,1  ; n1976 t=431.138s dur=69ms, freq=233Hz, sample=58, buffer_id=01:3A
    db 7,0,97,1,73,43,2,2,42,2,73,1  ; n1977 t=431.142s dur=353ms, freq=554Hz, sample=73, buffer_id=01:49
    db 191,0,198,0,65,37,1,3,93,1,65,1  ; n1978 t=431.150s dur=198ms, freq=349Hz, sample=65, buffer_id=01:41
    db 18,0,88,0,51,38,1,4,156,0,51,1  ; n1979 t=431.341s dur=88ms, freq=156Hz, sample=51, buffer_id=01:33
    db 7,0,230,0,68,41,2,5,159,1,68,1  ; n1980 t=431.358s dur=230ms, freq=415Hz, sample=68, buffer_id=01:44
    db 190,0,94,0,63,37,1,6,55,1,63,1  ; n1981 t=431.366s dur=94ms, freq=311Hz, sample=63, buffer_id=01:3F
    db 179,0,199,0,72,39,2,0,11,2,72,1  ; n1982 t=431.556s dur=199ms, freq=523Hz, sample=72, buffer_id=01:48
    db 1,0,151,0,51,33,1,1,156,0,51,1  ; n1983 t=431.735s dur=151ms, freq=156Hz, sample=51, buffer_id=01:33
    db 22,0,113,0,61,33,1,2,21,1,61,1  ; n1984 t=431.736s dur=113ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 8,0,178,1,70,42,2,3,210,1,70,1  ; n1985 t=431.758s dur=434ms, freq=466Hz, sample=70, buffer_id=01:46
    db 167,0,205,0,67,42,2,4,136,1,67,1  ; n1986 t=431.767s dur=205ms, freq=392Hz, sample=67, buffer_id=01:43
    db 6,0,113,0,60,35,1,5,6,1,60,1  ; n1987 t=431.933s dur=113ms, freq=262Hz, sample=60, buffer_id=01:3C
    db 201,0,144,0,56,35,1,6,208,0,56,1  ; n1988 t=431.940s dur=144ms, freq=208Hz, sample=56, buffer_id=01:38
    db 178,0,156,0,68,38,2,0,159,1,68,1  ; n1989 t=432.141s dur=156ms, freq=415Hz, sample=68, buffer_id=01:44
    db 14,0,17,1,58,34,1,1,233,0,58,1  ; n1990 t=432.319s dur=273ms, freq=233Hz, sample=58, buffer_id=01:3A
    db 13,0,131,0,61,34,1,2,21,1,61,1  ; n1991 t=432.333s dur=131ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 17,0,216,0,66,34,1,4,114,1,66,1  ; n1992 t=432.346s dur=216ms, freq=370Hz, sample=66, buffer_id=01:42
; t 432.3580 Soft 0 (Instr 1)
; t 432.3580 Soft 0 (Instr 2)
    db 187,0,194,0,78,48,2,5,228,2,78,1  ; n1993 t=432.362s dur=194ms, freq=740Hz, sample=78, buffer_id=01:4E
    db 12,0,211,1,56,37,1,0,208,0,56,1  ; n1994 t=432.549s dur=467ms, freq=208Hz, sample=56, buffer_id=01:38
    db 48,0,143,1,61,37,1,2,21,1,61,1  ; n1995 t=432.560s dur=399ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 25,0,95,1,77,47,2,3,186,2,77,1  ; n1996 t=432.609s dur=351ms, freq=698Hz, sample=77, buffer_id=01:4D
    db 88,1,70,1,65,38,1,6,93,1,65,1  ; n1997 t=432.634s dur=326ms, freq=349Hz, sample=65, buffer_id=01:41
; t 432.6915 Sustain 127 (Instr 1)
; t 432.6915 Sustain 127 (Instr 2)
; t 432.9599 Sustain 0 (Instr 1)
; t 432.9599 Sustain 0 (Instr 2)
    db 4,0,108,0,60,36,1,1,6,1,60,1  ; n1998 t=432.978s dur=108ms, freq=262Hz, sample=60, buffer_id=01:3C
    db 13,0,188,0,54,36,1,4,185,0,54,1  ; n1999 t=432.982s dur=188ms, freq=185Hz, sample=54, buffer_id=01:36
    db 14,0,166,0,75,42,2,5,110,2,75,1  ; n2000 t=432.995s dur=166ms, freq=622Hz, sample=75, buffer_id=01:4B
    db 153,0,117,0,63,37,1,7,55,1,63,1  ; n2001 t=433.008s dur=117ms, freq=311Hz, sample=63, buffer_id=01:3F
    db 18,0,181,1,53,39,1,2,175,0,53,1  ; n2002 t=433.161s dur=437ms, freq=175Hz, sample=53, buffer_id=01:35
    db 46,0,163,1,61,39,1,3,21,1,61,1  ; n2003 t=433.179s dur=419ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 9,0,117,1,80,47,2,0,63,3,80,1  ; n2004 t=433.225s dur=373ms, freq=831Hz, sample=80, buffer_id=01:50
    db 136,1,107,1,68,47,2,6,159,1,68,1  ; n2005 t=433.235s dur=363ms, freq=415Hz, sample=68, buffer_id=01:44
; t 433.2660 Sustain 127 (Instr 1)
; t 433.2660 Sustain 127 (Instr 2)
; t 433.5984 Sustain 0 (Instr 1)
; t 433.5984 Sustain 0 (Instr 2)
    db 5,0,137,0,58,39,1,1,233,0,58,1  ; n2006 t=433.627s dur=137ms, freq=233Hz, sample=58, buffer_id=01:3A
    db 1,0,158,1,66,39,1,4,114,1,66,1  ; n2007 t=433.632s dur=414ms, freq=370Hz, sample=66, buffer_id=01:42
    db 4,0,88,0,61,39,1,3,21,1,61,1  ; n2008 t=433.633s dur=88ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 180,0,152,1,78,52,2,5,228,2,78,1  ; n2009 t=433.637s dur=408ms, freq=740Hz, sample=78, buffer_id=01:4E
; t 433.8144 Sustain 127 (Instr 1)
; t 433.8144 Sustain 127 (Instr 2)
    db 1,0,178,1,56,42,1,0,208,0,56,1  ; n2010 t=433.817s dur=434ms, freq=208Hz, sample=56, buffer_id=01:38
    db 183,0,40,1,61,42,1,3,21,1,61,1  ; n2011 t=433.819s dur=296ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 12,0,125,0,65,40,1,1,93,1,65,1  ; n2012 t=434.002s dur=125ms, freq=349Hz, sample=65, buffer_id=01:41
    db 178,0,130,0,77,52,2,2,186,2,77,1  ; n2013 t=434.015s dur=130ms, freq=698Hz, sample=77, buffer_id=01:4D
; t 434.0461 Sustain 0 (Instr 1)
; t 434.0461 Sustain 0 (Instr 2)
    db 19,0,108,0,54,37,1,6,185,0,54,1  ; n2014 t=434.193s dur=108ms, freq=185Hz, sample=54, buffer_id=01:36
    db 22,0,174,0,60,37,1,7,6,1,60,1  ; n2015 t=434.212s dur=174ms, freq=262Hz, sample=60, buffer_id=01:3C
    db 1,0,108,0,75,51,2,8,110,2,75,1  ; n2016 t=434.234s dur=108ms, freq=622Hz, sample=75, buffer_id=01:4B
    db 110,0,90,0,63,37,1,9,55,1,63,1  ; n2017 t=434.235s dur=90ms, freq=311Hz, sample=63, buffer_id=01:3F
    db 50,0,144,1,53,38,1,1,175,0,53,1  ; n2018 t=434.345s dur=400ms, freq=175Hz, sample=53, buffer_id=01:35
    db 6,0,94,1,61,39,1,2,21,1,61,1  ; n2019 t=434.395s dur=350ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 12,0,87,1,68,54,2,3,159,1,68,1  ; n2020 t=434.401s dur=343ms, freq=415Hz, sample=68, buffer_id=01:44
    db 135,1,76,1,80,54,2,4,63,3,80,1  ; n2021 t=434.413s dur=332ms, freq=831Hz, sample=80, buffer_id=01:50
; t 434.5106 Sustain 127 (Instr 1)
; t 434.5106 Sustain 127 (Instr 2)
; t 434.7454 Sustain 0 (Instr 1)
; t 434.7454 Sustain 0 (Instr 2)
    db 13,0,130,1,66,44,1,0,114,1,66,1  ; n2022 t=434.804s dur=386ms, freq=370Hz, sample=66, buffer_id=01:42
    db 5,0,113,0,58,45,1,5,233,0,58,1  ; n2023 t=434.817s dur=113ms, freq=233Hz, sample=58, buffer_id=01:3A
    db 5,0,90,0,61,45,1,2,21,1,61,1  ; n2024 t=434.822s dur=90ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 151,0,107,1,78,62,2,6,228,2,78,1  ; n2025 t=434.827s dur=363ms, freq=740Hz, sample=78, buffer_id=01:4E
; t 434.9562 Sustain 127 (Instr 1)
; t 434.9562 Sustain 127 (Instr 2)
    db 7,0,128,1,56,47,1,1,208,0,56,1  ; n2026 t=434.978s dur=384ms, freq=208Hz, sample=56, buffer_id=01:38
    db 198,0,34,1,61,47,1,2,21,1,61,1  ; n2027 t=434.986s dur=290ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 3,0,94,1,65,49,1,3,93,1,65,1  ; n2028 t=435.184s dur=350ms, freq=349Hz, sample=65, buffer_id=01:41
    db 136,0,91,1,77,61,2,4,186,2,77,1  ; n2029 t=435.187s dur=347ms, freq=698Hz, sample=77, buffer_id=01:4D
; t 435.1910 Sustain 0 (Instr 1)
; t 435.1910 Sustain 0 (Instr 2)
    db 81,0,63,3,55,58,1,5,196,0,55,1  ; n2030 t=435.323s dur=831ms, freq=196Hz, sample=55, buffer_id=01:37
; t 435.3797 Sustain 127 (Instr 1)
; t 435.3797 Sustain 127 (Instr 2)
    db 48,0,16,2,61,60,1,2,21,1,61,1  ; n2031 t=435.404s dur=528ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 121,0,18,2,64,60,1,0,74,1,64,1  ; n2032 t=435.452s dur=530ms, freq=330Hz, sample=64, buffer_id=01:40
; t 435.5339 Sustain 0 (Instr 1)
; t 435.5339 Sustain 0 (Instr 2)
    db 12,0,61,5,70,70,2,1,210,1,70,1  ; n2033 t=435.573s dur=1341ms, freq=466Hz, sample=70, buffer_id=01:46
    db 78,2,50,5,82,70,2,6,164,3,82,1  ; n2034 t=435.584s dur=1330ms, freq=932Hz, sample=82, buffer_id=01:52
    db 5,0,59,4,56,40,1,2,208,0,56,1  ; n2035 t=436.175s dur=1083ms, freq=208Hz, sample=56, buffer_id=01:38
    db 2,0,210,3,65,40,1,3,93,1,65,1  ; n2036 t=436.180s dur=978ms, freq=349Hz, sample=65, buffer_id=01:41
    db 210,2,39,4,61,40,1,4,21,1,61,1  ; n2037 t=436.182s dur=1063ms, freq=277Hz, sample=61, buffer_id=01:3D
; t 436.6534 Sustain 127 (Instr 1)
; t 436.6534 Sustain 127 (Instr 2)
    db 12,0,67,1,68,40,2,0,159,1,68,1  ; n2038 t=436.904s dur=323ms, freq=415Hz, sample=68, buffer_id=01:44
; t 436.9144 Sustain 0 (Instr 1)
; t 436.9144 Sustain 0 (Instr 2)
    db 227,2,42,1,80,40,2,5,63,3,80,1  ; n2039 t=436.916s dur=298ms, freq=831Hz, sample=80, buffer_id=01:50
; t 436.9217 Soft 127 (Instr 1)
; t 436.9217 Soft 127 (Instr 2)
    db 42,0,149,5,32,34,1,0,52,0,32,1  ; n2040 t=437.654s dur=1429ms, freq=52Hz, sample=32, buffer_id=01:20
    db 130,0,37,14,44,35,1,1,104,0,44,1  ; n2041 t=437.696s dur=3621ms, freq=104Hz, sample=44, buffer_id=01:2C
    db 55,0,135,4,54,37,1,2,185,0,54,1  ; n2042 t=437.826s dur=1159ms, freq=185Hz, sample=54, buffer_id=01:36
    db 99,3,155,3,60,37,1,3,6,1,60,1  ; n2043 t=437.881s dur=923ms, freq=262Hz, sample=60, buffer_id=01:3C
    db 230,0,225,0,63,38,1,4,55,1,63,1  ; n2044 t=438.747s dur=225ms, freq=311Hz, sample=63, buffer_id=01:3F
    db 141,0,18,1,61,35,1,5,21,1,61,1  ; n2045 t=438.977s dur=274ms, freq=277Hz, sample=61, buffer_id=01:3D
    db 241,0,151,8,37,34,1,3,69,0,37,1  ; n2046 t=439.118s dur=2199ms, freq=69Hz, sample=37, buffer_id=01:25
    db 7,0,166,7,53,34,1,0,175,0,53,1  ; n2047 t=439.360s dur=1958ms, freq=175Hz, sample=53, buffer_id=01:35
    db 0,0,158,7,61,34,1,5,21,1,61,1  ; n2048 t=439.367s dur=1950ms, freq=277Hz, sample=61, buffer_id=01:3D
; t 439.3867 Sustain 127 (Instr 2)
; t 439.3930 Sustain 127 (Instr 1)
; t 439.4255 Soft 0 (Instr 2)
; t 439.4318 Soft 0 (Instr 1)
; t 441.3177 Sustain 0 (Instr 1)
; t 441.3649 Sustain 0 (Instr 2)
    db 255,255,255,255,255,255,255,255,255,255,255,255  ; End marker

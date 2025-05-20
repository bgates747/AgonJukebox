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

total_notes: equ 5694
midi_data:
    db 9,0,111,0,36,120,2,0,65,0,36,2  ; n1 t=3.523s dur=111ms, freq=65Hz, sample=36, buffer_id=02:24
    db 0,0,199,27,52,120,10,1,165,0,52,2  ; n2 t=3.532s dur=7111ms, freq=165Hz, sample=52, buffer_id=02:34
    db 9,0,199,27,48,115,13,2,131,0,48,2  ; n3 t=3.532s dur=7111ms, freq=131Hz, sample=48, buffer_id=02:30
    db 0,0,199,27,67,120,6,3,136,1,67,2  ; n4 t=3.542s dur=7111ms, freq=392Hz, sample=67, buffer_id=02:43
    db 14,0,199,27,60,120,8,4,6,1,60,2  ; n5 t=3.542s dur=7111ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 0,0,111,0,36,120,1,5,65,0,36,1  ; n6 t=3.556s dur=111ms, freq=65Hz, sample=36, buffer_id=01:24
    db 0,0,100,0,50,124,14,6,165,0,50,14  ; n7 t=3.556s dur=100ms, freq=165Hz, sample=50, buffer_id=0E:32
    db 155,2,100,0,55,124,14,7,196,0,55,14  ; n8 t=3.556s dur=100ms, freq=196Hz, sample=55, buffer_id=0E:37
    db 0,0,100,0,50,124,14,0,165,0,50,14  ; n9 t=4.222s dur=100ms, freq=165Hz, sample=50, buffer_id=0E:32
    db 111,0,100,0,55,124,14,5,196,0,55,14  ; n10 t=4.222s dur=100ms, freq=196Hz, sample=55, buffer_id=0E:37
    db 0,0,100,0,50,124,14,7,165,0,50,14  ; n11 t=4.333s dur=100ms, freq=165Hz, sample=50, buffer_id=0E:32
    db 111,0,100,0,55,124,14,6,196,0,55,14  ; n12 t=4.333s dur=100ms, freq=196Hz, sample=55, buffer_id=0E:37
    db 0,0,100,0,50,124,14,8,165,0,50,14  ; n13 t=4.444s dur=100ms, freq=165Hz, sample=50, buffer_id=0E:32
    db 190,0,100,0,55,124,14,9,196,0,55,14  ; n14 t=4.444s dur=100ms, freq=196Hz, sample=55, buffer_id=0E:37
    db 32,0,111,0,36,120,2,0,65,0,36,2  ; n15 t=4.634s dur=111ms, freq=65Hz, sample=36, buffer_id=02:24
    db 122,2,111,0,36,120,1,5,65,0,36,1  ; n16 t=4.667s dur=111ms, freq=65Hz, sample=36, buffer_id=01:24
    db 32,0,111,0,36,120,2,5,65,0,36,2  ; n17 t=5.301s dur=111ms, freq=65Hz, sample=36, buffer_id=02:24
    db 0,0,111,0,36,120,1,0,65,0,36,1  ; n18 t=5.333s dur=111ms, freq=65Hz, sample=36, buffer_id=01:24
    db 0,0,100,0,50,124,14,6,165,0,50,14  ; n19 t=5.333s dur=100ms, freq=165Hz, sample=50, buffer_id=0E:32
    db 155,2,100,0,55,124,14,7,196,0,55,14  ; n20 t=5.333s dur=100ms, freq=196Hz, sample=55, buffer_id=0E:37
    db 0,0,100,0,50,124,14,0,165,0,50,14  ; n21 t=6.000s dur=100ms, freq=165Hz, sample=50, buffer_id=0E:32
    db 111,0,100,0,55,124,14,5,196,0,55,14  ; n22 t=6.000s dur=100ms, freq=196Hz, sample=55, buffer_id=0E:37
    db 0,0,100,0,50,124,14,7,165,0,50,14  ; n23 t=6.111s dur=100ms, freq=165Hz, sample=50, buffer_id=0E:32
    db 111,0,100,0,55,124,14,6,196,0,55,14  ; n24 t=6.111s dur=100ms, freq=196Hz, sample=55, buffer_id=0E:37
    db 0,0,100,0,50,124,14,9,165,0,50,14  ; n25 t=6.222s dur=100ms, freq=165Hz, sample=50, buffer_id=0E:32
    db 111,0,100,0,55,124,14,8,196,0,55,14  ; n26 t=6.222s dur=100ms, freq=196Hz, sample=55, buffer_id=0E:37
    db 0,0,100,0,50,124,14,5,165,0,50,14  ; n27 t=6.333s dur=100ms, freq=165Hz, sample=50, buffer_id=0E:32
    db 79,0,100,0,55,124,14,0,196,0,55,14  ; n28 t=6.333s dur=100ms, freq=196Hz, sample=55, buffer_id=0E:37
    db 32,0,111,0,36,120,2,6,65,0,36,2  ; n29 t=6.412s dur=111ms, freq=65Hz, sample=36, buffer_id=02:24
    db 122,2,111,0,36,120,1,7,65,0,36,1  ; n30 t=6.444s dur=111ms, freq=65Hz, sample=36, buffer_id=01:24
    db 32,0,111,0,36,120,2,0,65,0,36,2  ; n31 t=7.079s dur=111ms, freq=65Hz, sample=36, buffer_id=02:24
    db 0,0,111,0,36,120,1,5,65,0,36,1  ; n32 t=7.111s dur=111ms, freq=65Hz, sample=36, buffer_id=01:24
    db 0,0,100,0,50,124,14,6,165,0,50,14  ; n33 t=7.111s dur=100ms, freq=165Hz, sample=50, buffer_id=0E:32
    db 155,2,100,0,55,124,14,7,196,0,55,14  ; n34 t=7.111s dur=100ms, freq=196Hz, sample=55, buffer_id=0E:37
    db 0,0,100,0,50,124,14,0,165,0,50,14  ; n35 t=7.778s dur=100ms, freq=165Hz, sample=50, buffer_id=0E:32
    db 111,0,100,0,55,124,14,5,196,0,55,14  ; n36 t=7.778s dur=100ms, freq=196Hz, sample=55, buffer_id=0E:37
    db 0,0,100,0,50,124,14,7,165,0,50,14  ; n37 t=7.889s dur=100ms, freq=165Hz, sample=50, buffer_id=0E:32
    db 111,0,100,0,55,124,14,6,196,0,55,14  ; n38 t=7.889s dur=100ms, freq=196Hz, sample=55, buffer_id=0E:37
    db 0,0,100,0,50,124,14,8,165,0,50,14  ; n39 t=8.000s dur=100ms, freq=165Hz, sample=50, buffer_id=0E:32
    db 190,0,100,0,55,124,14,9,196,0,55,14  ; n40 t=8.000s dur=100ms, freq=196Hz, sample=55, buffer_id=0E:37
    db 32,0,111,0,36,120,2,0,65,0,36,2  ; n41 t=8.190s dur=111ms, freq=65Hz, sample=36, buffer_id=02:24
    db 122,2,111,0,36,120,1,5,65,0,36,1  ; n42 t=8.222s dur=111ms, freq=65Hz, sample=36, buffer_id=01:24
    db 32,0,111,0,36,120,2,5,65,0,36,2  ; n43 t=8.857s dur=111ms, freq=65Hz, sample=36, buffer_id=02:24
    db 0,0,111,0,36,120,1,0,65,0,36,1  ; n44 t=8.889s dur=111ms, freq=65Hz, sample=36, buffer_id=01:24
    db 0,0,100,0,50,124,14,6,165,0,50,14  ; n45 t=8.889s dur=100ms, freq=165Hz, sample=50, buffer_id=0E:32
    db 155,2,100,0,55,124,14,7,196,0,55,14  ; n46 t=8.889s dur=100ms, freq=196Hz, sample=55, buffer_id=0E:37
    db 0,0,100,0,50,124,14,0,165,0,50,14  ; n47 t=9.556s dur=100ms, freq=165Hz, sample=50, buffer_id=0E:32
    db 111,0,100,0,55,124,14,5,196,0,55,14  ; n48 t=9.556s dur=100ms, freq=196Hz, sample=55, buffer_id=0E:37
    db 0,0,100,0,50,124,14,7,165,0,50,14  ; n49 t=9.667s dur=100ms, freq=165Hz, sample=50, buffer_id=0E:32
    db 111,0,100,0,55,124,14,6,196,0,55,14  ; n50 t=9.667s dur=100ms, freq=196Hz, sample=55, buffer_id=0E:37
    db 0,0,100,0,50,124,14,9,165,0,50,14  ; n51 t=9.778s dur=100ms, freq=165Hz, sample=50, buffer_id=0E:32
    db 111,0,100,0,55,124,14,8,196,0,55,14  ; n52 t=9.778s dur=100ms, freq=196Hz, sample=55, buffer_id=0E:37
    db 0,0,100,0,50,124,14,5,165,0,50,14  ; n53 t=9.889s dur=100ms, freq=165Hz, sample=50, buffer_id=0E:32
    db 79,0,100,0,55,124,14,0,196,0,55,14  ; n54 t=9.889s dur=100ms, freq=196Hz, sample=55, buffer_id=0E:37
    db 32,0,111,0,36,120,2,6,65,0,36,2  ; n55 t=9.968s dur=111ms, freq=65Hz, sample=36, buffer_id=02:24
    db 222,0,111,0,36,120,1,7,65,0,36,1  ; n56 t=10.000s dur=111ms, freq=65Hz, sample=36, buffer_id=01:24
    db 91,1,175,0,62,124,5,0,74,1,62,5  ; n57 t=10.222s dur=175ms, freq=330Hz, sample=62, buffer_id=05:3E
    db 65,0,100,0,67,124,5,5,93,1,67,5  ; n58 t=10.569s dur=100ms, freq=349Hz, sample=67, buffer_id=05:43
    db 9,0,112,0,36,120,2,0,65,0,36,2  ; n59 t=10.634s dur=112ms, freq=65Hz, sample=36, buffer_id=02:24
    db 0,0,16,7,52,120,10,6,165,0,52,2  ; n60 t=10.643s dur=1808ms, freq=165Hz, sample=52, buffer_id=02:34
    db 9,0,33,14,48,115,13,7,131,0,48,2  ; n61 t=10.643s dur=3617ms, freq=131Hz, sample=48, buffer_id=02:30
    db 0,0,34,14,67,120,6,8,136,1,67,2  ; n62 t=10.653s dur=3618ms, freq=392Hz, sample=67, buffer_id=02:43
    db 14,0,34,14,60,120,8,9,6,1,60,2  ; n63 t=10.653s dur=3618ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 0,0,113,0,36,120,1,10,65,0,36,1  ; n64 t=10.667s dur=113ms, freq=65Hz, sample=36, buffer_id=01:24
    db 0,0,100,0,67,124,5,11,136,1,67,5  ; n65 t=10.667s dur=100ms, freq=392Hz, sample=67, buffer_id=05:43
    db 0,0,100,0,50,124,14,12,165,0,50,14  ; n66 t=10.667s dur=100ms, freq=165Hz, sample=50, buffer_id=0E:32
    db 254,0,100,0,55,124,14,13,196,0,55,14  ; n67 t=10.667s dur=100ms, freq=196Hz, sample=55, buffer_id=0E:37
    db 168,1,249,3,72,124,5,1,11,2,72,5  ; n68 t=10.921s dur=1017ms, freq=523Hz, sample=72, buffer_id=05:48
    db 0,0,100,0,50,124,14,0,165,0,50,14  ; n69 t=11.345s dur=100ms, freq=165Hz, sample=50, buffer_id=0E:32
    db 113,0,100,0,55,124,14,2,196,0,55,14  ; n70 t=11.345s dur=100ms, freq=196Hz, sample=55, buffer_id=0E:37
    db 0,0,100,0,50,124,14,3,165,0,50,14  ; n71 t=11.458s dur=100ms, freq=165Hz, sample=50, buffer_id=0E:32
    db 113,0,100,0,55,124,14,4,196,0,55,14  ; n72 t=11.458s dur=100ms, freq=196Hz, sample=55, buffer_id=0E:37
    db 0,0,100,0,50,124,14,5,165,0,50,14  ; n73 t=11.571s dur=100ms, freq=165Hz, sample=50, buffer_id=0E:32
    db 193,0,100,0,55,124,14,10,196,0,55,14  ; n74 t=11.571s dur=100ms, freq=196Hz, sample=55, buffer_id=0E:37
    db 33,0,113,0,36,120,2,0,65,0,36,2  ; n75 t=11.764s dur=113ms, freq=65Hz, sample=36, buffer_id=02:24
    db 226,0,113,0,36,120,1,2,65,0,36,1  ; n76 t=11.797s dur=113ms, freq=65Hz, sample=36, buffer_id=01:24
    db 97,1,113,0,62,124,5,3,38,1,62,5  ; n77 t=12.024s dur=113ms, freq=294Hz, sample=62, buffer_id=05:3E
    db 66,0,100,0,62,124,5,0,74,1,62,5  ; n78 t=12.377s dur=100ms, freq=330Hz, sample=62, buffer_id=05:3E
    db 9,0,113,0,36,120,2,1,65,0,36,2  ; n79 t=12.443s dur=113ms, freq=65Hz, sample=36, buffer_id=02:24
    db 24,0,154,6,53,120,10,2,175,0,53,2  ; n80 t=12.452s dur=1690ms, freq=175Hz, sample=53, buffer_id=02:35
    db 0,0,113,0,36,120,1,3,65,0,36,1  ; n81 t=12.476s dur=113ms, freq=65Hz, sample=36, buffer_id=01:24
    db 0,0,219,4,67,124,5,4,93,1,67,5  ; n82 t=12.476s dur=1243ms, freq=349Hz, sample=67, buffer_id=05:43
    db 0,0,100,0,55,124,14,5,175,0,55,14  ; n83 t=12.476s dur=100ms, freq=175Hz, sample=55, buffer_id=0E:37
    db 166,2,100,0,55,124,14,11,196,0,55,14  ; n84 t=12.476s dur=100ms, freq=196Hz, sample=55, buffer_id=0E:37
    db 0,0,100,0,55,124,14,0,175,0,55,14  ; n85 t=13.154s dur=100ms, freq=175Hz, sample=55, buffer_id=0E:37
    db 113,0,100,0,55,124,14,1,196,0,55,14  ; n86 t=13.154s dur=100ms, freq=196Hz, sample=55, buffer_id=0E:37
    db 0,0,100,0,55,124,14,3,175,0,55,14  ; n87 t=13.267s dur=100ms, freq=175Hz, sample=55, buffer_id=0E:37
    db 113,0,100,0,55,124,14,6,196,0,55,14  ; n88 t=13.267s dur=100ms, freq=196Hz, sample=55, buffer_id=0E:37
    db 0,0,100,0,55,124,14,12,175,0,55,14  ; n89 t=13.380s dur=100ms, freq=175Hz, sample=55, buffer_id=0E:37
    db 113,0,100,0,55,124,14,13,196,0,55,14  ; n90 t=13.380s dur=100ms, freq=196Hz, sample=55, buffer_id=0E:37 [TRUNCATE prev:ch13 @10666.7ms -> 13380.4ms]
    db 0,0,100,0,55,124,14,10,175,0,55,14  ; n91 t=13.493s dur=100ms, freq=175Hz, sample=55, buffer_id=0E:37 [TRUNCATE prev:ch10 @11571.2ms -> 13493.4ms]
    db 80,0,100,0,55,124,14,5,196,0,55,14  ; n92 t=13.493s dur=100ms, freq=196Hz, sample=55, buffer_id=0E:37 [TRUNCATE prev:ch5 @12475.8ms -> 13493.4ms]
    db 33,0,113,0,36,120,2,0,65,0,36,2  ; n93 t=13.573s dur=113ms, freq=65Hz, sample=36, buffer_id=02:24
    db 226,0,113,0,36,120,1,1,65,0,36,1  ; n94 t=13.607s dur=113ms, freq=65Hz, sample=36, buffer_id=01:24
    db 97,1,179,0,67,124,5,3,136,1,67,5  ; n95 t=13.833s dur=179ms, freq=392Hz, sample=67, buffer_id=05:43
    db 66,0,100,0,67,124,5,0,184,1,67,5  ; n96 t=14.186s dur=100ms, freq=440Hz, sample=67, buffer_id=05:43
    db 10,0,113,0,36,120,2,1,65,0,36,2  ; n97 t=14.252s dur=113ms, freq=65Hz, sample=36, buffer_id=02:24
    db 0,0,154,6,53,120,10,3,175,0,53,2  ; n98 t=14.261s dur=1690ms, freq=175Hz, sample=53, buffer_id=02:35
    db 9,0,34,14,48,115,13,4,131,0,48,2  ; n99 t=14.261s dur=3618ms, freq=131Hz, sample=48, buffer_id=02:30
    db 0,0,34,14,67,120,6,5,136,1,67,2  ; n100 t=14.271s dur=3618ms, freq=392Hz, sample=67, buffer_id=02:43
    db 14,0,34,14,60,120,8,6,6,1,60,2  ; n101 t=14.271s dur=3618ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 0,0,113,0,36,120,1,10,65,0,36,1  ; n102 t=14.285s dur=113ms, freq=65Hz, sample=36, buffer_id=01:24
    db 0,0,100,0,72,124,5,11,238,1,72,5  ; n103 t=14.285s dur=100ms, freq=494Hz, sample=72, buffer_id=05:48
    db 0,0,100,0,55,124,14,12,175,0,55,14  ; n104 t=14.285s dur=100ms, freq=175Hz, sample=55, buffer_id=0E:37 [TRUNCATE prev:ch12 @13380.4ms -> 14284.9ms]
    db 254,0,100,0,55,124,14,13,196,0,55,14  ; n105 t=14.285s dur=100ms, freq=196Hz, sample=55, buffer_id=0E:37 [TRUNCATE prev:ch13 @13380.4ms -> 14284.9ms]
    db 168,1,249,3,77,124,5,0,186,2,77,5  ; n106 t=14.539s dur=1017ms, freq=698Hz, sample=77, buffer_id=05:4D
    db 0,0,100,0,55,124,14,1,175,0,55,14  ; n107 t=14.963s dur=100ms, freq=175Hz, sample=55, buffer_id=0E:37
    db 113,0,100,0,65,124,14,2,136,1,65,14  ; n108 t=14.963s dur=100ms, freq=392Hz, sample=65, buffer_id=0E:41
    db 0,0,100,0,55,124,14,7,175,0,55,14  ; n109 t=15.076s dur=100ms, freq=175Hz, sample=55, buffer_id=0E:37
    db 113,0,100,0,55,124,14,8,196,0,55,14  ; n110 t=15.076s dur=100ms, freq=196Hz, sample=55, buffer_id=0E:37
    db 0,0,100,0,55,124,14,9,175,0,55,14  ; n111 t=15.190s dur=100ms, freq=175Hz, sample=55, buffer_id=0E:37
    db 193,0,100,0,55,124,14,10,196,0,55,14  ; n112 t=15.190s dur=100ms, freq=196Hz, sample=55, buffer_id=0E:37
    db 33,0,113,0,36,120,2,1,65,0,36,2  ; n113 t=15.383s dur=113ms, freq=65Hz, sample=36, buffer_id=02:24
    db 226,0,113,0,36,120,1,2,65,0,36,1  ; n114 t=15.416s dur=113ms, freq=65Hz, sample=36, buffer_id=01:24
    db 97,1,113,0,67,124,5,7,184,1,67,5  ; n115 t=15.642s dur=113ms, freq=440Hz, sample=67, buffer_id=05:43
    db 66,0,100,0,72,124,5,0,238,1,72,5  ; n116 t=15.995s dur=100ms, freq=494Hz, sample=72, buffer_id=05:48
    db 9,0,113,0,36,120,2,2,65,0,36,2  ; n117 t=16.061s dur=113ms, freq=65Hz, sample=36, buffer_id=02:24
    db 24,0,17,7,52,120,10,1,165,0,52,2  ; n118 t=16.070s dur=1809ms, freq=165Hz, sample=52, buffer_id=02:34
    db 0,0,113,0,36,120,1,7,65,0,36,1  ; n119 t=16.094s dur=113ms, freq=65Hz, sample=36, buffer_id=01:24
    db 0,0,137,1,72,124,5,8,11,2,72,5  ; n120 t=16.094s dur=393ms, freq=523Hz, sample=72, buffer_id=05:48
    db 0,0,100,0,50,124,14,9,165,0,50,14  ; n121 t=16.094s dur=100ms, freq=165Hz, sample=50, buffer_id=0E:32
    db 196,1,100,0,55,124,14,11,196,0,55,14  ; n122 t=16.094s dur=100ms, freq=196Hz, sample=55, buffer_id=0E:37
    db 226,0,137,1,72,124,5,2,75,2,72,5  ; n123 t=16.546s dur=393ms, freq=587Hz, sample=72, buffer_id=05:48
    db 0,0,100,0,50,124,14,0,165,0,50,14  ; n124 t=16.773s dur=100ms, freq=165Hz, sample=50, buffer_id=0E:32
    db 113,0,100,0,55,124,14,3,196,0,55,14  ; n125 t=16.773s dur=100ms, freq=196Hz, sample=55, buffer_id=0E:37
    db 0,0,100,0,50,124,14,7,165,0,50,14  ; n126 t=16.886s dur=100ms, freq=165Hz, sample=50, buffer_id=0E:32
    db 113,0,100,0,55,124,14,8,196,0,55,14  ; n127 t=16.886s dur=100ms, freq=196Hz, sample=55, buffer_id=0E:37
    db 0,0,83,1,77,124,5,9,147,2,77,5  ; n128 t=16.999s dur=339ms, freq=659Hz, sample=77, buffer_id=05:4D
    db 0,0,100,0,50,124,14,10,165,0,50,14  ; n129 t=16.999s dur=100ms, freq=165Hz, sample=50, buffer_id=0E:32
    db 113,0,100,0,55,124,14,12,196,0,55,14  ; n130 t=16.999s dur=100ms, freq=196Hz, sample=55, buffer_id=0E:37 [TRUNCATE prev:ch12 @14284.9ms -> 16998.6ms]
    db 0,0,100,0,50,124,14,3,165,0,50,14  ; n131 t=17.112s dur=100ms, freq=165Hz, sample=50, buffer_id=0E:32
    db 80,0,100,0,55,124,14,0,196,0,55,14  ; n132 t=17.112s dur=100ms, freq=196Hz, sample=55, buffer_id=0E:37
    db 33,0,113,0,29,120,2,2,49,0,29,2  ; n133 t=17.192s dur=113ms, freq=49Hz, sample=29, buffer_id=02:1D
    db 226,0,113,0,31,120,1,7,49,0,31,1  ; n134 t=17.225s dur=113ms, freq=49Hz, sample=31, buffer_id=01:1F
    db 97,1,179,0,62,124,5,0,74,1,62,5  ; n135 t=17.451s dur=179ms, freq=330Hz, sample=62, buffer_id=05:3E
    db 66,0,100,0,67,124,5,2,93,1,67,5  ; n136 t=17.804s dur=100ms, freq=349Hz, sample=67, buffer_id=05:43
    db 9,0,113,0,36,120,2,0,65,0,36,2  ; n137 t=17.870s dur=113ms, freq=65Hz, sample=36, buffer_id=02:24
    db 0,0,17,7,52,120,10,3,165,0,52,2  ; n138 t=17.880s dur=1809ms, freq=165Hz, sample=52, buffer_id=02:34
    db 9,0,17,7,48,115,13,7,131,0,48,2  ; n139 t=17.880s dur=1809ms, freq=131Hz, sample=48, buffer_id=02:30
    db 0,0,17,7,67,120,6,8,136,1,67,2  ; n140 t=17.889s dur=1809ms, freq=392Hz, sample=67, buffer_id=02:43
    db 14,0,17,7,60,120,8,9,6,1,60,2  ; n141 t=17.889s dur=1809ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 0,0,113,0,36,120,1,10,65,0,36,1  ; n142 t=17.903s dur=113ms, freq=65Hz, sample=36, buffer_id=01:24
    db 0,0,100,0,67,124,5,11,136,1,67,5  ; n143 t=17.903s dur=100ms, freq=392Hz, sample=67, buffer_id=05:43
    db 0,0,100,0,50,124,14,12,165,0,50,14  ; n144 t=17.903s dur=100ms, freq=165Hz, sample=50, buffer_id=0E:32
    db 254,0,100,0,55,124,14,13,196,0,55,14  ; n145 t=17.903s dur=100ms, freq=196Hz, sample=55, buffer_id=0E:37 [TRUNCATE prev:ch13 @14284.9ms -> 17903.2ms]
    db 168,1,249,3,72,124,5,1,11,2,72,5  ; n146 t=18.158s dur=1017ms, freq=523Hz, sample=72, buffer_id=05:48
    db 0,0,100,0,50,124,14,0,165,0,50,14  ; n147 t=18.582s dur=100ms, freq=165Hz, sample=50, buffer_id=0E:32
    db 113,0,100,0,55,124,14,2,196,0,55,14  ; n148 t=18.582s dur=100ms, freq=196Hz, sample=55, buffer_id=0E:37
    db 0,0,100,0,50,124,14,4,165,0,50,14  ; n149 t=18.695s dur=100ms, freq=165Hz, sample=50, buffer_id=0E:32
    db 113,0,100,0,55,124,14,5,196,0,55,14  ; n150 t=18.695s dur=100ms, freq=196Hz, sample=55, buffer_id=0E:37
    db 0,0,100,0,50,124,14,6,165,0,50,14  ; n151 t=18.808s dur=100ms, freq=165Hz, sample=50, buffer_id=0E:32
    db 193,0,100,0,55,124,14,10,196,0,55,14  ; n152 t=18.808s dur=100ms, freq=196Hz, sample=55, buffer_id=0E:37
    db 33,0,113,0,36,120,2,0,65,0,36,2  ; n153 t=19.001s dur=113ms, freq=65Hz, sample=36, buffer_id=02:24
    db 226,0,113,0,36,120,1,2,65,0,36,1  ; n154 t=19.034s dur=113ms, freq=65Hz, sample=36, buffer_id=01:24
    db 97,1,113,0,72,124,5,4,75,2,72,5  ; n155 t=19.260s dur=113ms, freq=587Hz, sample=72, buffer_id=05:48
    db 66,0,100,0,77,124,5,0,147,2,77,5  ; n156 t=19.613s dur=100ms, freq=659Hz, sample=77, buffer_id=05:4D
    db 9,0,113,0,36,120,2,1,69,0,36,2  ; n157 t=19.679s dur=113ms, freq=69Hz, sample=36, buffer_id=02:24
    db 0,0,76,5,53,120,10,2,175,0,53,2  ; n158 t=19.689s dur=1356ms, freq=175Hz, sample=53, buffer_id=02:35
    db 9,0,76,5,48,115,13,4,139,0,48,2  ; n159 t=19.689s dur=1356ms, freq=139Hz, sample=48, buffer_id=02:30
    db 0,0,76,5,67,120,6,5,159,1,67,2  ; n160 t=19.698s dur=1356ms, freq=415Hz, sample=67, buffer_id=02:43
    db 14,0,0,1,61,120,8,6,21,1,61,2  ; n161 t=19.698s dur=256ms, freq=277Hz, sample=61, buffer_id=02:3D
    db 0,0,113,0,36,120,1,10,69,0,36,1  ; n162 t=19.712s dur=113ms, freq=69Hz, sample=36, buffer_id=01:24
    db 0,0,219,4,77,124,5,11,186,2,77,5  ; n163 t=19.712s dur=1243ms, freq=698Hz, sample=77, buffer_id=05:4D
    db 0,0,100,0,55,124,14,12,175,0,55,14  ; n164 t=19.712s dur=100ms, freq=175Hz, sample=55, buffer_id=0E:37
    db 166,2,100,0,55,124,14,13,208,0,55,14  ; n165 t=19.712s dur=100ms, freq=208Hz, sample=55, buffer_id=0E:37 [TRUNCATE prev:ch13 @17903.2ms -> 19712.3ms]
    db 0,0,100,0,55,124,14,0,175,0,55,14  ; n166 t=20.391s dur=100ms, freq=175Hz, sample=55, buffer_id=0E:37
    db 113,0,100,0,55,124,14,1,208,0,55,14  ; n167 t=20.391s dur=100ms, freq=208Hz, sample=55, buffer_id=0E:37
    db 0,0,100,0,55,124,14,3,175,0,55,14  ; n168 t=20.504s dur=100ms, freq=175Hz, sample=55, buffer_id=0E:37
    db 113,0,100,0,55,124,14,6,208,0,55,14  ; n169 t=20.504s dur=100ms, freq=208Hz, sample=55, buffer_id=0E:37
    db 0,0,100,0,55,124,14,7,175,0,55,14  ; n170 t=20.617s dur=100ms, freq=175Hz, sample=55, buffer_id=0E:37
    db 113,0,100,0,55,124,14,8,208,0,55,14  ; n171 t=20.617s dur=100ms, freq=208Hz, sample=55, buffer_id=0E:37
    db 0,0,100,0,55,124,14,9,175,0,55,14  ; n172 t=20.730s dur=100ms, freq=175Hz, sample=55, buffer_id=0E:37
    db 80,0,100,0,55,124,14,10,208,0,55,14  ; n173 t=20.730s dur=100ms, freq=208Hz, sample=55, buffer_id=0E:37
    db 33,0,113,0,36,120,2,0,69,0,36,2  ; n174 t=20.810s dur=113ms, freq=69Hz, sample=36, buffer_id=02:24
    db 207,0,113,0,36,120,1,1,69,0,36,1  ; n175 t=20.843s dur=113ms, freq=69Hz, sample=36, buffer_id=01:24
    db 5,0,113,0,65,110,4,3,136,1,65,4  ; n176 t=21.050s dur=113ms, freq=392Hz, sample=65, buffer_id=04:41
    db 14,0,113,0,77,110,16,6,16,3,77,16  ; n177 t=21.055s dur=113ms, freq=784Hz, sample=77, buffer_id=10:4D
    db 0,0,113,0,67,124,5,7,136,1,67,5  ; n178 t=21.069s dur=113ms, freq=392Hz, sample=67, buffer_id=05:43
    db 79,1,113,0,55,124,14,12,196,0,55,14  ; n179 t=21.069s dur=113ms, freq=196Hz, sample=55, buffer_id=0E:37 [TRUNCATE prev:ch12 @19712.3ms -> 21069.2ms]
    db 5,0,100,0,65,110,4,0,136,1,65,4  ; n180 t=21.404s dur=100ms, freq=392Hz, sample=65, buffer_id=04:41
    db 14,0,100,0,77,110,16,1,16,3,77,16  ; n181 t=21.408s dur=100ms, freq=784Hz, sample=77, buffer_id=10:4D
    db 0,0,100,0,67,124,5,2,136,1,67,5  ; n182 t=21.422s dur=100ms, freq=392Hz, sample=67, buffer_id=05:43
    db 80,0,100,0,55,124,14,3,196,0,55,14  ; n183 t=21.422s dur=100ms, freq=196Hz, sample=55, buffer_id=0E:37
    db 0,0,149,1,60,110,4,4,6,1,60,4  ; n184 t=21.503s dur=405ms, freq=262Hz, sample=60, buffer_id=04:3C
    db 5,0,149,1,65,110,4,5,74,1,65,4  ; n185 t=21.503s dur=405ms, freq=330Hz, sample=65, buffer_id=04:41
    db 14,0,177,1,89,110,16,6,39,5,89,16  ; n186 t=21.507s dur=433ms, freq=1319Hz, sample=89, buffer_id=10:59
    db 0,0,149,1,67,124,5,8,93,1,67,5  ; n187 t=21.521s dur=405ms, freq=349Hz, sample=67, buffer_id=05:43
    db 0,0,149,1,55,124,14,7,175,0,55,14  ; n188 t=21.521s dur=405ms, freq=175Hz, sample=55, buffer_id=0E:37
    db 0,0,149,1,55,124,14,11,220,0,55,14  ; n189 t=21.521s dur=405ms, freq=220Hz, sample=55, buffer_id=0E:37
    db 163,1,149,1,60,124,14,9,6,1,60,14  ; n190 t=21.521s dur=405ms, freq=262Hz, sample=60, buffer_id=0E:3C
    db 9,0,113,0,29,120,2,0,49,0,29,2  ; n191 t=21.941s dur=113ms, freq=49Hz, sample=29, buffer_id=02:1D
    db 5,0,113,0,43,115,13,1,98,0,43,2  ; n192 t=21.950s dur=113ms, freq=98Hz, sample=43, buffer_id=02:2B
    db 0,0,100,0,55,110,4,2,196,0,55,4  ; n193 t=21.955s dur=100ms, freq=196Hz, sample=55, buffer_id=04:37
    db 5,0,100,0,60,110,4,3,38,1,60,4  ; n194 t=21.955s dur=100ms, freq=294Hz, sample=60, buffer_id=04:3C
    db 14,0,100,0,84,110,16,10,151,4,84,16  ; n195 t=21.960s dur=100ms, freq=1175Hz, sample=84, buffer_id=10:54
    db 0,0,113,0,43,120,1,12,98,0,43,1  ; n196 t=21.974s dur=113ms, freq=98Hz, sample=43, buffer_id=01:2B
    db 0,0,100,0,67,124,5,13,136,1,67,5  ; n197 t=21.974s dur=100ms, freq=392Hz, sample=67, buffer_id=05:43
    db 0,0,100,0,55,124,14,7,196,0,55,14  ; n198 t=21.974s dur=100ms, freq=196Hz, sample=55, buffer_id=0E:37 [TRUNCATE prev:ch7 @21521.5ms -> 21973.8ms]
    db 78,1,100,0,65,124,14,4,93,1,65,14  ; n199 t=21.974s dur=100ms, freq=349Hz, sample=65, buffer_id=0E:41 [TRUNCATE prev:ch4 @21502.6ms -> 21973.8ms]
    db 5,0,100,0,55,110,4,0,196,0,55,4  ; n200 t=22.308s dur=100ms, freq=196Hz, sample=55, buffer_id=04:37
    db 14,0,100,0,77,110,16,1,16,3,77,16  ; n201 t=22.313s dur=100ms, freq=784Hz, sample=77, buffer_id=10:4D
    db 0,0,100,0,67,124,5,2,136,1,67,5  ; n202 t=22.327s dur=100ms, freq=392Hz, sample=67, buffer_id=05:43
    db 80,0,100,0,55,124,14,3,196,0,55,14  ; n203 t=22.327s dur=100ms, freq=196Hz, sample=55, buffer_id=0E:37
    db 0,0,149,1,60,110,4,4,6,1,60,4  ; n204 t=22.407s dur=405ms, freq=262Hz, sample=60, buffer_id=04:3C
    db 5,0,149,1,65,110,4,6,74,1,65,4  ; n205 t=22.407s dur=405ms, freq=330Hz, sample=65, buffer_id=04:41
    db 14,0,177,1,89,110,16,5,39,5,89,16  ; n206 t=22.412s dur=433ms, freq=1319Hz, sample=89, buffer_id=10:59
    db 0,0,149,1,67,124,5,7,93,1,67,5  ; n207 t=22.426s dur=405ms, freq=349Hz, sample=67, buffer_id=05:43
    db 0,0,149,1,55,124,14,8,175,0,55,14  ; n208 t=22.426s dur=405ms, freq=175Hz, sample=55, buffer_id=0E:37
    db 0,0,149,1,55,124,14,9,220,0,55,14  ; n209 t=22.426s dur=405ms, freq=220Hz, sample=55, buffer_id=0E:37
    db 163,1,149,1,60,124,14,10,6,1,60,14  ; n210 t=22.426s dur=405ms, freq=262Hz, sample=60, buffer_id=0E:3C
    db 9,0,113,0,29,120,2,0,49,0,29,2  ; n211 t=22.845s dur=113ms, freq=49Hz, sample=29, buffer_id=02:1D
    db 5,0,113,0,43,115,13,1,98,0,43,2  ; n212 t=22.855s dur=113ms, freq=98Hz, sample=43, buffer_id=02:2B
    db 0,0,100,0,55,110,4,2,196,0,55,4  ; n213 t=22.860s dur=100ms, freq=196Hz, sample=55, buffer_id=04:37
    db 5,0,100,0,60,110,4,3,38,1,60,4  ; n214 t=22.860s dur=100ms, freq=294Hz, sample=60, buffer_id=04:3C
    db 14,0,100,0,84,110,16,11,151,4,84,16  ; n215 t=22.864s dur=100ms, freq=1175Hz, sample=84, buffer_id=10:54
    db 0,0,113,0,43,120,1,13,98,0,43,1  ; n216 t=22.878s dur=113ms, freq=98Hz, sample=43, buffer_id=01:2B
    db 0,0,100,0,67,124,5,12,136,1,67,5  ; n217 t=22.878s dur=100ms, freq=392Hz, sample=67, buffer_id=05:43
    db 0,0,100,0,55,124,14,8,196,0,55,14  ; n218 t=22.878s dur=100ms, freq=196Hz, sample=55, buffer_id=0E:37 [TRUNCATE prev:ch8 @22426.0ms -> 22878.3ms]
    db 79,1,100,0,65,124,14,4,93,1,65,14  ; n219 t=22.878s dur=100ms, freq=349Hz, sample=65, buffer_id=0E:41 [TRUNCATE prev:ch4 @22407.2ms -> 22878.3ms]
    db 5,0,100,0,55,110,4,0,196,0,55,4  ; n220 t=23.213s dur=100ms, freq=196Hz, sample=55, buffer_id=04:37
    db 14,0,100,0,77,110,16,1,16,3,77,16  ; n221 t=23.218s dur=100ms, freq=784Hz, sample=77, buffer_id=10:4D
    db 0,0,100,0,67,124,5,2,136,1,67,5  ; n222 t=23.232s dur=100ms, freq=392Hz, sample=67, buffer_id=05:43
    db 80,0,100,0,55,124,14,3,196,0,55,14  ; n223 t=23.232s dur=100ms, freq=196Hz, sample=55, buffer_id=0E:37
    db 0,0,149,1,60,110,4,4,6,1,60,4  ; n224 t=23.312s dur=405ms, freq=262Hz, sample=60, buffer_id=04:3C
    db 5,0,149,1,65,110,4,5,74,1,65,4  ; n225 t=23.312s dur=405ms, freq=330Hz, sample=65, buffer_id=04:41
    db 14,0,177,1,89,110,16,6,39,5,89,16  ; n226 t=23.317s dur=433ms, freq=1319Hz, sample=89, buffer_id=10:59
    db 0,0,149,1,67,124,5,8,93,1,67,5  ; n227 t=23.331s dur=405ms, freq=349Hz, sample=67, buffer_id=05:43
    db 0,0,149,1,55,124,14,7,175,0,55,14  ; n228 t=23.331s dur=405ms, freq=175Hz, sample=55, buffer_id=0E:37
    db 0,0,149,1,55,124,14,10,220,0,55,14  ; n229 t=23.331s dur=405ms, freq=220Hz, sample=55, buffer_id=0E:37
    db 163,1,149,1,60,124,14,9,6,1,60,14  ; n230 t=23.331s dur=405ms, freq=262Hz, sample=60, buffer_id=0E:3C
    db 9,0,113,0,29,120,2,0,49,0,29,2  ; n231 t=23.750s dur=113ms, freq=49Hz, sample=29, buffer_id=02:1D
    db 5,0,113,0,43,115,13,1,98,0,43,2  ; n232 t=23.759s dur=113ms, freq=98Hz, sample=43, buffer_id=02:2B
    db 0,0,100,0,55,110,4,2,196,0,55,4  ; n233 t=23.764s dur=100ms, freq=196Hz, sample=55, buffer_id=04:37
    db 5,0,100,0,60,110,4,3,38,1,60,4  ; n234 t=23.764s dur=100ms, freq=294Hz, sample=60, buffer_id=04:3C
    db 14,0,100,0,84,110,16,12,151,4,84,16  ; n235 t=23.769s dur=100ms, freq=1175Hz, sample=84, buffer_id=10:54
    db 0,0,113,0,43,120,1,11,98,0,43,1  ; n236 t=23.783s dur=113ms, freq=98Hz, sample=43, buffer_id=01:2B
    db 0,0,100,0,67,124,5,13,136,1,67,5  ; n237 t=23.783s dur=100ms, freq=392Hz, sample=67, buffer_id=05:43
    db 0,0,100,0,55,124,14,7,196,0,55,14  ; n238 t=23.783s dur=100ms, freq=196Hz, sample=55, buffer_id=0E:37 [TRUNCATE prev:ch7 @23330.6ms -> 23782.9ms]
    db 78,1,100,0,65,124,14,4,93,1,65,14  ; n239 t=23.783s dur=100ms, freq=349Hz, sample=65, buffer_id=0E:41 [TRUNCATE prev:ch4 @23311.8ms -> 23782.9ms]
    db 5,0,100,0,55,110,4,0,196,0,55,4  ; n240 t=24.117s dur=100ms, freq=196Hz, sample=55, buffer_id=04:37
    db 14,0,100,0,77,110,16,1,16,3,77,16  ; n241 t=24.122s dur=100ms, freq=784Hz, sample=77, buffer_id=10:4D
    db 0,0,100,0,67,124,5,2,136,1,67,5  ; n242 t=24.136s dur=100ms, freq=392Hz, sample=67, buffer_id=05:43
    db 80,0,100,0,55,124,14,3,196,0,55,14  ; n243 t=24.136s dur=100ms, freq=196Hz, sample=55, buffer_id=0E:37
    db 0,0,202,0,60,110,4,4,6,1,60,4  ; n244 t=24.216s dur=202ms, freq=262Hz, sample=60, buffer_id=04:3C
    db 5,0,202,0,65,110,4,6,74,1,65,4  ; n245 t=24.216s dur=202ms, freq=330Hz, sample=65, buffer_id=04:41
    db 14,0,212,0,89,110,16,5,39,5,89,16  ; n246 t=24.221s dur=212ms, freq=1319Hz, sample=89, buffer_id=10:59
    db 0,0,202,0,67,124,5,7,93,1,67,5  ; n247 t=24.235s dur=202ms, freq=349Hz, sample=67, buffer_id=05:43
    db 0,0,202,0,55,124,14,8,175,0,55,14  ; n248 t=24.235s dur=202ms, freq=175Hz, sample=55, buffer_id=0E:37
    db 0,0,202,0,55,124,14,9,220,0,55,14  ; n249 t=24.235s dur=202ms, freq=220Hz, sample=55, buffer_id=0E:37
    db 193,0,202,0,60,124,14,10,6,1,60,14  ; n250 t=24.235s dur=202ms, freq=262Hz, sample=60, buffer_id=0E:3C
    db 9,0,113,0,29,120,2,0,49,0,29,2  ; n251 t=24.428s dur=113ms, freq=49Hz, sample=29, buffer_id=02:1D
    db 5,0,113,0,43,115,13,1,98,0,43,2  ; n252 t=24.438s dur=113ms, freq=98Hz, sample=43, buffer_id=02:2B
    db 0,0,100,0,55,110,4,2,196,0,55,4  ; n253 t=24.442s dur=100ms, freq=196Hz, sample=55, buffer_id=04:37
    db 5,0,100,0,60,110,4,3,38,1,60,4  ; n254 t=24.442s dur=100ms, freq=294Hz, sample=60, buffer_id=04:3C
    db 14,0,100,0,84,110,16,11,151,4,84,16  ; n255 t=24.447s dur=100ms, freq=1175Hz, sample=84, buffer_id=10:54
    db 0,0,113,0,43,120,1,12,98,0,43,1  ; n256 t=24.461s dur=113ms, freq=98Hz, sample=43, buffer_id=01:2B
    db 0,0,100,0,67,124,5,13,136,1,67,5  ; n257 t=24.461s dur=100ms, freq=392Hz, sample=67, buffer_id=05:43 [TRUNCATE prev:ch13 @23782.9ms -> 24461.3ms]
    db 0,0,100,0,55,124,14,8,196,0,55,14  ; n258 t=24.461s dur=100ms, freq=196Hz, sample=55, buffer_id=0E:37 [TRUNCATE prev:ch8 @24235.2ms -> 24461.3ms]
    db 226,0,100,0,65,124,14,4,93,1,65,14  ; n259 t=24.461s dur=100ms, freq=349Hz, sample=65, buffer_id=0E:41 [TRUNCATE prev:ch4 @24216.3ms -> 24461.3ms]
    db 0,0,179,0,62,124,5,5,74,1,62,5  ; n260 t=24.688s dur=179ms, freq=330Hz, sample=62, buffer_id=05:3E
    db 97,1,113,0,50,124,14,6,165,0,50,14  ; n261 t=24.688s dur=113ms, freq=165Hz, sample=50, buffer_id=0E:32
    db 0,0,100,0,67,124,5,0,93,1,67,5  ; n262 t=25.041s dur=100ms, freq=349Hz, sample=67, buffer_id=05:43
    db 66,0,100,0,55,124,14,1,196,0,55,14  ; n263 t=25.041s dur=100ms, freq=196Hz, sample=55, buffer_id=0E:37
    db 9,0,113,0,36,120,2,2,65,0,36,2  ; n264 t=25.107s dur=113ms, freq=65Hz, sample=36, buffer_id=02:24
    db 0,0,17,7,52,120,10,3,165,0,52,2  ; n265 t=25.116s dur=1809ms, freq=165Hz, sample=52, buffer_id=02:34
    db 9,0,34,14,48,115,13,4,131,0,48,2  ; n266 t=25.116s dur=3618ms, freq=131Hz, sample=48, buffer_id=02:30
    db 0,0,34,14,67,120,6,5,136,1,67,2  ; n267 t=25.126s dur=3618ms, freq=392Hz, sample=67, buffer_id=02:43
    db 0,0,34,14,60,120,8,6,6,1,60,2  ; n268 t=25.126s dur=3618ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 0,0,100,0,73,110,16,7,11,2,73,16  ; n269 t=25.126s dur=100ms, freq=523Hz, sample=73, buffer_id=10:49
    db 14,0,100,0,84,110,16,8,23,4,84,16  ; n270 t=25.126s dur=100ms, freq=1047Hz, sample=84, buffer_id=10:54
    db 0,0,113,0,36,120,1,9,65,0,36,1  ; n271 t=25.140s dur=113ms, freq=65Hz, sample=36, buffer_id=01:24
    db 0,0,100,0,67,124,5,10,136,1,67,5  ; n272 t=25.140s dur=100ms, freq=392Hz, sample=67, buffer_id=05:43
    db 0,0,100,0,50,124,14,11,165,0,50,14  ; n273 t=25.140s dur=100ms, freq=165Hz, sample=50, buffer_id=0E:32
    db 255,0,100,0,55,124,14,12,196,0,55,14  ; n274 t=25.140s dur=100ms, freq=196Hz, sample=55, buffer_id=0E:37
    db 154,1,249,3,72,124,5,0,11,2,72,5  ; n275 t=25.394s dur=1017ms, freq=523Hz, sample=72, buffer_id=05:48
    db 0,0,100,0,73,110,16,1,11,2,73,16  ; n276 t=25.804s dur=100ms, freq=523Hz, sample=73, buffer_id=10:49
    db 14,0,100,0,84,110,16,2,23,4,84,16  ; n277 t=25.804s dur=100ms, freq=1047Hz, sample=84, buffer_id=10:54
    db 0,0,100,0,50,124,14,7,165,0,50,14  ; n278 t=25.818s dur=100ms, freq=165Hz, sample=50, buffer_id=0E:32
    db 99,0,100,0,55,124,14,8,196,0,55,14  ; n279 t=25.818s dur=100ms, freq=196Hz, sample=55, buffer_id=0E:37
    db 0,0,100,0,73,110,16,9,11,2,73,16  ; n280 t=25.917s dur=100ms, freq=523Hz, sample=73, buffer_id=10:49
    db 14,0,100,0,84,110,16,10,23,4,84,16  ; n281 t=25.917s dur=100ms, freq=1047Hz, sample=84, buffer_id=10:54
    db 0,0,100,0,50,124,14,12,165,0,50,14  ; n282 t=25.931s dur=100ms, freq=165Hz, sample=50, buffer_id=0E:32
    db 99,0,100,0,55,124,14,11,196,0,55,14  ; n283 t=25.931s dur=100ms, freq=196Hz, sample=55, buffer_id=0E:37
    db 0,0,100,0,73,110,16,13,11,2,73,16  ; n284 t=26.030s dur=100ms, freq=523Hz, sample=73, buffer_id=10:49
    db 14,0,100,0,84,110,16,2,23,4,84,16  ; n285 t=26.030s dur=100ms, freq=1047Hz, sample=84, buffer_id=10:54 [TRUNCATE prev:ch2 @25804.0ms -> 26030.2ms]
    db 0,0,100,0,50,124,14,7,165,0,50,14  ; n286 t=26.044s dur=100ms, freq=165Hz, sample=50, buffer_id=0E:32 [TRUNCATE prev:ch7 @25818.2ms -> 26044.3ms]
    db 193,0,100,0,55,124,14,8,196,0,55,14  ; n287 t=26.044s dur=100ms, freq=196Hz, sample=55, buffer_id=0E:37 [TRUNCATE prev:ch8 @25818.2ms -> 26044.3ms]
    db 33,0,113,0,36,120,2,1,65,0,36,2  ; n288 t=26.238s dur=113ms, freq=65Hz, sample=36, buffer_id=02:24
    db 226,0,113,0,36,120,1,9,65,0,36,1  ; n289 t=26.270s dur=113ms, freq=65Hz, sample=36, buffer_id=01:24
    db 97,1,113,0,62,124,5,2,38,1,62,5  ; n290 t=26.497s dur=113ms, freq=294Hz, sample=62, buffer_id=05:3E
    db 66,0,100,0,62,124,5,0,74,1,62,5  ; n291 t=26.850s dur=100ms, freq=330Hz, sample=62, buffer_id=05:3E
    db 9,0,113,0,36,120,2,2,65,0,36,2  ; n292 t=26.916s dur=113ms, freq=65Hz, sample=36, buffer_id=02:24
    db 9,0,154,6,53,120,10,1,175,0,53,2  ; n293 t=26.925s dur=1690ms, freq=175Hz, sample=53, buffer_id=02:35
    db 0,0,100,0,73,110,16,7,11,2,73,16  ; n294 t=26.935s dur=100ms, freq=523Hz, sample=73, buffer_id=10:49
    db 14,0,100,0,84,110,16,8,23,4,84,16  ; n295 t=26.935s dur=100ms, freq=1047Hz, sample=84, buffer_id=10:54
    db 0,0,113,0,36,120,1,10,65,0,36,1  ; n296 t=26.949s dur=113ms, freq=65Hz, sample=36, buffer_id=01:24
    db 0,0,219,4,67,124,5,9,93,1,67,5  ; n297 t=26.949s dur=1243ms, freq=349Hz, sample=67, buffer_id=05:43
    db 0,0,100,0,55,124,14,12,175,0,55,14  ; n298 t=26.949s dur=100ms, freq=175Hz, sample=55, buffer_id=0E:37
    db 152,2,100,0,55,124,14,13,196,0,55,14  ; n299 t=26.949s dur=100ms, freq=196Hz, sample=55, buffer_id=0E:37
    db 0,0,100,0,73,110,16,0,11,2,73,16  ; n300 t=27.613s dur=100ms, freq=523Hz, sample=73, buffer_id=10:49
    db 14,0,100,0,84,110,16,2,23,4,84,16  ; n301 t=27.613s dur=100ms, freq=1047Hz, sample=84, buffer_id=10:54
    db 0,0,100,0,55,124,14,3,175,0,55,14  ; n302 t=27.627s dur=100ms, freq=175Hz, sample=55, buffer_id=0E:37
    db 99,0,100,0,55,124,14,7,196,0,55,14  ; n303 t=27.627s dur=100ms, freq=196Hz, sample=55, buffer_id=0E:37
    db 0,0,100,0,73,110,16,8,11,2,73,16  ; n304 t=27.726s dur=100ms, freq=523Hz, sample=73, buffer_id=10:49
    db 14,0,100,0,84,110,16,10,23,4,84,16  ; n305 t=27.726s dur=100ms, freq=1047Hz, sample=84, buffer_id=10:54
    db 0,0,100,0,55,124,14,11,175,0,55,14  ; n306 t=27.740s dur=100ms, freq=175Hz, sample=55, buffer_id=0E:37 [TRUNCATE prev:ch11 @25931.2ms -> 27740.4ms]
    db 99,0,100,0,55,124,14,12,196,0,55,14  ; n307 t=27.740s dur=100ms, freq=196Hz, sample=55, buffer_id=0E:37 [TRUNCATE prev:ch12 @26948.9ms -> 27740.4ms]
    db 0,0,100,0,73,110,16,13,11,2,73,16  ; n308 t=27.839s dur=100ms, freq=523Hz, sample=73, buffer_id=10:49
    db 14,0,100,0,84,110,16,2,23,4,84,16  ; n309 t=27.839s dur=100ms, freq=1047Hz, sample=84, buffer_id=10:54 [TRUNCATE prev:ch2 @27613.2ms -> 27839.3ms]
    db 0,0,100,0,55,124,14,3,175,0,55,14  ; n310 t=27.853s dur=100ms, freq=175Hz, sample=55, buffer_id=0E:37 [TRUNCATE prev:ch3 @27627.3ms -> 27853.4ms]
    db 99,0,100,0,55,124,14,7,196,0,55,14  ; n311 t=27.853s dur=100ms, freq=196Hz, sample=55, buffer_id=0E:37 [TRUNCATE prev:ch7 @27627.3ms -> 27853.4ms]
    db 0,0,100,0,73,110,16,0,11,2,73,16  ; n312 t=27.952s dur=100ms, freq=523Hz, sample=73, buffer_id=10:49 [TRUNCATE prev:ch0 @27613.2ms -> 27952.4ms]
    db 14,0,100,0,84,110,16,10,23,4,84,16  ; n313 t=27.952s dur=100ms, freq=1047Hz, sample=84, buffer_id=10:54 [TRUNCATE prev:ch10 @27726.2ms -> 27952.4ms]
    db 0,0,100,0,55,124,14,11,175,0,55,14  ; n314 t=27.966s dur=100ms, freq=175Hz, sample=55, buffer_id=0E:37 [TRUNCATE prev:ch11 @27740.4ms -> 27966.5ms]
    db 80,0,100,0,55,124,14,12,196,0,55,14  ; n315 t=27.966s dur=100ms, freq=196Hz, sample=55, buffer_id=0E:37 [TRUNCATE prev:ch12 @27740.4ms -> 27966.5ms]
    db 33,0,113,0,36,120,2,8,65,0,36,2  ; n316 t=28.047s dur=113ms, freq=65Hz, sample=36, buffer_id=02:24
    db 226,0,113,0,36,120,1,4,65,0,36,1  ; n317 t=28.080s dur=113ms, freq=65Hz, sample=36, buffer_id=01:24 [TRUNCATE prev:ch4 @25116.2ms -> 28079.6ms]
    db 97,1,179,0,67,124,5,0,136,1,67,5  ; n318 t=28.306s dur=179ms, freq=392Hz, sample=67, buffer_id=05:43
    db 66,0,100,0,67,124,5,2,184,1,67,5  ; n319 t=28.659s dur=100ms, freq=440Hz, sample=67, buffer_id=05:43
    db 9,0,113,0,36,120,2,0,65,0,36,2  ; n320 t=28.725s dur=113ms, freq=65Hz, sample=36, buffer_id=02:24
    db 0,0,154,6,53,120,10,3,175,0,53,2  ; n321 t=28.735s dur=1690ms, freq=175Hz, sample=53, buffer_id=02:35
    db 9,0,34,14,48,115,13,4,131,0,48,2  ; n322 t=28.735s dur=3618ms, freq=131Hz, sample=48, buffer_id=02:30
    db 0,0,34,14,67,120,6,7,136,1,67,2  ; n323 t=28.744s dur=3618ms, freq=392Hz, sample=67, buffer_id=02:43
    db 0,0,34,14,60,120,8,8,6,1,60,2  ; n324 t=28.744s dur=3618ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 0,0,100,0,73,110,16,9,11,2,73,16  ; n325 t=28.744s dur=100ms, freq=523Hz, sample=73, buffer_id=10:49
    db 14,0,100,0,84,110,16,11,23,4,84,16  ; n326 t=28.744s dur=100ms, freq=1047Hz, sample=84, buffer_id=10:54
    db 0,0,113,0,36,120,1,10,65,0,36,1  ; n327 t=28.758s dur=113ms, freq=65Hz, sample=36, buffer_id=01:24
    db 0,0,100,0,72,124,5,12,238,1,72,5  ; n328 t=28.758s dur=100ms, freq=494Hz, sample=72, buffer_id=05:48
    db 0,0,100,0,55,124,14,13,175,0,55,14  ; n329 t=28.758s dur=100ms, freq=175Hz, sample=55, buffer_id=0E:37
    db 254,0,100,0,55,124,14,5,196,0,55,14  ; n330 t=28.758s dur=100ms, freq=196Hz, sample=55, buffer_id=0E:37 [TRUNCATE prev:ch5 @25125.6ms -> 28758.0ms]
    db 154,1,249,3,77,124,5,1,186,2,77,5  ; n331 t=29.012s dur=1017ms, freq=698Hz, sample=77, buffer_id=05:4D
    db 0,0,100,0,73,110,16,0,11,2,73,16  ; n332 t=29.422s dur=100ms, freq=523Hz, sample=73, buffer_id=10:49
    db 14,0,100,0,84,110,16,2,23,4,84,16  ; n333 t=29.422s dur=100ms, freq=1047Hz, sample=84, buffer_id=10:54
    db 0,0,100,0,55,124,14,6,175,0,55,14  ; n334 t=29.436s dur=100ms, freq=175Hz, sample=55, buffer_id=0E:37
    db 99,0,100,0,65,124,14,5,136,1,65,14  ; n335 t=29.436s dur=100ms, freq=392Hz, sample=65, buffer_id=0E:41
    db 0,0,100,0,73,110,16,10,11,2,73,16  ; n336 t=29.535s dur=100ms, freq=523Hz, sample=73, buffer_id=10:49
    db 14,0,100,0,84,110,16,9,23,4,84,16  ; n337 t=29.535s dur=100ms, freq=1047Hz, sample=84, buffer_id=10:54
    db 0,0,100,0,55,124,14,11,175,0,55,14  ; n338 t=29.549s dur=100ms, freq=175Hz, sample=55, buffer_id=0E:37
    db 99,0,100,0,55,124,14,12,196,0,55,14  ; n339 t=29.549s dur=100ms, freq=196Hz, sample=55, buffer_id=0E:37
    db 0,0,100,0,73,110,16,13,11,2,73,16  ; n340 t=29.648s dur=100ms, freq=523Hz, sample=73, buffer_id=10:49
    db 14,0,100,0,84,110,16,2,23,4,84,16  ; n341 t=29.648s dur=100ms, freq=1047Hz, sample=84, buffer_id=10:54 [TRUNCATE prev:ch2 @29422.3ms -> 29648.5ms]
    db 0,0,100,0,55,124,14,6,175,0,55,14  ; n342 t=29.663s dur=100ms, freq=175Hz, sample=55, buffer_id=0E:37 [TRUNCATE prev:ch6 @29436.4ms -> 29662.6ms]
    db 193,0,100,0,55,124,14,11,196,0,55,14  ; n343 t=29.663s dur=100ms, freq=196Hz, sample=55, buffer_id=0E:37 [TRUNCATE prev:ch11 @29549.5ms -> 29662.6ms]
    db 33,0,113,0,36,120,2,0,65,0,36,2  ; n344 t=29.856s dur=113ms, freq=65Hz, sample=36, buffer_id=02:24
    db 226,0,113,0,36,120,1,5,65,0,36,1  ; n345 t=29.889s dur=113ms, freq=65Hz, sample=36, buffer_id=01:24
    db 97,1,113,0,67,124,5,2,184,1,67,5  ; n346 t=30.115s dur=113ms, freq=440Hz, sample=67, buffer_id=05:43
    db 66,0,100,0,72,124,5,0,238,1,72,5  ; n347 t=30.468s dur=100ms, freq=494Hz, sample=72, buffer_id=05:48
    db 9,0,113,0,36,120,2,1,65,0,36,2  ; n348 t=30.534s dur=113ms, freq=65Hz, sample=36, buffer_id=02:24
    db 9,0,17,7,52,120,10,2,165,0,52,2  ; n349 t=30.544s dur=1809ms, freq=165Hz, sample=52, buffer_id=02:34
    db 0,0,100,0,84,110,16,5,23,4,84,16  ; n350 t=30.553s dur=100ms, freq=1047Hz, sample=84, buffer_id=10:54
    db 14,0,100,0,73,110,16,6,11,2,73,16  ; n351 t=30.553s dur=100ms, freq=523Hz, sample=73, buffer_id=10:49
    db 0,0,113,0,36,120,1,9,65,0,36,1  ; n352 t=30.567s dur=113ms, freq=65Hz, sample=36, buffer_id=01:24
    db 0,0,80,1,72,124,5,10,11,2,72,5  ; n353 t=30.567s dur=336ms, freq=523Hz, sample=72, buffer_id=05:48
    db 0,0,100,0,50,124,14,11,165,0,50,14  ; n354 t=30.567s dur=100ms, freq=165Hz, sample=50, buffer_id=0E:32
    db 196,1,100,0,55,124,14,13,196,0,55,14  ; n355 t=30.567s dur=100ms, freq=196Hz, sample=55, buffer_id=0E:37
    db 212,0,80,1,72,124,5,1,75,2,72,5  ; n356 t=31.019s dur=336ms, freq=587Hz, sample=72, buffer_id=05:48
    db 0,0,100,0,73,110,16,0,11,2,73,16  ; n357 t=31.231s dur=100ms, freq=523Hz, sample=73, buffer_id=10:49
    db 14,0,100,0,84,110,16,3,23,4,84,16  ; n358 t=31.231s dur=100ms, freq=1047Hz, sample=84, buffer_id=10:54
    db 0,0,100,0,50,124,14,5,165,0,50,14  ; n359 t=31.246s dur=100ms, freq=165Hz, sample=50, buffer_id=0E:32
    db 99,0,100,0,55,124,14,6,196,0,55,14  ; n360 t=31.246s dur=100ms, freq=196Hz, sample=55, buffer_id=0E:37
    db 0,0,100,0,73,110,16,9,11,2,73,16  ; n361 t=31.345s dur=100ms, freq=523Hz, sample=73, buffer_id=10:49
    db 14,0,100,0,84,110,16,10,23,4,84,16  ; n362 t=31.345s dur=100ms, freq=1047Hz, sample=84, buffer_id=10:54
    db 0,0,100,0,50,124,14,12,165,0,50,14  ; n363 t=31.359s dur=100ms, freq=165Hz, sample=50, buffer_id=0E:32
    db 99,0,100,0,55,124,14,11,196,0,55,14  ; n364 t=31.359s dur=100ms, freq=196Hz, sample=55, buffer_id=0E:37
    db 0,0,100,0,73,110,16,13,11,2,73,16  ; n365 t=31.458s dur=100ms, freq=523Hz, sample=73, buffer_id=10:49
    db 14,0,100,0,84,110,16,3,23,4,84,16  ; n366 t=31.458s dur=100ms, freq=1047Hz, sample=84, buffer_id=10:54 [TRUNCATE prev:ch3 @31231.4ms -> 31457.6ms]
    db 0,0,83,1,77,124,5,4,147,2,77,5  ; n367 t=31.472s dur=339ms, freq=659Hz, sample=77, buffer_id=05:4D [TRUNCATE prev:ch4 @28734.5ms -> 31471.7ms]
    db 0,0,100,0,50,124,14,5,165,0,50,14  ; n368 t=31.472s dur=100ms, freq=165Hz, sample=50, buffer_id=0E:32 [TRUNCATE prev:ch5 @31245.6ms -> 31471.7ms]
    db 99,0,100,0,55,124,14,6,196,0,55,14  ; n369 t=31.472s dur=100ms, freq=196Hz, sample=55, buffer_id=0E:37 [TRUNCATE prev:ch6 @31245.6ms -> 31471.7ms]
    db 0,0,100,0,73,110,16,1,11,2,73,16  ; n370 t=31.571s dur=100ms, freq=523Hz, sample=73, buffer_id=10:49
    db 14,0,100,0,84,110,16,0,23,4,84,16  ; n371 t=31.571s dur=100ms, freq=1047Hz, sample=84, buffer_id=10:54
    db 0,0,100,0,50,124,14,12,165,0,50,14  ; n372 t=31.585s dur=100ms, freq=165Hz, sample=50, buffer_id=0E:32 [TRUNCATE prev:ch12 @31358.6ms -> 31584.8ms]
    db 80,0,100,0,55,124,14,11,196,0,55,14  ; n373 t=31.585s dur=100ms, freq=196Hz, sample=55, buffer_id=0E:37 [TRUNCATE prev:ch11 @31358.6ms -> 31584.8ms]
    db 33,0,113,0,29,120,2,9,49,0,29,2  ; n374 t=31.665s dur=113ms, freq=49Hz, sample=29, buffer_id=02:1D
    db 226,0,113,0,31,120,1,10,49,0,31,1  ; n375 t=31.698s dur=113ms, freq=49Hz, sample=31, buffer_id=01:1F
    db 97,1,179,0,62,124,5,0,74,1,62,5  ; n376 t=31.924s dur=179ms, freq=330Hz, sample=62, buffer_id=05:3E
    db 66,0,100,0,67,124,5,1,93,1,67,5  ; n377 t=32.277s dur=100ms, freq=349Hz, sample=67, buffer_id=05:43
    db 9,0,113,0,36,120,2,0,65,0,36,2  ; n378 t=32.343s dur=113ms, freq=65Hz, sample=36, buffer_id=02:24
    db 0,0,17,7,52,120,10,3,165,0,52,2  ; n379 t=32.353s dur=1809ms, freq=165Hz, sample=52, buffer_id=02:34
    db 10,0,17,7,48,115,13,4,131,0,48,2  ; n380 t=32.353s dur=1809ms, freq=131Hz, sample=48, buffer_id=02:30
    db 0,0,17,7,67,120,6,5,136,1,67,2  ; n381 t=32.362s dur=1809ms, freq=392Hz, sample=67, buffer_id=02:43
    db 0,0,17,7,60,120,8,6,6,1,60,2  ; n382 t=32.362s dur=1809ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 0,0,100,0,73,110,16,9,11,2,73,16  ; n383 t=32.362s dur=100ms, freq=523Hz, sample=73, buffer_id=10:49
    db 14,0,100,0,84,110,16,10,23,4,84,16  ; n384 t=32.362s dur=100ms, freq=1047Hz, sample=84, buffer_id=10:54
    db 0,0,113,0,36,120,1,11,65,0,36,1  ; n385 t=32.376s dur=113ms, freq=65Hz, sample=36, buffer_id=01:24
    db 0,0,100,0,67,124,5,12,136,1,67,5  ; n386 t=32.376s dur=100ms, freq=392Hz, sample=67, buffer_id=05:43
    db 0,0,100,0,50,124,14,13,165,0,50,14  ; n387 t=32.376s dur=100ms, freq=165Hz, sample=50, buffer_id=0E:32
    db 254,0,100,0,55,124,14,7,196,0,55,14  ; n388 t=32.376s dur=100ms, freq=196Hz, sample=55, buffer_id=0E:37 [TRUNCATE prev:ch7 @28743.9ms -> 32376.3ms]
    db 154,1,249,3,72,124,5,1,11,2,72,5  ; n389 t=32.631s dur=1017ms, freq=523Hz, sample=72, buffer_id=05:48
    db 0,0,100,0,73,110,16,0,11,2,73,16  ; n390 t=33.041s dur=100ms, freq=523Hz, sample=73, buffer_id=10:49
    db 14,0,100,0,84,110,16,2,23,4,84,16  ; n391 t=33.041s dur=100ms, freq=1047Hz, sample=84, buffer_id=10:54
    db 0,0,100,0,50,124,14,7,165,0,50,14  ; n392 t=33.055s dur=100ms, freq=165Hz, sample=50, buffer_id=0E:32
    db 99,0,100,0,55,124,14,8,196,0,55,14  ; n393 t=33.055s dur=100ms, freq=196Hz, sample=55, buffer_id=0E:37
    db 0,0,100,0,73,110,16,10,11,2,73,16  ; n394 t=33.154s dur=100ms, freq=523Hz, sample=73, buffer_id=10:49
    db 14,0,100,0,84,110,16,9,23,4,84,16  ; n395 t=33.154s dur=100ms, freq=1047Hz, sample=84, buffer_id=10:54
    db 0,0,100,0,50,124,14,11,165,0,50,14  ; n396 t=33.168s dur=100ms, freq=165Hz, sample=50, buffer_id=0E:32
    db 99,0,100,0,55,124,14,12,196,0,55,14  ; n397 t=33.168s dur=100ms, freq=196Hz, sample=55, buffer_id=0E:37
    db 0,0,100,0,73,110,16,13,11,2,73,16  ; n398 t=33.267s dur=100ms, freq=523Hz, sample=73, buffer_id=10:49
    db 14,0,100,0,84,110,16,2,23,4,84,16  ; n399 t=33.267s dur=100ms, freq=1047Hz, sample=84, buffer_id=10:54 [TRUNCATE prev:ch2 @33040.6ms -> 33266.7ms]
    db 0,0,100,0,50,124,14,7,165,0,50,14  ; n400 t=33.281s dur=100ms, freq=165Hz, sample=50, buffer_id=0E:32 [TRUNCATE prev:ch7 @33054.7ms -> 33280.9ms]
    db 193,0,100,0,55,124,14,8,196,0,55,14  ; n401 t=33.281s dur=100ms, freq=196Hz, sample=55, buffer_id=0E:37 [TRUNCATE prev:ch8 @33054.7ms -> 33280.9ms]
    db 33,0,113,0,36,120,2,0,65,0,36,2  ; n402 t=33.474s dur=113ms, freq=65Hz, sample=36, buffer_id=02:24
    db 226,0,113,0,36,120,1,9,65,0,36,1  ; n403 t=33.507s dur=113ms, freq=65Hz, sample=36, buffer_id=01:24
    db 97,1,113,0,72,124,5,2,75,2,72,5  ; n404 t=33.733s dur=113ms, freq=587Hz, sample=72, buffer_id=05:48
    db 66,0,100,0,77,124,5,0,147,2,77,5  ; n405 t=34.087s dur=100ms, freq=659Hz, sample=77, buffer_id=05:4D
    db 10,0,113,0,36,120,2,1,69,0,36,2  ; n406 t=34.152s dur=113ms, freq=69Hz, sample=36, buffer_id=02:24
    db 0,0,76,5,53,120,10,2,175,0,53,2  ; n407 t=34.162s dur=1356ms, freq=175Hz, sample=53, buffer_id=02:35
    db 9,0,76,5,48,115,13,7,139,0,48,2  ; n408 t=34.162s dur=1356ms, freq=139Hz, sample=48, buffer_id=02:30
    db 0,0,219,4,67,120,6,8,159,1,67,2  ; n409 t=34.171s dur=1243ms, freq=415Hz, sample=67, buffer_id=02:43
    db 0,0,0,1,61,120,8,9,21,1,61,2  ; n410 t=34.171s dur=256ms, freq=277Hz, sample=61, buffer_id=02:3D
    db 0,0,100,0,73,110,16,11,42,2,73,16  ; n411 t=34.171s dur=100ms, freq=554Hz, sample=73, buffer_id=10:49
    db 5,0,100,0,84,110,16,10,85,4,84,16  ; n412 t=34.171s dur=100ms, freq=1109Hz, sample=84, buffer_id=10:54
    db 0,0,100,0,77,100,18,12,186,2,77,18  ; n413 t=34.176s dur=100ms, freq=698Hz, sample=77, buffer_id=12:4D
    db 9,0,100,0,81,100,18,13,63,3,81,18  ; n414 t=34.176s dur=100ms, freq=831Hz, sample=81, buffer_id=12:51
    db 0,0,113,0,36,120,1,3,69,0,36,1  ; n415 t=34.185s dur=113ms, freq=69Hz, sample=36, buffer_id=01:24 [TRUNCATE prev:ch3 @32352.7ms -> 34185.4ms]
    db 0,0,219,4,77,124,5,4,186,2,77,5  ; n416 t=34.185s dur=1243ms, freq=698Hz, sample=77, buffer_id=05:4D [TRUNCATE prev:ch4 @32352.7ms -> 34185.4ms]
    db 0,0,100,0,55,124,14,5,175,0,55,14  ; n417 t=34.185s dur=100ms, freq=175Hz, sample=55, buffer_id=0E:37 [TRUNCATE prev:ch5 @32362.2ms -> 34185.4ms]
    db 152,2,100,0,55,124,14,6,208,0,55,14  ; n418 t=34.185s dur=100ms, freq=208Hz, sample=55, buffer_id=0E:37 [TRUNCATE prev:ch6 @32362.2ms -> 34185.4ms]
    db 0,0,100,0,73,110,16,0,42,2,73,16  ; n419 t=34.850s dur=100ms, freq=554Hz, sample=73, buffer_id=10:49
    db 5,0,100,0,84,110,16,1,85,4,84,16  ; n420 t=34.850s dur=100ms, freq=1109Hz, sample=84, buffer_id=10:54
    db 0,0,100,0,77,100,18,3,186,2,77,18  ; n421 t=34.854s dur=100ms, freq=698Hz, sample=77, buffer_id=12:4D
    db 9,0,100,0,81,100,18,5,63,3,81,18  ; n422 t=34.854s dur=100ms, freq=831Hz, sample=81, buffer_id=12:51
    db 0,0,100,0,55,124,14,9,175,0,55,14  ; n423 t=34.864s dur=100ms, freq=175Hz, sample=55, buffer_id=0E:37
    db 99,0,100,0,55,124,14,10,208,0,55,14  ; n424 t=34.864s dur=100ms, freq=208Hz, sample=55, buffer_id=0E:37
    db 0,0,100,0,73,110,16,6,42,2,73,16  ; n425 t=34.963s dur=100ms, freq=554Hz, sample=73, buffer_id=10:49
    db 5,0,100,0,84,110,16,11,85,4,84,16  ; n426 t=34.963s dur=100ms, freq=1109Hz, sample=84, buffer_id=10:54
    db 0,0,100,0,77,100,18,13,186,2,77,18  ; n427 t=34.968s dur=100ms, freq=698Hz, sample=77, buffer_id=12:4D
    db 9,0,100,0,81,100,18,12,63,3,81,18  ; n428 t=34.968s dur=100ms, freq=831Hz, sample=81, buffer_id=12:51
    db 0,0,100,0,55,124,14,9,175,0,55,14  ; n429 t=34.977s dur=100ms, freq=175Hz, sample=55, buffer_id=0E:37 [TRUNCATE prev:ch9 @34863.8ms -> 34976.9ms]
    db 99,0,100,0,55,124,14,10,208,0,55,14  ; n430 t=34.977s dur=100ms, freq=208Hz, sample=55, buffer_id=0E:37 [TRUNCATE prev:ch10 @34863.8ms -> 34976.9ms]
    db 0,0,100,0,73,110,16,0,42,2,73,16  ; n431 t=35.076s dur=100ms, freq=554Hz, sample=73, buffer_id=10:49 [TRUNCATE prev:ch0 @34849.7ms -> 35075.9ms]
    db 5,0,100,0,84,110,16,1,85,4,84,16  ; n432 t=35.076s dur=100ms, freq=1109Hz, sample=84, buffer_id=10:54 [TRUNCATE prev:ch1 @34849.7ms -> 35075.9ms]
    db 0,0,100,0,77,100,18,3,186,2,77,18  ; n433 t=35.081s dur=100ms, freq=698Hz, sample=77, buffer_id=12:4D [TRUNCATE prev:ch3 @34854.4ms -> 35080.6ms]
    db 9,0,100,0,81,100,18,5,63,3,81,18  ; n434 t=35.081s dur=100ms, freq=831Hz, sample=81, buffer_id=12:51 [TRUNCATE prev:ch5 @34854.4ms -> 35080.6ms]
    db 0,0,100,0,55,124,14,9,175,0,55,14  ; n435 t=35.090s dur=100ms, freq=175Hz, sample=55, buffer_id=0E:37 [TRUNCATE prev:ch9 @34976.9ms -> 35090.0ms]
    db 99,0,100,0,55,124,14,10,208,0,55,14  ; n436 t=35.090s dur=100ms, freq=208Hz, sample=55, buffer_id=0E:37 [TRUNCATE prev:ch10 @34976.9ms -> 35090.0ms]
    db 0,0,100,0,73,110,16,6,42,2,73,16  ; n437 t=35.189s dur=100ms, freq=554Hz, sample=73, buffer_id=10:49 [TRUNCATE prev:ch6 @34962.8ms -> 35188.9ms]
    db 5,0,100,0,84,110,16,11,85,4,84,16  ; n438 t=35.189s dur=100ms, freq=1109Hz, sample=84, buffer_id=10:54 [TRUNCATE prev:ch11 @34962.8ms -> 35188.9ms]
    db 0,0,100,0,77,100,18,13,186,2,77,18  ; n439 t=35.194s dur=100ms, freq=698Hz, sample=77, buffer_id=12:4D [TRUNCATE prev:ch13 @34967.5ms -> 35193.6ms]
    db 9,0,100,0,81,100,18,12,63,3,81,18  ; n440 t=35.194s dur=100ms, freq=831Hz, sample=81, buffer_id=12:51 [TRUNCATE prev:ch12 @34967.5ms -> 35193.6ms]
    db 0,0,100,0,55,124,14,9,175,0,55,14  ; n441 t=35.203s dur=100ms, freq=175Hz, sample=55, buffer_id=0E:37 [TRUNCATE prev:ch9 @35090.0ms -> 35203.1ms]
    db 80,0,100,0,55,124,14,10,208,0,55,14  ; n442 t=35.203s dur=100ms, freq=208Hz, sample=55, buffer_id=0E:37 [TRUNCATE prev:ch10 @35090.0ms -> 35203.1ms]
    db 33,0,113,0,36,120,2,2,69,0,36,2  ; n443 t=35.283s dur=113ms, freq=69Hz, sample=36, buffer_id=02:24 [TRUNCATE prev:ch2 @34161.9ms -> 35283.2ms]
    db 207,0,113,0,36,120,1,7,69,0,36,1  ; n444 t=35.316s dur=113ms, freq=69Hz, sample=36, buffer_id=01:24 [TRUNCATE prev:ch7 @34161.9ms -> 35316.1ms]
    db 5,0,113,0,65,110,4,0,136,1,65,4  ; n445 t=35.523s dur=113ms, freq=392Hz, sample=65, buffer_id=04:41
    db 0,0,113,0,79,120,7,1,16,3,79,2  ; n446 t=35.528s dur=113ms, freq=784Hz, sample=79, buffer_id=02:4F
    db 5,0,113,0,77,110,16,3,16,3,77,16  ; n447 t=35.528s dur=113ms, freq=784Hz, sample=77, buffer_id=10:4D
    db 0,0,113,0,79,90,17,5,16,3,79,17  ; n448 t=35.533s dur=113ms, freq=784Hz, sample=79, buffer_id=11:4F
    db 9,0,100,0,65,100,18,6,136,1,65,18  ; n449 t=35.533s dur=100ms, freq=392Hz, sample=65, buffer_id=12:41
    db 79,1,113,0,55,124,14,11,196,0,55,14  ; n450 t=35.542s dur=113ms, freq=196Hz, sample=55, buffer_id=0E:37
    db 5,0,100,0,65,110,4,1,136,1,65,4  ; n451 t=35.877s dur=100ms, freq=392Hz, sample=65, buffer_id=04:41
    db 0,0,100,0,79,120,7,0,16,3,79,2  ; n452 t=35.882s dur=100ms, freq=784Hz, sample=79, buffer_id=02:4F
    db 5,0,100,0,77,110,16,2,16,3,77,16  ; n453 t=35.882s dur=100ms, freq=784Hz, sample=77, buffer_id=10:4D
    db 0,0,100,0,79,90,17,3,16,3,79,17  ; n454 t=35.886s dur=100ms, freq=784Hz, sample=79, buffer_id=11:4F
    db 9,0,100,0,65,100,18,4,136,1,65,18  ; n455 t=35.886s dur=100ms, freq=392Hz, sample=65, buffer_id=12:41
    db 80,0,100,0,55,124,14,5,196,0,55,14  ; n456 t=35.896s dur=100ms, freq=196Hz, sample=55, buffer_id=0E:37
    db 0,0,149,1,60,110,4,6,6,1,60,4  ; n457 t=35.976s dur=405ms, freq=262Hz, sample=60, buffer_id=04:3C
    db 5,0,149,1,65,110,4,7,74,1,65,4  ; n458 t=35.976s dur=405ms, freq=330Hz, sample=65, buffer_id=04:41
    db 0,0,177,1,86,120,7,8,39,5,86,2  ; n459 t=35.980s dur=433ms, freq=1319Hz, sample=86, buffer_id=02:56
    db 0,0,177,1,84,120,9,9,23,4,84,2  ; n460 t=35.980s dur=433ms, freq=1047Hz, sample=84, buffer_id=02:54
    db 5,0,177,1,84,110,16,10,23,4,84,16  ; n461 t=35.980s dur=433ms, freq=1047Hz, sample=84, buffer_id=10:54
    db 0,0,50,1,85,90,17,11,39,5,85,17  ; n462 t=35.985s dur=306ms, freq=1319Hz, sample=85, buffer_id=11:55
    db 9,0,177,1,77,100,18,12,147,2,77,18  ; n463 t=35.985s dur=433ms, freq=659Hz, sample=77, buffer_id=12:4D
    db 0,0,149,1,55,124,14,13,175,0,55,14  ; n464 t=35.995s dur=405ms, freq=175Hz, sample=55, buffer_id=0E:37
    db 0,0,149,1,55,124,14,1,220,0,55,14  ; n465 t=35.995s dur=405ms, freq=220Hz, sample=55, buffer_id=0E:37 [TRUNCATE prev:ch1 @35876.8ms -> 35994.6ms]
    db 163,1,149,1,60,124,14,0,6,1,60,14  ; n466 t=35.995s dur=405ms, freq=262Hz, sample=60, buffer_id=0E:3C [TRUNCATE prev:ch0 @35881.5ms -> 35994.6ms]
    db 9,0,113,0,29,120,2,2,49,0,29,2  ; n467 t=36.414s dur=113ms, freq=49Hz, sample=29, buffer_id=02:1D
    db 5,0,113,0,43,115,13,3,98,0,43,2  ; n468 t=36.423s dur=113ms, freq=98Hz, sample=43, buffer_id=02:2B
    db 0,0,100,0,55,110,4,4,196,0,55,4  ; n469 t=36.428s dur=100ms, freq=196Hz, sample=55, buffer_id=04:37
    db 5,0,100,0,60,110,4,5,38,1,60,4  ; n470 t=36.428s dur=100ms, freq=294Hz, sample=60, buffer_id=04:3C
    db 0,0,100,0,86,120,7,8,151,4,86,2  ; n471 t=36.433s dur=100ms, freq=1175Hz, sample=86, buffer_id=02:56 [TRUNCATE prev:ch8 @35980.4ms -> 36432.7ms]
    db 0,0,100,0,79,120,9,6,16,3,79,2  ; n472 t=36.433s dur=100ms, freq=784Hz, sample=79, buffer_id=02:4F [TRUNCATE prev:ch6 @35975.7ms -> 36432.7ms]
    db 5,0,100,0,77,110,16,7,16,3,77,16  ; n473 t=36.433s dur=100ms, freq=784Hz, sample=77, buffer_id=10:4D [TRUNCATE prev:ch7 @35975.7ms -> 36432.7ms]
    db 0,0,100,0,85,90,17,11,151,4,85,17  ; n474 t=36.437s dur=100ms, freq=1175Hz, sample=85, buffer_id=11:55 [TRUNCATE prev:ch11 @35985.1ms -> 36437.4ms]
    db 9,0,100,0,77,100,18,12,75,2,77,18  ; n475 t=36.437s dur=100ms, freq=587Hz, sample=77, buffer_id=12:4D [TRUNCATE prev:ch12 @35985.1ms -> 36437.4ms]
    db 0,0,113,0,43,120,1,9,98,0,43,1  ; n476 t=36.447s dur=113ms, freq=98Hz, sample=43, buffer_id=01:2B [TRUNCATE prev:ch9 @35980.4ms -> 36446.8ms]
    db 0,0,100,0,55,124,14,1,196,0,55,14  ; n477 t=36.447s dur=100ms, freq=196Hz, sample=55, buffer_id=0E:37 [TRUNCATE prev:ch1 @35994.6ms -> 36446.8ms]
    db 78,1,100,0,65,124,14,10,93,1,65,14  ; n478 t=36.447s dur=100ms, freq=349Hz, sample=65, buffer_id=0E:41 [TRUNCATE prev:ch10 @35980.4ms -> 36446.8ms]
    db 5,0,100,0,55,110,4,0,196,0,55,4  ; n479 t=36.781s dur=100ms, freq=196Hz, sample=55, buffer_id=04:37
    db 0,0,100,0,79,120,7,1,16,3,79,2  ; n480 t=36.786s dur=100ms, freq=784Hz, sample=79, buffer_id=02:4F
    db 0,0,100,0,79,120,9,2,16,3,79,2  ; n481 t=36.786s dur=100ms, freq=784Hz, sample=79, buffer_id=02:4F
    db 5,0,100,0,77,110,16,3,16,3,77,16  ; n482 t=36.786s dur=100ms, freq=784Hz, sample=77, buffer_id=10:4D
    db 0,0,100,0,79,90,17,4,16,3,79,17  ; n483 t=36.791s dur=100ms, freq=784Hz, sample=79, buffer_id=11:4F
    db 9,0,100,0,65,100,18,5,136,1,65,18  ; n484 t=36.791s dur=100ms, freq=392Hz, sample=65, buffer_id=12:41
    db 80,0,100,0,55,124,14,6,196,0,55,14  ; n485 t=36.800s dur=100ms, freq=196Hz, sample=55, buffer_id=0E:37
    db 0,0,149,1,60,110,4,7,6,1,60,4  ; n486 t=36.880s dur=405ms, freq=262Hz, sample=60, buffer_id=04:3C
    db 5,0,149,1,65,110,4,8,74,1,65,4  ; n487 t=36.880s dur=405ms, freq=330Hz, sample=65, buffer_id=04:41
    db 0,0,177,1,86,120,7,9,39,5,86,2  ; n488 t=36.885s dur=433ms, freq=1319Hz, sample=86, buffer_id=02:56
    db 0,0,177,1,84,120,9,10,23,4,84,2  ; n489 t=36.885s dur=433ms, freq=1047Hz, sample=84, buffer_id=02:54
    db 5,0,177,1,84,110,16,11,23,4,84,16  ; n490 t=36.885s dur=433ms, freq=1047Hz, sample=84, buffer_id=10:54
    db 0,0,50,1,85,90,17,12,39,5,85,17  ; n491 t=36.890s dur=306ms, freq=1319Hz, sample=85, buffer_id=11:55
    db 9,0,177,1,77,100,18,13,147,2,77,18  ; n492 t=36.890s dur=433ms, freq=659Hz, sample=77, buffer_id=12:4D
    db 0,0,149,1,55,124,14,0,175,0,55,14  ; n493 t=36.899s dur=405ms, freq=175Hz, sample=55, buffer_id=0E:37 [TRUNCATE prev:ch0 @36781.3ms -> 36899.1ms]
    db 0,0,149,1,55,124,14,1,220,0,55,14  ; n494 t=36.899s dur=405ms, freq=220Hz, sample=55, buffer_id=0E:37 [TRUNCATE prev:ch1 @36786.1ms -> 36899.1ms]
    db 163,1,149,1,60,124,14,2,6,1,60,14  ; n495 t=36.899s dur=405ms, freq=262Hz, sample=60, buffer_id=0E:3C [TRUNCATE prev:ch2 @36786.1ms -> 36899.1ms]
    db 10,0,113,0,29,120,2,3,49,0,29,2  ; n496 t=37.318s dur=113ms, freq=49Hz, sample=29, buffer_id=02:1D
    db 5,0,113,0,43,115,13,4,98,0,43,2  ; n497 t=37.328s dur=113ms, freq=98Hz, sample=43, buffer_id=02:2B
    db 0,0,100,0,55,110,4,5,196,0,55,4  ; n498 t=37.333s dur=100ms, freq=196Hz, sample=55, buffer_id=04:37
    db 5,0,100,0,60,110,4,6,38,1,60,4  ; n499 t=37.333s dur=100ms, freq=294Hz, sample=60, buffer_id=04:3C
    db 0,0,100,0,86,120,7,9,151,4,86,2  ; n500 t=37.337s dur=100ms, freq=1175Hz, sample=86, buffer_id=02:56 [TRUNCATE prev:ch9 @36885.0ms -> 37337.3ms]
    db 0,0,100,0,79,120,9,7,16,3,79,2  ; n501 t=37.337s dur=100ms, freq=784Hz, sample=79, buffer_id=02:4F [TRUNCATE prev:ch7 @36880.3ms -> 37337.3ms]
    db 5,0,100,0,77,110,16,8,16,3,77,16  ; n502 t=37.337s dur=100ms, freq=784Hz, sample=77, buffer_id=10:4D [TRUNCATE prev:ch8 @36880.3ms -> 37337.3ms]
    db 0,0,100,0,85,90,17,12,151,4,85,17  ; n503 t=37.342s dur=100ms, freq=1175Hz, sample=85, buffer_id=11:55 [TRUNCATE prev:ch12 @36889.7ms -> 37342.0ms]
    db 9,0,100,0,77,100,18,13,75,2,77,18  ; n504 t=37.342s dur=100ms, freq=587Hz, sample=77, buffer_id=12:4D [TRUNCATE prev:ch13 @36889.7ms -> 37342.0ms]
    db 0,0,113,0,43,120,1,10,98,0,43,1  ; n505 t=37.351s dur=113ms, freq=98Hz, sample=43, buffer_id=01:2B [TRUNCATE prev:ch10 @36885.0ms -> 37351.4ms]
    db 0,0,100,0,55,124,14,0,196,0,55,14  ; n506 t=37.351s dur=100ms, freq=196Hz, sample=55, buffer_id=0E:37 [TRUNCATE prev:ch0 @36899.1ms -> 37351.4ms]
    db 78,1,100,0,65,124,14,11,93,1,65,14  ; n507 t=37.351s dur=100ms, freq=349Hz, sample=65, buffer_id=0E:41 [TRUNCATE prev:ch11 @36885.0ms -> 37351.4ms]
    db 5,0,100,0,55,110,4,0,196,0,55,4  ; n508 t=37.686s dur=100ms, freq=196Hz, sample=55, buffer_id=04:37
    db 0,0,100,0,79,120,7,1,16,3,79,2  ; n509 t=37.691s dur=100ms, freq=784Hz, sample=79, buffer_id=02:4F
    db 0,0,100,0,79,120,9,2,16,3,79,2  ; n510 t=37.691s dur=100ms, freq=784Hz, sample=79, buffer_id=02:4F
    db 5,0,100,0,77,110,16,3,16,3,77,16  ; n511 t=37.691s dur=100ms, freq=784Hz, sample=77, buffer_id=10:4D
    db 0,0,100,0,79,90,17,4,16,3,79,17  ; n512 t=37.695s dur=100ms, freq=784Hz, sample=79, buffer_id=11:4F
    db 9,0,100,0,65,100,18,5,136,1,65,18  ; n513 t=37.695s dur=100ms, freq=392Hz, sample=65, buffer_id=12:41
    db 80,0,100,0,55,124,14,6,196,0,55,14  ; n514 t=37.705s dur=100ms, freq=196Hz, sample=55, buffer_id=0E:37
    db 0,0,149,1,60,110,4,7,6,1,60,4  ; n515 t=37.785s dur=405ms, freq=262Hz, sample=60, buffer_id=04:3C
    db 5,0,149,1,65,110,4,8,74,1,65,4  ; n516 t=37.785s dur=405ms, freq=330Hz, sample=65, buffer_id=04:41
    db 0,0,177,1,86,120,7,10,39,5,86,2  ; n517 t=37.790s dur=433ms, freq=1319Hz, sample=86, buffer_id=02:56
    db 0,0,177,1,84,120,9,9,23,4,84,2  ; n518 t=37.790s dur=433ms, freq=1047Hz, sample=84, buffer_id=02:54
    db 5,0,177,1,84,110,16,11,23,4,84,16  ; n519 t=37.790s dur=433ms, freq=1047Hz, sample=84, buffer_id=10:54
    db 0,0,50,1,85,90,17,13,39,5,85,17  ; n520 t=37.794s dur=306ms, freq=1319Hz, sample=85, buffer_id=11:55
    db 9,0,177,1,77,100,18,12,147,2,77,18  ; n521 t=37.794s dur=433ms, freq=659Hz, sample=77, buffer_id=12:4D
    db 0,0,149,1,55,124,14,0,175,0,55,14  ; n522 t=37.804s dur=405ms, freq=175Hz, sample=55, buffer_id=0E:37 [TRUNCATE prev:ch0 @37685.9ms -> 37803.7ms]
    db 0,0,149,1,55,124,14,1,220,0,55,14  ; n523 t=37.804s dur=405ms, freq=220Hz, sample=55, buffer_id=0E:37 [TRUNCATE prev:ch1 @37690.6ms -> 37803.7ms]
    db 163,1,149,1,60,124,14,2,6,1,60,14  ; n524 t=37.804s dur=405ms, freq=262Hz, sample=60, buffer_id=0E:3C [TRUNCATE prev:ch2 @37690.6ms -> 37803.7ms]
    db 9,0,113,0,29,120,2,3,49,0,29,2  ; n525 t=38.223s dur=113ms, freq=49Hz, sample=29, buffer_id=02:1D
    db 5,0,113,0,43,115,13,4,98,0,43,2  ; n526 t=38.232s dur=113ms, freq=98Hz, sample=43, buffer_id=02:2B
    db 0,0,100,0,55,110,4,5,196,0,55,4  ; n527 t=38.237s dur=100ms, freq=196Hz, sample=55, buffer_id=04:37
    db 5,0,100,0,60,110,4,6,38,1,60,4  ; n528 t=38.237s dur=100ms, freq=294Hz, sample=60, buffer_id=04:3C
    db 0,0,100,0,86,120,7,10,151,4,86,2  ; n529 t=38.242s dur=100ms, freq=1175Hz, sample=86, buffer_id=02:56 [TRUNCATE prev:ch10 @37789.6ms -> 38241.8ms]
    db 0,0,100,0,79,120,9,7,16,3,79,2  ; n530 t=38.242s dur=100ms, freq=784Hz, sample=79, buffer_id=02:4F [TRUNCATE prev:ch7 @37784.9ms -> 38241.8ms]
    db 5,0,100,0,77,110,16,8,16,3,77,16  ; n531 t=38.242s dur=100ms, freq=784Hz, sample=77, buffer_id=10:4D [TRUNCATE prev:ch8 @37784.9ms -> 38241.8ms]
    db 0,0,100,0,85,90,17,13,151,4,85,17  ; n532 t=38.247s dur=100ms, freq=1175Hz, sample=85, buffer_id=11:55 [TRUNCATE prev:ch13 @37794.3ms -> 38246.6ms]
    db 9,0,100,0,77,100,18,12,75,2,77,18  ; n533 t=38.247s dur=100ms, freq=587Hz, sample=77, buffer_id=12:4D [TRUNCATE prev:ch12 @37794.3ms -> 38246.6ms]
    db 0,0,113,0,43,120,1,9,98,0,43,1  ; n534 t=38.256s dur=113ms, freq=98Hz, sample=43, buffer_id=01:2B [TRUNCATE prev:ch9 @37789.6ms -> 38256.0ms]
    db 0,0,100,0,55,124,14,0,196,0,55,14  ; n535 t=38.256s dur=100ms, freq=196Hz, sample=55, buffer_id=0E:37 [TRUNCATE prev:ch0 @37803.7ms -> 38256.0ms]
    db 78,1,100,0,65,124,14,11,93,1,65,14  ; n536 t=38.256s dur=100ms, freq=349Hz, sample=65, buffer_id=0E:41 [TRUNCATE prev:ch11 @37789.6ms -> 38256.0ms]
    db 5,0,100,0,55,110,4,0,196,0,55,4  ; n537 t=38.590s dur=100ms, freq=196Hz, sample=55, buffer_id=04:37
    db 0,0,100,0,79,120,7,1,16,3,79,2  ; n538 t=38.595s dur=100ms, freq=784Hz, sample=79, buffer_id=02:4F
    db 0,0,100,0,79,120,9,2,16,3,79,2  ; n539 t=38.595s dur=100ms, freq=784Hz, sample=79, buffer_id=02:4F
    db 5,0,100,0,77,110,16,3,16,3,77,16  ; n540 t=38.595s dur=100ms, freq=784Hz, sample=77, buffer_id=10:4D
    db 0,0,100,0,79,90,17,4,16,3,79,17  ; n541 t=38.600s dur=100ms, freq=784Hz, sample=79, buffer_id=11:4F
    db 9,0,100,0,65,100,18,5,136,1,65,18  ; n542 t=38.600s dur=100ms, freq=392Hz, sample=65, buffer_id=12:41
    db 80,0,100,0,55,124,14,6,196,0,55,14  ; n543 t=38.609s dur=100ms, freq=196Hz, sample=55, buffer_id=0E:37
    db 0,0,202,0,60,110,4,7,6,1,60,4  ; n544 t=38.689s dur=202ms, freq=262Hz, sample=60, buffer_id=04:3C
    db 5,0,202,0,65,110,4,8,74,1,65,4  ; n545 t=38.689s dur=202ms, freq=330Hz, sample=65, buffer_id=04:41
    db 0,0,207,0,86,120,7,9,39,5,86,2  ; n546 t=38.694s dur=207ms, freq=1319Hz, sample=86, buffer_id=02:56
    db 0,0,212,0,84,120,9,10,23,4,84,2  ; n547 t=38.694s dur=212ms, freq=1047Hz, sample=84, buffer_id=02:54
    db 5,0,212,0,84,110,16,11,23,4,84,16  ; n548 t=38.694s dur=212ms, freq=1047Hz, sample=84, buffer_id=10:54
    db 0,0,212,0,85,90,17,12,39,5,85,17  ; n549 t=38.699s dur=212ms, freq=1319Hz, sample=85, buffer_id=11:55
    db 10,0,212,0,77,100,18,13,147,2,77,18  ; n550 t=38.699s dur=212ms, freq=659Hz, sample=77, buffer_id=12:4D
    db 0,0,202,0,55,124,14,0,175,0,55,14  ; n551 t=38.708s dur=202ms, freq=175Hz, sample=55, buffer_id=0E:37 [TRUNCATE prev:ch0 @38590.5ms -> 38708.3ms]
    db 0,0,202,0,55,124,14,1,220,0,55,14  ; n552 t=38.708s dur=202ms, freq=220Hz, sample=55, buffer_id=0E:37 [TRUNCATE prev:ch1 @38595.2ms -> 38708.3ms]
    db 193,0,202,0,60,124,14,2,6,1,60,14  ; n553 t=38.708s dur=202ms, freq=262Hz, sample=60, buffer_id=0E:3C [TRUNCATE prev:ch2 @38595.2ms -> 38708.3ms]
    db 9,0,113,0,29,120,2,3,49,0,29,2  ; n554 t=38.901s dur=113ms, freq=49Hz, sample=29, buffer_id=02:1D
    db 5,0,113,0,43,115,13,4,98,0,43,2  ; n555 t=38.911s dur=113ms, freq=98Hz, sample=43, buffer_id=02:2B
    db 0,0,100,0,55,110,4,5,196,0,55,4  ; n556 t=38.916s dur=100ms, freq=196Hz, sample=55, buffer_id=04:37
    db 5,0,100,0,60,110,4,6,38,1,60,4  ; n557 t=38.916s dur=100ms, freq=294Hz, sample=60, buffer_id=04:3C
    db 0,0,100,0,86,120,7,9,151,4,86,2  ; n558 t=38.920s dur=100ms, freq=1175Hz, sample=86, buffer_id=02:56 [TRUNCATE prev:ch9 @38694.1ms -> 38920.3ms]
    db 0,0,100,0,79,120,9,7,16,3,79,2  ; n559 t=38.920s dur=100ms, freq=784Hz, sample=79, buffer_id=02:4F [TRUNCATE prev:ch7 @38689.4ms -> 38920.3ms]
    db 5,0,100,0,77,110,16,8,16,3,77,16  ; n560 t=38.920s dur=100ms, freq=784Hz, sample=77, buffer_id=10:4D [TRUNCATE prev:ch8 @38689.4ms -> 38920.3ms]
    db 0,0,100,0,85,90,17,12,151,4,85,17  ; n561 t=38.925s dur=100ms, freq=1175Hz, sample=85, buffer_id=11:55 [TRUNCATE prev:ch12 @38698.8ms -> 38925.0ms]
    db 9,0,100,0,77,100,18,13,75,2,77,18  ; n562 t=38.925s dur=100ms, freq=587Hz, sample=77, buffer_id=12:4D [TRUNCATE prev:ch13 @38698.8ms -> 38925.0ms]
    db 0,0,113,0,43,120,1,10,98,0,43,1  ; n563 t=38.934s dur=113ms, freq=98Hz, sample=43, buffer_id=01:2B [TRUNCATE prev:ch10 @38694.1ms -> 38934.4ms]
    db 0,0,100,0,55,124,14,0,196,0,55,14  ; n564 t=38.934s dur=100ms, freq=196Hz, sample=55, buffer_id=0E:37 [TRUNCATE prev:ch0 @38708.3ms -> 38934.4ms]
    db 203,0,100,0,65,124,14,11,93,1,65,14  ; n565 t=38.934s dur=100ms, freq=349Hz, sample=65, buffer_id=0E:41 [TRUNCATE prev:ch11 @38694.1ms -> 38934.4ms]
    db 0,0,113,0,56,120,11,1,196,0,56,2  ; n566 t=39.137s dur=113ms, freq=196Hz, sample=56, buffer_id=02:38
    db 5,0,113,0,52,115,13,2,165,0,52,2  ; n567 t=39.137s dur=113ms, freq=165Hz, sample=52, buffer_id=02:34
    db 5,0,113,0,50,110,4,3,165,0,50,4  ; n568 t=39.142s dur=113ms, freq=165Hz, sample=50, buffer_id=04:32 [TRUNCATE prev:ch3 @38901.4ms -> 39141.7ms]
    db 14,0,113,0,60,120,9,4,6,1,60,2  ; n569 t=39.146s dur=113ms, freq=262Hz, sample=60, buffer_id=02:3C [TRUNCATE prev:ch4 @38910.8ms -> 39146.4ms]
    db 46,1,113,0,50,124,14,5,165,0,50,14  ; n570 t=39.160s dur=113ms, freq=165Hz, sample=50, buffer_id=0E:32 [TRUNCATE prev:ch5 @38915.6ms -> 39160.5ms]
    db 28,0,100,0,63,120,9,0,74,1,63,2  ; n571 t=39.462s dur=100ms, freq=330Hz, sample=63, buffer_id=02:3F
    db 0,0,100,0,60,120,11,1,6,1,60,2  ; n572 t=39.490s dur=100ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 5,0,100,0,56,115,13,2,196,0,56,2  ; n573 t=39.490s dur=100ms, freq=196Hz, sample=56, buffer_id=02:38
    db 19,0,100,0,55,110,4,3,196,0,55,4  ; n574 t=39.495s dur=100ms, freq=196Hz, sample=55, buffer_id=04:37
    db 47,0,100,0,55,124,14,4,196,0,55,14  ; n575 t=39.514s dur=100ms, freq=196Hz, sample=55, buffer_id=0E:37
    db 19,0,241,0,61,120,9,5,38,1,61,2  ; n576 t=39.561s dur=241ms, freq=294Hz, sample=61, buffer_id=02:3D
    db 9,0,169,0,36,120,2,6,65,0,36,2  ; n577 t=39.580s dur=169ms, freq=65Hz, sample=36, buffer_id=02:24
    db 0,0,219,4,58,120,11,7,233,0,58,2  ; n578 t=39.589s dur=1243ms, freq=233Hz, sample=58, buffer_id=02:3A
    db 5,0,219,4,53,115,13,8,175,0,53,2  ; n579 t=39.589s dur=1243ms, freq=175Hz, sample=53, buffer_id=02:35
    db 19,0,219,4,55,110,4,9,175,0,55,4  ; n580 t=39.594s dur=1243ms, freq=175Hz, sample=55, buffer_id=04:37
    db 0,0,219,4,55,124,14,10,175,0,55,14  ; n581 t=39.613s dur=1243ms, freq=175Hz, sample=55, buffer_id=0E:37
    db 163,1,169,0,36,100,19,11,65,0,36,19  ; n582 t=39.613s dur=169ms, freq=65Hz, sample=36, buffer_id=13:24
    db 33,0,169,0,36,120,2,0,65,0,36,2  ; n583 t=40.032s dur=169ms, freq=65Hz, sample=36, buffer_id=02:24
    db 163,1,169,0,36,100,19,1,65,0,36,19  ; n584 t=40.065s dur=169ms, freq=65Hz, sample=36, buffer_id=13:24
    db 33,0,169,0,36,120,2,1,65,0,36,2  ; n585 t=40.484s dur=169ms, freq=65Hz, sample=36, buffer_id=02:24
    db 163,1,169,0,36,100,19,0,65,0,36,19  ; n586 t=40.517s dur=169ms, freq=65Hz, sample=36, buffer_id=13:24
    db 9,0,169,0,36,120,2,0,65,0,36,2  ; n587 t=40.937s dur=169ms, freq=65Hz, sample=36, buffer_id=02:24
    db 0,0,113,0,53,120,11,1,175,0,53,2  ; n588 t=40.946s dur=113ms, freq=175Hz, sample=53, buffer_id=02:35
    db 5,0,113,0,50,115,13,2,147,0,50,2  ; n589 t=40.946s dur=113ms, freq=147Hz, sample=50, buffer_id=02:32
    db 5,0,113,0,50,110,4,3,147,0,50,4  ; n590 t=40.951s dur=113ms, freq=147Hz, sample=50, buffer_id=04:32
    db 14,0,113,0,58,120,9,4,233,0,58,2  ; n591 t=40.956s dur=113ms, freq=233Hz, sample=58, buffer_id=02:3A
    db 0,0,113,0,50,124,14,5,147,0,50,14  ; n592 t=40.970s dur=113ms, freq=147Hz, sample=50, buffer_id=0E:32
    db 74,1,169,0,36,100,19,6,65,0,36,19  ; n593 t=40.970s dur=169ms, freq=65Hz, sample=36, buffer_id=13:24
    db 0,0,100,0,58,120,11,1,233,0,58,2  ; n594 t=41.300s dur=100ms, freq=233Hz, sample=58, buffer_id=02:3A
    db 5,0,100,0,53,115,13,2,175,0,53,2  ; n595 t=41.300s dur=100ms, freq=175Hz, sample=53, buffer_id=02:35
    db 5,0,100,0,55,110,4,3,175,0,55,4  ; n596 t=41.304s dur=100ms, freq=175Hz, sample=55, buffer_id=04:37
    db 14,0,100,0,61,120,9,0,38,1,61,2  ; n597 t=41.309s dur=100ms, freq=294Hz, sample=61, buffer_id=02:3D
    db 66,0,100,0,55,124,14,4,175,0,55,14  ; n598 t=41.323s dur=100ms, freq=175Hz, sample=55, buffer_id=0E:37
    db 9,0,169,0,36,120,2,5,65,0,36,2  ; n599 t=41.389s dur=169ms, freq=65Hz, sample=36, buffer_id=02:24
    db 0,0,100,0,56,120,11,6,196,0,56,2  ; n600 t=41.398s dur=100ms, freq=196Hz, sample=56, buffer_id=02:38
    db 5,0,100,0,52,115,13,7,165,0,52,2  ; n601 t=41.398s dur=100ms, freq=165Hz, sample=52, buffer_id=02:34
    db 5,0,100,0,50,110,4,8,165,0,50,4  ; n602 t=41.403s dur=100ms, freq=165Hz, sample=50, buffer_id=04:32
    db 9,0,100,0,60,120,9,9,6,1,60,2  ; n603 t=41.408s dur=100ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 5,0,169,0,36,100,19,10,65,0,36,19  ; n604 t=41.417s dur=169ms, freq=65Hz, sample=36, buffer_id=13:24
    db 108,0,100,0,50,124,14,11,165,0,50,14  ; n605 t=41.422s dur=100ms, freq=165Hz, sample=50, buffer_id=0E:32
    db 0,0,100,0,63,120,11,12,74,1,63,2  ; n606 t=41.530s dur=100ms, freq=330Hz, sample=63, buffer_id=02:3F
    db 5,0,100,0,56,115,13,13,196,0,56,2  ; n607 t=41.530s dur=100ms, freq=196Hz, sample=56, buffer_id=02:38
    db 5,0,100,0,55,110,4,3,196,0,55,4  ; n608 t=41.535s dur=100ms, freq=196Hz, sample=55, buffer_id=04:37 [TRUNCATE prev:ch3 @41304.2ms -> 41535.0ms]
    db 14,0,100,0,67,120,9,1,136,1,67,2  ; n609 t=41.540s dur=100ms, freq=392Hz, sample=67, buffer_id=02:43 [TRUNCATE prev:ch1 @41299.5ms -> 41539.8ms]
    db 108,0,100,0,55,124,14,4,196,0,55,14  ; n610 t=41.554s dur=100ms, freq=196Hz, sample=55, buffer_id=0E:37 [TRUNCATE prev:ch4 @41323.0ms -> 41553.9ms]
    db 0,0,249,3,67,120,11,0,136,1,67,2  ; n611 t=41.662s dur=1017ms, freq=392Hz, sample=67, buffer_id=02:43
    db 5,0,249,3,63,115,13,2,74,1,63,2  ; n612 t=41.662s dur=1017ms, freq=330Hz, sample=63, buffer_id=02:3F
    db 5,0,249,3,65,110,4,5,74,1,65,4  ; n613 t=41.667s dur=1017ms, freq=330Hz, sample=65, buffer_id=04:41 [TRUNCATE prev:ch5 @41389.0ms -> 41667.0ms]
    db 14,0,249,3,72,120,9,6,11,2,72,2  ; n614 t=41.672s dur=1017ms, freq=523Hz, sample=72, buffer_id=02:48 [TRUNCATE prev:ch6 @41398.4ms -> 41671.7ms]
    db 155,0,249,3,65,124,14,7,74,1,65,14  ; n615 t=41.686s dur=1017ms, freq=330Hz, sample=65, buffer_id=0E:41 [TRUNCATE prev:ch7 @41398.4ms -> 41685.8ms]
    db 28,0,169,0,36,120,2,1,65,0,36,2  ; n616 t=41.841s dur=169ms, freq=65Hz, sample=36, buffer_id=02:24
    db 168,1,169,0,36,100,19,3,65,0,36,19  ; n617 t=41.870s dur=169ms, freq=65Hz, sample=36, buffer_id=13:24
    db 28,0,169,0,36,120,2,3,65,0,36,2  ; n618 t=42.294s dur=169ms, freq=65Hz, sample=36, buffer_id=02:24
    db 168,1,169,0,36,100,19,1,65,0,36,19  ; n619 t=42.322s dur=169ms, freq=65Hz, sample=36, buffer_id=13:24
    db 9,0,169,0,36,120,2,1,65,0,36,2  ; n620 t=42.746s dur=169ms, freq=65Hz, sample=36, buffer_id=02:24
    db 0,0,113,0,56,120,11,3,196,0,56,2  ; n621 t=42.755s dur=113ms, freq=196Hz, sample=56, buffer_id=02:38
    db 5,0,113,0,52,115,13,4,165,0,52,2  ; n622 t=42.755s dur=113ms, freq=165Hz, sample=52, buffer_id=02:34
    db 5,0,113,0,50,110,4,9,165,0,50,4  ; n623 t=42.760s dur=113ms, freq=165Hz, sample=50, buffer_id=04:32
    db 9,0,113,0,60,120,9,8,6,1,60,2  ; n624 t=42.765s dur=113ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 5,0,169,0,36,100,19,11,65,0,36,19  ; n625 t=42.774s dur=169ms, freq=65Hz, sample=36, buffer_id=13:24
    db 74,1,113,0,50,124,14,10,165,0,50,14  ; n626 t=42.779s dur=113ms, freq=165Hz, sample=50, buffer_id=0E:32
    db 0,0,100,0,60,120,11,0,6,1,60,2  ; n627 t=43.109s dur=100ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 5,0,100,0,56,115,13,2,196,0,56,2  ; n628 t=43.109s dur=100ms, freq=196Hz, sample=56, buffer_id=02:38
    db 5,0,100,0,55,110,4,3,196,0,55,4  ; n629 t=43.113s dur=100ms, freq=196Hz, sample=55, buffer_id=04:37
    db 14,0,100,0,63,120,9,1,74,1,63,2  ; n630 t=43.118s dur=100ms, freq=330Hz, sample=63, buffer_id=02:3F
    db 66,0,100,0,55,124,14,4,196,0,55,14  ; n631 t=43.132s dur=100ms, freq=196Hz, sample=55, buffer_id=0E:37
    db 9,0,169,0,36,120,2,5,65,0,36,2  ; n632 t=43.198s dur=169ms, freq=65Hz, sample=36, buffer_id=02:24
    db 0,0,219,4,58,120,11,6,233,0,58,2  ; n633 t=43.208s dur=1243ms, freq=233Hz, sample=58, buffer_id=02:3A
    db 5,0,219,4,53,115,13,7,175,0,53,2  ; n634 t=43.208s dur=1243ms, freq=175Hz, sample=53, buffer_id=02:35
    db 5,0,219,4,55,110,4,8,175,0,55,4  ; n635 t=43.212s dur=1243ms, freq=175Hz, sample=55, buffer_id=04:37
    db 9,0,241,0,61,120,9,9,38,1,61,2  ; n636 t=43.217s dur=241ms, freq=294Hz, sample=61, buffer_id=02:3D
    db 5,0,169,0,36,100,19,10,65,0,36,19  ; n637 t=43.226s dur=169ms, freq=65Hz, sample=36, buffer_id=13:24
    db 221,0,219,4,55,124,14,11,175,0,55,14  ; n638 t=43.231s dur=1243ms, freq=175Hz, sample=55, buffer_id=0E:37
    db 0,0,150,0,73,110,16,0,75,2,73,16  ; n639 t=43.453s dur=150ms, freq=587Hz, sample=73, buffer_id=10:49
    db 198,0,150,0,73,110,16,1,210,1,73,16  ; n640 t=43.453s dur=150ms, freq=466Hz, sample=73, buffer_id=10:49
    db 28,0,169,0,36,120,2,2,65,0,36,2  ; n641 t=43.650s dur=169ms, freq=65Hz, sample=36, buffer_id=02:24
    db 0,0,100,0,73,110,16,3,210,1,73,16  ; n642 t=43.679s dur=100ms, freq=466Hz, sample=73, buffer_id=10:49
    db 0,0,100,0,65,110,16,4,93,1,65,16  ; n643 t=43.679s dur=100ms, freq=349Hz, sample=65, buffer_id=10:41
    db 75,0,169,0,36,100,19,5,65,0,36,19  ; n644 t=43.679s dur=169ms, freq=65Hz, sample=36, buffer_id=13:24
    db 0,0,100,0,73,110,16,9,75,2,73,16  ; n645 t=43.754s dur=100ms, freq=587Hz, sample=73, buffer_id=10:49
    db 75,0,100,0,73,110,16,10,210,1,73,16  ; n646 t=43.754s dur=100ms, freq=466Hz, sample=73, buffer_id=10:49
    db 0,0,100,0,77,110,16,0,186,2,77,16  ; n647 t=43.829s dur=100ms, freq=698Hz, sample=77, buffer_id=10:4D
    db 75,0,100,0,73,110,16,12,75,2,73,16  ; n648 t=43.829s dur=100ms, freq=587Hz, sample=73, buffer_id=10:49
    db 0,0,150,0,84,110,16,1,164,3,84,16  ; n649 t=43.905s dur=150ms, freq=932Hz, sample=84, buffer_id=10:54
    db 198,0,150,0,77,110,16,13,186,2,77,16  ; n650 t=43.905s dur=150ms, freq=698Hz, sample=77, buffer_id=10:4D
    db 28,0,169,0,36,120,2,3,65,0,36,2  ; n651 t=44.103s dur=169ms, freq=65Hz, sample=36, buffer_id=02:24
    db 0,0,100,0,73,110,16,0,75,2,73,16  ; n652 t=44.131s dur=100ms, freq=587Hz, sample=73, buffer_id=10:49
    db 0,0,100,0,73,110,16,2,210,1,73,16  ; n653 t=44.131s dur=100ms, freq=466Hz, sample=73, buffer_id=10:49
    db 75,0,169,0,36,100,19,4,65,0,36,19  ; n654 t=44.131s dur=169ms, freq=65Hz, sample=36, buffer_id=13:24
    db 0,0,100,0,77,110,16,5,186,2,77,16  ; n655 t=44.206s dur=100ms, freq=698Hz, sample=77, buffer_id=10:4D
    db 75,0,100,0,73,110,16,9,75,2,73,16  ; n656 t=44.206s dur=100ms, freq=587Hz, sample=73, buffer_id=10:49 [TRUNCATE prev:ch9 @43754.1ms -> 44206.3ms]
    db 0,0,100,0,84,110,16,10,164,3,84,16  ; n657 t=44.282s dur=100ms, freq=932Hz, sample=84, buffer_id=10:54
    db 75,0,100,0,77,110,16,1,186,2,77,16  ; n658 t=44.282s dur=100ms, freq=698Hz, sample=77, buffer_id=10:4D
    db 0,0,15,2,84,110,16,12,151,4,84,16  ; n659 t=44.357s dur=527ms, freq=1175Hz, sample=84, buffer_id=10:54
    db 198,0,15,2,84,110,16,13,164,3,84,16  ; n660 t=44.357s dur=527ms, freq=932Hz, sample=84, buffer_id=10:54
    db 9,0,169,0,36,120,2,0,65,0,36,2  ; n661 t=44.555s dur=169ms, freq=65Hz, sample=36, buffer_id=02:24
    db 0,0,113,0,53,120,11,2,175,0,53,2  ; n662 t=44.564s dur=113ms, freq=175Hz, sample=53, buffer_id=02:35
    db 5,0,113,0,50,115,13,3,147,0,50,2  ; n663 t=44.564s dur=113ms, freq=147Hz, sample=50, buffer_id=02:32
    db 5,0,113,0,50,110,4,4,147,0,50,4  ; n664 t=44.569s dur=113ms, freq=147Hz, sample=50, buffer_id=04:32
    db 9,0,113,0,58,120,9,5,233,0,58,2  ; n665 t=44.574s dur=113ms, freq=233Hz, sample=58, buffer_id=02:3A
    db 5,0,169,0,36,100,19,1,65,0,36,19  ; n666 t=44.583s dur=169ms, freq=65Hz, sample=36, buffer_id=13:24
    db 74,1,113,0,50,124,14,9,147,0,50,14  ; n667 t=44.588s dur=113ms, freq=147Hz, sample=50, buffer_id=0E:32
    db 0,0,100,0,58,120,11,2,233,0,58,2  ; n668 t=44.918s dur=100ms, freq=233Hz, sample=58, buffer_id=02:3A
    db 5,0,100,0,53,115,13,3,175,0,53,2  ; n669 t=44.918s dur=100ms, freq=175Hz, sample=53, buffer_id=02:35
    db 5,0,100,0,55,110,4,4,175,0,55,4  ; n670 t=44.922s dur=100ms, freq=175Hz, sample=55, buffer_id=04:37
    db 14,0,100,0,61,120,9,0,38,1,61,2  ; n671 t=44.927s dur=100ms, freq=294Hz, sample=61, buffer_id=02:3D
    db 66,0,100,0,55,124,14,5,175,0,55,14  ; n672 t=44.941s dur=100ms, freq=175Hz, sample=55, buffer_id=0E:37
    db 9,0,169,0,36,120,2,1,65,0,36,2  ; n673 t=45.007s dur=169ms, freq=65Hz, sample=36, buffer_id=02:24
    db 0,0,100,0,56,120,11,6,196,0,56,2  ; n674 t=45.017s dur=100ms, freq=196Hz, sample=56, buffer_id=02:38
    db 5,0,100,0,52,115,13,7,165,0,52,2  ; n675 t=45.017s dur=100ms, freq=165Hz, sample=52, buffer_id=02:34
    db 5,0,100,0,50,110,4,8,165,0,50,4  ; n676 t=45.021s dur=100ms, freq=165Hz, sample=50, buffer_id=04:32
    db 9,0,100,0,60,120,9,9,6,1,60,2  ; n677 t=45.026s dur=100ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 5,0,169,0,36,100,19,10,65,0,36,19  ; n678 t=45.035s dur=169ms, freq=65Hz, sample=36, buffer_id=13:24
    db 108,0,100,0,50,124,14,11,165,0,50,14  ; n679 t=45.040s dur=100ms, freq=165Hz, sample=50, buffer_id=0E:32
    db 0,0,100,0,63,120,11,12,74,1,63,2  ; n680 t=45.149s dur=100ms, freq=330Hz, sample=63, buffer_id=02:3F
    db 5,0,100,0,56,115,13,13,196,0,56,2  ; n681 t=45.149s dur=100ms, freq=196Hz, sample=56, buffer_id=02:38
    db 5,0,100,0,55,110,4,4,196,0,55,4  ; n682 t=45.153s dur=100ms, freq=196Hz, sample=55, buffer_id=04:37 [TRUNCATE prev:ch4 @44922.5ms -> 45153.3ms]
    db 14,0,100,0,67,120,9,2,136,1,67,2  ; n683 t=45.158s dur=100ms, freq=392Hz, sample=67, buffer_id=02:43 [TRUNCATE prev:ch2 @44917.7ms -> 45158.0ms]
    db 90,0,100,0,55,124,14,5,196,0,55,14  ; n684 t=45.172s dur=100ms, freq=196Hz, sample=55, buffer_id=0E:37 [TRUNCATE prev:ch5 @44941.3ms -> 45172.2ms]
    db 0,0,150,0,77,110,16,0,16,3,77,16  ; n685 t=45.262s dur=150ms, freq=784Hz, sample=77, buffer_id=10:4D
    db 19,0,150,0,77,110,16,3,147,2,77,16  ; n686 t=45.262s dur=150ms, freq=659Hz, sample=77, buffer_id=10:4D
    db 0,0,249,3,67,120,11,2,136,1,67,2  ; n687 t=45.281s dur=1017ms, freq=392Hz, sample=67, buffer_id=02:43 [TRUNCATE prev:ch2 @45158.0ms -> 45280.5ms]
    db 5,0,249,3,63,115,13,12,74,1,63,2  ; n688 t=45.281s dur=1017ms, freq=330Hz, sample=63, buffer_id=02:3F [TRUNCATE prev:ch12 @45148.6ms -> 45280.5ms]
    db 5,0,249,3,65,110,4,1,74,1,65,4  ; n689 t=45.285s dur=1017ms, freq=330Hz, sample=65, buffer_id=04:41 [TRUNCATE prev:ch1 @45007.3ms -> 45285.2ms]
    db 14,0,249,3,72,120,9,6,11,2,72,2  ; n690 t=45.290s dur=1017ms, freq=523Hz, sample=72, buffer_id=02:48 [TRUNCATE prev:ch6 @45016.7ms -> 45289.9ms]
    db 155,0,249,3,65,124,14,7,74,1,65,14  ; n691 t=45.304s dur=1017ms, freq=330Hz, sample=65, buffer_id=0E:41 [TRUNCATE prev:ch7 @45016.7ms -> 45304.1ms]
    db 28,0,169,0,36,120,2,4,65,0,36,2  ; n692 t=45.459s dur=169ms, freq=65Hz, sample=36, buffer_id=02:24
    db 0,0,100,0,77,110,16,5,147,2,77,16  ; n693 t=45.488s dur=100ms, freq=659Hz, sample=77, buffer_id=10:4D
    db 0,0,100,0,65,110,16,8,136,1,65,16  ; n694 t=45.488s dur=100ms, freq=392Hz, sample=65, buffer_id=10:41
    db 75,0,169,0,36,100,19,9,65,0,36,19  ; n695 t=45.488s dur=169ms, freq=65Hz, sample=36, buffer_id=13:24
    db 0,0,100,0,77,110,16,10,16,3,77,16  ; n696 t=45.563s dur=100ms, freq=784Hz, sample=77, buffer_id=10:4D
    db 75,0,100,0,73,110,16,11,11,2,73,16  ; n697 t=45.563s dur=100ms, freq=523Hz, sample=73, buffer_id=10:49
    db 0,0,100,0,84,110,16,0,23,4,84,16  ; n698 t=45.639s dur=100ms, freq=1047Hz, sample=84, buffer_id=10:54
    db 75,0,100,0,77,110,16,13,147,2,77,16  ; n699 t=45.639s dur=100ms, freq=659Hz, sample=77, buffer_id=10:4D
    db 0,0,150,0,89,110,16,3,39,5,89,16  ; n700 t=45.714s dur=150ms, freq=1319Hz, sample=89, buffer_id=10:59
    db 198,0,150,0,77,110,16,5,16,3,77,16  ; n701 t=45.714s dur=150ms, freq=784Hz, sample=77, buffer_id=10:4D [TRUNCATE prev:ch5 @45487.8ms -> 45714.0ms]
    db 28,0,169,0,36,120,2,8,65,0,36,2  ; n702 t=45.912s dur=169ms, freq=65Hz, sample=36, buffer_id=02:24
    db 0,0,100,0,77,110,16,0,16,3,77,16  ; n703 t=45.940s dur=100ms, freq=784Hz, sample=77, buffer_id=10:4D
    db 0,0,100,0,77,110,16,4,147,2,77,16  ; n704 t=45.940s dur=100ms, freq=659Hz, sample=77, buffer_id=10:4D
    db 75,0,169,0,36,100,19,10,65,0,36,19  ; n705 t=45.940s dur=169ms, freq=65Hz, sample=36, buffer_id=13:24
    db 0,0,100,0,84,110,16,9,23,4,84,16  ; n706 t=46.016s dur=100ms, freq=1047Hz, sample=84, buffer_id=10:54
    db 75,0,100,0,77,110,16,11,16,3,77,16  ; n707 t=46.016s dur=100ms, freq=784Hz, sample=77, buffer_id=10:4D
    db 0,0,100,0,89,110,16,5,39,5,89,16  ; n708 t=46.091s dur=100ms, freq=1319Hz, sample=89, buffer_id=10:59
    db 75,0,100,0,84,110,16,3,23,4,84,16  ; n709 t=46.091s dur=100ms, freq=1047Hz, sample=84, buffer_id=10:54
    db 0,0,15,2,89,110,16,13,32,6,89,16  ; n710 t=46.166s dur=527ms, freq=1568Hz, sample=89, buffer_id=10:59
    db 198,0,15,2,89,110,16,2,39,5,89,16  ; n711 t=46.166s dur=527ms, freq=1319Hz, sample=89, buffer_id=10:59 [TRUNCATE prev:ch2 @45280.5ms -> 46166.2ms]
    db 9,0,169,0,36,120,2,0,65,0,36,2  ; n712 t=46.364s dur=169ms, freq=65Hz, sample=36, buffer_id=02:24
    db 5,0,113,0,61,115,13,4,38,1,61,2  ; n713 t=46.373s dur=113ms, freq=294Hz, sample=61, buffer_id=02:3D
    db 14,0,113,0,60,110,4,8,38,1,60,4  ; n714 t=46.378s dur=113ms, freq=294Hz, sample=60, buffer_id=04:3C
    db 5,0,169,0,36,100,19,3,65,0,36,19  ; n715 t=46.392s dur=169ms, freq=65Hz, sample=36, buffer_id=13:24
    db 74,1,113,0,60,124,14,5,38,1,60,14  ; n716 t=46.397s dur=113ms, freq=294Hz, sample=60, buffer_id=0E:3C
    db 5,0,100,0,63,115,13,1,74,1,63,2  ; n717 t=46.727s dur=100ms, freq=330Hz, sample=63, buffer_id=02:3F
    db 19,0,100,0,65,110,4,4,74,1,65,4  ; n718 t=46.732s dur=100ms, freq=330Hz, sample=65, buffer_id=04:41
    db 66,0,100,0,65,124,14,0,74,1,65,14  ; n719 t=46.750s dur=100ms, freq=330Hz, sample=65, buffer_id=0E:41
    db 9,0,169,0,36,120,2,3,65,0,36,2  ; n720 t=46.816s dur=169ms, freq=65Hz, sample=36, buffer_id=02:24
    db 5,0,219,4,65,115,13,5,93,1,65,2  ; n721 t=46.826s dur=1243ms, freq=349Hz, sample=65, buffer_id=02:41
    db 5,0,219,4,65,110,4,6,93,1,65,4  ; n722 t=46.831s dur=1243ms, freq=349Hz, sample=65, buffer_id=04:41
    db 0,0,17,7,73,120,7,7,75,2,73,2  ; n723 t=46.835s dur=1809ms, freq=587Hz, sample=73, buffer_id=02:49
    db 10,0,17,7,71,120,9,8,210,1,71,2  ; n724 t=46.835s dur=1809ms, freq=466Hz, sample=71, buffer_id=02:47
    db 5,0,169,0,36,100,19,9,65,0,36,19  ; n725 t=46.845s dur=169ms, freq=65Hz, sample=36, buffer_id=13:24
    db 221,0,219,4,65,124,14,10,93,1,65,14  ; n726 t=46.849s dur=1243ms, freq=349Hz, sample=65, buffer_id=0E:41
    db 0,0,150,0,77,110,16,0,186,2,77,16  ; n727 t=47.071s dur=150ms, freq=698Hz, sample=77, buffer_id=10:4D
    db 198,0,150,0,73,110,16,1,75,2,73,16  ; n728 t=47.071s dur=150ms, freq=587Hz, sample=73, buffer_id=10:49
    db 28,0,169,0,36,120,2,2,65,0,36,2  ; n729 t=47.269s dur=169ms, freq=65Hz, sample=36, buffer_id=02:24
    db 0,0,100,0,73,110,16,3,75,2,73,16  ; n730 t=47.297s dur=100ms, freq=587Hz, sample=73, buffer_id=10:49
    db 0,0,100,0,73,110,16,4,210,1,73,16  ; n731 t=47.297s dur=100ms, freq=466Hz, sample=73, buffer_id=10:49
    db 5,0,169,0,36,100,19,11,65,0,36,19  ; n732 t=47.297s dur=169ms, freq=65Hz, sample=36, buffer_id=13:24
    db 56,0,100,0,58,100,22,9,233,0,58,22  ; n733 t=47.302s dur=100ms, freq=233Hz, sample=58, buffer_id=16:3A
    db 14,0,100,0,58,100,22,12,38,1,58,22  ; n734 t=47.358s dur=100ms, freq=294Hz, sample=58, buffer_id=16:3A
    db 0,0,100,0,77,110,16,13,186,2,77,16  ; n735 t=47.372s dur=100ms, freq=698Hz, sample=77, buffer_id=10:4D
    db 42,0,100,0,73,110,16,1,75,2,73,16  ; n736 t=47.372s dur=100ms, freq=587Hz, sample=73, buffer_id=10:49 [TRUNCATE prev:ch1 @47070.8ms -> 47372.3ms]
    db 33,0,100,0,70,100,22,5,93,1,70,22  ; n737 t=47.415s dur=100ms, freq=349Hz, sample=70, buffer_id=16:46 [TRUNCATE prev:ch5 @46825.8ms -> 47414.7ms]
    db 0,0,100,0,84,110,16,0,164,3,84,16  ; n738 t=47.448s dur=100ms, freq=932Hz, sample=84, buffer_id=10:54
    db 24,0,100,0,77,110,16,6,186,2,77,16  ; n739 t=47.448s dur=100ms, freq=698Hz, sample=77, buffer_id=10:4D [TRUNCATE prev:ch6 @46830.5ms -> 47447.7ms]
    db 52,0,100,0,70,100,22,7,210,1,70,22  ; n740 t=47.471s dur=100ms, freq=466Hz, sample=70, buffer_id=16:46 [TRUNCATE prev:ch7 @46835.2ms -> 47471.3ms]
    db 0,0,150,0,84,110,16,8,151,4,84,16  ; n741 t=47.523s dur=150ms, freq=1175Hz, sample=84, buffer_id=10:54 [TRUNCATE prev:ch8 @46835.2ms -> 47523.1ms]
    db 5,0,150,0,84,110,16,10,164,3,84,16  ; n742 t=47.523s dur=150ms, freq=932Hz, sample=84, buffer_id=10:54 [TRUNCATE prev:ch10 @46849.4ms -> 47523.1ms]
    db 56,0,100,0,75,100,22,2,75,2,75,22  ; n743 t=47.528s dur=100ms, freq=587Hz, sample=75, buffer_id=16:4B [TRUNCATE prev:ch2 @47268.7ms -> 47527.8ms]
    db 137,0,100,0,75,100,22,3,186,2,75,22  ; n744 t=47.584s dur=100ms, freq=698Hz, sample=75, buffer_id=16:4B [TRUNCATE prev:ch3 @47296.9ms -> 47584.3ms]
    db 28,0,169,0,36,120,2,1,65,0,36,2  ; n745 t=47.721s dur=169ms, freq=65Hz, sample=36, buffer_id=02:24
    db 0,0,100,0,77,110,16,0,186,2,77,16  ; n746 t=47.749s dur=100ms, freq=698Hz, sample=77, buffer_id=10:4D
    db 0,0,100,0,73,110,16,5,75,2,73,16  ; n747 t=47.749s dur=100ms, freq=587Hz, sample=73, buffer_id=10:49
    db 75,0,169,0,36,100,19,4,65,0,36,19  ; n748 t=47.749s dur=169ms, freq=65Hz, sample=36, buffer_id=13:24
    db 75,0,100,0,84,110,16,6,164,3,84,16  ; n749 t=47.825s dur=100ms, freq=932Hz, sample=84, buffer_id=10:54
    db 75,0,100,0,84,110,16,2,151,4,84,16  ; n750 t=47.900s dur=100ms, freq=1175Hz, sample=84, buffer_id=10:54
    db 0,0,15,2,89,110,16,3,117,5,89,16  ; n751 t=47.975s dur=527ms, freq=1397Hz, sample=89, buffer_id=10:59
    db 198,0,15,2,84,110,16,7,151,4,84,16  ; n752 t=47.975s dur=527ms, freq=1175Hz, sample=84, buffer_id=10:54
    db 9,0,169,0,36,120,2,0,65,0,36,2  ; n753 t=48.173s dur=169ms, freq=65Hz, sample=36, buffer_id=02:24
    db 5,0,113,0,61,115,13,1,38,1,61,2  ; n754 t=48.183s dur=113ms, freq=294Hz, sample=61, buffer_id=02:3D
    db 14,0,113,0,60,110,4,4,38,1,60,4  ; n755 t=48.187s dur=113ms, freq=294Hz, sample=60, buffer_id=04:3C
    db 5,0,169,0,36,100,19,2,65,0,36,19  ; n756 t=48.202s dur=169ms, freq=65Hz, sample=36, buffer_id=13:24
    db 74,1,113,0,60,124,14,5,38,1,60,14  ; n757 t=48.206s dur=113ms, freq=294Hz, sample=60, buffer_id=0E:3C
    db 5,0,100,0,65,115,13,1,93,1,65,2  ; n758 t=48.536s dur=100ms, freq=349Hz, sample=65, buffer_id=02:41
    db 19,0,100,0,65,110,4,4,93,1,65,4  ; n759 t=48.541s dur=100ms, freq=349Hz, sample=65, buffer_id=04:41
    db 66,0,100,0,65,124,14,0,93,1,65,14  ; n760 t=48.560s dur=100ms, freq=349Hz, sample=65, buffer_id=0E:41
    db 9,0,169,0,36,120,2,2,65,0,36,2  ; n761 t=48.626s dur=169ms, freq=65Hz, sample=36, buffer_id=02:24
    db 5,0,100,0,63,115,13,5,55,1,63,2  ; n762 t=48.635s dur=100ms, freq=311Hz, sample=63, buffer_id=02:3F
    db 5,0,100,0,65,110,4,6,55,1,65,4  ; n763 t=48.640s dur=100ms, freq=311Hz, sample=65, buffer_id=04:41
    db 0,0,17,7,72,120,7,8,11,2,72,2  ; n764 t=48.644s dur=1809ms, freq=523Hz, sample=72, buffer_id=02:48
    db 9,0,17,7,67,120,9,9,159,1,67,2  ; n765 t=48.644s dur=1809ms, freq=415Hz, sample=67, buffer_id=02:43
    db 5,0,169,0,36,100,19,10,65,0,36,19  ; n766 t=48.654s dur=169ms, freq=65Hz, sample=36, buffer_id=13:24
    db 108,0,100,0,65,124,14,11,55,1,65,14  ; n767 t=48.658s dur=100ms, freq=311Hz, sample=65, buffer_id=0E:41
    db 5,0,100,0,61,115,13,3,38,1,61,2  ; n768 t=48.767s dur=100ms, freq=294Hz, sample=61, buffer_id=02:3D
    db 19,0,100,0,60,110,4,7,38,1,60,4  ; n769 t=48.772s dur=100ms, freq=294Hz, sample=60, buffer_id=04:3C
    db 90,0,100,0,60,124,14,12,38,1,60,14  ; n770 t=48.790s dur=100ms, freq=294Hz, sample=60, buffer_id=0E:3C
    db 0,0,150,0,73,110,16,0,110,2,73,16  ; n771 t=48.880s dur=150ms, freq=622Hz, sample=73, buffer_id=10:49
    db 19,0,150,0,73,110,16,1,11,2,73,16  ; n772 t=48.880s dur=150ms, freq=523Hz, sample=73, buffer_id=10:49
    db 5,0,249,3,60,115,13,4,6,1,60,2  ; n773 t=48.899s dur=1017ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 19,0,249,3,60,110,4,13,6,1,60,4  ; n774 t=48.904s dur=1017ms, freq=262Hz, sample=60, buffer_id=04:3C
    db 156,0,249,3,60,124,14,12,6,1,60,14  ; n775 t=48.922s dur=1017ms, freq=262Hz, sample=60, buffer_id=0E:3C [TRUNCATE prev:ch12 @48790.4ms -> 48922.3ms]
    db 28,0,169,0,36,120,2,3,65,0,36,2  ; n776 t=49.078s dur=169ms, freq=65Hz, sample=36, buffer_id=02:24
    db 0,0,100,0,73,110,16,2,11,2,73,16  ; n777 t=49.106s dur=100ms, freq=523Hz, sample=73, buffer_id=10:49
    db 0,0,100,0,65,110,16,5,159,1,65,16  ; n778 t=49.106s dur=100ms, freq=415Hz, sample=65, buffer_id=10:41
    db 5,0,169,0,36,100,19,6,65,0,36,19  ; n779 t=49.106s dur=169ms, freq=65Hz, sample=36, buffer_id=13:24
    db 56,0,100,0,58,100,22,7,208,0,58,22  ; n780 t=49.111s dur=100ms, freq=208Hz, sample=58, buffer_id=16:3A
    db 14,0,100,0,58,100,22,10,6,1,58,22  ; n781 t=49.167s dur=100ms, freq=262Hz, sample=58, buffer_id=16:3A
    db 0,0,100,0,73,110,16,11,110,2,73,16  ; n782 t=49.181s dur=100ms, freq=622Hz, sample=73, buffer_id=10:49
    db 42,0,100,0,73,110,16,0,11,2,73,16  ; n783 t=49.181s dur=100ms, freq=523Hz, sample=73, buffer_id=10:49 [TRUNCATE prev:ch0 @48879.9ms -> 49181.5ms]
    db 33,0,100,0,58,100,22,7,55,1,58,22  ; n784 t=49.224s dur=100ms, freq=311Hz, sample=58, buffer_id=16:3A [TRUNCATE prev:ch7 @49110.8ms -> 49223.9ms]
    db 24,0,100,0,77,110,16,1,63,3,77,16  ; n785 t=49.257s dur=100ms, freq=831Hz, sample=77, buffer_id=10:4D
    db 52,0,100,0,70,100,22,8,159,1,70,22  ; n786 t=49.280s dur=100ms, freq=415Hz, sample=70, buffer_id=16:46 [TRUNCATE prev:ch8 @48644.4ms -> 49280.4ms]
    db 0,0,150,0,84,110,16,9,23,4,84,16  ; n787 t=49.332s dur=150ms, freq=1047Hz, sample=84, buffer_id=10:54 [TRUNCATE prev:ch9 @48644.4ms -> 49332.2ms]
    db 5,0,150,0,77,110,16,4,63,3,77,16  ; n788 t=49.332s dur=150ms, freq=831Hz, sample=77, buffer_id=10:4D [TRUNCATE prev:ch4 @48898.8ms -> 49332.2ms]
    db 57,0,100,0,70,100,22,13,11,2,70,22  ; n789 t=49.337s dur=100ms, freq=523Hz, sample=70, buffer_id=16:46 [TRUNCATE prev:ch13 @48903.5ms -> 49336.9ms]
    db 137,0,100,0,75,100,22,12,110,2,75,22  ; n790 t=49.394s dur=100ms, freq=622Hz, sample=75, buffer_id=16:4B [TRUNCATE prev:ch12 @48922.3ms -> 49393.5ms]
    db 28,0,169,0,36,120,2,0,65,0,36,2  ; n791 t=49.530s dur=169ms, freq=65Hz, sample=36, buffer_id=02:24
    db 0,0,100,0,73,110,16,1,110,2,73,16  ; n792 t=49.558s dur=100ms, freq=622Hz, sample=73, buffer_id=10:49
    db 75,0,169,0,36,100,19,2,65,0,36,19  ; n793 t=49.558s dur=169ms, freq=65Hz, sample=36, buffer_id=13:24
    db 0,0,100,0,77,110,16,3,63,3,77,16  ; n794 t=49.634s dur=100ms, freq=831Hz, sample=77, buffer_id=10:4D
    db 75,0,100,0,73,110,16,5,110,2,73,16  ; n795 t=49.634s dur=100ms, freq=622Hz, sample=73, buffer_id=10:49
    db 0,0,100,0,84,110,16,4,23,4,84,16  ; n796 t=49.709s dur=100ms, freq=1047Hz, sample=84, buffer_id=10:54
    db 75,0,100,0,77,110,16,6,63,3,77,16  ; n797 t=49.709s dur=100ms, freq=831Hz, sample=77, buffer_id=10:4D
    db 0,0,15,2,89,110,16,7,221,4,89,16  ; n798 t=49.785s dur=527ms, freq=1245Hz, sample=89, buffer_id=10:59
    db 198,0,15,2,84,110,16,8,23,4,84,16  ; n799 t=49.785s dur=527ms, freq=1047Hz, sample=84, buffer_id=10:54
    db 9,0,169,0,36,120,2,1,65,0,36,2  ; n800 t=49.982s dur=169ms, freq=65Hz, sample=36, buffer_id=02:24
    db 5,0,113,0,60,115,13,0,6,1,60,2  ; n801 t=49.992s dur=113ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 14,0,113,0,60,110,4,2,6,1,60,4  ; n802 t=49.996s dur=113ms, freq=262Hz, sample=60, buffer_id=04:3C
    db 5,0,169,0,36,100,19,3,65,0,36,19  ; n803 t=50.011s dur=169ms, freq=65Hz, sample=36, buffer_id=13:24
    db 74,1,113,0,60,124,14,4,6,1,60,14  ; n804 t=50.015s dur=113ms, freq=262Hz, sample=60, buffer_id=0E:3C
    db 5,0,100,0,60,115,13,2,6,1,60,2  ; n805 t=50.345s dur=100ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 19,0,100,0,65,110,4,0,55,1,65,4  ; n806 t=50.350s dur=100ms, freq=311Hz, sample=65, buffer_id=04:41
    db 66,0,100,0,65,124,14,1,55,1,65,14  ; n807 t=50.369s dur=100ms, freq=311Hz, sample=65, buffer_id=0E:41
    db 9,0,169,0,36,120,2,3,65,0,36,2  ; n808 t=50.435s dur=169ms, freq=65Hz, sample=36, buffer_id=02:24
    db 5,0,100,0,59,115,13,4,247,0,59,2  ; n809 t=50.444s dur=100ms, freq=247Hz, sample=59, buffer_id=02:3B
    db 5,0,100,0,60,110,4,5,38,1,60,4  ; n810 t=50.449s dur=100ms, freq=294Hz, sample=60, buffer_id=04:3C
    db 0,0,100,0,73,120,7,6,75,2,73,2  ; n811 t=50.453s dur=100ms, freq=587Hz, sample=73, buffer_id=02:49
    db 9,0,100,0,71,120,9,9,238,1,71,2  ; n812 t=50.453s dur=100ms, freq=494Hz, sample=71, buffer_id=02:47
    db 0,0,100,0,84,110,16,10,151,4,84,16  ; n813 t=50.463s dur=100ms, freq=1175Hz, sample=84, buffer_id=10:54
    db 5,0,169,0,36,100,19,11,65,0,36,19  ; n814 t=50.463s dur=169ms, freq=65Hz, sample=36, buffer_id=13:24
    db 222,0,100,0,60,124,14,12,38,1,60,14  ; n815 t=50.468s dur=100ms, freq=294Hz, sample=60, buffer_id=0E:3C
    db 5,0,100,0,56,115,13,0,196,0,56,2  ; n816 t=50.689s dur=100ms, freq=196Hz, sample=56, buffer_id=02:38
    db 5,0,100,0,55,110,4,1,196,0,55,4  ; n817 t=50.694s dur=100ms, freq=196Hz, sample=55, buffer_id=04:37
    db 0,0,100,0,67,120,7,2,136,1,67,2  ; n818 t=50.699s dur=100ms, freq=392Hz, sample=67, buffer_id=02:43
    db 9,0,100,0,61,120,9,7,38,1,61,2  ; n819 t=50.699s dur=100ms, freq=294Hz, sample=61, buffer_id=02:3D
    db 5,0,100,0,77,110,16,8,16,3,77,16  ; n820 t=50.708s dur=100ms, freq=784Hz, sample=77, buffer_id=10:4D
    db 80,0,100,0,55,124,14,13,196,0,55,14  ; n821 t=50.713s dur=100ms, freq=196Hz, sample=55, buffer_id=0E:37
    db 5,0,100,0,53,115,13,4,185,0,53,2  ; n822 t=50.793s dur=100ms, freq=185Hz, sample=53, buffer_id=02:35
    db 5,0,100,0,55,110,4,5,185,0,55,4  ; n823 t=50.797s dur=100ms, freq=185Hz, sample=55, buffer_id=04:37
    db 0,0,100,0,66,120,7,6,114,1,66,2  ; n824 t=50.802s dur=100ms, freq=370Hz, sample=66, buffer_id=02:42
    db 9,0,100,0,61,120,9,9,38,1,61,2  ; n825 t=50.802s dur=100ms, freq=294Hz, sample=61, buffer_id=02:3D
    db 5,0,100,0,77,110,16,3,228,2,77,16  ; n826 t=50.812s dur=100ms, freq=740Hz, sample=77, buffer_id=10:4D
    db 71,0,100,0,55,124,14,10,185,0,55,14  ; n827 t=50.816s dur=100ms, freq=185Hz, sample=55, buffer_id=0E:37
    db 9,0,169,0,36,120,2,11,65,0,36,2  ; n828 t=50.887s dur=169ms, freq=65Hz, sample=36, buffer_id=02:24
    db 5,0,100,0,56,115,13,12,196,0,56,2  ; n829 t=50.896s dur=100ms, freq=196Hz, sample=56, buffer_id=02:38
    db 5,0,100,0,55,110,4,1,196,0,55,4  ; n830 t=50.901s dur=100ms, freq=196Hz, sample=55, buffer_id=04:37 [TRUNCATE prev:ch1 @50693.8ms -> 50901.1ms]
    db 0,0,100,0,67,120,7,2,136,1,67,2  ; n831 t=50.906s dur=100ms, freq=392Hz, sample=67, buffer_id=02:43 [TRUNCATE prev:ch2 @50698.5ms -> 50905.8ms]
    db 9,0,100,0,61,120,9,7,38,1,61,2  ; n832 t=50.906s dur=100ms, freq=294Hz, sample=61, buffer_id=02:3D [TRUNCATE prev:ch7 @50698.5ms -> 50905.8ms]
    db 0,0,100,0,77,110,16,8,16,3,77,16  ; n833 t=50.915s dur=100ms, freq=784Hz, sample=77, buffer_id=10:4D [TRUNCATE prev:ch8 @50707.9ms -> 50915.2ms]
    db 5,0,169,0,36,100,19,0,65,0,36,19  ; n834 t=50.915s dur=169ms, freq=65Hz, sample=36, buffer_id=13:24 [TRUNCATE prev:ch0 @50689.1ms -> 50915.2ms]
    db 203,0,100,0,55,124,14,13,196,0,55,14  ; n835 t=50.920s dur=100ms, freq=196Hz, sample=55, buffer_id=0E:37 [TRUNCATE prev:ch13 @50712.6ms -> 50919.9ms]
    db 5,0,100,0,59,115,13,3,247,0,59,2  ; n836 t=51.123s dur=100ms, freq=247Hz, sample=59, buffer_id=02:3B
    db 5,0,100,0,60,110,4,4,38,1,60,4  ; n837 t=51.127s dur=100ms, freq=294Hz, sample=60, buffer_id=04:3C
    db 0,0,100,0,73,120,7,5,75,2,73,2  ; n838 t=51.132s dur=100ms, freq=587Hz, sample=73, buffer_id=02:49
    db 9,0,100,0,71,120,9,6,238,1,71,2  ; n839 t=51.132s dur=100ms, freq=494Hz, sample=71, buffer_id=02:47
    db 5,0,100,0,84,110,16,9,151,4,84,16  ; n840 t=51.141s dur=100ms, freq=1175Hz, sample=84, buffer_id=10:54
    db 193,0,100,0,60,124,14,10,38,1,60,14  ; n841 t=51.146s dur=100ms, freq=294Hz, sample=60, buffer_id=0E:3C
    db 28,0,169,0,36,120,2,0,65,0,36,2  ; n842 t=51.339s dur=169ms, freq=65Hz, sample=36, buffer_id=02:24
    db 0,0,100,0,56,115,13,1,196,0,56,2  ; n843 t=51.367s dur=100ms, freq=196Hz, sample=56, buffer_id=02:38
    db 5,0,169,0,36,100,19,2,65,0,36,19  ; n844 t=51.367s dur=169ms, freq=65Hz, sample=36, buffer_id=13:24
    db 5,0,100,0,55,110,4,7,196,0,55,4  ; n845 t=51.372s dur=100ms, freq=196Hz, sample=55, buffer_id=04:37
    db 0,0,100,0,67,120,7,8,136,1,67,2  ; n846 t=51.377s dur=100ms, freq=392Hz, sample=67, buffer_id=02:43
    db 9,0,100,0,61,120,9,11,38,1,61,2  ; n847 t=51.377s dur=100ms, freq=294Hz, sample=61, buffer_id=02:3D
    db 5,0,100,0,77,110,16,12,16,3,77,16  ; n848 t=51.386s dur=100ms, freq=784Hz, sample=77, buffer_id=10:4D
    db 80,0,100,0,55,124,14,13,196,0,55,14  ; n849 t=51.391s dur=100ms, freq=196Hz, sample=55, buffer_id=0E:37 [TRUNCATE prev:ch13 @50919.9ms -> 51391.1ms]
    db 5,0,100,0,53,115,13,3,185,0,53,2  ; n850 t=51.471s dur=100ms, freq=185Hz, sample=53, buffer_id=02:35
    db 5,0,100,0,55,110,4,4,185,0,55,4  ; n851 t=51.476s dur=100ms, freq=185Hz, sample=55, buffer_id=04:37
    db 0,0,100,0,66,120,7,5,114,1,66,2  ; n852 t=51.481s dur=100ms, freq=370Hz, sample=66, buffer_id=02:42
    db 9,0,100,0,61,120,9,6,38,1,61,2  ; n853 t=51.481s dur=100ms, freq=294Hz, sample=61, buffer_id=02:3D
    db 5,0,100,0,77,110,16,9,228,2,77,16  ; n854 t=51.490s dur=100ms, freq=740Hz, sample=77, buffer_id=10:4D
    db 80,0,100,0,55,124,14,10,185,0,55,14  ; n855 t=51.495s dur=100ms, freq=185Hz, sample=55, buffer_id=0E:37
    db 5,0,100,0,56,115,13,1,196,0,56,2  ; n856 t=51.575s dur=100ms, freq=196Hz, sample=56, buffer_id=02:38 [TRUNCATE prev:ch1 @51367.5ms -> 51574.8ms]
    db 5,0,100,0,55,110,4,7,196,0,55,4  ; n857 t=51.580s dur=100ms, freq=196Hz, sample=55, buffer_id=04:37 [TRUNCATE prev:ch7 @51372.2ms -> 51579.5ms]
    db 0,0,100,0,67,120,7,8,136,1,67,2  ; n858 t=51.584s dur=100ms, freq=392Hz, sample=67, buffer_id=02:43 [TRUNCATE prev:ch8 @51376.9ms -> 51584.2ms]
    db 9,0,100,0,61,120,9,11,38,1,61,2  ; n859 t=51.584s dur=100ms, freq=294Hz, sample=61, buffer_id=02:3D [TRUNCATE prev:ch11 @51376.9ms -> 51584.2ms]
    db 5,0,100,0,77,110,16,12,16,3,77,16  ; n860 t=51.594s dur=100ms, freq=784Hz, sample=77, buffer_id=10:4D [TRUNCATE prev:ch12 @51386.3ms -> 51593.6ms]
    db 193,0,100,0,55,124,14,13,196,0,55,14  ; n861 t=51.598s dur=100ms, freq=196Hz, sample=55, buffer_id=0E:37 [TRUNCATE prev:ch13 @51391.1ms -> 51598.4ms]
    db 9,0,169,0,36,120,2,2,65,0,36,2  ; n862 t=51.791s dur=169ms, freq=65Hz, sample=36, buffer_id=02:24
    db 5,0,100,0,59,115,13,0,247,0,59,2  ; n863 t=51.801s dur=100ms, freq=247Hz, sample=59, buffer_id=02:3B
    db 5,0,100,0,60,110,4,3,38,1,60,4  ; n864 t=51.806s dur=100ms, freq=294Hz, sample=60, buffer_id=04:3C
    db 0,0,100,0,73,120,7,4,75,2,73,2  ; n865 t=51.810s dur=100ms, freq=587Hz, sample=73, buffer_id=02:49
    db 9,0,100,0,71,120,9,5,238,1,71,2  ; n866 t=51.810s dur=100ms, freq=494Hz, sample=71, buffer_id=02:47
    db 0,0,100,0,84,110,16,6,151,4,84,16  ; n867 t=51.820s dur=100ms, freq=1175Hz, sample=84, buffer_id=10:54
    db 5,0,169,0,36,100,19,9,65,0,36,19  ; n868 t=51.820s dur=169ms, freq=65Hz, sample=36, buffer_id=13:24
    db 221,0,100,0,60,124,14,10,38,1,60,14  ; n869 t=51.825s dur=100ms, freq=294Hz, sample=60, buffer_id=0E:3C
    db 5,0,100,0,56,115,13,7,220,0,56,2  ; n870 t=52.046s dur=100ms, freq=220Hz, sample=56, buffer_id=02:38
    db 5,0,100,0,60,110,4,1,6,1,60,4  ; n871 t=52.051s dur=100ms, freq=262Hz, sample=60, buffer_id=04:3C
    db 0,0,100,0,72,120,7,8,11,2,72,2  ; n872 t=52.055s dur=100ms, freq=523Hz, sample=72, buffer_id=02:48
    db 9,0,100,0,67,120,9,11,184,1,67,2  ; n873 t=52.055s dur=100ms, freq=440Hz, sample=67, buffer_id=02:43
    db 5,0,100,0,84,110,16,12,23,4,84,16  ; n874 t=52.065s dur=100ms, freq=1047Hz, sample=84, buffer_id=10:54
    db 80,0,100,0,60,124,14,13,6,1,60,14  ; n875 t=52.069s dur=100ms, freq=262Hz, sample=60, buffer_id=0E:3C
    db 5,0,100,0,56,115,13,0,208,0,56,2  ; n876 t=52.150s dur=100ms, freq=208Hz, sample=56, buffer_id=02:38
    db 5,0,100,0,60,110,4,4,247,0,60,4  ; n877 t=52.154s dur=100ms, freq=247Hz, sample=60, buffer_id=04:3C
    db 0,0,100,0,71,120,7,3,238,1,71,2  ; n878 t=52.159s dur=100ms, freq=494Hz, sample=71, buffer_id=02:47
    db 9,0,100,0,67,120,9,5,159,1,67,2  ; n879 t=52.159s dur=100ms, freq=415Hz, sample=67, buffer_id=02:43
    db 5,0,100,0,84,110,16,2,220,3,84,16  ; n880 t=52.168s dur=100ms, freq=988Hz, sample=84, buffer_id=10:54
    db 71,0,100,0,60,124,14,6,247,0,60,14  ; n881 t=52.173s dur=100ms, freq=247Hz, sample=60, buffer_id=0E:3C
    db 9,0,169,0,36,120,2,9,65,0,36,2  ; n882 t=52.244s dur=169ms, freq=65Hz, sample=36, buffer_id=02:24
    db 5,0,241,0,56,115,13,10,220,0,56,2  ; n883 t=52.253s dur=241ms, freq=220Hz, sample=56, buffer_id=02:38
    db 5,0,219,4,60,110,4,1,6,1,60,4  ; n884 t=52.258s dur=1243ms, freq=262Hz, sample=60, buffer_id=04:3C [TRUNCATE prev:ch1 @52050.6ms -> 52257.9ms]
    db 0,0,219,4,72,120,7,8,11,2,72,2  ; n885 t=52.263s dur=1243ms, freq=523Hz, sample=72, buffer_id=02:48 [TRUNCATE prev:ch8 @52055.4ms -> 52262.7ms]
    db 9,0,219,4,67,120,9,11,184,1,67,2  ; n886 t=52.263s dur=1243ms, freq=440Hz, sample=67, buffer_id=02:43 [TRUNCATE prev:ch11 @52055.4ms -> 52262.7ms]
    db 0,0,219,4,84,110,16,12,23,4,84,16  ; n887 t=52.272s dur=1243ms, freq=1047Hz, sample=84, buffer_id=10:54 [TRUNCATE prev:ch12 @52064.8ms -> 52272.1ms]
    db 5,0,169,0,36,100,19,7,65,0,36,19  ; n888 t=52.272s dur=169ms, freq=65Hz, sample=36, buffer_id=13:24 [TRUNCATE prev:ch7 @52045.9ms -> 52272.1ms]
    db 163,1,219,4,60,124,14,13,6,1,60,14  ; n889 t=52.277s dur=1243ms, freq=262Hz, sample=60, buffer_id=0E:3C [TRUNCATE prev:ch13 @52069.5ms -> 52276.8ms]
    db 28,0,169,0,36,120,2,0,65,0,36,2  ; n890 t=52.696s dur=169ms, freq=65Hz, sample=36, buffer_id=02:24
    db 168,1,169,0,36,100,19,2,65,0,36,19  ; n891 t=52.724s dur=169ms, freq=65Hz, sample=36, buffer_id=13:24
    db 28,0,169,0,36,120,2,2,65,0,36,2  ; n892 t=53.148s dur=169ms, freq=65Hz, sample=36, buffer_id=02:24
    db 168,1,169,0,36,100,19,0,65,0,36,19  ; n893 t=53.177s dur=169ms, freq=65Hz, sample=36, buffer_id=13:24
    db 28,0,169,0,36,120,2,0,65,0,36,2  ; n894 t=53.601s dur=169ms, freq=65Hz, sample=36, buffer_id=02:24
    db 5,0,169,0,36,100,19,2,65,0,36,19  ; n895 t=53.629s dur=169ms, freq=65Hz, sample=36, buffer_id=13:24
    db 97,1,113,0,62,124,5,3,74,1,62,5  ; n896 t=53.634s dur=113ms, freq=330Hz, sample=62, buffer_id=05:3E
    db 66,0,100,0,67,124,5,0,136,1,67,5  ; n897 t=53.987s dur=100ms, freq=392Hz, sample=67, buffer_id=05:43
    db 9,0,169,0,36,120,2,1,65,0,36,2  ; n898 t=54.053s dur=169ms, freq=65Hz, sample=36, buffer_id=02:24
    db 24,0,169,0,48,115,13,2,131,0,48,2  ; n899 t=54.062s dur=169ms, freq=131Hz, sample=48, buffer_id=02:30
    db 0,0,106,4,36,120,1,3,65,0,36,1  ; n900 t=54.086s dur=1130ms, freq=65Hz, sample=36, buffer_id=01:24
    db 0,0,219,4,67,124,5,4,93,1,67,5  ; n901 t=54.086s dur=1243ms, freq=349Hz, sample=67, buffer_id=05:43
    db 0,0,106,4,55,124,14,5,175,0,55,14  ; n902 t=54.086s dur=1130ms, freq=175Hz, sample=55, buffer_id=0E:37
    db 0,0,106,4,60,124,14,7,233,0,60,14  ; n903 t=54.086s dur=1130ms, freq=233Hz, sample=60, buffer_id=0E:3C
    db 163,1,106,4,60,124,14,8,38,1,60,14  ; n904 t=54.086s dur=1130ms, freq=294Hz, sample=60, buffer_id=0E:3C
    db 9,0,169,0,36,120,2,0,65,0,36,2  ; n905 t=54.505s dur=169ms, freq=65Hz, sample=36, buffer_id=02:24
    db 187,1,169,0,48,115,13,1,131,0,48,2  ; n906 t=54.515s dur=169ms, freq=131Hz, sample=48, buffer_id=02:30
    db 9,0,169,0,36,120,2,1,65,0,36,2  ; n907 t=54.958s dur=169ms, freq=65Hz, sample=36, buffer_id=02:24
    db 187,1,169,0,48,115,13,0,131,0,48,2  ; n908 t=54.967s dur=169ms, freq=131Hz, sample=48, buffer_id=02:30
    db 9,0,169,0,36,120,2,0,65,0,36,2  ; n909 t=55.410s dur=169ms, freq=65Hz, sample=36, buffer_id=02:24
    db 24,0,169,0,48,115,13,1,131,0,48,2  ; n910 t=55.419s dur=169ms, freq=131Hz, sample=48, buffer_id=02:30
    db 0,0,113,0,36,120,1,2,65,0,36,1  ; n911 t=55.443s dur=113ms, freq=65Hz, sample=36, buffer_id=01:24
    db 0,0,113,0,62,124,5,3,38,1,62,5  ; n912 t=55.443s dur=113ms, freq=294Hz, sample=62, buffer_id=05:3E
    db 0,0,113,0,55,124,14,6,175,0,55,14  ; n913 t=55.443s dur=113ms, freq=175Hz, sample=55, buffer_id=0E:37
    db 0,0,113,0,60,124,14,5,233,0,60,14  ; n914 t=55.443s dur=113ms, freq=233Hz, sample=60, buffer_id=0E:3C
    db 97,1,113,0,60,124,14,9,38,1,60,14  ; n915 t=55.443s dur=113ms, freq=294Hz, sample=60, buffer_id=0E:3C
    db 66,0,100,0,67,124,5,0,93,1,67,5  ; n916 t=55.796s dur=100ms, freq=349Hz, sample=67, buffer_id=05:43
    db 9,0,169,0,34,120,2,1,55,0,34,2  ; n917 t=55.862s dur=169ms, freq=55Hz, sample=34, buffer_id=02:22
    db 24,0,169,0,45,115,13,2,110,0,45,2  ; n918 t=55.871s dur=169ms, freq=110Hz, sample=45, buffer_id=02:2D
    db 0,0,106,4,36,120,1,3,65,0,36,1  ; n919 t=55.895s dur=1130ms, freq=65Hz, sample=36, buffer_id=01:24
    db 0,0,100,0,62,124,5,4,74,1,62,5  ; n920 t=55.895s dur=100ms, freq=330Hz, sample=62, buffer_id=05:3E
    db 0,0,106,4,55,124,14,5,196,0,55,14  ; n921 t=55.895s dur=1130ms, freq=196Hz, sample=55, buffer_id=0E:37
    db 0,0,106,4,60,124,14,6,6,1,60,14  ; n922 t=55.895s dur=1130ms, freq=262Hz, sample=60, buffer_id=0E:3C
    db 132,0,106,4,65,124,14,7,74,1,65,14  ; n923 t=55.895s dur=1130ms, freq=330Hz, sample=65, buffer_id=0E:41
    db 132,0,100,0,67,124,5,8,136,1,67,5  ; n924 t=56.027s dur=100ms, freq=392Hz, sample=67, buffer_id=05:43
    db 155,0,249,3,77,124,5,0,147,2,77,5  ; n925 t=56.159s dur=1017ms, freq=659Hz, sample=77, buffer_id=05:4D
    db 9,0,169,0,34,120,2,2,55,0,34,2  ; n926 t=56.314s dur=169ms, freq=55Hz, sample=34, buffer_id=02:22
    db 187,1,169,0,45,115,13,1,110,0,45,2  ; n927 t=56.324s dur=169ms, freq=110Hz, sample=45, buffer_id=02:2D
    db 10,0,169,0,34,120,2,1,55,0,34,2  ; n928 t=56.767s dur=169ms, freq=55Hz, sample=34, buffer_id=02:22
    db 187,1,169,0,45,115,13,2,110,0,45,2  ; n929 t=56.776s dur=169ms, freq=110Hz, sample=45, buffer_id=02:2D
    db 10,0,169,0,34,120,2,2,55,0,34,2  ; n930 t=57.219s dur=169ms, freq=55Hz, sample=34, buffer_id=02:22
    db 23,0,169,0,45,115,13,1,110,0,45,2  ; n931 t=57.228s dur=169ms, freq=110Hz, sample=45, buffer_id=02:2D
    db 0,0,113,0,36,120,1,4,65,0,36,1  ; n932 t=57.252s dur=113ms, freq=65Hz, sample=36, buffer_id=01:24
    db 0,0,113,0,62,124,5,3,74,1,62,5  ; n933 t=57.252s dur=113ms, freq=330Hz, sample=62, buffer_id=05:3E
    db 0,0,113,0,50,124,14,5,165,0,50,14  ; n934 t=57.252s dur=113ms, freq=165Hz, sample=50, buffer_id=0E:32
    db 0,0,113,0,55,124,14,6,196,0,55,14  ; n935 t=57.252s dur=113ms, freq=196Hz, sample=55, buffer_id=0E:37
    db 97,1,113,0,60,124,14,7,6,1,60,14  ; n936 t=57.252s dur=113ms, freq=262Hz, sample=60, buffer_id=0E:3C
    db 66,0,100,0,67,124,5,0,136,1,67,5  ; n937 t=57.605s dur=100ms, freq=392Hz, sample=67, buffer_id=05:43
    db 9,0,169,0,36,120,2,1,65,0,36,2  ; n938 t=57.671s dur=169ms, freq=65Hz, sample=36, buffer_id=02:24
    db 24,0,169,0,48,115,13,2,131,0,48,2  ; n939 t=57.681s dur=169ms, freq=131Hz, sample=48, buffer_id=02:30
    db 0,0,130,3,31,120,1,3,55,0,31,1  ; n940 t=57.704s dur=898ms, freq=55Hz, sample=31, buffer_id=01:1F
    db 0,0,219,4,67,124,5,4,93,1,67,5  ; n941 t=57.704s dur=1243ms, freq=349Hz, sample=67, buffer_id=05:43
    db 0,0,106,4,60,124,14,5,233,0,60,14  ; n942 t=57.704s dur=1130ms, freq=233Hz, sample=60, buffer_id=0E:3C
    db 0,0,106,4,60,124,14,6,38,1,60,14  ; n943 t=57.704s dur=1130ms, freq=294Hz, sample=60, buffer_id=0E:3C
    db 163,1,106,4,65,124,14,7,93,1,65,14  ; n944 t=57.704s dur=1130ms, freq=349Hz, sample=65, buffer_id=0E:41
    db 9,0,169,0,36,120,2,0,65,0,36,2  ; n945 t=58.123s dur=169ms, freq=65Hz, sample=36, buffer_id=02:24
    db 187,1,169,0,48,115,13,1,131,0,48,2  ; n946 t=58.133s dur=169ms, freq=131Hz, sample=48, buffer_id=02:30
    db 9,0,169,0,36,120,2,1,65,0,36,2  ; n947 t=58.576s dur=169ms, freq=65Hz, sample=36, buffer_id=02:24
    db 187,1,169,0,48,115,13,0,131,0,48,2  ; n948 t=58.585s dur=169ms, freq=131Hz, sample=48, buffer_id=02:30
    db 9,0,169,0,36,120,2,0,65,0,36,2  ; n949 t=59.028s dur=169ms, freq=65Hz, sample=36, buffer_id=02:24
    db 23,0,169,0,48,115,13,1,131,0,48,2  ; n950 t=59.038s dur=169ms, freq=131Hz, sample=48, buffer_id=02:30
    db 0,0,113,0,31,120,1,2,55,0,31,1  ; n951 t=59.061s dur=113ms, freq=55Hz, sample=31, buffer_id=01:1F
    db 0,0,113,0,62,124,5,3,38,1,62,5  ; n952 t=59.061s dur=113ms, freq=294Hz, sample=62, buffer_id=05:3E
    db 0,0,113,0,55,124,14,5,175,0,55,14  ; n953 t=59.061s dur=113ms, freq=175Hz, sample=55, buffer_id=0E:37
    db 0,0,113,0,60,124,14,7,233,0,60,14  ; n954 t=59.061s dur=113ms, freq=233Hz, sample=60, buffer_id=0E:3C
    db 97,1,113,0,60,124,14,8,38,1,60,14  ; n955 t=59.061s dur=113ms, freq=294Hz, sample=60, buffer_id=0E:3C
    db 66,0,100,0,67,124,5,0,93,1,67,5  ; n956 t=59.414s dur=100ms, freq=349Hz, sample=67, buffer_id=05:43
    db 10,0,169,0,36,120,2,1,65,0,36,2  ; n957 t=59.480s dur=169ms, freq=65Hz, sample=36, buffer_id=02:24
    db 23,0,169,0,48,115,13,2,131,0,48,2  ; n958 t=59.490s dur=169ms, freq=131Hz, sample=48, buffer_id=02:30
    db 0,0,106,4,36,120,1,3,65,0,36,1  ; n959 t=59.513s dur=1130ms, freq=65Hz, sample=36, buffer_id=01:24
    db 0,0,100,0,62,124,5,4,55,1,62,5  ; n960 t=59.513s dur=100ms, freq=311Hz, sample=62, buffer_id=05:3E
    db 0,0,106,4,55,124,14,6,196,0,55,14  ; n961 t=59.513s dur=1130ms, freq=196Hz, sample=55, buffer_id=0E:37
    db 0,0,106,4,55,124,14,7,208,0,55,14  ; n962 t=59.513s dur=1130ms, freq=208Hz, sample=55, buffer_id=0E:37
    db 132,0,106,4,65,124,14,5,55,1,65,14  ; n963 t=59.513s dur=1130ms, freq=311Hz, sample=65, buffer_id=0E:41
    db 132,0,100,0,62,124,5,8,38,1,62,5  ; n964 t=59.645s dur=100ms, freq=294Hz, sample=62, buffer_id=05:3E
    db 155,0,249,3,62,124,5,0,6,1,62,5  ; n965 t=59.777s dur=1017ms, freq=262Hz, sample=62, buffer_id=05:3E
    db 10,0,169,0,36,120,2,2,65,0,36,2  ; n966 t=59.933s dur=169ms, freq=65Hz, sample=36, buffer_id=02:24
    db 187,1,169,0,48,115,13,1,131,0,48,2  ; n967 t=59.942s dur=169ms, freq=131Hz, sample=48, buffer_id=02:30
    db 9,0,169,0,36,120,2,1,65,0,36,2  ; n968 t=60.385s dur=169ms, freq=65Hz, sample=36, buffer_id=02:24
    db 187,1,169,0,48,115,13,2,131,0,48,2  ; n969 t=60.394s dur=169ms, freq=131Hz, sample=48, buffer_id=02:30
    db 9,0,169,0,36,120,2,2,65,0,36,2  ; n970 t=60.837s dur=169ms, freq=65Hz, sample=36, buffer_id=02:24
    db 24,0,169,0,48,115,13,1,131,0,48,2  ; n971 t=60.847s dur=169ms, freq=131Hz, sample=48, buffer_id=02:30
    db 0,0,113,0,36,120,1,4,65,0,36,1  ; n972 t=60.870s dur=113ms, freq=65Hz, sample=36, buffer_id=01:24
    db 0,0,113,0,62,124,5,3,74,1,62,5  ; n973 t=60.870s dur=113ms, freq=330Hz, sample=62, buffer_id=05:3E
    db 0,0,113,0,55,124,14,5,196,0,55,14  ; n974 t=60.870s dur=113ms, freq=196Hz, sample=55, buffer_id=0E:37
    db 0,0,113,0,60,124,14,6,6,1,60,14  ; n975 t=60.870s dur=113ms, freq=262Hz, sample=60, buffer_id=0E:3C
    db 97,1,113,0,65,124,14,7,74,1,65,14  ; n976 t=60.870s dur=113ms, freq=330Hz, sample=65, buffer_id=0E:41
    db 66,0,100,0,67,124,5,0,136,1,67,5  ; n977 t=61.224s dur=100ms, freq=392Hz, sample=67, buffer_id=05:43
    db 9,0,169,0,36,120,2,1,65,0,36,2  ; n978 t=61.289s dur=169ms, freq=65Hz, sample=36, buffer_id=02:24
    db 24,0,169,0,48,115,13,2,131,0,48,2  ; n979 t=61.299s dur=169ms, freq=131Hz, sample=48, buffer_id=02:30
    db 0,0,106,4,36,120,1,3,65,0,36,1  ; n980 t=61.322s dur=1130ms, freq=65Hz, sample=36, buffer_id=01:24
    db 0,0,219,4,67,124,5,4,93,1,67,5  ; n981 t=61.322s dur=1243ms, freq=349Hz, sample=67, buffer_id=05:43
    db 0,0,106,4,55,124,14,6,175,0,55,14  ; n982 t=61.322s dur=1130ms, freq=175Hz, sample=55, buffer_id=0E:37
    db 0,0,106,4,60,124,14,5,233,0,60,14  ; n983 t=61.322s dur=1130ms, freq=233Hz, sample=60, buffer_id=0E:3C
    db 163,1,106,4,60,124,14,7,38,1,60,14  ; n984 t=61.322s dur=1130ms, freq=294Hz, sample=60, buffer_id=0E:3C
    db 9,0,169,0,36,120,2,0,65,0,36,2  ; n985 t=61.742s dur=169ms, freq=65Hz, sample=36, buffer_id=02:24
    db 187,1,169,0,48,115,13,1,131,0,48,2  ; n986 t=61.751s dur=169ms, freq=131Hz, sample=48, buffer_id=02:30
    db 9,0,169,0,36,120,2,1,65,0,36,2  ; n987 t=62.194s dur=169ms, freq=65Hz, sample=36, buffer_id=02:24
    db 187,1,169,0,48,115,13,0,131,0,48,2  ; n988 t=62.203s dur=169ms, freq=131Hz, sample=48, buffer_id=02:30
    db 10,0,169,0,36,120,2,0,65,0,36,2  ; n989 t=62.646s dur=169ms, freq=65Hz, sample=36, buffer_id=02:24
    db 23,0,169,0,48,115,13,1,131,0,48,2  ; n990 t=62.656s dur=169ms, freq=131Hz, sample=48, buffer_id=02:30
    db 0,0,113,0,36,120,1,2,65,0,36,1  ; n991 t=62.679s dur=113ms, freq=65Hz, sample=36, buffer_id=01:24
    db 0,0,113,0,62,124,5,3,38,1,62,5  ; n992 t=62.679s dur=113ms, freq=294Hz, sample=62, buffer_id=05:3E
    db 0,0,113,0,55,124,14,5,175,0,55,14  ; n993 t=62.679s dur=113ms, freq=175Hz, sample=55, buffer_id=0E:37
    db 0,0,113,0,60,124,14,6,233,0,60,14  ; n994 t=62.679s dur=113ms, freq=233Hz, sample=60, buffer_id=0E:3C
    db 97,1,113,0,60,124,14,8,38,1,60,14  ; n995 t=62.679s dur=113ms, freq=294Hz, sample=60, buffer_id=0E:3C
    db 66,0,100,0,67,124,5,0,93,1,67,5  ; n996 t=63.033s dur=100ms, freq=349Hz, sample=67, buffer_id=05:43
    db 9,0,169,0,34,120,2,1,55,0,34,2  ; n997 t=63.099s dur=169ms, freq=55Hz, sample=34, buffer_id=02:22
    db 24,0,169,0,45,115,13,2,110,0,45,2  ; n998 t=63.108s dur=169ms, freq=110Hz, sample=45, buffer_id=02:2D
    db 0,0,106,4,36,120,1,3,65,0,36,1  ; n999 t=63.132s dur=1130ms, freq=65Hz, sample=36, buffer_id=01:24
    db 0,0,100,0,62,124,5,4,74,1,62,5  ; n1000 t=63.132s dur=100ms, freq=330Hz, sample=62, buffer_id=05:3E
    db 0,0,106,4,55,124,14,6,196,0,55,14  ; n1001 t=63.132s dur=1130ms, freq=196Hz, sample=55, buffer_id=0E:37
    db 0,0,106,4,60,124,14,5,6,1,60,14  ; n1002 t=63.132s dur=1130ms, freq=262Hz, sample=60, buffer_id=0E:3C
    db 132,0,106,4,65,124,14,7,74,1,65,14  ; n1003 t=63.132s dur=1130ms, freq=330Hz, sample=65, buffer_id=0E:41
    db 132,0,100,0,67,124,5,8,136,1,67,5  ; n1004 t=63.264s dur=100ms, freq=392Hz, sample=67, buffer_id=05:43
    db 155,0,249,3,77,124,5,0,147,2,77,5  ; n1005 t=63.395s dur=1017ms, freq=659Hz, sample=77, buffer_id=05:4D
    db 9,0,169,0,34,120,2,2,55,0,34,2  ; n1006 t=63.551s dur=169ms, freq=55Hz, sample=34, buffer_id=02:22
    db 226,0,169,0,45,115,13,1,110,0,45,2  ; n1007 t=63.560s dur=169ms, freq=110Hz, sample=45, buffer_id=02:2D
    db 217,0,131,0,72,120,11,4,11,2,72,2  ; n1008 t=63.786s dur=131ms, freq=523Hz, sample=72, buffer_id=02:48
    db 9,0,169,0,34,120,2,1,55,0,34,2  ; n1009 t=64.003s dur=169ms, freq=55Hz, sample=34, buffer_id=02:22
    db 0,0,131,0,72,120,11,2,11,2,72,2  ; n1010 t=64.013s dur=131ms, freq=523Hz, sample=72, buffer_id=02:48
    db 226,0,169,0,45,115,13,8,110,0,45,2  ; n1011 t=64.013s dur=169ms, freq=110Hz, sample=45, buffer_id=02:2D
    db 217,0,131,0,67,120,11,4,184,1,67,2  ; n1012 t=64.239s dur=131ms, freq=440Hz, sample=67, buffer_id=02:43
    db 9,0,169,0,34,120,2,2,55,0,34,2  ; n1013 t=64.456s dur=169ms, freq=55Hz, sample=34, buffer_id=02:22
    db 0,0,131,0,67,120,11,1,136,1,67,2  ; n1014 t=64.465s dur=131ms, freq=392Hz, sample=67, buffer_id=02:43
    db 24,0,169,0,45,115,13,3,110,0,45,2  ; n1015 t=64.465s dur=169ms, freq=110Hz, sample=45, buffer_id=02:2D
    db 0,0,113,0,36,120,1,5,65,0,36,1  ; n1016 t=64.489s dur=113ms, freq=65Hz, sample=36, buffer_id=01:24
    db 0,0,113,0,72,124,5,6,75,2,72,5  ; n1017 t=64.489s dur=113ms, freq=587Hz, sample=72, buffer_id=05:48
    db 0,0,113,0,60,124,14,7,6,1,60,14  ; n1018 t=64.489s dur=113ms, freq=262Hz, sample=60, buffer_id=0E:3C
    db 0,0,113,0,65,124,14,8,74,1,65,14  ; n1019 t=64.489s dur=113ms, freq=330Hz, sample=65, buffer_id=0E:41
    db 203,0,113,0,65,124,14,9,136,1,65,14  ; n1020 t=64.489s dur=113ms, freq=392Hz, sample=65, buffer_id=0E:41
    db 151,0,131,0,60,120,11,0,6,1,60,2  ; n1021 t=64.691s dur=131ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 66,0,100,0,77,124,5,1,147,2,77,5  ; n1022 t=64.842s dur=100ms, freq=659Hz, sample=77, buffer_id=05:4D
    db 9,0,153,0,29,120,2,2,49,0,29,2  ; n1023 t=64.908s dur=153ms, freq=49Hz, sample=29, buffer_id=02:1D
    db 0,0,131,0,56,120,11,3,196,0,56,2  ; n1024 t=64.917s dur=131ms, freq=196Hz, sample=56, buffer_id=02:38
    db 5,0,169,0,43,115,13,4,98,0,43,2  ; n1025 t=64.917s dur=169ms, freq=98Hz, sample=43, buffer_id=02:2B
    db 0,0,100,0,70,110,4,5,210,1,70,4  ; n1026 t=64.922s dur=100ms, freq=466Hz, sample=70, buffer_id=04:46
    db 19,0,100,0,65,110,4,6,93,1,65,4  ; n1027 t=64.922s dur=100ms, freq=349Hz, sample=65, buffer_id=04:41
    db 0,0,113,0,31,120,1,7,49,0,31,1  ; n1028 t=64.941s dur=113ms, freq=49Hz, sample=31, buffer_id=01:1F
    db 0,0,100,0,77,124,5,8,186,2,77,5  ; n1029 t=64.941s dur=100ms, freq=698Hz, sample=77, buffer_id=05:4D
    db 0,0,100,0,72,124,5,9,75,2,72,5  ; n1030 t=64.941s dur=100ms, freq=587Hz, sample=72, buffer_id=05:48
    db 0,0,100,0,67,124,5,10,184,1,67,5  ; n1031 t=64.941s dur=100ms, freq=440Hz, sample=67, buffer_id=05:43
    db 0,0,100,0,65,124,14,11,93,1,65,14  ; n1032 t=64.941s dur=100ms, freq=349Hz, sample=65, buffer_id=0E:41
    db 0,0,100,0,60,124,14,12,38,1,60,14  ; n1033 t=64.941s dur=100ms, freq=294Hz, sample=60, buffer_id=0E:3C
    db 203,0,100,0,55,124,14,13,220,0,55,14  ; n1034 t=64.941s dur=100ms, freq=220Hz, sample=55, buffer_id=0E:37
    db 42,0,131,0,60,120,11,1,6,1,60,2  ; n1035 t=65.143s dur=131ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 0,0,100,0,72,124,5,0,210,1,72,5  ; n1036 t=65.186s dur=100ms, freq=466Hz, sample=72, buffer_id=05:48
    db 104,0,100,0,60,124,14,12,233,0,60,14  ; n1037 t=65.186s dur=100ms, freq=233Hz, sample=60, buffer_id=0E:3C [TRUNCATE prev:ch12 @64940.7ms -> 65185.7ms]
    db 0,0,100,0,67,124,5,2,184,1,67,5  ; n1038 t=65.289s dur=100ms, freq=440Hz, sample=67, buffer_id=05:43
    db 71,0,100,0,55,124,14,3,220,0,55,14  ; n1039 t=65.289s dur=100ms, freq=220Hz, sample=55, buffer_id=0E:37
    db 10,0,169,0,36,120,2,4,65,0,36,2  ; n1040 t=65.360s dur=169ms, freq=65Hz, sample=36, buffer_id=02:24
    db 0,0,131,0,60,120,11,5,6,1,60,2  ; n1041 t=65.370s dur=131ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 23,0,169,0,48,115,13,6,131,0,48,2  ; n1042 t=65.370s dur=169ms, freq=131Hz, sample=48, buffer_id=02:30
    db 0,0,100,0,72,124,5,7,210,1,72,5  ; n1043 t=65.393s dur=100ms, freq=466Hz, sample=72, buffer_id=05:48
    db 203,0,100,0,60,124,14,8,233,0,60,14  ; n1044 t=65.393s dur=100ms, freq=233Hz, sample=60, buffer_id=0E:3C
    db 5,0,131,0,60,120,11,0,6,1,60,2  ; n1045 t=65.596s dur=131ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 0,0,100,0,70,110,4,1,210,1,70,4  ; n1046 t=65.600s dur=100ms, freq=466Hz, sample=70, buffer_id=04:46
    db 19,0,100,0,65,110,4,2,93,1,65,4  ; n1047 t=65.600s dur=100ms, freq=349Hz, sample=65, buffer_id=04:41
    db 0,0,100,0,77,124,5,3,186,2,77,5  ; n1048 t=65.619s dur=100ms, freq=698Hz, sample=77, buffer_id=05:4D
    db 0,0,100,0,72,124,5,10,75,2,72,5  ; n1049 t=65.619s dur=100ms, freq=587Hz, sample=72, buffer_id=05:48
    db 0,0,100,0,67,124,5,9,184,1,67,5  ; n1050 t=65.619s dur=100ms, freq=440Hz, sample=67, buffer_id=05:43
    db 0,0,100,0,65,124,14,12,93,1,65,14  ; n1051 t=65.619s dur=100ms, freq=349Hz, sample=65, buffer_id=0E:41
    db 0,0,100,0,60,124,14,11,38,1,60,14  ; n1052 t=65.619s dur=100ms, freq=294Hz, sample=60, buffer_id=0E:3C
    db 193,0,100,0,55,124,14,13,220,0,55,14  ; n1053 t=65.619s dur=100ms, freq=220Hz, sample=55, buffer_id=0E:37 [TRUNCATE prev:ch13 @64940.7ms -> 65619.2ms]
    db 9,0,169,0,36,120,2,5,65,0,36,2  ; n1054 t=65.812s dur=169ms, freq=65Hz, sample=36, buffer_id=02:24
    db 0,0,131,0,60,120,11,4,6,1,60,2  ; n1055 t=65.822s dur=131ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 42,0,169,0,48,115,13,7,131,0,48,2  ; n1056 t=65.822s dur=169ms, freq=131Hz, sample=48, buffer_id=02:30
    db 0,0,100,0,72,124,5,6,210,1,72,5  ; n1057 t=65.864s dur=100ms, freq=466Hz, sample=72, buffer_id=05:48
    db 104,0,100,0,60,124,14,8,233,0,60,14  ; n1058 t=65.864s dur=100ms, freq=233Hz, sample=60, buffer_id=0E:3C [TRUNCATE prev:ch8 @65393.0ms -> 65864.1ms]
    db 0,0,100,0,67,124,5,0,184,1,67,5  ; n1059 t=65.968s dur=100ms, freq=440Hz, sample=67, buffer_id=05:43
    db 80,0,100,0,55,124,14,1,220,0,55,14  ; n1060 t=65.968s dur=100ms, freq=220Hz, sample=55, buffer_id=0E:37
    db 23,0,131,0,60,120,11,2,6,1,60,2  ; n1061 t=66.048s dur=131ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 0,0,100,0,72,124,5,3,210,1,72,5  ; n1062 t=66.071s dur=100ms, freq=466Hz, sample=72, buffer_id=05:48
    db 193,0,100,0,60,124,14,9,233,0,60,14  ; n1063 t=66.071s dur=100ms, freq=233Hz, sample=60, buffer_id=0E:3C
    db 9,0,169,0,36,120,2,4,65,0,36,2  ; n1064 t=66.265s dur=169ms, freq=65Hz, sample=36, buffer_id=02:24
    db 0,0,131,0,60,120,11,0,6,1,60,2  ; n1065 t=66.274s dur=131ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 5,0,169,0,48,115,13,1,131,0,48,2  ; n1066 t=66.274s dur=169ms, freq=131Hz, sample=48, buffer_id=02:30
    db 0,0,100,0,70,110,4,5,210,1,70,4  ; n1067 t=66.279s dur=100ms, freq=466Hz, sample=70, buffer_id=04:46
    db 19,0,100,0,65,110,4,6,93,1,65,4  ; n1068 t=66.279s dur=100ms, freq=349Hz, sample=65, buffer_id=04:41
    db 0,0,113,0,36,120,1,7,65,0,36,1  ; n1069 t=66.298s dur=113ms, freq=65Hz, sample=36, buffer_id=01:24
    db 0,0,100,0,77,124,5,8,186,2,77,5  ; n1070 t=66.298s dur=100ms, freq=698Hz, sample=77, buffer_id=05:4D
    db 0,0,100,0,72,124,5,11,75,2,72,5  ; n1071 t=66.298s dur=100ms, freq=587Hz, sample=72, buffer_id=05:48
    db 0,0,100,0,67,124,5,10,184,1,67,5  ; n1072 t=66.298s dur=100ms, freq=440Hz, sample=67, buffer_id=05:43
    db 0,0,100,0,65,124,14,13,93,1,65,14  ; n1073 t=66.298s dur=100ms, freq=349Hz, sample=65, buffer_id=0E:41
    db 0,0,100,0,60,124,14,12,38,1,60,14  ; n1074 t=66.298s dur=100ms, freq=294Hz, sample=60, buffer_id=0E:3C
    db 203,0,100,0,55,124,14,2,220,0,55,14  ; n1075 t=66.298s dur=100ms, freq=220Hz, sample=55, buffer_id=0E:37 [TRUNCATE prev:ch2 @66047.9ms -> 66297.6ms]
    db 23,0,131,0,60,120,11,3,6,1,60,2  ; n1076 t=66.500s dur=131ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 0,0,100,0,70,110,4,9,159,1,70,4  ; n1077 t=66.524s dur=100ms, freq=415Hz, sample=70, buffer_id=04:46
    db 19,0,100,0,65,110,4,6,55,1,65,4  ; n1078 t=66.524s dur=100ms, freq=311Hz, sample=65, buffer_id=04:41 [TRUNCATE prev:ch6 @66278.7ms -> 66523.7ms]
    db 0,0,100,0,77,124,5,8,110,2,77,5  ; n1079 t=66.543s dur=100ms, freq=622Hz, sample=77, buffer_id=05:4D [TRUNCATE prev:ch8 @66297.6ms -> 66542.6ms]
    db 0,0,100,0,72,124,5,11,11,2,72,5  ; n1080 t=66.543s dur=100ms, freq=523Hz, sample=72, buffer_id=05:48 [TRUNCATE prev:ch11 @66297.6ms -> 66542.6ms]
    db 0,0,100,0,67,124,5,10,136,1,67,5  ; n1081 t=66.543s dur=100ms, freq=392Hz, sample=67, buffer_id=05:43 [TRUNCATE prev:ch10 @66297.6ms -> 66542.6ms]
    db 0,0,100,0,65,124,14,13,55,1,65,14  ; n1082 t=66.543s dur=100ms, freq=311Hz, sample=65, buffer_id=0E:41 [TRUNCATE prev:ch13 @66297.6ms -> 66542.6ms]
    db 0,0,100,0,60,124,14,12,6,1,60,14  ; n1083 t=66.543s dur=100ms, freq=262Hz, sample=60, buffer_id=0E:3C [TRUNCATE prev:ch12 @66297.6ms -> 66542.6ms]
    db 85,0,100,0,55,124,14,2,196,0,55,14  ; n1084 t=66.543s dur=100ms, freq=196Hz, sample=55, buffer_id=0E:37 [TRUNCATE prev:ch2 @66297.6ms -> 66542.6ms]
    db 0,0,100,0,65,110,4,0,136,1,65,4  ; n1085 t=66.627s dur=100ms, freq=392Hz, sample=65, buffer_id=04:41
    db 19,0,100,0,60,110,4,5,38,1,60,4  ; n1086 t=66.627s dur=100ms, freq=294Hz, sample=60, buffer_id=04:3C
    db 0,0,100,0,72,124,5,1,75,2,72,5  ; n1087 t=66.646s dur=100ms, freq=587Hz, sample=72, buffer_id=05:48
    db 0,0,100,0,72,124,5,4,238,1,72,5  ; n1088 t=66.646s dur=100ms, freq=494Hz, sample=72, buffer_id=05:48
    db 0,0,100,0,67,124,5,7,114,1,67,5  ; n1089 t=66.646s dur=100ms, freq=370Hz, sample=67, buffer_id=05:43
    db 0,0,100,0,60,124,14,12,38,1,60,14  ; n1090 t=66.646s dur=100ms, freq=294Hz, sample=60, buffer_id=0E:3C [TRUNCATE prev:ch12 @66542.6ms -> 66646.2ms]
    db 0,0,100,0,60,124,14,3,247,0,60,14  ; n1091 t=66.646s dur=100ms, freq=247Hz, sample=60, buffer_id=0E:3C [TRUNCATE prev:ch3 @66500.2ms -> 66646.2ms]
    db 71,0,100,0,55,124,14,2,185,0,55,14  ; n1092 t=66.646s dur=100ms, freq=185Hz, sample=55, buffer_id=0E:37 [TRUNCATE prev:ch2 @66542.6ms -> 66646.2ms]
    db 9,0,169,0,36,120,2,6,65,0,36,2  ; n1093 t=66.717s dur=169ms, freq=65Hz, sample=36, buffer_id=02:24 [TRUNCATE prev:ch6 @66523.7ms -> 66716.9ms]
    db 0,0,131,0,60,120,11,9,6,1,60,2  ; n1094 t=66.726s dur=131ms, freq=262Hz, sample=60, buffer_id=02:3C [TRUNCATE prev:ch9 @66523.7ms -> 66726.3ms]
    db 5,0,169,0,48,115,13,8,131,0,48,2  ; n1095 t=66.726s dur=169ms, freq=131Hz, sample=48, buffer_id=02:30 [TRUNCATE prev:ch8 @66542.6ms -> 66726.3ms]
    db 0,0,219,4,70,110,4,10,159,1,70,4  ; n1096 t=66.731s dur=1243ms, freq=415Hz, sample=70, buffer_id=04:46 [TRUNCATE prev:ch10 @66542.6ms -> 66731.0ms]
    db 19,0,219,4,65,110,4,0,55,1,65,4  ; n1097 t=66.731s dur=1243ms, freq=311Hz, sample=65, buffer_id=04:41 [TRUNCATE prev:ch0 @66627.4ms -> 66731.0ms]
    db 0,0,106,4,36,120,1,11,65,0,36,1  ; n1098 t=66.750s dur=1130ms, freq=65Hz, sample=36, buffer_id=01:24 [TRUNCATE prev:ch11 @66542.6ms -> 66749.9ms]
    db 0,0,219,4,77,124,5,13,110,2,77,5  ; n1099 t=66.750s dur=1243ms, freq=622Hz, sample=77, buffer_id=05:4D [TRUNCATE prev:ch13 @66542.6ms -> 66749.9ms]
    db 0,0,219,4,72,124,5,1,11,2,72,5  ; n1100 t=66.750s dur=1243ms, freq=523Hz, sample=72, buffer_id=05:48 [TRUNCATE prev:ch1 @66646.2ms -> 66749.9ms]
    db 0,0,219,4,67,124,5,7,136,1,67,5  ; n1101 t=66.750s dur=1243ms, freq=392Hz, sample=67, buffer_id=05:43 [TRUNCATE prev:ch7 @66646.2ms -> 66749.9ms]
    db 0,0,219,4,65,124,14,5,55,1,65,14  ; n1102 t=66.750s dur=1243ms, freq=311Hz, sample=65, buffer_id=0E:41 [TRUNCATE prev:ch5 @66627.4ms -> 66749.9ms]
    db 0,0,219,4,60,124,14,3,6,1,60,14  ; n1103 t=66.750s dur=1243ms, freq=262Hz, sample=60, buffer_id=0E:3C [TRUNCATE prev:ch3 @66646.2ms -> 66749.9ms]
    db 203,0,219,4,55,124,14,2,196,0,55,14  ; n1104 t=66.750s dur=1243ms, freq=196Hz, sample=55, buffer_id=0E:37 [TRUNCATE prev:ch2 @66646.2ms -> 66749.9ms]
    db 217,0,131,0,60,120,11,4,6,1,60,2  ; n1105 t=66.953s dur=131ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 9,0,169,0,36,120,2,8,65,0,36,2  ; n1106 t=67.169s dur=169ms, freq=65Hz, sample=36, buffer_id=02:24
    db 0,0,131,0,60,120,11,6,6,1,60,2  ; n1107 t=67.179s dur=131ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 9,0,169,0,48,115,13,9,131,0,48,2  ; n1108 t=67.179s dur=169ms, freq=131Hz, sample=48, buffer_id=02:30
    db 9,0,100,0,72,120,7,12,11,2,72,2  ; n1109 t=67.188s dur=100ms, freq=523Hz, sample=72, buffer_id=02:48
    db 0,0,100,0,73,110,16,0,11,2,73,16  ; n1110 t=67.197s dur=100ms, freq=523Hz, sample=73, buffer_id=10:49 [TRUNCATE prev:ch0 @66731.0ms -> 67197.4ms]
    db 0,0,100,0,85,90,17,10,23,4,85,17  ; n1111 t=67.197s dur=100ms, freq=1047Hz, sample=85, buffer_id=11:55 [TRUNCATE prev:ch10 @66731.0ms -> 67197.4ms]
    db 71,0,100,0,65,100,18,1,6,1,65,18  ; n1112 t=67.197s dur=100ms, freq=262Hz, sample=65, buffer_id=12:41 [TRUNCATE prev:ch1 @66749.9ms -> 67197.4ms]
    db 9,0,100,0,73,120,7,2,75,2,73,2  ; n1113 t=67.268s dur=100ms, freq=587Hz, sample=73, buffer_id=02:49 [TRUNCATE prev:ch2 @66749.9ms -> 67268.1ms]
    db 0,0,100,0,73,110,16,3,75,2,73,16  ; n1114 t=67.278s dur=100ms, freq=587Hz, sample=73, buffer_id=10:49 [TRUNCATE prev:ch3 @66749.9ms -> 67277.5ms]
    db 0,0,100,0,85,90,17,5,151,4,85,17  ; n1115 t=67.278s dur=100ms, freq=1175Hz, sample=85, buffer_id=11:55 [TRUNCATE prev:ch5 @66749.9ms -> 67277.5ms]
    db 71,0,100,0,65,100,18,7,38,1,65,18  ; n1116 t=67.278s dur=100ms, freq=294Hz, sample=65, buffer_id=12:41 [TRUNCATE prev:ch7 @66749.9ms -> 67277.5ms]
    db 9,0,100,0,75,120,7,4,110,2,75,2  ; n1117 t=67.348s dur=100ms, freq=622Hz, sample=75, buffer_id=02:4B
    db 0,0,100,0,73,110,16,0,110,2,73,16  ; n1118 t=67.358s dur=100ms, freq=622Hz, sample=73, buffer_id=10:49 [TRUNCATE prev:ch0 @67197.4ms -> 67357.6ms]
    db 0,0,100,0,85,90,17,10,221,4,85,17  ; n1119 t=67.358s dur=100ms, freq=1245Hz, sample=85, buffer_id=11:55 [TRUNCATE prev:ch10 @67197.4ms -> 67357.6ms]
    db 47,0,100,0,65,100,18,1,55,1,65,18  ; n1120 t=67.358s dur=100ms, freq=311Hz, sample=65, buffer_id=12:41 [TRUNCATE prev:ch1 @67197.4ms -> 67357.6ms]
    db 28,0,131,0,60,120,11,6,6,1,60,2  ; n1121 t=67.405s dur=131ms, freq=262Hz, sample=60, buffer_id=02:3C [TRUNCATE prev:ch6 @67178.6ms -> 67404.7ms]
    db 9,0,100,0,75,120,7,11,186,2,75,2  ; n1122 t=67.433s dur=100ms, freq=698Hz, sample=75, buffer_id=02:4B [TRUNCATE prev:ch11 @66749.9ms -> 67433.0ms]
    db 0,0,100,0,77,110,16,13,186,2,77,16  ; n1123 t=67.442s dur=100ms, freq=698Hz, sample=77, buffer_id=10:4D [TRUNCATE prev:ch13 @66749.9ms -> 67442.4ms]
    db 0,0,100,0,92,90,17,8,117,5,92,17  ; n1124 t=67.442s dur=100ms, freq=1397Hz, sample=92, buffer_id=11:5C [TRUNCATE prev:ch8 @67169.2ms -> 67442.4ms]
    db 71,0,100,0,65,100,18,7,93,1,65,18  ; n1125 t=67.442s dur=100ms, freq=349Hz, sample=65, buffer_id=12:41 [TRUNCATE prev:ch7 @67277.5ms -> 67442.4ms]
    db 9,0,100,0,79,120,7,12,16,3,79,2  ; n1126 t=67.513s dur=100ms, freq=784Hz, sample=79, buffer_id=02:4F
    db 0,0,100,0,77,110,16,9,16,3,77,16  ; n1127 t=67.522s dur=100ms, freq=784Hz, sample=77, buffer_id=10:4D [TRUNCATE prev:ch9 @67178.6ms -> 67522.5ms]
    db 0,0,100,0,92,90,17,2,32,6,92,17  ; n1128 t=67.522s dur=100ms, freq=1568Hz, sample=92, buffer_id=11:5C [TRUNCATE prev:ch2 @67268.1ms -> 67522.5ms]
    db 75,0,100,0,65,100,18,1,136,1,65,18  ; n1129 t=67.522s dur=100ms, freq=392Hz, sample=65, buffer_id=12:41 [TRUNCATE prev:ch1 @67357.6ms -> 67522.5ms]
    db 9,0,100,0,79,120,7,3,63,3,79,2  ; n1130 t=67.598s dur=100ms, freq=831Hz, sample=79, buffer_id=02:4F
    db 0,0,100,0,77,110,16,5,63,3,77,16  ; n1131 t=67.607s dur=100ms, freq=831Hz, sample=77, buffer_id=10:4D
    db 0,0,100,0,92,90,17,8,125,6,92,17  ; n1132 t=67.607s dur=100ms, freq=1661Hz, sample=92, buffer_id=11:5C [TRUNCATE prev:ch8 @67442.4ms -> 67607.3ms]
    db 14,0,100,0,70,100,18,4,159,1,70,18  ; n1133 t=67.607s dur=100ms, freq=415Hz, sample=70, buffer_id=12:46 [TRUNCATE prev:ch4 @67348.2ms -> 67607.3ms]
    db 9,0,169,0,36,120,2,0,65,0,36,2  ; n1134 t=67.621s dur=169ms, freq=65Hz, sample=36, buffer_id=02:24 [TRUNCATE prev:ch0 @67357.6ms -> 67621.5ms]
    db 0,0,131,0,60,120,11,6,6,1,60,2  ; n1135 t=67.631s dur=131ms, freq=262Hz, sample=60, buffer_id=02:3C [TRUNCATE prev:ch6 @67404.7ms -> 67630.9ms]
    db 47,0,169,0,48,115,13,10,131,0,48,2  ; n1136 t=67.631s dur=169ms, freq=131Hz, sample=48, buffer_id=02:30 [TRUNCATE prev:ch10 @67357.6ms -> 67630.9ms]
    db 9,0,100,0,84,120,7,11,164,3,84,2  ; n1137 t=67.678s dur=100ms, freq=932Hz, sample=84, buffer_id=02:54 [TRUNCATE prev:ch11 @67433.0ms -> 67678.0ms]
    db 0,0,100,0,84,110,16,7,164,3,84,16  ; n1138 t=67.687s dur=100ms, freq=932Hz, sample=84, buffer_id=10:54 [TRUNCATE prev:ch7 @67442.4ms -> 67687.4ms]
    db 0,0,100,0,92,90,17,2,73,7,92,17  ; n1139 t=67.687s dur=100ms, freq=1865Hz, sample=92, buffer_id=11:5C [TRUNCATE prev:ch2 @67522.5ms -> 67687.4ms]
    db 75,0,100,0,70,100,18,13,210,1,70,18  ; n1140 t=67.687s dur=100ms, freq=466Hz, sample=70, buffer_id=12:46 [TRUNCATE prev:ch13 @67442.4ms -> 67687.4ms]
    db 9,0,100,0,84,120,7,12,23,4,84,2  ; n1141 t=67.763s dur=100ms, freq=1047Hz, sample=84, buffer_id=02:54 [TRUNCATE prev:ch12 @67513.1ms -> 67762.8ms]
    db 0,0,100,0,84,110,16,1,23,4,84,16  ; n1142 t=67.772s dur=100ms, freq=1047Hz, sample=84, buffer_id=10:54 [TRUNCATE prev:ch1 @67522.5ms -> 67772.2ms]
    db 0,0,100,0,96,90,17,9,45,8,96,17  ; n1143 t=67.772s dur=100ms, freq=2093Hz, sample=96, buffer_id=11:60 [TRUNCATE prev:ch9 @67522.5ms -> 67772.2ms]
    db 71,0,100,0,70,100,18,4,11,2,70,18  ; n1144 t=67.772s dur=100ms, freq=523Hz, sample=70, buffer_id=12:46 [TRUNCATE prev:ch4 @67607.3ms -> 67772.2ms]
    db 9,0,100,0,86,120,7,3,151,4,86,2  ; n1145 t=67.843s dur=100ms, freq=1175Hz, sample=86, buffer_id=02:56 [TRUNCATE prev:ch3 @67597.9ms -> 67842.9ms]
    db 0,0,100,0,84,110,16,7,151,4,84,16  ; n1146 t=67.852s dur=100ms, freq=1175Hz, sample=84, buffer_id=10:54 [TRUNCATE prev:ch7 @67687.4ms -> 67852.3ms]
    db 0,0,100,0,96,90,17,5,45,9,96,17  ; n1147 t=67.852s dur=100ms, freq=2349Hz, sample=96, buffer_id=11:60 [TRUNCATE prev:ch5 @67607.3ms -> 67852.3ms]
    db 5,0,100,0,77,100,18,8,75,2,77,18  ; n1148 t=67.852s dur=100ms, freq=587Hz, sample=77, buffer_id=12:4D [TRUNCATE prev:ch8 @67607.3ms -> 67852.3ms]
    db 71,0,131,0,60,120,11,6,6,1,60,2  ; n1149 t=67.857s dur=131ms, freq=262Hz, sample=60, buffer_id=02:3C [TRUNCATE prev:ch6 @67630.9ms -> 67857.0ms]
    db 9,0,100,0,86,120,7,0,221,4,86,2  ; n1150 t=67.928s dur=100ms, freq=1245Hz, sample=86, buffer_id=02:56 [TRUNCATE prev:ch0 @67621.5ms -> 67927.7ms]
    db 0,0,100,0,89,110,16,10,221,4,89,16  ; n1151 t=67.937s dur=100ms, freq=1245Hz, sample=89, buffer_id=10:59 [TRUNCATE prev:ch10 @67630.9ms -> 67937.1ms]
    db 0,0,100,0,101,90,17,11,185,9,101,17  ; n1152 t=67.937s dur=100ms, freq=2489Hz, sample=101, buffer_id=11:65 [TRUNCATE prev:ch11 @67678.0ms -> 67937.1ms]
    db 71,0,100,0,77,100,18,2,110,2,77,18  ; n1153 t=67.937s dur=100ms, freq=622Hz, sample=77, buffer_id=12:4D [TRUNCATE prev:ch2 @67687.4ms -> 67937.1ms]
    db 9,0,100,0,91,120,7,13,117,5,91,2  ; n1154 t=68.008s dur=100ms, freq=1397Hz, sample=91, buffer_id=02:5B
    db 0,0,100,0,89,110,16,12,117,5,89,16  ; n1155 t=68.017s dur=100ms, freq=1397Hz, sample=89, buffer_id=10:59 [TRUNCATE prev:ch12 @67762.8ms -> 68017.2ms]
    db 0,0,100,0,101,90,17,1,234,10,101,17  ; n1156 t=68.017s dur=100ms, freq=2794Hz, sample=101, buffer_id=11:65 [TRUNCATE prev:ch1 @67772.2ms -> 68017.2ms]
    db 56,0,100,0,77,100,18,8,186,2,77,18  ; n1157 t=68.017s dur=100ms, freq=698Hz, sample=77, buffer_id=12:4D [TRUNCATE prev:ch8 @67852.3ms -> 68017.2ms]
    db 10,0,169,0,36,120,2,4,65,0,36,2  ; n1158 t=68.074s dur=169ms, freq=65Hz, sample=36, buffer_id=02:24
    db 0,0,131,0,60,120,11,9,6,1,60,2  ; n1159 t=68.083s dur=131ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 9,0,169,0,48,115,13,3,131,0,48,2  ; n1160 t=68.083s dur=169ms, freq=131Hz, sample=48, buffer_id=02:30 [TRUNCATE prev:ch3 @67842.9ms -> 68083.2ms]
    db 9,0,100,0,91,120,7,5,32,6,91,2  ; n1161 t=68.093s dur=100ms, freq=1568Hz, sample=91, buffer_id=02:5B [TRUNCATE prev:ch5 @67852.3ms -> 68092.6ms]
    db 0,0,100,0,89,110,16,10,32,6,89,16  ; n1162 t=68.102s dur=100ms, freq=1568Hz, sample=89, buffer_id=10:59 [TRUNCATE prev:ch10 @67937.1ms -> 68102.0ms]
    db 0,0,100,0,101,90,17,11,64,12,101,17  ; n1163 t=68.102s dur=100ms, freq=3136Hz, sample=101, buffer_id=11:65 [TRUNCATE prev:ch11 @67937.1ms -> 68102.0ms]
    db 5,0,100,0,77,100,18,2,16,3,77,18  ; n1164 t=68.102s dur=100ms, freq=784Hz, sample=77, buffer_id=12:4D [TRUNCATE prev:ch2 @67937.1ms -> 68102.0ms]
    db 203,0,113,0,36,120,1,7,65,0,36,1  ; n1165 t=68.107s dur=113ms, freq=65Hz, sample=36, buffer_id=01:24 [TRUNCATE prev:ch7 @67852.3ms -> 68106.7ms]
    db 42,0,131,0,60,120,11,0,6,1,60,2  ; n1166 t=68.309s dur=131ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 0,0,100,0,72,124,5,1,11,2,72,5  ; n1167 t=68.352s dur=100ms, freq=523Hz, sample=72, buffer_id=05:48
    db 104,0,100,0,60,124,14,6,6,1,60,14  ; n1168 t=68.352s dur=100ms, freq=262Hz, sample=60, buffer_id=0E:3C
    db 0,0,100,0,72,124,5,2,11,2,72,5  ; n1169 t=68.455s dur=100ms, freq=523Hz, sample=72, buffer_id=05:48
    db 71,0,100,0,60,124,14,3,6,1,60,14  ; n1170 t=68.455s dur=100ms, freq=262Hz, sample=60, buffer_id=0E:3C
    db 10,0,153,0,29,120,2,4,49,0,29,2  ; n1171 t=68.526s dur=153ms, freq=49Hz, sample=29, buffer_id=02:1D
    db 0,0,131,0,56,120,11,5,196,0,56,2  ; n1172 t=68.535s dur=131ms, freq=196Hz, sample=56, buffer_id=02:38
    db 5,0,169,0,43,115,13,7,98,0,43,2  ; n1173 t=68.535s dur=169ms, freq=98Hz, sample=43, buffer_id=02:2B
    db 0,0,100,0,70,110,4,8,210,1,70,4  ; n1174 t=68.540s dur=100ms, freq=466Hz, sample=70, buffer_id=04:46
    db 19,0,100,0,65,110,4,9,93,1,65,4  ; n1175 t=68.540s dur=100ms, freq=349Hz, sample=65, buffer_id=04:41
    db 0,0,113,0,31,120,1,10,49,0,31,1  ; n1176 t=68.559s dur=113ms, freq=49Hz, sample=31, buffer_id=01:1F
    db 0,0,100,0,77,124,5,11,186,2,77,5  ; n1177 t=68.559s dur=100ms, freq=698Hz, sample=77, buffer_id=05:4D
    db 0,0,100,0,72,124,5,12,75,2,72,5  ; n1178 t=68.559s dur=100ms, freq=587Hz, sample=72, buffer_id=05:48
    db 0,0,100,0,67,124,5,13,184,1,67,5  ; n1179 t=68.559s dur=100ms, freq=440Hz, sample=67, buffer_id=05:43
    db 0,0,100,0,65,124,14,0,93,1,65,14  ; n1180 t=68.559s dur=100ms, freq=349Hz, sample=65, buffer_id=0E:41 [TRUNCATE prev:ch0 @68309.3ms -> 68559.0ms]
    db 0,0,100,0,60,124,14,6,38,1,60,14  ; n1181 t=68.559s dur=100ms, freq=294Hz, sample=60, buffer_id=0E:3C [TRUNCATE prev:ch6 @68351.7ms -> 68559.0ms]
    db 203,0,100,0,55,124,14,1,220,0,55,14  ; n1182 t=68.559s dur=100ms, freq=220Hz, sample=55, buffer_id=0E:37 [TRUNCATE prev:ch1 @68351.7ms -> 68559.0ms]
    db 42,0,131,0,60,120,11,2,6,1,60,2  ; n1183 t=68.762s dur=131ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 0,0,100,0,72,124,5,3,210,1,72,5  ; n1184 t=68.804s dur=100ms, freq=466Hz, sample=72, buffer_id=05:48
    db 104,0,100,0,60,124,14,6,233,0,60,14  ; n1185 t=68.804s dur=100ms, freq=233Hz, sample=60, buffer_id=0E:3C [TRUNCATE prev:ch6 @68559.0ms -> 68804.0ms]
    db 0,0,100,0,67,124,5,0,184,1,67,5  ; n1186 t=68.908s dur=100ms, freq=440Hz, sample=67, buffer_id=05:43
    db 71,0,100,0,55,124,14,4,220,0,55,14  ; n1187 t=68.908s dur=100ms, freq=220Hz, sample=55, buffer_id=0E:37
    db 9,0,169,0,36,120,2,1,65,0,36,2  ; n1188 t=68.978s dur=169ms, freq=65Hz, sample=36, buffer_id=02:24
    db 0,0,131,0,60,120,11,5,6,1,60,2  ; n1189 t=68.988s dur=131ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 24,0,169,0,48,115,13,7,131,0,48,2  ; n1190 t=68.988s dur=169ms, freq=131Hz, sample=48, buffer_id=02:30
    db 0,0,100,0,72,124,5,8,210,1,72,5  ; n1191 t=69.011s dur=100ms, freq=466Hz, sample=72, buffer_id=05:48
    db 203,0,100,0,60,124,14,9,233,0,60,14  ; n1192 t=69.011s dur=100ms, freq=233Hz, sample=60, buffer_id=0E:3C
    db 5,0,131,0,60,120,11,0,6,1,60,2  ; n1193 t=69.214s dur=131ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 0,0,100,0,70,110,4,2,210,1,70,4  ; n1194 t=69.219s dur=100ms, freq=466Hz, sample=70, buffer_id=04:46
    db 19,0,100,0,65,110,4,3,93,1,65,4  ; n1195 t=69.219s dur=100ms, freq=349Hz, sample=65, buffer_id=04:41
    db 0,0,100,0,77,124,5,4,186,2,77,5  ; n1196 t=69.237s dur=100ms, freq=698Hz, sample=77, buffer_id=05:4D
    db 0,0,100,0,72,124,5,6,75,2,72,5  ; n1197 t=69.237s dur=100ms, freq=587Hz, sample=72, buffer_id=05:48
    db 0,0,100,0,67,124,5,10,184,1,67,5  ; n1198 t=69.237s dur=100ms, freq=440Hz, sample=67, buffer_id=05:43
    db 0,0,100,0,65,124,14,11,93,1,65,14  ; n1199 t=69.237s dur=100ms, freq=349Hz, sample=65, buffer_id=0E:41
    db 0,0,100,0,60,124,14,12,38,1,60,14  ; n1200 t=69.237s dur=100ms, freq=294Hz, sample=60, buffer_id=0E:3C
    db 193,0,100,0,55,124,14,13,220,0,55,14  ; n1201 t=69.237s dur=100ms, freq=220Hz, sample=55, buffer_id=0E:37
    db 9,0,169,0,36,120,2,5,65,0,36,2  ; n1202 t=69.431s dur=169ms, freq=65Hz, sample=36, buffer_id=02:24
    db 0,0,131,0,60,120,11,1,6,1,60,2  ; n1203 t=69.440s dur=131ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 42,0,169,0,48,115,13,8,131,0,48,2  ; n1204 t=69.440s dur=169ms, freq=131Hz, sample=48, buffer_id=02:30
    db 0,0,100,0,72,124,5,7,210,1,72,5  ; n1205 t=69.482s dur=100ms, freq=466Hz, sample=72, buffer_id=05:48
    db 104,0,100,0,60,124,14,9,233,0,60,14  ; n1206 t=69.482s dur=100ms, freq=233Hz, sample=60, buffer_id=0E:3C [TRUNCATE prev:ch9 @69011.3ms -> 69482.4ms]
    db 0,0,100,0,67,124,5,0,184,1,67,5  ; n1207 t=69.586s dur=100ms, freq=440Hz, sample=67, buffer_id=05:43
    db 80,0,100,0,55,124,14,2,220,0,55,14  ; n1208 t=69.586s dur=100ms, freq=220Hz, sample=55, buffer_id=0E:37
    db 23,0,131,0,60,120,11,3,6,1,60,2  ; n1209 t=69.666s dur=131ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 0,0,100,0,72,124,5,4,210,1,72,5  ; n1210 t=69.690s dur=100ms, freq=466Hz, sample=72, buffer_id=05:48
    db 193,0,100,0,60,124,14,6,233,0,60,14  ; n1211 t=69.690s dur=100ms, freq=233Hz, sample=60, buffer_id=0E:3C
    db 9,0,169,0,36,120,2,1,65,0,36,2  ; n1212 t=69.883s dur=169ms, freq=65Hz, sample=36, buffer_id=02:24
    db 0,0,131,0,60,120,11,0,6,1,60,2  ; n1213 t=69.892s dur=131ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 5,0,169,0,48,115,13,2,131,0,48,2  ; n1214 t=69.892s dur=169ms, freq=131Hz, sample=48, buffer_id=02:30
    db 0,0,100,0,70,110,4,5,210,1,70,4  ; n1215 t=69.897s dur=100ms, freq=466Hz, sample=70, buffer_id=04:46
    db 19,0,100,0,65,110,4,7,93,1,65,4  ; n1216 t=69.897s dur=100ms, freq=349Hz, sample=65, buffer_id=04:41
    db 0,0,113,0,36,120,1,8,65,0,36,1  ; n1217 t=69.916s dur=113ms, freq=65Hz, sample=36, buffer_id=01:24
    db 0,0,100,0,77,124,5,9,186,2,77,5  ; n1218 t=69.916s dur=100ms, freq=698Hz, sample=77, buffer_id=05:4D
    db 0,0,100,0,72,124,5,10,75,2,72,5  ; n1219 t=69.916s dur=100ms, freq=587Hz, sample=72, buffer_id=05:48
    db 0,0,100,0,67,124,5,11,184,1,67,5  ; n1220 t=69.916s dur=100ms, freq=440Hz, sample=67, buffer_id=05:43
    db 0,0,100,0,65,124,14,12,93,1,65,14  ; n1221 t=69.916s dur=100ms, freq=349Hz, sample=65, buffer_id=0E:41
    db 0,0,100,0,60,124,14,13,38,1,60,14  ; n1222 t=69.916s dur=100ms, freq=294Hz, sample=60, buffer_id=0E:3C
    db 203,0,100,0,55,124,14,3,220,0,55,14  ; n1223 t=69.916s dur=100ms, freq=220Hz, sample=55, buffer_id=0E:37 [TRUNCATE prev:ch3 @69666.2ms -> 69915.9ms]
    db 24,0,131,0,60,120,11,4,6,1,60,2  ; n1224 t=70.118s dur=131ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 0,0,100,0,70,110,4,6,159,1,70,4  ; n1225 t=70.142s dur=100ms, freq=415Hz, sample=70, buffer_id=04:46
    db 19,0,100,0,65,110,4,7,55,1,65,4  ; n1226 t=70.142s dur=100ms, freq=311Hz, sample=65, buffer_id=04:41 [TRUNCATE prev:ch7 @69897.0ms -> 70142.0ms]
    db 0,0,100,0,77,124,5,9,110,2,77,5  ; n1227 t=70.161s dur=100ms, freq=622Hz, sample=77, buffer_id=05:4D [TRUNCATE prev:ch9 @69915.9ms -> 70160.8ms]
    db 0,0,100,0,72,124,5,10,11,2,72,5  ; n1228 t=70.161s dur=100ms, freq=523Hz, sample=72, buffer_id=05:48 [TRUNCATE prev:ch10 @69915.9ms -> 70160.8ms]
    db 0,0,100,0,67,124,5,11,136,1,67,5  ; n1229 t=70.161s dur=100ms, freq=392Hz, sample=67, buffer_id=05:43 [TRUNCATE prev:ch11 @69915.9ms -> 70160.8ms]
    db 0,0,100,0,65,124,14,12,55,1,65,14  ; n1230 t=70.161s dur=100ms, freq=311Hz, sample=65, buffer_id=0E:41 [TRUNCATE prev:ch12 @69915.9ms -> 70160.8ms]
    db 0,0,100,0,60,124,14,13,6,1,60,14  ; n1231 t=70.161s dur=100ms, freq=262Hz, sample=60, buffer_id=0E:3C [TRUNCATE prev:ch13 @69915.9ms -> 70160.8ms]
    db 85,0,100,0,55,124,14,3,196,0,55,14  ; n1232 t=70.161s dur=100ms, freq=196Hz, sample=55, buffer_id=0E:37 [TRUNCATE prev:ch3 @69915.9ms -> 70160.8ms]
    db 0,0,100,0,65,110,4,0,136,1,65,4  ; n1233 t=70.246s dur=100ms, freq=392Hz, sample=65, buffer_id=04:41
    db 19,0,100,0,60,110,4,5,38,1,60,4  ; n1234 t=70.246s dur=100ms, freq=294Hz, sample=60, buffer_id=04:3C
    db 0,0,100,0,72,124,5,1,75,2,72,5  ; n1235 t=70.264s dur=100ms, freq=587Hz, sample=72, buffer_id=05:48
    db 0,0,100,0,72,124,5,2,238,1,72,5  ; n1236 t=70.264s dur=100ms, freq=494Hz, sample=72, buffer_id=05:48
    db 0,0,100,0,67,124,5,8,114,1,67,5  ; n1237 t=70.264s dur=100ms, freq=370Hz, sample=67, buffer_id=05:43
    db 0,0,100,0,60,124,14,13,38,1,60,14  ; n1238 t=70.264s dur=100ms, freq=294Hz, sample=60, buffer_id=0E:3C [TRUNCATE prev:ch13 @70160.8ms -> 70264.5ms]
    db 0,0,100,0,60,124,14,4,247,0,60,14  ; n1239 t=70.264s dur=100ms, freq=247Hz, sample=60, buffer_id=0E:3C [TRUNCATE prev:ch4 @70118.4ms -> 70264.5ms]
    db 71,0,100,0,55,124,14,3,185,0,55,14  ; n1240 t=70.264s dur=100ms, freq=185Hz, sample=55, buffer_id=0E:37 [TRUNCATE prev:ch3 @70160.8ms -> 70264.5ms]
    db 9,0,169,0,36,120,2,6,65,0,36,2  ; n1241 t=70.335s dur=169ms, freq=65Hz, sample=36, buffer_id=02:24 [TRUNCATE prev:ch6 @70142.0ms -> 70335.2ms]
    db 0,0,131,0,60,120,11,7,6,1,60,2  ; n1242 t=70.345s dur=131ms, freq=262Hz, sample=60, buffer_id=02:3C [TRUNCATE prev:ch7 @70142.0ms -> 70344.6ms]
    db 5,0,169,0,48,115,13,9,131,0,48,2  ; n1243 t=70.345s dur=169ms, freq=131Hz, sample=48, buffer_id=02:30 [TRUNCATE prev:ch9 @70160.8ms -> 70344.6ms]
    db 0,0,219,4,70,110,4,10,159,1,70,4  ; n1244 t=70.349s dur=1243ms, freq=415Hz, sample=70, buffer_id=04:46 [TRUNCATE prev:ch10 @70160.8ms -> 70349.3ms]
    db 19,0,219,4,65,110,4,0,55,1,65,4  ; n1245 t=70.349s dur=1243ms, freq=311Hz, sample=65, buffer_id=04:41 [TRUNCATE prev:ch0 @70245.7ms -> 70349.3ms]
    db 0,0,106,4,36,120,1,11,65,0,36,1  ; n1246 t=70.368s dur=1130ms, freq=65Hz, sample=36, buffer_id=01:24 [TRUNCATE prev:ch11 @70160.8ms -> 70368.1ms]
    db 0,0,219,4,77,124,5,12,110,2,77,5  ; n1247 t=70.368s dur=1243ms, freq=622Hz, sample=77, buffer_id=05:4D [TRUNCATE prev:ch12 @70160.8ms -> 70368.1ms]
    db 0,0,219,4,72,124,5,1,11,2,72,5  ; n1248 t=70.368s dur=1243ms, freq=523Hz, sample=72, buffer_id=05:48 [TRUNCATE prev:ch1 @70264.5ms -> 70368.1ms]
    db 0,0,219,4,67,124,5,8,136,1,67,5  ; n1249 t=70.368s dur=1243ms, freq=392Hz, sample=67, buffer_id=05:43 [TRUNCATE prev:ch8 @70264.5ms -> 70368.1ms]
    db 0,0,219,4,65,124,14,5,55,1,65,14  ; n1250 t=70.368s dur=1243ms, freq=311Hz, sample=65, buffer_id=0E:41 [TRUNCATE prev:ch5 @70245.7ms -> 70368.1ms]
    db 0,0,219,4,60,124,14,4,6,1,60,14  ; n1251 t=70.368s dur=1243ms, freq=262Hz, sample=60, buffer_id=0E:3C [TRUNCATE prev:ch4 @70264.5ms -> 70368.1ms]
    db 203,0,219,4,55,124,14,3,196,0,55,14  ; n1252 t=70.368s dur=1243ms, freq=196Hz, sample=55, buffer_id=0E:37 [TRUNCATE prev:ch3 @70264.5ms -> 70368.1ms]
    db 217,0,131,0,60,120,11,2,6,1,60,2  ; n1253 t=70.571s dur=131ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 9,0,169,0,36,120,2,7,65,0,36,2  ; n1254 t=70.787s dur=169ms, freq=65Hz, sample=36, buffer_id=02:24
    db 0,0,131,0,60,120,11,6,6,1,60,2  ; n1255 t=70.797s dur=131ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 9,0,169,0,48,115,13,13,131,0,48,2  ; n1256 t=70.797s dur=169ms, freq=131Hz, sample=48, buffer_id=02:30
    db 9,0,100,0,72,120,7,9,11,2,72,2  ; n1257 t=70.806s dur=100ms, freq=523Hz, sample=72, buffer_id=02:48
    db 0,0,100,0,73,110,16,0,11,2,73,16  ; n1258 t=70.816s dur=100ms, freq=523Hz, sample=73, buffer_id=10:49 [TRUNCATE prev:ch0 @70349.3ms -> 70815.7ms]
    db 0,0,100,0,85,90,17,10,23,4,85,17  ; n1259 t=70.816s dur=100ms, freq=1047Hz, sample=85, buffer_id=11:55 [TRUNCATE prev:ch10 @70349.3ms -> 70815.7ms]
    db 71,0,100,0,65,100,18,1,6,1,65,18  ; n1260 t=70.816s dur=100ms, freq=262Hz, sample=65, buffer_id=12:41 [TRUNCATE prev:ch1 @70368.1ms -> 70815.7ms]
    db 9,0,100,0,73,120,7,3,75,2,73,2  ; n1261 t=70.886s dur=100ms, freq=587Hz, sample=73, buffer_id=02:49 [TRUNCATE prev:ch3 @70368.1ms -> 70886.4ms]
    db 0,0,100,0,73,110,16,4,75,2,73,16  ; n1262 t=70.896s dur=100ms, freq=587Hz, sample=73, buffer_id=10:49 [TRUNCATE prev:ch4 @70368.1ms -> 70895.8ms]
    db 0,0,100,0,85,90,17,5,151,4,85,17  ; n1263 t=70.896s dur=100ms, freq=1175Hz, sample=85, buffer_id=11:55 [TRUNCATE prev:ch5 @70368.1ms -> 70895.8ms]
    db 71,0,100,0,65,100,18,8,38,1,65,18  ; n1264 t=70.896s dur=100ms, freq=294Hz, sample=65, buffer_id=12:41 [TRUNCATE prev:ch8 @70368.1ms -> 70895.8ms]
    db 9,0,100,0,75,120,7,2,110,2,75,2  ; n1265 t=70.966s dur=100ms, freq=622Hz, sample=75, buffer_id=02:4B
    db 0,0,100,0,73,110,16,0,110,2,73,16  ; n1266 t=70.976s dur=100ms, freq=622Hz, sample=73, buffer_id=10:49 [TRUNCATE prev:ch0 @70815.7ms -> 70975.9ms]
    db 0,0,100,0,85,90,17,10,221,4,85,17  ; n1267 t=70.976s dur=100ms, freq=1245Hz, sample=85, buffer_id=11:55 [TRUNCATE prev:ch10 @70815.7ms -> 70975.9ms]
    db 47,0,100,0,65,100,18,1,55,1,65,18  ; n1268 t=70.976s dur=100ms, freq=311Hz, sample=65, buffer_id=12:41 [TRUNCATE prev:ch1 @70815.7ms -> 70975.9ms]
    db 28,0,131,0,60,120,11,6,6,1,60,2  ; n1269 t=71.023s dur=131ms, freq=262Hz, sample=60, buffer_id=02:3C [TRUNCATE prev:ch6 @70796.9ms -> 71023.0ms]
    db 9,0,100,0,75,120,7,11,186,2,75,2  ; n1270 t=71.051s dur=100ms, freq=698Hz, sample=75, buffer_id=02:4B [TRUNCATE prev:ch11 @70368.1ms -> 71051.3ms]
    db 0,0,100,0,77,110,16,12,186,2,77,16  ; n1271 t=71.061s dur=100ms, freq=698Hz, sample=77, buffer_id=10:4D [TRUNCATE prev:ch12 @70368.1ms -> 71060.7ms]
    db 0,0,100,0,92,90,17,7,117,5,92,17  ; n1272 t=71.061s dur=100ms, freq=1397Hz, sample=92, buffer_id=11:5C [TRUNCATE prev:ch7 @70787.4ms -> 71060.7ms]
    db 71,0,100,0,65,100,18,8,93,1,65,18  ; n1273 t=71.061s dur=100ms, freq=349Hz, sample=65, buffer_id=12:41 [TRUNCATE prev:ch8 @70895.8ms -> 71060.7ms]
    db 9,0,100,0,79,120,7,9,16,3,79,2  ; n1274 t=71.131s dur=100ms, freq=784Hz, sample=79, buffer_id=02:4F
    db 0,0,100,0,77,110,16,13,16,3,77,16  ; n1275 t=71.141s dur=100ms, freq=784Hz, sample=77, buffer_id=10:4D [TRUNCATE prev:ch13 @70796.9ms -> 71140.8ms]
    db 0,0,100,0,92,90,17,3,32,6,92,17  ; n1276 t=71.141s dur=100ms, freq=1568Hz, sample=92, buffer_id=11:5C [TRUNCATE prev:ch3 @70886.4ms -> 71140.8ms]
    db 75,0,100,0,65,100,18,1,136,1,65,18  ; n1277 t=71.141s dur=100ms, freq=392Hz, sample=65, buffer_id=12:41 [TRUNCATE prev:ch1 @70975.9ms -> 71140.8ms]
    db 9,0,100,0,79,120,7,4,63,3,79,2  ; n1278 t=71.216s dur=100ms, freq=831Hz, sample=79, buffer_id=02:4F
    db 0,0,100,0,77,110,16,5,63,3,77,16  ; n1279 t=71.226s dur=100ms, freq=831Hz, sample=77, buffer_id=10:4D
    db 0,0,100,0,92,90,17,7,125,6,92,17  ; n1280 t=71.226s dur=100ms, freq=1661Hz, sample=92, buffer_id=11:5C [TRUNCATE prev:ch7 @71060.7ms -> 71225.6ms]
    db 14,0,100,0,70,100,18,2,159,1,70,18  ; n1281 t=71.226s dur=100ms, freq=415Hz, sample=70, buffer_id=12:46 [TRUNCATE prev:ch2 @70966.5ms -> 71225.6ms]
    db 10,0,169,0,36,120,2,0,65,0,36,2  ; n1282 t=71.240s dur=169ms, freq=65Hz, sample=36, buffer_id=02:24 [TRUNCATE prev:ch0 @70975.9ms -> 71239.7ms]
    db 0,0,131,0,60,120,11,6,6,1,60,2  ; n1283 t=71.249s dur=131ms, freq=262Hz, sample=60, buffer_id=02:3C [TRUNCATE prev:ch6 @71023.0ms -> 71249.2ms]
    db 47,0,169,0,48,115,13,10,131,0,48,2  ; n1284 t=71.249s dur=169ms, freq=131Hz, sample=48, buffer_id=02:30 [TRUNCATE prev:ch10 @70975.9ms -> 71249.2ms]
    db 9,0,100,0,84,120,7,11,164,3,84,2  ; n1285 t=71.296s dur=100ms, freq=932Hz, sample=84, buffer_id=02:54 [TRUNCATE prev:ch11 @71051.3ms -> 71296.3ms]
    db 0,0,100,0,84,110,16,8,164,3,84,16  ; n1286 t=71.306s dur=100ms, freq=932Hz, sample=84, buffer_id=10:54 [TRUNCATE prev:ch8 @71060.7ms -> 71305.7ms]
    db 0,0,100,0,92,90,17,3,73,7,92,17  ; n1287 t=71.306s dur=100ms, freq=1865Hz, sample=92, buffer_id=11:5C [TRUNCATE prev:ch3 @71140.8ms -> 71305.7ms]
    db 75,0,100,0,70,100,18,12,210,1,70,18  ; n1288 t=71.306s dur=100ms, freq=466Hz, sample=70, buffer_id=12:46 [TRUNCATE prev:ch12 @71060.7ms -> 71305.7ms]
    db 9,0,100,0,84,120,7,9,23,4,84,2  ; n1289 t=71.381s dur=100ms, freq=1047Hz, sample=84, buffer_id=02:54 [TRUNCATE prev:ch9 @71131.4ms -> 71381.1ms]
    db 0,0,100,0,84,110,16,1,23,4,84,16  ; n1290 t=71.391s dur=100ms, freq=1047Hz, sample=84, buffer_id=10:54 [TRUNCATE prev:ch1 @71140.8ms -> 71390.5ms]
    db 0,0,100,0,96,90,17,13,45,8,96,17  ; n1291 t=71.391s dur=100ms, freq=2093Hz, sample=96, buffer_id=11:60 [TRUNCATE prev:ch13 @71140.8ms -> 71390.5ms]
    db 71,0,100,0,70,100,18,2,11,2,70,18  ; n1292 t=71.391s dur=100ms, freq=523Hz, sample=70, buffer_id=12:46 [TRUNCATE prev:ch2 @71225.6ms -> 71390.5ms]
    db 9,0,100,0,86,120,7,4,151,4,86,2  ; n1293 t=71.461s dur=100ms, freq=1175Hz, sample=86, buffer_id=02:56 [TRUNCATE prev:ch4 @71216.2ms -> 71461.2ms]
    db 0,0,100,0,84,110,16,8,151,4,84,16  ; n1294 t=71.471s dur=100ms, freq=1175Hz, sample=84, buffer_id=10:54 [TRUNCATE prev:ch8 @71305.7ms -> 71470.6ms]
    db 0,0,100,0,96,90,17,5,45,9,96,17  ; n1295 t=71.471s dur=100ms, freq=2349Hz, sample=96, buffer_id=11:60 [TRUNCATE prev:ch5 @71225.6ms -> 71470.6ms]
    db 5,0,100,0,77,100,18,7,75,2,77,18  ; n1296 t=71.471s dur=100ms, freq=587Hz, sample=77, buffer_id=12:4D [TRUNCATE prev:ch7 @71225.6ms -> 71470.6ms]
    db 71,0,131,0,60,120,11,6,6,1,60,2  ; n1297 t=71.475s dur=131ms, freq=262Hz, sample=60, buffer_id=02:3C [TRUNCATE prev:ch6 @71249.2ms -> 71475.3ms]
    db 9,0,100,0,86,120,7,0,221,4,86,2  ; n1298 t=71.546s dur=100ms, freq=1245Hz, sample=86, buffer_id=02:56 [TRUNCATE prev:ch0 @71239.7ms -> 71546.0ms]
    db 0,0,100,0,89,110,16,10,221,4,89,16  ; n1299 t=71.555s dur=100ms, freq=1245Hz, sample=89, buffer_id=10:59 [TRUNCATE prev:ch10 @71249.2ms -> 71555.4ms]
    db 0,0,100,0,101,90,17,11,185,9,101,17  ; n1300 t=71.555s dur=100ms, freq=2489Hz, sample=101, buffer_id=11:65 [TRUNCATE prev:ch11 @71296.3ms -> 71555.4ms]
    db 71,0,100,0,77,100,18,3,110,2,77,18  ; n1301 t=71.555s dur=100ms, freq=622Hz, sample=77, buffer_id=12:4D [TRUNCATE prev:ch3 @71305.7ms -> 71555.4ms]
    db 9,0,100,0,91,120,7,12,117,5,91,2  ; n1302 t=71.626s dur=100ms, freq=1397Hz, sample=91, buffer_id=02:5B
    db 0,0,100,0,89,110,16,9,117,5,89,16  ; n1303 t=71.635s dur=100ms, freq=1397Hz, sample=89, buffer_id=10:59 [TRUNCATE prev:ch9 @71381.1ms -> 71635.5ms]
    db 0,0,100,0,101,90,17,1,234,10,101,17  ; n1304 t=71.635s dur=100ms, freq=2794Hz, sample=101, buffer_id=11:65 [TRUNCATE prev:ch1 @71390.5ms -> 71635.5ms]
    db 56,0,100,0,77,100,18,7,186,2,77,18  ; n1305 t=71.635s dur=100ms, freq=698Hz, sample=77, buffer_id=12:4D [TRUNCATE prev:ch7 @71470.6ms -> 71635.5ms]
    db 9,0,169,0,36,120,2,2,65,0,36,2  ; n1306 t=71.692s dur=169ms, freq=65Hz, sample=36, buffer_id=02:24
    db 0,0,131,0,60,120,11,13,6,1,60,2  ; n1307 t=71.701s dur=131ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 9,0,169,0,48,115,13,4,131,0,48,2  ; n1308 t=71.701s dur=169ms, freq=131Hz, sample=48, buffer_id=02:30 [TRUNCATE prev:ch4 @71461.2ms -> 71701.4ms]
    db 9,0,100,0,91,120,7,5,32,6,91,2  ; n1309 t=71.711s dur=100ms, freq=1568Hz, sample=91, buffer_id=02:5B [TRUNCATE prev:ch5 @71470.6ms -> 71710.9ms]
    db 0,0,100,0,89,110,16,10,32,6,89,16  ; n1310 t=71.720s dur=100ms, freq=1568Hz, sample=89, buffer_id=10:59 [TRUNCATE prev:ch10 @71555.4ms -> 71720.3ms]
    db 0,0,100,0,101,90,17,11,64,12,101,17  ; n1311 t=71.720s dur=100ms, freq=3136Hz, sample=101, buffer_id=11:65 [TRUNCATE prev:ch11 @71555.4ms -> 71720.3ms]
    db 5,0,100,0,77,100,18,3,16,3,77,18  ; n1312 t=71.720s dur=100ms, freq=784Hz, sample=77, buffer_id=12:4D [TRUNCATE prev:ch3 @71555.4ms -> 71720.3ms]
    db 203,0,113,0,36,120,1,8,65,0,36,1  ; n1313 t=71.725s dur=113ms, freq=65Hz, sample=36, buffer_id=01:24 [TRUNCATE prev:ch8 @71470.6ms -> 71725.0ms]
    db 42,0,131,0,60,120,11,0,6,1,60,2  ; n1314 t=71.928s dur=131ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 0,0,100,0,72,124,5,1,11,2,72,5  ; n1315 t=71.970s dur=100ms, freq=523Hz, sample=72, buffer_id=05:48
    db 104,0,100,0,60,124,14,6,6,1,60,14  ; n1316 t=71.970s dur=100ms, freq=262Hz, sample=60, buffer_id=0E:3C
    db 0,0,100,0,72,124,5,2,11,2,72,5  ; n1317 t=72.074s dur=100ms, freq=523Hz, sample=72, buffer_id=05:48
    db 71,0,100,0,60,124,14,3,6,1,60,14  ; n1318 t=72.074s dur=100ms, freq=262Hz, sample=60, buffer_id=0E:3C
    db 9,0,153,0,29,120,2,4,49,0,29,2  ; n1319 t=72.144s dur=153ms, freq=49Hz, sample=29, buffer_id=02:1D
    db 0,0,131,0,56,120,11,5,196,0,56,2  ; n1320 t=72.154s dur=131ms, freq=196Hz, sample=56, buffer_id=02:38
    db 5,0,169,0,43,115,13,7,98,0,43,2  ; n1321 t=72.154s dur=169ms, freq=98Hz, sample=43, buffer_id=02:2B
    db 0,0,100,0,70,110,4,8,210,1,70,4  ; n1322 t=72.158s dur=100ms, freq=466Hz, sample=70, buffer_id=04:46
    db 19,0,100,0,65,110,4,9,93,1,65,4  ; n1323 t=72.158s dur=100ms, freq=349Hz, sample=65, buffer_id=04:41
    db 0,0,113,0,31,120,1,10,49,0,31,1  ; n1324 t=72.177s dur=113ms, freq=49Hz, sample=31, buffer_id=01:1F
    db 0,0,100,0,77,124,5,11,186,2,77,5  ; n1325 t=72.177s dur=100ms, freq=698Hz, sample=77, buffer_id=05:4D
    db 0,0,100,0,72,124,5,12,75,2,72,5  ; n1326 t=72.177s dur=100ms, freq=587Hz, sample=72, buffer_id=05:48
    db 0,0,100,0,67,124,5,13,184,1,67,5  ; n1327 t=72.177s dur=100ms, freq=440Hz, sample=67, buffer_id=05:43
    db 0,0,100,0,65,124,14,0,93,1,65,14  ; n1328 t=72.177s dur=100ms, freq=349Hz, sample=65, buffer_id=0E:41 [TRUNCATE prev:ch0 @71927.6ms -> 72177.3ms]
    db 0,0,100,0,60,124,14,6,38,1,60,14  ; n1329 t=72.177s dur=100ms, freq=294Hz, sample=60, buffer_id=0E:3C [TRUNCATE prev:ch6 @71970.0ms -> 72177.3ms]
    db 203,0,100,0,55,124,14,1,220,0,55,14  ; n1330 t=72.177s dur=100ms, freq=220Hz, sample=55, buffer_id=0E:37 [TRUNCATE prev:ch1 @71970.0ms -> 72177.3ms]
    db 42,0,131,0,56,120,11,2,196,0,56,2  ; n1331 t=72.380s dur=131ms, freq=196Hz, sample=56, buffer_id=02:38
    db 0,0,100,0,72,124,5,3,210,1,72,5  ; n1332 t=72.422s dur=100ms, freq=466Hz, sample=72, buffer_id=05:48
    db 104,0,100,0,60,124,14,6,233,0,60,14  ; n1333 t=72.422s dur=100ms, freq=233Hz, sample=60, buffer_id=0E:3C [TRUNCATE prev:ch6 @72177.3ms -> 72422.3ms]
    db 0,0,100,0,67,124,5,0,184,1,67,5  ; n1334 t=72.526s dur=100ms, freq=440Hz, sample=67, buffer_id=05:43
    db 71,0,100,0,55,124,14,4,220,0,55,14  ; n1335 t=72.526s dur=100ms, freq=220Hz, sample=55, buffer_id=0E:37
    db 9,0,153,0,29,120,2,1,49,0,29,2  ; n1336 t=72.597s dur=153ms, freq=49Hz, sample=29, buffer_id=02:1D
    db 0,0,131,0,56,120,11,7,196,0,56,2  ; n1337 t=72.606s dur=131ms, freq=196Hz, sample=56, buffer_id=02:38
    db 24,0,169,0,43,115,13,5,98,0,43,2  ; n1338 t=72.606s dur=169ms, freq=98Hz, sample=43, buffer_id=02:2B
    db 0,0,100,0,72,124,5,8,210,1,72,5  ; n1339 t=72.630s dur=100ms, freq=466Hz, sample=72, buffer_id=05:48
    db 203,0,100,0,60,124,14,9,233,0,60,14  ; n1340 t=72.630s dur=100ms, freq=233Hz, sample=60, buffer_id=0E:3C
    db 5,0,131,0,56,120,11,0,196,0,56,2  ; n1341 t=72.832s dur=131ms, freq=196Hz, sample=56, buffer_id=02:38
    db 0,0,100,0,70,110,4,2,210,1,70,4  ; n1342 t=72.837s dur=100ms, freq=466Hz, sample=70, buffer_id=04:46
    db 19,0,100,0,65,110,4,3,93,1,65,4  ; n1343 t=72.837s dur=100ms, freq=349Hz, sample=65, buffer_id=04:41
    db 0,0,100,0,77,124,5,4,186,2,77,5  ; n1344 t=72.856s dur=100ms, freq=698Hz, sample=77, buffer_id=05:4D
    db 0,0,100,0,72,124,5,6,75,2,72,5  ; n1345 t=72.856s dur=100ms, freq=587Hz, sample=72, buffer_id=05:48
    db 0,0,100,0,67,124,5,10,184,1,67,5  ; n1346 t=72.856s dur=100ms, freq=440Hz, sample=67, buffer_id=05:43
    db 0,0,100,0,65,124,14,11,93,1,65,14  ; n1347 t=72.856s dur=100ms, freq=349Hz, sample=65, buffer_id=0E:41
    db 0,0,100,0,60,124,14,12,38,1,60,14  ; n1348 t=72.856s dur=100ms, freq=294Hz, sample=60, buffer_id=0E:3C
    db 193,0,100,0,55,124,14,13,220,0,55,14  ; n1349 t=72.856s dur=100ms, freq=220Hz, sample=55, buffer_id=0E:37
    db 9,0,153,0,29,120,2,5,49,0,29,2  ; n1350 t=73.049s dur=153ms, freq=49Hz, sample=29, buffer_id=02:1D
    db 0,0,131,0,56,120,11,1,196,0,56,2  ; n1351 t=73.058s dur=131ms, freq=196Hz, sample=56, buffer_id=02:38
    db 42,0,169,0,43,115,13,7,98,0,43,2  ; n1352 t=73.058s dur=169ms, freq=98Hz, sample=43, buffer_id=02:2B
    db 0,0,100,0,72,124,5,9,210,1,72,5  ; n1353 t=73.101s dur=100ms, freq=466Hz, sample=72, buffer_id=05:48
    db 104,0,100,0,60,124,14,8,233,0,60,14  ; n1354 t=73.101s dur=100ms, freq=233Hz, sample=60, buffer_id=0E:3C
    db 0,0,100,0,67,124,5,0,184,1,67,5  ; n1355 t=73.204s dur=100ms, freq=440Hz, sample=67, buffer_id=05:43
    db 80,0,100,0,55,124,14,2,220,0,55,14  ; n1356 t=73.204s dur=100ms, freq=220Hz, sample=55, buffer_id=0E:37
    db 24,0,131,0,56,120,11,3,196,0,56,2  ; n1357 t=73.284s dur=131ms, freq=196Hz, sample=56, buffer_id=02:38
    db 0,0,100,0,72,124,5,4,210,1,72,5  ; n1358 t=73.308s dur=100ms, freq=466Hz, sample=72, buffer_id=05:48
    db 193,0,100,0,60,124,14,6,233,0,60,14  ; n1359 t=73.308s dur=100ms, freq=233Hz, sample=60, buffer_id=0E:3C
    db 9,0,153,0,29,120,2,1,49,0,29,2  ; n1360 t=73.501s dur=153ms, freq=49Hz, sample=29, buffer_id=02:1D
    db 0,0,131,0,56,120,11,0,196,0,56,2  ; n1361 t=73.511s dur=131ms, freq=196Hz, sample=56, buffer_id=02:38
    db 5,0,169,0,43,115,13,2,98,0,43,2  ; n1362 t=73.511s dur=169ms, freq=98Hz, sample=43, buffer_id=02:2B
    db 0,0,100,0,70,110,4,5,210,1,70,4  ; n1363 t=73.515s dur=100ms, freq=466Hz, sample=70, buffer_id=04:46
    db 19,0,100,0,65,110,4,7,93,1,65,4  ; n1364 t=73.515s dur=100ms, freq=349Hz, sample=65, buffer_id=04:41
    db 0,0,113,0,31,120,1,8,49,0,31,1  ; n1365 t=73.534s dur=113ms, freq=49Hz, sample=31, buffer_id=01:1F
    db 0,0,100,0,77,124,5,9,186,2,77,5  ; n1366 t=73.534s dur=100ms, freq=698Hz, sample=77, buffer_id=05:4D
    db 0,0,100,0,72,124,5,10,75,2,72,5  ; n1367 t=73.534s dur=100ms, freq=587Hz, sample=72, buffer_id=05:48
    db 0,0,100,0,67,124,5,11,184,1,67,5  ; n1368 t=73.534s dur=100ms, freq=440Hz, sample=67, buffer_id=05:43
    db 0,0,100,0,65,124,14,12,93,1,65,14  ; n1369 t=73.534s dur=100ms, freq=349Hz, sample=65, buffer_id=0E:41
    db 0,0,100,0,60,124,14,13,38,1,60,14  ; n1370 t=73.534s dur=100ms, freq=294Hz, sample=60, buffer_id=0E:3C
    db 203,0,100,0,55,124,14,3,220,0,55,14  ; n1371 t=73.534s dur=100ms, freq=220Hz, sample=55, buffer_id=0E:37 [TRUNCATE prev:ch3 @73284.4ms -> 73534.1ms]
    db 24,0,131,0,56,120,11,4,196,0,56,2  ; n1372 t=73.737s dur=131ms, freq=196Hz, sample=56, buffer_id=02:38
    db 0,0,100,0,70,110,4,6,159,1,70,4  ; n1373 t=73.760s dur=100ms, freq=415Hz, sample=70, buffer_id=04:46
    db 19,0,100,0,65,110,4,7,55,1,65,4  ; n1374 t=73.760s dur=100ms, freq=311Hz, sample=65, buffer_id=04:41 [TRUNCATE prev:ch7 @73515.3ms -> 73760.3ms]
    db 0,0,100,0,77,124,5,9,110,2,77,5  ; n1375 t=73.779s dur=100ms, freq=622Hz, sample=77, buffer_id=05:4D [TRUNCATE prev:ch9 @73534.1ms -> 73779.1ms]
    db 0,0,100,0,72,124,5,10,11,2,72,5  ; n1376 t=73.779s dur=100ms, freq=523Hz, sample=72, buffer_id=05:48 [TRUNCATE prev:ch10 @73534.1ms -> 73779.1ms]
    db 0,0,100,0,67,124,5,11,136,1,67,5  ; n1377 t=73.779s dur=100ms, freq=392Hz, sample=67, buffer_id=05:43 [TRUNCATE prev:ch11 @73534.1ms -> 73779.1ms]
    db 0,0,100,0,65,124,14,12,55,1,65,14  ; n1378 t=73.779s dur=100ms, freq=311Hz, sample=65, buffer_id=0E:41 [TRUNCATE prev:ch12 @73534.1ms -> 73779.1ms]
    db 0,0,100,0,60,124,14,13,6,1,60,14  ; n1379 t=73.779s dur=100ms, freq=262Hz, sample=60, buffer_id=0E:3C [TRUNCATE prev:ch13 @73534.1ms -> 73779.1ms]
    db 85,0,100,0,55,124,14,3,196,0,55,14  ; n1380 t=73.779s dur=100ms, freq=196Hz, sample=55, buffer_id=0E:37 [TRUNCATE prev:ch3 @73534.1ms -> 73779.1ms]
    db 0,0,100,0,65,110,4,0,136,1,65,4  ; n1381 t=73.864s dur=100ms, freq=392Hz, sample=65, buffer_id=04:41
    db 19,0,100,0,60,110,4,1,38,1,60,4  ; n1382 t=73.864s dur=100ms, freq=294Hz, sample=60, buffer_id=04:3C
    db 0,0,100,0,72,124,5,2,75,2,72,5  ; n1383 t=73.883s dur=100ms, freq=587Hz, sample=72, buffer_id=05:48
    db 0,0,100,0,72,124,5,5,238,1,72,5  ; n1384 t=73.883s dur=100ms, freq=494Hz, sample=72, buffer_id=05:48
    db 0,0,100,0,67,124,5,8,114,1,67,5  ; n1385 t=73.883s dur=100ms, freq=370Hz, sample=67, buffer_id=05:43
    db 0,0,100,0,60,124,14,13,38,1,60,14  ; n1386 t=73.883s dur=100ms, freq=294Hz, sample=60, buffer_id=0E:3C [TRUNCATE prev:ch13 @73779.1ms -> 73882.8ms]
    db 0,0,100,0,60,124,14,4,247,0,60,14  ; n1387 t=73.883s dur=100ms, freq=247Hz, sample=60, buffer_id=0E:3C [TRUNCATE prev:ch4 @73736.7ms -> 73882.8ms]
    db 71,0,100,0,55,124,14,3,185,0,55,14  ; n1388 t=73.883s dur=100ms, freq=185Hz, sample=55, buffer_id=0E:37 [TRUNCATE prev:ch3 @73779.1ms -> 73882.8ms]
    db 10,0,169,0,29,120,2,6,44,0,29,2  ; n1389 t=73.953s dur=169ms, freq=44Hz, sample=29, buffer_id=02:1D [TRUNCATE prev:ch6 @73760.3ms -> 73953.4ms]
    db 0,0,131,0,53,120,11,7,175,0,53,2  ; n1390 t=73.963s dur=131ms, freq=175Hz, sample=53, buffer_id=02:35 [TRUNCATE prev:ch7 @73760.3ms -> 73962.9ms]
    db 5,0,169,0,41,115,13,9,87,0,41,2  ; n1391 t=73.963s dur=169ms, freq=87Hz, sample=41, buffer_id=02:29 [TRUNCATE prev:ch9 @73779.1ms -> 73962.9ms]
    db 0,0,100,0,70,110,4,10,159,1,70,4  ; n1392 t=73.968s dur=100ms, freq=415Hz, sample=70, buffer_id=04:46 [TRUNCATE prev:ch10 @73779.1ms -> 73967.6ms]
    db 19,0,100,0,65,110,4,0,55,1,65,4  ; n1393 t=73.968s dur=100ms, freq=311Hz, sample=65, buffer_id=04:41 [TRUNCATE prev:ch0 @73863.9ms -> 73967.6ms]
    db 0,0,113,0,31,120,1,11,44,0,31,1  ; n1394 t=73.986s dur=113ms, freq=44Hz, sample=31, buffer_id=01:1F [TRUNCATE prev:ch11 @73779.1ms -> 73986.4ms]
    db 0,0,100,0,77,124,5,12,110,2,77,5  ; n1395 t=73.986s dur=100ms, freq=622Hz, sample=77, buffer_id=05:4D [TRUNCATE prev:ch12 @73779.1ms -> 73986.4ms]
    db 0,0,100,0,72,124,5,2,11,2,72,5  ; n1396 t=73.986s dur=100ms, freq=523Hz, sample=72, buffer_id=05:48 [TRUNCATE prev:ch2 @73882.8ms -> 73986.4ms]
    db 0,0,100,0,67,124,5,8,136,1,67,5  ; n1397 t=73.986s dur=100ms, freq=392Hz, sample=67, buffer_id=05:43 [TRUNCATE prev:ch8 @73882.8ms -> 73986.4ms]
    db 0,0,100,0,65,124,14,1,55,1,65,14  ; n1398 t=73.986s dur=100ms, freq=311Hz, sample=65, buffer_id=0E:41 [TRUNCATE prev:ch1 @73863.9ms -> 73986.4ms]
    db 0,0,100,0,60,124,14,4,6,1,60,14  ; n1399 t=73.986s dur=100ms, freq=262Hz, sample=60, buffer_id=0E:3C [TRUNCATE prev:ch4 @73882.8ms -> 73986.4ms]
    db 203,0,100,0,55,124,14,3,196,0,55,14  ; n1400 t=73.986s dur=100ms, freq=196Hz, sample=55, buffer_id=0E:37 [TRUNCATE prev:ch3 @73882.8ms -> 73986.4ms]
    db 42,0,131,0,53,120,11,5,175,0,53,2  ; n1401 t=74.189s dur=131ms, freq=175Hz, sample=53, buffer_id=02:35
    db 0,0,100,0,67,124,5,13,159,1,67,5  ; n1402 t=74.231s dur=100ms, freq=415Hz, sample=67, buffer_id=05:43
    db 104,0,100,0,55,124,14,3,208,0,55,14  ; n1403 t=74.231s dur=100ms, freq=208Hz, sample=55, buffer_id=0E:37 [TRUNCATE prev:ch3 @73986.4ms -> 74231.4ms]
    db 0,0,100,0,67,124,5,0,136,1,67,5  ; n1404 t=74.335s dur=100ms, freq=392Hz, sample=67, buffer_id=05:43
    db 71,0,100,0,55,124,14,1,196,0,55,14  ; n1405 t=74.335s dur=100ms, freq=196Hz, sample=55, buffer_id=0E:37
    db 9,0,169,0,29,120,2,2,44,0,29,2  ; n1406 t=74.406s dur=169ms, freq=44Hz, sample=29, buffer_id=02:1D
    db 0,0,131,0,53,120,11,4,175,0,53,2  ; n1407 t=74.415s dur=131ms, freq=175Hz, sample=53, buffer_id=02:35
    db 24,0,169,0,41,115,13,6,87,0,41,2  ; n1408 t=74.415s dur=169ms, freq=87Hz, sample=41, buffer_id=02:29
    db 0,0,100,0,67,124,5,7,159,1,67,5  ; n1409 t=74.439s dur=100ms, freq=415Hz, sample=67, buffer_id=05:43
    db 203,0,100,0,55,124,14,8,208,0,55,14  ; n1410 t=74.439s dur=100ms, freq=208Hz, sample=55, buffer_id=0E:37
    db 5,0,131,0,53,120,11,0,175,0,53,2  ; n1411 t=74.641s dur=131ms, freq=175Hz, sample=53, buffer_id=02:35
    db 0,0,100,0,70,110,4,1,159,1,70,4  ; n1412 t=74.646s dur=100ms, freq=415Hz, sample=70, buffer_id=04:46
    db 19,0,100,0,65,110,4,3,55,1,65,4  ; n1413 t=74.646s dur=100ms, freq=311Hz, sample=65, buffer_id=04:41
    db 0,0,100,0,77,124,5,5,110,2,77,5  ; n1414 t=74.665s dur=100ms, freq=622Hz, sample=77, buffer_id=05:4D
    db 0,0,100,0,72,124,5,9,11,2,72,5  ; n1415 t=74.665s dur=100ms, freq=523Hz, sample=72, buffer_id=05:48
    db 0,0,100,0,67,124,5,10,136,1,67,5  ; n1416 t=74.665s dur=100ms, freq=392Hz, sample=67, buffer_id=05:43
    db 0,0,100,0,65,124,14,11,55,1,65,14  ; n1417 t=74.665s dur=100ms, freq=311Hz, sample=65, buffer_id=0E:41
    db 0,0,100,0,60,124,14,12,6,1,60,14  ; n1418 t=74.665s dur=100ms, freq=262Hz, sample=60, buffer_id=0E:3C
    db 193,0,100,0,55,124,14,13,196,0,55,14  ; n1419 t=74.665s dur=100ms, freq=196Hz, sample=55, buffer_id=0E:37
    db 9,0,169,0,29,120,2,4,44,0,29,2  ; n1420 t=74.858s dur=169ms, freq=44Hz, sample=29, buffer_id=02:1D
    db 0,0,131,0,53,120,11,2,175,0,53,2  ; n1421 t=74.867s dur=131ms, freq=175Hz, sample=53, buffer_id=02:35
    db 42,0,169,0,41,115,13,7,87,0,41,2  ; n1422 t=74.867s dur=169ms, freq=87Hz, sample=41, buffer_id=02:29
    db 0,0,100,0,67,124,5,6,159,1,67,5  ; n1423 t=74.910s dur=100ms, freq=415Hz, sample=67, buffer_id=05:43
    db 104,0,100,0,55,124,14,8,208,0,55,14  ; n1424 t=74.910s dur=100ms, freq=208Hz, sample=55, buffer_id=0E:37 [TRUNCATE prev:ch8 @74438.7ms -> 74909.8ms]
    db 0,0,100,0,67,124,5,0,136,1,67,5  ; n1425 t=75.013s dur=100ms, freq=392Hz, sample=67, buffer_id=05:43
    db 80,0,100,0,55,124,14,1,196,0,55,14  ; n1426 t=75.013s dur=100ms, freq=196Hz, sample=55, buffer_id=0E:37
    db 23,0,131,0,53,120,11,3,175,0,53,2  ; n1427 t=75.094s dur=131ms, freq=175Hz, sample=53, buffer_id=02:35
    db 0,0,100,0,67,124,5,5,159,1,67,5  ; n1428 t=75.117s dur=100ms, freq=415Hz, sample=67, buffer_id=05:43
    db 193,0,100,0,55,124,14,9,208,0,55,14  ; n1429 t=75.117s dur=100ms, freq=208Hz, sample=55, buffer_id=0E:37
    db 9,0,169,0,29,120,2,2,44,0,29,2  ; n1430 t=75.310s dur=169ms, freq=44Hz, sample=29, buffer_id=02:1D
    db 0,0,131,0,53,120,11,0,175,0,53,2  ; n1431 t=75.320s dur=131ms, freq=175Hz, sample=53, buffer_id=02:35
    db 5,0,169,0,41,115,13,1,87,0,41,2  ; n1432 t=75.320s dur=169ms, freq=87Hz, sample=41, buffer_id=02:29
    db 0,0,100,0,70,110,4,4,159,1,70,4  ; n1433 t=75.324s dur=100ms, freq=415Hz, sample=70, buffer_id=04:46
    db 19,0,100,0,65,110,4,6,55,1,65,4  ; n1434 t=75.324s dur=100ms, freq=311Hz, sample=65, buffer_id=04:41
    db 0,0,113,0,31,120,1,7,44,0,31,1  ; n1435 t=75.343s dur=113ms, freq=44Hz, sample=31, buffer_id=01:1F
    db 0,0,100,0,77,124,5,8,110,2,77,5  ; n1436 t=75.343s dur=100ms, freq=622Hz, sample=77, buffer_id=05:4D
    db 0,0,100,0,72,124,5,10,11,2,72,5  ; n1437 t=75.343s dur=100ms, freq=523Hz, sample=72, buffer_id=05:48
    db 0,0,100,0,67,124,5,11,136,1,67,5  ; n1438 t=75.343s dur=100ms, freq=392Hz, sample=67, buffer_id=05:43
    db 0,0,100,0,65,124,14,12,55,1,65,14  ; n1439 t=75.343s dur=100ms, freq=311Hz, sample=65, buffer_id=0E:41
    db 0,0,100,0,60,124,14,13,6,1,60,14  ; n1440 t=75.343s dur=100ms, freq=262Hz, sample=60, buffer_id=0E:3C
    db 203,0,100,0,55,124,14,9,196,0,55,14  ; n1441 t=75.343s dur=100ms, freq=196Hz, sample=55, buffer_id=0E:37 [TRUNCATE prev:ch9 @75117.1ms -> 75343.3ms]
    db 23,0,131,0,53,120,11,5,175,0,53,2  ; n1442 t=75.546s dur=131ms, freq=175Hz, sample=53, buffer_id=02:35
    db 0,0,100,0,70,110,4,3,159,1,70,4  ; n1443 t=75.569s dur=100ms, freq=415Hz, sample=70, buffer_id=04:46
    db 19,0,100,0,65,110,4,6,55,1,65,4  ; n1444 t=75.569s dur=100ms, freq=311Hz, sample=65, buffer_id=04:41 [TRUNCATE prev:ch6 @75324.4ms -> 75569.4ms]
    db 0,0,100,0,77,124,5,8,110,2,77,5  ; n1445 t=75.588s dur=100ms, freq=622Hz, sample=77, buffer_id=05:4D [TRUNCATE prev:ch8 @75343.3ms -> 75588.3ms]
    db 0,0,100,0,72,124,5,10,11,2,72,5  ; n1446 t=75.588s dur=100ms, freq=523Hz, sample=72, buffer_id=05:48 [TRUNCATE prev:ch10 @75343.3ms -> 75588.3ms]
    db 0,0,100,0,67,124,5,11,136,1,67,5  ; n1447 t=75.588s dur=100ms, freq=392Hz, sample=67, buffer_id=05:43 [TRUNCATE prev:ch11 @75343.3ms -> 75588.3ms]
    db 0,0,100,0,65,124,14,12,55,1,65,14  ; n1448 t=75.588s dur=100ms, freq=311Hz, sample=65, buffer_id=0E:41 [TRUNCATE prev:ch12 @75343.3ms -> 75588.3ms]
    db 0,0,100,0,60,124,14,13,6,1,60,14  ; n1449 t=75.588s dur=100ms, freq=262Hz, sample=60, buffer_id=0E:3C [TRUNCATE prev:ch13 @75343.3ms -> 75588.3ms]
    db 85,0,100,0,55,124,14,9,196,0,55,14  ; n1450 t=75.588s dur=100ms, freq=196Hz, sample=55, buffer_id=0E:37 [TRUNCATE prev:ch9 @75343.3ms -> 75588.3ms]
    db 0,0,100,0,70,110,4,0,210,1,70,4  ; n1451 t=75.673s dur=100ms, freq=466Hz, sample=70, buffer_id=04:46
    db 19,0,100,0,65,110,4,4,93,1,65,4  ; n1452 t=75.673s dur=100ms, freq=349Hz, sample=65, buffer_id=04:41
    db 0,0,100,0,77,124,5,1,186,2,77,5  ; n1453 t=75.692s dur=100ms, freq=698Hz, sample=77, buffer_id=05:4D
    db 0,0,100,0,72,124,5,2,75,2,72,5  ; n1454 t=75.692s dur=100ms, freq=587Hz, sample=72, buffer_id=05:48
    db 0,0,100,0,67,124,5,7,184,1,67,5  ; n1455 t=75.692s dur=100ms, freq=440Hz, sample=67, buffer_id=05:43
    db 0,0,100,0,65,124,14,12,93,1,65,14  ; n1456 t=75.692s dur=100ms, freq=349Hz, sample=65, buffer_id=0E:41 [TRUNCATE prev:ch12 @75588.3ms -> 75691.9ms]
    db 0,0,100,0,60,124,14,13,38,1,60,14  ; n1457 t=75.692s dur=100ms, freq=294Hz, sample=60, buffer_id=0E:3C [TRUNCATE prev:ch13 @75588.3ms -> 75691.9ms]
    db 71,0,100,0,55,124,14,9,220,0,55,14  ; n1458 t=75.692s dur=100ms, freq=220Hz, sample=55, buffer_id=0E:37 [TRUNCATE prev:ch9 @75588.3ms -> 75691.9ms]
    db 9,0,169,0,36,120,2,5,65,0,36,2  ; n1459 t=75.763s dur=169ms, freq=65Hz, sample=36, buffer_id=02:24 [TRUNCATE prev:ch5 @75545.9ms -> 75762.6ms]
    db 0,0,131,0,60,120,11,3,6,1,60,2  ; n1460 t=75.772s dur=131ms, freq=262Hz, sample=60, buffer_id=02:3C [TRUNCATE prev:ch3 @75569.4ms -> 75772.0ms]
    db 5,0,169,0,48,115,13,6,131,0,48,2  ; n1461 t=75.772s dur=169ms, freq=131Hz, sample=48, buffer_id=02:30 [TRUNCATE prev:ch6 @75569.4ms -> 75772.0ms]
    db 0,0,10,11,65,110,4,4,136,1,65,4  ; n1462 t=75.777s dur=2826ms, freq=392Hz, sample=65, buffer_id=04:41 [TRUNCATE prev:ch4 @75673.1ms -> 75776.7ms]
    db 19,0,177,9,70,110,4,0,11,2,70,4  ; n1463 t=75.777s dur=2481ms, freq=523Hz, sample=70, buffer_id=04:46 [TRUNCATE prev:ch0 @75673.1ms -> 75776.7ms]
    db 0,0,10,11,36,120,1,8,65,0,36,1  ; n1464 t=75.796s dur=2826ms, freq=65Hz, sample=36, buffer_id=01:24 [TRUNCATE prev:ch8 @75588.3ms -> 75795.6ms]
    db 0,0,223,10,77,124,5,1,16,3,77,5  ; n1465 t=75.796s dur=2783ms, freq=784Hz, sample=77, buffer_id=05:4D [TRUNCATE prev:ch1 @75691.9ms -> 75795.6ms]
    db 0,0,10,11,77,124,5,10,147,2,77,5  ; n1466 t=75.796s dur=2826ms, freq=659Hz, sample=77, buffer_id=05:4D [TRUNCATE prev:ch10 @75588.3ms -> 75795.6ms]
    db 0,0,10,11,72,124,5,2,238,1,72,5  ; n1467 t=75.796s dur=2826ms, freq=494Hz, sample=72, buffer_id=05:48 [TRUNCATE prev:ch2 @75691.9ms -> 75795.6ms]
    db 0,0,108,10,65,124,14,12,136,1,65,14  ; n1468 t=75.796s dur=2668ms, freq=392Hz, sample=65, buffer_id=0E:41 [TRUNCATE prev:ch12 @75691.9ms -> 75795.6ms]
    db 0,0,10,11,65,124,14,11,74,1,65,14  ; n1469 t=75.796s dur=2826ms, freq=330Hz, sample=65, buffer_id=0E:41 [TRUNCATE prev:ch11 @75588.3ms -> 75795.6ms]
    db 203,0,10,11,60,124,14,13,247,0,60,14  ; n1470 t=75.796s dur=2826ms, freq=247Hz, sample=60, buffer_id=0E:3C [TRUNCATE prev:ch13 @75691.9ms -> 75795.6ms]
    db 217,0,131,0,60,120,11,7,6,1,60,2  ; n1471 t=75.998s dur=131ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 9,0,169,0,36,120,2,3,65,0,36,2  ; n1472 t=76.215s dur=169ms, freq=65Hz, sample=36, buffer_id=02:24
    db 0,0,131,0,60,120,11,5,6,1,60,2  ; n1473 t=76.224s dur=131ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 226,0,169,0,48,115,13,9,131,0,48,2  ; n1474 t=76.224s dur=169ms, freq=131Hz, sample=48, buffer_id=02:30
    db 217,0,131,0,60,120,11,6,6,1,60,2  ; n1475 t=76.450s dur=131ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 9,0,169,0,36,120,2,5,65,0,36,2  ; n1476 t=76.667s dur=169ms, freq=65Hz, sample=36, buffer_id=02:24
    db 0,0,131,0,60,120,11,3,6,1,60,2  ; n1477 t=76.677s dur=131ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 9,0,169,0,48,115,13,7,131,0,48,2  ; n1478 t=76.677s dur=169ms, freq=131Hz, sample=48, buffer_id=02:30
    db 9,0,100,0,75,120,7,9,186,2,75,2  ; n1479 t=76.686s dur=100ms, freq=698Hz, sample=75, buffer_id=02:4B
    db 0,0,100,0,77,110,16,0,186,2,77,16  ; n1480 t=76.695s dur=100ms, freq=698Hz, sample=77, buffer_id=10:4D [TRUNCATE prev:ch0 @75776.7ms -> 76695.4ms]
    db 0,0,100,0,92,90,17,4,117,5,92,17  ; n1481 t=76.695s dur=100ms, freq=1397Hz, sample=92, buffer_id=11:5C [TRUNCATE prev:ch4 @75776.7ms -> 76695.4ms]
    db 80,0,100,0,65,100,18,1,93,1,65,18  ; n1482 t=76.695s dur=100ms, freq=349Hz, sample=65, buffer_id=12:41 [TRUNCATE prev:ch1 @75795.6ms -> 76695.4ms]
    db 9,0,100,0,79,120,7,2,16,3,79,2  ; n1483 t=76.775s dur=100ms, freq=784Hz, sample=79, buffer_id=02:4F [TRUNCATE prev:ch2 @75795.6ms -> 76775.5ms]
    db 0,0,100,0,77,110,16,6,16,3,77,16  ; n1484 t=76.785s dur=100ms, freq=784Hz, sample=77, buffer_id=10:4D
    db 0,0,100,0,92,90,17,8,32,6,92,17  ; n1485 t=76.785s dur=100ms, freq=1568Hz, sample=92, buffer_id=11:5C [TRUNCATE prev:ch8 @75795.6ms -> 76784.9ms]
    db 80,0,100,0,65,100,18,10,136,1,65,18  ; n1486 t=76.785s dur=100ms, freq=392Hz, sample=65, buffer_id=12:41 [TRUNCATE prev:ch10 @75795.6ms -> 76784.9ms]
    db 9,0,100,0,79,120,7,11,112,3,79,2  ; n1487 t=76.865s dur=100ms, freq=880Hz, sample=79, buffer_id=02:4F [TRUNCATE prev:ch11 @75795.6ms -> 76865.0ms]
    db 0,0,100,0,84,110,16,12,112,3,84,16  ; n1488 t=76.874s dur=100ms, freq=880Hz, sample=84, buffer_id=10:54 [TRUNCATE prev:ch12 @75795.6ms -> 76874.4ms]
    db 0,0,100,0,92,90,17,4,224,6,92,17  ; n1489 t=76.874s dur=100ms, freq=1760Hz, sample=92, buffer_id=11:5C [TRUNCATE prev:ch4 @76695.4ms -> 76874.4ms]
    db 28,0,100,0,70,100,18,13,184,1,70,18  ; n1490 t=76.874s dur=100ms, freq=440Hz, sample=70, buffer_id=12:46 [TRUNCATE prev:ch13 @75795.6ms -> 76874.4ms]
    db 52,0,131,0,60,120,11,3,6,1,60,2  ; n1491 t=76.903s dur=131ms, freq=262Hz, sample=60, buffer_id=02:3C [TRUNCATE prev:ch3 @76676.6ms -> 76902.7ms]
    db 10,0,100,0,84,120,7,5,220,3,84,2  ; n1492 t=76.954s dur=100ms, freq=988Hz, sample=84, buffer_id=02:54 [TRUNCATE prev:ch5 @76667.1ms -> 76954.5ms]
    db 0,0,100,0,84,110,16,7,220,3,84,16  ; n1493 t=76.964s dur=100ms, freq=988Hz, sample=84, buffer_id=10:54 [TRUNCATE prev:ch7 @76676.6ms -> 76964.0ms]
    db 0,0,100,0,96,90,17,9,184,7,96,17  ; n1494 t=76.964s dur=100ms, freq=1976Hz, sample=96, buffer_id=11:60 [TRUNCATE prev:ch9 @76686.0ms -> 76964.0ms]
    db 80,0,100,0,70,100,18,0,238,1,70,18  ; n1495 t=76.964s dur=100ms, freq=494Hz, sample=70, buffer_id=12:46 [TRUNCATE prev:ch0 @76695.4ms -> 76964.0ms]
    db 10,0,100,0,84,120,7,1,23,4,84,2  ; n1496 t=77.044s dur=100ms, freq=1047Hz, sample=84, buffer_id=02:54
    db 0,0,100,0,84,110,16,12,23,4,84,16  ; n1497 t=77.053s dur=100ms, freq=1047Hz, sample=84, buffer_id=10:54 [TRUNCATE prev:ch12 @76874.4ms -> 77053.5ms]
    db 0,0,100,0,96,90,17,2,45,8,96,17  ; n1498 t=77.053s dur=100ms, freq=2093Hz, sample=96, buffer_id=11:60 [TRUNCATE prev:ch2 @76775.5ms -> 77053.5ms]
    db 66,0,100,0,70,100,18,13,11,2,70,18  ; n1499 t=77.053s dur=100ms, freq=523Hz, sample=70, buffer_id=12:46 [TRUNCATE prev:ch13 @76874.4ms -> 77053.5ms]
    db 9,0,169,0,36,120,2,6,65,0,36,2  ; n1500 t=77.119s dur=169ms, freq=65Hz, sample=36, buffer_id=02:24
    db 0,0,131,0,60,120,11,8,6,1,60,2  ; n1501 t=77.129s dur=131ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 10,0,169,0,48,115,13,10,131,0,48,2  ; n1502 t=77.129s dur=169ms, freq=131Hz, sample=48, buffer_id=02:30
    db 9,0,100,0,79,120,7,11,16,3,79,2  ; n1503 t=77.138s dur=100ms, freq=784Hz, sample=79, buffer_id=02:4F [TRUNCATE prev:ch11 @76865.0ms -> 77138.3ms]
    db 0,0,100,0,77,110,16,4,16,3,77,16  ; n1504 t=77.148s dur=100ms, freq=784Hz, sample=77, buffer_id=10:4D [TRUNCATE prev:ch4 @76874.4ms -> 77147.7ms]
    db 0,0,100,0,92,90,17,3,32,6,92,17  ; n1505 t=77.148s dur=100ms, freq=1568Hz, sample=92, buffer_id=11:5C [TRUNCATE prev:ch3 @76902.7ms -> 77147.7ms]
    db 80,0,100,0,65,100,18,5,136,1,65,18  ; n1506 t=77.148s dur=100ms, freq=392Hz, sample=65, buffer_id=12:41 [TRUNCATE prev:ch5 @76954.5ms -> 77147.7ms]
    db 9,0,100,0,79,120,7,0,112,3,79,2  ; n1507 t=77.228s dur=100ms, freq=880Hz, sample=79, buffer_id=02:4F [TRUNCATE prev:ch0 @76964.0ms -> 77227.8ms]
    db 0,0,100,0,84,110,16,7,112,3,84,16  ; n1508 t=77.237s dur=100ms, freq=880Hz, sample=84, buffer_id=10:54 [TRUNCATE prev:ch7 @76964.0ms -> 77237.2ms]
    db 0,0,100,0,92,90,17,9,224,6,92,17  ; n1509 t=77.237s dur=100ms, freq=1760Hz, sample=92, buffer_id=11:5C [TRUNCATE prev:ch9 @76964.0ms -> 77237.2ms]
    db 80,0,100,0,70,100,18,13,184,1,70,18  ; n1510 t=77.237s dur=100ms, freq=440Hz, sample=70, buffer_id=12:46 [TRUNCATE prev:ch13 @77053.5ms -> 77237.2ms]
    db 9,0,100,0,84,120,7,1,220,3,84,2  ; n1511 t=77.317s dur=100ms, freq=988Hz, sample=84, buffer_id=02:54 [TRUNCATE prev:ch1 @77044.0ms -> 77317.3ms]
    db 0,0,100,0,84,110,16,12,220,3,84,16  ; n1512 t=77.327s dur=100ms, freq=988Hz, sample=84, buffer_id=10:54 [TRUNCATE prev:ch12 @77053.5ms -> 77326.7ms]
    db 0,0,100,0,96,90,17,2,184,7,96,17  ; n1513 t=77.327s dur=100ms, freq=1976Hz, sample=96, buffer_id=11:60 [TRUNCATE prev:ch2 @77053.5ms -> 77326.7ms]
    db 28,0,100,0,70,100,18,6,238,1,70,18  ; n1514 t=77.327s dur=100ms, freq=494Hz, sample=70, buffer_id=12:46 [TRUNCATE prev:ch6 @77119.4ms -> 77326.7ms]
    db 52,0,131,0,60,120,11,8,6,1,60,2  ; n1515 t=77.355s dur=131ms, freq=262Hz, sample=60, buffer_id=02:3C [TRUNCATE prev:ch8 @77128.8ms -> 77355.0ms]
    db 9,0,100,0,84,120,7,10,23,4,84,2  ; n1516 t=77.407s dur=100ms, freq=1047Hz, sample=84, buffer_id=02:54 [TRUNCATE prev:ch10 @77128.8ms -> 77406.8ms]
    db 0,0,100,0,84,110,16,7,23,4,84,16  ; n1517 t=77.416s dur=100ms, freq=1047Hz, sample=84, buffer_id=10:54 [TRUNCATE prev:ch7 @77237.2ms -> 77416.2ms]
    db 0,0,100,0,96,90,17,11,45,8,96,17  ; n1518 t=77.416s dur=100ms, freq=2093Hz, sample=96, buffer_id=11:60 [TRUNCATE prev:ch11 @77138.3ms -> 77416.2ms]
    db 80,0,100,0,70,100,18,13,11,2,70,18  ; n1519 t=77.416s dur=100ms, freq=523Hz, sample=70, buffer_id=12:46 [TRUNCATE prev:ch13 @77237.2ms -> 77416.2ms]
    db 9,0,100,0,86,120,7,3,151,4,86,2  ; n1520 t=77.496s dur=100ms, freq=1175Hz, sample=86, buffer_id=02:56
    db 0,0,100,0,84,110,16,4,151,4,84,16  ; n1521 t=77.506s dur=100ms, freq=1175Hz, sample=84, buffer_id=10:54
    db 0,0,100,0,96,90,17,5,45,9,96,17  ; n1522 t=77.506s dur=100ms, freq=2349Hz, sample=96, buffer_id=11:60
    db 66,0,100,0,77,100,18,0,75,2,77,18  ; n1523 t=77.506s dur=100ms, freq=587Hz, sample=77, buffer_id=12:4D [TRUNCATE prev:ch0 @77227.8ms -> 77505.8ms]
    db 9,0,169,0,36,120,2,9,65,0,36,2  ; n1524 t=77.572s dur=169ms, freq=65Hz, sample=36, buffer_id=02:24
    db 0,0,131,0,60,120,11,8,6,1,60,2  ; n1525 t=77.581s dur=131ms, freq=262Hz, sample=60, buffer_id=02:3C [TRUNCATE prev:ch8 @77355.0ms -> 77581.1ms]
    db 9,0,169,0,48,115,13,1,131,0,48,2  ; n1526 t=77.581s dur=169ms, freq=131Hz, sample=48, buffer_id=02:30 [TRUNCATE prev:ch1 @77317.3ms -> 77581.1ms]
    db 9,0,100,0,79,120,7,2,112,3,79,2  ; n1527 t=77.591s dur=100ms, freq=880Hz, sample=79, buffer_id=02:4F [TRUNCATE prev:ch2 @77326.7ms -> 77590.6ms]
    db 0,0,100,0,84,110,16,12,112,3,84,16  ; n1528 t=77.600s dur=100ms, freq=880Hz, sample=84, buffer_id=10:54 [TRUNCATE prev:ch12 @77326.7ms -> 77600.0ms]
    db 0,0,100,0,92,90,17,6,224,6,92,17  ; n1529 t=77.600s dur=100ms, freq=1760Hz, sample=92, buffer_id=11:5C [TRUNCATE prev:ch6 @77326.7ms -> 77600.0ms]
    db 80,0,100,0,70,100,18,13,184,1,70,18  ; n1530 t=77.600s dur=100ms, freq=440Hz, sample=70, buffer_id=12:46 [TRUNCATE prev:ch13 @77416.2ms -> 77600.0ms]
    db 9,0,100,0,84,120,7,10,220,3,84,2  ; n1531 t=77.680s dur=100ms, freq=988Hz, sample=84, buffer_id=02:54 [TRUNCATE prev:ch10 @77406.8ms -> 77680.1ms]
    db 0,0,100,0,84,110,16,7,220,3,84,16  ; n1532 t=77.689s dur=100ms, freq=988Hz, sample=84, buffer_id=10:54 [TRUNCATE prev:ch7 @77416.2ms -> 77689.5ms]
    db 0,0,100,0,96,90,17,11,184,7,96,17  ; n1533 t=77.689s dur=100ms, freq=1976Hz, sample=96, buffer_id=11:60 [TRUNCATE prev:ch11 @77416.2ms -> 77689.5ms]
    db 80,0,100,0,70,100,18,3,238,1,70,18  ; n1534 t=77.689s dur=100ms, freq=494Hz, sample=70, buffer_id=12:46 [TRUNCATE prev:ch3 @77496.3ms -> 77689.5ms]
    db 9,0,100,0,84,120,7,0,23,4,84,2  ; n1535 t=77.770s dur=100ms, freq=1047Hz, sample=84, buffer_id=02:54 [TRUNCATE prev:ch0 @77505.8ms -> 77769.6ms]
    db 0,0,100,0,84,110,16,4,23,4,84,16  ; n1536 t=77.779s dur=100ms, freq=1047Hz, sample=84, buffer_id=10:54 [TRUNCATE prev:ch4 @77505.8ms -> 77779.0ms]
    db 0,0,100,0,96,90,17,5,45,8,96,17  ; n1537 t=77.779s dur=100ms, freq=2093Hz, sample=96, buffer_id=11:60 [TRUNCATE prev:ch5 @77505.8ms -> 77779.0ms]
    db 28,0,100,0,70,100,18,13,11,2,70,18  ; n1538 t=77.779s dur=100ms, freq=523Hz, sample=70, buffer_id=12:46 [TRUNCATE prev:ch13 @77600.0ms -> 77779.0ms]
    db 52,0,131,0,60,120,11,8,6,1,60,2  ; n1539 t=77.807s dur=131ms, freq=262Hz, sample=60, buffer_id=02:3C [TRUNCATE prev:ch8 @77581.1ms -> 77807.3ms]
    db 9,0,100,0,86,120,7,9,151,4,86,2  ; n1540 t=77.859s dur=100ms, freq=1175Hz, sample=86, buffer_id=02:56 [TRUNCATE prev:ch9 @77571.7ms -> 77859.1ms]
    db 0,0,100,0,84,110,16,12,151,4,84,16  ; n1541 t=77.868s dur=100ms, freq=1175Hz, sample=84, buffer_id=10:54 [TRUNCATE prev:ch12 @77600.0ms -> 77868.5ms]
    db 0,0,100,0,96,90,17,11,45,9,96,17  ; n1542 t=77.868s dur=100ms, freq=2349Hz, sample=96, buffer_id=11:60 [TRUNCATE prev:ch11 @77689.5ms -> 77868.5ms]
    db 80,0,100,0,77,100,18,1,75,2,77,18  ; n1543 t=77.868s dur=100ms, freq=587Hz, sample=77, buffer_id=12:4D [TRUNCATE prev:ch1 @77581.1ms -> 77868.5ms]
    db 9,0,100,0,86,120,7,2,39,5,86,2  ; n1544 t=77.949s dur=100ms, freq=1319Hz, sample=86, buffer_id=02:56
    db 0,0,100,0,89,110,16,6,39,5,89,16  ; n1545 t=77.958s dur=100ms, freq=1319Hz, sample=89, buffer_id=10:59
    db 0,0,100,0,101,90,17,10,77,10,101,17  ; n1546 t=77.958s dur=100ms, freq=2637Hz, sample=101, buffer_id=11:65 [TRUNCATE prev:ch10 @77680.1ms -> 77958.0ms]
    db 66,0,100,0,77,100,18,3,147,2,77,18  ; n1547 t=77.958s dur=100ms, freq=659Hz, sample=77, buffer_id=12:4D [TRUNCATE prev:ch3 @77689.5ms -> 77958.0ms]
    db 9,0,169,0,36,120,2,7,65,0,36,2  ; n1548 t=78.024s dur=169ms, freq=65Hz, sample=36, buffer_id=02:24
    db 0,0,131,0,60,120,11,8,6,1,60,2  ; n1549 t=78.033s dur=131ms, freq=262Hz, sample=60, buffer_id=02:3C [TRUNCATE prev:ch8 @77807.3ms -> 78033.4ms]
    db 9,0,169,0,48,115,13,0,131,0,48,2  ; n1550 t=78.033s dur=169ms, freq=131Hz, sample=48, buffer_id=02:30 [TRUNCATE prev:ch0 @77769.6ms -> 78033.4ms]
    db 10,0,100,0,84,120,7,4,220,3,84,2  ; n1551 t=78.043s dur=100ms, freq=988Hz, sample=84, buffer_id=02:54 [TRUNCATE prev:ch4 @77779.0ms -> 78042.8ms]
    db 0,0,100,0,84,110,16,12,220,3,84,16  ; n1552 t=78.052s dur=100ms, freq=988Hz, sample=84, buffer_id=10:54 [TRUNCATE prev:ch12 @77868.5ms -> 78052.3ms]
    db 0,0,100,0,96,90,17,5,184,7,96,17  ; n1553 t=78.052s dur=100ms, freq=1976Hz, sample=96, buffer_id=11:60 [TRUNCATE prev:ch5 @77779.0ms -> 78052.3ms]
    db 80,0,100,0,70,100,18,13,238,1,70,18  ; n1554 t=78.052s dur=100ms, freq=494Hz, sample=70, buffer_id=12:46 [TRUNCATE prev:ch13 @77779.0ms -> 78052.3ms]
    db 9,0,100,0,84,120,7,9,23,4,84,2  ; n1555 t=78.132s dur=100ms, freq=1047Hz, sample=84, buffer_id=02:54 [TRUNCATE prev:ch9 @77859.1ms -> 78132.4ms]
    db 0,0,100,0,84,110,16,1,23,4,84,16  ; n1556 t=78.142s dur=100ms, freq=1047Hz, sample=84, buffer_id=10:54 [TRUNCATE prev:ch1 @77868.5ms -> 78141.8ms]
    db 0,0,100,0,96,90,17,11,45,8,96,17  ; n1557 t=78.142s dur=100ms, freq=2093Hz, sample=96, buffer_id=11:60 [TRUNCATE prev:ch11 @77868.5ms -> 78141.8ms]
    db 80,0,100,0,70,100,18,2,11,2,70,18  ; n1558 t=78.142s dur=100ms, freq=523Hz, sample=70, buffer_id=12:46 [TRUNCATE prev:ch2 @77948.6ms -> 78141.8ms]
    db 9,0,100,0,86,120,7,3,151,4,86,2  ; n1559 t=78.222s dur=100ms, freq=1175Hz, sample=86, buffer_id=02:56 [TRUNCATE prev:ch3 @77958.0ms -> 78221.9ms]
    db 0,0,100,0,84,110,16,12,151,4,84,16  ; n1560 t=78.231s dur=100ms, freq=1175Hz, sample=84, buffer_id=10:54 [TRUNCATE prev:ch12 @78052.3ms -> 78231.3ms]
    db 0,0,100,0,96,90,17,5,45,9,96,17  ; n1561 t=78.231s dur=100ms, freq=2349Hz, sample=96, buffer_id=11:60 [TRUNCATE prev:ch5 @78052.3ms -> 78231.3ms]
    db 28,0,100,0,77,100,18,6,75,2,77,18  ; n1562 t=78.231s dur=100ms, freq=587Hz, sample=77, buffer_id=12:4D [TRUNCATE prev:ch6 @77958.0ms -> 78231.3ms]
    db 52,0,131,0,60,120,11,10,6,1,60,2  ; n1563 t=78.260s dur=131ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 9,0,100,0,86,120,7,7,39,5,86,2  ; n1564 t=78.311s dur=100ms, freq=1319Hz, sample=86, buffer_id=02:56 [TRUNCATE prev:ch7 @78024.0ms -> 78311.4ms]
    db 0,0,100,0,89,110,16,0,39,5,89,16  ; n1565 t=78.321s dur=100ms, freq=1319Hz, sample=89, buffer_id=10:59 [TRUNCATE prev:ch0 @78033.4ms -> 78320.8ms]
    db 0,0,100,0,101,90,17,8,77,10,101,17  ; n1566 t=78.321s dur=100ms, freq=2637Hz, sample=101, buffer_id=11:65 [TRUNCATE prev:ch8 @78033.4ms -> 78320.8ms]
    db 80,0,100,0,77,100,18,4,147,2,77,18  ; n1567 t=78.321s dur=100ms, freq=659Hz, sample=77, buffer_id=12:4D [TRUNCATE prev:ch4 @78042.8ms -> 78320.8ms]
    db 9,0,100,0,91,120,7,13,117,5,91,2  ; n1568 t=78.401s dur=100ms, freq=1397Hz, sample=91, buffer_id=02:5B
    db 0,0,100,0,89,110,16,9,117,5,89,16  ; n1569 t=78.410s dur=100ms, freq=1397Hz, sample=89, buffer_id=10:59 [TRUNCATE prev:ch9 @78132.4ms -> 78410.3ms]
    db 0,0,100,0,101,90,17,1,234,10,101,17  ; n1570 t=78.410s dur=100ms, freq=2794Hz, sample=101, buffer_id=11:65 [TRUNCATE prev:ch1 @78141.8ms -> 78410.3ms]
    db 66,0,100,0,77,100,18,6,186,2,77,18  ; n1571 t=78.410s dur=100ms, freq=698Hz, sample=77, buffer_id=12:4D [TRUNCATE prev:ch6 @78231.3ms -> 78410.3ms]
    db 9,0,169,0,36,120,2,2,65,0,36,2  ; n1572 t=78.476s dur=169ms, freq=65Hz, sample=36, buffer_id=02:24
    db 0,0,131,0,60,120,11,11,6,1,60,2  ; n1573 t=78.486s dur=131ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 9,0,169,0,48,115,13,3,131,0,48,2  ; n1574 t=78.486s dur=169ms, freq=131Hz, sample=48, buffer_id=02:30 [TRUNCATE prev:ch3 @78221.9ms -> 78485.7ms]
    db 9,0,100,0,91,120,7,5,32,6,91,2  ; n1575 t=78.495s dur=100ms, freq=1568Hz, sample=91, buffer_id=02:5B [TRUNCATE prev:ch5 @78231.3ms -> 78495.1ms]
    db 0,0,100,0,89,110,16,0,32,6,89,16  ; n1576 t=78.504s dur=100ms, freq=1568Hz, sample=89, buffer_id=10:59 [TRUNCATE prev:ch0 @78320.8ms -> 78504.5ms]
    db 0,0,100,0,101,90,17,8,64,12,101,17  ; n1577 t=78.504s dur=100ms, freq=3136Hz, sample=101, buffer_id=11:65 [TRUNCATE prev:ch8 @78320.8ms -> 78504.5ms]
    db 196,1,100,0,77,100,18,4,16,3,77,18  ; n1578 t=78.504s dur=100ms, freq=784Hz, sample=77, buffer_id=12:4D [TRUNCATE prev:ch4 @78320.8ms -> 78504.5ms]
    db 0,0,179,0,77,110,16,0,147,2,77,16  ; n1579 t=78.957s dur=179ms, freq=659Hz, sample=77, buffer_id=10:4D
    db 5,0,179,0,73,110,16,1,11,2,73,16  ; n1580 t=78.957s dur=179ms, freq=523Hz, sample=73, buffer_id=10:49
    db 0,0,179,0,62,124,5,2,74,1,62,5  ; n1581 t=78.962s dur=179ms, freq=330Hz, sample=62, buffer_id=05:3E
    db 0,0,179,0,50,124,14,3,165,0,50,14  ; n1582 t=78.962s dur=179ms, freq=165Hz, sample=50, buffer_id=0E:32
    db 93,1,100,0,91,100,20,4,39,5,91,20  ; n1583 t=78.962s dur=100ms, freq=1319Hz, sample=91, buffer_id=14:5B
    db 0,0,100,0,77,110,16,4,186,2,77,16  ; n1584 t=79.310s dur=100ms, freq=698Hz, sample=77, buffer_id=10:4D
    db 5,0,100,0,73,110,16,5,75,2,73,16  ; n1585 t=79.310s dur=100ms, freq=587Hz, sample=73, buffer_id=10:49
    db 0,0,100,0,67,124,5,6,93,1,67,5  ; n1586 t=79.315s dur=100ms, freq=349Hz, sample=67, buffer_id=05:43
    db 0,0,100,0,55,124,14,7,175,0,55,14  ; n1587 t=79.315s dur=100ms, freq=175Hz, sample=55, buffer_id=0E:37
    db 66,0,100,0,91,100,20,8,117,5,91,20  ; n1588 t=79.315s dur=100ms, freq=1397Hz, sample=91, buffer_id=14:5B
    db 10,0,169,0,36,120,2,0,65,0,36,2  ; n1589 t=79.381s dur=169ms, freq=65Hz, sample=36, buffer_id=02:24
    db 0,0,100,0,60,120,11,1,6,1,60,2  ; n1590 t=79.390s dur=100ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 19,0,169,0,48,115,13,2,131,0,48,2  ; n1591 t=79.390s dur=169ms, freq=131Hz, sample=48, buffer_id=02:30
    db 0,0,100,0,77,110,16,3,16,3,77,16  ; n1592 t=79.409s dur=100ms, freq=784Hz, sample=77, buffer_id=10:4D
    db 5,0,100,0,77,110,16,9,147,2,77,16  ; n1593 t=79.409s dur=100ms, freq=659Hz, sample=77, buffer_id=10:4D
    db 0,0,113,0,36,120,1,10,65,0,36,1  ; n1594 t=79.414s dur=113ms, freq=65Hz, sample=36, buffer_id=01:24
    db 0,0,100,0,67,124,5,11,136,1,67,5  ; n1595 t=79.414s dur=100ms, freq=392Hz, sample=67, buffer_id=05:43
    db 0,0,100,0,55,124,14,12,196,0,55,14  ; n1596 t=79.414s dur=100ms, freq=196Hz, sample=55, buffer_id=0E:37
    db 250,0,100,0,91,100,20,13,32,6,91,20  ; n1597 t=79.414s dur=100ms, freq=1568Hz, sample=91, buffer_id=14:5B
    db 0,0,249,3,84,110,16,4,23,4,84,16  ; n1598 t=79.663s dur=1017ms, freq=1047Hz, sample=84, buffer_id=10:54
    db 5,0,249,3,77,110,16,5,147,2,77,16  ; n1599 t=79.663s dur=1017ms, freq=659Hz, sample=77, buffer_id=10:4D
    db 0,0,249,3,72,124,5,6,11,2,72,5  ; n1600 t=79.668s dur=1017ms, freq=523Hz, sample=72, buffer_id=05:48
    db 0,0,249,3,60,124,14,7,6,1,60,14  ; n1601 t=79.668s dur=1017ms, freq=262Hz, sample=60, buffer_id=0E:3C
    db 165,0,100,0,91,100,20,8,45,8,91,20  ; n1602 t=79.668s dur=100ms, freq=2093Hz, sample=91, buffer_id=14:5B [TRUNCATE prev:ch8 @79314.9ms -> 79668.2ms]
    db 10,0,169,0,36,120,2,1,65,0,36,2  ; n1603 t=79.833s dur=169ms, freq=65Hz, sample=36, buffer_id=02:24
    db 0,0,100,0,60,120,11,0,6,1,60,2  ; n1604 t=79.843s dur=100ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 23,0,169,0,48,115,13,3,131,0,48,2  ; n1605 t=79.843s dur=169ms, freq=131Hz, sample=48, buffer_id=02:30
    db 163,1,113,0,36,120,1,2,65,0,36,1  ; n1606 t=79.866s dur=113ms, freq=65Hz, sample=36, buffer_id=01:24
    db 9,0,169,0,36,120,2,0,65,0,36,2  ; n1607 t=80.285s dur=169ms, freq=65Hz, sample=36, buffer_id=02:24
    db 0,0,100,0,60,120,11,1,6,1,60,2  ; n1608 t=80.295s dur=100ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 24,0,169,0,48,115,13,2,131,0,48,2  ; n1609 t=80.295s dur=169ms, freq=131Hz, sample=48, buffer_id=02:30
    db 203,0,113,0,36,120,1,3,65,0,36,1  ; n1610 t=80.318s dur=113ms, freq=65Hz, sample=36, buffer_id=01:24
    db 113,0,100,0,60,120,11,8,6,1,60,2  ; n1611 t=80.521s dur=100ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 104,0,100,0,60,120,11,3,6,1,60,2  ; n1612 t=80.634s dur=100ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 9,0,169,0,36,120,2,1,65,0,36,2  ; n1613 t=80.738s dur=169ms, freq=65Hz, sample=36, buffer_id=02:24
    db 0,0,100,0,60,120,11,0,6,1,60,2  ; n1614 t=80.747s dur=100ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 19,0,169,0,48,115,13,9,131,0,48,2  ; n1615 t=80.747s dur=169ms, freq=131Hz, sample=48, buffer_id=02:30
    db 0,0,113,0,73,110,16,2,75,2,73,16  ; n1616 t=80.766s dur=113ms, freq=587Hz, sample=73, buffer_id=10:49
    db 5,0,113,0,77,110,16,10,186,2,77,16  ; n1617 t=80.766s dur=113ms, freq=698Hz, sample=77, buffer_id=10:4D
    db 0,0,113,0,36,120,1,11,65,0,36,1  ; n1618 t=80.771s dur=113ms, freq=65Hz, sample=36, buffer_id=01:24
    db 0,0,113,0,62,124,5,12,38,1,62,5  ; n1619 t=80.771s dur=113ms, freq=294Hz, sample=62, buffer_id=05:3E
    db 0,0,113,0,50,124,14,13,147,0,50,14  ; n1620 t=80.771s dur=113ms, freq=147Hz, sample=50, buffer_id=0E:32
    db 90,0,100,0,84,100,20,4,151,4,84,20  ; n1621 t=80.771s dur=100ms, freq=1175Hz, sample=84, buffer_id=14:54 [TRUNCATE prev:ch4 @79663.5ms -> 80770.7ms]
    db 3,1,100,0,60,120,11,8,6,1,60,2  ; n1622 t=80.860s dur=100ms, freq=262Hz, sample=60, buffer_id=02:3C [TRUNCATE prev:ch8 @80521.0ms -> 80860.2ms]
    db 0,0,100,0,77,110,16,0,147,2,77,16  ; n1623 t=81.119s dur=100ms, freq=659Hz, sample=77, buffer_id=10:4D
    db 5,0,100,0,77,110,16,1,16,3,77,16  ; n1624 t=81.119s dur=100ms, freq=784Hz, sample=77, buffer_id=10:4D
    db 0,0,100,0,62,124,5,2,74,1,62,5  ; n1625 t=81.124s dur=100ms, freq=330Hz, sample=62, buffer_id=05:3E
    db 0,0,100,0,50,124,14,3,165,0,50,14  ; n1626 t=81.124s dur=100ms, freq=165Hz, sample=50, buffer_id=0E:32
    db 66,0,100,0,91,100,20,4,39,5,91,20  ; n1627 t=81.124s dur=100ms, freq=1319Hz, sample=91, buffer_id=14:5B
    db 9,0,169,0,36,120,2,5,65,0,36,2  ; n1628 t=81.190s dur=169ms, freq=65Hz, sample=36, buffer_id=02:24
    db 0,0,100,0,60,120,11,6,6,1,60,2  ; n1629 t=81.199s dur=100ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 19,0,169,0,48,115,13,7,131,0,48,2  ; n1630 t=81.199s dur=169ms, freq=131Hz, sample=48, buffer_id=02:30
    db 0,0,219,4,77,110,16,8,186,2,77,16  ; n1631 t=81.218s dur=1243ms, freq=698Hz, sample=77, buffer_id=10:4D
    db 5,0,219,4,84,110,16,9,112,3,84,16  ; n1632 t=81.218s dur=1243ms, freq=880Hz, sample=84, buffer_id=10:54
    db 0,0,113,0,36,120,1,10,65,0,36,1  ; n1633 t=81.223s dur=113ms, freq=65Hz, sample=36, buffer_id=01:24
    db 0,0,219,4,67,124,5,11,93,1,67,5  ; n1634 t=81.223s dur=1243ms, freq=349Hz, sample=67, buffer_id=05:43
    db 0,0,219,4,55,124,14,12,175,0,55,14  ; n1635 t=81.223s dur=1243ms, freq=175Hz, sample=55, buffer_id=0E:37
    db 163,1,100,0,91,100,20,13,117,5,91,20  ; n1636 t=81.223s dur=100ms, freq=1397Hz, sample=91, buffer_id=14:5B
    db 9,0,169,0,36,120,2,0,65,0,36,2  ; n1637 t=81.642s dur=169ms, freq=65Hz, sample=36, buffer_id=02:24
    db 0,0,100,0,60,120,11,1,6,1,60,2  ; n1638 t=81.652s dur=100ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 23,0,169,0,48,115,13,2,131,0,48,2  ; n1639 t=81.652s dur=169ms, freq=131Hz, sample=48, buffer_id=02:30
    db 163,1,113,0,36,120,1,3,65,0,36,1  ; n1640 t=81.675s dur=113ms, freq=65Hz, sample=36, buffer_id=01:24
    db 10,0,169,0,36,120,2,1,65,0,36,2  ; n1641 t=82.094s dur=169ms, freq=65Hz, sample=36, buffer_id=02:24
    db 0,0,100,0,60,120,11,0,6,1,60,2  ; n1642 t=82.104s dur=100ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 23,0,169,0,48,115,13,3,131,0,48,2  ; n1643 t=82.104s dur=169ms, freq=131Hz, sample=48, buffer_id=02:30
    db 203,0,113,0,36,120,1,2,65,0,36,1  ; n1644 t=82.127s dur=113ms, freq=65Hz, sample=36, buffer_id=01:24
    db 113,0,100,0,60,120,11,4,6,1,60,2  ; n1645 t=82.330s dur=100ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 104,0,100,0,60,120,11,2,6,1,60,2  ; n1646 t=82.443s dur=100ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 9,0,169,0,36,120,2,0,65,0,36,2  ; n1647 t=82.547s dur=169ms, freq=65Hz, sample=36, buffer_id=02:24
    db 0,0,100,0,60,120,11,1,6,1,60,2  ; n1648 t=82.556s dur=100ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 19,0,169,0,48,115,13,5,131,0,48,2  ; n1649 t=82.556s dur=169ms, freq=131Hz, sample=48, buffer_id=02:30
    db 0,0,179,0,77,110,16,3,16,3,77,16  ; n1650 t=82.575s dur=179ms, freq=784Hz, sample=77, buffer_id=10:4D
    db 5,0,179,0,73,110,16,6,75,2,73,16  ; n1651 t=82.575s dur=179ms, freq=587Hz, sample=73, buffer_id=10:49
    db 0,0,113,0,36,120,1,7,65,0,36,1  ; n1652 t=82.580s dur=113ms, freq=65Hz, sample=36, buffer_id=01:24
    db 0,0,179,0,67,124,5,10,136,1,67,5  ; n1653 t=82.580s dur=179ms, freq=392Hz, sample=67, buffer_id=05:43
    db 0,0,179,0,55,124,14,13,196,0,55,14  ; n1654 t=82.580s dur=179ms, freq=196Hz, sample=55, buffer_id=0E:37
    db 90,0,100,0,91,100,20,8,32,6,91,20  ; n1655 t=82.580s dur=100ms, freq=1568Hz, sample=91, buffer_id=14:5B [TRUNCATE prev:ch8 @81218.2ms -> 82579.8ms]
    db 3,1,100,0,60,120,11,9,6,1,60,2  ; n1656 t=82.669s dur=100ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 0,0,100,0,84,110,16,0,112,3,84,16  ; n1657 t=82.928s dur=100ms, freq=880Hz, sample=84, buffer_id=10:54
    db 5,0,100,0,77,110,16,1,147,2,77,16  ; n1658 t=82.928s dur=100ms, freq=659Hz, sample=77, buffer_id=10:4D
    db 0,0,100,0,67,124,5,2,184,1,67,5  ; n1659 t=82.933s dur=100ms, freq=440Hz, sample=67, buffer_id=05:43
    db 0,0,100,0,55,124,14,4,220,0,55,14  ; n1660 t=82.933s dur=100ms, freq=220Hz, sample=55, buffer_id=0E:37
    db 66,0,100,0,91,100,20,5,224,6,91,20  ; n1661 t=82.933s dur=100ms, freq=1760Hz, sample=91, buffer_id=14:5B
    db 9,0,169,0,36,120,2,3,65,0,36,2  ; n1662 t=82.999s dur=169ms, freq=65Hz, sample=36, buffer_id=02:24
    db 0,0,100,0,60,120,11,6,6,1,60,2  ; n1663 t=83.008s dur=100ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 19,0,169,0,48,115,13,7,131,0,48,2  ; n1664 t=83.008s dur=169ms, freq=131Hz, sample=48, buffer_id=02:30
    db 0,0,100,0,84,110,16,8,220,3,84,16  ; n1665 t=83.027s dur=100ms, freq=988Hz, sample=84, buffer_id=10:54
    db 5,0,100,0,77,110,16,9,186,2,77,16  ; n1666 t=83.027s dur=100ms, freq=698Hz, sample=77, buffer_id=10:4D
    db 0,0,113,0,36,120,1,10,65,0,36,1  ; n1667 t=83.032s dur=113ms, freq=65Hz, sample=36, buffer_id=01:24
    db 0,0,100,0,72,124,5,11,238,1,72,5  ; n1668 t=83.032s dur=100ms, freq=494Hz, sample=72, buffer_id=05:48
    db 0,0,100,0,60,124,14,12,247,0,60,14  ; n1669 t=83.032s dur=100ms, freq=247Hz, sample=60, buffer_id=0E:3C
    db 250,0,100,0,91,100,20,13,184,7,91,20  ; n1670 t=83.032s dur=100ms, freq=1976Hz, sample=91, buffer_id=14:5B
    db 0,0,249,3,89,110,16,0,117,5,89,16  ; n1671 t=83.282s dur=1017ms, freq=1397Hz, sample=89, buffer_id=10:59
    db 5,0,249,3,84,110,16,1,112,3,84,16  ; n1672 t=83.282s dur=1017ms, freq=880Hz, sample=84, buffer_id=10:54
    db 0,0,249,3,77,124,5,2,186,2,77,5  ; n1673 t=83.287s dur=1017ms, freq=698Hz, sample=77, buffer_id=05:4D
    db 0,0,249,3,65,124,14,4,93,1,65,14  ; n1674 t=83.287s dur=1017ms, freq=349Hz, sample=65, buffer_id=0E:41
    db 165,0,100,0,101,100,20,5,234,10,101,20  ; n1675 t=83.287s dur=100ms, freq=2794Hz, sample=101, buffer_id=14:65
    db 9,0,169,0,36,120,2,6,65,0,36,2  ; n1676 t=83.451s dur=169ms, freq=65Hz, sample=36, buffer_id=02:24
    db 0,0,100,0,60,120,11,3,6,1,60,2  ; n1677 t=83.461s dur=100ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 24,0,169,0,48,115,13,8,131,0,48,2  ; n1678 t=83.461s dur=169ms, freq=131Hz, sample=48, buffer_id=02:30
    db 163,1,113,0,36,120,1,7,65,0,36,1  ; n1679 t=83.484s dur=113ms, freq=65Hz, sample=36, buffer_id=01:24
    db 9,0,169,0,36,120,2,3,65,0,36,2  ; n1680 t=83.904s dur=169ms, freq=65Hz, sample=36, buffer_id=02:24
    db 0,0,100,0,60,120,11,5,6,1,60,2  ; n1681 t=83.913s dur=100ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 24,0,169,0,48,115,13,6,131,0,48,2  ; n1682 t=83.913s dur=169ms, freq=131Hz, sample=48, buffer_id=02:30
    db 203,0,113,0,36,120,1,8,65,0,36,1  ; n1683 t=83.937s dur=113ms, freq=65Hz, sample=36, buffer_id=01:24
    db 113,0,100,0,60,120,11,7,6,1,60,2  ; n1684 t=84.139s dur=100ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 104,0,100,0,60,120,11,8,6,1,60,2  ; n1685 t=84.252s dur=100ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 9,0,169,0,36,120,2,5,65,0,36,2  ; n1686 t=84.356s dur=169ms, freq=65Hz, sample=36, buffer_id=02:24
    db 0,0,100,0,60,120,11,3,6,1,60,2  ; n1687 t=84.365s dur=100ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 19,0,169,0,48,115,13,9,131,0,48,2  ; n1688 t=84.365s dur=169ms, freq=131Hz, sample=48, buffer_id=02:30
    db 0,0,113,0,84,110,16,6,112,3,84,16  ; n1689 t=84.384s dur=113ms, freq=880Hz, sample=84, buffer_id=10:54
    db 5,0,113,0,77,110,16,10,186,2,77,16  ; n1690 t=84.384s dur=113ms, freq=698Hz, sample=77, buffer_id=10:4D
    db 0,0,113,0,36,120,1,11,65,0,36,1  ; n1691 t=84.389s dur=113ms, freq=65Hz, sample=36, buffer_id=01:24
    db 0,0,113,0,67,124,5,12,184,1,67,5  ; n1692 t=84.389s dur=113ms, freq=440Hz, sample=67, buffer_id=05:43
    db 0,0,113,0,55,124,14,13,220,0,55,14  ; n1693 t=84.389s dur=113ms, freq=220Hz, sample=55, buffer_id=0E:37
    db 90,0,100,0,91,100,20,0,224,6,91,20  ; n1694 t=84.389s dur=100ms, freq=1760Hz, sample=91, buffer_id=14:5B [TRUNCATE prev:ch0 @83281.8ms -> 84388.9ms]
    db 3,1,100,0,60,120,11,7,6,1,60,2  ; n1695 t=84.478s dur=100ms, freq=262Hz, sample=60, buffer_id=02:3C [TRUNCATE prev:ch7 @84139.2ms -> 84478.5ms]
    db 0,0,100,0,84,110,16,0,220,3,84,16  ; n1696 t=84.738s dur=100ms, freq=988Hz, sample=84, buffer_id=10:54
    db 5,0,100,0,77,110,16,1,16,3,77,16  ; n1697 t=84.738s dur=100ms, freq=784Hz, sample=77, buffer_id=10:4D
    db 0,0,100,0,72,124,5,2,238,1,72,5  ; n1698 t=84.742s dur=100ms, freq=494Hz, sample=72, buffer_id=05:48
    db 0,0,100,0,60,124,14,3,247,0,60,14  ; n1699 t=84.742s dur=100ms, freq=247Hz, sample=60, buffer_id=0E:3C
    db 66,0,100,0,91,100,20,4,184,7,91,20  ; n1700 t=84.742s dur=100ms, freq=1976Hz, sample=91, buffer_id=14:5B
    db 9,0,169,0,36,120,2,6,65,0,36,2  ; n1701 t=84.808s dur=169ms, freq=65Hz, sample=36, buffer_id=02:24
    db 0,0,100,0,60,120,11,5,6,1,60,2  ; n1702 t=84.818s dur=100ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 19,0,169,0,48,115,13,7,131,0,48,2  ; n1703 t=84.818s dur=169ms, freq=131Hz, sample=48, buffer_id=02:30
    db 0,0,80,1,84,110,16,8,23,4,84,16  ; n1704 t=84.837s dur=336ms, freq=1047Hz, sample=84, buffer_id=10:54
    db 5,0,80,1,77,110,16,9,147,2,77,16  ; n1705 t=84.837s dur=336ms, freq=659Hz, sample=77, buffer_id=10:4D
    db 0,0,113,0,36,120,1,10,65,0,36,1  ; n1706 t=84.841s dur=113ms, freq=65Hz, sample=36, buffer_id=01:24
    db 0,0,80,1,72,124,5,11,11,2,72,5  ; n1707 t=84.841s dur=336ms, freq=523Hz, sample=72, buffer_id=05:48
    db 0,0,80,1,60,124,14,12,6,1,60,14  ; n1708 t=84.841s dur=336ms, freq=262Hz, sample=60, buffer_id=0E:3C
    db 163,1,100,0,91,100,20,13,45,8,91,20  ; n1709 t=84.841s dur=100ms, freq=2093Hz, sample=91, buffer_id=14:5B
    db 10,0,169,0,36,120,2,0,65,0,36,2  ; n1710 t=85.260s dur=169ms, freq=65Hz, sample=36, buffer_id=02:24
    db 0,0,100,0,60,120,11,1,6,1,60,2  ; n1711 t=85.270s dur=100ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 19,0,169,0,48,115,13,2,131,0,48,2  ; n1712 t=85.270s dur=169ms, freq=131Hz, sample=48, buffer_id=02:30
    db 0,0,80,1,84,110,16,3,151,4,84,16  ; n1713 t=85.289s dur=336ms, freq=1175Hz, sample=84, buffer_id=10:54
    db 5,0,80,1,77,110,16,4,16,3,77,16  ; n1714 t=85.289s dur=336ms, freq=784Hz, sample=77, buffer_id=10:4D
    db 0,0,113,0,36,120,1,5,65,0,36,1  ; n1715 t=85.293s dur=113ms, freq=65Hz, sample=36, buffer_id=01:24
    db 0,0,226,0,67,124,5,6,136,1,67,5  ; n1716 t=85.293s dur=226ms, freq=392Hz, sample=67, buffer_id=05:43
    db 0,0,80,1,72,124,5,7,75,2,72,5  ; n1717 t=85.293s dur=336ms, freq=587Hz, sample=72, buffer_id=05:48
    db 0,0,80,1,60,124,14,10,38,1,60,14  ; n1718 t=85.293s dur=336ms, freq=294Hz, sample=60, buffer_id=0E:3C
    db 0,0,80,1,55,124,14,13,196,0,55,14  ; n1719 t=85.293s dur=336ms, freq=196Hz, sample=55, buffer_id=0E:37
    db 163,1,100,0,101,100,20,8,45,9,101,20  ; n1720 t=85.293s dur=100ms, freq=2349Hz, sample=101, buffer_id=14:65 [TRUNCATE prev:ch8 @84836.5ms -> 85293.5ms]
    db 9,0,169,0,36,120,2,1,65,0,36,2  ; n1721 t=85.713s dur=169ms, freq=65Hz, sample=36, buffer_id=02:24
    db 0,0,100,0,60,120,11,0,6,1,60,2  ; n1722 t=85.722s dur=100ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 19,0,169,0,48,115,13,5,131,0,48,2  ; n1723 t=85.722s dur=169ms, freq=131Hz, sample=48, buffer_id=02:30
    db 0,0,169,0,89,110,16,2,39,5,89,16  ; n1724 t=85.741s dur=169ms, freq=1319Hz, sample=89, buffer_id=10:59
    db 5,0,169,0,84,110,16,6,23,4,84,16  ; n1725 t=85.741s dur=169ms, freq=1047Hz, sample=84, buffer_id=10:54
    db 0,0,113,0,36,120,1,8,65,0,36,1  ; n1726 t=85.746s dur=113ms, freq=65Hz, sample=36, buffer_id=01:24
    db 0,0,169,0,77,124,5,9,147,2,77,5  ; n1727 t=85.746s dur=169ms, freq=659Hz, sample=77, buffer_id=05:4D
    db 0,0,169,0,72,124,5,12,11,2,72,5  ; n1728 t=85.746s dur=169ms, freq=523Hz, sample=72, buffer_id=05:48
    db 0,0,169,0,65,124,14,11,74,1,65,14  ; n1729 t=85.746s dur=169ms, freq=330Hz, sample=65, buffer_id=0E:41
    db 0,0,169,0,60,124,14,10,6,1,60,14  ; n1730 t=85.746s dur=169ms, freq=262Hz, sample=60, buffer_id=0E:3C [TRUNCATE prev:ch10 @85293.5ms -> 85745.8ms]
    db 203,0,100,0,101,100,20,3,77,10,101,20  ; n1731 t=85.746s dur=100ms, freq=2637Hz, sample=101, buffer_id=14:65 [TRUNCATE prev:ch3 @85288.8ms -> 85745.8ms]
    db 113,0,100,0,60,120,11,4,6,1,60,2  ; n1732 t=85.948s dur=100ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 104,0,100,0,60,120,11,3,6,1,60,2  ; n1733 t=86.061s dur=100ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 9,0,153,0,29,120,2,0,49,0,29,2  ; n1734 t=86.165s dur=153ms, freq=49Hz, sample=29, buffer_id=02:1D
    db 0,0,100,0,60,120,11,1,6,1,60,2  ; n1735 t=86.174s dur=100ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 19,0,169,0,43,115,13,2,98,0,43,2  ; n1736 t=86.174s dur=169ms, freq=98Hz, sample=43, buffer_id=02:2B
    db 0,0,179,0,77,110,16,5,147,2,77,16  ; n1737 t=86.193s dur=179ms, freq=659Hz, sample=77, buffer_id=10:4D
    db 5,0,179,0,73,110,16,6,11,2,73,16  ; n1738 t=86.193s dur=179ms, freq=523Hz, sample=73, buffer_id=10:49
    db 0,0,113,0,31,120,1,7,49,0,31,1  ; n1739 t=86.198s dur=113ms, freq=49Hz, sample=31, buffer_id=01:1F
    db 0,0,179,0,62,124,5,8,74,1,62,5  ; n1740 t=86.198s dur=179ms, freq=330Hz, sample=62, buffer_id=05:3E
    db 0,0,179,0,62,124,5,9,6,1,62,5  ; n1741 t=86.198s dur=179ms, freq=262Hz, sample=62, buffer_id=05:3E
    db 0,0,179,0,50,124,14,10,165,0,50,14  ; n1742 t=86.198s dur=179ms, freq=165Hz, sample=50, buffer_id=0E:32
    db 0,0,179,0,50,124,14,11,131,0,50,14  ; n1743 t=86.198s dur=179ms, freq=131Hz, sample=50, buffer_id=0E:32
    db 90,0,100,0,91,100,20,12,39,5,91,20  ; n1744 t=86.198s dur=100ms, freq=1319Hz, sample=91, buffer_id=14:5B
    db 3,1,100,0,60,120,11,13,6,1,60,2  ; n1745 t=86.288s dur=100ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 0,0,100,0,77,110,16,0,186,2,77,16  ; n1746 t=86.547s dur=100ms, freq=698Hz, sample=77, buffer_id=10:4D
    db 5,0,100,0,73,110,16,1,75,2,73,16  ; n1747 t=86.547s dur=100ms, freq=587Hz, sample=73, buffer_id=10:49
    db 0,0,100,0,67,124,5,2,93,1,67,5  ; n1748 t=86.551s dur=100ms, freq=349Hz, sample=67, buffer_id=05:43
    db 0,0,100,0,62,124,5,3,38,1,62,5  ; n1749 t=86.551s dur=100ms, freq=294Hz, sample=62, buffer_id=05:3E
    db 0,0,100,0,55,124,14,4,175,0,55,14  ; n1750 t=86.551s dur=100ms, freq=175Hz, sample=55, buffer_id=0E:37
    db 0,0,100,0,50,124,14,7,147,0,50,14  ; n1751 t=86.551s dur=100ms, freq=147Hz, sample=50, buffer_id=0E:32
    db 66,0,100,0,91,100,20,12,117,5,91,20  ; n1752 t=86.551s dur=100ms, freq=1397Hz, sample=91, buffer_id=14:5B [TRUNCATE prev:ch12 @86198.1ms -> 86551.4ms]
    db 9,0,169,0,36,120,2,5,65,0,36,2  ; n1753 t=86.617s dur=169ms, freq=65Hz, sample=36, buffer_id=02:24
    db 0,0,100,0,60,120,11,6,6,1,60,2  ; n1754 t=86.627s dur=100ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 19,0,169,0,48,115,13,8,131,0,48,2  ; n1755 t=86.627s dur=169ms, freq=131Hz, sample=48, buffer_id=02:30
    db 0,0,100,0,77,110,16,9,16,3,77,16  ; n1756 t=86.646s dur=100ms, freq=784Hz, sample=77, buffer_id=10:4D
    db 5,0,100,0,77,110,16,10,147,2,77,16  ; n1757 t=86.646s dur=100ms, freq=659Hz, sample=77, buffer_id=10:4D
    db 0,0,113,0,36,120,1,11,65,0,36,1  ; n1758 t=86.650s dur=113ms, freq=65Hz, sample=36, buffer_id=01:24
    db 0,0,100,0,67,124,5,13,136,1,67,5  ; n1759 t=86.650s dur=100ms, freq=392Hz, sample=67, buffer_id=05:43
    db 0,0,100,0,62,124,5,0,74,1,62,5  ; n1760 t=86.650s dur=100ms, freq=330Hz, sample=62, buffer_id=05:3E [TRUNCATE prev:ch0 @86546.7ms -> 86650.4ms]
    db 0,0,100,0,55,124,14,1,196,0,55,14  ; n1761 t=86.650s dur=100ms, freq=196Hz, sample=55, buffer_id=0E:37 [TRUNCATE prev:ch1 @86546.7ms -> 86650.4ms]
    db 0,0,100,0,50,124,14,2,165,0,50,14  ; n1762 t=86.650s dur=100ms, freq=165Hz, sample=50, buffer_id=0E:32 [TRUNCATE prev:ch2 @86551.4ms -> 86650.4ms]
    db 250,0,100,0,91,100,20,3,32,6,91,20  ; n1763 t=86.650s dur=100ms, freq=1568Hz, sample=91, buffer_id=14:5B [TRUNCATE prev:ch3 @86551.4ms -> 86650.4ms]
    db 0,0,249,3,84,110,16,4,23,4,84,16  ; n1764 t=86.900s dur=1017ms, freq=1047Hz, sample=84, buffer_id=10:54
    db 5,0,249,3,77,110,16,7,147,2,77,16  ; n1765 t=86.900s dur=1017ms, freq=659Hz, sample=77, buffer_id=10:4D
    db 0,0,249,3,72,124,5,12,11,2,72,5  ; n1766 t=86.905s dur=1017ms, freq=523Hz, sample=72, buffer_id=05:48
    db 0,0,249,3,67,124,5,13,136,1,67,5  ; n1767 t=86.905s dur=1017ms, freq=392Hz, sample=67, buffer_id=05:43 [TRUNCATE prev:ch13 @86650.4ms -> 86904.8ms]
    db 0,0,249,3,60,124,14,5,6,1,60,14  ; n1768 t=86.905s dur=1017ms, freq=262Hz, sample=60, buffer_id=0E:3C [TRUNCATE prev:ch5 @86617.4ms -> 86904.8ms]
    db 0,0,249,3,55,124,14,1,196,0,55,14  ; n1769 t=86.905s dur=1017ms, freq=196Hz, sample=55, buffer_id=0E:37 [TRUNCATE prev:ch1 @86650.4ms -> 86904.8ms]
    db 165,0,100,0,91,100,20,3,45,8,91,20  ; n1770 t=86.905s dur=100ms, freq=2093Hz, sample=91, buffer_id=14:5B [TRUNCATE prev:ch3 @86650.4ms -> 86904.8ms]
    db 9,0,169,0,36,120,2,0,65,0,36,2  ; n1771 t=87.070s dur=169ms, freq=65Hz, sample=36, buffer_id=02:24
    db 0,0,100,0,60,120,11,2,6,1,60,2  ; n1772 t=87.079s dur=100ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 24,0,169,0,48,115,13,6,131,0,48,2  ; n1773 t=87.079s dur=169ms, freq=131Hz, sample=48, buffer_id=02:30
    db 163,1,113,0,36,120,1,8,65,0,36,1  ; n1774 t=87.103s dur=113ms, freq=65Hz, sample=36, buffer_id=01:24
    db 9,0,169,0,36,120,2,2,65,0,36,2  ; n1775 t=87.522s dur=169ms, freq=65Hz, sample=36, buffer_id=02:24
    db 0,0,100,0,60,120,11,0,6,1,60,2  ; n1776 t=87.531s dur=100ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 23,0,169,0,48,115,13,3,131,0,48,2  ; n1777 t=87.531s dur=169ms, freq=131Hz, sample=48, buffer_id=02:30
    db 203,0,113,0,36,120,1,6,65,0,36,1  ; n1778 t=87.555s dur=113ms, freq=65Hz, sample=36, buffer_id=01:24
    db 113,0,100,0,60,120,11,8,6,1,60,2  ; n1779 t=87.757s dur=100ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 104,0,100,0,60,120,11,6,6,1,60,2  ; n1780 t=87.871s dur=100ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 10,0,169,0,36,120,2,0,65,0,36,2  ; n1781 t=87.974s dur=169ms, freq=65Hz, sample=36, buffer_id=02:24
    db 0,0,100,0,60,120,11,2,6,1,60,2  ; n1782 t=87.984s dur=100ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 19,0,169,0,48,115,13,9,131,0,48,2  ; n1783 t=87.984s dur=169ms, freq=131Hz, sample=48, buffer_id=02:30
    db 0,0,113,0,84,110,16,3,151,4,84,16  ; n1784 t=88.002s dur=113ms, freq=1175Hz, sample=84, buffer_id=10:54
    db 5,0,113,0,77,110,16,11,186,2,77,16  ; n1785 t=88.002s dur=113ms, freq=698Hz, sample=77, buffer_id=10:4D
    db 0,0,113,0,36,120,1,10,65,0,36,1  ; n1786 t=88.007s dur=113ms, freq=65Hz, sample=36, buffer_id=01:24
    db 0,0,113,0,72,124,5,12,75,2,72,5  ; n1787 t=88.007s dur=113ms, freq=587Hz, sample=72, buffer_id=05:48 [TRUNCATE prev:ch12 @86904.8ms -> 88007.2ms]
    db 0,0,113,0,72,124,5,4,238,1,72,5  ; n1788 t=88.007s dur=113ms, freq=494Hz, sample=72, buffer_id=05:48 [TRUNCATE prev:ch4 @86900.1ms -> 88007.2ms]
    db 0,0,113,0,60,124,14,5,38,1,60,14  ; n1789 t=88.007s dur=113ms, freq=294Hz, sample=60, buffer_id=0E:3C [TRUNCATE prev:ch5 @86904.8ms -> 88007.2ms]
    db 0,0,113,0,60,124,14,7,247,0,60,14  ; n1790 t=88.007s dur=113ms, freq=247Hz, sample=60, buffer_id=0E:3C [TRUNCATE prev:ch7 @86900.1ms -> 88007.2ms]
    db 90,0,100,0,101,100,20,1,45,9,101,20  ; n1791 t=88.007s dur=100ms, freq=2349Hz, sample=101, buffer_id=14:65 [TRUNCATE prev:ch1 @86904.8ms -> 88007.2ms]
    db 3,1,100,0,60,120,11,8,6,1,60,2  ; n1792 t=88.097s dur=100ms, freq=262Hz, sample=60, buffer_id=02:3C [TRUNCATE prev:ch8 @87757.5ms -> 88096.7ms]
    db 0,0,100,0,89,110,16,0,39,5,89,16  ; n1793 t=88.356s dur=100ms, freq=1319Hz, sample=89, buffer_id=10:59
    db 5,0,100,0,77,110,16,1,16,3,77,16  ; n1794 t=88.356s dur=100ms, freq=784Hz, sample=77, buffer_id=10:4D
    db 0,0,100,0,77,124,5,2,147,2,77,5  ; n1795 t=88.361s dur=100ms, freq=659Hz, sample=77, buffer_id=05:4D
    db 0,0,100,0,72,124,5,3,11,2,72,5  ; n1796 t=88.361s dur=100ms, freq=523Hz, sample=72, buffer_id=05:48
    db 0,0,100,0,65,124,14,4,74,1,65,14  ; n1797 t=88.361s dur=100ms, freq=330Hz, sample=65, buffer_id=0E:41
    db 0,0,100,0,60,124,14,6,6,1,60,14  ; n1798 t=88.361s dur=100ms, freq=262Hz, sample=60, buffer_id=0E:3C
    db 66,0,100,0,101,100,20,5,77,10,101,20  ; n1799 t=88.361s dur=100ms, freq=2637Hz, sample=101, buffer_id=14:65
    db 9,0,169,0,36,120,2,7,69,0,36,2  ; n1800 t=88.427s dur=169ms, freq=69Hz, sample=36, buffer_id=02:24
    db 0,0,100,0,61,120,11,8,21,1,61,2  ; n1801 t=88.436s dur=100ms, freq=277Hz, sample=61, buffer_id=02:3D
    db 19,0,169,0,48,115,13,10,139,0,48,2  ; n1802 t=88.436s dur=169ms, freq=139Hz, sample=48, buffer_id=02:30
    db 0,0,219,4,89,110,16,9,117,5,89,16  ; n1803 t=88.455s dur=1243ms, freq=1397Hz, sample=89, buffer_id=10:59
    db 5,0,22,4,77,110,16,12,63,3,77,16  ; n1804 t=88.455s dur=1046ms, freq=831Hz, sample=77, buffer_id=10:4D
    db 0,0,113,0,36,120,1,11,69,0,36,1  ; n1805 t=88.460s dur=113ms, freq=69Hz, sample=36, buffer_id=01:24
    db 0,0,219,4,77,124,5,13,186,2,77,5  ; n1806 t=88.460s dur=1243ms, freq=698Hz, sample=77, buffer_id=05:4D
    db 0,0,219,4,72,124,5,0,42,2,72,5  ; n1807 t=88.460s dur=1243ms, freq=554Hz, sample=72, buffer_id=05:48 [TRUNCATE prev:ch0 @88355.9ms -> 88459.5ms]
    db 0,0,219,4,65,124,14,1,93,1,65,14  ; n1808 t=88.460s dur=1243ms, freq=349Hz, sample=65, buffer_id=0E:41 [TRUNCATE prev:ch1 @88355.9ms -> 88459.5ms]
    db 0,0,219,4,60,124,14,2,21,1,60,14  ; n1809 t=88.460s dur=1243ms, freq=277Hz, sample=60, buffer_id=0E:3C [TRUNCATE prev:ch2 @88360.6ms -> 88459.5ms]
    db 203,0,100,0,101,100,20,3,234,10,101,20  ; n1810 t=88.460s dur=100ms, freq=2794Hz, sample=101, buffer_id=14:65 [TRUNCATE prev:ch3 @88360.6ms -> 88459.5ms]
    db 113,0,100,0,61,120,11,4,21,1,61,2  ; n1811 t=88.662s dur=100ms, freq=277Hz, sample=61, buffer_id=02:3D
    db 104,0,100,0,61,120,11,3,21,1,61,2  ; n1812 t=88.775s dur=100ms, freq=277Hz, sample=61, buffer_id=02:3D
    db 9,0,169,0,36,120,2,5,69,0,36,2  ; n1813 t=88.879s dur=169ms, freq=69Hz, sample=36, buffer_id=02:24
    db 0,0,100,0,61,120,11,6,21,1,61,2  ; n1814 t=88.888s dur=100ms, freq=277Hz, sample=61, buffer_id=02:3D
    db 10,0,169,0,48,115,13,7,139,0,48,2  ; n1815 t=88.888s dur=169ms, freq=139Hz, sample=48, buffer_id=02:30
    db 0,0,100,0,73,120,7,8,42,2,73,2  ; n1816 t=88.898s dur=100ms, freq=554Hz, sample=73, buffer_id=02:49
    db 14,0,100,0,61,120,9,10,21,1,61,2  ; n1817 t=88.898s dur=100ms, freq=277Hz, sample=61, buffer_id=02:3D
    db 33,0,113,0,36,120,1,11,69,0,36,1  ; n1818 t=88.912s dur=113ms, freq=69Hz, sample=36, buffer_id=01:24 [TRUNCATE prev:ch11 @88459.5ms -> 88911.8ms]
    db 0,0,100,0,75,120,7,9,110,2,75,2  ; n1819 t=88.945s dur=100ms, freq=622Hz, sample=75, buffer_id=02:4B [TRUNCATE prev:ch9 @88454.8ms -> 88944.8ms]
    db 52,0,100,0,63,120,9,12,55,1,63,2  ; n1820 t=88.945s dur=100ms, freq=311Hz, sample=63, buffer_id=02:3F [TRUNCATE prev:ch12 @88454.8ms -> 88944.8ms]
    db 0,0,100,0,75,120,7,4,186,2,75,2  ; n1821 t=88.997s dur=100ms, freq=698Hz, sample=75, buffer_id=02:4B
    db 5,0,100,0,65,120,9,0,93,1,65,2  ; n1822 t=88.997s dur=100ms, freq=349Hz, sample=65, buffer_id=02:41 [TRUNCATE prev:ch0 @88459.5ms -> 88996.6ms]
    db 47,0,100,0,61,120,11,3,21,1,61,2  ; n1823 t=89.001s dur=100ms, freq=277Hz, sample=61, buffer_id=02:3D [TRUNCATE prev:ch3 @88775.2ms -> 89001.3ms]
    db 0,0,100,0,79,120,7,1,16,3,79,2  ; n1824 t=89.048s dur=100ms, freq=784Hz, sample=79, buffer_id=02:4F [TRUNCATE prev:ch1 @88459.5ms -> 89048.4ms]
    db 47,0,100,0,67,120,9,2,136,1,67,2  ; n1825 t=89.048s dur=100ms, freq=392Hz, sample=67, buffer_id=02:43 [TRUNCATE prev:ch2 @88459.5ms -> 89048.4ms]
    db 0,0,100,0,79,120,7,13,63,3,79,2  ; n1826 t=89.096s dur=100ms, freq=831Hz, sample=79, buffer_id=02:4F [TRUNCATE prev:ch13 @88459.5ms -> 89095.5ms]
    db 52,0,100,0,67,120,9,5,159,1,67,2  ; n1827 t=89.096s dur=100ms, freq=415Hz, sample=67, buffer_id=02:43 [TRUNCATE prev:ch5 @88878.8ms -> 89095.5ms]
    db 0,0,100,0,84,120,7,6,164,3,84,2  ; n1828 t=89.147s dur=100ms, freq=932Hz, sample=84, buffer_id=02:54 [TRUNCATE prev:ch6 @88888.2ms -> 89147.4ms]
    db 52,0,100,0,71,120,9,7,210,1,71,2  ; n1829 t=89.147s dur=100ms, freq=466Hz, sample=71, buffer_id=02:47 [TRUNCATE prev:ch7 @88888.2ms -> 89147.4ms]
    db 0,0,100,0,84,120,7,8,23,4,84,2  ; n1830 t=89.199s dur=100ms, freq=1047Hz, sample=84, buffer_id=02:54
    db 47,0,100,0,72,120,9,10,11,2,72,2  ; n1831 t=89.199s dur=100ms, freq=523Hz, sample=72, buffer_id=02:48
    db 0,0,100,0,84,120,7,9,85,4,84,2  ; n1832 t=89.246s dur=100ms, freq=1109Hz, sample=84, buffer_id=02:54
    db 52,0,100,0,73,120,9,11,42,2,73,2  ; n1833 t=89.246s dur=100ms, freq=554Hz, sample=73, buffer_id=02:49
    db 0,0,100,0,86,120,7,0,221,4,86,2  ; n1834 t=89.298s dur=100ms, freq=1245Hz, sample=86, buffer_id=02:56
    db 33,0,100,0,75,120,9,12,110,2,75,2  ; n1835 t=89.298s dur=100ms, freq=622Hz, sample=75, buffer_id=02:4B
    db 9,0,169,0,36,120,2,3,69,0,36,2  ; n1836 t=89.331s dur=169ms, freq=69Hz, sample=36, buffer_id=02:24
    db 0,0,100,0,61,120,11,4,21,1,61,2  ; n1837 t=89.341s dur=100ms, freq=277Hz, sample=61, buffer_id=02:3D
    db 9,0,169,0,48,115,13,1,139,0,48,2  ; n1838 t=89.341s dur=169ms, freq=139Hz, sample=48, buffer_id=02:30 [TRUNCATE prev:ch1 @89048.4ms -> 89340.5ms]
    db 0,0,100,0,91,120,7,2,117,5,91,2  ; n1839 t=89.350s dur=100ms, freq=1397Hz, sample=91, buffer_id=02:5B
    db 14,0,100,0,75,120,9,5,186,2,75,2  ; n1840 t=89.350s dur=100ms, freq=698Hz, sample=75, buffer_id=02:4B [TRUNCATE prev:ch5 @89095.5ms -> 89349.9ms]
    db 173,1,113,0,36,120,1,13,69,0,36,1  ; n1841 t=89.364s dur=113ms, freq=69Hz, sample=36, buffer_id=01:24 [TRUNCATE prev:ch13 @89095.5ms -> 89364.1ms]
    db 5,0,113,0,56,120,11,0,196,0,56,2  ; n1842 t=89.793s dur=113ms, freq=196Hz, sample=56, buffer_id=02:38
    db 5,0,113,0,65,110,4,1,136,1,65,4  ; n1843 t=89.797s dur=113ms, freq=392Hz, sample=65, buffer_id=04:41
    db 0,0,113,0,91,120,7,3,32,6,91,2  ; n1844 t=89.802s dur=113ms, freq=1568Hz, sample=91, buffer_id=02:5B
    db 9,0,113,0,79,120,9,2,16,3,79,2  ; n1845 t=89.802s dur=113ms, freq=784Hz, sample=79, buffer_id=02:4F
    db 5,0,113,0,77,110,16,4,16,3,77,16  ; n1846 t=89.812s dur=113ms, freq=784Hz, sample=77, buffer_id=10:4D
    db 0,0,113,0,67,124,5,5,136,1,67,5  ; n1847 t=89.816s dur=113ms, freq=392Hz, sample=67, buffer_id=05:43
    db 0,0,113,0,55,124,14,6,196,0,55,14  ; n1848 t=89.816s dur=113ms, freq=196Hz, sample=55, buffer_id=0E:37
    db 74,1,100,0,91,100,20,7,32,6,91,20  ; n1849 t=89.816s dur=100ms, freq=1568Hz, sample=91, buffer_id=14:5B
    db 5,0,100,0,56,120,11,1,196,0,56,2  ; n1850 t=90.146s dur=100ms, freq=196Hz, sample=56, buffer_id=02:38
    db 5,0,100,0,65,110,4,0,136,1,65,4  ; n1851 t=90.151s dur=100ms, freq=392Hz, sample=65, buffer_id=04:41
    db 0,0,100,0,79,120,7,3,16,3,79,2  ; n1852 t=90.156s dur=100ms, freq=784Hz, sample=79, buffer_id=02:4F
    db 9,0,100,0,67,120,9,2,136,1,67,2  ; n1853 t=90.156s dur=100ms, freq=392Hz, sample=67, buffer_id=02:43
    db 5,0,100,0,77,110,16,5,16,3,77,16  ; n1854 t=90.165s dur=100ms, freq=784Hz, sample=77, buffer_id=10:4D
    db 0,0,100,0,67,124,5,4,136,1,67,5  ; n1855 t=90.170s dur=100ms, freq=392Hz, sample=67, buffer_id=05:43
    db 0,0,100,0,55,124,14,7,196,0,55,14  ; n1856 t=90.170s dur=100ms, freq=196Hz, sample=55, buffer_id=0E:37
    db 75,0,100,0,91,100,20,6,32,6,91,20  ; n1857 t=90.170s dur=100ms, freq=1568Hz, sample=91, buffer_id=14:5B
    db 5,0,149,1,63,120,11,8,74,1,63,2  ; n1858 t=90.245s dur=405ms, freq=330Hz, sample=63, buffer_id=02:3F
    db 0,0,149,1,60,110,4,9,6,1,60,4  ; n1859 t=90.250s dur=405ms, freq=262Hz, sample=60, buffer_id=04:3C
    db 5,0,149,1,65,110,4,10,74,1,65,4  ; n1860 t=90.250s dur=405ms, freq=330Hz, sample=65, buffer_id=04:41
    db 0,0,149,1,86,120,7,11,39,5,86,2  ; n1861 t=90.254s dur=405ms, freq=1319Hz, sample=86, buffer_id=02:56
    db 9,0,149,1,75,120,9,13,147,2,75,2  ; n1862 t=90.254s dur=405ms, freq=659Hz, sample=75, buffer_id=02:4B
    db 5,0,149,1,89,110,16,12,39,5,89,16  ; n1863 t=90.264s dur=405ms, freq=1319Hz, sample=89, buffer_id=10:59
    db 0,0,149,1,67,124,5,1,93,1,67,5  ; n1864 t=90.269s dur=405ms, freq=349Hz, sample=67, buffer_id=05:43 [TRUNCATE prev:ch1 @90146.1ms -> 90268.6ms]
    db 0,0,149,1,72,124,5,0,11,2,72,5  ; n1865 t=90.269s dur=405ms, freq=523Hz, sample=72, buffer_id=05:48 [TRUNCATE prev:ch0 @90150.9ms -> 90268.6ms]
    db 0,0,149,1,55,124,14,2,175,0,55,14  ; n1866 t=90.269s dur=405ms, freq=175Hz, sample=55, buffer_id=0E:37 [TRUNCATE prev:ch2 @90155.6ms -> 90268.6ms]
    db 0,0,149,1,55,124,14,3,220,0,55,14  ; n1867 t=90.269s dur=405ms, freq=220Hz, sample=55, buffer_id=0E:37 [TRUNCATE prev:ch3 @90155.6ms -> 90268.6ms]
    db 0,0,149,1,60,124,14,5,6,1,60,14  ; n1868 t=90.269s dur=405ms, freq=262Hz, sample=60, buffer_id=0E:3C [TRUNCATE prev:ch5 @90165.0ms -> 90268.6ms]
    db 163,1,100,0,101,100,20,4,77,10,101,20  ; n1869 t=90.269s dur=100ms, freq=2637Hz, sample=101, buffer_id=14:65 [TRUNCATE prev:ch4 @90169.7ms -> 90268.6ms]
    db 10,0,113,0,29,120,2,4,49,0,29,2  ; n1870 t=90.688s dur=113ms, freq=49Hz, sample=29, buffer_id=02:1D
    db 5,0,100,0,61,120,11,6,38,1,61,2  ; n1871 t=90.697s dur=100ms, freq=294Hz, sample=61, buffer_id=02:3D
    db 0,0,100,0,55,110,4,7,196,0,55,4  ; n1872 t=90.702s dur=100ms, freq=196Hz, sample=55, buffer_id=04:37
    db 5,0,100,0,60,110,4,9,38,1,60,4  ; n1873 t=90.702s dur=100ms, freq=294Hz, sample=60, buffer_id=04:3C [TRUNCATE prev:ch9 @90249.8ms -> 90702.1ms]
    db 0,0,100,0,86,120,7,11,151,4,86,2  ; n1874 t=90.707s dur=100ms, freq=1175Hz, sample=86, buffer_id=02:56 [TRUNCATE prev:ch11 @90254.5ms -> 90706.8ms]
    db 9,0,100,0,73,120,9,8,75,2,73,2  ; n1875 t=90.707s dur=100ms, freq=587Hz, sample=73, buffer_id=02:49 [TRUNCATE prev:ch8 @90245.1ms -> 90706.8ms]
    db 5,0,100,0,84,110,16,10,151,4,84,16  ; n1876 t=90.716s dur=100ms, freq=1175Hz, sample=84, buffer_id=10:54 [TRUNCATE prev:ch10 @90249.8ms -> 90716.2ms]
    db 0,0,113,0,31,120,1,13,49,0,31,1  ; n1877 t=90.721s dur=113ms, freq=49Hz, sample=31, buffer_id=01:1F [TRUNCATE prev:ch13 @90254.5ms -> 90720.9ms]
    db 0,0,100,0,67,124,5,1,136,1,67,5  ; n1878 t=90.721s dur=100ms, freq=392Hz, sample=67, buffer_id=05:43 [TRUNCATE prev:ch1 @90268.6ms -> 90720.9ms]
    db 0,0,100,0,55,124,14,2,196,0,55,14  ; n1879 t=90.721s dur=100ms, freq=196Hz, sample=55, buffer_id=0E:37 [TRUNCATE prev:ch2 @90268.6ms -> 90720.9ms]
    db 0,0,100,0,65,124,14,12,93,1,65,14  ; n1880 t=90.721s dur=100ms, freq=349Hz, sample=65, buffer_id=0E:41 [TRUNCATE prev:ch12 @90263.9ms -> 90720.9ms]
    db 74,1,100,0,101,100,20,0,45,9,101,20  ; n1881 t=90.721s dur=100ms, freq=2349Hz, sample=101, buffer_id=14:65 [TRUNCATE prev:ch0 @90268.6ms -> 90720.9ms]
    db 5,0,100,0,56,120,11,0,196,0,56,2  ; n1882 t=91.051s dur=100ms, freq=196Hz, sample=56, buffer_id=02:38
    db 5,0,100,0,55,110,4,1,196,0,55,4  ; n1883 t=91.055s dur=100ms, freq=196Hz, sample=55, buffer_id=04:37
    db 0,0,100,0,79,120,7,2,16,3,79,2  ; n1884 t=91.060s dur=100ms, freq=784Hz, sample=79, buffer_id=02:4F
    db 9,0,100,0,67,120,9,3,136,1,67,2  ; n1885 t=91.060s dur=100ms, freq=392Hz, sample=67, buffer_id=02:43
    db 5,0,100,0,77,110,16,4,16,3,77,16  ; n1886 t=91.070s dur=100ms, freq=784Hz, sample=77, buffer_id=10:4D
    db 0,0,100,0,67,124,5,5,136,1,67,5  ; n1887 t=91.074s dur=100ms, freq=392Hz, sample=67, buffer_id=05:43
    db 0,0,100,0,55,124,14,6,196,0,55,14  ; n1888 t=91.074s dur=100ms, freq=196Hz, sample=55, buffer_id=0E:37
    db 75,0,100,0,91,100,20,7,32,6,91,20  ; n1889 t=91.074s dur=100ms, freq=1568Hz, sample=91, buffer_id=14:5B
    db 5,0,149,1,63,120,11,8,74,1,63,2  ; n1890 t=91.150s dur=405ms, freq=330Hz, sample=63, buffer_id=02:3F
    db 0,0,149,1,60,110,4,10,6,1,60,4  ; n1891 t=91.154s dur=405ms, freq=262Hz, sample=60, buffer_id=04:3C
    db 5,0,149,1,65,110,4,9,74,1,65,4  ; n1892 t=91.154s dur=405ms, freq=330Hz, sample=65, buffer_id=04:41
    db 0,0,149,1,86,120,7,12,39,5,86,2  ; n1893 t=91.159s dur=405ms, freq=1319Hz, sample=86, buffer_id=02:56
    db 9,0,149,1,75,120,9,11,147,2,75,2  ; n1894 t=91.159s dur=405ms, freq=659Hz, sample=75, buffer_id=02:4B
    db 5,0,149,1,89,110,16,13,39,5,89,16  ; n1895 t=91.168s dur=405ms, freq=1319Hz, sample=89, buffer_id=10:59
    db 0,0,149,1,67,124,5,0,93,1,67,5  ; n1896 t=91.173s dur=405ms, freq=349Hz, sample=67, buffer_id=05:43 [TRUNCATE prev:ch0 @91050.7ms -> 91173.2ms]
    db 0,0,149,1,72,124,5,1,11,2,72,5  ; n1897 t=91.173s dur=405ms, freq=523Hz, sample=72, buffer_id=05:48 [TRUNCATE prev:ch1 @91055.4ms -> 91173.2ms]
    db 0,0,149,1,55,124,14,2,175,0,55,14  ; n1898 t=91.173s dur=405ms, freq=175Hz, sample=55, buffer_id=0E:37 [TRUNCATE prev:ch2 @91060.1ms -> 91173.2ms]
    db 0,0,149,1,55,124,14,3,220,0,55,14  ; n1899 t=91.173s dur=405ms, freq=220Hz, sample=55, buffer_id=0E:37 [TRUNCATE prev:ch3 @91060.1ms -> 91173.2ms]
    db 0,0,149,1,60,124,14,4,6,1,60,14  ; n1900 t=91.173s dur=405ms, freq=262Hz, sample=60, buffer_id=0E:3C [TRUNCATE prev:ch4 @91069.6ms -> 91173.2ms]
    db 163,1,100,0,101,100,20,5,77,10,101,20  ; n1901 t=91.173s dur=100ms, freq=2637Hz, sample=101, buffer_id=14:65 [TRUNCATE prev:ch5 @91074.3ms -> 91173.2ms]
    db 9,0,113,0,29,120,2,5,49,0,29,2  ; n1902 t=91.593s dur=113ms, freq=49Hz, sample=29, buffer_id=02:1D
    db 5,0,100,0,61,120,11,6,38,1,61,2  ; n1903 t=91.602s dur=100ms, freq=294Hz, sample=61, buffer_id=02:3D
    db 0,0,100,0,55,110,4,7,196,0,55,4  ; n1904 t=91.607s dur=100ms, freq=196Hz, sample=55, buffer_id=04:37
    db 5,0,100,0,60,110,4,10,38,1,60,4  ; n1905 t=91.607s dur=100ms, freq=294Hz, sample=60, buffer_id=04:3C [TRUNCATE prev:ch10 @91154.4ms -> 91606.6ms]
    db 0,0,100,0,86,120,7,12,151,4,86,2  ; n1906 t=91.611s dur=100ms, freq=1175Hz, sample=86, buffer_id=02:56 [TRUNCATE prev:ch12 @91159.1ms -> 91611.4ms]
    db 9,0,100,0,73,120,9,8,75,2,73,2  ; n1907 t=91.611s dur=100ms, freq=587Hz, sample=73, buffer_id=02:49 [TRUNCATE prev:ch8 @91149.7ms -> 91611.4ms]
    db 5,0,100,0,84,110,16,9,151,4,84,16  ; n1908 t=91.621s dur=100ms, freq=1175Hz, sample=84, buffer_id=10:54 [TRUNCATE prev:ch9 @91154.4ms -> 91620.8ms]
    db 0,0,113,0,31,120,1,11,49,0,31,1  ; n1909 t=91.626s dur=113ms, freq=49Hz, sample=31, buffer_id=01:1F [TRUNCATE prev:ch11 @91159.1ms -> 91625.5ms]
    db 0,0,100,0,67,124,5,0,136,1,67,5  ; n1910 t=91.626s dur=100ms, freq=392Hz, sample=67, buffer_id=05:43 [TRUNCATE prev:ch0 @91173.2ms -> 91625.5ms]
    db 0,0,100,0,55,124,14,2,196,0,55,14  ; n1911 t=91.626s dur=100ms, freq=196Hz, sample=55, buffer_id=0E:37 [TRUNCATE prev:ch2 @91173.2ms -> 91625.5ms]
    db 0,0,100,0,65,124,14,13,93,1,65,14  ; n1912 t=91.626s dur=100ms, freq=349Hz, sample=65, buffer_id=0E:41 [TRUNCATE prev:ch13 @91168.5ms -> 91625.5ms]
    db 74,1,100,0,101,100,20,1,45,9,101,20  ; n1913 t=91.626s dur=100ms, freq=2349Hz, sample=101, buffer_id=14:65 [TRUNCATE prev:ch1 @91173.2ms -> 91625.5ms]
    db 5,0,100,0,56,120,11,0,196,0,56,2  ; n1914 t=91.955s dur=100ms, freq=196Hz, sample=56, buffer_id=02:38
    db 5,0,100,0,55,110,4,1,196,0,55,4  ; n1915 t=91.960s dur=100ms, freq=196Hz, sample=55, buffer_id=04:37
    db 0,0,100,0,79,120,7,2,16,3,79,2  ; n1916 t=91.965s dur=100ms, freq=784Hz, sample=79, buffer_id=02:4F
    db 9,0,100,0,67,120,9,3,136,1,67,2  ; n1917 t=91.965s dur=100ms, freq=392Hz, sample=67, buffer_id=02:43
    db 5,0,100,0,77,110,16,4,16,3,77,16  ; n1918 t=91.974s dur=100ms, freq=784Hz, sample=77, buffer_id=10:4D
    db 0,0,100,0,67,124,5,5,136,1,67,5  ; n1919 t=91.979s dur=100ms, freq=392Hz, sample=67, buffer_id=05:43
    db 0,0,100,0,55,124,14,6,196,0,55,14  ; n1920 t=91.979s dur=100ms, freq=196Hz, sample=55, buffer_id=0E:37
    db 75,0,100,0,91,100,20,7,32,6,91,20  ; n1921 t=91.979s dur=100ms, freq=1568Hz, sample=91, buffer_id=14:5B
    db 5,0,149,1,63,120,11,8,74,1,63,2  ; n1922 t=92.054s dur=405ms, freq=330Hz, sample=63, buffer_id=02:3F
    db 0,0,149,1,60,110,4,9,6,1,60,4  ; n1923 t=92.059s dur=405ms, freq=262Hz, sample=60, buffer_id=04:3C
    db 5,0,149,1,65,110,4,10,74,1,65,4  ; n1924 t=92.059s dur=405ms, freq=330Hz, sample=65, buffer_id=04:41
    db 0,0,149,1,86,120,7,11,39,5,86,2  ; n1925 t=92.064s dur=405ms, freq=1319Hz, sample=86, buffer_id=02:56
    db 10,0,149,1,75,120,9,12,147,2,75,2  ; n1926 t=92.064s dur=405ms, freq=659Hz, sample=75, buffer_id=02:4B
    db 5,0,149,1,89,110,16,13,39,5,89,16  ; n1927 t=92.073s dur=405ms, freq=1319Hz, sample=89, buffer_id=10:59
    db 0,0,149,1,67,124,5,0,93,1,67,5  ; n1928 t=92.078s dur=405ms, freq=349Hz, sample=67, buffer_id=05:43 [TRUNCATE prev:ch0 @91955.3ms -> 92077.8ms]
    db 0,0,149,1,72,124,5,1,11,2,72,5  ; n1929 t=92.078s dur=405ms, freq=523Hz, sample=72, buffer_id=05:48 [TRUNCATE prev:ch1 @91960.0ms -> 92077.8ms]
    db 0,0,149,1,55,124,14,2,175,0,55,14  ; n1930 t=92.078s dur=405ms, freq=175Hz, sample=55, buffer_id=0E:37 [TRUNCATE prev:ch2 @91964.7ms -> 92077.8ms]
    db 0,0,149,1,55,124,14,3,220,0,55,14  ; n1931 t=92.078s dur=405ms, freq=220Hz, sample=55, buffer_id=0E:37 [TRUNCATE prev:ch3 @91964.7ms -> 92077.8ms]
    db 0,0,149,1,60,124,14,4,6,1,60,14  ; n1932 t=92.078s dur=405ms, freq=262Hz, sample=60, buffer_id=0E:3C [TRUNCATE prev:ch4 @91974.1ms -> 92077.8ms]
    db 163,1,100,0,101,100,20,5,77,10,101,20  ; n1933 t=92.078s dur=100ms, freq=2637Hz, sample=101, buffer_id=14:65 [TRUNCATE prev:ch5 @91978.8ms -> 92077.8ms]
    db 9,0,113,0,29,120,2,5,49,0,29,2  ; n1934 t=92.497s dur=113ms, freq=49Hz, sample=29, buffer_id=02:1D
    db 5,0,100,0,61,120,11,6,38,1,61,2  ; n1935 t=92.507s dur=100ms, freq=294Hz, sample=61, buffer_id=02:3D
    db 0,0,100,0,55,110,4,7,196,0,55,4  ; n1936 t=92.511s dur=100ms, freq=196Hz, sample=55, buffer_id=04:37
    db 5,0,100,0,60,110,4,9,38,1,60,4  ; n1937 t=92.511s dur=100ms, freq=294Hz, sample=60, buffer_id=04:3C [TRUNCATE prev:ch9 @92058.9ms -> 92511.2ms]
    db 0,0,100,0,86,120,7,11,151,4,86,2  ; n1938 t=92.516s dur=100ms, freq=1175Hz, sample=86, buffer_id=02:56 [TRUNCATE prev:ch11 @92063.6ms -> 92515.9ms]
    db 9,0,100,0,73,120,9,8,75,2,73,2  ; n1939 t=92.516s dur=100ms, freq=587Hz, sample=73, buffer_id=02:49 [TRUNCATE prev:ch8 @92054.2ms -> 92515.9ms]
    db 5,0,100,0,84,110,16,10,151,4,84,16  ; n1940 t=92.525s dur=100ms, freq=1175Hz, sample=84, buffer_id=10:54 [TRUNCATE prev:ch10 @92058.9ms -> 92525.3ms]
    db 0,0,113,0,31,120,1,12,49,0,31,1  ; n1941 t=92.530s dur=113ms, freq=49Hz, sample=31, buffer_id=01:1F [TRUNCATE prev:ch12 @92063.6ms -> 92530.1ms]
    db 0,0,100,0,67,124,5,0,136,1,67,5  ; n1942 t=92.530s dur=100ms, freq=392Hz, sample=67, buffer_id=05:43 [TRUNCATE prev:ch0 @92077.8ms -> 92530.1ms]
    db 0,0,100,0,55,124,14,2,196,0,55,14  ; n1943 t=92.530s dur=100ms, freq=196Hz, sample=55, buffer_id=0E:37 [TRUNCATE prev:ch2 @92077.8ms -> 92530.1ms]
    db 0,0,100,0,65,124,14,13,93,1,65,14  ; n1944 t=92.530s dur=100ms, freq=349Hz, sample=65, buffer_id=0E:41 [TRUNCATE prev:ch13 @92073.1ms -> 92530.1ms]
    db 74,1,100,0,101,100,20,1,45,9,101,20  ; n1945 t=92.530s dur=100ms, freq=2349Hz, sample=101, buffer_id=14:65 [TRUNCATE prev:ch1 @92077.8ms -> 92530.1ms]
    db 5,0,100,0,56,120,11,0,196,0,56,2  ; n1946 t=92.860s dur=100ms, freq=196Hz, sample=56, buffer_id=02:38
    db 5,0,100,0,55,110,4,1,196,0,55,4  ; n1947 t=92.865s dur=100ms, freq=196Hz, sample=55, buffer_id=04:37
    db 0,0,100,0,79,120,7,2,16,3,79,2  ; n1948 t=92.869s dur=100ms, freq=784Hz, sample=79, buffer_id=02:4F
    db 9,0,100,0,67,120,9,3,136,1,67,2  ; n1949 t=92.869s dur=100ms, freq=392Hz, sample=67, buffer_id=02:43
    db 5,0,100,0,77,110,16,4,16,3,77,16  ; n1950 t=92.879s dur=100ms, freq=784Hz, sample=77, buffer_id=10:4D
    db 0,0,100,0,67,124,5,5,136,1,67,5  ; n1951 t=92.883s dur=100ms, freq=392Hz, sample=67, buffer_id=05:43
    db 0,0,100,0,55,124,14,6,196,0,55,14  ; n1952 t=92.883s dur=100ms, freq=196Hz, sample=55, buffer_id=0E:37
    db 75,0,100,0,91,100,20,7,32,6,91,20  ; n1953 t=92.883s dur=100ms, freq=1568Hz, sample=91, buffer_id=14:5B
    db 5,0,149,1,65,120,11,8,93,1,65,2  ; n1954 t=92.959s dur=405ms, freq=349Hz, sample=65, buffer_id=02:41
    db 0,0,149,1,60,110,4,10,6,1,60,4  ; n1955 t=92.963s dur=405ms, freq=262Hz, sample=60, buffer_id=04:3C
    db 5,0,149,1,65,110,4,9,93,1,65,4  ; n1956 t=92.963s dur=405ms, freq=349Hz, sample=65, buffer_id=04:41
    db 0,0,149,1,91,120,7,11,117,5,91,2  ; n1957 t=92.968s dur=405ms, freq=1397Hz, sample=91, buffer_id=02:5B
    db 9,0,149,1,75,120,9,12,186,2,75,2  ; n1958 t=92.968s dur=405ms, freq=698Hz, sample=75, buffer_id=02:4B
    db 5,0,149,1,89,110,16,13,117,5,89,16  ; n1959 t=92.978s dur=405ms, freq=1397Hz, sample=89, buffer_id=10:59
    db 0,0,149,1,67,124,5,0,184,1,67,5  ; n1960 t=92.982s dur=405ms, freq=440Hz, sample=67, buffer_id=05:43 [TRUNCATE prev:ch0 @92859.9ms -> 92982.3ms]
    db 0,0,149,1,72,124,5,1,11,2,72,5  ; n1961 t=92.982s dur=405ms, freq=523Hz, sample=72, buffer_id=05:48 [TRUNCATE prev:ch1 @92864.6ms -> 92982.3ms]
    db 0,0,149,1,55,124,14,2,175,0,55,14  ; n1962 t=92.982s dur=405ms, freq=175Hz, sample=55, buffer_id=0E:37 [TRUNCATE prev:ch2 @92869.3ms -> 92982.3ms]
    db 0,0,149,1,55,124,14,3,220,0,55,14  ; n1963 t=92.982s dur=405ms, freq=220Hz, sample=55, buffer_id=0E:37 [TRUNCATE prev:ch3 @92869.3ms -> 92982.3ms]
    db 0,0,149,1,60,124,14,4,6,1,60,14  ; n1964 t=92.982s dur=405ms, freq=262Hz, sample=60, buffer_id=0E:3C [TRUNCATE prev:ch4 @92878.7ms -> 92982.3ms]
    db 163,1,100,0,101,100,20,5,234,10,101,20  ; n1965 t=92.982s dur=100ms, freq=2794Hz, sample=101, buffer_id=14:65 [TRUNCATE prev:ch5 @92883.4ms -> 92982.3ms]
    db 10,0,113,0,29,120,2,5,49,0,29,2  ; n1966 t=93.402s dur=113ms, freq=49Hz, sample=29, buffer_id=02:1D
    db 5,0,100,0,63,120,11,6,74,1,63,2  ; n1967 t=93.411s dur=100ms, freq=330Hz, sample=63, buffer_id=02:3F
    db 0,0,100,0,55,110,4,7,196,0,55,4  ; n1968 t=93.416s dur=100ms, freq=196Hz, sample=55, buffer_id=04:37
    db 5,0,100,0,65,110,4,9,74,1,65,4  ; n1969 t=93.416s dur=100ms, freq=330Hz, sample=65, buffer_id=04:41 [TRUNCATE prev:ch9 @92963.5ms -> 93415.8ms]
    db 0,0,100,0,86,120,7,8,39,5,86,2  ; n1970 t=93.421s dur=100ms, freq=1319Hz, sample=86, buffer_id=02:56 [TRUNCATE prev:ch8 @92958.8ms -> 93420.5ms]
    db 9,0,100,0,75,120,9,12,147,2,75,2  ; n1971 t=93.421s dur=100ms, freq=659Hz, sample=75, buffer_id=02:4B [TRUNCATE prev:ch12 @92968.2ms -> 93420.5ms]
    db 5,0,100,0,89,110,16,13,39,5,89,16  ; n1972 t=93.430s dur=100ms, freq=1319Hz, sample=89, buffer_id=10:59 [TRUNCATE prev:ch13 @92977.6ms -> 93429.9ms]
    db 0,0,113,0,31,120,1,10,49,0,31,1  ; n1973 t=93.435s dur=113ms, freq=49Hz, sample=31, buffer_id=01:1F [TRUNCATE prev:ch10 @92963.5ms -> 93434.6ms]
    db 0,0,100,0,67,124,5,0,136,1,67,5  ; n1974 t=93.435s dur=100ms, freq=392Hz, sample=67, buffer_id=05:43 [TRUNCATE prev:ch0 @92982.3ms -> 93434.6ms]
    db 0,0,100,0,55,124,14,2,196,0,55,14  ; n1975 t=93.435s dur=100ms, freq=196Hz, sample=55, buffer_id=0E:37 [TRUNCATE prev:ch2 @92982.3ms -> 93434.6ms]
    db 0,0,100,0,65,124,14,11,93,1,65,14  ; n1976 t=93.435s dur=100ms, freq=349Hz, sample=65, buffer_id=0E:41 [TRUNCATE prev:ch11 @92968.2ms -> 93434.6ms]
    db 74,1,100,0,101,100,20,1,77,10,101,20  ; n1977 t=93.435s dur=100ms, freq=2637Hz, sample=101, buffer_id=14:65 [TRUNCATE prev:ch1 @92982.3ms -> 93434.6ms]
    db 5,0,100,0,61,120,11,0,38,1,61,2  ; n1978 t=93.764s dur=100ms, freq=294Hz, sample=61, buffer_id=02:3D
    db 0,0,100,0,55,110,4,1,196,0,55,4  ; n1979 t=93.769s dur=100ms, freq=196Hz, sample=55, buffer_id=04:37
    db 5,0,100,0,60,110,4,2,38,1,60,4  ; n1980 t=93.769s dur=100ms, freq=294Hz, sample=60, buffer_id=04:3C
    db 0,0,100,0,86,120,7,3,151,4,86,2  ; n1981 t=93.774s dur=100ms, freq=1175Hz, sample=86, buffer_id=02:56
    db 10,0,100,0,73,120,9,4,75,2,73,2  ; n1982 t=93.774s dur=100ms, freq=587Hz, sample=73, buffer_id=02:49
    db 5,0,100,0,84,110,16,5,151,4,84,16  ; n1983 t=93.783s dur=100ms, freq=1175Hz, sample=84, buffer_id=10:54
    db 0,0,100,0,67,124,5,6,136,1,67,5  ; n1984 t=93.788s dur=100ms, freq=392Hz, sample=67, buffer_id=05:43
    db 0,0,100,0,55,124,14,7,196,0,55,14  ; n1985 t=93.788s dur=100ms, freq=196Hz, sample=55, buffer_id=0E:37
    db 66,0,100,0,101,100,20,8,45,9,101,20  ; n1986 t=93.788s dur=100ms, freq=2349Hz, sample=101, buffer_id=14:65
    db 10,0,169,0,36,120,2,9,65,0,36,2  ; n1987 t=93.854s dur=169ms, freq=65Hz, sample=36, buffer_id=02:24
    db 5,0,149,1,67,120,11,10,184,1,67,2  ; n1988 t=93.863s dur=405ms, freq=440Hz, sample=67, buffer_id=02:43
    db 5,0,89,3,60,110,4,11,6,1,60,4  ; n1989 t=93.868s dur=857ms, freq=262Hz, sample=60, buffer_id=04:3C
    db 0,0,149,1,91,120,7,12,117,5,91,2  ; n1990 t=93.873s dur=405ms, freq=1397Hz, sample=91, buffer_id=02:5B
    db 9,0,149,1,75,120,9,13,186,2,75,2  ; n1991 t=93.873s dur=405ms, freq=698Hz, sample=75, buffer_id=02:4B
    db 5,0,149,1,89,110,16,0,117,5,89,16  ; n1992 t=93.882s dur=405ms, freq=1397Hz, sample=89, buffer_id=10:59 [TRUNCATE prev:ch0 @93764.4ms -> 93882.2ms]
    db 0,0,169,0,36,120,1,1,65,0,36,1  ; n1993 t=93.887s dur=169ms, freq=65Hz, sample=36, buffer_id=01:24 [TRUNCATE prev:ch1 @93769.1ms -> 93886.9ms]
    db 0,0,243,10,67,124,5,2,136,1,67,5  ; n1994 t=93.887s dur=2803ms, freq=392Hz, sample=67, buffer_id=05:43 [TRUNCATE prev:ch2 @93769.1ms -> 93886.9ms]
    db 0,0,226,6,60,124,14,3,6,1,60,14  ; n1995 t=93.887s dur=1762ms, freq=262Hz, sample=60, buffer_id=0E:3C [TRUNCATE prev:ch3 @93773.8ms -> 93886.9ms]
    db 163,1,100,0,101,100,20,4,234,10,101,20  ; n1996 t=93.887s dur=100ms, freq=2794Hz, sample=101, buffer_id=14:65 [TRUNCATE prev:ch4 @93773.8ms -> 93886.9ms]
    db 9,0,169,0,36,120,2,1,65,0,36,2  ; n1997 t=94.306s dur=169ms, freq=65Hz, sample=36, buffer_id=02:24
    db 10,0,100,0,67,120,11,4,136,1,67,2  ; n1998 t=94.316s dur=100ms, freq=392Hz, sample=67, buffer_id=02:43
    db 0,0,100,0,86,120,7,5,39,5,86,2  ; n1999 t=94.325s dur=100ms, freq=1319Hz, sample=86, buffer_id=02:56
    db 9,0,100,0,75,120,9,6,147,2,75,2  ; n2000 t=94.325s dur=100ms, freq=659Hz, sample=75, buffer_id=02:4B
    db 5,0,100,0,89,110,16,7,39,5,89,16  ; n2001 t=94.335s dur=100ms, freq=1319Hz, sample=89, buffer_id=10:59
    db 74,1,100,0,101,100,20,9,77,10,101,20  ; n2002 t=94.339s dur=100ms, freq=2637Hz, sample=101, buffer_id=14:65
    db 9,0,100,0,65,120,11,0,93,1,65,2  ; n2003 t=94.669s dur=100ms, freq=349Hz, sample=65, buffer_id=02:41
    db 0,0,100,0,86,120,7,1,151,4,86,2  ; n2004 t=94.678s dur=100ms, freq=1175Hz, sample=86, buffer_id=02:56
    db 9,0,100,0,73,120,9,4,75,2,73,2  ; n2005 t=94.678s dur=100ms, freq=587Hz, sample=73, buffer_id=02:49
    db 5,0,100,0,84,110,16,5,151,4,84,16  ; n2006 t=94.688s dur=100ms, freq=1175Hz, sample=84, buffer_id=10:54
    db 66,0,100,0,101,100,20,6,45,9,101,20  ; n2007 t=94.692s dur=100ms, freq=2349Hz, sample=101, buffer_id=14:65
    db 9,0,169,0,36,120,2,7,65,0,36,2  ; n2008 t=94.758s dur=169ms, freq=65Hz, sample=36, buffer_id=02:24
    db 5,0,243,10,60,120,11,8,6,1,60,2  ; n2009 t=94.768s dur=2803ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 5,0,149,1,65,110,4,9,93,1,65,4  ; n2010 t=94.773s dur=405ms, freq=349Hz, sample=65, buffer_id=04:41
    db 0,0,106,7,84,120,7,10,23,4,84,2  ; n2011 t=94.777s dur=1898ms, freq=1047Hz, sample=84, buffer_id=02:54
    db 10,0,46,9,72,120,9,12,11,2,72,2  ; n2012 t=94.777s dur=2350ms, freq=523Hz, sample=72, buffer_id=02:48
    db 5,0,106,7,84,110,16,13,23,4,84,16  ; n2013 t=94.787s dur=1898ms, freq=1047Hz, sample=84, buffer_id=10:54
    db 163,1,100,0,91,100,20,11,45,8,91,20  ; n2014 t=94.791s dur=100ms, freq=2093Hz, sample=91, buffer_id=14:5B [TRUNCATE prev:ch11 @93868.1ms -> 94791.5ms]
    db 14,0,169,0,36,120,2,0,65,0,36,2  ; n2015 t=95.211s dur=169ms, freq=65Hz, sample=36, buffer_id=02:24
    db 97,1,100,0,65,110,4,1,74,1,65,4  ; n2016 t=95.225s dur=100ms, freq=330Hz, sample=65, buffer_id=04:41
    db 85,0,100,0,60,110,4,1,38,1,60,4  ; n2017 t=95.578s dur=100ms, freq=294Hz, sample=60, buffer_id=04:3C
    db 14,0,169,0,36,120,2,4,65,0,36,2  ; n2018 t=95.663s dur=169ms, freq=65Hz, sample=36, buffer_id=02:24
    db 19,0,226,3,60,110,4,0,6,1,60,4  ; n2019 t=95.677s dur=994ms, freq=262Hz, sample=60, buffer_id=04:3C
    db 0,0,149,1,43,120,1,5,87,0,43,1  ; n2020 t=95.696s dur=405ms, freq=87Hz, sample=43, buffer_id=01:2B
    db 163,1,149,1,55,124,14,6,175,0,55,14  ; n2021 t=95.696s dur=405ms, freq=175Hz, sample=55, buffer_id=0E:37
    db 33,0,169,0,36,120,2,1,65,0,36,2  ; n2022 t=96.115s dur=169ms, freq=65Hz, sample=36, buffer_id=02:24
    db 0,0,100,0,43,120,1,3,82,0,43,1  ; n2023 t=96.148s dur=100ms, freq=82Hz, sample=43, buffer_id=01:2B
    db 97,1,100,0,50,124,14,4,165,0,50,14  ; n2024 t=96.148s dur=100ms, freq=165Hz, sample=50, buffer_id=0E:32
    db 0,0,100,0,36,120,1,1,73,0,36,1  ; n2025 t=96.502s dur=100ms, freq=73Hz, sample=36, buffer_id=01:24
    db 66,0,100,0,50,124,14,3,147,0,50,14  ; n2026 t=96.502s dur=100ms, freq=147Hz, sample=50, buffer_id=0E:32
    db 33,0,169,0,36,120,2,4,65,0,36,2  ; n2027 t=96.568s dur=169ms, freq=65Hz, sample=36, buffer_id=02:24
    db 0,0,100,0,36,120,1,5,65,0,36,1  ; n2028 t=96.601s dur=100ms, freq=65Hz, sample=36, buffer_id=01:24
    db 196,1,100,0,50,124,14,6,131,0,50,14  ; n2029 t=96.601s dur=100ms, freq=131Hz, sample=50, buffer_id=0E:32
    db 0,0,179,0,67,124,5,0,93,1,67,5  ; n2030 t=97.053s dur=179ms, freq=349Hz, sample=67, buffer_id=05:43
    db 97,1,100,0,91,100,20,1,117,5,91,20  ; n2031 t=97.053s dur=100ms, freq=1397Hz, sample=91, buffer_id=14:5B
    db 0,0,100,0,67,124,5,1,114,1,67,5  ; n2032 t=97.406s dur=100ms, freq=370Hz, sample=67, buffer_id=05:43
    db 66,0,100,0,91,100,20,2,200,5,91,20  ; n2033 t=97.406s dur=100ms, freq=1480Hz, sample=91, buffer_id=14:5B
    db 9,0,169,0,36,120,2,0,69,0,36,2  ; n2034 t=97.472s dur=169ms, freq=69Hz, sample=36, buffer_id=02:24
    db 0,0,100,0,61,120,11,3,21,1,61,2  ; n2035 t=97.482s dur=100ms, freq=277Hz, sample=61, buffer_id=02:3D
    db 10,0,169,0,48,115,13,4,139,0,48,2  ; n2036 t=97.482s dur=169ms, freq=139Hz, sample=48, buffer_id=02:30
    db 0,0,100,0,84,120,7,5,85,4,84,2  ; n2037 t=97.491s dur=100ms, freq=1109Hz, sample=84, buffer_id=02:54
    db 14,0,100,0,73,120,9,6,42,2,73,2  ; n2038 t=97.491s dur=100ms, freq=554Hz, sample=73, buffer_id=02:49
    db 0,0,100,0,67,124,5,7,159,1,67,5  ; n2039 t=97.505s dur=100ms, freq=415Hz, sample=67, buffer_id=05:43
    db 254,0,100,0,91,100,20,9,125,6,91,20  ; n2040 t=97.505s dur=100ms, freq=1661Hz, sample=91, buffer_id=14:5B
    db 0,0,249,3,72,124,5,1,42,2,72,5  ; n2041 t=97.760s dur=1017ms, freq=554Hz, sample=72, buffer_id=05:48
    db 165,0,100,0,101,100,20,2,169,8,101,20  ; n2042 t=97.760s dur=100ms, freq=2217Hz, sample=101, buffer_id=14:65
    db 9,0,169,0,36,120,2,3,69,0,36,2  ; n2043 t=97.924s dur=169ms, freq=69Hz, sample=36, buffer_id=02:24
    db 0,0,100,0,61,120,11,0,21,1,61,2  ; n2044 t=97.934s dur=100ms, freq=277Hz, sample=61, buffer_id=02:3D
    db 9,0,169,0,48,115,13,5,139,0,48,2  ; n2045 t=97.934s dur=169ms, freq=139Hz, sample=48, buffer_id=02:30
    db 0,0,100,0,84,120,7,4,85,4,84,2  ; n2046 t=97.943s dur=100ms, freq=1109Hz, sample=84, buffer_id=02:54
    db 14,0,100,0,73,120,9,7,42,2,73,2  ; n2047 t=97.943s dur=100ms, freq=554Hz, sample=73, buffer_id=02:49
    db 97,1,179,0,55,124,14,6,175,0,55,14  ; n2048 t=97.957s dur=179ms, freq=175Hz, sample=55, buffer_id=0E:37
    db 66,0,100,0,55,124,14,0,185,0,55,14  ; n2049 t=98.311s dur=100ms, freq=185Hz, sample=55, buffer_id=0E:37
    db 9,0,169,0,36,120,2,2,69,0,36,2  ; n2050 t=98.377s dur=169ms, freq=69Hz, sample=36, buffer_id=02:24
    db 0,0,100,0,61,120,11,3,21,1,61,2  ; n2051 t=98.386s dur=100ms, freq=277Hz, sample=61, buffer_id=02:3D
    db 9,0,169,0,48,115,13,4,139,0,48,2  ; n2052 t=98.386s dur=169ms, freq=139Hz, sample=48, buffer_id=02:30
    db 0,0,100,0,84,120,7,5,85,4,84,2  ; n2053 t=98.396s dur=100ms, freq=1109Hz, sample=84, buffer_id=02:54
    db 14,0,100,0,73,120,9,6,42,2,73,2  ; n2054 t=98.396s dur=100ms, freq=554Hz, sample=73, buffer_id=02:49
    db 203,0,100,0,55,124,14,7,208,0,55,14  ; n2055 t=98.410s dur=100ms, freq=208Hz, sample=55, buffer_id=0E:37
    db 9,0,100,0,61,120,11,0,21,1,61,2  ; n2056 t=98.612s dur=100ms, freq=277Hz, sample=61, buffer_id=02:3D
    db 0,0,100,0,84,120,7,8,85,4,84,2  ; n2057 t=98.622s dur=100ms, freq=1109Hz, sample=84, buffer_id=02:54
    db 42,0,100,0,73,120,9,9,42,2,73,2  ; n2058 t=98.622s dur=100ms, freq=554Hz, sample=73, buffer_id=02:49
    db 61,0,23,3,60,124,14,10,21,1,60,14  ; n2059 t=98.664s dur=791ms, freq=277Hz, sample=60, buffer_id=0E:3C
    db 9,0,100,0,61,120,11,5,21,1,61,2  ; n2060 t=98.725s dur=100ms, freq=277Hz, sample=61, buffer_id=02:3D
    db 0,0,100,0,84,120,7,3,85,4,84,2  ; n2061 t=98.735s dur=100ms, freq=1109Hz, sample=84, buffer_id=02:54
    db 94,0,100,0,73,120,9,7,42,2,73,2  ; n2062 t=98.735s dur=100ms, freq=554Hz, sample=73, buffer_id=02:49
    db 9,0,169,0,36,120,2,4,69,0,36,2  ; n2063 t=98.829s dur=169ms, freq=69Hz, sample=36, buffer_id=02:24
    db 0,0,100,0,61,120,11,2,21,1,61,2  ; n2064 t=98.838s dur=100ms, freq=277Hz, sample=61, buffer_id=02:3D
    db 9,0,169,0,48,115,13,6,139,0,48,2  ; n2065 t=98.838s dur=169ms, freq=139Hz, sample=48, buffer_id=02:30
    db 0,0,100,0,84,120,7,11,85,4,84,2  ; n2066 t=98.848s dur=100ms, freq=1109Hz, sample=84, buffer_id=02:54
    db 14,0,100,0,73,120,9,12,42,2,73,2  ; n2067 t=98.848s dur=100ms, freq=554Hz, sample=73, buffer_id=02:49
    db 0,0,113,0,62,124,5,13,55,1,62,5  ; n2068 t=98.862s dur=113ms, freq=311Hz, sample=62, buffer_id=05:3E
    db 90,0,100,0,84,100,20,1,221,4,84,20  ; n2069 t=98.862s dur=100ms, freq=1245Hz, sample=84, buffer_id=14:54 [TRUNCATE prev:ch1 @97759.6ms -> 98862.0ms]
    db 9,0,100,0,61,120,11,8,21,1,61,2  ; n2070 t=98.952s dur=100ms, freq=277Hz, sample=61, buffer_id=02:3D
    db 0,0,100,0,84,120,7,0,85,4,84,2  ; n2071 t=98.961s dur=100ms, freq=1109Hz, sample=84, buffer_id=02:54
    db 254,0,100,0,73,120,9,9,42,2,73,2  ; n2072 t=98.961s dur=100ms, freq=554Hz, sample=73, buffer_id=02:49 [TRUNCATE prev:ch9 @98621.8ms -> 98961.0ms]
    db 0,0,100,0,67,124,5,1,93,1,67,5  ; n2073 t=99.215s dur=100ms, freq=349Hz, sample=67, buffer_id=05:43
    db 66,0,100,0,91,100,20,2,117,5,91,20  ; n2074 t=99.215s dur=100ms, freq=1397Hz, sample=91, buffer_id=14:5B
    db 10,0,169,0,36,120,2,0,69,0,36,2  ; n2075 t=99.281s dur=169ms, freq=69Hz, sample=36, buffer_id=02:24
    db 0,0,100,0,61,120,11,3,21,1,61,2  ; n2076 t=99.291s dur=100ms, freq=277Hz, sample=61, buffer_id=02:3D
    db 9,0,169,0,48,115,13,4,139,0,48,2  ; n2077 t=99.291s dur=169ms, freq=139Hz, sample=48, buffer_id=02:30
    db 0,0,100,0,84,120,7,5,85,4,84,2  ; n2078 t=99.300s dur=100ms, freq=1109Hz, sample=84, buffer_id=02:54
    db 14,0,100,0,73,120,9,6,42,2,73,2  ; n2079 t=99.300s dur=100ms, freq=554Hz, sample=73, buffer_id=02:49
    db 0,0,219,4,67,124,5,7,114,1,67,5  ; n2080 t=99.314s dur=1243ms, freq=370Hz, sample=67, buffer_id=05:43
    db 163,1,100,0,91,100,20,8,200,5,91,20  ; n2081 t=99.314s dur=100ms, freq=1480Hz, sample=91, buffer_id=14:5B
    db 9,0,169,0,36,120,2,1,69,0,36,2  ; n2082 t=99.734s dur=169ms, freq=69Hz, sample=36, buffer_id=02:24
    db 0,0,100,0,61,120,11,0,21,1,61,2  ; n2083 t=99.743s dur=100ms, freq=277Hz, sample=61, buffer_id=02:3D
    db 10,0,169,0,48,115,13,2,139,0,48,2  ; n2084 t=99.743s dur=169ms, freq=139Hz, sample=48, buffer_id=02:30
    db 0,0,100,0,84,120,7,3,85,4,84,2  ; n2085 t=99.752s dur=100ms, freq=1109Hz, sample=84, buffer_id=02:54
    db 14,0,100,0,73,120,9,4,42,2,73,2  ; n2086 t=99.752s dur=100ms, freq=554Hz, sample=73, buffer_id=02:49
    db 97,1,113,0,50,124,14,5,156,0,50,14  ; n2087 t=99.767s dur=113ms, freq=156Hz, sample=50, buffer_id=0E:32
    db 66,0,100,0,55,124,14,0,175,0,55,14  ; n2088 t=100.120s dur=100ms, freq=175Hz, sample=55, buffer_id=0E:37
    db 9,0,169,0,36,120,2,2,69,0,36,2  ; n2089 t=100.186s dur=169ms, freq=69Hz, sample=36, buffer_id=02:24
    db 0,0,100,0,61,120,11,1,21,1,61,2  ; n2090 t=100.195s dur=100ms, freq=277Hz, sample=61, buffer_id=02:3D
    db 10,0,169,0,48,115,13,3,139,0,48,2  ; n2091 t=100.195s dur=169ms, freq=139Hz, sample=48, buffer_id=02:30
    db 0,0,100,0,84,120,7,4,85,4,84,2  ; n2092 t=100.205s dur=100ms, freq=1109Hz, sample=84, buffer_id=02:54
    db 14,0,100,0,73,120,9,5,42,2,73,2  ; n2093 t=100.205s dur=100ms, freq=554Hz, sample=73, buffer_id=02:49
    db 203,0,53,2,55,124,14,6,185,0,55,14  ; n2094 t=100.219s dur=565ms, freq=185Hz, sample=55, buffer_id=0E:37
    db 9,0,100,0,61,120,11,0,21,1,61,2  ; n2095 t=100.421s dur=100ms, freq=277Hz, sample=61, buffer_id=02:3D
    db 0,0,100,0,84,120,7,8,85,4,84,2  ; n2096 t=100.431s dur=100ms, freq=1109Hz, sample=84, buffer_id=02:54
    db 104,0,100,0,73,120,9,10,42,2,73,2  ; n2097 t=100.431s dur=100ms, freq=554Hz, sample=73, buffer_id=02:49
    db 10,0,100,0,61,120,11,4,21,1,61,2  ; n2098 t=100.534s dur=100ms, freq=277Hz, sample=61, buffer_id=02:3D
    db 0,0,100,0,84,120,7,1,85,4,84,2  ; n2099 t=100.544s dur=100ms, freq=1109Hz, sample=84, buffer_id=02:54
    db 94,0,100,0,73,120,9,11,42,2,73,2  ; n2100 t=100.544s dur=100ms, freq=554Hz, sample=73, buffer_id=02:49
    db 9,0,169,0,36,120,2,3,69,0,36,2  ; n2101 t=100.638s dur=169ms, freq=69Hz, sample=36, buffer_id=02:24
    db 0,0,100,0,61,120,11,2,21,1,61,2  ; n2102 t=100.648s dur=100ms, freq=277Hz, sample=61, buffer_id=02:3D
    db 9,0,169,0,48,115,13,5,139,0,48,2  ; n2103 t=100.648s dur=169ms, freq=139Hz, sample=48, buffer_id=02:30
    db 0,0,100,0,84,120,7,9,85,4,84,2  ; n2104 t=100.657s dur=100ms, freq=1109Hz, sample=84, buffer_id=02:54
    db 14,0,100,0,73,120,9,13,42,2,73,2  ; n2105 t=100.657s dur=100ms, freq=554Hz, sample=73, buffer_id=02:49
    db 0,0,179,0,67,124,5,12,159,1,67,5  ; n2106 t=100.671s dur=179ms, freq=415Hz, sample=67, buffer_id=05:43
    db 90,0,100,0,91,100,20,7,125,6,91,20  ; n2107 t=100.671s dur=100ms, freq=1661Hz, sample=91, buffer_id=14:5B [TRUNCATE prev:ch7 @99314.3ms -> 100671.2ms]
    db 9,0,100,0,61,120,11,8,21,1,61,2  ; n2108 t=100.761s dur=100ms, freq=277Hz, sample=61, buffer_id=02:3D
    db 0,0,100,0,84,120,7,0,85,4,84,2  ; n2109 t=100.770s dur=100ms, freq=1109Hz, sample=84, buffer_id=02:54
    db 254,0,100,0,73,120,9,10,42,2,73,2  ; n2110 t=100.770s dur=100ms, freq=554Hz, sample=73, buffer_id=02:49 [TRUNCATE prev:ch10 @100430.9ms -> 100770.1ms]
    db 0,0,100,0,72,124,5,1,210,1,72,5  ; n2111 t=101.025s dur=100ms, freq=466Hz, sample=72, buffer_id=05:48
    db 66,0,100,0,91,100,20,2,73,7,91,20  ; n2112 t=101.025s dur=100ms, freq=1865Hz, sample=91, buffer_id=14:5B
    db 9,0,169,0,36,120,2,0,69,0,36,2  ; n2113 t=101.091s dur=169ms, freq=69Hz, sample=36, buffer_id=02:24
    db 0,0,100,0,61,120,11,3,21,1,61,2  ; n2114 t=101.100s dur=100ms, freq=277Hz, sample=61, buffer_id=02:3D
    db 9,0,169,0,48,115,13,4,139,0,48,2  ; n2115 t=101.100s dur=169ms, freq=139Hz, sample=48, buffer_id=02:30
    db 0,0,100,0,84,120,7,5,85,4,84,2  ; n2116 t=101.109s dur=100ms, freq=1109Hz, sample=84, buffer_id=02:54
    db 14,0,100,0,73,120,9,6,42,2,73,2  ; n2117 t=101.109s dur=100ms, freq=554Hz, sample=73, buffer_id=02:49
    db 0,0,100,0,72,124,5,7,11,2,72,5  ; n2118 t=101.124s dur=100ms, freq=523Hz, sample=72, buffer_id=05:48
    db 254,0,100,0,91,100,20,8,45,8,91,20  ; n2119 t=101.124s dur=100ms, freq=2093Hz, sample=91, buffer_id=14:5B
    db 0,0,249,3,77,124,5,1,228,2,77,5  ; n2120 t=101.378s dur=1017ms, freq=740Hz, sample=77, buffer_id=05:4D
    db 165,0,100,0,101,100,20,2,144,11,101,20  ; n2121 t=101.378s dur=100ms, freq=2960Hz, sample=101, buffer_id=14:65
    db 9,0,169,0,36,120,2,3,69,0,36,2  ; n2122 t=101.543s dur=169ms, freq=69Hz, sample=36, buffer_id=02:24
    db 0,0,100,0,61,120,11,0,21,1,61,2  ; n2123 t=101.552s dur=100ms, freq=277Hz, sample=61, buffer_id=02:3D
    db 9,0,169,0,48,115,13,5,139,0,48,2  ; n2124 t=101.552s dur=169ms, freq=139Hz, sample=48, buffer_id=02:30
    db 0,0,100,0,84,120,7,4,85,4,84,2  ; n2125 t=101.562s dur=100ms, freq=1109Hz, sample=84, buffer_id=02:54
    db 14,0,100,0,73,120,9,7,42,2,73,2  ; n2126 t=101.562s dur=100ms, freq=554Hz, sample=73, buffer_id=02:49
    db 97,1,179,0,55,124,14,6,208,0,55,14  ; n2127 t=101.576s dur=179ms, freq=208Hz, sample=55, buffer_id=0E:37
    db 66,0,100,0,60,124,14,0,233,0,60,14  ; n2128 t=101.929s dur=100ms, freq=233Hz, sample=60, buffer_id=0E:3C
    db 9,0,169,0,36,120,2,2,69,0,36,2  ; n2129 t=101.995s dur=169ms, freq=69Hz, sample=36, buffer_id=02:24
    db 0,0,100,0,61,120,11,3,21,1,61,2  ; n2130 t=102.004s dur=100ms, freq=277Hz, sample=61, buffer_id=02:3D
    db 9,0,169,0,48,115,13,4,139,0,48,2  ; n2131 t=102.004s dur=169ms, freq=139Hz, sample=48, buffer_id=02:30
    db 0,0,100,0,84,120,7,5,85,4,84,2  ; n2132 t=102.014s dur=100ms, freq=1109Hz, sample=84, buffer_id=02:54
    db 14,0,100,0,73,120,9,6,42,2,73,2  ; n2133 t=102.014s dur=100ms, freq=554Hz, sample=73, buffer_id=02:49
    db 203,0,100,0,60,124,14,7,6,1,60,14  ; n2134 t=102.028s dur=100ms, freq=262Hz, sample=60, buffer_id=0E:3C
    db 9,0,100,0,61,120,11,0,21,1,61,2  ; n2135 t=102.231s dur=100ms, freq=277Hz, sample=61, buffer_id=02:3D
    db 0,0,100,0,84,120,7,8,85,4,84,2  ; n2136 t=102.240s dur=100ms, freq=1109Hz, sample=84, buffer_id=02:54
    db 42,0,100,0,73,120,9,9,42,2,73,2  ; n2137 t=102.240s dur=100ms, freq=554Hz, sample=73, buffer_id=02:49
    db 61,0,23,3,65,124,14,10,114,1,65,14  ; n2138 t=102.282s dur=791ms, freq=370Hz, sample=65, buffer_id=0E:41
    db 9,0,100,0,61,120,11,5,21,1,61,2  ; n2139 t=102.344s dur=100ms, freq=277Hz, sample=61, buffer_id=02:3D
    db 0,0,100,0,84,120,7,3,85,4,84,2  ; n2140 t=102.353s dur=100ms, freq=1109Hz, sample=84, buffer_id=02:54
    db 94,0,100,0,73,120,9,7,42,2,73,2  ; n2141 t=102.353s dur=100ms, freq=554Hz, sample=73, buffer_id=02:49
    db 10,0,169,0,36,120,2,4,69,0,36,2  ; n2142 t=102.447s dur=169ms, freq=69Hz, sample=36, buffer_id=02:24
    db 0,0,100,0,61,120,11,2,21,1,61,2  ; n2143 t=102.457s dur=100ms, freq=277Hz, sample=61, buffer_id=02:3D
    db 9,0,169,0,48,115,13,6,139,0,48,2  ; n2144 t=102.457s dur=169ms, freq=139Hz, sample=48, buffer_id=02:30
    db 0,0,100,0,84,120,7,11,85,4,84,2  ; n2145 t=102.466s dur=100ms, freq=1109Hz, sample=84, buffer_id=02:54
    db 14,0,100,0,73,120,9,12,42,2,73,2  ; n2146 t=102.466s dur=100ms, freq=554Hz, sample=73, buffer_id=02:49
    db 0,0,113,0,72,124,5,13,210,1,72,5  ; n2147 t=102.480s dur=113ms, freq=466Hz, sample=72, buffer_id=05:48
    db 90,0,100,0,91,100,20,1,73,7,91,20  ; n2148 t=102.480s dur=100ms, freq=1865Hz, sample=91, buffer_id=14:5B [TRUNCATE prev:ch1 @101377.9ms -> 102480.3ms]
    db 9,0,100,0,61,120,11,8,21,1,61,2  ; n2149 t=102.570s dur=100ms, freq=277Hz, sample=61, buffer_id=02:3D
    db 0,0,100,0,84,120,7,0,85,4,84,2  ; n2150 t=102.579s dur=100ms, freq=1109Hz, sample=84, buffer_id=02:54
    db 254,0,100,0,73,120,9,9,42,2,73,2  ; n2151 t=102.579s dur=100ms, freq=554Hz, sample=73, buffer_id=02:49 [TRUNCATE prev:ch9 @102240.0ms -> 102579.2ms]
    db 0,0,100,0,72,124,5,1,11,2,72,5  ; n2152 t=102.834s dur=100ms, freq=523Hz, sample=72, buffer_id=05:48
    db 66,0,100,0,91,100,20,2,45,8,91,20  ; n2153 t=102.834s dur=100ms, freq=2093Hz, sample=91, buffer_id=14:5B
    db 9,0,169,0,36,120,2,0,69,0,36,2  ; n2154 t=102.900s dur=169ms, freq=69Hz, sample=36, buffer_id=02:24
    db 0,0,100,0,61,120,11,3,21,1,61,2  ; n2155 t=102.909s dur=100ms, freq=277Hz, sample=61, buffer_id=02:3D
    db 9,0,169,0,48,115,13,4,139,0,48,2  ; n2156 t=102.909s dur=169ms, freq=139Hz, sample=48, buffer_id=02:30
    db 0,0,100,0,84,120,7,5,85,4,84,2  ; n2157 t=102.918s dur=100ms, freq=1109Hz, sample=84, buffer_id=02:54
    db 14,0,100,0,73,120,9,6,42,2,73,2  ; n2158 t=102.918s dur=100ms, freq=554Hz, sample=73, buffer_id=02:49
    db 0,0,80,1,72,124,5,7,42,2,72,5  ; n2159 t=102.933s dur=336ms, freq=554Hz, sample=72, buffer_id=05:48
    db 163,1,100,0,101,100,20,8,169,8,101,20  ; n2160 t=102.933s dur=100ms, freq=2217Hz, sample=101, buffer_id=14:65
    db 9,0,169,0,36,120,2,1,69,0,36,2  ; n2161 t=103.352s dur=169ms, freq=69Hz, sample=36, buffer_id=02:24
    db 0,0,100,0,61,120,11,0,21,1,61,2  ; n2162 t=103.361s dur=100ms, freq=277Hz, sample=61, buffer_id=02:3D
    db 5,0,169,0,48,115,13,2,139,0,48,2  ; n2163 t=103.361s dur=169ms, freq=139Hz, sample=48, buffer_id=02:30
    db 5,0,226,0,55,110,4,3,208,0,55,4  ; n2164 t=103.366s dur=226ms, freq=208Hz, sample=55, buffer_id=04:37
    db 0,0,100,0,84,120,7,4,85,4,84,2  ; n2165 t=103.371s dur=100ms, freq=1109Hz, sample=84, buffer_id=02:54
    db 14,0,100,0,73,120,9,5,42,2,73,2  ; n2166 t=103.371s dur=100ms, freq=554Hz, sample=73, buffer_id=02:49
    db 0,0,80,1,77,124,5,6,110,2,77,5  ; n2167 t=103.385s dur=336ms, freq=622Hz, sample=77, buffer_id=05:4D
    db 0,0,80,1,67,124,5,8,159,1,67,5  ; n2168 t=103.385s dur=336ms, freq=415Hz, sample=67, buffer_id=05:43
    db 0,0,226,0,65,124,14,9,55,1,65,14  ; n2169 t=103.385s dur=226ms, freq=311Hz, sample=65, buffer_id=0E:41
    db 163,1,100,0,101,100,20,10,185,9,101,20  ; n2170 t=103.385s dur=100ms, freq=2489Hz, sample=101, buffer_id=14:65
    db 9,0,169,0,36,120,2,0,69,0,36,2  ; n2171 t=103.804s dur=169ms, freq=69Hz, sample=36, buffer_id=02:24
    db 0,0,100,0,61,120,11,1,21,1,61,2  ; n2172 t=103.814s dur=100ms, freq=277Hz, sample=61, buffer_id=02:3D
    db 5,0,169,0,48,115,13,3,139,0,48,2  ; n2173 t=103.814s dur=169ms, freq=139Hz, sample=48, buffer_id=02:30
    db 5,0,169,0,60,110,4,2,21,1,60,4  ; n2174 t=103.818s dur=169ms, freq=277Hz, sample=60, buffer_id=04:3C
    db 0,0,100,0,84,120,7,5,85,4,84,2  ; n2175 t=103.823s dur=100ms, freq=1109Hz, sample=84, buffer_id=02:54
    db 14,0,100,0,73,120,9,4,42,2,73,2  ; n2176 t=103.823s dur=100ms, freq=554Hz, sample=73, buffer_id=02:49
    db 0,0,169,0,77,124,5,7,186,2,77,5  ; n2177 t=103.837s dur=169ms, freq=698Hz, sample=77, buffer_id=05:4D
    db 0,0,169,0,72,124,5,9,42,2,72,5  ; n2178 t=103.837s dur=169ms, freq=554Hz, sample=72, buffer_id=05:48
    db 0,0,169,0,65,124,14,10,93,1,65,14  ; n2179 t=103.837s dur=169ms, freq=349Hz, sample=65, buffer_id=0E:41
    db 203,0,100,0,101,100,20,11,234,10,101,20  ; n2180 t=103.837s dur=100ms, freq=2794Hz, sample=101, buffer_id=14:65
    db 10,0,100,0,61,120,11,6,21,1,61,2  ; n2181 t=104.040s dur=100ms, freq=277Hz, sample=61, buffer_id=02:3D
    db 0,0,100,0,84,120,7,8,85,4,84,2  ; n2182 t=104.049s dur=100ms, freq=1109Hz, sample=84, buffer_id=02:54
    db 104,0,100,0,73,120,9,13,42,2,73,2  ; n2183 t=104.049s dur=100ms, freq=554Hz, sample=73, buffer_id=02:49
    db 9,0,100,0,61,120,11,4,21,1,61,2  ; n2184 t=104.153s dur=100ms, freq=277Hz, sample=61, buffer_id=02:3D
    db 0,0,100,0,84,120,7,1,85,4,84,2  ; n2185 t=104.162s dur=100ms, freq=1109Hz, sample=84, buffer_id=02:54
    db 94,0,100,0,73,120,9,5,42,2,73,2  ; n2186 t=104.162s dur=100ms, freq=554Hz, sample=73, buffer_id=02:49
    db 9,0,169,0,36,120,2,2,69,0,36,2  ; n2187 t=104.257s dur=169ms, freq=69Hz, sample=36, buffer_id=02:24
    db 0,0,100,0,61,120,11,0,21,1,61,2  ; n2188 t=104.266s dur=100ms, freq=277Hz, sample=61, buffer_id=02:3D
    db 5,0,169,0,48,115,13,7,139,0,48,2  ; n2189 t=104.266s dur=169ms, freq=139Hz, sample=48, buffer_id=02:30
    db 5,0,179,0,50,110,4,3,139,0,50,4  ; n2190 t=104.271s dur=179ms, freq=139Hz, sample=50, buffer_id=04:32
    db 0,0,100,0,84,120,7,9,85,4,84,2  ; n2191 t=104.275s dur=100ms, freq=1109Hz, sample=84, buffer_id=02:54
    db 14,0,100,0,73,120,9,10,42,2,73,2  ; n2192 t=104.275s dur=100ms, freq=554Hz, sample=73, buffer_id=02:49
    db 0,0,179,0,67,124,5,11,93,1,67,5  ; n2193 t=104.289s dur=179ms, freq=349Hz, sample=67, buffer_id=05:43
    db 0,0,179,0,62,124,5,12,21,1,62,5  ; n2194 t=104.289s dur=179ms, freq=277Hz, sample=62, buffer_id=05:3E
    db 90,0,100,0,91,100,20,6,117,5,91,20  ; n2195 t=104.289s dur=100ms, freq=1397Hz, sample=91, buffer_id=14:5B [TRUNCATE prev:ch6 @104039.7ms -> 104289.4ms]
    db 9,0,100,0,61,120,11,8,21,1,61,2  ; n2196 t=104.379s dur=100ms, freq=277Hz, sample=61, buffer_id=02:3D
    db 0,0,100,0,84,120,7,13,85,4,84,2  ; n2197 t=104.388s dur=100ms, freq=1109Hz, sample=84, buffer_id=02:54
    db 236,0,100,0,73,120,9,5,42,2,73,2  ; n2198 t=104.388s dur=100ms, freq=554Hz, sample=73, buffer_id=02:49 [TRUNCATE prev:ch5 @104162.2ms -> 104388.4ms]
    db 19,0,100,0,50,110,4,0,156,0,50,4  ; n2199 t=104.624s dur=100ms, freq=156Hz, sample=50, buffer_id=04:32
    db 0,0,100,0,67,124,5,1,114,1,67,5  ; n2200 t=104.643s dur=100ms, freq=370Hz, sample=67, buffer_id=05:43
    db 0,0,100,0,62,124,5,2,55,1,62,5  ; n2201 t=104.643s dur=100ms, freq=311Hz, sample=62, buffer_id=05:3E
    db 66,0,100,0,91,100,20,4,200,5,91,20  ; n2202 t=104.643s dur=100ms, freq=1480Hz, sample=91, buffer_id=14:5B
    db 10,0,169,0,36,120,2,3,69,0,36,2  ; n2203 t=104.709s dur=169ms, freq=69Hz, sample=36, buffer_id=02:24
    db 0,0,100,0,61,120,11,5,21,1,61,2  ; n2204 t=104.718s dur=100ms, freq=277Hz, sample=61, buffer_id=02:3D
    db 5,0,169,0,48,115,13,6,139,0,48,2  ; n2205 t=104.718s dur=169ms, freq=139Hz, sample=48, buffer_id=02:30
    db 5,0,100,0,55,110,4,7,175,0,55,4  ; n2206 t=104.723s dur=100ms, freq=175Hz, sample=55, buffer_id=04:37
    db 0,0,100,0,84,120,7,8,85,4,84,2  ; n2207 t=104.728s dur=100ms, freq=1109Hz, sample=84, buffer_id=02:54
    db 14,0,100,0,73,120,9,9,42,2,73,2  ; n2208 t=104.728s dur=100ms, freq=554Hz, sample=73, buffer_id=02:49
    db 0,0,100,0,67,124,5,10,159,1,67,5  ; n2209 t=104.742s dur=100ms, freq=415Hz, sample=67, buffer_id=05:43
    db 0,0,100,0,67,124,5,12,93,1,67,5  ; n2210 t=104.742s dur=100ms, freq=349Hz, sample=67, buffer_id=05:43
    db 236,0,100,0,91,100,20,11,125,6,91,20  ; n2211 t=104.742s dur=100ms, freq=1661Hz, sample=91, buffer_id=14:5B
    db 19,0,249,3,55,110,4,0,208,0,55,4  ; n2212 t=104.977s dur=1017ms, freq=208Hz, sample=55, buffer_id=04:37
    db 0,0,249,3,72,124,5,1,42,2,72,5  ; n2213 t=104.996s dur=1017ms, freq=554Hz, sample=72, buffer_id=05:48
    db 0,0,249,3,67,124,5,2,159,1,67,5  ; n2214 t=104.996s dur=1017ms, freq=415Hz, sample=67, buffer_id=05:43
    db 165,0,100,0,101,100,20,4,169,8,101,20  ; n2215 t=104.996s dur=100ms, freq=2217Hz, sample=101, buffer_id=14:65
    db 10,0,169,0,36,120,2,5,69,0,36,2  ; n2216 t=105.161s dur=169ms, freq=69Hz, sample=36, buffer_id=02:24
    db 0,0,100,0,61,120,11,3,21,1,61,2  ; n2217 t=105.171s dur=100ms, freq=277Hz, sample=61, buffer_id=02:3D
    db 9,0,169,0,48,115,13,7,139,0,48,2  ; n2218 t=105.171s dur=169ms, freq=139Hz, sample=48, buffer_id=02:30
    db 0,0,100,0,84,120,7,6,85,4,84,2  ; n2219 t=105.180s dur=100ms, freq=1109Hz, sample=84, buffer_id=02:54
    db 14,0,100,0,73,120,9,8,42,2,73,2  ; n2220 t=105.180s dur=100ms, freq=554Hz, sample=73, buffer_id=02:49
    db 97,1,179,0,55,124,14,9,175,0,55,14  ; n2221 t=105.194s dur=179ms, freq=175Hz, sample=55, buffer_id=0E:37
    db 66,0,100,0,55,124,14,3,185,0,55,14  ; n2222 t=105.547s dur=100ms, freq=185Hz, sample=55, buffer_id=0E:37
    db 9,0,169,0,36,120,2,4,69,0,36,2  ; n2223 t=105.613s dur=169ms, freq=69Hz, sample=36, buffer_id=02:24
    db 0,0,100,0,61,120,11,5,21,1,61,2  ; n2224 t=105.623s dur=100ms, freq=277Hz, sample=61, buffer_id=02:3D
    db 10,0,169,0,48,115,13,6,139,0,48,2  ; n2225 t=105.623s dur=169ms, freq=139Hz, sample=48, buffer_id=02:30
    db 0,0,100,0,84,120,7,7,85,4,84,2  ; n2226 t=105.632s dur=100ms, freq=1109Hz, sample=84, buffer_id=02:54
    db 14,0,100,0,73,120,9,9,42,2,73,2  ; n2227 t=105.632s dur=100ms, freq=554Hz, sample=73, buffer_id=02:49
    db 203,0,100,0,55,124,14,8,208,0,55,14  ; n2228 t=105.646s dur=100ms, freq=208Hz, sample=55, buffer_id=0E:37
    db 9,0,100,0,61,120,11,3,21,1,61,2  ; n2229 t=105.849s dur=100ms, freq=277Hz, sample=61, buffer_id=02:3D
    db 0,0,100,0,84,120,7,10,85,4,84,2  ; n2230 t=105.858s dur=100ms, freq=1109Hz, sample=84, buffer_id=02:54
    db 42,0,100,0,73,120,9,11,42,2,73,2  ; n2231 t=105.858s dur=100ms, freq=554Hz, sample=73, buffer_id=02:49
    db 61,0,166,2,60,124,14,12,21,1,60,14  ; n2232 t=105.901s dur=678ms, freq=277Hz, sample=60, buffer_id=0E:3C
    db 9,0,100,0,61,120,11,7,21,1,61,2  ; n2233 t=105.962s dur=100ms, freq=277Hz, sample=61, buffer_id=02:3D
    db 0,0,100,0,84,120,7,5,85,4,84,2  ; n2234 t=105.971s dur=100ms, freq=1109Hz, sample=84, buffer_id=02:54
    db 94,0,100,0,73,120,9,8,42,2,73,2  ; n2235 t=105.971s dur=100ms, freq=554Hz, sample=73, buffer_id=02:49
    db 9,0,169,0,36,120,2,6,69,0,36,2  ; n2236 t=106.066s dur=169ms, freq=69Hz, sample=36, buffer_id=02:24
    db 0,0,100,0,61,120,11,4,21,1,61,2  ; n2237 t=106.075s dur=100ms, freq=277Hz, sample=61, buffer_id=02:3D
    db 5,0,169,0,48,115,13,9,139,0,48,2  ; n2238 t=106.075s dur=169ms, freq=139Hz, sample=48, buffer_id=02:30
    db 5,0,113,0,60,110,4,13,6,1,60,4  ; n2239 t=106.080s dur=113ms, freq=262Hz, sample=60, buffer_id=04:3C
    db 0,0,100,0,84,120,7,10,85,4,84,2  ; n2240 t=106.084s dur=100ms, freq=1109Hz, sample=84, buffer_id=02:54 [TRUNCATE prev:ch10 @105858.3ms -> 106084.4ms]
    db 14,0,100,0,73,120,9,11,42,2,73,2  ; n2241 t=106.084s dur=100ms, freq=554Hz, sample=73, buffer_id=02:49 [TRUNCATE prev:ch11 @105858.3ms -> 106084.4ms]
    db 0,0,113,0,77,124,5,0,110,2,77,5  ; n2242 t=106.099s dur=113ms, freq=622Hz, sample=77, buffer_id=05:4D [TRUNCATE prev:ch0 @104977.3ms -> 106098.6ms]
    db 0,0,113,0,72,124,5,1,11,2,72,5  ; n2243 t=106.099s dur=113ms, freq=523Hz, sample=72, buffer_id=05:48 [TRUNCATE prev:ch1 @104996.1ms -> 106098.6ms]
    db 90,0,100,0,101,100,20,2,185,9,101,20  ; n2244 t=106.099s dur=100ms, freq=2489Hz, sample=101, buffer_id=14:65 [TRUNCATE prev:ch2 @104996.1ms -> 106098.6ms]
    db 9,0,100,0,61,120,11,3,21,1,61,2  ; n2245 t=106.188s dur=100ms, freq=277Hz, sample=61, buffer_id=02:3D [TRUNCATE prev:ch3 @105848.9ms -> 106188.1ms]
    db 0,0,100,0,84,120,7,5,85,4,84,2  ; n2246 t=106.198s dur=100ms, freq=1109Hz, sample=84, buffer_id=02:54 [TRUNCATE prev:ch5 @105971.4ms -> 106197.5ms]
    db 236,0,100,0,73,120,9,8,42,2,73,2  ; n2247 t=106.198s dur=100ms, freq=554Hz, sample=73, buffer_id=02:49 [TRUNCATE prev:ch8 @105971.4ms -> 106197.5ms]
    db 19,0,100,0,60,110,4,0,21,1,60,4  ; n2248 t=106.433s dur=100ms, freq=277Hz, sample=60, buffer_id=04:3C
    db 0,0,100,0,77,124,5,1,186,2,77,5  ; n2249 t=106.452s dur=100ms, freq=698Hz, sample=77, buffer_id=05:4D
    db 0,0,100,0,72,124,5,2,42,2,72,5  ; n2250 t=106.452s dur=100ms, freq=554Hz, sample=72, buffer_id=05:48
    db 66,0,100,0,101,100,20,4,234,10,101,20  ; n2251 t=106.452s dur=100ms, freq=2794Hz, sample=101, buffer_id=14:65
    db 9,0,169,0,36,120,2,3,73,0,36,2  ; n2252 t=106.518s dur=169ms, freq=73Hz, sample=36, buffer_id=02:24
    db 0,0,100,0,50,120,11,5,147,0,50,2  ; n2253 t=106.527s dur=100ms, freq=147Hz, sample=50, buffer_id=02:32
    db 5,0,169,0,50,115,13,6,147,0,50,2  ; n2254 t=106.527s dur=169ms, freq=147Hz, sample=50, buffer_id=02:32
    db 5,0,219,4,60,110,4,7,38,1,60,4  ; n2255 t=106.532s dur=1243ms, freq=294Hz, sample=60, buffer_id=04:3C
    db 0,0,100,0,86,120,7,8,151,4,86,2  ; n2256 t=106.537s dur=100ms, freq=1175Hz, sample=86, buffer_id=02:56
    db 14,0,100,0,73,120,9,9,75,2,73,2  ; n2257 t=106.537s dur=100ms, freq=587Hz, sample=73, buffer_id=02:49
    db 0,0,219,4,77,124,5,10,228,2,77,5  ; n2258 t=106.551s dur=1243ms, freq=740Hz, sample=77, buffer_id=05:4D
    db 0,0,219,4,72,124,5,11,75,2,72,5  ; n2259 t=106.551s dur=1243ms, freq=587Hz, sample=72, buffer_id=05:48
    db 203,0,100,0,101,100,20,13,144,11,101,20  ; n2260 t=106.551s dur=100ms, freq=2960Hz, sample=101, buffer_id=14:65
    db 10,0,100,0,50,120,11,0,147,0,50,2  ; n2261 t=106.753s dur=100ms, freq=147Hz, sample=50, buffer_id=02:32
    db 0,0,100,0,86,120,7,1,151,4,86,2  ; n2262 t=106.763s dur=100ms, freq=1175Hz, sample=86, buffer_id=02:56
    db 14,0,100,0,73,120,9,2,75,2,73,2  ; n2263 t=106.763s dur=100ms, freq=587Hz, sample=73, buffer_id=02:49
    db 90,0,100,0,55,124,14,4,220,0,55,14  ; n2264 t=106.777s dur=100ms, freq=220Hz, sample=55, buffer_id=0E:37
    db 9,0,100,0,50,120,11,8,147,0,50,2  ; n2265 t=106.867s dur=100ms, freq=147Hz, sample=50, buffer_id=02:32
    db 0,0,100,0,86,120,7,5,151,4,86,2  ; n2266 t=106.876s dur=100ms, freq=1175Hz, sample=86, buffer_id=02:56
    db 14,0,100,0,73,120,9,12,75,2,73,2  ; n2267 t=106.876s dur=100ms, freq=587Hz, sample=73, buffer_id=02:49
    db 80,0,100,0,55,124,14,3,220,0,55,14  ; n2268 t=106.890s dur=100ms, freq=220Hz, sample=55, buffer_id=0E:37
    db 9,0,169,0,36,120,2,6,73,0,36,2  ; n2269 t=106.970s dur=169ms, freq=73Hz, sample=36, buffer_id=02:24
    db 0,0,100,0,50,120,11,9,147,0,50,2  ; n2270 t=106.980s dur=100ms, freq=147Hz, sample=50, buffer_id=02:32
    db 9,0,169,0,50,115,13,13,147,0,50,2  ; n2271 t=106.980s dur=169ms, freq=147Hz, sample=50, buffer_id=02:32
    db 0,0,100,0,86,120,7,1,151,4,86,2  ; n2272 t=106.989s dur=100ms, freq=1175Hz, sample=86, buffer_id=02:56 [TRUNCATE prev:ch1 @106762.9ms -> 106989.0ms]
    db 14,0,100,0,73,120,9,2,75,2,73,2  ; n2273 t=106.989s dur=100ms, freq=587Hz, sample=73, buffer_id=02:49 [TRUNCATE prev:ch2 @106762.9ms -> 106989.0ms]
    db 90,0,100,0,55,124,14,4,220,0,55,14  ; n2274 t=107.003s dur=100ms, freq=220Hz, sample=55, buffer_id=0E:37 [TRUNCATE prev:ch4 @106777.0ms -> 107003.1ms]
    db 9,0,100,0,50,120,11,0,147,0,50,2  ; n2275 t=107.093s dur=100ms, freq=147Hz, sample=50, buffer_id=02:32 [TRUNCATE prev:ch0 @106753.4ms -> 107092.7ms]
    db 0,0,100,0,86,120,7,5,151,4,86,2  ; n2276 t=107.102s dur=100ms, freq=1175Hz, sample=86, buffer_id=02:56 [TRUNCATE prev:ch5 @106875.9ms -> 107102.1ms]
    db 14,0,100,0,73,120,9,12,75,2,73,2  ; n2277 t=107.102s dur=100ms, freq=587Hz, sample=73, buffer_id=02:49 [TRUNCATE prev:ch12 @106875.9ms -> 107102.1ms]
    db 50,1,100,0,55,124,14,3,220,0,55,14  ; n2278 t=107.116s dur=100ms, freq=220Hz, sample=55, buffer_id=0E:37 [TRUNCATE prev:ch3 @106890.1ms -> 107116.2ms]
    db 9,0,169,0,36,120,2,0,73,0,36,2  ; n2279 t=107.422s dur=169ms, freq=73Hz, sample=36, buffer_id=02:24
    db 0,0,100,0,50,120,11,1,147,0,50,2  ; n2280 t=107.432s dur=100ms, freq=147Hz, sample=50, buffer_id=02:32
    db 9,0,169,0,50,115,13,2,147,0,50,2  ; n2281 t=107.432s dur=169ms, freq=147Hz, sample=50, buffer_id=02:32
    db 0,0,100,0,86,120,7,3,151,4,86,2  ; n2282 t=107.441s dur=100ms, freq=1175Hz, sample=86, buffer_id=02:56
    db 14,0,100,0,73,120,9,4,75,2,73,2  ; n2283 t=107.441s dur=100ms, freq=587Hz, sample=73, buffer_id=02:49
    db 173,1,100,0,60,124,14,5,38,1,60,14  ; n2284 t=107.455s dur=100ms, freq=294Hz, sample=60, buffer_id=0E:3C
    db 9,0,113,0,56,120,11,0,208,0,56,2  ; n2285 t=107.884s dur=113ms, freq=208Hz, sample=56, buffer_id=02:38
    db 0,0,113,0,91,120,7,1,125,6,91,2  ; n2286 t=107.894s dur=113ms, freq=1661Hz, sample=91, buffer_id=02:5B
    db 14,0,113,0,79,120,9,2,63,3,79,2  ; n2287 t=107.894s dur=113ms, freq=831Hz, sample=79, buffer_id=02:4F
    db 0,0,113,0,67,124,5,3,159,1,67,5  ; n2288 t=107.908s dur=113ms, freq=415Hz, sample=67, buffer_id=05:43
    db 0,0,113,0,55,124,14,4,208,0,55,14  ; n2289 t=107.908s dur=113ms, freq=208Hz, sample=55, buffer_id=0E:37
    db 74,1,100,0,91,100,20,5,125,6,91,20  ; n2290 t=107.908s dur=100ms, freq=1661Hz, sample=91, buffer_id=14:5B
    db 9,0,100,0,56,120,11,1,208,0,56,2  ; n2291 t=108.237s dur=100ms, freq=208Hz, sample=56, buffer_id=02:38
    db 0,0,100,0,79,120,7,0,63,3,79,2  ; n2292 t=108.247s dur=100ms, freq=831Hz, sample=79, buffer_id=02:4F
    db 14,0,100,0,67,120,9,2,159,1,67,2  ; n2293 t=108.247s dur=100ms, freq=415Hz, sample=67, buffer_id=02:43
    db 0,0,100,0,67,124,5,4,159,1,67,5  ; n2294 t=108.261s dur=100ms, freq=415Hz, sample=67, buffer_id=05:43
    db 0,0,100,0,55,124,14,3,208,0,55,14  ; n2295 t=108.261s dur=100ms, freq=208Hz, sample=55, buffer_id=0E:37
    db 75,0,100,0,91,100,20,6,125,6,91,20  ; n2296 t=108.261s dur=100ms, freq=1661Hz, sample=91, buffer_id=14:5B
    db 5,0,149,1,65,120,11,5,93,1,65,2  ; n2297 t=108.336s dur=405ms, freq=349Hz, sample=65, buffer_id=02:41
    db 0,0,149,1,60,110,4,8,21,1,60,4  ; n2298 t=108.341s dur=405ms, freq=277Hz, sample=60, buffer_id=04:3C
    db 5,0,149,1,70,110,4,7,159,1,70,4  ; n2299 t=108.341s dur=405ms, freq=415Hz, sample=70, buffer_id=04:46
    db 0,0,149,1,91,120,7,9,117,5,91,2  ; n2300 t=108.346s dur=405ms, freq=1397Hz, sample=91, buffer_id=02:5B
    db 14,0,149,1,75,120,9,10,186,2,75,2  ; n2301 t=108.346s dur=405ms, freq=698Hz, sample=75, buffer_id=02:4B
    db 0,0,149,1,67,124,5,11,114,1,67,5  ; n2302 t=108.360s dur=405ms, freq=370Hz, sample=67, buffer_id=05:43
    db 0,0,149,1,72,124,5,12,42,2,72,5  ; n2303 t=108.360s dur=405ms, freq=554Hz, sample=72, buffer_id=05:48
    db 0,0,149,1,77,124,5,13,186,2,77,5  ; n2304 t=108.360s dur=405ms, freq=698Hz, sample=77, buffer_id=05:4D
    db 0,0,149,1,55,124,14,1,185,0,55,14  ; n2305 t=108.360s dur=405ms, freq=185Hz, sample=55, buffer_id=0E:37 [TRUNCATE prev:ch1 @108237.5ms -> 108360.0ms]
    db 0,0,149,1,60,124,14,0,233,0,60,14  ; n2306 t=108.360s dur=405ms, freq=233Hz, sample=60, buffer_id=0E:3C [TRUNCATE prev:ch0 @108246.9ms -> 108360.0ms]
    db 0,0,149,1,60,124,14,2,21,1,60,14  ; n2307 t=108.360s dur=405ms, freq=277Hz, sample=60, buffer_id=0E:3C [TRUNCATE prev:ch2 @108246.9ms -> 108360.0ms]
    db 163,1,100,0,101,100,20,3,234,10,101,20  ; n2308 t=108.360s dur=100ms, freq=2794Hz, sample=101, buffer_id=14:65 [TRUNCATE prev:ch3 @108261.1ms -> 108360.0ms]
    db 9,0,113,0,34,120,2,3,52,0,34,2  ; n2309 t=108.779s dur=113ms, freq=52Hz, sample=34, buffer_id=02:22
    db 5,0,100,0,63,120,11,4,55,1,63,2  ; n2310 t=108.789s dur=100ms, freq=311Hz, sample=63, buffer_id=02:3F
    db 0,0,100,0,70,110,4,6,159,1,70,4  ; n2311 t=108.793s dur=100ms, freq=415Hz, sample=70, buffer_id=04:46
    db 5,0,100,0,65,110,4,5,55,1,65,4  ; n2312 t=108.793s dur=100ms, freq=311Hz, sample=65, buffer_id=04:41 [TRUNCATE prev:ch5 @108336.4ms -> 108793.4ms]
    db 0,0,100,0,86,120,7,7,221,4,86,2  ; n2313 t=108.798s dur=100ms, freq=1245Hz, sample=86, buffer_id=02:56 [TRUNCATE prev:ch7 @108341.2ms -> 108798.2ms]
    db 14,0,100,0,75,120,9,10,110,2,75,2  ; n2314 t=108.798s dur=100ms, freq=622Hz, sample=75, buffer_id=02:4B [TRUNCATE prev:ch10 @108345.9ms -> 108798.2ms]
    db 0,0,113,0,31,120,1,8,52,0,31,1  ; n2315 t=108.812s dur=113ms, freq=52Hz, sample=31, buffer_id=01:1F [TRUNCATE prev:ch8 @108341.2ms -> 108812.3ms]
    db 0,0,100,0,67,124,5,11,159,1,67,5  ; n2316 t=108.812s dur=100ms, freq=415Hz, sample=67, buffer_id=05:43 [TRUNCATE prev:ch11 @108360.0ms -> 108812.3ms]
    db 0,0,100,0,77,124,5,13,110,2,77,5  ; n2317 t=108.812s dur=100ms, freq=622Hz, sample=77, buffer_id=05:4D [TRUNCATE prev:ch13 @108360.0ms -> 108812.3ms]
    db 0,0,100,0,55,124,14,1,208,0,55,14  ; n2318 t=108.812s dur=100ms, freq=208Hz, sample=55, buffer_id=0E:37 [TRUNCATE prev:ch1 @108360.0ms -> 108812.3ms]
    db 0,0,100,0,65,124,14,9,114,1,65,14  ; n2319 t=108.812s dur=100ms, freq=370Hz, sample=65, buffer_id=0E:41 [TRUNCATE prev:ch9 @108345.9ms -> 108812.3ms]
    db 74,1,100,0,101,100,20,0,185,9,101,20  ; n2320 t=108.812s dur=100ms, freq=2489Hz, sample=101, buffer_id=14:65 [TRUNCATE prev:ch0 @108360.0ms -> 108812.3ms]
    db 5,0,100,0,56,120,11,0,208,0,56,2  ; n2321 t=109.142s dur=100ms, freq=208Hz, sample=56, buffer_id=02:38
    db 0,0,100,0,70,110,4,1,159,1,70,4  ; n2322 t=109.147s dur=100ms, freq=415Hz, sample=70, buffer_id=04:46
    db 5,0,100,0,55,110,4,2,208,0,55,4  ; n2323 t=109.147s dur=100ms, freq=208Hz, sample=55, buffer_id=04:37
    db 0,0,100,0,79,120,7,3,63,3,79,2  ; n2324 t=109.151s dur=100ms, freq=831Hz, sample=79, buffer_id=02:4F
    db 14,0,100,0,67,120,9,4,159,1,67,2  ; n2325 t=109.151s dur=100ms, freq=415Hz, sample=67, buffer_id=02:43
    db 0,0,100,0,67,124,5,5,159,1,67,5  ; n2326 t=109.166s dur=100ms, freq=415Hz, sample=67, buffer_id=05:43
    db 0,0,100,0,55,124,14,6,208,0,55,14  ; n2327 t=109.166s dur=100ms, freq=208Hz, sample=55, buffer_id=0E:37
    db 75,0,100,0,91,100,20,7,125,6,91,20  ; n2328 t=109.166s dur=100ms, freq=1661Hz, sample=91, buffer_id=14:5B
    db 5,0,149,1,65,120,11,8,93,1,65,2  ; n2329 t=109.241s dur=405ms, freq=349Hz, sample=65, buffer_id=02:41
    db 0,0,149,1,60,110,4,9,21,1,60,4  ; n2330 t=109.246s dur=405ms, freq=277Hz, sample=60, buffer_id=04:3C
    db 5,0,149,1,70,110,4,10,159,1,70,4  ; n2331 t=109.246s dur=405ms, freq=415Hz, sample=70, buffer_id=04:46
    db 0,0,149,1,91,120,7,11,117,5,91,2  ; n2332 t=109.250s dur=405ms, freq=1397Hz, sample=91, buffer_id=02:5B
    db 14,0,149,1,75,120,9,12,186,2,75,2  ; n2333 t=109.250s dur=405ms, freq=698Hz, sample=75, buffer_id=02:4B
    db 0,0,149,1,67,124,5,13,114,1,67,5  ; n2334 t=109.265s dur=405ms, freq=370Hz, sample=67, buffer_id=05:43
    db 0,0,149,1,72,124,5,0,42,2,72,5  ; n2335 t=109.265s dur=405ms, freq=554Hz, sample=72, buffer_id=05:48 [TRUNCATE prev:ch0 @109142.1ms -> 109264.6ms]
    db 0,0,149,1,77,124,5,1,186,2,77,5  ; n2336 t=109.265s dur=405ms, freq=698Hz, sample=77, buffer_id=05:4D [TRUNCATE prev:ch1 @109146.8ms -> 109264.6ms]
    db 0,0,149,1,55,124,14,2,185,0,55,14  ; n2337 t=109.265s dur=405ms, freq=185Hz, sample=55, buffer_id=0E:37 [TRUNCATE prev:ch2 @109146.8ms -> 109264.6ms]
    db 0,0,149,1,60,124,14,3,233,0,60,14  ; n2338 t=109.265s dur=405ms, freq=233Hz, sample=60, buffer_id=0E:3C [TRUNCATE prev:ch3 @109151.5ms -> 109264.6ms]
    db 0,0,149,1,60,124,14,4,21,1,60,14  ; n2339 t=109.265s dur=405ms, freq=277Hz, sample=60, buffer_id=0E:3C [TRUNCATE prev:ch4 @109151.5ms -> 109264.6ms]
    db 163,1,100,0,101,100,20,5,234,10,101,20  ; n2340 t=109.265s dur=100ms, freq=2794Hz, sample=101, buffer_id=14:65 [TRUNCATE prev:ch5 @109165.6ms -> 109264.6ms]
    db 9,0,113,0,34,120,2,5,52,0,34,2  ; n2341 t=109.684s dur=113ms, freq=52Hz, sample=34, buffer_id=02:22
    db 5,0,100,0,63,120,11,6,55,1,63,2  ; n2342 t=109.693s dur=100ms, freq=311Hz, sample=63, buffer_id=02:3F
    db 0,0,100,0,70,110,4,7,159,1,70,4  ; n2343 t=109.698s dur=100ms, freq=415Hz, sample=70, buffer_id=04:46
    db 5,0,100,0,65,110,4,8,55,1,65,4  ; n2344 t=109.698s dur=100ms, freq=311Hz, sample=65, buffer_id=04:41 [TRUNCATE prev:ch8 @109241.0ms -> 109698.0ms]
    db 0,0,100,0,86,120,7,9,221,4,86,2  ; n2345 t=109.703s dur=100ms, freq=1245Hz, sample=86, buffer_id=02:56 [TRUNCATE prev:ch9 @109245.7ms -> 109702.7ms]
    db 14,0,100,0,75,120,9,12,110,2,75,2  ; n2346 t=109.703s dur=100ms, freq=622Hz, sample=75, buffer_id=02:4B [TRUNCATE prev:ch12 @109250.4ms -> 109702.7ms]
    db 0,0,113,0,31,120,1,10,52,0,31,1  ; n2347 t=109.717s dur=113ms, freq=52Hz, sample=31, buffer_id=01:1F [TRUNCATE prev:ch10 @109245.7ms -> 109716.9ms]
    db 0,0,100,0,67,124,5,13,159,1,67,5  ; n2348 t=109.717s dur=100ms, freq=415Hz, sample=67, buffer_id=05:43 [TRUNCATE prev:ch13 @109264.6ms -> 109716.9ms]
    db 0,0,100,0,77,124,5,1,110,2,77,5  ; n2349 t=109.717s dur=100ms, freq=622Hz, sample=77, buffer_id=05:4D [TRUNCATE prev:ch1 @109264.6ms -> 109716.9ms]
    db 0,0,100,0,55,124,14,2,208,0,55,14  ; n2350 t=109.717s dur=100ms, freq=208Hz, sample=55, buffer_id=0E:37 [TRUNCATE prev:ch2 @109264.6ms -> 109716.9ms]
    db 0,0,100,0,65,124,14,11,114,1,65,14  ; n2351 t=109.717s dur=100ms, freq=370Hz, sample=65, buffer_id=0E:41 [TRUNCATE prev:ch11 @109250.4ms -> 109716.9ms]
    db 74,1,100,0,101,100,20,0,185,9,101,20  ; n2352 t=109.717s dur=100ms, freq=2489Hz, sample=101, buffer_id=14:65 [TRUNCATE prev:ch0 @109264.6ms -> 109716.9ms]
    db 5,0,100,0,56,120,11,0,208,0,56,2  ; n2353 t=110.047s dur=100ms, freq=208Hz, sample=56, buffer_id=02:38
    db 0,0,100,0,70,110,4,1,159,1,70,4  ; n2354 t=110.051s dur=100ms, freq=415Hz, sample=70, buffer_id=04:46
    db 5,0,100,0,55,110,4,2,208,0,55,4  ; n2355 t=110.051s dur=100ms, freq=208Hz, sample=55, buffer_id=04:37
    db 0,0,100,0,79,120,7,3,63,3,79,2  ; n2356 t=110.056s dur=100ms, freq=831Hz, sample=79, buffer_id=02:4F
    db 14,0,100,0,67,120,9,4,159,1,67,2  ; n2357 t=110.056s dur=100ms, freq=415Hz, sample=67, buffer_id=02:43
    db 0,0,100,0,67,124,5,5,159,1,67,5  ; n2358 t=110.070s dur=100ms, freq=415Hz, sample=67, buffer_id=05:43
    db 0,0,100,0,55,124,14,6,208,0,55,14  ; n2359 t=110.070s dur=100ms, freq=208Hz, sample=55, buffer_id=0E:37
    db 75,0,100,0,91,100,20,7,125,6,91,20  ; n2360 t=110.070s dur=100ms, freq=1661Hz, sample=91, buffer_id=14:5B
    db 5,0,149,1,65,120,11,8,93,1,65,2  ; n2361 t=110.146s dur=405ms, freq=349Hz, sample=65, buffer_id=02:41
    db 0,0,149,1,60,110,4,9,21,1,60,4  ; n2362 t=110.150s dur=405ms, freq=277Hz, sample=60, buffer_id=04:3C
    db 5,0,149,1,70,110,4,10,159,1,70,4  ; n2363 t=110.150s dur=405ms, freq=415Hz, sample=70, buffer_id=04:46
    db 0,0,149,1,91,120,7,11,117,5,91,2  ; n2364 t=110.155s dur=405ms, freq=1397Hz, sample=91, buffer_id=02:5B
    db 14,0,149,1,75,120,9,13,186,2,75,2  ; n2365 t=110.155s dur=405ms, freq=698Hz, sample=75, buffer_id=02:4B
    db 0,0,149,1,67,124,5,12,114,1,67,5  ; n2366 t=110.169s dur=405ms, freq=370Hz, sample=67, buffer_id=05:43
    db 0,0,149,1,72,124,5,0,42,2,72,5  ; n2367 t=110.169s dur=405ms, freq=554Hz, sample=72, buffer_id=05:48 [TRUNCATE prev:ch0 @110046.6ms -> 110169.1ms]
    db 0,0,149,1,77,124,5,1,186,2,77,5  ; n2368 t=110.169s dur=405ms, freq=698Hz, sample=77, buffer_id=05:4D [TRUNCATE prev:ch1 @110051.4ms -> 110169.1ms]
    db 0,0,149,1,55,124,14,2,185,0,55,14  ; n2369 t=110.169s dur=405ms, freq=185Hz, sample=55, buffer_id=0E:37 [TRUNCATE prev:ch2 @110051.4ms -> 110169.1ms]
    db 0,0,149,1,60,124,14,3,233,0,60,14  ; n2370 t=110.169s dur=405ms, freq=233Hz, sample=60, buffer_id=0E:3C [TRUNCATE prev:ch3 @110056.1ms -> 110169.1ms]
    db 0,0,149,1,60,124,14,4,21,1,60,14  ; n2371 t=110.169s dur=405ms, freq=277Hz, sample=60, buffer_id=0E:3C [TRUNCATE prev:ch4 @110056.1ms -> 110169.1ms]
    db 163,1,100,0,101,100,20,5,234,10,101,20  ; n2372 t=110.169s dur=100ms, freq=2794Hz, sample=101, buffer_id=14:65 [TRUNCATE prev:ch5 @110070.2ms -> 110169.1ms]
    db 10,0,113,0,34,120,2,5,52,0,34,2  ; n2373 t=110.588s dur=113ms, freq=52Hz, sample=34, buffer_id=02:22
    db 5,0,100,0,63,120,11,6,55,1,63,2  ; n2374 t=110.598s dur=100ms, freq=311Hz, sample=63, buffer_id=02:3F
    db 0,0,100,0,70,110,4,7,159,1,70,4  ; n2375 t=110.603s dur=100ms, freq=415Hz, sample=70, buffer_id=04:46
    db 5,0,100,0,65,110,4,8,55,1,65,4  ; n2376 t=110.603s dur=100ms, freq=311Hz, sample=65, buffer_id=04:41 [TRUNCATE prev:ch8 @110145.6ms -> 110602.6ms]
    db 0,0,100,0,86,120,7,9,221,4,86,2  ; n2377 t=110.607s dur=100ms, freq=1245Hz, sample=86, buffer_id=02:56 [TRUNCATE prev:ch9 @110150.3ms -> 110607.3ms]
    db 14,0,100,0,75,120,9,13,110,2,75,2  ; n2378 t=110.607s dur=100ms, freq=622Hz, sample=75, buffer_id=02:4B [TRUNCATE prev:ch13 @110155.0ms -> 110607.3ms]
    db 0,0,113,0,31,120,1,10,52,0,31,1  ; n2379 t=110.621s dur=113ms, freq=52Hz, sample=31, buffer_id=01:1F [TRUNCATE prev:ch10 @110150.3ms -> 110621.4ms]
    db 0,0,100,0,67,124,5,12,159,1,67,5  ; n2380 t=110.621s dur=100ms, freq=415Hz, sample=67, buffer_id=05:43 [TRUNCATE prev:ch12 @110169.1ms -> 110621.4ms]
    db 0,0,100,0,77,124,5,1,110,2,77,5  ; n2381 t=110.621s dur=100ms, freq=622Hz, sample=77, buffer_id=05:4D [TRUNCATE prev:ch1 @110169.1ms -> 110621.4ms]
    db 0,0,100,0,55,124,14,2,208,0,55,14  ; n2382 t=110.621s dur=100ms, freq=208Hz, sample=55, buffer_id=0E:37 [TRUNCATE prev:ch2 @110169.1ms -> 110621.4ms]
    db 0,0,100,0,65,124,14,11,114,1,65,14  ; n2383 t=110.621s dur=100ms, freq=370Hz, sample=65, buffer_id=0E:41 [TRUNCATE prev:ch11 @110155.0ms -> 110621.4ms]
    db 74,1,100,0,101,100,20,0,185,9,101,20  ; n2384 t=110.621s dur=100ms, freq=2489Hz, sample=101, buffer_id=14:65 [TRUNCATE prev:ch0 @110169.1ms -> 110621.4ms]
    db 5,0,100,0,56,120,11,0,208,0,56,2  ; n2385 t=110.951s dur=100ms, freq=208Hz, sample=56, buffer_id=02:38
    db 0,0,100,0,70,110,4,1,159,1,70,4  ; n2386 t=110.956s dur=100ms, freq=415Hz, sample=70, buffer_id=04:46
    db 5,0,100,0,55,110,4,2,208,0,55,4  ; n2387 t=110.956s dur=100ms, freq=208Hz, sample=55, buffer_id=04:37
    db 0,0,100,0,79,120,7,3,63,3,79,2  ; n2388 t=110.961s dur=100ms, freq=831Hz, sample=79, buffer_id=02:4F
    db 14,0,100,0,67,120,9,4,159,1,67,2  ; n2389 t=110.961s dur=100ms, freq=415Hz, sample=67, buffer_id=02:43
    db 0,0,100,0,67,124,5,5,159,1,67,5  ; n2390 t=110.975s dur=100ms, freq=415Hz, sample=67, buffer_id=05:43
    db 0,0,100,0,55,124,14,6,208,0,55,14  ; n2391 t=110.975s dur=100ms, freq=208Hz, sample=55, buffer_id=0E:37
    db 75,0,100,0,91,100,20,7,125,6,91,20  ; n2392 t=110.975s dur=100ms, freq=1661Hz, sample=91, buffer_id=14:5B
    db 5,0,149,1,71,120,11,8,210,1,71,2  ; n2393 t=111.050s dur=405ms, freq=466Hz, sample=71, buffer_id=02:47
    db 0,0,149,1,60,110,4,9,21,1,60,4  ; n2394 t=111.055s dur=405ms, freq=277Hz, sample=60, buffer_id=04:3C
    db 5,0,149,1,70,110,4,10,159,1,70,4  ; n2395 t=111.055s dur=405ms, freq=415Hz, sample=70, buffer_id=04:46
    db 0,0,149,1,91,120,7,11,200,5,91,2  ; n2396 t=111.060s dur=405ms, freq=1480Hz, sample=91, buffer_id=02:5B
    db 14,0,149,1,79,120,9,12,228,2,79,2  ; n2397 t=111.060s dur=405ms, freq=740Hz, sample=79, buffer_id=02:4F
    db 0,0,149,1,72,124,5,13,210,1,72,5  ; n2398 t=111.074s dur=405ms, freq=466Hz, sample=72, buffer_id=05:48
    db 0,0,149,1,72,124,5,0,42,2,72,5  ; n2399 t=111.074s dur=405ms, freq=554Hz, sample=72, buffer_id=05:48 [TRUNCATE prev:ch0 @110951.2ms -> 111073.7ms]
    db 0,0,149,1,77,124,5,1,228,2,77,5  ; n2400 t=111.074s dur=405ms, freq=740Hz, sample=77, buffer_id=05:4D [TRUNCATE prev:ch1 @110955.9ms -> 111073.7ms]
    db 0,0,149,1,55,124,14,2,185,0,55,14  ; n2401 t=111.074s dur=405ms, freq=185Hz, sample=55, buffer_id=0E:37 [TRUNCATE prev:ch2 @110955.9ms -> 111073.7ms]
    db 0,0,149,1,60,124,14,3,233,0,60,14  ; n2402 t=111.074s dur=405ms, freq=233Hz, sample=60, buffer_id=0E:3C [TRUNCATE prev:ch3 @110960.6ms -> 111073.7ms]
    db 0,0,149,1,60,124,14,4,21,1,60,14  ; n2403 t=111.074s dur=405ms, freq=277Hz, sample=60, buffer_id=0E:3C [TRUNCATE prev:ch4 @110960.6ms -> 111073.7ms]
    db 163,1,100,0,101,100,20,5,144,11,101,20  ; n2404 t=111.074s dur=100ms, freq=2960Hz, sample=101, buffer_id=14:65 [TRUNCATE prev:ch5 @110974.8ms -> 111073.7ms]
    db 9,0,113,0,34,120,2,5,52,0,34,2  ; n2405 t=111.493s dur=113ms, freq=52Hz, sample=34, buffer_id=02:22
    db 5,0,100,0,67,120,11,6,159,1,67,2  ; n2406 t=111.502s dur=100ms, freq=415Hz, sample=67, buffer_id=02:43
    db 0,0,100,0,70,110,4,7,159,1,70,4  ; n2407 t=111.507s dur=100ms, freq=415Hz, sample=70, buffer_id=04:46
    db 5,0,100,0,65,110,4,8,55,1,65,4  ; n2408 t=111.507s dur=100ms, freq=311Hz, sample=65, buffer_id=04:41 [TRUNCATE prev:ch8 @111050.1ms -> 111507.1ms]
    db 0,0,100,0,91,120,7,11,117,5,91,2  ; n2409 t=111.512s dur=100ms, freq=1397Hz, sample=91, buffer_id=02:5B [TRUNCATE prev:ch11 @111059.6ms -> 111511.9ms]
    db 14,0,100,0,75,120,9,9,186,2,75,2  ; n2410 t=111.512s dur=100ms, freq=698Hz, sample=75, buffer_id=02:4B [TRUNCATE prev:ch9 @111054.9ms -> 111511.9ms]
    db 0,0,113,0,31,120,1,10,52,0,31,1  ; n2411 t=111.526s dur=113ms, freq=52Hz, sample=31, buffer_id=01:1F [TRUNCATE prev:ch10 @111054.9ms -> 111526.0ms]
    db 0,0,100,0,67,124,5,12,159,1,67,5  ; n2412 t=111.526s dur=100ms, freq=415Hz, sample=67, buffer_id=05:43 [TRUNCATE prev:ch12 @111059.6ms -> 111526.0ms]
    db 0,0,100,0,77,124,5,1,186,2,77,5  ; n2413 t=111.526s dur=100ms, freq=698Hz, sample=77, buffer_id=05:4D [TRUNCATE prev:ch1 @111073.7ms -> 111526.0ms]
    db 0,0,100,0,55,124,14,2,208,0,55,14  ; n2414 t=111.526s dur=100ms, freq=208Hz, sample=55, buffer_id=0E:37 [TRUNCATE prev:ch2 @111073.7ms -> 111526.0ms]
    db 0,0,100,0,65,124,14,0,114,1,65,14  ; n2415 t=111.526s dur=100ms, freq=370Hz, sample=65, buffer_id=0E:41 [TRUNCATE prev:ch0 @111073.7ms -> 111526.0ms]
    db 74,1,100,0,101,100,20,3,234,10,101,20  ; n2416 t=111.526s dur=100ms, freq=2794Hz, sample=101, buffer_id=14:65 [TRUNCATE prev:ch3 @111073.7ms -> 111526.0ms]
    db 5,0,100,0,66,120,11,0,114,1,66,2  ; n2417 t=111.856s dur=100ms, freq=370Hz, sample=66, buffer_id=02:42
    db 0,0,100,0,70,110,4,1,159,1,70,4  ; n2418 t=111.861s dur=100ms, freq=415Hz, sample=70, buffer_id=04:46
    db 5,0,100,0,55,110,4,2,208,0,55,4  ; n2419 t=111.861s dur=100ms, freq=208Hz, sample=55, buffer_id=04:37
    db 0,0,100,0,86,120,7,3,221,4,86,2  ; n2420 t=111.865s dur=100ms, freq=1245Hz, sample=86, buffer_id=02:56
    db 14,0,100,0,75,120,9,4,110,2,75,2  ; n2421 t=111.865s dur=100ms, freq=622Hz, sample=75, buffer_id=02:4B
    db 0,0,100,0,67,124,5,5,159,1,67,5  ; n2422 t=111.879s dur=100ms, freq=415Hz, sample=67, buffer_id=05:43
    db 0,0,100,0,77,124,5,6,110,2,77,5  ; n2423 t=111.879s dur=100ms, freq=622Hz, sample=77, buffer_id=05:4D
    db 0,0,100,0,55,124,14,7,208,0,55,14  ; n2424 t=111.879s dur=100ms, freq=208Hz, sample=55, buffer_id=0E:37
    db 0,0,100,0,65,124,14,8,55,1,65,14  ; n2425 t=111.879s dur=100ms, freq=311Hz, sample=65, buffer_id=0E:41
    db 66,0,100,0,101,100,20,9,185,9,101,20  ; n2426 t=111.879s dur=100ms, freq=2489Hz, sample=101, buffer_id=14:65
    db 9,0,169,0,36,120,2,10,69,0,36,2  ; n2427 t=111.945s dur=169ms, freq=69Hz, sample=36, buffer_id=02:24
    db 5,0,216,0,65,120,11,11,93,1,65,2  ; n2428 t=111.955s dur=216ms, freq=349Hz, sample=65, buffer_id=02:41
    db 0,0,100,0,70,110,4,12,159,1,70,4  ; n2429 t=111.959s dur=100ms, freq=415Hz, sample=70, buffer_id=04:46
    db 0,0,100,0,60,110,4,13,6,1,60,4  ; n2430 t=111.959s dur=100ms, freq=262Hz, sample=60, buffer_id=04:3C
    db 0,0,100,0,60,110,4,0,21,1,60,4  ; n2431 t=111.959s dur=100ms, freq=277Hz, sample=60, buffer_id=04:3C [TRUNCATE prev:ch0 @111855.8ms -> 111959.4ms]
    db 5,0,100,0,65,110,4,1,93,1,65,4  ; n2432 t=111.959s dur=100ms, freq=349Hz, sample=65, buffer_id=04:41 [TRUNCATE prev:ch1 @111860.5ms -> 111959.4ms]
    db 0,0,216,0,84,120,7,2,85,4,84,2  ; n2433 t=111.964s dur=216ms, freq=1109Hz, sample=84, buffer_id=02:54 [TRUNCATE prev:ch2 @111860.5ms -> 111964.1ms]
    db 10,0,216,0,73,120,9,3,42,2,73,2  ; n2434 t=111.964s dur=216ms, freq=554Hz, sample=73, buffer_id=02:49 [TRUNCATE prev:ch3 @111865.2ms -> 111964.1ms]
    db 0,0,100,0,89,110,16,4,117,5,89,16  ; n2435 t=111.974s dur=100ms, freq=1397Hz, sample=89, buffer_id=10:59 [TRUNCATE prev:ch4 @111865.2ms -> 111973.6ms]
    db 0,0,100,0,92,90,17,5,125,6,92,17  ; n2436 t=111.974s dur=100ms, freq=1661Hz, sample=92, buffer_id=11:5C [TRUNCATE prev:ch5 @111879.3ms -> 111973.6ms]
    db 5,0,100,0,81,100,18,6,63,3,81,18  ; n2437 t=111.974s dur=100ms, freq=831Hz, sample=81, buffer_id=12:51 [TRUNCATE prev:ch6 @111879.3ms -> 111973.6ms]
    db 0,0,169,0,36,120,1,7,69,0,36,1  ; n2438 t=111.978s dur=169ms, freq=69Hz, sample=36, buffer_id=01:24 [TRUNCATE prev:ch7 @111879.3ms -> 111978.3ms]
    db 0,0,108,0,67,124,5,8,159,1,67,5  ; n2439 t=111.978s dur=108ms, freq=415Hz, sample=67, buffer_id=05:43 [TRUNCATE prev:ch8 @111879.3ms -> 111978.3ms]
    db 0,0,108,0,72,124,5,9,42,2,72,5  ; n2440 t=111.978s dur=108ms, freq=554Hz, sample=72, buffer_id=05:48 [TRUNCATE prev:ch9 @111879.3ms -> 111978.3ms]
    db 0,0,108,0,60,124,14,10,21,1,60,14  ; n2441 t=111.978s dur=108ms, freq=277Hz, sample=60, buffer_id=0E:3C [TRUNCATE prev:ch10 @111945.3ms -> 111978.3ms]
    db 0,0,108,0,65,124,14,11,93,1,65,14  ; n2442 t=111.978s dur=108ms, freq=349Hz, sample=65, buffer_id=0E:41 [TRUNCATE prev:ch11 @111954.7ms -> 111978.3ms]
    db 203,0,100,0,101,100,20,0,169,8,101,20  ; n2443 t=111.978s dur=100ms, freq=2217Hz, sample=101, buffer_id=14:65 [TRUNCATE prev:ch0 @111959.4ms -> 111978.3ms]
    db 24,0,100,0,56,120,11,1,208,0,56,2  ; n2444 t=112.181s dur=100ms, freq=208Hz, sample=56, buffer_id=02:38 [TRUNCATE prev:ch1 @111959.4ms -> 112180.9ms]
    db 14,0,100,0,60,110,4,13,21,1,60,4  ; n2445 t=112.204s dur=100ms, freq=277Hz, sample=60, buffer_id=04:3C [TRUNCATE prev:ch13 @111959.4ms -> 112204.4ms]
    db 0,0,100,0,85,90,17,12,85,4,85,17  ; n2446 t=112.219s dur=100ms, freq=1109Hz, sample=85, buffer_id=11:55 [TRUNCATE prev:ch12 @111959.4ms -> 112218.5ms]
    db 75,0,100,0,70,100,18,2,42,2,70,18  ; n2447 t=112.219s dur=100ms, freq=554Hz, sample=70, buffer_id=12:46 [TRUNCATE prev:ch2 @111964.1ms -> 112218.5ms]
    db 14,0,100,0,56,120,11,0,208,0,56,2  ; n2448 t=112.294s dur=100ms, freq=208Hz, sample=56, buffer_id=02:38
    db 14,0,100,0,60,110,4,4,6,1,60,4  ; n2449 t=112.308s dur=100ms, freq=262Hz, sample=60, buffer_id=04:3C
    db 0,0,100,0,85,90,17,5,23,4,85,17  ; n2450 t=112.322s dur=100ms, freq=1047Hz, sample=85, buffer_id=11:55
    db 85,0,100,0,70,100,18,6,11,2,70,18  ; n2451 t=112.322s dur=100ms, freq=523Hz, sample=70, buffer_id=12:46
    db 5,0,100,0,56,120,11,3,208,0,56,2  ; n2452 t=112.407s dur=100ms, freq=208Hz, sample=56, buffer_id=02:38
    db 14,0,100,0,60,110,4,7,21,1,60,4  ; n2453 t=112.412s dur=100ms, freq=277Hz, sample=60, buffer_id=04:3C
    db 0,0,100,0,85,90,17,8,85,4,85,17  ; n2454 t=112.426s dur=100ms, freq=1109Hz, sample=85, buffer_id=11:55
    db 207,0,100,0,70,100,18,9,42,2,70,18  ; n2455 t=112.426s dur=100ms, freq=554Hz, sample=70, buffer_id=12:46
    db 5,0,100,0,61,120,11,0,21,1,61,2  ; n2456 t=112.633s dur=100ms, freq=277Hz, sample=61, buffer_id=02:3D
    db 0,0,100,0,70,110,4,1,159,1,70,4  ; n2457 t=112.638s dur=100ms, freq=415Hz, sample=70, buffer_id=04:46
    db 0,0,100,0,60,110,4,2,6,1,60,4  ; n2458 t=112.638s dur=100ms, freq=262Hz, sample=60, buffer_id=04:3C
    db 0,0,100,0,60,110,4,5,21,1,60,4  ; n2459 t=112.638s dur=100ms, freq=277Hz, sample=60, buffer_id=04:3C
    db 14,0,100,0,65,110,4,4,93,1,65,4  ; n2460 t=112.638s dur=100ms, freq=349Hz, sample=65, buffer_id=04:41
    db 0,0,100,0,89,110,16,6,117,5,89,16  ; n2461 t=112.652s dur=100ms, freq=1397Hz, sample=89, buffer_id=10:59
    db 0,0,100,0,92,90,17,10,125,6,92,17  ; n2462 t=112.652s dur=100ms, freq=1661Hz, sample=92, buffer_id=11:5C
    db 207,0,100,0,81,100,18,11,63,3,81,18  ; n2463 t=112.652s dur=100ms, freq=831Hz, sample=81, buffer_id=12:51
    db 23,0,100,0,56,120,11,7,208,0,56,2  ; n2464 t=112.859s dur=100ms, freq=208Hz, sample=56, buffer_id=02:38
    db 14,0,100,0,60,110,4,3,21,1,60,4  ; n2465 t=112.883s dur=100ms, freq=277Hz, sample=60, buffer_id=04:3C
    db 0,0,100,0,85,90,17,9,85,4,85,17  ; n2466 t=112.897s dur=100ms, freq=1109Hz, sample=85, buffer_id=11:55
    db 75,0,100,0,70,100,18,8,42,2,70,18  ; n2467 t=112.897s dur=100ms, freq=554Hz, sample=70, buffer_id=12:46
    db 14,0,100,0,56,120,11,0,208,0,56,2  ; n2468 t=112.972s dur=100ms, freq=208Hz, sample=56, buffer_id=02:38
    db 14,0,100,0,60,110,4,1,6,1,60,4  ; n2469 t=112.987s dur=100ms, freq=262Hz, sample=60, buffer_id=04:3C
    db 0,0,100,0,85,90,17,2,23,4,85,17  ; n2470 t=113.001s dur=100ms, freq=1047Hz, sample=85, buffer_id=11:55
    db 85,0,100,0,70,100,18,4,11,2,70,18  ; n2471 t=113.001s dur=100ms, freq=523Hz, sample=70, buffer_id=12:46
    db 5,0,100,0,56,120,11,5,208,0,56,2  ; n2472 t=113.085s dur=100ms, freq=208Hz, sample=56, buffer_id=02:38
    db 14,0,100,0,60,110,4,6,21,1,60,4  ; n2473 t=113.090s dur=100ms, freq=277Hz, sample=60, buffer_id=04:3C
    db 0,0,100,0,85,90,17,10,85,4,85,17  ; n2474 t=113.104s dur=100ms, freq=1109Hz, sample=85, buffer_id=11:55
    db 207,0,100,0,70,100,18,11,42,2,70,18  ; n2475 t=113.104s dur=100ms, freq=554Hz, sample=70, buffer_id=12:46
    db 5,0,100,0,61,120,11,0,21,1,61,2  ; n2476 t=113.312s dur=100ms, freq=277Hz, sample=61, buffer_id=02:3D
    db 0,0,100,0,70,110,4,1,159,1,70,4  ; n2477 t=113.316s dur=100ms, freq=415Hz, sample=70, buffer_id=04:46
    db 0,0,100,0,60,110,4,2,6,1,60,4  ; n2478 t=113.316s dur=100ms, freq=262Hz, sample=60, buffer_id=04:3C
    db 0,0,100,0,60,110,4,4,21,1,60,4  ; n2479 t=113.316s dur=100ms, freq=277Hz, sample=60, buffer_id=04:3C
    db 14,0,100,0,65,110,4,3,93,1,65,4  ; n2480 t=113.316s dur=100ms, freq=349Hz, sample=65, buffer_id=04:41
    db 0,0,100,0,89,110,16,7,117,5,89,16  ; n2481 t=113.330s dur=100ms, freq=1397Hz, sample=89, buffer_id=10:59
    db 0,0,100,0,92,90,17,8,125,6,92,17  ; n2482 t=113.330s dur=100ms, freq=1661Hz, sample=92, buffer_id=11:5C
    db 207,0,100,0,81,100,18,9,63,3,81,18  ; n2483 t=113.330s dur=100ms, freq=831Hz, sample=81, buffer_id=12:51
    db 24,0,100,0,56,120,11,6,208,0,56,2  ; n2484 t=113.538s dur=100ms, freq=208Hz, sample=56, buffer_id=02:38
    db 0,0,100,0,65,110,4,5,114,1,65,4  ; n2485 t=113.561s dur=100ms, freq=370Hz, sample=65, buffer_id=04:41
    db 0,0,100,0,60,110,4,10,233,0,60,4  ; n2486 t=113.561s dur=100ms, freq=233Hz, sample=60, buffer_id=04:3C
    db 0,0,100,0,60,110,4,11,247,0,60,4  ; n2487 t=113.561s dur=100ms, freq=247Hz, sample=60, buffer_id=04:3C
    db 14,0,100,0,65,110,4,12,55,1,65,4  ; n2488 t=113.561s dur=100ms, freq=311Hz, sample=65, buffer_id=04:41
    db 0,0,100,0,89,110,16,13,221,4,89,16  ; n2489 t=113.575s dur=100ms, freq=1245Hz, sample=89, buffer_id=10:59
    db 0,0,100,0,92,90,17,8,200,5,92,17  ; n2490 t=113.575s dur=100ms, freq=1480Hz, sample=92, buffer_id=11:5C [TRUNCATE prev:ch8 @113330.4ms -> 113575.4ms]
    db 75,0,100,0,77,100,18,0,228,2,77,18  ; n2491 t=113.575s dur=100ms, freq=740Hz, sample=77, buffer_id=12:4D [TRUNCATE prev:ch0 @113311.6ms -> 113575.4ms]
    db 14,0,100,0,56,120,11,1,208,0,56,2  ; n2492 t=113.651s dur=100ms, freq=208Hz, sample=56, buffer_id=02:38
    db 0,0,100,0,65,110,4,2,93,1,65,4  ; n2493 t=113.665s dur=100ms, freq=349Hz, sample=65, buffer_id=04:41
    db 0,0,100,0,55,110,4,3,220,0,55,4  ; n2494 t=113.665s dur=100ms, freq=220Hz, sample=55, buffer_id=04:37
    db 0,0,100,0,60,110,4,7,233,0,60,4  ; n2495 t=113.665s dur=100ms, freq=233Hz, sample=60, buffer_id=04:3C
    db 14,0,100,0,60,110,4,9,38,1,60,4  ; n2496 t=113.665s dur=100ms, freq=294Hz, sample=60, buffer_id=04:3C
    db 0,0,100,0,84,110,16,4,151,4,84,16  ; n2497 t=113.679s dur=100ms, freq=1175Hz, sample=84, buffer_id=10:54
    db 0,0,100,0,92,90,17,8,117,5,92,17  ; n2498 t=113.679s dur=100ms, freq=1397Hz, sample=92, buffer_id=11:5C [TRUNCATE prev:ch8 @113575.4ms -> 113679.0ms]
    db 85,0,100,0,77,100,18,0,186,2,77,18  ; n2499 t=113.679s dur=100ms, freq=698Hz, sample=77, buffer_id=12:4D [TRUNCATE prev:ch0 @113575.4ms -> 113679.0ms]
    db 5,0,100,0,59,120,11,6,247,0,59,2  ; n2500 t=113.764s dur=100ms, freq=247Hz, sample=59, buffer_id=02:3B [TRUNCATE prev:ch6 @113537.7ms -> 113763.9ms]
    db 0,0,219,4,65,110,4,5,114,1,65,4  ; n2501 t=113.769s dur=1243ms, freq=370Hz, sample=65, buffer_id=04:41 [TRUNCATE prev:ch5 @113561.3ms -> 113768.6ms]
    db 0,0,219,4,60,110,4,10,233,0,60,4  ; n2502 t=113.769s dur=1243ms, freq=233Hz, sample=60, buffer_id=04:3C [TRUNCATE prev:ch10 @113561.3ms -> 113768.6ms]
    db 0,0,219,4,60,110,4,11,247,0,60,4  ; n2503 t=113.769s dur=1243ms, freq=247Hz, sample=60, buffer_id=04:3C [TRUNCATE prev:ch11 @113561.3ms -> 113768.6ms]
    db 14,0,219,4,65,110,4,12,55,1,65,4  ; n2504 t=113.769s dur=1243ms, freq=311Hz, sample=65, buffer_id=04:41 [TRUNCATE prev:ch12 @113561.3ms -> 113768.6ms]
    db 0,0,219,4,89,110,16,13,221,4,89,16  ; n2505 t=113.783s dur=1243ms, freq=1245Hz, sample=89, buffer_id=10:59 [TRUNCATE prev:ch13 @113575.4ms -> 113782.7ms]
    db 0,0,219,4,92,90,17,8,200,5,92,17  ; n2506 t=113.783s dur=1243ms, freq=1480Hz, sample=92, buffer_id=11:5C [TRUNCATE prev:ch8 @113679.0ms -> 113782.7ms]
    db 207,0,219,4,77,100,18,0,228,2,77,18  ; n2507 t=113.783s dur=1243ms, freq=740Hz, sample=77, buffer_id=12:4D [TRUNCATE prev:ch0 @113679.0ms -> 113782.7ms]
    db 113,0,100,0,56,120,11,2,208,0,56,2  ; n2508 t=113.990s dur=100ms, freq=208Hz, sample=56, buffer_id=02:38
    db 113,0,100,0,56,120,11,3,208,0,56,2  ; n2509 t=114.103s dur=100ms, freq=208Hz, sample=56, buffer_id=02:38
    db 217,0,100,0,63,120,11,1,55,1,63,2  ; n2510 t=114.216s dur=100ms, freq=311Hz, sample=63, buffer_id=02:3F
    db 9,0,113,0,34,120,2,2,52,0,34,2  ; n2511 t=114.433s dur=113ms, freq=52Hz, sample=34, buffer_id=02:22
    db 113,0,100,0,56,120,11,4,208,0,56,2  ; n2512 t=114.442s dur=100ms, freq=208Hz, sample=56, buffer_id=02:38
    db 104,0,100,0,56,120,11,1,208,0,56,2  ; n2513 t=114.555s dur=100ms, freq=208Hz, sample=56, buffer_id=02:38
    db 9,0,113,0,36,120,2,3,69,0,36,2  ; n2514 t=114.659s dur=113ms, freq=69Hz, sample=36, buffer_id=02:24
    db 226,0,100,0,59,120,11,7,247,0,59,2  ; n2515 t=114.668s dur=100ms, freq=247Hz, sample=59, buffer_id=02:3B
    db 113,0,100,0,56,120,11,2,208,0,56,2  ; n2516 t=114.895s dur=100ms, freq=208Hz, sample=56, buffer_id=02:38
    db 113,0,100,0,56,120,11,3,208,0,56,2  ; n2517 t=115.008s dur=100ms, freq=208Hz, sample=56, buffer_id=02:38
    db 217,0,100,0,63,120,11,1,55,1,63,2  ; n2518 t=115.121s dur=100ms, freq=311Hz, sample=63, buffer_id=02:3F
    db 9,0,113,0,34,120,2,0,52,0,34,2  ; n2519 t=115.337s dur=113ms, freq=52Hz, sample=34, buffer_id=02:22
    db 24,0,100,0,56,120,11,5,208,0,56,2  ; n2520 t=115.347s dur=100ms, freq=208Hz, sample=56, buffer_id=02:38
    db 14,0,100,0,65,110,4,2,55,1,65,4  ; n2521 t=115.370s dur=100ms, freq=311Hz, sample=65, buffer_id=04:41
    db 0,0,100,0,85,90,17,3,221,4,85,17  ; n2522 t=115.385s dur=100ms, freq=1245Hz, sample=85, buffer_id=11:55
    db 75,0,100,0,77,100,18,4,110,2,77,18  ; n2523 t=115.385s dur=100ms, freq=622Hz, sample=77, buffer_id=12:4D
    db 14,0,100,0,56,120,11,1,208,0,56,2  ; n2524 t=115.460s dur=100ms, freq=208Hz, sample=56, buffer_id=02:38
    db 14,0,100,0,65,110,4,6,55,1,65,4  ; n2525 t=115.474s dur=100ms, freq=311Hz, sample=65, buffer_id=04:41
    db 0,0,100,0,85,90,17,7,221,4,85,17  ; n2526 t=115.488s dur=100ms, freq=1245Hz, sample=85, buffer_id=11:55
    db 75,0,100,0,77,100,18,8,110,2,77,18  ; n2527 t=115.488s dur=100ms, freq=622Hz, sample=77, buffer_id=12:4D
    db 9,0,113,0,36,120,2,9,69,0,36,2  ; n2528 t=115.564s dur=113ms, freq=69Hz, sample=36, buffer_id=02:24
    db 5,0,100,0,61,120,11,10,21,1,61,2  ; n2529 t=115.573s dur=100ms, freq=277Hz, sample=61, buffer_id=02:3D
    db 0,0,100,0,70,110,4,11,159,1,70,4  ; n2530 t=115.578s dur=100ms, freq=415Hz, sample=70, buffer_id=04:46
    db 0,0,100,0,60,110,4,12,6,1,60,4  ; n2531 t=115.578s dur=100ms, freq=262Hz, sample=60, buffer_id=04:3C
    db 0,0,100,0,60,110,4,13,21,1,60,4  ; n2532 t=115.578s dur=100ms, freq=277Hz, sample=60, buffer_id=04:3C
    db 14,0,100,0,65,110,4,2,93,1,65,4  ; n2533 t=115.578s dur=100ms, freq=349Hz, sample=65, buffer_id=04:41 [TRUNCATE prev:ch2 @115370.4ms -> 115577.7ms]
    db 0,0,100,0,89,110,16,0,117,5,89,16  ; n2534 t=115.592s dur=100ms, freq=1397Hz, sample=89, buffer_id=10:59 [TRUNCATE prev:ch0 @115337.4ms -> 115591.8ms]
    db 0,0,100,0,92,90,17,5,125,6,92,17  ; n2535 t=115.592s dur=100ms, freq=1661Hz, sample=92, buffer_id=11:5C [TRUNCATE prev:ch5 @115346.8ms -> 115591.8ms]
    db 207,0,100,0,81,100,18,3,63,3,81,18  ; n2536 t=115.592s dur=100ms, freq=831Hz, sample=81, buffer_id=12:51 [TRUNCATE prev:ch3 @115384.5ms -> 115591.8ms]
    db 24,0,100,0,56,120,11,4,208,0,56,2  ; n2537 t=115.799s dur=100ms, freq=208Hz, sample=56, buffer_id=02:38
    db 14,0,100,0,60,110,4,1,21,1,60,4  ; n2538 t=115.823s dur=100ms, freq=277Hz, sample=60, buffer_id=04:3C
    db 0,0,100,0,85,90,17,6,85,4,85,17  ; n2539 t=115.837s dur=100ms, freq=1109Hz, sample=85, buffer_id=11:55
    db 75,0,100,0,70,100,18,7,42,2,70,18  ; n2540 t=115.837s dur=100ms, freq=554Hz, sample=70, buffer_id=12:46
    db 14,0,100,0,56,120,11,0,208,0,56,2  ; n2541 t=115.912s dur=100ms, freq=208Hz, sample=56, buffer_id=02:38
    db 14,0,100,0,60,110,4,2,6,1,60,4  ; n2542 t=115.926s dur=100ms, freq=262Hz, sample=60, buffer_id=04:3C
    db 0,0,100,0,85,90,17,3,23,4,85,17  ; n2543 t=115.941s dur=100ms, freq=1047Hz, sample=85, buffer_id=11:55
    db 85,0,100,0,70,100,18,5,11,2,70,18  ; n2544 t=115.941s dur=100ms, freq=523Hz, sample=70, buffer_id=12:46
    db 5,0,100,0,56,120,11,8,208,0,56,2  ; n2545 t=116.025s dur=100ms, freq=208Hz, sample=56, buffer_id=02:38
    db 14,0,100,0,60,110,4,9,21,1,60,4  ; n2546 t=116.030s dur=100ms, freq=277Hz, sample=60, buffer_id=04:3C
    db 0,0,100,0,85,90,17,10,85,4,85,17  ; n2547 t=116.044s dur=100ms, freq=1109Hz, sample=85, buffer_id=11:55
    db 207,0,100,0,70,100,18,11,42,2,70,18  ; n2548 t=116.044s dur=100ms, freq=554Hz, sample=70, buffer_id=12:46
    db 5,0,100,0,61,120,11,0,21,1,61,2  ; n2549 t=116.251s dur=100ms, freq=277Hz, sample=61, buffer_id=02:3D
    db 0,0,100,0,70,110,4,1,159,1,70,4  ; n2550 t=116.256s dur=100ms, freq=415Hz, sample=70, buffer_id=04:46
    db 0,0,100,0,60,110,4,3,6,1,60,4  ; n2551 t=116.256s dur=100ms, freq=262Hz, sample=60, buffer_id=04:3C
    db 0,0,100,0,60,110,4,4,21,1,60,4  ; n2552 t=116.256s dur=100ms, freq=277Hz, sample=60, buffer_id=04:3C
    db 14,0,100,0,65,110,4,2,93,1,65,4  ; n2553 t=116.256s dur=100ms, freq=349Hz, sample=65, buffer_id=04:41
    db 0,0,100,0,89,110,16,5,117,5,89,16  ; n2554 t=116.270s dur=100ms, freq=1397Hz, sample=89, buffer_id=10:59
    db 0,0,100,0,92,90,17,6,125,6,92,17  ; n2555 t=116.270s dur=100ms, freq=1661Hz, sample=92, buffer_id=11:5C
    db 207,0,100,0,81,100,18,7,63,3,81,18  ; n2556 t=116.270s dur=100ms, freq=831Hz, sample=81, buffer_id=12:51
    db 23,0,100,0,56,120,11,9,208,0,56,2  ; n2557 t=116.478s dur=100ms, freq=208Hz, sample=56, buffer_id=02:38
    db 14,0,100,0,60,110,4,8,21,1,60,4  ; n2558 t=116.501s dur=100ms, freq=277Hz, sample=60, buffer_id=04:3C
    db 0,0,100,0,85,90,17,11,85,4,85,17  ; n2559 t=116.515s dur=100ms, freq=1109Hz, sample=85, buffer_id=11:55
    db 75,0,100,0,70,100,18,10,42,2,70,18  ; n2560 t=116.515s dur=100ms, freq=554Hz, sample=70, buffer_id=12:46
    db 14,0,100,0,56,120,11,0,208,0,56,2  ; n2561 t=116.591s dur=100ms, freq=208Hz, sample=56, buffer_id=02:38
    db 14,0,100,0,60,110,4,1,6,1,60,4  ; n2562 t=116.605s dur=100ms, freq=262Hz, sample=60, buffer_id=04:3C
    db 0,0,100,0,85,90,17,2,23,4,85,17  ; n2563 t=116.619s dur=100ms, freq=1047Hz, sample=85, buffer_id=11:55
    db 85,0,100,0,70,100,18,3,11,2,70,18  ; n2564 t=116.619s dur=100ms, freq=523Hz, sample=70, buffer_id=12:46
    db 5,0,100,0,56,120,11,4,208,0,56,2  ; n2565 t=116.704s dur=100ms, freq=208Hz, sample=56, buffer_id=02:38
    db 14,0,100,0,60,110,4,5,21,1,60,4  ; n2566 t=116.708s dur=100ms, freq=277Hz, sample=60, buffer_id=04:3C
    db 0,0,100,0,85,90,17,6,85,4,85,17  ; n2567 t=116.722s dur=100ms, freq=1109Hz, sample=85, buffer_id=11:55
    db 207,0,100,0,70,100,18,7,42,2,70,18  ; n2568 t=116.722s dur=100ms, freq=554Hz, sample=70, buffer_id=12:46
    db 5,0,100,0,61,120,11,0,21,1,61,2  ; n2569 t=116.930s dur=100ms, freq=277Hz, sample=61, buffer_id=02:3D
    db 0,0,100,0,70,110,4,1,159,1,70,4  ; n2570 t=116.935s dur=100ms, freq=415Hz, sample=70, buffer_id=04:46
    db 0,0,100,0,60,110,4,2,6,1,60,4  ; n2571 t=116.935s dur=100ms, freq=262Hz, sample=60, buffer_id=04:3C
    db 0,0,100,0,60,110,4,3,21,1,60,4  ; n2572 t=116.935s dur=100ms, freq=277Hz, sample=60, buffer_id=04:3C
    db 14,0,100,0,65,110,4,8,93,1,65,4  ; n2573 t=116.935s dur=100ms, freq=349Hz, sample=65, buffer_id=04:41
    db 0,0,100,0,89,110,16,9,117,5,89,16  ; n2574 t=116.949s dur=100ms, freq=1397Hz, sample=89, buffer_id=10:59
    db 0,0,100,0,92,90,17,10,125,6,92,17  ; n2575 t=116.949s dur=100ms, freq=1661Hz, sample=92, buffer_id=11:5C
    db 207,0,100,0,81,100,18,11,63,3,81,18  ; n2576 t=116.949s dur=100ms, freq=831Hz, sample=81, buffer_id=12:51
    db 23,0,100,0,56,120,11,5,208,0,56,2  ; n2577 t=117.156s dur=100ms, freq=208Hz, sample=56, buffer_id=02:38
    db 0,0,100,0,65,110,4,4,114,1,65,4  ; n2578 t=117.180s dur=100ms, freq=370Hz, sample=65, buffer_id=04:41
    db 0,0,100,0,60,110,4,6,233,0,60,4  ; n2579 t=117.180s dur=100ms, freq=233Hz, sample=60, buffer_id=04:3C
    db 0,0,100,0,60,110,4,7,247,0,60,4  ; n2580 t=117.180s dur=100ms, freq=247Hz, sample=60, buffer_id=04:3C
    db 14,0,100,0,65,110,4,12,55,1,65,4  ; n2581 t=117.180s dur=100ms, freq=311Hz, sample=65, buffer_id=04:41
    db 0,0,100,0,89,110,16,13,221,4,89,16  ; n2582 t=117.194s dur=100ms, freq=1245Hz, sample=89, buffer_id=10:59
    db 0,0,100,0,92,90,17,10,200,5,92,17  ; n2583 t=117.194s dur=100ms, freq=1480Hz, sample=92, buffer_id=11:5C [TRUNCATE prev:ch10 @116948.7ms -> 117193.7ms]
    db 75,0,100,0,77,100,18,0,228,2,77,18  ; n2584 t=117.194s dur=100ms, freq=740Hz, sample=77, buffer_id=12:4D [TRUNCATE prev:ch0 @116929.8ms -> 117193.7ms]
    db 14,0,100,0,56,120,11,1,208,0,56,2  ; n2585 t=117.269s dur=100ms, freq=208Hz, sample=56, buffer_id=02:38
    db 0,0,100,0,65,110,4,2,93,1,65,4  ; n2586 t=117.283s dur=100ms, freq=349Hz, sample=65, buffer_id=04:41
    db 0,0,100,0,55,110,4,3,220,0,55,4  ; n2587 t=117.283s dur=100ms, freq=220Hz, sample=55, buffer_id=04:37
    db 0,0,100,0,60,110,4,8,233,0,60,4  ; n2588 t=117.283s dur=100ms, freq=233Hz, sample=60, buffer_id=04:3C
    db 14,0,100,0,60,110,4,9,38,1,60,4  ; n2589 t=117.283s dur=100ms, freq=294Hz, sample=60, buffer_id=04:3C
    db 0,0,100,0,84,110,16,11,151,4,84,16  ; n2590 t=117.297s dur=100ms, freq=1175Hz, sample=84, buffer_id=10:54
    db 0,0,100,0,92,90,17,10,117,5,92,17  ; n2591 t=117.297s dur=100ms, freq=1397Hz, sample=92, buffer_id=11:5C [TRUNCATE prev:ch10 @117193.7ms -> 117297.3ms]
    db 85,0,100,0,77,100,18,0,186,2,77,18  ; n2592 t=117.297s dur=100ms, freq=698Hz, sample=77, buffer_id=12:4D [TRUNCATE prev:ch0 @117193.7ms -> 117297.3ms]
    db 5,0,100,0,59,120,11,5,247,0,59,2  ; n2593 t=117.382s dur=100ms, freq=247Hz, sample=59, buffer_id=02:3B [TRUNCATE prev:ch5 @117156.0ms -> 117382.1ms]
    db 0,0,219,4,65,110,4,4,114,1,65,4  ; n2594 t=117.387s dur=1243ms, freq=370Hz, sample=65, buffer_id=04:41 [TRUNCATE prev:ch4 @117179.5ms -> 117386.8ms]
    db 0,0,219,4,60,110,4,6,233,0,60,4  ; n2595 t=117.387s dur=1243ms, freq=233Hz, sample=60, buffer_id=04:3C [TRUNCATE prev:ch6 @117179.5ms -> 117386.8ms]
    db 0,0,219,4,60,110,4,7,247,0,60,4  ; n2596 t=117.387s dur=1243ms, freq=247Hz, sample=60, buffer_id=04:3C [TRUNCATE prev:ch7 @117179.5ms -> 117386.8ms]
    db 14,0,219,4,65,110,4,12,55,1,65,4  ; n2597 t=117.387s dur=1243ms, freq=311Hz, sample=65, buffer_id=04:41 [TRUNCATE prev:ch12 @117179.5ms -> 117386.8ms]
    db 0,0,219,4,89,110,16,13,221,4,89,16  ; n2598 t=117.401s dur=1243ms, freq=1245Hz, sample=89, buffer_id=10:59 [TRUNCATE prev:ch13 @117193.7ms -> 117401.0ms]
    db 0,0,219,4,92,90,17,10,200,5,92,17  ; n2599 t=117.401s dur=1243ms, freq=1480Hz, sample=92, buffer_id=11:5C [TRUNCATE prev:ch10 @117297.3ms -> 117401.0ms]
    db 207,0,219,4,77,100,18,0,228,2,77,18  ; n2600 t=117.401s dur=1243ms, freq=740Hz, sample=77, buffer_id=12:4D [TRUNCATE prev:ch0 @117297.3ms -> 117401.0ms]
    db 113,0,100,0,56,120,11,2,208,0,56,2  ; n2601 t=117.608s dur=100ms, freq=208Hz, sample=56, buffer_id=02:38
    db 113,0,100,0,56,120,11,3,208,0,56,2  ; n2602 t=117.721s dur=100ms, freq=208Hz, sample=56, buffer_id=02:38
    db 217,0,100,0,63,120,11,1,55,1,63,2  ; n2603 t=117.834s dur=100ms, freq=311Hz, sample=63, buffer_id=02:3F
    db 9,0,113,0,34,120,2,2,52,0,34,2  ; n2604 t=118.051s dur=113ms, freq=52Hz, sample=34, buffer_id=02:22
    db 113,0,100,0,56,120,11,5,208,0,56,2  ; n2605 t=118.061s dur=100ms, freq=208Hz, sample=56, buffer_id=02:38
    db 104,0,100,0,56,120,11,1,208,0,56,2  ; n2606 t=118.174s dur=100ms, freq=208Hz, sample=56, buffer_id=02:38
    db 9,0,113,0,36,120,2,3,69,0,36,2  ; n2607 t=118.277s dur=113ms, freq=69Hz, sample=36, buffer_id=02:24
    db 226,0,100,0,59,120,11,8,247,0,59,2  ; n2608 t=118.287s dur=100ms, freq=247Hz, sample=59, buffer_id=02:3B
    db 113,0,100,0,56,120,11,2,208,0,56,2  ; n2609 t=118.513s dur=100ms, freq=208Hz, sample=56, buffer_id=02:38
    db 113,0,100,0,56,120,11,3,208,0,56,2  ; n2610 t=118.626s dur=100ms, freq=208Hz, sample=56, buffer_id=02:38
    db 217,0,100,0,63,120,11,1,55,1,63,2  ; n2611 t=118.739s dur=100ms, freq=311Hz, sample=63, buffer_id=02:3F
    db 9,0,113,0,34,120,2,0,52,0,34,2  ; n2612 t=118.956s dur=113ms, freq=52Hz, sample=34, buffer_id=02:22
    db 24,0,100,0,56,120,11,4,208,0,56,2  ; n2613 t=118.965s dur=100ms, freq=208Hz, sample=56, buffer_id=02:38
    db 14,0,100,0,65,110,4,2,55,1,65,4  ; n2614 t=118.989s dur=100ms, freq=311Hz, sample=65, buffer_id=04:41
    db 0,0,100,0,85,90,17,3,221,4,85,17  ; n2615 t=119.003s dur=100ms, freq=1245Hz, sample=85, buffer_id=11:55
    db 75,0,100,0,77,100,18,5,110,2,77,18  ; n2616 t=119.003s dur=100ms, freq=622Hz, sample=77, buffer_id=12:4D
    db 14,0,100,0,56,120,11,1,208,0,56,2  ; n2617 t=119.078s dur=100ms, freq=208Hz, sample=56, buffer_id=02:38
    db 14,0,100,0,65,110,4,6,55,1,65,4  ; n2618 t=119.092s dur=100ms, freq=311Hz, sample=65, buffer_id=04:41
    db 0,0,100,0,85,90,17,7,221,4,85,17  ; n2619 t=119.106s dur=100ms, freq=1245Hz, sample=85, buffer_id=11:55
    db 75,0,100,0,77,100,18,8,110,2,77,18  ; n2620 t=119.106s dur=100ms, freq=622Hz, sample=77, buffer_id=12:4D
    db 10,0,113,0,36,120,3,9,69,0,36,2  ; n2621 t=119.182s dur=113ms, freq=69Hz, sample=36, buffer_id=02:24
    db 5,0,100,0,61,120,11,10,21,1,61,2  ; n2622 t=119.191s dur=100ms, freq=277Hz, sample=61, buffer_id=02:3D
    db 0,0,100,0,70,110,4,11,159,1,70,4  ; n2623 t=119.196s dur=100ms, freq=415Hz, sample=70, buffer_id=04:46
    db 0,0,100,0,60,110,4,12,6,1,60,4  ; n2624 t=119.196s dur=100ms, freq=262Hz, sample=60, buffer_id=04:3C
    db 0,0,100,0,60,110,4,13,21,1,60,4  ; n2625 t=119.196s dur=100ms, freq=277Hz, sample=60, buffer_id=04:3C
    db 14,0,100,0,65,110,4,2,93,1,65,4  ; n2626 t=119.196s dur=100ms, freq=349Hz, sample=65, buffer_id=04:41 [TRUNCATE prev:ch2 @118988.7ms -> 119196.0ms]
    db 0,0,100,0,89,110,16,0,117,5,89,16  ; n2627 t=119.210s dur=100ms, freq=1397Hz, sample=89, buffer_id=10:59 [TRUNCATE prev:ch0 @118955.7ms -> 119210.1ms]
    db 0,0,100,0,92,90,17,4,125,6,92,17  ; n2628 t=119.210s dur=100ms, freq=1661Hz, sample=92, buffer_id=11:5C [TRUNCATE prev:ch4 @118965.1ms -> 119210.1ms]
    db 207,0,100,0,81,100,18,3,63,3,81,18  ; n2629 t=119.210s dur=100ms, freq=831Hz, sample=81, buffer_id=12:51 [TRUNCATE prev:ch3 @119002.8ms -> 119210.1ms]
    db 24,0,100,0,56,120,11,5,208,0,56,2  ; n2630 t=119.417s dur=100ms, freq=208Hz, sample=56, buffer_id=02:38
    db 14,0,100,0,60,110,4,1,21,1,60,4  ; n2631 t=119.441s dur=100ms, freq=277Hz, sample=60, buffer_id=04:3C
    db 0,0,100,0,85,90,17,6,85,4,85,17  ; n2632 t=119.455s dur=100ms, freq=1109Hz, sample=85, buffer_id=11:55
    db 75,0,100,0,70,100,18,7,42,2,70,18  ; n2633 t=119.455s dur=100ms, freq=554Hz, sample=70, buffer_id=12:46
    db 14,0,100,0,56,120,11,0,208,0,56,2  ; n2634 t=119.531s dur=100ms, freq=208Hz, sample=56, buffer_id=02:38
    db 14,0,100,0,60,110,4,2,6,1,60,4  ; n2635 t=119.545s dur=100ms, freq=262Hz, sample=60, buffer_id=04:3C
    db 0,0,100,0,85,90,17,3,23,4,85,17  ; n2636 t=119.559s dur=100ms, freq=1047Hz, sample=85, buffer_id=11:55
    db 75,0,100,0,70,100,18,4,11,2,70,18  ; n2637 t=119.559s dur=100ms, freq=523Hz, sample=70, buffer_id=12:46
    db 9,0,113,0,36,120,3,8,69,0,36,2  ; n2638 t=119.634s dur=113ms, freq=69Hz, sample=36, buffer_id=02:24
    db 5,0,100,0,56,120,11,9,208,0,56,2  ; n2639 t=119.644s dur=100ms, freq=208Hz, sample=56, buffer_id=02:38
    db 14,0,100,0,60,110,4,10,21,1,60,4  ; n2640 t=119.648s dur=100ms, freq=277Hz, sample=60, buffer_id=04:3C
    db 0,0,100,0,85,90,17,11,85,4,85,17  ; n2641 t=119.662s dur=100ms, freq=1109Hz, sample=85, buffer_id=11:55
    db 207,0,100,0,70,100,18,12,42,2,70,18  ; n2642 t=119.662s dur=100ms, freq=554Hz, sample=70, buffer_id=12:46
    db 5,0,100,0,61,120,11,0,21,1,61,2  ; n2643 t=119.870s dur=100ms, freq=277Hz, sample=61, buffer_id=02:3D
    db 0,0,100,0,70,110,4,1,159,1,70,4  ; n2644 t=119.874s dur=100ms, freq=415Hz, sample=70, buffer_id=04:46
    db 0,0,100,0,60,110,4,3,6,1,60,4  ; n2645 t=119.874s dur=100ms, freq=262Hz, sample=60, buffer_id=04:3C
    db 0,0,100,0,60,110,4,4,21,1,60,4  ; n2646 t=119.874s dur=100ms, freq=277Hz, sample=60, buffer_id=04:3C
    db 14,0,100,0,65,110,4,2,93,1,65,4  ; n2647 t=119.874s dur=100ms, freq=349Hz, sample=65, buffer_id=04:41
    db 0,0,100,0,89,110,16,5,117,5,89,16  ; n2648 t=119.888s dur=100ms, freq=1397Hz, sample=89, buffer_id=10:59
    db 0,0,100,0,92,90,17,6,125,6,92,17  ; n2649 t=119.888s dur=100ms, freq=1661Hz, sample=92, buffer_id=11:5C
    db 207,0,100,0,81,100,18,7,63,3,81,18  ; n2650 t=119.888s dur=100ms, freq=831Hz, sample=81, buffer_id=12:51
    db 24,0,100,0,56,120,11,8,208,0,56,2  ; n2651 t=120.096s dur=100ms, freq=208Hz, sample=56, buffer_id=02:38
    db 14,0,100,0,60,110,4,9,21,1,60,4  ; n2652 t=120.119s dur=100ms, freq=277Hz, sample=60, buffer_id=04:3C
    db 0,0,100,0,85,90,17,10,85,4,85,17  ; n2653 t=120.133s dur=100ms, freq=1109Hz, sample=85, buffer_id=11:55
    db 75,0,100,0,70,100,18,11,42,2,70,18  ; n2654 t=120.133s dur=100ms, freq=554Hz, sample=70, buffer_id=12:46
    db 14,0,100,0,56,120,11,0,208,0,56,2  ; n2655 t=120.209s dur=100ms, freq=208Hz, sample=56, buffer_id=02:38
    db 14,0,100,0,60,110,4,1,6,1,60,4  ; n2656 t=120.223s dur=100ms, freq=262Hz, sample=60, buffer_id=04:3C
    db 0,0,100,0,85,90,17,2,23,4,85,17  ; n2657 t=120.237s dur=100ms, freq=1047Hz, sample=85, buffer_id=11:55
    db 85,0,100,0,70,100,18,3,11,2,70,18  ; n2658 t=120.237s dur=100ms, freq=523Hz, sample=70, buffer_id=12:46
    db 5,0,100,0,56,120,11,4,208,0,56,2  ; n2659 t=120.322s dur=100ms, freq=208Hz, sample=56, buffer_id=02:38
    db 14,0,100,0,60,110,4,5,21,1,60,4  ; n2660 t=120.327s dur=100ms, freq=277Hz, sample=60, buffer_id=04:3C
    db 0,0,100,0,85,90,17,6,85,4,85,17  ; n2661 t=120.341s dur=100ms, freq=1109Hz, sample=85, buffer_id=11:55
    db 198,0,100,0,70,100,18,7,42,2,70,18  ; n2662 t=120.341s dur=100ms, freq=554Hz, sample=70, buffer_id=12:46
    db 9,0,113,0,43,120,3,0,104,0,43,2  ; n2663 t=120.539s dur=113ms, freq=104Hz, sample=43, buffer_id=02:2B
    db 5,0,113,0,61,120,11,1,21,1,61,2  ; n2664 t=120.548s dur=113ms, freq=277Hz, sample=61, buffer_id=02:3D
    db 0,0,100,0,70,110,4,2,159,1,70,4  ; n2665 t=120.553s dur=100ms, freq=415Hz, sample=70, buffer_id=04:46
    db 0,0,100,0,60,110,4,3,6,1,60,4  ; n2666 t=120.553s dur=100ms, freq=262Hz, sample=60, buffer_id=04:3C
    db 0,0,100,0,60,110,4,8,21,1,60,4  ; n2667 t=120.553s dur=100ms, freq=277Hz, sample=60, buffer_id=04:3C
    db 14,0,100,0,65,110,4,9,93,1,65,4  ; n2668 t=120.553s dur=100ms, freq=349Hz, sample=65, buffer_id=04:41
    db 0,0,100,0,89,110,16,10,117,5,89,16  ; n2669 t=120.567s dur=100ms, freq=1397Hz, sample=89, buffer_id=10:59
    db 0,0,100,0,92,90,17,11,125,6,92,17  ; n2670 t=120.567s dur=100ms, freq=1661Hz, sample=92, buffer_id=11:5C
    db 207,0,100,0,81,100,18,12,63,3,81,18  ; n2671 t=120.567s dur=100ms, freq=831Hz, sample=81, buffer_id=12:51
    db 23,0,100,0,59,120,11,4,247,0,59,2  ; n2672 t=120.774s dur=100ms, freq=247Hz, sample=59, buffer_id=02:3B
    db 0,0,100,0,65,110,4,5,114,1,65,4  ; n2673 t=120.798s dur=100ms, freq=370Hz, sample=65, buffer_id=04:41
    db 0,0,100,0,60,110,4,6,233,0,60,4  ; n2674 t=120.798s dur=100ms, freq=233Hz, sample=60, buffer_id=04:3C
    db 0,0,100,0,60,110,4,7,247,0,60,4  ; n2675 t=120.798s dur=100ms, freq=247Hz, sample=60, buffer_id=04:3C
    db 14,0,100,0,65,110,4,13,55,1,65,4  ; n2676 t=120.798s dur=100ms, freq=311Hz, sample=65, buffer_id=04:41
    db 0,0,100,0,89,110,16,10,221,4,89,16  ; n2677 t=120.812s dur=100ms, freq=1245Hz, sample=89, buffer_id=10:59 [TRUNCATE prev:ch10 @120567.0ms -> 120811.9ms]
    db 0,0,100,0,92,90,17,11,200,5,92,17  ; n2678 t=120.812s dur=100ms, freq=1480Hz, sample=92, buffer_id=11:5C [TRUNCATE prev:ch11 @120567.0ms -> 120811.9ms]
    db 75,0,100,0,77,100,18,0,228,2,77,18  ; n2679 t=120.812s dur=100ms, freq=740Hz, sample=77, buffer_id=12:4D [TRUNCATE prev:ch0 @120538.7ms -> 120811.9ms]
    db 14,0,100,0,58,120,11,1,233,0,58,2  ; n2680 t=120.887s dur=100ms, freq=233Hz, sample=58, buffer_id=02:3A
    db 0,0,100,0,65,110,4,2,93,1,65,4  ; n2681 t=120.901s dur=100ms, freq=349Hz, sample=65, buffer_id=04:41
    db 0,0,100,0,55,110,4,3,220,0,55,4  ; n2682 t=120.901s dur=100ms, freq=220Hz, sample=55, buffer_id=04:37
    db 0,0,100,0,60,110,4,9,233,0,60,4  ; n2683 t=120.901s dur=100ms, freq=233Hz, sample=60, buffer_id=04:3C
    db 14,0,100,0,60,110,4,12,38,1,60,4  ; n2684 t=120.901s dur=100ms, freq=294Hz, sample=60, buffer_id=04:3C
    db 0,0,100,0,84,110,16,8,151,4,84,16  ; n2685 t=120.916s dur=100ms, freq=1175Hz, sample=84, buffer_id=10:54
    db 0,0,100,0,92,90,17,11,117,5,92,17  ; n2686 t=120.916s dur=100ms, freq=1397Hz, sample=92, buffer_id=11:5C [TRUNCATE prev:ch11 @120811.9ms -> 120915.6ms]
    db 85,0,100,0,77,100,18,0,186,2,77,18  ; n2687 t=120.916s dur=100ms, freq=698Hz, sample=77, buffer_id=12:4D [TRUNCATE prev:ch0 @120811.9ms -> 120915.6ms]
    db 5,0,100,0,59,120,11,4,247,0,59,2  ; n2688 t=121.000s dur=100ms, freq=247Hz, sample=59, buffer_id=02:3B [TRUNCATE prev:ch4 @120774.3ms -> 121000.4ms]
    db 0,0,100,0,65,110,4,5,114,1,65,4  ; n2689 t=121.005s dur=100ms, freq=370Hz, sample=65, buffer_id=04:41 [TRUNCATE prev:ch5 @120797.8ms -> 121005.1ms]
    db 0,0,100,0,60,110,4,6,233,0,60,4  ; n2690 t=121.005s dur=100ms, freq=233Hz, sample=60, buffer_id=04:3C [TRUNCATE prev:ch6 @120797.8ms -> 121005.1ms]
    db 0,0,100,0,60,110,4,7,247,0,60,4  ; n2691 t=121.005s dur=100ms, freq=247Hz, sample=60, buffer_id=04:3C [TRUNCATE prev:ch7 @120797.8ms -> 121005.1ms]
    db 14,0,100,0,65,110,4,13,55,1,65,4  ; n2692 t=121.005s dur=100ms, freq=311Hz, sample=65, buffer_id=04:41 [TRUNCATE prev:ch13 @120797.8ms -> 121005.1ms]
    db 0,0,100,0,89,110,16,10,221,4,89,16  ; n2693 t=121.019s dur=100ms, freq=1245Hz, sample=89, buffer_id=10:59 [TRUNCATE prev:ch10 @120811.9ms -> 121019.2ms]
    db 0,0,100,0,92,90,17,11,200,5,92,17  ; n2694 t=121.019s dur=100ms, freq=1480Hz, sample=92, buffer_id=11:5C [TRUNCATE prev:ch11 @120915.6ms -> 121019.2ms]
    db 207,0,100,0,77,100,18,0,228,2,77,18  ; n2695 t=121.019s dur=100ms, freq=740Hz, sample=77, buffer_id=12:4D [TRUNCATE prev:ch0 @120915.6ms -> 121019.2ms]
    db 24,0,100,0,53,120,11,1,185,0,53,2  ; n2696 t=121.227s dur=100ms, freq=185Hz, sample=53, buffer_id=02:35
    db 14,0,100,0,60,110,4,2,247,0,60,4  ; n2697 t=121.250s dur=100ms, freq=247Hz, sample=60, buffer_id=04:3C
    db 0,0,100,0,85,90,17,3,220,3,85,17  ; n2698 t=121.264s dur=100ms, freq=988Hz, sample=85, buffer_id=11:55
    db 75,0,100,0,70,100,18,8,238,1,70,18  ; n2699 t=121.264s dur=100ms, freq=494Hz, sample=70, buffer_id=12:46
    db 14,0,100,0,53,120,11,0,185,0,53,2  ; n2700 t=121.340s dur=100ms, freq=185Hz, sample=53, buffer_id=02:35
    db 14,0,100,0,60,110,4,4,233,0,60,4  ; n2701 t=121.354s dur=100ms, freq=233Hz, sample=60, buffer_id=04:3C
    db 0,0,100,0,79,90,17,5,164,3,79,17  ; n2702 t=121.368s dur=100ms, freq=932Hz, sample=79, buffer_id=11:4F
    db 75,0,100,0,70,100,18,6,210,1,70,18  ; n2703 t=121.368s dur=100ms, freq=466Hz, sample=70, buffer_id=12:46
    db 9,0,113,0,34,120,3,7,62,0,34,2  ; n2704 t=121.443s dur=113ms, freq=62Hz, sample=34, buffer_id=02:22
    db 5,0,100,0,53,120,11,9,185,0,53,2  ; n2705 t=121.453s dur=100ms, freq=185Hz, sample=53, buffer_id=02:35
    db 14,0,100,0,60,110,4,10,247,0,60,4  ; n2706 t=121.457s dur=100ms, freq=247Hz, sample=60, buffer_id=04:3C
    db 0,0,100,0,85,90,17,11,220,3,85,17  ; n2707 t=121.472s dur=100ms, freq=988Hz, sample=85, buffer_id=11:55
    db 208,0,100,0,70,100,18,12,238,1,70,18  ; n2708 t=121.472s dur=100ms, freq=494Hz, sample=70, buffer_id=12:46
    db 5,0,100,0,59,120,11,0,247,0,59,2  ; n2709 t=121.680s dur=100ms, freq=247Hz, sample=59, buffer_id=02:3B
    db 0,0,100,0,65,110,4,1,114,1,65,4  ; n2710 t=121.684s dur=100ms, freq=370Hz, sample=65, buffer_id=04:41
    db 0,0,100,0,60,110,4,3,233,0,60,4  ; n2711 t=121.684s dur=100ms, freq=233Hz, sample=60, buffer_id=04:3C
    db 0,0,100,0,60,110,4,5,247,0,60,4  ; n2712 t=121.684s dur=100ms, freq=247Hz, sample=60, buffer_id=04:3C
    db 14,0,100,0,65,110,4,2,55,1,65,4  ; n2713 t=121.684s dur=100ms, freq=311Hz, sample=65, buffer_id=04:41
    db 0,0,100,0,89,110,16,4,221,4,89,16  ; n2714 t=121.698s dur=100ms, freq=1245Hz, sample=89, buffer_id=10:59
    db 0,0,100,0,92,90,17,6,200,5,92,17  ; n2715 t=121.698s dur=100ms, freq=1480Hz, sample=92, buffer_id=11:5C
    db 208,0,100,0,77,100,18,8,228,2,77,18  ; n2716 t=121.698s dur=100ms, freq=740Hz, sample=77, buffer_id=12:4D
    db 24,0,100,0,53,120,11,7,185,0,53,2  ; n2717 t=121.906s dur=100ms, freq=185Hz, sample=53, buffer_id=02:35
    db 14,0,100,0,60,110,4,9,247,0,60,4  ; n2718 t=121.930s dur=100ms, freq=247Hz, sample=60, buffer_id=04:3C
    db 0,0,100,0,85,90,17,10,220,3,85,17  ; n2719 t=121.945s dur=100ms, freq=988Hz, sample=85, buffer_id=11:55
    db 77,0,100,0,70,100,18,11,238,1,70,18  ; n2720 t=121.945s dur=100ms, freq=494Hz, sample=70, buffer_id=12:46
    db 14,0,100,0,53,120,11,0,185,0,53,2  ; n2721 t=122.022s dur=100ms, freq=185Hz, sample=53, buffer_id=02:35
    db 14,0,100,0,60,110,4,1,233,0,60,4  ; n2722 t=122.036s dur=100ms, freq=233Hz, sample=60, buffer_id=04:3C
    db 0,0,100,0,79,90,17,2,164,3,79,17  ; n2723 t=122.051s dur=100ms, freq=932Hz, sample=79, buffer_id=11:4F
    db 87,0,100,0,70,100,18,3,210,1,70,18  ; n2724 t=122.051s dur=100ms, freq=466Hz, sample=70, buffer_id=12:46
    db 5,0,100,0,53,120,11,4,185,0,53,2  ; n2725 t=122.138s dur=100ms, freq=185Hz, sample=53, buffer_id=02:35
    db 14,0,100,0,60,110,4,6,247,0,60,4  ; n2726 t=122.143s dur=100ms, freq=247Hz, sample=60, buffer_id=04:3C
    db 0,0,100,0,85,90,17,5,220,3,85,17  ; n2727 t=122.157s dur=100ms, freq=988Hz, sample=85, buffer_id=11:55
    db 203,0,100,0,70,100,18,8,238,1,70,18  ; n2728 t=122.157s dur=100ms, freq=494Hz, sample=70, buffer_id=12:46
    db 10,0,115,0,41,120,3,0,92,0,41,2  ; n2729 t=122.360s dur=115ms, freq=92Hz, sample=41, buffer_id=02:29
    db 5,0,115,0,59,120,11,1,247,0,59,2  ; n2730 t=122.370s dur=115ms, freq=247Hz, sample=59, buffer_id=02:3B
    db 0,0,100,0,65,110,4,2,114,1,65,4  ; n2731 t=122.374s dur=100ms, freq=370Hz, sample=65, buffer_id=04:41
    db 0,0,100,0,60,110,4,3,233,0,60,4  ; n2732 t=122.374s dur=100ms, freq=233Hz, sample=60, buffer_id=04:3C
    db 0,0,100,0,60,110,4,7,247,0,60,4  ; n2733 t=122.374s dur=100ms, freq=247Hz, sample=60, buffer_id=04:3C
    db 14,0,100,0,65,110,4,9,55,1,65,4  ; n2734 t=122.374s dur=100ms, freq=311Hz, sample=65, buffer_id=04:41
    db 0,0,100,0,89,110,16,10,221,4,89,16  ; n2735 t=122.389s dur=100ms, freq=1245Hz, sample=89, buffer_id=10:59
    db 0,0,100,0,92,90,17,11,200,5,92,17  ; n2736 t=122.389s dur=100ms, freq=1480Hz, sample=92, buffer_id=11:5C
    db 212,0,100,0,77,100,18,12,228,2,77,18  ; n2737 t=122.389s dur=100ms, freq=740Hz, sample=77, buffer_id=12:4D
    db 24,0,100,0,58,120,11,4,233,0,58,2  ; n2738 t=122.601s dur=100ms, freq=233Hz, sample=58, buffer_id=02:3A
    db 0,0,100,0,65,110,4,5,93,1,65,4  ; n2739 t=122.626s dur=100ms, freq=349Hz, sample=65, buffer_id=04:41
    db 0,0,100,0,55,110,4,6,220,0,55,4  ; n2740 t=122.626s dur=100ms, freq=220Hz, sample=55, buffer_id=04:37
    db 0,0,100,0,60,110,4,8,233,0,60,4  ; n2741 t=122.626s dur=100ms, freq=233Hz, sample=60, buffer_id=04:3C
    db 14,0,100,0,60,110,4,13,38,1,60,4  ; n2742 t=122.626s dur=100ms, freq=294Hz, sample=60, buffer_id=04:3C
    db 0,0,100,0,84,110,16,0,151,4,84,16  ; n2743 t=122.640s dur=100ms, freq=1175Hz, sample=84, buffer_id=10:54 [TRUNCATE prev:ch0 @122360.0ms -> 122640.1ms]
    db 0,0,100,0,92,90,17,11,117,5,92,17  ; n2744 t=122.640s dur=100ms, freq=1397Hz, sample=92, buffer_id=11:5C [TRUNCATE prev:ch11 @122388.9ms -> 122640.1ms]
    db 77,0,100,0,77,100,18,12,186,2,77,18  ; n2745 t=122.640s dur=100ms, freq=698Hz, sample=77, buffer_id=12:4D [TRUNCATE prev:ch12 @122388.9ms -> 122640.1ms]
    db 14,0,100,0,56,120,11,1,220,0,56,2  ; n2746 t=122.717s dur=100ms, freq=220Hz, sample=56, buffer_id=02:38
    db 0,0,100,0,65,110,4,3,74,1,65,4  ; n2747 t=122.732s dur=100ms, freq=330Hz, sample=65, buffer_id=04:41
    db 0,0,100,0,55,110,4,2,208,0,55,4  ; n2748 t=122.732s dur=100ms, freq=208Hz, sample=55, buffer_id=04:37
    db 0,0,100,0,55,110,4,7,220,0,55,4  ; n2749 t=122.732s dur=100ms, freq=220Hz, sample=55, buffer_id=04:37
    db 14,0,100,0,60,110,4,9,21,1,60,4  ; n2750 t=122.732s dur=100ms, freq=277Hz, sample=60, buffer_id=04:3C
    db 0,0,100,0,84,110,16,10,85,4,84,16  ; n2751 t=122.746s dur=100ms, freq=1109Hz, sample=84, buffer_id=10:54
    db 0,0,100,0,85,90,17,4,39,5,85,17  ; n2752 t=122.746s dur=100ms, freq=1319Hz, sample=85, buffer_id=11:55 [TRUNCATE prev:ch4 @122601.4ms -> 122746.3ms]
    db 87,0,100,0,77,100,18,12,147,2,77,18  ; n2753 t=122.746s dur=100ms, freq=659Hz, sample=77, buffer_id=12:4D [TRUNCATE prev:ch12 @122640.1ms -> 122746.3ms]
    db 5,0,115,0,58,120,11,5,233,0,58,2  ; n2754 t=122.833s dur=115ms, freq=233Hz, sample=58, buffer_id=02:3A [TRUNCATE prev:ch5 @122625.6ms -> 122833.3ms]
    db 0,0,166,11,65,110,4,3,93,1,65,4  ; n2755 t=122.838s dur=2982ms, freq=349Hz, sample=65, buffer_id=04:41 [TRUNCATE prev:ch3 @122731.8ms -> 122838.1ms]
    db 0,0,98,10,55,110,4,6,220,0,55,4  ; n2756 t=122.838s dur=2658ms, freq=220Hz, sample=55, buffer_id=04:37 [TRUNCATE prev:ch6 @122625.6ms -> 122838.1ms]
    db 0,0,166,11,60,110,4,8,233,0,60,4  ; n2757 t=122.838s dur=2982ms, freq=233Hz, sample=60, buffer_id=04:3C [TRUNCATE prev:ch8 @122625.6ms -> 122838.1ms]
    db 14,0,166,11,60,110,4,13,38,1,60,4  ; n2758 t=122.838s dur=2982ms, freq=294Hz, sample=60, buffer_id=04:3C [TRUNCATE prev:ch13 @122625.6ms -> 122838.1ms]
    db 0,0,64,9,84,110,16,0,151,4,84,16  ; n2759 t=122.853s dur=2368ms, freq=1175Hz, sample=84, buffer_id=10:54 [TRUNCATE prev:ch0 @122640.1ms -> 122852.6ms]
    db 0,0,169,11,92,90,17,11,117,5,92,17  ; n2760 t=122.853s dur=2985ms, freq=1397Hz, sample=92, buffer_id=11:5C [TRUNCATE prev:ch11 @122640.1ms -> 122852.6ms]
    db 179,1,169,11,77,100,18,12,186,2,77,18  ; n2761 t=122.853s dur=2985ms, freq=698Hz, sample=77, buffer_id=12:4D [TRUNCATE prev:ch12 @122746.3ms -> 122852.6ms]
    db 10,0,115,0,41,120,3,1,87,0,41,2  ; n2762 t=123.287s dur=115ms, freq=87Hz, sample=41, buffer_id=02:29
    db 0,0,207,1,53,120,11,2,175,0,53,2  ; n2763 t=123.297s dur=463ms, freq=175Hz, sample=53, buffer_id=02:35
    db 10,0,207,1,41,115,13,4,87,0,41,2  ; n2764 t=123.297s dur=463ms, freq=87Hz, sample=41, buffer_id=02:29
    db 198,1,207,1,65,120,7,5,93,1,65,2  ; n2765 t=123.307s dur=463ms, freq=349Hz, sample=65, buffer_id=02:41
    db 0,0,207,1,60,120,11,1,6,1,60,2  ; n2766 t=123.761s dur=463ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 10,0,207,1,48,115,13,7,131,0,48,2  ; n2767 t=123.761s dur=463ms, freq=131Hz, sample=48, buffer_id=02:30
    db 198,1,207,1,72,120,7,9,11,2,72,2  ; n2768 t=123.770s dur=463ms, freq=523Hz, sample=72, buffer_id=02:48
    db 0,0,15,1,56,120,11,2,196,0,56,2  ; n2769 t=124.224s dur=271ms, freq=196Hz, sample=56, buffer_id=02:38
    db 10,0,219,1,43,115,13,4,98,0,43,2  ; n2770 t=124.224s dur=475ms, freq=98Hz, sample=43, buffer_id=02:2B
    db 209,1,219,1,67,120,7,5,136,1,67,2  ; n2771 t=124.234s dur=475ms, freq=392Hz, sample=67, buffer_id=02:43
    db 0,0,219,1,65,120,11,1,93,1,65,2  ; n2772 t=124.699s dur=475ms, freq=349Hz, sample=65, buffer_id=02:41
    db 10,0,219,1,53,115,13,2,175,0,53,2  ; n2773 t=124.699s dur=475ms, freq=175Hz, sample=53, buffer_id=02:35
    db 124,0,219,1,75,120,7,7,186,2,75,2  ; n2774 t=124.709s dur=475ms, freq=698Hz, sample=75, buffer_id=02:4B
    db 55,0,100,0,41,100,22,9,87,0,41,22  ; n2775 t=124.833s dur=100ms, freq=87Hz, sample=41, buffer_id=16:29
    db 54,0,100,0,41,100,22,10,98,0,41,22  ; n2776 t=124.888s dur=100ms, freq=98Hz, sample=41, buffer_id=16:29
    db 55,0,100,0,46,100,22,4,110,0,46,22  ; n2777 t=124.942s dur=100ms, freq=110Hz, sample=46, buffer_id=16:2E
    db 55,0,100,0,46,100,22,5,117,0,46,22  ; n2778 t=124.997s dur=100ms, freq=117Hz, sample=46, buffer_id=16:2E
    db 50,0,100,0,46,100,22,4,131,0,46,22  ; n2779 t=125.051s dur=100ms, freq=131Hz, sample=46, buffer_id=16:2E [TRUNCATE prev:ch4 @124942.1ms -> 125051.1ms]
    db 54,0,100,0,51,100,22,3,147,0,51,22  ; n2780 t=125.101s dur=100ms, freq=147Hz, sample=51, buffer_id=16:33 [TRUNCATE prev:ch3 @122838.1ms -> 125100.7ms]
    db 20,0,100,0,51,100,22,9,165,0,51,22  ; n2781 t=125.155s dur=100ms, freq=165Hz, sample=51, buffer_id=16:33
    db 0,0,245,1,60,120,11,6,6,1,60,2  ; n2782 t=125.175s dur=501ms, freq=262Hz, sample=60, buffer_id=02:3C [TRUNCATE prev:ch6 @122838.1ms -> 125175.0ms]
    db 10,0,245,1,48,115,13,8,131,0,48,2  ; n2783 t=125.175s dur=501ms, freq=131Hz, sample=48, buffer_id=02:30 [TRUNCATE prev:ch8 @122838.1ms -> 125175.0ms]
    db 25,0,245,1,72,120,7,13,11,2,72,2  ; n2784 t=125.185s dur=501ms, freq=523Hz, sample=72, buffer_id=02:48 [TRUNCATE prev:ch13 @122838.1ms -> 125185.0ms]
    db 58,0,100,0,51,100,22,10,175,0,51,22  ; n2785 t=125.210s dur=100ms, freq=175Hz, sample=51, buffer_id=16:33
    db 58,0,100,0,58,100,22,0,196,0,58,22  ; n2786 t=125.268s dur=100ms, freq=196Hz, sample=58, buffer_id=16:3A [TRUNCATE prev:ch0 @122852.6ms -> 125267.9ms]
    db 58,0,100,0,58,100,22,5,220,0,58,22  ; n2787 t=125.325s dur=100ms, freq=220Hz, sample=58, buffer_id=16:3A
    db 58,0,100,0,58,100,22,1,233,0,58,22  ; n2788 t=125.383s dur=100ms, freq=233Hz, sample=58, buffer_id=16:3A
    db 58,0,100,0,58,100,22,2,6,1,58,22  ; n2789 t=125.441s dur=100ms, freq=262Hz, sample=58, buffer_id=16:3A
    db 58,0,100,0,58,100,22,3,38,1,58,22  ; n2790 t=125.498s dur=100ms, freq=294Hz, sample=58, buffer_id=16:3A
    db 58,0,100,0,58,100,22,4,74,1,58,22  ; n2791 t=125.556s dur=100ms, freq=330Hz, sample=58, buffer_id=16:3A
    db 58,0,100,0,70,100,22,0,93,1,70,22  ; n2792 t=125.613s dur=100ms, freq=349Hz, sample=70, buffer_id=16:46
    db 5,0,100,0,70,100,22,5,136,1,70,22  ; n2793 t=125.671s dur=100ms, freq=392Hz, sample=70, buffer_id=16:46
    db 0,0,50,2,67,120,11,7,184,1,67,2  ; n2794 t=125.676s dur=562ms, freq=440Hz, sample=67, buffer_id=02:43
    db 10,0,241,0,56,115,13,9,220,0,56,2  ; n2795 t=125.676s dur=241ms, freq=220Hz, sample=56, buffer_id=02:38
    db 45,0,52,2,79,120,7,1,112,3,79,2  ; n2796 t=125.687s dur=564ms, freq=880Hz, sample=79, buffer_id=02:4F
    db 65,0,100,0,70,100,22,10,184,1,70,22  ; n2797 t=125.732s dur=100ms, freq=440Hz, sample=70, buffer_id=16:46
    db 65,0,100,0,70,100,22,2,210,1,70,22  ; n2798 t=125.797s dur=100ms, freq=466Hz, sample=70, buffer_id=16:46
    db 65,0,100,0,70,100,22,3,11,2,70,22  ; n2799 t=125.862s dur=100ms, freq=523Hz, sample=70, buffer_id=16:46
    db 65,0,100,0,75,100,22,0,75,2,75,22  ; n2800 t=125.926s dur=100ms, freq=587Hz, sample=75, buffer_id=16:4B
    db 65,0,100,0,75,100,22,4,147,2,75,22  ; n2801 t=125.991s dur=100ms, freq=659Hz, sample=75, buffer_id=16:4B
    db 65,0,100,0,75,100,22,5,186,2,75,22  ; n2802 t=126.056s dur=100ms, freq=698Hz, sample=75, buffer_id=16:4B
    db 65,0,100,0,79,100,22,2,16,3,79,22  ; n2803 t=126.121s dur=100ms, freq=784Hz, sample=79, buffer_id=16:4F
    db 53,0,100,0,79,100,22,3,112,3,79,22  ; n2804 t=126.186s dur=100ms, freq=880Hz, sample=79, buffer_id=16:4F
    db 0,0,241,0,61,120,11,0,38,1,61,2  ; n2805 t=126.239s dur=241ms, freq=294Hz, sample=61, buffer_id=02:3D
    db 6,0,135,2,50,115,13,6,147,0,50,2  ; n2806 t=126.239s dur=647ms, freq=147Hz, sample=50, buffer_id=02:32
    db 6,0,136,2,50,110,4,8,147,0,50,4  ; n2807 t=126.245s dur=648ms, freq=147Hz, sample=50, buffer_id=04:32
    db 0,0,137,2,73,120,7,9,75,2,73,2  ; n2808 t=126.251s dur=649ms, freq=587Hz, sample=73, buffer_id=02:49
    db 72,0,100,0,84,100,22,10,164,3,84,22  ; n2809 t=126.251s dur=100ms, freq=932Hz, sample=84, buffer_id=16:54
    db 75,0,100,0,84,100,22,4,23,4,84,22  ; n2810 t=126.323s dur=100ms, freq=1047Hz, sample=84, buffer_id=16:54
    db 75,0,100,0,84,100,22,5,151,4,84,22  ; n2811 t=126.397s dur=100ms, freq=1175Hz, sample=84, buffer_id=16:54
    db 75,0,100,0,88,100,22,1,39,5,88,22  ; n2812 t=126.472s dur=100ms, freq=1319Hz, sample=88, buffer_id=16:58
    db 75,0,100,0,88,100,22,2,117,5,88,22  ; n2813 t=126.547s dur=100ms, freq=1397Hz, sample=88, buffer_id=16:58
    db 75,0,100,0,93,100,22,3,32,6,93,22  ; n2814 t=126.622s dur=100ms, freq=1568Hz, sample=93, buffer_id=16:5D
    db 75,0,100,0,93,100,22,0,224,6,93,22  ; n2815 t=126.696s dur=100ms, freq=1760Hz, sample=93, buffer_id=16:5D
    db 75,0,100,0,93,100,22,4,73,7,93,22  ; n2816 t=126.771s dur=100ms, freq=1865Hz, sample=93, buffer_id=16:5D
    db 27,0,100,0,98,100,22,1,45,8,98,22  ; n2817 t=126.846s dur=100ms, freq=2093Hz, sample=98, buffer_id=16:62
    db 14,0,226,12,43,120,2,2,98,0,43,2  ; n2818 t=126.873s dur=3298ms, freq=98Hz, sample=43, buffer_id=02:2B
    db 0,0,241,0,61,120,11,5,38,1,61,2  ; n2819 t=126.886s dur=241ms, freq=294Hz, sample=61, buffer_id=02:3D
    db 7,0,28,8,59,115,13,7,247,0,59,2  ; n2820 t=126.886s dur=2076ms, freq=247Hz, sample=59, buffer_id=02:3B
    db 7,0,26,8,60,110,4,10,247,0,60,4  ; n2821 t=126.893s dur=2074ms, freq=247Hz, sample=60, buffer_id=04:3C
    db 0,0,6,1,84,120,7,11,220,3,84,2  ; n2822 t=126.900s dur=262ms, freq=988Hz, sample=84, buffer_id=02:54
    db 20,0,6,1,73,120,9,12,75,2,73,2  ; n2823 t=126.900s dur=262ms, freq=587Hz, sample=73, buffer_id=02:49
    db 242,0,100,0,98,100,22,13,45,9,98,22  ; n2824 t=126.921s dur=100ms, freq=2349Hz, sample=98, buffer_id=16:62
    db 0,0,2,1,79,120,7,0,16,3,79,2  ; n2825 t=127.163s dur=258ms, freq=784Hz, sample=79, buffer_id=02:4F
    db 3,1,2,1,71,120,9,1,238,1,71,2  ; n2826 t=127.163s dur=258ms, freq=494Hz, sample=71, buffer_id=02:47
    db 0,0,2,1,84,120,7,3,220,3,84,2  ; n2827 t=127.422s dur=258ms, freq=988Hz, sample=84, buffer_id=02:54
    db 3,1,2,1,73,120,9,4,75,2,73,2  ; n2828 t=127.422s dur=258ms, freq=587Hz, sample=73, buffer_id=02:49
    db 0,0,2,1,79,120,7,1,16,3,79,2  ; n2829 t=127.680s dur=258ms, freq=784Hz, sample=79, buffer_id=02:4F
    db 3,1,2,1,71,120,9,0,238,1,71,2  ; n2830 t=127.680s dur=258ms, freq=494Hz, sample=71, buffer_id=02:47
    db 0,0,2,1,84,120,7,4,220,3,84,2  ; n2831 t=127.939s dur=258ms, freq=988Hz, sample=84, buffer_id=02:54
    db 3,1,2,1,73,120,9,3,75,2,73,2  ; n2832 t=127.939s dur=258ms, freq=587Hz, sample=73, buffer_id=02:49
    db 0,0,2,1,79,120,7,0,16,3,79,2  ; n2833 t=128.197s dur=258ms, freq=784Hz, sample=79, buffer_id=02:4F
    db 3,1,2,1,71,120,9,1,238,1,71,2  ; n2834 t=128.197s dur=258ms, freq=494Hz, sample=71, buffer_id=02:47
    db 0,0,2,1,84,120,7,3,220,3,84,2  ; n2835 t=128.456s dur=258ms, freq=988Hz, sample=84, buffer_id=02:54
    db 3,1,2,1,73,120,9,4,75,2,73,2  ; n2836 t=128.456s dur=258ms, freq=587Hz, sample=73, buffer_id=02:49
    db 0,0,2,1,79,120,7,1,16,3,79,2  ; n2837 t=128.715s dur=258ms, freq=784Hz, sample=79, buffer_id=02:4F
    db 248,0,2,1,71,120,9,0,238,1,71,2  ; n2838 t=128.715s dur=258ms, freq=494Hz, sample=71, buffer_id=02:47
    db 0,0,21,8,63,120,11,3,55,1,63,2  ; n2839 t=128.963s dur=2069ms, freq=311Hz, sample=63, buffer_id=02:3F
    db 5,0,241,0,56,115,13,4,220,0,56,2  ; n2840 t=128.963s dur=241ms, freq=220Hz, sample=56, buffer_id=02:38
    db 5,0,88,1,55,110,4,5,220,0,55,4  ; n2841 t=128.968s dur=344ms, freq=220Hz, sample=55, buffer_id=04:37
    db 0,0,2,1,84,120,7,6,23,4,84,2  ; n2842 t=128.973s dur=258ms, freq=1047Hz, sample=84, buffer_id=02:54
    db 3,1,2,1,75,120,9,8,110,2,75,2  ; n2843 t=128.973s dur=258ms, freq=622Hz, sample=75, buffer_id=02:4B
    db 0,0,2,1,79,120,7,0,112,3,79,2  ; n2844 t=129.232s dur=258ms, freq=880Hz, sample=79, buffer_id=02:4F
    db 76,0,2,1,72,120,9,1,11,2,72,2  ; n2845 t=129.232s dur=258ms, freq=523Hz, sample=72, buffer_id=02:48
    db 5,0,88,1,59,115,13,9,247,0,59,2  ; n2846 t=129.307s dur=344ms, freq=247Hz, sample=59, buffer_id=02:3B
    db 178,0,88,1,60,110,4,7,247,0,60,4  ; n2847 t=129.313s dur=344ms, freq=247Hz, sample=60, buffer_id=04:3C
    db 0,0,2,1,84,120,7,4,23,4,84,2  ; n2848 t=129.490s dur=258ms, freq=1047Hz, sample=84, buffer_id=02:54
    db 162,0,2,1,75,120,9,6,110,2,75,2  ; n2849 t=129.490s dur=258ms, freq=622Hz, sample=75, buffer_id=02:4B
    db 5,0,88,1,60,115,13,5,6,1,60,2  ; n2850 t=129.652s dur=344ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 92,0,88,1,60,110,4,8,6,1,60,4  ; n2851 t=129.658s dur=344ms, freq=262Hz, sample=60, buffer_id=04:3C
    db 0,0,2,1,79,120,7,1,112,3,79,2  ; n2852 t=129.749s dur=258ms, freq=880Hz, sample=79, buffer_id=02:4F
    db 248,0,2,1,72,120,9,0,11,2,72,2  ; n2853 t=129.749s dur=258ms, freq=523Hz, sample=72, buffer_id=02:48
    db 5,0,5,2,50,115,13,4,156,0,50,2  ; n2854 t=129.997s dur=517ms, freq=156Hz, sample=50, buffer_id=02:32
    db 5,0,5,2,50,110,4,6,156,0,50,4  ; n2855 t=130.002s dur=517ms, freq=156Hz, sample=50, buffer_id=04:32
    db 0,0,2,1,84,120,7,7,23,4,84,2  ; n2856 t=130.008s dur=258ms, freq=1047Hz, sample=84, buffer_id=02:54
    db 3,1,2,1,75,120,9,9,110,2,75,2  ; n2857 t=130.008s dur=258ms, freq=622Hz, sample=75, buffer_id=02:4B
    db 0,0,2,1,79,120,7,0,112,3,79,2  ; n2858 t=130.266s dur=258ms, freq=880Hz, sample=79, buffer_id=02:4F
    db 248,0,2,1,72,120,9,1,11,2,72,2  ; n2859 t=130.266s dur=258ms, freq=523Hz, sample=72, buffer_id=02:48
    db 5,0,241,0,56,115,13,2,220,0,56,2  ; n2860 t=130.514s dur=241ms, freq=220Hz, sample=56, buffer_id=02:38
    db 5,0,5,2,55,110,4,5,220,0,55,4  ; n2861 t=130.520s dur=517ms, freq=220Hz, sample=55, buffer_id=04:37
    db 0,0,2,1,84,120,7,8,23,4,84,2  ; n2862 t=130.525s dur=258ms, freq=1047Hz, sample=84, buffer_id=02:54
    db 3,1,2,1,75,120,9,7,110,2,75,2  ; n2863 t=130.525s dur=258ms, freq=622Hz, sample=75, buffer_id=02:4B
    db 0,0,2,1,79,120,7,1,112,3,79,2  ; n2864 t=130.784s dur=258ms, freq=880Hz, sample=79, buffer_id=02:4F
    db 237,0,2,1,72,120,9,0,11,2,72,2  ; n2865 t=130.784s dur=258ms, freq=523Hz, sample=72, buffer_id=02:48
    db 11,0,226,12,43,120,2,2,98,0,43,2  ; n2866 t=131.021s dur=3298ms, freq=98Hz, sample=43, buffer_id=02:2B
    db 0,0,21,8,63,120,11,4,74,1,63,2  ; n2867 t=131.031s dur=2069ms, freq=330Hz, sample=63, buffer_id=02:3F
    db 5,0,21,8,59,115,13,6,247,0,59,2  ; n2868 t=131.031s dur=2069ms, freq=247Hz, sample=59, buffer_id=02:3B
    db 5,0,21,8,60,110,4,7,247,0,60,4  ; n2869 t=131.037s dur=2069ms, freq=247Hz, sample=60, buffer_id=04:3C
    db 0,0,2,1,84,120,7,9,220,3,84,2  ; n2870 t=131.042s dur=258ms, freq=988Hz, sample=84, buffer_id=02:54
    db 3,1,2,1,75,120,9,8,147,2,75,2  ; n2871 t=131.042s dur=258ms, freq=659Hz, sample=75, buffer_id=02:4B
    db 0,0,2,1,79,120,7,0,16,3,79,2  ; n2872 t=131.301s dur=258ms, freq=784Hz, sample=79, buffer_id=02:4F
    db 3,1,2,1,71,120,9,1,238,1,71,2  ; n2873 t=131.301s dur=258ms, freq=494Hz, sample=71, buffer_id=02:47
    db 0,0,2,1,84,120,7,3,220,3,84,2  ; n2874 t=131.560s dur=258ms, freq=988Hz, sample=84, buffer_id=02:54
    db 3,1,2,1,75,120,9,5,147,2,75,2  ; n2875 t=131.560s dur=258ms, freq=659Hz, sample=75, buffer_id=02:4B
    db 0,0,2,1,79,120,7,1,16,3,79,2  ; n2876 t=131.818s dur=258ms, freq=784Hz, sample=79, buffer_id=02:4F
    db 3,1,2,1,71,120,9,0,238,1,71,2  ; n2877 t=131.818s dur=258ms, freq=494Hz, sample=71, buffer_id=02:47
    db 0,0,2,1,84,120,7,5,220,3,84,2  ; n2878 t=132.077s dur=258ms, freq=988Hz, sample=84, buffer_id=02:54
    db 3,1,2,1,75,120,9,3,147,2,75,2  ; n2879 t=132.077s dur=258ms, freq=659Hz, sample=75, buffer_id=02:4B
    db 0,0,2,1,79,120,7,0,16,3,79,2  ; n2880 t=132.335s dur=258ms, freq=784Hz, sample=79, buffer_id=02:4F
    db 3,1,2,1,71,120,9,1,238,1,71,2  ; n2881 t=132.335s dur=258ms, freq=494Hz, sample=71, buffer_id=02:47
    db 0,0,2,1,84,120,7,3,220,3,84,2  ; n2882 t=132.594s dur=258ms, freq=988Hz, sample=84, buffer_id=02:54
    db 3,1,2,1,75,120,9,5,147,2,75,2  ; n2883 t=132.594s dur=258ms, freq=659Hz, sample=75, buffer_id=02:4B
    db 0,0,2,1,79,120,7,1,16,3,79,2  ; n2884 t=132.853s dur=258ms, freq=784Hz, sample=79, buffer_id=02:4F
    db 248,0,2,1,71,120,9,0,238,1,71,2  ; n2885 t=132.853s dur=258ms, freq=494Hz, sample=71, buffer_id=02:47
    db 0,0,21,8,63,120,11,3,55,1,63,2  ; n2886 t=133.101s dur=2069ms, freq=311Hz, sample=63, buffer_id=02:3F
    db 5,0,241,0,56,115,13,5,220,0,56,2  ; n2887 t=133.101s dur=241ms, freq=220Hz, sample=56, buffer_id=02:38
    db 5,0,88,1,55,110,4,8,220,0,55,4  ; n2888 t=133.106s dur=344ms, freq=220Hz, sample=55, buffer_id=04:37
    db 0,0,2,1,79,120,7,9,112,3,79,2  ; n2889 t=133.111s dur=258ms, freq=880Hz, sample=79, buffer_id=02:4F
    db 3,1,2,1,72,120,9,10,11,2,72,2  ; n2890 t=133.111s dur=258ms, freq=523Hz, sample=72, buffer_id=02:48
    db 0,0,2,1,75,120,7,0,110,2,75,2  ; n2891 t=133.370s dur=258ms, freq=622Hz, sample=75, buffer_id=02:4B
    db 76,0,2,1,67,120,9,1,184,1,67,2  ; n2892 t=133.370s dur=258ms, freq=440Hz, sample=67, buffer_id=02:43
    db 5,0,88,1,59,115,13,4,247,0,59,2  ; n2893 t=133.445s dur=344ms, freq=247Hz, sample=59, buffer_id=02:3B
    db 178,0,88,1,60,110,4,6,247,0,60,4  ; n2894 t=133.451s dur=344ms, freq=247Hz, sample=60, buffer_id=04:3C
    db 0,0,2,1,79,120,7,5,112,3,79,2  ; n2895 t=133.629s dur=258ms, freq=880Hz, sample=79, buffer_id=02:4F
    db 162,0,2,1,72,120,9,7,11,2,72,2  ; n2896 t=133.629s dur=258ms, freq=523Hz, sample=72, buffer_id=02:48
    db 5,0,88,1,60,115,13,8,6,1,60,2  ; n2897 t=133.790s dur=344ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 92,0,88,1,60,110,4,9,6,1,60,4  ; n2898 t=133.796s dur=344ms, freq=262Hz, sample=60, buffer_id=04:3C
    db 0,0,2,1,75,120,7,1,110,2,75,2  ; n2899 t=133.887s dur=258ms, freq=622Hz, sample=75, buffer_id=02:4B
    db 248,0,2,1,67,120,9,0,184,1,67,2  ; n2900 t=133.887s dur=258ms, freq=440Hz, sample=67, buffer_id=02:43
    db 5,0,5,2,50,115,13,4,156,0,50,2  ; n2901 t=134.135s dur=517ms, freq=156Hz, sample=50, buffer_id=02:32
    db 5,0,5,2,50,110,4,5,156,0,50,4  ; n2902 t=134.140s dur=517ms, freq=156Hz, sample=50, buffer_id=04:32
    db 0,0,2,1,79,120,7,6,112,3,79,2  ; n2903 t=134.146s dur=258ms, freq=880Hz, sample=79, buffer_id=02:4F
    db 3,1,2,1,72,120,9,11,11,2,72,2  ; n2904 t=134.146s dur=258ms, freq=523Hz, sample=72, buffer_id=02:48
    db 0,0,2,1,75,120,7,0,110,2,75,2  ; n2905 t=134.404s dur=258ms, freq=622Hz, sample=75, buffer_id=02:4B
    db 248,0,2,1,67,120,9,1,184,1,67,2  ; n2906 t=134.404s dur=258ms, freq=440Hz, sample=67, buffer_id=02:43
    db 5,0,241,0,56,115,13,2,220,0,56,2  ; n2907 t=134.652s dur=241ms, freq=220Hz, sample=56, buffer_id=02:38
    db 5,0,5,2,55,110,4,6,220,0,55,4  ; n2908 t=134.658s dur=517ms, freq=220Hz, sample=55, buffer_id=04:37
    db 0,0,2,1,79,120,7,7,112,3,79,2  ; n2909 t=134.663s dur=258ms, freq=880Hz, sample=79, buffer_id=02:4F
    db 3,1,2,1,72,120,9,8,11,2,72,2  ; n2910 t=134.663s dur=258ms, freq=523Hz, sample=72, buffer_id=02:48
    db 0,0,2,1,75,120,7,1,110,2,75,2  ; n2911 t=134.922s dur=258ms, freq=622Hz, sample=75, buffer_id=02:4B
    db 237,0,2,1,67,120,9,0,184,1,67,2  ; n2912 t=134.922s dur=258ms, freq=440Hz, sample=67, buffer_id=02:43
    db 11,0,226,12,43,120,2,2,98,0,43,2  ; n2913 t=135.159s dur=3298ms, freq=98Hz, sample=43, buffer_id=02:2B
    db 0,0,10,4,66,120,11,4,114,1,66,2  ; n2914 t=135.169s dur=1034ms, freq=370Hz, sample=66, buffer_id=02:42
    db 5,0,88,1,59,115,13,5,247,0,59,2  ; n2915 t=135.169s dur=344ms, freq=247Hz, sample=59, buffer_id=02:3B
    db 5,0,88,1,60,110,4,7,247,0,60,4  ; n2916 t=135.175s dur=344ms, freq=247Hz, sample=60, buffer_id=04:3C
    db 0,0,2,1,79,120,7,8,228,2,79,2  ; n2917 t=135.180s dur=258ms, freq=740Hz, sample=79, buffer_id=02:4F
    db 3,1,2,1,71,120,9,9,238,1,71,2  ; n2918 t=135.180s dur=258ms, freq=494Hz, sample=71, buffer_id=02:47
    db 0,0,2,1,73,120,7,0,75,2,73,2  ; n2919 t=135.439s dur=258ms, freq=587Hz, sample=73, buffer_id=02:49
    db 75,0,2,1,67,120,9,1,136,1,67,2  ; n2920 t=135.439s dur=258ms, freq=392Hz, sample=67, buffer_id=02:43
    db 5,0,88,1,60,115,13,3,6,1,60,2  ; n2921 t=135.514s dur=344ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 178,0,88,1,60,110,4,6,6,1,60,4  ; n2922 t=135.520s dur=344ms, freq=262Hz, sample=60, buffer_id=04:3C
    db 0,0,2,1,79,120,7,9,228,2,79,2  ; n2923 t=135.697s dur=258ms, freq=740Hz, sample=79, buffer_id=02:4F
    db 162,0,2,1,71,120,9,8,238,1,71,2  ; n2924 t=135.697s dur=258ms, freq=494Hz, sample=71, buffer_id=02:47
    db 5,0,241,0,61,115,13,5,38,1,61,2  ; n2925 t=135.859s dur=241ms, freq=294Hz, sample=61, buffer_id=02:3D
    db 92,0,88,1,60,110,4,10,38,1,60,4  ; n2926 t=135.864s dur=344ms, freq=294Hz, sample=60, buffer_id=04:3C
    db 0,0,2,1,73,120,7,1,75,2,73,2  ; n2927 t=135.956s dur=258ms, freq=587Hz, sample=73, buffer_id=02:49
    db 248,0,2,1,67,120,9,0,136,1,67,2  ; n2928 t=135.956s dur=258ms, freq=392Hz, sample=67, buffer_id=02:43
    db 0,0,10,4,67,120,11,3,136,1,67,2  ; n2929 t=136.204s dur=1034ms, freq=392Hz, sample=67, buffer_id=02:43
    db 5,0,5,2,65,115,13,6,93,1,65,2  ; n2930 t=136.204s dur=517ms, freq=349Hz, sample=65, buffer_id=02:41
    db 5,0,5,2,65,110,4,7,93,1,65,4  ; n2931 t=136.209s dur=517ms, freq=349Hz, sample=65, buffer_id=04:41
    db 0,0,2,1,79,120,7,8,16,3,79,2  ; n2932 t=136.215s dur=258ms, freq=784Hz, sample=79, buffer_id=02:4F
    db 3,1,2,1,72,120,9,9,11,2,72,2  ; n2933 t=136.215s dur=258ms, freq=523Hz, sample=72, buffer_id=02:48
    db 0,0,2,1,75,120,7,0,110,2,75,2  ; n2934 t=136.473s dur=258ms, freq=622Hz, sample=75, buffer_id=02:4B
    db 248,0,2,1,67,120,9,1,136,1,67,2  ; n2935 t=136.473s dur=258ms, freq=392Hz, sample=67, buffer_id=02:43
    db 5,0,5,2,63,115,13,4,55,1,63,2  ; n2936 t=136.721s dur=517ms, freq=311Hz, sample=63, buffer_id=02:3F
    db 5,0,5,2,65,110,4,5,55,1,65,4  ; n2937 t=136.726s dur=517ms, freq=311Hz, sample=65, buffer_id=04:41
    db 0,0,2,1,79,120,7,9,16,3,79,2  ; n2938 t=136.732s dur=258ms, freq=784Hz, sample=79, buffer_id=02:4F
    db 3,1,2,1,72,120,9,8,11,2,72,2  ; n2939 t=136.732s dur=258ms, freq=523Hz, sample=72, buffer_id=02:48
    db 0,0,2,1,75,120,7,1,110,2,75,2  ; n2940 t=136.990s dur=258ms, freq=622Hz, sample=75, buffer_id=02:4B
    db 248,0,2,1,67,120,9,0,136,1,67,2  ; n2941 t=136.990s dur=258ms, freq=392Hz, sample=67, buffer_id=02:43
    db 0,0,91,6,67,120,11,6,159,1,67,2  ; n2942 t=137.238s dur=1627ms, freq=415Hz, sample=67, buffer_id=02:43
    db 5,0,88,1,50,115,13,7,156,0,50,2  ; n2943 t=137.238s dur=344ms, freq=156Hz, sample=50, buffer_id=02:32
    db 5,0,88,1,50,110,4,8,156,0,50,4  ; n2944 t=137.244s dur=344ms, freq=156Hz, sample=50, buffer_id=04:32
    db 0,0,2,1,79,120,7,10,63,3,79,2  ; n2945 t=137.249s dur=258ms, freq=831Hz, sample=79, buffer_id=02:4F
    db 3,1,2,1,72,120,9,9,11,2,72,2  ; n2946 t=137.249s dur=258ms, freq=523Hz, sample=72, buffer_id=02:48
    db 0,0,2,1,75,120,7,0,110,2,75,2  ; n2947 t=137.508s dur=258ms, freq=622Hz, sample=75, buffer_id=02:4B
    db 75,0,2,1,67,120,9,1,159,1,67,2  ; n2948 t=137.508s dur=258ms, freq=415Hz, sample=67, buffer_id=02:43
    db 5,0,0,1,56,115,13,3,208,0,56,2  ; n2949 t=137.583s dur=256ms, freq=208Hz, sample=56, buffer_id=02:38
    db 178,0,88,1,55,110,4,4,208,0,55,4  ; n2950 t=137.589s dur=344ms, freq=208Hz, sample=55, buffer_id=04:37
    db 0,0,2,1,84,120,7,5,23,4,84,2  ; n2951 t=137.766s dur=258ms, freq=1047Hz, sample=84, buffer_id=02:54
    db 162,0,2,1,75,120,9,9,110,2,75,2  ; n2952 t=137.766s dur=258ms, freq=622Hz, sample=75, buffer_id=02:4B
    db 5,0,241,0,56,115,13,7,220,0,56,2  ; n2953 t=137.928s dur=241ms, freq=220Hz, sample=56, buffer_id=02:38
    db 92,0,88,1,55,110,4,8,220,0,55,4  ; n2954 t=137.933s dur=344ms, freq=220Hz, sample=55, buffer_id=04:37
    db 0,0,2,1,79,120,7,0,63,3,79,2  ; n2955 t=138.025s dur=258ms, freq=831Hz, sample=79, buffer_id=02:4F
    db 248,0,2,1,72,120,9,1,11,2,72,2  ; n2956 t=138.025s dur=258ms, freq=523Hz, sample=72, buffer_id=02:48
    db 5,0,80,2,60,115,13,3,6,1,60,2  ; n2957 t=138.273s dur=592ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 5,0,81,2,60,110,4,4,6,1,60,4  ; n2958 t=138.278s dur=593ms, freq=262Hz, sample=60, buffer_id=04:3C
    db 0,0,39,1,86,120,7,5,221,4,86,2  ; n2959 t=138.284s dur=295ms, freq=1245Hz, sample=86, buffer_id=02:56
    db 40,1,39,1,79,120,9,9,63,3,79,2  ; n2960 t=138.284s dur=295ms, freq=831Hz, sample=79, buffer_id=02:4F
    db 0,0,42,1,84,120,7,0,23,4,84,2  ; n2961 t=138.579s dur=298ms, freq=1047Hz, sample=84, buffer_id=02:54
    db 30,1,42,1,75,120,9,1,110,2,75,2  ; n2962 t=138.579s dur=298ms, freq=622Hz, sample=75, buffer_id=02:4B
    db 0,0,131,2,67,120,11,2,136,1,67,2  ; n2963 t=138.865s dur=643ms, freq=392Hz, sample=67, buffer_id=02:43
    db 6,0,131,2,59,115,13,5,247,0,59,2  ; n2964 t=138.865s dur=643ms, freq=247Hz, sample=59, buffer_id=02:3B
    db 6,0,131,2,60,110,4,7,247,0,60,4  ; n2965 t=138.872s dur=643ms, freq=247Hz, sample=60, buffer_id=04:3C
    db 0,0,65,1,86,120,7,8,151,4,86,2  ; n2966 t=138.878s dur=321ms, freq=1175Hz, sample=86, buffer_id=02:56
    db 65,1,65,1,79,120,9,11,16,3,79,2  ; n2967 t=138.878s dur=321ms, freq=784Hz, sample=79, buffer_id=02:4F
    db 0,0,66,1,84,120,7,1,220,3,84,2  ; n2968 t=139.199s dur=322ms, freq=988Hz, sample=84, buffer_id=02:54
    db 40,1,66,1,73,120,9,0,75,2,73,2  ; n2969 t=139.199s dur=322ms, freq=587Hz, sample=73, buffer_id=02:49
    db 13,0,40,12,41,120,3,3,92,0,41,2  ; n2970 t=139.495s dur=3112ms, freq=92Hz, sample=41, buffer_id=02:29
    db 0,0,11,2,66,120,11,4,114,1,66,2  ; n2971 t=139.509s dur=523ms, freq=370Hz, sample=66, buffer_id=02:42
    db 7,0,194,11,58,115,13,6,233,0,58,2  ; n2972 t=139.509s dur=3010ms, freq=233Hz, sample=58, buffer_id=02:3A
    db 7,0,36,12,60,110,4,8,233,0,60,4  ; n2973 t=139.515s dur=3108ms, freq=233Hz, sample=60, buffer_id=04:3C
    db 0,0,6,1,84,120,7,9,85,4,84,2  ; n2974 t=139.522s dur=262ms, freq=1109Hz, sample=84, buffer_id=02:54
    db 7,1,6,1,79,120,9,12,228,2,79,2  ; n2975 t=139.522s dur=262ms, freq=740Hz, sample=79, buffer_id=02:4F
    db 0,0,2,1,84,120,7,0,164,3,84,2  ; n2976 t=139.785s dur=258ms, freq=932Hz, sample=84, buffer_id=02:54
    db 248,0,2,1,73,120,9,1,42,2,73,2  ; n2977 t=139.785s dur=258ms, freq=554Hz, sample=73, buffer_id=02:49
    db 0,0,0,1,61,120,11,2,21,1,61,2  ; n2978 t=140.032s dur=256ms, freq=277Hz, sample=61, buffer_id=02:3D
    db 11,0,10,4,66,120,11,5,114,1,66,2  ; n2979 t=140.032s dur=1034ms, freq=370Hz, sample=66, buffer_id=02:42
    db 0,0,2,1,84,120,7,7,85,4,84,2  ; n2980 t=140.043s dur=258ms, freq=1109Hz, sample=84, buffer_id=02:54
    db 3,1,2,1,79,120,9,9,228,2,79,2  ; n2981 t=140.043s dur=258ms, freq=740Hz, sample=79, buffer_id=02:4F
    db 0,0,2,1,84,120,7,1,164,3,84,2  ; n2982 t=140.302s dur=258ms, freq=932Hz, sample=84, buffer_id=02:54
    db 3,1,2,1,73,120,9,0,42,2,73,2  ; n2983 t=140.302s dur=258ms, freq=554Hz, sample=73, buffer_id=02:49
    db 0,0,2,1,84,120,7,2,85,4,84,2  ; n2984 t=140.560s dur=258ms, freq=1109Hz, sample=84, buffer_id=02:54
    db 11,0,2,1,79,120,9,4,228,2,79,2  ; n2985 t=140.560s dur=258ms, freq=740Hz, sample=79, buffer_id=02:4F
    db 248,0,2,1,77,110,16,7,228,2,77,16  ; n2986 t=140.571s dur=258ms, freq=740Hz, sample=77, buffer_id=10:4D
    db 0,0,2,1,84,120,7,0,164,3,84,2  ; n2987 t=140.819s dur=258ms, freq=932Hz, sample=84, buffer_id=02:54
    db 11,0,2,1,73,120,9,1,42,2,73,2  ; n2988 t=140.819s dur=258ms, freq=554Hz, sample=73, buffer_id=02:49
    db 237,0,2,1,84,110,16,9,164,3,84,16  ; n2989 t=140.830s dur=258ms, freq=932Hz, sample=84, buffer_id=10:54
    db 0,0,0,1,61,120,11,2,21,1,61,2  ; n2990 t=141.067s dur=256ms, freq=277Hz, sample=61, buffer_id=02:3D
    db 11,0,15,6,66,120,11,4,114,1,66,2  ; n2991 t=141.067s dur=1551ms, freq=370Hz, sample=66, buffer_id=02:42
    db 0,0,2,1,84,120,7,7,85,4,84,2  ; n2992 t=141.078s dur=258ms, freq=1109Hz, sample=84, buffer_id=02:54
    db 11,0,2,1,79,120,9,13,228,2,79,2  ; n2993 t=141.078s dur=258ms, freq=740Hz, sample=79, buffer_id=02:4F
    db 248,0,2,1,84,110,16,10,85,4,84,16  ; n2994 t=141.089s dur=258ms, freq=1109Hz, sample=84, buffer_id=10:54
    db 0,0,2,1,84,120,7,1,164,3,84,2  ; n2995 t=141.336s dur=258ms, freq=932Hz, sample=84, buffer_id=02:54
    db 11,0,2,1,73,120,9,0,42,2,73,2  ; n2996 t=141.336s dur=258ms, freq=554Hz, sample=73, buffer_id=02:49
    db 248,0,2,1,89,110,16,5,200,5,89,16  ; n2997 t=141.347s dur=258ms, freq=1480Hz, sample=89, buffer_id=10:59
    db 0,0,2,1,84,120,7,2,85,4,84,2  ; n2998 t=141.595s dur=258ms, freq=1109Hz, sample=84, buffer_id=02:54
    db 3,1,2,1,79,120,9,7,228,2,79,2  ; n2999 t=141.595s dur=258ms, freq=740Hz, sample=79, buffer_id=02:4F
    db 0,0,2,1,84,120,7,0,164,3,84,2  ; n3000 t=141.854s dur=258ms, freq=932Hz, sample=84, buffer_id=02:54
    db 3,1,2,1,73,120,9,1,42,2,73,2  ; n3001 t=141.854s dur=258ms, freq=554Hz, sample=73, buffer_id=02:49
    db 0,0,2,1,84,120,7,5,85,4,84,2  ; n3002 t=142.112s dur=258ms, freq=1109Hz, sample=84, buffer_id=02:54
    db 3,1,2,1,79,120,9,2,228,2,79,2  ; n3003 t=142.112s dur=258ms, freq=740Hz, sample=79, buffer_id=02:4F
    db 0,0,2,1,84,120,7,1,164,3,84,2  ; n3004 t=142.371s dur=258ms, freq=932Hz, sample=84, buffer_id=02:54
    db 237,0,2,1,73,120,9,0,42,2,73,2  ; n3005 t=142.371s dur=258ms, freq=554Hz, sample=73, buffer_id=02:49
    db 11,0,116,0,36,120,3,2,73,0,36,2  ; n3006 t=142.608s dur=116ms, freq=73Hz, sample=36, buffer_id=02:24
    db 5,0,245,4,50,115,13,5,147,0,50,2  ; n3007 t=142.619s dur=1269ms, freq=147Hz, sample=50, buffer_id=02:32
    db 5,0,247,4,50,110,4,7,147,0,50,4  ; n3008 t=142.624s dur=1271ms, freq=147Hz, sample=50, buffer_id=04:32
    db 0,0,33,1,86,120,7,9,151,4,86,2  ; n3009 t=142.630s dur=289ms, freq=1175Hz, sample=86, buffer_id=02:56
    db 16,0,33,1,79,120,9,10,16,3,79,2  ; n3010 t=142.630s dur=289ms, freq=784Hz, sample=79, buffer_id=02:4F
    db 42,0,100,0,36,100,22,11,73,0,36,22  ; n3011 t=142.646s dur=100ms, freq=73Hz, sample=36, buffer_id=16:24
    db 43,0,100,0,41,100,22,12,82,0,41,22  ; n3012 t=142.688s dur=100ms, freq=82Hz, sample=41, buffer_id=16:29
    db 42,0,100,0,41,100,22,6,92,0,41,22  ; n3013 t=142.731s dur=100ms, freq=92Hz, sample=41, buffer_id=16:29
    db 42,0,100,0,41,100,22,13,98,0,41,22  ; n3014 t=142.773s dur=100ms, freq=98Hz, sample=41, buffer_id=16:29
    db 42,0,100,0,46,100,22,3,110,0,46,22  ; n3015 t=142.816s dur=100ms, freq=110Hz, sample=46, buffer_id=16:2E
    db 42,0,100,0,46,100,22,0,123,0,46,22  ; n3016 t=142.858s dur=100ms, freq=123Hz, sample=46, buffer_id=16:2E
    db 18,0,100,0,46,100,22,1,131,0,46,22  ; n3017 t=142.900s dur=100ms, freq=131Hz, sample=46, buffer_id=16:2E
    db 0,0,35,1,79,120,7,4,112,3,79,2  ; n3018 t=142.919s dur=291ms, freq=880Hz, sample=79, buffer_id=02:4F
    db 24,0,35,1,73,120,9,8,75,2,73,2  ; n3019 t=142.919s dur=291ms, freq=587Hz, sample=73, buffer_id=02:49
    db 42,0,100,0,51,100,22,2,147,0,51,22  ; n3020 t=142.943s dur=100ms, freq=147Hz, sample=51, buffer_id=16:33
    db 48,0,100,0,51,100,22,11,165,0,51,22  ; n3021 t=142.986s dur=100ms, freq=165Hz, sample=51, buffer_id=16:33
    db 43,0,100,0,51,100,22,6,185,0,51,22  ; n3022 t=143.034s dur=100ms, freq=185Hz, sample=51, buffer_id=16:33
    db 42,0,100,0,58,100,22,12,196,0,58,22  ; n3023 t=143.077s dur=100ms, freq=196Hz, sample=58, buffer_id=16:3A
    db 42,0,100,0,58,100,22,3,220,0,58,22  ; n3024 t=143.119s dur=100ms, freq=220Hz, sample=58, buffer_id=16:3A
    db 24,0,100,0,58,100,22,0,247,0,58,22  ; n3025 t=143.161s dur=100ms, freq=247Hz, sample=58, buffer_id=16:3A
    db 18,0,136,0,36,120,3,9,73,0,36,2  ; n3026 t=143.186s dur=136ms, freq=73Hz, sample=36, buffer_id=02:24
    db 6,0,100,0,58,100,22,1,6,1,58,22  ; n3027 t=143.204s dur=100ms, freq=262Hz, sample=58, buffer_id=16:3A
    db 0,0,88,1,86,120,7,10,151,4,86,2  ; n3028 t=143.210s dur=344ms, freq=1175Hz, sample=86, buffer_id=02:56
    db 40,0,88,1,79,120,9,13,16,3,79,2  ; n3029 t=143.210s dur=344ms, freq=784Hz, sample=79, buffer_id=02:4F
    db 51,0,100,0,58,100,22,2,38,1,58,22  ; n3030 t=143.250s dur=100ms, freq=294Hz, sample=58, buffer_id=16:3A
    db 51,0,100,0,58,100,22,11,74,1,58,22  ; n3031 t=143.301s dur=100ms, freq=330Hz, sample=58, buffer_id=16:3A
    db 51,0,100,0,70,100,22,6,114,1,70,22  ; n3032 t=143.352s dur=100ms, freq=370Hz, sample=70, buffer_id=16:46
    db 58,0,100,0,70,100,22,12,136,1,70,22  ; n3033 t=143.402s dur=100ms, freq=392Hz, sample=70, buffer_id=16:46
    db 51,0,100,0,70,100,22,3,184,1,70,22  ; n3034 t=143.460s dur=100ms, freq=440Hz, sample=70, buffer_id=16:46
    db 44,0,100,0,70,100,22,0,238,1,70,22  ; n3035 t=143.511s dur=100ms, freq=494Hz, sample=70, buffer_id=16:46
    db 0,0,92,1,79,120,7,1,112,3,79,2  ; n3036 t=143.555s dur=348ms, freq=880Hz, sample=79, buffer_id=02:4F
    db 7,0,92,1,73,120,9,2,75,2,73,2  ; n3037 t=143.555s dur=348ms, freq=587Hz, sample=73, buffer_id=02:49
    db 51,0,100,0,70,100,22,4,11,2,70,22  ; n3038 t=143.562s dur=100ms, freq=523Hz, sample=70, buffer_id=16:46
    db 51,0,100,0,75,100,22,8,75,2,75,22  ; n3039 t=143.613s dur=100ms, freq=587Hz, sample=75, buffer_id=16:4B
    db 51,0,100,0,75,100,22,6,147,2,75,22  ; n3040 t=143.664s dur=100ms, freq=659Hz, sample=75, buffer_id=16:4B
    db 51,0,100,0,79,100,22,9,228,2,79,22  ; n3041 t=143.714s dur=100ms, freq=740Hz, sample=79, buffer_id=16:4F
    db 51,0,100,0,79,100,22,3,16,3,79,22  ; n3042 t=143.765s dur=100ms, freq=784Hz, sample=79, buffer_id=16:4F
    db 51,0,100,0,79,100,22,0,112,3,79,22  ; n3043 t=143.816s dur=100ms, freq=880Hz, sample=79, buffer_id=16:4F
    db 7,0,100,0,84,100,22,4,220,3,84,22  ; n3044 t=143.867s dur=100ms, freq=988Hz, sample=84, buffer_id=16:54
    db 14,0,123,0,43,120,3,10,98,0,43,2  ; n3045 t=143.874s dur=123ms, freq=98Hz, sample=43, buffer_id=02:2B
    db 7,0,103,8,59,115,13,11,247,0,59,2  ; n3046 t=143.889s dur=2151ms, freq=247Hz, sample=59, buffer_id=02:3B
    db 7,0,101,8,60,110,4,12,247,0,60,4  ; n3047 t=143.896s dur=2149ms, freq=247Hz, sample=60, buffer_id=04:3C
    db 0,0,16,1,86,120,7,13,151,4,86,2  ; n3048 t=143.903s dur=272ms, freq=1175Hz, sample=86, buffer_id=02:56
    db 22,0,16,1,79,120,9,1,16,3,79,2  ; n3049 t=143.903s dur=272ms, freq=784Hz, sample=79, buffer_id=02:4F [TRUNCATE prev:ch1 @143554.8ms -> 143903.1ms]
    db 0,0,94,8,60,124,14,8,247,0,60,14  ; n3050 t=143.925s dur=2142ms, freq=247Hz, sample=60, buffer_id=0E:3C
    db 0,0,94,8,50,124,14,5,147,0,50,14  ; n3051 t=143.925s dur=2142ms, freq=147Hz, sample=50, buffer_id=0E:32 [TRUNCATE prev:ch5 @142618.7ms -> 143924.9ms]
    db 251,0,94,8,43,124,14,7,98,0,43,14  ; n3052 t=143.925s dur=2142ms, freq=98Hz, sample=43, buffer_id=0E:2B [TRUNCATE prev:ch7 @142624.1ms -> 143924.9ms]
    db 0,0,11,1,84,120,7,0,220,3,84,2  ; n3053 t=144.176s dur=267ms, freq=988Hz, sample=84, buffer_id=02:54
    db 246,0,11,1,73,120,9,3,75,2,73,2  ; n3054 t=144.176s dur=267ms, freq=587Hz, sample=73, buffer_id=02:49
    db 22,0,111,0,43,120,3,1,98,0,43,2  ; n3055 t=144.422s dur=111ms, freq=98Hz, sample=43, buffer_id=02:2B
    db 0,0,11,1,86,120,7,2,151,4,86,2  ; n3056 t=144.444s dur=267ms, freq=1175Hz, sample=86, buffer_id=02:56
    db 12,1,11,1,79,120,9,4,16,3,79,2  ; n3057 t=144.444s dur=267ms, freq=784Hz, sample=79, buffer_id=02:4F
    db 0,0,11,1,84,120,7,3,220,3,84,2  ; n3058 t=144.712s dur=267ms, freq=988Hz, sample=84, buffer_id=02:54
    db 11,0,11,1,73,120,9,0,75,2,73,2  ; n3059 t=144.712s dur=267ms, freq=587Hz, sample=73, buffer_id=02:49
    db 1,1,11,1,73,110,16,6,75,2,73,16  ; n3060 t=144.723s dur=267ms, freq=587Hz, sample=73, buffer_id=10:49
    db 0,0,11,1,86,120,7,1,151,4,86,2  ; n3061 t=144.980s dur=267ms, freq=1175Hz, sample=86, buffer_id=02:56
    db 11,0,11,1,79,120,9,2,16,3,79,2  ; n3062 t=144.980s dur=267ms, freq=784Hz, sample=79, buffer_id=02:4F
    db 1,1,47,4,84,110,16,4,151,4,84,16  ; n3063 t=144.991s dur=1071ms, freq=1175Hz, sample=84, buffer_id=10:54
    db 0,0,11,1,84,120,7,0,220,3,84,2  ; n3064 t=145.247s dur=267ms, freq=988Hz, sample=84, buffer_id=02:54
    db 246,0,11,1,73,120,9,3,75,2,73,2  ; n3065 t=145.247s dur=267ms, freq=587Hz, sample=73, buffer_id=02:49
    db 22,0,111,0,43,120,3,1,98,0,43,2  ; n3066 t=145.493s dur=111ms, freq=98Hz, sample=43, buffer_id=02:2B
    db 0,0,11,1,86,120,7,2,151,4,86,2  ; n3067 t=145.515s dur=267ms, freq=1175Hz, sample=86, buffer_id=02:56
    db 12,1,11,1,79,120,9,6,16,3,79,2  ; n3068 t=145.515s dur=267ms, freq=784Hz, sample=79, buffer_id=02:4F
    db 0,0,11,1,84,120,7,3,220,3,84,2  ; n3069 t=145.783s dur=267ms, freq=988Hz, sample=84, buffer_id=02:54
    db 245,0,11,1,73,120,9,0,75,2,73,2  ; n3070 t=145.783s dur=267ms, freq=587Hz, sample=73, buffer_id=02:49
    db 11,0,111,0,43,120,3,2,98,0,43,2  ; n3071 t=146.029s dur=111ms, freq=98Hz, sample=43, buffer_id=02:2B
    db 6,0,241,0,56,115,13,1,220,0,56,2  ; n3072 t=146.040s dur=241ms, freq=220Hz, sample=56, buffer_id=02:38
    db 6,0,101,1,55,110,4,6,220,0,55,4  ; n3073 t=146.045s dur=357ms, freq=220Hz, sample=55, buffer_id=04:37
    db 0,0,11,1,84,120,7,9,23,4,84,2  ; n3074 t=146.051s dur=267ms, freq=1047Hz, sample=84, buffer_id=02:54
    db 11,0,11,1,75,120,9,10,110,2,75,2  ; n3075 t=146.051s dur=267ms, freq=622Hz, sample=75, buffer_id=02:4B
    db 6,0,94,8,84,110,16,13,23,4,84,16  ; n3076 t=146.062s dur=2142ms, freq=1047Hz, sample=84, buffer_id=10:54
    db 0,0,94,8,60,124,14,8,6,1,60,14  ; n3077 t=146.068s dur=2142ms, freq=262Hz, sample=60, buffer_id=0E:3C [TRUNCATE prev:ch8 @143924.9ms -> 146067.8ms]
    db 0,0,94,8,50,124,14,5,156,0,50,14  ; n3078 t=146.068s dur=2142ms, freq=156Hz, sample=50, buffer_id=0E:32 [TRUNCATE prev:ch5 @143924.9ms -> 146067.8ms]
    db 251,0,94,8,43,124,14,7,98,0,43,14  ; n3079 t=146.068s dur=2142ms, freq=98Hz, sample=43, buffer_id=0E:2B [TRUNCATE prev:ch7 @143924.9ms -> 146067.8ms]
    db 0,0,11,1,79,120,7,0,112,3,79,2  ; n3080 t=146.319s dur=267ms, freq=880Hz, sample=79, buffer_id=02:4F
    db 78,0,11,1,72,120,9,3,11,2,72,2  ; n3081 t=146.319s dur=267ms, freq=523Hz, sample=72, buffer_id=02:48
    db 6,0,101,1,59,115,13,2,247,0,59,2  ; n3082 t=146.397s dur=357ms, freq=247Hz, sample=59, buffer_id=02:3B
    db 162,0,101,1,60,110,4,4,247,0,60,4  ; n3083 t=146.403s dur=357ms, freq=247Hz, sample=60, buffer_id=04:3C
    db 22,0,111,0,43,120,3,1,98,0,43,2  ; n3084 t=146.564s dur=111ms, freq=98Hz, sample=43, buffer_id=02:2B
    db 0,0,11,1,84,120,7,10,23,4,84,2  ; n3085 t=146.587s dur=267ms, freq=1047Hz, sample=84, buffer_id=02:54
    db 167,0,11,1,75,120,9,9,110,2,75,2  ; n3086 t=146.587s dur=267ms, freq=622Hz, sample=75, buffer_id=02:4B
    db 6,0,101,1,60,115,13,6,6,1,60,2  ; n3087 t=146.754s dur=357ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 95,0,101,1,60,110,4,11,6,1,60,4  ; n3088 t=146.760s dur=357ms, freq=262Hz, sample=60, buffer_id=04:3C
    db 0,0,11,1,79,120,7,3,112,3,79,2  ; n3089 t=146.855s dur=267ms, freq=880Hz, sample=79, buffer_id=02:4F
    db 1,1,11,1,72,120,9,0,11,2,72,2  ; n3090 t=146.855s dur=267ms, freq=523Hz, sample=72, buffer_id=02:48
    db 6,0,23,2,50,115,13,1,156,0,50,2  ; n3091 t=147.111s dur=535ms, freq=156Hz, sample=50, buffer_id=02:32
    db 6,0,23,2,50,110,4,2,156,0,50,4  ; n3092 t=147.117s dur=535ms, freq=156Hz, sample=50, buffer_id=04:32
    db 0,0,11,1,84,120,7,4,23,4,84,2  ; n3093 t=147.122s dur=267ms, freq=1047Hz, sample=84, buffer_id=02:54
    db 12,1,11,1,75,120,9,10,110,2,75,2  ; n3094 t=147.122s dur=267ms, freq=622Hz, sample=75, buffer_id=02:4B
    db 0,0,11,1,79,120,7,0,112,3,79,2  ; n3095 t=147.390s dur=267ms, freq=880Hz, sample=79, buffer_id=02:4F
    db 245,0,11,1,72,120,9,3,11,2,72,2  ; n3096 t=147.390s dur=267ms, freq=523Hz, sample=72, buffer_id=02:48
    db 11,0,111,0,43,120,3,4,98,0,43,2  ; n3097 t=147.636s dur=111ms, freq=98Hz, sample=43, buffer_id=02:2B
    db 6,0,241,0,56,115,13,6,220,0,56,2  ; n3098 t=147.647s dur=241ms, freq=220Hz, sample=56, buffer_id=02:38
    db 6,0,23,2,55,110,4,9,220,0,55,4  ; n3099 t=147.653s dur=535ms, freq=220Hz, sample=55, buffer_id=04:37
    db 0,0,11,1,84,120,7,10,23,4,84,2  ; n3100 t=147.658s dur=267ms, freq=1047Hz, sample=84, buffer_id=02:54
    db 12,1,11,1,75,120,9,11,110,2,75,2  ; n3101 t=147.658s dur=267ms, freq=622Hz, sample=75, buffer_id=02:4B
    db 0,0,11,1,79,120,7,1,112,3,79,2  ; n3102 t=147.926s dur=267ms, freq=880Hz, sample=79, buffer_id=02:4F
    db 246,0,11,1,72,120,9,0,11,2,72,2  ; n3103 t=147.926s dur=267ms, freq=523Hz, sample=72, buffer_id=02:48
    db 11,0,111,0,43,120,3,2,98,0,43,2  ; n3104 t=148.172s dur=111ms, freq=98Hz, sample=43, buffer_id=02:2B
    db 6,0,94,8,59,115,13,3,247,0,59,2  ; n3105 t=148.183s dur=2142ms, freq=247Hz, sample=59, buffer_id=02:3B
    db 6,0,94,8,60,110,4,4,247,0,60,4  ; n3106 t=148.188s dur=2142ms, freq=247Hz, sample=60, buffer_id=04:3C
    db 0,0,11,1,84,120,7,6,220,3,84,2  ; n3107 t=148.194s dur=267ms, freq=988Hz, sample=84, buffer_id=02:54
    db 17,0,11,1,75,120,9,10,147,2,75,2  ; n3108 t=148.194s dur=267ms, freq=659Hz, sample=75, buffer_id=02:4B
    db 0,0,94,8,60,124,14,11,247,0,60,14  ; n3109 t=148.211s dur=2142ms, freq=247Hz, sample=60, buffer_id=0E:3C
    db 0,0,94,8,50,124,14,12,165,0,50,14  ; n3110 t=148.211s dur=2142ms, freq=165Hz, sample=50, buffer_id=0E:32
    db 251,0,94,8,43,124,14,7,98,0,43,14  ; n3111 t=148.211s dur=2142ms, freq=98Hz, sample=43, buffer_id=0E:2B [TRUNCATE prev:ch7 @146067.8ms -> 148210.6ms]
    db 0,0,11,1,79,120,7,0,16,3,79,2  ; n3112 t=148.462s dur=267ms, freq=784Hz, sample=79, buffer_id=02:4F
    db 246,0,11,1,71,120,9,1,238,1,71,2  ; n3113 t=148.462s dur=267ms, freq=494Hz, sample=71, buffer_id=02:47
    db 22,0,111,0,43,120,3,5,98,0,43,2  ; n3114 t=148.707s dur=111ms, freq=98Hz, sample=43, buffer_id=02:2B
    db 0,0,11,1,84,120,7,2,220,3,84,2  ; n3115 t=148.730s dur=267ms, freq=988Hz, sample=84, buffer_id=02:54
    db 12,1,11,1,75,120,9,6,147,2,75,2  ; n3116 t=148.730s dur=267ms, freq=659Hz, sample=75, buffer_id=02:4B
    db 0,0,11,1,79,120,7,1,16,3,79,2  ; n3117 t=148.997s dur=267ms, freq=784Hz, sample=79, buffer_id=02:4F
    db 12,1,11,1,71,120,9,0,238,1,71,2  ; n3118 t=148.997s dur=267ms, freq=494Hz, sample=71, buffer_id=02:47
    db 0,0,11,1,84,120,7,5,220,3,84,2  ; n3119 t=149.265s dur=267ms, freq=988Hz, sample=84, buffer_id=02:54
    db 11,0,11,1,75,120,9,2,147,2,75,2  ; n3120 t=149.265s dur=267ms, freq=659Hz, sample=75, buffer_id=02:4B
    db 1,1,11,1,84,110,16,6,220,3,84,16  ; n3121 t=149.276s dur=267ms, freq=988Hz, sample=84, buffer_id=10:54
    db 0,0,11,1,79,120,7,0,16,3,79,2  ; n3122 t=149.533s dur=267ms, freq=784Hz, sample=79, buffer_id=02:4F
    db 11,0,11,1,71,120,9,1,238,1,71,2  ; n3123 t=149.533s dur=267ms, freq=494Hz, sample=71, buffer_id=02:47
    db 234,0,11,1,77,110,16,8,16,3,77,16  ; n3124 t=149.544s dur=267ms, freq=784Hz, sample=77, buffer_id=10:4D
    db 22,0,111,0,43,120,3,2,98,0,43,2  ; n3125 t=149.779s dur=111ms, freq=98Hz, sample=43, buffer_id=02:2B
    db 0,0,11,1,84,120,7,6,220,3,84,2  ; n3126 t=149.801s dur=267ms, freq=988Hz, sample=84, buffer_id=02:54
    db 11,0,11,1,75,120,9,5,147,2,75,2  ; n3127 t=149.801s dur=267ms, freq=659Hz, sample=75, buffer_id=02:4B
    db 1,1,11,1,84,110,16,9,220,3,84,16  ; n3128 t=149.812s dur=267ms, freq=988Hz, sample=84, buffer_id=10:54
    db 0,0,11,1,79,120,7,1,16,3,79,2  ; n3129 t=150.069s dur=267ms, freq=784Hz, sample=79, buffer_id=02:4F
    db 11,0,11,1,71,120,9,0,238,1,71,2  ; n3130 t=150.069s dur=267ms, freq=494Hz, sample=71, buffer_id=02:47
    db 234,0,23,2,89,110,16,8,32,6,89,16  ; n3131 t=150.080s dur=535ms, freq=1568Hz, sample=89, buffer_id=10:59
    db 11,0,111,0,36,120,3,2,69,0,36,2  ; n3132 t=150.314s dur=111ms, freq=69Hz, sample=36, buffer_id=02:24
    db 5,0,0,1,61,115,13,5,21,1,61,2  ; n3133 t=150.326s dur=256ms, freq=277Hz, sample=61, buffer_id=02:3D
    db 6,0,101,1,60,110,4,6,21,1,60,4  ; n3134 t=150.331s dur=357ms, freq=277Hz, sample=60, buffer_id=04:3C
    db 0,0,11,1,84,120,7,9,220,3,84,2  ; n3135 t=150.337s dur=267ms, freq=988Hz, sample=84, buffer_id=02:54
    db 17,0,11,1,75,120,9,13,147,2,75,2  ; n3136 t=150.337s dur=267ms, freq=659Hz, sample=75, buffer_id=02:4B
    db 0,0,47,4,60,124,14,10,247,0,60,14  ; n3137 t=150.353s dur=1071ms, freq=247Hz, sample=60, buffer_id=0E:3C
    db 0,0,47,4,55,124,14,3,196,0,55,14  ; n3138 t=150.353s dur=1071ms, freq=196Hz, sample=55, buffer_id=0E:37 [TRUNCATE prev:ch3 @148182.7ms -> 150353.5ms]
    db 251,0,47,4,50,124,14,12,139,0,50,14  ; n3139 t=150.353s dur=1071ms, freq=139Hz, sample=50, buffer_id=0E:32 [TRUNCATE prev:ch12 @148210.6ms -> 150353.5ms]
    db 0,0,11,1,79,120,7,0,228,2,79,2  ; n3140 t=150.605s dur=267ms, freq=740Hz, sample=79, buffer_id=02:4F
    db 11,0,11,1,71,120,9,1,238,1,71,2  ; n3141 t=150.605s dur=267ms, freq=494Hz, sample=71, buffer_id=02:47
    db 67,0,37,5,89,110,16,4,200,5,89,16  ; n3142 t=150.616s dur=1317ms, freq=1480Hz, sample=89, buffer_id=10:59
    db 6,0,241,0,61,115,13,2,38,1,61,2  ; n3143 t=150.683s dur=241ms, freq=294Hz, sample=61, buffer_id=02:3D
    db 162,0,101,1,60,110,4,7,38,1,60,4  ; n3144 t=150.688s dur=357ms, freq=294Hz, sample=60, buffer_id=04:3C
    db 22,0,111,0,36,120,3,5,69,0,36,2  ; n3145 t=150.850s dur=111ms, freq=69Hz, sample=36, buffer_id=02:24
    db 0,0,11,1,84,120,7,8,220,3,84,2  ; n3146 t=150.872s dur=267ms, freq=988Hz, sample=84, buffer_id=02:54
    db 167,0,11,1,75,120,9,9,147,2,75,2  ; n3147 t=150.872s dur=267ms, freq=659Hz, sample=75, buffer_id=02:4B
    db 6,0,101,1,63,115,13,6,74,1,63,2  ; n3148 t=151.040s dur=357ms, freq=330Hz, sample=63, buffer_id=02:3F
    db 95,0,101,1,65,110,4,11,74,1,65,4  ; n3149 t=151.045s dur=357ms, freq=330Hz, sample=65, buffer_id=04:41
    db 0,0,11,1,79,120,7,1,228,2,79,2  ; n3150 t=151.140s dur=267ms, freq=740Hz, sample=79, buffer_id=02:4F
    db 1,1,11,1,71,120,9,0,238,1,71,2  ; n3151 t=151.140s dur=267ms, freq=494Hz, sample=71, buffer_id=02:47
    db 6,0,23,2,53,115,13,2,185,0,53,2  ; n3152 t=151.397s dur=535ms, freq=185Hz, sample=53, buffer_id=02:35
    db 6,0,23,2,55,110,4,5,185,0,55,4  ; n3153 t=151.403s dur=535ms, freq=185Hz, sample=55, buffer_id=04:37
    db 0,0,11,1,84,120,7,7,164,3,84,2  ; n3154 t=151.408s dur=267ms, freq=932Hz, sample=84, buffer_id=02:54
    db 17,0,11,1,75,120,9,8,147,2,75,2  ; n3155 t=151.408s dur=267ms, freq=659Hz, sample=75, buffer_id=02:4B
    db 0,0,47,4,60,124,14,9,233,0,60,14  ; n3156 t=151.425s dur=1071ms, freq=233Hz, sample=60, buffer_id=0E:3C
    db 0,0,47,4,55,124,14,13,185,0,55,14  ; n3157 t=151.425s dur=1071ms, freq=185Hz, sample=55, buffer_id=0E:37
    db 251,0,47,4,43,124,14,3,92,0,43,14  ; n3158 t=151.425s dur=1071ms, freq=92Hz, sample=43, buffer_id=0E:2B [TRUNCATE prev:ch3 @150353.5ms -> 151424.9ms]
    db 0,0,11,1,79,120,7,0,228,2,79,2  ; n3159 t=151.676s dur=267ms, freq=740Hz, sample=79, buffer_id=02:4F
    db 246,0,11,1,71,120,9,1,238,1,71,2  ; n3160 t=151.676s dur=267ms, freq=494Hz, sample=71, buffer_id=02:47
    db 11,0,111,0,41,120,3,6,92,0,41,2  ; n3161 t=151.922s dur=111ms, freq=92Hz, sample=41, buffer_id=02:29
    db 6,0,23,2,63,115,13,7,74,1,63,2  ; n3162 t=151.933s dur=535ms, freq=330Hz, sample=63, buffer_id=02:3F
    db 6,0,23,2,65,110,4,8,74,1,65,4  ; n3163 t=151.938s dur=535ms, freq=330Hz, sample=65, buffer_id=04:41
    db 0,0,11,1,84,120,7,10,164,3,84,2  ; n3164 t=151.944s dur=267ms, freq=932Hz, sample=84, buffer_id=02:54
    db 11,0,11,1,75,120,9,11,147,2,75,2  ; n3165 t=151.944s dur=267ms, freq=659Hz, sample=75, buffer_id=02:4B
    db 1,1,23,2,89,110,16,12,39,5,89,16  ; n3166 t=151.955s dur=535ms, freq=1319Hz, sample=89, buffer_id=10:59
    db 0,0,11,1,79,120,7,1,228,2,79,2  ; n3167 t=152.212s dur=267ms, freq=740Hz, sample=79, buffer_id=02:4F
    db 246,0,11,1,71,120,9,0,210,1,71,2  ; n3168 t=152.212s dur=267ms, freq=466Hz, sample=71, buffer_id=02:47
    db 11,0,111,0,34,120,3,2,62,0,34,2  ; n3169 t=152.457s dur=111ms, freq=62Hz, sample=34, buffer_id=02:22
    db 6,0,241,0,61,115,13,4,38,1,61,2  ; n3170 t=152.468s dur=241ms, freq=294Hz, sample=61, buffer_id=02:3D
    db 6,0,101,1,60,110,4,5,38,1,60,4  ; n3171 t=152.474s dur=357ms, freq=294Hz, sample=60, buffer_id=04:3C
    db 0,0,11,1,84,120,7,6,220,3,84,2  ; n3172 t=152.480s dur=267ms, freq=988Hz, sample=84, buffer_id=02:54
    db 11,0,11,1,73,120,9,10,75,2,73,2  ; n3173 t=152.480s dur=267ms, freq=587Hz, sample=73, buffer_id=02:49
    db 6,0,35,3,84,110,16,11,151,4,84,16  ; n3174 t=152.491s dur=803ms, freq=1175Hz, sample=84, buffer_id=10:54
    db 0,0,226,14,60,124,14,9,38,1,60,14  ; n3175 t=152.496s dur=3810ms, freq=294Hz, sample=60, buffer_id=0E:3C [TRUNCATE prev:ch9 @151424.9ms -> 152496.3ms]
    db 0,0,189,16,55,124,14,13,185,0,55,14  ; n3176 t=152.496s dur=4285ms, freq=185Hz, sample=55, buffer_id=0E:37 [TRUNCATE prev:ch13 @151424.9ms -> 152496.3ms]
    db 251,0,189,16,50,124,14,3,123,0,50,14  ; n3177 t=152.496s dur=4285ms, freq=123Hz, sample=50, buffer_id=0E:32 [TRUNCATE prev:ch3 @151424.9ms -> 152496.3ms]
    db 0,0,11,1,79,120,7,0,228,2,79,2  ; n3178 t=152.747s dur=267ms, freq=740Hz, sample=79, buffer_id=02:4F
    db 78,0,11,1,71,120,9,1,238,1,71,2  ; n3179 t=152.747s dur=267ms, freq=494Hz, sample=71, buffer_id=02:47
    db 5,0,101,1,63,115,13,2,74,1,63,2  ; n3180 t=152.826s dur=357ms, freq=330Hz, sample=63, buffer_id=02:3F
    db 162,0,101,1,65,110,4,7,74,1,65,4  ; n3181 t=152.831s dur=357ms, freq=330Hz, sample=65, buffer_id=04:41
    db 22,0,111,0,47,120,3,4,123,0,47,2  ; n3182 t=152.993s dur=111ms, freq=123Hz, sample=47, buffer_id=02:2F
    db 0,0,11,1,84,120,7,8,220,3,84,2  ; n3183 t=153.015s dur=267ms, freq=988Hz, sample=84, buffer_id=02:54
    db 167,0,11,1,73,120,9,6,75,2,73,2  ; n3184 t=153.015s dur=267ms, freq=587Hz, sample=73, buffer_id=02:49
    db 6,0,101,1,66,115,13,5,114,1,66,2  ; n3185 t=153.183s dur=357ms, freq=370Hz, sample=66, buffer_id=02:42
    db 95,0,101,1,65,110,4,10,114,1,65,4  ; n3186 t=153.188s dur=357ms, freq=370Hz, sample=65, buffer_id=04:41
    db 0,0,11,1,79,120,7,1,228,2,79,2  ; n3187 t=153.283s dur=267ms, freq=740Hz, sample=79, buffer_id=02:4F
    db 1,1,11,1,71,120,9,0,238,1,71,2  ; n3188 t=153.283s dur=267ms, freq=494Hz, sample=71, buffer_id=02:47
    db 6,0,47,4,66,115,13,2,114,1,66,2  ; n3189 t=153.540s dur=1071ms, freq=370Hz, sample=66, buffer_id=02:42
    db 6,0,47,4,65,110,4,4,114,1,65,4  ; n3190 t=153.545s dur=1071ms, freq=370Hz, sample=65, buffer_id=04:41
    db 0,0,11,1,86,120,7,6,151,4,86,2  ; n3191 t=153.551s dur=267ms, freq=1175Hz, sample=86, buffer_id=02:56
    db 145,0,11,1,79,120,9,7,228,2,79,2  ; n3192 t=153.551s dur=267ms, freq=740Hz, sample=79, buffer_id=02:4F
    db 123,0,133,0,77,110,16,8,228,2,77,16  ; n3193 t=153.696s dur=133ms, freq=740Hz, sample=77, buffer_id=10:4D
    db 0,0,11,1,84,120,7,0,220,3,84,2  ; n3194 t=153.819s dur=267ms, freq=988Hz, sample=84, buffer_id=02:54
    db 11,0,11,1,73,120,9,1,75,2,73,2  ; n3195 t=153.819s dur=267ms, freq=587Hz, sample=73, buffer_id=02:49
    db 134,0,133,0,84,110,16,5,220,3,84,16  ; n3196 t=153.830s dur=133ms, freq=988Hz, sample=84, buffer_id=10:54
    db 100,0,133,0,84,110,16,10,151,4,84,16  ; n3197 t=153.964s dur=133ms, freq=1175Hz, sample=84, buffer_id=10:54
    db 22,0,111,0,34,120,3,6,62,0,34,2  ; n3198 t=154.064s dur=111ms, freq=62Hz, sample=34, buffer_id=02:22
    db 0,0,11,1,86,120,7,7,151,4,86,2  ; n3199 t=154.087s dur=267ms, freq=1175Hz, sample=86, buffer_id=02:56
    db 11,0,11,1,79,120,9,8,228,2,79,2  ; n3200 t=154.087s dur=267ms, freq=740Hz, sample=79, buffer_id=02:4F
    db 1,1,11,1,89,110,16,11,200,5,89,16  ; n3201 t=154.098s dur=267ms, freq=1480Hz, sample=89, buffer_id=10:59
    db 0,0,11,1,84,120,7,1,220,3,84,2  ; n3202 t=154.355s dur=267ms, freq=988Hz, sample=84, buffer_id=02:54
    db 245,0,11,1,73,120,9,0,75,2,73,2  ; n3203 t=154.355s dur=267ms, freq=587Hz, sample=73, buffer_id=02:49
    db 11,0,111,0,34,120,3,5,62,0,34,2  ; n3204 t=154.600s dur=111ms, freq=62Hz, sample=34, buffer_id=02:22
    db 6,0,241,0,61,115,13,6,38,1,61,2  ; n3205 t=154.611s dur=241ms, freq=294Hz, sample=61, buffer_id=02:3D
    db 6,0,101,1,60,110,4,7,38,1,60,4  ; n3206 t=154.617s dur=357ms, freq=294Hz, sample=60, buffer_id=04:3C
    db 0,0,11,1,86,120,7,8,151,4,86,2  ; n3207 t=154.622s dur=267ms, freq=1175Hz, sample=86, buffer_id=02:56
    db 12,1,11,1,79,120,9,10,16,3,79,2  ; n3208 t=154.622s dur=267ms, freq=784Hz, sample=79, buffer_id=02:4F
    db 0,0,11,1,84,120,7,0,220,3,84,2  ; n3209 t=154.890s dur=267ms, freq=988Hz, sample=84, buffer_id=02:54
    db 78,0,11,1,73,120,9,1,75,2,73,2  ; n3210 t=154.890s dur=267ms, freq=587Hz, sample=73, buffer_id=02:49
    db 6,0,101,1,63,115,13,2,74,1,63,2  ; n3211 t=154.968s dur=357ms, freq=330Hz, sample=63, buffer_id=02:3F
    db 162,0,101,1,65,110,4,5,74,1,65,4  ; n3212 t=154.974s dur=357ms, freq=330Hz, sample=65, buffer_id=04:41
    db 22,0,111,0,47,120,3,4,123,0,47,2  ; n3213 t=155.136s dur=111ms, freq=123Hz, sample=47, buffer_id=02:2F
    db 0,0,11,1,86,120,7,6,151,4,86,2  ; n3214 t=155.158s dur=267ms, freq=1175Hz, sample=86, buffer_id=02:56
    db 168,0,11,1,79,120,9,8,228,2,79,2  ; n3215 t=155.158s dur=267ms, freq=740Hz, sample=79, buffer_id=02:4F
    db 5,0,101,1,66,115,13,7,114,1,66,2  ; n3216 t=155.326s dur=357ms, freq=370Hz, sample=66, buffer_id=02:42
    db 95,0,101,1,65,110,4,10,114,1,65,4  ; n3217 t=155.331s dur=357ms, freq=370Hz, sample=65, buffer_id=04:41
    db 0,0,11,1,84,120,7,1,220,3,84,2  ; n3218 t=155.426s dur=267ms, freq=988Hz, sample=84, buffer_id=02:54
    db 1,1,11,1,73,120,9,0,75,2,73,2  ; n3219 t=155.426s dur=267ms, freq=587Hz, sample=73, buffer_id=02:49
    db 6,0,47,4,66,115,13,2,114,1,66,2  ; n3220 t=155.683s dur=1071ms, freq=370Hz, sample=66, buffer_id=02:42
    db 6,0,47,4,65,110,4,4,114,1,65,4  ; n3221 t=155.688s dur=1071ms, freq=370Hz, sample=65, buffer_id=04:41
    db 0,0,11,1,86,120,7,5,151,4,86,2  ; n3222 t=155.694s dur=267ms, freq=1175Hz, sample=86, buffer_id=02:56
    db 145,0,11,1,79,120,9,6,228,2,79,2  ; n3223 t=155.694s dur=267ms, freq=740Hz, sample=79, buffer_id=02:4F
    db 123,0,133,0,77,110,16,8,228,2,77,16  ; n3224 t=155.839s dur=133ms, freq=740Hz, sample=77, buffer_id=10:4D
    db 0,0,11,1,84,120,7,0,220,3,84,2  ; n3225 t=155.962s dur=267ms, freq=988Hz, sample=84, buffer_id=02:54
    db 11,0,11,1,73,120,9,1,75,2,73,2  ; n3226 t=155.962s dur=267ms, freq=587Hz, sample=73, buffer_id=02:49
    db 134,0,133,0,84,110,16,7,220,3,84,16  ; n3227 t=155.973s dur=133ms, freq=988Hz, sample=84, buffer_id=10:54
    db 101,0,133,0,84,110,16,10,151,4,84,16  ; n3228 t=156.107s dur=133ms, freq=1175Hz, sample=84, buffer_id=10:54
    db 22,0,111,0,34,120,3,5,62,0,34,2  ; n3229 t=156.207s dur=111ms, freq=62Hz, sample=34, buffer_id=02:22
    db 0,0,11,1,86,120,7,6,151,4,86,2  ; n3230 t=156.230s dur=267ms, freq=1175Hz, sample=86, buffer_id=02:56
    db 11,0,11,1,79,120,9,8,228,2,79,2  ; n3231 t=156.230s dur=267ms, freq=740Hz, sample=79, buffer_id=02:4F
    db 0,0,11,1,89,110,16,12,200,5,89,16  ; n3232 t=156.241s dur=267ms, freq=1480Hz, sample=89, buffer_id=10:59 [TRUNCATE prev:ch12 @151955.0ms -> 156240.7ms]
    db 1,1,6,1,55,100,19,11,185,0,55,19  ; n3233 t=156.241s dur=262ms, freq=185Hz, sample=55, buffer_id=13:37
    db 0,0,11,1,84,120,7,1,220,3,84,2  ; n3234 t=156.497s dur=267ms, freq=988Hz, sample=84, buffer_id=02:54
    db 11,0,11,1,73,120,9,0,75,2,73,2  ; n3235 t=156.497s dur=267ms, freq=587Hz, sample=73, buffer_id=02:49
    db 234,0,6,1,55,100,19,7,196,0,55,19  ; n3236 t=156.509s dur=262ms, freq=196Hz, sample=55, buffer_id=13:37
    db 11,0,114,0,34,120,3,6,55,0,34,2  ; n3237 t=156.743s dur=114ms, freq=55Hz, sample=34, buffer_id=02:22
    db 6,0,112,1,63,115,13,5,74,1,63,2  ; n3238 t=156.754s dur=368ms, freq=330Hz, sample=63, buffer_id=02:3F
    db 6,0,112,1,65,110,4,8,74,1,65,4  ; n3239 t=156.760s dur=368ms, freq=330Hz, sample=65, buffer_id=04:41
    db 0,0,20,1,86,120,7,9,39,5,86,2  ; n3240 t=156.765s dur=276ms, freq=1319Hz, sample=86, buffer_id=02:56
    db 11,0,20,1,79,120,9,10,63,3,79,2  ; n3241 t=156.765s dur=276ms, freq=831Hz, sample=79, buffer_id=02:4F
    db 6,0,35,2,55,100,19,12,208,0,55,19  ; n3242 t=156.776s dur=547ms, freq=208Hz, sample=55, buffer_id=13:37
    db 0,0,85,4,65,124,14,11,74,1,65,14  ; n3243 t=156.782s dur=1109ms, freq=330Hz, sample=65, buffer_id=0E:41
    db 0,0,85,4,60,124,14,3,6,1,60,14  ; n3244 t=156.782s dur=1109ms, freq=262Hz, sample=60, buffer_id=0E:3C [TRUNCATE prev:ch3 @152496.3ms -> 156782.0ms]
    db 4,1,85,4,43,124,14,13,110,0,43,14  ; n3245 t=156.782s dur=1109ms, freq=110Hz, sample=43, buffer_id=0E:2B [TRUNCATE prev:ch13 @152496.3ms -> 156782.0ms]
    db 0,0,20,1,84,120,7,0,23,4,84,2  ; n3246 t=157.042s dur=276ms, freq=1047Hz, sample=84, buffer_id=02:54
    db 81,0,20,1,75,120,9,1,147,2,75,2  ; n3247 t=157.042s dur=276ms, freq=659Hz, sample=75, buffer_id=02:4B
    db 6,0,113,1,66,115,13,4,114,1,66,2  ; n3248 t=157.122s dur=369ms, freq=370Hz, sample=66, buffer_id=02:42
    db 167,0,113,1,65,110,4,2,114,1,65,4  ; n3249 t=157.128s dur=369ms, freq=370Hz, sample=65, buffer_id=04:41
    db 23,0,115,0,45,120,3,6,110,0,45,2  ; n3250 t=157.295s dur=115ms, freq=110Hz, sample=45, buffer_id=02:2D
    db 0,0,21,1,86,120,7,7,39,5,86,2  ; n3251 t=157.318s dur=277ms, freq=1319Hz, sample=86, buffer_id=02:56
    db 12,0,21,1,79,120,9,9,112,3,79,2  ; n3252 t=157.318s dur=277ms, freq=880Hz, sample=79, buffer_id=02:4F
    db 162,0,38,2,55,100,19,5,220,0,55,19  ; n3253 t=157.330s dur=550ms, freq=220Hz, sample=55, buffer_id=13:37
    db 6,0,114,1,67,115,13,8,136,1,67,2  ; n3254 t=157.492s dur=370ms, freq=392Hz, sample=67, buffer_id=02:43
    db 98,0,114,1,65,110,4,10,136,1,65,4  ; n3255 t=157.498s dur=370ms, freq=392Hz, sample=65, buffer_id=04:41
    db 0,0,21,1,84,120,7,1,23,4,84,2  ; n3256 t=157.596s dur=277ms, freq=1047Hz, sample=84, buffer_id=02:54
    db 10,1,21,1,75,120,9,0,147,2,75,2  ; n3257 t=157.596s dur=277ms, freq=659Hz, sample=75, buffer_id=02:4B
    db 6,0,133,6,67,115,13,2,136,1,67,2  ; n3258 t=157.862s dur=1669ms, freq=392Hz, sample=67, buffer_id=02:43
    db 6,0,133,6,65,110,4,4,136,1,65,4  ; n3259 t=157.868s dur=1669ms, freq=392Hz, sample=65, buffer_id=04:41
    db 0,0,25,1,86,120,7,6,39,5,86,2  ; n3260 t=157.874s dur=281ms, freq=1319Hz, sample=86, buffer_id=02:56
    db 12,0,25,1,79,120,9,7,112,3,79,2  ; n3261 t=157.874s dur=281ms, freq=880Hz, sample=79, buffer_id=02:4F
    db 6,0,45,2,60,100,19,9,247,0,60,19  ; n3262 t=157.886s dur=557ms, freq=247Hz, sample=60, buffer_id=13:3C
    db 0,0,28,9,65,124,14,12,136,1,65,14  ; n3263 t=157.891s dur=2332ms, freq=392Hz, sample=65, buffer_id=0E:41
    db 0,0,28,9,65,124,14,11,74,1,65,14  ; n3264 t=157.891s dur=2332ms, freq=330Hz, sample=65, buffer_id=0E:41 [TRUNCATE prev:ch11 @156782.0ms -> 157891.4ms]
    db 135,0,117,7,43,124,14,13,110,0,43,14  ; n3265 t=157.891s dur=1909ms, freq=110Hz, sample=43, buffer_id=0E:2B [TRUNCATE prev:ch13 @156782.0ms -> 157891.4ms]
    db 129,0,140,0,77,110,16,3,16,3,77,16  ; n3266 t=158.026s dur=140ms, freq=784Hz, sample=77, buffer_id=10:4D [TRUNCATE prev:ch3 @156782.0ms -> 158026.3ms]
    db 0,0,25,1,84,120,7,0,23,4,84,2  ; n3267 t=158.155s dur=281ms, freq=1047Hz, sample=84, buffer_id=02:54
    db 12,0,25,1,75,120,9,1,147,2,75,2  ; n3268 t=158.155s dur=281ms, freq=659Hz, sample=75, buffer_id=02:4B
    db 141,0,140,0,84,110,16,5,23,4,84,16  ; n3269 t=158.167s dur=140ms, freq=1047Hz, sample=84, buffer_id=10:54
    db 106,0,140,0,89,110,16,8,39,5,89,16  ; n3270 t=158.308s dur=140ms, freq=1319Hz, sample=89, buffer_id=10:59
    db 24,0,115,0,34,120,3,3,55,0,34,2  ; n3271 t=158.413s dur=115ms, freq=55Hz, sample=34, buffer_id=02:22
    db 0,0,19,1,86,120,7,7,39,5,86,2  ; n3272 t=158.437s dur=275ms, freq=1319Hz, sample=86, buffer_id=02:56
    db 12,0,19,1,79,120,9,6,112,3,79,2  ; n3273 t=158.437s dur=275ms, freq=880Hz, sample=79, buffer_id=02:4F
    db 0,0,19,1,89,110,16,10,32,6,89,16  ; n3274 t=158.449s dur=275ms, freq=1568Hz, sample=89, buffer_id=10:59
    db 8,1,33,2,60,100,19,9,6,1,60,19  ; n3275 t=158.449s dur=545ms, freq=262Hz, sample=60, buffer_id=13:3C [TRUNCATE prev:ch9 @157885.6ms -> 158448.6ms]
    db 0,0,19,1,84,120,7,1,23,4,84,2  ; n3276 t=158.713s dur=275ms, freq=1047Hz, sample=84, buffer_id=02:54
    db 253,0,19,1,75,120,9,0,147,2,75,2  ; n3277 t=158.713s dur=275ms, freq=659Hz, sample=75, buffer_id=02:4B
    db 23,0,115,0,45,120,3,3,110,0,45,2  ; n3278 t=158.965s dur=115ms, freq=110Hz, sample=45, buffer_id=02:2D
    db 0,0,21,1,91,120,7,5,32,6,91,2  ; n3279 t=158.988s dur=277ms, freq=1568Hz, sample=91, buffer_id=02:5B
    db 11,0,21,1,84,120,9,6,23,4,84,2  ; n3280 t=158.988s dur=277ms, freq=1047Hz, sample=84, buffer_id=02:54
    db 10,1,38,2,60,100,19,7,38,1,60,19  ; n3281 t=159.000s dur=550ms, freq=294Hz, sample=60, buffer_id=13:3C
    db 0,0,21,1,86,120,7,0,151,4,86,2  ; n3282 t=159.266s dur=277ms, freq=1175Hz, sample=86, buffer_id=02:56
    db 255,0,21,1,79,120,9,1,112,3,79,2  ; n3283 t=159.266s dur=277ms, freq=880Hz, sample=79, buffer_id=02:4F
    db 11,0,130,0,34,120,3,3,55,0,34,2  ; n3284 t=159.521s dur=130ms, freq=55Hz, sample=34, buffer_id=02:22
    db 6,0,145,2,67,115,13,5,136,1,67,2  ; n3285 t=159.532s dur=657ms, freq=392Hz, sample=67, buffer_id=02:43
    db 6,0,146,2,65,110,4,6,136,1,65,4  ; n3286 t=159.538s dur=658ms, freq=392Hz, sample=65, buffer_id=04:41
    db 0,0,72,1,91,120,7,8,32,6,91,2  ; n3287 t=159.544s dur=328ms, freq=1568Hz, sample=91, buffer_id=02:5B
    db 12,0,72,1,84,120,9,9,23,4,84,2  ; n3288 t=159.544s dur=328ms, freq=1047Hz, sample=84, buffer_id=02:54
    db 60,1,142,2,60,100,19,10,6,1,60,19  ; n3289 t=159.555s dur=654ms, freq=262Hz, sample=60, buffer_id=13:3C
    db 0,0,75,1,86,120,7,1,151,4,86,2  ; n3290 t=159.872s dur=331ms, freq=1175Hz, sample=86, buffer_id=02:56
    db 62,1,75,1,79,120,9,0,112,3,79,2  ; n3291 t=159.872s dur=331ms, freq=880Hz, sample=79, buffer_id=02:4F
    db 7,0,166,2,71,115,13,2,238,1,71,2  ; n3292 t=160.190s dur=678ms, freq=494Hz, sample=71, buffer_id=02:47
    db 7,0,166,2,70,110,4,3,238,1,70,4  ; n3293 t=160.196s dur=678ms, freq=494Hz, sample=70, buffer_id=04:46
    db 0,0,83,1,91,120,7,4,32,6,91,2  ; n3294 t=160.203s dur=339ms, freq=1568Hz, sample=91, buffer_id=02:5B
    db 14,0,83,1,84,120,9,7,23,4,84,2  ; n3295 t=160.203s dur=339ms, freq=1047Hz, sample=84, buffer_id=02:54
    db 7,0,254,3,67,100,19,8,136,1,67,19  ; n3296 t=160.217s dur=1022ms, freq=392Hz, sample=67, buffer_id=13:43
    db 0,0,100,5,60,124,14,9,6,1,60,14  ; n3297 t=160.224s dur=1380ms, freq=262Hz, sample=60, buffer_id=0E:3C
    db 0,0,100,5,55,124,14,13,196,0,55,14  ; n3298 t=160.224s dur=1380ms, freq=196Hz, sample=55, buffer_id=0E:37
    db 63,1,100,5,43,124,14,11,110,0,43,14  ; n3299 t=160.224s dur=1380ms, freq=110Hz, sample=43, buffer_id=0E:2B [TRUNCATE prev:ch11 @157891.4ms -> 160224.0ms]
    db 0,0,83,1,86,120,7,0,221,4,86,2  ; n3300 t=160.543s dur=339ms, freq=1245Hz, sample=86, buffer_id=02:56
    db 55,1,83,1,79,120,9,1,112,3,79,2  ; n3301 t=160.543s dur=339ms, freq=880Hz, sample=79, buffer_id=02:4F
    db 14,0,144,0,45,120,3,4,110,0,45,2  ; n3302 t=160.854s dur=144ms, freq=110Hz, sample=45, buffer_id=02:2D
    db 7,0,187,2,67,115,13,6,184,1,67,2  ; n3303 t=160.868s dur=699ms, freq=440Hz, sample=67, buffer_id=02:43
    db 7,0,187,2,70,110,4,5,184,1,70,4  ; n3304 t=160.875s dur=699ms, freq=440Hz, sample=70, buffer_id=04:46
    db 0,0,93,1,91,120,7,7,32,6,91,2  ; n3305 t=160.882s dur=349ms, freq=1568Hz, sample=91, buffer_id=02:5B
    db 94,1,93,1,84,120,9,10,23,4,84,2  ; n3306 t=160.882s dur=349ms, freq=1047Hz, sample=84, buffer_id=02:54
    db 0,0,94,1,86,120,7,1,221,4,86,2  ; n3307 t=161.232s dur=350ms, freq=1245Hz, sample=86, buffer_id=02:56
    db 15,0,94,1,79,120,9,0,112,3,79,2  ; n3308 t=161.232s dur=350ms, freq=880Hz, sample=79, buffer_id=02:4F
    db 50,1,87,1,60,100,19,2,55,1,60,19  ; n3309 t=161.247s dur=343ms, freq=311Hz, sample=60, buffer_id=13:3C
    db 15,0,139,0,50,120,3,3,147,0,50,2  ; n3310 t=161.553s dur=139ms, freq=147Hz, sample=50, buffer_id=02:32
    db 7,0,130,9,66,115,13,4,114,1,66,2  ; n3311 t=161.568s dur=2434ms, freq=370Hz, sample=66, buffer_id=02:42
    db 22,0,128,9,65,110,4,7,114,1,65,4  ; n3312 t=161.575s dur=2432ms, freq=370Hz, sample=65, buffer_id=04:41
    db 7,0,192,5,60,100,19,8,38,1,60,19  ; n3313 t=161.597s dur=1472ms, freq=294Hz, sample=60, buffer_id=13:3C
    db 0,0,67,7,60,124,14,10,247,0,60,14  ; n3314 t=161.604s dur=1859ms, freq=247Hz, sample=60, buffer_id=0E:3C
    db 0,0,67,7,55,124,14,12,196,0,55,14  ; n3315 t=161.604s dur=1859ms, freq=196Hz, sample=55, buffer_id=0E:37
    db 109,2,67,7,50,124,14,9,147,0,50,14  ; n3316 t=161.604s dur=1859ms, freq=147Hz, sample=50, buffer_id=0E:32 [TRUNCATE prev:ch9 @160224.0ms -> 161604.3ms]
    db 14,0,115,2,67,120,11,0,184,1,67,2  ; n3317 t=162.226s dur=627ms, freq=440Hz, sample=67, buffer_id=02:43
    db 0,0,115,2,79,120,7,1,228,2,79,2  ; n3318 t=162.239s dur=627ms, freq=740Hz, sample=79, buffer_id=02:4F
    db 102,2,115,2,73,120,9,2,75,2,73,2  ; n3319 t=162.239s dur=627ms, freq=587Hz, sample=73, buffer_id=02:49
    db 13,0,68,2,73,120,11,3,75,2,73,2  ; n3320 t=162.853s dur=580ms, freq=587Hz, sample=73, buffer_id=02:49
    db 0,0,67,2,84,120,7,5,220,3,84,2  ; n3321 t=162.866s dur=579ms, freq=988Hz, sample=84, buffer_id=02:54
    db 55,2,67,2,79,120,9,6,228,2,79,2  ; n3322 t=162.866s dur=579ms, freq=740Hz, sample=79, buffer_id=02:4F
    db 12,0,56,2,71,120,11,0,238,1,71,2  ; n3323 t=163.434s dur=568ms, freq=494Hz, sample=71, buffer_id=02:47
    db 0,0,56,2,79,120,7,2,112,3,79,2  ; n3324 t=163.446s dur=568ms, freq=880Hz, sample=79, buffer_id=02:4F
    db 44,2,56,2,73,120,9,1,75,2,73,2  ; n3325 t=163.446s dur=568ms, freq=587Hz, sample=73, buffer_id=02:49
    db 0,0,12,2,67,120,11,3,184,1,67,2  ; n3326 t=164.002s dur=524ms, freq=440Hz, sample=67, buffer_id=02:43
    db 12,0,241,0,56,115,13,5,220,0,56,2  ; n3327 t=164.002s dur=241ms, freq=220Hz, sample=56, buffer_id=02:38
    db 0,0,11,2,79,120,7,8,228,2,79,2  ; n3328 t=164.014s dur=523ms, freq=740Hz, sample=79, buffer_id=02:4F
    db 82,1,98,4,72,120,9,6,11,2,72,2  ; n3329 t=164.014s dur=1122ms, freq=523Hz, sample=72, buffer_id=02:48
    db 174,0,114,1,59,115,13,0,247,0,59,2  ; n3330 t=164.352s dur=370ms, freq=247Hz, sample=59, buffer_id=02:3B
    db 11,0,85,2,67,120,11,1,136,1,67,2  ; n3331 t=164.526s dur=597ms, freq=392Hz, sample=67, buffer_id=02:43
    db 186,0,87,2,75,120,7,2,147,2,75,2  ; n3332 t=164.537s dur=599ms, freq=659Hz, sample=75, buffer_id=02:4B
    db 145,1,145,1,60,115,13,4,6,1,60,2  ; n3333 t=164.723s dur=401ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 0,0,170,4,72,120,11,0,11,2,72,2  ; n3334 t=165.124s dur=1194ms, freq=523Hz, sample=72, buffer_id=02:48
    db 12,0,87,2,71,115,13,3,238,1,71,2  ; n3335 t=165.124s dur=599ms, freq=494Hz, sample=71, buffer_id=02:47
    db 0,0,129,3,79,120,7,5,16,3,79,2  ; n3336 t=165.137s dur=897ms, freq=784Hz, sample=79, buffer_id=02:4F
    db 75,2,170,4,75,120,9,7,110,2,75,2  ; n3337 t=165.137s dur=1194ms, freq=622Hz, sample=75, buffer_id=02:4B
    db 54,1,83,2,67,115,13,2,184,1,67,2  ; n3338 t=165.724s dur=595ms, freq=440Hz, sample=67, buffer_id=02:43
    db 29,1,41,1,79,120,7,1,112,3,79,2  ; n3339 t=166.034s dur=297ms, freq=880Hz, sample=79, buffer_id=02:4F
    db 0,0,243,4,71,120,11,4,238,1,71,2  ; n3340 t=166.319s dur=1267ms, freq=494Hz, sample=71, buffer_id=02:47
    db 12,0,230,9,66,115,13,3,114,1,66,2  ; n3341 t=166.319s dur=2534ms, freq=370Hz, sample=66, buffer_id=02:42
    db 0,0,189,1,79,120,7,6,228,2,79,2  ; n3342 t=166.331s dur=445ms, freq=740Hz, sample=79, buffer_id=02:4F
    db 190,1,243,4,73,120,9,5,75,2,73,2  ; n3343 t=166.331s dur=1267ms, freq=587Hz, sample=73, buffer_id=02:49
    db 169,1,168,1,79,120,7,0,16,3,79,2  ; n3344 t=166.777s dur=424ms, freq=784Hz, sample=79, buffer_id=02:4F
    db 128,1,140,1,79,120,7,2,112,3,79,2  ; n3345 t=167.202s dur=396ms, freq=880Hz, sample=79, buffer_id=02:4F
    db 12,0,241,0,61,120,11,0,38,1,61,2  ; n3346 t=167.586s dur=241ms, freq=294Hz, sample=61, buffer_id=02:3D
    db 0,0,244,4,79,120,7,7,112,3,79,2  ; n3347 t=167.598s dur=1268ms, freq=880Hz, sample=79, buffer_id=02:4F
    db 171,1,171,1,71,120,9,1,238,1,71,2  ; n3348 t=167.598s dur=427ms, freq=494Hz, sample=71, buffer_id=02:47
    db 168,1,167,1,72,120,9,2,11,2,72,2  ; n3349 t=168.026s dur=423ms, freq=523Hz, sample=72, buffer_id=02:48
    db 148,1,161,1,73,120,9,0,75,2,73,2  ; n3350 t=168.449s dur=417ms, freq=587Hz, sample=73, buffer_id=02:49
    db 0,0,193,4,67,120,11,1,136,1,67,2  ; n3351 t=168.854s dur=1217ms, freq=392Hz, sample=67, buffer_id=02:43
    db 13,0,241,0,56,115,13,2,220,0,56,2  ; n3352 t=168.854s dur=241ms, freq=220Hz, sample=56, buffer_id=02:38
    db 0,0,194,4,79,120,7,4,16,3,79,2  ; n3353 t=168.867s dur=1218ms, freq=784Hz, sample=79, buffer_id=02:4F
    db 120,1,194,4,75,120,9,5,110,2,75,2  ; n3354 t=168.867s dur=1218ms, freq=622Hz, sample=75, buffer_id=02:4B
    db 147,1,147,1,59,115,13,0,247,0,59,2  ; n3355 t=169.243s dur=403ms, freq=247Hz, sample=59, buffer_id=02:3B
    db 170,1,169,1,60,115,13,2,6,1,60,2  ; n3356 t=169.646s dur=425ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 0,0,195,5,79,120,11,0,16,3,79,2  ; n3357 t=170.072s dur=1475ms, freq=784Hz, sample=79, buffer_id=02:4F
    db 13,0,188,2,71,115,13,3,238,1,71,2  ; n3358 t=170.072s dur=700ms, freq=494Hz, sample=71, buffer_id=02:47
    db 0,0,198,5,91,120,7,6,32,6,91,2  ; n3359 t=170.085s dur=1478ms, freq=1568Hz, sample=91, buffer_id=02:5B
    db 175,2,189,2,86,120,9,7,151,4,86,2  ; n3360 t=170.085s dur=701ms, freq=1175Hz, sample=86, buffer_id=02:56
    db 15,0,7,3,67,115,13,2,184,1,67,2  ; n3361 t=170.772s dur=775ms, freq=440Hz, sample=67, buffer_id=02:43
    db 232,2,9,3,86,120,9,1,221,4,86,2  ; n3362 t=170.787s dur=777ms, freq=1245Hz, sample=86, buffer_id=02:56
    db 16,0,21,5,50,120,2,3,147,0,50,2  ; n3363 t=171.531s dur=1301ms, freq=147Hz, sample=50, buffer_id=02:32
    db 0,0,18,5,79,120,11,5,228,2,79,2  ; n3364 t=171.548s dur=1298ms, freq=740Hz, sample=79, buffer_id=02:4F
    db 16,0,190,1,66,115,13,4,114,1,66,2  ; n3365 t=171.548s dur=446ms, freq=370Hz, sample=66, buffer_id=02:42
    db 0,0,15,5,86,120,7,8,151,4,86,2  ; n3366 t=171.564s dur=1295ms, freq=1175Hz, sample=86, buffer_id=02:56
    db 174,1,15,5,84,120,9,7,220,3,84,2  ; n3367 t=171.564s dur=1295ms, freq=988Hz, sample=84, buffer_id=02:54
    db 176,1,175,1,67,115,13,0,136,1,67,2  ; n3368 t=171.994s dur=431ms, freq=392Hz, sample=67, buffer_id=02:43
    db 151,1,241,0,61,115,13,1,38,1,61,2  ; n3369 t=172.426s dur=241ms, freq=294Hz, sample=61, buffer_id=02:3D
    db 13,0,64,5,48,120,2,0,131,0,48,2  ; n3370 t=172.833s dur=1344ms, freq=131Hz, sample=48, buffer_id=02:30
    db 0,0,66,5,79,120,11,2,16,3,79,2  ; n3371 t=172.846s dur=1346ms, freq=784Hz, sample=79, buffer_id=02:4F
    db 13,0,137,2,65,115,13,4,93,1,65,2  ; n3372 t=172.846s dur=649ms, freq=349Hz, sample=65, buffer_id=02:41
    db 0,0,67,5,86,120,7,6,221,4,86,2  ; n3373 t=172.859s dur=1347ms, freq=1245Hz, sample=86, buffer_id=02:56
    db 124,2,67,5,84,120,9,9,23,4,84,2  ; n3374 t=172.859s dur=1347ms, freq=1047Hz, sample=84, buffer_id=02:54
    db 170,2,184,2,63,115,13,1,55,1,63,2  ; n3375 t=173.496s dur=696ms, freq=311Hz, sample=63, buffer_id=02:3F
    db 15,0,77,5,45,120,2,3,110,0,45,2  ; n3376 t=174.178s dur=1357ms, freq=110Hz, sample=45, buffer_id=02:2D
    db 0,0,244,10,72,120,11,4,11,2,72,2  ; n3377 t=174.192s dur=2804ms, freq=523Hz, sample=72, buffer_id=02:48
    db 15,0,15,1,56,115,13,5,196,0,56,2  ; n3378 t=174.192s dur=271ms, freq=196Hz, sample=56, buffer_id=02:38
    db 0,0,75,5,84,120,7,8,23,4,84,2  ; n3379 t=174.207s dur=1355ms, freq=1047Hz, sample=84, buffer_id=02:54
    db 0,0,75,5,79,120,9,7,16,3,79,2  ; n3380 t=174.207s dur=1355ms, freq=784Hz, sample=79, buffer_id=02:4F
    db 194,1,103,8,75,120,9,10,110,2,75,2  ; n3381 t=174.207s dur=2151ms, freq=622Hz, sample=75, buffer_id=02:4B
    db 197,1,197,1,59,115,13,0,247,0,59,2  ; n3382 t=174.657s dur=453ms, freq=247Hz, sample=59, buffer_id=02:3B
    db 169,1,182,1,60,115,13,1,6,1,60,2  ; n3383 t=175.110s dur=438ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 14,0,165,5,43,120,2,0,104,0,43,2  ; n3384 t=175.535s dur=1445ms, freq=104Hz, sample=43, buffer_id=02:2B
    db 14,0,185,2,67,115,13,2,159,1,67,2  ; n3385 t=175.549s dur=697ms, freq=415Hz, sample=67, buffer_id=02:43
    db 0,0,169,5,86,120,7,5,221,4,86,2  ; n3386 t=175.563s dur=1449ms, freq=1245Hz, sample=86, buffer_id=02:56
    db 171,2,169,5,84,120,9,6,23,4,84,2  ; n3387 t=175.563s dur=1449ms, freq=1047Hz, sample=84, buffer_id=02:54
    db 223,2,238,2,67,115,13,1,136,1,67,2  ; n3388 t=176.246s dur=750ms, freq=392Hz, sample=67, buffer_id=02:43
    db 16,0,8,17,36,120,2,2,73,0,36,2  ; n3389 t=176.981s dur=4360ms, freq=73Hz, sample=36, buffer_id=02:24
    db 0,0,42,11,72,120,11,3,11,2,72,2  ; n3390 t=176.996s dur=2858ms, freq=523Hz, sample=72, buffer_id=02:48
    db 16,0,42,11,66,115,13,7,114,1,66,2  ; n3391 t=176.996s dur=2858ms, freq=370Hz, sample=66, buffer_id=02:42
    db 0,0,225,5,86,120,7,8,221,4,86,2  ; n3392 t=177.012s dur=1505ms, freq=1245Hz, sample=86, buffer_id=02:56
    db 0,0,40,11,79,120,9,9,112,3,79,2  ; n3393 t=177.012s dur=2856ms, freq=880Hz, sample=79, buffer_id=02:4F
    db 226,5,103,8,75,120,9,11,110,2,75,2  ; n3394 t=177.012s dur=2151ms, freq=622Hz, sample=75, buffer_id=02:4B
    db 56,5,70,5,91,120,7,0,125,6,91,2  ; n3395 t=178.518s dur=1350ms, freq=1661Hz, sample=91, buffer_id=02:5B
    db 14,0,238,4,73,120,11,1,75,2,73,2  ; n3396 t=179.855s dur=1262ms, freq=587Hz, sample=73, buffer_id=02:49
    db 0,0,237,4,86,120,7,4,151,4,86,2  ; n3397 t=179.869s dur=1261ms, freq=1175Hz, sample=86, buffer_id=02:56
    db 101,2,76,10,79,120,9,5,16,3,79,2  ; n3398 t=179.869s dur=2636ms, freq=784Hz, sample=79, buffer_id=02:4F
    db 123,2,123,2,60,115,13,0,6,1,60,2  ; n3399 t=180.482s dur=635ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 0,0,93,5,75,120,11,3,110,2,75,2  ; n3400 t=181.117s dur=1373ms, freq=622Hz, sample=75, buffer_id=02:4B
    db 13,0,15,1,56,115,13,6,196,0,56,2  ; n3401 t=181.117s dur=271ms, freq=196Hz, sample=56, buffer_id=02:38
    db 138,2,95,5,84,120,7,7,23,4,84,2  ; n3402 t=181.130s dur=1375ms, freq=1047Hz, sample=84, buffer_id=02:54
    db 198,2,197,2,66,115,13,0,114,1,66,2  ; n3403 t=181.781s dur=709ms, freq=370Hz, sample=66, buffer_id=02:42
    db 0,0,238,7,75,120,11,1,147,2,75,2  ; n3404 t=182.490s dur=2030ms, freq=659Hz, sample=75, buffer_id=02:4B
    db 15,0,19,10,67,115,13,2,136,1,67,2  ; n3405 t=182.490s dur=2579ms, freq=392Hz, sample=67, buffer_id=02:43
    db 0,0,17,10,84,120,7,4,220,3,84,2  ; n3406 t=182.505s dur=2577ms, freq=988Hz, sample=84, buffer_id=02:54
    db 27,5,17,10,79,120,9,6,16,3,79,2  ; n3407 t=182.505s dur=2577ms, freq=784Hz, sample=79, buffer_id=02:4F
    db 21,0,219,4,41,120,2,0,82,0,41,2  ; n3408 t=183.813s dur=1243ms, freq=82Hz, sample=41, buffer_id=02:29
    db 0,0,218,4,43,110,4,3,82,0,43,4  ; n3409 t=183.834s dur=1242ms, freq=82Hz, sample=43, buffer_id=04:2B
    db 0,0,218,4,50,110,4,5,123,0,50,4  ; n3410 t=183.834s dur=1242ms, freq=123Hz, sample=50, buffer_id=04:32
    db 21,0,218,4,55,110,4,7,196,0,55,4  ; n3411 t=183.834s dur=1242ms, freq=196Hz, sample=55, buffer_id=04:37
    db 7,0,50,2,55,100,19,8,220,0,55,19  ; n3412 t=183.855s dur=562ms, freq=220Hz, sample=55, buffer_id=13:37
    db 201,0,200,0,41,100,22,9,82,0,41,22  ; n3413 t=183.863s dur=200ms, freq=82Hz, sample=41, buffer_id=16:29
    db 201,0,200,0,46,100,22,10,123,0,46,22  ; n3414 t=184.063s dur=200ms, freq=123Hz, sample=46, buffer_id=16:2E
    db 194,0,200,0,51,100,22,9,165,0,51,22  ; n3415 t=184.264s dur=200ms, freq=165Hz, sample=51, buffer_id=16:33
    db 6,0,119,2,55,100,19,11,196,0,55,19  ; n3416 t=184.458s dur=631ms, freq=196Hz, sample=55, buffer_id=13:37
    db 213,0,212,0,58,100,22,10,196,0,58,22  ; n3417 t=184.464s dur=212ms, freq=196Hz, sample=58, buffer_id=16:3A
    db 213,0,212,0,58,100,22,8,247,0,58,22  ; n3418 t=184.677s dur=212ms, freq=247Hz, sample=58, buffer_id=16:3A
    db 166,0,178,0,58,100,22,1,74,1,58,22  ; n3419 t=184.890s dur=178ms, freq=330Hz, sample=58, buffer_id=16:3A
    db 13,0,121,12,45,120,2,9,110,0,45,2  ; n3420 t=185.056s dur=3193ms, freq=110Hz, sample=45, buffer_id=02:2D
    db 7,0,103,8,75,120,11,10,110,2,75,2  ; n3421 t=185.070s dur=2151ms, freq=622Hz, sample=75, buffer_id=02:4B
    db 0,0,130,12,60,110,4,12,6,1,60,4  ; n3422 t=185.076s dur=3202ms, freq=262Hz, sample=60, buffer_id=04:3C
    db 0,0,36,11,50,110,4,13,156,0,50,4  ; n3423 t=185.076s dur=2852ms, freq=156Hz, sample=50, buffer_id=04:32
    db 7,0,237,9,43,110,4,3,110,0,43,4  ; n3424 t=185.076s dur=2541ms, freq=110Hz, sample=43, buffer_id=04:2B [TRUNCATE prev:ch3 @183834.0ms -> 185076.4ms]
    db 0,0,133,12,84,120,7,4,23,4,84,2  ; n3425 t=185.083s dur=3205ms, freq=1047Hz, sample=84, buffer_id=02:54 [TRUNCATE prev:ch4 @182505.3ms -> 185083.0ms]
    db 13,0,133,12,79,120,9,6,16,3,79,2  ; n3426 t=185.083s dur=3205ms, freq=784Hz, sample=79, buffer_id=02:4F [TRUNCATE prev:ch6 @182505.3ms -> 185083.0ms]
    db 7,0,129,12,51,100,19,8,156,0,51,19  ; n3427 t=185.096s dur=3201ms, freq=156Hz, sample=51, buffer_id=13:33
    db 240,0,240,0,46,100,22,2,110,0,46,22  ; n3428 t=185.103s dur=240ms, freq=110Hz, sample=46, buffer_id=16:2E [TRUNCATE prev:ch2 @182490.4ms -> 185103.0ms]
    db 240,0,240,0,51,100,22,0,156,0,51,22  ; n3429 t=185.343s dur=240ms, freq=156Hz, sample=51, buffer_id=16:33
    db 203,0,225,0,58,100,22,2,6,1,58,22  ; n3430 t=185.584s dur=225ms, freq=262Hz, sample=58, buffer_id=16:3A
    db 38,0,35,3,60,115,13,0,6,1,60,2  ; n3431 t=185.786s dur=803ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 254,2,13,1,70,100,22,1,136,1,70,22  ; n3432 t=185.824s dur=269ms, freq=392Hz, sample=70, buffer_id=16:46
    db 6,3,15,1,56,115,13,1,196,0,56,2  ; n3433 t=186.590s dur=271ms, freq=196Hz, sample=56, buffer_id=02:38
    db 137,3,137,3,66,115,13,0,114,1,66,2  ; n3434 t=187.364s dur=905ms, freq=370Hz, sample=66, buffer_id=02:42
    db 168,2,15,15,67,115,13,1,136,1,67,2  ; n3435 t=188.269s dur=3855ms, freq=392Hz, sample=67, buffer_id=02:43
    db 21,0,241,4,43,120,2,0,98,0,43,2  ; n3436 t=188.949s dur=1265ms, freq=98Hz, sample=43, buffer_id=02:2B
    db 0,0,239,4,60,110,4,2,247,0,60,4  ; n3437 t=188.970s dur=1263ms, freq=247Hz, sample=60, buffer_id=04:3C
    db 0,0,239,4,43,110,4,4,98,0,43,4  ; n3438 t=188.970s dur=1263ms, freq=98Hz, sample=43, buffer_id=04:2B
    db 152,2,239,4,50,110,4,3,147,0,50,4  ; n3439 t=188.970s dur=1263ms, freq=147Hz, sample=50, buffer_id=04:32
    db 7,0,195,0,65,110,16,5,184,1,65,16  ; n3440 t=189.634s dur=195ms, freq=440Hz, sample=65, buffer_id=10:41
    db 47,1,100,0,79,100,20,6,112,3,79,20  ; n3441 t=189.641s dur=100ms, freq=880Hz, sample=79, buffer_id=14:4F
    db 7,0,53,1,73,110,16,6,238,1,73,16  ; n3442 t=189.944s dur=309ms, freq=494Hz, sample=73, buffer_id=10:49
    db 8,1,100,0,84,100,20,7,220,3,84,20  ; n3443 t=189.951s dur=100ms, freq=988Hz, sample=84, buffer_id=14:54
    db 19,0,136,2,43,120,2,5,98,0,43,2  ; n3444 t=190.215s dur=648ms, freq=98Hz, sample=43, buffer_id=02:2B
    db 0,0,137,2,60,110,4,8,247,0,60,4  ; n3445 t=190.234s dur=649ms, freq=247Hz, sample=60, buffer_id=04:3C
    db 0,0,137,2,50,110,4,9,147,0,50,4  ; n3446 t=190.234s dur=649ms, freq=147Hz, sample=50, buffer_id=04:32
    db 19,0,137,2,43,110,4,10,98,0,43,4  ; n3447 t=190.234s dur=649ms, freq=98Hz, sample=43, buffer_id=04:2B
    db 6,0,68,1,73,110,16,7,75,2,73,16  ; n3448 t=190.254s dur=324ms, freq=587Hz, sample=73, buffer_id=10:49
    db 63,1,100,0,84,100,20,11,151,4,84,20  ; n3449 t=190.260s dur=100ms, freq=1175Hz, sample=84, buffer_id=14:54
    db 7,0,69,1,84,110,16,0,112,3,84,16  ; n3450 t=190.578s dur=325ms, freq=880Hz, sample=84, buffer_id=10:54
    db 22,1,100,0,91,100,20,2,224,6,91,20  ; n3451 t=190.585s dur=100ms, freq=1760Hz, sample=91, buffer_id=14:5B
    db 20,0,224,4,43,120,2,3,98,0,43,2  ; n3452 t=190.863s dur=1248ms, freq=98Hz, sample=43, buffer_id=02:2B
    db 0,0,223,4,43,110,4,6,98,0,43,4  ; n3453 t=190.883s dur=1247ms, freq=98Hz, sample=43, buffer_id=04:2B
    db 0,0,223,4,50,110,4,4,147,0,50,4  ; n3454 t=190.883s dur=1247ms, freq=147Hz, sample=50, buffer_id=04:32
    db 20,0,223,4,60,110,4,7,247,0,60,4  ; n3455 t=190.883s dur=1247ms, freq=247Hz, sample=60, buffer_id=04:3C
    db 7,0,57,1,84,110,16,2,112,3,84,16  ; n3456 t=190.904s dur=313ms, freq=880Hz, sample=84, buffer_id=10:54
    db 51,1,100,0,91,100,20,11,224,6,91,20  ; n3457 t=190.911s dur=100ms, freq=1760Hz, sample=91, buffer_id=14:5B
    db 6,0,57,1,84,110,16,5,220,3,84,16  ; n3458 t=191.218s dur=313ms, freq=988Hz, sample=84, buffer_id=10:54
    db 51,1,100,0,91,100,20,0,184,7,91,20  ; n3459 t=191.224s dur=100ms, freq=1976Hz, sample=91, buffer_id=14:5B
    db 7,0,107,2,84,110,16,0,220,3,84,16  ; n3460 t=191.531s dur=619ms, freq=988Hz, sample=84, buffer_id=10:54
    db 75,2,100,0,91,100,20,2,184,7,91,20  ; n3461 t=191.538s dur=100ms, freq=1976Hz, sample=91, buffer_id=14:5B
    db 0,0,154,6,53,120,11,2,175,0,53,2  ; n3462 t=192.125s dur=1690ms, freq=175Hz, sample=53, buffer_id=02:35
    db 7,0,154,6,53,115,13,5,175,0,53,2  ; n3463 t=192.125s dur=1690ms, freq=175Hz, sample=53, buffer_id=02:35
    db 6,0,156,6,65,110,4,8,93,1,65,4  ; n3464 t=192.131s dur=1692ms, freq=349Hz, sample=65, buffer_id=04:41
    db 0,0,159,6,75,120,7,9,186,2,75,2  ; n3465 t=192.137s dur=1695ms, freq=698Hz, sample=75, buffer_id=02:4B
    db 85,2,159,6,65,120,9,10,93,1,65,2  ; n3466 t=192.137s dur=1695ms, freq=349Hz, sample=65, buffer_id=02:41
    db 36,0,100,0,41,100,22,0,87,0,41,22  ; n3467 t=192.735s dur=100ms, freq=87Hz, sample=41, buffer_id=16:29
    db 45,0,100,0,41,100,22,1,98,0,41,22  ; n3468 t=192.771s dur=100ms, freq=98Hz, sample=41, buffer_id=16:29
    db 45,0,100,0,46,100,22,3,110,0,46,22  ; n3469 t=192.816s dur=100ms, freq=110Hz, sample=46, buffer_id=16:2E
    db 45,0,100,0,46,100,22,4,117,0,46,22  ; n3470 t=192.861s dur=100ms, freq=117Hz, sample=46, buffer_id=16:2E
    db 45,0,100,0,46,100,22,6,131,0,46,22  ; n3471 t=192.906s dur=100ms, freq=131Hz, sample=46, buffer_id=16:2E
    db 45,0,100,0,51,100,22,7,147,0,51,22  ; n3472 t=192.951s dur=100ms, freq=147Hz, sample=51, buffer_id=16:33
    db 44,0,100,0,51,100,22,11,156,0,51,22  ; n3473 t=192.997s dur=100ms, freq=156Hz, sample=51, buffer_id=16:33
    db 43,0,100,0,51,100,22,0,175,0,51,22  ; n3474 t=193.041s dur=100ms, freq=175Hz, sample=51, buffer_id=16:33
    db 43,0,100,0,58,100,22,1,196,0,58,22  ; n3475 t=193.084s dur=100ms, freq=196Hz, sample=58, buffer_id=16:3A
    db 44,0,100,0,58,100,22,3,220,0,58,22  ; n3476 t=193.128s dur=100ms, freq=220Hz, sample=58, buffer_id=16:3A
    db 43,0,100,0,58,100,22,4,233,0,58,22  ; n3477 t=193.172s dur=100ms, freq=233Hz, sample=58, buffer_id=16:3A
    db 35,0,100,0,58,100,22,6,6,1,58,22  ; n3478 t=193.215s dur=100ms, freq=262Hz, sample=58, buffer_id=16:3A
    db 52,0,100,0,58,100,22,12,38,1,58,22  ; n3479 t=193.250s dur=100ms, freq=294Hz, sample=58, buffer_id=16:3A
    db 35,0,100,0,58,100,22,7,55,1,58,22  ; n3480 t=193.302s dur=100ms, freq=311Hz, sample=58, buffer_id=16:3A
    db 43,0,100,0,70,100,22,11,93,1,70,22  ; n3481 t=193.337s dur=100ms, freq=349Hz, sample=70, buffer_id=16:46
    db 43,0,100,0,70,100,22,0,136,1,70,22  ; n3482 t=193.380s dur=100ms, freq=392Hz, sample=70, buffer_id=16:46
    db 43,0,100,0,70,100,22,1,184,1,70,22  ; n3483 t=193.424s dur=100ms, freq=440Hz, sample=70, buffer_id=16:46
    db 44,0,100,0,70,100,22,3,210,1,70,22  ; n3484 t=193.467s dur=100ms, freq=466Hz, sample=70, buffer_id=16:46
    db 43,0,100,0,70,100,22,4,11,2,70,22  ; n3485 t=193.511s dur=100ms, freq=523Hz, sample=70, buffer_id=16:46
    db 43,0,100,0,75,100,22,6,75,2,75,22  ; n3486 t=193.554s dur=100ms, freq=587Hz, sample=75, buffer_id=16:4B
    db 43,0,100,0,75,100,22,12,110,2,75,22  ; n3487 t=193.598s dur=100ms, freq=622Hz, sample=75, buffer_id=16:4B
    db 43,0,100,0,75,100,22,7,186,2,75,22  ; n3488 t=193.641s dur=100ms, freq=698Hz, sample=75, buffer_id=16:4B
    db 44,0,100,0,79,100,22,0,16,3,79,22  ; n3489 t=193.685s dur=100ms, freq=784Hz, sample=79, buffer_id=16:4F
    db 43,0,100,0,79,100,22,1,112,3,79,22  ; n3490 t=193.728s dur=100ms, freq=880Hz, sample=79, buffer_id=16:4F
    db 26,0,100,0,84,100,22,3,164,3,84,22  ; n3491 t=193.772s dur=100ms, freq=932Hz, sample=84, buffer_id=16:54
    db 9,0,132,0,34,120,3,11,58,0,34,2  ; n3492 t=193.798s dur=132ms, freq=58Hz, sample=34, buffer_id=02:22
    db 9,0,100,0,84,100,22,13,23,4,84,22  ; n3493 t=193.806s dur=100ms, freq=1047Hz, sample=84, buffer_id=16:54
    db 0,0,241,0,61,120,11,4,38,1,61,2  ; n3494 t=193.815s dur=241ms, freq=294Hz, sample=61, buffer_id=02:3D
    db 9,0,154,6,53,115,13,2,175,0,53,2  ; n3495 t=193.815s dur=1690ms, freq=175Hz, sample=53, buffer_id=02:35 [TRUNCATE prev:ch2 @192124.6ms -> 193815.1ms]
    db 9,0,82,8,65,110,4,8,93,1,65,4  ; n3496 t=193.824s dur=2130ms, freq=349Hz, sample=65, buffer_id=04:41 [TRUNCATE prev:ch8 @192131.1ms -> 193823.8ms]
    db 0,0,79,8,86,120,7,5,151,4,86,2  ; n3497 t=193.833s dur=2127ms, freq=1175Hz, sample=86, buffer_id=02:56 [TRUNCATE prev:ch5 @192124.6ms -> 193832.5ms]
    db 26,0,79,8,73,120,9,9,75,2,73,2  ; n3498 t=193.833s dur=2127ms, freq=587Hz, sample=73, buffer_id=02:49 [TRUNCATE prev:ch9 @192137.5ms -> 193832.5ms]
    db 0,0,69,8,60,124,14,6,233,0,60,14  ; n3499 t=193.859s dur=2117ms, freq=233Hz, sample=60, buffer_id=0E:3C
    db 0,0,69,8,55,124,14,10,175,0,55,14  ; n3500 t=193.859s dur=2117ms, freq=175Hz, sample=55, buffer_id=0E:37 [TRUNCATE prev:ch10 @192137.5ms -> 193858.6ms]
    db 0,0,69,8,60,124,14,12,38,1,60,14  ; n3501 t=193.859s dur=2117ms, freq=294Hz, sample=60, buffer_id=0E:3C [TRUNCATE prev:ch12 @193597.7ms -> 193858.6ms]
    db 235,1,100,0,84,100,22,7,151,4,84,22  ; n3502 t=193.859s dur=100ms, freq=1175Hz, sample=84, buffer_id=16:54 [TRUNCATE prev:ch7 @193641.2ms -> 193858.6ms]
    db 50,2,110,0,41,120,3,0,87,0,41,2  ; n3503 t=194.350s dur=110ms, freq=87Hz, sample=41, buffer_id=02:29
    db 177,0,176,0,65,110,16,0,93,1,65,16  ; n3504 t=194.912s dur=176ms, freq=349Hz, sample=65, buffer_id=10:41
    db 176,0,176,0,65,110,16,1,184,1,65,16  ; n3505 t=195.089s dur=176ms, freq=440Hz, sample=65, buffer_id=10:41
    db 143,0,176,0,73,110,16,3,210,1,73,16  ; n3506 t=195.265s dur=176ms, freq=466Hz, sample=73, buffer_id=10:49
    db 33,0,110,0,41,120,3,0,87,0,41,2  ; n3507 t=195.408s dur=110ms, freq=87Hz, sample=41, buffer_id=02:29
    db 177,0,176,0,73,110,16,4,75,2,73,16  ; n3508 t=195.441s dur=176ms, freq=587Hz, sample=73, buffer_id=10:49
    db 177,0,176,0,77,110,16,1,186,2,77,16  ; n3509 t=195.618s dur=176ms, freq=698Hz, sample=77, buffer_id=10:4D
    db 143,0,176,0,84,110,16,0,112,3,84,16  ; n3510 t=195.794s dur=176ms, freq=880Hz, sample=84, buffer_id=10:54
    db 11,0,107,0,34,120,3,2,58,0,34,2  ; n3511 t=195.938s dur=107ms, freq=58Hz, sample=34, buffer_id=02:22
    db 0,0,84,1,60,120,11,3,6,1,60,2  ; n3512 t=195.949s dur=340ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 5,0,59,6,53,115,13,4,185,0,53,2  ; n3513 t=195.949s dur=1595ms, freq=185Hz, sample=53, buffer_id=02:35
    db 6,0,252,3,65,110,4,7,114,1,65,4  ; n3514 t=195.954s dur=1020ms, freq=370Hz, sample=65, buffer_id=04:41
    db 0,0,84,1,84,120,7,11,23,4,84,2  ; n3515 t=195.960s dur=340ms, freq=1047Hz, sample=84, buffer_id=02:54
    db 11,0,84,1,72,120,9,13,11,2,72,2  ; n3516 t=195.960s dur=340ms, freq=523Hz, sample=72, buffer_id=02:48
    db 5,0,84,1,84,110,16,0,164,3,84,16  ; n3517 t=195.971s dur=340ms, freq=932Hz, sample=84, buffer_id=10:54 [TRUNCATE prev:ch0 @195794.5ms -> 195971.0ms]
    db 0,0,246,7,60,124,14,6,6,1,60,14  ; n3518 t=195.976s dur=2038ms, freq=262Hz, sample=60, buffer_id=0E:3C [TRUNCATE prev:ch6 @193858.6ms -> 195976.5ms]
    db 0,0,246,7,55,124,14,10,185,0,55,14  ; n3519 t=195.976s dur=2038ms, freq=185Hz, sample=55, buffer_id=0E:37 [TRUNCATE prev:ch10 @193858.6ms -> 195976.5ms]
    db 57,1,246,7,65,124,14,8,55,1,65,14  ; n3520 t=195.976s dur=2038ms, freq=311Hz, sample=65, buffer_id=0E:41 [TRUNCATE prev:ch8 @193823.8ms -> 195976.5ms]
    db 11,0,241,0,61,120,11,1,38,1,61,2  ; n3521 t=196.290s dur=241ms, freq=294Hz, sample=61, buffer_id=02:3D
    db 0,0,83,1,86,120,7,2,151,4,86,2  ; n3522 t=196.300s dur=339ms, freq=1175Hz, sample=86, buffer_id=02:56
    db 149,0,83,1,73,120,9,5,75,2,73,2  ; n3523 t=196.300s dur=339ms, freq=587Hz, sample=73, buffer_id=02:49
    db 181,0,106,0,45,120,3,9,117,0,45,2  ; n3524 t=196.449s dur=106ms, freq=117Hz, sample=45, buffer_id=02:2D
    db 11,0,83,1,63,120,11,0,55,1,63,2  ; n3525 t=196.630s dur=339ms, freq=311Hz, sample=63, buffer_id=02:3F
    db 0,0,83,1,86,120,7,3,221,4,86,2  ; n3526 t=196.640s dur=339ms, freq=1245Hz, sample=86, buffer_id=02:56
    db 73,1,83,1,75,120,9,11,110,2,75,2  ; n3527 t=196.640s dur=339ms, freq=622Hz, sample=75, buffer_id=02:4B
    db 11,0,253,1,53,120,11,1,185,0,53,2  ; n3528 t=196.969s dur=509ms, freq=185Hz, sample=53, buffer_id=02:35
    db 0,0,253,1,79,120,7,2,228,2,79,2  ; n3529 t=196.980s dur=509ms, freq=740Hz, sample=79, buffer_id=02:4F
    db 233,1,253,1,66,120,9,5,114,1,66,2  ; n3530 t=196.980s dur=509ms, freq=370Hz, sample=66, buffer_id=02:42
    db 11,0,106,0,34,120,3,0,58,0,34,2  ; n3531 t=197.469s dur=106ms, freq=58Hz, sample=34, buffer_id=02:22
    db 11,0,253,1,60,120,11,3,6,1,60,2  ; n3532 t=197.479s dur=509ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 0,0,253,1,84,120,7,7,23,4,84,2  ; n3533 t=197.490s dur=509ms, freq=1047Hz, sample=84, buffer_id=02:54
    db 232,1,253,1,72,120,9,9,11,2,72,2  ; n3534 t=197.490s dur=509ms, freq=523Hz, sample=72, buffer_id=02:48
    db 11,0,108,0,34,120,3,1,58,0,34,2  ; n3535 t=197.978s dur=108ms, freq=58Hz, sample=34, buffer_id=02:22
    db 0,0,241,0,61,120,11,0,38,1,61,2  ; n3536 t=197.989s dur=241ms, freq=294Hz, sample=61, buffer_id=02:3D
    db 11,0,15,1,56,115,13,2,196,0,56,2  ; n3537 t=197.989s dur=271ms, freq=196Hz, sample=56, buffer_id=02:38
    db 0,0,58,8,86,120,7,4,151,4,86,2  ; n3538 t=198.000s dur=2106ms, freq=1175Hz, sample=86, buffer_id=02:56
    db 16,0,58,8,73,120,9,5,75,2,73,2  ; n3539 t=198.000s dur=2106ms, freq=587Hz, sample=73, buffer_id=02:49
    db 0,0,58,8,60,124,14,11,233,0,60,14  ; n3540 t=198.015s dur=2106ms, freq=233Hz, sample=60, buffer_id=0E:3C
    db 0,0,58,8,55,124,14,12,196,0,55,14  ; n3541 t=198.015s dur=2106ms, freq=196Hz, sample=55, buffer_id=0E:37
    db 232,1,58,8,60,124,14,13,38,1,60,14  ; n3542 t=198.015s dur=2106ms, freq=294Hz, sample=60, buffer_id=0E:3C
    db 31,2,109,0,43,120,3,0,98,0,43,2  ; n3543 t=198.504s dur=109ms, freq=98Hz, sample=43, buffer_id=02:2B
    db 148,0,95,1,65,110,4,0,136,1,65,4  ; n3544 t=199.047s dur=351ms, freq=392Hz, sample=65, buffer_id=04:41
    db 132,0,131,0,65,110,16,1,136,1,65,16  ; n3545 t=199.195s dur=131ms, freq=392Hz, sample=65, buffer_id=10:41
    db 71,0,131,0,73,110,16,2,210,1,73,16  ; n3546 t=199.327s dur=131ms, freq=466Hz, sample=73, buffer_id=10:49
    db 60,0,95,1,70,110,4,3,184,1,70,4  ; n3547 t=199.398s dur=351ms, freq=440Hz, sample=70, buffer_id=04:46
    db 99,0,131,0,73,110,16,6,75,2,73,16  ; n3548 t=199.458s dur=131ms, freq=587Hz, sample=73, buffer_id=10:49
    db 33,0,109,0,34,120,3,1,58,0,34,2  ; n3549 t=199.557s dur=109ms, freq=58Hz, sample=34, buffer_id=02:22
    db 132,0,131,0,77,110,16,7,16,3,77,16  ; n3550 t=199.590s dur=131ms, freq=784Hz, sample=77, buffer_id=10:4D
    db 27,0,131,0,84,110,16,0,164,3,84,16  ; n3551 t=199.722s dur=131ms, freq=932Hz, sample=84, buffer_id=10:54
    db 104,0,95,1,70,110,4,2,210,1,70,4  ; n3552 t=199.749s dur=351ms, freq=466Hz, sample=70, buffer_id=04:46
    db 132,0,131,0,84,110,16,6,151,4,84,16  ; n3553 t=199.853s dur=131ms, freq=1175Hz, sample=84, buffer_id=10:54
    db 99,0,131,0,89,110,16,1,32,6,89,16  ; n3554 t=199.985s dur=131ms, freq=1568Hz, sample=89, buffer_id=10:59
    db 11,0,107,0,34,120,3,0,58,0,34,2  ; n3555 t=200.084s dur=107ms, freq=58Hz, sample=34, buffer_id=02:22
    db 0,0,85,1,60,120,11,3,6,1,60,2  ; n3556 t=200.095s dur=341ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 6,0,255,2,58,115,13,7,233,0,58,2  ; n3557 t=200.095s dur=767ms, freq=233Hz, sample=58, buffer_id=02:3A
    db 5,0,83,5,65,110,4,8,114,1,65,4  ; n3558 t=200.100s dur=1363ms, freq=370Hz, sample=65, buffer_id=04:41
    db 0,0,85,1,84,120,7,9,23,4,84,2  ; n3559 t=200.106s dur=341ms, freq=1047Hz, sample=84, buffer_id=02:54
    db 11,0,85,1,72,120,9,10,11,2,72,2  ; n3560 t=200.106s dur=341ms, freq=523Hz, sample=72, buffer_id=02:48
    db 5,0,255,1,94,110,16,4,73,7,94,16  ; n3561 t=200.117s dur=511ms, freq=1865Hz, sample=94, buffer_id=10:5E [TRUNCATE prev:ch4 @197999.5ms -> 200116.8ms]
    db 0,0,254,2,60,124,14,11,233,0,60,14  ; n3562 t=200.122s dur=766ms, freq=233Hz, sample=60, buffer_id=0E:3C [TRUNCATE prev:ch11 @198015.4ms -> 200122.3ms]
    db 0,0,252,7,55,124,14,12,185,0,55,14  ; n3563 t=200.122s dur=2044ms, freq=185Hz, sample=55, buffer_id=0E:37 [TRUNCATE prev:ch12 @198015.4ms -> 200122.3ms]
    db 58,1,252,7,65,124,14,5,55,1,65,14  ; n3564 t=200.122s dur=2044ms, freq=311Hz, sample=65, buffer_id=0E:41 [TRUNCATE prev:ch5 @197999.5ms -> 200122.3ms]
    db 11,0,241,0,61,120,11,0,38,1,61,2  ; n3565 t=200.436s dur=241ms, freq=294Hz, sample=61, buffer_id=02:3D
    db 0,0,84,1,86,120,7,1,151,4,86,2  ; n3566 t=200.447s dur=340ms, freq=1175Hz, sample=86, buffer_id=02:56
    db 149,0,84,1,73,120,9,2,75,2,73,2  ; n3567 t=200.447s dur=340ms, freq=587Hz, sample=73, buffer_id=02:49
    db 181,0,106,0,45,120,3,6,117,0,45,2  ; n3568 t=200.596s dur=106ms, freq=117Hz, sample=45, buffer_id=02:2D
    db 11,0,84,1,63,120,11,3,55,1,63,2  ; n3569 t=200.777s dur=340ms, freq=311Hz, sample=63, buffer_id=02:3F
    db 0,0,84,1,86,120,7,9,221,4,86,2  ; n3570 t=200.788s dur=340ms, freq=1245Hz, sample=86, buffer_id=02:56
    db 75,0,84,1,75,120,9,10,110,2,75,2  ; n3571 t=200.788s dur=340ms, freq=622Hz, sample=75, buffer_id=02:4B
    db 27,0,254,2,60,115,13,4,6,1,60,2  ; n3572 t=200.863s dur=766ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 229,0,254,2,60,124,14,0,6,1,60,14  ; n3573 t=200.889s dur=766ms, freq=262Hz, sample=60, buffer_id=0E:3C
    db 11,0,255,1,53,120,11,1,185,0,53,2  ; n3574 t=201.118s dur=511ms, freq=185Hz, sample=53, buffer_id=02:35
    db 0,0,255,1,79,120,7,2,228,2,79,2  ; n3575 t=201.129s dur=511ms, freq=740Hz, sample=79, buffer_id=02:4F
    db 79,1,255,1,66,120,9,6,114,1,66,2  ; n3576 t=201.129s dur=511ms, freq=370Hz, sample=66, buffer_id=02:42
    db 154,0,84,1,65,110,4,3,55,1,65,4  ; n3577 t=201.464s dur=340ms, freq=311Hz, sample=65, buffer_id=04:41
    db 11,0,106,0,34,120,3,7,58,0,34,2  ; n3578 t=201.619s dur=106ms, freq=58Hz, sample=34, buffer_id=02:22
    db 0,0,255,1,60,120,11,9,6,1,60,2  ; n3579 t=201.629s dur=511ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 11,0,255,1,58,115,13,10,233,0,58,2  ; n3580 t=201.629s dur=511ms, freq=233Hz, sample=58, buffer_id=02:3A
    db 0,0,255,1,84,120,7,11,23,4,84,2  ; n3581 t=201.640s dur=511ms, freq=1047Hz, sample=84, buffer_id=02:54
    db 16,0,255,1,72,120,9,13,11,2,72,2  ; n3582 t=201.640s dur=511ms, freq=523Hz, sample=72, buffer_id=02:48
    db 149,0,255,1,60,124,14,0,233,0,60,14  ; n3583 t=201.656s dur=511ms, freq=233Hz, sample=60, buffer_id=0E:3C [TRUNCATE prev:ch0 @200889.1ms -> 201655.9ms]
    db 69,1,84,1,60,110,4,8,6,1,60,4  ; n3584 t=201.805s dur=340ms, freq=262Hz, sample=60, buffer_id=04:3C
    db 11,0,111,0,34,120,3,1,58,0,34,2  ; n3585 t=202.130s dur=111ms, freq=58Hz, sample=34, buffer_id=02:22
    db 0,0,241,0,61,120,11,2,38,1,61,2  ; n3586 t=202.141s dur=241ms, freq=294Hz, sample=61, buffer_id=02:3D
    db 5,0,88,6,53,115,13,3,175,0,53,2  ; n3587 t=202.141s dur=1624ms, freq=175Hz, sample=53, buffer_id=02:35
    db 5,0,89,6,60,110,4,4,38,1,60,4  ; n3588 t=202.146s dur=1625ms, freq=294Hz, sample=60, buffer_id=04:3C
    db 0,0,107,1,86,120,7,6,151,4,86,2  ; n3589 t=202.151s dur=363ms, freq=1175Hz, sample=86, buffer_id=02:56
    db 11,0,107,1,73,120,9,7,75,2,73,2  ; n3590 t=202.151s dur=363ms, freq=587Hz, sample=73, buffer_id=02:49
    db 5,0,107,1,84,110,16,5,151,4,84,16  ; n3591 t=202.162s dur=363ms, freq=1175Hz, sample=84, buffer_id=10:54 [TRUNCATE prev:ch5 @200122.3ms -> 202161.8ms]
    db 0,0,36,4,65,124,14,12,93,1,65,14  ; n3592 t=202.167s dur=1060ms, freq=349Hz, sample=65, buffer_id=0E:41 [TRUNCATE prev:ch12 @200122.3ms -> 202167.1ms]
    db 0,0,91,6,60,124,14,0,38,1,60,14  ; n3593 t=202.167s dur=1627ms, freq=294Hz, sample=60, buffer_id=0E:3C [TRUNCATE prev:ch0 @201655.9ms -> 202167.1ms]
    db 80,1,220,8,60,124,14,9,233,0,60,14  ; n3594 t=202.167s dur=2268ms, freq=233Hz, sample=60, buffer_id=0E:3C [TRUNCATE prev:ch9 @201629.3ms -> 202167.1ms]
    db 11,0,99,1,63,120,11,1,55,1,63,2  ; n3595 t=202.503s dur=355ms, freq=311Hz, sample=63, buffer_id=02:3F
    db 0,0,98,1,86,120,7,8,221,4,86,2  ; n3596 t=202.514s dur=354ms, freq=1245Hz, sample=86, buffer_id=02:56
    db 11,0,98,1,75,120,9,10,110,2,75,2  ; n3597 t=202.514s dur=354ms, freq=622Hz, sample=75, buffer_id=02:4B
    db 77,1,97,1,89,110,16,11,221,4,89,16  ; n3598 t=202.525s dur=353ms, freq=1245Hz, sample=89, buffer_id=10:59
    db 11,0,87,1,65,120,11,2,93,1,65,2  ; n3599 t=202.858s dur=343ms, freq=349Hz, sample=65, buffer_id=02:41
    db 0,0,87,1,91,120,7,5,117,5,91,2  ; n3600 t=202.869s dur=343ms, freq=1397Hz, sample=91, buffer_id=02:5B
    db 11,0,87,1,75,120,9,6,186,2,75,2  ; n3601 t=202.869s dur=343ms, freq=698Hz, sample=75, buffer_id=02:4B
    db 55,1,87,1,89,110,16,7,117,5,89,16  ; n3602 t=202.879s dur=343ms, freq=1397Hz, sample=89, buffer_id=10:59
    db 11,0,114,0,41,120,3,1,78,0,41,2  ; n3603 t=203.190s dur=114ms, freq=78Hz, sample=41, buffer_id=02:29
    db 11,0,52,2,67,120,11,8,159,1,67,2  ; n3604 t=203.201s dur=564ms, freq=415Hz, sample=67, buffer_id=02:43
    db 0,0,53,2,91,120,7,10,125,6,91,2  ; n3605 t=203.212s dur=565ms, freq=1661Hz, sample=91, buffer_id=02:5B
    db 11,0,53,2,79,120,9,11,63,3,79,2  ; n3606 t=203.212s dur=565ms, freq=831Hz, sample=79, buffer_id=02:4F
    db 5,0,54,2,94,110,16,13,125,6,94,16  ; n3607 t=203.222s dur=566ms, freq=1661Hz, sample=94, buffer_id=10:5E
    db 25,2,183,4,65,124,14,12,114,1,65,14  ; n3608 t=203.228s dur=1207ms, freq=370Hz, sample=65, buffer_id=0E:41 [TRUNCATE prev:ch12 @202167.1ms -> 203227.8ms]
    db 0,0,125,2,66,120,11,1,114,1,66,2  ; n3609 t=203.765s dur=637ms, freq=370Hz, sample=66, buffer_id=02:42
    db 6,0,125,2,50,115,13,2,156,0,50,2  ; n3610 t=203.765s dur=637ms, freq=156Hz, sample=50, buffer_id=02:32
    db 6,0,125,2,65,110,4,5,55,1,65,4  ; n3611 t=203.771s dur=637ms, freq=311Hz, sample=65, buffer_id=04:41
    db 0,0,126,2,91,120,7,6,200,5,91,2  ; n3612 t=203.777s dur=638ms, freq=1480Hz, sample=91, buffer_id=02:5B
    db 12,0,126,2,79,120,9,7,228,2,79,2  ; n3613 t=203.777s dur=638ms, freq=740Hz, sample=79, buffer_id=02:4F
    db 6,0,128,2,89,110,16,3,200,5,89,16  ; n3614 t=203.789s dur=640ms, freq=1480Hz, sample=89, buffer_id=10:59 [TRUNCATE prev:ch3 @202140.5ms -> 203788.8ms]
    db 96,2,129,2,65,124,14,12,55,1,65,14  ; n3615 t=203.795s dur=641ms, freq=311Hz, sample=65, buffer_id=0E:41 [TRUNCATE prev:ch12 @203227.8ms -> 203794.7ms]
    db 0,0,119,1,53,120,11,0,185,0,53,2  ; n3616 t=204.402s dur=375ms, freq=185Hz, sample=53, buffer_id=02:35
    db 13,0,119,1,50,115,13,4,156,0,50,2  ; n3617 t=204.402s dur=375ms, freq=156Hz, sample=50, buffer_id=02:32
    db 0,0,117,1,79,120,7,8,228,2,79,2  ; n3618 t=204.416s dur=373ms, freq=740Hz, sample=79, buffer_id=02:4F
    db 13,0,117,1,66,120,9,10,114,1,66,2  ; n3619 t=204.416s dur=373ms, freq=370Hz, sample=66, buffer_id=02:42
    db 7,0,115,1,77,110,16,11,228,2,77,16  ; n3620 t=204.429s dur=371ms, freq=740Hz, sample=77, buffer_id=10:4D
    db 0,0,87,4,55,124,14,13,185,0,55,14  ; n3621 t=204.436s dur=1111ms, freq=185Hz, sample=55, buffer_id=0E:37
    db 0,0,87,4,60,124,14,9,6,1,60,14  ; n3622 t=204.436s dur=1111ms, freq=262Hz, sample=60, buffer_id=0E:3C [TRUNCATE prev:ch9 @202167.1ms -> 204435.7ms]
    db 86,1,87,4,65,124,14,12,55,1,65,14  ; n3623 t=204.436s dur=1111ms, freq=311Hz, sample=65, buffer_id=0E:41 [TRUNCATE prev:ch12 @203794.7ms -> 204435.7ms]
    db 0,0,241,0,56,120,11,1,220,0,56,2  ; n3624 t=204.777s dur=241ms, freq=220Hz, sample=56, buffer_id=02:38
    db 12,0,114,1,53,115,13,2,175,0,53,2  ; n3625 t=204.777s dur=370ms, freq=175Hz, sample=53, buffer_id=02:35
    db 0,0,114,1,79,120,7,3,112,3,79,2  ; n3626 t=204.789s dur=370ms, freq=880Hz, sample=79, buffer_id=02:4F
    db 12,0,114,1,67,120,9,5,184,1,67,2  ; n3627 t=204.789s dur=370ms, freq=440Hz, sample=67, buffer_id=02:43
    db 91,1,114,1,84,110,16,6,112,3,84,16  ; n3628 t=204.800s dur=370ms, freq=880Hz, sample=84, buffer_id=10:54
    db 0,0,114,1,58,120,11,0,233,0,58,2  ; n3629 t=205.148s dur=370ms, freq=233Hz, sample=58, buffer_id=02:3A
    db 12,0,114,1,53,115,13,4,185,0,53,2  ; n3630 t=205.148s dur=370ms, freq=185Hz, sample=53, buffer_id=02:35
    db 0,0,114,1,84,120,7,7,164,3,84,2  ; n3631 t=205.160s dur=370ms, freq=932Hz, sample=84, buffer_id=02:54
    db 12,0,114,1,71,120,9,8,210,1,71,2  ; n3632 t=205.160s dur=370ms, freq=466Hz, sample=71, buffer_id=02:47
    db 80,1,114,1,84,110,16,10,164,3,84,16  ; n3633 t=205.171s dur=370ms, freq=932Hz, sample=84, buffer_id=10:54
    db 12,0,121,0,34,120,3,1,58,0,34,2  ; n3634 t=205.507s dur=121ms, freq=58Hz, sample=34, buffer_id=02:22
    db 0,0,82,2,63,120,11,2,55,1,63,2  ; n3635 t=205.518s dur=594ms, freq=311Hz, sample=63, buffer_id=02:3F
    db 12,0,241,0,56,115,13,3,220,0,56,2  ; n3636 t=205.518s dur=241ms, freq=220Hz, sample=56, buffer_id=02:38
    db 0,0,83,2,86,120,7,5,221,4,86,2  ; n3637 t=205.530s dur=595ms, freq=1245Hz, sample=86, buffer_id=02:56
    db 12,0,83,2,75,120,9,6,110,2,75,2  ; n3638 t=205.530s dur=595ms, freq=622Hz, sample=75, buffer_id=02:4B
    db 6,0,83,2,89,110,16,11,221,4,89,16  ; n3639 t=205.542s dur=595ms, freq=1245Hz, sample=89, buffer_id=10:59
    db 0,0,84,2,60,124,14,9,6,1,60,14  ; n3640 t=205.548s dur=596ms, freq=262Hz, sample=60, buffer_id=0E:3C [TRUNCATE prev:ch9 @204435.7ms -> 205547.5ms]
    db 0,0,237,4,55,124,14,13,175,0,55,14  ; n3641 t=205.548s dur=1261ms, freq=175Hz, sample=55, buffer_id=0E:37 [TRUNCATE prev:ch13 @204435.7ms -> 205547.5ms]
    db 53,2,237,4,60,124,14,12,38,1,60,14  ; n3642 t=205.548s dur=1261ms, freq=294Hz, sample=60, buffer_id=0E:3C [TRUNCATE prev:ch12 @204435.7ms -> 205547.5ms]
    db 0,0,241,0,61,120,11,0,38,1,61,2  ; n3643 t=206.113s dur=241ms, freq=294Hz, sample=61, buffer_id=02:3D
    db 12,0,149,2,58,115,13,1,233,0,58,2  ; n3644 t=206.113s dur=661ms, freq=233Hz, sample=58, buffer_id=02:3A
    db 0,0,150,2,86,120,7,3,151,4,86,2  ; n3645 t=206.125s dur=662ms, freq=1175Hz, sample=86, buffer_id=02:56
    db 12,0,150,2,73,120,9,4,75,2,73,2  ; n3646 t=206.125s dur=662ms, freq=587Hz, sample=73, buffer_id=02:49
    db 6,0,152,2,84,110,16,7,151,4,84,16  ; n3647 t=206.137s dur=664ms, freq=1175Hz, sample=84, buffer_id=10:54
    db 118,2,152,2,60,124,14,8,233,0,60,14  ; n3648 t=206.144s dur=664ms, freq=233Hz, sample=60, buffer_id=0E:3C
    db 0,0,0,1,61,120,11,2,21,1,61,2  ; n3649 t=206.774s dur=256ms, freq=277Hz, sample=61, buffer_id=02:3D
    db 14,0,241,0,56,115,13,0,220,0,56,2  ; n3650 t=206.774s dur=241ms, freq=220Hz, sample=56, buffer_id=02:38
    db 0,0,8,10,84,120,7,5,85,4,84,2  ; n3651 t=206.788s dur=2568ms, freq=1109Hz, sample=84, buffer_id=02:54
    db 14,0,8,10,73,120,9,6,42,2,73,2  ; n3652 t=206.788s dur=2568ms, freq=554Hz, sample=73, buffer_id=02:49
    db 7,0,205,9,84,110,16,9,85,4,84,16  ; n3653 t=206.802s dur=2509ms, freq=1109Hz, sample=84, buffer_id=10:54
    db 0,0,209,8,55,124,14,10,220,0,55,14  ; n3654 t=206.809s dur=2257ms, freq=220Hz, sample=55, buffer_id=0E:37
    db 0,0,209,8,60,124,14,11,21,1,60,14  ; n3655 t=206.809s dur=2257ms, freq=277Hz, sample=60, buffer_id=0E:3C
    db 11,2,209,8,50,124,14,12,165,0,50,14  ; n3656 t=206.809s dur=2257ms, freq=165Hz, sample=50, buffer_id=0E:32 [TRUNCATE prev:ch12 @205547.5ms -> 206808.6ms]
    db 18,0,117,0,45,120,3,0,110,0,45,2  ; n3657 t=207.332s dur=117ms, freq=110Hz, sample=45, buffer_id=02:2D
    db 8,1,104,4,70,110,4,1,184,1,70,4  ; n3658 t=207.350s dur=1128ms, freq=440Hz, sample=70, buffer_id=04:46
    db 26,1,117,0,41,120,3,2,82,0,41,2  ; n3659 t=207.614s dur=117ms, freq=82Hz, sample=41, buffer_id=02:29
    db 52,2,117,0,34,120,3,0,55,0,34,2  ; n3660 t=207.896s dur=117ms, freq=55Hz, sample=34, buffer_id=02:22
    db 18,0,117,0,45,120,3,0,110,0,45,2  ; n3661 t=208.461s dur=117ms, freq=110Hz, sample=45, buffer_id=02:2D
    db 35,2,52,2,65,110,4,2,74,1,65,4  ; n3662 t=208.478s dur=564ms, freq=330Hz, sample=65, buffer_id=04:41
    db 12,0,124,0,36,120,3,0,65,0,36,2  ; n3663 t=209.025s dur=124ms, freq=65Hz, sample=36, buffer_id=02:24
    db 6,0,3,8,58,115,13,1,233,0,58,2  ; n3664 t=209.037s dur=2051ms, freq=233Hz, sample=58, buffer_id=02:3A
    db 24,0,5,8,65,110,4,3,55,1,65,4  ; n3665 t=209.043s dur=2053ms, freq=311Hz, sample=65, buffer_id=04:41
    db 0,0,13,8,36,120,1,4,65,0,36,1  ; n3666 t=209.066s dur=2061ms, freq=65Hz, sample=36, buffer_id=01:24
    db 0,0,13,8,60,124,14,7,233,0,60,14  ; n3667 t=209.066s dur=2061ms, freq=233Hz, sample=60, buffer_id=0E:3C
    db 0,0,13,8,55,124,14,8,185,0,55,14  ; n3668 t=209.066s dur=2061ms, freq=185Hz, sample=55, buffer_id=0E:37
    db 74,2,13,8,65,124,14,13,55,1,65,14  ; n3669 t=209.066s dur=2061ms, freq=311Hz, sample=65, buffer_id=0E:41
    db 13,0,170,2,58,120,11,0,233,0,58,2  ; n3670 t=209.653s dur=682ms, freq=233Hz, sample=58, buffer_id=02:3A
    db 0,0,171,2,84,120,7,2,164,3,84,2  ; n3671 t=209.665s dur=683ms, freq=932Hz, sample=84, buffer_id=02:54
    db 157,2,171,2,71,120,9,5,210,1,71,2  ; n3672 t=209.665s dur=683ms, freq=466Hz, sample=71, buffer_id=02:47
    db 14,0,241,2,53,120,11,6,185,0,53,2  ; n3673 t=210.335s dur=753ms, freq=185Hz, sample=53, buffer_id=02:35
    db 0,0,243,2,79,120,7,9,228,2,79,2  ; n3674 t=210.349s dur=755ms, freq=740Hz, sample=79, buffer_id=02:4F
    db 227,2,243,2,66,120,9,10,114,1,66,2  ; n3675 t=210.349s dur=755ms, freq=370Hz, sample=66, buffer_id=02:42
    db 0,0,169,2,67,120,11,0,184,1,67,2  ; n3676 t=211.088s dur=681ms, freq=440Hz, sample=67, buffer_id=02:43
    db 16,0,169,2,53,115,13,2,185,0,53,2  ; n3677 t=211.088s dur=681ms, freq=185Hz, sample=53, buffer_id=02:35
    db 0,0,167,2,91,120,7,5,224,6,91,2  ; n3678 t=211.104s dur=679ms, freq=1760Hz, sample=91, buffer_id=02:5B
    db 139,2,167,2,79,120,9,11,112,3,79,2  ; n3679 t=211.104s dur=679ms, freq=880Hz, sample=79, buffer_id=02:4F
    db 14,0,137,0,29,120,3,1,49,0,29,2  ; n3680 t=211.756s dur=137ms, freq=49Hz, sample=29, buffer_id=02:1D
    db 0,0,213,11,71,120,11,3,210,1,71,2  ; n3681 t=211.770s dur=3029ms, freq=466Hz, sample=71, buffer_id=02:47
    db 7,0,15,1,56,115,13,4,196,0,56,2  ; n3682 t=211.770s dur=271ms, freq=196Hz, sample=56, buffer_id=02:38
    db 7,0,60,10,60,110,4,6,38,1,60,4  ; n3683 t=211.777s dur=2620ms, freq=294Hz, sample=60, buffer_id=04:3C
    db 0,0,216,11,91,120,7,7,73,7,91,2  ; n3684 t=211.784s dur=3032ms, freq=1865Hz, sample=91, buffer_id=02:5B
    db 21,0,216,11,84,120,9,8,164,3,84,2  ; n3685 t=211.784s dur=3032ms, freq=932Hz, sample=84, buffer_id=02:54
    db 0,0,138,2,43,120,1,9,98,0,43,1  ; n3686 t=211.805s dur=650ms, freq=98Hz, sample=43, buffer_id=01:2B
    db 0,0,138,2,55,124,14,10,196,0,55,14  ; n3687 t=211.805s dur=650ms, freq=196Hz, sample=55, buffer_id=0E:37
    db 0,0,138,2,60,124,14,12,233,0,60,14  ; n3688 t=211.805s dur=650ms, freq=233Hz, sample=60, buffer_id=0E:3C
    db 35,1,138,2,50,124,14,13,147,0,50,14  ; n3689 t=211.805s dur=650ms, freq=147Hz, sample=50, buffer_id=0E:32
    db 56,1,69,1,50,115,13,0,147,0,50,2  ; n3690 t=212.096s dur=325ms, freq=147Hz, sample=50, buffer_id=02:32
    db 14,0,132,0,43,120,3,1,98,0,43,2  ; n3691 t=212.408s dur=132ms, freq=98Hz, sample=43, buffer_id=02:2B
    db 34,0,15,1,56,115,13,2,196,0,56,2  ; n3692 t=212.422s dur=271ms, freq=196Hz, sample=56, buffer_id=02:38
    db 0,0,213,4,43,120,1,4,98,0,43,1  ; n3693 t=212.456s dur=1237ms, freq=98Hz, sample=43, buffer_id=01:2B
    db 0,0,213,4,60,124,14,5,233,0,60,14  ; n3694 t=212.456s dur=1237ms, freq=233Hz, sample=60, buffer_id=0E:3C
    db 0,0,213,4,55,124,14,11,196,0,55,14  ; n3695 t=212.456s dur=1237ms, freq=196Hz, sample=55, buffer_id=0E:37
    db 24,1,213,4,50,124,14,13,147,0,50,14  ; n3696 t=212.456s dur=1237ms, freq=147Hz, sample=50, buffer_id=0E:32 [TRUNCATE prev:ch13 @211805.0ms -> 212455.5ms]
    db 56,1,56,1,58,115,13,0,233,0,58,2  ; n3697 t=212.735s dur=312ms, freq=233Hz, sample=58, buffer_id=02:3A
    db 51,1,241,0,61,115,13,1,38,1,61,2  ; n3698 t=213.047s dur=241ms, freq=294Hz, sample=61, buffer_id=02:3D
    db 37,1,50,1,67,115,13,0,136,1,67,2  ; n3699 t=213.354s dur=306ms, freq=392Hz, sample=67, buffer_id=02:43
    db 13,0,144,0,29,120,3,1,49,0,29,2  ; n3700 t=213.648s dur=144ms, freq=49Hz, sample=29, buffer_id=02:1D
    db 32,0,105,1,67,115,13,2,184,1,67,2  ; n3701 t=213.661s dur=361ms, freq=440Hz, sample=67, buffer_id=02:43
    db 0,0,222,2,43,120,1,10,98,0,43,1  ; n3702 t=213.693s dur=734ms, freq=98Hz, sample=43, buffer_id=01:2B
    db 0,0,222,2,55,124,14,9,196,0,55,14  ; n3703 t=213.693s dur=734ms, freq=196Hz, sample=55, buffer_id=0E:37
    db 0,0,222,2,60,124,14,12,233,0,60,14  ; n3704 t=213.693s dur=734ms, freq=233Hz, sample=60, buffer_id=0E:3C [TRUNCATE prev:ch12 @211805.0ms -> 213692.6ms]
    db 73,1,222,2,50,124,14,13,147,0,50,14  ; n3705 t=213.693s dur=734ms, freq=147Hz, sample=50, buffer_id=0E:32 [TRUNCATE prev:ch13 @212455.5ms -> 213692.6ms]
    db 96,1,111,1,71,115,13,0,210,1,71,2  ; n3706 t=214.022s dur=367ms, freq=466Hz, sample=71, buffer_id=02:47
    db 15,0,165,0,36,120,3,1,65,0,36,2  ; n3707 t=214.374s dur=165ms, freq=65Hz, sample=36, buffer_id=02:24
    db 8,0,182,6,73,115,13,2,75,2,73,2  ; n3708 t=214.389s dur=1718ms, freq=587Hz, sample=73, buffer_id=02:49
    db 31,0,215,14,65,110,4,4,55,1,65,4  ; n3709 t=214.397s dur=3799ms, freq=311Hz, sample=65, buffer_id=04:41
    db 0,0,225,14,36,120,1,5,65,0,36,1  ; n3710 t=214.428s dur=3809ms, freq=65Hz, sample=36, buffer_id=01:24
    db 0,0,225,14,60,124,14,11,233,0,60,14  ; n3711 t=214.428s dur=3809ms, freq=233Hz, sample=60, buffer_id=0E:3C
    db 0,0,225,14,50,124,14,13,156,0,50,14  ; n3712 t=214.428s dur=3809ms, freq=156Hz, sample=50, buffer_id=0E:32 [TRUNCATE prev:ch13 @213692.6ms -> 214427.5ms]
    db 18,3,225,14,55,124,14,9,185,0,55,14  ; n3713 t=214.428s dur=3809ms, freq=185Hz, sample=55, buffer_id=0E:37 [TRUNCATE prev:ch9 @213692.6ms -> 214427.5ms]
    db 17,0,126,3,58,120,11,0,233,0,58,2  ; n3714 t=215.214s dur=894ms, freq=233Hz, sample=58, buffer_id=02:3A
    db 0,0,127,3,84,120,7,1,164,3,84,2  ; n3715 t=215.231s dur=895ms, freq=932Hz, sample=84, buffer_id=02:54
    db 109,3,127,3,71,120,9,6,210,1,71,2  ; n3716 t=215.231s dur=895ms, freq=466Hz, sample=71, buffer_id=02:47
    db 0,0,52,4,53,120,11,3,185,0,53,2  ; n3717 t=216.108s dur=1076ms, freq=185Hz, sample=53, buffer_id=02:35
    db 19,0,29,8,72,115,13,7,11,2,72,2  ; n3718 t=216.108s dur=2077ms, freq=523Hz, sample=72, buffer_id=02:48
    db 0,0,56,4,79,120,7,8,228,2,79,2  ; n3719 t=216.127s dur=1080ms, freq=740Hz, sample=79, buffer_id=02:4F
    db 34,4,56,4,66,120,9,10,114,1,66,2  ; n3720 t=216.127s dur=1080ms, freq=370Hz, sample=66, buffer_id=02:42
    db 23,0,233,3,67,120,11,0,184,1,67,2  ; n3721 t=217.184s dur=1001ms, freq=440Hz, sample=67, buffer_id=02:43
    db 0,0,231,3,91,120,7,1,224,6,91,2  ; n3722 t=217.207s dur=999ms, freq=1760Hz, sample=91, buffer_id=02:5B
    db 190,3,231,3,79,120,9,2,112,3,79,2  ; n3723 t=217.207s dur=999ms, freq=880Hz, sample=79, buffer_id=02:4F
    db 21,0,136,0,34,120,3,3,58,0,34,2  ; n3724 t=218.165s dur=136ms, freq=58Hz, sample=34, buffer_id=02:22
    db 21,0,102,31,71,115,13,8,210,1,71,2  ; n3725 t=218.185s dur=8038ms, freq=466Hz, sample=71, buffer_id=02:47
    db 0,0,44,22,91,120,7,6,73,7,91,2  ; n3726 t=218.206s dur=5676ms, freq=1865Hz, sample=91, buffer_id=02:5B
    db 21,0,91,31,84,120,9,10,164,3,84,2  ; n3727 t=218.206s dur=8027ms, freq=932Hz, sample=84, buffer_id=02:54
    db 0,0,100,0,77,110,16,12,186,2,77,16  ; n3728 t=218.227s dur=100ms, freq=698Hz, sample=77, buffer_id=10:4D
    db 0,0,100,0,73,110,16,4,75,2,73,16  ; n3729 t=218.227s dur=100ms, freq=587Hz, sample=73, buffer_id=10:49 [TRUNCATE prev:ch4 @214396.9ms -> 218227.0ms]
    db 10,0,100,0,70,100,18,5,210,1,70,18  ; n3730 t=218.227s dur=100ms, freq=466Hz, sample=70, buffer_id=12:46 [TRUNCATE prev:ch5 @214427.5ms -> 218227.0ms]
    db 0,0,218,1,36,120,1,9,58,0,36,1  ; n3731 t=218.237s dur=474ms, freq=58Hz, sample=36, buffer_id=01:24 [TRUNCATE prev:ch9 @214427.5ms -> 218237.4ms]
    db 0,0,218,1,55,124,14,11,175,0,55,14  ; n3732 t=218.237s dur=474ms, freq=175Hz, sample=55, buffer_id=0E:37 [TRUNCATE prev:ch11 @214427.5ms -> 218237.4ms]
    db 0,0,218,1,60,124,14,13,233,0,60,14  ; n3733 t=218.237s dur=474ms, freq=233Hz, sample=60, buffer_id=0E:3C [TRUNCATE prev:ch13 @214427.5ms -> 218237.4ms]
    db 214,1,218,1,50,124,14,7,147,0,50,14  ; n3734 t=218.237s dur=474ms, freq=147Hz, sample=50, buffer_id=0E:32 [TRUNCATE prev:ch7 @216108.0ms -> 218237.4ms]
    db 0,0,100,0,77,110,16,0,186,2,77,16  ; n3735 t=218.707s dur=100ms, freq=698Hz, sample=77, buffer_id=10:4D
    db 0,0,100,0,73,110,16,1,75,2,73,16  ; n3736 t=218.707s dur=100ms, freq=587Hz, sample=73, buffer_id=10:49
    db 219,1,100,0,70,100,18,2,210,1,70,18  ; n3737 t=218.707s dur=100ms, freq=466Hz, sample=70, buffer_id=12:46
    db 0,0,100,0,77,110,16,1,186,2,77,16  ; n3738 t=219.181s dur=100ms, freq=698Hz, sample=77, buffer_id=10:4D
    db 0,0,100,0,73,110,16,0,75,2,73,16  ; n3739 t=219.181s dur=100ms, freq=587Hz, sample=73, buffer_id=10:49
    db 237,0,100,0,70,100,18,3,210,1,70,18  ; n3740 t=219.181s dur=100ms, freq=466Hz, sample=70, buffer_id=12:46
    db 0,0,100,0,77,110,16,2,186,2,77,16  ; n3741 t=219.419s dur=100ms, freq=698Hz, sample=77, buffer_id=10:4D
    db 0,0,100,0,73,110,16,5,75,2,73,16  ; n3742 t=219.419s dur=100ms, freq=587Hz, sample=73, buffer_id=10:49
    db 119,0,100,0,70,100,18,4,210,1,70,18  ; n3743 t=219.419s dur=100ms, freq=466Hz, sample=70, buffer_id=12:46
    db 0,0,100,0,77,110,16,0,186,2,77,16  ; n3744 t=219.537s dur=100ms, freq=698Hz, sample=77, buffer_id=10:4D
    db 0,0,100,0,73,110,16,1,75,2,73,16  ; n3745 t=219.537s dur=100ms, freq=587Hz, sample=73, buffer_id=10:49
    db 89,0,100,0,70,100,18,7,210,1,70,18  ; n3746 t=219.537s dur=100ms, freq=466Hz, sample=70, buffer_id=12:46
    db 30,0,100,0,45,120,3,3,117,0,45,2  ; n3747 t=219.626s dur=100ms, freq=117Hz, sample=45, buffer_id=02:2D
    db 0,0,100,0,77,110,16,9,186,2,77,16  ; n3748 t=219.656s dur=100ms, freq=698Hz, sample=77, buffer_id=10:4D
    db 0,0,100,0,73,110,16,11,75,2,73,16  ; n3749 t=219.656s dur=100ms, freq=587Hz, sample=73, buffer_id=10:49
    db 119,0,100,0,70,100,18,12,210,1,70,18  ; n3750 t=219.656s dur=100ms, freq=466Hz, sample=70, buffer_id=12:46
    db 0,0,100,0,77,110,16,4,186,2,77,16  ; n3751 t=219.775s dur=100ms, freq=698Hz, sample=77, buffer_id=10:4D
    db 0,0,100,0,73,110,16,2,75,2,73,16  ; n3752 t=219.775s dur=100ms, freq=587Hz, sample=73, buffer_id=10:49
    db 70,1,100,0,70,100,18,5,210,1,70,18  ; n3753 t=219.775s dur=100ms, freq=466Hz, sample=70, buffer_id=12:46
    db 30,0,100,0,34,120,3,0,58,0,34,2  ; n3754 t=220.101s dur=100ms, freq=58Hz, sample=34, buffer_id=02:22
    db 0,0,100,0,77,110,16,1,186,2,77,16  ; n3755 t=220.131s dur=100ms, freq=698Hz, sample=77, buffer_id=10:4D
    db 0,0,100,0,73,110,16,3,75,2,73,16  ; n3756 t=220.131s dur=100ms, freq=587Hz, sample=73, buffer_id=10:49
    db 218,1,100,0,70,100,18,2,210,1,70,18  ; n3757 t=220.131s dur=100ms, freq=466Hz, sample=70, buffer_id=12:46
    db 0,0,100,0,77,110,16,0,186,2,77,16  ; n3758 t=220.605s dur=100ms, freq=698Hz, sample=77, buffer_id=10:4D
    db 0,0,100,0,73,110,16,1,75,2,73,16  ; n3759 t=220.605s dur=100ms, freq=587Hz, sample=73, buffer_id=10:49
    db 218,1,100,0,70,100,18,3,210,1,70,18  ; n3760 t=220.605s dur=100ms, freq=466Hz, sample=70, buffer_id=12:46
    db 0,0,100,0,77,110,16,1,186,2,77,16  ; n3761 t=221.079s dur=100ms, freq=698Hz, sample=77, buffer_id=10:4D
    db 0,0,100,0,73,110,16,0,75,2,73,16  ; n3762 t=221.079s dur=100ms, freq=587Hz, sample=73, buffer_id=10:49
    db 237,0,100,0,70,100,18,4,210,1,70,18  ; n3763 t=221.079s dur=100ms, freq=466Hz, sample=70, buffer_id=12:46
    db 0,0,100,0,77,110,16,2,186,2,77,16  ; n3764 t=221.317s dur=100ms, freq=698Hz, sample=77, buffer_id=10:4D
    db 0,0,100,0,73,110,16,3,75,2,73,16  ; n3765 t=221.317s dur=100ms, freq=587Hz, sample=73, buffer_id=10:49
    db 119,0,100,0,70,100,18,9,210,1,70,18  ; n3766 t=221.317s dur=100ms, freq=466Hz, sample=70, buffer_id=12:46
    db 0,0,100,0,77,110,16,0,186,2,77,16  ; n3767 t=221.435s dur=100ms, freq=698Hz, sample=77, buffer_id=10:4D
    db 0,0,100,0,73,110,16,1,75,2,73,16  ; n3768 t=221.435s dur=100ms, freq=587Hz, sample=73, buffer_id=10:49
    db 89,0,100,0,70,100,18,11,210,1,70,18  ; n3769 t=221.435s dur=100ms, freq=466Hz, sample=70, buffer_id=12:46
    db 15,0,100,0,45,120,3,4,117,0,45,2  ; n3770 t=221.524s dur=100ms, freq=117Hz, sample=45, buffer_id=02:2D
    db 15,0,118,0,55,110,4,5,196,0,55,4  ; n3771 t=221.539s dur=118ms, freq=196Hz, sample=55, buffer_id=04:37
    db 0,0,100,0,77,110,16,7,186,2,77,16  ; n3772 t=221.554s dur=100ms, freq=698Hz, sample=77, buffer_id=10:4D
    db 0,0,100,0,73,110,16,12,75,2,73,16  ; n3773 t=221.554s dur=100ms, freq=587Hz, sample=73, buffer_id=10:49
    db 119,0,100,0,70,100,18,13,210,1,70,18  ; n3774 t=221.554s dur=100ms, freq=466Hz, sample=70, buffer_id=12:46
    db 0,0,100,0,77,110,16,3,186,2,77,16  ; n3775 t=221.673s dur=100ms, freq=698Hz, sample=77, buffer_id=10:4D
    db 0,0,100,0,73,110,16,2,75,2,73,16  ; n3776 t=221.673s dur=100ms, freq=587Hz, sample=73, buffer_id=10:49
    db 237,0,100,0,70,100,18,9,210,1,70,18  ; n3777 t=221.673s dur=100ms, freq=466Hz, sample=70, buffer_id=12:46 [TRUNCATE prev:ch9 @221316.7ms -> 221672.6ms]
    db 89,0,100,0,60,110,4,0,233,0,60,4  ; n3778 t=221.910s dur=100ms, freq=233Hz, sample=60, buffer_id=04:3C
    db 15,0,100,0,34,120,3,1,58,0,34,2  ; n3779 t=221.999s dur=100ms, freq=58Hz, sample=34, buffer_id=02:22
    db 5,0,0,11,55,110,4,2,208,0,55,4  ; n3780 t=222.014s dur=2816ms, freq=208Hz, sample=55, buffer_id=04:37
    db 10,0,234,0,61,120,12,3,21,1,61,2  ; n3781 t=222.019s dur=234ms, freq=277Hz, sample=61, buffer_id=02:3D
    db 0,0,100,0,77,110,16,4,186,2,77,16  ; n3782 t=222.028s dur=100ms, freq=698Hz, sample=77, buffer_id=10:4D
    db 0,0,100,0,73,110,16,5,42,2,73,16  ; n3783 t=222.028s dur=100ms, freq=554Hz, sample=73, buffer_id=10:49
    db 244,0,100,0,70,100,18,7,159,1,70,18  ; n3784 t=222.028s dur=100ms, freq=415Hz, sample=70, buffer_id=12:46
    db 224,0,234,0,56,120,12,0,208,0,56,2  ; n3785 t=222.272s dur=234ms, freq=208Hz, sample=56, buffer_id=02:38
    db 0,0,100,0,77,110,16,1,186,2,77,16  ; n3786 t=222.497s dur=100ms, freq=698Hz, sample=77, buffer_id=10:4D
    db 0,0,100,0,73,110,16,3,42,2,73,16  ; n3787 t=222.497s dur=100ms, freq=554Hz, sample=73, buffer_id=10:49
    db 203,1,100,0,70,100,18,4,159,1,70,18  ; n3788 t=222.497s dur=100ms, freq=415Hz, sample=70, buffer_id=12:46
    db 10,0,234,0,61,120,12,0,21,1,61,2  ; n3789 t=222.955s dur=234ms, freq=277Hz, sample=61, buffer_id=02:3D
    db 0,0,100,0,77,110,16,3,186,2,77,16  ; n3790 t=222.965s dur=100ms, freq=698Hz, sample=77, buffer_id=10:4D
    db 0,0,100,0,73,110,16,1,42,2,73,16  ; n3791 t=222.965s dur=100ms, freq=554Hz, sample=73, buffer_id=10:49
    db 234,0,100,0,70,100,18,5,159,1,70,18  ; n3792 t=222.965s dur=100ms, freq=415Hz, sample=70, buffer_id=12:46
    db 0,0,100,0,77,110,16,4,186,2,77,16  ; n3793 t=223.199s dur=100ms, freq=698Hz, sample=77, buffer_id=10:4D
    db 0,0,100,0,73,110,16,7,42,2,73,16  ; n3794 t=223.199s dur=100ms, freq=554Hz, sample=73, buffer_id=10:49
    db 10,0,100,0,70,100,18,12,159,1,70,18  ; n3795 t=223.199s dur=100ms, freq=415Hz, sample=70, buffer_id=12:46
    db 107,0,234,0,56,120,12,9,208,0,56,2  ; n3796 t=223.209s dur=234ms, freq=208Hz, sample=56, buffer_id=02:38
    db 0,0,100,0,77,110,16,1,186,2,77,16  ; n3797 t=223.316s dur=100ms, freq=698Hz, sample=77, buffer_id=10:4D
    db 0,0,100,0,73,110,16,3,42,2,73,16  ; n3798 t=223.316s dur=100ms, freq=554Hz, sample=73, buffer_id=10:49
    db 88,0,100,0,70,100,18,11,159,1,70,18  ; n3799 t=223.316s dur=100ms, freq=415Hz, sample=70, buffer_id=12:46 [TRUNCATE prev:ch11 @221435.3ms -> 223316.4ms]
    db 29,0,100,0,45,120,3,0,117,0,45,2  ; n3800 t=223.404s dur=100ms, freq=117Hz, sample=45, buffer_id=02:2D
    db 0,0,100,0,77,110,16,5,186,2,77,16  ; n3801 t=223.433s dur=100ms, freq=698Hz, sample=77, buffer_id=10:4D
    db 0,0,100,0,73,110,16,13,42,2,73,16  ; n3802 t=223.433s dur=100ms, freq=554Hz, sample=73, buffer_id=10:49
    db 117,0,100,0,70,100,18,12,159,1,70,18  ; n3803 t=223.433s dur=100ms, freq=415Hz, sample=70, buffer_id=12:46 [TRUNCATE prev:ch12 @223199.3ms -> 223433.4ms]
    db 0,0,100,0,77,110,16,7,186,2,77,16  ; n3804 t=223.550s dur=100ms, freq=698Hz, sample=77, buffer_id=10:4D
    db 0,0,100,0,73,110,16,4,42,2,73,16  ; n3805 t=223.550s dur=100ms, freq=554Hz, sample=73, buffer_id=10:49
    db 66,1,100,0,70,100,18,11,159,1,70,18  ; n3806 t=223.550s dur=100ms, freq=415Hz, sample=70, buffer_id=12:46 [TRUNCATE prev:ch11 @223316.4ms -> 223550.5ms]
    db 19,0,100,0,34,120,3,0,58,0,34,2  ; n3807 t=223.873s dur=100ms, freq=58Hz, sample=34, buffer_id=02:22
    db 10,0,234,0,61,120,12,1,21,1,61,2  ; n3808 t=223.892s dur=234ms, freq=277Hz, sample=61, buffer_id=02:3D
    db 0,0,100,0,77,110,16,3,63,3,77,16  ; n3809 t=223.902s dur=100ms, freq=831Hz, sample=77, buffer_id=10:4D
    db 0,0,100,0,73,110,16,5,42,2,73,16  ; n3810 t=223.902s dur=100ms, freq=554Hz, sample=73, buffer_id=10:49
    db 0,0,100,0,92,90,17,4,117,5,92,17  ; n3811 t=223.902s dur=100ms, freq=1397Hz, sample=92, buffer_id=11:5C
    db 5,0,100,0,70,100,18,7,159,1,70,18  ; n3812 t=223.902s dur=100ms, freq=415Hz, sample=70, buffer_id=12:46
    db 239,0,100,0,91,100,20,9,117,5,91,20  ; n3813 t=223.907s dur=100ms, freq=1397Hz, sample=91, buffer_id=14:5B
    db 224,0,234,0,56,120,12,6,208,0,56,2  ; n3814 t=224.146s dur=234ms, freq=208Hz, sample=56, buffer_id=02:38
    db 0,0,100,0,77,110,16,0,186,2,77,16  ; n3815 t=224.370s dur=100ms, freq=698Hz, sample=77, buffer_id=10:4D
    db 0,0,100,0,73,110,16,1,42,2,73,16  ; n3816 t=224.370s dur=100ms, freq=554Hz, sample=73, buffer_id=10:49
    db 202,1,100,0,70,100,18,3,159,1,70,18  ; n3817 t=224.370s dur=100ms, freq=415Hz, sample=70, buffer_id=12:46
    db 10,0,234,0,61,120,12,0,21,1,61,2  ; n3818 t=224.829s dur=234ms, freq=277Hz, sample=61, buffer_id=02:3D
    db 0,0,100,0,77,110,16,1,186,2,77,16  ; n3819 t=224.838s dur=100ms, freq=698Hz, sample=77, buffer_id=10:4D
    db 0,0,100,0,73,110,16,3,42,2,73,16  ; n3820 t=224.838s dur=100ms, freq=554Hz, sample=73, buffer_id=10:49
    db 234,0,100,0,70,100,18,4,159,1,70,18  ; n3821 t=224.838s dur=100ms, freq=415Hz, sample=70, buffer_id=12:46
    db 0,0,100,0,77,110,16,2,186,2,77,16  ; n3822 t=225.072s dur=100ms, freq=698Hz, sample=77, buffer_id=10:4D
    db 0,0,100,0,73,110,16,6,42,2,73,16  ; n3823 t=225.072s dur=100ms, freq=554Hz, sample=73, buffer_id=10:49
    db 10,0,100,0,70,100,18,5,159,1,70,18  ; n3824 t=225.072s dur=100ms, freq=415Hz, sample=70, buffer_id=12:46
    db 107,0,234,0,56,120,12,7,208,0,56,2  ; n3825 t=225.082s dur=234ms, freq=208Hz, sample=56, buffer_id=02:38
    db 0,0,100,0,77,110,16,3,186,2,77,16  ; n3826 t=225.190s dur=100ms, freq=698Hz, sample=77, buffer_id=10:4D
    db 0,0,100,0,73,110,16,1,42,2,73,16  ; n3827 t=225.190s dur=100ms, freq=554Hz, sample=73, buffer_id=10:49
    db 88,0,100,0,70,100,18,9,159,1,70,18  ; n3828 t=225.190s dur=100ms, freq=415Hz, sample=70, buffer_id=12:46
    db 15,0,100,0,45,120,3,0,117,0,45,2  ; n3829 t=225.277s dur=100ms, freq=117Hz, sample=45, buffer_id=02:2D
    db 15,0,117,0,55,110,4,4,175,0,55,4  ; n3830 t=225.292s dur=117ms, freq=175Hz, sample=55, buffer_id=04:37
    db 0,0,100,0,77,110,16,11,186,2,77,16  ; n3831 t=225.307s dur=100ms, freq=698Hz, sample=77, buffer_id=10:4D
    db 0,0,100,0,73,110,16,12,42,2,73,16  ; n3832 t=225.307s dur=100ms, freq=554Hz, sample=73, buffer_id=10:49
    db 117,0,100,0,70,100,18,13,159,1,70,18  ; n3833 t=225.307s dur=100ms, freq=415Hz, sample=70, buffer_id=12:46
    db 0,0,100,0,77,110,16,5,186,2,77,16  ; n3834 t=225.424s dur=100ms, freq=698Hz, sample=77, buffer_id=10:4D
    db 0,0,100,0,73,110,16,2,42,2,73,16  ; n3835 t=225.424s dur=100ms, freq=554Hz, sample=73, buffer_id=10:49
    db 234,0,100,0,70,100,18,6,159,1,70,18  ; n3836 t=225.424s dur=100ms, freq=415Hz, sample=70, buffer_id=12:46
    db 88,0,100,0,55,110,4,0,208,0,55,4  ; n3837 t=225.658s dur=100ms, freq=208Hz, sample=55, buffer_id=04:37
    db 15,0,100,0,34,120,3,1,58,0,34,2  ; n3838 t=225.746s dur=100ms, freq=58Hz, sample=34, buffer_id=02:22
    db 5,0,100,0,55,110,4,2,196,0,55,4  ; n3839 t=225.760s dur=100ms, freq=196Hz, sample=55, buffer_id=04:37
    db 10,0,234,0,63,120,12,3,55,1,63,2  ; n3840 t=225.765s dur=234ms, freq=311Hz, sample=63, buffer_id=02:3F
    db 0,0,100,0,84,110,16,4,164,3,84,16  ; n3841 t=225.775s dur=100ms, freq=932Hz, sample=84, buffer_id=10:54
    db 0,0,100,0,73,110,16,5,110,2,73,16  ; n3842 t=225.775s dur=100ms, freq=622Hz, sample=73, buffer_id=10:49
    db 0,0,100,0,70,100,18,7,210,1,70,18  ; n3843 t=225.775s dur=100ms, freq=466Hz, sample=70, buffer_id=12:46
    db 122,0,100,0,77,100,18,6,16,3,77,18  ; n3844 t=225.775s dur=100ms, freq=784Hz, sample=77, buffer_id=12:4D
    db 122,0,100,0,60,110,4,9,233,0,60,4  ; n3845 t=225.897s dur=100ms, freq=233Hz, sample=60, buffer_id=04:3C
    db 15,0,234,0,58,120,12,0,233,0,58,2  ; n3846 t=226.019s dur=234ms, freq=233Hz, sample=58, buffer_id=02:3A
    db 210,0,88,11,65,110,4,11,136,1,65,4  ; n3847 t=226.034s dur=2904ms, freq=392Hz, sample=65, buffer_id=04:41
    db 0,0,100,0,84,110,16,1,164,3,84,16  ; n3848 t=226.243s dur=100ms, freq=932Hz, sample=84, buffer_id=10:54
    db 0,0,100,0,73,110,16,2,110,2,73,16  ; n3849 t=226.243s dur=100ms, freq=622Hz, sample=73, buffer_id=10:49
    db 0,0,100,0,70,100,18,3,210,1,70,18  ; n3850 t=226.243s dur=100ms, freq=466Hz, sample=70, buffer_id=12:46
    db 203,1,100,0,77,100,18,4,16,3,77,18  ; n3851 t=226.243s dur=100ms, freq=784Hz, sample=77, buffer_id=12:4D
    db 10,0,234,0,63,120,12,0,55,1,63,2  ; n3852 t=226.702s dur=234ms, freq=311Hz, sample=63, buffer_id=02:3F
    db 0,0,100,0,84,110,16,2,164,3,84,16  ; n3853 t=226.712s dur=100ms, freq=932Hz, sample=84, buffer_id=10:54
    db 0,0,100,0,73,110,16,1,110,2,73,16  ; n3854 t=226.712s dur=100ms, freq=622Hz, sample=73, buffer_id=10:49
    db 0,0,100,0,70,100,18,4,210,1,70,18  ; n3855 t=226.712s dur=100ms, freq=466Hz, sample=70, buffer_id=12:46
    db 5,0,100,0,77,100,18,3,16,3,77,18  ; n3856 t=226.712s dur=100ms, freq=784Hz, sample=77, buffer_id=12:4D
    db 44,0,100,0,46,100,22,5,117,0,46,22  ; n3857 t=226.716s dur=100ms, freq=117Hz, sample=46, buffer_id=16:2E
    db 44,0,100,0,46,100,22,6,131,0,46,22  ; n3858 t=226.760s dur=100ms, freq=131Hz, sample=46, buffer_id=16:2E
    db 44,0,100,0,51,100,22,7,156,0,51,22  ; n3859 t=226.804s dur=100ms, freq=156Hz, sample=51, buffer_id=16:33
    db 44,0,100,0,51,100,22,8,156,0,51,22  ; n3860 t=226.848s dur=100ms, freq=156Hz, sample=51, buffer_id=16:33
    db 44,0,100,0,51,100,22,9,175,0,51,22  ; n3861 t=226.892s dur=100ms, freq=175Hz, sample=51, buffer_id=16:33
    db 10,0,100,0,58,100,22,10,196,0,58,22  ; n3862 t=226.936s dur=100ms, freq=196Hz, sample=58, buffer_id=16:3A
    db 0,0,100,0,84,110,16,12,164,3,84,16  ; n3863 t=226.946s dur=100ms, freq=932Hz, sample=84, buffer_id=10:54
    db 0,0,100,0,73,110,16,13,110,2,73,16  ; n3864 t=226.946s dur=100ms, freq=622Hz, sample=73, buffer_id=10:49
    db 0,0,100,0,70,100,18,4,210,1,70,18  ; n3865 t=226.946s dur=100ms, freq=466Hz, sample=70, buffer_id=12:46 [TRUNCATE prev:ch4 @226711.6ms -> 226945.8ms]
    db 10,0,100,0,77,100,18,3,16,3,77,18  ; n3866 t=226.946s dur=100ms, freq=784Hz, sample=77, buffer_id=12:4D [TRUNCATE prev:ch3 @226711.6ms -> 226945.8ms]
    db 24,0,234,0,58,120,12,11,233,0,58,2  ; n3867 t=226.956s dur=234ms, freq=233Hz, sample=58, buffer_id=02:3A [TRUNCATE prev:ch11 @226033.5ms -> 226955.5ms]
    db 49,0,100,0,58,100,22,0,233,0,58,22  ; n3868 t=226.980s dur=100ms, freq=233Hz, sample=58, buffer_id=16:3A [TRUNCATE prev:ch0 @226701.9ms -> 226979.9ms]
    db 34,0,100,0,58,100,22,1,233,0,58,22  ; n3869 t=227.029s dur=100ms, freq=233Hz, sample=58, buffer_id=16:3A
    db 0,0,100,0,84,110,16,5,164,3,84,16  ; n3870 t=227.063s dur=100ms, freq=932Hz, sample=84, buffer_id=10:54
    db 0,0,100,0,73,110,16,2,110,2,73,16  ; n3871 t=227.063s dur=100ms, freq=622Hz, sample=73, buffer_id=10:49
    db 0,0,100,0,70,100,18,6,210,1,70,18  ; n3872 t=227.063s dur=100ms, freq=466Hz, sample=70, buffer_id=12:46
    db 10,0,100,0,77,100,18,3,16,3,77,18  ; n3873 t=227.063s dur=100ms, freq=784Hz, sample=77, buffer_id=12:4D [TRUNCATE prev:ch3 @226945.8ms -> 227062.8ms]
    db 44,0,100,0,58,100,22,10,6,1,58,22  ; n3874 t=227.073s dur=100ms, freq=262Hz, sample=58, buffer_id=16:3A [TRUNCATE prev:ch10 @226936.0ms -> 227072.6ms]
    db 34,0,100,0,58,100,22,7,55,1,58,22  ; n3875 t=227.117s dur=100ms, freq=311Hz, sample=58, buffer_id=16:3A
    db 10,0,100,0,34,120,3,8,58,0,34,2  ; n3876 t=227.151s dur=100ms, freq=58Hz, sample=34, buffer_id=02:22
    db 19,0,100,0,58,100,22,0,55,1,58,22  ; n3877 t=227.160s dur=100ms, freq=311Hz, sample=58, buffer_id=16:3A [TRUNCATE prev:ch0 @226979.9ms -> 227160.4ms]
    db 0,0,100,0,84,110,16,12,164,3,84,16  ; n3878 t=227.180s dur=100ms, freq=932Hz, sample=84, buffer_id=10:54 [TRUNCATE prev:ch12 @226945.8ms -> 227179.9ms]
    db 0,0,100,0,73,110,16,13,110,2,73,16  ; n3879 t=227.180s dur=100ms, freq=622Hz, sample=73, buffer_id=10:49 [TRUNCATE prev:ch13 @226945.8ms -> 227179.9ms]
    db 0,0,100,0,70,100,18,4,210,1,70,18  ; n3880 t=227.180s dur=100ms, freq=466Hz, sample=70, buffer_id=12:46 [TRUNCATE prev:ch4 @226945.8ms -> 227179.9ms]
    db 24,0,100,0,77,100,18,3,16,3,77,18  ; n3881 t=227.180s dur=100ms, freq=784Hz, sample=77, buffer_id=12:4D [TRUNCATE prev:ch3 @227062.8ms -> 227179.9ms]
    db 44,0,100,0,70,100,22,9,93,1,70,22  ; n3882 t=227.204s dur=100ms, freq=349Hz, sample=70, buffer_id=16:46
    db 44,0,100,0,70,100,22,11,136,1,70,22  ; n3883 t=227.248s dur=100ms, freq=392Hz, sample=70, buffer_id=16:46 [TRUNCATE prev:ch11 @226955.5ms -> 227248.2ms]
    db 5,0,100,0,70,100,22,1,210,1,70,22  ; n3884 t=227.292s dur=100ms, freq=466Hz, sample=70, buffer_id=16:46 [TRUNCATE prev:ch1 @227028.7ms -> 227292.1ms]
    db 0,0,100,0,84,110,16,5,164,3,84,16  ; n3885 t=227.297s dur=100ms, freq=932Hz, sample=84, buffer_id=10:54 [TRUNCATE prev:ch5 @227062.8ms -> 227297.0ms]
    db 0,0,100,0,73,110,16,2,110,2,73,16  ; n3886 t=227.297s dur=100ms, freq=622Hz, sample=73, buffer_id=10:49 [TRUNCATE prev:ch2 @227062.8ms -> 227297.0ms]
    db 0,0,100,0,70,100,18,6,210,1,70,18  ; n3887 t=227.297s dur=100ms, freq=466Hz, sample=70, buffer_id=12:46 [TRUNCATE prev:ch6 @227062.8ms -> 227297.0ms]
    db 44,0,100,0,77,100,18,3,16,3,77,18  ; n3888 t=227.297s dur=100ms, freq=784Hz, sample=77, buffer_id=12:4D [TRUNCATE prev:ch3 @227179.9ms -> 227297.0ms]
    db 44,0,100,0,70,100,22,9,210,1,70,22  ; n3889 t=227.341s dur=100ms, freq=466Hz, sample=70, buffer_id=16:46 [TRUNCATE prev:ch9 @227204.3ms -> 227340.9ms]
    db 44,0,100,0,70,100,22,10,11,2,70,22  ; n3890 t=227.385s dur=100ms, freq=523Hz, sample=70, buffer_id=16:46
    db 44,0,100,0,75,100,22,7,110,2,75,22  ; n3891 t=227.429s dur=100ms, freq=622Hz, sample=75, buffer_id=16:4B
    db 44,0,100,0,75,100,22,0,110,2,75,22  ; n3892 t=227.473s dur=100ms, freq=622Hz, sample=75, buffer_id=16:4B
    db 44,0,100,0,75,100,22,4,186,2,75,22  ; n3893 t=227.517s dur=100ms, freq=698Hz, sample=75, buffer_id=16:4B
    db 44,0,100,0,79,100,22,8,16,3,79,22  ; n3894 t=227.560s dur=100ms, freq=784Hz, sample=79, buffer_id=16:4F
    db 15,0,100,0,84,100,22,1,164,3,84,22  ; n3895 t=227.604s dur=100ms, freq=932Hz, sample=84, buffer_id=16:54
    db 19,0,100,0,34,120,3,2,58,0,34,2  ; n3896 t=227.619s dur=100ms, freq=58Hz, sample=34, buffer_id=02:22
    db 10,0,230,0,63,120,12,3,55,1,63,2  ; n3897 t=227.638s dur=230ms, freq=311Hz, sample=63, buffer_id=02:3F
    db 0,0,100,0,89,110,16,5,32,6,89,16  ; n3898 t=227.648s dur=100ms, freq=1568Hz, sample=89, buffer_id=10:59
    db 0,0,100,0,73,110,16,6,110,2,73,16  ; n3899 t=227.648s dur=100ms, freq=622Hz, sample=73, buffer_id=10:49
    db 0,0,100,0,92,90,17,9,73,7,92,17  ; n3900 t=227.648s dur=100ms, freq=1865Hz, sample=92, buffer_id=11:5C
    db 0,0,100,0,70,100,18,11,210,1,70,18  ; n3901 t=227.648s dur=100ms, freq=466Hz, sample=70, buffer_id=12:46
    db 5,0,100,0,77,100,18,12,16,3,77,18  ; n3902 t=227.648s dur=100ms, freq=784Hz, sample=77, buffer_id=12:4D
    db 0,0,100,0,91,100,20,13,73,7,91,20  ; n3903 t=227.653s dur=100ms, freq=1865Hz, sample=91, buffer_id=14:5B
    db 43,0,100,0,79,100,22,10,16,3,79,22  ; n3904 t=227.653s dur=100ms, freq=784Hz, sample=79, buffer_id=16:4F [TRUNCATE prev:ch10 @227384.8ms -> 227653.1ms]
    db 43,0,100,0,75,100,22,7,186,2,75,22  ; n3905 t=227.696s dur=100ms, freq=698Hz, sample=75, buffer_id=16:4B [TRUNCATE prev:ch7 @227428.7ms -> 227696.3ms]
    db 43,0,100,0,75,100,22,0,110,2,75,22  ; n3906 t=227.739s dur=100ms, freq=622Hz, sample=75, buffer_id=16:4B [TRUNCATE prev:ch0 @227472.6ms -> 227739.4ms]
    db 43,0,100,0,75,100,22,4,110,2,75,22  ; n3907 t=227.783s dur=100ms, freq=622Hz, sample=75, buffer_id=16:4B [TRUNCATE prev:ch4 @227516.5ms -> 227782.6ms]
    db 43,0,100,0,70,100,22,8,11,2,70,22  ; n3908 t=227.826s dur=100ms, freq=523Hz, sample=70, buffer_id=16:46 [TRUNCATE prev:ch8 @227560.4ms -> 227825.7ms]
    db 19,0,100,0,70,100,22,1,210,1,70,22  ; n3909 t=227.869s dur=100ms, freq=466Hz, sample=70, buffer_id=16:46 [TRUNCATE prev:ch1 @227604.3ms -> 227868.9ms]
    db 24,0,230,0,58,120,12,2,233,0,58,2  ; n3910 t=227.888s dur=230ms, freq=233Hz, sample=58, buffer_id=02:3A [TRUNCATE prev:ch2 @227619.0ms -> 227888.1ms]
    db 48,0,100,0,70,100,22,3,210,1,70,22  ; n3911 t=227.912s dur=100ms, freq=466Hz, sample=70, buffer_id=16:46 [TRUNCATE prev:ch3 @227638.5ms -> 227912.1ms]
    db 43,0,100,0,70,100,22,5,136,1,70,22  ; n3912 t=227.960s dur=100ms, freq=392Hz, sample=70, buffer_id=16:46
    db 43,0,100,0,70,100,22,6,93,1,70,22  ; n3913 t=228.003s dur=100ms, freq=349Hz, sample=70, buffer_id=16:46
    db 43,0,100,0,58,100,22,0,55,1,58,22  ; n3914 t=228.046s dur=100ms, freq=311Hz, sample=58, buffer_id=16:3A
    db 19,0,100,0,58,100,22,4,55,1,58,22  ; n3915 t=228.089s dur=100ms, freq=311Hz, sample=58, buffer_id=16:3A
    db 0,0,100,0,84,110,16,7,164,3,84,16  ; n3916 t=228.109s dur=100ms, freq=932Hz, sample=84, buffer_id=10:54
    db 0,0,100,0,73,110,16,9,110,2,73,16  ; n3917 t=228.109s dur=100ms, freq=622Hz, sample=73, buffer_id=10:49
    db 0,0,100,0,70,100,18,10,210,1,70,18  ; n3918 t=228.109s dur=100ms, freq=466Hz, sample=70, buffer_id=12:46
    db 24,0,100,0,77,100,18,11,16,3,77,18  ; n3919 t=228.109s dur=100ms, freq=784Hz, sample=77, buffer_id=12:4D
    db 43,0,100,0,58,100,22,8,6,1,58,22  ; n3920 t=228.133s dur=100ms, freq=262Hz, sample=58, buffer_id=16:3A
    db 43,0,100,0,58,100,22,1,233,0,58,22  ; n3921 t=228.176s dur=100ms, freq=233Hz, sample=58, buffer_id=16:3A
    db 48,0,100,0,58,100,22,3,233,0,58,22  ; n3922 t=228.219s dur=100ms, freq=233Hz, sample=58, buffer_id=16:3A
    db 43,0,100,0,58,100,22,5,196,0,58,22  ; n3923 t=228.267s dur=100ms, freq=196Hz, sample=58, buffer_id=16:3A
    db 43,0,100,0,51,100,22,6,175,0,51,22  ; n3924 t=228.310s dur=100ms, freq=175Hz, sample=51, buffer_id=16:33
    db 43,0,100,0,51,100,22,0,156,0,51,22  ; n3925 t=228.353s dur=100ms, freq=156Hz, sample=51, buffer_id=16:33
    db 43,0,100,0,51,100,22,2,156,0,51,22  ; n3926 t=228.396s dur=100ms, freq=156Hz, sample=51, buffer_id=16:33
    db 43,0,100,0,46,100,22,4,131,0,46,22  ; n3927 t=228.440s dur=100ms, freq=131Hz, sample=46, buffer_id=16:2E
    db 77,0,100,0,46,100,22,1,117,0,46,22  ; n3928 t=228.483s dur=100ms, freq=117Hz, sample=46, buffer_id=16:2E
    db 10,0,230,0,63,120,12,3,55,1,63,2  ; n3929 t=228.559s dur=230ms, freq=311Hz, sample=63, buffer_id=02:3F
    db 0,0,100,0,84,110,16,5,164,3,84,16  ; n3930 t=228.569s dur=100ms, freq=932Hz, sample=84, buffer_id=10:54
    db 0,0,100,0,73,110,16,7,110,2,73,16  ; n3931 t=228.569s dur=100ms, freq=622Hz, sample=73, buffer_id=10:49
    db 0,0,100,0,70,100,18,8,210,1,70,18  ; n3932 t=228.569s dur=100ms, freq=466Hz, sample=70, buffer_id=12:46
    db 230,0,100,0,77,100,18,9,16,3,77,18  ; n3933 t=228.569s dur=100ms, freq=784Hz, sample=77, buffer_id=12:4D
    db 0,0,100,0,84,110,16,0,164,3,84,16  ; n3934 t=228.799s dur=100ms, freq=932Hz, sample=84, buffer_id=10:54
    db 0,0,100,0,73,110,16,1,110,2,73,16  ; n3935 t=228.799s dur=100ms, freq=622Hz, sample=73, buffer_id=10:49
    db 0,0,100,0,70,100,18,2,210,1,70,18  ; n3936 t=228.799s dur=100ms, freq=466Hz, sample=70, buffer_id=12:46
    db 9,0,100,0,77,100,18,4,16,3,77,18  ; n3937 t=228.799s dur=100ms, freq=784Hz, sample=77, buffer_id=12:4D
    db 106,0,230,0,58,120,12,6,233,0,58,2  ; n3938 t=228.809s dur=230ms, freq=233Hz, sample=58, buffer_id=02:3A
    db 0,0,100,0,84,110,16,7,164,3,84,16  ; n3939 t=228.914s dur=100ms, freq=932Hz, sample=84, buffer_id=10:54
    db 0,0,100,0,73,110,16,5,110,2,73,16  ; n3940 t=228.914s dur=100ms, freq=622Hz, sample=73, buffer_id=10:49
    db 0,0,100,0,70,100,18,9,210,1,70,18  ; n3941 t=228.914s dur=100ms, freq=466Hz, sample=70, buffer_id=12:46
    db 86,0,100,0,77,100,18,8,16,3,77,18  ; n3942 t=228.914s dur=100ms, freq=784Hz, sample=77, buffer_id=12:4D
    db 14,0,100,0,34,120,3,3,58,0,34,2  ; n3943 t=229.001s dur=100ms, freq=58Hz, sample=34, buffer_id=02:22
    db 14,0,115,0,55,110,4,10,196,0,55,4  ; n3944 t=229.015s dur=115ms, freq=196Hz, sample=55, buffer_id=04:37
    db 0,0,100,0,84,110,16,11,164,3,84,16  ; n3945 t=229.029s dur=100ms, freq=932Hz, sample=84, buffer_id=10:54
    db 0,0,100,0,73,110,16,12,110,2,73,16  ; n3946 t=229.029s dur=100ms, freq=622Hz, sample=73, buffer_id=10:49
    db 0,0,100,0,70,100,18,13,210,1,70,18  ; n3947 t=229.029s dur=100ms, freq=466Hz, sample=70, buffer_id=12:46
    db 115,0,100,0,77,100,18,4,16,3,77,18  ; n3948 t=229.029s dur=100ms, freq=784Hz, sample=77, buffer_id=12:4D [TRUNCATE prev:ch4 @228799.2ms -> 229029.3ms]
    db 0,0,100,0,84,110,16,1,164,3,84,16  ; n3949 t=229.144s dur=100ms, freq=932Hz, sample=84, buffer_id=10:54
    db 0,0,100,0,73,110,16,0,110,2,73,16  ; n3950 t=229.144s dur=100ms, freq=622Hz, sample=73, buffer_id=10:49
    db 0,0,100,0,70,100,18,2,210,1,70,18  ; n3951 t=229.144s dur=100ms, freq=466Hz, sample=70, buffer_id=12:46 [TRUNCATE prev:ch2 @228799.2ms -> 229144.4ms]
    db 230,0,100,0,77,100,18,8,16,3,77,18  ; n3952 t=229.144s dur=100ms, freq=784Hz, sample=77, buffer_id=12:4D [TRUNCATE prev:ch8 @228914.2ms -> 229144.4ms]
    db 86,0,100,0,60,110,4,3,233,0,60,4  ; n3953 t=229.375s dur=100ms, freq=233Hz, sample=60, buffer_id=04:3C
    db 14,0,100,0,34,120,3,0,58,0,34,2  ; n3954 t=229.461s dur=100ms, freq=58Hz, sample=34, buffer_id=02:22
    db 5,0,0,11,55,110,4,1,208,0,55,4  ; n3955 t=229.475s dur=2816ms, freq=208Hz, sample=55, buffer_id=04:37
    db 0,0,83,14,67,120,7,2,159,1,67,2  ; n3956 t=229.480s dur=3667ms, freq=415Hz, sample=67, buffer_id=02:43
    db 0,0,0,1,61,120,9,4,21,1,61,2  ; n3957 t=229.480s dur=256ms, freq=277Hz, sample=61, buffer_id=02:3D
    db 10,0,230,0,61,120,12,5,21,1,61,2  ; n3958 t=229.480s dur=230ms, freq=277Hz, sample=61, buffer_id=02:3D
    db 0,0,100,0,77,110,16,6,63,3,77,16  ; n3959 t=229.490s dur=100ms, freq=831Hz, sample=77, buffer_id=10:4D
    db 0,0,100,0,73,110,16,7,42,2,73,16  ; n3960 t=229.490s dur=100ms, freq=554Hz, sample=73, buffer_id=10:49
    db 0,0,100,0,70,100,18,8,210,1,70,18  ; n3961 t=229.490s dur=100ms, freq=466Hz, sample=70, buffer_id=12:46
    db 240,0,100,0,77,100,18,9,186,2,77,18  ; n3962 t=229.490s dur=100ms, freq=698Hz, sample=77, buffer_id=12:4D
    db 221,0,230,0,56,120,12,3,208,0,56,2  ; n3963 t=229.729s dur=230ms, freq=208Hz, sample=56, buffer_id=02:38
    db 0,0,100,0,77,110,16,0,63,3,77,16  ; n3964 t=229.950s dur=100ms, freq=831Hz, sample=77, buffer_id=10:4D
    db 0,0,100,0,73,110,16,4,42,2,73,16  ; n3965 t=229.950s dur=100ms, freq=554Hz, sample=73, buffer_id=10:49
    db 0,0,100,0,70,100,18,5,210,1,70,18  ; n3966 t=229.950s dur=100ms, freq=466Hz, sample=70, buffer_id=12:46
    db 195,1,100,0,77,100,18,6,186,2,77,18  ; n3967 t=229.950s dur=100ms, freq=698Hz, sample=77, buffer_id=12:4D
    db 10,0,230,0,61,120,12,0,21,1,61,2  ; n3968 t=230.401s dur=230ms, freq=277Hz, sample=61, buffer_id=02:3D
    db 0,0,100,0,77,110,16,3,63,3,77,16  ; n3969 t=230.410s dur=100ms, freq=831Hz, sample=77, buffer_id=10:4D
    db 0,0,100,0,73,110,16,5,42,2,73,16  ; n3970 t=230.410s dur=100ms, freq=554Hz, sample=73, buffer_id=10:49
    db 0,0,100,0,70,100,18,4,210,1,70,18  ; n3971 t=230.410s dur=100ms, freq=466Hz, sample=70, buffer_id=12:46
    db 230,0,100,0,77,100,18,7,186,2,77,18  ; n3972 t=230.410s dur=100ms, freq=698Hz, sample=77, buffer_id=12:4D
    db 0,0,100,0,77,110,16,6,63,3,77,16  ; n3973 t=230.641s dur=100ms, freq=831Hz, sample=77, buffer_id=10:4D
    db 0,0,100,0,73,110,16,8,42,2,73,16  ; n3974 t=230.641s dur=100ms, freq=554Hz, sample=73, buffer_id=10:49
    db 0,0,100,0,70,100,18,9,210,1,70,18  ; n3975 t=230.641s dur=100ms, freq=466Hz, sample=70, buffer_id=12:46
    db 10,0,100,0,77,100,18,10,186,2,77,18  ; n3976 t=230.641s dur=100ms, freq=698Hz, sample=77, buffer_id=12:4D
    db 105,0,230,0,56,120,12,11,208,0,56,2  ; n3977 t=230.650s dur=230ms, freq=208Hz, sample=56, buffer_id=02:38
    db 0,0,100,0,77,110,16,4,63,3,77,16  ; n3978 t=230.756s dur=100ms, freq=831Hz, sample=77, buffer_id=10:4D
    db 0,0,100,0,73,110,16,3,42,2,73,16  ; n3979 t=230.756s dur=100ms, freq=554Hz, sample=73, buffer_id=10:49
    db 0,0,100,0,70,100,18,5,210,1,70,18  ; n3980 t=230.756s dur=100ms, freq=466Hz, sample=70, buffer_id=12:46
    db 86,0,100,0,77,100,18,12,186,2,77,18  ; n3981 t=230.756s dur=100ms, freq=698Hz, sample=77, buffer_id=12:4D
    db 29,0,100,0,45,120,3,0,117,0,45,2  ; n3982 t=230.842s dur=100ms, freq=117Hz, sample=45, buffer_id=02:2D
    db 0,0,100,0,77,110,16,7,63,3,77,16  ; n3983 t=230.871s dur=100ms, freq=831Hz, sample=77, buffer_id=10:4D
    db 0,0,100,0,73,110,16,13,42,2,73,16  ; n3984 t=230.871s dur=100ms, freq=554Hz, sample=73, buffer_id=10:49
    db 0,0,100,0,70,100,18,9,210,1,70,18  ; n3985 t=230.871s dur=100ms, freq=466Hz, sample=70, buffer_id=12:46 [TRUNCATE prev:ch9 @230640.5ms -> 230870.7ms]
    db 115,0,100,0,77,100,18,10,186,2,77,18  ; n3986 t=230.871s dur=100ms, freq=698Hz, sample=77, buffer_id=12:4D [TRUNCATE prev:ch10 @230640.5ms -> 230870.7ms]
    db 0,0,100,0,77,110,16,8,63,3,77,16  ; n3987 t=230.986s dur=100ms, freq=831Hz, sample=77, buffer_id=10:4D
    db 0,0,100,0,73,110,16,6,42,2,73,16  ; n3988 t=230.986s dur=100ms, freq=554Hz, sample=73, buffer_id=10:49
    db 0,0,100,0,70,100,18,5,210,1,70,18  ; n3989 t=230.986s dur=100ms, freq=466Hz, sample=70, buffer_id=12:46 [TRUNCATE prev:ch5 @230755.6ms -> 230985.7ms]
    db 60,1,100,0,77,100,18,12,186,2,77,18  ; n3990 t=230.986s dur=100ms, freq=698Hz, sample=77, buffer_id=12:4D [TRUNCATE prev:ch12 @230755.6ms -> 230985.7ms]
    db 19,0,100,0,34,120,3,0,58,0,34,2  ; n3991 t=231.302s dur=100ms, freq=58Hz, sample=34, buffer_id=02:22
    db 10,0,228,0,61,120,12,3,21,1,61,2  ; n3992 t=231.321s dur=228ms, freq=277Hz, sample=61, buffer_id=02:3D
    db 0,0,100,0,89,110,16,4,117,5,89,16  ; n3993 t=231.331s dur=100ms, freq=1397Hz, sample=89, buffer_id=10:59
    db 0,0,100,0,73,110,16,5,42,2,73,16  ; n3994 t=231.331s dur=100ms, freq=554Hz, sample=73, buffer_id=10:49
    db 0,0,100,0,92,90,17,6,125,6,92,17  ; n3995 t=231.331s dur=100ms, freq=1661Hz, sample=92, buffer_id=11:5C
    db 0,0,100,0,70,100,18,7,210,1,70,18  ; n3996 t=231.331s dur=100ms, freq=466Hz, sample=70, buffer_id=12:46
    db 5,0,100,0,77,100,18,8,186,2,77,18  ; n3997 t=231.331s dur=100ms, freq=698Hz, sample=77, buffer_id=12:4D
    db 233,0,100,0,91,100,20,9,125,6,91,20  ; n3998 t=231.336s dur=100ms, freq=1661Hz, sample=91, buffer_id=14:5B
    db 219,0,228,0,56,120,12,10,208,0,56,2  ; n3999 t=231.569s dur=228ms, freq=208Hz, sample=56, buffer_id=02:38
    db 0,0,100,0,77,110,16,0,63,3,77,16  ; n4000 t=231.788s dur=100ms, freq=831Hz, sample=77, buffer_id=10:4D
    db 0,0,100,0,73,110,16,3,42,2,73,16  ; n4001 t=231.788s dur=100ms, freq=554Hz, sample=73, buffer_id=10:49
    db 0,0,100,0,70,100,18,4,210,1,70,18  ; n4002 t=231.788s dur=100ms, freq=466Hz, sample=70, buffer_id=12:46
    db 191,1,100,0,77,100,18,5,186,2,77,18  ; n4003 t=231.788s dur=100ms, freq=698Hz, sample=77, buffer_id=12:4D
    db 10,0,228,0,61,120,12,0,21,1,61,2  ; n4004 t=232.235s dur=228ms, freq=277Hz, sample=61, buffer_id=02:3D
    db 0,0,100,0,77,110,16,3,63,3,77,16  ; n4005 t=232.244s dur=100ms, freq=831Hz, sample=77, buffer_id=10:4D
    db 0,0,100,0,73,110,16,4,42,2,73,16  ; n4006 t=232.244s dur=100ms, freq=554Hz, sample=73, buffer_id=10:49
    db 0,0,100,0,70,100,18,5,210,1,70,18  ; n4007 t=232.244s dur=100ms, freq=466Hz, sample=70, buffer_id=12:46
    db 228,0,100,0,77,100,18,6,186,2,77,18  ; n4008 t=232.244s dur=100ms, freq=698Hz, sample=77, buffer_id=12:4D
    db 0,0,100,0,77,110,16,7,63,3,77,16  ; n4009 t=232.472s dur=100ms, freq=831Hz, sample=77, buffer_id=10:4D
    db 0,0,100,0,73,110,16,8,42,2,73,16  ; n4010 t=232.472s dur=100ms, freq=554Hz, sample=73, buffer_id=10:49
    db 0,0,100,0,70,100,18,9,210,1,70,18  ; n4011 t=232.472s dur=100ms, freq=466Hz, sample=70, buffer_id=12:46
    db 10,0,100,0,77,100,18,10,186,2,77,18  ; n4012 t=232.472s dur=100ms, freq=698Hz, sample=77, buffer_id=12:4D
    db 105,0,228,0,56,120,12,12,208,0,56,2  ; n4013 t=232.482s dur=228ms, freq=208Hz, sample=56, buffer_id=02:38
    db 0,0,100,0,77,110,16,1,63,3,77,16  ; n4014 t=232.587s dur=100ms, freq=831Hz, sample=77, buffer_id=10:4D
    db 0,0,100,0,73,110,16,3,42,2,73,16  ; n4015 t=232.587s dur=100ms, freq=554Hz, sample=73, buffer_id=10:49
    db 0,0,100,0,70,100,18,4,210,1,70,18  ; n4016 t=232.587s dur=100ms, freq=466Hz, sample=70, buffer_id=12:46
    db 86,0,100,0,77,100,18,5,186,2,77,18  ; n4017 t=232.587s dur=100ms, freq=698Hz, sample=77, buffer_id=12:4D
    db 14,0,100,0,45,120,3,0,117,0,45,2  ; n4018 t=232.672s dur=100ms, freq=117Hz, sample=45, buffer_id=02:2D
    db 14,0,114,0,55,110,4,6,175,0,55,4  ; n4019 t=232.686s dur=114ms, freq=175Hz, sample=55, buffer_id=04:37
    db 0,0,100,0,77,110,16,11,63,3,77,16  ; n4020 t=232.701s dur=100ms, freq=831Hz, sample=77, buffer_id=10:4D
    db 0,0,100,0,73,110,16,13,42,2,73,16  ; n4021 t=232.701s dur=100ms, freq=554Hz, sample=73, buffer_id=10:49 [TRUNCATE prev:ch13 @230870.7ms -> 232700.8ms]
    db 0,0,100,0,70,100,18,9,210,1,70,18  ; n4022 t=232.701s dur=100ms, freq=466Hz, sample=70, buffer_id=12:46 [TRUNCATE prev:ch9 @232472.5ms -> 232700.8ms]
    db 114,0,100,0,77,100,18,10,186,2,77,18  ; n4023 t=232.701s dur=100ms, freq=698Hz, sample=77, buffer_id=12:4D [TRUNCATE prev:ch10 @232472.5ms -> 232700.8ms]
    db 0,0,100,0,77,110,16,8,63,3,77,16  ; n4024 t=232.815s dur=100ms, freq=831Hz, sample=77, buffer_id=10:4D
    db 0,0,100,0,73,110,16,7,42,2,73,16  ; n4025 t=232.815s dur=100ms, freq=554Hz, sample=73, buffer_id=10:49
    db 0,0,100,0,70,100,18,4,210,1,70,18  ; n4026 t=232.815s dur=100ms, freq=466Hz, sample=70, buffer_id=12:46 [TRUNCATE prev:ch4 @232586.7ms -> 232814.9ms]
    db 228,0,100,0,77,100,18,5,186,2,77,18  ; n4027 t=232.815s dur=100ms, freq=698Hz, sample=77, buffer_id=12:4D [TRUNCATE prev:ch5 @232586.7ms -> 232814.9ms]
    db 86,0,100,0,55,110,4,0,208,0,55,4  ; n4028 t=233.043s dur=100ms, freq=208Hz, sample=55, buffer_id=04:37
    db 14,0,100,0,34,120,3,1,52,0,34,2  ; n4029 t=233.129s dur=100ms, freq=52Hz, sample=34, buffer_id=02:22
    db 5,0,100,0,55,110,4,3,185,0,55,4  ; n4030 t=233.143s dur=100ms, freq=185Hz, sample=55, buffer_id=04:37
    db 0,0,117,12,66,120,7,4,114,1,66,2  ; n4031 t=233.148s dur=3189ms, freq=370Hz, sample=66, buffer_id=02:42
    db 0,0,117,12,59,120,9,5,247,0,59,2  ; n4032 t=233.148s dur=3189ms, freq=247Hz, sample=59, buffer_id=02:3B
    db 10,0,228,0,59,120,12,6,247,0,59,2  ; n4033 t=233.148s dur=228ms, freq=247Hz, sample=59, buffer_id=02:3B
    db 0,0,100,0,84,110,16,7,164,3,84,16  ; n4034 t=233.157s dur=100ms, freq=932Hz, sample=84, buffer_id=10:54
    db 0,0,100,0,73,110,16,8,110,2,73,16  ; n4035 t=233.157s dur=100ms, freq=622Hz, sample=73, buffer_id=10:49
    db 0,0,100,0,70,100,18,10,238,1,70,18  ; n4036 t=233.157s dur=100ms, freq=494Hz, sample=70, buffer_id=12:46
    db 119,0,100,0,77,100,18,9,228,2,77,18  ; n4037 t=233.157s dur=100ms, freq=740Hz, sample=77, buffer_id=12:4D
    db 119,0,100,0,55,110,4,11,175,0,55,4  ; n4038 t=233.276s dur=100ms, freq=175Hz, sample=55, buffer_id=04:37
    db 14,0,228,0,53,120,12,0,185,0,53,2  ; n4039 t=233.395s dur=228ms, freq=185Hz, sample=53, buffer_id=02:35
    db 204,0,31,11,50,110,4,2,156,0,50,4  ; n4040 t=233.410s dur=2847ms, freq=156Hz, sample=50, buffer_id=04:32
    db 0,0,100,0,84,110,16,1,164,3,84,16  ; n4041 t=233.614s dur=100ms, freq=932Hz, sample=84, buffer_id=10:54
    db 0,0,100,0,73,110,16,3,110,2,73,16  ; n4042 t=233.614s dur=100ms, freq=622Hz, sample=73, buffer_id=10:49
    db 0,0,100,0,70,100,18,6,238,1,70,18  ; n4043 t=233.614s dur=100ms, freq=494Hz, sample=70, buffer_id=12:46
    db 191,1,100,0,77,100,18,7,228,2,77,18  ; n4044 t=233.614s dur=100ms, freq=740Hz, sample=77, buffer_id=12:4D
    db 10,0,228,0,59,120,12,0,247,0,59,2  ; n4045 t=234.061s dur=228ms, freq=247Hz, sample=59, buffer_id=02:3B
    db 0,0,100,0,84,110,16,3,164,3,84,16  ; n4046 t=234.071s dur=100ms, freq=932Hz, sample=84, buffer_id=10:54
    db 0,0,100,0,73,110,16,1,110,2,73,16  ; n4047 t=234.071s dur=100ms, freq=622Hz, sample=73, buffer_id=10:49
    db 0,0,100,0,70,100,18,7,238,1,70,18  ; n4048 t=234.071s dur=100ms, freq=494Hz, sample=70, buffer_id=12:46
    db 228,0,100,0,77,100,18,6,228,2,77,18  ; n4049 t=234.071s dur=100ms, freq=740Hz, sample=77, buffer_id=12:4D
    db 0,0,100,0,84,110,16,8,164,3,84,16  ; n4050 t=234.299s dur=100ms, freq=932Hz, sample=84, buffer_id=10:54
    db 0,0,100,0,73,110,16,9,110,2,73,16  ; n4051 t=234.299s dur=100ms, freq=622Hz, sample=73, buffer_id=10:49
    db 0,0,100,0,70,100,18,11,238,1,70,18  ; n4052 t=234.299s dur=100ms, freq=494Hz, sample=70, buffer_id=12:46
    db 10,0,100,0,77,100,18,10,228,2,77,18  ; n4053 t=234.299s dur=100ms, freq=740Hz, sample=77, buffer_id=12:4D
    db 105,0,228,0,53,120,12,12,185,0,53,2  ; n4054 t=234.308s dur=228ms, freq=185Hz, sample=53, buffer_id=02:35
    db 0,0,100,0,84,110,16,1,164,3,84,16  ; n4055 t=234.413s dur=100ms, freq=932Hz, sample=84, buffer_id=10:54
    db 0,0,100,0,73,110,16,3,110,2,73,16  ; n4056 t=234.413s dur=100ms, freq=622Hz, sample=73, buffer_id=10:49
    db 0,0,100,0,70,100,18,6,238,1,70,18  ; n4057 t=234.413s dur=100ms, freq=494Hz, sample=70, buffer_id=12:46
    db 86,0,100,0,77,100,18,7,228,2,77,18  ; n4058 t=234.413s dur=100ms, freq=740Hz, sample=77, buffer_id=12:4D
    db 28,0,100,0,41,120,3,0,78,0,41,2  ; n4059 t=234.499s dur=100ms, freq=78Hz, sample=41, buffer_id=02:29
    db 0,0,100,0,84,110,16,13,164,3,84,16  ; n4060 t=234.527s dur=100ms, freq=932Hz, sample=84, buffer_id=10:54
    db 0,0,100,0,73,110,16,9,110,2,73,16  ; n4061 t=234.527s dur=100ms, freq=622Hz, sample=73, buffer_id=10:49 [TRUNCATE prev:ch9 @234298.8ms -> 234527.1ms]
    db 0,0,100,0,70,100,18,11,238,1,70,18  ; n4062 t=234.527s dur=100ms, freq=494Hz, sample=70, buffer_id=12:46 [TRUNCATE prev:ch11 @234298.8ms -> 234527.1ms]
    db 114,0,100,0,77,100,18,10,228,2,77,18  ; n4063 t=234.527s dur=100ms, freq=740Hz, sample=77, buffer_id=12:4D [TRUNCATE prev:ch10 @234298.8ms -> 234527.1ms]
    db 0,0,100,0,84,110,16,8,164,3,84,16  ; n4064 t=234.641s dur=100ms, freq=932Hz, sample=84, buffer_id=10:54 [TRUNCATE prev:ch8 @234298.8ms -> 234641.3ms]
    db 0,0,100,0,73,110,16,3,110,2,73,16  ; n4065 t=234.641s dur=100ms, freq=622Hz, sample=73, buffer_id=10:49 [TRUNCATE prev:ch3 @234413.0ms -> 234641.3ms]
    db 0,0,100,0,70,100,18,6,238,1,70,18  ; n4066 t=234.641s dur=100ms, freq=494Hz, sample=70, buffer_id=12:46 [TRUNCATE prev:ch6 @234413.0ms -> 234641.3ms]
    db 58,1,100,0,77,100,18,7,228,2,77,18  ; n4067 t=234.641s dur=100ms, freq=740Hz, sample=77, buffer_id=12:4D [TRUNCATE prev:ch7 @234413.0ms -> 234641.3ms]
    db 19,0,100,0,34,120,3,0,52,0,34,2  ; n4068 t=234.955s dur=100ms, freq=52Hz, sample=34, buffer_id=02:22
    db 10,0,227,0,59,120,12,1,247,0,59,2  ; n4069 t=234.974s dur=227ms, freq=247Hz, sample=59, buffer_id=02:3B
    db 0,0,100,0,89,110,16,3,200,5,89,16  ; n4070 t=234.984s dur=100ms, freq=1480Hz, sample=89, buffer_id=10:59
    db 0,0,100,0,73,110,16,6,110,2,73,16  ; n4071 t=234.984s dur=100ms, freq=622Hz, sample=73, buffer_id=10:49
    db 0,0,100,0,92,90,17,7,73,7,92,17  ; n4072 t=234.984s dur=100ms, freq=1865Hz, sample=92, buffer_id=11:5C
    db 0,0,100,0,70,100,18,8,238,1,70,18  ; n4073 t=234.984s dur=100ms, freq=494Hz, sample=70, buffer_id=12:46
    db 5,0,100,0,77,100,18,9,228,2,77,18  ; n4074 t=234.984s dur=100ms, freq=740Hz, sample=77, buffer_id=12:4D
    db 232,0,100,0,91,100,20,10,73,7,91,20  ; n4075 t=234.988s dur=100ms, freq=1865Hz, sample=91, buffer_id=14:5B
    db 218,0,227,0,53,120,12,11,185,0,53,2  ; n4076 t=235.220s dur=227ms, freq=185Hz, sample=53, buffer_id=02:35
    db 0,0,100,0,84,110,16,0,164,3,84,16  ; n4077 t=235.438s dur=100ms, freq=932Hz, sample=84, buffer_id=10:54
    db 0,0,100,0,73,110,16,1,110,2,73,16  ; n4078 t=235.438s dur=100ms, freq=622Hz, sample=73, buffer_id=10:49
    db 0,0,100,0,70,100,18,3,238,1,70,18  ; n4079 t=235.438s dur=100ms, freq=494Hz, sample=70, buffer_id=12:46
    db 189,1,100,0,77,100,18,6,228,2,77,18  ; n4080 t=235.438s dur=100ms, freq=740Hz, sample=77, buffer_id=12:4D
    db 10,0,227,0,59,120,12,0,247,0,59,2  ; n4081 t=235.883s dur=227ms, freq=247Hz, sample=59, buffer_id=02:3B
    db 0,0,100,0,84,110,16,1,164,3,84,16  ; n4082 t=235.892s dur=100ms, freq=932Hz, sample=84, buffer_id=10:54
    db 0,0,100,0,73,110,16,3,110,2,73,16  ; n4083 t=235.892s dur=100ms, freq=622Hz, sample=73, buffer_id=10:49
    db 0,0,100,0,70,100,18,6,238,1,70,18  ; n4084 t=235.892s dur=100ms, freq=494Hz, sample=70, buffer_id=12:46
    db 227,0,100,0,77,100,18,7,228,2,77,18  ; n4085 t=235.892s dur=100ms, freq=740Hz, sample=77, buffer_id=12:4D
    db 0,0,100,0,84,110,16,8,164,3,84,16  ; n4086 t=236.119s dur=100ms, freq=932Hz, sample=84, buffer_id=10:54
    db 0,0,100,0,73,110,16,9,110,2,73,16  ; n4087 t=236.119s dur=100ms, freq=622Hz, sample=73, buffer_id=10:49
    db 0,0,100,0,70,100,18,10,238,1,70,18  ; n4088 t=236.119s dur=100ms, freq=494Hz, sample=70, buffer_id=12:46
    db 9,0,100,0,77,100,18,11,228,2,77,18  ; n4089 t=236.119s dur=100ms, freq=740Hz, sample=77, buffer_id=12:4D
    db 104,0,227,0,53,120,12,13,185,0,53,2  ; n4090 t=236.129s dur=227ms, freq=185Hz, sample=53, buffer_id=02:35
    db 0,0,100,0,84,110,16,3,164,3,84,16  ; n4091 t=236.233s dur=100ms, freq=932Hz, sample=84, buffer_id=10:54
    db 0,0,100,0,73,110,16,1,110,2,73,16  ; n4092 t=236.233s dur=100ms, freq=622Hz, sample=73, buffer_id=10:49
    db 0,0,100,0,70,100,18,7,238,1,70,18  ; n4093 t=236.233s dur=100ms, freq=494Hz, sample=70, buffer_id=12:46
    db 85,0,100,0,77,100,18,6,228,2,77,18  ; n4094 t=236.233s dur=100ms, freq=740Hz, sample=77, buffer_id=12:4D
    db 14,0,100,0,41,120,3,0,78,0,41,2  ; n4095 t=236.318s dur=100ms, freq=78Hz, sample=41, buffer_id=02:29
    db 5,0,113,0,55,110,4,12,196,0,55,4  ; n4096 t=236.332s dur=113ms, freq=196Hz, sample=55, buffer_id=04:37
    db 0,0,198,1,71,120,7,4,210,1,71,2  ; n4097 t=236.337s dur=454ms, freq=466Hz, sample=71, buffer_id=02:47 [TRUNCATE prev:ch4 @233147.9ms -> 236336.9ms]
    db 9,0,198,1,67,120,9,5,136,1,67,2  ; n4098 t=236.337s dur=454ms, freq=392Hz, sample=67, buffer_id=02:43 [TRUNCATE prev:ch5 @233147.9ms -> 236336.9ms]
    db 0,0,100,0,84,110,16,8,164,3,84,16  ; n4099 t=236.346s dur=100ms, freq=932Hz, sample=84, buffer_id=10:54 [TRUNCATE prev:ch8 @236119.3ms -> 236346.4ms]
    db 0,0,100,0,73,110,16,9,110,2,73,16  ; n4100 t=236.346s dur=100ms, freq=622Hz, sample=73, buffer_id=10:49 [TRUNCATE prev:ch9 @236119.3ms -> 236346.4ms]
    db 0,0,100,0,70,100,18,10,238,1,70,18  ; n4101 t=236.346s dur=100ms, freq=494Hz, sample=70, buffer_id=12:46 [TRUNCATE prev:ch10 @236119.3ms -> 236346.4ms]
    db 114,0,100,0,77,100,18,11,228,2,77,18  ; n4102 t=236.346s dur=100ms, freq=740Hz, sample=77, buffer_id=12:4D [TRUNCATE prev:ch11 @236119.3ms -> 236346.4ms]
    db 0,0,100,0,84,110,16,2,164,3,84,16  ; n4103 t=236.460s dur=100ms, freq=932Hz, sample=84, buffer_id=10:54
    db 0,0,100,0,73,110,16,1,110,2,73,16  ; n4104 t=236.460s dur=100ms, freq=622Hz, sample=73, buffer_id=10:49 [TRUNCATE prev:ch1 @236232.8ms -> 236459.9ms]
    db 0,0,100,0,70,100,18,7,238,1,70,18  ; n4105 t=236.460s dur=100ms, freq=494Hz, sample=70, buffer_id=12:46 [TRUNCATE prev:ch7 @236232.8ms -> 236459.9ms]
    db 227,0,100,0,77,100,18,6,228,2,77,18  ; n4106 t=236.460s dur=100ms, freq=740Hz, sample=77, buffer_id=12:4D [TRUNCATE prev:ch6 @236232.8ms -> 236459.9ms]
    db 85,0,100,0,60,110,4,0,233,0,60,4  ; n4107 t=236.687s dur=100ms, freq=233Hz, sample=60, buffer_id=04:3C
    db 14,0,100,0,34,120,3,1,58,0,34,2  ; n4108 t=236.772s dur=100ms, freq=58Hz, sample=34, buffer_id=02:22
    db 5,0,0,11,55,110,4,2,208,0,55,4  ; n4109 t=236.786s dur=2816ms, freq=208Hz, sample=55, buffer_id=04:37
    db 0,0,153,12,79,120,7,3,63,3,79,2  ; n4110 t=236.791s dur=3225ms, freq=831Hz, sample=79, buffer_id=02:4F
    db 0,0,36,14,73,120,9,6,42,2,73,2  ; n4111 t=236.791s dur=3620ms, freq=554Hz, sample=73, buffer_id=02:49
    db 10,0,227,0,61,120,12,7,21,1,61,2  ; n4112 t=236.791s dur=227ms, freq=277Hz, sample=61, buffer_id=02:3D
    db 0,0,100,0,77,110,16,8,63,3,77,16  ; n4113 t=236.801s dur=100ms, freq=831Hz, sample=77, buffer_id=10:4D
    db 0,0,100,0,73,110,16,10,42,2,73,16  ; n4114 t=236.801s dur=100ms, freq=554Hz, sample=73, buffer_id=10:49
    db 0,0,100,0,70,100,18,9,210,1,70,18  ; n4115 t=236.801s dur=100ms, freq=466Hz, sample=70, buffer_id=12:46
    db 237,0,100,0,77,100,18,12,186,2,77,18  ; n4116 t=236.801s dur=100ms, freq=698Hz, sample=77, buffer_id=12:4D
    db 218,0,227,0,56,120,12,0,208,0,56,2  ; n4117 t=237.037s dur=227ms, freq=208Hz, sample=56, buffer_id=02:38
    db 0,0,100,0,77,110,16,1,63,3,77,16  ; n4118 t=237.255s dur=100ms, freq=831Hz, sample=77, buffer_id=10:4D
    db 0,0,100,0,73,110,16,4,42,2,73,16  ; n4119 t=237.255s dur=100ms, freq=554Hz, sample=73, buffer_id=10:49
    db 0,0,100,0,70,100,18,5,210,1,70,18  ; n4120 t=237.255s dur=100ms, freq=466Hz, sample=70, buffer_id=12:46
    db 189,1,100,0,77,100,18,7,186,2,77,18  ; n4121 t=237.255s dur=100ms, freq=698Hz, sample=77, buffer_id=12:4D
    db 10,0,227,0,61,120,12,0,21,1,61,2  ; n4122 t=237.700s dur=227ms, freq=277Hz, sample=61, buffer_id=02:3D
    db 0,0,100,0,77,110,16,4,63,3,77,16  ; n4123 t=237.709s dur=100ms, freq=831Hz, sample=77, buffer_id=10:4D
    db 0,0,100,0,73,110,16,1,42,2,73,16  ; n4124 t=237.709s dur=100ms, freq=554Hz, sample=73, buffer_id=10:49
    db 0,0,100,0,70,100,18,7,210,1,70,18  ; n4125 t=237.709s dur=100ms, freq=466Hz, sample=70, buffer_id=12:46
    db 227,0,100,0,77,100,18,5,186,2,77,18  ; n4126 t=237.709s dur=100ms, freq=698Hz, sample=77, buffer_id=12:4D
    db 0,0,100,0,77,110,16,9,63,3,77,16  ; n4127 t=237.936s dur=100ms, freq=831Hz, sample=77, buffer_id=10:4D
    db 0,0,100,0,73,110,16,8,42,2,73,16  ; n4128 t=237.936s dur=100ms, freq=554Hz, sample=73, buffer_id=10:49
    db 0,0,100,0,70,100,18,10,210,1,70,18  ; n4129 t=237.936s dur=100ms, freq=466Hz, sample=70, buffer_id=12:46
    db 9,0,100,0,77,100,18,13,186,2,77,18  ; n4130 t=237.936s dur=100ms, freq=698Hz, sample=77, buffer_id=12:4D
    db 104,0,227,0,56,120,12,11,208,0,56,2  ; n4131 t=237.946s dur=227ms, freq=208Hz, sample=56, buffer_id=02:38
    db 0,0,100,0,77,110,16,1,63,3,77,16  ; n4132 t=238.050s dur=100ms, freq=831Hz, sample=77, buffer_id=10:4D
    db 0,0,100,0,73,110,16,4,42,2,73,16  ; n4133 t=238.050s dur=100ms, freq=554Hz, sample=73, buffer_id=10:49
    db 0,0,100,0,70,100,18,5,210,1,70,18  ; n4134 t=238.050s dur=100ms, freq=466Hz, sample=70, buffer_id=12:46
    db 85,0,100,0,77,100,18,7,186,2,77,18  ; n4135 t=238.050s dur=100ms, freq=698Hz, sample=77, buffer_id=12:4D
    db 28,0,100,0,45,120,3,0,117,0,45,2  ; n4136 t=238.135s dur=100ms, freq=117Hz, sample=45, buffer_id=02:2D
    db 0,0,100,0,77,110,16,12,63,3,77,16  ; n4137 t=238.163s dur=100ms, freq=831Hz, sample=77, buffer_id=10:4D
    db 0,0,100,0,73,110,16,8,42,2,73,16  ; n4138 t=238.163s dur=100ms, freq=554Hz, sample=73, buffer_id=10:49 [TRUNCATE prev:ch8 @237936.1ms -> 238163.2ms]
    db 0,0,100,0,70,100,18,10,210,1,70,18  ; n4139 t=238.163s dur=100ms, freq=466Hz, sample=70, buffer_id=12:46 [TRUNCATE prev:ch10 @237936.1ms -> 238163.2ms]
    db 114,0,100,0,77,100,18,13,186,2,77,18  ; n4140 t=238.163s dur=100ms, freq=698Hz, sample=77, buffer_id=12:4D [TRUNCATE prev:ch13 @237936.1ms -> 238163.2ms]
    db 0,0,100,0,77,110,16,9,63,3,77,16  ; n4141 t=238.277s dur=100ms, freq=831Hz, sample=77, buffer_id=10:4D [TRUNCATE prev:ch9 @237936.1ms -> 238276.7ms]
    db 0,0,100,0,73,110,16,4,42,2,73,16  ; n4142 t=238.277s dur=100ms, freq=554Hz, sample=73, buffer_id=10:49 [TRUNCATE prev:ch4 @238049.6ms -> 238276.7ms]
    db 0,0,100,0,70,100,18,5,210,1,70,18  ; n4143 t=238.277s dur=100ms, freq=466Hz, sample=70, buffer_id=12:46 [TRUNCATE prev:ch5 @238049.6ms -> 238276.7ms]
    db 56,1,100,0,77,100,18,7,186,2,77,18  ; n4144 t=238.277s dur=100ms, freq=698Hz, sample=77, buffer_id=12:4D [TRUNCATE prev:ch7 @238049.6ms -> 238276.7ms]
    db 19,0,100,0,34,120,3,0,58,0,34,2  ; n4145 t=238.589s dur=100ms, freq=58Hz, sample=34, buffer_id=02:22
    db 10,0,225,0,61,120,12,1,21,1,61,2  ; n4146 t=238.608s dur=225ms, freq=277Hz, sample=61, buffer_id=02:3D
    db 0,0,100,0,89,110,16,4,117,5,89,16  ; n4147 t=238.617s dur=100ms, freq=1397Hz, sample=89, buffer_id=10:59
    db 0,0,100,0,73,110,16,5,42,2,73,16  ; n4148 t=238.617s dur=100ms, freq=554Hz, sample=73, buffer_id=10:49
    db 0,0,100,0,92,90,17,7,125,6,92,17  ; n4149 t=238.617s dur=100ms, freq=1661Hz, sample=92, buffer_id=11:5C
    db 0,0,100,0,70,100,18,8,210,1,70,18  ; n4150 t=238.617s dur=100ms, freq=466Hz, sample=70, buffer_id=12:46
    db 5,0,100,0,77,100,18,9,186,2,77,18  ; n4151 t=238.617s dur=100ms, freq=698Hz, sample=77, buffer_id=12:4D
    db 230,0,100,0,91,100,20,10,125,6,91,20  ; n4152 t=238.622s dur=100ms, freq=1661Hz, sample=91, buffer_id=14:5B
    db 216,0,225,0,56,120,12,12,208,0,56,2  ; n4153 t=238.852s dur=225ms, freq=208Hz, sample=56, buffer_id=02:38
    db 0,0,100,0,77,110,16,0,63,3,77,16  ; n4154 t=239.068s dur=100ms, freq=831Hz, sample=77, buffer_id=10:4D
    db 0,0,100,0,73,110,16,1,42,2,73,16  ; n4155 t=239.068s dur=100ms, freq=554Hz, sample=73, buffer_id=10:49
    db 0,0,100,0,70,100,18,4,210,1,70,18  ; n4156 t=239.068s dur=100ms, freq=466Hz, sample=70, buffer_id=12:46
    db 185,1,100,0,77,100,18,5,186,2,77,18  ; n4157 t=239.068s dur=100ms, freq=698Hz, sample=77, buffer_id=12:4D
    db 9,0,225,0,61,120,12,0,21,1,61,2  ; n4158 t=239.510s dur=225ms, freq=277Hz, sample=61, buffer_id=02:3D
    db 0,0,100,0,77,110,16,1,63,3,77,16  ; n4159 t=239.519s dur=100ms, freq=831Hz, sample=77, buffer_id=10:4D
    db 0,0,100,0,73,110,16,4,42,2,73,16  ; n4160 t=239.519s dur=100ms, freq=554Hz, sample=73, buffer_id=10:49
    db 0,0,100,0,70,100,18,5,210,1,70,18  ; n4161 t=239.519s dur=100ms, freq=466Hz, sample=70, buffer_id=12:46
    db 225,0,100,0,77,100,18,7,186,2,77,18  ; n4162 t=239.519s dur=100ms, freq=698Hz, sample=77, buffer_id=12:4D
    db 0,0,100,0,77,110,16,8,63,3,77,16  ; n4163 t=239.744s dur=100ms, freq=831Hz, sample=77, buffer_id=10:4D
    db 0,0,100,0,73,110,16,9,42,2,73,16  ; n4164 t=239.744s dur=100ms, freq=554Hz, sample=73, buffer_id=10:49
    db 0,0,100,0,70,100,18,10,210,1,70,18  ; n4165 t=239.744s dur=100ms, freq=466Hz, sample=70, buffer_id=12:46
    db 9,0,100,0,77,100,18,11,186,2,77,18  ; n4166 t=239.744s dur=100ms, freq=698Hz, sample=77, buffer_id=12:4D
    db 103,0,225,0,56,120,12,13,208,0,56,2  ; n4167 t=239.754s dur=225ms, freq=208Hz, sample=56, buffer_id=02:38
    db 0,0,100,0,77,110,16,2,63,3,77,16  ; n4168 t=239.857s dur=100ms, freq=831Hz, sample=77, buffer_id=10:4D
    db 0,0,100,0,73,110,16,1,42,2,73,16  ; n4169 t=239.857s dur=100ms, freq=554Hz, sample=73, buffer_id=10:49
    db 0,0,100,0,70,100,18,4,210,1,70,18  ; n4170 t=239.857s dur=100ms, freq=466Hz, sample=70, buffer_id=12:46
    db 84,0,100,0,77,100,18,5,186,2,77,18  ; n4171 t=239.857s dur=100ms, freq=698Hz, sample=77, buffer_id=12:4D
    db 14,0,100,0,45,120,3,0,117,0,45,2  ; n4172 t=239.942s dur=100ms, freq=117Hz, sample=45, buffer_id=02:2D
    db 14,0,112,0,55,110,4,7,175,0,55,4  ; n4173 t=239.956s dur=112ms, freq=175Hz, sample=55, buffer_id=04:37
    db 0,0,100,0,77,110,16,12,63,3,77,16  ; n4174 t=239.970s dur=100ms, freq=831Hz, sample=77, buffer_id=10:4D
    db 0,0,100,0,73,110,16,9,42,2,73,16  ; n4175 t=239.970s dur=100ms, freq=554Hz, sample=73, buffer_id=10:49 [TRUNCATE prev:ch9 @239744.4ms -> 239969.8ms]
    db 0,0,100,0,70,100,18,10,210,1,70,18  ; n4176 t=239.970s dur=100ms, freq=466Hz, sample=70, buffer_id=12:46 [TRUNCATE prev:ch10 @239744.4ms -> 239969.8ms]
    db 113,0,100,0,77,100,18,11,186,2,77,18  ; n4177 t=239.970s dur=100ms, freq=698Hz, sample=77, buffer_id=12:4D [TRUNCATE prev:ch11 @239744.4ms -> 239969.8ms]
    db 0,0,100,0,77,110,16,8,63,3,77,16  ; n4178 t=240.083s dur=100ms, freq=831Hz, sample=77, buffer_id=10:4D [TRUNCATE prev:ch8 @239744.4ms -> 240082.5ms]
    db 0,0,100,0,73,110,16,1,42,2,73,16  ; n4179 t=240.083s dur=100ms, freq=554Hz, sample=73, buffer_id=10:49 [TRUNCATE prev:ch1 @239857.1ms -> 240082.5ms]
    db 0,0,100,0,70,100,18,4,210,1,70,18  ; n4180 t=240.083s dur=100ms, freq=466Hz, sample=70, buffer_id=12:46 [TRUNCATE prev:ch4 @239857.1ms -> 240082.5ms]
    db 225,0,100,0,77,100,18,5,186,2,77,18  ; n4181 t=240.083s dur=100ms, freq=698Hz, sample=77, buffer_id=12:4D [TRUNCATE prev:ch5 @239857.1ms -> 240082.5ms]
    db 85,0,100,0,55,110,4,0,208,0,55,4  ; n4182 t=240.308s dur=100ms, freq=208Hz, sample=55, buffer_id=04:37
    db 14,0,100,0,36,120,3,1,65,0,36,2  ; n4183 t=240.392s dur=100ms, freq=65Hz, sample=36, buffer_id=02:24
    db 5,0,100,0,55,110,4,2,196,0,55,4  ; n4184 t=240.406s dur=100ms, freq=196Hz, sample=55, buffer_id=04:37
    db 0,0,107,12,84,120,7,3,164,3,84,2  ; n4185 t=240.411s dur=3179ms, freq=932Hz, sample=84, buffer_id=02:54
    db 0,0,103,8,75,120,9,4,110,2,75,2  ; n4186 t=240.411s dur=2151ms, freq=622Hz, sample=75, buffer_id=02:4B
    db 9,0,225,0,63,120,12,5,55,1,63,2  ; n4187 t=240.411s dur=225ms, freq=311Hz, sample=63, buffer_id=02:3F
    db 0,0,100,0,84,110,16,7,164,3,84,16  ; n4188 t=240.421s dur=100ms, freq=932Hz, sample=84, buffer_id=10:54
    db 0,0,100,0,73,110,16,8,110,2,73,16  ; n4189 t=240.421s dur=100ms, freq=622Hz, sample=73, buffer_id=10:49
    db 0,0,100,0,92,90,17,9,73,7,92,17  ; n4190 t=240.421s dur=100ms, freq=1865Hz, sample=92, buffer_id=11:5C
    db 0,0,100,0,70,100,18,11,210,1,70,18  ; n4191 t=240.421s dur=100ms, freq=466Hz, sample=70, buffer_id=12:46
    db 5,0,100,0,77,100,18,10,16,3,77,18  ; n4192 t=240.421s dur=100ms, freq=784Hz, sample=77, buffer_id=12:4D
    db 113,0,100,0,91,100,20,12,73,7,91,20  ; n4193 t=240.425s dur=100ms, freq=1865Hz, sample=91, buffer_id=14:5B
    db 117,0,100,0,60,110,4,13,233,0,60,4  ; n4194 t=240.538s dur=100ms, freq=233Hz, sample=60, buffer_id=04:3C
    db 14,0,225,0,58,120,12,0,233,0,58,2  ; n4195 t=240.655s dur=225ms, freq=233Hz, sample=58, buffer_id=02:3A
    db 202,0,23,11,65,110,4,6,136,1,65,4  ; n4196 t=240.669s dur=2839ms, freq=392Hz, sample=65, buffer_id=04:41
    db 0,0,100,0,89,110,16,1,32,6,89,16  ; n4197 t=240.871s dur=100ms, freq=1568Hz, sample=89, buffer_id=10:59
    db 0,0,100,0,73,110,16,2,110,2,73,16  ; n4198 t=240.871s dur=100ms, freq=622Hz, sample=73, buffer_id=10:49
    db 0,0,100,0,70,100,18,5,210,1,70,18  ; n4199 t=240.871s dur=100ms, freq=466Hz, sample=70, buffer_id=12:46
    db 185,1,100,0,77,100,18,7,16,3,77,18  ; n4200 t=240.871s dur=100ms, freq=784Hz, sample=77, buffer_id=12:4D
    db 9,0,225,0,63,120,12,0,55,1,63,2  ; n4201 t=241.313s dur=225ms, freq=311Hz, sample=63, buffer_id=02:3F
    db 0,0,100,0,84,110,16,1,164,3,84,16  ; n4202 t=241.322s dur=100ms, freq=932Hz, sample=84, buffer_id=10:54
    db 0,0,100,0,73,110,16,5,110,2,73,16  ; n4203 t=241.322s dur=100ms, freq=622Hz, sample=73, buffer_id=10:49
    db 0,0,100,0,70,100,18,2,210,1,70,18  ; n4204 t=241.322s dur=100ms, freq=466Hz, sample=70, buffer_id=12:46
    db 225,0,100,0,77,100,18,8,16,3,77,18  ; n4205 t=241.322s dur=100ms, freq=784Hz, sample=77, buffer_id=12:4D
    db 0,0,100,0,84,110,16,7,164,3,84,16  ; n4206 t=241.548s dur=100ms, freq=932Hz, sample=84, buffer_id=10:54
    db 0,0,100,0,73,110,16,9,110,2,73,16  ; n4207 t=241.548s dur=100ms, freq=622Hz, sample=73, buffer_id=10:49
    db 0,0,100,0,70,100,18,10,210,1,70,18  ; n4208 t=241.548s dur=100ms, freq=466Hz, sample=70, buffer_id=12:46
    db 9,0,100,0,77,100,18,11,16,3,77,18  ; n4209 t=241.548s dur=100ms, freq=784Hz, sample=77, buffer_id=12:4D
    db 103,0,225,0,58,120,12,12,233,0,58,2  ; n4210 t=241.557s dur=225ms, freq=233Hz, sample=58, buffer_id=02:3A
    db 0,0,100,0,84,110,16,2,164,3,84,16  ; n4211 t=241.660s dur=100ms, freq=932Hz, sample=84, buffer_id=10:54
    db 0,0,100,0,73,110,16,1,110,2,73,16  ; n4212 t=241.660s dur=100ms, freq=622Hz, sample=73, buffer_id=10:49
    db 0,0,100,0,70,100,18,5,210,1,70,18  ; n4213 t=241.660s dur=100ms, freq=466Hz, sample=70, buffer_id=12:46
    db 84,0,100,0,77,100,18,13,16,3,77,18  ; n4214 t=241.660s dur=100ms, freq=784Hz, sample=77, buffer_id=12:4D
    db 28,0,100,0,36,120,3,0,65,0,36,2  ; n4215 t=241.745s dur=100ms, freq=65Hz, sample=36, buffer_id=02:24
    db 0,0,100,0,84,110,16,8,164,3,84,16  ; n4216 t=241.773s dur=100ms, freq=932Hz, sample=84, buffer_id=10:54
    db 0,0,100,0,73,110,16,9,110,2,73,16  ; n4217 t=241.773s dur=100ms, freq=622Hz, sample=73, buffer_id=10:49 [TRUNCATE prev:ch9 @241547.5ms -> 241772.9ms]
    db 0,0,100,0,92,90,17,3,73,7,92,17  ; n4218 t=241.773s dur=100ms, freq=1865Hz, sample=92, buffer_id=11:5C [TRUNCATE prev:ch3 @240411.2ms -> 241772.9ms]
    db 0,0,100,0,70,100,18,10,210,1,70,18  ; n4219 t=241.773s dur=100ms, freq=466Hz, sample=70, buffer_id=12:46 [TRUNCATE prev:ch10 @241547.5ms -> 241772.9ms]
    db 113,0,100,0,77,100,18,11,16,3,77,18  ; n4220 t=241.773s dur=100ms, freq=784Hz, sample=77, buffer_id=12:4D [TRUNCATE prev:ch11 @241547.5ms -> 241772.9ms]
    db 0,0,100,0,84,110,16,7,164,3,84,16  ; n4221 t=241.886s dur=100ms, freq=932Hz, sample=84, buffer_id=10:54 [TRUNCATE prev:ch7 @241547.5ms -> 241885.6ms]
    db 0,0,100,0,73,110,16,1,110,2,73,16  ; n4222 t=241.886s dur=100ms, freq=622Hz, sample=73, buffer_id=10:49 [TRUNCATE prev:ch1 @241660.2ms -> 241885.6ms]
    db 0,0,100,0,70,100,18,5,210,1,70,18  ; n4223 t=241.886s dur=100ms, freq=466Hz, sample=70, buffer_id=12:46 [TRUNCATE prev:ch5 @241660.2ms -> 241885.6ms]
    db 113,0,100,0,77,100,18,13,16,3,77,18  ; n4224 t=241.886s dur=100ms, freq=784Hz, sample=77, buffer_id=12:4D [TRUNCATE prev:ch13 @241660.2ms -> 241885.6ms]
    db 113,0,100,0,92,90,17,2,73,7,92,17  ; n4225 t=241.998s dur=100ms, freq=1865Hz, sample=92, buffer_id=11:5C
    db 85,0,100,0,92,90,17,0,73,7,92,17  ; n4226 t=242.111s dur=100ms, freq=1865Hz, sample=92, buffer_id=11:5C
    db 19,0,100,0,36,120,3,1,65,0,36,2  ; n4227 t=242.196s dur=100ms, freq=65Hz, sample=36, buffer_id=02:24
    db 9,0,229,0,63,120,12,3,55,1,63,2  ; n4228 t=242.214s dur=229ms, freq=311Hz, sample=63, buffer_id=02:3F
    db 0,0,100,0,84,110,16,5,164,3,84,16  ; n4229 t=242.224s dur=100ms, freq=932Hz, sample=84, buffer_id=10:54
    db 0,0,100,0,73,110,16,7,110,2,73,16  ; n4230 t=242.224s dur=100ms, freq=622Hz, sample=73, buffer_id=10:49
    db 0,0,100,0,92,90,17,8,73,7,92,17  ; n4231 t=242.224s dur=100ms, freq=1865Hz, sample=92, buffer_id=11:5C
    db 0,0,100,0,70,100,18,9,210,1,70,18  ; n4232 t=242.224s dur=100ms, freq=466Hz, sample=70, buffer_id=12:46
    db 239,0,100,0,77,100,18,10,16,3,77,18  ; n4233 t=242.224s dur=100ms, freq=784Hz, sample=77, buffer_id=12:4D
    db 220,0,229,0,58,120,12,0,233,0,58,2  ; n4234 t=242.463s dur=229ms, freq=233Hz, sample=58, buffer_id=02:3A
    db 0,0,100,0,84,110,16,1,164,3,84,16  ; n4235 t=242.682s dur=100ms, freq=932Hz, sample=84, buffer_id=10:54
    db 0,0,100,0,73,110,16,2,110,2,73,16  ; n4236 t=242.682s dur=100ms, freq=622Hz, sample=73, buffer_id=10:49
    db 0,0,100,0,92,90,17,3,73,7,92,17  ; n4237 t=242.682s dur=100ms, freq=1865Hz, sample=92, buffer_id=11:5C
    db 0,0,100,0,70,100,18,5,210,1,70,18  ; n4238 t=242.682s dur=100ms, freq=466Hz, sample=70, buffer_id=12:46
    db 193,1,100,0,77,100,18,7,16,3,77,18  ; n4239 t=242.682s dur=100ms, freq=784Hz, sample=77, buffer_id=12:4D
    db 10,0,229,0,63,120,12,0,55,1,63,2  ; n4240 t=243.132s dur=229ms, freq=311Hz, sample=63, buffer_id=02:3F
    db 0,0,100,0,84,110,16,2,164,3,84,16  ; n4241 t=243.141s dur=100ms, freq=932Hz, sample=84, buffer_id=10:54
    db 0,0,100,0,73,110,16,1,110,2,73,16  ; n4242 t=243.141s dur=100ms, freq=622Hz, sample=73, buffer_id=10:49
    db 0,0,100,0,92,90,17,4,73,7,92,17  ; n4243 t=243.141s dur=100ms, freq=1865Hz, sample=92, buffer_id=11:5C
    db 0,0,100,0,70,100,18,3,210,1,70,18  ; n4244 t=243.141s dur=100ms, freq=466Hz, sample=70, buffer_id=12:46
    db 5,0,100,0,77,100,18,5,16,3,77,18  ; n4245 t=243.141s dur=100ms, freq=784Hz, sample=77, buffer_id=12:4D
    db 29,0,100,0,36,100,22,7,65,0,36,22  ; n4246 t=243.146s dur=100ms, freq=65Hz, sample=36, buffer_id=16:24
    db 34,0,100,0,41,100,22,8,78,0,41,22  ; n4247 t=243.175s dur=100ms, freq=78Hz, sample=41, buffer_id=16:29
    db 34,0,100,0,41,100,22,9,78,0,41,22  ; n4248 t=243.208s dur=100ms, freq=78Hz, sample=41, buffer_id=16:29
    db 33,0,100,0,41,100,22,10,87,0,41,22  ; n4249 t=243.242s dur=100ms, freq=87Hz, sample=41, buffer_id=16:29
    db 34,0,100,0,41,100,22,11,98,0,41,22  ; n4250 t=243.275s dur=100ms, freq=98Hz, sample=41, buffer_id=16:29
    db 33,0,100,0,46,100,22,12,117,0,46,22  ; n4251 t=243.309s dur=100ms, freq=117Hz, sample=46, buffer_id=16:2E
    db 29,0,100,0,46,100,22,13,117,0,46,22  ; n4252 t=243.342s dur=100ms, freq=117Hz, sample=46, buffer_id=16:2E
    db 0,0,100,0,84,110,16,2,164,3,84,16  ; n4253 t=243.371s dur=100ms, freq=932Hz, sample=84, buffer_id=10:54 [TRUNCATE prev:ch2 @243141.2ms -> 243370.6ms]
    db 0,0,100,0,73,110,16,1,110,2,73,16  ; n4254 t=243.371s dur=100ms, freq=622Hz, sample=73, buffer_id=10:49 [TRUNCATE prev:ch1 @243141.2ms -> 243370.6ms]
    db 0,0,100,0,70,100,18,3,210,1,70,18  ; n4255 t=243.371s dur=100ms, freq=466Hz, sample=70, buffer_id=12:46 [TRUNCATE prev:ch3 @243141.2ms -> 243370.6ms]
    db 5,0,100,0,77,100,18,5,16,3,77,18  ; n4256 t=243.371s dur=100ms, freq=784Hz, sample=77, buffer_id=12:4D [TRUNCATE prev:ch5 @243141.2ms -> 243370.6ms]
    db 5,0,100,0,46,100,22,6,131,0,46,22  ; n4257 t=243.375s dur=100ms, freq=131Hz, sample=46, buffer_id=16:2E [TRUNCATE prev:ch6 @240669.4ms -> 243375.4ms]
    db 24,0,229,0,58,120,11,0,233,0,58,2  ; n4258 t=243.380s dur=229ms, freq=233Hz, sample=58, buffer_id=02:3A [TRUNCATE prev:ch0 @243131.6ms -> 243380.1ms]
    db 34,0,100,0,51,100,22,4,156,0,51,22  ; n4259 t=243.404s dur=100ms, freq=156Hz, sample=51, buffer_id=16:33 [TRUNCATE prev:ch4 @243141.2ms -> 243404.0ms]
    db 33,0,100,0,51,100,22,7,156,0,51,22  ; n4260 t=243.438s dur=100ms, freq=156Hz, sample=51, buffer_id=16:33 [TRUNCATE prev:ch7 @243146.0ms -> 243437.5ms]
    db 14,0,100,0,51,100,22,8,175,0,51,22  ; n4261 t=243.471s dur=100ms, freq=175Hz, sample=51, buffer_id=16:33 [TRUNCATE prev:ch8 @243174.6ms -> 243470.9ms]
    db 0,0,100,0,84,110,16,2,164,3,84,16  ; n4262 t=243.485s dur=100ms, freq=932Hz, sample=84, buffer_id=10:54 [TRUNCATE prev:ch2 @243370.6ms -> 243485.3ms]
    db 0,0,100,0,73,110,16,1,110,2,73,16  ; n4263 t=243.485s dur=100ms, freq=622Hz, sample=73, buffer_id=10:49 [TRUNCATE prev:ch1 @243370.6ms -> 243485.3ms]
    db 0,0,100,0,70,100,18,3,210,1,70,18  ; n4264 t=243.485s dur=100ms, freq=466Hz, sample=70, buffer_id=12:46 [TRUNCATE prev:ch3 @243370.6ms -> 243485.3ms]
    db 19,0,100,0,77,100,18,5,16,3,77,18  ; n4265 t=243.485s dur=100ms, freq=784Hz, sample=77, buffer_id=12:4D [TRUNCATE prev:ch5 @243370.6ms -> 243485.3ms]
    db 34,0,100,0,58,100,22,9,196,0,58,22  ; n4266 t=243.504s dur=100ms, freq=196Hz, sample=58, buffer_id=16:3A [TRUNCATE prev:ch9 @243208.1ms -> 243504.4ms]
    db 33,0,100,0,58,100,22,10,233,0,58,22  ; n4267 t=243.538s dur=100ms, freq=233Hz, sample=58, buffer_id=16:3A [TRUNCATE prev:ch10 @243241.6ms -> 243537.9ms]
    db 0,0,100,0,36,120,3,11,65,0,36,2  ; n4268 t=243.571s dur=100ms, freq=65Hz, sample=36, buffer_id=02:24 [TRUNCATE prev:ch11 @243275.0ms -> 243571.3ms]
    db 29,0,100,0,58,100,22,12,233,0,58,22  ; n4269 t=243.571s dur=100ms, freq=233Hz, sample=58, buffer_id=16:3A [TRUNCATE prev:ch12 @243308.5ms -> 243571.3ms]
    db 5,0,100,0,92,90,17,13,73,7,92,17  ; n4270 t=243.600s dur=100ms, freq=1865Hz, sample=92, buffer_id=11:5C [TRUNCATE prev:ch13 @243341.9ms -> 243600.0ms]
    db 0,0,114,0,36,120,1,6,78,0,36,1  ; n4271 t=243.605s dur=114ms, freq=78Hz, sample=36, buffer_id=01:24 [TRUNCATE prev:ch6 @243375.4ms -> 243604.8ms]
    db 0,0,114,0,77,124,5,0,186,2,77,5  ; n4272 t=243.605s dur=114ms, freq=698Hz, sample=77, buffer_id=05:4D [TRUNCATE prev:ch0 @243380.1ms -> 243604.8ms]
    db 0,0,114,0,65,124,14,4,55,1,65,14  ; n4273 t=243.605s dur=114ms, freq=311Hz, sample=65, buffer_id=0E:41 [TRUNCATE prev:ch4 @243404.0ms -> 243604.8ms]
    db 0,0,114,0,65,124,14,7,136,1,65,14  ; n4274 t=243.605s dur=114ms, freq=392Hz, sample=65, buffer_id=0E:41 [TRUNCATE prev:ch7 @243437.5ms -> 243604.8ms]
    db 0,0,114,0,70,124,14,8,210,1,70,14  ; n4275 t=243.605s dur=114ms, freq=466Hz, sample=70, buffer_id=0E:46 [TRUNCATE prev:ch8 @243470.9ms -> 243604.8ms]
    db 29,0,100,0,58,100,22,9,6,1,58,22  ; n4276 t=243.605s dur=100ms, freq=262Hz, sample=58, buffer_id=16:3A [TRUNCATE prev:ch9 @243504.4ms -> 243604.8ms]
    db 34,0,100,0,58,100,22,1,55,1,58,22  ; n4277 t=243.633s dur=100ms, freq=311Hz, sample=58, buffer_id=16:3A [TRUNCATE prev:ch1 @243485.3ms -> 243633.4ms]
    db 33,0,100,0,58,100,22,10,55,1,58,22  ; n4278 t=243.667s dur=100ms, freq=311Hz, sample=58, buffer_id=16:3A [TRUNCATE prev:ch10 @243537.9ms -> 243666.9ms]
    db 34,0,100,0,70,100,22,2,93,1,70,22  ; n4279 t=243.700s dur=100ms, freq=349Hz, sample=70, buffer_id=16:46 [TRUNCATE prev:ch2 @243485.3ms -> 243700.3ms]
    db 33,0,100,0,70,100,22,3,136,1,70,22  ; n4280 t=243.734s dur=100ms, freq=392Hz, sample=70, buffer_id=16:46 [TRUNCATE prev:ch3 @243485.3ms -> 243733.8ms]
    db 34,0,100,0,70,100,22,5,210,1,70,22  ; n4281 t=243.767s dur=100ms, freq=466Hz, sample=70, buffer_id=16:46 [TRUNCATE prev:ch5 @243485.3ms -> 243767.2ms]
    db 34,0,100,0,70,100,22,2,210,1,70,22  ; n4282 t=243.801s dur=100ms, freq=466Hz, sample=70, buffer_id=16:46 [TRUNCATE prev:ch2 @243700.3ms -> 243800.7ms]
    db 29,0,100,0,70,100,22,3,11,2,70,22  ; n4283 t=243.834s dur=100ms, freq=523Hz, sample=70, buffer_id=16:46 [TRUNCATE prev:ch3 @243733.8ms -> 243834.2ms]
    db 34,0,100,0,75,100,22,11,110,2,75,22  ; n4284 t=243.863s dur=100ms, freq=622Hz, sample=75, buffer_id=16:4B [TRUNCATE prev:ch11 @243571.3ms -> 243862.8ms]
    db 33,0,100,0,75,100,22,12,110,2,75,22  ; n4285 t=243.896s dur=100ms, freq=622Hz, sample=75, buffer_id=16:4B
    db 34,0,100,0,75,100,22,0,186,2,75,22  ; n4286 t=243.930s dur=100ms, freq=698Hz, sample=75, buffer_id=16:4B
    db 0,0,100,0,77,124,5,1,16,3,77,5  ; n4287 t=243.963s dur=100ms, freq=784Hz, sample=77, buffer_id=05:4D
    db 33,0,100,0,79,100,22,4,16,3,79,22  ; n4288 t=243.963s dur=100ms, freq=784Hz, sample=79, buffer_id=16:4F
    db 34,0,100,0,84,100,22,6,164,3,84,22  ; n4289 t=243.997s dur=100ms, freq=932Hz, sample=84, buffer_id=16:54
    db 0,0,168,0,34,120,2,7,58,0,34,2  ; n4290 t=244.030s dur=168ms, freq=58Hz, sample=34, buffer_id=02:22
    db 14,0,100,0,84,100,22,8,164,3,84,22  ; n4291 t=244.030s dur=100ms, freq=932Hz, sample=84, buffer_id=16:54
    db 0,0,100,0,60,110,4,9,21,1,60,4  ; n4292 t=244.044s dur=100ms, freq=277Hz, sample=60, buffer_id=04:3C
    db 19,0,100,0,70,110,4,10,159,1,70,4  ; n4293 t=244.044s dur=100ms, freq=415Hz, sample=70, buffer_id=04:46
    db 0,0,111,0,36,120,1,13,58,0,36,1  ; n4294 t=244.064s dur=111ms, freq=58Hz, sample=36, buffer_id=01:24
    db 0,0,100,0,81,124,5,5,63,3,81,5  ; n4295 t=244.064s dur=100ms, freq=831Hz, sample=81, buffer_id=05:51 [TRUNCATE prev:ch5 @243767.2ms -> 244063.5ms]
    db 0,0,100,0,77,124,5,1,186,2,77,5  ; n4296 t=244.064s dur=100ms, freq=698Hz, sample=77, buffer_id=05:4D [TRUNCATE prev:ch1 @243963.2ms -> 244063.5ms]
    db 0,0,100,0,72,124,5,2,11,2,72,5  ; n4297 t=244.064s dur=100ms, freq=523Hz, sample=72, buffer_id=05:48 [TRUNCATE prev:ch2 @243800.7ms -> 244063.5ms]
    db 0,0,100,0,70,124,14,3,159,1,70,14  ; n4298 t=244.064s dur=100ms, freq=415Hz, sample=70, buffer_id=0E:46 [TRUNCATE prev:ch3 @243834.2ms -> 244063.5ms]
    db 0,0,100,0,65,124,14,11,93,1,65,14  ; n4299 t=244.064s dur=100ms, freq=349Hz, sample=65, buffer_id=0E:41 [TRUNCATE prev:ch11 @243862.8ms -> 244063.5ms]
    db 241,0,100,0,60,124,14,12,6,1,60,14  ; n4300 t=244.064s dur=100ms, freq=262Hz, sample=60, buffer_id=0E:3C [TRUNCATE prev:ch12 @243896.3ms -> 244063.5ms]
    db 0,0,100,0,72,124,5,0,42,2,72,5  ; n4301 t=244.305s dur=100ms, freq=554Hz, sample=72, buffer_id=05:48
    db 102,0,100,0,60,124,14,4,21,1,60,14  ; n4302 t=244.305s dur=100ms, freq=277Hz, sample=60, buffer_id=0E:3C
    db 0,0,100,0,72,124,5,1,11,2,72,5  ; n4303 t=244.407s dur=100ms, freq=523Hz, sample=72, buffer_id=05:48
    db 70,0,100,0,60,124,14,2,6,1,60,14  ; n4304 t=244.407s dur=100ms, freq=262Hz, sample=60, buffer_id=0E:3C
    db 32,0,167,0,41,120,2,3,78,0,41,2  ; n4305 t=244.477s dur=167ms, freq=78Hz, sample=41, buffer_id=02:29
    db 0,0,100,0,72,124,5,5,42,2,72,5  ; n4306 t=244.509s dur=100ms, freq=554Hz, sample=72, buffer_id=05:48
    db 204,0,100,0,60,124,14,6,21,1,60,14  ; n4307 t=244.509s dur=100ms, freq=277Hz, sample=60, buffer_id=0E:3C
    db 0,0,100,0,60,110,4,0,21,1,60,4  ; n4308 t=244.713s dur=100ms, freq=277Hz, sample=60, buffer_id=04:3C
    db 19,0,100,0,70,110,4,1,159,1,70,4  ; n4309 t=244.713s dur=100ms, freq=415Hz, sample=70, buffer_id=04:46
    db 0,0,100,0,81,124,5,2,63,3,81,5  ; n4310 t=244.732s dur=100ms, freq=831Hz, sample=81, buffer_id=05:51
    db 0,0,100,0,77,124,5,4,186,2,77,5  ; n4311 t=244.732s dur=100ms, freq=698Hz, sample=77, buffer_id=05:4D
    db 0,0,100,0,72,124,5,7,11,2,72,5  ; n4312 t=244.732s dur=100ms, freq=523Hz, sample=72, buffer_id=05:48
    db 0,0,100,0,70,124,14,8,159,1,70,14  ; n4313 t=244.732s dur=100ms, freq=415Hz, sample=70, buffer_id=0E:46
    db 0,0,100,0,65,124,14,9,93,1,65,14  ; n4314 t=244.732s dur=100ms, freq=349Hz, sample=65, buffer_id=0E:41
    db 190,0,100,0,60,124,14,10,6,1,60,14  ; n4315 t=244.732s dur=100ms, freq=262Hz, sample=60, buffer_id=0E:3C
    db 51,0,167,0,41,120,2,5,78,0,41,2  ; n4316 t=244.922s dur=167ms, freq=78Hz, sample=41, buffer_id=02:29
    db 0,0,100,0,72,124,5,3,42,2,72,5  ; n4317 t=244.973s dur=100ms, freq=554Hz, sample=72, buffer_id=05:48
    db 102,0,100,0,60,124,14,11,21,1,60,14  ; n4318 t=244.973s dur=100ms, freq=277Hz, sample=60, buffer_id=0E:3C
    db 0,0,100,0,72,124,5,0,11,2,72,5  ; n4319 t=245.075s dur=100ms, freq=523Hz, sample=72, buffer_id=05:48
    db 102,0,100,0,60,124,14,1,6,1,60,14  ; n4320 t=245.075s dur=100ms, freq=262Hz, sample=60, buffer_id=0E:3C
    db 0,0,100,0,72,124,5,2,42,2,72,5  ; n4321 t=245.178s dur=100ms, freq=554Hz, sample=72, buffer_id=05:48
    db 190,0,100,0,60,124,14,4,21,1,60,14  ; n4322 t=245.178s dur=100ms, freq=277Hz, sample=60, buffer_id=0E:3C
    db 14,0,167,0,41,120,2,3,78,0,41,2  ; n4323 t=245.368s dur=167ms, freq=78Hz, sample=41, buffer_id=02:29
    db 0,0,100,0,60,110,4,0,21,1,60,4  ; n4324 t=245.382s dur=100ms, freq=277Hz, sample=60, buffer_id=04:3C
    db 19,0,100,0,70,110,4,1,159,1,70,4  ; n4325 t=245.382s dur=100ms, freq=415Hz, sample=70, buffer_id=04:46
    db 0,0,111,0,36,120,1,5,78,0,36,1  ; n4326 t=245.400s dur=111ms, freq=78Hz, sample=36, buffer_id=01:24
    db 0,0,100,0,81,124,5,6,63,3,81,5  ; n4327 t=245.400s dur=100ms, freq=831Hz, sample=81, buffer_id=05:51
    db 0,0,100,0,77,124,5,7,186,2,77,5  ; n4328 t=245.400s dur=100ms, freq=698Hz, sample=77, buffer_id=05:4D
    db 0,0,100,0,72,124,5,8,11,2,72,5  ; n4329 t=245.400s dur=100ms, freq=523Hz, sample=72, buffer_id=05:48
    db 0,0,100,0,70,124,14,9,159,1,70,14  ; n4330 t=245.400s dur=100ms, freq=415Hz, sample=70, buffer_id=0E:46
    db 0,0,100,0,65,124,14,10,93,1,65,14  ; n4331 t=245.400s dur=100ms, freq=349Hz, sample=65, buffer_id=0E:41
    db 223,0,100,0,60,124,14,13,6,1,60,14  ; n4332 t=245.400s dur=100ms, freq=262Hz, sample=60, buffer_id=0E:3C
    db 0,0,100,0,60,110,4,2,247,0,60,4  ; n4333 t=245.623s dur=100ms, freq=247Hz, sample=60, buffer_id=04:3C
    db 19,0,100,0,65,110,4,4,114,1,65,4  ; n4334 t=245.623s dur=100ms, freq=370Hz, sample=65, buffer_id=04:41
    db 0,0,100,0,77,124,5,11,228,2,77,5  ; n4335 t=245.642s dur=100ms, freq=740Hz, sample=77, buffer_id=05:4D
    db 0,0,100,0,77,124,5,12,110,2,77,5  ; n4336 t=245.642s dur=100ms, freq=622Hz, sample=77, buffer_id=05:4D
    db 0,0,100,0,72,124,5,8,210,1,72,5  ; n4337 t=245.642s dur=100ms, freq=466Hz, sample=72, buffer_id=05:48 [TRUNCATE prev:ch8 @245400.2ms -> 245641.6ms]
    db 0,0,100,0,65,124,14,10,114,1,65,14  ; n4338 t=245.642s dur=100ms, freq=370Hz, sample=65, buffer_id=0E:41 [TRUNCATE prev:ch10 @245400.2ms -> 245641.6ms]
    db 0,0,100,0,65,124,14,3,55,1,65,14  ; n4339 t=245.642s dur=100ms, freq=311Hz, sample=65, buffer_id=0E:41 [TRUNCATE prev:ch3 @245367.8ms -> 245641.6ms]
    db 83,0,100,0,60,124,14,13,233,0,60,14  ; n4340 t=245.642s dur=100ms, freq=233Hz, sample=60, buffer_id=0E:3C [TRUNCATE prev:ch13 @245400.2ms -> 245641.6ms]
    db 0,0,100,0,60,110,4,1,233,0,60,4  ; n4341 t=245.725s dur=100ms, freq=233Hz, sample=60, buffer_id=04:3C
    db 19,0,100,0,65,110,4,0,93,1,65,4  ; n4342 t=245.725s dur=100ms, freq=349Hz, sample=65, buffer_id=04:41
    db 0,0,100,0,77,124,5,5,186,2,77,5  ; n4343 t=245.744s dur=100ms, freq=698Hz, sample=77, buffer_id=05:4D
    db 0,0,100,0,72,124,5,6,75,2,72,5  ; n4344 t=245.744s dur=100ms, freq=587Hz, sample=72, buffer_id=05:48
    db 0,0,100,0,67,124,5,7,184,1,67,5  ; n4345 t=245.744s dur=100ms, freq=440Hz, sample=67, buffer_id=05:43
    db 0,0,100,0,65,124,14,9,93,1,65,14  ; n4346 t=245.744s dur=100ms, freq=349Hz, sample=65, buffer_id=0E:41
    db 0,0,100,0,60,124,14,13,38,1,60,14  ; n4347 t=245.744s dur=100ms, freq=294Hz, sample=60, buffer_id=0E:3C [TRUNCATE prev:ch13 @245641.6ms -> 245743.7ms]
    db 70,0,100,0,55,124,14,2,220,0,55,14  ; n4348 t=245.744s dur=100ms, freq=220Hz, sample=55, buffer_id=0E:37 [TRUNCATE prev:ch2 @245623.0ms -> 245743.7ms]
    db 14,0,167,0,41,120,2,4,78,0,41,2  ; n4349 t=245.813s dur=167ms, freq=78Hz, sample=41, buffer_id=02:29 [TRUNCATE prev:ch4 @245623.0ms -> 245813.3ms]
    db 0,0,201,4,60,110,4,1,247,0,60,4  ; n4350 t=245.827s dur=1225ms, freq=247Hz, sample=60, buffer_id=04:3C [TRUNCATE prev:ch1 @245725.1ms -> 245827.2ms]
    db 19,0,201,4,65,110,4,0,114,1,65,4  ; n4351 t=245.827s dur=1225ms, freq=370Hz, sample=65, buffer_id=04:41 [TRUNCATE prev:ch0 @245725.1ms -> 245827.2ms]
    db 0,0,89,4,36,120,1,3,78,0,36,1  ; n4352 t=245.846s dur=1113ms, freq=78Hz, sample=36, buffer_id=01:24 [TRUNCATE prev:ch3 @245641.6ms -> 245845.8ms]
    db 0,0,201,4,77,124,5,11,228,2,77,5  ; n4353 t=245.846s dur=1225ms, freq=740Hz, sample=77, buffer_id=05:4D [TRUNCATE prev:ch11 @245641.6ms -> 245845.8ms]
    db 0,0,201,4,77,124,5,12,110,2,77,5  ; n4354 t=245.846s dur=1225ms, freq=622Hz, sample=77, buffer_id=05:4D [TRUNCATE prev:ch12 @245641.6ms -> 245845.8ms]
    db 0,0,201,4,72,124,5,8,210,1,72,5  ; n4355 t=245.846s dur=1225ms, freq=466Hz, sample=72, buffer_id=05:48 [TRUNCATE prev:ch8 @245641.6ms -> 245845.8ms]
    db 0,0,201,4,65,124,14,10,114,1,65,14  ; n4356 t=245.846s dur=1225ms, freq=370Hz, sample=65, buffer_id=0E:41 [TRUNCATE prev:ch10 @245641.6ms -> 245845.8ms]
    db 0,0,201,4,65,124,14,9,55,1,65,14  ; n4357 t=245.846s dur=1225ms, freq=311Hz, sample=65, buffer_id=0E:41 [TRUNCATE prev:ch9 @245743.7ms -> 245845.8ms]
    db 157,1,201,4,60,124,14,13,233,0,60,14  ; n4358 t=245.846s dur=1225ms, freq=233Hz, sample=60, buffer_id=0E:3C [TRUNCATE prev:ch13 @245743.7ms -> 245845.8ms]
    db 19,0,167,0,41,120,2,2,78,0,41,2  ; n4359 t=246.259s dur=167ms, freq=78Hz, sample=41, buffer_id=02:29
    db 9,0,100,0,75,120,7,4,110,2,75,2  ; n4360 t=246.278s dur=100ms, freq=622Hz, sample=75, buffer_id=02:4B
    db 0,0,100,0,73,110,16,5,110,2,73,16  ; n4361 t=246.287s dur=100ms, freq=622Hz, sample=73, buffer_id=10:49
    db 0,0,100,0,85,90,17,6,221,4,85,17  ; n4362 t=246.287s dur=100ms, freq=1245Hz, sample=85, buffer_id=11:55
    db 70,0,100,0,65,100,18,7,55,1,65,18  ; n4363 t=246.287s dur=100ms, freq=311Hz, sample=65, buffer_id=12:41
    db 9,0,100,0,75,120,7,0,186,2,75,2  ; n4364 t=246.356s dur=100ms, freq=698Hz, sample=75, buffer_id=02:4B [TRUNCATE prev:ch0 @245827.2ms -> 246356.4ms]
    db 0,0,100,0,77,110,16,1,186,2,77,16  ; n4365 t=246.366s dur=100ms, freq=698Hz, sample=77, buffer_id=10:4D [TRUNCATE prev:ch1 @245827.2ms -> 246365.6ms]
    db 0,0,100,0,92,90,17,3,117,5,92,17  ; n4366 t=246.366s dur=100ms, freq=1397Hz, sample=92, buffer_id=11:5C [TRUNCATE prev:ch3 @245845.8ms -> 246365.6ms]
    db 70,0,100,0,65,100,18,8,93,1,65,18  ; n4367 t=246.366s dur=100ms, freq=349Hz, sample=65, buffer_id=12:41 [TRUNCATE prev:ch8 @245845.8ms -> 246365.6ms]
    db 9,0,100,0,79,120,7,9,228,2,79,2  ; n4368 t=246.435s dur=100ms, freq=740Hz, sample=79, buffer_id=02:4F [TRUNCATE prev:ch9 @245845.8ms -> 246435.3ms]
    db 0,0,100,0,77,110,16,10,228,2,77,16  ; n4369 t=246.445s dur=100ms, freq=740Hz, sample=77, buffer_id=10:4D [TRUNCATE prev:ch10 @245845.8ms -> 246444.5ms]
    db 0,0,100,0,92,90,17,11,200,5,92,17  ; n4370 t=246.445s dur=100ms, freq=1480Hz, sample=92, buffer_id=11:5C [TRUNCATE prev:ch11 @245845.8ms -> 246444.5ms]
    db 74,0,100,0,65,100,18,7,114,1,65,18  ; n4371 t=246.445s dur=100ms, freq=370Hz, sample=65, buffer_id=12:41 [TRUNCATE prev:ch7 @246286.7ms -> 246444.5ms]
    db 9,0,100,0,79,120,7,12,63,3,79,2  ; n4372 t=246.519s dur=100ms, freq=831Hz, sample=79, buffer_id=02:4F [TRUNCATE prev:ch12 @245845.8ms -> 246518.8ms]
    db 0,0,100,0,77,110,16,1,63,3,77,16  ; n4373 t=246.528s dur=100ms, freq=831Hz, sample=77, buffer_id=10:4D [TRUNCATE prev:ch1 @246365.6ms -> 246528.1ms]
    db 0,0,100,0,92,90,17,3,125,6,92,17  ; n4374 t=246.528s dur=100ms, freq=1661Hz, sample=92, buffer_id=11:5C [TRUNCATE prev:ch3 @246365.6ms -> 246528.1ms]
    db 70,0,100,0,70,100,18,13,159,1,70,18  ; n4375 t=246.528s dur=100ms, freq=415Hz, sample=70, buffer_id=12:46 [TRUNCATE prev:ch13 @245845.8ms -> 246528.1ms]
    db 9,0,100,0,84,120,7,4,164,3,84,2  ; n4376 t=246.598s dur=100ms, freq=932Hz, sample=84, buffer_id=02:54
    db 0,0,100,0,84,110,16,5,164,3,84,16  ; n4377 t=246.607s dur=100ms, freq=932Hz, sample=84, buffer_id=10:54
    db 0,0,100,0,92,90,17,6,73,7,92,17  ; n4378 t=246.607s dur=100ms, freq=1865Hz, sample=92, buffer_id=11:5C
    db 74,0,100,0,70,100,18,2,210,1,70,18  ; n4379 t=246.607s dur=100ms, freq=466Hz, sample=70, buffer_id=12:46 [TRUNCATE prev:ch2 @246258.9ms -> 246607.0ms]
    db 9,0,100,0,84,120,7,0,220,3,84,2  ; n4380 t=246.681s dur=100ms, freq=988Hz, sample=84, buffer_id=02:54
    db 0,0,100,0,84,110,16,8,220,3,84,16  ; n4381 t=246.690s dur=100ms, freq=988Hz, sample=84, buffer_id=10:54
    db 0,0,100,0,96,90,17,9,184,7,96,17  ; n4382 t=246.690s dur=100ms, freq=1976Hz, sample=96, buffer_id=11:60 [TRUNCATE prev:ch9 @246435.3ms -> 246690.5ms]
    db 14,0,100,0,70,100,18,13,238,1,70,18  ; n4383 t=246.690s dur=100ms, freq=494Hz, sample=70, buffer_id=12:46 [TRUNCATE prev:ch13 @246528.1ms -> 246690.5ms]
    db 56,0,167,0,41,120,2,7,78,0,41,2  ; n4384 t=246.704s dur=167ms, freq=78Hz, sample=41, buffer_id=02:29 [TRUNCATE prev:ch7 @246444.5ms -> 246704.5ms]
    db 9,0,100,0,84,120,7,10,85,4,84,2  ; n4385 t=246.760s dur=100ms, freq=1109Hz, sample=84, buffer_id=02:54
    db 0,0,100,0,84,110,16,11,85,4,84,16  ; n4386 t=246.769s dur=100ms, freq=1109Hz, sample=84, buffer_id=10:54
    db 0,0,100,0,96,90,17,12,169,8,96,17  ; n4387 t=246.769s dur=100ms, freq=2217Hz, sample=96, buffer_id=11:60 [TRUNCATE prev:ch12 @246518.8ms -> 246769.4ms]
    db 74,0,100,0,70,100,18,2,42,2,70,18  ; n4388 t=246.769s dur=100ms, freq=554Hz, sample=70, buffer_id=12:46 [TRUNCATE prev:ch2 @246607.0ms -> 246769.4ms]
    db 9,0,100,0,86,120,7,1,221,4,86,2  ; n4389 t=246.844s dur=100ms, freq=1245Hz, sample=86, buffer_id=02:56
    db 0,0,100,0,89,110,16,3,221,4,89,16  ; n4390 t=246.853s dur=100ms, freq=1245Hz, sample=89, buffer_id=10:59
    db 0,0,100,0,101,90,17,4,185,9,101,17  ; n4391 t=246.853s dur=100ms, freq=2489Hz, sample=101, buffer_id=11:65 [TRUNCATE prev:ch4 @246597.7ms -> 246853.0ms]
    db 70,0,100,0,77,100,18,5,110,2,77,18  ; n4392 t=246.853s dur=100ms, freq=622Hz, sample=77, buffer_id=12:4D [TRUNCATE prev:ch5 @246607.0ms -> 246853.0ms]
    db 9,0,100,0,91,120,7,6,117,5,91,2  ; n4393 t=246.923s dur=100ms, freq=1397Hz, sample=91, buffer_id=02:5B
    db 0,0,100,0,89,110,16,0,117,5,89,16  ; n4394 t=246.932s dur=100ms, freq=1397Hz, sample=89, buffer_id=10:59 [TRUNCATE prev:ch0 @246681.3ms -> 246931.9ms]
    db 0,0,100,0,101,90,17,8,234,10,101,17  ; n4395 t=246.932s dur=100ms, freq=2794Hz, sample=101, buffer_id=11:65 [TRUNCATE prev:ch8 @246690.5ms -> 246931.9ms]
    db 74,0,100,0,77,100,18,9,186,2,77,18  ; n4396 t=246.932s dur=100ms, freq=698Hz, sample=77, buffer_id=12:4D [TRUNCATE prev:ch9 @246690.5ms -> 246931.9ms]
    db 9,0,100,0,91,120,7,13,200,5,91,2  ; n4397 t=247.006s dur=100ms, freq=1480Hz, sample=91, buffer_id=02:5B
    db 0,0,100,0,89,110,16,3,200,5,89,16  ; n4398 t=247.015s dur=100ms, freq=1480Hz, sample=89, buffer_id=10:59 [TRUNCATE prev:ch3 @246853.0ms -> 247015.4ms]
    db 0,0,100,0,101,90,17,4,144,11,101,17  ; n4399 t=247.015s dur=100ms, freq=2960Hz, sample=101, buffer_id=11:65 [TRUNCATE prev:ch4 @246853.0ms -> 247015.4ms]
    db 70,0,100,0,77,100,18,5,228,2,77,18  ; n4400 t=247.015s dur=100ms, freq=740Hz, sample=77, buffer_id=12:4D [TRUNCATE prev:ch5 @246853.0ms -> 247015.4ms]
    db 9,0,100,0,91,120,7,2,125,6,91,2  ; n4401 t=247.085s dur=100ms, freq=1661Hz, sample=91, buffer_id=02:5B
    db 0,0,100,0,94,110,16,7,125,6,94,16  ; n4402 t=247.094s dur=100ms, freq=1661Hz, sample=94, buffer_id=10:5E
    db 0,0,100,0,106,90,17,10,250,12,106,17  ; n4403 t=247.094s dur=100ms, freq=3322Hz, sample=106, buffer_id=11:6A
    db 56,0,100,0,81,100,18,11,63,3,81,18  ; n4404 t=247.094s dur=100ms, freq=831Hz, sample=81, buffer_id=12:51
    db 19,0,167,0,41,120,2,1,78,0,41,2  ; n4405 t=247.150s dur=167ms, freq=78Hz, sample=41, buffer_id=02:29
    db 9,0,100,0,91,120,7,12,73,7,91,2  ; n4406 t=247.169s dur=100ms, freq=1865Hz, sample=91, buffer_id=02:5B
    db 0,0,100,0,94,110,16,6,73,7,94,16  ; n4407 t=247.178s dur=100ms, freq=1865Hz, sample=94, buffer_id=10:5E [TRUNCATE prev:ch6 @246922.6ms -> 247177.9ms]
    db 0,0,100,0,106,90,17,0,145,14,106,17  ; n4408 t=247.178s dur=100ms, freq=3729Hz, sample=106, buffer_id=11:6A [TRUNCATE prev:ch0 @246931.9ms -> 247177.9ms]
    db 5,0,100,0,81,100,18,8,164,3,81,18  ; n4409 t=247.178s dur=100ms, freq=932Hz, sample=81, buffer_id=12:51 [TRUNCATE prev:ch8 @246931.9ms -> 247177.9ms]
    db 241,0,111,0,36,120,1,9,78,0,36,1  ; n4410 t=247.183s dur=111ms, freq=78Hz, sample=36, buffer_id=01:24 [TRUNCATE prev:ch9 @246931.9ms -> 247182.5ms]
    db 0,0,100,0,77,124,5,2,110,2,77,5  ; n4411 t=247.424s dur=100ms, freq=622Hz, sample=77, buffer_id=05:4D
    db 102,0,100,0,65,124,14,3,55,1,65,14  ; n4412 t=247.424s dur=100ms, freq=311Hz, sample=65, buffer_id=0E:41
    db 0,0,100,0,77,124,5,0,110,2,77,5  ; n4413 t=247.526s dur=100ms, freq=622Hz, sample=77, buffer_id=05:4D
    db 70,0,100,0,65,124,14,1,55,1,65,14  ; n4414 t=247.526s dur=100ms, freq=311Hz, sample=65, buffer_id=0E:41
    db 14,0,167,0,34,120,2,4,58,0,34,2  ; n4415 t=247.596s dur=167ms, freq=58Hz, sample=34, buffer_id=02:22
    db 0,0,100,0,60,110,4,5,21,1,60,4  ; n4416 t=247.609s dur=100ms, freq=277Hz, sample=60, buffer_id=04:3C
    db 19,0,100,0,70,110,4,6,159,1,70,4  ; n4417 t=247.609s dur=100ms, freq=415Hz, sample=70, buffer_id=04:46
    db 0,0,111,0,36,120,1,7,58,0,36,1  ; n4418 t=247.628s dur=111ms, freq=58Hz, sample=36, buffer_id=01:24
    db 0,0,100,0,81,124,5,8,63,3,81,5  ; n4419 t=247.628s dur=100ms, freq=831Hz, sample=81, buffer_id=05:51
    db 0,0,100,0,77,124,5,9,186,2,77,5  ; n4420 t=247.628s dur=100ms, freq=698Hz, sample=77, buffer_id=05:4D
    db 0,0,100,0,72,124,5,10,11,2,72,5  ; n4421 t=247.628s dur=100ms, freq=523Hz, sample=72, buffer_id=05:48
    db 0,0,100,0,70,124,14,11,159,1,70,14  ; n4422 t=247.628s dur=100ms, freq=415Hz, sample=70, buffer_id=0E:46
    db 0,0,100,0,65,124,14,12,93,1,65,14  ; n4423 t=247.628s dur=100ms, freq=349Hz, sample=65, buffer_id=0E:41
    db 241,0,100,0,60,124,14,13,6,1,60,14  ; n4424 t=247.628s dur=100ms, freq=262Hz, sample=60, buffer_id=0E:3C
    db 0,0,100,0,72,124,5,0,42,2,72,5  ; n4425 t=247.869s dur=100ms, freq=554Hz, sample=72, buffer_id=05:48
    db 102,0,100,0,60,124,14,1,21,1,60,14  ; n4426 t=247.869s dur=100ms, freq=277Hz, sample=60, buffer_id=0E:3C
    db 0,0,100,0,72,124,5,2,11,2,72,5  ; n4427 t=247.971s dur=100ms, freq=523Hz, sample=72, buffer_id=05:48
    db 70,0,100,0,60,124,14,3,6,1,60,14  ; n4428 t=247.971s dur=100ms, freq=262Hz, sample=60, buffer_id=0E:3C
    db 32,0,167,0,41,120,2,4,78,0,41,2  ; n4429 t=248.041s dur=167ms, freq=78Hz, sample=41, buffer_id=02:29
    db 0,0,100,0,72,124,5,5,42,2,72,5  ; n4430 t=248.074s dur=100ms, freq=554Hz, sample=72, buffer_id=05:48
    db 204,0,100,0,60,124,14,6,21,1,60,14  ; n4431 t=248.074s dur=100ms, freq=277Hz, sample=60, buffer_id=0E:3C
    db 0,0,100,0,60,110,4,0,21,1,60,4  ; n4432 t=248.278s dur=100ms, freq=277Hz, sample=60, buffer_id=04:3C
    db 19,0,100,0,70,110,4,1,159,1,70,4  ; n4433 t=248.278s dur=100ms, freq=415Hz, sample=70, buffer_id=04:46
    db 0,0,100,0,81,124,5,2,63,3,81,5  ; n4434 t=248.296s dur=100ms, freq=831Hz, sample=81, buffer_id=05:51
    db 0,0,100,0,77,124,5,3,186,2,77,5  ; n4435 t=248.296s dur=100ms, freq=698Hz, sample=77, buffer_id=05:4D
    db 0,0,100,0,72,124,5,7,11,2,72,5  ; n4436 t=248.296s dur=100ms, freq=523Hz, sample=72, buffer_id=05:48
    db 0,0,100,0,70,124,14,8,159,1,70,14  ; n4437 t=248.296s dur=100ms, freq=415Hz, sample=70, buffer_id=0E:46
    db 0,0,100,0,65,124,14,9,93,1,65,14  ; n4438 t=248.296s dur=100ms, freq=349Hz, sample=65, buffer_id=0E:41
    db 190,0,100,0,60,124,14,10,6,1,60,14  ; n4439 t=248.296s dur=100ms, freq=262Hz, sample=60, buffer_id=0E:3C
    db 51,0,167,0,41,120,2,5,78,0,41,2  ; n4440 t=248.487s dur=167ms, freq=78Hz, sample=41, buffer_id=02:29
    db 0,0,100,0,72,124,5,4,42,2,72,5  ; n4441 t=248.538s dur=100ms, freq=554Hz, sample=72, buffer_id=05:48
    db 102,0,100,0,60,124,14,11,21,1,60,14  ; n4442 t=248.538s dur=100ms, freq=277Hz, sample=60, buffer_id=0E:3C
    db 0,0,100,0,72,124,5,0,11,2,72,5  ; n4443 t=248.640s dur=100ms, freq=523Hz, sample=72, buffer_id=05:48
    db 102,0,100,0,60,124,14,1,6,1,60,14  ; n4444 t=248.640s dur=100ms, freq=262Hz, sample=60, buffer_id=0E:3C
    db 0,0,100,0,72,124,5,2,42,2,72,5  ; n4445 t=248.742s dur=100ms, freq=554Hz, sample=72, buffer_id=05:48
    db 190,0,100,0,60,124,14,3,21,1,60,14  ; n4446 t=248.742s dur=100ms, freq=277Hz, sample=60, buffer_id=0E:3C
    db 14,0,167,0,41,120,2,4,78,0,41,2  ; n4447 t=248.932s dur=167ms, freq=78Hz, sample=41, buffer_id=02:29
    db 0,0,100,0,60,110,4,0,21,1,60,4  ; n4448 t=248.946s dur=100ms, freq=277Hz, sample=60, buffer_id=04:3C
    db 19,0,100,0,70,110,4,1,159,1,70,4  ; n4449 t=248.946s dur=100ms, freq=415Hz, sample=70, buffer_id=04:46
    db 0,0,111,0,36,120,1,5,78,0,36,1  ; n4450 t=248.965s dur=111ms, freq=78Hz, sample=36, buffer_id=01:24
    db 0,0,100,0,81,124,5,6,63,3,81,5  ; n4451 t=248.965s dur=100ms, freq=831Hz, sample=81, buffer_id=05:51
    db 0,0,100,0,77,124,5,7,186,2,77,5  ; n4452 t=248.965s dur=100ms, freq=698Hz, sample=77, buffer_id=05:4D
    db 0,0,100,0,72,124,5,8,11,2,72,5  ; n4453 t=248.965s dur=100ms, freq=523Hz, sample=72, buffer_id=05:48
    db 0,0,100,0,70,124,14,9,159,1,70,14  ; n4454 t=248.965s dur=100ms, freq=415Hz, sample=70, buffer_id=0E:46
    db 0,0,100,0,65,124,14,10,93,1,65,14  ; n4455 t=248.965s dur=100ms, freq=349Hz, sample=65, buffer_id=0E:41
    db 223,0,100,0,60,124,14,12,6,1,60,14  ; n4456 t=248.965s dur=100ms, freq=262Hz, sample=60, buffer_id=0E:3C
    db 0,0,100,0,60,110,4,2,247,0,60,4  ; n4457 t=249.188s dur=100ms, freq=247Hz, sample=60, buffer_id=04:3C
    db 18,0,100,0,65,110,4,3,114,1,65,4  ; n4458 t=249.188s dur=100ms, freq=370Hz, sample=65, buffer_id=04:41
    db 0,0,100,0,77,124,5,11,228,2,77,5  ; n4459 t=249.206s dur=100ms, freq=740Hz, sample=77, buffer_id=05:4D
    db 0,0,100,0,77,124,5,13,110,2,77,5  ; n4460 t=249.206s dur=100ms, freq=622Hz, sample=77, buffer_id=05:4D
    db 0,0,100,0,72,124,5,8,210,1,72,5  ; n4461 t=249.206s dur=100ms, freq=466Hz, sample=72, buffer_id=05:48 [TRUNCATE prev:ch8 @248964.8ms -> 249206.1ms]
    db 0,0,100,0,65,124,14,10,114,1,65,14  ; n4462 t=249.206s dur=100ms, freq=370Hz, sample=65, buffer_id=0E:41 [TRUNCATE prev:ch10 @248964.8ms -> 249206.1ms]
    db 0,0,100,0,65,124,14,4,55,1,65,14  ; n4463 t=249.206s dur=100ms, freq=311Hz, sample=65, buffer_id=0E:41 [TRUNCATE prev:ch4 @248932.3ms -> 249206.1ms]
    db 84,0,100,0,60,124,14,12,233,0,60,14  ; n4464 t=249.206s dur=100ms, freq=233Hz, sample=60, buffer_id=0E:3C [TRUNCATE prev:ch12 @248964.8ms -> 249206.1ms]
    db 0,0,100,0,60,110,4,1,233,0,60,4  ; n4465 t=249.290s dur=100ms, freq=233Hz, sample=60, buffer_id=04:3C
    db 18,0,100,0,65,110,4,0,93,1,65,4  ; n4466 t=249.290s dur=100ms, freq=349Hz, sample=65, buffer_id=04:41
    db 0,0,100,0,77,124,5,5,186,2,77,5  ; n4467 t=249.308s dur=100ms, freq=698Hz, sample=77, buffer_id=05:4D
    db 0,0,100,0,72,124,5,6,75,2,72,5  ; n4468 t=249.308s dur=100ms, freq=587Hz, sample=72, buffer_id=05:48
    db 0,0,100,0,67,124,5,7,184,1,67,5  ; n4469 t=249.308s dur=100ms, freq=440Hz, sample=67, buffer_id=05:43
    db 0,0,100,0,65,124,14,9,93,1,65,14  ; n4470 t=249.308s dur=100ms, freq=349Hz, sample=65, buffer_id=0E:41
    db 0,0,100,0,60,124,14,12,38,1,60,14  ; n4471 t=249.308s dur=100ms, freq=294Hz, sample=60, buffer_id=0E:3C [TRUNCATE prev:ch12 @249206.1ms -> 249308.2ms]
    db 70,0,100,0,55,124,14,2,220,0,55,14  ; n4472 t=249.308s dur=100ms, freq=220Hz, sample=55, buffer_id=0E:37 [TRUNCATE prev:ch2 @249187.6ms -> 249308.2ms]
    db 14,0,167,0,41,120,2,3,78,0,41,2  ; n4473 t=249.378s dur=167ms, freq=78Hz, sample=41, buffer_id=02:29 [TRUNCATE prev:ch3 @249187.6ms -> 249377.9ms]
    db 0,0,201,4,60,110,4,1,247,0,60,4  ; n4474 t=249.392s dur=1225ms, freq=247Hz, sample=60, buffer_id=04:3C [TRUNCATE prev:ch1 @249289.7ms -> 249391.8ms]
    db 19,0,201,4,65,110,4,0,114,1,65,4  ; n4475 t=249.392s dur=1225ms, freq=370Hz, sample=65, buffer_id=04:41 [TRUNCATE prev:ch0 @249289.7ms -> 249391.8ms]
    db 0,0,89,4,36,120,1,4,78,0,36,1  ; n4476 t=249.410s dur=1113ms, freq=78Hz, sample=36, buffer_id=01:24 [TRUNCATE prev:ch4 @249206.1ms -> 249410.4ms]
    db 0,0,201,4,77,124,5,11,228,2,77,5  ; n4477 t=249.410s dur=1225ms, freq=740Hz, sample=77, buffer_id=05:4D [TRUNCATE prev:ch11 @249206.1ms -> 249410.4ms]
    db 0,0,201,4,77,124,5,13,110,2,77,5  ; n4478 t=249.410s dur=1225ms, freq=622Hz, sample=77, buffer_id=05:4D [TRUNCATE prev:ch13 @249206.1ms -> 249410.4ms]
    db 0,0,201,4,72,124,5,8,210,1,72,5  ; n4479 t=249.410s dur=1225ms, freq=466Hz, sample=72, buffer_id=05:48 [TRUNCATE prev:ch8 @249206.1ms -> 249410.4ms]
    db 0,0,201,4,65,124,14,10,114,1,65,14  ; n4480 t=249.410s dur=1225ms, freq=370Hz, sample=65, buffer_id=0E:41 [TRUNCATE prev:ch10 @249206.1ms -> 249410.4ms]
    db 0,0,201,4,65,124,14,9,55,1,65,14  ; n4481 t=249.410s dur=1225ms, freq=311Hz, sample=65, buffer_id=0E:41 [TRUNCATE prev:ch9 @249308.2ms -> 249410.4ms]
    db 157,1,201,4,60,124,14,12,233,0,60,14  ; n4482 t=249.410s dur=1225ms, freq=233Hz, sample=60, buffer_id=0E:3C [TRUNCATE prev:ch12 @249308.2ms -> 249410.4ms]
    db 19,0,167,0,41,120,2,2,78,0,41,2  ; n4483 t=249.823s dur=167ms, freq=78Hz, sample=41, buffer_id=02:29
    db 9,0,100,0,75,120,7,3,110,2,75,2  ; n4484 t=249.842s dur=100ms, freq=622Hz, sample=75, buffer_id=02:4B
    db 0,0,100,0,73,110,16,5,110,2,73,16  ; n4485 t=249.851s dur=100ms, freq=622Hz, sample=73, buffer_id=10:49
    db 0,0,100,0,85,90,17,6,221,4,85,17  ; n4486 t=249.851s dur=100ms, freq=1245Hz, sample=85, buffer_id=11:55
    db 70,0,100,0,65,100,18,7,55,1,65,18  ; n4487 t=249.851s dur=100ms, freq=311Hz, sample=65, buffer_id=12:41
    db 9,0,100,0,75,120,7,0,186,2,75,2  ; n4488 t=249.921s dur=100ms, freq=698Hz, sample=75, buffer_id=02:4B [TRUNCATE prev:ch0 @249391.8ms -> 249920.9ms]
    db 0,0,100,0,77,110,16,1,186,2,77,16  ; n4489 t=249.930s dur=100ms, freq=698Hz, sample=77, buffer_id=10:4D [TRUNCATE prev:ch1 @249391.8ms -> 249930.2ms]
    db 0,0,100,0,92,90,17,4,117,5,92,17  ; n4490 t=249.930s dur=100ms, freq=1397Hz, sample=92, buffer_id=11:5C [TRUNCATE prev:ch4 @249410.4ms -> 249930.2ms]
    db 70,0,100,0,65,100,18,8,93,1,65,18  ; n4491 t=249.930s dur=100ms, freq=349Hz, sample=65, buffer_id=12:41 [TRUNCATE prev:ch8 @249410.4ms -> 249930.2ms]
    db 9,0,100,0,79,120,7,9,228,2,79,2  ; n4492 t=250.000s dur=100ms, freq=740Hz, sample=79, buffer_id=02:4F [TRUNCATE prev:ch9 @249410.4ms -> 249999.8ms]
    db 0,0,100,0,77,110,16,10,228,2,77,16  ; n4493 t=250.009s dur=100ms, freq=740Hz, sample=77, buffer_id=10:4D [TRUNCATE prev:ch10 @249410.4ms -> 250009.1ms]
    db 0,0,100,0,92,90,17,11,200,5,92,17  ; n4494 t=250.009s dur=100ms, freq=1480Hz, sample=92, buffer_id=11:5C [TRUNCATE prev:ch11 @249410.4ms -> 250009.1ms]
    db 74,0,100,0,65,100,18,7,114,1,65,18  ; n4495 t=250.009s dur=100ms, freq=370Hz, sample=65, buffer_id=12:41 [TRUNCATE prev:ch7 @249851.3ms -> 250009.1ms]
    db 9,0,100,0,79,120,7,12,63,3,79,2  ; n4496 t=250.083s dur=100ms, freq=831Hz, sample=79, buffer_id=02:4F [TRUNCATE prev:ch12 @249410.4ms -> 250083.3ms]
    db 0,0,100,0,77,110,16,1,63,3,77,16  ; n4497 t=250.093s dur=100ms, freq=831Hz, sample=77, buffer_id=10:4D [TRUNCATE prev:ch1 @249930.2ms -> 250092.6ms]
    db 0,0,100,0,92,90,17,4,125,6,92,17  ; n4498 t=250.093s dur=100ms, freq=1661Hz, sample=92, buffer_id=11:5C [TRUNCATE prev:ch4 @249930.2ms -> 250092.6ms]
    db 70,0,100,0,70,100,18,13,159,1,70,18  ; n4499 t=250.093s dur=100ms, freq=415Hz, sample=70, buffer_id=12:46 [TRUNCATE prev:ch13 @249410.4ms -> 250092.6ms]
    db 9,0,100,0,84,120,7,3,164,3,84,2  ; n4500 t=250.162s dur=100ms, freq=932Hz, sample=84, buffer_id=02:54
    db 0,0,100,0,84,110,16,5,164,3,84,16  ; n4501 t=250.172s dur=100ms, freq=932Hz, sample=84, buffer_id=10:54
    db 0,0,100,0,92,90,17,6,73,7,92,17  ; n4502 t=250.172s dur=100ms, freq=1865Hz, sample=92, buffer_id=11:5C
    db 74,0,100,0,70,100,18,2,210,1,70,18  ; n4503 t=250.172s dur=100ms, freq=466Hz, sample=70, buffer_id=12:46 [TRUNCATE prev:ch2 @249823.4ms -> 250171.5ms]
    db 9,0,100,0,84,120,7,0,220,3,84,2  ; n4504 t=250.246s dur=100ms, freq=988Hz, sample=84, buffer_id=02:54
    db 0,0,100,0,84,110,16,8,220,3,84,16  ; n4505 t=250.255s dur=100ms, freq=988Hz, sample=84, buffer_id=10:54
    db 0,0,100,0,96,90,17,9,184,7,96,17  ; n4506 t=250.255s dur=100ms, freq=1976Hz, sample=96, buffer_id=11:60 [TRUNCATE prev:ch9 @249999.8ms -> 250255.1ms]
    db 14,0,100,0,70,100,18,13,238,1,70,18  ; n4507 t=250.255s dur=100ms, freq=494Hz, sample=70, buffer_id=12:46 [TRUNCATE prev:ch13 @250092.6ms -> 250255.1ms]
    db 56,0,167,0,41,120,2,7,78,0,41,2  ; n4508 t=250.269s dur=167ms, freq=78Hz, sample=41, buffer_id=02:29 [TRUNCATE prev:ch7 @250009.1ms -> 250269.0ms]
    db 9,0,100,0,84,120,7,10,85,4,84,2  ; n4509 t=250.325s dur=100ms, freq=1109Hz, sample=84, buffer_id=02:54
    db 0,0,100,0,84,110,16,11,85,4,84,16  ; n4510 t=250.334s dur=100ms, freq=1109Hz, sample=84, buffer_id=10:54
    db 0,0,100,0,96,90,17,12,169,8,96,17  ; n4511 t=250.334s dur=100ms, freq=2217Hz, sample=96, buffer_id=11:60 [TRUNCATE prev:ch12 @250083.3ms -> 250334.0ms]
    db 74,0,100,0,70,100,18,2,42,2,70,18  ; n4512 t=250.334s dur=100ms, freq=554Hz, sample=70, buffer_id=12:46 [TRUNCATE prev:ch2 @250171.5ms -> 250334.0ms]
    db 9,0,100,0,86,120,7,1,221,4,86,2  ; n4513 t=250.408s dur=100ms, freq=1245Hz, sample=86, buffer_id=02:56
    db 0,0,100,0,89,110,16,4,221,4,89,16  ; n4514 t=250.417s dur=100ms, freq=1245Hz, sample=89, buffer_id=10:59
    db 0,0,100,0,101,90,17,3,185,9,101,17  ; n4515 t=250.417s dur=100ms, freq=2489Hz, sample=101, buffer_id=11:65 [TRUNCATE prev:ch3 @250162.2ms -> 250417.5ms]
    db 70,0,100,0,77,100,18,5,110,2,77,18  ; n4516 t=250.417s dur=100ms, freq=622Hz, sample=77, buffer_id=12:4D [TRUNCATE prev:ch5 @250171.5ms -> 250417.5ms]
    db 9,0,100,0,91,120,7,6,117,5,91,2  ; n4517 t=250.487s dur=100ms, freq=1397Hz, sample=91, buffer_id=02:5B
    db 0,0,100,0,89,110,16,0,117,5,89,16  ; n4518 t=250.496s dur=100ms, freq=1397Hz, sample=89, buffer_id=10:59 [TRUNCATE prev:ch0 @250245.8ms -> 250496.4ms]
    db 0,0,100,0,101,90,17,8,234,10,101,17  ; n4519 t=250.496s dur=100ms, freq=2794Hz, sample=101, buffer_id=11:65 [TRUNCATE prev:ch8 @250255.1ms -> 250496.4ms]
    db 74,0,100,0,77,100,18,9,186,2,77,18  ; n4520 t=250.496s dur=100ms, freq=698Hz, sample=77, buffer_id=12:4D [TRUNCATE prev:ch9 @250255.1ms -> 250496.4ms]
    db 9,0,100,0,91,120,7,13,200,5,91,2  ; n4521 t=250.571s dur=100ms, freq=1480Hz, sample=91, buffer_id=02:5B
    db 0,0,100,0,89,110,16,4,200,5,89,16  ; n4522 t=250.580s dur=100ms, freq=1480Hz, sample=89, buffer_id=10:59 [TRUNCATE prev:ch4 @250417.5ms -> 250580.0ms]
    db 0,0,100,0,101,90,17,3,144,11,101,17  ; n4523 t=250.580s dur=100ms, freq=2960Hz, sample=101, buffer_id=11:65 [TRUNCATE prev:ch3 @250417.5ms -> 250580.0ms]
    db 70,0,100,0,77,100,18,5,228,2,77,18  ; n4524 t=250.580s dur=100ms, freq=740Hz, sample=77, buffer_id=12:4D [TRUNCATE prev:ch5 @250417.5ms -> 250580.0ms]
    db 9,0,100,0,91,120,7,2,125,6,91,2  ; n4525 t=250.650s dur=100ms, freq=1661Hz, sample=91, buffer_id=02:5B
    db 0,0,100,0,94,110,16,7,125,6,94,16  ; n4526 t=250.659s dur=100ms, freq=1661Hz, sample=94, buffer_id=10:5E
    db 0,0,100,0,106,90,17,10,250,12,106,17  ; n4527 t=250.659s dur=100ms, freq=3322Hz, sample=106, buffer_id=11:6A
    db 56,0,100,0,81,100,18,11,63,3,81,18  ; n4528 t=250.659s dur=100ms, freq=831Hz, sample=81, buffer_id=12:51
    db 19,0,167,0,41,120,2,1,78,0,41,2  ; n4529 t=250.715s dur=167ms, freq=78Hz, sample=41, buffer_id=02:29
    db 9,0,100,0,91,120,7,12,73,7,91,2  ; n4530 t=250.733s dur=100ms, freq=1865Hz, sample=91, buffer_id=02:5B
    db 0,0,100,0,94,110,16,6,73,7,94,16  ; n4531 t=250.742s dur=100ms, freq=1865Hz, sample=94, buffer_id=10:5E [TRUNCATE prev:ch6 @250487.1ms -> 250742.4ms]
    db 0,0,100,0,106,90,17,0,145,14,106,17  ; n4532 t=250.742s dur=100ms, freq=3729Hz, sample=106, buffer_id=11:6A [TRUNCATE prev:ch0 @250496.4ms -> 250742.4ms]
    db 5,0,100,0,81,100,18,8,164,3,81,18  ; n4533 t=250.742s dur=100ms, freq=932Hz, sample=81, buffer_id=12:51 [TRUNCATE prev:ch8 @250496.4ms -> 250742.4ms]
    db 241,0,111,0,36,120,1,9,78,0,36,1  ; n4534 t=250.747s dur=111ms, freq=78Hz, sample=36, buffer_id=01:24 [TRUNCATE prev:ch9 @250496.4ms -> 250747.1ms]
    db 0,0,100,0,77,124,5,2,110,2,77,5  ; n4535 t=250.988s dur=100ms, freq=622Hz, sample=77, buffer_id=05:4D
    db 102,0,100,0,65,124,14,3,55,1,65,14  ; n4536 t=250.988s dur=100ms, freq=311Hz, sample=65, buffer_id=0E:41
    db 0,0,100,0,77,124,5,0,110,2,77,5  ; n4537 t=251.090s dur=100ms, freq=622Hz, sample=77, buffer_id=05:4D
    db 70,0,100,0,65,124,14,1,55,1,65,14  ; n4538 t=251.090s dur=100ms, freq=311Hz, sample=65, buffer_id=0E:41
    db 14,0,167,0,34,120,2,4,58,0,34,2  ; n4539 t=251.160s dur=167ms, freq=58Hz, sample=34, buffer_id=02:22
    db 0,0,100,0,60,110,4,5,21,1,60,4  ; n4540 t=251.174s dur=100ms, freq=277Hz, sample=60, buffer_id=04:3C
    db 18,0,100,0,70,110,4,6,159,1,70,4  ; n4541 t=251.174s dur=100ms, freq=415Hz, sample=70, buffer_id=04:46
    db 0,0,111,0,36,120,1,7,58,0,36,1  ; n4542 t=251.193s dur=111ms, freq=58Hz, sample=36, buffer_id=01:24
    db 0,0,100,0,81,124,5,8,63,3,81,5  ; n4543 t=251.193s dur=100ms, freq=831Hz, sample=81, buffer_id=05:51
    db 0,0,100,0,77,124,5,9,186,2,77,5  ; n4544 t=251.193s dur=100ms, freq=698Hz, sample=77, buffer_id=05:4D
    db 0,0,100,0,72,124,5,10,11,2,72,5  ; n4545 t=251.193s dur=100ms, freq=523Hz, sample=72, buffer_id=05:48
    db 0,0,100,0,70,124,14,11,159,1,70,14  ; n4546 t=251.193s dur=100ms, freq=415Hz, sample=70, buffer_id=0E:46
    db 0,0,100,0,65,124,14,12,93,1,65,14  ; n4547 t=251.193s dur=100ms, freq=349Hz, sample=65, buffer_id=0E:41
    db 241,0,100,0,60,124,14,13,6,1,60,14  ; n4548 t=251.193s dur=100ms, freq=262Hz, sample=60, buffer_id=0E:3C
    db 0,0,100,0,72,124,5,0,42,2,72,5  ; n4549 t=251.434s dur=100ms, freq=554Hz, sample=72, buffer_id=05:48
    db 102,0,100,0,60,124,14,1,21,1,60,14  ; n4550 t=251.434s dur=100ms, freq=277Hz, sample=60, buffer_id=0E:3C
    db 0,0,100,0,72,124,5,2,11,2,72,5  ; n4551 t=251.536s dur=100ms, freq=523Hz, sample=72, buffer_id=05:48
    db 70,0,100,0,60,124,14,3,6,1,60,14  ; n4552 t=251.536s dur=100ms, freq=262Hz, sample=60, buffer_id=0E:3C
    db 32,0,167,0,34,120,2,5,58,0,34,2  ; n4553 t=251.606s dur=167ms, freq=58Hz, sample=34, buffer_id=02:22
    db 0,0,100,0,72,124,5,4,42,2,72,5  ; n4554 t=251.638s dur=100ms, freq=554Hz, sample=72, buffer_id=05:48
    db 204,0,100,0,60,124,14,6,21,1,60,14  ; n4555 t=251.638s dur=100ms, freq=277Hz, sample=60, buffer_id=0E:3C
    db 0,0,100,0,60,110,4,0,21,1,60,4  ; n4556 t=251.842s dur=100ms, freq=277Hz, sample=60, buffer_id=04:3C
    db 19,0,100,0,70,110,4,1,159,1,70,4  ; n4557 t=251.842s dur=100ms, freq=415Hz, sample=70, buffer_id=04:46
    db 0,0,100,0,81,124,5,2,63,3,81,5  ; n4558 t=251.861s dur=100ms, freq=831Hz, sample=81, buffer_id=05:51
    db 0,0,100,0,77,124,5,3,186,2,77,5  ; n4559 t=251.861s dur=100ms, freq=698Hz, sample=77, buffer_id=05:4D
    db 0,0,100,0,72,124,5,7,11,2,72,5  ; n4560 t=251.861s dur=100ms, freq=523Hz, sample=72, buffer_id=05:48
    db 0,0,100,0,70,124,14,8,159,1,70,14  ; n4561 t=251.861s dur=100ms, freq=415Hz, sample=70, buffer_id=0E:46
    db 0,0,100,0,65,124,14,9,93,1,65,14  ; n4562 t=251.861s dur=100ms, freq=349Hz, sample=65, buffer_id=0E:41
    db 190,0,100,0,60,124,14,10,6,1,60,14  ; n4563 t=251.861s dur=100ms, freq=262Hz, sample=60, buffer_id=0E:3C
    db 51,0,167,0,34,120,2,4,58,0,34,2  ; n4564 t=252.051s dur=167ms, freq=58Hz, sample=34, buffer_id=02:22
    db 0,0,100,0,72,124,5,5,42,2,72,5  ; n4565 t=252.102s dur=100ms, freq=554Hz, sample=72, buffer_id=05:48
    db 102,0,100,0,60,124,14,11,21,1,60,14  ; n4566 t=252.102s dur=100ms, freq=277Hz, sample=60, buffer_id=0E:3C
    db 0,0,100,0,72,124,5,0,11,2,72,5  ; n4567 t=252.204s dur=100ms, freq=523Hz, sample=72, buffer_id=05:48
    db 102,0,100,0,60,124,14,1,6,1,60,14  ; n4568 t=252.204s dur=100ms, freq=262Hz, sample=60, buffer_id=0E:3C
    db 0,0,100,0,72,124,5,2,42,2,72,5  ; n4569 t=252.306s dur=100ms, freq=554Hz, sample=72, buffer_id=05:48
    db 190,0,100,0,60,124,14,3,21,1,60,14  ; n4570 t=252.306s dur=100ms, freq=277Hz, sample=60, buffer_id=0E:3C
    db 14,0,167,0,34,120,2,5,58,0,34,2  ; n4571 t=252.497s dur=167ms, freq=58Hz, sample=34, buffer_id=02:22
    db 0,0,100,0,60,110,4,0,21,1,60,4  ; n4572 t=252.511s dur=100ms, freq=277Hz, sample=60, buffer_id=04:3C
    db 19,0,100,0,70,110,4,1,159,1,70,4  ; n4573 t=252.511s dur=100ms, freq=415Hz, sample=70, buffer_id=04:46
    db 0,0,111,0,36,120,1,4,58,0,36,1  ; n4574 t=252.529s dur=111ms, freq=58Hz, sample=36, buffer_id=01:24
    db 0,0,100,0,81,124,5,6,63,3,81,5  ; n4575 t=252.529s dur=100ms, freq=831Hz, sample=81, buffer_id=05:51
    db 0,0,100,0,77,124,5,7,186,2,77,5  ; n4576 t=252.529s dur=100ms, freq=698Hz, sample=77, buffer_id=05:4D
    db 0,0,100,0,72,124,5,8,11,2,72,5  ; n4577 t=252.529s dur=100ms, freq=523Hz, sample=72, buffer_id=05:48
    db 0,0,100,0,70,124,14,9,159,1,70,14  ; n4578 t=252.529s dur=100ms, freq=415Hz, sample=70, buffer_id=0E:46
    db 0,0,100,0,65,124,14,10,93,1,65,14  ; n4579 t=252.529s dur=100ms, freq=349Hz, sample=65, buffer_id=0E:41
    db 223,0,100,0,60,124,14,12,6,1,60,14  ; n4580 t=252.529s dur=100ms, freq=262Hz, sample=60, buffer_id=0E:3C
    db 0,0,100,0,60,110,4,2,247,0,60,4  ; n4581 t=252.752s dur=100ms, freq=247Hz, sample=60, buffer_id=04:3C
    db 19,0,100,0,65,110,4,3,114,1,65,4  ; n4582 t=252.752s dur=100ms, freq=370Hz, sample=65, buffer_id=04:41
    db 0,0,100,0,77,124,5,11,228,2,77,5  ; n4583 t=252.771s dur=100ms, freq=740Hz, sample=77, buffer_id=05:4D
    db 0,0,100,0,77,124,5,13,110,2,77,5  ; n4584 t=252.771s dur=100ms, freq=622Hz, sample=77, buffer_id=05:4D
    db 0,0,100,0,72,124,5,8,210,1,72,5  ; n4585 t=252.771s dur=100ms, freq=466Hz, sample=72, buffer_id=05:48 [TRUNCATE prev:ch8 @252529.3ms -> 252770.7ms]
    db 0,0,100,0,65,124,14,10,114,1,65,14  ; n4586 t=252.771s dur=100ms, freq=370Hz, sample=65, buffer_id=0E:41 [TRUNCATE prev:ch10 @252529.3ms -> 252770.7ms]
    db 0,0,100,0,65,124,14,5,55,1,65,14  ; n4587 t=252.771s dur=100ms, freq=311Hz, sample=65, buffer_id=0E:41 [TRUNCATE prev:ch5 @252496.8ms -> 252770.7ms]
    db 83,0,100,0,60,124,14,12,233,0,60,14  ; n4588 t=252.771s dur=100ms, freq=233Hz, sample=60, buffer_id=0E:3C [TRUNCATE prev:ch12 @252529.3ms -> 252770.7ms]
    db 0,0,100,0,60,110,4,1,233,0,60,4  ; n4589 t=252.854s dur=100ms, freq=233Hz, sample=60, buffer_id=04:3C
    db 19,0,100,0,65,110,4,0,93,1,65,4  ; n4590 t=252.854s dur=100ms, freq=349Hz, sample=65, buffer_id=04:41
    db 0,0,100,0,77,124,5,4,186,2,77,5  ; n4591 t=252.873s dur=100ms, freq=698Hz, sample=77, buffer_id=05:4D
    db 0,0,100,0,72,124,5,6,75,2,72,5  ; n4592 t=252.873s dur=100ms, freq=587Hz, sample=72, buffer_id=05:48
    db 0,0,100,0,67,124,5,7,184,1,67,5  ; n4593 t=252.873s dur=100ms, freq=440Hz, sample=67, buffer_id=05:43
    db 0,0,100,0,65,124,14,9,93,1,65,14  ; n4594 t=252.873s dur=100ms, freq=349Hz, sample=65, buffer_id=0E:41
    db 0,0,100,0,60,124,14,12,38,1,60,14  ; n4595 t=252.873s dur=100ms, freq=294Hz, sample=60, buffer_id=0E:3C [TRUNCATE prev:ch12 @252770.7ms -> 252872.8ms]
    db 70,0,100,0,55,124,14,2,220,0,55,14  ; n4596 t=252.873s dur=100ms, freq=220Hz, sample=55, buffer_id=0E:37 [TRUNCATE prev:ch2 @252752.1ms -> 252872.8ms]
    db 14,0,167,0,34,120,2,3,52,0,34,2  ; n4597 t=252.942s dur=167ms, freq=52Hz, sample=34, buffer_id=02:22 [TRUNCATE prev:ch3 @252752.1ms -> 252942.4ms]
    db 0,0,100,0,60,110,4,1,247,0,60,4  ; n4598 t=252.956s dur=100ms, freq=247Hz, sample=60, buffer_id=04:3C [TRUNCATE prev:ch1 @252854.2ms -> 252956.3ms]
    db 19,0,100,0,65,110,4,0,114,1,65,4  ; n4599 t=252.956s dur=100ms, freq=370Hz, sample=65, buffer_id=04:41 [TRUNCATE prev:ch0 @252854.2ms -> 252956.3ms]
    db 0,0,111,0,31,120,1,5,52,0,31,1  ; n4600 t=252.975s dur=111ms, freq=52Hz, sample=31, buffer_id=01:1F [TRUNCATE prev:ch5 @252770.7ms -> 252974.9ms]
    db 0,0,100,0,77,124,5,11,228,2,77,5  ; n4601 t=252.975s dur=100ms, freq=740Hz, sample=77, buffer_id=05:4D [TRUNCATE prev:ch11 @252770.7ms -> 252974.9ms]
    db 0,0,100,0,77,124,5,13,110,2,77,5  ; n4602 t=252.975s dur=100ms, freq=622Hz, sample=77, buffer_id=05:4D [TRUNCATE prev:ch13 @252770.7ms -> 252974.9ms]
    db 0,0,100,0,72,124,5,8,210,1,72,5  ; n4603 t=252.975s dur=100ms, freq=466Hz, sample=72, buffer_id=05:48 [TRUNCATE prev:ch8 @252770.7ms -> 252974.9ms]
    db 0,0,100,0,65,124,14,10,114,1,65,14  ; n4604 t=252.975s dur=100ms, freq=370Hz, sample=65, buffer_id=0E:41 [TRUNCATE prev:ch10 @252770.7ms -> 252974.9ms]
    db 0,0,100,0,65,124,14,9,55,1,65,14  ; n4605 t=252.975s dur=100ms, freq=311Hz, sample=65, buffer_id=0E:41 [TRUNCATE prev:ch9 @252872.8ms -> 252974.9ms]
    db 241,0,100,0,60,124,14,12,233,0,60,14  ; n4606 t=252.975s dur=100ms, freq=233Hz, sample=60, buffer_id=0E:3C [TRUNCATE prev:ch12 @252872.8ms -> 252974.9ms]
    db 0,0,100,0,72,124,5,2,238,1,72,5  ; n4607 t=253.216s dur=100ms, freq=494Hz, sample=72, buffer_id=05:48
    db 102,0,100,0,60,124,14,4,247,0,60,14  ; n4608 t=253.216s dur=100ms, freq=247Hz, sample=60, buffer_id=0E:3C
    db 0,0,100,0,72,124,5,0,210,1,72,5  ; n4609 t=253.318s dur=100ms, freq=466Hz, sample=72, buffer_id=05:48
    db 70,0,100,0,60,124,14,1,233,0,60,14  ; n4610 t=253.318s dur=100ms, freq=233Hz, sample=60, buffer_id=0E:3C
    db 32,0,167,0,34,120,2,5,52,0,34,2  ; n4611 t=253.388s dur=167ms, freq=52Hz, sample=34, buffer_id=02:22
    db 0,0,100,0,72,124,5,3,238,1,72,5  ; n4612 t=253.421s dur=100ms, freq=494Hz, sample=72, buffer_id=05:48
    db 204,0,100,0,60,124,14,6,247,0,60,14  ; n4613 t=253.421s dur=100ms, freq=247Hz, sample=60, buffer_id=0E:3C
    db 0,0,100,0,60,110,4,0,247,0,60,4  ; n4614 t=253.625s dur=100ms, freq=247Hz, sample=60, buffer_id=04:3C
    db 19,0,100,0,65,110,4,1,114,1,65,4  ; n4615 t=253.625s dur=100ms, freq=370Hz, sample=65, buffer_id=04:41
    db 0,0,100,0,77,124,5,2,228,2,77,5  ; n4616 t=253.643s dur=100ms, freq=740Hz, sample=77, buffer_id=05:4D
    db 0,0,100,0,77,124,5,4,110,2,77,5  ; n4617 t=253.643s dur=100ms, freq=622Hz, sample=77, buffer_id=05:4D
    db 0,0,100,0,72,124,5,7,210,1,72,5  ; n4618 t=253.643s dur=100ms, freq=466Hz, sample=72, buffer_id=05:48
    db 0,0,100,0,65,124,14,8,114,1,65,14  ; n4619 t=253.643s dur=100ms, freq=370Hz, sample=65, buffer_id=0E:41
    db 0,0,100,0,65,124,14,11,55,1,65,14  ; n4620 t=253.643s dur=100ms, freq=311Hz, sample=65, buffer_id=0E:41
    db 190,0,100,0,60,124,14,9,233,0,60,14  ; n4621 t=253.643s dur=100ms, freq=233Hz, sample=60, buffer_id=0E:3C
    db 51,0,167,0,34,120,2,3,52,0,34,2  ; n4622 t=253.833s dur=167ms, freq=52Hz, sample=34, buffer_id=02:22
    db 0,0,100,0,72,124,5,5,238,1,72,5  ; n4623 t=253.885s dur=100ms, freq=494Hz, sample=72, buffer_id=05:48
    db 102,0,100,0,60,124,14,10,247,0,60,14  ; n4624 t=253.885s dur=100ms, freq=247Hz, sample=60, buffer_id=0E:3C
    db 0,0,100,0,72,124,5,0,210,1,72,5  ; n4625 t=253.987s dur=100ms, freq=466Hz, sample=72, buffer_id=05:48
    db 102,0,100,0,60,124,14,1,233,0,60,14  ; n4626 t=253.987s dur=100ms, freq=233Hz, sample=60, buffer_id=0E:3C
    db 0,0,100,0,72,124,5,2,238,1,72,5  ; n4627 t=254.089s dur=100ms, freq=494Hz, sample=72, buffer_id=05:48
    db 190,0,100,0,60,124,14,4,247,0,60,14  ; n4628 t=254.089s dur=100ms, freq=247Hz, sample=60, buffer_id=0E:3C
    db 14,0,167,0,34,120,2,5,52,0,34,2  ; n4629 t=254.279s dur=167ms, freq=52Hz, sample=34, buffer_id=02:22
    db 0,0,100,0,60,110,4,0,247,0,60,4  ; n4630 t=254.293s dur=100ms, freq=247Hz, sample=60, buffer_id=04:3C
    db 19,0,100,0,65,110,4,1,114,1,65,4  ; n4631 t=254.293s dur=100ms, freq=370Hz, sample=65, buffer_id=04:41
    db 0,0,111,0,31,120,1,3,52,0,31,1  ; n4632 t=254.312s dur=111ms, freq=52Hz, sample=31, buffer_id=01:1F
    db 0,0,100,0,77,124,5,6,228,2,77,5  ; n4633 t=254.312s dur=100ms, freq=740Hz, sample=77, buffer_id=05:4D
    db 0,0,100,0,77,124,5,7,110,2,77,5  ; n4634 t=254.312s dur=100ms, freq=622Hz, sample=77, buffer_id=05:4D
    db 0,0,100,0,72,124,5,8,210,1,72,5  ; n4635 t=254.312s dur=100ms, freq=466Hz, sample=72, buffer_id=05:48
    db 0,0,100,0,65,124,14,9,114,1,65,14  ; n4636 t=254.312s dur=100ms, freq=370Hz, sample=65, buffer_id=0E:41
    db 0,0,100,0,65,124,14,10,55,1,65,14  ; n4637 t=254.312s dur=100ms, freq=311Hz, sample=65, buffer_id=0E:41
    db 223,0,100,0,60,124,14,11,233,0,60,14  ; n4638 t=254.312s dur=100ms, freq=233Hz, sample=60, buffer_id=0E:3C
    db 0,0,100,0,60,110,4,2,247,0,60,4  ; n4639 t=254.534s dur=100ms, freq=247Hz, sample=60, buffer_id=04:3C
    db 18,0,100,0,65,110,4,4,114,1,65,4  ; n4640 t=254.534s dur=100ms, freq=370Hz, sample=65, buffer_id=04:41
    db 0,0,100,0,77,124,5,12,228,2,77,5  ; n4641 t=254.553s dur=100ms, freq=740Hz, sample=77, buffer_id=05:4D
    db 0,0,100,0,77,124,5,13,110,2,77,5  ; n4642 t=254.553s dur=100ms, freq=622Hz, sample=77, buffer_id=05:4D [TRUNCATE prev:ch13 @252974.9ms -> 254552.9ms]
    db 0,0,100,0,72,124,5,8,210,1,72,5  ; n4643 t=254.553s dur=100ms, freq=466Hz, sample=72, buffer_id=05:48 [TRUNCATE prev:ch8 @254311.6ms -> 254552.9ms]
    db 0,0,100,0,65,124,14,9,114,1,65,14  ; n4644 t=254.553s dur=100ms, freq=370Hz, sample=65, buffer_id=0E:41 [TRUNCATE prev:ch9 @254311.6ms -> 254552.9ms]
    db 0,0,100,0,65,124,14,10,55,1,65,14  ; n4645 t=254.553s dur=100ms, freq=311Hz, sample=65, buffer_id=0E:41 [TRUNCATE prev:ch10 @254311.6ms -> 254552.9ms]
    db 84,0,100,0,60,124,14,11,233,0,60,14  ; n4646 t=254.553s dur=100ms, freq=233Hz, sample=60, buffer_id=0E:3C [TRUNCATE prev:ch11 @254311.6ms -> 254552.9ms]
    db 0,0,100,0,60,110,4,1,21,1,60,4  ; n4647 t=254.637s dur=100ms, freq=277Hz, sample=60, buffer_id=04:3C
    db 18,0,100,0,70,110,4,0,159,1,70,4  ; n4648 t=254.637s dur=100ms, freq=415Hz, sample=70, buffer_id=04:46
    db 0,0,100,0,81,124,5,3,63,3,81,5  ; n4649 t=254.655s dur=100ms, freq=831Hz, sample=81, buffer_id=05:51
    db 0,0,100,0,77,124,5,5,186,2,77,5  ; n4650 t=254.655s dur=100ms, freq=698Hz, sample=77, buffer_id=05:4D
    db 0,0,100,0,72,124,5,6,11,2,72,5  ; n4651 t=254.655s dur=100ms, freq=523Hz, sample=72, buffer_id=05:48
    db 0,0,100,0,70,124,14,7,159,1,70,14  ; n4652 t=254.655s dur=100ms, freq=415Hz, sample=70, buffer_id=0E:46
    db 0,0,100,0,65,124,14,9,93,1,65,14  ; n4653 t=254.655s dur=100ms, freq=349Hz, sample=65, buffer_id=0E:41 [TRUNCATE prev:ch9 @254552.9ms -> 254655.0ms]
    db 70,0,100,0,60,124,14,11,6,1,60,14  ; n4654 t=254.655s dur=100ms, freq=262Hz, sample=60, buffer_id=0E:3C [TRUNCATE prev:ch11 @254552.9ms -> 254655.0ms]
    db 9,0,167,0,41,120,2,2,78,0,41,2  ; n4655 t=254.725s dur=167ms, freq=78Hz, sample=41, buffer_id=02:29 [TRUNCATE prev:ch2 @254534.4ms -> 254724.7ms]
    db 0,0,100,0,50,120,11,4,156,0,50,2  ; n4656 t=254.734s dur=100ms, freq=156Hz, sample=50, buffer_id=02:32 [TRUNCATE prev:ch4 @254534.4ms -> 254733.9ms]
    db 5,0,100,0,41,115,13,8,78,0,41,2  ; n4657 t=254.734s dur=100ms, freq=78Hz, sample=41, buffer_id=02:29 [TRUNCATE prev:ch8 @254552.9ms -> 254733.9ms]
    db 0,0,224,10,70,110,4,0,210,1,70,4  ; n4658 t=254.739s dur=2784ms, freq=466Hz, sample=70, buffer_id=04:46 [TRUNCATE prev:ch0 @254636.5ms -> 254738.6ms]
    db 5,0,191,11,65,110,4,10,55,1,65,4  ; n4659 t=254.739s dur=3007ms, freq=311Hz, sample=65, buffer_id=04:41 [TRUNCATE prev:ch10 @254552.9ms -> 254738.6ms]
    db 14,0,100,0,63,120,9,12,55,1,63,2  ; n4660 t=254.743s dur=100ms, freq=311Hz, sample=63, buffer_id=02:3F [TRUNCATE prev:ch12 @254552.9ms -> 254743.2ms]
    db 0,0,224,10,36,120,1,13,78,0,36,1  ; n4661 t=254.757s dur=2784ms, freq=78Hz, sample=36, buffer_id=01:24 [TRUNCATE prev:ch13 @254552.9ms -> 254757.2ms]
    db 0,0,177,9,81,124,5,3,164,3,81,5  ; n4662 t=254.757s dur=2481ms, freq=932Hz, sample=81, buffer_id=05:51 [TRUNCATE prev:ch3 @254655.0ms -> 254757.2ms]
    db 0,0,223,10,77,124,5,5,16,3,77,5  ; n4663 t=254.757s dur=2783ms, freq=784Hz, sample=77, buffer_id=05:4D [TRUNCATE prev:ch5 @254655.0ms -> 254757.2ms]
    db 0,0,169,10,72,124,5,6,75,2,72,5  ; n4664 t=254.757s dur=2729ms, freq=587Hz, sample=72, buffer_id=05:48 [TRUNCATE prev:ch6 @254655.0ms -> 254757.2ms]
    db 0,0,224,10,70,124,14,7,210,1,70,14  ; n4665 t=254.757s dur=2784ms, freq=466Hz, sample=70, buffer_id=0E:46 [TRUNCATE prev:ch7 @254655.0ms -> 254757.2ms]
    db 0,0,108,10,65,124,14,9,136,1,65,14  ; n4666 t=254.757s dur=2668ms, freq=392Hz, sample=65, buffer_id=0E:41 [TRUNCATE prev:ch9 @254655.0ms -> 254757.2ms]
    db 157,1,224,10,60,124,14,11,38,1,60,14  ; n4667 t=254.757s dur=2784ms, freq=294Hz, sample=60, buffer_id=0E:3C [TRUNCATE prev:ch11 @254655.0ms -> 254757.2ms]
    db 9,0,167,0,41,120,2,1,78,0,41,2  ; n4668 t=255.170s dur=167ms, freq=78Hz, sample=41, buffer_id=02:29
    db 0,0,100,0,50,120,11,2,156,0,50,2  ; n4669 t=255.179s dur=100ms, freq=156Hz, sample=50, buffer_id=02:32
    db 9,0,100,0,41,115,13,4,78,0,41,2  ; n4670 t=255.179s dur=100ms, freq=78Hz, sample=41, buffer_id=02:29
    db 171,1,100,0,63,120,9,8,55,1,63,2  ; n4671 t=255.189s dur=100ms, freq=311Hz, sample=63, buffer_id=02:3F
    db 9,0,167,0,41,120,2,2,78,0,41,2  ; n4672 t=255.616s dur=167ms, freq=78Hz, sample=41, buffer_id=02:29
    db 0,0,100,0,50,120,11,1,156,0,50,2  ; n4673 t=255.625s dur=100ms, freq=156Hz, sample=50, buffer_id=02:32
    db 9,0,100,0,41,115,13,8,78,0,41,2  ; n4674 t=255.625s dur=100ms, freq=78Hz, sample=41, buffer_id=02:29
    db 214,0,100,0,63,120,9,4,55,1,63,2  ; n4675 t=255.634s dur=100ms, freq=311Hz, sample=63, buffer_id=02:3F
    db 0,0,100,0,50,120,11,12,156,0,50,2  ; n4676 t=255.848s dur=100ms, freq=156Hz, sample=50, buffer_id=02:32
    db 9,0,100,0,41,115,13,2,78,0,41,2  ; n4677 t=255.848s dur=100ms, freq=78Hz, sample=41, buffer_id=02:29 [TRUNCATE prev:ch2 @255615.8ms -> 255847.9ms]
    db 102,0,100,0,63,120,9,4,55,1,63,2  ; n4678 t=255.857s dur=100ms, freq=311Hz, sample=63, buffer_id=02:3F [TRUNCATE prev:ch4 @255634.4ms -> 255857.1ms]
    db 0,0,100,0,50,120,11,8,156,0,50,2  ; n4679 t=255.959s dur=100ms, freq=156Hz, sample=50, buffer_id=02:32
    db 9,0,100,0,41,115,13,1,78,0,41,2  ; n4680 t=255.959s dur=100ms, freq=78Hz, sample=41, buffer_id=02:29
    db 93,0,100,0,63,120,9,4,55,1,63,2  ; n4681 t=255.969s dur=100ms, freq=311Hz, sample=63, buffer_id=02:3F [TRUNCATE prev:ch4 @255857.1ms -> 255968.5ms]
    db 9,0,167,0,41,120,2,2,78,0,41,2  ; n4682 t=256.061s dur=167ms, freq=78Hz, sample=41, buffer_id=02:29 [TRUNCATE prev:ch2 @255847.9ms -> 256061.4ms]
    db 0,0,100,0,50,120,11,12,156,0,50,2  ; n4683 t=256.071s dur=100ms, freq=156Hz, sample=50, buffer_id=02:32 [TRUNCATE prev:ch12 @255847.9ms -> 256070.6ms]
    db 9,0,100,0,41,115,13,1,78,0,41,2  ; n4684 t=256.071s dur=100ms, freq=78Hz, sample=41, buffer_id=02:29 [TRUNCATE prev:ch1 @255959.3ms -> 256070.6ms]
    db 102,0,100,0,63,120,9,4,55,1,63,2  ; n4685 t=256.080s dur=100ms, freq=311Hz, sample=63, buffer_id=02:3F [TRUNCATE prev:ch4 @255968.5ms -> 256079.9ms]
    db 0,0,100,0,50,120,11,8,156,0,50,2  ; n4686 t=256.182s dur=100ms, freq=156Hz, sample=50, buffer_id=02:32 [TRUNCATE prev:ch8 @255959.3ms -> 256182.0ms]
    db 9,0,100,0,41,115,13,2,78,0,41,2  ; n4687 t=256.182s dur=100ms, freq=78Hz, sample=41, buffer_id=02:29 [TRUNCATE prev:ch2 @256061.4ms -> 256182.0ms]
    db 60,1,100,0,63,120,9,4,55,1,63,2  ; n4688 t=256.191s dur=100ms, freq=311Hz, sample=63, buffer_id=02:3F [TRUNCATE prev:ch4 @256079.9ms -> 256191.3ms]
    db 9,0,167,0,41,120,2,4,78,0,41,2  ; n4689 t=256.507s dur=167ms, freq=78Hz, sample=41, buffer_id=02:29
    db 0,0,100,0,50,120,11,1,156,0,50,2  ; n4690 t=256.516s dur=100ms, freq=156Hz, sample=50, buffer_id=02:32
    db 9,0,100,0,41,115,13,8,78,0,41,2  ; n4691 t=256.516s dur=100ms, freq=78Hz, sample=41, buffer_id=02:29
    db 171,1,100,0,63,120,9,2,55,1,63,2  ; n4692 t=256.526s dur=100ms, freq=311Hz, sample=63, buffer_id=02:3F
    db 9,0,167,0,41,120,2,1,78,0,41,2  ; n4693 t=256.952s dur=167ms, freq=78Hz, sample=41, buffer_id=02:29
    db 0,0,100,0,50,120,11,2,156,0,50,2  ; n4694 t=256.962s dur=100ms, freq=156Hz, sample=50, buffer_id=02:32
    db 9,0,100,0,41,115,13,12,78,0,41,2  ; n4695 t=256.962s dur=100ms, freq=78Hz, sample=41, buffer_id=02:29
    db 171,1,100,0,63,120,9,4,55,1,63,2  ; n4696 t=256.971s dur=100ms, freq=311Hz, sample=63, buffer_id=02:3F
    db 9,0,167,0,41,120,2,2,78,0,41,2  ; n4697 t=257.398s dur=167ms, freq=78Hz, sample=41, buffer_id=02:29
    db 0,0,100,0,50,120,11,1,156,0,50,2  ; n4698 t=257.407s dur=100ms, freq=156Hz, sample=50, buffer_id=02:32
    db 9,0,100,0,41,115,13,4,78,0,41,2  ; n4699 t=257.407s dur=100ms, freq=78Hz, sample=41, buffer_id=02:29
    db 214,0,100,0,63,120,9,8,55,1,63,2  ; n4700 t=257.417s dur=100ms, freq=311Hz, sample=63, buffer_id=02:3F
    db 0,0,100,0,50,120,11,3,156,0,50,2  ; n4701 t=257.630s dur=100ms, freq=156Hz, sample=50, buffer_id=02:32
    db 9,0,100,0,41,115,13,9,78,0,41,2  ; n4702 t=257.630s dur=100ms, freq=78Hz, sample=41, buffer_id=02:29
    db 102,0,100,0,63,120,9,12,55,1,63,2  ; n4703 t=257.639s dur=100ms, freq=311Hz, sample=63, buffer_id=02:3F
    db 0,0,100,0,50,120,11,0,156,0,50,2  ; n4704 t=257.741s dur=100ms, freq=156Hz, sample=50, buffer_id=02:32
    db 9,0,100,0,41,115,13,1,78,0,41,2  ; n4705 t=257.741s dur=100ms, freq=78Hz, sample=41, buffer_id=02:29
    db 102,0,100,0,63,120,9,4,55,1,63,2  ; n4706 t=257.751s dur=100ms, freq=311Hz, sample=63, buffer_id=02:3F
    db 0,0,100,0,50,120,11,2,156,0,50,2  ; n4707 t=257.853s dur=100ms, freq=156Hz, sample=50, buffer_id=02:32
    db 9,0,100,0,41,115,13,5,78,0,41,2  ; n4708 t=257.853s dur=100ms, freq=78Hz, sample=41, buffer_id=02:29
    db 102,0,100,0,63,120,9,6,55,1,63,2  ; n4709 t=257.862s dur=100ms, freq=311Hz, sample=63, buffer_id=02:3F
    db 0,0,100,0,50,120,11,7,156,0,50,2  ; n4710 t=257.964s dur=100ms, freq=156Hz, sample=50, buffer_id=02:32
    db 9,0,100,0,41,115,13,3,78,0,41,2  ; n4711 t=257.964s dur=100ms, freq=78Hz, sample=41, buffer_id=02:29
    db 60,1,100,0,63,120,9,9,55,1,63,2  ; n4712 t=257.974s dur=100ms, freq=311Hz, sample=63, buffer_id=02:3F
    db 9,0,168,0,41,120,2,0,78,0,41,2  ; n4713 t=258.289s dur=168ms, freq=78Hz, sample=41, buffer_id=02:29
    db 0,0,100,0,50,120,11,1,156,0,50,2  ; n4714 t=258.298s dur=100ms, freq=156Hz, sample=50, buffer_id=02:32
    db 9,0,100,0,41,115,13,2,78,0,41,2  ; n4715 t=258.298s dur=100ms, freq=78Hz, sample=41, buffer_id=02:29
    db 174,1,100,0,63,120,9,3,55,1,63,2  ; n4716 t=258.308s dur=100ms, freq=311Hz, sample=63, buffer_id=02:3F
    db 9,0,168,0,41,120,2,1,78,0,41,2  ; n4717 t=258.738s dur=168ms, freq=78Hz, sample=41, buffer_id=02:29
    db 0,0,100,0,50,120,11,0,156,0,50,2  ; n4718 t=258.747s dur=100ms, freq=156Hz, sample=50, buffer_id=02:32
    db 9,0,100,0,41,115,13,3,78,0,41,2  ; n4719 t=258.747s dur=100ms, freq=78Hz, sample=41, buffer_id=02:29
    db 174,1,100,0,63,120,9,2,55,1,63,2  ; n4720 t=258.757s dur=100ms, freq=311Hz, sample=63, buffer_id=02:3F
    db 9,0,168,0,41,120,2,0,78,0,41,2  ; n4721 t=259.187s dur=168ms, freq=78Hz, sample=41, buffer_id=02:29
    db 0,0,100,0,50,120,11,1,156,0,50,2  ; n4722 t=259.196s dur=100ms, freq=156Hz, sample=50, buffer_id=02:32
    db 9,0,100,0,41,115,13,2,78,0,41,2  ; n4723 t=259.196s dur=100ms, freq=78Hz, sample=41, buffer_id=02:29
    db 215,0,100,0,63,120,9,3,55,1,63,2  ; n4724 t=259.206s dur=100ms, freq=311Hz, sample=63, buffer_id=02:3F
    db 0,0,100,0,50,120,11,4,156,0,50,2  ; n4725 t=259.421s dur=100ms, freq=156Hz, sample=50, buffer_id=02:32
    db 9,0,100,0,41,115,13,6,78,0,41,2  ; n4726 t=259.421s dur=100ms, freq=78Hz, sample=41, buffer_id=02:29
    db 103,0,100,0,63,120,9,5,55,1,63,2  ; n4727 t=259.430s dur=100ms, freq=311Hz, sample=63, buffer_id=02:3F
    db 0,0,100,0,50,120,11,2,156,0,50,2  ; n4728 t=259.533s dur=100ms, freq=156Hz, sample=50, buffer_id=02:32
    db 9,0,100,0,41,115,13,1,78,0,41,2  ; n4729 t=259.533s dur=100ms, freq=78Hz, sample=41, buffer_id=02:29
    db 94,0,100,0,63,120,9,7,55,1,63,2  ; n4730 t=259.543s dur=100ms, freq=311Hz, sample=63, buffer_id=02:3F
    db 9,0,168,0,41,120,2,3,78,0,41,2  ; n4731 t=259.636s dur=168ms, freq=78Hz, sample=41, buffer_id=02:29
    db 0,0,100,0,50,120,11,0,156,0,50,2  ; n4732 t=259.645s dur=100ms, freq=156Hz, sample=50, buffer_id=02:32
    db 9,0,100,0,41,115,13,8,78,0,41,2  ; n4733 t=259.645s dur=100ms, freq=78Hz, sample=41, buffer_id=02:29
    db 103,0,100,0,63,120,9,10,55,1,63,2  ; n4734 t=259.655s dur=100ms, freq=311Hz, sample=63, buffer_id=02:3F
    db 0,0,100,0,50,120,11,5,156,0,50,2  ; n4735 t=259.758s dur=100ms, freq=156Hz, sample=50, buffer_id=02:32
    db 9,0,100,0,41,115,13,4,78,0,41,2  ; n4736 t=259.758s dur=100ms, freq=78Hz, sample=41, buffer_id=02:29
    db 62,1,100,0,63,120,9,6,55,1,63,2  ; n4737 t=259.767s dur=100ms, freq=311Hz, sample=63, buffer_id=02:3F
    db 9,0,168,0,41,120,2,0,78,0,41,2  ; n4738 t=260.085s dur=168ms, freq=78Hz, sample=41, buffer_id=02:29
    db 0,0,100,0,50,120,11,1,156,0,50,2  ; n4739 t=260.094s dur=100ms, freq=156Hz, sample=50, buffer_id=02:32
    db 9,0,100,0,41,115,13,2,78,0,41,2  ; n4740 t=260.094s dur=100ms, freq=78Hz, sample=41, buffer_id=02:29
    db 215,0,100,0,63,120,9,3,55,1,63,2  ; n4741 t=260.104s dur=100ms, freq=311Hz, sample=63, buffer_id=02:3F
    db 0,0,100,0,50,120,11,4,156,0,50,2  ; n4742 t=260.319s dur=100ms, freq=156Hz, sample=50, buffer_id=02:32
    db 9,0,100,0,41,115,13,5,78,0,41,2  ; n4743 t=260.319s dur=100ms, freq=78Hz, sample=41, buffer_id=02:29
    db 103,0,100,0,63,120,9,8,55,1,63,2  ; n4744 t=260.328s dur=100ms, freq=311Hz, sample=63, buffer_id=02:3F
    db 0,0,100,0,50,120,11,2,156,0,50,2  ; n4745 t=260.431s dur=100ms, freq=156Hz, sample=50, buffer_id=02:32
    db 9,0,100,0,41,115,13,1,78,0,41,2  ; n4746 t=260.431s dur=100ms, freq=78Hz, sample=41, buffer_id=02:29
    db 94,0,100,0,63,120,9,11,55,1,63,2  ; n4747 t=260.441s dur=100ms, freq=311Hz, sample=63, buffer_id=02:3F
    db 9,0,168,0,41,120,2,3,78,0,41,2  ; n4748 t=260.534s dur=168ms, freq=78Hz, sample=41, buffer_id=02:29
    db 0,0,100,0,50,120,11,0,156,0,50,2  ; n4749 t=260.543s dur=100ms, freq=156Hz, sample=50, buffer_id=02:32
    db 9,0,100,0,41,115,13,6,78,0,41,2  ; n4750 t=260.543s dur=100ms, freq=78Hz, sample=41, buffer_id=02:29
    db 103,0,100,0,63,120,9,13,55,1,63,2  ; n4751 t=260.553s dur=100ms, freq=311Hz, sample=63, buffer_id=02:3F
    db 0,0,100,0,50,120,11,5,156,0,50,2  ; n4752 t=260.656s dur=100ms, freq=156Hz, sample=50, buffer_id=02:32
    db 9,0,100,0,41,115,13,4,78,0,41,2  ; n4753 t=260.656s dur=100ms, freq=78Hz, sample=41, buffer_id=02:29
    db 62,1,100,0,63,120,9,12,55,1,63,2  ; n4754 t=260.665s dur=100ms, freq=311Hz, sample=63, buffer_id=02:3F [TRUNCATE prev:ch12 @257639.4ms -> 260665.1ms]
    db 9,0,168,0,41,120,2,0,78,0,41,2  ; n4755 t=260.983s dur=168ms, freq=78Hz, sample=41, buffer_id=02:29
    db 0,0,100,0,50,120,11,1,156,0,50,2  ; n4756 t=260.993s dur=100ms, freq=156Hz, sample=50, buffer_id=02:32
    db 9,0,100,0,41,115,13,2,78,0,41,2  ; n4757 t=260.993s dur=100ms, freq=78Hz, sample=41, buffer_id=02:29
    db 207,1,100,0,63,120,9,3,55,1,63,2  ; n4758 t=261.002s dur=100ms, freq=311Hz, sample=63, buffer_id=02:3F
    db 0,0,177,0,67,124,5,0,184,1,67,5  ; n4759 t=261.465s dur=177ms, freq=440Hz, sample=67, buffer_id=05:43
    db 95,1,177,0,67,124,5,1,93,1,67,5  ; n4760 t=261.465s dur=177ms, freq=349Hz, sample=67, buffer_id=05:43
    db 0,0,100,0,72,124,5,2,210,1,72,5  ; n4761 t=261.816s dur=100ms, freq=466Hz, sample=72, buffer_id=05:48
    db 65,0,100,0,67,124,5,3,136,1,67,5  ; n4762 t=261.816s dur=100ms, freq=392Hz, sample=67, buffer_id=05:43
    db 9,0,168,0,29,120,2,0,44,0,29,2  ; n4763 t=261.881s dur=168ms, freq=44Hz, sample=29, buffer_id=02:1D
    db 0,0,100,0,53,120,11,1,175,0,53,2  ; n4764 t=261.891s dur=100ms, freq=175Hz, sample=53, buffer_id=02:35
    db 9,0,168,0,41,115,13,5,87,0,41,2  ; n4765 t=261.891s dur=168ms, freq=87Hz, sample=41, buffer_id=02:29
    db 0,0,100,0,65,120,7,4,93,1,65,2  ; n4766 t=261.900s dur=100ms, freq=349Hz, sample=65, buffer_id=02:41
    db 14,0,100,0,60,120,9,6,6,1,60,2  ; n4767 t=261.900s dur=100ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 0,0,100,0,72,124,5,7,11,2,72,5  ; n4768 t=261.914s dur=100ms, freq=523Hz, sample=72, buffer_id=05:48
    db 252,0,100,0,67,124,5,8,184,1,67,5  ; n4769 t=261.914s dur=100ms, freq=440Hz, sample=67, buffer_id=05:43
    db 0,0,241,3,77,124,5,2,186,2,77,5  ; n4770 t=262.166s dur=1009ms, freq=698Hz, sample=77, buffer_id=05:4D
    db 163,0,241,3,67,124,5,9,184,1,67,5  ; n4771 t=262.166s dur=1009ms, freq=440Hz, sample=67, buffer_id=05:43
    db 9,0,168,0,29,120,2,1,44,0,29,2  ; n4772 t=262.330s dur=168ms, freq=44Hz, sample=29, buffer_id=02:1D
    db 0,0,100,0,53,120,11,0,175,0,53,2  ; n4773 t=262.339s dur=100ms, freq=175Hz, sample=53, buffer_id=02:35
    db 9,0,168,0,41,115,13,3,87,0,41,2  ; n4774 t=262.339s dur=168ms, freq=87Hz, sample=41, buffer_id=02:29
    db 0,0,100,0,65,120,7,5,93,1,65,2  ; n4775 t=262.349s dur=100ms, freq=349Hz, sample=65, buffer_id=02:41
    db 174,1,100,0,60,120,9,4,6,1,60,2  ; n4776 t=262.349s dur=100ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 9,0,168,0,29,120,2,0,44,0,29,2  ; n4777 t=262.778s dur=168ms, freq=44Hz, sample=29, buffer_id=02:1D
    db 0,0,100,0,53,120,11,1,175,0,53,2  ; n4778 t=262.788s dur=100ms, freq=175Hz, sample=53, buffer_id=02:35
    db 9,0,168,0,41,115,13,4,87,0,41,2  ; n4779 t=262.788s dur=168ms, freq=87Hz, sample=41, buffer_id=02:29
    db 0,0,100,0,65,120,7,3,93,1,65,2  ; n4780 t=262.797s dur=100ms, freq=349Hz, sample=65, buffer_id=02:41
    db 215,0,100,0,60,120,9,5,6,1,60,2  ; n4781 t=262.797s dur=100ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 9,0,100,0,53,120,11,6,175,0,53,2  ; n4782 t=263.012s dur=100ms, freq=175Hz, sample=53, buffer_id=02:35
    db 0,0,100,0,65,120,7,7,93,1,65,2  ; n4783 t=263.021s dur=100ms, freq=349Hz, sample=65, buffer_id=02:41
    db 103,0,100,0,60,120,9,8,6,1,60,2  ; n4784 t=263.021s dur=100ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 9,0,100,0,53,120,11,3,175,0,53,2  ; n4785 t=263.124s dur=100ms, freq=175Hz, sample=53, buffer_id=02:35
    db 0,0,100,0,65,120,7,1,93,1,65,2  ; n4786 t=263.133s dur=100ms, freq=349Hz, sample=65, buffer_id=02:41
    db 94,0,100,0,60,120,9,10,6,1,60,2  ; n4787 t=263.133s dur=100ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 9,0,168,0,29,120,2,4,44,0,29,2  ; n4788 t=263.227s dur=168ms, freq=44Hz, sample=29, buffer_id=02:1D
    db 0,0,100,0,53,120,11,0,175,0,53,2  ; n4789 t=263.236s dur=100ms, freq=175Hz, sample=53, buffer_id=02:35
    db 5,0,168,0,41,115,13,5,87,0,41,2  ; n4790 t=263.236s dur=168ms, freq=87Hz, sample=41, buffer_id=02:29
    db 5,0,112,0,55,110,4,11,196,0,55,4  ; n4791 t=263.241s dur=112ms, freq=196Hz, sample=55, buffer_id=04:37
    db 0,0,100,0,65,120,7,12,93,1,65,2  ; n4792 t=263.245s dur=100ms, freq=349Hz, sample=65, buffer_id=02:41
    db 14,0,100,0,60,120,9,13,6,1,60,2  ; n4793 t=263.245s dur=100ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 0,0,112,0,67,124,5,9,136,1,67,5  ; n4794 t=263.260s dur=112ms, freq=392Hz, sample=67, buffer_id=05:43 [TRUNCATE prev:ch9 @262166.3ms -> 263259.6ms]
    db 89,0,112,0,55,124,14,2,196,0,55,14  ; n4795 t=263.260s dur=112ms, freq=196Hz, sample=55, buffer_id=0E:37 [TRUNCATE prev:ch2 @262166.3ms -> 263259.6ms]
    db 9,0,100,0,53,120,11,7,175,0,53,2  ; n4796 t=263.348s dur=100ms, freq=175Hz, sample=53, buffer_id=02:35
    db 0,0,100,0,65,120,7,6,93,1,65,2  ; n4797 t=263.358s dur=100ms, freq=349Hz, sample=65, buffer_id=02:41
    db 234,0,100,0,60,120,9,8,6,1,60,2  ; n4798 t=263.358s dur=100ms, freq=262Hz, sample=60, buffer_id=02:3C [TRUNCATE prev:ch8 @263021.3ms -> 263357.7ms]
    db 19,0,100,0,55,110,4,0,220,0,55,4  ; n4799 t=263.591s dur=100ms, freq=220Hz, sample=55, buffer_id=04:37
    db 0,0,100,0,67,124,5,1,184,1,67,5  ; n4800 t=263.610s dur=100ms, freq=440Hz, sample=67, buffer_id=05:43
    db 65,0,100,0,55,124,14,3,220,0,55,14  ; n4801 t=263.610s dur=100ms, freq=220Hz, sample=55, buffer_id=0E:37
    db 9,0,168,0,29,120,2,2,44,0,29,2  ; n4802 t=263.675s dur=168ms, freq=44Hz, sample=29, buffer_id=02:1D
    db 0,0,100,0,53,120,11,4,175,0,53,2  ; n4803 t=263.685s dur=100ms, freq=175Hz, sample=53, buffer_id=02:35
    db 5,0,168,0,41,115,13,6,87,0,41,2  ; n4804 t=263.685s dur=168ms, freq=87Hz, sample=41, buffer_id=02:29
    db 5,0,209,4,60,110,4,5,233,0,60,4  ; n4805 t=263.689s dur=1233ms, freq=233Hz, sample=60, buffer_id=04:3C
    db 0,0,100,0,65,120,7,7,93,1,65,2  ; n4806 t=263.694s dur=100ms, freq=349Hz, sample=65, buffer_id=02:41
    db 14,0,100,0,60,120,9,9,6,1,60,2  ; n4807 t=263.694s dur=100ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 0,0,209,4,72,124,5,8,210,1,72,5  ; n4808 t=263.708s dur=1233ms, freq=466Hz, sample=72, buffer_id=05:48
    db 160,1,209,4,60,124,14,10,233,0,60,14  ; n4809 t=263.708s dur=1233ms, freq=233Hz, sample=60, buffer_id=0E:3C
    db 9,0,168,0,29,120,2,0,44,0,29,2  ; n4810 t=264.124s dur=168ms, freq=44Hz, sample=29, buffer_id=02:1D
    db 0,0,100,0,53,120,11,1,175,0,53,2  ; n4811 t=264.133s dur=100ms, freq=175Hz, sample=53, buffer_id=02:35
    db 9,0,168,0,41,115,13,2,87,0,41,2  ; n4812 t=264.133s dur=168ms, freq=87Hz, sample=41, buffer_id=02:29
    db 0,0,100,0,65,120,7,3,93,1,65,2  ; n4813 t=264.143s dur=100ms, freq=349Hz, sample=65, buffer_id=02:41
    db 9,0,100,0,60,120,9,4,6,1,60,2  ; n4814 t=264.143s dur=100ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 0,0,100,0,73,110,16,6,11,2,73,16  ; n4815 t=264.152s dur=100ms, freq=523Hz, sample=73, buffer_id=10:49
    db 75,0,100,0,65,100,18,7,6,1,65,18  ; n4816 t=264.152s dur=100ms, freq=262Hz, sample=65, buffer_id=12:41
    db 0,0,100,0,73,110,16,9,75,2,73,16  ; n4817 t=264.227s dur=100ms, freq=587Hz, sample=73, buffer_id=10:49
    db 75,0,100,0,65,100,18,11,38,1,65,18  ; n4818 t=264.227s dur=100ms, freq=294Hz, sample=65, buffer_id=12:41
    db 0,0,100,0,77,110,16,12,147,2,77,16  ; n4819 t=264.301s dur=100ms, freq=659Hz, sample=77, buffer_id=10:4D
    db 75,0,100,0,65,100,18,13,74,1,65,18  ; n4820 t=264.301s dur=100ms, freq=330Hz, sample=65, buffer_id=12:41
    db 0,0,100,0,77,110,16,5,186,2,77,16  ; n4821 t=264.376s dur=100ms, freq=698Hz, sample=77, buffer_id=10:4D [TRUNCATE prev:ch5 @263689.4ms -> 264376.2ms]
    db 75,0,100,0,65,100,18,7,93,1,65,18  ; n4822 t=264.376s dur=100ms, freq=349Hz, sample=65, buffer_id=12:41 [TRUNCATE prev:ch7 @264152.0ms -> 264376.2ms]
    db 0,0,100,0,77,110,16,1,16,3,77,16  ; n4823 t=264.451s dur=100ms, freq=784Hz, sample=77, buffer_id=10:4D
    db 75,0,100,0,65,100,18,3,136,1,65,18  ; n4824 t=264.451s dur=100ms, freq=392Hz, sample=65, buffer_id=12:41
    db 0,0,100,0,84,110,16,0,112,3,84,16  ; n4825 t=264.526s dur=100ms, freq=880Hz, sample=84, buffer_id=10:54
    db 47,0,100,0,70,100,18,2,184,1,70,18  ; n4826 t=264.526s dur=100ms, freq=440Hz, sample=70, buffer_id=12:46
    db 9,0,168,0,29,120,2,4,44,0,29,2  ; n4827 t=264.572s dur=168ms, freq=44Hz, sample=29, buffer_id=02:1D
    db 0,0,100,0,53,120,11,6,175,0,53,2  ; n4828 t=264.582s dur=100ms, freq=175Hz, sample=53, buffer_id=02:35
    db 9,0,168,0,41,115,13,9,87,0,41,2  ; n4829 t=264.582s dur=168ms, freq=87Hz, sample=41, buffer_id=02:29
    db 0,0,100,0,65,120,7,11,93,1,65,2  ; n4830 t=264.591s dur=100ms, freq=349Hz, sample=65, buffer_id=02:41
    db 9,0,100,0,60,120,9,8,6,1,60,2  ; n4831 t=264.591s dur=100ms, freq=262Hz, sample=60, buffer_id=02:3C [TRUNCATE prev:ch8 @263708.1ms -> 264591.1ms]
    db 0,0,100,0,84,110,16,10,164,3,84,16  ; n4832 t=264.601s dur=100ms, freq=932Hz, sample=84, buffer_id=10:54 [TRUNCATE prev:ch10 @263708.1ms -> 264600.5ms]
    db 75,0,100,0,70,100,18,12,210,1,70,18  ; n4833 t=264.601s dur=100ms, freq=466Hz, sample=70, buffer_id=12:46 [TRUNCATE prev:ch12 @264301.5ms -> 264600.5ms]
    db 0,0,100,0,84,110,16,13,23,4,84,16  ; n4834 t=264.675s dur=100ms, freq=1047Hz, sample=84, buffer_id=10:54
    db 75,0,100,0,70,100,18,2,11,2,70,18  ; n4835 t=264.675s dur=100ms, freq=523Hz, sample=70, buffer_id=12:46 [TRUNCATE prev:ch2 @264525.7ms -> 264675.2ms]
    db 0,0,100,0,84,110,16,5,151,4,84,16  ; n4836 t=264.750s dur=100ms, freq=1175Hz, sample=84, buffer_id=10:54
    db 56,0,100,0,77,100,18,7,75,2,77,18  ; n4837 t=264.750s dur=100ms, freq=587Hz, sample=77, buffer_id=12:4D
    db 9,0,100,0,53,120,11,1,175,0,53,2  ; n4838 t=264.806s dur=100ms, freq=175Hz, sample=53, buffer_id=02:35
    db 0,0,100,0,65,120,7,3,93,1,65,2  ; n4839 t=264.815s dur=100ms, freq=349Hz, sample=65, buffer_id=02:41
    db 9,0,100,0,60,120,9,8,6,1,60,2  ; n4840 t=264.815s dur=100ms, freq=262Hz, sample=60, buffer_id=02:3C [TRUNCATE prev:ch8 @264591.1ms -> 264815.4ms]
    db 0,0,100,0,89,110,16,0,39,5,89,16  ; n4841 t=264.825s dur=100ms, freq=1319Hz, sample=89, buffer_id=10:59 [TRUNCATE prev:ch0 @264525.7ms -> 264824.8ms]
    db 75,0,100,0,77,100,18,4,147,2,77,18  ; n4842 t=264.825s dur=100ms, freq=659Hz, sample=77, buffer_id=12:4D [TRUNCATE prev:ch4 @264572.5ms -> 264824.8ms]
    db 0,0,100,0,89,110,16,6,117,5,89,16  ; n4843 t=264.899s dur=100ms, freq=1397Hz, sample=89, buffer_id=10:59
    db 19,0,100,0,77,100,18,11,186,2,77,18  ; n4844 t=264.899s dur=100ms, freq=698Hz, sample=77, buffer_id=12:4D
    db 9,0,100,0,53,120,11,10,175,0,53,2  ; n4845 t=264.918s dur=100ms, freq=175Hz, sample=53, buffer_id=02:35
    db 0,0,100,0,65,120,7,12,93,1,65,2  ; n4846 t=264.928s dur=100ms, freq=349Hz, sample=65, buffer_id=02:41
    db 47,0,100,0,60,120,9,8,6,1,60,2  ; n4847 t=264.928s dur=100ms, freq=262Hz, sample=60, buffer_id=02:3C [TRUNCATE prev:ch8 @264815.4ms -> 264927.5ms]
    db 0,0,100,0,89,110,16,9,32,6,89,16  ; n4848 t=264.974s dur=100ms, freq=1568Hz, sample=89, buffer_id=10:59
    db 47,0,100,0,77,100,18,7,16,3,77,18  ; n4849 t=264.974s dur=100ms, freq=784Hz, sample=77, buffer_id=12:4D [TRUNCATE prev:ch7 @264750.0ms -> 264974.3ms]
    db 9,0,168,0,29,120,2,2,44,0,29,2  ; n4850 t=265.021s dur=168ms, freq=44Hz, sample=29, buffer_id=02:1D
    db 0,0,100,0,53,120,11,13,175,0,53,2  ; n4851 t=265.030s dur=100ms, freq=175Hz, sample=53, buffer_id=02:35
    db 9,0,168,0,41,115,13,5,87,0,41,2  ; n4852 t=265.030s dur=168ms, freq=87Hz, sample=41, buffer_id=02:29 [TRUNCATE prev:ch5 @264750.0ms -> 265030.3ms]
    db 0,0,100,0,65,120,7,3,93,1,65,2  ; n4853 t=265.040s dur=100ms, freq=349Hz, sample=65, buffer_id=02:41 [TRUNCATE prev:ch3 @264815.4ms -> 265039.7ms]
    db 14,0,100,0,60,120,9,8,6,1,60,2  ; n4854 t=265.040s dur=100ms, freq=262Hz, sample=60, buffer_id=02:3C [TRUNCATE prev:ch8 @264927.5ms -> 265039.7ms]
    db 89,0,177,0,72,124,5,1,11,2,72,5  ; n4855 t=265.054s dur=177ms, freq=523Hz, sample=72, buffer_id=05:48 [TRUNCATE prev:ch1 @264806.1ms -> 265053.7ms]
    db 9,0,100,0,53,120,11,0,175,0,53,2  ; n4856 t=265.142s dur=100ms, freq=175Hz, sample=53, buffer_id=02:35
    db 0,0,100,0,65,120,7,4,93,1,65,2  ; n4857 t=265.152s dur=100ms, freq=349Hz, sample=65, buffer_id=02:41
    db 252,0,100,0,60,120,9,8,6,1,60,2  ; n4858 t=265.152s dur=100ms, freq=262Hz, sample=60, buffer_id=02:3C [TRUNCATE prev:ch8 @265039.7ms -> 265151.8ms]
    db 65,0,100,0,72,124,5,2,75,2,72,5  ; n4859 t=265.404s dur=100ms, freq=587Hz, sample=72, buffer_id=05:48
    db 9,0,168,0,29,120,2,0,44,0,29,2  ; n4860 t=265.469s dur=168ms, freq=44Hz, sample=29, buffer_id=02:1D
    db 0,0,100,0,53,120,11,1,175,0,53,2  ; n4861 t=265.479s dur=100ms, freq=175Hz, sample=53, buffer_id=02:35
    db 9,0,168,0,41,115,13,3,87,0,41,2  ; n4862 t=265.479s dur=168ms, freq=87Hz, sample=41, buffer_id=02:29
    db 0,0,100,0,65,120,7,5,93,1,65,2  ; n4863 t=265.488s dur=100ms, freq=349Hz, sample=65, buffer_id=02:41
    db 14,0,100,0,60,120,9,4,6,1,60,2  ; n4864 t=265.488s dur=100ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 252,0,100,0,77,124,5,6,147,2,77,5  ; n4865 t=265.502s dur=100ms, freq=659Hz, sample=77, buffer_id=05:4D
    db 163,0,241,3,81,124,5,2,164,3,81,5  ; n4866 t=265.755s dur=1009ms, freq=932Hz, sample=81, buffer_id=05:51
    db 9,0,168,0,29,120,2,1,44,0,29,2  ; n4867 t=265.918s dur=168ms, freq=44Hz, sample=29, buffer_id=02:1D
    db 0,0,100,0,53,120,11,0,175,0,53,2  ; n4868 t=265.927s dur=100ms, freq=175Hz, sample=53, buffer_id=02:35
    db 9,0,168,0,41,115,13,4,87,0,41,2  ; n4869 t=265.927s dur=168ms, freq=87Hz, sample=41, buffer_id=02:29
    db 0,0,100,0,65,120,7,3,93,1,65,2  ; n4870 t=265.937s dur=100ms, freq=349Hz, sample=65, buffer_id=02:41
    db 174,1,100,0,60,120,9,5,6,1,60,2  ; n4871 t=265.937s dur=100ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 9,0,168,0,29,120,2,0,44,0,29,2  ; n4872 t=266.367s dur=168ms, freq=44Hz, sample=29, buffer_id=02:1D
    db 0,0,100,0,53,120,11,1,175,0,53,2  ; n4873 t=266.376s dur=100ms, freq=175Hz, sample=53, buffer_id=02:35
    db 9,0,168,0,41,115,13,3,87,0,41,2  ; n4874 t=266.376s dur=168ms, freq=87Hz, sample=41, buffer_id=02:29
    db 0,0,100,0,65,120,7,4,93,1,65,2  ; n4875 t=266.385s dur=100ms, freq=349Hz, sample=65, buffer_id=02:41
    db 215,0,100,0,60,120,9,6,6,1,60,2  ; n4876 t=266.385s dur=100ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 9,0,100,0,53,120,11,5,175,0,53,2  ; n4877 t=266.600s dur=100ms, freq=175Hz, sample=53, buffer_id=02:35
    db 0,0,100,0,65,120,7,7,93,1,65,2  ; n4878 t=266.610s dur=100ms, freq=349Hz, sample=65, buffer_id=02:41
    db 103,0,100,0,60,120,9,9,6,1,60,2  ; n4879 t=266.610s dur=100ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 9,0,100,0,53,120,11,4,175,0,53,2  ; n4880 t=266.712s dur=100ms, freq=175Hz, sample=53, buffer_id=02:35
    db 0,0,100,0,65,120,7,1,93,1,65,2  ; n4881 t=266.722s dur=100ms, freq=349Hz, sample=65, buffer_id=02:41
    db 93,0,100,0,60,120,9,10,6,1,60,2  ; n4882 t=266.722s dur=100ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 9,0,168,0,29,120,2,3,44,0,29,2  ; n4883 t=266.815s dur=168ms, freq=44Hz, sample=29, buffer_id=02:1D
    db 0,0,100,0,53,120,11,0,175,0,53,2  ; n4884 t=266.825s dur=100ms, freq=175Hz, sample=53, buffer_id=02:35
    db 5,0,168,0,41,115,13,6,87,0,41,2  ; n4885 t=266.825s dur=168ms, freq=87Hz, sample=41, buffer_id=02:29
    db 5,0,112,0,60,110,4,8,38,1,60,4  ; n4886 t=266.829s dur=112ms, freq=294Hz, sample=60, buffer_id=04:3C
    db 0,0,100,0,65,120,7,11,93,1,65,2  ; n4887 t=266.834s dur=100ms, freq=349Hz, sample=65, buffer_id=02:41
    db 14,0,100,0,60,120,9,12,6,1,60,2  ; n4888 t=266.834s dur=100ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 0,0,112,0,72,124,5,13,75,2,72,5  ; n4889 t=266.848s dur=112ms, freq=587Hz, sample=72, buffer_id=05:48
    db 89,0,112,0,60,124,14,2,38,1,60,14  ; n4890 t=266.848s dur=112ms, freq=294Hz, sample=60, buffer_id=0E:3C [TRUNCATE prev:ch2 @265754.5ms -> 266847.8ms]
    db 9,0,100,0,53,120,11,7,175,0,53,2  ; n4891 t=266.937s dur=100ms, freq=175Hz, sample=53, buffer_id=02:35
    db 0,0,100,0,65,120,7,5,93,1,65,2  ; n4892 t=266.946s dur=100ms, freq=349Hz, sample=65, buffer_id=02:41
    db 234,0,100,0,60,120,9,9,6,1,60,2  ; n4893 t=266.946s dur=100ms, freq=262Hz, sample=60, buffer_id=02:3C [TRUNCATE prev:ch9 @266609.5ms -> 266945.9ms]
    db 19,0,100,0,65,110,4,0,74,1,65,4  ; n4894 t=267.180s dur=100ms, freq=330Hz, sample=65, buffer_id=04:41
    db 0,0,100,0,77,124,5,1,147,2,77,5  ; n4895 t=267.198s dur=100ms, freq=659Hz, sample=77, buffer_id=05:4D
    db 65,0,100,0,65,124,14,2,74,1,65,14  ; n4896 t=267.198s dur=100ms, freq=330Hz, sample=65, buffer_id=0E:41
    db 9,0,168,0,29,120,2,4,44,0,29,2  ; n4897 t=267.264s dur=168ms, freq=44Hz, sample=29, buffer_id=02:1D
    db 0,0,100,0,53,120,11,3,175,0,53,2  ; n4898 t=267.273s dur=100ms, freq=175Hz, sample=53, buffer_id=02:35
    db 5,0,168,0,41,115,13,5,87,0,41,2  ; n4899 t=267.273s dur=168ms, freq=87Hz, sample=41, buffer_id=02:29
    db 5,0,224,0,65,110,4,6,93,1,65,4  ; n4900 t=267.278s dur=224ms, freq=349Hz, sample=65, buffer_id=04:41
    db 0,0,100,0,65,120,7,7,93,1,65,2  ; n4901 t=267.282s dur=100ms, freq=349Hz, sample=65, buffer_id=02:41
    db 14,0,100,0,60,120,9,8,6,1,60,2  ; n4902 t=267.282s dur=100ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 0,0,78,1,77,124,5,9,186,2,77,5  ; n4903 t=267.296s dur=334ms, freq=698Hz, sample=77, buffer_id=05:4D
    db 160,1,78,1,65,124,14,10,93,1,65,14  ; n4904 t=267.296s dur=334ms, freq=349Hz, sample=65, buffer_id=0E:41
    db 9,0,168,0,29,120,2,0,44,0,29,2  ; n4905 t=267.712s dur=168ms, freq=44Hz, sample=29, buffer_id=02:1D
    db 0,0,100,0,53,120,11,1,175,0,53,2  ; n4906 t=267.721s dur=100ms, freq=175Hz, sample=53, buffer_id=02:35
    db 5,0,168,0,41,115,13,2,87,0,41,2  ; n4907 t=267.721s dur=168ms, freq=87Hz, sample=41, buffer_id=02:29
    db 5,0,224,0,65,110,4,3,136,1,65,4  ; n4908 t=267.726s dur=224ms, freq=392Hz, sample=65, buffer_id=04:41
    db 0,0,100,0,65,120,7,4,93,1,65,2  ; n4909 t=267.731s dur=100ms, freq=349Hz, sample=65, buffer_id=02:41
    db 9,0,100,0,60,120,9,5,6,1,60,2  ; n4910 t=267.731s dur=100ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 0,0,100,0,84,110,16,6,23,4,84,16  ; n4911 t=267.740s dur=100ms, freq=1047Hz, sample=84, buffer_id=10:54
    db 5,0,100,0,70,100,18,7,11,2,70,18  ; n4912 t=267.740s dur=100ms, freq=523Hz, sample=70, buffer_id=12:46
    db 0,0,78,1,77,124,5,8,16,3,77,5  ; n4913 t=267.745s dur=334ms, freq=784Hz, sample=77, buffer_id=05:4D
    db 84,0,78,1,65,124,14,11,136,1,65,14  ; n4914 t=267.745s dur=334ms, freq=392Hz, sample=65, buffer_id=0E:41
    db 0,0,100,0,84,110,16,12,151,4,84,16  ; n4915 t=267.829s dur=100ms, freq=1175Hz, sample=84, buffer_id=10:54
    db 89,0,100,0,77,100,18,13,75,2,77,18  ; n4916 t=267.829s dur=100ms, freq=587Hz, sample=77, buffer_id=12:4D
    db 0,0,100,0,89,110,16,9,39,5,89,16  ; n4917 t=267.918s dur=100ms, freq=1319Hz, sample=89, buffer_id=10:59
    db 89,0,100,0,77,100,18,10,147,2,77,18  ; n4918 t=267.918s dur=100ms, freq=659Hz, sample=77, buffer_id=12:4D
    db 0,0,100,0,89,110,16,0,117,5,89,16  ; n4919 t=268.007s dur=100ms, freq=1397Hz, sample=89, buffer_id=10:59 [TRUNCATE prev:ch0 @267712.2ms -> 268006.5ms]
    db 89,0,100,0,77,100,18,13,186,2,77,18  ; n4920 t=268.007s dur=100ms, freq=698Hz, sample=77, buffer_id=12:4D [TRUNCATE prev:ch13 @267829.0ms -> 268006.5ms]
    db 0,0,100,0,89,110,16,1,32,6,89,16  ; n4921 t=268.095s dur=100ms, freq=1568Hz, sample=89, buffer_id=10:59
    db 65,0,100,0,77,100,18,2,16,3,77,18  ; n4922 t=268.095s dur=100ms, freq=784Hz, sample=77, buffer_id=12:4D
    db 9,0,168,0,29,120,2,3,44,0,29,2  ; n4923 t=268.161s dur=168ms, freq=44Hz, sample=29, buffer_id=02:1D
    db 0,0,100,0,53,120,11,4,175,0,53,2  ; n4924 t=268.170s dur=100ms, freq=175Hz, sample=53, buffer_id=02:35
    db 5,0,168,0,41,115,13,5,87,0,41,2  ; n4925 t=268.170s dur=168ms, freq=87Hz, sample=41, buffer_id=02:29
    db 5,0,80,1,70,110,4,6,184,1,70,4  ; n4926 t=268.175s dur=336ms, freq=440Hz, sample=70, buffer_id=04:46
    db 0,0,100,0,65,120,7,7,93,1,65,2  ; n4927 t=268.179s dur=100ms, freq=349Hz, sample=65, buffer_id=02:41
    db 9,0,100,0,60,120,9,12,6,1,60,2  ; n4928 t=268.179s dur=100ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 0,0,100,0,94,110,16,8,224,6,94,16  ; n4929 t=268.189s dur=100ms, freq=1760Hz, sample=94, buffer_id=10:5E [TRUNCATE prev:ch8 @267744.9ms -> 268188.7ms]
    db 5,0,100,0,81,100,18,11,112,3,81,18  ; n4930 t=268.189s dur=100ms, freq=880Hz, sample=81, buffer_id=12:51 [TRUNCATE prev:ch11 @267744.9ms -> 268188.7ms]
    db 0,0,80,1,81,124,5,9,112,3,81,5  ; n4931 t=268.193s dur=336ms, freq=880Hz, sample=81, buffer_id=05:51 [TRUNCATE prev:ch9 @267917.7ms -> 268193.4ms]
    db 201,0,80,1,70,124,14,10,184,1,70,14  ; n4932 t=268.193s dur=336ms, freq=440Hz, sample=70, buffer_id=0E:46 [TRUNCATE prev:ch10 @267917.7ms -> 268193.4ms]
    db 9,0,100,0,53,120,11,0,175,0,53,2  ; n4933 t=268.394s dur=100ms, freq=175Hz, sample=53, buffer_id=02:35
    db 0,0,100,0,65,120,7,1,93,1,65,2  ; n4934 t=268.404s dur=100ms, freq=349Hz, sample=65, buffer_id=02:41
    db 103,0,100,0,60,120,9,2,6,1,60,2  ; n4935 t=268.404s dur=100ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 9,0,100,0,53,120,11,7,175,0,53,2  ; n4936 t=268.506s dur=100ms, freq=175Hz, sample=53, buffer_id=02:35
    db 0,0,100,0,65,120,7,4,93,1,65,2  ; n4937 t=268.516s dur=100ms, freq=349Hz, sample=65, buffer_id=02:41
    db 93,0,100,0,60,120,9,8,6,1,60,2  ; n4938 t=268.516s dur=100ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 9,0,168,0,29,120,2,5,44,0,29,2  ; n4939 t=268.609s dur=168ms, freq=44Hz, sample=29, buffer_id=02:1D
    db 0,0,100,0,53,120,11,3,175,0,53,2  ; n4940 t=268.619s dur=100ms, freq=175Hz, sample=53, buffer_id=02:35
    db 9,0,168,0,41,115,13,11,87,0,41,2  ; n4941 t=268.619s dur=168ms, freq=87Hz, sample=41, buffer_id=02:29
    db 0,0,100,0,65,120,7,12,93,1,65,2  ; n4942 t=268.628s dur=100ms, freq=349Hz, sample=65, buffer_id=02:41
    db 14,0,100,0,60,120,9,13,6,1,60,2  ; n4943 t=268.628s dur=100ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 89,0,177,0,67,124,5,6,184,1,67,5  ; n4944 t=268.642s dur=177ms, freq=440Hz, sample=67, buffer_id=05:43 [TRUNCATE prev:ch6 @268174.7ms -> 268641.9ms]
    db 9,0,100,0,53,120,11,1,175,0,53,2  ; n4945 t=268.731s dur=100ms, freq=175Hz, sample=53, buffer_id=02:35
    db 0,0,100,0,65,120,7,0,93,1,65,2  ; n4946 t=268.740s dur=100ms, freq=349Hz, sample=65, buffer_id=02:41
    db 252,0,100,0,60,120,9,9,6,1,60,2  ; n4947 t=268.740s dur=100ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 65,0,100,0,72,124,5,2,210,1,72,5  ; n4948 t=268.992s dur=100ms, freq=466Hz, sample=72, buffer_id=05:48
    db 9,0,168,0,29,120,2,0,44,0,29,2  ; n4949 t=269.058s dur=168ms, freq=44Hz, sample=29, buffer_id=02:1D
    db 0,0,100,0,53,120,11,4,175,0,53,2  ; n4950 t=269.067s dur=100ms, freq=175Hz, sample=53, buffer_id=02:35
    db 9,0,168,0,41,115,13,1,87,0,41,2  ; n4951 t=269.067s dur=168ms, freq=87Hz, sample=41, buffer_id=02:29
    db 0,0,100,0,65,120,7,3,93,1,65,2  ; n4952 t=269.077s dur=100ms, freq=349Hz, sample=65, buffer_id=02:41
    db 14,0,100,0,60,120,9,5,6,1,60,2  ; n4953 t=269.077s dur=100ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 252,0,100,0,72,124,5,6,11,2,72,5  ; n4954 t=269.091s dur=100ms, freq=523Hz, sample=72, buffer_id=05:48
    db 163,0,241,3,77,124,5,2,186,2,77,5  ; n4955 t=269.343s dur=1009ms, freq=698Hz, sample=77, buffer_id=05:4D
    db 9,0,168,0,29,120,2,1,44,0,29,2  ; n4956 t=269.506s dur=168ms, freq=44Hz, sample=29, buffer_id=02:1D
    db 0,0,100,0,53,120,11,0,175,0,53,2  ; n4957 t=269.516s dur=100ms, freq=175Hz, sample=53, buffer_id=02:35
    db 9,0,168,0,41,115,13,3,87,0,41,2  ; n4958 t=269.516s dur=168ms, freq=87Hz, sample=41, buffer_id=02:29
    db 0,0,100,0,65,120,7,4,93,1,65,2  ; n4959 t=269.525s dur=100ms, freq=349Hz, sample=65, buffer_id=02:41
    db 174,1,100,0,60,120,9,6,6,1,60,2  ; n4960 t=269.525s dur=100ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 9,0,168,0,29,120,2,0,44,0,29,2  ; n4961 t=269.955s dur=168ms, freq=44Hz, sample=29, buffer_id=02:1D
    db 0,0,100,0,53,120,11,1,175,0,53,2  ; n4962 t=269.964s dur=100ms, freq=175Hz, sample=53, buffer_id=02:35
    db 9,0,168,0,41,115,13,4,87,0,41,2  ; n4963 t=269.964s dur=168ms, freq=87Hz, sample=41, buffer_id=02:29
    db 0,0,100,0,65,120,7,3,93,1,65,2  ; n4964 t=269.974s dur=100ms, freq=349Hz, sample=65, buffer_id=02:41
    db 215,0,100,0,60,120,9,7,6,1,60,2  ; n4965 t=269.974s dur=100ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 9,0,100,0,53,120,11,5,175,0,53,2  ; n4966 t=270.188s dur=100ms, freq=175Hz, sample=53, buffer_id=02:35
    db 0,0,100,0,65,120,7,6,93,1,65,2  ; n4967 t=270.198s dur=100ms, freq=349Hz, sample=65, buffer_id=02:41
    db 103,0,100,0,60,120,9,10,6,1,60,2  ; n4968 t=270.198s dur=100ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 9,0,100,0,53,120,11,3,175,0,53,2  ; n4969 t=270.301s dur=100ms, freq=175Hz, sample=53, buffer_id=02:35
    db 0,0,100,0,65,120,7,1,93,1,65,2  ; n4970 t=270.310s dur=100ms, freq=349Hz, sample=65, buffer_id=02:41
    db 93,0,100,0,60,120,9,11,6,1,60,2  ; n4971 t=270.310s dur=100ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 9,0,168,0,29,120,2,4,44,0,29,2  ; n4972 t=270.403s dur=168ms, freq=44Hz, sample=29, buffer_id=02:1D
    db 0,0,100,0,53,120,11,0,175,0,53,2  ; n4973 t=270.413s dur=100ms, freq=175Hz, sample=53, buffer_id=02:35
    db 9,0,168,0,41,115,13,7,87,0,41,2  ; n4974 t=270.413s dur=168ms, freq=87Hz, sample=41, buffer_id=02:29
    db 0,0,100,0,65,120,7,8,93,1,65,2  ; n4975 t=270.422s dur=100ms, freq=349Hz, sample=65, buffer_id=02:41
    db 14,0,100,0,60,120,9,12,6,1,60,2  ; n4976 t=270.422s dur=100ms, freq=262Hz, sample=60, buffer_id=02:3C
    db 89,0,112,0,77,124,5,9,16,3,77,5  ; n4977 t=270.436s dur=112ms, freq=784Hz, sample=77, buffer_id=05:4D
    db 9,0,100,0,53,120,11,6,175,0,53,2  ; n4978 t=270.525s dur=100ms, freq=175Hz, sample=53, buffer_id=02:35
    db 0,0,100,0,65,120,7,5,93,1,65,2  ; n4979 t=270.534s dur=100ms, freq=349Hz, sample=65, buffer_id=02:41
    db 252,0,100,0,60,120,9,13,6,1,60,2  ; n4980 t=270.534s dur=100ms, freq=262Hz, sample=60, buffer_id=02:3C [TRUNCATE prev:ch13 @268627.9ms -> 270534.2ms]
    db 65,0,100,0,81,124,5,0,112,3,81,5  ; n4981 t=270.786s dur=100ms, freq=880Hz, sample=81, buffer_id=05:51
    db 9,0,162,0,29,120,2,1,46,0,29,2  ; n4982 t=270.852s dur=162ms, freq=46Hz, sample=29, buffer_id=02:1D
    db 0,0,100,0,53,120,11,2,185,0,53,2  ; n4983 t=270.861s dur=100ms, freq=185Hz, sample=53, buffer_id=02:35
    db 9,0,168,0,41,115,13,3,92,0,41,2  ; n4984 t=270.861s dur=168ms, freq=92Hz, sample=41, buffer_id=02:29
    db 0,0,100,0,66,120,7,4,114,1,66,2  ; n4985 t=270.871s dur=100ms, freq=370Hz, sample=66, buffer_id=02:42
    db 14,0,100,0,61,120,9,5,21,1,61,2  ; n4986 t=270.871s dur=100ms, freq=277Hz, sample=61, buffer_id=02:3D
    db 160,1,222,4,81,124,5,6,164,3,81,5  ; n4987 t=270.885s dur=1246ms, freq=932Hz, sample=81, buffer_id=05:51
    db 9,0,162,0,29,120,2,0,46,0,29,2  ; n4988 t=271.300s dur=162ms, freq=46Hz, sample=29, buffer_id=02:1D
    db 0,0,100,0,53,120,11,1,185,0,53,2  ; n4989 t=271.310s dur=100ms, freq=185Hz, sample=53, buffer_id=02:35
    db 9,0,168,0,41,115,13,2,92,0,41,2  ; n4990 t=271.310s dur=168ms, freq=92Hz, sample=41, buffer_id=02:29
    db 0,0,100,0,66,120,7,3,114,1,66,2  ; n4991 t=271.319s dur=100ms, freq=370Hz, sample=66, buffer_id=02:42
    db 9,0,100,0,61,120,9,4,21,1,61,2  ; n4992 t=271.319s dur=100ms, freq=277Hz, sample=61, buffer_id=02:3D
    db 0,0,100,0,73,110,16,5,42,2,73,16  ; n4993 t=271.328s dur=100ms, freq=554Hz, sample=73, buffer_id=10:49
    db 61,0,100,0,65,100,18,7,21,1,65,18  ; n4994 t=271.328s dur=100ms, freq=277Hz, sample=65, buffer_id=12:41
    db 0,0,100,0,73,110,16,8,110,2,73,16  ; n4995 t=271.389s dur=100ms, freq=622Hz, sample=73, buffer_id=10:49
    db 65,0,100,0,65,100,18,9,55,1,65,18  ; n4996 t=271.389s dur=100ms, freq=311Hz, sample=65, buffer_id=12:41
    db 0,0,100,0,77,110,16,10,186,2,77,16  ; n4997 t=271.455s dur=100ms, freq=698Hz, sample=77, buffer_id=10:4D
    db 65,0,100,0,65,100,18,11,93,1,65,18  ; n4998 t=271.455s dur=100ms, freq=349Hz, sample=65, buffer_id=12:41
    db 0,0,100,0,77,110,16,12,228,2,77,16  ; n4999 t=271.520s dur=100ms, freq=740Hz, sample=77, buffer_id=10:4D
    db 61,0,100,0,65,100,18,13,114,1,65,18  ; n5000 t=271.520s dur=100ms, freq=370Hz, sample=65, buffer_id=12:41
    db 0,0,100,0,77,110,16,10,63,3,77,16  ; n5001 t=271.581s dur=100ms, freq=831Hz, sample=77, buffer_id=10:4D [TRUNCATE prev:ch10 @271454.6ms -> 271580.7ms]
    db 66,0,100,0,70,100,18,6,159,1,70,18  ; n5002 t=271.581s dur=100ms, freq=415Hz, sample=70, buffer_id=12:46 [TRUNCATE prev:ch6 @270884.6ms -> 271580.7ms]
    db 0,0,100,0,84,110,16,1,164,3,84,16  ; n5003 t=271.646s dur=100ms, freq=932Hz, sample=84, buffer_id=10:54
    db 65,0,100,0,70,100,18,3,210,1,70,18  ; n5004 t=271.646s dur=100ms, freq=466Hz, sample=70, buffer_id=12:46
    db 0,0,100,0,84,110,16,0,23,4,84,16  ; n5005 t=271.712s dur=100ms, freq=1047Hz, sample=84, buffer_id=10:54
    db 37,0,100,0,70,100,18,2,11,2,70,18  ; n5006 t=271.712s dur=100ms, freq=523Hz, sample=70, buffer_id=12:46
    db 9,0,162,0,29,120,2,4,46,0,29,2  ; n5007 t=271.749s dur=162ms, freq=46Hz, sample=29, buffer_id=02:1D
    db 0,0,100,0,53,120,11,5,185,0,53,2  ; n5008 t=271.758s dur=100ms, freq=185Hz, sample=53, buffer_id=02:35
    db 9,0,173,0,41,115,13,7,92,0,41,2  ; n5009 t=271.758s dur=173ms, freq=92Hz, sample=41, buffer_id=02:29
    db 0,0,100,0,66,120,7,8,114,1,66,2  ; n5010 t=271.768s dur=100ms, freq=370Hz, sample=66, buffer_id=02:42
    db 9,0,100,0,61,120,9,9,21,1,61,2  ; n5011 t=271.768s dur=100ms, freq=277Hz, sample=61, buffer_id=02:3D
    db 0,0,100,0,84,110,16,11,85,4,84,16  ; n5012 t=271.777s dur=100ms, freq=1109Hz, sample=84, buffer_id=10:54
    db 213,0,100,0,70,100,18,6,42,2,70,18  ; n5013 t=271.777s dur=100ms, freq=554Hz, sample=70, buffer_id=12:46 [TRUNCATE prev:ch6 @271580.7ms -> 271777.0ms]
    db 10,0,100,0,53,120,11,1,185,0,53,2  ; n5014 t=271.990s dur=100ms, freq=185Hz, sample=53, buffer_id=02:35
    db 0,0,100,0,66,120,7,3,114,1,66,2  ; n5015 t=272.000s dur=100ms, freq=370Hz, sample=66, buffer_id=02:42
    db 107,0,100,0,61,120,9,10,21,1,61,2  ; n5016 t=272.000s dur=100ms, freq=277Hz, sample=61, buffer_id=02:3D
    db 10,0,100,0,53,120,11,0,185,0,53,2  ; n5017 t=272.107s dur=100ms, freq=185Hz, sample=53, buffer_id=02:35
    db 0,0,100,0,66,120,7,2,114,1,66,2  ; n5018 t=272.117s dur=100ms, freq=370Hz, sample=66, buffer_id=02:42
    db 97,0,100,0,61,120,9,4,21,1,61,2  ; n5019 t=272.117s dur=100ms, freq=277Hz, sample=61, buffer_id=02:3D
    db 10,0,162,0,29,120,2,5,46,0,29,2  ; n5020 t=272.214s dur=162ms, freq=46Hz, sample=29, buffer_id=02:1D
    db 0,0,100,0,53,120,11,6,185,0,53,2  ; n5021 t=272.223s dur=100ms, freq=185Hz, sample=53, buffer_id=02:35
    db 5,0,174,0,41,115,13,8,92,0,41,2  ; n5022 t=272.223s dur=174ms, freq=92Hz, sample=41, buffer_id=02:29
    db 5,0,116,0,60,110,4,7,21,1,60,4  ; n5023 t=272.228s dur=116ms, freq=277Hz, sample=60, buffer_id=04:3C
    db 0,0,100,0,66,120,7,9,114,1,66,2  ; n5024 t=272.233s dur=100ms, freq=370Hz, sample=66, buffer_id=02:42
    db 10,0,100,0,61,120,9,11,21,1,61,2  ; n5025 t=272.233s dur=100ms, freq=277Hz, sample=61, buffer_id=02:3D
    db 0,0,116,0,84,110,16,12,85,4,84,16  ; n5026 t=272.243s dur=116ms, freq=1109Hz, sample=84, buffer_id=10:54
    db 0,0,116,0,85,90,17,13,85,4,85,17  ; n5027 t=272.243s dur=116ms, freq=1109Hz, sample=85, buffer_id=11:55
    db 97,0,100,0,70,100,18,1,42,2,70,18  ; n5028 t=272.243s dur=100ms, freq=554Hz, sample=70, buffer_id=12:46 [TRUNCATE prev:ch1 @271990.4ms -> 272242.8ms]
    db 10,0,100,0,53,120,11,3,185,0,53,2  ; n5029 t=272.340s dur=100ms, freq=185Hz, sample=53, buffer_id=02:35
    db 0,0,100,0,66,120,7,10,114,1,66,2  ; n5030 t=272.350s dur=100ms, freq=370Hz, sample=66, buffer_id=02:42
    db 243,0,100,0,61,120,9,4,21,1,61,2  ; n5031 t=272.350s dur=100ms, freq=277Hz, sample=61, buffer_id=02:3D [TRUNCATE prev:ch4 @272116.6ms -> 272349.6ms]
    db 15,0,100,0,60,110,4,0,21,1,60,4  ; n5032 t=272.592s dur=100ms, freq=277Hz, sample=60, buffer_id=04:3C
    db 0,0,100,0,84,110,16,1,85,4,84,16  ; n5033 t=272.607s dur=100ms, freq=1109Hz, sample=84, buffer_id=10:54
    db 0,0,100,0,85,90,17,2,85,4,85,17  ; n5034 t=272.607s dur=100ms, freq=1109Hz, sample=85, buffer_id=11:55
    db 87,0,100,0,70,100,18,5,42,2,70,18  ; n5035 t=272.607s dur=100ms, freq=554Hz, sample=70, buffer_id=12:46
    db 0,0,145,1,65,110,4,3,93,1,65,4  ; n5036 t=272.694s dur=401ms, freq=349Hz, sample=65, buffer_id=04:41
    db 14,0,145,1,70,110,4,4,184,1,70,4  ; n5037 t=272.694s dur=401ms, freq=440Hz, sample=70, buffer_id=04:46
    db 0,0,144,1,89,110,16,6,117,5,89,16  ; n5038 t=272.709s dur=400ms, freq=1397Hz, sample=89, buffer_id=10:59
    db 0,0,144,1,92,90,17,7,224,6,92,17  ; n5039 t=272.709s dur=400ms, freq=1760Hz, sample=92, buffer_id=11:5C
    db 5,0,144,1,81,100,18,8,112,3,81,18  ; n5040 t=272.709s dur=400ms, freq=880Hz, sample=81, buffer_id=12:51
    db 0,0,144,1,60,124,14,9,233,0,60,14  ; n5041 t=272.714s dur=400ms, freq=233Hz, sample=60, buffer_id=0E:3C
    db 0,0,144,1,60,124,14,10,38,1,60,14  ; n5042 t=272.714s dur=400ms, freq=294Hz, sample=60, buffer_id=0E:3C
    db 159,1,144,1,65,124,14,11,93,1,65,14  ; n5043 t=272.714s dur=400ms, freq=349Hz, sample=65, buffer_id=0E:41
    db 14,0,111,0,36,120,2,0,65,0,36,2  ; n5044 t=273.128s dur=111ms, freq=65Hz, sample=36, buffer_id=02:24
    db 0,0,100,0,60,110,4,1,6,1,60,4  ; n5045 t=273.142s dur=100ms, freq=262Hz, sample=60, buffer_id=04:3C
    db 14,0,100,0,65,110,4,2,136,1,65,4  ; n5046 t=273.142s dur=100ms, freq=392Hz, sample=65, buffer_id=04:41
    db 0,0,100,0,84,110,16,5,23,4,84,16  ; n5047 t=273.156s dur=100ms, freq=1047Hz, sample=84, buffer_id=10:54
    db 0,0,100,0,92,90,17,12,32,6,92,17  ; n5048 t=273.156s dur=100ms, freq=1568Hz, sample=92, buffer_id=11:5C
    db 5,0,100,0,77,100,18,13,16,3,77,18  ; n5049 t=273.156s dur=100ms, freq=784Hz, sample=77, buffer_id=12:4D
    db 0,0,111,0,36,120,1,3,65,0,36,1  ; n5050 t=273.161s dur=111ms, freq=65Hz, sample=36, buffer_id=01:24 [TRUNCATE prev:ch3 @272694.3ms -> 273160.9ms]
    db 0,0,100,0,60,124,14,9,6,1,60,14  ; n5051 t=273.161s dur=100ms, freq=262Hz, sample=60, buffer_id=0E:3C [TRUNCATE prev:ch9 @272713.7ms -> 273160.9ms]
    db 75,1,100,0,70,124,14,4,210,1,70,14  ; n5052 t=273.161s dur=100ms, freq=466Hz, sample=70, buffer_id=0E:46 [TRUNCATE prev:ch4 @272694.3ms -> 273160.9ms]
    db 14,0,100,0,60,110,4,0,6,1,60,4  ; n5053 t=273.492s dur=100ms, freq=262Hz, sample=60, buffer_id=04:3C
    db 0,0,100,0,84,110,16,1,23,4,84,16  ; n5054 t=273.506s dur=100ms, freq=1047Hz, sample=84, buffer_id=10:54
    db 5,0,100,0,70,100,18,2,11,2,70,18  ; n5055 t=273.506s dur=100ms, freq=523Hz, sample=70, buffer_id=12:46
    db 79,0,100,0,60,124,14,3,6,1,60,14  ; n5056 t=273.510s dur=100ms, freq=262Hz, sample=60, buffer_id=0E:3C
    db 0,0,144,1,65,110,4,4,93,1,65,4  ; n5057 t=273.589s dur=400ms, freq=349Hz, sample=65, buffer_id=04:41
    db 14,0,144,1,70,110,4,5,184,1,70,4  ; n5058 t=273.589s dur=400ms, freq=440Hz, sample=70, buffer_id=04:46
    db 0,0,144,1,89,110,16,7,117,5,89,16  ; n5059 t=273.603s dur=400ms, freq=1397Hz, sample=89, buffer_id=10:59
    db 0,0,144,1,92,90,17,6,224,6,92,17  ; n5060 t=273.603s dur=400ms, freq=1760Hz, sample=92, buffer_id=11:5C
    db 5,0,144,1,81,100,18,9,112,3,81,18  ; n5061 t=273.603s dur=400ms, freq=880Hz, sample=81, buffer_id=12:51
    db 0,0,144,1,60,124,14,8,233,0,60,14  ; n5062 t=273.608s dur=400ms, freq=233Hz, sample=60, buffer_id=0E:3C
    db 0,0,144,1,60,124,14,11,38,1,60,14  ; n5063 t=273.608s dur=400ms, freq=294Hz, sample=60, buffer_id=0E:3C
    db 159,1,144,1,65,124,14,10,93,1,65,14  ; n5064 t=273.608s dur=400ms, freq=349Hz, sample=65, buffer_id=0E:41
    db 14,0,111,0,36,120,2,0,65,0,36,2  ; n5065 t=274.023s dur=111ms, freq=65Hz, sample=36, buffer_id=02:24
    db 0,0,100,0,60,110,4,1,6,1,60,4  ; n5066 t=274.037s dur=100ms, freq=262Hz, sample=60, buffer_id=04:3C
    db 14,0,100,0,65,110,4,2,136,1,65,4  ; n5067 t=274.037s dur=100ms, freq=392Hz, sample=65, buffer_id=04:41
    db 0,0,100,0,84,110,16,3,23,4,84,16  ; n5068 t=274.051s dur=100ms, freq=1047Hz, sample=84, buffer_id=10:54
    db 0,0,100,0,92,90,17,13,32,6,92,17  ; n5069 t=274.051s dur=100ms, freq=1568Hz, sample=92, buffer_id=11:5C
    db 5,0,100,0,77,100,18,12,16,3,77,18  ; n5070 t=274.051s dur=100ms, freq=784Hz, sample=77, buffer_id=12:4D
    db 0,0,111,0,36,120,1,4,65,0,36,1  ; n5071 t=274.055s dur=111ms, freq=65Hz, sample=36, buffer_id=01:24 [TRUNCATE prev:ch4 @273589.4ms -> 274055.3ms]
    db 0,0,100,0,60,124,14,8,6,1,60,14  ; n5072 t=274.055s dur=100ms, freq=262Hz, sample=60, buffer_id=0E:3C [TRUNCATE prev:ch8 @273608.1ms -> 274055.3ms]
    db 75,1,100,0,70,124,14,5,210,1,70,14  ; n5073 t=274.055s dur=100ms, freq=466Hz, sample=70, buffer_id=0E:46 [TRUNCATE prev:ch5 @273589.4ms -> 274055.3ms]
    db 14,0,100,0,60,110,4,0,6,1,60,4  ; n5074 t=274.386s dur=100ms, freq=262Hz, sample=60, buffer_id=04:3C
    db 0,0,100,0,84,110,16,1,23,4,84,16  ; n5075 t=274.400s dur=100ms, freq=1047Hz, sample=84, buffer_id=10:54
    db 0,0,100,0,85,90,17,2,23,4,85,17  ; n5076 t=274.400s dur=100ms, freq=1047Hz, sample=85, buffer_id=11:55
    db 5,0,100,0,70,100,18,3,11,2,70,18  ; n5077 t=274.400s dur=100ms, freq=523Hz, sample=70, buffer_id=12:46
    db 79,0,100,0,60,124,14,4,6,1,60,14  ; n5078 t=274.405s dur=100ms, freq=262Hz, sample=60, buffer_id=0E:3C
    db 0,0,144,1,65,110,4,5,93,1,65,4  ; n5079 t=274.484s dur=400ms, freq=349Hz, sample=65, buffer_id=04:41
    db 14,0,144,1,70,110,4,6,184,1,70,4  ; n5080 t=274.484s dur=400ms, freq=440Hz, sample=70, buffer_id=04:46
    db 0,0,144,1,89,110,16,8,117,5,89,16  ; n5081 t=274.498s dur=400ms, freq=1397Hz, sample=89, buffer_id=10:59
    db 0,0,144,1,92,90,17,7,224,6,92,17  ; n5082 t=274.498s dur=400ms, freq=1760Hz, sample=92, buffer_id=11:5C
    db 5,0,144,1,81,100,18,10,112,3,81,18  ; n5083 t=274.498s dur=400ms, freq=880Hz, sample=81, buffer_id=12:51
    db 0,0,144,1,60,124,14,9,233,0,60,14  ; n5084 t=274.502s dur=400ms, freq=233Hz, sample=60, buffer_id=0E:3C
    db 0,0,144,1,60,124,14,12,38,1,60,14  ; n5085 t=274.502s dur=400ms, freq=294Hz, sample=60, buffer_id=0E:3C
    db 159,1,144,1,65,124,14,11,93,1,65,14  ; n5086 t=274.502s dur=400ms, freq=349Hz, sample=65, buffer_id=0E:41
    db 14,0,111,0,36,120,2,0,65,0,36,2  ; n5087 t=274.917s dur=111ms, freq=65Hz, sample=36, buffer_id=02:24
    db 0,0,100,0,60,110,4,1,6,1,60,4  ; n5088 t=274.931s dur=100ms, freq=262Hz, sample=60, buffer_id=04:3C
    db 14,0,100,0,65,110,4,2,136,1,65,4  ; n5089 t=274.931s dur=100ms, freq=392Hz, sample=65, buffer_id=04:41
    db 0,0,100,0,84,110,16,3,23,4,84,16  ; n5090 t=274.945s dur=100ms, freq=1047Hz, sample=84, buffer_id=10:54
    db 0,0,100,0,92,90,17,4,32,6,92,17  ; n5091 t=274.945s dur=100ms, freq=1568Hz, sample=92, buffer_id=11:5C
    db 5,0,100,0,77,100,18,13,16,3,77,18  ; n5092 t=274.945s dur=100ms, freq=784Hz, sample=77, buffer_id=12:4D
    db 0,0,111,0,36,120,1,5,65,0,36,1  ; n5093 t=274.950s dur=111ms, freq=65Hz, sample=36, buffer_id=01:24 [TRUNCATE prev:ch5 @274483.8ms -> 274949.7ms]
    db 0,0,100,0,60,124,14,9,6,1,60,14  ; n5094 t=274.950s dur=100ms, freq=262Hz, sample=60, buffer_id=0E:3C [TRUNCATE prev:ch9 @274502.5ms -> 274949.7ms]
    db 75,1,100,0,70,124,14,6,210,1,70,14  ; n5095 t=274.950s dur=100ms, freq=466Hz, sample=70, buffer_id=0E:46 [TRUNCATE prev:ch6 @274483.8ms -> 274949.7ms]
    db 14,0,100,0,60,110,4,0,6,1,60,4  ; n5096 t=275.280s dur=100ms, freq=262Hz, sample=60, buffer_id=04:3C
    db 0,0,100,0,84,110,16,1,23,4,84,16  ; n5097 t=275.294s dur=100ms, freq=1047Hz, sample=84, buffer_id=10:54
    db 0,0,100,0,85,90,17,2,23,4,85,17  ; n5098 t=275.294s dur=100ms, freq=1047Hz, sample=85, buffer_id=11:55
    db 5,0,100,0,70,100,18,3,11,2,70,18  ; n5099 t=275.294s dur=100ms, freq=523Hz, sample=70, buffer_id=12:46
    db 79,0,100,0,60,124,14,4,6,1,60,14  ; n5100 t=275.299s dur=100ms, freq=262Hz, sample=60, buffer_id=0E:3C
    db 0,0,200,0,65,110,4,5,93,1,65,4  ; n5101 t=275.378s dur=200ms, freq=349Hz, sample=65, buffer_id=04:41
    db 14,0,200,0,70,110,4,6,184,1,70,4  ; n5102 t=275.378s dur=200ms, freq=440Hz, sample=70, buffer_id=04:46
    db 0,0,200,0,89,110,16,7,117,5,89,16  ; n5103 t=275.392s dur=200ms, freq=1397Hz, sample=89, buffer_id=10:59
    db 0,0,200,0,92,90,17,8,224,6,92,17  ; n5104 t=275.392s dur=200ms, freq=1760Hz, sample=92, buffer_id=11:5C
    db 5,0,200,0,81,100,18,9,112,3,81,18  ; n5105 t=275.392s dur=200ms, freq=880Hz, sample=81, buffer_id=12:51
    db 0,0,200,0,60,124,14,10,233,0,60,14  ; n5106 t=275.397s dur=200ms, freq=233Hz, sample=60, buffer_id=0E:3C
    db 0,0,200,0,60,124,14,11,38,1,60,14  ; n5107 t=275.397s dur=200ms, freq=294Hz, sample=60, buffer_id=0E:3C
    db 205,0,200,0,65,124,14,12,93,1,65,14  ; n5108 t=275.397s dur=200ms, freq=349Hz, sample=65, buffer_id=0E:41
    db 0,0,100,0,60,110,4,1,6,1,60,4  ; n5109 t=275.602s dur=100ms, freq=262Hz, sample=60, buffer_id=04:3C
    db 14,0,100,0,65,110,4,0,136,1,65,4  ; n5110 t=275.602s dur=100ms, freq=392Hz, sample=65, buffer_id=04:41
    db 0,0,100,0,84,110,16,2,23,4,84,16  ; n5111 t=275.616s dur=100ms, freq=1047Hz, sample=84, buffer_id=10:54
    db 0,0,100,0,92,90,17,3,32,6,92,17  ; n5112 t=275.616s dur=100ms, freq=1568Hz, sample=92, buffer_id=11:5C
    db 5,0,100,0,77,100,18,4,16,3,77,18  ; n5113 t=275.616s dur=100ms, freq=784Hz, sample=77, buffer_id=12:4D
    db 0,0,100,0,60,124,14,13,6,1,60,14  ; n5114 t=275.620s dur=100ms, freq=262Hz, sample=60, buffer_id=0E:3C
    db 191,0,100,0,70,124,14,5,210,1,70,14  ; n5115 t=275.620s dur=100ms, freq=466Hz, sample=70, buffer_id=0E:46 [TRUNCATE prev:ch5 @275378.2ms -> 275620.5ms]
    db 33,0,111,0,36,120,2,6,65,0,36,2  ; n5116 t=275.811s dur=111ms, freq=65Hz, sample=36, buffer_id=02:24
    db 0,0,111,0,36,120,1,7,65,0,36,1  ; n5117 t=275.844s dur=111ms, freq=65Hz, sample=36, buffer_id=01:24
    db 0,0,177,0,67,124,5,8,184,1,67,5  ; n5118 t=275.844s dur=177ms, freq=440Hz, sample=67, buffer_id=05:43
    db 0,0,111,0,55,124,14,9,220,0,55,14  ; n5119 t=275.844s dur=111ms, freq=220Hz, sample=55, buffer_id=0E:37
    db 93,1,100,0,79,100,20,10,112,3,79,20  ; n5120 t=275.844s dur=100ms, freq=880Hz, sample=79, buffer_id=14:4F
    db 0,0,100,0,72,124,5,0,210,1,72,5  ; n5121 t=276.193s dur=100ms, freq=466Hz, sample=72, buffer_id=05:48
    db 0,0,100,0,60,124,14,1,6,1,60,14  ; n5122 t=276.193s dur=100ms, freq=262Hz, sample=60, buffer_id=0E:3C
    db 65,0,100,0,84,100,20,2,164,3,84,20  ; n5123 t=276.193s dur=100ms, freq=932Hz, sample=84, buffer_id=14:54
    db 33,0,168,0,41,120,2,3,87,0,41,2  ; n5124 t=276.259s dur=168ms, freq=87Hz, sample=41, buffer_id=02:29
    db 0,0,100,0,72,124,5,4,11,2,72,5  ; n5125 t=276.291s dur=100ms, freq=523Hz, sample=72, buffer_id=05:48
    db 253,0,100,0,84,100,20,5,23,4,84,20  ; n5126 t=276.291s dur=100ms, freq=1047Hz, sample=84, buffer_id=14:54
    db 0,0,245,3,77,124,5,0,186,2,77,5  ; n5127 t=276.545s dur=1013ms, freq=698Hz, sample=77, buffer_id=05:4D
    db 164,0,100,0,91,100,20,1,117,5,91,20  ; n5128 t=276.545s dur=100ms, freq=1397Hz, sample=91, buffer_id=14:5B
    db 33,0,168,0,41,120,2,2,87,0,41,2  ; n5129 t=276.709s dur=168ms, freq=87Hz, sample=41, buffer_id=02:29
    db 96,1,178,0,55,124,14,3,220,0,55,14  ; n5130 t=276.742s dur=178ms, freq=220Hz, sample=55, buffer_id=0E:37
    db 66,0,100,0,60,124,14,1,233,0,60,14  ; n5131 t=277.094s dur=100ms, freq=233Hz, sample=60, buffer_id=0E:3C
    db 33,0,168,0,41,120,2,3,87,0,41,2  ; n5132 t=277.159s dur=168ms, freq=87Hz, sample=41, buffer_id=02:29
    db 253,0,100,0,60,124,14,2,6,1,60,14  ; n5133 t=277.192s dur=100ms, freq=262Hz, sample=60, buffer_id=0E:3C
    db 164,0,20,3,65,124,14,1,93,1,65,14  ; n5134 t=277.446s dur=788ms, freq=349Hz, sample=65, buffer_id=0E:41
    db 33,0,168,0,36,120,2,2,65,0,36,2  ; n5135 t=277.610s dur=168ms, freq=65Hz, sample=36, buffer_id=02:24
    db 0,0,112,0,67,124,5,3,136,1,67,5  ; n5136 t=277.643s dur=112ms, freq=392Hz, sample=67, buffer_id=05:43
    db 96,1,100,0,79,100,20,4,16,3,79,20  ; n5137 t=277.643s dur=100ms, freq=784Hz, sample=79, buffer_id=14:4F
    db 0,0,100,0,67,124,5,0,184,1,67,5  ; n5138 t=277.995s dur=100ms, freq=440Hz, sample=67, buffer_id=05:43
    db 66,0,100,0,79,100,20,2,112,3,79,20  ; n5139 t=277.995s dur=100ms, freq=880Hz, sample=79, buffer_id=14:4F
    db 33,0,168,0,41,120,2,3,87,0,41,2  ; n5140 t=278.060s dur=168ms, freq=87Hz, sample=41, buffer_id=02:29
    db 0,0,214,4,72,124,5,4,210,1,72,5  ; n5141 t=278.093s dur=1238ms, freq=466Hz, sample=72, buffer_id=05:48
    db 162,1,100,0,84,100,20,6,164,3,84,20  ; n5142 t=278.093s dur=100ms, freq=932Hz, sample=84, buffer_id=14:54
    db 33,0,168,0,41,120,2,0,87,0,41,2  ; n5143 t=278.511s dur=168ms, freq=87Hz, sample=41, buffer_id=02:29
    db 96,1,112,0,55,124,14,1,196,0,55,14  ; n5144 t=278.544s dur=112ms, freq=196Hz, sample=55, buffer_id=0E:37
    db 66,0,100,0,55,124,14,0,220,0,55,14  ; n5145 t=278.896s dur=100ms, freq=220Hz, sample=55, buffer_id=0E:37
    db 33,0,168,0,41,120,2,1,87,0,41,2  ; n5146 t=278.961s dur=168ms, freq=87Hz, sample=41, buffer_id=02:29
    db 162,1,51,2,60,124,14,2,233,0,60,14  ; n5147 t=278.994s dur=563ms, freq=233Hz, sample=60, buffer_id=0E:3C
    db 33,0,168,0,36,120,2,0,65,0,36,2  ; n5148 t=279.412s dur=168ms, freq=65Hz, sample=36, buffer_id=02:24
    db 0,0,178,0,72,124,5,1,11,2,72,5  ; n5149 t=279.445s dur=178ms, freq=523Hz, sample=72, buffer_id=05:48
    db 96,1,100,0,84,100,20,3,23,4,84,20  ; n5150 t=279.445s dur=100ms, freq=1047Hz, sample=84, buffer_id=14:54
    db 0,0,100,0,72,124,5,0,75,2,72,5  ; n5151 t=279.797s dur=100ms, freq=587Hz, sample=72, buffer_id=05:48
    db 66,0,100,0,84,100,20,2,151,4,84,20  ; n5152 t=279.797s dur=100ms, freq=1175Hz, sample=84, buffer_id=14:54
    db 33,0,168,0,41,120,2,1,87,0,41,2  ; n5153 t=279.862s dur=168ms, freq=87Hz, sample=41, buffer_id=02:29
    db 0,0,100,0,77,124,5,3,147,2,77,5  ; n5154 t=279.895s dur=100ms, freq=659Hz, sample=77, buffer_id=05:4D
    db 253,0,100,0,91,100,20,4,39,5,91,20  ; n5155 t=279.895s dur=100ms, freq=1319Hz, sample=91, buffer_id=14:5B
    db 0,0,245,3,81,124,5,0,164,3,81,5  ; n5156 t=280.149s dur=1013ms, freq=932Hz, sample=81, buffer_id=05:51
    db 164,0,100,0,91,100,20,2,73,7,91,20  ; n5157 t=280.149s dur=100ms, freq=1865Hz, sample=91, buffer_id=14:5B
    db 33,0,168,0,41,120,2,3,87,0,41,2  ; n5158 t=280.313s dur=168ms, freq=87Hz, sample=41, buffer_id=02:29
    db 96,1,178,0,60,124,14,1,6,1,60,14  ; n5159 t=280.346s dur=178ms, freq=262Hz, sample=60, buffer_id=0E:3C
    db 66,0,100,0,60,124,14,2,38,1,60,14  ; n5160 t=280.697s dur=100ms, freq=294Hz, sample=60, buffer_id=0E:3C
    db 33,0,168,0,41,120,2,1,87,0,41,2  ; n5161 t=280.763s dur=168ms, freq=87Hz, sample=41, buffer_id=02:29
    db 253,0,100,0,65,124,14,3,74,1,65,14  ; n5162 t=280.796s dur=100ms, freq=330Hz, sample=65, buffer_id=0E:41
    db 164,0,20,3,70,124,14,2,210,1,70,14  ; n5163 t=281.050s dur=788ms, freq=466Hz, sample=70, buffer_id=0E:46
    db 33,0,168,0,36,120,2,1,65,0,36,2  ; n5164 t=281.214s dur=168ms, freq=65Hz, sample=36, buffer_id=02:24
    db 0,0,112,0,72,124,5,3,75,2,72,5  ; n5165 t=281.247s dur=112ms, freq=587Hz, sample=72, buffer_id=05:48
    db 96,1,100,0,84,100,20,4,151,4,84,20  ; n5166 t=281.247s dur=100ms, freq=1175Hz, sample=84, buffer_id=14:54
    db 0,0,100,0,77,124,5,0,147,2,77,5  ; n5167 t=281.599s dur=100ms, freq=659Hz, sample=77, buffer_id=05:4D
    db 66,0,100,0,91,100,20,1,39,5,91,20  ; n5168 t=281.599s dur=100ms, freq=1319Hz, sample=91, buffer_id=14:5B
    db 33,0,168,0,41,120,2,3,87,0,41,2  ; n5169 t=281.664s dur=168ms, freq=87Hz, sample=41, buffer_id=02:29
    db 0,0,79,1,77,124,5,4,186,2,77,5  ; n5170 t=281.697s dur=335ms, freq=698Hz, sample=77, buffer_id=05:4D
    db 162,1,100,0,91,100,20,5,117,5,91,20  ; n5171 t=281.697s dur=100ms, freq=1397Hz, sample=91, buffer_id=14:5B
    db 33,0,168,0,41,120,2,0,87,0,41,2  ; n5172 t=282.115s dur=168ms, freq=87Hz, sample=41, buffer_id=02:29
    db 0,0,79,1,77,124,5,1,16,3,77,5  ; n5173 t=282.147s dur=335ms, freq=784Hz, sample=77, buffer_id=05:4D
    db 0,0,79,1,72,124,5,2,11,2,72,5  ; n5174 t=282.147s dur=335ms, freq=523Hz, sample=72, buffer_id=05:48
    db 0,0,79,1,65,124,14,3,136,1,65,14  ; n5175 t=282.147s dur=335ms, freq=392Hz, sample=65, buffer_id=0E:41
    db 0,0,79,1,60,124,14,5,6,1,60,14  ; n5176 t=282.147s dur=335ms, freq=262Hz, sample=60, buffer_id=0E:3C
    db 162,1,100,0,91,100,20,6,32,6,91,20  ; n5177 t=282.147s dur=100ms, freq=1568Hz, sample=91, buffer_id=14:5B
    db 33,0,168,0,41,120,2,4,87,0,41,2  ; n5178 t=282.565s dur=168ms, freq=87Hz, sample=41, buffer_id=02:29
    db 0,0,168,0,81,124,5,0,112,3,81,5  ; n5179 t=282.598s dur=168ms, freq=880Hz, sample=81, buffer_id=05:51
    db 0,0,168,0,77,124,5,6,186,2,77,5  ; n5180 t=282.598s dur=168ms, freq=698Hz, sample=77, buffer_id=05:4D
    db 0,0,168,0,70,124,14,7,184,1,70,14  ; n5181 t=282.598s dur=168ms, freq=440Hz, sample=70, buffer_id=0E:46
    db 0,0,168,0,65,124,14,8,93,1,65,14  ; n5182 t=282.598s dur=168ms, freq=349Hz, sample=65, buffer_id=0E:41
    db 162,1,100,0,91,100,20,9,224,6,91,20  ; n5183 t=282.598s dur=100ms, freq=1760Hz, sample=91, buffer_id=14:5B
    db 33,0,168,0,36,120,2,0,65,0,36,2  ; n5184 t=283.016s dur=168ms, freq=65Hz, sample=36, buffer_id=02:24
    db 0,0,178,0,67,124,5,1,184,1,67,5  ; n5185 t=283.048s dur=178ms, freq=440Hz, sample=67, buffer_id=05:43
    db 0,0,178,0,67,124,5,2,93,1,67,5  ; n5186 t=283.048s dur=178ms, freq=349Hz, sample=67, buffer_id=05:43
    db 0,0,178,0,55,124,14,3,175,0,55,14  ; n5187 t=283.048s dur=178ms, freq=175Hz, sample=55, buffer_id=0E:37
    db 96,1,100,0,79,100,20,4,112,3,79,20  ; n5188 t=283.048s dur=100ms, freq=880Hz, sample=79, buffer_id=14:4F
    db 0,0,100,0,72,124,5,0,210,1,72,5  ; n5189 t=283.400s dur=100ms, freq=466Hz, sample=72, buffer_id=05:48
    db 0,0,100,0,67,124,5,4,136,1,67,5  ; n5190 t=283.400s dur=100ms, freq=392Hz, sample=67, buffer_id=05:43
    db 0,0,100,0,55,124,14,5,196,0,55,14  ; n5191 t=283.400s dur=100ms, freq=196Hz, sample=55, buffer_id=0E:37
    db 66,0,100,0,84,100,20,6,164,3,84,20  ; n5192 t=283.400s dur=100ms, freq=932Hz, sample=84, buffer_id=14:54
    db 33,0,168,0,41,120,2,1,87,0,41,2  ; n5193 t=283.466s dur=168ms, freq=87Hz, sample=41, buffer_id=02:29
    db 0,0,100,0,72,124,5,2,11,2,72,5  ; n5194 t=283.499s dur=100ms, freq=523Hz, sample=72, buffer_id=05:48
    db 0,0,100,0,67,124,5,3,184,1,67,5  ; n5195 t=283.499s dur=100ms, freq=440Hz, sample=67, buffer_id=05:43
    db 0,0,100,0,55,124,14,7,220,0,55,14  ; n5196 t=283.499s dur=100ms, freq=220Hz, sample=55, buffer_id=0E:37
    db 253,0,100,0,84,100,20,8,23,4,84,20  ; n5197 t=283.499s dur=100ms, freq=1047Hz, sample=84, buffer_id=14:54
    db 0,0,245,3,77,124,5,0,186,2,77,5  ; n5198 t=283.752s dur=1013ms, freq=698Hz, sample=77, buffer_id=05:4D
    db 0,0,245,3,72,124,5,4,11,2,72,5  ; n5199 t=283.752s dur=1013ms, freq=523Hz, sample=72, buffer_id=05:48
    db 0,0,6,1,60,124,14,5,6,1,60,14  ; n5200 t=283.752s dur=262ms, freq=262Hz, sample=60, buffer_id=0E:3C
    db 164,0,100,0,91,100,20,6,117,5,91,20  ; n5201 t=283.752s dur=100ms, freq=1397Hz, sample=91, buffer_id=14:5B
    db 33,0,168,0,41,120,2,2,87,0,41,2  ; n5202 t=283.917s dur=168ms, freq=87Hz, sample=41, buffer_id=02:29
    db 96,1,178,0,55,124,14,1,220,0,55,14  ; n5203 t=283.950s dur=178ms, freq=220Hz, sample=55, buffer_id=0E:37
    db 66,0,100,0,60,124,14,2,233,0,60,14  ; n5204 t=284.301s dur=100ms, freq=233Hz, sample=60, buffer_id=0E:3C
    db 33,0,168,0,41,120,2,1,87,0,41,2  ; n5205 t=284.367s dur=168ms, freq=87Hz, sample=41, buffer_id=02:29
    db 253,0,100,0,60,124,14,3,6,1,60,14  ; n5206 t=284.400s dur=100ms, freq=262Hz, sample=60, buffer_id=0E:3C
    db 164,0,239,0,65,124,14,2,93,1,65,14  ; n5207 t=284.653s dur=239ms, freq=349Hz, sample=65, buffer_id=0E:41
    db 33,0,168,0,36,120,2,1,65,0,36,2  ; n5208 t=284.818s dur=168ms, freq=65Hz, sample=36, buffer_id=02:24
    db 0,0,112,0,77,124,5,3,16,3,77,5  ; n5209 t=284.850s dur=112ms, freq=784Hz, sample=77, buffer_id=05:4D
    db 0,0,112,0,77,124,5,5,147,2,77,5  ; n5210 t=284.850s dur=112ms, freq=659Hz, sample=77, buffer_id=05:4D
    db 0,0,178,0,65,124,14,6,74,1,65,14  ; n5211 t=284.850s dur=178ms, freq=330Hz, sample=65, buffer_id=0E:41
    db 96,1,100,0,91,100,20,7,32,6,91,20  ; n5212 t=284.850s dur=100ms, freq=1568Hz, sample=91, buffer_id=14:5B
    db 0,0,100,0,81,124,5,0,112,3,81,5  ; n5213 t=285.202s dur=100ms, freq=880Hz, sample=81, buffer_id=05:51
    db 0,0,100,0,77,124,5,1,186,2,77,5  ; n5214 t=285.202s dur=100ms, freq=698Hz, sample=77, buffer_id=05:4D
    db 0,0,100,0,65,124,14,3,93,1,65,14  ; n5215 t=285.202s dur=100ms, freq=349Hz, sample=65, buffer_id=0E:41
    db 66,0,100,0,91,100,20,2,224,6,91,20  ; n5216 t=285.202s dur=100ms, freq=1760Hz, sample=91, buffer_id=14:5B
    db 33,0,194,1,41,120,2,4,92,0,41,2  ; n5217 t=285.268s dur=450ms, freq=92Hz, sample=41, buffer_id=02:29
    db 0,0,228,4,81,124,5,5,164,3,81,5  ; n5218 t=285.301s dur=1252ms, freq=932Hz, sample=81, buffer_id=05:51
    db 0,0,228,4,77,124,5,6,228,2,77,5  ; n5219 t=285.301s dur=1252ms, freq=740Hz, sample=77, buffer_id=05:4D
    db 0,0,201,2,65,124,14,7,114,1,65,14  ; n5220 t=285.301s dur=713ms, freq=370Hz, sample=65, buffer_id=0E:41
    db 225,0,100,0,91,100,20,8,73,7,91,20  ; n5221 t=285.301s dur=100ms, freq=1865Hz, sample=91, buffer_id=14:5B
    db 113,0,100,0,60,124,14,0,21,1,60,14  ; n5222 t=285.526s dur=100ms, freq=277Hz, sample=60, buffer_id=0E:3C
    db 80,0,100,0,60,124,14,1,21,1,60,14  ; n5223 t=285.639s dur=100ms, freq=277Hz, sample=60, buffer_id=0E:3C
    db 33,0,194,1,41,120,2,2,92,0,41,2  ; n5224 t=285.719s dur=450ms, freq=92Hz, sample=41, buffer_id=02:29
    db 113,0,100,0,60,124,14,3,21,1,60,14  ; n5225 t=285.751s dur=100ms, freq=277Hz, sample=60, buffer_id=0E:3C
    db 49,1,100,0,60,124,14,8,21,1,60,14  ; n5226 t=285.864s dur=100ms, freq=277Hz, sample=60, buffer_id=0E:3C
    db 33,0,211,1,41,120,2,0,92,0,41,2  ; n5227 t=286.169s dur=467ms, freq=92Hz, sample=41, buffer_id=02:29
    db 193,1,100,0,65,124,14,1,114,1,65,14  ; n5228 t=286.202s dur=100ms, freq=370Hz, sample=65, buffer_id=0E:41
    db 5,0,117,0,60,110,4,1,6,1,60,4  ; n5229 t=286.651s dur=117ms, freq=262Hz, sample=60, buffer_id=04:3C
    db 0,0,117,0,84,120,7,2,23,4,84,2  ; n5230 t=286.656s dur=117ms, freq=1047Hz, sample=84, buffer_id=02:54
    db 15,0,117,0,72,120,9,3,11,2,72,2  ; n5231 t=286.656s dur=117ms, freq=523Hz, sample=72, buffer_id=02:48
    db 0,0,117,0,72,124,5,4,11,2,72,5  ; n5232 t=286.670s dur=117ms, freq=523Hz, sample=72, buffer_id=05:48
    db 0,0,117,0,60,124,14,7,6,1,60,14  ; n5233 t=286.670s dur=117ms, freq=262Hz, sample=60, buffer_id=0E:3C
    db 90,1,100,0,84,100,20,8,23,4,84,20  ; n5234 t=286.670s dur=100ms, freq=1047Hz, sample=84, buffer_id=14:54
    db 5,0,100,0,60,110,4,0,6,1,60,4  ; n5235 t=287.017s dur=100ms, freq=262Hz, sample=60, buffer_id=04:3C
    db 0,0,100,0,84,120,7,1,23,4,84,2  ; n5236 t=287.022s dur=100ms, freq=1047Hz, sample=84, buffer_id=02:54
    db 15,0,100,0,72,120,9,2,11,2,72,2  ; n5237 t=287.022s dur=100ms, freq=523Hz, sample=72, buffer_id=02:48
    db 0,0,100,0,72,124,5,3,11,2,72,5  ; n5238 t=287.036s dur=100ms, freq=523Hz, sample=72, buffer_id=05:48
    db 0,0,100,0,60,124,14,4,6,1,60,14  ; n5239 t=287.036s dur=100ms, freq=262Hz, sample=60, buffer_id=0E:3C
    db 83,0,100,0,84,100,20,5,23,4,84,20  ; n5240 t=287.036s dur=100ms, freq=1047Hz, sample=84, buffer_id=14:54
    db 0,0,157,1,65,110,4,6,93,1,65,4  ; n5241 t=287.119s dur=413ms, freq=349Hz, sample=65, buffer_id=04:41
    db 5,0,157,1,60,110,4,7,6,1,60,4  ; n5242 t=287.119s dur=413ms, freq=262Hz, sample=60, buffer_id=04:3C
    db 0,0,157,1,91,120,7,8,224,6,91,2  ; n5243 t=287.124s dur=413ms, freq=1760Hz, sample=91, buffer_id=02:5B
    db 15,0,157,1,79,120,9,9,112,3,79,2  ; n5244 t=287.124s dur=413ms, freq=880Hz, sample=79, buffer_id=02:4F
    db 0,0,157,1,72,124,5,10,210,1,72,5  ; n5245 t=287.139s dur=413ms, freq=466Hz, sample=72, buffer_id=05:48
    db 0,0,157,1,77,124,5,11,186,2,77,5  ; n5246 t=287.139s dur=413ms, freq=698Hz, sample=77, buffer_id=05:4D
    db 0,0,157,1,81,124,5,12,112,3,81,5  ; n5247 t=287.139s dur=413ms, freq=880Hz, sample=81, buffer_id=05:51
    db 0,0,157,1,60,124,14,13,233,0,60,14  ; n5248 t=287.139s dur=413ms, freq=233Hz, sample=60, buffer_id=0E:3C [TRUNCATE prev:ch13 @275620.5ms -> 287138.8ms]
    db 0,0,157,1,60,124,14,4,38,1,60,14  ; n5249 t=287.139s dur=413ms, freq=294Hz, sample=60, buffer_id=0E:3C [TRUNCATE prev:ch4 @287036.3ms -> 287138.8ms]
    db 0,0,157,1,65,124,14,0,93,1,65,14  ; n5250 t=287.139s dur=413ms, freq=349Hz, sample=65, buffer_id=0E:41 [TRUNCATE prev:ch0 @287016.8ms -> 287138.8ms]
    db 172,1,100,0,91,100,20,1,224,6,91,20  ; n5251 t=287.139s dur=100ms, freq=1760Hz, sample=91, buffer_id=14:5B [TRUNCATE prev:ch1 @287021.7ms -> 287138.8ms]
    db 14,0,205,1,36,120,2,1,65,0,36,2  ; n5252 t=287.566s dur=461ms, freq=65Hz, sample=36, buffer_id=02:24
    db 0,0,100,0,65,110,4,2,136,1,65,4  ; n5253 t=287.581s dur=100ms, freq=392Hz, sample=65, buffer_id=04:41
    db 5,0,100,0,60,110,4,3,6,1,60,4  ; n5254 t=287.581s dur=100ms, freq=262Hz, sample=60, buffer_id=04:3C
    db 0,0,100,0,91,120,7,5,32,6,91,2  ; n5255 t=287.586s dur=100ms, freq=1568Hz, sample=91, buffer_id=02:5B
    db 14,0,100,0,79,120,9,9,16,3,79,2  ; n5256 t=287.586s dur=100ms, freq=784Hz, sample=79, buffer_id=02:4F [TRUNCATE prev:ch9 @287124.2ms -> 287585.5ms]
    db 0,0,115,0,36,120,1,6,65,0,36,1  ; n5257 t=287.600s dur=115ms, freq=65Hz, sample=36, buffer_id=01:24 [TRUNCATE prev:ch6 @287119.3ms -> 287599.9ms]
    db 0,0,100,0,72,124,5,10,11,2,72,5  ; n5258 t=287.600s dur=100ms, freq=523Hz, sample=72, buffer_id=05:48 [TRUNCATE prev:ch10 @287138.8ms -> 287599.9ms]
    db 0,0,100,0,77,124,5,11,16,3,77,5  ; n5259 t=287.600s dur=100ms, freq=784Hz, sample=77, buffer_id=05:4D [TRUNCATE prev:ch11 @287138.8ms -> 287599.9ms]
    db 0,0,100,0,60,124,14,4,6,1,60,14  ; n5260 t=287.600s dur=100ms, freq=262Hz, sample=60, buffer_id=0E:3C [TRUNCATE prev:ch4 @287138.8ms -> 287599.9ms]
    db 0,0,100,0,70,124,14,7,210,1,70,14  ; n5261 t=287.600s dur=100ms, freq=466Hz, sample=70, buffer_id=0E:46 [TRUNCATE prev:ch7 @287119.3ms -> 287599.9ms]
    db 85,1,100,0,91,100,20,8,32,6,91,20  ; n5262 t=287.600s dur=100ms, freq=1568Hz, sample=91, buffer_id=14:5B [TRUNCATE prev:ch8 @287124.2ms -> 287599.9ms]
    db 5,0,100,0,60,110,4,0,6,1,60,4  ; n5263 t=287.941s dur=100ms, freq=262Hz, sample=60, buffer_id=04:3C
    db 0,0,100,0,84,120,7,2,23,4,84,2  ; n5264 t=287.946s dur=100ms, freq=1047Hz, sample=84, buffer_id=02:54
    db 14,0,100,0,72,120,9,3,11,2,72,2  ; n5265 t=287.946s dur=100ms, freq=523Hz, sample=72, buffer_id=02:48
    db 0,0,100,0,72,124,5,4,11,2,72,5  ; n5266 t=287.960s dur=100ms, freq=523Hz, sample=72, buffer_id=05:48
    db 0,0,100,0,60,124,14,5,6,1,60,14  ; n5267 t=287.960s dur=100ms, freq=262Hz, sample=60, buffer_id=0E:3C
    db 82,0,100,0,84,100,20,6,23,4,84,20  ; n5268 t=287.960s dur=100ms, freq=1047Hz, sample=84, buffer_id=14:54
    db 0,0,157,1,65,110,4,7,93,1,65,4  ; n5269 t=288.042s dur=413ms, freq=349Hz, sample=65, buffer_id=04:41
    db 5,0,157,1,60,110,4,8,6,1,60,4  ; n5270 t=288.042s dur=413ms, freq=262Hz, sample=60, buffer_id=04:3C
    db 0,0,157,1,91,120,7,9,224,6,91,2  ; n5271 t=288.047s dur=413ms, freq=1760Hz, sample=91, buffer_id=02:5B
    db 14,0,157,1,79,120,9,10,112,3,79,2  ; n5272 t=288.047s dur=413ms, freq=880Hz, sample=79, buffer_id=02:4F
    db 0,0,157,1,72,124,5,11,210,1,72,5  ; n5273 t=288.061s dur=413ms, freq=466Hz, sample=72, buffer_id=05:48
    db 0,0,157,1,77,124,5,12,186,2,77,5  ; n5274 t=288.061s dur=413ms, freq=698Hz, sample=77, buffer_id=05:4D
    db 0,0,157,1,81,124,5,13,112,3,81,5  ; n5275 t=288.061s dur=413ms, freq=880Hz, sample=81, buffer_id=05:51
    db 0,0,157,1,60,124,14,5,233,0,60,14  ; n5276 t=288.061s dur=413ms, freq=233Hz, sample=60, buffer_id=0E:3C [TRUNCATE prev:ch5 @287960.2ms -> 288061.0ms]
    db 0,0,157,1,60,124,14,1,38,1,60,14  ; n5277 t=288.061s dur=413ms, freq=294Hz, sample=60, buffer_id=0E:3C [TRUNCATE prev:ch1 @287566.3ms -> 288061.0ms]
    db 0,0,157,1,65,124,14,0,93,1,65,14  ; n5278 t=288.061s dur=413ms, freq=349Hz, sample=65, buffer_id=0E:41 [TRUNCATE prev:ch0 @287940.9ms -> 288061.0ms]
    db 172,1,100,0,91,100,20,2,224,6,91,20  ; n5279 t=288.061s dur=100ms, freq=1760Hz, sample=91, buffer_id=14:5B [TRUNCATE prev:ch2 @287945.8ms -> 288061.0ms]
    db 14,0,205,1,36,120,2,2,65,0,36,2  ; n5280 t=288.488s dur=461ms, freq=65Hz, sample=36, buffer_id=02:24
    db 0,0,100,0,65,110,4,3,136,1,65,4  ; n5281 t=288.503s dur=100ms, freq=392Hz, sample=65, buffer_id=04:41
    db 5,0,100,0,60,110,4,4,6,1,60,4  ; n5282 t=288.503s dur=100ms, freq=262Hz, sample=60, buffer_id=04:3C
    db 0,0,100,0,91,120,7,6,32,6,91,2  ; n5283 t=288.508s dur=100ms, freq=1568Hz, sample=91, buffer_id=02:5B
    db 14,0,100,0,79,120,9,10,16,3,79,2  ; n5284 t=288.508s dur=100ms, freq=784Hz, sample=79, buffer_id=02:4F [TRUNCATE prev:ch10 @288046.6ms -> 288507.7ms]
    db 0,0,115,0,36,120,1,7,65,0,36,1  ; n5285 t=288.522s dur=115ms, freq=65Hz, sample=36, buffer_id=01:24 [TRUNCATE prev:ch7 @288041.8ms -> 288522.1ms]
    db 0,0,100,0,72,124,5,11,11,2,72,5  ; n5286 t=288.522s dur=100ms, freq=523Hz, sample=72, buffer_id=05:48 [TRUNCATE prev:ch11 @288061.0ms -> 288522.1ms]
    db 0,0,100,0,77,124,5,12,16,3,77,5  ; n5287 t=288.522s dur=100ms, freq=784Hz, sample=77, buffer_id=05:4D [TRUNCATE prev:ch12 @288061.0ms -> 288522.1ms]
    db 0,0,100,0,60,124,14,1,6,1,60,14  ; n5288 t=288.522s dur=100ms, freq=262Hz, sample=60, buffer_id=0E:3C [TRUNCATE prev:ch1 @288061.0ms -> 288522.1ms]
    db 0,0,100,0,70,124,14,8,210,1,70,14  ; n5289 t=288.522s dur=100ms, freq=466Hz, sample=70, buffer_id=0E:46 [TRUNCATE prev:ch8 @288041.8ms -> 288522.1ms]
    db 85,1,100,0,91,100,20,9,32,6,91,20  ; n5290 t=288.522s dur=100ms, freq=1568Hz, sample=91, buffer_id=14:5B [TRUNCATE prev:ch9 @288046.6ms -> 288522.1ms]
    db 5,0,100,0,60,110,4,0,6,1,60,4  ; n5291 t=288.863s dur=100ms, freq=262Hz, sample=60, buffer_id=04:3C
    db 0,0,100,0,84,120,7,1,23,4,84,2  ; n5292 t=288.868s dur=100ms, freq=1047Hz, sample=84, buffer_id=02:54
    db 14,0,100,0,72,120,9,3,11,2,72,2  ; n5293 t=288.868s dur=100ms, freq=523Hz, sample=72, buffer_id=02:48
    db 0,0,100,0,72,124,5,4,11,2,72,5  ; n5294 t=288.882s dur=100ms, freq=523Hz, sample=72, buffer_id=05:48
    db 0,0,100,0,60,124,14,6,6,1,60,14  ; n5295 t=288.882s dur=100ms, freq=262Hz, sample=60, buffer_id=0E:3C
    db 82,0,100,0,84,100,20,5,23,4,84,20  ; n5296 t=288.882s dur=100ms, freq=1047Hz, sample=84, buffer_id=14:54
    db 0,0,157,1,65,110,4,7,93,1,65,4  ; n5297 t=288.964s dur=413ms, freq=349Hz, sample=65, buffer_id=04:41
    db 5,0,157,1,60,110,4,8,6,1,60,4  ; n5298 t=288.964s dur=413ms, freq=262Hz, sample=60, buffer_id=04:3C
    db 0,0,157,1,91,120,7,9,224,6,91,2  ; n5299 t=288.969s dur=413ms, freq=1760Hz, sample=91, buffer_id=02:5B
    db 14,0,157,1,79,120,9,11,112,3,79,2  ; n5300 t=288.969s dur=413ms, freq=880Hz, sample=79, buffer_id=02:4F
    db 0,0,157,1,72,124,5,10,210,1,72,5  ; n5301 t=288.983s dur=413ms, freq=466Hz, sample=72, buffer_id=05:48
    db 0,0,157,1,77,124,5,13,186,2,77,5  ; n5302 t=288.983s dur=413ms, freq=698Hz, sample=77, buffer_id=05:4D
    db 0,0,157,1,81,124,5,12,112,3,81,5  ; n5303 t=288.983s dur=413ms, freq=880Hz, sample=81, buffer_id=05:51
    db 0,0,157,1,60,124,14,6,233,0,60,14  ; n5304 t=288.983s dur=413ms, freq=233Hz, sample=60, buffer_id=0E:3C [TRUNCATE prev:ch6 @288882.4ms -> 288983.3ms]
    db 0,0,157,1,60,124,14,2,38,1,60,14  ; n5305 t=288.983s dur=413ms, freq=294Hz, sample=60, buffer_id=0E:3C [TRUNCATE prev:ch2 @288488.5ms -> 288983.3ms]
    db 0,0,157,1,65,124,14,0,93,1,65,14  ; n5306 t=288.983s dur=413ms, freq=349Hz, sample=65, buffer_id=0E:41 [TRUNCATE prev:ch0 @288863.2ms -> 288983.3ms]
    db 171,1,100,0,91,100,20,1,224,6,91,20  ; n5307 t=288.983s dur=100ms, freq=1760Hz, sample=91, buffer_id=14:5B [TRUNCATE prev:ch1 @288868.0ms -> 288983.3ms]
    db 14,0,205,1,36,120,2,1,65,0,36,2  ; n5308 t=289.411s dur=461ms, freq=65Hz, sample=36, buffer_id=02:24
    db 0,0,100,0,65,110,4,3,136,1,65,4  ; n5309 t=289.425s dur=100ms, freq=392Hz, sample=65, buffer_id=04:41
    db 5,0,100,0,60,110,4,4,6,1,60,4  ; n5310 t=289.425s dur=100ms, freq=262Hz, sample=60, buffer_id=04:3C
    db 0,0,100,0,91,120,7,5,32,6,91,2  ; n5311 t=289.430s dur=100ms, freq=1568Hz, sample=91, buffer_id=02:5B
    db 14,0,100,0,79,120,9,11,16,3,79,2  ; n5312 t=289.430s dur=100ms, freq=784Hz, sample=79, buffer_id=02:4F [TRUNCATE prev:ch11 @288968.8ms -> 289430.0ms]
    db 0,0,115,0,36,120,1,7,65,0,36,1  ; n5313 t=289.444s dur=115ms, freq=65Hz, sample=36, buffer_id=01:24 [TRUNCATE prev:ch7 @288964.0ms -> 289444.4ms]
    db 0,0,100,0,72,124,5,10,11,2,72,5  ; n5314 t=289.444s dur=100ms, freq=523Hz, sample=72, buffer_id=05:48 [TRUNCATE prev:ch10 @288983.3ms -> 289444.4ms]
    db 0,0,100,0,77,124,5,13,16,3,77,5  ; n5315 t=289.444s dur=100ms, freq=784Hz, sample=77, buffer_id=05:4D [TRUNCATE prev:ch13 @288983.3ms -> 289444.4ms]
    db 0,0,100,0,60,124,14,2,6,1,60,14  ; n5316 t=289.444s dur=100ms, freq=262Hz, sample=60, buffer_id=0E:3C [TRUNCATE prev:ch2 @288983.3ms -> 289444.4ms]
    db 0,0,100,0,70,124,14,8,210,1,70,14  ; n5317 t=289.444s dur=100ms, freq=466Hz, sample=70, buffer_id=0E:46 [TRUNCATE prev:ch8 @288964.0ms -> 289444.4ms]
    db 85,1,100,0,91,100,20,9,32,6,91,20  ; n5318 t=289.444s dur=100ms, freq=1568Hz, sample=91, buffer_id=14:5B [TRUNCATE prev:ch9 @288968.8ms -> 289444.4ms]
    db 5,0,100,0,60,110,4,0,6,1,60,4  ; n5319 t=289.785s dur=100ms, freq=262Hz, sample=60, buffer_id=04:3C
    db 0,0,100,0,84,120,7,2,23,4,84,2  ; n5320 t=289.790s dur=100ms, freq=1047Hz, sample=84, buffer_id=02:54
    db 14,0,100,0,72,120,9,3,11,2,72,2  ; n5321 t=289.790s dur=100ms, freq=523Hz, sample=72, buffer_id=02:48
    db 0,0,100,0,72,124,5,4,11,2,72,5  ; n5322 t=289.805s dur=100ms, freq=523Hz, sample=72, buffer_id=05:48
    db 0,0,100,0,60,124,14,5,6,1,60,14  ; n5323 t=289.805s dur=100ms, freq=262Hz, sample=60, buffer_id=0E:3C
    db 82,0,100,0,84,100,20,6,23,4,84,20  ; n5324 t=289.805s dur=100ms, freq=1047Hz, sample=84, buffer_id=14:54
    db 0,0,157,1,65,110,4,7,93,1,65,4  ; n5325 t=289.886s dur=413ms, freq=349Hz, sample=65, buffer_id=04:41
    db 5,0,157,1,60,110,4,8,6,1,60,4  ; n5326 t=289.886s dur=413ms, freq=262Hz, sample=60, buffer_id=04:3C
    db 0,0,157,1,91,120,7,9,73,7,91,2  ; n5327 t=289.891s dur=413ms, freq=1865Hz, sample=91, buffer_id=02:5B
    db 14,0,157,1,84,120,9,10,164,3,84,2  ; n5328 t=289.891s dur=413ms, freq=932Hz, sample=84, buffer_id=02:54
    db 0,0,157,1,72,124,5,11,75,2,72,5  ; n5329 t=289.906s dur=413ms, freq=587Hz, sample=72, buffer_id=05:48
    db 0,0,157,1,77,124,5,12,186,2,77,5  ; n5330 t=289.906s dur=413ms, freq=698Hz, sample=77, buffer_id=05:4D
    db 0,0,157,1,81,124,5,13,164,3,81,5  ; n5331 t=289.906s dur=413ms, freq=932Hz, sample=81, buffer_id=05:51
    db 0,0,157,1,60,124,14,5,233,0,60,14  ; n5332 t=289.906s dur=413ms, freq=233Hz, sample=60, buffer_id=0E:3C [TRUNCATE prev:ch5 @289804.6ms -> 289905.5ms]
    db 0,0,157,1,60,124,14,1,38,1,60,14  ; n5333 t=289.906s dur=413ms, freq=294Hz, sample=60, buffer_id=0E:3C [TRUNCATE prev:ch1 @289410.7ms -> 289905.5ms]
    db 0,0,157,1,65,124,14,0,93,1,65,14  ; n5334 t=289.906s dur=413ms, freq=349Hz, sample=65, buffer_id=0E:41 [TRUNCATE prev:ch0 @289785.4ms -> 289905.5ms]
    db 172,1,100,0,91,100,20,2,73,7,91,20  ; n5335 t=289.906s dur=100ms, freq=1865Hz, sample=91, buffer_id=14:5B [TRUNCATE prev:ch2 @289790.2ms -> 289905.5ms]
    db 14,0,205,1,36,120,2,2,65,0,36,2  ; n5336 t=290.333s dur=461ms, freq=65Hz, sample=36, buffer_id=02:24
    db 0,0,100,0,65,110,4,3,136,1,65,4  ; n5337 t=290.347s dur=100ms, freq=392Hz, sample=65, buffer_id=04:41
    db 5,0,100,0,60,110,4,4,6,1,60,4  ; n5338 t=290.347s dur=100ms, freq=262Hz, sample=60, buffer_id=04:3C
    db 0,0,100,0,91,120,7,6,224,6,91,2  ; n5339 t=290.352s dur=100ms, freq=1760Hz, sample=91, buffer_id=02:5B
    db 14,0,100,0,79,120,9,7,112,3,79,2  ; n5340 t=290.352s dur=100ms, freq=880Hz, sample=79, buffer_id=02:4F [TRUNCATE prev:ch7 @289886.3ms -> 290352.2ms]
    db 0,0,115,0,36,120,1,8,65,0,36,1  ; n5341 t=290.367s dur=115ms, freq=65Hz, sample=36, buffer_id=01:24 [TRUNCATE prev:ch8 @289886.3ms -> 290366.6ms]
    db 0,0,100,0,72,124,5,11,11,2,72,5  ; n5342 t=290.367s dur=100ms, freq=523Hz, sample=72, buffer_id=05:48 [TRUNCATE prev:ch11 @289905.5ms -> 290366.6ms]
    db 0,0,100,0,81,124,5,13,112,3,81,5  ; n5343 t=290.367s dur=100ms, freq=880Hz, sample=81, buffer_id=05:51 [TRUNCATE prev:ch13 @289905.5ms -> 290366.6ms]
    db 0,0,100,0,60,124,14,1,6,1,60,14  ; n5344 t=290.367s dur=100ms, freq=262Hz, sample=60, buffer_id=0E:3C [TRUNCATE prev:ch1 @289905.5ms -> 290366.6ms]
    db 0,0,100,0,70,124,14,9,210,1,70,14  ; n5345 t=290.367s dur=100ms, freq=466Hz, sample=70, buffer_id=0E:46 [TRUNCATE prev:ch9 @289891.1ms -> 290366.6ms]
    db 85,1,100,0,91,100,20,10,224,6,91,20  ; n5346 t=290.367s dur=100ms, freq=1760Hz, sample=91, buffer_id=14:5B [TRUNCATE prev:ch10 @289891.1ms -> 290366.6ms]
    db 5,0,100,0,60,110,4,0,6,1,60,4  ; n5347 t=290.708s dur=100ms, freq=262Hz, sample=60, buffer_id=04:3C
    db 0,0,100,0,91,120,7,1,32,6,91,2  ; n5348 t=290.712s dur=100ms, freq=1568Hz, sample=91, buffer_id=02:5B
    db 14,0,100,0,79,120,9,3,16,3,79,2  ; n5349 t=290.712s dur=100ms, freq=784Hz, sample=79, buffer_id=02:4F
    db 0,0,100,0,77,124,5,4,16,3,77,5  ; n5350 t=290.727s dur=100ms, freq=784Hz, sample=77, buffer_id=05:4D
    db 0,0,100,0,72,124,5,5,11,2,72,5  ; n5351 t=290.727s dur=100ms, freq=523Hz, sample=72, buffer_id=05:48
    db 0,0,100,0,60,124,14,6,6,1,60,14  ; n5352 t=290.727s dur=100ms, freq=262Hz, sample=60, buffer_id=0E:3C
    db 0,0,100,0,65,124,14,7,136,1,65,14  ; n5353 t=290.727s dur=100ms, freq=392Hz, sample=65, buffer_id=0E:41
    db 67,0,100,0,91,100,20,8,32,6,91,20  ; n5354 t=290.727s dur=100ms, freq=1568Hz, sample=91, buffer_id=14:5B
    db 19,0,172,0,41,120,2,9,87,0,41,2  ; n5355 t=290.794s dur=172ms, freq=87Hz, sample=41, buffer_id=02:29
    db 0,0,157,1,91,120,7,10,73,7,91,2  ; n5356 t=290.813s dur=413ms, freq=1865Hz, sample=91, buffer_id=02:5B
    db 14,0,157,1,84,120,9,11,164,3,84,2  ; n5357 t=290.813s dur=413ms, freq=932Hz, sample=84, buffer_id=02:54
    db 0,0,172,0,43,120,1,12,87,0,43,1  ; n5358 t=290.828s dur=172ms, freq=87Hz, sample=43, buffer_id=01:2B
    db 0,0,248,11,72,124,5,13,11,2,72,5  ; n5359 t=290.828s dur=3064ms, freq=523Hz, sample=72, buffer_id=05:48
    db 0,0,51,12,77,124,5,4,186,2,77,5  ; n5360 t=290.828s dur=3123ms, freq=698Hz, sample=77, buffer_id=05:4D [TRUNCATE prev:ch4 @290726.8ms -> 290827.7ms]
    db 0,0,194,5,60,124,14,6,6,1,60,14  ; n5361 t=290.828s dur=1474ms, freq=262Hz, sample=60, buffer_id=0E:3C [TRUNCATE prev:ch6 @290726.8ms -> 290827.7ms]
    db 0,0,194,5,65,124,14,7,93,1,65,14  ; n5362 t=290.828s dur=1474ms, freq=349Hz, sample=65, buffer_id=0E:41 [TRUNCATE prev:ch7 @290726.8ms -> 290827.7ms]
    db 172,1,100,0,91,100,20,8,117,5,91,20  ; n5363 t=290.828s dur=100ms, freq=1397Hz, sample=91, buffer_id=14:5B [TRUNCATE prev:ch8 @290726.8ms -> 290827.7ms]
    db 19,0,172,0,41,120,2,0,87,0,41,2  ; n5364 t=291.255s dur=172ms, freq=87Hz, sample=41, buffer_id=02:29
    db 0,0,100,0,91,120,7,2,224,6,91,2  ; n5365 t=291.274s dur=100ms, freq=1760Hz, sample=91, buffer_id=02:5B
    db 104,1,100,0,79,120,9,1,112,3,79,2  ; n5366 t=291.274s dur=100ms, freq=880Hz, sample=79, buffer_id=02:4F
    db 0,0,100,0,91,120,7,0,32,6,91,2  ; n5367 t=291.635s dur=100ms, freq=1568Hz, sample=91, buffer_id=02:5B
    db 82,0,100,0,79,120,9,2,16,3,79,2  ; n5368 t=291.635s dur=100ms, freq=784Hz, sample=79, buffer_id=02:4F
    db 14,0,172,0,41,120,2,1,87,0,41,2  ; n5369 t=291.716s dur=172ms, freq=87Hz, sample=41, buffer_id=02:29
    db 5,0,157,1,70,110,4,3,210,1,70,4  ; n5370 t=291.731s dur=413ms, freq=466Hz, sample=70, buffer_id=04:46
    db 0,0,146,7,91,120,7,5,117,5,91,2  ; n5371 t=291.736s dur=1938ms, freq=1397Hz, sample=91, buffer_id=02:5B
    db 186,1,124,7,75,120,9,8,186,2,75,2  ; n5372 t=291.736s dur=1916ms, freq=698Hz, sample=75, buffer_id=02:4B
    db 14,0,172,0,41,120,2,0,87,0,41,2  ; n5373 t=292.177s dur=172ms, freq=87Hz, sample=41, buffer_id=02:29
    db 104,1,100,0,70,110,4,1,184,1,70,4  ; n5374 t=292.192s dur=100ms, freq=440Hz, sample=70, buffer_id=04:46
    db 86,0,100,0,65,110,4,0,136,1,65,4  ; n5375 t=292.552s dur=100ms, freq=392Hz, sample=65, buffer_id=04:41
    db 14,0,172,0,41,120,2,1,87,0,41,2  ; n5376 t=292.639s dur=172ms, freq=87Hz, sample=41, buffer_id=02:29
    db 19,0,247,3,65,110,4,2,93,1,65,4  ; n5377 t=292.653s dur=1015ms, freq=349Hz, sample=65, buffer_id=04:41
    db 0,0,157,1,43,120,1,3,117,0,43,1  ; n5378 t=292.672s dur=413ms, freq=117Hz, sample=43, buffer_id=01:2B
    db 0,0,157,1,60,124,14,7,233,0,60,14  ; n5379 t=292.672s dur=413ms, freq=233Hz, sample=60, buffer_id=0E:3C
    db 172,1,248,3,65,124,14,6,93,1,65,14  ; n5380 t=292.672s dur=1016ms, freq=349Hz, sample=65, buffer_id=0E:41
    db 34,0,172,0,41,120,2,0,87,0,41,2  ; n5381 t=293.100s dur=172ms, freq=87Hz, sample=41, buffer_id=02:29
    db 0,0,100,0,43,120,1,1,110,0,43,1  ; n5382 t=293.133s dur=100ms, freq=110Hz, sample=43, buffer_id=01:2B
    db 104,1,100,0,55,124,14,9,220,0,55,14  ; n5383 t=293.133s dur=100ms, freq=220Hz, sample=55, buffer_id=0E:37
    db 0,0,100,0,43,120,1,0,98,0,43,1  ; n5384 t=293.493s dur=100ms, freq=98Hz, sample=43, buffer_id=01:2B
    db 67,0,100,0,55,124,14,1,196,0,55,14  ; n5385 t=293.493s dur=100ms, freq=196Hz, sample=55, buffer_id=0E:37
    db 34,0,177,0,41,120,2,3,87,0,41,2  ; n5386 t=293.561s dur=177ms, freq=87Hz, sample=41, buffer_id=02:29
    db 0,0,100,0,43,120,1,7,87,0,43,1  ; n5387 t=293.594s dur=100ms, freq=87Hz, sample=43, buffer_id=01:2B
    db 200,1,100,0,55,124,14,10,175,0,55,14  ; n5388 t=293.594s dur=100ms, freq=175Hz, sample=55, buffer_id=0E:37
    db 20,0,100,0,65,110,4,0,93,1,65,4  ; n5389 t=294.050s dur=100ms, freq=349Hz, sample=65, buffer_id=04:41
    db 99,0,100,0,55,124,14,2,175,0,55,14  ; n5390 t=294.070s dur=100ms, freq=175Hz, sample=55, buffer_id=0E:37
    db 20,0,100,0,65,110,4,1,93,1,65,4  ; n5391 t=294.169s dur=100ms, freq=349Hz, sample=65, buffer_id=04:41
    db 99,0,100,0,55,124,14,3,175,0,55,14  ; n5392 t=294.189s dur=100ms, freq=175Hz, sample=55, buffer_id=0E:37
    db 20,0,100,0,65,110,4,4,93,1,65,4  ; n5393 t=294.288s dur=100ms, freq=349Hz, sample=65, buffer_id=04:41
    db 218,0,100,0,55,124,14,5,175,0,55,14  ; n5394 t=294.308s dur=100ms, freq=175Hz, sample=55, buffer_id=0E:37
    db 0,0,234,4,70,110,4,0,210,1,70,4  ; n5395 t=294.526s dur=1258ms, freq=466Hz, sample=70, buffer_id=04:46
    db 0,0,234,4,60,110,4,1,38,1,60,4  ; n5396 t=294.526s dur=1258ms, freq=294Hz, sample=60, buffer_id=04:3C
    db 0,0,234,4,65,110,4,2,55,1,65,4  ; n5397 t=294.526s dur=1258ms, freq=311Hz, sample=65, buffer_id=04:41
    db 20,0,234,4,65,110,4,3,136,1,65,4  ; n5398 t=294.526s dur=1258ms, freq=392Hz, sample=65, buffer_id=04:41
    db 214,0,233,4,65,124,14,7,55,1,65,14  ; n5399 t=294.546s dur=1257ms, freq=311Hz, sample=65, buffer_id=0E:41
    db 0,0,100,0,86,120,7,4,221,4,86,2  ; n5400 t=294.760s dur=100ms, freq=1245Hz, sample=86, buffer_id=02:56
    db 14,0,100,0,75,120,9,5,110,2,75,2  ; n5401 t=294.760s dur=100ms, freq=622Hz, sample=75, buffer_id=02:4B
    db 195,0,100,0,84,100,20,6,221,4,84,20  ; n5402 t=294.775s dur=100ms, freq=1245Hz, sample=84, buffer_id=14:54
    db 19,0,171,0,36,120,2,8,65,0,36,2  ; n5403 t=294.970s dur=171ms, freq=65Hz, sample=36, buffer_id=02:24
    db 0,0,100,0,86,120,7,9,151,4,86,2  ; n5404 t=294.989s dur=100ms, freq=1175Hz, sample=86, buffer_id=02:56
    db 14,0,100,0,73,120,9,10,75,2,73,2  ; n5405 t=294.989s dur=100ms, freq=587Hz, sample=73, buffer_id=02:49
    db 214,0,100,0,84,100,20,11,151,4,84,20  ; n5406 t=295.003s dur=100ms, freq=1175Hz, sample=84, buffer_id=14:54
    db 0,0,100,0,79,120,7,4,16,3,79,2  ; n5407 t=295.218s dur=100ms, freq=784Hz, sample=79, buffer_id=02:4F
    db 14,0,100,0,67,120,9,5,136,1,67,2  ; n5408 t=295.218s dur=100ms, freq=392Hz, sample=67, buffer_id=02:43
    db 214,0,100,0,79,100,20,6,16,3,79,20  ; n5409 t=295.232s dur=100ms, freq=784Hz, sample=79, buffer_id=14:4F
    db 0,0,100,0,75,120,7,8,110,2,75,2  ; n5410 t=295.446s dur=100ms, freq=622Hz, sample=75, buffer_id=02:4B
    db 14,0,100,0,63,120,9,9,55,1,63,2  ; n5411 t=295.446s dur=100ms, freq=311Hz, sample=63, buffer_id=02:3F
    db 214,0,100,0,75,100,20,10,110,2,75,20  ; n5412 t=295.461s dur=100ms, freq=622Hz, sample=75, buffer_id=14:4B
    db 0,0,100,0,84,120,7,4,164,3,84,2  ; n5413 t=295.675s dur=100ms, freq=932Hz, sample=84, buffer_id=02:54
    db 14,0,100,0,71,120,9,5,210,1,71,2  ; n5414 t=295.675s dur=100ms, freq=466Hz, sample=71, buffer_id=02:47
    db 195,0,100,0,84,100,20,6,164,3,84,20  ; n5415 t=295.689s dur=100ms, freq=932Hz, sample=84, buffer_id=14:54
    db 14,0,171,0,36,120,2,8,65,0,36,2  ; n5416 t=295.885s dur=171ms, freq=65Hz, sample=36, buffer_id=02:24
    db 0,0,100,0,70,110,4,9,210,1,70,4  ; n5417 t=295.899s dur=100ms, freq=466Hz, sample=70, buffer_id=04:46
    db 0,0,100,0,60,110,4,10,38,1,60,4  ; n5418 t=295.899s dur=100ms, freq=294Hz, sample=60, buffer_id=04:3C
    db 0,0,100,0,65,110,4,11,55,1,65,4  ; n5419 t=295.899s dur=100ms, freq=311Hz, sample=65, buffer_id=04:41
    db 5,0,100,0,65,110,4,12,136,1,65,4  ; n5420 t=295.899s dur=100ms, freq=392Hz, sample=65, buffer_id=04:41
    db 0,0,100,0,79,120,7,13,16,3,79,2  ; n5421 t=295.904s dur=100ms, freq=784Hz, sample=79, buffer_id=02:4F
    db 14,0,100,0,67,120,9,0,136,1,67,2  ; n5422 t=295.904s dur=100ms, freq=392Hz, sample=67, buffer_id=02:43 [TRUNCATE prev:ch0 @294526.0ms -> 295903.8ms]
    db 0,0,100,0,65,124,14,7,55,1,65,14  ; n5423 t=295.918s dur=100ms, freq=311Hz, sample=65, buffer_id=0E:41 [TRUNCATE prev:ch7 @294545.9ms -> 295918.1ms]
    db 214,0,100,0,79,100,20,1,16,3,79,20  ; n5424 t=295.918s dur=100ms, freq=784Hz, sample=79, buffer_id=14:4F [TRUNCATE prev:ch1 @294526.0ms -> 295918.1ms]
    db 0,0,100,0,86,120,7,2,221,4,86,2  ; n5425 t=296.132s dur=100ms, freq=1245Hz, sample=86, buffer_id=02:56
    db 14,0,100,0,75,120,9,3,110,2,75,2  ; n5426 t=296.132s dur=100ms, freq=622Hz, sample=75, buffer_id=02:4B
    db 0,0,100,0,70,110,4,4,210,1,70,4  ; n5427 t=296.147s dur=100ms, freq=466Hz, sample=70, buffer_id=04:46
    db 0,0,100,0,60,110,4,5,38,1,60,4  ; n5428 t=296.147s dur=100ms, freq=294Hz, sample=60, buffer_id=04:3C
    db 0,0,100,0,65,110,4,6,55,1,65,4  ; n5429 t=296.147s dur=100ms, freq=311Hz, sample=65, buffer_id=04:41
    db 0,0,100,0,65,110,4,11,136,1,65,4  ; n5430 t=296.147s dur=100ms, freq=392Hz, sample=65, buffer_id=04:41 [TRUNCATE prev:ch11 @295899.1ms -> 296146.8ms]
    db 19,0,100,0,84,100,20,8,221,4,84,20  ; n5431 t=296.147s dur=100ms, freq=1245Hz, sample=84, buffer_id=14:54 [TRUNCATE prev:ch8 @295884.8ms -> 296146.8ms]
    db 86,0,100,0,65,124,14,7,55,1,65,14  ; n5432 t=296.166s dur=100ms, freq=311Hz, sample=65, buffer_id=0E:41 [TRUNCATE prev:ch7 @295918.1ms -> 296165.9ms]
    db 0,0,100,0,70,110,4,0,238,1,70,4  ; n5433 t=296.252s dur=100ms, freq=494Hz, sample=70, buffer_id=04:46
    db 0,0,100,0,65,110,4,1,55,1,65,4  ; n5434 t=296.252s dur=100ms, freq=311Hz, sample=65, buffer_id=04:41
    db 0,0,100,0,65,110,4,9,74,1,65,4  ; n5435 t=296.252s dur=100ms, freq=330Hz, sample=65, buffer_id=04:41
    db 19,0,100,0,70,110,4,10,159,1,70,4  ; n5436 t=296.252s dur=100ms, freq=415Hz, sample=70, buffer_id=04:46
    db 86,0,100,0,65,124,14,12,74,1,65,14  ; n5437 t=296.271s dur=100ms, freq=330Hz, sample=65, buffer_id=0E:41
    db 0,0,233,4,70,110,4,13,11,2,70,4  ; n5438 t=296.356s dur=1257ms, freq=523Hz, sample=70, buffer_id=04:46
    db 0,0,233,4,65,110,4,6,74,1,65,4  ; n5439 t=296.356s dur=1257ms, freq=330Hz, sample=65, buffer_id=04:41 [TRUNCATE prev:ch6 @296146.8ms -> 296356.5ms]
    db 0,0,233,4,65,110,4,11,93,1,65,4  ; n5440 t=296.356s dur=1257ms, freq=349Hz, sample=65, buffer_id=04:41 [TRUNCATE prev:ch11 @296146.8ms -> 296356.5ms]
    db 5,0,233,4,70,110,4,4,184,1,70,4  ; n5441 t=296.356s dur=1257ms, freq=440Hz, sample=70, buffer_id=04:46 [TRUNCATE prev:ch4 @296146.8ms -> 296356.5ms]
    db 0,0,100,0,84,120,7,2,23,4,84,2  ; n5442 t=296.361s dur=100ms, freq=1047Hz, sample=84, buffer_id=02:54 [TRUNCATE prev:ch2 @296132.5ms -> 296361.3ms]
    db 14,0,100,0,72,120,9,3,11,2,72,2  ; n5443 t=296.361s dur=100ms, freq=523Hz, sample=72, buffer_id=02:48 [TRUNCATE prev:ch3 @296132.5ms -> 296361.3ms]
    db 0,0,233,4,65,124,14,7,93,1,65,14  ; n5444 t=296.375s dur=1257ms, freq=349Hz, sample=65, buffer_id=0E:41 [TRUNCATE prev:ch7 @296165.9ms -> 296375.5ms]
    db 214,0,100,0,84,100,20,8,23,4,84,20  ; n5445 t=296.375s dur=100ms, freq=1047Hz, sample=84, buffer_id=14:54 [TRUNCATE prev:ch8 @296146.8ms -> 296375.5ms]
    db 0,0,100,0,79,120,7,0,112,3,79,2  ; n5446 t=296.590s dur=100ms, freq=880Hz, sample=79, buffer_id=02:4F
    db 14,0,100,0,67,120,9,1,184,1,67,2  ; n5447 t=296.590s dur=100ms, freq=440Hz, sample=67, buffer_id=02:43
    db 195,0,100,0,79,100,20,5,112,3,79,20  ; n5448 t=296.604s dur=100ms, freq=880Hz, sample=79, buffer_id=14:4F
    db 19,0,171,0,41,120,2,2,87,0,41,2  ; n5449 t=296.800s dur=171ms, freq=87Hz, sample=41, buffer_id=02:29
    db 0,0,100,0,75,120,7,3,186,2,75,2  ; n5450 t=296.819s dur=100ms, freq=698Hz, sample=75, buffer_id=02:4B
    db 14,0,100,0,65,120,9,8,93,1,65,2  ; n5451 t=296.819s dur=100ms, freq=349Hz, sample=65, buffer_id=02:41
    db 214,0,100,0,75,100,20,9,186,2,75,20  ; n5452 t=296.833s dur=100ms, freq=698Hz, sample=75, buffer_id=14:4B
    db 0,0,100,0,84,120,7,0,23,4,84,2  ; n5453 t=297.047s dur=100ms, freq=1047Hz, sample=84, buffer_id=02:54
    db 14,0,100,0,72,120,9,1,11,2,72,2  ; n5454 t=297.047s dur=100ms, freq=523Hz, sample=72, buffer_id=02:48
    db 195,0,100,0,84,100,20,5,23,4,84,20  ; n5455 t=297.062s dur=100ms, freq=1047Hz, sample=84, buffer_id=14:54
    db 19,0,171,0,29,120,2,2,44,0,29,2  ; n5456 t=297.257s dur=171ms, freq=44Hz, sample=29, buffer_id=02:1D
    db 0,0,100,0,79,120,7,3,112,3,79,2  ; n5457 t=297.276s dur=100ms, freq=880Hz, sample=79, buffer_id=02:4F
    db 14,0,100,0,67,120,9,8,184,1,67,2  ; n5458 t=297.276s dur=100ms, freq=440Hz, sample=67, buffer_id=02:43
    db 214,0,100,0,79,100,20,9,112,3,79,20  ; n5459 t=297.290s dur=100ms, freq=880Hz, sample=79, buffer_id=14:4F
    db 0,0,100,0,91,120,7,0,117,5,91,2  ; n5460 t=297.505s dur=100ms, freq=1397Hz, sample=91, buffer_id=02:5B
    db 14,0,100,0,75,120,9,1,186,2,75,2  ; n5461 t=297.505s dur=100ms, freq=698Hz, sample=75, buffer_id=02:4B
    db 210,0,100,0,91,100,20,5,117,5,91,20  ; n5462 t=297.519s dur=100ms, freq=1397Hz, sample=91, buffer_id=14:5B
    db 19,0,100,0,65,110,4,2,93,1,65,4  ; n5463 t=297.729s dur=100ms, freq=349Hz, sample=65, buffer_id=04:41
    db 95,0,100,0,55,124,14,3,175,0,55,14  ; n5464 t=297.748s dur=100ms, freq=175Hz, sample=55, buffer_id=0E:37
    db 19,0,100,0,65,110,4,0,93,1,65,4  ; n5465 t=297.843s dur=100ms, freq=349Hz, sample=65, buffer_id=04:41
    db 95,0,100,0,55,124,14,1,175,0,55,14  ; n5466 t=297.862s dur=100ms, freq=175Hz, sample=55, buffer_id=0E:37
    db 19,0,100,0,65,110,4,4,93,1,65,4  ; n5467 t=297.957s dur=100ms, freq=349Hz, sample=65, buffer_id=04:41
    db 210,0,100,0,55,124,14,5,175,0,55,14  ; n5468 t=297.976s dur=100ms, freq=175Hz, sample=55, buffer_id=0E:37
    db 0,0,233,4,70,110,4,0,210,1,70,4  ; n5469 t=298.186s dur=1257ms, freq=466Hz, sample=70, buffer_id=04:46
    db 0,0,233,4,60,110,4,1,38,1,60,4  ; n5470 t=298.186s dur=1257ms, freq=294Hz, sample=60, buffer_id=04:3C
    db 0,0,233,4,65,110,4,3,55,1,65,4  ; n5471 t=298.186s dur=1257ms, freq=311Hz, sample=65, buffer_id=04:41
    db 19,0,233,4,65,110,4,7,136,1,65,4  ; n5472 t=298.186s dur=1257ms, freq=392Hz, sample=65, buffer_id=04:41
    db 214,0,233,4,65,124,14,2,55,1,65,14  ; n5473 t=298.205s dur=1257ms, freq=311Hz, sample=65, buffer_id=0E:41
    db 0,0,100,0,86,120,7,4,221,4,86,2  ; n5474 t=298.420s dur=100ms, freq=1245Hz, sample=86, buffer_id=02:56
    db 14,0,100,0,75,120,9,5,110,2,75,2  ; n5475 t=298.420s dur=100ms, freq=622Hz, sample=75, buffer_id=02:4B
    db 195,0,100,0,84,100,20,6,221,4,84,20  ; n5476 t=298.434s dur=100ms, freq=1245Hz, sample=84, buffer_id=14:54
    db 19,0,171,0,36,120,2,8,65,0,36,2  ; n5477 t=298.629s dur=171ms, freq=65Hz, sample=36, buffer_id=02:24
    db 0,0,100,0,86,120,7,9,151,4,86,2  ; n5478 t=298.648s dur=100ms, freq=1175Hz, sample=86, buffer_id=02:56
    db 14,0,100,0,73,120,9,10,75,2,73,2  ; n5479 t=298.648s dur=100ms, freq=587Hz, sample=73, buffer_id=02:49
    db 214,0,100,0,84,100,20,11,151,4,84,20  ; n5480 t=298.663s dur=100ms, freq=1175Hz, sample=84, buffer_id=14:54
    db 0,0,100,0,79,120,7,4,16,3,79,2  ; n5481 t=298.877s dur=100ms, freq=784Hz, sample=79, buffer_id=02:4F
    db 14,0,100,0,67,120,9,5,136,1,67,2  ; n5482 t=298.877s dur=100ms, freq=392Hz, sample=67, buffer_id=02:43
    db 214,0,100,0,79,100,20,6,16,3,79,20  ; n5483 t=298.891s dur=100ms, freq=784Hz, sample=79, buffer_id=14:4F
    db 0,0,100,0,75,120,7,8,110,2,75,2  ; n5484 t=299.106s dur=100ms, freq=622Hz, sample=75, buffer_id=02:4B
    db 14,0,100,0,63,120,9,9,55,1,63,2  ; n5485 t=299.106s dur=100ms, freq=311Hz, sample=63, buffer_id=02:3F
    db 214,0,100,0,75,100,20,10,110,2,75,20  ; n5486 t=299.120s dur=100ms, freq=622Hz, sample=75, buffer_id=14:4B
    db 0,0,100,0,84,120,7,4,164,3,84,2  ; n5487 t=299.334s dur=100ms, freq=932Hz, sample=84, buffer_id=02:54
    db 14,0,100,0,71,120,9,5,210,1,71,2  ; n5488 t=299.334s dur=100ms, freq=466Hz, sample=71, buffer_id=02:47
    db 195,0,100,0,84,100,20,6,164,3,84,20  ; n5489 t=299.349s dur=100ms, freq=932Hz, sample=84, buffer_id=14:54
    db 14,0,171,0,36,120,2,8,65,0,36,2  ; n5490 t=299.544s dur=171ms, freq=65Hz, sample=36, buffer_id=02:24
    db 0,0,100,0,70,110,4,9,210,1,70,4  ; n5491 t=299.558s dur=100ms, freq=466Hz, sample=70, buffer_id=04:46
    db 0,0,100,0,60,110,4,10,38,1,60,4  ; n5492 t=299.558s dur=100ms, freq=294Hz, sample=60, buffer_id=04:3C
    db 0,0,100,0,65,110,4,11,55,1,65,4  ; n5493 t=299.558s dur=100ms, freq=311Hz, sample=65, buffer_id=04:41
    db 5,0,100,0,65,110,4,12,136,1,65,4  ; n5494 t=299.558s dur=100ms, freq=392Hz, sample=65, buffer_id=04:41
    db 0,0,100,0,79,120,7,13,16,3,79,2  ; n5495 t=299.563s dur=100ms, freq=784Hz, sample=79, buffer_id=02:4F
    db 14,0,100,0,67,120,9,0,136,1,67,2  ; n5496 t=299.563s dur=100ms, freq=392Hz, sample=67, buffer_id=02:43 [TRUNCATE prev:ch0 @298186.2ms -> 299563.2ms]
    db 0,0,100,0,65,124,14,2,55,1,65,14  ; n5497 t=299.577s dur=100ms, freq=311Hz, sample=65, buffer_id=0E:41 [TRUNCATE prev:ch2 @298205.2ms -> 299577.5ms]
    db 214,0,100,0,79,100,20,1,16,3,79,20  ; n5498 t=299.577s dur=100ms, freq=784Hz, sample=79, buffer_id=14:4F [TRUNCATE prev:ch1 @298186.2ms -> 299577.5ms]
    db 0,0,100,0,86,120,7,3,221,4,86,2  ; n5499 t=299.792s dur=100ms, freq=1245Hz, sample=86, buffer_id=02:56
    db 14,0,100,0,75,120,9,4,110,2,75,2  ; n5500 t=299.792s dur=100ms, freq=622Hz, sample=75, buffer_id=02:4B
    db 0,0,100,0,70,110,4,5,210,1,70,4  ; n5501 t=299.806s dur=100ms, freq=466Hz, sample=70, buffer_id=04:46
    db 0,0,100,0,60,110,4,6,38,1,60,4  ; n5502 t=299.806s dur=100ms, freq=294Hz, sample=60, buffer_id=04:3C
    db 0,0,100,0,65,110,4,7,55,1,65,4  ; n5503 t=299.806s dur=100ms, freq=311Hz, sample=65, buffer_id=04:41 [TRUNCATE prev:ch7 @298186.2ms -> 299806.2ms]
    db 0,0,100,0,65,110,4,11,136,1,65,4  ; n5504 t=299.806s dur=100ms, freq=392Hz, sample=65, buffer_id=04:41 [TRUNCATE prev:ch11 @299558.4ms -> 299806.2ms]
    db 19,0,100,0,84,100,20,8,221,4,84,20  ; n5505 t=299.806s dur=100ms, freq=1245Hz, sample=84, buffer_id=14:54 [TRUNCATE prev:ch8 @299544.1ms -> 299806.2ms]
    db 86,0,100,0,65,124,14,2,55,1,65,14  ; n5506 t=299.825s dur=100ms, freq=311Hz, sample=65, buffer_id=0E:41 [TRUNCATE prev:ch2 @299577.5ms -> 299825.3ms]
    db 0,0,100,0,70,110,4,0,238,1,70,4  ; n5507 t=299.911s dur=100ms, freq=494Hz, sample=70, buffer_id=04:46
    db 0,0,100,0,65,110,4,1,55,1,65,4  ; n5508 t=299.911s dur=100ms, freq=311Hz, sample=65, buffer_id=04:41
    db 0,0,100,0,65,110,4,9,74,1,65,4  ; n5509 t=299.911s dur=100ms, freq=330Hz, sample=65, buffer_id=04:41
    db 19,0,100,0,70,110,4,10,159,1,70,4  ; n5510 t=299.911s dur=100ms, freq=415Hz, sample=70, buffer_id=04:46
    db 86,0,100,0,65,124,14,12,74,1,65,14  ; n5511 t=299.930s dur=100ms, freq=330Hz, sample=65, buffer_id=0E:41
    db 0,0,233,4,70,110,4,13,11,2,70,4  ; n5512 t=300.016s dur=1257ms, freq=523Hz, sample=70, buffer_id=04:46
    db 0,0,233,4,65,110,4,7,74,1,65,4  ; n5513 t=300.016s dur=1257ms, freq=330Hz, sample=65, buffer_id=04:41 [TRUNCATE prev:ch7 @299806.2ms -> 300015.9ms]
    db 0,0,233,4,65,110,4,11,93,1,65,4  ; n5514 t=300.016s dur=1257ms, freq=349Hz, sample=65, buffer_id=04:41 [TRUNCATE prev:ch11 @299806.2ms -> 300015.9ms]
    db 5,0,233,4,70,110,4,5,184,1,70,4  ; n5515 t=300.016s dur=1257ms, freq=440Hz, sample=70, buffer_id=04:46 [TRUNCATE prev:ch5 @299806.2ms -> 300015.9ms]
    db 0,0,100,0,84,120,7,3,23,4,84,2  ; n5516 t=300.021s dur=100ms, freq=1047Hz, sample=84, buffer_id=02:54 [TRUNCATE prev:ch3 @299791.9ms -> 300020.6ms]
    db 14,0,100,0,72,120,9,4,11,2,72,2  ; n5517 t=300.021s dur=100ms, freq=523Hz, sample=72, buffer_id=02:48 [TRUNCATE prev:ch4 @299791.9ms -> 300020.6ms]
    db 0,0,233,4,65,124,14,2,93,1,65,14  ; n5518 t=300.035s dur=1257ms, freq=349Hz, sample=65, buffer_id=0E:41 [TRUNCATE prev:ch2 @299825.3ms -> 300034.9ms]
    db 214,0,100,0,84,100,20,8,23,4,84,20  ; n5519 t=300.035s dur=100ms, freq=1047Hz, sample=84, buffer_id=14:54 [TRUNCATE prev:ch8 @299806.2ms -> 300034.9ms]
    db 0,0,100,0,79,120,7,0,112,3,79,2  ; n5520 t=300.249s dur=100ms, freq=880Hz, sample=79, buffer_id=02:4F
    db 14,0,100,0,67,120,9,1,184,1,67,2  ; n5521 t=300.249s dur=100ms, freq=440Hz, sample=67, buffer_id=02:43
    db 195,0,100,0,79,100,20,6,112,3,79,20  ; n5522 t=300.264s dur=100ms, freq=880Hz, sample=79, buffer_id=14:4F
    db 19,0,171,0,41,120,2,3,87,0,41,2  ; n5523 t=300.459s dur=171ms, freq=87Hz, sample=41, buffer_id=02:29
    db 0,0,100,0,75,120,7,4,186,2,75,2  ; n5524 t=300.478s dur=100ms, freq=698Hz, sample=75, buffer_id=02:4B
    db 14,0,100,0,65,120,9,8,93,1,65,2  ; n5525 t=300.478s dur=100ms, freq=349Hz, sample=65, buffer_id=02:41
    db 214,0,100,0,75,100,20,9,186,2,75,20  ; n5526 t=300.492s dur=100ms, freq=698Hz, sample=75, buffer_id=14:4B
    db 0,0,100,0,84,120,7,0,23,4,84,2  ; n5527 t=300.707s dur=100ms, freq=1047Hz, sample=84, buffer_id=02:54
    db 14,0,100,0,72,120,9,1,11,2,72,2  ; n5528 t=300.707s dur=100ms, freq=523Hz, sample=72, buffer_id=02:48
    db 195,0,100,0,84,100,20,6,23,4,84,20  ; n5529 t=300.721s dur=100ms, freq=1047Hz, sample=84, buffer_id=14:54
    db 19,0,171,0,29,120,2,3,44,0,29,2  ; n5530 t=300.916s dur=171ms, freq=44Hz, sample=29, buffer_id=02:1D
    db 0,0,100,0,79,120,7,4,112,3,79,2  ; n5531 t=300.935s dur=100ms, freq=880Hz, sample=79, buffer_id=02:4F
    db 14,0,100,0,67,120,9,8,184,1,67,2  ; n5532 t=300.935s dur=100ms, freq=440Hz, sample=67, buffer_id=02:43
    db 214,0,100,0,79,100,20,9,112,3,79,20  ; n5533 t=300.950s dur=100ms, freq=880Hz, sample=79, buffer_id=14:4F
    db 0,0,100,0,91,120,7,0,117,5,91,2  ; n5534 t=301.164s dur=100ms, freq=1397Hz, sample=91, buffer_id=02:5B
    db 14,0,100,0,75,120,9,1,186,2,75,2  ; n5535 t=301.164s dur=100ms, freq=698Hz, sample=75, buffer_id=02:4B
    db 210,0,100,0,91,100,20,6,117,5,91,20  ; n5536 t=301.178s dur=100ms, freq=1397Hz, sample=91, buffer_id=14:5B
    db 19,0,100,0,65,110,4,3,93,1,65,4  ; n5537 t=301.388s dur=100ms, freq=349Hz, sample=65, buffer_id=04:41
    db 0,0,100,0,77,124,5,4,186,2,77,5  ; n5538 t=301.407s dur=100ms, freq=698Hz, sample=77, buffer_id=05:4D
    db 0,0,100,0,67,124,5,8,93,1,67,5  ; n5539 t=301.407s dur=100ms, freq=349Hz, sample=67, buffer_id=05:43
    db 95,0,100,0,65,124,14,9,93,1,65,14  ; n5540 t=301.407s dur=100ms, freq=349Hz, sample=65, buffer_id=0E:41
    db 19,0,100,0,65,110,4,0,93,1,65,4  ; n5541 t=301.502s dur=100ms, freq=349Hz, sample=65, buffer_id=04:41
    db 0,0,100,0,77,124,5,1,186,2,77,5  ; n5542 t=301.522s dur=100ms, freq=698Hz, sample=77, buffer_id=05:4D
    db 0,0,100,0,67,124,5,2,93,1,67,5  ; n5543 t=301.522s dur=100ms, freq=349Hz, sample=67, buffer_id=05:43
    db 95,0,100,0,65,124,14,5,93,1,65,14  ; n5544 t=301.522s dur=100ms, freq=349Hz, sample=65, buffer_id=0E:41
    db 19,0,100,0,65,110,4,6,93,1,65,4  ; n5545 t=301.617s dur=100ms, freq=349Hz, sample=65, buffer_id=04:41
    db 0,0,100,0,77,124,5,7,186,2,77,5  ; n5546 t=301.636s dur=100ms, freq=698Hz, sample=77, buffer_id=05:4D
    db 0,0,100,0,67,124,5,10,93,1,67,5  ; n5547 t=301.636s dur=100ms, freq=349Hz, sample=67, buffer_id=05:43
    db 210,0,100,0,65,124,14,11,93,1,65,14  ; n5548 t=301.636s dur=100ms, freq=349Hz, sample=65, buffer_id=0E:41
    db 0,0,250,4,70,110,4,0,159,1,70,4  ; n5549 t=301.846s dur=1274ms, freq=415Hz, sample=70, buffer_id=04:46
    db 0,0,250,4,60,110,4,1,6,1,60,4  ; n5550 t=301.846s dur=1274ms, freq=262Hz, sample=60, buffer_id=04:3C
    db 0,0,250,4,60,110,4,2,21,1,60,4  ; n5551 t=301.846s dur=1274ms, freq=277Hz, sample=60, buffer_id=04:3C
    db 19,0,250,4,65,110,4,4,93,1,65,4  ; n5552 t=301.846s dur=1274ms, freq=349Hz, sample=65, buffer_id=04:41
    db 0,0,251,4,77,124,5,3,186,2,77,5  ; n5553 t=301.865s dur=1275ms, freq=698Hz, sample=77, buffer_id=05:4D
    db 0,0,251,4,67,124,5,5,93,1,67,5  ; n5554 t=301.865s dur=1275ms, freq=349Hz, sample=67, buffer_id=05:43
    db 217,0,251,4,70,124,14,8,159,1,70,14  ; n5555 t=301.865s dur=1275ms, freq=415Hz, sample=70, buffer_id=0E:46
    db 0,0,101,0,84,120,7,6,23,4,84,2  ; n5556 t=302.082s dur=101ms, freq=1047Hz, sample=84, buffer_id=02:54
    db 14,0,101,0,72,120,9,7,11,2,72,2  ; n5557 t=302.082s dur=101ms, freq=523Hz, sample=72, buffer_id=02:48
    db 198,0,100,0,84,100,20,9,23,4,84,20  ; n5558 t=302.096s dur=100ms, freq=1047Hz, sample=84, buffer_id=14:54
    db 19,0,43,3,36,120,2,10,65,0,36,2  ; n5559 t=302.294s dur=811ms, freq=65Hz, sample=36, buffer_id=02:24
    db 0,0,101,0,79,120,7,11,63,3,79,2  ; n5560 t=302.314s dur=101ms, freq=831Hz, sample=79, buffer_id=02:4F
    db 14,0,101,0,67,120,9,12,159,1,67,2  ; n5561 t=302.314s dur=101ms, freq=415Hz, sample=67, buffer_id=02:43
    db 217,0,100,0,79,100,20,13,63,3,79,20  ; n5562 t=302.328s dur=100ms, freq=831Hz, sample=79, buffer_id=14:4F
    db 0,0,101,0,75,120,7,6,186,2,75,2  ; n5563 t=302.546s dur=101ms, freq=698Hz, sample=75, buffer_id=02:4B
    db 14,0,101,0,65,120,9,7,93,1,65,2  ; n5564 t=302.546s dur=101ms, freq=349Hz, sample=65, buffer_id=02:41
    db 217,0,100,0,75,100,20,9,186,2,75,20  ; n5565 t=302.560s dur=100ms, freq=698Hz, sample=75, buffer_id=14:4B
    db 0,0,101,0,84,120,7,11,23,4,84,2  ; n5566 t=302.777s dur=101ms, freq=1047Hz, sample=84, buffer_id=02:54
    db 14,0,101,0,72,120,9,12,11,2,72,2  ; n5567 t=302.777s dur=101ms, freq=523Hz, sample=72, buffer_id=02:48
    db 217,0,100,0,84,100,20,13,23,4,84,20  ; n5568 t=302.792s dur=100ms, freq=1047Hz, sample=84, buffer_id=14:54
    db 0,0,101,0,79,120,7,6,63,3,79,2  ; n5569 t=303.009s dur=101ms, freq=831Hz, sample=79, buffer_id=02:4F
    db 14,0,101,0,67,120,9,7,159,1,67,2  ; n5570 t=303.009s dur=101ms, freq=415Hz, sample=67, buffer_id=02:43
    db 198,0,100,0,79,100,20,9,63,3,79,20  ; n5571 t=303.024s dur=100ms, freq=831Hz, sample=79, buffer_id=14:4F
    db 14,0,173,0,36,120,2,11,65,0,36,2  ; n5572 t=303.222s dur=173ms, freq=65Hz, sample=36, buffer_id=02:24
    db 0,0,115,0,65,110,4,12,93,1,65,4  ; n5573 t=303.236s dur=115ms, freq=349Hz, sample=65, buffer_id=04:41
    db 0,0,115,0,55,110,4,13,208,0,55,4  ; n5574 t=303.236s dur=115ms, freq=208Hz, sample=55, buffer_id=04:37
    db 0,0,115,0,60,110,4,1,6,1,60,4  ; n5575 t=303.236s dur=115ms, freq=262Hz, sample=60, buffer_id=04:3C [TRUNCATE prev:ch1 @301845.6ms -> 303236.2ms]
    db 5,0,115,0,60,110,4,2,21,1,60,4  ; n5576 t=303.236s dur=115ms, freq=277Hz, sample=60, buffer_id=04:3C [TRUNCATE prev:ch2 @301845.6ms -> 303236.2ms]
    db 0,0,101,0,75,120,7,0,186,2,75,2  ; n5577 t=303.241s dur=101ms, freq=698Hz, sample=75, buffer_id=02:4B [TRUNCATE prev:ch0 @301845.6ms -> 303241.1ms]
    db 14,0,101,0,65,120,9,4,93,1,65,2  ; n5578 t=303.241s dur=101ms, freq=349Hz, sample=65, buffer_id=02:41 [TRUNCATE prev:ch4 @301845.6ms -> 303241.1ms]
    db 0,0,115,0,77,124,5,3,186,2,77,5  ; n5579 t=303.255s dur=115ms, freq=698Hz, sample=77, buffer_id=05:4D [TRUNCATE prev:ch3 @301864.6ms -> 303255.5ms]
    db 0,0,115,0,67,124,5,5,93,1,67,5  ; n5580 t=303.255s dur=115ms, freq=349Hz, sample=67, buffer_id=05:43 [TRUNCATE prev:ch5 @301864.6ms -> 303255.5ms]
    db 0,0,115,0,65,124,14,8,93,1,65,14  ; n5581 t=303.255s dur=115ms, freq=349Hz, sample=65, buffer_id=0E:41 [TRUNCATE prev:ch8 @301864.6ms -> 303255.5ms]
    db 217,0,100,0,75,100,20,10,186,2,75,20  ; n5582 t=303.255s dur=100ms, freq=698Hz, sample=75, buffer_id=14:4B [TRUNCATE prev:ch10 @302294.4ms -> 303255.5ms]
    db 0,0,101,0,84,120,7,6,85,4,84,2  ; n5583 t=303.473s dur=101ms, freq=1109Hz, sample=84, buffer_id=02:54
    db 14,0,101,0,73,120,9,7,42,2,73,2  ; n5584 t=303.473s dur=101ms, freq=554Hz, sample=73, buffer_id=02:49
    db 106,0,100,0,84,100,20,9,85,4,84,20  ; n5585 t=303.487s dur=100ms, freq=1109Hz, sample=84, buffer_id=14:54
    db 0,0,100,0,65,110,4,0,93,1,65,4  ; n5586 t=303.594s dur=100ms, freq=349Hz, sample=65, buffer_id=04:41
    db 0,0,100,0,55,110,4,1,208,0,55,4  ; n5587 t=303.594s dur=100ms, freq=208Hz, sample=55, buffer_id=04:37
    db 0,0,100,0,60,110,4,3,6,1,60,4  ; n5588 t=303.594s dur=100ms, freq=262Hz, sample=60, buffer_id=04:3C
    db 19,0,100,0,60,110,4,4,21,1,60,4  ; n5589 t=303.594s dur=100ms, freq=277Hz, sample=60, buffer_id=04:3C
    db 0,0,100,0,77,124,5,2,186,2,77,5  ; n5590 t=303.613s dur=100ms, freq=698Hz, sample=77, buffer_id=05:4D
    db 0,0,100,0,67,124,5,8,93,1,67,5  ; n5591 t=303.613s dur=100ms, freq=349Hz, sample=67, buffer_id=05:43
    db 87,0,100,0,65,124,14,5,93,1,65,14  ; n5592 t=303.613s dur=100ms, freq=349Hz, sample=65, buffer_id=0E:41
    db 0,0,239,2,70,110,4,10,210,1,70,4  ; n5593 t=303.700s dur=751ms, freq=466Hz, sample=70, buffer_id=04:46
    db 0,0,239,2,60,110,4,11,38,1,60,4  ; n5594 t=303.700s dur=751ms, freq=294Hz, sample=60, buffer_id=04:3C
    db 0,0,239,2,65,110,4,13,55,1,65,4  ; n5595 t=303.700s dur=751ms, freq=311Hz, sample=65, buffer_id=04:41
    db 19,0,239,2,65,110,4,12,136,1,65,4  ; n5596 t=303.700s dur=751ms, freq=392Hz, sample=65, buffer_id=04:41 [TRUNCATE prev:ch12 @303236.2ms -> 303699.9ms]
    db 0,0,239,2,77,124,5,2,186,2,77,5  ; n5597 t=303.719s dur=751ms, freq=698Hz, sample=77, buffer_id=05:4D [TRUNCATE prev:ch2 @303612.9ms -> 303719.2ms]
    db 0,0,239,2,67,124,5,8,93,1,67,5  ; n5598 t=303.719s dur=751ms, freq=349Hz, sample=67, buffer_id=05:43 [TRUNCATE prev:ch8 @303612.9ms -> 303719.2ms]
    db 221,0,239,2,70,124,14,6,210,1,70,14  ; n5599 t=303.719s dur=751ms, freq=466Hz, sample=70, buffer_id=0E:46 [TRUNCATE prev:ch6 @303472.9ms -> 303719.2ms]
    db 0,0,103,0,86,120,7,0,151,4,86,2  ; n5600 t=303.940s dur=103ms, freq=1175Hz, sample=86, buffer_id=02:56
    db 15,0,103,0,73,120,9,1,75,2,73,2  ; n5601 t=303.940s dur=103ms, freq=587Hz, sample=73, buffer_id=02:49
    db 201,0,100,0,84,100,20,3,151,4,84,20  ; n5602 t=303.955s dur=100ms, freq=1175Hz, sample=84, buffer_id=14:54
    db 20,0,59,3,36,120,2,4,65,0,36,2  ; n5603 t=304.156s dur=827ms, freq=65Hz, sample=36, buffer_id=02:24
    db 0,0,103,0,84,120,7,5,164,3,84,2  ; n5604 t=304.176s dur=103ms, freq=932Hz, sample=84, buffer_id=02:54
    db 15,0,103,0,71,120,9,7,210,1,71,2  ; n5605 t=304.176s dur=103ms, freq=466Hz, sample=71, buffer_id=02:47
    db 221,0,100,0,84,100,20,9,164,3,84,20  ; n5606 t=304.191s dur=100ms, freq=932Hz, sample=84, buffer_id=14:54 [TRUNCATE prev:ch9 @303487.4ms -> 304190.7ms]
    db 0,0,103,0,79,120,7,0,16,3,79,2  ; n5607 t=304.412s dur=103ms, freq=784Hz, sample=79, buffer_id=02:4F
    db 15,0,103,0,67,120,9,1,136,1,67,2  ; n5608 t=304.412s dur=103ms, freq=392Hz, sample=67, buffer_id=02:43
    db 216,0,100,0,79,100,20,3,16,3,79,20  ; n5609 t=304.426s dur=100ms, freq=784Hz, sample=79, buffer_id=14:4F
    db 0,0,249,2,65,110,4,5,136,1,65,4  ; n5610 t=304.642s dur=761ms, freq=392Hz, sample=65, buffer_id=04:41
    db 0,0,249,2,60,110,4,7,233,0,60,4  ; n5611 t=304.642s dur=761ms, freq=233Hz, sample=60, buffer_id=04:3C
    db 0,0,249,2,60,110,4,9,38,1,60,4  ; n5612 t=304.642s dur=761ms, freq=294Hz, sample=60, buffer_id=04:3C
    db 5,0,249,2,65,110,4,12,55,1,65,4  ; n5613 t=304.642s dur=761ms, freq=311Hz, sample=65, buffer_id=04:41 [TRUNCATE prev:ch12 @303699.9ms -> 304642.5ms]
    db 0,0,103,0,86,120,7,10,151,4,86,2  ; n5614 t=304.647s dur=103ms, freq=1175Hz, sample=86, buffer_id=02:56 [TRUNCATE prev:ch10 @303699.9ms -> 304647.4ms]
    db 15,0,103,0,73,120,9,11,75,2,73,2  ; n5615 t=304.647s dur=103ms, freq=587Hz, sample=73, buffer_id=02:49 [TRUNCATE prev:ch11 @303699.9ms -> 304647.4ms]
    db 0,0,249,2,77,124,5,13,186,2,77,5  ; n5616 t=304.662s dur=761ms, freq=698Hz, sample=77, buffer_id=05:4D
    db 0,0,249,2,67,124,5,8,93,1,67,5  ; n5617 t=304.662s dur=761ms, freq=349Hz, sample=67, buffer_id=05:43 [TRUNCATE prev:ch8 @303719.2ms -> 304662.1ms]
    db 0,0,249,2,65,124,14,2,136,1,65,14  ; n5618 t=304.662s dur=761ms, freq=392Hz, sample=65, buffer_id=0E:41 [TRUNCATE prev:ch2 @303719.2ms -> 304662.1ms]
    db 222,0,100,0,84,100,20,6,151,4,84,20  ; n5619 t=304.662s dur=100ms, freq=1175Hz, sample=84, buffer_id=14:54 [TRUNCATE prev:ch6 @303719.2ms -> 304662.1ms]
    db 0,0,103,0,84,120,7,0,164,3,84,2  ; n5620 t=304.885s dur=103ms, freq=932Hz, sample=84, buffer_id=02:54
    db 15,0,103,0,71,120,9,1,210,1,71,2  ; n5621 t=304.885s dur=103ms, freq=466Hz, sample=71, buffer_id=02:47
    db 203,0,100,0,84,100,20,3,164,3,84,20  ; n5622 t=304.899s dur=100ms, freq=932Hz, sample=84, buffer_id=14:54
    db 20,0,180,0,36,120,2,6,65,0,36,2  ; n5623 t=305.102s dur=180ms, freq=65Hz, sample=36, buffer_id=02:24
    db 0,0,105,0,79,120,7,10,16,3,79,2  ; n5624 t=305.122s dur=105ms, freq=784Hz, sample=79, buffer_id=02:4F
    db 15,0,105,0,67,120,9,11,136,1,67,2  ; n5625 t=305.122s dur=105ms, freq=392Hz, sample=67, buffer_id=02:43
    db 227,0,100,0,79,100,20,4,16,3,79,20  ; n5626 t=305.137s dur=100ms, freq=784Hz, sample=79, buffer_id=14:4F [TRUNCATE prev:ch4 @304156.3ms -> 305136.6ms]
    db 0,0,105,0,86,120,7,0,221,4,86,2  ; n5627 t=305.363s dur=105ms, freq=1245Hz, sample=86, buffer_id=02:56
    db 15,0,105,0,75,120,9,1,110,2,75,2  ; n5628 t=305.363s dur=105ms, freq=622Hz, sample=75, buffer_id=02:4B
    db 222,0,100,0,84,100,20,3,221,4,84,20  ; n5629 t=305.378s dur=100ms, freq=1245Hz, sample=84, buffer_id=14:54 [TRUNCATE prev:ch3 @304899.4ms -> 305378.5ms]
    db 0,0,151,8,70,110,4,4,11,2,70,4  ; n5630 t=305.600s dur=2199ms, freq=523Hz, sample=70, buffer_id=04:46
    db 0,0,151,8,65,110,4,6,74,1,65,4  ; n5631 t=305.600s dur=2199ms, freq=330Hz, sample=65, buffer_id=04:41
    db 0,0,151,8,65,110,4,10,93,1,65,4  ; n5632 t=305.600s dur=2199ms, freq=349Hz, sample=65, buffer_id=04:41
    db 20,0,151,8,70,110,4,11,184,1,70,4  ; n5633 t=305.600s dur=2199ms, freq=440Hz, sample=70, buffer_id=04:46
    db 0,0,150,8,77,124,5,5,186,2,77,5  ; n5634 t=305.620s dur=2198ms, freq=698Hz, sample=77, buffer_id=05:4D
    db 0,0,150,8,67,124,5,7,93,1,67,5  ; n5635 t=305.620s dur=2198ms, freq=349Hz, sample=67, buffer_id=05:43
    db 228,0,150,8,70,124,14,9,11,2,70,14  ; n5636 t=305.620s dur=2198ms, freq=523Hz, sample=70, buffer_id=0E:46
    db 0,0,106,0,91,120,7,0,117,5,91,2  ; n5637 t=305.848s dur=106ms, freq=1397Hz, sample=91, buffer_id=02:5B
    db 223,0,106,0,75,120,9,2,186,2,75,2  ; n5638 t=305.848s dur=106ms, freq=698Hz, sample=75, buffer_id=02:4B
    db 20,0,184,0,41,120,2,1,87,0,41,2  ; n5639 t=306.071s dur=184ms, freq=87Hz, sample=41, buffer_id=02:29
    db 0,0,107,0,84,120,7,3,23,4,84,2  ; n5640 t=306.091s dur=107ms, freq=1047Hz, sample=84, buffer_id=02:54
    db 246,0,107,0,72,120,9,8,11,2,72,2  ; n5641 t=306.091s dur=107ms, freq=523Hz, sample=72, buffer_id=02:48
    db 0,0,107,0,79,120,7,0,112,3,79,2  ; n5642 t=306.337s dur=107ms, freq=880Hz, sample=79, buffer_id=02:4F
    db 226,0,107,0,67,120,9,2,184,1,67,2  ; n5643 t=306.337s dur=107ms, freq=440Hz, sample=67, buffer_id=02:43
    db 21,0,185,0,36,120,2,1,65,0,36,2  ; n5644 t=306.563s dur=185ms, freq=65Hz, sample=36, buffer_id=02:24
    db 0,0,108,0,91,120,7,3,117,5,91,2  ; n5645 t=306.584s dur=108ms, freq=1397Hz, sample=91, buffer_id=02:5B
    db 247,0,108,0,75,120,9,8,186,2,75,2  ; n5646 t=306.584s dur=108ms, freq=698Hz, sample=75, buffer_id=02:4B
    db 0,0,108,0,84,120,7,0,23,4,84,2  ; n5647 t=306.830s dur=108ms, freq=1047Hz, sample=84, buffer_id=02:54
    db 226,0,108,0,72,120,9,2,11,2,72,2  ; n5648 t=306.830s dur=108ms, freq=523Hz, sample=72, buffer_id=02:48
    db 20,0,186,0,36,120,2,3,65,0,36,2  ; n5649 t=307.057s dur=186ms, freq=65Hz, sample=36, buffer_id=02:24
    db 0,0,100,0,75,120,7,1,186,2,75,2  ; n5650 t=307.077s dur=100ms, freq=698Hz, sample=75, buffer_id=02:4B
    db 67,0,100,0,65,120,9,8,93,1,65,2  ; n5651 t=307.077s dur=100ms, freq=349Hz, sample=65, buffer_id=02:41
    db 0,0,100,0,79,120,7,0,16,3,79,2  ; n5652 t=307.144s dur=100ms, freq=784Hz, sample=79, buffer_id=02:4F
    db 72,0,100,0,67,120,9,2,136,1,67,2  ; n5653 t=307.144s dur=100ms, freq=392Hz, sample=67, buffer_id=02:43
    db 0,0,100,0,79,120,7,12,112,3,79,2  ; n5654 t=307.217s dur=100ms, freq=880Hz, sample=79, buffer_id=02:4F
    db 72,0,100,0,67,120,9,13,184,1,67,2  ; n5655 t=307.217s dur=100ms, freq=440Hz, sample=67, buffer_id=02:43
    db 0,0,100,0,84,120,7,4,164,3,84,2  ; n5656 t=307.289s dur=100ms, freq=932Hz, sample=84, buffer_id=02:54 [TRUNCATE prev:ch4 @305600.3ms -> 307289.3ms]
    db 67,0,100,0,71,120,9,6,210,1,71,2  ; n5657 t=307.289s dur=100ms, freq=466Hz, sample=71, buffer_id=02:47 [TRUNCATE prev:ch6 @305600.3ms -> 307289.3ms]
    db 0,0,100,0,84,120,7,10,23,4,84,2  ; n5658 t=307.356s dur=100ms, freq=1047Hz, sample=84, buffer_id=02:54 [TRUNCATE prev:ch10 @305600.3ms -> 307356.5ms]
    db 72,0,100,0,72,120,9,11,11,2,72,2  ; n5659 t=307.356s dur=100ms, freq=523Hz, sample=72, buffer_id=02:48 [TRUNCATE prev:ch11 @305600.3ms -> 307356.5ms]
    db 0,0,100,0,86,120,7,1,151,4,86,2  ; n5660 t=307.429s dur=100ms, freq=1175Hz, sample=86, buffer_id=02:56
    db 72,0,100,0,73,120,9,8,75,2,73,2  ; n5661 t=307.429s dur=100ms, freq=587Hz, sample=73, buffer_id=02:49
    db 0,0,100,0,86,120,7,0,39,5,86,2  ; n5662 t=307.501s dur=100ms, freq=1319Hz, sample=86, buffer_id=02:56
    db 52,0,100,0,75,120,9,2,147,2,75,2  ; n5663 t=307.501s dur=100ms, freq=659Hz, sample=75, buffer_id=02:4B
    db 21,0,175,0,41,120,2,3,87,0,41,2  ; n5664 t=307.553s dur=175ms, freq=87Hz, sample=41, buffer_id=02:29
    db 0,0,116,0,91,120,7,12,117,5,91,2  ; n5665 t=307.574s dur=116ms, freq=1397Hz, sample=91, buffer_id=02:5B
    db 186,1,116,0,75,120,9,13,186,2,75,2  ; n5666 t=307.574s dur=116ms, freq=698Hz, sample=75, buffer_id=02:4B
    db 10,0,100,0,29,120,2,0,44,0,29,2  ; n5667 t=308.016s dur=100ms, freq=44Hz, sample=29, buffer_id=02:1D
    db 0,0,100,0,53,120,11,1,175,0,53,2  ; n5668 t=308.025s dur=100ms, freq=175Hz, sample=53, buffer_id=02:35
    db 0,0,100,0,41,115,13,2,87,0,41,2  ; n5669 t=308.025s dur=100ms, freq=87Hz, sample=41, buffer_id=02:29
    db 0,0,100,0,53,100,18,3,175,0,53,18  ; n5670 t=308.025s dur=100ms, freq=175Hz, sample=53, buffer_id=12:35
    db 10,0,100,0,41,100,19,4,87,0,41,19  ; n5671 t=308.025s dur=100ms, freq=87Hz, sample=41, buffer_id=13:29
    db 105,0,100,0,65,120,7,5,93,1,65,2  ; n5672 t=308.035s dur=100ms, freq=349Hz, sample=65, buffer_id=02:41
    db 0,0,100,0,53,120,11,6,175,0,53,2  ; n5673 t=308.140s dur=100ms, freq=175Hz, sample=53, buffer_id=02:35
    db 0,0,100,0,41,115,13,7,87,0,41,2  ; n5674 t=308.140s dur=100ms, freq=87Hz, sample=41, buffer_id=02:29
    db 0,0,100,0,53,100,18,8,175,0,53,18  ; n5675 t=308.140s dur=100ms, freq=175Hz, sample=53, buffer_id=12:35
    db 10,0,100,0,41,100,19,9,87,0,41,19  ; n5676 t=308.140s dur=100ms, freq=87Hz, sample=41, buffer_id=13:29
    db 96,0,100,0,65,120,7,10,93,1,65,2  ; n5677 t=308.150s dur=100ms, freq=349Hz, sample=65, buffer_id=02:41
    db 10,0,100,0,29,120,2,11,44,0,29,2  ; n5678 t=308.246s dur=100ms, freq=44Hz, sample=29, buffer_id=02:1D
    db 0,0,100,0,53,120,11,12,175,0,53,2  ; n5679 t=308.255s dur=100ms, freq=175Hz, sample=53, buffer_id=02:35
    db 0,0,100,0,41,115,13,13,87,0,41,2  ; n5680 t=308.255s dur=100ms, freq=87Hz, sample=41, buffer_id=02:29
    db 0,0,100,0,53,100,18,3,175,0,53,18  ; n5681 t=308.255s dur=100ms, freq=175Hz, sample=53, buffer_id=12:35 [TRUNCATE prev:ch3 @308025.2ms -> 308255.2ms]
    db 10,0,100,0,41,100,19,4,87,0,41,19  ; n5682 t=308.255s dur=100ms, freq=87Hz, sample=41, buffer_id=13:29 [TRUNCATE prev:ch4 @308025.2ms -> 308255.2ms]
    db 105,0,100,0,65,120,7,5,93,1,65,2  ; n5683 t=308.265s dur=100ms, freq=349Hz, sample=65, buffer_id=02:41 [TRUNCATE prev:ch5 @308034.8ms -> 308264.8ms]
    db 0,0,100,0,53,120,11,0,175,0,53,2  ; n5684 t=308.370s dur=100ms, freq=175Hz, sample=53, buffer_id=02:35
    db 0,0,100,0,41,115,13,1,87,0,41,2  ; n5685 t=308.370s dur=100ms, freq=87Hz, sample=41, buffer_id=02:29
    db 0,0,100,0,53,100,18,2,175,0,53,18  ; n5686 t=308.370s dur=100ms, freq=175Hz, sample=53, buffer_id=12:35
    db 10,0,100,0,41,100,19,9,87,0,41,19  ; n5687 t=308.370s dur=100ms, freq=87Hz, sample=41, buffer_id=13:29 [TRUNCATE prev:ch9 @308140.2ms -> 308370.2ms]
    db 96,0,100,0,65,120,7,10,93,1,65,2  ; n5688 t=308.380s dur=100ms, freq=349Hz, sample=65, buffer_id=02:41 [TRUNCATE prev:ch10 @308149.8ms -> 308379.8ms]
    db 10,0,100,0,29,120,2,6,44,0,29,2  ; n5689 t=308.476s dur=100ms, freq=44Hz, sample=29, buffer_id=02:1D
    db 0,0,100,0,53,120,11,7,175,0,53,2  ; n5690 t=308.485s dur=100ms, freq=175Hz, sample=53, buffer_id=02:35
    db 0,0,100,0,41,115,13,8,87,0,41,2  ; n5691 t=308.485s dur=100ms, freq=87Hz, sample=41, buffer_id=02:29
    db 0,0,100,0,53,100,18,3,175,0,53,18  ; n5692 t=308.485s dur=100ms, freq=175Hz, sample=53, buffer_id=12:35 [TRUNCATE prev:ch3 @308255.2ms -> 308485.2ms]
    db 10,0,100,0,41,100,19,4,87,0,41,19  ; n5693 t=308.485s dur=100ms, freq=87Hz, sample=41, buffer_id=13:29 [TRUNCATE prev:ch4 @308255.2ms -> 308485.2ms]
    db 0,0,100,0,65,120,7,5,93,1,65,2  ; n5694 t=308.495s dur=100ms, freq=349Hz, sample=65, buffer_id=02:41 [TRUNCATE prev:ch5 @308264.8ms -> 308494.7ms]
    db 255,255,255,255,255,255,255,255,255,255,255,255  ; End marker

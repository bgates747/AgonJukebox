; Piano note data with dynamic channel assignment

; Field offsets:
;   tnext_lo    equ 0    ; next-note dt low byte
;   tnext_hi    equ 1    ; next-note dt high byte
;   duration_lo equ 2    ; duration low byte
;   duration_hi equ 3    ; duration high byte
;   sample_pitch equ 4   ; MIDI pitch of sample file
;   velocity    equ 5    ; MIDI velocity
;   instrument  equ 6    ; instrument ID
;   channel     equ 7    ; Agon channel (0–31)
;   freq_lo     equ 8    ; note frequency low byte
;   freq_hi     equ 9    ; note frequency high byte

; Total notes: 2048

midi_data:
; t 0.0000 Soft 127 (Instr 1)
; t 0.0000 Soft 127 (Instr 2)
    db 12,0,102,12,33,27,1,0,69,0  ; n1 t=0.783s dur=3174ms, vel 39->27, sust 1728->3174, freq=69Hz, sample=33
    db 20,0,102,12,45,27,1,1,139,0  ; n2 t=0.795s dur=3174ms, vel 39->27, sust 2263->3174, freq=139Hz, sample=45
    db 123,1,237,15,57,27,1,2,208,0  ; n3 t=0.815s dur=4077ms, vel 39->27, sust 766->4077, freq=208Hz, sample=57
; t 0.8432 Sustain 127 (Instr 1)
; t 0.8432 Sustain 127 (Instr 2)
    db 83,1,102,12,57,23,1,3,21,1  ; n4 t=1.194s dur=3174ms, vel 34->23, sust 412->3174, freq=277Hz, sample=57
    db 106,1,31,13,69,23,1,4,74,1  ; n5 t=1.533s dur=3359ms, vel 33->23, sust 460->3359, freq=330Hz, sample=69
    db 104,1,181,11,57,23,1,5,208,0  ; n6 t=1.895s dur=2997ms, vel 33->23, sust 724->2997, freq=208Hz, sample=57
    db 41,1,77,10,57,23,1,6,21,1  ; n7 t=2.254s dur=2637ms, vel 33->23, sust 358->2637, freq=277Hz, sample=57
    db 87,1,36,9,69,23,1,7,74,1  ; n8 t=2.551s dur=2340ms, vel 33->23, sust 525->2340, freq=330Hz, sample=69
    db 80,1,205,7,57,23,1,8,208,0  ; n9 t=2.895s dur=1997ms, vel 33->23, sust 728->1997, freq=208Hz, sample=57
    db 70,1,125,6,57,23,1,9,21,1  ; n10 t=3.230s dur=1661ms, vel 33->23, sust 372->1661, freq=277Hz, sample=57
    db 94,1,56,5,69,23,1,10,74,1  ; n11 t=3.556s dur=1336ms, vel 33->23, sust 693->1336, freq=330Hz, sample=69
    db 91,1,218,3,57,23,1,11,208,0  ; n12 t=3.906s dur=986ms, vel 33->23, sust 724->986, freq=208Hz, sample=57
    db 60,1,127,2,57,23,1,12,21,1  ; n13 t=4.253s dur=639ms, vel 33->23, sust 382->639, freq=277Hz, sample=57
    db 203,0,160,1,69,23,1,13,74,1  ; n14 t=4.569s dur=416ms, vel 33->23, freq=330Hz, sample=69
    db 10,0,235,13,33,28,1,14,62,0  ; n15 t=4.772s dur=3563ms, vel 41->28, sust 1774->3563, freq=62Hz, sample=33
    db 124,0,235,13,45,28,1,15,123,0  ; n16 t=4.782s dur=3563ms, vel 41->28, sust 2226->3563, freq=123Hz, sample=45
; t 4.8922 Sustain 0 (Instr 1)
; t 4.8922 Sustain 0 (Instr 2)
    db 100,1,60,16,57,23,1,16,208,0  ; n17 t=4.905s dur=4156ms, vel 33->23, sust 890->4156, freq=208Hz, sample=57
; t 5.2002 Sustain 127 (Instr 1)
; t 5.2002 Sustain 127 (Instr 2)
    db 99,1,102,12,57,23,1,17,21,1  ; n18 t=5.261s dur=3174ms, vel 33->23, sust 436->3174, freq=277Hz, sample=57
    db 68,1,117,13,69,23,1,18,74,1  ; n19 t=5.617s dur=3445ms, vel 33->23, sust 742->3445, freq=330Hz, sample=69
; t 5.7701 Soft 0 (Instr 1)
; t 5.7701 Soft 0 (Instr 2)
    db 120,1,49,12,57,33,1,19,208,0  ; n20 t=5.941s dur=3121ms, sust 911->3121, freq=208Hz, sample=57
    db 63,1,185,10,57,33,1,20,21,1  ; n21 t=6.317s dur=2745ms, sust 457->2745, freq=277Hz, sample=57
    db 86,1,122,9,69,33,1,21,74,1  ; n22 t=6.636s dur=2426ms, sust 721->2426, freq=330Hz, sample=69
    db 94,1,36,8,57,33,1,22,208,0  ; n23 t=6.978s dur=2084ms, sust 909->2084, freq=208Hz, sample=57
    db 78,1,198,6,57,33,1,23,21,1  ; n24 t=7.328s dur=1734ms, sust 455->1734, freq=277Hz, sample=57
    db 128,1,120,5,69,33,1,24,74,1  ; n25 t=7.662s dur=1400ms, sust 984->1400, freq=330Hz, sample=69
    db 74,1,248,3,57,33,1,25,208,0  ; n26 t=8.045s dur=1016ms, sust 552->1016, freq=208Hz, sample=57
    db 115,1,175,2,57,33,1,26,21,1  ; n27 t=8.375s dur=687ms, sust 624->687, freq=277Hz, sample=57
    db 220,0,104,2,69,34,1,27,74,1  ; n28 t=8.747s dur=616ms, freq=330Hz, sample=69
    db 32,0,32,9,33,37,1,28,55,0  ; n29 t=8.967s dur=2336ms, sust 1349->2336, freq=55Hz, sample=33
    db 128,0,1,9,45,37,1,29,110,0  ; n30 t=8.999s dur=2305ms, sust 1270->2305, freq=110Hz, sample=45
; t 9.0622 Sustain 0 (Instr 1)
; t 9.0622 Sustain 0 (Instr 2)
    db 114,1,129,8,57,36,1,30,220,0  ; n31 t=9.127s dur=2177ms, sust 798->2177, freq=220Hz, sample=57
    db 125,1,14,7,57,33,1,31,21,1  ; n32 t=9.497s dur=1806ms, sust 452->1806, freq=277Hz, sample=57
; t 9.5026 Sustain 127 (Instr 1)
; t 9.5026 Sustain 127 (Instr 2)
    db 74,1,145,5,69,33,1,0,74,1  ; n33 t=9.878s dur=1425ms, sust 583->1425, freq=330Hz, sample=69
    db 79,1,71,4,57,33,1,1,220,0  ; n34 t=10.208s dur=1095ms, sust 779->1095, freq=220Hz, sample=57
    db 135,1,248,2,57,33,1,2,21,1  ; n35 t=10.543s dur=760ms, sust 508->760, freq=277Hz, sample=57
    db 23,1,186,1,69,33,1,3,74,1  ; n36 t=10.935s dur=442ms, freq=330Hz, sample=69
    db 19,0,146,9,33,35,1,4,46,0  ; n37 t=11.214s dur=2450ms, sust 1033->2450, freq=46Hz, sample=33
    db 78,0,127,9,45,35,1,5,92,0  ; n38 t=11.233s dur=2431ms, sust 1037->2431, freq=92Hz, sample=45
; t 11.3038 Sustain 0 (Instr 1)
; t 11.3038 Sustain 0 (Instr 2)
    db 127,1,49,9,57,34,1,6,220,0  ; n39 t=11.310s dur=2353ms, sust 480->2353, freq=220Hz, sample=57
    db 102,1,178,7,57,33,1,7,38,1  ; n40 t=11.694s dur=1970ms, sust 414->1970, freq=294Hz, sample=57
; t 11.7683 Sustain 127 (Instr 1)
; t 11.7683 Sustain 127 (Instr 2)
; t 11.8177 Soft 127 (Instr 1)
; t 11.8177 Soft 127 (Instr 2)
    db 139,1,76,6,69,23,1,8,114,1  ; n41 t=12.052s dur=1612ms, vel 33->23, sust 833->1612, freq=370Hz, sample=69
    db 117,1,192,4,57,23,1,9,220,0  ; n42 t=12.447s dur=1216ms, vel 33->23, sust 458->1216, freq=220Hz, sample=57
    db 143,1,75,3,57,23,1,10,38,1  ; n43 t=12.821s dur=843ms, vel 33->23, sust 429->843, freq=294Hz, sample=57
    db 83,1,188,1,69,23,1,11,114,1  ; n44 t=13.220s dur=444ms, vel 33->23, sust 442->444, freq=370Hz, sample=69
    db 13,0,157,9,33,24,1,12,52,0  ; n45 t=13.559s dur=2461ms, vel 35->24, sust 2228->2461, freq=52Hz, sample=33
    db 83,0,144,9,45,24,1,13,104,0  ; n46 t=13.572s dur=2448ms, vel 35->24, sust 2180->2448, freq=104Hz, sample=45
    db 136,1,190,1,57,23,1,14,208,0  ; n47 t=13.655s dur=446ms, vel 34->23, freq=208Hz, sample=57
; t 13.6641 Sustain 0 (Instr 1)
; t 13.6641 Sustain 0 (Instr 2)
    db 127,1,163,4,57,23,1,15,6,1  ; n48 t=14.047s dur=1187ms, vel 33->23, sust 445->1187, freq=262Hz, sample=57
; t 14.1668 Sustain 127 (Instr 1)
; t 14.1668 Sustain 127 (Instr 2)
    db 99,1,35,3,69,23,1,16,114,1  ; n49 t=14.431s dur=803ms, vel 33->23, sust 407->803, freq=370Hz, sample=69
    db 144,1,211,4,57,23,1,17,208,0  ; n50 t=14.786s dur=1235ms, vel 33->23, sust 901->1235, freq=208Hz, sample=57
    db 100,1,67,3,57,23,1,18,21,1  ; n51 t=15.185s dur=835ms, vel 33->23, sust 468->835, freq=277Hz, sample=57
; t 15.2346 Sustain 0 (Instr 1)
; t 15.2346 Sustain 0 (Instr 2)
    db 101,1,223,1,69,23,1,19,74,1  ; n52 t=15.541s dur=479ms, vel 33->23, sust 478->479, freq=330Hz, sample=69
; t 15.5566 Sustain 127 (Instr 1)
; t 15.5566 Sustain 127 (Instr 2)
    db 12,0,183,11,33,24,1,20,52,0  ; n53 t=15.898s dur=2999ms, vel 35->24, sust 2596->2999, freq=52Hz, sample=33
    db 44,0,171,11,45,24,1,21,104,0  ; n54 t=15.910s dur=2987ms, vel 35->24, sust 2639->2987, freq=104Hz, sample=45
    db 181,1,65,5,57,24,1,22,208,0  ; n55 t=15.954s dur=1345ms, vel 35->24, sust 1092->1345, freq=208Hz, sample=57
; t 16.0209 Sustain 0 (Instr 1)
; t 16.0209 Sustain 0 (Instr 2)
    db 195,1,255,1,57,23,1,23,21,1  ; n56 t=16.391s dur=511ms, vel 33->23, freq=277Hz, sample=57
    db 204,1,8,2,57,23,1,24,55,1  ; n57 t=16.842s dur=520ms, vel 33->23, freq=311Hz, sample=57
; t 16.9032 Sustain 127 (Instr 1)
; t 16.9032 Sustain 127 (Instr 2)
; t 17.2995 Sustain 0 (Instr 1)
; t 17.2995 Sustain 0 (Instr 2)
    db 235,1,60,6,57,23,1,25,185,0  ; n58 t=17.302s dur=1596ms, vel 33->23, sust 1331->1596, freq=185Hz, sample=57
; t 17.5064 Sustain 127 (Instr 1)
; t 17.5064 Sustain 127 (Instr 2)
    db 14,2,9,2,57,23,1,26,6,1  ; n59 t=17.793s dur=521ms, vel 33->23, freq=262Hz, sample=57
; t 17.8556 Sustain 0 (Instr 1)
; t 17.8556 Sustain 0 (Instr 2)
    db 231,1,67,2,57,23,1,27,55,1  ; n60 t=18.319s dur=579ms, vel 33->23, sust 268->579, freq=311Hz, sample=57
; t 18.3800 Sustain 127 (Instr 1)
; t 18.3800 Sustain 127 (Instr 2)
    db 25,0,102,12,33,23,1,28,69,0  ; n61 t=18.806s dur=3174ms, vel 33->23, sust 1577->3174, freq=69Hz, sample=33
    db 0,0,141,16,45,23,1,29,104,0  ; n62 t=18.831s dur=4237ms, vel 33->23, sust 1792->4237, freq=104Hz, sample=45
    db 94,0,102,12,45,23,1,30,139,0  ; n63 t=18.831s dur=3174ms, vel 33->23, sust 2250->3174, freq=139Hz, sample=45
; t 18.8978 Sustain 0 (Instr 1)
; t 18.8978 Sustain 0 (Instr 2)
    db 165,1,141,20,57,23,1,31,165,0  ; n64 t=18.925s dur=5261ms, vel 33->23, sust 489->5261, freq=165Hz, sample=57
; t 19.3390 Sustain 127 (Instr 1)
; t 19.3390 Sustain 127 (Instr 2)
    db 147,1,141,16,57,23,1,0,208,0  ; n65 t=19.347s dur=4237ms, vel 33->23, sust 500->4237, freq=208Hz, sample=57
    db 123,1,102,12,57,23,1,1,21,1  ; n66 t=19.750s dur=3174ms, vel 33->23, sust 496->3174, freq=277Hz, sample=57
    db 146,1,218,15,57,23,1,2,208,0  ; n67 t=20.128s dur=4058ms, vel 33->23, sust 849->4058, freq=208Hz, sample=57
    db 130,1,102,12,57,23,1,3,21,1  ; n68 t=20.530s dur=3174ms, vel 33->23, sust 859->3174, freq=277Hz, sample=57
    db 105,1,198,12,69,23,1,4,74,1  ; n69 t=20.916s dur=3270ms, vel 33->23, sust 487->3270, freq=330Hz, sample=69
    db 165,1,93,11,57,23,1,5,208,0  ; n70 t=21.277s dur=2909ms, vel 33->23, sust 817->2909, freq=208Hz, sample=57
    db 124,1,184,9,57,23,1,6,21,1  ; n71 t=21.698s dur=2488ms, vel 33->23, sust 984->2488, freq=277Hz, sample=57
    db 0,2,60,8,69,23,1,7,74,1  ; n72 t=22.078s dur=2108ms, vel 33->23, sust 598->2108, freq=330Hz, sample=69
    db 11,0,60,6,57,27,1,8,208,0  ; n73 t=22.590s dur=1596ms, vel 39->27, sust 823->1596, freq=208Hz, sample=57
    db 18,2,49,6,69,34,2,9,159,1  ; n74 t=22.601s dur=1585ms, vel 49->34, sust 979->1585, freq=415Hz, sample=69
    db 153,1,31,4,57,23,1,10,21,1  ; n75 t=23.131s dur=1055ms, vel 33->23, sust 483->1055, freq=277Hz, sample=57
    db 163,1,134,2,69,23,1,11,74,1  ; n76 t=23.540s dur=646ms, vel 33->23, sust 152->646, freq=330Hz, sample=69
    db 213,0,227,0,69,30,2,12,159,1  ; n77 t=23.959s dur=227ms, vel 44->30, sust 146->227, freq=415Hz, sample=69
    db 1,0,237,13,69,32,2,13,159,1  ; n78 t=24.172s dur=3565ms, vel 47->32, sust 3128->3565, freq=415Hz, sample=69
    db 6,0,35,13,45,28,1,14,131,0  ; n79 t=24.174s dur=3363ms, vel 40->28, sust 4194->3363, freq=131Hz, sample=45
    db 0,0,230,13,57,28,1,15,208,0  ; n80 t=24.180s dur=3558ms, vel 40->28, sust 947->3558, freq=208Hz, sample=57
    db 7,0,35,13,33,28,1,16,65,0  ; n81 t=24.180s dur=3363ms, vel 40->28, sust 4208->3363, freq=65Hz, sample=33
    db 181,1,141,16,45,28,1,17,104,0  ; n82 t=24.187s dur=4237ms, vel 40->28, sust 4226->4237, freq=104Hz, sample=45
; t 24.1867 Sustain 0 (Instr 1)
; t 24.1867 Sustain 0 (Instr 2)
    db 166,1,12,11,57,24,1,18,55,1  ; n83 t=24.623s dur=2828ms, vel 35->24, sust 846->2828, freq=311Hz, sample=57
; t 24.6483 Sustain 127 (Instr 1)
; t 24.6483 Sustain 127 (Instr 2)
    db 95,1,132,10,69,23,1,19,114,1  ; n84 t=25.045s dur=2692ms, vel 33->23, sust 784->2692, freq=370Hz, sample=69
    db 119,1,37,9,57,23,1,20,208,0  ; n85 t=25.396s dur=2341ms, vel 33->23, sust 852->2341, freq=208Hz, sample=57
    db 128,1,174,7,57,23,1,21,55,1  ; n86 t=25.772s dur=1966ms, vel 33->23, sust 817->1966, freq=311Hz, sample=57
    db 92,1,46,6,69,23,1,22,114,1  ; n87 t=26.156s dur=1582ms, vel 33->23, sust 810->1582, freq=370Hz, sample=69
    db 153,1,210,4,57,23,1,23,208,0  ; n88 t=26.503s dur=1234ms, vel 33->23, sust 830->1234, freq=208Hz, sample=57
    db 118,1,57,3,57,23,1,24,55,1  ; n89 t=26.913s dur=825ms, vel 33->23, sust 616->825, freq=311Hz, sample=57
    db 190,1,237,1,69,23,1,25,114,1  ; n90 t=27.287s dur=493ms, vel 33->23, freq=370Hz, sample=69
    db 20,0,86,5,69,33,2,26,159,1  ; n91 t=27.733s dur=1366ms, vel 48->33, sust 810->1366, freq=415Hz, sample=69
; t 27.7384 Sustain 0 (Instr 1)
; t 27.7384 Sustain 0 (Instr 2)
    db 164,1,67,5,57,26,1,27,208,0  ; n92 t=27.753s dur=1347ms, vel 38->26, sust 706->1347, freq=208Hz, sample=57
; t 28.0785 Sustain 127 (Instr 1)
; t 28.0785 Sustain 127 (Instr 2)
    db 144,1,159,3,57,23,1,28,55,1  ; n93 t=28.172s dur=927ms, vel 33->23, sust 409->927, freq=311Hz, sample=57
    db 255,0,14,2,69,23,1,29,114,1  ; n94 t=28.573s dur=526ms, vel 33->23, sust 302->526, freq=370Hz, sample=69
    db 233,0,16,1,69,28,2,30,159,1  ; n95 t=28.828s dur=272ms, vel 40->28, sust 158->272, freq=415Hz, sample=69
    db 6,0,132,9,57,25,1,31,208,0  ; n96 t=29.060s dur=2436ms, vel 36->25, sust 960->2436, freq=208Hz, sample=57
    db 4,0,125,9,45,25,1,0,139,0  ; n97 t=29.067s dur=2429ms, vel 36->25, sust 869->2429, freq=139Hz, sample=45
    db 3,0,121,9,69,30,2,1,159,1  ; n98 t=29.071s dur=2425ms, vel 44->30, sust 1167->2425, freq=415Hz, sample=69
    db 164,1,117,9,33,25,1,2,69,0  ; n99 t=29.075s dur=2421ms, vel 36->25, sust 1216->2421, freq=69Hz, sample=33
; t 29.0997 Sustain 0 (Instr 1)
; t 29.0997 Sustain 0 (Instr 2)
; t 29.4627 Sustain 127 (Instr 1)
; t 29.4627 Sustain 127 (Instr 2)
    db 190,1,210,7,57,23,1,3,21,1  ; n100 t=29.494s dur=2002ms, vel 33->23, sust 879->2002, freq=277Hz, sample=57
    db 98,1,19,6,69,23,1,4,74,1  ; n101 t=29.941s dur=1555ms, vel 34->23, sust 460->1555, freq=330Hz, sample=69
    db 154,1,177,4,57,25,1,5,208,0  ; n102 t=30.295s dur=1201ms, vel 36->25, sust 970->1201, freq=208Hz, sample=57
    db 127,1,167,3,57,23,1,6,21,1  ; n103 t=30.705s dur=935ms, vel 34->23, freq=277Hz, sample=57
    db 63,1,226,1,69,26,1,7,74,1  ; n104 t=31.088s dur=482ms, vel 38->26, freq=330Hz, sample=69
    db 44,0,116,10,33,29,1,8,46,0  ; n105 t=31.407s dur=2676ms, vel 42->29, sust 1230->2676, freq=46Hz, sample=33
    db 97,0,72,10,45,30,1,9,92,0  ; n106 t=31.451s dur=2632ms, vel 43->30, sust 1185->2632, freq=92Hz, sample=45
; t 31.4965 Sustain 0 (Instr 1)
; t 31.4965 Sustain 0 (Instr 2)
    db 12,0,231,9,57,30,1,10,220,0  ; n107 t=31.548s dur=2535ms, vel 44->30, sust 958->2535, freq=220Hz, sample=57
    db 152,1,219,9,69,42,2,11,184,1  ; n108 t=31.560s dur=2523ms, vel 61->42, sust 1156->2523, freq=440Hz, sample=69
    db 191,1,67,8,57,27,1,12,21,1  ; n109 t=31.968s dur=2115ms, vel 39->27, sust 879->2115, freq=277Hz, sample=57
; t 32.0332 Sustain 127 (Instr 1)
; t 32.0332 Sustain 127 (Instr 2)
    db 148,1,132,6,69,23,1,13,114,1  ; n110 t=32.415s dur=1668ms, vel 33->23, sust 893->1668, freq=370Hz, sample=69
    db 122,1,240,4,57,23,1,14,220,0  ; n111 t=32.819s dur=1264ms, vel 33->23, sust 970->1264, freq=220Hz, sample=57
    db 183,1,118,3,57,23,1,15,21,1  ; n112 t=33.197s dur=886ms, vel 33->23, sust 657->886, freq=277Hz, sample=57
    db 252,1,190,1,69,23,1,16,114,1  ; n113 t=33.637s dur=446ms, vel 33->23, sust 243->446, freq=370Hz, sample=69
; t 34.0836 Sustain 0 (Instr 1)
; t 34.0836 Sustain 0 (Instr 2)
    db 4,0,33,10,33,25,1,17,62,0  ; n114 t=34.145s dur=2593ms, vel 37->25, sust 1961->2593, freq=62Hz, sample=33
    db 7,0,28,10,45,25,1,18,123,0  ; n115 t=34.149s dur=2588ms, vel 37->25, sust 918->2588, freq=123Hz, sample=45
    db 4,0,22,10,57,25,1,19,208,0  ; n116 t=34.156s dur=2582ms, vel 37->25, sust 905->2582, freq=208Hz, sample=57
    db 166,1,17,10,69,32,2,20,159,1  ; n117 t=34.160s dur=2577ms, vel 46->32, sust 1277->2577, freq=415Hz, sample=69
; t 34.4531 Sustain 127 (Instr 1)
; t 34.4531 Sustain 127 (Instr 2)
    db 155,1,107,8,57,23,1,21,247,0  ; n118 t=34.582s dur=2155ms, vel 33->23, sust 920->2155, freq=247Hz, sample=57
    db 161,1,208,6,69,23,1,22,74,1  ; n119 t=34.993s dur=1744ms, vel 33->23, sust 892->1744, freq=330Hz, sample=69
    db 125,1,47,5,57,23,1,23,208,0  ; n120 t=35.410s dur=1327ms, vel 33->23, sust 771->1327, freq=208Hz, sample=57
    db 202,1,178,3,57,23,1,24,247,0  ; n121 t=35.792s dur=946ms, vel 33->23, sust 622->946, freq=247Hz, sample=57
    db 36,1,232,1,69,23,1,25,74,1  ; n122 t=36.250s dur=488ms, vel 33->23, sust 209->488, freq=330Hz, sample=69
    db 69,0,120,12,33,23,1,26,62,0  ; n123 t=36.541s dur=3192ms, vel 33->23, sust 686->3192, freq=62Hz, sample=33
    db 110,0,51,12,45,23,1,27,123,0  ; n124 t=36.610s dur=3123ms, vel 33->23, sust 634->3123, freq=123Hz, sample=45
    db 24,0,197,11,57,25,1,28,220,0  ; n125 t=36.721s dur=3013ms, vel 36->25, sust 375->3013, freq=220Hz, sample=57
; t 36.7380 Sustain 0 (Instr 1)
; t 36.7380 Sustain 0 (Instr 2)
    db 149,1,173,11,69,28,1,29,114,1  ; n126 t=36.745s dur=2989ms, vel 40->28, sust 959->2989, freq=370Hz, sample=69
; t 36.9991 Sustain 127 (Instr 1)
; t 36.9991 Sustain 127 (Instr 2)
    db 160,1,23,10,57,23,1,30,247,0  ; n127 t=37.150s dur=2583ms, vel 33->23, sust 420->2583, freq=247Hz, sample=57
    db 255,1,119,8,57,23,1,31,55,1  ; n128 t=37.566s dur=2167ms, vel 33->23, sust 527->2167, freq=311Hz, sample=57
    db 31,0,120,6,57,25,1,0,220,0  ; n129 t=38.078s dur=1656ms, vel 36->25, sust 584->1656, freq=220Hz, sample=57
    db 219,1,89,6,69,30,2,1,238,1  ; n130 t=38.108s dur=1625ms, vel 44->30, sust 338->1625, freq=494Hz, sample=69
    db 75,2,126,4,57,23,1,2,247,0  ; n131 t=38.583s dur=1150ms, vel 33->23, sust 227->1150, freq=247Hz, sample=57
    db 79,2,51,2,57,23,1,3,55,1  ; n132 t=39.170s dur=563ms, vel 33->23, sust 206->563, freq=311Hz, sample=57
; t 39.7336 Sustain 0 (Instr 1)
; t 39.7336 Sustain 0 (Instr 2)
    db 1,0,94,17,57,23,1,4,165,0  ; n133 t=39.761s dur=4446ms, vel 34->23, sust 1874->4446, freq=165Hz, sample=57
    db 25,0,93,17,45,23,1,5,82,0  ; n134 t=39.762s dur=4445ms, vel 34->23, sust 1549->4445, freq=82Hz, sample=45
    db 11,0,141,16,57,25,1,6,208,0  ; n135 t=39.787s dur=4237ms, vel 36->25, sust 869->4237, freq=208Hz, sample=57
    db 136,1,57,17,69,26,1,7,74,1  ; n136 t=39.798s dur=4409ms, vel 38->26, sust 511->4409, freq=330Hz, sample=69
; t 40.0285 Sustain 127 (Instr 1)
; t 40.0285 Sustain 127 (Instr 2)
    db 120,1,235,13,57,23,1,8,247,0  ; n137 t=40.190s dur=3563ms, vel 33->23, sust 770->3563, freq=247Hz, sample=57
    db 83,1,57,14,69,23,1,9,74,1  ; n138 t=40.566s dur=3641ms, vel 33->23, sust 845->3641, freq=330Hz, sample=69
    db 119,1,231,12,57,23,1,10,208,0  ; n139 t=40.904s dur=3303ms, vel 33->23, sust 923->3303, freq=208Hz, sample=57
    db 129,1,112,11,57,23,1,11,247,0  ; n140 t=41.279s dur=2928ms, vel 33->23, sust 819->2928, freq=247Hz, sample=57
    db 90,1,239,9,69,23,1,12,74,1  ; n141 t=41.664s dur=2543ms, vel 33->23, sust 870->2543, freq=330Hz, sample=69
    db 136,1,149,8,57,23,1,13,208,0  ; n142 t=42.011s dur=2197ms, vel 33->23, sust 917->2197, freq=208Hz, sample=57
    db 137,1,12,7,57,23,1,14,247,0  ; n143 t=42.403s dur=1804ms, vel 33->23, sust 841->1804, freq=247Hz, sample=57
    db 120,1,131,5,69,23,1,15,74,1  ; n144 t=42.796s dur=1411ms, vel 33->23, sust 1080->1411, freq=330Hz, sample=69
    db 120,1,12,4,57,23,1,16,208,0  ; n145 t=43.172s dur=1036ms, vel 33->23, sust 654->1036, freq=208Hz, sample=57
    db 133,1,246,2,57,23,1,17,247,0  ; n146 t=43.547s dur=758ms, vel 33->23, freq=247Hz, sample=57
    db 200,0,236,1,69,25,1,18,74,1  ; n147 t=43.936s dur=492ms, vel 37->25, freq=330Hz, sample=69
    db 13,0,75,19,57,27,1,19,165,0  ; n148 t=44.136s dur=4939ms, vel 39->27, sust 4434->4939, freq=165Hz, sample=57
    db 143,0,62,19,45,27,1,20,82,0  ; n149 t=44.149s dur=4926ms, vel 39->27, sust 4487->4926, freq=82Hz, sample=45
; t 44.2077 Sustain 0 (Instr 1)
; t 44.2077 Sustain 0 (Instr 2)
    db 108,1,67,13,57,32,1,21,196,0  ; n150 t=44.292s dur=3395ms, vel 47->32, sust 876->3395, freq=196Hz, sample=57
; t 44.5035 Sustain 127 (Instr 1)
; t 44.5035 Sustain 127 (Instr 2)
    db 124,1,215,11,57,23,1,22,247,0  ; n151 t=44.655s dur=3031ms, vel 33->23, sust 804->3031, freq=247Hz, sample=57
    db 119,1,91,10,69,23,1,23,74,1  ; n152 t=45.035s dur=2651ms, vel 33->23, sust 932->2651, freq=330Hz, sample=69
    db 120,1,228,8,57,23,1,24,196,0  ; n153 t=45.411s dur=2276ms, vel 33->23, sust 826->2276, freq=196Hz, sample=57
    db 88,1,108,7,57,23,1,25,247,0  ; n154 t=45.786s dur=1900ms, vel 33->23, sust 764->1900, freq=247Hz, sample=57
    db 130,1,20,6,69,23,1,26,74,1  ; n155 t=46.130s dur=1556ms, vel 33->23, sust 921->1556, freq=330Hz, sample=69
    db 122,1,146,4,57,23,1,27,196,0  ; n156 t=46.517s dur=1170ms, vel 33->23, sust 767->1170, freq=196Hz, sample=57
    db 73,1,58,3,57,23,1,28,247,0  ; n157 t=46.894s dur=826ms, vel 33->23, freq=247Hz, sample=57
    db 198,1,254,1,69,23,1,29,74,1  ; n158 t=47.223s dur=510ms, vel 34->23, freq=330Hz, sample=69
    db 14,0,117,5,69,33,2,30,136,1  ; n159 t=47.677s dur=1397ms, vel 48->33, sust 944->1397, freq=392Hz, sample=69
; t 47.6867 Sustain 0 (Instr 1)
; t 47.6867 Sustain 0 (Instr 2)
    db 227,1,103,5,57,28,1,31,196,0  ; n160 t=47.691s dur=1383ms, vel 41->28, sust 859->1383, freq=196Hz, sample=57
    db 149,1,132,3,57,23,1,0,247,0  ; n161 t=48.175s dur=900ms, vel 34->23, sust 537->900, freq=247Hz, sample=57
; t 48.1876 Sustain 127 (Instr 1)
; t 48.1876 Sustain 127 (Instr 2)
    db 12,1,239,1,69,23,1,1,74,1  ; n162 t=48.579s dur=495ms, vel 33->23, sust 324->495, freq=330Hz, sample=69
    db 2,1,227,0,69,31,2,2,136,1  ; n163 t=48.848s dur=227ms, vel 45->31, sust 142->227, freq=392Hz, sample=69
; t 49.0748 Sustain 0 (Instr 1)
; t 49.0748 Sustain 0 (Instr 2)
    db 7,0,180,11,45,27,1,3,147,0  ; n164 t=49.105s dur=2996ms, vel 39->27, freq=147Hz, sample=45
    db 5,0,117,13,69,34,2,4,136,1  ; n165 t=49.112s dur=3445ms, vel 49->34, sust 1366->3445, freq=392Hz, sample=69
    db 8,0,180,11,33,27,1,5,73,0  ; n166 t=49.117s dur=2996ms, vel 39->27, freq=73Hz, sample=33
    db 176,1,104,13,57,28,1,6,196,0  ; n167 t=49.125s dur=3432ms, vel 40->28, sust 854->3432, freq=196Hz, sample=57
; t 49.5396 Sustain 127 (Instr 1)
; t 49.5396 Sustain 127 (Instr 2)
    db 118,1,184,11,57,23,1,7,247,0  ; n168 t=49.557s dur=3000ms, vel 34->23, sust 737->3000, freq=247Hz, sample=57
    db 72,1,66,10,69,23,1,8,93,1  ; n169 t=49.931s dur=2626ms, vel 33->23, sust 386->2626, freq=349Hz, sample=69
    db 104,1,249,8,57,23,1,9,196,0  ; n170 t=50.260s dur=2297ms, vel 33->23, sust 760->2297, freq=196Hz, sample=57
    db 106,1,145,7,57,23,1,10,247,0  ; n171 t=50.620s dur=1937ms, vel 33->23, sust 790->1937, freq=247Hz, sample=57
    db 111,1,39,6,69,23,1,11,93,1  ; n172 t=50.982s dur=1575ms, vel 33->23, sust 427->1575, freq=349Hz, sample=69
    db 140,1,184,4,57,23,1,12,196,0  ; n173 t=51.349s dur=1208ms, vel 33->23, sust 779->1208, freq=196Hz, sample=57
    db 99,1,103,3,57,23,1,13,247,0  ; n174 t=51.745s dur=871ms, vel 33->23, freq=247Hz, sample=57
    db 200,1,245,1,69,23,1,14,93,1  ; n175 t=52.099s dur=501ms, vel 33->23, freq=349Hz, sample=69
    db 26,0,251,4,57,24,1,15,196,0  ; n176 t=52.555s dur=1275ms, vel 35->24, sust 698->1275, freq=196Hz, sample=57
; t 52.5575 Sustain 0 (Instr 1)
; t 52.5575 Sustain 0 (Instr 2)
    db 142,1,224,4,69,32,2,16,136,1  ; n177 t=52.581s dur=1248ms, vel 47->32, sust 740->1248, freq=392Hz, sample=69
; t 52.9218 Sustain 127 (Instr 1)
; t 52.9218 Sustain 127 (Instr 2)
    db 78,1,82,3,57,23,1,17,247,0  ; n178 t=52.980s dur=850ms, vel 33->23, sust 492->850, freq=247Hz, sample=57
    db 245,0,4,2,69,23,1,18,93,1  ; n179 t=53.313s dur=516ms, vel 33->23, sust 312->516, freq=349Hz, sample=69
    db 30,1,15,1,69,32,2,19,136,1  ; n180 t=53.559s dur=271ms, vel 46->32, sust 164->271, freq=392Hz, sample=69
; t 53.8304 Sustain 0 (Instr 1)
; t 53.8304 Sustain 0 (Instr 2)
    db 8,0,173,4,45,25,1,20,131,0  ; n181 t=53.845s dur=1197ms, vel 36->25, sust 902->1197, freq=131Hz, sample=45
    db 4,0,166,4,57,25,1,21,196,0  ; n182 t=53.852s dur=1190ms, vel 36->25, sust 844->1190, freq=196Hz, sample=57
    db 10,0,25,14,69,35,2,22,136,1  ; n183 t=53.857s dur=3609ms, vel 50->35, sust 3251->3609, freq=392Hz, sample=69
    db 142,1,151,4,33,25,1,23,65,0  ; n184 t=53.866s dur=1175ms, vel 36->25, sust 1088->1175, freq=65Hz, sample=33
    db 127,1,9,3,57,23,1,24,6,1  ; n185 t=54.265s dur=777ms, vel 33->23, sust 452->777, freq=262Hz, sample=57
; t 54.2678 Soft 0 (Instr 1)
; t 54.2678 Soft 0 (Instr 2)
; t 54.3213 Sustain 127 (Instr 1)
; t 54.3213 Sustain 127 (Instr 2)
    db 112,1,120,3,69,33,1,25,74,1  ; n186 t=54.647s dur=888ms, freq=330Hz, sample=69
    db 1,0,3,5,45,37,1,26,123,0  ; n187 t=55.015s dur=1283ms, sust 845->1283, freq=123Hz, sample=45
    db 11,0,2,5,33,37,1,27,62,0  ; n188 t=55.016s dur=1282ms, sust 877->1282, freq=62Hz, sample=33
    db 168,1,247,4,57,37,1,28,196,0  ; n189 t=55.027s dur=1271ms, sust 859->1271, freq=196Hz, sample=57
; t 55.0423 Sustain 0 (Instr 1)
; t 55.0423 Sustain 0 (Instr 2)
    db 105,1,79,3,57,33,1,29,6,1  ; n190 t=55.451s dur=847ms, sust 370->847, freq=262Hz, sample=57
; t 55.5832 Sustain 127 (Instr 1)
; t 55.5832 Sustain 127 (Instr 2)
    db 151,1,61,2,69,33,1,30,74,1  ; n191 t=55.812s dur=573ms, freq=330Hz, sample=69
    db 5,0,18,10,33,38,1,31,58,0  ; n192 t=56.219s dur=2578ms, sust 2049->2578, freq=58Hz, sample=33
    db 64,0,13,10,45,38,1,0,117,0  ; n193 t=56.224s dur=2573ms, sust 2028->2573, freq=117Hz, sample=45
; t 56.2450 Soft 127 (Instr 1)
; t 56.2450 Soft 127 (Instr 2)
    db 154,1,153,4,57,26,1,1,196,0  ; n194 t=56.289s dur=1177ms, vel 38->26, sust 816->1177, freq=196Hz, sample=57
; t 56.2984 Sustain 0 (Instr 1)
; t 56.2984 Sustain 0 (Instr 2)
    db 106,1,92,3,57,23,1,2,21,1  ; n195 t=56.699s dur=860ms, vel 33->23, freq=277Hz, sample=57
; t 56.7291 Sustain 127 (Instr 1)
; t 56.7291 Sustain 127 (Instr 2)
    db 132,1,217,1,69,23,1,3,74,1  ; n196 t=57.061s dur=473ms, vel 33->23, freq=330Hz, sample=69
    db 76,0,68,5,57,23,1,4,185,0  ; n197 t=57.449s dur=1348ms, vel 33->23, sust 1130->1348, freq=185Hz, sample=57
; t 57.4662 Sustain 0 (Instr 1)
; t 57.4662 Sustain 0 (Instr 2)
    db 145,1,248,4,69,30,1,5,114,1  ; n198 t=57.525s dur=1272ms, vel 43->30, sust 937->1272, freq=370Hz, sample=69
; t 57.9035 Sustain 127 (Instr 1)
; t 57.9035 Sustain 127 (Instr 2)
    db 180,1,103,3,57,23,1,6,21,1  ; n199 t=57.926s dur=871ms, vel 33->23, sust 618->871, freq=277Hz, sample=57
    db 163,1,179,1,69,23,1,7,74,1  ; n200 t=58.362s dur=435ms, vel 33->23, sust 144->435, freq=330Hz, sample=69
    db 9,0,67,9,57,23,1,8,185,0  ; n201 t=58.781s dur=2371ms, vel 33->23, sust 937->2371, freq=185Hz, sample=57
    db 4,0,59,9,33,23,1,9,62,0  ; n202 t=58.790s dur=2363ms, vel 33->23, sust 1538->2363, freq=62Hz, sample=33
    db 56,0,54,9,45,23,1,10,123,0  ; n203 t=58.794s dur=2358ms, vel 33->23, sust 1525->2358, freq=123Hz, sample=45
; t 58.7976 Sustain 0 (Instr 1)
; t 58.7976 Sustain 0 (Instr 2)
    db 129,1,255,8,69,28,1,11,114,1  ; n204 t=58.850s dur=2303ms, vel 40->28, sust 1377->2303, freq=370Hz, sample=69
; t 59.1737 Sustain 127 (Instr 1)
; t 59.1737 Sustain 127 (Instr 2)
    db 150,1,126,7,57,23,1,12,247,0  ; n205 t=59.235s dur=1918ms, vel 33->23, sust 863->1918, freq=247Hz, sample=57
    db 110,1,232,5,57,23,1,13,38,1  ; n206 t=59.640s dur=1512ms, vel 33->23, sust 464->1512, freq=294Hz, sample=57
    db 144,1,122,4,57,23,1,14,185,0  ; n207 t=60.006s dur=1146ms, vel 33->23, sust 917->1146, freq=185Hz, sample=57
    db 136,1,234,2,57,23,1,15,247,0  ; n208 t=60.406s dur=746ms, vel 33->23, sust 542->746, freq=247Hz, sample=57
    db 12,1,218,1,57,23,1,16,38,1  ; n209 t=60.799s dur=474ms, vel 33->23, freq=294Hz, sample=57
    db 133,0,132,5,45,25,1,17,82,0  ; n210 t=61.067s dur=1412ms, vel 36->25, sust 1358->1412, freq=82Hz, sample=45
; t 61.1530 Sustain 0 (Instr 1)
; t 61.1530 Sustain 0 (Instr 2)
    db 24,0,255,4,57,23,1,18,196,0  ; n211 t=61.200s dur=1279ms, vel 34->23, sust 774->1279, freq=196Hz, sample=57
    db 169,1,231,4,69,31,2,19,136,1  ; n212 t=61.224s dur=1255ms, vel 45->31, sust 690->1255, freq=392Hz, sample=69
; t 61.5388 Sustain 127 (Instr 1)
; t 61.5388 Sustain 127 (Instr 2)
    db 148,1,65,3,57,23,1,20,247,0  ; n213 t=61.649s dur=833ms, vel 33->23, freq=247Hz, sample=57
    db 36,1,204,1,57,23,1,21,21,1  ; n214 t=62.053s dur=460ms, vel 33->23, freq=277Hz, sample=57
    db 76,0,144,5,45,23,1,22,98,0  ; n215 t=62.345s dur=1424ms, vel 33->23, sust 1345->1424, freq=98Hz, sample=45
    db 71,0,67,5,57,23,1,23,165,0  ; n216 t=62.422s dur=1347ms, vel 33->23, sust 835->1347, freq=165Hz, sample=57
; t 62.4795 Sustain 0 (Instr 1)
; t 62.4795 Sustain 0 (Instr 2)
    db 155,1,253,4,69,29,1,24,74,1  ; n217 t=62.492s dur=1277ms, vel 42->29, sust 822->1277, freq=330Hz, sample=69
; t 62.8577 Sustain 127 (Instr 1)
; t 62.8577 Sustain 127 (Instr 2)
    db 179,1,98,3,57,23,1,25,247,0  ; n218 t=62.903s dur=866ms, vel 33->23, sust 695->866, freq=247Hz, sample=57
    db 169,1,175,1,57,23,1,26,21,1  ; n219 t=63.338s dur=431ms, vel 33->23, sust 291->431, freq=277Hz, sample=57
    db 13,0,114,10,57,23,1,27,185,0  ; n220 t=63.763s dur=2674ms, vel 33->23, sust 1058->2674, freq=185Hz, sample=57
; t 63.7696 Sustain 0 (Instr 1)
; t 63.7696 Sustain 0 (Instr 2)
    db 70,0,101,10,45,23,1,28,92,0  ; n221 t=63.776s dur=2661ms, vel 33->23, sust 1784->2661, freq=92Hz, sample=45
    db 148,1,31,10,69,28,1,29,114,1  ; n222 t=63.846s dur=2591ms, vel 41->28, sust 2224->2591, freq=370Hz, sample=69
; t 64.1553 Sustain 127 (Instr 1)
; t 64.1553 Sustain 127 (Instr 2)
    db 163,1,139,8,57,23,1,30,247,0  ; n223 t=64.250s dur=2187ms, vel 33->23, sust 915->2187, freq=247Hz, sample=57
    db 110,1,232,6,57,23,1,31,38,1  ; n224 t=64.669s dur=1768ms, vel 33->23, sust 953->1768, freq=294Hz, sample=57
    db 148,1,122,5,57,23,1,0,185,0  ; n225 t=65.036s dur=1402ms, vel 33->23, sust 1060->1402, freq=185Hz, sample=57
    db 149,1,229,3,57,23,1,1,247,0  ; n226 t=65.440s dur=997ms, vel 33->23, sust 618->997, freq=247Hz, sample=57
    db 209,1,80,2,57,23,1,2,38,1  ; n227 t=65.845s dur=592ms, vel 33->23, sust 214->592, freq=294Hz, sample=57
    db 26,0,168,11,33,23,1,3,46,0  ; n228 t=66.310s dur=2984ms, vel 33->23, sust 1658->2984, freq=46Hz, sample=33
    db 7,0,142,11,57,23,1,4,185,0  ; n229 t=66.337s dur=2958ms, vel 33->23, sust 1033->2958, freq=185Hz, sample=57
    db 64,0,135,11,45,23,1,5,92,0  ; n230 t=66.343s dur=2951ms, vel 33->23, sust 1642->2951, freq=92Hz, sample=45
    db 188,1,71,11,69,28,1,6,114,1  ; n231 t=66.407s dur=2887ms, vel 41->28, sust 1525->2887, freq=370Hz, sample=69
; t 66.4378 Sustain 0 (Instr 1)
; t 66.4378 Sustain 0 (Instr 2)
; t 66.7265 Sustain 127 (Instr 1)
; t 66.7265 Sustain 127 (Instr 2)
    db 194,1,138,9,57,23,1,7,233,0  ; n232 t=66.852s dur=2442ms, vel 33->23, sust 961->2442, freq=233Hz, sample=57
    db 145,1,201,7,57,23,1,8,21,1  ; n233 t=67.302s dur=1993ms, vel 33->23, sust 582->1993, freq=277Hz, sample=57
    db 216,1,56,6,57,23,1,9,185,0  ; n234 t=67.702s dur=1592ms, vel 33->23, sust 525->1592, freq=185Hz, sample=57
    db 163,1,96,4,57,23,1,10,233,0  ; n235 t=68.174s dur=1120ms, vel 33->23, sust 642->1120, freq=233Hz, sample=57
    db 28,2,189,2,57,23,1,11,21,1  ; n236 t=68.593s dur=701ms, vel 33->23, sust 248->701, freq=277Hz, sample=57
    db 12,0,235,13,33,23,1,12,62,0  ; n237 t=69.133s dur=3563ms, vel 33->23, sust 5456->3563, freq=62Hz, sample=33
    db 51,0,235,13,45,24,1,13,123,0  ; n238 t=69.145s dur=3563ms, vel 35->24, sust 5460->3563, freq=123Hz, sample=45
    db 224,1,91,9,57,30,1,14,247,0  ; n239 t=69.197s dur=2395ms, vel 43->30, sust 925->2395, freq=247Hz, sample=57
; t 69.2946 Sustain 0 (Instr 1)
; t 69.2946 Sustain 0 (Instr 2)
; t 69.6061 Sustain 127 (Instr 1)
; t 69.6061 Sustain 127 (Instr 2)
    db 134,1,123,7,57,23,1,15,38,1  ; n240 t=69.677s dur=1915ms, vel 33->23, sust 516->1915, freq=294Hz, sample=57
    db 118,1,245,5,69,23,1,16,114,1  ; n241 t=70.067s dur=1525ms, vel 33->23, sust 484->1525, freq=370Hz, sample=69
    db 103,1,127,4,57,23,1,17,247,0  ; n242 t=70.440s dur=1151ms, vel 33->23, sust 836->1151, freq=247Hz, sample=57
    db 124,1,24,3,57,23,1,18,38,1  ; n243 t=70.800s dur=792ms, vel 33->23, sust 665->792, freq=294Hz, sample=57
    db 121,1,231,1,69,23,1,19,114,1  ; n244 t=71.180s dur=487ms, vel 33->23, freq=370Hz, sample=69
; t 71.2732 Soft 0 (Instr 1)
; t 71.2732 Soft 0 (Instr 2)
    db 172,1,0,5,57,33,1,20,247,0  ; n245 t=71.556s dur=1280ms, sust 930->1280, freq=247Hz, sample=57
; t 71.5922 Sustain 0 (Instr 1)
; t 71.5922 Sustain 0 (Instr 2)
; t 71.8371 Sustain 127 (Instr 1)
; t 71.8371 Sustain 127 (Instr 2)
    db 115,1,84,3,57,33,1,21,55,1  ; n246 t=71.984s dur=852ms, sust 528->852, freq=311Hz, sample=57
    db 183,1,225,1,69,36,1,22,114,1  ; n247 t=72.355s dur=481ms, sust 148->481, freq=370Hz, sample=69
    db 2,0,66,5,69,58,2,23,238,1  ; n248 t=72.794s dur=1346ms, sust 928->1346, freq=494Hz, sample=69
    db 214,1,64,5,57,42,1,24,247,0  ; n249 t=72.796s dur=1344ms, sust 929->1344, freq=247Hz, sample=57
; t 72.8365 Sustain 0 (Instr 1)
; t 72.8365 Sustain 0 (Instr 2)
; t 73.1500 Sustain 127 (Instr 1)
; t 73.1500 Sustain 127 (Instr 2)
    db 141,1,106,3,57,36,1,25,55,1  ; n250 t=73.266s dur=874ms, sust 464->874, freq=311Hz, sample=57
    db 120,1,220,1,69,38,1,26,114,1  ; n251 t=73.664s dur=476ms, sust 86->476, freq=370Hz, sample=69
    db 17,0,235,8,57,50,1,27,247,0  ; n252 t=74.039s dur=2283ms, sust 925->2283, freq=247Hz, sample=57
    db 179,1,35,13,69,59,2,28,11,2  ; n253 t=74.057s dur=3363ms, sust 2566->3363, freq=523Hz, sample=69
; t 74.1407 Sustain 0 (Instr 1)
; t 74.1407 Sustain 0 (Instr 2)
; t 74.4030 Sustain 127 (Instr 1)
; t 74.4030 Sustain 127 (Instr 2)
    db 136,1,38,7,69,52,1,29,74,1  ; n254 t=74.492s dur=1830ms, sust 676->1830, freq=330Hz, sample=69
    db 233,0,158,5,69,49,2,30,136,1  ; n255 t=74.884s dur=1438ms, sust 368->1438, freq=392Hz, sample=69
    db 3,0,181,4,45,53,1,31,82,0  ; n256 t=75.117s dur=1205ms, sust 877->1205, freq=82Hz, sample=45
    db 73,0,178,4,57,53,1,0,165,0  ; n257 t=75.120s dur=1202ms, sust 859->1202, freq=165Hz, sample=57
    db 130,1,105,4,57,54,1,1,247,0  ; n258 t=75.193s dur=1129ms, sust 837->1129, freq=247Hz, sample=57
    db 101,1,7,3,69,49,1,2,74,1  ; n259 t=75.579s dur=775ms, freq=330Hz, sample=69
    db 3,1,130,1,69,38,2,3,136,1  ; n260 t=75.936s dur=386ms, sust 337->386, freq=392Hz, sample=69
    db 12,0,174,5,45,52,1,4,98,0  ; n261 t=76.195s dur=1454ms, sust 660->1454, freq=98Hz, sample=45
    db 52,0,162,5,57,52,1,5,196,0  ; n262 t=76.207s dur=1442ms, sust 535->1442, freq=196Hz, sample=57
; t 76.2357 Soft 127 (Instr 1)
; t 76.2357 Soft 127 (Instr 2)
    db 197,1,110,5,57,25,1,6,247,0  ; n263 t=76.260s dur=1390ms, vel 37->25, sust 1118->1390, freq=247Hz, sample=57
; t 76.3227 Sustain 0 (Instr 1)
; t 76.3227 Sustain 0 (Instr 2)
; t 76.5600 Sustain 127 (Instr 1)
; t 76.5600 Sustain 127 (Instr 2)
    db 161,1,191,3,69,23,1,7,74,1  ; n264 t=76.712s dur=959ms, vel 33->23, freq=330Hz, sample=69
    db 146,1,9,2,69,27,2,8,136,1  ; n265 t=77.129s dur=521ms, vel 39->27, sust 414->521, freq=392Hz, sample=69
    db 57,0,168,4,45,25,1,9,82,0  ; n266 t=77.531s dur=1192ms, vel 36->25, sust 738->1192, freq=82Hz, sample=45
    db 13,0,48,1,57,25,1,10,165,0  ; n267 t=77.587s dur=304ms, vel 36->25, freq=165Hz, sample=57
    db 4,0,98,4,57,24,1,11,247,0  ; n268 t=77.600s dur=1122ms, vel 35->24, sust 742->1122, freq=247Hz, sample=57
    db 132,1,94,4,69,32,2,12,210,1  ; n269 t=77.605s dur=1118ms, vel 46->32, sust 810->1118, freq=466Hz, sample=69
; t 77.6503 Sustain 0 (Instr 1)
; t 77.6503 Sustain 0 (Instr 2)
; t 77.8941 Sustain 127 (Instr 1)
; t 77.8941 Sustain 127 (Instr 2)
    db 110,1,254,2,69,23,1,13,74,1  ; n270 t=77.993s dur=766ms, vel 33->23, freq=330Hz, sample=69
    db 247,0,143,1,69,26,2,14,136,1  ; n271 t=78.359s dur=399ms, vel 38->26, freq=392Hz, sample=69
    db 10,0,235,13,33,25,1,15,62,0  ; n272 t=78.606s dur=3563ms, vel 37->25, sust 5034->3563, freq=62Hz, sample=33
    db 90,0,235,13,45,25,1,16,123,0  ; n273 t=78.616s dur=3563ms, vel 37->25, sust 5028->3563, freq=123Hz, sample=45
    db 29,0,248,12,57,25,1,17,247,0  ; n274 t=78.706s dur=3320ms, vel 36->25, sust 867->3320, freq=247Hz, sample=57
; t 78.7233 Sustain 0 (Instr 1)
; t 78.7233 Sustain 0 (Instr 2)
    db 136,1,219,12,69,30,2,18,238,1  ; n275 t=78.735s dur=3291ms, vel 43->30, sust 3023->3291, freq=494Hz, sample=69
; t 79.0474 Sustain 127 (Instr 1)
; t 79.0474 Sustain 127 (Instr 2)
    db 77,1,12,11,57,23,1,19,55,1  ; n276 t=79.127s dur=2828ms, vel 33->23, sust 750->2828, freq=311Hz, sample=57
    db 93,1,7,10,69,23,1,20,114,1  ; n277 t=79.460s dur=2567ms, vel 33->23, sust 420->2567, freq=370Hz, sample=69
; t 79.6718 Soft 0 (Instr 1)
; t 79.6718 Soft 0 (Instr 2)
    db 103,1,169,8,57,33,1,21,247,0  ; n278 t=79.809s dur=2217ms, sust 786->2217, freq=247Hz, sample=57
    db 91,1,66,7,57,33,1,22,55,1  ; n279 t=80.168s dur=1858ms, sust 751->1858, freq=311Hz, sample=57
    db 88,1,232,5,69,36,1,23,114,1  ; n280 t=80.515s dur=1512ms, sust 371->1512, freq=370Hz, sample=69
    db 89,1,144,4,57,41,1,24,247,0  ; n281 t=80.859s dur=1168ms, sust 895->1168, freq=247Hz, sample=57
    db 86,1,55,3,57,42,1,25,55,1  ; n282 t=81.203s dur=823ms, sust 659->823, freq=311Hz, sample=57
    db 141,1,225,1,69,37,1,26,114,1  ; n283 t=81.545s dur=481ms, sust 348->481, freq=370Hz, sample=69
    db 9,0,99,4,69,54,2,27,238,1  ; n284 t=81.942s dur=1123ms, sust 734->1123, freq=494Hz, sample=69
    db 116,1,90,4,57,42,1,28,247,0  ; n285 t=81.951s dur=1114ms, sust 721->1114, freq=247Hz, sample=57
; t 82.0268 Sustain 0 (Instr 1)
; t 82.0268 Sustain 0 (Instr 2)
    db 78,1,230,2,57,41,1,29,55,1  ; n286 t=82.323s dur=742ms, sust 374->742, freq=311Hz, sample=57
; t 82.3292 Sustain 127 (Instr 1)
; t 82.3292 Sustain 127 (Instr 2)
    db 56,1,152,1,69,36,1,30,114,1  ; n287 t=82.656s dur=408ms, sust 64->408, freq=370Hz, sample=69
    db 17,0,163,8,57,40,1,31,247,0  ; n288 t=82.969s dur=2211ms, sust 942->2211, freq=247Hz, sample=57
    db 142,1,35,13,69,56,2,0,11,2  ; n289 t=82.986s dur=3363ms, sust 2527->3363, freq=523Hz, sample=69
; t 83.0654 Sustain 0 (Instr 1)
; t 83.0654 Sustain 0 (Instr 2)
    db 135,1,4,7,69,39,1,1,74,1  ; n290 t=83.384s dur=1796ms, sust 621->1796, freq=330Hz, sample=69
; t 83.4111 Sustain 127 (Instr 1)
; t 83.4111 Sustain 127 (Instr 2)
    db 247,0,124,5,69,40,2,2,136,1  ; n291 t=83.775s dur=1404ms, sust 368->1404, freq=392Hz, sample=69
    db 7,0,134,4,57,42,1,3,165,0  ; n292 t=84.022s dur=1158ms, sust 852->1158, freq=165Hz, sample=57
    db 67,0,127,4,45,43,1,4,82,0  ; n293 t=84.029s dur=1151ms, sust 861->1151, freq=82Hz, sample=45
    db 66,1,60,4,57,43,1,5,247,0  ; n294 t=84.096s dur=1084ms, sust 863->1084, freq=247Hz, sample=57
    db 123,1,250,2,69,38,1,6,74,1  ; n295 t=84.418s dur=762ms, sust 756->762, freq=330Hz, sample=69
    db 17,1,162,6,69,38,2,7,136,1  ; n296 t=84.797s dur=1698ms, sust 1030->1698, freq=392Hz, sample=69
    db 11,0,145,5,45,40,1,8,98,0  ; n297 t=85.070s dur=1425ms, sust 648->1425, freq=98Hz, sample=45
    db 51,0,134,5,57,42,1,9,196,0  ; n298 t=85.081s dur=1414ms, sust 464->1414, freq=196Hz, sample=57
    db 155,1,83,5,57,40,1,10,247,0  ; n299 t=85.132s dur=1363ms, sust 1095->1363, freq=247Hz, sample=57
; t 85.1802 Sustain 0 (Instr 1)
; t 85.1802 Sustain 0 (Instr 2)
; t 85.4618 Sustain 127 (Instr 1)
; t 85.4618 Sustain 127 (Instr 2)
    db 167,1,236,3,69,33,1,11,74,1  ; n300 t=85.543s dur=1004ms, freq=330Hz, sample=69
    db 137,1,29,2,69,40,2,12,136,1  ; n301 t=85.966s dur=541ms, freq=392Hz, sample=69
    db 38,0,170,4,45,39,1,13,82,0  ; n302 t=86.359s dur=1194ms, sust 1167->1194, freq=82Hz, sample=45
    db 57,0,132,4,57,38,1,14,165,0  ; n303 t=86.397s dur=1156ms, sust 548->1156, freq=165Hz, sample=57
    db 14,0,75,4,69,47,2,15,210,1  ; n304 t=86.454s dur=1099ms, sust 814->1099, freq=466Hz, sample=69
    db 129,1,61,4,57,37,1,16,247,0  ; n305 t=86.468s dur=1085ms, sust 751->1085, freq=247Hz, sample=57
; t 86.4959 Sustain 0 (Instr 1)
; t 86.4959 Sustain 0 (Instr 2)
; t 86.7469 Sustain 127 (Instr 1)
; t 86.7469 Sustain 127 (Instr 2)
    db 108,1,22,3,69,33,1,17,74,1  ; n306 t=86.852s dur=790ms, freq=330Hz, sample=69
    db 224,0,176,1,69,39,2,18,136,1  ; n307 t=87.216s dur=432ms, freq=392Hz, sample=69
    db 25,0,169,9,33,39,1,19,62,0  ; n308 t=87.440s dur=2473ms, sust 1791->2473, freq=62Hz, sample=33
    db 117,0,144,9,45,39,1,20,123,0  ; n309 t=87.465s dur=2448ms, sust 1693->2448, freq=123Hz, sample=45
; t 87.5534 Sustain 0 (Instr 1)
; t 87.5534 Sustain 0 (Instr 2)
    db 4,0,27,9,57,37,1,21,247,0  ; n310 t=87.583s dur=2331ms, sust 959->2331, freq=247Hz, sample=57
    db 153,1,22,9,69,44,2,22,238,1  ; n311 t=87.587s dur=2326ms, sust 1404->2326, freq=494Hz, sample=69
; t 87.8816 Sustain 127 (Instr 1)
; t 87.8816 Sustain 127 (Instr 2)
    db 138,1,126,7,57,33,1,23,55,1  ; n312 t=87.996s dur=1918ms, sust 837->1918, freq=311Hz, sample=57
    db 139,1,243,5,69,38,1,24,114,1  ; n313 t=88.390s dur=1523ms, sust 453->1523, freq=370Hz, sample=69
    db 129,1,105,4,57,33,1,25,247,0  ; n314 t=88.785s dur=1129ms, sust 836->1129, freq=247Hz, sample=57
    db 134,1,232,2,57,33,1,26,55,1  ; n315 t=89.170s dur=744ms, sust 490->744, freq=311Hz, sample=57
    db 174,0,163,1,69,37,1,27,114,1  ; n316 t=89.560s dur=419ms, freq=370Hz, sample=69
    db 56,0,173,9,33,39,1,28,52,0  ; n317 t=89.734s dur=2477ms, sust 1568->2477, freq=52Hz, sample=33
    db 141,0,116,9,45,39,1,29,104,0  ; n318 t=89.790s dur=2420ms, sust 1210->2420, freq=104Hz, sample=45
; t 89.9141 Sustain 0 (Instr 1)
; t 89.9141 Sustain 0 (Instr 2)
    db 2,0,231,8,69,52,2,30,238,1  ; n319 t=89.931s dur=2279ms, sust 1867->2279, freq=494Hz, sample=69
    db 134,1,229,8,57,37,1,31,247,0  ; n320 t=89.934s dur=2277ms, sust 856->2277, freq=247Hz, sample=57
; t 90.3163 Sustain 127 (Instr 1)
; t 90.3163 Sustain 127 (Instr 2)
    db 97,1,95,7,57,33,1,0,38,1  ; n321 t=90.324s dur=1887ms, sust 774->1887, freq=294Hz, sample=57
    db 109,1,254,5,69,33,1,1,93,1  ; n322 t=90.677s dur=1534ms, sust 456->1534, freq=349Hz, sample=69
    db 122,1,144,4,57,33,1,2,247,0  ; n323 t=91.042s dur=1168ms, sust 687->1168, freq=247Hz, sample=57
    db 120,1,22,3,57,33,1,3,38,1  ; n324 t=91.420s dur=790ms, sust 486->790, freq=294Hz, sample=57
    db 206,0,159,1,69,33,1,4,93,1  ; n325 t=91.796s dur=415ms, sust 126->415, freq=349Hz, sample=69
    db 30,0,183,9,33,36,1,5,44,0  ; n326 t=92.002s dur=2487ms, sust 1988->2487, freq=44Hz, sample=33
    db 157,0,153,9,45,36,1,6,87,0  ; n327 t=92.033s dur=2457ms, sust 916->2457, freq=87Hz, sample=45
    db 12,0,252,8,57,34,1,7,247,0  ; n328 t=92.189s dur=2300ms, sust 894->2300, freq=247Hz, sample=57
    db 130,1,241,8,69,42,2,8,238,1  ; n329 t=92.201s dur=2289ms, sust 1182->2289, freq=494Hz, sample=69
; t 92.2111 Sustain 0 (Instr 1)
; t 92.2111 Sustain 0 (Instr 2)
    db 134,1,111,7,57,33,1,9,21,1  ; n330 t=92.587s dur=1903ms, sust 495->1903, freq=277Hz, sample=57
; t 92.6065 Sustain 127 (Instr 1)
; t 92.6065 Sustain 127 (Instr 2)
    db 123,1,233,5,69,38,2,10,159,1  ; n331 t=92.977s dur=1513ms, sust 1017->1513, freq=415Hz, sample=69
    db 79,1,110,4,57,33,1,11,247,0  ; n332 t=93.356s dur=1134ms, sust 804->1134, freq=247Hz, sample=57
    db 127,1,84,3,57,33,1,12,21,1  ; n333 t=93.691s dur=852ms, freq=277Hz, sample=57
    db 220,0,181,1,69,43,2,13,159,1  ; n334 t=94.074s dur=437ms, freq=415Hz, sample=69
    db 51,0,180,9,33,37,1,14,46,0  ; n335 t=94.294s dur=2484ms, sust 1728->2484, freq=46Hz, sample=33
    db 135,0,129,9,45,38,1,15,92,0  ; n336 t=94.345s dur=2433ms, sust 660->2433, freq=92Hz, sample=45
    db 10,0,251,8,57,39,1,16,220,0  ; n337 t=94.480s dur=2299ms, sust 931->2299, freq=220Hz, sample=57
    db 123,1,241,8,69,48,2,17,184,1  ; n338 t=94.489s dur=2289ms, sust 1040->2289, freq=440Hz, sample=69
; t 94.4904 Sustain 0 (Instr 1)
; t 94.4904 Sustain 0 (Instr 2)
    db 147,1,118,7,57,33,1,18,21,1  ; n339 t=94.868s dur=1910ms, sust 875->1910, freq=277Hz, sample=57
; t 94.8987 Sustain 127 (Instr 1)
; t 94.8987 Sustain 127 (Instr 2)
    db 132,1,227,5,69,33,1,19,114,1  ; n340 t=95.271s dur=1507ms, sust 888->1507, freq=370Hz, sample=69
    db 121,1,95,4,57,33,1,20,220,0  ; n341 t=95.659s dur=1119ms, sust 826->1119, freq=220Hz, sample=57
    db 83,1,71,3,57,33,1,21,21,1  ; n342 t=96.036s dur=839ms, freq=277Hz, sample=57
    db 240,0,230,1,69,33,1,22,114,1  ; n343 t=96.375s dur=486ms, freq=370Hz, sample=69
    db 37,0,45,10,33,36,1,23,62,0  ; n344 t=96.615s dur=2605ms, sust 2133->2605, freq=62Hz, sample=33
    db 133,0,7,10,45,35,1,24,123,0  ; n345 t=96.652s dur=2567ms, sust 1120->2567, freq=123Hz, sample=45
; t 96.7786 Sustain 0 (Instr 1)
; t 96.7786 Sustain 0 (Instr 2)
    db 11,0,130,9,57,33,1,25,196,0  ; n346 t=96.785s dur=2434ms, sust 896->2434, freq=196Hz, sample=57
    db 149,1,119,9,69,44,2,26,136,1  ; n347 t=96.796s dur=2423ms, sust 1273->2423, freq=392Hz, sample=69
    db 144,1,226,7,57,33,1,27,247,0  ; n348 t=97.201s dur=2018ms, sust 838->2018, freq=247Hz, sample=57
; t 97.3227 Sustain 127 (Instr 1)
; t 97.3227 Sustain 127 (Instr 2)
    db 131,1,82,6,57,33,1,28,38,1  ; n349 t=97.601s dur=1618ms, sust 464->1618, freq=294Hz, sample=57
    db 141,1,208,4,57,33,1,29,196,0  ; n350 t=97.987s dur=1232ms, sust 809->1232, freq=196Hz, sample=57
; t 98.3804 Soft 127 (Instr 1)
; t 98.3804 Soft 127 (Instr 2)
    db 114,1,66,3,57,23,1,30,247,0  ; n351 t=98.385s dur=834ms, vel 33->23, sust 549->834, freq=247Hz, sample=57
    db 17,1,208,1,57,23,1,31,38,1  ; n352 t=98.755s dur=464ms, vel 33->23, sust 213->464, freq=294Hz, sample=57
    db 59,0,0,11,33,23,1,0,65,0  ; n353 t=99.028s dur=2816ms, vel 33->23, sust 1083->2816, freq=65Hz, sample=33
    db 63,0,197,10,45,23,1,1,131,0  ; n354 t=99.087s dur=2757ms, vel 33->23, sust 1819->2757, freq=131Hz, sample=45
    db 43,0,134,10,57,23,1,2,185,0  ; n355 t=99.150s dur=2694ms, vel 33->23, sust 1100->2694, freq=185Hz, sample=57
    db 208,1,90,10,69,27,1,3,114,1  ; n356 t=99.194s dur=2650ms, vel 39->27, sust 1837->2650, freq=370Hz, sample=69
; t 99.2196 Sustain 0 (Instr 1)
; t 99.2196 Sustain 0 (Instr 2)
; t 99.4617 Sustain 127 (Instr 1)
; t 99.4617 Sustain 127 (Instr 2)
    db 187,1,139,8,57,23,1,4,220,0  ; n357 t=99.657s dur=2187ms, vel 33->23, sust 905->2187, freq=220Hz, sample=57
    db 109,1,208,6,57,23,1,5,55,1  ; n358 t=100.100s dur=1744ms, vel 33->23, sust 436->1744, freq=311Hz, sample=57
    db 164,1,99,5,57,23,1,6,185,0  ; n359 t=100.465s dur=1379ms, vel 33->23, sust 1010->1379, freq=185Hz, sample=57
    db 203,1,191,3,57,23,1,7,220,0  ; n360 t=100.885s dur=959ms, vel 33->23, sust 629->959, freq=220Hz, sample=57
    db 239,1,244,1,57,23,1,8,55,1  ; n361 t=101.344s dur=500ms, vel 33->23, sust 181->500, freq=311Hz, sample=57
    db 8,0,55,10,45,23,1,9,139,0  ; n362 t=101.839s dur=2615ms, vel 33->23, sust 994->2615, freq=139Hz, sample=45
; t 101.8445 Sustain 0 (Instr 1)
; t 101.8445 Sustain 0 (Instr 2)
    db 37,0,47,10,33,23,1,10,69,0  ; n363 t=101.847s dur=2607ms, vel 33->23, sust 939->2607, freq=69Hz, sample=33
    db 205,1,10,10,57,25,1,11,21,1  ; n364 t=101.884s dur=2570ms, vel 36->25, sust 1272->2570, freq=277Hz, sample=57
; t 102.2017 Sustain 127 (Instr 1)
; t 102.2017 Sustain 127 (Instr 2)
    db 128,1,61,8,57,23,1,12,185,0  ; n365 t=102.345s dur=2109ms, vel 33->23, sust 908->2109, freq=185Hz, sample=57
    db 150,1,189,6,57,23,1,13,220,0  ; n366 t=102.729s dur=1725ms, vel 33->23, sust 629->1725, freq=220Hz, sample=57
; t 103.0112 Soft 127 (Instr 1)
; t 103.0112 Soft 127 (Instr 2)
    db 141,1,39,5,45,23,1,14,139,0  ; n367 t=103.135s dur=1319ms, vel 33->23, sust 940->1319, freq=139Hz, sample=45
    db 143,1,154,3,57,23,1,15,185,0  ; n368 t=103.532s dur=922ms, vel 33->23, sust 587->922, freq=185Hz, sample=57
    db 243,1,11,2,57,23,1,16,220,0  ; n369 t=103.931s dur=523ms, vel 33->23, sust 168->523, freq=220Hz, sample=57
    db 4,0,201,11,33,23,1,17,69,0  ; n370 t=104.431s dur=3017ms, vel 33->23, sust 2242->3017, freq=69Hz, sample=33
    db 2,0,180,5,45,23,1,18,139,0  ; n371 t=104.435s dur=1460ms, vel 33->23, sust 985->1460, freq=139Hz, sample=45
    db 37,0,194,11,21,23,1,19,35,0  ; n372 t=104.437s dur=3010ms, vel 33->23, sust 2204->3010, freq=35Hz, sample=21
; t 104.4544 Sustain 0 (Instr 1)
; t 104.4544 Sustain 0 (Instr 2)
    db 186,1,141,5,57,25,1,20,21,1  ; n373 t=104.474s dur=1421ms, vel 37->25, sust 895->1421, freq=277Hz, sample=57
; t 104.8950 Sustain 127 (Instr 1)
; t 104.8950 Sustain 127 (Instr 2)
    db 172,1,211,3,57,23,1,21,185,0  ; n374 t=104.916s dur=979ms, vel 33->23, sust 493->979, freq=185Hz, sample=57
    db 237,1,105,2,57,23,1,22,208,0  ; n375 t=105.343s dur=617ms, vel 33->23, freq=208Hz, sample=57
    db 14,0,75,6,45,23,1,23,139,0  ; n376 t=105.836s dur=1611ms, vel 33->23, sust 848->1611, freq=139Hz, sample=45
    db 0,2,61,6,57,24,1,24,21,1  ; n377 t=105.850s dur=1597ms, vel 35->24, sust 1222->1597, freq=277Hz, sample=57
; t 105.8955 Sustain 0 (Instr 1)
; t 105.8955 Sustain 0 (Instr 2)
    db 5,2,61,4,57,23,1,25,175,0  ; n378 t=106.362s dur=1085ms, vel 33->23, sust 416->1085, freq=175Hz, sample=57
; t 106.3945 Sustain 127 (Instr 1)
; t 106.3945 Sustain 127 (Instr 2)
    db 131,1,56,2,57,23,1,26,208,0  ; n379 t=106.879s dur=568ms, vel 33->23, sust 214->568, freq=208Hz, sample=57
    db 13,0,148,18,45,23,1,27,92,0  ; n380 t=107.267s dur=4756ms, vel 33->23, sust 1379->4756, freq=92Hz, sample=45
    db 38,0,148,18,33,23,1,28,46,0  ; n381 t=107.280s dur=4756ms, vel 34->23, sust 1960->4756, freq=46Hz, sample=33
    db 249,1,148,18,57,28,1,29,185,0  ; n382 t=107.318s dur=4756ms, vel 41->28, sust 637->4756, freq=185Hz, sample=57
; t 107.4478 Sustain 0 (Instr 1)
; t 107.4478 Sustain 0 (Instr 2)
; t 107.6897 Sustain 127 (Instr 1)
; t 107.6897 Sustain 127 (Instr 2)
    db 141,1,160,15,57,23,1,30,220,0  ; n383 t=107.823s dur=4000ms, vel 33->23, sust 405->4000, freq=220Hz, sample=57
    db 136,1,102,12,57,23,1,31,21,1  ; n384 t=108.220s dur=3174ms, vel 33->23, sust 375->3174, freq=277Hz, sample=57
    db 100,1,210,14,57,23,1,0,220,0  ; n385 t=108.612s dur=3794ms, vel 33->23, sust 370->3794, freq=220Hz, sample=57
    db 69,1,102,12,57,23,1,1,21,1  ; n386 t=108.968s dur=3174ms, vel 33->23, sust 398->3174, freq=277Hz, sample=57
    db 140,1,41,12,69,23,1,2,114,1  ; n387 t=109.293s dur=3113ms, vel 33->23, sust 442->3113, freq=370Hz, sample=69
    db 121,1,157,10,57,23,1,3,21,1  ; n388 t=109.689s dur=2717ms, vel 33->23, sust 873->2717, freq=277Hz, sample=57
    db 140,1,35,9,69,23,1,4,114,1  ; n389 t=110.066s dur=2339ms, vel 33->23, sust 1025->2339, freq=370Hz, sample=69
    db 188,1,152,7,69,26,2,5,184,1  ; n390 t=110.462s dur=1944ms, vel 38->26, sust 596->1944, freq=440Hz, sample=69
    db 61,0,220,5,57,23,1,6,21,1  ; n391 t=110.906s dur=1500ms, vel 33->23, sust 1263->1500, freq=277Hz, sample=57
    db 192,1,159,5,69,35,2,7,42,2  ; n392 t=110.966s dur=1439ms, vel 51->35, sust 889->1439, freq=554Hz, sample=69
    db 157,1,224,3,69,23,1,8,114,1  ; n393 t=111.414s dur=992ms, vel 33->23, sust 472->992, freq=370Hz, sample=69
    db 81,1,66,2,69,26,2,9,184,1  ; n394 t=111.827s dur=578ms, vel 38->26, sust 577->578, freq=440Hz, sample=69
    db 109,0,241,0,69,29,2,10,42,2  ; n395 t=112.164s dur=241ms, vel 42->29, sust 113->241, freq=554Hz, sample=69
    db 21,0,190,18,45,25,1,11,87,0  ; n396 t=112.274s dur=4798ms, vel 36->25, sust 4152->4798, freq=87Hz, sample=45
    db 39,0,102,12,45,25,1,12,139,0  ; n397 t=112.294s dur=3174ms, vel 36->25, sust 4163->3174, freq=139Hz, sample=45
    db 29,0,131,18,57,25,1,13,175,0  ; n398 t=112.334s dur=4739ms, vel 36->25, sust 4103->4739, freq=175Hz, sample=57
    db 21,0,102,12,69,36,2,14,42,2  ; n399 t=112.363s dur=3174ms, vel 52->36, sust 3018->3174, freq=554Hz, sample=69
    db 82,1,102,12,57,25,1,15,21,1  ; n400 t=112.383s dur=3174ms, vel 37->25, sust 802->3174, freq=277Hz, sample=57
; t 112.4061 Sustain 0 (Instr 1)
; t 112.4061 Sustain 0 (Instr 2)
    db 145,1,244,11,69,26,2,16,159,1  ; n401 t=112.722s dur=3060ms, vel 38->26, sust 762->3060, freq=415Hz, sample=69
; t 112.8073 Sustain 127 (Instr 1)
; t 112.8073 Sustain 127 (Instr 2)
    db 73,1,99,10,69,26,2,17,238,1  ; n402 t=113.123s dur=2659ms, vel 38->26, sust 865->2659, freq=494Hz, sample=69
    db 149,1,26,9,57,23,1,18,21,1  ; n403 t=113.451s dur=2330ms, vel 33->23, sust 870->2330, freq=277Hz, sample=57
    db 115,1,132,7,69,26,2,19,159,1  ; n404 t=113.857s dur=1924ms, vel 38->26, sust 846->1924, freq=415Hz, sample=69
    db 124,1,18,6,69,26,2,20,238,1  ; n405 t=114.228s dur=1554ms, vel 38->26, sust 903->1554, freq=494Hz, sample=69
    db 118,1,149,4,57,23,1,21,21,1  ; n406 t=114.608s dur=1173ms, vel 33->23, sust 800->1173, freq=277Hz, sample=57
    db 64,1,40,3,69,26,2,22,159,1  ; n407 t=114.982s dur=808ms, vel 38->26, freq=415Hz, sample=69
    db 193,1,250,1,69,26,2,23,238,1  ; n408 t=115.302s dur=506ms, vel 38->26, freq=494Hz, sample=69
    db 11,0,42,5,57,25,1,24,21,1  ; n409 t=115.750s dur=1322ms, vel 37->25, sust 719->1322, freq=277Hz, sample=57
    db 186,1,31,5,69,33,2,25,42,2  ; n410 t=115.761s dur=1311ms, vel 48->33, sust 776->1311, freq=554Hz, sample=69
; t 115.7818 Sustain 0 (Instr 1)
; t 115.7818 Sustain 0 (Instr 2)
; t 116.0181 Sustain 127 (Instr 1)
; t 116.0181 Sustain 127 (Instr 2)
    db 76,1,101,3,69,26,2,26,159,1  ; n411 t=116.203s dur=869ms, vel 38->26, sust 404->869, freq=415Hz, sample=69
    db 17,1,25,2,69,26,2,27,238,1  ; n412 t=116.535s dur=537ms, vel 38->26, sust 326->537, freq=494Hz, sample=69
    db 138,0,8,1,69,29,2,28,42,2  ; n413 t=116.808s dur=264ms, vel 42->29, sust 151->264, freq=554Hz, sample=69
    db 18,0,6,9,45,25,1,29,92,0  ; n414 t=116.946s dur=2310ms, vel 36->25, sust 1254->2310, freq=92Hz, sample=45
    db 81,0,243,8,57,25,1,30,185,0  ; n415 t=116.964s dur=2291ms, vel 37->25, sust 1486->2291, freq=185Hz, sample=57
    db 7,0,162,8,69,37,2,31,42,2  ; n416 t=117.046s dur=2210ms, vel 54->37, sust 1866->2210, freq=554Hz, sample=69
    db 105,1,155,8,57,25,1,0,21,1  ; n417 t=117.052s dur=2203ms, vel 37->25, sust 786->2203, freq=277Hz, sample=57
; t 117.0726 Sustain 0 (Instr 1)
; t 117.0726 Sustain 0 (Instr 2)
; t 117.3924 Sustain 127 (Instr 1)
; t 117.3924 Sustain 127 (Instr 2)
    db 107,1,51,7,69,23,1,1,114,1  ; n418 t=117.413s dur=1843ms, vel 33->23, sust 766->1843, freq=370Hz, sample=69
    db 95,1,199,5,69,26,2,2,184,1  ; n419 t=117.776s dur=1479ms, vel 38->26, sust 403->1479, freq=440Hz, sample=69
    db 138,1,104,4,57,23,1,3,21,1  ; n420 t=118.127s dur=1128ms, vel 33->23, sust 843->1128, freq=277Hz, sample=57
; t 118.1357 Soft 0 (Instr 1)
; t 118.1357 Soft 0 (Instr 2)
    db 119,1,24,3,69,33,1,4,114,1  ; n421 t=118.521s dur=792ms, freq=370Hz, sample=69
    db 232,0,148,1,69,41,2,5,184,1  ; n422 t=118.896s dur=404ms, freq=440Hz, sample=69
    db 30,0,240,4,33,39,1,6,78,0  ; n423 t=119.128s dur=1264ms, sust 1194->1264, freq=78Hz, sample=33
    db 115,0,209,4,45,39,1,7,156,0  ; n424 t=119.159s dur=1233ms, sust 829->1233, freq=156Hz, sample=45
; t 119.2560 Sustain 0 (Instr 1)
; t 119.2560 Sustain 0 (Instr 2)
    db 2,0,95,4,69,46,2,8,11,2  ; n425 t=119.273s dur=1119ms, sust 743->1119, freq=523Hz, sample=69
    db 141,1,93,4,57,37,1,9,6,1  ; n426 t=119.275s dur=1117ms, sust 769->1117, freq=262Hz, sample=57
; t 119.6016 Sustain 127 (Instr 1)
; t 119.6016 Sustain 127 (Instr 2)
    db 68,1,230,2,69,33,1,10,114,1  ; n427 t=119.672s dur=742ms, freq=370Hz, sample=69
    db 238,0,162,1,69,39,2,11,184,1  ; n428 t=119.996s dur=418ms, freq=440Hz, sample=69
    db 12,0,47,5,33,37,1,12,69,0  ; n429 t=120.234s dur=1327ms, sust 900->1327, freq=69Hz, sample=33
    db 115,0,35,5,45,37,1,13,139,0  ; n430 t=120.246s dur=1315ms, sust 868->1315, freq=139Hz, sample=45
    db 3,0,176,4,57,36,1,14,21,1  ; n431 t=120.361s dur=1200ms, sust 784->1200, freq=277Hz, sample=57
    db 147,1,173,4,69,44,2,15,42,2  ; n432 t=120.364s dur=1197ms, sust 768->1197, freq=554Hz, sample=69
; t 120.3925 Sustain 0 (Instr 1)
; t 120.3925 Sustain 0 (Instr 2)
    db 100,1,26,3,69,33,1,16,114,1  ; n433 t=120.767s dur=794ms, sust 416->794, freq=370Hz, sample=69
; t 120.7879 Sustain 127 (Instr 1)
; t 120.7879 Sustain 127 (Instr 2)
    db 14,1,194,1,69,39,2,17,184,1  ; n434 t=121.124s dur=450ms, freq=440Hz, sample=69
; t 121.1975 Soft 0 (Instr 1)
; t 121.1975 Soft 0 (Instr 2)
    db 6,0,251,12,33,36,1,18,65,0  ; n435 t=121.394s dur=3323ms, sust 1422->3323, freq=65Hz, sample=33
    db 0,0,245,12,45,36,1,19,104,0  ; n436 t=121.400s dur=3317ms, sust 1565->3317, freq=104Hz, sample=45
    db 107,0,245,12,45,36,1,20,131,0  ; n437 t=121.400s dur=3317ms, sust 1929->3317, freq=131Hz, sample=45
    db 2,0,12,11,69,44,2,21,110,2  ; n438 t=121.507s dur=2828ms, sust 1595->2828, freq=622Hz, sample=69
    db 127,1,12,11,57,35,1,22,55,1  ; n439 t=121.510s dur=2828ms, sust 811->2828, freq=311Hz, sample=57
; t 121.5615 Sustain 0 (Instr 1)
; t 121.5615 Sustain 0 (Instr 2)
    db 48,1,8,11,69,33,1,23,114,1  ; n440 t=121.893s dur=2824ms, sust 478->2824, freq=370Hz, sample=69
; t 121.9352 Sustain 127 (Instr 1)
; t 121.9352 Sustain 127 (Instr 2)
    db 97,1,216,9,69,38,2,24,159,1  ; n441 t=122.197s dur=2520ms, sust 468->2520, freq=415Hz, sample=69
    db 98,1,119,8,57,33,1,25,55,1  ; n442 t=122.550s dur=2167ms, sust 823->2167, freq=311Hz, sample=57
    db 77,1,20,7,69,33,1,26,114,1  ; n443 t=122.904s dur=1812ms, sust 778->1812, freq=370Hz, sample=69
    db 124,1,200,5,69,38,2,27,159,1  ; n444 t=123.237s dur=1480ms, sust 465->1480, freq=415Hz, sample=69
    db 44,1,76,4,57,33,1,28,55,1  ; n445 t=123.617s dur=1100ms, sust 646->1100, freq=311Hz, sample=57
    db 118,1,43,3,69,33,1,29,114,1  ; n446 t=123.917s dur=811ms, freq=370Hz, sample=69
    db 239,0,175,1,69,38,2,30,159,1  ; n447 t=124.291s dur=431ms, freq=415Hz, sample=69
    db 7,0,130,5,33,36,1,31,65,0  ; n448 t=124.530s dur=1410ms, sust 756->1410, freq=65Hz, sample=33
    db 37,0,124,5,45,36,1,0,104,0  ; n449 t=124.537s dur=1404ms, sust 756->1404, freq=104Hz, sample=45
    db 90,0,87,5,45,35,1,1,131,0  ; n450 t=124.573s dur=1367ms, sust 705->1367, freq=131Hz, sample=45
    db 35,0,253,4,57,34,1,2,55,1  ; n451 t=124.663s dur=1277ms, sust 671->1277, freq=311Hz, sample=57
    db 143,1,219,4,69,51,2,3,110,2  ; n452 t=124.698s dur=1243ms, sust 834->1243, freq=622Hz, sample=69
; t 124.7173 Sustain 0 (Instr 1)
; t 124.7173 Sustain 0 (Instr 2)
; t 124.9751 Sustain 127 (Instr 1)
; t 124.9751 Sustain 127 (Instr 2)
    db 69,1,76,3,69,33,1,4,114,1  ; n453 t=125.096s dur=844ms, sust 487->844, freq=370Hz, sample=69
; t 125.2469 Soft 127 (Instr 1)
; t 125.2469 Soft 127 (Instr 2)
    db 42,1,7,2,69,26,2,5,159,1  ; n454 t=125.421s dur=519ms, vel 38->26, sust 176->519, freq=415Hz, sample=69
    db 44,0,191,9,33,25,1,6,69,0  ; n455 t=125.719s dur=2495ms, vel 36->25, sust 1764->2495, freq=69Hz, sample=33
    db 115,0,146,9,45,25,1,7,139,0  ; n456 t=125.763s dur=2450ms, vel 36->25, sust 1150->2450, freq=139Hz, sample=45
    db 42,0,32,9,69,24,1,8,74,1  ; n457 t=125.878s dur=2336ms, vel 35->24, sust 900->2336, freq=330Hz, sample=69
    db 108,1,245,8,81,33,2,9,147,2  ; n458 t=125.920s dur=2293ms, vel 48->33, sust 1398->2293, freq=659Hz, sample=81
; t 125.9409 Sustain 0 (Instr 1)
; t 125.9409 Sustain 0 (Instr 2)
    db 164,1,138,7,69,26,2,10,159,1  ; n459 t=126.284s dur=1930ms, vel 38->26, sust 862->1930, freq=415Hz, sample=69
; t 126.3783 Sustain 127 (Instr 1)
; t 126.3783 Sustain 127 (Instr 2)
    db 102,1,230,5,69,26,2,11,42,2  ; n460 t=126.704s dur=1510ms, vel 38->26, sust 922->1510, freq=554Hz, sample=69
    db 132,1,127,4,69,23,1,12,74,1  ; n461 t=127.062s dur=1151ms, vel 33->23, sust 849->1151, freq=330Hz, sample=69
    db 130,1,252,2,69,26,2,13,159,1  ; n462 t=127.450s dur=764ms, vel 38->26, sust 682->764, freq=415Hz, sample=69
    db 246,0,199,1,69,26,2,14,42,2  ; n463 t=127.837s dur=455ms, vel 38->26, freq=554Hz, sample=69
    db 50,0,73,5,33,25,1,15,46,0  ; n464 t=128.082s dur=1353ms, vel 36->25, sust 907->1353, freq=46Hz, sample=33
    db 108,0,23,5,45,25,1,16,92,0  ; n465 t=128.132s dur=1303ms, vel 36->25, sust 823->1303, freq=92Hz, sample=45
; t 128.2143 Sustain 0 (Instr 1)
; t 128.2143 Sustain 0 (Instr 2)
    db 23,0,171,4,57,23,1,17,55,1  ; n466 t=128.240s dur=1195ms, vel 34->23, sust 897->1195, freq=311Hz, sample=57
    db 139,1,148,4,69,36,2,18,110,2  ; n467 t=128.263s dur=1172ms, vel 52->36, sust 776->1172, freq=622Hz, sample=69
; t 128.5499 Sustain 127 (Instr 1)
; t 128.5499 Sustain 127 (Instr 2)
    db 124,1,9,3,69,23,1,19,114,1  ; n468 t=128.658s dur=777ms, vel 33->23, sust 524->777, freq=370Hz, sample=69
    db 3,1,213,1,69,26,2,20,184,1  ; n469 t=129.038s dur=469ms, vel 38->26, freq=440Hz, sample=69
    db 38,0,157,5,33,25,1,21,49,0  ; n470 t=129.297s dur=1437ms, vel 36->25, sust 857->1437, freq=49Hz, sample=33
    db 112,0,119,5,45,24,1,22,98,0  ; n471 t=129.335s dur=1399ms, vel 35->24, sust 836->1399, freq=98Hz, sample=45
; t 129.4354 Sustain 0 (Instr 1)
; t 129.4354 Sustain 0 (Instr 2)
    db 3,0,7,5,69,30,2,23,42,2  ; n472 t=129.446s dur=1287ms, vel 43->30, sust 1029->1287, freq=554Hz, sample=69
    db 213,1,4,5,57,23,1,24,21,1  ; n473 t=129.450s dur=1284ms, vel 34->23, sust 1034->1284, freq=277Hz, sample=57
; t 129.7579 Sustain 127 (Instr 1)
; t 129.7579 Sustain 127 (Instr 2)
    db 177,1,52,3,69,23,1,25,74,1  ; n474 t=129.918s dur=820ms, vel 33->23, freq=330Hz, sample=69
    db 35,1,212,1,69,26,2,26,210,1  ; n475 t=130.351s dur=468ms, vel 38->26, freq=466Hz, sample=69
    db 25,0,99,16,33,27,1,27,52,0  ; n476 t=130.642s dur=4195ms, vel 39->27, sust 3769->4195, freq=52Hz, sample=33
    db 91,0,74,16,45,27,1,28,104,0  ; n477 t=130.667s dur=4170ms, vel 39->27, sust 3736->4170, freq=104Hz, sample=45
; t 130.7339 Sustain 0 (Instr 1)
; t 130.7339 Sustain 0 (Instr 2)
    db 85,1,72,4,69,32,2,29,11,2  ; n478 t=130.758s dur=1096ms, vel 47->32, sust 448->1096, freq=523Hz, sample=69
; t 131.0337 Sustain 127 (Instr 1)
; t 131.0337 Sustain 127 (Instr 2)
    db 75,1,243,2,57,23,1,30,6,1  ; n479 t=131.099s dur=755ms, vel 33->23, sust 454->755, freq=262Hz, sample=57
    db 89,1,187,1,57,23,1,31,55,1  ; n480 t=131.430s dur=443ms, vel 33->23, freq=311Hz, sample=57
    db 111,1,45,4,69,30,2,0,159,1  ; n481 t=131.775s dur=1069ms, vel 43->30, freq=415Hz, sample=69
; t 131.8539 Sustain 0 (Instr 1)
; t 131.8539 Sustain 0 (Instr 2)
; t 132.0844 Sustain 127 (Instr 1)
; t 132.0844 Sustain 127 (Instr 2)
    db 89,1,189,2,57,25,1,1,6,1  ; n482 t=132.142s dur=701ms, vel 36->25, sust 411->701, freq=262Hz, sample=57
    db 47,1,115,1,57,23,1,2,55,1  ; n483 t=132.487s dur=371ms, vel 33->23, freq=311Hz, sample=57
    db 122,1,126,4,69,33,2,3,184,1  ; n484 t=132.790s dur=1150ms, vel 48->33, sust 1055->1150, freq=440Hz, sample=69
; t 132.8430 Sustain 0 (Instr 1)
; t 132.8430 Sustain 0 (Instr 2)
    db 126,1,4,3,57,23,1,4,6,1  ; n485 t=133.168s dur=772ms, vel 33->23, sust 531->772, freq=262Hz, sample=57
; t 133.2434 Sustain 127 (Instr 1)
; t 133.2434 Sustain 127 (Instr 2)
    db 44,1,192,1,57,23,1,5,55,1  ; n486 t=133.549s dur=448ms, vel 34->23, freq=311Hz, sample=57
    db 47,1,220,3,69,30,1,6,114,1  ; n487 t=133.849s dur=988ms, vel 44->30, sust 825->988, freq=370Hz, sample=69
; t 133.9400 Sustain 0 (Instr 1)
; t 133.9400 Sustain 0 (Instr 2)
    db 67,1,173,2,57,23,1,7,6,1  ; n488 t=134.152s dur=685ms, vel 33->23, sust 358->685, freq=262Hz, sample=57
; t 134.2029 Sustain 127 (Instr 1)
; t 134.2029 Sustain 127 (Instr 2)
    db 24,1,106,1,57,23,1,8,55,1  ; n489 t=134.475s dur=362ms, vel 33->23, sust 220->362, freq=311Hz, sample=57
    db 2,0,174,15,45,25,1,9,104,0  ; n490 t=134.756s dur=4014ms, vel 37->25, sust 3548->4014, freq=104Hz, sample=45
    db 53,1,172,15,33,25,1,10,52,0  ; n491 t=134.758s dur=4012ms, vel 37->25, sust 3539->4012, freq=52Hz, sample=33
; t 134.8378 Sustain 0 (Instr 1)
; t 134.8378 Sustain 0 (Instr 2)
; t 135.0455 Sustain 127 (Instr 1)
; t 135.0455 Sustain 127 (Instr 2)
    db 67,1,192,2,57,23,1,11,6,1  ; n492 t=135.067s dur=704ms, vel 33->23, freq=262Hz, sample=57
    db 58,1,60,5,57,23,1,12,55,1  ; n493 t=135.391s dur=1340ms, vel 34->23, sust 653->1340, freq=311Hz, sample=57
    db 121,1,2,4,57,30,1,13,208,0  ; n494 t=135.704s dur=1026ms, vel 44->30, sust 750->1026, freq=208Hz, sample=57
; t 135.7172 Sustain 0 (Instr 1)
; t 135.7172 Sustain 0 (Instr 2)
; t 135.9271 Sustain 127 (Instr 1)
; t 135.9271 Sustain 127 (Instr 2)
    db 44,1,138,2,57,23,1,14,6,1  ; n495 t=136.081s dur=650ms, vel 33->23, sust 406->650, freq=262Hz, sample=57
    db 44,1,4,2,57,23,1,15,55,1  ; n496 t=136.380s dur=516ms, vel 33->23, freq=311Hz, sample=57
    db 93,1,32,4,57,33,1,16,220,0  ; n497 t=136.680s dur=1056ms, vel 48->33, sust 701->1056, freq=220Hz, sample=57
; t 136.7308 Sustain 0 (Instr 1)
; t 136.7308 Sustain 0 (Instr 2)
; t 136.9460 Sustain 127 (Instr 1)
; t 136.9460 Sustain 127 (Instr 2)
    db 69,1,195,2,57,23,1,17,6,1  ; n498 t=137.029s dur=707ms, vel 33->23, sust 466->707, freq=262Hz, sample=57
    db 73,1,152,1,57,23,1,18,55,1  ; n499 t=137.354s dur=408ms, vel 33->23, freq=311Hz, sample=57
    db 146,1,63,4,57,28,1,19,185,0  ; n500 t=137.683s dur=1087ms, vel 40->28, sust 929->1087, freq=185Hz, sample=57
; t 137.7365 Sustain 0 (Instr 1)
; t 137.7365 Sustain 0 (Instr 2)
; t 137.9852 Sustain 127 (Instr 1)
; t 137.9852 Sustain 127 (Instr 2)
    db 115,1,173,2,57,23,1,20,6,1  ; n501 t=138.085s dur=685ms, vel 33->23, sust 577->685, freq=262Hz, sample=57
    db 215,0,58,1,57,23,1,21,55,1  ; n502 t=138.456s dur=314ms, vel 33->23, sust 231->314, freq=311Hz, sample=57
    db 19,0,234,14,33,24,1,22,52,0  ; n503 t=138.671s dur=3818ms, vel 35->24, sust 3363->3818, freq=52Hz, sample=33
    db 102,0,214,14,45,25,1,23,104,0  ; n504 t=138.690s dur=3798ms, vel 36->25, sust 3335->3798, freq=104Hz, sample=45
; t 138.7702 Sustain 0 (Instr 1)
; t 138.7702 Sustain 0 (Instr 2)
    db 36,1,13,11,57,25,1,24,165,0  ; n505 t=138.792s dur=2829ms, vel 37->25, sust 282->2829, freq=165Hz, sample=57
; t 138.9713 Sustain 127 (Instr 1)
; t 138.9713 Sustain 127 (Instr 2)
    db 30,1,233,9,69,23,1,25,74,1  ; n506 t=139.084s dur=2537ms, vel 33->23, sust 149->2537, freq=330Hz, sample=69
    db 77,1,202,8,69,26,2,26,159,1  ; n507 t=139.370s dur=2250ms, vel 38->26, sust 514->2250, freq=415Hz, sample=69
    db 63,1,125,7,69,35,2,27,42,2  ; n508 t=139.703s dur=1917ms, vel 50->35, sust 1002->1917, freq=554Hz, sample=69
    db 5,1,62,6,69,23,1,28,74,1  ; n509 t=140.022s dur=1598ms, vel 33->23, sust 354->1598, freq=330Hz, sample=69
    db 94,1,58,5,69,26,2,29,159,1  ; n510 t=140.283s dur=1338ms, vel 38->26, sust 436->1338, freq=415Hz, sample=69
    db 13,1,219,3,81,34,2,30,147,2  ; n511 t=140.633s dur=987ms, vel 49->34, sust 677->987, freq=659Hz, sample=81
    db 53,1,216,2,69,23,1,31,74,1  ; n512 t=140.902s dur=728ms, vel 33->23, freq=330Hz, sample=69
    db 107,1,213,1,69,26,2,0,159,1  ; n513 t=141.212s dur=469ms, vel 38->26, freq=415Hz, sample=69
    db 34,1,146,3,69,35,2,1,42,2  ; n514 t=141.575s dur=914ms, vel 51->35, sust 690->914, freq=554Hz, sample=69
; t 141.6212 Sustain 0 (Instr 1)
; t 141.6212 Sustain 0 (Instr 2)
; t 141.8201 Sustain 127 (Instr 1)
; t 141.8201 Sustain 127 (Instr 2)
    db 15,1,112,2,69,23,1,2,74,1  ; n515 t=141.864s dur=624ms, vel 33->23, sust 345->624, freq=330Hz, sample=69
    db 255,0,97,1,69,26,2,3,159,1  ; n516 t=142.136s dur=353ms, vel 38->26, sust 180->353, freq=415Hz, sample=69
    db 18,0,26,14,33,25,1,4,52,0  ; n517 t=142.391s dur=3610ms, vel 36->25, sust 3266->3610, freq=52Hz, sample=33
    db 25,1,8,14,45,25,1,5,104,0  ; n518 t=142.409s dur=3592ms, vel 36->25, sust 3240->3592, freq=104Hz, sample=45
; t 142.4891 Sustain 0 (Instr 1)
; t 142.4891 Sustain 0 (Instr 2)
    db 242,0,235,5,57,23,1,6,165,0  ; n519 t=142.690s dur=1515ms, vel 33->23, sust 684->1515, freq=165Hz, sample=57
; t 142.7107 Sustain 127 (Instr 1)
; t 142.7107 Sustain 127 (Instr 2)
    db 89,1,249,4,57,23,1,7,208,0  ; n520 t=142.932s dur=1273ms, vel 34->23, sust 488->1273, freq=208Hz, sample=57
    db 51,1,160,3,57,31,1,8,21,1  ; n521 t=143.277s dur=928ms, vel 45->31, freq=277Hz, sample=57
    db 243,0,109,2,57,23,1,9,165,0  ; n522 t=143.584s dur=621ms, vel 33->23, sust 583->621, freq=165Hz, sample=57
    db 62,1,122,1,57,23,1,10,208,0  ; n523 t=143.827s dur=378ms, vel 33->23, sust 373->378, freq=208Hz, sample=57
    db 89,1,56,4,69,28,1,11,74,1  ; n524 t=144.145s dur=1080ms, vel 40->28, sust 662->1080, freq=330Hz, sample=69
; t 144.2055 Sustain 0 (Instr 1)
; t 144.2055 Sustain 0 (Instr 2)
; t 144.4346 Sustain 127 (Instr 1)
; t 144.4346 Sustain 127 (Instr 2)
    db 8,1,223,2,57,23,1,12,165,0  ; n525 t=144.490s dur=735ms, vel 33->23, sust 681->735, freq=165Hz, sample=57
    db 102,1,216,1,57,23,1,13,208,0  ; n526 t=144.754s dur=472ms, vel 33->23, sust 443->472, freq=208Hz, sample=57
    db 75,1,122,3,57,28,1,14,21,1  ; n527 t=145.111s dur=890ms, vel 40->28, sust 715->890, freq=277Hz, sample=57
; t 145.2257 Sustain 0 (Instr 1)
; t 145.2257 Sustain 0 (Instr 2)
; t 145.3985 Sustain 127 (Instr 1)
; t 145.3985 Sustain 127 (Instr 2)
    db 25,1,47,2,57,23,1,15,165,0  ; n528 t=145.442s dur=559ms, vel 33->23, sust 353->559, freq=165Hz, sample=57
    db 166,0,22,1,57,23,1,16,208,0  ; n529 t=145.723s dur=278ms, vel 33->23, sust 168->278, freq=208Hz, sample=57
    db 37,0,171,13,33,25,1,17,52,0  ; n530 t=145.889s dur=3499ms, vel 36->25, sust 1108->3499, freq=52Hz, sample=33
    db 107,0,134,13,45,25,1,18,104,0  ; n531 t=145.926s dur=3462ms, vel 36->25, sust 1401->3462, freq=104Hz, sample=45
; t 146.0014 Sustain 0 (Instr 1)
; t 146.0014 Sustain 0 (Instr 2)
    db 255,0,12,11,45,32,1,19,156,0  ; n532 t=146.033s dur=2828ms, vel 47->32, sust 587->2828, freq=156Hz, sample=45
; t 146.2250 Sustain 127 (Instr 1)
; t 146.2250 Sustain 127 (Instr 2)
; t 146.2769 Soft 0 (Instr 1)
; t 146.2769 Soft 0 (Instr 2)
    db 42,1,28,12,57,36,1,20,220,0  ; n533 t=146.288s dur=3100ms, sust 682->3100, freq=220Hz, sample=57
    db 44,1,242,10,57,38,1,21,185,0  ; n534 t=146.586s dur=2802ms, sust 378->2802, freq=185Hz, sample=57
    db 29,1,198,9,57,34,1,22,6,1  ; n535 t=146.886s dur=2502ms, sust 274->2502, freq=262Hz, sample=57
    db 19,1,168,8,57,38,1,23,220,0  ; n536 t=147.172s dur=2216ms, sust 526->2216, freq=220Hz, sample=57
    db 249,0,149,7,57,42,1,24,55,1  ; n537 t=147.447s dur=1941ms, sust 379->1941, freq=311Hz, sample=57
    db 75,1,155,6,57,45,1,25,6,1  ; n538 t=147.696s dur=1691ms, sust 412->1691, freq=262Hz, sample=57
    db 242,0,81,5,69,45,1,26,114,1  ; n539 t=148.027s dur=1361ms, sust 160->1361, freq=370Hz, sample=69
    db 15,1,95,4,57,49,1,27,55,1  ; n540 t=148.269s dur=1119ms, sust 510->1119, freq=311Hz, sample=57
    db 10,1,79,3,69,51,2,28,184,1  ; n541 t=148.540s dur=847ms, sust 460->847, freq=440Hz, sample=69
    db 5,1,70,2,69,44,1,29,114,1  ; n542 t=148.806s dur=582ms, sust 360->582, freq=370Hz, sample=69
    db 150,0,64,1,69,49,2,30,11,2  ; n543 t=149.067s dur=320ms, sust 78->320, freq=523Hz, sample=69
    db 38,0,108,12,33,44,1,31,52,0  ; n544 t=149.218s dur=3180ms, sust 1168->3180, freq=52Hz, sample=33
    db 107,0,70,12,45,45,1,0,104,0  ; n545 t=149.255s dur=3142ms, sust 1211->3142, freq=104Hz, sample=45
    db 250,0,219,11,57,55,1,1,165,0  ; n546 t=149.362s dur=3035ms, sust 310->3035, freq=165Hz, sample=57
; t 149.3882 Sustain 0 (Instr 1)
; t 149.3882 Sustain 0 (Instr 2)
; t 149.6042 Sustain 127 (Instr 1)
; t 149.6042 Sustain 127 (Instr 2)
    db 237,0,225,10,57,39,1,2,21,1  ; n547 t=149.613s dur=2785ms, sust 238->2785, freq=277Hz, sample=57
    db 2,1,244,9,57,43,1,3,208,0  ; n548 t=149.849s dur=2548ms, sust 294->2548, freq=208Hz, sample=57
    db 17,1,242,8,69,46,1,4,74,1  ; n549 t=150.107s dur=2290ms, sust 540->2290, freq=330Hz, sample=69
    db 232,0,225,7,57,42,1,5,21,1  ; n550 t=150.381s dur=2017ms, sust 323->2017, freq=277Hz, sample=57
    db 254,0,249,6,69,47,2,6,159,1  ; n551 t=150.613s dur=1785ms, sust 224->1785, freq=415Hz, sample=69
    db 254,0,251,5,69,36,1,7,74,1  ; n552 t=150.867s dur=1531ms, sust 424->1531, freq=330Hz, sample=69
    db 252,0,253,4,69,49,2,8,42,2  ; n553 t=151.120s dur=1277ms, sust 424->1277, freq=554Hz, sample=69
    db 252,0,1,4,69,53,2,9,159,1  ; n554 t=151.372s dur=1025ms, sust 455->1025, freq=415Hz, sample=69
    db 249,0,6,3,81,56,2,10,147,2  ; n555 t=151.624s dur=774ms, sust 297->774, freq=659Hz, sample=81
    db 225,0,12,2,69,53,2,11,42,2  ; n556 t=151.873s dur=524ms, sust 284->524, freq=554Hz, sample=69
    db 161,0,44,1,69,53,2,12,159,1  ; n557 t=152.098s dur=300ms, sust 111->300, freq=415Hz, sample=69
; t 152.2220 Soft 0 (Instr 1)
; t 152.2220 Soft 0 (Instr 2)
    db 25,0,237,10,33,38,1,13,52,0  ; n558 t=152.259s dur=2797ms, sust 1233->2797, freq=52Hz, sample=33
    db 88,0,212,10,45,38,1,14,104,0  ; n559 t=152.284s dur=2772ms, sust 1219->2772, freq=104Hz, sample=45
    db 221,0,123,10,57,39,1,15,21,1  ; n560 t=152.372s dur=2683ms, sust 419->2683, freq=277Hz, sample=57
; t 152.3980 Sustain 0 (Instr 1)
; t 152.3980 Sustain 0 (Instr 2)
; t 152.5924 Sustain 127 (Instr 1)
; t 152.5924 Sustain 127 (Instr 2)
    db 229,0,158,9,69,59,2,16,136,1  ; n561 t=152.594s dur=2462ms, sust 407->2462, freq=392Hz, sample=69
    db 232,0,185,8,69,43,1,17,74,1  ; n562 t=152.822s dur=2233ms, sust 288->2233, freq=330Hz, sample=69
    db 213,0,209,7,69,55,2,18,210,1  ; n563 t=153.054s dur=2001ms, sust 234->2001, freq=466Hz, sample=69
    db 204,0,252,6,69,58,2,19,136,1  ; n564 t=153.267s dur=1788ms, sust 310->1788, freq=392Hz, sample=69
    db 239,0,48,6,69,61,2,20,42,2  ; n565 t=153.471s dur=1584ms, sust 380->1584, freq=554Hz, sample=69
    db 233,0,66,5,69,64,2,21,210,1  ; n566 t=153.710s dur=1346ms, sust 288->1346, freq=466Hz, sample=69
    db 239,0,88,4,81,61,2,22,147,2  ; n567 t=153.943s dur=1112ms, sust 146->1112, freq=659Hz, sample=81
    db 194,0,106,3,69,61,2,23,42,2  ; n568 t=154.182s dur=874ms, sust 275->874, freq=554Hz, sample=69
    db 204,0,168,2,81,64,2,24,16,3  ; n569 t=154.376s dur=680ms, sust 284->680, freq=784Hz, sample=81
    db 188,0,220,1,81,67,2,25,147,2  ; n570 t=154.580s dur=476ms, sust 224->476, freq=659Hz, sample=81
    db 134,0,32,1,81,69,2,26,164,3  ; n571 t=154.768s dur=288ms, sust 82->288, freq=932Hz, sample=81
    db 11,0,141,16,33,55,1,27,52,0  ; n572 t=154.902s dur=4237ms, sust 7560->4237, freq=52Hz, sample=33
    db 113,0,141,16,45,55,1,28,104,0  ; n573 t=154.912s dur=4237ms, sust 7548->4237, freq=104Hz, sample=45
    db 208,0,148,18,69,54,1,29,114,1  ; n574 t=155.026s dur=4756ms, sust 299->4756, freq=370Hz, sample=69
; t 155.0560 Sustain 0 (Instr 1)
; t 155.0560 Sustain 0 (Instr 2)
    db 186,0,35,13,69,70,2,30,11,2  ; n575 t=155.234s dur=3363ms, sust 240->3363, freq=523Hz, sample=69
; t 155.2805 Sustain 127 (Instr 1)
; t 155.2805 Sustain 127 (Instr 2)
    db 210,0,160,15,69,70,2,31,184,1  ; n576 t=155.420s dur=4000ms, sust 250->4000, freq=440Hz, sample=69
    db 215,0,12,11,69,70,2,0,110,2  ; n577 t=155.630s dur=2828ms, sust 192->2828, freq=622Hz, sample=69
    db 160,0,35,13,69,70,2,1,11,2  ; n578 t=155.845s dur=3363ms, sust 239->3363, freq=523Hz, sample=69
    db 235,0,148,18,81,70,2,2,228,2  ; n579 t=156.005s dur=4756ms, sust 302->4756, freq=740Hz, sample=81
    db 184,0,12,11,69,70,2,3,110,2  ; n580 t=156.240s dur=2828ms, sust 200->2828, freq=622Hz, sample=69
    db 184,0,160,15,81,70,2,4,112,3  ; n581 t=156.424s dur=4000ms, sust 92->4000, freq=880Hz, sample=81
    db 200,0,183,17,81,70,2,5,228,2  ; n582 t=156.607s dur=4535ms, sust 153->4535, freq=740Hz, sample=81
    db 191,0,35,13,81,70,2,6,23,4  ; n583 t=156.807s dur=3363ms, sust 226->3363, freq=1047Hz, sample=81
    db 178,0,160,15,81,70,2,7,112,3  ; n584 t=156.998s dur=4000ms, sust 214->4000, freq=880Hz, sample=81
    db 192,0,12,11,81,70,2,8,221,4  ; n585 t=157.176s dur=2828ms, sust 145->2828, freq=1245Hz, sample=81
    db 207,0,35,13,81,67,2,9,23,4  ; n586 t=157.368s dur=3363ms, sust 176->3363, freq=1047Hz, sample=81
    db 162,0,239,13,81,64,2,10,228,2  ; n587 t=157.575s dur=3567ms, sust 135->3567, freq=740Hz, sample=81
    db 226,0,77,13,81,62,2,11,112,3  ; n588 t=157.737s dur=3405ms, sust 278->3405, freq=880Hz, sample=81
    db 189,0,12,11,69,59,2,12,110,2  ; n589 t=157.963s dur=2828ms, sust 249->2828, freq=622Hz, sample=69
    db 212,0,175,11,81,57,2,13,228,2  ; n590 t=158.151s dur=2991ms, sust 254->2991, freq=740Hz, sample=81
    db 191,0,219,10,69,54,2,14,11,2  ; n591 t=158.363s dur=2779ms, sust 207->2779, freq=523Hz, sample=69
    db 190,0,28,10,69,51,2,15,110,2  ; n592 t=158.554s dur=2588ms, sust 210->2588, freq=622Hz, sample=69
    db 190,0,94,9,69,49,2,16,184,1  ; n593 t=158.744s dur=2398ms, sust 250->2398, freq=440Hz, sample=69
    db 204,0,160,8,69,46,2,17,11,2  ; n594 t=158.934s dur=2208ms, sust 212->2208, freq=523Hz, sample=69
    db 200,0,212,7,69,38,1,18,114,1  ; n595 t=159.138s dur=2004ms, sust 228->2004, freq=370Hz, sample=69
    db 213,0,13,7,69,41,2,19,184,1  ; n596 t=159.337s dur=1805ms, sust 238->1805, freq=440Hz, sample=69
    db 209,0,56,6,57,33,1,20,55,1  ; n597 t=159.550s dur=1592ms, sust 269->1592, freq=311Hz, sample=57
    db 210,0,103,5,69,33,1,21,114,1  ; n598 t=159.759s dur=1383ms, sust 330->1383, freq=370Hz, sample=69
    db 228,0,148,4,57,33,1,22,6,1  ; n599 t=159.970s dur=1172ms, sust 248->1172, freq=262Hz, sample=57
    db 221,0,177,3,57,33,1,23,55,1  ; n600 t=160.197s dur=945ms, sust 256->945, freq=311Hz, sample=57
    db 185,0,211,2,57,33,1,24,220,0  ; n601 t=160.419s dur=723ms, sust 237->723, freq=220Hz, sample=57
    db 202,0,27,2,57,33,1,25,6,1  ; n602 t=160.603s dur=539ms, sust 193->539, freq=262Hz, sample=57
    db 209,0,81,1,57,33,1,26,185,0  ; n603 t=160.805s dur=337ms, sust 244->337, freq=185Hz, sample=57
    db 11,1,38,4,57,33,1,27,220,0  ; n604 t=161.014s dur=1062ms, sust 568->1062, freq=220Hz, sample=57
; t 161.1424 Sustain 0 (Instr 1)
; t 161.1424 Sustain 0 (Instr 2)
    db 56,1,27,3,45,38,1,28,156,0  ; n605 t=161.282s dur=795ms, sust 576->795, freq=156Hz, sample=45
; t 161.3830 Sustain 127 (Instr 1)
; t 161.3830 Sustain 127 (Instr 2)
    db 109,1,227,1,57,33,1,29,185,0  ; n606 t=161.593s dur=483ms, sust 283->483, freq=185Hz, sample=57
    db 98,0,185,3,57,34,1,30,220,0  ; n607 t=161.958s dur=953ms, sust 382->953, freq=220Hz, sample=57
    db 32,1,87,3,45,41,1,31,139,0  ; n608 t=162.056s dur=855ms, sust 475->855, freq=139Hz, sample=45
; t 162.0766 Sustain 0 (Instr 1)
; t 162.0766 Sustain 0 (Instr 2)
; t 162.3009 Sustain 127 (Instr 1)
; t 162.3009 Sustain 127 (Instr 2)
    db 247,0,55,2,57,33,1,0,185,0  ; n609 t=162.344s dur=567ms, sust 371->567, freq=185Hz, sample=57
    db 150,0,146,2,57,33,1,1,220,0  ; n610 t=162.591s dur=658ms, freq=220Hz, sample=57
    db 41,0,133,14,33,35,1,2,52,0  ; n611 t=162.741s dur=3717ms, sust 3245->3717, freq=52Hz, sample=33
    db 115,0,92,14,45,35,1,3,104,0  ; n612 t=162.782s dur=3676ms, sust 3215->3676, freq=104Hz, sample=45
    db 30,1,57,6,45,40,1,4,131,0  ; n613 t=162.897s dur=1593ms, sust 1278->1593, freq=131Hz, sample=45
; t 162.9115 Sustain 0 (Instr 1)
; t 162.9115 Sustain 0 (Instr 2)
    db 231,0,27,5,57,34,1,5,185,0  ; n614 t=163.183s dur=1307ms, sust 348->1307, freq=185Hz, sample=57
; t 163.2501 Sustain 127 (Instr 1)
; t 163.2501 Sustain 127 (Instr 2)
    db 236,0,52,4,57,34,1,6,208,0  ; n615 t=163.414s dur=1076ms, sust 334->1076, freq=208Hz, sample=57
    db 9,1,72,3,57,34,1,7,220,0  ; n616 t=163.650s dur=840ms, sust 369->840, freq=220Hz, sample=57
    db 225,0,62,2,57,33,1,8,208,0  ; n617 t=163.916s dur=574ms, sust 260->574, freq=208Hz, sample=57
    db 137,1,209,1,57,33,1,9,185,0  ; n618 t=164.141s dur=465ms, freq=185Hz, sample=57
; t 164.4906 Sustain 0 (Instr 1)
; t 164.4906 Sustain 0 (Instr 2)
    db 126,1,193,3,45,40,1,10,156,0  ; n619 t=164.534s dur=961ms, sust 631->961, freq=156Hz, sample=45
; t 164.8464 Sustain 127 (Instr 1)
; t 164.8464 Sustain 127 (Instr 2)
    db 15,1,68,2,57,33,1,11,185,0  ; n620 t=164.915s dur=580ms, sust 326->580, freq=185Hz, sample=57
    db 31,1,103,1,57,33,1,12,220,0  ; n621 t=165.186s dur=359ms, freq=220Hz, sample=57
    db 88,1,217,3,45,40,1,13,139,0  ; n622 t=165.473s dur=985ms, sust 506->985, freq=139Hz, sample=45
; t 165.4955 Sustain 0 (Instr 1)
; t 165.4955 Sustain 0 (Instr 2)
; t 165.8114 Sustain 127 (Instr 1)
; t 165.8114 Sustain 127 (Instr 2)
    db 252,0,129,2,57,33,1,14,185,0  ; n623 t=165.817s dur=641ms, sust 420->641, freq=185Hz, sample=57
    db 196,0,171,1,57,33,1,15,220,0  ; n624 t=166.069s dur=427ms, freq=220Hz, sample=57
    db 52,0,227,15,33,35,1,16,52,0  ; n625 t=166.265s dur=4067ms, sust 3733->4067, freq=52Hz, sample=33
    db 127,0,175,15,45,34,1,17,104,0  ; n626 t=166.317s dur=4015ms, sust 3648->4015, freq=104Hz, sample=45
    db 126,1,5,7,45,36,1,18,131,0  ; n627 t=166.444s dur=1797ms, sust 1547->1797, freq=131Hz, sample=45
; t 166.4584 Sustain 0 (Instr 1)
; t 166.4584 Sustain 0 (Instr 2)
    db 242,0,65,1,57,34,1,19,185,0  ; n628 t=166.826s dur=321ms, freq=185Hz, sample=57
    db 35,1,96,1,57,37,1,20,208,0  ; n629 t=167.068s dur=352ms, freq=208Hz, sample=57
    db 19,1,127,1,57,39,1,21,220,0  ; n630 t=167.359s dur=383ms, freq=220Hz, sample=57
    db 253,0,96,2,57,35,1,22,208,0  ; n631 t=167.634s dur=608ms, sust 276->608, freq=208Hz, sample=57
; t 167.7544 Soft 127 (Instr 1)
; t 167.7544 Soft 127 (Instr 2)
; t 167.8698 Sustain 127 (Instr 1)
; t 167.8698 Sustain 127 (Instr 2)
    db 199,1,23,2,57,23,1,23,185,0  ; n632 t=167.887s dur=535ms, vel 33->23, freq=185Hz, sample=57
; t 168.2417 Sustain 0 (Instr 1)
; t 168.2417 Sustain 0 (Instr 2)
    db 171,1,28,4,45,33,1,24,147,0  ; n633 t=168.342s dur=1052ms, vel 48->33, sust 721->1052, freq=147Hz, sample=45
; t 168.7160 Sustain 127 (Instr 1)
; t 168.7160 Sustain 127 (Instr 2)
    db 250,0,114,2,57,23,1,25,185,0  ; n634 t=168.769s dur=626ms, vel 34->23, sust 360->626, freq=185Hz, sample=57
    db 41,1,120,1,57,23,1,26,220,0  ; n635 t=169.019s dur=376ms, vel 33->23, sust 370->376, freq=220Hz, sample=57
    db 124,1,248,3,45,25,1,27,139,0  ; n636 t=169.316s dur=1016ms, vel 37->25, sust 764->1016, freq=139Hz, sample=45
; t 169.3950 Sustain 0 (Instr 1)
; t 169.3950 Sustain 0 (Instr 2)
    db 61,1,123,2,57,23,1,28,185,0  ; n637 t=169.697s dur=635ms, vel 33->23, sust 460->635, freq=185Hz, sample=57
; t 169.7291 Sustain 127 (Instr 1)
; t 169.7291 Sustain 127 (Instr 2)
    db 210,0,247,1,57,23,1,29,220,0  ; n638 t=170.014s dur=503ms, vel 33->23, freq=220Hz, sample=57
    db 38,0,59,8,33,23,1,30,52,0  ; n639 t=170.224s dur=2107ms, vel 33->23, sust 1784->2107, freq=52Hz, sample=33
    db 127,0,21,8,45,23,1,31,104,0  ; n640 t=170.262s dur=2069ms, vel 33->23, sust 1732->2069, freq=104Hz, sample=45
; t 170.3327 Sustain 0 (Instr 1)
; t 170.3327 Sustain 0 (Instr 2)
    db 99,1,150,7,45,25,1,0,131,0  ; n641 t=170.389s dur=1942ms, vel 36->25, sust 1689->1942, freq=131Hz, sample=45
    db 63,1,136,1,57,24,1,1,185,0  ; n642 t=170.743s dur=392ms, vel 35->24, freq=185Hz, sample=57
    db 45,1,104,1,57,23,1,2,208,0  ; n643 t=171.062s dur=360ms, vel 33->23, freq=208Hz, sample=57
    db 86,1,112,1,57,24,1,3,220,0  ; n644 t=171.363s dur=368ms, vel 35->24, freq=220Hz, sample=57
    db 44,1,114,2,57,23,1,4,208,0  ; n645 t=171.705s dur=626ms, vel 33->23, sust 321->626, freq=208Hz, sample=57
; t 171.8017 Sustain 127 (Instr 1)
; t 171.8017 Sustain 127 (Instr 2)
    db 231,0,173,1,57,23,1,5,185,0  ; n646 t=172.004s dur=429ms, vel 33->23, freq=185Hz, sample=57
    db 19,0,210,8,33,24,1,6,55,0  ; n647 t=172.235s dur=2258ms, vel 35->24, sust 1557->2258, freq=55Hz, sample=33
    db 138,0,190,8,45,24,1,7,110,0  ; n648 t=172.254s dur=2238ms, vel 35->24, sust 1431->2238, freq=110Hz, sample=45
; t 172.3309 Sustain 0 (Instr 1)
; t 172.3309 Sustain 0 (Instr 2)
    db 125,1,52,8,45,25,1,8,139,0  ; n649 t=172.392s dur=2100ms, vel 37->25, sust 492->2100, freq=139Hz, sample=45
    db 77,1,183,6,57,23,1,9,165,0  ; n650 t=172.774s dur=1719ms, vel 33->23, sust 405->1719, freq=165Hz, sample=57
; t 172.8049 Sustain 127 (Instr 1)
; t 172.8049 Sustain 127 (Instr 2)
    db 70,1,106,5,57,23,1,10,21,1  ; n651 t=173.107s dur=1386ms, vel 33->23, sust 721->1386, freq=277Hz, sample=57
    db 136,1,36,4,45,23,1,11,139,0  ; n652 t=173.433s dur=1060ms, vel 33->23, sust 414->1060, freq=139Hz, sample=45
    db 51,1,156,2,57,23,1,12,165,0  ; n653 t=173.825s dur=668ms, vel 33->23, sust 321->668, freq=165Hz, sample=57
    db 5,1,213,1,57,23,1,13,21,1  ; n654 t=174.132s dur=469ms, vel 33->23, freq=277Hz, sample=57
    db 43,0,165,9,33,23,1,14,46,0  ; n655 t=174.393s dur=2469ms, vel 34->23, sust 1570->2469, freq=46Hz, sample=33
    db 138,0,122,9,45,24,1,15,92,0  ; n656 t=174.436s dur=2426ms, vel 35->24, sust 1607->2426, freq=92Hz, sample=45
; t 174.4932 Sustain 0 (Instr 1)
; t 174.4932 Sustain 0 (Instr 2)
    db 131,1,240,8,45,25,1,16,156,0  ; n657 t=174.574s dur=2288ms, vel 37->25, sust 464->2288, freq=156Hz, sample=45
; t 174.8702 Sustain 127 (Instr 1)
; t 174.8702 Sustain 127 (Instr 2)
    db 128,1,110,7,57,23,1,17,220,0  ; n658 t=174.961s dur=1902ms, vel 33->23, sust 500->1902, freq=220Hz, sample=57
    db 118,1,238,5,57,23,1,18,21,1  ; n659 t=175.344s dur=1518ms, vel 33->23, sust 553->1518, freq=277Hz, sample=57
    db 138,1,120,4,45,23,1,19,156,0  ; n660 t=175.718s dur=1144ms, vel 33->23, sust 517->1144, freq=156Hz, sample=45
    db 123,1,238,2,57,23,1,20,220,0  ; n661 t=176.112s dur=750ms, vel 33->23, sust 533->750, freq=220Hz, sample=57
    db 67,1,221,1,57,23,1,21,21,1  ; n662 t=176.492s dur=477ms, vel 33->23, freq=277Hz, sample=57
    db 62,0,73,11,33,23,1,22,52,0  ; n663 t=176.815s dur=2889ms, vel 34->23, sust 2424->2889, freq=52Hz, sample=33
; t 176.8630 Sustain 0 (Instr 1)
; t 176.8630 Sustain 0 (Instr 2)
    db 64,0,10,11,45,24,1,23,104,0  ; n664 t=176.877s dur=2826ms, vel 35->24, sust 2403->2826, freq=104Hz, sample=45
    db 123,1,19,5,45,25,1,24,156,0  ; n665 t=176.941s dur=1299ms, vel 36->25, sust 1031->1299, freq=156Hz, sample=45
; t 177.1194 Sustain 127 (Instr 1)
; t 177.1194 Sustain 127 (Instr 2)
    db 134,1,152,3,57,23,1,25,208,0  ; n666 t=177.320s dur=920ms, vel 33->23, sust 443->920, freq=208Hz, sample=57
; t 177.4403 Sustain 0 (Instr 1)
; t 177.4403 Sustain 0 (Instr 2)
    db 210,1,18,2,57,23,1,26,6,1  ; n667 t=177.709s dur=530ms, vel 33->23, sust 281->530, freq=262Hz, sample=57
; t 177.7332 Sustain 127 (Instr 1)
; t 177.7332 Sustain 127 (Instr 2)
    db 186,1,248,5,45,25,1,27,156,0  ; n668 t=178.176s dur=1528ms, vel 36->25, sust 1264->1528, freq=156Hz, sample=45
; t 178.2404 Sustain 0 (Instr 1)
; t 178.2404 Sustain 0 (Instr 2)
    db 252,1,62,4,57,23,1,28,185,0  ; n669 t=178.617s dur=1086ms, vel 33->23, sust 675->1086, freq=185Hz, sample=57
; t 179.0912 Sustain 127 (Instr 1)
; t 179.0912 Sustain 127 (Instr 2)
    db 234,1,66,2,57,23,1,29,6,1  ; n670 t=179.126s dur=578ms, vel 33->23, sust 276->578, freq=262Hz, sample=57
    db 5,0,102,12,33,23,1,30,69,0  ; n671 t=179.616s dur=3174ms, vel 34->23, sust 1149->3174, freq=69Hz, sample=33
    db 6,0,102,12,45,23,1,31,139,0  ; n672 t=179.621s dur=3174ms, vel 34->23, sust 2036->3174, freq=139Hz, sample=45
    db 18,0,141,16,45,24,1,0,104,0  ; n673 t=179.627s dur=4237ms, vel 35->24, sust 1582->4237, freq=104Hz, sample=45
    db 248,1,219,20,57,24,1,1,165,0  ; n674 t=179.646s dur=5339ms, vel 35->24, sust 523->5339, freq=165Hz, sample=57
; t 179.7040 Sustain 0 (Instr 1)
; t 179.7040 Sustain 0 (Instr 2)
; t 180.1067 Sustain 127 (Instr 1)
; t 180.1067 Sustain 127 (Instr 2)
    db 149,1,141,16,57,23,1,2,208,0  ; n675 t=180.150s dur=4237ms, vel 33->23, sust 469->4237, freq=208Hz, sample=57
    db 124,1,102,12,57,23,1,3,21,1  ; n676 t=180.554s dur=3174ms, vel 33->23, sust 459->3174, freq=277Hz, sample=57
    db 179,1,53,16,57,23,1,4,208,0  ; n677 t=180.935s dur=4149ms, vel 33->23, sust 939->4149, freq=208Hz, sample=57
    db 125,1,102,12,57,23,1,5,21,1  ; n678 t=181.369s dur=3174ms, vel 33->23, sust 509->3174, freq=277Hz, sample=57
    db 112,1,5,13,69,23,1,6,74,1  ; n679 t=181.750s dur=3333ms, vel 33->23, sust 511->3333, freq=330Hz, sample=69
    db 183,1,149,11,57,23,1,7,208,0  ; n680 t=182.119s dur=2965ms, vel 33->23, sust 737->2965, freq=208Hz, sample=57
    db 148,1,222,9,57,23,1,8,21,1  ; n681 t=182.558s dur=2526ms, vel 33->23, sust 666->2526, freq=277Hz, sample=57
    db 196,1,74,8,69,23,1,9,74,1  ; n682 t=182.962s dur=2122ms, vel 33->23, sust 576->2122, freq=330Hz, sample=69
    db 31,0,134,6,57,26,1,10,208,0  ; n683 t=183.414s dur=1670ms, vel 38->26, sust 847->1670, freq=208Hz, sample=57
    db 201,1,103,6,69,33,2,11,159,1  ; n684 t=183.445s dur=1639ms, vel 48->33, sust 1070->1639, freq=415Hz, sample=69
    db 2,2,157,4,57,23,1,12,21,1  ; n685 t=183.902s dur=1181ms, vel 33->23, sust 648->1181, freq=277Hz, sample=57
    db 187,1,155,2,69,23,1,13,74,1  ; n686 t=184.417s dur=667ms, vel 33->23, sust 187->667, freq=330Hz, sample=69
    db 242,0,223,0,69,30,2,14,159,1  ; n687 t=184.860s dur=223ms, vel 44->30, sust 147->223, freq=415Hz, sample=69
; t 185.0840 Sustain 0 (Instr 1)
; t 185.0840 Sustain 0 (Instr 2)
    db 5,0,35,13,33,27,1,15,65,0  ; n688 t=185.102s dur=3363ms, vel 39->27, sust 4243->3363, freq=65Hz, sample=33
    db 0,0,53,14,57,27,1,16,208,0  ; n689 t=185.108s dur=3637ms, vel 39->27, sust 897->3637, freq=208Hz, sample=57
    db 13,0,141,16,45,27,1,17,104,0  ; n690 t=185.108s dur=4237ms, vel 39->27, sust 4178->4237, freq=104Hz, sample=45
    db 4,0,35,13,45,27,1,18,131,0  ; n691 t=185.121s dur=3363ms, vel 39->27, sust 4160->3363, freq=131Hz, sample=45
    db 178,1,36,14,69,32,2,19,159,1  ; n692 t=185.125s dur=3620ms, vel 47->32, sust 3140->3620, freq=415Hz, sample=69
; t 185.5262 Sustain 127 (Instr 1)
; t 185.5262 Sustain 127 (Instr 2)
    db 131,1,12,11,57,23,1,20,55,1  ; n693 t=185.559s dur=2828ms, vel 33->23, sust 830->2828, freq=311Hz, sample=57
    db 139,1,239,10,69,23,1,21,114,1  ; n694 t=185.946s dur=2799ms, vel 33->23, sust 823->2799, freq=370Hz, sample=69
    db 100,1,100,9,57,25,1,22,208,0  ; n695 t=186.341s dur=2404ms, vel 36->25, sust 819->2404, freq=208Hz, sample=57
    db 151,1,0,8,57,23,1,23,55,1  ; n696 t=186.697s dur=2048ms, vel 33->23, sust 880->2048, freq=311Hz, sample=57
    db 101,1,105,6,69,23,1,24,114,1  ; n697 t=187.104s dur=1641ms, vel 33->23, sust 855->1641, freq=370Hz, sample=69
    db 145,1,4,5,57,24,1,25,208,0  ; n698 t=187.461s dur=1284ms, vel 35->24, sust 905->1284, freq=208Hz, sample=57
    db 142,1,116,3,57,23,1,26,55,1  ; n699 t=187.862s dur=884ms, vel 33->23, freq=311Hz, sample=57
    db 187,1,4,2,69,23,1,27,114,1  ; n700 t=188.260s dur=516ms, vel 33->23, freq=370Hz, sample=69
    db 1,0,107,5,69,33,2,28,159,1  ; n701 t=188.703s dur=1387ms, vel 48->33, sust 866->1387, freq=415Hz, sample=69
    db 223,1,106,5,57,25,1,29,208,0  ; n702 t=188.704s dur=1386ms, vel 36->25, sust 709->1386, freq=208Hz, sample=57
; t 188.7454 Sustain 0 (Instr 1)
; t 188.7454 Sustain 0 (Instr 2)
; t 189.0423 Sustain 127 (Instr 1)
; t 189.0423 Sustain 127 (Instr 2)
    db 122,1,139,3,57,23,1,30,55,1  ; n703 t=189.183s dur=907ms, vel 33->23, sust 426->907, freq=311Hz, sample=57
    db 24,1,18,2,69,23,1,31,114,1  ; n704 t=189.561s dur=530ms, vel 33->23, sust 371->530, freq=370Hz, sample=69
    db 180,0,250,0,69,30,2,0,159,1  ; n705 t=189.840s dur=250ms, vel 44->30, sust 169->250, freq=415Hz, sample=69
    db 36,0,227,9,33,27,1,1,69,0  ; n706 t=190.020s dur=2531ms, vel 39->27, sust 960->2531, freq=69Hz, sample=33
    db 40,0,191,9,45,27,1,2,139,0  ; n707 t=190.057s dur=2495ms, vel 39->27, sust 655->2495, freq=139Hz, sample=45
; t 190.0911 Sustain 0 (Instr 1)
; t 190.0911 Sustain 0 (Instr 2)
    db 10,0,151,9,57,26,1,3,208,0  ; n708 t=190.096s dur=2455ms, vel 38->26, sust 896->2455, freq=208Hz, sample=57
    db 176,1,141,9,69,33,2,4,159,1  ; n709 t=190.106s dur=2445ms, vel 48->33, sust 1050->2445, freq=415Hz, sample=69
; t 190.4385 Sustain 127 (Instr 1)
; t 190.4385 Sustain 127 (Instr 2)
    db 126,1,221,7,57,23,1,5,21,1  ; n710 t=190.538s dur=2013ms, vel 33->23, sust 855->2013, freq=277Hz, sample=57
    db 115,1,95,6,69,23,1,6,74,1  ; n711 t=190.920s dur=1631ms, vel 33->23, sust 467->1631, freq=330Hz, sample=69
    db 167,1,236,4,57,24,1,7,208,0  ; n712 t=191.292s dur=1260ms, vel 35->24, sust 903->1260, freq=208Hz, sample=57
    db 157,1,158,3,57,23,1,8,21,1  ; n713 t=191.714s dur=926ms, vel 33->23, freq=277Hz, sample=57
    db 61,1,233,1,69,23,1,9,74,1  ; n714 t=192.127s dur=489ms, vel 33->23, freq=330Hz, sample=69
    db 12,0,110,10,33,28,1,10,46,0  ; n715 t=192.444s dur=2670ms, vel 40->28, sust 1058->2670, freq=46Hz, sample=33
    db 96,0,99,10,45,28,1,11,92,0  ; n716 t=192.456s dur=2659ms, vel 40->28, sust 1308->2659, freq=92Hz, sample=45
    db 17,0,3,10,57,26,1,12,220,0  ; n717 t=192.552s dur=2563ms, vel 38->26, sust 1009->2563, freq=220Hz, sample=57
; t 192.5517 Sustain 0 (Instr 1)
; t 192.5517 Sustain 0 (Instr 2)
    db 215,1,242,9,69,36,2,13,184,1  ; n718 t=192.569s dur=2546ms, vel 52->36, sust 1350->2546, freq=440Hz, sample=69
; t 192.9840 Sustain 127 (Instr 1)
; t 192.9840 Sustain 127 (Instr 2)
    db 161,1,27,8,57,23,1,14,21,1  ; n719 t=193.040s dur=2075ms, vel 33->23, sust 912->2075, freq=277Hz, sample=57
    db 213,1,122,6,69,23,1,15,114,1  ; n720 t=193.457s dur=1658ms, vel 33->23, sust 999->1658, freq=370Hz, sample=69
    db 165,1,165,4,57,24,1,16,220,0  ; n721 t=193.926s dur=1189ms, vel 35->24, sust 882->1189, freq=220Hz, sample=57
    db 110,1,255,2,57,23,1,17,21,1  ; n722 t=194.347s dur=767ms, vel 33->23, sust 711->767, freq=277Hz, sample=57
    db 49,1,42,2,69,23,1,18,114,1  ; n723 t=194.713s dur=554ms, vel 33->23, freq=370Hz, sample=69
    db 35,0,206,10,33,25,1,19,62,0  ; n724 t=195.018s dur=2766ms, vel 36->25, sust 1251->2766, freq=62Hz, sample=33
    db 120,0,171,10,45,25,1,20,123,0  ; n725 t=195.054s dur=2731ms, vel 36->25, sust 1138->2731, freq=123Hz, sample=45
; t 195.1151 Sustain 0 (Instr 1)
; t 195.1151 Sustain 0 (Instr 2)
    db 2,0,50,10,69,30,2,21,159,1  ; n726 t=195.174s dur=2610ms, vel 44->30, sust 1219->2610, freq=415Hz, sample=69
    db 206,1,48,10,57,25,1,22,208,0  ; n727 t=195.176s dur=2608ms, vel 36->25, sust 959->2608, freq=208Hz, sample=57
; t 195.6021 Sustain 127 (Instr 1)
; t 195.6021 Sustain 127 (Instr 2)
    db 151,1,98,8,57,23,1,23,247,0  ; n728 t=195.639s dur=2146ms, vel 33->23, sust 921->2146, freq=247Hz, sample=57
    db 193,1,203,6,69,23,1,24,74,1  ; n729 t=196.046s dur=1739ms, vel 33->23, sust 961->1739, freq=330Hz, sample=69
    db 126,1,9,5,57,24,1,25,208,0  ; n730 t=196.495s dur=1289ms, vel 35->24, sust 619->1289, freq=208Hz, sample=57
    db 151,1,140,3,57,23,1,26,247,0  ; n731 t=196.877s dur=908ms, vel 33->23, sust 557->908, freq=247Hz, sample=57
    db 43,1,244,1,69,23,1,27,74,1  ; n732 t=197.284s dur=500ms, vel 33->23, sust 181->500, freq=330Hz, sample=69
    db 100,0,16,13,33,25,1,28,62,0  ; n733 t=197.583s dur=3344ms, vel 36->25, sust 731->3344, freq=62Hz, sample=33
    db 106,0,172,12,45,25,1,29,123,0  ; n734 t=197.683s dur=3244ms, vel 36->25, sust 674->3244, freq=123Hz, sample=45
; t 197.7849 Sustain 0 (Instr 1)
; t 197.7849 Sustain 0 (Instr 2)
    db 2,0,65,12,69,25,1,30,114,1  ; n735 t=197.789s dur=3137ms, vel 37->25, sust 831->3137, freq=370Hz, sample=69
    db 205,1,63,12,57,25,1,31,220,0  ; n736 t=197.791s dur=3135ms, vel 37->25, sust 382->3135, freq=220Hz, sample=57
; t 198.0128 Sustain 127 (Instr 1)
; t 198.0128 Sustain 127 (Instr 2)
    db 213,1,114,10,57,23,1,0,247,0  ; n737 t=198.252s dur=2674ms, vel 33->23, sust 357->2674, freq=247Hz, sample=57
    db 203,1,157,8,57,23,1,1,55,1  ; n738 t=198.721s dur=2205ms, vel 33->23, sust 359->2205, freq=311Hz, sample=57
    db 29,0,210,6,57,25,1,2,220,0  ; n739 t=199.180s dur=1746ms, vel 36->25, sust 764->1746, freq=220Hz, sample=57
    db 58,2,181,6,69,33,2,3,238,1  ; n740 t=199.209s dur=1717ms, vel 48->33, sust 326->1717, freq=494Hz, sample=69
    db 79,2,124,4,57,23,1,4,247,0  ; n741 t=199.779s dur=1148ms, vel 33->23, sust 330->1148, freq=247Hz, sample=57
    db 155,1,45,2,57,23,1,5,55,1  ; n742 t=200.369s dur=557ms, vel 33->23, sust 233->557, freq=311Hz, sample=57
    db 55,0,32,20,45,25,1,6,82,0  ; n743 t=200.781s dur=5152ms, vel 36->25, sust 4520->5152, freq=82Hz, sample=45
    db 83,0,233,19,57,24,1,7,165,0  ; n744 t=200.836s dur=5097ms, vel 35->24, sust 4445->5097, freq=165Hz, sample=57
    db 39,0,112,14,57,23,1,8,208,0  ; n745 t=200.918s dur=3696ms, vel 34->23, sust 556->3696, freq=208Hz, sample=57
; t 200.9270 Sustain 0 (Instr 1)
; t 200.9270 Sustain 0 (Instr 2)
    db 189,1,73,14,69,25,1,9,74,1  ; n746 t=200.957s dur=3657ms, vel 37->25, sust 542->3657, freq=330Hz, sample=69
; t 201.2052 Sustain 127 (Instr 1)
; t 201.2052 Sustain 127 (Instr 2)
    db 92,1,140,12,57,23,1,10,247,0  ; n747 t=201.402s dur=3212ms, vel 33->23, sust 432->3212, freq=247Hz, sample=57
    db 125,1,48,11,69,23,1,11,74,1  ; n748 t=201.750s dur=2864ms, vel 33->23, sust 471->2864, freq=330Hz, sample=69
    db 119,1,179,9,57,23,1,12,247,0  ; n749 t=202.131s dur=2483ms, vel 33->23, sust 723->2483, freq=247Hz, sample=57
    db 134,1,60,8,69,23,1,13,74,1  ; n750 t=202.506s dur=2108ms, vel 33->23, sust 540->2108, freq=330Hz, sample=69
    db 170,1,182,6,69,26,2,14,159,1  ; n751 t=202.896s dur=1718ms, vel 38->26, sust 618->1718, freq=415Hz, sample=69
    db 150,1,12,5,57,23,1,15,247,0  ; n752 t=203.323s dur=1292ms, vel 33->23, sust 540->1292, freq=247Hz, sample=57
    db 131,1,117,3,69,23,1,16,74,1  ; n753 t=203.729s dur=885ms, vel 33->23, sust 868->885, freq=330Hz, sample=69
    db 197,1,13,2,69,26,2,17,159,1  ; n754 t=204.115s dur=525ms, vel 38->26, freq=415Hz, sample=69
    db 12,0,84,5,57,26,1,18,247,0  ; n755 t=204.569s dur=1364ms, vel 38->26, sust 853->1364, freq=247Hz, sample=57
    db 195,1,73,5,69,35,2,19,238,1  ; n756 t=204.580s dur=1353ms, vel 51->35, sust 896->1353, freq=494Hz, sample=69
; t 204.6147 Sustain 0 (Instr 1)
; t 204.6147 Sustain 0 (Instr 2)
; t 204.9744 Sustain 127 (Instr 1)
; t 204.9744 Sustain 127 (Instr 2)
    db 130,1,134,3,69,23,1,20,74,1  ; n757 t=205.031s dur=902ms, vel 33->23, sust 452->902, freq=330Hz, sample=69
; t 205.1097 Soft 127 (Instr 1)
; t 205.1097 Soft 127 (Instr 2)
    db 5,1,4,2,69,28,2,21,159,1  ; n758 t=205.417s dur=516ms, vel 40->28, sust 295->516, freq=415Hz, sample=69
    db 142,0,255,0,69,30,2,22,238,1  ; n759 t=205.678s dur=255ms, vel 43->30, sust 168->255, freq=494Hz, sample=69
    db 30,0,12,11,33,28,1,23,78,0  ; n760 t=205.820s dur=2828ms, vel 40->28, sust 4120->2828, freq=78Hz, sample=33
    db 56,0,12,11,45,28,1,24,156,0  ; n761 t=205.850s dur=2828ms, vel 40->28, sust 4032->2828, freq=156Hz, sample=45
    db 9,0,71,13,69,37,2,25,238,1  ; n762 t=205.905s dur=3399ms, vel 53->37, sust 3001->3399, freq=494Hz, sample=69
    db 101,1,62,13,57,27,1,26,247,0  ; n763 t=205.914s dur=3390ms, vel 39->27, sust 891->3390, freq=247Hz, sample=57
; t 205.9334 Sustain 0 (Instr 1)
; t 205.9334 Sustain 0 (Instr 2)
    db 122,1,218,11,69,23,1,27,114,1  ; n764 t=206.271s dur=3034ms, vel 34->23, sust 591->3034, freq=370Hz, sample=69
; t 206.3340 Sustain 127 (Instr 1)
; t 206.3340 Sustain 127 (Instr 2)
    db 101,1,96,10,69,26,2,28,184,1  ; n765 t=206.649s dur=2656ms, vel 38->26, sust 584->2656, freq=440Hz, sample=69
    db 132,1,251,8,57,23,1,29,247,0  ; n766 t=207.005s dur=2299ms, vel 33->23, sust 973->2299, freq=247Hz, sample=57
    db 85,1,119,7,69,23,1,30,114,1  ; n767 t=207.393s dur=1911ms, vel 33->23, sust 772->1911, freq=370Hz, sample=69
    db 141,1,34,6,69,26,2,31,184,1  ; n768 t=207.734s dur=1570ms, vel 38->26, sust 819->1570, freq=440Hz, sample=69
    db 112,1,149,4,57,23,1,0,247,0  ; n769 t=208.131s dur=1173ms, vel 33->23, sust 859->1173, freq=247Hz, sample=57
    db 85,1,37,3,69,23,1,1,114,1  ; n770 t=208.500s dur=805ms, vel 33->23, sust 579->805, freq=370Hz, sample=69
    db 154,1,228,1,69,26,2,2,184,1  ; n771 t=208.841s dur=484ms, vel 38->26, freq=440Hz, sample=69
    db 14,0,236,4,69,34,2,3,238,1  ; n772 t=209.251s dur=1260ms, vel 49->34, sust 787->1260, freq=494Hz, sample=69
    db 168,1,222,4,57,25,1,4,247,0  ; n773 t=209.265s dur=1246ms, vel 36->25, sust 681->1246, freq=247Hz, sample=57
; t 209.3047 Sustain 0 (Instr 1)
; t 209.3047 Sustain 0 (Instr 2)
; t 209.6149 Sustain 127 (Instr 1)
; t 209.6149 Sustain 127 (Instr 2)
    db 104,1,54,3,69,23,1,5,114,1  ; n774 t=209.689s dur=822ms, vel 33->23, sust 381->822, freq=370Hz, sample=69
    db 220,0,206,1,69,26,2,6,184,1  ; n775 t=210.049s dur=462ms, vel 38->26, sust 267->462, freq=440Hz, sample=69
    db 120,0,242,0,69,28,2,7,238,1  ; n776 t=210.269s dur=242ms, vel 41->28, sust 110->242, freq=494Hz, sample=69
    db 38,0,100,9,45,25,1,8,82,0  ; n777 t=210.389s dur=2404ms, vel 37->25, sust 1452->2404, freq=82Hz, sample=45
    db 75,0,63,9,57,25,1,9,165,0  ; n778 t=210.427s dur=2367ms, vel 36->25, sust 1658->2367, freq=165Hz, sample=57
    db 1,0,244,8,69,39,2,10,238,1  ; n779 t=210.502s dur=2292ms, vel 57->39, sust 1877->2292, freq=494Hz, sample=69
    db 131,1,243,8,57,24,1,11,247,0  ; n780 t=210.503s dur=2291ms, vel 35->24, sust 930->2291, freq=247Hz, sample=57
; t 210.5113 Sustain 0 (Instr 1)
; t 210.5113 Sustain 0 (Instr 2)
    db 120,1,111,7,69,23,1,12,74,1  ; n781 t=210.890s dur=1903ms, vel 33->23, sust 543->1903, freq=330Hz, sample=69
; t 210.9160 Sustain 127 (Instr 1)
; t 210.9160 Sustain 127 (Instr 2)
    db 131,1,247,5,69,26,2,13,159,1  ; n782 t=211.266s dur=1527ms, vel 38->26, sust 823->1527, freq=415Hz, sample=69
    db 97,1,116,4,57,23,1,14,247,0  ; n783 t=211.653s dur=1140ms, vel 33->23, sust 482->1140, freq=247Hz, sample=57
    db 109,1,19,3,69,23,1,15,74,1  ; n784 t=212.006s dur=787ms, vel 33->23, sust 682->787, freq=330Hz, sample=69
; t 212.2326 Soft 0 (Instr 1)
; t 212.2326 Soft 0 (Instr 2)
    db 9,1,187,1,69,40,2,16,159,1  ; n785 t=212.371s dur=443ms, freq=415Hz, sample=69
    db 12,0,15,5,33,39,1,17,78,0  ; n786 t=212.636s dur=1295ms, sust 1207->1295, freq=78Hz, sample=33
    db 115,0,3,5,45,39,1,18,156,0  ; n787 t=212.648s dur=1283ms, sust 828->1283, freq=156Hz, sample=45
    db 11,0,144,4,57,40,1,19,6,1  ; n788 t=212.763s dur=1168ms, sust 822->1168, freq=262Hz, sample=57
    db 148,1,133,4,69,58,2,20,11,2  ; n789 t=212.774s dur=1157ms, sust 784->1157, freq=523Hz, sample=69
; t 212.7938 Sustain 0 (Instr 1)
; t 212.7938 Sustain 0 (Instr 2)
; t 213.1222 Sustain 127 (Instr 1)
; t 213.1222 Sustain 127 (Instr 2)
    db 96,1,241,2,69,40,1,21,114,1  ; n790 t=213.178s dur=753ms, sust 443->753, freq=370Hz, sample=69
    db 220,0,184,1,69,41,2,22,159,1  ; n791 t=213.530s dur=440ms, freq=415Hz, sample=69
    db 28,0,5,6,33,46,1,23,69,0  ; n792 t=213.750s dur=1541ms, sust 898->1541, freq=69Hz, sample=33
    db 127,0,233,5,45,46,1,24,139,0  ; n793 t=213.778s dur=1513ms, sust 863->1513, freq=139Hz, sample=45
    db 7,0,107,5,69,60,2,25,42,2  ; n794 t=213.905s dur=1387ms, sust 905->1387, freq=554Hz, sample=69
    db 185,1,99,5,57,44,1,26,21,1  ; n795 t=213.912s dur=1379ms, sust 753->1379, freq=277Hz, sample=57
; t 213.9313 Sustain 0 (Instr 1)
; t 213.9313 Sustain 0 (Instr 2)
    db 148,1,170,3,69,38,1,27,74,1  ; n796 t=214.353s dur=938ms, sust 471->938, freq=330Hz, sample=69
; t 214.3916 Sustain 127 (Instr 1)
; t 214.3916 Sustain 127 (Instr 2)
; t 214.7361 Soft 127 (Instr 1)
; t 214.7361 Soft 127 (Instr 2)
    db 190,1,22,2,69,26,2,28,159,1  ; n797 t=214.757s dur=534ms, vel 38->26, sust 162->534, freq=415Hz, sample=69
    db 80,0,173,10,33,25,1,29,65,0  ; n798 t=215.204s dur=2733ms, vel 36->25, sust 1770->2733, freq=65Hz, sample=33
    db 0,0,92,10,45,25,1,30,104,0  ; n799 t=215.284s dur=2652ms, vel 36->25, sust 723->2652, freq=104Hz, sample=45
    db 88,0,92,10,45,25,1,31,131,0  ; n800 t=215.284s dur=2652ms, vel 36->25, sust 1663->2652, freq=131Hz, sample=45
; t 215.2917 Sustain 0 (Instr 1)
; t 215.2917 Sustain 0 (Instr 2)
    db 2,0,4,10,69,32,2,0,110,2  ; n801 t=215.372s dur=2564ms, vel 47->32, sust 1273->2564, freq=622Hz, sample=69
    db 172,1,2,10,57,24,1,1,55,1  ; n802 t=215.374s dur=2562ms, vel 35->24, sust 900->2562, freq=311Hz, sample=57
; t 215.6650 Sustain 127 (Instr 1)
; t 215.6650 Sustain 127 (Instr 2)
    db 110,1,86,8,69,23,1,2,114,1  ; n803 t=215.802s dur=2134ms, vel 33->23, sust 844->2134, freq=370Hz, sample=69
    db 152,1,232,6,69,26,2,3,159,1  ; n804 t=216.168s dur=1768ms, vel 38->26, sust 530->1768, freq=415Hz, sample=69
    db 143,1,81,5,57,23,1,4,55,1  ; n805 t=216.576s dur=1361ms, vel 33->23, sust 697->1361, freq=311Hz, sample=57
; t 216.8513 Soft 127 (Instr 1)
; t 216.8513 Soft 127 (Instr 2)
    db 119,1,194,3,69,23,1,5,114,1  ; n806 t=216.975s dur=962ms, vel 33->23, sust 567->962, freq=370Hz, sample=69
    db 106,1,74,2,69,27,2,6,159,1  ; n807 t=217.350s dur=586ms, vel 39->27, sust 217->586, freq=415Hz, sample=69
    db 68,0,80,10,33,27,1,7,69,0  ; n808 t=217.712s dur=2640ms, vel 39->27, sust 1149->2640, freq=69Hz, sample=33
    db 138,0,12,10,45,26,1,8,139,0  ; n809 t=217.779s dur=2572ms, vel 38->26, sust 1400->2572, freq=139Hz, sample=45
    db 23,0,130,9,69,25,1,9,74,1  ; n810 t=217.917s dur=2434ms, vel 36->25, sust 1004->2434, freq=330Hz, sample=69
; t 217.9369 Sustain 0 (Instr 1)
; t 217.9369 Sustain 0 (Instr 2)
    db 148,1,107,9,81,39,2,10,147,2  ; n811 t=217.940s dur=2411ms, vel 56->39, sust 709->2411, freq=659Hz, sample=81
; t 218.1825 Sustain 127 (Instr 1)
; t 218.1825 Sustain 127 (Instr 2)
    db 196,1,215,7,69,26,2,11,159,1  ; n812 t=218.345s dur=2007ms, vel 38->26, sust 902->2007, freq=415Hz, sample=69
    db 111,1,18,6,69,26,2,12,42,2  ; n813 t=218.797s dur=1554ms, vel 38->26, sust 863->1554, freq=554Hz, sample=69
    db 106,1,163,4,69,23,1,13,74,1  ; n814 t=219.164s dur=1187ms, vel 33->23, sust 888->1187, freq=330Hz, sample=69
    db 195,1,223,3,69,26,2,14,159,1  ; n815 t=219.526s dur=991ms, vel 38->26, freq=415Hz, sample=69
    db 230,0,8,2,69,26,2,15,42,2  ; n816 t=219.977s dur=520ms, vel 38->26, freq=554Hz, sample=69
    db 62,0,1,11,33,28,1,16,46,0  ; n817 t=220.207s dur=2817ms, vel 41->28, sust 1040->2817, freq=46Hz, sample=33
    db 151,0,195,10,45,28,1,17,92,0  ; n818 t=220.269s dur=2755ms, vel 40->28, sust 1021->2755, freq=92Hz, sample=45
; t 220.3517 Sustain 0 (Instr 1)
; t 220.3517 Sustain 0 (Instr 2)
    db 7,0,44,10,69,38,2,18,75,2  ; n819 t=220.420s dur=2604ms, vel 55->38, sust 980->2604, freq=587Hz, sample=69
    db 205,1,36,10,57,26,1,19,38,1  ; n820 t=220.428s dur=2596ms, vel 38->26, sust 999->2596, freq=294Hz, sample=57
; t 220.8010 Sustain 127 (Instr 1)
; t 220.8010 Sustain 127 (Instr 2)
    db 203,1,87,8,69,23,1,20,114,1  ; n821 t=220.889s dur=2135ms, vel 33->23, sust 1058->2135, freq=370Hz, sample=69
    db 172,1,140,6,69,26,2,21,184,1  ; n822 t=221.348s dur=1676ms, vel 38->26, sust 536->1676, freq=440Hz, sample=69
    db 146,1,224,4,57,23,1,22,38,1  ; n823 t=221.776s dur=1248ms, vel 33->23, sust 881->1248, freq=294Hz, sample=57
    db 180,1,78,3,69,23,1,23,114,1  ; n824 t=222.178s dur=846ms, vel 33->23, sust 565->846, freq=370Hz, sample=69
    db 56,1,2,2,69,26,2,24,184,1  ; n825 t=222.614s dur=514ms, vel 38->26, freq=440Hz, sample=69
    db 63,0,210,10,33,24,1,25,52,0  ; n826 t=222.926s dur=2770ms, vel 35->24, sust 814->2770, freq=52Hz, sample=33
    db 100,0,147,10,45,24,1,26,104,0  ; n827 t=222.989s dur=2707ms, vel 35->24, sust 938->2707, freq=104Hz, sample=45
; t 223.0245 Sustain 0 (Instr 1)
; t 223.0245 Sustain 0 (Instr 2)
    db 4,0,47,10,57,23,1,27,6,1  ; n828 t=223.089s dur=2607ms, vel 34->23, sust 982->2607, freq=262Hz, sample=57
    db 217,1,43,10,69,36,2,28,11,2  ; n829 t=223.093s dur=2603ms, vel 52->36, sust 1090->2603, freq=523Hz, sample=69
; t 223.4286 Sustain 127 (Instr 1)
; t 223.4286 Sustain 127 (Instr 2)
    db 146,1,82,8,69,23,1,29,114,1  ; n830 t=223.566s dur=2130ms, vel 33->23, sust 929->2130, freq=370Hz, sample=69
    db 138,1,192,6,69,26,2,30,159,1  ; n831 t=223.968s dur=1728ms, vel 38->26, sust 1029->1728, freq=415Hz, sample=69
    db 176,1,54,5,57,23,1,31,6,1  ; n832 t=224.362s dur=1334ms, vel 33->23, sust 895->1334, freq=262Hz, sample=57
    db 134,1,134,3,69,23,1,0,114,1  ; n833 t=224.794s dur=902ms, vel 33->23, sust 530->902, freq=370Hz, sample=69
    db 85,1,0,2,69,26,2,1,159,1  ; n834 t=225.184s dur=512ms, vel 38->26, sust 248->512, freq=415Hz, sample=69
    db 52,0,102,12,33,25,1,2,69,0  ; n835 t=225.525s dur=3174ms, vel 36->25, sust 5394->3174, freq=69Hz, sample=33
    db 111,0,102,12,45,24,1,3,139,0  ; n836 t=225.577s dur=3174ms, vel 35->24, sust 5355->3174, freq=139Hz, sample=45
    db 14,0,102,12,69,30,2,4,42,2  ; n837 t=225.688s dur=3174ms, vel 43->30, sust 2611->3174, freq=554Hz, sample=69
; t 225.6965 Sustain 0 (Instr 1)
; t 225.6965 Sustain 0 (Instr 2)
    db 133,1,72,9,57,23,1,5,21,1  ; n838 t=225.702s dur=2376ms, vel 34->23, sust 892->2376, freq=277Hz, sample=57
; t 225.9655 Sustain 127 (Instr 1)
; t 225.9655 Sustain 127 (Instr 2)
    db 135,1,195,7,69,23,1,6,74,1  ; n839 t=226.091s dur=1987ms, vel 33->23, sust 913->1987, freq=330Hz, sample=69
    db 108,1,60,6,69,26,2,7,159,1  ; n840 t=226.482s dur=1596ms, vel 38->26, sust 484->1596, freq=415Hz, sample=69
; t 226.7595 Soft 0 (Instr 1)
; t 226.7595 Soft 0 (Instr 2)
    db 128,1,208,4,57,38,1,8,21,1  ; n841 t=226.846s dur=1232ms, sust 1003->1232, freq=277Hz, sample=57
    db 140,1,80,3,69,38,1,9,74,1  ; n842 t=227.230s dur=848ms, sust 494->848, freq=330Hz, sample=69
    db 107,1,196,1,69,42,2,10,159,1  ; n843 t=227.626s dur=452ms, sust 441->452, freq=415Hz, sample=69
    db 116,1,146,4,57,37,1,11,21,1  ; n844 t=227.989s dur=1170ms, sust 800->1170, freq=277Hz, sample=57
; t 228.0784 Sustain 0 (Instr 1)
; t 228.0784 Sustain 0 (Instr 2)
; t 228.2669 Sustain 127 (Instr 1)
; t 228.2669 Sustain 127 (Instr 2)
    db 125,1,30,3,69,33,1,12,93,1  ; n845 t=228.361s dur=798ms, sust 763->798, freq=349Hz, sample=69
    db 86,1,160,1,69,43,2,13,159,1  ; n846 t=228.743s dur=416ms, sust 414->416, freq=415Hz, sample=69
    db 4,0,228,4,57,43,1,14,21,1  ; n847 t=229.084s dur=1252ms, sust 721->1252, freq=277Hz, sample=57
    db 162,1,224,4,69,59,2,15,42,2  ; n848 t=229.089s dur=1248ms, sust 752->1248, freq=554Hz, sample=69
; t 229.1594 Sustain 0 (Instr 1)
; t 229.1594 Sustain 0 (Instr 2)
; t 229.3672 Sustain 127 (Instr 1)
; t 229.3672 Sustain 127 (Instr 2)
    db 88,1,62,3,69,41,1,16,93,1  ; n849 t=229.506s dur=830ms, sust 416->830, freq=349Hz, sample=69
    db 133,1,230,1,69,38,2,17,159,1  ; n850 t=229.850s dur=486ms, sust 122->486, freq=415Hz, sample=69
    db 16,0,180,11,69,59,2,18,75,2  ; n851 t=230.239s dur=2996ms, sust 2542->2996, freq=587Hz, sample=69
    db 169,1,87,8,57,46,1,19,21,1  ; n852 t=230.255s dur=2135ms, sust 1083->2135, freq=277Hz, sample=57
; t 230.3367 Sustain 0 (Instr 1)
; t 230.3367 Sustain 0 (Instr 2)
; t 230.6269 Sustain 127 (Instr 1)
; t 230.6269 Sustain 127 (Instr 2)
    db 141,1,174,6,69,41,1,20,114,1  ; n853 t=230.680s dur=1710ms, sust 613->1710, freq=370Hz, sample=69
    db 233,0,33,5,69,38,2,21,184,1  ; n854 t=231.078s dur=1313ms, sust 379->1313, freq=440Hz, sample=69
    db 32,0,55,4,45,42,1,22,92,0  ; n855 t=231.311s dur=1079ms, sust 704->1079, freq=92Hz, sample=45
    db 69,0,23,4,57,45,1,23,185,0  ; n856 t=231.343s dur=1047ms, sust 626->1047, freq=185Hz, sample=57
    db 53,1,210,3,57,44,1,24,21,1  ; n857 t=231.412s dur=978ms, sust 967->978, freq=277Hz, sample=57
    db 124,1,2,3,69,39,1,25,114,1  ; n858 t=231.721s dur=770ms, freq=370Hz, sample=69
    db 230,0,126,5,69,38,2,26,184,1  ; n859 t=232.102s dur=1406ms, sust 636->1406, freq=440Hz, sample=69
    db 0,0,151,4,57,44,1,27,220,0  ; n860 t=232.332s dur=1175ms, sust 508->1175, freq=220Hz, sample=57
    db 82,0,151,4,45,44,1,28,110,0  ; n861 t=232.332s dur=1175ms, sust 598->1175, freq=110Hz, sample=45
; t 232.3468 Soft 127 (Instr 1)
; t 232.3468 Soft 127 (Instr 2)
; t 232.3908 Sustain 0 (Instr 1)
; t 232.3908 Sustain 0 (Instr 2)
    db 123,1,69,4,57,23,1,29,21,1  ; n862 t=232.414s dur=1093ms, vel 33->23, sust 766->1093, freq=277Hz, sample=57
; t 232.5857 Sustain 127 (Instr 1)
; t 232.5857 Sustain 127 (Instr 2)
    db 95,1,28,3,69,23,1,30,114,1  ; n863 t=232.793s dur=796ms, vel 33->23, freq=370Hz, sample=69
    db 26,1,190,1,69,27,2,31,184,1  ; n864 t=233.145s dur=446ms, vel 39->27, freq=440Hz, sample=69
    db 0,0,171,4,57,28,1,0,185,0  ; n865 t=233.426s dur=1195ms, vel 40->28, sust 525->1195, freq=185Hz, sample=57
    db 72,0,171,4,45,28,1,1,92,0  ; n866 t=233.426s dur=1195ms, vel 40->28, sust 594->1195, freq=92Hz, sample=45
    db 28,0,100,4,69,34,2,2,11,2  ; n867 t=233.498s dur=1124ms, vel 49->34, sust 837->1124, freq=523Hz, sample=69
; t 233.5077 Sustain 0 (Instr 1)
; t 233.5077 Sustain 0 (Instr 2)
    db 147,1,72,4,57,23,1,3,21,1  ; n868 t=233.526s dur=1096ms, vel 33->23, sust 772->1096, freq=277Hz, sample=57
; t 233.7990 Sustain 127 (Instr 1)
; t 233.7990 Sustain 127 (Instr 2)
    db 91,1,181,2,69,23,1,4,114,1  ; n869 t=233.929s dur=693ms, vel 33->23, sust 400->693, freq=370Hz, sample=69
    db 254,0,177,1,69,26,2,5,184,1  ; n870 t=234.275s dur=433ms, vel 38->26, freq=440Hz, sample=69
    db 13,0,102,12,45,25,1,6,139,0  ; n871 t=234.529s dur=3174ms, vel 37->25, sust 4978->3174, freq=139Hz, sample=45
    db 108,0,102,12,33,25,1,7,69,0  ; n872 t=234.542s dur=3174ms, vel 37->25, sust 4985->3174, freq=69Hz, sample=33
; t 234.6223 Sustain 0 (Instr 1)
; t 234.6223 Sustain 0 (Instr 2)
    db 18,0,102,12,57,25,1,8,21,1  ; n873 t=234.650s dur=3174ms, vel 36->25, sust 780->3174, freq=277Hz, sample=57
    db 111,1,102,12,69,30,2,9,42,2  ; n874 t=234.668s dur=3174ms, vel 44->30, sust 1258->3174, freq=554Hz, sample=69
; t 234.9810 Sustain 127 (Instr 1)
; t 234.9810 Sustain 127 (Instr 2)
    db 65,1,58,11,69,23,1,10,93,1  ; n875 t=235.036s dur=2874ms, vel 33->23, sust 772->2874, freq=349Hz, sample=69
    db 118,1,249,9,69,26,2,11,159,1  ; n876 t=235.357s dur=2553ms, vel 38->26, sust 451->2553, freq=415Hz, sample=69
; t 235.6939 Soft 0 (Instr 1)
; t 235.6939 Soft 0 (Instr 2)
    db 78,1,131,8,57,33,1,12,21,1  ; n877 t=235.730s dur=2179ms, sust 722->2179, freq=277Hz, sample=57
    db 92,1,53,7,69,33,1,13,93,1  ; n878 t=236.064s dur=1845ms, sust 773->1845, freq=349Hz, sample=69
    db 80,1,217,5,69,41,2,14,159,1  ; n879 t=236.412s dur=1497ms, sust 408->1497, freq=415Hz, sample=69
    db 117,1,137,4,57,40,1,15,21,1  ; n880 t=236.748s dur=1161ms, sust 778->1161, freq=277Hz, sample=57
    db 89,1,20,3,69,37,1,16,93,1  ; n881 t=237.121s dur=788ms, sust 562->788, freq=349Hz, sample=69
    db 129,1,188,1,69,40,2,17,159,1  ; n882 t=237.466s dur=444ms, sust 407->444, freq=415Hz, sample=69
    db 7,0,116,4,69,58,2,18,42,2  ; n883 t=237.851s dur=1140ms, sust 594->1140, freq=554Hz, sample=69
    db 96,1,110,4,57,42,1,19,21,1  ; n884 t=237.857s dur=1134ms, sust 488->1134, freq=277Hz, sample=57
; t 237.9098 Sustain 0 (Instr 1)
; t 237.9098 Sustain 0 (Instr 2)
; t 238.1431 Sustain 127 (Instr 1)
; t 238.1431 Sustain 127 (Instr 2)
    db 118,1,14,3,69,37,1,20,93,1  ; n885 t=238.209s dur=782ms, sust 420->782, freq=349Hz, sample=69
    db 97,1,152,1,69,39,2,21,159,1  ; n886 t=238.583s dur=408ms, sust 90->408, freq=415Hz, sample=69
    db 13,0,180,11,69,57,2,22,75,2  ; n887 t=238.936s dur=2996ms, sust 2290->2996, freq=587Hz, sample=69
    db 122,1,229,7,57,41,1,23,21,1  ; n888 t=238.949s dur=2021ms, sust 1004->2021, freq=277Hz, sample=57
; t 238.9917 Sustain 0 (Instr 1)
; t 238.9917 Sustain 0 (Instr 2)
; t 239.3127 Sustain 127 (Instr 1)
; t 239.3127 Sustain 127 (Instr 2)
    db 131,1,107,6,69,36,1,24,114,1  ; n889 t=239.327s dur=1643ms, sust 498->1643, freq=370Hz, sample=69
    db 200,0,232,4,69,38,2,25,184,1  ; n890 t=239.714s dur=1256ms, sust 364->1256, freq=440Hz, sample=69
    db 19,0,32,4,45,44,1,26,92,0  ; n891 t=239.914s dur=1056ms, sust 689->1056, freq=92Hz, sample=45
    db 88,0,12,4,57,46,1,27,185,0  ; n892 t=239.933s dur=1036ms, sust 600->1036, freq=185Hz, sample=57
    db 70,1,185,3,57,44,1,28,21,1  ; n893 t=240.021s dur=953ms, freq=277Hz, sample=57
    db 76,1,34,3,69,40,1,29,114,1  ; n894 t=240.347s dur=802ms, freq=370Hz, sample=69
    db 249,0,114,5,69,38,2,30,184,1  ; n895 t=240.679s dur=1394ms, sust 673->1394, freq=440Hz, sample=69
    db 7,0,120,4,57,46,1,31,220,0  ; n896 t=240.929s dur=1144ms, sust 462->1144, freq=220Hz, sample=57
    db 93,0,113,4,45,46,1,0,110,0  ; n897 t=240.936s dur=1137ms, sust 546->1137, freq=110Hz, sample=45
; t 240.9702 Sustain 0 (Instr 1)
; t 240.9702 Sustain 0 (Instr 2)
    db 53,1,20,4,57,33,1,1,21,1  ; n898 t=241.029s dur=1044ms, sust 707->1044, freq=277Hz, sample=57
; t 241.1971 Sustain 127 (Instr 1)
; t 241.1971 Sustain 127 (Instr 2)
    db 88,1,243,2,69,33,1,2,114,1  ; n899 t=241.338s dur=755ms, freq=370Hz, sample=69
    db 242,0,149,1,69,38,2,3,184,1  ; n900 t=241.682s dur=405ms, freq=440Hz, sample=69
    db 25,0,171,4,57,47,1,4,185,0  ; n901 t=241.924s dur=1195ms, sust 634->1195, freq=185Hz, sample=57
    db 86,0,147,4,45,46,1,5,92,0  ; n902 t=241.948s dur=1171ms, sust 771->1171, freq=92Hz, sample=45
    db 2,0,61,4,69,51,2,6,11,2  ; n903 t=242.034s dur=1085ms, sust 785->1085, freq=523Hz, sample=69
    db 156,1,59,4,57,33,1,7,21,1  ; n904 t=242.036s dur=1083ms, sust 758->1083, freq=277Hz, sample=57
; t 242.0733 Sustain 0 (Instr 1)
; t 242.0733 Sustain 0 (Instr 2)
; t 242.3675 Sustain 127 (Instr 1)
; t 242.3675 Sustain 127 (Instr 2)
; t 242.4263 Soft 127 (Instr 1)
; t 242.4263 Soft 127 (Instr 2)
    db 76,1,159,2,69,23,1,8,114,1  ; n905 t=242.448s dur=671ms, vel 33->23, sust 366->671, freq=370Hz, sample=69
    db 189,0,136,1,69,27,2,9,184,1  ; n906 t=242.779s dur=392ms, vel 39->27, freq=440Hz, sample=69
    db 7,0,173,9,45,28,1,10,139,0  ; n907 t=242.969s dur=2477ms, vel 40->28, sust 1429->2477, freq=139Hz, sample=45
    db 160,0,165,9,33,28,1,11,69,0  ; n908 t=242.976s dur=2469ms, vel 41->28, sust 1093->2469, freq=69Hz, sample=33
; t 243.1194 Sustain 0 (Instr 1)
; t 243.1194 Sustain 0 (Instr 2)
    db 9,0,5,9,69,35,2,12,42,2  ; n909 t=243.137s dur=2309ms, vel 51->35, sust 1030->2309, freq=554Hz, sample=69
    db 164,1,252,8,57,27,1,13,21,1  ; n910 t=243.145s dur=2300ms, vel 39->27, sust 953->2300, freq=277Hz, sample=57
; t 243.5409 Sustain 127 (Instr 1)
; t 243.5409 Sustain 127 (Instr 2)
    db 128,1,88,7,69,23,1,14,93,1  ; n911 t=243.565s dur=1880ms, vel 33->23, sust 835->1880, freq=349Hz, sample=69
    db 132,1,216,5,69,26,2,15,159,1  ; n912 t=243.950s dur=1496ms, vel 38->26, sust 452->1496, freq=415Hz, sample=69
    db 128,1,84,4,57,23,1,16,21,1  ; n913 t=244.338s dur=1108ms, vel 33->23, sust 681->1108, freq=277Hz, sample=57
    db 51,1,212,2,69,23,1,17,93,1  ; n914 t=244.722s dur=724ms, vel 33->23, sust 371->724, freq=349Hz, sample=69
    db 244,0,230,1,69,27,2,18,159,1  ; n915 t=245.029s dur=486ms, vel 39->27, freq=415Hz, sample=69
; t 245.0705 Soft 0 (Instr 1)
; t 245.0705 Soft 0 (Instr 2)
    db 36,0,38,10,33,38,1,19,46,0  ; n916 t=245.273s dur=2598ms, sust 1490->2598, freq=46Hz, sample=33
    db 147,0,1,10,45,38,1,20,92,0  ; n917 t=245.309s dur=2561ms, sust 1395->2561, freq=92Hz, sample=45
; t 245.4459 Sustain 0 (Instr 1)
; t 245.4459 Sustain 0 (Instr 2)
    db 28,0,111,9,69,51,2,21,42,2  ; n918 t=245.456s dur=2415ms, sust 780->2415, freq=554Hz, sample=69
    db 171,1,83,9,57,36,1,22,21,1  ; n919 t=245.483s dur=2387ms, sust 885->2387, freq=277Hz, sample=57
; t 245.7774 Sustain 127 (Instr 1)
; t 245.7774 Sustain 127 (Instr 2)
    db 135,1,168,7,69,33,1,23,114,1  ; n920 t=245.910s dur=1960ms, sust 489->1960, freq=370Hz, sample=69
    db 162,1,33,6,69,38,2,24,184,1  ; n921 t=246.301s dur=1569ms, sust 828->1569, freq=440Hz, sample=69
    db 128,1,127,4,57,33,1,25,21,1  ; n922 t=246.719s dur=1151ms, sust 680->1151, freq=277Hz, sample=57
    db 119,1,37,3,69,33,1,26,114,1  ; n923 t=247.103s dur=805ms, freq=370Hz, sample=69
    db 233,0,186,1,69,39,2,27,184,1  ; n924 t=247.478s dur=442ms, freq=440Hz, sample=69
    db 5,0,12,11,33,39,1,28,78,0  ; n925 t=247.712s dur=2828ms, sust 905->2828, freq=78Hz, sample=33
    db 137,0,12,11,45,39,1,29,156,0  ; n926 t=247.717s dur=2828ms, sust 1098->2828, freq=156Hz, sample=45
    db 15,0,48,13,69,52,2,30,238,1  ; n927 t=247.854s dur=3376ms, sust 1568->3376, freq=494Hz, sample=69
    db 206,1,33,13,57,37,1,31,247,0  ; n928 t=247.869s dur=3361ms, sust 927->3361, freq=247Hz, sample=57
; t 247.8709 Sustain 0 (Instr 1)
; t 247.8709 Sustain 0 (Instr 2)
; t 248.2944 Sustain 127 (Instr 1)
; t 248.2944 Sustain 127 (Instr 2)
    db 91,1,84,11,69,33,1,0,114,1  ; n929 t=248.331s dur=2900ms, sust 746->2900, freq=370Hz, sample=69
    db 97,1,248,9,69,38,2,1,184,1  ; n930 t=248.678s dur=2552ms, sust 718->2552, freq=440Hz, sample=69
    db 125,1,151,8,57,33,1,2,247,0  ; n931 t=249.031s dur=2199ms, sust 888->2199, freq=247Hz, sample=57
    db 90,1,27,7,69,33,1,3,114,1  ; n932 t=249.412s dur=1819ms, sust 759->1819, freq=370Hz, sample=69
    db 118,1,192,5,69,38,2,4,184,1  ; n933 t=249.758s dur=1472ms, sust 554->1472, freq=440Hz, sample=69
    db 87,1,74,4,57,33,1,5,247,0  ; n934 t=250.132s dur=1098ms, sust 799->1098, freq=247Hz, sample=57
    db 101,1,50,3,69,33,1,6,114,1  ; n935 t=250.475s dur=818ms, freq=370Hz, sample=69
    db 4,1,212,1,69,38,2,7,184,1  ; n936 t=250.832s dur=468ms, freq=440Hz, sample=69
    db 31,0,117,5,45,38,1,8,82,0  ; n937 t=251.092s dur=1397ms, sust 764->1397, freq=82Hz, sample=45
    db 107,0,86,5,57,38,1,9,165,0  ; n938 t=251.123s dur=1366ms, sust 681->1366, freq=165Hz, sample=57
    db 3,0,236,4,57,36,1,10,247,0  ; n939 t=251.230s dur=1260ms, sust 865->1260, freq=247Hz, sample=57
; t 251.2308 Sustain 0 (Instr 1)
; t 251.2308 Sustain 0 (Instr 2)
    db 180,1,232,4,69,52,2,11,238,1  ; n940 t=251.233s dur=1256ms, sust 840->1256, freq=494Hz, sample=69
; t 251.6177 Sustain 127 (Instr 1)
; t 251.6177 Sustain 127 (Instr 2)
    db 139,1,74,3,69,33,1,12,74,1  ; n941 t=251.669s dur=842ms, freq=330Hz, sample=69
    db 237,0,182,1,69,38,2,13,159,1  ; n942 t=252.064s dur=438ms, freq=415Hz, sample=69
    db 5,0,60,5,33,39,1,14,69,0  ; n943 t=252.302s dur=1340ms, sust 878->1340, freq=69Hz, sample=33
    db 140,0,54,5,45,39,1,15,139,0  ; n944 t=252.307s dur=1334ms, sust 867->1334, freq=139Hz, sample=45
    db 16,0,170,4,57,37,1,16,220,0  ; n945 t=252.447s dur=1194ms, sust 856->1194, freq=220Hz, sample=57
    db 143,1,154,4,69,52,2,17,184,1  ; n946 t=252.463s dur=1178ms, sust 773->1178, freq=440Hz, sample=69
; t 252.4898 Sustain 0 (Instr 1)
; t 252.4898 Sustain 0 (Instr 2)
    db 84,1,26,3,69,33,1,18,74,1  ; n947 t=252.862s dur=794ms, freq=330Hz, sample=69
; t 252.8820 Sustain 127 (Instr 1)
; t 252.8820 Sustain 127 (Instr 2)
    db 8,1,198,1,69,38,2,19,159,1  ; n948 t=253.202s dur=454ms, freq=415Hz, sample=69
    db 63,0,75,5,33,36,1,20,78,0  ; n949 t=253.465s dur=1355ms, sust 762->1355, freq=78Hz, sample=33
    db 87,0,12,5,45,36,1,21,156,0  ; n950 t=253.529s dur=1292ms, sust 620->1292, freq=156Hz, sample=45
    db 7,0,182,4,69,44,2,22,184,1  ; n951 t=253.615s dur=1206ms, sust 811->1206, freq=440Hz, sample=69
    db 135,1,174,4,57,34,1,23,220,0  ; n952 t=253.623s dur=1198ms, sust 798->1198, freq=220Hz, sample=57
; t 253.6418 Sustain 0 (Instr 1)
; t 253.6418 Sustain 0 (Instr 2)
    db 129,1,39,3,57,33,1,24,55,1  ; n953 t=254.014s dur=807ms, sust 628->807, freq=311Hz, sample=57
; t 254.0147 Sustain 127 (Instr 1)
; t 254.0147 Sustain 127 (Instr 2)
    db 17,1,218,1,69,33,1,25,114,1  ; n954 t=254.398s dur=474ms, freq=370Hz, sample=69
    db 37,0,113,5,33,36,1,26,65,0  ; n955 t=254.672s dur=1393ms, sust 799->1393, freq=65Hz, sample=33
    db 93,0,75,5,45,36,1,27,131,0  ; n956 t=254.709s dur=1355ms, sust 754->1355, freq=131Hz, sample=45
    db 4,0,238,4,57,35,1,28,208,0  ; n957 t=254.802s dur=1262ms, sust 944->1262, freq=208Hz, sample=57
    db 186,1,234,4,69,44,2,29,159,1  ; n958 t=254.806s dur=1258ms, sust 902->1258, freq=415Hz, sample=69
; t 254.8213 Sustain 0 (Instr 1)
; t 254.8213 Sustain 0 (Instr 2)
; t 255.1439 Sustain 127 (Instr 1)
; t 255.1439 Sustain 127 (Instr 2)
; t 255.2454 Soft 127 (Instr 1)
; t 255.2454 Soft 127 (Instr 2)
    db 147,1,48,3,57,23,1,30,55,1  ; n959 t=255.249s dur=816ms, vel 33->23, sust 517->816, freq=311Hz, sample=57
    db 246,0,247,1,69,23,1,31,114,1  ; n960 t=255.651s dur=503ms, vel 33->23, freq=370Hz, sample=69
    db 30,0,232,5,33,24,1,0,69,0  ; n961 t=255.897s dur=1512ms, vel 35->24, sust 819->1512, freq=69Hz, sample=33
    db 126,0,202,5,45,24,1,1,139,0  ; n962 t=255.927s dur=1482ms, vel 35->24, sust 656->1482, freq=139Hz, sample=45
    db 24,0,76,5,57,23,1,2,208,0  ; n963 t=256.053s dur=1356ms, vel 33->23, sust 1064->1356, freq=208Hz, sample=57
; t 256.0649 Sustain 0 (Instr 1)
; t 256.0649 Sustain 0 (Instr 2)
    db 184,1,53,5,69,30,2,3,159,1  ; n964 t=256.077s dur=1333ms, vel 44->30, sust 958->1333, freq=415Hz, sample=69
; t 256.3971 Sustain 127 (Instr 1)
; t 256.3971 Sustain 127 (Instr 2)
    db 172,1,125,3,57,23,1,4,21,1  ; n965 t=256.517s dur=893ms, vel 33->23, sust 638->893, freq=277Hz, sample=57
    db 71,1,65,2,69,23,1,5,74,1  ; n966 t=256.945s dur=577ms, vel 33->23, freq=330Hz, sample=69
    db 18,0,133,10,33,24,1,6,55,0  ; n967 t=257.272s dur=2693ms, vel 35->24, sust 754->2693, freq=55Hz, sample=33
    db 120,0,115,10,45,24,1,7,110,0  ; n968 t=257.290s dur=2675ms, vel 35->24, sust 880->2675, freq=110Hz, sample=45
    db 42,0,251,9,57,23,1,8,185,0  ; n969 t=257.410s dur=2555ms, vel 33->23, sust 1028->2555, freq=185Hz, sample=57
; t 257.4098 Sustain 0 (Instr 1)
; t 257.4098 Sustain 0 (Instr 2)
    db 182,1,209,9,69,28,1,9,114,1  ; n970 t=257.452s dur=2513ms, vel 40->28, sust 823->2513, freq=370Hz, sample=69
; t 257.7868 Sustain 127 (Instr 1)
; t 257.7868 Sustain 127 (Instr 2)
    db 153,1,28,8,57,23,1,10,21,1  ; n971 t=257.889s dur=2076ms, vel 33->23, sust 662->2076, freq=277Hz, sample=57
    db 127,1,131,6,57,23,1,11,55,1  ; n972 t=258.298s dur=1667ms, vel 33->23, sust 556->1667, freq=311Hz, sample=57
    db 161,1,3,5,57,23,1,12,185,0  ; n973 t=258.682s dur=1283ms, vel 33->23, sust 872->1283, freq=185Hz, sample=57
    db 171,1,171,3,57,23,1,13,21,1  ; n974 t=259.098s dur=939ms, vel 33->23, freq=277Hz, sample=57
    db 24,1,0,2,57,23,1,14,55,1  ; n975 t=259.525s dur=512ms, vel 33->23, freq=311Hz, sample=57
    db 22,0,125,5,33,25,1,15,52,0  ; n976 t=259.805s dur=1405ms, vel 36->25, sust 837->1405, freq=52Hz, sample=33
    db 131,0,102,5,45,25,1,16,104,0  ; n977 t=259.828s dur=1382ms, vel 36->25, sust 730->1382, freq=104Hz, sample=45
    db 7,0,227,4,69,30,2,17,159,1  ; n978 t=259.959s dur=1251ms, vel 44->30, sust 856->1251, freq=415Hz, sample=69
; t 259.9654 Sustain 0 (Instr 1)
; t 259.9654 Sustain 0 (Instr 2)
    db 157,1,220,4,57,23,1,18,208,0  ; n979 t=259.966s dur=1244ms, vel 34->23, sust 655->1244, freq=208Hz, sample=57
; t 260.2366 Sustain 127 (Instr 1)
; t 260.2366 Sustain 127 (Instr 2)
    db 154,1,62,3,57,23,1,19,21,1  ; n980 t=260.380s dur=830ms, vel 33->23, sust 733->830, freq=277Hz, sample=57
    db 28,1,211,1,57,23,1,20,55,1  ; n981 t=260.790s dur=467ms, vel 34->23, freq=311Hz, sample=57
    db 43,0,161,6,33,25,1,21,46,0  ; n982 t=261.074s dur=1697ms, vel 37->25, sust 956->1697, freq=46Hz, sample=33
    db 112,0,118,6,45,26,1,22,92,0  ; n983 t=261.117s dur=1654ms, vel 38->26, sust 938->1654, freq=92Hz, sample=45
; t 261.2105 Sustain 0 (Instr 1)
; t 261.2105 Sustain 0 (Instr 2)
    db 36,0,6,6,57,25,1,23,220,0  ; n984 t=261.229s dur=1542ms, vel 37->25, sust 1077->1542, freq=220Hz, sample=57
    db 4,2,226,5,69,31,2,24,184,1  ; n985 t=261.265s dur=1506ms, vel 45->31, sust 878->1506, freq=440Hz, sample=69
; t 261.7507 Sustain 127 (Instr 1)
; t 261.7507 Sustain 127 (Instr 2)
    db 225,1,222,3,57,23,1,25,21,1  ; n986 t=261.781s dur=990ms, vel 33->23, sust 639->990, freq=277Hz, sample=57
    db 90,1,253,1,57,23,1,26,55,1  ; n987 t=262.262s dur=509ms, vel 33->23, sust 191->509, freq=311Hz, sample=57
    db 44,0,119,11,33,25,1,27,52,0  ; n988 t=262.608s dur=2935ms, vel 36->25, sust 2385->2935, freq=52Hz, sample=33
    db 138,0,75,11,45,25,1,28,104,0  ; n989 t=262.652s dur=2891ms, vel 36->25, sust 2320->2891, freq=104Hz, sample=45
; t 262.7712 Sustain 0 (Instr 1)
; t 262.7712 Sustain 0 (Instr 2)
    db 7,0,193,10,69,30,2,29,159,1  ; n990 t=262.789s dur=2753ms, vel 43->30, sust 2458->2753, freq=415Hz, sample=69
    db 4,2,186,10,57,23,1,30,208,0  ; n991 t=262.797s dur=2746ms, vel 34->23, sust 1036->2746, freq=208Hz, sample=57
; t 263.1950 Sustain 127 (Instr 1)
; t 263.1950 Sustain 127 (Instr 2)
    db 162,1,182,8,57,23,1,31,21,1  ; n992 t=263.312s dur=2230ms, vel 33->23, sust 1006->2230, freq=277Hz, sample=57
    db 185,1,20,7,69,23,1,0,74,1  ; n993 t=263.731s dur=1812ms, vel 33->23, sust 1014->1812, freq=330Hz, sample=69
    db 215,1,91,5,57,23,1,1,208,0  ; n994 t=264.172s dur=1371ms, vel 33->23, sust 1046->1371, freq=208Hz, sample=57
    db 129,1,132,3,57,23,1,2,21,1  ; n995 t=264.642s dur=900ms, vel 33->23, sust 613->900, freq=277Hz, sample=57
    db 88,1,3,2,69,23,1,3,74,1  ; n996 t=265.028s dur=515ms, vel 33->23, sust 214->515, freq=330Hz, sample=69
    db 44,0,101,11,33,25,1,4,52,0  ; n997 t=265.371s dur=2917ms, vel 36->25, sust 1961->2917, freq=52Hz, sample=33
    db 124,0,57,11,45,25,1,5,104,0  ; n998 t=265.415s dur=2873ms, vel 36->25, sust 1961->2873, freq=104Hz, sample=45
    db 20,0,189,10,69,30,2,6,159,1  ; n999 t=265.539s dur=2749ms, vel 44->30, sust 2295->2749, freq=415Hz, sample=69
; t 265.5432 Sustain 0 (Instr 1)
; t 265.5432 Sustain 0 (Instr 2)
    db 173,1,169,10,57,24,1,7,185,0  ; n1000 t=265.559s dur=2729ms, vel 35->24, sust 934->2729, freq=185Hz, sample=57
; t 265.8185 Sustain 127 (Instr 1)
; t 265.8185 Sustain 127 (Instr 2)
    db 156,1,252,8,57,23,1,8,6,1  ; n1001 t=265.988s dur=2300ms, vel 33->23, sust 999->2300, freq=262Hz, sample=57
    db 185,1,96,7,57,23,1,9,55,1  ; n1002 t=266.400s dur=1888ms, vel 33->23, sust 593->1888, freq=311Hz, sample=57
    db 234,1,167,5,57,23,1,10,185,0  ; n1003 t=266.841s dur=1447ms, vel 33->23, sust 900->1447, freq=185Hz, sample=57
    db 230,1,190,3,57,23,1,11,6,1  ; n1004 t=267.331s dur=958ms, vel 33->23, sust 650->958, freq=262Hz, sample=57
    db 83,1,216,1,57,23,1,12,55,1  ; n1005 t=267.816s dur=472ms, vel 33->23, sust 163->472, freq=311Hz, sample=57
    db 11,0,102,12,33,25,1,13,69,0  ; n1006 t=268.155s dur=3174ms, vel 36->25, sust 4507->3174, freq=69Hz, sample=33
    db 127,0,209,14,45,25,1,14,104,0  ; n1007 t=268.166s dur=3793ms, vel 36->25, sust 3403->3793, freq=104Hz, sample=45
; t 268.2888 Sustain 0 (Instr 1)
; t 268.2888 Sustain 0 (Instr 2)
    db 7,0,82,14,57,23,1,15,165,0  ; n1008 t=268.293s dur=3666ms, vel 34->23, sust 516->3666, freq=165Hz, sample=57
    db 163,1,102,12,57,24,1,16,21,1  ; n1009 t=268.300s dur=3174ms, vel 35->24, sust 509->3174, freq=277Hz, sample=57
; t 268.6431 Sustain 127 (Instr 1)
; t 268.6431 Sustain 127 (Instr 2)
    db 170,1,167,12,57,23,1,17,208,0  ; n1010 t=268.720s dur=3239ms, vel 33->23, sust 542->3239, freq=208Hz, sample=57
    db 106,1,253,10,57,23,1,18,21,1  ; n1011 t=269.146s dur=2813ms, vel 33->23, sust 394->2813, freq=277Hz, sample=57
    db 165,1,148,9,57,23,1,19,208,0  ; n1012 t=269.507s dur=2452ms, vel 33->23, sust 1052->2452, freq=208Hz, sample=57
    db 139,1,238,7,57,23,1,20,21,1  ; n1013 t=269.928s dur=2030ms, vel 33->23, sust 506->2030, freq=277Hz, sample=57
    db 171,1,100,6,69,23,1,21,74,1  ; n1014 t=270.323s dur=1636ms, vel 33->23, sust 885->1636, freq=330Hz, sample=69
    db 131,1,185,4,57,23,1,22,208,0  ; n1015 t=270.750s dur=1209ms, vel 33->23, sust 731->1209, freq=208Hz, sample=57
    db 135,1,54,3,57,23,1,23,21,1  ; n1016 t=271.137s dur=822ms, vel 33->23, sust 520->822, freq=277Hz, sample=57
    db 86,1,126,7,69,23,1,24,74,1  ; n1017 t=271.528s dur=1918ms, vel 33->23, sust 1037->1918, freq=330Hz, sample=69
    db 177,0,40,6,45,30,1,25,104,0  ; n1018 t=271.871s dur=1576ms, vel 44->30, sust 758->1576, freq=104Hz, sample=45
; t 271.9593 Sustain 0 (Instr 1)
; t 271.9593 Sustain 0 (Instr 2)
    db 147,1,119,5,57,23,1,26,208,0  ; n1019 t=272.048s dur=1399ms, vel 33->23, sust 556->1399, freq=208Hz, sample=57
; t 272.3134 Sustain 127 (Instr 1)
; t 272.3134 Sustain 127 (Instr 2)
    db 139,1,227,3,57,24,1,27,21,1  ; n1020 t=272.451s dur=995ms, vel 35->24, sust 478->995, freq=277Hz, sample=57
    db 21,1,89,2,69,23,1,28,74,1  ; n1021 t=272.846s dur=601ms, vel 34->23, sust 271->601, freq=330Hz, sample=69
    db 221,0,68,1,45,27,1,29,104,0  ; n1022 t=273.123s dur=324ms, vel 39->27, sust 203->324, freq=104Hz, sample=45
; t 273.2379 Soft 0 (Instr 1)
; t 273.2379 Soft 0 (Instr 2)
    db 92,0,35,13,33,35,1,30,65,0  ; n1023 t=273.344s dur=3363ms, sust 4392->3363, freq=65Hz, sample=33
    db 64,0,50,14,45,41,1,31,104,0  ; n1024 t=273.435s dur=3634ms, sust 3287->3634, freq=104Hz, sample=45
; t 273.4469 Sustain 0 (Instr 1)
; t 273.4469 Sustain 0 (Instr 2)
    db 129,1,111,3,57,40,1,0,208,0  ; n1025 t=273.499s dur=879ms, freq=208Hz, sample=57
    db 147,1,187,1,57,33,1,1,55,1  ; n1026 t=273.884s dur=443ms, freq=311Hz, sample=57
    db 153,1,222,10,69,33,1,2,114,1  ; n1027 t=274.287s dur=2782ms, sust 492->2782, freq=370Hz, sample=69
; t 274.3820 Sustain 127 (Instr 1)
; t 274.3820 Sustain 127 (Instr 2)
    db 147,1,69,9,57,33,1,3,208,0  ; n1028 t=274.697s dur=2373ms, sust 929->2373, freq=208Hz, sample=57
    db 139,1,178,7,57,33,1,4,55,1  ; n1029 t=275.099s dur=1970ms, sust 550->1970, freq=311Hz, sample=57
    db 137,1,39,6,69,33,1,5,114,1  ; n1030 t=275.494s dur=1575ms, sust 768->1575, freq=370Hz, sample=69
    db 124,1,158,4,57,33,1,6,208,0  ; n1031 t=275.887s dur=1182ms, sust 692->1182, freq=208Hz, sample=57
    db 133,1,34,3,57,33,1,7,55,1  ; n1032 t=276.267s dur=802ms, sust 580->802, freq=311Hz, sample=57
    db 134,1,157,1,69,33,1,8,114,1  ; n1033 t=276.656s dur=413ms, sust 395->413, freq=370Hz, sample=69
    db 98,0,162,5,45,44,1,9,104,0  ; n1034 t=277.046s dur=1442ms, sust 720->1442, freq=104Hz, sample=45
; t 277.0696 Sustain 0 (Instr 1)
; t 277.0696 Sustain 0 (Instr 2)
    db 136,1,63,5,57,33,1,10,208,0  ; n1035 t=277.144s dur=1343ms, sust 692->1343, freq=208Hz, sample=57
; t 277.5045 Sustain 127 (Instr 1)
; t 277.5045 Sustain 127 (Instr 2)
    db 161,1,183,3,57,33,1,11,55,1  ; n1036 t=277.536s dur=951ms, sust 488->951, freq=311Hz, sample=57
    db 14,1,23,2,69,33,1,12,114,1  ; n1037 t=277.953s dur=535ms, sust 484->535, freq=370Hz, sample=69
; t 278.0917 Soft 0 (Instr 1)
; t 278.0917 Soft 0 (Instr 2)
    db 182,0,9,1,45,41,1,13,104,0  ; n1038 t=278.223s dur=265ms, sust 184->265, freq=104Hz, sample=45
    db 39,0,102,12,33,34,1,14,69,0  ; n1039 t=278.405s dur=3174ms, sust 3808->3174, freq=69Hz, sample=33
    db 44,0,239,11,57,35,1,15,208,0  ; n1040 t=278.445s dur=3055ms, sust 478->3055, freq=208Hz, sample=57
    db 132,1,195,11,45,40,1,16,104,0  ; n1041 t=278.488s dur=3011ms, sust 2729->3011, freq=104Hz, sample=45
; t 278.4882 Sustain 0 (Instr 1)
; t 278.4882 Sustain 0 (Instr 2)
; t 278.8698 Sustain 127 (Instr 1)
; t 278.8698 Sustain 127 (Instr 2)
    db 101,1,63,10,69,33,1,17,74,1  ; n1042 t=278.876s dur=2623ms, sust 354->2623, freq=330Hz, sample=69
    db 64,1,218,8,57,37,1,18,21,1  ; n1043 t=279.233s dur=2266ms, sust 443->2266, freq=277Hz, sample=57
    db 53,1,154,7,69,43,2,19,159,1  ; n1044 t=279.553s dur=1946ms, sust 424->1946, freq=415Hz, sample=69
    db 127,1,101,6,69,37,1,20,74,1  ; n1045 t=279.862s dur=1637ms, sust 474->1637, freq=330Hz, sample=69
    db 52,1,230,4,69,40,2,21,42,2  ; n1046 t=280.245s dur=1254ms, sust 216->1254, freq=554Hz, sample=69
    db 75,1,179,3,69,44,2,22,159,1  ; n1047 t=280.553s dur=947ms, sust 372->947, freq=415Hz, sample=69
    db 61,1,103,2,81,41,2,23,147,2  ; n1048 t=280.884s dur=615ms, sust 384->615, freq=659Hz, sample=81
    db 21,1,238,1,69,42,2,24,42,2  ; n1049 t=281.201s dur=494ms, freq=554Hz, sample=69
    db 208,0,202,4,45,44,1,25,104,0  ; n1050 t=281.478s dur=1226ms, sust 752->1226, freq=104Hz, sample=45
; t 281.4996 Sustain 0 (Instr 1)
; t 281.4996 Sustain 0 (Instr 2)
    db 89,1,250,3,81,41,2,26,63,3  ; n1051 t=281.686s dur=1018ms, sust 341->1018, freq=831Hz, sample=81
; t 282.0110 Sustain 127 (Instr 1)
; t 282.0110 Sustain 127 (Instr 2)
    db 41,1,161,2,81,38,2,27,147,2  ; n1052 t=282.031s dur=673ms, sust 331->673, freq=659Hz, sample=81
    db 153,0,149,1,69,38,2,28,42,2  ; n1053 t=282.329s dur=405ms, freq=554Hz, sample=69
    db 158,0,222,0,45,47,1,29,104,0  ; n1054 t=282.482s dur=222ms, sust 78->222, freq=104Hz, sample=45
    db 37,0,141,16,33,35,1,30,52,0  ; n1055 t=282.640s dur=4237ms, sust 3856->4237, freq=52Hz, sample=33
    db 48,0,173,11,45,42,1,31,104,0  ; n1056 t=282.677s dur=2989ms, sust 2539->2989, freq=104Hz, sample=45
; t 282.7046 Sustain 0 (Instr 1)
; t 282.7046 Sustain 0 (Instr 2)
    db 63,1,65,1,69,43,2,0,11,2  ; n1057 t=282.725s dur=321ms, freq=523Hz, sample=69
    db 51,1,123,2,69,40,2,1,110,2  ; n1058 t=283.043s dur=635ms, sust 315->635, freq=622Hz, sample=69
; t 283.2959 Sustain 127 (Instr 1)
; t 283.2959 Sustain 127 (Instr 2)
    db 79,1,176,1,69,38,2,2,184,1  ; n1059 t=283.350s dur=432ms, freq=440Hz, sample=69
; t 283.6794 Sustain 0 (Instr 1)
; t 283.6794 Sustain 0 (Instr 2)
    db 45,1,68,3,69,38,2,3,11,2  ; n1060 t=283.685s dur=836ms, sust 329->836, freq=523Hz, sample=69
; t 283.8626 Sustain 127 (Instr 1)
; t 283.8626 Sustain 127 (Instr 2)
    db 51,1,22,2,69,34,1,4,114,1  ; n1061 t=283.986s dur=534ms, sust 354->534, freq=370Hz, sample=69
    db 91,1,166,1,69,38,2,5,184,1  ; n1062 t=284.293s dur=422ms, freq=440Hz, sample=69
; t 284.5208 Sustain 0 (Instr 1)
; t 284.5208 Sustain 0 (Instr 2)
    db 67,1,2,4,57,33,1,6,55,1  ; n1063 t=284.640s dur=1026ms, sust 408->1026, freq=311Hz, sample=57
; t 284.7328 Sustain 127 (Instr 1)
; t 284.7328 Sustain 127 (Instr 2)
    db 115,1,191,2,69,34,1,7,114,1  ; n1064 t=284.963s dur=703ms, sust 408->703, freq=370Hz, sample=69
    db 104,1,101,3,57,36,1,8,220,0  ; n1065 t=285.333s dur=869ms, freq=220Hz, sample=57
; t 285.6667 Sustain 0 (Instr 1)
; t 285.6667 Sustain 0 (Instr 2)
    db 119,0,25,5,45,40,1,9,104,0  ; n1066 t=285.693s dur=1305ms, sust 832->1305, freq=104Hz, sample=45
    db 133,1,162,4,57,38,1,10,6,1  ; n1067 t=285.813s dur=1186ms, sust 933->1186, freq=262Hz, sample=57
    db 109,1,29,3,57,36,1,11,208,0  ; n1068 t=286.201s dur=797ms, sust 425->797, freq=208Hz, sample=57
; t 286.2972 Sustain 127 (Instr 1)
; t 286.2972 Sustain 127 (Instr 2)
    db 244,0,176,1,57,33,1,12,185,0  ; n1069 t=286.567s dur=432ms, sust 412->432, freq=185Hz, sample=57
    db 202,0,188,0,45,37,1,13,104,0  ; n1070 t=286.810s dur=188ms, sust 97->188, freq=104Hz, sample=45
; t 286.9990 Sustain 0 (Instr 1)
; t 286.9990 Sustain 0 (Instr 2)
    db 1,0,92,1,57,34,1,14,165,0  ; n1071 t=287.013s dur=348ms, freq=165Hz, sample=57
    db 5,0,208,11,45,34,1,15,104,0  ; n1072 t=287.014s dur=3024ms, sust 2650->3024, freq=104Hz, sample=45
    db 1,0,203,11,57,34,1,16,21,1  ; n1073 t=287.019s dur=3019ms, sust 505->3019, freq=277Hz, sample=57
    db 125,1,102,12,33,34,1,17,69,0  ; n1074 t=287.020s dur=3174ms, sust 3648->3174, freq=69Hz, sample=33
; t 287.1747 Soft 127 (Instr 1)
; t 287.1747 Soft 127 (Instr 2)
    db 108,1,77,10,69,23,1,18,74,1  ; n1075 t=287.401s dur=2637ms, vel 33->23, sust 281->2637, freq=330Hz, sample=69
; t 287.4196 Sustain 127 (Instr 1)
; t 287.4196 Sustain 127 (Instr 2)
    db 44,1,224,8,57,24,1,19,21,1  ; n1076 t=287.766s dur=2272ms, vel 35->24, sust 475->2272, freq=277Hz, sample=57
    db 59,1,180,7,69,30,2,20,159,1  ; n1077 t=288.066s dur=1972ms, vel 43->30, sust 757->1972, freq=415Hz, sample=69
    db 63,1,121,6,69,25,1,21,74,1  ; n1078 t=288.381s dur=1657ms, vel 37->25, sust 424->1657, freq=330Hz, sample=69
    db 64,1,58,5,69,27,2,22,42,2  ; n1079 t=288.700s dur=1338ms, vel 39->27, sust 216->1338, freq=554Hz, sample=69
    db 83,1,249,3,69,26,2,23,159,1  ; n1080 t=289.021s dur=1017ms, vel 38->26, sust 392->1017, freq=415Hz, sample=69
    db 57,1,167,2,81,26,2,24,147,2  ; n1081 t=289.359s dur=679ms, vel 38->26, sust 334->679, freq=659Hz, sample=81
    db 42,1,198,1,69,28,2,25,42,2  ; n1082 t=289.672s dur=454ms, vel 40->28, freq=554Hz, sample=69
    db 122,0,61,5,45,28,1,26,104,0  ; n1083 t=289.970s dur=1341ms, vel 41->28, sust 728->1341, freq=104Hz, sample=45
; t 290.0385 Sustain 0 (Instr 1)
; t 290.0385 Sustain 0 (Instr 2)
    db 155,1,194,4,81,31,2,27,63,3  ; n1084 t=290.093s dur=1218ms, vel 45->31, sust 452->1218, freq=831Hz, sample=81
; t 290.4377 Sustain 127 (Instr 1)
; t 290.4377 Sustain 127 (Instr 2)
    db 123,1,39,3,81,28,2,28,147,2  ; n1085 t=290.504s dur=807ms, vel 40->28, sust 462->807, freq=659Hz, sample=81
    db 160,0,217,1,69,26,2,29,42,2  ; n1086 t=290.883s dur=473ms, vel 38->26, freq=554Hz, sample=69
    db 240,0,13,1,45,25,1,30,104,0  ; n1087 t=291.042s dur=269ms, vel 36->25, sust 66->269, freq=104Hz, sample=45
    db 14,0,43,12,45,24,1,31,104,0  ; n1088 t=291.282s dur=3115ms, vel 35->24, sust 2742->3115, freq=104Hz, sample=45
    db 20,0,141,16,33,24,1,0,52,0  ; n1089 t=291.296s dur=4237ms, vel 35->24, sust 4082->4237, freq=52Hz, sample=33
; t 291.3117 Sustain 0 (Instr 1)
; t 291.3117 Sustain 0 (Instr 2)
    db 90,1,229,6,69,28,2,1,11,2  ; n1090 t=291.316s dur=1765ms, vel 41->28, sust 361->1765, freq=523Hz, sample=69
; t 291.6257 Sustain 127 (Instr 1)
; t 291.6257 Sustain 127 (Instr 2)
    db 70,1,139,5,69,26,2,2,110,2  ; n1091 t=291.662s dur=1419ms, vel 38->26, sust 358->1419, freq=622Hz, sample=69
    db 64,1,69,4,69,26,2,3,184,1  ; n1092 t=291.988s dur=1093ms, vel 38->26, sust 404->1093, freq=440Hz, sample=69
    db 83,1,5,3,69,26,2,4,11,2  ; n1093 t=292.308s dur=773ms, vel 38->26, sust 353->773, freq=523Hz, sample=69
    db 62,1,178,1,69,23,1,5,114,1  ; n1094 t=292.647s dur=434ms, vel 33->23, sust 360->434, freq=370Hz, sample=69
    db 93,1,152,5,69,26,2,6,184,1  ; n1095 t=292.965s dur=1432ms, vel 38->26, sust 406->1432, freq=440Hz, sample=69
; t 293.0814 Sustain 0 (Instr 1)
; t 293.0814 Sustain 0 (Instr 2)
    db 89,1,59,4,57,23,1,7,55,1  ; n1096 t=293.314s dur=1083ms, vel 33->23, sust 421->1083, freq=311Hz, sample=57
; t 293.3144 Sustain 127 (Instr 1)
; t 293.3144 Sustain 127 (Instr 2)
    db 88,1,226,2,69,23,1,8,114,1  ; n1097 t=293.659s dur=738ms, vel 33->23, sust 395->738, freq=370Hz, sample=69
    db 121,1,165,3,57,23,1,9,220,0  ; n1098 t=294.003s dur=933ms, vel 33->23, freq=220Hz, sample=57
    db 142,0,190,5,45,25,1,10,104,0  ; n1099 t=294.380s dur=1470ms, vel 37->25, sust 991->1470, freq=104Hz, sample=45
; t 294.3977 Sustain 0 (Instr 1)
; t 294.3977 Sustain 0 (Instr 2)
    db 172,1,49,5,57,28,1,11,6,1  ; n1100 t=294.521s dur=1329ms, vel 41->28, sust 1023->1329, freq=262Hz, sample=57
    db 111,1,133,3,57,23,1,12,208,0  ; n1101 t=294.949s dur=901ms, vel 33->23, sust 483->901, freq=208Hz, sample=57
; t 295.1947 Sustain 127 (Instr 1)
; t 295.1947 Sustain 127 (Instr 2)
    db 77,1,22,2,57,23,1,13,185,0  ; n1102 t=295.316s dur=534ms, vel 33->23, sust 274->534, freq=185Hz, sample=57
; t 295.3628 Soft 127 (Instr 1)
; t 295.3628 Soft 127 (Instr 2)
    db 121,0,201,0,45,23,1,14,104,0  ; n1103 t=295.649s dur=201ms, vel 33->23, sust 78->201, freq=104Hz, sample=45
    db 48,0,102,12,33,23,1,15,69,0  ; n1104 t=295.770s dur=3174ms, vel 34->23, sust 1033->3174, freq=69Hz, sample=33
    db 61,0,141,16,45,24,1,16,104,0  ; n1105 t=295.818s dur=4237ms, vel 35->24, sust 730->4237, freq=104Hz, sample=45
; t 295.8501 Sustain 0 (Instr 1)
; t 295.8501 Sustain 0 (Instr 2)
    db 8,0,219,20,57,25,1,17,165,0  ; n1106 t=295.879s dur=5339ms, vel 36->25, sust 669->5339, freq=165Hz, sample=57
    db 101,1,102,12,57,25,1,18,21,1  ; n1107 t=295.887s dur=3174ms, vel 36->25, sust 434->3174, freq=277Hz, sample=57
; t 296.1883 Sustain 127 (Instr 1)
; t 296.1883 Sustain 127 (Instr 2)
    db 107,1,141,16,57,23,1,19,208,0  ; n1108 t=296.245s dur=4237ms, vel 33->23, sust 740->4237, freq=208Hz, sample=57
    db 80,1,102,12,57,23,1,20,21,1  ; n1109 t=296.607s dur=3174ms, vel 33->23, sust 503->3174, freq=277Hz, sample=57
    db 99,1,219,20,69,23,1,21,74,1  ; n1110 t=296.943s dur=5339ms, vel 33->23, sust 426->5339, freq=330Hz, sample=69
    db 58,1,102,12,57,23,1,22,21,1  ; n1111 t=297.299s dur=3174ms, vel 33->23, sust 446->3174, freq=277Hz, sample=57
    db 76,1,141,16,57,23,1,23,208,0  ; n1112 t=297.613s dur=4237ms, vel 33->23, sust 217->4237, freq=208Hz, sample=57
    db 110,1,102,12,45,23,1,24,139,0  ; n1113 t=297.944s dur=3174ms, vel 33->23, sust 433->3174, freq=139Hz, sample=45
    db 67,1,219,20,57,23,1,25,165,0  ; n1114 t=298.310s dur=5339ms, vel 33->23, sust 428->5339, freq=165Hz, sample=57
    db 59,1,141,16,57,23,1,26,208,0  ; n1115 t=298.634s dur=4237ms, vel 33->23, sust 426->4237, freq=208Hz, sample=57
    db 92,1,102,12,57,23,1,27,21,1  ; n1116 t=298.949s dur=3174ms, vel 33->23, sust 551->3174, freq=277Hz, sample=57
    db 102,1,141,16,57,23,1,28,208,0  ; n1117 t=299.296s dur=4237ms, vel 33->23, sust 436->4237, freq=208Hz, sample=57
    db 26,1,159,15,57,23,1,29,165,0  ; n1118 t=299.655s dur=3999ms, vel 33->23, sust 178->3999, freq=165Hz, sample=57
    db 96,1,134,14,45,25,1,30,104,0  ; n1119 t=299.936s dur=3718ms, vel 37->25, sust 241->3718, freq=104Hz, sample=45
    db 155,1,102,12,45,23,1,31,139,0  ; n1120 t=300.288s dur=3174ms, vel 33->23, sust 880->3174, freq=139Hz, sample=45
    db 121,1,138,11,57,23,1,0,165,0  ; n1121 t=300.700s dur=2954ms, vel 33->23, sust 545->2954, freq=165Hz, sample=57
    db 97,1,17,10,57,23,1,1,208,0  ; n1122 t=301.077s dur=2577ms, vel 33->23, sust 388->2577, freq=208Hz, sample=57
    db 128,1,176,8,57,23,1,2,165,0  ; n1123 t=301.430s dur=2224ms, vel 33->23, sust 455->2224, freq=165Hz, sample=57
    db 164,1,48,7,45,23,1,3,139,0  ; n1124 t=301.814s dur=1840ms, vel 33->23, sust 528->1840, freq=139Hz, sample=45
    db 254,1,140,5,45,23,1,4,104,0  ; n1125 t=302.234s dur=1420ms, vel 33->23, sust 207->1420, freq=104Hz, sample=45
    db 232,1,142,3,45,23,1,5,139,0  ; n1126 t=302.744s dur=910ms, vel 33->23, sust 579->910, freq=139Hz, sample=45
    db 5,2,105,2,45,23,1,6,104,0  ; n1127 t=303.233s dur=617ms, vel 33->23, freq=104Hz, sample=45
; t 303.6544 Sustain 0 (Instr 1)
; t 303.6544 Sustain 0 (Instr 2)
    db 51,2,143,2,45,25,1,7,82,0  ; n1128 t=303.749s dur=655ms, vel 36->25, freq=82Hz, sample=45
; t 303.8850 Sustain 127 (Instr 1)
; t 303.8850 Sustain 127 (Instr 2)
    db 189,2,235,2,45,23,1,8,104,0  ; n1129 t=304.312s dur=747ms, vel 33->23, freq=104Hz, sample=45
; t 304.3442 Sustain 0 (Instr 1)
; t 304.3442 Sustain 0 (Instr 2)
; t 304.6566 Sustain 127 (Instr 1)
; t 304.6566 Sustain 127 (Instr 2)
    db 100,3,158,3,45,23,1,9,82,0  ; n1130 t=305.014s dur=926ms, vel 33->23, freq=82Hz, sample=45
; t 305.0403 Sustain 0 (Instr 1)
; t 305.0403 Sustain 0 (Instr 2)
; t 305.2614 Sustain 127 (Instr 1)
; t 305.2614 Sustain 127 (Instr 2)
    db 98,10,102,12,33,23,1,10,69,0  ; n1131 t=305.882s dur=3174ms, vel 33->23, sust 1292->3174, freq=69Hz, sample=33
; t 305.8884 Sustain 0 (Instr 1)
; t 305.8884 Sustain 0 (Instr 2)
; t 306.7504 Sustain 127 (Instr 1)
; t 306.7504 Sustain 127 (Instr 2)
    db 5,0,102,12,33,24,1,11,69,0  ; n1132 t=308.540s dur=3174ms, vel 35->24, sust 423->3174, freq=69Hz, sample=33
    db 6,0,102,12,57,25,1,12,21,1  ; n1133 t=308.545s dur=3174ms, vel 36->25, sust 602->3174, freq=277Hz, sample=57
    db 0,0,102,12,45,25,1,13,139,0  ; n1134 t=308.551s dur=3174ms, vel 36->25, sust 497->3174, freq=139Hz, sample=45
    db 5,0,141,16,57,25,1,14,208,0  ; n1135 t=308.551s dur=4237ms, vel 36->25, sust 552->4237, freq=208Hz, sample=57
    db 0,0,141,16,45,25,1,15,104,0  ; n1136 t=308.557s dur=4237ms, vel 36->25, sust 465->4237, freq=104Hz, sample=45
    db 123,12,219,20,57,25,1,16,165,0  ; n1137 t=308.557s dur=5339ms, vel 36->25, sust 528->5339, freq=165Hz, sample=57
    db 5,0,102,12,33,24,1,17,69,0  ; n1138 t=311.752s dur=3174ms, vel 35->24, sust 1070->3174, freq=69Hz, sample=33
    db 12,0,141,16,45,24,1,18,104,0  ; n1139 t=311.757s dur=4237ms, vel 35->24, sust 1113->4237, freq=104Hz, sample=45
    db 0,0,102,12,45,24,1,19,139,0  ; n1140 t=311.769s dur=3174ms, vel 35->24, sust 1127->3174, freq=139Hz, sample=45
    db 1,0,102,12,57,24,1,20,21,1  ; n1141 t=311.769s dur=3174ms, vel 35->24, sust 1220->3174, freq=277Hz, sample=57
    db 0,0,219,20,57,24,1,21,165,0  ; n1142 t=311.770s dur=5339ms, vel 35->24, sust 1174->5339, freq=165Hz, sample=57
    db 165,48,141,16,57,24,1,22,208,0  ; n1143 t=311.770s dur=4237ms, vel 35->24, sust 1189->4237, freq=208Hz, sample=57
; t 321.8300 Sustain 0 (Instr 1)
; t 321.8300 Sustain 0 (Instr 2)
    db 6,0,122,1,69,23,1,23,93,1  ; n1144 t=324.223s dur=378ms, vel 34->23, freq=349Hz, sample=69
    db 11,0,177,0,69,27,2,24,159,1  ; n1145 t=324.229s dur=177ms, vel 39->27, freq=415Hz, sample=69
    db 22,1,10,1,69,27,2,25,42,2  ; n1146 t=324.240s dur=266ms, vel 39->27, freq=554Hz, sample=69
; t 324.2517 Soft 0 (Instr 1)
; t 324.2517 Soft 0 (Instr 2)
    db 5,0,228,1,69,43,2,26,159,1  ; n1147 t=324.518s dur=484ms, freq=415Hz, sample=69
    db 8,0,247,1,69,43,2,27,11,2  ; n1148 t=324.523s dur=503ms, freq=523Hz, sample=69
    db 209,1,246,1,57,38,1,28,55,1  ; n1149 t=324.532s dur=502ms, freq=311Hz, sample=57
; t 324.8680 Soft 127 (Instr 1)
; t 324.8680 Soft 127 (Instr 2)
    db 17,0,69,1,57,23,1,29,21,1  ; n1150 t=324.996s dur=325ms, vel 33->23, freq=277Hz, sample=57
    db 5,0,251,0,69,26,2,30,136,1  ; n1151 t=325.013s dur=251ms, vel 38->26, freq=392Hz, sample=69
    db 244,0,34,1,69,26,2,31,210,1  ; n1152 t=325.019s dur=290ms, vel 38->26, freq=466Hz, sample=69
    db 15,0,128,0,69,28,2,0,159,1  ; n1153 t=325.263s dur=128ms, vel 41->28, freq=415Hz, sample=69
    db 22,0,120,0,57,25,1,1,6,1  ; n1154 t=325.277s dur=120ms, vel 36->25, freq=262Hz, sample=57
    db 204,1,108,0,69,29,2,2,110,2  ; n1155 t=325.300s dur=108ms, vel 42->29, freq=622Hz, sample=69
    db 23,0,109,0,45,23,1,3,139,0  ; n1156 t=325.760s dur=109ms, vel 34->23, freq=139Hz, sample=45
    db 7,0,95,0,69,23,1,4,93,1  ; n1157 t=325.783s dur=95ms, vel 34->23, freq=349Hz, sample=69
    db 11,0,82,0,57,23,1,5,233,0  ; n1158 t=325.791s dur=82ms, vel 34->23, freq=233Hz, sample=57
    db 225,0,107,0,69,28,2,6,42,2  ; n1159 t=325.801s dur=107ms, vel 40->28, freq=554Hz, sample=69
    db 26,0,127,0,69,30,2,7,159,1  ; n1160 t=326.026s dur=127ms, vel 43->30, freq=415Hz, sample=69
    db 12,0,95,0,45,26,1,8,156,0  ; n1161 t=326.053s dur=95ms, vel 38->26, freq=156Hz, sample=45
    db 4,0,95,0,57,26,1,9,55,1  ; n1162 t=326.064s dur=95ms, vel 38->26, freq=311Hz, sample=57
    db 204,1,64,0,69,30,2,10,11,2  ; n1163 t=326.069s dur=64ms, vel 43->30, freq=523Hz, sample=69
    db 1,0,113,0,69,26,2,11,210,1  ; n1164 t=326.529s dur=113ms, vel 38->26, freq=466Hz, sample=69
    db 0,0,101,0,45,24,1,12,156,0  ; n1165 t=326.530s dur=101ms, vel 35->24, freq=156Hz, sample=45
    db 14,0,126,0,69,26,2,13,136,1  ; n1166 t=326.530s dur=126ms, vel 38->26, freq=392Hz, sample=69
    db 235,0,118,0,57,24,1,14,21,1  ; n1167 t=326.544s dur=118ms, vel 35->24, freq=277Hz, sample=57
    db 14,0,165,0,57,23,1,15,208,0  ; n1168 t=326.779s dur=165ms, vel 34->23, freq=208Hz, sample=57
    db 3,0,138,0,57,23,1,16,6,1  ; n1169 t=326.793s dur=138ms, vel 34->23, freq=262Hz, sample=57
    db 238,1,123,0,69,26,2,17,159,1  ; n1170 t=326.796s dur=123ms, vel 38->26, freq=415Hz, sample=69
; t 326.8576 Soft 0 (Instr 1)
; t 326.8576 Soft 0 (Instr 2)
; t 327.2668 Sustain 127 (Instr 1)
; t 327.2668 Sustain 127 (Instr 2)
    db 0,0,70,1,69,40,2,18,42,2  ; n1171 t=327.290s dur=326ms, sust 154->326, freq=554Hz, sample=69
    db 12,0,70,1,69,40,2,19,210,1  ; n1172 t=327.290s dur=326ms, sust 308->326, freq=466Hz, sample=69
    db 2,1,58,1,81,40,2,20,228,2  ; n1173 t=327.302s dur=314ms, sust 260->314, freq=740Hz, sample=81
    db 31,0,13,2,69,43,2,21,159,1  ; n1174 t=327.560s dur=525ms, freq=415Hz, sample=69
    db 0,0,239,1,69,44,2,22,42,2  ; n1175 t=327.590s dur=495ms, freq=554Hz, sample=69
    db 194,1,251,1,81,44,2,23,186,2  ; n1176 t=327.590s dur=507ms, freq=698Hz, sample=81
; t 327.6167 Sustain 0 (Instr 1)
; t 327.6167 Sustain 0 (Instr 2)
    db 17,0,52,1,69,33,1,24,114,1  ; n1177 t=328.040s dur=308ms, freq=370Hz, sample=69
    db 13,0,84,1,69,38,2,25,110,2  ; n1178 t=328.057s dur=340ms, freq=622Hz, sample=69
    db 14,1,204,0,69,38,2,26,11,2  ; n1179 t=328.069s dur=204ms, freq=523Hz, sample=69
; t 328.2179 Soft 127 (Instr 1)
; t 328.2179 Soft 127 (Instr 2)
    db 7,0,82,0,69,29,2,27,42,2  ; n1180 t=328.340s dur=82ms, vel 42->29, freq=554Hz, sample=69
    db 4,0,94,0,69,25,1,28,93,1  ; n1181 t=328.347s dur=94ms, vel 36->25, freq=349Hz, sample=69
    db 221,1,89,0,81,29,2,29,63,3  ; n1182 t=328.351s dur=89ms, vel 42->29, freq=831Hz, sample=81
    db 18,0,134,0,57,23,1,30,185,0  ; n1183 t=328.829s dur=134ms, vel 34->23, freq=185Hz, sample=57
    db 2,0,177,0,81,28,2,31,228,2  ; n1184 t=328.847s dur=177ms, vel 40->28, freq=740Hz, sample=81
    db 3,0,81,0,57,23,1,0,55,1  ; n1185 t=328.849s dur=81ms, vel 34->23, freq=311Hz, sample=57
    db 8,1,147,0,69,28,2,1,210,1  ; n1186 t=328.852s dur=147ms, vel 40->28, freq=466Hz, sample=69
    db 2,0,129,0,69,30,2,2,159,1  ; n1187 t=329.116s dur=129ms, vel 43->30, freq=415Hz, sample=69
    db 11,0,102,0,57,26,1,3,208,0  ; n1188 t=329.118s dur=102ms, vel 38->26, freq=208Hz, sample=57
    db 5,0,72,0,69,30,2,4,42,2  ; n1189 t=329.129s dur=72ms, vel 43->30, freq=554Hz, sample=69
    db 216,1,97,0,81,30,2,5,186,2  ; n1190 t=329.134s dur=97ms, vel 43->30, freq=698Hz, sample=81
    db 4,0,88,0,57,23,1,6,208,0  ; n1191 t=329.606s dur=88ms, vel 34->23, freq=208Hz, sample=57
    db 4,0,114,0,69,23,1,7,114,1  ; n1192 t=329.610s dur=114ms, vel 34->23, freq=370Hz, sample=69
    db 14,0,83,0,69,26,2,8,110,2  ; n1193 t=329.614s dur=83ms, vel 38->26, freq=622Hz, sample=69
    db 232,0,95,0,69,26,2,9,11,2  ; n1194 t=329.628s dur=95ms, vel 38->26, freq=523Hz, sample=69
    db 16,0,218,1,57,25,1,10,21,1  ; n1195 t=329.860s dur=474ms, vel 36->25, sust 138->474, freq=277Hz, sample=57
    db 1,0,203,1,69,26,2,11,42,2  ; n1196 t=329.876s dur=459ms, vel 38->26, sust 132->459, freq=554Hz, sample=69
    db 163,1,201,1,69,25,1,12,93,1  ; n1197 t=329.877s dur=457ms, vel 36->25, sust 94->457, freq=349Hz, sample=69
; t 329.8867 Sustain 127 (Instr 1)
; t 329.8867 Sustain 127 (Instr 2)
    db 14,0,28,1,57,23,1,13,175,0  ; n1198 t=330.296s dur=284ms, vel 34->23, freq=175Hz, sample=57
    db 23,0,133,0,57,23,1,14,208,0  ; n1199 t=330.310s dur=133ms, vel 34->23, freq=208Hz, sample=57
    db 1,0,213,1,69,37,2,15,42,2  ; n1200 t=330.333s dur=469ms, vel 53->37, freq=554Hz, sample=69
    db 224,0,183,1,57,23,1,16,21,1  ; n1201 t=330.334s dur=439ms, vel 34->23, freq=277Hz, sample=57
; t 330.3351 Sustain 0 (Instr 1)
; t 330.3351 Sustain 0 (Instr 2)
; t 330.4347 Soft 0 (Instr 1)
; t 330.4347 Soft 0 (Instr 2)
    db 2,0,210,1,45,37,1,17,156,0  ; n1202 t=330.558s dur=466ms, freq=156Hz, sample=45
    db 230,0,170,1,57,37,1,18,208,0  ; n1203 t=330.560s dur=426ms, freq=208Hz, sample=57
    db 4,0,133,0,57,34,1,19,6,1  ; n1204 t=330.790s dur=133ms, freq=262Hz, sample=57
    db 189,0,188,0,69,47,2,20,11,2  ; n1205 t=330.794s dur=188ms, freq=523Hz, sample=69
    db 7,0,204,0,45,37,1,21,139,0  ; n1206 t=330.983s dur=204ms, freq=139Hz, sample=45
    db 22,0,178,0,57,37,1,22,196,0  ; n1207 t=330.990s dur=178ms, freq=196Hz, sample=57
    db 7,0,3,1,69,50,2,23,210,1  ; n1208 t=331.012s dur=259ms, freq=466Hz, sample=69
    db 189,0,77,0,57,37,1,24,233,0  ; n1209 t=331.020s dur=77ms, freq=233Hz, sample=57
    db 0,0,64,0,45,35,1,25,131,0  ; n1210 t=331.208s dur=64ms, freq=131Hz, sample=45
    db 37,0,76,0,57,35,1,26,6,1  ; n1211 t=331.208s dur=76ms, freq=262Hz, sample=57
    db 202,0,194,0,57,40,1,27,55,1  ; n1212 t=331.245s dur=194ms, freq=311Hz, sample=57
    db 196,0,245,0,69,47,2,28,110,2  ; n1213 t=331.448s dur=245ms, freq=622Hz, sample=69
    db 6,0,138,0,45,37,1,29,139,0  ; n1214 t=331.644s dur=138ms, freq=139Hz, sample=45
    db 29,0,62,0,57,37,1,30,233,0  ; n1215 t=331.650s dur=62ms, freq=233Hz, sample=57
    db 0,0,169,0,69,37,1,31,93,1  ; n1216 t=331.679s dur=169ms, freq=349Hz, sample=69
    db 207,0,18,1,69,50,2,0,42,2  ; n1217 t=331.679s dur=274ms, freq=554Hz, sample=69
    db 12,0,68,0,45,34,1,1,156,0  ; n1218 t=331.886s dur=68ms, freq=156Hz, sample=45
    db 6,0,243,0,69,47,2,2,159,1  ; n1219 t=331.897s dur=243ms, freq=415Hz, sample=69
    db 203,0,75,0,57,34,1,3,55,1  ; n1220 t=331.904s dur=75ms, freq=311Hz, sample=57
    db 177,0,209,0,69,45,2,4,11,2  ; n1221 t=332.107s dur=209ms, freq=523Hz, sample=69
    db 12,0,145,0,57,36,1,5,21,1  ; n1222 t=332.284s dur=145ms, freq=277Hz, sample=57
    db 25,0,160,0,45,36,1,6,156,0  ; n1223 t=332.296s dur=160ms, freq=156Hz, sample=45
    db 12,0,88,2,69,48,2,7,136,1  ; n1224 t=332.321s dur=600ms, sust 346->600, freq=392Hz, sample=69
    db 164,0,77,2,69,48,2,8,210,1  ; n1225 t=332.333s dur=589ms, sust 471->589, freq=466Hz, sample=69
    db 6,0,168,1,57,35,1,9,208,0  ; n1226 t=332.497s dur=424ms, sust 158->424, freq=208Hz, sample=57
    db 225,0,162,1,57,35,1,10,6,1  ; n1227 t=332.503s dur=418ms, sust 116->418, freq=262Hz, sample=57
; t 332.5979 Sustain 127 (Instr 1)
; t 332.5979 Sustain 127 (Instr 2)
    db 221,0,193,0,69,43,2,11,159,1  ; n1228 t=332.728s dur=193ms, sust 149->193, freq=415Hz, sample=69
; t 332.9222 Sustain 0 (Instr 1)
; t 332.9222 Sustain 0 (Instr 2)
    db 0,0,104,0,57,34,1,12,21,1  ; n1229 t=332.950s dur=104ms, freq=277Hz, sample=57
    db 1,0,154,1,81,49,2,13,228,2  ; n1230 t=332.950s dur=410ms, sust 335->410, freq=740Hz, sample=81
    db 0,0,121,0,57,34,1,14,233,0  ; n1231 t=332.951s dur=121ms, freq=233Hz, sample=57
    db 212,0,153,1,69,34,1,15,114,1  ; n1232 t=332.951s dur=409ms, sust 338->409, freq=370Hz, sample=69
    db 8,0,184,1,57,36,1,16,208,0  ; n1233 t=333.163s dur=440ms, freq=208Hz, sample=57
    db 186,0,76,1,57,36,1,17,21,1  ; n1234 t=333.170s dur=332ms, freq=277Hz, sample=57
; t 333.1712 Sustain 127 (Instr 1)
; t 333.1712 Sustain 127 (Instr 2)
    db 6,0,195,0,81,44,2,18,186,2  ; n1235 t=333.357s dur=195ms, freq=698Hz, sample=81
; t 333.3599 Sustain 0 (Instr 1)
; t 333.3599 Sustain 0 (Instr 2)
    db 175,0,119,0,69,33,1,19,93,1  ; n1236 t=333.363s dur=119ms, freq=349Hz, sample=69
    db 19,0,169,0,57,35,1,20,185,0  ; n1237 t=333.538s dur=169ms, freq=185Hz, sample=57
    db 29,0,150,0,57,35,1,21,6,1  ; n1238 t=333.557s dur=150ms, freq=262Hz, sample=57
    db 2,0,213,0,69,47,2,22,110,2  ; n1239 t=333.586s dur=213ms, freq=622Hz, sample=69
    db 164,0,81,0,57,36,1,23,55,1  ; n1240 t=333.588s dur=81ms, freq=311Hz, sample=57
    db 1,0,84,0,69,34,1,24,93,1  ; n1241 t=333.752s dur=84ms, freq=349Hz, sample=69
    db 32,0,78,0,57,34,1,25,175,0  ; n1242 t=333.753s dur=78ms, freq=175Hz, sample=57
    db 194,0,222,0,69,45,2,26,159,1  ; n1243 t=333.785s dur=222ms, freq=415Hz, sample=69
    db 207,0,38,1,81,42,2,27,63,3  ; n1244 t=333.979s dur=294ms, freq=831Hz, sample=81
    db 21,0,127,0,57,35,1,28,185,0  ; n1245 t=334.185s dur=127ms, freq=185Hz, sample=57
    db 15,0,87,0,57,36,1,29,55,1  ; n1246 t=334.207s dur=87ms, freq=311Hz, sample=57
    db 6,0,30,1,81,45,2,30,228,2  ; n1247 t=334.221s dur=286ms, freq=740Hz, sample=81
    db 184,0,204,0,69,45,2,31,210,1  ; n1248 t=334.228s dur=204ms, freq=466Hz, sample=69
    db 10,0,109,0,57,34,1,0,208,0  ; n1249 t=334.412s dur=109ms, freq=208Hz, sample=57
    db 52,0,117,0,69,44,2,1,159,1  ; n1250 t=334.422s dur=117ms, freq=415Hz, sample=69
    db 174,0,231,0,69,43,2,2,42,2  ; n1251 t=334.474s dur=231ms, freq=554Hz, sample=69
    db 193,0,1,1,81,42,2,3,186,2  ; n1252 t=334.647s dur=257ms, freq=698Hz, sample=81
    db 26,0,212,0,69,33,1,4,114,1  ; n1253 t=334.840s dur=212ms, freq=370Hz, sample=69
    db 22,0,212,0,57,33,1,5,208,0  ; n1254 t=334.866s dur=212ms, freq=208Hz, sample=57
    db 31,0,182,0,69,46,2,6,11,2  ; n1255 t=334.889s dur=182ms, freq=523Hz, sample=69
    db 145,0,241,1,69,46,2,7,110,2  ; n1256 t=334.920s dur=497ms, sust 426->497, freq=622Hz, sample=69
    db 5,0,96,1,57,33,1,8,21,1  ; n1257 t=335.065s dur=352ms, sust 320->352, freq=277Hz, sample=57
    db 212,0,91,1,69,33,1,9,93,1  ; n1258 t=335.070s dur=347ms, sust 257->347, freq=349Hz, sample=69
    db 227,0,207,0,69,43,2,10,42,2  ; n1259 t=335.282s dur=207ms, freq=554Hz, sample=69
; t 335.2903 Sustain 127 (Instr 1)
; t 335.2903 Sustain 127 (Instr 2)
; t 335.4174 Sustain 0 (Instr 1)
; t 335.4174 Sustain 0 (Instr 2)
    db 16,0,79,1,57,36,1,11,21,1  ; n1260 t=335.509s dur=335ms, freq=277Hz, sample=57
    db 1,0,178,0,69,46,2,12,42,2  ; n1261 t=335.524s dur=178ms, freq=554Hz, sample=69
    db 236,0,156,0,69,36,1,13,93,1  ; n1262 t=335.526s dur=156ms, sust 88->156, freq=349Hz, sample=69
; t 335.5276 Sustain 127 (Instr 1)
; t 335.5276 Sustain 127 (Instr 2)
; t 335.6823 Sustain 0 (Instr 1)
; t 335.6823 Sustain 0 (Instr 2)
    db 61,0,34,2,57,40,1,14,233,0  ; n1263 t=335.762s dur=546ms, sust 495->546, freq=233Hz, sample=57
    db 7,0,229,1,69,56,2,15,42,2  ; n1264 t=335.823s dur=485ms, sust 284->485, freq=554Hz, sample=69
    db 138,1,221,1,69,40,1,16,93,1  ; n1265 t=335.831s dur=477ms, sust 194->477, freq=349Hz, sample=69
; t 335.8635 Sustain 127 (Instr 1)
; t 335.8635 Sustain 127 (Instr 2)
    db 60,0,39,1,57,34,1,17,208,0  ; n1266 t=336.225s dur=295ms, freq=208Hz, sample=57
    db 9,0,134,0,69,53,2,18,42,2  ; n1267 t=336.285s dur=134ms, freq=554Hz, sample=69
    db 162,0,82,0,69,35,1,19,93,1  ; n1268 t=336.294s dur=82ms, freq=349Hz, sample=69
; t 336.3084 Sustain 0 (Instr 1)
; t 336.3084 Sustain 0 (Instr 2)
    db 42,0,186,1,57,37,1,20,196,0  ; n1269 t=336.456s dur=442ms, sust 346->442, freq=196Hz, sample=57
    db 9,0,232,0,69,55,2,21,42,2  ; n1270 t=336.498s dur=232ms, freq=554Hz, sample=69
    db 5,1,187,0,57,37,1,22,55,1  ; n1271 t=336.507s dur=187ms, freq=311Hz, sample=57
; t 336.7618 Sustain 127 (Instr 1)
; t 336.7618 Sustain 127 (Instr 2)
    db 17,0,165,0,57,34,1,23,208,0  ; n1272 t=336.767s dur=165ms, freq=208Hz, sample=57
    db 8,0,119,0,69,52,2,24,11,2  ; n1273 t=336.784s dur=119ms, freq=523Hz, sample=69
    db 177,0,107,0,57,33,1,25,55,1  ; n1274 t=336.793s dur=107ms, freq=311Hz, sample=57
; t 336.8985 Sustain 0 (Instr 1)
; t 336.8985 Sustain 0 (Instr 2)
    db 22,0,33,1,69,50,2,26,238,1  ; n1275 t=336.969s dur=289ms, sust 251->289, freq=494Hz, sample=69
    db 5,0,10,1,57,33,1,27,208,0  ; n1276 t=336.992s dur=266ms, sust 188->266, freq=208Hz, sample=57
    db 17,1,5,1,57,34,1,28,55,1  ; n1277 t=336.997s dur=261ms, sust 201->261, freq=311Hz, sample=57
; t 337.0659 Sustain 127 (Instr 1)
; t 337.0659 Sustain 127 (Instr 2)
; t 337.2587 Sustain 0 (Instr 1)
; t 337.2587 Sustain 0 (Instr 2)
    db 41,0,87,2,57,37,1,29,208,0  ; n1278 t=337.270s dur=599ms, sust 476->599, freq=208Hz, sample=57
    db 9,0,46,2,69,54,2,30,238,1  ; n1279 t=337.312s dur=558ms, sust 356->558, freq=494Hz, sample=69
    db 176,1,82,0,57,37,1,31,55,1  ; n1280 t=337.320s dur=82ms, freq=311Hz, sample=57
; t 337.4452 Sustain 127 (Instr 1)
; t 337.4452 Sustain 127 (Instr 2)
    db 2,0,195,0,69,51,2,0,238,1  ; n1281 t=337.752s dur=195ms, freq=494Hz, sample=69
    db 13,0,115,0,57,34,1,1,55,1  ; n1282 t=337.754s dur=115ms, sust 76->115, freq=311Hz, sample=57
    db 150,0,177,0,57,34,1,2,185,0  ; n1283 t=337.767s dur=177ms, freq=185Hz, sample=57
; t 337.8699 Sustain 0 (Instr 1)
; t 337.8699 Sustain 0 (Instr 2)
    db 24,0,95,1,57,36,1,3,175,0  ; n1284 t=337.918s dur=351ms, freq=175Hz, sample=57
    db 60,0,71,1,57,37,1,4,21,1  ; n1285 t=337.942s dur=327ms, sust 238->327, freq=277Hz, sample=57
    db 209,0,10,1,69,54,2,5,238,1  ; n1286 t=338.002s dur=266ms, sust 196->266, freq=494Hz, sample=69
; t 338.0563 Sustain 127 (Instr 1)
; t 338.0563 Sustain 127 (Instr 2)
    db 18,0,138,0,57,35,1,6,185,0  ; n1287 t=338.211s dur=138ms, freq=185Hz, sample=57
    db 8,0,176,0,69,51,2,7,210,1  ; n1288 t=338.229s dur=176ms, freq=466Hz, sample=69
    db 210,0,130,0,57,34,1,8,21,1  ; n1289 t=338.237s dur=130ms, freq=277Hz, sample=57
; t 338.2691 Sustain 0 (Instr 1)
; t 338.2691 Sustain 0 (Instr 2)
    db 43,0,27,1,57,33,1,9,185,0  ; n1290 t=338.447s dur=283ms, freq=185Hz, sample=57
    db 21,0,14,1,69,48,2,10,210,1  ; n1291 t=338.490s dur=270ms, freq=466Hz, sample=69
; t 338.5095 Sustain 127 (Instr 1)
; t 338.5095 Sustain 127 (Instr 2)
    db 203,0,216,0,57,33,1,11,21,1  ; n1292 t=338.512s dur=216ms, sust 100->216, freq=277Hz, sample=57
    db 18,0,163,2,45,36,1,12,156,0  ; n1293 t=338.715s dur=675ms, sust 386->675, freq=156Hz, sample=45
; t 338.7277 Sustain 0 (Instr 1)
; t 338.7277 Sustain 0 (Instr 2)
    db 60,0,145,2,57,36,1,13,208,0  ; n1294 t=338.733s dur=657ms, sust 425->657, freq=208Hz, sample=57
    db 14,0,85,2,69,52,2,14,11,2  ; n1295 t=338.793s dur=597ms, sust 332->597, freq=523Hz, sample=69
    db 52,2,71,2,69,37,1,15,114,1  ; n1296 t=338.807s dur=583ms, sust 292->583, freq=370Hz, sample=69
; t 338.9384 Sustain 127 (Instr 1)
; t 338.9384 Sustain 127 (Instr 2)
    db 5,0,204,1,69,52,2,16,42,2  ; n1297 t=339.372s dur=460ms, freq=554Hz, sample=69
    db 1,0,8,1,69,36,1,17,93,1  ; n1298 t=339.377s dur=264ms, freq=349Hz, sample=69
    db 6,0,196,1,45,36,1,18,139,0  ; n1299 t=339.378s dur=452ms, freq=139Hz, sample=45
    db 129,1,53,1,57,36,1,19,208,0  ; n1300 t=339.384s dur=309ms, freq=208Hz, sample=57
; t 339.3906 Sustain 0 (Instr 1)
; t 339.3906 Sustain 0 (Instr 2)
    db 40,0,186,5,45,42,1,20,131,0  ; n1301 t=339.770s dur=1466ms, freq=131Hz, sample=45
    db 16,0,25,5,57,47,1,21,208,0  ; n1302 t=339.810s dur=1305ms, sust 1271->1305, freq=208Hz, sample=57
    db 1,0,9,5,69,61,2,22,110,2  ; n1303 t=339.826s dur=1289ms, sust 719->1289, freq=622Hz, sample=69
    db 104,4,8,5,69,50,1,23,114,1  ; n1304 t=339.827s dur=1288ms, sust 793->1288, freq=370Hz, sample=69
; t 340.2844 Sustain 127 (Instr 1)
; t 340.2844 Sustain 127 (Instr 2)
; t 340.9261 Soft 127 (Instr 1)
; t 340.9261 Soft 127 (Instr 2)
    db 6,0,141,2,69,25,1,24,114,1  ; n1305 t=340.955s dur=653ms, vel 37->25, freq=370Hz, sample=69
    db 9,1,129,2,57,25,1,25,55,1  ; n1306 t=340.961s dur=641ms, vel 37->25, freq=311Hz, sample=57
; t 341.1157 Sustain 0 (Instr 1)
; t 341.1157 Sustain 0 (Instr 2)
    db 6,0,97,2,45,23,1,26,139,0  ; n1307 t=341.226s dur=609ms, vel 34->23, freq=139Hz, sample=45
    db 44,1,177,1,57,23,1,27,208,0  ; n1308 t=341.232s dur=433ms, vel 34->23, freq=208Hz, sample=57
    db 61,0,153,0,57,23,1,28,21,1  ; n1309 t=341.532s dur=153ms, vel 33->23, freq=277Hz, sample=57
    db 220,0,108,1,69,27,1,29,93,1  ; n1310 t=341.593s dur=364ms, vel 39->27, freq=349Hz, sample=69
    db 107,0,165,1,45,24,1,30,92,0  ; n1311 t=341.813s dur=421ms, vel 35->24, freq=92Hz, sample=45
    db 12,0,116,1,57,25,1,31,185,0  ; n1312 t=341.920s dur=372ms, vel 36->25, freq=185Hz, sample=57
    db 93,0,204,1,57,25,1,0,233,0  ; n1313 t=341.932s dur=460ms, vel 37->25, freq=233Hz, sample=57
    db 207,0,235,0,69,31,2,1,210,1  ; n1314 t=342.025s dur=235ms, vel 45->31, freq=466Hz, sample=69
    db 14,0,152,0,69,23,1,2,114,1  ; n1315 t=342.233s dur=152ms, vel 34->23, freq=370Hz, sample=69
    db 161,0,211,1,45,23,1,3,156,0  ; n1316 t=342.246s dur=467ms, vel 34->23, sust 234->467, freq=156Hz, sample=45
    db 19,0,57,1,45,23,1,4,104,0  ; n1317 t=342.407s dur=313ms, vel 34->23, freq=104Hz, sample=45
    db 25,0,77,1,57,24,1,5,208,0  ; n1318 t=342.426s dur=333ms, vel 35->24, freq=208Hz, sample=57
    db 7,0,43,1,69,28,1,6,93,1  ; n1319 t=342.452s dur=299ms, vel 40->28, freq=349Hz, sample=69
    db 6,1,255,0,57,28,1,7,21,1  ; n1320 t=342.459s dur=255ms, vel 41->28, sust 244->255, freq=277Hz, sample=57
; t 342.4719 Sustain 127 (Instr 1)
; t 342.4719 Sustain 127 (Instr 2)
; t 342.7143 Sustain 0 (Instr 1)
; t 342.7143 Sustain 0 (Instr 2)
    db 11,0,87,0,57,27,1,8,6,1  ; n1321 t=342.721s dur=87ms, vel 39->27, freq=262Hz, sample=57
    db 199,0,72,0,57,27,1,9,55,1  ; n1322 t=342.731s dur=72ms, vel 39->27, freq=311Hz, sample=57
    db 1,0,152,0,57,29,1,10,208,0  ; n1323 t=342.930s dur=152ms, vel 42->29, freq=208Hz, sample=57
    db 44,0,144,0,57,29,1,11,175,0  ; n1324 t=342.931s dur=144ms, vel 42->29, freq=175Hz, sample=57
    db 10,0,224,0,57,29,1,12,21,1  ; n1325 t=342.976s dur=224ms, vel 42->29, freq=277Hz, sample=57
    db 187,0,131,0,69,33,2,13,42,2  ; n1326 t=342.985s dur=131ms, vel 48->33, freq=554Hz, sample=69
    db 5,0,239,1,45,31,1,14,156,0  ; n1327 t=343.173s dur=495ms, vel 45->31, sust 466->495, freq=156Hz, sample=45
    db 60,0,234,1,57,31,1,15,208,0  ; n1328 t=343.178s dur=490ms, vel 45->31, sust 437->490, freq=208Hz, sample=57
    db 2,0,173,1,69,38,2,16,11,2  ; n1329 t=343.238s dur=429ms, vel 55->38, sust 349->429, freq=523Hz, sample=69
    db 146,1,171,1,57,30,1,17,6,1  ; n1330 t=343.240s dur=427ms, vel 44->30, sust 343->427, freq=262Hz, sample=57
; t 343.3865 Sustain 127 (Instr 1)
; t 343.3865 Sustain 127 (Instr 2)
    db 13,0,16,1,57,27,1,18,196,0  ; n1331 t=343.643s dur=272ms, vel 39->27, freq=196Hz, sample=57
    db 23,0,221,0,45,28,1,19,139,0  ; n1332 t=343.655s dur=221ms, vel 40->28, freq=139Hz, sample=45
; t 343.6680 Sustain 0 (Instr 1)
; t 343.6680 Sustain 0 (Instr 2)
    db 13,0,47,1,69,35,2,20,210,1  ; n1333 t=343.679s dur=303ms, vel 50->35, freq=466Hz, sample=69
    db 240,0,72,0,57,28,1,21,233,0  ; n1334 t=343.691s dur=72ms, vel 40->28, freq=233Hz, sample=57
    db 12,0,75,0,45,28,1,22,131,0  ; n1335 t=343.932s dur=75ms, vel 41->28, freq=131Hz, sample=45
    db 12,0,101,0,57,28,1,23,6,1  ; n1336 t=343.943s dur=101ms, vel 41->28, freq=262Hz, sample=57
    db 10,0,101,0,57,28,1,24,55,1  ; n1337 t=343.955s dur=101ms, vel 41->28, freq=311Hz, sample=57
    db 160,1,90,0,69,37,2,25,110,2  ; n1338 t=343.964s dur=90ms, vel 53->37, freq=622Hz, sample=69
    db 18,0,113,0,45,28,1,26,139,0  ; n1339 t=344.380s dur=113ms, vel 41->28, freq=139Hz, sample=45
    db 18,0,76,0,57,29,1,27,233,0  ; n1340 t=344.399s dur=76ms, vel 42->29, freq=233Hz, sample=57
    db 5,0,6,1,69,29,1,28,93,1  ; n1341 t=344.416s dur=262ms, vel 42->29, freq=349Hz, sample=69
    db 200,0,119,1,69,38,2,29,42,2  ; n1342 t=344.422s dur=375ms, vel 55->38, freq=554Hz, sample=69
    db 14,0,109,0,45,31,1,30,156,0  ; n1343 t=344.622s dur=109ms, vel 45->31, freq=156Hz, sample=45
    db 11,0,83,0,57,31,1,31,55,1  ; n1344 t=344.636s dur=83ms, vel 45->31, freq=311Hz, sample=57
    db 193,0,213,0,69,36,2,0,159,1  ; n1345 t=344.646s dur=213ms, vel 52->36, freq=415Hz, sample=69
    db 187,0,211,0,69,35,2,1,11,2  ; n1346 t=344.839s dur=211ms, vel 50->35, freq=523Hz, sample=69
    db 22,0,130,0,57,28,1,2,21,1  ; n1347 t=345.026s dur=130ms, vel 40->28, freq=277Hz, sample=57
    db 18,0,102,0,45,28,1,3,156,0  ; n1348 t=345.048s dur=102ms, vel 41->28, freq=156Hz, sample=45
    db 7,0,64,2,69,37,2,4,210,1  ; n1349 t=345.066s dur=576ms, vel 53->37, sust 441->576, freq=466Hz, sample=69
    db 161,0,57,2,69,37,2,5,136,1  ; n1350 t=345.074s dur=569ms, vel 54->37, sust 258->569, freq=392Hz, sample=69
    db 6,0,152,1,57,29,1,6,208,0  ; n1351 t=345.235s dur=408ms, vel 42->29, sust 131->408, freq=208Hz, sample=57
    db 206,0,146,1,57,29,1,7,6,1  ; n1352 t=345.241s dur=402ms, vel 42->29, sust 111->402, freq=262Hz, sample=57
; t 345.3321 Sustain 127 (Instr 1)
; t 345.3321 Sustain 127 (Instr 2)
    db 190,0,195,0,69,34,2,8,159,1  ; n1353 t=345.447s dur=195ms, vel 49->34, sust 140->195, freq=415Hz, sample=69
; t 345.4696 Soft 0 (Instr 1)
; t 345.4696 Soft 0 (Instr 2)
    db 6,0,232,0,57,40,1,9,233,0  ; n1354 t=345.638s dur=232ms, freq=233Hz, sample=57
; t 345.6432 Sustain 0 (Instr 1)
; t 345.6432 Sustain 0 (Instr 2)
    db 10,0,132,0,57,40,1,10,21,1  ; n1355 t=345.644s dur=132ms, freq=277Hz, sample=57
    db 1,0,184,0,81,50,2,11,228,2  ; n1356 t=345.654s dur=184ms, freq=740Hz, sample=81
    db 215,0,189,0,69,40,1,12,114,1  ; n1357 t=345.655s dur=189ms, freq=370Hz, sample=69
    db 0,0,93,1,57,43,1,13,21,1  ; n1358 t=345.870s dur=349ms, sust 344->349, freq=277Hz, sample=57
    db 11,0,195,1,57,43,1,14,208,0  ; n1359 t=345.870s dur=451ms, freq=208Hz, sample=57
    db 19,0,95,1,81,53,2,15,186,2  ; n1360 t=345.880s dur=351ms, freq=698Hz, sample=81
    db 121,1,63,1,69,44,1,16,93,1  ; n1361 t=345.899s dur=319ms, sust 295->319, freq=349Hz, sample=69
; t 345.9691 Sustain 127 (Instr 1)
; t 345.9691 Sustain 127 (Instr 2)
; t 346.2188 Sustain 0 (Instr 1)
; t 346.2188 Sustain 0 (Instr 2)
    db 13,0,208,0,57,44,1,17,185,0  ; n1362 t=346.276s dur=208ms, freq=185Hz, sample=57
    db 9,0,112,0,57,45,1,18,6,1  ; n1363 t=346.289s dur=112ms, freq=262Hz, sample=57
    db 10,0,165,0,69,48,2,19,110,2  ; n1364 t=346.297s dur=165ms, freq=622Hz, sample=69
    db 162,0,100,0,57,45,1,20,55,1  ; n1365 t=346.307s dur=100ms, freq=311Hz, sample=57
    db 19,0,193,1,57,46,1,21,175,0  ; n1366 t=346.469s dur=449ms, sust 164->449, freq=175Hz, sample=57
    db 18,0,174,1,57,46,1,22,21,1  ; n1367 t=346.488s dur=430ms, sust 196->430, freq=277Hz, sample=57
    db 0,0,156,1,69,58,2,23,159,1  ; n1368 t=346.506s dur=412ms, sust 196->412, freq=415Hz, sample=69
    db 161,1,156,1,81,58,2,24,63,3  ; n1369 t=346.506s dur=412ms, sust 215->412, freq=831Hz, sample=81
; t 346.5944 Sustain 127 (Instr 1)
; t 346.5944 Sustain 127 (Instr 2)
; t 346.9182 Sustain 0 (Instr 1)
; t 346.9182 Sustain 0 (Instr 2)
    db 7,0,220,1,81,58,2,25,228,2  ; n1370 t=346.923s dur=476ms, sust 323->476, freq=740Hz, sample=81
    db 1,0,212,1,69,48,1,26,114,1  ; n1371 t=346.930s dur=468ms, sust 304->468, freq=370Hz, sample=69
    db 5,0,101,0,57,49,1,27,21,1  ; n1372 t=346.931s dur=101ms, freq=277Hz, sample=57
    db 192,0,145,0,57,49,1,28,233,0  ; n1373 t=346.936s dur=145ms, freq=233Hz, sample=57
    db 1,0,36,1,57,51,1,29,21,1  ; n1374 t=347.128s dur=292ms, freq=277Hz, sample=57
    db 182,0,139,1,57,51,1,30,208,0  ; n1375 t=347.129s dur=395ms, freq=208Hz, sample=57
; t 347.1457 Sustain 127 (Instr 1)
; t 347.1457 Sustain 127 (Instr 2)
    db 14,0,125,0,81,63,2,31,186,2  ; n1376 t=347.311s dur=125ms, freq=698Hz, sample=81
    db 161,0,94,0,69,49,1,0,93,1  ; n1377 t=347.325s dur=94ms, freq=349Hz, sample=69
; t 347.3986 Sustain 0 (Instr 1)
; t 347.3986 Sustain 0 (Instr 2)
    db 13,0,189,0,57,51,1,1,185,0  ; n1378 t=347.485s dur=189ms, freq=185Hz, sample=57
    db 8,0,89,0,57,51,1,2,6,1  ; n1379 t=347.498s dur=89ms, freq=262Hz, sample=57
    db 28,0,165,0,69,61,2,3,110,2  ; n1380 t=347.507s dur=165ms, freq=622Hz, sample=69
    db 99,0,109,0,57,52,1,4,55,1  ; n1381 t=347.534s dur=109ms, freq=311Hz, sample=57
    db 65,0,209,1,57,53,1,5,175,0  ; n1382 t=347.634s dur=465ms, sust 218->465, freq=175Hz, sample=57
    db 47,0,145,1,57,54,1,6,21,1  ; n1383 t=347.698s dur=401ms, sust 240->401, freq=277Hz, sample=57
    db 7,0,98,1,81,70,2,7,63,3  ; n1384 t=347.745s dur=354ms, sust 273->354, freq=831Hz, sample=81
    db 138,1,91,1,69,70,2,8,159,1  ; n1385 t=347.752s dur=347ms, sust 254->347, freq=415Hz, sample=69
; t 347.8060 Sustain 127 (Instr 1)
; t 347.8060 Sustain 127 (Instr 2)
; t 348.0991 Sustain 0 (Instr 1)
; t 348.0991 Sustain 0 (Instr 2)
    db 9,0,28,1,81,70,2,9,228,2  ; n1386 t=348.146s dur=284ms, freq=740Hz, sample=81
    db 1,0,0,1,69,53,1,10,114,1  ; n1387 t=348.154s dur=256ms, freq=370Hz, sample=69
    db 5,0,124,0,57,53,1,11,233,0  ; n1388 t=348.155s dur=124ms, freq=233Hz, sample=57
    db 161,0,88,0,57,54,1,12,21,1  ; n1389 t=348.161s dur=88ms, freq=277Hz, sample=57
    db 6,0,249,1,57,56,1,13,208,0  ; n1390 t=348.321s dur=505ms, sust 351->505, freq=208Hz, sample=57
    db 173,0,243,1,57,56,1,14,21,1  ; n1391 t=348.328s dur=499ms, sust 239->499, freq=277Hz, sample=57
; t 348.4695 Sustain 127 (Instr 1)
; t 348.4695 Sustain 127 (Instr 2)
    db 5,0,69,1,81,66,2,15,186,2  ; n1392 t=348.501s dur=325ms, sust 239->325, freq=698Hz, sample=81
    db 108,0,64,1,69,58,1,16,93,1  ; n1393 t=348.507s dur=320ms, sust 172->320, freq=349Hz, sample=69
    db 69,0,32,3,57,65,1,17,196,0  ; n1394 t=348.615s dur=800ms, freq=196Hz, sample=57
    db 32,0,45,2,57,65,1,18,21,1  ; n1395 t=348.683s dur=557ms, freq=277Hz, sample=57
    db 103,0,32,2,69,65,1,19,74,1  ; n1396 t=348.715s dur=544ms, freq=330Hz, sample=69
    db 7,0,13,5,81,70,2,20,164,3  ; n1397 t=348.818s dur=1293ms, freq=932Hz, sample=81
    db 113,2,107,4,69,70,2,21,210,1  ; n1398 t=348.825s dur=1131ms, freq=466Hz, sample=69
; t 348.8271 Sustain 0 (Instr 1)
; t 348.8271 Sustain 0 (Instr 2)
; t 349.2355 Soft 127 (Instr 1)
; t 349.2355 Soft 127 (Instr 2)
    db 4,0,251,3,57,32,1,22,208,0  ; n1399 t=349.450s dur=1019ms, vel 46->32, freq=208Hz, sample=57
    db 13,0,208,3,57,32,1,23,21,1  ; n1400 t=349.454s dur=976ms, vel 46->32, freq=277Hz, sample=57
    db 98,2,114,3,69,31,1,24,93,1  ; n1401 t=349.467s dur=882ms, vel 45->31, freq=349Hz, sample=69
    db 1,0,69,1,81,37,2,25,63,3  ; n1402 t=350.077s dur=325ms, vel 53->37, freq=831Hz, sample=81
    db 112,3,63,1,69,37,2,26,159,1  ; n1403 t=350.079s dur=319ms, vel 53->37, freq=415Hz, sample=69
    db 54,0,187,4,33,24,1,27,52,0  ; n1404 t=350.959s dur=1211ms, vel 35->24, freq=52Hz, sample=33
    db 125,0,106,4,45,24,1,28,104,0  ; n1405 t=351.012s dur=1130ms, vel 35->24, freq=104Hz, sample=45
    db 25,0,244,3,57,25,1,29,185,0  ; n1406 t=351.137s dur=1012ms, vel 37->25, freq=185Hz, sample=57
    db 254,2,24,3,57,25,1,30,6,1  ; n1407 t=351.163s dur=792ms, vel 37->25, freq=262Hz, sample=57
    db 187,0,208,0,57,25,1,31,55,1  ; n1408 t=351.928s dur=208ms, vel 37->25, freq=311Hz, sample=57
    db 144,0,225,0,57,24,1,0,21,1  ; n1409 t=352.116s dur=225ms, vel 35->24, freq=277Hz, sample=57
    db 36,0,182,2,33,23,1,1,69,0  ; n1410 t=352.260s dur=694ms, vel 33->23, sust 414->694, freq=69Hz, sample=33
    db 112,0,146,2,45,23,1,2,104,0  ; n1411 t=352.296s dur=658ms, vel 34->23, sust 389->658, freq=104Hz, sample=45
    db 6,0,34,2,57,24,1,3,21,1  ; n1412 t=352.408s dur=546ms, vel 35->24, sust 313->546, freq=277Hz, sample=57
    db 163,3,28,2,57,24,1,4,175,0  ; n1413 t=352.414s dur=540ms, vel 35->24, sust 257->540, freq=175Hz, sample=57
; t 352.4647 Sustain 127 (Instr 1)
; t 352.4647 Sustain 127 (Instr 2)
; t 352.5663 Soft 0 (Instr 1)
; t 352.5663 Soft 0 (Instr 2)
; t 352.9544 Sustain 0 (Instr 1)
; t 352.9544 Sustain 0 (Instr 2)
    db 10,0,52,3,57,33,1,5,21,1  ; n1414 t=353.345s dur=820ms, sust 425->820, freq=277Hz, sample=57
    db 26,0,42,3,69,44,2,6,42,2  ; n1415 t=353.354s dur=810ms, sust 252->810, freq=554Hz, sample=69
; t 353.3668 Sustain 127 (Instr 1)
; t 353.3668 Sustain 127 (Instr 2)
    db 38,1,16,3,69,33,1,7,93,1  ; n1416 t=353.380s dur=784ms, sust 138->784, freq=349Hz, sample=69
    db 11,0,249,1,57,37,1,8,233,0  ; n1417 t=353.674s dur=505ms, freq=233Hz, sample=57
    db 1,0,224,1,69,48,2,9,42,2  ; n1418 t=353.685s dur=480ms, sust 271->480, freq=554Hz, sample=69
    db 211,1,222,1,69,37,1,10,93,1  ; n1419 t=353.686s dur=478ms, sust 100->478, freq=349Hz, sample=69
    db 11,0,2,1,57,36,1,11,208,0  ; n1420 t=354.153s dur=258ms, freq=208Hz, sample=57
    db 7,0,181,0,69,43,2,12,42,2  ; n1421 t=354.164s dur=181ms, freq=554Hz, sample=69
; t 354.1650 Sustain 0 (Instr 1)
; t 354.1650 Sustain 0 (Instr 2)
    db 206,0,106,0,69,37,1,13,93,1  ; n1422 t=354.171s dur=106ms, freq=349Hz, sample=69
    db 41,0,57,1,57,39,1,14,196,0  ; n1423 t=354.377s dur=313ms, freq=196Hz, sample=57
    db 8,0,218,0,69,47,2,15,42,2  ; n1424 t=354.419s dur=218ms, freq=554Hz, sample=69
    db 229,0,125,0,57,40,1,16,55,1  ; n1425 t=354.427s dur=125ms, freq=311Hz, sample=57
    db 23,0,158,0,57,37,1,17,208,0  ; n1426 t=354.657s dur=158ms, freq=208Hz, sample=57
    db 2,0,101,0,69,44,2,18,11,2  ; n1427 t=354.680s dur=101ms, freq=523Hz, sample=69
    db 220,0,144,0,57,37,1,19,55,1  ; n1428 t=354.682s dur=144ms, freq=311Hz, sample=57
; t 354.8777 Sustain 127 (Instr 1)
; t 354.8777 Sustain 127 (Instr 2)
    db 8,0,55,3,69,41,2,20,238,1  ; n1429 t=354.902s dur=823ms, sust 171->823, freq=494Hz, sample=69
    db 19,0,47,3,57,34,1,21,208,0  ; n1430 t=354.910s dur=815ms, sust 146->815, freq=208Hz, sample=57
    db 249,0,28,3,57,34,1,22,55,1  ; n1431 t=354.930s dur=796ms, sust 113->796, freq=311Hz, sample=57
    db 4,0,34,2,57,37,1,23,208,0  ; n1432 t=355.179s dur=546ms, sust 461->546, freq=208Hz, sample=57
    db 10,0,30,2,69,45,2,24,238,1  ; n1433 t=355.183s dur=542ms, sust 348->542, freq=494Hz, sample=69
    db 171,1,20,2,57,37,1,25,55,1  ; n1434 t=355.193s dur=532ms, sust 329->532, freq=311Hz, sample=57
    db 10,0,222,0,57,33,1,26,185,0  ; n1435 t=355.620s dur=222ms, freq=185Hz, sample=57
    db 16,0,190,0,69,40,2,27,238,1  ; n1436 t=355.629s dur=190ms, freq=494Hz, sample=69
    db 156,0,80,0,57,34,1,28,55,1  ; n1437 t=355.645s dur=80ms, sust 63->80, freq=311Hz, sample=57
; t 355.7256 Sustain 0 (Instr 1)
; t 355.7256 Sustain 0 (Instr 2)
    db 5,0,7,1,57,36,1,29,21,1  ; n1438 t=355.802s dur=263ms, freq=277Hz, sample=57
    db 72,0,59,1,57,36,1,30,175,0  ; n1439 t=355.807s dur=315ms, freq=175Hz, sample=57
    db 190,0,177,0,69,43,2,31,238,1  ; n1440 t=355.879s dur=177ms, freq=494Hz, sample=69
    db 42,0,164,0,57,34,1,0,185,0  ; n1441 t=356.069s dur=164ms, freq=185Hz, sample=57
    db 1,0,164,0,69,42,2,1,210,1  ; n1442 t=356.111s dur=164ms, freq=466Hz, sample=69
    db 182,0,144,0,57,34,1,2,21,1  ; n1443 t=356.113s dur=144ms, freq=277Hz, sample=57
    db 54,0,2,1,57,33,1,3,185,0  ; n1444 t=356.294s dur=258ms, freq=185Hz, sample=57
    db 2,0,20,1,69,45,2,4,210,1  ; n1445 t=356.348s dur=276ms, freq=466Hz, sample=69
    db 181,0,100,0,57,34,1,5,21,1  ; n1446 t=356.351s dur=100ms, freq=277Hz, sample=57
    db 23,0,175,2,45,36,1,6,156,0  ; n1447 t=356.531s dur=687ms, sust 410->687, freq=156Hz, sample=45
    db 97,0,151,2,57,37,1,7,208,0  ; n1448 t=356.555s dur=663ms, sust 443->663, freq=208Hz, sample=57
    db 21,0,54,2,69,49,2,8,11,2  ; n1449 t=356.652s dur=566ms, sust 288->566, freq=523Hz, sample=69
    db 239,1,33,2,69,38,1,9,114,1  ; n1450 t=356.673s dur=545ms, sust 244->545, freq=370Hz, sample=69
; t 356.7533 Sustain 127 (Instr 1)
; t 356.7533 Sustain 127 (Instr 2)
    db 3,0,193,1,69,51,2,10,42,2  ; n1451 t=357.168s dur=449ms, freq=554Hz, sample=69
    db 19,0,186,1,45,38,1,11,139,0  ; n1452 t=357.171s dur=442ms, freq=139Hz, sample=45
    db 4,0,7,1,57,39,1,12,208,0  ; n1453 t=357.190s dur=263ms, freq=208Hz, sample=57
    db 125,1,232,0,69,39,1,13,93,1  ; n1454 t=357.194s dur=232ms, freq=349Hz, sample=69
; t 357.2183 Sustain 0 (Instr 1)
; t 357.2183 Sustain 0 (Instr 2)
    db 36,0,253,5,45,44,1,14,131,0  ; n1455 t=357.575s dur=1533ms, freq=131Hz, sample=45
    db 24,0,250,4,57,44,1,15,208,0  ; n1456 t=357.611s dur=1274ms, freq=208Hz, sample=57
    db 3,0,216,4,69,45,1,16,114,1  ; n1457 t=357.636s dur=1240ms, sust 741->1240, freq=370Hz, sample=69
    db 48,4,213,4,69,64,2,17,110,2  ; n1458 t=357.639s dur=1237ms, sust 686->1237, freq=622Hz, sample=69
; t 358.1388 Sustain 127 (Instr 1)
; t 358.1388 Sustain 127 (Instr 2)
    db 6,0,225,2,69,37,1,18,114,1  ; n1459 t=358.711s dur=737ms, freq=370Hz, sample=69
    db 109,1,246,2,57,38,1,19,55,1  ; n1460 t=358.717s dur=758ms, freq=311Hz, sample=57
; t 358.8765 Sustain 0 (Instr 1)
; t 358.8765 Sustain 0 (Instr 2)
; t 358.9473 Soft 127 (Instr 1)
; t 358.9473 Soft 127 (Instr 2)
    db 18,0,143,2,45,23,1,20,139,0  ; n1461 t=359.082s dur=655ms, vel 34->23, freq=139Hz, sample=45
    db 49,1,251,1,57,23,1,21,208,0  ; n1462 t=359.099s dur=507ms, vel 34->23, freq=208Hz, sample=57
    db 97,0,162,0,57,23,1,22,21,1  ; n1463 t=359.405s dur=162ms, vel 33->23, freq=277Hz, sample=57
    db 239,0,125,1,69,29,1,23,93,1  ; n1464 t=359.502s dur=381ms, vel 42->29, freq=349Hz, sample=69
    db 92,0,100,1,45,24,1,24,92,0  ; n1465 t=359.741s dur=356ms, vel 35->24, freq=92Hz, sample=45
    db 7,0,12,2,57,25,1,25,233,0  ; n1466 t=359.833s dur=524ms, vel 36->25, freq=233Hz, sample=57
    db 72,0,75,1,57,25,1,26,185,0  ; n1467 t=359.840s dur=331ms, vel 36->25, freq=185Hz, sample=57
    db 195,0,223,0,69,30,2,27,210,1  ; n1468 t=359.912s dur=223ms, vel 43->30, freq=466Hz, sample=69
    db 36,0,45,1,45,23,1,28,156,0  ; n1469 t=360.108s dur=301ms, vel 33->23, freq=156Hz, sample=45
    db 207,0,8,1,69,26,1,29,114,1  ; n1470 t=360.144s dur=264ms, vel 38->26, freq=370Hz, sample=69
    db 19,0,194,1,45,23,1,30,104,0  ; n1471 t=360.351s dur=450ms, vel 34->23, freq=104Hz, sample=45
    db 87,0,12,2,57,24,1,31,208,0  ; n1472 t=360.370s dur=524ms, vel 35->24, freq=208Hz, sample=57
    db 5,0,82,1,57,28,1,0,21,1  ; n1473 t=360.457s dur=338ms, vel 40->28, freq=277Hz, sample=57
    db 69,1,130,1,69,28,1,1,93,1  ; n1474 t=360.462s dur=386ms, vel 41->28, freq=349Hz, sample=69
    db 5,0,75,0,57,28,1,2,6,1  ; n1475 t=360.787s dur=75ms, vel 40->28, freq=262Hz, sample=57
    db 224,0,88,0,57,28,1,3,55,1  ; n1476 t=360.793s dur=88ms, vel 40->28, freq=311Hz, sample=57
    db 6,0,182,0,57,26,1,4,175,0  ; n1477 t=361.017s dur=182ms, vel 38->26, freq=175Hz, sample=57
    db 49,0,146,0,57,26,1,5,208,0  ; n1478 t=361.023s dur=146ms, vel 38->26, freq=208Hz, sample=57
    db 1,0,15,1,69,28,2,6,42,2  ; n1479 t=361.071s dur=271ms, vel 41->28, freq=554Hz, sample=69
    db 213,0,247,0,57,27,1,7,21,1  ; n1480 t=361.072s dur=247ms, vel 39->27, freq=277Hz, sample=57
    db 7,0,60,2,45,29,1,8,156,0  ; n1481 t=361.286s dur=572ms, vel 42->29, sust 507->572, freq=156Hz, sample=45
    db 67,0,53,2,57,29,1,9,208,0  ; n1482 t=361.293s dur=565ms, vel 42->29, sust 462->565, freq=208Hz, sample=57
    db 7,0,242,1,69,30,2,10,11,2  ; n1483 t=361.360s dur=498ms, vel 44->30, sust 350->498, freq=523Hz, sample=69
    db 161,1,235,1,57,28,1,11,6,1  ; n1484 t=361.367s dur=491ms, vel 41->28, sust 333->491, freq=262Hz, sample=57
; t 361.4539 Sustain 127 (Instr 1)
; t 361.4539 Sustain 127 (Instr 2)
; t 361.4877 Soft 0 (Instr 1)
; t 361.4877 Soft 0 (Instr 2)
    db 5,0,164,0,57,35,1,12,196,0  ; n1485 t=361.784s dur=164ms, freq=196Hz, sample=57
    db 1,0,0,1,69,40,2,13,210,1  ; n1486 t=361.790s dur=256ms, freq=466Hz, sample=69
    db 0,0,69,0,57,35,1,14,233,0  ; n1487 t=361.791s dur=69ms, freq=233Hz, sample=57
    db 229,0,114,0,45,35,1,15,139,0  ; n1488 t=361.791s dur=114ms, freq=139Hz, sample=45
; t 361.8585 Sustain 0 (Instr 1)
; t 361.8585 Sustain 0 (Instr 2)
    db 13,0,77,0,45,33,1,16,131,0  ; n1489 t=362.020s dur=77ms, freq=131Hz, sample=45
    db 23,0,115,0,57,33,1,17,6,1  ; n1490 t=362.033s dur=115ms, freq=262Hz, sample=57
    db 2,0,106,0,69,43,2,18,110,2  ; n1491 t=362.056s dur=106ms, freq=622Hz, sample=69
    db 131,1,95,0,57,33,1,19,55,1  ; n1492 t=362.058s dur=95ms, freq=311Hz, sample=57
    db 5,0,112,0,45,34,1,20,139,0  ; n1493 t=362.445s dur=112ms, freq=139Hz, sample=45
    db 41,0,81,0,57,34,1,21,233,0  ; n1494 t=362.450s dur=81ms, freq=233Hz, sample=57
    db 1,0,105,1,69,45,2,22,42,2  ; n1495 t=362.491s dur=361ms, freq=554Hz, sample=69
    db 185,0,230,0,69,34,1,23,93,1  ; n1496 t=362.492s dur=230ms, freq=349Hz, sample=69
    db 1,0,89,0,45,37,1,24,156,0  ; n1497 t=362.677s dur=89ms, freq=156Hz, sample=45
    db 24,0,95,0,57,37,1,25,55,1  ; n1498 t=362.678s dur=95ms, freq=311Hz, sample=57
    db 189,0,6,1,69,42,2,26,159,1  ; n1499 t=362.703s dur=262ms, freq=415Hz, sample=69
    db 219,0,251,0,69,40,2,27,11,2  ; n1500 t=362.892s dur=251ms, freq=523Hz, sample=69
    db 1,0,158,0,45,34,1,28,156,0  ; n1501 t=363.110s dur=158ms, freq=156Hz, sample=45
    db 10,0,125,0,57,34,1,29,21,1  ; n1502 t=363.111s dur=125ms, freq=277Hz, sample=57
    db 14,0,171,1,69,43,2,30,210,1  ; n1503 t=363.121s dur=427ms, freq=466Hz, sample=69
    db 169,0,232,0,69,43,2,31,136,1  ; n1504 t=363.135s dur=232ms, freq=392Hz, sample=69
    db 13,0,115,0,57,34,1,0,6,1  ; n1505 t=363.304s dur=115ms, freq=262Hz, sample=57
    db 167,0,151,0,57,33,1,1,208,0  ; n1506 t=363.316s dur=151ms, freq=208Hz, sample=57
    db 206,0,158,0,69,39,2,2,159,1  ; n1507 t=363.483s dur=158ms, freq=415Hz, sample=69
    db 17,0,217,0,57,35,1,3,233,0  ; n1508 t=363.689s dur=217ms, freq=233Hz, sample=57
    db 7,0,176,0,81,40,2,4,228,2  ; n1509 t=363.706s dur=176ms, freq=740Hz, sample=81
    db 13,0,95,0,57,35,1,5,21,1  ; n1510 t=363.714s dur=95ms, freq=277Hz, sample=57
    db 180,0,174,0,69,35,1,6,114,1  ; n1511 t=363.726s dur=174ms, freq=370Hz, sample=69
    db 6,0,116,1,57,38,1,7,21,1  ; n1512 t=363.906s dur=372ms, sust 355->372, freq=277Hz, sample=57
    db 48,0,145,1,57,38,1,8,208,0  ; n1513 t=363.912s dur=401ms, freq=208Hz, sample=57
    db 0,0,63,1,69,38,1,9,93,1  ; n1514 t=363.960s dur=319ms, sust 262->319, freq=349Hz, sample=69
    db 105,1,63,1,81,43,2,10,186,2  ; n1515 t=363.960s dur=319ms, sust 295->319, freq=698Hz, sample=81
; t 364.0232 Sustain 127 (Instr 1)
; t 364.0232 Sustain 127 (Instr 2)
; t 364.2788 Sustain 0 (Instr 1)
; t 364.2788 Sustain 0 (Instr 2)
    db 1,0,139,0,57,38,1,11,185,0  ; n1516 t=364.321s dur=139ms, freq=185Hz, sample=57
    db 10,0,107,0,57,38,1,12,6,1  ; n1517 t=364.322s dur=107ms, freq=262Hz, sample=57
    db 3,0,164,0,69,39,2,13,110,2  ; n1518 t=364.332s dur=164ms, freq=622Hz, sample=69
    db 154,0,119,0,57,38,1,14,55,1  ; n1519 t=364.335s dur=119ms, freq=311Hz, sample=57
    db 35,0,208,1,57,40,1,15,175,0  ; n1520 t=364.489s dur=464ms, sust 198->464, freq=175Hz, sample=57
    db 17,0,173,1,57,41,1,16,21,1  ; n1521 t=364.524s dur=429ms, sust 188->429, freq=277Hz, sample=57
    db 2,0,156,1,81,47,2,17,63,3  ; n1522 t=364.541s dur=412ms, sust 220->412, freq=831Hz, sample=81
    db 183,1,154,1,69,47,2,18,159,1  ; n1523 t=364.543s dur=410ms, sust 225->410, freq=415Hz, sample=69
; t 364.5977 Sustain 127 (Instr 1)
; t 364.5977 Sustain 127 (Instr 2)
; t 364.9536 Sustain 0 (Instr 1)
; t 364.9536 Sustain 0 (Instr 2)
    db 12,0,165,1,69,43,1,19,114,1  ; n1524 t=364.982s dur=421ms, sust 296->421, freq=370Hz, sample=69
    db 2,0,153,1,81,56,2,20,228,2  ; n1525 t=364.994s dur=409ms, sust 297->409, freq=740Hz, sample=81
    db 13,0,144,0,57,43,1,21,233,0  ; n1526 t=364.996s dur=144ms, freq=233Hz, sample=57
    db 193,0,95,0,57,44,1,22,21,1  ; n1527 t=365.009s dur=95ms, freq=277Hz, sample=57
; t 365.1765 Sustain 127 (Instr 1)
; t 365.1765 Sustain 127 (Instr 2)
    db 6,0,2,1,57,46,1,23,21,1  ; n1528 t=365.202s dur=258ms, freq=277Hz, sample=57
    db 156,0,122,1,57,46,1,24,208,0  ; n1529 t=365.208s dur=378ms, freq=208Hz, sample=57
    db 17,0,119,0,81,53,2,25,186,2  ; n1530 t=365.364s dur=119ms, freq=698Hz, sample=81
    db 171,0,83,0,69,44,1,26,93,1  ; n1531 t=365.381s dur=83ms, freq=349Hz, sample=69
; t 365.4035 Sustain 0 (Instr 1)
; t 365.4035 Sustain 0 (Instr 2)
    db 0,0,96,0,57,44,1,27,6,1  ; n1532 t=365.552s dur=96ms, freq=262Hz, sample=57
    db 11,0,164,0,57,44,1,28,185,0  ; n1533 t=365.552s dur=164ms, freq=185Hz, sample=57
    db 8,0,138,0,69,56,2,29,110,2  ; n1534 t=365.563s dur=138ms, freq=622Hz, sample=69
    db 117,0,101,0,57,44,1,30,55,1  ; n1535 t=365.571s dur=101ms, freq=311Hz, sample=57
    db 38,0,199,0,57,46,1,31,175,0  ; n1536 t=365.689s dur=199ms, freq=175Hz, sample=57
    db 35,0,198,0,57,47,1,0,21,1  ; n1537 t=365.727s dur=198ms, freq=277Hz, sample=57
    db 4,0,0,1,69,66,2,1,159,1  ; n1538 t=365.762s dur=256ms, freq=415Hz, sample=69
    db 112,1,239,0,81,67,2,2,63,3  ; n1539 t=365.766s dur=239ms, freq=831Hz, sample=81
    db 2,0,30,1,81,66,2,3,228,2  ; n1540 t=366.133s dur=286ms, freq=740Hz, sample=81
    db 18,0,100,0,57,52,1,4,233,0  ; n1541 t=366.135s dur=100ms, freq=233Hz, sample=57
    db 18,0,87,0,57,52,1,5,21,1  ; n1542 t=366.153s dur=87ms, freq=277Hz, sample=57
    db 144,0,3,1,69,53,1,6,114,1  ; n1543 t=366.171s dur=259ms, freq=370Hz, sample=69
    db 5,0,213,1,57,55,1,7,21,1  ; n1544 t=366.315s dur=469ms, sust 284->469, freq=277Hz, sample=57
    db 184,0,208,1,57,54,1,8,208,0  ; n1545 t=366.320s dur=464ms, sust 256->464, freq=208Hz, sample=57
    db 13,0,24,1,81,70,2,9,186,2  ; n1546 t=366.504s dur=280ms, sust 242->280, freq=698Hz, sample=81
    db 112,0,12,1,69,52,1,10,93,1  ; n1547 t=366.517s dur=268ms, sust 180->268, freq=349Hz, sample=69
; t 366.5240 Sustain 127 (Instr 1)
; t 366.5240 Sustain 127 (Instr 2)
    db 67,0,101,3,57,61,1,11,196,0  ; n1548 t=366.628s dur=869ms, freq=196Hz, sample=57
    db 31,0,101,2,57,62,1,12,21,1  ; n1549 t=366.695s dur=613ms, freq=277Hz, sample=57
    db 98,0,133,2,69,62,1,13,74,1  ; n1550 t=366.726s dur=645ms, freq=330Hz, sample=69
; t 366.7848 Sustain 0 (Instr 1)
; t 366.7848 Sustain 0 (Instr 2)
    db 14,0,8,6,81,80,2,14,164,3  ; n1551 t=366.824s dur=1544ms, freq=932Hz, sample=81
    db 140,2,133,5,69,83,2,15,210,1  ; n1552 t=366.838s dur=1413ms, freq=466Hz, sample=69
; t 367.1079 Soft 127 (Instr 1)
; t 367.1079 Soft 127 (Instr 2)
    db 6,0,237,4,57,38,1,16,21,1  ; n1553 t=367.489s dur=1261ms, vel 55->38, freq=277Hz, sample=57
    db 3,0,27,5,57,38,1,17,208,0  ; n1554 t=367.495s dur=1307ms, vel 55->38, freq=208Hz, sample=57
    db 43,3,147,4,69,38,1,18,93,1  ; n1555 t=367.499s dur=1171ms, vel 55->38, freq=349Hz, sample=69
    db 14,0,142,1,81,35,2,19,63,3  ; n1556 t=368.310s dur=398ms, vel 50->35, freq=831Hz, sample=81
    db 103,4,147,1,69,35,2,20,159,1  ; n1557 t=368.323s dur=403ms, vel 50->35, freq=415Hz, sample=69
    db 24,0,244,5,33,23,1,21,52,0  ; n1558 t=369.451s dur=1524ms, vel 34->23, freq=52Hz, sample=33
    db 144,0,114,5,45,24,1,22,104,0  ; n1559 t=369.475s dur=1394ms, vel 35->24, freq=104Hz, sample=45
    db 7,0,177,4,57,25,1,23,185,0  ; n1560 t=369.619s dur=1201ms, vel 37->25, freq=185Hz, sample=57
    db 138,3,209,3,57,25,1,24,6,1  ; n1561 t=369.626s dur=977ms, vel 37->25, freq=262Hz, sample=57
    db 12,1,37,1,57,26,1,25,55,1  ; n1562 t=370.532s dur=293ms, vel 38->26, freq=311Hz, sample=57
    db 173,0,37,1,57,25,1,26,21,1  ; n1563 t=370.800s dur=293ms, vel 36->25, freq=277Hz, sample=57
    db 31,0,148,3,33,23,1,27,69,0  ; n1564 t=370.973s dur=916ms, vel 33->23, freq=69Hz, sample=33
    db 177,0,91,3,45,23,1,28,104,0  ; n1565 t=371.003s dur=859ms, vel 33->23, freq=104Hz, sample=45
    db 5,0,157,2,57,24,1,29,21,1  ; n1566 t=371.181s dur=669ms, vel 35->24, freq=277Hz, sample=57
    db 122,5,78,2,57,24,1,30,175,0  ; n1567 t=371.186s dur=590ms, vel 35->24, freq=175Hz, sample=57
; t 371.2199 Soft 0 (Instr 1)
; t 371.2199 Soft 0 (Instr 2)
    db 4,0,198,3,57,45,1,31,175,0  ; n1568 t=372.588s dur=966ms, sust 672->966, freq=175Hz, sample=57
    db 138,1,194,3,69,45,1,0,93,1  ; n1569 t=372.592s dur=962ms, sust 672->962, freq=349Hz, sample=69
; t 372.9106 Sustain 127 (Instr 1)
; t 372.9106 Sustain 127 (Instr 2)
    db 12,0,106,3,33,50,1,1,69,0  ; n1570 t=372.986s dur=874ms, freq=69Hz, sample=33
    db 111,2,120,10,45,50,1,2,104,0  ; n1571 t=372.997s dur=2680ms, freq=104Hz, sample=45
; t 373.5543 Sustain 0 (Instr 1)
; t 373.5543 Sustain 0 (Instr 2)
    db 7,0,91,3,69,55,1,3,114,1  ; n1572 t=373.620s dur=859ms, sust 503->859, freq=370Hz, sample=69
    db 255,0,84,3,57,55,1,4,185,0  ; n1573 t=373.627s dur=852ms, sust 488->852, freq=185Hz, sample=57
; t 373.8624 Sustain 127 (Instr 1)
; t 373.8624 Sustain 127 (Instr 2)
    db 56,2,178,3,33,55,1,5,78,0  ; n1574 t=373.882s dur=946ms, sust 795->946, freq=78Hz, sample=33
    db 4,0,122,1,57,55,1,6,55,1  ; n1575 t=374.450s dur=378ms, sust 354->378, freq=311Hz, sample=57
    db 201,0,118,1,69,52,2,7,110,2  ; n1576 t=374.454s dur=374ms, sust 366->374, freq=622Hz, sample=69
; t 374.4797 Sustain 0 (Instr 1)
; t 374.4797 Sustain 0 (Instr 2)
    db 219,0,55,2,45,55,1,8,92,0  ; n1577 t=374.655s dur=567ms, freq=92Hz, sample=45
; t 374.6601 Sustain 127 (Instr 1)
; t 374.6601 Sustain 127 (Instr 2)
; t 374.8289 Sustain 0 (Instr 1)
; t 374.8289 Sustain 0 (Instr 2)
    db 3,0,109,0,69,46,2,9,11,2  ; n1578 t=374.874s dur=109ms, freq=523Hz, sample=69
    db 198,0,115,0,57,55,1,10,6,1  ; n1579 t=374.877s dur=115ms, freq=262Hz, sample=57
; t 375.0094 Sustain 127 (Instr 1)
; t 375.0094 Sustain 127 (Instr 2)
; t 375.0368 Soft 127 (Instr 1)
; t 375.0368 Soft 127 (Instr 2)
    db 8,0,113,0,69,30,2,11,159,1  ; n1580 t=375.076s dur=113ms, vel 44->30, sust 108->113, freq=415Hz, sample=69
    db 110,0,105,0,57,38,1,12,208,0  ; n1581 t=375.084s dur=105ms, vel 55->38, sust 64->105, freq=208Hz, sample=57
; t 375.1898 Sustain 0 (Instr 1)
; t 375.1898 Sustain 0 (Instr 2)
    db 88,0,191,1,45,38,1,13,87,0  ; n1582 t=375.194s dur=447ms, vel 55->38, freq=87Hz, sample=45
    db 13,0,162,0,69,32,2,14,42,2  ; n1583 t=375.282s dur=162ms, vel 47->32, freq=554Hz, sample=69
    db 217,0,119,0,57,38,1,15,21,1  ; n1584 t=375.294s dur=119ms, vel 55->38, freq=277Hz, sample=57
    db 12,0,76,0,81,30,2,16,186,2  ; n1585 t=375.512s dur=76ms, vel 44->30, freq=698Hz, sample=81
    db 60,1,64,0,69,38,1,17,93,1  ; n1586 t=375.523s dur=64ms, vel 55->38, freq=349Hz, sample=69
    db 4,0,198,2,57,38,1,18,175,0  ; n1587 t=375.839s dur=710ms, vel 55->38, sust 578->710, freq=175Hz, sample=57
    db 177,0,194,2,69,38,1,19,93,1  ; n1588 t=375.843s dur=706ms, vel 55->38, sust 601->706, freq=349Hz, sample=69
; t 375.8724 Soft 0 (Instr 1)
; t 375.8724 Soft 0 (Instr 2)
    db 16,0,31,3,33,55,1,20,69,0  ; n1589 t=376.020s dur=799ms, freq=69Hz, sample=33
    db 13,2,207,7,45,55,1,21,104,0  ; n1590 t=376.036s dur=1999ms, sust 1816->1999, freq=104Hz, sample=45
; t 376.0359 Sustain 127 (Instr 1)
; t 376.0359 Sustain 127 (Instr 2)
; t 376.5496 Sustain 0 (Instr 1)
; t 376.5496 Sustain 0 (Instr 2)
    db 20,0,104,3,69,55,1,22,114,1  ; n1591 t=376.561s dur=872ms, sust 510->872, freq=370Hz, sample=69
    db 242,0,84,3,57,55,1,23,185,0  ; n1592 t=376.581s dur=852ms, sust 486->852, freq=185Hz, sample=57
    db 245,1,250,2,33,55,1,24,78,0  ; n1593 t=376.823s dur=762ms, freq=78Hz, sample=33
; t 376.8861 Sustain 127 (Instr 1)
; t 376.8861 Sustain 127 (Instr 2)
; t 377.2647 Soft 127 (Instr 1)
; t 377.2647 Soft 127 (Instr 2)
    db 2,0,199,2,81,35,2,25,228,2  ; n1594 t=377.324s dur=711ms, vel 50->35, sust 483->711, freq=740Hz, sample=81
    db 237,0,197,2,69,38,1,26,114,1  ; n1595 t=377.326s dur=709ms, vel 55->38, sust 493->709, freq=370Hz, sample=69
; t 377.4335 Sustain 0 (Instr 1)
; t 377.4335 Sustain 0 (Instr 2)
    db 240,0,81,2,33,38,1,27,52,0  ; n1596 t=377.563s dur=593ms, vel 55->38, freq=52Hz, sample=33
    db 8,0,233,0,81,30,2,28,164,3  ; n1597 t=377.803s dur=233ms, vel 44->30, sust 146->233, freq=932Hz, sample=81
; t 377.8069 Sustain 127 (Instr 1)
; t 377.8069 Sustain 127 (Instr 2)
    db 224,0,224,0,69,30,2,29,210,1  ; n1598 t=377.811s dur=224ms, vel 44->30, sust 170->224, freq=466Hz, sample=69
    db 62,0,108,0,45,38,1,30,104,0  ; n1599 t=378.035s dur=108ms, vel 55->38, freq=104Hz, sample=45
; t 378.0358 Sustain 0 (Instr 1)
; t 378.0358 Sustain 0 (Instr 2)
    db 4,0,96,0,57,38,1,31,6,1  ; n1600 t=378.097s dur=96ms, vel 55->38, freq=262Hz, sample=57
    db 121,0,101,0,69,32,2,0,11,2  ; n1601 t=378.101s dur=101ms, vel 46->32, freq=523Hz, sample=69
    db 29,0,57,2,33,38,1,1,69,0  ; n1602 t=378.223s dur=569ms, vel 55->38, sust 401->569, freq=69Hz, sample=33
    db 63,0,27,2,45,38,1,2,104,0  ; n1603 t=378.252s dur=539ms, vel 55->38, sust 343->539, freq=104Hz, sample=45
    db 10,0,220,1,57,38,1,3,55,1  ; n1604 t=378.315s dur=476ms, vel 55->38, sust 100->476, freq=311Hz, sample=57
    db 194,0,211,1,69,34,2,4,110,2  ; n1605 t=378.325s dur=467ms, vel 49->34, sust 168->467, freq=622Hz, sample=69
; t 378.4007 Sustain 127 (Instr 1)
; t 378.4007 Sustain 127 (Instr 2)
    db 10,0,17,1,57,38,1,5,21,1  ; n1606 t=378.519s dur=273ms, vel 55->38, sust 102->273, freq=277Hz, sample=57
    db 240,0,7,1,69,32,2,6,42,2  ; n1607 t=378.528s dur=263ms, vel 46->32, sust 83->263, freq=554Hz, sample=69
; t 378.5705 Soft 0 (Instr 1)
; t 378.5705 Soft 0 (Instr 2)
    db 4,0,29,3,57,55,1,7,175,0  ; n1608 t=378.768s dur=797ms, sust 623->797, freq=175Hz, sample=57
    db 247,0,25,3,69,55,1,8,93,1  ; n1609 t=378.772s dur=793ms, sust 618->793, freq=349Hz, sample=69
; t 378.7920 Sustain 0 (Instr 1)
; t 378.7920 Sustain 0 (Instr 2)
    db 4,0,225,2,33,55,1,9,69,0  ; n1610 t=379.019s dur=737ms, freq=69Hz, sample=33
    db 4,2,206,9,45,55,1,10,104,0  ; n1611 t=379.023s dur=2510ms, sust 2320->2510, freq=104Hz, sample=45
; t 379.0420 Sustain 127 (Instr 1)
; t 379.0420 Sustain 127 (Instr 2)
    db 14,0,196,2,69,55,1,11,114,1  ; n1612 t=379.539s dur=708ms, sust 432->708, freq=370Hz, sample=69
    db 208,0,182,2,57,55,1,12,185,0  ; n1613 t=379.553s dur=694ms, sust 408->694, freq=185Hz, sample=57
; t 379.5651 Sustain 0 (Instr 1)
; t 379.5651 Sustain 0 (Instr 2)
    db 237,1,99,3,33,55,1,13,78,0  ; n1614 t=379.760s dur=867ms, sust 728->867, freq=78Hz, sample=33
; t 379.8319 Sustain 127 (Instr 1)
; t 379.8319 Sustain 127 (Instr 2)
; t 380.2473 Sustain 0 (Instr 1)
; t 380.2473 Sustain 0 (Instr 2)
    db 11,0,118,1,57,55,1,14,55,1  ; n1615 t=380.254s dur=374ms, sust 295->374, freq=311Hz, sample=57
    db 201,0,107,1,69,51,2,15,110,2  ; n1616 t=380.264s dur=363ms, sust 288->363, freq=622Hz, sample=69
; t 380.4529 Sustain 127 (Instr 1)
; t 380.4529 Sustain 127 (Instr 2)
    db 172,0,12,2,45,55,1,16,92,0  ; n1617 t=380.466s dur=524ms, freq=92Hz, sample=45
; t 380.5731 Soft 127 (Instr 1)
; t 380.5731 Soft 127 (Instr 2)
; t 380.6279 Sustain 0 (Instr 1)
; t 380.6279 Sustain 0 (Instr 2)
    db 8,0,94,0,69,32,2,17,11,2  ; n1618 t=380.637s dur=94ms, vel 46->32, freq=523Hz, sample=69
    db 209,0,100,0,57,38,1,18,6,1  ; n1619 t=380.646s dur=100ms, vel 55->38, freq=262Hz, sample=57
    db 2,0,108,0,69,30,2,19,159,1  ; n1620 t=380.855s dur=108ms, vel 44->30, freq=415Hz, sample=69
    db 104,0,70,0,57,38,1,20,208,0  ; n1621 t=380.857s dur=70ms, vel 55->38, freq=208Hz, sample=57
    db 107,0,60,2,45,38,1,21,87,0  ; n1622 t=380.961s dur=572ms, vel 55->38, sust 381->572, freq=87Hz, sample=45
    db 3,0,75,0,57,38,1,22,21,1  ; n1623 t=381.068s dur=75ms, vel 55->38, freq=277Hz, sample=57
    db 180,0,114,0,69,32,2,23,42,2  ; n1624 t=381.071s dur=114ms, vel 47->32, freq=554Hz, sample=69
; t 381.2152 Sustain 127 (Instr 1)
; t 381.2152 Sustain 127 (Instr 2)
    db 1,0,26,1,81,31,2,24,186,2  ; n1625 t=381.251s dur=282ms, vel 45->31, sust 72->282, freq=698Hz, sample=81
    db 31,1,25,1,69,38,1,25,93,1  ; n1626 t=381.252s dur=281ms, vel 55->38, sust 71->281, freq=349Hz, sample=69
; t 381.3649 Soft 0 (Instr 1)
; t 381.3649 Soft 0 (Instr 2)
; t 381.5336 Sustain 0 (Instr 1)
; t 381.5336 Sustain 0 (Instr 2)
    db 10,0,200,2,57,55,1,26,175,0  ; n1627 t=381.539s dur=712ms, sust 556->712, freq=175Hz, sample=57
    db 153,0,190,2,69,55,1,27,93,1  ; n1628 t=381.549s dur=702ms, sust 525->702, freq=349Hz, sample=69
    db 16,0,227,2,33,55,1,28,69,0  ; n1629 t=381.702s dur=739ms, freq=69Hz, sample=33
    db 234,1,142,7,45,55,1,29,104,0  ; n1630 t=381.718s dur=1934ms, sust 1690->1934, freq=104Hz, sample=45
; t 381.7561 Sustain 127 (Instr 1)
; t 381.7561 Sustain 127 (Instr 2)
    db 25,0,227,2,69,55,1,30,114,1  ; n1631 t=382.208s dur=739ms, sust 416->739, freq=370Hz, sample=69
    db 212,0,201,2,57,55,1,31,185,0  ; n1632 t=382.234s dur=713ms, sust 406->713, freq=185Hz, sample=57
; t 382.2516 Sustain 0 (Instr 1)
; t 382.2516 Sustain 0 (Instr 2)
    db 225,1,197,2,33,55,1,0,78,0  ; n1633 t=382.446s dur=709ms, freq=78Hz, sample=33
; t 382.4973 Sustain 127 (Instr 1)
; t 382.4973 Sustain 127 (Instr 2)
    db 1,0,214,2,81,51,2,1,228,2  ; n1634 t=382.926s dur=726ms, sust 480->726, freq=740Hz, sample=81
    db 232,0,213,2,69,55,1,2,114,1  ; n1635 t=382.927s dur=725ms, sust 460->725, freq=370Hz, sample=69
; t 382.9475 Sustain 0 (Instr 1)
; t 382.9475 Sustain 0 (Instr 2)
    db 220,0,52,2,33,55,1,3,52,0  ; n1636 t=383.159s dur=564ms, freq=52Hz, sample=33
; t 383.3576 Sustain 127 (Instr 1)
; t 383.3576 Sustain 127 (Instr 2)
    db 3,0,16,1,69,45,2,4,210,1  ; n1637 t=383.380s dur=272ms, sust 156->272, freq=466Hz, sample=69
    db 226,0,13,1,81,45,2,5,164,3  ; n1638 t=383.383s dur=269ms, sust 128->269, freq=932Hz, sample=81
    db 55,0,103,0,45,55,1,6,104,0  ; n1639 t=383.608s dur=103ms, freq=104Hz, sample=45
; t 383.6527 Sustain 0 (Instr 1)
; t 383.6527 Sustain 0 (Instr 2)
    db 15,0,127,0,69,43,2,7,11,2  ; n1640 t=383.663s dur=127ms, freq=523Hz, sample=69
    db 112,0,70,0,57,55,1,8,6,1  ; n1641 t=383.678s dur=70ms, freq=262Hz, sample=57
    db 50,0,231,1,33,55,1,9,69,0  ; n1642 t=383.790s dur=487ms, sust 294->487, freq=69Hz, sample=33
    db 46,0,182,1,45,55,1,10,104,0  ; n1643 t=383.839s dur=438ms, sust 250->438, freq=104Hz, sample=45
    db 2,0,135,1,69,46,2,11,110,2  ; n1644 t=383.886s dur=391ms, sust 145->391, freq=622Hz, sample=69
    db 191,0,133,1,57,55,1,12,55,1  ; n1645 t=383.888s dur=389ms, sust 113->389, freq=311Hz, sample=57
; t 383.8930 Sustain 127 (Instr 1)
; t 383.8930 Sustain 127 (Instr 2)
; t 384.0511 Soft 127 (Instr 1)
; t 384.0511 Soft 127 (Instr 2)
    db 10,0,199,0,57,38,1,13,21,1  ; n1646 t=384.079s dur=199ms, vel 55->38, sust 90->199, freq=277Hz, sample=57
    db 17,1,188,0,69,33,2,14,42,2  ; n1647 t=384.089s dur=188ms, vel 48->33, sust 108->188, freq=554Hz, sample=69
; t 384.2776 Sustain 0 (Instr 1)
; t 384.2776 Sustain 0 (Instr 2)
    db 1,0,42,3,81,36,2,15,186,2  ; n1648 t=384.362s dur=810ms, vel 52->36, sust 536->810, freq=698Hz, sample=81
    db 6,1,41,3,69,38,1,16,93,1  ; n1649 t=384.363s dur=809ms, vel 55->38, sust 543->809, freq=349Hz, sample=69
    db 1,0,205,2,45,38,1,17,147,0  ; n1650 t=384.625s dur=717ms, vel 55->38, freq=147Hz, sample=45
    db 233,1,93,2,57,38,1,18,208,0  ; n1651 t=384.627s dur=605ms, vel 55->38, freq=208Hz, sample=57
; t 384.6950 Sustain 127 (Instr 1)
; t 384.6950 Sustain 127 (Instr 2)
    db 32,0,15,3,69,33,2,19,210,1  ; n1652 t=385.115s dur=783ms, vel 48->33, sust 764->783, freq=466Hz, sample=69
    db 224,0,239,2,57,38,1,20,233,0  ; n1653 t=385.147s dur=751ms, vel 55->38, sust 734->751, freq=233Hz, sample=57
; t 385.1724 Sustain 0 (Instr 1)
; t 385.1724 Sustain 0 (Instr 2)
    db 6,0,222,2,45,38,1,21,139,0  ; n1654 t=385.371s dur=734ms, vel 55->38, freq=139Hz, sample=45
    db 8,2,147,2,57,38,1,22,196,0  ; n1655 t=385.377s dur=659ms, vel 55->38, freq=196Hz, sample=57
; t 385.5687 Sustain 127 (Instr 1)
; t 385.5687 Sustain 127 (Instr 2)
    db 7,0,234,2,69,31,2,23,110,2  ; n1656 t=385.897s dur=746ms, vel 45->31, sust 502->746, freq=622Hz, sample=69
; t 385.8986 Sustain 0 (Instr 1)
; t 385.8986 Sustain 0 (Instr 2)
    db 198,0,226,2,57,38,1,24,55,1  ; n1657 t=385.904s dur=738ms, vel 55->38, sust 496->738, freq=311Hz, sample=57
    db 4,0,248,2,57,38,1,25,185,0  ; n1658 t=386.102s dur=760ms, vel 55->38, freq=185Hz, sample=57
    db 216,1,250,2,45,38,1,26,131,0  ; n1659 t=386.106s dur=762ms, vel 55->38, freq=131Hz, sample=45
; t 386.1895 Sustain 127 (Instr 1)
; t 386.1895 Sustain 127 (Instr 2)
    db 14,0,133,3,69,30,2,27,159,1  ; n1660 t=386.578s dur=901ms, vel 43->30, sust 716->901, freq=415Hz, sample=69
    db 237,0,120,3,57,38,1,28,208,0  ; n1661 t=386.592s dur=888ms, vel 55->38, sust 714->888, freq=208Hz, sample=57
; t 386.6427 Sustain 0 (Instr 1)
; t 386.6427 Sustain 0 (Instr 2)
    db 6,0,139,2,45,38,1,29,123,0  ; n1662 t=386.829s dur=651ms, vel 55->38, sust 391->651, freq=123Hz, sample=45
    db 231,1,132,2,57,38,1,30,175,0  ; n1663 t=386.836s dur=644ms, vel 55->38, sust 358->644, freq=175Hz, sample=57
; t 386.9915 Sustain 127 (Instr 1)
; t 386.9915 Sustain 127 (Instr 2)
    db 5,0,178,2,57,38,1,31,21,1  ; n1664 t=387.322s dur=690ms, vel 55->38, sust 466->690, freq=277Hz, sample=57
    db 188,0,172,2,69,29,2,0,42,2  ; n1665 t=387.328s dur=684ms, vel 42->29, sust 459->684, freq=554Hz, sample=69
; t 387.4803 Sustain 0 (Instr 1)
; t 387.4803 Sustain 0 (Instr 2)
    db 19,0,109,4,45,38,1,1,117,0  ; n1666 t=387.515s dur=1133ms, vel 55->38, sust 783->1133, freq=117Hz, sample=45
    db 221,1,49,10,45,38,1,2,139,0  ; n1667 t=387.534s dur=2609ms, vel 55->38, freq=139Hz, sample=45
; t 387.6974 Sustain 127 (Instr 1)
; t 387.6974 Sustain 127 (Instr 2)
    db 5,0,125,2,57,38,1,3,185,0  ; n1668 t=388.011s dur=637ms, vel 55->38, sust 560->637, freq=185Hz, sample=57
; t 388.0124 Sustain 0 (Instr 1)
; t 388.0124 Sustain 0 (Instr 2)
    db 216,0,120,2,69,38,1,4,114,1  ; n1669 t=388.017s dur=632ms, vel 55->38, sust 566->632, freq=370Hz, sample=69
    db 170,1,146,2,45,38,1,5,104,0  ; n1670 t=388.233s dur=658ms, vel 55->38, freq=104Hz, sample=45
; t 388.2800 Sustain 127 (Instr 1)
; t 388.2800 Sustain 127 (Instr 2)
; t 388.6487 Sustain 0 (Instr 1)
; t 388.6487 Sustain 0 (Instr 2)
    db 18,0,49,1,57,38,1,6,175,0  ; n1671 t=388.658s dur=305ms, vel 55->38, freq=175Hz, sample=57
    db 175,0,37,1,69,38,1,7,93,1  ; n1672 t=388.676s dur=293ms, vel 55->38, freq=349Hz, sample=69
    db 178,0,37,1,33,38,1,8,69,0  ; n1673 t=388.851s dur=293ms, vel 55->38, freq=69Hz, sample=33
    db 26,0,27,1,45,38,1,9,87,0  ; n1674 t=389.029s dur=283ms, vel 55->38, freq=87Hz, sample=45
    db 19,0,54,1,69,30,2,10,159,1  ; n1675 t=389.055s dur=310ms, vel 43->30, freq=415Hz, sample=69
    db 222,0,24,1,57,38,1,11,208,0  ; n1676 t=389.074s dur=280ms, vel 55->38, freq=208Hz, sample=57
    db 17,0,31,1,45,38,1,12,104,0  ; n1677 t=389.297s dur=287ms, vel 55->38, freq=104Hz, sample=45
    db 14,0,5,2,69,32,2,13,238,1  ; n1678 t=389.313s dur=517ms, vel 46->32, freq=494Hz, sample=69
    db 11,1,237,1,57,38,1,14,247,0  ; n1679 t=389.327s dur=493ms, vel 55->38, freq=247Hz, sample=57
    db 237,0,230,2,45,38,1,15,92,0  ; n1680 t=389.594s dur=742ms, vel 55->38, freq=92Hz, sample=45
    db 13,0,100,0,57,38,1,16,233,0  ; n1681 t=389.831s dur=100ms, vel 55->38, freq=233Hz, sample=57
    db 228,0,219,0,69,28,2,17,210,1  ; n1682 t=389.843s dur=219ms, vel 41->28, freq=466Hz, sample=69
    db 2,0,100,1,69,30,2,18,42,2  ; n1683 t=390.071s dur=356ms, vel 44->30, freq=554Hz, sample=69
    db 192,0,93,1,57,38,1,19,21,1  ; n1684 t=390.073s dur=349ms, vel 55->38, freq=277Hz, sample=57
    db 44,0,105,3,45,38,1,20,117,0  ; n1685 t=390.265s dur=873ms, vel 55->38, freq=117Hz, sample=45
    db 24,2,204,11,45,38,1,21,139,0  ; n1686 t=390.309s dur=3020ms, vel 55->38, sust 2922->3020, freq=139Hz, sample=45
    db 0,0,16,3,69,38,1,22,114,1  ; n1687 t=390.845s dur=784ms, vel 55->38, sust 686->784, freq=370Hz, sample=69
    db 253,0,16,3,57,38,1,23,185,0  ; n1688 t=390.845s dur=784ms, vel 55->38, sust 687->784, freq=185Hz, sample=57
    db 248,1,9,3,45,38,1,24,104,0  ; n1689 t=391.098s dur=777ms, vel 55->38, freq=104Hz, sample=45
; t 391.2538 Sustain 127 (Instr 1)
; t 391.2538 Sustain 127 (Instr 2)
    db 7,0,69,3,69,38,1,25,93,1  ; n1690 t=391.602s dur=837ms, vel 55->38, sust 682->837, freq=349Hz, sample=69
    db 2,1,61,3,57,38,1,26,175,0  ; n1691 t=391.610s dur=829ms, vel 55->38, sust 669->829, freq=175Hz, sample=57
; t 391.6298 Sustain 0 (Instr 1)
; t 391.6298 Sustain 0 (Instr 2)
    db 10,2,60,3,45,38,1,27,98,0  ; n1692 t=391.868s dur=828ms, vel 55->38, freq=98Hz, sample=45
; t 392.0478 Sustain 127 (Instr 1)
; t 392.0478 Sustain 127 (Instr 2)
    db 10,0,171,3,69,38,1,28,74,1  ; n1693 t=392.390s dur=939ms, vel 55->38, sust 797->939, freq=330Hz, sample=69
    db 1,1,160,3,57,38,1,29,165,0  ; n1694 t=392.401s dur=928ms, vel 55->38, sust 602->928, freq=165Hz, sample=57
; t 392.4396 Sustain 0 (Instr 1)
; t 392.4396 Sustain 0 (Instr 2)
    db 3,2,48,3,45,38,1,30,104,0  ; n1695 t=392.658s dur=816ms, vel 55->38, freq=104Hz, sample=45
; t 392.6944 Soft 0 (Instr 1)
; t 392.6944 Soft 0 (Instr 2)
; t 392.7639 Sustain 127 (Instr 1)
; t 392.7639 Sustain 127 (Instr 2)
    db 0,0,98,3,57,55,1,31,175,0  ; n1696 t=393.173s dur=866ms, sust 713->866, freq=175Hz, sample=57
    db 4,1,118,3,69,55,1,0,93,1  ; n1697 t=393.173s dur=886ms, freq=349Hz, sample=69
; t 393.3295 Sustain 0 (Instr 1)
; t 393.3295 Sustain 0 (Instr 2)
    db 37,0,48,4,45,55,1,1,117,0  ; n1698 t=393.433s dur=1072ms, freq=117Hz, sample=45
    db 50,2,175,5,45,55,1,2,139,0  ; n1699 t=393.469s dur=1455ms, freq=139Hz, sample=45
; t 393.7623 Sustain 127 (Instr 1)
; t 393.7623 Sustain 127 (Instr 2)
    db 27,0,115,4,69,55,1,3,114,1  ; n1700 t=394.032s dur=1139ms, freq=370Hz, sample=69
; t 394.0392 Sustain 0 (Instr 1)
; t 394.0392 Sustain 0 (Instr 2)
    db 156,1,35,4,57,55,1,4,185,0  ; n1701 t=394.059s dur=1059ms, freq=185Hz, sample=57
; t 394.4426 Soft 127 (Instr 1)
; t 394.4426 Soft 127 (Instr 2)
    db 150,2,240,5,45,38,1,5,104,0  ; n1702 t=394.471s dur=1520ms, vel 55->38, sust 1102->1520, freq=104Hz, sample=45
    db 55,0,89,3,57,38,1,6,175,0  ; n1703 t=395.133s dur=857ms, vel 55->38, sust 643->857, freq=175Hz, sample=57
    db 72,1,35,3,69,38,1,7,93,1  ; n1704 t=395.188s dur=803ms, vel 55->38, sust 606->803, freq=349Hz, sample=69
    db 224,1,187,5,33,38,1,8,52,0  ; n1705 t=395.516s dur=1467ms, vel 55->38, sust 1170->1467, freq=52Hz, sample=33
; t 395.5521 Sustain 127 (Instr 1)
; t 395.5521 Sustain 127 (Instr 2)
; t 395.9911 Sustain 0 (Instr 1)
; t 395.9911 Sustain 0 (Instr 2)
    db 1,0,74,1,69,38,1,9,114,1  ; n1706 t=395.996s dur=330ms, vel 55->38, freq=370Hz, sample=69
    db 42,2,70,1,57,38,1,10,185,0  ; n1707 t=395.997s dur=326ms, vel 55->38, freq=185Hz, sample=57
    db 6,0,176,1,57,38,1,11,6,1  ; n1708 t=396.551s dur=432ms, vel 55->38, sust 244->432, freq=262Hz, sample=57
    db 18,0,175,1,45,38,1,12,104,0  ; n1709 t=396.557s dur=431ms, vel 55->38, freq=104Hz, sample=45
    db 151,1,152,1,45,38,1,13,131,0  ; n1710 t=396.575s dur=408ms, vel 55->38, sust 227->408, freq=131Hz, sample=45
; t 396.6059 Sustain 127 (Instr 1)
; t 396.6059 Sustain 127 (Instr 2)
    db 84,0,77,2,33,38,1,14,69,0  ; n1711 t=396.983s dur=589ms, vel 55->38, sust 313->589, freq=69Hz, sample=33
; t 396.9838 Sustain 0 (Instr 1)
; t 396.9838 Sustain 0 (Instr 2)
    db 0,0,249,1,45,38,1,15,139,0  ; n1712 t=397.067s dur=505ms, vel 55->38, sust 306->505, freq=139Hz, sample=45
    db 190,2,249,1,57,38,1,16,21,1  ; n1713 t=397.067s dur=505ms, vel 55->38, sust 317->505, freq=277Hz, sample=57
; t 397.2080 Sustain 127 (Instr 1)
; t 397.2080 Sustain 127 (Instr 2)
; t 397.3554 Soft 0 (Instr 1)
; t 397.3554 Soft 0 (Instr 2)
; t 397.5722 Sustain 0 (Instr 1)
; t 397.5722 Sustain 0 (Instr 2)
    db 1,0,241,2,81,44,2,17,186,2  ; n1714 t=397.769s dur=753ms, sust 468->753, freq=698Hz, sample=81
    db 223,0,240,2,69,55,1,18,93,1  ; n1715 t=397.770s dur=752ms, sust 468->752, freq=349Hz, sample=69
    db 1,0,175,2,45,55,1,19,147,0  ; n1716 t=397.993s dur=687ms, freq=147Hz, sample=45
    db 11,2,101,2,57,55,1,20,208,0  ; n1717 t=397.994s dur=613ms, freq=208Hz, sample=57
; t 398.0627 Sustain 127 (Instr 1)
; t 398.0627 Sustain 127 (Instr 2)
    db 12,0,209,2,57,55,1,21,233,0  ; n1718 t=398.517s dur=721ms, freq=233Hz, sample=57
; t 398.5227 Sustain 0 (Instr 1)
; t 398.5227 Sustain 0 (Instr 2)
    db 187,0,198,2,69,41,2,22,210,1  ; n1719 t=398.529s dur=710ms, freq=466Hz, sample=69
    db 6,0,227,2,45,55,1,23,139,0  ; n1720 t=398.716s dur=739ms, freq=139Hz, sample=45
    db 28,2,185,2,57,55,1,24,196,0  ; n1721 t=398.723s dur=697ms, freq=196Hz, sample=57
; t 398.9015 Sustain 127 (Instr 1)
; t 398.9015 Sustain 127 (Instr 2)
; t 399.2077 Sustain 0 (Instr 1)
; t 399.2077 Sustain 0 (Instr 2)
    db 2,0,160,2,57,55,1,25,55,1  ; n1722 t=399.262s dur=672ms, sust 524->672, freq=311Hz, sample=57
    db 208,0,158,2,69,42,2,26,110,2  ; n1723 t=399.264s dur=670ms, sust 521->670, freq=622Hz, sample=69
    db 4,0,224,2,45,55,1,27,131,0  ; n1724 t=399.473s dur=736ms, freq=131Hz, sample=45
    db 218,1,208,2,57,55,1,28,185,0  ; n1725 t=399.477s dur=720ms, freq=185Hz, sample=57
; t 399.5813 Sustain 127 (Instr 1)
; t 399.5813 Sustain 127 (Instr 2)
; t 399.9348 Sustain 0 (Instr 1)
; t 399.9348 Sustain 0 (Instr 2)
    db 14,0,235,2,69,42,2,29,159,1  ; n1726 t=399.951s dur=747ms, sust 719->747, freq=415Hz, sample=69
    db 243,0,221,2,57,55,1,30,208,0  ; n1727 t=399.964s dur=733ms, sust 481->733, freq=208Hz, sample=57
    db 13,0,234,1,45,55,1,31,123,0  ; n1728 t=400.207s dur=490ms, sust 414->490, freq=123Hz, sample=45
    db 216,1,221,1,57,55,1,0,175,0  ; n1729 t=400.220s dur=477ms, sust 388->477, freq=175Hz, sample=57
; t 400.3378 Sustain 127 (Instr 1)
; t 400.3378 Sustain 127 (Instr 2)
    db 10,0,228,2,57,55,1,1,21,1  ; n1730 t=400.692s dur=740ms, sust 504->740, freq=277Hz, sample=57
; t 400.6977 Sustain 0 (Instr 1)
; t 400.6977 Sustain 0 (Instr 2)
    db 196,0,219,2,69,43,2,2,42,2  ; n1731 t=400.702s dur=731ms, sust 486->731, freq=554Hz, sample=69
    db 0,0,238,2,45,55,1,3,117,0  ; n1732 t=400.898s dur=750ms, freq=117Hz, sample=45
    db 233,1,156,9,45,55,1,4,139,0  ; n1733 t=400.898s dur=2460ms, freq=139Hz, sample=45
; t 400.9955 Sustain 127 (Instr 1)
; t 400.9955 Sustain 127 (Instr 2)
    db 6,0,173,2,69,55,1,5,114,1  ; n1734 t=401.387s dur=685ms, sust 586->685, freq=370Hz, sample=69
    db 208,0,166,2,57,55,1,6,185,0  ; n1735 t=401.393s dur=678ms, sust 569->678, freq=185Hz, sample=57
; t 401.4332 Sustain 0 (Instr 1)
; t 401.4332 Sustain 0 (Instr 2)
    db 187,1,157,2,45,55,1,7,104,0  ; n1736 t=401.602s dur=669ms, freq=104Hz, sample=45
; t 401.6026 Soft 0 (Instr 1)
; t 401.6026 Soft 0 (Instr 2)
; t 401.7194 Sustain 127 (Instr 1)
; t 401.7194 Sustain 127 (Instr 2)
    db 12,0,180,1,57,55,1,8,175,0  ; n1737 t=402.045s dur=436ms, sust 296->436, freq=175Hz, sample=57
    db 163,0,169,1,69,55,1,9,93,1  ; n1738 t=402.056s dur=425ms, sust 283->425, freq=349Hz, sample=69
; t 402.0719 Sustain 0 (Instr 1)
; t 402.0719 Sustain 0 (Instr 2)
    db 198,0,19,1,33,55,1,10,69,0  ; n1739 t=402.219s dur=275ms, freq=69Hz, sample=33
; t 402.2718 Sustain 127 (Instr 1)
; t 402.2718 Sustain 127 (Instr 2)
    db 24,0,11,1,45,55,1,11,87,0  ; n1740 t=402.417s dur=267ms, freq=87Hz, sample=45
    db 1,0,19,1,69,40,2,12,159,1  ; n1741 t=402.441s dur=275ms, freq=415Hz, sample=69
    db 197,0,156,0,57,55,1,13,208,0  ; n1742 t=402.442s dur=156ms, freq=208Hz, sample=57
; t 402.4811 Sustain 0 (Instr 1)
; t 402.4811 Sustain 0 (Instr 2)
    db 12,0,30,1,45,55,1,14,104,0  ; n1743 t=402.639s dur=286ms, freq=104Hz, sample=45
    db 14,0,212,1,69,42,2,15,238,1  ; n1744 t=402.651s dur=468ms, freq=494Hz, sample=69
    db 210,0,75,1,57,55,1,16,247,0  ; n1745 t=402.664s dur=331ms, freq=247Hz, sample=57
    db 199,0,148,2,45,55,1,17,92,0  ; n1746 t=402.875s dur=660ms, freq=92Hz, sample=45
    db 6,0,229,0,69,44,2,18,210,1  ; n1747 t=403.073s dur=229ms, freq=466Hz, sample=69
    db 245,0,223,0,57,55,1,19,233,0  ; n1748 t=403.080s dur=223ms, freq=233Hz, sample=57
    db 1,0,127,1,69,47,2,20,42,2  ; n1749 t=403.325s dur=383ms, freq=554Hz, sample=69
    db 160,0,171,1,57,55,1,21,21,1  ; n1750 t=403.326s dur=427ms, freq=277Hz, sample=57
    db 55,0,59,3,45,55,1,22,117,0  ; n1751 t=403.486s dur=827ms, freq=117Hz, sample=45
    db 219,1,92,11,45,55,1,23,139,0  ; n1752 t=403.540s dur=2908ms, freq=139Hz, sample=45
    db 6,0,36,3,57,55,1,24,185,0  ; n1753 t=404.016s dur=804ms, sust 674->804, freq=185Hz, sample=57
    db 246,0,30,3,69,55,1,25,114,1  ; n1754 t=404.022s dur=798ms, sust 680->798, freq=370Hz, sample=69
    db 233,1,25,3,45,55,1,26,104,0  ; n1755 t=404.268s dur=793ms, freq=104Hz, sample=45
; t 404.3471 Sustain 127 (Instr 1)
; t 404.3471 Sustain 127 (Instr 2)
    db 17,0,69,3,57,55,1,27,175,0  ; n1756 t=404.757s dur=837ms, sust 824->837, freq=175Hz, sample=57
    db 36,1,56,3,69,55,1,28,93,1  ; n1757 t=404.774s dur=824ms, freq=349Hz, sample=69
; t 404.8204 Sustain 0 (Instr 1)
; t 404.8204 Sustain 0 (Instr 2)
    db 1,2,6,3,45,55,1,29,98,0  ; n1758 t=405.067s dur=774ms, freq=98Hz, sample=45
; t 405.2537 Sustain 127 (Instr 1)
; t 405.2537 Sustain 127 (Instr 2)
    db 17,0,7,3,69,55,1,30,74,1  ; n1759 t=405.580s dur=775ms, freq=330Hz, sample=69
; t 405.5945 Sustain 0 (Instr 1)
; t 405.5945 Sustain 0 (Instr 2)
    db 9,1,1,3,57,55,1,31,165,0  ; n1760 t=405.597s dur=769ms, freq=165Hz, sample=57
    db 3,2,35,3,45,55,1,0,104,0  ; n1761 t=405.862s dur=803ms, freq=104Hz, sample=45
; t 405.9879 Sustain 127 (Instr 1)
; t 405.9879 Sustain 127 (Instr 2)
; t 406.3054 Sustain 0 (Instr 1)
; t 406.3054 Sustain 0 (Instr 2)
    db 0,0,139,3,57,55,1,1,175,0  ; n1762 t=406.377s dur=907ms, sust 611->907, freq=175Hz, sample=57
    db 24,1,139,3,69,55,1,2,93,1  ; n1763 t=406.377s dur=907ms, sust 621->907, freq=349Hz, sample=69
    db 18,0,227,3,45,55,1,3,117,0  ; n1764 t=406.657s dur=995ms, freq=117Hz, sample=45
    db 84,2,84,4,45,55,1,4,139,0  ; n1765 t=406.675s dur=1108ms, freq=139Hz, sample=45
; t 406.7617 Sustain 127 (Instr 1)
; t 406.7617 Sustain 127 (Instr 2)
; t 406.8080 Soft 127 (Instr 1)
; t 406.8080 Soft 127 (Instr 2)
    db 19,0,7,4,69,38,1,5,114,1  ; n1766 t=407.271s dur=1031ms, vel 55->38, freq=370Hz, sample=69
; t 407.2843 Sustain 0 (Instr 1)
; t 407.2843 Sustain 0 (Instr 2)
    db 97,1,197,3,57,38,1,6,185,0  ; n1767 t=407.289s dur=965ms, vel 55->38, freq=185Hz, sample=57
    db 141,2,52,5,45,38,1,7,104,0  ; n1768 t=407.643s dur=1332ms, vel 55->38, sust 1026->1332, freq=104Hz, sample=45
    db 10,0,167,2,57,38,1,8,175,0  ; n1769 t=408.296s dur=679ms, vel 55->38, sust 472->679, freq=175Hz, sample=57
    db 68,1,156,2,69,38,1,9,93,1  ; n1770 t=408.306s dur=668ms, vel 55->38, sust 460->668, freq=349Hz, sample=69
    db 149,1,15,6,33,38,1,10,52,0  ; n1771 t=408.630s dur=1551ms, vel 55->38, sust 1182->1551, freq=52Hz, sample=33
; t 408.6606 Sustain 127 (Instr 1)
; t 408.6606 Sustain 127 (Instr 2)
; t 408.9749 Sustain 0 (Instr 1)
; t 408.9749 Sustain 0 (Instr 2)
    db 18,0,233,1,57,38,1,11,185,0  ; n1772 t=409.035s dur=489ms, vel 55->38, sust 231->489, freq=185Hz, sample=57
    db 196,1,216,1,69,38,1,12,114,1  ; n1773 t=409.053s dur=472ms, vel 55->38, sust 174->472, freq=370Hz, sample=69
; t 409.2094 Sustain 127 (Instr 1)
; t 409.2094 Sustain 127 (Instr 2)
    db 106,0,165,2,45,38,1,13,104,0  ; n1774 t=409.505s dur=677ms, vel 55->38, sust 423->677, freq=104Hz, sample=45
; t 409.5248 Sustain 0 (Instr 1)
; t 409.5248 Sustain 0 (Instr 2)
    db 5,0,58,2,45,38,1,14,131,0  ; n1775 t=409.611s dur=570ms, vel 55->38, sust 250->570, freq=131Hz, sample=45
    db 253,1,53,2,57,38,1,15,6,1  ; n1776 t=409.616s dur=565ms, vel 55->38, sust 201->565, freq=262Hz, sample=57
; t 409.7656 Sustain 127 (Instr 1)
; t 409.7656 Sustain 127 (Instr 2)
    db 86,0,88,2,33,38,1,16,69,0  ; n1777 t=410.125s dur=600ms, vel 55->38, sust 348->600, freq=69Hz, sample=33
; t 410.1818 Sustain 0 (Instr 1)
; t 410.1818 Sustain 0 (Instr 2)
    db 6,0,1,2,45,38,1,17,139,0  ; n1778 t=410.211s dur=513ms, vel 55->38, sust 224->513, freq=139Hz, sample=45
    db 197,4,251,1,57,38,1,18,21,1  ; n1779 t=410.217s dur=507ms, vel 55->38, sust 310->507, freq=277Hz, sample=57
; t 410.3772 Sustain 127 (Instr 1)
; t 410.3772 Sustain 127 (Instr 2)
; t 410.7251 Sustain 0 (Instr 1)
; t 410.7251 Sustain 0 (Instr 2)
    db 5,0,170,0,69,28,2,19,159,1  ; n1780 t=411.439s dur=170ms, vel 41->28, freq=415Hz, sample=69
    db 19,0,57,1,69,27,1,20,93,1  ; n1781 t=411.444s dur=313ms, vel 39->27, freq=349Hz, sample=69
; t 411.4513 Soft 0 (Instr 1)
; t 411.4513 Soft 0 (Instr 2)
    db 6,1,13,1,69,41,2,21,42,2  ; n1782 t=411.463s dur=269ms, freq=554Hz, sample=69
    db 24,0,242,1,69,45,2,22,159,1  ; n1783 t=411.725s dur=498ms, freq=415Hz, sample=69
    db 2,0,229,1,69,45,2,23,11,2  ; n1784 t=411.749s dur=485ms, freq=523Hz, sample=69
    db 215,1,247,1,57,43,1,24,55,1  ; n1785 t=411.751s dur=503ms, freq=311Hz, sample=57
    db 12,0,13,1,57,40,1,25,21,1  ; n1786 t=412.222s dur=269ms, freq=277Hz, sample=57
    db 1,0,43,1,69,43,2,26,210,1  ; n1787 t=412.233s dur=299ms, freq=466Hz, sample=69
    db 4,1,179,0,69,43,2,27,136,1  ; n1788 t=412.234s dur=179ms, freq=392Hz, sample=69
    db 19,0,112,0,69,41,2,28,159,1  ; n1789 t=412.494s dur=112ms, freq=415Hz, sample=69
    db 10,0,100,0,57,38,1,29,6,1  ; n1790 t=412.513s dur=100ms, freq=262Hz, sample=57
    db 205,1,76,0,69,40,2,30,110,2  ; n1791 t=412.523s dur=76ms, freq=622Hz, sample=69
    db 7,0,104,0,69,38,2,31,42,2  ; n1792 t=412.985s dur=104ms, freq=554Hz, sample=69
    db 5,0,87,0,45,33,1,0,139,0  ; n1793 t=412.992s dur=87ms, freq=139Hz, sample=45
    db 1,0,86,0,69,33,1,1,93,1  ; n1794 t=412.997s dur=86ms, freq=349Hz, sample=69
    db 239,0,74,0,57,33,1,2,233,0  ; n1795 t=412.998s dur=74ms, freq=233Hz, sample=57
    db 26,0,132,0,69,41,2,3,159,1  ; n1796 t=413.237s dur=132ms, freq=415Hz, sample=69
    db 3,0,99,0,57,37,1,4,55,1  ; n1797 t=413.263s dur=99ms, freq=311Hz, sample=57
    db 8,0,113,0,69,42,2,5,11,2  ; n1798 t=413.266s dur=113ms, freq=523Hz, sample=69
    db 226,1,99,0,45,37,1,6,156,0  ; n1799 t=413.275s dur=99ms, freq=156Hz, sample=45
    db 8,0,101,0,45,34,1,7,156,0  ; n1800 t=413.757s dur=101ms, freq=156Hz, sample=45
    db 4,0,125,0,57,34,1,8,21,1  ; n1801 t=413.765s dur=125ms, freq=277Hz, sample=57
    db 6,0,138,0,69,40,2,9,136,1  ; n1802 t=413.770s dur=138ms, freq=392Hz, sample=69
    db 231,0,138,0,69,40,2,10,210,1  ; n1803 t=413.776s dur=138ms, freq=466Hz, sample=69
    db 11,0,150,0,57,34,1,11,208,0  ; n1804 t=414.007s dur=150ms, freq=208Hz, sample=57
    db 14,0,132,0,69,38,2,12,159,1  ; n1805 t=414.018s dur=132ms, freq=415Hz, sample=69
    db 194,1,143,0,57,33,1,13,6,1  ; n1806 t=414.031s dur=143ms, freq=262Hz, sample=57
    db 0,0,224,0,81,42,2,14,228,2  ; n1807 t=414.481s dur=224ms, freq=740Hz, sample=81
    db 6,0,0,1,69,42,2,15,210,1  ; n1808 t=414.481s dur=256ms, freq=466Hz, sample=69
    db 253,0,162,0,69,42,2,16,42,2  ; n1809 t=414.487s dur=162ms, freq=554Hz, sample=69
    db 6,0,136,1,69,45,2,17,42,2  ; n1810 t=414.740s dur=392ms, freq=554Hz, sample=69
    db 6,0,192,1,81,45,2,18,186,2  ; n1811 t=414.747s dur=448ms, freq=698Hz, sample=81
    db 173,1,168,1,69,45,2,19,159,1  ; n1812 t=414.753s dur=424ms, freq=415Hz, sample=69
    db 17,0,19,1,69,33,1,20,114,1  ; n1813 t=415.182s dur=275ms, freq=370Hz, sample=69
    db 0,0,147,0,69,43,2,21,11,2  ; n1814 t=415.199s dur=147ms, freq=523Hz, sample=69
    db 10,1,25,1,69,43,2,22,110,2  ; n1815 t=415.199s dur=281ms, freq=622Hz, sample=69
    db 2,0,128,0,81,44,2,23,63,3  ; n1816 t=415.464s dur=128ms, freq=831Hz, sample=81
    db 11,0,70,0,69,33,1,24,93,1  ; n1817 t=415.466s dur=70ms, freq=349Hz, sample=69
    db 212,1,77,0,69,44,2,25,42,2  ; n1818 t=415.478s dur=77ms, freq=554Hz, sample=69
    db 48,0,164,0,57,33,1,26,185,0  ; n1819 t=415.945s dur=164ms, freq=185Hz, sample=57
    db 0,0,95,0,69,38,2,27,210,1  ; n1820 t=415.994s dur=95ms, freq=466Hz, sample=69
    db 2,0,152,0,81,38,2,28,228,2  ; n1821 t=415.994s dur=152ms, freq=740Hz, sample=81
    db 253,0,63,0,57,33,1,29,55,1  ; n1822 t=415.996s dur=63ms, freq=311Hz, sample=57
    db 6,0,125,0,69,42,2,30,159,1  ; n1823 t=416.249s dur=125ms, freq=415Hz, sample=69
    db 0,0,131,0,81,42,2,31,186,2  ; n1824 t=416.255s dur=131ms, freq=698Hz, sample=81
    db 2,0,136,0,69,42,2,0,42,2  ; n1825 t=416.255s dur=136ms, freq=554Hz, sample=69
    db 196,1,99,0,57,37,1,1,208,0  ; n1826 t=416.257s dur=99ms, freq=208Hz, sample=57
    db 23,0,155,0,57,33,1,2,208,0  ; n1827 t=416.709s dur=155ms, freq=208Hz, sample=57
    db 4,0,107,0,69,33,1,3,114,1  ; n1828 t=416.732s dur=107ms, freq=370Hz, sample=69
    db 1,0,125,0,69,38,2,4,110,2  ; n1829 t=416.736s dur=125ms, freq=622Hz, sample=69
    db 236,0,119,0,69,38,2,5,11,2  ; n1830 t=416.738s dur=119ms, freq=523Hz, sample=69
    db 0,0,219,1,69,33,1,6,93,1  ; n1831 t=416.974s dur=475ms, sust 111->475, freq=349Hz, sample=69
    db 3,0,219,1,57,33,1,7,21,1  ; n1832 t=416.974s dur=475ms, sust 129->475, freq=277Hz, sample=57
    db 203,1,216,1,69,38,2,8,42,2  ; n1833 t=416.977s dur=472ms, sust 162->472, freq=554Hz, sample=69
; t 416.9792 Sustain 127 (Instr 1)
; t 416.9792 Sustain 127 (Instr 2)
    db 0,0,109,0,57,34,1,9,208,0  ; n1834 t=417.436s dur=109ms, freq=208Hz, sample=57
    db 10,0,233,0,57,34,1,10,175,0  ; n1835 t=417.436s dur=233ms, freq=175Hz, sample=57
    db 15,0,175,1,69,45,2,11,42,2  ; n1836 t=417.447s dur=431ms, freq=554Hz, sample=69
; t 417.4498 Sustain 0 (Instr 1)
; t 417.4498 Sustain 0 (Instr 2)
    db 205,0,137,1,57,34,1,12,21,1  ; n1837 t=417.461s dur=393ms, freq=277Hz, sample=57
    db 7,0,192,1,45,37,1,13,156,0  ; n1838 t=417.666s dur=448ms, freq=156Hz, sample=45
    db 214,0,135,1,57,37,1,14,208,0  ; n1839 t=417.673s dur=391ms, freq=208Hz, sample=57
    db 2,0,175,0,69,42,2,15,11,2  ; n1840 t=417.888s dur=175ms, freq=523Hz, sample=69
    db 191,0,107,0,57,34,1,16,6,1  ; n1841 t=417.890s dur=107ms, freq=262Hz, sample=57
    db 13,0,119,0,45,33,1,17,139,0  ; n1842 t=418.081s dur=119ms, freq=139Hz, sample=45
    db 10,0,95,0,57,33,1,18,196,0  ; n1843 t=418.094s dur=95ms, freq=196Hz, sample=57
    db 10,0,252,0,69,45,2,19,210,1  ; n1844 t=418.104s dur=252ms, freq=466Hz, sample=69
    db 185,0,69,0,57,33,1,20,233,0  ; n1845 t=418.113s dur=69ms, freq=233Hz, sample=57
; t 418.1219 Soft 127 (Instr 1)
; t 418.1219 Soft 127 (Instr 2)
    db 6,0,76,0,45,25,1,21,131,0  ; n1846 t=418.298s dur=76ms, vel 36->25, freq=131Hz, sample=45
    db 31,0,76,0,57,25,1,22,6,1  ; n1847 t=418.305s dur=76ms, vel 36->25, freq=262Hz, sample=57
    db 206,0,192,0,57,25,1,23,55,1  ; n1848 t=418.336s dur=192ms, vel 36->25, freq=311Hz, sample=57
    db 187,0,186,0,69,32,2,24,110,2  ; n1849 t=418.542s dur=186ms, vel 46->32, freq=622Hz, sample=69
    db 30,0,108,0,45,24,1,25,139,0  ; n1850 t=418.729s dur=108ms, vel 35->24, freq=139Hz, sample=45
    db 3,0,70,0,57,25,1,26,233,0  ; n1851 t=418.759s dur=70ms, vel 36->25, freq=233Hz, sample=57
    db 2,0,24,1,69,40,2,27,42,2  ; n1852 t=418.762s dur=280ms, vel 58->40, freq=554Hz, sample=69
    db 222,0,23,1,69,25,1,28,93,1  ; n1853 t=418.765s dur=279ms, vel 36->25, freq=349Hz, sample=69
    db 21,0,78,0,45,27,1,29,156,0  ; n1854 t=418.986s dur=78ms, vel 39->27, freq=156Hz, sample=45
    db 16,0,98,0,57,27,1,30,55,1  ; n1855 t=419.007s dur=98ms, vel 39->27, freq=311Hz, sample=57
    db 191,0,224,0,69,26,2,31,159,1  ; n1856 t=419.023s dur=224ms, vel 38->26, freq=415Hz, sample=69
    db 175,0,169,0,69,28,2,0,11,2  ; n1857 t=419.214s dur=169ms, vel 41->28, freq=523Hz, sample=69
    db 1,0,151,0,45,23,1,1,156,0  ; n1858 t=419.389s dur=151ms, vel 34->23, freq=156Hz, sample=45
    db 40,0,118,0,57,23,1,2,21,1  ; n1859 t=419.390s dur=118ms, vel 34->23, freq=277Hz, sample=57
    db 1,0,73,2,69,30,2,3,210,1  ; n1860 t=419.430s dur=585ms, vel 44->30, sust 433->585, freq=466Hz, sample=69
    db 175,0,20,1,69,30,2,4,136,1  ; n1861 t=419.431s dur=276ms, vel 44->30, freq=392Hz, sample=69
    db 5,0,152,1,57,23,1,5,6,1  ; n1862 t=419.607s dur=408ms, vel 33->23, sust 158->408, freq=262Hz, sample=57
    db 193,0,147,1,57,23,1,6,208,0  ; n1863 t=419.612s dur=403ms, vel 33->23, sust 190->403, freq=208Hz, sample=57
; t 419.7244 Sustain 127 (Instr 1)
; t 419.7244 Sustain 127 (Instr 2)
    db 211,0,210,0,69,29,2,7,159,1  ; n1864 t=419.805s dur=210ms, vel 42->29, sust 168->210, freq=415Hz, sample=69
; t 420.0153 Sustain 0 (Instr 1)
; t 420.0153 Sustain 0 (Instr 2)
    db 0,0,125,0,57,25,1,8,21,1  ; n1865 t=420.016s dur=125ms, vel 36->25, freq=277Hz, sample=57
    db 18,0,131,0,57,25,1,9,233,0  ; n1866 t=420.016s dur=131ms, vel 36->25, freq=233Hz, sample=57
    db 4,0,96,1,69,25,1,10,114,1  ; n1867 t=420.034s dur=352ms, vel 36->25, freq=370Hz, sample=69
    db 187,0,68,1,81,36,2,11,228,2  ; n1868 t=420.038s dur=324ms, vel 52->36, freq=740Hz, sample=81
    db 6,0,90,1,57,26,1,12,21,1  ; n1869 t=420.225s dur=346ms, vel 38->26, freq=277Hz, sample=57
    db 192,0,123,1,57,26,1,13,208,0  ; n1870 t=420.232s dur=379ms, vel 38->26, freq=208Hz, sample=57
    db 5,0,160,0,81,34,2,14,186,2  ; n1871 t=420.424s dur=160ms, vel 49->34, freq=698Hz, sample=81
    db 190,0,130,0,69,25,1,15,93,1  ; n1872 t=420.429s dur=130ms, vel 37->25, freq=349Hz, sample=69
    db 0,0,150,0,57,27,1,16,6,1  ; n1873 t=420.619s dur=150ms, vel 39->27, freq=262Hz, sample=57
    db 28,0,175,0,57,27,1,17,185,0  ; n1874 t=420.619s dur=175ms, vel 39->27, freq=185Hz, sample=57
    db 15,0,186,0,69,36,2,18,110,2  ; n1875 t=420.647s dur=186ms, vel 52->36, freq=622Hz, sample=69
    db 117,0,76,0,57,28,1,19,55,1  ; n1876 t=420.662s dur=76ms, vel 40->28, freq=311Hz, sample=57
    db 31,0,70,0,57,26,1,20,175,0  ; n1877 t=420.779s dur=70ms, vel 38->26, freq=175Hz, sample=57
    db 29,0,73,0,69,26,1,21,93,1  ; n1878 t=420.810s dur=73ms, vel 38->26, freq=349Hz, sample=69
    db 194,0,217,0,69,35,2,22,159,1  ; n1879 t=420.840s dur=217ms, vel 50->35, freq=415Hz, sample=69
    db 195,0,244,0,81,35,2,23,63,3  ; n1880 t=421.034s dur=244ms, vel 50->35, freq=831Hz, sample=81
    db 21,0,102,0,57,25,1,24,185,0  ; n1881 t=421.229s dur=102ms, vel 36->25, freq=185Hz, sample=57
    db 14,0,45,1,81,37,2,25,228,2  ; n1882 t=421.250s dur=301ms, vel 53->37, freq=740Hz, sample=81
    db 2,0,200,0,69,37,2,26,210,1  ; n1883 t=421.264s dur=200ms, vel 53->37, freq=466Hz, sample=69
    db 205,0,76,0,57,25,1,27,55,1  ; n1884 t=421.266s dur=76ms, vel 37->25, freq=311Hz, sample=57
    db 1,0,106,0,69,26,2,28,159,1  ; n1885 t=421.471s dur=106ms, vel 38->26, freq=415Hz, sample=69
    db 21,0,114,0,57,28,1,29,208,0  ; n1886 t=421.472s dur=114ms, vel 40->28, freq=208Hz, sample=57
    db 174,0,221,0,69,26,2,30,42,2  ; n1887 t=421.493s dur=221ms, vel 38->26, freq=554Hz, sample=69
    db 225,0,232,0,81,28,2,31,186,2  ; n1888 t=421.667s dur=232ms, vel 41->28, freq=698Hz, sample=81
    db 6,0,198,0,57,25,1,0,208,0  ; n1889 t=421.892s dur=198ms, vel 36->25, freq=208Hz, sample=57
    db 15,0,178,0,69,25,1,1,114,1  ; n1890 t=421.898s dur=178ms, vel 36->25, freq=370Hz, sample=69
    db 8,0,177,1,69,30,2,2,110,2  ; n1891 t=421.913s dur=433ms, vel 44->30, freq=622Hz, sample=69
    db 191,0,236,0,69,30,2,3,11,2  ; n1892 t=421.921s dur=236ms, vel 44->30, freq=523Hz, sample=69
    db 13,0,11,1,57,25,1,4,21,1  ; n1893 t=422.112s dur=267ms, vel 37->25, freq=277Hz, sample=57
    db 176,0,180,0,69,25,1,5,93,1  ; n1894 t=422.125s dur=180ms, vel 36->25, freq=349Hz, sample=69
; t 422.1949 Soft 0 (Instr 1)
; t 422.1949 Soft 0 (Instr 2)
    db 231,0,138,0,69,39,2,6,42,2  ; n1895 t=422.301s dur=138ms, freq=554Hz, sample=69
    db 10,0,89,1,57,33,1,7,21,1  ; n1896 t=422.532s dur=345ms, freq=277Hz, sample=57
    db 1,0,254,0,69,39,2,8,42,2  ; n1897 t=422.542s dur=254ms, freq=554Hz, sample=69
    db 33,1,116,0,69,33,1,9,93,1  ; n1898 t=422.543s dur=116ms, freq=349Hz, sample=69
    db 55,0,53,2,57,37,1,10,233,0  ; n1899 t=422.832s dur=565ms, sust 340->565, freq=233Hz, sample=57
    db 3,0,255,1,69,38,1,11,93,1  ; n1900 t=422.887s dur=511ms, sust 69->511, freq=349Hz, sample=69
    db 223,1,252,1,69,43,2,12,42,2  ; n1901 t=422.890s dur=508ms, sust 268->508, freq=554Hz, sample=69
; t 422.9056 Sustain 127 (Instr 1)
; t 422.9056 Sustain 127 (Instr 2)
    db 48,0,255,0,57,33,1,13,208,0  ; n1902 t=423.368s dur=255ms, freq=208Hz, sample=57
; t 423.3979 Sustain 0 (Instr 1)
; t 423.3979 Sustain 0 (Instr 2)
    db 4,0,86,0,69,34,1,14,93,1  ; n1903 t=423.417s dur=86ms, freq=349Hz, sample=69
    db 195,0,162,0,69,39,2,15,42,2  ; n1904 t=423.421s dur=162ms, freq=554Hz, sample=69
    db 24,0,204,2,57,36,1,16,196,0  ; n1905 t=423.616s dur=716ms, sust 318->716, freq=196Hz, sample=57
    db 22,0,156,0,57,37,1,17,55,1  ; n1906 t=423.640s dur=156ms, freq=311Hz, sample=57
    db 238,0,194,0,69,42,2,18,42,2  ; n1907 t=423.662s dur=194ms, freq=554Hz, sample=69
    db 10,0,176,1,57,34,1,19,208,0  ; n1908 t=423.901s dur=432ms, sust 175->432, freq=208Hz, sample=57
    db 27,0,167,1,69,40,2,20,11,2  ; n1909 t=423.910s dur=423ms, sust 146->423, freq=523Hz, sample=69
; t 423.9238 Sustain 127 (Instr 1)
; t 423.9238 Sustain 127 (Instr 2)
    db 197,0,139,1,57,33,1,21,55,1  ; n1910 t=423.938s dur=395ms, sust 114->395, freq=311Hz, sample=57
    db 4,0,223,0,57,33,1,22,208,0  ; n1911 t=424.135s dur=223ms, freq=208Hz, sample=57
    db 16,0,205,0,69,38,2,23,238,1  ; n1912 t=424.139s dur=205ms, freq=494Hz, sample=69
    db 21,1,178,0,57,33,1,24,55,1  ; n1913 t=424.155s dur=178ms, sust 174->178, freq=311Hz, sample=57
; t 424.3332 Sustain 0 (Instr 1)
; t 424.3332 Sustain 0 (Instr 2)
    db 3,0,104,2,57,37,1,25,55,1  ; n1914 t=424.432s dur=616ms, sust 388->616, freq=311Hz, sample=57
    db 8,0,100,2,69,42,2,26,238,1  ; n1915 t=424.435s dur=612ms, sust 396->612, freq=494Hz, sample=69
    db 208,1,92,2,57,37,1,27,208,0  ; n1916 t=424.443s dur=604ms, sust 494->604, freq=208Hz, sample=57
; t 424.5862 Sustain 127 (Instr 1)
; t 424.5862 Sustain 127 (Instr 2)
    db 9,0,196,0,69,39,2,28,238,1  ; n1917 t=424.907s dur=196ms, freq=494Hz, sample=69
    db 5,0,131,0,57,34,1,29,55,1  ; n1918 t=424.917s dur=131ms, sust 89->131, freq=311Hz, sample=57
    db 173,0,219,0,57,34,1,30,185,0  ; n1919 t=424.922s dur=219ms, freq=185Hz, sample=57
; t 425.0480 Sustain 0 (Instr 1)
; t 425.0480 Sustain 0 (Instr 2)
    db 1,0,86,1,57,36,1,31,21,1  ; n1920 t=425.095s dur=342ms, sust 225->342, freq=277Hz, sample=57
    db 79,0,85,1,57,36,1,0,175,0  ; n1921 t=425.096s dur=341ms, sust 318->341, freq=175Hz, sample=57
    db 169,0,6,1,69,43,2,1,238,1  ; n1922 t=425.175s dur=262ms, sust 138->262, freq=494Hz, sample=69
; t 425.2190 Sustain 127 (Instr 1)
; t 425.2190 Sustain 127 (Instr 2)
    db 16,0,108,0,57,35,1,2,185,0  ; n1923 t=425.344s dur=108ms, freq=185Hz, sample=57
    db 2,0,177,0,69,40,2,3,210,1  ; n1924 t=425.360s dur=177ms, freq=466Hz, sample=69
    db 155,0,157,0,57,35,1,4,21,1  ; n1925 t=425.362s dur=157ms, freq=277Hz, sample=57
; t 425.4373 Sustain 0 (Instr 1)
; t 425.4373 Sustain 0 (Instr 2)
    db 90,0,75,1,57,33,1,5,185,0  ; n1926 t=425.517s dur=331ms, freq=185Hz, sample=57
    db 15,0,251,0,69,40,2,6,210,1  ; n1927 t=425.607s dur=251ms, freq=466Hz, sample=69
    db 192,0,140,0,57,33,1,7,21,1  ; n1928 t=425.622s dur=140ms, freq=277Hz, sample=57
    db 1,0,134,2,57,36,1,8,208,0  ; n1929 t=425.814s dur=646ms, sust 429->646, freq=208Hz, sample=57
    db 85,0,133,2,45,36,1,9,156,0  ; n1930 t=425.815s dur=645ms, sust 359->645, freq=156Hz, sample=45
    db 1,0,48,2,69,44,2,10,11,2  ; n1931 t=425.900s dur=560ms, sust 254->560, freq=523Hz, sample=69
    db 241,1,47,2,69,37,1,11,114,1  ; n1932 t=425.901s dur=559ms, sust 241->559, freq=370Hz, sample=69
; t 425.9305 Sustain 127 (Instr 1)
; t 425.9305 Sustain 127 (Instr 2)
    db 3,0,111,1,45,34,1,12,139,0  ; n1933 t=426.399s dur=367ms, freq=139Hz, sample=45
    db 3,0,124,1,69,45,2,13,42,2  ; n1934 t=426.402s dur=380ms, freq=554Hz, sample=69
    db 6,0,248,0,57,34,1,14,208,0  ; n1935 t=426.405s dur=248ms, freq=208Hz, sample=57
    db 71,1,22,1,69,34,1,15,93,1  ; n1936 t=426.411s dur=278ms, freq=349Hz, sample=69
; t 426.4604 Sustain 0 (Instr 1)
; t 426.4604 Sustain 0 (Instr 2)
    db 44,0,254,4,45,39,1,16,131,0  ; n1937 t=426.738s dur=1278ms, freq=131Hz, sample=45
    db 17,0,61,4,57,39,1,17,208,0  ; n1938 t=426.783s dur=1085ms, freq=208Hz, sample=57
    db 1,0,242,3,69,51,2,18,110,2  ; n1939 t=426.799s dur=1010ms, sust 592->1010, freq=622Hz, sample=69
    db 123,3,241,3,69,42,1,19,114,1  ; n1940 t=426.800s dur=1009ms, sust 592->1009, freq=370Hz, sample=69
; t 427.0511 Sustain 127 (Instr 1)
; t 427.0511 Sustain 127 (Instr 2)
    db 20,0,175,2,69,36,1,20,114,1  ; n1941 t=427.691s dur=687ms, freq=370Hz, sample=69
    db 78,1,236,2,57,37,1,21,55,1  ; n1942 t=427.711s dur=748ms, freq=311Hz, sample=57
; t 427.7877 Soft 127 (Instr 1)
; t 427.7877 Soft 127 (Instr 2)
; t 427.8098 Sustain 0 (Instr 1)
; t 427.8098 Sustain 0 (Instr 2)
    db 28,0,80,2,45,23,1,22,139,0  ; n1943 t=428.045s dur=592ms, vel 33->23, freq=139Hz, sample=45
    db 17,1,148,1,57,23,1,23,208,0  ; n1944 t=428.073s dur=404ms, vel 33->23, freq=208Hz, sample=57
    db 113,0,172,0,57,23,1,24,21,1  ; n1945 t=428.346s dur=172ms, vel 34->23, freq=277Hz, sample=57
    db 156,0,18,1,69,29,1,25,93,1  ; n1946 t=428.459s dur=274ms, vel 42->29, freq=349Hz, sample=69
    db 104,0,92,1,45,23,1,26,92,0  ; n1947 t=428.616s dur=348ms, vel 34->23, freq=92Hz, sample=45
    db 13,0,154,1,57,24,1,27,233,0  ; n1948 t=428.719s dur=410ms, vel 35->24, freq=233Hz, sample=57
    db 110,0,44,1,57,24,1,28,185,0  ; n1949 t=428.732s dur=300ms, vel 35->24, freq=185Hz, sample=57
    db 130,0,157,0,69,30,2,29,210,1  ; n1950 t=428.842s dur=157ms, vel 43->30, freq=466Hz, sample=69
    db 25,0,232,0,45,23,1,30,156,0  ; n1951 t=428.972s dur=232ms, vel 33->23, freq=156Hz, sample=45
    db 164,0,181,0,69,23,1,31,114,1  ; n1952 t=428.997s dur=181ms, vel 34->23, freq=370Hz, sample=69
    db 19,0,74,1,45,23,1,0,104,0  ; n1953 t=429.161s dur=330ms, vel 34->23, sust 302->330, freq=104Hz, sample=45
    db 64,0,63,1,57,23,1,1,208,0  ; n1954 t=429.180s dur=319ms, vel 34->23, freq=208Hz, sample=57
; t 429.2146 Sustain 127 (Instr 1)
; t 429.2146 Sustain 127 (Instr 2)
    db 2,0,247,0,69,26,1,2,93,1  ; n1955 t=429.244s dur=247ms, vel 38->26, sust 242->247, freq=349Hz, sample=69
    db 239,0,245,0,57,26,1,3,21,1  ; n1956 t=429.246s dur=245ms, vel 38->26, sust 210->245, freq=277Hz, sample=57
    db 6,0,75,0,57,28,1,4,6,1  ; n1957 t=429.485s dur=75ms, vel 40->28, freq=262Hz, sample=57
    db 217,0,89,0,57,28,1,5,55,1  ; n1958 t=429.491s dur=89ms, vel 40->28, freq=311Hz, sample=57
; t 429.4915 Sustain 0 (Instr 1)
; t 429.4915 Sustain 0 (Instr 2)
    db 5,0,166,0,57,26,1,6,175,0  ; n1959 t=429.709s dur=166ms, vel 38->26, freq=175Hz, sample=57
    db 17,0,102,0,57,26,1,7,208,0  ; n1960 t=429.714s dur=102ms, vel 38->26, freq=208Hz, sample=57
    db 2,0,230,0,69,30,2,8,42,2  ; n1961 t=429.731s dur=230ms, vel 43->30, freq=554Hz, sample=69
    db 210,0,248,0,57,27,1,9,21,1  ; n1962 t=429.733s dur=248ms, vel 39->27, freq=277Hz, sample=57
    db 19,0,207,1,45,29,1,10,156,0  ; n1963 t=429.942s dur=463ms, vel 42->29, freq=156Hz, sample=45
    db 55,0,179,1,57,29,1,11,208,0  ; n1964 t=429.961s dur=435ms, vel 42->29, sust 403->435, freq=208Hz, sample=57
    db 3,0,123,1,57,28,1,12,6,1  ; n1965 t=430.017s dur=379ms, vel 41->28, sust 340->379, freq=262Hz, sample=57
    db 145,1,120,1,69,31,2,13,11,2  ; n1966 t=430.020s dur=376ms, vel 45->31, sust 329->376, freq=523Hz, sample=69
; t 430.0967 Sustain 127 (Instr 1)
; t 430.0967 Sustain 127 (Instr 2)
; t 430.3966 Sustain 0 (Instr 1)
; t 430.3966 Sustain 0 (Instr 2)
    db 1,0,30,1,69,29,2,14,210,1  ; n1967 t=430.421s dur=286ms, vel 42->29, freq=466Hz, sample=69
    db 6,0,163,0,57,26,1,15,196,0  ; n1968 t=430.422s dur=163ms, vel 38->26, freq=196Hz, sample=57
    db 0,0,81,0,57,26,1,16,233,0  ; n1969 t=430.428s dur=81ms, vel 38->26, freq=233Hz, sample=57
    db 210,0,150,0,45,26,1,17,139,0  ; n1970 t=430.428s dur=150ms, vel 38->26, freq=139Hz, sample=45
    db 37,0,89,0,45,25,1,18,131,0  ; n1971 t=430.638s dur=89ms, vel 37->25, freq=131Hz, sample=45
    db 25,0,101,0,57,25,1,19,6,1  ; n1972 t=430.675s dur=101ms, vel 37->25, freq=262Hz, sample=57
    db 11,0,81,0,57,25,1,20,55,1  ; n1973 t=430.700s dur=81ms, vel 37->25, freq=311Hz, sample=57
    db 135,1,64,0,69,30,2,21,110,2  ; n1974 t=430.710s dur=64ms, vel 43->30, freq=622Hz, sample=69
    db 37,0,112,0,45,25,1,22,139,0  ; n1975 t=431.101s dur=112ms, vel 37->25, freq=139Hz, sample=45
    db 4,0,69,0,57,25,1,23,233,0  ; n1976 t=431.138s dur=69ms, vel 37->25, freq=233Hz, sample=57
    db 7,0,97,1,69,30,2,24,42,2  ; n1977 t=431.142s dur=353ms, vel 43->30, freq=554Hz, sample=69
    db 191,0,198,0,69,25,1,25,93,1  ; n1978 t=431.150s dur=198ms, vel 37->25, freq=349Hz, sample=69
    db 18,0,88,0,45,26,1,26,156,0  ; n1979 t=431.341s dur=88ms, vel 38->26, freq=156Hz, sample=45
    db 7,0,230,0,69,28,2,27,159,1  ; n1980 t=431.358s dur=230ms, vel 41->28, freq=415Hz, sample=69
    db 190,0,94,0,57,25,1,28,55,1  ; n1981 t=431.366s dur=94ms, vel 37->25, freq=311Hz, sample=57
    db 179,0,199,0,69,27,2,29,11,2  ; n1982 t=431.556s dur=199ms, vel 39->27, freq=523Hz, sample=69
    db 1,0,151,0,45,23,1,30,156,0  ; n1983 t=431.735s dur=151ms, vel 33->23, freq=156Hz, sample=45
    db 22,0,113,0,57,23,1,31,21,1  ; n1984 t=431.736s dur=113ms, vel 33->23, freq=277Hz, sample=57
    db 8,0,178,1,69,29,2,0,210,1  ; n1985 t=431.758s dur=434ms, vel 42->29, freq=466Hz, sample=69
    db 167,0,205,0,69,29,2,1,136,1  ; n1986 t=431.767s dur=205ms, vel 42->29, freq=392Hz, sample=69
    db 6,0,113,0,57,24,1,2,6,1  ; n1987 t=431.933s dur=113ms, vel 35->24, freq=262Hz, sample=57
    db 201,0,144,0,57,24,1,3,208,0  ; n1988 t=431.940s dur=144ms, vel 35->24, freq=208Hz, sample=57
    db 178,0,156,0,69,26,2,4,159,1  ; n1989 t=432.141s dur=156ms, vel 38->26, freq=415Hz, sample=69
    db 14,0,17,1,57,23,1,5,233,0  ; n1990 t=432.319s dur=273ms, vel 34->23, freq=233Hz, sample=57
    db 13,0,131,0,57,23,1,6,21,1  ; n1991 t=432.333s dur=131ms, vel 34->23, freq=277Hz, sample=57
    db 17,0,216,0,69,23,1,7,114,1  ; n1992 t=432.346s dur=216ms, vel 34->23, freq=370Hz, sample=69
; t 432.3580 Soft 0 (Instr 1)
; t 432.3580 Soft 0 (Instr 2)
    db 187,0,194,0,81,48,2,8,228,2  ; n1993 t=432.362s dur=194ms, freq=740Hz, sample=81
    db 12,0,211,1,57,37,1,9,208,0  ; n1994 t=432.549s dur=467ms, freq=208Hz, sample=57
    db 48,0,143,1,57,37,1,10,21,1  ; n1995 t=432.560s dur=399ms, sust 369->399, freq=277Hz, sample=57
    db 25,0,95,1,81,47,2,11,186,2  ; n1996 t=432.609s dur=351ms, sust 312->351, freq=698Hz, sample=81
    db 88,1,70,1,69,38,1,12,93,1  ; n1997 t=432.634s dur=326ms, sust 270->326, freq=349Hz, sample=69
; t 432.6915 Sustain 127 (Instr 1)
; t 432.6915 Sustain 127 (Instr 2)
; t 432.9599 Sustain 0 (Instr 1)
; t 432.9599 Sustain 0 (Instr 2)
    db 4,0,108,0,57,36,1,13,6,1  ; n1998 t=432.978s dur=108ms, freq=262Hz, sample=57
    db 13,0,188,0,57,36,1,14,185,0  ; n1999 t=432.982s dur=188ms, freq=185Hz, sample=57
    db 14,0,166,0,69,42,2,15,110,2  ; n2000 t=432.995s dur=166ms, freq=622Hz, sample=69
    db 153,0,117,0,57,37,1,16,55,1  ; n2001 t=433.008s dur=117ms, freq=311Hz, sample=57
    db 18,0,181,1,57,39,1,17,175,0  ; n2002 t=433.161s dur=437ms, sust 221->437, freq=175Hz, sample=57
    db 46,0,163,1,57,39,1,18,21,1  ; n2003 t=433.179s dur=419ms, sust 204->419, freq=277Hz, sample=57
    db 9,0,117,1,81,47,2,19,63,3  ; n2004 t=433.225s dur=373ms, sust 199->373, freq=831Hz, sample=81
    db 136,1,107,1,69,47,2,20,159,1  ; n2005 t=433.235s dur=363ms, sust 184->363, freq=415Hz, sample=69
; t 433.2660 Sustain 127 (Instr 1)
; t 433.2660 Sustain 127 (Instr 2)
; t 433.5984 Sustain 0 (Instr 1)
; t 433.5984 Sustain 0 (Instr 2)
    db 5,0,137,0,57,39,1,21,233,0  ; n2006 t=433.627s dur=137ms, freq=233Hz, sample=57
    db 1,0,158,1,69,39,1,22,114,1  ; n2007 t=433.632s dur=414ms, sust 305->414, freq=370Hz, sample=69
    db 4,0,88,0,57,39,1,23,21,1  ; n2008 t=433.633s dur=88ms, freq=277Hz, sample=57
    db 180,0,152,1,81,52,2,24,228,2  ; n2009 t=433.637s dur=408ms, sust 300->408, freq=740Hz, sample=81
; t 433.8144 Sustain 127 (Instr 1)
; t 433.8144 Sustain 127 (Instr 2)
    db 1,0,178,1,57,42,1,25,208,0  ; n2010 t=433.817s dur=434ms, freq=208Hz, sample=57
    db 183,0,40,1,57,42,1,26,21,1  ; n2011 t=433.819s dur=296ms, freq=277Hz, sample=57
    db 12,0,125,0,69,40,1,27,93,1  ; n2012 t=434.002s dur=125ms, freq=349Hz, sample=69
    db 178,0,130,0,81,52,2,28,186,2  ; n2013 t=434.015s dur=130ms, freq=698Hz, sample=81
; t 434.0461 Sustain 0 (Instr 1)
; t 434.0461 Sustain 0 (Instr 2)
    db 19,0,108,0,57,37,1,29,185,0  ; n2014 t=434.193s dur=108ms, freq=185Hz, sample=57
    db 22,0,174,0,57,37,1,30,6,1  ; n2015 t=434.212s dur=174ms, freq=262Hz, sample=57
    db 1,0,108,0,69,51,2,31,110,2  ; n2016 t=434.234s dur=108ms, freq=622Hz, sample=69
    db 110,0,90,0,57,37,1,0,55,1  ; n2017 t=434.235s dur=90ms, freq=311Hz, sample=57
    db 50,0,144,1,57,38,1,1,175,0  ; n2018 t=434.345s dur=400ms, sust 212->400, freq=175Hz, sample=57
    db 6,0,94,1,57,39,1,2,21,1  ; n2019 t=434.395s dur=350ms, sust 206->350, freq=277Hz, sample=57
    db 12,0,87,1,69,54,2,3,159,1  ; n2020 t=434.401s dur=343ms, sust 262->343, freq=415Hz, sample=69
    db 135,1,76,1,81,54,2,4,63,3  ; n2021 t=434.413s dur=332ms, sust 243->332, freq=831Hz, sample=81
; t 434.5106 Sustain 127 (Instr 1)
; t 434.5106 Sustain 127 (Instr 2)
; t 434.7454 Sustain 0 (Instr 1)
; t 434.7454 Sustain 0 (Instr 2)
    db 13,0,130,1,69,44,1,5,114,1  ; n2022 t=434.804s dur=386ms, sust 300->386, freq=370Hz, sample=69
    db 5,0,113,0,57,45,1,6,233,0  ; n2023 t=434.817s dur=113ms, freq=233Hz, sample=57
    db 5,0,90,0,57,45,1,7,21,1  ; n2024 t=434.822s dur=90ms, freq=277Hz, sample=57
    db 151,0,107,1,81,62,2,8,228,2  ; n2025 t=434.827s dur=363ms, sust 278->363, freq=740Hz, sample=81
; t 434.9562 Sustain 127 (Instr 1)
; t 434.9562 Sustain 127 (Instr 2)
    db 7,0,128,1,57,47,1,9,208,0  ; n2026 t=434.978s dur=384ms, freq=208Hz, sample=57
    db 198,0,34,1,57,47,1,10,21,1  ; n2027 t=434.986s dur=290ms, freq=277Hz, sample=57
    db 3,0,94,1,69,49,1,11,93,1  ; n2028 t=435.184s dur=350ms, sust 238->350, freq=349Hz, sample=69
    db 136,0,91,1,81,61,2,12,186,2  ; n2029 t=435.187s dur=347ms, sust 279->347, freq=698Hz, sample=81
; t 435.1910 Sustain 0 (Instr 1)
; t 435.1910 Sustain 0 (Instr 2)
    db 81,0,63,3,57,58,1,13,196,0  ; n2030 t=435.323s dur=831ms, freq=196Hz, sample=57
; t 435.3797 Sustain 127 (Instr 1)
; t 435.3797 Sustain 127 (Instr 2)
    db 48,0,16,2,57,60,1,14,21,1  ; n2031 t=435.404s dur=528ms, freq=277Hz, sample=57
    db 121,0,18,2,69,60,1,15,74,1  ; n2032 t=435.452s dur=530ms, freq=330Hz, sample=69
; t 435.5339 Sustain 0 (Instr 1)
; t 435.5339 Sustain 0 (Instr 2)
    db 12,0,61,5,69,70,2,16,210,1  ; n2033 t=435.573s dur=1341ms, sust 1240->1341, freq=466Hz, sample=69
    db 78,2,50,5,81,70,2,17,164,3  ; n2034 t=435.584s dur=1330ms, sust 1309->1330, freq=932Hz, sample=81
    db 5,0,59,4,57,40,1,18,208,0  ; n2035 t=436.175s dur=1083ms, freq=208Hz, sample=57
    db 2,0,210,3,69,40,1,19,93,1  ; n2036 t=436.180s dur=978ms, freq=349Hz, sample=69
    db 210,2,39,4,57,40,1,20,21,1  ; n2037 t=436.182s dur=1063ms, freq=277Hz, sample=57
; t 436.6534 Sustain 127 (Instr 1)
; t 436.6534 Sustain 127 (Instr 2)
    db 12,0,67,1,69,40,2,21,159,1  ; n2038 t=436.904s dur=323ms, freq=415Hz, sample=69
; t 436.9144 Sustain 0 (Instr 1)
; t 436.9144 Sustain 0 (Instr 2)
    db 227,2,42,1,81,40,2,22,63,3  ; n2039 t=436.916s dur=298ms, freq=831Hz, sample=81
; t 436.9217 Soft 127 (Instr 1)
; t 436.9217 Soft 127 (Instr 2)
    db 42,0,149,5,33,23,1,23,52,0  ; n2040 t=437.654s dur=1429ms, vel 34->23, freq=52Hz, sample=33
    db 130,0,37,14,45,24,1,24,104,0  ; n2041 t=437.696s dur=3621ms, vel 35->24, sust 1978->3621, freq=104Hz, sample=45
    db 55,0,135,4,57,25,1,25,185,0  ; n2042 t=437.826s dur=1159ms, vel 37->25, freq=185Hz, sample=57
    db 99,3,155,3,57,25,1,26,6,1  ; n2043 t=437.881s dur=923ms, vel 37->25, freq=262Hz, sample=57
    db 230,0,225,0,57,26,1,27,55,1  ; n2044 t=438.747s dur=225ms, vel 38->26, freq=311Hz, sample=57
    db 141,0,18,1,57,24,1,28,21,1  ; n2045 t=438.977s dur=274ms, vel 35->24, freq=277Hz, sample=57
    db 241,0,151,8,33,23,1,29,69,0  ; n2046 t=439.118s dur=2199ms, vel 34->23, sust 562->2199, freq=69Hz, sample=33
    db 7,0,166,7,57,23,1,30,175,0  ; n2047 t=439.360s dur=1958ms, vel 34->23, sust 320->1958, freq=175Hz, sample=57
    db 0,0,158,7,57,23,1,31,21,1  ; n2048 t=439.367s dur=1950ms, vel 34->23, sust 327->1950, freq=277Hz, sample=57
; t 439.3867 Sustain 127 (Instr 2)
; t 439.3930 Sustain 127 (Instr 1)
; t 439.4255 Soft 0 (Instr 2)
; t 439.4318 Soft 0 (Instr 1)
; t 441.3177 Sustain 0 (Instr 1)
; t 441.3649 Sustain 0 (Instr 2)
    db 255,255,255,255,255,255,255,255,255,255  ; End marker

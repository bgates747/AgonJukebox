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

total_notes: equ 4056
midi_data:
    db 0,0,23,3,58,125,5,0,233,0,58,5  ; n1 t=2.330s dur=791ms, freq=233Hz, sample=58, buffer_id=05:3A
    db 0,0,93,24,82,125,8,1,164,3,82,8  ; n2 t=2.330s dur=6237ms, freq=932Hz, sample=82, buffer_id=08:52
    db 0,0,100,0,62,108,9,2,38,1,62,8  ; n3 t=2.330s dur=100ms, freq=294Hz, sample=62, buffer_id=08:3E
    db 0,0,178,3,70,108,9,3,210,1,70,8  ; n4 t=2.330s dur=946ms, freq=466Hz, sample=70, buffer_id=08:46
    db 0,0,189,2,47,108,9,4,117,0,47,8  ; n5 t=2.330s dur=701ms, freq=117Hz, sample=47, buffer_id=08:2F
    db 24,0,92,4,31,108,9,5,58,0,31,8  ; n6 t=2.330s dur=1116ms, freq=58Hz, sample=31, buffer_id=08:1F
    db 0,0,119,2,53,125,8,6,175,0,53,8  ; n7 t=2.354s dur=631ms, freq=175Hz, sample=53, buffer_id=08:35
    db 68,0,100,0,62,125,8,7,38,1,62,8  ; n8 t=2.354s dur=100ms, freq=294Hz, sample=62, buffer_id=08:3E
    db 244,1,252,23,94,125,8,8,73,7,94,8  ; n9 t=2.422s dur=6140ms, freq=1865Hz, sample=94, buffer_id=08:5E
    db 26,1,23,3,58,126,3,2,233,0,58,3  ; n10 t=2.922s dur=791ms, freq=233Hz, sample=58, buffer_id=03:3A
    db 78,0,100,0,58,125,5,6,233,0,58,5  ; n11 t=3.204s dur=100ms, freq=233Hz, sample=58, buffer_id=05:3A
    db 78,0,100,0,58,125,5,4,233,0,58,5  ; n12 t=3.282s dur=100ms, freq=233Hz, sample=58, buffer_id=05:3A
    db 78,0,100,0,58,125,5,7,233,0,58,5  ; n13 t=3.359s dur=100ms, freq=233Hz, sample=58, buffer_id=05:3A
    db 68,0,100,0,58,125,5,9,233,0,58,5  ; n14 t=3.437s dur=100ms, freq=233Hz, sample=58, buffer_id=05:3A
    db 35,1,191,2,58,125,5,3,233,0,58,5  ; n15 t=3.505s dur=703ms, freq=233Hz, sample=58, buffer_id=05:3A
    db 35,1,106,0,58,126,3,0,233,0,58,3  ; n16 t=3.796s dur=106ms, freq=233Hz, sample=58, buffer_id=03:3A
    db 194,0,121,0,58,126,3,4,233,0,58,3  ; n17 t=4.087s dur=121ms, freq=233Hz, sample=58, buffer_id=03:3A
    db 87,0,100,0,58,126,3,5,233,0,58,3  ; n18 t=4.282s dur=100ms, freq=233Hz, sample=58, buffer_id=03:3A
    db 78,0,100,0,58,125,5,0,233,0,58,5  ; n19 t=4.369s dur=100ms, freq=233Hz, sample=58, buffer_id=05:3A
    db 29,0,100,0,58,125,5,2,233,0,58,5  ; n20 t=4.447s dur=100ms, freq=233Hz, sample=58, buffer_id=05:3A
    db 49,0,100,0,58,126,3,3,233,0,58,3  ; n21 t=4.476s dur=100ms, freq=233Hz, sample=58, buffer_id=03:3A
    db 78,0,100,0,58,125,5,4,233,0,58,5  ; n22 t=4.524s dur=100ms, freq=233Hz, sample=58, buffer_id=05:3A
    db 68,0,100,0,58,125,5,5,233,0,58,5  ; n23 t=4.602s dur=100ms, freq=233Hz, sample=58, buffer_id=05:3A
    db 0,0,201,2,58,126,3,0,233,0,58,3  ; n24 t=4.670s dur=713ms, freq=233Hz, sample=58, buffer_id=03:3A
    db 184,0,100,0,58,125,5,10,233,0,58,5  ; n25 t=4.670s dur=100ms, freq=233Hz, sample=58, buffer_id=05:3A
    db 73,0,100,0,53,125,5,2,175,0,53,5  ; n26 t=4.854s dur=100ms, freq=175Hz, sample=53, buffer_id=05:35
    db 73,0,100,0,70,126,4,3,210,1,70,4  ; n27 t=4.927s dur=100ms, freq=466Hz, sample=70, buffer_id=04:46
    db 48,0,100,0,70,126,4,4,210,1,70,4  ; n28 t=5.000s dur=100ms, freq=466Hz, sample=70, buffer_id=04:46
    db 24,0,100,0,58,125,5,11,233,0,58,5  ; n29 t=5.048s dur=100ms, freq=233Hz, sample=58, buffer_id=05:3A
    db 73,0,100,0,70,126,4,5,210,1,70,4  ; n30 t=5.073s dur=100ms, freq=466Hz, sample=70, buffer_id=04:46
    db 78,0,100,0,70,126,4,6,210,1,70,4  ; n31 t=5.146s dur=100ms, freq=466Hz, sample=70, buffer_id=04:46
    db 10,0,100,0,70,126,4,2,210,1,70,4  ; n32 t=5.223s dur=100ms, freq=466Hz, sample=70, buffer_id=04:46
    db 180,0,100,0,63,125,5,3,93,1,63,5  ; n33 t=5.233s dur=100ms, freq=349Hz, sample=63, buffer_id=05:3F
    db 15,0,100,0,65,126,4,4,93,1,65,4  ; n34 t=5.413s dur=100ms, freq=349Hz, sample=65, buffer_id=04:41
    db 141,0,100,0,63,125,5,5,55,1,63,5  ; n35 t=5.427s dur=100ms, freq=311Hz, sample=63, buffer_id=05:3F
    db 29,0,100,0,65,126,3,2,93,1,65,3  ; n36 t=5.568s dur=100ms, freq=349Hz, sample=65, buffer_id=03:41
    db 10,0,100,0,75,126,4,0,110,2,75,4  ; n37 t=5.597s dur=100ms, freq=622Hz, sample=75, buffer_id=04:4B
    db 199,0,100,0,58,125,5,3,233,0,58,5  ; n38 t=5.607s dur=100ms, freq=233Hz, sample=58, buffer_id=05:3A
    db 0,0,100,0,77,126,4,4,186,2,77,4  ; n39 t=5.806s dur=100ms, freq=698Hz, sample=77, buffer_id=04:4D
    db 39,0,100,0,58,125,5,5,233,0,58,5  ; n40 t=5.806s dur=100ms, freq=233Hz, sample=58, buffer_id=05:3A
    db 5,0,119,2,70,126,3,6,210,1,70,3  ; n41 t=5.845s dur=631ms, freq=466Hz, sample=70, buffer_id=03:46
    db 141,0,229,1,65,126,3,7,93,1,65,3  ; n42 t=5.849s dur=485ms, freq=349Hz, sample=65, buffer_id=03:41
    db 10,0,100,0,53,125,5,0,175,0,53,5  ; n43 t=5.990s dur=100ms, freq=175Hz, sample=53, buffer_id=05:35
    db 184,0,100,0,75,126,4,2,110,2,75,4  ; n44 t=6.000s dur=100ms, freq=622Hz, sample=75, buffer_id=04:4B
    db 10,0,100,0,70,126,4,3,210,1,70,4  ; n45 t=6.184s dur=100ms, freq=466Hz, sample=70, buffer_id=04:46
    db 199,0,100,0,63,125,5,4,55,1,63,5  ; n46 t=6.194s dur=100ms, freq=311Hz, sample=63, buffer_id=05:3F
    db 0,0,100,0,70,126,4,0,210,1,70,4  ; n47 t=6.393s dur=100ms, freq=466Hz, sample=70, buffer_id=04:46
    db 15,0,100,0,63,125,5,2,93,1,63,5  ; n48 t=6.393s dur=100ms, freq=349Hz, sample=63, buffer_id=05:3F
    db 170,0,100,0,63,126,3,5,55,1,63,3  ; n49 t=6.408s dur=100ms, freq=311Hz, sample=63, buffer_id=03:3F
    db 14,0,100,0,65,126,4,3,93,1,65,4  ; n50 t=6.578s dur=100ms, freq=349Hz, sample=65, buffer_id=04:41
    db 19,0,100,0,58,125,5,4,233,0,58,5  ; n51 t=6.592s dur=100ms, freq=233Hz, sample=58, buffer_id=05:3A
    db 5,0,100,0,69,126,3,7,159,1,69,3  ; n52 t=6.612s dur=100ms, freq=415Hz, sample=69, buffer_id=03:45
    db 73,0,100,0,63,126,3,9,55,1,63,3  ; n53 t=6.617s dur=100ms, freq=311Hz, sample=63, buffer_id=03:3F
    db 82,0,100,0,58,125,5,6,233,0,58,5  ; n54 t=6.689s dur=100ms, freq=233Hz, sample=58, buffer_id=05:3A
    db 0,0,100,0,75,126,4,0,110,2,75,4  ; n55 t=6.772s dur=100ms, freq=622Hz, sample=75, buffer_id=04:4B
    db 24,0,100,0,58,125,5,2,233,0,58,5  ; n56 t=6.772s dur=100ms, freq=233Hz, sample=58, buffer_id=05:3A
    db 10,0,100,0,69,126,3,5,159,1,69,3  ; n57 t=6.796s dur=100ms, freq=415Hz, sample=69, buffer_id=03:45
    db 170,0,100,0,63,126,3,10,55,1,63,3  ; n58 t=6.806s dur=100ms, freq=311Hz, sample=63, buffer_id=03:3F
    db 5,0,100,0,63,125,5,3,55,1,63,5  ; n59 t=6.976s dur=100ms, freq=311Hz, sample=63, buffer_id=05:3F
    db 14,0,100,0,77,126,4,4,186,2,77,4  ; n60 t=6.981s dur=100ms, freq=698Hz, sample=77, buffer_id=04:4D
    db 0,0,100,0,70,126,3,6,210,1,70,3  ; n61 t=6.995s dur=100ms, freq=466Hz, sample=70, buffer_id=03:46
    db 24,0,239,1,63,126,3,7,55,1,63,3  ; n62 t=6.995s dur=495ms, freq=311Hz, sample=63, buffer_id=03:3F
    db 146,0,100,0,51,125,5,9,156,0,51,5  ; n63 t=7.019s dur=100ms, freq=156Hz, sample=51, buffer_id=05:33
    db 10,0,100,0,58,125,5,0,233,0,58,5  ; n64 t=7.165s dur=100ms, freq=233Hz, sample=58, buffer_id=05:3A
    db 19,0,100,0,75,126,4,2,110,2,75,4  ; n65 t=7.175s dur=100ms, freq=622Hz, sample=75, buffer_id=04:4B
    db 5,0,131,0,48,125,5,5,117,0,48,5  ; n66 t=7.194s dur=131ms, freq=117Hz, sample=48, buffer_id=05:30
    db 155,0,100,0,70,126,3,10,210,1,70,3  ; n67 t=7.199s dur=100ms, freq=466Hz, sample=70, buffer_id=03:46
    db 5,0,100,0,70,126,4,3,210,1,70,4  ; n68 t=7.354s dur=100ms, freq=466Hz, sample=70, buffer_id=04:46
    db 15,0,100,0,63,125,5,4,93,1,63,5  ; n69 t=7.359s dur=100ms, freq=349Hz, sample=63, buffer_id=05:3F
    db 14,0,100,0,70,126,3,9,210,1,70,3  ; n70 t=7.374s dur=100ms, freq=466Hz, sample=70, buffer_id=03:46
    db 170,0,100,0,53,125,5,6,175,0,53,5  ; n71 t=7.388s dur=100ms, freq=175Hz, sample=53, buffer_id=05:35
    db 15,0,100,0,70,126,4,0,210,1,70,4  ; n72 t=7.558s dur=100ms, freq=466Hz, sample=70, buffer_id=04:46
    db 15,0,97,4,69,125,5,2,159,1,69,5  ; n73 t=7.573s dur=1121ms, freq=415Hz, sample=69, buffer_id=05:45
    db 10,0,232,3,70,126,3,5,210,1,70,3  ; n74 t=7.587s dur=1000ms, freq=466Hz, sample=70, buffer_id=03:46
    db 24,0,100,0,63,126,3,10,55,1,63,3  ; n75 t=7.597s dur=100ms, freq=311Hz, sample=63, buffer_id=03:3F
    db 131,0,242,3,55,125,5,11,208,0,55,5  ; n76 t=7.621s dur=1010ms, freq=208Hz, sample=55, buffer_id=05:37
    db 44,0,100,0,65,126,4,3,93,1,65,4  ; n77 t=7.752s dur=100ms, freq=349Hz, sample=65, buffer_id=04:41
    db 155,0,100,0,63,126,3,4,55,1,63,3  ; n78 t=7.796s dur=100ms, freq=311Hz, sample=63, buffer_id=03:3F
    db 34,0,100,0,75,126,4,0,110,2,75,4  ; n79 t=7.952s dur=100ms, freq=622Hz, sample=75, buffer_id=04:4B
    db 170,0,100,0,63,126,3,6,55,1,63,3  ; n80 t=7.985s dur=100ms, freq=311Hz, sample=63, buffer_id=03:3F
    db 19,0,100,0,77,126,4,3,186,2,77,4  ; n81 t=8.155s dur=100ms, freq=698Hz, sample=77, buffer_id=04:4D
    db 199,0,108,1,63,126,3,9,55,1,63,3  ; n82 t=8.175s dur=364ms, freq=311Hz, sample=63, buffer_id=03:3F
    db 78,0,100,0,70,126,4,0,210,1,70,4  ; n83 t=8.374s dur=100ms, freq=466Hz, sample=70, buffer_id=04:46
    db 150,0,100,0,70,126,4,4,210,1,70,4  ; n84 t=8.451s dur=100ms, freq=466Hz, sample=70, buffer_id=04:46
    db 222,0,100,0,70,126,4,3,210,1,70,4  ; n85 t=8.602s dur=100ms, freq=466Hz, sample=70, buffer_id=04:46
    db 26,0,100,0,82,125,8,0,112,3,82,8  ; n86 t=8.824s dur=100ms, freq=880Hz, sample=82, buffer_id=08:52
    db 4,0,100,0,65,126,4,1,93,1,65,4  ; n87 t=8.850s dur=100ms, freq=349Hz, sample=65, buffer_id=04:41
    db 22,0,134,0,57,126,4,4,220,0,57,4  ; n88 t=8.854s dur=134ms, freq=220Hz, sample=57, buffer_id=04:39
    db 0,0,100,0,65,126,4,5,93,1,65,4  ; n89 t=8.876s dur=100ms, freq=349Hz, sample=65, buffer_id=04:41
    db 4,0,153,0,58,125,5,6,233,0,58,5  ; n90 t=8.876s dur=153ms, freq=233Hz, sample=58, buffer_id=05:3A
    db 19,0,134,0,53,125,5,7,175,0,53,5  ; n91 t=8.880s dur=134ms, freq=175Hz, sample=53, buffer_id=05:35
    db 101,0,100,0,82,125,8,2,164,3,82,8  ; n92 t=8.898s dur=100ms, freq=932Hz, sample=82, buffer_id=08:52
    db 78,0,100,0,82,125,8,3,23,4,82,8  ; n93 t=8.999s dur=100ms, freq=1047Hz, sample=82, buffer_id=08:52
    db 7,0,100,0,87,125,8,8,85,4,87,8  ; n94 t=9.077s dur=100ms, freq=1109Hz, sample=87, buffer_id=08:57
    db 45,0,100,0,65,126,4,9,93,1,65,4  ; n95 t=9.085s dur=100ms, freq=349Hz, sample=65, buffer_id=04:41
    db 7,0,100,0,65,126,4,0,93,1,65,4  ; n96 t=9.130s dur=100ms, freq=349Hz, sample=65, buffer_id=04:41
    db 11,0,108,0,53,125,5,10,175,0,53,5  ; n97 t=9.137s dur=108ms, freq=175Hz, sample=53, buffer_id=05:35
    db 19,0,119,0,58,125,5,11,233,0,58,5  ; n98 t=9.148s dur=119ms, freq=233Hz, sample=58, buffer_id=05:3A
    db 86,0,100,0,87,125,8,1,221,4,87,8  ; n99 t=9.167s dur=100ms, freq=1245Hz, sample=87, buffer_id=08:57
    db 71,0,100,0,89,125,8,2,117,5,89,8  ; n100 t=9.253s dur=100ms, freq=1397Hz, sample=89, buffer_id=08:59
    db 30,0,100,0,65,124,4,3,93,1,65,4  ; n101 t=9.324s dur=100ms, freq=349Hz, sample=65, buffer_id=04:41
    db 11,0,100,0,91,125,8,4,32,6,91,8  ; n102 t=9.354s dur=100ms, freq=1568Hz, sample=91, buffer_id=08:5B
    db 0,0,100,0,65,124,4,6,93,1,65,4  ; n103 t=9.365s dur=100ms, freq=349Hz, sample=65, buffer_id=04:41
    db 8,0,160,0,53,125,5,5,175,0,53,5  ; n104 t=9.365s dur=160ms, freq=175Hz, sample=53, buffer_id=05:35
    db 67,0,156,0,58,125,5,7,233,0,58,5  ; n105 t=9.372s dur=156ms, freq=233Hz, sample=58, buffer_id=05:3A
    db 93,0,119,0,94,125,8,0,224,6,94,8  ; n106 t=9.439s dur=119ms, freq=1760Hz, sample=94, buffer_id=08:5E
    db 110,0,187,28,94,125,8,1,73,7,94,8  ; n107 t=9.533s dur=7355ms, freq=1865Hz, sample=94, buffer_id=08:5E
    db 76,1,19,4,70,124,4,2,210,1,70,4  ; n108 t=9.643s dur=1043ms, freq=466Hz, sample=70, buffer_id=04:46
    db 0,0,100,0,31,108,9,0,58,0,31,8  ; n109 t=9.975s dur=100ms, freq=58Hz, sample=31, buffer_id=08:1F
    db 48,0,100,0,43,108,9,3,87,0,43,8  ; n110 t=9.975s dur=100ms, freq=87Hz, sample=43, buffer_id=08:2B
    db 10,0,100,0,58,125,5,4,233,0,58,5  ; n111 t=10.023s dur=100ms, freq=233Hz, sample=58, buffer_id=05:3A
    db 34,0,100,0,53,125,5,6,175,0,53,5  ; n112 t=10.032s dur=100ms, freq=175Hz, sample=53, buffer_id=05:35
    db 0,0,100,0,43,108,9,5,87,0,43,8  ; n113 t=10.066s dur=100ms, freq=87Hz, sample=43, buffer_id=08:2B
    db 53,0,100,0,31,108,9,7,58,0,31,8  ; n114 t=10.066s dur=100ms, freq=58Hz, sample=31, buffer_id=08:1F
    db 5,0,100,0,58,125,5,8,233,0,58,5  ; n115 t=10.119s dur=100ms, freq=233Hz, sample=58, buffer_id=05:3A
    db 34,0,100,0,53,125,5,9,175,0,53,5  ; n116 t=10.124s dur=100ms, freq=175Hz, sample=53, buffer_id=05:35
    db 0,0,180,2,31,108,9,10,58,0,31,8  ; n117 t=10.157s dur=692ms, freq=58Hz, sample=31, buffer_id=08:1F
    db 53,0,189,2,43,108,9,11,87,0,43,8  ; n118 t=10.157s dur=701ms, freq=87Hz, sample=43, buffer_id=08:2B
    db 0,0,209,2,53,125,5,12,175,0,53,5  ; n119 t=10.210s dur=721ms, freq=175Hz, sample=53, buffer_id=05:35
    db 74,2,218,2,58,125,5,13,233,0,58,5  ; n120 t=10.210s dur=730ms, freq=233Hz, sample=58, buffer_id=05:3A
    db 23,1,232,3,77,124,4,0,186,2,77,4  ; n121 t=10.797s dur=1000ms, freq=698Hz, sample=77, buffer_id=04:4D
    db 0,0,100,0,58,125,5,2,233,0,58,5  ; n122 t=11.076s dur=100ms, freq=233Hz, sample=58, buffer_id=05:3A
    db 0,0,100,0,43,108,9,4,87,0,43,8  ; n123 t=11.076s dur=100ms, freq=87Hz, sample=43, buffer_id=08:2B
    db 10,0,100,0,50,108,9,3,147,0,50,8  ; n124 t=11.076s dur=100ms, freq=147Hz, sample=50, buffer_id=08:32
    db 0,0,100,0,53,125,5,5,175,0,53,5  ; n125 t=11.085s dur=100ms, freq=175Hz, sample=53, buffer_id=05:35
    db 0,0,100,0,58,108,9,6,233,0,58,8  ; n126 t=11.085s dur=100ms, freq=233Hz, sample=58, buffer_id=08:3A
    db 86,0,100,0,31,108,9,8,58,0,31,8  ; n127 t=11.085s dur=100ms, freq=58Hz, sample=31, buffer_id=08:1F
    db 0,0,100,0,58,125,5,7,233,0,58,5  ; n128 t=11.172s dur=100ms, freq=233Hz, sample=58, buffer_id=05:3A
    db 0,0,100,0,53,125,5,10,175,0,53,5  ; n129 t=11.172s dur=100ms, freq=175Hz, sample=53, buffer_id=05:35
    db 0,0,100,0,43,108,9,9,87,0,43,8  ; n130 t=11.172s dur=100ms, freq=87Hz, sample=43, buffer_id=08:2B
    db 0,0,100,0,31,108,9,11,58,0,31,8  ; n131 t=11.172s dur=100ms, freq=58Hz, sample=31, buffer_id=08:1F
    db 0,0,100,0,58,108,9,12,233,0,58,8  ; n132 t=11.172s dur=100ms, freq=233Hz, sample=58, buffer_id=08:3A
    db 77,0,100,0,50,108,9,13,147,0,50,8  ; n133 t=11.172s dur=100ms, freq=147Hz, sample=50, buffer_id=08:32
    db 0,0,100,0,43,108,9,4,87,0,43,8  ; n134 t=11.249s dur=100ms, freq=87Hz, sample=43, buffer_id=08:2B [TRUNCATE prev:ch4 @11075.7ms -> 11248.8ms]
    db 5,0,101,0,50,108,9,3,147,0,50,8  ; n135 t=11.249s dur=101ms, freq=147Hz, sample=50, buffer_id=08:32 [TRUNCATE prev:ch3 @11075.7ms -> 11248.8ms]
    db 0,0,100,0,58,125,5,2,233,0,58,5  ; n136 t=11.254s dur=100ms, freq=233Hz, sample=58, buffer_id=05:3A [TRUNCATE prev:ch2 @11075.7ms -> 11253.6ms]
    db 0,0,100,0,58,108,9,6,233,0,58,8  ; n137 t=11.254s dur=100ms, freq=233Hz, sample=58, buffer_id=08:3A [TRUNCATE prev:ch6 @11085.3ms -> 11253.6ms]
    db 5,0,100,0,31,108,9,8,58,0,31,8  ; n138 t=11.254s dur=100ms, freq=58Hz, sample=31, buffer_id=08:1F [TRUNCATE prev:ch8 @11085.3ms -> 11253.6ms]
    db 120,0,100,0,53,125,5,5,175,0,53,5  ; n139 t=11.258s dur=100ms, freq=175Hz, sample=53, buffer_id=05:35 [TRUNCATE prev:ch5 @11085.3ms -> 11258.4ms]
    db 0,0,100,0,53,125,5,10,175,0,53,5  ; n140 t=11.379s dur=100ms, freq=175Hz, sample=53, buffer_id=05:35 [TRUNCATE prev:ch10 @11171.8ms -> 11378.6ms]
    db 0,0,105,0,43,108,9,9,87,0,43,8  ; n141 t=11.379s dur=105ms, freq=87Hz, sample=43, buffer_id=08:2B [TRUNCATE prev:ch9 @11171.8ms -> 11378.6ms]
    db 0,0,110,0,58,108,9,12,233,0,58,8  ; n142 t=11.379s dur=110ms, freq=233Hz, sample=58, buffer_id=08:3A [TRUNCATE prev:ch12 @11171.8ms -> 11378.6ms]
    db 5,0,110,0,31,108,9,11,58,0,31,8  ; n143 t=11.379s dur=110ms, freq=58Hz, sample=31, buffer_id=08:1F [TRUNCATE prev:ch11 @11171.8ms -> 11378.6ms]
    db 0,0,105,0,58,125,5,7,233,0,58,5  ; n144 t=11.383s dur=105ms, freq=233Hz, sample=58, buffer_id=05:3A [TRUNCATE prev:ch7 @11171.8ms -> 11383.4ms]
    db 13,1,115,0,50,108,9,13,147,0,50,8  ; n145 t=11.383s dur=115ms, freq=147Hz, sample=50, buffer_id=08:32 [TRUNCATE prev:ch13 @11171.8ms -> 11383.4ms]
    db 0,0,100,0,55,125,5,2,208,0,55,5  ; n146 t=11.653s dur=100ms, freq=208Hz, sample=55, buffer_id=05:37
    db 0,0,120,0,58,125,5,3,233,0,58,5  ; n147 t=11.653s dur=120ms, freq=233Hz, sample=58, buffer_id=05:3A
    db 0,0,100,0,56,108,9,4,208,0,56,8  ; n148 t=11.653s dur=100ms, freq=208Hz, sample=56, buffer_id=08:38
    db 0,0,110,0,43,108,9,5,87,0,43,8  ; n149 t=11.653s dur=110ms, freq=87Hz, sample=43, buffer_id=08:2B
    db 5,0,110,0,29,108,9,6,44,0,29,8  ; n150 t=11.653s dur=110ms, freq=44Hz, sample=29, buffer_id=08:1D
    db 32,1,110,0,58,108,9,8,233,0,58,8  ; n151 t=11.657s dur=110ms, freq=233Hz, sample=58, buffer_id=08:3A
    db 10,0,100,0,75,124,4,7,110,2,75,4  ; n152 t=11.946s dur=100ms, freq=622Hz, sample=75, buffer_id=04:4B
    db 111,0,100,0,70,102,6,2,210,1,70,6  ; n153 t=11.956s dur=100ms, freq=466Hz, sample=70, buffer_id=06:46
    db 48,0,100,0,75,102,6,0,110,2,75,6  ; n154 t=12.066s dur=100ms, freq=622Hz, sample=75, buffer_id=06:4B
    db 38,0,100,0,74,124,4,3,75,2,74,4  ; n155 t=12.114s dur=100ms, freq=587Hz, sample=74, buffer_id=04:4A
    db 77,0,100,0,77,102,6,4,186,2,77,6  ; n156 t=12.153s dur=100ms, freq=698Hz, sample=77, buffer_id=06:4D
    db 0,0,120,0,55,125,5,5,208,0,55,5  ; n157 t=12.229s dur=120ms, freq=208Hz, sample=55, buffer_id=05:37
    db 0,0,144,0,58,125,5,6,233,0,58,5  ; n158 t=12.229s dur=144ms, freq=233Hz, sample=58, buffer_id=05:3A
    db 5,0,182,0,29,108,9,8,44,0,29,8  ; n159 t=12.229s dur=182ms, freq=44Hz, sample=29, buffer_id=08:1D
    db 0,0,149,0,56,108,9,9,208,0,56,8  ; n160 t=12.234s dur=149ms, freq=208Hz, sample=56, buffer_id=08:38
    db 5,0,187,0,53,108,9,10,175,0,53,8  ; n161 t=12.234s dur=187ms, freq=175Hz, sample=53, buffer_id=08:35
    db 67,0,100,0,82,102,6,11,164,3,82,6  ; n162 t=12.239s dur=100ms, freq=932Hz, sample=82, buffer_id=06:52
    db 38,0,100,0,72,124,4,2,11,2,72,4  ; n163 t=12.306s dur=100ms, freq=523Hz, sample=72, buffer_id=04:48
    db 91,0,100,0,77,102,6,7,186,2,77,6  ; n164 t=12.345s dur=100ms, freq=698Hz, sample=77, buffer_id=06:4D
    db 91,0,100,0,75,102,6,3,110,2,75,6  ; n165 t=12.436s dur=100ms, freq=622Hz, sample=75, buffer_id=06:4B
    db 19,0,241,3,82,124,4,0,164,3,82,4  ; n166 t=12.528s dur=1009ms, freq=932Hz, sample=82, buffer_id=04:52
    db 96,0,100,0,70,102,6,4,210,1,70,6  ; n167 t=12.547s dur=100ms, freq=466Hz, sample=70, buffer_id=06:46
    db 91,0,100,0,75,102,6,2,110,2,75,6  ; n168 t=12.643s dur=100ms, freq=622Hz, sample=75, buffer_id=06:4B
    db 62,0,100,0,77,102,6,5,186,2,77,6  ; n169 t=12.734s dur=100ms, freq=698Hz, sample=77, buffer_id=06:4D
    db 5,0,144,0,63,125,5,3,55,1,63,5  ; n170 t=12.797s dur=144ms, freq=311Hz, sample=63, buffer_id=05:3F
    db 5,0,120,0,58,125,5,7,233,0,58,5  ; n171 t=12.802s dur=120ms, freq=233Hz, sample=58, buffer_id=05:3A
    db 0,0,173,0,56,108,9,6,208,0,56,8  ; n172 t=12.806s dur=173ms, freq=208Hz, sample=56, buffer_id=08:38
    db 5,0,173,0,29,108,9,9,44,0,29,8  ; n173 t=12.806s dur=173ms, freq=44Hz, sample=29, buffer_id=08:1D
    db 19,0,115,0,58,108,9,8,233,0,58,8  ; n174 t=12.811s dur=115ms, freq=233Hz, sample=58, buffer_id=08:3A
    db 96,0,100,0,82,102,6,10,164,3,82,6  ; n175 t=12.831s dur=100ms, freq=932Hz, sample=82, buffer_id=06:52
    db 91,0,100,0,77,102,6,4,186,2,77,6  ; n176 t=12.927s dur=100ms, freq=698Hz, sample=77, buffer_id=06:4D
    db 82,0,100,0,75,102,6,11,110,2,75,6  ; n177 t=13.018s dur=100ms, freq=622Hz, sample=75, buffer_id=06:4B
    db 10,0,101,0,58,125,5,2,233,0,58,5  ; n178 t=13.100s dur=101ms, freq=233Hz, sample=58, buffer_id=05:3A
    db 0,0,100,0,63,125,5,5,55,1,63,5  ; n179 t=13.109s dur=100ms, freq=311Hz, sample=63, buffer_id=05:3F
    db 5,0,101,0,58,108,9,13,233,0,58,8  ; n180 t=13.109s dur=101ms, freq=233Hz, sample=58, buffer_id=08:3A
    db 0,0,100,0,70,102,6,12,210,1,70,6  ; n181 t=13.114s dur=100ms, freq=466Hz, sample=70, buffer_id=06:46
    db 0,0,100,0,56,108,9,6,208,0,56,8  ; n182 t=13.114s dur=100ms, freq=208Hz, sample=56, buffer_id=08:38 [TRUNCATE prev:ch6 @12806.5ms -> 13114.2ms]
    db 0,0,100,0,63,108,9,1,55,1,63,8  ; n183 t=13.114s dur=100ms, freq=311Hz, sample=63, buffer_id=08:3F [TRUNCATE prev:ch1 @9532.6ms -> 13114.2ms]
    db 91,0,125,0,29,108,9,9,44,0,29,8  ; n184 t=13.114s dur=125ms, freq=44Hz, sample=29, buffer_id=08:1D [TRUNCATE prev:ch9 @12806.5ms -> 13114.2ms]
    db 96,0,100,0,70,102,6,3,11,2,70,6  ; n185 t=13.206s dur=100ms, freq=523Hz, sample=70, buffer_id=06:46
    db 72,0,100,0,77,102,6,7,186,2,77,6  ; n186 t=13.302s dur=100ms, freq=698Hz, sample=77, buffer_id=06:4D
    db 0,0,100,0,58,125,5,4,233,0,58,5  ; n187 t=13.374s dur=100ms, freq=233Hz, sample=58, buffer_id=05:3A
    db 10,0,100,0,29,108,9,8,44,0,29,8  ; n188 t=13.374s dur=100ms, freq=44Hz, sample=29, buffer_id=08:1D
    db 0,0,100,0,63,125,5,10,55,1,63,5  ; n189 t=13.383s dur=100ms, freq=311Hz, sample=63, buffer_id=05:3F
    db 5,0,100,0,58,108,9,11,233,0,58,8  ; n190 t=13.383s dur=100ms, freq=233Hz, sample=58, buffer_id=08:3A
    db 0,0,100,0,56,108,9,6,208,0,56,8  ; n191 t=13.388s dur=100ms, freq=208Hz, sample=56, buffer_id=08:38 [TRUNCATE prev:ch6 @13114.2ms -> 13388.2ms]
    db 14,0,100,0,63,108,9,1,55,1,63,8  ; n192 t=13.388s dur=100ms, freq=311Hz, sample=63, buffer_id=08:3F [TRUNCATE prev:ch1 @13114.2ms -> 13388.2ms]
    db 67,0,100,0,82,102,6,2,164,3,82,6  ; n193 t=13.403s dur=100ms, freq=932Hz, sample=82, buffer_id=06:52
    db 10,0,100,0,58,125,5,5,233,0,58,5  ; n194 t=13.470s dur=100ms, freq=233Hz, sample=58, buffer_id=05:3A
    db 0,0,100,0,63,125,5,9,55,1,63,5  ; n195 t=13.479s dur=100ms, freq=311Hz, sample=63, buffer_id=05:3F
    db 5,0,100,0,58,108,9,12,233,0,58,8  ; n196 t=13.479s dur=100ms, freq=233Hz, sample=58, buffer_id=08:3A
    db 0,0,100,0,56,108,9,13,208,0,56,8  ; n197 t=13.484s dur=100ms, freq=208Hz, sample=56, buffer_id=08:38
    db 0,0,100,0,63,108,9,0,55,1,63,8  ; n198 t=13.484s dur=100ms, freq=311Hz, sample=63, buffer_id=08:3F [TRUNCATE prev:ch0 @12527.6ms -> 13484.3ms]
    db 5,0,100,0,29,108,9,8,44,0,29,8  ; n199 t=13.484s dur=100ms, freq=44Hz, sample=29, buffer_id=08:1D [TRUNCATE prev:ch8 @13373.8ms -> 13484.3ms]
    db 77,0,100,0,77,102,6,7,186,2,77,6  ; n200 t=13.489s dur=100ms, freq=698Hz, sample=77, buffer_id=06:4D [TRUNCATE prev:ch7 @13301.7ms -> 13489.2ms]
    db 5,0,100,0,58,125,5,3,233,0,58,5  ; n201 t=13.566s dur=100ms, freq=233Hz, sample=58, buffer_id=05:3A
    db 0,0,100,0,63,125,5,10,55,1,63,5  ; n202 t=13.571s dur=100ms, freq=311Hz, sample=63, buffer_id=05:3F [TRUNCATE prev:ch10 @13383.4ms -> 13570.9ms]
    db 5,0,100,0,58,108,9,11,233,0,58,8  ; n203 t=13.571s dur=100ms, freq=233Hz, sample=58, buffer_id=08:3A [TRUNCATE prev:ch11 @13383.4ms -> 13570.9ms]
    db 0,0,100,0,70,102,6,4,11,2,70,6  ; n204 t=13.576s dur=100ms, freq=523Hz, sample=70, buffer_id=06:46 [TRUNCATE prev:ch4 @13373.8ms -> 13575.7ms]
    db 0,0,100,0,63,108,9,1,55,1,63,8  ; n205 t=13.576s dur=100ms, freq=311Hz, sample=63, buffer_id=08:3F [TRUNCATE prev:ch1 @13388.2ms -> 13575.7ms]
    db 0,0,100,0,29,108,9,6,44,0,29,8  ; n206 t=13.576s dur=100ms, freq=44Hz, sample=29, buffer_id=08:1D [TRUNCATE prev:ch6 @13388.2ms -> 13575.7ms]
    db 96,0,100,0,56,108,9,2,208,0,56,8  ; n207 t=13.576s dur=100ms, freq=208Hz, sample=56, buffer_id=08:38 [TRUNCATE prev:ch2 @13402.6ms -> 13575.7ms]
    db 0,0,100,0,58,125,5,5,233,0,58,5  ; n208 t=13.672s dur=100ms, freq=233Hz, sample=58, buffer_id=05:3A [TRUNCATE prev:ch5 @13469.9ms -> 13671.8ms]
    db 5,0,100,0,53,125,5,9,175,0,53,5  ; n209 t=13.672s dur=100ms, freq=175Hz, sample=53, buffer_id=05:35 [TRUNCATE prev:ch9 @13479.5ms -> 13671.8ms]
    db 0,0,167,1,77,124,4,12,186,2,77,4  ; n210 t=13.677s dur=423ms, freq=698Hz, sample=77, buffer_id=04:4D [TRUNCATE prev:ch12 @13479.5ms -> 13676.7ms]
    db 0,0,100,0,70,102,6,4,210,1,70,6  ; n211 t=13.677s dur=100ms, freq=466Hz, sample=70, buffer_id=06:46 [TRUNCATE prev:ch4 @13575.7ms -> 13676.7ms]
    db 0,0,100,0,50,108,9,0,147,0,50,8  ; n212 t=13.677s dur=100ms, freq=147Hz, sample=50, buffer_id=08:32 [TRUNCATE prev:ch0 @13484.3ms -> 13676.7ms]
    db 0,0,100,0,58,108,9,11,233,0,58,8  ; n213 t=13.677s dur=100ms, freq=233Hz, sample=58, buffer_id=08:3A [TRUNCATE prev:ch11 @13570.9ms -> 13676.7ms]
    db 0,0,100,0,31,108,9,8,58,0,31,8  ; n214 t=13.677s dur=100ms, freq=58Hz, sample=31, buffer_id=08:1F [TRUNCATE prev:ch8 @13484.3ms -> 13676.7ms]
    db 0,0,100,0,53,108,9,13,175,0,53,8  ; n215 t=13.677s dur=100ms, freq=175Hz, sample=53, buffer_id=08:35 [TRUNCATE prev:ch13 @13484.3ms -> 13676.7ms]
    db 96,0,100,0,47,108,9,7,117,0,47,8  ; n216 t=13.677s dur=100ms, freq=117Hz, sample=47, buffer_id=08:2F [TRUNCATE prev:ch7 @13489.2ms -> 13676.7ms]
    db 91,0,100,0,70,102,6,3,11,2,70,6  ; n217 t=13.773s dur=100ms, freq=523Hz, sample=70, buffer_id=06:46 [TRUNCATE prev:ch3 @13566.1ms -> 13772.8ms]
    db 0,0,100,0,58,125,5,5,233,0,58,5  ; n218 t=13.864s dur=100ms, freq=233Hz, sample=58, buffer_id=05:3A [TRUNCATE prev:ch5 @13671.8ms -> 13864.2ms]
    db 0,0,100,0,53,125,5,9,175,0,53,5  ; n219 t=13.864s dur=100ms, freq=175Hz, sample=53, buffer_id=05:35 [TRUNCATE prev:ch9 @13671.8ms -> 13864.2ms]
    db 5,0,100,0,77,102,6,10,186,2,77,6  ; n220 t=13.864s dur=100ms, freq=698Hz, sample=77, buffer_id=06:4D [TRUNCATE prev:ch10 @13570.9ms -> 13864.2ms]
    db 0,0,100,0,58,108,9,11,233,0,58,8  ; n221 t=13.869s dur=100ms, freq=233Hz, sample=58, buffer_id=08:3A [TRUNCATE prev:ch11 @13676.7ms -> 13869.0ms]
    db 0,0,100,0,50,108,9,0,147,0,50,8  ; n222 t=13.869s dur=100ms, freq=147Hz, sample=50, buffer_id=08:32 [TRUNCATE prev:ch0 @13676.7ms -> 13869.0ms]
    db 0,0,100,0,31,108,9,8,58,0,31,8  ; n223 t=13.869s dur=100ms, freq=58Hz, sample=31, buffer_id=08:1F [TRUNCATE prev:ch8 @13676.7ms -> 13869.0ms]
    db 0,0,100,0,53,108,9,13,175,0,53,8  ; n224 t=13.869s dur=100ms, freq=175Hz, sample=53, buffer_id=08:35 [TRUNCATE prev:ch13 @13676.7ms -> 13869.0ms]
    db 91,0,100,0,47,108,9,7,117,0,47,8  ; n225 t=13.869s dur=100ms, freq=117Hz, sample=47, buffer_id=08:2F [TRUNCATE prev:ch7 @13676.7ms -> 13869.0ms]
    db 96,0,100,0,82,102,6,1,164,3,82,6  ; n226 t=13.960s dur=100ms, freq=932Hz, sample=82, buffer_id=06:52
    db 0,0,100,0,53,125,5,2,175,0,53,5  ; n227 t=14.056s dur=100ms, freq=175Hz, sample=53, buffer_id=05:35
    db 0,0,100,0,58,125,5,4,233,0,58,5  ; n228 t=14.056s dur=100ms, freq=233Hz, sample=58, buffer_id=05:3A
    db 5,0,100,0,77,102,6,6,186,2,77,6  ; n229 t=14.056s dur=100ms, freq=698Hz, sample=77, buffer_id=06:4D
    db 0,0,100,0,47,108,9,7,117,0,47,8  ; n230 t=14.061s dur=100ms, freq=117Hz, sample=47, buffer_id=08:2F [TRUNCATE prev:ch7 @13869.0ms -> 14061.3ms]
    db 0,0,100,0,53,108,9,13,175,0,53,8  ; n231 t=14.061s dur=100ms, freq=175Hz, sample=53, buffer_id=08:35 [TRUNCATE prev:ch13 @13869.0ms -> 14061.3ms]
    db 0,0,100,0,50,108,9,0,147,0,50,8  ; n232 t=14.061s dur=100ms, freq=147Hz, sample=50, buffer_id=08:32 [TRUNCATE prev:ch0 @13869.0ms -> 14061.3ms]
    db 0,0,100,0,58,108,9,11,233,0,58,8  ; n233 t=14.061s dur=100ms, freq=233Hz, sample=58, buffer_id=08:3A [TRUNCATE prev:ch11 @13869.0ms -> 14061.3ms]
    db 87,0,101,0,31,108,9,8,58,0,31,8  ; n234 t=14.061s dur=101ms, freq=58Hz, sample=31, buffer_id=08:1F [TRUNCATE prev:ch8 @13869.0ms -> 14061.3ms]
    db 82,0,100,0,70,102,6,3,11,2,70,6  ; n235 t=14.148s dur=100ms, freq=523Hz, sample=70, buffer_id=06:46 [TRUNCATE prev:ch3 @13772.8ms -> 14147.8ms]
    db 10,0,100,0,75,124,4,5,110,2,75,4  ; n236 t=14.229s dur=100ms, freq=622Hz, sample=75, buffer_id=04:4B
    db 101,0,100,0,70,102,6,9,210,1,70,6  ; n237 t=14.239s dur=100ms, freq=466Hz, sample=70, buffer_id=06:46
    db 58,0,100,0,75,102,6,1,110,2,75,6  ; n238 t=14.340s dur=100ms, freq=622Hz, sample=75, buffer_id=06:4B
    db 34,0,100,0,74,124,4,0,75,2,74,4  ; n239 t=14.398s dur=100ms, freq=587Hz, sample=74, buffer_id=04:4A
    db 96,0,100,0,77,102,6,2,186,2,77,6  ; n240 t=14.431s dur=100ms, freq=698Hz, sample=77, buffer_id=06:4D
    db 10,0,100,0,82,102,6,3,164,3,82,6  ; n241 t=14.528s dur=100ms, freq=932Hz, sample=82, buffer_id=06:52
    db 0,0,120,0,53,125,5,4,175,0,53,5  ; n242 t=14.537s dur=120ms, freq=175Hz, sample=53, buffer_id=05:35
    db 0,0,144,0,58,125,5,5,233,0,58,5  ; n243 t=14.537s dur=144ms, freq=233Hz, sample=58, buffer_id=05:3A
    db 0,0,173,0,58,108,9,6,233,0,58,8  ; n244 t=14.537s dur=173ms, freq=233Hz, sample=58, buffer_id=08:3A
    db 5,0,182,0,29,108,9,7,44,0,29,8  ; n245 t=14.537s dur=182ms, freq=44Hz, sample=29, buffer_id=08:1D
    db 0,0,149,0,56,108,9,8,208,0,56,8  ; n246 t=14.542s dur=149ms, freq=208Hz, sample=56, buffer_id=08:38
    db 53,0,173,0,50,108,9,9,156,0,50,8  ; n247 t=14.542s dur=173ms, freq=156Hz, sample=50, buffer_id=08:32
    db 29,0,100,0,72,124,4,10,11,2,72,4  ; n248 t=14.595s dur=100ms, freq=523Hz, sample=72, buffer_id=04:48
    db 87,0,100,0,77,102,6,11,186,2,77,6  ; n249 t=14.624s dur=100ms, freq=698Hz, sample=77, buffer_id=06:4D
    db 96,0,100,0,75,102,6,0,110,2,75,6  ; n250 t=14.710s dur=100ms, freq=622Hz, sample=75, buffer_id=06:4B
    db 19,0,100,0,70,102,6,1,210,1,70,6  ; n251 t=14.806s dur=100ms, freq=466Hz, sample=70, buffer_id=06:46
    db 87,0,33,4,82,124,4,2,164,3,82,4  ; n252 t=14.826s dur=1057ms, freq=932Hz, sample=82, buffer_id=04:52
    db 82,0,100,0,75,102,6,3,110,2,75,6  ; n253 t=14.912s dur=100ms, freq=622Hz, sample=75, buffer_id=06:4B
    db 101,0,100,0,77,102,6,4,186,2,77,6  ; n254 t=14.994s dur=100ms, freq=698Hz, sample=77, buffer_id=06:4D
    db 10,0,100,0,82,102,6,0,164,3,82,6  ; n255 t=15.095s dur=100ms, freq=932Hz, sample=82, buffer_id=06:52
    db 5,0,144,0,63,125,5,5,55,1,63,5  ; n256 t=15.104s dur=144ms, freq=311Hz, sample=63, buffer_id=05:3F
    db 5,0,120,0,58,125,5,1,233,0,58,5  ; n257 t=15.109s dur=120ms, freq=233Hz, sample=58, buffer_id=05:3A
    db 0,0,173,0,56,108,9,6,208,0,56,8  ; n258 t=15.114s dur=173ms, freq=208Hz, sample=56, buffer_id=08:38
    db 5,0,173,0,29,108,9,8,44,0,29,8  ; n259 t=15.114s dur=173ms, freq=44Hz, sample=29, buffer_id=08:1D
    db 0,0,115,0,58,108,9,7,233,0,58,8  ; n260 t=15.119s dur=115ms, freq=233Hz, sample=58, buffer_id=08:3A
    db 72,0,158,0,50,108,9,10,156,0,50,8  ; n261 t=15.119s dur=158ms, freq=156Hz, sample=50, buffer_id=08:32
    db 96,0,100,0,77,102,6,9,186,2,77,6  ; n262 t=15.191s dur=100ms, freq=698Hz, sample=77, buffer_id=06:4D
    db 101,0,100,0,75,102,6,11,110,2,75,6  ; n263 t=15.287s dur=100ms, freq=622Hz, sample=75, buffer_id=06:4B
    db 19,0,100,0,70,102,6,3,210,1,70,6  ; n264 t=15.388s dur=100ms, freq=466Hz, sample=70, buffer_id=06:46
    db 10,0,101,0,58,125,5,0,233,0,58,5  ; n265 t=15.407s dur=101ms, freq=233Hz, sample=58, buffer_id=05:3A
    db 0,0,100,0,63,125,5,4,55,1,63,5  ; n266 t=15.417s dur=100ms, freq=311Hz, sample=63, buffer_id=05:3F
    db 0,0,101,0,50,108,9,12,156,0,50,8  ; n267 t=15.417s dur=101ms, freq=156Hz, sample=50, buffer_id=08:32
    db 5,0,101,0,58,108,9,13,233,0,58,8  ; n268 t=15.417s dur=101ms, freq=233Hz, sample=58, buffer_id=08:3A
    db 0,0,100,0,56,108,9,6,208,0,56,8  ; n269 t=15.422s dur=100ms, freq=208Hz, sample=56, buffer_id=08:38 [TRUNCATE prev:ch6 @15114.2ms -> 15421.8ms]
    db 0,0,100,0,63,108,9,2,55,1,63,8  ; n270 t=15.422s dur=100ms, freq=311Hz, sample=63, buffer_id=08:3F [TRUNCATE prev:ch2 @14825.7ms -> 15421.8ms]
    db 62,0,125,0,29,108,9,8,44,0,29,8  ; n271 t=15.422s dur=125ms, freq=44Hz, sample=29, buffer_id=08:1D [TRUNCATE prev:ch8 @15114.2ms -> 15421.8ms]
    db 91,0,100,0,70,102,6,1,11,2,70,6  ; n272 t=15.484s dur=100ms, freq=523Hz, sample=70, buffer_id=06:46
    db 106,0,100,0,77,102,6,5,186,2,77,6  ; n273 t=15.576s dur=100ms, freq=698Hz, sample=77, buffer_id=06:4D
    db 0,0,100,0,58,125,5,7,233,0,58,5  ; n274 t=15.681s dur=100ms, freq=233Hz, sample=58, buffer_id=05:3A
    db 0,0,100,0,82,102,6,9,164,3,82,6  ; n275 t=15.681s dur=100ms, freq=932Hz, sample=82, buffer_id=06:52
    db 10,0,100,0,29,108,9,10,44,0,29,8  ; n276 t=15.681s dur=100ms, freq=44Hz, sample=29, buffer_id=08:1D
    db 0,0,100,0,63,125,5,3,55,1,63,5  ; n277 t=15.691s dur=100ms, freq=311Hz, sample=63, buffer_id=05:3F
    db 0,0,100,0,58,108,9,11,233,0,58,8  ; n278 t=15.691s dur=100ms, freq=233Hz, sample=58, buffer_id=08:3A
    db 5,0,100,0,50,108,9,12,156,0,50,8  ; n279 t=15.691s dur=100ms, freq=156Hz, sample=50, buffer_id=08:32 [TRUNCATE prev:ch12 @15417.0ms -> 15691.1ms]
    db 0,0,100,0,56,108,9,6,208,0,56,8  ; n280 t=15.696s dur=100ms, freq=208Hz, sample=56, buffer_id=08:38 [TRUNCATE prev:ch6 @15421.8ms -> 15695.9ms]
    db 82,0,100,0,63,108,9,2,55,1,63,8  ; n281 t=15.696s dur=100ms, freq=311Hz, sample=63, buffer_id=08:3F [TRUNCATE prev:ch2 @15421.8ms -> 15695.9ms]
    db 0,0,100,0,58,125,5,4,233,0,58,5  ; n282 t=15.778s dur=100ms, freq=233Hz, sample=58, buffer_id=05:3A
    db 10,0,100,0,77,102,6,0,186,2,77,6  ; n283 t=15.778s dur=100ms, freq=698Hz, sample=77, buffer_id=06:4D
    db 0,0,100,0,63,125,5,1,55,1,63,5  ; n284 t=15.787s dur=100ms, freq=311Hz, sample=63, buffer_id=05:3F
    db 0,0,100,0,50,108,9,8,156,0,50,8  ; n285 t=15.787s dur=100ms, freq=156Hz, sample=50, buffer_id=08:32
    db 5,0,100,0,58,108,9,13,233,0,58,8  ; n286 t=15.787s dur=100ms, freq=233Hz, sample=58, buffer_id=08:3A [TRUNCATE prev:ch13 @15417.0ms -> 15787.2ms]
    db 0,0,100,0,56,108,9,5,208,0,56,8  ; n287 t=15.792s dur=100ms, freq=208Hz, sample=56, buffer_id=08:38 [TRUNCATE prev:ch5 @15575.7ms -> 15792.0ms]
    db 0,0,100,0,63,108,9,7,55,1,63,8  ; n288 t=15.792s dur=100ms, freq=311Hz, sample=63, buffer_id=08:3F [TRUNCATE prev:ch7 @15681.5ms -> 15792.0ms]
    db 58,0,100,0,29,108,9,10,44,0,29,8  ; n289 t=15.792s dur=100ms, freq=44Hz, sample=29, buffer_id=08:1D [TRUNCATE prev:ch10 @15681.5ms -> 15792.0ms]
    db 19,0,100,0,58,125,5,9,233,0,58,5  ; n290 t=15.850s dur=100ms, freq=233Hz, sample=58, buffer_id=05:3A [TRUNCATE prev:ch9 @15681.5ms -> 15849.7ms]
    db 10,0,100,0,70,102,6,3,11,2,70,6  ; n291 t=15.869s dur=100ms, freq=523Hz, sample=70, buffer_id=06:46 [TRUNCATE prev:ch3 @15691.1ms -> 15869.0ms]
    db 0,0,100,0,63,125,5,11,55,1,63,5  ; n292 t=15.879s dur=100ms, freq=311Hz, sample=63, buffer_id=05:3F [TRUNCATE prev:ch11 @15691.1ms -> 15878.6ms]
    db 0,0,100,0,50,108,9,12,156,0,50,8  ; n293 t=15.879s dur=100ms, freq=156Hz, sample=50, buffer_id=08:32 [TRUNCATE prev:ch12 @15691.1ms -> 15878.6ms]
    db 5,0,100,0,58,108,9,2,233,0,58,8  ; n294 t=15.879s dur=100ms, freq=233Hz, sample=58, buffer_id=08:3A [TRUNCATE prev:ch2 @15695.9ms -> 15878.6ms]
    db 0,0,100,0,63,108,9,6,55,1,63,8  ; n295 t=15.883s dur=100ms, freq=311Hz, sample=63, buffer_id=08:3F [TRUNCATE prev:ch6 @15695.9ms -> 15883.4ms]
    db 0,0,100,0,56,108,9,0,208,0,56,8  ; n296 t=15.883s dur=100ms, freq=208Hz, sample=56, buffer_id=08:38 [TRUNCATE prev:ch0 @15777.6ms -> 15883.4ms]
    db 77,0,100,0,29,108,9,4,44,0,29,8  ; n297 t=15.883s dur=100ms, freq=44Hz, sample=29, buffer_id=08:1D [TRUNCATE prev:ch4 @15777.6ms -> 15883.4ms]
    db 19,0,100,0,70,102,6,1,210,1,70,6  ; n298 t=15.960s dur=100ms, freq=466Hz, sample=70, buffer_id=06:46 [TRUNCATE prev:ch1 @15787.2ms -> 15960.3ms]
    db 0,0,100,0,58,125,5,9,233,0,58,5  ; n299 t=15.979s dur=100ms, freq=233Hz, sample=58, buffer_id=05:3A [TRUNCATE prev:ch9 @15849.7ms -> 15979.5ms]
    db 5,0,100,0,53,125,5,8,175,0,53,5  ; n300 t=15.979s dur=100ms, freq=175Hz, sample=53, buffer_id=05:35 [TRUNCATE prev:ch8 @15787.2ms -> 15979.5ms]
    db 0,0,100,0,50,108,9,12,156,0,50,8  ; n301 t=15.984s dur=100ms, freq=156Hz, sample=50, buffer_id=08:32 [TRUNCATE prev:ch12 @15878.6ms -> 15984.3ms]
    db 0,0,100,0,58,108,9,13,233,0,58,8  ; n302 t=15.984s dur=100ms, freq=233Hz, sample=58, buffer_id=08:3A [TRUNCATE prev:ch13 @15787.2ms -> 15984.3ms]
    db 0,0,100,0,31,108,9,5,58,0,31,8  ; n303 t=15.984s dur=100ms, freq=58Hz, sample=31, buffer_id=08:1F [TRUNCATE prev:ch5 @15792.0ms -> 15984.3ms]
    db 0,0,100,0,53,108,9,7,175,0,53,8  ; n304 t=15.984s dur=100ms, freq=175Hz, sample=53, buffer_id=08:35 [TRUNCATE prev:ch7 @15792.0ms -> 15984.3ms]
    db 19,0,100,0,47,108,9,10,117,0,47,8  ; n305 t=15.984s dur=100ms, freq=117Hz, sample=47, buffer_id=08:2F [TRUNCATE prev:ch10 @15792.0ms -> 15984.3ms]
    db 53,0,80,1,77,124,4,3,186,2,77,4  ; n306 t=16.004s dur=336ms, freq=698Hz, sample=77, buffer_id=04:4D [TRUNCATE prev:ch3 @15869.0ms -> 16003.6ms]
    db 96,0,100,0,70,102,6,2,11,2,70,6  ; n307 t=16.056s dur=100ms, freq=523Hz, sample=70, buffer_id=06:46 [TRUNCATE prev:ch2 @15878.6ms -> 16056.5ms]
    db 19,0,100,0,77,102,6,11,186,2,77,6  ; n308 t=16.153s dur=100ms, freq=698Hz, sample=77, buffer_id=06:4D [TRUNCATE prev:ch11 @15878.6ms -> 16152.6ms]
    db 0,0,100,0,58,125,5,9,233,0,58,5  ; n309 t=16.172s dur=100ms, freq=233Hz, sample=58, buffer_id=05:3A [TRUNCATE prev:ch9 @15979.5ms -> 16171.8ms]
    db 5,0,100,0,53,125,5,8,175,0,53,5  ; n310 t=16.172s dur=100ms, freq=175Hz, sample=53, buffer_id=05:35 [TRUNCATE prev:ch8 @15979.5ms -> 16171.8ms]
    db 0,0,100,0,58,108,9,13,233,0,58,8  ; n311 t=16.177s dur=100ms, freq=233Hz, sample=58, buffer_id=08:3A [TRUNCATE prev:ch13 @15984.3ms -> 16176.7ms]
    db 0,0,100,0,50,108,9,12,147,0,50,8  ; n312 t=16.177s dur=100ms, freq=147Hz, sample=50, buffer_id=08:32 [TRUNCATE prev:ch12 @15984.3ms -> 16176.7ms]
    db 0,0,100,0,31,108,9,5,58,0,31,8  ; n313 t=16.177s dur=100ms, freq=58Hz, sample=31, buffer_id=08:1F [TRUNCATE prev:ch5 @15984.3ms -> 16176.7ms]
    db 0,0,100,0,53,108,9,7,175,0,53,8  ; n314 t=16.177s dur=100ms, freq=175Hz, sample=53, buffer_id=08:35 [TRUNCATE prev:ch7 @15984.3ms -> 16176.7ms]
    db 67,0,100,0,47,108,9,10,117,0,47,8  ; n315 t=16.177s dur=100ms, freq=117Hz, sample=47, buffer_id=08:2F [TRUNCATE prev:ch10 @15984.3ms -> 16176.7ms]
    db 101,0,100,0,82,102,6,0,164,3,82,6  ; n316 t=16.244s dur=100ms, freq=932Hz, sample=82, buffer_id=06:52
    db 19,0,100,0,77,102,6,1,186,2,77,6  ; n317 t=16.345s dur=100ms, freq=698Hz, sample=77, buffer_id=06:4D
    db 0,0,100,0,53,125,5,2,175,0,53,5  ; n318 t=16.364s dur=100ms, freq=175Hz, sample=53, buffer_id=05:35
    db 5,0,100,0,58,125,5,4,233,0,58,5  ; n319 t=16.364s dur=100ms, freq=233Hz, sample=58, buffer_id=05:3A
    db 0,0,100,0,47,108,9,6,117,0,47,8  ; n320 t=16.369s dur=100ms, freq=117Hz, sample=47, buffer_id=08:2F
    db 0,0,100,0,53,108,9,7,175,0,53,8  ; n321 t=16.369s dur=100ms, freq=175Hz, sample=53, buffer_id=08:35 [TRUNCATE prev:ch7 @16176.7ms -> 16369.0ms]
    db 0,0,100,0,50,108,9,12,147,0,50,8  ; n322 t=16.369s dur=100ms, freq=147Hz, sample=50, buffer_id=08:32 [TRUNCATE prev:ch12 @16176.7ms -> 16369.0ms]
    db 0,0,100,0,58,108,9,13,233,0,58,8  ; n323 t=16.369s dur=100ms, freq=233Hz, sample=58, buffer_id=08:3A [TRUNCATE prev:ch13 @16176.7ms -> 16369.0ms]
    db 67,0,101,0,31,108,9,5,58,0,31,8  ; n324 t=16.369s dur=101ms, freq=58Hz, sample=31, buffer_id=08:1F [TRUNCATE prev:ch5 @16176.7ms -> 16369.0ms]
    db 120,0,100,0,70,102,6,3,11,2,70,6  ; n325 t=16.436s dur=100ms, freq=523Hz, sample=70, buffer_id=06:46 [TRUNCATE prev:ch3 @16003.6ms -> 16436.3ms]
    db 14,0,100,0,69,126,3,0,159,1,69,3  ; n326 t=16.556s dur=100ms, freq=415Hz, sample=69, buffer_id=03:45
    db 10,0,100,0,75,124,4,8,110,2,75,4  ; n327 t=16.571s dur=100ms, freq=622Hz, sample=75, buffer_id=04:4B
    db 24,0,100,0,70,102,6,9,210,1,70,6  ; n328 t=16.581s dur=100ms, freq=466Hz, sample=70, buffer_id=06:46
    db 135,0,100,0,72,126,3,10,11,2,72,3  ; n329 t=16.605s dur=100ms, freq=523Hz, sample=72, buffer_id=03:48
    db 38,0,100,0,74,124,4,1,75,2,74,4  ; n330 t=16.739s dur=100ms, freq=587Hz, sample=74, buffer_id=04:4A
    db 5,0,100,0,70,126,3,2,238,1,70,3  ; n331 t=16.778s dur=100ms, freq=494Hz, sample=70, buffer_id=03:46
    db 149,0,100,0,65,126,3,3,136,1,65,3  ; n332 t=16.782s dur=100ms, freq=392Hz, sample=65, buffer_id=03:41
    db 34,0,100,0,75,124,4,0,110,2,75,4  ; n333 t=16.931s dur=100ms, freq=622Hz, sample=75, buffer_id=04:4B
    db 5,0,100,0,69,126,3,4,159,1,69,3  ; n334 t=16.965s dur=100ms, freq=415Hz, sample=69, buffer_id=03:45
    db 159,0,100,0,72,126,3,5,11,2,72,3  ; n335 t=16.970s dur=100ms, freq=523Hz, sample=72, buffer_id=03:48
    db 19,0,177,4,72,124,4,1,11,2,72,4  ; n336 t=17.129s dur=1201ms, freq=523Hz, sample=72, buffer_id=04:48
    db 10,0,125,0,43,108,9,2,87,0,43,8  ; n337 t=17.148s dur=125ms, freq=87Hz, sample=43, buffer_id=08:2B
    db 5,0,9,4,69,126,3,3,184,1,69,3  ; n338 t=17.157s dur=1033ms, freq=440Hz, sample=69, buffer_id=03:45
    db 5,0,100,0,59,125,8,6,6,1,59,8  ; n339 t=17.162s dur=100ms, freq=262Hz, sample=59, buffer_id=08:3B
    db 72,0,251,3,65,126,3,7,93,1,65,3  ; n340 t=17.167s dur=1019ms, freq=349Hz, sample=65, buffer_id=03:41
    db 96,0,100,0,59,125,8,0,247,0,59,8  ; n341 t=17.239s dur=100ms, freq=247Hz, sample=59, buffer_id=08:3B
    db 87,0,100,0,59,125,8,4,6,1,59,8  ; n342 t=17.335s dur=100ms, freq=262Hz, sample=59, buffer_id=08:3B
    db 96,0,100,0,62,125,8,5,38,1,62,8  ; n343 t=17.422s dur=100ms, freq=294Hz, sample=62, buffer_id=08:3E
    db 82,0,100,0,63,125,8,2,55,1,63,8  ; n344 t=17.518s dur=100ms, freq=311Hz, sample=63, buffer_id=08:3F
    db 101,0,100,0,63,125,8,0,74,1,63,8  ; n345 t=17.600s dur=100ms, freq=330Hz, sample=63, buffer_id=08:3F
    db 91,0,100,0,65,125,8,4,93,1,65,8  ; n346 t=17.701s dur=100ms, freq=349Hz, sample=65, buffer_id=08:41
    db 96,0,100,0,63,125,8,5,74,1,63,8  ; n347 t=17.792s dur=100ms, freq=330Hz, sample=63, buffer_id=08:3F
    db 91,0,100,0,65,125,8,2,93,1,65,8  ; n348 t=17.888s dur=100ms, freq=349Hz, sample=65, buffer_id=08:41
    db 10,0,100,0,43,108,9,0,87,0,43,8  ; n349 t=17.980s dur=100ms, freq=87Hz, sample=43, buffer_id=08:2B
    db 87,0,100,0,67,125,8,6,136,1,67,8  ; n350 t=17.989s dur=100ms, freq=392Hz, sample=67, buffer_id=08:43
    db 5,0,100,0,43,108,9,4,87,0,43,8  ; n351 t=18.076s dur=100ms, freq=87Hz, sample=43, buffer_id=08:2B
    db 77,0,100,0,69,125,8,8,184,1,69,8  ; n352 t=18.081s dur=100ms, freq=440Hz, sample=69, buffer_id=08:45
    db 14,0,100,0,43,108,9,5,87,0,43,8  ; n353 t=18.157s dur=100ms, freq=87Hz, sample=43, buffer_id=08:2B
    db 106,0,100,0,70,125,8,9,210,1,70,8  ; n354 t=18.172s dur=100ms, freq=466Hz, sample=70, buffer_id=08:46
    db 5,0,144,0,43,108,9,2,87,0,43,8  ; n355 t=18.278s dur=144ms, freq=87Hz, sample=43, buffer_id=08:2B
    db 101,0,100,0,72,125,8,0,11,2,72,8  ; n356 t=18.282s dur=100ms, freq=523Hz, sample=72, buffer_id=08:48
    db 77,0,105,0,74,125,8,4,75,2,74,8  ; n357 t=18.383s dur=105ms, freq=587Hz, sample=74, buffer_id=08:4A
    db 91,0,101,0,75,125,8,3,110,2,75,8  ; n358 t=18.460s dur=101ms, freq=622Hz, sample=75, buffer_id=08:4B
    db 5,0,120,0,77,125,8,1,186,2,77,8  ; n359 t=18.552s dur=120ms, freq=698Hz, sample=77, buffer_id=08:4D
    db 0,0,100,0,65,124,4,5,93,1,65,4  ; n360 t=18.556s dur=100ms, freq=349Hz, sample=65, buffer_id=04:41
    db 91,0,125,0,43,108,9,6,87,0,43,8  ; n361 t=18.556s dur=125ms, freq=87Hz, sample=43, buffer_id=08:2B
    db 0,0,100,0,65,124,4,0,93,1,65,4  ; n362 t=18.648s dur=100ms, freq=349Hz, sample=65, buffer_id=04:41
    db 87,0,110,0,77,125,8,2,16,3,77,8  ; n363 t=18.648s dur=110ms, freq=784Hz, sample=77, buffer_id=08:4D
    db 10,0,144,0,82,125,8,4,112,3,82,8  ; n364 t=18.734s dur=144ms, freq=880Hz, sample=82, buffer_id=08:52
    db 111,0,100,0,65,124,4,7,93,1,65,4  ; n365 t=18.744s dur=100ms, freq=349Hz, sample=65, buffer_id=04:41
    db 0,0,48,4,70,124,4,3,210,1,70,4  ; n366 t=18.855s dur=1072ms, freq=466Hz, sample=70, buffer_id=04:46
    db 0,0,248,1,31,108,9,8,58,0,31,8  ; n367 t=18.855s dur=504ms, freq=58Hz, sample=31, buffer_id=08:1F
    db 10,0,248,1,47,108,9,9,117,0,47,8  ; n368 t=18.855s dur=504ms, freq=117Hz, sample=47, buffer_id=08:2F
    db 10,0,100,0,82,125,8,5,164,3,82,8  ; n369 t=18.864s dur=100ms, freq=932Hz, sample=82, buffer_id=08:52
    db 5,0,186,1,58,125,5,1,233,0,58,5  ; n370 t=18.874s dur=442ms, freq=233Hz, sample=58, buffer_id=05:3A
    db 188,0,51,1,50,126,3,10,147,0,50,3  ; n371 t=18.879s dur=307ms, freq=147Hz, sample=50, buffer_id=03:32
    db 87,0,125,0,82,125,8,0,164,3,82,8  ; n372 t=19.066s dur=125ms, freq=932Hz, sample=82, buffer_id=08:52
    db 96,0,115,0,82,125,8,2,112,3,82,8  ; n373 t=19.153s dur=115ms, freq=880Hz, sample=82, buffer_id=08:52
    db 82,0,101,0,82,125,8,6,164,3,82,8  ; n374 t=19.249s dur=101ms, freq=932Hz, sample=82, buffer_id=08:52
    db 87,0,120,0,82,125,8,7,112,3,82,8  ; n375 t=19.331s dur=120ms, freq=880Hz, sample=82, buffer_id=08:52
    db 5,0,101,0,82,125,8,10,164,3,82,8  ; n376 t=19.417s dur=101ms, freq=932Hz, sample=82, buffer_id=08:52
    db 0,0,210,1,31,108,9,0,55,0,31,8  ; n377 t=19.422s dur=466ms, freq=55Hz, sample=31, buffer_id=08:1F
    db 19,0,210,1,43,108,9,4,110,0,43,8  ; n378 t=19.422s dur=466ms, freq=110Hz, sample=43, buffer_id=08:2B
    db 14,0,143,1,58,125,5,5,233,0,58,5  ; n379 t=19.441s dur=399ms, freq=233Hz, sample=58, buffer_id=05:3A
    db 159,0,3,1,50,126,3,11,147,0,50,3  ; n380 t=19.456s dur=259ms, freq=147Hz, sample=50, buffer_id=03:32
    db 77,0,105,0,82,125,8,1,164,3,82,8  ; n381 t=19.614s dur=105ms, freq=932Hz, sample=82, buffer_id=08:52
    db 87,0,120,0,82,125,8,8,112,3,82,8  ; n382 t=19.691s dur=120ms, freq=880Hz, sample=82, buffer_id=08:52
    db 87,0,105,0,82,125,8,9,164,3,82,8  ; n383 t=19.778s dur=105ms, freq=932Hz, sample=82, buffer_id=08:52
    db 101,0,115,0,82,125,8,12,112,3,82,8  ; n384 t=19.864s dur=115ms, freq=880Hz, sample=82, buffer_id=08:52
    db 38,0,101,0,82,125,8,11,164,3,82,8  ; n385 t=19.965s dur=101ms, freq=932Hz, sample=82, buffer_id=08:52
    db 0,0,104,1,31,108,9,1,55,0,31,8  ; n386 t=20.004s dur=360ms, freq=55Hz, sample=31, buffer_id=08:1F
    db 5,0,104,1,43,108,9,2,110,0,43,8  ; n387 t=20.004s dur=360ms, freq=110Hz, sample=43, buffer_id=08:2B
    db 5,0,245,0,50,126,3,6,147,0,50,3  ; n388 t=20.008s dur=245ms, freq=147Hz, sample=50, buffer_id=03:32
    db 10,0,109,1,58,125,5,7,233,0,58,5  ; n389 t=20.013s dur=365ms, freq=233Hz, sample=58, buffer_id=05:3A
    db 163,0,81,4,77,124,4,8,186,2,77,4  ; n390 t=20.023s dur=1105ms, freq=698Hz, sample=77, buffer_id=04:4D
    db 91,0,120,0,82,125,8,0,164,3,82,8  ; n391 t=20.186s dur=120ms, freq=932Hz, sample=82, buffer_id=08:52
    db 58,0,120,0,82,125,8,3,112,3,82,8  ; n392 t=20.278s dur=120ms, freq=880Hz, sample=82, buffer_id=08:52
    db 0,0,100,0,31,108,9,4,55,0,31,8  ; n393 t=20.335s dur=100ms, freq=55Hz, sample=31, buffer_id=08:1F
    db 43,0,100,0,43,108,9,5,110,0,43,8  ; n394 t=20.335s dur=100ms, freq=110Hz, sample=43, buffer_id=08:2B
    db 87,0,110,0,82,125,8,13,164,3,82,8  ; n395 t=20.379s dur=110ms, freq=932Hz, sample=82, buffer_id=08:52
    db 5,0,100,0,58,125,5,6,233,0,58,5  ; n396 t=20.465s dur=100ms, freq=233Hz, sample=58, buffer_id=05:3A
    db 0,0,100,0,50,126,3,9,147,0,50,3  ; n397 t=20.470s dur=100ms, freq=147Hz, sample=50, buffer_id=03:32
    db 96,0,120,0,82,125,8,10,112,3,82,8  ; n398 t=20.470s dur=120ms, freq=880Hz, sample=82, buffer_id=08:52 [TRUNCATE prev:ch10 @19417.0ms -> 20469.9ms]
    db 10,0,100,0,82,125,8,1,164,3,82,8  ; n399 t=20.566s dur=100ms, freq=932Hz, sample=82, buffer_id=08:52
    db 5,0,100,0,58,125,5,0,233,0,58,5  ; n400 t=20.576s dur=100ms, freq=233Hz, sample=58, buffer_id=05:3A
    db 10,0,100,0,50,126,3,2,147,0,50,3  ; n401 t=20.581s dur=100ms, freq=147Hz, sample=50, buffer_id=03:32
    db 0,0,100,0,47,108,9,7,117,0,47,8  ; n402 t=20.590s dur=100ms, freq=117Hz, sample=47, buffer_id=08:2F
    db 173,0,100,0,31,108,9,11,58,0,31,8  ; n403 t=20.590s dur=100ms, freq=58Hz, sample=31, buffer_id=08:1F
    db 14,0,120,0,82,125,8,4,164,3,82,8  ; n404 t=20.763s dur=120ms, freq=932Hz, sample=82, buffer_id=08:52
    db 0,0,100,0,31,108,9,3,58,0,31,8  ; n405 t=20.778s dur=100ms, freq=58Hz, sample=31, buffer_id=08:1F
    db 24,0,100,0,47,108,9,5,117,0,47,8  ; n406 t=20.778s dur=100ms, freq=117Hz, sample=47, buffer_id=08:2F
    db 10,0,100,0,50,126,3,6,147,0,50,3  ; n407 t=20.802s dur=100ms, freq=147Hz, sample=50, buffer_id=03:32
    db 38,0,100,0,58,125,5,9,233,0,58,5  ; n408 t=20.811s dur=100ms, freq=233Hz, sample=58, buffer_id=05:3A
    db 87,0,120,0,82,125,8,12,112,3,82,8  ; n409 t=20.850s dur=120ms, freq=880Hz, sample=82, buffer_id=08:52 [TRUNCATE prev:ch12 @19864.1ms -> 20849.7ms]
    db 0,0,105,0,31,108,9,0,55,0,31,8  ; n410 t=20.936s dur=105ms, freq=55Hz, sample=31, buffer_id=08:1F
    db 19,0,105,0,43,108,9,1,110,0,43,8  ; n411 t=20.936s dur=105ms, freq=110Hz, sample=43, buffer_id=08:2B
    db 14,0,110,0,82,125,8,2,164,3,82,8  ; n412 t=20.956s dur=110ms, freq=932Hz, sample=82, buffer_id=08:52
    db 10,0,100,0,50,126,3,7,147,0,50,3  ; n413 t=20.970s dur=100ms, freq=147Hz, sample=50, buffer_id=03:32
    db 58,0,100,0,58,125,5,10,233,0,58,5  ; n414 t=20.980s dur=100ms, freq=233Hz, sample=58, buffer_id=05:3A
    db 111,0,120,0,82,125,8,11,112,3,82,8  ; n415 t=21.037s dur=120ms, freq=880Hz, sample=82, buffer_id=08:52
    db 14,0,101,0,82,125,8,3,164,3,82,8  ; n416 t=21.148s dur=101ms, freq=932Hz, sample=82, buffer_id=08:52
    db 0,0,7,2,31,108,9,4,49,0,31,8  ; n417 t=21.162s dur=519ms, freq=49Hz, sample=31, buffer_id=08:1F
    db 10,0,7,2,43,108,9,5,98,0,43,8  ; n418 t=21.162s dur=519ms, freq=98Hz, sample=43, buffer_id=08:2B
    db 5,0,130,1,50,126,3,9,156,0,50,3  ; n419 t=21.172s dur=386ms, freq=156Hz, sample=50, buffer_id=03:32
    db 5,0,100,0,75,124,4,6,110,2,75,4  ; n420 t=21.177s dur=100ms, freq=622Hz, sample=75, buffer_id=04:4B
    db 173,0,162,1,63,125,5,12,55,1,63,5  ; n421 t=21.181s dur=418ms, freq=311Hz, sample=63, buffer_id=05:3F
    db 10,0,100,0,74,124,4,0,75,2,74,4  ; n422 t=21.355s dur=100ms, freq=587Hz, sample=74, buffer_id=04:4A
    db 62,0,101,0,82,125,8,1,164,3,82,8  ; n423 t=21.364s dur=101ms, freq=932Hz, sample=82, buffer_id=08:52
    db 111,0,129,0,82,125,8,7,112,3,82,8  ; n424 t=21.427s dur=129ms, freq=880Hz, sample=82, buffer_id=08:52
    db 5,0,105,0,82,125,8,6,164,3,82,8  ; n425 t=21.537s dur=105ms, freq=932Hz, sample=82, buffer_id=08:52
    db 72,0,100,0,72,124,4,2,11,2,72,4  ; n426 t=21.542s dur=100ms, freq=523Hz, sample=72, buffer_id=04:48
    db 101,0,129,0,82,125,8,8,112,3,82,8  ; n427 t=21.614s dur=129ms, freq=880Hz, sample=82, buffer_id=08:52
    db 0,0,42,1,53,126,3,0,175,0,53,3  ; n428 t=21.715s dur=298ms, freq=175Hz, sample=53, buffer_id=03:35
    db 14,0,100,0,82,125,8,10,164,3,82,8  ; n429 t=21.715s dur=100ms, freq=932Hz, sample=82, buffer_id=08:52
    db 19,0,22,1,63,125,5,1,55,1,63,5  ; n430 t=21.730s dur=278ms, freq=311Hz, sample=63, buffer_id=05:3F
    db 0,0,133,1,31,108,9,3,49,0,31,8  ; n431 t=21.749s dur=389ms, freq=49Hz, sample=31, buffer_id=08:1F
    db 5,0,133,1,43,108,9,11,98,0,43,8  ; n432 t=21.749s dur=389ms, freq=98Hz, sample=43, buffer_id=08:2B
    db 163,0,57,4,82,124,4,13,164,3,82,4  ; n433 t=21.754s dur=1081ms, freq=932Hz, sample=82, buffer_id=04:52
    db 82,0,115,0,82,125,8,2,164,3,82,8  ; n434 t=21.917s dur=115ms, freq=932Hz, sample=82, buffer_id=08:52
    db 91,0,125,0,82,125,8,4,112,3,82,8  ; n435 t=21.999s dur=125ms, freq=880Hz, sample=82, buffer_id=08:52
    db 14,0,129,0,55,126,3,5,196,0,55,3  ; n436 t=22.090s dur=129ms, freq=196Hz, sample=55, buffer_id=03:37
    db 0,0,101,0,63,125,5,6,55,1,63,5  ; n437 t=22.105s dur=101ms, freq=311Hz, sample=63, buffer_id=05:3F
    db 43,0,115,0,82,125,8,9,164,3,82,8  ; n438 t=22.105s dur=115ms, freq=932Hz, sample=82, buffer_id=08:52
    db 0,0,101,0,38,108,9,7,78,0,38,8  ; n439 t=22.148s dur=101ms, freq=78Hz, sample=38, buffer_id=08:26
    db 43,0,101,0,50,108,9,8,156,0,50,8  ; n440 t=22.148s dur=101ms, freq=156Hz, sample=50, buffer_id=08:32
    db 101,0,120,0,82,125,8,12,112,3,82,8  ; n441 t=22.191s dur=120ms, freq=880Hz, sample=82, buffer_id=08:52
    db 38,0,100,0,82,125,8,0,164,3,82,8  ; n442 t=22.292s dur=100ms, freq=932Hz, sample=82, buffer_id=08:52
    db 0,0,100,0,38,108,9,1,78,0,38,8  ; n443 t=22.331s dur=100ms, freq=78Hz, sample=38, buffer_id=08:26
    db 19,0,100,0,50,108,9,2,156,0,50,8  ; n444 t=22.331s dur=100ms, freq=156Hz, sample=50, buffer_id=08:32
    db 5,0,152,1,63,125,5,3,55,1,63,5  ; n445 t=22.350s dur=408ms, freq=311Hz, sample=63, buffer_id=05:3F
    db 144,0,157,1,55,126,3,4,196,0,55,3  ; n446 t=22.355s dur=413ms, freq=196Hz, sample=55, buffer_id=03:37
    db 34,0,115,0,82,125,8,5,164,3,82,8  ; n447 t=22.499s dur=115ms, freq=932Hz, sample=82, buffer_id=08:52
    db 0,0,100,0,38,108,9,6,73,0,38,8  ; n448 t=22.532s dur=100ms, freq=73Hz, sample=38, buffer_id=08:26
    db 48,0,100,0,50,108,9,7,147,0,50,8  ; n449 t=22.532s dur=100ms, freq=147Hz, sample=50, buffer_id=08:32
    db 111,0,129,0,82,125,8,8,112,3,82,8  ; n450 t=22.581s dur=129ms, freq=880Hz, sample=82, buffer_id=08:52
    db 34,0,110,0,82,125,8,1,164,3,82,8  ; n451 t=22.691s dur=110ms, freq=932Hz, sample=82, buffer_id=08:52
    db 0,0,100,0,38,108,9,0,65,0,38,8  ; n452 t=22.725s dur=100ms, freq=65Hz, sample=38, buffer_id=08:26
    db 58,0,100,0,47,108,9,2,131,0,47,8  ; n453 t=22.725s dur=100ms, freq=131Hz, sample=47, buffer_id=08:2F
    db 96,0,115,0,82,125,8,11,112,3,82,8  ; n454 t=22.782s dur=115ms, freq=880Hz, sample=82, buffer_id=08:52
    db 5,0,133,1,63,125,5,5,38,1,63,5  ; n455 t=22.879s dur=389ms, freq=294Hz, sample=63, buffer_id=05:3F
    db 5,0,152,1,58,125,5,6,233,0,58,5  ; n456 t=22.883s dur=408ms, freq=233Hz, sample=58, buffer_id=05:3A
    db 10,0,138,1,53,126,3,7,175,0,53,3  ; n457 t=22.888s dur=394ms, freq=175Hz, sample=53, buffer_id=03:35
    db 10,0,100,0,82,125,8,10,164,3,82,8  ; n458 t=22.898s dur=100ms, freq=932Hz, sample=82, buffer_id=08:52 [TRUNCATE prev:ch10 @21715.1ms -> 22897.8ms]
    db 29,0,215,1,77,124,4,9,186,2,77,4  ; n459 t=22.907s dur=471ms, freq=698Hz, sample=77, buffer_id=04:4D
    db 0,0,100,0,31,108,9,8,58,0,31,8  ; n460 t=22.936s dur=100ms, freq=58Hz, sample=31, buffer_id=08:1F
    db 173,0,100,0,47,108,9,12,117,0,47,8  ; n461 t=22.936s dur=100ms, freq=117Hz, sample=47, buffer_id=08:2F
    db 10,0,110,0,82,125,8,0,164,3,82,8  ; n462 t=23.109s dur=110ms, freq=932Hz, sample=82, buffer_id=08:52
    db 0,0,100,0,31,108,9,1,55,0,31,8  ; n463 t=23.119s dur=100ms, freq=55Hz, sample=31, buffer_id=08:1F
    db 72,0,100,0,43,108,9,2,110,0,43,8  ; n464 t=23.119s dur=100ms, freq=110Hz, sample=43, buffer_id=08:2B
    db 101,0,125,0,82,125,8,3,112,3,82,8  ; n465 t=23.191s dur=125ms, freq=880Hz, sample=82, buffer_id=08:52
    db 10,0,110,0,82,125,8,4,164,3,82,8  ; n466 t=23.292s dur=110ms, freq=932Hz, sample=82, buffer_id=08:52
    db 0,0,101,0,31,108,9,10,49,0,31,8  ; n467 t=23.302s dur=101ms, freq=49Hz, sample=31, buffer_id=08:1F
    db 82,0,101,0,43,108,9,8,98,0,43,8  ; n468 t=23.302s dur=101ms, freq=98Hz, sample=43, buffer_id=08:2B
    db 91,0,120,0,82,125,8,12,112,3,82,8  ; n469 t=23.383s dur=120ms, freq=880Hz, sample=82, buffer_id=08:52
    db 5,0,100,0,82,125,8,1,164,3,82,8  ; n470 t=23.475s dur=100ms, freq=932Hz, sample=82, buffer_id=08:52
    db 0,0,130,1,50,126,3,0,156,0,50,3  ; n471 t=23.480s dur=386ms, freq=156Hz, sample=50, buffer_id=03:32
    db 0,0,100,0,75,124,4,2,110,2,75,4  ; n472 t=23.480s dur=100ms, freq=622Hz, sample=75, buffer_id=04:4B
    db 0,0,167,1,63,125,5,11,55,1,63,5  ; n473 t=23.480s dur=423ms, freq=311Hz, sample=63, buffer_id=05:3F
    db 34,0,176,1,58,125,5,5,233,0,58,5  ; n474 t=23.480s dur=432ms, freq=233Hz, sample=58, buffer_id=05:3A
    db 0,0,152,1,29,108,9,6,44,0,29,8  ; n475 t=23.513s dur=408ms, freq=44Hz, sample=29, buffer_id=08:1D
    db 159,0,152,1,43,108,9,7,87,0,43,8  ; n476 t=23.513s dur=408ms, freq=87Hz, sample=43, buffer_id=08:2B
    db 0,0,100,0,74,124,4,3,75,2,74,4  ; n477 t=23.672s dur=100ms, freq=587Hz, sample=74, buffer_id=04:4A
    db 62,0,100,0,82,125,8,8,164,3,82,8  ; n478 t=23.672s dur=100ms, freq=932Hz, sample=82, buffer_id=08:52
    db 106,0,139,0,82,125,8,9,112,3,82,8  ; n479 t=23.734s dur=139ms, freq=880Hz, sample=82, buffer_id=08:52
    db 10,0,115,0,82,125,8,2,164,3,82,8  ; n480 t=23.840s dur=115ms, freq=932Hz, sample=82, buffer_id=08:52
    db 87,0,100,0,72,124,4,1,11,2,72,4  ; n481 t=23.850s dur=100ms, freq=523Hz, sample=72, buffer_id=04:48
    db 111,0,110,0,82,125,8,10,112,3,82,8  ; n482 t=23.936s dur=110ms, freq=880Hz, sample=82, buffer_id=08:52
    db 10,0,100,0,82,125,8,3,164,3,82,8  ; n483 t=24.047s dur=100ms, freq=932Hz, sample=82, buffer_id=08:52
    db 0,0,100,0,50,126,3,4,156,0,50,3  ; n484 t=24.056s dur=100ms, freq=156Hz, sample=50, buffer_id=03:32
    db 0,0,100,0,63,126,3,8,55,1,63,3  ; n485 t=24.056s dur=100ms, freq=311Hz, sample=63, buffer_id=03:3F
    db 0,0,110,4,82,124,4,12,164,3,82,4  ; n486 t=24.056s dur=1134ms, freq=932Hz, sample=82, buffer_id=04:52
    db 0,0,100,0,58,125,5,13,233,0,58,5  ; n487 t=24.056s dur=100ms, freq=233Hz, sample=58, buffer_id=05:3A
    db 5,0,100,0,63,125,5,11,55,1,63,5  ; n488 t=24.056s dur=100ms, freq=311Hz, sample=63, buffer_id=05:3F [TRUNCATE prev:ch11 @23479.5ms -> 24056.5ms]
    db 0,0,125,0,31,108,9,0,49,0,31,8  ; n489 t=24.061s dur=125ms, freq=49Hz, sample=31, buffer_id=08:1F [TRUNCATE prev:ch0 @23479.5ms -> 24061.3ms]
    db 192,0,125,0,43,108,9,7,98,0,43,8  ; n490 t=24.061s dur=125ms, freq=98Hz, sample=43, buffer_id=08:2B [TRUNCATE prev:ch7 @23513.2ms -> 24061.3ms]
    db 0,0,100,0,50,126,3,1,156,0,50,3  ; n491 t=24.254s dur=100ms, freq=156Hz, sample=50, buffer_id=03:32
    db 0,0,100,0,63,126,3,2,55,1,63,3  ; n492 t=24.254s dur=100ms, freq=311Hz, sample=63, buffer_id=03:3F
    db 0,0,100,0,63,125,5,5,55,1,63,5  ; n493 t=24.254s dur=100ms, freq=311Hz, sample=63, buffer_id=05:3F
    db 0,0,100,0,58,125,5,6,233,0,58,5  ; n494 t=24.254s dur=100ms, freq=233Hz, sample=58, buffer_id=05:3A
    db 72,0,110,0,82,125,8,9,164,3,82,8  ; n495 t=24.254s dur=110ms, freq=932Hz, sample=82, buffer_id=08:52 [TRUNCATE prev:ch9 @23734.3ms -> 24253.6ms]
    db 0,0,125,0,31,108,9,10,55,0,31,8  ; n496 t=24.326s dur=125ms, freq=55Hz, sample=31, buffer_id=08:1F
    db 10,0,125,0,43,108,9,7,110,0,43,8  ; n497 t=24.326s dur=125ms, freq=110Hz, sample=43, buffer_id=08:2B [TRUNCATE prev:ch7 @24061.3ms -> 24325.7ms]
    db 96,0,129,0,82,125,8,3,112,3,82,8  ; n498 t=24.335s dur=129ms, freq=880Hz, sample=82, buffer_id=08:52 [TRUNCATE prev:ch3 @24046.8ms -> 24335.3ms]
    db 0,0,100,0,63,126,3,0,55,1,63,3  ; n499 t=24.431s dur=100ms, freq=311Hz, sample=63, buffer_id=03:3F
    db 0,0,100,0,50,126,3,8,156,0,50,3  ; n500 t=24.431s dur=100ms, freq=156Hz, sample=50, buffer_id=03:32
    db 0,0,100,0,58,125,5,4,233,0,58,5  ; n501 t=24.431s dur=100ms, freq=233Hz, sample=58, buffer_id=05:3A
    db 10,0,100,0,63,125,5,13,55,1,63,5  ; n502 t=24.431s dur=100ms, freq=311Hz, sample=63, buffer_id=05:3F
    db 96,0,129,0,82,125,8,11,164,3,82,8  ; n503 t=24.441s dur=129ms, freq=932Hz, sample=82, buffer_id=08:52
    db 67,0,101,0,82,125,8,9,112,3,82,8  ; n504 t=24.537s dur=101ms, freq=880Hz, sample=82, buffer_id=08:52 [TRUNCATE prev:ch9 @24253.6ms -> 24537.2ms]
    db 0,0,101,0,31,108,9,1,58,0,31,8  ; n505 t=24.605s dur=101ms, freq=58Hz, sample=31, buffer_id=08:1F
    db 29,0,101,0,47,108,9,2,117,0,47,8  ; n506 t=24.605s dur=101ms, freq=117Hz, sample=47, buffer_id=08:2F
    db 0,0,186,1,58,126,3,5,233,0,58,3  ; n507 t=24.633s dur=442ms, freq=233Hz, sample=58, buffer_id=03:3A
    db 0,0,224,1,58,126,3,6,220,0,58,3  ; n508 t=24.633s dur=480ms, freq=220Hz, sample=58, buffer_id=03:3A
    db 5,0,186,1,58,125,5,4,233,0,58,5  ; n509 t=24.633s dur=442ms, freq=233Hz, sample=58, buffer_id=05:3A [TRUNCATE prev:ch4 @24431.5ms -> 24633.4ms]
    db 0,0,191,1,62,126,3,12,38,1,62,3  ; n510 t=24.638s dur=447ms, freq=294Hz, sample=62, buffer_id=03:3E [TRUNCATE prev:ch12 @24056.5ms -> 24638.2ms]
    db 0,0,191,1,63,125,5,13,38,1,63,5  ; n511 t=24.638s dur=447ms, freq=294Hz, sample=63, buffer_id=05:3F [TRUNCATE prev:ch13 @24431.5ms -> 24638.2ms]
    db 163,0,100,0,82,125,8,3,164,3,82,8  ; n512 t=24.638s dur=100ms, freq=932Hz, sample=82, buffer_id=08:52 [TRUNCATE prev:ch3 @24335.3ms -> 24638.2ms]
    db 0,0,100,0,31,108,9,0,55,0,31,8  ; n513 t=24.802s dur=100ms, freq=55Hz, sample=31, buffer_id=08:1F
    db 29,0,100,0,43,108,9,8,110,0,43,8  ; n514 t=24.802s dur=100ms, freq=110Hz, sample=43, buffer_id=08:2B
    db 58,0,100,0,82,125,8,7,164,3,82,8  ; n515 t=24.831s dur=100ms, freq=932Hz, sample=82, buffer_id=08:52
    db 96,0,139,0,82,125,8,10,112,3,82,8  ; n516 t=24.888s dur=139ms, freq=880Hz, sample=82, buffer_id=08:52
    db 0,0,105,0,31,108,9,2,49,0,31,8  ; n517 t=24.984s dur=105ms, freq=49Hz, sample=31, buffer_id=08:1F
    db 10,0,105,0,43,108,9,1,98,0,43,8  ; n518 t=24.984s dur=105ms, freq=98Hz, sample=43, buffer_id=08:2B
    db 96,0,120,0,82,125,8,11,164,3,82,8  ; n519 t=24.994s dur=120ms, freq=932Hz, sample=82, buffer_id=08:52 [TRUNCATE prev:ch11 @24441.1ms -> 24994.0ms]
    db 106,0,120,0,82,125,8,9,112,3,82,8  ; n520 t=25.090s dur=120ms, freq=880Hz, sample=82, buffer_id=08:52 [TRUNCATE prev:ch9 @24537.2ms -> 25090.1ms]
    db 0,0,100,0,82,125,8,0,164,3,82,8  ; n521 t=25.196s dur=100ms, freq=932Hz, sample=82, buffer_id=08:52
    db 0,0,134,0,29,108,9,3,44,0,29,8  ; n522 t=25.196s dur=134ms, freq=44Hz, sample=29, buffer_id=08:1D
    db 5,0,134,0,43,108,9,7,87,0,43,8  ; n523 t=25.196s dur=134ms, freq=87Hz, sample=43, buffer_id=08:2B
    db 0,0,100,0,62,126,3,8,38,1,62,3  ; n524 t=25.201s dur=100ms, freq=294Hz, sample=62, buffer_id=03:3E
    db 10,0,100,0,63,125,5,13,38,1,63,5  ; n525 t=25.201s dur=100ms, freq=294Hz, sample=63, buffer_id=05:3F [TRUNCATE prev:ch13 @24638.2ms -> 25200.7ms]
    db 0,0,100,0,58,126,3,5,233,0,58,3  ; n526 t=25.210s dur=100ms, freq=233Hz, sample=58, buffer_id=03:3A [TRUNCATE prev:ch5 @24633.4ms -> 25210.3ms]
    db 0,0,16,2,77,124,4,4,186,2,77,4  ; n527 t=25.210s dur=528ms, freq=698Hz, sample=77, buffer_id=04:4D [TRUNCATE prev:ch4 @24633.4ms -> 25210.3ms]
    db 173,0,100,0,58,125,5,6,233,0,58,5  ; n528 t=25.210s dur=100ms, freq=233Hz, sample=58, buffer_id=05:3A [TRUNCATE prev:ch6 @24633.4ms -> 25210.3ms]
    db 0,0,100,0,62,126,3,1,38,1,62,3  ; n529 t=25.383s dur=100ms, freq=294Hz, sample=62, buffer_id=03:3E
    db 5,0,100,0,63,125,5,2,38,1,63,5  ; n530 t=25.383s dur=100ms, freq=294Hz, sample=63, buffer_id=05:3F
    db 0,0,100,0,58,126,3,10,233,0,58,3  ; n531 t=25.388s dur=100ms, freq=233Hz, sample=58, buffer_id=03:3A
    db 5,0,100,0,58,125,5,11,233,0,58,5  ; n532 t=25.388s dur=100ms, freq=233Hz, sample=58, buffer_id=05:3A
    db 82,0,110,0,82,125,8,12,164,3,82,8  ; n533 t=25.393s dur=110ms, freq=932Hz, sample=82, buffer_id=08:52
    db 19,0,129,0,82,125,8,9,112,3,82,8  ; n534 t=25.475s dur=129ms, freq=880Hz, sample=82, buffer_id=08:52 [TRUNCATE prev:ch9 @25090.1ms -> 25474.7ms]
    db 0,0,163,0,31,108,9,0,58,0,31,8  ; n535 t=25.494s dur=163ms, freq=58Hz, sample=31, buffer_id=08:1F [TRUNCATE prev:ch0 @25195.9ms -> 25494.0ms]
    db 77,0,163,0,47,108,9,3,117,0,47,8  ; n536 t=25.494s dur=163ms, freq=117Hz, sample=47, buffer_id=08:2F [TRUNCATE prev:ch3 @25195.9ms -> 25494.0ms]
    db 0,0,100,0,62,126,3,5,38,1,62,3  ; n537 t=25.571s dur=100ms, freq=294Hz, sample=62, buffer_id=03:3E
    db 10,0,100,0,63,125,5,6,38,1,63,5  ; n538 t=25.571s dur=100ms, freq=294Hz, sample=63, buffer_id=05:3F
    db 0,0,100,0,58,126,3,7,233,0,58,3  ; n539 t=25.581s dur=100ms, freq=233Hz, sample=58, buffer_id=03:3A
    db 5,0,100,0,58,125,5,8,233,0,58,5  ; n540 t=25.581s dur=100ms, freq=233Hz, sample=58, buffer_id=05:3A
    db 87,0,125,0,82,125,8,13,164,3,82,8  ; n541 t=25.585s dur=125ms, freq=932Hz, sample=82, buffer_id=08:52
    db 101,0,110,0,82,125,8,12,112,3,82,8  ; n542 t=25.672s dur=110ms, freq=880Hz, sample=82, buffer_id=08:52 [TRUNCATE prev:ch12 @25393.0ms -> 25671.8ms]
    db 5,0,162,1,53,108,9,1,175,0,53,8  ; n543 t=25.773s dur=418ms, freq=175Hz, sample=53, buffer_id=08:35
    db 0,0,100,0,72,126,3,2,11,2,72,3  ; n544 t=25.778s dur=100ms, freq=523Hz, sample=72, buffer_id=03:48
    db 0,0,100,0,69,126,3,10,159,1,69,3  ; n545 t=25.778s dur=100ms, freq=415Hz, sample=69, buffer_id=03:45
    db 0,0,100,0,63,125,5,11,55,1,63,5  ; n546 t=25.778s dur=100ms, freq=311Hz, sample=63, buffer_id=05:3F
    db 0,0,100,0,58,125,5,8,6,1,58,5  ; n547 t=25.778s dur=100ms, freq=262Hz, sample=58, buffer_id=05:3A [TRUNCATE prev:ch8 @25580.5ms -> 25777.6ms]
    db 5,0,191,1,43,108,9,4,87,0,43,8  ; n548 t=25.778s dur=447ms, freq=87Hz, sample=43, buffer_id=08:2B [TRUNCATE prev:ch4 @25210.3ms -> 25777.6ms]
    db 14,0,100,0,56,108,9,9,208,0,56,8  ; n549 t=25.782s dur=100ms, freq=208Hz, sample=56, buffer_id=08:38 [TRUNCATE prev:ch9 @25474.7ms -> 25782.4ms]
    db 5,0,100,0,82,125,8,13,63,3,82,8  ; n550 t=25.797s dur=100ms, freq=831Hz, sample=82, buffer_id=08:52 [TRUNCATE prev:ch13 @25585.3ms -> 25796.8ms]
    db 154,0,100,0,75,124,4,0,110,2,75,4  ; n551 t=25.802s dur=100ms, freq=622Hz, sample=75, buffer_id=04:4B [TRUNCATE prev:ch0 @25494.0ms -> 25801.6ms]
    db 10,0,100,0,55,108,9,3,196,0,55,8  ; n552 t=25.956s dur=100ms, freq=196Hz, sample=55, buffer_id=08:37
    db 14,0,100,0,77,125,8,5,16,3,77,8  ; n553 t=25.965s dur=100ms, freq=784Hz, sample=77, buffer_id=08:4D
    db 0,0,100,0,70,126,3,6,238,1,70,3  ; n554 t=25.980s dur=100ms, freq=494Hz, sample=70, buffer_id=03:46
    db 0,0,100,0,65,126,3,7,136,1,65,3  ; n555 t=25.980s dur=100ms, freq=392Hz, sample=65, buffer_id=03:41
    db 0,0,100,0,63,125,5,11,38,1,63,5  ; n556 t=25.980s dur=100ms, freq=294Hz, sample=63, buffer_id=05:3F [TRUNCATE prev:ch11 @25777.6ms -> 25979.5ms]
    db 10,0,100,0,58,125,5,8,247,0,58,5  ; n557 t=25.980s dur=100ms, freq=247Hz, sample=58, buffer_id=05:3A [TRUNCATE prev:ch8 @25777.6ms -> 25979.5ms]
    db 149,0,100,0,74,124,4,12,75,2,74,4  ; n558 t=25.989s dur=100ms, freq=587Hz, sample=74, buffer_id=04:4A
    db 14,0,100,0,82,125,8,0,63,3,82,8  ; n559 t=26.138s dur=100ms, freq=831Hz, sample=82, buffer_id=08:52
    db 19,0,100,0,56,108,9,2,208,0,56,8  ; n560 t=26.153s dur=100ms, freq=208Hz, sample=56, buffer_id=08:38
    db 0,0,100,0,69,126,3,9,159,1,69,3  ; n561 t=26.172s dur=100ms, freq=415Hz, sample=69, buffer_id=03:45
    db 5,0,100,0,58,125,5,10,6,1,58,5  ; n562 t=26.172s dur=100ms, freq=262Hz, sample=58, buffer_id=05:3A
    db 0,0,100,0,72,126,3,13,11,2,72,3  ; n563 t=26.177s dur=100ms, freq=523Hz, sample=72, buffer_id=03:48
    db 0,0,100,0,75,124,4,1,110,2,75,4  ; n564 t=26.177s dur=100ms, freq=622Hz, sample=75, buffer_id=04:4B [TRUNCATE prev:ch1 @25772.8ms -> 26176.6ms]
    db 144,0,100,0,63,125,5,11,55,1,63,5  ; n565 t=26.177s dur=100ms, freq=311Hz, sample=63, buffer_id=05:3F [TRUNCATE prev:ch11 @25979.5ms -> 26176.6ms]
    db 0,0,234,1,77,125,8,3,186,2,77,8  ; n566 t=26.321s dur=490ms, freq=698Hz, sample=77, buffer_id=08:4D
    db 5,0,100,0,29,108,9,5,44,0,29,8  ; n567 t=26.321s dur=100ms, freq=44Hz, sample=29, buffer_id=08:1D
    db 10,0,100,0,43,108,9,6,87,0,43,8  ; n568 t=26.326s dur=100ms, freq=87Hz, sample=43, buffer_id=08:2B
    db 29,0,226,4,53,108,9,7,175,0,53,8  ; n569 t=26.335s dur=1250ms, freq=175Hz, sample=53, buffer_id=08:35
    db 5,0,38,4,72,124,4,8,11,2,72,4  ; n570 t=26.364s dur=1062ms, freq=523Hz, sample=72, buffer_id=04:48
    db 0,0,212,3,69,126,3,12,184,1,69,3  ; n571 t=26.369s dur=980ms, freq=440Hz, sample=69, buffer_id=03:45
    db 0,0,232,3,65,126,3,4,93,1,65,3  ; n572 t=26.369s dur=1000ms, freq=349Hz, sample=65, buffer_id=03:41 [TRUNCATE prev:ch4 @25777.6ms -> 26369.0ms]
    db 0,0,252,3,58,125,5,10,6,1,58,5  ; n573 t=26.369s dur=1020ms, freq=262Hz, sample=58, buffer_id=05:3A [TRUNCATE prev:ch10 @26171.8ms -> 26369.0ms]
    db 125,0,57,4,58,125,5,0,220,0,58,5  ; n574 t=26.369s dur=1081ms, freq=220Hz, sample=58, buffer_id=05:3A [TRUNCATE prev:ch0 @26138.2ms -> 26369.0ms]
    db 14,0,100,0,29,108,9,1,44,0,29,8  ; n575 t=26.494s dur=100ms, freq=44Hz, sample=29, buffer_id=08:1D
    db 168,0,100,0,43,108,9,2,87,0,43,8  ; n576 t=26.508s dur=100ms, freq=87Hz, sample=43, buffer_id=08:2B
    db 10,0,100,0,29,108,9,6,44,0,29,8  ; n577 t=26.677s dur=100ms, freq=44Hz, sample=29, buffer_id=08:1D
    db 212,0,105,0,43,108,9,5,87,0,43,8  ; n578 t=26.686s dur=105ms, freq=87Hz, sample=43, buffer_id=08:2B
    db 10,0,248,1,29,108,9,2,44,0,29,8  ; n579 t=26.898s dur=504ms, freq=44Hz, sample=29, buffer_id=08:1D
    db 55,2,239,1,43,108,9,1,87,0,43,8  ; n580 t=26.907s dur=495ms, freq=87Hz, sample=43, buffer_id=08:2B
    db 0,0,143,1,77,125,8,5,186,2,77,8  ; n581 t=27.475s dur=399ms, freq=698Hz, sample=77, buffer_id=08:4D
    db 43,0,66,1,65,108,9,3,93,1,65,8  ; n582 t=27.475s dur=322ms, freq=349Hz, sample=65, buffer_id=08:41
    db 153,1,192,0,29,108,9,9,44,0,29,8  ; n583 t=27.518s dur=192ms, freq=44Hz, sample=29, buffer_id=08:1D
    db 0,0,173,0,77,125,8,0,186,2,77,8  ; n584 t=27.927s dur=173ms, freq=698Hz, sample=77, buffer_id=08:4D
    db 173,0,173,0,65,108,9,1,93,1,65,8  ; n585 t=27.927s dur=173ms, freq=349Hz, sample=65, buffer_id=08:41
    db 0,0,239,1,55,126,3,2,196,0,55,3  ; n586 t=28.100s dur=495ms, freq=196Hz, sample=55, buffer_id=03:37
    db 0,0,180,1,77,125,8,3,16,3,77,8  ; n587 t=28.100s dur=436ms, freq=784Hz, sample=77, buffer_id=08:4D
    db 5,0,25,3,67,108,9,4,136,1,67,8  ; n588 t=28.100s dur=793ms, freq=392Hz, sample=67, buffer_id=08:43
    db 0,0,224,1,63,126,3,5,55,1,63,3  ; n589 t=28.105s dur=480ms, freq=311Hz, sample=63, buffer_id=03:3F
    db 87,0,100,0,65,102,6,6,93,1,65,6  ; n590 t=28.105s dur=100ms, freq=349Hz, sample=65, buffer_id=06:41
    db 77,0,100,0,67,102,6,7,136,1,67,6  ; n591 t=28.191s dur=100ms, freq=392Hz, sample=67, buffer_id=06:43
    db 96,0,100,0,70,102,6,8,210,1,70,6  ; n592 t=28.268s dur=100ms, freq=466Hz, sample=70, buffer_id=06:46
    db 82,0,100,0,75,102,6,0,110,2,75,6  ; n593 t=28.364s dur=100ms, freq=622Hz, sample=75, buffer_id=06:4B
    db 86,0,100,0,77,102,6,1,186,2,77,6  ; n594 t=28.446s dur=100ms, freq=698Hz, sample=77, buffer_id=06:4D
    db 82,0,100,0,82,102,6,6,164,3,82,6  ; n595 t=28.532s dur=100ms, freq=932Hz, sample=82, buffer_id=06:52
    db 24,0,39,3,29,108,9,7,44,0,29,8  ; n596 t=28.614s dur=807ms, freq=44Hz, sample=29, buffer_id=08:1D
    db 43,0,100,0,65,102,6,8,93,1,65,6  ; n597 t=28.638s dur=100ms, freq=349Hz, sample=65, buffer_id=06:41
    db 0,0,212,3,63,126,3,0,55,1,63,3  ; n598 t=28.681s dur=980ms, freq=311Hz, sample=63, buffer_id=03:3F
    db 43,0,217,3,55,126,3,9,196,0,55,3  ; n599 t=28.681s dur=985ms, freq=196Hz, sample=55, buffer_id=03:37
    db 91,0,100,0,67,102,6,10,136,1,67,6  ; n600 t=28.725s dur=100ms, freq=392Hz, sample=67, buffer_id=06:43
    db 77,0,100,0,70,102,6,1,210,1,70,6  ; n601 t=28.816s dur=100ms, freq=466Hz, sample=70, buffer_id=06:46
    db 0,0,180,1,77,125,8,2,16,3,77,8  ; n602 t=28.893s dur=436ms, freq=784Hz, sample=77, buffer_id=08:4D
    db 19,0,25,3,67,108,9,3,136,1,67,8  ; n603 t=28.893s dur=793ms, freq=392Hz, sample=67, buffer_id=08:43
    db 87,0,100,0,75,102,6,5,110,2,75,6  ; n604 t=28.912s dur=100ms, freq=622Hz, sample=75, buffer_id=06:4B
    db 87,0,100,0,77,102,6,6,186,2,77,6  ; n605 t=28.999s dur=100ms, freq=698Hz, sample=77, buffer_id=06:4D
    db 82,0,100,0,82,102,6,8,164,3,82,6  ; n606 t=29.085s dur=100ms, freq=932Hz, sample=82, buffer_id=06:52
    db 0,0,66,1,87,125,8,1,221,4,87,8  ; n607 t=29.167s dur=322ms, freq=1245Hz, sample=87, buffer_id=08:57
    db 24,0,66,1,75,108,9,4,110,2,75,8  ; n608 t=29.167s dur=322ms, freq=622Hz, sample=75, buffer_id=08:4B
    db 96,0,100,0,65,102,6,10,93,1,65,6  ; n609 t=29.191s dur=100ms, freq=349Hz, sample=65, buffer_id=06:41
    db 96,0,100,0,67,102,6,5,136,1,67,6  ; n610 t=29.287s dur=100ms, freq=392Hz, sample=67, buffer_id=06:43
    db 96,0,100,0,70,102,6,6,210,1,70,6  ; n611 t=29.383s dur=100ms, freq=466Hz, sample=70, buffer_id=06:46
    db 0,0,245,0,87,125,8,8,151,4,87,8  ; n612 t=29.480s dur=245ms, freq=1175Hz, sample=87, buffer_id=08:57
    db 14,0,245,0,74,108,9,11,75,2,74,8  ; n613 t=29.480s dur=245ms, freq=587Hz, sample=74, buffer_id=08:4A
    db 96,0,100,0,75,102,6,10,110,2,75,6  ; n614 t=29.494s dur=100ms, freq=622Hz, sample=75, buffer_id=06:4B
    db 91,0,100,0,77,102,6,2,186,2,77,6  ; n615 t=29.590s dur=100ms, freq=698Hz, sample=77, buffer_id=06:4D
    db 58,0,100,0,82,102,6,5,164,3,82,6  ; n616 t=29.681s dur=100ms, freq=932Hz, sample=82, buffer_id=06:52
    db 0,0,56,1,82,125,8,1,23,4,82,8  ; n617 t=29.739s dur=312ms, freq=1047Hz, sample=82, buffer_id=08:52
    db 5,0,56,1,72,108,9,4,11,2,72,8  ; n618 t=29.739s dur=312ms, freq=523Hz, sample=72, buffer_id=08:48
    db 58,0,102,3,29,108,9,6,44,0,29,8  ; n619 t=29.744s dur=870ms, freq=44Hz, sample=29, buffer_id=08:1D
    db 0,0,248,1,55,126,3,7,196,0,55,3  ; n620 t=29.802s dur=504ms, freq=196Hz, sample=55, buffer_id=03:37
    db 5,0,100,0,65,102,6,10,93,1,65,6  ; n621 t=29.802s dur=100ms, freq=349Hz, sample=65, buffer_id=06:41
    db 87,0,224,1,63,126,3,12,55,1,63,3  ; n622 t=29.806s dur=480ms, freq=311Hz, sample=63, buffer_id=03:3F
    db 91,0,100,0,67,102,6,0,136,1,67,6  ; n623 t=29.893s dur=100ms, freq=392Hz, sample=67, buffer_id=06:43
    db 53,0,100,0,70,102,6,2,210,1,70,6  ; n624 t=29.984s dur=100ms, freq=466Hz, sample=70, buffer_id=06:46
    db 0,0,32,1,82,125,8,3,164,3,82,8  ; n625 t=30.037s dur=288ms, freq=932Hz, sample=82, buffer_id=08:52
    db 58,0,32,1,70,108,9,5,210,1,70,8  ; n626 t=30.037s dur=288ms, freq=466Hz, sample=70, buffer_id=08:46
    db 72,0,100,0,75,102,6,8,110,2,75,6  ; n627 t=30.095s dur=100ms, freq=622Hz, sample=75, buffer_id=06:4B
    db 91,0,100,0,77,102,6,9,186,2,77,6  ; n628 t=30.167s dur=100ms, freq=698Hz, sample=77, buffer_id=06:4D
    db 96,0,100,0,82,102,6,0,164,3,82,6  ; n629 t=30.258s dur=100ms, freq=932Hz, sample=82, buffer_id=06:52
    db 0,0,230,0,82,125,8,2,164,3,82,8  ; n630 t=30.355s dur=230ms, freq=932Hz, sample=82, buffer_id=08:52
    db 14,0,230,0,70,108,9,1,210,1,70,8  ; n631 t=30.355s dur=230ms, freq=466Hz, sample=70, buffer_id=08:46
    db 14,0,100,0,65,102,6,4,93,1,65,6  ; n632 t=30.369s dur=100ms, freq=349Hz, sample=65, buffer_id=06:41
    db 0,0,34,3,55,126,3,10,196,0,55,3  ; n633 t=30.383s dur=802ms, freq=196Hz, sample=55, buffer_id=03:37
    db 72,0,54,3,63,126,3,11,55,1,63,3  ; n634 t=30.383s dur=822ms, freq=311Hz, sample=63, buffer_id=03:3F
    db 77,0,100,0,67,102,6,8,136,1,67,6  ; n635 t=30.456s dur=100ms, freq=392Hz, sample=67, buffer_id=06:43
    db 0,0,168,0,82,125,8,5,23,4,82,8  ; n636 t=30.532s dur=168ms, freq=1047Hz, sample=82, buffer_id=08:52
    db 14,0,168,0,72,108,9,3,11,2,72,8  ; n637 t=30.532s dur=168ms, freq=523Hz, sample=72, buffer_id=08:48
    db 111,0,100,0,70,102,6,7,210,1,70,6  ; n638 t=30.547s dur=100ms, freq=466Hz, sample=70, buffer_id=06:46
    db 48,0,100,0,75,102,6,0,110,2,75,6  ; n639 t=30.657s dur=100ms, freq=622Hz, sample=75, buffer_id=06:4B
    db 0,0,221,0,87,125,8,4,151,4,87,8  ; n640 t=30.706s dur=221ms, freq=1175Hz, sample=87, buffer_id=08:57
    db 48,0,221,0,74,108,9,9,75,2,74,8  ; n641 t=30.706s dur=221ms, freq=587Hz, sample=74, buffer_id=08:4A
    db 82,0,100,0,77,102,6,12,186,2,77,6  ; n642 t=30.754s dur=100ms, freq=698Hz, sample=77, buffer_id=06:4D
    db 101,0,100,0,82,102,6,1,164,3,82,6  ; n643 t=30.835s dur=100ms, freq=932Hz, sample=82, buffer_id=06:52
    db 0,0,152,1,82,125,8,3,23,4,82,8  ; n644 t=30.936s dur=408ms, freq=1047Hz, sample=82, buffer_id=08:52
    db 10,0,152,1,72,108,9,2,11,2,72,8  ; n645 t=30.936s dur=408ms, freq=523Hz, sample=72, buffer_id=08:48
    db 0,0,100,0,65,102,6,5,93,1,65,6  ; n646 t=30.946s dur=100ms, freq=349Hz, sample=65, buffer_id=06:41
    db 86,0,49,3,29,108,9,7,44,0,29,8  ; n647 t=30.946s dur=817ms, freq=44Hz, sample=29, buffer_id=08:1D
    db 101,0,100,0,67,102,6,0,136,1,67,6  ; n648 t=31.032s dur=100ms, freq=392Hz, sample=67, buffer_id=06:43
    db 106,0,100,0,70,102,6,4,210,1,70,6  ; n649 t=31.133s dur=100ms, freq=466Hz, sample=70, buffer_id=06:46
    db 38,0,100,0,75,102,6,1,110,2,75,6  ; n650 t=31.239s dur=100ms, freq=622Hz, sample=75, buffer_id=06:4B
    db 43,0,201,0,55,126,3,5,196,0,55,3  ; n651 t=31.278s dur=201ms, freq=196Hz, sample=55, buffer_id=03:37
    db 43,0,100,0,77,102,6,6,186,2,77,6  ; n652 t=31.321s dur=100ms, freq=698Hz, sample=77, buffer_id=06:4D
    db 0,0,168,0,77,125,8,0,16,3,77,8  ; n653 t=31.364s dur=168ms, freq=784Hz, sample=77, buffer_id=08:4D
    db 48,0,168,0,67,108,9,8,136,1,67,8  ; n654 t=31.364s dur=168ms, freq=392Hz, sample=67, buffer_id=08:43
    db 125,0,100,0,82,102,6,9,164,3,82,6  ; n655 t=31.412s dur=100ms, freq=932Hz, sample=82, buffer_id=06:52
    db 0,0,26,2,82,125,8,4,112,3,82,8  ; n656 t=31.537s dur=538ms, freq=880Hz, sample=82, buffer_id=08:52
    db 10,0,100,0,69,108,9,10,184,1,69,8  ; n657 t=31.537s dur=100ms, freq=440Hz, sample=69, buffer_id=08:45
    db 0,0,87,3,58,126,3,1,220,0,58,3  ; n658 t=31.547s dur=855ms, freq=220Hz, sample=58, buffer_id=03:3A
    db 31,2,97,3,65,126,3,2,93,1,65,3  ; n659 t=31.547s dur=865ms, freq=349Hz, sample=65, buffer_id=03:41
    db 14,0,247,2,29,108,9,0,44,0,29,8  ; n660 t=32.090s dur=759ms, freq=44Hz, sample=29, buffer_id=08:1D
    db 0,0,80,1,77,125,8,3,186,2,77,8  ; n661 t=32.105s dur=336ms, freq=698Hz, sample=77, buffer_id=08:4D
    db 85,1,66,1,65,108,9,5,93,1,65,8  ; n662 t=32.105s dur=322ms, freq=349Hz, sample=65, buffer_id=08:41
    db 87,0,149,0,58,126,3,4,220,0,58,3  ; n663 t=32.446s dur=149ms, freq=220Hz, sample=58, buffer_id=03:3A
    db 0,0,197,0,77,125,8,6,186,2,77,8  ; n664 t=32.532s dur=197ms, freq=698Hz, sample=77, buffer_id=08:4D
    db 154,0,197,0,65,108,9,7,93,1,65,8  ; n665 t=32.532s dur=197ms, freq=349Hz, sample=65, buffer_id=08:41
    db 0,0,180,1,77,125,8,1,16,3,77,8  ; n666 t=32.686s dur=436ms, freq=784Hz, sample=77, buffer_id=08:4D
    db 24,0,39,3,67,108,9,2,136,1,67,8  ; n667 t=32.686s dur=807ms, freq=392Hz, sample=67, buffer_id=08:43
    db 5,0,32,1,63,126,3,3,55,1,63,3  ; n668 t=32.710s dur=288ms, freq=311Hz, sample=63, buffer_id=03:3F
    db 5,0,254,0,55,126,3,5,196,0,55,3  ; n669 t=32.715s dur=254ms, freq=196Hz, sample=55, buffer_id=03:37
    db 87,0,100,0,65,102,6,8,93,1,65,6  ; n670 t=32.720s dur=100ms, freq=349Hz, sample=65, buffer_id=06:41
    db 77,0,100,0,67,102,6,4,136,1,67,6  ; n671 t=32.806s dur=100ms, freq=392Hz, sample=67, buffer_id=06:43
    db 96,0,100,0,70,102,6,9,210,1,70,6  ; n672 t=32.883s dur=100ms, freq=466Hz, sample=70, buffer_id=06:46
    db 82,0,100,0,75,102,6,6,110,2,75,6  ; n673 t=32.980s dur=100ms, freq=622Hz, sample=75, buffer_id=06:4B
    db 86,0,100,0,77,102,6,0,186,2,77,6  ; n674 t=33.061s dur=100ms, freq=698Hz, sample=77, buffer_id=06:4D
    db 72,0,100,0,82,102,6,4,164,3,82,6  ; n675 t=33.148s dur=100ms, freq=932Hz, sample=82, buffer_id=06:52
    db 34,0,87,3,29,108,9,3,44,0,29,8  ; n676 t=33.220s dur=855ms, freq=44Hz, sample=29, buffer_id=08:1D
    db 29,0,100,0,65,102,6,5,93,1,65,6  ; n677 t=33.254s dur=100ms, freq=349Hz, sample=65, buffer_id=06:41
    db 5,0,28,4,63,126,3,6,55,1,63,3  ; n678 t=33.282s dur=1052ms, freq=311Hz, sample=63, buffer_id=03:3F
    db 53,0,246,3,55,126,3,7,196,0,55,3  ; n679 t=33.287s dur=1014ms, freq=196Hz, sample=55, buffer_id=03:37
    db 91,0,100,0,67,102,6,1,136,1,67,6  ; n680 t=33.340s dur=100ms, freq=392Hz, sample=67, buffer_id=06:43
    db 96,0,100,0,70,102,6,0,210,1,70,6  ; n681 t=33.431s dur=100ms, freq=466Hz, sample=70, buffer_id=06:46
    db 14,0,100,0,75,102,6,4,110,2,75,6  ; n682 t=33.528s dur=100ms, freq=622Hz, sample=75, buffer_id=06:4B
    db 0,0,129,0,77,125,8,8,16,3,77,8  ; n683 t=33.542s dur=129ms, freq=784Hz, sample=77, buffer_id=08:4D
    db 72,0,129,0,67,108,9,9,136,1,67,8  ; n684 t=33.542s dur=129ms, freq=392Hz, sample=67, buffer_id=08:43
    db 48,0,100,0,77,102,6,5,186,2,77,6  ; n685 t=33.614s dur=100ms, freq=698Hz, sample=77, buffer_id=06:4D
    db 0,0,134,0,87,125,8,1,221,4,87,8  ; n686 t=33.662s dur=134ms, freq=1245Hz, sample=87, buffer_id=08:57
    db 38,0,134,0,75,108,9,10,110,2,75,8  ; n687 t=33.662s dur=134ms, freq=622Hz, sample=75, buffer_id=08:4B
    db 106,0,100,0,82,102,6,2,164,3,82,6  ; n688 t=33.701s dur=100ms, freq=932Hz, sample=82, buffer_id=06:52
    db 10,0,100,0,65,102,6,0,93,1,65,6  ; n689 t=33.806s dur=100ms, freq=349Hz, sample=65, buffer_id=06:41
    db 0,0,8,1,87,125,8,11,221,4,87,8  ; n690 t=33.816s dur=264ms, freq=1245Hz, sample=87, buffer_id=08:57
    db 87,0,8,1,75,108,9,12,110,2,75,8  ; n691 t=33.816s dur=264ms, freq=622Hz, sample=75, buffer_id=08:4B
    db 96,0,100,0,67,102,6,4,136,1,67,6  ; n692 t=33.903s dur=100ms, freq=392Hz, sample=67, buffer_id=06:43
    db 86,0,100,0,70,102,6,1,210,1,70,6  ; n693 t=33.999s dur=100ms, freq=466Hz, sample=70, buffer_id=06:46
    db 0,0,8,1,87,125,8,2,151,4,87,8  ; n694 t=34.085s dur=264ms, freq=1175Hz, sample=87, buffer_id=08:57
    db 24,0,8,1,74,108,9,5,75,2,74,8  ; n695 t=34.085s dur=264ms, freq=587Hz, sample=74, buffer_id=08:4A
    db 96,0,100,0,75,102,6,0,110,2,75,6  ; n696 t=34.109s dur=100ms, freq=622Hz, sample=75, buffer_id=06:4B
    db 91,0,100,0,77,102,6,4,186,2,77,6  ; n697 t=34.206s dur=100ms, freq=698Hz, sample=77, buffer_id=06:4D
    db 58,0,100,0,82,102,6,3,164,3,82,6  ; n698 t=34.297s dur=100ms, freq=932Hz, sample=82, buffer_id=06:52
    db 0,0,37,1,82,125,8,1,23,4,82,8  ; n699 t=34.355s dur=293ms, freq=1047Hz, sample=82, buffer_id=08:52
    db 38,0,37,1,72,108,9,8,11,2,72,8  ; n700 t=34.355s dur=293ms, freq=523Hz, sample=72, buffer_id=08:48
    db 24,0,36,2,29,108,9,9,44,0,29,8  ; n701 t=34.393s dur=548ms, freq=44Hz, sample=29, buffer_id=08:1D
    db 5,0,100,0,65,102,6,0,93,1,65,6  ; n702 t=34.417s dur=100ms, freq=349Hz, sample=65, buffer_id=06:41
    db 10,0,224,1,63,126,3,10,55,1,63,3  ; n703 t=34.422s dur=480ms, freq=311Hz, sample=63, buffer_id=03:3F
    db 77,0,205,1,55,126,3,11,196,0,55,3  ; n704 t=34.431s dur=461ms, freq=196Hz, sample=55, buffer_id=03:37
    db 91,0,100,0,67,102,6,4,136,1,67,6  ; n705 t=34.508s dur=100ms, freq=392Hz, sample=67, buffer_id=06:43
    db 58,0,100,0,70,102,6,2,210,1,70,6  ; n706 t=34.600s dur=100ms, freq=466Hz, sample=70, buffer_id=06:46
    db 0,0,192,0,82,125,8,3,164,3,82,8  ; n707 t=34.657s dur=192ms, freq=932Hz, sample=82, buffer_id=08:52
    db 53,0,192,0,70,108,9,5,210,1,70,8  ; n708 t=34.657s dur=192ms, freq=466Hz, sample=70, buffer_id=08:46
    db 72,0,100,0,75,102,6,6,110,2,75,6  ; n709 t=34.710s dur=100ms, freq=622Hz, sample=75, buffer_id=06:4B
    db 5,0,100,0,77,102,6,0,186,2,77,6  ; n710 t=34.782s dur=100ms, freq=698Hz, sample=77, buffer_id=06:4D
    db 0,0,100,0,89,125,8,7,117,5,89,8  ; n711 t=34.787s dur=100ms, freq=1397Hz, sample=89, buffer_id=08:59
    db 87,0,100,0,77,108,9,12,186,2,77,8  ; n712 t=34.787s dur=100ms, freq=698Hz, sample=77, buffer_id=08:4D
    db 38,0,100,0,82,102,6,1,164,3,82,6  ; n713 t=34.874s dur=100ms, freq=932Hz, sample=82, buffer_id=06:52
    db 0,0,234,1,89,125,8,2,117,5,89,8  ; n714 t=34.912s dur=490ms, freq=1397Hz, sample=89, buffer_id=08:59
    db 72,0,234,1,77,108,9,4,186,2,77,8  ; n715 t=34.912s dur=490ms, freq=698Hz, sample=77, buffer_id=08:4D
    db 15,0,100,0,65,102,6,8,93,1,65,6  ; n716 t=34.984s dur=100ms, freq=349Hz, sample=65, buffer_id=06:41
    db 10,0,2,2,38,108,9,13,69,0,38,8  ; n717 t=34.999s dur=514ms, freq=69Hz, sample=38, buffer_id=08:26
    db 5,0,239,1,55,126,3,11,208,0,55,3  ; n718 t=35.008s dur=495ms, freq=208Hz, sample=55, buffer_id=03:37 [TRUNCATE prev:ch11 @34431.5ms -> 35008.4ms]
    db 58,0,2,2,62,126,3,6,21,1,62,3  ; n719 t=35.013s dur=514ms, freq=277Hz, sample=62, buffer_id=03:3E
    db 91,0,100,0,67,102,6,3,159,1,67,6  ; n720 t=35.071s dur=100ms, freq=415Hz, sample=67, buffer_id=06:43
    db 111,0,100,0,70,102,6,0,11,2,70,6  ; n721 t=35.162s dur=100ms, freq=523Hz, sample=70, buffer_id=06:46
    db 96,0,100,0,75,102,6,1,42,2,75,6  ; n722 t=35.273s dur=100ms, freq=554Hz, sample=75, buffer_id=06:4B
    db 38,0,100,0,77,102,6,5,186,2,77,6  ; n723 t=35.369s dur=100ms, freq=698Hz, sample=77, buffer_id=06:4D
    db 0,0,100,0,82,125,8,3,23,4,82,8  ; n724 t=35.407s dur=100ms, freq=1047Hz, sample=82, buffer_id=08:52
    db 43,0,100,0,72,108,9,7,11,2,72,8  ; n725 t=35.407s dur=100ms, freq=523Hz, sample=72, buffer_id=08:48
    db 77,0,100,0,82,102,6,8,63,3,82,6  ; n726 t=35.451s dur=100ms, freq=831Hz, sample=82, buffer_id=06:52
    db 0,0,45,6,82,125,8,0,23,4,82,8  ; n727 t=35.528s dur=1581ms, freq=1047Hz, sample=82, buffer_id=08:52
    db 34,0,45,6,72,108,9,9,11,2,72,8  ; n728 t=35.528s dur=1581ms, freq=523Hz, sample=72, buffer_id=08:48
    db 10,0,100,0,65,102,6,10,93,1,65,6  ; n729 t=35.561s dur=100ms, freq=349Hz, sample=65, buffer_id=06:41
    db 5,0,2,2,58,126,3,12,6,1,58,3  ; n730 t=35.571s dur=514ms, freq=262Hz, sample=58, buffer_id=03:3A
    db 5,0,159,3,29,108,9,1,44,0,29,8  ; n731 t=35.576s dur=927ms, freq=44Hz, sample=29, buffer_id=08:1D
    db 67,0,248,1,58,126,3,2,220,0,58,3  ; n732 t=35.581s dur=504ms, freq=220Hz, sample=58, buffer_id=03:3A [TRUNCATE prev:ch2 @34912.2ms -> 35580.5ms]
    db 101,0,100,0,70,102,6,4,11,2,70,6  ; n733 t=35.648s dur=100ms, freq=523Hz, sample=70, buffer_id=06:46
    db 106,0,100,0,77,102,6,3,186,2,77,6  ; n734 t=35.749s dur=100ms, freq=698Hz, sample=77, buffer_id=06:4D
    db 82,0,100,0,89,102,6,5,117,5,89,6  ; n735 t=35.855s dur=100ms, freq=1397Hz, sample=89, buffer_id=06:59
    db 91,0,100,0,85,102,6,6,23,4,85,6  ; n736 t=35.936s dur=100ms, freq=1047Hz, sample=85, buffer_id=06:55
    db 106,0,100,0,77,102,6,4,186,2,77,6  ; n737 t=36.028s dur=100ms, freq=698Hz, sample=77, buffer_id=06:4D
    db 5,0,98,2,55,126,3,3,196,0,55,3  ; n738 t=36.133s dur=610ms, freq=196Hz, sample=55, buffer_id=03:37
    db 50,2,89,2,63,126,3,7,55,1,63,3  ; n739 t=36.138s dur=601ms, freq=311Hz, sample=63, buffer_id=03:3F
    db 29,0,21,2,43,108,9,2,87,0,43,8  ; n740 t=36.701s dur=533ms, freq=87Hz, sample=43, buffer_id=08:2B
    db 0,0,224,1,58,126,3,1,220,0,58,3  ; n741 t=36.730s dur=480ms, freq=220Hz, sample=58, buffer_id=03:3A
    db 172,1,253,1,58,126,3,4,6,1,58,3  ; n742 t=36.730s dur=509ms, freq=262Hz, sample=58, buffer_id=03:3A
    db 0,0,173,0,77,125,8,3,186,2,77,8  ; n743 t=37.157s dur=173ms, freq=698Hz, sample=77, buffer_id=08:4D
    db 125,0,173,0,65,108,9,5,93,1,65,8  ; n744 t=37.157s dur=173ms, freq=349Hz, sample=65, buffer_id=08:41
    db 24,0,144,2,38,108,9,6,78,0,38,8  ; n745 t=37.282s dur=656ms, freq=78Hz, sample=38, buffer_id=08:26
    db 0,0,180,1,77,125,8,7,16,3,77,8  ; n746 t=37.306s dur=436ms, freq=784Hz, sample=77, buffer_id=08:4D
    db 34,0,34,3,67,108,9,8,136,1,67,8  ; n747 t=37.306s dur=802ms, freq=392Hz, sample=67, buffer_id=08:43
    db 10,0,36,2,55,126,3,0,196,0,55,3  ; n748 t=37.340s dur=548ms, freq=196Hz, sample=55, buffer_id=03:37
    db 36,2,42,5,63,126,3,9,55,1,63,3  ; n749 t=37.350s dur=1322ms, freq=311Hz, sample=63, buffer_id=03:3F
    db 226,0,22,1,58,126,3,2,220,0,58,3  ; n750 t=37.898s dur=278ms, freq=220Hz, sample=58, buffer_id=03:3A
    db 0,0,37,1,77,125,8,0,16,3,77,8  ; n751 t=38.124s dur=293ms, freq=784Hz, sample=77, buffer_id=08:4D
    db 34,0,37,1,67,108,9,1,136,1,67,8  ; n752 t=38.124s dur=293ms, freq=392Hz, sample=67, buffer_id=08:43
    db 240,0,51,1,58,126,3,3,233,0,58,3  ; n753 t=38.157s dur=307ms, freq=233Hz, sample=58, buffer_id=03:3A
    db 0,0,66,1,87,125,8,2,221,4,87,8  ; n754 t=38.398s dur=322ms, freq=1245Hz, sample=87, buffer_id=08:57
    db 43,0,66,1,75,108,9,4,110,2,75,8  ; n755 t=38.398s dur=322ms, freq=622Hz, sample=75, buffer_id=08:4B
    db 14,0,13,3,38,108,9,5,65,0,38,8  ; n756 t=38.441s dur=781ms, freq=65Hz, sample=38, buffer_id=08:26
    db 250,0,74,2,58,126,3,6,247,0,58,3  ; n757 t=38.456s dur=586ms, freq=247Hz, sample=58, buffer_id=03:3A
    db 5,0,18,1,62,126,3,0,38,1,62,3  ; n758 t=38.706s dur=274ms, freq=294Hz, sample=62, buffer_id=03:3E
    db 0,0,245,0,87,125,8,1,151,4,87,8  ; n759 t=38.710s dur=245ms, freq=1175Hz, sample=87, buffer_id=08:57
    db 4,1,245,0,74,108,9,3,75,2,74,8  ; n760 t=38.710s dur=245ms, freq=587Hz, sample=74, buffer_id=08:4A
    db 0,0,56,1,82,125,8,2,23,4,82,8  ; n761 t=38.970s dur=312ms, freq=1047Hz, sample=82, buffer_id=08:52
    db 53,0,56,1,72,108,9,4,11,2,72,8  ; n762 t=38.970s dur=312ms, freq=523Hz, sample=72, buffer_id=08:48
    db 10,0,106,0,59,108,9,7,6,1,59,8  ; n763 t=39.023s dur=106ms, freq=262Hz, sample=59, buffer_id=08:3B
    db 226,0,221,0,58,126,3,8,6,1,58,3  ; n764 t=39.032s dur=221ms, freq=262Hz, sample=58, buffer_id=03:3A
    db 5,0,37,1,58,126,3,0,233,0,58,3  ; n765 t=39.258s dur=293ms, freq=233Hz, sample=58, buffer_id=03:3A
    db 5,0,18,1,62,126,3,1,38,1,62,3  ; n766 t=39.263s dur=274ms, freq=294Hz, sample=62, buffer_id=03:3E
    db 0,0,32,1,82,125,8,3,164,3,82,8  ; n767 t=39.268s dur=288ms, freq=932Hz, sample=82, buffer_id=08:52
    db 14,0,32,1,70,108,9,6,210,1,70,8  ; n768 t=39.268s dur=288ms, freq=466Hz, sample=70, buffer_id=08:46
    db 28,1,100,0,62,108,9,9,38,1,62,8  ; n769 t=39.282s dur=100ms, freq=294Hz, sample=62, buffer_id=08:3E
    db 14,0,93,2,47,108,9,2,131,0,47,8  ; n770 t=39.566s dur=605ms, freq=131Hz, sample=47, buffer_id=08:2F
    db 5,0,64,2,63,126,3,4,55,1,63,3  ; n771 t=39.581s dur=576ms, freq=311Hz, sample=63, buffer_id=03:3F
    db 0,0,33,4,58,126,3,5,233,0,58,3  ; n772 t=39.585s dur=1057ms, freq=233Hz, sample=58, buffer_id=03:3A
    db 0,0,230,0,82,125,8,7,164,3,82,8  ; n773 t=39.585s dur=230ms, freq=932Hz, sample=82, buffer_id=08:52
    db 5,0,230,0,70,108,9,8,210,1,70,8  ; n774 t=39.585s dur=230ms, freq=466Hz, sample=70, buffer_id=08:46
    db 173,0,79,6,63,108,9,9,55,1,63,8  ; n775 t=39.590s dur=1615ms, freq=311Hz, sample=63, buffer_id=08:3F
    db 0,0,168,0,82,125,8,0,23,4,82,8  ; n776 t=39.763s dur=168ms, freq=1047Hz, sample=82, buffer_id=08:52
    db 173,0,168,0,72,108,9,1,11,2,72,8  ; n777 t=39.763s dur=168ms, freq=523Hz, sample=72, buffer_id=08:48
    db 0,0,221,0,87,125,8,3,151,4,87,8  ; n778 t=39.936s dur=221ms, freq=1175Hz, sample=87, buffer_id=08:57
    db 207,0,221,0,74,108,9,6,75,2,74,8  ; n779 t=39.936s dur=221ms, freq=587Hz, sample=74, buffer_id=08:4A
    db 0,0,72,4,65,126,3,0,93,1,65,3  ; n780 t=40.143s dur=1096ms, freq=349Hz, sample=65, buffer_id=03:41
    db 24,0,120,4,53,126,3,1,175,0,53,3  ; n781 t=40.143s dur=1144ms, freq=175Hz, sample=53, buffer_id=03:35
    db 0,0,152,1,82,125,8,8,23,4,82,8  ; n782 t=40.167s dur=408ms, freq=1047Hz, sample=82, buffer_id=08:52
    db 0,0,152,1,72,108,9,7,11,2,72,8  ; n783 t=40.167s dur=408ms, freq=523Hz, sample=72, buffer_id=08:48
    db 172,1,67,4,53,108,9,10,175,0,53,8  ; n784 t=40.167s dur=1091ms, freq=175Hz, sample=53, buffer_id=08:35
    db 0,0,134,0,77,125,8,2,16,3,77,8  ; n785 t=40.595s dur=134ms, freq=784Hz, sample=77, buffer_id=08:4D
    db 144,0,134,0,67,108,9,3,136,1,67,8  ; n786 t=40.595s dur=134ms, freq=392Hz, sample=67, buffer_id=08:43
    db 29,0,12,2,58,126,3,4,6,1,58,3  ; n787 t=40.739s dur=524ms, freq=262Hz, sample=58, buffer_id=03:3A
    db 0,0,26,2,82,125,8,6,112,3,82,8  ; n788 t=40.768s dur=538ms, freq=880Hz, sample=82, buffer_id=08:52
    db 36,2,100,0,69,108,9,11,184,1,69,8  ; n789 t=40.768s dur=100ms, freq=440Hz, sample=69, buffer_id=08:45
    db 38,0,109,1,77,124,4,2,186,2,77,4  ; n790 t=41.316s dur=365ms, freq=698Hz, sample=77, buffer_id=04:4D
    db 19,0,51,1,43,108,9,3,87,0,43,8  ; n791 t=41.355s dur=307ms, freq=87Hz, sample=43, buffer_id=08:2B
    db 5,0,37,1,53,108,9,5,175,0,53,8  ; n792 t=41.374s dur=293ms, freq=175Hz, sample=53, buffer_id=08:35
    db 0,0,245,0,65,126,3,7,93,1,65,3  ; n793 t=41.379s dur=245ms, freq=349Hz, sample=65, buffer_id=03:41
    db 138,1,70,1,89,125,8,8,117,5,89,8  ; n794 t=41.379s dur=326ms, freq=1397Hz, sample=89, buffer_id=08:59
    db 24,0,100,0,77,124,4,0,186,2,77,4  ; n795 t=41.773s dur=100ms, freq=698Hz, sample=77, buffer_id=04:4D
    db 0,0,123,0,53,108,9,1,175,0,53,8  ; n796 t=41.797s dur=123ms, freq=175Hz, sample=53, buffer_id=08:35
    db 10,0,123,0,43,108,9,4,87,0,43,8  ; n797 t=41.797s dur=123ms, freq=87Hz, sample=43, buffer_id=08:2B
    db 0,0,100,0,65,126,3,6,93,1,65,3  ; n798 t=41.806s dur=100ms, freq=349Hz, sample=65, buffer_id=03:41
    db 110,0,100,0,89,125,8,9,117,5,89,8  ; n799 t=41.806s dur=100ms, freq=1397Hz, sample=89, buffer_id=08:59
    db 5,0,29,1,94,125,8,2,73,7,94,8  ; n800 t=41.916s dur=285ms, freq=1865Hz, sample=94, buffer_id=08:5E
    db 5,0,174,7,70,126,3,3,210,1,70,3  ; n801 t=41.921s dur=1966ms, freq=466Hz, sample=70, buffer_id=03:46
    db 5,0,242,0,89,125,8,5,200,5,89,8  ; n802 t=41.925s dur=242ms, freq=1480Hz, sample=89, buffer_id=08:59
    db 10,0,104,1,38,108,9,7,65,0,38,8  ; n803 t=41.930s dur=360ms, freq=65Hz, sample=38, buffer_id=08:26
    db 5,0,29,1,82,124,4,8,164,3,82,4  ; n804 t=41.940s dur=285ms, freq=932Hz, sample=82, buffer_id=04:52
    db 10,0,104,0,78,124,4,10,228,2,78,4  ; n805 t=41.944s dur=104ms, freq=740Hz, sample=78, buffer_id=04:4E
    db 19,0,90,1,47,108,9,11,131,0,47,8  ; n806 t=41.954s dur=346ms, freq=131Hz, sample=47, buffer_id=08:2F
    db 118,1,75,1,65,126,3,12,114,1,65,3  ; n807 t=41.973s dur=331ms, freq=370Hz, sample=65, buffer_id=03:41
    db 0,0,100,0,81,124,4,0,63,3,81,4  ; n808 t=42.347s dur=100ms, freq=831Hz, sample=81, buffer_id=04:51
    db 19,0,100,0,77,124,4,1,186,2,77,4  ; n809 t=42.347s dur=100ms, freq=698Hz, sample=77, buffer_id=04:4D
    db 5,0,100,0,38,108,9,4,73,0,38,8  ; n810 t=42.365s dur=100ms, freq=73Hz, sample=38, buffer_id=08:26
    db 9,0,116,0,50,108,9,5,147,0,50,8  ; n811 t=42.370s dur=116ms, freq=147Hz, sample=50, buffer_id=08:32
    db 0,0,100,0,65,126,3,9,93,1,65,3  ; n812 t=42.379s dur=100ms, freq=349Hz, sample=65, buffer_id=03:41
    db 19,0,100,0,89,125,8,6,117,5,89,8  ; n813 t=42.379s dur=100ms, freq=1397Hz, sample=89, buffer_id=08:59
    db 0,0,100,0,69,126,3,10,159,1,69,3  ; n814 t=42.398s dur=100ms, freq=415Hz, sample=69, buffer_id=03:45
    db 84,0,100,0,91,125,8,13,125,6,91,8  ; n815 t=42.398s dur=100ms, freq=1661Hz, sample=91, buffer_id=08:5B
    db 9,0,250,0,89,125,8,2,200,5,89,8  ; n816 t=42.482s dur=250ms, freq=1480Hz, sample=89, buffer_id=08:59
    db 14,0,250,0,87,125,8,7,221,4,87,8  ; n817 t=42.492s dur=250ms, freq=1245Hz, sample=87, buffer_id=08:57
    db 0,0,21,1,78,124,4,8,228,2,78,4  ; n818 t=42.506s dur=277ms, freq=740Hz, sample=78, buffer_id=04:4E
    db 5,0,62,1,38,108,9,11,78,0,38,8  ; n819 t=42.506s dur=318ms, freq=78Hz, sample=38, buffer_id=08:26
    db 0,0,100,0,75,124,4,12,110,2,75,4  ; n820 t=42.510s dur=100ms, freq=622Hz, sample=75, buffer_id=04:4B
    db 19,0,49,1,50,108,9,5,156,0,50,8  ; n821 t=42.510s dur=305ms, freq=156Hz, sample=50, buffer_id=08:32 [TRUNCATE prev:ch5 @42370.0ms -> 42510.2ms]
    db 9,0,80,1,65,126,3,9,114,1,65,3  ; n822 t=42.529s dur=336ms, freq=370Hz, sample=65, buffer_id=03:41 [TRUNCATE prev:ch9 @42379.4ms -> 42528.9ms]
    db 127,1,80,1,63,126,3,3,55,1,63,3  ; n823 t=42.538s dur=336ms, freq=311Hz, sample=63, buffer_id=03:3F [TRUNCATE prev:ch3 @41920.6ms -> 42538.3ms]
    db 5,0,100,0,77,124,4,0,186,2,77,4  ; n824 t=42.921s dur=100ms, freq=698Hz, sample=77, buffer_id=04:4D
    db 0,0,100,0,62,126,3,1,21,1,62,3  ; n825 t=42.925s dur=100ms, freq=277Hz, sample=62, buffer_id=03:3E
    db 0,0,100,0,65,126,3,4,93,1,65,3  ; n826 t=42.925s dur=100ms, freq=349Hz, sample=65, buffer_id=03:41
    db 0,0,100,0,72,124,4,6,42,2,72,4  ; n827 t=42.925s dur=100ms, freq=554Hz, sample=72, buffer_id=04:48
    db 0,0,100,0,87,125,8,10,85,4,87,8  ; n828 t=42.925s dur=100ms, freq=1109Hz, sample=87, buffer_id=08:57
    db 5,0,100,0,89,125,8,12,117,5,89,8  ; n829 t=42.925s dur=100ms, freq=1397Hz, sample=89, buffer_id=08:59
    db 14,0,105,0,53,108,9,13,175,0,53,8  ; n830 t=42.930s dur=105ms, freq=175Hz, sample=53, buffer_id=08:35
    db 119,0,100,0,43,108,9,2,87,0,43,8  ; n831 t=42.944s dur=100ms, freq=87Hz, sample=43, buffer_id=08:2B
    db 0,0,202,0,87,125,8,5,221,4,87,8  ; n832 t=43.063s dur=202ms, freq=1245Hz, sample=87, buffer_id=08:57
    db 9,0,63,1,53,108,9,7,185,0,53,8  ; n833 t=43.063s dur=319ms, freq=185Hz, sample=53, buffer_id=08:35
    db 0,0,14,1,75,124,4,8,110,2,75,4  ; n834 t=43.072s dur=270ms, freq=622Hz, sample=75, buffer_id=04:4B
    db 9,0,81,1,43,108,9,9,92,0,43,8  ; n835 t=43.072s dur=337ms, freq=92Hz, sample=43, buffer_id=08:2B
    db 5,0,135,0,72,124,4,3,11,2,72,4  ; n836 t=43.081s dur=135ms, freq=523Hz, sample=72, buffer_id=04:48
    db 5,0,27,1,63,126,3,11,55,1,63,3  ; n837 t=43.085s dur=283ms, freq=311Hz, sample=63, buffer_id=03:3F
    db 0,0,41,1,58,126,3,0,6,1,58,3  ; n838 t=43.090s dur=297ms, freq=262Hz, sample=58, buffer_id=03:3A [TRUNCATE prev:ch0 @42920.8ms -> 43089.9ms]
    db 109,1,211,0,82,125,8,1,23,4,82,8  ; n839 t=43.090s dur=211ms, freq=1047Hz, sample=82, buffer_id=08:52 [TRUNCATE prev:ch1 @42925.3ms -> 43089.9ms]
    db 0,0,100,0,58,126,3,2,233,0,58,3  ; n840 t=43.455s dur=100ms, freq=233Hz, sample=58, buffer_id=03:3A
    db 18,0,100,0,82,125,8,3,164,3,82,8  ; n841 t=43.455s dur=100ms, freq=932Hz, sample=82, buffer_id=08:52
    db 5,0,100,0,72,124,4,4,42,2,72,4  ; n842 t=43.473s dur=100ms, freq=554Hz, sample=72, buffer_id=04:48
    db 18,0,100,0,70,124,4,5,210,1,70,4  ; n843 t=43.477s dur=100ms, freq=466Hz, sample=70, buffer_id=04:46
    db 0,0,100,0,62,126,3,6,21,1,62,3  ; n844 t=43.495s dur=100ms, freq=277Hz, sample=62, buffer_id=03:3E
    db 14,0,100,0,87,125,8,12,85,4,87,8  ; n845 t=43.495s dur=100ms, freq=1109Hz, sample=87, buffer_id=08:57
    db 0,0,100,0,43,108,9,1,104,0,43,8  ; n846 t=43.509s dur=100ms, freq=104Hz, sample=43, buffer_id=08:2B
    db 90,0,100,0,56,108,9,10,208,0,56,8  ; n847 t=43.509s dur=100ms, freq=208Hz, sample=56, buffer_id=08:38
    db 0,0,220,0,55,126,3,0,208,0,55,3  ; n848 t=43.599s dur=220ms, freq=208Hz, sample=55, buffer_id=03:37
    db 9,0,220,0,82,125,8,7,63,3,82,8  ; n849 t=43.599s dur=220ms, freq=831Hz, sample=82, buffer_id=08:52
    db 14,0,18,1,72,124,4,8,11,2,72,4  ; n850 t=43.608s dur=274ms, freq=523Hz, sample=72, buffer_id=04:48
    db 0,0,198,0,58,126,3,9,6,1,58,3  ; n851 t=43.621s dur=198ms, freq=262Hz, sample=58, buffer_id=03:3A
    db 0,0,135,0,70,124,4,11,159,1,70,4  ; n852 t=43.621s dur=135ms, freq=415Hz, sample=70, buffer_id=04:46
    db 9,0,220,0,82,125,8,13,23,4,82,8  ; n853 t=43.621s dur=220ms, freq=1047Hz, sample=82, buffer_id=08:52
    db 5,0,50,1,47,108,9,2,117,0,47,8  ; n854 t=43.630s dur=306ms, freq=117Hz, sample=47, buffer_id=08:2F [TRUNCATE prev:ch2 @43454.8ms -> 43630.4ms]
    db 82,1,63,1,58,108,9,3,233,0,58,8  ; n855 t=43.635s dur=319ms, freq=233Hz, sample=58, buffer_id=08:3A [TRUNCATE prev:ch3 @43454.8ms -> 43635.0ms]
    db 9,0,100,0,82,125,8,1,164,3,82,8  ; n856 t=43.973s dur=100ms, freq=932Hz, sample=82, buffer_id=08:52
    db 0,0,100,0,53,126,3,4,185,0,53,3  ; n857 t=43.982s dur=100ms, freq=185Hz, sample=53, buffer_id=03:35
    db 5,0,100,0,77,125,8,5,228,2,77,8  ; n858 t=43.982s dur=100ms, freq=740Hz, sample=77, buffer_id=08:4D
    db 9,0,100,0,70,124,4,6,210,1,70,4  ; n859 t=43.986s dur=100ms, freq=466Hz, sample=70, buffer_id=04:46
    db 144,0,100,0,58,126,3,10,233,0,58,3  ; n860 t=43.995s dur=100ms, freq=233Hz, sample=58, buffer_id=03:3A
    db 0,0,128,0,58,125,5,0,6,1,58,5  ; n861 t=44.139s dur=128ms, freq=262Hz, sample=58, buffer_id=05:3A
    db 0,0,186,3,63,125,5,2,93,1,63,5  ; n862 t=44.139s dur=954ms, freq=349Hz, sample=63, buffer_id=05:3F
    db 4,0,47,3,53,108,9,7,175,0,53,8  ; n863 t=44.139s dur=815ms, freq=175Hz, sample=53, buffer_id=08:35
    db 4,0,175,1,89,102,6,8,117,5,89,6  ; n864 t=44.144s dur=431ms, freq=1397Hz, sample=89, buffer_id=06:59
    db 38,0,218,5,89,125,8,9,117,5,89,8  ; n865 t=44.148s dur=1498ms, freq=1397Hz, sample=89, buffer_id=08:59
    db 82,1,231,3,77,124,4,3,186,2,77,4  ; n866 t=44.187s dur=999ms, freq=698Hz, sample=77, buffer_id=04:4D
    db 128,0,100,0,65,125,8,0,93,1,65,8  ; n867 t=44.524s dur=100ms, freq=349Hz, sample=65, buffer_id=08:41
    db 122,1,100,0,65,125,8,1,93,1,65,8  ; n868 t=44.652s dur=100ms, freq=349Hz, sample=65, buffer_id=08:41
    db 0,0,100,0,65,125,8,4,93,1,65,8  ; n869 t=45.030s dur=100ms, freq=349Hz, sample=65, buffer_id=08:41
    db 126,0,113,0,53,108,9,0,175,0,53,8  ; n870 t=45.030s dur=113ms, freq=175Hz, sample=53, buffer_id=08:35
    db 0,0,100,0,53,125,5,1,175,0,53,5  ; n871 t=45.157s dur=100ms, freq=175Hz, sample=53, buffer_id=05:35
    db 0,0,100,0,65,125,8,5,93,1,65,8  ; n872 t=45.157s dur=100ms, freq=349Hz, sample=65, buffer_id=08:41
    db 126,0,113,0,53,76,9,6,175,0,53,8  ; n873 t=45.157s dur=113ms, freq=175Hz, sample=53, buffer_id=08:35
    db 0,0,100,0,53,125,5,7,175,0,53,5  ; n874 t=45.282s dur=100ms, freq=175Hz, sample=53, buffer_id=05:35
    db 0,0,100,0,65,125,8,8,93,1,65,8  ; n875 t=45.282s dur=100ms, freq=349Hz, sample=65, buffer_id=08:41
    db 126,0,113,0,53,76,9,10,175,0,53,8  ; n876 t=45.282s dur=113ms, freq=175Hz, sample=53, buffer_id=08:35
    db 0,0,100,0,53,125,5,0,175,0,53,5  ; n877 t=45.409s dur=100ms, freq=175Hz, sample=53, buffer_id=05:35
    db 0,0,100,0,65,125,8,2,93,1,65,8  ; n878 t=45.409s dur=100ms, freq=349Hz, sample=65, buffer_id=08:41
    db 126,0,113,0,53,76,9,3,175,0,53,8  ; n879 t=45.409s dur=113ms, freq=175Hz, sample=53, buffer_id=08:35
    db 0,0,100,0,53,125,5,4,175,0,53,5  ; n880 t=45.535s dur=100ms, freq=175Hz, sample=53, buffer_id=05:35
    db 0,0,100,0,65,125,8,1,93,1,65,8  ; n881 t=45.535s dur=100ms, freq=349Hz, sample=65, buffer_id=08:41
    db 124,0,111,0,53,76,9,5,175,0,53,8  ; n882 t=45.535s dur=111ms, freq=175Hz, sample=53, buffer_id=08:35
    db 0,0,100,0,53,125,5,6,175,0,53,5  ; n883 t=45.659s dur=100ms, freq=175Hz, sample=53, buffer_id=05:35
    db 0,0,100,0,65,125,8,7,93,1,65,8  ; n884 t=45.659s dur=100ms, freq=349Hz, sample=65, buffer_id=08:41
    db 116,1,111,0,53,76,9,8,175,0,53,8  ; n885 t=45.659s dur=111ms, freq=175Hz, sample=53, buffer_id=08:35
    db 0,0,100,0,65,125,8,0,93,1,65,8  ; n886 t=46.031s dur=100ms, freq=349Hz, sample=65, buffer_id=08:41
    db 124,0,111,0,53,76,9,1,175,0,53,8  ; n887 t=46.031s dur=111ms, freq=175Hz, sample=53, buffer_id=08:35
    db 0,0,100,0,65,125,8,3,93,1,65,8  ; n888 t=46.155s dur=100ms, freq=349Hz, sample=65, buffer_id=08:41
    db 116,1,111,0,53,76,9,2,175,0,53,8  ; n889 t=46.155s dur=111ms, freq=175Hz, sample=53, buffer_id=08:35
    db 0,0,100,0,65,125,8,1,93,1,65,8  ; n890 t=46.527s dur=100ms, freq=349Hz, sample=65, buffer_id=08:41
    db 124,0,111,0,53,76,9,0,175,0,53,8  ; n891 t=46.527s dur=111ms, freq=175Hz, sample=53, buffer_id=08:35
    db 0,0,100,0,53,125,5,2,175,0,53,5  ; n892 t=46.651s dur=100ms, freq=175Hz, sample=53, buffer_id=05:35
    db 0,0,100,0,65,125,8,4,93,1,65,8  ; n893 t=46.651s dur=100ms, freq=349Hz, sample=65, buffer_id=08:41
    db 124,0,111,0,53,76,9,3,175,0,53,8  ; n894 t=46.651s dur=111ms, freq=175Hz, sample=53, buffer_id=08:35
    db 0,0,100,0,53,125,5,5,175,0,53,5  ; n895 t=46.775s dur=100ms, freq=175Hz, sample=53, buffer_id=05:35
    db 0,0,100,0,65,125,8,6,93,1,65,8  ; n896 t=46.775s dur=100ms, freq=349Hz, sample=65, buffer_id=08:41
    db 124,0,111,0,53,76,9,7,175,0,53,8  ; n897 t=46.775s dur=111ms, freq=175Hz, sample=53, buffer_id=08:35
    db 0,0,100,0,53,125,5,0,175,0,53,5  ; n898 t=46.899s dur=100ms, freq=175Hz, sample=53, buffer_id=05:35
    db 0,0,100,0,65,125,8,8,93,1,65,8  ; n899 t=46.899s dur=100ms, freq=349Hz, sample=65, buffer_id=08:41
    db 124,0,111,0,53,76,9,1,175,0,53,8  ; n900 t=46.899s dur=111ms, freq=175Hz, sample=53, buffer_id=08:35
    db 0,0,100,0,70,124,4,2,210,1,70,4  ; n901 t=47.023s dur=100ms, freq=466Hz, sample=70, buffer_id=04:46
    db 0,0,100,0,65,124,4,3,136,1,65,4  ; n902 t=47.023s dur=100ms, freq=392Hz, sample=65, buffer_id=04:41
    db 0,0,100,0,65,124,4,4,55,1,65,4  ; n903 t=47.023s dur=100ms, freq=311Hz, sample=65, buffer_id=04:41
    db 0,0,100,0,53,125,5,9,175,0,53,5  ; n904 t=47.023s dur=100ms, freq=175Hz, sample=53, buffer_id=05:35
    db 0,0,100,0,65,125,8,10,93,1,65,8  ; n905 t=47.023s dur=100ms, freq=349Hz, sample=65, buffer_id=08:41
    db 124,0,111,0,53,76,9,11,175,0,53,8  ; n906 t=47.023s dur=111ms, freq=175Hz, sample=53, buffer_id=08:35
    db 0,0,190,1,70,124,4,5,210,1,70,4  ; n907 t=47.147s dur=446ms, freq=466Hz, sample=70, buffer_id=04:46
    db 0,0,210,1,65,124,4,6,136,1,65,4  ; n908 t=47.147s dur=466ms, freq=392Hz, sample=65, buffer_id=04:41
    db 0,0,215,1,65,124,4,7,55,1,65,4  ; n909 t=47.147s dur=471ms, freq=311Hz, sample=65, buffer_id=04:41
    db 0,0,100,0,53,125,5,12,175,0,53,5  ; n910 t=47.147s dur=100ms, freq=175Hz, sample=53, buffer_id=05:35
    db 0,0,100,0,65,125,8,13,93,1,65,8  ; n911 t=47.147s dur=100ms, freq=349Hz, sample=65, buffer_id=08:41
    db 116,1,111,0,53,76,9,1,175,0,53,8  ; n912 t=47.147s dur=111ms, freq=175Hz, sample=53, buffer_id=08:35 [TRUNCATE prev:ch1 @46898.6ms -> 47146.6ms]
    db 0,0,100,0,65,125,8,0,93,1,65,8  ; n913 t=47.519s dur=100ms, freq=349Hz, sample=65, buffer_id=08:41
    db 124,0,111,0,53,76,9,2,175,0,53,8  ; n914 t=47.519s dur=111ms, freq=175Hz, sample=53, buffer_id=08:35
    db 0,0,128,0,65,124,4,1,74,1,65,4  ; n915 t=47.642s dur=128ms, freq=330Hz, sample=65, buffer_id=04:41
    db 0,0,219,0,65,124,4,8,136,1,65,4  ; n916 t=47.642s dur=219ms, freq=392Hz, sample=65, buffer_id=04:41
    db 0,0,227,0,58,124,4,3,6,1,58,4  ; n917 t=47.642s dur=227ms, freq=262Hz, sample=58, buffer_id=04:3A
    db 0,0,100,0,65,125,8,4,93,1,65,8  ; n918 t=47.642s dur=100ms, freq=349Hz, sample=65, buffer_id=08:41
    db 116,1,111,0,53,76,9,9,175,0,53,8  ; n919 t=47.642s dur=111ms, freq=175Hz, sample=53, buffer_id=08:35
    db 0,0,100,0,70,124,4,0,210,1,70,4  ; n920 t=48.014s dur=100ms, freq=466Hz, sample=70, buffer_id=04:46
    db 0,0,100,0,65,124,4,2,136,1,65,4  ; n921 t=48.014s dur=100ms, freq=392Hz, sample=65, buffer_id=04:41
    db 0,0,100,0,65,124,4,4,55,1,65,4  ; n922 t=48.014s dur=100ms, freq=311Hz, sample=65, buffer_id=04:41
    db 0,0,100,0,65,125,8,1,93,1,65,8  ; n923 t=48.014s dur=100ms, freq=349Hz, sample=65, buffer_id=08:41
    db 124,0,111,0,53,76,9,5,175,0,53,8  ; n924 t=48.014s dur=111ms, freq=175Hz, sample=53, buffer_id=08:35
    db 0,0,202,1,65,124,4,3,136,1,65,4  ; n925 t=48.138s dur=458ms, freq=392Hz, sample=65, buffer_id=04:41
    db 0,0,244,1,65,124,4,9,55,1,65,4  ; n926 t=48.138s dur=500ms, freq=311Hz, sample=65, buffer_id=04:41
    db 0,0,16,2,70,124,4,6,210,1,70,4  ; n927 t=48.138s dur=528ms, freq=466Hz, sample=70, buffer_id=04:46
    db 0,0,100,0,53,125,5,7,175,0,53,5  ; n928 t=48.138s dur=100ms, freq=175Hz, sample=53, buffer_id=05:35
    db 0,0,100,0,65,125,8,8,93,1,65,8  ; n929 t=48.138s dur=100ms, freq=349Hz, sample=65, buffer_id=08:41
    db 124,0,111,0,53,76,9,10,175,0,53,8  ; n930 t=48.138s dur=111ms, freq=175Hz, sample=53, buffer_id=08:35
    db 0,0,100,0,53,125,5,11,175,0,53,5  ; n931 t=48.262s dur=100ms, freq=175Hz, sample=53, buffer_id=05:35
    db 0,0,100,0,65,125,8,12,93,1,65,8  ; n932 t=48.262s dur=100ms, freq=349Hz, sample=65, buffer_id=08:41
    db 124,0,111,0,53,76,9,13,175,0,53,8  ; n933 t=48.262s dur=111ms, freq=175Hz, sample=53, buffer_id=08:35
    db 0,0,100,0,53,125,5,0,175,0,53,5  ; n934 t=48.386s dur=100ms, freq=175Hz, sample=53, buffer_id=05:35
    db 0,0,100,0,65,125,8,2,93,1,65,8  ; n935 t=48.386s dur=100ms, freq=349Hz, sample=65, buffer_id=08:41
    db 124,0,111,0,53,76,9,1,175,0,53,8  ; n936 t=48.386s dur=111ms, freq=175Hz, sample=53, buffer_id=08:35
    db 0,0,100,0,53,125,5,4,175,0,53,5  ; n937 t=48.510s dur=100ms, freq=175Hz, sample=53, buffer_id=05:35
    db 0,0,100,0,65,125,8,5,93,1,65,8  ; n938 t=48.510s dur=100ms, freq=349Hz, sample=65, buffer_id=08:41
    db 124,0,111,0,53,76,9,7,175,0,53,8  ; n939 t=48.510s dur=111ms, freq=175Hz, sample=53, buffer_id=08:35
    db 0,0,148,0,65,124,4,8,74,1,65,4  ; n940 t=48.634s dur=148ms, freq=330Hz, sample=65, buffer_id=04:41
    db 0,0,165,0,65,124,4,10,136,1,65,4  ; n941 t=48.634s dur=165ms, freq=392Hz, sample=65, buffer_id=04:41
    db 0,0,206,0,58,124,4,11,6,1,58,4  ; n942 t=48.634s dur=206ms, freq=262Hz, sample=58, buffer_id=04:3A
    db 0,0,103,0,53,125,5,12,175,0,53,5  ; n943 t=48.634s dur=103ms, freq=175Hz, sample=53, buffer_id=05:35
    db 0,0,100,0,65,125,8,13,93,1,65,8  ; n944 t=48.634s dur=100ms, freq=349Hz, sample=65, buffer_id=08:41
    db 116,1,111,0,53,76,9,1,175,0,53,8  ; n945 t=48.634s dur=111ms, freq=175Hz, sample=53, buffer_id=08:35 [TRUNCATE prev:ch1 @48386.2ms -> 48634.2ms]
    db 0,0,100,0,72,124,4,0,42,2,72,4  ; n946 t=49.006s dur=100ms, freq=554Hz, sample=72, buffer_id=04:48
    db 0,0,100,0,70,124,4,1,210,1,70,4  ; n947 t=49.006s dur=100ms, freq=466Hz, sample=70, buffer_id=04:46
    db 0,0,100,0,65,124,4,2,114,1,65,4  ; n948 t=49.006s dur=100ms, freq=370Hz, sample=65, buffer_id=04:41
    db 0,0,100,0,65,125,8,3,93,1,65,8  ; n949 t=49.006s dur=100ms, freq=349Hz, sample=65, buffer_id=08:41
    db 124,0,111,0,53,76,9,4,175,0,53,8  ; n950 t=49.006s dur=111ms, freq=175Hz, sample=53, buffer_id=08:35
    db 0,0,144,1,70,124,4,5,210,1,70,4  ; n951 t=49.130s dur=400ms, freq=466Hz, sample=70, buffer_id=04:46
    db 0,0,239,1,65,124,4,6,114,1,65,4  ; n952 t=49.130s dur=495ms, freq=370Hz, sample=65, buffer_id=04:41
    db 0,0,4,2,72,124,4,7,42,2,72,4  ; n953 t=49.130s dur=516ms, freq=554Hz, sample=72, buffer_id=04:48
    db 0,0,100,0,65,125,8,8,93,1,65,8  ; n954 t=49.130s dur=100ms, freq=349Hz, sample=65, buffer_id=08:41
    db 116,1,111,0,53,76,9,9,175,0,53,8  ; n955 t=49.130s dur=111ms, freq=175Hz, sample=53, buffer_id=08:35
    db 0,0,100,0,65,125,8,0,93,1,65,8  ; n956 t=49.502s dur=100ms, freq=349Hz, sample=65, buffer_id=08:41
    db 124,0,111,0,53,76,9,1,175,0,53,8  ; n957 t=49.502s dur=111ms, freq=175Hz, sample=53, buffer_id=08:35
    db 0,0,136,0,70,124,4,2,184,1,70,4  ; n958 t=49.626s dur=136ms, freq=440Hz, sample=70, buffer_id=04:46
    db 0,0,148,0,72,124,4,3,11,2,72,4  ; n959 t=49.626s dur=148ms, freq=523Hz, sample=72, buffer_id=04:48
    db 0,0,165,0,65,124,4,4,93,1,65,4  ; n960 t=49.626s dur=165ms, freq=349Hz, sample=65, buffer_id=04:41
    db 0,0,100,0,53,125,5,8,175,0,53,5  ; n961 t=49.626s dur=100ms, freq=175Hz, sample=53, buffer_id=05:35
    db 0,0,100,0,65,125,8,9,93,1,65,8  ; n962 t=49.626s dur=100ms, freq=349Hz, sample=65, buffer_id=08:41
    db 124,0,111,0,53,76,9,10,175,0,53,8  ; n963 t=49.626s dur=111ms, freq=175Hz, sample=53, buffer_id=08:35
    db 0,0,100,0,53,125,5,5,175,0,53,5  ; n964 t=49.750s dur=100ms, freq=175Hz, sample=53, buffer_id=05:35
    db 0,0,100,0,65,125,8,11,93,1,65,8  ; n965 t=49.750s dur=100ms, freq=349Hz, sample=65, buffer_id=08:41
    db 124,0,111,0,53,76,9,12,175,0,53,8  ; n966 t=49.750s dur=111ms, freq=175Hz, sample=53, buffer_id=08:35
    db 0,0,100,0,70,124,4,0,210,1,70,4  ; n967 t=49.874s dur=100ms, freq=466Hz, sample=70, buffer_id=04:46
    db 0,0,115,0,72,124,4,1,42,2,72,4  ; n968 t=49.874s dur=115ms, freq=554Hz, sample=72, buffer_id=04:48
    db 0,0,128,0,65,124,4,7,114,1,65,4  ; n969 t=49.874s dur=128ms, freq=370Hz, sample=65, buffer_id=04:41
    db 0,0,100,0,53,125,5,6,175,0,53,5  ; n970 t=49.874s dur=100ms, freq=175Hz, sample=53, buffer_id=05:35
    db 0,0,100,0,65,125,8,13,93,1,65,8  ; n971 t=49.874s dur=100ms, freq=349Hz, sample=65, buffer_id=08:41 [TRUNCATE prev:ch13 @48634.2ms -> 49873.8ms]
    db 124,0,111,0,53,76,9,10,175,0,53,8  ; n972 t=49.874s dur=111ms, freq=175Hz, sample=53, buffer_id=08:35 [TRUNCATE prev:ch10 @49625.9ms -> 49873.8ms]
    db 0,0,111,0,70,124,4,3,184,1,70,4  ; n973 t=49.998s dur=111ms, freq=440Hz, sample=70, buffer_id=04:46
    db 0,0,128,0,72,124,4,2,11,2,72,4  ; n974 t=49.998s dur=128ms, freq=523Hz, sample=72, buffer_id=04:48
    db 0,0,152,0,65,124,4,8,93,1,65,4  ; n975 t=49.998s dur=152ms, freq=349Hz, sample=65, buffer_id=04:41
    db 0,0,100,0,53,125,5,4,175,0,53,5  ; n976 t=49.998s dur=100ms, freq=175Hz, sample=53, buffer_id=05:35
    db 0,0,100,0,65,125,8,9,93,1,65,8  ; n977 t=49.998s dur=100ms, freq=349Hz, sample=65, buffer_id=08:41 [TRUNCATE prev:ch9 @49625.9ms -> 49997.8ms]
    db 124,0,111,0,53,76,9,12,175,0,53,8  ; n978 t=49.998s dur=111ms, freq=175Hz, sample=53, buffer_id=08:35 [TRUNCATE prev:ch12 @49749.9ms -> 49997.8ms]
    db 0,0,100,0,65,124,4,5,55,1,65,4  ; n979 t=50.122s dur=100ms, freq=311Hz, sample=65, buffer_id=04:41
    db 0,0,100,0,65,124,4,11,136,1,65,4  ; n980 t=50.122s dur=100ms, freq=392Hz, sample=65, buffer_id=04:41
    db 0,0,100,0,70,124,4,0,210,1,70,4  ; n981 t=50.122s dur=100ms, freq=466Hz, sample=70, buffer_id=04:46 [TRUNCATE prev:ch0 @49873.8ms -> 50121.8ms]
    db 0,0,100,0,53,125,5,6,175,0,53,5  ; n982 t=50.122s dur=100ms, freq=175Hz, sample=53, buffer_id=05:35 [TRUNCATE prev:ch6 @49873.8ms -> 50121.8ms]
    db 0,0,100,0,65,125,8,13,93,1,65,8  ; n983 t=50.122s dur=100ms, freq=349Hz, sample=65, buffer_id=08:41 [TRUNCATE prev:ch13 @49873.8ms -> 50121.8ms]
    db 248,0,111,0,53,76,9,10,175,0,53,8  ; n984 t=50.122s dur=111ms, freq=175Hz, sample=53, buffer_id=08:35 [TRUNCATE prev:ch10 @49873.8ms -> 50121.8ms]
    db 0,0,65,15,65,124,4,1,74,1,65,4  ; n985 t=50.370s dur=3905ms, freq=330Hz, sample=65, buffer_id=04:41
    db 0,0,44,12,58,124,4,2,6,1,58,4  ; n986 t=50.370s dur=3116ms, freq=262Hz, sample=58, buffer_id=04:3A
    db 124,0,101,14,65,124,4,3,136,1,65,4  ; n987 t=50.370s dur=3685ms, freq=392Hz, sample=65, buffer_id=04:41
    db 0,0,100,0,65,125,8,0,93,1,65,8  ; n988 t=50.494s dur=100ms, freq=349Hz, sample=65, buffer_id=08:41
    db 124,0,111,0,53,76,9,4,175,0,53,8  ; n989 t=50.494s dur=111ms, freq=175Hz, sample=53, buffer_id=08:35
    db 0,0,100,0,65,125,8,5,93,1,65,8  ; n990 t=50.618s dur=100ms, freq=349Hz, sample=65, buffer_id=08:41
    db 116,1,111,0,53,76,9,6,175,0,53,8  ; n991 t=50.618s dur=111ms, freq=175Hz, sample=53, buffer_id=08:35
    db 0,0,100,0,65,125,8,4,93,1,65,8  ; n992 t=50.989s dur=100ms, freq=349Hz, sample=65, buffer_id=08:41
    db 124,0,111,0,53,76,9,0,175,0,53,8  ; n993 t=50.989s dur=111ms, freq=175Hz, sample=53, buffer_id=08:35
    db 0,0,100,0,53,125,5,5,175,0,53,5  ; n994 t=51.114s dur=100ms, freq=175Hz, sample=53, buffer_id=05:35
    db 0,0,100,0,61,125,8,6,21,1,61,8  ; n995 t=51.114s dur=100ms, freq=277Hz, sample=61, buffer_id=08:3D
    db 29,0,111,0,50,76,9,7,139,0,50,8  ; n996 t=51.114s dur=111ms, freq=139Hz, sample=50, buffer_id=08:32
    db 95,0,100,0,61,125,8,8,21,1,61,8  ; n997 t=51.142s dur=100ms, freq=277Hz, sample=61, buffer_id=08:3D
    db 0,0,100,0,53,125,5,9,175,0,53,5  ; n998 t=51.237s dur=100ms, freq=175Hz, sample=53, buffer_id=05:35
    db 0,0,100,0,61,125,8,10,21,1,61,8  ; n999 t=51.237s dur=100ms, freq=277Hz, sample=61, buffer_id=08:3D
    db 25,0,111,0,50,76,9,11,139,0,50,8  ; n1000 t=51.237s dur=111ms, freq=139Hz, sample=50, buffer_id=08:32
    db 99,0,100,0,61,125,8,12,21,1,61,8  ; n1001 t=51.262s dur=100ms, freq=277Hz, sample=61, buffer_id=08:3D
    db 0,0,100,0,53,125,5,0,175,0,53,5  ; n1002 t=51.361s dur=100ms, freq=175Hz, sample=53, buffer_id=05:35
    db 0,0,100,0,61,125,8,4,21,1,61,8  ; n1003 t=51.361s dur=100ms, freq=277Hz, sample=61, buffer_id=08:3D
    db 25,0,111,0,50,76,9,13,139,0,50,8  ; n1004 t=51.361s dur=111ms, freq=139Hz, sample=50, buffer_id=08:32
    db 99,0,100,0,61,125,8,6,21,1,61,8  ; n1005 t=51.386s dur=100ms, freq=277Hz, sample=61, buffer_id=08:3D [TRUNCATE prev:ch6 @51113.5ms -> 51386.2ms]
    db 0,0,100,0,53,125,5,7,175,0,53,5  ; n1006 t=51.485s dur=100ms, freq=175Hz, sample=53, buffer_id=05:35
    db 0,0,100,0,61,125,8,5,21,1,61,8  ; n1007 t=51.485s dur=100ms, freq=277Hz, sample=61, buffer_id=08:3D
    db 12,0,111,0,50,76,9,8,139,0,50,8  ; n1008 t=51.485s dur=111ms, freq=139Hz, sample=50, buffer_id=08:32
    db 112,0,100,0,61,125,8,10,21,1,61,8  ; n1009 t=51.498s dur=100ms, freq=277Hz, sample=61, buffer_id=08:3D [TRUNCATE prev:ch10 @51237.5ms -> 51497.8ms]
    db 0,0,100,0,53,125,5,11,175,0,53,5  ; n1010 t=51.609s dur=100ms, freq=175Hz, sample=53, buffer_id=05:35
    db 0,0,100,0,65,125,8,9,93,1,65,8  ; n1011 t=51.609s dur=100ms, freq=349Hz, sample=65, buffer_id=08:41
    db 116,1,111,0,53,76,9,12,175,0,53,8  ; n1012 t=51.609s dur=111ms, freq=175Hz, sample=53, buffer_id=08:35
    db 0,0,100,0,65,125,8,0,93,1,65,8  ; n1013 t=51.981s dur=100ms, freq=349Hz, sample=65, buffer_id=08:41
    db 124,0,111,0,53,76,9,4,175,0,53,8  ; n1014 t=51.981s dur=111ms, freq=175Hz, sample=53, buffer_id=08:35
    db 0,0,100,0,65,125,8,5,93,1,65,8  ; n1015 t=52.105s dur=100ms, freq=349Hz, sample=65, buffer_id=08:41
    db 116,1,111,0,53,76,9,6,175,0,53,8  ; n1016 t=52.105s dur=111ms, freq=175Hz, sample=53, buffer_id=08:35
    db 0,0,100,0,65,125,8,4,93,1,65,8  ; n1017 t=52.477s dur=100ms, freq=349Hz, sample=65, buffer_id=08:41
    db 124,0,111,0,53,76,9,0,175,0,53,8  ; n1018 t=52.477s dur=111ms, freq=175Hz, sample=53, buffer_id=08:35
    db 0,0,100,0,53,125,5,5,175,0,53,5  ; n1019 t=52.601s dur=100ms, freq=175Hz, sample=53, buffer_id=05:35
    db 0,0,100,0,61,125,8,6,21,1,61,8  ; n1020 t=52.601s dur=100ms, freq=277Hz, sample=61, buffer_id=08:3D
    db 0,0,100,0,61,125,8,7,21,1,61,8  ; n1021 t=52.601s dur=100ms, freq=277Hz, sample=61, buffer_id=08:3D
    db 116,0,111,0,50,76,9,9,139,0,50,8  ; n1022 t=52.601s dur=111ms, freq=139Hz, sample=50, buffer_id=08:32
    db 8,0,100,0,61,125,8,8,21,1,61,8  ; n1023 t=52.717s dur=100ms, freq=277Hz, sample=61, buffer_id=08:3D
    db 0,0,100,0,53,125,5,10,175,0,53,5  ; n1024 t=52.725s dur=100ms, freq=175Hz, sample=53, buffer_id=05:35
    db 0,0,100,0,61,125,8,11,21,1,61,8  ; n1025 t=52.725s dur=100ms, freq=277Hz, sample=61, buffer_id=08:3D
    db 111,0,111,0,50,76,9,12,139,0,50,8  ; n1026 t=52.725s dur=111ms, freq=139Hz, sample=50, buffer_id=08:32
    db 12,0,100,0,61,125,8,0,21,1,61,8  ; n1027 t=52.837s dur=100ms, freq=277Hz, sample=61, buffer_id=08:3D
    db 0,0,100,0,53,125,5,4,175,0,53,5  ; n1028 t=52.849s dur=100ms, freq=175Hz, sample=53, buffer_id=05:35
    db 0,0,100,0,61,125,8,13,21,1,61,8  ; n1029 t=52.849s dur=100ms, freq=277Hz, sample=61, buffer_id=08:3D
    db 95,0,111,0,50,76,9,9,139,0,50,8  ; n1030 t=52.849s dur=111ms, freq=139Hz, sample=50, buffer_id=08:32 [TRUNCATE prev:ch9 @52601.1ms -> 52849.0ms]
    db 29,0,100,0,61,125,8,5,21,1,61,8  ; n1031 t=52.944s dur=100ms, freq=277Hz, sample=61, buffer_id=08:3D
    db 0,0,100,0,53,125,5,6,175,0,53,5  ; n1032 t=52.973s dur=100ms, freq=175Hz, sample=53, buffer_id=05:35
    db 0,0,100,0,61,125,8,7,21,1,61,8  ; n1033 t=52.973s dur=100ms, freq=277Hz, sample=61, buffer_id=08:3D [TRUNCATE prev:ch7 @52601.1ms -> 52973.0ms]
    db 124,0,111,0,50,76,9,12,139,0,50,8  ; n1034 t=52.973s dur=111ms, freq=139Hz, sample=50, buffer_id=08:32 [TRUNCATE prev:ch12 @52725.1ms -> 52973.0ms]
    db 0,0,100,0,53,125,5,8,175,0,53,5  ; n1035 t=53.097s dur=100ms, freq=175Hz, sample=53, buffer_id=05:35
    db 0,0,100,0,65,125,8,10,93,1,65,8  ; n1036 t=53.097s dur=100ms, freq=349Hz, sample=65, buffer_id=08:41
    db 116,1,111,0,53,76,9,11,175,0,53,8  ; n1037 t=53.097s dur=111ms, freq=175Hz, sample=53, buffer_id=08:35
    db 0,0,100,0,65,125,8,0,93,1,65,8  ; n1038 t=53.469s dur=100ms, freq=349Hz, sample=65, buffer_id=08:41
    db 124,0,111,0,53,76,9,4,175,0,53,8  ; n1039 t=53.469s dur=111ms, freq=175Hz, sample=53, buffer_id=08:35
    db 0,0,100,0,65,125,8,5,93,1,65,8  ; n1040 t=53.593s dur=100ms, freq=349Hz, sample=65, buffer_id=08:41
    db 116,1,111,0,53,76,9,6,175,0,53,8  ; n1041 t=53.593s dur=111ms, freq=175Hz, sample=53, buffer_id=08:35
    db 0,0,100,0,65,125,8,2,93,1,65,8  ; n1042 t=53.965s dur=100ms, freq=349Hz, sample=65, buffer_id=08:41
    db 116,0,111,0,53,76,9,0,175,0,53,8  ; n1043 t=53.965s dur=111ms, freq=175Hz, sample=53, buffer_id=08:35
    db 8,0,100,0,61,125,8,4,21,1,61,8  ; n1044 t=54.080s dur=100ms, freq=277Hz, sample=61, buffer_id=08:3D
    db 0,0,100,0,53,125,5,5,175,0,53,5  ; n1045 t=54.089s dur=100ms, freq=175Hz, sample=53, buffer_id=05:35
    db 0,0,100,0,61,125,8,6,21,1,61,8  ; n1046 t=54.089s dur=100ms, freq=277Hz, sample=61, buffer_id=08:3D
    db 116,0,111,0,50,76,9,7,139,0,50,8  ; n1047 t=54.089s dur=111ms, freq=139Hz, sample=50, buffer_id=08:32
    db 8,0,100,0,61,125,8,8,21,1,61,8  ; n1048 t=54.204s dur=100ms, freq=277Hz, sample=61, buffer_id=08:3D
    db 0,0,100,0,53,125,5,9,175,0,53,5  ; n1049 t=54.213s dur=100ms, freq=175Hz, sample=53, buffer_id=05:35
    db 0,0,100,0,61,125,8,10,21,1,61,8  ; n1050 t=54.213s dur=100ms, freq=277Hz, sample=61, buffer_id=08:3D
    db 124,0,111,0,50,76,9,11,139,0,50,8  ; n1051 t=54.213s dur=111ms, freq=139Hz, sample=50, buffer_id=08:32
    db 0,0,100,0,53,125,5,0,175,0,53,5  ; n1052 t=54.337s dur=100ms, freq=175Hz, sample=53, buffer_id=05:35
    db 0,0,100,0,61,125,8,2,21,1,61,8  ; n1053 t=54.337s dur=100ms, freq=277Hz, sample=61, buffer_id=08:3D
    db 0,0,100,0,61,125,8,3,21,1,61,8  ; n1054 t=54.337s dur=100ms, freq=277Hz, sample=61, buffer_id=08:3D
    db 95,0,111,0,50,76,9,13,139,0,50,8  ; n1055 t=54.337s dur=111ms, freq=139Hz, sample=50, buffer_id=08:32
    db 29,0,100,0,61,125,8,5,21,1,61,8  ; n1056 t=54.432s dur=100ms, freq=277Hz, sample=61, buffer_id=08:3D
    db 0,0,100,0,53,125,5,4,175,0,53,5  ; n1057 t=54.461s dur=100ms, freq=175Hz, sample=53, buffer_id=05:35
    db 0,0,100,0,61,125,8,7,21,1,61,8  ; n1058 t=54.461s dur=100ms, freq=277Hz, sample=61, buffer_id=08:3D
    db 124,0,111,0,50,76,9,6,139,0,50,8  ; n1059 t=54.461s dur=111ms, freq=139Hz, sample=50, buffer_id=08:32
    db 0,0,124,0,53,125,5,1,175,0,53,5  ; n1060 t=54.585s dur=124ms, freq=175Hz, sample=53, buffer_id=05:35
    db 0,0,100,0,65,125,8,8,93,1,65,8  ; n1061 t=54.585s dur=100ms, freq=349Hz, sample=65, buffer_id=08:41
    db 124,0,111,0,53,76,9,9,175,0,53,8  ; n1062 t=54.585s dur=111ms, freq=175Hz, sample=53, buffer_id=08:35
    db 0,0,100,0,65,125,8,0,93,1,65,8  ; n1063 t=54.709s dur=100ms, freq=349Hz, sample=65, buffer_id=08:41
    db 124,0,111,0,53,76,9,2,175,0,53,8  ; n1064 t=54.709s dur=111ms, freq=175Hz, sample=53, buffer_id=08:35
    db 0,0,100,0,65,125,8,3,93,1,65,8  ; n1065 t=54.833s dur=100ms, freq=349Hz, sample=65, buffer_id=08:41
    db 124,0,111,0,53,76,9,4,175,0,53,8  ; n1066 t=54.833s dur=111ms, freq=175Hz, sample=53, buffer_id=08:35
    db 0,0,100,0,53,125,5,5,175,0,53,5  ; n1067 t=54.956s dur=100ms, freq=175Hz, sample=53, buffer_id=05:35
    db 0,0,100,0,65,125,8,1,93,1,65,8  ; n1068 t=54.956s dur=100ms, freq=349Hz, sample=65, buffer_id=08:41
    db 124,0,111,0,53,76,9,6,175,0,53,8  ; n1069 t=54.956s dur=111ms, freq=175Hz, sample=53, buffer_id=08:35
    db 0,0,100,0,55,125,5,0,208,0,55,5  ; n1070 t=55.080s dur=100ms, freq=208Hz, sample=55, buffer_id=05:37
    db 0,0,100,0,59,125,8,2,6,1,59,8  ; n1071 t=55.080s dur=100ms, freq=262Hz, sample=59, buffer_id=08:3B
    db 124,0,111,0,47,76,9,7,131,0,47,8  ; n1072 t=55.080s dur=111ms, freq=131Hz, sample=47, buffer_id=08:2F
    db 0,0,100,0,55,125,5,3,208,0,55,5  ; n1073 t=55.204s dur=100ms, freq=208Hz, sample=55, buffer_id=05:37
    db 0,0,100,0,59,125,8,4,6,1,59,8  ; n1074 t=55.204s dur=100ms, freq=262Hz, sample=59, buffer_id=08:3B
    db 124,0,111,0,47,76,9,8,131,0,47,8  ; n1075 t=55.204s dur=111ms, freq=131Hz, sample=47, buffer_id=08:2F
    db 0,0,100,0,55,125,5,1,208,0,55,5  ; n1076 t=55.328s dur=100ms, freq=208Hz, sample=55, buffer_id=05:37
    db 0,0,100,0,59,125,8,5,6,1,59,8  ; n1077 t=55.328s dur=100ms, freq=262Hz, sample=59, buffer_id=08:3B
    db 124,0,111,0,47,76,9,6,131,0,47,8  ; n1078 t=55.328s dur=111ms, freq=131Hz, sample=47, buffer_id=08:2F
    db 0,0,100,0,55,125,5,2,208,0,55,5  ; n1079 t=55.452s dur=100ms, freq=208Hz, sample=55, buffer_id=05:37
    db 0,0,100,0,59,125,8,0,6,1,59,8  ; n1080 t=55.452s dur=100ms, freq=262Hz, sample=59, buffer_id=08:3B
    db 240,1,111,0,47,76,9,9,131,0,47,8  ; n1081 t=55.452s dur=111ms, freq=131Hz, sample=47, buffer_id=08:2F
    db 0,0,100,0,67,125,8,0,136,1,67,8  ; n1082 t=55.948s dur=100ms, freq=392Hz, sample=67, buffer_id=08:43
    db 124,0,111,0,55,76,9,1,196,0,55,8  ; n1083 t=55.948s dur=111ms, freq=196Hz, sample=55, buffer_id=08:37
    db 0,0,100,0,67,125,8,2,136,1,67,8  ; n1084 t=56.072s dur=100ms, freq=392Hz, sample=67, buffer_id=08:43
    db 116,1,111,0,55,76,9,3,196,0,55,8  ; n1085 t=56.072s dur=111ms, freq=196Hz, sample=55, buffer_id=08:37
    db 0,0,100,0,67,125,8,1,136,1,67,8  ; n1086 t=56.444s dur=100ms, freq=392Hz, sample=67, buffer_id=08:43
    db 124,0,111,0,55,76,9,0,196,0,55,8  ; n1087 t=56.444s dur=111ms, freq=196Hz, sample=55, buffer_id=08:37
    db 0,0,100,0,67,125,8,3,136,1,67,8  ; n1088 t=56.568s dur=100ms, freq=392Hz, sample=67, buffer_id=08:43
    db 116,1,111,0,55,76,9,2,196,0,55,8  ; n1089 t=56.568s dur=111ms, freq=196Hz, sample=55, buffer_id=08:37
    db 0,0,100,0,67,125,8,0,136,1,67,8  ; n1090 t=56.940s dur=100ms, freq=392Hz, sample=67, buffer_id=08:43
    db 124,0,111,0,55,76,9,1,196,0,55,8  ; n1091 t=56.940s dur=111ms, freq=196Hz, sample=55, buffer_id=08:37
    db 0,0,100,0,67,125,8,2,136,1,67,8  ; n1092 t=57.064s dur=100ms, freq=392Hz, sample=67, buffer_id=08:43
    db 124,0,111,0,55,76,9,3,196,0,55,8  ; n1093 t=57.064s dur=111ms, freq=196Hz, sample=55, buffer_id=08:37
    db 0,0,100,0,67,125,8,4,136,1,67,8  ; n1094 t=57.188s dur=100ms, freq=392Hz, sample=67, buffer_id=08:43
    db 124,0,111,0,55,76,9,5,196,0,55,8  ; n1095 t=57.188s dur=111ms, freq=196Hz, sample=55, buffer_id=08:37
    db 0,0,100,0,67,125,8,1,136,1,67,8  ; n1096 t=57.312s dur=100ms, freq=392Hz, sample=67, buffer_id=08:43
    db 116,0,111,0,55,76,9,0,196,0,55,8  ; n1097 t=57.312s dur=111ms, freq=196Hz, sample=55, buffer_id=08:37
    db 8,0,100,0,65,124,4,2,93,1,65,4  ; n1098 t=57.428s dur=100ms, freq=349Hz, sample=65, buffer_id=04:41
    db 0,0,100,0,72,124,4,3,11,2,72,4  ; n1099 t=57.436s dur=100ms, freq=523Hz, sample=72, buffer_id=04:48
    db 0,0,100,0,67,125,8,6,136,1,67,8  ; n1100 t=57.436s dur=100ms, freq=392Hz, sample=67, buffer_id=08:43
    db 12,0,111,0,55,76,9,7,196,0,55,8  ; n1101 t=57.436s dur=111ms, freq=196Hz, sample=55, buffer_id=08:37
    db 33,0,100,0,70,124,4,8,184,1,70,4  ; n1102 t=57.448s dur=100ms, freq=440Hz, sample=70, buffer_id=04:46
    db 79,0,100,0,58,126,3,9,6,1,58,3  ; n1103 t=57.481s dur=100ms, freq=262Hz, sample=58, buffer_id=03:3A
    db 0,0,100,0,67,125,8,5,136,1,67,8  ; n1104 t=57.560s dur=100ms, freq=392Hz, sample=67, buffer_id=08:43
    db 21,0,111,0,55,76,9,4,196,0,55,8  ; n1105 t=57.560s dur=111ms, freq=196Hz, sample=55, buffer_id=08:37
    db 4,0,4,2,65,124,4,10,93,1,65,4  ; n1106 t=57.580s dur=516ms, freq=349Hz, sample=65, buffer_id=04:41
    db 4,0,210,1,72,124,4,11,11,2,72,4  ; n1107 t=57.585s dur=466ms, freq=523Hz, sample=72, buffer_id=04:48
    db 4,0,239,1,70,124,4,12,184,1,70,4  ; n1108 t=57.589s dur=495ms, freq=440Hz, sample=70, buffer_id=04:46
    db 83,1,4,2,58,126,3,13,6,1,58,3  ; n1109 t=57.593s dur=516ms, freq=262Hz, sample=58, buffer_id=03:3A
    db 0,0,100,0,67,125,8,0,136,1,67,8  ; n1110 t=57.932s dur=100ms, freq=392Hz, sample=67, buffer_id=08:43
    db 124,0,111,0,55,76,9,1,196,0,55,8  ; n1111 t=57.932s dur=111ms, freq=196Hz, sample=55, buffer_id=08:37
    db 0,0,100,0,67,125,8,2,136,1,67,8  ; n1112 t=58.056s dur=100ms, freq=392Hz, sample=67, buffer_id=08:43
    db 33,0,111,0,55,76,9,3,196,0,55,8  ; n1113 t=58.056s dur=111ms, freq=196Hz, sample=55, buffer_id=08:37
    db 0,0,177,0,70,124,4,4,184,1,70,4  ; n1114 t=58.089s dur=177ms, freq=440Hz, sample=70, buffer_id=04:46
    db 21,0,190,0,65,124,4,5,38,1,65,4  ; n1115 t=58.089s dur=190ms, freq=294Hz, sample=65, buffer_id=04:41
    db 8,0,124,0,58,126,3,6,220,0,58,3  ; n1116 t=58.109s dur=124ms, freq=220Hz, sample=58, buffer_id=03:3A
    db 54,1,132,0,65,124,4,7,114,1,65,4  ; n1117 t=58.118s dur=132ms, freq=370Hz, sample=65, buffer_id=04:41
    db 0,0,100,0,67,125,8,1,136,1,67,8  ; n1118 t=58.428s dur=100ms, freq=392Hz, sample=67, buffer_id=08:43
    db 41,0,111,0,55,76,9,0,196,0,55,8  ; n1119 t=58.428s dur=111ms, freq=196Hz, sample=55, buffer_id=08:37
    db 0,0,100,0,72,124,4,2,11,2,72,4  ; n1120 t=58.469s dur=100ms, freq=523Hz, sample=72, buffer_id=04:48
    db 12,0,100,0,70,124,4,3,184,1,70,4  ; n1121 t=58.469s dur=100ms, freq=440Hz, sample=70, buffer_id=04:46
    db 0,0,100,0,58,126,3,4,6,1,58,3  ; n1122 t=58.481s dur=100ms, freq=262Hz, sample=58, buffer_id=03:3A
    db 70,0,100,0,65,124,4,6,93,1,65,4  ; n1123 t=58.481s dur=100ms, freq=349Hz, sample=65, buffer_id=04:41
    db 0,0,100,0,67,125,8,5,136,1,67,8  ; n1124 t=58.551s dur=100ms, freq=392Hz, sample=67, buffer_id=08:43
    db 12,0,111,0,55,76,9,7,196,0,55,8  ; n1125 t=58.551s dur=111ms, freq=196Hz, sample=55, buffer_id=08:37
    db 29,0,4,2,65,124,4,8,93,1,65,4  ; n1126 t=58.564s dur=516ms, freq=349Hz, sample=65, buffer_id=04:41
    db 12,0,210,1,72,124,4,9,11,2,72,4  ; n1127 t=58.593s dur=466ms, freq=523Hz, sample=72, buffer_id=04:48
    db 0,0,231,1,58,126,3,10,6,1,58,3  ; n1128 t=58.605s dur=487ms, freq=262Hz, sample=58, buffer_id=03:3A
    db 70,0,198,1,70,124,4,11,184,1,70,4  ; n1129 t=58.605s dur=454ms, freq=440Hz, sample=70, buffer_id=04:46
    db 0,0,100,0,67,125,8,12,136,1,67,8  ; n1130 t=58.675s dur=100ms, freq=392Hz, sample=67, buffer_id=08:43
    db 124,0,111,0,55,76,9,13,196,0,55,8  ; n1131 t=58.675s dur=111ms, freq=196Hz, sample=55, buffer_id=08:37
    db 0,0,100,0,67,125,8,0,136,1,67,8  ; n1132 t=58.799s dur=100ms, freq=392Hz, sample=67, buffer_id=08:43
    db 124,0,111,0,55,76,9,1,196,0,55,8  ; n1133 t=58.799s dur=111ms, freq=196Hz, sample=55, buffer_id=08:37
    db 0,0,100,0,67,125,8,2,136,1,67,8  ; n1134 t=58.923s dur=100ms, freq=392Hz, sample=67, buffer_id=08:43
    db 124,0,111,0,55,76,9,3,196,0,55,8  ; n1135 t=58.923s dur=111ms, freq=196Hz, sample=55, buffer_id=08:37
    db 0,0,100,0,70,124,4,4,184,1,70,4  ; n1136 t=59.047s dur=100ms, freq=440Hz, sample=70, buffer_id=04:46
    db 0,0,100,0,67,125,8,6,136,1,67,8  ; n1137 t=59.047s dur=100ms, freq=392Hz, sample=67, buffer_id=08:43
    db 4,0,111,0,55,76,9,5,196,0,55,8  ; n1138 t=59.047s dur=111ms, freq=196Hz, sample=55, buffer_id=08:37
    db 21,0,186,0,65,124,4,7,38,1,65,4  ; n1139 t=59.051s dur=186ms, freq=294Hz, sample=65, buffer_id=04:41
    db 8,0,144,0,87,125,8,12,151,4,87,8  ; n1140 t=59.072s dur=144ms, freq=1175Hz, sample=87, buffer_id=08:57
    db 0,0,140,0,58,126,3,13,220,0,58,3  ; n1141 t=59.080s dur=140ms, freq=220Hz, sample=58, buffer_id=03:3A
    db 120,0,128,0,65,124,4,8,114,1,65,4  ; n1142 t=59.080s dur=128ms, freq=370Hz, sample=65, buffer_id=04:41 [TRUNCATE prev:ch8 @58563.9ms -> 59080.4ms]
    db 99,0,128,0,87,125,8,0,221,4,87,8  ; n1143 t=59.200s dur=128ms, freq=1245Hz, sample=87, buffer_id=08:57
    db 120,0,148,0,87,125,8,1,151,4,87,8  ; n1144 t=59.299s dur=148ms, freq=1175Hz, sample=87, buffer_id=08:57
    db 0,0,100,0,72,124,4,2,11,2,72,4  ; n1145 t=59.419s dur=100ms, freq=523Hz, sample=72, buffer_id=04:48
    db 4,0,111,0,55,76,9,4,196,0,55,8  ; n1146 t=59.419s dur=111ms, freq=196Hz, sample=55, buffer_id=08:37
    db 8,0,100,0,63,126,3,3,55,1,63,3  ; n1147 t=59.423s dur=100ms, freq=311Hz, sample=63, buffer_id=03:3F
    db 8,0,136,0,87,125,8,5,221,4,87,8  ; n1148 t=59.432s dur=136ms, freq=1245Hz, sample=87, buffer_id=08:57
    db 4,0,100,0,75,124,4,6,110,2,75,4  ; n1149 t=59.440s dur=100ms, freq=622Hz, sample=75, buffer_id=04:4B
    db 99,0,100,0,70,124,4,7,159,1,70,4  ; n1150 t=59.444s dur=100ms, freq=415Hz, sample=70, buffer_id=04:46
    db 0,0,37,2,63,126,3,0,55,1,63,3  ; n1151 t=59.543s dur=549ms, freq=311Hz, sample=63, buffer_id=03:3F
    db 0,0,140,0,87,125,8,8,151,4,87,8  ; n1152 t=59.543s dur=140ms, freq=1175Hz, sample=87, buffer_id=08:57
    db 12,0,111,0,55,76,9,9,196,0,55,8  ; n1153 t=59.543s dur=111ms, freq=196Hz, sample=55, buffer_id=08:37
    db 8,0,210,1,72,124,4,10,11,2,72,4  ; n1154 t=59.556s dur=466ms, freq=523Hz, sample=72, buffer_id=04:48
    db 4,0,0,2,70,124,4,12,159,1,70,4  ; n1155 t=59.564s dur=512ms, freq=415Hz, sample=70, buffer_id=04:46
    db 108,0,12,2,75,124,4,11,110,2,75,4  ; n1156 t=59.568s dur=524ms, freq=622Hz, sample=75, buffer_id=04:4B
    db 120,0,132,0,87,125,8,13,221,4,87,8  ; n1157 t=59.675s dur=132ms, freq=1245Hz, sample=87, buffer_id=08:57
    db 120,0,136,0,87,125,8,2,151,4,87,8  ; n1158 t=59.795s dur=136ms, freq=1175Hz, sample=87, buffer_id=08:57
    db 8,0,111,0,55,76,9,1,196,0,55,8  ; n1159 t=59.915s dur=111ms, freq=196Hz, sample=55, buffer_id=08:37
    db 116,0,136,0,87,125,8,3,221,4,87,8  ; n1160 t=59.923s dur=136ms, freq=1245Hz, sample=87, buffer_id=08:57
    db 0,0,136,0,70,124,4,4,238,1,70,4  ; n1161 t=60.039s dur=136ms, freq=494Hz, sample=70, buffer_id=04:46
    db 12,0,111,0,55,76,9,5,196,0,55,8  ; n1162 t=60.039s dur=111ms, freq=196Hz, sample=55, buffer_id=08:37
    db 0,0,124,0,65,124,4,6,136,1,65,4  ; n1163 t=60.051s dur=124ms, freq=392Hz, sample=65, buffer_id=04:41
    db 0,0,124,0,74,124,4,7,75,2,74,4  ; n1164 t=60.051s dur=124ms, freq=587Hz, sample=74, buffer_id=04:4A
    db 12,0,119,0,87,125,8,9,151,4,87,8  ; n1165 t=60.051s dur=119ms, freq=1175Hz, sample=87, buffer_id=08:57
    db 99,0,173,0,62,126,3,8,38,1,62,3  ; n1166 t=60.064s dur=173ms, freq=294Hz, sample=62, buffer_id=03:3E
    db 4,0,111,0,55,76,9,2,196,0,55,8  ; n1167 t=60.163s dur=111ms, freq=196Hz, sample=55, buffer_id=08:37
    db 120,0,136,0,87,125,8,13,221,4,87,8  ; n1168 t=60.167s dur=136ms, freq=1245Hz, sample=87, buffer_id=08:57 [TRUNCATE prev:ch13 @59675.5ms -> 60167.2ms]
    db 12,0,111,0,55,76,9,3,196,0,55,8  ; n1169 t=60.287s dur=111ms, freq=196Hz, sample=55, buffer_id=08:37
    db 0,0,100,0,72,124,4,0,11,2,72,4  ; n1170 t=60.299s dur=100ms, freq=523Hz, sample=72, buffer_id=04:48
    db 0,0,161,0,75,124,4,1,110,2,75,4  ; n1171 t=60.299s dur=161ms, freq=622Hz, sample=75, buffer_id=04:4B
    db 8,0,115,0,87,125,8,10,151,4,87,8  ; n1172 t=60.299s dur=115ms, freq=1175Hz, sample=87, buffer_id=08:57
    db 12,0,100,0,70,124,4,11,159,1,70,4  ; n1173 t=60.308s dur=100ms, freq=415Hz, sample=70, buffer_id=04:46
    db 83,0,144,0,63,126,3,12,55,1,63,3  ; n1174 t=60.320s dur=144ms, freq=311Hz, sample=63, buffer_id=03:3F
    db 8,0,100,0,70,124,4,5,238,1,70,4  ; n1175 t=60.403s dur=100ms, freq=494Hz, sample=70, buffer_id=04:46
    db 0,0,100,0,65,124,4,4,136,1,65,4  ; n1176 t=60.411s dur=100ms, freq=392Hz, sample=65, buffer_id=04:41
    db 0,0,100,0,74,125,5,6,11,2,74,5  ; n1177 t=60.411s dur=100ms, freq=523Hz, sample=74, buffer_id=05:4A
    db 12,0,111,0,55,76,9,7,196,0,55,8  ; n1178 t=60.411s dur=111ms, freq=196Hz, sample=55, buffer_id=08:37
    db 0,0,132,0,62,126,3,9,38,1,62,3  ; n1179 t=60.423s dur=132ms, freq=294Hz, sample=62, buffer_id=03:3E
    db 8,0,128,0,87,125,8,13,221,4,87,8  ; n1180 t=60.423s dur=128ms, freq=1245Hz, sample=87, buffer_id=08:57 [TRUNCATE prev:ch13 @60167.2ms -> 60423.4ms]
    db 0,0,132,0,74,124,4,8,75,2,74,4  ; n1181 t=60.432s dur=132ms, freq=587Hz, sample=74, buffer_id=04:4A [TRUNCATE prev:ch8 @60063.9ms -> 60431.7ms]
    db 4,0,100,0,74,125,5,2,110,2,74,5  ; n1182 t=60.432s dur=100ms, freq=622Hz, sample=74, buffer_id=05:4A [TRUNCATE prev:ch2 @60163.1ms -> 60431.7ms]
    db 91,0,100,0,69,125,5,3,159,1,69,5  ; n1183 t=60.436s dur=100ms, freq=415Hz, sample=69, buffer_id=05:45 [TRUNCATE prev:ch3 @60287.1ms -> 60435.8ms]
    db 0,0,100,0,65,124,4,4,93,1,65,4  ; n1184 t=60.527s dur=100ms, freq=349Hz, sample=65, buffer_id=04:41 [TRUNCATE prev:ch4 @60411.0ms -> 60526.7ms]
    db 8,0,210,1,74,125,5,6,11,2,74,5  ; n1185 t=60.527s dur=466ms, freq=523Hz, sample=74, buffer_id=05:4A [TRUNCATE prev:ch6 @60411.0ms -> 60526.7ms]
    db 0,0,124,0,87,125,8,10,151,4,87,8  ; n1186 t=60.535s dur=124ms, freq=1175Hz, sample=87, buffer_id=08:57 [TRUNCATE prev:ch10 @60299.4ms -> 60535.0ms]
    db 4,0,111,0,55,76,9,7,196,0,55,8  ; n1187 t=60.535s dur=111ms, freq=196Hz, sample=55, buffer_id=08:37 [TRUNCATE prev:ch7 @60411.0ms -> 60535.0ms]
    db 0,0,100,0,70,124,4,11,184,1,70,4  ; n1188 t=60.539s dur=100ms, freq=440Hz, sample=70, buffer_id=04:46 [TRUNCATE prev:ch11 @60307.7ms -> 60539.1ms]
    db 8,0,144,0,72,124,4,0,11,2,72,4  ; n1189 t=60.539s dur=144ms, freq=523Hz, sample=72, buffer_id=04:48 [TRUNCATE prev:ch0 @60299.4ms -> 60539.1ms]
    db 8,0,124,0,58,126,3,1,6,1,58,3  ; n1190 t=60.547s dur=124ms, freq=262Hz, sample=58, buffer_id=03:3A [TRUNCATE prev:ch1 @60299.4ms -> 60547.4ms]
    db 4,0,0,2,69,125,5,3,159,1,69,5  ; n1191 t=60.556s dur=512ms, freq=415Hz, sample=69, buffer_id=05:45 [TRUNCATE prev:ch3 @60435.8ms -> 60555.6ms]
    db 91,0,12,2,74,125,5,2,110,2,74,5  ; n1192 t=60.560s dur=524ms, freq=622Hz, sample=74, buffer_id=05:4A [TRUNCATE prev:ch2 @60431.7ms -> 60559.8ms]
    db 124,0,144,0,87,125,8,13,221,4,87,8  ; n1193 t=60.651s dur=144ms, freq=1245Hz, sample=87, buffer_id=08:57 [TRUNCATE prev:ch13 @60423.4ms -> 60650.7ms]
    db 29,0,136,0,87,125,8,5,151,4,87,8  ; n1194 t=60.775s dur=136ms, freq=1175Hz, sample=87, buffer_id=08:57
    db 87,0,136,1,58,126,3,8,220,0,58,3  ; n1195 t=60.804s dur=392ms, freq=220Hz, sample=58, buffer_id=03:3A
    db 17,0,128,0,87,125,8,0,221,4,87,8  ; n1196 t=60.890s dur=128ms, freq=1245Hz, sample=87, buffer_id=08:57
    db 95,0,111,0,55,76,9,1,196,0,55,8  ; n1197 t=60.907s dur=111ms, freq=196Hz, sample=55, buffer_id=08:37
    db 29,0,128,0,87,125,8,4,151,4,87,8  ; n1198 t=61.002s dur=128ms, freq=1175Hz, sample=87, buffer_id=08:57
    db 0,0,136,0,69,125,5,7,238,1,69,5  ; n1199 t=61.031s dur=136ms, freq=494Hz, sample=69, buffer_id=05:45
    db 12,0,111,0,55,76,9,9,196,0,55,8  ; n1200 t=61.031s dur=111ms, freq=196Hz, sample=55, buffer_id=08:37
    db 0,0,124,0,69,125,5,10,136,1,69,5  ; n1201 t=61.043s dur=124ms, freq=392Hz, sample=69, buffer_id=05:45
    db 70,0,124,0,74,125,5,11,75,2,74,5  ; n1202 t=61.043s dur=124ms, freq=587Hz, sample=74, buffer_id=05:4A
    db 128,0,140,0,87,125,8,12,221,4,87,8  ; n1203 t=61.114s dur=140ms, freq=1245Hz, sample=87, buffer_id=08:57
    db 29,0,132,0,87,125,8,1,151,4,87,8  ; n1204 t=61.242s dur=132ms, freq=1175Hz, sample=87, buffer_id=08:57
    db 21,0,198,0,74,125,5,0,110,2,74,5  ; n1205 t=61.270s dur=198ms, freq=622Hz, sample=74, buffer_id=05:4A
    db 8,0,100,0,74,125,5,3,11,2,74,5  ; n1206 t=61.291s dur=100ms, freq=523Hz, sample=74, buffer_id=05:4A
    db 62,0,136,0,69,125,5,2,159,1,69,5  ; n1207 t=61.299s dur=136ms, freq=415Hz, sample=69, buffer_id=05:45
    db 33,0,144,0,87,125,8,6,221,4,87,8  ; n1208 t=61.361s dur=144ms, freq=1245Hz, sample=87, buffer_id=08:57
    db 8,0,136,0,69,125,5,4,238,1,69,5  ; n1209 t=61.395s dur=136ms, freq=494Hz, sample=69, buffer_id=05:45
    db 0,0,132,0,69,125,5,5,136,1,69,5  ; n1210 t=61.403s dur=132ms, freq=392Hz, sample=69, buffer_id=05:45
    db 21,0,111,0,55,76,9,7,196,0,55,8  ; n1211 t=61.403s dur=111ms, freq=196Hz, sample=55, buffer_id=08:37
    db 62,0,132,0,74,125,5,8,75,2,74,5  ; n1212 t=61.423s dur=132ms, freq=587Hz, sample=74, buffer_id=05:4A
    db 33,0,124,0,87,125,8,9,151,4,87,8  ; n1213 t=61.485s dur=124ms, freq=1175Hz, sample=87, buffer_id=08:57
    db 8,0,100,0,63,125,5,10,93,1,63,5  ; n1214 t=61.519s dur=100ms, freq=349Hz, sample=63, buffer_id=05:3F
    db 4,0,111,0,50,76,9,11,156,0,50,8  ; n1215 t=61.527s dur=111ms, freq=156Hz, sample=50, buffer_id=08:32
    db 0,0,100,0,69,125,5,12,184,1,69,5  ; n1216 t=61.531s dur=100ms, freq=440Hz, sample=69, buffer_id=05:45
    db 74,0,100,0,74,125,5,13,11,2,74,5  ; n1217 t=61.531s dur=100ms, freq=523Hz, sample=74, buffer_id=05:4A
    db 45,0,136,0,87,125,8,3,221,4,87,8  ; n1218 t=61.605s dur=136ms, freq=1245Hz, sample=87, buffer_id=08:57
    db 66,0,111,0,50,76,9,1,156,0,50,8  ; n1219 t=61.651s dur=111ms, freq=156Hz, sample=50, buffer_id=08:32
    db 21,0,136,0,87,125,8,0,151,4,87,8  ; n1220 t=61.717s dur=136ms, freq=1175Hz, sample=87, buffer_id=08:57
    db 17,0,129,6,69,125,5,6,184,1,69,5  ; n1221 t=61.737s dur=1665ms, freq=440Hz, sample=69, buffer_id=05:45
    db 21,0,71,6,63,125,5,2,38,1,63,5  ; n1222 t=61.754s dur=1607ms, freq=294Hz, sample=63, buffer_id=05:3F
    db 70,0,111,0,50,76,9,4,156,0,50,8  ; n1223 t=61.775s dur=111ms, freq=156Hz, sample=50, buffer_id=08:32
    db 54,0,148,0,87,125,8,5,221,4,87,8  ; n1224 t=61.845s dur=148ms, freq=1245Hz, sample=87, buffer_id=08:57
    db 54,0,111,0,50,76,9,7,156,0,50,8  ; n1225 t=61.899s dur=111ms, freq=156Hz, sample=50, buffer_id=08:32
    db 70,0,148,0,87,125,8,8,151,4,87,8  ; n1226 t=61.952s dur=148ms, freq=1175Hz, sample=87, buffer_id=08:57
    db 62,0,111,0,55,76,9,1,196,0,55,8  ; n1227 t=62.023s dur=111ms, freq=196Hz, sample=55, buffer_id=08:37
    db 120,0,152,0,87,125,8,10,221,4,87,8  ; n1228 t=62.085s dur=152ms, freq=1245Hz, sample=87, buffer_id=08:57
    db 132,0,144,0,87,125,8,4,151,4,87,8  ; n1229 t=62.204s dur=144ms, freq=1175Hz, sample=87, buffer_id=08:57
    db 58,0,148,0,87,125,8,1,221,4,87,8  ; n1230 t=62.337s dur=148ms, freq=1245Hz, sample=87, buffer_id=08:57
    db 50,0,111,0,55,76,9,0,196,0,55,8  ; n1231 t=62.395s dur=111ms, freq=196Hz, sample=55, buffer_id=08:37
    db 74,0,148,0,87,125,8,7,151,4,87,8  ; n1232 t=62.444s dur=148ms, freq=1175Hz, sample=87, buffer_id=08:57
    db 45,0,111,0,55,76,9,3,196,0,55,8  ; n1233 t=62.519s dur=111ms, freq=196Hz, sample=55, buffer_id=08:37
    db 99,0,136,0,87,125,8,11,221,4,87,8  ; n1234 t=62.564s dur=136ms, freq=1245Hz, sample=87, buffer_id=08:57
    db 83,0,119,0,87,125,8,12,151,4,87,8  ; n1235 t=62.663s dur=119ms, freq=1175Hz, sample=87, buffer_id=08:57
    db 112,0,115,0,82,125,8,0,23,4,82,8  ; n1236 t=62.746s dur=115ms, freq=1047Hz, sample=82, buffer_id=08:52
    db 120,0,103,0,87,125,8,3,85,4,87,8  ; n1237 t=62.857s dur=103ms, freq=1109Hz, sample=87, buffer_id=08:57
    db 37,0,128,0,87,125,8,13,151,4,87,8  ; n1238 t=62.977s dur=128ms, freq=1175Hz, sample=87, buffer_id=08:57
    db 95,0,111,0,50,76,9,1,156,0,50,8  ; n1239 t=63.014s dur=111ms, freq=156Hz, sample=50, buffer_id=08:32
    db 29,0,100,0,87,125,8,0,221,4,87,8  ; n1240 t=63.109s dur=100ms, freq=1245Hz, sample=87, buffer_id=08:57
    db 95,0,111,0,50,76,9,4,156,0,50,8  ; n1241 t=63.138s dur=111ms, freq=156Hz, sample=50, buffer_id=08:32
    db 17,0,103,0,87,125,8,9,39,5,87,8  ; n1242 t=63.233s dur=103ms, freq=1319Hz, sample=87, buffer_id=08:57 [TRUNCATE prev:ch9 @61485.4ms -> 63233.3ms]
    db 12,0,100,0,75,124,4,3,147,2,75,4  ; n1243 t=63.250s dur=100ms, freq=659Hz, sample=75, buffer_id=04:4B
    db 74,0,111,0,50,76,9,5,156,0,50,8  ; n1244 t=63.262s dur=111ms, freq=156Hz, sample=50, buffer_id=08:32
    db 17,0,100,0,89,125,8,1,117,5,89,8  ; n1245 t=63.337s dur=100ms, freq=1397Hz, sample=89, buffer_id=08:59
    db 33,0,100,0,77,124,4,7,186,2,77,4  ; n1246 t=63.353s dur=100ms, freq=698Hz, sample=77, buffer_id=04:4D
    db 33,0,111,0,50,76,9,8,156,0,50,8  ; n1247 t=63.386s dur=111ms, freq=156Hz, sample=50, buffer_id=08:32
    db 33,0,114,0,89,125,8,0,200,5,89,8  ; n1248 t=63.419s dur=114ms, freq=1480Hz, sample=89, buffer_id=08:59
    db 63,0,115,0,78,124,4,4,228,2,78,4  ; n1249 t=63.452s dur=115ms, freq=740Hz, sample=78, buffer_id=04:4E
    db 14,0,239,1,91,125,8,10,32,6,91,8  ; n1250 t=63.515s dur=495ms, freq=1568Hz, sample=91, buffer_id=08:5B
    db 29,0,80,1,78,124,4,11,16,3,78,4  ; n1251 t=63.529s dur=336ms, freq=784Hz, sample=78, buffer_id=04:4E
    db 5,0,127,6,62,126,3,3,38,1,62,3  ; n1252 t=63.558s dur=1663ms, freq=294Hz, sample=62, buffer_id=03:3E
    db 10,0,27,1,43,76,9,2,98,0,43,8  ; n1253 t=63.563s dur=283ms, freq=98Hz, sample=43, buffer_id=08:2B
    db 50,2,228,6,55,126,3,9,196,0,55,3  ; n1254 t=63.573s dur=1764ms, freq=196Hz, sample=55, buffer_id=03:37
    db 0,0,100,0,31,76,9,0,49,0,31,8  ; n1255 t=64.135s dur=100ms, freq=49Hz, sample=31, buffer_id=08:1F
    db 23,1,100,0,43,76,9,1,98,0,43,8  ; n1256 t=64.135s dur=100ms, freq=98Hz, sample=43, buffer_id=08:2B
    db 0,0,100,0,43,76,9,4,98,0,43,8  ; n1257 t=64.414s dur=100ms, freq=98Hz, sample=43, buffer_id=08:2B
    db 19,0,100,0,31,76,9,2,49,0,31,8  ; n1258 t=64.414s dur=100ms, freq=49Hz, sample=31, buffer_id=08:1F
    db 77,0,100,0,55,125,8,5,196,0,55,8  ; n1259 t=64.433s dur=100ms, freq=196Hz, sample=55, buffer_id=08:37
    db 0,0,100,0,31,76,9,1,49,0,31,8  ; n1260 t=64.510s dur=100ms, freq=49Hz, sample=31, buffer_id=08:1F
    db 14,0,100,0,43,76,9,0,98,0,43,8  ; n1261 t=64.510s dur=100ms, freq=98Hz, sample=43, buffer_id=08:2B
    db 77,0,100,0,55,125,8,6,196,0,55,8  ; n1262 t=64.525s dur=100ms, freq=196Hz, sample=55, buffer_id=08:37
    db 0,0,100,0,43,76,9,7,98,0,43,8  ; n1263 t=64.602s dur=100ms, freq=98Hz, sample=43, buffer_id=08:2B
    db 14,0,100,0,31,76,9,8,49,0,31,8  ; n1264 t=64.602s dur=100ms, freq=49Hz, sample=31, buffer_id=08:1F
    db 91,0,100,0,55,125,8,10,196,0,55,8  ; n1265 t=64.616s dur=100ms, freq=196Hz, sample=55, buffer_id=08:37
    db 5,0,100,0,55,125,8,11,196,0,55,8  ; n1266 t=64.707s dur=100ms, freq=196Hz, sample=55, buffer_id=08:37
    db 0,0,100,0,31,76,9,12,49,0,31,8  ; n1267 t=64.712s dur=100ms, freq=49Hz, sample=31, buffer_id=08:1F
    db 32,1,100,0,43,76,9,13,98,0,43,8  ; n1268 t=64.712s dur=100ms, freq=98Hz, sample=43, buffer_id=08:2B
    db 0,0,100,0,43,76,9,1,98,0,43,8  ; n1269 t=65.001s dur=100ms, freq=98Hz, sample=43, buffer_id=08:2B
    db 14,0,100,0,31,76,9,0,49,0,31,8  ; n1270 t=65.001s dur=100ms, freq=49Hz, sample=31, buffer_id=08:1F
    db 82,0,100,0,55,125,8,2,196,0,55,8  ; n1271 t=65.015s dur=100ms, freq=196Hz, sample=55, buffer_id=08:37
    db 0,0,100,0,31,76,9,4,49,0,31,8  ; n1272 t=65.097s dur=100ms, freq=49Hz, sample=31, buffer_id=08:1F
    db 14,0,100,0,43,76,9,5,98,0,43,8  ; n1273 t=65.097s dur=100ms, freq=98Hz, sample=43, buffer_id=08:2B
    db 82,0,100,0,55,125,8,7,196,0,55,8  ; n1274 t=65.111s dur=100ms, freq=196Hz, sample=55, buffer_id=08:37
    db 0,0,100,0,43,76,9,6,98,0,43,8  ; n1275 t=65.193s dur=100ms, freq=98Hz, sample=43, buffer_id=08:2B
    db 5,0,100,0,31,76,9,10,49,0,31,8  ; n1276 t=65.193s dur=100ms, freq=49Hz, sample=31, buffer_id=08:1F
    db 87,0,100,0,55,125,8,8,196,0,55,8  ; n1277 t=65.198s dur=100ms, freq=196Hz, sample=55, buffer_id=08:37
    db 0,0,100,0,27,76,9,11,39,0,27,8  ; n1278 t=65.284s dur=100ms, freq=39Hz, sample=27, buffer_id=08:1B
    db 10,0,100,0,38,76,9,12,78,0,38,8  ; n1279 t=65.284s dur=100ms, freq=78Hz, sample=38, buffer_id=08:26
    db 0,0,100,0,63,125,8,13,55,1,63,8  ; n1280 t=65.294s dur=100ms, freq=311Hz, sample=63, buffer_id=08:3F
    db 82,0,100,0,58,76,9,3,233,0,58,8  ; n1281 t=65.294s dur=100ms, freq=233Hz, sample=58, buffer_id=08:3A [TRUNCATE prev:ch3 @63558.3ms -> 65293.8ms]
    db 0,0,100,0,27,76,9,0,39,0,27,8  ; n1282 t=65.376s dur=100ms, freq=39Hz, sample=27, buffer_id=08:1B
    db 10,0,100,0,38,76,9,1,78,0,38,8  ; n1283 t=65.376s dur=100ms, freq=78Hz, sample=38, buffer_id=08:26
    db 5,0,100,0,63,125,8,2,55,1,63,8  ; n1284 t=65.385s dur=100ms, freq=311Hz, sample=63, buffer_id=08:3F
    db 77,0,100,0,58,76,9,9,233,0,58,8  ; n1285 t=65.390s dur=100ms, freq=233Hz, sample=58, buffer_id=08:3A [TRUNCATE prev:ch9 @63572.7ms -> 65390.0ms]
    db 0,0,100,0,27,76,9,4,39,0,27,8  ; n1286 t=65.467s dur=100ms, freq=39Hz, sample=27, buffer_id=08:1B
    db 14,0,100,0,38,76,9,5,78,0,38,8  ; n1287 t=65.467s dur=100ms, freq=78Hz, sample=38, buffer_id=08:26
    db 10,0,100,0,63,125,8,7,55,1,63,8  ; n1288 t=65.481s dur=100ms, freq=311Hz, sample=63, buffer_id=08:3F
    db 77,0,100,0,58,76,9,3,233,0,58,8  ; n1289 t=65.491s dur=100ms, freq=233Hz, sample=58, buffer_id=08:3A [TRUNCATE prev:ch3 @65293.8ms -> 65491.0ms]
    db 0,0,100,0,27,76,9,6,39,0,27,8  ; n1290 t=65.568s dur=100ms, freq=39Hz, sample=27, buffer_id=08:1B
    db 10,0,100,0,38,76,9,8,78,0,38,8  ; n1291 t=65.568s dur=100ms, freq=78Hz, sample=38, buffer_id=08:26
    db 5,0,100,0,63,125,8,10,55,1,63,8  ; n1292 t=65.578s dur=100ms, freq=311Hz, sample=63, buffer_id=08:3F
    db 28,1,100,0,58,76,9,9,233,0,58,8  ; n1293 t=65.582s dur=100ms, freq=233Hz, sample=58, buffer_id=08:3A [TRUNCATE prev:ch9 @65390.0ms -> 65582.3ms]
    db 5,0,100,0,55,125,8,0,196,0,55,8  ; n1294 t=65.866s dur=100ms, freq=196Hz, sample=55, buffer_id=08:37
    db 0,0,100,0,55,125,5,1,196,0,55,5  ; n1295 t=65.871s dur=100ms, freq=196Hz, sample=55, buffer_id=05:37
    db 0,0,100,0,31,76,9,2,49,0,31,8  ; n1296 t=65.871s dur=100ms, freq=49Hz, sample=31, buffer_id=08:1F
    db 65,2,100,0,43,76,9,3,98,0,43,8  ; n1297 t=65.871s dur=100ms, freq=98Hz, sample=43, buffer_id=08:2B
    db 0,0,100,0,55,125,5,0,196,0,55,5  ; n1298 t=66.448s dur=100ms, freq=196Hz, sample=55, buffer_id=05:37
    db 0,0,100,0,55,125,8,1,196,0,55,8  ; n1299 t=66.448s dur=100ms, freq=196Hz, sample=55, buffer_id=08:37
    db 0,0,100,0,43,76,9,2,98,0,43,8  ; n1300 t=66.448s dur=100ms, freq=98Hz, sample=43, buffer_id=08:2B
    db 32,1,100,0,31,76,9,3,49,0,31,8  ; n1301 t=66.448s dur=100ms, freq=49Hz, sample=31, buffer_id=08:1F
    db 0,0,100,0,55,125,5,4,196,0,55,5  ; n1302 t=66.736s dur=100ms, freq=196Hz, sample=55, buffer_id=05:37
    db 0,0,100,0,31,76,9,5,49,0,31,8  ; n1303 t=66.736s dur=100ms, freq=49Hz, sample=31, buffer_id=08:1F
    db 5,0,100,0,43,76,9,6,98,0,43,8  ; n1304 t=66.736s dur=100ms, freq=98Hz, sample=43, buffer_id=08:2B
    db 91,0,100,0,55,125,8,7,196,0,55,8  ; n1305 t=66.741s dur=100ms, freq=196Hz, sample=55, buffer_id=08:37
    db 0,0,100,0,55,125,5,1,196,0,55,5  ; n1306 t=66.832s dur=100ms, freq=196Hz, sample=55, buffer_id=05:37
    db 0,0,100,0,55,125,8,0,196,0,55,8  ; n1307 t=66.832s dur=100ms, freq=196Hz, sample=55, buffer_id=08:37
    db 0,0,100,0,43,76,9,3,98,0,43,8  ; n1308 t=66.832s dur=100ms, freq=98Hz, sample=43, buffer_id=08:2B
    db 96,0,100,0,31,76,9,2,49,0,31,8  ; n1309 t=66.832s dur=100ms, freq=49Hz, sample=31, buffer_id=08:1F
    db 0,0,100,0,55,125,5,8,196,0,55,5  ; n1310 t=66.928s dur=100ms, freq=196Hz, sample=55, buffer_id=05:37
    db 0,0,100,0,55,125,8,9,196,0,55,8  ; n1311 t=66.928s dur=100ms, freq=196Hz, sample=55, buffer_id=08:37
    db 0,0,100,0,31,76,9,10,49,0,31,8  ; n1312 t=66.928s dur=100ms, freq=49Hz, sample=31, buffer_id=08:1F
    db 96,0,100,0,43,76,9,11,98,0,43,8  ; n1313 t=66.928s dur=100ms, freq=98Hz, sample=43, buffer_id=08:2B
    db 0,0,100,0,55,125,5,12,196,0,55,5  ; n1314 t=67.025s dur=100ms, freq=196Hz, sample=55, buffer_id=05:37
    db 0,0,100,0,55,125,8,13,196,0,55,8  ; n1315 t=67.025s dur=100ms, freq=196Hz, sample=55, buffer_id=08:37
    db 0,0,100,0,43,76,9,6,98,0,43,8  ; n1316 t=67.025s dur=100ms, freq=98Hz, sample=43, buffer_id=08:2B [TRUNCATE prev:ch6 @66736.2ms -> 67024.6ms]
    db 37,1,100,0,31,76,9,5,49,0,31,8  ; n1317 t=67.025s dur=100ms, freq=49Hz, sample=31, buffer_id=08:1F [TRUNCATE prev:ch5 @66736.2ms -> 67024.6ms]
    db 14,0,100,0,55,125,8,1,196,0,55,8  ; n1318 t=67.318s dur=100ms, freq=196Hz, sample=55, buffer_id=08:37
    db 0,0,100,0,55,125,5,0,196,0,55,5  ; n1319 t=67.332s dur=100ms, freq=196Hz, sample=55, buffer_id=05:37
    db 0,0,100,0,31,76,9,3,49,0,31,8  ; n1320 t=67.332s dur=100ms, freq=49Hz, sample=31, buffer_id=08:1F
    db 82,0,100,0,43,76,9,2,98,0,43,8  ; n1321 t=67.332s dur=100ms, freq=98Hz, sample=43, buffer_id=08:2B
    db 14,0,100,0,55,125,8,4,196,0,55,8  ; n1322 t=67.414s dur=100ms, freq=196Hz, sample=55, buffer_id=08:37
    db 0,0,100,0,55,125,5,5,196,0,55,5  ; n1323 t=67.428s dur=100ms, freq=196Hz, sample=55, buffer_id=05:37
    db 0,0,100,0,43,76,9,7,98,0,43,8  ; n1324 t=67.428s dur=100ms, freq=98Hz, sample=43, buffer_id=08:2B
    db 82,0,100,0,31,76,9,6,49,0,31,8  ; n1325 t=67.428s dur=100ms, freq=49Hz, sample=31, buffer_id=08:1F
    db 5,0,100,0,55,125,8,8,196,0,55,8  ; n1326 t=67.510s dur=100ms, freq=196Hz, sample=55, buffer_id=08:37
    db 0,0,100,0,55,125,5,9,196,0,55,5  ; n1327 t=67.515s dur=100ms, freq=196Hz, sample=55, buffer_id=05:37
    db 0,0,100,0,31,76,9,11,49,0,31,8  ; n1328 t=67.515s dur=100ms, freq=49Hz, sample=31, buffer_id=08:1F
    db 87,0,100,0,43,76,9,10,98,0,43,8  ; n1329 t=67.515s dur=100ms, freq=98Hz, sample=43, buffer_id=08:2B
    db 0,0,100,0,63,125,8,12,55,1,63,8  ; n1330 t=67.602s dur=100ms, freq=311Hz, sample=63, buffer_id=08:3F
    db 10,0,100,0,58,76,9,13,233,0,58,8  ; n1331 t=67.602s dur=100ms, freq=233Hz, sample=58, buffer_id=08:3A
    db 0,0,100,0,51,125,5,1,156,0,51,5  ; n1332 t=67.611s dur=100ms, freq=156Hz, sample=51, buffer_id=05:33 [TRUNCATE prev:ch1 @67317.9ms -> 67611.2ms]
    db 0,0,100,0,27,76,9,0,39,0,27,8  ; n1333 t=67.611s dur=100ms, freq=39Hz, sample=27, buffer_id=08:1B [TRUNCATE prev:ch0 @67332.3ms -> 67611.2ms]
    db 87,0,100,0,38,76,9,2,78,0,38,8  ; n1334 t=67.611s dur=100ms, freq=78Hz, sample=38, buffer_id=08:26 [TRUNCATE prev:ch2 @67332.3ms -> 67611.2ms]
    db 0,0,100,0,51,125,5,3,156,0,51,5  ; n1335 t=67.698s dur=100ms, freq=156Hz, sample=51, buffer_id=05:33
    db 0,0,100,0,63,125,8,4,55,1,63,8  ; n1336 t=67.698s dur=100ms, freq=311Hz, sample=63, buffer_id=08:3F [TRUNCATE prev:ch4 @67414.0ms -> 67697.7ms]
    db 0,0,100,0,58,76,9,5,233,0,58,8  ; n1337 t=67.698s dur=100ms, freq=233Hz, sample=58, buffer_id=08:3A [TRUNCATE prev:ch5 @67428.5ms -> 67697.7ms]
    db 0,0,100,0,27,76,9,6,39,0,27,8  ; n1338 t=67.698s dur=100ms, freq=39Hz, sample=27, buffer_id=08:1B [TRUNCATE prev:ch6 @67428.5ms -> 67697.7ms]
    db 91,0,100,0,38,76,9,7,78,0,38,8  ; n1339 t=67.698s dur=100ms, freq=78Hz, sample=38, buffer_id=08:26 [TRUNCATE prev:ch7 @67428.5ms -> 67697.7ms]
    db 0,0,100,0,51,125,5,1,156,0,51,5  ; n1340 t=67.789s dur=100ms, freq=156Hz, sample=51, buffer_id=05:33 [TRUNCATE prev:ch1 @67611.2ms -> 67789.0ms]
    db 0,0,100,0,63,125,8,12,55,1,63,8  ; n1341 t=67.789s dur=100ms, freq=311Hz, sample=63, buffer_id=08:3F [TRUNCATE prev:ch12 @67601.5ms -> 67789.0ms]
    db 0,0,100,0,38,76,9,2,78,0,38,8  ; n1342 t=67.789s dur=100ms, freq=78Hz, sample=38, buffer_id=08:26 [TRUNCATE prev:ch2 @67611.2ms -> 67789.0ms]
    db 5,0,100,0,27,76,9,0,39,0,27,8  ; n1343 t=67.789s dur=100ms, freq=39Hz, sample=27, buffer_id=08:1B [TRUNCATE prev:ch0 @67611.2ms -> 67789.0ms]
    db 91,0,100,0,58,76,9,13,233,0,58,8  ; n1344 t=67.794s dur=100ms, freq=233Hz, sample=58, buffer_id=08:3A [TRUNCATE prev:ch13 @67601.5ms -> 67793.8ms]
    db 0,0,100,0,51,125,5,8,156,0,51,5  ; n1345 t=67.885s dur=100ms, freq=156Hz, sample=51, buffer_id=05:33
    db 0,0,100,0,27,76,9,9,39,0,27,8  ; n1346 t=67.885s dur=100ms, freq=39Hz, sample=27, buffer_id=08:1B
    db 0,0,100,0,38,76,9,10,78,0,38,8  ; n1347 t=67.885s dur=100ms, freq=78Hz, sample=38, buffer_id=08:26
    db 5,0,100,0,58,76,9,11,233,0,58,8  ; n1348 t=67.885s dur=100ms, freq=233Hz, sample=58, buffer_id=08:3A
    db 245,0,100,0,63,125,8,4,55,1,63,8  ; n1349 t=67.890s dur=100ms, freq=311Hz, sample=63, buffer_id=08:3F [TRUNCATE prev:ch4 @67697.7ms -> 67890.0ms]
    db 43,0,176,1,65,124,4,0,136,1,65,4  ; n1350 t=68.135s dur=432ms, freq=392Hz, sample=65, buffer_id=04:41
    db 10,0,100,0,55,125,8,1,196,0,55,8  ; n1351 t=68.178s dur=100ms, freq=196Hz, sample=55, buffer_id=08:37
    db 50,2,66,1,69,125,5,2,136,1,69,5  ; n1352 t=68.188s dur=322ms, freq=392Hz, sample=69, buffer_id=05:45
    db 0,0,95,1,69,125,5,1,136,1,69,5  ; n1353 t=68.751s dur=351ms, freq=392Hz, sample=69, buffer_id=05:45
    db 5,0,100,0,55,125,8,2,196,0,55,8  ; n1354 t=68.751s dur=100ms, freq=196Hz, sample=55, buffer_id=08:37
    db 0,0,100,0,55,125,5,3,196,0,55,5  ; n1355 t=68.755s dur=100ms, freq=196Hz, sample=55, buffer_id=05:37
    db 0,0,100,0,43,76,9,4,98,0,43,8  ; n1356 t=68.755s dur=100ms, freq=98Hz, sample=43, buffer_id=08:2B
    db 19,0,100,0,31,76,9,5,49,0,31,8  ; n1357 t=68.755s dur=100ms, freq=49Hz, sample=31, buffer_id=08:1F
    db 23,1,133,1,65,124,4,6,136,1,65,4  ; n1358 t=68.775s dur=389ms, freq=392Hz, sample=65, buffer_id=04:41
    db 0,0,100,0,55,125,5,0,196,0,55,5  ; n1359 t=69.053s dur=100ms, freq=196Hz, sample=55, buffer_id=05:37
    db 0,0,100,0,31,76,9,2,49,0,31,8  ; n1360 t=69.053s dur=100ms, freq=49Hz, sample=31, buffer_id=08:1F
    db 14,0,100,0,43,76,9,7,98,0,43,8  ; n1361 t=69.053s dur=100ms, freq=98Hz, sample=43, buffer_id=08:2B
    db 82,0,100,0,55,125,8,3,196,0,55,8  ; n1362 t=69.068s dur=100ms, freq=196Hz, sample=55, buffer_id=08:37
    db 0,0,100,0,55,125,5,4,196,0,55,5  ; n1363 t=69.150s dur=100ms, freq=196Hz, sample=55, buffer_id=05:37
    db 0,0,100,0,43,76,9,5,98,0,43,8  ; n1364 t=69.150s dur=100ms, freq=98Hz, sample=43, buffer_id=08:2B
    db 10,0,100,0,31,76,9,8,49,0,31,8  ; n1365 t=69.150s dur=100ms, freq=49Hz, sample=31, buffer_id=08:1F
    db 82,0,100,0,55,125,8,9,196,0,55,8  ; n1366 t=69.159s dur=100ms, freq=196Hz, sample=55, buffer_id=08:37
    db 0,0,100,0,55,125,5,10,196,0,55,5  ; n1367 t=69.241s dur=100ms, freq=196Hz, sample=55, buffer_id=05:37
    db 0,0,100,0,31,76,9,11,49,0,31,8  ; n1368 t=69.241s dur=100ms, freq=49Hz, sample=31, buffer_id=08:1F
    db 10,0,100,0,43,76,9,12,98,0,43,8  ; n1369 t=69.241s dur=100ms, freq=98Hz, sample=43, buffer_id=08:2B
    db 77,0,100,0,55,125,8,13,196,0,55,8  ; n1370 t=69.251s dur=100ms, freq=196Hz, sample=55, buffer_id=08:37
    db 5,0,100,0,55,125,8,1,196,0,55,8  ; n1371 t=69.328s dur=100ms, freq=196Hz, sample=55, buffer_id=08:37
    db 0,0,100,0,55,125,5,0,196,0,55,5  ; n1372 t=69.332s dur=100ms, freq=196Hz, sample=55, buffer_id=05:37 [TRUNCATE prev:ch0 @69053.5ms -> 69332.3ms]
    db 0,0,100,0,43,76,9,7,98,0,43,8  ; n1373 t=69.332s dur=100ms, freq=98Hz, sample=43, buffer_id=08:2B [TRUNCATE prev:ch7 @69053.5ms -> 69332.3ms]
    db 24,0,100,0,31,76,9,2,49,0,31,8  ; n1374 t=69.332s dur=100ms, freq=49Hz, sample=31, buffer_id=08:1F [TRUNCATE prev:ch2 @69053.5ms -> 69332.3ms]
    db 19,0,99,1,69,125,5,6,136,1,69,5  ; n1375 t=69.356s dur=355ms, freq=392Hz, sample=69, buffer_id=05:45 [TRUNCATE prev:ch6 @68774.6ms -> 69356.3ms]
    db 245,0,90,1,65,124,4,3,136,1,65,4  ; n1376 t=69.376s dur=346ms, freq=392Hz, sample=65, buffer_id=04:41
    db 0,0,100,0,55,125,5,5,196,0,55,5  ; n1377 t=69.621s dur=100ms, freq=196Hz, sample=55, buffer_id=05:37
    db 0,0,100,0,31,76,9,4,49,0,31,8  ; n1378 t=69.621s dur=100ms, freq=49Hz, sample=31, buffer_id=08:1F
    db 10,0,100,0,43,76,9,8,98,0,43,8  ; n1379 t=69.621s dur=100ms, freq=98Hz, sample=43, buffer_id=08:2B
    db 87,0,100,0,55,125,8,10,196,0,55,8  ; n1380 t=69.630s dur=100ms, freq=196Hz, sample=55, buffer_id=08:37
    db 0,0,100,0,55,125,5,1,196,0,55,5  ; n1381 t=69.717s dur=100ms, freq=196Hz, sample=55, buffer_id=05:37
    db 0,0,100,0,43,76,9,0,98,0,43,8  ; n1382 t=69.717s dur=100ms, freq=98Hz, sample=43, buffer_id=08:2B
    db 5,0,100,0,31,76,9,7,49,0,31,8  ; n1383 t=69.717s dur=100ms, freq=49Hz, sample=31, buffer_id=08:1F
    db 87,0,100,0,55,125,8,2,196,0,55,8  ; n1384 t=69.722s dur=100ms, freq=196Hz, sample=55, buffer_id=08:37
    db 0,0,100,0,55,125,5,9,196,0,55,5  ; n1385 t=69.808s dur=100ms, freq=196Hz, sample=55, buffer_id=05:37
    db 0,0,100,0,31,76,9,12,49,0,31,8  ; n1386 t=69.808s dur=100ms, freq=49Hz, sample=31, buffer_id=08:1F
    db 10,0,100,0,43,76,9,11,98,0,43,8  ; n1387 t=69.808s dur=100ms, freq=98Hz, sample=43, buffer_id=08:2B
    db 87,0,100,0,55,125,8,13,196,0,55,8  ; n1388 t=69.818s dur=100ms, freq=196Hz, sample=55, buffer_id=08:37 [TRUNCATE prev:ch13 @69250.6ms -> 69817.9ms]
    db 5,0,100,0,63,125,8,6,55,1,63,8  ; n1389 t=69.904s dur=100ms, freq=311Hz, sample=63, buffer_id=08:3F [TRUNCATE prev:ch6 @69356.3ms -> 69904.4ms]
    db 0,0,37,1,65,124,4,3,55,1,65,4  ; n1390 t=69.909s dur=293ms, freq=311Hz, sample=65, buffer_id=04:41 [TRUNCATE prev:ch3 @69375.6ms -> 69909.2ms]
    db 0,0,100,0,51,125,5,4,156,0,51,5  ; n1391 t=69.909s dur=100ms, freq=156Hz, sample=51, buffer_id=05:33 [TRUNCATE prev:ch4 @69620.8ms -> 69909.2ms]
    db 0,0,100,0,55,125,8,10,196,0,55,8  ; n1392 t=69.909s dur=100ms, freq=196Hz, sample=55, buffer_id=08:37 [TRUNCATE prev:ch10 @69630.4ms -> 69909.2ms]
    db 0,0,100,0,27,76,9,5,39,0,27,8  ; n1393 t=69.909s dur=100ms, freq=39Hz, sample=27, buffer_id=08:1B [TRUNCATE prev:ch5 @69620.8ms -> 69909.2ms]
    db 10,0,100,0,38,76,9,8,78,0,38,8  ; n1394 t=69.909s dur=100ms, freq=78Hz, sample=38, buffer_id=08:26 [TRUNCATE prev:ch8 @69620.8ms -> 69909.2ms]
    db 77,0,22,1,63,125,5,0,55,1,63,5  ; n1395 t=69.919s dur=278ms, freq=311Hz, sample=63, buffer_id=05:3F [TRUNCATE prev:ch0 @69716.9ms -> 69918.8ms]
    db 0,0,100,0,51,125,5,1,156,0,51,5  ; n1396 t=69.996s dur=100ms, freq=156Hz, sample=51, buffer_id=05:33 [TRUNCATE prev:ch1 @69716.9ms -> 69995.8ms]
    db 0,0,100,0,38,76,9,7,78,0,38,8  ; n1397 t=69.996s dur=100ms, freq=78Hz, sample=38, buffer_id=08:26 [TRUNCATE prev:ch7 @69716.9ms -> 69995.8ms]
    db 5,0,100,0,27,76,9,2,39,0,27,8  ; n1398 t=69.996s dur=100ms, freq=39Hz, sample=27, buffer_id=08:1B [TRUNCATE prev:ch2 @69721.7ms -> 69995.8ms]
    db 5,0,100,0,55,125,8,13,196,0,55,8  ; n1399 t=70.001s dur=100ms, freq=196Hz, sample=55, buffer_id=08:37 [TRUNCATE prev:ch13 @69817.9ms -> 70000.6ms]
    db 82,0,100,0,63,125,8,6,55,1,63,8  ; n1400 t=70.005s dur=100ms, freq=311Hz, sample=63, buffer_id=08:3F [TRUNCATE prev:ch6 @69904.4ms -> 70005.4ms]
    db 5,0,100,0,55,125,8,10,196,0,55,8  ; n1401 t=70.087s dur=100ms, freq=196Hz, sample=55, buffer_id=08:37 [TRUNCATE prev:ch10 @69909.2ms -> 70087.1ms]
    db 0,0,100,0,51,125,5,4,156,0,51,5  ; n1402 t=70.092s dur=100ms, freq=156Hz, sample=51, buffer_id=05:33 [TRUNCATE prev:ch4 @69909.2ms -> 70091.9ms]
    db 0,0,100,0,27,76,9,5,39,0,27,8  ; n1403 t=70.092s dur=100ms, freq=39Hz, sample=27, buffer_id=08:1B [TRUNCATE prev:ch5 @69909.2ms -> 70091.9ms]
    db 10,0,100,0,38,76,9,8,78,0,38,8  ; n1404 t=70.092s dur=100ms, freq=78Hz, sample=38, buffer_id=08:26 [TRUNCATE prev:ch8 @69909.2ms -> 70091.9ms]
    db 87,0,100,0,63,125,8,9,55,1,63,8  ; n1405 t=70.102s dur=100ms, freq=311Hz, sample=63, buffer_id=08:3F [TRUNCATE prev:ch9 @69808.3ms -> 70101.5ms]
    db 5,0,100,0,55,125,8,11,196,0,55,8  ; n1406 t=70.188s dur=100ms, freq=196Hz, sample=55, buffer_id=08:37
    db 0,0,100,0,51,125,5,12,156,0,51,5  ; n1407 t=70.193s dur=100ms, freq=156Hz, sample=51, buffer_id=05:33
    db 0,0,100,0,63,125,8,6,55,1,63,8  ; n1408 t=70.193s dur=100ms, freq=311Hz, sample=63, buffer_id=08:3F [TRUNCATE prev:ch6 @70005.4ms -> 70192.9ms]
    db 0,0,100,0,27,76,9,2,39,0,27,8  ; n1409 t=70.193s dur=100ms, freq=39Hz, sample=27, buffer_id=08:1B [TRUNCATE prev:ch2 @69995.8ms -> 70192.9ms]
    db 130,0,100,0,38,76,9,7,78,0,38,8  ; n1410 t=70.193s dur=100ms, freq=78Hz, sample=38, buffer_id=08:26 [TRUNCATE prev:ch7 @69995.8ms -> 70192.9ms]
    db 19,0,100,0,70,124,4,1,210,1,70,4  ; n1411 t=70.323s dur=100ms, freq=466Hz, sample=70, buffer_id=04:46
    db 139,0,100,0,69,125,5,13,210,1,69,5  ; n1412 t=70.342s dur=100ms, freq=466Hz, sample=69, buffer_id=05:45
    db 10,0,205,1,65,124,4,0,136,1,65,4  ; n1413 t=70.481s dur=461ms, freq=392Hz, sample=65, buffer_id=04:41
    db 5,0,147,1,69,125,5,3,136,1,69,5  ; n1414 t=70.491s dur=403ms, freq=392Hz, sample=69, buffer_id=05:45
    db 0,0,100,0,55,125,5,2,196,0,55,5  ; n1415 t=70.496s dur=100ms, freq=196Hz, sample=55, buffer_id=05:37
    db 0,0,100,0,43,76,9,4,98,0,43,8  ; n1416 t=70.496s dur=100ms, freq=98Hz, sample=43, buffer_id=08:2B
    db 10,0,100,0,31,76,9,5,49,0,31,8  ; n1417 t=70.496s dur=100ms, freq=49Hz, sample=31, buffer_id=08:1F
    db 41,2,100,0,55,125,8,6,196,0,55,8  ; n1418 t=70.505s dur=100ms, freq=196Hz, sample=55, buffer_id=08:37
    db 0,0,100,0,55,125,5,1,196,0,55,5  ; n1419 t=71.058s dur=100ms, freq=196Hz, sample=55, buffer_id=05:37
    db 0,0,100,0,31,76,9,2,49,0,31,8  ; n1420 t=71.058s dur=100ms, freq=49Hz, sample=31, buffer_id=08:1F
    db 5,0,100,0,43,76,9,5,98,0,43,8  ; n1421 t=71.058s dur=100ms, freq=98Hz, sample=43, buffer_id=08:2B
    db 5,0,22,1,63,125,5,4,55,1,63,5  ; n1422 t=71.063s dur=278ms, freq=311Hz, sample=63, buffer_id=05:3F
    db 5,0,250,0,65,124,4,6,55,1,65,4  ; n1423 t=71.068s dur=250ms, freq=311Hz, sample=65, buffer_id=04:41
    db 18,1,100,0,55,125,8,7,196,0,55,8  ; n1424 t=71.073s dur=100ms, freq=196Hz, sample=55, buffer_id=08:37
    db 0,0,100,0,55,125,5,0,196,0,55,5  ; n1425 t=71.347s dur=100ms, freq=196Hz, sample=55, buffer_id=05:37
    db 0,0,100,0,43,76,9,3,98,0,43,8  ; n1426 t=71.347s dur=100ms, freq=98Hz, sample=43, buffer_id=08:2B
    db 24,0,100,0,31,76,9,8,49,0,31,8  ; n1427 t=71.347s dur=100ms, freq=49Hz, sample=31, buffer_id=08:1F
    db 72,0,100,0,55,125,8,1,196,0,55,8  ; n1428 t=71.371s dur=100ms, freq=196Hz, sample=55, buffer_id=08:37
    db 0,0,100,0,55,125,5,2,196,0,55,5  ; n1429 t=71.443s dur=100ms, freq=196Hz, sample=55, buffer_id=05:37
    db 0,0,100,0,31,76,9,5,49,0,31,8  ; n1430 t=71.443s dur=100ms, freq=49Hz, sample=31, buffer_id=08:1F
    db 10,0,100,0,43,76,9,7,98,0,43,8  ; n1431 t=71.443s dur=100ms, freq=98Hz, sample=43, buffer_id=08:2B
    db 58,0,100,0,55,125,8,9,196,0,55,8  ; n1432 t=71.453s dur=100ms, freq=196Hz, sample=55, buffer_id=08:37
    db 0,0,100,0,70,124,4,10,210,1,70,4  ; n1433 t=71.510s dur=100ms, freq=466Hz, sample=70, buffer_id=04:46
    db 29,0,100,0,69,125,5,11,210,1,69,5  ; n1434 t=71.510s dur=100ms, freq=466Hz, sample=69, buffer_id=05:45
    db 0,0,100,0,55,125,5,6,196,0,55,5  ; n1435 t=71.539s dur=100ms, freq=196Hz, sample=55, buffer_id=05:37
    db 0,0,100,0,43,76,9,12,98,0,43,8  ; n1436 t=71.539s dur=100ms, freq=98Hz, sample=43, buffer_id=08:2B
    db 10,0,100,0,31,76,9,13,49,0,31,8  ; n1437 t=71.539s dur=100ms, freq=49Hz, sample=31, buffer_id=08:1F
    db 72,0,100,0,55,125,8,4,196,0,55,8  ; n1438 t=71.549s dur=100ms, freq=196Hz, sample=55, buffer_id=08:37
    db 14,0,100,0,55,125,8,1,196,0,55,8  ; n1439 t=71.621s dur=100ms, freq=196Hz, sample=55, buffer_id=08:37 [TRUNCATE prev:ch1 @71370.8ms -> 71620.8ms]
    db 0,0,100,0,55,125,5,0,196,0,55,5  ; n1440 t=71.635s dur=100ms, freq=196Hz, sample=55, buffer_id=05:37 [TRUNCATE prev:ch0 @71346.7ms -> 71635.2ms]
    db 0,0,100,0,31,76,9,8,49,0,31,8  ; n1441 t=71.635s dur=100ms, freq=49Hz, sample=31, buffer_id=08:1F [TRUNCATE prev:ch8 @71346.7ms -> 71635.2ms]
    db 10,0,100,0,43,76,9,3,98,0,43,8  ; n1442 t=71.635s dur=100ms, freq=98Hz, sample=43, buffer_id=08:2B [TRUNCATE prev:ch3 @71346.7ms -> 71635.2ms]
    db 14,0,218,2,69,125,5,11,136,1,69,5  ; n1443 t=71.645s dur=730ms, freq=392Hz, sample=69, buffer_id=05:45 [TRUNCATE prev:ch11 @71510.2ms -> 71644.8ms]
    db 255,0,242,2,65,124,4,2,136,1,65,4  ; n1444 t=71.659s dur=754ms, freq=392Hz, sample=65, buffer_id=04:41 [TRUNCATE prev:ch2 @71442.9ms -> 71659.2ms]
    db 0,0,100,0,55,125,5,4,196,0,55,5  ; n1445 t=71.914s dur=100ms, freq=196Hz, sample=55, buffer_id=05:37
    db 0,0,100,0,43,76,9,5,98,0,43,8  ; n1446 t=71.914s dur=100ms, freq=98Hz, sample=43, buffer_id=08:2B
    db 29,0,100,0,31,76,9,6,49,0,31,8  ; n1447 t=71.914s dur=100ms, freq=49Hz, sample=31, buffer_id=08:1F
    db 67,0,100,0,55,125,8,0,196,0,55,8  ; n1448 t=71.943s dur=100ms, freq=196Hz, sample=55, buffer_id=08:37
    db 0,0,100,0,55,125,5,1,196,0,55,5  ; n1449 t=72.010s dur=100ms, freq=196Hz, sample=55, buffer_id=05:37
    db 0,0,100,0,31,76,9,3,49,0,31,8  ; n1450 t=72.010s dur=100ms, freq=49Hz, sample=31, buffer_id=08:1F
    db 24,0,100,0,43,76,9,8,98,0,43,8  ; n1451 t=72.010s dur=100ms, freq=98Hz, sample=43, buffer_id=08:2B
    db 82,0,100,0,55,125,8,7,196,0,55,8  ; n1452 t=72.034s dur=100ms, freq=196Hz, sample=55, buffer_id=08:37
    db 0,0,100,0,55,125,5,9,196,0,55,5  ; n1453 t=72.116s dur=100ms, freq=196Hz, sample=55, buffer_id=05:37
    db 0,0,100,0,43,76,9,10,98,0,43,8  ; n1454 t=72.116s dur=100ms, freq=98Hz, sample=43, buffer_id=08:2B
    db 5,0,100,0,31,76,9,12,49,0,31,8  ; n1455 t=72.116s dur=100ms, freq=49Hz, sample=31, buffer_id=08:1F
    db 82,0,100,0,55,125,8,13,196,0,55,8  ; n1456 t=72.121s dur=100ms, freq=196Hz, sample=55, buffer_id=08:37
    db 5,0,100,0,55,125,8,0,196,0,55,8  ; n1457 t=72.203s dur=100ms, freq=196Hz, sample=55, buffer_id=08:37 [TRUNCATE prev:ch0 @71942.9ms -> 72202.5ms]
    db 5,0,100,0,58,125,8,11,233,0,58,8  ; n1458 t=72.207s dur=100ms, freq=233Hz, sample=58, buffer_id=08:3A [TRUNCATE prev:ch11 @71644.8ms -> 72207.3ms]
    db 0,0,100,0,51,125,5,2,156,0,51,5  ; n1459 t=72.212s dur=100ms, freq=156Hz, sample=51, buffer_id=05:33 [TRUNCATE prev:ch2 @71659.2ms -> 72212.1ms]
    db 0,0,100,0,27,76,9,4,39,0,27,8  ; n1460 t=72.212s dur=100ms, freq=39Hz, sample=27, buffer_id=08:1B [TRUNCATE prev:ch4 @71914.0ms -> 72212.1ms]
    db 96,0,100,0,38,76,9,5,78,0,38,8  ; n1461 t=72.212s dur=100ms, freq=78Hz, sample=38, buffer_id=08:26 [TRUNCATE prev:ch5 @71914.0ms -> 72212.1ms]
    db 0,0,100,0,51,125,5,6,156,0,51,5  ; n1462 t=72.308s dur=100ms, freq=156Hz, sample=51, buffer_id=05:33
    db 0,0,100,0,55,125,8,7,196,0,55,8  ; n1463 t=72.308s dur=100ms, freq=196Hz, sample=55, buffer_id=08:37 [TRUNCATE prev:ch7 @72034.2ms -> 72308.3ms]
    db 0,0,100,0,58,125,8,11,233,0,58,8  ; n1464 t=72.308s dur=100ms, freq=233Hz, sample=58, buffer_id=08:3A [TRUNCATE prev:ch11 @72207.3ms -> 72308.3ms]
    db 0,0,100,0,27,76,9,1,39,0,27,8  ; n1465 t=72.308s dur=100ms, freq=39Hz, sample=27, buffer_id=08:1B [TRUNCATE prev:ch1 @72010.2ms -> 72308.3ms]
    db 72,0,100,0,38,76,9,3,78,0,38,8  ; n1466 t=72.308s dur=100ms, freq=78Hz, sample=38, buffer_id=08:26 [TRUNCATE prev:ch3 @72010.2ms -> 72308.3ms]
    db 14,0,100,0,55,125,8,8,196,0,55,8  ; n1467 t=72.380s dur=100ms, freq=196Hz, sample=55, buffer_id=08:37
    db 0,0,100,0,51,125,5,2,156,0,51,5  ; n1468 t=72.395s dur=100ms, freq=156Hz, sample=51, buffer_id=05:33 [TRUNCATE prev:ch2 @72212.1ms -> 72394.8ms]
    db 0,0,100,0,58,125,8,9,233,0,58,8  ; n1469 t=72.395s dur=100ms, freq=233Hz, sample=58, buffer_id=08:3A [TRUNCATE prev:ch9 @72116.0ms -> 72394.8ms]
    db 0,0,100,0,27,76,9,4,39,0,27,8  ; n1470 t=72.395s dur=100ms, freq=39Hz, sample=27, buffer_id=08:1B [TRUNCATE prev:ch4 @72212.1ms -> 72394.8ms]
    db 91,0,100,0,38,76,9,5,78,0,38,8  ; n1471 t=72.395s dur=100ms, freq=78Hz, sample=38, buffer_id=08:26 [TRUNCATE prev:ch5 @72212.1ms -> 72394.8ms]
    db 5,0,100,0,58,125,8,10,233,0,58,8  ; n1472 t=72.486s dur=100ms, freq=233Hz, sample=58, buffer_id=08:3A
    db 10,0,100,0,55,125,8,12,196,0,55,8  ; n1473 t=72.491s dur=100ms, freq=196Hz, sample=55, buffer_id=08:37
    db 0,0,100,0,51,125,5,13,156,0,51,5  ; n1474 t=72.501s dur=100ms, freq=156Hz, sample=51, buffer_id=05:33
    db 0,0,100,0,27,76,9,1,39,0,27,8  ; n1475 t=72.501s dur=100ms, freq=39Hz, sample=27, buffer_id=08:1B [TRUNCATE prev:ch1 @72308.3ms -> 72500.6ms]
    db 37,1,100,0,38,76,9,3,78,0,38,8  ; n1476 t=72.501s dur=100ms, freq=78Hz, sample=38, buffer_id=08:26 [TRUNCATE prev:ch3 @72308.3ms -> 72500.6ms]
    db 0,0,109,1,74,125,5,0,75,2,74,5  ; n1477 t=72.794s dur=365ms, freq=587Hz, sample=74, buffer_id=05:4A
    db 5,0,100,0,55,125,8,2,196,0,55,8  ; n1478 t=72.794s dur=100ms, freq=196Hz, sample=55, buffer_id=08:37
    db 0,0,100,0,55,125,5,4,196,0,55,5  ; n1479 t=72.799s dur=100ms, freq=196Hz, sample=55, buffer_id=05:37
    db 0,0,100,0,43,76,9,5,98,0,43,8  ; n1480 t=72.799s dur=100ms, freq=98Hz, sample=43, buffer_id=08:2B
    db 5,0,100,0,31,76,9,6,49,0,31,8  ; n1481 t=72.799s dur=100ms, freq=49Hz, sample=31, buffer_id=08:1F
    db 55,2,133,1,74,124,4,1,75,2,74,4  ; n1482 t=72.803s dur=389ms, freq=587Hz, sample=74, buffer_id=04:4A
    db 0,0,104,1,74,125,5,2,75,2,74,5  ; n1483 t=73.371s dur=360ms, freq=587Hz, sample=74, buffer_id=05:4A
    db 10,0,100,0,55,125,8,0,196,0,55,8  ; n1484 t=73.371s dur=100ms, freq=196Hz, sample=55, buffer_id=08:37
    db 0,0,128,1,74,124,4,3,75,2,74,4  ; n1485 t=73.380s dur=384ms, freq=587Hz, sample=74, buffer_id=04:4A
    db 0,0,100,0,55,125,5,5,196,0,55,5  ; n1486 t=73.380s dur=100ms, freq=196Hz, sample=55, buffer_id=05:37
    db 0,0,100,0,31,76,9,4,49,0,31,8  ; n1487 t=73.380s dur=100ms, freq=49Hz, sample=31, buffer_id=08:1F
    db 32,1,100,0,43,76,9,6,98,0,43,8  ; n1488 t=73.380s dur=100ms, freq=98Hz, sample=43, buffer_id=08:2B
    db 0,0,100,0,55,125,5,1,196,0,55,5  ; n1489 t=73.669s dur=100ms, freq=196Hz, sample=55, buffer_id=05:37
    db 0,0,100,0,43,76,9,7,98,0,43,8  ; n1490 t=73.669s dur=100ms, freq=98Hz, sample=43, buffer_id=08:2B
    db 19,0,100,0,31,76,9,8,49,0,31,8  ; n1491 t=73.669s dur=100ms, freq=49Hz, sample=31, buffer_id=08:1F
    db 72,0,100,0,55,125,8,4,196,0,55,8  ; n1492 t=73.688s dur=100ms, freq=196Hz, sample=55, buffer_id=08:37
    db 0,0,100,0,55,125,5,0,196,0,55,5  ; n1493 t=73.760s dur=100ms, freq=196Hz, sample=55, buffer_id=05:37
    db 0,0,100,0,31,76,9,5,49,0,31,8  ; n1494 t=73.760s dur=100ms, freq=49Hz, sample=31, buffer_id=08:1F
    db 19,0,100,0,43,76,9,9,98,0,43,8  ; n1495 t=73.760s dur=100ms, freq=98Hz, sample=43, buffer_id=08:2B
    db 77,0,100,0,55,125,8,6,196,0,55,8  ; n1496 t=73.779s dur=100ms, freq=196Hz, sample=55, buffer_id=08:37
    db 0,0,100,0,55,125,5,10,196,0,55,5  ; n1497 t=73.856s dur=100ms, freq=196Hz, sample=55, buffer_id=05:37
    db 0,0,100,0,43,76,9,11,98,0,43,8  ; n1498 t=73.856s dur=100ms, freq=98Hz, sample=43, buffer_id=08:2B
    db 24,0,100,0,31,76,9,12,49,0,31,8  ; n1499 t=73.856s dur=100ms, freq=49Hz, sample=31, buffer_id=08:1F
    db 62,0,100,0,55,125,8,13,196,0,55,8  ; n1500 t=73.880s dur=100ms, freq=196Hz, sample=55, buffer_id=08:37
    db 5,0,119,1,74,125,5,2,75,2,74,5  ; n1501 t=73.943s dur=375ms, freq=587Hz, sample=74, buffer_id=05:4A [TRUNCATE prev:ch2 @73370.8ms -> 73942.9ms]
    db 0,0,100,0,55,125,5,1,196,0,55,5  ; n1502 t=73.948s dur=100ms, freq=196Hz, sample=55, buffer_id=05:37 [TRUNCATE prev:ch1 @73668.8ms -> 73947.7ms]
    db 0,0,100,0,31,76,9,8,49,0,31,8  ; n1503 t=73.948s dur=100ms, freq=49Hz, sample=31, buffer_id=08:1F [TRUNCATE prev:ch8 @73668.8ms -> 73947.7ms]
    db 10,0,100,0,43,76,9,7,98,0,43,8  ; n1504 t=73.948s dur=100ms, freq=98Hz, sample=43, buffer_id=08:2B [TRUNCATE prev:ch7 @73668.8ms -> 73947.7ms]
    db 10,0,100,0,55,125,8,4,196,0,55,8  ; n1505 t=73.957s dur=100ms, freq=196Hz, sample=55, buffer_id=08:37 [TRUNCATE prev:ch4 @73688.1ms -> 73957.3ms]
    db 13,1,128,1,74,124,4,3,75,2,74,4  ; n1506 t=73.967s dur=384ms, freq=587Hz, sample=74, buffer_id=04:4A [TRUNCATE prev:ch3 @73380.4ms -> 73966.9ms]
    db 10,0,100,0,55,125,8,0,196,0,55,8  ; n1507 t=74.236s dur=100ms, freq=196Hz, sample=55, buffer_id=08:37
    db 0,0,100,0,55,125,5,5,196,0,55,5  ; n1508 t=74.246s dur=100ms, freq=196Hz, sample=55, buffer_id=05:37
    db 0,0,100,0,43,76,9,6,98,0,43,8  ; n1509 t=74.246s dur=100ms, freq=98Hz, sample=43, buffer_id=08:2B
    db 87,0,100,0,31,76,9,9,49,0,31,8  ; n1510 t=74.246s dur=100ms, freq=49Hz, sample=31, buffer_id=08:1F
    db 5,0,100,0,55,125,8,1,196,0,55,8  ; n1511 t=74.332s dur=100ms, freq=196Hz, sample=55, buffer_id=08:37
    db 0,0,100,0,55,125,5,4,196,0,55,5  ; n1512 t=74.337s dur=100ms, freq=196Hz, sample=55, buffer_id=05:37
    db 0,0,100,0,31,76,9,7,49,0,31,8  ; n1513 t=74.337s dur=100ms, freq=49Hz, sample=31, buffer_id=08:1F
    db 91,0,100,0,43,76,9,8,98,0,43,8  ; n1514 t=74.337s dur=100ms, freq=98Hz, sample=43, buffer_id=08:2B
    db 5,0,100,0,55,125,8,10,196,0,55,8  ; n1515 t=74.428s dur=100ms, freq=196Hz, sample=55, buffer_id=08:37
    db 0,0,100,0,55,125,5,11,196,0,55,5  ; n1516 t=74.433s dur=100ms, freq=196Hz, sample=55, buffer_id=05:37
    db 0,0,100,0,43,76,9,12,98,0,43,8  ; n1517 t=74.433s dur=100ms, freq=98Hz, sample=43, buffer_id=08:2B
    db 87,0,100,0,31,76,9,13,49,0,31,8  ; n1518 t=74.433s dur=100ms, freq=49Hz, sample=31, buffer_id=08:1F
    db 0,0,100,0,65,125,8,2,114,1,65,8  ; n1519 t=74.520s dur=100ms, freq=370Hz, sample=65, buffer_id=08:41
    db 5,0,100,0,58,125,8,3,233,0,58,8  ; n1520 t=74.520s dur=100ms, freq=233Hz, sample=58, buffer_id=08:3A [TRUNCATE prev:ch3 @73966.9ms -> 74519.8ms]
    db 0,0,100,0,51,125,5,0,156,0,51,5  ; n1521 t=74.525s dur=100ms, freq=156Hz, sample=51, buffer_id=05:33 [TRUNCATE prev:ch0 @74236.2ms -> 74524.6ms]
    db 0,0,100,0,27,76,9,5,39,0,27,8  ; n1522 t=74.525s dur=100ms, freq=39Hz, sample=27, buffer_id=08:1B [TRUNCATE prev:ch5 @74245.8ms -> 74524.6ms]
    db 0,0,100,0,38,76,9,6,78,0,38,8  ; n1523 t=74.525s dur=100ms, freq=78Hz, sample=38, buffer_id=08:26 [TRUNCATE prev:ch6 @74245.8ms -> 74524.6ms]
    db 14,0,100,0,58,76,9,9,233,0,58,8  ; n1524 t=74.525s dur=100ms, freq=233Hz, sample=58, buffer_id=08:3A [TRUNCATE prev:ch9 @74245.8ms -> 74524.6ms]
    db 5,0,250,0,74,125,5,1,110,2,74,5  ; n1525 t=74.539s dur=250ms, freq=622Hz, sample=74, buffer_id=05:4A [TRUNCATE prev:ch1 @74332.3ms -> 74539.0ms]
    db 72,0,254,0,75,124,4,4,110,2,75,4  ; n1526 t=74.544s dur=254ms, freq=622Hz, sample=75, buffer_id=04:4B [TRUNCATE prev:ch4 @74337.1ms -> 74543.8ms]
    db 0,0,100,0,58,125,8,7,233,0,58,8  ; n1527 t=74.616s dur=100ms, freq=233Hz, sample=58, buffer_id=08:3A [TRUNCATE prev:ch7 @74337.1ms -> 74616.0ms]
    db 0,0,100,0,65,125,8,8,114,1,65,8  ; n1528 t=74.616s dur=100ms, freq=370Hz, sample=65, buffer_id=08:41 [TRUNCATE prev:ch8 @74337.1ms -> 74616.0ms]
    db 5,0,100,0,58,76,9,10,233,0,58,8  ; n1529 t=74.616s dur=100ms, freq=233Hz, sample=58, buffer_id=08:3A [TRUNCATE prev:ch10 @74428.5ms -> 74616.0ms]
    db 0,0,100,0,51,125,5,11,156,0,51,5  ; n1530 t=74.621s dur=100ms, freq=156Hz, sample=51, buffer_id=05:33 [TRUNCATE prev:ch11 @74433.3ms -> 74620.8ms]
    db 0,0,100,0,27,76,9,12,39,0,27,8  ; n1531 t=74.621s dur=100ms, freq=39Hz, sample=27, buffer_id=08:1B [TRUNCATE prev:ch12 @74433.3ms -> 74620.8ms]
    db 91,0,100,0,38,76,9,13,78,0,38,8  ; n1532 t=74.621s dur=100ms, freq=78Hz, sample=38, buffer_id=08:26 [TRUNCATE prev:ch13 @74433.3ms -> 74620.8ms]
    db 5,0,100,0,65,125,8,2,114,1,65,8  ; n1533 t=74.712s dur=100ms, freq=370Hz, sample=65, buffer_id=08:41 [TRUNCATE prev:ch2 @74519.8ms -> 74712.1ms]
    db 0,0,100,0,51,125,5,0,156,0,51,5  ; n1534 t=74.717s dur=100ms, freq=156Hz, sample=51, buffer_id=05:33 [TRUNCATE prev:ch0 @74524.6ms -> 74716.9ms]
    db 0,0,100,0,58,125,8,3,233,0,58,8  ; n1535 t=74.717s dur=100ms, freq=233Hz, sample=58, buffer_id=08:3A [TRUNCATE prev:ch3 @74519.8ms -> 74716.9ms]
    db 0,0,100,0,27,76,9,5,39,0,27,8  ; n1536 t=74.717s dur=100ms, freq=39Hz, sample=27, buffer_id=08:1B [TRUNCATE prev:ch5 @74524.6ms -> 74716.9ms]
    db 0,0,100,0,38,76,9,6,78,0,38,8  ; n1537 t=74.717s dur=100ms, freq=78Hz, sample=38, buffer_id=08:26 [TRUNCATE prev:ch6 @74524.6ms -> 74716.9ms]
    db 91,0,100,0,58,76,9,9,233,0,58,8  ; n1538 t=74.717s dur=100ms, freq=233Hz, sample=58, buffer_id=08:3A [TRUNCATE prev:ch9 @74524.6ms -> 74716.9ms]
    db 0,0,100,0,58,125,8,7,233,0,58,8  ; n1539 t=74.808s dur=100ms, freq=233Hz, sample=58, buffer_id=08:3A [TRUNCATE prev:ch7 @74616.0ms -> 74808.3ms]
    db 0,0,100,0,65,125,8,8,114,1,65,8  ; n1540 t=74.808s dur=100ms, freq=370Hz, sample=65, buffer_id=08:41 [TRUNCATE prev:ch8 @74616.0ms -> 74808.3ms]
    db 10,0,100,0,58,76,9,10,233,0,58,8  ; n1541 t=74.808s dur=100ms, freq=233Hz, sample=58, buffer_id=08:3A [TRUNCATE prev:ch10 @74616.0ms -> 74808.3ms]
    db 0,0,100,0,51,125,5,11,156,0,51,5  ; n1542 t=74.818s dur=100ms, freq=156Hz, sample=51, buffer_id=05:33 [TRUNCATE prev:ch11 @74620.8ms -> 74817.9ms]
    db 0,0,100,0,27,76,9,12,39,0,27,8  ; n1543 t=74.818s dur=100ms, freq=39Hz, sample=27, buffer_id=08:1B [TRUNCATE prev:ch12 @74620.8ms -> 74817.9ms]
    db 139,0,100,0,38,76,9,13,78,0,38,8  ; n1544 t=74.818s dur=100ms, freq=78Hz, sample=38, buffer_id=08:26 [TRUNCATE prev:ch13 @74620.8ms -> 74817.9ms]
    db 5,0,100,0,69,125,5,1,210,1,69,5  ; n1545 t=74.957s dur=100ms, freq=466Hz, sample=69, buffer_id=05:45 [TRUNCATE prev:ch1 @74539.0ms -> 74957.3ms]
    db 125,0,100,0,70,124,4,4,210,1,70,4  ; n1546 t=74.962s dur=100ms, freq=466Hz, sample=70, buffer_id=04:46 [TRUNCATE prev:ch4 @74543.8ms -> 74962.1ms]
    db 0,0,100,0,63,125,5,0,55,1,63,5  ; n1547 t=75.087s dur=100ms, freq=311Hz, sample=63, buffer_id=05:3F
    db 0,0,100,0,50,76,9,2,156,0,50,8  ; n1548 t=75.087s dur=100ms, freq=156Hz, sample=50, buffer_id=08:32
    db 24,0,100,0,38,76,9,3,78,0,38,8  ; n1549 t=75.087s dur=100ms, freq=78Hz, sample=38, buffer_id=08:26
    db 0,0,104,1,65,124,4,5,114,1,65,4  ; n1550 t=75.111s dur=360ms, freq=370Hz, sample=65, buffer_id=04:41
    db 0,0,100,0,63,125,8,6,55,1,63,8  ; n1551 t=75.111s dur=100ms, freq=311Hz, sample=63, buffer_id=08:3F
    db 10,0,100,0,58,125,8,8,233,0,58,8  ; n1552 t=75.111s dur=100ms, freq=233Hz, sample=58, buffer_id=08:3A
    db 41,2,147,1,63,125,5,7,114,1,63,5  ; n1553 t=75.121s dur=403ms, freq=370Hz, sample=63, buffer_id=05:3F
    db 0,0,56,1,65,124,4,0,55,1,65,4  ; n1554 t=75.674s dur=312ms, freq=311Hz, sample=65, buffer_id=04:41
    db 0,0,100,0,58,125,5,1,6,1,58,5  ; n1555 t=75.674s dur=100ms, freq=262Hz, sample=58, buffer_id=05:3A
    db 0,0,100,0,63,125,8,2,55,1,63,8  ; n1556 t=75.674s dur=100ms, freq=311Hz, sample=63, buffer_id=08:3F
    db 0,0,100,0,47,76,9,3,131,0,47,8  ; n1557 t=75.674s dur=100ms, freq=131Hz, sample=47, buffer_id=08:2F
    db 5,0,100,0,38,76,9,4,65,0,38,8  ; n1558 t=75.674s dur=100ms, freq=65Hz, sample=38, buffer_id=08:26
    db 5,0,240,0,63,125,5,5,55,1,63,5  ; n1559 t=75.678s dur=240ms, freq=311Hz, sample=63, buffer_id=05:3F
    db 28,1,100,0,63,125,8,8,55,1,63,8  ; n1560 t=75.683s dur=100ms, freq=311Hz, sample=63, buffer_id=08:3F
    db 0,0,100,0,58,125,5,6,6,1,58,5  ; n1561 t=75.967s dur=100ms, freq=262Hz, sample=58, buffer_id=05:3A
    db 0,0,100,0,47,76,9,7,131,0,47,8  ; n1562 t=75.967s dur=100ms, freq=131Hz, sample=47, buffer_id=08:2F
    db 38,0,100,0,38,76,9,9,65,0,38,8  ; n1563 t=75.967s dur=100ms, freq=65Hz, sample=38, buffer_id=08:26
    db 58,0,100,0,63,125,8,1,55,1,63,8  ; n1564 t=76.005s dur=100ms, freq=311Hz, sample=63, buffer_id=08:3F
    db 0,0,100,0,58,125,5,2,6,1,58,5  ; n1565 t=76.063s dur=100ms, freq=262Hz, sample=58, buffer_id=05:3A
    db 0,0,100,0,47,76,9,4,131,0,47,8  ; n1566 t=76.063s dur=100ms, freq=131Hz, sample=47, buffer_id=08:2F
    db 24,0,100,0,38,76,9,3,65,0,38,8  ; n1567 t=76.063s dur=100ms, freq=65Hz, sample=38, buffer_id=08:26
    db 10,0,100,0,63,125,8,10,55,1,63,8  ; n1568 t=76.087s dur=100ms, freq=311Hz, sample=63, buffer_id=08:3F
    db 10,0,100,0,69,125,5,8,210,1,69,5  ; n1569 t=76.097s dur=100ms, freq=466Hz, sample=69, buffer_id=05:45
    db 53,0,100,0,70,124,4,11,210,1,70,4  ; n1570 t=76.106s dur=100ms, freq=466Hz, sample=70, buffer_id=04:46
    db 0,0,100,0,58,125,5,5,6,1,58,5  ; n1571 t=76.159s dur=100ms, freq=262Hz, sample=58, buffer_id=05:3A
    db 0,0,100,0,47,76,9,12,131,0,47,8  ; n1572 t=76.159s dur=100ms, freq=131Hz, sample=47, buffer_id=08:2F
    db 19,0,100,0,38,76,9,13,65,0,38,8  ; n1573 t=76.159s dur=100ms, freq=65Hz, sample=38, buffer_id=08:26 [TRUNCATE prev:ch13 @74817.9ms -> 76159.2ms]
    db 72,0,100,0,63,125,8,1,55,1,63,8  ; n1574 t=76.178s dur=100ms, freq=311Hz, sample=63, buffer_id=08:3F [TRUNCATE prev:ch1 @76005.4ms -> 76178.5ms]
    db 0,0,100,0,55,125,5,0,196,0,55,5  ; n1575 t=76.251s dur=100ms, freq=196Hz, sample=55, buffer_id=05:37
    db 0,0,100,0,43,76,9,6,98,0,43,8  ; n1576 t=76.251s dur=100ms, freq=98Hz, sample=43, buffer_id=08:2B [TRUNCATE prev:ch6 @75966.9ms -> 76250.6ms]
    db 5,0,100,0,31,76,9,7,49,0,31,8  ; n1577 t=76.251s dur=100ms, freq=49Hz, sample=31, buffer_id=08:1F [TRUNCATE prev:ch7 @75966.9ms -> 76250.6ms]
    db 5,0,189,2,69,125,5,8,136,1,69,5  ; n1578 t=76.255s dur=701ms, freq=392Hz, sample=69, buffer_id=05:45 [TRUNCATE prev:ch8 @76096.7ms -> 76255.4ms]
    db 5,0,100,0,55,125,8,9,196,0,55,8  ; n1579 t=76.260s dur=100ms, freq=196Hz, sample=55, buffer_id=08:37 [TRUNCATE prev:ch9 @75966.9ms -> 76260.2ms]
    db 18,1,189,2,65,124,4,2,136,1,65,4  ; n1580 t=76.265s dur=701ms, freq=392Hz, sample=65, buffer_id=04:41 [TRUNCATE prev:ch2 @76063.1ms -> 76265.0ms]
    db 0,0,100,0,58,126,3,1,233,0,58,3  ; n1581 t=76.539s dur=100ms, freq=233Hz, sample=58, buffer_id=03:3A
    db 5,0,100,0,58,125,8,3,233,0,58,8  ; n1582 t=76.539s dur=100ms, freq=233Hz, sample=58, buffer_id=08:3A
    db 0,0,100,0,62,126,3,4,38,1,62,3  ; n1583 t=76.544s dur=100ms, freq=294Hz, sample=62, buffer_id=03:3E
    db 91,0,100,0,62,125,8,5,38,1,62,8  ; n1584 t=76.544s dur=100ms, freq=294Hz, sample=62, buffer_id=08:3E
    db 0,0,100,0,58,126,3,0,233,0,58,3  ; n1585 t=76.635s dur=100ms, freq=233Hz, sample=58, buffer_id=03:3A
    db 0,0,100,0,58,125,8,6,233,0,58,8  ; n1586 t=76.635s dur=100ms, freq=233Hz, sample=58, buffer_id=08:3A
    db 5,0,100,0,62,125,8,7,38,1,62,8  ; n1587 t=76.635s dur=100ms, freq=294Hz, sample=62, buffer_id=08:3E
    db 0,0,100,0,62,126,3,9,38,1,62,3  ; n1588 t=76.640s dur=100ms, freq=294Hz, sample=62, buffer_id=03:3E
    db 0,0,100,0,55,125,5,10,196,0,55,5  ; n1589 t=76.640s dur=100ms, freq=196Hz, sample=55, buffer_id=05:37
    db 0,0,100,0,31,76,9,11,49,0,31,8  ; n1590 t=76.640s dur=100ms, freq=49Hz, sample=31, buffer_id=08:1F
    db 91,0,100,0,43,76,9,12,98,0,43,8  ; n1591 t=76.640s dur=100ms, freq=98Hz, sample=43, buffer_id=08:2B
    db 0,0,100,0,58,126,3,13,233,0,58,3  ; n1592 t=76.731s dur=100ms, freq=233Hz, sample=58, buffer_id=03:3A
    db 0,0,100,0,55,125,5,8,196,0,55,5  ; n1593 t=76.731s dur=100ms, freq=196Hz, sample=55, buffer_id=05:37 [TRUNCATE prev:ch8 @76255.4ms -> 76731.3ms]
    db 0,0,100,0,58,125,8,3,233,0,58,8  ; n1594 t=76.731s dur=100ms, freq=233Hz, sample=58, buffer_id=08:3A [TRUNCATE prev:ch3 @76539.0ms -> 76731.3ms]
    db 0,0,100,0,62,125,8,5,38,1,62,8  ; n1595 t=76.731s dur=100ms, freq=294Hz, sample=62, buffer_id=08:3E [TRUNCATE prev:ch5 @76543.8ms -> 76731.3ms]
    db 0,0,100,0,31,76,9,2,49,0,31,8  ; n1596 t=76.731s dur=100ms, freq=49Hz, sample=31, buffer_id=08:1F [TRUNCATE prev:ch2 @76265.0ms -> 76731.3ms]
    db 5,0,100,0,43,76,9,1,98,0,43,8  ; n1597 t=76.731s dur=100ms, freq=98Hz, sample=43, buffer_id=08:2B [TRUNCATE prev:ch1 @76539.0ms -> 76731.3ms]
    db 91,0,100,0,62,126,3,4,38,1,62,3  ; n1598 t=76.736s dur=100ms, freq=294Hz, sample=62, buffer_id=03:3E [TRUNCATE prev:ch4 @76543.8ms -> 76736.2ms]
    db 0,0,100,0,63,126,3,0,55,1,63,3  ; n1599 t=76.828s dur=100ms, freq=311Hz, sample=63, buffer_id=03:3F [TRUNCATE prev:ch0 @76635.2ms -> 76827.5ms]
    db 0,0,100,0,58,126,3,6,247,0,58,3  ; n1600 t=76.828s dur=100ms, freq=247Hz, sample=58, buffer_id=03:3A [TRUNCATE prev:ch6 @76635.2ms -> 76827.5ms]
    db 0,0,100,0,59,125,8,7,247,0,59,8  ; n1601 t=76.828s dur=100ms, freq=247Hz, sample=59, buffer_id=08:3B [TRUNCATE prev:ch7 @76635.2ms -> 76827.5ms]
    db 5,0,100,0,63,125,8,9,55,1,63,8  ; n1602 t=76.828s dur=100ms, freq=311Hz, sample=63, buffer_id=08:3F [TRUNCATE prev:ch9 @76640.0ms -> 76827.5ms]
    db 0,0,100,0,55,125,5,10,196,0,55,5  ; n1603 t=76.832s dur=100ms, freq=196Hz, sample=55, buffer_id=05:37 [TRUNCATE prev:ch10 @76640.0ms -> 76832.3ms]
    db 0,0,100,0,31,76,9,11,49,0,31,8  ; n1604 t=76.832s dur=100ms, freq=49Hz, sample=31, buffer_id=08:1F [TRUNCATE prev:ch11 @76640.0ms -> 76832.3ms]
    db 10,0,100,0,43,76,9,12,98,0,43,8  ; n1605 t=76.832s dur=100ms, freq=98Hz, sample=43, buffer_id=08:2B [TRUNCATE prev:ch12 @76640.0ms -> 76832.3ms]
    db 82,0,100,0,50,76,9,1,147,0,50,8  ; n1606 t=76.842s dur=100ms, freq=147Hz, sample=50, buffer_id=08:32 [TRUNCATE prev:ch1 @76731.3ms -> 76841.9ms]
    db 0,0,100,0,58,126,3,13,247,0,58,3  ; n1607 t=76.924s dur=100ms, freq=247Hz, sample=58, buffer_id=03:3A [TRUNCATE prev:ch13 @76731.3ms -> 76923.7ms]
    db 0,0,100,0,55,125,5,8,196,0,55,5  ; n1608 t=76.924s dur=100ms, freq=196Hz, sample=55, buffer_id=05:37 [TRUNCATE prev:ch8 @76731.3ms -> 76923.7ms]
    db 0,0,100,0,59,125,8,2,247,0,59,8  ; n1609 t=76.924s dur=100ms, freq=247Hz, sample=59, buffer_id=08:3B [TRUNCATE prev:ch2 @76731.3ms -> 76923.7ms]
    db 0,0,100,0,63,125,8,3,55,1,63,8  ; n1610 t=76.924s dur=100ms, freq=311Hz, sample=63, buffer_id=08:3F [TRUNCATE prev:ch3 @76731.3ms -> 76923.7ms]
    db 0,0,100,0,31,76,9,5,49,0,31,8  ; n1611 t=76.924s dur=100ms, freq=49Hz, sample=31, buffer_id=08:1F [TRUNCATE prev:ch5 @76731.3ms -> 76923.7ms]
    db 5,0,100,0,43,76,9,4,98,0,43,8  ; n1612 t=76.924s dur=100ms, freq=98Hz, sample=43, buffer_id=08:2B [TRUNCATE prev:ch4 @76736.2ms -> 76923.7ms]
    db 10,0,100,0,63,126,3,0,55,1,63,3  ; n1613 t=76.928s dur=100ms, freq=311Hz, sample=63, buffer_id=03:3F [TRUNCATE prev:ch0 @76827.5ms -> 76928.5ms]
    db 77,0,100,0,50,76,9,6,147,0,50,8  ; n1614 t=76.938s dur=100ms, freq=147Hz, sample=50, buffer_id=08:32 [TRUNCATE prev:ch6 @76827.5ms -> 76938.1ms]
    db 5,0,100,0,58,126,3,7,247,0,58,3  ; n1615 t=77.015s dur=100ms, freq=247Hz, sample=58, buffer_id=03:3A [TRUNCATE prev:ch7 @76827.5ms -> 77015.0ms]
    db 0,0,100,0,63,126,3,9,55,1,63,3  ; n1616 t=77.020s dur=100ms, freq=311Hz, sample=63, buffer_id=03:3F [TRUNCATE prev:ch9 @76827.5ms -> 77019.8ms]
    db 0,0,100,0,55,125,5,10,196,0,55,5  ; n1617 t=77.020s dur=100ms, freq=196Hz, sample=55, buffer_id=05:37 [TRUNCATE prev:ch10 @76832.3ms -> 77019.8ms]
    db 0,0,100,0,63,125,8,11,55,1,63,8  ; n1618 t=77.020s dur=100ms, freq=311Hz, sample=63, buffer_id=08:3F [TRUNCATE prev:ch11 @76832.3ms -> 77019.8ms]
    db 0,0,100,0,59,125,8,12,247,0,59,8  ; n1619 t=77.020s dur=100ms, freq=247Hz, sample=59, buffer_id=08:3B [TRUNCATE prev:ch12 @76832.3ms -> 77019.8ms]
    db 0,0,100,0,31,76,9,1,49,0,31,8  ; n1620 t=77.020s dur=100ms, freq=49Hz, sample=31, buffer_id=08:1F [TRUNCATE prev:ch1 @76841.9ms -> 77019.8ms]
    db 14,0,100,0,43,76,9,2,98,0,43,8  ; n1621 t=77.020s dur=100ms, freq=98Hz, sample=43, buffer_id=08:2B [TRUNCATE prev:ch2 @76923.7ms -> 77019.8ms]
    db 82,0,100,0,50,76,9,3,147,0,50,8  ; n1622 t=77.034s dur=100ms, freq=147Hz, sample=50, buffer_id=08:32 [TRUNCATE prev:ch3 @76923.7ms -> 77034.2ms]
    db 0,0,100,0,62,126,3,4,21,1,62,3  ; n1623 t=77.116s dur=100ms, freq=277Hz, sample=62, buffer_id=03:3E [TRUNCATE prev:ch4 @76923.7ms -> 77116.0ms]
    db 0,0,100,0,65,126,3,5,93,1,65,3  ; n1624 t=77.116s dur=100ms, freq=349Hz, sample=65, buffer_id=03:41 [TRUNCATE prev:ch5 @76923.7ms -> 77116.0ms]
    db 0,0,100,0,55,125,5,8,196,0,55,5  ; n1625 t=77.116s dur=100ms, freq=196Hz, sample=55, buffer_id=05:37 [TRUNCATE prev:ch8 @76923.7ms -> 77116.0ms]
    db 0,0,100,0,65,125,8,13,93,1,65,8  ; n1626 t=77.116s dur=100ms, freq=349Hz, sample=65, buffer_id=08:41 [TRUNCATE prev:ch13 @76923.7ms -> 77116.0ms]
    db 0,0,100,0,61,125,8,0,21,1,61,8  ; n1627 t=77.116s dur=100ms, freq=277Hz, sample=61, buffer_id=08:3D [TRUNCATE prev:ch0 @76928.5ms -> 77116.0ms]
    db 0,0,100,0,31,76,9,6,49,0,31,8  ; n1628 t=77.116s dur=100ms, freq=49Hz, sample=31, buffer_id=08:1F [TRUNCATE prev:ch6 @76938.1ms -> 77116.0ms]
    db 10,0,100,0,43,76,9,7,98,0,43,8  ; n1629 t=77.116s dur=100ms, freq=98Hz, sample=43, buffer_id=08:2B [TRUNCATE prev:ch7 @77015.0ms -> 77116.0ms]
    db 82,0,100,0,50,76,9,1,147,0,50,8  ; n1630 t=77.126s dur=100ms, freq=147Hz, sample=50, buffer_id=08:32 [TRUNCATE prev:ch1 @77019.8ms -> 77125.6ms]
    db 0,0,100,0,65,126,3,2,93,1,65,3  ; n1631 t=77.207s dur=100ms, freq=349Hz, sample=65, buffer_id=03:41 [TRUNCATE prev:ch2 @77019.8ms -> 77207.3ms]
    db 5,0,100,0,62,126,3,9,21,1,62,3  ; n1632 t=77.207s dur=100ms, freq=277Hz, sample=62, buffer_id=03:3E [TRUNCATE prev:ch9 @77019.8ms -> 77207.3ms]
    db 0,0,100,0,61,125,8,10,21,1,61,8  ; n1633 t=77.212s dur=100ms, freq=277Hz, sample=61, buffer_id=08:3D [TRUNCATE prev:ch10 @77019.8ms -> 77212.1ms]
    db 87,0,100,0,65,125,8,11,93,1,65,8  ; n1634 t=77.212s dur=100ms, freq=349Hz, sample=65, buffer_id=08:41 [TRUNCATE prev:ch11 @77019.8ms -> 77212.1ms]
    db 10,0,100,0,65,126,3,5,93,1,65,3  ; n1635 t=77.299s dur=100ms, freq=349Hz, sample=65, buffer_id=03:41 [TRUNCATE prev:ch5 @77116.0ms -> 77298.7ms]
    db 0,0,100,0,62,126,3,4,21,1,62,3  ; n1636 t=77.308s dur=100ms, freq=277Hz, sample=62, buffer_id=03:3E [TRUNCATE prev:ch4 @77116.0ms -> 77308.3ms]
    db 0,0,100,0,61,125,8,0,21,1,61,8  ; n1637 t=77.308s dur=100ms, freq=277Hz, sample=61, buffer_id=08:3D [TRUNCATE prev:ch0 @77116.0ms -> 77308.3ms]
    db 96,0,100,0,65,125,8,13,93,1,65,8  ; n1638 t=77.308s dur=100ms, freq=349Hz, sample=65, buffer_id=08:41 [TRUNCATE prev:ch13 @77116.0ms -> 77308.3ms]
    db 0,0,100,0,55,125,5,3,196,0,55,5  ; n1639 t=77.404s dur=100ms, freq=196Hz, sample=55, buffer_id=05:37
    db 0,0,186,1,79,125,5,12,16,3,79,5  ; n1640 t=77.404s dur=442ms, freq=784Hz, sample=79, buffer_id=05:4F
    db 0,0,100,0,31,76,9,6,49,0,31,8  ; n1641 t=77.404s dur=100ms, freq=49Hz, sample=31, buffer_id=08:1F [TRUNCATE prev:ch6 @77116.0ms -> 77404.4ms]
    db 5,0,100,0,43,76,9,7,98,0,43,8  ; n1642 t=77.404s dur=100ms, freq=98Hz, sample=43, buffer_id=08:2B [TRUNCATE prev:ch7 @77116.0ms -> 77404.4ms]
    db 29,0,100,0,67,125,8,8,136,1,67,8  ; n1643 t=77.409s dur=100ms, freq=392Hz, sample=67, buffer_id=08:43 [TRUNCATE prev:ch8 @77116.0ms -> 77409.2ms]
    db 31,2,90,1,78,124,4,1,16,3,78,4  ; n1644 t=77.438s dur=346ms, freq=784Hz, sample=78, buffer_id=04:4E
    db 0,0,211,0,65,124,4,0,136,1,65,4  ; n1645 t=77.981s dur=211ms, freq=392Hz, sample=65, buffer_id=04:41
    db 5,0,100,0,67,125,8,2,136,1,67,8  ; n1646 t=77.981s dur=100ms, freq=392Hz, sample=67, buffer_id=08:43
    db 0,0,100,0,55,125,5,1,196,0,55,5  ; n1647 t=77.986s dur=100ms, freq=196Hz, sample=55, buffer_id=05:37
    db 0,0,32,1,69,125,5,3,136,1,69,5  ; n1648 t=77.986s dur=288ms, freq=392Hz, sample=69, buffer_id=05:45
    db 0,0,100,0,43,76,9,4,98,0,43,8  ; n1649 t=77.986s dur=100ms, freq=98Hz, sample=43, buffer_id=08:2B
    db 42,1,100,0,31,76,9,5,49,0,31,8  ; n1650 t=77.986s dur=100ms, freq=49Hz, sample=31, buffer_id=08:1F
    db 0,0,100,0,55,125,5,2,196,0,55,5  ; n1651 t=78.284s dur=100ms, freq=196Hz, sample=55, buffer_id=05:37
    db 0,0,100,0,31,76,9,7,49,0,31,8  ; n1652 t=78.284s dur=100ms, freq=49Hz, sample=31, buffer_id=08:1F
    db 14,0,100,0,43,76,9,6,98,0,43,8  ; n1653 t=78.284s dur=100ms, freq=98Hz, sample=43, buffer_id=08:2B
    db 82,0,100,0,67,125,8,1,136,1,67,8  ; n1654 t=78.299s dur=100ms, freq=392Hz, sample=67, buffer_id=08:43
    db 0,0,100,0,55,125,5,4,196,0,55,5  ; n1655 t=78.380s dur=100ms, freq=196Hz, sample=55, buffer_id=05:37
    db 0,0,100,0,43,76,9,5,98,0,43,8  ; n1656 t=78.380s dur=100ms, freq=98Hz, sample=43, buffer_id=08:2B
    db 10,0,100,0,31,76,9,8,49,0,31,8  ; n1657 t=78.380s dur=100ms, freq=49Hz, sample=31, buffer_id=08:1F
    db 48,0,100,0,67,125,8,9,136,1,67,8  ; n1658 t=78.390s dur=100ms, freq=392Hz, sample=67, buffer_id=08:43
    db 14,0,110,0,69,125,5,0,136,1,69,5  ; n1659 t=78.438s dur=110ms, freq=392Hz, sample=69, buffer_id=05:45
    db 19,0,100,0,65,124,4,10,136,1,65,4  ; n1660 t=78.453s dur=100ms, freq=392Hz, sample=65, buffer_id=04:41
    db 0,0,100,0,55,125,5,11,196,0,55,5  ; n1661 t=78.472s dur=100ms, freq=196Hz, sample=55, buffer_id=05:37
    db 0,0,100,0,31,76,9,12,49,0,31,8  ; n1662 t=78.472s dur=100ms, freq=49Hz, sample=31, buffer_id=08:1F
    db 10,0,100,0,43,76,9,13,98,0,43,8  ; n1663 t=78.472s dur=100ms, freq=98Hz, sample=43, buffer_id=08:2B
    db 77,0,100,0,67,125,8,3,136,1,67,8  ; n1664 t=78.481s dur=100ms, freq=392Hz, sample=67, buffer_id=08:43
    db 5,0,100,0,67,125,8,1,136,1,67,8  ; n1665 t=78.558s dur=100ms, freq=392Hz, sample=67, buffer_id=08:43 [TRUNCATE prev:ch1 @78298.7ms -> 78558.3ms]
    db 0,0,100,0,55,125,5,2,196,0,55,5  ; n1666 t=78.563s dur=100ms, freq=196Hz, sample=55, buffer_id=05:37 [TRUNCATE prev:ch2 @78284.2ms -> 78563.1ms]
    db 0,0,100,0,43,76,9,6,98,0,43,8  ; n1667 t=78.563s dur=100ms, freq=98Hz, sample=43, buffer_id=08:2B [TRUNCATE prev:ch6 @78284.2ms -> 78563.1ms]
    db 19,0,100,0,31,76,9,7,49,0,31,8  ; n1668 t=78.563s dur=100ms, freq=49Hz, sample=31, buffer_id=08:1F [TRUNCATE prev:ch7 @78284.2ms -> 78563.1ms]
    db 5,0,109,1,79,125,5,4,16,3,79,5  ; n1669 t=78.582s dur=365ms, freq=784Hz, sample=79, buffer_id=05:4F [TRUNCATE prev:ch4 @78380.4ms -> 78582.3ms]
    db 8,1,133,1,78,124,4,5,16,3,78,4  ; n1670 t=78.587s dur=389ms, freq=784Hz, sample=78, buffer_id=04:4E [TRUNCATE prev:ch5 @78380.4ms -> 78587.1ms]
    db 0,0,100,0,55,125,5,0,196,0,55,5  ; n1671 t=78.852s dur=100ms, freq=196Hz, sample=55, buffer_id=05:37
    db 0,0,100,0,31,76,9,3,49,0,31,8  ; n1672 t=78.852s dur=100ms, freq=49Hz, sample=31, buffer_id=08:1F
    db 10,0,100,0,43,76,9,8,98,0,43,8  ; n1673 t=78.852s dur=100ms, freq=98Hz, sample=43, buffer_id=08:2B
    db 87,0,100,0,67,125,8,10,136,1,67,8  ; n1674 t=78.861s dur=100ms, freq=392Hz, sample=67, buffer_id=08:43
    db 0,0,100,0,55,125,5,1,196,0,55,5  ; n1675 t=78.948s dur=100ms, freq=196Hz, sample=55, buffer_id=05:37
    db 0,0,100,0,43,76,9,2,98,0,43,8  ; n1676 t=78.948s dur=100ms, freq=98Hz, sample=43, buffer_id=08:2B
    db 5,0,100,0,31,76,9,6,49,0,31,8  ; n1677 t=78.948s dur=100ms, freq=49Hz, sample=31, buffer_id=08:1F
    db 87,0,100,0,67,125,8,7,136,1,67,8  ; n1678 t=78.953s dur=100ms, freq=392Hz, sample=67, buffer_id=08:43
    db 0,0,100,0,55,125,5,9,196,0,55,5  ; n1679 t=79.039s dur=100ms, freq=196Hz, sample=55, buffer_id=05:37
    db 0,0,100,0,31,76,9,11,49,0,31,8  ; n1680 t=79.039s dur=100ms, freq=49Hz, sample=31, buffer_id=08:1F
    db 10,0,100,0,43,76,9,12,98,0,43,8  ; n1681 t=79.039s dur=100ms, freq=98Hz, sample=43, buffer_id=08:2B
    db 58,0,100,0,67,125,8,13,136,1,67,8  ; n1682 t=79.049s dur=100ms, freq=392Hz, sample=67, buffer_id=08:43
    db 29,0,56,1,79,125,5,4,228,2,79,5  ; n1683 t=79.106s dur=312ms, freq=740Hz, sample=79, buffer_id=05:4F [TRUNCATE prev:ch4 @78582.3ms -> 79106.3ms]
    db 5,0,100,0,63,125,8,5,55,1,63,8  ; n1684 t=79.135s dur=100ms, freq=311Hz, sample=63, buffer_id=08:3F [TRUNCATE prev:ch5 @78587.1ms -> 79135.2ms]
    db 0,0,100,0,51,125,5,0,156,0,51,5  ; n1685 t=79.140s dur=100ms, freq=156Hz, sample=51, buffer_id=05:33 [TRUNCATE prev:ch0 @78851.5ms -> 79140.0ms]
    db 0,0,100,0,67,125,8,10,136,1,67,8  ; n1686 t=79.140s dur=100ms, freq=392Hz, sample=67, buffer_id=08:43 [TRUNCATE prev:ch10 @78861.2ms -> 79140.0ms]
    db 0,0,100,0,27,76,9,3,39,0,27,8  ; n1687 t=79.140s dur=100ms, freq=39Hz, sample=27, buffer_id=08:1B [TRUNCATE prev:ch3 @78851.5ms -> 79140.0ms]
    db 24,0,100,0,38,76,9,8,78,0,38,8  ; n1688 t=79.140s dur=100ms, freq=78Hz, sample=38, buffer_id=08:26 [TRUNCATE prev:ch8 @78851.5ms -> 79140.0ms]
    db 62,0,42,1,78,124,4,1,228,2,78,4  ; n1689 t=79.164s dur=298ms, freq=740Hz, sample=78, buffer_id=04:4E [TRUNCATE prev:ch1 @78947.7ms -> 79164.0ms]
    db 0,0,100,0,51,125,5,2,156,0,51,5  ; n1690 t=79.227s dur=100ms, freq=156Hz, sample=51, buffer_id=05:33 [TRUNCATE prev:ch2 @78947.7ms -> 79226.5ms]
    db 0,0,100,0,38,76,9,6,78,0,38,8  ; n1691 t=79.227s dur=100ms, freq=78Hz, sample=38, buffer_id=08:26 [TRUNCATE prev:ch6 @78947.7ms -> 79226.5ms]
    db 5,0,100,0,27,76,9,7,39,0,27,8  ; n1692 t=79.227s dur=100ms, freq=39Hz, sample=27, buffer_id=08:1B [TRUNCATE prev:ch7 @78952.5ms -> 79226.5ms]
    db 5,0,100,0,67,125,8,13,136,1,67,8  ; n1693 t=79.231s dur=100ms, freq=392Hz, sample=67, buffer_id=08:43 [TRUNCATE prev:ch13 @79048.7ms -> 79231.3ms]
    db 82,0,100,0,63,125,8,5,55,1,63,8  ; n1694 t=79.236s dur=100ms, freq=311Hz, sample=63, buffer_id=08:3F [TRUNCATE prev:ch5 @79135.2ms -> 79236.2ms]
    db 5,0,100,0,67,125,8,10,136,1,67,8  ; n1695 t=79.318s dur=100ms, freq=392Hz, sample=67, buffer_id=08:43 [TRUNCATE prev:ch10 @79140.0ms -> 79317.9ms]
    db 0,0,100,0,51,125,5,0,156,0,51,5  ; n1696 t=79.323s dur=100ms, freq=156Hz, sample=51, buffer_id=05:33 [TRUNCATE prev:ch0 @79140.0ms -> 79322.7ms]
    db 0,0,100,0,27,76,9,3,39,0,27,8  ; n1697 t=79.323s dur=100ms, freq=39Hz, sample=27, buffer_id=08:1B [TRUNCATE prev:ch3 @79140.0ms -> 79322.7ms]
    db 10,0,100,0,38,76,9,8,78,0,38,8  ; n1698 t=79.323s dur=100ms, freq=78Hz, sample=38, buffer_id=08:26 [TRUNCATE prev:ch8 @79140.0ms -> 79322.7ms]
    db 87,0,100,0,63,125,8,9,55,1,63,8  ; n1699 t=79.332s dur=100ms, freq=311Hz, sample=63, buffer_id=08:3F [TRUNCATE prev:ch9 @79039.0ms -> 79332.3ms]
    db 5,0,100,0,67,125,8,11,136,1,67,8  ; n1700 t=79.419s dur=100ms, freq=392Hz, sample=67, buffer_id=08:43
    db 0,0,100,0,51,125,5,12,156,0,51,5  ; n1701 t=79.424s dur=100ms, freq=156Hz, sample=51, buffer_id=05:33
    db 0,0,100,0,63,125,8,5,55,1,63,8  ; n1702 t=79.424s dur=100ms, freq=311Hz, sample=63, buffer_id=08:3F [TRUNCATE prev:ch5 @79236.2ms -> 79423.7ms]
    db 0,0,100,0,27,76,9,7,39,0,27,8  ; n1703 t=79.424s dur=100ms, freq=39Hz, sample=27, buffer_id=08:1B [TRUNCATE prev:ch7 @79226.5ms -> 79423.7ms]
    db 154,0,100,0,38,76,9,6,78,0,38,8  ; n1704 t=79.424s dur=100ms, freq=78Hz, sample=38, buffer_id=08:26 [TRUNCATE prev:ch6 @79226.5ms -> 79423.7ms]
    db 29,0,100,0,79,125,5,2,186,2,79,5  ; n1705 t=79.578s dur=100ms, freq=698Hz, sample=79, buffer_id=05:4F
    db 96,0,100,0,77,124,4,13,186,2,77,4  ; n1706 t=79.606s dur=100ms, freq=698Hz, sample=77, buffer_id=04:4D
    db 5,0,134,0,74,125,5,0,147,2,74,5  ; n1707 t=79.703s dur=134ms, freq=659Hz, sample=74, buffer_id=05:4A
    db 0,0,100,0,63,125,5,1,21,1,63,5  ; n1708 t=79.707s dur=100ms, freq=277Hz, sample=63, buffer_id=05:3F
    db 14,0,100,0,50,76,9,3,139,0,50,8  ; n1709 t=79.707s dur=100ms, freq=139Hz, sample=50, buffer_id=08:32
    db 0,0,100,0,68,125,8,4,159,1,68,8  ; n1710 t=79.722s dur=100ms, freq=415Hz, sample=68, buffer_id=08:44
    db 5,0,100,0,63,125,8,8,74,1,63,8  ; n1711 t=79.722s dur=100ms, freq=330Hz, sample=63, buffer_id=08:3F
    db 10,0,100,0,38,76,9,5,69,0,38,8  ; n1712 t=79.727s dur=100ms, freq=69Hz, sample=38, buffer_id=08:26
    db 135,0,105,0,75,124,4,6,147,2,75,4  ; n1713 t=79.736s dur=105ms, freq=659Hz, sample=75, buffer_id=04:4B
    db 24,0,100,0,75,124,4,7,110,2,75,4  ; n1714 t=79.871s dur=100ms, freq=622Hz, sample=75, buffer_id=04:4B
    db 91,0,100,0,74,125,5,2,110,2,74,5  ; n1715 t=79.895s dur=100ms, freq=622Hz, sample=74, buffer_id=05:4A
    db 14,0,187,0,75,124,4,9,147,2,75,4  ; n1716 t=79.986s dur=187ms, freq=659Hz, sample=75, buffer_id=04:4B
    db 18,1,129,0,74,125,5,10,147,2,74,5  ; n1717 t=80.001s dur=129ms, freq=659Hz, sample=74, buffer_id=05:4A
    db 0,0,100,0,63,125,5,0,21,1,63,5  ; n1718 t=80.275s dur=100ms, freq=277Hz, sample=63, buffer_id=05:3F
    db 14,0,100,0,50,76,9,1,139,0,50,8  ; n1719 t=80.275s dur=100ms, freq=139Hz, sample=50, buffer_id=08:32
    db 14,0,100,0,38,76,9,2,69,0,38,8  ; n1720 t=80.289s dur=100ms, freq=69Hz, sample=38, buffer_id=08:26
    db 0,0,100,0,63,125,8,3,74,1,63,8  ; n1721 t=80.303s dur=100ms, freq=330Hz, sample=63, buffer_id=08:3F
    db 18,1,100,0,68,125,8,5,159,1,68,8  ; n1722 t=80.303s dur=100ms, freq=415Hz, sample=68, buffer_id=08:44
    db 0,0,100,0,63,125,5,1,21,1,63,5  ; n1723 t=80.578s dur=100ms, freq=277Hz, sample=63, buffer_id=05:3F
    db 0,0,100,0,38,76,9,0,69,0,38,8  ; n1724 t=80.578s dur=100ms, freq=69Hz, sample=38, buffer_id=08:26
    db 5,0,100,0,50,76,9,4,139,0,50,8  ; n1725 t=80.578s dur=100ms, freq=139Hz, sample=50, buffer_id=08:32
    db 10,0,105,0,70,124,4,6,159,1,70,4  ; n1726 t=80.582s dur=105ms, freq=415Hz, sample=70, buffer_id=04:46
    db 14,0,110,0,69,125,5,2,159,1,69,5  ; n1727 t=80.592s dur=110ms, freq=415Hz, sample=69, buffer_id=05:45
    db 0,0,100,0,63,125,8,5,74,1,63,8  ; n1728 t=80.606s dur=100ms, freq=330Hz, sample=63, buffer_id=08:3F
    db 67,0,100,0,68,125,8,3,159,1,68,8  ; n1729 t=80.606s dur=100ms, freq=415Hz, sample=68, buffer_id=08:44
    db 0,0,100,0,63,125,5,7,21,1,63,5  ; n1730 t=80.674s dur=100ms, freq=277Hz, sample=63, buffer_id=05:3F
    db 0,0,100,0,38,76,9,8,69,0,38,8  ; n1731 t=80.674s dur=100ms, freq=69Hz, sample=38, buffer_id=08:26
    db 14,0,100,0,50,76,9,9,139,0,50,8  ; n1732 t=80.674s dur=100ms, freq=139Hz, sample=50, buffer_id=08:32
    db 0,0,100,0,63,125,8,10,74,1,63,8  ; n1733 t=80.688s dur=100ms, freq=330Hz, sample=63, buffer_id=08:3F
    db 82,0,100,0,68,125,8,11,159,1,68,8  ; n1734 t=80.688s dur=100ms, freq=415Hz, sample=68, buffer_id=08:44
    db 0,0,100,0,63,125,5,12,21,1,63,5  ; n1735 t=80.770s dur=100ms, freq=277Hz, sample=63, buffer_id=05:3F
    db 0,0,100,0,38,76,9,13,69,0,38,8  ; n1736 t=80.770s dur=100ms, freq=69Hz, sample=38, buffer_id=08:26
    db 14,0,100,0,50,76,9,4,139,0,50,8  ; n1737 t=80.770s dur=100ms, freq=139Hz, sample=50, buffer_id=08:32 [TRUNCATE prev:ch4 @80577.5ms -> 80769.8ms]
    db 0,0,100,0,63,125,8,5,74,1,63,8  ; n1738 t=80.784s dur=100ms, freq=330Hz, sample=63, buffer_id=08:3F [TRUNCATE prev:ch5 @80606.3ms -> 80784.2ms]
    db 72,0,100,0,68,125,8,3,159,1,68,8  ; n1739 t=80.784s dur=100ms, freq=415Hz, sample=68, buffer_id=08:44 [TRUNCATE prev:ch3 @80606.3ms -> 80784.2ms]
    db 0,0,100,0,63,125,8,10,74,1,63,8  ; n1740 t=80.856s dur=100ms, freq=330Hz, sample=63, buffer_id=08:3F [TRUNCATE prev:ch10 @80688.1ms -> 80856.3ms]
    db 10,0,100,0,68,125,8,11,159,1,68,8  ; n1741 t=80.856s dur=100ms, freq=415Hz, sample=68, buffer_id=08:44 [TRUNCATE prev:ch11 @80688.1ms -> 80856.3ms]
    db 0,0,100,0,63,125,5,1,21,1,63,5  ; n1742 t=80.866s dur=100ms, freq=277Hz, sample=63, buffer_id=05:3F [TRUNCATE prev:ch1 @80577.5ms -> 80866.0ms]
    db 0,0,100,0,38,76,9,0,69,0,38,8  ; n1743 t=80.866s dur=100ms, freq=69Hz, sample=38, buffer_id=08:26 [TRUNCATE prev:ch0 @80577.5ms -> 80866.0ms]
    db 14,0,100,0,50,76,9,9,139,0,50,8  ; n1744 t=80.866s dur=100ms, freq=139Hz, sample=50, buffer_id=08:32 [TRUNCATE prev:ch9 @80673.7ms -> 80866.0ms]
    db 10,0,128,1,74,125,5,6,42,2,74,5  ; n1745 t=80.880s dur=384ms, freq=554Hz, sample=74, buffer_id=05:4A [TRUNCATE prev:ch6 @80582.3ms -> 80880.4ms]
    db 255,0,176,1,72,124,4,2,42,2,72,4  ; n1746 t=80.890s dur=432ms, freq=554Hz, sample=72, buffer_id=04:48 [TRUNCATE prev:ch2 @80591.9ms -> 80890.0ms]
    db 0,0,100,0,63,125,5,3,21,1,63,5  ; n1747 t=81.145s dur=100ms, freq=277Hz, sample=63, buffer_id=05:3F
    db 0,0,100,0,50,76,9,5,139,0,50,8  ; n1748 t=81.145s dur=100ms, freq=139Hz, sample=50, buffer_id=08:32
    db 34,0,100,0,38,76,9,4,69,0,38,8  ; n1749 t=81.145s dur=100ms, freq=69Hz, sample=38, buffer_id=08:26
    db 0,0,100,0,63,125,8,0,74,1,63,8  ; n1750 t=81.178s dur=100ms, freq=330Hz, sample=63, buffer_id=08:3F
    db 62,0,100,0,68,125,8,1,159,1,68,8  ; n1751 t=81.178s dur=100ms, freq=415Hz, sample=68, buffer_id=08:44
    db 0,0,100,0,63,125,5,8,21,1,63,5  ; n1752 t=81.241s dur=100ms, freq=277Hz, sample=63, buffer_id=05:3F
    db 0,0,100,0,38,76,9,7,69,0,38,8  ; n1753 t=81.241s dur=100ms, freq=69Hz, sample=38, buffer_id=08:26
    db 34,0,100,0,50,76,9,10,139,0,50,8  ; n1754 t=81.241s dur=100ms, freq=139Hz, sample=50, buffer_id=08:32
    db 0,0,100,0,63,125,8,9,74,1,63,8  ; n1755 t=81.275s dur=100ms, freq=330Hz, sample=63, buffer_id=08:3F
    db 72,0,100,0,68,125,8,12,159,1,68,8  ; n1756 t=81.275s dur=100ms, freq=415Hz, sample=68, buffer_id=08:44
    db 0,0,100,0,63,125,5,11,21,1,63,5  ; n1757 t=81.347s dur=100ms, freq=277Hz, sample=63, buffer_id=05:3F
    db 0,0,100,0,38,76,9,13,69,0,38,8  ; n1758 t=81.347s dur=100ms, freq=69Hz, sample=38, buffer_id=08:26 [TRUNCATE prev:ch13 @80769.8ms -> 81346.7ms]
    db 10,0,100,0,50,76,9,5,139,0,50,8  ; n1759 t=81.347s dur=100ms, freq=139Hz, sample=50, buffer_id=08:32 [TRUNCATE prev:ch5 @81144.8ms -> 81346.7ms]
    db 0,0,100,0,63,125,8,0,74,1,63,8  ; n1760 t=81.356s dur=100ms, freq=330Hz, sample=63, buffer_id=08:3F [TRUNCATE prev:ch0 @81178.5ms -> 81356.3ms]
    db 87,0,100,0,68,125,8,1,159,1,68,8  ; n1761 t=81.356s dur=100ms, freq=415Hz, sample=68, buffer_id=08:44 [TRUNCATE prev:ch1 @81178.5ms -> 81356.3ms]
    db 0,0,100,0,63,125,5,3,21,1,63,5  ; n1762 t=81.443s dur=100ms, freq=277Hz, sample=63, buffer_id=05:3F [TRUNCATE prev:ch3 @81144.8ms -> 81442.9ms]
    db 0,0,100,0,68,125,8,12,159,1,68,8  ; n1763 t=81.443s dur=100ms, freq=415Hz, sample=68, buffer_id=08:44 [TRUNCATE prev:ch12 @81274.6ms -> 81442.9ms]
    db 0,0,100,0,63,125,8,9,74,1,63,8  ; n1764 t=81.443s dur=100ms, freq=330Hz, sample=63, buffer_id=08:3F [TRUNCATE prev:ch9 @81274.6ms -> 81442.9ms]
    db 0,0,100,0,38,76,9,4,69,0,38,8  ; n1765 t=81.443s dur=100ms, freq=69Hz, sample=38, buffer_id=08:26 [TRUNCATE prev:ch4 @81144.8ms -> 81442.9ms]
    db 14,0,100,0,50,76,9,10,139,0,50,8  ; n1766 t=81.443s dur=100ms, freq=139Hz, sample=50, buffer_id=08:32 [TRUNCATE prev:ch10 @81241.0ms -> 81442.9ms]
    db 0,0,104,1,72,124,4,2,11,2,72,4  ; n1767 t=81.457s dur=360ms, freq=523Hz, sample=72, buffer_id=04:48 [TRUNCATE prev:ch2 @80890.0ms -> 81457.3ms]
    db 82,0,61,1,74,125,5,6,11,2,74,5  ; n1768 t=81.457s dur=317ms, freq=523Hz, sample=74, buffer_id=05:4A [TRUNCATE prev:ch6 @80880.4ms -> 81457.3ms]
    db 0,0,100,0,63,125,5,8,21,1,63,5  ; n1769 t=81.539s dur=100ms, freq=277Hz, sample=63, buffer_id=05:3F [TRUNCATE prev:ch8 @81241.0ms -> 81539.0ms]
    db 0,0,100,0,38,76,9,7,69,0,38,8  ; n1770 t=81.539s dur=100ms, freq=69Hz, sample=38, buffer_id=08:26 [TRUNCATE prev:ch7 @81241.0ms -> 81539.0ms]
    db 5,0,100,0,50,76,9,5,139,0,50,8  ; n1771 t=81.539s dur=100ms, freq=139Hz, sample=50, buffer_id=08:32 [TRUNCATE prev:ch5 @81346.7ms -> 81539.0ms]
    db 0,0,100,0,63,125,8,0,74,1,63,8  ; n1772 t=81.544s dur=100ms, freq=330Hz, sample=63, buffer_id=08:3F [TRUNCATE prev:ch0 @81356.3ms -> 81543.8ms]
    db 72,0,100,0,68,125,8,1,159,1,68,8  ; n1773 t=81.544s dur=100ms, freq=415Hz, sample=68, buffer_id=08:44 [TRUNCATE prev:ch1 @81356.3ms -> 81543.8ms]
    db 0,0,100,0,63,125,8,9,74,1,63,8  ; n1774 t=81.616s dur=100ms, freq=330Hz, sample=63, buffer_id=08:3F [TRUNCATE prev:ch9 @81442.9ms -> 81616.0ms]
    db 10,0,100,0,68,125,8,12,159,1,68,8  ; n1775 t=81.616s dur=100ms, freq=415Hz, sample=68, buffer_id=08:44 [TRUNCATE prev:ch12 @81442.9ms -> 81616.0ms]
    db 0,0,100,0,63,125,5,11,21,1,63,5  ; n1776 t=81.626s dur=100ms, freq=277Hz, sample=63, buffer_id=05:3F [TRUNCATE prev:ch11 @81346.7ms -> 81625.6ms]
    db 0,0,100,0,38,76,9,13,69,0,38,8  ; n1777 t=81.626s dur=100ms, freq=69Hz, sample=38, buffer_id=08:26 [TRUNCATE prev:ch13 @81346.7ms -> 81625.6ms]
    db 101,0,100,0,50,76,9,10,139,0,50,8  ; n1778 t=81.626s dur=100ms, freq=139Hz, sample=50, buffer_id=08:32 [TRUNCATE prev:ch10 @81442.9ms -> 81625.6ms]
    db 0,0,100,0,63,125,8,0,74,1,63,8  ; n1779 t=81.727s dur=100ms, freq=330Hz, sample=63, buffer_id=08:3F [TRUNCATE prev:ch0 @81543.8ms -> 81726.5ms]
    db 5,0,100,0,68,125,8,1,159,1,68,8  ; n1780 t=81.727s dur=100ms, freq=415Hz, sample=68, buffer_id=08:44 [TRUNCATE prev:ch1 @81543.8ms -> 81726.5ms]
    db 0,0,100,0,63,125,5,3,21,1,63,5  ; n1781 t=81.731s dur=100ms, freq=277Hz, sample=63, buffer_id=05:3F [TRUNCATE prev:ch3 @81442.9ms -> 81731.3ms]
    db 0,0,100,0,38,76,9,4,69,0,38,8  ; n1782 t=81.731s dur=100ms, freq=69Hz, sample=38, buffer_id=08:26 [TRUNCATE prev:ch4 @81442.9ms -> 81731.3ms]
    db 159,0,100,0,50,76,9,5,139,0,50,8  ; n1783 t=81.731s dur=100ms, freq=139Hz, sample=50, buffer_id=08:32 [TRUNCATE prev:ch5 @81539.0ms -> 81731.3ms]
    db 10,0,105,0,69,125,5,7,238,1,69,5  ; n1784 t=81.890s dur=105ms, freq=494Hz, sample=69, buffer_id=05:45
    db 115,0,101,0,70,124,4,8,238,1,70,4  ; n1785 t=81.900s dur=101ms, freq=494Hz, sample=70, buffer_id=04:46
    db 0,0,100,0,63,125,5,6,55,1,63,5  ; n1786 t=82.015s dur=100ms, freq=311Hz, sample=63, buffer_id=05:3F
    db 10,0,100,0,50,76,9,9,156,0,50,8  ; n1787 t=82.015s dur=100ms, freq=156Hz, sample=50, buffer_id=08:32
    db 10,0,100,0,38,76,9,2,78,0,38,8  ; n1788 t=82.025s dur=100ms, freq=78Hz, sample=38, buffer_id=08:26
    db 0,0,100,0,63,125,8,1,55,1,63,8  ; n1789 t=82.034s dur=100ms, freq=311Hz, sample=63, buffer_id=08:3F
    db 10,0,100,0,65,125,8,0,114,1,65,8  ; n1790 t=82.034s dur=100ms, freq=370Hz, sample=65, buffer_id=08:41
    db 5,0,110,0,69,125,5,3,210,1,69,5  ; n1791 t=82.044s dur=110ms, freq=466Hz, sample=69, buffer_id=05:45
    db 125,0,105,0,70,124,4,4,210,1,70,4  ; n1792 t=82.049s dur=105ms, freq=466Hz, sample=70, buffer_id=04:46
    db 14,0,100,0,69,125,5,5,184,1,69,5  ; n1793 t=82.174s dur=100ms, freq=440Hz, sample=69, buffer_id=05:45
    db 135,0,100,0,70,124,4,10,184,1,70,4  ; n1794 t=82.188s dur=100ms, freq=440Hz, sample=70, buffer_id=04:46
    db 14,0,125,0,69,125,5,6,210,1,69,5  ; n1795 t=82.323s dur=125ms, freq=466Hz, sample=69, buffer_id=05:45
    db 245,0,100,0,70,124,4,0,210,1,70,4  ; n1796 t=82.337s dur=100ms, freq=466Hz, sample=70, buffer_id=04:46
    db 0,0,100,0,63,125,5,1,55,1,63,5  ; n1797 t=82.582s dur=100ms, freq=311Hz, sample=63, buffer_id=05:3F
    db 0,0,100,0,63,125,8,2,55,1,63,8  ; n1798 t=82.582s dur=100ms, freq=311Hz, sample=63, buffer_id=08:3F
    db 0,0,100,0,65,125,8,3,114,1,65,8  ; n1799 t=82.582s dur=100ms, freq=370Hz, sample=65, buffer_id=08:41
    db 0,0,100,0,38,76,9,4,78,0,38,8  ; n1800 t=82.582s dur=100ms, freq=78Hz, sample=38, buffer_id=08:26
    db 47,1,100,0,50,76,9,5,156,0,50,8  ; n1801 t=82.582s dur=100ms, freq=156Hz, sample=50, buffer_id=08:32
    db 0,0,100,0,63,125,5,0,55,1,63,5  ; n1802 t=82.885s dur=100ms, freq=311Hz, sample=63, buffer_id=05:3F
    db 0,0,100,0,63,125,8,1,55,1,63,8  ; n1803 t=82.885s dur=100ms, freq=311Hz, sample=63, buffer_id=08:3F
    db 0,0,100,0,65,125,8,2,114,1,65,8  ; n1804 t=82.885s dur=100ms, freq=370Hz, sample=65, buffer_id=08:41
    db 0,0,100,0,50,76,9,3,156,0,50,8  ; n1805 t=82.885s dur=100ms, freq=156Hz, sample=50, buffer_id=08:32
    db 24,0,100,0,38,76,9,5,78,0,38,8  ; n1806 t=82.885s dur=100ms, freq=78Hz, sample=38, buffer_id=08:26
    db 5,0,100,0,63,125,5,4,55,1,63,5  ; n1807 t=82.909s dur=100ms, freq=311Hz, sample=63, buffer_id=05:3F
    db 67,0,101,0,65,124,4,6,55,1,65,4  ; n1808 t=82.914s dur=101ms, freq=311Hz, sample=65, buffer_id=04:41
    db 0,0,100,0,63,125,5,7,55,1,63,5  ; n1809 t=82.981s dur=100ms, freq=311Hz, sample=63, buffer_id=05:3F
    db 0,0,100,0,63,125,8,8,55,1,63,8  ; n1810 t=82.981s dur=100ms, freq=311Hz, sample=63, buffer_id=08:3F
    db 0,0,100,0,65,125,8,9,114,1,65,8  ; n1811 t=82.981s dur=100ms, freq=370Hz, sample=65, buffer_id=08:41
    db 0,0,100,0,38,76,9,10,78,0,38,8  ; n1812 t=82.981s dur=100ms, freq=78Hz, sample=38, buffer_id=08:26
    db 91,0,100,0,50,76,9,11,156,0,50,8  ; n1813 t=82.981s dur=100ms, freq=156Hz, sample=50, buffer_id=08:32
    db 0,0,100,0,63,125,5,12,55,1,63,5  ; n1814 t=83.073s dur=100ms, freq=311Hz, sample=63, buffer_id=05:3F
    db 5,0,100,0,50,76,9,13,156,0,50,8  ; n1815 t=83.073s dur=100ms, freq=156Hz, sample=50, buffer_id=08:32
    db 0,0,100,0,63,125,8,1,55,1,63,8  ; n1816 t=83.078s dur=100ms, freq=311Hz, sample=63, buffer_id=08:3F [TRUNCATE prev:ch1 @82885.2ms -> 83077.5ms]
    db 0,0,100,0,65,125,8,2,114,1,65,8  ; n1817 t=83.078s dur=100ms, freq=370Hz, sample=65, buffer_id=08:41 [TRUNCATE prev:ch2 @82885.2ms -> 83077.5ms]
    db 96,0,100,0,38,76,9,5,78,0,38,8  ; n1818 t=83.078s dur=100ms, freq=78Hz, sample=38, buffer_id=08:26 [TRUNCATE prev:ch5 @82885.2ms -> 83077.5ms]
    db 0,0,120,0,63,125,5,0,38,1,63,5  ; n1819 t=83.174s dur=120ms, freq=294Hz, sample=63, buffer_id=05:3F [TRUNCATE prev:ch0 @82885.2ms -> 83173.7ms]
    db 0,0,100,0,63,125,8,8,55,1,63,8  ; n1820 t=83.174s dur=100ms, freq=311Hz, sample=63, buffer_id=08:3F [TRUNCATE prev:ch8 @82981.3ms -> 83173.7ms]
    db 0,0,100,0,65,125,8,9,114,1,65,8  ; n1821 t=83.174s dur=100ms, freq=370Hz, sample=65, buffer_id=08:41 [TRUNCATE prev:ch9 @82981.3ms -> 83173.7ms]
    db 0,0,120,0,50,76,9,3,147,0,50,8  ; n1822 t=83.174s dur=120ms, freq=147Hz, sample=50, buffer_id=08:32 [TRUNCATE prev:ch3 @82885.2ms -> 83173.7ms]
    db 19,0,149,0,38,76,9,10,73,0,38,8  ; n1823 t=83.174s dur=149ms, freq=73Hz, sample=38, buffer_id=08:26 [TRUNCATE prev:ch10 @82981.3ms -> 83173.7ms]
    db 5,0,147,1,65,124,4,6,114,1,65,4  ; n1824 t=83.193s dur=403ms, freq=370Hz, sample=65, buffer_id=04:41 [TRUNCATE prev:ch6 @82914.0ms -> 83192.9ms]
    db 41,2,90,1,63,125,5,4,114,1,63,5  ; n1825 t=83.198s dur=346ms, freq=370Hz, sample=63, buffer_id=05:3F [TRUNCATE prev:ch4 @82909.2ms -> 83197.7ms]
    db 0,0,100,0,58,125,5,0,6,1,58,5  ; n1826 t=83.751s dur=100ms, freq=262Hz, sample=58, buffer_id=05:3A
    db 0,0,100,0,63,125,8,2,55,1,63,8  ; n1827 t=83.751s dur=100ms, freq=311Hz, sample=63, buffer_id=08:3F
    db 0,0,100,0,65,125,8,1,114,1,65,8  ; n1828 t=83.751s dur=100ms, freq=370Hz, sample=65, buffer_id=08:41
    db 0,0,100,0,38,76,9,3,65,0,38,8  ; n1829 t=83.751s dur=100ms, freq=65Hz, sample=38, buffer_id=08:26
    db 14,0,100,0,47,76,9,4,131,0,47,8  ; n1830 t=83.751s dur=100ms, freq=131Hz, sample=47, buffer_id=08:2F
    db 19,0,104,1,65,124,4,5,55,1,65,4  ; n1831 t=83.765s dur=360ms, freq=311Hz, sample=65, buffer_id=04:41
    db 62,0,70,1,63,125,5,8,55,1,63,5  ; n1832 t=83.784s dur=326ms, freq=311Hz, sample=63, buffer_id=05:3F
    db 0,0,100,0,58,125,5,6,6,1,58,5  ; n1833 t=83.847s dur=100ms, freq=262Hz, sample=58, buffer_id=05:3A
    db 0,0,100,0,63,125,8,7,55,1,63,8  ; n1834 t=83.847s dur=100ms, freq=311Hz, sample=63, buffer_id=08:3F
    db 0,0,100,0,65,125,8,10,114,1,65,8  ; n1835 t=83.847s dur=100ms, freq=370Hz, sample=65, buffer_id=08:41
    db 0,0,100,0,47,76,9,9,131,0,47,8  ; n1836 t=83.847s dur=100ms, freq=131Hz, sample=47, buffer_id=08:2F
    db 87,0,100,0,38,76,9,11,65,0,38,8  ; n1837 t=83.847s dur=100ms, freq=65Hz, sample=38, buffer_id=08:26
    db 0,0,100,0,58,125,5,12,6,1,58,5  ; n1838 t=83.933s dur=100ms, freq=262Hz, sample=58, buffer_id=05:3A
    db 0,0,100,0,63,125,8,13,55,1,63,8  ; n1839 t=83.933s dur=100ms, freq=311Hz, sample=63, buffer_id=08:3F
    db 0,0,100,0,65,125,8,1,114,1,65,8  ; n1840 t=83.933s dur=100ms, freq=370Hz, sample=65, buffer_id=08:41 [TRUNCATE prev:ch1 @83750.6ms -> 83933.3ms]
    db 0,0,100,0,38,76,9,3,65,0,38,8  ; n1841 t=83.933s dur=100ms, freq=65Hz, sample=38, buffer_id=08:26 [TRUNCATE prev:ch3 @83750.6ms -> 83933.3ms]
    db 106,0,100,0,47,76,9,4,131,0,47,8  ; n1842 t=83.933s dur=100ms, freq=131Hz, sample=47, buffer_id=08:2F [TRUNCATE prev:ch4 @83750.6ms -> 83933.3ms]
    db 0,0,100,0,58,125,5,0,6,1,58,5  ; n1843 t=84.039s dur=100ms, freq=262Hz, sample=58, buffer_id=05:3A [TRUNCATE prev:ch0 @83750.6ms -> 84039.0ms]
    db 0,0,100,0,63,125,8,2,55,1,63,8  ; n1844 t=84.039s dur=100ms, freq=311Hz, sample=63, buffer_id=08:3F [TRUNCATE prev:ch2 @83750.6ms -> 84039.0ms]
    db 0,0,100,0,65,125,8,10,114,1,65,8  ; n1845 t=84.039s dur=100ms, freq=370Hz, sample=65, buffer_id=08:41 [TRUNCATE prev:ch10 @83846.7ms -> 84039.0ms]
    db 0,0,100,0,47,76,9,9,131,0,47,8  ; n1846 t=84.039s dur=100ms, freq=131Hz, sample=47, buffer_id=08:2F [TRUNCATE prev:ch9 @83846.7ms -> 84039.0ms]
    db 168,0,100,0,38,76,9,11,65,0,38,8  ; n1847 t=84.039s dur=100ms, freq=65Hz, sample=38, buffer_id=08:26 [TRUNCATE prev:ch11 @83846.7ms -> 84039.0ms]
    db 5,0,100,0,65,124,4,6,114,1,65,4  ; n1848 t=84.207s dur=100ms, freq=370Hz, sample=65, buffer_id=04:41
    db 120,0,100,0,63,125,5,7,114,1,63,5  ; n1849 t=84.212s dur=100ms, freq=370Hz, sample=63, buffer_id=05:3F
    db 0,0,100,0,55,125,5,1,196,0,55,5  ; n1850 t=84.332s dur=100ms, freq=196Hz, sample=55, buffer_id=05:37
    db 0,0,100,0,67,125,8,3,136,1,67,8  ; n1851 t=84.332s dur=100ms, freq=392Hz, sample=67, buffer_id=08:43
    db 0,0,100,0,31,76,9,4,49,0,31,8  ; n1852 t=84.332s dur=100ms, freq=49Hz, sample=31, buffer_id=08:1F
    db 24,0,100,0,43,76,9,5,98,0,43,8  ; n1853 t=84.332s dur=100ms, freq=98Hz, sample=43, buffer_id=08:2B
    db 19,0,143,1,70,124,4,0,210,1,70,4  ; n1854 t=84.356s dur=399ms, freq=466Hz, sample=70, buffer_id=04:46
    db 17,2,133,1,69,125,5,2,210,1,69,5  ; n1855 t=84.376s dur=389ms, freq=466Hz, sample=69, buffer_id=05:45
    db 0,0,100,0,63,125,5,1,55,1,63,5  ; n1856 t=84.904s dur=100ms, freq=311Hz, sample=63, buffer_id=05:3F
    db 0,0,100,0,63,125,8,3,55,1,63,8  ; n1857 t=84.904s dur=100ms, freq=311Hz, sample=63, buffer_id=08:3F
    db 0,0,100,0,67,125,8,4,136,1,67,8  ; n1858 t=84.904s dur=100ms, freq=392Hz, sample=67, buffer_id=08:43
    db 0,0,100,0,50,76,9,5,156,0,50,8  ; n1859 t=84.904s dur=100ms, freq=156Hz, sample=50, buffer_id=08:32
    db 24,0,100,0,38,76,9,6,78,0,38,8  ; n1860 t=84.904s dur=100ms, freq=78Hz, sample=38, buffer_id=08:26
    db 10,0,66,1,69,125,5,7,136,1,69,5  ; n1861 t=84.928s dur=322ms, freq=392Hz, sample=69, buffer_id=05:45
    db 62,0,32,1,65,124,4,8,136,1,65,4  ; n1862 t=84.938s dur=288ms, freq=392Hz, sample=65, buffer_id=04:41
    db 0,0,100,0,63,125,5,0,55,1,63,5  ; n1863 t=85.001s dur=100ms, freq=311Hz, sample=63, buffer_id=05:3F
    db 0,0,100,0,63,125,8,2,55,1,63,8  ; n1864 t=85.001s dur=100ms, freq=311Hz, sample=63, buffer_id=08:3F
    db 0,0,100,0,67,125,8,9,136,1,67,8  ; n1865 t=85.001s dur=100ms, freq=392Hz, sample=67, buffer_id=08:43
    db 0,0,100,0,38,76,9,10,78,0,38,8  ; n1866 t=85.001s dur=100ms, freq=78Hz, sample=38, buffer_id=08:26
    db 87,0,100,0,50,76,9,11,156,0,50,8  ; n1867 t=85.001s dur=100ms, freq=156Hz, sample=50, buffer_id=08:32
    db 0,0,100,0,63,125,5,12,55,1,63,5  ; n1868 t=85.087s dur=100ms, freq=311Hz, sample=63, buffer_id=05:3F
    db 0,0,100,0,63,125,8,13,55,1,63,8  ; n1869 t=85.087s dur=100ms, freq=311Hz, sample=63, buffer_id=08:3F [TRUNCATE prev:ch13 @83933.3ms -> 85087.1ms]
    db 0,0,100,0,67,125,8,4,136,1,67,8  ; n1870 t=85.087s dur=100ms, freq=392Hz, sample=67, buffer_id=08:43 [TRUNCATE prev:ch4 @84904.4ms -> 85087.1ms]
    db 0,0,100,0,50,76,9,5,156,0,50,8  ; n1871 t=85.087s dur=100ms, freq=156Hz, sample=50, buffer_id=08:32 [TRUNCATE prev:ch5 @84904.4ms -> 85087.1ms]
    db 106,0,100,0,38,76,9,6,78,0,38,8  ; n1872 t=85.087s dur=100ms, freq=78Hz, sample=38, buffer_id=08:26 [TRUNCATE prev:ch6 @84904.4ms -> 85087.1ms]
    db 0,0,100,0,63,125,5,1,55,1,63,5  ; n1873 t=85.193s dur=100ms, freq=311Hz, sample=63, buffer_id=05:3F [TRUNCATE prev:ch1 @84904.4ms -> 85192.9ms]
    db 0,0,100,0,63,125,8,3,55,1,63,8  ; n1874 t=85.193s dur=100ms, freq=311Hz, sample=63, buffer_id=08:3F [TRUNCATE prev:ch3 @84904.4ms -> 85192.9ms]
    db 0,0,100,0,67,125,8,9,136,1,67,8  ; n1875 t=85.193s dur=100ms, freq=392Hz, sample=67, buffer_id=08:43 [TRUNCATE prev:ch9 @85000.6ms -> 85192.9ms]
    db 5,0,100,0,50,76,9,11,156,0,50,8  ; n1876 t=85.193s dur=100ms, freq=156Hz, sample=50, buffer_id=08:32 [TRUNCATE prev:ch11 @85000.6ms -> 85192.9ms]
    db 163,0,100,0,38,76,9,10,78,0,38,8  ; n1877 t=85.198s dur=100ms, freq=78Hz, sample=38, buffer_id=08:26 [TRUNCATE prev:ch10 @85000.6ms -> 85197.7ms]
    db 0,0,100,0,70,124,4,0,210,1,70,4  ; n1878 t=85.361s dur=100ms, freq=466Hz, sample=70, buffer_id=04:46
    db 135,0,100,0,69,125,5,2,210,1,69,5  ; n1879 t=85.361s dur=100ms, freq=466Hz, sample=69, buffer_id=05:45
    db 0,0,100,0,55,125,5,1,196,0,55,5  ; n1880 t=85.496s dur=100ms, freq=196Hz, sample=55, buffer_id=05:37
    db 0,0,100,0,67,125,8,3,136,1,67,8  ; n1881 t=85.496s dur=100ms, freq=392Hz, sample=67, buffer_id=08:43
    db 0,0,100,0,43,76,9,4,98,0,43,8  ; n1882 t=85.496s dur=100ms, freq=98Hz, sample=43, buffer_id=08:2B
    db 14,0,100,0,31,76,9,5,49,0,31,8  ; n1883 t=85.496s dur=100ms, freq=49Hz, sample=31, buffer_id=08:1F
    db 5,0,39,3,74,124,4,6,75,2,74,4  ; n1884 t=85.510s dur=807ms, freq=587Hz, sample=74, buffer_id=04:4A
    db 4,1,214,2,74,125,5,7,75,2,74,5  ; n1885 t=85.515s dur=726ms, freq=587Hz, sample=74, buffer_id=05:4A
    db 0,0,100,0,55,125,5,0,196,0,55,5  ; n1886 t=85.775s dur=100ms, freq=196Hz, sample=55, buffer_id=05:37
    db 0,0,100,0,67,125,8,2,136,1,67,8  ; n1887 t=85.775s dur=100ms, freq=392Hz, sample=67, buffer_id=08:43
    db 0,0,100,0,31,76,9,8,49,0,31,8  ; n1888 t=85.775s dur=100ms, freq=49Hz, sample=31, buffer_id=08:1F
    db 96,0,100,0,43,76,9,9,98,0,43,8  ; n1889 t=85.775s dur=100ms, freq=98Hz, sample=43, buffer_id=08:2B
    db 0,0,100,0,55,125,5,3,196,0,55,5  ; n1890 t=85.871s dur=100ms, freq=196Hz, sample=55, buffer_id=05:37
    db 0,0,100,0,67,125,8,1,136,1,67,8  ; n1891 t=85.871s dur=100ms, freq=392Hz, sample=67, buffer_id=08:43
    db 0,0,100,0,43,76,9,5,98,0,43,8  ; n1892 t=85.871s dur=100ms, freq=98Hz, sample=43, buffer_id=08:2B
    db 96,0,100,0,31,76,9,4,49,0,31,8  ; n1893 t=85.871s dur=100ms, freq=49Hz, sample=31, buffer_id=08:1F
    db 0,0,100,0,55,125,5,10,196,0,55,5  ; n1894 t=85.967s dur=100ms, freq=196Hz, sample=55, buffer_id=05:37
    db 0,0,100,0,67,125,8,11,136,1,67,8  ; n1895 t=85.967s dur=100ms, freq=392Hz, sample=67, buffer_id=08:43
    db 0,0,100,0,31,76,9,12,49,0,31,8  ; n1896 t=85.967s dur=100ms, freq=49Hz, sample=31, buffer_id=08:1F
    db 96,0,100,0,43,76,9,13,98,0,43,8  ; n1897 t=85.967s dur=100ms, freq=98Hz, sample=43, buffer_id=08:2B
    db 0,0,100,0,55,125,5,0,196,0,55,5  ; n1898 t=86.063s dur=100ms, freq=196Hz, sample=55, buffer_id=05:37 [TRUNCATE prev:ch0 @85774.6ms -> 86063.1ms]
    db 0,0,100,0,67,125,8,2,136,1,67,8  ; n1899 t=86.063s dur=100ms, freq=392Hz, sample=67, buffer_id=08:43 [TRUNCATE prev:ch2 @85774.6ms -> 86063.1ms]
    db 0,0,100,0,43,76,9,9,98,0,43,8  ; n1900 t=86.063s dur=100ms, freq=98Hz, sample=43, buffer_id=08:2B [TRUNCATE prev:ch9 @85774.6ms -> 86063.1ms]
    db 91,0,100,0,31,76,9,8,49,0,31,8  ; n1901 t=86.063s dur=100ms, freq=49Hz, sample=31, buffer_id=08:1F [TRUNCATE prev:ch8 @85774.6ms -> 86063.1ms]
    db 0,0,100,0,55,125,5,3,196,0,55,5  ; n1902 t=86.154s dur=100ms, freq=196Hz, sample=55, buffer_id=05:37 [TRUNCATE prev:ch3 @85870.8ms -> 86154.4ms]
    db 0,0,100,0,67,125,8,1,136,1,67,8  ; n1903 t=86.154s dur=100ms, freq=392Hz, sample=67, buffer_id=08:43 [TRUNCATE prev:ch1 @85870.8ms -> 86154.4ms]
    db 0,0,100,0,31,76,9,4,49,0,31,8  ; n1904 t=86.154s dur=100ms, freq=49Hz, sample=31, buffer_id=08:1F [TRUNCATE prev:ch4 @85870.8ms -> 86154.4ms]
    db 96,0,100,0,43,76,9,5,98,0,43,8  ; n1905 t=86.154s dur=100ms, freq=98Hz, sample=43, buffer_id=08:2B [TRUNCATE prev:ch5 @85870.8ms -> 86154.4ms]
    db 0,0,100,0,55,125,5,10,196,0,55,5  ; n1906 t=86.251s dur=100ms, freq=196Hz, sample=55, buffer_id=05:37 [TRUNCATE prev:ch10 @85966.9ms -> 86250.6ms]
    db 0,0,100,0,67,125,8,11,136,1,67,8  ; n1907 t=86.251s dur=100ms, freq=392Hz, sample=67, buffer_id=08:43 [TRUNCATE prev:ch11 @85966.9ms -> 86250.6ms]
    db 0,0,100,0,43,76,9,13,98,0,43,8  ; n1908 t=86.251s dur=100ms, freq=98Hz, sample=43, buffer_id=08:2B [TRUNCATE prev:ch13 @85966.9ms -> 86250.6ms]
    db 101,0,100,0,31,76,9,12,49,0,31,8  ; n1909 t=86.251s dur=100ms, freq=49Hz, sample=31, buffer_id=08:1F [TRUNCATE prev:ch12 @85966.9ms -> 86250.6ms]
    db 0,0,100,0,55,125,5,0,196,0,55,5  ; n1910 t=86.352s dur=100ms, freq=196Hz, sample=55, buffer_id=05:37 [TRUNCATE prev:ch0 @86063.1ms -> 86351.5ms]
    db 0,0,100,0,67,125,8,2,136,1,67,8  ; n1911 t=86.352s dur=100ms, freq=392Hz, sample=67, buffer_id=08:43 [TRUNCATE prev:ch2 @86063.1ms -> 86351.5ms]
    db 0,0,100,0,31,76,9,8,49,0,31,8  ; n1912 t=86.352s dur=100ms, freq=49Hz, sample=31, buffer_id=08:1F [TRUNCATE prev:ch8 @86063.1ms -> 86351.5ms]
    db 91,0,100,0,43,76,9,9,98,0,43,8  ; n1913 t=86.352s dur=100ms, freq=98Hz, sample=43, buffer_id=08:2B [TRUNCATE prev:ch9 @86063.1ms -> 86351.5ms]
    db 0,0,100,0,55,125,5,7,196,0,55,5  ; n1914 t=86.443s dur=100ms, freq=196Hz, sample=55, buffer_id=05:37
    db 0,0,100,0,67,125,8,1,136,1,67,8  ; n1915 t=86.443s dur=100ms, freq=392Hz, sample=67, buffer_id=08:43 [TRUNCATE prev:ch1 @86154.4ms -> 86442.9ms]
    db 0,0,100,0,43,76,9,5,98,0,43,8  ; n1916 t=86.443s dur=100ms, freq=98Hz, sample=43, buffer_id=08:2B [TRUNCATE prev:ch5 @86154.4ms -> 86442.9ms]
    db 96,0,100,0,31,76,9,4,49,0,31,8  ; n1917 t=86.443s dur=100ms, freq=49Hz, sample=31, buffer_id=08:1F [TRUNCATE prev:ch4 @86154.4ms -> 86442.9ms]
    db 0,0,100,0,55,125,5,6,196,0,55,5  ; n1918 t=86.539s dur=100ms, freq=196Hz, sample=55, buffer_id=05:37
    db 0,0,100,0,67,125,8,3,136,1,67,8  ; n1919 t=86.539s dur=100ms, freq=392Hz, sample=67, buffer_id=08:43
    db 0,0,100,0,31,76,9,12,49,0,31,8  ; n1920 t=86.539s dur=100ms, freq=49Hz, sample=31, buffer_id=08:1F [TRUNCATE prev:ch12 @86250.6ms -> 86539.0ms]
    db 96,0,100,0,43,76,9,13,98,0,43,8  ; n1921 t=86.539s dur=100ms, freq=98Hz, sample=43, buffer_id=08:2B [TRUNCATE prev:ch13 @86250.6ms -> 86539.0ms]
    db 0,0,100,0,63,125,5,10,55,1,63,5  ; n1922 t=86.635s dur=100ms, freq=311Hz, sample=63, buffer_id=05:3F
    db 0,0,186,1,79,125,5,11,16,3,79,5  ; n1923 t=86.635s dur=442ms, freq=784Hz, sample=79, buffer_id=05:4F
    db 0,0,100,0,50,76,9,0,156,0,50,8  ; n1924 t=86.635s dur=100ms, freq=156Hz, sample=50, buffer_id=08:32 [TRUNCATE prev:ch0 @86351.5ms -> 86635.2ms]
    db 5,0,100,0,38,76,9,2,78,0,38,8  ; n1925 t=86.635s dur=100ms, freq=78Hz, sample=38, buffer_id=08:26 [TRUNCATE prev:ch2 @86351.5ms -> 86635.2ms]
    db 29,0,100,0,67,125,8,1,136,1,67,8  ; n1926 t=86.640s dur=100ms, freq=392Hz, sample=67, buffer_id=08:43 [TRUNCATE prev:ch1 @86442.9ms -> 86640.0ms]
    db 31,2,90,1,78,124,4,8,16,3,78,4  ; n1927 t=86.669s dur=346ms, freq=784Hz, sample=78, buffer_id=04:4E
    db 0,0,211,0,65,124,4,0,136,1,65,4  ; n1928 t=87.212s dur=211ms, freq=392Hz, sample=65, buffer_id=04:41
    db 5,0,100,0,67,125,8,2,136,1,67,8  ; n1929 t=87.212s dur=100ms, freq=392Hz, sample=67, buffer_id=08:43
    db 0,0,100,0,63,125,5,1,55,1,63,5  ; n1930 t=87.217s dur=100ms, freq=311Hz, sample=63, buffer_id=05:3F
    db 0,0,32,1,69,125,5,3,136,1,69,5  ; n1931 t=87.217s dur=288ms, freq=392Hz, sample=69, buffer_id=05:45
    db 0,0,100,0,38,76,9,4,78,0,38,8  ; n1932 t=87.217s dur=100ms, freq=78Hz, sample=38, buffer_id=08:26
    db 42,1,100,0,50,76,9,5,156,0,50,8  ; n1933 t=87.217s dur=100ms, freq=156Hz, sample=50, buffer_id=08:32
    db 0,0,100,0,63,125,5,2,55,1,63,5  ; n1934 t=87.515s dur=100ms, freq=311Hz, sample=63, buffer_id=05:3F
    db 0,0,100,0,50,76,9,6,156,0,50,8  ; n1935 t=87.515s dur=100ms, freq=156Hz, sample=50, buffer_id=08:32
    db 14,0,100,0,38,76,9,7,78,0,38,8  ; n1936 t=87.515s dur=100ms, freq=78Hz, sample=38, buffer_id=08:26
    db 82,0,100,0,67,125,8,1,136,1,67,8  ; n1937 t=87.529s dur=100ms, freq=392Hz, sample=67, buffer_id=08:43
    db 0,0,100,0,63,125,5,4,55,1,63,5  ; n1938 t=87.611s dur=100ms, freq=311Hz, sample=63, buffer_id=05:3F
    db 0,0,100,0,38,76,9,5,78,0,38,8  ; n1939 t=87.611s dur=100ms, freq=78Hz, sample=38, buffer_id=08:26
    db 10,0,100,0,50,76,9,8,156,0,50,8  ; n1940 t=87.611s dur=100ms, freq=156Hz, sample=50, buffer_id=08:32
    db 48,0,100,0,67,125,8,9,136,1,67,8  ; n1941 t=87.621s dur=100ms, freq=392Hz, sample=67, buffer_id=08:43
    db 14,0,110,0,69,125,5,0,136,1,69,5  ; n1942 t=87.669s dur=110ms, freq=392Hz, sample=69, buffer_id=05:45
    db 19,0,100,0,65,124,4,10,136,1,65,4  ; n1943 t=87.683s dur=100ms, freq=392Hz, sample=65, buffer_id=04:41
    db 0,0,100,0,63,125,5,11,55,1,63,5  ; n1944 t=87.703s dur=100ms, freq=311Hz, sample=63, buffer_id=05:3F
    db 0,0,100,0,50,76,9,12,156,0,50,8  ; n1945 t=87.703s dur=100ms, freq=156Hz, sample=50, buffer_id=08:32
    db 10,0,100,0,38,76,9,13,78,0,38,8  ; n1946 t=87.703s dur=100ms, freq=78Hz, sample=38, buffer_id=08:26
    db 77,0,100,0,67,125,8,3,136,1,67,8  ; n1947 t=87.712s dur=100ms, freq=392Hz, sample=67, buffer_id=08:43
    db 5,0,100,0,67,125,8,1,136,1,67,8  ; n1948 t=87.789s dur=100ms, freq=392Hz, sample=67, buffer_id=08:43 [TRUNCATE prev:ch1 @87529.4ms -> 87789.0ms]
    db 0,0,100,0,55,125,5,2,196,0,55,5  ; n1949 t=87.794s dur=100ms, freq=196Hz, sample=55, buffer_id=05:37 [TRUNCATE prev:ch2 @87515.0ms -> 87793.8ms]
    db 0,0,100,0,31,76,9,6,49,0,31,8  ; n1950 t=87.794s dur=100ms, freq=49Hz, sample=31, buffer_id=08:1F [TRUNCATE prev:ch6 @87515.0ms -> 87793.8ms]
    db 19,0,100,0,43,76,9,7,98,0,43,8  ; n1951 t=87.794s dur=100ms, freq=98Hz, sample=43, buffer_id=08:2B [TRUNCATE prev:ch7 @87515.0ms -> 87793.8ms]
    db 5,0,109,1,79,125,5,4,16,3,79,5  ; n1952 t=87.813s dur=365ms, freq=784Hz, sample=79, buffer_id=05:4F [TRUNCATE prev:ch4 @87611.2ms -> 87813.1ms]
    db 8,1,133,1,78,124,4,5,16,3,78,4  ; n1953 t=87.818s dur=389ms, freq=784Hz, sample=78, buffer_id=04:4E [TRUNCATE prev:ch5 @87611.2ms -> 87817.9ms]
    db 0,0,100,0,55,125,5,0,196,0,55,5  ; n1954 t=88.082s dur=100ms, freq=196Hz, sample=55, buffer_id=05:37
    db 0,0,100,0,43,76,9,3,98,0,43,8  ; n1955 t=88.082s dur=100ms, freq=98Hz, sample=43, buffer_id=08:2B
    db 10,0,100,0,31,76,9,8,49,0,31,8  ; n1956 t=88.082s dur=100ms, freq=49Hz, sample=31, buffer_id=08:1F
    db 87,0,100,0,67,125,8,10,136,1,67,8  ; n1957 t=88.092s dur=100ms, freq=392Hz, sample=67, buffer_id=08:43
    db 0,0,100,0,55,125,5,1,196,0,55,5  ; n1958 t=88.178s dur=100ms, freq=196Hz, sample=55, buffer_id=05:37
    db 0,0,100,0,31,76,9,2,49,0,31,8  ; n1959 t=88.178s dur=100ms, freq=49Hz, sample=31, buffer_id=08:1F
    db 5,0,100,0,43,76,9,6,98,0,43,8  ; n1960 t=88.178s dur=100ms, freq=98Hz, sample=43, buffer_id=08:2B
    db 87,0,100,0,67,125,8,7,136,1,67,8  ; n1961 t=88.183s dur=100ms, freq=392Hz, sample=67, buffer_id=08:43
    db 0,0,100,0,55,125,5,9,196,0,55,5  ; n1962 t=88.270s dur=100ms, freq=196Hz, sample=55, buffer_id=05:37
    db 0,0,100,0,43,76,9,11,98,0,43,8  ; n1963 t=88.270s dur=100ms, freq=98Hz, sample=43, buffer_id=08:2B
    db 10,0,100,0,31,76,9,12,49,0,31,8  ; n1964 t=88.270s dur=100ms, freq=49Hz, sample=31, buffer_id=08:1F
    db 58,0,100,0,67,125,8,13,136,1,67,8  ; n1965 t=88.279s dur=100ms, freq=392Hz, sample=67, buffer_id=08:43
    db 29,0,56,1,79,125,5,4,228,2,79,5  ; n1966 t=88.337s dur=312ms, freq=740Hz, sample=79, buffer_id=05:4F [TRUNCATE prev:ch4 @87813.1ms -> 88337.1ms]
    db 5,0,100,0,63,125,8,5,55,1,63,8  ; n1967 t=88.366s dur=100ms, freq=311Hz, sample=63, buffer_id=08:3F [TRUNCATE prev:ch5 @87817.9ms -> 88366.0ms]
    db 0,0,100,0,51,125,5,0,156,0,51,5  ; n1968 t=88.371s dur=100ms, freq=156Hz, sample=51, buffer_id=05:33 [TRUNCATE prev:ch0 @88082.3ms -> 88370.8ms]
    db 0,0,100,0,67,125,8,10,136,1,67,8  ; n1969 t=88.371s dur=100ms, freq=392Hz, sample=67, buffer_id=08:43 [TRUNCATE prev:ch10 @88091.9ms -> 88370.8ms]
    db 0,0,100,0,27,76,9,3,39,0,27,8  ; n1970 t=88.371s dur=100ms, freq=39Hz, sample=27, buffer_id=08:1B [TRUNCATE prev:ch3 @88082.3ms -> 88370.8ms]
    db 24,0,100,0,38,76,9,8,78,0,38,8  ; n1971 t=88.371s dur=100ms, freq=78Hz, sample=38, buffer_id=08:26 [TRUNCATE prev:ch8 @88082.3ms -> 88370.8ms]
    db 62,0,42,1,78,124,4,1,228,2,78,4  ; n1972 t=88.395s dur=298ms, freq=740Hz, sample=78, buffer_id=04:4E [TRUNCATE prev:ch1 @88178.5ms -> 88394.8ms]
    db 0,0,100,0,51,125,5,2,156,0,51,5  ; n1973 t=88.457s dur=100ms, freq=156Hz, sample=51, buffer_id=05:33 [TRUNCATE prev:ch2 @88178.5ms -> 88457.3ms]
    db 0,0,100,0,38,76,9,6,78,0,38,8  ; n1974 t=88.457s dur=100ms, freq=78Hz, sample=38, buffer_id=08:26 [TRUNCATE prev:ch6 @88178.5ms -> 88457.3ms]
    db 5,0,100,0,27,76,9,7,39,0,27,8  ; n1975 t=88.457s dur=100ms, freq=39Hz, sample=27, buffer_id=08:1B [TRUNCATE prev:ch7 @88183.3ms -> 88457.3ms]
    db 5,0,100,0,67,125,8,13,136,1,67,8  ; n1976 t=88.462s dur=100ms, freq=392Hz, sample=67, buffer_id=08:43 [TRUNCATE prev:ch13 @88279.4ms -> 88462.1ms]
    db 82,0,100,0,63,125,8,5,55,1,63,8  ; n1977 t=88.467s dur=100ms, freq=311Hz, sample=63, buffer_id=08:3F [TRUNCATE prev:ch5 @88366.0ms -> 88466.9ms]
    db 5,0,100,0,67,125,8,10,136,1,67,8  ; n1978 t=88.549s dur=100ms, freq=392Hz, sample=67, buffer_id=08:43 [TRUNCATE prev:ch10 @88370.8ms -> 88548.7ms]
    db 0,0,100,0,51,125,5,0,156,0,51,5  ; n1979 t=88.553s dur=100ms, freq=156Hz, sample=51, buffer_id=05:33 [TRUNCATE prev:ch0 @88370.8ms -> 88553.5ms]
    db 0,0,100,0,27,76,9,3,39,0,27,8  ; n1980 t=88.553s dur=100ms, freq=39Hz, sample=27, buffer_id=08:1B [TRUNCATE prev:ch3 @88370.8ms -> 88553.5ms]
    db 10,0,100,0,38,76,9,8,78,0,38,8  ; n1981 t=88.553s dur=100ms, freq=78Hz, sample=38, buffer_id=08:26 [TRUNCATE prev:ch8 @88370.8ms -> 88553.5ms]
    db 87,0,100,0,63,125,8,9,55,1,63,8  ; n1982 t=88.563s dur=100ms, freq=311Hz, sample=63, buffer_id=08:3F [TRUNCATE prev:ch9 @88269.8ms -> 88563.1ms]
    db 5,0,100,0,67,125,8,11,136,1,67,8  ; n1983 t=88.650s dur=100ms, freq=392Hz, sample=67, buffer_id=08:43
    db 0,0,100,0,51,125,5,12,156,0,51,5  ; n1984 t=88.654s dur=100ms, freq=156Hz, sample=51, buffer_id=05:33
    db 0,0,100,0,63,125,8,5,55,1,63,8  ; n1985 t=88.654s dur=100ms, freq=311Hz, sample=63, buffer_id=08:3F [TRUNCATE prev:ch5 @88466.9ms -> 88654.4ms]
    db 0,0,100,0,27,76,9,7,39,0,27,8  ; n1986 t=88.654s dur=100ms, freq=39Hz, sample=27, buffer_id=08:1B [TRUNCATE prev:ch7 @88457.3ms -> 88654.4ms]
    db 154,0,100,0,38,76,9,6,78,0,38,8  ; n1987 t=88.654s dur=100ms, freq=78Hz, sample=38, buffer_id=08:26 [TRUNCATE prev:ch6 @88457.3ms -> 88654.4ms]
    db 29,0,100,0,79,125,5,2,186,2,79,5  ; n1988 t=88.808s dur=100ms, freq=698Hz, sample=79, buffer_id=05:4F
    db 96,0,100,0,77,124,4,13,186,2,77,4  ; n1989 t=88.837s dur=100ms, freq=698Hz, sample=77, buffer_id=04:4D
    db 5,0,134,0,74,125,5,0,147,2,74,5  ; n1990 t=88.933s dur=134ms, freq=659Hz, sample=74, buffer_id=05:4A
    db 0,0,100,0,63,125,5,1,21,1,63,5  ; n1991 t=88.938s dur=100ms, freq=277Hz, sample=63, buffer_id=05:3F
    db 14,0,100,0,50,76,9,3,139,0,50,8  ; n1992 t=88.938s dur=100ms, freq=139Hz, sample=50, buffer_id=08:32
    db 0,0,100,0,68,125,8,4,159,1,68,8  ; n1993 t=88.953s dur=100ms, freq=415Hz, sample=68, buffer_id=08:44
    db 5,0,100,0,63,125,8,8,74,1,63,8  ; n1994 t=88.953s dur=100ms, freq=330Hz, sample=63, buffer_id=08:3F
    db 10,0,100,0,38,76,9,5,69,0,38,8  ; n1995 t=88.957s dur=100ms, freq=69Hz, sample=38, buffer_id=08:26
    db 135,0,105,0,75,124,4,6,147,2,75,4  ; n1996 t=88.967s dur=105ms, freq=659Hz, sample=75, buffer_id=04:4B
    db 24,0,100,0,75,124,4,7,110,2,75,4  ; n1997 t=89.102s dur=100ms, freq=622Hz, sample=75, buffer_id=04:4B
    db 91,0,100,0,74,125,5,2,110,2,74,5  ; n1998 t=89.126s dur=100ms, freq=622Hz, sample=74, buffer_id=05:4A
    db 14,0,187,0,75,124,4,9,147,2,75,4  ; n1999 t=89.217s dur=187ms, freq=659Hz, sample=75, buffer_id=04:4B
    db 18,1,129,0,74,125,5,10,147,2,74,5  ; n2000 t=89.231s dur=129ms, freq=659Hz, sample=74, buffer_id=05:4A
    db 0,0,100,0,63,125,5,0,21,1,63,5  ; n2001 t=89.505s dur=100ms, freq=277Hz, sample=63, buffer_id=05:3F
    db 14,0,100,0,50,76,9,1,139,0,50,8  ; n2002 t=89.505s dur=100ms, freq=139Hz, sample=50, buffer_id=08:32
    db 14,0,100,0,38,76,9,2,69,0,38,8  ; n2003 t=89.520s dur=100ms, freq=69Hz, sample=38, buffer_id=08:26
    db 0,0,100,0,63,125,8,3,74,1,63,8  ; n2004 t=89.534s dur=100ms, freq=330Hz, sample=63, buffer_id=08:3F
    db 18,1,100,0,68,125,8,5,159,1,68,8  ; n2005 t=89.534s dur=100ms, freq=415Hz, sample=68, buffer_id=08:44
    db 0,0,100,0,63,125,5,1,21,1,63,5  ; n2006 t=89.808s dur=100ms, freq=277Hz, sample=63, buffer_id=05:3F
    db 0,0,100,0,38,76,9,0,69,0,38,8  ; n2007 t=89.808s dur=100ms, freq=69Hz, sample=38, buffer_id=08:26
    db 5,0,100,0,50,76,9,4,139,0,50,8  ; n2008 t=89.808s dur=100ms, freq=139Hz, sample=50, buffer_id=08:32
    db 10,0,105,0,70,124,4,6,159,1,70,4  ; n2009 t=89.813s dur=105ms, freq=415Hz, sample=70, buffer_id=04:46
    db 0,0,110,0,69,125,5,2,159,1,69,5  ; n2010 t=89.823s dur=110ms, freq=415Hz, sample=69, buffer_id=05:45
    db 14,0,100,0,63,125,8,7,74,1,63,8  ; n2011 t=89.823s dur=100ms, freq=330Hz, sample=63, buffer_id=08:3F
    db 67,0,100,0,68,125,8,3,159,1,68,8  ; n2012 t=89.837s dur=100ms, freq=415Hz, sample=68, buffer_id=08:44
    db 0,0,100,0,63,125,5,5,21,1,63,5  ; n2013 t=89.904s dur=100ms, freq=277Hz, sample=63, buffer_id=05:3F
    db 0,0,100,0,38,76,9,8,69,0,38,8  ; n2014 t=89.904s dur=100ms, freq=69Hz, sample=38, buffer_id=08:26
    db 10,0,100,0,50,76,9,9,139,0,50,8  ; n2015 t=89.904s dur=100ms, freq=139Hz, sample=50, buffer_id=08:32
    db 5,0,100,0,63,125,8,10,74,1,63,8  ; n2016 t=89.914s dur=100ms, freq=330Hz, sample=63, buffer_id=08:3F
    db 82,0,100,0,68,125,8,11,159,1,68,8  ; n2017 t=89.919s dur=100ms, freq=415Hz, sample=68, buffer_id=08:44
    db 0,0,100,0,63,125,5,12,21,1,63,5  ; n2018 t=90.001s dur=100ms, freq=277Hz, sample=63, buffer_id=05:3F
    db 0,0,100,0,38,76,9,13,69,0,38,8  ; n2019 t=90.001s dur=100ms, freq=69Hz, sample=38, buffer_id=08:26
    db 5,0,100,0,50,76,9,4,139,0,50,8  ; n2020 t=90.001s dur=100ms, freq=139Hz, sample=50, buffer_id=08:32 [TRUNCATE prev:ch4 @89808.3ms -> 90000.6ms]
    db 10,0,100,0,63,125,8,7,74,1,63,8  ; n2021 t=90.005s dur=100ms, freq=330Hz, sample=63, buffer_id=08:3F [TRUNCATE prev:ch7 @89822.7ms -> 90005.4ms]
    db 72,0,100,0,68,125,8,3,159,1,68,8  ; n2022 t=90.015s dur=100ms, freq=415Hz, sample=68, buffer_id=08:44 [TRUNCATE prev:ch3 @89837.1ms -> 90015.0ms]
    db 10,0,100,0,68,125,8,11,159,1,68,8  ; n2023 t=90.087s dur=100ms, freq=415Hz, sample=68, buffer_id=08:44 [TRUNCATE prev:ch11 @89918.8ms -> 90087.1ms]
    db 0,0,100,0,63,125,5,1,21,1,63,5  ; n2024 t=90.097s dur=100ms, freq=277Hz, sample=63, buffer_id=05:3F [TRUNCATE prev:ch1 @89808.3ms -> 90096.7ms]
    db 0,0,100,0,63,125,8,10,74,1,63,8  ; n2025 t=90.097s dur=100ms, freq=330Hz, sample=63, buffer_id=08:3F [TRUNCATE prev:ch10 @89914.0ms -> 90096.7ms]
    db 0,0,100,0,38,76,9,0,69,0,38,8  ; n2026 t=90.097s dur=100ms, freq=69Hz, sample=38, buffer_id=08:26 [TRUNCATE prev:ch0 @89808.3ms -> 90096.7ms]
    db 14,0,100,0,50,76,9,9,139,0,50,8  ; n2027 t=90.097s dur=100ms, freq=139Hz, sample=50, buffer_id=08:32 [TRUNCATE prev:ch9 @89904.4ms -> 90096.7ms]
    db 10,0,128,1,74,125,5,6,42,2,74,5  ; n2028 t=90.111s dur=384ms, freq=554Hz, sample=74, buffer_id=05:4A [TRUNCATE prev:ch6 @89813.1ms -> 90111.2ms]
    db 0,0,176,1,72,124,4,2,42,2,72,4  ; n2029 t=90.121s dur=432ms, freq=554Hz, sample=72, buffer_id=04:48 [TRUNCATE prev:ch2 @89822.7ms -> 90120.8ms]
    db 255,0,128,1,69,125,5,5,159,1,69,5  ; n2030 t=90.121s dur=384ms, freq=415Hz, sample=69, buffer_id=05:45 [TRUNCATE prev:ch5 @89904.4ms -> 90120.8ms]
    db 0,0,100,0,63,125,5,3,21,1,63,5  ; n2031 t=90.376s dur=100ms, freq=277Hz, sample=63, buffer_id=05:3F
    db 0,0,100,0,50,76,9,7,139,0,50,8  ; n2032 t=90.376s dur=100ms, freq=139Hz, sample=50, buffer_id=08:32
    db 24,0,100,0,38,76,9,4,69,0,38,8  ; n2033 t=90.376s dur=100ms, freq=69Hz, sample=38, buffer_id=08:26
    db 10,0,100,0,63,125,8,0,74,1,63,8  ; n2034 t=90.400s dur=100ms, freq=330Hz, sample=63, buffer_id=08:3F
    db 62,0,100,0,68,125,8,1,159,1,68,8  ; n2035 t=90.409s dur=100ms, freq=415Hz, sample=68, buffer_id=08:44
    db 0,0,100,0,63,125,5,8,21,1,63,5  ; n2036 t=90.472s dur=100ms, freq=277Hz, sample=63, buffer_id=05:3F
    db 0,0,100,0,38,76,9,9,69,0,38,8  ; n2037 t=90.472s dur=100ms, freq=69Hz, sample=38, buffer_id=08:26
    db 24,0,100,0,50,76,9,10,139,0,50,8  ; n2038 t=90.472s dur=100ms, freq=139Hz, sample=50, buffer_id=08:32
    db 10,0,100,0,63,125,8,11,74,1,63,8  ; n2039 t=90.496s dur=100ms, freq=330Hz, sample=63, buffer_id=08:3F
    db 72,0,100,0,68,125,8,12,159,1,68,8  ; n2040 t=90.505s dur=100ms, freq=415Hz, sample=68, buffer_id=08:44
    db 0,0,100,0,63,125,5,13,21,1,63,5  ; n2041 t=90.578s dur=100ms, freq=277Hz, sample=63, buffer_id=05:3F
    db 0,0,100,0,38,76,9,4,69,0,38,8  ; n2042 t=90.578s dur=100ms, freq=69Hz, sample=38, buffer_id=08:26 [TRUNCATE prev:ch4 @90375.6ms -> 90577.5ms]
    db 5,0,100,0,50,76,9,7,139,0,50,8  ; n2043 t=90.578s dur=100ms, freq=139Hz, sample=50, buffer_id=08:32 [TRUNCATE prev:ch7 @90375.6ms -> 90577.5ms]
    db 5,0,100,0,63,125,8,0,74,1,63,8  ; n2044 t=90.582s dur=100ms, freq=330Hz, sample=63, buffer_id=08:3F [TRUNCATE prev:ch0 @90399.6ms -> 90582.3ms]
    db 87,0,100,0,68,125,8,1,159,1,68,8  ; n2045 t=90.587s dur=100ms, freq=415Hz, sample=68, buffer_id=08:44 [TRUNCATE prev:ch1 @90409.2ms -> 90587.1ms]
    db 0,0,100,0,63,125,5,3,21,1,63,5  ; n2046 t=90.674s dur=100ms, freq=277Hz, sample=63, buffer_id=05:3F [TRUNCATE prev:ch3 @90375.6ms -> 90673.7ms]
    db 0,0,100,0,68,125,8,12,159,1,68,8  ; n2047 t=90.674s dur=100ms, freq=415Hz, sample=68, buffer_id=08:44 [TRUNCATE prev:ch12 @90505.4ms -> 90673.7ms]
    db 0,0,100,0,63,125,8,11,74,1,63,8  ; n2048 t=90.674s dur=100ms, freq=330Hz, sample=63, buffer_id=08:3F [TRUNCATE prev:ch11 @90495.8ms -> 90673.7ms]
    db 0,0,100,0,38,76,9,9,69,0,38,8  ; n2049 t=90.674s dur=100ms, freq=69Hz, sample=38, buffer_id=08:26 [TRUNCATE prev:ch9 @90471.7ms -> 90673.7ms]
    db 14,0,100,0,50,76,9,10,139,0,50,8  ; n2050 t=90.674s dur=100ms, freq=139Hz, sample=50, buffer_id=08:32 [TRUNCATE prev:ch10 @90471.7ms -> 90673.7ms]
    db 0,0,104,1,72,124,4,2,11,2,72,4  ; n2051 t=90.688s dur=360ms, freq=523Hz, sample=72, buffer_id=04:48 [TRUNCATE prev:ch2 @90120.8ms -> 90688.1ms]
    db 10,0,61,1,74,125,5,6,11,2,74,5  ; n2052 t=90.688s dur=317ms, freq=523Hz, sample=74, buffer_id=05:4A [TRUNCATE prev:ch6 @90111.2ms -> 90688.1ms]
    db 72,0,254,0,69,125,5,5,159,1,69,5  ; n2053 t=90.698s dur=254ms, freq=415Hz, sample=69, buffer_id=05:45 [TRUNCATE prev:ch5 @90120.8ms -> 90697.7ms]
    db 0,0,100,0,63,125,5,8,21,1,63,5  ; n2054 t=90.770s dur=100ms, freq=277Hz, sample=63, buffer_id=05:3F [TRUNCATE prev:ch8 @90471.7ms -> 90769.8ms]
    db 0,0,100,0,38,76,9,4,69,0,38,8  ; n2055 t=90.770s dur=100ms, freq=69Hz, sample=38, buffer_id=08:26 [TRUNCATE prev:ch4 @90577.5ms -> 90769.8ms]
    db 5,0,100,0,50,76,9,7,139,0,50,8  ; n2056 t=90.770s dur=100ms, freq=139Hz, sample=50, buffer_id=08:32 [TRUNCATE prev:ch7 @90577.5ms -> 90769.8ms]
    db 0,0,100,0,63,125,8,0,74,1,63,8  ; n2057 t=90.775s dur=100ms, freq=330Hz, sample=63, buffer_id=08:3F [TRUNCATE prev:ch0 @90582.3ms -> 90774.6ms]
    db 72,0,100,0,68,125,8,1,159,1,68,8  ; n2058 t=90.775s dur=100ms, freq=415Hz, sample=68, buffer_id=08:44 [TRUNCATE prev:ch1 @90587.1ms -> 90774.6ms]
    db 10,0,100,0,68,125,8,12,159,1,68,8  ; n2059 t=90.847s dur=100ms, freq=415Hz, sample=68, buffer_id=08:44 [TRUNCATE prev:ch12 @90673.7ms -> 90846.7ms]
    db 0,0,100,0,63,125,5,13,21,1,63,5  ; n2060 t=90.856s dur=100ms, freq=277Hz, sample=63, buffer_id=05:3F [TRUNCATE prev:ch13 @90577.5ms -> 90856.3ms]
    db 0,0,100,0,63,125,8,11,74,1,63,8  ; n2061 t=90.856s dur=100ms, freq=330Hz, sample=63, buffer_id=08:3F [TRUNCATE prev:ch11 @90673.7ms -> 90856.3ms]
    db 0,0,100,0,38,76,9,9,69,0,38,8  ; n2062 t=90.856s dur=100ms, freq=69Hz, sample=38, buffer_id=08:26 [TRUNCATE prev:ch9 @90673.7ms -> 90856.3ms]
    db 101,0,100,0,50,76,9,10,139,0,50,8  ; n2063 t=90.856s dur=100ms, freq=139Hz, sample=50, buffer_id=08:32 [TRUNCATE prev:ch10 @90673.7ms -> 90856.3ms]
    db 5,0,100,0,68,125,8,1,159,1,68,8  ; n2064 t=90.957s dur=100ms, freq=415Hz, sample=68, buffer_id=08:44 [TRUNCATE prev:ch1 @90774.6ms -> 90957.3ms]
    db 0,0,100,0,63,125,5,3,21,1,63,5  ; n2065 t=90.962s dur=100ms, freq=277Hz, sample=63, buffer_id=05:3F [TRUNCATE prev:ch3 @90673.7ms -> 90962.1ms]
    db 0,0,100,0,63,125,8,0,74,1,63,8  ; n2066 t=90.962s dur=100ms, freq=330Hz, sample=63, buffer_id=08:3F [TRUNCATE prev:ch0 @90774.6ms -> 90962.1ms]
    db 0,0,100,0,50,76,9,7,139,0,50,8  ; n2067 t=90.962s dur=100ms, freq=139Hz, sample=50, buffer_id=08:32 [TRUNCATE prev:ch7 @90769.8ms -> 90962.1ms]
    db 159,0,100,0,38,76,9,4,69,0,38,8  ; n2068 t=90.962s dur=100ms, freq=69Hz, sample=38, buffer_id=08:26 [TRUNCATE prev:ch4 @90769.8ms -> 90962.1ms]
    db 0,0,100,0,69,125,5,8,238,1,69,5  ; n2069 t=91.121s dur=100ms, freq=494Hz, sample=69, buffer_id=05:45
    db 10,0,100,0,69,125,5,5,159,1,69,5  ; n2070 t=91.121s dur=100ms, freq=415Hz, sample=69, buffer_id=05:45 [TRUNCATE prev:ch5 @90697.7ms -> 91120.8ms]
    db 115,0,101,0,70,124,4,2,238,1,70,4  ; n2071 t=91.130s dur=101ms, freq=494Hz, sample=70, buffer_id=04:46 [TRUNCATE prev:ch2 @90688.1ms -> 91130.4ms]
    db 0,0,100,0,63,125,5,6,55,1,63,5  ; n2072 t=91.246s dur=100ms, freq=311Hz, sample=63, buffer_id=05:3F
    db 10,0,100,0,50,76,9,9,156,0,50,8  ; n2073 t=91.246s dur=100ms, freq=156Hz, sample=50, buffer_id=08:32
    db 10,0,100,0,38,76,9,10,78,0,38,8  ; n2074 t=91.255s dur=100ms, freq=78Hz, sample=38, buffer_id=08:26
    db 0,0,110,0,69,125,5,0,210,1,69,5  ; n2075 t=91.265s dur=110ms, freq=466Hz, sample=69, buffer_id=05:45
    db 0,0,100,0,63,125,8,1,55,1,63,8  ; n2076 t=91.265s dur=100ms, freq=311Hz, sample=63, buffer_id=08:3F
    db 5,0,100,0,65,125,8,3,114,1,65,8  ; n2077 t=91.265s dur=100ms, freq=370Hz, sample=65, buffer_id=08:41
    db 10,0,100,0,63,125,5,4,114,1,63,5  ; n2078 t=91.270s dur=100ms, freq=370Hz, sample=63, buffer_id=05:3F
    db 120,0,105,0,70,124,4,7,210,1,70,4  ; n2079 t=91.279s dur=105ms, freq=466Hz, sample=70, buffer_id=04:46
    db 0,0,100,0,69,125,5,11,184,1,69,5  ; n2080 t=91.400s dur=100ms, freq=440Hz, sample=69, buffer_id=05:45
    db 19,0,100,0,63,125,5,12,93,1,63,5  ; n2081 t=91.400s dur=100ms, freq=349Hz, sample=63, buffer_id=05:3F
    db 125,0,100,0,70,124,4,13,184,1,70,4  ; n2082 t=91.419s dur=100ms, freq=440Hz, sample=70, buffer_id=04:46
    db 10,0,125,0,69,125,5,2,210,1,69,5  ; n2083 t=91.544s dur=125ms, freq=466Hz, sample=69, buffer_id=05:45
    db 14,0,110,0,63,125,5,5,114,1,63,5  ; n2084 t=91.553s dur=110ms, freq=370Hz, sample=63, buffer_id=05:3F
    db 245,0,100,0,70,124,4,1,210,1,70,4  ; n2085 t=91.568s dur=100ms, freq=466Hz, sample=70, buffer_id=04:46
    db 0,0,100,0,63,125,5,0,55,1,63,5  ; n2086 t=91.813s dur=100ms, freq=311Hz, sample=63, buffer_id=05:3F
    db 0,0,100,0,63,125,8,3,55,1,63,8  ; n2087 t=91.813s dur=100ms, freq=311Hz, sample=63, buffer_id=08:3F
    db 0,0,100,0,65,125,8,4,114,1,65,8  ; n2088 t=91.813s dur=100ms, freq=370Hz, sample=65, buffer_id=08:41
    db 0,0,100,0,38,76,9,6,78,0,38,8  ; n2089 t=91.813s dur=100ms, freq=78Hz, sample=38, buffer_id=08:26
    db 47,1,100,0,50,76,9,7,156,0,50,8  ; n2090 t=91.813s dur=100ms, freq=156Hz, sample=50, buffer_id=08:32
    db 0,0,100,0,63,125,5,1,55,1,63,5  ; n2091 t=92.116s dur=100ms, freq=311Hz, sample=63, buffer_id=05:3F
    db 0,0,100,0,63,125,8,0,55,1,63,8  ; n2092 t=92.116s dur=100ms, freq=311Hz, sample=63, buffer_id=08:3F
    db 0,0,100,0,65,125,8,2,114,1,65,8  ; n2093 t=92.116s dur=100ms, freq=370Hz, sample=65, buffer_id=08:41
    db 0,0,100,0,50,76,9,3,156,0,50,8  ; n2094 t=92.116s dur=100ms, freq=156Hz, sample=50, buffer_id=08:32
    db 24,0,100,0,38,76,9,4,78,0,38,8  ; n2095 t=92.116s dur=100ms, freq=78Hz, sample=38, buffer_id=08:26
    db 5,0,100,0,63,125,5,6,55,1,63,5  ; n2096 t=92.140s dur=100ms, freq=311Hz, sample=63, buffer_id=05:3F
    db 67,0,101,0,65,124,4,5,55,1,65,4  ; n2097 t=92.145s dur=101ms, freq=311Hz, sample=65, buffer_id=04:41
    db 0,0,100,0,63,125,5,7,55,1,63,5  ; n2098 t=92.212s dur=100ms, freq=311Hz, sample=63, buffer_id=05:3F
    db 0,0,100,0,63,125,8,8,55,1,63,8  ; n2099 t=92.212s dur=100ms, freq=311Hz, sample=63, buffer_id=08:3F
    db 0,0,100,0,65,125,8,9,114,1,65,8  ; n2100 t=92.212s dur=100ms, freq=370Hz, sample=65, buffer_id=08:41
    db 0,0,100,0,38,76,9,11,78,0,38,8  ; n2101 t=92.212s dur=100ms, freq=78Hz, sample=38, buffer_id=08:26
    db 96,0,100,0,50,76,9,10,156,0,50,8  ; n2102 t=92.212s dur=100ms, freq=156Hz, sample=50, buffer_id=08:32
    db 0,0,100,0,63,125,5,13,55,1,63,5  ; n2103 t=92.308s dur=100ms, freq=311Hz, sample=63, buffer_id=05:3F
    db 0,0,100,0,63,125,8,12,55,1,63,8  ; n2104 t=92.308s dur=100ms, freq=311Hz, sample=63, buffer_id=08:3F
    db 0,0,100,0,65,125,8,2,114,1,65,8  ; n2105 t=92.308s dur=100ms, freq=370Hz, sample=65, buffer_id=08:41 [TRUNCATE prev:ch2 @92116.0ms -> 92308.3ms]
    db 0,0,100,0,50,76,9,3,156,0,50,8  ; n2106 t=92.308s dur=100ms, freq=156Hz, sample=50, buffer_id=08:32 [TRUNCATE prev:ch3 @92116.0ms -> 92308.3ms]
    db 96,0,100,0,38,76,9,4,78,0,38,8  ; n2107 t=92.308s dur=100ms, freq=78Hz, sample=38, buffer_id=08:26 [TRUNCATE prev:ch4 @92116.0ms -> 92308.3ms]
    db 0,0,100,0,63,125,5,1,55,1,63,5  ; n2108 t=92.404s dur=100ms, freq=311Hz, sample=63, buffer_id=05:3F [TRUNCATE prev:ch1 @92116.0ms -> 92404.4ms]
    db 0,0,100,0,63,125,8,0,55,1,63,8  ; n2109 t=92.404s dur=100ms, freq=311Hz, sample=63, buffer_id=08:3F [TRUNCATE prev:ch0 @92116.0ms -> 92404.4ms]
    db 0,0,100,0,65,125,8,9,114,1,65,8  ; n2110 t=92.404s dur=100ms, freq=370Hz, sample=65, buffer_id=08:41 [TRUNCATE prev:ch9 @92212.1ms -> 92404.4ms]
    db 0,0,100,0,38,76,9,11,78,0,38,8  ; n2111 t=92.404s dur=100ms, freq=78Hz, sample=38, buffer_id=08:26 [TRUNCATE prev:ch11 @92212.1ms -> 92404.4ms]
    db 19,0,100,0,50,76,9,10,156,0,50,8  ; n2112 t=92.404s dur=100ms, freq=156Hz, sample=50, buffer_id=08:32 [TRUNCATE prev:ch10 @92212.1ms -> 92404.4ms]
    db 5,0,147,1,65,124,4,5,114,1,65,4  ; n2113 t=92.424s dur=403ms, freq=370Hz, sample=65, buffer_id=04:41 [TRUNCATE prev:ch5 @92144.8ms -> 92423.7ms]
    db 41,2,90,1,63,125,5,6,114,1,63,5  ; n2114 t=92.428s dur=346ms, freq=370Hz, sample=63, buffer_id=05:3F [TRUNCATE prev:ch6 @92140.0ms -> 92428.5ms]
    db 0,0,100,0,58,125,5,0,6,1,58,5  ; n2115 t=92.981s dur=100ms, freq=262Hz, sample=58, buffer_id=05:3A
    db 0,0,100,0,63,125,8,1,55,1,63,8  ; n2116 t=92.981s dur=100ms, freq=311Hz, sample=63, buffer_id=08:3F
    db 0,0,100,0,65,125,8,3,114,1,65,8  ; n2117 t=92.981s dur=100ms, freq=370Hz, sample=65, buffer_id=08:41
    db 0,0,100,0,47,76,9,2,131,0,47,8  ; n2118 t=92.981s dur=100ms, freq=131Hz, sample=47, buffer_id=08:2F
    db 5,0,100,0,38,76,9,6,65,0,38,8  ; n2119 t=92.981s dur=100ms, freq=65Hz, sample=38, buffer_id=08:26
    db 10,0,109,1,63,125,5,4,114,1,63,5  ; n2120 t=92.986s dur=365ms, freq=370Hz, sample=63, buffer_id=05:3F
    db 0,0,104,1,65,124,4,7,55,1,65,4  ; n2121 t=92.996s dur=360ms, freq=311Hz, sample=65, buffer_id=04:41
    db 0,0,70,1,63,125,5,8,55,1,63,5  ; n2122 t=92.996s dur=326ms, freq=311Hz, sample=63, buffer_id=05:3F
    db 82,0,123,1,69,125,5,9,210,1,69,5  ; n2123 t=92.996s dur=379ms, freq=466Hz, sample=69, buffer_id=05:45
    db 0,0,100,0,58,125,5,5,6,1,58,5  ; n2124 t=93.078s dur=100ms, freq=262Hz, sample=58, buffer_id=05:3A
    db 0,0,100,0,63,125,8,10,55,1,63,8  ; n2125 t=93.078s dur=100ms, freq=311Hz, sample=63, buffer_id=08:3F
    db 0,0,100,0,65,125,8,11,114,1,65,8  ; n2126 t=93.078s dur=100ms, freq=370Hz, sample=65, buffer_id=08:41
    db 0,0,100,0,38,76,9,12,65,0,38,8  ; n2127 t=93.078s dur=100ms, freq=65Hz, sample=38, buffer_id=08:26
    db 87,0,100,0,47,76,9,13,131,0,47,8  ; n2128 t=93.078s dur=100ms, freq=131Hz, sample=47, buffer_id=08:2F
    db 0,0,100,0,58,125,5,0,6,1,58,5  ; n2129 t=93.164s dur=100ms, freq=262Hz, sample=58, buffer_id=05:3A [TRUNCATE prev:ch0 @92981.3ms -> 93164.0ms]
    db 0,0,100,0,63,125,8,1,55,1,63,8  ; n2130 t=93.164s dur=100ms, freq=311Hz, sample=63, buffer_id=08:3F [TRUNCATE prev:ch1 @92981.3ms -> 93164.0ms]
    db 0,0,100,0,65,125,8,3,114,1,65,8  ; n2131 t=93.164s dur=100ms, freq=370Hz, sample=65, buffer_id=08:41 [TRUNCATE prev:ch3 @92981.3ms -> 93164.0ms]
    db 0,0,100,0,47,76,9,2,131,0,47,8  ; n2132 t=93.164s dur=100ms, freq=131Hz, sample=47, buffer_id=08:2F [TRUNCATE prev:ch2 @92981.3ms -> 93164.0ms]
    db 106,0,100,0,38,76,9,6,65,0,38,8  ; n2133 t=93.164s dur=100ms, freq=65Hz, sample=38, buffer_id=08:26 [TRUNCATE prev:ch6 @92981.3ms -> 93164.0ms]
    db 0,0,100,0,58,125,5,5,6,1,58,5  ; n2134 t=93.270s dur=100ms, freq=262Hz, sample=58, buffer_id=05:3A [TRUNCATE prev:ch5 @93077.5ms -> 93269.8ms]
    db 0,0,100,0,63,125,8,10,55,1,63,8  ; n2135 t=93.270s dur=100ms, freq=311Hz, sample=63, buffer_id=08:3F [TRUNCATE prev:ch10 @93077.5ms -> 93269.8ms]
    db 0,0,100,0,65,125,8,11,114,1,65,8  ; n2136 t=93.270s dur=100ms, freq=370Hz, sample=65, buffer_id=08:41 [TRUNCATE prev:ch11 @93077.5ms -> 93269.8ms]
    db 0,0,100,0,38,76,9,12,65,0,38,8  ; n2137 t=93.270s dur=100ms, freq=65Hz, sample=38, buffer_id=08:26 [TRUNCATE prev:ch12 @93077.5ms -> 93269.8ms]
    db 168,0,100,0,47,76,9,13,131,0,47,8  ; n2138 t=93.270s dur=100ms, freq=131Hz, sample=47, buffer_id=08:2F [TRUNCATE prev:ch13 @93077.5ms -> 93269.8ms]
    db 5,0,100,0,70,124,4,4,210,1,70,4  ; n2139 t=93.438s dur=100ms, freq=466Hz, sample=70, buffer_id=04:46 [TRUNCATE prev:ch4 @92986.2ms -> 93438.1ms]
    db 120,0,100,0,69,125,5,9,210,1,69,5  ; n2140 t=93.443s dur=100ms, freq=466Hz, sample=69, buffer_id=05:45 [TRUNCATE prev:ch9 @92995.8ms -> 93442.9ms]
    db 0,0,100,0,55,125,5,0,196,0,55,5  ; n2141 t=93.563s dur=100ms, freq=196Hz, sample=55, buffer_id=05:37
    db 0,0,100,0,67,125,8,1,136,1,67,8  ; n2142 t=93.563s dur=100ms, freq=392Hz, sample=67, buffer_id=08:43
    db 0,0,100,0,43,76,9,2,98,0,43,8  ; n2143 t=93.563s dur=100ms, freq=98Hz, sample=43, buffer_id=08:2B
    db 14,0,100,0,31,76,9,3,49,0,31,8  ; n2144 t=93.563s dur=100ms, freq=49Hz, sample=31, buffer_id=08:1F
    db 10,0,128,1,69,125,5,5,136,1,69,5  ; n2145 t=93.578s dur=384ms, freq=392Hz, sample=69, buffer_id=05:45
    db 36,2,143,1,65,124,4,6,136,1,65,4  ; n2146 t=93.587s dur=399ms, freq=392Hz, sample=65, buffer_id=04:41
    db 0,0,100,0,63,125,5,0,55,1,63,5  ; n2147 t=94.135s dur=100ms, freq=311Hz, sample=63, buffer_id=05:3F
    db 0,0,80,1,69,125,5,1,210,1,69,5  ; n2148 t=94.135s dur=336ms, freq=466Hz, sample=69, buffer_id=05:45
    db 0,0,80,1,63,125,5,2,114,1,63,5  ; n2149 t=94.135s dur=336ms, freq=370Hz, sample=63, buffer_id=05:3F
    db 0,0,100,0,63,125,8,3,55,1,63,8  ; n2150 t=94.135s dur=100ms, freq=311Hz, sample=63, buffer_id=08:3F
    db 0,0,100,0,65,125,8,4,114,1,65,8  ; n2151 t=94.135s dur=100ms, freq=370Hz, sample=65, buffer_id=08:41
    db 0,0,100,0,38,76,9,7,78,0,38,8  ; n2152 t=94.135s dur=100ms, freq=78Hz, sample=38, buffer_id=08:26
    db 5,0,100,0,50,76,9,8,156,0,50,8  ; n2153 t=94.135s dur=100ms, freq=156Hz, sample=50, buffer_id=08:32
    db 29,0,100,0,63,125,5,9,55,1,63,5  ; n2154 t=94.140s dur=100ms, freq=311Hz, sample=63, buffer_id=05:3F
    db 62,0,32,1,65,124,4,5,55,1,65,4  ; n2155 t=94.169s dur=288ms, freq=311Hz, sample=65, buffer_id=04:41
    db 0,0,100,0,63,125,5,6,55,1,63,5  ; n2156 t=94.231s dur=100ms, freq=311Hz, sample=63, buffer_id=05:3F
    db 0,0,100,0,63,125,8,11,55,1,63,8  ; n2157 t=94.231s dur=100ms, freq=311Hz, sample=63, buffer_id=08:3F
    db 0,0,100,0,65,125,8,10,114,1,65,8  ; n2158 t=94.231s dur=100ms, freq=370Hz, sample=65, buffer_id=08:41
    db 0,0,100,0,50,76,9,12,156,0,50,8  ; n2159 t=94.231s dur=100ms, freq=156Hz, sample=50, buffer_id=08:32
    db 87,0,100,0,38,76,9,13,78,0,38,8  ; n2160 t=94.231s dur=100ms, freq=78Hz, sample=38, buffer_id=08:26
    db 0,0,100,0,63,125,5,0,55,1,63,5  ; n2161 t=94.318s dur=100ms, freq=311Hz, sample=63, buffer_id=05:3F [TRUNCATE prev:ch0 @94135.2ms -> 94317.9ms]
    db 0,0,100,0,63,125,8,3,55,1,63,8  ; n2162 t=94.318s dur=100ms, freq=311Hz, sample=63, buffer_id=08:3F [TRUNCATE prev:ch3 @94135.2ms -> 94317.9ms]
    db 0,0,100,0,65,125,8,4,114,1,65,8  ; n2163 t=94.318s dur=100ms, freq=370Hz, sample=65, buffer_id=08:41 [TRUNCATE prev:ch4 @94135.2ms -> 94317.9ms]
    db 0,0,100,0,38,76,9,7,78,0,38,8  ; n2164 t=94.318s dur=100ms, freq=78Hz, sample=38, buffer_id=08:26 [TRUNCATE prev:ch7 @94135.2ms -> 94317.9ms]
    db 106,0,100,0,50,76,9,8,156,0,50,8  ; n2165 t=94.318s dur=100ms, freq=156Hz, sample=50, buffer_id=08:32 [TRUNCATE prev:ch8 @94135.2ms -> 94317.9ms]
    db 0,0,100,0,63,125,5,2,55,1,63,5  ; n2166 t=94.424s dur=100ms, freq=311Hz, sample=63, buffer_id=05:3F [TRUNCATE prev:ch2 @94135.2ms -> 94423.7ms]
    db 0,0,100,0,63,125,8,11,55,1,63,8  ; n2167 t=94.424s dur=100ms, freq=311Hz, sample=63, buffer_id=08:3F [TRUNCATE prev:ch11 @94231.3ms -> 94423.7ms]
    db 0,0,100,0,65,125,8,10,114,1,65,8  ; n2168 t=94.424s dur=100ms, freq=370Hz, sample=65, buffer_id=08:41 [TRUNCATE prev:ch10 @94231.3ms -> 94423.7ms]
    db 0,0,100,0,50,76,9,12,156,0,50,8  ; n2169 t=94.424s dur=100ms, freq=156Hz, sample=50, buffer_id=08:32 [TRUNCATE prev:ch12 @94231.3ms -> 94423.7ms]
    db 168,0,100,0,38,76,9,13,78,0,38,8  ; n2170 t=94.424s dur=100ms, freq=78Hz, sample=38, buffer_id=08:26 [TRUNCATE prev:ch13 @94231.3ms -> 94423.7ms]
    db 10,0,100,0,70,124,4,6,210,1,70,4  ; n2171 t=94.592s dur=100ms, freq=466Hz, sample=70, buffer_id=04:46
    db 125,0,100,0,69,125,5,9,210,1,69,5  ; n2172 t=94.602s dur=100ms, freq=466Hz, sample=69, buffer_id=05:45
    db 0,0,100,0,55,125,5,0,196,0,55,5  ; n2173 t=94.727s dur=100ms, freq=196Hz, sample=55, buffer_id=05:37
    db 0,0,214,2,69,125,5,2,136,1,69,5  ; n2174 t=94.727s dur=726ms, freq=392Hz, sample=69, buffer_id=05:45
    db 0,0,100,0,67,125,8,1,136,1,67,8  ; n2175 t=94.727s dur=100ms, freq=392Hz, sample=67, buffer_id=08:43
    db 0,0,100,0,31,76,9,3,49,0,31,8  ; n2176 t=94.727s dur=100ms, freq=49Hz, sample=31, buffer_id=08:1F
    db 14,0,100,0,43,76,9,4,98,0,43,8  ; n2177 t=94.727s dur=100ms, freq=98Hz, sample=43, buffer_id=08:2B
    db 8,1,39,3,65,124,4,7,136,1,65,4  ; n2178 t=94.741s dur=807ms, freq=392Hz, sample=65, buffer_id=04:41
    db 0,0,100,0,55,125,5,5,196,0,55,5  ; n2179 t=95.005s dur=100ms, freq=196Hz, sample=55, buffer_id=05:37
    db 0,0,100,0,67,125,8,6,136,1,67,8  ; n2180 t=95.005s dur=100ms, freq=392Hz, sample=67, buffer_id=08:43
    db 0,0,100,0,43,76,9,8,98,0,43,8  ; n2181 t=95.005s dur=100ms, freq=98Hz, sample=43, buffer_id=08:2B
    db 96,0,100,0,31,76,9,9,49,0,31,8  ; n2182 t=95.005s dur=100ms, freq=49Hz, sample=31, buffer_id=08:1F
    db 0,0,100,0,55,125,5,1,196,0,55,5  ; n2183 t=95.102s dur=100ms, freq=196Hz, sample=55, buffer_id=05:37
    db 0,0,100,0,67,125,8,0,136,1,67,8  ; n2184 t=95.102s dur=100ms, freq=392Hz, sample=67, buffer_id=08:43
    db 0,0,100,0,31,76,9,4,49,0,31,8  ; n2185 t=95.102s dur=100ms, freq=49Hz, sample=31, buffer_id=08:1F
    db 96,0,100,0,43,76,9,3,98,0,43,8  ; n2186 t=95.102s dur=100ms, freq=98Hz, sample=43, buffer_id=08:2B
    db 0,0,100,0,55,125,5,10,196,0,55,5  ; n2187 t=95.198s dur=100ms, freq=196Hz, sample=55, buffer_id=05:37
    db 0,0,100,0,67,125,8,11,136,1,67,8  ; n2188 t=95.198s dur=100ms, freq=392Hz, sample=67, buffer_id=08:43
    db 0,0,100,0,43,76,9,12,98,0,43,8  ; n2189 t=95.198s dur=100ms, freq=98Hz, sample=43, buffer_id=08:2B
    db 96,0,100,0,31,76,9,13,49,0,31,8  ; n2190 t=95.198s dur=100ms, freq=49Hz, sample=31, buffer_id=08:1F
    db 0,0,100,0,55,125,5,5,196,0,55,5  ; n2191 t=95.294s dur=100ms, freq=196Hz, sample=55, buffer_id=05:37 [TRUNCATE prev:ch5 @95005.4ms -> 95293.8ms]
    db 0,0,100,0,67,125,8,6,136,1,67,8  ; n2192 t=95.294s dur=100ms, freq=392Hz, sample=67, buffer_id=08:43 [TRUNCATE prev:ch6 @95005.4ms -> 95293.8ms]
    db 0,0,100,0,31,76,9,9,49,0,31,8  ; n2193 t=95.294s dur=100ms, freq=49Hz, sample=31, buffer_id=08:1F [TRUNCATE prev:ch9 @95005.4ms -> 95293.8ms]
    db 91,0,100,0,43,76,9,8,98,0,43,8  ; n2194 t=95.294s dur=100ms, freq=98Hz, sample=43, buffer_id=08:2B [TRUNCATE prev:ch8 @95005.4ms -> 95293.8ms]
    db 0,0,100,0,55,125,5,1,196,0,55,5  ; n2195 t=95.385s dur=100ms, freq=196Hz, sample=55, buffer_id=05:37 [TRUNCATE prev:ch1 @95101.5ms -> 95385.2ms]
    db 0,0,100,0,67,125,8,0,136,1,67,8  ; n2196 t=95.385s dur=100ms, freq=392Hz, sample=67, buffer_id=08:43 [TRUNCATE prev:ch0 @95101.5ms -> 95385.2ms]
    db 0,0,100,0,43,76,9,3,98,0,43,8  ; n2197 t=95.385s dur=100ms, freq=98Hz, sample=43, buffer_id=08:2B [TRUNCATE prev:ch3 @95101.5ms -> 95385.2ms]
    db 96,0,100,0,31,76,9,4,49,0,31,8  ; n2198 t=95.385s dur=100ms, freq=49Hz, sample=31, buffer_id=08:1F [TRUNCATE prev:ch4 @95101.5ms -> 95385.2ms]
    db 0,0,100,0,55,125,5,10,196,0,55,5  ; n2199 t=95.481s dur=100ms, freq=196Hz, sample=55, buffer_id=05:37 [TRUNCATE prev:ch10 @95197.7ms -> 95481.3ms]
    db 0,0,100,0,67,125,8,11,136,1,67,8  ; n2200 t=95.481s dur=100ms, freq=392Hz, sample=67, buffer_id=08:43 [TRUNCATE prev:ch11 @95197.7ms -> 95481.3ms]
    db 0,0,100,0,31,76,9,13,49,0,31,8  ; n2201 t=95.481s dur=100ms, freq=49Hz, sample=31, buffer_id=08:1F [TRUNCATE prev:ch13 @95197.7ms -> 95481.3ms]
    db 101,0,100,0,43,76,9,12,98,0,43,8  ; n2202 t=95.481s dur=100ms, freq=98Hz, sample=43, buffer_id=08:2B [TRUNCATE prev:ch12 @95197.7ms -> 95481.3ms]
    db 0,0,100,0,55,125,5,5,196,0,55,5  ; n2203 t=95.582s dur=100ms, freq=196Hz, sample=55, buffer_id=05:37 [TRUNCATE prev:ch5 @95293.8ms -> 95582.3ms]
    db 0,0,100,0,67,125,8,6,136,1,67,8  ; n2204 t=95.582s dur=100ms, freq=392Hz, sample=67, buffer_id=08:43 [TRUNCATE prev:ch6 @95293.8ms -> 95582.3ms]
    db 0,0,100,0,43,76,9,8,98,0,43,8  ; n2205 t=95.582s dur=100ms, freq=98Hz, sample=43, buffer_id=08:2B [TRUNCATE prev:ch8 @95293.8ms -> 95582.3ms]
    db 60,2,100,0,31,76,9,9,49,0,31,8  ; n2206 t=95.582s dur=100ms, freq=49Hz, sample=31, buffer_id=08:1F [TRUNCATE prev:ch9 @95293.8ms -> 95582.3ms]
    db 5,0,100,0,58,125,8,0,233,0,58,8  ; n2207 t=96.154s dur=100ms, freq=233Hz, sample=58, buffer_id=08:3A
    db 0,0,100,0,58,126,3,1,233,0,58,3  ; n2208 t=96.159s dur=100ms, freq=233Hz, sample=58, buffer_id=03:3A
    db 0,0,100,0,62,126,3,2,38,1,62,3  ; n2209 t=96.159s dur=100ms, freq=294Hz, sample=62, buffer_id=03:3E
    db 91,0,100,0,62,125,8,3,38,1,62,8  ; n2210 t=96.159s dur=100ms, freq=294Hz, sample=62, buffer_id=08:3E
    db 0,0,100,0,58,126,3,4,233,0,58,3  ; n2211 t=96.251s dur=100ms, freq=233Hz, sample=58, buffer_id=03:3A
    db 0,0,100,0,58,125,8,5,233,0,58,8  ; n2212 t=96.251s dur=100ms, freq=233Hz, sample=58, buffer_id=08:3A
    db 5,0,100,0,62,125,8,6,38,1,62,8  ; n2213 t=96.251s dur=100ms, freq=294Hz, sample=62, buffer_id=08:3E
    db 0,0,100,0,62,126,3,7,38,1,62,3  ; n2214 t=96.255s dur=100ms, freq=294Hz, sample=62, buffer_id=03:3E
    db 0,0,100,0,55,125,5,8,196,0,55,5  ; n2215 t=96.255s dur=100ms, freq=196Hz, sample=55, buffer_id=05:37
    db 0,0,100,0,31,124,10,10,49,0,31,8  ; n2216 t=96.255s dur=100ms, freq=49Hz, sample=31, buffer_id=08:1F
    db 91,0,100,0,43,124,10,9,98,0,43,8  ; n2217 t=96.255s dur=100ms, freq=98Hz, sample=43, buffer_id=08:2B
    db 0,0,100,0,58,126,3,11,233,0,58,3  ; n2218 t=96.347s dur=100ms, freq=233Hz, sample=58, buffer_id=03:3A
    db 0,0,100,0,55,125,5,12,196,0,55,5  ; n2219 t=96.347s dur=100ms, freq=196Hz, sample=55, buffer_id=05:37
    db 0,0,100,0,58,125,8,13,233,0,58,8  ; n2220 t=96.347s dur=100ms, freq=233Hz, sample=58, buffer_id=08:3A
    db 0,0,100,0,62,125,8,3,38,1,62,8  ; n2221 t=96.347s dur=100ms, freq=294Hz, sample=62, buffer_id=08:3E [TRUNCATE prev:ch3 @96159.2ms -> 96346.7ms]
    db 0,0,100,0,31,124,10,0,49,0,31,8  ; n2222 t=96.347s dur=100ms, freq=49Hz, sample=31, buffer_id=08:1F [TRUNCATE prev:ch0 @96154.4ms -> 96346.7ms]
    db 5,0,100,0,43,124,10,1,98,0,43,8  ; n2223 t=96.347s dur=100ms, freq=98Hz, sample=43, buffer_id=08:2B [TRUNCATE prev:ch1 @96159.2ms -> 96346.7ms]
    db 91,0,100,0,62,126,3,2,38,1,62,3  ; n2224 t=96.352s dur=100ms, freq=294Hz, sample=62, buffer_id=03:3E [TRUNCATE prev:ch2 @96159.2ms -> 96351.5ms]
    db 0,0,100,0,63,126,3,4,55,1,63,3  ; n2225 t=96.443s dur=100ms, freq=311Hz, sample=63, buffer_id=03:3F [TRUNCATE prev:ch4 @96250.6ms -> 96442.9ms]
    db 0,0,100,0,58,126,3,5,247,0,58,3  ; n2226 t=96.443s dur=100ms, freq=247Hz, sample=58, buffer_id=03:3A [TRUNCATE prev:ch5 @96250.6ms -> 96442.9ms]
    db 0,0,100,0,59,125,8,6,247,0,59,8  ; n2227 t=96.443s dur=100ms, freq=247Hz, sample=59, buffer_id=08:3B [TRUNCATE prev:ch6 @96250.6ms -> 96442.9ms]
    db 5,0,100,0,63,125,8,7,55,1,63,8  ; n2228 t=96.443s dur=100ms, freq=311Hz, sample=63, buffer_id=08:3F [TRUNCATE prev:ch7 @96255.4ms -> 96442.9ms]
    db 0,0,100,0,55,125,5,8,196,0,55,5  ; n2229 t=96.448s dur=100ms, freq=196Hz, sample=55, buffer_id=05:37 [TRUNCATE prev:ch8 @96255.4ms -> 96447.7ms]
    db 0,0,100,0,31,124,10,10,49,0,31,8  ; n2230 t=96.448s dur=100ms, freq=49Hz, sample=31, buffer_id=08:1F [TRUNCATE prev:ch10 @96255.4ms -> 96447.7ms]
    db 10,0,100,0,43,124,10,9,98,0,43,8  ; n2231 t=96.448s dur=100ms, freq=98Hz, sample=43, buffer_id=08:2B [TRUNCATE prev:ch9 @96255.4ms -> 96447.7ms]
    db 82,0,100,0,50,124,10,0,147,0,50,8  ; n2232 t=96.457s dur=100ms, freq=147Hz, sample=50, buffer_id=08:32 [TRUNCATE prev:ch0 @96346.7ms -> 96457.3ms]
    db 0,0,100,0,58,126,3,11,247,0,58,3  ; n2233 t=96.539s dur=100ms, freq=247Hz, sample=58, buffer_id=03:3A [TRUNCATE prev:ch11 @96346.7ms -> 96539.0ms]
    db 0,0,100,0,55,125,5,12,196,0,55,5  ; n2234 t=96.539s dur=100ms, freq=196Hz, sample=55, buffer_id=05:37 [TRUNCATE prev:ch12 @96346.7ms -> 96539.0ms]
    db 0,0,100,0,59,125,8,1,247,0,59,8  ; n2235 t=96.539s dur=100ms, freq=247Hz, sample=59, buffer_id=08:3B [TRUNCATE prev:ch1 @96346.7ms -> 96539.0ms]
    db 0,0,100,0,63,125,8,3,55,1,63,8  ; n2236 t=96.539s dur=100ms, freq=311Hz, sample=63, buffer_id=08:3F [TRUNCATE prev:ch3 @96346.7ms -> 96539.0ms]
    db 0,0,100,0,31,124,10,13,49,0,31,8  ; n2237 t=96.539s dur=100ms, freq=49Hz, sample=31, buffer_id=08:1F [TRUNCATE prev:ch13 @96346.7ms -> 96539.0ms]
    db 5,0,100,0,43,124,10,2,98,0,43,8  ; n2238 t=96.539s dur=100ms, freq=98Hz, sample=43, buffer_id=08:2B [TRUNCATE prev:ch2 @96351.5ms -> 96539.0ms]
    db 10,0,100,0,63,126,3,4,55,1,63,3  ; n2239 t=96.544s dur=100ms, freq=311Hz, sample=63, buffer_id=03:3F [TRUNCATE prev:ch4 @96442.9ms -> 96543.8ms]
    db 77,0,100,0,50,124,10,5,147,0,50,8  ; n2240 t=96.553s dur=100ms, freq=147Hz, sample=50, buffer_id=08:32 [TRUNCATE prev:ch5 @96442.9ms -> 96553.5ms]
    db 0,0,100,0,58,126,3,6,247,0,58,3  ; n2241 t=96.630s dur=100ms, freq=247Hz, sample=58, buffer_id=03:3A [TRUNCATE prev:ch6 @96442.9ms -> 96630.4ms]
    db 5,0,100,0,63,125,8,7,55,1,63,8  ; n2242 t=96.630s dur=100ms, freq=311Hz, sample=63, buffer_id=08:3F [TRUNCATE prev:ch7 @96442.9ms -> 96630.4ms]
    db 0,0,100,0,63,126,3,8,55,1,63,3  ; n2243 t=96.635s dur=100ms, freq=311Hz, sample=63, buffer_id=03:3F [TRUNCATE prev:ch8 @96447.7ms -> 96635.2ms]
    db 0,0,100,0,55,125,5,9,196,0,55,5  ; n2244 t=96.635s dur=100ms, freq=196Hz, sample=55, buffer_id=05:37 [TRUNCATE prev:ch9 @96447.7ms -> 96635.2ms]
    db 0,0,100,0,59,125,8,10,247,0,59,8  ; n2245 t=96.635s dur=100ms, freq=247Hz, sample=59, buffer_id=08:3B [TRUNCATE prev:ch10 @96447.7ms -> 96635.2ms]
    db 0,0,100,0,31,124,10,0,49,0,31,8  ; n2246 t=96.635s dur=100ms, freq=49Hz, sample=31, buffer_id=08:1F [TRUNCATE prev:ch0 @96457.3ms -> 96635.2ms]
    db 14,0,100,0,43,124,10,1,98,0,43,8  ; n2247 t=96.635s dur=100ms, freq=98Hz, sample=43, buffer_id=08:2B [TRUNCATE prev:ch1 @96539.0ms -> 96635.2ms]
    db 82,0,100,0,50,124,10,2,147,0,50,8  ; n2248 t=96.650s dur=100ms, freq=147Hz, sample=50, buffer_id=08:32 [TRUNCATE prev:ch2 @96539.0ms -> 96649.6ms]
    db 0,0,100,0,62,126,3,3,21,1,62,3  ; n2249 t=96.731s dur=100ms, freq=277Hz, sample=62, buffer_id=03:3E [TRUNCATE prev:ch3 @96539.0ms -> 96731.3ms]
    db 0,0,100,0,65,126,3,11,93,1,65,3  ; n2250 t=96.731s dur=100ms, freq=349Hz, sample=65, buffer_id=03:41 [TRUNCATE prev:ch11 @96539.0ms -> 96731.3ms]
    db 0,0,100,0,55,125,5,12,196,0,55,5  ; n2251 t=96.731s dur=100ms, freq=196Hz, sample=55, buffer_id=05:37 [TRUNCATE prev:ch12 @96539.0ms -> 96731.3ms]
    db 0,0,100,0,65,125,8,13,93,1,65,8  ; n2252 t=96.731s dur=100ms, freq=349Hz, sample=65, buffer_id=08:41 [TRUNCATE prev:ch13 @96539.0ms -> 96731.3ms]
    db 0,0,100,0,61,125,8,4,21,1,61,8  ; n2253 t=96.731s dur=100ms, freq=277Hz, sample=61, buffer_id=08:3D [TRUNCATE prev:ch4 @96543.8ms -> 96731.3ms]
    db 0,0,100,0,31,124,10,5,49,0,31,8  ; n2254 t=96.731s dur=100ms, freq=49Hz, sample=31, buffer_id=08:1F [TRUNCATE prev:ch5 @96553.5ms -> 96731.3ms]
    db 10,0,100,0,43,124,10,6,98,0,43,8  ; n2255 t=96.731s dur=100ms, freq=98Hz, sample=43, buffer_id=08:2B [TRUNCATE prev:ch6 @96630.4ms -> 96731.3ms]
    db 77,0,100,0,50,124,10,7,147,0,50,8  ; n2256 t=96.741s dur=100ms, freq=147Hz, sample=50, buffer_id=08:32 [TRUNCATE prev:ch7 @96630.4ms -> 96741.0ms]
    db 5,0,100,0,65,125,8,0,93,1,65,8  ; n2257 t=96.818s dur=100ms, freq=349Hz, sample=65, buffer_id=08:41 [TRUNCATE prev:ch0 @96635.2ms -> 96817.9ms]
    db 5,0,100,0,62,126,3,1,21,1,62,3  ; n2258 t=96.823s dur=100ms, freq=277Hz, sample=62, buffer_id=03:3E [TRUNCATE prev:ch1 @96635.2ms -> 96822.7ms]
    db 0,0,100,0,65,126,3,8,93,1,65,3  ; n2259 t=96.828s dur=100ms, freq=349Hz, sample=65, buffer_id=03:41 [TRUNCATE prev:ch8 @96635.2ms -> 96827.5ms]
    db 87,0,100,0,61,125,8,9,21,1,61,8  ; n2260 t=96.828s dur=100ms, freq=277Hz, sample=61, buffer_id=08:3D [TRUNCATE prev:ch9 @96635.2ms -> 96827.5ms]
    db 10,0,100,0,65,125,8,13,93,1,65,8  ; n2261 t=96.914s dur=100ms, freq=349Hz, sample=65, buffer_id=08:41 [TRUNCATE prev:ch13 @96731.3ms -> 96914.0ms]
    db 0,0,100,0,65,126,3,11,93,1,65,3  ; n2262 t=96.924s dur=100ms, freq=349Hz, sample=65, buffer_id=03:41 [TRUNCATE prev:ch11 @96731.3ms -> 96923.7ms]
    db 0,0,100,0,62,126,3,3,21,1,62,3  ; n2263 t=96.924s dur=100ms, freq=277Hz, sample=62, buffer_id=03:3E [TRUNCATE prev:ch3 @96731.3ms -> 96923.7ms]
    db 126,0,100,0,61,125,8,4,21,1,61,8  ; n2264 t=96.924s dur=100ms, freq=277Hz, sample=61, buffer_id=08:3D [TRUNCATE prev:ch4 @96731.3ms -> 96923.7ms]
    db 16,0,191,1,38,124,10,2,65,0,38,8  ; n2265 t=97.050s dur=447ms, freq=65Hz, sample=38, buffer_id=08:26
    db 5,0,4,1,62,102,6,5,6,1,62,6  ; n2266 t=97.066s dur=260ms, freq=262Hz, sample=62, buffer_id=06:3E
    db 36,1,239,0,48,102,6,6,131,0,48,6  ; n2267 t=97.071s dur=239ms, freq=131Hz, sample=48, buffer_id=06:30
    db 10,0,100,0,55,124,10,0,196,0,55,8  ; n2268 t=97.362s dur=100ms, freq=196Hz, sample=55, buffer_id=08:37
    db 94,0,100,0,50,124,10,1,156,0,50,8  ; n2269 t=97.373s dur=100ms, freq=156Hz, sample=50, buffer_id=08:32
    db 10,0,100,0,55,124,10,3,196,0,55,8  ; n2270 t=97.466s dur=100ms, freq=196Hz, sample=55, buffer_id=08:37
    db 73,0,100,0,50,124,10,4,156,0,50,8  ; n2271 t=97.477s dur=100ms, freq=156Hz, sample=50, buffer_id=08:32
    db 10,0,100,0,50,124,10,5,156,0,50,8  ; n2272 t=97.550s dur=100ms, freq=156Hz, sample=50, buffer_id=08:32
    db 104,0,100,0,55,124,10,6,196,0,55,8  ; n2273 t=97.560s dur=100ms, freq=196Hz, sample=55, buffer_id=08:37
    db 0,0,100,0,56,124,10,0,208,0,56,8  ; n2274 t=97.664s dur=100ms, freq=208Hz, sample=56, buffer_id=08:38
    db 104,0,100,0,47,124,10,7,123,0,47,8  ; n2275 t=97.664s dur=100ms, freq=123Hz, sample=47, buffer_id=08:2F
    db 16,0,100,0,56,124,10,1,208,0,56,8  ; n2276 t=97.769s dur=100ms, freq=208Hz, sample=56, buffer_id=08:38
    db 83,0,100,0,47,124,10,2,123,0,47,8  ; n2277 t=97.784s dur=100ms, freq=123Hz, sample=47, buffer_id=08:2F
    db 10,0,100,0,56,124,10,3,208,0,56,8  ; n2278 t=97.868s dur=100ms, freq=208Hz, sample=56, buffer_id=08:38
    db 99,0,100,0,47,124,10,4,123,0,47,8  ; n2279 t=97.878s dur=100ms, freq=123Hz, sample=47, buffer_id=08:2F
    db 10,0,100,0,53,124,10,0,175,0,53,8  ; n2280 t=97.977s dur=100ms, freq=175Hz, sample=53, buffer_id=08:35
    db 94,0,100,0,50,124,10,6,147,0,50,8  ; n2281 t=97.987s dur=100ms, freq=147Hz, sample=50, buffer_id=08:32
    db 16,0,100,0,53,124,10,1,175,0,53,8  ; n2282 t=98.081s dur=100ms, freq=175Hz, sample=53, buffer_id=08:35
    db 83,0,100,0,50,124,10,2,147,0,50,8  ; n2283 t=98.097s dur=100ms, freq=147Hz, sample=50, buffer_id=08:32
    db 10,0,100,0,53,124,10,3,175,0,53,8  ; n2284 t=98.180s dur=100ms, freq=175Hz, sample=53, buffer_id=08:35
    db 146,0,100,0,50,124,10,4,147,0,50,8  ; n2285 t=98.191s dur=100ms, freq=147Hz, sample=50, buffer_id=08:32
    db 10,1,108,1,38,124,10,0,65,0,38,8  ; n2286 t=98.336s dur=364ms, freq=65Hz, sample=38, buffer_id=08:26
    db 21,0,100,0,55,124,10,1,196,0,55,8  ; n2287 t=98.602s dur=100ms, freq=196Hz, sample=55, buffer_id=08:37
    db 73,0,100,0,63,124,10,2,55,1,63,8  ; n2288 t=98.623s dur=100ms, freq=311Hz, sample=63, buffer_id=08:3F
    db 31,0,100,0,55,124,10,3,196,0,55,8  ; n2289 t=98.696s dur=100ms, freq=196Hz, sample=55, buffer_id=08:37
    db 73,0,100,0,63,124,10,4,55,1,63,8  ; n2290 t=98.727s dur=100ms, freq=311Hz, sample=63, buffer_id=08:3F
    db 21,0,100,0,55,124,10,5,196,0,55,8  ; n2291 t=98.800s dur=100ms, freq=196Hz, sample=55, buffer_id=08:37
    db 94,0,100,0,63,124,10,6,55,1,63,8  ; n2292 t=98.821s dur=100ms, freq=311Hz, sample=63, buffer_id=08:3F
    db 10,0,100,0,50,124,10,0,156,0,50,8  ; n2293 t=98.914s dur=100ms, freq=156Hz, sample=50, buffer_id=08:32
    db 94,0,100,0,62,124,10,1,38,1,62,8  ; n2294 t=98.925s dur=100ms, freq=294Hz, sample=62, buffer_id=08:3E
    db 10,0,100,0,50,124,10,2,156,0,50,8  ; n2295 t=99.019s dur=100ms, freq=156Hz, sample=50, buffer_id=08:32
    db 83,0,100,0,62,124,10,3,38,1,62,8  ; n2296 t=99.029s dur=100ms, freq=294Hz, sample=62, buffer_id=08:3E
    db 10,0,100,0,50,124,10,4,156,0,50,8  ; n2297 t=99.112s dur=100ms, freq=156Hz, sample=50, buffer_id=08:32
    db 109,0,100,0,62,124,10,5,38,1,62,8  ; n2298 t=99.123s dur=100ms, freq=294Hz, sample=62, buffer_id=08:3E
    db 5,0,100,0,59,124,10,0,247,0,59,8  ; n2299 t=99.232s dur=100ms, freq=247Hz, sample=59, buffer_id=08:3B
    db 104,0,100,0,53,124,10,1,185,0,53,8  ; n2300 t=99.237s dur=100ms, freq=185Hz, sample=53, buffer_id=08:35
    db 0,0,100,0,53,124,10,2,185,0,53,8  ; n2301 t=99.341s dur=100ms, freq=185Hz, sample=53, buffer_id=08:35
    db 83,0,100,0,59,124,10,3,247,0,59,8  ; n2302 t=99.341s dur=100ms, freq=247Hz, sample=59, buffer_id=08:3B
    db 21,0,100,0,53,124,10,4,185,0,53,8  ; n2303 t=99.425s dur=100ms, freq=185Hz, sample=53, buffer_id=08:35
    db 83,0,100,0,59,124,10,5,247,0,59,8  ; n2304 t=99.446s dur=100ms, freq=247Hz, sample=59, buffer_id=08:3B
    db 62,1,107,2,38,124,10,6,65,0,38,8  ; n2305 t=99.529s dur=619ms, freq=65Hz, sample=38, buffer_id=08:26
    db 0,0,100,0,59,124,10,1,247,0,59,8  ; n2306 t=99.847s dur=100ms, freq=247Hz, sample=59, buffer_id=08:3B
    db 104,0,100,0,67,124,10,0,136,1,67,8  ; n2307 t=99.847s dur=100ms, freq=392Hz, sample=67, buffer_id=08:43
    db 5,0,100,0,59,124,10,2,247,0,59,8  ; n2308 t=99.951s dur=100ms, freq=247Hz, sample=59, buffer_id=08:3B
    db 88,0,100,0,67,124,10,3,136,1,67,8  ; n2309 t=99.956s dur=100ms, freq=392Hz, sample=67, buffer_id=08:43
    db 0,0,100,0,59,124,10,4,247,0,59,8  ; n2310 t=100.045s dur=100ms, freq=247Hz, sample=59, buffer_id=08:3B
    db 94,0,100,0,67,124,10,5,136,1,67,8  ; n2311 t=100.045s dur=100ms, freq=392Hz, sample=67, buffer_id=08:43
    db 26,0,180,2,38,124,10,7,73,0,38,8  ; n2312 t=100.138s dur=692ms, freq=73Hz, sample=38, buffer_id=08:26
    db 16,0,100,0,65,124,10,0,114,1,65,8  ; n2313 t=100.164s dur=100ms, freq=370Hz, sample=65, buffer_id=08:41
    db 73,0,100,0,59,124,10,8,6,1,59,8  ; n2314 t=100.180s dur=100ms, freq=262Hz, sample=59, buffer_id=08:3B
    db 21,0,100,0,59,124,10,9,6,1,59,8  ; n2315 t=100.253s dur=100ms, freq=262Hz, sample=59, buffer_id=08:3B
    db 78,0,100,0,65,124,10,1,114,1,65,8  ; n2316 t=100.274s dur=100ms, freq=370Hz, sample=65, buffer_id=08:41
    db 16,0,100,0,59,124,10,3,6,1,59,8  ; n2317 t=100.352s dur=100ms, freq=262Hz, sample=59, buffer_id=08:3B
    db 104,0,100,0,65,124,10,2,114,1,65,8  ; n2318 t=100.368s dur=100ms, freq=370Hz, sample=65, buffer_id=08:41
    db 16,0,100,0,53,124,10,0,185,0,53,8  ; n2319 t=100.472s dur=100ms, freq=185Hz, sample=53, buffer_id=08:35
    db 89,0,100,0,62,124,10,4,38,1,62,8  ; n2320 t=100.487s dur=100ms, freq=294Hz, sample=62, buffer_id=08:3E
    db 26,0,100,0,53,124,10,1,185,0,53,8  ; n2321 t=100.576s dur=100ms, freq=185Hz, sample=53, buffer_id=08:35
    db 68,0,100,0,62,124,10,5,38,1,62,8  ; n2322 t=100.602s dur=100ms, freq=294Hz, sample=62, buffer_id=08:3E
    db 31,0,100,0,53,124,10,2,185,0,53,8  ; n2323 t=100.670s dur=100ms, freq=185Hz, sample=53, buffer_id=08:35
    db 36,0,100,0,62,124,10,3,38,1,62,8  ; n2324 t=100.701s dur=100ms, freq=294Hz, sample=62, buffer_id=08:3E
    db 36,0,118,2,38,124,10,8,78,0,38,8  ; n2325 t=100.737s dur=630ms, freq=78Hz, sample=38, buffer_id=08:26
    db 10,0,100,0,65,124,10,0,93,1,65,8  ; n2326 t=100.774s dur=100ms, freq=349Hz, sample=65, buffer_id=08:41
    db 89,0,100,0,56,124,10,6,220,0,56,8  ; n2327 t=100.784s dur=100ms, freq=220Hz, sample=56, buffer_id=08:38
    db 5,0,100,0,65,124,10,4,93,1,65,8  ; n2328 t=100.873s dur=100ms, freq=349Hz, sample=65, buffer_id=08:41
    db 99,0,100,0,56,124,10,1,220,0,56,8  ; n2329 t=100.878s dur=100ms, freq=220Hz, sample=56, buffer_id=08:38
    db 5,0,100,0,65,124,10,2,93,1,65,8  ; n2330 t=100.977s dur=100ms, freq=349Hz, sample=65, buffer_id=08:41
    db 104,0,100,0,56,124,10,5,220,0,56,8  ; n2331 t=100.982s dur=100ms, freq=220Hz, sample=56, buffer_id=08:38
    db 5,0,100,0,63,124,10,0,55,1,63,8  ; n2332 t=101.086s dur=100ms, freq=311Hz, sample=63, buffer_id=08:3F
    db 89,0,100,0,55,124,10,3,196,0,55,8  ; n2333 t=101.091s dur=100ms, freq=196Hz, sample=55, buffer_id=08:37
    db 10,0,100,0,63,124,10,1,55,1,63,8  ; n2334 t=101.180s dur=100ms, freq=311Hz, sample=63, buffer_id=08:3F
    db 83,0,100,0,55,124,10,4,196,0,55,8  ; n2335 t=101.191s dur=100ms, freq=196Hz, sample=55, buffer_id=08:37
    db 21,0,100,0,63,124,10,6,55,1,63,8  ; n2336 t=101.274s dur=100ms, freq=311Hz, sample=63, buffer_id=08:3F
    db 73,0,100,0,55,124,10,2,196,0,55,8  ; n2337 t=101.295s dur=100ms, freq=196Hz, sample=55, buffer_id=08:37
    db 21,0,113,2,43,124,10,5,87,0,43,8  ; n2338 t=101.368s dur=625ms, freq=87Hz, sample=43, buffer_id=08:2B
    db 16,0,100,0,59,124,10,0,247,0,59,8  ; n2339 t=101.388s dur=100ms, freq=247Hz, sample=59, buffer_id=08:3B
    db 89,0,100,0,50,124,10,3,156,0,50,8  ; n2340 t=101.404s dur=100ms, freq=156Hz, sample=50, buffer_id=08:32
    db 10,0,100,0,59,124,10,1,247,0,59,8  ; n2341 t=101.493s dur=100ms, freq=247Hz, sample=59, buffer_id=08:3B
    db 94,0,100,0,50,124,10,4,156,0,50,8  ; n2342 t=101.503s dur=100ms, freq=156Hz, sample=50, buffer_id=08:32
    db 5,0,100,0,59,124,10,2,247,0,59,8  ; n2343 t=101.597s dur=100ms, freq=247Hz, sample=59, buffer_id=08:3B
    db 89,0,100,0,50,124,10,6,156,0,50,8  ; n2344 t=101.602s dur=100ms, freq=156Hz, sample=50, buffer_id=08:32
    db 26,0,100,0,56,124,10,0,208,0,56,8  ; n2345 t=101.691s dur=100ms, freq=208Hz, sample=56, buffer_id=08:38
    db 99,0,100,0,47,124,10,3,123,0,47,8  ; n2346 t=101.716s dur=100ms, freq=123Hz, sample=47, buffer_id=08:2F
    db 5,0,100,0,56,124,10,1,208,0,56,8  ; n2347 t=101.816s dur=100ms, freq=208Hz, sample=56, buffer_id=08:38
    db 78,0,100,0,47,124,10,4,123,0,47,8  ; n2348 t=101.821s dur=100ms, freq=123Hz, sample=47, buffer_id=08:2F
    db 21,0,100,0,56,124,10,2,208,0,56,8  ; n2349 t=101.899s dur=100ms, freq=208Hz, sample=56, buffer_id=08:38
    db 89,0,100,0,47,124,10,6,123,0,47,8  ; n2350 t=101.920s dur=100ms, freq=123Hz, sample=47, buffer_id=08:2F
    db 5,0,100,0,62,125,8,0,38,1,62,8  ; n2351 t=102.008s dur=100ms, freq=294Hz, sample=62, buffer_id=08:3E
    db 16,0,255,0,50,124,10,7,147,0,50,8  ; n2352 t=102.013s dur=255ms, freq=147Hz, sample=50, buffer_id=08:32
    db 0,0,46,1,50,125,5,3,147,0,50,5  ; n2353 t=102.029s dur=302ms, freq=147Hz, sample=50, buffer_id=05:32
    db 10,0,25,1,38,124,10,9,73,0,38,8  ; n2354 t=102.029s dur=281ms, freq=73Hz, sample=38, buffer_id=08:26
    db 0,0,82,1,65,124,4,8,38,1,65,4  ; n2355 t=102.039s dur=338ms, freq=294Hz, sample=65, buffer_id=04:41
    db 16,0,25,1,63,125,5,10,38,1,63,5  ; n2356 t=102.039s dur=281ms, freq=294Hz, sample=63, buffer_id=05:3F
    db 10,0,108,1,43,124,10,11,110,0,43,8  ; n2357 t=102.055s dur=364ms, freq=110Hz, sample=43, buffer_id=08:2B
    db 5,0,4,1,62,102,6,12,38,1,62,6  ; n2358 t=102.066s dur=260ms, freq=294Hz, sample=62, buffer_id=06:3E
    db 36,1,239,0,50,102,6,13,147,0,50,6  ; n2359 t=102.071s dur=239ms, freq=147Hz, sample=50, buffer_id=06:32
    db 10,0,100,0,56,124,10,0,220,0,56,8  ; n2360 t=102.362s dur=100ms, freq=220Hz, sample=56, buffer_id=08:38
    db 94,0,100,0,53,124,10,1,175,0,53,8  ; n2361 t=102.373s dur=100ms, freq=175Hz, sample=53, buffer_id=08:35
    db 10,0,100,0,56,124,10,4,220,0,56,8  ; n2362 t=102.466s dur=100ms, freq=220Hz, sample=56, buffer_id=08:38
    db 73,0,100,0,53,124,10,2,175,0,53,8  ; n2363 t=102.477s dur=100ms, freq=175Hz, sample=53, buffer_id=08:35
    db 10,0,100,0,53,124,10,3,175,0,53,8  ; n2364 t=102.550s dur=100ms, freq=175Hz, sample=53, buffer_id=08:35
    db 104,0,100,0,56,124,10,5,220,0,56,8  ; n2365 t=102.560s dur=100ms, freq=220Hz, sample=56, buffer_id=08:38
    db 0,0,100,0,58,124,10,0,233,0,58,8  ; n2366 t=102.664s dur=100ms, freq=233Hz, sample=58, buffer_id=08:3A
    db 104,0,100,0,50,124,10,6,139,0,50,8  ; n2367 t=102.664s dur=100ms, freq=139Hz, sample=50, buffer_id=08:32
    db 16,0,100,0,58,124,10,1,233,0,58,8  ; n2368 t=102.769s dur=100ms, freq=233Hz, sample=58, buffer_id=08:3A
    db 83,0,100,0,50,124,10,2,139,0,50,8  ; n2369 t=102.784s dur=100ms, freq=139Hz, sample=50, buffer_id=08:32
    db 10,0,100,0,58,124,10,3,233,0,58,8  ; n2370 t=102.868s dur=100ms, freq=233Hz, sample=58, buffer_id=08:3A
    db 99,0,100,0,50,124,10,4,139,0,50,8  ; n2371 t=102.878s dur=100ms, freq=139Hz, sample=50, buffer_id=08:32
    db 10,0,100,0,55,124,10,0,196,0,55,8  ; n2372 t=102.977s dur=100ms, freq=196Hz, sample=55, buffer_id=08:37
    db 94,0,100,0,53,124,10,5,165,0,53,8  ; n2373 t=102.987s dur=100ms, freq=165Hz, sample=53, buffer_id=08:35
    db 16,0,100,0,55,124,10,1,196,0,55,8  ; n2374 t=103.081s dur=100ms, freq=196Hz, sample=55, buffer_id=08:37
    db 83,0,100,0,53,124,10,2,165,0,53,8  ; n2375 t=103.097s dur=100ms, freq=165Hz, sample=53, buffer_id=08:35
    db 10,0,100,0,55,124,10,3,196,0,55,8  ; n2376 t=103.180s dur=100ms, freq=196Hz, sample=55, buffer_id=08:37
    db 94,0,100,0,53,124,10,4,165,0,53,8  ; n2377 t=103.191s dur=100ms, freq=165Hz, sample=53, buffer_id=08:35
    db 5,0,244,0,38,124,10,0,73,0,38,8  ; n2378 t=103.284s dur=244ms, freq=73Hz, sample=38, buffer_id=08:26
    db 0,0,4,1,50,125,5,5,147,0,50,5  ; n2379 t=103.289s dur=260ms, freq=147Hz, sample=50, buffer_id=05:32
    db 0,0,100,0,62,125,8,6,38,1,62,8  ; n2380 t=103.289s dur=100ms, freq=294Hz, sample=62, buffer_id=08:3E
    db 5,0,218,0,50,124,10,8,147,0,50,8  ; n2381 t=103.289s dur=218ms, freq=147Hz, sample=50, buffer_id=08:32
    db 10,0,234,0,63,125,5,7,38,1,63,5  ; n2382 t=103.295s dur=234ms, freq=294Hz, sample=63, buffer_id=05:3F
    db 26,0,20,1,65,124,4,9,38,1,65,4  ; n2383 t=103.305s dur=276ms, freq=294Hz, sample=65, buffer_id=04:41
    db 15,1,87,1,43,124,10,10,110,0,43,8  ; n2384 t=103.331s dur=343ms, freq=110Hz, sample=43, buffer_id=08:2B
    db 21,0,100,0,56,124,10,1,220,0,56,8  ; n2385 t=103.602s dur=100ms, freq=220Hz, sample=56, buffer_id=08:38
    db 73,0,100,0,65,124,10,2,93,1,65,8  ; n2386 t=103.623s dur=100ms, freq=349Hz, sample=65, buffer_id=08:41
    db 31,0,100,0,56,124,10,3,220,0,56,8  ; n2387 t=103.696s dur=100ms, freq=220Hz, sample=56, buffer_id=08:38
    db 73,0,100,0,65,124,10,4,93,1,65,8  ; n2388 t=103.727s dur=100ms, freq=349Hz, sample=65, buffer_id=08:41
    db 21,0,100,0,56,124,10,0,220,0,56,8  ; n2389 t=103.800s dur=100ms, freq=220Hz, sample=56, buffer_id=08:38
    db 94,0,100,0,65,124,10,5,93,1,65,8  ; n2390 t=103.821s dur=100ms, freq=349Hz, sample=65, buffer_id=08:41
    db 10,0,100,0,53,124,10,1,175,0,53,8  ; n2391 t=103.914s dur=100ms, freq=175Hz, sample=53, buffer_id=08:35
    db 94,0,100,0,63,124,10,2,74,1,63,8  ; n2392 t=103.925s dur=100ms, freq=330Hz, sample=63, buffer_id=08:3F
    db 10,0,100,0,53,124,10,3,175,0,53,8  ; n2393 t=104.019s dur=100ms, freq=175Hz, sample=53, buffer_id=08:35
    db 83,0,100,0,63,124,10,4,74,1,63,8  ; n2394 t=104.029s dur=100ms, freq=330Hz, sample=63, buffer_id=08:3F
    db 10,0,100,0,53,124,10,0,175,0,53,8  ; n2395 t=104.112s dur=100ms, freq=175Hz, sample=53, buffer_id=08:35
    db 109,0,100,0,63,124,10,5,74,1,63,8  ; n2396 t=104.123s dur=100ms, freq=330Hz, sample=63, buffer_id=08:3F
    db 5,0,100,0,61,124,10,1,21,1,61,8  ; n2397 t=104.232s dur=100ms, freq=277Hz, sample=61, buffer_id=08:3D
    db 104,0,100,0,56,124,10,2,208,0,56,8  ; n2398 t=104.237s dur=100ms, freq=208Hz, sample=56, buffer_id=08:38
    db 0,0,100,0,56,124,10,3,208,0,56,8  ; n2399 t=104.341s dur=100ms, freq=208Hz, sample=56, buffer_id=08:38
    db 83,0,100,0,61,124,10,4,21,1,61,8  ; n2400 t=104.341s dur=100ms, freq=277Hz, sample=61, buffer_id=08:3D
    db 21,0,100,0,56,124,10,0,208,0,56,8  ; n2401 t=104.425s dur=100ms, freq=208Hz, sample=56, buffer_id=08:38
    db 83,0,100,0,61,124,10,5,21,1,61,8  ; n2402 t=104.446s dur=100ms, freq=277Hz, sample=61, buffer_id=08:3D
    db 0,0,239,0,50,124,10,6,147,0,50,8  ; n2403 t=104.529s dur=239ms, freq=147Hz, sample=50, buffer_id=08:32
    db 10,0,255,0,38,124,10,7,73,0,38,8  ; n2404 t=104.529s dur=255ms, freq=73Hz, sample=38, buffer_id=08:26
    db 0,0,239,0,63,125,5,1,38,1,63,5  ; n2405 t=104.539s dur=239ms, freq=294Hz, sample=63, buffer_id=05:3F
    db 5,0,244,0,50,125,5,2,147,0,50,5  ; n2406 t=104.539s dur=244ms, freq=147Hz, sample=50, buffer_id=05:32
    db 10,0,100,0,62,125,8,8,38,1,62,8  ; n2407 t=104.545s dur=100ms, freq=294Hz, sample=62, buffer_id=08:3E
    db 36,1,250,0,65,124,4,10,38,1,65,4  ; n2408 t=104.555s dur=250ms, freq=294Hz, sample=65, buffer_id=04:41
    db 0,0,100,0,61,124,10,0,21,1,61,8  ; n2409 t=104.847s dur=100ms, freq=277Hz, sample=61, buffer_id=08:3D
    db 104,0,100,0,69,124,10,3,184,1,69,8  ; n2410 t=104.847s dur=100ms, freq=440Hz, sample=69, buffer_id=08:45
    db 5,0,100,0,61,124,10,8,21,1,61,8  ; n2411 t=104.951s dur=100ms, freq=277Hz, sample=61, buffer_id=08:3D
    db 88,0,100,0,69,124,10,4,184,1,69,8  ; n2412 t=104.956s dur=100ms, freq=440Hz, sample=69, buffer_id=08:45
    db 0,0,100,0,61,124,10,1,21,1,61,8  ; n2413 t=105.045s dur=100ms, freq=277Hz, sample=61, buffer_id=08:3D
    db 120,0,100,0,69,124,10,2,184,1,69,8  ; n2414 t=105.045s dur=100ms, freq=440Hz, sample=69, buffer_id=08:45
    db 16,0,100,0,68,124,10,0,159,1,68,8  ; n2415 t=105.164s dur=100ms, freq=415Hz, sample=68, buffer_id=08:44
    db 0,0,100,0,62,124,10,3,38,1,62,8  ; n2416 t=105.180s dur=100ms, freq=294Hz, sample=62, buffer_id=08:3E
    db 73,0,149,2,47,124,10,5,123,0,47,8  ; n2417 t=105.180s dur=661ms, freq=123Hz, sample=47, buffer_id=08:2F
    db 21,0,100,0,62,124,10,6,38,1,62,8  ; n2418 t=105.253s dur=100ms, freq=294Hz, sample=62, buffer_id=08:3E
    db 78,0,100,0,68,124,10,4,159,1,68,8  ; n2419 t=105.274s dur=100ms, freq=415Hz, sample=68, buffer_id=08:44
    db 16,0,100,0,62,124,10,1,38,1,62,8  ; n2420 t=105.352s dur=100ms, freq=294Hz, sample=62, buffer_id=08:3E
    db 104,0,100,0,68,124,10,2,159,1,68,8  ; n2421 t=105.368s dur=100ms, freq=415Hz, sample=68, buffer_id=08:44
    db 16,0,100,0,56,124,10,0,208,0,56,8  ; n2422 t=105.472s dur=100ms, freq=208Hz, sample=56, buffer_id=08:38
    db 89,0,100,0,63,124,10,3,74,1,63,8  ; n2423 t=105.487s dur=100ms, freq=330Hz, sample=63, buffer_id=08:3F
    db 26,0,100,0,56,124,10,4,208,0,56,8  ; n2424 t=105.576s dur=100ms, freq=208Hz, sample=56, buffer_id=08:38
    db 68,0,100,0,63,124,10,6,74,1,63,8  ; n2425 t=105.602s dur=100ms, freq=330Hz, sample=63, buffer_id=08:3F
    db 31,0,100,0,56,124,10,1,208,0,56,8  ; n2426 t=105.670s dur=100ms, freq=208Hz, sample=56, buffer_id=08:38
    db 73,0,100,0,63,124,10,2,74,1,63,8  ; n2427 t=105.701s dur=100ms, freq=330Hz, sample=63, buffer_id=08:3F
    db 10,0,100,0,67,124,10,0,136,1,67,8  ; n2428 t=105.774s dur=100ms, freq=392Hz, sample=67, buffer_id=08:43
    db 21,0,100,0,59,124,10,7,247,0,59,8  ; n2429 t=105.784s dur=100ms, freq=247Hz, sample=59, buffer_id=08:3B
    db 68,0,112,2,47,124,10,3,131,0,47,8  ; n2430 t=105.805s dur=624ms, freq=131Hz, sample=47, buffer_id=08:2F
    db 5,0,100,0,67,124,10,8,136,1,67,8  ; n2431 t=105.873s dur=100ms, freq=392Hz, sample=67, buffer_id=08:43
    db 99,0,100,0,59,124,10,4,247,0,59,8  ; n2432 t=105.878s dur=100ms, freq=247Hz, sample=59, buffer_id=08:3B
    db 5,0,100,0,67,124,10,1,136,1,67,8  ; n2433 t=105.977s dur=100ms, freq=392Hz, sample=67, buffer_id=08:43
    db 104,0,100,0,59,124,10,6,247,0,59,8  ; n2434 t=105.982s dur=100ms, freq=247Hz, sample=59, buffer_id=08:3B
    db 5,0,100,0,65,124,10,0,93,1,65,8  ; n2435 t=106.086s dur=100ms, freq=349Hz, sample=65, buffer_id=08:41
    db 89,0,100,0,56,124,10,2,220,0,56,8  ; n2436 t=106.091s dur=100ms, freq=220Hz, sample=56, buffer_id=08:38
    db 10,0,100,0,65,124,10,4,93,1,65,8  ; n2437 t=106.180s dur=100ms, freq=349Hz, sample=65, buffer_id=08:41
    db 83,0,100,0,56,124,10,5,220,0,56,8  ; n2438 t=106.191s dur=100ms, freq=220Hz, sample=56, buffer_id=08:38
    db 21,0,100,0,65,124,10,7,93,1,65,8  ; n2439 t=106.274s dur=100ms, freq=349Hz, sample=65, buffer_id=08:41
    db 94,0,100,0,56,124,10,1,220,0,56,8  ; n2440 t=106.295s dur=100ms, freq=220Hz, sample=56, buffer_id=08:38
    db 16,0,100,0,61,124,10,0,21,1,61,8  ; n2441 t=106.388s dur=100ms, freq=277Hz, sample=61, buffer_id=08:3D
    db 42,0,100,0,53,124,10,2,175,0,53,8  ; n2442 t=106.404s dur=100ms, freq=175Hz, sample=53, buffer_id=08:35
    db 47,0,56,1,50,124,10,6,139,0,50,8  ; n2443 t=106.446s dur=312ms, freq=139Hz, sample=50, buffer_id=08:32
    db 10,0,100,0,61,124,10,4,21,1,61,8  ; n2444 t=106.493s dur=100ms, freq=277Hz, sample=61, buffer_id=08:3D
    db 94,0,100,0,53,124,10,5,175,0,53,8  ; n2445 t=106.503s dur=100ms, freq=175Hz, sample=53, buffer_id=08:35
    db 5,0,100,0,61,124,10,1,21,1,61,8  ; n2446 t=106.597s dur=100ms, freq=277Hz, sample=61, buffer_id=08:3D
    db 89,0,100,0,53,124,10,7,175,0,53,8  ; n2447 t=106.602s dur=100ms, freq=175Hz, sample=53, buffer_id=08:35
    db 26,0,100,0,58,124,10,0,233,0,58,8  ; n2448 t=106.691s dur=100ms, freq=233Hz, sample=58, buffer_id=08:3A
    db 99,0,100,0,50,124,10,2,139,0,50,8  ; n2449 t=106.716s dur=100ms, freq=139Hz, sample=50, buffer_id=08:32
    db 5,0,100,0,58,124,10,3,233,0,58,8  ; n2450 t=106.816s dur=100ms, freq=233Hz, sample=58, buffer_id=08:3A
    db 88,0,100,0,50,124,10,4,139,0,50,8  ; n2451 t=106.821s dur=100ms, freq=139Hz, sample=50, buffer_id=08:32
    db 21,0,100,0,58,124,10,1,233,0,58,8  ; n2452 t=106.909s dur=100ms, freq=233Hz, sample=58, buffer_id=08:3A
    db 99,0,100,0,50,124,10,5,139,0,50,8  ; n2453 t=106.930s dur=100ms, freq=139Hz, sample=50, buffer_id=08:32
    db 0,0,109,0,70,125,8,0,238,1,70,8  ; n2454 t=107.029s dur=109ms, freq=494Hz, sample=70, buffer_id=08:46
    db 0,0,100,0,53,124,10,2,165,0,53,8  ; n2455 t=107.029s dur=100ms, freq=165Hz, sample=53, buffer_id=08:35
    db 5,0,100,0,53,124,10,6,165,0,53,8  ; n2456 t=107.029s dur=100ms, freq=165Hz, sample=53, buffer_id=08:35
    db 94,0,100,0,68,125,8,7,159,1,68,8  ; n2457 t=107.034s dur=100ms, freq=415Hz, sample=68, buffer_id=08:44
    db 0,0,119,0,72,125,8,3,11,2,72,8  ; n2458 t=107.128s dur=119ms, freq=523Hz, sample=72, buffer_id=08:48
    db 0,0,100,0,47,124,10,4,123,0,47,8  ; n2459 t=107.128s dur=100ms, freq=123Hz, sample=47, buffer_id=08:2F
    db 21,0,119,0,53,124,10,8,175,0,53,8  ; n2460 t=107.128s dur=119ms, freq=175Hz, sample=53, buffer_id=08:35
    db 78,0,130,0,67,125,8,9,136,1,67,8  ; n2461 t=107.149s dur=130ms, freq=392Hz, sample=67, buffer_id=08:43
    db 0,0,130,0,74,125,8,1,75,2,74,8  ; n2462 t=107.227s dur=130ms, freq=587Hz, sample=74, buffer_id=08:4A
    db 5,0,109,0,55,124,10,10,196,0,55,8  ; n2463 t=107.227s dur=109ms, freq=196Hz, sample=55, buffer_id=08:37
    db 21,0,140,0,43,124,10,5,87,0,43,8  ; n2464 t=107.232s dur=140ms, freq=87Hz, sample=43, buffer_id=08:2B
    db 78,0,100,0,63,125,8,11,74,1,63,8  ; n2465 t=107.253s dur=100ms, freq=330Hz, sample=63, buffer_id=08:3F
    db 10,0,130,0,56,124,10,2,208,0,56,8  ; n2466 t=107.331s dur=130ms, freq=208Hz, sample=56, buffer_id=08:38
    db 0,0,100,0,77,125,8,0,186,2,77,8  ; n2467 t=107.341s dur=100ms, freq=698Hz, sample=77, buffer_id=08:4D
    db 10,0,109,0,38,124,10,6,82,0,38,8  ; n2468 t=107.341s dur=109ms, freq=82Hz, sample=38, buffer_id=08:26
    db 89,0,100,0,59,125,8,7,6,1,59,8  ; n2469 t=107.352s dur=100ms, freq=262Hz, sample=59, buffer_id=08:3B
    db 0,0,100,0,75,125,8,4,147,2,75,8  ; n2470 t=107.441s dur=100ms, freq=659Hz, sample=75, buffer_id=08:4B
    db 0,0,100,0,55,124,10,12,196,0,55,8  ; n2471 t=107.441s dur=100ms, freq=196Hz, sample=55, buffer_id=08:37
    db 16,0,104,0,38,124,10,13,78,0,38,8  ; n2472 t=107.441s dur=104ms, freq=78Hz, sample=38, buffer_id=08:26
    db 78,0,100,0,59,125,8,3,247,0,59,8  ; n2473 t=107.456s dur=100ms, freq=247Hz, sample=59, buffer_id=08:3B
    db 5,0,106,0,59,125,8,8,6,1,59,8  ; n2474 t=107.534s dur=106ms, freq=262Hz, sample=59, buffer_id=08:3B
    db 0,0,119,0,77,125,8,9,186,2,77,8  ; n2475 t=107.539s dur=119ms, freq=698Hz, sample=77, buffer_id=08:4D
    db 5,0,130,0,56,124,10,10,208,0,56,8  ; n2476 t=107.539s dur=130ms, freq=208Hz, sample=56, buffer_id=08:38
    db 104,0,109,0,38,124,10,6,82,0,38,8  ; n2477 t=107.545s dur=109ms, freq=82Hz, sample=38, buffer_id=08:26 [TRUNCATE prev:ch6 @107341.5ms -> 107544.6ms]
    db 0,0,100,0,72,125,8,0,11,2,72,8  ; n2478 t=107.649s dur=100ms, freq=523Hz, sample=72, buffer_id=08:48
    db 5,0,100,0,63,125,8,1,74,1,63,8  ; n2479 t=107.649s dur=100ms, freq=330Hz, sample=63, buffer_id=08:3F
    db 0,0,100,0,53,124,10,5,175,0,53,8  ; n2480 t=107.654s dur=100ms, freq=175Hz, sample=53, buffer_id=08:35
    db 89,0,130,0,43,124,10,7,104,0,43,8  ; n2481 t=107.654s dur=130ms, freq=104Hz, sample=43, buffer_id=08:2B
    db 5,0,100,0,63,125,8,2,55,1,63,8  ; n2482 t=107.743s dur=100ms, freq=311Hz, sample=63, buffer_id=08:3F
    db 0,0,130,0,70,125,8,4,238,1,70,8  ; n2483 t=107.748s dur=130ms, freq=494Hz, sample=70, buffer_id=08:46
    db 21,0,125,0,53,124,10,11,165,0,53,8  ; n2484 t=107.748s dur=125ms, freq=165Hz, sample=53, buffer_id=08:35
    db 62,0,114,0,43,124,10,3,98,0,43,8  ; n2485 t=107.769s dur=114ms, freq=98Hz, sample=43, buffer_id=08:2B
    db 21,0,114,0,63,125,8,12,74,1,63,8  ; n2486 t=107.831s dur=114ms, freq=330Hz, sample=63, buffer_id=08:3F
    db 0,0,125,0,72,125,8,8,11,2,72,8  ; n2487 t=107.852s dur=125ms, freq=523Hz, sample=72, buffer_id=08:48
    db 5,0,109,0,53,124,10,13,175,0,53,8  ; n2488 t=107.852s dur=109ms, freq=175Hz, sample=53, buffer_id=08:35
    db 94,0,104,0,43,124,10,6,104,0,43,8  ; n2489 t=107.857s dur=104ms, freq=104Hz, sample=43, buffer_id=08:2B
    db 5,0,100,0,68,125,8,0,159,1,68,8  ; n2490 t=107.951s dur=100ms, freq=415Hz, sample=68, buffer_id=08:44
    db 5,0,104,0,59,124,10,1,6,1,59,8  ; n2491 t=107.956s dur=104ms, freq=262Hz, sample=59, buffer_id=08:3B
    db 0,0,100,0,75,125,8,5,147,2,75,8  ; n2492 t=107.961s dur=100ms, freq=659Hz, sample=75, buffer_id=08:4B
    db 83,0,104,0,47,124,10,9,123,0,47,8  ; n2493 t=107.961s dur=104ms, freq=123Hz, sample=47, buffer_id=08:2F
    db 16,0,109,0,67,125,8,2,136,1,67,8  ; n2494 t=108.045s dur=109ms, freq=392Hz, sample=67, buffer_id=08:43
    db 0,0,104,0,75,125,8,7,110,2,75,8  ; n2495 t=108.060s dur=104ms, freq=622Hz, sample=75, buffer_id=08:4B
    db 10,0,100,0,59,124,10,10,247,0,59,8  ; n2496 t=108.060s dur=100ms, freq=247Hz, sample=59, buffer_id=08:3B
    db 73,0,100,0,47,124,10,9,117,0,47,8  ; n2497 t=108.071s dur=100ms, freq=117Hz, sample=47, buffer_id=08:2F [TRUNCATE prev:ch9 @107961.3ms -> 108070.7ms]
    db 21,0,100,0,68,125,8,3,159,1,68,8  ; n2498 t=108.144s dur=100ms, freq=415Hz, sample=68, buffer_id=08:44
    db 0,0,100,0,75,125,8,4,147,2,75,8  ; n2499 t=108.164s dur=100ms, freq=659Hz, sample=75, buffer_id=08:4B
    db 5,0,100,0,59,124,10,6,6,1,59,8  ; n2500 t=108.164s dur=100ms, freq=262Hz, sample=59, buffer_id=08:3B
    db 109,0,100,0,47,124,10,11,123,0,47,8  ; n2501 t=108.170s dur=100ms, freq=123Hz, sample=47, buffer_id=08:2F
    db 0,0,100,0,69,125,8,0,184,1,69,8  ; n2502 t=108.279s dur=100ms, freq=440Hz, sample=69, buffer_id=08:45
    db 5,0,104,0,77,125,8,1,186,2,77,8  ; n2503 t=108.279s dur=104ms, freq=698Hz, sample=77, buffer_id=08:4D
    db 5,0,109,0,53,124,10,5,165,0,53,8  ; n2504 t=108.284s dur=109ms, freq=165Hz, sample=53, buffer_id=08:35
    db 89,0,106,0,59,124,10,8,6,1,59,8  ; n2505 t=108.289s dur=106ms, freq=262Hz, sample=59, buffer_id=08:3B
    db 0,0,104,0,75,125,8,2,147,2,75,8  ; n2506 t=108.378s dur=104ms, freq=659Hz, sample=75, buffer_id=08:4B
    db 5,0,100,0,68,125,8,7,159,1,68,8  ; n2507 t=108.378s dur=100ms, freq=415Hz, sample=68, buffer_id=08:44
    db 5,0,104,0,59,124,10,9,247,0,59,8  ; n2508 t=108.383s dur=104ms, freq=247Hz, sample=59, buffer_id=08:3B
    db 83,0,100,0,47,124,10,10,131,0,47,8  ; n2509 t=108.388s dur=100ms, freq=131Hz, sample=47, buffer_id=08:2F
    db 5,0,114,0,77,125,8,3,186,2,77,8  ; n2510 t=108.472s dur=114ms, freq=698Hz, sample=77, buffer_id=08:4D
    db 5,0,100,0,69,125,8,4,184,1,69,8  ; n2511 t=108.477s dur=100ms, freq=440Hz, sample=69, buffer_id=08:45
    db 5,0,130,0,47,124,10,6,123,0,47,8  ; n2512 t=108.482s dur=130ms, freq=123Hz, sample=47, buffer_id=08:2F
    db 104,0,167,0,56,124,10,11,220,0,56,8  ; n2513 t=108.487s dur=167ms, freq=220Hz, sample=56, buffer_id=08:38
    db 0,0,100,0,70,125,8,0,238,1,70,8  ; n2514 t=108.591s dur=100ms, freq=494Hz, sample=70, buffer_id=08:46
    db 0,0,104,0,82,125,8,1,63,3,82,8  ; n2515 t=108.591s dur=104ms, freq=831Hz, sample=82, buffer_id=08:52
    db 26,0,119,0,53,124,10,12,175,0,53,8  ; n2516 t=108.591s dur=119ms, freq=175Hz, sample=53, buffer_id=08:35
    db 62,0,100,0,56,124,10,5,208,0,56,8  ; n2517 t=108.618s dur=100ms, freq=208Hz, sample=56, buffer_id=08:38
    db 10,0,100,0,69,125,8,7,184,1,69,8  ; n2518 t=108.680s dur=100ms, freq=440Hz, sample=69, buffer_id=08:45
    db 5,0,104,0,77,125,8,2,16,3,77,8  ; n2519 t=108.691s dur=104ms, freq=784Hz, sample=77, buffer_id=08:4D
    db 21,0,140,0,53,124,10,8,165,0,53,8  ; n2520 t=108.696s dur=140ms, freq=165Hz, sample=53, buffer_id=08:35
    db 31,0,100,0,59,124,10,10,247,0,59,8  ; n2521 t=108.716s dur=100ms, freq=247Hz, sample=59, buffer_id=08:3B
    db 21,0,114,0,52,102,6,9,165,0,52,6  ; n2522 t=108.748s dur=114ms, freq=165Hz, sample=52, buffer_id=06:34
    db 10,0,138,0,52,102,6,13,175,0,52,6  ; n2523 t=108.769s dur=138ms, freq=175Hz, sample=52, buffer_id=06:34
    db 16,0,104,0,70,125,8,4,238,1,70,8  ; n2524 t=108.779s dur=104ms, freq=494Hz, sample=70, buffer_id=08:46
    db 5,0,100,0,82,125,8,3,63,3,82,8  ; n2525 t=108.795s dur=100ms, freq=831Hz, sample=82, buffer_id=08:52
    db 10,0,100,0,47,124,10,6,131,0,47,8  ; n2526 t=108.800s dur=100ms, freq=131Hz, sample=47, buffer_id=08:2F [TRUNCATE prev:ch6 @108482.1ms -> 108799.9ms]
    db 68,0,100,0,63,124,10,11,74,1,63,8  ; n2527 t=108.810s dur=100ms, freq=330Hz, sample=63, buffer_id=08:3F [TRUNCATE prev:ch11 @108487.4ms -> 108810.3ms]
    db 16,0,104,0,52,102,6,9,196,0,52,6  ; n2528 t=108.878s dur=104ms, freq=196Hz, sample=52, buffer_id=06:34 [TRUNCATE prev:ch9 @108747.8ms -> 108878.0ms]
    db 10,0,104,0,82,125,8,0,220,3,82,8  ; n2529 t=108.894s dur=104ms, freq=988Hz, sample=82, buffer_id=08:52
    db 5,0,140,0,43,124,10,1,87,0,43,8  ; n2530 t=108.904s dur=140ms, freq=87Hz, sample=43, buffer_id=08:2B
    db 16,0,113,0,59,125,8,10,247,0,59,8  ; n2531 t=108.909s dur=113ms, freq=247Hz, sample=59, buffer_id=08:3B [TRUNCATE prev:ch10 @108716.5ms -> 108909.2ms]
    db 21,0,100,0,63,124,10,5,74,1,63,8  ; n2532 t=108.925s dur=100ms, freq=330Hz, sample=63, buffer_id=08:3F
    db 52,0,100,0,52,102,6,12,220,0,52,6  ; n2533 t=108.946s dur=100ms, freq=220Hz, sample=52, buffer_id=06:34
    db 5,0,109,0,82,125,8,2,164,3,82,8  ; n2534 t=108.998s dur=109ms, freq=932Hz, sample=82, buffer_id=08:52
    db 5,0,100,0,62,102,6,7,247,0,62,6  ; n2535 t=109.003s dur=100ms, freq=247Hz, sample=62, buffer_id=06:3E
    db 0,0,104,0,59,125,8,8,6,1,59,8  ; n2536 t=109.008s dur=104ms, freq=262Hz, sample=59, buffer_id=08:3B [TRUNCATE prev:ch8 @108695.7ms -> 109008.2ms]
    db 21,0,109,0,43,124,10,1,104,0,43,8  ; n2537 t=109.008s dur=109ms, freq=104Hz, sample=43, buffer_id=08:2B [TRUNCATE prev:ch1 @108904.0ms -> 109008.2ms]
    db 42,0,104,0,59,124,10,10,6,1,59,8  ; n2538 t=109.029s dur=104ms, freq=262Hz, sample=59, buffer_id=08:3B [TRUNCATE prev:ch10 @108909.2ms -> 109029.0ms]
    db 21,0,100,0,62,102,6,13,6,1,62,6  ; n2539 t=109.071s dur=100ms, freq=262Hz, sample=62, buffer_id=06:3E [TRUNCATE prev:ch13 @108768.6ms -> 109070.7ms]
    db 16,0,100,0,82,125,8,4,220,3,82,8  ; n2540 t=109.091s dur=100ms, freq=988Hz, sample=82, buffer_id=08:52
    db 5,0,100,0,63,125,8,3,74,1,63,8  ; n2541 t=109.107s dur=100ms, freq=330Hz, sample=63, buffer_id=08:3F
    db 0,0,100,0,62,102,6,6,38,1,62,6  ; n2542 t=109.112s dur=100ms, freq=294Hz, sample=62, buffer_id=06:3E
    db 5,0,109,0,47,124,10,11,123,0,47,8  ; n2543 t=109.112s dur=109ms, freq=123Hz, sample=47, buffer_id=08:2F
    db 42,0,104,0,59,124,10,8,247,0,59,8  ; n2544 t=109.118s dur=104ms, freq=247Hz, sample=59, buffer_id=08:3B [TRUNCATE prev:ch8 @109008.2ms -> 109117.6ms]
    db 42,0,100,0,64,102,6,9,74,1,64,6  ; n2545 t=109.159s dur=100ms, freq=330Hz, sample=64, buffer_id=06:40 [TRUNCATE prev:ch9 @108878.0ms -> 109159.2ms]
    db 5,0,100,0,65,102,6,0,93,1,65,6  ; n2546 t=109.201s dur=100ms, freq=349Hz, sample=65, buffer_id=06:41
    db 5,0,119,0,65,125,8,5,93,1,65,8  ; n2547 t=109.206s dur=119ms, freq=349Hz, sample=65, buffer_id=08:41 [TRUNCATE prev:ch5 @108924.9ms -> 109206.1ms]
    db 10,0,114,0,70,125,8,12,238,1,70,8  ; n2548 t=109.211s dur=114ms, freq=494Hz, sample=70, buffer_id=08:46 [TRUNCATE prev:ch12 @108945.7ms -> 109211.3ms]
    db 10,0,100,0,47,124,10,11,131,0,47,8  ; n2549 t=109.222s dur=100ms, freq=131Hz, sample=47, buffer_id=08:2F [TRUNCATE prev:ch11 @109112.4ms -> 109221.7ms]
    db 10,0,125,0,56,124,10,2,208,0,56,8  ; n2550 t=109.232s dur=125ms, freq=208Hz, sample=56, buffer_id=08:38 [TRUNCATE prev:ch2 @108997.8ms -> 109232.1ms]
    db 42,0,100,0,67,102,6,7,136,1,67,6  ; n2551 t=109.243s dur=100ms, freq=392Hz, sample=67, buffer_id=06:43 [TRUNCATE prev:ch7 @109003.0ms -> 109242.6ms]
    db 21,0,100,0,70,102,6,1,184,1,70,6  ; n2552 t=109.284s dur=100ms, freq=440Hz, sample=70, buffer_id=06:46 [TRUNCATE prev:ch1 @109008.2ms -> 109284.2ms]
    db 0,0,100,0,68,125,8,10,159,1,68,8  ; n2553 t=109.305s dur=100ms, freq=415Hz, sample=68, buffer_id=08:44 [TRUNCATE prev:ch10 @109029.0ms -> 109305.1ms]
    db 16,0,104,0,72,125,8,13,11,2,72,8  ; n2554 t=109.305s dur=104ms, freq=523Hz, sample=72, buffer_id=08:48 [TRUNCATE prev:ch13 @109070.7ms -> 109305.1ms]
    db 10,0,109,0,47,124,10,4,123,0,47,8  ; n2555 t=109.321s dur=109ms, freq=123Hz, sample=47, buffer_id=08:2F [TRUNCATE prev:ch4 @109091.5ms -> 109320.7ms]
    db 10,0,100,0,70,102,6,3,238,1,70,6  ; n2556 t=109.331s dur=100ms, freq=494Hz, sample=70, buffer_id=06:46 [TRUNCATE prev:ch3 @109107.1ms -> 109331.1ms]
    db 52,0,100,0,63,124,10,6,74,1,63,8  ; n2557 t=109.341s dur=100ms, freq=330Hz, sample=63, buffer_id=08:3F [TRUNCATE prev:ch6 @109112.4ms -> 109341.5ms]
    db 10,0,100,0,70,102,6,1,11,2,70,6  ; n2558 t=109.394s dur=100ms, freq=523Hz, sample=70, buffer_id=06:46 [TRUNCATE prev:ch1 @109284.2ms -> 109393.6ms]
    db 5,0,104,0,70,125,8,12,238,1,70,8  ; n2559 t=109.404s dur=104ms, freq=494Hz, sample=70, buffer_id=08:46 [TRUNCATE prev:ch12 @109211.3ms -> 109404.0ms]
    db 16,0,104,0,75,125,8,8,147,2,75,8  ; n2560 t=109.409s dur=104ms, freq=659Hz, sample=75, buffer_id=08:4B [TRUNCATE prev:ch8 @109117.6ms -> 109409.2ms]
    db 0,0,100,0,68,124,10,10,159,1,68,8  ; n2561 t=109.425s dur=100ms, freq=415Hz, sample=68, buffer_id=08:44 [TRUNCATE prev:ch10 @109305.1ms -> 109424.9ms]
    db 26,0,104,0,47,124,10,11,131,0,47,8  ; n2562 t=109.425s dur=104ms, freq=131Hz, sample=47, buffer_id=08:2F [TRUNCATE prev:ch11 @109221.7ms -> 109424.9ms]
    db 62,0,100,0,75,102,6,9,75,2,75,6  ; n2563 t=109.451s dur=100ms, freq=587Hz, sample=75, buffer_id=06:4B [TRUNCATE prev:ch9 @109159.2ms -> 109450.9ms]
    db 77,1,125,0,75,102,6,0,147,2,75,6  ; n2564 t=109.513s dur=125ms, freq=659Hz, sample=75, buffer_id=06:4B
    db 0,0,100,0,65,124,4,0,74,1,65,4  ; n2565 t=109.847s dur=100ms, freq=330Hz, sample=65, buffer_id=04:41
    db 0,0,100,0,58,124,4,1,6,1,58,4  ; n2566 t=109.847s dur=100ms, freq=262Hz, sample=58, buffer_id=04:3A
    db 0,0,100,0,63,125,5,2,74,1,63,5  ; n2567 t=109.847s dur=100ms, freq=330Hz, sample=63, buffer_id=05:3F
    db 5,0,100,0,58,125,5,3,6,1,58,5  ; n2568 t=109.847s dur=100ms, freq=262Hz, sample=58, buffer_id=05:3A
    db 0,0,100,0,70,124,4,4,159,1,70,4  ; n2569 t=109.852s dur=100ms, freq=415Hz, sample=70, buffer_id=04:46
    db 115,0,100,0,69,125,5,5,159,1,69,5  ; n2570 t=109.852s dur=100ms, freq=415Hz, sample=69, buffer_id=05:45
    db 0,0,100,0,70,124,4,6,159,1,70,4  ; n2571 t=109.966s dur=100ms, freq=415Hz, sample=70, buffer_id=04:46
    db 0,0,100,0,65,124,4,7,74,1,65,4  ; n2572 t=109.966s dur=100ms, freq=330Hz, sample=65, buffer_id=04:41
    db 0,0,100,0,58,124,4,8,6,1,58,4  ; n2573 t=109.966s dur=100ms, freq=262Hz, sample=58, buffer_id=04:3A
    db 0,0,100,0,69,125,5,9,159,1,69,5  ; n2574 t=109.966s dur=100ms, freq=415Hz, sample=69, buffer_id=05:45
    db 0,0,100,0,63,125,5,10,74,1,63,5  ; n2575 t=109.966s dur=100ms, freq=330Hz, sample=63, buffer_id=05:3F
    db 83,0,100,0,58,125,5,11,6,1,58,5  ; n2576 t=109.966s dur=100ms, freq=262Hz, sample=58, buffer_id=05:3A
    db 0,0,100,0,70,124,4,12,159,1,70,4  ; n2577 t=110.050s dur=100ms, freq=415Hz, sample=70, buffer_id=04:46
    db 0,0,100,0,65,124,4,13,74,1,65,4  ; n2578 t=110.050s dur=100ms, freq=330Hz, sample=65, buffer_id=04:41
    db 0,0,100,0,69,125,5,5,159,1,69,5  ; n2579 t=110.050s dur=100ms, freq=415Hz, sample=69, buffer_id=05:45 [TRUNCATE prev:ch5 @109851.9ms -> 110049.9ms]
    db 10,0,100,0,63,125,5,2,74,1,63,5  ; n2580 t=110.050s dur=100ms, freq=330Hz, sample=63, buffer_id=05:3F [TRUNCATE prev:ch2 @109846.7ms -> 110049.9ms]
    db 0,0,100,0,58,124,4,1,6,1,58,4  ; n2581 t=110.060s dur=100ms, freq=262Hz, sample=58, buffer_id=04:3A [TRUNCATE prev:ch1 @109846.7ms -> 110060.3ms]
    db 104,0,100,0,58,125,5,3,6,1,58,5  ; n2582 t=110.060s dur=100ms, freq=262Hz, sample=58, buffer_id=05:3A [TRUNCATE prev:ch3 @109846.7ms -> 110060.3ms]
    db 0,0,100,0,65,124,4,4,93,1,65,4  ; n2583 t=110.164s dur=100ms, freq=349Hz, sample=65, buffer_id=04:41
    db 0,0,100,0,70,124,4,0,184,1,70,4  ; n2584 t=110.164s dur=100ms, freq=440Hz, sample=70, buffer_id=04:46
    db 0,0,100,0,63,125,5,10,93,1,63,5  ; n2585 t=110.164s dur=100ms, freq=349Hz, sample=63, buffer_id=05:3F [TRUNCATE prev:ch10 @109966.5ms -> 110164.4ms]
    db 5,0,100,0,69,125,5,9,184,1,69,5  ; n2586 t=110.164s dur=100ms, freq=440Hz, sample=69, buffer_id=05:45 [TRUNCATE prev:ch9 @109966.5ms -> 110164.4ms]
    db 0,0,100,0,58,124,4,8,21,1,58,4  ; n2587 t=110.170s dur=100ms, freq=277Hz, sample=58, buffer_id=04:3A [TRUNCATE prev:ch8 @109966.5ms -> 110169.6ms]
    db 94,0,100,0,63,125,5,2,21,1,63,5  ; n2588 t=110.170s dur=100ms, freq=277Hz, sample=63, buffer_id=05:3F [TRUNCATE prev:ch2 @110049.9ms -> 110169.6ms]
    db 0,0,100,0,70,124,4,6,184,1,70,4  ; n2589 t=110.263s dur=100ms, freq=440Hz, sample=70, buffer_id=04:46 [TRUNCATE prev:ch6 @109966.5ms -> 110263.4ms]
    db 0,0,100,0,65,124,4,7,93,1,65,4  ; n2590 t=110.263s dur=100ms, freq=349Hz, sample=65, buffer_id=04:41 [TRUNCATE prev:ch7 @109966.5ms -> 110263.4ms]
    db 0,0,100,0,69,125,5,5,184,1,69,5  ; n2591 t=110.263s dur=100ms, freq=440Hz, sample=69, buffer_id=05:45 [TRUNCATE prev:ch5 @110049.9ms -> 110263.4ms]
    db 5,0,100,0,63,125,5,11,93,1,63,5  ; n2592 t=110.263s dur=100ms, freq=349Hz, sample=63, buffer_id=05:3F [TRUNCATE prev:ch11 @109966.5ms -> 110263.4ms]
    db 0,0,100,0,58,124,4,1,21,1,58,4  ; n2593 t=110.269s dur=100ms, freq=277Hz, sample=58, buffer_id=04:3A [TRUNCATE prev:ch1 @110060.3ms -> 110268.6ms]
    db 94,0,100,0,63,125,5,10,21,1,63,5  ; n2594 t=110.269s dur=100ms, freq=277Hz, sample=63, buffer_id=05:3F [TRUNCATE prev:ch10 @110164.4ms -> 110268.6ms]
    db 0,0,100,0,70,124,4,3,184,1,70,4  ; n2595 t=110.362s dur=100ms, freq=440Hz, sample=70, buffer_id=04:46
    db 0,0,100,0,58,124,4,12,21,1,58,4  ; n2596 t=110.362s dur=100ms, freq=277Hz, sample=58, buffer_id=04:3A
    db 0,0,100,0,65,124,4,13,93,1,65,4  ; n2597 t=110.362s dur=100ms, freq=349Hz, sample=65, buffer_id=04:41 [TRUNCATE prev:ch13 @110049.9ms -> 110362.4ms]
    db 0,0,100,0,69,125,5,9,184,1,69,5  ; n2598 t=110.362s dur=100ms, freq=440Hz, sample=69, buffer_id=05:45 [TRUNCATE prev:ch9 @110164.4ms -> 110362.4ms]
    db 0,0,100,0,63,125,5,2,21,1,63,5  ; n2599 t=110.362s dur=100ms, freq=277Hz, sample=63, buffer_id=05:3F [TRUNCATE prev:ch2 @110169.6ms -> 110362.4ms]
    db 125,0,100,0,63,125,5,0,93,1,63,5  ; n2600 t=110.362s dur=100ms, freq=349Hz, sample=63, buffer_id=05:3F [TRUNCATE prev:ch0 @110164.4ms -> 110362.4ms]
    db 0,0,100,0,65,124,4,8,114,1,65,4  ; n2601 t=110.487s dur=100ms, freq=370Hz, sample=65, buffer_id=04:41
    db 0,0,100,0,58,124,4,4,233,0,58,4  ; n2602 t=110.487s dur=100ms, freq=233Hz, sample=58, buffer_id=04:3A
    db 0,0,100,0,63,125,5,11,114,1,63,5  ; n2603 t=110.487s dur=100ms, freq=370Hz, sample=63, buffer_id=05:3F [TRUNCATE prev:ch11 @110263.4ms -> 110487.4ms]
    db 5,0,100,0,58,125,5,5,233,0,58,5  ; n2604 t=110.487s dur=100ms, freq=233Hz, sample=58, buffer_id=05:3A [TRUNCATE prev:ch5 @110263.4ms -> 110487.4ms]
    db 0,0,100,0,65,124,4,7,38,1,65,4  ; n2605 t=110.493s dur=100ms, freq=294Hz, sample=65, buffer_id=04:41 [TRUNCATE prev:ch7 @110263.4ms -> 110492.6ms]
    db 89,0,100,0,63,125,5,10,38,1,63,5  ; n2606 t=110.493s dur=100ms, freq=294Hz, sample=63, buffer_id=05:3F [TRUNCATE prev:ch10 @110268.6ms -> 110492.6ms]
    db 0,0,100,0,65,124,4,1,114,1,65,4  ; n2607 t=110.581s dur=100ms, freq=370Hz, sample=65, buffer_id=04:41
    db 0,0,100,0,65,124,4,6,38,1,65,4  ; n2608 t=110.581s dur=100ms, freq=294Hz, sample=65, buffer_id=04:41
    db 0,0,100,0,63,125,5,0,114,1,63,5  ; n2609 t=110.581s dur=100ms, freq=370Hz, sample=63, buffer_id=05:3F [TRUNCATE prev:ch0 @110362.4ms -> 110581.1ms]
    db 10,0,100,0,63,125,5,2,38,1,63,5  ; n2610 t=110.581s dur=100ms, freq=294Hz, sample=63, buffer_id=05:3F [TRUNCATE prev:ch2 @110362.4ms -> 110581.1ms]
    db 0,0,100,0,58,124,4,12,233,0,58,4  ; n2611 t=110.591s dur=100ms, freq=233Hz, sample=58, buffer_id=04:3A [TRUNCATE prev:ch12 @110362.4ms -> 110591.5ms]
    db 83,0,100,0,58,125,5,5,233,0,58,5  ; n2612 t=110.591s dur=100ms, freq=233Hz, sample=58, buffer_id=05:3A [TRUNCATE prev:ch5 @110487.4ms -> 110591.5ms]
    db 0,0,100,0,65,124,4,3,114,1,65,4  ; n2613 t=110.675s dur=100ms, freq=370Hz, sample=65, buffer_id=04:41
    db 0,0,100,0,65,124,4,9,38,1,65,4  ; n2614 t=110.675s dur=100ms, freq=294Hz, sample=65, buffer_id=04:41
    db 0,0,100,0,63,125,5,13,114,1,63,5  ; n2615 t=110.675s dur=100ms, freq=370Hz, sample=63, buffer_id=05:3F
    db 10,0,100,0,63,125,5,11,38,1,63,5  ; n2616 t=110.675s dur=100ms, freq=294Hz, sample=63, buffer_id=05:3F [TRUNCATE prev:ch11 @110487.4ms -> 110674.9ms]
    db 0,0,100,0,58,124,4,4,233,0,58,4  ; n2617 t=110.685s dur=100ms, freq=233Hz, sample=58, buffer_id=04:3A [TRUNCATE prev:ch4 @110487.4ms -> 110685.3ms]
    db 73,0,100,0,58,125,5,8,233,0,58,5  ; n2618 t=110.685s dur=100ms, freq=233Hz, sample=58, buffer_id=05:3A [TRUNCATE prev:ch8 @110487.4ms -> 110685.3ms]
    db 10,0,166,0,56,125,8,7,220,0,56,8  ; n2619 t=110.758s dur=166ms, freq=220Hz, sample=56, buffer_id=08:38 [TRUNCATE prev:ch7 @110492.6ms -> 110758.2ms]
    db 16,0,161,0,65,125,8,10,93,1,65,8  ; n2620 t=110.769s dur=161ms, freq=349Hz, sample=65, buffer_id=08:41 [TRUNCATE prev:ch10 @110492.6ms -> 110768.6ms]
    db 0,0,135,0,53,124,10,0,175,0,53,8  ; n2621 t=110.784s dur=135ms, freq=175Hz, sample=53, buffer_id=08:35 [TRUNCATE prev:ch0 @110581.1ms -> 110784.2ms]
    db 10,0,145,0,61,124,10,1,21,1,61,8  ; n2622 t=110.784s dur=145ms, freq=277Hz, sample=61, buffer_id=08:3D [TRUNCATE prev:ch1 @110581.1ms -> 110784.2ms]
    db 0,0,145,0,38,124,10,2,73,0,38,8  ; n2623 t=110.795s dur=145ms, freq=73Hz, sample=38, buffer_id=08:26 [TRUNCATE prev:ch2 @110581.1ms -> 110794.6ms]
    db 51,1,145,0,50,124,10,6,139,0,50,8  ; n2624 t=110.795s dur=145ms, freq=139Hz, sample=50, buffer_id=08:32 [TRUNCATE prev:ch6 @110581.1ms -> 110794.6ms]
    db 0,0,100,0,70,124,4,3,159,1,70,4  ; n2625 t=111.102s dur=100ms, freq=415Hz, sample=70, buffer_id=04:46
    db 0,0,100,0,65,124,4,4,74,1,65,4  ; n2626 t=111.102s dur=100ms, freq=330Hz, sample=65, buffer_id=04:41
    db 0,0,100,0,69,125,5,5,159,1,69,5  ; n2627 t=111.102s dur=100ms, freq=415Hz, sample=69, buffer_id=05:45
    db 5,0,100,0,63,125,5,8,74,1,63,5  ; n2628 t=111.102s dur=100ms, freq=330Hz, sample=63, buffer_id=05:3F
    db 0,0,100,0,58,124,4,9,6,1,58,4  ; n2629 t=111.107s dur=100ms, freq=262Hz, sample=58, buffer_id=04:3A
    db 109,0,100,0,58,125,5,11,6,1,58,5  ; n2630 t=111.107s dur=100ms, freq=262Hz, sample=58, buffer_id=05:3A
    db 0,0,100,0,70,124,4,0,159,1,70,4  ; n2631 t=111.216s dur=100ms, freq=415Hz, sample=70, buffer_id=04:46
    db 0,0,100,0,58,124,4,1,6,1,58,4  ; n2632 t=111.216s dur=100ms, freq=262Hz, sample=58, buffer_id=04:3A
    db 0,0,100,0,65,124,4,2,74,1,65,4  ; n2633 t=111.216s dur=100ms, freq=330Hz, sample=65, buffer_id=04:41
    db 0,0,100,0,69,125,5,6,159,1,69,5  ; n2634 t=111.216s dur=100ms, freq=415Hz, sample=69, buffer_id=05:45
    db 0,0,100,0,58,125,5,7,6,1,58,5  ; n2635 t=111.216s dur=100ms, freq=262Hz, sample=58, buffer_id=05:3A
    db 83,0,100,0,63,125,5,10,74,1,63,5  ; n2636 t=111.216s dur=100ms, freq=330Hz, sample=63, buffer_id=05:3F
    db 0,0,100,0,70,124,4,12,159,1,70,4  ; n2637 t=111.300s dur=100ms, freq=415Hz, sample=70, buffer_id=04:46
    db 0,0,100,0,65,124,4,13,74,1,65,4  ; n2638 t=111.300s dur=100ms, freq=330Hz, sample=65, buffer_id=04:41
    db 0,0,100,0,69,125,5,5,159,1,69,5  ; n2639 t=111.300s dur=100ms, freq=415Hz, sample=69, buffer_id=05:45 [TRUNCATE prev:ch5 @111101.9ms -> 111299.9ms]
    db 5,0,100,0,63,125,5,8,74,1,63,5  ; n2640 t=111.300s dur=100ms, freq=330Hz, sample=63, buffer_id=05:3F [TRUNCATE prev:ch8 @111101.9ms -> 111299.9ms]
    db 0,0,100,0,58,124,4,9,6,1,58,4  ; n2641 t=111.305s dur=100ms, freq=262Hz, sample=58, buffer_id=04:3A [TRUNCATE prev:ch9 @111107.1ms -> 111305.1ms]
    db 115,0,100,0,58,125,5,11,6,1,58,5  ; n2642 t=111.305s dur=100ms, freq=262Hz, sample=58, buffer_id=05:3A [TRUNCATE prev:ch11 @111107.1ms -> 111305.1ms]
    db 0,0,100,0,65,124,4,3,93,1,65,4  ; n2643 t=111.420s dur=100ms, freq=349Hz, sample=65, buffer_id=04:41
    db 0,0,100,0,58,124,4,4,21,1,58,4  ; n2644 t=111.420s dur=100ms, freq=277Hz, sample=58, buffer_id=04:3A
    db 0,0,100,0,63,125,5,10,93,1,63,5  ; n2645 t=111.420s dur=100ms, freq=349Hz, sample=63, buffer_id=05:3F [TRUNCATE prev:ch10 @111216.5ms -> 111419.6ms]
    db 5,0,100,0,63,125,5,8,21,1,63,5  ; n2646 t=111.420s dur=100ms, freq=277Hz, sample=63, buffer_id=05:3F [TRUNCATE prev:ch8 @111299.9ms -> 111419.6ms]
    db 0,0,100,0,70,124,4,0,184,1,70,4  ; n2647 t=111.425s dur=100ms, freq=440Hz, sample=70, buffer_id=04:46 [TRUNCATE prev:ch0 @111216.5ms -> 111424.9ms]
    db 94,0,100,0,69,125,5,6,184,1,69,5  ; n2648 t=111.425s dur=100ms, freq=440Hz, sample=69, buffer_id=05:45 [TRUNCATE prev:ch6 @111216.5ms -> 111424.9ms]
    db 0,0,100,0,65,124,4,1,93,1,65,4  ; n2649 t=111.519s dur=100ms, freq=349Hz, sample=65, buffer_id=04:41
    db 0,0,100,0,70,124,4,2,184,1,70,4  ; n2650 t=111.519s dur=100ms, freq=440Hz, sample=70, buffer_id=04:46
    db 0,0,100,0,63,125,5,7,93,1,63,5  ; n2651 t=111.519s dur=100ms, freq=349Hz, sample=63, buffer_id=05:3F
    db 10,0,100,0,69,125,5,5,184,1,69,5  ; n2652 t=111.519s dur=100ms, freq=440Hz, sample=69, buffer_id=05:45 [TRUNCATE prev:ch5 @111299.9ms -> 111518.6ms]
    db 0,0,100,0,58,124,4,9,21,1,58,4  ; n2653 t=111.529s dur=100ms, freq=277Hz, sample=58, buffer_id=04:3A [TRUNCATE prev:ch9 @111305.1ms -> 111529.0ms]
    db 83,0,100,0,63,125,5,8,21,1,63,5  ; n2654 t=111.529s dur=100ms, freq=277Hz, sample=63, buffer_id=05:3F [TRUNCATE prev:ch8 @111419.6ms -> 111529.0ms]
    db 0,0,100,0,65,124,4,11,93,1,65,4  ; n2655 t=111.612s dur=100ms, freq=349Hz, sample=65, buffer_id=04:41
    db 5,0,100,0,63,125,5,12,93,1,63,5  ; n2656 t=111.612s dur=100ms, freq=349Hz, sample=63, buffer_id=05:3F
    db 0,0,100,0,70,124,4,13,184,1,70,4  ; n2657 t=111.618s dur=100ms, freq=440Hz, sample=70, buffer_id=04:46
    db 0,0,100,0,58,124,4,4,21,1,58,4  ; n2658 t=111.618s dur=100ms, freq=277Hz, sample=58, buffer_id=04:3A [TRUNCATE prev:ch4 @111419.6ms -> 111617.6ms]
    db 0,0,100,0,69,125,5,6,184,1,69,5  ; n2659 t=111.618s dur=100ms, freq=440Hz, sample=69, buffer_id=05:45 [TRUNCATE prev:ch6 @111424.9ms -> 111617.6ms]
    db 125,0,100,0,63,125,5,10,21,1,63,5  ; n2660 t=111.618s dur=100ms, freq=277Hz, sample=63, buffer_id=05:3F [TRUNCATE prev:ch10 @111419.6ms -> 111617.6ms]
    db 0,0,100,0,65,124,4,0,114,1,65,4  ; n2661 t=111.743s dur=100ms, freq=370Hz, sample=65, buffer_id=04:41
    db 0,0,100,0,65,124,4,3,38,1,65,4  ; n2662 t=111.743s dur=100ms, freq=294Hz, sample=65, buffer_id=04:41 [TRUNCATE prev:ch3 @111419.6ms -> 111742.6ms]
    db 0,0,100,0,63,125,5,7,114,1,63,5  ; n2663 t=111.743s dur=100ms, freq=370Hz, sample=63, buffer_id=05:3F [TRUNCATE prev:ch7 @111518.6ms -> 111742.6ms]
    db 10,0,100,0,63,125,5,8,38,1,63,5  ; n2664 t=111.743s dur=100ms, freq=294Hz, sample=63, buffer_id=05:3F [TRUNCATE prev:ch8 @111529.0ms -> 111742.6ms]
    db 0,0,100,0,58,124,4,9,233,0,58,4  ; n2665 t=111.753s dur=100ms, freq=233Hz, sample=58, buffer_id=04:3A [TRUNCATE prev:ch9 @111529.0ms -> 111753.0ms]
    db 88,0,100,0,58,125,5,1,233,0,58,5  ; n2666 t=111.753s dur=100ms, freq=233Hz, sample=58, buffer_id=05:3A [TRUNCATE prev:ch1 @111518.6ms -> 111753.0ms]
    db 0,0,100,0,65,124,4,2,114,1,65,4  ; n2667 t=111.841s dur=100ms, freq=370Hz, sample=65, buffer_id=04:41
    db 5,0,100,0,63,125,5,5,114,1,63,5  ; n2668 t=111.841s dur=100ms, freq=370Hz, sample=63, buffer_id=05:3F
    db 0,0,100,0,65,124,4,11,38,1,65,4  ; n2669 t=111.847s dur=100ms, freq=294Hz, sample=65, buffer_id=04:41 [TRUNCATE prev:ch11 @111612.4ms -> 111846.7ms]
    db 0,0,100,0,58,124,4,4,233,0,58,4  ; n2670 t=111.847s dur=100ms, freq=233Hz, sample=58, buffer_id=04:3A [TRUNCATE prev:ch4 @111617.6ms -> 111846.7ms]
    db 0,0,100,0,63,125,5,12,38,1,63,5  ; n2671 t=111.847s dur=100ms, freq=294Hz, sample=63, buffer_id=05:3F [TRUNCATE prev:ch12 @111612.4ms -> 111846.7ms]
    db 78,0,100,0,58,125,5,6,233,0,58,5  ; n2672 t=111.847s dur=100ms, freq=233Hz, sample=58, buffer_id=05:3A [TRUNCATE prev:ch6 @111617.6ms -> 111846.7ms]
    db 0,0,100,0,65,124,4,10,114,1,65,4  ; n2673 t=111.925s dur=100ms, freq=370Hz, sample=65, buffer_id=04:41
    db 10,0,100,0,65,124,4,13,38,1,65,4  ; n2674 t=111.925s dur=100ms, freq=294Hz, sample=65, buffer_id=04:41
    db 94,0,100,0,58,124,4,9,233,0,58,4  ; n2675 t=111.935s dur=100ms, freq=233Hz, sample=58, buffer_id=04:3A [TRUNCATE prev:ch9 @111753.0ms -> 111935.3ms]
    db 5,0,161,0,56,125,8,0,220,0,56,8  ; n2676 t=112.029s dur=161ms, freq=220Hz, sample=56, buffer_id=08:38 [TRUNCATE prev:ch0 @111742.6ms -> 112029.0ms]
    db 0,0,192,0,65,125,8,3,93,1,65,8  ; n2677 t=112.034s dur=192ms, freq=349Hz, sample=65, buffer_id=08:41 [TRUNCATE prev:ch3 @111742.6ms -> 112034.2ms]
    db 0,0,140,0,53,124,10,7,175,0,53,8  ; n2678 t=112.034s dur=140ms, freq=175Hz, sample=53, buffer_id=08:35 [TRUNCATE prev:ch7 @111742.6ms -> 112034.2ms]
    db 10,0,145,0,61,124,10,8,21,1,61,8  ; n2679 t=112.034s dur=145ms, freq=277Hz, sample=61, buffer_id=08:3D [TRUNCATE prev:ch8 @111742.6ms -> 112034.2ms]
    db 10,0,145,0,50,124,10,1,139,0,50,8  ; n2680 t=112.045s dur=145ms, freq=139Hz, sample=50, buffer_id=08:32 [TRUNCATE prev:ch1 @111753.0ms -> 112044.6ms]
    db 36,1,109,0,38,124,10,2,73,0,38,8  ; n2681 t=112.055s dur=109ms, freq=73Hz, sample=38, buffer_id=08:26 [TRUNCATE prev:ch2 @111841.5ms -> 112055.1ms]
    db 0,0,100,0,70,124,4,4,159,1,70,4  ; n2682 t=112.347s dur=100ms, freq=415Hz, sample=70, buffer_id=04:46
    db 0,0,100,0,65,124,4,5,74,1,65,4  ; n2683 t=112.347s dur=100ms, freq=330Hz, sample=65, buffer_id=04:41
    db 0,0,100,0,63,125,5,6,74,1,63,5  ; n2684 t=112.347s dur=100ms, freq=330Hz, sample=63, buffer_id=05:3F
    db 5,0,100,0,58,125,5,9,6,1,58,5  ; n2685 t=112.347s dur=100ms, freq=262Hz, sample=58, buffer_id=05:3A
    db 0,0,100,0,72,124,4,10,11,2,72,4  ; n2686 t=112.352s dur=100ms, freq=523Hz, sample=72, buffer_id=04:48
    db 115,0,100,0,69,125,5,11,159,1,69,5  ; n2687 t=112.352s dur=100ms, freq=415Hz, sample=69, buffer_id=05:45
    db 0,0,100,0,72,124,4,0,11,2,72,4  ; n2688 t=112.466s dur=100ms, freq=523Hz, sample=72, buffer_id=04:48
    db 0,0,100,0,70,124,4,1,159,1,70,4  ; n2689 t=112.466s dur=100ms, freq=415Hz, sample=70, buffer_id=04:46
    db 0,0,100,0,65,124,4,2,74,1,65,4  ; n2690 t=112.466s dur=100ms, freq=330Hz, sample=65, buffer_id=04:41
    db 0,0,100,0,69,125,5,3,159,1,69,5  ; n2691 t=112.466s dur=100ms, freq=415Hz, sample=69, buffer_id=05:45
    db 0,0,100,0,63,125,5,7,74,1,63,5  ; n2692 t=112.466s dur=100ms, freq=330Hz, sample=63, buffer_id=05:3F
    db 83,0,100,0,58,125,5,8,6,1,58,5  ; n2693 t=112.466s dur=100ms, freq=262Hz, sample=58, buffer_id=05:3A
    db 0,0,100,0,72,124,4,12,11,2,72,4  ; n2694 t=112.550s dur=100ms, freq=523Hz, sample=72, buffer_id=04:48
    db 0,0,100,0,70,124,4,13,159,1,70,4  ; n2695 t=112.550s dur=100ms, freq=415Hz, sample=70, buffer_id=04:46
    db 0,0,100,0,69,125,5,11,159,1,69,5  ; n2696 t=112.550s dur=100ms, freq=415Hz, sample=69, buffer_id=05:45 [TRUNCATE prev:ch11 @112351.9ms -> 112549.9ms]
    db 10,0,100,0,63,125,5,6,74,1,63,5  ; n2697 t=112.550s dur=100ms, freq=330Hz, sample=63, buffer_id=05:3F [TRUNCATE prev:ch6 @112346.7ms -> 112549.9ms]
    db 0,0,100,0,65,124,4,5,74,1,65,4  ; n2698 t=112.560s dur=100ms, freq=330Hz, sample=65, buffer_id=04:41 [TRUNCATE prev:ch5 @112346.7ms -> 112560.3ms]
    db 104,0,100,0,58,125,5,9,6,1,58,5  ; n2699 t=112.560s dur=100ms, freq=262Hz, sample=58, buffer_id=05:3A [TRUNCATE prev:ch9 @112346.7ms -> 112560.3ms]
    db 0,0,100,0,70,124,4,10,184,1,70,4  ; n2700 t=112.664s dur=100ms, freq=440Hz, sample=70, buffer_id=04:46
    db 0,0,100,0,72,124,4,4,42,2,72,4  ; n2701 t=112.664s dur=100ms, freq=554Hz, sample=72, buffer_id=04:48
    db 0,0,100,0,63,125,5,7,93,1,63,5  ; n2702 t=112.664s dur=100ms, freq=349Hz, sample=63, buffer_id=05:3F [TRUNCATE prev:ch7 @112466.5ms -> 112664.4ms]
    db 5,0,100,0,69,125,5,3,184,1,69,5  ; n2703 t=112.664s dur=100ms, freq=440Hz, sample=69, buffer_id=05:45 [TRUNCATE prev:ch3 @112466.5ms -> 112664.4ms]
    db 0,0,100,0,65,124,4,2,93,1,65,4  ; n2704 t=112.670s dur=100ms, freq=349Hz, sample=65, buffer_id=04:41 [TRUNCATE prev:ch2 @112466.5ms -> 112669.6ms]
    db 94,0,100,0,63,125,5,6,21,1,63,5  ; n2705 t=112.670s dur=100ms, freq=277Hz, sample=63, buffer_id=05:3F [TRUNCATE prev:ch6 @112549.9ms -> 112669.6ms]
    db 0,0,100,0,72,124,4,0,42,2,72,4  ; n2706 t=112.763s dur=100ms, freq=554Hz, sample=72, buffer_id=04:48 [TRUNCATE prev:ch0 @112466.5ms -> 112763.4ms]
    db 0,0,100,0,70,124,4,1,184,1,70,4  ; n2707 t=112.763s dur=100ms, freq=440Hz, sample=70, buffer_id=04:46 [TRUNCATE prev:ch1 @112466.5ms -> 112763.4ms]
    db 0,0,100,0,69,125,5,11,184,1,69,5  ; n2708 t=112.763s dur=100ms, freq=440Hz, sample=69, buffer_id=05:45 [TRUNCATE prev:ch11 @112549.9ms -> 112763.4ms]
    db 5,0,100,0,63,125,5,8,93,1,63,5  ; n2709 t=112.763s dur=100ms, freq=349Hz, sample=63, buffer_id=05:3F [TRUNCATE prev:ch8 @112466.5ms -> 112763.4ms]
    db 0,0,100,0,65,124,4,5,93,1,65,4  ; n2710 t=112.769s dur=100ms, freq=349Hz, sample=65, buffer_id=04:41 [TRUNCATE prev:ch5 @112560.3ms -> 112768.6ms]
    db 94,0,100,0,63,125,5,7,21,1,63,5  ; n2711 t=112.769s dur=100ms, freq=277Hz, sample=63, buffer_id=05:3F [TRUNCATE prev:ch7 @112664.4ms -> 112768.6ms]
    db 0,0,100,0,72,124,4,9,42,2,72,4  ; n2712 t=112.862s dur=100ms, freq=554Hz, sample=72, buffer_id=04:48
    db 0,0,100,0,65,124,4,12,93,1,65,4  ; n2713 t=112.862s dur=100ms, freq=349Hz, sample=65, buffer_id=04:41
    db 0,0,100,0,70,124,4,13,184,1,70,4  ; n2714 t=112.862s dur=100ms, freq=440Hz, sample=70, buffer_id=04:46 [TRUNCATE prev:ch13 @112549.9ms -> 112862.4ms]
    db 0,0,100,0,69,125,5,3,184,1,69,5  ; n2715 t=112.862s dur=100ms, freq=440Hz, sample=69, buffer_id=05:45 [TRUNCATE prev:ch3 @112664.4ms -> 112862.4ms]
    db 0,0,100,0,63,125,5,6,21,1,63,5  ; n2716 t=112.862s dur=100ms, freq=277Hz, sample=63, buffer_id=05:3F [TRUNCATE prev:ch6 @112669.6ms -> 112862.4ms]
    db 125,0,100,0,63,125,5,4,93,1,63,5  ; n2717 t=112.862s dur=100ms, freq=349Hz, sample=63, buffer_id=05:3F [TRUNCATE prev:ch4 @112664.4ms -> 112862.4ms]
    db 0,0,100,0,70,124,4,2,210,1,70,4  ; n2718 t=112.987s dur=100ms, freq=466Hz, sample=70, buffer_id=04:46
    db 0,0,100,0,65,124,4,10,38,1,65,4  ; n2719 t=112.987s dur=100ms, freq=294Hz, sample=65, buffer_id=04:41
    db 0,0,100,0,63,125,5,8,114,1,63,5  ; n2720 t=112.987s dur=100ms, freq=370Hz, sample=63, buffer_id=05:3F [TRUNCATE prev:ch8 @112763.4ms -> 112987.4ms]
    db 5,0,100,0,58,125,5,0,233,0,58,5  ; n2721 t=112.987s dur=100ms, freq=233Hz, sample=58, buffer_id=05:3A [TRUNCATE prev:ch0 @112763.4ms -> 112987.4ms]
    db 0,0,100,0,65,124,4,5,114,1,65,4  ; n2722 t=112.993s dur=100ms, freq=370Hz, sample=65, buffer_id=04:41 [TRUNCATE prev:ch5 @112768.6ms -> 112992.6ms]
    db 89,0,100,0,63,125,5,7,38,1,63,5  ; n2723 t=112.993s dur=100ms, freq=294Hz, sample=63, buffer_id=05:3F [TRUNCATE prev:ch7 @112768.6ms -> 112992.6ms]
    db 0,0,100,0,70,124,4,11,210,1,70,4  ; n2724 t=113.081s dur=100ms, freq=466Hz, sample=70, buffer_id=04:46
    db 0,0,100,0,65,124,4,1,114,1,65,4  ; n2725 t=113.081s dur=100ms, freq=370Hz, sample=65, buffer_id=04:41
    db 0,0,100,0,63,125,5,4,114,1,63,5  ; n2726 t=113.081s dur=100ms, freq=370Hz, sample=63, buffer_id=05:3F [TRUNCATE prev:ch4 @112862.4ms -> 113081.1ms]
    db 10,0,100,0,63,125,5,6,38,1,63,5  ; n2727 t=113.081s dur=100ms, freq=294Hz, sample=63, buffer_id=05:3F [TRUNCATE prev:ch6 @112862.4ms -> 113081.1ms]
    db 0,0,100,0,65,124,4,12,38,1,65,4  ; n2728 t=113.091s dur=100ms, freq=294Hz, sample=65, buffer_id=04:41 [TRUNCATE prev:ch12 @112862.4ms -> 113091.5ms]
    db 83,0,100,0,58,125,5,0,233,0,58,5  ; n2729 t=113.091s dur=100ms, freq=233Hz, sample=58, buffer_id=05:3A [TRUNCATE prev:ch0 @112987.4ms -> 113091.5ms]
    db 0,0,100,0,70,124,4,3,210,1,70,4  ; n2730 t=113.175s dur=100ms, freq=466Hz, sample=70, buffer_id=04:46
    db 0,0,100,0,65,124,4,9,114,1,65,4  ; n2731 t=113.175s dur=100ms, freq=370Hz, sample=65, buffer_id=04:41
    db 0,0,100,0,63,125,5,13,114,1,63,5  ; n2732 t=113.175s dur=100ms, freq=370Hz, sample=63, buffer_id=05:3F
    db 10,0,100,0,63,125,5,8,38,1,63,5  ; n2733 t=113.175s dur=100ms, freq=294Hz, sample=63, buffer_id=05:3F [TRUNCATE prev:ch8 @112987.4ms -> 113174.9ms]
    db 0,0,100,0,65,124,4,10,38,1,65,4  ; n2734 t=113.185s dur=100ms, freq=294Hz, sample=65, buffer_id=04:41 [TRUNCATE prev:ch10 @112987.4ms -> 113185.3ms]
    db 73,0,100,0,58,125,5,2,233,0,58,5  ; n2735 t=113.185s dur=100ms, freq=233Hz, sample=58, buffer_id=05:3A [TRUNCATE prev:ch2 @112987.4ms -> 113185.3ms]
    db 5,0,166,0,56,125,8,5,220,0,56,8  ; n2736 t=113.258s dur=166ms, freq=220Hz, sample=56, buffer_id=08:38 [TRUNCATE prev:ch5 @112992.6ms -> 113258.2ms]
    db 26,0,177,0,65,125,8,7,93,1,65,8  ; n2737 t=113.263s dur=177ms, freq=349Hz, sample=65, buffer_id=08:41 [TRUNCATE prev:ch7 @112992.6ms -> 113263.4ms]
    db 0,0,104,0,53,124,10,1,175,0,53,8  ; n2738 t=113.289s dur=104ms, freq=175Hz, sample=53, buffer_id=08:35 [TRUNCATE prev:ch1 @113081.1ms -> 113289.4ms]
    db 10,0,114,0,61,124,10,4,21,1,61,8  ; n2739 t=113.289s dur=114ms, freq=277Hz, sample=61, buffer_id=08:3D [TRUNCATE prev:ch4 @113081.1ms -> 113289.4ms]
    db 0,0,130,0,38,124,10,6,73,0,38,8  ; n2740 t=113.300s dur=130ms, freq=73Hz, sample=38, buffer_id=08:26 [TRUNCATE prev:ch6 @113081.1ms -> 113299.9ms]
    db 26,0,145,0,50,124,10,11,139,0,50,8  ; n2741 t=113.300s dur=145ms, freq=139Hz, sample=50, buffer_id=08:32 [TRUNCATE prev:ch11 @113081.1ms -> 113299.9ms]
    db 20,1,139,1,25,124,10,0,35,0,25,8  ; n2742 t=113.326s dur=395ms, freq=35Hz, sample=25, buffer_id=08:19 [TRUNCATE prev:ch0 @113091.5ms -> 113325.9ms]
    db 0,0,100,0,72,124,4,1,11,2,72,4  ; n2743 t=113.602s dur=100ms, freq=523Hz, sample=72, buffer_id=04:48
    db 0,0,100,0,70,124,4,2,159,1,70,4  ; n2744 t=113.602s dur=100ms, freq=415Hz, sample=70, buffer_id=04:46
    db 0,0,100,0,69,125,5,3,159,1,69,5  ; n2745 t=113.602s dur=100ms, freq=415Hz, sample=69, buffer_id=05:45
    db 5,0,100,0,63,125,5,9,74,1,63,5  ; n2746 t=113.602s dur=100ms, freq=330Hz, sample=63, buffer_id=05:3F
    db 0,0,100,0,65,124,4,4,74,1,65,4  ; n2747 t=113.607s dur=100ms, freq=330Hz, sample=65, buffer_id=04:41
    db 109,0,100,0,58,125,5,8,6,1,58,5  ; n2748 t=113.607s dur=100ms, freq=262Hz, sample=58, buffer_id=05:3A
    db 0,0,100,0,72,124,4,5,11,2,72,4  ; n2749 t=113.716s dur=100ms, freq=523Hz, sample=72, buffer_id=04:48
    db 0,0,100,0,65,124,4,6,74,1,65,4  ; n2750 t=113.716s dur=100ms, freq=330Hz, sample=65, buffer_id=04:41
    db 0,0,100,0,70,124,4,7,159,1,70,4  ; n2751 t=113.716s dur=100ms, freq=415Hz, sample=70, buffer_id=04:46
    db 0,0,100,0,69,125,5,10,159,1,69,5  ; n2752 t=113.716s dur=100ms, freq=415Hz, sample=69, buffer_id=05:45
    db 0,0,100,0,58,125,5,11,6,1,58,5  ; n2753 t=113.716s dur=100ms, freq=262Hz, sample=58, buffer_id=05:3A
    db 83,0,100,0,63,125,5,12,74,1,63,5  ; n2754 t=113.716s dur=100ms, freq=330Hz, sample=63, buffer_id=05:3F
    db 0,0,100,0,72,124,4,13,11,2,72,4  ; n2755 t=113.800s dur=100ms, freq=523Hz, sample=72, buffer_id=04:48
    db 0,0,100,0,70,124,4,2,159,1,70,4  ; n2756 t=113.800s dur=100ms, freq=415Hz, sample=70, buffer_id=04:46 [TRUNCATE prev:ch2 @113601.9ms -> 113799.9ms]
    db 0,0,100,0,69,125,5,3,159,1,69,5  ; n2757 t=113.800s dur=100ms, freq=415Hz, sample=69, buffer_id=05:45 [TRUNCATE prev:ch3 @113601.9ms -> 113799.9ms]
    db 5,0,100,0,63,125,5,9,74,1,63,5  ; n2758 t=113.800s dur=100ms, freq=330Hz, sample=63, buffer_id=05:3F [TRUNCATE prev:ch9 @113601.9ms -> 113799.9ms]
    db 0,0,100,0,65,124,4,4,74,1,65,4  ; n2759 t=113.805s dur=100ms, freq=330Hz, sample=65, buffer_id=04:41 [TRUNCATE prev:ch4 @113607.1ms -> 113805.1ms]
    db 115,0,100,0,58,125,5,8,6,1,58,5  ; n2760 t=113.805s dur=100ms, freq=262Hz, sample=58, buffer_id=05:3A [TRUNCATE prev:ch8 @113607.1ms -> 113805.1ms]
    db 0,0,100,0,70,124,4,1,184,1,70,4  ; n2761 t=113.920s dur=100ms, freq=440Hz, sample=70, buffer_id=04:46
    db 0,0,100,0,65,124,4,6,93,1,65,4  ; n2762 t=113.920s dur=100ms, freq=349Hz, sample=65, buffer_id=04:41 [TRUNCATE prev:ch6 @113716.5ms -> 113919.6ms]
    db 0,0,100,0,63,125,5,12,93,1,63,5  ; n2763 t=113.920s dur=100ms, freq=349Hz, sample=63, buffer_id=05:3F [TRUNCATE prev:ch12 @113716.5ms -> 113919.6ms]
    db 5,0,100,0,63,125,5,9,21,1,63,5  ; n2764 t=113.920s dur=100ms, freq=277Hz, sample=63, buffer_id=05:3F [TRUNCATE prev:ch9 @113799.9ms -> 113919.6ms]
    db 0,0,100,0,72,124,4,0,42,2,72,4  ; n2765 t=113.925s dur=100ms, freq=554Hz, sample=72, buffer_id=04:48
    db 94,0,100,0,69,125,5,10,184,1,69,5  ; n2766 t=113.925s dur=100ms, freq=440Hz, sample=69, buffer_id=05:45 [TRUNCATE prev:ch10 @113716.5ms -> 113924.9ms]
    db 0,0,100,0,70,124,4,5,184,1,70,4  ; n2767 t=114.019s dur=100ms, freq=440Hz, sample=70, buffer_id=04:46
    db 0,0,100,0,72,124,4,7,42,2,72,4  ; n2768 t=114.019s dur=100ms, freq=554Hz, sample=72, buffer_id=04:48
    db 0,0,100,0,63,125,5,11,93,1,63,5  ; n2769 t=114.019s dur=100ms, freq=349Hz, sample=63, buffer_id=05:3F
    db 10,0,100,0,69,125,5,3,184,1,69,5  ; n2770 t=114.019s dur=100ms, freq=440Hz, sample=69, buffer_id=05:45 [TRUNCATE prev:ch3 @113799.9ms -> 114018.6ms]
    db 0,0,100,0,65,124,4,4,93,1,65,4  ; n2771 t=114.029s dur=100ms, freq=349Hz, sample=65, buffer_id=04:41 [TRUNCATE prev:ch4 @113805.1ms -> 114029.0ms]
    db 83,0,100,0,63,125,5,9,21,1,63,5  ; n2772 t=114.029s dur=100ms, freq=277Hz, sample=63, buffer_id=05:3F [TRUNCATE prev:ch9 @113919.6ms -> 114029.0ms]
    db 0,0,100,0,70,124,4,8,184,1,70,4  ; n2773 t=114.112s dur=100ms, freq=440Hz, sample=70, buffer_id=04:46
    db 5,0,100,0,63,125,5,2,93,1,63,5  ; n2774 t=114.112s dur=100ms, freq=349Hz, sample=63, buffer_id=05:3F
    db 0,0,100,0,72,124,4,13,42,2,72,4  ; n2775 t=114.118s dur=100ms, freq=554Hz, sample=72, buffer_id=04:48 [TRUNCATE prev:ch13 @113799.9ms -> 114117.6ms]
    db 0,0,100,0,65,124,4,6,93,1,65,4  ; n2776 t=114.118s dur=100ms, freq=349Hz, sample=65, buffer_id=04:41 [TRUNCATE prev:ch6 @113919.6ms -> 114117.6ms]
    db 0,0,100,0,69,125,5,10,184,1,69,5  ; n2777 t=114.118s dur=100ms, freq=440Hz, sample=69, buffer_id=05:45 [TRUNCATE prev:ch10 @113924.9ms -> 114117.6ms]
    db 125,0,100,0,63,125,5,12,21,1,63,5  ; n2778 t=114.118s dur=100ms, freq=277Hz, sample=63, buffer_id=05:3F [TRUNCATE prev:ch12 @113919.6ms -> 114117.6ms]
    db 0,0,100,0,70,124,4,0,210,1,70,4  ; n2779 t=114.243s dur=100ms, freq=466Hz, sample=70, buffer_id=04:46
    db 0,0,100,0,65,124,4,1,114,1,65,4  ; n2780 t=114.243s dur=100ms, freq=370Hz, sample=65, buffer_id=04:41
    db 0,0,100,0,63,125,5,11,114,1,63,5  ; n2781 t=114.243s dur=100ms, freq=370Hz, sample=63, buffer_id=05:3F [TRUNCATE prev:ch11 @114018.6ms -> 114242.6ms]
    db 10,0,100,0,63,125,5,9,38,1,63,5  ; n2782 t=114.243s dur=100ms, freq=294Hz, sample=63, buffer_id=05:3F [TRUNCATE prev:ch9 @114029.0ms -> 114242.6ms]
    db 0,0,100,0,65,124,4,4,38,1,65,4  ; n2783 t=114.253s dur=100ms, freq=294Hz, sample=65, buffer_id=04:41 [TRUNCATE prev:ch4 @114029.0ms -> 114253.0ms]
    db 88,0,100,0,58,125,5,3,233,0,58,5  ; n2784 t=114.253s dur=100ms, freq=233Hz, sample=58, buffer_id=05:3A [TRUNCATE prev:ch3 @114018.6ms -> 114253.0ms]
    db 0,0,100,0,70,124,4,7,210,1,70,4  ; n2785 t=114.341s dur=100ms, freq=466Hz, sample=70, buffer_id=04:46
    db 5,0,100,0,63,125,5,5,114,1,63,5  ; n2786 t=114.341s dur=100ms, freq=370Hz, sample=63, buffer_id=05:3F
    db 0,0,100,0,65,124,4,6,114,1,65,4  ; n2787 t=114.347s dur=100ms, freq=370Hz, sample=65, buffer_id=04:41 [TRUNCATE prev:ch6 @114117.6ms -> 114346.7ms]
    db 0,0,100,0,65,124,4,1,38,1,65,4  ; n2788 t=114.347s dur=100ms, freq=294Hz, sample=65, buffer_id=04:41 [TRUNCATE prev:ch1 @114242.6ms -> 114346.7ms]
    db 0,0,100,0,63,125,5,2,38,1,63,5  ; n2789 t=114.347s dur=100ms, freq=294Hz, sample=63, buffer_id=05:3F [TRUNCATE prev:ch2 @114112.4ms -> 114346.7ms]
    db 89,0,100,0,58,125,5,8,233,0,58,5  ; n2790 t=114.347s dur=100ms, freq=233Hz, sample=58, buffer_id=05:3A [TRUNCATE prev:ch8 @114112.4ms -> 114346.7ms]
    db 0,0,100,0,70,124,4,10,210,1,70,4  ; n2791 t=114.435s dur=100ms, freq=466Hz, sample=70, buffer_id=04:46
    db 0,0,100,0,65,124,4,12,114,1,65,4  ; n2792 t=114.435s dur=100ms, freq=370Hz, sample=65, buffer_id=04:41
    db 0,0,100,0,63,125,5,13,114,1,63,5  ; n2793 t=114.435s dur=100ms, freq=370Hz, sample=63, buffer_id=05:3F
    db 5,0,100,0,63,125,5,9,38,1,63,5  ; n2794 t=114.435s dur=100ms, freq=294Hz, sample=63, buffer_id=05:3F [TRUNCATE prev:ch9 @114242.6ms -> 114435.3ms]
    db 0,0,100,0,65,124,4,4,38,1,65,4  ; n2795 t=114.441s dur=100ms, freq=294Hz, sample=65, buffer_id=04:41 [TRUNCATE prev:ch4 @114253.0ms -> 114440.5ms]
    db 115,0,100,0,58,125,5,3,233,0,58,5  ; n2796 t=114.441s dur=100ms, freq=233Hz, sample=58, buffer_id=05:3A [TRUNCATE prev:ch3 @114253.0ms -> 114440.5ms]
    db 10,0,4,1,53,125,5,0,185,0,53,5  ; n2797 t=114.555s dur=260ms, freq=185Hz, sample=53, buffer_id=05:35
    db 10,0,3,9,25,76,9,11,35,0,25,8  ; n2798 t=114.566s dur=2307ms, freq=35Hz, sample=25, buffer_id=08:19
    db 0,0,4,1,42,125,5,5,92,0,42,5  ; n2799 t=114.576s dur=260ms, freq=92Hz, sample=42, buffer_id=05:2A [TRUNCATE prev:ch5 @114341.5ms -> 114575.9ms]
    db 5,0,4,1,48,125,5,7,139,0,48,5  ; n2800 t=114.576s dur=260ms, freq=139Hz, sample=48, buffer_id=05:30 [TRUNCATE prev:ch7 @114341.5ms -> 114575.9ms]
    db 0,0,4,1,72,124,4,1,11,2,72,4  ; n2801 t=114.581s dur=260ms, freq=523Hz, sample=72, buffer_id=04:48 [TRUNCATE prev:ch1 @114346.7ms -> 114581.1ms]
    db 5,0,4,1,65,124,4,6,136,1,65,4  ; n2802 t=114.581s dur=260ms, freq=392Hz, sample=65, buffer_id=04:41 [TRUNCATE prev:ch6 @114346.7ms -> 114581.1ms]
    db 82,2,4,1,58,124,4,2,6,1,58,4  ; n2803 t=114.586s dur=260ms, freq=262Hz, sample=58, buffer_id=04:3A [TRUNCATE prev:ch2 @114346.7ms -> 114586.3ms]
    db 0,0,130,0,65,124,4,0,136,1,65,4  ; n2804 t=115.180s dur=130ms, freq=392Hz, sample=65, buffer_id=04:41
    db 10,0,145,0,58,124,4,1,6,1,58,4  ; n2805 t=115.180s dur=145ms, freq=262Hz, sample=58, buffer_id=04:3A
    db 10,0,119,0,72,124,4,2,11,2,72,4  ; n2806 t=115.191s dur=119ms, freq=523Hz, sample=72, buffer_id=04:48
    db 0,0,135,0,48,125,5,3,139,0,48,5  ; n2807 t=115.201s dur=135ms, freq=139Hz, sample=48, buffer_id=05:30
    db 5,0,145,0,53,125,5,4,185,0,53,5  ; n2808 t=115.201s dur=145ms, freq=185Hz, sample=53, buffer_id=05:35
    db 30,1,130,0,42,125,5,6,92,0,42,5  ; n2809 t=115.206s dur=130ms, freq=92Hz, sample=42, buffer_id=05:2A
    db 0,0,4,1,48,125,5,5,139,0,48,5  ; n2810 t=115.493s dur=260ms, freq=139Hz, sample=48, buffer_id=05:30
    db 5,0,4,1,53,125,5,7,185,0,53,5  ; n2811 t=115.493s dur=260ms, freq=185Hz, sample=53, buffer_id=05:35
    db 10,0,4,1,42,125,5,8,92,0,42,5  ; n2812 t=115.498s dur=260ms, freq=92Hz, sample=42, buffer_id=05:2A
    db 5,0,4,1,72,124,4,9,11,2,72,4  ; n2813 t=115.508s dur=260ms, freq=523Hz, sample=72, buffer_id=04:48
    db 5,0,4,1,65,124,4,2,136,1,65,4  ; n2814 t=115.513s dur=260ms, freq=392Hz, sample=65, buffer_id=04:41
    db 82,2,4,1,58,124,4,0,6,1,58,4  ; n2815 t=115.519s dur=260ms, freq=262Hz, sample=58, buffer_id=04:3A
    db 5,0,4,1,65,124,4,0,136,1,65,4  ; n2816 t=116.112s dur=260ms, freq=392Hz, sample=65, buffer_id=04:41
    db 5,0,4,1,72,124,4,1,11,2,72,4  ; n2817 t=116.118s dur=260ms, freq=523Hz, sample=72, buffer_id=04:48
    db 0,0,4,1,58,124,4,2,6,1,58,4  ; n2818 t=116.123s dur=260ms, freq=262Hz, sample=58, buffer_id=04:3A
    db 10,0,4,1,53,125,5,3,185,0,53,5  ; n2819 t=116.123s dur=260ms, freq=185Hz, sample=53, buffer_id=05:35
    db 5,0,4,1,48,125,5,4,139,0,48,5  ; n2820 t=116.133s dur=260ms, freq=139Hz, sample=48, buffer_id=05:30
    db 76,2,4,1,42,125,5,5,92,0,42,5  ; n2821 t=116.138s dur=260ms, freq=92Hz, sample=42, buffer_id=05:2A
    db 0,0,4,1,72,124,4,0,11,2,72,4  ; n2822 t=116.727s dur=260ms, freq=523Hz, sample=72, buffer_id=04:48
    db 0,0,4,1,65,124,4,1,136,1,65,4  ; n2823 t=116.727s dur=260ms, freq=392Hz, sample=65, buffer_id=04:41
    db 0,0,4,1,58,124,4,3,6,1,58,4  ; n2824 t=116.727s dur=260ms, freq=262Hz, sample=58, buffer_id=04:3A
    db 5,0,4,1,53,125,5,2,185,0,53,5  ; n2825 t=116.727s dur=260ms, freq=185Hz, sample=53, buffer_id=05:35
    db 10,0,4,1,48,125,5,5,139,0,48,5  ; n2826 t=116.732s dur=260ms, freq=139Hz, sample=48, buffer_id=05:30
    db 25,1,4,1,42,125,5,4,92,0,42,5  ; n2827 t=116.743s dur=260ms, freq=92Hz, sample=42, buffer_id=05:2A
    db 11,0,100,0,68,125,8,6,159,1,68,8  ; n2828 t=117.024s dur=100ms, freq=415Hz, sample=68, buffer_id=08:44
    db 16,0,225,2,38,76,9,7,69,0,38,8  ; n2829 t=117.034s dur=737ms, freq=69Hz, sample=38, buffer_id=08:26
    db 74,0,231,0,85,102,6,8,85,4,85,6  ; n2830 t=117.050s dur=231ms, freq=1109Hz, sample=85, buffer_id=06:55
    db 105,0,100,0,72,125,8,9,11,2,72,8  ; n2831 t=117.124s dur=100ms, freq=523Hz, sample=72, buffer_id=08:48
    db 58,0,105,0,72,125,8,0,42,2,72,8  ; n2832 t=117.229s dur=105ms, freq=554Hz, sample=72, buffer_id=08:48
    db 53,0,210,0,82,102,6,1,112,3,82,6  ; n2833 t=117.287s dur=210ms, freq=880Hz, sample=82, buffer_id=06:52
    db 105,0,136,0,77,125,8,2,186,2,77,8  ; n2834 t=117.340s dur=136ms, freq=698Hz, sample=77, buffer_id=08:4D
    db 63,0,100,0,72,125,8,3,42,2,72,8  ; n2835 t=117.445s dur=100ms, freq=554Hz, sample=72, buffer_id=08:48
    db 37,0,197,0,77,102,6,4,186,2,77,6  ; n2836 t=117.508s dur=197ms, freq=698Hz, sample=77, buffer_id=06:4D
    db 112,0,112,0,72,125,8,5,11,2,72,8  ; n2837 t=117.545s dur=112ms, freq=523Hz, sample=72, buffer_id=08:48
    db 70,0,100,0,68,125,8,0,159,1,68,8  ; n2838 t=117.657s dur=100ms, freq=415Hz, sample=68, buffer_id=08:44
    db 38,0,204,0,85,102,6,1,85,4,85,6  ; n2839 t=117.727s dur=204ms, freq=1109Hz, sample=85, buffer_id=06:55
    db 91,0,118,0,72,125,8,2,11,2,72,8  ; n2840 t=117.765s dur=118ms, freq=523Hz, sample=72, buffer_id=08:48
    db 86,0,123,0,72,125,8,6,42,2,72,8  ; n2841 t=117.856s dur=123ms, freq=554Hz, sample=72, buffer_id=08:48
    db 38,0,216,0,82,102,6,3,112,3,82,6  ; n2842 t=117.942s dur=216ms, freq=880Hz, sample=82, buffer_id=06:52
    db 0,0,140,0,69,125,5,0,159,1,69,5  ; n2843 t=117.980s dur=140ms, freq=415Hz, sample=69, buffer_id=05:45
    db 5,0,113,0,77,125,8,4,186,2,77,8  ; n2844 t=117.980s dur=113ms, freq=698Hz, sample=77, buffer_id=08:4D
    db 16,0,140,0,63,125,5,5,93,1,63,5  ; n2845 t=117.985s dur=140ms, freq=349Hz, sample=63, buffer_id=05:3F
    db 75,0,135,0,63,125,5,7,21,1,63,5  ; n2846 t=118.001s dur=135ms, freq=277Hz, sample=63, buffer_id=05:3F
    db 82,0,114,0,72,125,8,8,42,2,72,8  ; n2847 t=118.077s dur=114ms, freq=554Hz, sample=72, buffer_id=08:48
    db 22,0,192,0,77,102,6,1,186,2,77,6  ; n2848 t=118.159s dur=192ms, freq=698Hz, sample=77, buffer_id=06:4D
    db 115,0,104,0,72,125,8,10,11,2,72,8  ; n2849 t=118.181s dur=104ms, freq=523Hz, sample=72, buffer_id=08:48
    db 5,0,100,0,68,125,8,2,159,1,68,8  ; n2850 t=118.296s dur=100ms, freq=415Hz, sample=68, buffer_id=08:44
    db 5,0,125,3,63,125,5,4,93,1,63,5  ; n2851 t=118.302s dur=893ms, freq=349Hz, sample=63, buffer_id=05:3F
    db 0,0,114,3,69,125,5,6,159,1,69,5  ; n2852 t=118.307s dur=882ms, freq=415Hz, sample=69, buffer_id=05:45
    db 60,0,114,3,63,125,5,9,21,1,63,5  ; n2853 t=118.307s dur=882ms, freq=277Hz, sample=63, buffer_id=05:3F
    db 11,0,225,0,85,102,6,0,85,4,85,6  ; n2854 t=118.367s dur=225ms, freq=1109Hz, sample=85, buffer_id=06:55
    db 22,0,117,5,91,125,8,3,125,6,91,8  ; n2855 t=118.378s dur=1397ms, freq=1661Hz, sample=91, buffer_id=08:5B
    db 110,0,115,0,72,125,8,5,11,2,72,8  ; n2856 t=118.400s dur=115ms, freq=523Hz, sample=72, buffer_id=08:48
    db 82,0,115,0,72,125,8,7,42,2,72,8  ; n2857 t=118.510s dur=115ms, freq=554Hz, sample=72, buffer_id=08:48
    db 33,0,201,0,82,102,6,1,112,3,82,6  ; n2858 t=118.593s dur=201ms, freq=880Hz, sample=82, buffer_id=06:52
    db 107,0,112,0,77,125,8,2,186,2,77,8  ; n2859 t=118.626s dur=112ms, freq=698Hz, sample=77, buffer_id=08:4D
    db 67,0,101,0,72,125,8,11,42,2,72,8  ; n2860 t=118.733s dur=101ms, freq=554Hz, sample=72, buffer_id=08:48
    db 50,0,213,0,77,102,6,0,186,2,77,6  ; n2861 t=118.800s dur=213ms, freq=698Hz, sample=77, buffer_id=06:4D
    db 124,0,134,0,72,125,8,12,11,2,72,8  ; n2862 t=118.851s dur=134ms, freq=523Hz, sample=72, buffer_id=08:48
    db 45,0,100,0,68,125,8,2,159,1,68,8  ; n2863 t=118.974s dur=100ms, freq=415Hz, sample=68, buffer_id=08:44
    db 56,0,250,0,85,102,6,1,85,4,85,6  ; n2864 t=119.019s dur=250ms, freq=1109Hz, sample=85, buffer_id=06:55
    db 108,0,142,0,72,125,8,13,11,2,72,8  ; n2865 t=119.075s dur=142ms, freq=523Hz, sample=72, buffer_id=08:48
    db 75,0,109,0,72,125,8,8,42,2,72,8  ; n2866 t=119.184s dur=109ms, freq=554Hz, sample=72, buffer_id=08:48 [TRUNCATE prev:ch8 @118076.7ms -> 119183.7ms]
    db 34,0,212,0,82,102,6,0,112,3,82,6  ; n2867 t=119.258s dur=212ms, freq=880Hz, sample=82, buffer_id=06:52
    db 11,0,132,0,63,125,5,2,93,1,63,5  ; n2868 t=119.293s dur=132ms, freq=349Hz, sample=63, buffer_id=05:3F
    db 0,0,103,0,69,125,5,5,159,1,69,5  ; n2869 t=119.304s dur=103ms, freq=415Hz, sample=69, buffer_id=05:45
    db 11,0,149,0,77,125,8,7,186,2,77,8  ; n2870 t=119.304s dur=149ms, freq=698Hz, sample=77, buffer_id=08:4D
    db 98,0,103,0,63,125,5,10,21,1,63,5  ; n2871 t=119.316s dur=103ms, freq=277Hz, sample=63, buffer_id=05:3F
    db 63,0,137,0,72,125,8,4,42,2,72,8  ; n2872 t=119.414s dur=137ms, freq=554Hz, sample=72, buffer_id=08:48
    db 52,0,237,0,77,102,6,1,186,2,77,6  ; n2873 t=119.477s dur=237ms, freq=698Hz, sample=77, buffer_id=06:4D
    db 133,0,115,0,72,125,8,6,11,2,72,8  ; n2874 t=119.529s dur=115ms, freq=523Hz, sample=72, buffer_id=08:48
    db 18,0,100,0,68,125,8,2,159,1,68,8  ; n2875 t=119.662s dur=100ms, freq=415Hz, sample=68, buffer_id=08:44
    db 12,0,241,0,63,125,5,0,93,1,63,5  ; n2876 t=119.679s dur=241ms, freq=349Hz, sample=63, buffer_id=05:3F
    db 6,0,91,5,89,125,8,5,117,5,89,8  ; n2877 t=119.691s dur=1371ms, freq=1397Hz, sample=89, buffer_id=08:59
    db 23,0,200,0,69,125,5,7,184,1,69,5  ; n2878 t=119.697s dur=200ms, freq=440Hz, sample=69, buffer_id=05:45
    db 6,0,223,0,85,102,6,8,85,4,85,6  ; n2879 t=119.721s dur=223ms, freq=1109Hz, sample=85, buffer_id=06:55
    db 47,0,194,0,63,125,5,11,21,1,63,5  ; n2880 t=119.727s dur=194ms, freq=277Hz, sample=63, buffer_id=05:3F
    db 118,0,100,0,69,125,8,4,184,1,69,8  ; n2881 t=119.773s dur=100ms, freq=440Hz, sample=69, buffer_id=08:45
    db 53,0,117,0,72,125,8,9,42,2,72,8  ; n2882 t=119.891s dur=117ms, freq=554Hz, sample=72, buffer_id=08:48
    db 71,0,212,0,82,102,6,1,112,3,82,6  ; n2883 t=119.944s dur=212ms, freq=880Hz, sample=82, buffer_id=06:52
    db 118,0,153,0,77,125,8,2,186,2,77,8  ; n2884 t=120.015s dur=153ms, freq=698Hz, sample=77, buffer_id=08:4D
    db 30,0,113,0,72,125,8,0,42,2,72,8  ; n2885 t=120.133s dur=113ms, freq=554Hz, sample=72, buffer_id=08:48
    db 0,0,100,0,63,125,5,3,93,1,63,5  ; n2886 t=120.162s dur=100ms, freq=349Hz, sample=63, buffer_id=05:3F
    db 0,0,101,0,63,125,5,4,21,1,63,5  ; n2887 t=120.162s dur=101ms, freq=277Hz, sample=63, buffer_id=05:3F
    db 6,0,226,0,77,102,6,6,186,2,77,6  ; n2888 t=120.162s dur=226ms, freq=698Hz, sample=77, buffer_id=06:4D
    db 77,0,100,0,69,125,5,8,184,1,69,5  ; n2889 t=120.168s dur=100ms, freq=440Hz, sample=69, buffer_id=05:45
    db 113,0,100,0,69,125,8,7,184,1,69,8  ; n2890 t=120.246s dur=100ms, freq=440Hz, sample=69, buffer_id=08:45
    db 6,0,173,10,69,125,5,1,159,1,69,5  ; n2891 t=120.359s dur=2733ms, freq=415Hz, sample=69, buffer_id=05:45
    db 6,0,201,10,63,125,5,9,21,1,63,5  ; n2892 t=120.365s dur=2761ms, freq=277Hz, sample=63, buffer_id=05:3F
    db 0,0,134,9,63,125,5,2,93,1,63,5  ; n2893 t=120.371s dur=2438ms, freq=349Hz, sample=63, buffer_id=05:3F
    db 36,0,100,0,68,125,8,10,159,1,68,8  ; n2894 t=120.371s dur=100ms, freq=415Hz, sample=68, buffer_id=08:44
    db 83,0,240,0,85,102,6,11,85,4,85,6  ; n2895 t=120.406s dur=240ms, freq=1109Hz, sample=85, buffer_id=06:55
    db 102,0,100,0,69,125,8,0,184,1,69,8  ; n2896 t=120.490s dur=100ms, freq=440Hz, sample=69, buffer_id=08:45
    db 37,0,140,0,72,125,8,3,42,2,72,8  ; n2897 t=120.592s dur=140ms, freq=554Hz, sample=72, buffer_id=08:48
    db 104,0,243,0,82,102,6,4,112,3,82,6  ; n2898 t=120.628s dur=243ms, freq=880Hz, sample=82, buffer_id=06:52
    db 110,0,128,0,77,125,8,6,186,2,77,8  ; n2899 t=120.732s dur=128ms, freq=698Hz, sample=77, buffer_id=08:4D
    db 37,0,128,0,72,125,8,0,42,2,72,8  ; n2900 t=120.842s dur=128ms, freq=554Hz, sample=72, buffer_id=08:48
    db 79,0,227,0,77,102,6,7,186,2,77,6  ; n2901 t=120.878s dur=227ms, freq=698Hz, sample=77, buffer_id=06:4D
    db 92,0,100,0,69,125,8,3,184,1,69,8  ; n2902 t=120.957s dur=100ms, freq=440Hz, sample=69, buffer_id=08:45
    db 37,0,201,5,91,125,8,8,32,6,91,8  ; n2903 t=121.050s dur=1481ms, freq=1568Hz, sample=91, buffer_id=08:5B
    db 31,0,100,0,68,125,8,4,159,1,68,8  ; n2904 t=121.087s dur=100ms, freq=415Hz, sample=68, buffer_id=08:44
    db 88,0,237,0,85,102,6,6,85,4,85,6  ; n2905 t=121.118s dur=237ms, freq=1109Hz, sample=85, buffer_id=06:55
    db 125,0,100,0,69,125,8,0,184,1,69,8  ; n2906 t=121.206s dur=100ms, freq=440Hz, sample=69, buffer_id=08:45
    db 25,0,131,0,72,125,8,3,42,2,72,8  ; n2907 t=121.331s dur=131ms, freq=554Hz, sample=72, buffer_id=08:48
    db 106,0,239,0,82,102,6,5,112,3,82,6  ; n2908 t=121.356s dur=239ms, freq=880Hz, sample=82, buffer_id=06:52
    db 120,0,126,0,77,125,8,4,186,2,77,8  ; n2909 t=121.462s dur=126ms, freq=698Hz, sample=77, buffer_id=08:4D
    db 19,0,113,0,72,125,8,0,42,2,72,8  ; n2910 t=121.582s dur=113ms, freq=554Hz, sample=72, buffer_id=08:48
    db 114,0,9,1,77,102,6,6,186,2,77,6  ; n2911 t=121.601s dur=265ms, freq=698Hz, sample=77, buffer_id=06:4D
    db 139,0,100,0,69,125,8,3,184,1,69,8  ; n2912 t=121.715s dur=100ms, freq=440Hz, sample=69, buffer_id=08:45
    db 0,0,22,1,82,102,6,4,112,3,82,6  ; n2913 t=121.854s dur=278ms, freq=880Hz, sample=82, buffer_id=06:52
    db 116,0,100,0,68,125,8,5,159,1,68,8  ; n2914 t=121.854s dur=100ms, freq=415Hz, sample=68, buffer_id=08:44
    db 123,0,100,0,69,125,8,0,184,1,69,8  ; n2915 t=121.970s dur=100ms, freq=440Hz, sample=69, buffer_id=08:45
    db 26,0,123,0,72,125,8,3,42,2,72,8  ; n2916 t=122.093s dur=123ms, freq=554Hz, sample=72, buffer_id=08:48
    db 110,0,4,1,77,102,6,10,186,2,77,6  ; n2917 t=122.119s dur=260ms, freq=698Hz, sample=77, buffer_id=06:4D
    db 124,0,169,0,77,125,8,5,186,2,77,8  ; n2918 t=122.230s dur=169ms, freq=698Hz, sample=77, buffer_id=08:4D
    db 20,0,157,0,72,125,8,0,42,2,72,8  ; n2919 t=122.353s dur=157ms, freq=554Hz, sample=72, buffer_id=08:48
    db 112,0,46,1,75,102,6,4,42,2,75,6  ; n2920 t=122.373s dur=302ms, freq=554Hz, sample=75, buffer_id=06:4B
    db 145,0,100,0,69,125,8,3,184,1,69,8  ; n2921 t=122.485s dur=100ms, freq=440Hz, sample=69, buffer_id=08:45
    db 0,0,185,0,77,125,8,6,186,2,77,8  ; n2922 t=122.630s dur=185ms, freq=698Hz, sample=77, buffer_id=08:4D
    db 39,0,51,22,87,125,8,5,39,5,87,8  ; n2923 t=122.630s dur=5683ms, freq=1319Hz, sample=87, buffer_id=08:57
    db 93,0,25,1,82,102,6,7,112,3,82,6  ; n2924 t=122.669s dur=281ms, freq=880Hz, sample=82, buffer_id=06:52
    db 128,0,141,0,72,125,8,8,42,2,72,8  ; n2925 t=122.762s dur=141ms, freq=554Hz, sample=72, buffer_id=08:48
    db 47,0,100,0,69,125,8,0,184,1,69,8  ; n2926 t=122.890s dur=100ms, freq=440Hz, sample=69, buffer_id=08:45
    db 101,0,250,0,77,102,6,3,186,2,77,6  ; n2927 t=122.937s dur=250ms, freq=698Hz, sample=77, buffer_id=06:4D
    db 135,0,189,0,72,125,8,2,42,2,72,8  ; n2928 t=123.038s dur=189ms, freq=554Hz, sample=72, buffer_id=08:48
    db 0,0,65,1,75,102,6,6,42,2,75,6  ; n2929 t=123.174s dur=321ms, freq=554Hz, sample=75, buffer_id=06:4B
    db 137,0,100,0,69,125,8,4,184,1,69,8  ; n2930 t=123.174s dur=100ms, freq=440Hz, sample=69, buffer_id=08:45
    db 144,0,171,0,65,125,8,0,93,1,65,8  ; n2931 t=123.311s dur=171ms, freq=349Hz, sample=65, buffer_id=08:41
    db 0,0,22,1,77,102,6,1,186,2,77,6  ; n2932 t=123.454s dur=278ms, freq=698Hz, sample=77, buffer_id=06:4D
    db 137,0,193,0,72,125,8,3,42,2,72,8  ; n2933 t=123.454s dur=193ms, freq=554Hz, sample=72, buffer_id=08:48
    db 134,0,100,0,69,125,8,2,184,1,69,8  ; n2934 t=123.592s dur=100ms, freq=440Hz, sample=69, buffer_id=08:45
    db 7,0,32,1,75,102,6,0,42,2,75,6  ; n2935 t=123.725s dur=288ms, freq=554Hz, sample=75, buffer_id=06:4B
    db 155,0,162,0,65,125,8,4,93,1,65,8  ; n2936 t=123.733s dur=162ms, freq=349Hz, sample=65, buffer_id=08:41
    db 113,0,100,0,69,125,8,3,184,1,69,8  ; n2937 t=123.888s dur=100ms, freq=440Hz, sample=69, buffer_id=08:45
    db 78,0,93,1,70,102,6,1,184,1,70,6  ; n2938 t=124.000s dur=349ms, freq=440Hz, sample=70, buffer_id=06:46
    db 207,0,200,0,65,125,8,2,93,1,65,8  ; n2939 t=124.079s dur=200ms, freq=349Hz, sample=65, buffer_id=08:41
    db 52,0,112,0,72,125,8,0,42,2,72,8  ; n2940 t=124.286s dur=112ms, freq=554Hz, sample=72, buffer_id=08:48
    db 212,0,200,0,64,102,6,3,74,1,64,6  ; n2941 t=124.338s dur=200ms, freq=330Hz, sample=64, buffer_id=06:40
    db 38,0,208,0,70,102,6,2,184,1,70,6  ; n2942 t=124.550s dur=208ms, freq=440Hz, sample=70, buffer_id=06:46
    db 125,0,35,1,70,125,8,1,238,1,70,8  ; n2943 t=124.588s dur=291ms, freq=494Hz, sample=70, buffer_id=08:46
    db 114,0,178,0,70,102,6,0,238,1,70,6  ; n2944 t=124.713s dur=178ms, freq=494Hz, sample=70, buffer_id=06:46
    db 102,0,117,0,75,102,6,3,147,2,75,6  ; n2945 t=124.827s dur=117ms, freq=659Hz, sample=75, buffer_id=06:4B
    db 30,0,73,1,63,125,8,4,74,1,63,8  ; n2946 t=124.929s dur=329ms, freq=330Hz, sample=63, buffer_id=08:3F
    db 23,0,223,0,82,102,6,2,220,3,82,6  ; n2947 t=124.959s dur=223ms, freq=988Hz, sample=82, buffer_id=06:52
    db 95,0,200,0,38,76,9,6,73,0,38,8  ; n2948 t=124.982s dur=200ms, freq=73Hz, sample=38, buffer_id=08:26
    db 61,0,189,0,85,102,6,7,23,4,85,6  ; n2949 t=125.077s dur=189ms, freq=1047Hz, sample=85, buffer_id=06:55
    db 68,0,121,0,38,76,9,0,78,0,38,8  ; n2950 t=125.137s dur=121ms, freq=78Hz, sample=38, buffer_id=08:26
    db 11,0,231,0,89,102,6,1,39,5,89,6  ; n2951 t=125.205s dur=231ms, freq=1319Hz, sample=89, buffer_id=06:59
    db 0,0,31,1,72,125,8,3,11,2,72,8  ; n2952 t=125.217s dur=287ms, freq=523Hz, sample=72, buffer_id=08:48
    db 43,1,108,2,38,76,9,8,82,0,38,8  ; n2953 t=125.217s dur=620ms, freq=82Hz, sample=38, buffer_id=08:26
    db 96,1,77,1,70,125,8,0,238,1,70,8  ; n2954 t=125.516s dur=333ms, freq=494Hz, sample=70, buffer_id=08:46
    db 246,0,92,1,63,125,8,1,74,1,63,8  ; n2955 t=125.868s dur=348ms, freq=330Hz, sample=63, buffer_id=08:3F
    db 83,0,16,1,72,125,8,0,11,2,72,8  ; n2956 t=126.114s dur=272ms, freq=523Hz, sample=72, buffer_id=08:48
    db 212,0,148,3,53,126,3,2,165,0,53,3  ; n2957 t=126.198s dur=916ms, freq=165Hz, sample=53, buffer_id=03:35
    db 239,0,66,1,70,125,8,3,238,1,70,8  ; n2958 t=126.410s dur=322ms, freq=494Hz, sample=70, buffer_id=08:46
    db 106,0,106,0,59,125,8,0,6,1,59,8  ; n2959 t=126.648s dur=106ms, freq=262Hz, sample=59, buffer_id=08:3B
    db 5,1,12,1,63,125,8,6,74,1,63,8  ; n2960 t=126.755s dur=268ms, freq=330Hz, sample=63, buffer_id=08:3F
    db 76,0,58,1,72,125,8,0,11,2,72,8  ; n2961 t=127.016s dur=314ms, freq=523Hz, sample=72, buffer_id=08:48
    db 125,0,221,6,58,126,3,1,220,0,58,3  ; n2962 t=127.092s dur=1757ms, freq=220Hz, sample=58, buffer_id=03:3A
    db 246,0,242,0,70,125,8,4,238,1,70,8  ; n2963 t=127.217s dur=242ms, freq=494Hz, sample=70, buffer_id=08:46
    db 91,0,100,0,69,125,8,2,184,1,69,8  ; n2964 t=127.463s dur=100ms, freq=440Hz, sample=69, buffer_id=08:45
    db 133,0,106,0,59,125,8,0,6,1,59,8  ; n2965 t=127.554s dur=106ms, freq=262Hz, sample=59, buffer_id=08:3B
    db 242,0,31,1,63,125,8,3,74,1,63,8  ; n2966 t=127.686s dur=287ms, freq=330Hz, sample=63, buffer_id=08:3F
    db 239,0,69,1,72,125,8,0,11,2,72,8  ; n2967 t=127.929s dur=325ms, freq=523Hz, sample=72, buffer_id=08:48
    db 216,0,219,0,70,125,8,2,238,1,70,8  ; n2968 t=128.167s dur=219ms, freq=494Hz, sample=70, buffer_id=08:46
    db 4,0,106,0,59,125,8,3,6,1,59,8  ; n2969 t=128.383s dur=106ms, freq=262Hz, sample=59, buffer_id=08:3B
    db 239,0,100,0,69,125,8,4,184,1,69,8  ; n2970 t=128.387s dur=100ms, freq=440Hz, sample=69, buffer_id=08:45
    db 208,0,16,1,63,125,8,0,74,1,63,8  ; n2971 t=128.626s dur=272ms, freq=330Hz, sample=63, buffer_id=08:3F
    db 19,0,159,5,58,126,3,2,247,0,58,3  ; n2972 t=128.834s dur=1439ms, freq=247Hz, sample=58, buffer_id=03:3A
    db 224,0,31,1,72,125,8,3,11,2,72,8  ; n2973 t=128.853s dur=287ms, freq=523Hz, sample=72, buffer_id=08:48
    db 208,0,204,0,70,125,8,1,238,1,70,8  ; n2974 t=129.077s dur=204ms, freq=494Hz, sample=70, buffer_id=08:46
    db 30,0,100,0,69,125,8,0,184,1,69,8  ; n2975 t=129.285s dur=100ms, freq=440Hz, sample=69, buffer_id=08:45
    db 201,0,106,0,59,125,8,4,6,1,59,8  ; n2976 t=129.315s dur=106ms, freq=262Hz, sample=59, buffer_id=08:3B
    db 235,0,43,1,63,125,8,1,74,1,63,8  ; n2977 t=129.516s dur=299ms, freq=330Hz, sample=63, buffer_id=08:3F
    db 26,0,47,1,72,125,8,0,11,2,72,8  ; n2978 t=129.751s dur=303ms, freq=523Hz, sample=72, buffer_id=08:48
    db 193,0,205,3,63,126,3,3,74,1,63,3  ; n2979 t=129.777s dur=973ms, freq=330Hz, sample=63, buffer_id=03:3F
    db 220,0,208,0,70,125,8,4,238,1,70,8  ; n2980 t=129.970s dur=208ms, freq=494Hz, sample=70, buffer_id=08:46
    db 26,0,100,0,69,125,8,1,184,1,69,8  ; n2981 t=130.190s dur=100ms, freq=440Hz, sample=69, buffer_id=08:45
    db 30,0,106,0,59,125,8,5,6,1,59,8  ; n2982 t=130.217s dur=106ms, freq=262Hz, sample=59, buffer_id=08:3B
    db 167,0,189,0,58,126,3,6,6,1,58,3  ; n2983 t=130.247s dur=189ms, freq=262Hz, sample=58, buffer_id=03:3A
    db 19,0,9,1,63,125,8,0,74,1,63,8  ; n2984 t=130.414s dur=265ms, freq=330Hz, sample=63, buffer_id=08:3F
    db 208,0,215,0,62,126,3,4,38,1,62,3  ; n2985 t=130.433s dur=215ms, freq=294Hz, sample=62, buffer_id=03:3E
    db 8,0,225,7,58,126,3,1,6,1,58,3  ; n2986 t=130.641s dur=2017ms, freq=262Hz, sample=58, buffer_id=03:3A
    db 61,0,31,1,72,125,8,2,11,2,72,8  ; n2987 t=130.649s dur=287ms, freq=523Hz, sample=72, buffer_id=08:48
    db 171,0,22,7,69,126,3,5,184,1,69,3  ; n2988 t=130.709s dur=1814ms, freq=440Hz, sample=69, buffer_id=03:45
    db 216,0,242,0,70,125,8,0,238,1,70,8  ; n2989 t=130.880s dur=242ms, freq=494Hz, sample=70, buffer_id=08:46
    db 23,0,100,0,69,125,8,3,184,1,69,8  ; n2990 t=131.095s dur=100ms, freq=440Hz, sample=69, buffer_id=08:45
    db 216,0,106,0,59,125,8,4,6,1,59,8  ; n2991 t=131.118s dur=106ms, freq=262Hz, sample=59, buffer_id=08:3B
    db 227,0,24,1,63,125,8,0,74,1,63,8  ; n2992 t=131.334s dur=280ms, freq=330Hz, sample=63, buffer_id=08:3F
    db 0,0,20,1,72,125,8,3,11,2,72,8  ; n2993 t=131.561s dur=276ms, freq=523Hz, sample=72, buffer_id=08:48
    db 227,0,167,0,56,76,9,2,220,0,56,8  ; n2994 t=131.561s dur=167ms, freq=220Hz, sample=56, buffer_id=08:38
    db 216,0,219,0,70,125,8,4,238,1,70,8  ; n2995 t=131.789s dur=219ms, freq=494Hz, sample=70, buffer_id=08:46
    db 19,0,100,0,69,125,8,0,184,1,69,8  ; n2996 t=132.005s dur=100ms, freq=440Hz, sample=69, buffer_id=08:45
    db 216,0,106,0,59,125,8,2,6,1,59,8  ; n2997 t=132.024s dur=106ms, freq=262Hz, sample=59, buffer_id=08:3B
    db 231,0,250,0,63,125,8,3,74,1,63,8  ; n2998 t=132.239s dur=250ms, freq=330Hz, sample=63, buffer_id=08:3F
    db 0,0,28,1,72,125,8,0,11,2,72,8  ; n2999 t=132.470s dur=284ms, freq=523Hz, sample=72, buffer_id=08:48
    db 4,0,167,0,56,76,9,2,220,0,56,8  ; n3000 t=132.470s dur=167ms, freq=220Hz, sample=56, buffer_id=08:38
    db 224,0,163,5,70,126,3,4,238,1,70,3  ; n3001 t=132.474s dur=1443ms, freq=494Hz, sample=70, buffer_id=03:46
    db 182,0,231,0,70,125,8,3,238,1,70,8  ; n3002 t=132.698s dur=231ms, freq=494Hz, sample=70, buffer_id=08:46
    db 34,0,106,0,59,125,8,1,6,1,59,8  ; n3003 t=132.880s dur=106ms, freq=262Hz, sample=59, buffer_id=08:3B
    db 231,0,100,0,69,125,8,2,184,1,69,8  ; n3004 t=132.914s dur=100ms, freq=440Hz, sample=69, buffer_id=08:45
    db 231,0,12,1,63,125,8,0,74,1,63,8  ; n3005 t=133.145s dur=268ms, freq=330Hz, sample=63, buffer_id=08:3F
    db 15,0,39,1,72,125,8,1,11,2,72,8  ; n3006 t=133.376s dur=295ms, freq=523Hz, sample=72, buffer_id=08:48
    db 4,0,84,3,53,126,3,2,165,0,53,3  ; n3007 t=133.391s dur=852ms, freq=165Hz, sample=53, buffer_id=03:35
    db 212,0,167,0,56,76,9,3,220,0,56,8  ; n3008 t=133.395s dur=167ms, freq=220Hz, sample=56, buffer_id=08:38
    db 201,0,231,0,70,125,8,5,238,1,70,8  ; n3009 t=133.607s dur=231ms, freq=494Hz, sample=70, buffer_id=08:46
    db 26,0,106,0,59,125,8,0,6,1,59,8  ; n3010 t=133.808s dur=106ms, freq=262Hz, sample=59, buffer_id=08:3B
    db 61,0,100,0,69,125,8,3,184,1,69,8  ; n3011 t=133.834s dur=100ms, freq=440Hz, sample=69, buffer_id=08:45
    db 171,0,208,0,72,126,3,1,11,2,72,3  ; n3012 t=133.895s dur=208ms, freq=523Hz, sample=72, buffer_id=03:48
    db 64,0,1,1,63,125,8,5,74,1,63,8  ; n3013 t=134.065s dur=257ms, freq=330Hz, sample=63, buffer_id=08:3F
    db 110,0,28,1,74,126,3,0,75,2,74,3  ; n3014 t=134.130s dur=284ms, freq=587Hz, sample=74, buffer_id=03:4A
    db 42,0,159,5,58,126,3,3,220,0,58,3  ; n3015 t=134.239s dur=1439ms, freq=220Hz, sample=58, buffer_id=03:3A
    db 11,0,112,2,47,76,9,4,131,0,47,8  ; n3016 t=134.281s dur=624ms, freq=131Hz, sample=47, buffer_id=08:2F
    db 19,0,28,1,72,125,8,6,11,2,72,8  ; n3017 t=134.292s dur=284ms, freq=523Hz, sample=72, buffer_id=08:48
    db 106,0,167,0,56,76,9,1,220,0,56,8  ; n3018 t=134.311s dur=167ms, freq=220Hz, sample=56, buffer_id=08:38
    db 99,0,244,4,72,126,3,7,11,2,72,3  ; n3019 t=134.417s dur=1268ms, freq=523Hz, sample=72, buffer_id=03:48
    db 201,0,219,0,70,125,8,2,238,1,70,8  ; n3020 t=134.516s dur=219ms, freq=494Hz, sample=70, buffer_id=08:46
    db 15,0,106,0,59,125,8,0,6,1,59,8  ; n3021 t=134.717s dur=106ms, freq=262Hz, sample=59, buffer_id=08:3B
    db 227,0,100,0,69,125,8,1,184,1,69,8  ; n3022 t=134.732s dur=100ms, freq=440Hz, sample=69, buffer_id=08:45
    db 235,0,16,1,63,125,8,2,74,1,63,8  ; n3023 t=134.959s dur=272ms, freq=330Hz, sample=63, buffer_id=08:3F
    db 23,0,69,1,72,125,8,0,11,2,72,8  ; n3024 t=135.194s dur=325ms, freq=523Hz, sample=72, buffer_id=08:48
    db 205,0,167,0,56,76,9,1,220,0,56,8  ; n3025 t=135.217s dur=167ms, freq=220Hz, sample=56, buffer_id=08:38
    db 189,0,219,0,70,125,8,4,238,1,70,8  ; n3026 t=135.421s dur=219ms, freq=494Hz, sample=70, buffer_id=08:46
    db 11,0,14,2,47,76,9,1,123,0,47,8  ; n3027 t=135.611s dur=526ms, freq=123Hz, sample=47, buffer_id=08:2F
    db 23,0,100,0,62,125,8,2,38,1,62,8  ; n3028 t=135.622s dur=100ms, freq=294Hz, sample=62, buffer_id=08:3E
    db 0,0,3,2,58,126,3,5,247,0,58,3  ; n3029 t=135.645s dur=515ms, freq=247Hz, sample=58, buffer_id=03:3A
    db 57,0,100,0,69,125,8,6,184,1,69,8  ; n3030 t=135.645s dur=100ms, freq=440Hz, sample=69, buffer_id=08:45
    db 170,0,213,1,70,126,3,8,238,1,70,3  ; n3031 t=135.702s dur=469ms, freq=494Hz, sample=70, buffer_id=03:46
    db 235,0,246,0,63,125,8,0,74,1,63,8  ; n3032 t=135.872s dur=246ms, freq=330Hz, sample=63, buffer_id=08:3F
    db 7,0,246,0,72,125,8,2,11,2,72,8  ; n3033 t=136.107s dur=246ms, freq=523Hz, sample=72, buffer_id=08:48
    db 8,0,100,0,63,125,8,3,74,1,63,8  ; n3034 t=136.114s dur=100ms, freq=330Hz, sample=63, buffer_id=08:3F
    db 11,0,167,0,56,76,9,4,220,0,56,8  ; n3035 t=136.122s dur=167ms, freq=220Hz, sample=56, buffer_id=08:38
    db 11,0,125,5,43,76,9,6,110,0,43,8  ; n3036 t=136.133s dur=1405ms, freq=110Hz, sample=43, buffer_id=08:2B
    db 30,0,168,1,58,126,3,7,6,1,58,3  ; n3037 t=136.145s dur=424ms, freq=262Hz, sample=58, buffer_id=03:3A
    db 155,0,190,3,69,126,3,9,184,1,69,3  ; n3038 t=136.175s dur=958ms, freq=440Hz, sample=69, buffer_id=03:45
    db 220,0,1,1,70,125,8,0,238,1,70,8  ; n3039 t=136.330s dur=257ms, freq=494Hz, sample=70, buffer_id=08:46
    db 19,0,100,0,69,125,8,1,184,1,69,8  ; n3040 t=136.550s dur=100ms, freq=440Hz, sample=69, buffer_id=08:45
    db 0,0,228,1,53,126,3,2,165,0,53,3  ; n3041 t=136.569s dur=484ms, freq=165Hz, sample=53, buffer_id=03:35
    db 208,0,144,3,53,125,8,3,165,0,53,8  ; n3042 t=136.569s dur=912ms, freq=165Hz, sample=53, buffer_id=08:35
    db 231,0,20,1,63,125,8,4,74,1,63,8  ; n3043 t=136.777s dur=276ms, freq=330Hz, sample=63, buffer_id=08:3F
    db 0,0,28,1,72,125,8,0,11,2,72,8  ; n3044 t=137.008s dur=284ms, freq=523Hz, sample=72, buffer_id=08:48
    db 42,0,167,0,56,76,9,1,220,0,56,8  ; n3045 t=137.008s dur=167ms, freq=220Hz, sample=56, buffer_id=08:38
    db 19,0,58,1,58,126,3,8,6,1,58,3  ; n3046 t=137.050s dur=314ms, freq=262Hz, sample=58, buffer_id=03:3A
    db 167,0,125,3,65,126,3,5,136,1,65,3  ; n3047 t=137.069s dur=893ms, freq=392Hz, sample=65, buffer_id=03:41
    db 110,0,219,0,70,125,8,7,238,1,70,8  ; n3048 t=137.236s dur=219ms, freq=494Hz, sample=70, buffer_id=08:46
    db 114,0,50,1,58,126,3,2,220,0,58,3  ; n3049 t=137.345s dur=306ms, freq=220Hz, sample=58, buffer_id=03:3A
    db 23,0,100,0,69,125,8,1,184,1,69,8  ; n3050 t=137.459s dur=100ms, freq=440Hz, sample=69, buffer_id=08:45
    db 23,0,198,1,55,125,8,4,196,0,55,8  ; n3051 t=137.482s dur=454ms, freq=196Hz, sample=55, buffer_id=08:37
    db 148,0,198,1,43,76,9,0,98,0,43,8  ; n3052 t=137.505s dur=454ms, freq=98Hz, sample=43, buffer_id=08:2B
    db 23,0,47,1,63,126,3,8,74,1,63,3  ; n3053 t=137.652s dur=303ms, freq=330Hz, sample=63, buffer_id=03:3F
    db 250,0,39,1,63,125,8,7,74,1,63,8  ; n3054 t=137.675s dur=295ms, freq=330Hz, sample=63, buffer_id=08:3F
    db 8,0,8,1,74,125,8,1,75,2,74,8  ; n3055 t=137.925s dur=264ms, freq=587Hz, sample=74, buffer_id=08:4A
    db 4,0,167,0,56,76,9,2,220,0,56,8  ; n3056 t=137.933s dur=167ms, freq=220Hz, sample=56, buffer_id=08:38
    db 8,0,192,14,62,126,3,3,38,1,62,3  ; n3057 t=137.936s dur=3776ms, freq=294Hz, sample=62, buffer_id=03:3E
    db 8,0,52,14,43,76,9,9,92,0,43,8  ; n3058 t=137.944s dur=3636ms, freq=92Hz, sample=43, buffer_id=08:2B
    db 19,0,167,0,56,125,8,6,220,0,56,8  ; n3059 t=137.952s dur=167ms, freq=220Hz, sample=56, buffer_id=08:38
    db 174,0,101,7,65,126,3,10,114,1,65,3  ; n3060 t=137.970s dur=1893ms, freq=370Hz, sample=65, buffer_id=03:41
    db 224,0,43,1,70,125,8,4,210,1,70,8  ; n3061 t=138.145s dur=299ms, freq=466Hz, sample=70, buffer_id=08:46
    db 239,0,100,0,69,125,8,0,184,1,69,8  ; n3062 t=138.368s dur=100ms, freq=440Hz, sample=69, buffer_id=08:45
    db 227,0,215,0,65,125,8,1,114,1,65,8  ; n3063 t=138.607s dur=215ms, freq=370Hz, sample=65, buffer_id=08:41
    db 19,0,1,1,74,125,8,0,75,2,74,8  ; n3064 t=138.834s dur=257ms, freq=587Hz, sample=74, buffer_id=08:4A
    db 208,0,167,0,56,76,9,4,220,0,56,8  ; n3065 t=138.853s dur=167ms, freq=220Hz, sample=56, buffer_id=08:38
    db 227,0,231,0,70,125,8,1,210,1,70,8  ; n3066 t=139.061s dur=231ms, freq=466Hz, sample=70, buffer_id=08:46
    db 220,0,100,0,69,125,8,2,184,1,69,8  ; n3067 t=139.289s dur=100ms, freq=440Hz, sample=69, buffer_id=08:45
    db 235,0,238,0,65,125,8,0,114,1,65,8  ; n3068 t=139.508s dur=238ms, freq=370Hz, sample=65, buffer_id=08:41
    db 23,0,8,1,74,125,8,1,75,2,74,8  ; n3069 t=139.743s dur=264ms, freq=587Hz, sample=74, buffer_id=08:4A
    db 11,0,167,0,56,76,9,2,220,0,56,8  ; n3070 t=139.766s dur=167ms, freq=220Hz, sample=56, buffer_id=08:38
    db 193,0,141,1,63,125,5,4,38,1,63,5  ; n3071 t=139.777s dur=397ms, freq=294Hz, sample=63, buffer_id=05:3F
    db 227,0,12,1,70,125,8,0,210,1,70,8  ; n3072 t=139.970s dur=268ms, freq=466Hz, sample=70, buffer_id=08:46
    db 224,0,100,0,69,125,8,2,184,1,69,8  ; n3073 t=140.198s dur=100ms, freq=440Hz, sample=69, buffer_id=08:45
    db 231,0,12,1,65,125,8,1,114,1,65,8  ; n3074 t=140.421s dur=268ms, freq=370Hz, sample=65, buffer_id=08:41
    db 19,0,8,1,74,125,8,0,75,2,74,8  ; n3075 t=140.652s dur=264ms, freq=587Hz, sample=74, buffer_id=08:4A
    db 7,0,94,2,69,125,5,2,184,1,69,5  ; n3076 t=140.671s dur=606ms, freq=440Hz, sample=69, buffer_id=05:45
    db 201,0,167,0,56,76,9,4,220,0,56,8  ; n3077 t=140.679s dur=167ms, freq=220Hz, sample=56, buffer_id=08:38
    db 227,0,54,1,70,125,8,5,210,1,70,8  ; n3078 t=140.880s dur=310ms, freq=466Hz, sample=70, buffer_id=08:46
    db 223,0,100,0,69,125,8,1,184,1,69,8  ; n3079 t=141.107s dur=100ms, freq=440Hz, sample=69, buffer_id=08:45
    db 231,0,47,1,65,125,8,0,114,1,65,8  ; n3080 t=141.330s dur=303ms, freq=370Hz, sample=65, buffer_id=08:41
    db 11,0,8,1,74,125,8,1,75,2,74,8  ; n3081 t=141.561s dur=264ms, freq=587Hz, sample=74, buffer_id=08:4A
    db 0,0,227,0,69,125,5,4,136,1,69,5  ; n3082 t=141.573s dur=227ms, freq=392Hz, sample=69, buffer_id=05:45
    db 15,0,184,2,38,76,9,2,73,0,38,8  ; n3083 t=141.573s dur=696ms, freq=73Hz, sample=38, buffer_id=08:26
    db 201,0,167,0,56,76,9,5,220,0,56,8  ; n3084 t=141.588s dur=167ms, freq=220Hz, sample=56, buffer_id=08:38
    db 121,0,31,1,70,125,8,6,210,1,70,8  ; n3085 t=141.789s dur=287ms, freq=466Hz, sample=70, buffer_id=08:46
    db 110,0,117,0,63,125,5,0,114,1,63,5  ; n3086 t=141.910s dur=117ms, freq=370Hz, sample=63, buffer_id=05:3F
    db 182,0,100,0,69,125,8,3,184,1,69,8  ; n3087 t=142.020s dur=100ms, freq=440Hz, sample=69, buffer_id=08:45
    db 42,0,117,0,63,125,5,1,74,1,63,5  ; n3088 t=142.202s dur=117ms, freq=330Hz, sample=63, buffer_id=05:3F
    db 227,0,20,1,65,125,8,0,114,1,65,8  ; n3089 t=142.243s dur=276ms, freq=370Hz, sample=65, buffer_id=08:41
    db 19,0,8,1,74,125,8,2,75,2,74,8  ; n3090 t=142.470s dur=264ms, freq=587Hz, sample=74, buffer_id=08:4A
    db 8,0,238,2,74,125,5,3,75,2,74,5  ; n3091 t=142.489s dur=750ms, freq=587Hz, sample=74, buffer_id=05:4A
    db 0,0,167,0,56,76,9,4,220,0,56,8  ; n3092 t=142.497s dur=167ms, freq=220Hz, sample=56, buffer_id=08:38
    db 201,0,160,3,43,76,9,5,104,0,43,8  ; n3093 t=142.497s dur=928ms, freq=104Hz, sample=43, buffer_id=08:2B
    db 231,0,215,0,70,125,8,1,210,1,70,8  ; n3094 t=142.698s dur=215ms, freq=466Hz, sample=70, buffer_id=08:46
    db 224,0,100,0,69,125,8,0,184,1,69,8  ; n3095 t=142.929s dur=100ms, freq=440Hz, sample=69, buffer_id=08:45
    db 235,0,181,0,65,125,8,1,114,1,65,8  ; n3096 t=143.152s dur=181ms, freq=370Hz, sample=65, buffer_id=08:41
    db 4,0,8,1,74,125,8,0,75,2,74,8  ; n3097 t=143.387s dur=264ms, freq=587Hz, sample=74, buffer_id=08:4A
    db 27,0,6,9,69,125,5,2,184,1,69,5  ; n3098 t=143.391s dur=2310ms, freq=440Hz, sample=69, buffer_id=05:45
    db 19,0,209,13,43,76,9,4,92,0,43,8  ; n3099 t=143.417s dur=3537ms, freq=92Hz, sample=43, buffer_id=08:2B
    db 186,0,167,0,56,76,9,6,220,0,56,8  ; n3100 t=143.436s dur=167ms, freq=220Hz, sample=56, buffer_id=08:38
    db 227,0,69,1,70,125,8,1,210,1,70,8  ; n3101 t=143.622s dur=325ms, freq=466Hz, sample=70, buffer_id=08:46
    db 227,0,100,0,69,125,8,3,184,1,69,8  ; n3102 t=143.849s dur=100ms, freq=440Hz, sample=69, buffer_id=08:45
    db 227,0,100,0,62,125,8,0,38,1,62,8  ; n3103 t=144.077s dur=100ms, freq=294Hz, sample=62, buffer_id=08:3E
    db 11,0,8,1,74,125,8,1,75,2,74,8  ; n3104 t=144.304s dur=264ms, freq=587Hz, sample=74, buffer_id=08:4A
    db 4,0,103,1,69,126,3,3,184,1,69,3  ; n3105 t=144.315s dur=359ms, freq=440Hz, sample=69, buffer_id=03:45
    db 45,0,167,0,56,76,9,5,220,0,56,8  ; n3106 t=144.319s dur=167ms, freq=220Hz, sample=56, buffer_id=08:38
    db 167,0,181,0,74,124,4,6,75,2,74,4  ; n3107 t=144.364s dur=181ms, freq=587Hz, sample=74, buffer_id=04:4A
    db 227,0,20,1,70,125,8,0,210,1,70,8  ; n3108 t=144.531s dur=276ms, freq=466Hz, sample=70, buffer_id=08:46
    db 61,0,100,0,69,125,8,5,184,1,69,8  ; n3109 t=144.758s dur=100ms, freq=440Hz, sample=69, buffer_id=08:45
    db 151,0,151,0,81,124,4,1,112,3,81,4  ; n3110 t=144.819s dur=151ms, freq=880Hz, sample=81, buffer_id=04:51
    db 45,0,100,0,62,125,8,3,38,1,62,8  ; n3111 t=144.970s dur=100ms, freq=294Hz, sample=62, buffer_id=08:3E
    db 186,0,106,0,69,126,3,0,184,1,69,3  ; n3112 t=145.016s dur=106ms, freq=440Hz, sample=69, buffer_id=03:45
    db 11,0,8,1,74,125,8,1,75,2,74,8  ; n3113 t=145.202s dur=264ms, freq=587Hz, sample=74, buffer_id=08:4A
    db 15,0,167,0,56,76,9,5,220,0,56,8  ; n3114 t=145.213s dur=167ms, freq=220Hz, sample=56, buffer_id=08:38
    db 11,0,132,7,69,126,3,6,184,1,69,3  ; n3115 t=145.228s dur=1924ms, freq=440Hz, sample=69, buffer_id=03:45
    db 159,0,106,0,78,124,4,7,16,3,78,4  ; n3116 t=145.239s dur=106ms, freq=784Hz, sample=78, buffer_id=04:4E
    db 38,0,109,0,78,124,4,0,228,2,78,4  ; n3117 t=145.399s dur=109ms, freq=740Hz, sample=78, buffer_id=04:4E
    db 102,0,242,0,70,125,8,3,210,1,70,8  ; n3118 t=145.436s dur=242ms, freq=466Hz, sample=70, buffer_id=08:46
    db 114,0,100,0,75,124,4,8,147,2,75,4  ; n3119 t=145.539s dur=100ms, freq=659Hz, sample=75, buffer_id=04:4B
    db 46,0,100,0,69,125,8,5,184,1,69,8  ; n3120 t=145.652s dur=100ms, freq=440Hz, sample=69, buffer_id=08:45
    db 178,0,178,0,86,124,4,1,151,4,86,4  ; n3121 t=145.698s dur=178ms, freq=1175Hz, sample=86, buffer_id=04:56
    db 231,0,100,0,62,125,8,0,38,1,62,8  ; n3122 t=145.876s dur=100ms, freq=294Hz, sample=62, buffer_id=08:3E
    db 0,0,8,1,74,125,8,1,75,2,74,8  ; n3123 t=146.107s dur=264ms, freq=587Hz, sample=74, buffer_id=08:4A
    db 83,0,167,0,56,76,9,2,220,0,56,8  ; n3124 t=146.107s dur=167ms, freq=220Hz, sample=56, buffer_id=08:38
    db 136,0,97,4,81,124,4,0,112,3,81,4  ; n3125 t=146.190s dur=1121ms, freq=880Hz, sample=81, buffer_id=04:51
    db 231,0,31,1,70,125,8,5,210,1,70,8  ; n3126 t=146.327s dur=287ms, freq=466Hz, sample=70, buffer_id=08:46
    db 231,0,100,0,69,125,8,2,184,1,69,8  ; n3127 t=146.558s dur=100ms, freq=440Hz, sample=69, buffer_id=08:45
    db 163,0,100,0,62,125,8,1,38,1,62,8  ; n3128 t=146.789s dur=100ms, freq=294Hz, sample=62, buffer_id=08:3E
    db 64,0,184,2,38,76,9,2,73,0,38,8  ; n3129 t=146.952s dur=696ms, freq=73Hz, sample=38, buffer_id=08:26
    db 11,0,250,0,77,125,8,3,186,2,77,8  ; n3130 t=147.016s dur=250ms, freq=698Hz, sample=77, buffer_id=08:4D
    db 34,0,33,14,58,76,9,5,233,0,58,8  ; n3131 t=147.027s dur=3617ms, freq=233Hz, sample=58, buffer_id=08:3A
    db 182,0,167,0,56,125,8,7,220,0,56,8  ; n3132 t=147.061s dur=167ms, freq=220Hz, sample=56, buffer_id=08:38
    db 246,0,219,0,70,125,8,1,210,1,70,8  ; n3133 t=147.243s dur=219ms, freq=466Hz, sample=70, buffer_id=08:46
    db 182,0,170,0,65,125,8,3,114,1,65,8  ; n3134 t=147.489s dur=170ms, freq=370Hz, sample=65, buffer_id=08:41
    db 246,0,12,1,65,125,8,0,93,1,65,8  ; n3135 t=147.671s dur=268ms, freq=349Hz, sample=65, buffer_id=08:41
    db 4,0,67,2,65,126,3,1,93,1,65,3  ; n3136 t=147.917s dur=579ms, freq=349Hz, sample=65, buffer_id=03:41
    db 23,0,250,0,77,125,8,2,186,2,77,8  ; n3137 t=147.921s dur=250ms, freq=698Hz, sample=77, buffer_id=08:4D
    db 205,0,167,0,56,125,8,3,220,0,56,8  ; n3138 t=147.944s dur=167ms, freq=220Hz, sample=56, buffer_id=08:38
    db 212,0,223,0,70,125,8,0,210,1,70,8  ; n3139 t=148.149s dur=223ms, freq=466Hz, sample=70, buffer_id=08:46
    db 19,0,227,0,65,125,8,3,114,1,65,8  ; n3140 t=148.361s dur=227ms, freq=370Hz, sample=65, buffer_id=08:41
    db 129,0,100,0,65,124,4,2,136,1,65,4  ; n3141 t=148.380s dur=100ms, freq=392Hz, sample=65, buffer_id=04:41
    db 68,0,100,0,65,124,4,4,114,1,65,4  ; n3142 t=148.508s dur=100ms, freq=370Hz, sample=65, buffer_id=04:41
    db 0,0,170,0,70,126,3,0,210,1,70,3  ; n3143 t=148.577s dur=170ms, freq=466Hz, sample=70, buffer_id=03:46
    db 57,0,1,1,65,125,8,6,93,1,65,8  ; n3144 t=148.577s dur=257ms, freq=349Hz, sample=65, buffer_id=08:41
    db 182,0,100,0,65,124,4,7,74,1,65,4  ; n3145 t=148.633s dur=100ms, freq=330Hz, sample=65, buffer_id=04:41
    db 26,0,12,1,77,125,8,1,186,2,77,8  ; n3146 t=148.815s dur=268ms, freq=698Hz, sample=77, buffer_id=08:4D
    db 4,0,103,3,69,126,3,2,184,1,69,3  ; n3147 t=148.842s dur=871ms, freq=440Hz, sample=69, buffer_id=03:45
    db 8,0,117,0,70,124,4,3,184,1,70,4  ; n3148 t=148.845s dur=117ms, freq=440Hz, sample=70, buffer_id=04:46
    db 178,0,167,0,56,125,8,4,220,0,56,8  ; n3149 t=148.853s dur=167ms, freq=220Hz, sample=56, buffer_id=08:38
    db 220,0,246,0,70,125,8,0,210,1,70,8  ; n3150 t=149.031s dur=246ms, freq=466Hz, sample=70, buffer_id=08:46
    db 38,0,215,0,65,125,8,3,114,1,65,8  ; n3151 t=149.251s dur=215ms, freq=370Hz, sample=65, buffer_id=08:41
    db 140,0,100,0,65,124,4,1,136,1,65,4  ; n3152 t=149.289s dur=100ms, freq=392Hz, sample=65, buffer_id=04:41
    db 34,0,100,0,65,124,4,4,114,1,65,4  ; n3153 t=149.429s dur=100ms, freq=370Hz, sample=65, buffer_id=04:41
    db 102,0,1,1,65,125,8,7,93,1,65,8  ; n3154 t=149.463s dur=257ms, freq=349Hz, sample=65, buffer_id=08:41
    db 148,0,100,0,65,124,4,0,74,1,65,4  ; n3155 t=149.565s dur=100ms, freq=330Hz, sample=65, buffer_id=04:41
    db 42,0,31,1,77,125,8,1,186,2,77,8  ; n3156 t=149.713s dur=287ms, freq=698Hz, sample=77, buffer_id=08:4D
    db 8,0,139,2,65,126,3,3,93,1,65,3  ; n3157 t=149.755s dur=651ms, freq=349Hz, sample=65, buffer_id=03:41
    db 7,0,162,0,74,124,4,4,75,2,74,4  ; n3158 t=149.762s dur=162ms, freq=587Hz, sample=74, buffer_id=04:4A
    db 163,0,167,0,56,125,8,6,220,0,56,8  ; n3159 t=149.770s dur=167ms, freq=220Hz, sample=56, buffer_id=08:38
    db 235,0,253,0,70,125,8,0,210,1,70,8  ; n3160 t=149.933s dur=253ms, freq=466Hz, sample=70, buffer_id=08:46
    db 87,0,9,1,65,125,8,2,114,1,65,8  ; n3161 t=150.167s dur=265ms, freq=370Hz, sample=65, buffer_id=08:41
    db 163,0,132,0,70,124,4,1,184,1,70,4  ; n3162 t=150.255s dur=132ms, freq=440Hz, sample=70, buffer_id=04:46
    db 53,0,166,0,65,125,8,0,93,1,65,8  ; n3163 t=150.417s dur=166ms, freq=349Hz, sample=65, buffer_id=08:41
    db 129,0,132,0,70,126,3,4,210,1,70,3  ; n3164 t=150.470s dur=132ms, freq=466Hz, sample=70, buffer_id=03:46
    db 19,0,100,0,74,124,4,1,75,2,74,4  ; n3165 t=150.599s dur=100ms, freq=587Hz, sample=74, buffer_id=04:4A
    db 4,0,125,0,70,124,4,3,184,1,70,4  ; n3166 t=150.618s dur=125ms, freq=440Hz, sample=70, buffer_id=04:46
    db 8,0,167,0,56,76,9,7,220,0,56,8  ; n3167 t=150.622s dur=167ms, freq=220Hz, sample=56, buffer_id=08:38
    db 4,0,100,0,69,125,5,6,184,1,69,5  ; n3168 t=150.630s dur=100ms, freq=440Hz, sample=69, buffer_id=05:45
    db 7,0,100,0,74,125,5,2,75,2,74,5  ; n3169 t=150.633s dur=100ms, freq=587Hz, sample=74, buffer_id=05:4A
    db 4,0,37,14,43,76,9,8,92,0,43,8  ; n3170 t=150.641s dur=3621ms, freq=92Hz, sample=43, buffer_id=08:2B
    db 34,0,242,0,74,125,8,9,75,2,74,8  ; n3171 t=150.645s dur=242ms, freq=587Hz, sample=74, buffer_id=08:4A
    db 0,0,188,2,69,126,3,10,184,1,69,3  ; n3172 t=150.679s dur=700ms, freq=440Hz, sample=69, buffer_id=03:45
    db 8,0,128,0,81,124,4,11,112,3,81,4  ; n3173 t=150.679s dur=128ms, freq=880Hz, sample=81, buffer_id=04:51
    db 11,0,167,0,56,125,8,12,220,0,56,8  ; n3174 t=150.686s dur=167ms, freq=220Hz, sample=56, buffer_id=08:38
    db 72,0,143,0,81,125,5,13,112,3,81,5  ; n3175 t=150.698s dur=143ms, freq=880Hz, sample=81, buffer_id=05:51
    db 87,0,100,0,74,124,4,1,75,2,74,4  ; n3176 t=150.770s dur=100ms, freq=587Hz, sample=74, buffer_id=04:4A [TRUNCATE prev:ch1 @150599.3ms -> 150769.7ms]
    db 220,0,50,1,70,125,8,0,210,1,70,8  ; n3177 t=150.857s dur=306ms, freq=466Hz, sample=70, buffer_id=08:46
    db 19,0,100,0,74,125,5,1,75,2,74,5  ; n3178 t=151.077s dur=100ms, freq=587Hz, sample=74, buffer_id=05:4A
    db 4,0,100,0,74,124,4,2,75,2,74,4  ; n3179 t=151.095s dur=100ms, freq=587Hz, sample=74, buffer_id=04:4A
    db 0,0,100,0,70,124,4,4,184,1,70,4  ; n3180 t=151.099s dur=100ms, freq=440Hz, sample=70, buffer_id=04:46
    db 7,0,100,0,69,125,8,3,184,1,69,8  ; n3181 t=151.099s dur=100ms, freq=440Hz, sample=69, buffer_id=08:45
    db 27,0,100,0,69,125,5,5,184,1,69,5  ; n3182 t=151.107s dur=100ms, freq=440Hz, sample=69, buffer_id=05:45
    db 19,0,128,0,81,125,5,6,112,3,81,5  ; n3183 t=151.133s dur=128ms, freq=880Hz, sample=81, buffer_id=05:51
    db 30,0,151,0,81,124,4,7,112,3,81,4  ; n3184 t=151.152s dur=151ms, freq=880Hz, sample=81, buffer_id=04:51
    db 19,0,117,0,74,124,4,9,75,2,74,4  ; n3185 t=151.183s dur=117ms, freq=587Hz, sample=74, buffer_id=04:4A
    db 125,0,100,0,74,125,5,11,75,2,74,5  ; n3186 t=151.202s dur=100ms, freq=587Hz, sample=74, buffer_id=05:4A
    db 186,0,100,0,62,125,8,12,38,1,62,8  ; n3187 t=151.327s dur=100ms, freq=294Hz, sample=62, buffer_id=08:3E
    db 19,0,100,0,70,124,4,0,184,1,70,4  ; n3188 t=151.512s dur=100ms, freq=440Hz, sample=70, buffer_id=04:46
    db 26,0,193,0,79,125,5,1,16,3,79,5  ; n3189 t=151.531s dur=193ms, freq=784Hz, sample=79, buffer_id=05:4F
    db 23,0,100,0,74,125,5,2,75,2,74,5  ; n3190 t=151.558s dur=100ms, freq=587Hz, sample=74, buffer_id=05:4A
    db 4,0,8,1,74,125,8,3,75,2,74,8  ; n3191 t=151.580s dur=264ms, freq=587Hz, sample=74, buffer_id=08:4A
    db 4,0,77,1,69,126,3,4,184,1,69,3  ; n3192 t=151.584s dur=333ms, freq=440Hz, sample=69, buffer_id=03:45
    db 0,0,162,0,78,124,4,5,16,3,78,4  ; n3193 t=151.588s dur=162ms, freq=784Hz, sample=78, buffer_id=04:4E
    db 11,0,167,0,56,125,8,6,220,0,56,8  ; n3194 t=151.588s dur=167ms, freq=220Hz, sample=56, buffer_id=08:38
    db 4,0,100,0,69,125,5,7,238,1,69,5  ; n3195 t=151.599s dur=100ms, freq=494Hz, sample=69, buffer_id=05:45
    db 136,0,113,0,74,124,4,10,75,2,74,4  ; n3196 t=151.603s dur=113ms, freq=587Hz, sample=74, buffer_id=04:4A
    db 11,0,100,0,78,124,4,9,228,2,78,4  ; n3197 t=151.739s dur=100ms, freq=740Hz, sample=78, buffer_id=04:4E
    db 45,0,102,0,79,125,5,11,228,2,79,5  ; n3198 t=151.751s dur=102ms, freq=740Hz, sample=79, buffer_id=05:4F
    db 38,0,9,1,70,125,8,12,210,1,70,8  ; n3199 t=151.796s dur=265ms, freq=466Hz, sample=70, buffer_id=08:46
    db 23,0,100,0,69,125,5,0,238,1,69,5  ; n3200 t=151.834s dur=100ms, freq=494Hz, sample=69, buffer_id=05:45
    db 34,0,100,0,75,124,4,13,147,2,75,4  ; n3201 t=151.857s dur=100ms, freq=659Hz, sample=75, buffer_id=04:4B
    db 110,0,100,0,74,125,5,2,147,2,74,5  ; n3202 t=151.891s dur=100ms, freq=659Hz, sample=74, buffer_id=05:4A [TRUNCATE prev:ch2 @151557.6ms -> 151890.9ms]
    db 38,0,100,0,69,125,8,1,184,1,69,8  ; n3203 t=152.001s dur=100ms, freq=440Hz, sample=69, buffer_id=08:45
    db 4,0,100,0,74,125,5,5,75,2,74,5  ; n3204 t=152.039s dur=100ms, freq=587Hz, sample=74, buffer_id=05:4A
    db 11,0,147,0,86,125,5,6,151,4,86,5  ; n3205 t=152.042s dur=147ms, freq=1175Hz, sample=86, buffer_id=05:56
    db 174,0,238,0,86,124,4,3,151,4,86,4  ; n3206 t=152.054s dur=238ms, freq=1175Hz, sample=86, buffer_id=04:56
    db 38,0,100,0,62,125,8,0,38,1,62,8  ; n3207 t=152.228s dur=100ms, freq=294Hz, sample=62, buffer_id=08:3E
    db 201,0,106,0,69,126,3,2,184,1,69,3  ; n3208 t=152.266s dur=106ms, freq=440Hz, sample=69, buffer_id=03:45
    db 26,0,8,1,74,125,8,1,75,2,74,8  ; n3209 t=152.467s dur=264ms, freq=587Hz, sample=74, buffer_id=08:4A
    db 23,0,167,0,56,125,8,3,220,0,56,8  ; n3210 t=152.493s dur=167ms, freq=220Hz, sample=56, buffer_id=08:38
    db 4,0,94,7,81,125,5,4,112,3,81,5  ; n3211 t=152.516s dur=1886ms, freq=880Hz, sample=81, buffer_id=05:51
    db 34,0,65,10,69,126,3,5,184,1,69,3  ; n3212 t=152.520s dur=2625ms, freq=440Hz, sample=69, buffer_id=03:45
    db 117,0,229,6,81,124,4,0,112,3,81,4  ; n3213 t=152.554s dur=1765ms, freq=880Hz, sample=81, buffer_id=04:51
    db 205,0,5,1,70,125,8,2,210,1,70,8  ; n3214 t=152.671s dur=261ms, freq=466Hz, sample=70, buffer_id=08:46
    db 45,0,100,0,69,125,8,3,184,1,69,8  ; n3215 t=152.876s dur=100ms, freq=440Hz, sample=69, buffer_id=08:45
    db 182,0,100,0,74,124,4,6,75,2,74,4  ; n3216 t=152.921s dur=100ms, freq=587Hz, sample=74, buffer_id=04:4A
    db 19,0,100,0,70,124,4,1,184,1,70,4  ; n3217 t=153.103s dur=100ms, freq=440Hz, sample=70, buffer_id=04:46
    db 117,0,100,0,62,125,8,7,38,1,62,8  ; n3218 t=153.122s dur=100ms, freq=294Hz, sample=62, buffer_id=08:3E
    db 110,0,100,0,74,124,4,2,75,2,74,4  ; n3219 t=153.239s dur=100ms, freq=587Hz, sample=74, buffer_id=04:4A
    db 42,0,8,1,74,125,8,3,75,2,74,8  ; n3220 t=153.349s dur=264ms, freq=587Hz, sample=74, buffer_id=08:4A
    db 15,0,50,1,75,124,4,6,147,2,75,4  ; n3221 t=153.391s dur=306ms, freq=659Hz, sample=75, buffer_id=04:4B
    db 167,0,167,0,56,125,8,1,220,0,56,8  ; n3222 t=153.406s dur=167ms, freq=220Hz, sample=56, buffer_id=08:38
    db 212,0,9,1,70,125,8,2,210,1,70,8  ; n3223 t=153.573s dur=265ms, freq=466Hz, sample=70, buffer_id=08:46
    db 68,0,100,0,69,125,8,1,184,1,69,8  ; n3224 t=153.785s dur=100ms, freq=440Hz, sample=69, buffer_id=08:45
    db 26,0,100,0,74,124,4,3,75,2,74,4  ; n3225 t=153.853s dur=100ms, freq=587Hz, sample=74, buffer_id=04:4A
    db 140,0,125,0,63,125,5,7,38,1,63,5  ; n3226 t=153.880s dur=125ms, freq=294Hz, sample=63, buffer_id=05:3F
    db 26,0,100,0,62,125,8,6,38,1,62,8  ; n3227 t=154.020s dur=100ms, freq=294Hz, sample=62, buffer_id=08:3E
    db 49,0,100,0,70,124,4,2,184,1,70,4  ; n3228 t=154.046s dur=100ms, freq=440Hz, sample=70, buffer_id=04:46
    db 68,0,113,0,63,125,5,1,74,1,63,5  ; n3229 t=154.095s dur=113ms, freq=330Hz, sample=63, buffer_id=05:3F
    db 76,0,100,0,74,124,4,9,75,2,74,4  ; n3230 t=154.164s dur=100ms, freq=587Hz, sample=74, buffer_id=04:4A
    db 4,0,144,2,38,76,9,3,78,0,38,8  ; n3231 t=154.239s dur=656ms, freq=78Hz, sample=38, buffer_id=08:26
    db 42,0,113,0,59,76,9,7,247,0,59,8  ; n3232 t=154.243s dur=113ms, freq=247Hz, sample=59, buffer_id=08:3B
    db 15,0,1,1,70,125,8,10,238,1,70,8  ; n3233 t=154.285s dur=257ms, freq=494Hz, sample=70, buffer_id=08:46
    db 4,0,128,0,63,125,5,11,38,1,63,5  ; n3234 t=154.300s dur=128ms, freq=294Hz, sample=63, buffer_id=05:3F
    db 11,0,167,0,56,125,8,12,220,0,56,8  ; n3235 t=154.304s dur=167ms, freq=220Hz, sample=56, buffer_id=08:38
    db 0,0,154,5,82,124,4,13,220,3,82,4  ; n3236 t=154.315s dur=1434ms, freq=988Hz, sample=82, buffer_id=04:52
    db 8,0,155,0,63,125,5,1,114,1,63,5  ; n3237 t=154.315s dur=155ms, freq=370Hz, sample=63, buffer_id=05:3F [TRUNCATE prev:ch1 @154095.5ms -> 154315.2ms]
    db 30,0,62,6,78,124,4,6,228,2,78,4  ; n3238 t=154.323s dur=1598ms, freq=740Hz, sample=78, buffer_id=04:4E
    db 0,0,113,0,74,125,5,2,75,2,74,5  ; n3239 t=154.353s dur=113ms, freq=587Hz, sample=74, buffer_id=05:4A
    db 151,0,113,0,69,125,5,8,184,1,69,5  ; n3240 t=154.353s dur=113ms, freq=440Hz, sample=69, buffer_id=05:45 [TRUNCATE prev:ch8 @150640.9ms -> 154353.1ms]
    db 227,0,1,1,67,125,8,9,136,1,67,8  ; n3241 t=154.505s dur=257ms, freq=392Hz, sample=67, buffer_id=08:43
    db 30,0,16,1,65,125,8,0,114,1,65,8  ; n3242 t=154.732s dur=272ms, freq=370Hz, sample=65, buffer_id=08:41
    db 19,0,128,0,58,125,5,1,247,0,58,5  ; n3243 t=154.762s dur=128ms, freq=247Hz, sample=58, buffer_id=05:3A
    db 8,0,100,0,74,125,5,4,75,2,74,5  ; n3244 t=154.781s dur=100ms, freq=587Hz, sample=74, buffer_id=05:4A
    db 11,0,100,0,69,125,5,2,184,1,69,5  ; n3245 t=154.789s dur=100ms, freq=440Hz, sample=69, buffer_id=05:45
    db 167,0,100,0,63,125,5,7,38,1,63,5  ; n3246 t=154.800s dur=100ms, freq=294Hz, sample=63, buffer_id=05:3F
    db 224,0,113,0,59,125,8,8,247,0,59,8  ; n3247 t=154.967s dur=113ms, freq=247Hz, sample=59, buffer_id=08:3B
    db 11,0,238,0,70,125,8,1,238,1,70,8  ; n3248 t=155.190s dur=238ms, freq=494Hz, sample=70, buffer_id=08:46
    db 19,0,167,0,56,125,8,2,220,0,56,8  ; n3249 t=155.202s dur=167ms, freq=220Hz, sample=56, buffer_id=08:38
    db 11,0,103,3,65,126,3,0,114,1,65,3  ; n3250 t=155.220s dur=871ms, freq=370Hz, sample=65, buffer_id=03:41
    db 4,0,100,0,69,125,5,3,184,1,69,5  ; n3251 t=155.232s dur=100ms, freq=440Hz, sample=69, buffer_id=05:45
    db 0,0,100,0,63,125,5,4,38,1,63,5  ; n3252 t=155.236s dur=100ms, freq=294Hz, sample=63, buffer_id=05:3F
    db 19,0,100,0,74,125,5,7,75,2,74,5  ; n3253 t=155.236s dur=100ms, freq=587Hz, sample=74, buffer_id=05:4A
    db 144,0,31,3,58,125,5,9,247,0,58,5  ; n3254 t=155.255s dur=799ms, freq=247Hz, sample=58, buffer_id=05:3A
    db 159,0,246,0,67,125,8,5,136,1,67,8  ; n3255 t=155.399s dur=246ms, freq=392Hz, sample=67, buffer_id=08:43
    db 8,0,100,0,69,125,5,4,184,1,69,5  ; n3256 t=155.558s dur=100ms, freq=440Hz, sample=69, buffer_id=05:45
    db 4,0,100,0,74,125,5,3,75,2,74,5  ; n3257 t=155.565s dur=100ms, freq=587Hz, sample=74, buffer_id=05:4A
    db 45,0,100,0,81,125,5,2,112,3,81,5  ; n3258 t=155.569s dur=100ms, freq=880Hz, sample=81, buffer_id=05:51
    db 95,0,31,1,65,125,8,7,114,1,65,8  ; n3259 t=155.614s dur=287ms, freq=370Hz, sample=65, buffer_id=08:41
    db 0,0,100,0,74,125,5,1,75,2,74,5  ; n3260 t=155.709s dur=100ms, freq=587Hz, sample=74, buffer_id=05:4A
    db 4,0,100,0,69,125,5,8,184,1,69,5  ; n3261 t=155.709s dur=100ms, freq=440Hz, sample=69, buffer_id=05:45
    db 129,0,100,0,81,125,5,10,112,3,81,5  ; n3262 t=155.713s dur=100ms, freq=880Hz, sample=81, buffer_id=05:51
    db 0,0,100,0,69,125,5,11,184,1,69,5  ; n3263 t=155.842s dur=100ms, freq=440Hz, sample=69, buffer_id=05:45
    db 15,0,113,0,59,125,8,12,247,0,59,8  ; n3264 t=155.842s dur=113ms, freq=247Hz, sample=59, buffer_id=08:3B
    db 11,0,100,0,81,125,5,5,112,3,81,5  ; n3265 t=155.857s dur=100ms, freq=880Hz, sample=81, buffer_id=05:51
    db 114,0,100,0,74,125,5,4,75,2,74,5  ; n3266 t=155.868s dur=100ms, freq=587Hz, sample=74, buffer_id=05:4A
    db 0,0,100,0,69,125,5,2,184,1,69,5  ; n3267 t=155.982s dur=100ms, freq=440Hz, sample=69, buffer_id=05:45
    db 11,0,100,0,81,125,5,3,112,3,81,5  ; n3268 t=155.982s dur=100ms, freq=880Hz, sample=81, buffer_id=05:51
    db 87,0,100,0,74,125,5,13,75,2,74,5  ; n3269 t=155.993s dur=100ms, freq=587Hz, sample=74, buffer_id=05:4A
    db 15,0,134,1,70,125,8,1,238,1,70,8  ; n3270 t=156.080s dur=390ms, freq=494Hz, sample=70, buffer_id=08:46
    db 19,0,167,0,56,125,8,8,220,0,56,8  ; n3271 t=156.095s dur=167ms, freq=220Hz, sample=56, buffer_id=08:38
    db 19,0,121,0,69,125,5,7,136,1,69,5  ; n3272 t=156.114s dur=121ms, freq=392Hz, sample=69, buffer_id=05:45
    db 4,0,125,10,62,126,3,6,38,1,62,3  ; n3273 t=156.133s dur=2685ms, freq=294Hz, sample=62, buffer_id=03:3E
    db 0,0,223,0,79,125,5,10,16,3,79,5  ; n3274 t=156.137s dur=223ms, freq=784Hz, sample=79, buffer_id=05:4F
    db 38,0,231,0,86,125,5,0,151,4,86,5  ; n3275 t=156.137s dur=231ms, freq=1175Hz, sample=86, buffer_id=05:56 [TRUNCATE prev:ch0 @155220.5ms -> 156137.1ms]
    db 45,0,100,0,69,125,5,4,136,1,69,5  ; n3276 t=156.175s dur=100ms, freq=392Hz, sample=69, buffer_id=05:45
    db 8,0,100,0,62,125,8,5,38,1,62,8  ; n3277 t=156.220s dur=100ms, freq=294Hz, sample=62, buffer_id=08:3E
    db 106,0,102,0,50,76,9,11,147,0,50,8  ; n3278 t=156.228s dur=102ms, freq=147Hz, sample=50, buffer_id=08:32
    db 8,0,102,0,61,125,8,2,21,1,61,8  ; n3279 t=156.334s dur=102ms, freq=277Hz, sample=61, buffer_id=08:3D
    db 106,0,102,0,50,76,9,3,139,0,50,8  ; n3280 t=156.342s dur=102ms, freq=139Hz, sample=50, buffer_id=08:32
    db 8,0,102,0,58,125,8,7,233,0,58,8  ; n3281 t=156.448s dur=102ms, freq=233Hz, sample=58, buffer_id=08:3A
    db 106,0,102,0,47,76,9,9,117,0,47,8  ; n3282 t=156.455s dur=102ms, freq=117Hz, sample=47, buffer_id=08:2F
    db 0,0,100,0,56,125,8,4,220,0,56,8  ; n3283 t=156.561s dur=100ms, freq=220Hz, sample=56, buffer_id=08:38
    db 8,0,136,0,29,76,9,5,46,0,29,8  ; n3284 t=156.561s dur=136ms, freq=46Hz, sample=29, buffer_id=08:1D
    db 106,0,102,0,43,76,9,0,110,0,43,8  ; n3285 t=156.569s dur=102ms, freq=110Hz, sample=43, buffer_id=08:2B
    db 8,0,102,0,58,125,8,1,233,0,58,8  ; n3286 t=156.675s dur=102ms, freq=233Hz, sample=58, buffer_id=08:3A
    db 106,0,102,0,47,76,9,2,117,0,47,8  ; n3287 t=156.683s dur=102ms, freq=117Hz, sample=47, buffer_id=08:2F
    db 0,0,102,0,61,125,8,3,21,1,61,8  ; n3288 t=156.789s dur=102ms, freq=277Hz, sample=61, buffer_id=08:3D
    db 7,0,162,0,27,76,9,7,41,0,27,8  ; n3289 t=156.789s dur=162ms, freq=41Hz, sample=27, buffer_id=08:1B
    db 106,0,102,0,50,76,9,8,139,0,50,8  ; n3290 t=156.796s dur=102ms, freq=139Hz, sample=50, buffer_id=08:32
    db 8,0,100,0,62,125,8,0,38,1,62,8  ; n3291 t=156.902s dur=100ms, freq=294Hz, sample=62, buffer_id=08:3E
    db 106,0,102,0,50,76,9,4,147,0,50,8  ; n3292 t=156.910s dur=102ms, freq=147Hz, sample=50, buffer_id=08:32
    db 8,0,100,0,56,125,8,1,220,0,56,8  ; n3293 t=157.016s dur=100ms, freq=220Hz, sample=56, buffer_id=08:38
    db 106,0,102,0,43,76,9,2,110,0,43,8  ; n3294 t=157.024s dur=102ms, freq=110Hz, sample=43, buffer_id=08:2B
    db 7,0,102,0,58,125,8,3,233,0,58,8  ; n3295 t=157.130s dur=102ms, freq=233Hz, sample=58, buffer_id=08:3A
    db 106,0,102,0,47,76,9,5,117,0,47,8  ; n3296 t=157.137s dur=102ms, freq=117Hz, sample=47, buffer_id=08:2F
    db 8,0,102,0,61,125,8,0,21,1,61,8  ; n3297 t=157.243s dur=102ms, freq=277Hz, sample=61, buffer_id=08:3D
    db 106,0,102,0,50,76,9,7,139,0,50,8  ; n3298 t=157.251s dur=102ms, freq=139Hz, sample=50, buffer_id=08:32
    db 8,0,100,0,62,125,8,1,38,1,62,8  ; n3299 t=157.357s dur=100ms, freq=294Hz, sample=62, buffer_id=08:3E
    db 114,0,102,0,50,76,9,2,147,0,50,8  ; n3300 t=157.364s dur=102ms, freq=147Hz, sample=50, buffer_id=08:32
    db 106,0,64,5,74,125,5,3,75,2,74,5  ; n3301 t=157.478s dur=1344ms, freq=587Hz, sample=74, buffer_id=05:4A
    db 8,0,100,0,62,125,8,0,38,1,62,8  ; n3302 t=157.584s dur=100ms, freq=294Hz, sample=62, buffer_id=08:3E
    db 106,0,102,0,50,76,9,5,147,0,50,8  ; n3303 t=157.592s dur=102ms, freq=147Hz, sample=50, buffer_id=08:32
    db 8,0,102,0,61,125,8,1,21,1,61,8  ; n3304 t=157.698s dur=102ms, freq=277Hz, sample=61, buffer_id=08:3D
    db 106,0,102,0,50,76,9,9,139,0,50,8  ; n3305 t=157.705s dur=102ms, freq=139Hz, sample=50, buffer_id=08:32
    db 8,0,102,0,58,125,8,2,233,0,58,8  ; n3306 t=157.811s dur=102ms, freq=233Hz, sample=58, buffer_id=08:3A
    db 106,0,102,0,47,76,9,4,117,0,47,8  ; n3307 t=157.819s dur=102ms, freq=117Hz, sample=47, buffer_id=08:2F
    db 0,0,102,0,56,125,8,0,220,0,56,8  ; n3308 t=157.925s dur=102ms, freq=220Hz, sample=56, buffer_id=08:38
    db 8,0,174,0,29,76,9,5,46,0,29,8  ; n3309 t=157.925s dur=174ms, freq=46Hz, sample=29, buffer_id=08:1D
    db 106,0,102,0,43,76,9,7,110,0,43,8  ; n3310 t=157.933s dur=102ms, freq=110Hz, sample=43, buffer_id=08:2B
    db 7,0,102,0,58,125,8,1,233,0,58,8  ; n3311 t=158.039s dur=102ms, freq=233Hz, sample=58, buffer_id=08:3A
    db 106,0,102,0,47,76,9,8,117,0,47,8  ; n3312 t=158.046s dur=102ms, freq=117Hz, sample=47, buffer_id=08:2F
    db 8,0,102,0,61,125,8,2,21,1,61,8  ; n3313 t=158.152s dur=102ms, freq=277Hz, sample=61, buffer_id=08:3D
    db 106,0,102,0,50,76,9,4,139,0,50,8  ; n3314 t=158.160s dur=102ms, freq=139Hz, sample=50, buffer_id=08:32
    db 8,0,100,0,62,125,8,0,38,1,62,8  ; n3315 t=158.266s dur=100ms, freq=294Hz, sample=62, buffer_id=08:3E
    db 106,0,102,0,50,76,9,7,147,0,50,8  ; n3316 t=158.274s dur=102ms, freq=147Hz, sample=50, buffer_id=08:32
    db 0,0,102,0,63,125,8,1,74,1,63,8  ; n3317 t=158.380s dur=102ms, freq=330Hz, sample=63, buffer_id=08:3F
    db 7,0,155,0,27,76,9,5,41,0,27,8  ; n3318 t=158.380s dur=155ms, freq=41Hz, sample=27, buffer_id=08:1B
    db 106,0,102,0,53,76,9,8,165,0,53,8  ; n3319 t=158.387s dur=102ms, freq=165Hz, sample=53, buffer_id=08:35
    db 8,0,102,0,65,125,8,2,114,1,65,8  ; n3320 t=158.493s dur=102ms, freq=370Hz, sample=65, buffer_id=08:41
    db 106,0,102,0,53,76,9,4,185,0,53,8  ; n3321 t=158.501s dur=102ms, freq=185Hz, sample=53, buffer_id=08:35
    db 8,0,102,0,67,125,8,0,136,1,67,8  ; n3322 t=158.607s dur=102ms, freq=392Hz, sample=67, buffer_id=08:43
    db 106,0,102,0,55,76,9,7,196,0,55,8  ; n3323 t=158.614s dur=102ms, freq=196Hz, sample=55, buffer_id=08:37
    db 8,0,100,0,69,125,8,1,184,1,69,8  ; n3324 t=158.720s dur=100ms, freq=440Hz, sample=69, buffer_id=08:45
    db 114,0,102,0,56,76,9,8,220,0,56,8  ; n3325 t=158.728s dur=102ms, freq=220Hz, sample=56, buffer_id=08:38
    db 0,0,100,0,58,126,3,2,6,1,58,3  ; n3326 t=158.842s dur=100ms, freq=262Hz, sample=58, buffer_id=03:3A
    db 151,0,113,0,74,125,5,4,11,2,74,5  ; n3327 t=158.842s dur=113ms, freq=523Hz, sample=74, buffer_id=05:4A
    db 0,0,100,0,58,126,3,0,233,0,58,3  ; n3328 t=158.993s dur=100ms, freq=233Hz, sample=58, buffer_id=03:3A
    db 151,0,117,0,69,125,5,5,210,1,69,5  ; n3329 t=158.993s dur=117ms, freq=466Hz, sample=69, buffer_id=05:45
    db 0,0,100,0,58,126,3,1,220,0,58,3  ; n3330 t=159.145s dur=100ms, freq=220Hz, sample=58, buffer_id=03:3A
    db 30,0,128,0,69,125,5,2,184,1,69,5  ; n3331 t=159.145s dur=128ms, freq=440Hz, sample=69, buffer_id=05:45
    db 8,0,100,0,62,125,8,3,38,1,62,8  ; n3332 t=159.175s dur=100ms, freq=294Hz, sample=62, buffer_id=08:3E
    db 95,0,102,0,50,76,9,4,147,0,50,8  ; n3333 t=159.183s dur=102ms, freq=147Hz, sample=50, buffer_id=08:32
    db 11,0,107,3,65,126,3,6,136,1,65,3  ; n3334 t=159.277s dur=875ms, freq=392Hz, sample=65, buffer_id=03:41
    db 7,0,100,0,62,125,8,7,38,1,62,8  ; n3335 t=159.289s dur=100ms, freq=294Hz, sample=62, buffer_id=08:3E
    db 0,0,107,3,79,125,5,0,16,3,79,5  ; n3336 t=159.296s dur=875ms, freq=784Hz, sample=79, buffer_id=05:4F
    db 106,0,102,0,50,76,9,8,147,0,50,8  ; n3337 t=159.296s dur=102ms, freq=147Hz, sample=50, buffer_id=08:32
    db 8,0,102,0,63,125,8,5,74,1,63,8  ; n3338 t=159.402s dur=102ms, freq=330Hz, sample=63, buffer_id=08:3F
    db 106,0,102,0,53,76,9,9,165,0,53,8  ; n3339 t=159.410s dur=102ms, freq=165Hz, sample=53, buffer_id=08:35
    db 8,0,102,0,65,125,8,1,114,1,65,8  ; n3340 t=159.516s dur=102ms, freq=370Hz, sample=65, buffer_id=08:41
    db 106,0,102,0,53,76,9,2,185,0,53,8  ; n3341 t=159.524s dur=102ms, freq=185Hz, sample=53, buffer_id=08:35
    db 7,0,102,0,67,125,8,3,136,1,67,8  ; n3342 t=159.630s dur=102ms, freq=392Hz, sample=67, buffer_id=08:43
    db 106,0,102,0,55,76,9,4,196,0,55,8  ; n3343 t=159.637s dur=102ms, freq=196Hz, sample=55, buffer_id=08:37
    db 0,0,102,0,67,125,8,5,136,1,67,8  ; n3344 t=159.743s dur=102ms, freq=392Hz, sample=67, buffer_id=08:43
    db 8,0,147,0,29,76,9,7,46,0,29,8  ; n3345 t=159.743s dur=147ms, freq=46Hz, sample=29, buffer_id=08:1D
    db 106,0,102,0,55,76,9,8,196,0,55,8  ; n3346 t=159.751s dur=102ms, freq=196Hz, sample=55, buffer_id=08:37
    db 8,0,100,0,69,125,8,1,184,1,69,8  ; n3347 t=159.857s dur=100ms, freq=440Hz, sample=69, buffer_id=08:45
    db 106,0,102,0,56,76,9,2,220,0,56,8  ; n3348 t=159.864s dur=102ms, freq=220Hz, sample=56, buffer_id=08:38
    db 0,0,102,0,70,125,8,3,210,1,70,8  ; n3349 t=159.970s dur=102ms, freq=466Hz, sample=70, buffer_id=08:46
    db 8,0,136,0,27,76,9,4,41,0,27,8  ; n3350 t=159.970s dur=136ms, freq=41Hz, sample=27, buffer_id=08:1B
    db 106,0,102,0,58,76,9,9,233,0,58,8  ; n3351 t=159.978s dur=102ms, freq=233Hz, sample=58, buffer_id=08:3A
    db 8,0,102,0,72,125,8,5,11,2,72,8  ; n3352 t=160.084s dur=102ms, freq=523Hz, sample=72, buffer_id=08:48
    db 114,0,102,0,59,76,9,7,6,1,59,8  ; n3353 t=160.092s dur=102ms, freq=262Hz, sample=59, buffer_id=08:3B
    db 0,0,8,5,62,126,3,1,38,1,62,3  ; n3354 t=160.205s dur=1288ms, freq=294Hz, sample=62, buffer_id=03:3E
    db 106,0,8,5,74,125,5,2,75,2,74,5  ; n3355 t=160.205s dur=1288ms, freq=587Hz, sample=74, buffer_id=05:4A
    db 8,0,102,0,72,125,8,3,42,2,72,8  ; n3356 t=160.311s dur=102ms, freq=554Hz, sample=72, buffer_id=08:48
    db 106,0,102,0,61,76,9,4,21,1,61,8  ; n3357 t=160.319s dur=102ms, freq=277Hz, sample=61, buffer_id=08:3D
    db 8,0,100,0,72,125,8,0,11,2,72,8  ; n3358 t=160.425s dur=100ms, freq=523Hz, sample=72, buffer_id=08:48
    db 105,0,100,0,59,76,9,5,6,1,59,8  ; n3359 t=160.433s dur=100ms, freq=262Hz, sample=59, buffer_id=08:3B
    db 7,0,100,0,70,125,8,6,210,1,70,8  ; n3360 t=160.537s dur=100ms, freq=466Hz, sample=70, buffer_id=08:46
    db 105,0,100,0,58,76,9,7,233,0,58,8  ; n3361 t=160.544s dur=100ms, freq=233Hz, sample=58, buffer_id=08:3A
    db 0,0,100,0,62,125,8,3,38,1,62,8  ; n3362 t=160.649s dur=100ms, freq=294Hz, sample=62, buffer_id=08:3E
    db 7,0,153,0,29,76,9,4,46,0,29,8  ; n3363 t=160.649s dur=153ms, freq=46Hz, sample=29, buffer_id=08:1D
    db 72,1,100,0,50,76,9,8,147,0,50,8  ; n3364 t=160.656s dur=100ms, freq=147Hz, sample=50, buffer_id=08:32
    db 7,0,100,0,69,125,8,0,184,1,69,8  ; n3365 t=160.985s dur=100ms, freq=440Hz, sample=69, buffer_id=08:45
    db 104,0,100,0,56,76,9,3,220,0,56,8  ; n3366 t=160.992s dur=100ms, freq=220Hz, sample=56, buffer_id=08:38
    db 0,0,100,0,72,125,8,4,42,2,72,8  ; n3367 t=161.096s dur=100ms, freq=554Hz, sample=72, buffer_id=08:48
    db 7,0,162,0,27,76,9,5,41,0,27,8  ; n3368 t=161.096s dur=162ms, freq=41Hz, sample=27, buffer_id=08:1B
    db 103,0,100,0,61,76,9,6,21,1,61,8  ; n3369 t=161.104s dur=100ms, freq=277Hz, sample=61, buffer_id=08:3D
    db 7,0,100,0,72,125,8,7,11,2,72,8  ; n3370 t=161.207s dur=100ms, freq=523Hz, sample=72, buffer_id=08:48
    db 103,0,100,0,59,76,9,8,6,1,59,8  ; n3371 t=161.214s dur=100ms, freq=262Hz, sample=59, buffer_id=08:3B
    db 7,0,100,0,70,125,8,0,210,1,70,8  ; n3372 t=161.317s dur=100ms, freq=466Hz, sample=70, buffer_id=08:46
    db 103,0,100,0,58,76,9,3,233,0,58,8  ; n3373 t=161.324s dur=100ms, freq=233Hz, sample=58, buffer_id=08:3A
    db 7,0,100,0,62,125,8,4,38,1,62,8  ; n3374 t=161.427s dur=100ms, freq=294Hz, sample=62, buffer_id=08:3E
    db 110,0,100,0,50,76,9,6,147,0,50,8  ; n3375 t=161.435s dur=100ms, freq=147Hz, sample=50, buffer_id=08:32
    db 0,0,120,0,58,126,3,5,6,1,58,3  ; n3376 t=161.545s dur=120ms, freq=262Hz, sample=58, buffer_id=03:3A
    db 146,0,100,0,74,125,5,7,11,2,74,5  ; n3377 t=161.545s dur=100ms, freq=523Hz, sample=74, buffer_id=05:4A
    db 0,0,127,0,58,126,3,0,233,0,58,3  ; n3378 t=161.691s dur=127ms, freq=233Hz, sample=58, buffer_id=03:3A
    db 146,0,100,0,69,125,5,3,210,1,69,5  ; n3379 t=161.691s dur=100ms, freq=466Hz, sample=69, buffer_id=05:45
    db 0,0,124,0,58,126,3,1,220,0,58,3  ; n3380 t=161.837s dur=124ms, freq=220Hz, sample=58, buffer_id=03:3A
    db 29,0,100,0,69,125,5,2,184,1,69,5  ; n3381 t=161.837s dur=100ms, freq=440Hz, sample=69, buffer_id=05:45
    db 7,0,100,0,62,125,8,5,38,1,62,8  ; n3382 t=161.866s dur=100ms, freq=294Hz, sample=62, buffer_id=08:3E
    db 102,0,100,0,50,76,9,4,147,0,50,8  ; n3383 t=161.873s dur=100ms, freq=147Hz, sample=50, buffer_id=08:32
    db 7,0,100,0,62,125,8,6,38,1,62,8  ; n3384 t=161.976s dur=100ms, freq=294Hz, sample=62, buffer_id=08:3E
    db 0,0,111,3,65,126,3,7,136,1,65,3  ; n3385 t=161.983s dur=879ms, freq=392Hz, sample=65, buffer_id=03:41
    db 0,0,111,3,79,125,5,8,16,3,79,5  ; n3386 t=161.983s dur=879ms, freq=784Hz, sample=79, buffer_id=05:4F
    db 102,0,100,0,50,76,9,9,147,0,50,8  ; n3387 t=161.983s dur=100ms, freq=147Hz, sample=50, buffer_id=08:32
    db 7,0,100,0,63,125,8,0,74,1,63,8  ; n3388 t=162.085s dur=100ms, freq=330Hz, sample=63, buffer_id=08:3F
    db 102,0,100,0,53,76,9,3,165,0,53,8  ; n3389 t=162.092s dur=100ms, freq=165Hz, sample=53, buffer_id=08:35
    db 0,0,100,0,65,125,8,1,114,1,65,8  ; n3390 t=162.195s dur=100ms, freq=370Hz, sample=65, buffer_id=08:41
    db 7,0,156,0,31,76,9,2,55,0,31,8  ; n3391 t=162.195s dur=156ms, freq=55Hz, sample=31, buffer_id=08:1F
    db 102,0,100,0,53,76,9,4,185,0,53,8  ; n3392 t=162.202s dur=100ms, freq=185Hz, sample=53, buffer_id=08:35
    db 7,0,100,0,67,125,8,5,136,1,67,8  ; n3393 t=162.304s dur=100ms, freq=392Hz, sample=67, buffer_id=08:43
    db 102,0,100,0,55,76,9,6,196,0,55,8  ; n3394 t=162.311s dur=100ms, freq=196Hz, sample=55, buffer_id=08:37
    db 0,0,100,0,69,125,8,0,184,1,69,8  ; n3395 t=162.413s dur=100ms, freq=440Hz, sample=69, buffer_id=08:45
    db 7,0,131,0,29,76,9,3,46,0,29,8  ; n3396 t=162.413s dur=131ms, freq=46Hz, sample=29, buffer_id=08:1D
    db 102,0,100,0,56,76,9,9,220,0,56,8  ; n3397 t=162.421s dur=100ms, freq=220Hz, sample=56, buffer_id=08:38
    db 7,0,100,0,70,125,8,1,210,1,70,8  ; n3398 t=162.523s dur=100ms, freq=466Hz, sample=70, buffer_id=08:46
    db 102,0,100,0,58,76,9,4,233,0,58,8  ; n3399 t=162.530s dur=100ms, freq=233Hz, sample=58, buffer_id=08:3A
    db 0,0,100,0,72,125,8,2,11,2,72,8  ; n3400 t=162.632s dur=100ms, freq=523Hz, sample=72, buffer_id=08:48
    db 7,0,142,0,27,76,9,5,41,0,27,8  ; n3401 t=162.632s dur=142ms, freq=41Hz, sample=27, buffer_id=08:1B
    db 102,0,100,0,59,76,9,6,6,1,59,8  ; n3402 t=162.640s dur=100ms, freq=262Hz, sample=59, buffer_id=08:3B
    db 7,0,100,0,72,125,8,0,42,2,72,8  ; n3403 t=162.742s dur=100ms, freq=554Hz, sample=72, buffer_id=08:48
    db 109,0,100,0,61,76,9,3,21,1,61,8  ; n3404 t=162.749s dur=100ms, freq=277Hz, sample=61, buffer_id=08:3D
    db 0,0,52,5,62,126,3,1,38,1,62,3  ; n3405 t=162.859s dur=1332ms, freq=294Hz, sample=62, buffer_id=03:3E
    db 102,0,52,5,74,125,5,4,75,2,74,5  ; n3406 t=162.859s dur=1332ms, freq=587Hz, sample=74, buffer_id=05:4A
    db 7,0,100,0,72,125,8,6,42,2,72,8  ; n3407 t=162.961s dur=100ms, freq=554Hz, sample=72, buffer_id=08:48
    db 102,0,100,0,61,76,9,2,21,1,61,8  ; n3408 t=162.968s dur=100ms, freq=277Hz, sample=61, buffer_id=08:3D
    db 7,0,100,0,72,125,8,3,11,2,72,8  ; n3409 t=163.070s dur=100ms, freq=523Hz, sample=72, buffer_id=08:48
    db 102,0,100,0,59,76,9,0,6,1,59,8  ; n3410 t=163.078s dur=100ms, freq=262Hz, sample=59, buffer_id=08:3B
    db 7,0,100,0,70,125,8,5,210,1,70,8  ; n3411 t=163.180s dur=100ms, freq=466Hz, sample=70, buffer_id=08:46
    db 102,0,100,0,58,76,9,7,233,0,58,8  ; n3412 t=163.187s dur=100ms, freq=233Hz, sample=58, buffer_id=08:3A
    db 109,0,204,0,29,76,9,2,46,0,29,8  ; n3413 t=163.289s dur=204ms, freq=46Hz, sample=29, buffer_id=08:1D
    db 7,0,100,0,72,125,8,0,42,2,72,8  ; n3414 t=163.399s dur=100ms, freq=554Hz, sample=72, buffer_id=08:48
    db 102,0,100,0,61,76,9,3,21,1,61,8  ; n3415 t=163.406s dur=100ms, freq=277Hz, sample=61, buffer_id=08:3D
    db 7,0,100,0,72,125,8,5,11,2,72,8  ; n3416 t=163.508s dur=100ms, freq=523Hz, sample=72, buffer_id=08:48
    db 102,0,100,0,59,76,9,6,6,1,59,8  ; n3417 t=163.516s dur=100ms, freq=262Hz, sample=59, buffer_id=08:3B
    db 7,0,100,0,70,125,8,7,210,1,70,8  ; n3418 t=163.618s dur=100ms, freq=466Hz, sample=70, buffer_id=08:46
    db 102,0,100,0,58,76,9,8,233,0,58,8  ; n3419 t=163.625s dur=100ms, freq=233Hz, sample=58, buffer_id=08:3A
    db 0,0,100,0,62,125,8,0,38,1,62,8  ; n3420 t=163.727s dur=100ms, freq=294Hz, sample=62, buffer_id=08:3E
    db 7,0,160,0,27,76,9,2,41,0,27,8  ; n3421 t=163.727s dur=160ms, freq=41Hz, sample=27, buffer_id=08:1B
    db 65,1,100,0,50,76,9,3,147,0,50,8  ; n3422 t=163.735s dur=100ms, freq=147Hz, sample=50, buffer_id=08:32
    db 7,0,100,0,62,125,8,3,38,1,62,8  ; n3423 t=164.056s dur=100ms, freq=294Hz, sample=62, buffer_id=08:3E
    db 102,0,100,0,50,76,9,0,147,0,50,8  ; n3424 t=164.063s dur=100ms, freq=147Hz, sample=50, buffer_id=08:32
    db 7,0,100,0,67,125,8,2,136,1,67,8  ; n3425 t=164.165s dur=100ms, freq=392Hz, sample=67, buffer_id=08:43
    db 0,0,162,4,58,126,3,5,6,1,58,3  ; n3426 t=164.173s dur=1186ms, freq=262Hz, sample=58, buffer_id=03:3A
    db 0,0,162,4,74,125,5,6,11,2,74,5  ; n3427 t=164.173s dur=1186ms, freq=523Hz, sample=74, buffer_id=05:4A
    db 102,0,100,0,55,76,9,7,196,0,55,8  ; n3428 t=164.173s dur=100ms, freq=196Hz, sample=55, buffer_id=08:37
    db 7,0,100,0,69,125,8,8,184,1,69,8  ; n3429 t=164.275s dur=100ms, freq=440Hz, sample=69, buffer_id=08:45
    db 102,0,100,0,56,76,9,10,220,0,56,8  ; n3430 t=164.282s dur=100ms, freq=220Hz, sample=56, buffer_id=08:38
    db 0,0,100,0,70,125,8,0,210,1,70,8  ; n3431 t=164.384s dur=100ms, freq=466Hz, sample=70, buffer_id=08:46
    db 7,0,142,0,31,76,9,3,58,0,31,8  ; n3432 t=164.384s dur=142ms, freq=58Hz, sample=31, buffer_id=08:1F
    db 102,0,100,0,58,76,9,1,233,0,58,8  ; n3433 t=164.392s dur=100ms, freq=233Hz, sample=58, buffer_id=08:3A
    db 7,0,100,0,72,125,8,2,11,2,72,8  ; n3434 t=164.494s dur=100ms, freq=523Hz, sample=72, buffer_id=08:48
    db 102,0,100,0,59,76,9,4,6,1,59,8  ; n3435 t=164.501s dur=100ms, freq=262Hz, sample=59, buffer_id=08:3B
    db 219,0,146,0,31,76,9,7,55,0,31,8  ; n3436 t=164.603s dur=146ms, freq=55Hz, sample=31, buffer_id=08:1F
    db 0,0,100,0,67,125,8,0,136,1,67,8  ; n3437 t=164.822s dur=100ms, freq=392Hz, sample=67, buffer_id=08:43
    db 7,0,116,0,31,76,9,1,49,0,31,8  ; n3438 t=164.822s dur=116ms, freq=49Hz, sample=31, buffer_id=08:1F
    db 102,0,100,0,55,76,9,2,196,0,55,8  ; n3439 t=164.829s dur=100ms, freq=196Hz, sample=55, buffer_id=08:37
    db 7,0,100,0,69,125,8,3,184,1,69,8  ; n3440 t=164.932s dur=100ms, freq=440Hz, sample=69, buffer_id=08:45
    db 102,0,100,0,56,76,9,4,220,0,56,8  ; n3441 t=164.939s dur=100ms, freq=220Hz, sample=56, buffer_id=08:38
    db 0,0,100,0,70,125,8,7,210,1,70,8  ; n3442 t=165.041s dur=100ms, freq=466Hz, sample=70, buffer_id=08:46
    db 7,0,142,0,29,76,9,8,46,0,29,8  ; n3443 t=165.041s dur=142ms, freq=46Hz, sample=29, buffer_id=08:1D
    db 102,0,100,0,58,76,9,9,233,0,58,8  ; n3444 t=165.048s dur=100ms, freq=233Hz, sample=58, buffer_id=08:3A
    db 7,0,100,0,72,125,8,0,11,2,72,8  ; n3445 t=165.151s dur=100ms, freq=523Hz, sample=72, buffer_id=08:48
    db 102,0,100,0,59,76,9,1,6,1,59,8  ; n3446 t=165.158s dur=100ms, freq=262Hz, sample=59, buffer_id=08:3B
    db 0,0,100,0,72,125,8,2,42,2,72,8  ; n3447 t=165.260s dur=100ms, freq=554Hz, sample=72, buffer_id=08:48
    db 7,0,149,0,27,76,9,3,41,0,27,8  ; n3448 t=165.260s dur=149ms, freq=41Hz, sample=27, buffer_id=08:1B
    db 102,0,100,0,61,76,9,4,21,1,61,8  ; n3449 t=165.268s dur=100ms, freq=277Hz, sample=61, buffer_id=08:3D
    db 7,0,100,0,75,125,8,7,110,2,75,8  ; n3450 t=165.370s dur=100ms, freq=622Hz, sample=75, buffer_id=08:4B
    db 91,0,100,0,63,76,9,9,55,1,63,8  ; n3451 t=165.377s dur=100ms, freq=311Hz, sample=63, buffer_id=08:3F
    db 18,0,100,0,70,125,8,0,210,1,70,8  ; n3452 t=165.468s dur=100ms, freq=466Hz, sample=70, buffer_id=08:46
    db 0,0,135,0,53,126,3,1,175,0,53,3  ; n3453 t=165.487s dur=135ms, freq=175Hz, sample=53, buffer_id=03:35
    db 0,0,138,0,58,124,4,8,233,0,58,4  ; n3454 t=165.487s dur=138ms, freq=233Hz, sample=58, buffer_id=04:3A
    db 0,0,149,0,50,125,5,10,147,0,50,5  ; n3455 t=165.487s dur=149ms, freq=147Hz, sample=50, buffer_id=05:32
    db 102,0,227,4,31,76,9,11,58,0,31,8  ; n3456 t=165.487s dur=1251ms, freq=58Hz, sample=31, buffer_id=08:1F
    db 109,0,100,0,69,125,8,2,184,1,69,8  ; n3457 t=165.589s dur=100ms, freq=440Hz, sample=69, buffer_id=08:45
    db 109,0,100,0,67,125,8,3,136,1,67,8  ; n3458 t=165.698s dur=100ms, freq=392Hz, sample=67, buffer_id=08:43
    db 109,0,100,0,65,125,8,0,93,1,65,8  ; n3459 t=165.808s dur=100ms, freq=349Hz, sample=65, buffer_id=08:41
    db 7,0,100,0,70,125,8,1,210,1,70,8  ; n3460 t=165.917s dur=100ms, freq=466Hz, sample=70, buffer_id=08:46
    db 0,0,236,2,53,126,3,2,175,0,53,3  ; n3461 t=165.924s dur=748ms, freq=175Hz, sample=53, buffer_id=03:35
    db 0,0,225,2,58,124,4,4,233,0,58,4  ; n3462 t=165.924s dur=737ms, freq=233Hz, sample=58, buffer_id=04:3A
    db 102,0,221,2,50,125,5,5,147,0,50,5  ; n3463 t=165.924s dur=733ms, freq=147Hz, sample=50, buffer_id=05:32
    db 109,0,100,0,69,125,8,3,184,1,69,8  ; n3464 t=166.027s dur=100ms, freq=440Hz, sample=69, buffer_id=08:45
    db 109,0,100,0,67,125,8,0,136,1,67,8  ; n3465 t=166.136s dur=100ms, freq=392Hz, sample=67, buffer_id=08:43
    db 109,0,100,0,65,125,8,1,93,1,65,8  ; n3466 t=166.246s dur=100ms, freq=349Hz, sample=65, buffer_id=08:41
    db 109,0,100,0,70,125,8,3,210,1,70,8  ; n3467 t=166.355s dur=100ms, freq=466Hz, sample=70, buffer_id=08:46
    db 109,0,100,0,69,125,8,0,184,1,69,8  ; n3468 t=166.465s dur=100ms, freq=440Hz, sample=69, buffer_id=08:45
    db 109,0,100,0,67,125,8,1,136,1,67,8  ; n3469 t=166.574s dur=100ms, freq=392Hz, sample=67, buffer_id=08:43
    db 109,0,100,0,65,125,8,3,93,1,65,8  ; n3470 t=166.684s dur=100ms, freq=349Hz, sample=65, buffer_id=08:41
    db 7,0,100,0,75,125,8,0,110,2,75,8  ; n3471 t=166.793s dur=100ms, freq=622Hz, sample=75, buffer_id=08:4B
    db 0,0,164,0,55,126,3,6,196,0,55,3  ; n3472 t=166.800s dur=164ms, freq=196Hz, sample=55, buffer_id=03:37
    db 0,0,127,0,58,124,4,7,233,0,58,4  ; n3473 t=166.800s dur=127ms, freq=233Hz, sample=58, buffer_id=04:3A
    db 0,0,229,0,51,125,5,8,156,0,51,5  ; n3474 t=166.800s dur=229ms, freq=156Hz, sample=51, buffer_id=05:33
    db 102,0,237,0,38,76,9,9,78,0,38,8  ; n3475 t=166.800s dur=237ms, freq=78Hz, sample=38, buffer_id=08:26
    db 109,0,100,0,74,125,8,1,75,2,74,8  ; n3476 t=166.903s dur=100ms, freq=587Hz, sample=74, buffer_id=08:4A
    db 109,0,100,0,72,125,8,2,11,2,72,8  ; n3477 t=167.012s dur=100ms, freq=523Hz, sample=72, buffer_id=08:48
    db 109,0,100,0,70,125,8,0,210,1,70,8  ; n3478 t=167.121s dur=100ms, freq=466Hz, sample=70, buffer_id=08:46
    db 7,0,100,0,70,125,8,1,210,1,70,8  ; n3479 t=167.231s dur=100ms, freq=466Hz, sample=70, buffer_id=08:46
    db 0,0,156,0,53,126,3,3,175,0,53,3  ; n3480 t=167.238s dur=156ms, freq=175Hz, sample=53, buffer_id=03:35
    db 0,0,138,0,58,124,4,5,233,0,58,4  ; n3481 t=167.238s dur=138ms, freq=233Hz, sample=58, buffer_id=04:3A
    db 0,0,160,0,50,125,5,4,147,0,50,5  ; n3482 t=167.238s dur=160ms, freq=147Hz, sample=50, buffer_id=05:32
    db 102,0,15,5,31,76,9,6,58,0,31,8  ; n3483 t=167.238s dur=1295ms, freq=58Hz, sample=31, buffer_id=08:1F
    db 109,0,100,0,69,125,8,2,184,1,69,8  ; n3484 t=167.340s dur=100ms, freq=440Hz, sample=69, buffer_id=08:45
    db 110,0,100,0,67,125,8,0,136,1,67,8  ; n3485 t=167.450s dur=100ms, freq=392Hz, sample=67, buffer_id=08:43
    db 109,0,100,0,65,125,8,1,93,1,65,8  ; n3486 t=167.560s dur=100ms, freq=349Hz, sample=65, buffer_id=08:41
    db 7,0,100,0,70,125,8,2,210,1,70,8  ; n3487 t=167.669s dur=100ms, freq=466Hz, sample=70, buffer_id=08:46
    db 0,0,232,2,53,126,3,4,175,0,53,3  ; n3488 t=167.676s dur=744ms, freq=175Hz, sample=53, buffer_id=03:35
    db 0,0,250,2,58,124,4,3,233,0,58,4  ; n3489 t=167.676s dur=762ms, freq=233Hz, sample=58, buffer_id=04:3A
    db 102,0,207,2,50,125,5,5,147,0,50,5  ; n3490 t=167.676s dur=719ms, freq=147Hz, sample=50, buffer_id=05:32
    db 109,0,100,0,69,125,8,0,184,1,69,8  ; n3491 t=167.778s dur=100ms, freq=440Hz, sample=69, buffer_id=08:45
    db 109,0,100,0,67,125,8,1,136,1,67,8  ; n3492 t=167.888s dur=100ms, freq=392Hz, sample=67, buffer_id=08:43
    db 109,0,100,0,65,125,8,2,93,1,65,8  ; n3493 t=167.997s dur=100ms, freq=349Hz, sample=65, buffer_id=08:41
    db 109,0,100,0,70,125,8,0,210,1,70,8  ; n3494 t=168.107s dur=100ms, freq=466Hz, sample=70, buffer_id=08:46
    db 109,0,100,0,69,125,8,1,184,1,69,8  ; n3495 t=168.216s dur=100ms, freq=440Hz, sample=69, buffer_id=08:45
    db 109,0,100,0,67,125,8,2,136,1,67,8  ; n3496 t=168.326s dur=100ms, freq=392Hz, sample=67, buffer_id=08:43
    db 110,0,100,0,65,125,8,0,93,1,65,8  ; n3497 t=168.435s dur=100ms, freq=349Hz, sample=65, buffer_id=08:41
    db 7,0,100,0,75,125,8,1,110,2,75,8  ; n3498 t=168.545s dur=100ms, freq=622Hz, sample=75, buffer_id=08:4B
    db 0,0,10,1,55,126,3,7,196,0,55,3  ; n3499 t=168.552s dur=266ms, freq=196Hz, sample=55, buffer_id=03:37
    db 0,0,156,0,58,124,4,8,233,0,58,4  ; n3500 t=168.552s dur=156ms, freq=233Hz, sample=58, buffer_id=04:3A
    db 0,0,215,0,51,125,5,9,156,0,51,5  ; n3501 t=168.552s dur=215ms, freq=156Hz, sample=51, buffer_id=05:33
    db 102,0,25,1,38,76,9,10,78,0,38,8  ; n3502 t=168.552s dur=281ms, freq=78Hz, sample=38, buffer_id=08:26
    db 109,0,100,0,74,125,8,2,75,2,74,8  ; n3503 t=168.654s dur=100ms, freq=587Hz, sample=74, buffer_id=08:4A
    db 109,0,100,0,72,125,8,0,11,2,72,8  ; n3504 t=168.764s dur=100ms, freq=523Hz, sample=72, buffer_id=08:48
    db 109,0,100,0,70,125,8,1,210,1,70,8  ; n3505 t=168.873s dur=100ms, freq=466Hz, sample=70, buffer_id=08:46
    db 7,0,100,0,70,125,8,2,210,1,70,8  ; n3506 t=168.983s dur=100ms, freq=466Hz, sample=70, buffer_id=08:46
    db 0,0,189,0,53,126,3,3,175,0,53,3  ; n3507 t=168.990s dur=189ms, freq=175Hz, sample=53, buffer_id=03:35
    db 0,0,156,0,58,124,4,4,233,0,58,4  ; n3508 t=168.990s dur=156ms, freq=233Hz, sample=58, buffer_id=04:3A
    db 0,0,167,0,48,125,5,5,131,0,48,5  ; n3509 t=168.990s dur=167ms, freq=131Hz, sample=48, buffer_id=05:30
    db 102,0,26,5,31,76,9,8,49,0,31,8  ; n3510 t=168.990s dur=1306ms, freq=49Hz, sample=31, buffer_id=08:1F
    db 109,0,100,0,69,125,8,0,184,1,69,8  ; n3511 t=169.092s dur=100ms, freq=440Hz, sample=69, buffer_id=08:45
    db 109,0,100,0,67,125,8,1,136,1,67,8  ; n3512 t=169.202s dur=100ms, freq=392Hz, sample=67, buffer_id=08:43
    db 110,0,100,0,65,125,8,2,93,1,65,8  ; n3513 t=169.311s dur=100ms, freq=349Hz, sample=65, buffer_id=08:41
    db 7,0,100,0,70,125,8,0,210,1,70,8  ; n3514 t=169.421s dur=100ms, freq=466Hz, sample=70, buffer_id=08:46
    db 0,0,159,2,53,126,3,4,175,0,53,3  ; n3515 t=169.428s dur=671ms, freq=175Hz, sample=53, buffer_id=03:35
    db 0,0,228,2,58,124,4,3,233,0,58,4  ; n3516 t=169.428s dur=740ms, freq=233Hz, sample=58, buffer_id=04:3A
    db 102,0,163,2,48,125,5,6,131,0,48,5  ; n3517 t=169.428s dur=675ms, freq=131Hz, sample=48, buffer_id=05:30
    db 109,0,100,0,69,125,8,1,184,1,69,8  ; n3518 t=169.530s dur=100ms, freq=440Hz, sample=69, buffer_id=08:45
    db 109,0,100,0,67,125,8,2,136,1,67,8  ; n3519 t=169.640s dur=100ms, freq=392Hz, sample=67, buffer_id=08:43
    db 109,0,100,0,65,125,8,0,93,1,65,8  ; n3520 t=169.749s dur=100ms, freq=349Hz, sample=65, buffer_id=08:41
    db 109,0,100,0,70,125,8,1,210,1,70,8  ; n3521 t=169.859s dur=100ms, freq=466Hz, sample=70, buffer_id=08:46
    db 109,0,100,0,69,125,8,2,184,1,69,8  ; n3522 t=169.968s dur=100ms, freq=440Hz, sample=69, buffer_id=08:45
    db 109,0,100,0,67,125,8,0,136,1,67,8  ; n3523 t=170.078s dur=100ms, freq=392Hz, sample=67, buffer_id=08:43
    db 109,0,100,0,65,125,8,1,93,1,65,8  ; n3524 t=170.187s dur=100ms, freq=349Hz, sample=65, buffer_id=08:41
    db 7,0,100,0,75,125,8,2,110,2,75,8  ; n3525 t=170.297s dur=100ms, freq=622Hz, sample=75, buffer_id=08:4B
    db 0,0,237,0,50,126,3,4,156,0,50,3  ; n3526 t=170.304s dur=237ms, freq=156Hz, sample=50, buffer_id=03:32
    db 0,0,164,0,58,124,4,5,233,0,58,4  ; n3527 t=170.304s dur=164ms, freq=233Hz, sample=58, buffer_id=04:3A
    db 0,0,240,0,48,125,5,7,131,0,48,5  ; n3528 t=170.304s dur=240ms, freq=131Hz, sample=48, buffer_id=05:30
    db 102,0,14,1,43,76,9,6,87,0,43,8  ; n3529 t=170.304s dur=270ms, freq=87Hz, sample=43, buffer_id=08:2B
    db 109,0,100,0,74,125,8,0,75,2,74,8  ; n3530 t=170.406s dur=100ms, freq=587Hz, sample=74, buffer_id=08:4A
    db 109,0,100,0,72,125,8,1,11,2,72,8  ; n3531 t=170.516s dur=100ms, freq=523Hz, sample=72, buffer_id=08:48
    db 109,0,100,0,70,125,8,2,210,1,70,8  ; n3532 t=170.625s dur=100ms, freq=466Hz, sample=70, buffer_id=08:46
    db 7,0,100,0,70,125,8,0,210,1,70,8  ; n3533 t=170.735s dur=100ms, freq=466Hz, sample=70, buffer_id=08:46
    db 0,0,178,0,53,126,3,3,175,0,53,3  ; n3534 t=170.742s dur=178ms, freq=175Hz, sample=53, buffer_id=03:35
    db 0,0,149,0,58,124,4,4,233,0,58,4  ; n3535 t=170.742s dur=149ms, freq=233Hz, sample=58, buffer_id=04:3A
    db 0,0,229,0,48,125,5,5,131,0,48,5  ; n3536 t=170.742s dur=229ms, freq=131Hz, sample=48, buffer_id=05:30
    db 102,0,70,5,31,76,9,9,49,0,31,8  ; n3537 t=170.742s dur=1350ms, freq=49Hz, sample=31, buffer_id=08:1F
    db 109,0,100,0,69,125,8,1,184,1,69,8  ; n3538 t=170.844s dur=100ms, freq=440Hz, sample=69, buffer_id=08:45
    db 109,0,100,0,67,125,8,2,136,1,67,8  ; n3539 t=170.954s dur=100ms, freq=392Hz, sample=67, buffer_id=08:43
    db 109,0,100,0,65,125,8,0,93,1,65,8  ; n3540 t=171.063s dur=100ms, freq=349Hz, sample=65, buffer_id=08:41
    db 7,0,100,0,70,125,8,1,210,1,70,8  ; n3541 t=171.173s dur=100ms, freq=466Hz, sample=70, buffer_id=08:46
    db 0,0,250,2,53,126,3,4,175,0,53,3  ; n3542 t=171.180s dur=762ms, freq=175Hz, sample=53, buffer_id=03:35
    db 0,0,181,2,58,124,4,3,233,0,58,4  ; n3543 t=171.180s dur=693ms, freq=233Hz, sample=58, buffer_id=04:3A
    db 102,0,217,2,48,125,5,6,131,0,48,5  ; n3544 t=171.180s dur=729ms, freq=131Hz, sample=48, buffer_id=05:30
    db 109,0,100,0,69,125,8,2,184,1,69,8  ; n3545 t=171.282s dur=100ms, freq=440Hz, sample=69, buffer_id=08:45
    db 109,0,100,0,67,125,8,0,136,1,67,8  ; n3546 t=171.392s dur=100ms, freq=392Hz, sample=67, buffer_id=08:43
    db 109,0,100,0,65,125,8,1,93,1,65,8  ; n3547 t=171.501s dur=100ms, freq=349Hz, sample=65, buffer_id=08:41
    db 109,0,100,0,70,125,8,2,210,1,70,8  ; n3548 t=171.611s dur=100ms, freq=466Hz, sample=70, buffer_id=08:46
    db 109,0,100,0,69,125,8,0,184,1,69,8  ; n3549 t=171.720s dur=100ms, freq=440Hz, sample=69, buffer_id=08:45
    db 109,0,100,0,67,125,8,1,136,1,67,8  ; n3550 t=171.829s dur=100ms, freq=392Hz, sample=67, buffer_id=08:43
    db 109,0,100,0,65,125,8,2,93,1,65,8  ; n3551 t=171.939s dur=100ms, freq=349Hz, sample=65, buffer_id=08:41
    db 7,0,100,0,75,125,8,0,110,2,75,8  ; n3552 t=172.048s dur=100ms, freq=622Hz, sample=75, buffer_id=08:4B
    db 0,0,219,0,50,126,3,5,156,0,50,3  ; n3553 t=172.056s dur=219ms, freq=156Hz, sample=50, buffer_id=03:32
    db 0,0,186,0,58,124,4,7,233,0,58,4  ; n3554 t=172.056s dur=186ms, freq=233Hz, sample=58, buffer_id=04:3A
    db 0,0,211,0,48,125,5,8,131,0,48,5  ; n3555 t=172.056s dur=211ms, freq=131Hz, sample=48, buffer_id=05:30
    db 102,0,222,0,43,76,9,10,87,0,43,8  ; n3556 t=172.056s dur=222ms, freq=87Hz, sample=43, buffer_id=08:2B
    db 110,0,100,0,74,125,8,1,75,2,74,8  ; n3557 t=172.158s dur=100ms, freq=587Hz, sample=74, buffer_id=08:4A
    db 109,0,100,0,72,125,8,2,11,2,72,8  ; n3558 t=172.268s dur=100ms, freq=523Hz, sample=72, buffer_id=08:48
    db 117,0,100,0,70,125,8,0,210,1,70,8  ; n3559 t=172.377s dur=100ms, freq=466Hz, sample=70, buffer_id=08:46
    db 18,0,100,0,56,125,8,1,220,0,56,8  ; n3560 t=172.494s dur=100ms, freq=220Hz, sample=56, buffer_id=08:38
    db 0,0,218,1,50,76,9,3,147,0,50,8  ; n3561 t=172.512s dur=474ms, freq=147Hz, sample=50, buffer_id=08:32
    db 84,0,218,1,29,76,9,4,44,0,29,8  ; n3562 t=172.512s dur=474ms, freq=44Hz, sample=29, buffer_id=08:1D
    db 128,0,100,0,58,125,8,2,233,0,58,8  ; n3563 t=172.596s dur=100ms, freq=233Hz, sample=58, buffer_id=08:3A
    db 109,0,100,0,59,125,8,0,247,0,59,8  ; n3564 t=172.724s dur=100ms, freq=247Hz, sample=59, buffer_id=08:3B
    db 91,0,100,0,61,125,8,1,21,1,61,8  ; n3565 t=172.833s dur=100ms, freq=277Hz, sample=61, buffer_id=08:3D
    db 7,0,100,0,59,125,8,2,247,0,59,8  ; n3566 t=172.924s dur=100ms, freq=247Hz, sample=59, buffer_id=08:3B
    db 0,0,255,2,50,76,9,5,156,0,50,8  ; n3567 t=172.932s dur=767ms, freq=156Hz, sample=50, buffer_id=08:32
    db 102,0,130,4,29,76,9,6,46,0,29,8  ; n3568 t=172.932s dur=1154ms, freq=46Hz, sample=29, buffer_id=08:1D
    db 110,0,100,0,58,125,8,0,233,0,58,8  ; n3569 t=173.034s dur=100ms, freq=233Hz, sample=58, buffer_id=08:3A
    db 109,0,100,0,56,125,8,1,208,0,56,8  ; n3570 t=173.143s dur=100ms, freq=208Hz, sample=56, buffer_id=08:38
    db 109,0,100,0,53,125,8,2,185,0,53,8  ; n3571 t=173.253s dur=100ms, freq=185Hz, sample=53, buffer_id=08:35
    db 109,0,100,0,59,125,8,0,247,0,59,8  ; n3572 t=173.362s dur=100ms, freq=247Hz, sample=59, buffer_id=08:3B
    db 109,0,100,0,61,125,8,1,21,1,61,8  ; n3573 t=173.472s dur=100ms, freq=277Hz, sample=61, buffer_id=08:3D
    db 109,0,100,0,63,125,8,2,55,1,63,8  ; n3574 t=173.581s dur=100ms, freq=311Hz, sample=63, buffer_id=08:3F
    db 109,0,100,0,65,125,8,0,114,1,65,8  ; n3575 t=173.691s dur=100ms, freq=370Hz, sample=65, buffer_id=08:41
    db 109,0,100,0,63,125,8,1,74,1,63,8  ; n3576 t=173.800s dur=100ms, freq=330Hz, sample=63, buffer_id=08:3F
    db 109,0,100,0,63,125,8,3,55,1,63,8  ; n3577 t=173.910s dur=100ms, freq=311Hz, sample=63, buffer_id=08:3F
    db 110,0,100,0,61,125,8,0,21,1,61,8  ; n3578 t=174.019s dur=100ms, freq=277Hz, sample=61, buffer_id=08:3D
    db 128,0,100,0,59,125,8,1,247,0,59,8  ; n3579 t=174.129s dur=100ms, freq=247Hz, sample=59, buffer_id=08:3B
    db 7,0,219,0,82,125,8,2,220,3,82,8  ; n3580 t=174.256s dur=219ms, freq=988Hz, sample=82, buffer_id=08:52
    db 0,0,89,3,53,76,9,3,165,0,53,8  ; n3581 t=174.264s dur=857ms, freq=165Hz, sample=53, buffer_id=08:35
    db 11,0,89,3,31,76,9,4,49,0,31,8  ; n3582 t=174.264s dur=857ms, freq=49Hz, sample=31, buffer_id=08:1F
    db 91,0,100,0,61,125,8,5,21,1,61,8  ; n3583 t=174.275s dur=100ms, freq=277Hz, sample=61, buffer_id=08:3D
    db 109,0,100,0,63,125,8,0,55,1,63,8  ; n3584 t=174.366s dur=100ms, freq=311Hz, sample=63, buffer_id=08:3F
    db 69,0,100,0,63,125,8,1,74,1,63,8  ; n3585 t=174.476s dur=100ms, freq=330Hz, sample=63, buffer_id=08:3F
    db 40,0,100,0,87,125,8,6,85,4,87,8  ; n3586 t=174.545s dur=100ms, freq=1109Hz, sample=87, buffer_id=08:57
    db 26,0,100,0,68,125,8,5,159,1,68,8  ; n3587 t=174.585s dur=100ms, freq=415Hz, sample=68, buffer_id=08:44
    db 29,0,100,0,87,125,8,7,221,4,87,8  ; n3588 t=174.611s dur=100ms, freq=1245Hz, sample=87, buffer_id=08:57
    db 51,0,100,0,87,125,8,8,39,5,87,8  ; n3589 t=174.640s dur=100ms, freq=1319Hz, sample=87, buffer_id=08:57
    db 4,0,100,0,89,125,8,0,200,5,89,8  ; n3590 t=174.691s dur=100ms, freq=1480Hz, sample=89, buffer_id=08:59
    db 11,0,100,0,65,125,8,2,114,1,65,8  ; n3591 t=174.695s dur=100ms, freq=370Hz, sample=65, buffer_id=08:41
    db 99,0,100,0,75,102,6,9,110,2,75,6  ; n3592 t=174.705s dur=100ms, freq=622Hz, sample=75, buffer_id=06:4B
    db 109,0,100,0,63,125,8,10,55,1,63,8  ; n3593 t=174.804s dur=100ms, freq=311Hz, sample=63, buffer_id=08:3F
    db 33,0,100,0,61,125,8,1,21,1,61,8  ; n3594 t=174.913s dur=100ms, freq=277Hz, sample=61, buffer_id=08:3D
    db 77,0,100,0,75,102,6,5,147,2,75,6  ; n3595 t=174.946s dur=100ms, freq=659Hz, sample=75, buffer_id=06:4B
    db 99,0,100,0,63,125,8,0,55,1,63,8  ; n3596 t=175.023s dur=100ms, freq=311Hz, sample=63, buffer_id=08:3F
    db 0,0,200,1,29,76,9,2,46,0,29,8  ; n3597 t=175.121s dur=456ms, freq=46Hz, sample=29, buffer_id=08:1D
    db 11,0,200,1,50,76,9,6,156,0,50,8  ; n3598 t=175.121s dur=456ms, freq=156Hz, sample=50, buffer_id=08:32
    db 22,0,100,0,63,125,8,7,74,1,63,8  ; n3599 t=175.132s dur=100ms, freq=330Hz, sample=63, buffer_id=08:3F
    db 88,0,100,0,77,102,6,8,228,2,77,6  ; n3600 t=175.154s dur=100ms, freq=740Hz, sample=77, buffer_id=06:4D
    db 106,0,100,0,70,125,8,1,210,1,70,8  ; n3601 t=175.242s dur=100ms, freq=466Hz, sample=70, buffer_id=08:46
    db 4,0,100,0,82,102,6,0,63,3,82,6  ; n3602 t=175.348s dur=100ms, freq=831Hz, sample=82, buffer_id=06:52
    db 109,0,100,0,72,125,8,3,42,2,72,8  ; n3603 t=175.351s dur=100ms, freq=554Hz, sample=72, buffer_id=08:48
    db 99,0,100,0,70,125,8,4,238,1,70,8  ; n3604 t=175.461s dur=100ms, freq=494Hz, sample=70, buffer_id=08:46
    db 0,0,218,1,31,76,9,1,49,0,31,8  ; n3605 t=175.560s dur=474ms, freq=49Hz, sample=31, buffer_id=08:1F
    db 11,0,218,1,53,76,9,5,165,0,53,8  ; n3606 t=175.560s dur=474ms, freq=165Hz, sample=53, buffer_id=08:35
    db 0,0,100,0,75,102,6,7,110,2,75,6  ; n3607 t=175.570s dur=100ms, freq=622Hz, sample=75, buffer_id=06:4B
    db 109,0,100,0,70,125,8,8,210,1,70,8  ; n3608 t=175.570s dur=100ms, freq=466Hz, sample=70, buffer_id=08:46
    db 106,0,100,0,68,125,8,0,159,1,68,8  ; n3609 t=175.680s dur=100ms, freq=415Hz, sample=68, buffer_id=08:44
    db 4,0,100,0,75,102,6,2,147,2,75,6  ; n3610 t=175.786s dur=100ms, freq=659Hz, sample=75, buffer_id=06:4B
    db 109,0,100,0,65,125,8,3,114,1,65,8  ; n3611 t=175.789s dur=100ms, freq=370Hz, sample=65, buffer_id=08:41
    db 109,0,100,0,63,125,8,4,74,1,63,8  ; n3612 t=175.899s dur=100ms, freq=330Hz, sample=63, buffer_id=08:3F
    db 0,0,100,0,63,125,8,0,55,1,63,8  ; n3613 t=176.008s dur=100ms, freq=311Hz, sample=63, buffer_id=08:3F
    db 11,0,100,0,70,125,8,6,238,1,70,8  ; n3614 t=176.008s dur=100ms, freq=494Hz, sample=70, buffer_id=08:46
    db 18,0,211,1,43,76,9,7,92,0,43,8  ; n3615 t=176.019s dur=467ms, freq=92Hz, sample=43, buffer_id=08:2B
    db 7,0,211,1,50,76,9,8,156,0,50,8  ; n3616 t=176.038s dur=467ms, freq=156Hz, sample=50, buffer_id=08:32
    db 55,0,100,0,77,102,6,9,228,2,77,6  ; n3617 t=176.045s dur=100ms, freq=740Hz, sample=77, buffer_id=06:4D
    db 18,0,100,0,70,125,8,2,210,1,70,8  ; n3618 t=176.100s dur=100ms, freq=466Hz, sample=70, buffer_id=08:46
    db 91,0,100,0,65,125,8,10,114,1,65,8  ; n3619 t=176.118s dur=100ms, freq=370Hz, sample=65, buffer_id=08:41
    db 18,0,100,0,68,125,8,3,159,1,68,8  ; n3620 t=176.209s dur=100ms, freq=415Hz, sample=68, buffer_id=08:44
    db 91,0,100,0,63,125,8,11,74,1,63,8  ; n3621 t=176.227s dur=100ms, freq=330Hz, sample=63, buffer_id=08:3F
    db 18,0,100,0,65,125,8,0,114,1,65,8  ; n3622 t=176.319s dur=100ms, freq=370Hz, sample=65, buffer_id=08:41
    db 80,0,100,0,63,125,8,1,55,1,63,8  ; n3623 t=176.337s dur=100ms, freq=311Hz, sample=63, buffer_id=08:3F
    db 11,0,100,0,75,125,8,2,147,2,75,8  ; n3624 t=176.417s dur=100ms, freq=659Hz, sample=75, buffer_id=08:4B
    db 11,0,100,0,70,125,8,4,238,1,70,8  ; n3625 t=176.428s dur=100ms, freq=494Hz, sample=70, buffer_id=08:46
    db 7,0,100,0,77,125,8,5,228,2,77,8  ; n3626 t=176.439s dur=100ms, freq=740Hz, sample=77, buffer_id=08:4D
    db 26,0,100,0,61,125,8,6,21,1,61,8  ; n3627 t=176.446s dur=100ms, freq=277Hz, sample=61, buffer_id=08:3D
    db 0,0,229,1,53,76,9,9,165,0,53,8  ; n3628 t=176.472s dur=485ms, freq=165Hz, sample=53, buffer_id=08:35
    db 11,0,229,1,43,76,9,10,98,0,43,8  ; n3629 t=176.472s dur=485ms, freq=98Hz, sample=43, buffer_id=08:2B
    db 55,0,100,0,77,102,6,12,228,2,77,6  ; n3630 t=176.483s dur=100ms, freq=740Hz, sample=77, buffer_id=06:4D
    db 18,0,100,0,70,125,8,3,210,1,70,8  ; n3631 t=176.538s dur=100ms, freq=466Hz, sample=70, buffer_id=08:46
    db 91,0,100,0,59,125,8,11,247,0,59,8  ; n3632 t=176.556s dur=100ms, freq=247Hz, sample=59, buffer_id=08:3B
    db 18,0,100,0,68,125,8,0,159,1,68,8  ; n3633 t=176.647s dur=100ms, freq=415Hz, sample=68, buffer_id=08:44
    db 91,0,100,0,58,125,8,1,233,0,58,8  ; n3634 t=176.665s dur=100ms, freq=233Hz, sample=58, buffer_id=08:3A
    db 18,0,100,0,65,125,8,2,114,1,65,8  ; n3635 t=176.756s dur=100ms, freq=370Hz, sample=65, buffer_id=08:41
    db 91,0,100,0,56,125,8,4,208,0,56,8  ; n3636 t=176.775s dur=100ms, freq=208Hz, sample=56, buffer_id=08:38
    db 0,0,100,0,70,125,8,5,238,1,70,8  ; n3637 t=176.866s dur=100ms, freq=494Hz, sample=70, buffer_id=08:46
    db 18,0,222,1,50,76,9,3,156,0,50,8  ; n3638 t=176.866s dur=478ms, freq=156Hz, sample=50, buffer_id=08:32
    db 0,0,100,0,63,125,8,6,55,1,63,8  ; n3639 t=176.884s dur=100ms, freq=311Hz, sample=63, buffer_id=08:3F
    db 15,0,222,1,43,76,9,8,92,0,43,8  ; n3640 t=176.884s dur=478ms, freq=92Hz, sample=43, buffer_id=08:2B
    db 77,0,100,0,75,102,6,7,110,2,75,6  ; n3641 t=176.899s dur=100ms, freq=622Hz, sample=75, buffer_id=06:4B
    db 0,0,100,0,61,125,8,0,21,1,61,8  ; n3642 t=176.976s dur=100ms, freq=277Hz, sample=61, buffer_id=08:3D
    db 109,0,100,0,70,125,8,1,210,1,70,8  ; n3643 t=176.976s dur=100ms, freq=466Hz, sample=70, buffer_id=08:46
    db 0,0,100,0,59,125,8,2,247,0,59,8  ; n3644 t=177.085s dur=100ms, freq=247Hz, sample=59, buffer_id=08:3B
    db 36,0,100,0,68,125,8,4,159,1,68,8  ; n3645 t=177.085s dur=100ms, freq=415Hz, sample=68, buffer_id=08:44
    db 58,0,100,0,75,102,6,11,147,2,75,6  ; n3646 t=177.121s dur=100ms, freq=659Hz, sample=75, buffer_id=06:4B
    db 15,0,100,0,75,102,6,5,147,2,75,6  ; n3647 t=177.180s dur=100ms, freq=659Hz, sample=75, buffer_id=06:4B
    db 0,0,100,0,58,125,8,6,233,0,58,8  ; n3648 t=177.195s dur=100ms, freq=233Hz, sample=58, buffer_id=08:3A
    db 84,0,100,0,65,125,8,9,114,1,65,8  ; n3649 t=177.195s dur=100ms, freq=370Hz, sample=65, buffer_id=08:41
    db 18,0,35,2,53,76,9,0,165,0,53,8  ; n3650 t=177.278s dur=547ms, freq=165Hz, sample=53, buffer_id=08:35
    db 7,0,192,1,43,76,9,1,98,0,43,8  ; n3651 t=177.297s dur=448ms, freq=98Hz, sample=43, buffer_id=08:2B
    db 18,0,100,0,75,125,8,7,147,2,75,8  ; n3652 t=177.304s dur=100ms, freq=659Hz, sample=75, buffer_id=08:4B
    db 26,0,100,0,68,125,8,10,159,1,68,8  ; n3653 t=177.322s dur=100ms, freq=415Hz, sample=68, buffer_id=08:44
    db 66,0,100,0,77,102,6,13,228,2,77,6  ; n3654 t=177.348s dur=100ms, freq=740Hz, sample=77, buffer_id=06:4D
    db 0,0,100,0,65,125,8,2,114,1,65,8  ; n3655 t=177.413s dur=100ms, freq=370Hz, sample=65, buffer_id=08:41
    db 109,0,100,0,75,125,8,4,110,2,75,8  ; n3656 t=177.413s dur=100ms, freq=622Hz, sample=75, buffer_id=08:4B
    db 0,0,100,0,63,125,8,5,74,1,63,8  ; n3657 t=177.523s dur=100ms, freq=330Hz, sample=63, buffer_id=08:3F
    db 40,0,100,0,72,125,8,6,42,2,72,8  ; n3658 t=177.523s dur=100ms, freq=554Hz, sample=72, buffer_id=08:48
    db 69,0,100,0,82,102,6,3,63,3,82,6  ; n3659 t=177.563s dur=100ms, freq=831Hz, sample=82, buffer_id=06:52
    db 18,0,100,0,70,125,8,7,238,1,70,8  ; n3660 t=177.632s dur=100ms, freq=494Hz, sample=70, buffer_id=08:46
    db 58,0,100,0,65,125,8,8,114,1,65,8  ; n3661 t=177.651s dur=100ms, freq=370Hz, sample=65, buffer_id=08:41
    db 15,0,68,2,50,76,9,9,156,0,50,8  ; n3662 t=177.709s dur=580ms, freq=156Hz, sample=50, buffer_id=08:32
    db 18,0,100,0,63,125,8,2,55,1,63,8  ; n3663 t=177.724s dur=100ms, freq=311Hz, sample=63, buffer_id=08:3F
    db 22,0,100,0,70,125,8,4,238,1,70,8  ; n3664 t=177.742s dur=100ms, freq=494Hz, sample=70, buffer_id=08:46
    db 22,0,185,1,43,76,9,10,92,0,43,8  ; n3665 t=177.764s dur=441ms, freq=92Hz, sample=43, buffer_id=08:2B
    db 66,0,100,0,75,102,6,12,110,2,75,6  ; n3666 t=177.786s dur=100ms, freq=622Hz, sample=75, buffer_id=06:4B
    db 0,0,100,0,61,125,8,5,21,1,61,8  ; n3667 t=177.851s dur=100ms, freq=277Hz, sample=61, buffer_id=08:3D
    db 109,0,100,0,70,125,8,6,210,1,70,8  ; n3668 t=177.851s dur=100ms, freq=466Hz, sample=70, buffer_id=08:46
    db 0,0,100,0,59,125,8,1,247,0,59,8  ; n3669 t=177.961s dur=100ms, freq=247Hz, sample=59, buffer_id=08:3B
    db 33,0,100,0,68,125,8,3,159,1,68,8  ; n3670 t=177.961s dur=100ms, freq=415Hz, sample=68, buffer_id=08:44
    db 77,0,100,0,75,102,6,7,147,2,75,6  ; n3671 t=177.994s dur=100ms, freq=659Hz, sample=75, buffer_id=06:4B
    db 0,0,100,0,65,125,8,0,114,1,65,8  ; n3672 t=178.070s dur=100ms, freq=370Hz, sample=65, buffer_id=08:41
    db 58,0,100,0,58,125,8,2,233,0,58,8  ; n3673 t=178.070s dur=100ms, freq=233Hz, sample=58, buffer_id=08:3A
    db 25,0,100,0,77,125,8,4,228,2,77,8  ; n3674 t=178.129s dur=100ms, freq=740Hz, sample=77, buffer_id=08:4D
    db 11,0,100,0,82,125,8,5,63,3,82,8  ; n3675 t=178.154s dur=100ms, freq=831Hz, sample=82, buffer_id=08:52
    db 7,0,203,1,53,76,9,6,165,0,53,8  ; n3676 t=178.165s dur=459ms, freq=165Hz, sample=53, buffer_id=08:35
    db 7,0,100,0,82,125,8,8,164,3,82,8  ; n3677 t=178.173s dur=100ms, freq=932Hz, sample=82, buffer_id=08:52
    db 18,0,100,0,70,125,8,11,238,1,70,8  ; n3678 t=178.180s dur=100ms, freq=494Hz, sample=70, buffer_id=08:46
    db 4,0,100,0,63,125,8,12,55,1,63,8  ; n3679 t=178.198s dur=100ms, freq=311Hz, sample=63, buffer_id=08:3F
    db 0,0,100,0,82,125,8,13,220,3,82,8  ; n3680 t=178.202s dur=100ms, freq=988Hz, sample=82, buffer_id=08:52
    db 40,0,203,1,43,76,9,10,98,0,43,8  ; n3681 t=178.202s dur=459ms, freq=98Hz, sample=43, buffer_id=08:2B [TRUNCATE prev:ch10 @177763.8ms -> 178201.8ms]
    db 48,0,100,0,77,102,6,9,228,2,77,6  ; n3682 t=178.242s dur=100ms, freq=740Hz, sample=77, buffer_id=06:4D [TRUNCATE prev:ch9 @177709.1ms -> 178241.9ms]
    db 0,0,100,0,61,125,8,1,21,1,61,8  ; n3683 t=178.289s dur=100ms, freq=277Hz, sample=61, buffer_id=08:3D
    db 109,0,100,0,70,125,8,3,210,1,70,8  ; n3684 t=178.289s dur=100ms, freq=466Hz, sample=70, buffer_id=08:46
    db 0,0,100,0,59,125,8,0,247,0,59,8  ; n3685 t=178.399s dur=100ms, freq=247Hz, sample=59, buffer_id=08:3B
    db 109,0,100,0,68,125,8,2,159,1,68,8  ; n3686 t=178.399s dur=100ms, freq=415Hz, sample=68, buffer_id=08:44
    db 0,0,100,0,58,125,8,4,233,0,58,8  ; n3687 t=178.508s dur=100ms, freq=233Hz, sample=58, buffer_id=08:3A
    db 84,0,100,0,65,125,8,5,114,1,65,8  ; n3688 t=178.508s dur=100ms, freq=370Hz, sample=65, buffer_id=08:41
    db 25,0,244,1,50,76,9,1,156,0,50,8  ; n3689 t=178.592s dur=500ms, freq=156Hz, sample=50, buffer_id=08:32
    db 0,0,100,0,63,125,8,3,55,1,63,8  ; n3690 t=178.618s dur=100ms, freq=311Hz, sample=63, buffer_id=08:3F
    db 11,0,100,0,70,125,8,7,238,1,70,8  ; n3691 t=178.618s dur=100ms, freq=494Hz, sample=70, buffer_id=08:46
    db 40,0,244,1,43,76,9,8,92,0,43,8  ; n3692 t=178.629s dur=500ms, freq=92Hz, sample=43, buffer_id=08:2B
    db 58,0,100,0,77,102,6,11,228,2,77,6  ; n3693 t=178.669s dur=100ms, freq=740Hz, sample=77, buffer_id=06:4D
    db 0,0,100,0,61,125,8,0,21,1,61,8  ; n3694 t=178.727s dur=100ms, freq=277Hz, sample=61, buffer_id=08:3D
    db 109,0,100,0,70,125,8,2,210,1,70,8  ; n3695 t=178.727s dur=100ms, freq=466Hz, sample=70, buffer_id=08:46
    db 0,0,100,0,59,125,8,4,247,0,59,8  ; n3696 t=178.837s dur=100ms, freq=247Hz, sample=59, buffer_id=08:3B
    db 109,0,100,0,68,125,8,5,159,1,68,8  ; n3697 t=178.837s dur=100ms, freq=415Hz, sample=68, buffer_id=08:44
    db 0,0,100,0,77,125,8,3,228,2,77,8  ; n3698 t=178.946s dur=100ms, freq=740Hz, sample=77, buffer_id=08:4D
    db 0,0,100,0,65,125,8,6,114,1,65,8  ; n3699 t=178.946s dur=100ms, freq=370Hz, sample=65, buffer_id=08:41
    db 33,0,100,0,58,125,8,7,233,0,58,8  ; n3700 t=178.946s dur=100ms, freq=233Hz, sample=58, buffer_id=08:3A
    db 47,0,100,0,82,125,8,9,63,3,82,8  ; n3701 t=178.979s dur=100ms, freq=831Hz, sample=82, buffer_id=08:52
    db 4,0,167,1,53,76,9,10,165,0,53,8  ; n3702 t=179.027s dur=423ms, freq=165Hz, sample=53, buffer_id=08:35
    db 25,0,100,0,82,125,8,0,164,3,82,8  ; n3703 t=179.030s dur=100ms, freq=932Hz, sample=82, buffer_id=08:52
    db 0,0,100,0,68,125,8,2,159,1,68,8  ; n3704 t=179.056s dur=100ms, freq=415Hz, sample=68, buffer_id=08:44
    db 7,0,100,0,75,125,8,11,147,2,75,8  ; n3705 t=179.056s dur=100ms, freq=659Hz, sample=75, buffer_id=08:4B
    db 11,0,167,1,43,76,9,12,98,0,43,8  ; n3706 t=179.063s dur=423ms, freq=98Hz, sample=43, buffer_id=08:2B
    db 33,0,100,0,82,125,8,13,220,3,82,8  ; n3707 t=179.074s dur=100ms, freq=988Hz, sample=82, buffer_id=08:52 [TRUNCATE prev:ch13 @178201.8ms -> 179074.1ms]
    db 58,0,100,0,75,102,6,1,110,2,75,6  ; n3708 t=179.107s dur=100ms, freq=622Hz, sample=75, buffer_id=06:4B [TRUNCATE prev:ch1 @178592.3ms -> 179106.9ms]
    db 0,0,100,0,65,125,8,4,114,1,65,8  ; n3709 t=179.165s dur=100ms, freq=370Hz, sample=65, buffer_id=08:41
    db 109,0,100,0,75,125,8,5,110,2,75,8  ; n3710 t=179.165s dur=100ms, freq=622Hz, sample=75, buffer_id=08:4B
    db 0,0,100,0,63,125,8,3,74,1,63,8  ; n3711 t=179.275s dur=100ms, freq=330Hz, sample=63, buffer_id=08:3F
    db 44,0,100,0,72,125,8,6,42,2,72,8  ; n3712 t=179.275s dur=100ms, freq=554Hz, sample=72, buffer_id=08:48
    db 66,0,100,0,75,102,6,7,147,2,75,6  ; n3713 t=179.319s dur=100ms, freq=659Hz, sample=75, buffer_id=06:4B
    db 18,0,100,0,70,125,8,0,238,1,70,8  ; n3714 t=179.384s dur=100ms, freq=494Hz, sample=70, buffer_id=08:46
    db 99,0,100,0,63,125,8,2,55,1,63,8  ; n3715 t=179.403s dur=100ms, freq=311Hz, sample=63, buffer_id=08:3F
    db 0,0,244,1,47,76,9,1,123,0,47,8  ; n3716 t=179.501s dur=500ms, freq=123Hz, sample=47, buffer_id=08:2F
    db 11,0,108,2,38,76,9,4,82,0,38,8  ; n3717 t=179.501s dur=620ms, freq=82Hz, sample=38, buffer_id=08:26
    db 62,0,120,0,63,125,8,5,55,1,63,8  ; n3718 t=179.512s dur=120ms, freq=311Hz, sample=63, buffer_id=08:3F
    db 36,0,100,0,42,102,6,8,92,0,42,6  ; n3719 t=179.574s dur=100ms, freq=92Hz, sample=42, buffer_id=06:2A
    db 55,0,127,0,61,125,8,3,21,1,61,8  ; n3720 t=179.611s dur=127ms, freq=277Hz, sample=61, buffer_id=08:3D
    db 58,0,100,0,42,102,6,6,104,0,42,6  ; n3721 t=179.665s dur=100ms, freq=104Hz, sample=42, buffer_id=06:2A
    db 11,0,100,0,59,125,8,0,247,0,59,8  ; n3722 t=179.724s dur=100ms, freq=247Hz, sample=59, buffer_id=08:3B
    db 55,0,100,0,48,102,6,2,117,0,48,6  ; n3723 t=179.735s dur=100ms, freq=117Hz, sample=48, buffer_id=06:30
    db 47,0,100,0,48,102,6,7,123,0,48,6  ; n3724 t=179.789s dur=100ms, freq=123Hz, sample=48, buffer_id=06:30
    db 22,0,109,0,58,125,8,5,233,0,58,8  ; n3725 t=179.837s dur=109ms, freq=233Hz, sample=58, buffer_id=08:3A
    db 73,0,100,0,48,102,6,9,139,0,48,6  ; n3726 t=179.859s dur=100ms, freq=139Hz, sample=48, buffer_id=06:30
    db 22,0,100,0,50,102,6,8,156,0,50,6  ; n3727 t=179.932s dur=100ms, freq=156Hz, sample=50, buffer_id=06:32
    db 15,0,116,0,63,125,8,3,55,1,63,8  ; n3728 t=179.954s dur=116ms, freq=311Hz, sample=63, buffer_id=08:3F
    db 48,0,218,1,50,76,9,6,156,0,50,8  ; n3729 t=179.968s dur=474ms, freq=156Hz, sample=50, buffer_id=08:32
    db 44,0,100,0,52,102,6,10,165,0,52,6  ; n3730 t=180.016s dur=100ms, freq=165Hz, sample=52, buffer_id=06:34
    db 36,0,127,0,61,125,8,0,21,1,61,8  ; n3731 t=180.060s dur=127ms, freq=277Hz, sample=61, buffer_id=08:3D
    db 80,0,100,0,52,102,6,2,185,0,52,6  ; n3732 t=180.096s dur=100ms, freq=185Hz, sample=52, buffer_id=06:34
    db 109,0,105,0,59,125,8,5,247,0,59,8  ; n3733 t=180.176s dur=105ms, freq=247Hz, sample=59, buffer_id=08:3B
    db 99,0,113,0,58,125,8,1,233,0,58,8  ; n3734 t=180.286s dur=113ms, freq=233Hz, sample=58, buffer_id=08:3A
    db 29,0,116,0,75,125,8,3,110,2,75,8  ; n3735 t=180.384s dur=116ms, freq=622Hz, sample=75, buffer_id=08:4B
    db 77,0,254,1,53,76,9,0,185,0,53,8  ; n3736 t=180.413s dur=510ms, freq=185Hz, sample=53, buffer_id=08:35
    db 113,0,149,0,72,125,8,2,42,2,72,8  ; n3737 t=180.490s dur=149ms, freq=554Hz, sample=72, buffer_id=08:48
    db 113,0,100,0,70,125,8,1,238,1,70,8  ; n3738 t=180.603s dur=100ms, freq=494Hz, sample=70, buffer_id=08:46
    db 124,0,116,0,70,125,8,3,210,1,70,8  ; n3739 t=180.716s dur=116ms, freq=466Hz, sample=70, buffer_id=08:46
    db 4,0,177,0,56,76,9,2,208,0,56,8  ; n3740 t=180.840s dur=177ms, freq=208Hz, sample=56, buffer_id=08:38
    db 106,0,113,0,87,125,8,4,221,4,87,8  ; n3741 t=180.844s dur=113ms, freq=1245Hz, sample=87, buffer_id=08:57
    db 110,0,146,0,87,125,8,1,85,4,87,8  ; n3742 t=180.950s dur=146ms, freq=1109Hz, sample=87, buffer_id=08:57
    db 91,0,116,0,82,125,8,3,220,3,82,8  ; n3743 t=181.060s dur=116ms, freq=988Hz, sample=82, buffer_id=08:52
    db 120,0,120,0,82,125,8,0,164,3,82,8  ; n3744 t=181.151s dur=120ms, freq=932Hz, sample=82, buffer_id=08:52
    db 11,0,113,0,87,125,8,2,221,4,87,8  ; n3745 t=181.271s dur=113ms, freq=1245Hz, sample=87, buffer_id=08:57
    db 102,0,64,3,58,76,9,4,233,0,58,8  ; n3746 t=181.282s dur=832ms, freq=233Hz, sample=58, buffer_id=08:3A
    db 95,0,109,0,87,125,8,3,85,4,87,8  ; n3747 t=181.384s dur=109ms, freq=1109Hz, sample=87, buffer_id=08:57
    db 106,0,102,0,82,125,8,1,220,3,82,8  ; n3748 t=181.479s dur=102ms, freq=988Hz, sample=82, buffer_id=08:52
    db 131,0,113,0,82,125,8,2,164,3,82,8  ; n3749 t=181.585s dur=113ms, freq=932Hz, sample=82, buffer_id=08:52
    db 106,0,109,0,82,125,8,3,63,3,82,8  ; n3750 t=181.716s dur=109ms, freq=831Hz, sample=82, buffer_id=08:52
    db 106,0,105,0,77,125,8,0,228,2,77,8  ; n3751 t=181.822s dur=105ms, freq=740Hz, sample=77, buffer_id=08:4D
    db 109,0,100,0,75,125,8,1,147,2,75,8  ; n3752 t=181.928s dur=100ms, freq=659Hz, sample=75, buffer_id=08:4B
    db 91,0,100,0,75,125,8,2,110,2,75,8  ; n3753 t=182.038s dur=100ms, freq=622Hz, sample=75, buffer_id=08:4B
    db 4,0,146,0,61,76,9,0,21,1,61,8  ; n3754 t=182.129s dur=146ms, freq=277Hz, sample=61, buffer_id=08:3D
    db 15,0,113,0,70,76,9,3,210,1,70,8  ; n3755 t=182.132s dur=113ms, freq=466Hz, sample=70, buffer_id=08:46
    db 73,0,102,0,72,125,8,5,42,2,72,8  ; n3756 t=182.147s dur=102ms, freq=554Hz, sample=72, buffer_id=08:48
    db 36,0,100,0,68,76,9,6,159,1,68,8  ; n3757 t=182.220s dur=100ms, freq=415Hz, sample=68, buffer_id=08:44
    db 37,0,100,0,70,125,8,1,238,1,70,8  ; n3758 t=182.256s dur=100ms, freq=494Hz, sample=70, buffer_id=08:46
    db 7,0,100,0,65,76,9,7,114,1,65,8  ; n3759 t=182.293s dur=100ms, freq=370Hz, sample=65, buffer_id=08:41
    db 51,0,100,0,70,125,8,8,210,1,70,8  ; n3760 t=182.300s dur=100ms, freq=466Hz, sample=70, buffer_id=08:46
    db 33,0,100,0,63,76,9,2,74,1,63,8  ; n3761 t=182.351s dur=100ms, freq=330Hz, sample=63, buffer_id=08:3F
    db 40,0,100,0,68,125,8,4,159,1,68,8  ; n3762 t=182.384s dur=100ms, freq=415Hz, sample=68, buffer_id=08:44
    db 33,0,100,0,63,76,9,9,55,1,63,8  ; n3763 t=182.424s dur=100ms, freq=311Hz, sample=63, buffer_id=08:3F
    db 40,0,100,0,65,125,8,3,114,1,65,8  ; n3764 t=182.457s dur=100ms, freq=370Hz, sample=65, buffer_id=08:41
    db 36,0,100,0,61,76,9,5,21,1,61,8  ; n3765 t=182.497s dur=100ms, freq=277Hz, sample=61, buffer_id=08:3D
    db 33,0,100,0,63,125,8,0,74,1,63,8  ; n3766 t=182.534s dur=100ms, freq=330Hz, sample=63, buffer_id=08:3F
    db 4,0,182,1,63,76,9,1,55,1,63,8  ; n3767 t=182.567s dur=438ms, freq=311Hz, sample=63, buffer_id=08:3F
    db 33,0,100,0,59,76,9,6,247,0,59,8  ; n3768 t=182.570s dur=100ms, freq=247Hz, sample=59, buffer_id=08:3B
    db 40,0,100,0,63,125,8,7,55,1,63,8  ; n3769 t=182.603s dur=100ms, freq=311Hz, sample=63, buffer_id=08:3F
    db 18,0,100,0,58,76,9,8,233,0,58,8  ; n3770 t=182.643s dur=100ms, freq=233Hz, sample=58, buffer_id=08:3A
    db 55,0,100,0,61,125,8,2,21,1,61,8  ; n3771 t=182.662s dur=100ms, freq=277Hz, sample=61, buffer_id=08:3D
    db 15,0,100,0,56,76,9,4,208,0,56,8  ; n3772 t=182.716s dur=100ms, freq=208Hz, sample=56, buffer_id=08:38
    db 58,0,100,0,59,125,8,9,247,0,59,8  ; n3773 t=182.731s dur=100ms, freq=247Hz, sample=59, buffer_id=08:3B
    db 7,0,100,0,53,76,9,3,185,0,53,8  ; n3774 t=182.789s dur=100ms, freq=185Hz, sample=53, buffer_id=08:35
    db 62,0,100,0,58,125,8,10,233,0,58,8  ; n3775 t=182.797s dur=100ms, freq=233Hz, sample=58, buffer_id=08:3A
    db 0,0,100,0,56,125,8,0,208,0,56,8  ; n3776 t=182.859s dur=100ms, freq=208Hz, sample=56, buffer_id=08:38
    db 73,0,100,0,53,76,9,5,165,0,53,8  ; n3777 t=182.859s dur=100ms, freq=165Hz, sample=53, buffer_id=08:35
    db 4,0,100,0,50,76,9,6,156,0,50,8  ; n3778 t=182.932s dur=100ms, freq=156Hz, sample=50, buffer_id=08:32
    db 51,0,100,0,53,125,8,7,185,0,53,8  ; n3779 t=182.935s dur=100ms, freq=185Hz, sample=53, buffer_id=08:35
    db 18,0,100,0,62,76,9,2,38,1,62,8  ; n3780 t=182.987s dur=100ms, freq=294Hz, sample=62, buffer_id=08:3E
    db 4,0,189,2,47,76,9,8,117,0,47,8  ; n3781 t=183.005s dur=701ms, freq=117Hz, sample=47, buffer_id=08:2F
    db 0,0,100,0,65,125,8,11,93,1,65,8  ; n3782 t=183.008s dur=100ms, freq=349Hz, sample=65, buffer_id=08:41
    db 15,0,45,3,50,76,9,12,147,0,50,8  ; n3783 t=183.008s dur=813ms, freq=147Hz, sample=50, buffer_id=08:32
    db 12,0,214,6,31,76,9,4,58,0,31,8  ; n3784 t=183.024s dur=1750ms, freq=58Hz, sample=31, buffer_id=08:1F
    db 12,0,193,3,53,125,8,9,175,0,53,8  ; n3785 t=183.035s dur=961ms, freq=175Hz, sample=53, buffer_id=08:35
    db 38,0,159,8,53,76,9,13,175,0,53,8  ; n3786 t=183.047s dur=2207ms, freq=175Hz, sample=53, buffer_id=08:35
    db 35,0,100,0,70,125,8,1,210,1,70,8  ; n3787 t=183.085s dur=100ms, freq=466Hz, sample=70, buffer_id=08:46 [TRUNCATE prev:ch1 @182566.8ms -> 183085.3ms]
    db 38,0,100,0,70,102,6,3,210,1,70,6  ; n3788 t=183.120s dur=100ms, freq=466Hz, sample=70, buffer_id=06:46
    db 77,0,100,0,77,125,8,10,186,2,77,8  ; n3789 t=183.158s dur=100ms, freq=698Hz, sample=77, buffer_id=08:4D
    db 4,0,100,0,77,125,8,0,186,2,77,8  ; n3790 t=183.235s dur=100ms, freq=698Hz, sample=77, buffer_id=08:4D
    db 73,0,100,0,77,102,6,5,186,2,77,6  ; n3791 t=183.239s dur=100ms, freq=698Hz, sample=77, buffer_id=06:4D
    db 77,0,100,0,70,125,8,2,210,1,70,8  ; n3792 t=183.312s dur=100ms, freq=466Hz, sample=70, buffer_id=08:46
    db 77,0,100,0,65,125,8,1,93,1,65,8  ; n3793 t=183.389s dur=100ms, freq=349Hz, sample=65, buffer_id=08:41
    db 4,0,100,0,65,125,8,3,93,1,65,8  ; n3794 t=183.466s dur=100ms, freq=349Hz, sample=65, buffer_id=08:41
    db 0,0,242,0,58,125,5,6,233,0,58,5  ; n3795 t=183.470s dur=242ms, freq=233Hz, sample=58, buffer_id=05:3A
    db 4,0,100,0,82,102,6,7,164,3,82,6  ; n3796 t=183.470s dur=100ms, freq=932Hz, sample=82, buffer_id=06:52
    db 69,0,185,3,58,76,9,10,233,0,58,8  ; n3797 t=183.474s dur=953ms, freq=233Hz, sample=58, buffer_id=08:3A
    db 77,0,100,0,70,125,8,0,210,1,70,8  ; n3798 t=183.543s dur=100ms, freq=466Hz, sample=70, buffer_id=08:46
    db 77,0,100,0,77,125,8,2,186,2,77,8  ; n3799 t=183.620s dur=100ms, freq=698Hz, sample=77, buffer_id=08:4D
    db 0,0,100,0,77,102,6,1,186,2,77,6  ; n3800 t=183.697s dur=100ms, freq=698Hz, sample=77, buffer_id=06:4D
    db 77,0,100,0,77,125,8,5,186,2,77,8  ; n3801 t=183.697s dur=100ms, freq=698Hz, sample=77, buffer_id=08:4D
    db 77,0,100,0,70,125,8,3,210,1,70,8  ; n3802 t=183.774s dur=100ms, freq=466Hz, sample=70, buffer_id=08:46
    db 65,0,100,0,65,125,8,0,93,1,65,8  ; n3803 t=183.851s dur=100ms, freq=349Hz, sample=65, buffer_id=08:41
    db 12,0,255,1,63,125,5,6,93,1,63,5  ; n3804 t=183.916s dur=511ms, freq=349Hz, sample=63, buffer_id=05:3F
    db 0,0,100,0,70,102,6,2,210,1,70,6  ; n3805 t=183.928s dur=100ms, freq=466Hz, sample=70, buffer_id=06:46
    db 77,0,100,0,65,125,8,7,93,1,65,8  ; n3806 t=183.928s dur=100ms, freq=349Hz, sample=65, buffer_id=08:41
    db 77,0,100,0,70,125,8,1,210,1,70,8  ; n3807 t=184.005s dur=100ms, freq=466Hz, sample=70, buffer_id=08:46
    db 77,0,100,0,77,125,8,3,186,2,77,8  ; n3808 t=184.082s dur=100ms, freq=698Hz, sample=77, buffer_id=08:4D
    db 0,0,100,0,77,102,6,0,186,2,77,6  ; n3809 t=184.158s dur=100ms, freq=698Hz, sample=77, buffer_id=06:4D
    db 77,0,100,0,77,125,8,8,186,2,77,8  ; n3810 t=184.158s dur=100ms, freq=698Hz, sample=77, buffer_id=08:4D
    db 77,0,100,0,70,125,8,2,210,1,70,8  ; n3811 t=184.235s dur=100ms, freq=466Hz, sample=70, buffer_id=08:46
    db 77,0,100,0,65,125,8,1,93,1,65,8  ; n3812 t=184.312s dur=100ms, freq=349Hz, sample=65, buffer_id=08:41
    db 0,0,100,0,82,102,6,3,164,3,82,6  ; n3813 t=184.389s dur=100ms, freq=932Hz, sample=82, buffer_id=06:52
    db 8,0,100,0,65,125,8,5,93,1,65,8  ; n3814 t=184.389s dur=100ms, freq=349Hz, sample=65, buffer_id=08:41
    db 69,0,100,0,62,76,9,7,38,1,62,8  ; n3815 t=184.397s dur=100ms, freq=294Hz, sample=62, buffer_id=08:3E
    db 77,0,100,0,70,125,8,0,210,1,70,8  ; n3816 t=184.466s dur=100ms, freq=466Hz, sample=70, buffer_id=08:46
    db 4,0,100,0,77,125,8,2,186,2,77,8  ; n3817 t=184.543s dur=100ms, freq=698Hz, sample=77, buffer_id=08:4D
    db 73,0,100,0,63,125,5,8,55,1,63,5  ; n3818 t=184.547s dur=100ms, freq=311Hz, sample=63, buffer_id=05:3F
    db 4,0,100,0,77,125,8,1,186,2,77,8  ; n3819 t=184.620s dur=100ms, freq=698Hz, sample=77, buffer_id=08:4D
    db 38,0,100,0,77,102,6,9,186,2,77,6  ; n3820 t=184.624s dur=100ms, freq=698Hz, sample=77, buffer_id=06:4D
    db 35,0,100,0,63,125,5,10,93,1,63,5  ; n3821 t=184.662s dur=100ms, freq=349Hz, sample=63, buffer_id=05:3F
    db 61,0,100,0,70,125,8,3,210,1,70,8  ; n3822 t=184.697s dur=100ms, freq=466Hz, sample=70, buffer_id=08:46
    db 58,0,100,0,65,125,8,6,93,1,65,8  ; n3823 t=184.758s dur=100ms, freq=349Hz, sample=65, buffer_id=08:41
    db 35,0,234,0,69,125,5,0,136,1,69,5  ; n3824 t=184.816s dur=234ms, freq=392Hz, sample=69, buffer_id=05:45
    db 0,0,100,0,70,102,6,2,11,2,70,6  ; n3825 t=184.851s dur=100ms, freq=523Hz, sample=70, buffer_id=06:46
    db 19,0,106,0,59,76,9,5,6,1,59,8  ; n3826 t=184.851s dur=106ms, freq=262Hz, sample=59, buffer_id=08:3B
    db 58,0,100,0,65,125,8,7,93,1,65,8  ; n3827 t=184.870s dur=100ms, freq=349Hz, sample=65, buffer_id=08:41
    db 77,0,100,0,70,125,8,1,210,1,70,8  ; n3828 t=184.928s dur=100ms, freq=466Hz, sample=70, buffer_id=08:46
    db 77,0,100,0,75,125,8,3,110,2,75,8  ; n3829 t=185.005s dur=100ms, freq=622Hz, sample=75, buffer_id=08:4B
    db 0,0,100,0,77,102,6,4,186,2,77,6  ; n3830 t=185.082s dur=100ms, freq=698Hz, sample=77, buffer_id=06:4D
    db 77,0,100,0,75,125,8,6,110,2,75,8  ; n3831 t=185.082s dur=100ms, freq=622Hz, sample=75, buffer_id=08:4B
    db 61,0,100,0,70,125,8,2,210,1,70,8  ; n3832 t=185.158s dur=100ms, freq=466Hz, sample=70, buffer_id=08:46
    db 58,0,100,0,65,125,8,5,93,1,65,8  ; n3833 t=185.220s dur=100ms, freq=349Hz, sample=65, buffer_id=08:41
    db 23,0,51,1,63,125,5,0,55,1,63,5  ; n3834 t=185.278s dur=307ms, freq=311Hz, sample=63, buffer_id=05:3F
    db 12,0,66,1,65,76,9,1,93,1,65,8  ; n3835 t=185.301s dur=322ms, freq=349Hz, sample=65, buffer_id=08:41
    db 0,0,100,0,82,102,6,3,164,3,82,6  ; n3836 t=185.312s dur=100ms, freq=932Hz, sample=82, buffer_id=06:52
    db 12,0,100,0,65,125,8,8,93,1,65,8  ; n3837 t=185.312s dur=100ms, freq=349Hz, sample=65, buffer_id=08:41
    db 46,0,234,0,75,124,4,7,110,2,75,4  ; n3838 t=185.324s dur=234ms, freq=622Hz, sample=75, buffer_id=04:4B
    db 81,0,100,0,70,125,8,9,210,1,70,8  ; n3839 t=185.370s dur=100ms, freq=466Hz, sample=70, buffer_id=08:46
    db 92,0,100,0,75,125,8,4,110,2,75,8  ; n3840 t=185.451s dur=100ms, freq=622Hz, sample=75, buffer_id=08:4B
    db 12,0,100,0,77,102,6,2,186,2,77,6  ; n3841 t=185.543s dur=100ms, freq=698Hz, sample=77, buffer_id=06:4D
    db 65,0,100,0,75,125,8,5,110,2,75,8  ; n3842 t=185.555s dur=100ms, freq=622Hz, sample=75, buffer_id=08:4B
    db 69,0,100,0,70,125,8,3,210,1,70,8  ; n3843 t=185.620s dur=100ms, freq=466Hz, sample=70, buffer_id=08:46
    db 46,0,100,0,65,125,8,6,93,1,65,8  ; n3844 t=185.689s dur=100ms, freq=349Hz, sample=65, buffer_id=08:41
    db 38,0,100,0,63,125,5,8,55,1,63,5  ; n3845 t=185.735s dur=100ms, freq=311Hz, sample=63, buffer_id=05:3F
    db 0,0,70,1,70,124,4,4,210,1,70,4  ; n3846 t=185.774s dur=326ms, freq=466Hz, sample=70, buffer_id=04:46
    db 4,0,100,0,65,125,8,7,93,1,65,8  ; n3847 t=185.774s dur=100ms, freq=349Hz, sample=65, buffer_id=08:41
    db 8,0,100,0,70,102,6,9,11,2,70,6  ; n3848 t=185.778s dur=100ms, freq=523Hz, sample=70, buffer_id=06:46
    db 65,0,178,10,67,76,9,0,136,1,67,8  ; n3849 t=185.785s dur=2738ms, freq=392Hz, sample=67, buffer_id=08:43
    db 27,0,100,0,70,125,8,1,210,1,70,8  ; n3850 t=185.851s dur=100ms, freq=466Hz, sample=70, buffer_id=08:46
    db 50,0,100,0,63,125,5,2,38,1,63,5  ; n3851 t=185.878s dur=100ms, freq=294Hz, sample=63, buffer_id=05:3F
    db 77,0,100,0,75,125,8,3,110,2,75,8  ; n3852 t=185.928s dur=100ms, freq=622Hz, sample=75, buffer_id=08:4B
    db 4,0,100,0,75,125,8,6,110,2,75,8  ; n3853 t=186.005s dur=100ms, freq=622Hz, sample=75, buffer_id=08:4B
    db 4,0,100,0,77,102,6,5,186,2,77,6  ; n3854 t=186.008s dur=100ms, freq=698Hz, sample=77, buffer_id=06:4D
    db 69,0,100,0,63,125,5,11,55,1,63,5  ; n3855 t=186.012s dur=100ms, freq=311Hz, sample=63, buffer_id=05:3F
    db 42,0,100,0,70,125,8,7,210,1,70,8  ; n3856 t=186.082s dur=100ms, freq=466Hz, sample=70, buffer_id=08:46
    db 38,0,100,0,63,125,5,9,55,1,63,5  ; n3857 t=186.124s dur=100ms, freq=311Hz, sample=63, buffer_id=05:3F
    db 19,0,100,0,65,125,8,1,93,1,65,8  ; n3858 t=186.162s dur=100ms, freq=349Hz, sample=65, buffer_id=08:41
    db 31,0,100,0,63,125,5,12,55,1,63,5  ; n3859 t=186.181s dur=100ms, freq=311Hz, sample=63, buffer_id=05:3F
    db 27,0,100,0,70,124,4,2,159,1,70,4  ; n3860 t=186.212s dur=100ms, freq=415Hz, sample=70, buffer_id=04:46
    db 0,0,100,0,82,102,6,3,164,3,82,6  ; n3861 t=186.239s dur=100ms, freq=932Hz, sample=82, buffer_id=06:52
    db 4,0,106,0,59,76,9,8,6,1,59,8  ; n3862 t=186.239s dur=106ms, freq=262Hz, sample=59, buffer_id=08:3B
    db 4,0,100,0,63,125,5,13,55,1,63,5  ; n3863 t=186.243s dur=100ms, freq=311Hz, sample=63, buffer_id=05:3F
    db 46,0,100,0,65,125,8,10,93,1,65,8  ; n3864 t=186.247s dur=100ms, freq=349Hz, sample=65, buffer_id=08:41
    db 62,0,100,0,70,125,8,7,210,1,70,8  ; n3865 t=186.293s dur=100ms, freq=466Hz, sample=70, buffer_id=08:46 [TRUNCATE prev:ch7 @186081.5ms -> 186293.0ms]
    db 23,0,100,0,65,124,4,4,136,1,65,4  ; n3866 t=186.355s dur=100ms, freq=392Hz, sample=65, buffer_id=04:41
    db 4,0,100,0,63,125,5,5,55,1,63,5  ; n3867 t=186.378s dur=100ms, freq=311Hz, sample=63, buffer_id=05:3F
    db 85,0,100,0,75,125,8,11,110,2,75,8  ; n3868 t=186.381s dur=100ms, freq=622Hz, sample=75, buffer_id=08:4B
    db 4,0,100,0,75,125,8,1,110,2,75,8  ; n3869 t=186.466s dur=100ms, freq=622Hz, sample=75, buffer_id=08:4B
    db 38,0,100,0,77,102,6,6,186,2,77,6  ; n3870 t=186.470s dur=100ms, freq=698Hz, sample=77, buffer_id=06:4D
    db 0,0,100,0,65,124,4,9,93,1,65,4  ; n3871 t=186.508s dur=100ms, freq=349Hz, sample=65, buffer_id=04:41
    db 35,0,100,0,63,125,5,12,55,1,63,5  ; n3872 t=186.508s dur=100ms, freq=311Hz, sample=63, buffer_id=05:3F [TRUNCATE prev:ch12 @186181.5ms -> 186508.4ms]
    db 50,0,100,0,70,125,8,2,210,1,70,8  ; n3873 t=186.543s dur=100ms, freq=466Hz, sample=70, buffer_id=08:46
    db 85,0,100,0,65,125,8,3,93,1,65,8  ; n3874 t=186.593s dur=100ms, freq=349Hz, sample=65, buffer_id=08:41
    db 12,0,73,7,31,76,9,4,58,0,31,8  ; n3875 t=186.678s dur=1865ms, freq=58Hz, sample=31, buffer_id=08:1F
    db 8,0,100,0,68,76,9,5,159,1,68,8  ; n3876 t=186.689s dur=100ms, freq=415Hz, sample=68, buffer_id=08:44
    db 4,0,119,0,63,125,8,7,55,1,63,8  ; n3877 t=186.697s dur=119ms, freq=311Hz, sample=63, buffer_id=08:3F
    db 0,0,99,2,69,125,5,8,159,1,69,5  ; n3878 t=186.701s dur=611ms, freq=415Hz, sample=69, buffer_id=05:45
    db 27,0,100,0,75,102,6,10,110,2,75,6  ; n3879 t=186.701s dur=100ms, freq=622Hz, sample=75, buffer_id=06:4B
    db 46,0,89,5,72,124,4,11,11,2,72,4  ; n3880 t=186.728s dur=1369ms, freq=523Hz, sample=72, buffer_id=04:48
    db 65,0,100,0,70,125,8,1,210,1,70,8  ; n3881 t=186.774s dur=100ms, freq=466Hz, sample=70, buffer_id=08:46
    db 11,0,107,0,69,126,3,6,159,1,69,3  ; n3882 t=186.839s dur=107ms, freq=415Hz, sample=69, buffer_id=03:45
    db 12,0,100,0,75,125,8,2,110,2,75,8  ; n3883 t=186.851s dur=100ms, freq=622Hz, sample=75, buffer_id=08:4B
    db 65,0,100,0,58,126,3,9,6,1,58,3  ; n3884 t=186.862s dur=100ms, freq=262Hz, sample=58, buffer_id=03:3A
    db 0,0,100,0,82,102,6,3,63,3,82,6  ; n3885 t=186.928s dur=100ms, freq=831Hz, sample=82, buffer_id=06:52
    db 69,0,100,0,75,125,8,12,110,2,75,8  ; n3886 t=186.928s dur=100ms, freq=622Hz, sample=75, buffer_id=08:4B
    db 0,0,100,0,70,126,3,5,210,1,70,3  ; n3887 t=186.997s dur=100ms, freq=466Hz, sample=70, buffer_id=03:46
    db 8,0,100,0,63,126,3,13,55,1,63,3  ; n3888 t=186.997s dur=100ms, freq=311Hz, sample=63, buffer_id=03:3F
    db 77,0,100,0,70,125,8,10,210,1,70,8  ; n3889 t=187.005s dur=100ms, freq=466Hz, sample=70, buffer_id=08:46
    db 73,0,100,0,63,125,8,1,55,1,63,8  ; n3890 t=187.082s dur=100ms, freq=311Hz, sample=63, buffer_id=08:3F
    db 4,0,157,0,69,126,3,2,159,1,69,3  ; n3891 t=187.155s dur=157ms, freq=415Hz, sample=69, buffer_id=03:45
    db 4,0,100,0,63,125,8,6,55,1,63,8  ; n3892 t=187.158s dur=100ms, freq=311Hz, sample=63, buffer_id=08:3F
    db 0,0,246,0,77,126,3,7,186,2,77,3  ; n3893 t=187.162s dur=246ms, freq=698Hz, sample=77, buffer_id=03:4D
    db 73,0,100,0,85,102,6,9,221,4,85,6  ; n3894 t=187.162s dur=100ms, freq=1245Hz, sample=85, buffer_id=06:55
    db 77,0,100,0,68,125,8,3,159,1,68,8  ; n3895 t=187.235s dur=100ms, freq=415Hz, sample=68, buffer_id=08:44
    db 77,0,100,0,75,125,8,5,110,2,75,8  ; n3896 t=187.312s dur=100ms, freq=622Hz, sample=75, buffer_id=08:4B
    db 4,0,100,0,75,125,8,1,110,2,75,8  ; n3897 t=187.389s dur=100ms, freq=622Hz, sample=75, buffer_id=08:4B
    db 73,0,100,0,82,102,6,10,63,3,82,6  ; n3898 t=187.393s dur=100ms, freq=831Hz, sample=82, buffer_id=06:52
    db 0,0,100,0,69,126,3,6,159,1,69,3  ; n3899 t=187.466s dur=100ms, freq=415Hz, sample=69, buffer_id=03:45
    db 0,0,100,0,63,125,5,9,38,1,63,5  ; n3900 t=187.466s dur=100ms, freq=294Hz, sample=63, buffer_id=05:3F
    db 11,0,100,0,68,125,8,12,159,1,68,8  ; n3901 t=187.466s dur=100ms, freq=415Hz, sample=68, buffer_id=08:44
    db 31,0,100,0,58,126,3,13,6,1,58,3  ; n3902 t=187.478s dur=100ms, freq=262Hz, sample=58, buffer_id=03:3A
    db 15,0,100,0,70,126,3,0,210,1,70,3  ; n3903 t=187.508s dur=100ms, freq=466Hz, sample=70, buffer_id=03:46 [TRUNCATE prev:ch0 @185785.3ms -> 187508.4ms]
    db 19,0,142,0,63,126,3,2,55,1,63,3  ; n3904 t=187.524s dur=142ms, freq=311Hz, sample=63, buffer_id=03:3F
    db 46,0,100,0,63,125,8,3,55,1,63,8  ; n3905 t=187.543s dur=100ms, freq=311Hz, sample=63, buffer_id=08:3F
    db 19,0,128,3,77,126,3,8,186,2,77,3  ; n3906 t=187.589s dur=896ms, freq=698Hz, sample=77, buffer_id=03:4D
    db 12,0,100,0,72,125,8,7,11,2,72,8  ; n3907 t=187.608s dur=100ms, freq=523Hz, sample=72, buffer_id=08:48
    db 0,0,100,0,69,125,5,5,159,1,69,5  ; n3908 t=187.620s dur=100ms, freq=415Hz, sample=69, buffer_id=05:45
    db 4,0,100,0,63,125,8,4,55,1,63,8  ; n3909 t=187.620s dur=100ms, freq=311Hz, sample=63, buffer_id=08:3F [TRUNCATE prev:ch4 @186677.6ms -> 187619.9ms]
    db 4,0,100,0,75,102,6,11,110,2,75,6  ; n3910 t=187.624s dur=100ms, freq=622Hz, sample=75, buffer_id=06:4B [TRUNCATE prev:ch11 @186727.6ms -> 187623.8ms]
    db 69,0,236,1,69,126,3,6,159,1,69,3  ; n3911 t=187.628s dur=492ms, freq=415Hz, sample=69, buffer_id=03:45 [TRUNCATE prev:ch6 @187466.1ms -> 187627.6ms]
    db 4,0,100,0,65,125,8,1,93,1,65,8  ; n3912 t=187.697s dur=100ms, freq=349Hz, sample=65, buffer_id=08:41
    db 73,0,100,0,74,125,8,10,75,2,74,8  ; n3913 t=187.701s dur=100ms, freq=587Hz, sample=74, buffer_id=08:4A
    db 0,0,100,0,74,125,5,9,11,2,74,5  ; n3914 t=187.774s dur=100ms, freq=523Hz, sample=74, buffer_id=05:4A
    db 8,0,100,0,67,125,8,12,136,1,67,8  ; n3915 t=187.774s dur=100ms, freq=392Hz, sample=67, buffer_id=08:43
    db 69,0,100,0,75,125,8,13,110,2,75,8  ; n3916 t=187.781s dur=100ms, freq=622Hz, sample=75, buffer_id=08:4B
    db 4,0,100,0,68,125,8,0,159,1,68,8  ; n3917 t=187.851s dur=100ms, freq=415Hz, sample=68, buffer_id=08:44
    db 4,0,100,0,82,102,6,3,63,3,82,6  ; n3918 t=187.855s dur=100ms, freq=831Hz, sample=82, buffer_id=06:52
    db 69,0,100,0,77,125,8,2,186,2,77,8  ; n3919 t=187.858s dur=100ms, freq=698Hz, sample=77, buffer_id=08:4D [TRUNCATE prev:ch2 @187523.8ms -> 187858.4ms]
    db 0,0,100,0,63,125,5,4,55,1,63,5  ; n3920 t=187.928s dur=100ms, freq=311Hz, sample=63, buffer_id=05:3F
    db 0,0,100,0,77,125,8,5,16,3,77,8  ; n3921 t=187.928s dur=100ms, freq=784Hz, sample=77, buffer_id=08:4D
    db 73,0,100,0,70,125,8,7,210,1,70,8  ; n3922 t=187.928s dur=100ms, freq=466Hz, sample=70, buffer_id=08:46
    db 4,0,100,0,82,125,8,1,112,3,82,8  ; n3923 t=188.001s dur=100ms, freq=880Hz, sample=82, buffer_id=08:52
    db 77,0,100,0,72,125,8,10,11,2,72,8  ; n3924 t=188.005s dur=100ms, freq=523Hz, sample=72, buffer_id=08:48
    db 0,0,13,1,74,124,4,9,75,2,74,4  ; n3925 t=188.082s dur=269ms, freq=587Hz, sample=74, buffer_id=04:4A
    db 4,0,100,0,72,125,8,11,42,2,72,8  ; n3926 t=188.082s dur=100ms, freq=554Hz, sample=72, buffer_id=08:48
    db 0,0,59,8,74,125,5,12,75,2,74,5  ; n3927 t=188.085s dur=2107ms, freq=587Hz, sample=74, buffer_id=05:4A
    db 0,0,100,0,85,102,6,13,221,4,85,6  ; n3928 t=188.085s dur=100ms, freq=1245Hz, sample=85, buffer_id=06:55
    db 73,0,100,0,82,125,8,8,164,3,82,8  ; n3929 t=188.085s dur=100ms, freq=932Hz, sample=82, buffer_id=08:52 [TRUNCATE prev:ch8 @187589.2ms -> 188085.3ms]
    db 8,0,100,0,75,125,8,0,110,2,75,8  ; n3930 t=188.158s dur=100ms, freq=622Hz, sample=75, buffer_id=08:4B
    db 69,0,100,0,82,125,8,2,23,4,82,8  ; n3931 t=188.166s dur=100ms, freq=1047Hz, sample=82, buffer_id=08:52
    db 4,0,100,0,77,125,8,3,186,2,77,8  ; n3932 t=188.235s dur=100ms, freq=698Hz, sample=77, buffer_id=08:4D
    db 73,0,100,0,87,125,8,4,151,4,87,8  ; n3933 t=188.239s dur=100ms, freq=1175Hz, sample=87, buffer_id=08:57
    db 0,0,100,0,87,125,8,1,221,4,87,8  ; n3934 t=188.312s dur=100ms, freq=1245Hz, sample=87, buffer_id=08:57
    db 69,0,100,0,77,125,8,7,16,3,77,8  ; n3935 t=188.312s dur=100ms, freq=784Hz, sample=77, buffer_id=08:4D
    db 12,0,100,0,89,125,8,5,117,5,89,8  ; n3936 t=188.381s dur=100ms, freq=1397Hz, sample=89, buffer_id=08:59
    db 38,0,100,0,82,125,8,6,63,3,82,8  ; n3937 t=188.393s dur=100ms, freq=831Hz, sample=82, buffer_id=08:52
    db 27,0,100,0,81,124,4,8,112,3,81,4  ; n3938 t=188.431s dur=100ms, freq=880Hz, sample=81, buffer_id=04:51
    db 8,0,100,0,91,125,8,0,32,6,91,8  ; n3939 t=188.458s dur=100ms, freq=1568Hz, sample=91, buffer_id=08:5B
    db 77,0,122,0,82,125,8,10,112,3,82,8  ; n3940 t=188.466s dur=122ms, freq=880Hz, sample=82, buffer_id=08:52
    db 19,0,100,0,50,102,6,2,147,0,50,6  ; n3941 t=188.543s dur=100ms, freq=147Hz, sample=50, buffer_id=06:32
    db 6,0,87,14,94,125,8,3,224,6,94,8  ; n3942 t=188.562s dur=3671ms, freq=1760Hz, sample=94, buffer_id=08:5E
    db 27,0,145,6,81,124,4,4,112,3,81,4  ; n3943 t=188.568s dur=1681ms, freq=880Hz, sample=81, buffer_id=04:51
    db 35,0,100,0,52,102,6,9,165,0,52,6  ; n3944 t=188.595s dur=100ms, freq=165Hz, sample=52, buffer_id=06:34
    db 0,0,100,0,52,102,6,1,185,0,52,6  ; n3945 t=188.630s dur=100ms, freq=185Hz, sample=52, buffer_id=06:34
    db 21,0,184,2,38,76,9,7,73,0,38,8  ; n3946 t=188.630s dur=696ms, freq=73Hz, sample=38, buffer_id=08:26
    db 28,0,48,29,25,76,9,11,37,0,25,8  ; n3947 t=188.651s dur=7472ms, freq=37Hz, sample=25, buffer_id=08:19
    db 42,0,100,0,52,102,6,13,196,0,52,6  ; n3948 t=188.679s dur=100ms, freq=196Hz, sample=52, buffer_id=06:34
    db 35,0,100,0,52,102,6,5,220,0,52,6  ; n3949 t=188.720s dur=100ms, freq=220Hz, sample=52, buffer_id=06:34
    db 35,0,100,0,62,102,6,6,247,0,62,6  ; n3950 t=188.755s dur=100ms, freq=247Hz, sample=62, buffer_id=06:3E
    db 35,0,100,0,62,102,6,0,21,1,62,6  ; n3951 t=188.790s dur=100ms, freq=277Hz, sample=62, buffer_id=06:3E
    db 35,0,100,0,62,102,6,8,38,1,62,6  ; n3952 t=188.825s dur=100ms, freq=294Hz, sample=62, buffer_id=06:3E
    db 35,0,100,0,64,102,6,2,74,1,64,6  ; n3953 t=188.859s dur=100ms, freq=330Hz, sample=64, buffer_id=06:40
    db 35,0,100,0,65,102,6,10,114,1,65,6  ; n3954 t=188.894s dur=100ms, freq=370Hz, sample=65, buffer_id=06:41
    db 35,0,100,0,67,102,6,9,136,1,67,6  ; n3955 t=188.929s dur=100ms, freq=392Hz, sample=67, buffer_id=06:43
    db 90,0,100,0,70,102,6,1,184,1,70,6  ; n3956 t=188.964s dur=100ms, freq=440Hz, sample=70, buffer_id=06:46
    db 62,0,100,0,67,102,6,5,136,1,67,6  ; n3957 t=189.054s dur=100ms, freq=392Hz, sample=67, buffer_id=06:43
    db 49,0,100,0,65,102,6,0,114,1,65,6  ; n3958 t=189.116s dur=100ms, freq=370Hz, sample=65, buffer_id=06:41
    db 70,0,100,0,64,102,6,6,74,1,64,6  ; n3959 t=189.165s dur=100ms, freq=330Hz, sample=64, buffer_id=06:40
    db 139,0,100,0,62,102,6,2,38,1,62,6  ; n3960 t=189.234s dur=100ms, freq=294Hz, sample=62, buffer_id=06:3E
    db 55,0,100,0,50,102,6,1,147,0,50,6  ; n3961 t=189.373s dur=100ms, freq=147Hz, sample=50, buffer_id=06:32
    db 35,0,100,0,52,102,6,0,165,0,52,6  ; n3962 t=189.429s dur=100ms, freq=165Hz, sample=52, buffer_id=06:34
    db 49,0,100,0,52,102,6,5,185,0,52,6  ; n3963 t=189.464s dur=100ms, freq=185Hz, sample=52, buffer_id=06:34
    db 42,0,100,0,52,102,6,6,196,0,52,6  ; n3964 t=189.512s dur=100ms, freq=196Hz, sample=52, buffer_id=06:34
    db 35,0,100,0,52,102,6,2,220,0,52,6  ; n3965 t=189.554s dur=100ms, freq=220Hz, sample=52, buffer_id=06:34
    db 35,0,100,0,62,102,6,7,247,0,62,6  ; n3966 t=189.589s dur=100ms, freq=247Hz, sample=62, buffer_id=06:3E
    db 35,0,100,0,62,102,6,9,21,1,62,6  ; n3967 t=189.623s dur=100ms, freq=277Hz, sample=62, buffer_id=06:3E
    db 35,0,100,0,62,102,6,10,38,1,62,6  ; n3968 t=189.658s dur=100ms, freq=294Hz, sample=62, buffer_id=06:3E
    db 35,0,100,0,64,102,6,1,74,1,64,6  ; n3969 t=189.693s dur=100ms, freq=330Hz, sample=64, buffer_id=06:40
    db 35,0,100,0,65,102,6,8,114,1,65,6  ; n3970 t=189.727s dur=100ms, freq=370Hz, sample=65, buffer_id=06:41
    db 35,0,100,0,67,102,6,0,136,1,67,6  ; n3971 t=189.762s dur=100ms, freq=392Hz, sample=67, buffer_id=06:43
    db 90,0,100,0,70,102,6,5,184,1,70,6  ; n3972 t=189.797s dur=100ms, freq=440Hz, sample=70, buffer_id=06:46
    db 62,0,100,0,67,102,6,2,136,1,67,6  ; n3973 t=189.887s dur=100ms, freq=392Hz, sample=67, buffer_id=06:43
    db 49,0,100,0,65,102,6,6,114,1,65,6  ; n3974 t=189.950s dur=100ms, freq=370Hz, sample=65, buffer_id=06:41
    db 153,0,100,0,64,102,6,7,74,1,64,6  ; n3975 t=189.998s dur=100ms, freq=330Hz, sample=64, buffer_id=06:40
    db 42,0,100,0,52,102,6,0,220,0,52,6  ; n3976 t=190.151s dur=100ms, freq=220Hz, sample=52, buffer_id=06:34
    db 18,0,100,0,62,102,6,1,247,0,62,6  ; n3977 t=190.193s dur=100ms, freq=247Hz, sample=62, buffer_id=06:3E
    db 23,0,112,1,63,125,5,2,38,1,63,5  ; n3978 t=190.211s dur=368ms, freq=294Hz, sample=63, buffer_id=05:3F
    db 37,0,100,0,62,102,6,5,21,1,62,6  ; n3979 t=190.234s dur=100ms, freq=277Hz, sample=62, buffer_id=06:3E
    db 49,0,100,0,62,102,6,6,38,1,62,6  ; n3980 t=190.270s dur=100ms, freq=294Hz, sample=62, buffer_id=06:3E
    db 61,0,100,0,64,102,6,8,74,1,64,6  ; n3981 t=190.319s dur=100ms, freq=330Hz, sample=64, buffer_id=06:40
    db 53,0,100,0,65,102,6,7,114,1,65,6  ; n3982 t=190.380s dur=100ms, freq=370Hz, sample=65, buffer_id=06:41
    db 45,0,100,0,67,102,6,9,136,1,67,6  ; n3983 t=190.433s dur=100ms, freq=392Hz, sample=67, buffer_id=06:43
    db 49,0,100,0,70,102,6,0,184,1,70,6  ; n3984 t=190.478s dur=100ms, freq=440Hz, sample=70, buffer_id=06:46
    db 37,0,100,0,70,102,6,1,238,1,70,6  ; n3985 t=190.526s dur=100ms, freq=494Hz, sample=70, buffer_id=06:46
    db 41,0,100,0,75,102,6,4,42,2,75,6  ; n3986 t=190.563s dur=100ms, freq=554Hz, sample=75, buffer_id=06:4B
    db 33,0,100,0,75,102,6,5,75,2,75,6  ; n3987 t=190.604s dur=100ms, freq=587Hz, sample=75, buffer_id=06:4B
    db 32,0,100,0,75,102,6,6,147,2,75,6  ; n3988 t=190.636s dur=100ms, freq=659Hz, sample=75, buffer_id=06:4B
    db 41,0,100,0,82,102,6,8,112,3,82,6  ; n3989 t=190.669s dur=100ms, freq=880Hz, sample=82, buffer_id=06:52
    db 224,1,109,1,69,125,5,7,184,1,69,5  ; n3990 t=190.709s dur=365ms, freq=440Hz, sample=69, buffer_id=05:45
    db 16,0,100,0,69,125,5,0,136,1,69,5  ; n3991 t=191.189s dur=100ms, freq=392Hz, sample=69, buffer_id=05:45
    db 0,0,8,1,74,125,8,1,75,2,74,8  ; n3992 t=191.205s dur=264ms, freq=587Hz, sample=74, buffer_id=08:4A
    db 20,0,118,7,67,125,8,2,136,1,67,8  ; n3993 t=191.205s dur=1910ms, freq=392Hz, sample=67, buffer_id=08:43
    db 126,0,100,0,69,125,8,4,184,1,69,8  ; n3994 t=191.226s dur=100ms, freq=440Hz, sample=69, buffer_id=08:45
    db 163,0,100,0,63,125,5,5,114,1,63,5  ; n3995 t=191.352s dur=100ms, freq=370Hz, sample=63, buffer_id=05:3F
    db 159,0,100,0,63,125,5,0,74,1,63,5  ; n3996 t=191.514s dur=100ms, freq=330Hz, sample=63, buffer_id=05:3F
    db 24,0,89,1,65,126,3,1,136,1,65,3  ; n3997 t=191.673s dur=345ms, freq=392Hz, sample=65, buffer_id=03:41
    db 207,1,82,11,69,125,5,4,136,1,69,5  ; n3998 t=191.697s dur=2898ms, freq=392Hz, sample=69, buffer_id=05:45
    db 33,0,109,1,74,126,3,0,75,2,74,3  ; n3999 t=192.161s dur=365ms, freq=587Hz, sample=74, buffer_id=03:4A
    db 199,1,70,18,95,125,8,5,184,7,95,8  ; n4000 t=192.193s dur=4678ms, freq=1976Hz, sample=95, buffer_id=08:5F
    db 163,0,100,0,72,126,3,1,11,2,72,3  ; n4001 t=192.649s dur=100ms, freq=523Hz, sample=72, buffer_id=03:48
    db 163,0,100,0,70,126,3,0,238,1,70,3  ; n4002 t=192.811s dur=100ms, freq=494Hz, sample=70, buffer_id=03:46
    db 183,0,100,0,69,126,3,1,184,1,69,3  ; n4003 t=192.974s dur=100ms, freq=440Hz, sample=69, buffer_id=03:45
    db 0,0,180,1,77,125,8,0,16,3,77,8  ; n4004 t=193.157s dur=436ms, freq=784Hz, sample=77, buffer_id=08:4D
    db 20,0,46,6,72,125,8,3,11,2,72,8  ; n4005 t=193.157s dur=1582ms, freq=523Hz, sample=72, buffer_id=08:48
    db 16,0,115,14,100,125,8,6,77,10,100,8  ; n4006 t=193.177s dur=3699ms, freq=2637Hz, sample=100, buffer_id=08:64
    db 4,0,200,14,72,126,3,7,11,2,72,3  ; n4007 t=193.193s dur=3784ms, freq=523Hz, sample=72, buffer_id=03:48
    db 123,5,8,1,74,125,8,8,75,2,74,8  ; n4008 t=193.197s dur=264ms, freq=587Hz, sample=74, buffer_id=08:4A
    db 163,0,101,0,74,125,5,0,147,2,74,5  ; n4009 t=194.600s dur=101ms, freq=659Hz, sample=74, buffer_id=05:4A
    db 163,0,113,0,74,125,5,1,75,2,74,5  ; n4010 t=194.762s dur=113ms, freq=587Hz, sample=74, buffer_id=05:4A
    db 175,0,142,0,74,125,5,2,11,2,74,5  ; n4011 t=194.925s dur=142ms, freq=523Hz, sample=74, buffer_id=05:4A
    db 8,0,244,7,105,125,8,0,192,13,105,8  ; n4012 t=195.100s dur=2036ms, freq=3520Hz, sample=105, buffer_id=08:69
    db 0,0,61,5,79,125,5,1,186,2,79,5  ; n4013 t=195.108s dur=1341ms, freq=698Hz, sample=79, buffer_id=05:4F
    db 0,0,118,7,82,125,8,3,23,4,82,8  ; n4014 t=195.108s dur=1910ms, freq=1047Hz, sample=82, buffer_id=08:52
    db 0,0,234,1,77,125,8,4,186,2,77,8  ; n4015 t=195.108s dur=490ms, freq=698Hz, sample=77, buffer_id=08:4D
    db 183,5,180,1,77,125,8,8,16,3,77,8  ; n4016 t=195.108s dur=436ms, freq=784Hz, sample=77, buffer_id=08:4D
    db 20,0,100,0,74,125,5,4,11,2,74,5  ; n4017 t=196.571s dur=100ms, freq=523Hz, sample=74, buffer_id=05:4A
    db 126,0,100,0,82,124,4,2,23,4,82,4  ; n4018 t=196.591s dur=100ms, freq=1047Hz, sample=82, buffer_id=04:52
    db 28,0,122,0,82,125,8,1,112,3,82,8  ; n4019 t=196.718s dur=122ms, freq=880Hz, sample=82, buffer_id=08:52
    db 20,0,100,0,69,125,5,8,238,1,69,5  ; n4020 t=196.746s dur=100ms, freq=494Hz, sample=69, buffer_id=05:45
    db 29,0,100,0,82,124,4,9,220,3,82,4  ; n4021 t=196.766s dur=100ms, freq=988Hz, sample=82, buffer_id=04:52
    db 81,0,142,0,82,125,8,10,220,3,82,8  ; n4022 t=196.795s dur=142ms, freq=988Hz, sample=82, buffer_id=08:52
    db 12,0,142,0,82,125,8,4,23,4,82,8  ; n4023 t=196.876s dur=142ms, freq=1047Hz, sample=82, buffer_id=08:52
    db 20,0,100,0,81,124,4,11,112,3,81,4  ; n4024 t=196.888s dur=100ms, freq=880Hz, sample=81, buffer_id=04:51
    db 53,0,100,0,69,125,5,2,184,1,69,5  ; n4025 t=196.909s dur=100ms, freq=440Hz, sample=69, buffer_id=05:45
    db 77,0,142,0,87,125,8,12,85,4,87,8  ; n4026 t=196.962s dur=142ms, freq=1109Hz, sample=87, buffer_id=08:57
    db 0,0,57,1,82,125,8,13,112,3,82,8  ; n4027 t=197.039s dur=313ms, freq=880Hz, sample=82, buffer_id=08:52
    db 4,0,57,1,87,125,8,5,151,4,87,8  ; n4028 t=197.039s dur=313ms, freq=1175Hz, sample=87, buffer_id=08:57 [TRUNCATE prev:ch5 @192193.2ms -> 197038.7ms]
    db 8,0,8,1,74,125,8,1,75,2,74,8  ; n4029 t=197.043s dur=264ms, freq=587Hz, sample=74, buffer_id=08:4A
    db 28,0,179,1,86,124,4,8,151,4,86,4  ; n4030 t=197.051s dur=435ms, freq=1175Hz, sample=86, buffer_id=04:56
    db 33,0,170,1,93,124,4,6,224,6,93,4  ; n4031 t=197.079s dur=426ms, freq=1760Hz, sample=93, buffer_id=04:5D
    db 138,1,158,1,74,125,5,9,75,2,74,5  ; n4032 t=197.112s dur=414ms, freq=587Hz, sample=74, buffer_id=05:4A
    db 20,0,117,0,38,76,9,0,73,0,38,8  ; n4033 t=197.506s dur=117ms, freq=73Hz, sample=38, buffer_id=08:26
    db 0,0,100,0,62,126,3,1,38,1,62,3  ; n4034 t=197.526s dur=100ms, freq=294Hz, sample=62, buffer_id=03:3E
    db 4,0,100,0,74,124,4,2,75,2,74,4  ; n4035 t=197.526s dur=100ms, freq=587Hz, sample=74, buffer_id=04:4A
    db 0,0,100,0,50,125,5,3,147,0,50,5  ; n4036 t=197.531s dur=100ms, freq=147Hz, sample=50, buffer_id=05:32
    db 0,0,100,0,38,125,8,4,73,0,38,8  ; n4037 t=197.531s dur=100ms, freq=73Hz, sample=38, buffer_id=08:26
    db 138,0,100,0,50,125,8,7,147,0,50,8  ; n4038 t=197.531s dur=100ms, freq=147Hz, sample=50, buffer_id=08:32
    db 20,0,109,0,38,76,9,5,73,0,38,8  ; n4039 t=197.669s dur=109ms, freq=73Hz, sample=38, buffer_id=08:26
    db 0,0,100,0,62,126,3,8,38,1,62,3  ; n4040 t=197.689s dur=100ms, freq=294Hz, sample=62, buffer_id=03:3E
    db 4,0,100,0,74,124,4,10,75,2,74,4  ; n4041 t=197.689s dur=100ms, freq=587Hz, sample=74, buffer_id=04:4A
    db 0,0,100,0,50,125,5,11,147,0,50,5  ; n4042 t=197.693s dur=100ms, freq=147Hz, sample=50, buffer_id=05:32
    db 0,0,100,0,50,125,8,12,147,0,50,8  ; n4043 t=197.693s dur=100ms, freq=147Hz, sample=50, buffer_id=08:32
    db 142,0,100,0,38,125,8,13,73,0,38,8  ; n4044 t=197.693s dur=100ms, freq=73Hz, sample=38, buffer_id=08:26
    db 16,0,105,0,38,76,9,1,73,0,38,8  ; n4045 t=197.835s dur=105ms, freq=73Hz, sample=38, buffer_id=08:26
    db 0,0,100,0,62,126,3,0,38,1,62,3  ; n4046 t=197.852s dur=100ms, freq=294Hz, sample=62, buffer_id=03:3E
    db 4,0,100,0,74,124,4,3,75,2,74,4  ; n4047 t=197.852s dur=100ms, freq=587Hz, sample=74, buffer_id=04:4A
    db 0,0,100,0,50,125,5,2,147,0,50,5  ; n4048 t=197.856s dur=100ms, freq=147Hz, sample=50, buffer_id=05:32
    db 0,0,100,0,38,125,8,6,73,0,38,8  ; n4049 t=197.856s dur=100ms, freq=73Hz, sample=38, buffer_id=08:26
    db 142,0,100,0,50,125,8,4,147,0,50,8  ; n4050 t=197.856s dur=100ms, freq=147Hz, sample=50, buffer_id=08:32
    db 16,0,248,0,38,76,9,7,73,0,38,8  ; n4051 t=197.998s dur=248ms, freq=73Hz, sample=38, buffer_id=08:26
    db 0,0,227,0,62,126,3,5,38,1,62,3  ; n4052 t=198.014s dur=227ms, freq=294Hz, sample=62, buffer_id=03:3E
    db 4,0,138,0,74,124,4,8,75,2,74,4  ; n4053 t=198.014s dur=138ms, freq=587Hz, sample=74, buffer_id=04:4A
    db 0,0,154,0,50,125,5,9,147,0,50,5  ; n4054 t=198.018s dur=154ms, freq=147Hz, sample=50, buffer_id=05:32
    db 0,0,178,0,38,125,8,10,73,0,38,8  ; n4055 t=198.018s dur=178ms, freq=73Hz, sample=38, buffer_id=08:26
    db 0,0,187,0,50,125,8,11,147,0,50,8  ; n4056 t=198.018s dur=187ms, freq=147Hz, sample=50, buffer_id=08:32
    db 255,255,255,255,255,255,255,255,255,255,255,255  ; End marker

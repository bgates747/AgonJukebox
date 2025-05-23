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

total_notes: equ 5815
midi_data:
    db 0,0,194,13,54,127,7,0,185,0,54,7  ; n1 t=3.429s dur=3522ms, freq=185Hz, sample=54, buffer_id=07:36
    db 100,13,194,13,66,127,7,1,114,1,66,7  ; n2 t=3.429s dur=3522ms, freq=370Hz, sample=66, buffer_id=07:42
    db 0,0,100,0,47,127,5,2,123,0,47,5  ; n3 t=6.857s dur=100ms, freq=123Hz, sample=47, buffer_id=05:2F
    db 0,0,100,0,35,127,6,3,62,0,35,5  ; n4 t=6.857s dur=100ms, freq=62Hz, sample=35, buffer_id=05:23
    db 0,0,218,0,47,127,19,4,123,0,47,19  ; n5 t=6.857s dur=218ms, freq=123Hz, sample=47, buffer_id=13:2F
    db 250,0,218,0,35,127,20,5,62,0,35,20  ; n6 t=6.857s dur=218ms, freq=62Hz, sample=35, buffer_id=14:23
    db 0,0,218,0,47,127,19,6,139,0,47,19  ; n7 t=7.107s dur=218ms, freq=139Hz, sample=47, buffer_id=13:2F
    db 250,0,218,0,35,127,20,7,69,0,35,20  ; n8 t=7.107s dur=218ms, freq=69Hz, sample=35, buffer_id=14:23
    db 0,0,100,0,54,127,5,0,185,0,54,5  ; n9 t=7.357s dur=100ms, freq=185Hz, sample=54, buffer_id=05:36
    db 0,0,100,0,42,127,6,1,92,0,42,5  ; n10 t=7.357s dur=100ms, freq=92Hz, sample=42, buffer_id=05:2A
    db 0,0,218,0,47,127,19,2,147,0,47,19  ; n11 t=7.357s dur=218ms, freq=147Hz, sample=47, buffer_id=13:2F
    db 250,0,218,0,35,127,20,3,73,0,35,20  ; n12 t=7.357s dur=218ms, freq=73Hz, sample=35, buffer_id=14:23
    db 0,0,218,0,54,127,19,4,165,0,54,19  ; n13 t=7.607s dur=218ms, freq=165Hz, sample=54, buffer_id=13:36
    db 250,0,218,0,42,127,20,5,82,0,42,20  ; n14 t=7.607s dur=218ms, freq=82Hz, sample=42, buffer_id=14:2A
    db 0,0,100,0,47,127,5,0,123,0,47,5  ; n15 t=7.857s dur=100ms, freq=123Hz, sample=47, buffer_id=05:2F
    db 0,0,100,0,35,127,6,1,62,0,35,5  ; n16 t=7.857s dur=100ms, freq=62Hz, sample=35, buffer_id=05:23
    db 0,0,218,0,54,127,19,2,185,0,54,19  ; n17 t=7.857s dur=218ms, freq=185Hz, sample=54, buffer_id=13:36
    db 250,0,218,0,42,127,20,3,92,0,42,20  ; n18 t=7.857s dur=218ms, freq=92Hz, sample=42, buffer_id=14:2A
    db 0,0,218,0,47,127,19,4,147,0,47,19  ; n19 t=8.107s dur=218ms, freq=147Hz, sample=47, buffer_id=13:2F
    db 250,0,218,0,35,127,20,5,73,0,35,20  ; n20 t=8.107s dur=218ms, freq=73Hz, sample=35, buffer_id=14:23
    db 0,0,100,0,54,127,5,0,185,0,54,5  ; n21 t=8.357s dur=100ms, freq=185Hz, sample=54, buffer_id=05:36
    db 0,0,100,0,42,127,6,1,92,0,42,5  ; n22 t=8.357s dur=100ms, freq=92Hz, sample=42, buffer_id=05:2A
    db 0,0,212,1,54,127,19,3,185,0,54,19  ; n23 t=8.357s dur=468ms, freq=185Hz, sample=54, buffer_id=13:36
    db 244,1,212,1,42,127,20,2,92,0,42,20  ; n24 t=8.357s dur=468ms, freq=92Hz, sample=42, buffer_id=14:2A
    db 0,0,100,0,47,127,5,0,123,0,47,5  ; n25 t=8.857s dur=100ms, freq=123Hz, sample=47, buffer_id=05:2F
    db 0,0,100,0,35,127,6,1,62,0,35,5  ; n26 t=8.857s dur=100ms, freq=62Hz, sample=35, buffer_id=05:23
    db 0,0,218,0,54,127,19,4,175,0,54,19  ; n27 t=8.857s dur=218ms, freq=175Hz, sample=54, buffer_id=13:36
    db 250,0,218,0,42,127,20,5,87,0,42,20  ; n28 t=8.857s dur=218ms, freq=87Hz, sample=42, buffer_id=14:2A
    db 0,0,218,0,47,127,19,2,139,0,47,19  ; n29 t=9.107s dur=218ms, freq=139Hz, sample=47, buffer_id=13:2F
    db 250,0,218,0,35,127,20,3,69,0,35,20  ; n30 t=9.107s dur=218ms, freq=69Hz, sample=35, buffer_id=14:23
    db 0,0,100,0,54,127,5,0,185,0,54,5  ; n31 t=9.357s dur=100ms, freq=185Hz, sample=54, buffer_id=05:36
    db 0,0,100,0,42,127,6,1,92,0,42,5  ; n32 t=9.357s dur=100ms, freq=92Hz, sample=42, buffer_id=05:2A
    db 0,0,212,1,54,127,19,5,175,0,54,19  ; n33 t=9.357s dur=468ms, freq=175Hz, sample=54, buffer_id=13:36
    db 244,1,212,1,42,127,20,4,87,0,42,20  ; n34 t=9.357s dur=468ms, freq=87Hz, sample=42, buffer_id=14:2A
    db 0,0,100,0,47,127,5,0,123,0,47,5  ; n35 t=9.857s dur=100ms, freq=123Hz, sample=47, buffer_id=05:2F
    db 0,0,100,0,35,127,6,1,62,0,35,5  ; n36 t=9.857s dur=100ms, freq=62Hz, sample=35, buffer_id=05:23
    db 0,0,218,0,54,127,19,2,165,0,54,19  ; n37 t=9.857s dur=218ms, freq=165Hz, sample=54, buffer_id=13:36
    db 250,0,218,0,42,127,20,3,82,0,42,20  ; n38 t=9.857s dur=218ms, freq=82Hz, sample=42, buffer_id=14:2A
    db 0,0,218,0,47,127,19,4,131,0,47,19  ; n39 t=10.107s dur=218ms, freq=131Hz, sample=47, buffer_id=13:2F
    db 250,0,218,0,35,127,20,5,65,0,35,20  ; n40 t=10.107s dur=218ms, freq=65Hz, sample=35, buffer_id=14:23
    db 0,0,100,0,54,127,5,0,185,0,54,5  ; n41 t=10.357s dur=100ms, freq=185Hz, sample=54, buffer_id=05:36
    db 0,0,100,0,42,127,6,1,92,0,42,5  ; n42 t=10.357s dur=100ms, freq=92Hz, sample=42, buffer_id=05:2A
    db 0,0,212,1,54,127,19,3,165,0,54,19  ; n43 t=10.357s dur=468ms, freq=165Hz, sample=54, buffer_id=13:36
    db 244,1,212,1,42,127,20,2,82,0,42,20  ; n44 t=10.357s dur=468ms, freq=82Hz, sample=42, buffer_id=14:2A
    db 0,0,100,0,47,127,5,0,123,0,47,5  ; n45 t=10.857s dur=100ms, freq=123Hz, sample=47, buffer_id=05:2F
    db 0,0,100,0,35,127,6,1,62,0,35,5  ; n46 t=10.857s dur=100ms, freq=62Hz, sample=35, buffer_id=05:23
    db 0,0,218,0,47,127,19,5,123,0,47,19  ; n47 t=10.857s dur=218ms, freq=123Hz, sample=47, buffer_id=13:2F
    db 250,0,218,0,35,127,20,4,62,0,35,20  ; n48 t=10.857s dur=218ms, freq=62Hz, sample=35, buffer_id=14:23
    db 0,0,218,0,47,127,19,2,139,0,47,19  ; n49 t=11.107s dur=218ms, freq=139Hz, sample=47, buffer_id=13:2F
    db 250,0,218,0,35,127,20,3,69,0,35,20  ; n50 t=11.107s dur=218ms, freq=69Hz, sample=35, buffer_id=14:23
    db 0,0,100,0,54,127,5,0,185,0,54,5  ; n51 t=11.357s dur=100ms, freq=185Hz, sample=54, buffer_id=05:36
    db 0,0,100,0,42,127,6,1,92,0,42,5  ; n52 t=11.357s dur=100ms, freq=92Hz, sample=42, buffer_id=05:2A
    db 0,0,218,0,47,127,19,4,147,0,47,19  ; n53 t=11.357s dur=218ms, freq=147Hz, sample=47, buffer_id=13:2F
    db 250,0,218,0,35,127,20,5,73,0,35,20  ; n54 t=11.357s dur=218ms, freq=73Hz, sample=35, buffer_id=14:23
    db 0,0,218,0,54,127,19,2,165,0,54,19  ; n55 t=11.607s dur=218ms, freq=165Hz, sample=54, buffer_id=13:36
    db 250,0,218,0,42,127,20,3,82,0,42,20  ; n56 t=11.607s dur=218ms, freq=82Hz, sample=42, buffer_id=14:2A
    db 0,0,100,0,47,127,5,0,123,0,47,5  ; n57 t=11.857s dur=100ms, freq=123Hz, sample=47, buffer_id=05:2F
    db 0,0,100,0,35,127,6,1,62,0,35,5  ; n58 t=11.857s dur=100ms, freq=62Hz, sample=35, buffer_id=05:23
    db 0,0,218,0,54,127,19,4,185,0,54,19  ; n59 t=11.857s dur=218ms, freq=185Hz, sample=54, buffer_id=13:36
    db 250,0,218,0,42,127,20,5,92,0,42,20  ; n60 t=11.857s dur=218ms, freq=92Hz, sample=42, buffer_id=14:2A
    db 0,0,218,0,47,127,19,2,147,0,47,19  ; n61 t=12.107s dur=218ms, freq=147Hz, sample=47, buffer_id=13:2F
    db 250,0,218,0,35,127,20,3,73,0,35,20  ; n62 t=12.107s dur=218ms, freq=73Hz, sample=35, buffer_id=14:23
    db 0,0,100,0,54,127,5,0,185,0,54,5  ; n63 t=12.357s dur=100ms, freq=185Hz, sample=54, buffer_id=05:36
    db 0,0,100,0,42,127,6,1,92,0,42,5  ; n64 t=12.357s dur=100ms, freq=92Hz, sample=42, buffer_id=05:2A
    db 0,0,218,0,54,127,19,5,185,0,54,19  ; n65 t=12.357s dur=218ms, freq=185Hz, sample=54, buffer_id=13:36
    db 250,0,218,0,42,127,20,4,92,0,42,20  ; n66 t=12.357s dur=218ms, freq=92Hz, sample=42, buffer_id=14:2A
    db 0,0,218,0,59,127,19,2,247,0,59,19  ; n67 t=12.607s dur=218ms, freq=247Hz, sample=59, buffer_id=13:3B
    db 250,0,218,0,47,127,20,3,123,0,47,20  ; n68 t=12.607s dur=218ms, freq=123Hz, sample=47, buffer_id=14:2F
    db 0,0,100,0,50,127,5,0,147,0,50,5  ; n69 t=12.857s dur=100ms, freq=147Hz, sample=50, buffer_id=05:32
    db 0,0,100,0,35,127,6,1,73,0,35,5  ; n70 t=12.857s dur=100ms, freq=73Hz, sample=35, buffer_id=05:23
    db 0,0,218,0,59,127,19,4,220,0,59,19  ; n71 t=12.857s dur=218ms, freq=220Hz, sample=59, buffer_id=13:3B
    db 250,0,218,0,47,127,20,5,110,0,47,20  ; n72 t=12.857s dur=218ms, freq=110Hz, sample=47, buffer_id=14:2F
    db 0,0,218,0,54,127,19,2,185,0,54,19  ; n73 t=13.107s dur=218ms, freq=185Hz, sample=54, buffer_id=13:36
    db 250,0,218,0,42,127,20,3,92,0,42,20  ; n74 t=13.107s dur=218ms, freq=92Hz, sample=42, buffer_id=14:2A
    db 0,0,100,0,54,127,5,0,220,0,54,5  ; n75 t=13.357s dur=100ms, freq=220Hz, sample=54, buffer_id=05:36
    db 0,0,100,0,47,127,6,1,110,0,47,5  ; n76 t=13.357s dur=100ms, freq=110Hz, sample=47, buffer_id=05:2F
    db 0,0,218,0,47,127,19,4,147,0,47,19  ; n77 t=13.357s dur=218ms, freq=147Hz, sample=47, buffer_id=13:2F
    db 250,0,218,0,35,127,20,5,73,0,35,20  ; n78 t=13.357s dur=218ms, freq=73Hz, sample=35, buffer_id=14:23
    db 0,0,218,0,54,127,19,3,185,0,54,19  ; n79 t=13.607s dur=218ms, freq=185Hz, sample=54, buffer_id=13:36
    db 250,0,218,0,42,127,20,2,92,0,42,20  ; n80 t=13.607s dur=218ms, freq=92Hz, sample=42, buffer_id=14:2A
    db 0,0,100,0,50,127,5,0,147,0,50,5  ; n81 t=13.857s dur=100ms, freq=147Hz, sample=50, buffer_id=05:32
    db 0,0,100,0,35,127,6,1,73,0,35,5  ; n82 t=13.857s dur=100ms, freq=73Hz, sample=35, buffer_id=05:23
    db 0,0,232,3,45,127,7,4,110,0,45,7  ; n83 t=13.857s dur=1000ms, freq=110Hz, sample=45, buffer_id=07:2D
    db 0,0,120,0,57,127,7,5,220,0,57,7  ; n84 t=13.857s dur=120ms, freq=220Hz, sample=57, buffer_id=07:39
    db 0,0,212,1,59,127,19,6,220,0,59,19  ; n85 t=13.857s dur=468ms, freq=220Hz, sample=59, buffer_id=13:3B
    db 244,1,212,1,47,127,20,7,110,0,47,20  ; n86 t=13.857s dur=468ms, freq=110Hz, sample=47, buffer_id=14:2F
    db 0,0,100,0,54,127,5,0,220,0,54,5  ; n87 t=14.357s dur=100ms, freq=220Hz, sample=54, buffer_id=05:36
    db 244,1,100,0,47,127,6,1,110,0,47,5  ; n88 t=14.357s dur=100ms, freq=110Hz, sample=47, buffer_id=05:2F
    db 0,0,100,0,47,127,5,0,123,0,47,5  ; n89 t=14.857s dur=100ms, freq=123Hz, sample=47, buffer_id=05:2F
    db 0,0,100,0,35,127,6,1,62,0,35,5  ; n90 t=14.857s dur=100ms, freq=62Hz, sample=35, buffer_id=05:23
    db 0,0,218,0,47,127,19,2,123,0,47,19  ; n91 t=14.857s dur=218ms, freq=123Hz, sample=47, buffer_id=13:2F
    db 250,0,218,0,35,127,20,3,62,0,35,20  ; n92 t=14.857s dur=218ms, freq=62Hz, sample=35, buffer_id=14:23
    db 0,0,100,0,49,127,5,4,139,0,49,5  ; n93 t=15.107s dur=100ms, freq=139Hz, sample=49, buffer_id=05:31
    db 250,0,100,0,35,127,6,5,69,0,35,5  ; n94 t=15.107s dur=100ms, freq=69Hz, sample=35, buffer_id=05:23
    db 0,0,100,0,50,127,5,0,147,0,50,5  ; n95 t=15.357s dur=100ms, freq=147Hz, sample=50, buffer_id=05:32
    db 0,0,100,0,35,127,6,2,73,0,35,5  ; n96 t=15.357s dur=100ms, freq=73Hz, sample=35, buffer_id=05:23
    db 0,0,218,0,54,127,19,1,185,0,54,19  ; n97 t=15.357s dur=218ms, freq=185Hz, sample=54, buffer_id=13:36
    db 250,0,218,0,42,127,20,3,92,0,42,20  ; n98 t=15.357s dur=218ms, freq=92Hz, sample=42, buffer_id=14:2A
    db 0,0,100,0,50,127,5,4,165,0,50,5  ; n99 t=15.607s dur=100ms, freq=165Hz, sample=50, buffer_id=05:32
    db 250,0,100,0,42,127,6,5,82,0,42,5  ; n100 t=15.607s dur=100ms, freq=82Hz, sample=42, buffer_id=05:2A
    db 0,0,100,0,54,127,5,0,185,0,54,5  ; n101 t=15.857s dur=100ms, freq=185Hz, sample=54, buffer_id=05:36
    db 0,0,100,0,42,127,6,1,92,0,42,5  ; n102 t=15.857s dur=100ms, freq=92Hz, sample=42, buffer_id=05:2A
    db 0,0,218,0,47,127,19,2,123,0,47,19  ; n103 t=15.857s dur=218ms, freq=123Hz, sample=47, buffer_id=13:2F
    db 250,0,218,0,35,127,20,3,62,0,35,20  ; n104 t=15.857s dur=218ms, freq=62Hz, sample=35, buffer_id=14:23
    db 0,0,100,0,50,127,5,5,147,0,50,5  ; n105 t=16.107s dur=100ms, freq=147Hz, sample=50, buffer_id=05:32
    db 250,0,100,0,35,127,6,4,73,0,35,5  ; n106 t=16.107s dur=100ms, freq=73Hz, sample=35, buffer_id=05:23
    db 0,0,100,0,54,127,5,1,185,0,54,5  ; n107 t=16.357s dur=100ms, freq=185Hz, sample=54, buffer_id=05:36
    db 0,0,100,0,42,127,6,0,92,0,42,5  ; n108 t=16.357s dur=100ms, freq=92Hz, sample=42, buffer_id=05:2A
    db 0,0,218,0,54,127,19,2,185,0,54,19  ; n109 t=16.357s dur=218ms, freq=185Hz, sample=54, buffer_id=13:36
    db 244,1,218,0,42,127,20,3,92,0,42,20  ; n110 t=16.357s dur=218ms, freq=92Hz, sample=42, buffer_id=14:2A
    db 0,0,100,0,54,127,5,0,175,0,54,5  ; n111 t=16.857s dur=100ms, freq=175Hz, sample=54, buffer_id=05:36
    db 0,0,100,0,42,127,6,1,87,0,42,5  ; n112 t=16.857s dur=100ms, freq=87Hz, sample=42, buffer_id=05:2A
    db 0,0,218,0,47,127,19,2,123,0,47,19  ; n113 t=16.857s dur=218ms, freq=123Hz, sample=47, buffer_id=13:2F
    db 250,0,218,0,35,127,20,3,62,0,35,20  ; n114 t=16.857s dur=218ms, freq=62Hz, sample=35, buffer_id=14:23
    db 0,0,100,0,49,127,5,4,139,0,49,5  ; n115 t=17.107s dur=100ms, freq=139Hz, sample=49, buffer_id=05:31
    db 250,0,100,0,35,127,6,5,69,0,35,5  ; n116 t=17.107s dur=100ms, freq=69Hz, sample=35, buffer_id=05:23
    db 0,0,100,0,54,127,5,1,175,0,54,5  ; n117 t=17.357s dur=100ms, freq=175Hz, sample=54, buffer_id=05:36
    db 0,0,100,0,42,127,6,0,87,0,42,5  ; n118 t=17.357s dur=100ms, freq=87Hz, sample=42, buffer_id=05:2A
    db 0,0,218,0,54,127,19,2,185,0,54,19  ; n119 t=17.357s dur=218ms, freq=185Hz, sample=54, buffer_id=13:36
    db 244,1,218,0,42,127,20,3,92,0,42,20  ; n120 t=17.357s dur=218ms, freq=92Hz, sample=42, buffer_id=14:2A
    db 0,0,100,0,50,127,5,0,165,0,50,5  ; n121 t=17.857s dur=100ms, freq=165Hz, sample=50, buffer_id=05:32
    db 0,0,100,0,42,127,6,1,82,0,42,5  ; n122 t=17.857s dur=100ms, freq=82Hz, sample=42, buffer_id=05:2A
    db 0,0,218,0,47,127,19,2,123,0,47,19  ; n123 t=17.857s dur=218ms, freq=123Hz, sample=47, buffer_id=13:2F
    db 250,0,218,0,35,127,20,3,62,0,35,20  ; n124 t=17.857s dur=218ms, freq=62Hz, sample=35, buffer_id=14:23
    db 0,0,100,0,47,127,5,4,131,0,47,5  ; n125 t=18.107s dur=100ms, freq=131Hz, sample=47, buffer_id=05:2F
    db 250,0,100,0,35,127,6,6,65,0,35,5  ; n126 t=18.107s dur=100ms, freq=65Hz, sample=35, buffer_id=05:23
    db 0,0,100,0,50,127,5,1,165,0,50,5  ; n127 t=18.357s dur=100ms, freq=165Hz, sample=50, buffer_id=05:32
    db 0,0,100,0,42,127,6,0,82,0,42,5  ; n128 t=18.357s dur=100ms, freq=82Hz, sample=42, buffer_id=05:2A
    db 0,0,218,0,54,127,19,2,185,0,54,19  ; n129 t=18.357s dur=218ms, freq=185Hz, sample=54, buffer_id=13:36
    db 244,1,218,0,42,127,20,3,92,0,42,20  ; n130 t=18.357s dur=218ms, freq=92Hz, sample=42, buffer_id=14:2A
    db 0,0,100,0,47,127,5,0,123,0,47,5  ; n131 t=18.857s dur=100ms, freq=123Hz, sample=47, buffer_id=05:2F
    db 0,0,100,0,35,127,6,1,62,0,35,5  ; n132 t=18.857s dur=100ms, freq=62Hz, sample=35, buffer_id=05:23
    db 0,0,218,0,47,127,19,2,123,0,47,19  ; n133 t=18.857s dur=218ms, freq=123Hz, sample=47, buffer_id=13:2F
    db 250,0,218,0,35,127,20,3,62,0,35,20  ; n134 t=18.857s dur=218ms, freq=62Hz, sample=35, buffer_id=14:23
    db 0,0,100,0,49,127,5,4,139,0,49,5  ; n135 t=19.107s dur=100ms, freq=139Hz, sample=49, buffer_id=05:31
    db 250,0,100,0,35,127,6,7,69,0,35,5  ; n136 t=19.107s dur=100ms, freq=69Hz, sample=35, buffer_id=05:23
    db 0,0,100,0,50,127,5,0,147,0,50,5  ; n137 t=19.357s dur=100ms, freq=147Hz, sample=50, buffer_id=05:32
    db 0,0,100,0,35,127,6,2,73,0,35,5  ; n138 t=19.357s dur=100ms, freq=73Hz, sample=35, buffer_id=05:23
    db 0,0,218,0,54,127,19,1,185,0,54,19  ; n139 t=19.357s dur=218ms, freq=185Hz, sample=54, buffer_id=13:36
    db 250,0,218,0,42,127,20,3,92,0,42,20  ; n140 t=19.357s dur=218ms, freq=92Hz, sample=42, buffer_id=14:2A
    db 0,0,100,0,50,127,5,4,165,0,50,5  ; n141 t=19.607s dur=100ms, freq=165Hz, sample=50, buffer_id=05:32
    db 250,0,100,0,42,127,6,5,82,0,42,5  ; n142 t=19.607s dur=100ms, freq=82Hz, sample=42, buffer_id=05:2A
    db 0,0,100,0,54,127,5,0,185,0,54,5  ; n143 t=19.857s dur=100ms, freq=185Hz, sample=54, buffer_id=05:36
    db 0,0,100,0,42,127,6,1,92,0,42,5  ; n144 t=19.857s dur=100ms, freq=92Hz, sample=42, buffer_id=05:2A
    db 0,0,218,0,47,127,19,2,123,0,47,19  ; n145 t=19.857s dur=218ms, freq=123Hz, sample=47, buffer_id=13:2F
    db 250,0,218,0,35,127,20,3,62,0,35,20  ; n146 t=19.857s dur=218ms, freq=62Hz, sample=35, buffer_id=14:23
    db 0,0,100,0,50,127,5,5,147,0,50,5  ; n147 t=20.107s dur=100ms, freq=147Hz, sample=50, buffer_id=05:32
    db 250,0,100,0,35,127,6,4,73,0,35,5  ; n148 t=20.107s dur=100ms, freq=73Hz, sample=35, buffer_id=05:23
    db 0,0,100,0,54,127,5,1,185,0,54,5  ; n149 t=20.357s dur=100ms, freq=185Hz, sample=54, buffer_id=05:36
    db 0,0,100,0,42,127,6,0,92,0,42,5  ; n150 t=20.357s dur=100ms, freq=92Hz, sample=42, buffer_id=05:2A
    db 0,0,218,0,54,127,19,2,185,0,54,19  ; n151 t=20.357s dur=218ms, freq=185Hz, sample=54, buffer_id=13:36
    db 250,0,218,0,42,127,20,3,92,0,42,20  ; n152 t=20.357s dur=218ms, freq=92Hz, sample=42, buffer_id=14:2A
    db 0,0,100,0,61,127,5,4,247,0,61,5  ; n153 t=20.607s dur=100ms, freq=247Hz, sample=61, buffer_id=05:3D
    db 250,0,100,0,47,127,6,5,123,0,47,5  ; n154 t=20.607s dur=100ms, freq=123Hz, sample=47, buffer_id=05:2F
    db 0,0,100,0,54,127,5,0,220,0,54,5  ; n155 t=20.857s dur=100ms, freq=220Hz, sample=54, buffer_id=05:36
    db 0,0,100,0,47,127,6,1,110,0,47,5  ; n156 t=20.857s dur=100ms, freq=110Hz, sample=47, buffer_id=05:2F
    db 0,0,218,0,47,127,19,2,147,0,47,19  ; n157 t=20.857s dur=218ms, freq=147Hz, sample=47, buffer_id=13:2F
    db 250,0,218,0,35,127,20,3,73,0,35,20  ; n158 t=20.857s dur=218ms, freq=73Hz, sample=35, buffer_id=14:23
    db 0,0,100,0,54,127,5,4,185,0,54,5  ; n159 t=21.107s dur=100ms, freq=185Hz, sample=54, buffer_id=05:36
    db 250,0,100,0,42,127,6,5,92,0,42,5  ; n160 t=21.107s dur=100ms, freq=92Hz, sample=42, buffer_id=05:2A
    db 0,0,100,0,50,127,5,0,147,0,50,5  ; n161 t=21.357s dur=100ms, freq=147Hz, sample=50, buffer_id=05:32
    db 0,0,100,0,35,127,6,1,73,0,35,5  ; n162 t=21.357s dur=100ms, freq=73Hz, sample=35, buffer_id=05:23
    db 0,0,218,0,59,127,19,2,220,0,59,19  ; n163 t=21.357s dur=218ms, freq=220Hz, sample=59, buffer_id=13:3B
    db 250,0,218,0,47,127,20,3,110,0,47,20  ; n164 t=21.357s dur=218ms, freq=110Hz, sample=47, buffer_id=14:2F
    db 0,0,100,0,54,127,5,5,185,0,54,5  ; n165 t=21.607s dur=100ms, freq=185Hz, sample=54, buffer_id=05:36
    db 250,0,100,0,42,127,6,4,92,0,42,5  ; n166 t=21.607s dur=100ms, freq=92Hz, sample=42, buffer_id=05:2A
    db 0,0,122,1,54,127,5,0,220,0,54,5  ; n167 t=21.857s dur=378ms, freq=220Hz, sample=54, buffer_id=05:36
    db 0,0,212,1,47,127,6,1,110,0,47,5  ; n168 t=21.857s dur=468ms, freq=110Hz, sample=47, buffer_id=05:2F
    db 0,0,232,3,45,127,7,2,110,0,45,7  ; n169 t=21.857s dur=1000ms, freq=110Hz, sample=45, buffer_id=07:2D
    db 0,0,120,0,57,127,7,3,220,0,57,7  ; n170 t=21.857s dur=120ms, freq=220Hz, sample=57, buffer_id=07:39
    db 0,0,218,0,47,127,19,6,147,0,47,19  ; n171 t=21.857s dur=218ms, freq=147Hz, sample=47, buffer_id=13:2F
    db 244,1,218,0,35,127,20,7,73,0,35,20  ; n172 t=21.857s dur=218ms, freq=73Hz, sample=35, buffer_id=14:23
    db 0,0,218,0,59,127,19,3,220,0,59,19  ; n173 t=22.357s dur=218ms, freq=220Hz, sample=59, buffer_id=13:3B
    db 244,1,218,0,47,127,20,4,110,0,47,20  ; n174 t=22.357s dur=218ms, freq=110Hz, sample=47, buffer_id=14:2F
    db 0,0,100,0,54,127,5,1,185,0,54,5  ; n175 t=22.857s dur=100ms, freq=185Hz, sample=54, buffer_id=05:36
    db 0,0,100,0,42,127,6,0,92,0,42,5  ; n176 t=22.857s dur=100ms, freq=92Hz, sample=42, buffer_id=05:2A
    db 0,0,218,0,54,127,19,3,185,0,54,19  ; n177 t=22.857s dur=218ms, freq=185Hz, sample=54, buffer_id=13:36
    db 250,0,218,0,42,127,20,4,92,0,42,20  ; n178 t=22.857s dur=218ms, freq=92Hz, sample=42, buffer_id=14:2A
    db 0,0,218,0,54,127,19,2,208,0,54,19  ; n179 t=23.107s dur=218ms, freq=208Hz, sample=54, buffer_id=13:36
    db 250,0,218,0,42,127,20,5,104,0,42,20  ; n180 t=23.107s dur=218ms, freq=104Hz, sample=42, buffer_id=14:2A
    db 0,0,100,0,61,127,5,0,21,1,61,5  ; n181 t=23.357s dur=100ms, freq=277Hz, sample=61, buffer_id=05:3D
    db 0,0,100,0,49,127,6,1,139,0,49,5  ; n182 t=23.357s dur=100ms, freq=139Hz, sample=49, buffer_id=05:31
    db 0,0,218,0,59,127,19,3,233,0,59,19  ; n183 t=23.357s dur=218ms, freq=233Hz, sample=59, buffer_id=13:3B
    db 250,0,218,0,47,127,20,4,117,0,47,20  ; n184 t=23.357s dur=218ms, freq=117Hz, sample=47, buffer_id=14:2F
    db 0,0,218,0,59,127,19,2,247,0,59,19  ; n185 t=23.607s dur=218ms, freq=247Hz, sample=59, buffer_id=13:3B
    db 250,0,218,0,47,127,20,5,123,0,47,20  ; n186 t=23.607s dur=218ms, freq=123Hz, sample=47, buffer_id=14:2F
    db 0,0,100,0,54,127,5,0,185,0,54,5  ; n187 t=23.857s dur=100ms, freq=185Hz, sample=54, buffer_id=05:36
    db 0,0,100,0,42,127,6,1,92,0,42,5  ; n188 t=23.857s dur=100ms, freq=92Hz, sample=42, buffer_id=05:2A
    db 0,0,218,0,62,127,19,3,21,1,62,19  ; n189 t=23.857s dur=218ms, freq=277Hz, sample=62, buffer_id=13:3E
    db 250,0,218,0,50,127,20,4,139,0,50,20  ; n190 t=23.857s dur=218ms, freq=139Hz, sample=50, buffer_id=14:32
    db 0,0,218,0,59,127,19,5,233,0,59,19  ; n191 t=24.107s dur=218ms, freq=233Hz, sample=59, buffer_id=13:3B
    db 250,0,218,0,47,127,20,2,117,0,47,20  ; n192 t=24.107s dur=218ms, freq=117Hz, sample=47, buffer_id=14:2F
    db 0,0,100,0,61,127,5,0,233,0,61,5  ; n193 t=24.357s dur=100ms, freq=233Hz, sample=61, buffer_id=05:3D
    db 0,0,100,0,47,127,6,1,117,0,47,5  ; n194 t=24.357s dur=100ms, freq=117Hz, sample=47, buffer_id=05:2F
    db 0,0,218,0,62,127,19,4,21,1,62,19  ; n195 t=24.357s dur=218ms, freq=277Hz, sample=62, buffer_id=13:3E
    db 244,1,218,0,50,127,20,3,139,0,50,20  ; n196 t=24.357s dur=218ms, freq=139Hz, sample=50, buffer_id=14:32
    db 0,0,100,0,50,127,5,0,147,0,50,5  ; n197 t=24.857s dur=100ms, freq=147Hz, sample=50, buffer_id=05:32
    db 0,0,100,0,35,127,6,1,73,0,35,5  ; n198 t=24.857s dur=100ms, freq=73Hz, sample=35, buffer_id=05:23
    db 0,0,218,0,62,127,19,2,38,1,62,19  ; n199 t=24.857s dur=218ms, freq=294Hz, sample=62, buffer_id=13:3E
    db 250,0,218,0,50,127,20,4,147,0,50,20  ; n200 t=24.857s dur=218ms, freq=147Hz, sample=50, buffer_id=14:32
    db 0,0,218,0,59,127,19,3,233,0,59,19  ; n201 t=25.107s dur=218ms, freq=233Hz, sample=59, buffer_id=13:3B
    db 250,0,218,0,47,127,20,5,117,0,47,20  ; n202 t=25.107s dur=218ms, freq=117Hz, sample=47, buffer_id=14:2F
    db 0,0,100,0,61,127,5,0,233,0,61,5  ; n203 t=25.357s dur=100ms, freq=233Hz, sample=61, buffer_id=05:3D
    db 0,0,100,0,47,127,6,1,117,0,47,5  ; n204 t=25.357s dur=100ms, freq=117Hz, sample=47, buffer_id=05:2F
    db 0,0,212,1,62,127,19,4,38,1,62,19  ; n205 t=25.357s dur=468ms, freq=294Hz, sample=62, buffer_id=13:3E
    db 244,1,212,1,50,127,20,2,147,0,50,20  ; n206 t=25.357s dur=468ms, freq=147Hz, sample=50, buffer_id=14:32
    db 0,0,100,0,54,127,5,0,185,0,54,5  ; n207 t=25.857s dur=100ms, freq=185Hz, sample=54, buffer_id=05:36
    db 0,0,100,0,42,127,6,1,92,0,42,5  ; n208 t=25.857s dur=100ms, freq=92Hz, sample=42, buffer_id=05:2A
    db 0,0,218,0,62,127,19,3,21,1,62,19  ; n209 t=25.857s dur=218ms, freq=277Hz, sample=62, buffer_id=13:3E
    db 250,0,218,0,50,127,20,5,139,0,50,20  ; n210 t=25.857s dur=218ms, freq=139Hz, sample=50, buffer_id=14:32
    db 0,0,218,0,59,127,19,2,233,0,59,19  ; n211 t=26.107s dur=218ms, freq=233Hz, sample=59, buffer_id=13:3B
    db 250,0,218,0,47,127,20,4,117,0,47,20  ; n212 t=26.107s dur=218ms, freq=117Hz, sample=47, buffer_id=14:2F
    db 0,0,100,0,61,127,5,0,233,0,61,5  ; n213 t=26.357s dur=100ms, freq=233Hz, sample=61, buffer_id=05:3D
    db 0,0,100,0,47,127,6,1,117,0,47,5  ; n214 t=26.357s dur=100ms, freq=117Hz, sample=47, buffer_id=05:2F
    db 0,0,212,1,62,127,19,5,21,1,62,19  ; n215 t=26.357s dur=468ms, freq=277Hz, sample=62, buffer_id=13:3E
    db 244,1,212,1,50,127,20,3,139,0,50,20  ; n216 t=26.357s dur=468ms, freq=139Hz, sample=50, buffer_id=14:32
    db 0,0,100,0,54,127,5,0,185,0,54,5  ; n217 t=26.857s dur=100ms, freq=185Hz, sample=54, buffer_id=05:36
    db 0,0,100,0,42,127,6,1,92,0,42,5  ; n218 t=26.857s dur=100ms, freq=92Hz, sample=42, buffer_id=05:2A
    db 0,0,218,0,54,127,19,2,185,0,54,19  ; n219 t=26.857s dur=218ms, freq=185Hz, sample=54, buffer_id=13:36
    db 250,0,218,0,42,127,20,4,92,0,42,20  ; n220 t=26.857s dur=218ms, freq=92Hz, sample=42, buffer_id=14:2A
    db 0,0,218,0,54,127,19,3,208,0,54,19  ; n221 t=27.107s dur=218ms, freq=208Hz, sample=54, buffer_id=13:36
    db 250,0,218,0,42,127,20,5,104,0,42,20  ; n222 t=27.107s dur=218ms, freq=104Hz, sample=42, buffer_id=14:2A
    db 0,0,100,0,61,127,5,0,21,1,61,5  ; n223 t=27.357s dur=100ms, freq=277Hz, sample=61, buffer_id=05:3D
    db 0,0,100,0,49,127,6,1,139,0,49,5  ; n224 t=27.357s dur=100ms, freq=139Hz, sample=49, buffer_id=05:31
    db 0,0,218,0,59,127,19,2,233,0,59,19  ; n225 t=27.357s dur=218ms, freq=233Hz, sample=59, buffer_id=13:3B
    db 250,0,218,0,47,127,20,4,117,0,47,20  ; n226 t=27.357s dur=218ms, freq=117Hz, sample=47, buffer_id=14:2F
    db 0,0,218,0,59,127,19,3,247,0,59,19  ; n227 t=27.607s dur=218ms, freq=247Hz, sample=59, buffer_id=13:3B
    db 250,0,218,0,47,127,20,5,123,0,47,20  ; n228 t=27.607s dur=218ms, freq=123Hz, sample=47, buffer_id=14:2F
    db 0,0,100,0,54,127,5,0,185,0,54,5  ; n229 t=27.857s dur=100ms, freq=185Hz, sample=54, buffer_id=05:36
    db 0,0,100,0,42,127,6,1,92,0,42,5  ; n230 t=27.857s dur=100ms, freq=92Hz, sample=42, buffer_id=05:2A
    db 0,0,218,0,62,127,19,2,21,1,62,19  ; n231 t=27.857s dur=218ms, freq=277Hz, sample=62, buffer_id=13:3E
    db 250,0,218,0,50,127,20,4,139,0,50,20  ; n232 t=27.857s dur=218ms, freq=139Hz, sample=50, buffer_id=14:32
    db 0,0,218,0,59,127,19,5,233,0,59,19  ; n233 t=28.107s dur=218ms, freq=233Hz, sample=59, buffer_id=13:3B
    db 250,0,218,0,47,127,20,3,117,0,47,20  ; n234 t=28.107s dur=218ms, freq=117Hz, sample=47, buffer_id=14:2F
    db 0,0,100,0,61,127,5,0,233,0,61,5  ; n235 t=28.357s dur=100ms, freq=233Hz, sample=61, buffer_id=05:3D
    db 0,0,100,0,47,127,6,1,117,0,47,5  ; n236 t=28.357s dur=100ms, freq=117Hz, sample=47, buffer_id=05:2F
    db 0,0,218,0,62,127,19,4,21,1,62,19  ; n237 t=28.357s dur=218ms, freq=277Hz, sample=62, buffer_id=13:3E
    db 244,1,218,0,50,127,20,2,139,0,50,20  ; n238 t=28.357s dur=218ms, freq=139Hz, sample=50, buffer_id=14:32
    db 0,0,100,0,50,127,5,0,147,0,50,5  ; n239 t=28.857s dur=100ms, freq=147Hz, sample=50, buffer_id=05:32
    db 0,0,100,0,35,127,6,1,73,0,35,5  ; n240 t=28.857s dur=100ms, freq=73Hz, sample=35, buffer_id=05:23
    db 0,0,218,0,62,127,19,2,38,1,62,19  ; n241 t=28.857s dur=218ms, freq=294Hz, sample=62, buffer_id=13:3E
    db 250,0,218,0,50,127,20,3,147,0,50,20  ; n242 t=28.857s dur=218ms, freq=147Hz, sample=50, buffer_id=14:32
    db 0,0,218,0,59,127,19,4,233,0,59,19  ; n243 t=29.107s dur=218ms, freq=233Hz, sample=59, buffer_id=13:3B
    db 250,0,218,0,47,127,20,5,117,0,47,20  ; n244 t=29.107s dur=218ms, freq=117Hz, sample=47, buffer_id=14:2F
    db 0,0,100,0,61,127,5,0,233,0,61,5  ; n245 t=29.357s dur=100ms, freq=233Hz, sample=61, buffer_id=05:3D
    db 0,0,100,0,47,127,6,1,117,0,47,5  ; n246 t=29.357s dur=100ms, freq=117Hz, sample=47, buffer_id=05:2F
    db 0,0,212,1,62,127,19,3,38,1,62,19  ; n247 t=29.357s dur=468ms, freq=294Hz, sample=62, buffer_id=13:3E
    db 244,1,212,1,50,127,20,2,147,0,50,20  ; n248 t=29.357s dur=468ms, freq=147Hz, sample=50, buffer_id=14:32
    db 0,0,100,0,54,127,5,0,185,0,54,5  ; n249 t=29.857s dur=100ms, freq=185Hz, sample=54, buffer_id=05:36
    db 0,0,100,0,42,127,6,1,92,0,42,5  ; n250 t=29.857s dur=100ms, freq=92Hz, sample=42, buffer_id=05:2A
    db 0,0,25,3,45,127,7,4,139,0,45,7  ; n251 t=29.857s dur=793ms, freq=139Hz, sample=45, buffer_id=07:2D
    db 0,0,127,0,61,127,7,5,21,1,61,7  ; n252 t=29.857s dur=127ms, freq=277Hz, sample=61, buffer_id=07:3D
    db 0,0,212,1,62,127,19,6,21,1,62,19  ; n253 t=29.857s dur=468ms, freq=277Hz, sample=62, buffer_id=13:3E
    db 244,1,212,1,50,127,20,7,139,0,50,20  ; n254 t=29.857s dur=468ms, freq=139Hz, sample=50, buffer_id=14:32
    db 0,0,100,0,61,127,5,0,233,0,61,5  ; n255 t=30.357s dur=100ms, freq=233Hz, sample=61, buffer_id=05:3D
    db 244,1,100,0,47,127,6,1,117,0,47,5  ; n256 t=30.357s dur=100ms, freq=117Hz, sample=47, buffer_id=05:2F
    db 0,0,100,0,54,127,5,0,185,0,54,5  ; n257 t=30.857s dur=100ms, freq=185Hz, sample=54, buffer_id=05:36
    db 0,0,100,0,42,127,6,1,92,0,42,5  ; n258 t=30.857s dur=100ms, freq=92Hz, sample=42, buffer_id=05:2A
    db 0,0,212,1,54,127,19,2,185,0,54,19  ; n259 t=30.857s dur=468ms, freq=185Hz, sample=54, buffer_id=13:36
    db 250,0,212,1,42,127,20,3,92,0,42,20  ; n260 t=30.857s dur=468ms, freq=92Hz, sample=42, buffer_id=14:2A
    db 0,0,100,0,54,127,5,4,208,0,54,5  ; n261 t=31.107s dur=100ms, freq=208Hz, sample=54, buffer_id=05:36
    db 250,0,100,0,42,127,6,5,104,0,42,5  ; n262 t=31.107s dur=100ms, freq=104Hz, sample=42, buffer_id=05:2A
    db 0,0,100,0,61,127,5,0,233,0,61,5  ; n263 t=31.357s dur=100ms, freq=233Hz, sample=61, buffer_id=05:3D
    db 0,0,100,0,47,127,6,1,117,0,47,5  ; n264 t=31.357s dur=100ms, freq=117Hz, sample=47, buffer_id=05:2F
    db 0,0,212,1,62,127,19,7,21,1,62,19  ; n265 t=31.357s dur=468ms, freq=277Hz, sample=62, buffer_id=13:3E
    db 250,0,212,1,50,127,20,6,139,0,50,20  ; n266 t=31.357s dur=468ms, freq=139Hz, sample=50, buffer_id=14:32
    db 0,0,100,0,61,127,5,2,247,0,61,5  ; n267 t=31.607s dur=100ms, freq=247Hz, sample=61, buffer_id=05:3D
    db 250,0,100,0,47,127,6,3,123,0,47,5  ; n268 t=31.607s dur=100ms, freq=123Hz, sample=47, buffer_id=05:2F
    db 0,0,100,0,61,127,5,1,21,1,61,5  ; n269 t=31.857s dur=100ms, freq=277Hz, sample=61, buffer_id=05:3D
    db 0,0,100,0,49,127,6,0,139,0,49,5  ; n270 t=31.857s dur=100ms, freq=139Hz, sample=49, buffer_id=05:31
    db 0,0,212,1,54,127,19,4,185,0,54,19  ; n271 t=31.857s dur=468ms, freq=185Hz, sample=54, buffer_id=13:36
    db 250,0,212,1,42,127,20,5,92,0,42,20  ; n272 t=31.857s dur=468ms, freq=92Hz, sample=42, buffer_id=14:2A
    db 0,0,100,0,61,127,5,3,233,0,61,5  ; n273 t=32.107s dur=100ms, freq=233Hz, sample=61, buffer_id=05:3D
    db 250,0,100,0,47,127,6,2,117,0,47,5  ; n274 t=32.107s dur=100ms, freq=117Hz, sample=47, buffer_id=05:2F
    db 0,0,100,0,61,127,5,0,21,1,61,5  ; n275 t=32.357s dur=100ms, freq=277Hz, sample=61, buffer_id=05:3D
    db 0,0,100,0,49,127,6,1,139,0,49,5  ; n276 t=32.357s dur=100ms, freq=139Hz, sample=49, buffer_id=05:31
    db 0,0,212,1,59,127,19,6,233,0,59,19  ; n277 t=32.357s dur=468ms, freq=233Hz, sample=59, buffer_id=13:3B
    db 244,1,212,1,47,127,20,7,117,0,47,20  ; n278 t=32.357s dur=468ms, freq=117Hz, sample=47, buffer_id=14:2F
    db 0,0,100,0,62,127,5,0,38,1,62,5  ; n279 t=32.857s dur=100ms, freq=294Hz, sample=62, buffer_id=05:3E
    db 0,0,100,0,50,127,6,1,147,0,50,5  ; n280 t=32.857s dur=100ms, freq=147Hz, sample=50, buffer_id=05:32
    db 0,0,138,1,47,127,19,2,147,0,47,19  ; n281 t=32.857s dur=394ms, freq=147Hz, sample=47, buffer_id=13:2F
    db 250,0,138,1,35,127,20,3,73,0,35,20  ; n282 t=32.857s dur=394ms, freq=73Hz, sample=35, buffer_id=14:23
    db 0,0,100,0,61,127,5,4,233,0,61,5  ; n283 t=33.107s dur=100ms, freq=233Hz, sample=61, buffer_id=05:3D
    db 250,0,100,0,47,127,6,5,117,0,47,5  ; n284 t=33.107s dur=100ms, freq=117Hz, sample=47, buffer_id=05:2F
    db 0,0,100,0,62,127,5,1,38,1,62,5  ; n285 t=33.357s dur=100ms, freq=294Hz, sample=62, buffer_id=05:3E
    db 0,0,100,0,50,127,6,0,147,0,50,5  ; n286 t=33.357s dur=100ms, freq=147Hz, sample=50, buffer_id=05:32
    db 0,0,212,1,59,127,19,7,233,0,59,19  ; n287 t=33.357s dur=468ms, freq=233Hz, sample=59, buffer_id=13:3B
    db 244,1,212,1,47,127,20,6,117,0,47,20  ; n288 t=33.357s dur=468ms, freq=117Hz, sample=47, buffer_id=14:2F
    db 0,0,100,0,61,127,5,0,21,1,61,5  ; n289 t=33.857s dur=100ms, freq=277Hz, sample=61, buffer_id=05:3D
    db 0,0,100,0,49,127,6,1,139,0,49,5  ; n290 t=33.857s dur=100ms, freq=139Hz, sample=49, buffer_id=05:31
    db 0,0,212,1,54,127,19,2,185,0,54,19  ; n291 t=33.857s dur=468ms, freq=185Hz, sample=54, buffer_id=13:36
    db 250,0,212,1,42,127,20,3,92,0,42,20  ; n292 t=33.857s dur=468ms, freq=92Hz, sample=42, buffer_id=14:2A
    db 0,0,100,0,61,127,5,5,233,0,61,5  ; n293 t=34.107s dur=100ms, freq=233Hz, sample=61, buffer_id=05:3D
    db 250,0,100,0,47,127,6,4,117,0,47,5  ; n294 t=34.107s dur=100ms, freq=117Hz, sample=47, buffer_id=05:2F
    db 0,0,100,0,61,127,5,1,21,1,61,5  ; n295 t=34.357s dur=100ms, freq=277Hz, sample=61, buffer_id=05:3D
    db 0,0,100,0,49,127,6,0,139,0,49,5  ; n296 t=34.357s dur=100ms, freq=139Hz, sample=49, buffer_id=05:31
    db 0,0,212,1,59,127,19,6,233,0,59,19  ; n297 t=34.357s dur=468ms, freq=233Hz, sample=59, buffer_id=13:3B
    db 244,1,212,1,47,127,20,7,117,0,47,20  ; n298 t=34.357s dur=468ms, freq=117Hz, sample=47, buffer_id=14:2F
    db 0,0,100,0,54,127,5,0,185,0,54,5  ; n299 t=34.857s dur=100ms, freq=185Hz, sample=54, buffer_id=05:36
    db 0,0,100,0,42,127,6,1,92,0,42,5  ; n300 t=34.857s dur=100ms, freq=92Hz, sample=42, buffer_id=05:2A
    db 0,0,212,1,54,127,19,3,185,0,54,19  ; n301 t=34.857s dur=468ms, freq=185Hz, sample=54, buffer_id=13:36
    db 250,0,212,1,42,127,20,2,92,0,42,20  ; n302 t=34.857s dur=468ms, freq=92Hz, sample=42, buffer_id=14:2A
    db 0,0,100,0,54,127,5,4,208,0,54,5  ; n303 t=35.107s dur=100ms, freq=208Hz, sample=54, buffer_id=05:36
    db 250,0,100,0,42,127,6,5,104,0,42,5  ; n304 t=35.107s dur=100ms, freq=104Hz, sample=42, buffer_id=05:2A
    db 0,0,100,0,61,127,5,0,233,0,61,5  ; n305 t=35.357s dur=100ms, freq=233Hz, sample=61, buffer_id=05:3D
    db 0,0,100,0,47,127,6,1,117,0,47,5  ; n306 t=35.357s dur=100ms, freq=117Hz, sample=47, buffer_id=05:2F
    db 0,0,212,1,62,127,19,6,21,1,62,19  ; n307 t=35.357s dur=468ms, freq=277Hz, sample=62, buffer_id=13:3E
    db 250,0,212,1,50,127,20,7,139,0,50,20  ; n308 t=35.357s dur=468ms, freq=139Hz, sample=50, buffer_id=14:32
    db 0,0,100,0,61,127,5,2,247,0,61,5  ; n309 t=35.607s dur=100ms, freq=247Hz, sample=61, buffer_id=05:3D
    db 250,0,100,0,47,127,6,3,123,0,47,5  ; n310 t=35.607s dur=100ms, freq=123Hz, sample=47, buffer_id=05:2F
    db 0,0,100,0,61,127,5,1,21,1,61,5  ; n311 t=35.857s dur=100ms, freq=277Hz, sample=61, buffer_id=05:3D
    db 0,0,100,0,49,127,6,0,139,0,49,5  ; n312 t=35.857s dur=100ms, freq=139Hz, sample=49, buffer_id=05:31
    db 0,0,212,1,54,127,19,4,185,0,54,19  ; n313 t=35.857s dur=468ms, freq=185Hz, sample=54, buffer_id=13:36
    db 250,0,212,1,42,127,20,5,92,0,42,20  ; n314 t=35.857s dur=468ms, freq=92Hz, sample=42, buffer_id=14:2A
    db 0,0,100,0,61,127,5,3,233,0,61,5  ; n315 t=36.107s dur=100ms, freq=233Hz, sample=61, buffer_id=05:3D
    db 250,0,100,0,47,127,6,2,117,0,47,5  ; n316 t=36.107s dur=100ms, freq=117Hz, sample=47, buffer_id=05:2F
    db 0,0,100,0,61,127,5,0,21,1,61,5  ; n317 t=36.357s dur=100ms, freq=277Hz, sample=61, buffer_id=05:3D
    db 0,0,100,0,49,127,6,1,139,0,49,5  ; n318 t=36.357s dur=100ms, freq=139Hz, sample=49, buffer_id=05:31
    db 0,0,212,1,59,127,19,6,233,0,59,19  ; n319 t=36.357s dur=468ms, freq=233Hz, sample=59, buffer_id=13:3B
    db 244,1,212,1,47,127,20,7,117,0,47,20  ; n320 t=36.357s dur=468ms, freq=117Hz, sample=47, buffer_id=14:2F
    db 0,0,100,0,62,127,5,0,38,1,62,5  ; n321 t=36.857s dur=100ms, freq=294Hz, sample=62, buffer_id=05:3E
    db 0,0,100,0,50,127,6,1,147,0,50,5  ; n322 t=36.857s dur=100ms, freq=147Hz, sample=50, buffer_id=05:32
    db 0,0,138,1,47,127,19,2,147,0,47,19  ; n323 t=36.857s dur=394ms, freq=147Hz, sample=47, buffer_id=13:2F
    db 250,0,138,1,35,127,20,3,73,0,35,20  ; n324 t=36.857s dur=394ms, freq=73Hz, sample=35, buffer_id=14:23
    db 0,0,100,0,61,127,5,4,233,0,61,5  ; n325 t=37.107s dur=100ms, freq=233Hz, sample=61, buffer_id=05:3D
    db 250,0,100,0,47,127,6,5,117,0,47,5  ; n326 t=37.107s dur=100ms, freq=117Hz, sample=47, buffer_id=05:2F
    db 0,0,100,0,62,127,5,1,38,1,62,5  ; n327 t=37.357s dur=100ms, freq=294Hz, sample=62, buffer_id=05:3E
    db 0,0,100,0,50,127,6,0,147,0,50,5  ; n328 t=37.357s dur=100ms, freq=147Hz, sample=50, buffer_id=05:32
    db 0,0,212,1,59,127,19,7,233,0,59,19  ; n329 t=37.357s dur=468ms, freq=233Hz, sample=59, buffer_id=13:3B
    db 244,1,212,1,47,127,20,6,117,0,47,20  ; n330 t=37.357s dur=468ms, freq=117Hz, sample=47, buffer_id=14:2F
    db 0,0,100,0,61,127,5,0,21,1,61,5  ; n331 t=37.857s dur=100ms, freq=277Hz, sample=61, buffer_id=05:3D
    db 0,0,100,0,49,127,6,1,139,0,49,5  ; n332 t=37.857s dur=100ms, freq=139Hz, sample=49, buffer_id=05:31
    db 0,0,25,3,45,127,7,2,139,0,45,7  ; n333 t=37.857s dur=793ms, freq=139Hz, sample=45, buffer_id=07:2D
    db 0,0,127,0,61,127,7,3,21,1,61,7  ; n334 t=37.857s dur=127ms, freq=277Hz, sample=61, buffer_id=07:3D
    db 0,0,212,1,54,127,19,4,185,0,54,19  ; n335 t=37.857s dur=468ms, freq=185Hz, sample=54, buffer_id=13:36
    db 244,1,212,1,42,127,20,5,92,0,42,20  ; n336 t=37.857s dur=468ms, freq=92Hz, sample=42, buffer_id=14:2A
    db 0,0,212,1,59,127,19,0,233,0,59,19  ; n337 t=38.357s dur=468ms, freq=233Hz, sample=59, buffer_id=13:3B
    db 244,1,212,1,47,127,20,1,117,0,47,20  ; n338 t=38.357s dur=468ms, freq=117Hz, sample=47, buffer_id=14:2F
    db 0,0,100,0,47,127,5,2,123,0,47,5  ; n339 t=38.857s dur=100ms, freq=123Hz, sample=47, buffer_id=05:2F
    db 0,0,100,0,35,127,6,3,62,0,35,5  ; n340 t=38.857s dur=100ms, freq=62Hz, sample=35, buffer_id=05:23
    db 0,0,218,0,47,127,19,4,123,0,47,19  ; n341 t=38.857s dur=218ms, freq=123Hz, sample=47, buffer_id=13:2F
    db 250,0,218,0,35,127,20,5,62,0,35,20  ; n342 t=38.857s dur=218ms, freq=62Hz, sample=35, buffer_id=14:23
    db 0,0,218,0,47,127,19,0,139,0,47,19  ; n343 t=39.107s dur=218ms, freq=139Hz, sample=47, buffer_id=13:2F
    db 250,0,218,0,35,127,20,1,69,0,35,20  ; n344 t=39.107s dur=218ms, freq=69Hz, sample=35, buffer_id=14:23
    db 0,0,100,0,54,127,5,2,185,0,54,5  ; n345 t=39.357s dur=100ms, freq=185Hz, sample=54, buffer_id=05:36
    db 0,0,100,0,42,127,6,3,92,0,42,5  ; n346 t=39.357s dur=100ms, freq=92Hz, sample=42, buffer_id=05:2A
    db 0,0,218,0,47,127,19,5,147,0,47,19  ; n347 t=39.357s dur=218ms, freq=147Hz, sample=47, buffer_id=13:2F
    db 250,0,218,0,35,127,20,4,73,0,35,20  ; n348 t=39.357s dur=218ms, freq=73Hz, sample=35, buffer_id=14:23
    db 0,0,218,0,54,127,19,0,165,0,54,19  ; n349 t=39.607s dur=218ms, freq=165Hz, sample=54, buffer_id=13:36
    db 250,0,218,0,42,127,20,1,82,0,42,20  ; n350 t=39.607s dur=218ms, freq=82Hz, sample=42, buffer_id=14:2A
    db 0,0,100,0,47,127,5,2,123,0,47,5  ; n351 t=39.857s dur=100ms, freq=123Hz, sample=47, buffer_id=05:2F
    db 0,0,100,0,35,127,6,3,62,0,35,5  ; n352 t=39.857s dur=100ms, freq=62Hz, sample=35, buffer_id=05:23
    db 0,0,218,0,54,127,19,4,185,0,54,19  ; n353 t=39.857s dur=218ms, freq=185Hz, sample=54, buffer_id=13:36
    db 250,0,218,0,42,127,20,5,92,0,42,20  ; n354 t=39.857s dur=218ms, freq=92Hz, sample=42, buffer_id=14:2A
    db 0,0,218,0,47,127,19,0,147,0,47,19  ; n355 t=40.107s dur=218ms, freq=147Hz, sample=47, buffer_id=13:2F
    db 250,0,218,0,35,127,20,1,73,0,35,20  ; n356 t=40.107s dur=218ms, freq=73Hz, sample=35, buffer_id=14:23
    db 0,0,100,0,54,127,5,2,185,0,54,5  ; n357 t=40.357s dur=100ms, freq=185Hz, sample=54, buffer_id=05:36
    db 0,0,100,0,42,127,6,3,92,0,42,5  ; n358 t=40.357s dur=100ms, freq=92Hz, sample=42, buffer_id=05:2A
    db 0,0,218,0,54,127,19,5,185,0,54,19  ; n359 t=40.357s dur=218ms, freq=185Hz, sample=54, buffer_id=13:36
    db 244,1,218,0,42,127,20,4,92,0,42,20  ; n360 t=40.357s dur=218ms, freq=92Hz, sample=42, buffer_id=14:2A
    db 0,0,100,0,47,127,5,0,123,0,47,5  ; n361 t=40.857s dur=100ms, freq=123Hz, sample=47, buffer_id=05:2F
    db 0,0,100,0,35,127,6,1,62,0,35,5  ; n362 t=40.857s dur=100ms, freq=62Hz, sample=35, buffer_id=05:23
    db 0,0,218,0,54,127,19,2,175,0,54,19  ; n363 t=40.857s dur=218ms, freq=175Hz, sample=54, buffer_id=13:36
    db 250,0,218,0,42,127,20,3,87,0,42,20  ; n364 t=40.857s dur=218ms, freq=87Hz, sample=42, buffer_id=14:2A
    db 0,0,218,0,47,127,19,4,139,0,47,19  ; n365 t=41.107s dur=218ms, freq=139Hz, sample=47, buffer_id=13:2F
    db 250,0,218,0,35,127,20,5,69,0,35,20  ; n366 t=41.107s dur=218ms, freq=69Hz, sample=35, buffer_id=14:23
    db 0,0,100,0,54,127,5,0,185,0,54,5  ; n367 t=41.357s dur=100ms, freq=185Hz, sample=54, buffer_id=05:36
    db 0,0,100,0,42,127,6,1,92,0,42,5  ; n368 t=41.357s dur=100ms, freq=92Hz, sample=42, buffer_id=05:2A
    db 0,0,212,1,54,127,19,3,175,0,54,19  ; n369 t=41.357s dur=468ms, freq=175Hz, sample=54, buffer_id=13:36
    db 244,1,212,1,42,127,20,2,87,0,42,20  ; n370 t=41.357s dur=468ms, freq=87Hz, sample=42, buffer_id=14:2A
    db 0,0,100,0,47,127,5,0,123,0,47,5  ; n371 t=41.857s dur=100ms, freq=123Hz, sample=47, buffer_id=05:2F
    db 0,0,100,0,35,127,6,1,62,0,35,5  ; n372 t=41.857s dur=100ms, freq=62Hz, sample=35, buffer_id=05:23
    db 0,0,218,0,54,127,19,4,165,0,54,19  ; n373 t=41.857s dur=218ms, freq=165Hz, sample=54, buffer_id=13:36
    db 250,0,218,0,42,127,20,5,82,0,42,20  ; n374 t=41.857s dur=218ms, freq=82Hz, sample=42, buffer_id=14:2A
    db 0,0,218,0,47,127,19,2,131,0,47,19  ; n375 t=42.107s dur=218ms, freq=131Hz, sample=47, buffer_id=13:2F
    db 250,0,218,0,35,127,20,3,65,0,35,20  ; n376 t=42.107s dur=218ms, freq=65Hz, sample=35, buffer_id=14:23
    db 0,0,100,0,54,127,5,0,185,0,54,5  ; n377 t=42.357s dur=100ms, freq=185Hz, sample=54, buffer_id=05:36
    db 0,0,100,0,42,127,6,1,92,0,42,5  ; n378 t=42.357s dur=100ms, freq=92Hz, sample=42, buffer_id=05:2A
    db 0,0,212,1,54,127,19,5,165,0,54,19  ; n379 t=42.357s dur=468ms, freq=165Hz, sample=54, buffer_id=13:36
    db 244,1,212,1,42,127,20,4,82,0,42,20  ; n380 t=42.357s dur=468ms, freq=82Hz, sample=42, buffer_id=14:2A
    db 0,0,100,0,47,127,5,0,123,0,47,5  ; n381 t=42.857s dur=100ms, freq=123Hz, sample=47, buffer_id=05:2F
    db 0,0,100,0,35,127,6,1,62,0,35,5  ; n382 t=42.857s dur=100ms, freq=62Hz, sample=35, buffer_id=05:23
    db 0,0,218,0,47,127,19,3,123,0,47,19  ; n383 t=42.857s dur=218ms, freq=123Hz, sample=47, buffer_id=13:2F
    db 250,0,218,0,35,127,20,2,62,0,35,20  ; n384 t=42.857s dur=218ms, freq=62Hz, sample=35, buffer_id=14:23
    db 0,0,218,0,47,127,19,4,139,0,47,19  ; n385 t=43.107s dur=218ms, freq=139Hz, sample=47, buffer_id=13:2F
    db 250,0,218,0,35,127,20,5,69,0,35,20  ; n386 t=43.107s dur=218ms, freq=69Hz, sample=35, buffer_id=14:23
    db 0,0,100,0,54,127,5,0,185,0,54,5  ; n387 t=43.357s dur=100ms, freq=185Hz, sample=54, buffer_id=05:36
    db 0,0,100,0,42,127,6,1,92,0,42,5  ; n388 t=43.357s dur=100ms, freq=92Hz, sample=42, buffer_id=05:2A
    db 0,0,218,0,47,127,19,2,147,0,47,19  ; n389 t=43.357s dur=218ms, freq=147Hz, sample=47, buffer_id=13:2F
    db 250,0,218,0,35,127,20,3,73,0,35,20  ; n390 t=43.357s dur=218ms, freq=73Hz, sample=35, buffer_id=14:23
    db 0,0,218,0,54,127,19,4,165,0,54,19  ; n391 t=43.607s dur=218ms, freq=165Hz, sample=54, buffer_id=13:36
    db 250,0,218,0,42,127,20,5,82,0,42,20  ; n392 t=43.607s dur=218ms, freq=82Hz, sample=42, buffer_id=14:2A
    db 0,0,100,0,47,127,5,0,123,0,47,5  ; n393 t=43.857s dur=100ms, freq=123Hz, sample=47, buffer_id=05:2F
    db 0,0,100,0,35,127,6,1,62,0,35,5  ; n394 t=43.857s dur=100ms, freq=62Hz, sample=35, buffer_id=05:23
    db 0,0,218,0,54,127,19,2,185,0,54,19  ; n395 t=43.857s dur=218ms, freq=185Hz, sample=54, buffer_id=13:36
    db 250,0,218,0,42,127,20,3,92,0,42,20  ; n396 t=43.857s dur=218ms, freq=92Hz, sample=42, buffer_id=14:2A
    db 0,0,218,0,47,127,19,4,147,0,47,19  ; n397 t=44.107s dur=218ms, freq=147Hz, sample=47, buffer_id=13:2F
    db 250,0,218,0,35,127,20,5,73,0,35,20  ; n398 t=44.107s dur=218ms, freq=73Hz, sample=35, buffer_id=14:23
    db 0,0,100,0,54,127,5,0,185,0,54,5  ; n399 t=44.357s dur=100ms, freq=185Hz, sample=54, buffer_id=05:36
    db 0,0,100,0,42,127,6,1,92,0,42,5  ; n400 t=44.357s dur=100ms, freq=92Hz, sample=42, buffer_id=05:2A
    db 0,0,218,0,54,127,19,3,185,0,54,19  ; n401 t=44.357s dur=218ms, freq=185Hz, sample=54, buffer_id=13:36
    db 250,0,218,0,42,127,20,2,92,0,42,20  ; n402 t=44.357s dur=218ms, freq=92Hz, sample=42, buffer_id=14:2A
    db 0,0,218,0,59,127,19,4,247,0,59,19  ; n403 t=44.607s dur=218ms, freq=247Hz, sample=59, buffer_id=13:3B
    db 250,0,218,0,47,127,20,5,123,0,47,20  ; n404 t=44.607s dur=218ms, freq=123Hz, sample=47, buffer_id=14:2F
    db 0,0,100,0,50,127,5,0,147,0,50,5  ; n405 t=44.857s dur=100ms, freq=147Hz, sample=50, buffer_id=05:32
    db 0,0,100,0,35,127,6,1,73,0,35,5  ; n406 t=44.857s dur=100ms, freq=73Hz, sample=35, buffer_id=05:23
    db 0,0,218,0,59,127,19,2,220,0,59,19  ; n407 t=44.857s dur=218ms, freq=220Hz, sample=59, buffer_id=13:3B
    db 250,0,218,0,47,127,20,3,110,0,47,20  ; n408 t=44.857s dur=218ms, freq=110Hz, sample=47, buffer_id=14:2F
    db 0,0,218,0,54,127,19,4,185,0,54,19  ; n409 t=45.107s dur=218ms, freq=185Hz, sample=54, buffer_id=13:36
    db 250,0,218,0,42,127,20,5,92,0,42,20  ; n410 t=45.107s dur=218ms, freq=92Hz, sample=42, buffer_id=14:2A
    db 0,0,100,0,54,127,5,0,220,0,54,5  ; n411 t=45.357s dur=100ms, freq=220Hz, sample=54, buffer_id=05:36
    db 0,0,100,0,47,127,6,1,110,0,47,5  ; n412 t=45.357s dur=100ms, freq=110Hz, sample=47, buffer_id=05:2F
    db 0,0,218,0,47,127,19,2,147,0,47,19  ; n413 t=45.357s dur=218ms, freq=147Hz, sample=47, buffer_id=13:2F
    db 250,0,218,0,35,127,20,3,73,0,35,20  ; n414 t=45.357s dur=218ms, freq=73Hz, sample=35, buffer_id=14:23
    db 0,0,218,0,54,127,19,5,185,0,54,19  ; n415 t=45.607s dur=218ms, freq=185Hz, sample=54, buffer_id=13:36
    db 250,0,218,0,42,127,20,4,92,0,42,20  ; n416 t=45.607s dur=218ms, freq=92Hz, sample=42, buffer_id=14:2A
    db 0,0,100,0,50,127,5,0,147,0,50,5  ; n417 t=45.857s dur=100ms, freq=147Hz, sample=50, buffer_id=05:32
    db 0,0,100,0,35,127,6,1,73,0,35,5  ; n418 t=45.857s dur=100ms, freq=73Hz, sample=35, buffer_id=05:23
    db 0,0,232,3,45,127,7,2,110,0,45,7  ; n419 t=45.857s dur=1000ms, freq=110Hz, sample=45, buffer_id=07:2D
    db 0,0,120,0,57,127,7,3,220,0,57,7  ; n420 t=45.857s dur=120ms, freq=220Hz, sample=57, buffer_id=07:39
    db 0,0,212,1,59,127,19,6,220,0,59,19  ; n421 t=45.857s dur=468ms, freq=220Hz, sample=59, buffer_id=13:3B
    db 244,1,212,1,47,127,20,7,110,0,47,20  ; n422 t=45.857s dur=468ms, freq=110Hz, sample=47, buffer_id=14:2F
    db 0,0,100,0,54,127,5,0,220,0,54,5  ; n423 t=46.357s dur=100ms, freq=220Hz, sample=54, buffer_id=05:36
    db 244,1,100,0,47,127,6,1,110,0,47,5  ; n424 t=46.357s dur=100ms, freq=110Hz, sample=47, buffer_id=05:2F
    db 0,0,100,0,47,127,5,0,123,0,47,5  ; n425 t=46.857s dur=100ms, freq=123Hz, sample=47, buffer_id=05:2F
    db 0,0,100,0,35,127,6,1,62,0,35,5  ; n426 t=46.857s dur=100ms, freq=62Hz, sample=35, buffer_id=05:23
    db 0,0,212,1,47,127,19,3,123,0,47,19  ; n427 t=46.857s dur=468ms, freq=123Hz, sample=47, buffer_id=13:2F
    db 250,0,212,1,35,127,20,4,62,0,35,20  ; n428 t=46.857s dur=468ms, freq=62Hz, sample=35, buffer_id=14:23
    db 0,0,100,0,49,127,5,2,139,0,49,5  ; n429 t=47.107s dur=100ms, freq=139Hz, sample=49, buffer_id=05:31
    db 250,0,100,0,35,127,6,5,69,0,35,5  ; n430 t=47.107s dur=100ms, freq=69Hz, sample=35, buffer_id=05:23
    db 0,0,100,0,50,127,5,0,147,0,50,5  ; n431 t=47.357s dur=100ms, freq=147Hz, sample=50, buffer_id=05:32
    db 0,0,100,0,35,127,6,6,73,0,35,5  ; n432 t=47.357s dur=100ms, freq=73Hz, sample=35, buffer_id=05:23
    db 0,0,212,1,54,127,19,1,185,0,54,19  ; n433 t=47.357s dur=468ms, freq=185Hz, sample=54, buffer_id=13:36
    db 250,0,212,1,42,127,20,7,92,0,42,20  ; n434 t=47.357s dur=468ms, freq=92Hz, sample=42, buffer_id=14:2A
    db 0,0,100,0,50,127,5,2,165,0,50,5  ; n435 t=47.607s dur=100ms, freq=165Hz, sample=50, buffer_id=05:32
    db 250,0,100,0,42,127,6,3,82,0,42,5  ; n436 t=47.607s dur=100ms, freq=82Hz, sample=42, buffer_id=05:2A
    db 0,0,100,0,54,127,5,0,185,0,54,5  ; n437 t=47.857s dur=100ms, freq=185Hz, sample=54, buffer_id=05:36
    db 0,0,100,0,42,127,6,4,92,0,42,5  ; n438 t=47.857s dur=100ms, freq=92Hz, sample=42, buffer_id=05:2A
    db 0,0,212,1,47,127,19,5,123,0,47,19  ; n439 t=47.857s dur=468ms, freq=123Hz, sample=47, buffer_id=13:2F
    db 250,0,212,1,35,127,20,6,62,0,35,20  ; n440 t=47.857s dur=468ms, freq=62Hz, sample=35, buffer_id=14:23
    db 0,0,100,0,50,127,5,1,147,0,50,5  ; n441 t=48.107s dur=100ms, freq=147Hz, sample=50, buffer_id=05:32
    db 250,0,100,0,35,127,6,2,73,0,35,5  ; n442 t=48.107s dur=100ms, freq=73Hz, sample=35, buffer_id=05:23
    db 0,0,100,0,54,127,5,3,185,0,54,5  ; n443 t=48.357s dur=100ms, freq=185Hz, sample=54, buffer_id=05:36
    db 0,0,100,0,42,127,6,0,92,0,42,5  ; n444 t=48.357s dur=100ms, freq=92Hz, sample=42, buffer_id=05:2A
    db 0,0,212,1,54,127,19,4,185,0,54,19  ; n445 t=48.357s dur=468ms, freq=185Hz, sample=54, buffer_id=13:36
    db 244,1,212,1,42,127,20,8,92,0,42,20  ; n446 t=48.357s dur=468ms, freq=92Hz, sample=42, buffer_id=14:2A
    db 0,0,100,0,54,127,5,0,175,0,54,5  ; n447 t=48.857s dur=100ms, freq=175Hz, sample=54, buffer_id=05:36
    db 0,0,100,0,42,127,6,1,87,0,42,5  ; n448 t=48.857s dur=100ms, freq=87Hz, sample=42, buffer_id=05:2A
    db 0,0,212,1,47,127,19,2,123,0,47,19  ; n449 t=48.857s dur=468ms, freq=123Hz, sample=47, buffer_id=13:2F
    db 250,0,212,1,35,127,20,3,62,0,35,20  ; n450 t=48.857s dur=468ms, freq=62Hz, sample=35, buffer_id=14:23
    db 0,0,100,0,49,127,5,4,139,0,49,5  ; n451 t=49.107s dur=100ms, freq=139Hz, sample=49, buffer_id=05:31
    db 250,0,100,0,35,127,6,5,69,0,35,5  ; n452 t=49.107s dur=100ms, freq=69Hz, sample=35, buffer_id=05:23
    db 0,0,100,0,54,127,5,1,175,0,54,5  ; n453 t=49.357s dur=100ms, freq=175Hz, sample=54, buffer_id=05:36
    db 0,0,100,0,42,127,6,0,87,0,42,5  ; n454 t=49.357s dur=100ms, freq=87Hz, sample=42, buffer_id=05:2A
    db 0,0,212,1,54,127,19,6,185,0,54,19  ; n455 t=49.357s dur=468ms, freq=185Hz, sample=54, buffer_id=13:36
    db 244,1,212,1,42,127,20,9,92,0,42,20  ; n456 t=49.357s dur=468ms, freq=92Hz, sample=42, buffer_id=14:2A
    db 0,0,100,0,50,127,5,0,165,0,50,5  ; n457 t=49.857s dur=100ms, freq=165Hz, sample=50, buffer_id=05:32
    db 0,0,100,0,42,127,6,1,82,0,42,5  ; n458 t=49.857s dur=100ms, freq=82Hz, sample=42, buffer_id=05:2A
    db 0,0,212,1,47,127,19,3,123,0,47,19  ; n459 t=49.857s dur=468ms, freq=123Hz, sample=47, buffer_id=13:2F
    db 250,0,212,1,35,127,20,2,62,0,35,20  ; n460 t=49.857s dur=468ms, freq=62Hz, sample=35, buffer_id=14:23
    db 0,0,100,0,47,127,5,4,131,0,47,5  ; n461 t=50.107s dur=100ms, freq=131Hz, sample=47, buffer_id=05:2F
    db 250,0,100,0,35,127,6,6,65,0,35,5  ; n462 t=50.107s dur=100ms, freq=65Hz, sample=35, buffer_id=05:23
    db 0,0,100,0,50,127,5,1,165,0,50,5  ; n463 t=50.357s dur=100ms, freq=165Hz, sample=50, buffer_id=05:32
    db 0,0,100,0,42,127,6,0,82,0,42,5  ; n464 t=50.357s dur=100ms, freq=82Hz, sample=42, buffer_id=05:2A
    db 0,0,212,1,54,127,19,5,185,0,54,19  ; n465 t=50.357s dur=468ms, freq=185Hz, sample=54, buffer_id=13:36
    db 244,1,212,1,42,127,20,10,92,0,42,20  ; n466 t=50.357s dur=468ms, freq=92Hz, sample=42, buffer_id=14:2A
    db 0,0,100,0,47,127,5,0,123,0,47,5  ; n467 t=50.857s dur=100ms, freq=123Hz, sample=47, buffer_id=05:2F
    db 0,0,100,0,35,127,6,1,62,0,35,5  ; n468 t=50.857s dur=100ms, freq=62Hz, sample=35, buffer_id=05:23
    db 0,0,212,1,47,127,19,2,123,0,47,19  ; n469 t=50.857s dur=468ms, freq=123Hz, sample=47, buffer_id=13:2F
    db 250,0,212,1,35,127,20,3,62,0,35,20  ; n470 t=50.857s dur=468ms, freq=62Hz, sample=35, buffer_id=14:23
    db 0,0,100,0,49,127,5,4,139,0,49,5  ; n471 t=51.107s dur=100ms, freq=139Hz, sample=49, buffer_id=05:31
    db 250,0,100,0,35,127,6,5,69,0,35,5  ; n472 t=51.107s dur=100ms, freq=69Hz, sample=35, buffer_id=05:23
    db 0,0,100,0,50,127,5,0,147,0,50,5  ; n473 t=51.357s dur=100ms, freq=147Hz, sample=50, buffer_id=05:32
    db 0,0,100,0,35,127,6,7,73,0,35,5  ; n474 t=51.357s dur=100ms, freq=73Hz, sample=35, buffer_id=05:23
    db 0,0,212,1,59,127,19,1,247,0,59,19  ; n475 t=51.357s dur=468ms, freq=247Hz, sample=59, buffer_id=13:3B
    db 250,0,212,1,47,127,20,6,123,0,47,20  ; n476 t=51.357s dur=468ms, freq=123Hz, sample=47, buffer_id=14:2F
    db 0,0,100,0,50,127,5,2,165,0,50,5  ; n477 t=51.607s dur=100ms, freq=165Hz, sample=50, buffer_id=05:32
    db 250,0,100,0,42,127,6,3,82,0,42,5  ; n478 t=51.607s dur=100ms, freq=82Hz, sample=42, buffer_id=05:2A
    db 0,0,100,0,54,127,5,0,185,0,54,5  ; n479 t=51.857s dur=100ms, freq=185Hz, sample=54, buffer_id=05:36
    db 0,0,100,0,42,127,6,4,92,0,42,5  ; n480 t=51.857s dur=100ms, freq=92Hz, sample=42, buffer_id=05:2A
    db 0,0,212,1,59,127,19,5,220,0,59,19  ; n481 t=51.857s dur=468ms, freq=220Hz, sample=59, buffer_id=13:3B
    db 250,0,212,1,47,127,20,7,110,0,47,20  ; n482 t=51.857s dur=468ms, freq=110Hz, sample=47, buffer_id=14:2F
    db 0,0,100,0,50,127,5,1,147,0,50,5  ; n483 t=52.107s dur=100ms, freq=147Hz, sample=50, buffer_id=05:32
    db 250,0,100,0,35,127,6,2,73,0,35,5  ; n484 t=52.107s dur=100ms, freq=73Hz, sample=35, buffer_id=05:23
    db 0,0,100,0,54,127,5,3,185,0,54,5  ; n485 t=52.357s dur=100ms, freq=185Hz, sample=54, buffer_id=05:36
    db 0,0,100,0,42,127,6,0,92,0,42,5  ; n486 t=52.357s dur=100ms, freq=92Hz, sample=42, buffer_id=05:2A
    db 0,0,212,1,54,127,19,4,196,0,54,19  ; n487 t=52.357s dur=468ms, freq=196Hz, sample=54, buffer_id=13:36
    db 250,0,212,1,42,127,20,6,98,0,42,20  ; n488 t=52.357s dur=468ms, freq=98Hz, sample=42, buffer_id=14:2A
    db 0,0,100,0,61,127,5,1,247,0,61,5  ; n489 t=52.607s dur=100ms, freq=247Hz, sample=61, buffer_id=05:3D
    db 250,0,100,0,47,127,6,2,123,0,47,5  ; n490 t=52.607s dur=100ms, freq=123Hz, sample=47, buffer_id=05:2F
    db 0,0,100,0,54,127,5,0,185,0,54,5  ; n491 t=52.857s dur=100ms, freq=185Hz, sample=54, buffer_id=05:36
    db 0,0,100,0,42,127,6,3,92,0,42,5  ; n492 t=52.857s dur=100ms, freq=92Hz, sample=42, buffer_id=05:2A
    db 0,0,212,1,54,127,19,5,185,0,54,19  ; n493 t=52.857s dur=468ms, freq=185Hz, sample=54, buffer_id=13:36
    db 250,0,212,1,42,127,20,7,92,0,42,20  ; n494 t=52.857s dur=468ms, freq=92Hz, sample=42, buffer_id=14:2A
    db 0,0,100,0,50,127,5,1,147,0,50,5  ; n495 t=53.107s dur=100ms, freq=147Hz, sample=50, buffer_id=05:32
    db 250,0,100,0,35,127,6,2,73,0,35,5  ; n496 t=53.107s dur=100ms, freq=73Hz, sample=35, buffer_id=05:23
    db 0,0,100,0,54,127,5,3,185,0,54,5  ; n497 t=53.357s dur=100ms, freq=185Hz, sample=54, buffer_id=05:36
    db 0,0,100,0,42,127,6,0,92,0,42,5  ; n498 t=53.357s dur=100ms, freq=92Hz, sample=42, buffer_id=05:2A
    db 0,0,212,1,54,127,19,6,165,0,54,19  ; n499 t=53.357s dur=468ms, freq=165Hz, sample=54, buffer_id=13:36
    db 250,0,212,1,42,127,20,4,82,0,42,20  ; n500 t=53.357s dur=468ms, freq=82Hz, sample=42, buffer_id=14:2A
    db 0,0,100,0,61,127,5,1,247,0,61,5  ; n501 t=53.607s dur=100ms, freq=247Hz, sample=61, buffer_id=05:3D
    db 250,0,100,0,47,127,6,2,123,0,47,5  ; n502 t=53.607s dur=100ms, freq=123Hz, sample=47, buffer_id=05:2F
    db 0,0,200,3,47,127,5,0,123,0,47,5  ; n503 t=53.857s dur=968ms, freq=123Hz, sample=47, buffer_id=05:2F
    db 0,0,200,3,35,127,6,3,62,0,35,5  ; n504 t=53.857s dur=968ms, freq=62Hz, sample=35, buffer_id=05:23
    db 0,0,138,1,47,127,19,5,147,0,47,19  ; n505 t=53.857s dur=394ms, freq=147Hz, sample=47, buffer_id=13:2F
    db 244,1,138,1,35,127,20,7,73,0,35,20  ; n506 t=53.857s dur=394ms, freq=73Hz, sample=35, buffer_id=14:23
    db 0,0,161,1,47,127,19,1,139,0,47,19  ; n507 t=54.357s dur=417ms, freq=139Hz, sample=47, buffer_id=13:2F
    db 244,1,161,1,35,127,20,2,69,0,35,20  ; n508 t=54.357s dur=417ms, freq=69Hz, sample=35, buffer_id=14:23
    db 0,0,210,0,70,127,16,4,238,1,70,16  ; n509 t=54.857s dur=210ms, freq=494Hz, sample=70, buffer_id=10:46
    db 0,0,210,0,59,127,17,5,247,0,59,16  ; n510 t=54.857s dur=210ms, freq=247Hz, sample=59, buffer_id=10:3B
    db 0,0,194,1,47,127,19,6,123,0,47,19  ; n511 t=54.857s dur=450ms, freq=123Hz, sample=47, buffer_id=13:2F
    db 240,0,194,1,35,127,20,8,62,0,35,20  ; n512 t=54.857s dur=450ms, freq=62Hz, sample=35, buffer_id=14:23
    db 0,0,210,0,73,127,16,0,42,2,73,16  ; n513 t=55.097s dur=210ms, freq=554Hz, sample=73, buffer_id=10:49
    db 240,0,210,0,61,127,17,1,21,1,61,16  ; n514 t=55.097s dur=210ms, freq=277Hz, sample=61, buffer_id=10:3D
    db 0,0,100,0,78,127,2,2,228,2,78,2  ; n515 t=55.337s dur=100ms, freq=740Hz, sample=78, buffer_id=02:4E
    db 0,0,100,0,74,127,4,3,75,2,74,4  ; n516 t=55.337s dur=100ms, freq=587Hz, sample=74, buffer_id=04:4A
    db 0,0,100,0,78,127,4,4,228,2,78,4  ; n517 t=55.337s dur=100ms, freq=740Hz, sample=78, buffer_id=04:4E
    db 0,0,120,0,54,127,7,5,185,0,54,7  ; n518 t=55.337s dur=120ms, freq=185Hz, sample=54, buffer_id=07:36
    db 0,0,120,0,66,127,7,7,114,1,66,7  ; n519 t=55.337s dur=120ms, freq=370Hz, sample=66, buffer_id=07:42
    db 0,0,120,0,62,127,8,9,38,1,62,7  ; n520 t=55.337s dur=120ms, freq=294Hz, sample=62, buffer_id=07:3E
    db 0,0,210,0,74,127,16,10,75,2,74,16  ; n521 t=55.337s dur=210ms, freq=587Hz, sample=74, buffer_id=10:4A
    db 0,0,210,0,62,127,17,11,38,1,62,16  ; n522 t=55.337s dur=210ms, freq=294Hz, sample=62, buffer_id=10:3E
    db 0,0,150,0,54,127,18,12,185,0,54,18  ; n523 t=55.337s dur=150ms, freq=185Hz, sample=54, buffer_id=12:36
    db 0,0,194,1,59,127,19,13,247,0,59,19  ; n524 t=55.337s dur=450ms, freq=247Hz, sample=59, buffer_id=13:3B
    db 120,0,194,1,47,127,20,14,123,0,47,20  ; n525 t=55.337s dur=450ms, freq=123Hz, sample=47, buffer_id=14:2F
    db 120,0,150,0,54,127,18,15,175,0,54,18  ; n526 t=55.457s dur=150ms, freq=175Hz, sample=54, buffer_id=12:36
    db 0,0,210,0,74,127,16,0,147,2,74,16  ; n527 t=55.577s dur=210ms, freq=659Hz, sample=74, buffer_id=10:4A
    db 0,0,210,0,65,127,17,1,74,1,65,16  ; n528 t=55.577s dur=210ms, freq=330Hz, sample=65, buffer_id=10:41
    db 240,0,210,0,54,127,18,6,185,0,54,18  ; n529 t=55.577s dur=210ms, freq=185Hz, sample=54, buffer_id=12:36
    db 0,0,210,0,78,127,16,2,228,2,78,16  ; n530 t=55.817s dur=210ms, freq=740Hz, sample=78, buffer_id=10:4E
    db 0,0,210,0,66,127,17,3,114,1,66,16  ; n531 t=55.817s dur=210ms, freq=370Hz, sample=66, buffer_id=10:42
    db 0,0,194,1,47,127,19,4,123,0,47,19  ; n532 t=55.817s dur=450ms, freq=123Hz, sample=47, buffer_id=13:2F
    db 240,0,194,1,35,127,20,5,62,0,35,20  ; n533 t=55.817s dur=450ms, freq=62Hz, sample=35, buffer_id=14:23
    db 0,0,210,0,74,127,16,1,75,2,74,16  ; n534 t=56.057s dur=210ms, freq=587Hz, sample=74, buffer_id=10:4A
    db 240,0,210,0,62,127,17,0,38,1,62,16  ; n535 t=56.057s dur=210ms, freq=294Hz, sample=62, buffer_id=10:3E
    db 0,0,100,0,78,127,2,2,228,2,78,2  ; n536 t=56.297s dur=100ms, freq=740Hz, sample=78, buffer_id=02:4E
    db 0,0,100,0,74,127,4,3,75,2,74,4  ; n537 t=56.297s dur=100ms, freq=587Hz, sample=74, buffer_id=04:4A
    db 0,0,100,0,78,127,4,6,228,2,78,4  ; n538 t=56.297s dur=100ms, freq=740Hz, sample=78, buffer_id=04:4E
    db 0,0,120,0,54,127,7,7,185,0,54,7  ; n539 t=56.297s dur=120ms, freq=185Hz, sample=54, buffer_id=07:36
    db 0,0,120,0,66,127,7,8,114,1,66,7  ; n540 t=56.297s dur=120ms, freq=370Hz, sample=66, buffer_id=07:42
    db 0,0,120,0,62,127,8,10,38,1,62,7  ; n541 t=56.297s dur=120ms, freq=294Hz, sample=62, buffer_id=07:3E
    db 0,0,194,1,78,127,16,9,228,2,78,16  ; n542 t=56.297s dur=450ms, freq=740Hz, sample=78, buffer_id=10:4E
    db 0,0,194,1,66,127,17,11,114,1,66,16  ; n543 t=56.297s dur=450ms, freq=370Hz, sample=66, buffer_id=10:42
    db 0,0,150,0,54,127,18,13,185,0,54,18  ; n544 t=56.297s dur=150ms, freq=185Hz, sample=54, buffer_id=12:36
    db 0,0,194,1,59,127,19,12,247,0,59,19  ; n545 t=56.297s dur=450ms, freq=247Hz, sample=59, buffer_id=13:3B
    db 120,0,194,1,47,127,20,15,123,0,47,20  ; n546 t=56.297s dur=450ms, freq=123Hz, sample=47, buffer_id=14:2F
    db 120,0,150,0,54,127,18,14,175,0,54,18  ; n547 t=56.417s dur=150ms, freq=175Hz, sample=54, buffer_id=12:36
    db 240,0,210,0,54,127,18,0,185,0,54,18  ; n548 t=56.537s dur=210ms, freq=185Hz, sample=54, buffer_id=12:36
    db 0,0,210,0,78,127,16,1,186,2,78,16  ; n549 t=56.777s dur=210ms, freq=698Hz, sample=78, buffer_id=10:4E
    db 0,0,210,0,65,127,17,2,93,1,65,16  ; n550 t=56.777s dur=210ms, freq=349Hz, sample=65, buffer_id=10:41
    db 0,0,194,1,47,127,19,3,123,0,47,19  ; n551 t=56.777s dur=450ms, freq=123Hz, sample=47, buffer_id=13:2F
    db 240,0,194,1,35,127,20,4,62,0,35,20  ; n552 t=56.777s dur=450ms, freq=62Hz, sample=35, buffer_id=14:23
    db 0,0,210,0,73,127,16,0,42,2,73,16  ; n553 t=57.017s dur=210ms, freq=554Hz, sample=73, buffer_id=10:49
    db 240,0,210,0,61,127,17,5,21,1,61,16  ; n554 t=57.017s dur=210ms, freq=277Hz, sample=61, buffer_id=10:3D
    db 0,0,100,0,78,127,2,1,228,2,78,2  ; n555 t=57.257s dur=100ms, freq=740Hz, sample=78, buffer_id=02:4E
    db 0,0,100,0,73,127,4,2,42,2,73,4  ; n556 t=57.257s dur=100ms, freq=554Hz, sample=73, buffer_id=04:49
    db 0,0,100,0,78,127,4,7,186,2,78,4  ; n557 t=57.257s dur=100ms, freq=698Hz, sample=78, buffer_id=04:4E
    db 0,0,120,0,54,127,7,6,185,0,54,7  ; n558 t=57.257s dur=120ms, freq=185Hz, sample=54, buffer_id=07:36
    db 0,0,120,0,66,127,7,9,114,1,66,7  ; n559 t=57.257s dur=120ms, freq=370Hz, sample=66, buffer_id=07:42
    db 0,0,120,0,61,127,8,8,21,1,61,7  ; n560 t=57.257s dur=120ms, freq=277Hz, sample=61, buffer_id=07:3D
    db 0,0,120,0,66,127,8,10,93,1,66,7  ; n561 t=57.257s dur=120ms, freq=349Hz, sample=66, buffer_id=07:42
    db 0,0,194,1,78,127,16,11,186,2,78,16  ; n562 t=57.257s dur=450ms, freq=698Hz, sample=78, buffer_id=10:4E
    db 0,0,194,1,65,127,17,12,93,1,65,16  ; n563 t=57.257s dur=450ms, freq=349Hz, sample=65, buffer_id=10:41
    db 0,0,150,0,54,127,18,15,185,0,54,18  ; n564 t=57.257s dur=150ms, freq=185Hz, sample=54, buffer_id=12:36
    db 0,0,194,1,59,127,19,13,247,0,59,19  ; n565 t=57.257s dur=450ms, freq=247Hz, sample=59, buffer_id=13:3B
    db 120,0,194,1,47,127,20,14,123,0,47,20  ; n566 t=57.257s dur=450ms, freq=123Hz, sample=47, buffer_id=14:2F
    db 120,0,150,0,54,127,18,16,175,0,54,18  ; n567 t=57.377s dur=150ms, freq=175Hz, sample=54, buffer_id=12:36
    db 240,0,210,0,54,127,18,0,185,0,54,18  ; n568 t=57.497s dur=210ms, freq=185Hz, sample=54, buffer_id=12:36
    db 0,0,210,0,74,127,16,1,147,2,74,16  ; n569 t=57.737s dur=210ms, freq=659Hz, sample=74, buffer_id=10:4A
    db 0,0,210,0,65,127,17,2,74,1,65,16  ; n570 t=57.737s dur=210ms, freq=330Hz, sample=65, buffer_id=10:41
    db 0,0,194,1,47,127,19,4,123,0,47,19  ; n571 t=57.737s dur=450ms, freq=123Hz, sample=47, buffer_id=13:2F
    db 240,0,194,1,35,127,20,3,62,0,35,20  ; n572 t=57.737s dur=450ms, freq=62Hz, sample=35, buffer_id=14:23
    db 0,0,210,0,73,127,16,0,11,2,73,16  ; n573 t=57.977s dur=210ms, freq=523Hz, sample=73, buffer_id=10:49
    db 240,0,198,0,59,127,17,5,6,1,59,16  ; n574 t=57.977s dur=198ms, freq=262Hz, sample=59, buffer_id=10:3B
    db 0,0,100,0,78,127,2,1,228,2,78,2  ; n575 t=58.217s dur=100ms, freq=740Hz, sample=78, buffer_id=02:4E
    db 0,0,100,0,73,127,4,2,42,2,73,4  ; n576 t=58.217s dur=100ms, freq=554Hz, sample=73, buffer_id=04:49
    db 0,0,100,0,78,127,4,6,186,2,78,4  ; n577 t=58.217s dur=100ms, freq=698Hz, sample=78, buffer_id=04:4E
    db 0,0,120,0,54,127,7,7,185,0,54,7  ; n578 t=58.217s dur=120ms, freq=185Hz, sample=54, buffer_id=07:36
    db 0,0,120,0,66,127,7,8,114,1,66,7  ; n579 t=58.217s dur=120ms, freq=370Hz, sample=66, buffer_id=07:42
    db 0,0,120,0,59,127,8,9,6,1,59,7  ; n580 t=58.217s dur=120ms, freq=262Hz, sample=59, buffer_id=07:3B
    db 0,0,106,0,62,127,8,10,74,1,62,7  ; n581 t=58.217s dur=106ms, freq=330Hz, sample=62, buffer_id=07:3E
    db 0,0,144,1,74,127,16,11,147,2,74,16  ; n582 t=58.217s dur=400ms, freq=659Hz, sample=74, buffer_id=10:4A
    db 0,0,194,1,65,127,17,13,74,1,65,16  ; n583 t=58.217s dur=450ms, freq=330Hz, sample=65, buffer_id=10:41
    db 0,0,150,0,54,127,18,12,185,0,54,18  ; n584 t=58.217s dur=150ms, freq=185Hz, sample=54, buffer_id=12:36
    db 0,0,194,1,59,127,19,14,247,0,59,19  ; n585 t=58.217s dur=450ms, freq=247Hz, sample=59, buffer_id=13:3B
    db 120,0,194,1,47,127,20,15,123,0,47,20  ; n586 t=58.217s dur=450ms, freq=123Hz, sample=47, buffer_id=14:2F
    db 120,0,150,0,54,127,18,17,175,0,54,18  ; n587 t=58.337s dur=150ms, freq=175Hz, sample=54, buffer_id=12:36
    db 240,0,210,0,54,127,18,0,185,0,54,18  ; n588 t=58.457s dur=210ms, freq=185Hz, sample=54, buffer_id=12:36
    db 0,0,210,0,70,127,16,1,238,1,70,16  ; n589 t=58.697s dur=210ms, freq=494Hz, sample=70, buffer_id=10:46
    db 0,0,210,0,59,127,17,2,247,0,59,16  ; n590 t=58.697s dur=210ms, freq=247Hz, sample=59, buffer_id=10:3B
    db 0,0,194,1,47,127,19,3,123,0,47,19  ; n591 t=58.697s dur=450ms, freq=123Hz, sample=47, buffer_id=13:2F
    db 240,0,194,1,35,127,20,4,62,0,35,20  ; n592 t=58.697s dur=450ms, freq=62Hz, sample=35, buffer_id=14:23
    db 0,0,210,0,73,127,16,0,42,2,73,16  ; n593 t=58.937s dur=210ms, freq=554Hz, sample=73, buffer_id=10:49
    db 240,0,210,0,61,127,17,5,21,1,61,16  ; n594 t=58.937s dur=210ms, freq=277Hz, sample=61, buffer_id=10:3D
    db 0,0,100,0,78,127,2,1,228,2,78,2  ; n595 t=59.177s dur=100ms, freq=740Hz, sample=78, buffer_id=02:4E
    db 0,0,100,0,70,127,4,2,238,1,70,4  ; n596 t=59.177s dur=100ms, freq=494Hz, sample=70, buffer_id=04:46
    db 0,0,100,0,74,127,4,6,75,2,74,4  ; n597 t=59.177s dur=100ms, freq=587Hz, sample=74, buffer_id=04:4A
    db 0,0,120,0,54,127,7,8,185,0,54,7  ; n598 t=59.177s dur=120ms, freq=185Hz, sample=54, buffer_id=07:36
    db 0,0,120,0,66,127,7,7,114,1,66,7  ; n599 t=59.177s dur=120ms, freq=370Hz, sample=66, buffer_id=07:42
    db 0,0,120,0,59,127,8,10,247,0,59,7  ; n600 t=59.177s dur=120ms, freq=247Hz, sample=59, buffer_id=07:3B
    db 0,0,120,0,62,127,8,9,38,1,62,7  ; n601 t=59.177s dur=120ms, freq=294Hz, sample=62, buffer_id=07:3E
    db 0,0,210,0,74,127,16,12,75,2,74,16  ; n602 t=59.177s dur=210ms, freq=587Hz, sample=74, buffer_id=10:4A
    db 0,0,210,0,62,127,17,11,38,1,62,16  ; n603 t=59.177s dur=210ms, freq=294Hz, sample=62, buffer_id=10:3E
    db 0,0,150,0,54,127,18,13,185,0,54,18  ; n604 t=59.177s dur=150ms, freq=185Hz, sample=54, buffer_id=12:36
    db 0,0,194,1,59,127,19,15,247,0,59,19  ; n605 t=59.177s dur=450ms, freq=247Hz, sample=59, buffer_id=13:3B
    db 120,0,194,1,47,127,20,14,123,0,47,20  ; n606 t=59.177s dur=450ms, freq=123Hz, sample=47, buffer_id=14:2F
    db 120,0,150,0,54,127,18,18,175,0,54,18  ; n607 t=59.297s dur=150ms, freq=175Hz, sample=54, buffer_id=12:36
    db 0,0,210,0,74,127,16,0,147,2,74,16  ; n608 t=59.417s dur=210ms, freq=659Hz, sample=74, buffer_id=10:4A
    db 0,0,210,0,65,127,17,3,74,1,65,16  ; n609 t=59.417s dur=210ms, freq=330Hz, sample=65, buffer_id=10:41
    db 240,0,210,0,54,127,18,4,185,0,54,18  ; n610 t=59.417s dur=210ms, freq=185Hz, sample=54, buffer_id=12:36
    db 0,0,210,0,78,127,16,1,228,2,78,16  ; n611 t=59.657s dur=210ms, freq=740Hz, sample=78, buffer_id=10:4E
    db 0,0,210,0,66,127,17,2,114,1,66,16  ; n612 t=59.657s dur=210ms, freq=370Hz, sample=66, buffer_id=10:42
    db 0,0,194,1,47,127,19,5,123,0,47,19  ; n613 t=59.657s dur=450ms, freq=123Hz, sample=47, buffer_id=13:2F
    db 240,0,194,1,35,127,20,6,62,0,35,20  ; n614 t=59.657s dur=450ms, freq=62Hz, sample=35, buffer_id=14:23
    db 0,0,210,0,74,127,16,3,75,2,74,16  ; n615 t=59.897s dur=210ms, freq=587Hz, sample=74, buffer_id=10:4A
    db 240,0,210,0,62,127,17,0,38,1,62,16  ; n616 t=59.897s dur=210ms, freq=294Hz, sample=62, buffer_id=10:3E
    db 0,0,100,0,78,127,2,1,228,2,78,2  ; n617 t=60.137s dur=100ms, freq=740Hz, sample=78, buffer_id=02:4E
    db 0,0,100,0,70,127,4,2,238,1,70,4  ; n618 t=60.137s dur=100ms, freq=494Hz, sample=70, buffer_id=04:46
    db 0,0,100,0,74,127,4,4,75,2,74,4  ; n619 t=60.137s dur=100ms, freq=587Hz, sample=74, buffer_id=04:4A
    db 0,0,120,0,54,127,7,7,185,0,54,7  ; n620 t=60.137s dur=120ms, freq=185Hz, sample=54, buffer_id=07:36
    db 0,0,120,0,66,127,7,8,114,1,66,7  ; n621 t=60.137s dur=120ms, freq=370Hz, sample=66, buffer_id=07:42
    db 0,0,120,0,59,127,8,9,247,0,59,7  ; n622 t=60.137s dur=120ms, freq=247Hz, sample=59, buffer_id=07:3B
    db 0,0,120,0,62,127,8,10,38,1,62,7  ; n623 t=60.137s dur=120ms, freq=294Hz, sample=62, buffer_id=07:3E
    db 0,0,210,0,78,127,16,11,228,2,78,16  ; n624 t=60.137s dur=210ms, freq=740Hz, sample=78, buffer_id=10:4E
    db 0,0,210,0,66,127,17,12,114,1,66,16  ; n625 t=60.137s dur=210ms, freq=370Hz, sample=66, buffer_id=10:42
    db 0,0,150,0,54,127,18,14,185,0,54,18  ; n626 t=60.137s dur=150ms, freq=185Hz, sample=54, buffer_id=12:36
    db 0,0,194,1,59,127,19,13,247,0,59,19  ; n627 t=60.137s dur=450ms, freq=247Hz, sample=59, buffer_id=13:3B
    db 120,0,194,1,47,127,20,15,123,0,47,20  ; n628 t=60.137s dur=450ms, freq=123Hz, sample=47, buffer_id=14:2F
    db 120,0,150,0,54,127,18,19,175,0,54,18  ; n629 t=60.257s dur=150ms, freq=175Hz, sample=54, buffer_id=12:36
    db 0,0,210,0,85,127,16,0,220,3,85,16  ; n630 t=60.377s dur=210ms, freq=988Hz, sample=85, buffer_id=10:55
    db 0,0,210,0,70,127,17,3,238,1,70,16  ; n631 t=60.377s dur=210ms, freq=494Hz, sample=70, buffer_id=10:46
    db 240,0,210,0,54,127,18,5,185,0,54,18  ; n632 t=60.377s dur=210ms, freq=185Hz, sample=54, buffer_id=12:36
    db 0,0,210,0,78,127,16,1,112,3,78,16  ; n633 t=60.617s dur=210ms, freq=880Hz, sample=78, buffer_id=10:4E
    db 0,0,210,0,69,127,17,2,184,1,69,16  ; n634 t=60.617s dur=210ms, freq=440Hz, sample=69, buffer_id=10:45
    db 0,0,138,1,47,127,19,4,147,0,47,19  ; n635 t=60.617s dur=394ms, freq=147Hz, sample=47, buffer_id=13:2F
    db 240,0,138,1,35,127,20,7,73,0,35,20  ; n636 t=60.617s dur=394ms, freq=73Hz, sample=35, buffer_id=14:23
    db 0,0,210,0,78,127,16,0,228,2,78,16  ; n637 t=60.857s dur=210ms, freq=740Hz, sample=78, buffer_id=10:4E
    db 240,0,210,0,66,127,17,3,114,1,66,16  ; n638 t=60.857s dur=210ms, freq=370Hz, sample=66, buffer_id=10:42
    db 0,0,100,0,78,127,2,1,228,2,78,2  ; n639 t=61.097s dur=100ms, freq=740Hz, sample=78, buffer_id=02:4E
    db 0,0,100,0,70,127,4,2,184,1,70,4  ; n640 t=61.097s dur=100ms, freq=440Hz, sample=70, buffer_id=04:46
    db 0,0,100,0,74,127,4,5,75,2,74,4  ; n641 t=61.097s dur=100ms, freq=587Hz, sample=74, buffer_id=04:4A
    db 0,0,120,0,54,127,7,6,185,0,54,7  ; n642 t=61.097s dur=120ms, freq=185Hz, sample=54, buffer_id=07:36
    db 0,0,120,0,66,127,7,9,114,1,66,7  ; n643 t=61.097s dur=120ms, freq=370Hz, sample=66, buffer_id=07:42
    db 0,0,120,0,57,127,8,8,220,0,57,7  ; n644 t=61.097s dur=120ms, freq=220Hz, sample=57, buffer_id=07:39
    db 0,0,120,0,62,127,8,11,38,1,62,7  ; n645 t=61.097s dur=120ms, freq=294Hz, sample=62, buffer_id=07:3E
    db 0,0,210,0,74,127,16,10,75,2,74,16  ; n646 t=61.097s dur=210ms, freq=587Hz, sample=74, buffer_id=10:4A
    db 0,0,210,0,62,127,17,12,38,1,62,16  ; n647 t=61.097s dur=210ms, freq=294Hz, sample=62, buffer_id=10:3E
    db 0,0,150,0,54,127,18,13,220,0,54,18  ; n648 t=61.097s dur=150ms, freq=220Hz, sample=54, buffer_id=12:36
    db 0,0,194,1,62,127,19,14,38,1,62,19  ; n649 t=61.097s dur=450ms, freq=294Hz, sample=62, buffer_id=13:3E
    db 120,0,194,1,50,127,20,15,147,0,50,20  ; n650 t=61.097s dur=450ms, freq=147Hz, sample=50, buffer_id=14:32
    db 120,0,150,0,54,127,18,4,208,0,54,18  ; n651 t=61.217s dur=150ms, freq=208Hz, sample=54, buffer_id=12:36
    db 0,0,210,0,78,127,16,3,228,2,78,16  ; n652 t=61.337s dur=210ms, freq=740Hz, sample=78, buffer_id=10:4E
    db 0,0,210,0,66,127,17,0,114,1,66,16  ; n653 t=61.337s dur=210ms, freq=370Hz, sample=66, buffer_id=10:42
    db 240,0,176,0,54,127,18,7,220,0,54,18  ; n654 t=61.337s dur=176ms, freq=220Hz, sample=54, buffer_id=12:36
    db 0,0,162,3,71,127,3,1,184,1,71,3  ; n655 t=61.577s dur=930ms, freq=440Hz, sample=71, buffer_id=03:47
    db 0,0,145,2,78,127,3,2,112,3,78,3  ; n656 t=61.577s dur=657ms, freq=880Hz, sample=78, buffer_id=03:4E
    db 0,0,194,1,78,127,16,4,112,3,78,16  ; n657 t=61.577s dur=450ms, freq=880Hz, sample=78, buffer_id=10:4E
    db 0,0,194,1,69,127,17,5,184,1,69,16  ; n658 t=61.577s dur=450ms, freq=440Hz, sample=69, buffer_id=10:45
    db 0,0,138,1,47,127,19,6,147,0,47,19  ; n659 t=61.577s dur=394ms, freq=147Hz, sample=47, buffer_id=13:2F
    db 224,1,138,1,35,127,20,8,73,0,35,20  ; n660 t=61.577s dur=394ms, freq=73Hz, sample=35, buffer_id=14:23
    db 0,0,100,0,78,127,2,0,228,2,78,2  ; n661 t=62.057s dur=100ms, freq=740Hz, sample=78, buffer_id=02:4E
    db 0,0,100,0,70,127,4,3,184,1,70,4  ; n662 t=62.057s dur=100ms, freq=440Hz, sample=70, buffer_id=04:46
    db 0,0,100,0,74,127,4,7,75,2,74,4  ; n663 t=62.057s dur=100ms, freq=587Hz, sample=74, buffer_id=04:4A
    db 0,0,120,0,54,127,7,9,185,0,54,7  ; n664 t=62.057s dur=120ms, freq=185Hz, sample=54, buffer_id=07:36
    db 0,0,120,0,66,127,7,10,114,1,66,7  ; n665 t=62.057s dur=120ms, freq=370Hz, sample=66, buffer_id=07:42
    db 0,0,120,0,57,127,8,11,220,0,57,7  ; n666 t=62.057s dur=120ms, freq=220Hz, sample=57, buffer_id=07:39
    db 0,0,120,0,62,127,8,12,38,1,62,7  ; n667 t=62.057s dur=120ms, freq=294Hz, sample=62, buffer_id=07:3E
    db 0,0,150,0,54,127,18,14,220,0,54,18  ; n668 t=62.057s dur=150ms, freq=220Hz, sample=54, buffer_id=12:36
    db 0,0,194,1,62,127,19,13,38,1,62,19  ; n669 t=62.057s dur=450ms, freq=294Hz, sample=62, buffer_id=13:3E
    db 120,0,194,1,50,127,20,16,147,0,50,20  ; n670 t=62.057s dur=450ms, freq=147Hz, sample=50, buffer_id=14:32
    db 120,0,150,0,54,127,18,6,208,0,54,18  ; n671 t=62.177s dur=150ms, freq=208Hz, sample=54, buffer_id=12:36
    db 240,0,176,0,54,127,18,4,220,0,54,18  ; n672 t=62.297s dur=176ms, freq=220Hz, sample=54, buffer_id=12:36
    db 0,0,100,0,71,127,3,0,238,1,71,3  ; n673 t=62.537s dur=100ms, freq=494Hz, sample=71, buffer_id=03:47
    db 0,0,100,0,59,127,4,2,247,0,59,4  ; n674 t=62.537s dur=100ms, freq=247Hz, sample=59, buffer_id=04:3B
    db 0,0,100,0,42,127,5,3,92,0,42,5  ; n675 t=62.537s dur=100ms, freq=92Hz, sample=42, buffer_id=05:2A
    db 0,0,100,0,35,127,6,5,62,0,35,5  ; n676 t=62.537s dur=100ms, freq=62Hz, sample=35, buffer_id=05:23
    db 0,0,194,1,47,127,19,6,123,0,47,19  ; n677 t=62.537s dur=450ms, freq=123Hz, sample=47, buffer_id=13:2F
    db 240,0,194,1,35,127,20,7,62,0,35,20  ; n678 t=62.537s dur=450ms, freq=62Hz, sample=35, buffer_id=14:23
    db 0,0,100,0,73,127,3,1,42,2,73,3  ; n679 t=62.777s dur=100ms, freq=554Hz, sample=73, buffer_id=03:49
    db 240,0,100,0,61,127,4,4,21,1,61,4  ; n680 t=62.777s dur=100ms, freq=277Hz, sample=61, buffer_id=04:3D
    db 0,0,100,0,74,127,3,0,75,2,74,3  ; n681 t=63.017s dur=100ms, freq=587Hz, sample=74, buffer_id=03:4A
    db 0,0,100,0,62,127,4,2,38,1,62,4  ; n682 t=63.017s dur=100ms, freq=294Hz, sample=62, buffer_id=04:3E
    db 0,0,100,0,54,127,5,3,185,0,54,5  ; n683 t=63.017s dur=100ms, freq=185Hz, sample=54, buffer_id=05:36
    db 0,0,100,0,50,127,6,5,147,0,50,5  ; n684 t=63.017s dur=100ms, freq=147Hz, sample=50, buffer_id=05:32
    db 0,0,120,0,54,127,7,8,185,0,54,7  ; n685 t=63.017s dur=120ms, freq=185Hz, sample=54, buffer_id=07:36
    db 0,0,120,0,66,127,7,9,114,1,66,7  ; n686 t=63.017s dur=120ms, freq=370Hz, sample=66, buffer_id=07:42
    db 0,0,120,0,62,127,8,10,38,1,62,7  ; n687 t=63.017s dur=120ms, freq=294Hz, sample=62, buffer_id=07:3E
    db 0,0,194,1,74,127,16,11,75,2,74,16  ; n688 t=63.017s dur=450ms, freq=587Hz, sample=74, buffer_id=10:4A
    db 0,0,194,1,78,127,16,12,228,2,78,16  ; n689 t=63.017s dur=450ms, freq=740Hz, sample=78, buffer_id=10:4E
    db 0,0,194,1,66,127,17,13,114,1,66,16  ; n690 t=63.017s dur=450ms, freq=370Hz, sample=66, buffer_id=10:42
    db 0,0,105,0,54,127,18,15,185,0,54,18  ; n691 t=63.017s dur=105ms, freq=185Hz, sample=54, buffer_id=12:36
    db 0,0,194,1,59,127,19,14,247,0,59,19  ; n692 t=63.017s dur=450ms, freq=247Hz, sample=59, buffer_id=13:3B
    db 96,0,194,1,47,127,20,16,123,0,47,20  ; n693 t=63.017s dur=450ms, freq=123Hz, sample=47, buffer_id=14:2F
    db 96,0,105,0,54,127,18,1,196,0,54,18  ; n694 t=63.113s dur=105ms, freq=196Hz, sample=54, buffer_id=12:36
    db 48,0,105,0,54,127,18,4,185,0,54,18  ; n695 t=63.209s dur=105ms, freq=185Hz, sample=54, buffer_id=12:36
    db 0,0,100,0,74,127,3,6,147,2,74,3  ; n696 t=63.257s dur=100ms, freq=659Hz, sample=74, buffer_id=03:4A
    db 48,0,100,0,62,127,4,7,74,1,62,4  ; n697 t=63.257s dur=100ms, freq=330Hz, sample=62, buffer_id=04:3E
    db 96,0,105,0,54,127,18,20,175,0,54,18  ; n698 t=63.305s dur=105ms, freq=175Hz, sample=54, buffer_id=12:36
    db 96,0,105,0,54,127,18,0,185,0,54,18  ; n699 t=63.401s dur=105ms, freq=185Hz, sample=54, buffer_id=12:36
    db 0,0,100,0,78,127,3,1,228,2,78,3  ; n700 t=63.497s dur=100ms, freq=740Hz, sample=78, buffer_id=03:4E
    db 0,0,100,0,66,127,4,2,114,1,66,4  ; n701 t=63.497s dur=100ms, freq=370Hz, sample=66, buffer_id=04:42
    db 0,0,100,0,42,127,5,3,92,0,42,5  ; n702 t=63.497s dur=100ms, freq=92Hz, sample=42, buffer_id=05:2A
    db 0,0,100,0,35,127,6,5,62,0,35,5  ; n703 t=63.497s dur=100ms, freq=62Hz, sample=35, buffer_id=05:23
    db 0,0,194,1,47,127,19,8,123,0,47,19  ; n704 t=63.497s dur=450ms, freq=123Hz, sample=47, buffer_id=13:2F
    db 240,0,194,1,35,127,20,9,62,0,35,20  ; n705 t=63.497s dur=450ms, freq=62Hz, sample=35, buffer_id=14:23
    db 0,0,100,0,74,127,3,0,75,2,74,3  ; n706 t=63.737s dur=100ms, freq=587Hz, sample=74, buffer_id=03:4A
    db 240,0,100,0,62,127,4,4,38,1,62,4  ; n707 t=63.737s dur=100ms, freq=294Hz, sample=62, buffer_id=04:3E
    db 0,0,100,0,78,127,3,2,228,2,78,3  ; n708 t=63.977s dur=100ms, freq=740Hz, sample=78, buffer_id=03:4E
    db 0,0,100,0,66,127,4,1,114,1,66,4  ; n709 t=63.977s dur=100ms, freq=370Hz, sample=66, buffer_id=04:42
    db 0,0,100,0,54,127,5,3,185,0,54,5  ; n710 t=63.977s dur=100ms, freq=185Hz, sample=54, buffer_id=05:36
    db 0,0,100,0,50,127,6,5,147,0,50,5  ; n711 t=63.977s dur=100ms, freq=147Hz, sample=50, buffer_id=05:32
    db 0,0,120,0,54,127,7,6,185,0,54,7  ; n712 t=63.977s dur=120ms, freq=185Hz, sample=54, buffer_id=07:36
    db 0,0,120,0,66,127,7,7,114,1,66,7  ; n713 t=63.977s dur=120ms, freq=370Hz, sample=66, buffer_id=07:42
    db 0,0,120,0,62,127,8,11,38,1,62,7  ; n714 t=63.977s dur=120ms, freq=294Hz, sample=62, buffer_id=07:3E
    db 0,0,194,1,74,127,16,10,75,2,74,16  ; n715 t=63.977s dur=450ms, freq=587Hz, sample=74, buffer_id=10:4A
    db 0,0,194,1,78,127,16,13,228,2,78,16  ; n716 t=63.977s dur=450ms, freq=740Hz, sample=78, buffer_id=10:4E
    db 0,0,194,1,66,127,17,12,114,1,66,16  ; n717 t=63.977s dur=450ms, freq=370Hz, sample=66, buffer_id=10:42
    db 0,0,105,0,54,127,18,14,185,0,54,18  ; n718 t=63.977s dur=105ms, freq=185Hz, sample=54, buffer_id=12:36
    db 0,0,194,1,59,127,19,15,247,0,59,19  ; n719 t=63.977s dur=450ms, freq=247Hz, sample=59, buffer_id=13:3B
    db 96,0,194,1,47,127,20,17,123,0,47,20  ; n720 t=63.977s dur=450ms, freq=123Hz, sample=47, buffer_id=14:2F
    db 96,0,105,0,54,127,18,0,196,0,54,18  ; n721 t=64.073s dur=105ms, freq=196Hz, sample=54, buffer_id=12:36
    db 96,0,105,0,54,127,18,4,185,0,54,18  ; n722 t=64.169s dur=105ms, freq=185Hz, sample=54, buffer_id=12:36
    db 96,0,105,0,54,127,18,8,175,0,54,18  ; n723 t=64.265s dur=105ms, freq=175Hz, sample=54, buffer_id=12:36
    db 96,0,105,0,54,127,18,1,185,0,54,18  ; n724 t=64.361s dur=105ms, freq=185Hz, sample=54, buffer_id=12:36
    db 0,0,100,0,78,127,3,0,186,2,78,3  ; n725 t=64.457s dur=100ms, freq=698Hz, sample=78, buffer_id=03:4E
    db 0,0,100,0,66,127,4,2,93,1,66,4  ; n726 t=64.457s dur=100ms, freq=349Hz, sample=66, buffer_id=04:42
    db 0,0,100,0,42,127,5,3,92,0,42,5  ; n727 t=64.457s dur=100ms, freq=92Hz, sample=42, buffer_id=05:2A
    db 0,0,100,0,35,127,6,5,62,0,35,5  ; n728 t=64.457s dur=100ms, freq=62Hz, sample=35, buffer_id=05:23
    db 0,0,194,1,47,127,19,6,123,0,47,19  ; n729 t=64.457s dur=450ms, freq=123Hz, sample=47, buffer_id=13:2F
    db 240,0,194,1,35,127,20,7,62,0,35,20  ; n730 t=64.457s dur=450ms, freq=62Hz, sample=35, buffer_id=14:23
    db 0,0,100,0,73,127,3,1,42,2,73,3  ; n731 t=64.697s dur=100ms, freq=554Hz, sample=73, buffer_id=03:49
    db 240,0,100,0,61,127,4,4,21,1,61,4  ; n732 t=64.697s dur=100ms, freq=277Hz, sample=61, buffer_id=04:3D
    db 0,0,100,0,78,127,3,2,186,2,78,3  ; n733 t=64.937s dur=100ms, freq=698Hz, sample=78, buffer_id=03:4E
    db 0,0,100,0,66,127,4,0,93,1,66,4  ; n734 t=64.937s dur=100ms, freq=349Hz, sample=66, buffer_id=04:42
    db 0,0,100,0,54,127,5,3,175,0,54,5  ; n735 t=64.937s dur=100ms, freq=175Hz, sample=54, buffer_id=05:36
    db 0,0,100,0,49,127,6,5,139,0,49,5  ; n736 t=64.937s dur=100ms, freq=139Hz, sample=49, buffer_id=05:31
    db 0,0,120,0,54,127,7,8,185,0,54,7  ; n737 t=64.937s dur=120ms, freq=185Hz, sample=54, buffer_id=07:36
    db 0,0,120,0,66,127,7,9,114,1,66,7  ; n738 t=64.937s dur=120ms, freq=370Hz, sample=66, buffer_id=07:42
    db 0,0,120,0,61,127,8,10,21,1,61,7  ; n739 t=64.937s dur=120ms, freq=277Hz, sample=61, buffer_id=07:3D
    db 0,0,120,0,66,127,8,11,93,1,66,7  ; n740 t=64.937s dur=120ms, freq=349Hz, sample=66, buffer_id=07:42
    db 0,0,194,1,73,127,16,12,42,2,73,16  ; n741 t=64.937s dur=450ms, freq=554Hz, sample=73, buffer_id=10:49
    db 0,0,194,1,78,127,16,14,186,2,78,16  ; n742 t=64.937s dur=450ms, freq=698Hz, sample=78, buffer_id=10:4E
    db 0,0,194,1,66,127,17,13,114,1,66,16  ; n743 t=64.937s dur=450ms, freq=370Hz, sample=66, buffer_id=10:42
    db 0,0,194,1,78,127,17,15,228,2,78,16  ; n744 t=64.937s dur=450ms, freq=740Hz, sample=78, buffer_id=10:4E
    db 0,0,105,0,54,127,18,16,185,0,54,18  ; n745 t=64.937s dur=105ms, freq=185Hz, sample=54, buffer_id=12:36
    db 0,0,194,1,59,127,19,17,247,0,59,19  ; n746 t=64.937s dur=450ms, freq=247Hz, sample=59, buffer_id=13:3B
    db 96,0,194,1,47,127,20,18,123,0,47,20  ; n747 t=64.937s dur=450ms, freq=123Hz, sample=47, buffer_id=14:2F
    db 96,0,105,0,54,127,18,1,196,0,54,18  ; n748 t=65.033s dur=105ms, freq=196Hz, sample=54, buffer_id=12:36
    db 96,0,105,0,54,127,18,4,185,0,54,18  ; n749 t=65.129s dur=105ms, freq=185Hz, sample=54, buffer_id=12:36
    db 96,0,105,0,54,127,18,6,175,0,54,18  ; n750 t=65.225s dur=105ms, freq=175Hz, sample=54, buffer_id=12:36
    db 96,0,105,0,54,127,18,0,185,0,54,18  ; n751 t=65.321s dur=105ms, freq=185Hz, sample=54, buffer_id=12:36
    db 0,0,100,0,74,127,3,1,147,2,74,3  ; n752 t=65.417s dur=100ms, freq=659Hz, sample=74, buffer_id=03:4A
    db 0,0,100,0,62,127,4,2,74,1,62,4  ; n753 t=65.417s dur=100ms, freq=330Hz, sample=62, buffer_id=04:3E
    db 0,0,100,0,42,127,5,3,92,0,42,5  ; n754 t=65.417s dur=100ms, freq=92Hz, sample=42, buffer_id=05:2A
    db 0,0,100,0,35,127,6,5,62,0,35,5  ; n755 t=65.417s dur=100ms, freq=62Hz, sample=35, buffer_id=05:23
    db 0,0,194,1,47,127,19,7,123,0,47,19  ; n756 t=65.417s dur=450ms, freq=123Hz, sample=47, buffer_id=13:2F
    db 240,0,194,1,35,127,20,8,62,0,35,20  ; n757 t=65.417s dur=450ms, freq=62Hz, sample=35, buffer_id=14:23
    db 0,0,100,0,71,127,3,0,11,2,71,3  ; n758 t=65.657s dur=100ms, freq=523Hz, sample=71, buffer_id=03:47
    db 240,0,100,0,59,127,4,4,6,1,59,4  ; n759 t=65.657s dur=100ms, freq=262Hz, sample=59, buffer_id=04:3B
    db 0,0,100,0,74,127,3,2,147,2,74,3  ; n760 t=65.897s dur=100ms, freq=659Hz, sample=74, buffer_id=03:4A
    db 0,0,100,0,62,127,4,1,74,1,62,4  ; n761 t=65.897s dur=100ms, freq=330Hz, sample=62, buffer_id=04:3E
    db 0,0,100,0,50,127,5,3,165,0,50,5  ; n762 t=65.897s dur=100ms, freq=165Hz, sample=50, buffer_id=05:32
    db 0,0,100,0,47,127,6,5,131,0,47,5  ; n763 t=65.897s dur=100ms, freq=131Hz, sample=47, buffer_id=05:2F
    db 0,0,120,0,54,127,7,6,185,0,54,7  ; n764 t=65.897s dur=120ms, freq=185Hz, sample=54, buffer_id=07:36
    db 0,0,120,0,66,127,7,10,114,1,66,7  ; n765 t=65.897s dur=120ms, freq=370Hz, sample=66, buffer_id=07:42
    db 0,0,120,0,59,127,8,9,6,1,59,7  ; n766 t=65.897s dur=120ms, freq=262Hz, sample=59, buffer_id=07:3B
    db 0,0,106,0,62,127,8,11,74,1,62,7  ; n767 t=65.897s dur=106ms, freq=330Hz, sample=62, buffer_id=07:3E
    db 0,0,194,1,73,127,16,13,11,2,73,16  ; n768 t=65.897s dur=450ms, freq=523Hz, sample=73, buffer_id=10:49
    db 0,0,144,1,74,127,16,12,147,2,74,16  ; n769 t=65.897s dur=400ms, freq=659Hz, sample=74, buffer_id=10:4A
    db 0,0,194,1,66,127,17,14,114,1,66,16  ; n770 t=65.897s dur=450ms, freq=370Hz, sample=66, buffer_id=10:42
    db 0,0,194,1,78,127,17,16,228,2,78,16  ; n771 t=65.897s dur=450ms, freq=740Hz, sample=78, buffer_id=10:4E
    db 0,0,105,0,54,127,18,15,185,0,54,18  ; n772 t=65.897s dur=105ms, freq=185Hz, sample=54, buffer_id=12:36
    db 0,0,194,1,59,127,19,18,247,0,59,19  ; n773 t=65.897s dur=450ms, freq=247Hz, sample=59, buffer_id=13:3B
    db 96,0,194,1,47,127,20,17,123,0,47,20  ; n774 t=65.897s dur=450ms, freq=123Hz, sample=47, buffer_id=14:2F
    db 96,0,105,0,54,127,18,0,196,0,54,18  ; n775 t=65.993s dur=105ms, freq=196Hz, sample=54, buffer_id=12:36
    db 96,0,105,0,54,127,18,4,185,0,54,18  ; n776 t=66.089s dur=105ms, freq=185Hz, sample=54, buffer_id=12:36
    db 96,0,105,0,54,127,18,7,175,0,54,18  ; n777 t=66.185s dur=105ms, freq=175Hz, sample=54, buffer_id=12:36
    db 96,0,105,0,54,127,18,1,185,0,54,18  ; n778 t=66.281s dur=105ms, freq=185Hz, sample=54, buffer_id=12:36
    db 0,0,100,0,71,127,3,0,238,1,71,3  ; n779 t=66.377s dur=100ms, freq=494Hz, sample=71, buffer_id=03:47
    db 0,0,100,0,59,127,4,2,247,0,59,4  ; n780 t=66.377s dur=100ms, freq=247Hz, sample=59, buffer_id=04:3B
    db 0,0,100,0,42,127,5,3,92,0,42,5  ; n781 t=66.377s dur=100ms, freq=92Hz, sample=42, buffer_id=05:2A
    db 0,0,100,0,35,127,6,5,62,0,35,5  ; n782 t=66.377s dur=100ms, freq=62Hz, sample=35, buffer_id=05:23
    db 0,0,194,1,47,127,19,6,123,0,47,19  ; n783 t=66.377s dur=450ms, freq=123Hz, sample=47, buffer_id=13:2F
    db 240,0,194,1,35,127,20,9,62,0,35,20  ; n784 t=66.377s dur=450ms, freq=62Hz, sample=35, buffer_id=14:23
    db 0,0,100,0,73,127,3,1,42,2,73,3  ; n785 t=66.617s dur=100ms, freq=554Hz, sample=73, buffer_id=03:49
    db 240,0,100,0,61,127,4,4,21,1,61,4  ; n786 t=66.617s dur=100ms, freq=277Hz, sample=61, buffer_id=04:3D
    db 0,0,100,0,74,127,3,0,75,2,74,3  ; n787 t=66.857s dur=100ms, freq=587Hz, sample=74, buffer_id=03:4A
    db 0,0,100,0,62,127,4,2,38,1,62,4  ; n788 t=66.857s dur=100ms, freq=294Hz, sample=62, buffer_id=04:3E
    db 0,0,100,0,50,127,5,3,147,0,50,5  ; n789 t=66.857s dur=100ms, freq=147Hz, sample=50, buffer_id=05:32
    db 0,0,100,0,47,127,6,5,123,0,47,5  ; n790 t=66.857s dur=100ms, freq=123Hz, sample=47, buffer_id=05:2F
    db 0,0,120,0,54,127,7,7,185,0,54,7  ; n791 t=66.857s dur=120ms, freq=185Hz, sample=54, buffer_id=07:36
    db 0,0,120,0,66,127,7,8,114,1,66,7  ; n792 t=66.857s dur=120ms, freq=370Hz, sample=66, buffer_id=07:42
    db 0,0,120,0,59,127,8,10,247,0,59,7  ; n793 t=66.857s dur=120ms, freq=247Hz, sample=59, buffer_id=07:3B
    db 0,0,120,0,62,127,8,12,38,1,62,7  ; n794 t=66.857s dur=120ms, freq=294Hz, sample=62, buffer_id=07:3E
    db 0,0,145,1,70,127,16,11,238,1,70,16  ; n795 t=66.857s dur=401ms, freq=494Hz, sample=70, buffer_id=10:46
    db 0,0,194,1,74,127,16,13,75,2,74,16  ; n796 t=66.857s dur=450ms, freq=587Hz, sample=74, buffer_id=10:4A
    db 0,0,194,1,66,127,17,15,114,1,66,16  ; n797 t=66.857s dur=450ms, freq=370Hz, sample=66, buffer_id=10:42
    db 0,0,194,1,78,127,17,14,228,2,78,16  ; n798 t=66.857s dur=450ms, freq=740Hz, sample=78, buffer_id=10:4E
    db 0,0,105,0,54,127,18,16,185,0,54,18  ; n799 t=66.857s dur=105ms, freq=185Hz, sample=54, buffer_id=12:36
    db 0,0,194,1,59,127,19,17,247,0,59,19  ; n800 t=66.857s dur=450ms, freq=247Hz, sample=59, buffer_id=13:3B
    db 96,0,194,1,47,127,20,18,123,0,47,20  ; n801 t=66.857s dur=450ms, freq=123Hz, sample=47, buffer_id=14:2F
    db 96,0,105,0,54,127,18,1,196,0,54,18  ; n802 t=66.953s dur=105ms, freq=196Hz, sample=54, buffer_id=12:36
    db 48,0,105,0,54,127,18,4,185,0,54,18  ; n803 t=67.049s dur=105ms, freq=185Hz, sample=54, buffer_id=12:36
    db 0,0,100,0,74,127,3,6,147,2,74,3  ; n804 t=67.097s dur=100ms, freq=659Hz, sample=74, buffer_id=03:4A
    db 48,0,100,0,62,127,4,9,74,1,62,4  ; n805 t=67.097s dur=100ms, freq=330Hz, sample=62, buffer_id=04:3E
    db 96,0,105,0,54,127,18,21,175,0,54,18  ; n806 t=67.145s dur=105ms, freq=175Hz, sample=54, buffer_id=12:36
    db 96,0,105,0,54,127,18,0,185,0,54,18  ; n807 t=67.241s dur=105ms, freq=185Hz, sample=54, buffer_id=12:36
    db 0,0,100,0,78,127,3,1,228,2,78,3  ; n808 t=67.337s dur=100ms, freq=740Hz, sample=78, buffer_id=03:4E
    db 0,0,100,0,66,127,4,2,114,1,66,4  ; n809 t=67.337s dur=100ms, freq=370Hz, sample=66, buffer_id=04:42
    db 0,0,100,0,42,127,5,3,92,0,42,5  ; n810 t=67.337s dur=100ms, freq=92Hz, sample=42, buffer_id=05:2A
    db 0,0,100,0,35,127,6,5,62,0,35,5  ; n811 t=67.337s dur=100ms, freq=62Hz, sample=35, buffer_id=05:23
    db 0,0,194,1,47,127,19,7,123,0,47,19  ; n812 t=67.337s dur=450ms, freq=123Hz, sample=47, buffer_id=13:2F
    db 240,0,194,1,35,127,20,8,62,0,35,20  ; n813 t=67.337s dur=450ms, freq=62Hz, sample=35, buffer_id=14:23
    db 0,0,100,0,74,127,3,0,75,2,74,3  ; n814 t=67.577s dur=100ms, freq=587Hz, sample=74, buffer_id=03:4A
    db 240,0,100,0,62,127,4,4,38,1,62,4  ; n815 t=67.577s dur=100ms, freq=294Hz, sample=62, buffer_id=04:3E
    db 0,0,100,0,78,127,3,2,228,2,78,3  ; n816 t=67.817s dur=100ms, freq=740Hz, sample=78, buffer_id=03:4E
    db 0,0,100,0,66,127,4,1,114,1,66,4  ; n817 t=67.817s dur=100ms, freq=370Hz, sample=66, buffer_id=04:42
    db 0,0,100,0,50,127,5,3,147,0,50,5  ; n818 t=67.817s dur=100ms, freq=147Hz, sample=50, buffer_id=05:32
    db 0,0,100,0,47,127,6,5,123,0,47,5  ; n819 t=67.817s dur=100ms, freq=123Hz, sample=47, buffer_id=05:2F
    db 0,0,120,0,54,127,7,6,185,0,54,7  ; n820 t=67.817s dur=120ms, freq=185Hz, sample=54, buffer_id=07:36
    db 0,0,120,0,66,127,7,9,114,1,66,7  ; n821 t=67.817s dur=120ms, freq=370Hz, sample=66, buffer_id=07:42
    db 0,0,120,0,59,127,8,11,247,0,59,7  ; n822 t=67.817s dur=120ms, freq=247Hz, sample=59, buffer_id=07:3B
    db 0,0,120,0,62,127,8,10,38,1,62,7  ; n823 t=67.817s dur=120ms, freq=294Hz, sample=62, buffer_id=07:3E
    db 0,0,145,1,70,127,16,12,238,1,70,16  ; n824 t=67.817s dur=401ms, freq=494Hz, sample=70, buffer_id=10:46
    db 0,0,194,1,74,127,16,14,75,2,74,16  ; n825 t=67.817s dur=450ms, freq=587Hz, sample=74, buffer_id=10:4A
    db 0,0,194,1,66,127,17,13,114,1,66,16  ; n826 t=67.817s dur=450ms, freq=370Hz, sample=66, buffer_id=10:42
    db 0,0,194,1,78,127,17,15,228,2,78,16  ; n827 t=67.817s dur=450ms, freq=740Hz, sample=78, buffer_id=10:4E
    db 0,0,105,0,54,127,18,17,185,0,54,18  ; n828 t=67.817s dur=105ms, freq=185Hz, sample=54, buffer_id=12:36
    db 0,0,194,1,59,127,19,16,247,0,59,19  ; n829 t=67.817s dur=450ms, freq=247Hz, sample=59, buffer_id=13:3B
    db 96,0,194,1,47,127,20,19,123,0,47,20  ; n830 t=67.817s dur=450ms, freq=123Hz, sample=47, buffer_id=14:2F
    db 96,0,105,0,54,127,18,0,196,0,54,18  ; n831 t=67.913s dur=105ms, freq=196Hz, sample=54, buffer_id=12:36
    db 48,0,105,0,54,127,18,4,185,0,54,18  ; n832 t=68.009s dur=105ms, freq=185Hz, sample=54, buffer_id=12:36
    db 0,0,100,0,85,127,3,7,220,3,85,3  ; n833 t=68.057s dur=100ms, freq=988Hz, sample=85, buffer_id=03:55
    db 48,0,100,0,70,127,4,8,238,1,70,4  ; n834 t=68.057s dur=100ms, freq=494Hz, sample=70, buffer_id=04:46
    db 96,0,105,0,54,127,18,18,175,0,54,18  ; n835 t=68.105s dur=105ms, freq=175Hz, sample=54, buffer_id=12:36
    db 96,0,105,0,54,127,18,1,185,0,54,18  ; n836 t=68.201s dur=105ms, freq=185Hz, sample=54, buffer_id=12:36
    db 0,0,100,0,78,127,3,0,112,3,78,3  ; n837 t=68.297s dur=100ms, freq=880Hz, sample=78, buffer_id=03:4E
    db 0,0,100,0,70,127,4,2,184,1,70,4  ; n838 t=68.297s dur=100ms, freq=440Hz, sample=70, buffer_id=04:46
    db 0,0,100,0,47,127,5,3,110,0,47,5  ; n839 t=68.297s dur=100ms, freq=110Hz, sample=47, buffer_id=05:2F
    db 0,0,100,0,35,127,6,5,73,0,35,5  ; n840 t=68.297s dur=100ms, freq=73Hz, sample=35, buffer_id=05:23
    db 0,0,138,1,47,127,19,6,147,0,47,19  ; n841 t=68.297s dur=394ms, freq=147Hz, sample=47, buffer_id=13:2F
    db 240,0,138,1,35,127,20,9,73,0,35,20  ; n842 t=68.297s dur=394ms, freq=73Hz, sample=35, buffer_id=14:23
    db 0,0,100,0,78,127,3,1,228,2,78,3  ; n843 t=68.537s dur=100ms, freq=740Hz, sample=78, buffer_id=03:4E
    db 240,0,100,0,66,127,4,4,114,1,66,4  ; n844 t=68.537s dur=100ms, freq=370Hz, sample=66, buffer_id=04:42
    db 0,0,100,0,74,127,3,0,75,2,74,3  ; n845 t=68.777s dur=100ms, freq=587Hz, sample=74, buffer_id=03:4A
    db 0,0,100,0,62,127,4,2,38,1,62,4  ; n846 t=68.777s dur=100ms, freq=294Hz, sample=62, buffer_id=04:3E
    db 0,0,100,0,50,127,5,3,147,0,50,5  ; n847 t=68.777s dur=100ms, freq=147Hz, sample=50, buffer_id=05:32
    db 0,0,100,0,47,127,6,5,110,0,47,5  ; n848 t=68.777s dur=100ms, freq=110Hz, sample=47, buffer_id=05:2F
    db 0,0,120,0,54,127,7,7,185,0,54,7  ; n849 t=68.777s dur=120ms, freq=185Hz, sample=54, buffer_id=07:36
    db 0,0,120,0,66,127,7,8,114,1,66,7  ; n850 t=68.777s dur=120ms, freq=370Hz, sample=66, buffer_id=07:42
    db 0,0,120,0,57,127,8,10,220,0,57,7  ; n851 t=68.777s dur=120ms, freq=220Hz, sample=57, buffer_id=07:39
    db 0,0,120,0,62,127,8,11,38,1,62,7  ; n852 t=68.777s dur=120ms, freq=294Hz, sample=62, buffer_id=07:3E
    db 0,0,194,1,69,127,16,12,184,1,69,16  ; n853 t=68.777s dur=450ms, freq=440Hz, sample=69, buffer_id=10:45
    db 0,0,194,1,74,127,16,13,75,2,74,16  ; n854 t=68.777s dur=450ms, freq=587Hz, sample=74, buffer_id=10:4A
    db 0,0,194,1,66,127,17,14,114,1,66,16  ; n855 t=68.777s dur=450ms, freq=370Hz, sample=66, buffer_id=10:42
    db 0,0,194,1,78,127,17,16,228,2,78,16  ; n856 t=68.777s dur=450ms, freq=740Hz, sample=78, buffer_id=10:4E
    db 0,0,105,0,54,127,18,15,220,0,54,18  ; n857 t=68.777s dur=105ms, freq=220Hz, sample=54, buffer_id=12:36
    db 0,0,194,1,62,127,19,17,38,1,62,19  ; n858 t=68.777s dur=450ms, freq=294Hz, sample=62, buffer_id=13:3E
    db 96,0,194,1,50,127,20,18,147,0,50,20  ; n859 t=68.777s dur=450ms, freq=147Hz, sample=50, buffer_id=14:32
    db 96,0,105,0,54,127,18,1,247,0,54,18  ; n860 t=68.873s dur=105ms, freq=247Hz, sample=54, buffer_id=12:36
    db 48,0,105,0,54,127,18,4,220,0,54,18  ; n861 t=68.969s dur=105ms, freq=220Hz, sample=54, buffer_id=12:36
    db 0,0,100,0,78,127,3,6,228,2,78,3  ; n862 t=69.017s dur=100ms, freq=740Hz, sample=78, buffer_id=03:4E
    db 48,0,100,0,66,127,4,9,114,1,66,4  ; n863 t=69.017s dur=100ms, freq=370Hz, sample=66, buffer_id=04:42
    db 96,0,105,0,54,127,18,19,208,0,54,18  ; n864 t=69.065s dur=105ms, freq=208Hz, sample=54, buffer_id=12:36
    db 96,0,105,0,54,127,18,0,220,0,54,18  ; n865 t=69.161s dur=105ms, freq=220Hz, sample=54, buffer_id=12:36
    db 0,0,145,2,78,127,3,1,112,3,78,3  ; n866 t=69.257s dur=657ms, freq=880Hz, sample=78, buffer_id=03:4E
    db 0,0,162,3,70,127,4,2,184,1,70,4  ; n867 t=69.257s dur=930ms, freq=440Hz, sample=70, buffer_id=04:46
    db 0,0,100,0,47,127,5,3,110,0,47,5  ; n868 t=69.257s dur=100ms, freq=110Hz, sample=47, buffer_id=05:2F
    db 0,0,100,0,35,127,6,5,73,0,35,5  ; n869 t=69.257s dur=100ms, freq=73Hz, sample=35, buffer_id=05:23
    db 0,0,138,1,47,127,19,7,147,0,47,19  ; n870 t=69.257s dur=394ms, freq=147Hz, sample=47, buffer_id=13:2F
    db 224,1,138,1,35,127,20,8,73,0,35,20  ; n871 t=69.257s dur=394ms, freq=73Hz, sample=35, buffer_id=14:23
    db 0,0,100,0,50,127,5,0,147,0,50,5  ; n872 t=69.737s dur=100ms, freq=147Hz, sample=50, buffer_id=05:32
    db 0,0,100,0,47,127,6,4,110,0,47,5  ; n873 t=69.737s dur=100ms, freq=110Hz, sample=47, buffer_id=05:2F
    db 0,0,120,0,54,127,7,3,185,0,54,7  ; n874 t=69.737s dur=120ms, freq=185Hz, sample=54, buffer_id=07:36
    db 0,0,120,0,66,127,7,5,114,1,66,7  ; n875 t=69.737s dur=120ms, freq=370Hz, sample=66, buffer_id=07:42
    db 0,0,120,0,57,127,8,6,220,0,57,7  ; n876 t=69.737s dur=120ms, freq=220Hz, sample=57, buffer_id=07:39
    db 0,0,120,0,62,127,8,9,38,1,62,7  ; n877 t=69.737s dur=120ms, freq=294Hz, sample=62, buffer_id=07:3E
    db 0,0,194,1,69,127,16,10,184,1,69,16  ; n878 t=69.737s dur=450ms, freq=440Hz, sample=69, buffer_id=10:45
    db 0,0,194,1,74,127,16,11,75,2,74,16  ; n879 t=69.737s dur=450ms, freq=587Hz, sample=74, buffer_id=10:4A
    db 0,0,194,1,66,127,17,12,114,1,66,16  ; n880 t=69.737s dur=450ms, freq=370Hz, sample=66, buffer_id=10:42
    db 0,0,194,1,78,127,17,13,228,2,78,16  ; n881 t=69.737s dur=450ms, freq=740Hz, sample=78, buffer_id=10:4E
    db 0,0,105,0,54,127,18,14,220,0,54,18  ; n882 t=69.737s dur=105ms, freq=220Hz, sample=54, buffer_id=12:36
    db 0,0,194,1,62,127,19,15,38,1,62,19  ; n883 t=69.737s dur=450ms, freq=294Hz, sample=62, buffer_id=13:3E
    db 96,0,194,1,50,127,20,16,147,0,50,20  ; n884 t=69.737s dur=450ms, freq=147Hz, sample=50, buffer_id=14:32
    db 96,0,105,0,54,127,18,17,247,0,54,18  ; n885 t=69.833s dur=105ms, freq=247Hz, sample=54, buffer_id=12:36
    db 96,0,105,0,54,127,18,7,220,0,54,18  ; n886 t=69.929s dur=105ms, freq=220Hz, sample=54, buffer_id=12:36
    db 96,0,105,0,54,127,18,8,208,0,54,18  ; n887 t=70.025s dur=105ms, freq=208Hz, sample=54, buffer_id=12:36
    db 96,0,105,0,54,127,18,0,220,0,54,18  ; n888 t=70.121s dur=105ms, freq=220Hz, sample=54, buffer_id=12:36
    db 0,0,210,0,78,127,16,1,228,2,78,16  ; n889 t=70.217s dur=210ms, freq=740Hz, sample=78, buffer_id=10:4E
    db 0,0,210,0,66,127,17,3,114,1,66,16  ; n890 t=70.217s dur=210ms, freq=370Hz, sample=66, buffer_id=10:42
    db 0,0,185,1,54,127,19,4,185,0,54,19  ; n891 t=70.217s dur=441ms, freq=185Hz, sample=54, buffer_id=13:36
    db 240,0,185,1,42,127,20,5,92,0,42,20  ; n892 t=70.217s dur=441ms, freq=92Hz, sample=42, buffer_id=14:2A
    db 0,0,201,0,78,127,16,0,63,3,78,16  ; n893 t=70.457s dur=201ms, freq=831Hz, sample=78, buffer_id=10:4E
    db 231,0,201,0,69,127,17,2,159,1,69,16  ; n894 t=70.457s dur=201ms, freq=415Hz, sample=69, buffer_id=10:45
    db 0,0,100,0,78,127,2,1,228,2,78,2  ; n895 t=70.688s dur=100ms, freq=740Hz, sample=78, buffer_id=02:4E
    db 0,0,100,0,70,127,4,3,210,1,70,4  ; n896 t=70.688s dur=100ms, freq=466Hz, sample=70, buffer_id=04:46
    db 0,0,100,0,73,127,4,6,42,2,73,4  ; n897 t=70.688s dur=100ms, freq=554Hz, sample=73, buffer_id=04:49
    db 0,0,114,0,54,127,7,7,185,0,54,7  ; n898 t=70.688s dur=114ms, freq=185Hz, sample=54, buffer_id=07:36
    db 0,0,114,0,66,127,7,8,114,1,66,7  ; n899 t=70.688s dur=114ms, freq=370Hz, sample=66, buffer_id=07:42
    db 0,0,114,0,58,127,8,9,233,0,58,7  ; n900 t=70.688s dur=114ms, freq=233Hz, sample=58, buffer_id=07:3A
    db 0,0,114,0,61,127,8,10,21,1,61,7  ; n901 t=70.688s dur=114ms, freq=277Hz, sample=61, buffer_id=07:3D
    db 0,0,201,0,85,127,16,11,164,3,85,16  ; n902 t=70.688s dur=201ms, freq=932Hz, sample=85, buffer_id=10:55
    db 0,0,201,0,70,127,17,12,210,1,70,16  ; n903 t=70.688s dur=201ms, freq=466Hz, sample=70, buffer_id=10:46
    db 0,0,143,0,49,127,18,13,139,0,49,18  ; n904 t=70.688s dur=143ms, freq=139Hz, sample=49, buffer_id=12:31
    db 0,0,174,1,66,127,19,14,114,1,66,19  ; n905 t=70.688s dur=430ms, freq=370Hz, sample=66, buffer_id=13:42
    db 115,0,174,1,54,127,20,15,185,0,54,20  ; n906 t=70.688s dur=430ms, freq=185Hz, sample=54, buffer_id=14:36
    db 115,0,143,0,48,127,18,16,131,0,48,18  ; n907 t=70.803s dur=143ms, freq=131Hz, sample=48, buffer_id=12:30
    db 0,0,200,0,85,127,16,0,220,3,85,16  ; n908 t=70.918s dur=200ms, freq=988Hz, sample=85, buffer_id=10:55
    db 0,0,200,0,70,127,17,2,238,1,70,16  ; n909 t=70.918s dur=200ms, freq=494Hz, sample=70, buffer_id=10:46
    db 229,0,200,0,49,127,18,4,139,0,49,18  ; n910 t=70.918s dur=200ms, freq=139Hz, sample=49, buffer_id=12:31
    db 0,0,189,0,85,127,16,1,85,4,85,16  ; n911 t=71.147s dur=189ms, freq=1109Hz, sample=85, buffer_id=10:55
    db 0,0,200,0,73,127,17,3,42,2,73,16  ; n912 t=71.147s dur=200ms, freq=554Hz, sample=73, buffer_id=10:49
    db 0,0,172,1,54,127,19,5,185,0,54,19  ; n913 t=71.147s dur=428ms, freq=185Hz, sample=54, buffer_id=13:36
    db 229,0,172,1,42,127,20,6,92,0,42,20  ; n914 t=71.147s dur=428ms, freq=92Hz, sample=42, buffer_id=14:2A
    db 0,0,199,0,85,127,16,2,164,3,85,16  ; n915 t=71.376s dur=199ms, freq=932Hz, sample=85, buffer_id=10:55
    db 228,0,199,0,70,127,17,0,210,1,70,16  ; n916 t=71.376s dur=199ms, freq=466Hz, sample=70, buffer_id=10:46
    db 0,0,100,0,78,127,2,1,228,2,78,2  ; n917 t=71.604s dur=100ms, freq=740Hz, sample=78, buffer_id=02:4E
    db 0,0,100,0,70,127,4,3,210,1,70,4  ; n918 t=71.604s dur=100ms, freq=466Hz, sample=70, buffer_id=04:46
    db 0,0,100,0,73,127,4,4,42,2,73,4  ; n919 t=71.604s dur=100ms, freq=554Hz, sample=73, buffer_id=04:49
    db 0,0,113,0,54,127,7,8,185,0,54,7  ; n920 t=71.604s dur=113ms, freq=185Hz, sample=54, buffer_id=07:36
    db 0,0,113,0,66,127,7,7,114,1,66,7  ; n921 t=71.604s dur=113ms, freq=370Hz, sample=66, buffer_id=07:42
    db 0,0,113,0,58,127,8,10,233,0,58,7  ; n922 t=71.604s dur=113ms, freq=233Hz, sample=58, buffer_id=07:3A
    db 0,0,113,0,61,127,8,9,21,1,61,7  ; n923 t=71.604s dur=113ms, freq=277Hz, sample=61, buffer_id=07:3D
    db 0,0,189,0,85,127,16,12,85,4,85,16  ; n924 t=71.604s dur=189ms, freq=1109Hz, sample=85, buffer_id=10:55
    db 0,0,170,1,73,127,17,11,42,2,73,16  ; n925 t=71.604s dur=426ms, freq=554Hz, sample=73, buffer_id=10:49
    db 0,0,142,0,49,127,18,14,139,0,49,18  ; n926 t=71.604s dur=142ms, freq=139Hz, sample=49, buffer_id=12:31
    db 0,0,170,1,66,127,19,13,114,1,66,19  ; n927 t=71.604s dur=426ms, freq=370Hz, sample=66, buffer_id=13:42
    db 114,0,170,1,54,127,20,16,185,0,54,20  ; n928 t=71.604s dur=426ms, freq=185Hz, sample=54, buffer_id=14:36
    db 114,0,142,0,48,127,18,15,131,0,48,18  ; n929 t=71.718s dur=142ms, freq=131Hz, sample=48, buffer_id=12:30
    db 228,0,199,0,49,127,18,0,139,0,49,18  ; n930 t=71.832s dur=199ms, freq=139Hz, sample=49, buffer_id=12:31
    db 0,0,159,0,86,127,16,1,151,4,86,16  ; n931 t=72.060s dur=159ms, freq=1175Hz, sample=86, buffer_id=10:56
    db 0,0,198,0,74,127,17,2,75,2,74,16  ; n932 t=72.060s dur=198ms, freq=587Hz, sample=74, buffer_id=10:4A
    db 0,0,138,1,47,127,19,3,147,0,47,19  ; n933 t=72.060s dur=394ms, freq=147Hz, sample=47, buffer_id=13:2F
    db 227,0,138,1,35,127,20,4,73,0,35,20  ; n934 t=72.060s dur=394ms, freq=73Hz, sample=35, buffer_id=14:23
    db 0,0,198,0,85,127,16,0,164,3,85,16  ; n935 t=72.287s dur=198ms, freq=932Hz, sample=85, buffer_id=10:55
    db 227,0,198,0,70,127,17,5,210,1,70,16  ; n936 t=72.287s dur=198ms, freq=466Hz, sample=70, buffer_id=10:46
    db 0,0,100,0,78,127,2,1,228,2,78,2  ; n937 t=72.513s dur=100ms, freq=740Hz, sample=78, buffer_id=02:4E
    db 0,0,100,0,70,127,4,2,210,1,70,4  ; n938 t=72.513s dur=100ms, freq=466Hz, sample=70, buffer_id=04:46
    db 0,0,100,0,74,127,4,6,75,2,74,4  ; n939 t=72.513s dur=100ms, freq=587Hz, sample=74, buffer_id=04:4A
    db 0,0,113,0,54,127,7,7,185,0,54,7  ; n940 t=72.513s dur=113ms, freq=185Hz, sample=54, buffer_id=07:36
    db 0,0,113,0,66,127,7,8,114,1,66,7  ; n941 t=72.513s dur=113ms, freq=370Hz, sample=66, buffer_id=07:42
    db 0,0,113,0,58,127,8,9,233,0,58,7  ; n942 t=72.513s dur=113ms, freq=233Hz, sample=58, buffer_id=07:3A
    db 0,0,113,0,62,127,8,10,38,1,62,7  ; n943 t=72.513s dur=113ms, freq=294Hz, sample=62, buffer_id=07:3E
    db 0,0,159,0,86,127,16,11,151,4,86,16  ; n944 t=72.513s dur=159ms, freq=1175Hz, sample=86, buffer_id=10:56
    db 0,0,167,1,74,127,17,12,75,2,74,16  ; n945 t=72.513s dur=423ms, freq=587Hz, sample=74, buffer_id=10:4A
    db 0,0,141,0,49,127,18,13,147,0,49,18  ; n946 t=72.513s dur=141ms, freq=147Hz, sample=49, buffer_id=12:31
    db 0,0,167,1,62,127,19,14,38,1,62,19  ; n947 t=72.513s dur=423ms, freq=294Hz, sample=62, buffer_id=13:3E
    db 113,0,167,1,50,127,20,15,147,0,50,20  ; n948 t=72.513s dur=423ms, freq=147Hz, sample=50, buffer_id=14:32
    db 113,0,141,0,49,127,18,16,139,0,49,18  ; n949 t=72.626s dur=141ms, freq=139Hz, sample=49, buffer_id=12:31
    db 226,0,189,0,49,127,18,0,147,0,49,18  ; n950 t=72.739s dur=189ms, freq=147Hz, sample=49, buffer_id=12:31
    db 0,0,189,0,85,127,16,1,85,4,85,16  ; n951 t=72.965s dur=189ms, freq=1109Hz, sample=85, buffer_id=10:55
    db 0,0,197,0,73,127,17,2,42,2,73,16  ; n952 t=72.965s dur=197ms, freq=554Hz, sample=73, buffer_id=10:49
    db 0,0,165,1,54,127,19,3,185,0,54,19  ; n953 t=72.965s dur=421ms, freq=185Hz, sample=54, buffer_id=13:36
    db 225,0,165,1,42,127,20,4,92,0,42,20  ; n954 t=72.965s dur=421ms, freq=92Hz, sample=42, buffer_id=14:2A
    db 0,0,196,0,85,127,16,0,164,3,85,16  ; n955 t=73.190s dur=196ms, freq=932Hz, sample=85, buffer_id=10:55
    db 225,0,196,0,70,127,17,6,210,1,70,16  ; n956 t=73.190s dur=196ms, freq=466Hz, sample=70, buffer_id=10:46
    db 0,0,100,0,78,127,2,1,228,2,78,2  ; n957 t=73.414s dur=100ms, freq=740Hz, sample=78, buffer_id=02:4E
    db 0,0,100,0,70,127,4,2,210,1,70,4  ; n958 t=73.414s dur=100ms, freq=466Hz, sample=70, buffer_id=04:46
    db 0,0,100,0,73,127,4,5,42,2,73,4  ; n959 t=73.414s dur=100ms, freq=554Hz, sample=73, buffer_id=04:49
    db 0,0,112,0,54,127,7,8,185,0,54,7  ; n960 t=73.414s dur=112ms, freq=185Hz, sample=54, buffer_id=07:36
    db 0,0,112,0,66,127,7,7,114,1,66,7  ; n961 t=73.414s dur=112ms, freq=370Hz, sample=66, buffer_id=07:42
    db 0,0,112,0,58,127,8,10,233,0,58,7  ; n962 t=73.414s dur=112ms, freq=233Hz, sample=58, buffer_id=07:3A
    db 0,0,112,0,61,127,8,9,21,1,61,7  ; n963 t=73.414s dur=112ms, freq=277Hz, sample=61, buffer_id=07:3D
    db 0,0,189,0,85,127,16,11,85,4,85,16  ; n964 t=73.414s dur=189ms, freq=1109Hz, sample=85, buffer_id=10:55
    db 0,0,163,1,73,127,17,12,42,2,73,16  ; n965 t=73.414s dur=419ms, freq=554Hz, sample=73, buffer_id=10:49
    db 0,0,140,0,49,127,18,14,139,0,49,18  ; n966 t=73.414s dur=140ms, freq=139Hz, sample=49, buffer_id=12:31
    db 0,0,163,1,66,127,19,13,114,1,66,19  ; n967 t=73.414s dur=419ms, freq=370Hz, sample=66, buffer_id=13:42
    db 112,0,163,1,54,127,20,15,185,0,54,20  ; n968 t=73.414s dur=419ms, freq=185Hz, sample=54, buffer_id=14:36
    db 112,0,140,0,48,127,18,16,131,0,48,18  ; n969 t=73.526s dur=140ms, freq=131Hz, sample=48, buffer_id=12:30
    db 224,0,195,0,49,127,18,0,139,0,49,18  ; n970 t=73.638s dur=195ms, freq=139Hz, sample=49, buffer_id=12:31
    db 0,0,195,0,78,127,16,1,228,2,78,16  ; n971 t=73.862s dur=195ms, freq=740Hz, sample=78, buffer_id=10:4E
    db 0,0,195,0,66,127,17,2,114,1,66,16  ; n972 t=73.862s dur=195ms, freq=370Hz, sample=66, buffer_id=10:42
    db 0,0,162,1,54,127,19,4,185,0,54,19  ; n973 t=73.862s dur=418ms, freq=185Hz, sample=54, buffer_id=13:36
    db 223,0,162,1,42,127,20,3,92,0,42,20  ; n974 t=73.862s dur=418ms, freq=92Hz, sample=42, buffer_id=14:2A
    db 0,0,195,0,78,127,16,0,63,3,78,16  ; n975 t=74.085s dur=195ms, freq=831Hz, sample=78, buffer_id=10:4E
    db 223,0,195,0,69,127,17,5,159,1,69,16  ; n976 t=74.085s dur=195ms, freq=415Hz, sample=69, buffer_id=10:45
    db 0,0,100,0,78,127,2,1,228,2,78,2  ; n977 t=74.308s dur=100ms, freq=740Hz, sample=78, buffer_id=02:4E
    db 0,0,100,0,70,127,4,2,210,1,70,4  ; n978 t=74.308s dur=100ms, freq=466Hz, sample=70, buffer_id=04:46
    db 0,0,100,0,73,127,4,6,42,2,73,4  ; n979 t=74.308s dur=100ms, freq=554Hz, sample=73, buffer_id=04:49
    db 0,0,111,0,54,127,7,7,185,0,54,7  ; n980 t=74.308s dur=111ms, freq=185Hz, sample=54, buffer_id=07:36
    db 0,0,111,0,66,127,7,8,114,1,66,7  ; n981 t=74.308s dur=111ms, freq=370Hz, sample=66, buffer_id=07:42
    db 0,0,111,0,58,127,8,9,233,0,58,7  ; n982 t=74.308s dur=111ms, freq=233Hz, sample=58, buffer_id=07:3A
    db 0,0,111,0,61,127,8,10,21,1,61,7  ; n983 t=74.308s dur=111ms, freq=277Hz, sample=61, buffer_id=07:3D
    db 0,0,194,0,85,127,16,12,164,3,85,16  ; n984 t=74.308s dur=194ms, freq=932Hz, sample=85, buffer_id=10:55
    db 0,0,194,0,70,127,17,11,210,1,70,16  ; n985 t=74.308s dur=194ms, freq=466Hz, sample=70, buffer_id=10:46
    db 0,0,139,0,49,127,18,13,139,0,49,18  ; n986 t=74.308s dur=139ms, freq=139Hz, sample=49, buffer_id=12:31
    db 0,0,160,1,66,127,19,14,114,1,66,19  ; n987 t=74.308s dur=416ms, freq=370Hz, sample=66, buffer_id=13:42
    db 111,0,160,1,54,127,20,16,185,0,54,20  ; n988 t=74.308s dur=416ms, freq=185Hz, sample=54, buffer_id=14:36
    db 111,0,138,0,48,127,18,15,131,0,48,18  ; n989 t=74.419s dur=138ms, freq=131Hz, sample=48, buffer_id=12:30
    db 0,0,194,0,85,127,16,0,220,3,85,16  ; n990 t=74.531s dur=194ms, freq=988Hz, sample=85, buffer_id=10:55
    db 0,0,194,0,70,127,17,3,238,1,70,16  ; n991 t=74.531s dur=194ms, freq=494Hz, sample=70, buffer_id=10:46
    db 222,0,194,0,49,127,18,4,139,0,49,18  ; n992 t=74.531s dur=194ms, freq=139Hz, sample=49, buffer_id=12:31
    db 0,0,189,0,85,127,16,1,85,4,85,16  ; n993 t=74.752s dur=189ms, freq=1109Hz, sample=85, buffer_id=10:55
    db 0,0,193,0,73,127,17,2,42,2,73,16  ; n994 t=74.752s dur=193ms, freq=554Hz, sample=73, buffer_id=10:49
    db 0,0,158,1,54,127,19,5,185,0,54,19  ; n995 t=74.752s dur=414ms, freq=185Hz, sample=54, buffer_id=13:36
    db 221,0,158,1,42,127,20,6,92,0,42,20  ; n996 t=74.752s dur=414ms, freq=92Hz, sample=42, buffer_id=14:2A
    db 0,0,193,0,85,127,16,3,164,3,85,16  ; n997 t=74.974s dur=193ms, freq=932Hz, sample=85, buffer_id=10:55
    db 221,0,193,0,70,127,17,0,210,1,70,16  ; n998 t=74.974s dur=193ms, freq=466Hz, sample=70, buffer_id=10:46
    db 0,0,100,0,78,127,2,1,228,2,78,2  ; n999 t=75.195s dur=100ms, freq=740Hz, sample=78, buffer_id=02:4E
    db 0,0,100,0,70,127,4,2,210,1,70,4  ; n1000 t=75.195s dur=100ms, freq=466Hz, sample=70, buffer_id=04:46
    db 0,0,100,0,73,127,4,4,42,2,73,4  ; n1001 t=75.195s dur=100ms, freq=554Hz, sample=73, buffer_id=04:49
    db 0,0,110,0,54,127,7,8,185,0,54,7  ; n1002 t=75.195s dur=110ms, freq=185Hz, sample=54, buffer_id=07:36
    db 0,0,110,0,66,127,7,7,114,1,66,7  ; n1003 t=75.195s dur=110ms, freq=370Hz, sample=66, buffer_id=07:42
    db 0,0,110,0,58,127,8,10,233,0,58,7  ; n1004 t=75.195s dur=110ms, freq=233Hz, sample=58, buffer_id=07:3A
    db 0,0,110,0,61,127,8,9,21,1,61,7  ; n1005 t=75.195s dur=110ms, freq=277Hz, sample=61, buffer_id=07:3D
    db 0,0,189,0,85,127,16,11,85,4,85,16  ; n1006 t=75.195s dur=189ms, freq=1109Hz, sample=85, buffer_id=10:55
    db 0,0,157,1,73,127,17,12,42,2,73,16  ; n1007 t=75.195s dur=413ms, freq=554Hz, sample=73, buffer_id=10:49
    db 0,0,137,0,49,127,18,14,139,0,49,18  ; n1008 t=75.195s dur=137ms, freq=139Hz, sample=49, buffer_id=12:31
    db 0,0,157,1,66,127,19,13,114,1,66,19  ; n1009 t=75.195s dur=413ms, freq=370Hz, sample=66, buffer_id=13:42
    db 110,0,157,1,54,127,20,15,185,0,54,20  ; n1010 t=75.195s dur=413ms, freq=185Hz, sample=54, buffer_id=14:36
    db 110,0,137,0,48,127,18,16,131,0,48,18  ; n1011 t=75.305s dur=137ms, freq=131Hz, sample=48, buffer_id=12:30
    db 220,0,192,0,49,127,18,0,139,0,49,18  ; n1012 t=75.415s dur=192ms, freq=139Hz, sample=49, buffer_id=12:31
    db 0,0,159,0,86,127,16,1,151,4,86,16  ; n1013 t=75.636s dur=159ms, freq=1175Hz, sample=86, buffer_id=10:56
    db 0,0,192,0,74,127,17,2,75,2,74,16  ; n1014 t=75.636s dur=192ms, freq=587Hz, sample=74, buffer_id=10:4A
    db 0,0,138,1,47,127,19,3,147,0,47,19  ; n1015 t=75.636s dur=394ms, freq=147Hz, sample=47, buffer_id=13:2F
    db 220,0,138,1,35,127,20,4,73,0,35,20  ; n1016 t=75.636s dur=394ms, freq=73Hz, sample=35, buffer_id=14:23
    db 0,0,191,0,85,127,16,0,164,3,85,16  ; n1017 t=75.855s dur=191ms, freq=932Hz, sample=85, buffer_id=10:55
    db 219,0,191,0,70,127,17,5,210,1,70,16  ; n1018 t=75.855s dur=191ms, freq=466Hz, sample=70, buffer_id=10:46
    db 0,0,100,0,78,127,2,1,228,2,78,2  ; n1019 t=76.075s dur=100ms, freq=740Hz, sample=78, buffer_id=02:4E
    db 0,0,100,0,70,127,4,2,210,1,70,4  ; n1020 t=76.075s dur=100ms, freq=466Hz, sample=70, buffer_id=04:46
    db 0,0,100,0,74,127,4,6,75,2,74,4  ; n1021 t=76.075s dur=100ms, freq=587Hz, sample=74, buffer_id=04:4A
    db 0,0,109,0,54,127,7,7,185,0,54,7  ; n1022 t=76.075s dur=109ms, freq=185Hz, sample=54, buffer_id=07:36
    db 0,0,109,0,66,127,7,8,114,1,66,7  ; n1023 t=76.075s dur=109ms, freq=370Hz, sample=66, buffer_id=07:42
    db 0,0,109,0,58,127,8,9,233,0,58,7  ; n1024 t=76.075s dur=109ms, freq=233Hz, sample=58, buffer_id=07:3A
    db 0,0,109,0,62,127,8,10,38,1,62,7  ; n1025 t=76.075s dur=109ms, freq=294Hz, sample=62, buffer_id=07:3E
    db 0,0,159,0,86,127,16,11,151,4,86,16  ; n1026 t=76.075s dur=159ms, freq=1175Hz, sample=86, buffer_id=10:56
    db 0,0,153,1,74,127,17,12,75,2,74,16  ; n1027 t=76.075s dur=409ms, freq=587Hz, sample=74, buffer_id=10:4A
    db 0,0,136,0,49,127,18,13,147,0,49,18  ; n1028 t=76.075s dur=136ms, freq=147Hz, sample=49, buffer_id=12:31
    db 0,0,153,1,62,127,19,14,38,1,62,19  ; n1029 t=76.075s dur=409ms, freq=294Hz, sample=62, buffer_id=13:3E
    db 109,0,153,1,50,127,20,15,147,0,50,20  ; n1030 t=76.075s dur=409ms, freq=147Hz, sample=50, buffer_id=14:32
    db 109,0,136,0,49,127,18,16,139,0,49,18  ; n1031 t=76.184s dur=136ms, freq=139Hz, sample=49, buffer_id=12:31
    db 218,0,189,0,49,127,18,0,147,0,49,18  ; n1032 t=76.293s dur=189ms, freq=147Hz, sample=49, buffer_id=12:31
    db 0,0,74,3,85,127,2,1,85,4,85,2  ; n1033 t=76.512s dur=842ms, freq=1109Hz, sample=85, buffer_id=02:55
    db 0,0,74,3,73,127,3,2,42,2,73,3  ; n1034 t=76.512s dur=842ms, freq=554Hz, sample=73, buffer_id=03:49
    db 0,0,189,0,85,127,16,3,85,4,85,16  ; n1035 t=76.512s dur=189ms, freq=1109Hz, sample=85, buffer_id=10:55
    db 0,0,152,1,73,127,17,4,42,2,73,16  ; n1036 t=76.512s dur=408ms, freq=554Hz, sample=73, buffer_id=10:49
    db 0,0,152,1,54,127,19,5,185,0,54,19  ; n1037 t=76.512s dur=408ms, freq=185Hz, sample=54, buffer_id=13:36
    db 179,1,152,1,42,127,20,6,92,0,42,20  ; n1038 t=76.512s dur=408ms, freq=92Hz, sample=42, buffer_id=14:2A
    db 0,0,100,0,78,127,2,0,228,2,78,2  ; n1039 t=76.947s dur=100ms, freq=740Hz, sample=78, buffer_id=02:4E
    db 0,0,100,0,70,127,4,3,210,1,70,4  ; n1040 t=76.947s dur=100ms, freq=466Hz, sample=70, buffer_id=04:46
    db 0,0,100,0,73,127,4,7,42,2,73,4  ; n1041 t=76.947s dur=100ms, freq=554Hz, sample=73, buffer_id=04:49
    db 0,0,108,0,54,127,7,8,185,0,54,7  ; n1042 t=76.947s dur=108ms, freq=185Hz, sample=54, buffer_id=07:36
    db 0,0,108,0,66,127,7,9,114,1,66,7  ; n1043 t=76.947s dur=108ms, freq=370Hz, sample=66, buffer_id=07:42
    db 0,0,108,0,58,127,8,10,233,0,58,7  ; n1044 t=76.947s dur=108ms, freq=233Hz, sample=58, buffer_id=07:3A
    db 0,0,108,0,61,127,8,11,21,1,61,7  ; n1045 t=76.947s dur=108ms, freq=277Hz, sample=61, buffer_id=07:3D
    db 0,0,135,0,49,127,18,12,139,0,49,18  ; n1046 t=76.947s dur=135ms, freq=139Hz, sample=49, buffer_id=12:31
    db 0,0,150,1,66,127,19,13,114,1,66,19  ; n1047 t=76.947s dur=406ms, freq=370Hz, sample=66, buffer_id=13:42
    db 109,0,150,1,54,127,20,14,185,0,54,20  ; n1048 t=76.947s dur=406ms, freq=185Hz, sample=54, buffer_id=14:36
    db 108,0,135,0,48,127,18,15,131,0,48,18  ; n1049 t=77.056s dur=135ms, freq=131Hz, sample=48, buffer_id=12:30
    db 217,0,189,0,49,127,18,4,139,0,49,18  ; n1050 t=77.164s dur=189ms, freq=139Hz, sample=49, buffer_id=12:31
    db 0,0,100,0,78,127,3,0,228,2,78,3  ; n1051 t=77.381s dur=100ms, freq=740Hz, sample=78, buffer_id=03:4E
    db 0,0,100,0,66,127,4,3,114,1,66,4  ; n1052 t=77.381s dur=100ms, freq=370Hz, sample=66, buffer_id=04:42
    db 0,0,100,0,49,127,5,5,139,0,49,5  ; n1053 t=77.381s dur=100ms, freq=139Hz, sample=49, buffer_id=05:31
    db 0,0,100,0,42,127,6,6,92,0,42,5  ; n1054 t=77.381s dur=100ms, freq=92Hz, sample=42, buffer_id=05:2A
    db 0,0,149,1,54,127,19,7,185,0,54,19  ; n1055 t=77.381s dur=405ms, freq=185Hz, sample=54, buffer_id=13:36
    db 216,0,149,1,42,127,20,8,92,0,42,20  ; n1056 t=77.381s dur=405ms, freq=92Hz, sample=42, buffer_id=14:2A
    db 0,0,100,0,78,127,3,1,63,3,78,3  ; n1057 t=77.597s dur=100ms, freq=831Hz, sample=78, buffer_id=03:4E
    db 216,0,100,0,66,127,4,2,159,1,66,4  ; n1058 t=77.597s dur=100ms, freq=415Hz, sample=66, buffer_id=04:42
    db 0,0,100,0,85,127,3,0,164,3,85,3  ; n1059 t=77.813s dur=100ms, freq=932Hz, sample=85, buffer_id=03:55
    db 0,0,100,0,70,127,4,3,210,1,70,4  ; n1060 t=77.813s dur=100ms, freq=466Hz, sample=70, buffer_id=04:46
    db 0,0,100,0,54,127,5,4,185,0,54,5  ; n1061 t=77.813s dur=100ms, freq=185Hz, sample=54, buffer_id=05:36
    db 0,0,100,0,49,127,6,6,139,0,49,5  ; n1062 t=77.813s dur=100ms, freq=139Hz, sample=49, buffer_id=05:31
    db 0,0,107,0,54,127,7,5,185,0,54,7  ; n1063 t=77.813s dur=107ms, freq=185Hz, sample=54, buffer_id=07:36
    db 0,0,107,0,66,127,7,10,114,1,66,7  ; n1064 t=77.813s dur=107ms, freq=370Hz, sample=66, buffer_id=07:42
    db 0,0,107,0,58,127,8,9,233,0,58,7  ; n1065 t=77.813s dur=107ms, freq=233Hz, sample=58, buffer_id=07:3A
    db 0,0,107,0,61,127,8,12,21,1,61,7  ; n1066 t=77.813s dur=107ms, freq=277Hz, sample=61, buffer_id=07:3D
    db 0,0,147,1,70,127,16,11,210,1,70,16  ; n1067 t=77.813s dur=403ms, freq=466Hz, sample=70, buffer_id=10:46
    db 0,0,147,1,73,127,16,13,42,2,73,16  ; n1068 t=77.813s dur=403ms, freq=554Hz, sample=73, buffer_id=10:49
    db 0,0,147,1,66,127,17,14,114,1,66,16  ; n1069 t=77.813s dur=403ms, freq=370Hz, sample=66, buffer_id=10:42
    db 0,0,147,1,78,127,17,15,228,2,78,16  ; n1070 t=77.813s dur=403ms, freq=740Hz, sample=78, buffer_id=10:4E
    db 0,0,100,0,49,127,18,17,139,0,49,18  ; n1071 t=77.813s dur=100ms, freq=139Hz, sample=49, buffer_id=12:31
    db 86,0,147,1,54,127,20,16,185,0,54,20  ; n1072 t=77.813s dur=403ms, freq=185Hz, sample=54, buffer_id=14:36
    db 86,0,100,0,49,127,18,1,147,0,49,18  ; n1073 t=77.899s dur=100ms, freq=147Hz, sample=49, buffer_id=12:31
    db 43,0,100,0,49,127,18,2,139,0,49,18  ; n1074 t=77.985s dur=100ms, freq=139Hz, sample=49, buffer_id=12:31
    db 0,0,100,0,85,127,3,7,220,3,85,3  ; n1075 t=78.028s dur=100ms, freq=988Hz, sample=85, buffer_id=03:55
    db 43,0,100,0,70,127,4,8,238,1,70,4  ; n1076 t=78.028s dur=100ms, freq=494Hz, sample=70, buffer_id=04:46
    db 86,0,100,0,48,127,18,18,131,0,48,18  ; n1077 t=78.071s dur=100ms, freq=131Hz, sample=48, buffer_id=12:30
    db 86,0,100,0,49,127,18,0,139,0,49,18  ; n1078 t=78.157s dur=100ms, freq=139Hz, sample=49, buffer_id=12:31
    db 0,0,100,0,85,127,3,1,85,4,85,3  ; n1079 t=78.243s dur=100ms, freq=1109Hz, sample=85, buffer_id=03:55
    db 0,0,100,0,73,127,4,3,42,2,73,4  ; n1080 t=78.243s dur=100ms, freq=554Hz, sample=73, buffer_id=04:49
    db 0,0,100,0,49,127,5,4,139,0,49,5  ; n1081 t=78.243s dur=100ms, freq=139Hz, sample=49, buffer_id=05:31
    db 0,0,100,0,42,127,6,5,92,0,42,5  ; n1082 t=78.243s dur=100ms, freq=92Hz, sample=42, buffer_id=05:2A
    db 0,0,145,1,54,127,19,6,185,0,54,19  ; n1083 t=78.243s dur=401ms, freq=185Hz, sample=54, buffer_id=13:36
    db 215,0,145,1,42,127,20,9,92,0,42,20  ; n1084 t=78.243s dur=401ms, freq=92Hz, sample=42, buffer_id=14:2A
    db 0,0,100,0,85,127,3,0,164,3,85,3  ; n1085 t=78.458s dur=100ms, freq=932Hz, sample=85, buffer_id=03:55
    db 214,0,100,0,70,127,4,2,210,1,70,4  ; n1086 t=78.458s dur=100ms, freq=466Hz, sample=70, buffer_id=04:46
    db 0,0,100,0,85,127,3,3,85,4,85,3  ; n1087 t=78.672s dur=100ms, freq=1109Hz, sample=85, buffer_id=03:55
    db 0,0,100,0,73,127,4,1,42,2,73,4  ; n1088 t=78.672s dur=100ms, freq=554Hz, sample=73, buffer_id=04:49
    db 0,0,100,0,54,127,5,4,185,0,54,5  ; n1089 t=78.672s dur=100ms, freq=185Hz, sample=54, buffer_id=05:36
    db 0,0,100,0,49,127,6,5,139,0,49,5  ; n1090 t=78.672s dur=100ms, freq=139Hz, sample=49, buffer_id=05:31
    db 0,0,106,0,54,127,7,7,185,0,54,7  ; n1091 t=78.672s dur=106ms, freq=185Hz, sample=54, buffer_id=07:36
    db 0,0,106,0,66,127,7,8,114,1,66,7  ; n1092 t=78.672s dur=106ms, freq=370Hz, sample=66, buffer_id=07:42
    db 0,0,106,0,58,127,8,10,233,0,58,7  ; n1093 t=78.672s dur=106ms, freq=233Hz, sample=58, buffer_id=07:3A
    db 0,0,106,0,61,127,8,11,21,1,61,7  ; n1094 t=78.672s dur=106ms, freq=277Hz, sample=61, buffer_id=07:3D
    db 0,0,144,1,70,127,16,12,210,1,70,16  ; n1095 t=78.672s dur=400ms, freq=466Hz, sample=70, buffer_id=10:46
    db 0,0,144,1,73,127,16,14,42,2,73,16  ; n1096 t=78.672s dur=400ms, freq=554Hz, sample=73, buffer_id=10:49
    db 0,0,144,1,66,127,17,13,114,1,66,16  ; n1097 t=78.672s dur=400ms, freq=370Hz, sample=66, buffer_id=10:42
    db 0,0,144,1,78,127,17,16,228,2,78,16  ; n1098 t=78.672s dur=400ms, freq=740Hz, sample=78, buffer_id=10:4E
    db 0,0,100,0,49,127,18,15,139,0,49,18  ; n1099 t=78.672s dur=100ms, freq=139Hz, sample=49, buffer_id=12:31
    db 85,0,144,1,54,127,20,17,185,0,54,20  ; n1100 t=78.672s dur=400ms, freq=185Hz, sample=54, buffer_id=14:36
    db 85,0,100,0,49,127,18,18,147,0,49,18  ; n1101 t=78.757s dur=100ms, freq=147Hz, sample=49, buffer_id=12:31
    db 85,0,100,0,49,127,18,0,139,0,49,18  ; n1102 t=78.843s dur=100ms, freq=139Hz, sample=49, buffer_id=12:31
    db 85,0,100,0,48,127,18,2,131,0,48,18  ; n1103 t=78.928s dur=100ms, freq=131Hz, sample=48, buffer_id=12:30
    db 85,0,100,0,49,127,18,1,139,0,49,18  ; n1104 t=79.013s dur=100ms, freq=139Hz, sample=49, buffer_id=12:31
    db 0,0,100,0,86,127,3,3,151,4,86,3  ; n1105 t=79.099s dur=100ms, freq=1175Hz, sample=86, buffer_id=03:56
    db 0,0,100,0,74,127,4,4,75,2,74,4  ; n1106 t=79.099s dur=100ms, freq=587Hz, sample=74, buffer_id=04:4A
    db 0,0,100,0,50,127,5,5,147,0,50,5  ; n1107 t=79.099s dur=100ms, freq=147Hz, sample=50, buffer_id=05:32
    db 0,0,100,0,35,127,6,6,73,0,35,5  ; n1108 t=79.099s dur=100ms, freq=73Hz, sample=35, buffer_id=05:23
    db 0,0,138,1,47,127,19,7,147,0,47,19  ; n1109 t=79.099s dur=394ms, freq=147Hz, sample=47, buffer_id=13:2F
    db 213,0,138,1,35,127,20,8,73,0,35,20  ; n1110 t=79.099s dur=394ms, freq=73Hz, sample=35, buffer_id=14:23
    db 0,0,100,0,85,127,3,0,164,3,85,3  ; n1111 t=79.312s dur=100ms, freq=932Hz, sample=85, buffer_id=03:55
    db 213,0,100,0,70,127,4,2,210,1,70,4  ; n1112 t=79.312s dur=100ms, freq=466Hz, sample=70, buffer_id=04:46
    db 0,0,100,0,86,127,3,1,151,4,86,3  ; n1113 t=79.524s dur=100ms, freq=1175Hz, sample=86, buffer_id=03:56
    db 0,0,100,0,74,127,4,3,75,2,74,4  ; n1114 t=79.524s dur=100ms, freq=587Hz, sample=74, buffer_id=04:4A
    db 0,0,100,0,54,127,5,4,185,0,54,5  ; n1115 t=79.524s dur=100ms, freq=185Hz, sample=54, buffer_id=05:36
    db 0,0,100,0,50,127,6,6,147,0,50,5  ; n1116 t=79.524s dur=100ms, freq=147Hz, sample=50, buffer_id=05:32
    db 0,0,106,0,54,127,7,5,185,0,54,7  ; n1117 t=79.524s dur=106ms, freq=185Hz, sample=54, buffer_id=07:36
    db 0,0,106,0,66,127,7,9,114,1,66,7  ; n1118 t=79.524s dur=106ms, freq=370Hz, sample=66, buffer_id=07:42
    db 0,0,106,0,58,127,8,11,233,0,58,7  ; n1119 t=79.524s dur=106ms, freq=233Hz, sample=58, buffer_id=07:3A
    db 0,0,106,0,62,127,8,10,38,1,62,7  ; n1120 t=79.524s dur=106ms, freq=294Hz, sample=62, buffer_id=07:3E
    db 0,0,141,1,70,127,16,13,210,1,70,16  ; n1121 t=79.524s dur=397ms, freq=466Hz, sample=70, buffer_id=10:46
    db 0,0,141,1,74,127,16,12,75,2,74,16  ; n1122 t=79.524s dur=397ms, freq=587Hz, sample=74, buffer_id=10:4A
    db 0,0,141,1,66,127,17,14,114,1,66,16  ; n1123 t=79.524s dur=397ms, freq=370Hz, sample=66, buffer_id=10:42
    db 0,0,141,1,78,127,17,15,228,2,78,16  ; n1124 t=79.524s dur=397ms, freq=740Hz, sample=78, buffer_id=10:4E
    db 0,0,100,0,49,127,18,16,147,0,49,18  ; n1125 t=79.524s dur=100ms, freq=147Hz, sample=49, buffer_id=12:31
    db 0,0,141,1,62,127,19,17,38,1,62,19  ; n1126 t=79.524s dur=397ms, freq=294Hz, sample=62, buffer_id=13:3E
    db 85,0,141,1,50,127,20,18,147,0,50,20  ; n1127 t=79.524s dur=397ms, freq=147Hz, sample=50, buffer_id=14:32
    db 85,0,100,0,54,127,18,22,165,0,54,18  ; n1128 t=79.609s dur=100ms, freq=165Hz, sample=54, buffer_id=12:36
    db 85,0,100,0,49,127,18,0,147,0,49,18  ; n1129 t=79.694s dur=100ms, freq=147Hz, sample=49, buffer_id=12:31
    db 85,0,100,0,49,127,18,2,139,0,49,18  ; n1130 t=79.778s dur=100ms, freq=139Hz, sample=49, buffer_id=12:31
    db 85,0,100,0,49,127,18,1,147,0,49,18  ; n1131 t=79.863s dur=100ms, freq=147Hz, sample=49, buffer_id=12:31
    db 0,0,100,0,85,127,3,3,85,4,85,3  ; n1132 t=79.948s dur=100ms, freq=1109Hz, sample=85, buffer_id=03:55
    db 0,0,100,0,73,127,4,4,42,2,73,4  ; n1133 t=79.948s dur=100ms, freq=554Hz, sample=73, buffer_id=04:49
    db 0,0,100,0,49,127,5,5,139,0,49,5  ; n1134 t=79.948s dur=100ms, freq=139Hz, sample=49, buffer_id=05:31
    db 0,0,100,0,42,127,6,6,92,0,42,5  ; n1135 t=79.948s dur=100ms, freq=92Hz, sample=42, buffer_id=05:2A
    db 0,0,139,1,54,127,19,7,185,0,54,19  ; n1136 t=79.948s dur=395ms, freq=185Hz, sample=54, buffer_id=13:36
    db 211,0,139,1,42,127,20,8,92,0,42,20  ; n1137 t=79.948s dur=395ms, freq=92Hz, sample=42, buffer_id=14:2A
    db 0,0,100,0,85,127,3,0,164,3,85,3  ; n1138 t=80.159s dur=100ms, freq=932Hz, sample=85, buffer_id=03:55
    db 211,0,100,0,70,127,4,2,210,1,70,4  ; n1139 t=80.159s dur=100ms, freq=466Hz, sample=70, buffer_id=04:46
    db 0,0,100,0,85,127,3,1,85,4,85,3  ; n1140 t=80.370s dur=100ms, freq=1109Hz, sample=85, buffer_id=03:55
    db 0,0,100,0,73,127,4,3,42,2,73,4  ; n1141 t=80.370s dur=100ms, freq=554Hz, sample=73, buffer_id=04:49
    db 0,0,100,0,54,127,5,4,185,0,54,5  ; n1142 t=80.370s dur=100ms, freq=185Hz, sample=54, buffer_id=05:36
    db 0,0,100,0,49,127,6,6,139,0,49,5  ; n1143 t=80.370s dur=100ms, freq=139Hz, sample=49, buffer_id=05:31
    db 0,0,105,0,54,127,7,5,185,0,54,7  ; n1144 t=80.370s dur=105ms, freq=185Hz, sample=54, buffer_id=07:36
    db 0,0,105,0,66,127,7,10,114,1,66,7  ; n1145 t=80.370s dur=105ms, freq=370Hz, sample=66, buffer_id=07:42
    db 0,0,105,0,58,127,8,9,233,0,58,7  ; n1146 t=80.370s dur=105ms, freq=233Hz, sample=58, buffer_id=07:3A
    db 0,0,105,0,61,127,8,11,21,1,61,7  ; n1147 t=80.370s dur=105ms, freq=277Hz, sample=61, buffer_id=07:3D
    db 0,0,138,1,70,127,16,12,210,1,70,16  ; n1148 t=80.370s dur=394ms, freq=466Hz, sample=70, buffer_id=10:46
    db 0,0,138,1,73,127,16,13,42,2,73,16  ; n1149 t=80.370s dur=394ms, freq=554Hz, sample=73, buffer_id=10:49
    db 0,0,138,1,66,127,17,15,114,1,66,16  ; n1150 t=80.370s dur=394ms, freq=370Hz, sample=66, buffer_id=10:42
    db 0,0,138,1,78,127,17,14,228,2,78,16  ; n1151 t=80.370s dur=394ms, freq=740Hz, sample=78, buffer_id=10:4E
    db 0,0,100,0,49,127,18,17,139,0,49,18  ; n1152 t=80.370s dur=100ms, freq=139Hz, sample=49, buffer_id=12:31
    db 84,0,138,1,54,127,20,16,185,0,54,20  ; n1153 t=80.370s dur=394ms, freq=185Hz, sample=54, buffer_id=14:36
    db 84,0,100,0,49,127,18,18,147,0,49,18  ; n1154 t=80.454s dur=100ms, freq=147Hz, sample=49, buffer_id=12:31
    db 84,0,100,0,49,127,18,0,139,0,49,18  ; n1155 t=80.538s dur=100ms, freq=139Hz, sample=49, buffer_id=12:31
    db 84,0,100,0,48,127,18,2,131,0,48,18  ; n1156 t=80.622s dur=100ms, freq=131Hz, sample=48, buffer_id=12:30
    db 84,0,100,0,49,127,18,1,139,0,49,18  ; n1157 t=80.706s dur=100ms, freq=139Hz, sample=49, buffer_id=12:31
    db 0,0,100,0,78,127,3,3,228,2,78,3  ; n1158 t=80.790s dur=100ms, freq=740Hz, sample=78, buffer_id=03:4E
    db 0,0,100,0,66,127,4,4,114,1,66,4  ; n1159 t=80.790s dur=100ms, freq=370Hz, sample=66, buffer_id=04:42
    db 0,0,100,0,49,127,5,5,139,0,49,5  ; n1160 t=80.790s dur=100ms, freq=139Hz, sample=49, buffer_id=05:31
    db 0,0,100,0,42,127,6,6,92,0,42,5  ; n1161 t=80.790s dur=100ms, freq=92Hz, sample=42, buffer_id=05:2A
    db 0,0,136,1,54,127,19,8,185,0,54,19  ; n1162 t=80.790s dur=392ms, freq=185Hz, sample=54, buffer_id=13:36
    db 210,0,136,1,42,127,20,7,92,0,42,20  ; n1163 t=80.790s dur=392ms, freq=92Hz, sample=42, buffer_id=14:2A
    db 0,0,100,0,78,127,3,0,63,3,78,3  ; n1164 t=81.000s dur=100ms, freq=831Hz, sample=78, buffer_id=03:4E
    db 209,0,100,0,66,127,4,2,159,1,66,4  ; n1165 t=81.000s dur=100ms, freq=415Hz, sample=66, buffer_id=04:42
    db 0,0,100,0,85,127,3,1,164,3,85,3  ; n1166 t=81.209s dur=100ms, freq=932Hz, sample=85, buffer_id=03:55
    db 0,0,100,0,70,127,4,3,210,1,70,4  ; n1167 t=81.209s dur=100ms, freq=466Hz, sample=70, buffer_id=04:46
    db 0,0,100,0,54,127,5,4,185,0,54,5  ; n1168 t=81.209s dur=100ms, freq=185Hz, sample=54, buffer_id=05:36
    db 0,0,100,0,49,127,6,6,139,0,49,5  ; n1169 t=81.209s dur=100ms, freq=139Hz, sample=49, buffer_id=05:31
    db 0,0,104,0,54,127,7,5,185,0,54,7  ; n1170 t=81.209s dur=104ms, freq=185Hz, sample=54, buffer_id=07:36
    db 0,0,104,0,66,127,7,9,114,1,66,7  ; n1171 t=81.209s dur=104ms, freq=370Hz, sample=66, buffer_id=07:42
    db 0,0,104,0,58,127,8,10,233,0,58,7  ; n1172 t=81.209s dur=104ms, freq=233Hz, sample=58, buffer_id=07:3A
    db 0,0,104,0,61,127,8,12,21,1,61,7  ; n1173 t=81.209s dur=104ms, freq=277Hz, sample=61, buffer_id=07:3D
    db 0,0,135,1,70,127,16,11,210,1,70,16  ; n1174 t=81.209s dur=391ms, freq=466Hz, sample=70, buffer_id=10:46
    db 0,0,135,1,73,127,16,14,42,2,73,16  ; n1175 t=81.209s dur=391ms, freq=554Hz, sample=73, buffer_id=10:49
    db 0,0,135,1,66,127,17,13,114,1,66,16  ; n1176 t=81.209s dur=391ms, freq=370Hz, sample=66, buffer_id=10:42
    db 0,0,135,1,78,127,17,15,228,2,78,16  ; n1177 t=81.209s dur=391ms, freq=740Hz, sample=78, buffer_id=10:4E
    db 0,0,100,0,49,127,18,16,139,0,49,18  ; n1178 t=81.209s dur=100ms, freq=139Hz, sample=49, buffer_id=12:31
    db 84,0,135,1,54,127,20,17,185,0,54,20  ; n1179 t=81.209s dur=391ms, freq=185Hz, sample=54, buffer_id=14:36
    db 84,0,100,0,49,127,18,19,147,0,49,18  ; n1180 t=81.293s dur=100ms, freq=147Hz, sample=49, buffer_id=12:31
    db 42,0,100,0,49,127,18,0,139,0,49,18  ; n1181 t=81.376s dur=100ms, freq=139Hz, sample=49, buffer_id=12:31
    db 0,0,100,0,85,127,3,2,220,3,85,3  ; n1182 t=81.418s dur=100ms, freq=988Hz, sample=85, buffer_id=03:55
    db 42,0,100,0,70,127,4,7,238,1,70,4  ; n1183 t=81.418s dur=100ms, freq=494Hz, sample=70, buffer_id=04:46
    db 83,0,100,0,48,127,18,8,131,0,48,18  ; n1184 t=81.460s dur=100ms, freq=131Hz, sample=48, buffer_id=12:30
    db 83,0,100,0,49,127,18,1,139,0,49,18  ; n1185 t=81.543s dur=100ms, freq=139Hz, sample=49, buffer_id=12:31
    db 0,0,100,0,85,127,3,3,85,4,85,3  ; n1186 t=81.626s dur=100ms, freq=1109Hz, sample=85, buffer_id=03:55
    db 0,0,100,0,73,127,4,4,42,2,73,4  ; n1187 t=81.626s dur=100ms, freq=554Hz, sample=73, buffer_id=04:49
    db 0,0,100,0,49,127,5,5,139,0,49,5  ; n1188 t=81.626s dur=100ms, freq=139Hz, sample=49, buffer_id=05:31
    db 0,0,100,0,42,127,6,6,92,0,42,5  ; n1189 t=81.626s dur=100ms, freq=92Hz, sample=42, buffer_id=05:2A
    db 0,0,133,1,54,127,19,9,185,0,54,19  ; n1190 t=81.626s dur=389ms, freq=185Hz, sample=54, buffer_id=13:36
    db 208,0,133,1,42,127,20,10,92,0,42,20  ; n1191 t=81.626s dur=389ms, freq=92Hz, sample=42, buffer_id=14:2A
    db 0,0,100,0,85,127,3,0,164,3,85,3  ; n1192 t=81.834s dur=100ms, freq=932Hz, sample=85, buffer_id=03:55
    db 208,0,100,0,70,127,4,2,210,1,70,4  ; n1193 t=81.834s dur=100ms, freq=466Hz, sample=70, buffer_id=04:46
    db 0,0,100,0,85,127,3,1,85,4,85,3  ; n1194 t=82.042s dur=100ms, freq=1109Hz, sample=85, buffer_id=03:55
    db 0,0,100,0,73,127,4,3,42,2,73,4  ; n1195 t=82.042s dur=100ms, freq=554Hz, sample=73, buffer_id=04:49
    db 0,0,100,0,54,127,5,4,185,0,54,5  ; n1196 t=82.042s dur=100ms, freq=185Hz, sample=54, buffer_id=05:36
    db 0,0,100,0,49,127,6,6,139,0,49,5  ; n1197 t=82.042s dur=100ms, freq=139Hz, sample=49, buffer_id=05:31
    db 0,0,103,0,54,127,7,5,185,0,54,7  ; n1198 t=82.042s dur=103ms, freq=185Hz, sample=54, buffer_id=07:36
    db 0,0,103,0,66,127,7,7,114,1,66,7  ; n1199 t=82.042s dur=103ms, freq=370Hz, sample=66, buffer_id=07:42
    db 0,0,103,0,58,127,8,8,233,0,58,7  ; n1200 t=82.042s dur=103ms, freq=233Hz, sample=58, buffer_id=07:3A
    db 0,0,103,0,61,127,8,11,21,1,61,7  ; n1201 t=82.042s dur=103ms, freq=277Hz, sample=61, buffer_id=07:3D
    db 0,0,132,1,70,127,16,12,210,1,70,16  ; n1202 t=82.042s dur=388ms, freq=466Hz, sample=70, buffer_id=10:46
    db 0,0,132,1,73,127,16,13,42,2,73,16  ; n1203 t=82.042s dur=388ms, freq=554Hz, sample=73, buffer_id=10:49
    db 0,0,132,1,66,127,17,14,114,1,66,16  ; n1204 t=82.042s dur=388ms, freq=370Hz, sample=66, buffer_id=10:42
    db 0,0,132,1,78,127,17,16,228,2,78,16  ; n1205 t=82.042s dur=388ms, freq=740Hz, sample=78, buffer_id=10:4E
    db 0,0,100,0,49,127,18,15,139,0,49,18  ; n1206 t=82.042s dur=100ms, freq=139Hz, sample=49, buffer_id=12:31
    db 83,0,132,1,54,127,20,18,185,0,54,20  ; n1207 t=82.042s dur=388ms, freq=185Hz, sample=54, buffer_id=14:36
    db 83,0,100,0,49,127,18,17,147,0,49,18  ; n1208 t=82.125s dur=100ms, freq=147Hz, sample=49, buffer_id=12:31
    db 83,0,100,0,49,127,18,0,139,0,49,18  ; n1209 t=82.208s dur=100ms, freq=139Hz, sample=49, buffer_id=12:31
    db 83,0,100,0,48,127,18,2,131,0,48,18  ; n1210 t=82.290s dur=100ms, freq=131Hz, sample=48, buffer_id=12:30
    db 83,0,100,0,49,127,18,1,139,0,49,18  ; n1211 t=82.373s dur=100ms, freq=139Hz, sample=49, buffer_id=12:31
    db 0,0,100,0,86,127,3,3,151,4,86,3  ; n1212 t=82.456s dur=100ms, freq=1175Hz, sample=86, buffer_id=03:56
    db 0,0,100,0,74,127,4,4,75,2,74,4  ; n1213 t=82.456s dur=100ms, freq=587Hz, sample=74, buffer_id=04:4A
    db 0,0,100,0,50,127,5,5,147,0,50,5  ; n1214 t=82.456s dur=100ms, freq=147Hz, sample=50, buffer_id=05:32
    db 0,0,100,0,35,127,6,6,73,0,35,5  ; n1215 t=82.456s dur=100ms, freq=73Hz, sample=35, buffer_id=05:23
    db 0,0,130,1,47,127,19,7,147,0,47,19  ; n1216 t=82.456s dur=386ms, freq=147Hz, sample=47, buffer_id=13:2F
    db 207,0,130,1,35,127,20,8,73,0,35,20  ; n1217 t=82.456s dur=386ms, freq=73Hz, sample=35, buffer_id=14:23
    db 0,0,100,0,85,127,3,0,164,3,85,3  ; n1218 t=82.662s dur=100ms, freq=932Hz, sample=85, buffer_id=03:55
    db 206,0,100,0,70,127,4,2,210,1,70,4  ; n1219 t=82.662s dur=100ms, freq=466Hz, sample=70, buffer_id=04:46
    db 0,0,100,0,86,127,3,1,151,4,86,3  ; n1220 t=82.868s dur=100ms, freq=1175Hz, sample=86, buffer_id=03:56
    db 0,0,100,0,74,127,4,3,75,2,74,4  ; n1221 t=82.868s dur=100ms, freq=587Hz, sample=74, buffer_id=04:4A
    db 0,0,100,0,54,127,5,4,185,0,54,5  ; n1222 t=82.868s dur=100ms, freq=185Hz, sample=54, buffer_id=05:36
    db 0,0,100,0,50,127,6,6,147,0,50,5  ; n1223 t=82.868s dur=100ms, freq=147Hz, sample=50, buffer_id=05:32
    db 0,0,102,0,54,127,7,5,185,0,54,7  ; n1224 t=82.868s dur=102ms, freq=185Hz, sample=54, buffer_id=07:36
    db 0,0,102,0,66,127,7,9,114,1,66,7  ; n1225 t=82.868s dur=102ms, freq=370Hz, sample=66, buffer_id=07:42
    db 0,0,102,0,58,127,8,10,233,0,58,7  ; n1226 t=82.868s dur=102ms, freq=233Hz, sample=58, buffer_id=07:3A
    db 0,0,102,0,62,127,8,11,38,1,62,7  ; n1227 t=82.868s dur=102ms, freq=294Hz, sample=62, buffer_id=07:3E
    db 0,0,129,1,70,127,16,13,210,1,70,16  ; n1228 t=82.868s dur=385ms, freq=466Hz, sample=70, buffer_id=10:46
    db 0,0,129,1,74,127,16,12,75,2,74,16  ; n1229 t=82.868s dur=385ms, freq=587Hz, sample=74, buffer_id=10:4A
    db 0,0,129,1,66,127,17,15,114,1,66,16  ; n1230 t=82.868s dur=385ms, freq=370Hz, sample=66, buffer_id=10:42
    db 0,0,129,1,78,127,17,14,228,2,78,16  ; n1231 t=82.868s dur=385ms, freq=740Hz, sample=78, buffer_id=10:4E
    db 0,0,100,0,49,127,18,16,147,0,49,18  ; n1232 t=82.868s dur=100ms, freq=147Hz, sample=49, buffer_id=12:31
    db 0,0,129,1,62,127,19,17,38,1,62,19  ; n1233 t=82.868s dur=385ms, freq=294Hz, sample=62, buffer_id=13:3E
    db 82,0,129,1,50,127,20,18,147,0,50,20  ; n1234 t=82.868s dur=385ms, freq=147Hz, sample=50, buffer_id=14:32
    db 82,0,100,0,54,127,18,19,165,0,54,18  ; n1235 t=82.951s dur=100ms, freq=165Hz, sample=54, buffer_id=12:36
    db 82,0,100,0,49,127,18,0,147,0,49,18  ; n1236 t=83.033s dur=100ms, freq=147Hz, sample=49, buffer_id=12:31
    db 82,0,100,0,49,127,18,2,139,0,49,18  ; n1237 t=83.115s dur=100ms, freq=139Hz, sample=49, buffer_id=12:31
    db 82,0,100,0,49,127,18,1,147,0,49,18  ; n1238 t=83.197s dur=100ms, freq=147Hz, sample=49, buffer_id=12:31
    db 0,0,23,3,85,127,3,3,85,4,85,3  ; n1239 t=83.279s dur=791ms, freq=1109Hz, sample=85, buffer_id=03:55
    db 0,0,23,3,73,127,4,4,42,2,73,4  ; n1240 t=83.279s dur=791ms, freq=554Hz, sample=73, buffer_id=04:49
    db 0,0,100,0,49,127,5,5,139,0,49,5  ; n1241 t=83.279s dur=100ms, freq=139Hz, sample=49, buffer_id=05:31
    db 0,0,100,0,42,127,6,6,92,0,42,5  ; n1242 t=83.279s dur=100ms, freq=92Hz, sample=42, buffer_id=05:2A
    db 0,0,127,1,54,127,19,7,185,0,54,19  ; n1243 t=83.279s dur=383ms, freq=185Hz, sample=54, buffer_id=13:36
    db 153,1,127,1,42,127,20,8,92,0,42,20  ; n1244 t=83.279s dur=383ms, freq=92Hz, sample=42, buffer_id=14:2A
    db 0,0,100,0,54,127,5,0,185,0,54,5  ; n1245 t=83.689s dur=100ms, freq=185Hz, sample=54, buffer_id=05:36
    db 0,0,100,0,49,127,6,1,139,0,49,5  ; n1246 t=83.689s dur=100ms, freq=139Hz, sample=49, buffer_id=05:31
    db 0,0,102,0,54,127,7,2,185,0,54,7  ; n1247 t=83.689s dur=102ms, freq=185Hz, sample=54, buffer_id=07:36
    db 0,0,102,0,66,127,7,5,114,1,66,7  ; n1248 t=83.689s dur=102ms, freq=370Hz, sample=66, buffer_id=07:42
    db 0,0,102,0,58,127,8,6,233,0,58,7  ; n1249 t=83.689s dur=102ms, freq=233Hz, sample=58, buffer_id=07:3A
    db 0,0,102,0,61,127,8,9,21,1,61,7  ; n1250 t=83.689s dur=102ms, freq=277Hz, sample=61, buffer_id=07:3D
    db 0,0,126,1,70,127,16,10,210,1,70,16  ; n1251 t=83.689s dur=382ms, freq=466Hz, sample=70, buffer_id=10:46
    db 0,0,126,1,73,127,16,11,42,2,73,16  ; n1252 t=83.689s dur=382ms, freq=554Hz, sample=73, buffer_id=10:49
    db 0,0,126,1,66,127,17,12,114,1,66,16  ; n1253 t=83.689s dur=382ms, freq=370Hz, sample=66, buffer_id=10:42
    db 0,0,126,1,78,127,17,13,228,2,78,16  ; n1254 t=83.689s dur=382ms, freq=740Hz, sample=78, buffer_id=10:4E
    db 0,0,100,0,49,127,18,14,139,0,49,18  ; n1255 t=83.689s dur=100ms, freq=139Hz, sample=49, buffer_id=12:31
    db 82,0,126,1,54,127,20,15,185,0,54,20  ; n1256 t=83.689s dur=382ms, freq=185Hz, sample=54, buffer_id=14:36
    db 82,0,100,0,49,127,18,17,147,0,49,18  ; n1257 t=83.770s dur=100ms, freq=147Hz, sample=49, buffer_id=12:31
    db 82,0,100,0,49,127,18,18,139,0,49,18  ; n1258 t=83.852s dur=100ms, freq=139Hz, sample=49, buffer_id=12:31
    db 82,0,100,0,48,127,18,7,131,0,48,18  ; n1259 t=83.934s dur=100ms, freq=131Hz, sample=48, buffer_id=12:30
    db 79,0,100,0,49,127,18,0,139,0,49,18  ; n1260 t=84.015s dur=100ms, freq=139Hz, sample=49, buffer_id=12:31
    db 3,0,125,1,47,127,10,1,123,0,47,10  ; n1261 t=84.094s dur=381ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 0,0,100,0,42,127,5,2,92,0,42,5  ; n1262 t=84.097s dur=100ms, freq=92Hz, sample=42, buffer_id=05:2A
    db 0,0,100,0,35,127,6,5,62,0,35,5  ; n1263 t=84.097s dur=100ms, freq=62Hz, sample=35, buffer_id=05:23
    db 0,0,178,0,70,127,16,6,238,1,70,16  ; n1264 t=84.097s dur=178ms, freq=494Hz, sample=70, buffer_id=10:46
    db 0,0,178,0,59,127,17,8,247,0,59,16  ; n1265 t=84.097s dur=178ms, freq=247Hz, sample=59, buffer_id=10:3B
    db 0,0,127,0,42,127,19,9,92,0,42,19  ; n1266 t=84.097s dur=127ms, freq=92Hz, sample=42, buffer_id=13:2A
    db 102,0,125,1,35,127,20,14,62,0,35,20  ; n1267 t=84.097s dur=381ms, freq=62Hz, sample=35, buffer_id=14:23
    db 102,0,127,0,41,127,19,16,87,0,41,19  ; n1268 t=84.198s dur=127ms, freq=87Hz, sample=41, buffer_id=13:29
    db 0,0,177,0,73,127,16,3,42,2,73,16  ; n1269 t=84.300s dur=177ms, freq=554Hz, sample=73, buffer_id=10:49
    db 0,0,177,0,61,127,17,4,21,1,61,16  ; n1270 t=84.300s dur=177ms, freq=277Hz, sample=61, buffer_id=10:3D
    db 203,0,177,0,42,127,19,7,92,0,42,19  ; n1271 t=84.300s dur=177ms, freq=92Hz, sample=42, buffer_id=13:2A
    db 0,0,100,0,78,127,2,0,228,2,78,2  ; n1272 t=84.503s dur=100ms, freq=740Hz, sample=78, buffer_id=02:4E
    db 0,0,100,0,74,127,4,2,75,2,74,4  ; n1273 t=84.503s dur=100ms, freq=587Hz, sample=74, buffer_id=04:4A
    db 0,0,100,0,78,127,4,5,228,2,78,4  ; n1274 t=84.503s dur=100ms, freq=740Hz, sample=78, buffer_id=04:4E
    db 0,0,100,0,54,127,5,6,185,0,54,5  ; n1275 t=84.503s dur=100ms, freq=185Hz, sample=54, buffer_id=05:36
    db 0,0,100,0,50,127,6,8,147,0,50,5  ; n1276 t=84.503s dur=100ms, freq=147Hz, sample=50, buffer_id=05:32
    db 0,0,101,0,54,127,7,9,185,0,54,7  ; n1277 t=84.503s dur=101ms, freq=185Hz, sample=54, buffer_id=07:36
    db 0,0,101,0,66,127,7,10,114,1,66,7  ; n1278 t=84.503s dur=101ms, freq=370Hz, sample=66, buffer_id=07:42
    db 0,0,101,0,62,127,8,11,38,1,62,7  ; n1279 t=84.503s dur=101ms, freq=294Hz, sample=62, buffer_id=07:3E
    db 0,0,177,0,74,127,16,12,75,2,74,16  ; n1280 t=84.503s dur=177ms, freq=587Hz, sample=74, buffer_id=10:4A
    db 0,0,177,0,62,127,17,13,38,1,62,16  ; n1281 t=84.503s dur=177ms, freq=294Hz, sample=62, buffer_id=10:3E
    db 0,0,126,0,54,127,18,15,185,0,54,18  ; n1282 t=84.503s dur=126ms, freq=185Hz, sample=54, buffer_id=12:36
    db 101,0,123,1,47,127,20,17,123,0,47,20  ; n1283 t=84.503s dur=379ms, freq=123Hz, sample=47, buffer_id=14:2F
    db 101,0,126,0,54,127,18,16,175,0,54,18  ; n1284 t=84.605s dur=126ms, freq=175Hz, sample=54, buffer_id=12:36
    db 0,0,177,0,74,127,16,1,147,2,74,16  ; n1285 t=84.706s dur=177ms, freq=659Hz, sample=74, buffer_id=10:4A
    db 0,0,177,0,65,127,17,3,74,1,65,16  ; n1286 t=84.706s dur=177ms, freq=330Hz, sample=65, buffer_id=10:41
    db 200,0,177,0,54,127,18,4,185,0,54,18  ; n1287 t=84.706s dur=177ms, freq=185Hz, sample=54, buffer_id=12:36
    db 3,0,122,1,47,127,10,0,123,0,47,10  ; n1288 t=84.906s dur=378ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 0,0,100,0,42,127,5,2,92,0,42,5  ; n1289 t=84.908s dur=100ms, freq=92Hz, sample=42, buffer_id=05:2A
    db 0,0,100,0,35,127,6,5,62,0,35,5  ; n1290 t=84.908s dur=100ms, freq=62Hz, sample=35, buffer_id=05:23
    db 0,0,176,0,78,127,16,6,228,2,78,16  ; n1291 t=84.908s dur=176ms, freq=740Hz, sample=78, buffer_id=10:4E
    db 0,0,176,0,66,127,17,7,114,1,66,16  ; n1292 t=84.908s dur=176ms, freq=370Hz, sample=66, buffer_id=10:42
    db 0,0,126,0,42,127,19,8,92,0,42,19  ; n1293 t=84.908s dur=126ms, freq=92Hz, sample=42, buffer_id=13:2A
    db 101,0,122,1,35,127,20,9,62,0,35,20  ; n1294 t=84.908s dur=378ms, freq=62Hz, sample=35, buffer_id=14:23
    db 101,0,126,0,41,127,19,10,87,0,41,19  ; n1295 t=85.009s dur=126ms, freq=87Hz, sample=41, buffer_id=13:29
    db 0,0,176,0,74,127,16,3,75,2,74,16  ; n1296 t=85.110s dur=176ms, freq=587Hz, sample=74, buffer_id=10:4A
    db 0,0,176,0,62,127,17,1,38,1,62,16  ; n1297 t=85.110s dur=176ms, freq=294Hz, sample=62, buffer_id=10:3E
    db 201,0,176,0,42,127,19,4,92,0,42,19  ; n1298 t=85.110s dur=176ms, freq=92Hz, sample=42, buffer_id=13:2A
    db 0,0,100,0,78,127,2,2,228,2,78,2  ; n1299 t=85.311s dur=100ms, freq=740Hz, sample=78, buffer_id=02:4E
    db 0,0,100,0,74,127,4,5,75,2,74,4  ; n1300 t=85.311s dur=100ms, freq=587Hz, sample=74, buffer_id=04:4A
    db 0,0,100,0,78,127,4,6,228,2,78,4  ; n1301 t=85.311s dur=100ms, freq=740Hz, sample=78, buffer_id=04:4E
    db 0,0,100,0,54,127,5,7,185,0,54,5  ; n1302 t=85.311s dur=100ms, freq=185Hz, sample=54, buffer_id=05:36
    db 0,0,100,0,50,127,6,8,147,0,50,5  ; n1303 t=85.311s dur=100ms, freq=147Hz, sample=50, buffer_id=05:32
    db 0,0,100,0,54,127,7,11,185,0,54,7  ; n1304 t=85.311s dur=100ms, freq=185Hz, sample=54, buffer_id=07:36
    db 0,0,100,0,66,127,7,12,114,1,66,7  ; n1305 t=85.311s dur=100ms, freq=370Hz, sample=66, buffer_id=07:42
    db 0,0,100,0,62,127,8,13,38,1,62,7  ; n1306 t=85.311s dur=100ms, freq=294Hz, sample=62, buffer_id=07:3E
    db 0,0,120,1,78,127,16,14,228,2,78,16  ; n1307 t=85.311s dur=376ms, freq=740Hz, sample=78, buffer_id=10:4E
    db 0,0,120,1,66,127,17,15,114,1,66,16  ; n1308 t=85.311s dur=376ms, freq=370Hz, sample=66, buffer_id=10:42
    db 0,0,125,0,54,127,18,17,185,0,54,18  ; n1309 t=85.311s dur=125ms, freq=185Hz, sample=54, buffer_id=12:36
    db 101,0,120,1,47,127,20,16,123,0,47,20  ; n1310 t=85.311s dur=376ms, freq=123Hz, sample=47, buffer_id=14:2F
    db 101,0,125,0,54,127,18,10,175,0,54,18  ; n1311 t=85.412s dur=125ms, freq=175Hz, sample=54, buffer_id=12:36
    db 201,0,175,0,54,127,18,0,185,0,54,18  ; n1312 t=85.513s dur=175ms, freq=185Hz, sample=54, buffer_id=12:36
    db 0,0,100,0,42,127,5,1,92,0,42,5  ; n1313 t=85.713s dur=100ms, freq=92Hz, sample=42, buffer_id=05:2A
    db 0,0,100,0,35,127,6,2,62,0,35,5  ; n1314 t=85.713s dur=100ms, freq=62Hz, sample=35, buffer_id=05:23
    db 0,0,175,0,78,127,16,3,186,2,78,16  ; n1315 t=85.713s dur=175ms, freq=698Hz, sample=78, buffer_id=10:4E
    db 0,0,175,0,65,127,17,4,93,1,65,16  ; n1316 t=85.713s dur=175ms, freq=349Hz, sample=65, buffer_id=10:41
    db 0,0,125,0,42,127,19,5,92,0,42,19  ; n1317 t=85.713s dur=125ms, freq=92Hz, sample=42, buffer_id=13:2A
    db 100,0,119,1,35,127,20,6,62,0,35,20  ; n1318 t=85.713s dur=375ms, freq=62Hz, sample=35, buffer_id=14:23
    db 100,0,125,0,41,127,19,7,87,0,41,19  ; n1319 t=85.814s dur=125ms, freq=87Hz, sample=41, buffer_id=13:29
    db 0,0,175,0,73,127,16,0,42,2,73,16  ; n1320 t=85.914s dur=175ms, freq=554Hz, sample=73, buffer_id=10:49
    db 0,0,175,0,61,127,17,8,21,1,61,16  ; n1321 t=85.914s dur=175ms, freq=277Hz, sample=61, buffer_id=10:3D
    db 200,0,175,0,42,127,19,9,92,0,42,19  ; n1322 t=85.914s dur=175ms, freq=92Hz, sample=42, buffer_id=13:2A
    db 0,0,100,0,78,127,2,1,228,2,78,2  ; n1323 t=86.114s dur=100ms, freq=740Hz, sample=78, buffer_id=02:4E
    db 0,0,100,0,73,127,4,2,42,2,73,4  ; n1324 t=86.114s dur=100ms, freq=554Hz, sample=73, buffer_id=04:49
    db 0,0,100,0,78,127,4,3,186,2,78,4  ; n1325 t=86.114s dur=100ms, freq=698Hz, sample=78, buffer_id=04:4E
    db 0,0,100,0,54,127,5,4,175,0,54,5  ; n1326 t=86.114s dur=100ms, freq=175Hz, sample=54, buffer_id=05:36
    db 0,0,100,0,49,127,6,5,139,0,49,5  ; n1327 t=86.114s dur=100ms, freq=139Hz, sample=49, buffer_id=05:31
    db 0,0,100,0,54,127,7,10,185,0,54,7  ; n1328 t=86.114s dur=100ms, freq=185Hz, sample=54, buffer_id=07:36
    db 0,0,100,0,66,127,7,11,114,1,66,7  ; n1329 t=86.114s dur=100ms, freq=370Hz, sample=66, buffer_id=07:42
    db 0,0,100,0,61,127,8,12,21,1,61,7  ; n1330 t=86.114s dur=100ms, freq=277Hz, sample=61, buffer_id=07:3D
    db 0,0,100,0,66,127,8,13,93,1,66,7  ; n1331 t=86.114s dur=100ms, freq=349Hz, sample=66, buffer_id=07:42
    db 0,0,118,1,78,127,16,15,186,2,78,16  ; n1332 t=86.114s dur=374ms, freq=698Hz, sample=78, buffer_id=10:4E
    db 0,0,118,1,65,127,17,14,93,1,65,16  ; n1333 t=86.114s dur=374ms, freq=349Hz, sample=65, buffer_id=10:41
    db 0,0,124,0,54,127,18,16,185,0,54,18  ; n1334 t=86.114s dur=124ms, freq=185Hz, sample=54, buffer_id=12:36
    db 100,0,118,1,47,127,20,17,123,0,47,20  ; n1335 t=86.114s dur=374ms, freq=123Hz, sample=47, buffer_id=14:2F
    db 100,0,124,0,54,127,18,7,175,0,54,18  ; n1336 t=86.214s dur=124ms, freq=175Hz, sample=54, buffer_id=12:36
    db 199,0,174,0,54,127,18,0,185,0,54,18  ; n1337 t=86.314s dur=174ms, freq=185Hz, sample=54, buffer_id=12:36
    db 0,0,100,0,42,127,5,1,92,0,42,5  ; n1338 t=86.513s dur=100ms, freq=92Hz, sample=42, buffer_id=05:2A
    db 0,0,100,0,35,127,6,2,62,0,35,5  ; n1339 t=86.513s dur=100ms, freq=62Hz, sample=35, buffer_id=05:23
    db 0,0,174,0,74,127,16,3,147,2,74,16  ; n1340 t=86.513s dur=174ms, freq=659Hz, sample=74, buffer_id=10:4A
    db 0,0,174,0,65,127,17,4,74,1,65,16  ; n1341 t=86.513s dur=174ms, freq=330Hz, sample=65, buffer_id=10:41
    db 0,0,124,0,42,127,19,5,92,0,42,19  ; n1342 t=86.513s dur=124ms, freq=92Hz, sample=42, buffer_id=13:2A
    db 99,0,116,1,35,127,20,8,62,0,35,20  ; n1343 t=86.513s dur=372ms, freq=62Hz, sample=35, buffer_id=14:23
    db 100,0,124,0,41,127,19,6,87,0,41,19  ; n1344 t=86.612s dur=124ms, freq=87Hz, sample=41, buffer_id=13:29
    db 0,0,173,0,73,127,16,0,11,2,73,16  ; n1345 t=86.712s dur=173ms, freq=523Hz, sample=73, buffer_id=10:49
    db 0,0,173,0,59,127,17,7,6,1,59,16  ; n1346 t=86.712s dur=173ms, freq=262Hz, sample=59, buffer_id=10:3B
    db 199,0,173,0,42,127,19,10,92,0,42,19  ; n1347 t=86.712s dur=173ms, freq=92Hz, sample=42, buffer_id=13:2A
    db 0,0,100,0,78,127,2,1,228,2,78,2  ; n1348 t=86.910s dur=100ms, freq=740Hz, sample=78, buffer_id=02:4E
    db 0,0,100,0,73,127,4,2,11,2,73,4  ; n1349 t=86.910s dur=100ms, freq=523Hz, sample=73, buffer_id=04:49
    db 0,0,100,0,74,127,4,3,147,2,74,4  ; n1350 t=86.910s dur=100ms, freq=659Hz, sample=74, buffer_id=04:4A
    db 0,0,100,0,50,127,5,4,165,0,50,5  ; n1351 t=86.910s dur=100ms, freq=165Hz, sample=50, buffer_id=05:32
    db 0,0,100,0,47,127,6,5,131,0,47,5  ; n1352 t=86.910s dur=100ms, freq=131Hz, sample=47, buffer_id=05:2F
    db 0,0,100,0,54,127,7,9,185,0,54,7  ; n1353 t=86.910s dur=100ms, freq=185Hz, sample=54, buffer_id=07:36
    db 0,0,100,0,66,127,7,12,114,1,66,7  ; n1354 t=86.910s dur=100ms, freq=370Hz, sample=66, buffer_id=07:42
    db 0,0,100,0,59,127,8,11,6,1,59,7  ; n1355 t=86.910s dur=100ms, freq=262Hz, sample=59, buffer_id=07:3B
    db 0,0,100,0,62,127,8,13,74,1,62,7  ; n1356 t=86.910s dur=100ms, freq=330Hz, sample=62, buffer_id=07:3E
    db 0,0,115,1,74,127,16,14,147,2,74,16  ; n1357 t=86.910s dur=371ms, freq=659Hz, sample=74, buffer_id=10:4A
    db 0,0,115,1,65,127,17,15,74,1,65,16  ; n1358 t=86.910s dur=371ms, freq=330Hz, sample=65, buffer_id=10:41
    db 0,0,123,0,54,127,18,17,185,0,54,18  ; n1359 t=86.910s dur=123ms, freq=185Hz, sample=54, buffer_id=12:36
    db 99,0,115,1,47,127,20,16,123,0,47,20  ; n1360 t=86.910s dur=371ms, freq=123Hz, sample=47, buffer_id=14:2F
    db 99,0,123,0,54,127,18,6,175,0,54,18  ; n1361 t=87.010s dur=123ms, freq=175Hz, sample=54, buffer_id=12:36
    db 195,0,173,0,54,127,18,0,185,0,54,18  ; n1362 t=87.109s dur=173ms, freq=185Hz, sample=54, buffer_id=12:36
    db 2,0,114,1,47,127,10,1,123,0,47,10  ; n1363 t=87.304s dur=370ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 0,0,100,0,42,127,5,2,92,0,42,5  ; n1364 t=87.307s dur=100ms, freq=92Hz, sample=42, buffer_id=05:2A
    db 0,0,100,0,35,127,6,3,62,0,35,5  ; n1365 t=87.307s dur=100ms, freq=62Hz, sample=35, buffer_id=05:23
    db 0,0,172,0,70,127,16,4,238,1,70,16  ; n1366 t=87.307s dur=172ms, freq=494Hz, sample=70, buffer_id=10:46
    db 0,0,172,0,59,127,17,5,247,0,59,16  ; n1367 t=87.307s dur=172ms, freq=247Hz, sample=59, buffer_id=10:3B
    db 0,0,123,0,42,127,19,7,92,0,42,19  ; n1368 t=87.307s dur=123ms, freq=92Hz, sample=42, buffer_id=13:2A
    db 99,0,114,1,35,127,20,9,62,0,35,20  ; n1369 t=87.307s dur=370ms, freq=62Hz, sample=35, buffer_id=14:23
    db 99,0,123,0,41,127,19,6,87,0,41,19  ; n1370 t=87.405s dur=123ms, freq=87Hz, sample=41, buffer_id=13:29
    db 0,0,172,0,73,127,16,0,42,2,73,16  ; n1371 t=87.504s dur=172ms, freq=554Hz, sample=73, buffer_id=10:49
    db 0,0,172,0,61,127,17,8,21,1,61,16  ; n1372 t=87.504s dur=172ms, freq=277Hz, sample=61, buffer_id=10:3D
    db 197,0,172,0,42,127,19,11,92,0,42,19  ; n1373 t=87.504s dur=172ms, freq=92Hz, sample=42, buffer_id=13:2A
    db 0,0,100,0,78,127,2,2,228,2,78,2  ; n1374 t=87.701s dur=100ms, freq=740Hz, sample=78, buffer_id=02:4E
    db 0,0,100,0,70,127,4,3,238,1,70,4  ; n1375 t=87.701s dur=100ms, freq=494Hz, sample=70, buffer_id=04:46
    db 0,0,100,0,74,127,4,4,75,2,74,4  ; n1376 t=87.701s dur=100ms, freq=587Hz, sample=74, buffer_id=04:4A
    db 0,0,100,0,50,127,5,5,147,0,50,5  ; n1377 t=87.701s dur=100ms, freq=147Hz, sample=50, buffer_id=05:32
    db 0,0,100,0,47,127,6,7,123,0,47,5  ; n1378 t=87.701s dur=100ms, freq=123Hz, sample=47, buffer_id=05:2F
    db 0,0,100,0,54,127,7,10,185,0,54,7  ; n1379 t=87.701s dur=100ms, freq=185Hz, sample=54, buffer_id=07:36
    db 0,0,100,0,66,127,7,13,114,1,66,7  ; n1380 t=87.701s dur=100ms, freq=370Hz, sample=66, buffer_id=07:42
    db 0,0,100,0,59,127,8,12,247,0,59,7  ; n1381 t=87.701s dur=100ms, freq=247Hz, sample=59, buffer_id=07:3B
    db 0,0,100,0,62,127,8,14,38,1,62,7  ; n1382 t=87.701s dur=100ms, freq=294Hz, sample=62, buffer_id=07:3E
    db 0,0,172,0,74,127,16,15,75,2,74,16  ; n1383 t=87.701s dur=172ms, freq=587Hz, sample=74, buffer_id=10:4A
    db 0,0,172,0,62,127,17,16,38,1,62,16  ; n1384 t=87.701s dur=172ms, freq=294Hz, sample=62, buffer_id=10:3E
    db 0,0,123,0,54,127,18,18,185,0,54,18  ; n1385 t=87.701s dur=123ms, freq=185Hz, sample=54, buffer_id=12:36
    db 98,0,112,1,47,127,20,17,123,0,47,20  ; n1386 t=87.701s dur=368ms, freq=123Hz, sample=47, buffer_id=14:2F
    db 98,0,123,0,54,127,18,6,175,0,54,18  ; n1387 t=87.800s dur=123ms, freq=175Hz, sample=54, buffer_id=12:36
    db 0,0,171,0,74,127,16,0,147,2,74,16  ; n1388 t=87.898s dur=171ms, freq=659Hz, sample=74, buffer_id=10:4A
    db 0,0,171,0,65,127,17,1,74,1,65,16  ; n1389 t=87.898s dur=171ms, freq=330Hz, sample=65, buffer_id=10:41
    db 194,0,171,0,54,127,18,8,185,0,54,18  ; n1390 t=87.898s dur=171ms, freq=185Hz, sample=54, buffer_id=12:36
    db 2,0,111,1,47,127,10,2,123,0,47,10  ; n1391 t=88.092s dur=367ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 0,0,100,0,42,127,5,3,92,0,42,5  ; n1392 t=88.095s dur=100ms, freq=92Hz, sample=42, buffer_id=05:2A
    db 0,0,100,0,35,127,6,4,62,0,35,5  ; n1393 t=88.095s dur=100ms, freq=62Hz, sample=35, buffer_id=05:23
    db 0,0,171,0,78,127,16,5,228,2,78,16  ; n1394 t=88.095s dur=171ms, freq=740Hz, sample=78, buffer_id=10:4E
    db 0,0,171,0,66,127,17,7,114,1,66,16  ; n1395 t=88.095s dur=171ms, freq=370Hz, sample=66, buffer_id=10:42
    db 0,0,122,0,42,127,19,9,92,0,42,19  ; n1396 t=88.095s dur=122ms, freq=92Hz, sample=42, buffer_id=13:2A
    db 98,0,111,1,35,127,20,10,62,0,35,20  ; n1397 t=88.095s dur=367ms, freq=62Hz, sample=35, buffer_id=14:23
    db 98,0,122,0,41,127,19,6,87,0,41,19  ; n1398 t=88.193s dur=122ms, freq=87Hz, sample=41, buffer_id=13:29
    db 0,0,171,0,74,127,16,1,75,2,74,16  ; n1399 t=88.291s dur=171ms, freq=587Hz, sample=74, buffer_id=10:4A
    db 0,0,171,0,62,127,17,0,38,1,62,16  ; n1400 t=88.291s dur=171ms, freq=294Hz, sample=62, buffer_id=10:3E
    db 196,0,171,0,42,127,19,8,92,0,42,19  ; n1401 t=88.291s dur=171ms, freq=92Hz, sample=42, buffer_id=13:2A
    db 0,0,100,0,78,127,2,3,228,2,78,2  ; n1402 t=88.487s dur=100ms, freq=740Hz, sample=78, buffer_id=02:4E
    db 0,0,100,0,70,127,4,4,238,1,70,4  ; n1403 t=88.487s dur=100ms, freq=494Hz, sample=70, buffer_id=04:46
    db 0,0,100,0,74,127,4,5,75,2,74,4  ; n1404 t=88.487s dur=100ms, freq=587Hz, sample=74, buffer_id=04:4A
    db 0,0,100,0,50,127,5,7,147,0,50,5  ; n1405 t=88.487s dur=100ms, freq=147Hz, sample=50, buffer_id=05:32
    db 0,0,100,0,47,127,6,9,123,0,47,5  ; n1406 t=88.487s dur=100ms, freq=123Hz, sample=47, buffer_id=05:2F
    db 0,0,100,0,54,127,7,11,185,0,54,7  ; n1407 t=88.487s dur=100ms, freq=185Hz, sample=54, buffer_id=07:36
    db 0,0,100,0,66,127,7,12,114,1,66,7  ; n1408 t=88.487s dur=100ms, freq=370Hz, sample=66, buffer_id=07:42
    db 0,0,100,0,59,127,8,13,247,0,59,7  ; n1409 t=88.487s dur=100ms, freq=247Hz, sample=59, buffer_id=07:3B
    db 0,0,100,0,62,127,8,15,38,1,62,7  ; n1410 t=88.487s dur=100ms, freq=294Hz, sample=62, buffer_id=07:3E
    db 0,0,171,0,78,127,16,14,228,2,78,16  ; n1411 t=88.487s dur=171ms, freq=740Hz, sample=78, buffer_id=10:4E
    db 0,0,171,0,66,127,17,16,114,1,66,16  ; n1412 t=88.487s dur=171ms, freq=370Hz, sample=66, buffer_id=10:42
    db 0,0,122,0,54,127,18,17,185,0,54,18  ; n1413 t=88.487s dur=122ms, freq=185Hz, sample=54, buffer_id=12:36
    db 98,0,110,1,47,127,20,18,123,0,47,20  ; n1414 t=88.487s dur=366ms, freq=123Hz, sample=47, buffer_id=14:2F
    db 98,0,122,0,54,127,18,6,175,0,54,18  ; n1415 t=88.584s dur=122ms, freq=175Hz, sample=54, buffer_id=12:36
    db 0,0,170,0,85,127,16,0,220,3,85,16  ; n1416 t=88.682s dur=170ms, freq=988Hz, sample=85, buffer_id=10:55
    db 0,0,170,0,70,127,17,1,238,1,70,16  ; n1417 t=88.682s dur=170ms, freq=494Hz, sample=70, buffer_id=10:46
    db 195,0,170,0,54,127,18,2,185,0,54,18  ; n1418 t=88.682s dur=170ms, freq=185Hz, sample=54, buffer_id=12:36
    db 0,0,100,0,47,127,5,3,110,0,47,5  ; n1419 t=88.877s dur=100ms, freq=110Hz, sample=47, buffer_id=05:2F
    db 0,0,100,0,35,127,6,4,73,0,35,5  ; n1420 t=88.877s dur=100ms, freq=73Hz, sample=35, buffer_id=05:23
    db 0,0,170,0,78,127,16,5,112,3,78,16  ; n1421 t=88.877s dur=170ms, freq=880Hz, sample=78, buffer_id=10:4E
    db 0,0,170,0,69,127,17,7,184,1,69,16  ; n1422 t=88.877s dur=170ms, freq=440Hz, sample=69, buffer_id=10:45
    db 0,0,121,0,47,127,19,8,110,0,47,19  ; n1423 t=88.877s dur=121ms, freq=110Hz, sample=47, buffer_id=13:2F
    db 97,0,108,1,35,127,20,9,73,0,35,20  ; n1424 t=88.877s dur=364ms, freq=73Hz, sample=35, buffer_id=14:23
    db 97,0,121,0,42,127,19,6,104,0,42,19  ; n1425 t=88.974s dur=121ms, freq=104Hz, sample=42, buffer_id=13:2A
    db 0,0,170,0,78,127,16,0,228,2,78,16  ; n1426 t=89.072s dur=170ms, freq=740Hz, sample=78, buffer_id=10:4E
    db 0,0,170,0,66,127,17,1,114,1,66,16  ; n1427 t=89.072s dur=170ms, freq=370Hz, sample=66, buffer_id=10:42
    db 194,0,170,0,47,127,19,2,110,0,47,19  ; n1428 t=89.072s dur=170ms, freq=110Hz, sample=47, buffer_id=13:2F
    db 0,0,100,0,78,127,2,3,228,2,78,2  ; n1429 t=89.266s dur=100ms, freq=740Hz, sample=78, buffer_id=02:4E
    db 0,0,100,0,70,127,4,4,184,1,70,4  ; n1430 t=89.266s dur=100ms, freq=440Hz, sample=70, buffer_id=04:46
    db 0,0,100,0,74,127,4,5,75,2,74,4  ; n1431 t=89.266s dur=100ms, freq=587Hz, sample=74, buffer_id=04:4A
    db 0,0,100,0,50,127,5,7,147,0,50,5  ; n1432 t=89.266s dur=100ms, freq=147Hz, sample=50, buffer_id=05:32
    db 0,0,100,0,47,127,6,8,110,0,47,5  ; n1433 t=89.266s dur=100ms, freq=110Hz, sample=47, buffer_id=05:2F
    db 0,0,100,0,54,127,7,10,185,0,54,7  ; n1434 t=89.266s dur=100ms, freq=185Hz, sample=54, buffer_id=07:36
    db 0,0,100,0,66,127,7,11,114,1,66,7  ; n1435 t=89.266s dur=100ms, freq=370Hz, sample=66, buffer_id=07:42
    db 0,0,100,0,57,127,8,12,220,0,57,7  ; n1436 t=89.266s dur=100ms, freq=220Hz, sample=57, buffer_id=07:39
    db 0,0,100,0,62,127,8,13,38,1,62,7  ; n1437 t=89.266s dur=100ms, freq=294Hz, sample=62, buffer_id=07:3E
    db 0,0,169,0,74,127,16,14,75,2,74,16  ; n1438 t=89.266s dur=169ms, freq=587Hz, sample=74, buffer_id=10:4A
    db 0,0,169,0,62,127,17,15,38,1,62,16  ; n1439 t=89.266s dur=169ms, freq=294Hz, sample=62, buffer_id=10:3E
    db 0,0,121,0,54,127,18,16,220,0,54,18  ; n1440 t=89.266s dur=121ms, freq=220Hz, sample=54, buffer_id=12:36
    db 97,0,107,1,50,127,20,17,147,0,50,20  ; n1441 t=89.266s dur=363ms, freq=147Hz, sample=50, buffer_id=14:32
    db 97,0,121,0,54,127,18,6,208,0,54,18  ; n1442 t=89.363s dur=121ms, freq=208Hz, sample=54, buffer_id=12:36
    db 0,0,169,0,78,127,16,1,228,2,78,16  ; n1443 t=89.460s dur=169ms, freq=740Hz, sample=78, buffer_id=10:4E
    db 0,0,169,0,66,127,17,0,114,1,66,16  ; n1444 t=89.460s dur=169ms, freq=370Hz, sample=66, buffer_id=10:42
    db 194,0,169,0,54,127,18,2,220,0,54,18  ; n1445 t=89.460s dur=169ms, freq=220Hz, sample=54, buffer_id=12:36
    db 0,0,235,2,71,127,3,3,184,1,71,3  ; n1446 t=89.654s dur=747ms, freq=440Hz, sample=71, buffer_id=03:47
    db 0,0,145,2,78,127,3,4,112,3,78,3  ; n1447 t=89.654s dur=657ms, freq=880Hz, sample=78, buffer_id=03:4E
    db 0,0,100,0,47,127,5,5,110,0,47,5  ; n1448 t=89.654s dur=100ms, freq=110Hz, sample=47, buffer_id=05:2F
    db 0,0,100,0,35,127,6,7,73,0,35,5  ; n1449 t=89.654s dur=100ms, freq=73Hz, sample=35, buffer_id=05:23
    db 0,0,106,1,78,127,16,8,112,3,78,16  ; n1450 t=89.654s dur=362ms, freq=880Hz, sample=78, buffer_id=10:4E
    db 0,0,106,1,69,127,17,9,184,1,69,16  ; n1451 t=89.654s dur=362ms, freq=440Hz, sample=69, buffer_id=10:45
    db 0,0,120,0,47,127,19,10,110,0,47,19  ; n1452 t=89.654s dur=120ms, freq=110Hz, sample=47, buffer_id=13:2F
    db 97,0,106,1,35,127,20,11,73,0,35,20  ; n1453 t=89.654s dur=362ms, freq=73Hz, sample=35, buffer_id=14:23
    db 97,0,120,0,42,127,19,6,104,0,42,19  ; n1454 t=89.751s dur=120ms, freq=104Hz, sample=42, buffer_id=13:2A
    db 193,0,168,0,47,127,19,0,110,0,47,19  ; n1455 t=89.847s dur=168ms, freq=110Hz, sample=47, buffer_id=13:2F
    db 0,0,100,0,78,127,2,1,228,2,78,2  ; n1456 t=90.040s dur=100ms, freq=740Hz, sample=78, buffer_id=02:4E
    db 0,0,100,0,70,127,4,2,184,1,70,4  ; n1457 t=90.040s dur=100ms, freq=440Hz, sample=70, buffer_id=04:46
    db 0,0,100,0,74,127,4,5,75,2,74,4  ; n1458 t=90.040s dur=100ms, freq=587Hz, sample=74, buffer_id=04:4A
    db 0,0,100,0,50,127,5,7,147,0,50,5  ; n1459 t=90.040s dur=100ms, freq=147Hz, sample=50, buffer_id=05:32
    db 0,0,100,0,47,127,6,10,110,0,47,5  ; n1460 t=90.040s dur=100ms, freq=110Hz, sample=47, buffer_id=05:2F
    db 0,0,100,0,54,127,7,12,185,0,54,7  ; n1461 t=90.040s dur=100ms, freq=185Hz, sample=54, buffer_id=07:36
    db 0,0,100,0,66,127,7,13,114,1,66,7  ; n1462 t=90.040s dur=100ms, freq=370Hz, sample=66, buffer_id=07:42
    db 0,0,100,0,57,127,8,14,220,0,57,7  ; n1463 t=90.040s dur=100ms, freq=220Hz, sample=57, buffer_id=07:39
    db 0,0,100,0,62,127,8,15,38,1,62,7  ; n1464 t=90.040s dur=100ms, freq=294Hz, sample=62, buffer_id=07:3E
    db 0,0,120,0,54,127,18,17,220,0,54,18  ; n1465 t=90.040s dur=120ms, freq=220Hz, sample=54, buffer_id=12:36
    db 96,0,105,1,50,127,20,16,147,0,50,20  ; n1466 t=90.040s dur=361ms, freq=147Hz, sample=50, buffer_id=14:32
    db 96,0,120,0,54,127,18,6,208,0,54,18  ; n1467 t=90.136s dur=120ms, freq=208Hz, sample=54, buffer_id=12:36
    db 190,0,168,0,54,127,18,0,220,0,54,18  ; n1468 t=90.233s dur=168ms, freq=220Hz, sample=54, buffer_id=12:36
    db 2,0,103,1,47,127,10,1,123,0,47,10  ; n1469 t=90.423s dur=359ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 0,0,100,0,59,127,3,2,247,0,59,3  ; n1470 t=90.425s dur=100ms, freq=247Hz, sample=59, buffer_id=03:3B
    db 0,0,100,0,71,127,3,5,238,1,71,3  ; n1471 t=90.425s dur=100ms, freq=494Hz, sample=71, buffer_id=03:47
    db 0,0,100,0,42,127,5,7,92,0,42,5  ; n1472 t=90.425s dur=100ms, freq=92Hz, sample=42, buffer_id=05:2A
    db 0,0,100,0,35,127,6,8,62,0,35,5  ; n1473 t=90.425s dur=100ms, freq=62Hz, sample=35, buffer_id=05:23
    db 0,0,100,0,54,127,18,9,185,0,54,18  ; n1474 t=90.425s dur=100ms, freq=185Hz, sample=54, buffer_id=12:36
    db 0,0,100,0,42,127,19,10,92,0,42,19  ; n1475 t=90.425s dur=100ms, freq=92Hz, sample=42, buffer_id=13:2A
    db 77,0,103,1,35,127,20,12,62,0,35,20  ; n1476 t=90.425s dur=359ms, freq=62Hz, sample=35, buffer_id=14:23
    db 0,0,100,0,54,127,18,11,196,0,54,18  ; n1477 t=90.502s dur=100ms, freq=196Hz, sample=54, buffer_id=12:36
    db 77,0,100,0,42,127,19,6,98,0,42,19  ; n1478 t=90.502s dur=100ms, freq=98Hz, sample=42, buffer_id=13:2A
    db 0,0,100,0,54,127,18,4,185,0,54,18  ; n1479 t=90.579s dur=100ms, freq=185Hz, sample=54, buffer_id=12:36
    db 38,0,100,0,42,127,19,13,92,0,42,19  ; n1480 t=90.579s dur=100ms, freq=92Hz, sample=42, buffer_id=13:2A
    db 0,0,100,0,62,127,3,0,21,1,62,3  ; n1481 t=90.617s dur=100ms, freq=277Hz, sample=62, buffer_id=03:3E
    db 38,0,100,0,73,127,3,3,42,2,73,3  ; n1482 t=90.617s dur=100ms, freq=554Hz, sample=73, buffer_id=03:49
    db 0,0,100,0,54,127,18,14,175,0,54,18  ; n1483 t=90.656s dur=100ms, freq=175Hz, sample=54, buffer_id=12:36
    db 77,0,100,0,41,127,19,15,87,0,41,19  ; n1484 t=90.656s dur=100ms, freq=87Hz, sample=41, buffer_id=13:29
    db 0,0,100,0,54,127,18,2,185,0,54,18  ; n1485 t=90.732s dur=100ms, freq=185Hz, sample=54, buffer_id=12:36
    db 77,0,100,0,42,127,19,5,92,0,42,19  ; n1486 t=90.732s dur=100ms, freq=92Hz, sample=42, buffer_id=13:2A
    db 0,0,100,0,78,127,2,6,228,2,78,2  ; n1487 t=90.809s dur=100ms, freq=740Hz, sample=78, buffer_id=02:4E
    db 0,0,100,0,62,127,3,7,38,1,62,3  ; n1488 t=90.809s dur=100ms, freq=294Hz, sample=62, buffer_id=03:3E
    db 0,0,100,0,74,127,3,8,75,2,74,3  ; n1489 t=90.809s dur=100ms, freq=587Hz, sample=74, buffer_id=03:4A
    db 0,0,100,0,74,127,4,9,75,2,74,4  ; n1490 t=90.809s dur=100ms, freq=587Hz, sample=74, buffer_id=04:4A
    db 0,0,100,0,78,127,4,10,228,2,78,4  ; n1491 t=90.809s dur=100ms, freq=740Hz, sample=78, buffer_id=04:4E
    db 0,0,100,0,54,127,5,11,185,0,54,5  ; n1492 t=90.809s dur=100ms, freq=185Hz, sample=54, buffer_id=05:36
    db 0,0,100,0,50,127,6,16,147,0,50,5  ; n1493 t=90.809s dur=100ms, freq=147Hz, sample=50, buffer_id=05:32
    db 0,0,100,0,54,127,7,17,185,0,54,7  ; n1494 t=90.809s dur=100ms, freq=185Hz, sample=54, buffer_id=07:36
    db 0,0,100,0,66,127,7,18,114,1,66,7  ; n1495 t=90.809s dur=100ms, freq=370Hz, sample=66, buffer_id=07:42
    db 0,0,100,0,62,127,8,19,38,1,62,7  ; n1496 t=90.809s dur=100ms, freq=294Hz, sample=62, buffer_id=07:3E
    db 0,0,100,0,78,127,16,20,228,2,78,16  ; n1497 t=90.809s dur=100ms, freq=740Hz, sample=78, buffer_id=10:4E
    db 0,0,100,0,66,127,17,21,114,1,66,16  ; n1498 t=90.809s dur=100ms, freq=370Hz, sample=66, buffer_id=10:42
    db 77,0,102,1,47,127,20,22,123,0,47,20  ; n1499 t=90.809s dur=358ms, freq=123Hz, sample=47, buffer_id=14:2F
    db 0,0,100,0,78,127,16,4,16,3,78,16  ; n1500 t=90.885s dur=100ms, freq=784Hz, sample=78, buffer_id=10:4E
    db 76,0,100,0,66,127,17,13,136,1,66,16  ; n1501 t=90.885s dur=100ms, freq=392Hz, sample=66, buffer_id=10:42
    db 0,0,100,0,78,127,16,0,228,2,78,16  ; n1502 t=90.962s dur=100ms, freq=740Hz, sample=78, buffer_id=10:4E
    db 38,0,100,0,66,127,17,3,114,1,66,16  ; n1503 t=90.962s dur=100ms, freq=370Hz, sample=66, buffer_id=10:42
    db 0,0,100,0,62,127,3,1,74,1,62,3  ; n1504 t=91.000s dur=100ms, freq=330Hz, sample=62, buffer_id=03:3E
    db 38,0,100,0,74,127,3,12,147,2,74,3  ; n1505 t=91.000s dur=100ms, freq=659Hz, sample=74, buffer_id=03:4A
    db 0,0,100,0,78,127,16,2,186,2,78,16  ; n1506 t=91.038s dur=100ms, freq=698Hz, sample=78, buffer_id=10:4E
    db 76,0,100,0,65,127,17,5,93,1,65,16  ; n1507 t=91.038s dur=100ms, freq=349Hz, sample=65, buffer_id=10:41
    db 0,0,100,0,78,127,16,6,228,2,78,16  ; n1508 t=91.115s dur=100ms, freq=740Hz, sample=78, buffer_id=10:4E
    db 74,0,100,0,66,127,17,7,114,1,66,16  ; n1509 t=91.115s dur=100ms, freq=370Hz, sample=66, buffer_id=10:42
    db 2,0,101,1,47,127,10,4,123,0,47,10  ; n1510 t=91.189s dur=357ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 0,0,100,0,66,127,3,8,114,1,66,3  ; n1511 t=91.191s dur=100ms, freq=370Hz, sample=66, buffer_id=03:42
    db 0,0,100,0,78,127,3,9,228,2,78,3  ; n1512 t=91.191s dur=100ms, freq=740Hz, sample=78, buffer_id=03:4E
    db 0,0,100,0,42,127,5,10,92,0,42,5  ; n1513 t=91.191s dur=100ms, freq=92Hz, sample=42, buffer_id=05:2A
    db 0,0,100,0,35,127,6,11,62,0,35,5  ; n1514 t=91.191s dur=100ms, freq=62Hz, sample=35, buffer_id=05:23
    db 0,0,100,0,54,127,18,13,185,0,54,18  ; n1515 t=91.191s dur=100ms, freq=185Hz, sample=54, buffer_id=12:36
    db 0,0,100,0,42,127,19,14,92,0,42,19  ; n1516 t=91.191s dur=100ms, freq=92Hz, sample=42, buffer_id=13:2A
    db 76,0,101,1,35,127,20,15,62,0,35,20  ; n1517 t=91.191s dur=357ms, freq=62Hz, sample=35, buffer_id=14:23
    db 0,0,100,0,54,127,18,0,196,0,54,18  ; n1518 t=91.267s dur=100ms, freq=196Hz, sample=54, buffer_id=12:36
    db 76,0,100,0,42,127,19,3,98,0,42,19  ; n1519 t=91.267s dur=100ms, freq=98Hz, sample=42, buffer_id=13:2A
    db 0,0,100,0,54,127,18,1,185,0,54,18  ; n1520 t=91.344s dur=100ms, freq=185Hz, sample=54, buffer_id=12:36
    db 38,0,100,0,42,127,19,2,92,0,42,19  ; n1521 t=91.344s dur=100ms, freq=92Hz, sample=42, buffer_id=13:2A
    db 0,0,100,0,62,127,3,5,38,1,62,3  ; n1522 t=91.382s dur=100ms, freq=294Hz, sample=62, buffer_id=03:3E
    db 38,0,100,0,74,127,3,16,75,2,74,3  ; n1523 t=91.382s dur=100ms, freq=587Hz, sample=74, buffer_id=03:4A
    db 0,0,100,0,54,127,18,6,175,0,54,18  ; n1524 t=91.420s dur=100ms, freq=175Hz, sample=54, buffer_id=12:36
    db 76,0,100,0,41,127,19,7,87,0,41,19  ; n1525 t=91.420s dur=100ms, freq=87Hz, sample=41, buffer_id=13:29
    db 0,0,100,0,54,127,18,8,185,0,54,18  ; n1526 t=91.496s dur=100ms, freq=185Hz, sample=54, buffer_id=12:36
    db 76,0,100,0,42,127,19,9,92,0,42,19  ; n1527 t=91.496s dur=100ms, freq=92Hz, sample=42, buffer_id=13:2A
    db 0,0,100,0,78,127,2,0,228,2,78,2  ; n1528 t=91.572s dur=100ms, freq=740Hz, sample=78, buffer_id=02:4E
    db 0,0,100,0,66,127,3,3,114,1,66,3  ; n1529 t=91.572s dur=100ms, freq=370Hz, sample=66, buffer_id=03:42
    db 0,0,100,0,78,127,3,10,228,2,78,3  ; n1530 t=91.572s dur=100ms, freq=740Hz, sample=78, buffer_id=03:4E
    db 0,0,100,0,74,127,4,11,75,2,74,4  ; n1531 t=91.572s dur=100ms, freq=587Hz, sample=74, buffer_id=04:4A
    db 0,0,100,0,78,127,4,12,228,2,78,4  ; n1532 t=91.572s dur=100ms, freq=740Hz, sample=78, buffer_id=04:4E
    db 0,0,100,0,54,127,5,13,185,0,54,5  ; n1533 t=91.572s dur=100ms, freq=185Hz, sample=54, buffer_id=05:36
    db 0,0,100,0,50,127,6,14,147,0,50,5  ; n1534 t=91.572s dur=100ms, freq=147Hz, sample=50, buffer_id=05:32
    db 0,0,100,0,54,127,7,18,185,0,54,7  ; n1535 t=91.572s dur=100ms, freq=185Hz, sample=54, buffer_id=07:36
    db 0,0,100,0,66,127,7,17,114,1,66,7  ; n1536 t=91.572s dur=100ms, freq=370Hz, sample=66, buffer_id=07:42
    db 0,0,100,0,62,127,8,20,38,1,62,7  ; n1537 t=91.572s dur=100ms, freq=294Hz, sample=62, buffer_id=07:3E
    db 0,0,100,0,78,127,16,19,228,2,78,16  ; n1538 t=91.572s dur=100ms, freq=740Hz, sample=78, buffer_id=10:4E
    db 0,0,100,0,66,127,17,22,114,1,66,16  ; n1539 t=91.572s dur=100ms, freq=370Hz, sample=66, buffer_id=10:42
    db 76,0,100,1,47,127,20,21,123,0,47,20  ; n1540 t=91.572s dur=356ms, freq=123Hz, sample=47, buffer_id=14:2F
    db 0,0,100,0,78,127,16,1,16,3,78,16  ; n1541 t=91.648s dur=100ms, freq=784Hz, sample=78, buffer_id=10:4E
    db 76,0,100,0,66,127,17,2,136,1,66,16  ; n1542 t=91.648s dur=100ms, freq=392Hz, sample=66, buffer_id=10:42
    db 0,0,100,0,78,127,16,5,228,2,78,16  ; n1543 t=91.724s dur=100ms, freq=740Hz, sample=78, buffer_id=10:4E
    db 76,0,100,0,66,127,17,6,114,1,66,16  ; n1544 t=91.724s dur=100ms, freq=370Hz, sample=66, buffer_id=10:42
    db 0,0,100,0,78,127,16,4,186,2,78,16  ; n1545 t=91.800s dur=100ms, freq=698Hz, sample=78, buffer_id=10:4E
    db 76,0,100,0,65,127,17,7,93,1,65,16  ; n1546 t=91.800s dur=100ms, freq=349Hz, sample=65, buffer_id=10:41
    db 0,0,100,0,78,127,16,0,228,2,78,16  ; n1547 t=91.876s dur=100ms, freq=740Hz, sample=78, buffer_id=10:4E
    db 76,0,100,0,66,127,17,3,114,1,66,16  ; n1548 t=91.876s dur=100ms, freq=370Hz, sample=66, buffer_id=10:42
    db 0,0,100,0,66,127,3,1,93,1,66,3  ; n1549 t=91.952s dur=100ms, freq=349Hz, sample=66, buffer_id=03:42
    db 0,0,100,0,78,127,3,2,186,2,78,3  ; n1550 t=91.952s dur=100ms, freq=698Hz, sample=78, buffer_id=03:4E
    db 0,0,100,0,42,127,5,8,92,0,42,5  ; n1551 t=91.952s dur=100ms, freq=92Hz, sample=42, buffer_id=05:2A
    db 0,0,100,0,35,127,6,9,62,0,35,5  ; n1552 t=91.952s dur=100ms, freq=62Hz, sample=35, buffer_id=05:23
    db 0,0,100,0,54,127,18,10,185,0,54,18  ; n1553 t=91.952s dur=100ms, freq=185Hz, sample=54, buffer_id=12:36
    db 0,0,100,0,42,127,19,11,92,0,42,19  ; n1554 t=91.952s dur=100ms, freq=92Hz, sample=42, buffer_id=13:2A
    db 76,0,98,1,35,127,20,12,62,0,35,20  ; n1555 t=91.952s dur=354ms, freq=62Hz, sample=35, buffer_id=14:23
    db 0,0,100,0,54,127,18,5,196,0,54,18  ; n1556 t=92.028s dur=100ms, freq=196Hz, sample=54, buffer_id=12:36
    db 76,0,100,0,42,127,19,6,98,0,42,19  ; n1557 t=92.028s dur=100ms, freq=98Hz, sample=42, buffer_id=13:2A
    db 0,0,100,0,54,127,18,4,185,0,54,18  ; n1558 t=92.103s dur=100ms, freq=185Hz, sample=54, buffer_id=12:36
    db 38,0,100,0,42,127,19,7,92,0,42,19  ; n1559 t=92.103s dur=100ms, freq=92Hz, sample=42, buffer_id=13:2A
    db 0,0,100,0,62,127,3,13,21,1,62,3  ; n1560 t=92.141s dur=100ms, freq=277Hz, sample=62, buffer_id=03:3E
    db 38,0,100,0,73,127,3,14,42,2,73,3  ; n1561 t=92.141s dur=100ms, freq=554Hz, sample=73, buffer_id=03:49
    db 0,0,100,0,54,127,18,0,175,0,54,18  ; n1562 t=92.179s dur=100ms, freq=175Hz, sample=54, buffer_id=12:36
    db 76,0,100,0,41,127,19,3,87,0,41,19  ; n1563 t=92.179s dur=100ms, freq=87Hz, sample=41, buffer_id=13:29
    db 0,0,100,0,54,127,18,1,185,0,54,18  ; n1564 t=92.255s dur=100ms, freq=185Hz, sample=54, buffer_id=12:36
    db 76,0,100,0,42,127,19,2,92,0,42,19  ; n1565 t=92.255s dur=100ms, freq=92Hz, sample=42, buffer_id=13:2A
    db 0,0,100,0,78,127,2,5,228,2,78,2  ; n1566 t=92.330s dur=100ms, freq=740Hz, sample=78, buffer_id=02:4E
    db 0,0,100,0,66,127,3,6,93,1,66,3  ; n1567 t=92.330s dur=100ms, freq=349Hz, sample=66, buffer_id=03:42
    db 0,0,100,0,78,127,3,8,186,2,78,3  ; n1568 t=92.330s dur=100ms, freq=698Hz, sample=78, buffer_id=03:4E
    db 0,0,100,0,73,127,4,9,42,2,73,4  ; n1569 t=92.330s dur=100ms, freq=554Hz, sample=73, buffer_id=04:49
    db 0,0,100,0,78,127,4,10,186,2,78,4  ; n1570 t=92.330s dur=100ms, freq=698Hz, sample=78, buffer_id=04:4E
    db 0,0,100,0,54,127,5,11,175,0,54,5  ; n1571 t=92.330s dur=100ms, freq=175Hz, sample=54, buffer_id=05:36
    db 0,0,100,0,49,127,6,15,139,0,49,5  ; n1572 t=92.330s dur=100ms, freq=139Hz, sample=49, buffer_id=05:31
    db 0,0,100,0,54,127,7,16,185,0,54,7  ; n1573 t=92.330s dur=100ms, freq=185Hz, sample=54, buffer_id=07:36
    db 0,0,100,0,66,127,7,18,114,1,66,7  ; n1574 t=92.330s dur=100ms, freq=370Hz, sample=66, buffer_id=07:42
    db 0,0,100,0,61,127,8,17,21,1,61,7  ; n1575 t=92.330s dur=100ms, freq=277Hz, sample=61, buffer_id=07:3D
    db 0,0,100,0,66,127,8,19,93,1,66,7  ; n1576 t=92.330s dur=100ms, freq=349Hz, sample=66, buffer_id=07:42
    db 0,0,100,0,78,127,16,20,228,2,78,16  ; n1577 t=92.330s dur=100ms, freq=740Hz, sample=78, buffer_id=10:4E
    db 0,0,100,0,66,127,17,21,114,1,66,16  ; n1578 t=92.330s dur=100ms, freq=370Hz, sample=66, buffer_id=10:42
    db 75,0,97,1,47,127,20,22,123,0,47,20  ; n1579 t=92.330s dur=353ms, freq=123Hz, sample=47, buffer_id=14:2F
    db 0,0,100,0,78,127,16,4,16,3,78,16  ; n1580 t=92.406s dur=100ms, freq=784Hz, sample=78, buffer_id=10:4E
    db 76,0,100,0,66,127,17,7,136,1,66,16  ; n1581 t=92.406s dur=100ms, freq=392Hz, sample=66, buffer_id=10:42
    db 0,0,100,0,78,127,16,0,228,2,78,16  ; n1582 t=92.481s dur=100ms, freq=740Hz, sample=78, buffer_id=10:4E
    db 75,0,100,0,66,127,17,3,114,1,66,16  ; n1583 t=92.481s dur=100ms, freq=370Hz, sample=66, buffer_id=10:42
    db 0,0,100,0,78,127,16,1,186,2,78,16  ; n1584 t=92.557s dur=100ms, freq=698Hz, sample=78, buffer_id=10:4E
    db 75,0,100,0,65,127,17,2,93,1,65,16  ; n1585 t=92.557s dur=100ms, freq=349Hz, sample=65, buffer_id=10:41
    db 0,0,100,0,78,127,16,5,228,2,78,16  ; n1586 t=92.632s dur=100ms, freq=740Hz, sample=78, buffer_id=10:4E
    db 75,0,100,0,66,127,17,6,114,1,66,16  ; n1587 t=92.632s dur=100ms, freq=370Hz, sample=66, buffer_id=10:42
    db 0,0,100,0,62,127,3,4,74,1,62,3  ; n1588 t=92.707s dur=100ms, freq=330Hz, sample=62, buffer_id=03:3E
    db 0,0,100,0,74,127,3,7,147,2,74,3  ; n1589 t=92.707s dur=100ms, freq=659Hz, sample=74, buffer_id=03:4A
    db 0,0,100,0,42,127,5,8,92,0,42,5  ; n1590 t=92.707s dur=100ms, freq=92Hz, sample=42, buffer_id=05:2A
    db 0,0,100,0,35,127,6,9,62,0,35,5  ; n1591 t=92.707s dur=100ms, freq=62Hz, sample=35, buffer_id=05:23
    db 0,0,100,0,54,127,18,10,185,0,54,18  ; n1592 t=92.707s dur=100ms, freq=185Hz, sample=54, buffer_id=12:36
    db 0,0,100,0,42,127,19,11,92,0,42,19  ; n1593 t=92.707s dur=100ms, freq=92Hz, sample=42, buffer_id=13:2A
    db 75,0,96,1,35,127,20,13,62,0,35,20  ; n1594 t=92.707s dur=352ms, freq=62Hz, sample=35, buffer_id=14:23
    db 0,0,100,0,54,127,18,0,196,0,54,18  ; n1595 t=92.782s dur=100ms, freq=196Hz, sample=54, buffer_id=12:36
    db 75,0,100,0,42,127,19,3,98,0,42,19  ; n1596 t=92.782s dur=100ms, freq=98Hz, sample=42, buffer_id=13:2A
    db 0,0,100,0,54,127,18,1,185,0,54,18  ; n1597 t=92.858s dur=100ms, freq=185Hz, sample=54, buffer_id=12:36
    db 38,0,100,0,42,127,19,2,92,0,42,19  ; n1598 t=92.858s dur=100ms, freq=92Hz, sample=42, buffer_id=13:2A
    db 0,0,100,0,59,127,3,12,6,1,59,3  ; n1599 t=92.895s dur=100ms, freq=262Hz, sample=59, buffer_id=03:3B
    db 38,0,100,0,71,127,3,14,11,2,71,3  ; n1600 t=92.895s dur=100ms, freq=523Hz, sample=71, buffer_id=03:47
    db 0,0,100,0,54,127,18,5,175,0,54,18  ; n1601 t=92.933s dur=100ms, freq=175Hz, sample=54, buffer_id=12:36
    db 75,0,100,0,41,127,19,6,87,0,41,19  ; n1602 t=92.933s dur=100ms, freq=87Hz, sample=41, buffer_id=13:29
    db 0,0,100,0,54,127,18,4,185,0,54,18  ; n1603 t=93.008s dur=100ms, freq=185Hz, sample=54, buffer_id=12:36
    db 75,0,100,0,42,127,19,7,92,0,42,19  ; n1604 t=93.008s dur=100ms, freq=92Hz, sample=42, buffer_id=13:2A
    db 0,0,100,0,78,127,2,0,228,2,78,2  ; n1605 t=93.083s dur=100ms, freq=740Hz, sample=78, buffer_id=02:4E
    db 0,0,100,0,62,127,3,3,74,1,62,3  ; n1606 t=93.083s dur=100ms, freq=330Hz, sample=62, buffer_id=03:3E
    db 0,0,100,0,74,127,3,8,147,2,74,3  ; n1607 t=93.083s dur=100ms, freq=659Hz, sample=74, buffer_id=03:4A
    db 0,0,100,0,73,127,4,9,11,2,73,4  ; n1608 t=93.083s dur=100ms, freq=523Hz, sample=73, buffer_id=04:49
    db 0,0,100,0,74,127,4,10,147,2,74,4  ; n1609 t=93.083s dur=100ms, freq=659Hz, sample=74, buffer_id=04:4A
    db 0,0,100,0,50,127,5,11,165,0,50,5  ; n1610 t=93.083s dur=100ms, freq=165Hz, sample=50, buffer_id=05:32
    db 0,0,100,0,47,127,6,15,131,0,47,5  ; n1611 t=93.083s dur=100ms, freq=131Hz, sample=47, buffer_id=05:2F
    db 0,0,100,0,54,127,7,17,185,0,54,7  ; n1612 t=93.083s dur=100ms, freq=185Hz, sample=54, buffer_id=07:36
    db 0,0,100,0,66,127,7,16,114,1,66,7  ; n1613 t=93.083s dur=100ms, freq=370Hz, sample=66, buffer_id=07:42
    db 0,0,100,0,59,127,8,18,6,1,59,7  ; n1614 t=93.083s dur=100ms, freq=262Hz, sample=59, buffer_id=07:3B
    db 0,0,100,0,62,127,8,19,74,1,62,7  ; n1615 t=93.083s dur=100ms, freq=330Hz, sample=62, buffer_id=07:3E
    db 0,0,100,0,78,127,16,21,228,2,78,16  ; n1616 t=93.083s dur=100ms, freq=740Hz, sample=78, buffer_id=10:4E
    db 0,0,100,0,66,127,17,20,114,1,66,16  ; n1617 t=93.083s dur=100ms, freq=370Hz, sample=66, buffer_id=10:42
    db 75,0,95,1,47,127,20,23,123,0,47,20  ; n1618 t=93.083s dur=351ms, freq=123Hz, sample=47, buffer_id=14:2F
    db 0,0,100,0,78,127,16,1,16,3,78,16  ; n1619 t=93.158s dur=100ms, freq=784Hz, sample=78, buffer_id=10:4E
    db 75,0,100,0,66,127,17,2,136,1,66,16  ; n1620 t=93.158s dur=100ms, freq=392Hz, sample=66, buffer_id=10:42
    db 0,0,100,0,78,127,16,5,228,2,78,16  ; n1621 t=93.233s dur=100ms, freq=740Hz, sample=78, buffer_id=10:4E
    db 75,0,100,0,66,127,17,6,114,1,66,16  ; n1622 t=93.233s dur=100ms, freq=370Hz, sample=66, buffer_id=10:42
    db 0,0,100,0,78,127,16,12,186,2,78,16  ; n1623 t=93.308s dur=100ms, freq=698Hz, sample=78, buffer_id=10:4E
    db 75,0,100,0,65,127,17,13,93,1,65,16  ; n1624 t=93.308s dur=100ms, freq=349Hz, sample=65, buffer_id=10:41
    db 0,0,100,0,78,127,16,4,228,2,78,16  ; n1625 t=93.383s dur=100ms, freq=740Hz, sample=78, buffer_id=10:4E
    db 73,0,100,0,66,127,17,7,114,1,66,16  ; n1626 t=93.383s dur=100ms, freq=370Hz, sample=66, buffer_id=10:42
    db 2,0,93,1,47,127,10,0,123,0,47,10  ; n1627 t=93.455s dur=349ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 0,0,100,0,59,127,3,3,247,0,59,3  ; n1628 t=93.458s dur=100ms, freq=247Hz, sample=59, buffer_id=03:3B
    db 0,0,100,0,71,127,3,8,238,1,71,3  ; n1629 t=93.458s dur=100ms, freq=494Hz, sample=71, buffer_id=03:47
    db 0,0,100,0,42,127,5,9,92,0,42,5  ; n1630 t=93.458s dur=100ms, freq=92Hz, sample=42, buffer_id=05:2A
    db 0,0,100,0,35,127,6,10,62,0,35,5  ; n1631 t=93.458s dur=100ms, freq=62Hz, sample=35, buffer_id=05:23
    db 0,0,100,0,54,127,18,11,185,0,54,18  ; n1632 t=93.458s dur=100ms, freq=185Hz, sample=54, buffer_id=12:36
    db 0,0,100,0,42,127,19,14,92,0,42,19  ; n1633 t=93.458s dur=100ms, freq=92Hz, sample=42, buffer_id=13:2A
    db 75,0,93,1,35,127,20,15,62,0,35,20  ; n1634 t=93.458s dur=349ms, freq=62Hz, sample=35, buffer_id=14:23
    db 0,0,100,0,54,127,18,1,196,0,54,18  ; n1635 t=93.532s dur=100ms, freq=196Hz, sample=54, buffer_id=12:36
    db 75,0,100,0,42,127,19,2,98,0,42,19  ; n1636 t=93.532s dur=100ms, freq=98Hz, sample=42, buffer_id=13:2A
    db 0,0,100,0,54,127,18,5,185,0,54,18  ; n1637 t=93.607s dur=100ms, freq=185Hz, sample=54, buffer_id=12:36
    db 37,0,100,0,42,127,19,6,92,0,42,19  ; n1638 t=93.607s dur=100ms, freq=92Hz, sample=42, buffer_id=13:2A
    db 0,0,100,0,62,127,3,12,21,1,62,3  ; n1639 t=93.644s dur=100ms, freq=277Hz, sample=62, buffer_id=03:3E
    db 37,0,100,0,73,127,3,13,42,2,73,3  ; n1640 t=93.644s dur=100ms, freq=554Hz, sample=73, buffer_id=03:49
    db 0,0,100,0,54,127,18,16,175,0,54,18  ; n1641 t=93.682s dur=100ms, freq=175Hz, sample=54, buffer_id=12:36
    db 75,0,100,0,41,127,19,17,87,0,41,19  ; n1642 t=93.682s dur=100ms, freq=87Hz, sample=41, buffer_id=13:29
    db 0,0,100,0,54,127,18,4,185,0,54,18  ; n1643 t=93.756s dur=100ms, freq=185Hz, sample=54, buffer_id=12:36
    db 72,0,100,0,42,127,19,7,92,0,42,19  ; n1644 t=93.756s dur=100ms, freq=92Hz, sample=42, buffer_id=13:2A
    db 2,0,92,1,47,127,10,3,123,0,47,10  ; n1645 t=93.829s dur=348ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 0,0,100,0,78,127,2,8,228,2,78,2  ; n1646 t=93.831s dur=100ms, freq=740Hz, sample=78, buffer_id=02:4E
    db 0,0,100,0,62,127,3,9,38,1,62,3  ; n1647 t=93.831s dur=100ms, freq=294Hz, sample=62, buffer_id=03:3E
    db 0,0,100,0,74,127,3,10,75,2,74,3  ; n1648 t=93.831s dur=100ms, freq=587Hz, sample=74, buffer_id=03:4A
    db 0,0,100,0,70,127,4,11,238,1,70,4  ; n1649 t=93.831s dur=100ms, freq=494Hz, sample=70, buffer_id=04:46
    db 0,0,100,0,74,127,4,14,75,2,74,4  ; n1650 t=93.831s dur=100ms, freq=587Hz, sample=74, buffer_id=04:4A
    db 0,0,100,0,50,127,5,18,147,0,50,5  ; n1651 t=93.831s dur=100ms, freq=147Hz, sample=50, buffer_id=05:32
    db 0,0,100,0,47,127,6,19,123,0,47,5  ; n1652 t=93.831s dur=100ms, freq=123Hz, sample=47, buffer_id=05:2F
    db 0,0,100,0,54,127,7,20,185,0,54,7  ; n1653 t=93.831s dur=100ms, freq=185Hz, sample=54, buffer_id=07:36
    db 0,0,100,0,66,127,7,21,114,1,66,7  ; n1654 t=93.831s dur=100ms, freq=370Hz, sample=66, buffer_id=07:42
    db 0,0,100,0,59,127,8,22,247,0,59,7  ; n1655 t=93.831s dur=100ms, freq=247Hz, sample=59, buffer_id=07:3B
    db 0,0,100,0,62,127,8,23,38,1,62,7  ; n1656 t=93.831s dur=100ms, freq=294Hz, sample=62, buffer_id=07:3E
    db 0,0,100,0,59,127,12,24,247,0,59,11  ; n1657 t=93.831s dur=100ms, freq=247Hz, sample=59, buffer_id=0B:3B
    db 0,0,100,0,47,127,13,25,123,0,47,13  ; n1658 t=93.831s dur=100ms, freq=123Hz, sample=47, buffer_id=0D:2F
    db 0,0,100,0,78,127,16,26,228,2,78,16  ; n1659 t=93.831s dur=100ms, freq=740Hz, sample=78, buffer_id=10:4E
    db 0,0,100,0,66,127,17,27,114,1,66,16  ; n1660 t=93.831s dur=100ms, freq=370Hz, sample=66, buffer_id=10:42
    db 0,0,100,0,54,127,18,28,185,0,54,18  ; n1661 t=93.831s dur=100ms, freq=185Hz, sample=54, buffer_id=12:36
    db 0,0,100,0,59,127,19,29,247,0,59,19  ; n1662 t=93.831s dur=100ms, freq=247Hz, sample=59, buffer_id=13:3B
    db 75,0,100,0,47,127,20,30,123,0,47,20  ; n1663 t=93.831s dur=100ms, freq=123Hz, sample=47, buffer_id=14:2F
    db 0,0,100,0,78,127,16,1,16,3,78,16  ; n1664 t=93.905s dur=100ms, freq=784Hz, sample=78, buffer_id=10:4E
    db 0,0,100,0,66,127,17,2,136,1,66,16  ; n1665 t=93.905s dur=100ms, freq=392Hz, sample=66, buffer_id=10:42
    db 74,0,100,0,54,127,18,31,196,0,54,18  ; n1666 t=93.905s dur=100ms, freq=196Hz, sample=54, buffer_id=12:36
    db 0,0,100,0,78,127,16,5,228,2,78,16  ; n1667 t=93.980s dur=100ms, freq=740Hz, sample=78, buffer_id=10:4E
    db 0,0,100,0,66,127,17,6,114,1,66,16  ; n1668 t=93.980s dur=100ms, freq=370Hz, sample=66, buffer_id=10:42
    db 37,0,100,0,54,127,18,12,185,0,54,18  ; n1669 t=93.980s dur=100ms, freq=185Hz, sample=54, buffer_id=12:36
    db 0,0,100,0,62,127,3,0,74,1,62,3  ; n1670 t=94.017s dur=100ms, freq=330Hz, sample=62, buffer_id=03:3E
    db 37,0,100,0,74,127,3,13,147,2,74,3  ; n1671 t=94.017s dur=100ms, freq=659Hz, sample=74, buffer_id=03:4A
    db 0,0,100,0,78,127,16,15,186,2,78,16  ; n1672 t=94.054s dur=100ms, freq=698Hz, sample=78, buffer_id=10:4E
    db 0,0,100,0,65,127,17,16,93,1,65,16  ; n1673 t=94.054s dur=100ms, freq=349Hz, sample=65, buffer_id=10:41
    db 74,0,100,0,54,127,18,17,175,0,54,18  ; n1674 t=94.054s dur=100ms, freq=175Hz, sample=54, buffer_id=12:36
    db 0,0,100,0,78,127,16,4,228,2,78,16  ; n1675 t=94.128s dur=100ms, freq=740Hz, sample=78, buffer_id=10:4E
    db 0,0,100,0,66,127,17,7,114,1,66,16  ; n1676 t=94.128s dur=100ms, freq=370Hz, sample=66, buffer_id=10:42
    db 72,0,100,0,54,127,18,28,185,0,54,18  ; n1677 t=94.128s dur=100ms, freq=185Hz, sample=54, buffer_id=12:36 [TRUNCATE prev:ch28 @93830.8ms -> 94128.4ms]
    db 2,0,91,1,47,127,10,8,123,0,47,10  ; n1678 t=94.200s dur=347ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 0,0,100,0,66,127,3,9,114,1,66,3  ; n1679 t=94.203s dur=100ms, freq=370Hz, sample=66, buffer_id=03:42
    db 0,0,100,0,78,127,3,10,228,2,78,3  ; n1680 t=94.203s dur=100ms, freq=740Hz, sample=78, buffer_id=03:4E
    db 0,0,100,0,58,127,12,11,220,0,58,11  ; n1681 t=94.203s dur=100ms, freq=220Hz, sample=58, buffer_id=0B:3A
    db 0,0,100,0,43,127,13,14,110,0,43,13  ; n1682 t=94.203s dur=100ms, freq=110Hz, sample=43, buffer_id=0D:2B
    db 0,0,100,0,78,127,16,18,228,2,78,16  ; n1683 t=94.203s dur=100ms, freq=740Hz, sample=78, buffer_id=10:4E
    db 0,0,100,0,66,127,17,19,114,1,66,16  ; n1684 t=94.203s dur=100ms, freq=370Hz, sample=66, buffer_id=10:42
    db 0,0,100,0,54,127,18,20,185,0,54,18  ; n1685 t=94.203s dur=100ms, freq=185Hz, sample=54, buffer_id=12:36
    db 0,0,100,0,59,127,19,21,220,0,59,19  ; n1686 t=94.203s dur=100ms, freq=220Hz, sample=59, buffer_id=13:3B
    db 74,0,100,0,47,127,20,22,110,0,47,20  ; n1687 t=94.203s dur=100ms, freq=110Hz, sample=47, buffer_id=14:2F
    db 0,0,100,0,78,127,16,2,16,3,78,16  ; n1688 t=94.277s dur=100ms, freq=784Hz, sample=78, buffer_id=10:4E
    db 0,0,100,0,66,127,17,1,136,1,66,16  ; n1689 t=94.277s dur=100ms, freq=392Hz, sample=66, buffer_id=10:42
    db 74,0,100,0,54,127,18,23,196,0,54,18  ; n1690 t=94.277s dur=100ms, freq=196Hz, sample=54, buffer_id=12:36
    db 0,0,100,0,78,127,16,0,228,2,78,16  ; n1691 t=94.351s dur=100ms, freq=740Hz, sample=78, buffer_id=10:4E
    db 0,0,100,0,66,127,17,5,114,1,66,16  ; n1692 t=94.351s dur=100ms, freq=370Hz, sample=66, buffer_id=10:42
    db 37,0,100,0,54,127,18,6,185,0,54,18  ; n1693 t=94.351s dur=100ms, freq=185Hz, sample=54, buffer_id=12:36
    db 0,0,100,0,62,127,3,3,38,1,62,3  ; n1694 t=94.388s dur=100ms, freq=294Hz, sample=62, buffer_id=03:3E
    db 37,0,100,0,74,127,3,12,75,2,74,3  ; n1695 t=94.388s dur=100ms, freq=587Hz, sample=74, buffer_id=03:4A
    db 0,0,100,0,78,127,16,13,186,2,78,16  ; n1696 t=94.425s dur=100ms, freq=698Hz, sample=78, buffer_id=10:4E
    db 0,0,100,0,65,127,17,15,93,1,65,16  ; n1697 t=94.425s dur=100ms, freq=349Hz, sample=65, buffer_id=10:41
    db 74,0,100,0,54,127,18,16,175,0,54,18  ; n1698 t=94.425s dur=100ms, freq=175Hz, sample=54, buffer_id=12:36
    db 0,0,100,0,78,127,16,7,228,2,78,16  ; n1699 t=94.499s dur=100ms, freq=740Hz, sample=78, buffer_id=10:4E
    db 0,0,100,0,66,127,17,4,114,1,66,16  ; n1700 t=94.499s dur=100ms, freq=370Hz, sample=66, buffer_id=10:42
    db 72,0,100,0,54,127,18,24,185,0,54,18  ; n1701 t=94.499s dur=100ms, freq=185Hz, sample=54, buffer_id=12:36
    db 2,0,90,1,47,127,10,9,123,0,47,10  ; n1702 t=94.571s dur=346ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 0,0,100,0,78,127,2,10,228,2,78,2  ; n1703 t=94.573s dur=100ms, freq=740Hz, sample=78, buffer_id=02:4E
    db 0,0,100,0,66,127,3,11,114,1,66,3  ; n1704 t=94.573s dur=100ms, freq=370Hz, sample=66, buffer_id=03:42
    db 0,0,100,0,78,127,3,14,228,2,78,3  ; n1705 t=94.573s dur=100ms, freq=740Hz, sample=78, buffer_id=03:4E
    db 0,0,100,0,70,127,4,17,238,1,70,4  ; n1706 t=94.573s dur=100ms, freq=494Hz, sample=70, buffer_id=04:46
    db 0,0,100,0,74,127,4,18,75,2,74,4  ; n1707 t=94.573s dur=100ms, freq=587Hz, sample=74, buffer_id=04:4A
    db 0,0,100,0,50,127,5,19,147,0,50,5  ; n1708 t=94.573s dur=100ms, freq=147Hz, sample=50, buffer_id=05:32
    db 0,0,100,0,47,127,6,20,123,0,47,5  ; n1709 t=94.573s dur=100ms, freq=123Hz, sample=47, buffer_id=05:2F
    db 0,0,100,0,54,127,7,21,185,0,54,7  ; n1710 t=94.573s dur=100ms, freq=185Hz, sample=54, buffer_id=07:36
    db 0,0,100,0,66,127,7,22,114,1,66,7  ; n1711 t=94.573s dur=100ms, freq=370Hz, sample=66, buffer_id=07:42
    db 0,0,100,0,59,127,8,25,247,0,59,7  ; n1712 t=94.573s dur=100ms, freq=247Hz, sample=59, buffer_id=07:3B
    db 0,0,100,0,62,127,8,26,38,1,62,7  ; n1713 t=94.573s dur=100ms, freq=294Hz, sample=62, buffer_id=07:3E
    db 0,0,100,0,54,127,12,27,196,0,54,11  ; n1714 t=94.573s dur=100ms, freq=196Hz, sample=54, buffer_id=0B:36
    db 0,0,100,0,43,127,13,28,98,0,43,13  ; n1715 t=94.573s dur=100ms, freq=98Hz, sample=43, buffer_id=0D:2B
    db 0,0,100,0,78,127,16,29,228,2,78,16  ; n1716 t=94.573s dur=100ms, freq=740Hz, sample=78, buffer_id=10:4E
    db 0,0,100,0,66,127,17,30,114,1,66,16  ; n1717 t=94.573s dur=100ms, freq=370Hz, sample=66, buffer_id=10:42
    db 0,0,100,0,54,127,18,31,185,0,54,18  ; n1718 t=94.573s dur=100ms, freq=185Hz, sample=54, buffer_id=12:36 [TRUNCATE prev:ch31 @93905.3ms -> 94573.5ms]
    db 0,0,100,0,54,127,19,8,196,0,54,19  ; n1719 t=94.573s dur=100ms, freq=196Hz, sample=54, buffer_id=13:36 [TRUNCATE prev:ch8 @94200.4ms -> 94573.5ms]
    db 74,0,100,0,42,127,20,1,98,0,42,20  ; n1720 t=94.573s dur=100ms, freq=98Hz, sample=42, buffer_id=14:2A [TRUNCATE prev:ch1 @94277.0ms -> 94573.5ms]
    db 0,0,100,0,78,127,16,23,16,3,78,16  ; n1721 t=94.647s dur=100ms, freq=784Hz, sample=78, buffer_id=10:4E
    db 0,0,100,0,66,127,17,2,136,1,66,16  ; n1722 t=94.647s dur=100ms, freq=392Hz, sample=66, buffer_id=10:42
    db 74,0,100,0,54,127,18,6,196,0,54,18  ; n1723 t=94.647s dur=100ms, freq=196Hz, sample=54, buffer_id=12:36 [TRUNCATE prev:ch6 @94351.2ms -> 94647.4ms]
    db 0,0,100,0,78,127,16,3,228,2,78,16  ; n1724 t=94.721s dur=100ms, freq=740Hz, sample=78, buffer_id=10:4E
    db 0,0,100,0,66,127,17,0,114,1,66,16  ; n1725 t=94.721s dur=100ms, freq=370Hz, sample=66, buffer_id=10:42
    db 37,0,100,0,54,127,18,5,185,0,54,18  ; n1726 t=94.721s dur=100ms, freq=185Hz, sample=54, buffer_id=12:36
    db 0,0,100,0,71,127,3,12,238,1,71,3  ; n1727 t=94.758s dur=100ms, freq=494Hz, sample=71, buffer_id=03:47
    db 37,0,100,0,85,127,3,13,220,3,85,3  ; n1728 t=94.758s dur=100ms, freq=988Hz, sample=85, buffer_id=03:55
    db 0,0,100,0,78,127,16,15,186,2,78,16  ; n1729 t=94.795s dur=100ms, freq=698Hz, sample=78, buffer_id=10:4E
    db 0,0,100,0,65,127,17,16,93,1,65,16  ; n1730 t=94.795s dur=100ms, freq=349Hz, sample=65, buffer_id=10:41
    db 74,0,100,0,54,127,18,24,175,0,54,18  ; n1731 t=94.795s dur=100ms, freq=175Hz, sample=54, buffer_id=12:36 [TRUNCATE prev:ch24 @94499.4ms -> 94795.3ms]
    db 0,0,100,0,78,127,16,4,228,2,78,16  ; n1732 t=94.869s dur=100ms, freq=740Hz, sample=78, buffer_id=10:4E
    db 0,0,100,0,66,127,17,7,114,1,66,16  ; n1733 t=94.869s dur=100ms, freq=370Hz, sample=66, buffer_id=10:42
    db 72,0,100,0,54,127,18,31,185,0,54,18  ; n1734 t=94.869s dur=100ms, freq=185Hz, sample=54, buffer_id=12:36 [TRUNCATE prev:ch31 @94573.5ms -> 94869.1ms]
    db 2,0,89,1,47,127,10,1,123,0,47,10  ; n1735 t=94.941s dur=345ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 0,0,100,0,66,127,3,8,114,1,66,3  ; n1736 t=94.943s dur=100ms, freq=370Hz, sample=66, buffer_id=03:42
    db 0,0,100,0,78,127,3,10,228,2,78,3  ; n1737 t=94.943s dur=100ms, freq=740Hz, sample=78, buffer_id=03:4E
    db 0,0,100,0,54,127,12,11,185,0,54,11  ; n1738 t=94.943s dur=100ms, freq=185Hz, sample=54, buffer_id=0B:36
    db 0,0,100,0,42,127,13,14,92,0,42,13  ; n1739 t=94.943s dur=100ms, freq=92Hz, sample=42, buffer_id=0D:2A
    db 0,0,100,0,78,127,16,17,228,2,78,16  ; n1740 t=94.943s dur=100ms, freq=740Hz, sample=78, buffer_id=10:4E
    db 0,0,100,0,66,127,17,18,114,1,66,16  ; n1741 t=94.943s dur=100ms, freq=370Hz, sample=66, buffer_id=10:42
    db 0,0,100,0,54,127,18,19,185,0,54,18  ; n1742 t=94.943s dur=100ms, freq=185Hz, sample=54, buffer_id=12:36
    db 0,0,100,0,54,127,19,20,185,0,54,19  ; n1743 t=94.943s dur=100ms, freq=185Hz, sample=54, buffer_id=13:36
    db 74,0,100,0,42,127,20,21,92,0,42,20  ; n1744 t=94.943s dur=100ms, freq=92Hz, sample=42, buffer_id=14:2A
    db 0,0,100,0,78,127,16,2,16,3,78,16  ; n1745 t=95.017s dur=100ms, freq=784Hz, sample=78, buffer_id=10:4E
    db 0,0,100,0,66,127,17,6,136,1,66,16  ; n1746 t=95.017s dur=100ms, freq=392Hz, sample=66, buffer_id=10:42
    db 74,0,100,0,54,127,18,22,196,0,54,18  ; n1747 t=95.017s dur=100ms, freq=196Hz, sample=54, buffer_id=12:36
    db 0,0,100,0,78,127,16,0,228,2,78,16  ; n1748 t=95.090s dur=100ms, freq=740Hz, sample=78, buffer_id=10:4E
    db 0,0,100,0,66,127,17,3,114,1,66,16  ; n1749 t=95.090s dur=100ms, freq=370Hz, sample=66, buffer_id=10:42
    db 37,0,100,0,54,127,18,12,185,0,54,18  ; n1750 t=95.090s dur=100ms, freq=185Hz, sample=54, buffer_id=12:36
    db 0,0,100,0,62,127,3,5,38,1,62,3  ; n1751 t=95.127s dur=100ms, freq=294Hz, sample=62, buffer_id=03:3E
    db 37,0,100,0,74,127,3,9,75,2,74,3  ; n1752 t=95.127s dur=100ms, freq=587Hz, sample=74, buffer_id=03:4A
    db 0,0,100,0,78,127,16,13,186,2,78,16  ; n1753 t=95.164s dur=100ms, freq=698Hz, sample=78, buffer_id=10:4E
    db 0,0,100,0,65,127,17,15,93,1,65,16  ; n1754 t=95.164s dur=100ms, freq=349Hz, sample=65, buffer_id=10:41
    db 73,0,100,0,54,127,18,16,175,0,54,18  ; n1755 t=95.164s dur=100ms, freq=175Hz, sample=54, buffer_id=12:36
    db 0,0,100,0,78,127,16,7,228,2,78,16  ; n1756 t=95.237s dur=100ms, freq=740Hz, sample=78, buffer_id=10:4E
    db 0,0,100,0,66,127,17,4,114,1,66,16  ; n1757 t=95.237s dur=100ms, freq=370Hz, sample=66, buffer_id=10:42
    db 71,0,100,0,54,127,18,23,185,0,54,18  ; n1758 t=95.237s dur=100ms, freq=185Hz, sample=54, buffer_id=12:36
    db 2,0,88,1,47,127,10,8,123,0,47,10  ; n1759 t=95.309s dur=344ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 0,0,100,0,78,127,2,10,228,2,78,2  ; n1760 t=95.311s dur=100ms, freq=740Hz, sample=78, buffer_id=02:4E
    db 0,0,100,0,66,127,3,11,114,1,66,3  ; n1761 t=95.311s dur=100ms, freq=370Hz, sample=66, buffer_id=03:42
    db 0,0,100,0,78,127,3,14,228,2,78,3  ; n1762 t=95.311s dur=100ms, freq=740Hz, sample=78, buffer_id=03:4E
    db 0,0,100,0,70,127,4,17,238,1,70,4  ; n1763 t=95.311s dur=100ms, freq=494Hz, sample=70, buffer_id=04:46
    db 0,0,100,0,74,127,4,18,75,2,74,4  ; n1764 t=95.311s dur=100ms, freq=587Hz, sample=74, buffer_id=04:4A
    db 0,0,100,0,50,127,5,19,147,0,50,5  ; n1765 t=95.311s dur=100ms, freq=147Hz, sample=50, buffer_id=05:32
    db 0,0,100,0,47,127,6,20,123,0,47,5  ; n1766 t=95.311s dur=100ms, freq=123Hz, sample=47, buffer_id=05:2F
    db 0,0,100,0,54,127,7,21,185,0,54,7  ; n1767 t=95.311s dur=100ms, freq=185Hz, sample=54, buffer_id=07:36
    db 0,0,100,0,66,127,7,24,114,1,66,7  ; n1768 t=95.311s dur=100ms, freq=370Hz, sample=66, buffer_id=07:42
    db 0,0,100,0,59,127,8,26,247,0,59,7  ; n1769 t=95.311s dur=100ms, freq=247Hz, sample=59, buffer_id=07:3B
    db 0,0,100,0,62,127,8,25,38,1,62,7  ; n1770 t=95.311s dur=100ms, freq=294Hz, sample=62, buffer_id=07:3E
    db 0,0,100,0,53,127,12,27,165,0,53,11  ; n1771 t=95.311s dur=100ms, freq=165Hz, sample=53, buffer_id=0B:35
    db 0,0,100,0,42,127,13,28,82,0,42,13  ; n1772 t=95.311s dur=100ms, freq=82Hz, sample=42, buffer_id=0D:2A
    db 0,0,100,0,78,127,16,30,228,2,78,16  ; n1773 t=95.311s dur=100ms, freq=740Hz, sample=78, buffer_id=10:4E
    db 0,0,100,0,66,127,17,29,114,1,66,16  ; n1774 t=95.311s dur=100ms, freq=370Hz, sample=66, buffer_id=10:42
    db 0,0,100,0,54,127,18,31,185,0,54,18  ; n1775 t=95.311s dur=100ms, freq=185Hz, sample=54, buffer_id=12:36 [TRUNCATE prev:ch31 @94869.1ms -> 95311.1ms]
    db 0,0,100,0,54,127,19,1,165,0,54,19  ; n1776 t=95.311s dur=100ms, freq=165Hz, sample=54, buffer_id=13:36 [TRUNCATE prev:ch1 @94940.6ms -> 95311.1ms]
    db 74,0,100,0,42,127,20,2,82,0,42,20  ; n1777 t=95.311s dur=100ms, freq=82Hz, sample=42, buffer_id=14:2A [TRUNCATE prev:ch2 @95016.6ms -> 95311.1ms]
    db 0,0,100,0,78,127,16,6,16,3,78,16  ; n1778 t=95.385s dur=100ms, freq=784Hz, sample=78, buffer_id=10:4E
    db 0,0,100,0,66,127,17,22,136,1,66,16  ; n1779 t=95.385s dur=100ms, freq=392Hz, sample=66, buffer_id=10:42
    db 73,0,100,0,54,127,18,12,196,0,54,18  ; n1780 t=95.385s dur=100ms, freq=196Hz, sample=54, buffer_id=12:36 [TRUNCATE prev:ch12 @95090.3ms -> 95384.6ms]
    db 0,0,100,0,78,127,16,3,228,2,78,16  ; n1781 t=95.458s dur=100ms, freq=740Hz, sample=78, buffer_id=10:4E
    db 0,0,100,0,66,127,17,0,114,1,66,16  ; n1782 t=95.458s dur=100ms, freq=370Hz, sample=66, buffer_id=10:42
    db 37,0,100,0,54,127,18,5,185,0,54,18  ; n1783 t=95.458s dur=100ms, freq=185Hz, sample=54, buffer_id=12:36
    db 0,0,100,0,71,127,3,9,238,1,71,3  ; n1784 t=95.495s dur=100ms, freq=494Hz, sample=71, buffer_id=03:47
    db 37,0,100,0,85,127,3,13,220,3,85,3  ; n1785 t=95.495s dur=100ms, freq=988Hz, sample=85, buffer_id=03:55
    db 0,0,100,0,78,127,16,15,186,2,78,16  ; n1786 t=95.531s dur=100ms, freq=698Hz, sample=78, buffer_id=10:4E
    db 0,0,100,0,65,127,17,16,93,1,65,16  ; n1787 t=95.531s dur=100ms, freq=349Hz, sample=65, buffer_id=10:41
    db 73,0,100,0,54,127,18,23,175,0,54,18  ; n1788 t=95.531s dur=100ms, freq=175Hz, sample=54, buffer_id=12:36 [TRUNCATE prev:ch23 @95237.5ms -> 95531.4ms]
    db 0,0,100,0,78,127,16,4,228,2,78,16  ; n1789 t=95.605s dur=100ms, freq=740Hz, sample=78, buffer_id=10:4E
    db 0,0,100,0,66,127,17,7,114,1,66,16  ; n1790 t=95.605s dur=100ms, freq=370Hz, sample=66, buffer_id=10:42
    db 71,0,100,0,54,127,18,31,185,0,54,18  ; n1791 t=95.605s dur=100ms, freq=185Hz, sample=54, buffer_id=12:36 [TRUNCATE prev:ch31 @95311.1ms -> 95604.8ms]
    db 2,0,86,1,47,127,10,1,123,0,47,10  ; n1792 t=95.676s dur=342ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 0,0,195,2,59,127,3,2,247,0,59,3  ; n1793 t=95.678s dur=707ms, freq=247Hz, sample=59, buffer_id=03:3B
    db 0,0,195,2,71,127,3,10,238,1,71,3  ; n1794 t=95.678s dur=707ms, freq=494Hz, sample=71, buffer_id=03:47
    db 0,0,100,0,50,127,12,11,147,0,50,11  ; n1795 t=95.678s dur=100ms, freq=147Hz, sample=50, buffer_id=0B:32
    db 0,0,100,0,35,127,13,14,73,0,35,13  ; n1796 t=95.678s dur=100ms, freq=73Hz, sample=35, buffer_id=0D:23
    db 0,0,100,0,78,127,16,17,228,2,78,16  ; n1797 t=95.678s dur=100ms, freq=740Hz, sample=78, buffer_id=10:4E
    db 0,0,100,0,66,127,17,18,114,1,66,16  ; n1798 t=95.678s dur=100ms, freq=370Hz, sample=66, buffer_id=10:42
    db 0,0,100,0,54,127,18,19,185,0,54,18  ; n1799 t=95.678s dur=100ms, freq=185Hz, sample=54, buffer_id=12:36
    db 0,0,100,0,47,127,19,20,147,0,47,19  ; n1800 t=95.678s dur=100ms, freq=147Hz, sample=47, buffer_id=13:2F
    db 73,0,100,0,35,127,20,21,73,0,35,20  ; n1801 t=95.678s dur=100ms, freq=73Hz, sample=35, buffer_id=14:23
    db 0,0,100,0,78,127,16,12,16,3,78,16  ; n1802 t=95.751s dur=100ms, freq=784Hz, sample=78, buffer_id=10:4E
    db 0,0,100,0,66,127,17,6,136,1,66,16  ; n1803 t=95.751s dur=100ms, freq=392Hz, sample=66, buffer_id=10:42
    db 73,0,100,0,54,127,18,22,196,0,54,18  ; n1804 t=95.751s dur=100ms, freq=196Hz, sample=54, buffer_id=12:36
    db 0,0,100,0,78,127,16,0,228,2,78,16  ; n1805 t=95.825s dur=100ms, freq=740Hz, sample=78, buffer_id=10:4E
    db 0,0,100,0,66,127,17,3,114,1,66,16  ; n1806 t=95.825s dur=100ms, freq=370Hz, sample=66, buffer_id=10:42
    db 73,0,100,0,54,127,18,9,185,0,54,18  ; n1807 t=95.825s dur=100ms, freq=185Hz, sample=54, buffer_id=12:36
    db 0,0,100,0,78,127,16,5,186,2,78,16  ; n1808 t=95.898s dur=100ms, freq=698Hz, sample=78, buffer_id=10:4E
    db 0,0,100,0,65,127,17,8,93,1,65,16  ; n1809 t=95.898s dur=100ms, freq=349Hz, sample=65, buffer_id=10:41
    db 73,0,100,0,54,127,18,13,175,0,54,18  ; n1810 t=95.898s dur=100ms, freq=175Hz, sample=54, buffer_id=12:36
    db 0,0,100,0,78,127,16,7,228,2,78,16  ; n1811 t=95.971s dur=100ms, freq=740Hz, sample=78, buffer_id=10:4E
    db 0,0,100,0,66,127,17,4,114,1,66,16  ; n1812 t=95.971s dur=100ms, freq=370Hz, sample=66, buffer_id=10:42
    db 71,0,100,0,54,127,18,15,185,0,54,18  ; n1813 t=95.971s dur=100ms, freq=185Hz, sample=54, buffer_id=12:36
    db 2,0,85,1,47,127,10,11,123,0,47,10  ; n1814 t=96.042s dur=341ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 0,0,100,0,78,127,2,14,228,2,78,2  ; n1815 t=96.044s dur=100ms, freq=740Hz, sample=78, buffer_id=02:4E
    db 0,0,100,0,70,127,4,16,238,1,70,4  ; n1816 t=96.044s dur=100ms, freq=494Hz, sample=70, buffer_id=04:46
    db 0,0,100,0,74,127,4,17,75,2,74,4  ; n1817 t=96.044s dur=100ms, freq=587Hz, sample=74, buffer_id=04:4A
    db 0,0,100,0,50,127,5,18,147,0,50,5  ; n1818 t=96.044s dur=100ms, freq=147Hz, sample=50, buffer_id=05:32
    db 0,0,100,0,47,127,6,19,123,0,47,5  ; n1819 t=96.044s dur=100ms, freq=123Hz, sample=47, buffer_id=05:2F
    db 0,0,100,0,54,127,7,20,185,0,54,7  ; n1820 t=96.044s dur=100ms, freq=185Hz, sample=54, buffer_id=07:36
    db 0,0,100,0,66,127,7,21,114,1,66,7  ; n1821 t=96.044s dur=100ms, freq=370Hz, sample=66, buffer_id=07:42
    db 0,0,100,0,59,127,8,23,247,0,59,7  ; n1822 t=96.044s dur=100ms, freq=247Hz, sample=59, buffer_id=07:3B
    db 0,0,100,0,62,127,8,24,38,1,62,7  ; n1823 t=96.044s dur=100ms, freq=294Hz, sample=62, buffer_id=07:3E
    db 0,0,100,0,49,127,12,25,139,0,49,11  ; n1824 t=96.044s dur=100ms, freq=139Hz, sample=49, buffer_id=0B:31
    db 0,0,100,0,35,127,13,26,69,0,35,13  ; n1825 t=96.044s dur=100ms, freq=69Hz, sample=35, buffer_id=0D:23
    db 0,0,100,0,78,127,16,27,228,2,78,16  ; n1826 t=96.044s dur=100ms, freq=740Hz, sample=78, buffer_id=10:4E
    db 0,0,100,0,66,127,17,28,114,1,66,16  ; n1827 t=96.044s dur=100ms, freq=370Hz, sample=66, buffer_id=10:42
    db 0,0,100,0,54,127,18,29,185,0,54,18  ; n1828 t=96.044s dur=100ms, freq=185Hz, sample=54, buffer_id=12:36
    db 0,0,100,0,47,127,19,30,139,0,47,19  ; n1829 t=96.044s dur=100ms, freq=139Hz, sample=47, buffer_id=13:2F
    db 73,0,100,0,35,127,20,31,69,0,35,20  ; n1830 t=96.044s dur=100ms, freq=69Hz, sample=35, buffer_id=14:23
    db 0,0,100,0,78,127,16,6,16,3,78,16  ; n1831 t=96.117s dur=100ms, freq=784Hz, sample=78, buffer_id=10:4E
    db 0,0,100,0,66,127,17,12,136,1,66,16  ; n1832 t=96.117s dur=100ms, freq=392Hz, sample=66, buffer_id=10:42
    db 73,0,100,0,54,127,18,22,196,0,54,18  ; n1833 t=96.117s dur=100ms, freq=196Hz, sample=54, buffer_id=12:36 [TRUNCATE prev:ch22 @95751.3ms -> 96116.8ms]
    db 0,0,100,0,78,127,16,3,228,2,78,16  ; n1834 t=96.190s dur=100ms, freq=740Hz, sample=78, buffer_id=10:4E
    db 0,0,100,0,66,127,17,0,114,1,66,16  ; n1835 t=96.190s dur=100ms, freq=370Hz, sample=66, buffer_id=10:42
    db 73,0,100,0,54,127,18,9,185,0,54,18  ; n1836 t=96.190s dur=100ms, freq=185Hz, sample=54, buffer_id=12:36 [TRUNCATE prev:ch9 @95824.5ms -> 96189.8ms]
    db 0,0,100,0,78,127,16,1,186,2,78,16  ; n1837 t=96.263s dur=100ms, freq=698Hz, sample=78, buffer_id=10:4E
    db 0,0,100,0,65,127,17,5,93,1,65,16  ; n1838 t=96.263s dur=100ms, freq=349Hz, sample=65, buffer_id=10:41
    db 73,0,100,0,54,127,18,8,175,0,54,18  ; n1839 t=96.263s dur=100ms, freq=175Hz, sample=54, buffer_id=12:36
    db 0,0,100,0,78,127,16,4,228,2,78,16  ; n1840 t=96.335s dur=100ms, freq=740Hz, sample=78, buffer_id=10:4E
    db 0,0,100,0,66,127,17,7,114,1,66,16  ; n1841 t=96.335s dur=100ms, freq=370Hz, sample=66, buffer_id=10:42
    db 70,0,100,0,54,127,18,13,185,0,54,18  ; n1842 t=96.335s dur=100ms, freq=185Hz, sample=54, buffer_id=12:36 [TRUNCATE prev:ch13 @95897.7ms -> 96335.4ms]
    db 2,0,100,0,47,127,10,14,123,0,47,10  ; n1843 t=96.406s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 0,0,192,2,59,127,7,15,247,0,59,7  ; n1844 t=96.408s dur=704ms, freq=247Hz, sample=59, buffer_id=07:3B
    db 0,0,192,2,71,127,7,16,238,1,71,7  ; n1845 t=96.408s dur=704ms, freq=494Hz, sample=71, buffer_id=07:47
    db 0,0,100,0,47,127,12,17,123,0,47,11  ; n1846 t=96.408s dur=100ms, freq=123Hz, sample=47, buffer_id=0B:2F
    db 0,0,100,0,35,127,13,18,62,0,35,13  ; n1847 t=96.408s dur=100ms, freq=62Hz, sample=35, buffer_id=0D:23
    db 0,0,159,0,85,127,16,19,220,3,85,16  ; n1848 t=96.408s dur=159ms, freq=988Hz, sample=85, buffer_id=10:55
    db 0,0,159,0,70,127,17,20,238,1,70,16  ; n1849 t=96.408s dur=159ms, freq=494Hz, sample=70, buffer_id=10:46
    db 0,0,157,0,54,127,18,21,247,0,54,18  ; n1850 t=96.408s dur=157ms, freq=247Hz, sample=54, buffer_id=12:36
    db 0,0,159,0,47,127,19,23,123,0,47,19  ; n1851 t=96.408s dur=159ms, freq=123Hz, sample=47, buffer_id=13:2F
    db 78,0,159,0,35,127,20,24,62,0,35,20  ; n1852 t=96.408s dur=159ms, freq=62Hz, sample=35, buffer_id=14:23
    db 80,0,100,0,47,127,10,6,123,0,47,10  ; n1853 t=96.486s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 24,0,100,0,47,127,10,0,123,0,47,10  ; n1854 t=96.566s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 0,0,159,0,85,127,16,1,85,4,85,16  ; n1855 t=96.590s dur=159ms, freq=1109Hz, sample=85, buffer_id=10:55
    db 0,0,159,0,73,127,17,2,42,2,73,16  ; n1856 t=96.590s dur=159ms, freq=554Hz, sample=73, buffer_id=10:49
    db 0,0,159,0,66,127,18,3,21,1,66,18  ; n1857 t=96.590s dur=159ms, freq=277Hz, sample=66, buffer_id=12:42
    db 0,0,159,0,47,127,19,5,110,0,47,19  ; n1858 t=96.590s dur=159ms, freq=110Hz, sample=47, buffer_id=13:2F
    db 55,0,159,0,33,127,20,8,55,0,33,20  ; n1859 t=96.590s dur=159ms, freq=55Hz, sample=33, buffer_id=14:21
    db 80,0,100,0,47,127,10,4,123,0,47,10  ; n1860 t=96.644s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 47,0,100,0,47,127,10,7,123,0,47,10  ; n1861 t=96.725s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 0,0,113,0,86,127,2,9,151,4,86,2  ; n1862 t=96.772s dur=113ms, freq=1175Hz, sample=86, buffer_id=02:56
    db 0,0,113,0,90,127,2,10,200,5,90,2  ; n1863 t=96.772s dur=113ms, freq=1480Hz, sample=90, buffer_id=02:5A
    db 0,0,113,0,74,127,3,11,75,2,74,3  ; n1864 t=96.772s dur=113ms, freq=587Hz, sample=74, buffer_id=03:4A
    db 0,0,113,0,78,127,3,12,228,2,78,3  ; n1865 t=96.772s dur=113ms, freq=740Hz, sample=78, buffer_id=03:4E
    db 0,0,113,0,74,127,4,13,75,2,74,4  ; n1866 t=96.772s dur=113ms, freq=587Hz, sample=74, buffer_id=04:4A
    db 0,0,113,0,78,127,4,14,228,2,78,4  ; n1867 t=96.772s dur=113ms, freq=740Hz, sample=78, buffer_id=04:4E
    db 0,0,113,0,66,127,5,17,114,1,66,5  ; n1868 t=96.772s dur=113ms, freq=370Hz, sample=66, buffer_id=05:42
    db 0,0,113,0,62,127,6,18,38,1,62,5  ; n1869 t=96.772s dur=113ms, freq=294Hz, sample=62, buffer_id=05:3E
    db 0,0,100,0,66,127,9,19,114,1,66,9  ; n1870 t=96.772s dur=100ms, freq=370Hz, sample=66, buffer_id=09:42
    db 0,0,100,0,78,127,9,20,228,2,78,9  ; n1871 t=96.772s dur=100ms, freq=740Hz, sample=78, buffer_id=09:4E
    db 0,0,100,0,62,127,11,21,38,1,62,11  ; n1872 t=96.772s dur=100ms, freq=294Hz, sample=62, buffer_id=0B:3E
    db 0,0,100,0,66,127,11,22,114,1,66,11  ; n1873 t=96.772s dur=100ms, freq=370Hz, sample=66, buffer_id=0B:42
    db 0,0,100,0,54,127,12,23,185,0,54,11  ; n1874 t=96.772s dur=100ms, freq=185Hz, sample=54, buffer_id=0B:36
    db 0,0,159,0,86,127,16,24,151,4,86,16  ; n1875 t=96.772s dur=159ms, freq=1175Hz, sample=86, buffer_id=10:56
    db 0,0,159,0,74,127,17,25,75,2,74,16  ; n1876 t=96.772s dur=159ms, freq=587Hz, sample=74, buffer_id=10:4A
    db 0,0,159,0,66,127,18,26,38,1,66,18  ; n1877 t=96.772s dur=159ms, freq=294Hz, sample=66, buffer_id=12:42
    db 0,0,159,0,42,127,19,27,98,0,42,19  ; n1878 t=96.772s dur=159ms, freq=98Hz, sample=42, buffer_id=13:2A
    db 33,0,159,0,30,127,20,28,49,0,30,20  ; n1879 t=96.772s dur=159ms, freq=49Hz, sample=30, buffer_id=14:1E
    db 58,0,100,0,47,127,10,29,123,0,47,10  ; n1880 t=96.804s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 0,0,113,0,85,127,2,6,85,4,85,2  ; n1881 t=96.863s dur=113ms, freq=1109Hz, sample=85, buffer_id=02:55
    db 0,0,113,0,90,127,2,30,117,5,90,2  ; n1882 t=96.863s dur=113ms, freq=1397Hz, sample=90, buffer_id=02:5A
    db 0,0,113,0,73,127,3,31,42,2,73,3  ; n1883 t=96.863s dur=113ms, freq=554Hz, sample=73, buffer_id=03:49
    db 0,0,113,0,78,127,3,15,186,2,78,3  ; n1884 t=96.863s dur=113ms, freq=698Hz, sample=78, buffer_id=03:4E [TRUNCATE prev:ch15 @96408.1ms -> 96862.7ms]
    db 0,0,113,0,73,127,4,16,42,2,73,4  ; n1885 t=96.863s dur=113ms, freq=554Hz, sample=73, buffer_id=04:49 [TRUNCATE prev:ch16 @96408.1ms -> 96862.7ms]
    db 0,0,113,0,78,127,4,0,186,2,78,4  ; n1886 t=96.863s dur=113ms, freq=698Hz, sample=78, buffer_id=04:4E [TRUNCATE prev:ch0 @96565.7ms -> 96862.7ms]
    db 0,0,113,0,66,127,5,1,93,1,66,5  ; n1887 t=96.863s dur=113ms, freq=349Hz, sample=66, buffer_id=05:42 [TRUNCATE prev:ch1 @96589.9ms -> 96862.7ms]
    db 20,0,113,0,61,127,6,2,21,1,61,5  ; n1888 t=96.863s dur=113ms, freq=277Hz, sample=61, buffer_id=05:3D [TRUNCATE prev:ch2 @96589.9ms -> 96862.7ms]
    db 70,0,100,0,47,127,10,4,123,0,47,10  ; n1889 t=96.883s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F [TRUNCATE prev:ch4 @96644.5ms -> 96883.1ms]
    db 0,0,100,0,86,127,2,3,151,4,86,2  ; n1890 t=96.954s dur=100ms, freq=1175Hz, sample=86, buffer_id=02:56
    db 0,0,100,0,90,127,2,5,200,5,90,2  ; n1891 t=96.954s dur=100ms, freq=1480Hz, sample=90, buffer_id=02:5A
    db 0,0,100,0,74,127,3,8,75,2,74,3  ; n1892 t=96.954s dur=100ms, freq=587Hz, sample=74, buffer_id=03:4A
    db 0,0,100,0,78,127,3,12,228,2,78,3  ; n1893 t=96.954s dur=100ms, freq=740Hz, sample=78, buffer_id=03:4E [TRUNCATE prev:ch12 @96771.7ms -> 96953.6ms]
    db 0,0,100,0,74,127,4,13,75,2,74,4  ; n1894 t=96.954s dur=100ms, freq=587Hz, sample=74, buffer_id=04:4A [TRUNCATE prev:ch13 @96771.7ms -> 96953.6ms]
    db 0,0,100,0,78,127,4,14,228,2,78,4  ; n1895 t=96.954s dur=100ms, freq=740Hz, sample=78, buffer_id=04:4E [TRUNCATE prev:ch14 @96771.7ms -> 96953.6ms]
    db 0,0,100,0,66,127,5,17,114,1,66,5  ; n1896 t=96.954s dur=100ms, freq=370Hz, sample=66, buffer_id=05:42 [TRUNCATE prev:ch17 @96771.7ms -> 96953.6ms]
    db 0,0,100,0,62,127,6,18,38,1,62,5  ; n1897 t=96.954s dur=100ms, freq=294Hz, sample=62, buffer_id=05:3E [TRUNCATE prev:ch18 @96771.7ms -> 96953.6ms]
    db 0,0,150,0,87,127,16,7,39,5,87,16  ; n1898 t=96.954s dur=150ms, freq=1319Hz, sample=87, buffer_id=10:57 [TRUNCATE prev:ch7 @96724.8ms -> 96953.6ms]
    db 0,0,159,0,74,127,17,25,147,2,74,16  ; n1899 t=96.954s dur=159ms, freq=659Hz, sample=74, buffer_id=10:4A [TRUNCATE prev:ch25 @96771.7ms -> 96953.6ms]
    db 0,0,159,0,66,127,18,26,74,1,66,18  ; n1900 t=96.954s dur=159ms, freq=330Hz, sample=66, buffer_id=12:42 [TRUNCATE prev:ch26 @96771.7ms -> 96953.6ms]
    db 0,0,159,0,42,127,19,27,92,0,42,19  ; n1901 t=96.954s dur=159ms, freq=92Hz, sample=42, buffer_id=13:2A [TRUNCATE prev:ch27 @96771.7ms -> 96953.6ms]
    db 9,0,159,0,30,127,20,28,46,0,30,20  ; n1902 t=96.954s dur=159ms, freq=46Hz, sample=30, buffer_id=14:1E [TRUNCATE prev:ch28 @96771.7ms -> 96953.6ms]
    db 80,0,100,0,47,127,10,29,123,0,47,10  ; n1903 t=96.963s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F [TRUNCATE prev:ch29 @96804.3ms -> 96962.7ms]
    db 79,0,100,0,47,127,10,4,123,0,47,10  ; n1904 t=97.043s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F [TRUNCATE prev:ch4 @96883.1ms -> 97043.0ms]
    db 13,0,100,0,47,127,10,9,123,0,47,10  ; n1905 t=97.123s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 0,0,192,2,59,127,7,10,247,0,59,7  ; n1906 t=97.135s dur=704ms, freq=247Hz, sample=59, buffer_id=07:3B
    db 0,0,192,2,71,127,7,11,238,1,71,7  ; n1907 t=97.135s dur=704ms, freq=494Hz, sample=71, buffer_id=07:47
    db 0,0,100,0,47,127,12,19,123,0,47,11  ; n1908 t=97.135s dur=100ms, freq=123Hz, sample=47, buffer_id=0B:2F
    db 0,0,100,0,35,127,13,20,62,0,35,13  ; n1909 t=97.135s dur=100ms, freq=62Hz, sample=35, buffer_id=0D:23
    db 0,0,159,0,90,127,16,21,200,5,90,16  ; n1910 t=97.135s dur=159ms, freq=1480Hz, sample=90, buffer_id=10:5A
    db 0,0,159,0,78,127,17,22,228,2,78,16  ; n1911 t=97.135s dur=159ms, freq=740Hz, sample=78, buffer_id=10:4E
    db 0,0,159,0,66,127,18,23,114,1,66,18  ; n1912 t=97.135s dur=159ms, freq=370Hz, sample=66, buffer_id=12:42
    db 0,0,159,0,47,127,19,24,123,0,47,19  ; n1913 t=97.135s dur=159ms, freq=123Hz, sample=47, buffer_id=13:2F
    db 66,0,159,0,35,127,20,0,62,0,35,20  ; n1914 t=97.135s dur=159ms, freq=62Hz, sample=35, buffer_id=14:23 [TRUNCATE prev:ch0 @96862.7ms -> 97135.4ms]
    db 79,0,100,0,47,127,10,1,123,0,47,10  ; n1915 t=97.201s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 36,0,100,0,47,127,10,2,123,0,47,10  ; n1916 t=97.281s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 0,0,159,0,86,127,16,3,151,4,86,16  ; n1917 t=97.317s dur=159ms, freq=1175Hz, sample=86, buffer_id=10:56
    db 0,0,159,0,74,127,17,5,75,2,74,16  ; n1918 t=97.317s dur=159ms, freq=587Hz, sample=74, buffer_id=10:4A
    db 0,0,159,0,66,127,18,6,38,1,66,18  ; n1919 t=97.317s dur=159ms, freq=294Hz, sample=66, buffer_id=12:42
    db 0,0,159,0,47,127,19,7,110,0,47,19  ; n1920 t=97.317s dur=159ms, freq=110Hz, sample=47, buffer_id=13:2F
    db 42,0,159,0,33,127,20,8,55,0,33,20  ; n1921 t=97.317s dur=159ms, freq=55Hz, sample=33, buffer_id=14:21
    db 80,0,100,0,47,127,10,12,123,0,47,10  ; n1922 t=97.360s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 59,0,100,0,47,127,10,13,123,0,47,10  ; n1923 t=97.440s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 0,0,113,0,86,127,2,0,151,4,86,2  ; n1924 t=97.499s dur=113ms, freq=1175Hz, sample=86, buffer_id=02:56
    db 0,0,113,0,90,127,2,4,200,5,90,2  ; n1925 t=97.499s dur=113ms, freq=1480Hz, sample=90, buffer_id=02:5A
    db 0,0,113,0,74,127,3,9,75,2,74,3  ; n1926 t=97.499s dur=113ms, freq=587Hz, sample=74, buffer_id=03:4A
    db 0,0,113,0,78,127,3,14,228,2,78,3  ; n1927 t=97.499s dur=113ms, freq=740Hz, sample=78, buffer_id=03:4E
    db 0,0,113,0,74,127,4,15,75,2,74,4  ; n1928 t=97.499s dur=113ms, freq=587Hz, sample=74, buffer_id=04:4A
    db 0,0,113,0,78,127,4,16,228,2,78,4  ; n1929 t=97.499s dur=113ms, freq=740Hz, sample=78, buffer_id=04:4E
    db 0,0,113,0,66,127,5,18,114,1,66,5  ; n1930 t=97.499s dur=113ms, freq=370Hz, sample=66, buffer_id=05:42
    db 0,0,113,0,62,127,6,17,38,1,62,5  ; n1931 t=97.499s dur=113ms, freq=294Hz, sample=62, buffer_id=05:3E
    db 0,0,100,0,66,127,9,19,114,1,66,9  ; n1932 t=97.499s dur=100ms, freq=370Hz, sample=66, buffer_id=09:42
    db 0,0,100,0,78,127,9,20,228,2,78,9  ; n1933 t=97.499s dur=100ms, freq=740Hz, sample=78, buffer_id=09:4E
    db 0,0,100,0,62,127,11,21,38,1,62,11  ; n1934 t=97.499s dur=100ms, freq=294Hz, sample=62, buffer_id=0B:3E
    db 0,0,100,0,66,127,11,22,114,1,66,11  ; n1935 t=97.499s dur=100ms, freq=370Hz, sample=66, buffer_id=0B:42
    db 0,0,100,0,54,127,12,23,185,0,54,11  ; n1936 t=97.499s dur=100ms, freq=185Hz, sample=54, buffer_id=0B:36
    db 0,0,100,0,90,127,16,24,200,5,90,16  ; n1937 t=97.499s dur=100ms, freq=1480Hz, sample=90, buffer_id=10:5A
    db 0,0,100,0,78,127,17,25,228,2,78,16  ; n1938 t=97.499s dur=100ms, freq=740Hz, sample=78, buffer_id=10:4E
    db 0,0,100,0,66,127,18,27,114,1,66,18  ; n1939 t=97.499s dur=100ms, freq=370Hz, sample=66, buffer_id=12:42
    db 0,0,159,0,42,127,19,26,98,0,42,19  ; n1940 t=97.499s dur=159ms, freq=98Hz, sample=42, buffer_id=13:2A
    db 20,0,159,0,30,127,20,29,49,0,30,20  ; n1941 t=97.499s dur=159ms, freq=49Hz, sample=30, buffer_id=14:1E
    db 70,0,100,0,47,127,10,28,123,0,47,10  ; n1942 t=97.519s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 0,0,113,0,85,127,2,1,85,4,85,2  ; n1943 t=97.590s dur=113ms, freq=1109Hz, sample=85, buffer_id=02:55
    db 0,0,113,0,90,127,2,2,117,5,90,2  ; n1944 t=97.590s dur=113ms, freq=1397Hz, sample=90, buffer_id=02:5A
    db 0,0,113,0,73,127,3,30,42,2,73,3  ; n1945 t=97.590s dur=113ms, freq=554Hz, sample=73, buffer_id=03:49
    db 0,0,113,0,78,127,3,31,186,2,78,3  ; n1946 t=97.590s dur=113ms, freq=698Hz, sample=78, buffer_id=03:4E
    db 0,0,113,0,73,127,4,10,42,2,73,4  ; n1947 t=97.590s dur=113ms, freq=554Hz, sample=73, buffer_id=04:49 [TRUNCATE prev:ch10 @97135.4ms -> 97589.9ms]
    db 0,0,113,0,78,127,4,11,186,2,78,4  ; n1948 t=97.590s dur=113ms, freq=698Hz, sample=78, buffer_id=04:4E [TRUNCATE prev:ch11 @97135.4ms -> 97589.9ms]
    db 0,0,113,0,66,127,5,3,93,1,66,5  ; n1949 t=97.590s dur=113ms, freq=349Hz, sample=66, buffer_id=05:42 [TRUNCATE prev:ch3 @97317.2ms -> 97589.9ms]
    db 0,0,113,0,61,127,6,5,21,1,61,5  ; n1950 t=97.590s dur=113ms, freq=277Hz, sample=61, buffer_id=05:3D [TRUNCATE prev:ch5 @97317.2ms -> 97589.9ms]
    db 0,0,100,0,90,127,16,6,200,5,90,16  ; n1951 t=97.590s dur=100ms, freq=1480Hz, sample=90, buffer_id=10:5A [TRUNCATE prev:ch6 @97317.2ms -> 97589.9ms]
    db 0,0,100,0,78,127,17,7,228,2,78,16  ; n1952 t=97.590s dur=100ms, freq=740Hz, sample=78, buffer_id=10:4E [TRUNCATE prev:ch7 @97317.2ms -> 97589.9ms]
    db 9,0,100,0,66,127,18,8,114,1,66,18  ; n1953 t=97.590s dur=100ms, freq=370Hz, sample=66, buffer_id=12:42 [TRUNCATE prev:ch8 @97317.2ms -> 97589.9ms]
    db 80,0,100,0,47,127,10,12,123,0,47,10  ; n1954 t=97.599s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F [TRUNCATE prev:ch12 @97359.6ms -> 97599.0ms]
    db 2,0,100,0,47,127,10,13,123,0,47,10  ; n1955 t=97.679s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F [TRUNCATE prev:ch13 @97439.9ms -> 97679.3ms]
    db 0,0,100,0,86,127,2,0,151,4,86,2  ; n1956 t=97.681s dur=100ms, freq=1175Hz, sample=86, buffer_id=02:56 [TRUNCATE prev:ch0 @97499.0ms -> 97680.8ms]
    db 0,0,100,0,90,127,2,4,200,5,90,2  ; n1957 t=97.681s dur=100ms, freq=1480Hz, sample=90, buffer_id=02:5A [TRUNCATE prev:ch4 @97499.0ms -> 97680.8ms]
    db 0,0,181,0,74,127,3,9,75,2,74,3  ; n1958 t=97.681s dur=181ms, freq=587Hz, sample=74, buffer_id=03:4A [TRUNCATE prev:ch9 @97499.0ms -> 97680.8ms]
    db 0,0,181,0,78,127,3,14,228,2,78,3  ; n1959 t=97.681s dur=181ms, freq=740Hz, sample=78, buffer_id=03:4E [TRUNCATE prev:ch14 @97499.0ms -> 97680.8ms]
    db 0,0,100,0,74,127,4,15,75,2,74,4  ; n1960 t=97.681s dur=100ms, freq=587Hz, sample=74, buffer_id=04:4A [TRUNCATE prev:ch15 @97499.0ms -> 97680.8ms]
    db 0,0,100,0,78,127,4,16,228,2,78,4  ; n1961 t=97.681s dur=100ms, freq=740Hz, sample=78, buffer_id=04:4E [TRUNCATE prev:ch16 @97499.0ms -> 97680.8ms]
    db 0,0,100,0,66,127,5,18,114,1,66,5  ; n1962 t=97.681s dur=100ms, freq=370Hz, sample=66, buffer_id=05:42 [TRUNCATE prev:ch18 @97499.0ms -> 97680.8ms]
    db 0,0,100,0,62,127,6,17,38,1,62,5  ; n1963 t=97.681s dur=100ms, freq=294Hz, sample=62, buffer_id=05:3E [TRUNCATE prev:ch17 @97499.0ms -> 97680.8ms]
    db 0,0,100,0,90,127,16,24,200,5,90,16  ; n1964 t=97.681s dur=100ms, freq=1480Hz, sample=90, buffer_id=10:5A [TRUNCATE prev:ch24 @97499.0ms -> 97680.8ms]
    db 0,0,100,0,78,127,17,25,228,2,78,16  ; n1965 t=97.681s dur=100ms, freq=740Hz, sample=78, buffer_id=10:4E [TRUNCATE prev:ch25 @97499.0ms -> 97680.8ms]
    db 0,0,100,0,66,127,18,27,114,1,66,18  ; n1966 t=97.681s dur=100ms, freq=370Hz, sample=66, buffer_id=12:42 [TRUNCATE prev:ch27 @97499.0ms -> 97680.8ms]
    db 0,0,159,0,42,127,19,26,92,0,42,19  ; n1967 t=97.681s dur=159ms, freq=92Hz, sample=42, buffer_id=13:2A [TRUNCATE prev:ch26 @97499.0ms -> 97680.8ms]
    db 78,0,159,0,30,127,20,29,46,0,30,20  ; n1968 t=97.681s dur=159ms, freq=46Hz, sample=30, buffer_id=14:1E [TRUNCATE prev:ch29 @97499.0ms -> 97680.8ms]
    db 13,0,100,0,47,127,10,28,123,0,47,10  ; n1969 t=97.759s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F [TRUNCATE prev:ch28 @97519.5ms -> 97758.9ms]
    db 0,0,100,0,90,127,16,6,200,5,90,16  ; n1970 t=97.772s dur=100ms, freq=1480Hz, sample=90, buffer_id=10:5A [TRUNCATE prev:ch6 @97589.9ms -> 97771.7ms]
    db 0,0,100,0,78,127,17,7,228,2,78,16  ; n1971 t=97.772s dur=100ms, freq=740Hz, sample=78, buffer_id=10:4E [TRUNCATE prev:ch7 @97589.9ms -> 97771.7ms]
    db 65,0,100,0,66,127,18,8,114,1,66,18  ; n1972 t=97.772s dur=100ms, freq=370Hz, sample=66, buffer_id=12:42 [TRUNCATE prev:ch8 @97589.9ms -> 97771.7ms]
    db 26,0,100,0,47,127,10,19,123,0,47,10  ; n1973 t=97.837s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 0,0,192,2,59,127,7,20,247,0,59,7  ; n1974 t=97.863s dur=704ms, freq=247Hz, sample=59, buffer_id=07:3B
    db 0,0,192,2,71,127,7,21,238,1,71,7  ; n1975 t=97.863s dur=704ms, freq=494Hz, sample=71, buffer_id=07:47
    db 0,0,100,0,47,127,12,22,123,0,47,11  ; n1976 t=97.863s dur=100ms, freq=123Hz, sample=47, buffer_id=0B:2F
    db 0,0,100,0,35,127,13,23,62,0,35,13  ; n1977 t=97.863s dur=100ms, freq=62Hz, sample=35, buffer_id=0D:23
    db 0,0,159,0,90,127,16,24,117,5,90,16  ; n1978 t=97.863s dur=159ms, freq=1397Hz, sample=90, buffer_id=10:5A [TRUNCATE prev:ch24 @97680.8ms -> 97862.7ms]
    db 0,0,159,0,78,127,17,25,186,2,78,16  ; n1979 t=97.863s dur=159ms, freq=698Hz, sample=78, buffer_id=10:4E [TRUNCATE prev:ch25 @97680.8ms -> 97862.7ms]
    db 0,0,159,0,66,127,18,27,93,1,66,18  ; n1980 t=97.863s dur=159ms, freq=349Hz, sample=66, buffer_id=12:42 [TRUNCATE prev:ch27 @97680.8ms -> 97862.7ms]
    db 0,0,159,0,47,127,19,1,123,0,47,19  ; n1981 t=97.863s dur=159ms, freq=123Hz, sample=47, buffer_id=13:2F [TRUNCATE prev:ch1 @97589.9ms -> 97862.7ms]
    db 54,0,159,0,35,127,20,2,62,0,35,20  ; n1982 t=97.863s dur=159ms, freq=62Hz, sample=35, buffer_id=14:23 [TRUNCATE prev:ch2 @97589.9ms -> 97862.7ms]
    db 80,0,100,0,47,127,10,3,123,0,47,10  ; n1983 t=97.917s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 48,0,100,0,47,127,10,0,123,0,47,10  ; n1984 t=97.997s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 0,0,159,0,85,127,16,4,85,4,85,16  ; n1985 t=98.044s dur=159ms, freq=1109Hz, sample=85, buffer_id=10:55
    db 0,0,159,0,73,127,17,5,42,2,73,16  ; n1986 t=98.044s dur=159ms, freq=554Hz, sample=73, buffer_id=10:49
    db 0,0,159,0,66,127,18,10,21,1,66,18  ; n1987 t=98.044s dur=159ms, freq=277Hz, sample=66, buffer_id=12:42
    db 0,0,159,0,47,127,19,11,110,0,47,19  ; n1988 t=98.044s dur=159ms, freq=110Hz, sample=47, buffer_id=13:2F
    db 32,0,159,0,33,127,20,12,55,0,33,20  ; n1989 t=98.044s dur=159ms, freq=55Hz, sample=33, buffer_id=14:21
    db 79,0,100,0,47,127,10,6,123,0,47,10  ; n1990 t=98.077s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 70,0,100,0,47,127,10,7,123,0,47,10  ; n1991 t=98.156s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 0,0,113,0,85,127,2,1,85,4,85,2  ; n1992 t=98.226s dur=113ms, freq=1109Hz, sample=85, buffer_id=02:55
    db 0,0,113,0,90,127,2,2,117,5,90,2  ; n1993 t=98.226s dur=113ms, freq=1397Hz, sample=90, buffer_id=02:5A
    db 0,0,113,0,73,127,3,3,42,2,73,3  ; n1994 t=98.226s dur=113ms, freq=554Hz, sample=73, buffer_id=03:49
    db 0,0,113,0,78,127,3,8,186,2,78,3  ; n1995 t=98.226s dur=113ms, freq=698Hz, sample=78, buffer_id=03:4E
    db 0,0,113,0,73,127,4,9,42,2,73,4  ; n1996 t=98.226s dur=113ms, freq=554Hz, sample=73, buffer_id=04:49
    db 0,0,113,0,78,127,4,13,186,2,78,4  ; n1997 t=98.226s dur=113ms, freq=698Hz, sample=78, buffer_id=04:4E
    db 0,0,113,0,66,127,5,14,93,1,66,5  ; n1998 t=98.226s dur=113ms, freq=349Hz, sample=66, buffer_id=05:42
    db 0,0,113,0,61,127,6,15,21,1,61,5  ; n1999 t=98.226s dur=113ms, freq=277Hz, sample=61, buffer_id=05:3D
    db 0,0,100,0,66,127,9,16,114,1,66,9  ; n2000 t=98.226s dur=100ms, freq=370Hz, sample=66, buffer_id=09:42
    db 0,0,100,0,78,127,9,17,228,2,78,9  ; n2001 t=98.226s dur=100ms, freq=740Hz, sample=78, buffer_id=09:4E
    db 0,0,100,0,61,127,11,18,21,1,61,11  ; n2002 t=98.226s dur=100ms, freq=277Hz, sample=61, buffer_id=0B:3D
    db 0,0,100,0,66,127,11,19,93,1,66,11  ; n2003 t=98.226s dur=100ms, freq=349Hz, sample=66, buffer_id=0B:42
    db 0,0,100,0,54,127,12,22,185,0,54,11  ; n2004 t=98.226s dur=100ms, freq=185Hz, sample=54, buffer_id=0B:36
    db 0,0,100,0,90,127,16,23,117,5,90,16  ; n2005 t=98.226s dur=100ms, freq=1397Hz, sample=90, buffer_id=10:5A
    db 0,0,100,0,78,127,17,24,186,2,78,16  ; n2006 t=98.226s dur=100ms, freq=698Hz, sample=78, buffer_id=10:4E
    db 0,0,100,0,66,127,18,25,93,1,66,18  ; n2007 t=98.226s dur=100ms, freq=349Hz, sample=66, buffer_id=12:42
    db 0,0,159,0,42,127,19,27,98,0,42,19  ; n2008 t=98.226s dur=159ms, freq=98Hz, sample=42, buffer_id=13:2A
    db 9,0,159,0,30,127,20,26,49,0,30,20  ; n2009 t=98.226s dur=159ms, freq=49Hz, sample=30, buffer_id=14:1E
    db 79,0,100,0,47,127,10,29,123,0,47,10  ; n2010 t=98.235s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 2,0,100,0,47,127,10,30,123,0,47,10  ; n2011 t=98.315s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 0,0,113,0,85,127,2,0,23,4,85,2  ; n2012 t=98.317s dur=113ms, freq=1047Hz, sample=85, buffer_id=02:55
    db 0,0,113,0,86,127,2,28,39,5,86,2  ; n2013 t=98.317s dur=113ms, freq=1319Hz, sample=86, buffer_id=02:56
    db 0,0,113,0,71,127,3,31,11,2,71,3  ; n2014 t=98.317s dur=113ms, freq=523Hz, sample=71, buffer_id=03:47
    db 0,0,113,0,74,127,3,20,147,2,74,3  ; n2015 t=98.317s dur=113ms, freq=659Hz, sample=74, buffer_id=03:4A [TRUNCATE prev:ch20 @97862.7ms -> 98317.2ms]
    db 0,0,113,0,73,127,4,21,11,2,73,4  ; n2016 t=98.317s dur=113ms, freq=523Hz, sample=73, buffer_id=04:49 [TRUNCATE prev:ch21 @97862.7ms -> 98317.2ms]
    db 0,0,113,0,74,127,4,4,147,2,74,4  ; n2017 t=98.317s dur=113ms, freq=659Hz, sample=74, buffer_id=04:4A [TRUNCATE prev:ch4 @98044.5ms -> 98317.2ms]
    db 0,0,113,0,62,127,5,5,74,1,62,5  ; n2018 t=98.317s dur=113ms, freq=330Hz, sample=62, buffer_id=05:3E [TRUNCATE prev:ch5 @98044.5ms -> 98317.2ms]
    db 0,0,113,0,61,127,6,10,6,1,61,5  ; n2019 t=98.317s dur=113ms, freq=262Hz, sample=61, buffer_id=05:3D [TRUNCATE prev:ch10 @98044.5ms -> 98317.2ms]
    db 0,0,100,0,90,127,16,11,117,5,90,16  ; n2020 t=98.317s dur=100ms, freq=1397Hz, sample=90, buffer_id=10:5A [TRUNCATE prev:ch11 @98044.5ms -> 98317.2ms]
    db 0,0,100,0,78,127,17,12,186,2,78,16  ; n2021 t=98.317s dur=100ms, freq=698Hz, sample=78, buffer_id=10:4E [TRUNCATE prev:ch12 @98044.5ms -> 98317.2ms]
    db 77,0,100,0,66,127,18,6,93,1,66,18  ; n2022 t=98.317s dur=100ms, freq=349Hz, sample=66, buffer_id=12:42 [TRUNCATE prev:ch6 @98077.0ms -> 98317.2ms]
    db 14,0,100,0,47,127,10,7,123,0,47,10  ; n2023 t=98.394s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F [TRUNCATE prev:ch7 @98155.8ms -> 98394.5ms]
    db 0,0,181,0,85,127,2,1,85,4,85,2  ; n2024 t=98.408s dur=181ms, freq=1109Hz, sample=85, buffer_id=02:55 [TRUNCATE prev:ch1 @98226.3ms -> 98408.1ms]
    db 0,0,181,0,90,127,2,2,117,5,90,2  ; n2025 t=98.408s dur=181ms, freq=1397Hz, sample=90, buffer_id=02:5A [TRUNCATE prev:ch2 @98226.3ms -> 98408.1ms]
    db 0,0,181,0,73,127,3,3,42,2,73,3  ; n2026 t=98.408s dur=181ms, freq=554Hz, sample=73, buffer_id=03:49 [TRUNCATE prev:ch3 @98226.3ms -> 98408.1ms]
    db 0,0,181,0,78,127,3,8,186,2,78,3  ; n2027 t=98.408s dur=181ms, freq=698Hz, sample=78, buffer_id=03:4E [TRUNCATE prev:ch8 @98226.3ms -> 98408.1ms]
    db 0,0,181,0,73,127,4,9,42,2,73,4  ; n2028 t=98.408s dur=181ms, freq=554Hz, sample=73, buffer_id=04:49 [TRUNCATE prev:ch9 @98226.3ms -> 98408.1ms]
    db 0,0,181,0,78,127,4,13,186,2,78,4  ; n2029 t=98.408s dur=181ms, freq=698Hz, sample=78, buffer_id=04:4E [TRUNCATE prev:ch13 @98226.3ms -> 98408.1ms]
    db 0,0,181,0,66,127,5,14,93,1,66,5  ; n2030 t=98.408s dur=181ms, freq=349Hz, sample=66, buffer_id=05:42 [TRUNCATE prev:ch14 @98226.3ms -> 98408.1ms]
    db 0,0,181,0,61,127,6,15,21,1,61,5  ; n2031 t=98.408s dur=181ms, freq=277Hz, sample=61, buffer_id=05:3D [TRUNCATE prev:ch15 @98226.3ms -> 98408.1ms]
    db 0,0,100,0,90,127,16,23,117,5,90,16  ; n2032 t=98.408s dur=100ms, freq=1397Hz, sample=90, buffer_id=10:5A [TRUNCATE prev:ch23 @98226.3ms -> 98408.1ms]
    db 0,0,100,0,78,127,17,24,186,2,78,16  ; n2033 t=98.408s dur=100ms, freq=698Hz, sample=78, buffer_id=10:4E [TRUNCATE prev:ch24 @98226.3ms -> 98408.1ms]
    db 0,0,100,0,66,127,18,25,93,1,66,18  ; n2034 t=98.408s dur=100ms, freq=349Hz, sample=66, buffer_id=12:42 [TRUNCATE prev:ch25 @98226.3ms -> 98408.1ms]
    db 0,0,159,0,42,127,19,27,92,0,42,19  ; n2035 t=98.408s dur=159ms, freq=92Hz, sample=42, buffer_id=13:2A [TRUNCATE prev:ch27 @98226.3ms -> 98408.1ms]
    db 66,0,159,0,30,127,20,26,46,0,30,20  ; n2036 t=98.408s dur=159ms, freq=46Hz, sample=30, buffer_id=14:1E [TRUNCATE prev:ch26 @98226.3ms -> 98408.1ms]
    db 25,0,100,0,47,127,10,29,123,0,47,10  ; n2037 t=98.474s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F [TRUNCATE prev:ch29 @98235.4ms -> 98474.0ms]
    db 0,0,100,0,90,127,16,11,117,5,90,16  ; n2038 t=98.499s dur=100ms, freq=1397Hz, sample=90, buffer_id=10:5A [TRUNCATE prev:ch11 @98317.2ms -> 98499.0ms]
    db 0,0,100,0,78,127,17,12,186,2,78,16  ; n2039 t=98.499s dur=100ms, freq=698Hz, sample=78, buffer_id=10:4E [TRUNCATE prev:ch12 @98317.2ms -> 98499.0ms]
    db 55,0,100,0,66,127,18,6,93,1,66,18  ; n2040 t=98.499s dur=100ms, freq=349Hz, sample=66, buffer_id=12:42 [TRUNCATE prev:ch6 @98317.2ms -> 98499.0ms]
    db 36,0,100,0,47,127,10,16,123,0,47,10  ; n2041 t=98.554s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 0,0,192,2,59,127,7,17,247,0,59,7  ; n2042 t=98.590s dur=704ms, freq=247Hz, sample=59, buffer_id=07:3B
    db 0,0,192,2,71,127,7,18,238,1,71,7  ; n2043 t=98.590s dur=704ms, freq=494Hz, sample=71, buffer_id=07:47
    db 0,0,100,0,47,127,12,19,123,0,47,11  ; n2044 t=98.590s dur=100ms, freq=123Hz, sample=47, buffer_id=0B:2F
    db 0,0,100,0,35,127,13,22,62,0,35,13  ; n2045 t=98.590s dur=100ms, freq=62Hz, sample=35, buffer_id=0D:23
    db 0,0,150,0,87,127,16,30,39,5,87,16  ; n2046 t=98.590s dur=150ms, freq=1319Hz, sample=87, buffer_id=10:57 [TRUNCATE prev:ch30 @98314.9ms -> 98589.9ms]
    db 0,0,159,0,74,127,17,0,147,2,74,16  ; n2047 t=98.590s dur=159ms, freq=659Hz, sample=74, buffer_id=10:4A [TRUNCATE prev:ch0 @98317.2ms -> 98589.9ms]
    db 0,0,159,0,66,127,18,25,74,1,66,18  ; n2048 t=98.590s dur=159ms, freq=330Hz, sample=66, buffer_id=12:42 [TRUNCATE prev:ch25 @98408.1ms -> 98589.9ms]
    db 0,0,159,0,47,127,19,4,123,0,47,19  ; n2049 t=98.590s dur=159ms, freq=123Hz, sample=47, buffer_id=13:2F [TRUNCATE prev:ch4 @98317.2ms -> 98589.9ms]
    db 44,0,159,0,35,127,20,5,62,0,35,20  ; n2050 t=98.590s dur=159ms, freq=62Hz, sample=35, buffer_id=14:23 [TRUNCATE prev:ch5 @98317.2ms -> 98589.9ms]
    db 79,0,100,0,47,127,10,10,123,0,47,10  ; n2051 t=98.634s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 59,0,100,0,47,127,10,20,123,0,47,10  ; n2052 t=98.713s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 0,0,159,0,85,127,16,7,23,4,85,16  ; n2053 t=98.772s dur=159ms, freq=1047Hz, sample=85, buffer_id=10:55
    db 0,0,159,0,73,127,17,21,11,2,73,16  ; n2054 t=98.772s dur=159ms, freq=523Hz, sample=73, buffer_id=10:49
    db 0,0,148,0,54,127,18,23,6,1,54,18  ; n2055 t=98.772s dur=148ms, freq=262Hz, sample=54, buffer_id=12:36
    db 0,0,159,0,47,127,19,24,110,0,47,19  ; n2056 t=98.772s dur=159ms, freq=110Hz, sample=47, buffer_id=13:2F
    db 21,0,159,0,33,127,20,26,55,0,33,20  ; n2057 t=98.772s dur=159ms, freq=55Hz, sample=33, buffer_id=14:21
    db 79,0,100,0,47,127,10,1,123,0,47,10  ; n2058 t=98.793s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 80,0,100,0,47,127,10,2,123,0,47,10  ; n2059 t=98.872s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 2,0,100,0,47,127,10,0,123,0,47,10  ; n2060 t=98.952s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 0,0,113,0,85,127,2,3,23,4,85,2  ; n2061 t=98.954s dur=113ms, freq=1047Hz, sample=85, buffer_id=02:55
    db 0,0,113,0,86,127,2,4,39,5,86,2  ; n2062 t=98.954s dur=113ms, freq=1319Hz, sample=86, buffer_id=02:56
    db 0,0,113,0,71,127,3,5,11,2,71,3  ; n2063 t=98.954s dur=113ms, freq=523Hz, sample=71, buffer_id=03:47
    db 0,0,113,0,74,127,3,6,147,2,74,3  ; n2064 t=98.954s dur=113ms, freq=659Hz, sample=74, buffer_id=03:4A
    db 0,0,113,0,73,127,4,8,11,2,73,4  ; n2065 t=98.954s dur=113ms, freq=523Hz, sample=73, buffer_id=04:49
    db 0,0,113,0,74,127,4,9,147,2,74,4  ; n2066 t=98.954s dur=113ms, freq=659Hz, sample=74, buffer_id=04:4A
    db 0,0,113,0,62,127,5,10,74,1,62,5  ; n2067 t=98.954s dur=113ms, freq=330Hz, sample=62, buffer_id=05:3E
    db 0,0,113,0,61,127,6,11,6,1,61,5  ; n2068 t=98.954s dur=113ms, freq=262Hz, sample=61, buffer_id=05:3D
    db 0,0,100,0,66,127,9,12,114,1,66,9  ; n2069 t=98.954s dur=100ms, freq=370Hz, sample=66, buffer_id=09:42
    db 0,0,100,0,78,127,9,13,228,2,78,9  ; n2070 t=98.954s dur=100ms, freq=740Hz, sample=78, buffer_id=09:4E
    db 0,0,100,0,59,127,11,14,6,1,59,11  ; n2071 t=98.954s dur=100ms, freq=262Hz, sample=59, buffer_id=0B:3B
    db 0,0,100,0,62,127,11,15,74,1,62,11  ; n2072 t=98.954s dur=100ms, freq=330Hz, sample=62, buffer_id=0B:3E
    db 0,0,100,0,54,127,12,16,185,0,54,11  ; n2073 t=98.954s dur=100ms, freq=185Hz, sample=54, buffer_id=0B:36
    db 0,0,100,0,87,127,16,19,39,5,87,16  ; n2074 t=98.954s dur=100ms, freq=1319Hz, sample=87, buffer_id=10:57
    db 0,0,100,0,74,127,17,22,147,2,74,16  ; n2075 t=98.954s dur=100ms, freq=659Hz, sample=74, buffer_id=10:4A
    db 0,0,100,0,66,127,18,27,74,1,66,18  ; n2076 t=98.954s dur=100ms, freq=330Hz, sample=66, buffer_id=12:42
    db 0,0,159,0,42,127,19,25,98,0,42,19  ; n2077 t=98.954s dur=159ms, freq=98Hz, sample=42, buffer_id=13:2A
    db 78,0,159,0,30,127,20,28,49,0,30,20  ; n2078 t=98.954s dur=159ms, freq=49Hz, sample=30, buffer_id=14:1E
    db 13,0,100,0,47,127,10,30,123,0,47,10  ; n2079 t=99.032s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 0,0,113,0,85,127,2,20,220,3,85,2  ; n2080 t=99.044s dur=113ms, freq=988Hz, sample=85, buffer_id=02:55
    db 0,0,113,0,86,127,2,29,221,4,86,2  ; n2081 t=99.044s dur=113ms, freq=1245Hz, sample=86, buffer_id=02:56
    db 0,0,113,0,71,127,3,31,238,1,71,3  ; n2082 t=99.044s dur=113ms, freq=494Hz, sample=71, buffer_id=03:47 [TRUNCATE prev:ch31 @98317.2ms -> 99044.5ms]
    db 0,0,113,0,74,127,3,17,110,2,74,3  ; n2083 t=99.044s dur=113ms, freq=622Hz, sample=74, buffer_id=03:4A [TRUNCATE prev:ch17 @98589.9ms -> 99044.5ms]
    db 0,0,113,0,70,127,4,18,238,1,70,4  ; n2084 t=99.044s dur=113ms, freq=494Hz, sample=70, buffer_id=04:46 [TRUNCATE prev:ch18 @98589.9ms -> 99044.5ms]
    db 0,0,113,0,74,127,4,7,110,2,74,4  ; n2085 t=99.044s dur=113ms, freq=622Hz, sample=74, buffer_id=04:4A [TRUNCATE prev:ch7 @98771.7ms -> 99044.5ms]
    db 0,0,113,0,62,127,5,21,55,1,62,5  ; n2086 t=99.044s dur=113ms, freq=311Hz, sample=62, buffer_id=05:3E [TRUNCATE prev:ch21 @98771.7ms -> 99044.5ms]
    db 0,0,113,0,61,127,6,23,247,0,61,5  ; n2087 t=99.044s dur=113ms, freq=247Hz, sample=61, buffer_id=05:3D [TRUNCATE prev:ch23 @98771.7ms -> 99044.5ms]
    db 0,0,100,0,87,127,16,24,39,5,87,16  ; n2088 t=99.044s dur=100ms, freq=1319Hz, sample=87, buffer_id=10:57 [TRUNCATE prev:ch24 @98771.7ms -> 99044.5ms]
    db 0,0,100,0,74,127,17,26,147,2,74,16  ; n2089 t=99.044s dur=100ms, freq=659Hz, sample=74, buffer_id=10:4A [TRUNCATE prev:ch26 @98771.7ms -> 99044.5ms]
    db 66,0,100,0,66,127,18,1,74,1,66,18  ; n2090 t=99.044s dur=100ms, freq=330Hz, sample=66, buffer_id=12:42 [TRUNCATE prev:ch1 @98793.0ms -> 99044.5ms]
    db 25,0,100,0,47,127,10,2,123,0,47,10  ; n2091 t=99.110s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F [TRUNCATE prev:ch2 @98871.7ms -> 99110.4ms]
    db 0,0,181,0,85,127,2,3,23,4,85,2  ; n2092 t=99.135s dur=181ms, freq=1047Hz, sample=85, buffer_id=02:55 [TRUNCATE prev:ch3 @98953.6ms -> 99135.4ms]
    db 0,0,162,0,86,127,2,4,39,5,86,2  ; n2093 t=99.135s dur=162ms, freq=1319Hz, sample=86, buffer_id=02:56 [TRUNCATE prev:ch4 @98953.6ms -> 99135.4ms]
    db 0,0,181,0,71,127,3,5,11,2,71,3  ; n2094 t=99.135s dur=181ms, freq=523Hz, sample=71, buffer_id=03:47 [TRUNCATE prev:ch5 @98953.6ms -> 99135.4ms]
    db 0,0,162,0,74,127,3,6,147,2,74,3  ; n2095 t=99.135s dur=162ms, freq=659Hz, sample=74, buffer_id=03:4A [TRUNCATE prev:ch6 @98953.6ms -> 99135.4ms]
    db 0,0,181,0,73,127,4,8,11,2,73,4  ; n2096 t=99.135s dur=181ms, freq=523Hz, sample=73, buffer_id=04:49 [TRUNCATE prev:ch8 @98953.6ms -> 99135.4ms]
    db 0,0,181,0,74,127,4,9,147,2,74,4  ; n2097 t=99.135s dur=181ms, freq=659Hz, sample=74, buffer_id=04:4A [TRUNCATE prev:ch9 @98953.6ms -> 99135.4ms]
    db 0,0,162,0,62,127,5,10,74,1,62,5  ; n2098 t=99.135s dur=162ms, freq=330Hz, sample=62, buffer_id=05:3E [TRUNCATE prev:ch10 @98953.6ms -> 99135.4ms]
    db 0,0,181,0,61,127,6,11,6,1,61,5  ; n2099 t=99.135s dur=181ms, freq=262Hz, sample=61, buffer_id=05:3D [TRUNCATE prev:ch11 @98953.6ms -> 99135.4ms]
    db 0,0,100,0,87,127,16,19,39,5,87,16  ; n2100 t=99.135s dur=100ms, freq=1319Hz, sample=87, buffer_id=10:57 [TRUNCATE prev:ch19 @98953.6ms -> 99135.4ms]
    db 0,0,100,0,74,127,17,22,147,2,74,16  ; n2101 t=99.135s dur=100ms, freq=659Hz, sample=74, buffer_id=10:4A [TRUNCATE prev:ch22 @98953.6ms -> 99135.4ms]
    db 0,0,100,0,66,127,18,27,74,1,66,18  ; n2102 t=99.135s dur=100ms, freq=330Hz, sample=66, buffer_id=12:42 [TRUNCATE prev:ch27 @98953.6ms -> 99135.4ms]
    db 0,0,159,0,42,127,19,25,92,0,42,19  ; n2103 t=99.135s dur=159ms, freq=92Hz, sample=42, buffer_id=13:2A [TRUNCATE prev:ch25 @98953.6ms -> 99135.4ms]
    db 54,0,159,0,30,127,20,28,46,0,30,20  ; n2104 t=99.135s dur=159ms, freq=46Hz, sample=30, buffer_id=14:1E [TRUNCATE prev:ch28 @98953.6ms -> 99135.4ms]
    db 37,0,100,0,47,127,10,0,123,0,47,10  ; n2105 t=99.189s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F [TRUNCATE prev:ch0 @98952.0ms -> 99189.2ms]
    db 0,0,100,0,87,127,16,24,39,5,87,16  ; n2106 t=99.226s dur=100ms, freq=1319Hz, sample=87, buffer_id=10:57 [TRUNCATE prev:ch24 @99044.5ms -> 99226.3ms]
    db 0,0,100,0,74,127,17,26,147,2,74,16  ; n2107 t=99.226s dur=100ms, freq=659Hz, sample=74, buffer_id=10:4A [TRUNCATE prev:ch26 @99044.5ms -> 99226.3ms]
    db 43,0,100,0,66,127,18,1,74,1,66,18  ; n2108 t=99.226s dur=100ms, freq=330Hz, sample=66, buffer_id=12:42 [TRUNCATE prev:ch1 @99044.5ms -> 99226.3ms]
    db 48,0,100,0,47,127,10,12,123,0,47,10  ; n2109 t=99.269s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 0,0,192,2,59,127,7,13,247,0,59,7  ; n2110 t=99.317s dur=704ms, freq=247Hz, sample=59, buffer_id=07:3B
    db 0,0,192,2,71,127,7,14,238,1,71,7  ; n2111 t=99.317s dur=704ms, freq=494Hz, sample=71, buffer_id=07:47
    db 0,0,100,0,47,127,12,15,123,0,47,11  ; n2112 t=99.317s dur=100ms, freq=123Hz, sample=47, buffer_id=0B:2F
    db 0,0,100,0,35,127,13,16,62,0,35,13  ; n2113 t=99.317s dur=100ms, freq=62Hz, sample=35, buffer_id=0D:23
    db 0,0,159,0,85,127,16,30,220,3,85,16  ; n2114 t=99.317s dur=159ms, freq=988Hz, sample=85, buffer_id=10:55 [TRUNCATE prev:ch30 @99031.6ms -> 99317.2ms]
    db 0,0,159,0,70,127,17,7,238,1,70,16  ; n2115 t=99.317s dur=159ms, freq=494Hz, sample=70, buffer_id=10:46 [TRUNCATE prev:ch7 @99044.5ms -> 99317.2ms]
    db 0,0,157,0,54,127,18,17,247,0,54,18  ; n2116 t=99.317s dur=157ms, freq=247Hz, sample=54, buffer_id=12:36 [TRUNCATE prev:ch17 @99044.5ms -> 99317.2ms]
    db 0,0,159,0,47,127,19,18,123,0,47,19  ; n2117 t=99.317s dur=159ms, freq=123Hz, sample=47, buffer_id=13:2F [TRUNCATE prev:ch18 @99044.5ms -> 99317.2ms]
    db 33,0,159,0,35,127,20,20,62,0,35,20  ; n2118 t=99.317s dur=159ms, freq=62Hz, sample=35, buffer_id=14:23 [TRUNCATE prev:ch20 @99044.5ms -> 99317.2ms]
    db 79,0,100,0,47,127,10,2,123,0,47,10  ; n2119 t=99.350s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F [TRUNCATE prev:ch2 @99110.4ms -> 99349.8ms]
    db 70,0,100,0,47,127,10,21,123,0,47,10  ; n2120 t=99.429s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 0,0,159,0,85,127,16,0,85,4,85,16  ; n2121 t=99.499s dur=159ms, freq=1109Hz, sample=85, buffer_id=10:55
    db 0,0,159,0,73,127,17,4,42,2,73,16  ; n2122 t=99.499s dur=159ms, freq=554Hz, sample=73, buffer_id=10:49
    db 0,0,159,0,66,127,18,6,21,1,66,18  ; n2123 t=99.499s dur=159ms, freq=277Hz, sample=66, buffer_id=12:42
    db 0,0,159,0,47,127,19,10,110,0,47,19  ; n2124 t=99.499s dur=159ms, freq=110Hz, sample=47, buffer_id=13:2F
    db 9,0,159,0,33,127,20,19,55,0,33,20  ; n2125 t=99.499s dur=159ms, freq=55Hz, sample=33, buffer_id=14:21
    db 80,0,100,0,47,127,10,22,123,0,47,10  ; n2126 t=99.508s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 79,0,100,0,47,127,10,1,123,0,47,10  ; n2127 t=99.588s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 14,0,100,0,47,127,10,3,123,0,47,10  ; n2128 t=99.667s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 0,0,113,0,85,127,2,2,220,3,85,2  ; n2129 t=99.681s dur=113ms, freq=988Hz, sample=85, buffer_id=02:55
    db 0,0,113,0,86,127,2,5,151,4,86,2  ; n2130 t=99.681s dur=113ms, freq=1175Hz, sample=86, buffer_id=02:56
    db 0,0,113,0,71,127,3,7,238,1,71,3  ; n2131 t=99.681s dur=113ms, freq=494Hz, sample=71, buffer_id=03:47
    db 0,0,113,0,74,127,3,8,75,2,74,3  ; n2132 t=99.681s dur=113ms, freq=587Hz, sample=74, buffer_id=03:4A
    db 0,0,113,0,70,127,4,9,238,1,70,4  ; n2133 t=99.681s dur=113ms, freq=494Hz, sample=70, buffer_id=04:46
    db 0,0,113,0,74,127,4,11,75,2,74,4  ; n2134 t=99.681s dur=113ms, freq=587Hz, sample=74, buffer_id=04:4A
    db 0,0,113,0,62,127,5,12,38,1,62,5  ; n2135 t=99.681s dur=113ms, freq=294Hz, sample=62, buffer_id=05:3E
    db 0,0,113,0,61,127,6,15,247,0,61,5  ; n2136 t=99.681s dur=113ms, freq=247Hz, sample=61, buffer_id=05:3D
    db 0,0,100,0,66,127,9,16,114,1,66,9  ; n2137 t=99.681s dur=100ms, freq=370Hz, sample=66, buffer_id=09:42
    db 0,0,100,0,78,127,9,17,228,2,78,9  ; n2138 t=99.681s dur=100ms, freq=740Hz, sample=78, buffer_id=09:4E
    db 0,0,100,0,59,127,11,18,247,0,59,11  ; n2139 t=99.681s dur=100ms, freq=247Hz, sample=59, buffer_id=0B:3B
    db 0,0,100,0,62,127,11,20,38,1,62,11  ; n2140 t=99.681s dur=100ms, freq=294Hz, sample=62, buffer_id=0B:3E
    db 0,0,100,0,54,127,12,23,185,0,54,11  ; n2141 t=99.681s dur=100ms, freq=185Hz, sample=54, buffer_id=0B:36
    db 0,0,159,0,86,127,16,24,151,4,86,16  ; n2142 t=99.681s dur=159ms, freq=1175Hz, sample=86, buffer_id=10:56
    db 0,0,159,0,74,127,17,25,75,2,74,16  ; n2143 t=99.681s dur=159ms, freq=587Hz, sample=74, buffer_id=10:4A
    db 0,0,159,0,66,127,18,26,38,1,66,18  ; n2144 t=99.681s dur=159ms, freq=294Hz, sample=66, buffer_id=12:42
    db 0,0,159,0,42,127,19,27,98,0,42,19  ; n2145 t=99.681s dur=159ms, freq=98Hz, sample=42, buffer_id=13:2A
    db 65,0,159,0,30,127,20,29,49,0,30,20  ; n2146 t=99.681s dur=159ms, freq=49Hz, sample=30, buffer_id=14:1E
    db 26,0,100,0,47,127,10,28,123,0,47,10  ; n2147 t=99.746s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 0,0,113,0,85,127,2,21,164,3,85,2  ; n2148 t=99.772s dur=113ms, freq=932Hz, sample=85, buffer_id=02:55
    db 0,0,113,0,85,127,2,30,85,4,85,2  ; n2149 t=99.772s dur=113ms, freq=1109Hz, sample=85, buffer_id=02:55
    db 0,0,113,0,71,127,3,31,210,1,71,3  ; n2150 t=99.772s dur=113ms, freq=466Hz, sample=71, buffer_id=03:47 [TRUNCATE prev:ch31 @99044.5ms -> 99771.7ms]
    db 0,0,113,0,73,127,3,13,42,2,73,3  ; n2151 t=99.772s dur=113ms, freq=554Hz, sample=73, buffer_id=03:49 [TRUNCATE prev:ch13 @99317.2ms -> 99771.7ms]
    db 0,0,113,0,70,127,4,14,210,1,70,4  ; n2152 t=99.772s dur=113ms, freq=466Hz, sample=70, buffer_id=04:46 [TRUNCATE prev:ch14 @99317.2ms -> 99771.7ms]
    db 0,0,113,0,73,127,4,0,42,2,73,4  ; n2153 t=99.772s dur=113ms, freq=554Hz, sample=73, buffer_id=04:49 [TRUNCATE prev:ch0 @99499.0ms -> 99771.7ms]
    db 0,0,113,0,61,127,5,4,21,1,61,5  ; n2154 t=99.772s dur=113ms, freq=277Hz, sample=61, buffer_id=05:3D [TRUNCATE prev:ch4 @99499.0ms -> 99771.7ms]
    db 55,0,113,0,61,127,6,6,233,0,61,5  ; n2155 t=99.772s dur=113ms, freq=233Hz, sample=61, buffer_id=05:3D [TRUNCATE prev:ch6 @99499.0ms -> 99771.7ms]
    db 36,0,100,0,47,127,10,22,123,0,47,10  ; n2156 t=99.827s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F [TRUNCATE prev:ch22 @99508.1ms -> 99827.0ms]
    db 0,0,181,0,85,127,2,10,220,3,85,2  ; n2157 t=99.863s dur=181ms, freq=988Hz, sample=85, buffer_id=02:55
    db 0,0,181,0,86,127,2,19,151,4,86,2  ; n2158 t=99.863s dur=181ms, freq=1175Hz, sample=86, buffer_id=02:56
    db 0,0,181,0,71,127,3,7,238,1,71,3  ; n2159 t=99.863s dur=181ms, freq=494Hz, sample=71, buffer_id=03:47 [TRUNCATE prev:ch7 @99680.8ms -> 99862.7ms]
    db 0,0,181,0,74,127,3,8,75,2,74,3  ; n2160 t=99.863s dur=181ms, freq=587Hz, sample=74, buffer_id=03:4A [TRUNCATE prev:ch8 @99680.8ms -> 99862.7ms]
    db 0,0,181,0,70,127,4,9,238,1,70,4  ; n2161 t=99.863s dur=181ms, freq=494Hz, sample=70, buffer_id=04:46 [TRUNCATE prev:ch9 @99680.8ms -> 99862.7ms]
    db 0,0,181,0,74,127,4,11,75,2,74,4  ; n2162 t=99.863s dur=181ms, freq=587Hz, sample=74, buffer_id=04:4A [TRUNCATE prev:ch11 @99680.8ms -> 99862.7ms]
    db 0,0,181,0,62,127,5,12,38,1,62,5  ; n2163 t=99.863s dur=181ms, freq=294Hz, sample=62, buffer_id=05:3E [TRUNCATE prev:ch12 @99680.8ms -> 99862.7ms]
    db 0,0,181,0,61,127,6,15,247,0,61,5  ; n2164 t=99.863s dur=181ms, freq=247Hz, sample=61, buffer_id=05:3D [TRUNCATE prev:ch15 @99680.8ms -> 99862.7ms]
    db 0,0,150,0,87,127,16,1,39,5,87,16  ; n2165 t=99.863s dur=150ms, freq=1319Hz, sample=87, buffer_id=10:57 [TRUNCATE prev:ch1 @99587.7ms -> 99862.7ms]
    db 0,0,159,0,74,127,17,25,147,2,74,16  ; n2166 t=99.863s dur=159ms, freq=659Hz, sample=74, buffer_id=10:4A [TRUNCATE prev:ch25 @99680.8ms -> 99862.7ms]
    db 0,0,159,0,66,127,18,26,74,1,66,18  ; n2167 t=99.863s dur=159ms, freq=330Hz, sample=66, buffer_id=12:42 [TRUNCATE prev:ch26 @99680.8ms -> 99862.7ms]
    db 0,0,159,0,42,127,19,27,92,0,42,19  ; n2168 t=99.863s dur=159ms, freq=92Hz, sample=42, buffer_id=13:2A [TRUNCATE prev:ch27 @99680.8ms -> 99862.7ms]
    db 44,0,159,0,30,127,20,29,46,0,30,20  ; n2169 t=99.863s dur=159ms, freq=46Hz, sample=30, buffer_id=14:1E [TRUNCATE prev:ch29 @99680.8ms -> 99862.7ms]
    db 79,0,100,0,47,127,10,3,123,0,47,10  ; n2170 t=99.907s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F [TRUNCATE prev:ch3 @99667.2ms -> 99906.6ms]
    db 58,0,100,0,47,127,10,16,123,0,47,10  ; n2171 t=99.986s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 0,0,192,2,59,127,7,2,247,0,59,7  ; n2172 t=100.044s dur=704ms, freq=247Hz, sample=59, buffer_id=07:3B
    db 0,0,192,2,71,127,7,5,238,1,71,7  ; n2173 t=100.044s dur=704ms, freq=494Hz, sample=71, buffer_id=07:47
    db 0,0,100,0,47,127,12,17,123,0,47,11  ; n2174 t=100.044s dur=100ms, freq=123Hz, sample=47, buffer_id=0B:2F
    db 0,0,100,0,35,127,13,18,62,0,35,13  ; n2175 t=100.044s dur=100ms, freq=62Hz, sample=35, buffer_id=0D:23
    db 0,0,159,0,90,127,16,20,200,5,90,16  ; n2176 t=100.044s dur=159ms, freq=1480Hz, sample=90, buffer_id=10:5A
    db 0,0,159,0,78,127,17,23,228,2,78,16  ; n2177 t=100.044s dur=159ms, freq=740Hz, sample=78, buffer_id=10:4E
    db 0,0,159,0,66,127,18,24,114,1,66,18  ; n2178 t=100.044s dur=159ms, freq=370Hz, sample=66, buffer_id=12:42
    db 0,0,159,0,47,127,19,28,123,0,47,19  ; n2179 t=100.044s dur=159ms, freq=123Hz, sample=47, buffer_id=13:2F [TRUNCATE prev:ch28 @99746.0ms -> 100044.5ms]
    db 20,0,159,0,35,127,20,0,62,0,35,20  ; n2180 t=100.044s dur=159ms, freq=62Hz, sample=35, buffer_id=14:23 [TRUNCATE prev:ch0 @99771.7ms -> 100044.5ms]
    db 79,0,100,0,47,127,10,22,123,0,47,10  ; n2181 t=100.064s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F [TRUNCATE prev:ch22 @99827.0ms -> 100064.2ms]
    db 80,0,100,0,47,127,10,4,123,0,47,10  ; n2182 t=100.144s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 2,0,100,0,47,127,10,1,123,0,47,10  ; n2183 t=100.224s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 0,0,159,0,86,127,16,3,151,4,86,16  ; n2184 t=100.226s dur=159ms, freq=1175Hz, sample=86, buffer_id=10:56
    db 0,0,159,0,74,127,17,6,75,2,74,16  ; n2185 t=100.226s dur=159ms, freq=587Hz, sample=74, buffer_id=10:4A
    db 0,0,159,0,66,127,18,13,38,1,66,18  ; n2186 t=100.226s dur=159ms, freq=294Hz, sample=66, buffer_id=12:42
    db 0,0,159,0,47,127,19,14,110,0,47,19  ; n2187 t=100.226s dur=159ms, freq=110Hz, sample=47, buffer_id=13:2F
    db 78,0,159,0,33,127,20,21,55,0,33,20  ; n2188 t=100.226s dur=159ms, freq=55Hz, sample=33, buffer_id=14:21
    db 79,0,100,0,47,127,10,7,123,0,47,10  ; n2189 t=100.304s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 25,0,100,0,47,127,10,8,123,0,47,10  ; n2190 t=100.383s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 0,0,113,0,86,127,2,0,151,4,86,2  ; n2191 t=100.408s dur=113ms, freq=1175Hz, sample=86, buffer_id=02:56
    db 0,0,113,0,90,127,2,9,200,5,90,2  ; n2192 t=100.408s dur=113ms, freq=1480Hz, sample=90, buffer_id=02:5A
    db 0,0,113,0,74,127,3,10,75,2,74,3  ; n2193 t=100.408s dur=113ms, freq=587Hz, sample=74, buffer_id=03:4A
    db 0,0,113,0,78,127,3,11,228,2,78,3  ; n2194 t=100.408s dur=113ms, freq=740Hz, sample=78, buffer_id=03:4E
    db 0,0,113,0,74,127,4,12,75,2,74,4  ; n2195 t=100.408s dur=113ms, freq=587Hz, sample=74, buffer_id=04:4A
    db 0,0,113,0,78,127,4,15,228,2,78,4  ; n2196 t=100.408s dur=113ms, freq=740Hz, sample=78, buffer_id=04:4E
    db 0,0,113,0,66,127,5,16,114,1,66,5  ; n2197 t=100.408s dur=113ms, freq=370Hz, sample=66, buffer_id=05:42
    db 0,0,113,0,62,127,6,17,38,1,62,5  ; n2198 t=100.408s dur=113ms, freq=294Hz, sample=62, buffer_id=05:3E
    db 0,0,100,0,66,127,9,18,114,1,66,9  ; n2199 t=100.408s dur=100ms, freq=370Hz, sample=66, buffer_id=09:42
    db 0,0,100,0,78,127,9,19,228,2,78,9  ; n2200 t=100.408s dur=100ms, freq=740Hz, sample=78, buffer_id=09:4E
    db 0,0,100,0,59,127,11,20,247,0,59,11  ; n2201 t=100.408s dur=100ms, freq=247Hz, sample=59, buffer_id=0B:3B
    db 0,0,100,0,62,127,11,22,38,1,62,11  ; n2202 t=100.408s dur=100ms, freq=294Hz, sample=62, buffer_id=0B:3E
    db 0,0,100,0,54,127,12,23,185,0,54,11  ; n2203 t=100.408s dur=100ms, freq=185Hz, sample=54, buffer_id=0B:36
    db 0,0,159,0,90,127,16,24,200,5,90,16  ; n2204 t=100.408s dur=159ms, freq=1480Hz, sample=90, buffer_id=10:5A
    db 0,0,159,0,78,127,17,25,228,2,78,16  ; n2205 t=100.408s dur=159ms, freq=740Hz, sample=78, buffer_id=10:4E
    db 0,0,159,0,66,127,18,27,114,1,66,18  ; n2206 t=100.408s dur=159ms, freq=370Hz, sample=66, buffer_id=12:42
    db 0,0,159,0,42,127,19,26,98,0,42,19  ; n2207 t=100.408s dur=159ms, freq=98Hz, sample=42, buffer_id=13:2A
    db 55,0,159,0,30,127,20,28,49,0,30,20  ; n2208 t=100.408s dur=159ms, freq=49Hz, sample=30, buffer_id=14:1E
    db 36,0,100,0,47,127,10,29,123,0,47,10  ; n2209 t=100.463s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 0,0,113,0,85,127,2,4,85,4,85,2  ; n2210 t=100.499s dur=113ms, freq=1109Hz, sample=85, buffer_id=02:55
    db 0,0,113,0,90,127,2,30,117,5,90,2  ; n2211 t=100.499s dur=113ms, freq=1397Hz, sample=90, buffer_id=02:5A
    db 0,0,113,0,73,127,3,31,42,2,73,3  ; n2212 t=100.499s dur=113ms, freq=554Hz, sample=73, buffer_id=03:49
    db 0,0,113,0,78,127,3,2,186,2,78,3  ; n2213 t=100.499s dur=113ms, freq=698Hz, sample=78, buffer_id=03:4E [TRUNCATE prev:ch2 @100044.5ms -> 100499.0ms]
    db 0,0,113,0,73,127,4,5,42,2,73,4  ; n2214 t=100.499s dur=113ms, freq=554Hz, sample=73, buffer_id=04:49 [TRUNCATE prev:ch5 @100044.5ms -> 100499.0ms]
    db 0,0,113,0,78,127,4,1,186,2,78,4  ; n2215 t=100.499s dur=113ms, freq=698Hz, sample=78, buffer_id=04:4E [TRUNCATE prev:ch1 @100224.0ms -> 100499.0ms]
    db 0,0,113,0,66,127,5,3,93,1,66,5  ; n2216 t=100.499s dur=113ms, freq=349Hz, sample=66, buffer_id=05:42 [TRUNCATE prev:ch3 @100226.3ms -> 100499.0ms]
    db 43,0,113,0,61,127,6,6,21,1,61,5  ; n2217 t=100.499s dur=113ms, freq=277Hz, sample=61, buffer_id=05:3D [TRUNCATE prev:ch6 @100226.3ms -> 100499.0ms]
    db 48,0,100,0,47,127,10,7,123,0,47,10  ; n2218 t=100.542s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F [TRUNCATE prev:ch7 @100304.3ms -> 100542.2ms]
    db 0,0,181,0,86,127,2,13,151,4,86,2  ; n2219 t=100.590s dur=181ms, freq=1175Hz, sample=86, buffer_id=02:56
    db 0,0,181,0,90,127,2,14,200,5,90,2  ; n2220 t=100.590s dur=181ms, freq=1480Hz, sample=90, buffer_id=02:5A
    db 0,0,181,0,74,127,3,21,75,2,74,3  ; n2221 t=100.590s dur=181ms, freq=587Hz, sample=74, buffer_id=03:4A
    db 0,0,181,0,78,127,3,11,228,2,78,3  ; n2222 t=100.590s dur=181ms, freq=740Hz, sample=78, buffer_id=03:4E [TRUNCATE prev:ch11 @100408.1ms -> 100589.9ms]
    db 0,0,181,0,74,127,4,12,75,2,74,4  ; n2223 t=100.590s dur=181ms, freq=587Hz, sample=74, buffer_id=04:4A [TRUNCATE prev:ch12 @100408.1ms -> 100589.9ms]
    db 0,0,181,0,78,127,4,15,228,2,78,4  ; n2224 t=100.590s dur=181ms, freq=740Hz, sample=78, buffer_id=04:4E [TRUNCATE prev:ch15 @100408.1ms -> 100589.9ms]
    db 0,0,181,0,66,127,5,16,114,1,66,5  ; n2225 t=100.590s dur=181ms, freq=370Hz, sample=66, buffer_id=05:42 [TRUNCATE prev:ch16 @100408.1ms -> 100589.9ms]
    db 0,0,181,0,62,127,6,17,38,1,62,5  ; n2226 t=100.590s dur=181ms, freq=294Hz, sample=62, buffer_id=05:3E [TRUNCATE prev:ch17 @100408.1ms -> 100589.9ms]
    db 0,0,159,0,97,127,16,8,184,7,97,16  ; n2227 t=100.590s dur=159ms, freq=1976Hz, sample=97, buffer_id=10:61 [TRUNCATE prev:ch8 @100383.1ms -> 100589.9ms]
    db 0,0,159,0,85,127,17,0,220,3,85,16  ; n2228 t=100.590s dur=159ms, freq=988Hz, sample=85, buffer_id=10:55 [TRUNCATE prev:ch0 @100408.1ms -> 100589.9ms]
    db 0,0,159,0,73,127,18,9,238,1,73,18  ; n2229 t=100.590s dur=159ms, freq=494Hz, sample=73, buffer_id=12:49 [TRUNCATE prev:ch9 @100408.1ms -> 100589.9ms]
    db 0,0,159,0,42,127,19,26,92,0,42,19  ; n2230 t=100.590s dur=159ms, freq=92Hz, sample=42, buffer_id=13:2A [TRUNCATE prev:ch26 @100408.1ms -> 100589.9ms]
    db 182,0,159,0,30,127,20,28,46,0,30,20  ; n2231 t=100.590s dur=159ms, freq=46Hz, sample=30, buffer_id=14:1E [TRUNCATE prev:ch28 @100408.1ms -> 100589.9ms]
    db 0,0,120,0,62,127,7,10,38,1,62,7  ; n2232 t=100.772s dur=120ms, freq=294Hz, sample=62, buffer_id=07:3E
    db 0,0,100,0,68,127,7,18,184,1,68,7  ; n2233 t=100.772s dur=100ms, freq=440Hz, sample=68, buffer_id=07:44
    db 0,0,100,0,50,127,12,19,147,0,50,11  ; n2234 t=100.772s dur=100ms, freq=147Hz, sample=50, buffer_id=0B:32
    db 0,0,100,0,35,127,13,20,73,0,35,13  ; n2235 t=100.772s dur=100ms, freq=73Hz, sample=35, buffer_id=0D:23
    db 0,0,159,0,90,127,16,22,224,6,90,16  ; n2236 t=100.772s dur=159ms, freq=1760Hz, sample=90, buffer_id=10:5A
    db 0,0,159,0,78,127,17,23,112,3,78,16  ; n2237 t=100.772s dur=159ms, freq=880Hz, sample=78, buffer_id=10:4E
    db 0,0,159,0,66,127,18,24,184,1,66,18  ; n2238 t=100.772s dur=159ms, freq=440Hz, sample=66, buffer_id=12:42
    db 0,0,159,0,47,127,19,25,147,0,47,19  ; n2239 t=100.772s dur=159ms, freq=147Hz, sample=47, buffer_id=13:2F
    db 8,0,159,0,35,127,20,27,73,0,35,20  ; n2240 t=100.772s dur=159ms, freq=73Hz, sample=35, buffer_id=14:23
    db 79,0,100,0,42,127,10,29,92,0,42,10  ; n2241 t=100.780s dur=100ms, freq=92Hz, sample=42, buffer_id=0A:2A
    db 80,0,100,0,42,127,10,1,92,0,42,10  ; n2242 t=100.860s dur=100ms, freq=92Hz, sample=42, buffer_id=0A:2A
    db 14,0,100,0,42,127,10,2,92,0,42,10  ; n2243 t=100.940s dur=100ms, freq=92Hz, sample=42, buffer_id=0A:2A
    db 0,0,159,0,90,127,16,0,200,5,90,16  ; n2244 t=100.954s dur=159ms, freq=1480Hz, sample=90, buffer_id=10:5A
    db 0,0,159,0,78,127,17,3,228,2,78,16  ; n2245 t=100.954s dur=159ms, freq=740Hz, sample=78, buffer_id=10:4E
    db 0,0,159,0,66,127,18,4,114,1,66,18  ; n2246 t=100.954s dur=159ms, freq=370Hz, sample=66, buffer_id=12:42
    db 0,0,159,0,47,127,19,5,139,0,47,19  ; n2247 t=100.954s dur=159ms, freq=139Hz, sample=47, buffer_id=13:2F
    db 66,0,159,0,35,127,20,6,69,0,35,20  ; n2248 t=100.954s dur=159ms, freq=69Hz, sample=35, buffer_id=14:23
    db 80,0,100,0,42,127,10,7,92,0,42,10  ; n2249 t=101.019s dur=100ms, freq=92Hz, sample=42, buffer_id=0A:2A
    db 36,0,100,0,42,127,10,8,92,0,42,10  ; n2250 t=101.099s dur=100ms, freq=92Hz, sample=42, buffer_id=0A:2A
    db 0,0,113,0,90,127,2,9,200,5,90,2  ; n2251 t=101.135s dur=113ms, freq=1480Hz, sample=90, buffer_id=02:5A
    db 0,0,113,0,94,127,2,10,224,6,94,2  ; n2252 t=101.135s dur=113ms, freq=1760Hz, sample=94, buffer_id=02:5E
    db 0,0,113,0,78,127,3,12,228,2,78,3  ; n2253 t=101.135s dur=113ms, freq=740Hz, sample=78, buffer_id=03:4E
    db 0,0,113,0,78,127,3,13,112,3,78,3  ; n2254 t=101.135s dur=113ms, freq=880Hz, sample=78, buffer_id=03:4E
    db 0,0,113,0,78,127,4,11,228,2,78,4  ; n2255 t=101.135s dur=113ms, freq=740Hz, sample=78, buffer_id=04:4E
    db 0,0,113,0,81,127,4,14,112,3,81,4  ; n2256 t=101.135s dur=113ms, freq=880Hz, sample=81, buffer_id=04:51
    db 0,0,113,0,70,127,5,15,184,1,70,5  ; n2257 t=101.135s dur=113ms, freq=440Hz, sample=70, buffer_id=05:46
    db 0,0,113,0,66,127,6,17,114,1,66,5  ; n2258 t=101.135s dur=113ms, freq=370Hz, sample=66, buffer_id=05:42
    db 0,0,100,0,66,127,9,16,114,1,66,9  ; n2259 t=101.135s dur=100ms, freq=370Hz, sample=66, buffer_id=09:42
    db 0,0,100,0,78,127,9,18,228,2,78,9  ; n2260 t=101.135s dur=100ms, freq=740Hz, sample=78, buffer_id=09:4E
    db 0,0,100,0,58,127,11,19,220,0,58,11  ; n2261 t=101.135s dur=100ms, freq=220Hz, sample=58, buffer_id=0B:3A
    db 0,0,100,0,62,127,11,20,38,1,62,11  ; n2262 t=101.135s dur=100ms, freq=294Hz, sample=62, buffer_id=0B:3E
    db 0,0,100,0,54,127,12,21,185,0,54,11  ; n2263 t=101.135s dur=100ms, freq=185Hz, sample=54, buffer_id=0B:36
    db 0,0,159,0,86,127,16,22,151,4,86,16  ; n2264 t=101.135s dur=159ms, freq=1175Hz, sample=86, buffer_id=10:56
    db 0,0,159,0,74,127,17,23,75,2,74,16  ; n2265 t=101.135s dur=159ms, freq=587Hz, sample=74, buffer_id=10:4A
    db 0,0,159,0,66,127,18,25,38,1,66,18  ; n2266 t=101.135s dur=159ms, freq=294Hz, sample=66, buffer_id=12:42
    db 0,0,159,0,47,127,19,24,123,0,47,19  ; n2267 t=101.135s dur=159ms, freq=123Hz, sample=47, buffer_id=13:2F
    db 44,0,159,0,35,127,20,26,62,0,35,20  ; n2268 t=101.135s dur=159ms, freq=62Hz, sample=35, buffer_id=14:23
    db 47,0,100,0,42,127,10,27,92,0,42,10  ; n2269 t=101.179s dur=100ms, freq=92Hz, sample=42, buffer_id=0A:2A
    db 0,0,113,0,90,127,2,1,117,5,90,2  ; n2270 t=101.226s dur=113ms, freq=1397Hz, sample=90, buffer_id=02:5A
    db 0,0,113,0,90,127,2,28,125,6,90,2  ; n2271 t=101.226s dur=113ms, freq=1661Hz, sample=90, buffer_id=02:5A
    db 0,0,113,0,78,127,3,29,186,2,78,3  ; n2272 t=101.226s dur=113ms, freq=698Hz, sample=78, buffer_id=03:4E
    db 0,0,113,0,78,127,3,30,63,3,78,3  ; n2273 t=101.226s dur=113ms, freq=831Hz, sample=78, buffer_id=03:4E
    db 0,0,113,0,78,127,4,31,186,2,78,4  ; n2274 t=101.226s dur=113ms, freq=698Hz, sample=78, buffer_id=04:4E
    db 0,0,113,0,81,127,4,2,63,3,81,4  ; n2275 t=101.226s dur=113ms, freq=831Hz, sample=81, buffer_id=04:51 [TRUNCATE prev:ch2 @100939.9ms -> 101226.3ms]
    db 0,0,113,0,66,127,5,0,159,1,66,5  ; n2276 t=101.226s dur=113ms, freq=415Hz, sample=66, buffer_id=05:42 [TRUNCATE prev:ch0 @100953.6ms -> 101226.3ms]
    db 32,0,113,0,66,127,6,3,93,1,66,5  ; n2277 t=101.226s dur=113ms, freq=349Hz, sample=66, buffer_id=05:42 [TRUNCATE prev:ch3 @100953.6ms -> 101226.3ms]
    db 59,0,100,0,42,127,10,7,92,0,42,10  ; n2278 t=101.258s dur=100ms, freq=92Hz, sample=42, buffer_id=0A:2A [TRUNCATE prev:ch7 @101019.5ms -> 101258.1ms]
    db 0,0,181,0,90,127,2,4,200,5,90,2  ; n2279 t=101.317s dur=181ms, freq=1480Hz, sample=90, buffer_id=02:5A
    db 0,0,181,0,94,127,2,5,224,6,94,2  ; n2280 t=101.317s dur=181ms, freq=1760Hz, sample=94, buffer_id=02:5E
    db 0,0,181,0,78,127,3,6,228,2,78,3  ; n2281 t=101.317s dur=181ms, freq=740Hz, sample=78, buffer_id=03:4E
    db 0,0,181,0,78,127,3,12,112,3,78,3  ; n2282 t=101.317s dur=181ms, freq=880Hz, sample=78, buffer_id=03:4E [TRUNCATE prev:ch12 @101135.4ms -> 101317.2ms]
    db 0,0,181,0,78,127,4,11,228,2,78,4  ; n2283 t=101.317s dur=181ms, freq=740Hz, sample=78, buffer_id=04:4E [TRUNCATE prev:ch11 @101135.4ms -> 101317.2ms]
    db 0,0,181,0,81,127,4,14,112,3,81,4  ; n2284 t=101.317s dur=181ms, freq=880Hz, sample=81, buffer_id=04:51 [TRUNCATE prev:ch14 @101135.4ms -> 101317.2ms]
    db 0,0,181,0,70,127,5,15,184,1,70,5  ; n2285 t=101.317s dur=181ms, freq=440Hz, sample=70, buffer_id=05:46 [TRUNCATE prev:ch15 @101135.4ms -> 101317.2ms]
    db 0,0,181,0,66,127,6,17,114,1,66,5  ; n2286 t=101.317s dur=181ms, freq=370Hz, sample=66, buffer_id=05:42 [TRUNCATE prev:ch17 @101135.4ms -> 101317.2ms]
    db 0,0,159,0,90,127,16,8,200,5,90,16  ; n2287 t=101.317s dur=159ms, freq=1480Hz, sample=90, buffer_id=10:5A [TRUNCATE prev:ch8 @101099.0ms -> 101317.2ms]
    db 0,0,159,0,78,127,17,9,228,2,78,16  ; n2288 t=101.317s dur=159ms, freq=740Hz, sample=78, buffer_id=10:4E [TRUNCATE prev:ch9 @101135.4ms -> 101317.2ms]
    db 0,0,159,0,66,127,18,25,114,1,66,18  ; n2289 t=101.317s dur=159ms, freq=370Hz, sample=66, buffer_id=12:42 [TRUNCATE prev:ch25 @101135.4ms -> 101317.2ms]
    db 0,0,159,0,47,127,19,24,110,0,47,19  ; n2290 t=101.317s dur=159ms, freq=110Hz, sample=47, buffer_id=13:2F [TRUNCATE prev:ch24 @101135.4ms -> 101317.2ms]
    db 20,0,159,0,33,127,20,10,55,0,33,20  ; n2291 t=101.317s dur=159ms, freq=55Hz, sample=33, buffer_id=14:21 [TRUNCATE prev:ch10 @101135.4ms -> 101317.2ms]
    db 159,0,100,0,42,127,10,27,92,0,42,10  ; n2292 t=101.338s dur=100ms, freq=92Hz, sample=42, buffer_id=0A:2A [TRUNCATE prev:ch27 @101179.3ms -> 101337.7ms]
    db 2,0,84,1,42,127,10,13,92,0,42,10  ; n2293 t=101.497s dur=340ms, freq=92Hz, sample=42, buffer_id=0A:2A
    db 0,0,120,0,62,127,7,16,38,1,62,7  ; n2294 t=101.499s dur=120ms, freq=294Hz, sample=62, buffer_id=07:3E
    db 0,0,100,0,68,127,7,18,184,1,68,7  ; n2295 t=101.499s dur=100ms, freq=440Hz, sample=68, buffer_id=07:44
    db 0,0,100,0,50,127,12,19,147,0,50,11  ; n2296 t=101.499s dur=100ms, freq=147Hz, sample=50, buffer_id=0B:32
    db 0,0,100,0,35,127,13,20,73,0,35,13  ; n2297 t=101.499s dur=100ms, freq=73Hz, sample=35, buffer_id=0D:23
    db 0,0,100,0,90,127,16,21,224,6,90,16  ; n2298 t=101.499s dur=100ms, freq=1760Hz, sample=90, buffer_id=10:5A
    db 0,0,100,0,78,127,17,22,112,3,78,16  ; n2299 t=101.499s dur=100ms, freq=880Hz, sample=78, buffer_id=10:4E
    db 0,0,100,0,66,127,18,23,184,1,66,18  ; n2300 t=101.499s dur=100ms, freq=440Hz, sample=66, buffer_id=12:42
    db 0,0,159,0,47,127,19,26,147,0,47,19  ; n2301 t=101.499s dur=159ms, freq=147Hz, sample=47, buffer_id=13:2F
    db 91,0,159,0,35,127,20,0,73,0,35,20  ; n2302 t=101.499s dur=159ms, freq=73Hz, sample=35, buffer_id=14:23 [TRUNCATE prev:ch0 @101226.3ms -> 101499.0ms]
    db 0,0,100,0,90,127,16,1,224,6,90,16  ; n2303 t=101.590s dur=100ms, freq=1760Hz, sample=90, buffer_id=10:5A
    db 0,0,100,0,78,127,17,2,112,3,78,16  ; n2304 t=101.590s dur=100ms, freq=880Hz, sample=78, buffer_id=10:4E
    db 91,0,100,0,66,127,18,3,184,1,66,18  ; n2305 t=101.590s dur=100ms, freq=440Hz, sample=66, buffer_id=12:42
    db 0,0,100,0,90,127,16,7,224,6,90,16  ; n2306 t=101.681s dur=100ms, freq=1760Hz, sample=90, buffer_id=10:5A
    db 0,0,100,0,78,127,17,8,112,3,78,16  ; n2307 t=101.681s dur=100ms, freq=880Hz, sample=78, buffer_id=10:4E
    db 0,0,100,0,66,127,18,9,184,1,66,18  ; n2308 t=101.681s dur=100ms, freq=440Hz, sample=66, buffer_id=12:42
    db 0,0,159,0,47,127,19,10,139,0,47,19  ; n2309 t=101.681s dur=159ms, freq=139Hz, sample=47, buffer_id=13:2F
    db 91,0,159,0,35,127,20,24,69,0,35,20  ; n2310 t=101.681s dur=159ms, freq=69Hz, sample=35, buffer_id=14:23
    db 0,0,100,0,90,127,16,4,224,6,90,16  ; n2311 t=101.772s dur=100ms, freq=1760Hz, sample=90, buffer_id=10:5A
    db 0,0,100,0,78,127,17,5,112,3,78,16  ; n2312 t=101.772s dur=100ms, freq=880Hz, sample=78, buffer_id=10:4E
    db 91,0,100,0,66,127,18,6,184,1,66,18  ; n2313 t=101.772s dur=100ms, freq=440Hz, sample=66, buffer_id=12:42
    db 0,0,113,0,90,127,2,0,200,5,90,2  ; n2314 t=101.863s dur=113ms, freq=1480Hz, sample=90, buffer_id=02:5A
    db 0,0,113,0,94,127,2,11,224,6,94,2  ; n2315 t=101.863s dur=113ms, freq=1760Hz, sample=94, buffer_id=02:5E
    db 0,0,113,0,78,127,3,14,228,2,78,3  ; n2316 t=101.863s dur=113ms, freq=740Hz, sample=78, buffer_id=03:4E
    db 0,0,113,0,78,127,3,15,112,3,78,3  ; n2317 t=101.863s dur=113ms, freq=880Hz, sample=78, buffer_id=03:4E
    db 0,0,113,0,78,127,4,12,228,2,78,4  ; n2318 t=101.863s dur=113ms, freq=740Hz, sample=78, buffer_id=04:4E
    db 0,0,113,0,81,127,4,16,112,3,81,4  ; n2319 t=101.863s dur=113ms, freq=880Hz, sample=81, buffer_id=04:51
    db 0,0,113,0,70,127,5,17,184,1,70,5  ; n2320 t=101.863s dur=113ms, freq=440Hz, sample=70, buffer_id=05:46
    db 0,0,113,0,66,127,6,18,114,1,66,5  ; n2321 t=101.863s dur=113ms, freq=370Hz, sample=66, buffer_id=05:42
    db 0,0,100,0,66,127,9,19,114,1,66,9  ; n2322 t=101.863s dur=100ms, freq=370Hz, sample=66, buffer_id=09:42
    db 0,0,100,0,78,127,9,20,228,2,78,9  ; n2323 t=101.863s dur=100ms, freq=740Hz, sample=78, buffer_id=09:4E
    db 0,0,100,0,58,127,11,21,220,0,58,11  ; n2324 t=101.863s dur=100ms, freq=220Hz, sample=58, buffer_id=0B:3A
    db 0,0,100,0,62,127,11,22,38,1,62,11  ; n2325 t=101.863s dur=100ms, freq=294Hz, sample=62, buffer_id=0B:3E
    db 0,0,100,0,54,127,12,23,185,0,54,11  ; n2326 t=101.863s dur=100ms, freq=185Hz, sample=54, buffer_id=0B:36
    db 0,0,100,0,90,127,16,25,224,6,90,16  ; n2327 t=101.863s dur=100ms, freq=1760Hz, sample=90, buffer_id=10:5A
    db 0,0,100,0,78,127,17,26,112,3,78,16  ; n2328 t=101.863s dur=100ms, freq=880Hz, sample=78, buffer_id=10:4E
    db 0,0,100,0,66,127,18,27,184,1,66,18  ; n2329 t=101.863s dur=100ms, freq=440Hz, sample=66, buffer_id=12:42
    db 0,0,159,0,47,127,19,28,123,0,47,19  ; n2330 t=101.863s dur=159ms, freq=123Hz, sample=47, buffer_id=13:2F
    db 91,0,159,0,35,127,20,29,62,0,35,20  ; n2331 t=101.863s dur=159ms, freq=62Hz, sample=35, buffer_id=14:23
    db 0,0,113,0,90,127,2,1,117,5,90,2  ; n2332 t=101.954s dur=113ms, freq=1397Hz, sample=90, buffer_id=02:5A
    db 0,0,113,0,90,127,2,2,125,6,90,2  ; n2333 t=101.954s dur=113ms, freq=1661Hz, sample=90, buffer_id=02:5A
    db 0,0,113,0,78,127,3,3,186,2,78,3  ; n2334 t=101.954s dur=113ms, freq=698Hz, sample=78, buffer_id=03:4E
    db 0,0,113,0,78,127,3,31,63,3,78,3  ; n2335 t=101.954s dur=113ms, freq=831Hz, sample=78, buffer_id=03:4E
    db 0,0,113,0,78,127,4,30,186,2,78,4  ; n2336 t=101.954s dur=113ms, freq=698Hz, sample=78, buffer_id=04:4E
    db 0,0,113,0,81,127,4,13,63,3,81,4  ; n2337 t=101.954s dur=113ms, freq=831Hz, sample=81, buffer_id=04:51 [TRUNCATE prev:ch13 @101496.7ms -> 101953.6ms]
    db 0,0,113,0,66,127,5,7,159,1,66,5  ; n2338 t=101.954s dur=113ms, freq=415Hz, sample=66, buffer_id=05:42 [TRUNCATE prev:ch7 @101680.8ms -> 101953.6ms]
    db 0,0,113,0,66,127,6,8,93,1,66,5  ; n2339 t=101.954s dur=113ms, freq=349Hz, sample=66, buffer_id=05:42 [TRUNCATE prev:ch8 @101680.8ms -> 101953.6ms]
    db 0,0,100,0,90,127,16,4,224,6,90,16  ; n2340 t=101.954s dur=100ms, freq=1760Hz, sample=90, buffer_id=10:5A [TRUNCATE prev:ch4 @101771.7ms -> 101953.6ms]
    db 0,0,100,0,78,127,17,5,112,3,78,16  ; n2341 t=101.954s dur=100ms, freq=880Hz, sample=78, buffer_id=10:4E [TRUNCATE prev:ch5 @101771.7ms -> 101953.6ms]
    db 91,0,100,0,66,127,18,9,184,1,66,18  ; n2342 t=101.954s dur=100ms, freq=440Hz, sample=66, buffer_id=12:42 [TRUNCATE prev:ch9 @101680.8ms -> 101953.6ms]
    db 0,0,181,0,90,127,2,10,200,5,90,2  ; n2343 t=102.044s dur=181ms, freq=1480Hz, sample=90, buffer_id=02:5A
    db 0,0,181,0,94,127,2,24,224,6,94,2  ; n2344 t=102.044s dur=181ms, freq=1760Hz, sample=94, buffer_id=02:5E
    db 0,0,181,0,78,127,3,14,228,2,78,3  ; n2345 t=102.044s dur=181ms, freq=740Hz, sample=78, buffer_id=03:4E [TRUNCATE prev:ch14 @101862.6ms -> 102044.5ms]
    db 0,0,181,0,78,127,3,15,112,3,78,3  ; n2346 t=102.044s dur=181ms, freq=880Hz, sample=78, buffer_id=03:4E [TRUNCATE prev:ch15 @101862.6ms -> 102044.5ms]
    db 0,0,181,0,78,127,4,12,228,2,78,4  ; n2347 t=102.044s dur=181ms, freq=740Hz, sample=78, buffer_id=04:4E [TRUNCATE prev:ch12 @101862.6ms -> 102044.5ms]
    db 0,0,181,0,81,127,4,16,112,3,81,4  ; n2348 t=102.044s dur=181ms, freq=880Hz, sample=81, buffer_id=04:51 [TRUNCATE prev:ch16 @101862.6ms -> 102044.5ms]
    db 0,0,181,0,70,127,5,17,184,1,70,5  ; n2349 t=102.044s dur=181ms, freq=440Hz, sample=70, buffer_id=05:46 [TRUNCATE prev:ch17 @101862.6ms -> 102044.5ms]
    db 0,0,181,0,66,127,6,18,114,1,66,5  ; n2350 t=102.044s dur=181ms, freq=370Hz, sample=66, buffer_id=05:42 [TRUNCATE prev:ch18 @101862.6ms -> 102044.5ms]
    db 0,0,100,0,90,127,16,25,224,6,90,16  ; n2351 t=102.044s dur=100ms, freq=1760Hz, sample=90, buffer_id=10:5A [TRUNCATE prev:ch25 @101862.6ms -> 102044.5ms]
    db 0,0,100,0,78,127,17,26,112,3,78,16  ; n2352 t=102.044s dur=100ms, freq=880Hz, sample=78, buffer_id=10:4E [TRUNCATE prev:ch26 @101862.6ms -> 102044.5ms]
    db 0,0,100,0,66,127,18,6,184,1,66,18  ; n2353 t=102.044s dur=100ms, freq=440Hz, sample=66, buffer_id=12:42 [TRUNCATE prev:ch6 @101771.7ms -> 102044.5ms]
    db 0,0,159,0,47,127,19,28,110,0,47,19  ; n2354 t=102.044s dur=159ms, freq=110Hz, sample=47, buffer_id=13:2F [TRUNCATE prev:ch28 @101862.6ms -> 102044.5ms]
    db 91,0,159,0,33,127,20,0,55,0,33,20  ; n2355 t=102.044s dur=159ms, freq=55Hz, sample=33, buffer_id=14:21 [TRUNCATE prev:ch0 @101862.6ms -> 102044.5ms]
    db 0,0,100,0,90,127,16,4,224,6,90,16  ; n2356 t=102.135s dur=100ms, freq=1760Hz, sample=90, buffer_id=10:5A [TRUNCATE prev:ch4 @101953.6ms -> 102135.4ms]
    db 0,0,100,0,78,127,17,5,112,3,78,16  ; n2357 t=102.135s dur=100ms, freq=880Hz, sample=78, buffer_id=10:4E [TRUNCATE prev:ch5 @101953.6ms -> 102135.4ms]
    db 89,0,100,0,66,127,18,27,184,1,66,18  ; n2358 t=102.135s dur=100ms, freq=440Hz, sample=66, buffer_id=12:42 [TRUNCATE prev:ch27 @101862.6ms -> 102135.4ms]
    db 2,0,159,0,47,127,10,11,123,0,47,10  ; n2359 t=102.224s dur=159ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 0,0,192,2,59,127,7,19,247,0,59,7  ; n2360 t=102.226s dur=704ms, freq=247Hz, sample=59, buffer_id=07:3B
    db 0,0,192,2,71,127,7,20,238,1,71,7  ; n2361 t=102.226s dur=704ms, freq=494Hz, sample=71, buffer_id=07:47
    db 0,0,100,0,47,127,12,21,123,0,47,11  ; n2362 t=102.226s dur=100ms, freq=123Hz, sample=47, buffer_id=0B:2F
    db 0,0,100,0,35,127,13,22,62,0,35,13  ; n2363 t=102.226s dur=100ms, freq=62Hz, sample=35, buffer_id=0D:23
    db 0,0,159,0,85,127,16,23,220,3,85,16  ; n2364 t=102.226s dur=159ms, freq=988Hz, sample=85, buffer_id=10:55
    db 0,0,159,0,70,127,17,29,238,1,70,16  ; n2365 t=102.226s dur=159ms, freq=494Hz, sample=70, buffer_id=10:46
    db 0,0,157,0,54,127,18,1,247,0,54,18  ; n2366 t=102.226s dur=157ms, freq=247Hz, sample=54, buffer_id=12:36 [TRUNCATE prev:ch1 @101953.6ms -> 102226.3ms]
    db 0,0,159,0,47,127,19,28,123,0,47,19  ; n2367 t=102.226s dur=159ms, freq=123Hz, sample=47, buffer_id=13:2F [TRUNCATE prev:ch28 @102044.5ms -> 102226.3ms]
    db 180,0,159,0,35,127,20,2,62,0,35,20  ; n2368 t=102.226s dur=159ms, freq=62Hz, sample=35, buffer_id=14:23 [TRUNCATE prev:ch2 @101953.6ms -> 102226.3ms]
    db 2,0,159,0,47,127,10,0,123,0,47,10  ; n2369 t=102.406s dur=159ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 0,0,159,0,85,127,16,3,85,4,85,16  ; n2370 t=102.408s dur=159ms, freq=1109Hz, sample=85, buffer_id=10:55
    db 0,0,159,0,73,127,17,6,42,2,73,16  ; n2371 t=102.408s dur=159ms, freq=554Hz, sample=73, buffer_id=10:49
    db 0,0,159,0,66,127,18,7,21,1,66,18  ; n2372 t=102.408s dur=159ms, freq=277Hz, sample=66, buffer_id=12:42
    db 0,0,159,0,47,127,19,8,110,0,47,19  ; n2373 t=102.408s dur=159ms, freq=110Hz, sample=47, buffer_id=13:2F
    db 179,0,159,0,33,127,20,9,55,0,33,20  ; n2374 t=102.408s dur=159ms, freq=55Hz, sample=33, buffer_id=14:21
    db 2,0,159,0,47,127,10,1,123,0,47,10  ; n2375 t=102.588s dur=159ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 0,0,113,0,86,127,2,2,151,4,86,2  ; n2376 t=102.590s dur=113ms, freq=1175Hz, sample=86, buffer_id=02:56
    db 0,0,113,0,90,127,2,4,200,5,90,2  ; n2377 t=102.590s dur=113ms, freq=1480Hz, sample=90, buffer_id=02:5A
    db 0,0,113,0,74,127,3,5,75,2,74,3  ; n2378 t=102.590s dur=113ms, freq=587Hz, sample=74, buffer_id=03:4A
    db 0,0,113,0,78,127,3,10,228,2,78,3  ; n2379 t=102.590s dur=113ms, freq=740Hz, sample=78, buffer_id=03:4E
    db 0,0,113,0,74,127,4,11,75,2,74,4  ; n2380 t=102.590s dur=113ms, freq=587Hz, sample=74, buffer_id=04:4A
    db 0,0,113,0,78,127,4,13,228,2,78,4  ; n2381 t=102.590s dur=113ms, freq=740Hz, sample=78, buffer_id=04:4E
    db 0,0,113,0,66,127,5,12,114,1,66,5  ; n2382 t=102.590s dur=113ms, freq=370Hz, sample=66, buffer_id=05:42
    db 0,0,113,0,62,127,6,14,38,1,62,5  ; n2383 t=102.590s dur=113ms, freq=294Hz, sample=62, buffer_id=05:3E
    db 0,0,100,0,66,127,9,15,114,1,66,9  ; n2384 t=102.590s dur=100ms, freq=370Hz, sample=66, buffer_id=09:42
    db 0,0,100,0,78,127,9,16,228,2,78,9  ; n2385 t=102.590s dur=100ms, freq=740Hz, sample=78, buffer_id=09:4E
    db 0,0,100,0,62,127,11,17,38,1,62,11  ; n2386 t=102.590s dur=100ms, freq=294Hz, sample=62, buffer_id=0B:3E
    db 0,0,100,0,66,127,11,18,114,1,66,11  ; n2387 t=102.590s dur=100ms, freq=370Hz, sample=66, buffer_id=0B:42
    db 0,0,100,0,54,127,12,21,185,0,54,11  ; n2388 t=102.590s dur=100ms, freq=185Hz, sample=54, buffer_id=0B:36
    db 0,0,159,0,86,127,16,22,151,4,86,16  ; n2389 t=102.590s dur=159ms, freq=1175Hz, sample=86, buffer_id=10:56
    db 0,0,159,0,74,127,17,23,75,2,74,16  ; n2390 t=102.590s dur=159ms, freq=587Hz, sample=74, buffer_id=10:4A
    db 0,0,159,0,66,127,18,24,38,1,66,18  ; n2391 t=102.590s dur=159ms, freq=294Hz, sample=66, buffer_id=12:42
    db 0,0,159,0,42,127,19,25,98,0,42,19  ; n2392 t=102.590s dur=159ms, freq=98Hz, sample=42, buffer_id=13:2A
    db 91,0,159,0,30,127,20,26,49,0,30,20  ; n2393 t=102.590s dur=159ms, freq=49Hz, sample=30, buffer_id=14:1E
    db 0,0,113,0,85,127,2,27,85,4,85,2  ; n2394 t=102.681s dur=113ms, freq=1109Hz, sample=85, buffer_id=02:55
    db 0,0,113,0,90,127,2,28,117,5,90,2  ; n2395 t=102.681s dur=113ms, freq=1397Hz, sample=90, buffer_id=02:5A
    db 0,0,113,0,73,127,3,29,42,2,73,3  ; n2396 t=102.681s dur=113ms, freq=554Hz, sample=73, buffer_id=03:49
    db 0,0,113,0,78,127,3,30,186,2,78,3  ; n2397 t=102.681s dur=113ms, freq=698Hz, sample=78, buffer_id=03:4E
    db 0,0,113,0,73,127,4,31,42,2,73,4  ; n2398 t=102.681s dur=113ms, freq=554Hz, sample=73, buffer_id=04:49
    db 0,0,113,0,78,127,4,19,186,2,78,4  ; n2399 t=102.681s dur=113ms, freq=698Hz, sample=78, buffer_id=04:4E [TRUNCATE prev:ch19 @102226.3ms -> 102680.8ms]
    db 0,0,113,0,66,127,5,20,93,1,66,5  ; n2400 t=102.681s dur=113ms, freq=349Hz, sample=66, buffer_id=05:42 [TRUNCATE prev:ch20 @102226.3ms -> 102680.8ms]
    db 89,0,113,0,61,127,6,0,21,1,61,5  ; n2401 t=102.681s dur=113ms, freq=277Hz, sample=61, buffer_id=05:3D [TRUNCATE prev:ch0 @102405.8ms -> 102680.8ms]
    db 2,0,159,0,47,127,10,3,123,0,47,10  ; n2402 t=102.769s dur=159ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 0,0,181,0,86,127,2,6,151,4,86,2  ; n2403 t=102.772s dur=181ms, freq=1175Hz, sample=86, buffer_id=02:56
    db 0,0,181,0,90,127,2,7,200,5,90,2  ; n2404 t=102.772s dur=181ms, freq=1480Hz, sample=90, buffer_id=02:5A
    db 0,0,181,0,74,127,3,8,75,2,74,3  ; n2405 t=102.772s dur=181ms, freq=587Hz, sample=74, buffer_id=03:4A
    db 0,0,181,0,78,127,3,9,228,2,78,3  ; n2406 t=102.772s dur=181ms, freq=740Hz, sample=78, buffer_id=03:4E
    db 0,0,181,0,74,127,4,11,75,2,74,4  ; n2407 t=102.772s dur=181ms, freq=587Hz, sample=74, buffer_id=04:4A [TRUNCATE prev:ch11 @102589.9ms -> 102771.7ms]
    db 0,0,181,0,78,127,4,13,228,2,78,4  ; n2408 t=102.772s dur=181ms, freq=740Hz, sample=78, buffer_id=04:4E [TRUNCATE prev:ch13 @102589.9ms -> 102771.7ms]
    db 0,0,181,0,66,127,5,12,114,1,66,5  ; n2409 t=102.772s dur=181ms, freq=370Hz, sample=66, buffer_id=05:42 [TRUNCATE prev:ch12 @102589.9ms -> 102771.7ms]
    db 0,0,181,0,62,127,6,14,38,1,62,5  ; n2410 t=102.772s dur=181ms, freq=294Hz, sample=62, buffer_id=05:3E [TRUNCATE prev:ch14 @102589.9ms -> 102771.7ms]
    db 0,0,150,0,87,127,16,1,39,5,87,16  ; n2411 t=102.772s dur=150ms, freq=1319Hz, sample=87, buffer_id=10:57 [TRUNCATE prev:ch1 @102587.6ms -> 102771.7ms]
    db 0,0,159,0,74,127,17,23,147,2,74,16  ; n2412 t=102.772s dur=159ms, freq=659Hz, sample=74, buffer_id=10:4A [TRUNCATE prev:ch23 @102589.9ms -> 102771.7ms]
    db 0,0,159,0,66,127,18,24,74,1,66,18  ; n2413 t=102.772s dur=159ms, freq=330Hz, sample=66, buffer_id=12:42 [TRUNCATE prev:ch24 @102589.9ms -> 102771.7ms]
    db 0,0,159,0,42,127,19,25,92,0,42,19  ; n2414 t=102.772s dur=159ms, freq=92Hz, sample=42, buffer_id=13:2A [TRUNCATE prev:ch25 @102589.9ms -> 102771.7ms]
    db 180,0,159,0,30,127,20,26,46,0,30,20  ; n2415 t=102.772s dur=159ms, freq=46Hz, sample=30, buffer_id=14:1E [TRUNCATE prev:ch26 @102589.9ms -> 102771.7ms]
    db 2,0,159,0,47,127,10,2,123,0,47,10  ; n2416 t=102.951s dur=159ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 0,0,192,2,59,127,7,4,247,0,59,7  ; n2417 t=102.954s dur=704ms, freq=247Hz, sample=59, buffer_id=07:3B
    db 0,0,192,2,71,127,7,5,238,1,71,7  ; n2418 t=102.954s dur=704ms, freq=494Hz, sample=71, buffer_id=07:47
    db 0,0,100,0,47,127,12,10,123,0,47,11  ; n2419 t=102.954s dur=100ms, freq=123Hz, sample=47, buffer_id=0B:2F
    db 0,0,100,0,35,127,13,15,62,0,35,13  ; n2420 t=102.954s dur=100ms, freq=62Hz, sample=35, buffer_id=0D:23
    db 0,0,159,0,90,127,16,16,200,5,90,16  ; n2421 t=102.954s dur=159ms, freq=1480Hz, sample=90, buffer_id=10:5A
    db 0,0,159,0,78,127,17,17,228,2,78,16  ; n2422 t=102.954s dur=159ms, freq=740Hz, sample=78, buffer_id=10:4E
    db 0,0,159,0,66,127,18,18,114,1,66,18  ; n2423 t=102.954s dur=159ms, freq=370Hz, sample=66, buffer_id=12:42
    db 0,0,159,0,47,127,19,21,123,0,47,19  ; n2424 t=102.954s dur=159ms, freq=123Hz, sample=47, buffer_id=13:2F
    db 180,0,159,0,35,127,20,22,62,0,35,20  ; n2425 t=102.954s dur=159ms, freq=62Hz, sample=35, buffer_id=14:23
    db 2,0,159,0,47,127,10,0,123,0,47,10  ; n2426 t=103.133s dur=159ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 0,0,159,0,86,127,16,1,151,4,86,16  ; n2427 t=103.135s dur=159ms, freq=1175Hz, sample=86, buffer_id=10:56
    db 0,0,159,0,74,127,17,3,75,2,74,16  ; n2428 t=103.135s dur=159ms, freq=587Hz, sample=74, buffer_id=10:4A
    db 0,0,159,0,66,127,18,19,38,1,66,18  ; n2429 t=103.135s dur=159ms, freq=294Hz, sample=66, buffer_id=12:42
    db 0,0,159,0,47,127,19,20,110,0,47,19  ; n2430 t=103.135s dur=159ms, freq=110Hz, sample=47, buffer_id=13:2F
    db 179,0,159,0,33,127,20,23,55,0,33,20  ; n2431 t=103.135s dur=159ms, freq=55Hz, sample=33, buffer_id=14:21
    db 2,0,84,1,47,127,10,6,123,0,47,10  ; n2432 t=103.315s dur=340ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 0,0,113,0,86,127,2,2,151,4,86,2  ; n2433 t=103.317s dur=113ms, freq=1175Hz, sample=86, buffer_id=02:56
    db 0,0,113,0,90,127,2,8,200,5,90,2  ; n2434 t=103.317s dur=113ms, freq=1480Hz, sample=90, buffer_id=02:5A
    db 0,0,113,0,74,127,3,7,75,2,74,3  ; n2435 t=103.317s dur=113ms, freq=587Hz, sample=74, buffer_id=03:4A
    db 0,0,113,0,78,127,3,10,228,2,78,3  ; n2436 t=103.317s dur=113ms, freq=740Hz, sample=78, buffer_id=03:4E
    db 0,0,113,0,74,127,4,9,75,2,74,4  ; n2437 t=103.317s dur=113ms, freq=587Hz, sample=74, buffer_id=04:4A
    db 0,0,113,0,78,127,4,11,228,2,78,4  ; n2438 t=103.317s dur=113ms, freq=740Hz, sample=78, buffer_id=04:4E
    db 0,0,113,0,66,127,5,13,114,1,66,5  ; n2439 t=103.317s dur=113ms, freq=370Hz, sample=66, buffer_id=05:42
    db 0,0,113,0,62,127,6,12,38,1,62,5  ; n2440 t=103.317s dur=113ms, freq=294Hz, sample=62, buffer_id=05:3E
    db 0,0,100,0,66,127,9,14,114,1,66,9  ; n2441 t=103.317s dur=100ms, freq=370Hz, sample=66, buffer_id=09:42
    db 0,0,100,0,78,127,9,15,228,2,78,9  ; n2442 t=103.317s dur=100ms, freq=740Hz, sample=78, buffer_id=09:4E
    db 0,0,100,0,62,127,11,16,38,1,62,11  ; n2443 t=103.317s dur=100ms, freq=294Hz, sample=62, buffer_id=0B:3E
    db 0,0,100,0,66,127,11,17,114,1,66,11  ; n2444 t=103.317s dur=100ms, freq=370Hz, sample=66, buffer_id=0B:42
    db 0,0,100,0,54,127,12,18,185,0,54,11  ; n2445 t=103.317s dur=100ms, freq=185Hz, sample=54, buffer_id=0B:36
    db 0,0,100,0,90,127,16,21,200,5,90,16  ; n2446 t=103.317s dur=100ms, freq=1480Hz, sample=90, buffer_id=10:5A
    db 0,0,100,0,78,127,17,22,228,2,78,16  ; n2447 t=103.317s dur=100ms, freq=740Hz, sample=78, buffer_id=10:4E
    db 0,0,100,0,66,127,18,25,114,1,66,18  ; n2448 t=103.317s dur=100ms, freq=370Hz, sample=66, buffer_id=12:42
    db 0,0,159,0,42,127,19,24,98,0,42,19  ; n2449 t=103.317s dur=159ms, freq=98Hz, sample=42, buffer_id=13:2A
    db 91,0,159,0,30,127,20,27,49,0,30,20  ; n2450 t=103.317s dur=159ms, freq=49Hz, sample=30, buffer_id=14:1E
    db 0,0,113,0,85,127,2,26,85,4,85,2  ; n2451 t=103.408s dur=113ms, freq=1109Hz, sample=85, buffer_id=02:55
    db 0,0,113,0,90,127,2,29,117,5,90,2  ; n2452 t=103.408s dur=113ms, freq=1397Hz, sample=90, buffer_id=02:5A
    db 0,0,113,0,73,127,3,28,42,2,73,3  ; n2453 t=103.408s dur=113ms, freq=554Hz, sample=73, buffer_id=03:49
    db 0,0,113,0,78,127,3,31,186,2,78,3  ; n2454 t=103.408s dur=113ms, freq=698Hz, sample=78, buffer_id=03:4E
    db 0,0,113,0,73,127,4,30,42,2,73,4  ; n2455 t=103.408s dur=113ms, freq=554Hz, sample=73, buffer_id=04:49
    db 0,0,113,0,78,127,4,4,186,2,78,4  ; n2456 t=103.408s dur=113ms, freq=698Hz, sample=78, buffer_id=04:4E [TRUNCATE prev:ch4 @102953.6ms -> 103408.1ms]
    db 0,0,113,0,66,127,5,5,93,1,66,5  ; n2457 t=103.408s dur=113ms, freq=349Hz, sample=66, buffer_id=05:42 [TRUNCATE prev:ch5 @102953.6ms -> 103408.1ms]
    db 0,0,113,0,61,127,6,0,21,1,61,5  ; n2458 t=103.408s dur=113ms, freq=277Hz, sample=61, buffer_id=05:3D [TRUNCATE prev:ch0 @103133.1ms -> 103408.1ms]
    db 0,0,100,0,90,127,16,1,200,5,90,16  ; n2459 t=103.408s dur=100ms, freq=1480Hz, sample=90, buffer_id=10:5A [TRUNCATE prev:ch1 @103135.4ms -> 103408.1ms]
    db 0,0,100,0,78,127,17,3,228,2,78,16  ; n2460 t=103.408s dur=100ms, freq=740Hz, sample=78, buffer_id=10:4E [TRUNCATE prev:ch3 @103135.4ms -> 103408.1ms]
    db 91,0,100,0,66,127,18,19,114,1,66,18  ; n2461 t=103.408s dur=100ms, freq=370Hz, sample=66, buffer_id=12:42 [TRUNCATE prev:ch19 @103135.4ms -> 103408.1ms]
    db 0,0,181,0,86,127,2,20,151,4,86,2  ; n2462 t=103.499s dur=181ms, freq=1175Hz, sample=86, buffer_id=02:56
    db 0,0,181,0,90,127,2,23,200,5,90,2  ; n2463 t=103.499s dur=181ms, freq=1480Hz, sample=90, buffer_id=02:5A
    db 0,0,181,0,74,127,3,7,75,2,74,3  ; n2464 t=103.499s dur=181ms, freq=587Hz, sample=74, buffer_id=03:4A [TRUNCATE prev:ch7 @103317.2ms -> 103499.0ms]
    db 0,0,181,0,78,127,3,10,228,2,78,3  ; n2465 t=103.499s dur=181ms, freq=740Hz, sample=78, buffer_id=03:4E [TRUNCATE prev:ch10 @103317.2ms -> 103499.0ms]
    db 0,0,181,0,74,127,4,9,75,2,74,4  ; n2466 t=103.499s dur=181ms, freq=587Hz, sample=74, buffer_id=04:4A [TRUNCATE prev:ch9 @103317.2ms -> 103499.0ms]
    db 0,0,181,0,78,127,4,11,228,2,78,4  ; n2467 t=103.499s dur=181ms, freq=740Hz, sample=78, buffer_id=04:4E [TRUNCATE prev:ch11 @103317.2ms -> 103499.0ms]
    db 0,0,181,0,66,127,5,13,114,1,66,5  ; n2468 t=103.499s dur=181ms, freq=370Hz, sample=66, buffer_id=05:42 [TRUNCATE prev:ch13 @103317.2ms -> 103499.0ms]
    db 0,0,181,0,62,127,6,12,38,1,62,5  ; n2469 t=103.499s dur=181ms, freq=294Hz, sample=62, buffer_id=05:3E [TRUNCATE prev:ch12 @103317.2ms -> 103499.0ms]
    db 0,0,100,0,90,127,16,21,200,5,90,16  ; n2470 t=103.499s dur=100ms, freq=1480Hz, sample=90, buffer_id=10:5A [TRUNCATE prev:ch21 @103317.2ms -> 103499.0ms]
    db 0,0,100,0,78,127,17,22,228,2,78,16  ; n2471 t=103.499s dur=100ms, freq=740Hz, sample=78, buffer_id=10:4E [TRUNCATE prev:ch22 @103317.2ms -> 103499.0ms]
    db 0,0,100,0,66,127,18,25,114,1,66,18  ; n2472 t=103.499s dur=100ms, freq=370Hz, sample=66, buffer_id=12:42 [TRUNCATE prev:ch25 @103317.2ms -> 103499.0ms]
    db 0,0,159,0,42,127,19,24,92,0,42,19  ; n2473 t=103.499s dur=159ms, freq=92Hz, sample=42, buffer_id=13:2A [TRUNCATE prev:ch24 @103317.2ms -> 103499.0ms]
    db 91,0,159,0,30,127,20,27,46,0,30,20  ; n2474 t=103.499s dur=159ms, freq=46Hz, sample=30, buffer_id=14:1E [TRUNCATE prev:ch27 @103317.2ms -> 103499.0ms]
    db 0,0,100,0,90,127,16,1,200,5,90,16  ; n2475 t=103.590s dur=100ms, freq=1480Hz, sample=90, buffer_id=10:5A [TRUNCATE prev:ch1 @103408.1ms -> 103589.9ms]
    db 0,0,100,0,78,127,17,3,228,2,78,16  ; n2476 t=103.590s dur=100ms, freq=740Hz, sample=78, buffer_id=10:4E [TRUNCATE prev:ch3 @103408.1ms -> 103589.9ms]
    db 89,0,100,0,66,127,18,19,114,1,66,18  ; n2477 t=103.590s dur=100ms, freq=370Hz, sample=66, buffer_id=12:42 [TRUNCATE prev:ch19 @103408.1ms -> 103589.9ms]
    db 2,0,159,0,47,127,10,2,123,0,47,10  ; n2478 t=103.679s dur=159ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 0,0,192,2,59,127,7,8,247,0,59,7  ; n2479 t=103.681s dur=704ms, freq=247Hz, sample=59, buffer_id=07:3B
    db 0,0,192,2,71,127,7,14,238,1,71,7  ; n2480 t=103.681s dur=704ms, freq=494Hz, sample=71, buffer_id=07:47
    db 0,0,100,0,47,127,12,15,123,0,47,11  ; n2481 t=103.681s dur=100ms, freq=123Hz, sample=47, buffer_id=0B:2F
    db 0,0,100,0,35,127,13,16,62,0,35,13  ; n2482 t=103.681s dur=100ms, freq=62Hz, sample=35, buffer_id=0D:23
    db 0,0,159,0,90,127,16,17,117,5,90,16  ; n2483 t=103.681s dur=159ms, freq=1397Hz, sample=90, buffer_id=10:5A
    db 0,0,159,0,78,127,17,18,186,2,78,16  ; n2484 t=103.681s dur=159ms, freq=698Hz, sample=78, buffer_id=10:4E
    db 0,0,159,0,66,127,18,25,93,1,66,18  ; n2485 t=103.681s dur=159ms, freq=349Hz, sample=66, buffer_id=12:42 [TRUNCATE prev:ch25 @103499.0ms -> 103680.8ms]
    db 0,0,159,0,47,127,19,6,123,0,47,19  ; n2486 t=103.681s dur=159ms, freq=123Hz, sample=47, buffer_id=13:2F [TRUNCATE prev:ch6 @103314.9ms -> 103680.8ms]
    db 180,0,159,0,35,127,20,0,62,0,35,20  ; n2487 t=103.681s dur=159ms, freq=62Hz, sample=35, buffer_id=14:23 [TRUNCATE prev:ch0 @103408.1ms -> 103680.8ms]
    db 2,0,159,0,47,127,10,4,123,0,47,10  ; n2488 t=103.860s dur=159ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 0,0,159,0,85,127,16,5,85,4,85,16  ; n2489 t=103.863s dur=159ms, freq=1109Hz, sample=85, buffer_id=10:55
    db 0,0,159,0,73,127,17,21,42,2,73,16  ; n2490 t=103.863s dur=159ms, freq=554Hz, sample=73, buffer_id=10:49
    db 0,0,159,0,66,127,18,22,21,1,66,18  ; n2491 t=103.863s dur=159ms, freq=277Hz, sample=66, buffer_id=12:42
    db 0,0,159,0,47,127,19,24,110,0,47,19  ; n2492 t=103.863s dur=159ms, freq=110Hz, sample=47, buffer_id=13:2F
    db 180,0,159,0,33,127,20,26,55,0,33,20  ; n2493 t=103.863s dur=159ms, freq=55Hz, sample=33, buffer_id=14:21
    db 2,0,84,1,47,127,10,0,123,0,47,10  ; n2494 t=104.042s dur=340ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 0,0,113,0,85,127,2,1,85,4,85,2  ; n2495 t=104.044s dur=113ms, freq=1109Hz, sample=85, buffer_id=02:55
    db 0,0,113,0,90,127,2,2,117,5,90,2  ; n2496 t=104.044s dur=113ms, freq=1397Hz, sample=90, buffer_id=02:5A
    db 0,0,113,0,73,127,3,3,42,2,73,3  ; n2497 t=104.044s dur=113ms, freq=554Hz, sample=73, buffer_id=03:49
    db 0,0,113,0,78,127,3,6,186,2,78,3  ; n2498 t=104.044s dur=113ms, freq=698Hz, sample=78, buffer_id=03:4E
    db 0,0,113,0,73,127,4,7,42,2,73,4  ; n2499 t=104.044s dur=113ms, freq=554Hz, sample=73, buffer_id=04:49
    db 0,0,113,0,78,127,4,9,186,2,78,4  ; n2500 t=104.044s dur=113ms, freq=698Hz, sample=78, buffer_id=04:4E
    db 0,0,113,0,66,127,5,10,93,1,66,5  ; n2501 t=104.044s dur=113ms, freq=349Hz, sample=66, buffer_id=05:42
    db 0,0,113,0,61,127,6,11,21,1,61,5  ; n2502 t=104.044s dur=113ms, freq=277Hz, sample=61, buffer_id=05:3D
    db 0,0,100,0,66,127,9,12,114,1,66,9  ; n2503 t=104.044s dur=100ms, freq=370Hz, sample=66, buffer_id=09:42
    db 0,0,100,0,78,127,9,13,228,2,78,9  ; n2504 t=104.044s dur=100ms, freq=740Hz, sample=78, buffer_id=09:4E
    db 0,0,100,0,61,127,11,15,21,1,61,11  ; n2505 t=104.044s dur=100ms, freq=277Hz, sample=61, buffer_id=0B:3D
    db 0,0,100,0,66,127,11,16,93,1,66,11  ; n2506 t=104.044s dur=100ms, freq=349Hz, sample=66, buffer_id=0B:42
    db 0,0,100,0,54,127,12,17,185,0,54,11  ; n2507 t=104.044s dur=100ms, freq=185Hz, sample=54, buffer_id=0B:36
    db 0,0,100,0,90,127,16,18,117,5,90,16  ; n2508 t=104.044s dur=100ms, freq=1397Hz, sample=90, buffer_id=10:5A
    db 0,0,100,0,78,127,17,19,186,2,78,16  ; n2509 t=104.044s dur=100ms, freq=698Hz, sample=78, buffer_id=10:4E
    db 0,0,100,0,66,127,18,20,93,1,66,18  ; n2510 t=104.044s dur=100ms, freq=349Hz, sample=66, buffer_id=12:42
    db 0,0,159,0,42,127,19,23,98,0,42,19  ; n2511 t=104.044s dur=159ms, freq=98Hz, sample=42, buffer_id=13:2A
    db 91,0,159,0,30,127,20,25,49,0,30,20  ; n2512 t=104.044s dur=159ms, freq=49Hz, sample=30, buffer_id=14:1E
    db 0,0,113,0,85,127,2,27,23,4,85,2  ; n2513 t=104.135s dur=113ms, freq=1047Hz, sample=85, buffer_id=02:55
    db 0,0,113,0,86,127,2,28,39,5,86,2  ; n2514 t=104.135s dur=113ms, freq=1319Hz, sample=86, buffer_id=02:56
    db 0,0,113,0,71,127,3,29,11,2,71,3  ; n2515 t=104.135s dur=113ms, freq=523Hz, sample=71, buffer_id=03:47
    db 0,0,113,0,74,127,3,30,147,2,74,3  ; n2516 t=104.135s dur=113ms, freq=659Hz, sample=74, buffer_id=03:4A
    db 0,0,113,0,73,127,4,31,11,2,73,4  ; n2517 t=104.135s dur=113ms, freq=523Hz, sample=73, buffer_id=04:49
    db 0,0,113,0,74,127,4,8,147,2,74,4  ; n2518 t=104.135s dur=113ms, freq=659Hz, sample=74, buffer_id=04:4A [TRUNCATE prev:ch8 @103680.8ms -> 104135.4ms]
    db 0,0,113,0,62,127,5,14,74,1,62,5  ; n2519 t=104.135s dur=113ms, freq=330Hz, sample=62, buffer_id=05:3E [TRUNCATE prev:ch14 @103680.8ms -> 104135.4ms]
    db 0,0,113,0,61,127,6,4,6,1,61,5  ; n2520 t=104.135s dur=113ms, freq=262Hz, sample=61, buffer_id=05:3D [TRUNCATE prev:ch4 @103860.4ms -> 104135.4ms]
    db 0,0,100,0,90,127,16,5,117,5,90,16  ; n2521 t=104.135s dur=100ms, freq=1397Hz, sample=90, buffer_id=10:5A [TRUNCATE prev:ch5 @103862.6ms -> 104135.4ms]
    db 0,0,100,0,78,127,17,21,186,2,78,16  ; n2522 t=104.135s dur=100ms, freq=698Hz, sample=78, buffer_id=10:4E [TRUNCATE prev:ch21 @103862.6ms -> 104135.4ms]
    db 91,0,100,0,66,127,18,22,93,1,66,18  ; n2523 t=104.135s dur=100ms, freq=349Hz, sample=66, buffer_id=12:42 [TRUNCATE prev:ch22 @103862.6ms -> 104135.4ms]
    db 0,0,181,0,85,127,2,24,85,4,85,2  ; n2524 t=104.226s dur=181ms, freq=1109Hz, sample=85, buffer_id=02:55
    db 0,0,181,0,90,127,2,26,117,5,90,2  ; n2525 t=104.226s dur=181ms, freq=1397Hz, sample=90, buffer_id=02:5A
    db 0,0,181,0,73,127,3,3,42,2,73,3  ; n2526 t=104.226s dur=181ms, freq=554Hz, sample=73, buffer_id=03:49 [TRUNCATE prev:ch3 @104044.5ms -> 104226.3ms]
    db 0,0,181,0,78,127,3,6,186,2,78,3  ; n2527 t=104.226s dur=181ms, freq=698Hz, sample=78, buffer_id=03:4E [TRUNCATE prev:ch6 @104044.5ms -> 104226.3ms]
    db 0,0,181,0,73,127,4,7,42,2,73,4  ; n2528 t=104.226s dur=181ms, freq=554Hz, sample=73, buffer_id=04:49 [TRUNCATE prev:ch7 @104044.5ms -> 104226.3ms]
    db 0,0,181,0,78,127,4,9,186,2,78,4  ; n2529 t=104.226s dur=181ms, freq=698Hz, sample=78, buffer_id=04:4E [TRUNCATE prev:ch9 @104044.5ms -> 104226.3ms]
    db 0,0,181,0,66,127,5,10,93,1,66,5  ; n2530 t=104.226s dur=181ms, freq=349Hz, sample=66, buffer_id=05:42 [TRUNCATE prev:ch10 @104044.5ms -> 104226.3ms]
    db 0,0,181,0,61,127,6,11,21,1,61,5  ; n2531 t=104.226s dur=181ms, freq=277Hz, sample=61, buffer_id=05:3D [TRUNCATE prev:ch11 @104044.5ms -> 104226.3ms]
    db 0,0,100,0,90,127,16,18,117,5,90,16  ; n2532 t=104.226s dur=100ms, freq=1397Hz, sample=90, buffer_id=10:5A [TRUNCATE prev:ch18 @104044.5ms -> 104226.3ms]
    db 0,0,100,0,78,127,17,19,186,2,78,16  ; n2533 t=104.226s dur=100ms, freq=698Hz, sample=78, buffer_id=10:4E [TRUNCATE prev:ch19 @104044.5ms -> 104226.3ms]
    db 0,0,100,0,66,127,18,20,93,1,66,18  ; n2534 t=104.226s dur=100ms, freq=349Hz, sample=66, buffer_id=12:42 [TRUNCATE prev:ch20 @104044.5ms -> 104226.3ms]
    db 0,0,159,0,42,127,19,23,92,0,42,19  ; n2535 t=104.226s dur=159ms, freq=92Hz, sample=42, buffer_id=13:2A [TRUNCATE prev:ch23 @104044.5ms -> 104226.3ms]
    db 91,0,159,0,30,127,20,25,46,0,30,20  ; n2536 t=104.226s dur=159ms, freq=46Hz, sample=30, buffer_id=14:1E [TRUNCATE prev:ch25 @104044.5ms -> 104226.3ms]
    db 0,0,100,0,90,127,16,5,117,5,90,16  ; n2537 t=104.317s dur=100ms, freq=1397Hz, sample=90, buffer_id=10:5A [TRUNCATE prev:ch5 @104135.4ms -> 104317.2ms]
    db 0,0,100,0,78,127,17,21,186,2,78,16  ; n2538 t=104.317s dur=100ms, freq=698Hz, sample=78, buffer_id=10:4E [TRUNCATE prev:ch21 @104135.4ms -> 104317.2ms]
    db 89,0,100,0,66,127,18,22,93,1,66,18  ; n2539 t=104.317s dur=100ms, freq=349Hz, sample=66, buffer_id=12:42 [TRUNCATE prev:ch22 @104135.4ms -> 104317.2ms]
    db 2,0,159,0,47,127,10,1,123,0,47,10  ; n2540 t=104.406s dur=159ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 0,0,192,2,59,127,7,2,247,0,59,7  ; n2541 t=104.408s dur=704ms, freq=247Hz, sample=59, buffer_id=07:3B
    db 0,0,192,2,71,127,7,12,238,1,71,7  ; n2542 t=104.408s dur=704ms, freq=494Hz, sample=71, buffer_id=07:47
    db 0,0,100,0,47,127,12,13,123,0,47,11  ; n2543 t=104.408s dur=100ms, freq=123Hz, sample=47, buffer_id=0B:2F
    db 0,0,100,0,35,127,13,15,62,0,35,13  ; n2544 t=104.408s dur=100ms, freq=62Hz, sample=35, buffer_id=0D:23
    db 0,0,150,0,87,127,16,16,39,5,87,16  ; n2545 t=104.408s dur=150ms, freq=1319Hz, sample=87, buffer_id=10:57
    db 0,0,159,0,74,127,17,17,147,2,74,16  ; n2546 t=104.408s dur=159ms, freq=659Hz, sample=74, buffer_id=10:4A
    db 0,0,159,0,66,127,18,20,74,1,66,18  ; n2547 t=104.408s dur=159ms, freq=330Hz, sample=66, buffer_id=12:42 [TRUNCATE prev:ch20 @104226.3ms -> 104408.1ms]
    db 0,0,159,0,47,127,19,0,123,0,47,19  ; n2548 t=104.408s dur=159ms, freq=123Hz, sample=47, buffer_id=13:2F [TRUNCATE prev:ch0 @104042.2ms -> 104408.1ms]
    db 179,0,159,0,35,127,20,4,62,0,35,20  ; n2549 t=104.408s dur=159ms, freq=62Hz, sample=35, buffer_id=14:23 [TRUNCATE prev:ch4 @104135.4ms -> 104408.1ms]
    db 2,0,159,0,47,127,10,8,123,0,47,10  ; n2550 t=104.588s dur=159ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 0,0,159,0,85,127,16,14,23,4,85,16  ; n2551 t=104.590s dur=159ms, freq=1047Hz, sample=85, buffer_id=10:55
    db 0,0,159,0,73,127,17,18,11,2,73,16  ; n2552 t=104.590s dur=159ms, freq=523Hz, sample=73, buffer_id=10:49
    db 0,0,148,0,54,127,18,19,6,1,54,18  ; n2553 t=104.590s dur=148ms, freq=262Hz, sample=54, buffer_id=12:36
    db 0,0,159,0,47,127,19,23,110,0,47,19  ; n2554 t=104.590s dur=159ms, freq=110Hz, sample=47, buffer_id=13:2F
    db 180,0,159,0,33,127,20,25,55,0,33,20  ; n2555 t=104.590s dur=159ms, freq=55Hz, sample=33, buffer_id=14:21
    db 2,0,84,1,47,127,10,0,123,0,47,10  ; n2556 t=104.769s dur=340ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 0,0,113,0,85,127,2,1,23,4,85,2  ; n2557 t=104.772s dur=113ms, freq=1047Hz, sample=85, buffer_id=02:55
    db 0,0,113,0,86,127,2,3,39,5,86,2  ; n2558 t=104.772s dur=113ms, freq=1319Hz, sample=86, buffer_id=02:56
    db 0,0,113,0,71,127,3,4,11,2,71,3  ; n2559 t=104.772s dur=113ms, freq=523Hz, sample=71, buffer_id=03:47
    db 0,0,113,0,74,127,3,5,147,2,74,3  ; n2560 t=104.772s dur=113ms, freq=659Hz, sample=74, buffer_id=03:4A
    db 0,0,113,0,73,127,4,6,11,2,73,4  ; n2561 t=104.772s dur=113ms, freq=523Hz, sample=73, buffer_id=04:49
    db 0,0,113,0,74,127,4,7,147,2,74,4  ; n2562 t=104.772s dur=113ms, freq=659Hz, sample=74, buffer_id=04:4A
    db 0,0,113,0,62,127,5,9,74,1,62,5  ; n2563 t=104.772s dur=113ms, freq=330Hz, sample=62, buffer_id=05:3E
    db 0,0,113,0,61,127,6,10,6,1,61,5  ; n2564 t=104.772s dur=113ms, freq=262Hz, sample=61, buffer_id=05:3D
    db 0,0,100,0,66,127,9,11,114,1,66,9  ; n2565 t=104.772s dur=100ms, freq=370Hz, sample=66, buffer_id=09:42
    db 0,0,100,0,78,127,9,13,228,2,78,9  ; n2566 t=104.772s dur=100ms, freq=740Hz, sample=78, buffer_id=09:4E
    db 0,0,100,0,59,127,11,15,6,1,59,11  ; n2567 t=104.772s dur=100ms, freq=262Hz, sample=59, buffer_id=0B:3B
    db 0,0,100,0,62,127,11,16,74,1,62,11  ; n2568 t=104.772s dur=100ms, freq=330Hz, sample=62, buffer_id=0B:3E
    db 0,0,100,0,54,127,12,17,185,0,54,11  ; n2569 t=104.772s dur=100ms, freq=185Hz, sample=54, buffer_id=0B:36
    db 0,0,100,0,87,127,16,20,39,5,87,16  ; n2570 t=104.772s dur=100ms, freq=1319Hz, sample=87, buffer_id=10:57
    db 0,0,100,0,74,127,17,21,147,2,74,16  ; n2571 t=104.772s dur=100ms, freq=659Hz, sample=74, buffer_id=10:4A
    db 0,0,100,0,66,127,18,24,74,1,66,18  ; n2572 t=104.772s dur=100ms, freq=330Hz, sample=66, buffer_id=12:42
    db 0,0,159,0,42,127,19,22,98,0,42,19  ; n2573 t=104.772s dur=159ms, freq=98Hz, sample=42, buffer_id=13:2A
    db 91,0,159,0,30,127,20,26,49,0,30,20  ; n2574 t=104.772s dur=159ms, freq=49Hz, sample=30, buffer_id=14:1E
    db 0,0,113,0,85,127,2,28,220,3,85,2  ; n2575 t=104.863s dur=113ms, freq=988Hz, sample=85, buffer_id=02:55
    db 0,0,113,0,86,127,2,27,221,4,86,2  ; n2576 t=104.863s dur=113ms, freq=1245Hz, sample=86, buffer_id=02:56
    db 0,0,113,0,71,127,3,30,238,1,71,3  ; n2577 t=104.863s dur=113ms, freq=494Hz, sample=71, buffer_id=03:47
    db 0,0,113,0,74,127,3,29,110,2,74,3  ; n2578 t=104.863s dur=113ms, freq=622Hz, sample=74, buffer_id=03:4A
    db 0,0,113,0,70,127,4,31,238,1,70,4  ; n2579 t=104.863s dur=113ms, freq=494Hz, sample=70, buffer_id=04:46
    db 0,0,113,0,74,127,4,2,110,2,74,4  ; n2580 t=104.863s dur=113ms, freq=622Hz, sample=74, buffer_id=04:4A [TRUNCATE prev:ch2 @104408.1ms -> 104862.6ms]
    db 0,0,113,0,62,127,5,12,55,1,62,5  ; n2581 t=104.863s dur=113ms, freq=311Hz, sample=62, buffer_id=05:3E [TRUNCATE prev:ch12 @104408.1ms -> 104862.6ms]
    db 0,0,113,0,61,127,6,8,247,0,61,5  ; n2582 t=104.863s dur=113ms, freq=247Hz, sample=61, buffer_id=05:3D [TRUNCATE prev:ch8 @104587.6ms -> 104862.6ms]
    db 0,0,100,0,87,127,16,14,39,5,87,16  ; n2583 t=104.863s dur=100ms, freq=1319Hz, sample=87, buffer_id=10:57 [TRUNCATE prev:ch14 @104589.9ms -> 104862.6ms]
    db 0,0,100,0,74,127,17,18,147,2,74,16  ; n2584 t=104.863s dur=100ms, freq=659Hz, sample=74, buffer_id=10:4A [TRUNCATE prev:ch18 @104589.9ms -> 104862.6ms]
    db 91,0,100,0,66,127,18,19,74,1,66,18  ; n2585 t=104.863s dur=100ms, freq=330Hz, sample=66, buffer_id=12:42 [TRUNCATE prev:ch19 @104589.9ms -> 104862.6ms]
    db 0,0,181,0,85,127,2,23,23,4,85,2  ; n2586 t=104.954s dur=181ms, freq=1047Hz, sample=85, buffer_id=02:55
    db 0,0,162,0,86,127,2,25,39,5,86,2  ; n2587 t=104.954s dur=162ms, freq=1319Hz, sample=86, buffer_id=02:56
    db 0,0,181,0,71,127,3,4,11,2,71,3  ; n2588 t=104.954s dur=181ms, freq=523Hz, sample=71, buffer_id=03:47 [TRUNCATE prev:ch4 @104771.7ms -> 104953.6ms]
    db 0,0,162,0,74,127,3,5,147,2,74,3  ; n2589 t=104.954s dur=162ms, freq=659Hz, sample=74, buffer_id=03:4A [TRUNCATE prev:ch5 @104771.7ms -> 104953.6ms]
    db 0,0,181,0,73,127,4,6,11,2,73,4  ; n2590 t=104.954s dur=181ms, freq=523Hz, sample=73, buffer_id=04:49 [TRUNCATE prev:ch6 @104771.7ms -> 104953.6ms]
    db 0,0,181,0,74,127,4,7,147,2,74,4  ; n2591 t=104.954s dur=181ms, freq=659Hz, sample=74, buffer_id=04:4A [TRUNCATE prev:ch7 @104771.7ms -> 104953.6ms]
    db 0,0,162,0,62,127,5,9,74,1,62,5  ; n2592 t=104.954s dur=162ms, freq=330Hz, sample=62, buffer_id=05:3E [TRUNCATE prev:ch9 @104771.7ms -> 104953.6ms]
    db 0,0,181,0,61,127,6,10,6,1,61,5  ; n2593 t=104.954s dur=181ms, freq=262Hz, sample=61, buffer_id=05:3D [TRUNCATE prev:ch10 @104771.7ms -> 104953.6ms]
    db 0,0,100,0,87,127,16,20,39,5,87,16  ; n2594 t=104.954s dur=100ms, freq=1319Hz, sample=87, buffer_id=10:57 [TRUNCATE prev:ch20 @104771.7ms -> 104953.6ms]
    db 0,0,100,0,74,127,17,21,147,2,74,16  ; n2595 t=104.954s dur=100ms, freq=659Hz, sample=74, buffer_id=10:4A [TRUNCATE prev:ch21 @104771.7ms -> 104953.6ms]
    db 0,0,100,0,66,127,18,24,74,1,66,18  ; n2596 t=104.954s dur=100ms, freq=330Hz, sample=66, buffer_id=12:42 [TRUNCATE prev:ch24 @104771.7ms -> 104953.6ms]
    db 0,0,159,0,42,127,19,22,92,0,42,19  ; n2597 t=104.954s dur=159ms, freq=92Hz, sample=42, buffer_id=13:2A [TRUNCATE prev:ch22 @104771.7ms -> 104953.6ms]
    db 91,0,159,0,30,127,20,26,46,0,30,20  ; n2598 t=104.954s dur=159ms, freq=46Hz, sample=30, buffer_id=14:1E [TRUNCATE prev:ch26 @104771.7ms -> 104953.6ms]
    db 0,0,100,0,87,127,16,14,39,5,87,16  ; n2599 t=105.044s dur=100ms, freq=1319Hz, sample=87, buffer_id=10:57 [TRUNCATE prev:ch14 @104862.6ms -> 105044.5ms]
    db 0,0,100,0,74,127,17,18,147,2,74,16  ; n2600 t=105.044s dur=100ms, freq=659Hz, sample=74, buffer_id=10:4A [TRUNCATE prev:ch18 @104862.6ms -> 105044.5ms]
    db 89,0,100,0,66,127,18,19,74,1,66,18  ; n2601 t=105.044s dur=100ms, freq=330Hz, sample=66, buffer_id=12:42 [TRUNCATE prev:ch19 @104862.6ms -> 105044.5ms]
    db 2,0,159,0,47,127,10,1,123,0,47,10  ; n2602 t=105.133s dur=159ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 0,0,192,2,59,127,7,3,247,0,59,7  ; n2603 t=105.135s dur=704ms, freq=247Hz, sample=59, buffer_id=07:3B
    db 0,0,192,2,71,127,7,11,238,1,71,7  ; n2604 t=105.135s dur=704ms, freq=494Hz, sample=71, buffer_id=07:47
    db 0,0,100,0,47,127,12,13,123,0,47,11  ; n2605 t=105.135s dur=100ms, freq=123Hz, sample=47, buffer_id=0B:2F
    db 0,0,100,0,35,127,13,15,62,0,35,13  ; n2606 t=105.135s dur=100ms, freq=62Hz, sample=35, buffer_id=0D:23
    db 0,0,159,0,85,127,16,16,220,3,85,16  ; n2607 t=105.135s dur=159ms, freq=988Hz, sample=85, buffer_id=10:55
    db 0,0,159,0,70,127,17,17,238,1,70,16  ; n2608 t=105.135s dur=159ms, freq=494Hz, sample=70, buffer_id=10:46
    db 0,0,157,0,54,127,18,0,247,0,54,18  ; n2609 t=105.135s dur=157ms, freq=247Hz, sample=54, buffer_id=12:36 [TRUNCATE prev:ch0 @104769.5ms -> 105135.4ms]
    db 0,0,159,0,47,127,19,2,123,0,47,19  ; n2610 t=105.135s dur=159ms, freq=123Hz, sample=47, buffer_id=13:2F [TRUNCATE prev:ch2 @104862.6ms -> 105135.4ms]
    db 179,0,159,0,35,127,20,8,62,0,35,20  ; n2611 t=105.135s dur=159ms, freq=62Hz, sample=35, buffer_id=14:23 [TRUNCATE prev:ch8 @104862.6ms -> 105135.4ms]
    db 2,0,159,0,47,127,10,12,123,0,47,10  ; n2612 t=105.315s dur=159ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 0,0,159,0,85,127,16,5,85,4,85,16  ; n2613 t=105.317s dur=159ms, freq=1109Hz, sample=85, buffer_id=10:55
    db 0,0,159,0,73,127,17,9,42,2,73,16  ; n2614 t=105.317s dur=159ms, freq=554Hz, sample=73, buffer_id=10:49
    db 0,0,159,0,66,127,18,20,21,1,66,18  ; n2615 t=105.317s dur=159ms, freq=277Hz, sample=66, buffer_id=12:42
    db 0,0,159,0,47,127,19,21,110,0,47,19  ; n2616 t=105.317s dur=159ms, freq=110Hz, sample=47, buffer_id=13:2F
    db 180,0,159,0,33,127,20,22,55,0,33,20  ; n2617 t=105.317s dur=159ms, freq=55Hz, sample=33, buffer_id=14:21
    db 2,0,159,0,47,127,10,0,123,0,47,10  ; n2618 t=105.497s dur=159ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 0,0,113,0,85,127,2,1,220,3,85,2  ; n2619 t=105.499s dur=113ms, freq=988Hz, sample=85, buffer_id=02:55
    db 0,0,113,0,86,127,2,2,151,4,86,2  ; n2620 t=105.499s dur=113ms, freq=1175Hz, sample=86, buffer_id=02:56
    db 0,0,113,0,71,127,3,6,238,1,71,3  ; n2621 t=105.499s dur=113ms, freq=494Hz, sample=71, buffer_id=03:47
    db 0,0,113,0,74,127,3,4,75,2,74,3  ; n2622 t=105.499s dur=113ms, freq=587Hz, sample=74, buffer_id=03:4A
    db 0,0,113,0,70,127,4,7,238,1,70,4  ; n2623 t=105.499s dur=113ms, freq=494Hz, sample=70, buffer_id=04:46
    db 0,0,113,0,74,127,4,8,75,2,74,4  ; n2624 t=105.499s dur=113ms, freq=587Hz, sample=74, buffer_id=04:4A
    db 0,0,113,0,62,127,5,10,38,1,62,5  ; n2625 t=105.499s dur=113ms, freq=294Hz, sample=62, buffer_id=05:3E
    db 0,0,113,0,61,127,6,13,247,0,61,5  ; n2626 t=105.499s dur=113ms, freq=247Hz, sample=61, buffer_id=05:3D
    db 0,0,100,0,66,127,9,14,114,1,66,9  ; n2627 t=105.499s dur=100ms, freq=370Hz, sample=66, buffer_id=09:42
    db 0,0,100,0,78,127,9,15,228,2,78,9  ; n2628 t=105.499s dur=100ms, freq=740Hz, sample=78, buffer_id=09:4E
    db 0,0,100,0,59,127,11,16,247,0,59,11  ; n2629 t=105.499s dur=100ms, freq=247Hz, sample=59, buffer_id=0B:3B
    db 0,0,100,0,62,127,11,17,38,1,62,11  ; n2630 t=105.499s dur=100ms, freq=294Hz, sample=62, buffer_id=0B:3E
    db 0,0,100,0,54,127,12,18,185,0,54,11  ; n2631 t=105.499s dur=100ms, freq=185Hz, sample=54, buffer_id=0B:36
    db 0,0,159,0,86,127,16,19,151,4,86,16  ; n2632 t=105.499s dur=159ms, freq=1175Hz, sample=86, buffer_id=10:56
    db 0,0,159,0,74,127,17,23,75,2,74,16  ; n2633 t=105.499s dur=159ms, freq=587Hz, sample=74, buffer_id=10:4A
    db 0,0,159,0,66,127,18,25,38,1,66,18  ; n2634 t=105.499s dur=159ms, freq=294Hz, sample=66, buffer_id=12:42
    db 0,0,159,0,42,127,19,24,98,0,42,19  ; n2635 t=105.499s dur=159ms, freq=98Hz, sample=42, buffer_id=13:2A
    db 91,0,159,0,30,127,20,27,49,0,30,20  ; n2636 t=105.499s dur=159ms, freq=49Hz, sample=30, buffer_id=14:1E
    db 0,0,113,0,85,127,2,26,164,3,85,2  ; n2637 t=105.590s dur=113ms, freq=932Hz, sample=85, buffer_id=02:55
    db 0,0,113,0,85,127,2,29,85,4,85,2  ; n2638 t=105.590s dur=113ms, freq=1109Hz, sample=85, buffer_id=02:55
    db 0,0,113,0,71,127,3,28,210,1,71,3  ; n2639 t=105.590s dur=113ms, freq=466Hz, sample=71, buffer_id=03:47
    db 0,0,113,0,73,127,3,30,42,2,73,3  ; n2640 t=105.590s dur=113ms, freq=554Hz, sample=73, buffer_id=03:49
    db 0,0,113,0,70,127,4,31,210,1,70,4  ; n2641 t=105.590s dur=113ms, freq=466Hz, sample=70, buffer_id=04:46 [TRUNCATE prev:ch31 @104862.6ms -> 105589.9ms]
    db 0,0,113,0,73,127,4,3,42,2,73,4  ; n2642 t=105.590s dur=113ms, freq=554Hz, sample=73, buffer_id=04:49 [TRUNCATE prev:ch3 @105135.4ms -> 105589.9ms]
    db 0,0,113,0,61,127,5,11,21,1,61,5  ; n2643 t=105.590s dur=113ms, freq=277Hz, sample=61, buffer_id=05:3D [TRUNCATE prev:ch11 @105135.4ms -> 105589.9ms]
    db 89,0,113,0,61,127,6,12,233,0,61,5  ; n2644 t=105.590s dur=113ms, freq=233Hz, sample=61, buffer_id=05:3D [TRUNCATE prev:ch12 @105314.9ms -> 105589.9ms]
    db 2,0,159,0,47,127,10,5,123,0,47,10  ; n2645 t=105.679s dur=159ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 0,0,181,0,85,127,2,9,220,3,85,2  ; n2646 t=105.681s dur=181ms, freq=988Hz, sample=85, buffer_id=02:55
    db 0,0,181,0,86,127,2,20,151,4,86,2  ; n2647 t=105.681s dur=181ms, freq=1175Hz, sample=86, buffer_id=02:56
    db 0,0,181,0,71,127,3,21,238,1,71,3  ; n2648 t=105.681s dur=181ms, freq=494Hz, sample=71, buffer_id=03:47
    db 0,0,181,0,74,127,3,22,75,2,74,3  ; n2649 t=105.681s dur=181ms, freq=587Hz, sample=74, buffer_id=03:4A
    db 0,0,181,0,70,127,4,7,238,1,70,4  ; n2650 t=105.681s dur=181ms, freq=494Hz, sample=70, buffer_id=04:46 [TRUNCATE prev:ch7 @105499.0ms -> 105680.8ms]
    db 0,0,181,0,74,127,4,8,75,2,74,4  ; n2651 t=105.681s dur=181ms, freq=587Hz, sample=74, buffer_id=04:4A [TRUNCATE prev:ch8 @105499.0ms -> 105680.8ms]
    db 0,0,181,0,62,127,5,10,38,1,62,5  ; n2652 t=105.681s dur=181ms, freq=294Hz, sample=62, buffer_id=05:3E [TRUNCATE prev:ch10 @105499.0ms -> 105680.8ms]
    db 0,0,181,0,61,127,6,13,247,0,61,5  ; n2653 t=105.681s dur=181ms, freq=247Hz, sample=61, buffer_id=05:3D [TRUNCATE prev:ch13 @105499.0ms -> 105680.8ms]
    db 0,0,150,0,87,127,16,0,39,5,87,16  ; n2654 t=105.681s dur=150ms, freq=1319Hz, sample=87, buffer_id=10:57 [TRUNCATE prev:ch0 @105496.7ms -> 105680.8ms]
    db 0,0,159,0,74,127,17,23,147,2,74,16  ; n2655 t=105.681s dur=159ms, freq=659Hz, sample=74, buffer_id=10:4A [TRUNCATE prev:ch23 @105499.0ms -> 105680.8ms]
    db 0,0,159,0,66,127,18,25,74,1,66,18  ; n2656 t=105.681s dur=159ms, freq=330Hz, sample=66, buffer_id=12:42 [TRUNCATE prev:ch25 @105499.0ms -> 105680.8ms]
    db 0,0,159,0,42,127,19,24,92,0,42,19  ; n2657 t=105.681s dur=159ms, freq=92Hz, sample=42, buffer_id=13:2A [TRUNCATE prev:ch24 @105499.0ms -> 105680.8ms]
    db 180,0,159,0,30,127,20,27,46,0,30,20  ; n2658 t=105.681s dur=159ms, freq=46Hz, sample=30, buffer_id=14:1E [TRUNCATE prev:ch27 @105499.0ms -> 105680.8ms]
    db 2,0,159,0,47,127,10,1,123,0,47,10  ; n2659 t=105.860s dur=159ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 0,0,192,2,59,127,7,2,247,0,59,7  ; n2660 t=105.863s dur=704ms, freq=247Hz, sample=59, buffer_id=07:3B
    db 0,0,192,2,71,127,7,4,238,1,71,7  ; n2661 t=105.863s dur=704ms, freq=494Hz, sample=71, buffer_id=07:47
    db 0,0,100,0,47,127,12,6,123,0,47,11  ; n2662 t=105.863s dur=100ms, freq=123Hz, sample=47, buffer_id=0B:2F
    db 0,0,100,0,35,127,13,14,62,0,35,13  ; n2663 t=105.863s dur=100ms, freq=62Hz, sample=35, buffer_id=0D:23
    db 0,0,159,0,90,127,16,15,200,5,90,16  ; n2664 t=105.863s dur=159ms, freq=1480Hz, sample=90, buffer_id=10:5A
    db 0,0,159,0,78,127,17,16,228,2,78,16  ; n2665 t=105.863s dur=159ms, freq=740Hz, sample=78, buffer_id=10:4E
    db 0,0,159,0,66,127,18,17,114,1,66,18  ; n2666 t=105.863s dur=159ms, freq=370Hz, sample=66, buffer_id=12:42
    db 0,0,159,0,47,127,19,18,123,0,47,19  ; n2667 t=105.863s dur=159ms, freq=123Hz, sample=47, buffer_id=13:2F
    db 180,0,159,0,35,127,20,19,62,0,35,20  ; n2668 t=105.863s dur=159ms, freq=62Hz, sample=35, buffer_id=14:23
    db 2,0,159,0,47,127,10,0,123,0,47,10  ; n2669 t=106.042s dur=159ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 0,0,159,0,86,127,16,3,151,4,86,16  ; n2670 t=106.044s dur=159ms, freq=1175Hz, sample=86, buffer_id=10:56
    db 0,0,159,0,74,127,17,5,75,2,74,16  ; n2671 t=106.044s dur=159ms, freq=587Hz, sample=74, buffer_id=10:4A
    db 0,0,159,0,66,127,18,11,38,1,66,18  ; n2672 t=106.044s dur=159ms, freq=294Hz, sample=66, buffer_id=12:42
    db 0,0,159,0,47,127,19,12,110,0,47,19  ; n2673 t=106.044s dur=159ms, freq=110Hz, sample=47, buffer_id=13:2F
    db 180,0,159,0,33,127,20,23,55,0,33,20  ; n2674 t=106.044s dur=159ms, freq=55Hz, sample=33, buffer_id=14:21
    db 2,0,159,0,47,127,10,6,123,0,47,10  ; n2675 t=106.224s dur=159ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 0,0,113,0,86,127,2,1,151,4,86,2  ; n2676 t=106.226s dur=113ms, freq=1175Hz, sample=86, buffer_id=02:56
    db 0,0,113,0,90,127,2,7,200,5,90,2  ; n2677 t=106.226s dur=113ms, freq=1480Hz, sample=90, buffer_id=02:5A
    db 0,0,113,0,74,127,3,8,75,2,74,3  ; n2678 t=106.226s dur=113ms, freq=587Hz, sample=74, buffer_id=03:4A
    db 0,0,113,0,78,127,3,9,228,2,78,3  ; n2679 t=106.226s dur=113ms, freq=740Hz, sample=78, buffer_id=03:4E
    db 0,0,113,0,74,127,4,10,75,2,74,4  ; n2680 t=106.226s dur=113ms, freq=587Hz, sample=74, buffer_id=04:4A
    db 0,0,113,0,78,127,4,13,228,2,78,4  ; n2681 t=106.226s dur=113ms, freq=740Hz, sample=78, buffer_id=04:4E
    db 0,0,113,0,66,127,5,14,114,1,66,5  ; n2682 t=106.226s dur=113ms, freq=370Hz, sample=66, buffer_id=05:42
    db 0,0,113,0,62,127,6,15,38,1,62,5  ; n2683 t=106.226s dur=113ms, freq=294Hz, sample=62, buffer_id=05:3E
    db 0,0,100,0,66,127,9,16,114,1,66,9  ; n2684 t=106.226s dur=100ms, freq=370Hz, sample=66, buffer_id=09:42
    db 0,0,100,0,78,127,9,17,228,2,78,9  ; n2685 t=106.226s dur=100ms, freq=740Hz, sample=78, buffer_id=09:4E
    db 0,0,100,0,59,127,11,18,247,0,59,11  ; n2686 t=106.226s dur=100ms, freq=247Hz, sample=59, buffer_id=0B:3B
    db 0,0,100,0,62,127,11,19,38,1,62,11  ; n2687 t=106.226s dur=100ms, freq=294Hz, sample=62, buffer_id=0B:3E
    db 0,0,100,0,54,127,12,20,185,0,54,11  ; n2688 t=106.226s dur=100ms, freq=185Hz, sample=54, buffer_id=0B:36
    db 0,0,159,0,90,127,16,21,200,5,90,16  ; n2689 t=106.226s dur=159ms, freq=1480Hz, sample=90, buffer_id=10:5A
    db 0,0,159,0,78,127,17,22,228,2,78,16  ; n2690 t=106.226s dur=159ms, freq=740Hz, sample=78, buffer_id=10:4E
    db 0,0,159,0,66,127,18,24,114,1,66,18  ; n2691 t=106.226s dur=159ms, freq=370Hz, sample=66, buffer_id=12:42
    db 0,0,159,0,42,127,19,25,98,0,42,19  ; n2692 t=106.226s dur=159ms, freq=98Hz, sample=42, buffer_id=13:2A
    db 91,0,159,0,30,127,20,26,49,0,30,20  ; n2693 t=106.226s dur=159ms, freq=49Hz, sample=30, buffer_id=14:1E
    db 0,0,113,0,85,127,2,27,85,4,85,2  ; n2694 t=106.317s dur=113ms, freq=1109Hz, sample=85, buffer_id=02:55
    db 0,0,113,0,90,127,2,28,117,5,90,2  ; n2695 t=106.317s dur=113ms, freq=1397Hz, sample=90, buffer_id=02:5A
    db 0,0,113,0,73,127,3,29,42,2,73,3  ; n2696 t=106.317s dur=113ms, freq=554Hz, sample=73, buffer_id=03:49
    db 0,0,113,0,78,127,3,30,186,2,78,3  ; n2697 t=106.317s dur=113ms, freq=698Hz, sample=78, buffer_id=03:4E
    db 0,0,113,0,73,127,4,31,42,2,73,4  ; n2698 t=106.317s dur=113ms, freq=554Hz, sample=73, buffer_id=04:49
    db 0,0,113,0,78,127,4,2,186,2,78,4  ; n2699 t=106.317s dur=113ms, freq=698Hz, sample=78, buffer_id=04:4E [TRUNCATE prev:ch2 @105862.6ms -> 106317.2ms]
    db 0,0,113,0,66,127,5,4,93,1,66,5  ; n2700 t=106.317s dur=113ms, freq=349Hz, sample=66, buffer_id=05:42 [TRUNCATE prev:ch4 @105862.6ms -> 106317.2ms]
    db 89,0,113,0,61,127,6,0,21,1,61,5  ; n2701 t=106.317s dur=113ms, freq=277Hz, sample=61, buffer_id=05:3D [TRUNCATE prev:ch0 @106042.2ms -> 106317.2ms]
    db 2,0,159,0,47,127,10,3,123,0,47,10  ; n2702 t=106.406s dur=159ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 0,0,181,0,86,127,2,5,151,4,86,2  ; n2703 t=106.408s dur=181ms, freq=1175Hz, sample=86, buffer_id=02:56
    db 0,0,181,0,90,127,2,11,200,5,90,2  ; n2704 t=106.408s dur=181ms, freq=1480Hz, sample=90, buffer_id=02:5A
    db 0,0,181,0,74,127,3,12,75,2,74,3  ; n2705 t=106.408s dur=181ms, freq=587Hz, sample=74, buffer_id=03:4A
    db 0,0,181,0,78,127,3,23,228,2,78,3  ; n2706 t=106.408s dur=181ms, freq=740Hz, sample=78, buffer_id=03:4E
    db 0,0,181,0,74,127,4,10,75,2,74,4  ; n2707 t=106.408s dur=181ms, freq=587Hz, sample=74, buffer_id=04:4A [TRUNCATE prev:ch10 @106226.3ms -> 106408.1ms]
    db 0,0,181,0,78,127,4,13,228,2,78,4  ; n2708 t=106.408s dur=181ms, freq=740Hz, sample=78, buffer_id=04:4E [TRUNCATE prev:ch13 @106226.3ms -> 106408.1ms]
    db 0,0,181,0,66,127,5,14,114,1,66,5  ; n2709 t=106.408s dur=181ms, freq=370Hz, sample=66, buffer_id=05:42 [TRUNCATE prev:ch14 @106226.3ms -> 106408.1ms]
    db 0,0,181,0,62,127,6,15,38,1,62,5  ; n2710 t=106.408s dur=181ms, freq=294Hz, sample=62, buffer_id=05:3E [TRUNCATE prev:ch15 @106226.3ms -> 106408.1ms]
    db 0,0,159,0,97,127,16,6,184,7,97,16  ; n2711 t=106.408s dur=159ms, freq=1976Hz, sample=97, buffer_id=10:61 [TRUNCATE prev:ch6 @106224.0ms -> 106408.1ms]
    db 0,0,159,0,85,127,17,1,220,3,85,16  ; n2712 t=106.408s dur=159ms, freq=988Hz, sample=85, buffer_id=10:55 [TRUNCATE prev:ch1 @106226.3ms -> 106408.1ms]
    db 0,0,159,0,73,127,18,7,238,1,73,18  ; n2713 t=106.408s dur=159ms, freq=494Hz, sample=73, buffer_id=12:49 [TRUNCATE prev:ch7 @106226.3ms -> 106408.1ms]
    db 0,0,159,0,42,127,19,25,92,0,42,19  ; n2714 t=106.408s dur=159ms, freq=92Hz, sample=42, buffer_id=13:2A [TRUNCATE prev:ch25 @106226.3ms -> 106408.1ms]
    db 179,0,159,0,30,127,20,26,46,0,30,20  ; n2715 t=106.408s dur=159ms, freq=46Hz, sample=30, buffer_id=14:1E [TRUNCATE prev:ch26 @106226.3ms -> 106408.1ms]
    db 2,0,159,0,42,127,10,8,92,0,42,10  ; n2716 t=106.588s dur=159ms, freq=92Hz, sample=42, buffer_id=0A:2A
    db 0,0,120,0,62,127,7,9,38,1,62,7  ; n2717 t=106.590s dur=120ms, freq=294Hz, sample=62, buffer_id=07:3E
    db 0,0,100,0,68,127,7,16,184,1,68,7  ; n2718 t=106.590s dur=100ms, freq=440Hz, sample=68, buffer_id=07:44
    db 0,0,100,0,50,127,12,17,147,0,50,11  ; n2719 t=106.590s dur=100ms, freq=147Hz, sample=50, buffer_id=0B:32
    db 0,0,100,0,35,127,13,18,73,0,35,13  ; n2720 t=106.590s dur=100ms, freq=73Hz, sample=35, buffer_id=0D:23
    db 0,0,159,0,90,127,16,19,224,6,90,16  ; n2721 t=106.590s dur=159ms, freq=1760Hz, sample=90, buffer_id=10:5A
    db 0,0,159,0,78,127,17,20,112,3,78,16  ; n2722 t=106.590s dur=159ms, freq=880Hz, sample=78, buffer_id=10:4E
    db 0,0,159,0,66,127,18,21,184,1,66,18  ; n2723 t=106.590s dur=159ms, freq=440Hz, sample=66, buffer_id=12:42
    db 0,0,159,0,47,127,19,22,147,0,47,19  ; n2724 t=106.590s dur=159ms, freq=147Hz, sample=47, buffer_id=13:2F
    db 180,0,159,0,35,127,20,24,73,0,35,20  ; n2725 t=106.590s dur=159ms, freq=73Hz, sample=35, buffer_id=14:23
    db 2,0,159,0,42,127,10,0,92,0,42,10  ; n2726 t=106.769s dur=159ms, freq=92Hz, sample=42, buffer_id=0A:2A
    db 0,0,159,0,90,127,16,1,200,5,90,16  ; n2727 t=106.772s dur=159ms, freq=1480Hz, sample=90, buffer_id=10:5A
    db 0,0,159,0,78,127,17,2,228,2,78,16  ; n2728 t=106.772s dur=159ms, freq=740Hz, sample=78, buffer_id=10:4E
    db 0,0,159,0,66,127,18,3,114,1,66,18  ; n2729 t=106.772s dur=159ms, freq=370Hz, sample=66, buffer_id=12:42
    db 0,0,159,0,47,127,19,4,139,0,47,19  ; n2730 t=106.772s dur=159ms, freq=139Hz, sample=47, buffer_id=13:2F
    db 180,0,159,0,35,127,20,6,69,0,35,20  ; n2731 t=106.772s dur=159ms, freq=69Hz, sample=35, buffer_id=14:23
    db 2,0,159,0,42,127,10,5,92,0,42,10  ; n2732 t=106.951s dur=159ms, freq=92Hz, sample=42, buffer_id=0A:2A
    db 0,0,113,0,90,127,2,7,200,5,90,2  ; n2733 t=106.954s dur=113ms, freq=1480Hz, sample=90, buffer_id=02:5A
    db 0,0,113,0,94,127,2,8,224,6,94,2  ; n2734 t=106.954s dur=113ms, freq=1760Hz, sample=94, buffer_id=02:5E
    db 0,0,113,0,78,127,3,9,228,2,78,3  ; n2735 t=106.954s dur=113ms, freq=740Hz, sample=78, buffer_id=03:4E
    db 0,0,113,0,78,127,3,10,112,3,78,3  ; n2736 t=106.954s dur=113ms, freq=880Hz, sample=78, buffer_id=03:4E
    db 0,0,113,0,78,127,4,11,228,2,78,4  ; n2737 t=106.954s dur=113ms, freq=740Hz, sample=78, buffer_id=04:4E
    db 0,0,113,0,81,127,4,12,112,3,81,4  ; n2738 t=106.954s dur=113ms, freq=880Hz, sample=81, buffer_id=04:51
    db 0,0,113,0,70,127,5,13,184,1,70,5  ; n2739 t=106.954s dur=113ms, freq=440Hz, sample=70, buffer_id=05:46
    db 0,0,113,0,66,127,6,15,114,1,66,5  ; n2740 t=106.954s dur=113ms, freq=370Hz, sample=66, buffer_id=05:42
    db 0,0,100,0,66,127,9,14,114,1,66,9  ; n2741 t=106.954s dur=100ms, freq=370Hz, sample=66, buffer_id=09:42
    db 0,0,100,0,78,127,9,16,228,2,78,9  ; n2742 t=106.954s dur=100ms, freq=740Hz, sample=78, buffer_id=09:4E
    db 0,0,100,0,58,127,11,17,220,0,58,11  ; n2743 t=106.954s dur=100ms, freq=220Hz, sample=58, buffer_id=0B:3A
    db 0,0,100,0,62,127,11,18,38,1,62,11  ; n2744 t=106.954s dur=100ms, freq=294Hz, sample=62, buffer_id=0B:3E
    db 0,0,100,0,54,127,12,19,185,0,54,11  ; n2745 t=106.954s dur=100ms, freq=185Hz, sample=54, buffer_id=0B:36
    db 0,0,159,0,86,127,16,20,151,4,86,16  ; n2746 t=106.954s dur=159ms, freq=1175Hz, sample=86, buffer_id=10:56
    db 0,0,159,0,74,127,17,21,75,2,74,16  ; n2747 t=106.954s dur=159ms, freq=587Hz, sample=74, buffer_id=10:4A
    db 0,0,159,0,66,127,18,22,38,1,66,18  ; n2748 t=106.954s dur=159ms, freq=294Hz, sample=66, buffer_id=12:42
    db 0,0,159,0,47,127,19,23,123,0,47,19  ; n2749 t=106.954s dur=159ms, freq=123Hz, sample=47, buffer_id=13:2F
    db 91,0,159,0,35,127,20,25,62,0,35,20  ; n2750 t=106.954s dur=159ms, freq=62Hz, sample=35, buffer_id=14:23
    db 0,0,113,0,90,127,2,24,117,5,90,2  ; n2751 t=107.044s dur=113ms, freq=1397Hz, sample=90, buffer_id=02:5A
    db 0,0,113,0,90,127,2,26,125,6,90,2  ; n2752 t=107.044s dur=113ms, freq=1661Hz, sample=90, buffer_id=02:5A
    db 0,0,113,0,78,127,3,27,186,2,78,3  ; n2753 t=107.044s dur=113ms, freq=698Hz, sample=78, buffer_id=03:4E
    db 0,0,113,0,78,127,3,28,63,3,78,3  ; n2754 t=107.044s dur=113ms, freq=831Hz, sample=78, buffer_id=03:4E
    db 0,0,113,0,78,127,4,29,186,2,78,4  ; n2755 t=107.044s dur=113ms, freq=698Hz, sample=78, buffer_id=04:4E
    db 0,0,113,0,81,127,4,30,63,3,81,4  ; n2756 t=107.044s dur=113ms, freq=831Hz, sample=81, buffer_id=04:51
    db 0,0,113,0,66,127,5,31,159,1,66,5  ; n2757 t=107.044s dur=113ms, freq=415Hz, sample=66, buffer_id=05:42
    db 89,0,113,0,66,127,6,0,93,1,66,5  ; n2758 t=107.044s dur=113ms, freq=349Hz, sample=66, buffer_id=05:42 [TRUNCATE prev:ch0 @106769.5ms -> 107044.5ms]
    db 2,0,159,0,42,127,10,1,92,0,42,10  ; n2759 t=107.133s dur=159ms, freq=92Hz, sample=42, buffer_id=0A:2A
    db 0,0,181,0,90,127,2,2,200,5,90,2  ; n2760 t=107.135s dur=181ms, freq=1480Hz, sample=90, buffer_id=02:5A
    db 0,0,181,0,94,127,2,3,224,6,94,2  ; n2761 t=107.135s dur=181ms, freq=1760Hz, sample=94, buffer_id=02:5E
    db 0,0,181,0,78,127,3,4,228,2,78,3  ; n2762 t=107.135s dur=181ms, freq=740Hz, sample=78, buffer_id=03:4E
    db 0,0,181,0,78,127,3,6,112,3,78,3  ; n2763 t=107.135s dur=181ms, freq=880Hz, sample=78, buffer_id=03:4E
    db 0,0,181,0,78,127,4,11,228,2,78,4  ; n2764 t=107.135s dur=181ms, freq=740Hz, sample=78, buffer_id=04:4E [TRUNCATE prev:ch11 @106953.6ms -> 107135.4ms]
    db 0,0,181,0,81,127,4,12,112,3,81,4  ; n2765 t=107.135s dur=181ms, freq=880Hz, sample=81, buffer_id=04:51 [TRUNCATE prev:ch12 @106953.6ms -> 107135.4ms]
    db 0,0,181,0,70,127,5,13,184,1,70,5  ; n2766 t=107.135s dur=181ms, freq=440Hz, sample=70, buffer_id=05:46 [TRUNCATE prev:ch13 @106953.6ms -> 107135.4ms]
    db 0,0,181,0,66,127,6,15,114,1,66,5  ; n2767 t=107.135s dur=181ms, freq=370Hz, sample=66, buffer_id=05:42 [TRUNCATE prev:ch15 @106953.6ms -> 107135.4ms]
    db 0,0,159,0,90,127,16,5,200,5,90,16  ; n2768 t=107.135s dur=159ms, freq=1480Hz, sample=90, buffer_id=10:5A [TRUNCATE prev:ch5 @106951.3ms -> 107135.4ms]
    db 0,0,159,0,78,127,17,7,228,2,78,16  ; n2769 t=107.135s dur=159ms, freq=740Hz, sample=78, buffer_id=10:4E [TRUNCATE prev:ch7 @106953.6ms -> 107135.4ms]
    db 0,0,159,0,66,127,18,22,114,1,66,18  ; n2770 t=107.135s dur=159ms, freq=370Hz, sample=66, buffer_id=12:42 [TRUNCATE prev:ch22 @106953.6ms -> 107135.4ms]
    db 0,0,159,0,47,127,19,23,110,0,47,19  ; n2771 t=107.135s dur=159ms, freq=110Hz, sample=47, buffer_id=13:2F [TRUNCATE prev:ch23 @106953.6ms -> 107135.4ms]
    db 179,0,159,0,33,127,20,8,55,0,33,20  ; n2772 t=107.135s dur=159ms, freq=55Hz, sample=33, buffer_id=14:21 [TRUNCATE prev:ch8 @106953.6ms -> 107135.4ms]
    db 2,0,84,1,42,127,10,9,92,0,42,10  ; n2773 t=107.315s dur=340ms, freq=92Hz, sample=42, buffer_id=0A:2A
    db 0,0,120,0,62,127,7,10,38,1,62,7  ; n2774 t=107.317s dur=120ms, freq=294Hz, sample=62, buffer_id=07:3E
    db 0,0,100,0,68,127,7,14,184,1,68,7  ; n2775 t=107.317s dur=100ms, freq=440Hz, sample=68, buffer_id=07:44
    db 0,0,100,0,50,127,12,16,147,0,50,11  ; n2776 t=107.317s dur=100ms, freq=147Hz, sample=50, buffer_id=0B:32
    db 0,0,100,0,35,127,13,17,73,0,35,13  ; n2777 t=107.317s dur=100ms, freq=73Hz, sample=35, buffer_id=0D:23
    db 0,0,100,0,90,127,16,18,224,6,90,16  ; n2778 t=107.317s dur=100ms, freq=1760Hz, sample=90, buffer_id=10:5A
    db 0,0,100,0,78,127,17,19,112,3,78,16  ; n2779 t=107.317s dur=100ms, freq=880Hz, sample=78, buffer_id=10:4E
    db 0,0,100,0,66,127,18,20,184,1,66,18  ; n2780 t=107.317s dur=100ms, freq=440Hz, sample=66, buffer_id=12:42
    db 0,0,159,0,47,127,19,21,147,0,47,19  ; n2781 t=107.317s dur=159ms, freq=147Hz, sample=47, buffer_id=13:2F
    db 91,0,159,0,35,127,20,25,73,0,35,20  ; n2782 t=107.317s dur=159ms, freq=73Hz, sample=35, buffer_id=14:23 [TRUNCATE prev:ch25 @106953.6ms -> 107317.2ms]
    db 0,0,100,0,90,127,16,0,224,6,90,16  ; n2783 t=107.408s dur=100ms, freq=1760Hz, sample=90, buffer_id=10:5A
    db 0,0,100,0,78,127,17,24,112,3,78,16  ; n2784 t=107.408s dur=100ms, freq=880Hz, sample=78, buffer_id=10:4E
    db 91,0,100,0,66,127,18,26,184,1,66,18  ; n2785 t=107.408s dur=100ms, freq=440Hz, sample=66, buffer_id=12:42
    db 0,0,100,0,90,127,16,1,224,6,90,16  ; n2786 t=107.499s dur=100ms, freq=1760Hz, sample=90, buffer_id=10:5A
    db 0,0,100,0,78,127,17,5,112,3,78,16  ; n2787 t=107.499s dur=100ms, freq=880Hz, sample=78, buffer_id=10:4E
    db 0,0,100,0,66,127,18,7,184,1,66,18  ; n2788 t=107.499s dur=100ms, freq=440Hz, sample=66, buffer_id=12:42
    db 0,0,159,0,47,127,19,8,139,0,47,19  ; n2789 t=107.499s dur=159ms, freq=139Hz, sample=47, buffer_id=13:2F
    db 91,0,159,0,35,127,20,22,69,0,35,20  ; n2790 t=107.499s dur=159ms, freq=69Hz, sample=35, buffer_id=14:23
    db 0,0,100,0,90,127,16,2,224,6,90,16  ; n2791 t=107.590s dur=100ms, freq=1760Hz, sample=90, buffer_id=10:5A
    db 0,0,100,0,78,127,17,3,112,3,78,16  ; n2792 t=107.590s dur=100ms, freq=880Hz, sample=78, buffer_id=10:4E
    db 91,0,100,0,66,127,18,4,184,1,66,18  ; n2793 t=107.590s dur=100ms, freq=440Hz, sample=66, buffer_id=12:42
    db 0,0,113,0,90,127,2,6,200,5,90,2  ; n2794 t=107.681s dur=113ms, freq=1480Hz, sample=90, buffer_id=02:5A
    db 0,0,113,0,94,127,2,10,224,6,94,2  ; n2795 t=107.681s dur=113ms, freq=1760Hz, sample=94, buffer_id=02:5E
    db 0,0,113,0,78,127,3,11,228,2,78,3  ; n2796 t=107.681s dur=113ms, freq=740Hz, sample=78, buffer_id=03:4E
    db 0,0,113,0,78,127,3,12,112,3,78,3  ; n2797 t=107.681s dur=113ms, freq=880Hz, sample=78, buffer_id=03:4E
    db 0,0,113,0,78,127,4,13,228,2,78,4  ; n2798 t=107.681s dur=113ms, freq=740Hz, sample=78, buffer_id=04:4E
    db 0,0,113,0,81,127,4,14,112,3,81,4  ; n2799 t=107.681s dur=113ms, freq=880Hz, sample=81, buffer_id=04:51
    db 0,0,113,0,70,127,5,15,184,1,70,5  ; n2800 t=107.681s dur=113ms, freq=440Hz, sample=70, buffer_id=05:46
    db 0,0,113,0,66,127,6,16,114,1,66,5  ; n2801 t=107.681s dur=113ms, freq=370Hz, sample=66, buffer_id=05:42
    db 0,0,100,0,66,127,9,17,114,1,66,9  ; n2802 t=107.681s dur=100ms, freq=370Hz, sample=66, buffer_id=09:42
    db 0,0,100,0,78,127,9,18,228,2,78,9  ; n2803 t=107.681s dur=100ms, freq=740Hz, sample=78, buffer_id=09:4E
    db 0,0,100,0,58,127,11,19,220,0,58,11  ; n2804 t=107.681s dur=100ms, freq=220Hz, sample=58, buffer_id=0B:3A
    db 0,0,100,0,62,127,11,20,38,1,62,11  ; n2805 t=107.681s dur=100ms, freq=294Hz, sample=62, buffer_id=0B:3E
    db 0,0,100,0,54,127,12,21,185,0,54,11  ; n2806 t=107.681s dur=100ms, freq=185Hz, sample=54, buffer_id=0B:36
    db 0,0,100,0,90,127,16,23,224,6,90,16  ; n2807 t=107.681s dur=100ms, freq=1760Hz, sample=90, buffer_id=10:5A
    db 0,0,100,0,78,127,17,25,112,3,78,16  ; n2808 t=107.681s dur=100ms, freq=880Hz, sample=78, buffer_id=10:4E
    db 0,0,100,0,66,127,18,27,184,1,66,18  ; n2809 t=107.681s dur=100ms, freq=440Hz, sample=66, buffer_id=12:42
    db 0,0,159,0,47,127,19,28,123,0,47,19  ; n2810 t=107.681s dur=159ms, freq=123Hz, sample=47, buffer_id=13:2F
    db 91,0,159,0,35,127,20,29,62,0,35,20  ; n2811 t=107.681s dur=159ms, freq=62Hz, sample=35, buffer_id=14:23
    db 0,0,113,0,90,127,2,0,117,5,90,2  ; n2812 t=107.772s dur=113ms, freq=1397Hz, sample=90, buffer_id=02:5A
    db 0,0,113,0,90,127,2,24,125,6,90,2  ; n2813 t=107.772s dur=113ms, freq=1661Hz, sample=90, buffer_id=02:5A
    db 0,0,113,0,78,127,3,26,186,2,78,3  ; n2814 t=107.772s dur=113ms, freq=698Hz, sample=78, buffer_id=03:4E
    db 0,0,113,0,78,127,3,30,63,3,78,3  ; n2815 t=107.772s dur=113ms, freq=831Hz, sample=78, buffer_id=03:4E
    db 0,0,113,0,78,127,4,31,186,2,78,4  ; n2816 t=107.772s dur=113ms, freq=698Hz, sample=78, buffer_id=04:4E
    db 0,0,113,0,81,127,4,9,63,3,81,4  ; n2817 t=107.772s dur=113ms, freq=831Hz, sample=81, buffer_id=04:51 [TRUNCATE prev:ch9 @107314.9ms -> 107771.7ms]
    db 0,0,113,0,66,127,5,1,159,1,66,5  ; n2818 t=107.772s dur=113ms, freq=415Hz, sample=66, buffer_id=05:42 [TRUNCATE prev:ch1 @107499.0ms -> 107771.7ms]
    db 0,0,113,0,66,127,6,5,93,1,66,5  ; n2819 t=107.772s dur=113ms, freq=349Hz, sample=66, buffer_id=05:42 [TRUNCATE prev:ch5 @107499.0ms -> 107771.7ms]
    db 0,0,100,0,90,127,16,2,224,6,90,16  ; n2820 t=107.772s dur=100ms, freq=1760Hz, sample=90, buffer_id=10:5A [TRUNCATE prev:ch2 @107589.9ms -> 107771.7ms]
    db 0,0,100,0,78,127,17,3,112,3,78,16  ; n2821 t=107.772s dur=100ms, freq=880Hz, sample=78, buffer_id=10:4E [TRUNCATE prev:ch3 @107589.9ms -> 107771.7ms]
    db 91,0,100,0,66,127,18,7,184,1,66,18  ; n2822 t=107.772s dur=100ms, freq=440Hz, sample=66, buffer_id=12:42 [TRUNCATE prev:ch7 @107499.0ms -> 107771.7ms]
    db 0,0,181,0,90,127,2,8,200,5,90,2  ; n2823 t=107.863s dur=181ms, freq=1480Hz, sample=90, buffer_id=02:5A
    db 0,0,181,0,94,127,2,22,224,6,94,2  ; n2824 t=107.863s dur=181ms, freq=1760Hz, sample=94, buffer_id=02:5E
    db 0,0,181,0,78,127,3,11,228,2,78,3  ; n2825 t=107.863s dur=181ms, freq=740Hz, sample=78, buffer_id=03:4E [TRUNCATE prev:ch11 @107680.8ms -> 107862.6ms]
    db 0,0,181,0,78,127,3,12,112,3,78,3  ; n2826 t=107.863s dur=181ms, freq=880Hz, sample=78, buffer_id=03:4E [TRUNCATE prev:ch12 @107680.8ms -> 107862.6ms]
    db 0,0,181,0,78,127,4,13,228,2,78,4  ; n2827 t=107.863s dur=181ms, freq=740Hz, sample=78, buffer_id=04:4E [TRUNCATE prev:ch13 @107680.8ms -> 107862.6ms]
    db 0,0,181,0,81,127,4,14,112,3,81,4  ; n2828 t=107.863s dur=181ms, freq=880Hz, sample=81, buffer_id=04:51 [TRUNCATE prev:ch14 @107680.8ms -> 107862.6ms]
    db 0,0,181,0,70,127,5,15,184,1,70,5  ; n2829 t=107.863s dur=181ms, freq=440Hz, sample=70, buffer_id=05:46 [TRUNCATE prev:ch15 @107680.8ms -> 107862.6ms]
    db 0,0,181,0,66,127,6,16,114,1,66,5  ; n2830 t=107.863s dur=181ms, freq=370Hz, sample=66, buffer_id=05:42 [TRUNCATE prev:ch16 @107680.8ms -> 107862.6ms]
    db 0,0,100,0,90,127,16,23,224,6,90,16  ; n2831 t=107.863s dur=100ms, freq=1760Hz, sample=90, buffer_id=10:5A [TRUNCATE prev:ch23 @107680.8ms -> 107862.6ms]
    db 0,0,100,0,78,127,17,25,112,3,78,16  ; n2832 t=107.863s dur=100ms, freq=880Hz, sample=78, buffer_id=10:4E [TRUNCATE prev:ch25 @107680.8ms -> 107862.6ms]
    db 0,0,100,0,66,127,18,4,184,1,66,18  ; n2833 t=107.863s dur=100ms, freq=440Hz, sample=66, buffer_id=12:42 [TRUNCATE prev:ch4 @107589.9ms -> 107862.6ms]
    db 0,0,159,0,47,127,19,28,110,0,47,19  ; n2834 t=107.863s dur=159ms, freq=110Hz, sample=47, buffer_id=13:2F [TRUNCATE prev:ch28 @107680.8ms -> 107862.6ms]
    db 91,0,159,0,33,127,20,6,55,0,33,20  ; n2835 t=107.863s dur=159ms, freq=55Hz, sample=33, buffer_id=14:21 [TRUNCATE prev:ch6 @107680.8ms -> 107862.6ms]
    db 0,0,100,0,90,127,16,2,224,6,90,16  ; n2836 t=107.954s dur=100ms, freq=1760Hz, sample=90, buffer_id=10:5A [TRUNCATE prev:ch2 @107771.7ms -> 107953.6ms]
    db 0,0,100,0,78,127,17,3,112,3,78,16  ; n2837 t=107.954s dur=100ms, freq=880Hz, sample=78, buffer_id=10:4E [TRUNCATE prev:ch3 @107771.7ms -> 107953.6ms]
    db 89,0,100,0,66,127,18,27,184,1,66,18  ; n2838 t=107.954s dur=100ms, freq=440Hz, sample=66, buffer_id=12:42 [TRUNCATE prev:ch27 @107680.8ms -> 107953.6ms]
    db 2,0,100,0,42,127,10,10,92,0,42,10  ; n2839 t=108.042s dur=100ms, freq=92Hz, sample=42, buffer_id=0A:2A
    db 0,0,192,2,66,127,7,17,114,1,66,7  ; n2840 t=108.044s dur=704ms, freq=370Hz, sample=66, buffer_id=07:42
    db 0,0,100,0,54,127,12,18,185,0,54,11  ; n2841 t=108.044s dur=100ms, freq=185Hz, sample=54, buffer_id=0B:36
    db 0,0,100,0,42,127,13,19,92,0,42,13  ; n2842 t=108.044s dur=100ms, freq=92Hz, sample=42, buffer_id=0D:2A
    db 0,0,159,0,90,127,16,20,200,5,90,16  ; n2843 t=108.044s dur=159ms, freq=1480Hz, sample=90, buffer_id=10:5A
    db 0,0,159,0,78,127,17,21,228,2,78,16  ; n2844 t=108.044s dur=159ms, freq=740Hz, sample=78, buffer_id=10:4E
    db 0,0,159,0,66,127,18,29,114,1,66,18  ; n2845 t=108.044s dur=159ms, freq=370Hz, sample=66, buffer_id=12:42
    db 0,0,159,0,54,127,19,0,185,0,54,19  ; n2846 t=108.044s dur=159ms, freq=185Hz, sample=54, buffer_id=13:36 [TRUNCATE prev:ch0 @107771.7ms -> 108044.5ms]
    db 78,0,159,0,42,127,20,1,92,0,42,20  ; n2847 t=108.044s dur=159ms, freq=92Hz, sample=42, buffer_id=14:2A [TRUNCATE prev:ch1 @107771.7ms -> 108044.5ms]
    db 79,0,100,0,42,127,10,5,92,0,42,10  ; n2848 t=108.123s dur=100ms, freq=92Hz, sample=42, buffer_id=0A:2A
    db 24,0,100,0,42,127,10,4,92,0,42,10  ; n2849 t=108.202s dur=100ms, freq=92Hz, sample=42, buffer_id=0A:2A
    db 0,0,159,0,90,127,16,6,125,6,90,16  ; n2850 t=108.226s dur=159ms, freq=1661Hz, sample=90, buffer_id=10:5A
    db 0,0,159,0,78,127,17,7,63,3,78,16  ; n2851 t=108.226s dur=159ms, freq=831Hz, sample=78, buffer_id=10:4E
    db 0,0,159,0,66,127,18,9,159,1,66,18  ; n2852 t=108.226s dur=159ms, freq=415Hz, sample=66, buffer_id=12:42
    db 0,0,159,0,54,127,19,23,165,0,54,19  ; n2853 t=108.226s dur=159ms, freq=165Hz, sample=54, buffer_id=13:36
    db 55,0,159,0,42,127,20,24,82,0,42,20  ; n2854 t=108.226s dur=159ms, freq=82Hz, sample=42, buffer_id=14:2A
    db 80,0,100,0,42,127,10,2,92,0,42,10  ; n2855 t=108.281s dur=100ms, freq=92Hz, sample=42, buffer_id=0A:2A
    db 47,0,100,0,42,127,10,3,92,0,42,10  ; n2856 t=108.361s dur=100ms, freq=92Hz, sample=42, buffer_id=0A:2A
    db 0,0,113,0,97,127,1,0,169,8,97,1  ; n2857 t=108.408s dur=113ms, freq=2217Hz, sample=97, buffer_id=01:61
    db 0,0,113,0,94,127,2,1,73,7,94,2  ; n2858 t=108.408s dur=113ms, freq=1865Hz, sample=94, buffer_id=02:5E
    db 0,0,107,1,90,127,2,10,200,5,90,2  ; n2859 t=108.408s dur=363ms, freq=1480Hz, sample=90, buffer_id=02:5A
    db 0,0,113,0,85,127,3,8,85,4,85,3  ; n2860 t=108.408s dur=113ms, freq=1109Hz, sample=85, buffer_id=03:55
    db 0,0,107,1,85,127,3,11,164,3,85,3  ; n2861 t=108.408s dur=363ms, freq=932Hz, sample=85, buffer_id=03:55
    db 0,0,113,0,78,127,4,12,228,2,78,4  ; n2862 t=108.408s dur=113ms, freq=740Hz, sample=78, buffer_id=04:4E
    db 0,0,107,1,73,127,4,13,42,2,73,4  ; n2863 t=108.408s dur=363ms, freq=554Hz, sample=73, buffer_id=04:49
    db 0,0,113,0,70,127,5,14,210,1,70,5  ; n2864 t=108.408s dur=113ms, freq=466Hz, sample=70, buffer_id=05:46
    db 0,0,113,0,66,127,6,15,114,1,66,5  ; n2865 t=108.408s dur=113ms, freq=370Hz, sample=66, buffer_id=05:42
    db 0,0,100,0,66,127,9,16,210,1,66,9  ; n2866 t=108.408s dur=100ms, freq=466Hz, sample=66, buffer_id=09:42
    db 0,0,100,0,78,127,9,18,228,2,78,9  ; n2867 t=108.408s dur=100ms, freq=740Hz, sample=78, buffer_id=09:4E
    db 0,0,100,0,61,127,11,19,21,1,61,11  ; n2868 t=108.408s dur=100ms, freq=277Hz, sample=61, buffer_id=0B:3D
    db 0,0,100,0,66,127,11,20,114,1,66,11  ; n2869 t=108.408s dur=100ms, freq=370Hz, sample=66, buffer_id=0B:42
    db 0,0,100,0,58,127,12,21,233,0,58,11  ; n2870 t=108.408s dur=100ms, freq=233Hz, sample=58, buffer_id=0B:3A
    db 0,0,159,0,97,127,16,22,73,7,97,16  ; n2871 t=108.408s dur=159ms, freq=1865Hz, sample=97, buffer_id=10:61
    db 0,0,159,0,85,127,17,25,164,3,85,16  ; n2872 t=108.408s dur=159ms, freq=932Hz, sample=85, buffer_id=10:55
    db 0,0,159,0,73,127,18,26,210,1,73,18  ; n2873 t=108.408s dur=159ms, freq=466Hz, sample=73, buffer_id=12:49
    db 0,0,159,0,47,127,19,27,147,0,47,19  ; n2874 t=108.408s dur=159ms, freq=147Hz, sample=47, buffer_id=13:2F
    db 33,0,159,0,35,127,20,28,73,0,35,20  ; n2875 t=108.408s dur=159ms, freq=73Hz, sample=35, buffer_id=14:23
    db 58,0,100,0,42,127,10,29,92,0,42,10  ; n2876 t=108.441s dur=100ms, freq=92Hz, sample=42, buffer_id=0A:2A
    db 0,0,113,0,94,127,1,5,73,7,94,1  ; n2877 t=108.499s dur=113ms, freq=1865Hz, sample=94, buffer_id=01:5E
    db 0,0,113,0,85,127,2,30,85,4,85,2  ; n2878 t=108.499s dur=113ms, freq=1109Hz, sample=85, buffer_id=02:55
    db 0,0,113,0,78,127,3,31,228,2,78,3  ; n2879 t=108.499s dur=113ms, freq=740Hz, sample=78, buffer_id=03:4E
    db 0,0,113,0,70,127,4,17,210,1,70,4  ; n2880 t=108.499s dur=113ms, freq=466Hz, sample=70, buffer_id=04:46 [TRUNCATE prev:ch17 @108044.5ms -> 108499.0ms]
    db 0,0,113,0,66,127,5,4,114,1,66,5  ; n2881 t=108.499s dur=113ms, freq=370Hz, sample=66, buffer_id=05:42 [TRUNCATE prev:ch4 @108202.0ms -> 108499.0ms]
    db 20,0,113,0,61,127,6,6,21,1,61,5  ; n2882 t=108.499s dur=113ms, freq=277Hz, sample=61, buffer_id=05:3D [TRUNCATE prev:ch6 @108226.3ms -> 108499.0ms]
    db 70,0,100,0,42,127,10,2,92,0,42,10  ; n2883 t=108.519s dur=100ms, freq=92Hz, sample=42, buffer_id=0A:2A [TRUNCATE prev:ch2 @108280.8ms -> 108519.5ms]
    db 0,0,100,0,97,127,1,7,169,8,97,1  ; n2884 t=108.590s dur=100ms, freq=2217Hz, sample=97, buffer_id=01:61
    db 0,0,181,0,94,127,2,9,73,7,94,2  ; n2885 t=108.590s dur=181ms, freq=1865Hz, sample=94, buffer_id=02:5E
    db 0,0,181,0,85,127,3,23,85,4,85,3  ; n2886 t=108.590s dur=181ms, freq=1109Hz, sample=85, buffer_id=03:55
    db 0,0,181,0,78,127,4,24,228,2,78,4  ; n2887 t=108.590s dur=181ms, freq=740Hz, sample=78, buffer_id=04:4E
    db 0,0,181,0,70,127,5,14,210,1,70,5  ; n2888 t=108.590s dur=181ms, freq=466Hz, sample=70, buffer_id=05:46 [TRUNCATE prev:ch14 @108408.1ms -> 108589.9ms]
    db 0,0,181,0,66,127,6,15,114,1,66,5  ; n2889 t=108.590s dur=181ms, freq=370Hz, sample=66, buffer_id=05:42 [TRUNCATE prev:ch15 @108408.1ms -> 108589.9ms]
    db 0,0,159,0,97,127,16,22,184,7,97,16  ; n2890 t=108.590s dur=159ms, freq=1976Hz, sample=97, buffer_id=10:61 [TRUNCATE prev:ch22 @108408.1ms -> 108589.9ms]
    db 0,0,159,0,85,127,17,25,220,3,85,16  ; n2891 t=108.590s dur=159ms, freq=988Hz, sample=85, buffer_id=10:55 [TRUNCATE prev:ch25 @108408.1ms -> 108589.9ms]
    db 0,0,159,0,73,127,18,26,238,1,73,18  ; n2892 t=108.590s dur=159ms, freq=494Hz, sample=73, buffer_id=12:49 [TRUNCATE prev:ch26 @108408.1ms -> 108589.9ms]
    db 0,0,159,0,47,127,19,27,139,0,47,19  ; n2893 t=108.590s dur=159ms, freq=139Hz, sample=47, buffer_id=13:2F [TRUNCATE prev:ch27 @108408.1ms -> 108589.9ms]
    db 9,0,159,0,35,127,20,28,69,0,35,20  ; n2894 t=108.590s dur=159ms, freq=69Hz, sample=35, buffer_id=14:23 [TRUNCATE prev:ch28 @108408.1ms -> 108589.9ms]
    db 80,0,100,0,42,127,10,3,92,0,42,10  ; n2895 t=108.599s dur=100ms, freq=92Hz, sample=42, buffer_id=0A:2A [TRUNCATE prev:ch3 @108361.1ms -> 108599.0ms]
    db 80,0,100,0,42,127,10,29,92,0,42,10  ; n2896 t=108.679s dur=100ms, freq=92Hz, sample=42, buffer_id=0A:2A [TRUNCATE prev:ch29 @108440.7ms -> 108679.3ms]
    db 13,0,100,0,42,127,10,0,92,0,42,10  ; n2897 t=108.759s dur=100ms, freq=92Hz, sample=42, buffer_id=0A:2A
    db 0,0,192,2,66,127,7,1,114,1,66,7  ; n2898 t=108.772s dur=704ms, freq=370Hz, sample=66, buffer_id=07:42
    db 0,0,100,0,54,127,12,8,185,0,54,11  ; n2899 t=108.772s dur=100ms, freq=185Hz, sample=54, buffer_id=0B:36
    db 0,0,100,0,42,127,13,12,92,0,42,13  ; n2900 t=108.772s dur=100ms, freq=92Hz, sample=42, buffer_id=0D:2A
    db 0,0,159,0,97,127,16,16,169,8,97,16  ; n2901 t=108.772s dur=159ms, freq=2217Hz, sample=97, buffer_id=10:61
    db 0,0,159,0,85,127,17,18,85,4,85,16  ; n2902 t=108.772s dur=159ms, freq=1109Hz, sample=85, buffer_id=10:55
    db 0,0,159,0,73,127,18,19,42,2,73,18  ; n2903 t=108.772s dur=159ms, freq=554Hz, sample=73, buffer_id=12:49
    db 0,0,159,0,54,127,19,20,185,0,54,19  ; n2904 t=108.772s dur=159ms, freq=185Hz, sample=54, buffer_id=13:36
    db 66,0,159,0,42,127,20,21,92,0,42,20  ; n2905 t=108.772s dur=159ms, freq=92Hz, sample=42, buffer_id=14:2A
    db 80,0,100,0,42,127,10,4,92,0,42,10  ; n2906 t=108.838s dur=100ms, freq=92Hz, sample=42, buffer_id=0A:2A
    db 36,0,100,0,42,127,10,5,92,0,42,10  ; n2907 t=108.917s dur=100ms, freq=92Hz, sample=42, buffer_id=0A:2A
    db 0,0,159,0,97,127,16,2,73,7,97,16  ; n2908 t=108.954s dur=159ms, freq=1865Hz, sample=97, buffer_id=10:61
    db 0,0,159,0,85,127,17,3,164,3,85,16  ; n2909 t=108.954s dur=159ms, freq=932Hz, sample=85, buffer_id=10:55
    db 0,0,159,0,73,127,18,6,210,1,73,18  ; n2910 t=108.954s dur=159ms, freq=466Hz, sample=73, buffer_id=12:49
    db 0,0,159,0,54,127,19,7,165,0,54,19  ; n2911 t=108.954s dur=159ms, freq=165Hz, sample=54, buffer_id=13:36
    db 42,0,159,0,42,127,20,17,82,0,42,20  ; n2912 t=108.954s dur=159ms, freq=82Hz, sample=42, buffer_id=14:2A
    db 80,0,100,0,42,127,10,9,92,0,42,10  ; n2913 t=108.996s dur=100ms, freq=92Hz, sample=42, buffer_id=0A:2A
    db 59,0,100,0,42,127,10,8,92,0,42,10  ; n2914 t=109.076s dur=100ms, freq=92Hz, sample=42, buffer_id=0A:2A
    db 0,0,113,0,97,127,1,0,169,8,97,1  ; n2915 t=109.135s dur=113ms, freq=2217Hz, sample=97, buffer_id=01:61
    db 0,0,113,0,94,127,2,10,73,7,94,2  ; n2916 t=109.135s dur=113ms, freq=1865Hz, sample=94, buffer_id=02:5E
    db 0,0,107,1,90,127,2,11,200,5,90,2  ; n2917 t=109.135s dur=363ms, freq=1480Hz, sample=90, buffer_id=02:5A
    db 0,0,113,0,85,127,3,12,85,4,85,3  ; n2918 t=109.135s dur=113ms, freq=1109Hz, sample=85, buffer_id=03:55
    db 0,0,107,1,85,127,3,13,164,3,85,3  ; n2919 t=109.135s dur=363ms, freq=932Hz, sample=85, buffer_id=03:55
    db 0,0,113,0,78,127,4,14,228,2,78,4  ; n2920 t=109.135s dur=113ms, freq=740Hz, sample=78, buffer_id=04:4E
    db 0,0,107,1,73,127,4,15,42,2,73,4  ; n2921 t=109.135s dur=363ms, freq=554Hz, sample=73, buffer_id=04:49
    db 0,0,113,0,70,127,5,16,210,1,70,5  ; n2922 t=109.135s dur=113ms, freq=466Hz, sample=70, buffer_id=05:46
    db 0,0,113,0,66,127,6,18,114,1,66,5  ; n2923 t=109.135s dur=113ms, freq=370Hz, sample=66, buffer_id=05:42
    db 0,0,100,0,66,127,9,19,210,1,66,9  ; n2924 t=109.135s dur=100ms, freq=466Hz, sample=66, buffer_id=09:42
    db 0,0,100,0,78,127,9,20,228,2,78,9  ; n2925 t=109.135s dur=100ms, freq=740Hz, sample=78, buffer_id=09:4E
    db 0,0,100,0,61,127,11,21,21,1,61,11  ; n2926 t=109.135s dur=100ms, freq=277Hz, sample=61, buffer_id=0B:3D
    db 0,0,100,0,66,127,11,22,114,1,66,11  ; n2927 t=109.135s dur=100ms, freq=370Hz, sample=66, buffer_id=0B:42
    db 0,0,100,0,58,127,12,23,233,0,58,11  ; n2928 t=109.135s dur=100ms, freq=233Hz, sample=58, buffer_id=0B:3A
    db 0,0,100,0,97,127,16,24,169,8,97,16  ; n2929 t=109.135s dur=100ms, freq=2217Hz, sample=97, buffer_id=10:61
    db 0,0,100,0,85,127,17,26,85,4,85,16  ; n2930 t=109.135s dur=100ms, freq=1109Hz, sample=85, buffer_id=10:55
    db 0,0,100,0,73,127,18,25,42,2,73,18  ; n2931 t=109.135s dur=100ms, freq=554Hz, sample=73, buffer_id=12:49
    db 0,0,159,0,47,127,19,28,147,0,47,19  ; n2932 t=109.135s dur=159ms, freq=147Hz, sample=47, buffer_id=13:2F
    db 20,0,159,0,35,127,20,27,73,0,35,20  ; n2933 t=109.135s dur=159ms, freq=73Hz, sample=35, buffer_id=14:23
    db 70,0,100,0,42,127,10,30,92,0,42,10  ; n2934 t=109.156s dur=100ms, freq=92Hz, sample=42, buffer_id=0A:2A
    db 0,0,113,0,94,127,1,4,73,7,94,1  ; n2935 t=109.226s dur=113ms, freq=1865Hz, sample=94, buffer_id=01:5E
    db 0,0,113,0,85,127,2,5,85,4,85,2  ; n2936 t=109.226s dur=113ms, freq=1109Hz, sample=85, buffer_id=02:55
    db 0,0,113,0,78,127,3,29,228,2,78,3  ; n2937 t=109.226s dur=113ms, freq=740Hz, sample=78, buffer_id=03:4E
    db 0,0,113,0,70,127,4,31,210,1,70,4  ; n2938 t=109.226s dur=113ms, freq=466Hz, sample=70, buffer_id=04:46
    db 0,0,113,0,66,127,5,1,114,1,66,5  ; n2939 t=109.226s dur=113ms, freq=370Hz, sample=66, buffer_id=05:42 [TRUNCATE prev:ch1 @108771.7ms -> 109226.3ms]
    db 0,0,113,0,61,127,6,2,21,1,61,5  ; n2940 t=109.226s dur=113ms, freq=277Hz, sample=61, buffer_id=05:3D [TRUNCATE prev:ch2 @108953.6ms -> 109226.3ms]
    db 0,0,100,0,97,127,16,3,169,8,97,16  ; n2941 t=109.226s dur=100ms, freq=2217Hz, sample=97, buffer_id=10:61 [TRUNCATE prev:ch3 @108953.6ms -> 109226.3ms]
    db 0,0,100,0,85,127,17,6,85,4,85,16  ; n2942 t=109.226s dur=100ms, freq=1109Hz, sample=85, buffer_id=10:55 [TRUNCATE prev:ch6 @108953.6ms -> 109226.3ms]
    db 9,0,100,0,73,127,18,7,42,2,73,18  ; n2943 t=109.226s dur=100ms, freq=554Hz, sample=73, buffer_id=12:49 [TRUNCATE prev:ch7 @108953.6ms -> 109226.3ms]
    db 80,0,100,0,42,127,10,9,92,0,42,10  ; n2944 t=109.235s dur=100ms, freq=92Hz, sample=42, buffer_id=0A:2A [TRUNCATE prev:ch9 @108996.0ms -> 109235.4ms]
    db 1,0,100,0,42,127,10,17,92,0,42,10  ; n2945 t=109.316s dur=100ms, freq=92Hz, sample=42, buffer_id=0A:2A
    db 0,0,100,0,97,127,1,0,169,8,97,1  ; n2946 t=109.317s dur=100ms, freq=2217Hz, sample=97, buffer_id=01:61 [TRUNCATE prev:ch0 @109135.4ms -> 109317.2ms]
    db 0,0,181,0,94,127,2,10,73,7,94,2  ; n2947 t=109.317s dur=181ms, freq=1865Hz, sample=94, buffer_id=02:5E [TRUNCATE prev:ch10 @109135.4ms -> 109317.2ms]
    db 0,0,181,0,85,127,3,12,85,4,85,3  ; n2948 t=109.317s dur=181ms, freq=1109Hz, sample=85, buffer_id=03:55 [TRUNCATE prev:ch12 @109135.4ms -> 109317.2ms]
    db 0,0,181,0,78,127,4,14,228,2,78,4  ; n2949 t=109.317s dur=181ms, freq=740Hz, sample=78, buffer_id=04:4E [TRUNCATE prev:ch14 @109135.4ms -> 109317.2ms]
    db 0,0,181,0,70,127,5,16,210,1,70,5  ; n2950 t=109.317s dur=181ms, freq=466Hz, sample=70, buffer_id=05:46 [TRUNCATE prev:ch16 @109135.4ms -> 109317.2ms]
    db 0,0,181,0,66,127,6,18,114,1,66,5  ; n2951 t=109.317s dur=181ms, freq=370Hz, sample=66, buffer_id=05:42 [TRUNCATE prev:ch18 @109135.4ms -> 109317.2ms]
    db 0,0,100,0,97,127,16,24,169,8,97,16  ; n2952 t=109.317s dur=100ms, freq=2217Hz, sample=97, buffer_id=10:61 [TRUNCATE prev:ch24 @109135.4ms -> 109317.2ms]
    db 0,0,100,0,85,127,17,26,85,4,85,16  ; n2953 t=109.317s dur=100ms, freq=1109Hz, sample=85, buffer_id=10:55 [TRUNCATE prev:ch26 @109135.4ms -> 109317.2ms]
    db 0,0,100,0,73,127,18,25,42,2,73,18  ; n2954 t=109.317s dur=100ms, freq=554Hz, sample=73, buffer_id=12:49 [TRUNCATE prev:ch25 @109135.4ms -> 109317.2ms]
    db 0,0,159,0,47,127,19,28,139,0,47,19  ; n2955 t=109.317s dur=159ms, freq=139Hz, sample=47, buffer_id=13:2F [TRUNCATE prev:ch28 @109135.4ms -> 109317.2ms]
    db 78,0,159,0,35,127,20,27,69,0,35,20  ; n2956 t=109.317s dur=159ms, freq=69Hz, sample=35, buffer_id=14:23 [TRUNCATE prev:ch27 @109135.4ms -> 109317.2ms]
    db 13,0,100,0,42,127,10,8,92,0,42,10  ; n2957 t=109.395s dur=100ms, freq=92Hz, sample=42, buffer_id=0A:2A [TRUNCATE prev:ch8 @109076.3ms -> 109395.2ms]
    db 0,0,100,0,97,127,16,3,169,8,97,16  ; n2958 t=109.408s dur=100ms, freq=2217Hz, sample=97, buffer_id=10:61 [TRUNCATE prev:ch3 @109226.3ms -> 109408.1ms]
    db 0,0,100,0,85,127,17,6,85,4,85,16  ; n2959 t=109.408s dur=100ms, freq=1109Hz, sample=85, buffer_id=10:55 [TRUNCATE prev:ch6 @109226.3ms -> 109408.1ms]
    db 65,0,100,0,73,127,18,7,42,2,73,18  ; n2960 t=109.408s dur=100ms, freq=554Hz, sample=73, buffer_id=12:49 [TRUNCATE prev:ch7 @109226.3ms -> 109408.1ms]
    db 26,0,100,0,42,127,10,19,92,0,42,10  ; n2961 t=109.473s dur=100ms, freq=92Hz, sample=42, buffer_id=0A:2A
    db 0,0,120,0,62,127,7,20,38,1,62,7  ; n2962 t=109.499s dur=120ms, freq=294Hz, sample=62, buffer_id=07:3E
    db 0,0,100,0,50,127,12,21,147,0,50,11  ; n2963 t=109.499s dur=100ms, freq=147Hz, sample=50, buffer_id=0B:32
    db 0,0,100,0,35,127,13,22,73,0,35,13  ; n2964 t=109.499s dur=100ms, freq=73Hz, sample=35, buffer_id=0D:23
    db 0,0,159,0,98,127,16,23,45,9,98,16  ; n2965 t=109.499s dur=159ms, freq=2349Hz, sample=98, buffer_id=10:62
    db 0,0,159,0,86,127,17,30,151,4,86,16  ; n2966 t=109.499s dur=159ms, freq=1175Hz, sample=86, buffer_id=10:56
    db 0,0,159,0,74,127,18,11,75,2,74,18  ; n2967 t=109.499s dur=159ms, freq=587Hz, sample=74, buffer_id=12:4A [TRUNCATE prev:ch11 @109135.4ms -> 109499.0ms]
    db 0,0,159,0,47,127,19,28,147,0,47,19  ; n2968 t=109.499s dur=159ms, freq=147Hz, sample=47, buffer_id=13:2F [TRUNCATE prev:ch28 @109317.2ms -> 109499.0ms]
    db 55,0,159,0,35,127,20,27,73,0,35,20  ; n2969 t=109.499s dur=159ms, freq=73Hz, sample=35, buffer_id=14:23 [TRUNCATE prev:ch27 @109317.2ms -> 109499.0ms]
    db 79,0,100,0,42,127,10,1,92,0,42,10  ; n2970 t=109.554s dur=100ms, freq=92Hz, sample=42, buffer_id=0A:2A
    db 48,0,100,0,42,127,10,0,92,0,42,10  ; n2971 t=109.633s dur=100ms, freq=92Hz, sample=42, buffer_id=0A:2A
    db 0,0,159,0,97,127,16,2,73,7,97,16  ; n2972 t=109.681s dur=159ms, freq=1865Hz, sample=97, buffer_id=10:61
    db 0,0,159,0,85,127,17,4,164,3,85,16  ; n2973 t=109.681s dur=159ms, freq=932Hz, sample=85, buffer_id=10:55
    db 0,0,159,0,73,127,18,5,210,1,73,18  ; n2974 t=109.681s dur=159ms, freq=466Hz, sample=73, buffer_id=12:49
    db 0,0,159,0,47,127,19,9,139,0,47,19  ; n2975 t=109.681s dur=159ms, freq=139Hz, sample=47, buffer_id=13:2F
    db 33,0,159,0,35,127,20,17,69,0,35,20  ; n2976 t=109.681s dur=159ms, freq=69Hz, sample=35, buffer_id=14:23
    db 79,0,100,0,42,127,10,3,92,0,42,10  ; n2977 t=109.713s dur=100ms, freq=92Hz, sample=42, buffer_id=0A:2A
    db 70,0,100,0,42,127,10,6,92,0,42,10  ; n2978 t=109.792s dur=100ms, freq=92Hz, sample=42, buffer_id=0A:2A
    db 0,0,113,0,98,127,1,1,45,9,98,1  ; n2979 t=109.863s dur=113ms, freq=2349Hz, sample=98, buffer_id=01:62
    db 0,0,113,0,94,127,2,7,73,7,94,2  ; n2980 t=109.863s dur=113ms, freq=1865Hz, sample=94, buffer_id=02:5E
    db 0,0,107,1,90,127,2,8,200,5,90,2  ; n2981 t=109.863s dur=363ms, freq=1480Hz, sample=90, buffer_id=02:5A
    db 0,0,113,0,86,127,3,10,151,4,86,3  ; n2982 t=109.863s dur=113ms, freq=1175Hz, sample=86, buffer_id=03:56
    db 0,0,107,1,85,127,3,11,164,3,85,3  ; n2983 t=109.863s dur=363ms, freq=932Hz, sample=85, buffer_id=03:55
    db 0,0,113,0,78,127,4,12,228,2,78,4  ; n2984 t=109.863s dur=113ms, freq=740Hz, sample=78, buffer_id=04:4E
    db 0,0,107,1,74,127,4,13,75,2,74,4  ; n2985 t=109.863s dur=363ms, freq=587Hz, sample=74, buffer_id=04:4A
    db 0,0,113,0,70,127,5,14,210,1,70,5  ; n2986 t=109.863s dur=113ms, freq=466Hz, sample=70, buffer_id=05:46
    db 0,0,113,0,66,127,6,15,114,1,66,5  ; n2987 t=109.863s dur=113ms, freq=370Hz, sample=66, buffer_id=05:42
    db 0,0,100,0,66,127,9,16,210,1,66,9  ; n2988 t=109.863s dur=100ms, freq=466Hz, sample=66, buffer_id=09:42
    db 0,0,100,0,78,127,9,18,228,2,78,9  ; n2989 t=109.863s dur=100ms, freq=740Hz, sample=78, buffer_id=09:4E
    db 0,0,100,0,62,127,11,19,38,1,62,11  ; n2990 t=109.863s dur=100ms, freq=294Hz, sample=62, buffer_id=0B:3E
    db 0,0,100,0,66,127,11,20,114,1,66,11  ; n2991 t=109.863s dur=100ms, freq=370Hz, sample=66, buffer_id=0B:42
    db 0,0,100,0,58,127,12,21,233,0,58,11  ; n2992 t=109.863s dur=100ms, freq=233Hz, sample=58, buffer_id=0B:3A
    db 0,0,100,0,98,127,16,22,45,9,98,16  ; n2993 t=109.863s dur=100ms, freq=2349Hz, sample=98, buffer_id=10:62
    db 0,0,100,0,86,127,17,23,151,4,86,16  ; n2994 t=109.863s dur=100ms, freq=1175Hz, sample=86, buffer_id=10:56
    db 0,0,100,0,74,127,18,24,75,2,74,18  ; n2995 t=109.863s dur=100ms, freq=587Hz, sample=74, buffer_id=12:4A
    db 0,0,159,0,47,127,19,25,147,0,47,19  ; n2996 t=109.863s dur=159ms, freq=147Hz, sample=47, buffer_id=13:2F
    db 9,0,159,0,35,127,20,26,73,0,35,20  ; n2997 t=109.863s dur=159ms, freq=73Hz, sample=35, buffer_id=14:23
    db 80,0,100,0,42,127,10,27,92,0,42,10  ; n2998 t=109.872s dur=100ms, freq=92Hz, sample=42, buffer_id=0A:2A
    db 2,0,100,0,42,127,10,28,92,0,42,10  ; n2999 t=109.951s dur=100ms, freq=92Hz, sample=42, buffer_id=0A:2A
    db 0,0,113,0,94,127,1,0,73,7,94,1  ; n3000 t=109.954s dur=113ms, freq=1865Hz, sample=94, buffer_id=01:5E
    db 0,0,113,0,86,127,2,29,151,4,86,2  ; n3001 t=109.954s dur=113ms, freq=1175Hz, sample=86, buffer_id=02:56
    db 0,0,113,0,78,127,3,30,228,2,78,3  ; n3002 t=109.954s dur=113ms, freq=740Hz, sample=78, buffer_id=03:4E
    db 0,0,113,0,70,127,4,31,210,1,70,4  ; n3003 t=109.954s dur=113ms, freq=466Hz, sample=70, buffer_id=04:46 [TRUNCATE prev:ch31 @109226.3ms -> 109953.6ms]
    db 0,0,113,0,66,127,5,2,114,1,66,5  ; n3004 t=109.954s dur=113ms, freq=370Hz, sample=66, buffer_id=05:42 [TRUNCATE prev:ch2 @109680.8ms -> 109953.6ms]
    db 0,0,113,0,62,127,6,4,38,1,62,5  ; n3005 t=109.954s dur=113ms, freq=294Hz, sample=62, buffer_id=05:3E [TRUNCATE prev:ch4 @109680.8ms -> 109953.6ms]
    db 0,0,100,0,98,127,16,5,45,9,98,16  ; n3006 t=109.954s dur=100ms, freq=2349Hz, sample=98, buffer_id=10:62 [TRUNCATE prev:ch5 @109680.8ms -> 109953.6ms]
    db 0,0,100,0,86,127,17,9,151,4,86,16  ; n3007 t=109.954s dur=100ms, freq=1175Hz, sample=86, buffer_id=10:56 [TRUNCATE prev:ch9 @109680.8ms -> 109953.6ms]
    db 77,0,100,0,74,127,18,17,75,2,74,18  ; n3008 t=109.954s dur=100ms, freq=587Hz, sample=74, buffer_id=12:4A [TRUNCATE prev:ch17 @109680.8ms -> 109953.6ms]
    db 14,0,100,0,42,127,10,3,92,0,42,10  ; n3009 t=110.031s dur=100ms, freq=92Hz, sample=42, buffer_id=0A:2A [TRUNCATE prev:ch3 @109713.4ms -> 110030.8ms]
    db 0,0,181,0,98,127,1,1,45,9,98,1  ; n3010 t=110.044s dur=181ms, freq=2349Hz, sample=98, buffer_id=01:62 [TRUNCATE prev:ch1 @109862.6ms -> 110044.5ms]
    db 0,0,181,0,94,127,2,7,73,7,94,2  ; n3011 t=110.044s dur=181ms, freq=1865Hz, sample=94, buffer_id=02:5E [TRUNCATE prev:ch7 @109862.6ms -> 110044.5ms]
    db 0,0,181,0,86,127,3,10,151,4,86,3  ; n3012 t=110.044s dur=181ms, freq=1175Hz, sample=86, buffer_id=03:56 [TRUNCATE prev:ch10 @109862.6ms -> 110044.5ms]
    db 0,0,181,0,78,127,4,12,228,2,78,4  ; n3013 t=110.044s dur=181ms, freq=740Hz, sample=78, buffer_id=04:4E [TRUNCATE prev:ch12 @109862.6ms -> 110044.5ms]
    db 0,0,181,0,70,127,5,14,210,1,70,5  ; n3014 t=110.044s dur=181ms, freq=466Hz, sample=70, buffer_id=05:46 [TRUNCATE prev:ch14 @109862.6ms -> 110044.5ms]
    db 0,0,181,0,66,127,6,15,114,1,66,5  ; n3015 t=110.044s dur=181ms, freq=370Hz, sample=66, buffer_id=05:42 [TRUNCATE prev:ch15 @109862.6ms -> 110044.5ms]
    db 0,0,100,0,98,127,16,22,45,9,98,16  ; n3016 t=110.044s dur=100ms, freq=2349Hz, sample=98, buffer_id=10:62 [TRUNCATE prev:ch22 @109862.6ms -> 110044.5ms]
    db 0,0,100,0,86,127,17,23,151,4,86,16  ; n3017 t=110.044s dur=100ms, freq=1175Hz, sample=86, buffer_id=10:56 [TRUNCATE prev:ch23 @109862.6ms -> 110044.5ms]
    db 0,0,100,0,74,127,18,24,75,2,74,18  ; n3018 t=110.044s dur=100ms, freq=587Hz, sample=74, buffer_id=12:4A [TRUNCATE prev:ch24 @109862.6ms -> 110044.5ms]
    db 0,0,159,0,54,127,19,6,165,0,54,19  ; n3019 t=110.044s dur=159ms, freq=165Hz, sample=54, buffer_id=13:36 [TRUNCATE prev:ch6 @109792.2ms -> 110044.5ms]
    db 66,0,159,0,42,127,20,8,82,0,42,20  ; n3020 t=110.044s dur=159ms, freq=82Hz, sample=42, buffer_id=14:2A [TRUNCATE prev:ch8 @109862.6ms -> 110044.5ms]
    db 25,0,100,0,42,127,10,27,92,0,42,10  ; n3021 t=110.110s dur=100ms, freq=92Hz, sample=42, buffer_id=0A:2A [TRUNCATE prev:ch27 @109871.7ms -> 110110.4ms]
    db 0,0,100,0,98,127,16,5,45,9,98,16  ; n3022 t=110.135s dur=100ms, freq=2349Hz, sample=98, buffer_id=10:62 [TRUNCATE prev:ch5 @109953.6ms -> 110135.4ms]
    db 0,0,100,0,86,127,17,9,151,4,86,16  ; n3023 t=110.135s dur=100ms, freq=1175Hz, sample=86, buffer_id=10:56 [TRUNCATE prev:ch9 @109953.6ms -> 110135.4ms]
    db 54,0,100,0,74,127,18,17,75,2,74,18  ; n3024 t=110.135s dur=100ms, freq=587Hz, sample=74, buffer_id=12:4A [TRUNCATE prev:ch17 @109953.6ms -> 110135.4ms]
    db 36,0,100,0,42,127,10,16,92,0,42,10  ; n3025 t=110.190s dur=100ms, freq=92Hz, sample=42, buffer_id=0A:2A
    db 0,0,192,2,66,127,7,18,114,1,66,7  ; n3026 t=110.226s dur=704ms, freq=370Hz, sample=66, buffer_id=07:42
    db 0,0,100,0,54,127,12,19,185,0,54,11  ; n3027 t=110.226s dur=100ms, freq=185Hz, sample=54, buffer_id=0B:36
    db 0,0,100,0,42,127,13,20,92,0,42,13  ; n3028 t=110.226s dur=100ms, freq=92Hz, sample=42, buffer_id=0D:2A
    db 0,0,159,0,97,127,16,21,169,8,97,16  ; n3029 t=110.226s dur=159ms, freq=2217Hz, sample=97, buffer_id=10:61
    db 0,0,159,0,85,127,17,25,85,4,85,16  ; n3030 t=110.226s dur=159ms, freq=1109Hz, sample=85, buffer_id=10:55
    db 0,0,159,0,73,127,18,26,42,2,73,18  ; n3031 t=110.226s dur=159ms, freq=554Hz, sample=73, buffer_id=12:49
    db 0,0,159,0,54,127,19,6,185,0,54,19  ; n3032 t=110.226s dur=159ms, freq=185Hz, sample=54, buffer_id=13:36 [TRUNCATE prev:ch6 @110044.5ms -> 110226.3ms]
    db 44,0,159,0,42,127,20,8,92,0,42,20  ; n3033 t=110.226s dur=159ms, freq=92Hz, sample=42, buffer_id=14:2A [TRUNCATE prev:ch8 @110044.5ms -> 110226.3ms]
    db 79,0,100,0,42,127,10,0,92,0,42,10  ; n3034 t=110.270s dur=100ms, freq=92Hz, sample=42, buffer_id=0A:2A
    db 59,0,100,0,42,127,10,2,92,0,42,10  ; n3035 t=110.349s dur=100ms, freq=92Hz, sample=42, buffer_id=0A:2A
    db 0,0,159,0,97,127,16,3,73,7,97,16  ; n3036 t=110.408s dur=159ms, freq=1865Hz, sample=97, buffer_id=10:61
    db 0,0,159,0,85,127,17,4,164,3,85,16  ; n3037 t=110.408s dur=159ms, freq=932Hz, sample=85, buffer_id=10:55
    db 0,0,159,0,73,127,18,22,210,1,73,18  ; n3038 t=110.408s dur=159ms, freq=466Hz, sample=73, buffer_id=12:49
    db 0,0,159,0,54,127,19,23,165,0,54,19  ; n3039 t=110.408s dur=159ms, freq=165Hz, sample=54, buffer_id=13:36
    db 21,0,159,0,42,127,20,24,82,0,42,20  ; n3040 t=110.408s dur=159ms, freq=82Hz, sample=42, buffer_id=14:2A
    db 79,0,100,0,42,127,10,1,92,0,42,10  ; n3041 t=110.429s dur=100ms, freq=92Hz, sample=42, buffer_id=0A:2A
    db 80,0,100,0,42,127,10,5,92,0,42,10  ; n3042 t=110.508s dur=100ms, freq=92Hz, sample=42, buffer_id=0A:2A
    db 2,0,100,0,42,127,10,6,92,0,42,10  ; n3043 t=110.588s dur=100ms, freq=92Hz, sample=42, buffer_id=0A:2A
    db 0,0,113,0,97,127,1,0,169,8,97,1  ; n3044 t=110.590s dur=113ms, freq=2217Hz, sample=97, buffer_id=01:61
    db 0,0,113,0,94,127,2,8,73,7,94,2  ; n3045 t=110.590s dur=113ms, freq=1865Hz, sample=94, buffer_id=02:5E
    db 0,0,107,1,90,127,2,7,200,5,90,2  ; n3046 t=110.590s dur=363ms, freq=1480Hz, sample=90, buffer_id=02:5A
    db 0,0,113,0,85,127,3,9,85,4,85,3  ; n3047 t=110.590s dur=113ms, freq=1109Hz, sample=85, buffer_id=03:55
    db 0,0,107,1,85,127,3,10,164,3,85,3  ; n3048 t=110.590s dur=363ms, freq=932Hz, sample=85, buffer_id=03:55
    db 0,0,113,0,78,127,4,11,228,2,78,4  ; n3049 t=110.590s dur=113ms, freq=740Hz, sample=78, buffer_id=04:4E
    db 0,0,107,1,73,127,4,12,42,2,73,4  ; n3050 t=110.590s dur=363ms, freq=554Hz, sample=73, buffer_id=04:49
    db 0,0,113,0,70,127,5,13,210,1,70,5  ; n3051 t=110.590s dur=113ms, freq=466Hz, sample=70, buffer_id=05:46
    db 0,0,113,0,66,127,6,14,114,1,66,5  ; n3052 t=110.590s dur=113ms, freq=370Hz, sample=66, buffer_id=05:42
    db 0,0,100,0,66,127,9,15,210,1,66,9  ; n3053 t=110.590s dur=100ms, freq=466Hz, sample=66, buffer_id=09:42
    db 0,0,100,0,78,127,9,16,228,2,78,9  ; n3054 t=110.590s dur=100ms, freq=740Hz, sample=78, buffer_id=09:4E
    db 0,0,100,0,61,127,11,17,21,1,61,11  ; n3055 t=110.590s dur=100ms, freq=277Hz, sample=61, buffer_id=0B:3D
    db 0,0,100,0,66,127,11,19,114,1,66,11  ; n3056 t=110.590s dur=100ms, freq=370Hz, sample=66, buffer_id=0B:42
    db 0,0,100,0,58,127,12,20,233,0,58,11  ; n3057 t=110.590s dur=100ms, freq=233Hz, sample=58, buffer_id=0B:3A
    db 0,0,100,0,97,127,16,25,169,8,97,16  ; n3058 t=110.590s dur=100ms, freq=2217Hz, sample=97, buffer_id=10:61
    db 0,0,100,0,85,127,17,21,85,4,85,16  ; n3059 t=110.590s dur=100ms, freq=1109Hz, sample=85, buffer_id=10:55
    db 0,0,100,0,73,127,18,27,42,2,73,18  ; n3060 t=110.590s dur=100ms, freq=554Hz, sample=73, buffer_id=12:49
    db 0,0,159,0,47,127,19,26,147,0,47,19  ; n3061 t=110.590s dur=159ms, freq=147Hz, sample=47, buffer_id=13:2F
    db 78,0,159,0,35,127,20,28,73,0,35,20  ; n3062 t=110.590s dur=159ms, freq=73Hz, sample=35, buffer_id=14:23
    db 13,0,100,0,42,127,10,29,92,0,42,10  ; n3063 t=110.668s dur=100ms, freq=92Hz, sample=42, buffer_id=0A:2A
    db 0,0,113,0,94,127,1,2,73,7,94,1  ; n3064 t=110.681s dur=113ms, freq=1865Hz, sample=94, buffer_id=01:5E
    db 0,0,113,0,85,127,2,30,85,4,85,2  ; n3065 t=110.681s dur=113ms, freq=1109Hz, sample=85, buffer_id=02:55
    db 0,0,113,0,78,127,3,31,228,2,78,3  ; n3066 t=110.681s dur=113ms, freq=740Hz, sample=78, buffer_id=03:4E
    db 0,0,113,0,70,127,4,18,210,1,70,4  ; n3067 t=110.681s dur=113ms, freq=466Hz, sample=70, buffer_id=04:46 [TRUNCATE prev:ch18 @110226.3ms -> 110680.8ms]
    db 0,0,113,0,66,127,5,3,114,1,66,5  ; n3068 t=110.681s dur=113ms, freq=370Hz, sample=66, buffer_id=05:42 [TRUNCATE prev:ch3 @110408.1ms -> 110680.8ms]
    db 0,0,113,0,61,127,6,4,21,1,61,5  ; n3069 t=110.681s dur=113ms, freq=277Hz, sample=61, buffer_id=05:3D [TRUNCATE prev:ch4 @110408.1ms -> 110680.8ms]
    db 0,0,100,0,97,127,16,22,169,8,97,16  ; n3070 t=110.681s dur=100ms, freq=2217Hz, sample=97, buffer_id=10:61 [TRUNCATE prev:ch22 @110408.1ms -> 110680.8ms]
    db 0,0,100,0,85,127,17,23,85,4,85,16  ; n3071 t=110.681s dur=100ms, freq=1109Hz, sample=85, buffer_id=10:55 [TRUNCATE prev:ch23 @110408.1ms -> 110680.8ms]
    db 66,0,100,0,73,127,18,24,42,2,73,18  ; n3072 t=110.681s dur=100ms, freq=554Hz, sample=73, buffer_id=12:49 [TRUNCATE prev:ch24 @110408.1ms -> 110680.8ms]
    db 25,0,100,0,42,127,10,1,92,0,42,10  ; n3073 t=110.747s dur=100ms, freq=92Hz, sample=42, buffer_id=0A:2A [TRUNCATE prev:ch1 @110429.3ms -> 110746.7ms]
    db 0,0,181,0,97,127,1,0,169,8,97,1  ; n3074 t=110.772s dur=181ms, freq=2217Hz, sample=97, buffer_id=01:61 [TRUNCATE prev:ch0 @110589.9ms -> 110771.7ms]
    db 0,0,181,0,94,127,2,8,73,7,94,2  ; n3075 t=110.772s dur=181ms, freq=1865Hz, sample=94, buffer_id=02:5E [TRUNCATE prev:ch8 @110589.9ms -> 110771.7ms]
    db 0,0,181,0,85,127,3,9,85,4,85,3  ; n3076 t=110.772s dur=181ms, freq=1109Hz, sample=85, buffer_id=03:55 [TRUNCATE prev:ch9 @110589.9ms -> 110771.7ms]
    db 0,0,181,0,78,127,4,11,228,2,78,4  ; n3077 t=110.772s dur=181ms, freq=740Hz, sample=78, buffer_id=04:4E [TRUNCATE prev:ch11 @110589.9ms -> 110771.7ms]
    db 0,0,181,0,70,127,5,13,210,1,70,5  ; n3078 t=110.772s dur=181ms, freq=466Hz, sample=70, buffer_id=05:46 [TRUNCATE prev:ch13 @110589.9ms -> 110771.7ms]
    db 0,0,181,0,66,127,6,14,114,1,66,5  ; n3079 t=110.772s dur=181ms, freq=370Hz, sample=66, buffer_id=05:42 [TRUNCATE prev:ch14 @110589.9ms -> 110771.7ms]
    db 0,0,100,0,97,127,16,25,169,8,97,16  ; n3080 t=110.772s dur=100ms, freq=2217Hz, sample=97, buffer_id=10:61 [TRUNCATE prev:ch25 @110589.9ms -> 110771.7ms]
    db 0,0,100,0,85,127,17,21,85,4,85,16  ; n3081 t=110.772s dur=100ms, freq=1109Hz, sample=85, buffer_id=10:55 [TRUNCATE prev:ch21 @110589.9ms -> 110771.7ms]
    db 0,0,100,0,73,127,18,27,42,2,73,18  ; n3082 t=110.772s dur=100ms, freq=554Hz, sample=73, buffer_id=12:49 [TRUNCATE prev:ch27 @110589.9ms -> 110771.7ms]
    db 0,0,159,0,47,127,19,26,139,0,47,19  ; n3083 t=110.772s dur=159ms, freq=139Hz, sample=47, buffer_id=13:2F [TRUNCATE prev:ch26 @110589.9ms -> 110771.7ms]
    db 54,0,159,0,35,127,20,28,69,0,35,20  ; n3084 t=110.772s dur=159ms, freq=69Hz, sample=35, buffer_id=14:23 [TRUNCATE prev:ch28 @110589.9ms -> 110771.7ms]
    db 37,0,100,0,42,127,10,5,92,0,42,10  ; n3085 t=110.826s dur=100ms, freq=92Hz, sample=42, buffer_id=0A:2A [TRUNCATE prev:ch5 @110508.1ms -> 110825.5ms]
    db 0,0,100,0,97,127,16,22,169,8,97,16  ; n3086 t=110.863s dur=100ms, freq=2217Hz, sample=97, buffer_id=10:61 [TRUNCATE prev:ch22 @110680.8ms -> 110862.6ms]
    db 0,0,100,0,85,127,17,23,85,4,85,16  ; n3087 t=110.863s dur=100ms, freq=1109Hz, sample=85, buffer_id=10:55 [TRUNCATE prev:ch23 @110680.8ms -> 110862.6ms]
    db 89,0,100,0,73,127,18,24,42,2,73,18  ; n3088 t=110.863s dur=100ms, freq=554Hz, sample=73, buffer_id=12:49 [TRUNCATE prev:ch24 @110680.8ms -> 110862.6ms]
    db 2,0,159,0,42,127,10,15,92,0,42,10  ; n3089 t=110.951s dur=159ms, freq=92Hz, sample=42, buffer_id=0A:2A
    db 0,0,100,0,54,127,7,6,185,0,54,7  ; n3090 t=110.954s dur=100ms, freq=185Hz, sample=54, buffer_id=07:36
    db 0,0,100,0,66,127,7,16,114,1,66,7  ; n3091 t=110.954s dur=100ms, freq=370Hz, sample=66, buffer_id=07:42
    db 0,0,100,0,66,127,9,17,114,1,66,9  ; n3092 t=110.954s dur=100ms, freq=370Hz, sample=66, buffer_id=09:42
    db 0,0,100,0,78,127,9,19,228,2,78,9  ; n3093 t=110.954s dur=100ms, freq=740Hz, sample=78, buffer_id=09:4E
    db 0,0,100,0,54,127,12,20,185,0,54,11  ; n3094 t=110.954s dur=100ms, freq=185Hz, sample=54, buffer_id=0B:36
    db 0,0,100,0,42,127,13,7,92,0,42,13  ; n3095 t=110.954s dur=100ms, freq=92Hz, sample=42, buffer_id=0D:2A [TRUNCATE prev:ch7 @110589.9ms -> 110953.5ms]
    db 0,0,159,0,90,127,16,10,200,5,90,16  ; n3096 t=110.954s dur=159ms, freq=1480Hz, sample=90, buffer_id=10:5A [TRUNCATE prev:ch10 @110589.9ms -> 110953.5ms]
    db 0,0,159,0,78,127,17,12,228,2,78,16  ; n3097 t=110.954s dur=159ms, freq=740Hz, sample=78, buffer_id=10:4E [TRUNCATE prev:ch12 @110589.9ms -> 110953.5ms]
    db 0,0,159,0,66,127,18,29,114,1,66,18  ; n3098 t=110.954s dur=159ms, freq=370Hz, sample=66, buffer_id=12:42 [TRUNCATE prev:ch29 @110667.9ms -> 110953.5ms]
    db 0,0,159,0,54,127,19,2,185,0,54,19  ; n3099 t=110.954s dur=159ms, freq=185Hz, sample=54, buffer_id=13:36 [TRUNCATE prev:ch2 @110680.8ms -> 110953.5ms]
    db 180,0,159,0,42,127,20,3,92,0,42,20  ; n3100 t=110.954s dur=159ms, freq=92Hz, sample=42, buffer_id=14:2A [TRUNCATE prev:ch3 @110680.8ms -> 110953.5ms]
    db 2,0,159,0,42,127,10,4,92,0,42,10  ; n3101 t=111.133s dur=159ms, freq=92Hz, sample=42, buffer_id=0A:2A
    db 0,0,100,0,57,127,7,1,208,0,57,7  ; n3102 t=111.135s dur=100ms, freq=208Hz, sample=57, buffer_id=07:39
    db 0,0,100,0,66,127,7,5,114,1,66,7  ; n3103 t=111.135s dur=100ms, freq=370Hz, sample=66, buffer_id=07:42
    db 0,0,100,0,66,127,9,18,159,1,66,9  ; n3104 t=111.135s dur=100ms, freq=415Hz, sample=66, buffer_id=09:42
    db 0,0,100,0,78,127,9,21,228,2,78,9  ; n3105 t=111.135s dur=100ms, freq=740Hz, sample=78, buffer_id=09:4E
    db 0,0,159,0,90,127,16,25,125,6,90,16  ; n3106 t=111.135s dur=159ms, freq=1661Hz, sample=90, buffer_id=10:5A
    db 0,0,159,0,78,127,17,26,63,3,78,16  ; n3107 t=111.135s dur=159ms, freq=831Hz, sample=78, buffer_id=10:4E
    db 0,0,159,0,66,127,18,27,159,1,66,18  ; n3108 t=111.135s dur=159ms, freq=415Hz, sample=66, buffer_id=12:42
    db 0,0,159,0,54,127,19,28,165,0,54,19  ; n3109 t=111.135s dur=159ms, freq=165Hz, sample=54, buffer_id=13:36
    db 179,0,159,0,42,127,20,30,82,0,42,20  ; n3110 t=111.135s dur=159ms, freq=82Hz, sample=42, buffer_id=14:2A
    db 2,0,159,0,42,127,10,0,92,0,42,10  ; n3111 t=111.315s dur=159ms, freq=92Hz, sample=42, buffer_id=0A:2A
    db 0,0,113,0,97,127,1,2,169,8,97,1  ; n3112 t=111.317s dur=113ms, freq=2217Hz, sample=97, buffer_id=01:61
    db 0,0,113,0,94,127,2,3,73,7,94,2  ; n3113 t=111.317s dur=113ms, freq=1865Hz, sample=94, buffer_id=02:5E
    db 0,0,107,1,90,127,2,6,200,5,90,2  ; n3114 t=111.317s dur=363ms, freq=1480Hz, sample=90, buffer_id=02:5A
    db 0,0,113,0,85,127,3,7,85,4,85,3  ; n3115 t=111.317s dur=113ms, freq=1109Hz, sample=85, buffer_id=03:55
    db 0,0,107,1,85,127,3,8,164,3,85,3  ; n3116 t=111.317s dur=363ms, freq=932Hz, sample=85, buffer_id=03:55
    db 0,0,113,0,78,127,4,9,228,2,78,4  ; n3117 t=111.317s dur=113ms, freq=740Hz, sample=78, buffer_id=04:4E
    db 0,0,107,1,73,127,4,10,42,2,73,4  ; n3118 t=111.317s dur=363ms, freq=554Hz, sample=73, buffer_id=04:49
    db 0,0,113,0,70,127,5,11,210,1,70,5  ; n3119 t=111.317s dur=113ms, freq=466Hz, sample=70, buffer_id=05:46
    db 0,0,113,0,66,127,6,12,114,1,66,5  ; n3120 t=111.317s dur=113ms, freq=370Hz, sample=66, buffer_id=05:42
    db 0,0,100,0,58,127,7,13,233,0,58,7  ; n3121 t=111.317s dur=100ms, freq=233Hz, sample=58, buffer_id=07:3A
    db 0,0,100,0,66,127,7,14,114,1,66,7  ; n3122 t=111.317s dur=100ms, freq=370Hz, sample=66, buffer_id=07:42
    db 0,0,100,0,66,127,9,15,210,1,66,9  ; n3123 t=111.317s dur=100ms, freq=466Hz, sample=66, buffer_id=09:42
    db 0,0,100,0,78,127,9,16,228,2,78,9  ; n3124 t=111.317s dur=100ms, freq=740Hz, sample=78, buffer_id=09:4E
    db 0,0,100,0,61,127,11,17,21,1,61,11  ; n3125 t=111.317s dur=100ms, freq=277Hz, sample=61, buffer_id=0B:3D
    db 0,0,100,0,66,127,11,19,114,1,66,11  ; n3126 t=111.317s dur=100ms, freq=370Hz, sample=66, buffer_id=0B:42
    db 0,0,100,0,58,127,12,20,233,0,58,11  ; n3127 t=111.317s dur=100ms, freq=233Hz, sample=58, buffer_id=0B:3A
    db 0,0,159,0,97,127,16,23,73,7,97,16  ; n3128 t=111.317s dur=159ms, freq=1865Hz, sample=97, buffer_id=10:61
    db 0,0,159,0,85,127,17,22,164,3,85,16  ; n3129 t=111.317s dur=159ms, freq=932Hz, sample=85, buffer_id=10:55
    db 0,0,159,0,73,127,18,29,210,1,73,18  ; n3130 t=111.317s dur=159ms, freq=466Hz, sample=73, buffer_id=12:49
    db 0,0,159,0,47,127,19,24,147,0,47,19  ; n3131 t=111.317s dur=159ms, freq=147Hz, sample=47, buffer_id=13:2F
    db 91,0,159,0,35,127,20,31,73,0,35,20  ; n3132 t=111.317s dur=159ms, freq=73Hz, sample=35, buffer_id=14:23
    db 0,0,113,0,94,127,1,4,73,7,94,1  ; n3133 t=111.408s dur=113ms, freq=1865Hz, sample=94, buffer_id=01:5E [TRUNCATE prev:ch4 @111133.1ms -> 111408.1ms]
    db 0,0,113,0,85,127,2,1,85,4,85,2  ; n3134 t=111.408s dur=113ms, freq=1109Hz, sample=85, buffer_id=02:55 [TRUNCATE prev:ch1 @111135.4ms -> 111408.1ms]
    db 0,0,113,0,78,127,3,5,228,2,78,3  ; n3135 t=111.408s dur=113ms, freq=740Hz, sample=78, buffer_id=03:4E [TRUNCATE prev:ch5 @111135.4ms -> 111408.1ms]
    db 0,0,113,0,70,127,4,18,210,1,70,4  ; n3136 t=111.408s dur=113ms, freq=466Hz, sample=70, buffer_id=04:46 [TRUNCATE prev:ch18 @111135.4ms -> 111408.1ms]
    db 0,0,113,0,66,127,5,21,114,1,66,5  ; n3137 t=111.408s dur=113ms, freq=370Hz, sample=66, buffer_id=05:42 [TRUNCATE prev:ch21 @111135.4ms -> 111408.1ms]
    db 89,0,113,0,61,127,6,25,21,1,61,5  ; n3138 t=111.408s dur=113ms, freq=277Hz, sample=61, buffer_id=05:3D [TRUNCATE prev:ch25 @111135.4ms -> 111408.1ms]
    db 2,0,159,0,42,127,10,26,92,0,42,10  ; n3139 t=111.497s dur=159ms, freq=92Hz, sample=42, buffer_id=0A:2A
    db 0,0,100,0,97,127,1,27,169,8,97,1  ; n3140 t=111.499s dur=100ms, freq=2217Hz, sample=97, buffer_id=01:61
    db 0,0,181,0,94,127,2,28,73,7,94,2  ; n3141 t=111.499s dur=181ms, freq=1865Hz, sample=94, buffer_id=02:5E
    db 0,0,181,0,85,127,3,30,85,4,85,3  ; n3142 t=111.499s dur=181ms, freq=1109Hz, sample=85, buffer_id=03:55
    db 0,0,181,0,78,127,4,9,228,2,78,4  ; n3143 t=111.499s dur=181ms, freq=740Hz, sample=78, buffer_id=04:4E [TRUNCATE prev:ch9 @111317.2ms -> 111499.0ms]
    db 0,0,181,0,70,127,5,11,210,1,70,5  ; n3144 t=111.499s dur=181ms, freq=466Hz, sample=70, buffer_id=05:46 [TRUNCATE prev:ch11 @111317.2ms -> 111499.0ms]
    db 0,0,181,0,66,127,6,12,114,1,66,5  ; n3145 t=111.499s dur=181ms, freq=370Hz, sample=66, buffer_id=05:42 [TRUNCATE prev:ch12 @111317.2ms -> 111499.0ms]
    db 0,0,100,0,59,127,7,0,247,0,59,7  ; n3146 t=111.499s dur=100ms, freq=247Hz, sample=59, buffer_id=07:3B [TRUNCATE prev:ch0 @111314.9ms -> 111499.0ms]
    db 0,0,100,0,66,127,7,14,114,1,66,7  ; n3147 t=111.499s dur=100ms, freq=370Hz, sample=66, buffer_id=07:42 [TRUNCATE prev:ch14 @111317.2ms -> 111499.0ms]
    db 0,0,100,0,66,127,9,15,238,1,66,9  ; n3148 t=111.499s dur=100ms, freq=494Hz, sample=66, buffer_id=09:42 [TRUNCATE prev:ch15 @111317.2ms -> 111499.0ms]
    db 0,0,100,0,78,127,9,16,228,2,78,9  ; n3149 t=111.499s dur=100ms, freq=740Hz, sample=78, buffer_id=09:4E [TRUNCATE prev:ch16 @111317.2ms -> 111499.0ms]
    db 0,0,159,0,97,127,16,23,184,7,97,16  ; n3150 t=111.499s dur=159ms, freq=1976Hz, sample=97, buffer_id=10:61 [TRUNCATE prev:ch23 @111317.2ms -> 111499.0ms]
    db 0,0,159,0,85,127,17,22,220,3,85,16  ; n3151 t=111.499s dur=159ms, freq=988Hz, sample=85, buffer_id=10:55 [TRUNCATE prev:ch22 @111317.2ms -> 111499.0ms]
    db 0,0,159,0,73,127,18,29,238,1,73,18  ; n3152 t=111.499s dur=159ms, freq=494Hz, sample=73, buffer_id=12:49 [TRUNCATE prev:ch29 @111317.2ms -> 111499.0ms]
    db 0,0,159,0,47,127,19,24,139,0,47,19  ; n3153 t=111.499s dur=159ms, freq=139Hz, sample=47, buffer_id=13:2F [TRUNCATE prev:ch24 @111317.2ms -> 111499.0ms]
    db 180,0,159,0,35,127,20,31,69,0,35,20  ; n3154 t=111.499s dur=159ms, freq=69Hz, sample=35, buffer_id=14:23 [TRUNCATE prev:ch31 @111317.2ms -> 111499.0ms]
    db 2,0,159,0,42,127,10,2,92,0,42,10  ; n3155 t=111.678s dur=159ms, freq=92Hz, sample=42, buffer_id=0A:2A
    db 0,0,100,0,61,127,7,3,21,1,61,7  ; n3156 t=111.681s dur=100ms, freq=277Hz, sample=61, buffer_id=07:3D
    db 0,0,100,0,66,127,7,7,114,1,66,7  ; n3157 t=111.681s dur=100ms, freq=370Hz, sample=66, buffer_id=07:42
    db 0,0,100,0,78,127,9,13,42,2,78,9  ; n3158 t=111.681s dur=100ms, freq=554Hz, sample=78, buffer_id=09:4E
    db 0,0,100,0,78,127,9,17,228,2,78,9  ; n3159 t=111.681s dur=100ms, freq=740Hz, sample=78, buffer_id=09:4E
    db 0,0,100,0,54,127,12,19,185,0,54,11  ; n3160 t=111.681s dur=100ms, freq=185Hz, sample=54, buffer_id=0B:36
    db 0,0,100,0,42,127,13,20,92,0,42,13  ; n3161 t=111.681s dur=100ms, freq=92Hz, sample=42, buffer_id=0D:2A
    db 0,0,159,0,97,127,16,23,169,8,97,16  ; n3162 t=111.681s dur=159ms, freq=2217Hz, sample=97, buffer_id=10:61 [TRUNCATE prev:ch23 @111499.0ms -> 111680.8ms]
    db 0,0,159,0,85,127,17,22,85,4,85,16  ; n3163 t=111.681s dur=159ms, freq=1109Hz, sample=85, buffer_id=10:55 [TRUNCATE prev:ch22 @111499.0ms -> 111680.8ms]
    db 0,0,159,0,73,127,18,29,42,2,73,18  ; n3164 t=111.681s dur=159ms, freq=554Hz, sample=73, buffer_id=12:49 [TRUNCATE prev:ch29 @111499.0ms -> 111680.8ms]
    db 0,0,159,0,54,127,19,6,185,0,54,19  ; n3165 t=111.681s dur=159ms, freq=185Hz, sample=54, buffer_id=13:36 [TRUNCATE prev:ch6 @111317.2ms -> 111680.8ms]
    db 180,0,159,0,42,127,20,8,92,0,42,20  ; n3166 t=111.681s dur=159ms, freq=92Hz, sample=42, buffer_id=14:2A [TRUNCATE prev:ch8 @111317.2ms -> 111680.8ms]
    db 2,0,159,0,42,127,10,0,92,0,42,10  ; n3167 t=111.860s dur=159ms, freq=92Hz, sample=42, buffer_id=0A:2A
    db 0,0,100,0,58,127,7,1,233,0,58,7  ; n3168 t=111.863s dur=100ms, freq=233Hz, sample=58, buffer_id=07:3A
    db 0,0,100,0,66,127,7,4,114,1,66,7  ; n3169 t=111.863s dur=100ms, freq=370Hz, sample=66, buffer_id=07:42
    db 0,0,100,0,66,127,9,5,210,1,66,9  ; n3170 t=111.863s dur=100ms, freq=466Hz, sample=66, buffer_id=09:42
    db 0,0,100,0,78,127,9,14,228,2,78,9  ; n3171 t=111.863s dur=100ms, freq=740Hz, sample=78, buffer_id=09:4E
    db 0,0,159,0,97,127,16,15,73,7,97,16  ; n3172 t=111.863s dur=159ms, freq=1865Hz, sample=97, buffer_id=10:61
    db 0,0,159,0,85,127,17,16,164,3,85,16  ; n3173 t=111.863s dur=159ms, freq=932Hz, sample=85, buffer_id=10:55
    db 0,0,159,0,73,127,18,18,210,1,73,18  ; n3174 t=111.863s dur=159ms, freq=466Hz, sample=73, buffer_id=12:49
    db 0,0,159,0,54,127,19,21,165,0,54,19  ; n3175 t=111.863s dur=159ms, freq=165Hz, sample=54, buffer_id=13:36
    db 180,0,159,0,42,127,20,24,82,0,42,20  ; n3176 t=111.863s dur=159ms, freq=82Hz, sample=42, buffer_id=14:2A
    db 2,0,84,1,42,127,10,3,92,0,42,10  ; n3177 t=112.042s dur=340ms, freq=92Hz, sample=42, buffer_id=0A:2A
    db 0,0,113,0,97,127,1,2,169,8,97,1  ; n3178 t=112.044s dur=113ms, freq=2217Hz, sample=97, buffer_id=01:61
    db 0,0,113,0,94,127,2,6,73,7,94,2  ; n3179 t=112.044s dur=113ms, freq=1865Hz, sample=94, buffer_id=02:5E
    db 0,0,107,1,90,127,2,7,200,5,90,2  ; n3180 t=112.044s dur=363ms, freq=1480Hz, sample=90, buffer_id=02:5A
    db 0,0,113,0,85,127,3,8,85,4,85,3  ; n3181 t=112.044s dur=113ms, freq=1109Hz, sample=85, buffer_id=03:55
    db 0,0,107,1,85,127,3,9,164,3,85,3  ; n3182 t=112.044s dur=363ms, freq=932Hz, sample=85, buffer_id=03:55
    db 0,0,113,0,78,127,4,10,228,2,78,4  ; n3183 t=112.044s dur=113ms, freq=740Hz, sample=78, buffer_id=04:4E
    db 0,0,107,1,73,127,4,11,42,2,73,4  ; n3184 t=112.044s dur=363ms, freq=554Hz, sample=73, buffer_id=04:49
    db 0,0,113,0,70,127,5,12,210,1,70,5  ; n3185 t=112.044s dur=113ms, freq=466Hz, sample=70, buffer_id=05:46
    db 0,0,113,0,66,127,6,13,114,1,66,5  ; n3186 t=112.044s dur=113ms, freq=370Hz, sample=66, buffer_id=05:42
    db 0,0,100,0,61,127,7,17,21,1,61,7  ; n3187 t=112.044s dur=100ms, freq=277Hz, sample=61, buffer_id=07:3D
    db 0,0,100,0,66,127,7,19,114,1,66,7  ; n3188 t=112.044s dur=100ms, freq=370Hz, sample=66, buffer_id=07:42
    db 0,0,100,0,78,127,9,20,42,2,78,9  ; n3189 t=112.044s dur=100ms, freq=554Hz, sample=78, buffer_id=09:4E
    db 0,0,100,0,78,127,9,22,228,2,78,9  ; n3190 t=112.044s dur=100ms, freq=740Hz, sample=78, buffer_id=09:4E
    db 0,0,100,0,61,127,11,23,21,1,61,11  ; n3191 t=112.044s dur=100ms, freq=277Hz, sample=61, buffer_id=0B:3D
    db 0,0,100,0,66,127,11,25,114,1,66,11  ; n3192 t=112.044s dur=100ms, freq=370Hz, sample=66, buffer_id=0B:42
    db 0,0,100,0,58,127,12,26,233,0,58,11  ; n3193 t=112.044s dur=100ms, freq=233Hz, sample=58, buffer_id=0B:3A
    db 0,0,100,0,97,127,16,27,169,8,97,16  ; n3194 t=112.044s dur=100ms, freq=2217Hz, sample=97, buffer_id=10:61
    db 0,0,100,0,85,127,17,28,85,4,85,16  ; n3195 t=112.044s dur=100ms, freq=1109Hz, sample=85, buffer_id=10:55
    db 0,0,100,0,73,127,18,30,42,2,73,18  ; n3196 t=112.044s dur=100ms, freq=554Hz, sample=73, buffer_id=12:49
    db 0,0,159,0,47,127,19,29,147,0,47,19  ; n3197 t=112.044s dur=159ms, freq=147Hz, sample=47, buffer_id=13:2F
    db 91,0,159,0,35,127,20,31,73,0,35,20  ; n3198 t=112.044s dur=159ms, freq=73Hz, sample=35, buffer_id=14:23 [TRUNCATE prev:ch31 @111499.0ms -> 112044.5ms]
    db 0,0,113,0,94,127,1,0,73,7,94,1  ; n3199 t=112.135s dur=113ms, freq=1865Hz, sample=94, buffer_id=01:5E [TRUNCATE prev:ch0 @111860.4ms -> 112135.4ms]
    db 0,0,113,0,85,127,2,1,85,4,85,2  ; n3200 t=112.135s dur=113ms, freq=1109Hz, sample=85, buffer_id=02:55 [TRUNCATE prev:ch1 @111862.6ms -> 112135.4ms]
    db 0,0,113,0,78,127,3,4,228,2,78,3  ; n3201 t=112.135s dur=113ms, freq=740Hz, sample=78, buffer_id=03:4E [TRUNCATE prev:ch4 @111862.6ms -> 112135.4ms]
    db 0,0,113,0,70,127,4,5,210,1,70,4  ; n3202 t=112.135s dur=113ms, freq=466Hz, sample=70, buffer_id=04:46 [TRUNCATE prev:ch5 @111862.6ms -> 112135.4ms]
    db 0,0,113,0,66,127,5,14,114,1,66,5  ; n3203 t=112.135s dur=113ms, freq=370Hz, sample=66, buffer_id=05:42 [TRUNCATE prev:ch14 @111862.6ms -> 112135.4ms]
    db 0,0,113,0,61,127,6,15,21,1,61,5  ; n3204 t=112.135s dur=113ms, freq=277Hz, sample=61, buffer_id=05:3D [TRUNCATE prev:ch15 @111862.6ms -> 112135.4ms]
    db 0,0,100,0,97,127,16,16,169,8,97,16  ; n3205 t=112.135s dur=100ms, freq=2217Hz, sample=97, buffer_id=10:61 [TRUNCATE prev:ch16 @111862.6ms -> 112135.4ms]
    db 0,0,100,0,85,127,17,18,85,4,85,16  ; n3206 t=112.135s dur=100ms, freq=1109Hz, sample=85, buffer_id=10:55 [TRUNCATE prev:ch18 @111862.6ms -> 112135.4ms]
    db 91,0,100,0,73,127,18,21,42,2,73,18  ; n3207 t=112.135s dur=100ms, freq=554Hz, sample=73, buffer_id=12:49 [TRUNCATE prev:ch21 @111862.6ms -> 112135.4ms]
    db 0,0,100,0,97,127,1,24,169,8,97,1  ; n3208 t=112.226s dur=100ms, freq=2217Hz, sample=97, buffer_id=01:61
    db 0,0,181,0,94,127,2,6,73,7,94,2  ; n3209 t=112.226s dur=181ms, freq=1865Hz, sample=94, buffer_id=02:5E [TRUNCATE prev:ch6 @112044.5ms -> 112226.3ms]
    db 0,0,181,0,85,127,3,8,85,4,85,3  ; n3210 t=112.226s dur=181ms, freq=1109Hz, sample=85, buffer_id=03:55 [TRUNCATE prev:ch8 @112044.5ms -> 112226.3ms]
    db 0,0,181,0,78,127,4,10,228,2,78,4  ; n3211 t=112.226s dur=181ms, freq=740Hz, sample=78, buffer_id=04:4E [TRUNCATE prev:ch10 @112044.5ms -> 112226.3ms]
    db 0,0,181,0,70,127,5,12,210,1,70,5  ; n3212 t=112.226s dur=181ms, freq=466Hz, sample=70, buffer_id=05:46 [TRUNCATE prev:ch12 @112044.5ms -> 112226.3ms]
    db 0,0,181,0,66,127,6,13,114,1,66,5  ; n3213 t=112.226s dur=181ms, freq=370Hz, sample=66, buffer_id=05:42 [TRUNCATE prev:ch13 @112044.5ms -> 112226.3ms]
    db 0,0,100,0,97,127,16,27,169,8,97,16  ; n3214 t=112.226s dur=100ms, freq=2217Hz, sample=97, buffer_id=10:61 [TRUNCATE prev:ch27 @112044.5ms -> 112226.3ms]
    db 0,0,100,0,85,127,17,28,85,4,85,16  ; n3215 t=112.226s dur=100ms, freq=1109Hz, sample=85, buffer_id=10:55 [TRUNCATE prev:ch28 @112044.5ms -> 112226.3ms]
    db 0,0,100,0,73,127,18,30,42,2,73,18  ; n3216 t=112.226s dur=100ms, freq=554Hz, sample=73, buffer_id=12:49 [TRUNCATE prev:ch30 @112044.5ms -> 112226.3ms]
    db 0,0,159,0,47,127,19,29,139,0,47,19  ; n3217 t=112.226s dur=159ms, freq=139Hz, sample=47, buffer_id=13:2F [TRUNCATE prev:ch29 @112044.5ms -> 112226.3ms]
    db 91,0,159,0,35,127,20,31,69,0,35,20  ; n3218 t=112.226s dur=159ms, freq=69Hz, sample=35, buffer_id=14:23 [TRUNCATE prev:ch31 @112044.5ms -> 112226.3ms]
    db 0,0,100,0,97,127,16,16,169,8,97,16  ; n3219 t=112.317s dur=100ms, freq=2217Hz, sample=97, buffer_id=10:61 [TRUNCATE prev:ch16 @112135.4ms -> 112317.2ms]
    db 0,0,100,0,85,127,17,18,85,4,85,16  ; n3220 t=112.317s dur=100ms, freq=1109Hz, sample=85, buffer_id=10:55 [TRUNCATE prev:ch18 @112135.4ms -> 112317.2ms]
    db 89,0,100,0,73,127,18,21,42,2,73,18  ; n3221 t=112.317s dur=100ms, freq=554Hz, sample=73, buffer_id=12:49 [TRUNCATE prev:ch21 @112135.4ms -> 112317.2ms]
    db 2,0,159,0,42,127,10,2,92,0,42,10  ; n3222 t=112.406s dur=159ms, freq=92Hz, sample=42, buffer_id=0A:2A
    db 0,0,100,0,62,127,7,17,38,1,62,7  ; n3223 t=112.408s dur=100ms, freq=294Hz, sample=62, buffer_id=07:3E
    db 0,0,100,0,66,127,7,20,114,1,66,7  ; n3224 t=112.408s dur=100ms, freq=370Hz, sample=66, buffer_id=07:42
    db 0,0,100,0,78,127,9,19,75,2,78,9  ; n3225 t=112.408s dur=100ms, freq=587Hz, sample=78, buffer_id=09:4E
    db 0,0,100,0,78,127,9,23,228,2,78,9  ; n3226 t=112.408s dur=100ms, freq=740Hz, sample=78, buffer_id=09:4E
    db 0,0,100,0,50,127,12,22,147,0,50,11  ; n3227 t=112.408s dur=100ms, freq=147Hz, sample=50, buffer_id=0B:32
    db 0,0,100,0,35,127,13,25,73,0,35,13  ; n3228 t=112.408s dur=100ms, freq=73Hz, sample=35, buffer_id=0D:23
    db 0,0,159,0,98,127,16,26,45,9,98,16  ; n3229 t=112.408s dur=159ms, freq=2349Hz, sample=98, buffer_id=10:62
    db 0,0,159,0,86,127,17,3,151,4,86,16  ; n3230 t=112.408s dur=159ms, freq=1175Hz, sample=86, buffer_id=10:56 [TRUNCATE prev:ch3 @112042.2ms -> 112408.1ms]
    db 0,0,159,0,74,127,18,7,75,2,74,18  ; n3231 t=112.408s dur=159ms, freq=587Hz, sample=74, buffer_id=12:4A [TRUNCATE prev:ch7 @112044.5ms -> 112408.1ms]
    db 0,0,159,0,47,127,19,29,147,0,47,19  ; n3232 t=112.408s dur=159ms, freq=147Hz, sample=47, buffer_id=13:2F [TRUNCATE prev:ch29 @112226.3ms -> 112408.1ms]
    db 179,0,159,0,35,127,20,31,73,0,35,20  ; n3233 t=112.408s dur=159ms, freq=73Hz, sample=35, buffer_id=14:23 [TRUNCATE prev:ch31 @112226.3ms -> 112408.1ms]
    db 2,0,159,0,42,127,10,0,92,0,42,10  ; n3234 t=112.588s dur=159ms, freq=92Hz, sample=42, buffer_id=0A:2A
    db 0,0,100,0,58,127,7,1,233,0,58,7  ; n3235 t=112.590s dur=100ms, freq=233Hz, sample=58, buffer_id=07:3A
    db 0,0,100,0,66,127,7,4,114,1,66,7  ; n3236 t=112.590s dur=100ms, freq=370Hz, sample=66, buffer_id=07:42
    db 0,0,100,0,66,127,9,5,210,1,66,9  ; n3237 t=112.590s dur=100ms, freq=466Hz, sample=66, buffer_id=09:42
    db 0,0,100,0,78,127,9,14,228,2,78,9  ; n3238 t=112.590s dur=100ms, freq=740Hz, sample=78, buffer_id=09:4E
    db 0,0,159,0,97,127,16,15,73,7,97,16  ; n3239 t=112.590s dur=159ms, freq=1865Hz, sample=97, buffer_id=10:61
    db 0,0,159,0,85,127,17,24,164,3,85,16  ; n3240 t=112.590s dur=159ms, freq=932Hz, sample=85, buffer_id=10:55
    db 0,0,159,0,73,127,18,27,210,1,73,18  ; n3241 t=112.590s dur=159ms, freq=466Hz, sample=73, buffer_id=12:49
    db 0,0,159,0,47,127,19,28,139,0,47,19  ; n3242 t=112.590s dur=159ms, freq=139Hz, sample=47, buffer_id=13:2F
    db 180,0,159,0,35,127,20,30,69,0,35,20  ; n3243 t=112.590s dur=159ms, freq=69Hz, sample=35, buffer_id=14:23
    db 2,0,84,1,42,127,10,3,92,0,42,10  ; n3244 t=112.769s dur=340ms, freq=92Hz, sample=42, buffer_id=0A:2A
    db 0,0,113,0,98,127,1,2,45,9,98,1  ; n3245 t=112.772s dur=113ms, freq=2349Hz, sample=98, buffer_id=01:62
    db 0,0,113,0,94,127,2,7,73,7,94,2  ; n3246 t=112.772s dur=113ms, freq=1865Hz, sample=94, buffer_id=02:5E
    db 0,0,107,1,90,127,2,6,200,5,90,2  ; n3247 t=112.772s dur=363ms, freq=1480Hz, sample=90, buffer_id=02:5A
    db 0,0,113,0,86,127,3,8,151,4,86,3  ; n3248 t=112.772s dur=113ms, freq=1175Hz, sample=86, buffer_id=03:56
    db 0,0,107,1,85,127,3,10,164,3,85,3  ; n3249 t=112.772s dur=363ms, freq=932Hz, sample=85, buffer_id=03:55
    db 0,0,113,0,78,127,4,9,228,2,78,4  ; n3250 t=112.772s dur=113ms, freq=740Hz, sample=78, buffer_id=04:4E
    db 0,0,107,1,74,127,4,11,75,2,74,4  ; n3251 t=112.772s dur=363ms, freq=587Hz, sample=74, buffer_id=04:4A
    db 0,0,113,0,70,127,5,13,210,1,70,5  ; n3252 t=112.772s dur=113ms, freq=466Hz, sample=70, buffer_id=05:46
    db 0,0,113,0,66,127,6,12,114,1,66,5  ; n3253 t=112.772s dur=113ms, freq=370Hz, sample=66, buffer_id=05:42
    db 0,0,100,0,62,127,7,16,38,1,62,7  ; n3254 t=112.772s dur=100ms, freq=294Hz, sample=62, buffer_id=07:3E
    db 0,0,100,0,66,127,7,17,114,1,66,7  ; n3255 t=112.772s dur=100ms, freq=370Hz, sample=66, buffer_id=07:42
    db 0,0,100,0,78,127,9,18,75,2,78,9  ; n3256 t=112.772s dur=100ms, freq=587Hz, sample=78, buffer_id=09:4E
    db 0,0,100,0,78,127,9,20,228,2,78,9  ; n3257 t=112.772s dur=100ms, freq=740Hz, sample=78, buffer_id=09:4E
    db 0,0,100,0,62,127,11,19,38,1,62,11  ; n3258 t=112.772s dur=100ms, freq=294Hz, sample=62, buffer_id=0B:3E
    db 0,0,100,0,66,127,11,21,114,1,66,11  ; n3259 t=112.772s dur=100ms, freq=370Hz, sample=66, buffer_id=0B:42
    db 0,0,100,0,58,127,12,22,233,0,58,11  ; n3260 t=112.772s dur=100ms, freq=233Hz, sample=58, buffer_id=0B:3A
    db 0,0,100,0,98,127,16,23,45,9,98,16  ; n3261 t=112.772s dur=100ms, freq=2349Hz, sample=98, buffer_id=10:62
    db 0,0,100,0,86,127,17,25,151,4,86,16  ; n3262 t=112.772s dur=100ms, freq=1175Hz, sample=86, buffer_id=10:56
    db 0,0,100,0,74,127,18,26,75,2,74,18  ; n3263 t=112.772s dur=100ms, freq=587Hz, sample=74, buffer_id=12:4A
    db 0,0,159,0,47,127,19,31,147,0,47,19  ; n3264 t=112.772s dur=159ms, freq=147Hz, sample=47, buffer_id=13:2F
    db 91,0,159,0,35,127,20,29,73,0,35,20  ; n3265 t=112.772s dur=159ms, freq=73Hz, sample=35, buffer_id=14:23
    db 0,0,113,0,94,127,1,0,73,7,94,1  ; n3266 t=112.863s dur=113ms, freq=1865Hz, sample=94, buffer_id=01:5E [TRUNCATE prev:ch0 @112587.6ms -> 112862.6ms]
    db 0,0,113,0,86,127,2,1,151,4,86,2  ; n3267 t=112.863s dur=113ms, freq=1175Hz, sample=86, buffer_id=02:56 [TRUNCATE prev:ch1 @112589.9ms -> 112862.6ms]
    db 0,0,113,0,78,127,3,4,228,2,78,3  ; n3268 t=112.863s dur=113ms, freq=740Hz, sample=78, buffer_id=03:4E [TRUNCATE prev:ch4 @112589.9ms -> 112862.6ms]
    db 0,0,113,0,70,127,4,5,210,1,70,4  ; n3269 t=112.863s dur=113ms, freq=466Hz, sample=70, buffer_id=04:46 [TRUNCATE prev:ch5 @112589.9ms -> 112862.6ms]
    db 0,0,113,0,66,127,5,14,114,1,66,5  ; n3270 t=112.863s dur=113ms, freq=370Hz, sample=66, buffer_id=05:42 [TRUNCATE prev:ch14 @112589.9ms -> 112862.6ms]
    db 0,0,113,0,62,127,6,15,38,1,62,5  ; n3271 t=112.863s dur=113ms, freq=294Hz, sample=62, buffer_id=05:3E [TRUNCATE prev:ch15 @112589.9ms -> 112862.6ms]
    db 0,0,100,0,98,127,16,24,45,9,98,16  ; n3272 t=112.863s dur=100ms, freq=2349Hz, sample=98, buffer_id=10:62 [TRUNCATE prev:ch24 @112589.9ms -> 112862.6ms]
    db 0,0,100,0,86,127,17,27,151,4,86,16  ; n3273 t=112.863s dur=100ms, freq=1175Hz, sample=86, buffer_id=10:56 [TRUNCATE prev:ch27 @112589.9ms -> 112862.6ms]
    db 91,0,100,0,74,127,18,28,75,2,74,18  ; n3274 t=112.863s dur=100ms, freq=587Hz, sample=74, buffer_id=12:4A [TRUNCATE prev:ch28 @112589.9ms -> 112862.6ms]
    db 0,0,181,0,98,127,1,30,45,9,98,1  ; n3275 t=112.954s dur=181ms, freq=2349Hz, sample=98, buffer_id=01:62
    db 0,0,181,0,94,127,2,7,73,7,94,2  ; n3276 t=112.954s dur=181ms, freq=1865Hz, sample=94, buffer_id=02:5E [TRUNCATE prev:ch7 @112771.7ms -> 112953.5ms]
    db 0,0,181,0,86,127,3,8,151,4,86,3  ; n3277 t=112.954s dur=181ms, freq=1175Hz, sample=86, buffer_id=03:56 [TRUNCATE prev:ch8 @112771.7ms -> 112953.5ms]
    db 0,0,181,0,78,127,4,9,228,2,78,4  ; n3278 t=112.954s dur=181ms, freq=740Hz, sample=78, buffer_id=04:4E [TRUNCATE prev:ch9 @112771.7ms -> 112953.5ms]
    db 0,0,181,0,70,127,5,13,210,1,70,5  ; n3279 t=112.954s dur=181ms, freq=466Hz, sample=70, buffer_id=05:46 [TRUNCATE prev:ch13 @112771.7ms -> 112953.5ms]
    db 0,0,181,0,66,127,6,12,114,1,66,5  ; n3280 t=112.954s dur=181ms, freq=370Hz, sample=66, buffer_id=05:42 [TRUNCATE prev:ch12 @112771.7ms -> 112953.5ms]
    db 0,0,100,0,98,127,16,23,45,9,98,16  ; n3281 t=112.954s dur=100ms, freq=2349Hz, sample=98, buffer_id=10:62 [TRUNCATE prev:ch23 @112771.7ms -> 112953.5ms]
    db 0,0,100,0,86,127,17,25,151,4,86,16  ; n3282 t=112.954s dur=100ms, freq=1175Hz, sample=86, buffer_id=10:56 [TRUNCATE prev:ch25 @112771.7ms -> 112953.5ms]
    db 0,0,100,0,74,127,18,26,75,2,74,18  ; n3283 t=112.954s dur=100ms, freq=587Hz, sample=74, buffer_id=12:4A [TRUNCATE prev:ch26 @112771.7ms -> 112953.5ms]
    db 0,0,159,0,54,127,19,3,165,0,54,19  ; n3284 t=112.954s dur=159ms, freq=165Hz, sample=54, buffer_id=13:36 [TRUNCATE prev:ch3 @112769.5ms -> 112953.5ms]
    db 91,0,159,0,42,127,20,2,82,0,42,20  ; n3285 t=112.954s dur=159ms, freq=82Hz, sample=42, buffer_id=14:2A [TRUNCATE prev:ch2 @112771.7ms -> 112953.5ms]
    db 0,0,100,0,98,127,16,24,45,9,98,16  ; n3286 t=113.044s dur=100ms, freq=2349Hz, sample=98, buffer_id=10:62 [TRUNCATE prev:ch24 @112862.6ms -> 113044.5ms]
    db 0,0,100,0,86,127,17,27,151,4,86,16  ; n3287 t=113.044s dur=100ms, freq=1175Hz, sample=86, buffer_id=10:56 [TRUNCATE prev:ch27 @112862.6ms -> 113044.5ms]
    db 89,0,100,0,74,127,18,28,75,2,74,18  ; n3288 t=113.044s dur=100ms, freq=587Hz, sample=74, buffer_id=12:4A [TRUNCATE prev:ch28 @112862.6ms -> 113044.5ms]
    db 2,0,84,1,42,127,10,16,92,0,42,10  ; n3289 t=113.133s dur=340ms, freq=92Hz, sample=42, buffer_id=0A:2A
    db 0,0,127,0,61,127,7,17,21,1,61,7  ; n3290 t=113.135s dur=127ms, freq=277Hz, sample=61, buffer_id=07:3D
    db 0,0,192,2,66,127,7,18,114,1,66,7  ; n3291 t=113.135s dur=704ms, freq=370Hz, sample=66, buffer_id=07:42
    db 0,0,192,2,78,127,9,19,42,2,78,9  ; n3292 t=113.135s dur=704ms, freq=554Hz, sample=78, buffer_id=09:4E
    db 0,0,192,2,78,127,9,21,228,2,78,9  ; n3293 t=113.135s dur=704ms, freq=740Hz, sample=78, buffer_id=09:4E
    db 0,0,100,0,54,127,12,20,185,0,54,11  ; n3294 t=113.135s dur=100ms, freq=185Hz, sample=54, buffer_id=0B:36
    db 0,0,100,0,42,127,13,22,92,0,42,13  ; n3295 t=113.135s dur=100ms, freq=92Hz, sample=42, buffer_id=0D:2A
    db 0,0,100,0,97,127,16,29,169,8,97,16  ; n3296 t=113.135s dur=100ms, freq=2217Hz, sample=97, buffer_id=10:61
    db 0,0,100,0,85,127,17,31,85,4,85,16  ; n3297 t=113.135s dur=100ms, freq=1109Hz, sample=85, buffer_id=10:55
    db 0,0,100,0,73,127,18,6,42,2,73,18  ; n3298 t=113.135s dur=100ms, freq=554Hz, sample=73, buffer_id=12:49 [TRUNCATE prev:ch6 @112771.7ms -> 113135.4ms]
    db 0,0,159,0,54,127,19,3,185,0,54,19  ; n3299 t=113.135s dur=159ms, freq=185Hz, sample=54, buffer_id=13:36 [TRUNCATE prev:ch3 @112953.5ms -> 113135.4ms]
    db 91,0,159,0,42,127,20,2,92,0,42,20  ; n3300 t=113.135s dur=159ms, freq=92Hz, sample=42, buffer_id=14:2A [TRUNCATE prev:ch2 @112953.5ms -> 113135.4ms]
    db 0,0,100,0,97,127,16,0,169,8,97,16  ; n3301 t=113.226s dur=100ms, freq=2217Hz, sample=97, buffer_id=10:61
    db 0,0,100,0,85,127,17,1,85,4,85,16  ; n3302 t=113.226s dur=100ms, freq=1109Hz, sample=85, buffer_id=10:55
    db 91,0,100,0,73,127,18,4,42,2,73,18  ; n3303 t=113.226s dur=100ms, freq=554Hz, sample=73, buffer_id=12:49
    db 0,0,100,0,97,127,16,5,169,8,97,16  ; n3304 t=113.317s dur=100ms, freq=2217Hz, sample=97, buffer_id=10:61
    db 0,0,100,0,85,127,17,14,85,4,85,16  ; n3305 t=113.317s dur=100ms, freq=1109Hz, sample=85, buffer_id=10:55
    db 0,0,100,0,73,127,18,15,42,2,73,18  ; n3306 t=113.317s dur=100ms, freq=554Hz, sample=73, buffer_id=12:49
    db 0,0,159,0,54,127,19,23,165,0,54,19  ; n3307 t=113.317s dur=159ms, freq=165Hz, sample=54, buffer_id=13:36
    db 91,0,159,0,42,127,20,25,82,0,42,20  ; n3308 t=113.317s dur=159ms, freq=82Hz, sample=42, buffer_id=14:2A
    db 0,0,100,0,97,127,16,7,169,8,97,16  ; n3309 t=113.408s dur=100ms, freq=2217Hz, sample=97, buffer_id=10:61
    db 0,0,100,0,85,127,17,8,85,4,85,16  ; n3310 t=113.408s dur=100ms, freq=1109Hz, sample=85, buffer_id=10:55
    db 91,0,100,0,73,127,18,9,42,2,73,18  ; n3311 t=113.408s dur=100ms, freq=554Hz, sample=73, buffer_id=12:49
    db 0,0,113,0,97,127,1,2,169,8,97,1  ; n3312 t=113.499s dur=113ms, freq=2217Hz, sample=97, buffer_id=01:61
    db 0,0,113,0,94,127,2,3,73,7,94,2  ; n3313 t=113.499s dur=113ms, freq=1865Hz, sample=94, buffer_id=02:5E
    db 0,0,107,1,90,127,2,6,200,5,90,2  ; n3314 t=113.499s dur=363ms, freq=1480Hz, sample=90, buffer_id=02:5A
    db 0,0,113,0,85,127,3,11,85,4,85,3  ; n3315 t=113.499s dur=113ms, freq=1109Hz, sample=85, buffer_id=03:55
    db 0,0,107,1,85,127,3,12,164,3,85,3  ; n3316 t=113.499s dur=363ms, freq=932Hz, sample=85, buffer_id=03:55
    db 0,0,113,0,78,127,4,10,228,2,78,4  ; n3317 t=113.499s dur=113ms, freq=740Hz, sample=78, buffer_id=04:4E
    db 0,0,107,1,73,127,4,13,42,2,73,4  ; n3318 t=113.499s dur=363ms, freq=554Hz, sample=73, buffer_id=04:49
    db 0,0,113,0,70,127,5,17,210,1,70,5  ; n3319 t=113.499s dur=113ms, freq=466Hz, sample=70, buffer_id=05:46
    db 0,0,113,0,66,127,6,20,114,1,66,5  ; n3320 t=113.499s dur=113ms, freq=370Hz, sample=66, buffer_id=05:42
    db 0,0,100,0,61,127,11,22,21,1,61,11  ; n3321 t=113.499s dur=100ms, freq=277Hz, sample=61, buffer_id=0B:3D
    db 0,0,100,0,66,127,11,24,114,1,66,11  ; n3322 t=113.499s dur=100ms, freq=370Hz, sample=66, buffer_id=0B:42
    db 0,0,100,0,58,127,12,26,233,0,58,11  ; n3323 t=113.499s dur=100ms, freq=233Hz, sample=58, buffer_id=0B:3A
    db 0,0,100,0,97,127,16,27,169,8,97,16  ; n3324 t=113.499s dur=100ms, freq=2217Hz, sample=97, buffer_id=10:61
    db 0,0,100,0,85,127,17,28,85,4,85,16  ; n3325 t=113.499s dur=100ms, freq=1109Hz, sample=85, buffer_id=10:55
    db 0,0,100,0,73,127,18,29,42,2,73,18  ; n3326 t=113.499s dur=100ms, freq=554Hz, sample=73, buffer_id=12:49
    db 0,0,159,0,47,127,19,30,147,0,47,19  ; n3327 t=113.499s dur=159ms, freq=147Hz, sample=47, buffer_id=13:2F
    db 91,0,159,0,35,127,20,31,73,0,35,20  ; n3328 t=113.499s dur=159ms, freq=73Hz, sample=35, buffer_id=14:23
    db 0,0,113,0,94,127,1,0,73,7,94,1  ; n3329 t=113.590s dur=113ms, freq=1865Hz, sample=94, buffer_id=01:5E
    db 0,0,113,0,85,127,2,1,85,4,85,2  ; n3330 t=113.590s dur=113ms, freq=1109Hz, sample=85, buffer_id=02:55
    db 0,0,113,0,78,127,3,4,228,2,78,3  ; n3331 t=113.590s dur=113ms, freq=740Hz, sample=78, buffer_id=03:4E
    db 0,0,113,0,70,127,4,16,210,1,70,4  ; n3332 t=113.590s dur=113ms, freq=466Hz, sample=70, buffer_id=04:46 [TRUNCATE prev:ch16 @113133.1ms -> 113589.9ms]
    db 0,0,113,0,66,127,5,18,114,1,66,5  ; n3333 t=113.590s dur=113ms, freq=370Hz, sample=66, buffer_id=05:42 [TRUNCATE prev:ch18 @113135.4ms -> 113589.9ms]
    db 0,0,113,0,61,127,6,19,21,1,61,5  ; n3334 t=113.590s dur=113ms, freq=277Hz, sample=61, buffer_id=05:3D [TRUNCATE prev:ch19 @113135.4ms -> 113589.9ms]
    db 0,0,100,0,97,127,16,5,169,8,97,16  ; n3335 t=113.590s dur=100ms, freq=2217Hz, sample=97, buffer_id=10:61 [TRUNCATE prev:ch5 @113317.2ms -> 113589.9ms]
    db 0,0,100,0,85,127,17,14,85,4,85,16  ; n3336 t=113.590s dur=100ms, freq=1109Hz, sample=85, buffer_id=10:55 [TRUNCATE prev:ch14 @113317.2ms -> 113589.9ms]
    db 91,0,100,0,73,127,18,15,42,2,73,18  ; n3337 t=113.590s dur=100ms, freq=554Hz, sample=73, buffer_id=12:49 [TRUNCATE prev:ch15 @113317.2ms -> 113589.9ms]
    db 0,0,181,0,97,127,1,23,169,8,97,1  ; n3338 t=113.681s dur=181ms, freq=2217Hz, sample=97, buffer_id=01:61
    db 0,0,181,0,94,127,2,25,73,7,94,2  ; n3339 t=113.681s dur=181ms, freq=1865Hz, sample=94, buffer_id=02:5E
    db 0,0,181,0,85,127,3,11,85,4,85,3  ; n3340 t=113.681s dur=181ms, freq=1109Hz, sample=85, buffer_id=03:55 [TRUNCATE prev:ch11 @113499.0ms -> 113680.8ms]
    db 0,0,181,0,78,127,4,10,228,2,78,4  ; n3341 t=113.681s dur=181ms, freq=740Hz, sample=78, buffer_id=04:4E [TRUNCATE prev:ch10 @113499.0ms -> 113680.8ms]
    db 0,0,181,0,70,127,5,17,210,1,70,5  ; n3342 t=113.681s dur=181ms, freq=466Hz, sample=70, buffer_id=05:46 [TRUNCATE prev:ch17 @113499.0ms -> 113680.8ms]
    db 0,0,181,0,66,127,6,20,114,1,66,5  ; n3343 t=113.681s dur=181ms, freq=370Hz, sample=66, buffer_id=05:42 [TRUNCATE prev:ch20 @113499.0ms -> 113680.8ms]
    db 0,0,100,0,97,127,16,7,169,8,97,16  ; n3344 t=113.681s dur=100ms, freq=2217Hz, sample=97, buffer_id=10:61 [TRUNCATE prev:ch7 @113408.1ms -> 113680.8ms]
    db 0,0,100,0,85,127,17,8,85,4,85,16  ; n3345 t=113.681s dur=100ms, freq=1109Hz, sample=85, buffer_id=10:55 [TRUNCATE prev:ch8 @113408.1ms -> 113680.8ms]
    db 0,0,100,0,73,127,18,9,42,2,73,18  ; n3346 t=113.681s dur=100ms, freq=554Hz, sample=73, buffer_id=12:49 [TRUNCATE prev:ch9 @113408.1ms -> 113680.8ms]
    db 0,0,159,0,47,127,19,30,139,0,47,19  ; n3347 t=113.681s dur=159ms, freq=139Hz, sample=47, buffer_id=13:2F [TRUNCATE prev:ch30 @113499.0ms -> 113680.8ms]
    db 91,0,159,0,35,127,20,31,69,0,35,20  ; n3348 t=113.681s dur=159ms, freq=69Hz, sample=35, buffer_id=14:23 [TRUNCATE prev:ch31 @113499.0ms -> 113680.8ms]
    db 0,0,100,0,97,127,16,27,169,8,97,16  ; n3349 t=113.772s dur=100ms, freq=2217Hz, sample=97, buffer_id=10:61 [TRUNCATE prev:ch27 @113499.0ms -> 113771.7ms]
    db 0,0,100,0,85,127,17,28,85,4,85,16  ; n3350 t=113.772s dur=100ms, freq=1109Hz, sample=85, buffer_id=10:55 [TRUNCATE prev:ch28 @113499.0ms -> 113771.7ms]
    db 89,0,100,0,73,127,18,29,42,2,73,18  ; n3351 t=113.772s dur=100ms, freq=554Hz, sample=73, buffer_id=12:49 [TRUNCATE prev:ch29 @113499.0ms -> 113771.7ms]
    db 2,0,100,0,42,127,10,2,92,0,42,10  ; n3352 t=113.860s dur=100ms, freq=92Hz, sample=42, buffer_id=0A:2A
    db 0,0,192,2,66,127,7,3,114,1,66,7  ; n3353 t=113.863s dur=704ms, freq=370Hz, sample=66, buffer_id=07:42
    db 0,0,100,0,54,127,12,22,185,0,54,11  ; n3354 t=113.863s dur=100ms, freq=185Hz, sample=54, buffer_id=0B:36
    db 0,0,100,0,42,127,13,24,92,0,42,13  ; n3355 t=113.863s dur=100ms, freq=92Hz, sample=42, buffer_id=0D:2A
    db 0,0,159,0,90,127,16,26,200,5,90,16  ; n3356 t=113.863s dur=159ms, freq=1480Hz, sample=90, buffer_id=10:5A
    db 0,0,159,0,78,127,17,21,228,2,78,16  ; n3357 t=113.863s dur=159ms, freq=740Hz, sample=78, buffer_id=10:4E [TRUNCATE prev:ch21 @113135.4ms -> 113862.6ms]
    db 0,0,159,0,66,127,18,6,114,1,66,18  ; n3358 t=113.863s dur=159ms, freq=370Hz, sample=66, buffer_id=12:42 [TRUNCATE prev:ch6 @113499.0ms -> 113862.6ms]
    db 0,0,159,0,54,127,19,12,185,0,54,19  ; n3359 t=113.863s dur=159ms, freq=185Hz, sample=54, buffer_id=13:36 [TRUNCATE prev:ch12 @113499.0ms -> 113862.6ms]
    db 78,0,159,0,42,127,20,13,92,0,42,20  ; n3360 t=113.863s dur=159ms, freq=92Hz, sample=42, buffer_id=14:2A [TRUNCATE prev:ch13 @113499.0ms -> 113862.6ms]
    db 79,0,100,0,42,127,10,0,92,0,42,10  ; n3361 t=113.941s dur=100ms, freq=92Hz, sample=42, buffer_id=0A:2A
    db 24,0,100,0,42,127,10,1,92,0,42,10  ; n3362 t=114.020s dur=100ms, freq=92Hz, sample=42, buffer_id=0A:2A
    db 0,0,159,0,90,127,16,4,125,6,90,16  ; n3363 t=114.044s dur=159ms, freq=1661Hz, sample=90, buffer_id=10:5A
    db 0,0,159,0,78,127,17,5,63,3,78,16  ; n3364 t=114.044s dur=159ms, freq=831Hz, sample=78, buffer_id=10:4E
    db 0,0,159,0,66,127,18,7,159,1,66,18  ; n3365 t=114.044s dur=159ms, freq=415Hz, sample=66, buffer_id=12:42
    db 0,0,159,0,54,127,19,8,175,0,54,19  ; n3366 t=114.044s dur=159ms, freq=175Hz, sample=54, buffer_id=13:36
    db 55,0,159,0,42,127,20,9,87,0,42,20  ; n3367 t=114.044s dur=159ms, freq=87Hz, sample=42, buffer_id=14:2A
    db 80,0,100,0,42,127,10,10,92,0,42,10  ; n3368 t=114.099s dur=100ms, freq=92Hz, sample=42, buffer_id=0A:2A
    db 47,0,100,0,42,127,10,11,92,0,42,10  ; n3369 t=114.179s dur=100ms, freq=92Hz, sample=42, buffer_id=0A:2A
    db 0,0,113,0,97,127,1,2,169,8,97,1  ; n3370 t=114.226s dur=113ms, freq=2217Hz, sample=97, buffer_id=01:61
    db 0,0,113,0,94,127,2,6,73,7,94,2  ; n3371 t=114.226s dur=113ms, freq=1865Hz, sample=94, buffer_id=02:5E
    db 0,0,107,1,90,127,2,12,200,5,90,2  ; n3372 t=114.226s dur=363ms, freq=1480Hz, sample=90, buffer_id=02:5A
    db 0,0,113,0,85,127,3,13,85,4,85,3  ; n3373 t=114.226s dur=113ms, freq=1109Hz, sample=85, buffer_id=03:55
    db 0,0,107,1,85,127,3,14,164,3,85,3  ; n3374 t=114.226s dur=363ms, freq=932Hz, sample=85, buffer_id=03:55
    db 0,0,113,0,78,127,4,15,228,2,78,4  ; n3375 t=114.226s dur=113ms, freq=740Hz, sample=78, buffer_id=04:4E
    db 0,0,107,1,73,127,4,16,42,2,73,4  ; n3376 t=114.226s dur=363ms, freq=554Hz, sample=73, buffer_id=04:49
    db 0,0,113,0,70,127,5,18,210,1,70,5  ; n3377 t=114.226s dur=113ms, freq=466Hz, sample=70, buffer_id=05:46
    db 0,0,113,0,66,127,6,17,114,1,66,5  ; n3378 t=114.226s dur=113ms, freq=370Hz, sample=66, buffer_id=05:42
    db 0,0,100,0,66,127,9,19,210,1,66,9  ; n3379 t=114.226s dur=100ms, freq=466Hz, sample=66, buffer_id=09:42
    db 0,0,100,0,78,127,9,20,228,2,78,9  ; n3380 t=114.226s dur=100ms, freq=740Hz, sample=78, buffer_id=09:4E
    db 0,0,100,0,61,127,11,21,21,1,61,11  ; n3381 t=114.226s dur=100ms, freq=277Hz, sample=61, buffer_id=0B:3D
    db 0,0,100,0,66,127,11,22,114,1,66,11  ; n3382 t=114.226s dur=100ms, freq=370Hz, sample=66, buffer_id=0B:42
    db 0,0,100,0,58,127,12,23,233,0,58,11  ; n3383 t=114.226s dur=100ms, freq=233Hz, sample=58, buffer_id=0B:3A
    db 0,0,159,0,97,127,16,24,73,7,97,16  ; n3384 t=114.226s dur=159ms, freq=1865Hz, sample=97, buffer_id=10:61
    db 0,0,159,0,85,127,17,25,164,3,85,16  ; n3385 t=114.226s dur=159ms, freq=932Hz, sample=85, buffer_id=10:55
    db 0,0,159,0,73,127,18,26,210,1,73,18  ; n3386 t=114.226s dur=159ms, freq=466Hz, sample=73, buffer_id=12:49
    db 0,0,159,0,54,127,19,27,156,0,54,19  ; n3387 t=114.226s dur=159ms, freq=156Hz, sample=54, buffer_id=13:36
    db 32,0,159,0,42,127,20,28,78,0,42,20  ; n3388 t=114.226s dur=159ms, freq=78Hz, sample=42, buffer_id=14:2A
    db 58,0,100,0,42,127,10,29,92,0,42,10  ; n3389 t=114.259s dur=100ms, freq=92Hz, sample=42, buffer_id=0A:2A
    db 0,0,113,0,94,127,1,0,73,7,94,1  ; n3390 t=114.317s dur=113ms, freq=1865Hz, sample=94, buffer_id=01:5E
    db 0,0,113,0,85,127,2,30,85,4,85,2  ; n3391 t=114.317s dur=113ms, freq=1109Hz, sample=85, buffer_id=02:55
    db 0,0,113,0,78,127,3,31,228,2,78,3  ; n3392 t=114.317s dur=113ms, freq=740Hz, sample=78, buffer_id=03:4E
    db 0,0,113,0,70,127,4,3,210,1,70,4  ; n3393 t=114.317s dur=113ms, freq=466Hz, sample=70, buffer_id=04:46 [TRUNCATE prev:ch3 @113862.6ms -> 114317.2ms]
    db 0,0,113,0,66,127,5,1,114,1,66,5  ; n3394 t=114.317s dur=113ms, freq=370Hz, sample=66, buffer_id=05:42 [TRUNCATE prev:ch1 @114020.2ms -> 114317.2ms]
    db 20,0,113,0,61,127,6,4,21,1,61,5  ; n3395 t=114.317s dur=113ms, freq=277Hz, sample=61, buffer_id=05:3D [TRUNCATE prev:ch4 @114044.5ms -> 114317.2ms]
    db 71,0,100,0,42,127,10,10,92,0,42,10  ; n3396 t=114.338s dur=100ms, freq=92Hz, sample=42, buffer_id=0A:2A [TRUNCATE prev:ch10 @114099.0ms -> 114337.6ms]
    db 0,0,181,0,97,127,1,5,169,8,97,1  ; n3397 t=114.408s dur=181ms, freq=2217Hz, sample=97, buffer_id=01:61
    db 0,0,181,0,94,127,2,7,73,7,94,2  ; n3398 t=114.408s dur=181ms, freq=1865Hz, sample=94, buffer_id=02:5E
    db 0,0,181,0,85,127,3,8,85,4,85,3  ; n3399 t=114.408s dur=181ms, freq=1109Hz, sample=85, buffer_id=03:55
    db 0,0,181,0,78,127,4,9,228,2,78,4  ; n3400 t=114.408s dur=181ms, freq=740Hz, sample=78, buffer_id=04:4E
    db 0,0,181,0,70,127,5,18,210,1,70,5  ; n3401 t=114.408s dur=181ms, freq=466Hz, sample=70, buffer_id=05:46 [TRUNCATE prev:ch18 @114226.3ms -> 114408.1ms]
    db 0,0,181,0,66,127,6,17,114,1,66,5  ; n3402 t=114.408s dur=181ms, freq=370Hz, sample=66, buffer_id=05:42 [TRUNCATE prev:ch17 @114226.3ms -> 114408.1ms]
    db 0,0,159,0,97,127,16,24,184,7,97,16  ; n3403 t=114.408s dur=159ms, freq=1976Hz, sample=97, buffer_id=10:61 [TRUNCATE prev:ch24 @114226.3ms -> 114408.1ms]
    db 0,0,159,0,85,127,17,25,220,3,85,16  ; n3404 t=114.408s dur=159ms, freq=988Hz, sample=85, buffer_id=10:55 [TRUNCATE prev:ch25 @114226.3ms -> 114408.1ms]
    db 0,0,159,0,73,127,18,26,238,1,73,18  ; n3405 t=114.408s dur=159ms, freq=494Hz, sample=73, buffer_id=12:49 [TRUNCATE prev:ch26 @114226.3ms -> 114408.1ms]
    db 0,0,159,0,47,127,19,11,139,0,47,19  ; n3406 t=114.408s dur=159ms, freq=139Hz, sample=47, buffer_id=13:2F [TRUNCATE prev:ch11 @114179.3ms -> 114408.1ms]
    db 9,0,159,0,35,127,20,2,69,0,35,20  ; n3407 t=114.408s dur=159ms, freq=69Hz, sample=35, buffer_id=14:23 [TRUNCATE prev:ch2 @114226.3ms -> 114408.1ms]
    db 80,0,100,0,42,127,10,29,92,0,42,10  ; n3408 t=114.417s dur=100ms, freq=92Hz, sample=42, buffer_id=0A:2A [TRUNCATE prev:ch29 @114258.8ms -> 114417.2ms]
    db 79,0,100,0,42,127,10,10,92,0,42,10  ; n3409 t=114.498s dur=100ms, freq=92Hz, sample=42, buffer_id=0A:2A [TRUNCATE prev:ch10 @114337.6ms -> 114497.5ms]
    db 13,0,100,0,42,127,10,6,92,0,42,10  ; n3410 t=114.577s dur=100ms, freq=92Hz, sample=42, buffer_id=0A:2A
    db 0,0,192,2,66,127,7,13,114,1,66,7  ; n3411 t=114.590s dur=704ms, freq=370Hz, sample=66, buffer_id=07:42
    db 0,0,100,0,54,127,12,15,185,0,54,11  ; n3412 t=114.590s dur=100ms, freq=185Hz, sample=54, buffer_id=0B:36
    db 0,0,100,0,42,127,13,19,92,0,42,13  ; n3413 t=114.590s dur=100ms, freq=92Hz, sample=42, buffer_id=0D:2A
    db 0,0,159,0,97,127,16,20,169,8,97,16  ; n3414 t=114.590s dur=159ms, freq=2217Hz, sample=97, buffer_id=10:61
    db 0,0,159,0,85,127,17,21,85,4,85,16  ; n3415 t=114.590s dur=159ms, freq=1109Hz, sample=85, buffer_id=10:55
    db 0,0,159,0,73,127,18,22,42,2,73,18  ; n3416 t=114.590s dur=159ms, freq=554Hz, sample=73, buffer_id=12:49
    db 0,0,159,0,54,127,19,23,185,0,54,19  ; n3417 t=114.590s dur=159ms, freq=185Hz, sample=54, buffer_id=13:36
    db 66,0,159,0,42,127,20,27,92,0,42,20  ; n3418 t=114.590s dur=159ms, freq=92Hz, sample=42, buffer_id=14:2A
    db 80,0,100,0,42,127,10,0,92,0,42,10  ; n3419 t=114.656s dur=100ms, freq=92Hz, sample=42, buffer_id=0A:2A
    db 36,0,100,0,42,127,10,1,92,0,42,10  ; n3420 t=114.735s dur=100ms, freq=92Hz, sample=42, buffer_id=0A:2A
    db 0,0,159,0,97,127,16,2,73,7,97,16  ; n3421 t=114.772s dur=159ms, freq=1865Hz, sample=97, buffer_id=10:61
    db 0,0,159,0,85,127,17,3,164,3,85,16  ; n3422 t=114.772s dur=159ms, freq=932Hz, sample=85, buffer_id=10:55
    db 0,0,159,0,73,127,18,4,210,1,73,18  ; n3423 t=114.772s dur=159ms, freq=466Hz, sample=73, buffer_id=12:49
    db 0,0,159,0,54,127,19,11,175,0,54,19  ; n3424 t=114.772s dur=159ms, freq=175Hz, sample=54, buffer_id=13:36
    db 43,0,159,0,42,127,20,24,87,0,42,20  ; n3425 t=114.772s dur=159ms, freq=87Hz, sample=42, buffer_id=14:2A
    db 80,0,100,0,42,127,10,5,92,0,42,10  ; n3426 t=114.814s dur=100ms, freq=92Hz, sample=42, buffer_id=0A:2A
    db 59,0,100,0,42,127,10,7,92,0,42,10  ; n3427 t=114.894s dur=100ms, freq=92Hz, sample=42, buffer_id=0A:2A
    db 0,0,113,0,97,127,1,6,169,8,97,1  ; n3428 t=114.954s dur=113ms, freq=2217Hz, sample=97, buffer_id=01:61
    db 0,0,113,0,94,127,2,8,73,7,94,2  ; n3429 t=114.954s dur=113ms, freq=1865Hz, sample=94, buffer_id=02:5E
    db 0,0,107,1,90,127,2,9,200,5,90,2  ; n3430 t=114.954s dur=363ms, freq=1480Hz, sample=90, buffer_id=02:5A
    db 0,0,113,0,85,127,3,10,85,4,85,3  ; n3431 t=114.954s dur=113ms, freq=1109Hz, sample=85, buffer_id=03:55
    db 0,0,107,1,85,127,3,12,164,3,85,3  ; n3432 t=114.954s dur=363ms, freq=932Hz, sample=85, buffer_id=03:55
    db 0,0,113,0,78,127,4,14,228,2,78,4  ; n3433 t=114.954s dur=113ms, freq=740Hz, sample=78, buffer_id=04:4E
    db 0,0,107,1,73,127,4,15,42,2,73,4  ; n3434 t=114.954s dur=363ms, freq=554Hz, sample=73, buffer_id=04:49
    db 0,0,113,0,70,127,5,16,210,1,70,5  ; n3435 t=114.954s dur=113ms, freq=466Hz, sample=70, buffer_id=05:46
    db 0,0,113,0,66,127,6,18,114,1,66,5  ; n3436 t=114.954s dur=113ms, freq=370Hz, sample=66, buffer_id=05:42
    db 0,0,100,0,66,127,9,17,210,1,66,9  ; n3437 t=114.954s dur=100ms, freq=466Hz, sample=66, buffer_id=09:42
    db 0,0,100,0,78,127,9,19,228,2,78,9  ; n3438 t=114.954s dur=100ms, freq=740Hz, sample=78, buffer_id=09:4E
    db 0,0,100,0,61,127,11,20,21,1,61,11  ; n3439 t=114.954s dur=100ms, freq=277Hz, sample=61, buffer_id=0B:3D
    db 0,0,100,0,66,127,11,21,114,1,66,11  ; n3440 t=114.954s dur=100ms, freq=370Hz, sample=66, buffer_id=0B:42
    db 0,0,100,0,58,127,12,22,233,0,58,11  ; n3441 t=114.954s dur=100ms, freq=233Hz, sample=58, buffer_id=0B:3A
    db 0,0,100,0,97,127,16,23,169,8,97,16  ; n3442 t=114.954s dur=100ms, freq=2217Hz, sample=97, buffer_id=10:61
    db 0,0,100,0,85,127,17,26,85,4,85,16  ; n3443 t=114.954s dur=100ms, freq=1109Hz, sample=85, buffer_id=10:55
    db 0,0,100,0,73,127,18,25,42,2,73,18  ; n3444 t=114.954s dur=100ms, freq=554Hz, sample=73, buffer_id=12:49
    db 0,0,159,0,54,127,19,27,156,0,54,19  ; n3445 t=114.954s dur=159ms, freq=156Hz, sample=54, buffer_id=13:36
    db 20,0,159,0,42,127,20,29,78,0,42,20  ; n3446 t=114.954s dur=159ms, freq=78Hz, sample=42, buffer_id=14:2A
    db 70,0,100,0,42,127,10,28,92,0,42,10  ; n3447 t=114.974s dur=100ms, freq=92Hz, sample=42, buffer_id=0A:2A
    db 0,0,113,0,94,127,1,0,73,7,94,1  ; n3448 t=115.044s dur=113ms, freq=1865Hz, sample=94, buffer_id=01:5E
    db 0,0,113,0,85,127,2,1,85,4,85,2  ; n3449 t=115.044s dur=113ms, freq=1109Hz, sample=85, buffer_id=02:55
    db 0,0,113,0,78,127,3,30,228,2,78,3  ; n3450 t=115.044s dur=113ms, freq=740Hz, sample=78, buffer_id=03:4E
    db 0,0,113,0,70,127,4,31,210,1,70,4  ; n3451 t=115.044s dur=113ms, freq=466Hz, sample=70, buffer_id=04:46
    db 0,0,113,0,66,127,5,13,114,1,66,5  ; n3452 t=115.044s dur=113ms, freq=370Hz, sample=66, buffer_id=05:42 [TRUNCATE prev:ch13 @114589.9ms -> 115044.5ms]
    db 0,0,113,0,61,127,6,2,21,1,61,5  ; n3453 t=115.044s dur=113ms, freq=277Hz, sample=61, buffer_id=05:3D [TRUNCATE prev:ch2 @114771.7ms -> 115044.5ms]
    db 0,0,100,0,97,127,16,3,169,8,97,16  ; n3454 t=115.044s dur=100ms, freq=2217Hz, sample=97, buffer_id=10:61 [TRUNCATE prev:ch3 @114771.7ms -> 115044.5ms]
    db 0,0,100,0,85,127,17,4,85,4,85,16  ; n3455 t=115.044s dur=100ms, freq=1109Hz, sample=85, buffer_id=10:55 [TRUNCATE prev:ch4 @114771.7ms -> 115044.5ms]
    db 9,0,100,0,73,127,18,11,42,2,73,18  ; n3456 t=115.044s dur=100ms, freq=554Hz, sample=73, buffer_id=12:49 [TRUNCATE prev:ch11 @114771.7ms -> 115044.5ms]
    db 80,0,100,0,42,127,10,5,92,0,42,10  ; n3457 t=115.053s dur=100ms, freq=92Hz, sample=42, buffer_id=0A:2A [TRUNCATE prev:ch5 @114814.2ms -> 115053.5ms]
    db 2,0,100,0,42,127,10,24,92,0,42,10  ; n3458 t=115.134s dur=100ms, freq=92Hz, sample=42, buffer_id=0A:2A
    db 0,0,181,0,97,127,1,6,169,8,97,1  ; n3459 t=115.135s dur=181ms, freq=2217Hz, sample=97, buffer_id=01:61 [TRUNCATE prev:ch6 @114953.5ms -> 115135.4ms]
    db 0,0,181,0,94,127,2,8,73,7,94,2  ; n3460 t=115.135s dur=181ms, freq=1865Hz, sample=94, buffer_id=02:5E [TRUNCATE prev:ch8 @114953.5ms -> 115135.4ms]
    db 0,0,181,0,85,127,3,10,85,4,85,3  ; n3461 t=115.135s dur=181ms, freq=1109Hz, sample=85, buffer_id=03:55 [TRUNCATE prev:ch10 @114953.5ms -> 115135.4ms]
    db 0,0,181,0,78,127,4,14,228,2,78,4  ; n3462 t=115.135s dur=181ms, freq=740Hz, sample=78, buffer_id=04:4E [TRUNCATE prev:ch14 @114953.5ms -> 115135.4ms]
    db 0,0,181,0,70,127,5,16,210,1,70,5  ; n3463 t=115.135s dur=181ms, freq=466Hz, sample=70, buffer_id=05:46 [TRUNCATE prev:ch16 @114953.5ms -> 115135.4ms]
    db 0,0,181,0,66,127,6,18,114,1,66,5  ; n3464 t=115.135s dur=181ms, freq=370Hz, sample=66, buffer_id=05:42 [TRUNCATE prev:ch18 @114953.5ms -> 115135.4ms]
    db 0,0,100,0,97,127,16,23,169,8,97,16  ; n3465 t=115.135s dur=100ms, freq=2217Hz, sample=97, buffer_id=10:61 [TRUNCATE prev:ch23 @114953.5ms -> 115135.4ms]
    db 0,0,100,0,85,127,17,26,85,4,85,16  ; n3466 t=115.135s dur=100ms, freq=1109Hz, sample=85, buffer_id=10:55 [TRUNCATE prev:ch26 @114953.5ms -> 115135.4ms]
    db 0,0,100,0,73,127,18,25,42,2,73,18  ; n3467 t=115.135s dur=100ms, freq=554Hz, sample=73, buffer_id=12:49 [TRUNCATE prev:ch25 @114953.5ms -> 115135.4ms]
    db 0,0,159,0,47,127,19,7,139,0,47,19  ; n3468 t=115.135s dur=159ms, freq=139Hz, sample=47, buffer_id=13:2F [TRUNCATE prev:ch7 @114894.5ms -> 115135.4ms]
    db 78,0,159,0,35,127,20,9,69,0,35,20  ; n3469 t=115.135s dur=159ms, freq=69Hz, sample=35, buffer_id=14:23 [TRUNCATE prev:ch9 @114953.5ms -> 115135.4ms]
    db 13,0,100,0,42,127,10,28,92,0,42,10  ; n3470 t=115.213s dur=100ms, freq=92Hz, sample=42, buffer_id=0A:2A [TRUNCATE prev:ch28 @114974.0ms -> 115213.4ms]
    db 0,0,100,0,97,127,16,3,169,8,97,16  ; n3471 t=115.226s dur=100ms, freq=2217Hz, sample=97, buffer_id=10:61 [TRUNCATE prev:ch3 @115044.5ms -> 115226.3ms]
    db 0,0,100,0,85,127,17,4,85,4,85,16  ; n3472 t=115.226s dur=100ms, freq=1109Hz, sample=85, buffer_id=10:55 [TRUNCATE prev:ch4 @115044.5ms -> 115226.3ms]
    db 65,0,100,0,73,127,18,11,42,2,73,18  ; n3473 t=115.226s dur=100ms, freq=554Hz, sample=73, buffer_id=12:49 [TRUNCATE prev:ch11 @115044.5ms -> 115226.3ms]
    db 26,0,100,0,42,127,10,17,92,0,42,10  ; n3474 t=115.291s dur=100ms, freq=92Hz, sample=42, buffer_id=0A:2A
    db 0,0,113,0,62,127,7,19,55,1,62,7  ; n3475 t=115.317s dur=113ms, freq=311Hz, sample=62, buffer_id=07:3E
    db 0,0,100,0,50,127,12,20,156,0,50,11  ; n3476 t=115.317s dur=100ms, freq=156Hz, sample=50, buffer_id=0B:32
    db 0,0,100,0,42,127,13,21,78,0,42,13  ; n3477 t=115.317s dur=100ms, freq=78Hz, sample=42, buffer_id=0D:2A
    db 0,0,159,0,99,127,16,22,185,9,99,16  ; n3478 t=115.317s dur=159ms, freq=2489Hz, sample=99, buffer_id=10:63
    db 0,0,159,0,87,127,17,27,221,4,87,16  ; n3479 t=115.317s dur=159ms, freq=1245Hz, sample=87, buffer_id=10:57
    db 0,0,159,0,75,127,18,29,110,2,75,18  ; n3480 t=115.317s dur=159ms, freq=622Hz, sample=75, buffer_id=12:4B
    db 0,0,159,0,54,127,19,12,156,0,54,19  ; n3481 t=115.317s dur=159ms, freq=156Hz, sample=54, buffer_id=13:36 [TRUNCATE prev:ch12 @114953.5ms -> 115317.2ms]
    db 55,0,159,0,42,127,20,15,78,0,42,20  ; n3482 t=115.317s dur=159ms, freq=78Hz, sample=42, buffer_id=14:2A [TRUNCATE prev:ch15 @114953.5ms -> 115317.2ms]
    db 80,0,100,0,42,127,10,0,92,0,42,10  ; n3483 t=115.372s dur=100ms, freq=92Hz, sample=42, buffer_id=0A:2A
    db 48,0,100,0,42,127,10,1,92,0,42,10  ; n3484 t=115.451s dur=100ms, freq=92Hz, sample=42, buffer_id=0A:2A
    db 0,0,159,0,97,127,16,2,73,7,97,16  ; n3485 t=115.499s dur=159ms, freq=1865Hz, sample=97, buffer_id=10:61
    db 0,0,159,0,85,127,17,5,164,3,85,16  ; n3486 t=115.499s dur=159ms, freq=932Hz, sample=85, buffer_id=10:55
    db 0,0,159,0,73,127,18,7,210,1,73,18  ; n3487 t=115.499s dur=159ms, freq=466Hz, sample=73, buffer_id=12:49
    db 0,0,159,0,47,127,19,9,139,0,47,19  ; n3488 t=115.499s dur=159ms, freq=139Hz, sample=47, buffer_id=13:2F
    db 33,0,159,0,35,127,20,13,69,0,35,20  ; n3489 t=115.499s dur=159ms, freq=69Hz, sample=35, buffer_id=14:23
    db 79,0,100,0,42,127,10,3,92,0,42,10  ; n3490 t=115.532s dur=100ms, freq=92Hz, sample=42, buffer_id=0A:2A
    db 70,0,100,0,42,127,10,4,92,0,42,10  ; n3491 t=115.610s dur=100ms, freq=92Hz, sample=42, buffer_id=0A:2A
    db 0,0,113,0,99,127,1,0,185,9,99,1  ; n3492 t=115.681s dur=113ms, freq=2489Hz, sample=99, buffer_id=01:63
    db 0,0,113,0,94,127,2,6,73,7,94,2  ; n3493 t=115.681s dur=113ms, freq=1865Hz, sample=94, buffer_id=02:5E
    db 0,0,107,1,90,127,2,8,200,5,90,2  ; n3494 t=115.681s dur=363ms, freq=1480Hz, sample=90, buffer_id=02:5A
    db 0,0,113,0,87,127,3,10,221,4,87,3  ; n3495 t=115.681s dur=113ms, freq=1245Hz, sample=87, buffer_id=03:57
    db 0,0,107,1,85,127,3,11,164,3,85,3  ; n3496 t=115.681s dur=363ms, freq=932Hz, sample=85, buffer_id=03:55
    db 0,0,113,0,78,127,4,12,228,2,78,4  ; n3497 t=115.681s dur=113ms, freq=740Hz, sample=78, buffer_id=04:4E
    db 0,0,87,1,74,127,4,14,110,2,74,4  ; n3498 t=115.681s dur=343ms, freq=622Hz, sample=74, buffer_id=04:4A
    db 0,0,113,0,70,127,5,15,210,1,70,5  ; n3499 t=115.681s dur=113ms, freq=466Hz, sample=70, buffer_id=05:46
    db 0,0,113,0,66,127,6,16,114,1,66,5  ; n3500 t=115.681s dur=113ms, freq=370Hz, sample=66, buffer_id=05:42
    db 0,0,100,0,66,127,9,17,210,1,66,9  ; n3501 t=115.681s dur=100ms, freq=466Hz, sample=66, buffer_id=09:42
    db 0,0,100,0,78,127,9,18,228,2,78,9  ; n3502 t=115.681s dur=100ms, freq=740Hz, sample=78, buffer_id=09:4E
    db 0,0,100,0,62,127,11,19,55,1,62,11  ; n3503 t=115.681s dur=100ms, freq=311Hz, sample=62, buffer_id=0B:3E
    db 0,0,100,0,66,127,11,20,114,1,66,11  ; n3504 t=115.681s dur=100ms, freq=370Hz, sample=66, buffer_id=0B:42
    db 0,0,100,0,58,127,12,21,233,0,58,11  ; n3505 t=115.681s dur=100ms, freq=233Hz, sample=58, buffer_id=0B:3A
    db 0,0,100,0,99,127,16,23,185,9,99,16  ; n3506 t=115.681s dur=100ms, freq=2489Hz, sample=99, buffer_id=10:63
    db 0,0,100,0,87,127,17,22,221,4,87,16  ; n3507 t=115.681s dur=100ms, freq=1245Hz, sample=87, buffer_id=10:57
    db 0,0,100,0,75,127,18,24,110,2,75,18  ; n3508 t=115.681s dur=100ms, freq=622Hz, sample=75, buffer_id=12:4B
    db 0,0,159,0,54,127,19,25,156,0,54,19  ; n3509 t=115.681s dur=159ms, freq=156Hz, sample=54, buffer_id=13:36
    db 9,0,159,0,42,127,20,26,78,0,42,20  ; n3510 t=115.681s dur=159ms, freq=78Hz, sample=42, buffer_id=14:2A
    db 80,0,100,0,42,127,10,27,92,0,42,10  ; n3511 t=115.690s dur=100ms, freq=92Hz, sample=42, buffer_id=0A:2A
    db 2,0,100,0,42,127,10,29,92,0,42,10  ; n3512 t=115.769s dur=100ms, freq=92Hz, sample=42, buffer_id=0A:2A
    db 0,0,113,0,94,127,1,1,73,7,94,1  ; n3513 t=115.772s dur=113ms, freq=1865Hz, sample=94, buffer_id=01:5E
    db 0,0,113,0,86,127,2,28,221,4,86,2  ; n3514 t=115.772s dur=113ms, freq=1245Hz, sample=86, buffer_id=02:56
    db 0,0,113,0,78,127,3,31,228,2,78,3  ; n3515 t=115.772s dur=113ms, freq=740Hz, sample=78, buffer_id=03:4E
    db 0,0,113,0,70,127,4,30,210,1,70,4  ; n3516 t=115.772s dur=113ms, freq=466Hz, sample=70, buffer_id=04:46
    db 0,0,113,0,66,127,5,2,114,1,66,5  ; n3517 t=115.772s dur=113ms, freq=370Hz, sample=66, buffer_id=05:42 [TRUNCATE prev:ch2 @115499.0ms -> 115771.7ms]
    db 0,0,113,0,62,127,6,5,55,1,62,5  ; n3518 t=115.772s dur=113ms, freq=311Hz, sample=62, buffer_id=05:3E [TRUNCATE prev:ch5 @115499.0ms -> 115771.7ms]
    db 0,0,100,0,99,127,16,7,185,9,99,16  ; n3519 t=115.772s dur=100ms, freq=2489Hz, sample=99, buffer_id=10:63 [TRUNCATE prev:ch7 @115499.0ms -> 115771.7ms]
    db 0,0,100,0,87,127,17,9,221,4,87,16  ; n3520 t=115.772s dur=100ms, freq=1245Hz, sample=87, buffer_id=10:57 [TRUNCATE prev:ch9 @115499.0ms -> 115771.7ms]
    db 77,0,100,0,75,127,18,13,110,2,75,18  ; n3521 t=115.772s dur=100ms, freq=622Hz, sample=75, buffer_id=12:4B [TRUNCATE prev:ch13 @115499.0ms -> 115771.7ms]
    db 14,0,100,0,42,127,10,3,92,0,42,10  ; n3522 t=115.849s dur=100ms, freq=92Hz, sample=42, buffer_id=0A:2A [TRUNCATE prev:ch3 @115531.6ms -> 115849.0ms]
    db 0,0,181,0,99,127,1,0,185,9,99,1  ; n3523 t=115.863s dur=181ms, freq=2489Hz, sample=99, buffer_id=01:63 [TRUNCATE prev:ch0 @115680.8ms -> 115862.6ms]
    db 0,0,181,0,94,127,2,6,73,7,94,2  ; n3524 t=115.863s dur=181ms, freq=1865Hz, sample=94, buffer_id=02:5E [TRUNCATE prev:ch6 @115680.8ms -> 115862.6ms]
    db 0,0,181,0,87,127,3,10,221,4,87,3  ; n3525 t=115.863s dur=181ms, freq=1245Hz, sample=87, buffer_id=03:57 [TRUNCATE prev:ch10 @115680.8ms -> 115862.6ms]
    db 0,0,181,0,78,127,4,12,228,2,78,4  ; n3526 t=115.863s dur=181ms, freq=740Hz, sample=78, buffer_id=04:4E [TRUNCATE prev:ch12 @115680.8ms -> 115862.6ms]
    db 0,0,181,0,70,127,5,15,210,1,70,5  ; n3527 t=115.863s dur=181ms, freq=466Hz, sample=70, buffer_id=05:46 [TRUNCATE prev:ch15 @115680.8ms -> 115862.6ms]
    db 0,0,181,0,66,127,6,16,114,1,66,5  ; n3528 t=115.863s dur=181ms, freq=370Hz, sample=66, buffer_id=05:42 [TRUNCATE prev:ch16 @115680.8ms -> 115862.6ms]
    db 0,0,100,0,99,127,16,23,185,9,99,16  ; n3529 t=115.863s dur=100ms, freq=2489Hz, sample=99, buffer_id=10:63 [TRUNCATE prev:ch23 @115680.8ms -> 115862.6ms]
    db 0,0,100,0,87,127,17,22,221,4,87,16  ; n3530 t=115.863s dur=100ms, freq=1245Hz, sample=87, buffer_id=10:57 [TRUNCATE prev:ch22 @115680.8ms -> 115862.6ms]
    db 0,0,100,0,75,127,18,24,110,2,75,18  ; n3531 t=115.863s dur=100ms, freq=622Hz, sample=75, buffer_id=12:4B [TRUNCATE prev:ch24 @115680.8ms -> 115862.6ms]
    db 0,0,159,0,54,127,19,25,175,0,54,19  ; n3532 t=115.863s dur=159ms, freq=175Hz, sample=54, buffer_id=13:36 [TRUNCATE prev:ch25 @115680.8ms -> 115862.6ms]
    db 66,0,159,0,42,127,20,26,87,0,42,20  ; n3533 t=115.863s dur=159ms, freq=87Hz, sample=42, buffer_id=14:2A [TRUNCATE prev:ch26 @115680.8ms -> 115862.6ms]
    db 25,0,100,0,42,127,10,4,92,0,42,10  ; n3534 t=115.928s dur=100ms, freq=92Hz, sample=42, buffer_id=0A:2A [TRUNCATE prev:ch4 @115610.4ms -> 115928.5ms]
    db 0,0,100,0,99,127,16,7,185,9,99,16  ; n3535 t=115.954s dur=100ms, freq=2489Hz, sample=99, buffer_id=10:63 [TRUNCATE prev:ch7 @115771.7ms -> 115953.5ms]
    db 0,0,100,0,87,127,17,9,221,4,87,16  ; n3536 t=115.954s dur=100ms, freq=1245Hz, sample=87, buffer_id=10:57 [TRUNCATE prev:ch9 @115771.7ms -> 115953.5ms]
    db 55,0,100,0,75,127,18,13,110,2,75,18  ; n3537 t=115.954s dur=100ms, freq=622Hz, sample=75, buffer_id=12:4B [TRUNCATE prev:ch13 @115771.7ms -> 115953.5ms]
    db 36,0,100,0,42,127,10,17,92,0,42,10  ; n3538 t=116.008s dur=100ms, freq=92Hz, sample=42, buffer_id=0A:2A
    db 0,0,192,2,66,127,7,18,114,1,66,7  ; n3539 t=116.044s dur=704ms, freq=370Hz, sample=66, buffer_id=07:42
    db 0,0,100,0,54,127,12,19,185,0,54,11  ; n3540 t=116.044s dur=100ms, freq=185Hz, sample=54, buffer_id=0B:36
    db 0,0,100,0,42,127,13,20,92,0,42,13  ; n3541 t=116.044s dur=100ms, freq=92Hz, sample=42, buffer_id=0D:2A
    db 0,0,159,0,97,127,16,21,169,8,97,16  ; n3542 t=116.044s dur=159ms, freq=2217Hz, sample=97, buffer_id=10:61
    db 0,0,159,0,85,127,17,27,85,4,85,16  ; n3543 t=116.044s dur=159ms, freq=1109Hz, sample=85, buffer_id=10:55
    db 0,0,159,0,73,127,18,8,42,2,73,18  ; n3544 t=116.044s dur=159ms, freq=554Hz, sample=73, buffer_id=12:49 [TRUNCATE prev:ch8 @115680.8ms -> 116044.5ms]
    db 0,0,159,0,54,127,19,25,185,0,54,19  ; n3545 t=116.044s dur=159ms, freq=185Hz, sample=54, buffer_id=13:36 [TRUNCATE prev:ch25 @115862.6ms -> 116044.5ms]
    db 44,0,159,0,42,127,20,26,92,0,42,20  ; n3546 t=116.044s dur=159ms, freq=92Hz, sample=42, buffer_id=14:2A [TRUNCATE prev:ch26 @115862.6ms -> 116044.5ms]
    db 79,0,100,0,42,127,10,1,92,0,42,10  ; n3547 t=116.088s dur=100ms, freq=92Hz, sample=42, buffer_id=0A:2A
    db 59,0,100,0,42,127,10,2,92,0,42,10  ; n3548 t=116.167s dur=100ms, freq=92Hz, sample=42, buffer_id=0A:2A
    db 0,0,159,0,97,127,16,3,73,7,97,16  ; n3549 t=116.226s dur=159ms, freq=1865Hz, sample=97, buffer_id=10:61
    db 0,0,159,0,85,127,17,5,164,3,85,16  ; n3550 t=116.226s dur=159ms, freq=932Hz, sample=85, buffer_id=10:55
    db 0,0,159,0,73,127,18,14,210,1,73,18  ; n3551 t=116.226s dur=159ms, freq=466Hz, sample=73, buffer_id=12:49
    db 0,0,159,0,54,127,19,22,175,0,54,19  ; n3552 t=116.226s dur=159ms, freq=175Hz, sample=54, buffer_id=13:36
    db 21,0,159,0,42,127,20,23,87,0,42,20  ; n3553 t=116.226s dur=159ms, freq=87Hz, sample=42, buffer_id=14:2A
    db 79,0,100,0,42,127,10,0,92,0,42,10  ; n3554 t=116.248s dur=100ms, freq=92Hz, sample=42, buffer_id=0A:2A
    db 80,0,100,0,42,127,10,6,92,0,42,10  ; n3555 t=116.326s dur=100ms, freq=92Hz, sample=42, buffer_id=0A:2A
    db 2,0,100,0,42,127,10,7,92,0,42,10  ; n3556 t=116.407s dur=100ms, freq=92Hz, sample=42, buffer_id=0A:2A
    db 0,0,113,0,97,127,1,1,169,8,97,1  ; n3557 t=116.408s dur=113ms, freq=2217Hz, sample=97, buffer_id=01:61
    db 0,0,113,0,94,127,2,4,73,7,94,2  ; n3558 t=116.408s dur=113ms, freq=1865Hz, sample=94, buffer_id=02:5E
    db 0,0,107,1,90,127,2,8,200,5,90,2  ; n3559 t=116.408s dur=363ms, freq=1480Hz, sample=90, buffer_id=02:5A
    db 0,0,113,0,85,127,3,9,85,4,85,3  ; n3560 t=116.408s dur=113ms, freq=1109Hz, sample=85, buffer_id=03:55
    db 0,0,107,1,85,127,3,10,164,3,85,3  ; n3561 t=116.408s dur=363ms, freq=932Hz, sample=85, buffer_id=03:55
    db 0,0,113,0,78,127,4,11,228,2,78,4  ; n3562 t=116.408s dur=113ms, freq=740Hz, sample=78, buffer_id=04:4E
    db 0,0,107,1,73,127,4,12,42,2,73,4  ; n3563 t=116.408s dur=363ms, freq=554Hz, sample=73, buffer_id=04:49
    db 0,0,113,0,70,127,5,13,210,1,70,5  ; n3564 t=116.408s dur=113ms, freq=466Hz, sample=70, buffer_id=05:46
    db 0,0,113,0,66,127,6,15,114,1,66,5  ; n3565 t=116.408s dur=113ms, freq=370Hz, sample=66, buffer_id=05:42
    db 0,0,100,0,66,127,9,16,210,1,66,9  ; n3566 t=116.408s dur=100ms, freq=466Hz, sample=66, buffer_id=09:42
    db 0,0,100,0,78,127,9,17,228,2,78,9  ; n3567 t=116.408s dur=100ms, freq=740Hz, sample=78, buffer_id=09:4E
    db 0,0,100,0,61,127,11,19,21,1,61,11  ; n3568 t=116.408s dur=100ms, freq=277Hz, sample=61, buffer_id=0B:3D
    db 0,0,100,0,66,127,11,20,114,1,66,11  ; n3569 t=116.408s dur=100ms, freq=370Hz, sample=66, buffer_id=0B:42
    db 0,0,100,0,58,127,12,21,233,0,58,11  ; n3570 t=116.408s dur=100ms, freq=233Hz, sample=58, buffer_id=0B:3A
    db 0,0,100,0,97,127,16,24,169,8,97,16  ; n3571 t=116.408s dur=100ms, freq=2217Hz, sample=97, buffer_id=10:61
    db 0,0,100,0,85,127,17,25,85,4,85,16  ; n3572 t=116.408s dur=100ms, freq=1109Hz, sample=85, buffer_id=10:55
    db 0,0,100,0,73,127,18,26,42,2,73,18  ; n3573 t=116.408s dur=100ms, freq=554Hz, sample=73, buffer_id=12:49
    db 0,0,159,0,54,127,19,27,156,0,54,19  ; n3574 t=116.408s dur=159ms, freq=156Hz, sample=54, buffer_id=13:36
    db 78,0,159,0,42,127,20,28,78,0,42,20  ; n3575 t=116.408s dur=159ms, freq=78Hz, sample=42, buffer_id=14:2A
    db 13,0,100,0,42,127,10,30,92,0,42,10  ; n3576 t=116.486s dur=100ms, freq=92Hz, sample=42, buffer_id=0A:2A
    db 0,0,113,0,94,127,1,2,73,7,94,1  ; n3577 t=116.499s dur=113ms, freq=1865Hz, sample=94, buffer_id=01:5E
    db 0,0,113,0,85,127,2,29,85,4,85,2  ; n3578 t=116.499s dur=113ms, freq=1109Hz, sample=85, buffer_id=02:55
    db 0,0,113,0,78,127,3,31,228,2,78,3  ; n3579 t=116.499s dur=113ms, freq=740Hz, sample=78, buffer_id=03:4E [TRUNCATE prev:ch31 @115771.7ms -> 116499.0ms]
    db 0,0,113,0,70,127,4,18,210,1,70,4  ; n3580 t=116.499s dur=113ms, freq=466Hz, sample=70, buffer_id=04:46 [TRUNCATE prev:ch18 @116044.5ms -> 116499.0ms]
    db 0,0,113,0,66,127,5,3,114,1,66,5  ; n3581 t=116.499s dur=113ms, freq=370Hz, sample=66, buffer_id=05:42 [TRUNCATE prev:ch3 @116226.3ms -> 116499.0ms]
    db 0,0,113,0,61,127,6,5,21,1,61,5  ; n3582 t=116.499s dur=113ms, freq=277Hz, sample=61, buffer_id=05:3D [TRUNCATE prev:ch5 @116226.3ms -> 116499.0ms]
    db 0,0,100,0,97,127,16,14,169,8,97,16  ; n3583 t=116.499s dur=100ms, freq=2217Hz, sample=97, buffer_id=10:61 [TRUNCATE prev:ch14 @116226.3ms -> 116499.0ms]
    db 0,0,100,0,85,127,17,22,85,4,85,16  ; n3584 t=116.499s dur=100ms, freq=1109Hz, sample=85, buffer_id=10:55 [TRUNCATE prev:ch22 @116226.3ms -> 116499.0ms]
    db 66,0,100,0,73,127,18,23,42,2,73,18  ; n3585 t=116.499s dur=100ms, freq=554Hz, sample=73, buffer_id=12:49 [TRUNCATE prev:ch23 @116226.3ms -> 116499.0ms]
    db 25,0,100,0,42,127,10,0,92,0,42,10  ; n3586 t=116.565s dur=100ms, freq=92Hz, sample=42, buffer_id=0A:2A [TRUNCATE prev:ch0 @116247.5ms -> 116564.9ms]
    db 0,0,181,0,97,127,1,1,169,8,97,1  ; n3587 t=116.590s dur=181ms, freq=2217Hz, sample=97, buffer_id=01:61 [TRUNCATE prev:ch1 @116408.1ms -> 116589.9ms]
    db 0,0,181,0,94,127,2,4,73,7,94,2  ; n3588 t=116.590s dur=181ms, freq=1865Hz, sample=94, buffer_id=02:5E [TRUNCATE prev:ch4 @116408.1ms -> 116589.9ms]
    db 0,0,181,0,85,127,3,9,85,4,85,3  ; n3589 t=116.590s dur=181ms, freq=1109Hz, sample=85, buffer_id=03:55 [TRUNCATE prev:ch9 @116408.1ms -> 116589.9ms]
    db 0,0,181,0,78,127,4,11,228,2,78,4  ; n3590 t=116.590s dur=181ms, freq=740Hz, sample=78, buffer_id=04:4E [TRUNCATE prev:ch11 @116408.1ms -> 116589.9ms]
    db 0,0,181,0,70,127,5,13,210,1,70,5  ; n3591 t=116.590s dur=181ms, freq=466Hz, sample=70, buffer_id=05:46 [TRUNCATE prev:ch13 @116408.1ms -> 116589.9ms]
    db 0,0,181,0,66,127,6,15,114,1,66,5  ; n3592 t=116.590s dur=181ms, freq=370Hz, sample=66, buffer_id=05:42 [TRUNCATE prev:ch15 @116408.1ms -> 116589.9ms]
    db 0,0,100,0,97,127,16,24,169,8,97,16  ; n3593 t=116.590s dur=100ms, freq=2217Hz, sample=97, buffer_id=10:61 [TRUNCATE prev:ch24 @116408.1ms -> 116589.9ms]
    db 0,0,100,0,85,127,17,25,85,4,85,16  ; n3594 t=116.590s dur=100ms, freq=1109Hz, sample=85, buffer_id=10:55 [TRUNCATE prev:ch25 @116408.1ms -> 116589.9ms]
    db 0,0,100,0,73,127,18,26,42,2,73,18  ; n3595 t=116.590s dur=100ms, freq=554Hz, sample=73, buffer_id=12:49 [TRUNCATE prev:ch26 @116408.1ms -> 116589.9ms]
    db 0,0,159,0,47,127,19,6,139,0,47,19  ; n3596 t=116.590s dur=159ms, freq=139Hz, sample=47, buffer_id=13:2F [TRUNCATE prev:ch6 @116326.3ms -> 116589.9ms]
    db 54,0,159,0,35,127,20,7,69,0,35,20  ; n3597 t=116.590s dur=159ms, freq=69Hz, sample=35, buffer_id=14:23 [TRUNCATE prev:ch7 @116406.6ms -> 116589.9ms]
    db 37,0,100,0,42,127,10,30,92,0,42,10  ; n3598 t=116.644s dur=100ms, freq=92Hz, sample=42, buffer_id=0A:2A [TRUNCATE prev:ch30 @116486.1ms -> 116643.7ms]
    db 0,0,100,0,97,127,16,14,169,8,97,16  ; n3599 t=116.681s dur=100ms, freq=2217Hz, sample=97, buffer_id=10:61 [TRUNCATE prev:ch14 @116499.0ms -> 116680.8ms]
    db 0,0,100,0,85,127,17,22,85,4,85,16  ; n3600 t=116.681s dur=100ms, freq=1109Hz, sample=85, buffer_id=10:55 [TRUNCATE prev:ch22 @116499.0ms -> 116680.8ms]
    db 89,0,100,0,73,127,18,23,42,2,73,18  ; n3601 t=116.681s dur=100ms, freq=554Hz, sample=73, buffer_id=12:49 [TRUNCATE prev:ch23 @116499.0ms -> 116680.8ms]
    db 2,0,159,0,42,127,10,16,92,0,42,10  ; n3602 t=116.769s dur=159ms, freq=92Hz, sample=42, buffer_id=0A:2A
    db 0,0,100,0,54,127,7,17,185,0,54,7  ; n3603 t=116.772s dur=100ms, freq=185Hz, sample=54, buffer_id=07:36
    db 0,0,100,0,66,127,7,19,114,1,66,7  ; n3604 t=116.772s dur=100ms, freq=370Hz, sample=66, buffer_id=07:42
    db 0,0,100,0,66,127,9,20,114,1,66,9  ; n3605 t=116.772s dur=100ms, freq=370Hz, sample=66, buffer_id=09:42
    db 0,0,100,0,78,127,9,21,228,2,78,9  ; n3606 t=116.772s dur=100ms, freq=740Hz, sample=78, buffer_id=09:4E
    db 0,0,100,0,54,127,12,27,185,0,54,11  ; n3607 t=116.772s dur=100ms, freq=185Hz, sample=54, buffer_id=0B:36
    db 0,0,100,0,42,127,13,28,92,0,42,13  ; n3608 t=116.772s dur=100ms, freq=92Hz, sample=42, buffer_id=0D:2A
    db 0,0,159,0,90,127,16,8,200,5,90,16  ; n3609 t=116.772s dur=159ms, freq=1480Hz, sample=90, buffer_id=10:5A [TRUNCATE prev:ch8 @116408.1ms -> 116771.7ms]
    db 0,0,159,0,78,127,17,10,228,2,78,16  ; n3610 t=116.772s dur=159ms, freq=740Hz, sample=78, buffer_id=10:4E [TRUNCATE prev:ch10 @116408.1ms -> 116771.7ms]
    db 0,0,159,0,66,127,18,12,114,1,66,18  ; n3611 t=116.772s dur=159ms, freq=370Hz, sample=66, buffer_id=12:42 [TRUNCATE prev:ch12 @116408.1ms -> 116771.7ms]
    db 0,0,159,0,54,127,19,2,185,0,54,19  ; n3612 t=116.772s dur=159ms, freq=185Hz, sample=54, buffer_id=13:36 [TRUNCATE prev:ch2 @116499.0ms -> 116771.7ms]
    db 180,0,159,0,42,127,20,3,92,0,42,20  ; n3613 t=116.772s dur=159ms, freq=92Hz, sample=42, buffer_id=14:2A [TRUNCATE prev:ch3 @116499.0ms -> 116771.7ms]
    db 2,0,159,0,42,127,10,5,92,0,42,10  ; n3614 t=116.951s dur=159ms, freq=92Hz, sample=42, buffer_id=0A:2A
    db 0,0,100,0,57,127,7,0,208,0,57,7  ; n3615 t=116.954s dur=100ms, freq=208Hz, sample=57, buffer_id=07:39
    db 0,0,100,0,66,127,7,6,114,1,66,7  ; n3616 t=116.954s dur=100ms, freq=370Hz, sample=66, buffer_id=07:42
    db 0,0,100,0,66,127,9,7,159,1,66,9  ; n3617 t=116.954s dur=100ms, freq=415Hz, sample=66, buffer_id=09:42
    db 0,0,100,0,78,127,9,18,228,2,78,9  ; n3618 t=116.954s dur=100ms, freq=740Hz, sample=78, buffer_id=09:4E
    db 0,0,159,0,90,127,16,24,125,6,90,16  ; n3619 t=116.954s dur=159ms, freq=1661Hz, sample=90, buffer_id=10:5A
    db 0,0,159,0,78,127,17,25,63,3,78,16  ; n3620 t=116.954s dur=159ms, freq=831Hz, sample=78, buffer_id=10:4E
    db 0,0,159,0,66,127,18,26,159,1,66,18  ; n3621 t=116.954s dur=159ms, freq=415Hz, sample=66, buffer_id=12:42
    db 0,0,159,0,54,127,19,29,175,0,54,19  ; n3622 t=116.954s dur=159ms, freq=175Hz, sample=54, buffer_id=13:36
    db 180,0,159,0,42,127,20,30,87,0,42,20  ; n3623 t=116.954s dur=159ms, freq=87Hz, sample=42, buffer_id=14:2A
    db 2,0,159,0,42,127,10,1,92,0,42,10  ; n3624 t=117.133s dur=159ms, freq=92Hz, sample=42, buffer_id=0A:2A
    db 0,0,113,0,97,127,1,2,169,8,97,1  ; n3625 t=117.135s dur=113ms, freq=2217Hz, sample=97, buffer_id=01:61
    db 0,0,113,0,94,127,2,3,73,7,94,2  ; n3626 t=117.135s dur=113ms, freq=1865Hz, sample=94, buffer_id=02:5E
    db 0,0,107,1,90,127,2,4,200,5,90,2  ; n3627 t=117.135s dur=363ms, freq=1480Hz, sample=90, buffer_id=02:5A
    db 0,0,113,0,85,127,3,8,85,4,85,3  ; n3628 t=117.135s dur=113ms, freq=1109Hz, sample=85, buffer_id=03:55
    db 0,0,107,1,85,127,3,10,164,3,85,3  ; n3629 t=117.135s dur=363ms, freq=932Hz, sample=85, buffer_id=03:55
    db 0,0,113,0,78,127,4,9,228,2,78,4  ; n3630 t=117.135s dur=113ms, freq=740Hz, sample=78, buffer_id=04:4E
    db 0,0,107,1,73,127,4,11,42,2,73,4  ; n3631 t=117.135s dur=363ms, freq=554Hz, sample=73, buffer_id=04:49
    db 0,0,113,0,70,127,5,12,210,1,70,5  ; n3632 t=117.135s dur=113ms, freq=466Hz, sample=70, buffer_id=05:46
    db 0,0,113,0,66,127,6,13,114,1,66,5  ; n3633 t=117.135s dur=113ms, freq=370Hz, sample=66, buffer_id=05:42
    db 0,0,100,0,58,127,7,14,233,0,58,7  ; n3634 t=117.135s dur=100ms, freq=233Hz, sample=58, buffer_id=07:3A
    db 0,0,100,0,66,127,7,15,114,1,66,7  ; n3635 t=117.135s dur=100ms, freq=370Hz, sample=66, buffer_id=07:42
    db 0,0,100,0,66,127,9,16,210,1,66,9  ; n3636 t=117.135s dur=100ms, freq=466Hz, sample=66, buffer_id=09:42
    db 0,0,100,0,78,127,9,17,228,2,78,9  ; n3637 t=117.135s dur=100ms, freq=740Hz, sample=78, buffer_id=09:4E
    db 0,0,100,0,61,127,11,19,21,1,61,11  ; n3638 t=117.135s dur=100ms, freq=277Hz, sample=61, buffer_id=0B:3D
    db 0,0,100,0,66,127,11,20,114,1,66,11  ; n3639 t=117.135s dur=100ms, freq=370Hz, sample=66, buffer_id=0B:42
    db 0,0,100,0,58,127,12,21,233,0,58,11  ; n3640 t=117.135s dur=100ms, freq=233Hz, sample=58, buffer_id=0B:3A
    db 0,0,159,0,97,127,16,22,73,7,97,16  ; n3641 t=117.135s dur=159ms, freq=1865Hz, sample=97, buffer_id=10:61
    db 0,0,159,0,85,127,17,23,164,3,85,16  ; n3642 t=117.135s dur=159ms, freq=932Hz, sample=85, buffer_id=10:55
    db 0,0,159,0,73,127,18,27,210,1,73,18  ; n3643 t=117.135s dur=159ms, freq=466Hz, sample=73, buffer_id=12:49
    db 0,0,159,0,54,127,19,28,156,0,54,19  ; n3644 t=117.135s dur=159ms, freq=156Hz, sample=54, buffer_id=13:36
    db 91,0,159,0,42,127,20,31,78,0,42,20  ; n3645 t=117.135s dur=159ms, freq=78Hz, sample=42, buffer_id=14:2A
    db 0,0,113,0,94,127,1,5,73,7,94,1  ; n3646 t=117.226s dur=113ms, freq=1865Hz, sample=94, buffer_id=01:5E [TRUNCATE prev:ch5 @116951.3ms -> 117226.3ms]
    db 0,0,113,0,85,127,2,0,85,4,85,2  ; n3647 t=117.226s dur=113ms, freq=1109Hz, sample=85, buffer_id=02:55 [TRUNCATE prev:ch0 @116953.5ms -> 117226.3ms]
    db 0,0,113,0,78,127,3,6,228,2,78,3  ; n3648 t=117.226s dur=113ms, freq=740Hz, sample=78, buffer_id=03:4E [TRUNCATE prev:ch6 @116953.5ms -> 117226.3ms]
    db 0,0,113,0,70,127,4,7,210,1,70,4  ; n3649 t=117.226s dur=113ms, freq=466Hz, sample=70, buffer_id=04:46 [TRUNCATE prev:ch7 @116953.5ms -> 117226.3ms]
    db 0,0,113,0,66,127,5,18,114,1,66,5  ; n3650 t=117.226s dur=113ms, freq=370Hz, sample=66, buffer_id=05:42 [TRUNCATE prev:ch18 @116953.5ms -> 117226.3ms]
    db 89,0,113,0,61,127,6,24,21,1,61,5  ; n3651 t=117.226s dur=113ms, freq=277Hz, sample=61, buffer_id=05:3D [TRUNCATE prev:ch24 @116953.5ms -> 117226.3ms]
    db 2,0,159,0,42,127,10,25,92,0,42,10  ; n3652 t=117.315s dur=159ms, freq=92Hz, sample=42, buffer_id=0A:2A
    db 0,0,181,0,97,127,1,26,169,8,97,1  ; n3653 t=117.317s dur=181ms, freq=2217Hz, sample=97, buffer_id=01:61
    db 0,0,181,0,94,127,2,29,73,7,94,2  ; n3654 t=117.317s dur=181ms, freq=1865Hz, sample=94, buffer_id=02:5E
    db 0,0,181,0,85,127,3,30,85,4,85,3  ; n3655 t=117.317s dur=181ms, freq=1109Hz, sample=85, buffer_id=03:55
    db 0,0,181,0,78,127,4,9,228,2,78,4  ; n3656 t=117.317s dur=181ms, freq=740Hz, sample=78, buffer_id=04:4E [TRUNCATE prev:ch9 @117135.4ms -> 117317.2ms]
    db 0,0,181,0,70,127,5,12,210,1,70,5  ; n3657 t=117.317s dur=181ms, freq=466Hz, sample=70, buffer_id=05:46 [TRUNCATE prev:ch12 @117135.4ms -> 117317.2ms]
    db 0,0,181,0,66,127,6,13,114,1,66,5  ; n3658 t=117.317s dur=181ms, freq=370Hz, sample=66, buffer_id=05:42 [TRUNCATE prev:ch13 @117135.4ms -> 117317.2ms]
    db 0,0,100,0,59,127,7,1,247,0,59,7  ; n3659 t=117.317s dur=100ms, freq=247Hz, sample=59, buffer_id=07:3B [TRUNCATE prev:ch1 @117133.1ms -> 117317.2ms]
    db 0,0,100,0,66,127,7,15,114,1,66,7  ; n3660 t=117.317s dur=100ms, freq=370Hz, sample=66, buffer_id=07:42 [TRUNCATE prev:ch15 @117135.4ms -> 117317.2ms]
    db 0,0,100,0,66,127,9,16,238,1,66,9  ; n3661 t=117.317s dur=100ms, freq=494Hz, sample=66, buffer_id=09:42 [TRUNCATE prev:ch16 @117135.4ms -> 117317.2ms]
    db 0,0,100,0,78,127,9,17,228,2,78,9  ; n3662 t=117.317s dur=100ms, freq=740Hz, sample=78, buffer_id=09:4E [TRUNCATE prev:ch17 @117135.4ms -> 117317.2ms]
    db 0,0,159,0,97,127,16,22,184,7,97,16  ; n3663 t=117.317s dur=159ms, freq=1976Hz, sample=97, buffer_id=10:61 [TRUNCATE prev:ch22 @117135.4ms -> 117317.2ms]
    db 0,0,159,0,85,127,17,23,220,3,85,16  ; n3664 t=117.317s dur=159ms, freq=988Hz, sample=85, buffer_id=10:55 [TRUNCATE prev:ch23 @117135.4ms -> 117317.2ms]
    db 0,0,159,0,73,127,18,27,238,1,73,18  ; n3665 t=117.317s dur=159ms, freq=494Hz, sample=73, buffer_id=12:49 [TRUNCATE prev:ch27 @117135.4ms -> 117317.2ms]
    db 0,0,159,0,47,127,19,2,139,0,47,19  ; n3666 t=117.317s dur=159ms, freq=139Hz, sample=47, buffer_id=13:2F [TRUNCATE prev:ch2 @117135.4ms -> 117317.2ms]
    db 180,0,159,0,35,127,20,3,69,0,35,20  ; n3667 t=117.317s dur=159ms, freq=69Hz, sample=35, buffer_id=14:23 [TRUNCATE prev:ch3 @117135.4ms -> 117317.2ms]
    db 2,0,159,0,42,127,10,8,92,0,42,10  ; n3668 t=117.497s dur=159ms, freq=92Hz, sample=42, buffer_id=0A:2A
    db 0,0,100,0,61,127,7,14,21,1,61,7  ; n3669 t=117.499s dur=100ms, freq=277Hz, sample=61, buffer_id=07:3D
    db 0,0,100,0,66,127,7,19,114,1,66,7  ; n3670 t=117.499s dur=100ms, freq=370Hz, sample=66, buffer_id=07:42
    db 0,0,100,0,78,127,9,20,42,2,78,9  ; n3671 t=117.499s dur=100ms, freq=554Hz, sample=78, buffer_id=09:4E
    db 0,0,100,0,78,127,9,21,228,2,78,9  ; n3672 t=117.499s dur=100ms, freq=740Hz, sample=78, buffer_id=09:4E
    db 0,0,100,0,54,127,12,28,185,0,54,11  ; n3673 t=117.499s dur=100ms, freq=185Hz, sample=54, buffer_id=0B:36
    db 0,0,100,0,42,127,13,31,92,0,42,13  ; n3674 t=117.499s dur=100ms, freq=92Hz, sample=42, buffer_id=0D:2A
    db 0,0,159,0,97,127,16,22,169,8,97,16  ; n3675 t=117.499s dur=159ms, freq=2217Hz, sample=97, buffer_id=10:61 [TRUNCATE prev:ch22 @117317.2ms -> 117499.0ms]
    db 0,0,159,0,85,127,17,23,85,4,85,16  ; n3676 t=117.499s dur=159ms, freq=1109Hz, sample=85, buffer_id=10:55 [TRUNCATE prev:ch23 @117317.2ms -> 117499.0ms]
    db 0,0,159,0,73,127,18,27,42,2,73,18  ; n3677 t=117.499s dur=159ms, freq=554Hz, sample=73, buffer_id=12:49 [TRUNCATE prev:ch27 @117317.2ms -> 117499.0ms]
    db 0,0,159,0,54,127,19,4,185,0,54,19  ; n3678 t=117.499s dur=159ms, freq=185Hz, sample=54, buffer_id=13:36 [TRUNCATE prev:ch4 @117135.4ms -> 117499.0ms]
    db 180,0,159,0,42,127,20,10,92,0,42,20  ; n3679 t=117.499s dur=159ms, freq=92Hz, sample=42, buffer_id=14:2A [TRUNCATE prev:ch10 @117135.4ms -> 117499.0ms]
    db 2,0,159,0,42,127,10,0,92,0,42,10  ; n3680 t=117.678s dur=159ms, freq=92Hz, sample=42, buffer_id=0A:2A
    db 0,0,100,0,58,127,7,1,233,0,58,7  ; n3681 t=117.681s dur=100ms, freq=233Hz, sample=58, buffer_id=07:3A
    db 0,0,100,0,66,127,7,2,114,1,66,7  ; n3682 t=117.681s dur=100ms, freq=370Hz, sample=66, buffer_id=07:42
    db 0,0,100,0,66,127,9,3,210,1,66,9  ; n3683 t=117.681s dur=100ms, freq=466Hz, sample=66, buffer_id=09:42
    db 0,0,100,0,78,127,9,5,228,2,78,9  ; n3684 t=117.681s dur=100ms, freq=740Hz, sample=78, buffer_id=09:4E
    db 0,0,159,0,97,127,16,6,73,7,97,16  ; n3685 t=117.681s dur=159ms, freq=1865Hz, sample=97, buffer_id=10:61
    db 0,0,159,0,85,127,17,7,164,3,85,16  ; n3686 t=117.681s dur=159ms, freq=932Hz, sample=85, buffer_id=10:55
    db 0,0,159,0,73,127,18,15,210,1,73,18  ; n3687 t=117.681s dur=159ms, freq=466Hz, sample=73, buffer_id=12:49
    db 0,0,159,0,54,127,19,16,175,0,54,19  ; n3688 t=117.681s dur=159ms, freq=175Hz, sample=54, buffer_id=13:36
    db 180,0,159,0,42,127,20,17,87,0,42,20  ; n3689 t=117.681s dur=159ms, freq=87Hz, sample=42, buffer_id=14:2A
    db 2,0,84,1,42,127,10,4,92,0,42,10  ; n3690 t=117.860s dur=340ms, freq=92Hz, sample=42, buffer_id=0A:2A
    db 0,0,113,0,97,127,1,8,169,8,97,1  ; n3691 t=117.863s dur=113ms, freq=2217Hz, sample=97, buffer_id=01:61
    db 0,0,113,0,94,127,2,9,73,7,94,2  ; n3692 t=117.863s dur=113ms, freq=1865Hz, sample=94, buffer_id=02:5E
    db 0,0,107,1,90,127,2,10,200,5,90,2  ; n3693 t=117.863s dur=363ms, freq=1480Hz, sample=90, buffer_id=02:5A
    db 0,0,113,0,85,127,3,11,85,4,85,3  ; n3694 t=117.863s dur=113ms, freq=1109Hz, sample=85, buffer_id=03:55
    db 0,0,107,1,85,127,3,12,164,3,85,3  ; n3695 t=117.863s dur=363ms, freq=932Hz, sample=85, buffer_id=03:55
    db 0,0,113,0,78,127,4,13,228,2,78,4  ; n3696 t=117.863s dur=113ms, freq=740Hz, sample=78, buffer_id=04:4E
    db 0,0,107,1,73,127,4,14,42,2,73,4  ; n3697 t=117.863s dur=363ms, freq=554Hz, sample=73, buffer_id=04:49
    db 0,0,113,0,70,127,5,18,210,1,70,5  ; n3698 t=117.863s dur=113ms, freq=466Hz, sample=70, buffer_id=05:46
    db 0,0,113,0,66,127,6,19,114,1,66,5  ; n3699 t=117.863s dur=113ms, freq=370Hz, sample=66, buffer_id=05:42
    db 0,0,100,0,61,127,7,20,21,1,61,7  ; n3700 t=117.863s dur=100ms, freq=277Hz, sample=61, buffer_id=07:3D
    db 0,0,100,0,66,127,7,21,114,1,66,7  ; n3701 t=117.863s dur=100ms, freq=370Hz, sample=66, buffer_id=07:42
    db 0,0,100,0,78,127,9,22,42,2,78,9  ; n3702 t=117.863s dur=100ms, freq=554Hz, sample=78, buffer_id=09:4E
    db 0,0,100,0,78,127,9,23,228,2,78,9  ; n3703 t=117.863s dur=100ms, freq=740Hz, sample=78, buffer_id=09:4E
    db 0,0,100,0,61,127,11,24,21,1,61,11  ; n3704 t=117.863s dur=100ms, freq=277Hz, sample=61, buffer_id=0B:3D
    db 0,0,100,0,66,127,11,25,114,1,66,11  ; n3705 t=117.863s dur=100ms, freq=370Hz, sample=66, buffer_id=0B:42
    db 0,0,100,0,58,127,12,26,233,0,58,11  ; n3706 t=117.863s dur=100ms, freq=233Hz, sample=58, buffer_id=0B:3A
    db 0,0,100,0,97,127,16,27,169,8,97,16  ; n3707 t=117.863s dur=100ms, freq=2217Hz, sample=97, buffer_id=10:61
    db 0,0,100,0,85,127,17,28,85,4,85,16  ; n3708 t=117.863s dur=100ms, freq=1109Hz, sample=85, buffer_id=10:55
    db 0,0,100,0,73,127,18,29,42,2,73,18  ; n3709 t=117.863s dur=100ms, freq=554Hz, sample=73, buffer_id=12:49
    db 0,0,159,0,54,127,19,30,156,0,54,19  ; n3710 t=117.863s dur=159ms, freq=156Hz, sample=54, buffer_id=13:36
    db 91,0,159,0,42,127,20,31,78,0,42,20  ; n3711 t=117.863s dur=159ms, freq=78Hz, sample=42, buffer_id=14:2A
    db 0,0,113,0,94,127,1,0,73,7,94,1  ; n3712 t=117.954s dur=113ms, freq=1865Hz, sample=94, buffer_id=01:5E [TRUNCATE prev:ch0 @117678.5ms -> 117953.5ms]
    db 0,0,113,0,85,127,2,1,85,4,85,2  ; n3713 t=117.954s dur=113ms, freq=1109Hz, sample=85, buffer_id=02:55 [TRUNCATE prev:ch1 @117680.8ms -> 117953.5ms]
    db 0,0,113,0,78,127,3,2,228,2,78,3  ; n3714 t=117.954s dur=113ms, freq=740Hz, sample=78, buffer_id=03:4E [TRUNCATE prev:ch2 @117680.8ms -> 117953.5ms]
    db 0,0,113,0,70,127,4,3,210,1,70,4  ; n3715 t=117.954s dur=113ms, freq=466Hz, sample=70, buffer_id=04:46 [TRUNCATE prev:ch3 @117680.8ms -> 117953.5ms]
    db 0,0,113,0,66,127,5,5,114,1,66,5  ; n3716 t=117.954s dur=113ms, freq=370Hz, sample=66, buffer_id=05:42 [TRUNCATE prev:ch5 @117680.8ms -> 117953.5ms]
    db 0,0,113,0,61,127,6,6,21,1,61,5  ; n3717 t=117.954s dur=113ms, freq=277Hz, sample=61, buffer_id=05:3D [TRUNCATE prev:ch6 @117680.8ms -> 117953.5ms]
    db 0,0,100,0,97,127,16,7,169,8,97,16  ; n3718 t=117.954s dur=100ms, freq=2217Hz, sample=97, buffer_id=10:61 [TRUNCATE prev:ch7 @117680.8ms -> 117953.5ms]
    db 0,0,100,0,85,127,17,15,85,4,85,16  ; n3719 t=117.954s dur=100ms, freq=1109Hz, sample=85, buffer_id=10:55 [TRUNCATE prev:ch15 @117680.8ms -> 117953.5ms]
    db 91,0,100,0,73,127,18,16,42,2,73,18  ; n3720 t=117.954s dur=100ms, freq=554Hz, sample=73, buffer_id=12:49 [TRUNCATE prev:ch16 @117680.8ms -> 117953.5ms]
    db 0,0,181,0,97,127,1,17,169,8,97,1  ; n3721 t=118.044s dur=181ms, freq=2217Hz, sample=97, buffer_id=01:61
    db 0,0,181,0,94,127,2,9,73,7,94,2  ; n3722 t=118.044s dur=181ms, freq=1865Hz, sample=94, buffer_id=02:5E [TRUNCATE prev:ch9 @117862.6ms -> 118044.5ms]
    db 0,0,181,0,85,127,3,11,85,4,85,3  ; n3723 t=118.044s dur=181ms, freq=1109Hz, sample=85, buffer_id=03:55 [TRUNCATE prev:ch11 @117862.6ms -> 118044.5ms]
    db 0,0,181,0,78,127,4,13,228,2,78,4  ; n3724 t=118.044s dur=181ms, freq=740Hz, sample=78, buffer_id=04:4E [TRUNCATE prev:ch13 @117862.6ms -> 118044.5ms]
    db 0,0,181,0,70,127,5,18,210,1,70,5  ; n3725 t=118.044s dur=181ms, freq=466Hz, sample=70, buffer_id=05:46 [TRUNCATE prev:ch18 @117862.6ms -> 118044.5ms]
    db 0,0,181,0,66,127,6,19,114,1,66,5  ; n3726 t=118.044s dur=181ms, freq=370Hz, sample=66, buffer_id=05:42 [TRUNCATE prev:ch19 @117862.6ms -> 118044.5ms]
    db 0,0,100,0,97,127,16,27,169,8,97,16  ; n3727 t=118.044s dur=100ms, freq=2217Hz, sample=97, buffer_id=10:61 [TRUNCATE prev:ch27 @117862.6ms -> 118044.5ms]
    db 0,0,100,0,85,127,17,28,85,4,85,16  ; n3728 t=118.044s dur=100ms, freq=1109Hz, sample=85, buffer_id=10:55 [TRUNCATE prev:ch28 @117862.6ms -> 118044.5ms]
    db 0,0,100,0,73,127,18,29,42,2,73,18  ; n3729 t=118.044s dur=100ms, freq=554Hz, sample=73, buffer_id=12:49 [TRUNCATE prev:ch29 @117862.6ms -> 118044.5ms]
    db 0,0,159,0,47,127,19,4,139,0,47,19  ; n3730 t=118.044s dur=159ms, freq=139Hz, sample=47, buffer_id=13:2F [TRUNCATE prev:ch4 @117860.4ms -> 118044.5ms]
    db 91,0,159,0,35,127,20,8,69,0,35,20  ; n3731 t=118.044s dur=159ms, freq=69Hz, sample=35, buffer_id=14:23 [TRUNCATE prev:ch8 @117862.6ms -> 118044.5ms]
    db 0,0,100,0,97,127,16,7,169,8,97,16  ; n3732 t=118.135s dur=100ms, freq=2217Hz, sample=97, buffer_id=10:61 [TRUNCATE prev:ch7 @117953.5ms -> 118135.4ms]
    db 0,0,100,0,85,127,17,15,85,4,85,16  ; n3733 t=118.135s dur=100ms, freq=1109Hz, sample=85, buffer_id=10:55 [TRUNCATE prev:ch15 @117953.5ms -> 118135.4ms]
    db 89,0,100,0,73,127,18,16,42,2,73,18  ; n3734 t=118.135s dur=100ms, freq=554Hz, sample=73, buffer_id=12:49 [TRUNCATE prev:ch16 @117953.5ms -> 118135.4ms]
    db 2,0,159,0,42,127,10,20,92,0,42,10  ; n3735 t=118.224s dur=159ms, freq=92Hz, sample=42, buffer_id=0A:2A
    db 0,0,100,0,62,127,7,21,55,1,62,7  ; n3736 t=118.226s dur=100ms, freq=311Hz, sample=62, buffer_id=07:3E
    db 0,0,100,0,66,127,7,22,114,1,66,7  ; n3737 t=118.226s dur=100ms, freq=370Hz, sample=66, buffer_id=07:42
    db 0,0,100,0,78,127,9,24,110,2,78,9  ; n3738 t=118.226s dur=100ms, freq=622Hz, sample=78, buffer_id=09:4E
    db 0,0,100,0,78,127,9,25,228,2,78,9  ; n3739 t=118.226s dur=100ms, freq=740Hz, sample=78, buffer_id=09:4E
    db 0,0,100,0,50,127,12,23,156,0,50,11  ; n3740 t=118.226s dur=100ms, freq=156Hz, sample=50, buffer_id=0B:32
    db 0,0,100,0,42,127,13,26,78,0,42,13  ; n3741 t=118.226s dur=100ms, freq=78Hz, sample=42, buffer_id=0D:2A
    db 0,0,159,0,99,127,16,30,185,9,99,16  ; n3742 t=118.226s dur=159ms, freq=2489Hz, sample=99, buffer_id=10:63
    db 0,0,159,0,87,127,17,31,221,4,87,16  ; n3743 t=118.226s dur=159ms, freq=1245Hz, sample=87, buffer_id=10:57
    db 0,0,159,0,75,127,18,10,110,2,75,18  ; n3744 t=118.226s dur=159ms, freq=622Hz, sample=75, buffer_id=12:4B [TRUNCATE prev:ch10 @117862.6ms -> 118226.3ms]
    db 0,0,159,0,54,127,19,12,156,0,54,19  ; n3745 t=118.226s dur=159ms, freq=156Hz, sample=54, buffer_id=13:36 [TRUNCATE prev:ch12 @117862.6ms -> 118226.3ms]
    db 180,0,159,0,42,127,20,14,78,0,42,20  ; n3746 t=118.226s dur=159ms, freq=78Hz, sample=42, buffer_id=14:2A [TRUNCATE prev:ch14 @117862.6ms -> 118226.3ms]
    db 2,0,159,0,42,127,10,0,92,0,42,10  ; n3747 t=118.406s dur=159ms, freq=92Hz, sample=42, buffer_id=0A:2A
    db 0,0,100,0,58,127,7,1,233,0,58,7  ; n3748 t=118.408s dur=100ms, freq=233Hz, sample=58, buffer_id=07:3A
    db 0,0,100,0,66,127,7,2,114,1,66,7  ; n3749 t=118.408s dur=100ms, freq=370Hz, sample=66, buffer_id=07:42
    db 0,0,100,0,66,127,9,3,210,1,66,9  ; n3750 t=118.408s dur=100ms, freq=466Hz, sample=66, buffer_id=09:42
    db 0,0,100,0,78,127,9,4,228,2,78,9  ; n3751 t=118.408s dur=100ms, freq=740Hz, sample=78, buffer_id=09:4E
    db 0,0,159,0,97,127,16,5,73,7,97,16  ; n3752 t=118.408s dur=159ms, freq=1865Hz, sample=97, buffer_id=10:61
    db 0,0,159,0,85,127,17,6,164,3,85,16  ; n3753 t=118.408s dur=159ms, freq=932Hz, sample=85, buffer_id=10:55
    db 0,0,159,0,73,127,18,8,210,1,73,18  ; n3754 t=118.408s dur=159ms, freq=466Hz, sample=73, buffer_id=12:49
    db 0,0,159,0,47,127,19,27,139,0,47,19  ; n3755 t=118.408s dur=159ms, freq=139Hz, sample=47, buffer_id=13:2F
    db 179,0,159,0,35,127,20,28,69,0,35,20  ; n3756 t=118.408s dur=159ms, freq=69Hz, sample=35, buffer_id=14:23
    db 2,0,84,1,42,127,10,7,92,0,42,10  ; n3757 t=118.588s dur=340ms, freq=92Hz, sample=42, buffer_id=0A:2A
    db 0,0,113,0,99,127,1,9,185,9,99,1  ; n3758 t=118.590s dur=113ms, freq=2489Hz, sample=99, buffer_id=01:63
    db 0,0,113,0,94,127,2,10,73,7,94,2  ; n3759 t=118.590s dur=113ms, freq=1865Hz, sample=94, buffer_id=02:5E
    db 0,0,107,1,90,127,2,11,200,5,90,2  ; n3760 t=118.590s dur=363ms, freq=1480Hz, sample=90, buffer_id=02:5A
    db 0,0,113,0,87,127,3,12,221,4,87,3  ; n3761 t=118.590s dur=113ms, freq=1245Hz, sample=87, buffer_id=03:57
    db 0,0,107,1,85,127,3,13,164,3,85,3  ; n3762 t=118.590s dur=363ms, freq=932Hz, sample=85, buffer_id=03:55
    db 0,0,113,0,78,127,4,14,228,2,78,4  ; n3763 t=118.590s dur=113ms, freq=740Hz, sample=78, buffer_id=04:4E
    db 0,0,87,1,74,127,4,15,110,2,74,4  ; n3764 t=118.590s dur=343ms, freq=622Hz, sample=74, buffer_id=04:4A
    db 0,0,113,0,70,127,5,16,210,1,70,5  ; n3765 t=118.590s dur=113ms, freq=466Hz, sample=70, buffer_id=05:46
    db 0,0,113,0,66,127,6,17,114,1,66,5  ; n3766 t=118.590s dur=113ms, freq=370Hz, sample=66, buffer_id=05:42
    db 0,0,100,0,62,127,7,18,55,1,62,7  ; n3767 t=118.590s dur=100ms, freq=311Hz, sample=62, buffer_id=07:3E
    db 0,0,100,0,66,127,7,19,114,1,66,7  ; n3768 t=118.590s dur=100ms, freq=370Hz, sample=66, buffer_id=07:42
    db 0,0,100,0,78,127,9,20,110,2,78,9  ; n3769 t=118.590s dur=100ms, freq=622Hz, sample=78, buffer_id=09:4E
    db 0,0,100,0,78,127,9,21,228,2,78,9  ; n3770 t=118.590s dur=100ms, freq=740Hz, sample=78, buffer_id=09:4E
    db 0,0,100,0,62,127,11,22,55,1,62,11  ; n3771 t=118.590s dur=100ms, freq=311Hz, sample=62, buffer_id=0B:3E
    db 0,0,100,0,66,127,11,23,114,1,66,11  ; n3772 t=118.590s dur=100ms, freq=370Hz, sample=66, buffer_id=0B:42
    db 0,0,100,0,58,127,12,24,233,0,58,11  ; n3773 t=118.590s dur=100ms, freq=233Hz, sample=58, buffer_id=0B:3A
    db 0,0,100,0,99,127,16,25,185,9,99,16  ; n3774 t=118.590s dur=100ms, freq=2489Hz, sample=99, buffer_id=10:63
    db 0,0,100,0,87,127,17,26,221,4,87,16  ; n3775 t=118.590s dur=100ms, freq=1245Hz, sample=87, buffer_id=10:57
    db 0,0,100,0,75,127,18,29,110,2,75,18  ; n3776 t=118.590s dur=100ms, freq=622Hz, sample=75, buffer_id=12:4B
    db 0,0,159,0,54,127,19,30,156,0,54,19  ; n3777 t=118.590s dur=159ms, freq=156Hz, sample=54, buffer_id=13:36
    db 91,0,159,0,42,127,20,31,78,0,42,20  ; n3778 t=118.590s dur=159ms, freq=78Hz, sample=42, buffer_id=14:2A
    db 0,0,113,0,94,127,1,0,73,7,94,1  ; n3779 t=118.681s dur=113ms, freq=1865Hz, sample=94, buffer_id=01:5E [TRUNCATE prev:ch0 @118405.8ms -> 118680.8ms]
    db 0,0,113,0,86,127,2,1,221,4,86,2  ; n3780 t=118.681s dur=113ms, freq=1245Hz, sample=86, buffer_id=02:56 [TRUNCATE prev:ch1 @118408.1ms -> 118680.8ms]
    db 0,0,113,0,78,127,3,2,228,2,78,3  ; n3781 t=118.681s dur=113ms, freq=740Hz, sample=78, buffer_id=03:4E [TRUNCATE prev:ch2 @118408.1ms -> 118680.8ms]
    db 0,0,113,0,70,127,4,3,210,1,70,4  ; n3782 t=118.681s dur=113ms, freq=466Hz, sample=70, buffer_id=04:46 [TRUNCATE prev:ch3 @118408.1ms -> 118680.8ms]
    db 0,0,113,0,66,127,5,4,114,1,66,5  ; n3783 t=118.681s dur=113ms, freq=370Hz, sample=66, buffer_id=05:42 [TRUNCATE prev:ch4 @118408.1ms -> 118680.8ms]
    db 0,0,113,0,62,127,6,5,55,1,62,5  ; n3784 t=118.681s dur=113ms, freq=311Hz, sample=62, buffer_id=05:3E [TRUNCATE prev:ch5 @118408.1ms -> 118680.8ms]
    db 0,0,100,0,99,127,16,6,185,9,99,16  ; n3785 t=118.681s dur=100ms, freq=2489Hz, sample=99, buffer_id=10:63 [TRUNCATE prev:ch6 @118408.1ms -> 118680.8ms]
    db 0,0,100,0,87,127,17,8,221,4,87,16  ; n3786 t=118.681s dur=100ms, freq=1245Hz, sample=87, buffer_id=10:57 [TRUNCATE prev:ch8 @118408.1ms -> 118680.8ms]
    db 91,0,100,0,75,127,18,27,110,2,75,18  ; n3787 t=118.681s dur=100ms, freq=622Hz, sample=75, buffer_id=12:4B [TRUNCATE prev:ch27 @118408.1ms -> 118680.8ms]
    db 0,0,181,0,99,127,1,28,185,9,99,1  ; n3788 t=118.772s dur=181ms, freq=2489Hz, sample=99, buffer_id=01:63
    db 0,0,181,0,94,127,2,10,73,7,94,2  ; n3789 t=118.772s dur=181ms, freq=1865Hz, sample=94, buffer_id=02:5E [TRUNCATE prev:ch10 @118589.9ms -> 118771.7ms]
    db 0,0,181,0,87,127,3,12,221,4,87,3  ; n3790 t=118.772s dur=181ms, freq=1245Hz, sample=87, buffer_id=03:57 [TRUNCATE prev:ch12 @118589.9ms -> 118771.7ms]
    db 0,0,181,0,78,127,4,14,228,2,78,4  ; n3791 t=118.772s dur=181ms, freq=740Hz, sample=78, buffer_id=04:4E [TRUNCATE prev:ch14 @118589.9ms -> 118771.7ms]
    db 0,0,181,0,70,127,5,16,210,1,70,5  ; n3792 t=118.772s dur=181ms, freq=466Hz, sample=70, buffer_id=05:46 [TRUNCATE prev:ch16 @118589.9ms -> 118771.7ms]
    db 0,0,181,0,66,127,6,17,114,1,66,5  ; n3793 t=118.772s dur=181ms, freq=370Hz, sample=66, buffer_id=05:42 [TRUNCATE prev:ch17 @118589.9ms -> 118771.7ms]
    db 0,0,100,0,99,127,16,25,185,9,99,16  ; n3794 t=118.772s dur=100ms, freq=2489Hz, sample=99, buffer_id=10:63 [TRUNCATE prev:ch25 @118589.9ms -> 118771.7ms]
    db 0,0,100,0,87,127,17,26,221,4,87,16  ; n3795 t=118.772s dur=100ms, freq=1245Hz, sample=87, buffer_id=10:57 [TRUNCATE prev:ch26 @118589.9ms -> 118771.7ms]
    db 0,0,100,0,75,127,18,29,110,2,75,18  ; n3796 t=118.772s dur=100ms, freq=622Hz, sample=75, buffer_id=12:4B [TRUNCATE prev:ch29 @118589.9ms -> 118771.7ms]
    db 0,0,159,0,54,127,19,30,175,0,54,19  ; n3797 t=118.772s dur=159ms, freq=175Hz, sample=54, buffer_id=13:36 [TRUNCATE prev:ch30 @118589.9ms -> 118771.7ms]
    db 91,0,159,0,42,127,20,31,87,0,42,20  ; n3798 t=118.772s dur=159ms, freq=87Hz, sample=42, buffer_id=14:2A [TRUNCATE prev:ch31 @118589.9ms -> 118771.7ms]
    db 0,0,100,0,99,127,16,6,185,9,99,16  ; n3799 t=118.863s dur=100ms, freq=2489Hz, sample=99, buffer_id=10:63 [TRUNCATE prev:ch6 @118680.8ms -> 118862.6ms]
    db 0,0,100,0,87,127,17,8,221,4,87,16  ; n3800 t=118.863s dur=100ms, freq=1245Hz, sample=87, buffer_id=10:57 [TRUNCATE prev:ch8 @118680.8ms -> 118862.6ms]
    db 89,0,100,0,75,127,18,27,110,2,75,18  ; n3801 t=118.863s dur=100ms, freq=622Hz, sample=75, buffer_id=12:4B [TRUNCATE prev:ch27 @118680.8ms -> 118862.6ms]
    db 2,0,84,1,42,127,10,9,92,0,42,10  ; n3802 t=118.951s dur=340ms, freq=92Hz, sample=42, buffer_id=0A:2A
    db 0,0,127,0,61,127,7,18,21,1,61,7  ; n3803 t=118.954s dur=127ms, freq=277Hz, sample=61, buffer_id=07:3D
    db 0,0,192,2,66,127,7,20,114,1,66,7  ; n3804 t=118.954s dur=704ms, freq=370Hz, sample=66, buffer_id=07:42
    db 0,0,192,2,78,127,9,19,42,2,78,9  ; n3805 t=118.954s dur=704ms, freq=554Hz, sample=78, buffer_id=09:4E
    db 0,0,192,2,78,127,9,22,228,2,78,9  ; n3806 t=118.954s dur=704ms, freq=740Hz, sample=78, buffer_id=09:4E
    db 0,0,100,0,54,127,12,21,185,0,54,11  ; n3807 t=118.954s dur=100ms, freq=185Hz, sample=54, buffer_id=0B:36
    db 0,0,100,0,42,127,13,23,92,0,42,13  ; n3808 t=118.954s dur=100ms, freq=92Hz, sample=42, buffer_id=0D:2A
    db 0,0,100,0,97,127,16,24,169,8,97,16  ; n3809 t=118.954s dur=100ms, freq=2217Hz, sample=97, buffer_id=10:61
    db 0,0,100,0,85,127,17,7,85,4,85,16  ; n3810 t=118.954s dur=100ms, freq=1109Hz, sample=85, buffer_id=10:55 [TRUNCATE prev:ch7 @118587.6ms -> 118953.5ms]
    db 0,0,100,0,73,127,18,11,42,2,73,18  ; n3811 t=118.954s dur=100ms, freq=554Hz, sample=73, buffer_id=12:49 [TRUNCATE prev:ch11 @118589.9ms -> 118953.5ms]
    db 0,0,159,0,54,127,19,30,185,0,54,19  ; n3812 t=118.954s dur=159ms, freq=185Hz, sample=54, buffer_id=13:36 [TRUNCATE prev:ch30 @118771.7ms -> 118953.5ms]
    db 91,0,159,0,42,127,20,31,92,0,42,20  ; n3813 t=118.954s dur=159ms, freq=92Hz, sample=42, buffer_id=14:2A [TRUNCATE prev:ch31 @118771.7ms -> 118953.5ms]
    db 0,0,100,0,97,127,16,0,169,8,97,16  ; n3814 t=119.044s dur=100ms, freq=2217Hz, sample=97, buffer_id=10:61
    db 0,0,100,0,85,127,17,1,85,4,85,16  ; n3815 t=119.044s dur=100ms, freq=1109Hz, sample=85, buffer_id=10:55
    db 91,0,100,0,73,127,18,2,42,2,73,18  ; n3816 t=119.044s dur=100ms, freq=554Hz, sample=73, buffer_id=12:49
    db 0,0,100,0,97,127,16,3,169,8,97,16  ; n3817 t=119.135s dur=100ms, freq=2217Hz, sample=97, buffer_id=10:61
    db 0,0,100,0,85,127,17,4,85,4,85,16  ; n3818 t=119.135s dur=100ms, freq=1109Hz, sample=85, buffer_id=10:55
    db 0,0,100,0,73,127,18,5,42,2,73,18  ; n3819 t=119.135s dur=100ms, freq=554Hz, sample=73, buffer_id=12:49
    db 0,0,159,0,54,127,19,15,175,0,54,19  ; n3820 t=119.135s dur=159ms, freq=175Hz, sample=54, buffer_id=13:36
    db 91,0,159,0,42,127,20,25,87,0,42,20  ; n3821 t=119.135s dur=159ms, freq=87Hz, sample=42, buffer_id=14:2A
    db 0,0,100,0,97,127,16,6,169,8,97,16  ; n3822 t=119.226s dur=100ms, freq=2217Hz, sample=97, buffer_id=10:61
    db 0,0,100,0,85,127,17,8,85,4,85,16  ; n3823 t=119.226s dur=100ms, freq=1109Hz, sample=85, buffer_id=10:55
    db 91,0,100,0,73,127,18,10,42,2,73,18  ; n3824 t=119.226s dur=100ms, freq=554Hz, sample=73, buffer_id=12:49
    db 0,0,113,0,97,127,1,7,169,8,97,1  ; n3825 t=119.317s dur=113ms, freq=2217Hz, sample=97, buffer_id=01:61
    db 0,0,113,0,94,127,2,11,73,7,94,2  ; n3826 t=119.317s dur=113ms, freq=1865Hz, sample=94, buffer_id=02:5E
    db 0,0,107,1,90,127,2,12,200,5,90,2  ; n3827 t=119.317s dur=363ms, freq=1480Hz, sample=90, buffer_id=02:5A
    db 0,0,113,0,85,127,3,14,85,4,85,3  ; n3828 t=119.317s dur=113ms, freq=1109Hz, sample=85, buffer_id=03:55
    db 0,0,107,1,85,127,3,16,164,3,85,3  ; n3829 t=119.317s dur=363ms, freq=932Hz, sample=85, buffer_id=03:55
    db 0,0,113,0,78,127,4,13,228,2,78,4  ; n3830 t=119.317s dur=113ms, freq=740Hz, sample=78, buffer_id=04:4E
    db 0,0,107,1,73,127,4,17,42,2,73,4  ; n3831 t=119.317s dur=363ms, freq=554Hz, sample=73, buffer_id=04:49
    db 0,0,113,0,70,127,5,18,210,1,70,5  ; n3832 t=119.317s dur=113ms, freq=466Hz, sample=70, buffer_id=05:46
    db 0,0,113,0,66,127,6,21,114,1,66,5  ; n3833 t=119.317s dur=113ms, freq=370Hz, sample=66, buffer_id=05:42
    db 0,0,100,0,61,127,11,23,21,1,61,11  ; n3834 t=119.317s dur=100ms, freq=277Hz, sample=61, buffer_id=0B:3D
    db 0,0,100,0,66,127,11,24,114,1,66,11  ; n3835 t=119.317s dur=100ms, freq=370Hz, sample=66, buffer_id=0B:42
    db 0,0,100,0,58,127,12,26,233,0,58,11  ; n3836 t=119.317s dur=100ms, freq=233Hz, sample=58, buffer_id=0B:3A
    db 0,0,100,0,97,127,16,27,169,8,97,16  ; n3837 t=119.317s dur=100ms, freq=2217Hz, sample=97, buffer_id=10:61
    db 0,0,100,0,85,127,17,28,85,4,85,16  ; n3838 t=119.317s dur=100ms, freq=1109Hz, sample=85, buffer_id=10:55
    db 0,0,100,0,73,127,18,29,42,2,73,18  ; n3839 t=119.317s dur=100ms, freq=554Hz, sample=73, buffer_id=12:49
    db 0,0,159,0,54,127,19,31,156,0,54,19  ; n3840 t=119.317s dur=159ms, freq=156Hz, sample=54, buffer_id=13:36
    db 91,0,159,0,42,127,20,30,78,0,42,20  ; n3841 t=119.317s dur=159ms, freq=78Hz, sample=42, buffer_id=14:2A
    db 0,0,113,0,94,127,1,0,73,7,94,1  ; n3842 t=119.408s dur=113ms, freq=1865Hz, sample=94, buffer_id=01:5E
    db 0,0,113,0,85,127,2,1,85,4,85,2  ; n3843 t=119.408s dur=113ms, freq=1109Hz, sample=85, buffer_id=02:55
    db 0,0,113,0,78,127,3,2,228,2,78,3  ; n3844 t=119.408s dur=113ms, freq=740Hz, sample=78, buffer_id=03:4E
    db 0,0,113,0,70,127,4,9,210,1,70,4  ; n3845 t=119.408s dur=113ms, freq=466Hz, sample=70, buffer_id=04:46 [TRUNCATE prev:ch9 @118951.3ms -> 119408.1ms]
    db 0,0,113,0,66,127,5,19,114,1,66,5  ; n3846 t=119.408s dur=113ms, freq=370Hz, sample=66, buffer_id=05:42 [TRUNCATE prev:ch19 @118953.5ms -> 119408.1ms]
    db 0,0,113,0,61,127,6,20,21,1,61,5  ; n3847 t=119.408s dur=113ms, freq=277Hz, sample=61, buffer_id=05:3D [TRUNCATE prev:ch20 @118953.5ms -> 119408.1ms]
    db 0,0,100,0,97,127,16,3,169,8,97,16  ; n3848 t=119.408s dur=100ms, freq=2217Hz, sample=97, buffer_id=10:61 [TRUNCATE prev:ch3 @119135.4ms -> 119408.1ms]
    db 0,0,100,0,85,127,17,4,85,4,85,16  ; n3849 t=119.408s dur=100ms, freq=1109Hz, sample=85, buffer_id=10:55 [TRUNCATE prev:ch4 @119135.4ms -> 119408.1ms]
    db 91,0,100,0,73,127,18,5,42,2,73,18  ; n3850 t=119.408s dur=100ms, freq=554Hz, sample=73, buffer_id=12:49 [TRUNCATE prev:ch5 @119135.4ms -> 119408.1ms]
    db 0,0,181,0,97,127,1,15,169,8,97,1  ; n3851 t=119.499s dur=181ms, freq=2217Hz, sample=97, buffer_id=01:61
    db 0,0,181,0,94,127,2,25,73,7,94,2  ; n3852 t=119.499s dur=181ms, freq=1865Hz, sample=94, buffer_id=02:5E
    db 0,0,181,0,85,127,3,14,85,4,85,3  ; n3853 t=119.499s dur=181ms, freq=1109Hz, sample=85, buffer_id=03:55 [TRUNCATE prev:ch14 @119317.2ms -> 119499.0ms]
    db 0,0,181,0,78,127,4,13,228,2,78,4  ; n3854 t=119.499s dur=181ms, freq=740Hz, sample=78, buffer_id=04:4E [TRUNCATE prev:ch13 @119317.2ms -> 119499.0ms]
    db 0,0,181,0,70,127,5,18,210,1,70,5  ; n3855 t=119.499s dur=181ms, freq=466Hz, sample=70, buffer_id=05:46 [TRUNCATE prev:ch18 @119317.2ms -> 119499.0ms]
    db 0,0,181,0,66,127,6,21,114,1,66,5  ; n3856 t=119.499s dur=181ms, freq=370Hz, sample=66, buffer_id=05:42 [TRUNCATE prev:ch21 @119317.2ms -> 119499.0ms]
    db 0,0,100,0,97,127,16,6,169,8,97,16  ; n3857 t=119.499s dur=100ms, freq=2217Hz, sample=97, buffer_id=10:61 [TRUNCATE prev:ch6 @119226.3ms -> 119499.0ms]
    db 0,0,100,0,85,127,17,8,85,4,85,16  ; n3858 t=119.499s dur=100ms, freq=1109Hz, sample=85, buffer_id=10:55 [TRUNCATE prev:ch8 @119226.3ms -> 119499.0ms]
    db 0,0,100,0,73,127,18,10,42,2,73,18  ; n3859 t=119.499s dur=100ms, freq=554Hz, sample=73, buffer_id=12:49 [TRUNCATE prev:ch10 @119226.3ms -> 119499.0ms]
    db 0,0,159,0,47,127,19,22,139,0,47,19  ; n3860 t=119.499s dur=159ms, freq=139Hz, sample=47, buffer_id=13:2F [TRUNCATE prev:ch22 @118953.5ms -> 119499.0ms]
    db 91,0,159,0,35,127,20,7,69,0,35,20  ; n3861 t=119.499s dur=159ms, freq=69Hz, sample=35, buffer_id=14:23 [TRUNCATE prev:ch7 @119317.2ms -> 119499.0ms]
    db 0,0,100,0,97,127,16,27,169,8,97,16  ; n3862 t=119.590s dur=100ms, freq=2217Hz, sample=97, buffer_id=10:61 [TRUNCATE prev:ch27 @119317.2ms -> 119589.9ms]
    db 0,0,100,0,85,127,17,28,85,4,85,16  ; n3863 t=119.590s dur=100ms, freq=1109Hz, sample=85, buffer_id=10:55 [TRUNCATE prev:ch28 @119317.2ms -> 119589.9ms]
    db 89,0,100,0,73,127,18,29,42,2,73,18  ; n3864 t=119.590s dur=100ms, freq=554Hz, sample=73, buffer_id=12:49 [TRUNCATE prev:ch29 @119317.2ms -> 119589.9ms]
    db 2,0,100,0,47,127,10,11,123,0,47,10  ; n3865 t=119.678s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 0,0,192,2,59,127,7,23,247,0,59,7  ; n3866 t=119.681s dur=704ms, freq=247Hz, sample=59, buffer_id=07:3B
    db 0,0,192,2,71,127,7,24,238,1,71,7  ; n3867 t=119.681s dur=704ms, freq=494Hz, sample=71, buffer_id=07:47
    db 0,0,100,0,47,127,12,26,123,0,47,11  ; n3868 t=119.681s dur=100ms, freq=123Hz, sample=47, buffer_id=0B:2F
    db 0,0,84,1,35,127,13,30,62,0,35,13  ; n3869 t=119.681s dur=340ms, freq=62Hz, sample=35, buffer_id=0D:23
    db 0,0,159,0,85,127,16,31,220,3,85,16  ; n3870 t=119.681s dur=159ms, freq=988Hz, sample=85, buffer_id=10:55
    db 0,0,159,0,70,127,17,12,238,1,70,16  ; n3871 t=119.681s dur=159ms, freq=494Hz, sample=70, buffer_id=10:46 [TRUNCATE prev:ch12 @119317.2ms -> 119680.8ms]
    db 0,0,157,0,54,127,18,16,247,0,54,18  ; n3872 t=119.681s dur=157ms, freq=247Hz, sample=54, buffer_id=12:36 [TRUNCATE prev:ch16 @119317.2ms -> 119680.8ms]
    db 0,0,159,0,47,127,19,22,123,0,47,19  ; n3873 t=119.681s dur=159ms, freq=123Hz, sample=47, buffer_id=13:2F [TRUNCATE prev:ch22 @119499.0ms -> 119680.8ms]
    db 78,0,159,0,35,127,20,7,62,0,35,20  ; n3874 t=119.681s dur=159ms, freq=62Hz, sample=35, buffer_id=14:23 [TRUNCATE prev:ch7 @119499.0ms -> 119680.8ms]
    db 80,0,100,0,47,127,10,0,123,0,47,10  ; n3875 t=119.759s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 24,0,100,0,47,127,10,1,123,0,47,10  ; n3876 t=119.838s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 0,0,159,0,85,127,16,2,85,4,85,16  ; n3877 t=119.863s dur=159ms, freq=1109Hz, sample=85, buffer_id=10:55
    db 0,0,159,0,73,127,17,3,42,2,73,16  ; n3878 t=119.863s dur=159ms, freq=554Hz, sample=73, buffer_id=10:49
    db 0,0,159,0,66,127,18,4,21,1,66,18  ; n3879 t=119.863s dur=159ms, freq=277Hz, sample=66, buffer_id=12:42
    db 0,0,159,0,47,127,19,5,110,0,47,19  ; n3880 t=119.863s dur=159ms, freq=110Hz, sample=47, buffer_id=13:2F
    db 55,0,159,0,33,127,20,6,55,0,33,20  ; n3881 t=119.863s dur=159ms, freq=55Hz, sample=33, buffer_id=14:21
    db 80,0,100,0,47,127,10,8,123,0,47,10  ; n3882 t=119.917s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 47,0,100,0,47,127,10,9,123,0,47,10  ; n3883 t=119.998s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 0,0,113,0,86,127,2,7,151,4,86,2  ; n3884 t=120.044s dur=113ms, freq=1175Hz, sample=86, buffer_id=02:56
    db 0,0,113,0,90,127,2,10,200,5,90,2  ; n3885 t=120.044s dur=113ms, freq=1480Hz, sample=90, buffer_id=02:5A
    db 0,0,113,0,74,127,3,11,75,2,74,3  ; n3886 t=120.044s dur=113ms, freq=587Hz, sample=74, buffer_id=03:4A
    db 0,0,113,0,78,127,3,12,228,2,78,3  ; n3887 t=120.044s dur=113ms, freq=740Hz, sample=78, buffer_id=03:4E
    db 0,0,113,0,74,127,4,13,75,2,74,4  ; n3888 t=120.044s dur=113ms, freq=587Hz, sample=74, buffer_id=04:4A
    db 0,0,113,0,78,127,4,14,228,2,78,4  ; n3889 t=120.044s dur=113ms, freq=740Hz, sample=78, buffer_id=04:4E
    db 0,0,113,0,66,127,5,15,114,1,66,5  ; n3890 t=120.044s dur=113ms, freq=370Hz, sample=66, buffer_id=05:42
    db 0,0,113,0,62,127,6,16,38,1,62,5  ; n3891 t=120.044s dur=113ms, freq=294Hz, sample=62, buffer_id=05:3E
    db 0,0,100,0,66,127,9,17,114,1,66,9  ; n3892 t=120.044s dur=100ms, freq=370Hz, sample=66, buffer_id=09:42
    db 0,0,100,0,78,127,9,18,228,2,78,9  ; n3893 t=120.044s dur=100ms, freq=740Hz, sample=78, buffer_id=09:4E
    db 0,0,100,0,62,127,11,19,38,1,62,11  ; n3894 t=120.044s dur=100ms, freq=294Hz, sample=62, buffer_id=0B:3E
    db 0,0,100,0,66,127,11,20,114,1,66,11  ; n3895 t=120.044s dur=100ms, freq=370Hz, sample=66, buffer_id=0B:42
    db 0,0,100,0,54,127,12,21,185,0,54,11  ; n3896 t=120.044s dur=100ms, freq=185Hz, sample=54, buffer_id=0B:36
    db 0,0,159,0,86,127,16,22,151,4,86,16  ; n3897 t=120.044s dur=159ms, freq=1175Hz, sample=86, buffer_id=10:56
    db 0,0,159,0,74,127,17,25,75,2,74,16  ; n3898 t=120.044s dur=159ms, freq=587Hz, sample=74, buffer_id=10:4A
    db 0,0,159,0,66,127,18,26,38,1,66,18  ; n3899 t=120.044s dur=159ms, freq=294Hz, sample=66, buffer_id=12:42
    db 0,0,159,0,42,127,19,27,98,0,42,19  ; n3900 t=120.044s dur=159ms, freq=98Hz, sample=42, buffer_id=13:2A
    db 33,0,159,0,30,127,20,28,49,0,30,20  ; n3901 t=120.044s dur=159ms, freq=49Hz, sample=30, buffer_id=14:1E
    db 58,0,100,0,47,127,10,29,123,0,47,10  ; n3902 t=120.077s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 0,0,113,0,85,127,2,0,85,4,85,2  ; n3903 t=120.135s dur=113ms, freq=1109Hz, sample=85, buffer_id=02:55
    db 0,0,113,0,90,127,2,31,117,5,90,2  ; n3904 t=120.135s dur=113ms, freq=1397Hz, sample=90, buffer_id=02:5A
    db 0,0,113,0,73,127,3,23,42,2,73,3  ; n3905 t=120.135s dur=113ms, freq=554Hz, sample=73, buffer_id=03:49 [TRUNCATE prev:ch23 @119680.8ms -> 120135.4ms]
    db 0,0,113,0,78,127,3,24,186,2,78,3  ; n3906 t=120.135s dur=113ms, freq=698Hz, sample=78, buffer_id=03:4E [TRUNCATE prev:ch24 @119680.8ms -> 120135.4ms]
    db 0,0,113,0,73,127,4,30,42,2,73,4  ; n3907 t=120.135s dur=113ms, freq=554Hz, sample=73, buffer_id=04:49 [TRUNCATE prev:ch30 @119680.8ms -> 120135.4ms]
    db 0,0,113,0,78,127,4,1,186,2,78,4  ; n3908 t=120.135s dur=113ms, freq=698Hz, sample=78, buffer_id=04:4E [TRUNCATE prev:ch1 @119838.4ms -> 120135.4ms]
    db 0,0,113,0,66,127,5,2,93,1,66,5  ; n3909 t=120.135s dur=113ms, freq=349Hz, sample=66, buffer_id=05:42 [TRUNCATE prev:ch2 @119862.6ms -> 120135.4ms]
    db 20,0,113,0,61,127,6,3,21,1,61,5  ; n3910 t=120.135s dur=113ms, freq=277Hz, sample=61, buffer_id=05:3D [TRUNCATE prev:ch3 @119862.6ms -> 120135.4ms]
    db 70,0,100,0,47,127,10,8,123,0,47,10  ; n3911 t=120.156s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F [TRUNCATE prev:ch8 @119917.2ms -> 120155.8ms]
    db 0,0,181,0,86,127,2,4,151,4,86,2  ; n3912 t=120.226s dur=181ms, freq=1175Hz, sample=86, buffer_id=02:56
    db 0,0,181,0,90,127,2,5,200,5,90,2  ; n3913 t=120.226s dur=181ms, freq=1480Hz, sample=90, buffer_id=02:5A
    db 0,0,181,0,74,127,3,6,75,2,74,3  ; n3914 t=120.226s dur=181ms, freq=587Hz, sample=74, buffer_id=03:4A
    db 0,0,181,0,78,127,3,12,228,2,78,3  ; n3915 t=120.226s dur=181ms, freq=740Hz, sample=78, buffer_id=03:4E [TRUNCATE prev:ch12 @120044.4ms -> 120226.3ms]
    db 0,0,181,0,74,127,4,13,75,2,74,4  ; n3916 t=120.226s dur=181ms, freq=587Hz, sample=74, buffer_id=04:4A [TRUNCATE prev:ch13 @120044.4ms -> 120226.3ms]
    db 0,0,181,0,78,127,4,14,228,2,78,4  ; n3917 t=120.226s dur=181ms, freq=740Hz, sample=78, buffer_id=04:4E [TRUNCATE prev:ch14 @120044.4ms -> 120226.3ms]
    db 0,0,181,0,66,127,5,15,114,1,66,5  ; n3918 t=120.226s dur=181ms, freq=370Hz, sample=66, buffer_id=05:42 [TRUNCATE prev:ch15 @120044.4ms -> 120226.3ms]
    db 0,0,181,0,62,127,6,16,38,1,62,5  ; n3919 t=120.226s dur=181ms, freq=294Hz, sample=62, buffer_id=05:3E [TRUNCATE prev:ch16 @120044.4ms -> 120226.3ms]
    db 0,0,150,0,87,127,16,9,39,5,87,16  ; n3920 t=120.226s dur=150ms, freq=1319Hz, sample=87, buffer_id=10:57 [TRUNCATE prev:ch9 @119997.5ms -> 120226.3ms]
    db 0,0,159,0,74,127,17,25,147,2,74,16  ; n3921 t=120.226s dur=159ms, freq=659Hz, sample=74, buffer_id=10:4A [TRUNCATE prev:ch25 @120044.4ms -> 120226.3ms]
    db 0,0,159,0,66,127,18,26,74,1,66,18  ; n3922 t=120.226s dur=159ms, freq=330Hz, sample=66, buffer_id=12:42 [TRUNCATE prev:ch26 @120044.4ms -> 120226.3ms]
    db 0,0,159,0,42,127,19,27,92,0,42,19  ; n3923 t=120.226s dur=159ms, freq=92Hz, sample=42, buffer_id=13:2A [TRUNCATE prev:ch27 @120044.4ms -> 120226.3ms]
    db 9,0,159,0,30,127,20,28,46,0,30,20  ; n3924 t=120.226s dur=159ms, freq=46Hz, sample=30, buffer_id=14:1E [TRUNCATE prev:ch28 @120044.4ms -> 120226.3ms]
    db 80,0,100,0,47,127,10,29,123,0,47,10  ; n3925 t=120.235s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F [TRUNCATE prev:ch29 @120077.0ms -> 120235.4ms]
    db 79,0,100,0,47,127,10,8,123,0,47,10  ; n3926 t=120.316s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F [TRUNCATE prev:ch8 @120155.8ms -> 120315.7ms]
    db 13,0,100,0,47,127,10,7,123,0,47,10  ; n3927 t=120.395s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 0,0,192,2,59,127,7,10,247,0,59,7  ; n3928 t=120.408s dur=704ms, freq=247Hz, sample=59, buffer_id=07:3B
    db 0,0,192,2,71,127,7,11,238,1,71,7  ; n3929 t=120.408s dur=704ms, freq=494Hz, sample=71, buffer_id=07:47
    db 0,0,100,0,47,127,12,17,123,0,47,11  ; n3930 t=120.408s dur=100ms, freq=123Hz, sample=47, buffer_id=0B:2F
    db 0,0,84,1,35,127,13,18,62,0,35,13  ; n3931 t=120.408s dur=340ms, freq=62Hz, sample=35, buffer_id=0D:23
    db 0,0,159,0,90,127,16,19,200,5,90,16  ; n3932 t=120.408s dur=159ms, freq=1480Hz, sample=90, buffer_id=10:5A
    db 0,0,159,0,78,127,17,20,228,2,78,16  ; n3933 t=120.408s dur=159ms, freq=740Hz, sample=78, buffer_id=10:4E
    db 0,0,159,0,66,127,18,21,114,1,66,18  ; n3934 t=120.408s dur=159ms, freq=370Hz, sample=66, buffer_id=12:42
    db 0,0,159,0,47,127,19,22,123,0,47,19  ; n3935 t=120.408s dur=159ms, freq=123Hz, sample=47, buffer_id=13:2F
    db 66,0,159,0,35,127,20,0,62,0,35,20  ; n3936 t=120.408s dur=159ms, freq=62Hz, sample=35, buffer_id=14:23 [TRUNCATE prev:ch0 @120135.4ms -> 120408.1ms]
    db 79,0,100,0,47,127,10,1,123,0,47,10  ; n3937 t=120.474s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 36,0,100,0,47,127,10,2,123,0,47,10  ; n3938 t=120.553s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 0,0,159,0,86,127,16,3,151,4,86,16  ; n3939 t=120.590s dur=159ms, freq=1175Hz, sample=86, buffer_id=10:56
    db 0,0,159,0,74,127,17,9,75,2,74,16  ; n3940 t=120.590s dur=159ms, freq=587Hz, sample=74, buffer_id=10:4A
    db 0,0,159,0,66,127,18,23,38,1,66,18  ; n3941 t=120.590s dur=159ms, freq=294Hz, sample=66, buffer_id=12:42
    db 0,0,159,0,47,127,19,24,110,0,47,19  ; n3942 t=120.590s dur=159ms, freq=110Hz, sample=47, buffer_id=13:2F
    db 42,0,159,0,33,127,20,25,55,0,33,20  ; n3943 t=120.590s dur=159ms, freq=55Hz, sample=33, buffer_id=14:21
    db 80,0,100,0,47,127,10,4,123,0,47,10  ; n3944 t=120.632s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 59,0,100,0,47,127,10,5,123,0,47,10  ; n3945 t=120.713s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 0,0,113,0,86,127,2,0,151,4,86,2  ; n3946 t=120.772s dur=113ms, freq=1175Hz, sample=86, buffer_id=02:56
    db 0,0,113,0,90,127,2,6,200,5,90,2  ; n3947 t=120.772s dur=113ms, freq=1480Hz, sample=90, buffer_id=02:5A
    db 0,0,113,0,74,127,3,7,75,2,74,3  ; n3948 t=120.772s dur=113ms, freq=587Hz, sample=74, buffer_id=03:4A
    db 0,0,113,0,78,127,3,8,228,2,78,3  ; n3949 t=120.772s dur=113ms, freq=740Hz, sample=78, buffer_id=03:4E
    db 0,0,113,0,74,127,4,12,75,2,74,4  ; n3950 t=120.772s dur=113ms, freq=587Hz, sample=74, buffer_id=04:4A
    db 0,0,113,0,78,127,4,13,228,2,78,4  ; n3951 t=120.772s dur=113ms, freq=740Hz, sample=78, buffer_id=04:4E
    db 0,0,113,0,66,127,5,14,114,1,66,5  ; n3952 t=120.772s dur=113ms, freq=370Hz, sample=66, buffer_id=05:42
    db 0,0,113,0,62,127,6,15,38,1,62,5  ; n3953 t=120.772s dur=113ms, freq=294Hz, sample=62, buffer_id=05:3E
    db 0,0,100,0,66,127,9,16,114,1,66,9  ; n3954 t=120.772s dur=100ms, freq=370Hz, sample=66, buffer_id=09:42
    db 0,0,100,0,78,127,9,17,228,2,78,9  ; n3955 t=120.772s dur=100ms, freq=740Hz, sample=78, buffer_id=09:4E
    db 0,0,100,0,62,127,11,19,38,1,62,11  ; n3956 t=120.772s dur=100ms, freq=294Hz, sample=62, buffer_id=0B:3E
    db 0,0,100,0,66,127,11,20,114,1,66,11  ; n3957 t=120.772s dur=100ms, freq=370Hz, sample=66, buffer_id=0B:42
    db 0,0,100,0,54,127,12,21,185,0,54,11  ; n3958 t=120.772s dur=100ms, freq=185Hz, sample=54, buffer_id=0B:36
    db 0,0,100,0,90,127,16,22,200,5,90,16  ; n3959 t=120.772s dur=100ms, freq=1480Hz, sample=90, buffer_id=10:5A
    db 0,0,100,0,78,127,17,26,228,2,78,16  ; n3960 t=120.772s dur=100ms, freq=740Hz, sample=78, buffer_id=10:4E
    db 0,0,100,0,66,127,18,27,114,1,66,18  ; n3961 t=120.772s dur=100ms, freq=370Hz, sample=66, buffer_id=12:42
    db 0,0,159,0,42,127,19,28,98,0,42,19  ; n3962 t=120.772s dur=159ms, freq=98Hz, sample=42, buffer_id=13:2A
    db 20,0,159,0,30,127,20,29,49,0,30,20  ; n3963 t=120.772s dur=159ms, freq=49Hz, sample=30, buffer_id=14:1E
    db 70,0,100,0,47,127,10,30,123,0,47,10  ; n3964 t=120.792s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 0,0,113,0,85,127,2,1,85,4,85,2  ; n3965 t=120.863s dur=113ms, freq=1109Hz, sample=85, buffer_id=02:55
    db 0,0,113,0,90,127,2,2,117,5,90,2  ; n3966 t=120.863s dur=113ms, freq=1397Hz, sample=90, buffer_id=02:5A
    db 0,0,113,0,73,127,3,31,42,2,73,3  ; n3967 t=120.863s dur=113ms, freq=554Hz, sample=73, buffer_id=03:49
    db 0,0,113,0,78,127,3,10,186,2,78,3  ; n3968 t=120.863s dur=113ms, freq=698Hz, sample=78, buffer_id=03:4E [TRUNCATE prev:ch10 @120408.1ms -> 120862.6ms]
    db 0,0,113,0,73,127,4,11,42,2,73,4  ; n3969 t=120.863s dur=113ms, freq=554Hz, sample=73, buffer_id=04:49 [TRUNCATE prev:ch11 @120408.1ms -> 120862.6ms]
    db 0,0,113,0,78,127,4,18,186,2,78,4  ; n3970 t=120.863s dur=113ms, freq=698Hz, sample=78, buffer_id=04:4E [TRUNCATE prev:ch18 @120408.1ms -> 120862.6ms]
    db 0,0,113,0,66,127,5,3,93,1,66,5  ; n3971 t=120.863s dur=113ms, freq=349Hz, sample=66, buffer_id=05:42 [TRUNCATE prev:ch3 @120589.9ms -> 120862.6ms]
    db 0,0,113,0,61,127,6,9,21,1,61,5  ; n3972 t=120.863s dur=113ms, freq=277Hz, sample=61, buffer_id=05:3D [TRUNCATE prev:ch9 @120589.9ms -> 120862.6ms]
    db 0,0,100,0,90,127,16,23,200,5,90,16  ; n3973 t=120.863s dur=100ms, freq=1480Hz, sample=90, buffer_id=10:5A [TRUNCATE prev:ch23 @120589.9ms -> 120862.6ms]
    db 0,0,100,0,78,127,17,24,228,2,78,16  ; n3974 t=120.863s dur=100ms, freq=740Hz, sample=78, buffer_id=10:4E [TRUNCATE prev:ch24 @120589.9ms -> 120862.6ms]
    db 9,0,100,0,66,127,18,25,114,1,66,18  ; n3975 t=120.863s dur=100ms, freq=370Hz, sample=66, buffer_id=12:42 [TRUNCATE prev:ch25 @120589.9ms -> 120862.6ms]
    db 80,0,100,0,47,127,10,4,123,0,47,10  ; n3976 t=120.872s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F [TRUNCATE prev:ch4 @120632.3ms -> 120871.7ms]
    db 2,0,100,0,47,127,10,5,123,0,47,10  ; n3977 t=120.952s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F [TRUNCATE prev:ch5 @120712.6ms -> 120952.0ms]
    db 0,0,181,0,86,127,2,0,151,4,86,2  ; n3978 t=120.954s dur=181ms, freq=1175Hz, sample=86, buffer_id=02:56 [TRUNCATE prev:ch0 @120771.7ms -> 120953.5ms]
    db 0,0,181,0,90,127,2,6,200,5,90,2  ; n3979 t=120.954s dur=181ms, freq=1480Hz, sample=90, buffer_id=02:5A [TRUNCATE prev:ch6 @120771.7ms -> 120953.5ms]
    db 0,0,181,0,74,127,3,7,75,2,74,3  ; n3980 t=120.954s dur=181ms, freq=587Hz, sample=74, buffer_id=03:4A [TRUNCATE prev:ch7 @120771.7ms -> 120953.5ms]
    db 0,0,181,0,78,127,3,8,228,2,78,3  ; n3981 t=120.954s dur=181ms, freq=740Hz, sample=78, buffer_id=03:4E [TRUNCATE prev:ch8 @120771.7ms -> 120953.5ms]
    db 0,0,181,0,74,127,4,12,75,2,74,4  ; n3982 t=120.954s dur=181ms, freq=587Hz, sample=74, buffer_id=04:4A [TRUNCATE prev:ch12 @120771.7ms -> 120953.5ms]
    db 0,0,181,0,78,127,4,13,228,2,78,4  ; n3983 t=120.954s dur=181ms, freq=740Hz, sample=78, buffer_id=04:4E [TRUNCATE prev:ch13 @120771.7ms -> 120953.5ms]
    db 0,0,181,0,66,127,5,14,114,1,66,5  ; n3984 t=120.954s dur=181ms, freq=370Hz, sample=66, buffer_id=05:42 [TRUNCATE prev:ch14 @120771.7ms -> 120953.5ms]
    db 0,0,181,0,62,127,6,15,38,1,62,5  ; n3985 t=120.954s dur=181ms, freq=294Hz, sample=62, buffer_id=05:3E [TRUNCATE prev:ch15 @120771.7ms -> 120953.5ms]
    db 0,0,100,0,90,127,16,22,200,5,90,16  ; n3986 t=120.954s dur=100ms, freq=1480Hz, sample=90, buffer_id=10:5A [TRUNCATE prev:ch22 @120771.7ms -> 120953.5ms]
    db 0,0,100,0,78,127,17,26,228,2,78,16  ; n3987 t=120.954s dur=100ms, freq=740Hz, sample=78, buffer_id=10:4E [TRUNCATE prev:ch26 @120771.7ms -> 120953.5ms]
    db 0,0,100,0,66,127,18,27,114,1,66,18  ; n3988 t=120.954s dur=100ms, freq=370Hz, sample=66, buffer_id=12:42 [TRUNCATE prev:ch27 @120771.7ms -> 120953.5ms]
    db 0,0,159,0,42,127,19,28,92,0,42,19  ; n3989 t=120.954s dur=159ms, freq=92Hz, sample=42, buffer_id=13:2A [TRUNCATE prev:ch28 @120771.7ms -> 120953.5ms]
    db 78,0,159,0,30,127,20,29,46,0,30,20  ; n3990 t=120.954s dur=159ms, freq=46Hz, sample=30, buffer_id=14:1E [TRUNCATE prev:ch29 @120771.7ms -> 120953.5ms]
    db 13,0,100,0,47,127,10,30,123,0,47,10  ; n3991 t=121.032s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F [TRUNCATE prev:ch30 @120792.2ms -> 121031.6ms]
    db 0,0,100,0,90,127,16,23,200,5,90,16  ; n3992 t=121.044s dur=100ms, freq=1480Hz, sample=90, buffer_id=10:5A [TRUNCATE prev:ch23 @120862.6ms -> 121044.4ms]
    db 0,0,100,0,78,127,17,24,228,2,78,16  ; n3993 t=121.044s dur=100ms, freq=740Hz, sample=78, buffer_id=10:4E [TRUNCATE prev:ch24 @120862.6ms -> 121044.4ms]
    db 65,0,100,0,66,127,18,25,114,1,66,18  ; n3994 t=121.044s dur=100ms, freq=370Hz, sample=66, buffer_id=12:42 [TRUNCATE prev:ch25 @120862.6ms -> 121044.4ms]
    db 26,0,100,0,47,127,10,16,123,0,47,10  ; n3995 t=121.110s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 0,0,192,2,59,127,7,17,247,0,59,7  ; n3996 t=121.135s dur=704ms, freq=247Hz, sample=59, buffer_id=07:3B
    db 0,0,192,2,71,127,7,19,238,1,71,7  ; n3997 t=121.135s dur=704ms, freq=494Hz, sample=71, buffer_id=07:47
    db 0,0,100,0,47,127,12,20,123,0,47,11  ; n3998 t=121.135s dur=100ms, freq=123Hz, sample=47, buffer_id=0B:2F
    db 0,0,84,1,35,127,13,21,62,0,35,13  ; n3999 t=121.135s dur=340ms, freq=62Hz, sample=35, buffer_id=0D:23
    db 0,0,159,0,90,127,16,22,117,5,90,16  ; n4000 t=121.135s dur=159ms, freq=1397Hz, sample=90, buffer_id=10:5A [TRUNCATE prev:ch22 @120953.5ms -> 121135.4ms]
    db 0,0,159,0,78,127,17,26,186,2,78,16  ; n4001 t=121.135s dur=159ms, freq=698Hz, sample=78, buffer_id=10:4E [TRUNCATE prev:ch26 @120953.5ms -> 121135.4ms]
    db 0,0,159,0,66,127,18,27,93,1,66,18  ; n4002 t=121.135s dur=159ms, freq=349Hz, sample=66, buffer_id=12:42 [TRUNCATE prev:ch27 @120953.5ms -> 121135.4ms]
    db 0,0,159,0,47,127,19,1,123,0,47,19  ; n4003 t=121.135s dur=159ms, freq=123Hz, sample=47, buffer_id=13:2F [TRUNCATE prev:ch1 @120862.6ms -> 121135.4ms]
    db 54,0,159,0,35,127,20,2,62,0,35,20  ; n4004 t=121.135s dur=159ms, freq=62Hz, sample=35, buffer_id=14:23 [TRUNCATE prev:ch2 @120862.6ms -> 121135.4ms]
    db 80,0,100,0,47,127,10,3,123,0,47,10  ; n4005 t=121.190s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 48,0,100,0,47,127,10,9,123,0,47,10  ; n4006 t=121.269s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 0,0,159,0,85,127,16,4,85,4,85,16  ; n4007 t=121.317s dur=159ms, freq=1109Hz, sample=85, buffer_id=10:55
    db 0,0,159,0,73,127,17,5,42,2,73,16  ; n4008 t=121.317s dur=159ms, freq=554Hz, sample=73, buffer_id=10:49
    db 0,0,159,0,66,127,18,10,21,1,66,18  ; n4009 t=121.317s dur=159ms, freq=277Hz, sample=66, buffer_id=12:42
    db 0,0,159,0,47,127,19,11,110,0,47,19  ; n4010 t=121.317s dur=159ms, freq=110Hz, sample=47, buffer_id=13:2F
    db 33,0,159,0,33,127,20,18,55,0,33,20  ; n4011 t=121.317s dur=159ms, freq=55Hz, sample=33, buffer_id=14:21
    db 79,0,100,0,47,127,10,0,123,0,47,10  ; n4012 t=121.350s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 70,0,100,0,47,127,10,6,123,0,47,10  ; n4013 t=121.428s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 0,0,113,0,85,127,2,1,85,4,85,2  ; n4014 t=121.499s dur=113ms, freq=1109Hz, sample=85, buffer_id=02:55
    db 0,0,113,0,90,127,2,2,117,5,90,2  ; n4015 t=121.499s dur=113ms, freq=1397Hz, sample=90, buffer_id=02:5A
    db 0,0,113,0,73,127,3,3,42,2,73,3  ; n4016 t=121.499s dur=113ms, freq=554Hz, sample=73, buffer_id=03:49
    db 0,0,113,0,78,127,3,7,186,2,78,3  ; n4017 t=121.499s dur=113ms, freq=698Hz, sample=78, buffer_id=03:4E
    db 0,0,113,0,73,127,4,8,42,2,73,4  ; n4018 t=121.499s dur=113ms, freq=554Hz, sample=73, buffer_id=04:49
    db 0,0,113,0,78,127,4,12,186,2,78,4  ; n4019 t=121.499s dur=113ms, freq=698Hz, sample=78, buffer_id=04:4E
    db 0,0,113,0,66,127,5,13,93,1,66,5  ; n4020 t=121.499s dur=113ms, freq=349Hz, sample=66, buffer_id=05:42
    db 0,0,113,0,61,127,6,14,21,1,61,5  ; n4021 t=121.499s dur=113ms, freq=277Hz, sample=61, buffer_id=05:3D
    db 0,0,100,0,66,127,9,15,114,1,66,9  ; n4022 t=121.499s dur=100ms, freq=370Hz, sample=66, buffer_id=09:42
    db 0,0,100,0,78,127,9,16,228,2,78,9  ; n4023 t=121.499s dur=100ms, freq=740Hz, sample=78, buffer_id=09:4E
    db 0,0,100,0,61,127,11,20,21,1,61,11  ; n4024 t=121.499s dur=100ms, freq=277Hz, sample=61, buffer_id=0B:3D
    db 0,0,100,0,66,127,11,22,93,1,66,11  ; n4025 t=121.499s dur=100ms, freq=349Hz, sample=66, buffer_id=0B:42
    db 0,0,100,0,54,127,12,23,185,0,54,11  ; n4026 t=121.499s dur=100ms, freq=185Hz, sample=54, buffer_id=0B:36
    db 0,0,100,0,90,127,16,24,117,5,90,16  ; n4027 t=121.499s dur=100ms, freq=1397Hz, sample=90, buffer_id=10:5A
    db 0,0,100,0,78,127,17,25,186,2,78,16  ; n4028 t=121.499s dur=100ms, freq=698Hz, sample=78, buffer_id=10:4E
    db 0,0,100,0,66,127,18,26,93,1,66,18  ; n4029 t=121.499s dur=100ms, freq=349Hz, sample=66, buffer_id=12:42
    db 0,0,159,0,42,127,19,27,98,0,42,19  ; n4030 t=121.499s dur=159ms, freq=98Hz, sample=42, buffer_id=13:2A
    db 9,0,159,0,30,127,20,28,49,0,30,20  ; n4031 t=121.499s dur=159ms, freq=49Hz, sample=30, buffer_id=14:1E
    db 79,0,100,0,47,127,10,29,123,0,47,10  ; n4032 t=121.508s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 2,0,100,0,47,127,10,31,123,0,47,10  ; n4033 t=121.588s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 0,0,113,0,85,127,2,9,23,4,85,2  ; n4034 t=121.590s dur=113ms, freq=1047Hz, sample=85, buffer_id=02:55
    db 0,0,113,0,86,127,2,30,39,5,86,2  ; n4035 t=121.590s dur=113ms, freq=1319Hz, sample=86, buffer_id=02:56
    db 0,0,113,0,71,127,3,17,11,2,71,3  ; n4036 t=121.590s dur=113ms, freq=523Hz, sample=71, buffer_id=03:47 [TRUNCATE prev:ch17 @121135.4ms -> 121589.9ms]
    db 0,0,113,0,74,127,3,19,147,2,74,3  ; n4037 t=121.590s dur=113ms, freq=659Hz, sample=74, buffer_id=03:4A [TRUNCATE prev:ch19 @121135.4ms -> 121589.9ms]
    db 0,0,113,0,73,127,4,21,11,2,73,4  ; n4038 t=121.590s dur=113ms, freq=523Hz, sample=73, buffer_id=04:49 [TRUNCATE prev:ch21 @121135.4ms -> 121589.9ms]
    db 0,0,113,0,74,127,4,4,147,2,74,4  ; n4039 t=121.590s dur=113ms, freq=659Hz, sample=74, buffer_id=04:4A [TRUNCATE prev:ch4 @121317.2ms -> 121589.9ms]
    db 0,0,113,0,62,127,5,5,74,1,62,5  ; n4040 t=121.590s dur=113ms, freq=330Hz, sample=62, buffer_id=05:3E [TRUNCATE prev:ch5 @121317.2ms -> 121589.9ms]
    db 0,0,113,0,61,127,6,10,6,1,61,5  ; n4041 t=121.590s dur=113ms, freq=262Hz, sample=61, buffer_id=05:3D [TRUNCATE prev:ch10 @121317.2ms -> 121589.9ms]
    db 0,0,100,0,90,127,16,11,117,5,90,16  ; n4042 t=121.590s dur=100ms, freq=1397Hz, sample=90, buffer_id=10:5A [TRUNCATE prev:ch11 @121317.2ms -> 121589.9ms]
    db 0,0,100,0,78,127,17,18,186,2,78,16  ; n4043 t=121.590s dur=100ms, freq=698Hz, sample=78, buffer_id=10:4E [TRUNCATE prev:ch18 @121317.2ms -> 121589.9ms]
    db 77,0,100,0,66,127,18,0,93,1,66,18  ; n4044 t=121.590s dur=100ms, freq=349Hz, sample=66, buffer_id=12:42 [TRUNCATE prev:ch0 @121349.8ms -> 121589.9ms]
    db 14,0,100,0,47,127,10,6,123,0,47,10  ; n4045 t=121.667s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F [TRUNCATE prev:ch6 @121428.5ms -> 121667.2ms]
    db 0,0,181,0,85,127,2,1,85,4,85,2  ; n4046 t=121.681s dur=181ms, freq=1109Hz, sample=85, buffer_id=02:55 [TRUNCATE prev:ch1 @121499.0ms -> 121680.8ms]
    db 0,0,181,0,90,127,2,2,117,5,90,2  ; n4047 t=121.681s dur=181ms, freq=1397Hz, sample=90, buffer_id=02:5A [TRUNCATE prev:ch2 @121499.0ms -> 121680.8ms]
    db 0,0,181,0,73,127,3,3,42,2,73,3  ; n4048 t=121.681s dur=181ms, freq=554Hz, sample=73, buffer_id=03:49 [TRUNCATE prev:ch3 @121499.0ms -> 121680.8ms]
    db 0,0,181,0,78,127,3,7,186,2,78,3  ; n4049 t=121.681s dur=181ms, freq=698Hz, sample=78, buffer_id=03:4E [TRUNCATE prev:ch7 @121499.0ms -> 121680.8ms]
    db 0,0,181,0,73,127,4,8,42,2,73,4  ; n4050 t=121.681s dur=181ms, freq=554Hz, sample=73, buffer_id=04:49 [TRUNCATE prev:ch8 @121499.0ms -> 121680.8ms]
    db 0,0,181,0,78,127,4,12,186,2,78,4  ; n4051 t=121.681s dur=181ms, freq=698Hz, sample=78, buffer_id=04:4E [TRUNCATE prev:ch12 @121499.0ms -> 121680.8ms]
    db 0,0,181,0,66,127,5,13,93,1,66,5  ; n4052 t=121.681s dur=181ms, freq=349Hz, sample=66, buffer_id=05:42 [TRUNCATE prev:ch13 @121499.0ms -> 121680.8ms]
    db 0,0,181,0,61,127,6,14,21,1,61,5  ; n4053 t=121.681s dur=181ms, freq=277Hz, sample=61, buffer_id=05:3D [TRUNCATE prev:ch14 @121499.0ms -> 121680.8ms]
    db 0,0,100,0,90,127,16,24,117,5,90,16  ; n4054 t=121.681s dur=100ms, freq=1397Hz, sample=90, buffer_id=10:5A [TRUNCATE prev:ch24 @121499.0ms -> 121680.8ms]
    db 0,0,100,0,78,127,17,25,186,2,78,16  ; n4055 t=121.681s dur=100ms, freq=698Hz, sample=78, buffer_id=10:4E [TRUNCATE prev:ch25 @121499.0ms -> 121680.8ms]
    db 0,0,100,0,66,127,18,26,93,1,66,18  ; n4056 t=121.681s dur=100ms, freq=349Hz, sample=66, buffer_id=12:42 [TRUNCATE prev:ch26 @121499.0ms -> 121680.8ms]
    db 0,0,159,0,42,127,19,27,92,0,42,19  ; n4057 t=121.681s dur=159ms, freq=92Hz, sample=42, buffer_id=13:2A [TRUNCATE prev:ch27 @121499.0ms -> 121680.8ms]
    db 66,0,159,0,30,127,20,28,46,0,30,20  ; n4058 t=121.681s dur=159ms, freq=46Hz, sample=30, buffer_id=14:1E [TRUNCATE prev:ch28 @121499.0ms -> 121680.8ms]
    db 25,0,100,0,47,127,10,29,123,0,47,10  ; n4059 t=121.747s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F [TRUNCATE prev:ch29 @121508.1ms -> 121746.7ms]
    db 0,0,100,0,90,127,16,11,117,5,90,16  ; n4060 t=121.772s dur=100ms, freq=1397Hz, sample=90, buffer_id=10:5A [TRUNCATE prev:ch11 @121589.9ms -> 121771.7ms]
    db 0,0,100,0,78,127,17,18,186,2,78,16  ; n4061 t=121.772s dur=100ms, freq=698Hz, sample=78, buffer_id=10:4E [TRUNCATE prev:ch18 @121589.9ms -> 121771.7ms]
    db 55,0,100,0,66,127,18,0,93,1,66,18  ; n4062 t=121.772s dur=100ms, freq=349Hz, sample=66, buffer_id=12:42 [TRUNCATE prev:ch0 @121589.9ms -> 121771.7ms]
    db 36,0,100,0,47,127,10,15,123,0,47,10  ; n4063 t=121.826s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 0,0,192,2,59,127,7,16,247,0,59,7  ; n4064 t=121.863s dur=704ms, freq=247Hz, sample=59, buffer_id=07:3B
    db 0,0,192,2,71,127,7,20,238,1,71,7  ; n4065 t=121.863s dur=704ms, freq=494Hz, sample=71, buffer_id=07:47
    db 0,0,100,0,47,127,12,22,123,0,47,11  ; n4066 t=121.863s dur=100ms, freq=123Hz, sample=47, buffer_id=0B:2F
    db 0,0,84,1,35,127,13,23,62,0,35,13  ; n4067 t=121.863s dur=340ms, freq=62Hz, sample=35, buffer_id=0D:23
    db 0,0,150,0,87,127,16,31,39,5,87,16  ; n4068 t=121.863s dur=150ms, freq=1319Hz, sample=87, buffer_id=10:57 [TRUNCATE prev:ch31 @121587.6ms -> 121862.6ms]
    db 0,0,159,0,74,127,17,4,147,2,74,16  ; n4069 t=121.863s dur=159ms, freq=659Hz, sample=74, buffer_id=10:4A [TRUNCATE prev:ch4 @121589.9ms -> 121862.6ms]
    db 0,0,159,0,66,127,18,26,74,1,66,18  ; n4070 t=121.863s dur=159ms, freq=330Hz, sample=66, buffer_id=12:42 [TRUNCATE prev:ch26 @121680.8ms -> 121862.6ms]
    db 0,0,159,0,47,127,19,5,123,0,47,19  ; n4071 t=121.863s dur=159ms, freq=123Hz, sample=47, buffer_id=13:2F [TRUNCATE prev:ch5 @121589.9ms -> 121862.6ms]
    db 44,0,159,0,35,127,20,9,62,0,35,20  ; n4072 t=121.863s dur=159ms, freq=62Hz, sample=35, buffer_id=14:23 [TRUNCATE prev:ch9 @121589.9ms -> 121862.6ms]
    db 79,0,100,0,47,127,10,10,123,0,47,10  ; n4073 t=121.907s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 59,0,100,0,47,127,10,17,123,0,47,10  ; n4074 t=121.985s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 0,0,159,0,85,127,16,6,23,4,85,16  ; n4075 t=122.044s dur=159ms, freq=1047Hz, sample=85, buffer_id=10:55
    db 0,0,159,0,73,127,17,19,11,2,73,16  ; n4076 t=122.044s dur=159ms, freq=523Hz, sample=73, buffer_id=10:49
    db 0,0,148,0,54,127,18,21,6,1,54,18  ; n4077 t=122.044s dur=148ms, freq=262Hz, sample=54, buffer_id=12:36
    db 0,0,159,0,47,127,19,24,110,0,47,19  ; n4078 t=122.044s dur=159ms, freq=110Hz, sample=47, buffer_id=13:2F
    db 21,0,159,0,33,127,20,25,55,0,33,20  ; n4079 t=122.044s dur=159ms, freq=55Hz, sample=33, buffer_id=14:21
    db 79,0,100,0,47,127,10,1,123,0,47,10  ; n4080 t=122.066s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 80,0,100,0,47,127,10,0,123,0,47,10  ; n4081 t=122.144s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 1,0,100,0,47,127,10,2,123,0,47,10  ; n4082 t=122.225s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 0,0,113,0,85,127,2,3,23,4,85,2  ; n4083 t=122.226s dur=113ms, freq=1047Hz, sample=85, buffer_id=02:55
    db 0,0,113,0,86,127,2,4,39,5,86,2  ; n4084 t=122.226s dur=113ms, freq=1319Hz, sample=86, buffer_id=02:56
    db 0,0,113,0,71,127,3,5,11,2,71,3  ; n4085 t=122.226s dur=113ms, freq=523Hz, sample=71, buffer_id=03:47
    db 0,0,113,0,74,127,3,7,147,2,74,3  ; n4086 t=122.226s dur=113ms, freq=659Hz, sample=74, buffer_id=03:4A
    db 0,0,113,0,73,127,4,9,11,2,73,4  ; n4087 t=122.226s dur=113ms, freq=523Hz, sample=73, buffer_id=04:49
    db 0,0,113,0,74,127,4,8,147,2,74,4  ; n4088 t=122.226s dur=113ms, freq=659Hz, sample=74, buffer_id=04:4A
    db 0,0,113,0,62,127,5,10,74,1,62,5  ; n4089 t=122.226s dur=113ms, freq=330Hz, sample=62, buffer_id=05:3E
    db 0,0,113,0,61,127,6,11,6,1,61,5  ; n4090 t=122.226s dur=113ms, freq=262Hz, sample=61, buffer_id=05:3D
    db 0,0,100,0,66,127,9,12,114,1,66,9  ; n4091 t=122.226s dur=100ms, freq=370Hz, sample=66, buffer_id=09:42
    db 0,0,100,0,78,127,9,13,228,2,78,9  ; n4092 t=122.226s dur=100ms, freq=740Hz, sample=78, buffer_id=09:4E
    db 0,0,100,0,59,127,11,14,6,1,59,11  ; n4093 t=122.226s dur=100ms, freq=262Hz, sample=59, buffer_id=0B:3B
    db 0,0,100,0,62,127,11,15,74,1,62,11  ; n4094 t=122.226s dur=100ms, freq=330Hz, sample=62, buffer_id=0B:3E
    db 0,0,100,0,54,127,12,18,185,0,54,11  ; n4095 t=122.226s dur=100ms, freq=185Hz, sample=54, buffer_id=0B:36
    db 0,0,100,0,87,127,16,22,39,5,87,16  ; n4096 t=122.226s dur=100ms, freq=1319Hz, sample=87, buffer_id=10:57
    db 0,0,100,0,74,127,17,26,147,2,74,16  ; n4097 t=122.226s dur=100ms, freq=659Hz, sample=74, buffer_id=10:4A
    db 0,0,100,0,66,127,18,27,74,1,66,18  ; n4098 t=122.226s dur=100ms, freq=330Hz, sample=66, buffer_id=12:42
    db 0,0,159,0,42,127,19,28,98,0,42,19  ; n4099 t=122.226s dur=159ms, freq=98Hz, sample=42, buffer_id=13:2A
    db 78,0,159,0,30,127,20,29,49,0,30,20  ; n4100 t=122.226s dur=159ms, freq=49Hz, sample=30, buffer_id=14:1E
    db 13,0,100,0,47,127,10,30,123,0,47,10  ; n4101 t=122.304s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 0,0,113,0,85,127,2,17,220,3,85,2  ; n4102 t=122.317s dur=113ms, freq=988Hz, sample=85, buffer_id=02:55
    db 0,0,113,0,86,127,2,31,221,4,86,2  ; n4103 t=122.317s dur=113ms, freq=1245Hz, sample=86, buffer_id=02:56
    db 0,0,113,0,71,127,3,16,238,1,71,3  ; n4104 t=122.317s dur=113ms, freq=494Hz, sample=71, buffer_id=03:47 [TRUNCATE prev:ch16 @121862.6ms -> 122317.2ms]
    db 0,0,113,0,74,127,3,20,110,2,74,3  ; n4105 t=122.317s dur=113ms, freq=622Hz, sample=74, buffer_id=03:4A [TRUNCATE prev:ch20 @121862.6ms -> 122317.2ms]
    db 0,0,113,0,70,127,4,23,238,1,70,4  ; n4106 t=122.317s dur=113ms, freq=494Hz, sample=70, buffer_id=04:46 [TRUNCATE prev:ch23 @121862.6ms -> 122317.2ms]
    db 0,0,113,0,74,127,4,6,110,2,74,4  ; n4107 t=122.317s dur=113ms, freq=622Hz, sample=74, buffer_id=04:4A [TRUNCATE prev:ch6 @122044.4ms -> 122317.2ms]
    db 0,0,113,0,62,127,5,19,55,1,62,5  ; n4108 t=122.317s dur=113ms, freq=311Hz, sample=62, buffer_id=05:3E [TRUNCATE prev:ch19 @122044.4ms -> 122317.2ms]
    db 0,0,113,0,61,127,6,21,247,0,61,5  ; n4109 t=122.317s dur=113ms, freq=247Hz, sample=61, buffer_id=05:3D [TRUNCATE prev:ch21 @122044.4ms -> 122317.2ms]
    db 0,0,100,0,87,127,16,24,39,5,87,16  ; n4110 t=122.317s dur=100ms, freq=1319Hz, sample=87, buffer_id=10:57 [TRUNCATE prev:ch24 @122044.4ms -> 122317.2ms]
    db 0,0,100,0,74,127,17,25,147,2,74,16  ; n4111 t=122.317s dur=100ms, freq=659Hz, sample=74, buffer_id=10:4A [TRUNCATE prev:ch25 @122044.4ms -> 122317.2ms]
    db 66,0,100,0,66,127,18,1,74,1,66,18  ; n4112 t=122.317s dur=100ms, freq=330Hz, sample=66, buffer_id=12:42 [TRUNCATE prev:ch1 @122065.7ms -> 122317.2ms]
    db 25,0,100,0,47,127,10,0,123,0,47,10  ; n4113 t=122.383s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F [TRUNCATE prev:ch0 @122144.4ms -> 122383.1ms]
    db 0,0,181,0,85,127,2,3,23,4,85,2  ; n4114 t=122.408s dur=181ms, freq=1047Hz, sample=85, buffer_id=02:55 [TRUNCATE prev:ch3 @122226.3ms -> 122408.1ms]
    db 0,0,162,0,86,127,2,4,39,5,86,2  ; n4115 t=122.408s dur=162ms, freq=1319Hz, sample=86, buffer_id=02:56 [TRUNCATE prev:ch4 @122226.3ms -> 122408.1ms]
    db 0,0,181,0,71,127,3,5,11,2,71,3  ; n4116 t=122.408s dur=181ms, freq=523Hz, sample=71, buffer_id=03:47 [TRUNCATE prev:ch5 @122226.3ms -> 122408.1ms]
    db 0,0,162,0,74,127,3,7,147,2,74,3  ; n4117 t=122.408s dur=162ms, freq=659Hz, sample=74, buffer_id=03:4A [TRUNCATE prev:ch7 @122226.3ms -> 122408.1ms]
    db 0,0,181,0,73,127,4,9,11,2,73,4  ; n4118 t=122.408s dur=181ms, freq=523Hz, sample=73, buffer_id=04:49 [TRUNCATE prev:ch9 @122226.3ms -> 122408.1ms]
    db 0,0,181,0,74,127,4,8,147,2,74,4  ; n4119 t=122.408s dur=181ms, freq=659Hz, sample=74, buffer_id=04:4A [TRUNCATE prev:ch8 @122226.3ms -> 122408.1ms]
    db 0,0,162,0,62,127,5,10,74,1,62,5  ; n4120 t=122.408s dur=162ms, freq=330Hz, sample=62, buffer_id=05:3E [TRUNCATE prev:ch10 @122226.3ms -> 122408.1ms]
    db 0,0,181,0,61,127,6,11,6,1,61,5  ; n4121 t=122.408s dur=181ms, freq=262Hz, sample=61, buffer_id=05:3D [TRUNCATE prev:ch11 @122226.3ms -> 122408.1ms]
    db 0,0,100,0,87,127,16,22,39,5,87,16  ; n4122 t=122.408s dur=100ms, freq=1319Hz, sample=87, buffer_id=10:57 [TRUNCATE prev:ch22 @122226.3ms -> 122408.1ms]
    db 0,0,100,0,74,127,17,26,147,2,74,16  ; n4123 t=122.408s dur=100ms, freq=659Hz, sample=74, buffer_id=10:4A [TRUNCATE prev:ch26 @122226.3ms -> 122408.1ms]
    db 0,0,100,0,66,127,18,27,74,1,66,18  ; n4124 t=122.408s dur=100ms, freq=330Hz, sample=66, buffer_id=12:42 [TRUNCATE prev:ch27 @122226.3ms -> 122408.1ms]
    db 0,0,159,0,42,127,19,28,92,0,42,19  ; n4125 t=122.408s dur=159ms, freq=92Hz, sample=42, buffer_id=13:2A [TRUNCATE prev:ch28 @122226.3ms -> 122408.1ms]
    db 54,0,159,0,30,127,20,29,46,0,30,20  ; n4126 t=122.408s dur=159ms, freq=46Hz, sample=30, buffer_id=14:1E [TRUNCATE prev:ch29 @122226.3ms -> 122408.1ms]
    db 37,0,100,0,47,127,10,2,123,0,47,10  ; n4127 t=122.462s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F [TRUNCATE prev:ch2 @122224.8ms -> 122461.9ms]
    db 0,0,100,0,87,127,16,24,39,5,87,16  ; n4128 t=122.499s dur=100ms, freq=1319Hz, sample=87, buffer_id=10:57 [TRUNCATE prev:ch24 @122317.2ms -> 122499.0ms]
    db 0,0,100,0,74,127,17,25,147,2,74,16  ; n4129 t=122.499s dur=100ms, freq=659Hz, sample=74, buffer_id=10:4A [TRUNCATE prev:ch25 @122317.2ms -> 122499.0ms]
    db 43,0,100,0,66,127,18,1,74,1,66,18  ; n4130 t=122.499s dur=100ms, freq=330Hz, sample=66, buffer_id=12:42 [TRUNCATE prev:ch1 @122317.2ms -> 122499.0ms]
    db 48,0,100,0,47,127,10,12,123,0,47,10  ; n4131 t=122.542s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 0,0,192,2,59,127,7,13,247,0,59,7  ; n4132 t=122.590s dur=704ms, freq=247Hz, sample=59, buffer_id=07:3B
    db 0,0,192,2,71,127,7,14,238,1,71,7  ; n4133 t=122.590s dur=704ms, freq=494Hz, sample=71, buffer_id=07:47
    db 0,0,100,0,47,127,12,15,123,0,47,11  ; n4134 t=122.590s dur=100ms, freq=123Hz, sample=47, buffer_id=0B:2F
    db 0,0,84,1,35,127,13,18,62,0,35,13  ; n4135 t=122.590s dur=340ms, freq=62Hz, sample=35, buffer_id=0D:23
    db 0,0,159,0,85,127,16,30,220,3,85,16  ; n4136 t=122.590s dur=159ms, freq=988Hz, sample=85, buffer_id=10:55 [TRUNCATE prev:ch30 @122304.3ms -> 122589.9ms]
    db 0,0,159,0,70,127,17,6,238,1,70,16  ; n4137 t=122.590s dur=159ms, freq=494Hz, sample=70, buffer_id=10:46 [TRUNCATE prev:ch6 @122317.2ms -> 122589.9ms]
    db 0,0,157,0,54,127,18,16,247,0,54,18  ; n4138 t=122.590s dur=157ms, freq=247Hz, sample=54, buffer_id=12:36 [TRUNCATE prev:ch16 @122317.2ms -> 122589.9ms]
    db 0,0,159,0,47,127,19,17,123,0,47,19  ; n4139 t=122.590s dur=159ms, freq=123Hz, sample=47, buffer_id=13:2F [TRUNCATE prev:ch17 @122317.2ms -> 122589.9ms]
    db 33,0,159,0,35,127,20,19,62,0,35,20  ; n4140 t=122.590s dur=159ms, freq=62Hz, sample=35, buffer_id=14:23 [TRUNCATE prev:ch19 @122317.2ms -> 122589.9ms]
    db 79,0,100,0,47,127,10,0,123,0,47,10  ; n4141 t=122.623s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F [TRUNCATE prev:ch0 @122383.1ms -> 122622.5ms]
    db 70,0,100,0,47,127,10,20,123,0,47,10  ; n4142 t=122.701s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 0,0,159,0,85,127,16,2,85,4,85,16  ; n4143 t=122.772s dur=159ms, freq=1109Hz, sample=85, buffer_id=10:55
    db 0,0,159,0,73,127,17,4,42,2,73,16  ; n4144 t=122.772s dur=159ms, freq=554Hz, sample=73, buffer_id=10:49
    db 0,0,159,0,66,127,18,7,21,1,66,18  ; n4145 t=122.772s dur=159ms, freq=277Hz, sample=66, buffer_id=12:42
    db 0,0,159,0,47,127,19,10,110,0,47,19  ; n4146 t=122.772s dur=159ms, freq=110Hz, sample=47, buffer_id=13:2F
    db 9,0,159,0,33,127,20,21,55,0,33,20  ; n4147 t=122.772s dur=159ms, freq=55Hz, sample=33, buffer_id=14:21
    db 80,0,100,0,47,127,10,22,123,0,47,10  ; n4148 t=122.781s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 79,0,100,0,47,127,10,1,123,0,47,10  ; n4149 t=122.860s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 14,0,100,0,47,127,10,3,123,0,47,10  ; n4150 t=122.940s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 0,0,113,0,85,127,2,0,220,3,85,2  ; n4151 t=122.954s dur=113ms, freq=988Hz, sample=85, buffer_id=02:55
    db 0,0,113,0,86,127,2,5,151,4,86,2  ; n4152 t=122.954s dur=113ms, freq=1175Hz, sample=86, buffer_id=02:56
    db 0,0,113,0,71,127,3,6,238,1,71,3  ; n4153 t=122.954s dur=113ms, freq=494Hz, sample=71, buffer_id=03:47
    db 0,0,113,0,74,127,3,8,75,2,74,3  ; n4154 t=122.954s dur=113ms, freq=587Hz, sample=74, buffer_id=03:4A
    db 0,0,113,0,70,127,4,9,238,1,70,4  ; n4155 t=122.954s dur=113ms, freq=494Hz, sample=70, buffer_id=04:46
    db 0,0,113,0,74,127,4,11,75,2,74,4  ; n4156 t=122.954s dur=113ms, freq=587Hz, sample=74, buffer_id=04:4A
    db 0,0,113,0,62,127,5,12,38,1,62,5  ; n4157 t=122.954s dur=113ms, freq=294Hz, sample=62, buffer_id=05:3E
    db 0,0,113,0,61,127,6,15,247,0,61,5  ; n4158 t=122.954s dur=113ms, freq=247Hz, sample=61, buffer_id=05:3D
    db 0,0,100,0,66,127,9,16,114,1,66,9  ; n4159 t=122.954s dur=100ms, freq=370Hz, sample=66, buffer_id=09:42
    db 0,0,100,0,78,127,9,17,228,2,78,9  ; n4160 t=122.954s dur=100ms, freq=740Hz, sample=78, buffer_id=09:4E
    db 0,0,100,0,59,127,11,19,247,0,59,11  ; n4161 t=122.954s dur=100ms, freq=247Hz, sample=59, buffer_id=0B:3B
    db 0,0,100,0,62,127,11,23,38,1,62,11  ; n4162 t=122.954s dur=100ms, freq=294Hz, sample=62, buffer_id=0B:3E
    db 0,0,100,0,54,127,12,24,185,0,54,11  ; n4163 t=122.954s dur=100ms, freq=185Hz, sample=54, buffer_id=0B:36
    db 0,0,159,0,86,127,16,25,151,4,86,16  ; n4164 t=122.954s dur=159ms, freq=1175Hz, sample=86, buffer_id=10:56
    db 0,0,159,0,74,127,17,27,75,2,74,16  ; n4165 t=122.954s dur=159ms, freq=587Hz, sample=74, buffer_id=10:4A
    db 0,0,159,0,66,127,18,26,38,1,66,18  ; n4166 t=122.954s dur=159ms, freq=294Hz, sample=66, buffer_id=12:42
    db 0,0,159,0,42,127,19,29,98,0,42,19  ; n4167 t=122.954s dur=159ms, freq=98Hz, sample=42, buffer_id=13:2A
    db 65,0,159,0,30,127,20,28,49,0,30,20  ; n4168 t=122.954s dur=159ms, freq=49Hz, sample=30, buffer_id=14:1E
    db 26,0,100,0,47,127,10,30,123,0,47,10  ; n4169 t=123.019s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 0,0,113,0,85,127,2,20,164,3,85,2  ; n4170 t=123.044s dur=113ms, freq=932Hz, sample=85, buffer_id=02:55
    db 0,0,113,0,85,127,2,31,85,4,85,2  ; n4171 t=123.044s dur=113ms, freq=1109Hz, sample=85, buffer_id=02:55
    db 0,0,113,0,71,127,3,13,210,1,71,3  ; n4172 t=123.044s dur=113ms, freq=466Hz, sample=71, buffer_id=03:47 [TRUNCATE prev:ch13 @122589.9ms -> 123044.4ms]
    db 0,0,113,0,73,127,3,14,42,2,73,3  ; n4173 t=123.044s dur=113ms, freq=554Hz, sample=73, buffer_id=03:49 [TRUNCATE prev:ch14 @122589.9ms -> 123044.4ms]
    db 0,0,113,0,70,127,4,18,210,1,70,4  ; n4174 t=123.044s dur=113ms, freq=466Hz, sample=70, buffer_id=04:46 [TRUNCATE prev:ch18 @122589.9ms -> 123044.4ms]
    db 0,0,113,0,73,127,4,2,42,2,73,4  ; n4175 t=123.044s dur=113ms, freq=554Hz, sample=73, buffer_id=04:49 [TRUNCATE prev:ch2 @122771.7ms -> 123044.4ms]
    db 0,0,113,0,61,127,5,4,21,1,61,5  ; n4176 t=123.044s dur=113ms, freq=277Hz, sample=61, buffer_id=05:3D [TRUNCATE prev:ch4 @122771.7ms -> 123044.4ms]
    db 55,0,113,0,61,127,6,7,233,0,61,5  ; n4177 t=123.044s dur=113ms, freq=233Hz, sample=61, buffer_id=05:3D [TRUNCATE prev:ch7 @122771.7ms -> 123044.4ms]
    db 36,0,100,0,47,127,10,22,123,0,47,10  ; n4178 t=123.100s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F [TRUNCATE prev:ch22 @122780.8ms -> 123099.7ms]
    db 0,0,181,0,85,127,2,10,220,3,85,2  ; n4179 t=123.135s dur=181ms, freq=988Hz, sample=85, buffer_id=02:55
    db 0,0,181,0,86,127,2,21,151,4,86,2  ; n4180 t=123.135s dur=181ms, freq=1175Hz, sample=86, buffer_id=02:56
    db 0,0,181,0,71,127,3,6,238,1,71,3  ; n4181 t=123.135s dur=181ms, freq=494Hz, sample=71, buffer_id=03:47 [TRUNCATE prev:ch6 @122953.5ms -> 123135.4ms]
    db 0,0,181,0,74,127,3,8,75,2,74,3  ; n4182 t=123.135s dur=181ms, freq=587Hz, sample=74, buffer_id=03:4A [TRUNCATE prev:ch8 @122953.5ms -> 123135.4ms]
    db 0,0,181,0,70,127,4,9,238,1,70,4  ; n4183 t=123.135s dur=181ms, freq=494Hz, sample=70, buffer_id=04:46 [TRUNCATE prev:ch9 @122953.5ms -> 123135.4ms]
    db 0,0,181,0,74,127,4,11,75,2,74,4  ; n4184 t=123.135s dur=181ms, freq=587Hz, sample=74, buffer_id=04:4A [TRUNCATE prev:ch11 @122953.5ms -> 123135.4ms]
    db 0,0,181,0,62,127,5,12,38,1,62,5  ; n4185 t=123.135s dur=181ms, freq=294Hz, sample=62, buffer_id=05:3E [TRUNCATE prev:ch12 @122953.5ms -> 123135.4ms]
    db 0,0,181,0,61,127,6,15,247,0,61,5  ; n4186 t=123.135s dur=181ms, freq=247Hz, sample=61, buffer_id=05:3D [TRUNCATE prev:ch15 @122953.5ms -> 123135.4ms]
    db 0,0,150,0,87,127,16,1,39,5,87,16  ; n4187 t=123.135s dur=150ms, freq=1319Hz, sample=87, buffer_id=10:57 [TRUNCATE prev:ch1 @122860.4ms -> 123135.4ms]
    db 0,0,159,0,74,127,17,27,147,2,74,16  ; n4188 t=123.135s dur=159ms, freq=659Hz, sample=74, buffer_id=10:4A [TRUNCATE prev:ch27 @122953.5ms -> 123135.4ms]
    db 0,0,159,0,66,127,18,26,74,1,66,18  ; n4189 t=123.135s dur=159ms, freq=330Hz, sample=66, buffer_id=12:42 [TRUNCATE prev:ch26 @122953.5ms -> 123135.4ms]
    db 0,0,159,0,42,127,19,29,92,0,42,19  ; n4190 t=123.135s dur=159ms, freq=92Hz, sample=42, buffer_id=13:2A [TRUNCATE prev:ch29 @122953.5ms -> 123135.4ms]
    db 44,0,159,0,30,127,20,28,46,0,30,20  ; n4191 t=123.135s dur=159ms, freq=46Hz, sample=30, buffer_id=14:1E [TRUNCATE prev:ch28 @122953.5ms -> 123135.4ms]
    db 79,0,100,0,47,127,10,3,123,0,47,10  ; n4192 t=123.179s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F [TRUNCATE prev:ch3 @122939.9ms -> 123179.3ms]
    db 58,0,100,0,47,127,10,16,123,0,47,10  ; n4193 t=123.259s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 0,0,192,2,59,127,7,0,247,0,59,7  ; n4194 t=123.317s dur=704ms, freq=247Hz, sample=59, buffer_id=07:3B
    db 0,0,192,2,71,127,7,5,238,1,71,7  ; n4195 t=123.317s dur=704ms, freq=494Hz, sample=71, buffer_id=07:47
    db 0,0,100,0,47,127,12,17,123,0,47,11  ; n4196 t=123.317s dur=100ms, freq=123Hz, sample=47, buffer_id=0B:2F
    db 0,0,84,1,35,127,13,19,62,0,35,13  ; n4197 t=123.317s dur=340ms, freq=62Hz, sample=35, buffer_id=0D:23
    db 0,0,159,0,90,127,16,23,200,5,90,16  ; n4198 t=123.317s dur=159ms, freq=1480Hz, sample=90, buffer_id=10:5A
    db 0,0,159,0,78,127,17,24,228,2,78,16  ; n4199 t=123.317s dur=159ms, freq=740Hz, sample=78, buffer_id=10:4E
    db 0,0,159,0,66,127,18,25,114,1,66,18  ; n4200 t=123.317s dur=159ms, freq=370Hz, sample=66, buffer_id=12:42
    db 0,0,159,0,47,127,19,30,123,0,47,19  ; n4201 t=123.317s dur=159ms, freq=123Hz, sample=47, buffer_id=13:2F [TRUNCATE prev:ch30 @123018.7ms -> 123317.2ms]
    db 20,0,159,0,35,127,20,2,62,0,35,20  ; n4202 t=123.317s dur=159ms, freq=62Hz, sample=35, buffer_id=14:23 [TRUNCATE prev:ch2 @123044.4ms -> 123317.2ms]
    db 79,0,100,0,47,127,10,22,123,0,47,10  ; n4203 t=123.337s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F [TRUNCATE prev:ch22 @123099.7ms -> 123336.9ms]
    db 80,0,100,0,47,127,10,4,123,0,47,10  ; n4204 t=123.416s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 2,0,100,0,47,127,10,1,123,0,47,10  ; n4205 t=123.497s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 0,0,159,0,86,127,16,3,151,4,86,16  ; n4206 t=123.499s dur=159ms, freq=1175Hz, sample=86, buffer_id=10:56
    db 0,0,159,0,74,127,17,7,75,2,74,16  ; n4207 t=123.499s dur=159ms, freq=587Hz, sample=74, buffer_id=10:4A
    db 0,0,159,0,66,127,18,13,38,1,66,18  ; n4208 t=123.499s dur=159ms, freq=294Hz, sample=66, buffer_id=12:42
    db 0,0,159,0,47,127,19,14,110,0,47,19  ; n4209 t=123.499s dur=159ms, freq=110Hz, sample=47, buffer_id=13:2F
    db 78,0,159,0,33,127,20,18,55,0,33,20  ; n4210 t=123.499s dur=159ms, freq=55Hz, sample=33, buffer_id=14:21
    db 79,0,100,0,47,127,10,6,123,0,47,10  ; n4211 t=123.577s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 25,0,100,0,47,127,10,8,123,0,47,10  ; n4212 t=123.656s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 0,0,113,0,86,127,2,2,151,4,86,2  ; n4213 t=123.681s dur=113ms, freq=1175Hz, sample=86, buffer_id=02:56
    db 0,0,113,0,90,127,2,9,200,5,90,2  ; n4214 t=123.681s dur=113ms, freq=1480Hz, sample=90, buffer_id=02:5A
    db 0,0,113,0,74,127,3,10,75,2,74,3  ; n4215 t=123.681s dur=113ms, freq=587Hz, sample=74, buffer_id=03:4A
    db 0,0,113,0,78,127,3,11,228,2,78,3  ; n4216 t=123.681s dur=113ms, freq=740Hz, sample=78, buffer_id=03:4E
    db 0,0,113,0,74,127,4,12,75,2,74,4  ; n4217 t=123.681s dur=113ms, freq=587Hz, sample=74, buffer_id=04:4A
    db 0,0,113,0,78,127,4,15,228,2,78,4  ; n4218 t=123.681s dur=113ms, freq=740Hz, sample=78, buffer_id=04:4E
    db 0,0,113,0,66,127,5,16,114,1,66,5  ; n4219 t=123.681s dur=113ms, freq=370Hz, sample=66, buffer_id=05:42
    db 0,0,113,0,62,127,6,17,38,1,62,5  ; n4220 t=123.681s dur=113ms, freq=294Hz, sample=62, buffer_id=05:3E
    db 0,0,100,0,66,127,9,20,114,1,66,9  ; n4221 t=123.681s dur=100ms, freq=370Hz, sample=66, buffer_id=09:42
    db 0,0,100,0,78,127,9,21,228,2,78,9  ; n4222 t=123.681s dur=100ms, freq=740Hz, sample=78, buffer_id=09:4E
    db 0,0,100,0,59,127,11,22,247,0,59,11  ; n4223 t=123.681s dur=100ms, freq=247Hz, sample=59, buffer_id=0B:3B
    db 0,0,100,0,62,127,11,23,38,1,62,11  ; n4224 t=123.681s dur=100ms, freq=294Hz, sample=62, buffer_id=0B:3E
    db 0,0,100,0,54,127,12,24,185,0,54,11  ; n4225 t=123.681s dur=100ms, freq=185Hz, sample=54, buffer_id=0B:36
    db 0,0,159,0,90,127,16,25,200,5,90,16  ; n4226 t=123.681s dur=159ms, freq=1480Hz, sample=90, buffer_id=10:5A
    db 0,0,159,0,78,127,17,26,228,2,78,16  ; n4227 t=123.681s dur=159ms, freq=740Hz, sample=78, buffer_id=10:4E
    db 0,0,159,0,66,127,18,27,114,1,66,18  ; n4228 t=123.681s dur=159ms, freq=370Hz, sample=66, buffer_id=12:42
    db 0,0,159,0,42,127,19,28,98,0,42,19  ; n4229 t=123.681s dur=159ms, freq=98Hz, sample=42, buffer_id=13:2A
    db 55,0,159,0,30,127,20,29,49,0,30,20  ; n4230 t=123.681s dur=159ms, freq=49Hz, sample=30, buffer_id=14:1E
    db 36,0,100,0,47,127,10,30,123,0,47,10  ; n4231 t=123.736s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 0,0,113,0,85,127,2,4,85,4,85,2  ; n4232 t=123.772s dur=113ms, freq=1109Hz, sample=85, buffer_id=02:55
    db 0,0,113,0,90,127,2,31,117,5,90,2  ; n4233 t=123.772s dur=113ms, freq=1397Hz, sample=90, buffer_id=02:5A
    db 0,0,113,0,73,127,3,0,42,2,73,3  ; n4234 t=123.772s dur=113ms, freq=554Hz, sample=73, buffer_id=03:49 [TRUNCATE prev:ch0 @123317.2ms -> 123771.7ms]
    db 0,0,113,0,78,127,3,5,186,2,78,3  ; n4235 t=123.772s dur=113ms, freq=698Hz, sample=78, buffer_id=03:4E [TRUNCATE prev:ch5 @123317.2ms -> 123771.7ms]
    db 0,0,113,0,73,127,4,19,42,2,73,4  ; n4236 t=123.772s dur=113ms, freq=554Hz, sample=73, buffer_id=04:49 [TRUNCATE prev:ch19 @123317.2ms -> 123771.7ms]
    db 0,0,113,0,78,127,4,1,186,2,78,4  ; n4237 t=123.772s dur=113ms, freq=698Hz, sample=78, buffer_id=04:4E [TRUNCATE prev:ch1 @123496.7ms -> 123771.7ms]
    db 0,0,113,0,66,127,5,3,93,1,66,5  ; n4238 t=123.772s dur=113ms, freq=349Hz, sample=66, buffer_id=05:42 [TRUNCATE prev:ch3 @123499.0ms -> 123771.7ms]
    db 43,0,113,0,61,127,6,7,21,1,61,5  ; n4239 t=123.772s dur=113ms, freq=277Hz, sample=61, buffer_id=05:3D [TRUNCATE prev:ch7 @123499.0ms -> 123771.7ms]
    db 48,0,100,0,47,127,10,6,123,0,47,10  ; n4240 t=123.815s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F [TRUNCATE prev:ch6 @123577.0ms -> 123814.9ms]
    db 0,0,181,0,86,127,2,13,151,4,86,2  ; n4241 t=123.863s dur=181ms, freq=1175Hz, sample=86, buffer_id=02:56
    db 0,0,181,0,90,127,2,14,200,5,90,2  ; n4242 t=123.863s dur=181ms, freq=1480Hz, sample=90, buffer_id=02:5A
    db 0,0,181,0,74,127,3,18,75,2,74,3  ; n4243 t=123.863s dur=181ms, freq=587Hz, sample=74, buffer_id=03:4A
    db 0,0,181,0,78,127,3,11,228,2,78,3  ; n4244 t=123.863s dur=181ms, freq=740Hz, sample=78, buffer_id=03:4E [TRUNCATE prev:ch11 @123680.8ms -> 123862.6ms]
    db 0,0,181,0,74,127,4,12,75,2,74,4  ; n4245 t=123.863s dur=181ms, freq=587Hz, sample=74, buffer_id=04:4A [TRUNCATE prev:ch12 @123680.8ms -> 123862.6ms]
    db 0,0,181,0,78,127,4,15,228,2,78,4  ; n4246 t=123.863s dur=181ms, freq=740Hz, sample=78, buffer_id=04:4E [TRUNCATE prev:ch15 @123680.8ms -> 123862.6ms]
    db 0,0,181,0,66,127,5,16,114,1,66,5  ; n4247 t=123.863s dur=181ms, freq=370Hz, sample=66, buffer_id=05:42 [TRUNCATE prev:ch16 @123680.8ms -> 123862.6ms]
    db 0,0,181,0,62,127,6,17,38,1,62,5  ; n4248 t=123.863s dur=181ms, freq=294Hz, sample=62, buffer_id=05:3E [TRUNCATE prev:ch17 @123680.8ms -> 123862.6ms]
    db 0,0,159,0,97,127,16,8,184,7,97,16  ; n4249 t=123.863s dur=159ms, freq=1976Hz, sample=97, buffer_id=10:61 [TRUNCATE prev:ch8 @123655.8ms -> 123862.6ms]
    db 0,0,159,0,85,127,17,2,220,3,85,16  ; n4250 t=123.863s dur=159ms, freq=988Hz, sample=85, buffer_id=10:55 [TRUNCATE prev:ch2 @123680.8ms -> 123862.6ms]
    db 0,0,159,0,73,127,18,9,238,1,73,18  ; n4251 t=123.863s dur=159ms, freq=494Hz, sample=73, buffer_id=12:49 [TRUNCATE prev:ch9 @123680.8ms -> 123862.6ms]
    db 0,0,159,0,42,127,19,28,92,0,42,19  ; n4252 t=123.863s dur=159ms, freq=92Hz, sample=42, buffer_id=13:2A [TRUNCATE prev:ch28 @123680.8ms -> 123862.6ms]
    db 182,0,159,0,30,127,20,29,46,0,30,20  ; n4253 t=123.863s dur=159ms, freq=46Hz, sample=30, buffer_id=14:1E [TRUNCATE prev:ch29 @123680.8ms -> 123862.6ms]
    db 0,0,120,0,62,127,7,10,38,1,62,7  ; n4254 t=124.044s dur=120ms, freq=294Hz, sample=62, buffer_id=07:3E
    db 0,0,100,0,68,127,7,20,184,1,68,7  ; n4255 t=124.044s dur=100ms, freq=440Hz, sample=68, buffer_id=07:44
    db 0,0,100,0,50,127,12,21,147,0,50,11  ; n4256 t=124.044s dur=100ms, freq=147Hz, sample=50, buffer_id=0B:32
    db 0,0,84,1,35,127,13,22,73,0,35,13  ; n4257 t=124.044s dur=340ms, freq=73Hz, sample=35, buffer_id=0D:23
    db 0,0,159,0,90,127,16,23,224,6,90,16  ; n4258 t=124.044s dur=159ms, freq=1760Hz, sample=90, buffer_id=10:5A
    db 0,0,159,0,78,127,17,24,112,3,78,16  ; n4259 t=124.044s dur=159ms, freq=880Hz, sample=78, buffer_id=10:4E
    db 0,0,159,0,66,127,18,25,184,1,66,18  ; n4260 t=124.044s dur=159ms, freq=440Hz, sample=66, buffer_id=12:42
    db 0,0,159,0,47,127,19,26,147,0,47,19  ; n4261 t=124.044s dur=159ms, freq=147Hz, sample=47, buffer_id=13:2F
    db 8,0,159,0,35,127,20,27,73,0,35,20  ; n4262 t=124.044s dur=159ms, freq=73Hz, sample=35, buffer_id=14:23
    db 79,0,100,0,42,127,10,30,92,0,42,10  ; n4263 t=124.053s dur=100ms, freq=92Hz, sample=42, buffer_id=0A:2A
    db 80,0,100,0,42,127,10,0,92,0,42,10  ; n4264 t=124.132s dur=100ms, freq=92Hz, sample=42, buffer_id=0A:2A
    db 14,0,100,0,42,127,10,1,92,0,42,10  ; n4265 t=124.213s dur=100ms, freq=92Hz, sample=42, buffer_id=0A:2A
    db 0,0,159,0,90,127,16,2,200,5,90,16  ; n4266 t=124.226s dur=159ms, freq=1480Hz, sample=90, buffer_id=10:5A
    db 0,0,159,0,78,127,17,3,228,2,78,16  ; n4267 t=124.226s dur=159ms, freq=740Hz, sample=78, buffer_id=10:4E
    db 0,0,159,0,66,127,18,4,114,1,66,18  ; n4268 t=124.226s dur=159ms, freq=370Hz, sample=66, buffer_id=12:42
    db 0,0,159,0,47,127,19,5,139,0,47,19  ; n4269 t=124.226s dur=159ms, freq=139Hz, sample=47, buffer_id=13:2F
    db 66,0,159,0,35,127,20,6,69,0,35,20  ; n4270 t=124.226s dur=159ms, freq=69Hz, sample=35, buffer_id=14:23
    db 80,0,100,0,42,127,10,7,92,0,42,10  ; n4271 t=124.292s dur=100ms, freq=92Hz, sample=42, buffer_id=0A:2A
    db 36,0,100,0,42,127,10,8,92,0,42,10  ; n4272 t=124.372s dur=100ms, freq=92Hz, sample=42, buffer_id=0A:2A
    db 0,0,113,0,90,127,2,9,200,5,90,2  ; n4273 t=124.408s dur=113ms, freq=1480Hz, sample=90, buffer_id=02:5A
    db 0,0,113,0,94,127,2,10,224,6,94,2  ; n4274 t=124.408s dur=113ms, freq=1760Hz, sample=94, buffer_id=02:5E
    db 0,0,113,0,78,127,3,12,228,2,78,3  ; n4275 t=124.408s dur=113ms, freq=740Hz, sample=78, buffer_id=03:4E
    db 0,0,113,0,78,127,3,13,112,3,78,3  ; n4276 t=124.408s dur=113ms, freq=880Hz, sample=78, buffer_id=03:4E
    db 0,0,113,0,78,127,4,11,228,2,78,4  ; n4277 t=124.408s dur=113ms, freq=740Hz, sample=78, buffer_id=04:4E
    db 0,0,113,0,81,127,4,14,112,3,81,4  ; n4278 t=124.408s dur=113ms, freq=880Hz, sample=81, buffer_id=04:51
    db 0,0,113,0,70,127,5,15,184,1,70,5  ; n4279 t=124.408s dur=113ms, freq=440Hz, sample=70, buffer_id=05:46
    db 0,0,113,0,66,127,6,17,114,1,66,5  ; n4280 t=124.408s dur=113ms, freq=370Hz, sample=66, buffer_id=05:42
    db 0,0,100,0,66,127,9,16,114,1,66,9  ; n4281 t=124.408s dur=100ms, freq=370Hz, sample=66, buffer_id=09:42
    db 0,0,100,0,78,127,9,18,228,2,78,9  ; n4282 t=124.408s dur=100ms, freq=740Hz, sample=78, buffer_id=09:4E
    db 0,0,100,0,58,127,11,19,220,0,58,11  ; n4283 t=124.408s dur=100ms, freq=220Hz, sample=58, buffer_id=0B:3A
    db 0,0,100,0,62,127,11,20,38,1,62,11  ; n4284 t=124.408s dur=100ms, freq=294Hz, sample=62, buffer_id=0B:3E
    db 0,0,100,0,54,127,12,21,185,0,54,11  ; n4285 t=124.408s dur=100ms, freq=185Hz, sample=54, buffer_id=0B:36
    db 0,0,159,0,86,127,16,23,151,4,86,16  ; n4286 t=124.408s dur=159ms, freq=1175Hz, sample=86, buffer_id=10:56
    db 0,0,159,0,74,127,17,24,75,2,74,16  ; n4287 t=124.408s dur=159ms, freq=587Hz, sample=74, buffer_id=10:4A
    db 0,0,159,0,66,127,18,26,38,1,66,18  ; n4288 t=124.408s dur=159ms, freq=294Hz, sample=66, buffer_id=12:42
    db 0,0,159,0,47,127,19,25,123,0,47,19  ; n4289 t=124.408s dur=159ms, freq=123Hz, sample=47, buffer_id=13:2F
    db 44,0,159,0,35,127,20,28,62,0,35,20  ; n4290 t=124.408s dur=159ms, freq=62Hz, sample=35, buffer_id=14:23
    db 47,0,100,0,42,127,10,27,92,0,42,10  ; n4291 t=124.452s dur=100ms, freq=92Hz, sample=42, buffer_id=0A:2A
    db 0,0,113,0,90,127,2,0,117,5,90,2  ; n4292 t=124.499s dur=113ms, freq=1397Hz, sample=90, buffer_id=02:5A
    db 0,0,113,0,90,127,2,29,125,6,90,2  ; n4293 t=124.499s dur=113ms, freq=1661Hz, sample=90, buffer_id=02:5A
    db 0,0,113,0,78,127,3,30,186,2,78,3  ; n4294 t=124.499s dur=113ms, freq=698Hz, sample=78, buffer_id=03:4E
    db 0,0,113,0,78,127,3,31,63,3,78,3  ; n4295 t=124.499s dur=113ms, freq=831Hz, sample=78, buffer_id=03:4E
    db 0,0,113,0,78,127,4,22,186,2,78,4  ; n4296 t=124.499s dur=113ms, freq=698Hz, sample=78, buffer_id=04:4E [TRUNCATE prev:ch22 @124044.4ms -> 124499.0ms]
    db 0,0,113,0,81,127,4,1,63,3,81,4  ; n4297 t=124.499s dur=113ms, freq=831Hz, sample=81, buffer_id=04:51 [TRUNCATE prev:ch1 @124212.6ms -> 124499.0ms]
    db 0,0,113,0,66,127,5,2,159,1,66,5  ; n4298 t=124.499s dur=113ms, freq=415Hz, sample=66, buffer_id=05:42 [TRUNCATE prev:ch2 @124226.3ms -> 124499.0ms]
    db 32,0,113,0,66,127,6,3,93,1,66,5  ; n4299 t=124.499s dur=113ms, freq=349Hz, sample=66, buffer_id=05:42 [TRUNCATE prev:ch3 @124226.3ms -> 124499.0ms]
    db 59,0,100,0,42,127,10,7,92,0,42,10  ; n4300 t=124.531s dur=100ms, freq=92Hz, sample=42, buffer_id=0A:2A [TRUNCATE prev:ch7 @124292.2ms -> 124530.8ms]
    db 0,0,181,0,90,127,2,4,200,5,90,2  ; n4301 t=124.590s dur=181ms, freq=1480Hz, sample=90, buffer_id=02:5A
    db 0,0,181,0,94,127,2,5,224,6,94,2  ; n4302 t=124.590s dur=181ms, freq=1760Hz, sample=94, buffer_id=02:5E
    db 0,0,181,0,78,127,3,6,228,2,78,3  ; n4303 t=124.590s dur=181ms, freq=740Hz, sample=78, buffer_id=03:4E
    db 0,0,181,0,78,127,3,12,112,3,78,3  ; n4304 t=124.590s dur=181ms, freq=880Hz, sample=78, buffer_id=03:4E [TRUNCATE prev:ch12 @124408.1ms -> 124589.9ms]
    db 0,0,181,0,78,127,4,11,228,2,78,4  ; n4305 t=124.590s dur=181ms, freq=740Hz, sample=78, buffer_id=04:4E [TRUNCATE prev:ch11 @124408.1ms -> 124589.9ms]
    db 0,0,181,0,81,127,4,14,112,3,81,4  ; n4306 t=124.590s dur=181ms, freq=880Hz, sample=81, buffer_id=04:51 [TRUNCATE prev:ch14 @124408.1ms -> 124589.9ms]
    db 0,0,181,0,70,127,5,15,184,1,70,5  ; n4307 t=124.590s dur=181ms, freq=440Hz, sample=70, buffer_id=05:46 [TRUNCATE prev:ch15 @124408.1ms -> 124589.9ms]
    db 0,0,181,0,66,127,6,17,114,1,66,5  ; n4308 t=124.590s dur=181ms, freq=370Hz, sample=66, buffer_id=05:42 [TRUNCATE prev:ch17 @124408.1ms -> 124589.9ms]
    db 0,0,159,0,90,127,16,8,200,5,90,16  ; n4309 t=124.590s dur=159ms, freq=1480Hz, sample=90, buffer_id=10:5A [TRUNCATE prev:ch8 @124371.7ms -> 124589.9ms]
    db 0,0,159,0,78,127,17,9,228,2,78,16  ; n4310 t=124.590s dur=159ms, freq=740Hz, sample=78, buffer_id=10:4E [TRUNCATE prev:ch9 @124408.1ms -> 124589.9ms]
    db 0,0,159,0,66,127,18,26,114,1,66,18  ; n4311 t=124.590s dur=159ms, freq=370Hz, sample=66, buffer_id=12:42 [TRUNCATE prev:ch26 @124408.1ms -> 124589.9ms]
    db 0,0,159,0,47,127,19,25,110,0,47,19  ; n4312 t=124.590s dur=159ms, freq=110Hz, sample=47, buffer_id=13:2F [TRUNCATE prev:ch25 @124408.1ms -> 124589.9ms]
    db 20,0,159,0,33,127,20,10,55,0,33,20  ; n4313 t=124.590s dur=159ms, freq=55Hz, sample=33, buffer_id=14:21 [TRUNCATE prev:ch10 @124408.1ms -> 124589.9ms]
    db 159,0,100,0,42,127,10,27,92,0,42,10  ; n4314 t=124.610s dur=100ms, freq=92Hz, sample=42, buffer_id=0A:2A [TRUNCATE prev:ch27 @124452.0ms -> 124610.4ms]
    db 2,0,84,1,42,127,10,13,92,0,42,10  ; n4315 t=124.769s dur=340ms, freq=92Hz, sample=42, buffer_id=0A:2A
    db 0,0,120,0,62,127,7,16,38,1,62,7  ; n4316 t=124.772s dur=120ms, freq=294Hz, sample=62, buffer_id=07:3E
    db 0,0,100,0,68,127,7,18,184,1,68,7  ; n4317 t=124.772s dur=100ms, freq=440Hz, sample=68, buffer_id=07:44
    db 0,0,100,0,50,127,12,19,147,0,50,11  ; n4318 t=124.772s dur=100ms, freq=147Hz, sample=50, buffer_id=0B:32
    db 0,0,84,1,35,127,13,20,73,0,35,13  ; n4319 t=124.772s dur=340ms, freq=73Hz, sample=35, buffer_id=0D:23
    db 0,0,100,0,90,127,16,21,224,6,90,16  ; n4320 t=124.772s dur=100ms, freq=1760Hz, sample=90, buffer_id=10:5A
    db 0,0,100,0,78,127,17,23,112,3,78,16  ; n4321 t=124.772s dur=100ms, freq=880Hz, sample=78, buffer_id=10:4E
    db 0,0,100,0,66,127,18,24,184,1,66,18  ; n4322 t=124.772s dur=100ms, freq=440Hz, sample=66, buffer_id=12:42
    db 0,0,159,0,47,127,19,28,147,0,47,19  ; n4323 t=124.772s dur=159ms, freq=147Hz, sample=47, buffer_id=13:2F
    db 91,0,159,0,35,127,20,0,73,0,35,20  ; n4324 t=124.772s dur=159ms, freq=73Hz, sample=35, buffer_id=14:23 [TRUNCATE prev:ch0 @124499.0ms -> 124771.7ms]
    db 0,0,100,0,90,127,16,1,224,6,90,16  ; n4325 t=124.863s dur=100ms, freq=1760Hz, sample=90, buffer_id=10:5A
    db 0,0,100,0,78,127,17,2,112,3,78,16  ; n4326 t=124.863s dur=100ms, freq=880Hz, sample=78, buffer_id=10:4E
    db 91,0,100,0,66,127,18,3,184,1,66,18  ; n4327 t=124.863s dur=100ms, freq=440Hz, sample=66, buffer_id=12:42
    db 0,0,100,0,90,127,16,7,224,6,90,16  ; n4328 t=124.954s dur=100ms, freq=1760Hz, sample=90, buffer_id=10:5A
    db 0,0,100,0,78,127,17,8,112,3,78,16  ; n4329 t=124.954s dur=100ms, freq=880Hz, sample=78, buffer_id=10:4E
    db 0,0,100,0,66,127,18,9,184,1,66,18  ; n4330 t=124.954s dur=100ms, freq=440Hz, sample=66, buffer_id=12:42
    db 0,0,159,0,47,127,19,10,139,0,47,19  ; n4331 t=124.954s dur=159ms, freq=139Hz, sample=47, buffer_id=13:2F
    db 91,0,159,0,35,127,20,22,69,0,35,20  ; n4332 t=124.954s dur=159ms, freq=69Hz, sample=35, buffer_id=14:23
    db 0,0,100,0,90,127,16,4,224,6,90,16  ; n4333 t=125.044s dur=100ms, freq=1760Hz, sample=90, buffer_id=10:5A
    db 0,0,100,0,78,127,17,5,112,3,78,16  ; n4334 t=125.044s dur=100ms, freq=880Hz, sample=78, buffer_id=10:4E
    db 91,0,100,0,66,127,18,6,184,1,66,18  ; n4335 t=125.044s dur=100ms, freq=440Hz, sample=66, buffer_id=12:42
    db 0,0,113,0,90,127,2,0,200,5,90,2  ; n4336 t=125.135s dur=113ms, freq=1480Hz, sample=90, buffer_id=02:5A
    db 0,0,113,0,94,127,2,11,224,6,94,2  ; n4337 t=125.135s dur=113ms, freq=1760Hz, sample=94, buffer_id=02:5E
    db 0,0,113,0,78,127,3,14,228,2,78,3  ; n4338 t=125.135s dur=113ms, freq=740Hz, sample=78, buffer_id=03:4E
    db 0,0,113,0,78,127,3,15,112,3,78,3  ; n4339 t=125.135s dur=113ms, freq=880Hz, sample=78, buffer_id=03:4E
    db 0,0,113,0,78,127,4,12,228,2,78,4  ; n4340 t=125.135s dur=113ms, freq=740Hz, sample=78, buffer_id=04:4E
    db 0,0,113,0,81,127,4,16,112,3,81,4  ; n4341 t=125.135s dur=113ms, freq=880Hz, sample=81, buffer_id=04:51
    db 0,0,113,0,70,127,5,17,184,1,70,5  ; n4342 t=125.135s dur=113ms, freq=440Hz, sample=70, buffer_id=05:46
    db 0,0,113,0,66,127,6,18,114,1,66,5  ; n4343 t=125.135s dur=113ms, freq=370Hz, sample=66, buffer_id=05:42
    db 0,0,100,0,66,127,9,19,114,1,66,9  ; n4344 t=125.135s dur=100ms, freq=370Hz, sample=66, buffer_id=09:42
    db 0,0,100,0,78,127,9,21,228,2,78,9  ; n4345 t=125.135s dur=100ms, freq=740Hz, sample=78, buffer_id=09:4E
    db 0,0,100,0,58,127,11,23,220,0,58,11  ; n4346 t=125.135s dur=100ms, freq=220Hz, sample=58, buffer_id=0B:3A
    db 0,0,100,0,62,127,11,24,38,1,62,11  ; n4347 t=125.135s dur=100ms, freq=294Hz, sample=62, buffer_id=0B:3E
    db 0,0,100,0,54,127,12,25,185,0,54,11  ; n4348 t=125.135s dur=100ms, freq=185Hz, sample=54, buffer_id=0B:36
    db 0,0,100,0,90,127,16,26,224,6,90,16  ; n4349 t=125.135s dur=100ms, freq=1760Hz, sample=90, buffer_id=10:5A
    db 0,0,100,0,78,127,17,27,112,3,78,16  ; n4350 t=125.135s dur=100ms, freq=880Hz, sample=78, buffer_id=10:4E
    db 0,0,100,0,66,127,18,28,184,1,66,18  ; n4351 t=125.135s dur=100ms, freq=440Hz, sample=66, buffer_id=12:42
    db 0,0,159,0,47,127,19,29,123,0,47,19  ; n4352 t=125.135s dur=159ms, freq=123Hz, sample=47, buffer_id=13:2F
    db 91,0,159,0,35,127,20,30,62,0,35,20  ; n4353 t=125.135s dur=159ms, freq=62Hz, sample=35, buffer_id=14:23
    db 0,0,113,0,90,127,2,1,117,5,90,2  ; n4354 t=125.226s dur=113ms, freq=1397Hz, sample=90, buffer_id=02:5A
    db 0,0,113,0,90,127,2,2,125,6,90,2  ; n4355 t=125.226s dur=113ms, freq=1661Hz, sample=90, buffer_id=02:5A
    db 0,0,113,0,78,127,3,3,186,2,78,3  ; n4356 t=125.226s dur=113ms, freq=698Hz, sample=78, buffer_id=03:4E
    db 0,0,113,0,78,127,3,31,63,3,78,3  ; n4357 t=125.226s dur=113ms, freq=831Hz, sample=78, buffer_id=03:4E [TRUNCATE prev:ch31 @124499.0ms -> 125226.3ms]
    db 0,0,113,0,78,127,4,13,186,2,78,4  ; n4358 t=125.226s dur=113ms, freq=698Hz, sample=78, buffer_id=04:4E [TRUNCATE prev:ch13 @124769.4ms -> 125226.3ms]
    db 0,0,113,0,81,127,4,20,63,3,81,4  ; n4359 t=125.226s dur=113ms, freq=831Hz, sample=81, buffer_id=04:51 [TRUNCATE prev:ch20 @124771.7ms -> 125226.3ms]
    db 0,0,113,0,66,127,5,7,159,1,66,5  ; n4360 t=125.226s dur=113ms, freq=415Hz, sample=66, buffer_id=05:42 [TRUNCATE prev:ch7 @124953.5ms -> 125226.3ms]
    db 0,0,113,0,66,127,6,8,93,1,66,5  ; n4361 t=125.226s dur=113ms, freq=349Hz, sample=66, buffer_id=05:42 [TRUNCATE prev:ch8 @124953.5ms -> 125226.3ms]
    db 0,0,100,0,90,127,16,4,224,6,90,16  ; n4362 t=125.226s dur=100ms, freq=1760Hz, sample=90, buffer_id=10:5A [TRUNCATE prev:ch4 @125044.4ms -> 125226.3ms]
    db 0,0,100,0,78,127,17,5,112,3,78,16  ; n4363 t=125.226s dur=100ms, freq=880Hz, sample=78, buffer_id=10:4E [TRUNCATE prev:ch5 @125044.4ms -> 125226.3ms]
    db 91,0,100,0,66,127,18,9,184,1,66,18  ; n4364 t=125.226s dur=100ms, freq=440Hz, sample=66, buffer_id=12:42 [TRUNCATE prev:ch9 @124953.5ms -> 125226.3ms]
    db 0,0,181,0,90,127,2,10,200,5,90,2  ; n4365 t=125.317s dur=181ms, freq=1480Hz, sample=90, buffer_id=02:5A
    db 0,0,181,0,94,127,2,22,224,6,94,2  ; n4366 t=125.317s dur=181ms, freq=1760Hz, sample=94, buffer_id=02:5E
    db 0,0,181,0,78,127,3,14,228,2,78,3  ; n4367 t=125.317s dur=181ms, freq=740Hz, sample=78, buffer_id=03:4E [TRUNCATE prev:ch14 @125135.4ms -> 125317.2ms]
    db 0,0,181,0,78,127,3,15,112,3,78,3  ; n4368 t=125.317s dur=181ms, freq=880Hz, sample=78, buffer_id=03:4E [TRUNCATE prev:ch15 @125135.4ms -> 125317.2ms]
    db 0,0,181,0,78,127,4,12,228,2,78,4  ; n4369 t=125.317s dur=181ms, freq=740Hz, sample=78, buffer_id=04:4E [TRUNCATE prev:ch12 @125135.4ms -> 125317.2ms]
    db 0,0,181,0,81,127,4,16,112,3,81,4  ; n4370 t=125.317s dur=181ms, freq=880Hz, sample=81, buffer_id=04:51 [TRUNCATE prev:ch16 @125135.4ms -> 125317.2ms]
    db 0,0,181,0,70,127,5,17,184,1,70,5  ; n4371 t=125.317s dur=181ms, freq=440Hz, sample=70, buffer_id=05:46 [TRUNCATE prev:ch17 @125135.4ms -> 125317.2ms]
    db 0,0,181,0,66,127,6,18,114,1,66,5  ; n4372 t=125.317s dur=181ms, freq=370Hz, sample=66, buffer_id=05:42 [TRUNCATE prev:ch18 @125135.4ms -> 125317.2ms]
    db 0,0,100,0,90,127,16,26,224,6,90,16  ; n4373 t=125.317s dur=100ms, freq=1760Hz, sample=90, buffer_id=10:5A [TRUNCATE prev:ch26 @125135.4ms -> 125317.2ms]
    db 0,0,100,0,78,127,17,27,112,3,78,16  ; n4374 t=125.317s dur=100ms, freq=880Hz, sample=78, buffer_id=10:4E [TRUNCATE prev:ch27 @125135.4ms -> 125317.2ms]
    db 0,0,100,0,66,127,18,6,184,1,66,18  ; n4375 t=125.317s dur=100ms, freq=440Hz, sample=66, buffer_id=12:42 [TRUNCATE prev:ch6 @125044.4ms -> 125317.2ms]
    db 0,0,159,0,47,127,19,29,110,0,47,19  ; n4376 t=125.317s dur=159ms, freq=110Hz, sample=47, buffer_id=13:2F [TRUNCATE prev:ch29 @125135.4ms -> 125317.2ms]
    db 91,0,159,0,33,127,20,0,55,0,33,20  ; n4377 t=125.317s dur=159ms, freq=55Hz, sample=33, buffer_id=14:21 [TRUNCATE prev:ch0 @125135.4ms -> 125317.2ms]
    db 0,0,100,0,90,127,16,4,224,6,90,16  ; n4378 t=125.408s dur=100ms, freq=1760Hz, sample=90, buffer_id=10:5A [TRUNCATE prev:ch4 @125226.3ms -> 125408.1ms]
    db 0,0,100,0,78,127,17,5,112,3,78,16  ; n4379 t=125.408s dur=100ms, freq=880Hz, sample=78, buffer_id=10:4E [TRUNCATE prev:ch5 @125226.3ms -> 125408.1ms]
    db 89,0,100,0,66,127,18,28,184,1,66,18  ; n4380 t=125.408s dur=100ms, freq=440Hz, sample=66, buffer_id=12:42 [TRUNCATE prev:ch28 @125135.4ms -> 125408.1ms]
    db 2,0,159,0,47,127,10,11,123,0,47,10  ; n4381 t=125.497s dur=159ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 0,0,159,0,59,127,7,19,247,0,59,7  ; n4382 t=125.499s dur=159ms, freq=247Hz, sample=59, buffer_id=07:3B
    db 0,0,159,0,71,127,7,21,238,1,71,7  ; n4383 t=125.499s dur=159ms, freq=494Hz, sample=71, buffer_id=07:47
    db 0,0,100,0,47,127,12,23,123,0,47,11  ; n4384 t=125.499s dur=100ms, freq=123Hz, sample=47, buffer_id=0B:2F
    db 0,0,84,1,35,127,13,24,62,0,35,13  ; n4385 t=125.499s dur=340ms, freq=62Hz, sample=35, buffer_id=0D:23
    db 0,0,159,0,85,127,16,25,220,3,85,16  ; n4386 t=125.499s dur=159ms, freq=988Hz, sample=85, buffer_id=10:55
    db 0,0,159,0,70,127,17,30,238,1,70,16  ; n4387 t=125.499s dur=159ms, freq=494Hz, sample=70, buffer_id=10:46
    db 0,0,157,0,54,127,18,1,247,0,54,18  ; n4388 t=125.499s dur=157ms, freq=247Hz, sample=54, buffer_id=12:36 [TRUNCATE prev:ch1 @125226.3ms -> 125499.0ms]
    db 0,0,159,0,47,127,19,29,123,0,47,19  ; n4389 t=125.499s dur=159ms, freq=123Hz, sample=47, buffer_id=13:2F [TRUNCATE prev:ch29 @125317.2ms -> 125499.0ms]
    db 180,0,159,0,35,127,20,2,62,0,35,20  ; n4390 t=125.499s dur=159ms, freq=62Hz, sample=35, buffer_id=14:23 [TRUNCATE prev:ch2 @125226.3ms -> 125499.0ms]
    db 2,0,159,0,47,127,10,0,123,0,47,10  ; n4391 t=125.678s dur=159ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 0,0,159,0,59,127,7,3,247,0,59,7  ; n4392 t=125.681s dur=159ms, freq=247Hz, sample=59, buffer_id=07:3B
    db 0,0,159,0,71,127,7,6,238,1,71,7  ; n4393 t=125.681s dur=159ms, freq=494Hz, sample=71, buffer_id=07:47
    db 0,0,159,0,85,127,16,7,85,4,85,16  ; n4394 t=125.681s dur=159ms, freq=1109Hz, sample=85, buffer_id=10:55
    db 0,0,159,0,73,127,17,8,42,2,73,16  ; n4395 t=125.681s dur=159ms, freq=554Hz, sample=73, buffer_id=10:49
    db 0,0,159,0,66,127,18,13,21,1,66,18  ; n4396 t=125.681s dur=159ms, freq=277Hz, sample=66, buffer_id=12:42
    db 0,0,159,0,47,127,19,9,110,0,47,19  ; n4397 t=125.681s dur=159ms, freq=110Hz, sample=47, buffer_id=13:2F
    db 180,0,159,0,33,127,20,20,55,0,33,20  ; n4398 t=125.681s dur=159ms, freq=55Hz, sample=33, buffer_id=14:21
    db 2,0,159,0,47,127,10,1,123,0,47,10  ; n4399 t=125.860s dur=159ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 0,0,113,0,86,127,2,2,151,4,86,2  ; n4400 t=125.863s dur=113ms, freq=1175Hz, sample=86, buffer_id=02:56
    db 0,0,113,0,90,127,2,4,200,5,90,2  ; n4401 t=125.863s dur=113ms, freq=1480Hz, sample=90, buffer_id=02:5A
    db 0,0,113,0,74,127,3,5,75,2,74,3  ; n4402 t=125.863s dur=113ms, freq=587Hz, sample=74, buffer_id=03:4A
    db 0,0,113,0,78,127,3,10,228,2,78,3  ; n4403 t=125.863s dur=113ms, freq=740Hz, sample=78, buffer_id=03:4E
    db 0,0,113,0,74,127,4,11,75,2,74,4  ; n4404 t=125.863s dur=113ms, freq=587Hz, sample=74, buffer_id=04:4A
    db 0,0,113,0,78,127,4,14,228,2,78,4  ; n4405 t=125.863s dur=113ms, freq=740Hz, sample=78, buffer_id=04:4E
    db 0,0,113,0,66,127,5,12,114,1,66,5  ; n4406 t=125.863s dur=113ms, freq=370Hz, sample=66, buffer_id=05:42
    db 0,0,113,0,62,127,6,15,38,1,62,5  ; n4407 t=125.863s dur=113ms, freq=294Hz, sample=62, buffer_id=05:3E
    db 0,0,159,0,59,127,7,16,247,0,59,7  ; n4408 t=125.863s dur=159ms, freq=247Hz, sample=59, buffer_id=07:3B
    db 0,0,159,0,71,127,7,17,238,1,71,7  ; n4409 t=125.863s dur=159ms, freq=494Hz, sample=71, buffer_id=07:47
    db 0,0,100,0,66,127,9,18,114,1,66,9  ; n4410 t=125.863s dur=100ms, freq=370Hz, sample=66, buffer_id=09:42
    db 0,0,100,0,78,127,9,19,228,2,78,9  ; n4411 t=125.863s dur=100ms, freq=740Hz, sample=78, buffer_id=09:4E
    db 0,0,100,0,62,127,11,21,38,1,62,11  ; n4412 t=125.863s dur=100ms, freq=294Hz, sample=62, buffer_id=0B:3E
    db 0,0,100,0,66,127,11,22,114,1,66,11  ; n4413 t=125.863s dur=100ms, freq=370Hz, sample=66, buffer_id=0B:42
    db 0,0,100,0,54,127,12,23,185,0,54,11  ; n4414 t=125.863s dur=100ms, freq=185Hz, sample=54, buffer_id=0B:36
    db 0,0,159,0,86,127,16,25,151,4,86,16  ; n4415 t=125.863s dur=159ms, freq=1175Hz, sample=86, buffer_id=10:56
    db 0,0,159,0,74,127,17,26,75,2,74,16  ; n4416 t=125.863s dur=159ms, freq=587Hz, sample=74, buffer_id=10:4A
    db 0,0,159,0,66,127,18,27,38,1,66,18  ; n4417 t=125.863s dur=159ms, freq=294Hz, sample=66, buffer_id=12:42
    db 0,0,159,0,42,127,19,28,98,0,42,19  ; n4418 t=125.863s dur=159ms, freq=98Hz, sample=42, buffer_id=13:2A
    db 91,0,159,0,30,127,20,29,49,0,30,20  ; n4419 t=125.863s dur=159ms, freq=49Hz, sample=30, buffer_id=14:1E
    db 0,0,113,0,85,127,2,30,85,4,85,2  ; n4420 t=125.954s dur=113ms, freq=1109Hz, sample=85, buffer_id=02:55
    db 0,0,113,0,90,127,2,31,117,5,90,2  ; n4421 t=125.954s dur=113ms, freq=1397Hz, sample=90, buffer_id=02:5A
    db 0,0,113,0,73,127,3,24,42,2,73,3  ; n4422 t=125.954s dur=113ms, freq=554Hz, sample=73, buffer_id=03:49 [TRUNCATE prev:ch24 @125499.0ms -> 125953.5ms]
    db 0,0,113,0,78,127,3,0,186,2,78,3  ; n4423 t=125.954s dur=113ms, freq=698Hz, sample=78, buffer_id=03:4E [TRUNCATE prev:ch0 @125678.5ms -> 125953.5ms]
    db 0,0,113,0,73,127,4,3,42,2,73,4  ; n4424 t=125.954s dur=113ms, freq=554Hz, sample=73, buffer_id=04:49 [TRUNCATE prev:ch3 @125680.8ms -> 125953.5ms]
    db 0,0,113,0,78,127,4,6,186,2,78,4  ; n4425 t=125.954s dur=113ms, freq=698Hz, sample=78, buffer_id=04:4E [TRUNCATE prev:ch6 @125680.8ms -> 125953.5ms]
    db 0,0,113,0,66,127,5,7,93,1,66,5  ; n4426 t=125.954s dur=113ms, freq=349Hz, sample=66, buffer_id=05:42 [TRUNCATE prev:ch7 @125680.8ms -> 125953.5ms]
    db 89,0,113,0,61,127,6,8,21,1,61,5  ; n4427 t=125.954s dur=113ms, freq=277Hz, sample=61, buffer_id=05:3D [TRUNCATE prev:ch8 @125680.8ms -> 125953.5ms]
    db 2,0,159,0,47,127,10,9,123,0,47,10  ; n4428 t=126.042s dur=159ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 0,0,181,0,86,127,2,13,151,4,86,2  ; n4429 t=126.044s dur=181ms, freq=1175Hz, sample=86, buffer_id=02:56
    db 0,0,181,0,90,127,2,20,200,5,90,2  ; n4430 t=126.044s dur=181ms, freq=1480Hz, sample=90, buffer_id=02:5A
    db 0,0,181,0,74,127,3,5,75,2,74,3  ; n4431 t=126.044s dur=181ms, freq=587Hz, sample=74, buffer_id=03:4A [TRUNCATE prev:ch5 @125862.6ms -> 126044.4ms]
    db 0,0,181,0,78,127,3,10,228,2,78,3  ; n4432 t=126.044s dur=181ms, freq=740Hz, sample=78, buffer_id=03:4E [TRUNCATE prev:ch10 @125862.6ms -> 126044.4ms]
    db 0,0,181,0,74,127,4,11,75,2,74,4  ; n4433 t=126.044s dur=181ms, freq=587Hz, sample=74, buffer_id=04:4A [TRUNCATE prev:ch11 @125862.6ms -> 126044.4ms]
    db 0,0,181,0,78,127,4,14,228,2,78,4  ; n4434 t=126.044s dur=181ms, freq=740Hz, sample=78, buffer_id=04:4E [TRUNCATE prev:ch14 @125862.6ms -> 126044.4ms]
    db 0,0,181,0,66,127,5,12,114,1,66,5  ; n4435 t=126.044s dur=181ms, freq=370Hz, sample=66, buffer_id=05:42 [TRUNCATE prev:ch12 @125862.6ms -> 126044.4ms]
    db 0,0,181,0,62,127,6,15,38,1,62,5  ; n4436 t=126.044s dur=181ms, freq=294Hz, sample=62, buffer_id=05:3E [TRUNCATE prev:ch15 @125862.6ms -> 126044.4ms]
    db 0,0,159,0,59,127,7,16,247,0,59,7  ; n4437 t=126.044s dur=159ms, freq=247Hz, sample=59, buffer_id=07:3B [TRUNCATE prev:ch16 @125862.6ms -> 126044.4ms]
    db 0,0,159,0,71,127,7,17,238,1,71,7  ; n4438 t=126.044s dur=159ms, freq=494Hz, sample=71, buffer_id=07:47 [TRUNCATE prev:ch17 @125862.6ms -> 126044.4ms]
    db 0,0,150,0,87,127,16,1,39,5,87,16  ; n4439 t=126.044s dur=150ms, freq=1319Hz, sample=87, buffer_id=10:57 [TRUNCATE prev:ch1 @125860.4ms -> 126044.4ms]
    db 0,0,159,0,74,127,17,26,147,2,74,16  ; n4440 t=126.044s dur=159ms, freq=659Hz, sample=74, buffer_id=10:4A [TRUNCATE prev:ch26 @125862.6ms -> 126044.4ms]
    db 0,0,159,0,66,127,18,27,74,1,66,18  ; n4441 t=126.044s dur=159ms, freq=330Hz, sample=66, buffer_id=12:42 [TRUNCATE prev:ch27 @125862.6ms -> 126044.4ms]
    db 0,0,159,0,42,127,19,28,92,0,42,19  ; n4442 t=126.044s dur=159ms, freq=92Hz, sample=42, buffer_id=13:2A [TRUNCATE prev:ch28 @125862.6ms -> 126044.4ms]
    db 180,0,159,0,30,127,20,29,46,0,30,20  ; n4443 t=126.044s dur=159ms, freq=46Hz, sample=30, buffer_id=14:1E [TRUNCATE prev:ch29 @125862.6ms -> 126044.4ms]
    db 2,0,159,0,47,127,10,2,123,0,47,10  ; n4444 t=126.224s dur=159ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 0,0,159,0,59,127,7,4,247,0,59,7  ; n4445 t=126.226s dur=159ms, freq=247Hz, sample=59, buffer_id=07:3B
    db 0,0,159,0,71,127,7,18,238,1,71,7  ; n4446 t=126.226s dur=159ms, freq=494Hz, sample=71, buffer_id=07:47
    db 0,0,100,0,47,127,12,19,123,0,47,11  ; n4447 t=126.226s dur=100ms, freq=123Hz, sample=47, buffer_id=0B:2F
    db 0,0,84,1,35,127,13,21,62,0,35,13  ; n4448 t=126.226s dur=340ms, freq=62Hz, sample=35, buffer_id=0D:23
    db 0,0,159,0,90,127,16,22,200,5,90,16  ; n4449 t=126.226s dur=159ms, freq=1480Hz, sample=90, buffer_id=10:5A
    db 0,0,159,0,78,127,17,23,228,2,78,16  ; n4450 t=126.226s dur=159ms, freq=740Hz, sample=78, buffer_id=10:4E
    db 0,0,159,0,66,127,18,25,114,1,66,18  ; n4451 t=126.226s dur=159ms, freq=370Hz, sample=66, buffer_id=12:42
    db 0,0,159,0,47,127,19,0,123,0,47,19  ; n4452 t=126.226s dur=159ms, freq=123Hz, sample=47, buffer_id=13:2F [TRUNCATE prev:ch0 @125953.5ms -> 126226.3ms]
    db 180,0,159,0,35,127,20,3,62,0,35,20  ; n4453 t=126.226s dur=159ms, freq=62Hz, sample=35, buffer_id=14:23 [TRUNCATE prev:ch3 @125953.5ms -> 126226.3ms]
    db 2,0,159,0,47,127,10,1,123,0,47,10  ; n4454 t=126.406s dur=159ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 0,0,159,0,59,127,7,6,247,0,59,7  ; n4455 t=126.408s dur=159ms, freq=247Hz, sample=59, buffer_id=07:3B
    db 0,0,159,0,71,127,7,7,238,1,71,7  ; n4456 t=126.408s dur=159ms, freq=494Hz, sample=71, buffer_id=07:47
    db 0,0,159,0,86,127,16,8,151,4,86,16  ; n4457 t=126.408s dur=159ms, freq=1175Hz, sample=86, buffer_id=10:56
    db 0,0,159,0,74,127,17,9,75,2,74,16  ; n4458 t=126.408s dur=159ms, freq=587Hz, sample=74, buffer_id=10:4A
    db 0,0,159,0,66,127,18,16,38,1,66,18  ; n4459 t=126.408s dur=159ms, freq=294Hz, sample=66, buffer_id=12:42
    db 0,0,159,0,47,127,19,17,110,0,47,19  ; n4460 t=126.408s dur=159ms, freq=110Hz, sample=47, buffer_id=13:2F
    db 179,0,159,0,33,127,20,24,55,0,33,20  ; n4461 t=126.408s dur=159ms, freq=55Hz, sample=33, buffer_id=14:21
    db 2,0,84,1,47,127,10,0,123,0,47,10  ; n4462 t=126.588s dur=340ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 0,0,113,0,86,127,2,2,151,4,86,2  ; n4463 t=126.590s dur=113ms, freq=1175Hz, sample=86, buffer_id=02:56
    db 0,0,113,0,90,127,2,3,200,5,90,2  ; n4464 t=126.590s dur=113ms, freq=1480Hz, sample=90, buffer_id=02:5A
    db 0,0,113,0,74,127,3,4,75,2,74,3  ; n4465 t=126.590s dur=113ms, freq=587Hz, sample=74, buffer_id=03:4A
    db 0,0,113,0,78,127,3,5,228,2,78,3  ; n4466 t=126.590s dur=113ms, freq=740Hz, sample=78, buffer_id=03:4E
    db 0,0,113,0,74,127,4,10,75,2,74,4  ; n4467 t=126.590s dur=113ms, freq=587Hz, sample=74, buffer_id=04:4A
    db 0,0,113,0,78,127,4,11,228,2,78,4  ; n4468 t=126.590s dur=113ms, freq=740Hz, sample=78, buffer_id=04:4E
    db 0,0,113,0,66,127,5,13,114,1,66,5  ; n4469 t=126.590s dur=113ms, freq=370Hz, sample=66, buffer_id=05:42
    db 0,0,113,0,62,127,6,12,38,1,62,5  ; n4470 t=126.590s dur=113ms, freq=294Hz, sample=62, buffer_id=05:3E
    db 0,0,84,1,59,127,7,14,247,0,59,7  ; n4471 t=126.590s dur=340ms, freq=247Hz, sample=59, buffer_id=07:3B
    db 0,0,84,1,71,127,7,15,238,1,71,7  ; n4472 t=126.590s dur=340ms, freq=494Hz, sample=71, buffer_id=07:47
    db 0,0,100,0,66,127,9,18,114,1,66,9  ; n4473 t=126.590s dur=100ms, freq=370Hz, sample=66, buffer_id=09:42
    db 0,0,100,0,78,127,9,19,228,2,78,9  ; n4474 t=126.590s dur=100ms, freq=740Hz, sample=78, buffer_id=09:4E
    db 0,0,100,0,62,127,11,20,38,1,62,11  ; n4475 t=126.590s dur=100ms, freq=294Hz, sample=62, buffer_id=0B:3E
    db 0,0,100,0,66,127,11,22,114,1,66,11  ; n4476 t=126.590s dur=100ms, freq=370Hz, sample=66, buffer_id=0B:42
    db 0,0,100,0,54,127,12,23,185,0,54,11  ; n4477 t=126.590s dur=100ms, freq=185Hz, sample=54, buffer_id=0B:36
    db 0,0,100,0,90,127,16,25,200,5,90,16  ; n4478 t=126.590s dur=100ms, freq=1480Hz, sample=90, buffer_id=10:5A
    db 0,0,100,0,78,127,17,26,228,2,78,16  ; n4479 t=126.590s dur=100ms, freq=740Hz, sample=78, buffer_id=10:4E
    db 0,0,100,0,66,127,18,28,114,1,66,18  ; n4480 t=126.590s dur=100ms, freq=370Hz, sample=66, buffer_id=12:42
    db 0,0,159,0,42,127,19,27,98,0,42,19  ; n4481 t=126.590s dur=159ms, freq=98Hz, sample=42, buffer_id=13:2A
    db 91,0,159,0,30,127,20,30,49,0,30,20  ; n4482 t=126.590s dur=159ms, freq=49Hz, sample=30, buffer_id=14:1E
    db 0,0,113,0,85,127,2,29,85,4,85,2  ; n4483 t=126.681s dur=113ms, freq=1109Hz, sample=85, buffer_id=02:55
    db 0,0,113,0,90,127,2,31,117,5,90,2  ; n4484 t=126.681s dur=113ms, freq=1397Hz, sample=90, buffer_id=02:5A [TRUNCATE prev:ch31 @125953.5ms -> 126680.8ms]
    db 0,0,113,0,73,127,3,21,42,2,73,3  ; n4485 t=126.681s dur=113ms, freq=554Hz, sample=73, buffer_id=03:49 [TRUNCATE prev:ch21 @126226.3ms -> 126680.8ms]
    db 0,0,113,0,78,127,3,1,186,2,78,3  ; n4486 t=126.681s dur=113ms, freq=698Hz, sample=78, buffer_id=03:4E [TRUNCATE prev:ch1 @126405.8ms -> 126680.8ms]
    db 0,0,113,0,73,127,4,6,42,2,73,4  ; n4487 t=126.681s dur=113ms, freq=554Hz, sample=73, buffer_id=04:49 [TRUNCATE prev:ch6 @126408.1ms -> 126680.8ms]
    db 0,0,113,0,78,127,4,7,186,2,78,4  ; n4488 t=126.681s dur=113ms, freq=698Hz, sample=78, buffer_id=04:4E [TRUNCATE prev:ch7 @126408.1ms -> 126680.8ms]
    db 0,0,113,0,66,127,5,8,93,1,66,5  ; n4489 t=126.681s dur=113ms, freq=349Hz, sample=66, buffer_id=05:42 [TRUNCATE prev:ch8 @126408.1ms -> 126680.8ms]
    db 0,0,113,0,61,127,6,9,21,1,61,5  ; n4490 t=126.681s dur=113ms, freq=277Hz, sample=61, buffer_id=05:3D [TRUNCATE prev:ch9 @126408.1ms -> 126680.8ms]
    db 0,0,100,0,90,127,16,16,200,5,90,16  ; n4491 t=126.681s dur=100ms, freq=1480Hz, sample=90, buffer_id=10:5A [TRUNCATE prev:ch16 @126408.1ms -> 126680.8ms]
    db 0,0,100,0,78,127,17,17,228,2,78,16  ; n4492 t=126.681s dur=100ms, freq=740Hz, sample=78, buffer_id=10:4E [TRUNCATE prev:ch17 @126408.1ms -> 126680.8ms]
    db 91,0,100,0,66,127,18,24,114,1,66,18  ; n4493 t=126.681s dur=100ms, freq=370Hz, sample=66, buffer_id=12:42 [TRUNCATE prev:ch24 @126408.1ms -> 126680.8ms]
    db 0,0,181,0,86,127,2,2,151,4,86,2  ; n4494 t=126.772s dur=181ms, freq=1175Hz, sample=86, buffer_id=02:56 [TRUNCATE prev:ch2 @126589.9ms -> 126771.7ms]
    db 0,0,181,0,90,127,2,3,200,5,90,2  ; n4495 t=126.772s dur=181ms, freq=1480Hz, sample=90, buffer_id=02:5A [TRUNCATE prev:ch3 @126589.9ms -> 126771.7ms]
    db 0,0,181,0,74,127,3,4,75,2,74,3  ; n4496 t=126.772s dur=181ms, freq=587Hz, sample=74, buffer_id=03:4A [TRUNCATE prev:ch4 @126589.9ms -> 126771.7ms]
    db 0,0,181,0,78,127,3,5,228,2,78,3  ; n4497 t=126.772s dur=181ms, freq=740Hz, sample=78, buffer_id=03:4E [TRUNCATE prev:ch5 @126589.9ms -> 126771.7ms]
    db 0,0,181,0,74,127,4,10,75,2,74,4  ; n4498 t=126.772s dur=181ms, freq=587Hz, sample=74, buffer_id=04:4A [TRUNCATE prev:ch10 @126589.9ms -> 126771.7ms]
    db 0,0,181,0,78,127,4,11,228,2,78,4  ; n4499 t=126.772s dur=181ms, freq=740Hz, sample=78, buffer_id=04:4E [TRUNCATE prev:ch11 @126589.9ms -> 126771.7ms]
    db 0,0,181,0,66,127,5,13,114,1,66,5  ; n4500 t=126.772s dur=181ms, freq=370Hz, sample=66, buffer_id=05:42 [TRUNCATE prev:ch13 @126589.9ms -> 126771.7ms]
    db 0,0,181,0,62,127,6,12,38,1,62,5  ; n4501 t=126.772s dur=181ms, freq=294Hz, sample=62, buffer_id=05:3E [TRUNCATE prev:ch12 @126589.9ms -> 126771.7ms]
    db 0,0,100,0,90,127,16,25,200,5,90,16  ; n4502 t=126.772s dur=100ms, freq=1480Hz, sample=90, buffer_id=10:5A [TRUNCATE prev:ch25 @126589.9ms -> 126771.7ms]
    db 0,0,100,0,78,127,17,26,228,2,78,16  ; n4503 t=126.772s dur=100ms, freq=740Hz, sample=78, buffer_id=10:4E [TRUNCATE prev:ch26 @126589.9ms -> 126771.7ms]
    db 0,0,100,0,66,127,18,28,114,1,66,18  ; n4504 t=126.772s dur=100ms, freq=370Hz, sample=66, buffer_id=12:42 [TRUNCATE prev:ch28 @126589.9ms -> 126771.7ms]
    db 0,0,159,0,42,127,19,27,92,0,42,19  ; n4505 t=126.772s dur=159ms, freq=92Hz, sample=42, buffer_id=13:2A [TRUNCATE prev:ch27 @126589.9ms -> 126771.7ms]
    db 91,0,159,0,30,127,20,30,46,0,30,20  ; n4506 t=126.772s dur=159ms, freq=46Hz, sample=30, buffer_id=14:1E [TRUNCATE prev:ch30 @126589.9ms -> 126771.7ms]
    db 0,0,100,0,90,127,16,16,200,5,90,16  ; n4507 t=126.863s dur=100ms, freq=1480Hz, sample=90, buffer_id=10:5A [TRUNCATE prev:ch16 @126680.8ms -> 126862.6ms]
    db 0,0,100,0,78,127,17,17,228,2,78,16  ; n4508 t=126.863s dur=100ms, freq=740Hz, sample=78, buffer_id=10:4E [TRUNCATE prev:ch17 @126680.8ms -> 126862.6ms]
    db 89,0,100,0,66,127,18,24,114,1,66,18  ; n4509 t=126.863s dur=100ms, freq=370Hz, sample=66, buffer_id=12:42 [TRUNCATE prev:ch24 @126680.8ms -> 126862.6ms]
    db 2,0,159,0,47,127,10,18,123,0,47,10  ; n4510 t=126.951s dur=159ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 0,0,159,0,59,127,7,19,247,0,59,7  ; n4511 t=126.954s dur=159ms, freq=247Hz, sample=59, buffer_id=07:3B
    db 0,0,159,0,71,127,7,20,238,1,71,7  ; n4512 t=126.954s dur=159ms, freq=494Hz, sample=71, buffer_id=07:47
    db 0,0,100,0,47,127,12,22,123,0,47,11  ; n4513 t=126.954s dur=100ms, freq=123Hz, sample=47, buffer_id=0B:2F
    db 0,0,84,1,35,127,13,23,62,0,35,13  ; n4514 t=126.954s dur=340ms, freq=62Hz, sample=35, buffer_id=0D:23
    db 0,0,159,0,90,127,16,25,117,5,90,16  ; n4515 t=126.954s dur=159ms, freq=1397Hz, sample=90, buffer_id=10:5A [TRUNCATE prev:ch25 @126771.7ms -> 126953.5ms]
    db 0,0,159,0,78,127,17,26,186,2,78,16  ; n4516 t=126.954s dur=159ms, freq=698Hz, sample=78, buffer_id=10:4E [TRUNCATE prev:ch26 @126771.7ms -> 126953.5ms]
    db 0,0,159,0,66,127,18,28,93,1,66,18  ; n4517 t=126.954s dur=159ms, freq=349Hz, sample=66, buffer_id=12:42 [TRUNCATE prev:ch28 @126771.7ms -> 126953.5ms]
    db 0,0,159,0,47,127,19,0,123,0,47,19  ; n4518 t=126.954s dur=159ms, freq=123Hz, sample=47, buffer_id=13:2F [TRUNCATE prev:ch0 @126587.6ms -> 126953.5ms]
    db 180,0,159,0,35,127,20,14,62,0,35,20  ; n4519 t=126.954s dur=159ms, freq=62Hz, sample=35, buffer_id=14:23 [TRUNCATE prev:ch14 @126589.9ms -> 126953.5ms]
    db 2,0,159,0,47,127,10,1,123,0,47,10  ; n4520 t=127.133s dur=159ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 0,0,159,0,59,127,7,6,247,0,59,7  ; n4521 t=127.135s dur=159ms, freq=247Hz, sample=59, buffer_id=07:3B
    db 0,0,159,0,71,127,7,7,238,1,71,7  ; n4522 t=127.135s dur=159ms, freq=494Hz, sample=71, buffer_id=07:47
    db 0,0,159,0,85,127,16,8,85,4,85,16  ; n4523 t=127.135s dur=159ms, freq=1109Hz, sample=85, buffer_id=10:55
    db 0,0,159,0,73,127,17,9,42,2,73,16  ; n4524 t=127.135s dur=159ms, freq=554Hz, sample=73, buffer_id=10:49
    db 0,0,159,0,66,127,18,15,21,1,66,18  ; n4525 t=127.135s dur=159ms, freq=277Hz, sample=66, buffer_id=12:42
    db 0,0,159,0,47,127,19,21,110,0,47,19  ; n4526 t=127.135s dur=159ms, freq=110Hz, sample=47, buffer_id=13:2F
    db 179,0,159,0,33,127,20,27,55,0,33,20  ; n4527 t=127.135s dur=159ms, freq=55Hz, sample=33, buffer_id=14:21
    db 2,0,84,1,47,127,10,0,123,0,47,10  ; n4528 t=127.315s dur=340ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 0,0,113,0,85,127,2,2,85,4,85,2  ; n4529 t=127.317s dur=113ms, freq=1109Hz, sample=85, buffer_id=02:55
    db 0,0,113,0,90,127,2,4,117,5,90,2  ; n4530 t=127.317s dur=113ms, freq=1397Hz, sample=90, buffer_id=02:5A
    db 0,0,113,0,73,127,3,3,42,2,73,3  ; n4531 t=127.317s dur=113ms, freq=554Hz, sample=73, buffer_id=03:49
    db 0,0,113,0,78,127,3,10,186,2,78,3  ; n4532 t=127.317s dur=113ms, freq=698Hz, sample=78, buffer_id=03:4E
    db 0,0,113,0,73,127,4,5,42,2,73,4  ; n4533 t=127.317s dur=113ms, freq=554Hz, sample=73, buffer_id=04:49
    db 0,0,113,0,78,127,4,12,186,2,78,4  ; n4534 t=127.317s dur=113ms, freq=698Hz, sample=78, buffer_id=04:4E
    db 0,0,113,0,66,127,5,11,93,1,66,5  ; n4535 t=127.317s dur=113ms, freq=349Hz, sample=66, buffer_id=05:42
    db 0,0,113,0,61,127,6,13,21,1,61,5  ; n4536 t=127.317s dur=113ms, freq=277Hz, sample=61, buffer_id=05:3D
    db 0,0,84,1,59,127,7,14,247,0,59,7  ; n4537 t=127.317s dur=340ms, freq=247Hz, sample=59, buffer_id=07:3B
    db 0,0,84,1,71,127,7,16,238,1,71,7  ; n4538 t=127.317s dur=340ms, freq=494Hz, sample=71, buffer_id=07:47
    db 0,0,100,0,66,127,9,17,114,1,66,9  ; n4539 t=127.317s dur=100ms, freq=370Hz, sample=66, buffer_id=09:42
    db 0,0,100,0,78,127,9,18,228,2,78,9  ; n4540 t=127.317s dur=100ms, freq=740Hz, sample=78, buffer_id=09:4E
    db 0,0,100,0,61,127,11,19,21,1,61,11  ; n4541 t=127.317s dur=100ms, freq=277Hz, sample=61, buffer_id=0B:3D
    db 0,0,100,0,66,127,11,20,93,1,66,11  ; n4542 t=127.317s dur=100ms, freq=349Hz, sample=66, buffer_id=0B:42
    db 0,0,100,0,54,127,12,22,185,0,54,11  ; n4543 t=127.317s dur=100ms, freq=185Hz, sample=54, buffer_id=0B:36
    db 0,0,100,0,90,127,16,24,117,5,90,16  ; n4544 t=127.317s dur=100ms, freq=1397Hz, sample=90, buffer_id=10:5A
    db 0,0,100,0,78,127,17,25,186,2,78,16  ; n4545 t=127.317s dur=100ms, freq=698Hz, sample=78, buffer_id=10:4E
    db 0,0,100,0,66,127,18,26,93,1,66,18  ; n4546 t=127.317s dur=100ms, freq=349Hz, sample=66, buffer_id=12:42
    db 0,0,159,0,42,127,19,28,98,0,42,19  ; n4547 t=127.317s dur=159ms, freq=98Hz, sample=42, buffer_id=13:2A
    db 91,0,159,0,30,127,20,29,49,0,30,20  ; n4548 t=127.317s dur=159ms, freq=49Hz, sample=30, buffer_id=14:1E
    db 0,0,113,0,85,127,2,30,23,4,85,2  ; n4549 t=127.408s dur=113ms, freq=1047Hz, sample=85, buffer_id=02:55
    db 0,0,113,0,86,127,2,31,39,5,86,2  ; n4550 t=127.408s dur=113ms, freq=1319Hz, sample=86, buffer_id=02:56
    db 0,0,113,0,71,127,3,23,11,2,71,3  ; n4551 t=127.408s dur=113ms, freq=523Hz, sample=71, buffer_id=03:47 [TRUNCATE prev:ch23 @126953.5ms -> 127408.1ms]
    db 0,0,113,0,74,127,3,1,147,2,74,3  ; n4552 t=127.408s dur=113ms, freq=659Hz, sample=74, buffer_id=03:4A [TRUNCATE prev:ch1 @127133.1ms -> 127408.1ms]
    db 0,0,113,0,73,127,4,6,11,2,73,4  ; n4553 t=127.408s dur=113ms, freq=523Hz, sample=73, buffer_id=04:49 [TRUNCATE prev:ch6 @127135.4ms -> 127408.1ms]
    db 0,0,113,0,74,127,4,7,147,2,74,4  ; n4554 t=127.408s dur=113ms, freq=659Hz, sample=74, buffer_id=04:4A [TRUNCATE prev:ch7 @127135.4ms -> 127408.1ms]
    db 0,0,113,0,62,127,5,8,74,1,62,5  ; n4555 t=127.408s dur=113ms, freq=330Hz, sample=62, buffer_id=05:3E [TRUNCATE prev:ch8 @127135.4ms -> 127408.1ms]
    db 0,0,113,0,61,127,6,9,6,1,61,5  ; n4556 t=127.408s dur=113ms, freq=262Hz, sample=61, buffer_id=05:3D [TRUNCATE prev:ch9 @127135.4ms -> 127408.1ms]
    db 0,0,100,0,90,127,16,15,117,5,90,16  ; n4557 t=127.408s dur=100ms, freq=1397Hz, sample=90, buffer_id=10:5A [TRUNCATE prev:ch15 @127135.4ms -> 127408.1ms]
    db 0,0,100,0,78,127,17,21,186,2,78,16  ; n4558 t=127.408s dur=100ms, freq=698Hz, sample=78, buffer_id=10:4E [TRUNCATE prev:ch21 @127135.4ms -> 127408.1ms]
    db 91,0,100,0,66,127,18,27,93,1,66,18  ; n4559 t=127.408s dur=100ms, freq=349Hz, sample=66, buffer_id=12:42 [TRUNCATE prev:ch27 @127135.4ms -> 127408.1ms]
    db 0,0,181,0,85,127,2,2,85,4,85,2  ; n4560 t=127.499s dur=181ms, freq=1109Hz, sample=85, buffer_id=02:55 [TRUNCATE prev:ch2 @127317.2ms -> 127499.0ms]
    db 0,0,181,0,90,127,2,4,117,5,90,2  ; n4561 t=127.499s dur=181ms, freq=1397Hz, sample=90, buffer_id=02:5A [TRUNCATE prev:ch4 @127317.2ms -> 127499.0ms]
    db 0,0,181,0,73,127,3,3,42,2,73,3  ; n4562 t=127.499s dur=181ms, freq=554Hz, sample=73, buffer_id=03:49 [TRUNCATE prev:ch3 @127317.2ms -> 127499.0ms]
    db 0,0,181,0,78,127,3,10,186,2,78,3  ; n4563 t=127.499s dur=181ms, freq=698Hz, sample=78, buffer_id=03:4E [TRUNCATE prev:ch10 @127317.2ms -> 127499.0ms]
    db 0,0,181,0,73,127,4,5,42,2,73,4  ; n4564 t=127.499s dur=181ms, freq=554Hz, sample=73, buffer_id=04:49 [TRUNCATE prev:ch5 @127317.2ms -> 127499.0ms]
    db 0,0,181,0,78,127,4,12,186,2,78,4  ; n4565 t=127.499s dur=181ms, freq=698Hz, sample=78, buffer_id=04:4E [TRUNCATE prev:ch12 @127317.2ms -> 127499.0ms]
    db 0,0,181,0,66,127,5,11,93,1,66,5  ; n4566 t=127.499s dur=181ms, freq=349Hz, sample=66, buffer_id=05:42 [TRUNCATE prev:ch11 @127317.2ms -> 127499.0ms]
    db 0,0,181,0,61,127,6,13,21,1,61,5  ; n4567 t=127.499s dur=181ms, freq=277Hz, sample=61, buffer_id=05:3D [TRUNCATE prev:ch13 @127317.2ms -> 127499.0ms]
    db 0,0,100,0,90,127,16,24,117,5,90,16  ; n4568 t=127.499s dur=100ms, freq=1397Hz, sample=90, buffer_id=10:5A [TRUNCATE prev:ch24 @127317.2ms -> 127499.0ms]
    db 0,0,100,0,78,127,17,25,186,2,78,16  ; n4569 t=127.499s dur=100ms, freq=698Hz, sample=78, buffer_id=10:4E [TRUNCATE prev:ch25 @127317.2ms -> 127499.0ms]
    db 0,0,100,0,66,127,18,26,93,1,66,18  ; n4570 t=127.499s dur=100ms, freq=349Hz, sample=66, buffer_id=12:42 [TRUNCATE prev:ch26 @127317.2ms -> 127499.0ms]
    db 0,0,159,0,42,127,19,28,92,0,42,19  ; n4571 t=127.499s dur=159ms, freq=92Hz, sample=42, buffer_id=13:2A [TRUNCATE prev:ch28 @127317.2ms -> 127499.0ms]
    db 91,0,159,0,30,127,20,29,46,0,30,20  ; n4572 t=127.499s dur=159ms, freq=46Hz, sample=30, buffer_id=14:1E [TRUNCATE prev:ch29 @127317.2ms -> 127499.0ms]
    db 0,0,100,0,90,127,16,15,117,5,90,16  ; n4573 t=127.590s dur=100ms, freq=1397Hz, sample=90, buffer_id=10:5A [TRUNCATE prev:ch15 @127408.1ms -> 127589.9ms]
    db 0,0,100,0,78,127,17,21,186,2,78,16  ; n4574 t=127.590s dur=100ms, freq=698Hz, sample=78, buffer_id=10:4E [TRUNCATE prev:ch21 @127408.1ms -> 127589.9ms]
    db 89,0,100,0,66,127,18,27,93,1,66,18  ; n4575 t=127.590s dur=100ms, freq=349Hz, sample=66, buffer_id=12:42 [TRUNCATE prev:ch27 @127408.1ms -> 127589.9ms]
    db 2,0,159,0,47,127,10,17,123,0,47,10  ; n4576 t=127.678s dur=159ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 0,0,159,0,59,127,7,18,247,0,59,7  ; n4577 t=127.681s dur=159ms, freq=247Hz, sample=59, buffer_id=07:3B
    db 0,0,159,0,71,127,7,19,238,1,71,7  ; n4578 t=127.681s dur=159ms, freq=494Hz, sample=71, buffer_id=07:47
    db 0,0,100,0,47,127,12,20,123,0,47,11  ; n4579 t=127.681s dur=100ms, freq=123Hz, sample=47, buffer_id=0B:2F
    db 0,0,84,1,35,127,13,22,62,0,35,13  ; n4580 t=127.681s dur=340ms, freq=62Hz, sample=35, buffer_id=0D:23
    db 0,0,159,0,47,127,19,0,123,0,47,19  ; n4581 t=127.681s dur=159ms, freq=123Hz, sample=47, buffer_id=13:2F [TRUNCATE prev:ch0 @127314.9ms -> 127680.8ms]
    db 45,0,159,0,35,127,20,14,62,0,35,20  ; n4582 t=127.681s dur=159ms, freq=62Hz, sample=35, buffer_id=14:23 [TRUNCATE prev:ch14 @127317.2ms -> 127680.8ms]
    db 0,0,150,0,87,127,16,1,39,5,87,16  ; n4583 t=127.726s dur=150ms, freq=1319Hz, sample=87, buffer_id=10:57
    db 0,0,159,0,74,127,17,6,147,2,74,16  ; n4584 t=127.726s dur=159ms, freq=659Hz, sample=74, buffer_id=10:4A
    db 134,0,159,0,66,127,18,7,74,1,66,18  ; n4585 t=127.726s dur=159ms, freq=330Hz, sample=66, buffer_id=12:42
    db 2,0,159,0,47,127,10,8,123,0,47,10  ; n4586 t=127.860s dur=159ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 0,0,159,0,59,127,7,9,247,0,59,7  ; n4587 t=127.863s dur=159ms, freq=247Hz, sample=59, buffer_id=07:3B
    db 0,0,159,0,71,127,7,23,238,1,71,7  ; n4588 t=127.863s dur=159ms, freq=494Hz, sample=71, buffer_id=07:47
    db 0,0,159,0,47,127,19,16,110,0,47,19  ; n4589 t=127.863s dur=159ms, freq=110Hz, sample=47, buffer_id=13:2F
    db 46,0,159,0,33,127,20,24,55,0,33,20  ; n4590 t=127.863s dur=159ms, freq=55Hz, sample=33, buffer_id=14:21
    db 0,0,159,0,85,127,16,2,23,4,85,16  ; n4591 t=127.908s dur=159ms, freq=1047Hz, sample=85, buffer_id=10:55
    db 0,0,159,0,73,127,17,3,11,2,73,16  ; n4592 t=127.908s dur=159ms, freq=523Hz, sample=73, buffer_id=10:49
    db 134,0,148,0,54,127,18,4,6,1,54,18  ; n4593 t=127.908s dur=148ms, freq=262Hz, sample=54, buffer_id=12:36
    db 2,0,84,1,47,127,10,0,123,0,47,10  ; n4594 t=128.042s dur=340ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 0,0,113,0,85,127,2,5,23,4,85,2  ; n4595 t=128.044s dur=113ms, freq=1047Hz, sample=85, buffer_id=02:55
    db 0,0,113,0,86,127,2,10,39,5,86,2  ; n4596 t=128.044s dur=113ms, freq=1319Hz, sample=86, buffer_id=02:56
    db 0,0,113,0,71,127,3,11,11,2,71,3  ; n4597 t=128.044s dur=113ms, freq=523Hz, sample=71, buffer_id=03:47
    db 0,0,113,0,74,127,3,12,147,2,74,3  ; n4598 t=128.044s dur=113ms, freq=659Hz, sample=74, buffer_id=03:4A
    db 0,0,113,0,73,127,4,13,11,2,73,4  ; n4599 t=128.044s dur=113ms, freq=523Hz, sample=73, buffer_id=04:49
    db 0,0,113,0,74,127,4,14,147,2,74,4  ; n4600 t=128.044s dur=113ms, freq=659Hz, sample=74, buffer_id=04:4A
    db 0,0,113,0,62,127,5,15,74,1,62,5  ; n4601 t=128.044s dur=113ms, freq=330Hz, sample=62, buffer_id=05:3E
    db 0,0,113,0,61,127,6,17,6,1,61,5  ; n4602 t=128.044s dur=113ms, freq=262Hz, sample=61, buffer_id=05:3D
    db 0,0,84,1,59,127,7,19,247,0,59,7  ; n4603 t=128.044s dur=340ms, freq=247Hz, sample=59, buffer_id=07:3B
    db 0,0,84,1,71,127,7,18,238,1,71,7  ; n4604 t=128.044s dur=340ms, freq=494Hz, sample=71, buffer_id=07:47
    db 0,0,100,0,66,127,9,20,114,1,66,9  ; n4605 t=128.044s dur=100ms, freq=370Hz, sample=66, buffer_id=09:42
    db 0,0,100,0,78,127,9,21,228,2,78,9  ; n4606 t=128.044s dur=100ms, freq=740Hz, sample=78, buffer_id=09:4E
    db 0,0,100,0,59,127,11,25,6,1,59,11  ; n4607 t=128.044s dur=100ms, freq=262Hz, sample=59, buffer_id=0B:3B
    db 0,0,100,0,62,127,11,26,74,1,62,11  ; n4608 t=128.044s dur=100ms, freq=330Hz, sample=62, buffer_id=0B:3E
    db 0,0,100,0,54,127,12,27,185,0,54,11  ; n4609 t=128.044s dur=100ms, freq=185Hz, sample=54, buffer_id=0B:36
    db 0,0,100,0,87,127,16,28,39,5,87,16  ; n4610 t=128.044s dur=100ms, freq=1319Hz, sample=87, buffer_id=10:57
    db 0,0,100,0,74,127,17,29,147,2,74,16  ; n4611 t=128.044s dur=100ms, freq=659Hz, sample=74, buffer_id=10:4A
    db 0,0,100,0,66,127,18,30,74,1,66,18  ; n4612 t=128.044s dur=100ms, freq=330Hz, sample=66, buffer_id=12:42
    db 0,0,159,0,42,127,19,31,98,0,42,19  ; n4613 t=128.044s dur=159ms, freq=98Hz, sample=42, buffer_id=13:2A
    db 91,0,159,0,30,127,20,22,49,0,30,20  ; n4614 t=128.044s dur=159ms, freq=49Hz, sample=30, buffer_id=14:1E [TRUNCATE prev:ch22 @127680.8ms -> 128044.4ms]
    db 0,0,113,0,85,127,2,1,220,3,85,2  ; n4615 t=128.135s dur=113ms, freq=988Hz, sample=85, buffer_id=02:55
    db 0,0,113,0,86,127,2,6,221,4,86,2  ; n4616 t=128.135s dur=113ms, freq=1245Hz, sample=86, buffer_id=02:56
    db 0,0,113,0,71,127,3,7,238,1,71,3  ; n4617 t=128.135s dur=113ms, freq=494Hz, sample=71, buffer_id=03:47
    db 0,0,113,0,74,127,3,8,110,2,74,3  ; n4618 t=128.135s dur=113ms, freq=622Hz, sample=74, buffer_id=03:4A [TRUNCATE prev:ch8 @127860.4ms -> 128135.4ms]
    db 0,0,113,0,70,127,4,9,238,1,70,4  ; n4619 t=128.135s dur=113ms, freq=494Hz, sample=70, buffer_id=04:46 [TRUNCATE prev:ch9 @127862.6ms -> 128135.4ms]
    db 0,0,113,0,74,127,4,16,110,2,74,4  ; n4620 t=128.135s dur=113ms, freq=622Hz, sample=74, buffer_id=04:4A [TRUNCATE prev:ch16 @127862.6ms -> 128135.4ms]
    db 0,0,113,0,62,127,5,23,55,1,62,5  ; n4621 t=128.135s dur=113ms, freq=311Hz, sample=62, buffer_id=05:3E [TRUNCATE prev:ch23 @127862.6ms -> 128135.4ms]
    db 0,0,113,0,61,127,6,24,247,0,61,5  ; n4622 t=128.135s dur=113ms, freq=247Hz, sample=61, buffer_id=05:3D [TRUNCATE prev:ch24 @127862.6ms -> 128135.4ms]
    db 0,0,100,0,87,127,16,2,39,5,87,16  ; n4623 t=128.135s dur=100ms, freq=1319Hz, sample=87, buffer_id=10:57 [TRUNCATE prev:ch2 @127908.1ms -> 128135.4ms]
    db 0,0,100,0,74,127,17,3,147,2,74,16  ; n4624 t=128.135s dur=100ms, freq=659Hz, sample=74, buffer_id=10:4A [TRUNCATE prev:ch3 @127908.1ms -> 128135.4ms]
    db 91,0,100,0,66,127,18,4,74,1,66,18  ; n4625 t=128.135s dur=100ms, freq=330Hz, sample=66, buffer_id=12:42 [TRUNCATE prev:ch4 @127908.1ms -> 128135.4ms]
    db 0,0,181,0,85,127,2,5,23,4,85,2  ; n4626 t=128.226s dur=181ms, freq=1047Hz, sample=85, buffer_id=02:55 [TRUNCATE prev:ch5 @128044.4ms -> 128226.3ms]
    db 0,0,162,0,86,127,2,10,39,5,86,2  ; n4627 t=128.226s dur=162ms, freq=1319Hz, sample=86, buffer_id=02:56 [TRUNCATE prev:ch10 @128044.4ms -> 128226.3ms]
    db 0,0,181,0,71,127,3,11,11,2,71,3  ; n4628 t=128.226s dur=181ms, freq=523Hz, sample=71, buffer_id=03:47 [TRUNCATE prev:ch11 @128044.4ms -> 128226.3ms]
    db 0,0,162,0,74,127,3,12,147,2,74,3  ; n4629 t=128.226s dur=162ms, freq=659Hz, sample=74, buffer_id=03:4A [TRUNCATE prev:ch12 @128044.4ms -> 128226.3ms]
    db 0,0,181,0,73,127,4,13,11,2,73,4  ; n4630 t=128.226s dur=181ms, freq=523Hz, sample=73, buffer_id=04:49 [TRUNCATE prev:ch13 @128044.4ms -> 128226.3ms]
    db 0,0,181,0,74,127,4,14,147,2,74,4  ; n4631 t=128.226s dur=181ms, freq=659Hz, sample=74, buffer_id=04:4A [TRUNCATE prev:ch14 @128044.4ms -> 128226.3ms]
    db 0,0,162,0,62,127,5,15,74,1,62,5  ; n4632 t=128.226s dur=162ms, freq=330Hz, sample=62, buffer_id=05:3E [TRUNCATE prev:ch15 @128044.4ms -> 128226.3ms]
    db 0,0,181,0,61,127,6,17,6,1,61,5  ; n4633 t=128.226s dur=181ms, freq=262Hz, sample=61, buffer_id=05:3D [TRUNCATE prev:ch17 @128044.4ms -> 128226.3ms]
    db 0,0,100,0,87,127,16,28,39,5,87,16  ; n4634 t=128.226s dur=100ms, freq=1319Hz, sample=87, buffer_id=10:57 [TRUNCATE prev:ch28 @128044.4ms -> 128226.3ms]
    db 0,0,100,0,74,127,17,29,147,2,74,16  ; n4635 t=128.226s dur=100ms, freq=659Hz, sample=74, buffer_id=10:4A [TRUNCATE prev:ch29 @128044.4ms -> 128226.3ms]
    db 0,0,100,0,66,127,18,30,74,1,66,18  ; n4636 t=128.226s dur=100ms, freq=330Hz, sample=66, buffer_id=12:42 [TRUNCATE prev:ch30 @128044.4ms -> 128226.3ms]
    db 0,0,159,0,42,127,19,31,92,0,42,19  ; n4637 t=128.226s dur=159ms, freq=92Hz, sample=42, buffer_id=13:2A [TRUNCATE prev:ch31 @128044.4ms -> 128226.3ms]
    db 91,0,159,0,30,127,20,22,46,0,30,20  ; n4638 t=128.226s dur=159ms, freq=46Hz, sample=30, buffer_id=14:1E [TRUNCATE prev:ch22 @128044.4ms -> 128226.3ms]
    db 0,0,100,0,87,127,16,2,39,5,87,16  ; n4639 t=128.317s dur=100ms, freq=1319Hz, sample=87, buffer_id=10:57 [TRUNCATE prev:ch2 @128135.4ms -> 128317.2ms]
    db 0,0,100,0,74,127,17,3,147,2,74,16  ; n4640 t=128.317s dur=100ms, freq=659Hz, sample=74, buffer_id=10:4A [TRUNCATE prev:ch3 @128135.4ms -> 128317.2ms]
    db 89,0,100,0,66,127,18,4,74,1,66,18  ; n4641 t=128.317s dur=100ms, freq=330Hz, sample=66, buffer_id=12:42 [TRUNCATE prev:ch4 @128135.4ms -> 128317.2ms]
    db 2,0,159,0,47,127,10,20,123,0,47,10  ; n4642 t=128.406s dur=159ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 0,0,159,0,59,127,7,21,247,0,59,7  ; n4643 t=128.408s dur=159ms, freq=247Hz, sample=59, buffer_id=07:3B
    db 0,0,159,0,71,127,7,25,238,1,71,7  ; n4644 t=128.408s dur=159ms, freq=494Hz, sample=71, buffer_id=07:47
    db 0,0,100,0,47,127,12,26,123,0,47,11  ; n4645 t=128.408s dur=100ms, freq=123Hz, sample=47, buffer_id=0B:2F
    db 0,0,84,1,35,127,13,27,62,0,35,13  ; n4646 t=128.408s dur=340ms, freq=62Hz, sample=35, buffer_id=0D:23
    db 0,0,159,0,85,127,16,0,220,3,85,16  ; n4647 t=128.408s dur=159ms, freq=988Hz, sample=85, buffer_id=10:55 [TRUNCATE prev:ch0 @128042.2ms -> 128408.1ms]
    db 0,0,159,0,70,127,17,18,238,1,70,16  ; n4648 t=128.408s dur=159ms, freq=494Hz, sample=70, buffer_id=10:46 [TRUNCATE prev:ch18 @128044.4ms -> 128408.1ms]
    db 0,0,157,0,54,127,18,19,247,0,54,18  ; n4649 t=128.408s dur=157ms, freq=247Hz, sample=54, buffer_id=12:36 [TRUNCATE prev:ch19 @128044.4ms -> 128408.1ms]
    db 0,0,159,0,47,127,19,1,123,0,47,19  ; n4650 t=128.408s dur=159ms, freq=123Hz, sample=47, buffer_id=13:2F [TRUNCATE prev:ch1 @128135.4ms -> 128408.1ms]
    db 180,0,159,0,35,127,20,6,62,0,35,20  ; n4651 t=128.408s dur=159ms, freq=62Hz, sample=35, buffer_id=14:23 [TRUNCATE prev:ch6 @128135.4ms -> 128408.1ms]
    db 2,0,159,0,47,127,10,7,123,0,47,10  ; n4652 t=128.588s dur=159ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 0,0,159,0,59,127,7,8,247,0,59,7  ; n4653 t=128.590s dur=159ms, freq=247Hz, sample=59, buffer_id=07:3B
    db 0,0,159,0,71,127,7,9,238,1,71,7  ; n4654 t=128.590s dur=159ms, freq=494Hz, sample=71, buffer_id=07:47
    db 0,0,159,0,85,127,16,10,85,4,85,16  ; n4655 t=128.590s dur=159ms, freq=1109Hz, sample=85, buffer_id=10:55
    db 0,0,159,0,73,127,17,12,42,2,73,16  ; n4656 t=128.590s dur=159ms, freq=554Hz, sample=73, buffer_id=10:49
    db 0,0,159,0,66,127,18,15,21,1,66,18  ; n4657 t=128.590s dur=159ms, freq=277Hz, sample=66, buffer_id=12:42
    db 0,0,159,0,47,127,19,16,110,0,47,19  ; n4658 t=128.590s dur=159ms, freq=110Hz, sample=47, buffer_id=13:2F
    db 179,0,159,0,33,127,20,22,55,0,33,20  ; n4659 t=128.590s dur=159ms, freq=55Hz, sample=33, buffer_id=14:21
    db 2,0,159,0,47,127,10,0,123,0,47,10  ; n4660 t=128.769s dur=159ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 0,0,113,0,85,127,2,1,220,3,85,2  ; n4661 t=128.772s dur=113ms, freq=988Hz, sample=85, buffer_id=02:55
    db 0,0,113,0,86,127,2,2,151,4,86,2  ; n4662 t=128.772s dur=113ms, freq=1175Hz, sample=86, buffer_id=02:56
    db 0,0,113,0,71,127,3,3,238,1,71,3  ; n4663 t=128.772s dur=113ms, freq=494Hz, sample=71, buffer_id=03:47
    db 0,0,113,0,74,127,3,4,75,2,74,3  ; n4664 t=128.772s dur=113ms, freq=587Hz, sample=74, buffer_id=03:4A
    db 0,0,113,0,70,127,4,5,238,1,70,4  ; n4665 t=128.772s dur=113ms, freq=494Hz, sample=70, buffer_id=04:46
    db 0,0,113,0,74,127,4,6,75,2,74,4  ; n4666 t=128.772s dur=113ms, freq=587Hz, sample=74, buffer_id=04:4A
    db 0,0,113,0,62,127,5,11,38,1,62,5  ; n4667 t=128.772s dur=113ms, freq=294Hz, sample=62, buffer_id=05:3E
    db 0,0,113,0,61,127,6,13,247,0,61,5  ; n4668 t=128.772s dur=113ms, freq=247Hz, sample=61, buffer_id=05:3D
    db 0,0,159,0,59,127,7,14,247,0,59,7  ; n4669 t=128.772s dur=159ms, freq=247Hz, sample=59, buffer_id=07:3B
    db 0,0,159,0,71,127,7,17,238,1,71,7  ; n4670 t=128.772s dur=159ms, freq=494Hz, sample=71, buffer_id=07:47
    db 0,0,100,0,66,127,9,18,114,1,66,9  ; n4671 t=128.772s dur=100ms, freq=370Hz, sample=66, buffer_id=09:42
    db 0,0,100,0,78,127,9,19,228,2,78,9  ; n4672 t=128.772s dur=100ms, freq=740Hz, sample=78, buffer_id=09:4E
    db 0,0,100,0,59,127,11,20,247,0,59,11  ; n4673 t=128.772s dur=100ms, freq=247Hz, sample=59, buffer_id=0B:3B
    db 0,0,100,0,62,127,11,21,38,1,62,11  ; n4674 t=128.772s dur=100ms, freq=294Hz, sample=62, buffer_id=0B:3E
    db 0,0,100,0,54,127,12,23,185,0,54,11  ; n4675 t=128.772s dur=100ms, freq=185Hz, sample=54, buffer_id=0B:36
    db 0,0,159,0,86,127,16,24,151,4,86,16  ; n4676 t=128.772s dur=159ms, freq=1175Hz, sample=86, buffer_id=10:56
    db 0,0,159,0,74,127,17,25,75,2,74,16  ; n4677 t=128.772s dur=159ms, freq=587Hz, sample=74, buffer_id=10:4A
    db 0,0,159,0,66,127,18,26,38,1,66,18  ; n4678 t=128.772s dur=159ms, freq=294Hz, sample=66, buffer_id=12:42
    db 0,0,159,0,42,127,19,28,98,0,42,19  ; n4679 t=128.772s dur=159ms, freq=98Hz, sample=42, buffer_id=13:2A
    db 91,0,159,0,30,127,20,29,49,0,30,20  ; n4680 t=128.772s dur=159ms, freq=49Hz, sample=30, buffer_id=14:1E
    db 0,0,113,0,85,127,2,30,164,3,85,2  ; n4681 t=128.863s dur=113ms, freq=932Hz, sample=85, buffer_id=02:55
    db 0,0,113,0,85,127,2,31,85,4,85,2  ; n4682 t=128.863s dur=113ms, freq=1109Hz, sample=85, buffer_id=02:55
    db 0,0,113,0,71,127,3,27,210,1,71,3  ; n4683 t=128.863s dur=113ms, freq=466Hz, sample=71, buffer_id=03:47 [TRUNCATE prev:ch27 @128408.1ms -> 128862.6ms]
    db 0,0,113,0,73,127,3,7,42,2,73,3  ; n4684 t=128.863s dur=113ms, freq=554Hz, sample=73, buffer_id=03:49 [TRUNCATE prev:ch7 @128587.6ms -> 128862.6ms]
    db 0,0,113,0,70,127,4,8,210,1,70,4  ; n4685 t=128.863s dur=113ms, freq=466Hz, sample=70, buffer_id=04:46 [TRUNCATE prev:ch8 @128589.9ms -> 128862.6ms]
    db 0,0,113,0,73,127,4,9,42,2,73,4  ; n4686 t=128.863s dur=113ms, freq=554Hz, sample=73, buffer_id=04:49 [TRUNCATE prev:ch9 @128589.9ms -> 128862.6ms]
    db 0,0,113,0,61,127,5,10,21,1,61,5  ; n4687 t=128.863s dur=113ms, freq=277Hz, sample=61, buffer_id=05:3D [TRUNCATE prev:ch10 @128589.9ms -> 128862.6ms]
    db 89,0,113,0,61,127,6,12,233,0,61,5  ; n4688 t=128.863s dur=113ms, freq=233Hz, sample=61, buffer_id=05:3D [TRUNCATE prev:ch12 @128589.9ms -> 128862.6ms]
    db 2,0,159,0,47,127,10,15,123,0,47,10  ; n4689 t=128.951s dur=159ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 0,0,181,0,85,127,2,16,220,3,85,2  ; n4690 t=128.953s dur=181ms, freq=988Hz, sample=85, buffer_id=02:55
    db 0,0,181,0,86,127,2,22,151,4,86,2  ; n4691 t=128.953s dur=181ms, freq=1175Hz, sample=86, buffer_id=02:56
    db 0,0,181,0,71,127,3,3,238,1,71,3  ; n4692 t=128.953s dur=181ms, freq=494Hz, sample=71, buffer_id=03:47 [TRUNCATE prev:ch3 @128771.7ms -> 128953.5ms]
    db 0,0,181,0,74,127,3,4,75,2,74,3  ; n4693 t=128.953s dur=181ms, freq=587Hz, sample=74, buffer_id=03:4A [TRUNCATE prev:ch4 @128771.7ms -> 128953.5ms]
    db 0,0,181,0,70,127,4,5,238,1,70,4  ; n4694 t=128.953s dur=181ms, freq=494Hz, sample=70, buffer_id=04:46 [TRUNCATE prev:ch5 @128771.7ms -> 128953.5ms]
    db 0,0,181,0,74,127,4,6,75,2,74,4  ; n4695 t=128.953s dur=181ms, freq=587Hz, sample=74, buffer_id=04:4A [TRUNCATE prev:ch6 @128771.7ms -> 128953.5ms]
    db 0,0,181,0,62,127,5,11,38,1,62,5  ; n4696 t=128.953s dur=181ms, freq=294Hz, sample=62, buffer_id=05:3E [TRUNCATE prev:ch11 @128771.7ms -> 128953.5ms]
    db 0,0,181,0,61,127,6,13,247,0,61,5  ; n4697 t=128.953s dur=181ms, freq=247Hz, sample=61, buffer_id=05:3D [TRUNCATE prev:ch13 @128771.7ms -> 128953.5ms]
    db 0,0,159,0,59,127,7,14,247,0,59,7  ; n4698 t=128.953s dur=159ms, freq=247Hz, sample=59, buffer_id=07:3B [TRUNCATE prev:ch14 @128771.7ms -> 128953.5ms]
    db 0,0,159,0,71,127,7,17,238,1,71,7  ; n4699 t=128.953s dur=159ms, freq=494Hz, sample=71, buffer_id=07:47 [TRUNCATE prev:ch17 @128771.7ms -> 128953.5ms]
    db 0,0,150,0,87,127,16,0,39,5,87,16  ; n4700 t=128.953s dur=150ms, freq=1319Hz, sample=87, buffer_id=10:57 [TRUNCATE prev:ch0 @128769.4ms -> 128953.5ms]
    db 0,0,159,0,74,127,17,25,147,2,74,16  ; n4701 t=128.953s dur=159ms, freq=659Hz, sample=74, buffer_id=10:4A [TRUNCATE prev:ch25 @128771.7ms -> 128953.5ms]
    db 0,0,159,0,66,127,18,26,74,1,66,18  ; n4702 t=128.953s dur=159ms, freq=330Hz, sample=66, buffer_id=12:42 [TRUNCATE prev:ch26 @128771.7ms -> 128953.5ms]
    db 0,0,159,0,42,127,19,28,92,0,42,19  ; n4703 t=128.953s dur=159ms, freq=92Hz, sample=42, buffer_id=13:2A [TRUNCATE prev:ch28 @128771.7ms -> 128953.5ms]
    db 180,0,159,0,30,127,20,29,46,0,30,20  ; n4704 t=128.953s dur=159ms, freq=46Hz, sample=30, buffer_id=14:1E [TRUNCATE prev:ch29 @128771.7ms -> 128953.5ms]
    db 2,0,159,0,47,127,10,1,123,0,47,10  ; n4705 t=129.133s dur=159ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 0,0,159,0,59,127,7,2,247,0,59,7  ; n4706 t=129.135s dur=159ms, freq=247Hz, sample=59, buffer_id=07:3B
    db 0,0,159,0,71,127,7,18,238,1,71,7  ; n4707 t=129.135s dur=159ms, freq=494Hz, sample=71, buffer_id=07:47
    db 0,0,100,0,47,127,12,19,123,0,47,11  ; n4708 t=129.135s dur=100ms, freq=123Hz, sample=47, buffer_id=0B:2F
    db 0,0,84,1,35,127,13,20,62,0,35,13  ; n4709 t=129.135s dur=340ms, freq=62Hz, sample=35, buffer_id=0D:23
    db 0,0,159,0,90,127,16,21,200,5,90,16  ; n4710 t=129.135s dur=159ms, freq=1480Hz, sample=90, buffer_id=10:5A
    db 0,0,159,0,78,127,17,23,228,2,78,16  ; n4711 t=129.135s dur=159ms, freq=740Hz, sample=78, buffer_id=10:4E
    db 0,0,159,0,66,127,18,24,114,1,66,18  ; n4712 t=129.135s dur=159ms, freq=370Hz, sample=66, buffer_id=12:42
    db 0,0,159,0,47,127,19,7,123,0,47,19  ; n4713 t=129.135s dur=159ms, freq=123Hz, sample=47, buffer_id=13:2F [TRUNCATE prev:ch7 @128862.6ms -> 129135.3ms]
    db 180,0,159,0,35,127,20,8,62,0,35,20  ; n4714 t=129.135s dur=159ms, freq=62Hz, sample=35, buffer_id=14:23 [TRUNCATE prev:ch8 @128862.6ms -> 129135.3ms]
    db 2,0,159,0,47,127,10,0,123,0,47,10  ; n4715 t=129.315s dur=159ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 0,0,159,0,59,127,7,9,247,0,59,7  ; n4716 t=129.317s dur=159ms, freq=247Hz, sample=59, buffer_id=07:3B
    db 0,0,159,0,71,127,7,10,238,1,71,7  ; n4717 t=129.317s dur=159ms, freq=494Hz, sample=71, buffer_id=07:47
    db 0,0,159,0,86,127,16,12,151,4,86,16  ; n4718 t=129.317s dur=159ms, freq=1175Hz, sample=86, buffer_id=10:56
    db 0,0,159,0,74,127,17,14,75,2,74,16  ; n4719 t=129.317s dur=159ms, freq=587Hz, sample=74, buffer_id=10:4A
    db 0,0,159,0,66,127,18,15,38,1,66,18  ; n4720 t=129.317s dur=159ms, freq=294Hz, sample=66, buffer_id=12:42
    db 0,0,159,0,47,127,19,17,110,0,47,19  ; n4721 t=129.317s dur=159ms, freq=110Hz, sample=47, buffer_id=13:2F
    db 179,0,159,0,33,127,20,25,55,0,33,20  ; n4722 t=129.317s dur=159ms, freq=55Hz, sample=33, buffer_id=14:21
    db 2,0,159,0,47,127,10,2,123,0,47,10  ; n4723 t=129.497s dur=159ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 0,0,113,0,86,127,2,1,151,4,86,2  ; n4724 t=129.499s dur=113ms, freq=1175Hz, sample=86, buffer_id=02:56
    db 0,0,113,0,90,127,2,3,200,5,90,2  ; n4725 t=129.499s dur=113ms, freq=1480Hz, sample=90, buffer_id=02:5A
    db 0,0,113,0,74,127,3,5,75,2,74,3  ; n4726 t=129.499s dur=113ms, freq=587Hz, sample=74, buffer_id=03:4A
    db 0,0,113,0,78,127,3,4,228,2,78,3  ; n4727 t=129.499s dur=113ms, freq=740Hz, sample=78, buffer_id=03:4E
    db 0,0,113,0,74,127,4,7,75,2,74,4  ; n4728 t=129.499s dur=113ms, freq=587Hz, sample=74, buffer_id=04:4A
    db 0,0,113,0,78,127,4,6,228,2,78,4  ; n4729 t=129.499s dur=113ms, freq=740Hz, sample=78, buffer_id=04:4E
    db 0,0,113,0,66,127,5,8,114,1,66,5  ; n4730 t=129.499s dur=113ms, freq=370Hz, sample=66, buffer_id=05:42
    db 0,0,113,0,62,127,6,13,38,1,62,5  ; n4731 t=129.499s dur=113ms, freq=294Hz, sample=62, buffer_id=05:3E
    db 0,0,159,0,59,127,7,11,247,0,59,7  ; n4732 t=129.499s dur=159ms, freq=247Hz, sample=59, buffer_id=07:3B
    db 0,0,159,0,71,127,7,16,238,1,71,7  ; n4733 t=129.499s dur=159ms, freq=494Hz, sample=71, buffer_id=07:47
    db 0,0,100,0,66,127,9,18,114,1,66,9  ; n4734 t=129.499s dur=100ms, freq=370Hz, sample=66, buffer_id=09:42
    db 0,0,100,0,78,127,9,19,228,2,78,9  ; n4735 t=129.499s dur=100ms, freq=740Hz, sample=78, buffer_id=09:4E
    db 0,0,100,0,59,127,11,21,247,0,59,11  ; n4736 t=129.499s dur=100ms, freq=247Hz, sample=59, buffer_id=0B:3B
    db 0,0,100,0,62,127,11,22,38,1,62,11  ; n4737 t=129.499s dur=100ms, freq=294Hz, sample=62, buffer_id=0B:3E
    db 0,0,100,0,54,127,12,23,185,0,54,11  ; n4738 t=129.499s dur=100ms, freq=185Hz, sample=54, buffer_id=0B:36
    db 0,0,159,0,90,127,16,24,200,5,90,16  ; n4739 t=129.499s dur=159ms, freq=1480Hz, sample=90, buffer_id=10:5A
    db 0,0,159,0,78,127,17,26,228,2,78,16  ; n4740 t=129.499s dur=159ms, freq=740Hz, sample=78, buffer_id=10:4E
    db 0,0,159,0,66,127,18,27,114,1,66,18  ; n4741 t=129.499s dur=159ms, freq=370Hz, sample=66, buffer_id=12:42
    db 0,0,159,0,42,127,19,29,98,0,42,19  ; n4742 t=129.499s dur=159ms, freq=98Hz, sample=42, buffer_id=13:2A
    db 91,0,159,0,30,127,20,28,49,0,30,20  ; n4743 t=129.499s dur=159ms, freq=49Hz, sample=30, buffer_id=14:1E
    db 0,0,113,0,85,127,2,30,85,4,85,2  ; n4744 t=129.590s dur=113ms, freq=1109Hz, sample=85, buffer_id=02:55 [TRUNCATE prev:ch30 @128862.6ms -> 129589.9ms]
    db 0,0,113,0,90,127,2,31,117,5,90,2  ; n4745 t=129.590s dur=113ms, freq=1397Hz, sample=90, buffer_id=02:5A
    db 0,0,113,0,73,127,3,20,42,2,73,3  ; n4746 t=129.590s dur=113ms, freq=554Hz, sample=73, buffer_id=03:49 [TRUNCATE prev:ch20 @129135.3ms -> 129589.9ms]
    db 0,0,113,0,78,127,3,0,186,2,78,3  ; n4747 t=129.590s dur=113ms, freq=698Hz, sample=78, buffer_id=03:4E [TRUNCATE prev:ch0 @129314.9ms -> 129589.9ms]
    db 0,0,113,0,73,127,4,9,42,2,73,4  ; n4748 t=129.590s dur=113ms, freq=554Hz, sample=73, buffer_id=04:49 [TRUNCATE prev:ch9 @129317.2ms -> 129589.9ms]
    db 0,0,113,0,78,127,4,10,186,2,78,4  ; n4749 t=129.590s dur=113ms, freq=698Hz, sample=78, buffer_id=04:4E [TRUNCATE prev:ch10 @129317.2ms -> 129589.9ms]
    db 0,0,113,0,66,127,5,12,93,1,66,5  ; n4750 t=129.590s dur=113ms, freq=349Hz, sample=66, buffer_id=05:42 [TRUNCATE prev:ch12 @129317.2ms -> 129589.9ms]
    db 89,0,113,0,61,127,6,14,21,1,61,5  ; n4751 t=129.590s dur=113ms, freq=277Hz, sample=61, buffer_id=05:3D [TRUNCATE prev:ch14 @129317.2ms -> 129589.9ms]
    db 2,0,159,0,47,127,10,15,123,0,47,10  ; n4752 t=129.679s dur=159ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 0,0,181,0,86,127,2,17,151,4,86,2  ; n4753 t=129.681s dur=181ms, freq=1175Hz, sample=86, buffer_id=02:56
    db 0,0,181,0,90,127,2,25,200,5,90,2  ; n4754 t=129.681s dur=181ms, freq=1480Hz, sample=90, buffer_id=02:5A
    db 0,0,181,0,74,127,3,5,75,2,74,3  ; n4755 t=129.681s dur=181ms, freq=587Hz, sample=74, buffer_id=03:4A [TRUNCATE prev:ch5 @129499.0ms -> 129680.8ms]
    db 0,0,181,0,78,127,3,4,228,2,78,3  ; n4756 t=129.681s dur=181ms, freq=740Hz, sample=78, buffer_id=03:4E [TRUNCATE prev:ch4 @129499.0ms -> 129680.8ms]
    db 0,0,181,0,74,127,4,7,75,2,74,4  ; n4757 t=129.681s dur=181ms, freq=587Hz, sample=74, buffer_id=04:4A [TRUNCATE prev:ch7 @129499.0ms -> 129680.8ms]
    db 0,0,181,0,78,127,4,6,228,2,78,4  ; n4758 t=129.681s dur=181ms, freq=740Hz, sample=78, buffer_id=04:4E [TRUNCATE prev:ch6 @129499.0ms -> 129680.8ms]
    db 0,0,181,0,66,127,5,8,114,1,66,5  ; n4759 t=129.681s dur=181ms, freq=370Hz, sample=66, buffer_id=05:42 [TRUNCATE prev:ch8 @129499.0ms -> 129680.8ms]
    db 0,0,181,0,62,127,6,13,38,1,62,5  ; n4760 t=129.681s dur=181ms, freq=294Hz, sample=62, buffer_id=05:3E [TRUNCATE prev:ch13 @129499.0ms -> 129680.8ms]
    db 0,0,159,0,59,127,7,11,247,0,59,7  ; n4761 t=129.681s dur=159ms, freq=247Hz, sample=59, buffer_id=07:3B [TRUNCATE prev:ch11 @129499.0ms -> 129680.8ms]
    db 0,0,159,0,71,127,7,16,238,1,71,7  ; n4762 t=129.681s dur=159ms, freq=494Hz, sample=71, buffer_id=07:47 [TRUNCATE prev:ch16 @129499.0ms -> 129680.8ms]
    db 0,0,159,0,97,127,16,2,184,7,97,16  ; n4763 t=129.681s dur=159ms, freq=1976Hz, sample=97, buffer_id=10:61 [TRUNCATE prev:ch2 @129496.7ms -> 129680.8ms]
    db 0,0,159,0,85,127,17,1,220,3,85,16  ; n4764 t=129.681s dur=159ms, freq=988Hz, sample=85, buffer_id=10:55 [TRUNCATE prev:ch1 @129499.0ms -> 129680.8ms]
    db 0,0,159,0,73,127,18,3,238,1,73,18  ; n4765 t=129.681s dur=159ms, freq=494Hz, sample=73, buffer_id=12:49 [TRUNCATE prev:ch3 @129499.0ms -> 129680.8ms]
    db 0,0,159,0,42,127,19,29,92,0,42,19  ; n4766 t=129.681s dur=159ms, freq=92Hz, sample=42, buffer_id=13:2A [TRUNCATE prev:ch29 @129499.0ms -> 129680.8ms]
    db 179,0,159,0,30,127,20,28,46,0,30,20  ; n4767 t=129.681s dur=159ms, freq=46Hz, sample=30, buffer_id=14:1E [TRUNCATE prev:ch28 @129499.0ms -> 129680.8ms]
    db 2,0,159,0,47,127,10,18,123,0,47,10  ; n4768 t=129.860s dur=159ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 0,0,159,0,59,127,7,19,247,0,59,7  ; n4769 t=129.863s dur=159ms, freq=247Hz, sample=59, buffer_id=07:3B
    db 0,0,159,0,71,127,7,21,238,1,71,7  ; n4770 t=129.863s dur=159ms, freq=494Hz, sample=71, buffer_id=07:47
    db 0,0,100,0,47,127,12,22,123,0,47,11  ; n4771 t=129.863s dur=100ms, freq=123Hz, sample=47, buffer_id=0B:2F
    db 0,0,84,1,35,127,13,23,62,0,35,13  ; n4772 t=129.863s dur=340ms, freq=62Hz, sample=35, buffer_id=0D:23
    db 0,0,159,0,90,127,16,26,200,5,90,16  ; n4773 t=129.863s dur=159ms, freq=1480Hz, sample=90, buffer_id=10:5A
    db 0,0,159,0,78,127,17,24,228,2,78,16  ; n4774 t=129.863s dur=159ms, freq=740Hz, sample=78, buffer_id=10:4E
    db 0,0,159,0,66,127,18,27,114,1,66,18  ; n4775 t=129.863s dur=159ms, freq=370Hz, sample=66, buffer_id=12:42 [TRUNCATE prev:ch27 @129499.0ms -> 129862.6ms]
    db 0,0,159,0,47,127,19,0,123,0,47,19  ; n4776 t=129.863s dur=159ms, freq=123Hz, sample=47, buffer_id=13:2F [TRUNCATE prev:ch0 @129589.9ms -> 129862.6ms]
    db 180,0,159,0,35,127,20,9,62,0,35,20  ; n4777 t=129.863s dur=159ms, freq=62Hz, sample=35, buffer_id=14:23 [TRUNCATE prev:ch9 @129589.9ms -> 129862.6ms]
    db 2,0,159,0,47,127,10,1,123,0,47,10  ; n4778 t=130.042s dur=159ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 0,0,159,0,59,127,7,2,247,0,59,7  ; n4779 t=130.044s dur=159ms, freq=247Hz, sample=59, buffer_id=07:3B
    db 0,0,159,0,71,127,7,3,238,1,71,7  ; n4780 t=130.044s dur=159ms, freq=494Hz, sample=71, buffer_id=07:47
    db 0,0,159,0,86,127,16,10,151,4,86,16  ; n4781 t=130.044s dur=159ms, freq=1175Hz, sample=86, buffer_id=10:56
    db 0,0,159,0,74,127,17,11,75,2,74,16  ; n4782 t=130.044s dur=159ms, freq=587Hz, sample=74, buffer_id=10:4A
    db 0,0,159,0,66,127,18,12,38,1,66,18  ; n4783 t=130.044s dur=159ms, freq=294Hz, sample=66, buffer_id=12:42
    db 0,0,159,0,47,127,19,14,110,0,47,19  ; n4784 t=130.044s dur=159ms, freq=110Hz, sample=47, buffer_id=13:2F
    db 180,0,159,0,33,127,20,15,55,0,33,20  ; n4785 t=130.044s dur=159ms, freq=55Hz, sample=33, buffer_id=14:21
    db 2,0,159,0,47,127,10,0,123,0,47,10  ; n4786 t=130.224s dur=159ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 0,0,113,0,86,127,2,4,151,4,86,2  ; n4787 t=130.226s dur=113ms, freq=1175Hz, sample=86, buffer_id=02:56
    db 0,0,113,0,90,127,2,5,200,5,90,2  ; n4788 t=130.226s dur=113ms, freq=1480Hz, sample=90, buffer_id=02:5A
    db 0,0,113,0,74,127,3,6,75,2,74,3  ; n4789 t=130.226s dur=113ms, freq=587Hz, sample=74, buffer_id=03:4A
    db 0,0,113,0,78,127,3,7,228,2,78,3  ; n4790 t=130.226s dur=113ms, freq=740Hz, sample=78, buffer_id=03:4E
    db 0,0,113,0,74,127,4,8,75,2,74,4  ; n4791 t=130.226s dur=113ms, freq=587Hz, sample=74, buffer_id=04:4A
    db 0,0,113,0,78,127,4,9,228,2,78,4  ; n4792 t=130.226s dur=113ms, freq=740Hz, sample=78, buffer_id=04:4E
    db 0,0,113,0,66,127,5,13,114,1,66,5  ; n4793 t=130.226s dur=113ms, freq=370Hz, sample=66, buffer_id=05:42
    db 0,0,113,0,62,127,6,16,38,1,62,5  ; n4794 t=130.226s dur=113ms, freq=294Hz, sample=62, buffer_id=05:3E
    db 0,0,159,0,59,127,7,17,247,0,59,7  ; n4795 t=130.226s dur=159ms, freq=247Hz, sample=59, buffer_id=07:3B
    db 0,0,159,0,71,127,7,18,238,1,71,7  ; n4796 t=130.226s dur=159ms, freq=494Hz, sample=71, buffer_id=07:47
    db 0,0,100,0,66,127,9,19,114,1,66,9  ; n4797 t=130.226s dur=100ms, freq=370Hz, sample=66, buffer_id=09:42
    db 0,0,100,0,78,127,9,20,228,2,78,9  ; n4798 t=130.226s dur=100ms, freq=740Hz, sample=78, buffer_id=09:4E
    db 0,0,100,0,59,127,11,21,247,0,59,11  ; n4799 t=130.226s dur=100ms, freq=247Hz, sample=59, buffer_id=0B:3B
    db 0,0,100,0,62,127,11,22,38,1,62,11  ; n4800 t=130.226s dur=100ms, freq=294Hz, sample=62, buffer_id=0B:3E
    db 0,0,100,0,54,127,12,24,185,0,54,11  ; n4801 t=130.226s dur=100ms, freq=185Hz, sample=54, buffer_id=0B:36
    db 0,0,159,0,90,127,16,25,200,5,90,16  ; n4802 t=130.226s dur=159ms, freq=1480Hz, sample=90, buffer_id=10:5A
    db 0,0,159,0,78,127,17,26,228,2,78,16  ; n4803 t=130.226s dur=159ms, freq=740Hz, sample=78, buffer_id=10:4E
    db 0,0,159,0,66,127,18,28,114,1,66,18  ; n4804 t=130.226s dur=159ms, freq=370Hz, sample=66, buffer_id=12:42
    db 0,0,159,0,42,127,19,27,98,0,42,19  ; n4805 t=130.226s dur=159ms, freq=98Hz, sample=42, buffer_id=13:2A
    db 91,0,159,0,30,127,20,29,49,0,30,20  ; n4806 t=130.226s dur=159ms, freq=49Hz, sample=30, buffer_id=14:1E
    db 0,0,113,0,85,127,2,31,85,4,85,2  ; n4807 t=130.317s dur=113ms, freq=1109Hz, sample=85, buffer_id=02:55
    db 0,0,113,0,90,127,2,30,117,5,90,2  ; n4808 t=130.317s dur=113ms, freq=1397Hz, sample=90, buffer_id=02:5A
    db 0,0,113,0,73,127,3,23,42,2,73,3  ; n4809 t=130.317s dur=113ms, freq=554Hz, sample=73, buffer_id=03:49 [TRUNCATE prev:ch23 @129862.6ms -> 130317.2ms]
    db 0,0,113,0,78,127,3,1,186,2,78,3  ; n4810 t=130.317s dur=113ms, freq=698Hz, sample=78, buffer_id=03:4E [TRUNCATE prev:ch1 @130042.2ms -> 130317.2ms]
    db 0,0,113,0,73,127,4,2,42,2,73,4  ; n4811 t=130.317s dur=113ms, freq=554Hz, sample=73, buffer_id=04:49 [TRUNCATE prev:ch2 @130044.4ms -> 130317.2ms]
    db 0,0,113,0,78,127,4,3,186,2,78,4  ; n4812 t=130.317s dur=113ms, freq=698Hz, sample=78, buffer_id=04:4E [TRUNCATE prev:ch3 @130044.4ms -> 130317.2ms]
    db 0,0,113,0,66,127,5,10,93,1,66,5  ; n4813 t=130.317s dur=113ms, freq=349Hz, sample=66, buffer_id=05:42 [TRUNCATE prev:ch10 @130044.4ms -> 130317.2ms]
    db 89,0,113,0,61,127,6,11,21,1,61,5  ; n4814 t=130.317s dur=113ms, freq=277Hz, sample=61, buffer_id=05:3D [TRUNCATE prev:ch11 @130044.4ms -> 130317.2ms]
    db 2,0,159,0,47,127,10,12,123,0,47,10  ; n4815 t=130.406s dur=159ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 0,0,181,0,86,127,2,14,151,4,86,2  ; n4816 t=130.408s dur=181ms, freq=1175Hz, sample=86, buffer_id=02:56
    db 0,0,181,0,90,127,2,15,200,5,90,2  ; n4817 t=130.408s dur=181ms, freq=1480Hz, sample=90, buffer_id=02:5A
    db 0,0,181,0,74,127,3,6,75,2,74,3  ; n4818 t=130.408s dur=181ms, freq=587Hz, sample=74, buffer_id=03:4A [TRUNCATE prev:ch6 @130226.3ms -> 130408.1ms]
    db 0,0,181,0,78,127,3,7,228,2,78,3  ; n4819 t=130.408s dur=181ms, freq=740Hz, sample=78, buffer_id=03:4E [TRUNCATE prev:ch7 @130226.3ms -> 130408.1ms]
    db 0,0,181,0,74,127,4,8,75,2,74,4  ; n4820 t=130.408s dur=181ms, freq=587Hz, sample=74, buffer_id=04:4A [TRUNCATE prev:ch8 @130226.3ms -> 130408.1ms]
    db 0,0,181,0,78,127,4,9,228,2,78,4  ; n4821 t=130.408s dur=181ms, freq=740Hz, sample=78, buffer_id=04:4E [TRUNCATE prev:ch9 @130226.3ms -> 130408.1ms]
    db 0,0,181,0,66,127,5,13,114,1,66,5  ; n4822 t=130.408s dur=181ms, freq=370Hz, sample=66, buffer_id=05:42 [TRUNCATE prev:ch13 @130226.3ms -> 130408.1ms]
    db 0,0,181,0,62,127,6,16,38,1,62,5  ; n4823 t=130.408s dur=181ms, freq=294Hz, sample=62, buffer_id=05:3E [TRUNCATE prev:ch16 @130226.3ms -> 130408.1ms]
    db 0,0,159,0,59,127,7,17,247,0,59,7  ; n4824 t=130.408s dur=159ms, freq=247Hz, sample=59, buffer_id=07:3B [TRUNCATE prev:ch17 @130226.3ms -> 130408.1ms]
    db 0,0,159,0,71,127,7,18,238,1,71,7  ; n4825 t=130.408s dur=159ms, freq=494Hz, sample=71, buffer_id=07:47 [TRUNCATE prev:ch18 @130226.3ms -> 130408.1ms]
    db 0,0,159,0,97,127,16,0,184,7,97,16  ; n4826 t=130.408s dur=159ms, freq=1976Hz, sample=97, buffer_id=10:61 [TRUNCATE prev:ch0 @130224.0ms -> 130408.1ms]
    db 0,0,159,0,85,127,17,4,220,3,85,16  ; n4827 t=130.408s dur=159ms, freq=988Hz, sample=85, buffer_id=10:55 [TRUNCATE prev:ch4 @130226.3ms -> 130408.1ms]
    db 0,0,159,0,73,127,18,5,238,1,73,18  ; n4828 t=130.408s dur=159ms, freq=494Hz, sample=73, buffer_id=12:49 [TRUNCATE prev:ch5 @130226.3ms -> 130408.1ms]
    db 0,0,159,0,42,127,19,27,92,0,42,19  ; n4829 t=130.408s dur=159ms, freq=92Hz, sample=42, buffer_id=13:2A [TRUNCATE prev:ch27 @130226.3ms -> 130408.1ms]
    db 180,0,159,0,30,127,20,29,46,0,30,20  ; n4830 t=130.408s dur=159ms, freq=46Hz, sample=30, buffer_id=14:1E [TRUNCATE prev:ch29 @130226.3ms -> 130408.1ms]
    db 2,0,84,1,47,127,10,19,123,0,47,10  ; n4831 t=130.588s dur=340ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 0,0,192,2,59,127,7,20,247,0,59,7  ; n4832 t=130.590s dur=704ms, freq=247Hz, sample=59, buffer_id=07:3B
    db 0,0,100,0,47,127,12,21,123,0,47,11  ; n4833 t=130.590s dur=100ms, freq=123Hz, sample=47, buffer_id=0B:2F
    db 0,0,84,1,35,127,13,22,62,0,35,13  ; n4834 t=130.590s dur=340ms, freq=62Hz, sample=35, buffer_id=0D:23
    db 0,0,100,0,85,127,16,24,220,3,85,16  ; n4835 t=130.590s dur=100ms, freq=988Hz, sample=85, buffer_id=10:55
    db 0,0,100,0,70,127,17,25,238,1,70,16  ; n4836 t=130.590s dur=100ms, freq=494Hz, sample=70, buffer_id=10:46
    db 0,0,100,0,54,127,18,26,247,0,54,18  ; n4837 t=130.590s dur=100ms, freq=247Hz, sample=54, buffer_id=12:36
    db 0,0,159,0,47,127,19,28,123,0,47,19  ; n4838 t=130.590s dur=159ms, freq=123Hz, sample=47, buffer_id=13:2F
    db 91,0,159,0,35,127,20,1,62,0,35,20  ; n4839 t=130.590s dur=159ms, freq=62Hz, sample=35, buffer_id=14:23 [TRUNCATE prev:ch1 @130317.2ms -> 130589.9ms]
    db 0,0,100,0,85,127,16,2,220,3,85,16  ; n4840 t=130.681s dur=100ms, freq=988Hz, sample=85, buffer_id=10:55
    db 0,0,100,0,70,127,17,3,238,1,70,16  ; n4841 t=130.681s dur=100ms, freq=494Hz, sample=70, buffer_id=10:46
    db 91,0,100,0,54,127,18,10,247,0,54,18  ; n4842 t=130.681s dur=100ms, freq=247Hz, sample=54, buffer_id=12:36
    db 0,0,100,0,85,127,16,0,220,3,85,16  ; n4843 t=130.772s dur=100ms, freq=988Hz, sample=85, buffer_id=10:55
    db 0,0,100,0,70,127,17,4,238,1,70,16  ; n4844 t=130.772s dur=100ms, freq=494Hz, sample=70, buffer_id=10:46
    db 0,0,100,0,54,127,18,5,247,0,54,18  ; n4845 t=130.772s dur=100ms, freq=247Hz, sample=54, buffer_id=12:36
    db 0,0,159,0,47,127,19,11,110,0,47,19  ; n4846 t=130.772s dur=159ms, freq=110Hz, sample=47, buffer_id=13:2F
    db 91,0,159,0,33,127,20,12,55,0,33,20  ; n4847 t=130.772s dur=159ms, freq=55Hz, sample=33, buffer_id=14:21
    db 0,0,100,0,85,127,16,6,220,3,85,16  ; n4848 t=130.863s dur=100ms, freq=988Hz, sample=85, buffer_id=10:55
    db 0,0,100,0,70,127,17,7,238,1,70,16  ; n4849 t=130.863s dur=100ms, freq=494Hz, sample=70, buffer_id=10:46
    db 91,0,100,0,54,127,18,8,247,0,54,18  ; n4850 t=130.863s dur=100ms, freq=247Hz, sample=54, buffer_id=12:36
    db 0,0,113,0,86,127,2,1,151,4,86,2  ; n4851 t=130.953s dur=113ms, freq=1175Hz, sample=86, buffer_id=02:56
    db 0,0,113,0,90,127,2,9,200,5,90,2  ; n4852 t=130.953s dur=113ms, freq=1480Hz, sample=90, buffer_id=02:5A
    db 0,0,113,0,74,127,3,13,75,2,74,3  ; n4853 t=130.953s dur=113ms, freq=587Hz, sample=74, buffer_id=03:4A
    db 0,0,113,0,78,127,3,14,228,2,78,3  ; n4854 t=130.953s dur=113ms, freq=740Hz, sample=78, buffer_id=03:4E
    db 0,0,113,0,74,127,4,15,75,2,74,4  ; n4855 t=130.953s dur=113ms, freq=587Hz, sample=74, buffer_id=04:4A
    db 0,0,113,0,78,127,4,16,228,2,78,4  ; n4856 t=130.953s dur=113ms, freq=740Hz, sample=78, buffer_id=04:4E
    db 0,0,113,0,66,127,5,17,114,1,66,5  ; n4857 t=130.953s dur=113ms, freq=370Hz, sample=66, buffer_id=05:42
    db 0,0,113,0,62,127,6,18,38,1,62,5  ; n4858 t=130.953s dur=113ms, freq=294Hz, sample=62, buffer_id=05:3E
    db 0,0,100,0,66,127,9,21,114,1,66,9  ; n4859 t=130.953s dur=100ms, freq=370Hz, sample=66, buffer_id=09:42
    db 0,0,100,0,78,127,9,23,228,2,78,9  ; n4860 t=130.953s dur=100ms, freq=740Hz, sample=78, buffer_id=09:4E
    db 0,0,100,0,59,127,11,24,247,0,59,11  ; n4861 t=130.953s dur=100ms, freq=247Hz, sample=59, buffer_id=0B:3B
    db 0,0,100,0,62,127,11,25,38,1,62,11  ; n4862 t=130.953s dur=100ms, freq=294Hz, sample=62, buffer_id=0B:3E
    db 0,0,100,0,54,127,12,26,185,0,54,11  ; n4863 t=130.953s dur=100ms, freq=185Hz, sample=54, buffer_id=0B:36
    db 0,0,100,0,85,127,16,27,220,3,85,16  ; n4864 t=130.953s dur=100ms, freq=988Hz, sample=85, buffer_id=10:55
    db 0,0,100,0,70,127,17,28,238,1,70,16  ; n4865 t=130.953s dur=100ms, freq=494Hz, sample=70, buffer_id=10:46
    db 0,0,100,0,54,127,18,29,247,0,54,18  ; n4866 t=130.953s dur=100ms, freq=247Hz, sample=54, buffer_id=12:36
    db 0,0,159,0,42,127,19,30,98,0,42,19  ; n4867 t=130.953s dur=159ms, freq=98Hz, sample=42, buffer_id=13:2A
    db 91,0,159,0,30,127,20,31,49,0,30,20  ; n4868 t=130.953s dur=159ms, freq=49Hz, sample=30, buffer_id=14:1E
    db 0,0,113,0,85,127,2,2,85,4,85,2  ; n4869 t=131.044s dur=113ms, freq=1109Hz, sample=85, buffer_id=02:55
    db 0,0,113,0,90,127,2,3,117,5,90,2  ; n4870 t=131.044s dur=113ms, freq=1397Hz, sample=90, buffer_id=02:5A
    db 0,0,113,0,73,127,3,10,42,2,73,3  ; n4871 t=131.044s dur=113ms, freq=554Hz, sample=73, buffer_id=03:49
    db 0,0,113,0,78,127,3,19,186,2,78,3  ; n4872 t=131.044s dur=113ms, freq=698Hz, sample=78, buffer_id=03:4E [TRUNCATE prev:ch19 @130587.6ms -> 131044.4ms]
    db 0,0,113,0,73,127,4,20,42,2,73,4  ; n4873 t=131.044s dur=113ms, freq=554Hz, sample=73, buffer_id=04:49 [TRUNCATE prev:ch20 @130589.9ms -> 131044.4ms]
    db 0,0,113,0,78,127,4,22,186,2,78,4  ; n4874 t=131.044s dur=113ms, freq=698Hz, sample=78, buffer_id=04:4E [TRUNCATE prev:ch22 @130589.9ms -> 131044.4ms]
    db 0,0,113,0,66,127,5,0,93,1,66,5  ; n4875 t=131.044s dur=113ms, freq=349Hz, sample=66, buffer_id=05:42 [TRUNCATE prev:ch0 @130771.7ms -> 131044.4ms]
    db 0,0,113,0,61,127,6,4,21,1,61,5  ; n4876 t=131.044s dur=113ms, freq=277Hz, sample=61, buffer_id=05:3D [TRUNCATE prev:ch4 @130771.7ms -> 131044.4ms]
    db 0,0,100,0,85,127,16,6,220,3,85,16  ; n4877 t=131.044s dur=100ms, freq=988Hz, sample=85, buffer_id=10:55 [TRUNCATE prev:ch6 @130862.6ms -> 131044.4ms]
    db 0,0,100,0,70,127,17,7,238,1,70,16  ; n4878 t=131.044s dur=100ms, freq=494Hz, sample=70, buffer_id=10:46 [TRUNCATE prev:ch7 @130862.6ms -> 131044.4ms]
    db 91,0,100,0,54,127,18,5,247,0,54,18  ; n4879 t=131.044s dur=100ms, freq=247Hz, sample=54, buffer_id=12:36 [TRUNCATE prev:ch5 @130771.7ms -> 131044.4ms]
    db 0,0,181,0,86,127,2,11,151,4,86,2  ; n4880 t=131.135s dur=181ms, freq=1175Hz, sample=86, buffer_id=02:56
    db 0,0,181,0,90,127,2,12,200,5,90,2  ; n4881 t=131.135s dur=181ms, freq=1480Hz, sample=90, buffer_id=02:5A
    db 0,0,181,0,74,127,3,13,75,2,74,3  ; n4882 t=131.135s dur=181ms, freq=587Hz, sample=74, buffer_id=03:4A [TRUNCATE prev:ch13 @130953.5ms -> 131135.3ms]
    db 0,0,181,0,78,127,3,14,228,2,78,3  ; n4883 t=131.135s dur=181ms, freq=740Hz, sample=78, buffer_id=03:4E [TRUNCATE prev:ch14 @130953.5ms -> 131135.3ms]
    db 0,0,181,0,74,127,4,15,75,2,74,4  ; n4884 t=131.135s dur=181ms, freq=587Hz, sample=74, buffer_id=04:4A [TRUNCATE prev:ch15 @130953.5ms -> 131135.3ms]
    db 0,0,181,0,78,127,4,16,228,2,78,4  ; n4885 t=131.135s dur=181ms, freq=740Hz, sample=78, buffer_id=04:4E [TRUNCATE prev:ch16 @130953.5ms -> 131135.3ms]
    db 0,0,181,0,66,127,5,17,114,1,66,5  ; n4886 t=131.135s dur=181ms, freq=370Hz, sample=66, buffer_id=05:42 [TRUNCATE prev:ch17 @130953.5ms -> 131135.3ms]
    db 0,0,181,0,62,127,6,18,38,1,62,5  ; n4887 t=131.135s dur=181ms, freq=294Hz, sample=62, buffer_id=05:3E [TRUNCATE prev:ch18 @130953.5ms -> 131135.3ms]
    db 0,0,100,0,85,127,16,27,220,3,85,16  ; n4888 t=131.135s dur=100ms, freq=988Hz, sample=85, buffer_id=10:55 [TRUNCATE prev:ch27 @130953.5ms -> 131135.3ms]
    db 0,0,100,0,70,127,17,28,238,1,70,16  ; n4889 t=131.135s dur=100ms, freq=494Hz, sample=70, buffer_id=10:46 [TRUNCATE prev:ch28 @130953.5ms -> 131135.3ms]
    db 0,0,100,0,54,127,18,8,247,0,54,18  ; n4890 t=131.135s dur=100ms, freq=247Hz, sample=54, buffer_id=12:36 [TRUNCATE prev:ch8 @130862.6ms -> 131135.3ms]
    db 0,0,159,0,42,127,19,30,92,0,42,19  ; n4891 t=131.135s dur=159ms, freq=92Hz, sample=42, buffer_id=13:2A [TRUNCATE prev:ch30 @130953.5ms -> 131135.3ms]
    db 91,0,159,0,30,127,20,31,46,0,30,20  ; n4892 t=131.135s dur=159ms, freq=46Hz, sample=30, buffer_id=14:1E [TRUNCATE prev:ch31 @130953.5ms -> 131135.3ms]
    db 0,0,100,0,85,127,16,6,220,3,85,16  ; n4893 t=131.226s dur=100ms, freq=988Hz, sample=85, buffer_id=10:55 [TRUNCATE prev:ch6 @131044.4ms -> 131226.3ms]
    db 0,0,100,0,70,127,17,7,238,1,70,16  ; n4894 t=131.226s dur=100ms, freq=494Hz, sample=70, buffer_id=10:46 [TRUNCATE prev:ch7 @131044.4ms -> 131226.3ms]
    db 89,0,100,0,54,127,18,29,247,0,54,18  ; n4895 t=131.226s dur=100ms, freq=247Hz, sample=54, buffer_id=12:36 [TRUNCATE prev:ch29 @130953.5ms -> 131226.3ms]
    db 2,0,84,1,47,127,10,1,123,0,47,10  ; n4896 t=131.315s dur=340ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 0,0,84,1,35,127,13,9,62,0,35,13  ; n4897 t=131.317s dur=340ms, freq=62Hz, sample=35, buffer_id=0D:23
    db 0,0,84,1,47,127,19,21,123,0,47,19  ; n4898 t=131.317s dur=340ms, freq=123Hz, sample=47, buffer_id=13:2F
    db 108,1,84,1,35,127,20,23,62,0,35,20  ; n4899 t=131.317s dur=340ms, freq=62Hz, sample=35, buffer_id=14:23
    db 0,0,100,0,92,127,1,0,125,6,92,1  ; n4900 t=131.681s dur=100ms, freq=1661Hz, sample=92, buffer_id=01:5C
    db 0,0,113,0,86,127,2,2,151,4,86,2  ; n4901 t=131.681s dur=113ms, freq=1175Hz, sample=86, buffer_id=02:56
    db 0,0,113,0,90,127,2,4,117,5,90,2  ; n4902 t=131.681s dur=113ms, freq=1397Hz, sample=90, buffer_id=02:5A
    db 0,0,100,0,78,127,3,3,63,3,78,3  ; n4903 t=131.681s dur=100ms, freq=831Hz, sample=78, buffer_id=03:4E
    db 0,0,100,0,85,127,3,5,220,3,85,3  ; n4904 t=131.681s dur=100ms, freq=988Hz, sample=85, buffer_id=03:55
    db 0,0,113,0,74,127,4,6,75,2,74,4  ; n4905 t=131.681s dur=113ms, freq=587Hz, sample=74, buffer_id=04:4A
    db 0,0,113,0,78,127,4,7,186,2,78,4  ; n4906 t=131.681s dur=113ms, freq=698Hz, sample=78, buffer_id=04:4E
    db 0,0,113,0,66,127,5,8,93,1,66,5  ; n4907 t=131.681s dur=113ms, freq=349Hz, sample=66, buffer_id=05:42
    db 0,0,113,0,62,127,6,10,38,1,62,5  ; n4908 t=131.681s dur=113ms, freq=294Hz, sample=62, buffer_id=05:3E
    db 0,0,100,0,59,127,7,11,247,0,59,7  ; n4909 t=131.681s dur=100ms, freq=247Hz, sample=59, buffer_id=07:3B
    db 0,0,100,0,71,127,7,12,238,1,71,7  ; n4910 t=131.681s dur=100ms, freq=494Hz, sample=71, buffer_id=07:47
    db 0,0,100,0,62,127,8,13,38,1,62,7  ; n4911 t=131.681s dur=100ms, freq=294Hz, sample=62, buffer_id=07:3E
    db 0,0,100,0,68,127,8,14,159,1,68,7  ; n4912 t=131.681s dur=100ms, freq=415Hz, sample=68, buffer_id=07:44
    db 0,0,100,0,65,127,9,15,93,1,65,9  ; n4913 t=131.681s dur=100ms, freq=349Hz, sample=65, buffer_id=09:41
    db 0,0,100,0,78,127,9,16,186,2,78,9  ; n4914 t=131.681s dur=100ms, freq=698Hz, sample=78, buffer_id=09:4E
    db 0,0,100,0,53,127,11,17,175,0,53,11  ; n4915 t=131.681s dur=100ms, freq=175Hz, sample=53, buffer_id=0B:35
    db 0,0,100,0,54,127,11,18,208,0,54,11  ; n4916 t=131.681s dur=100ms, freq=208Hz, sample=54, buffer_id=0B:36
    db 0,0,100,0,50,127,12,19,147,0,50,11  ; n4917 t=131.681s dur=100ms, freq=147Hz, sample=50, buffer_id=0B:32
    db 0,0,100,0,97,127,16,20,184,7,97,16  ; n4918 t=131.681s dur=100ms, freq=1976Hz, sample=97, buffer_id=10:61
    db 0,0,100,0,78,127,17,22,63,3,78,16  ; n4919 t=131.681s dur=100ms, freq=831Hz, sample=78, buffer_id=10:4E
    db 46,0,100,0,66,127,18,24,159,1,66,18  ; n4920 t=131.681s dur=100ms, freq=415Hz, sample=66, buffer_id=12:42
    db 0,0,100,0,92,127,1,25,224,6,92,1  ; n4921 t=131.726s dur=100ms, freq=1760Hz, sample=92, buffer_id=01:5C
    db 0,0,100,0,78,127,17,26,112,3,78,16  ; n4922 t=131.726s dur=100ms, freq=880Hz, sample=78, buffer_id=10:4E
    db 45,0,100,0,66,127,18,27,184,1,66,18  ; n4923 t=131.726s dur=100ms, freq=440Hz, sample=66, buffer_id=12:42
    db 0,0,100,0,94,127,1,28,73,7,94,1  ; n4924 t=131.772s dur=100ms, freq=1865Hz, sample=94, buffer_id=01:5E
    db 0,0,113,0,85,127,2,29,85,4,85,2  ; n4925 t=131.772s dur=113ms, freq=1109Hz, sample=85, buffer_id=02:55
    db 0,0,113,0,86,127,2,30,39,5,86,2  ; n4926 t=131.772s dur=113ms, freq=1319Hz, sample=86, buffer_id=02:56
    db 0,0,113,0,73,127,4,31,42,2,73,4  ; n4927 t=131.772s dur=113ms, freq=554Hz, sample=73, buffer_id=04:49
    db 0,0,113,0,74,127,4,1,147,2,74,4  ; n4928 t=131.772s dur=113ms, freq=659Hz, sample=74, buffer_id=04:4A [TRUNCATE prev:ch1 @131314.9ms -> 131771.7ms]
    db 0,0,113,0,62,127,5,9,74,1,62,5  ; n4929 t=131.772s dur=113ms, freq=330Hz, sample=62, buffer_id=05:3E [TRUNCATE prev:ch9 @131317.2ms -> 131771.7ms]
    db 0,0,113,0,61,127,6,21,21,1,61,5  ; n4930 t=131.772s dur=113ms, freq=277Hz, sample=61, buffer_id=05:3D [TRUNCATE prev:ch21 @131317.2ms -> 131771.7ms]
    db 0,0,100,0,85,127,17,23,164,3,85,16  ; n4931 t=131.772s dur=100ms, freq=932Hz, sample=85, buffer_id=10:55 [TRUNCATE prev:ch23 @131317.2ms -> 131771.7ms]
    db 46,0,100,0,73,127,18,0,210,1,73,18  ; n4932 t=131.772s dur=100ms, freq=466Hz, sample=73, buffer_id=12:49 [TRUNCATE prev:ch0 @131680.8ms -> 131771.7ms]
    db 0,0,100,0,94,127,1,2,184,7,94,1  ; n4933 t=131.817s dur=100ms, freq=1976Hz, sample=94, buffer_id=01:5E [TRUNCATE prev:ch2 @131680.8ms -> 131817.2ms]
    db 0,0,100,0,85,127,17,3,220,3,85,16  ; n4934 t=131.817s dur=100ms, freq=988Hz, sample=85, buffer_id=10:55 [TRUNCATE prev:ch3 @131680.8ms -> 131817.2ms]
    db 45,0,100,0,73,127,18,4,238,1,73,18  ; n4935 t=131.817s dur=100ms, freq=494Hz, sample=73, buffer_id=12:49 [TRUNCATE prev:ch4 @131680.8ms -> 131817.2ms]
    db 0,0,181,0,86,127,2,5,151,4,86,2  ; n4936 t=131.863s dur=181ms, freq=1175Hz, sample=86, buffer_id=02:56 [TRUNCATE prev:ch5 @131680.8ms -> 131862.6ms]
    db 0,0,181,0,90,127,2,6,117,5,90,2  ; n4937 t=131.863s dur=181ms, freq=1397Hz, sample=90, buffer_id=02:5A [TRUNCATE prev:ch6 @131680.8ms -> 131862.6ms]
    db 0,0,181,0,74,127,4,7,75,2,74,4  ; n4938 t=131.863s dur=181ms, freq=587Hz, sample=74, buffer_id=04:4A [TRUNCATE prev:ch7 @131680.8ms -> 131862.6ms]
    db 0,0,181,0,78,127,4,8,186,2,78,4  ; n4939 t=131.863s dur=181ms, freq=698Hz, sample=78, buffer_id=04:4E [TRUNCATE prev:ch8 @131680.8ms -> 131862.6ms]
    db 0,0,181,0,66,127,5,10,93,1,66,5  ; n4940 t=131.863s dur=181ms, freq=349Hz, sample=66, buffer_id=05:42 [TRUNCATE prev:ch10 @131680.8ms -> 131862.6ms]
    db 139,3,181,0,62,127,6,11,38,1,62,5  ; n4941 t=131.863s dur=181ms, freq=294Hz, sample=62, buffer_id=05:3E [TRUNCATE prev:ch11 @131680.8ms -> 131862.6ms]
    db 2,0,84,1,47,127,10,0,123,0,47,10  ; n4942 t=132.769s dur=340ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 0,0,84,1,35,127,13,1,62,0,35,13  ; n4943 t=132.772s dur=340ms, freq=62Hz, sample=35, buffer_id=0D:23
    db 0,0,84,1,47,127,19,2,123,0,47,19  ; n4944 t=132.772s dur=340ms, freq=123Hz, sample=47, buffer_id=13:2F
    db 108,1,84,1,35,127,20,3,62,0,35,20  ; n4945 t=132.772s dur=340ms, freq=62Hz, sample=35, buffer_id=14:23
    db 0,0,100,0,92,127,1,4,125,6,92,1  ; n4946 t=133.135s dur=100ms, freq=1661Hz, sample=92, buffer_id=01:5C
    db 0,0,113,0,86,127,2,6,151,4,86,2  ; n4947 t=133.135s dur=113ms, freq=1175Hz, sample=86, buffer_id=02:56
    db 0,0,113,0,90,127,2,5,200,5,90,2  ; n4948 t=133.135s dur=113ms, freq=1480Hz, sample=90, buffer_id=02:5A
    db 0,0,100,0,78,127,3,7,228,2,78,3  ; n4949 t=133.135s dur=100ms, freq=740Hz, sample=78, buffer_id=03:4E
    db 0,0,100,0,85,127,3,8,220,3,85,3  ; n4950 t=133.135s dur=100ms, freq=988Hz, sample=85, buffer_id=03:55
    db 0,0,113,0,74,127,4,9,75,2,74,4  ; n4951 t=133.135s dur=113ms, freq=587Hz, sample=74, buffer_id=04:4A
    db 0,0,113,0,78,127,4,10,228,2,78,4  ; n4952 t=133.135s dur=113ms, freq=740Hz, sample=78, buffer_id=04:4E
    db 0,0,113,0,66,127,5,11,114,1,66,5  ; n4953 t=133.135s dur=113ms, freq=370Hz, sample=66, buffer_id=05:42
    db 0,0,113,0,62,127,6,12,38,1,62,5  ; n4954 t=133.135s dur=113ms, freq=294Hz, sample=62, buffer_id=05:3E
    db 0,0,100,0,62,127,7,14,38,1,62,7  ; n4955 t=133.135s dur=100ms, freq=294Hz, sample=62, buffer_id=07:3E
    db 0,0,100,0,71,127,7,13,238,1,71,7  ; n4956 t=133.135s dur=100ms, freq=494Hz, sample=71, buffer_id=07:47
    db 0,0,100,0,66,127,9,15,114,1,66,9  ; n4957 t=133.135s dur=100ms, freq=370Hz, sample=66, buffer_id=09:42
    db 0,0,100,0,78,127,9,17,228,2,78,9  ; n4958 t=133.135s dur=100ms, freq=740Hz, sample=78, buffer_id=09:4E
    db 0,0,100,0,54,127,11,16,185,0,54,11  ; n4959 t=133.135s dur=100ms, freq=185Hz, sample=54, buffer_id=0B:36
    db 0,0,100,0,59,127,11,18,247,0,59,11  ; n4960 t=133.135s dur=100ms, freq=247Hz, sample=59, buffer_id=0B:3B
    db 0,0,100,0,50,127,12,20,147,0,50,11  ; n4961 t=133.135s dur=100ms, freq=147Hz, sample=50, buffer_id=0B:32
    db 0,0,100,0,97,127,16,19,184,7,97,16  ; n4962 t=133.135s dur=100ms, freq=1976Hz, sample=97, buffer_id=10:61
    db 0,0,100,0,78,127,17,21,63,3,78,16  ; n4963 t=133.135s dur=100ms, freq=831Hz, sample=78, buffer_id=10:4E
    db 46,0,100,0,66,127,18,22,159,1,66,18  ; n4964 t=133.135s dur=100ms, freq=415Hz, sample=66, buffer_id=12:42
    db 0,0,100,0,92,127,1,23,224,6,92,1  ; n4965 t=133.181s dur=100ms, freq=1760Hz, sample=92, buffer_id=01:5C
    db 0,0,100,0,78,127,17,24,112,3,78,16  ; n4966 t=133.181s dur=100ms, freq=880Hz, sample=78, buffer_id=10:4E
    db 46,0,100,0,66,127,18,25,184,1,66,18  ; n4967 t=133.181s dur=100ms, freq=440Hz, sample=66, buffer_id=12:42
    db 0,0,100,0,94,127,1,26,73,7,94,1  ; n4968 t=133.226s dur=100ms, freq=1865Hz, sample=94, buffer_id=01:5E
    db 0,0,113,0,85,127,2,27,85,4,85,2  ; n4969 t=133.226s dur=113ms, freq=1109Hz, sample=85, buffer_id=02:55
    db 0,0,113,0,90,127,2,28,117,5,90,2  ; n4970 t=133.226s dur=113ms, freq=1397Hz, sample=90, buffer_id=02:5A
    db 0,0,113,0,73,127,4,29,42,2,73,4  ; n4971 t=133.226s dur=113ms, freq=554Hz, sample=73, buffer_id=04:49
    db 0,0,113,0,78,127,4,30,186,2,78,4  ; n4972 t=133.226s dur=113ms, freq=698Hz, sample=78, buffer_id=04:4E
    db 0,0,113,0,66,127,5,31,93,1,66,5  ; n4973 t=133.226s dur=113ms, freq=349Hz, sample=66, buffer_id=05:42
    db 0,0,113,0,61,127,6,0,21,1,61,5  ; n4974 t=133.226s dur=113ms, freq=277Hz, sample=61, buffer_id=05:3D [TRUNCATE prev:ch0 @132769.4ms -> 133226.3ms]
    db 0,0,100,0,85,127,17,1,164,3,85,16  ; n4975 t=133.226s dur=100ms, freq=932Hz, sample=85, buffer_id=10:55 [TRUNCATE prev:ch1 @132771.7ms -> 133226.3ms]
    db 45,0,100,0,73,127,18,2,210,1,73,18  ; n4976 t=133.226s dur=100ms, freq=466Hz, sample=73, buffer_id=12:49 [TRUNCATE prev:ch2 @132771.7ms -> 133226.3ms]
    db 0,0,100,0,94,127,1,3,184,7,94,1  ; n4977 t=133.272s dur=100ms, freq=1976Hz, sample=94, buffer_id=01:5E [TRUNCATE prev:ch3 @132771.7ms -> 133271.7ms]
    db 0,0,100,0,85,127,17,4,220,3,85,16  ; n4978 t=133.272s dur=100ms, freq=988Hz, sample=85, buffer_id=10:55 [TRUNCATE prev:ch4 @133135.3ms -> 133271.7ms]
    db 46,0,100,0,73,127,18,5,238,1,73,18  ; n4979 t=133.272s dur=100ms, freq=494Hz, sample=73, buffer_id=12:49 [TRUNCATE prev:ch5 @133135.3ms -> 133271.7ms]
    db 0,0,181,0,86,127,2,6,151,4,86,2  ; n4980 t=133.317s dur=181ms, freq=1175Hz, sample=86, buffer_id=02:56 [TRUNCATE prev:ch6 @133135.3ms -> 133317.2ms]
    db 0,0,181,0,90,127,2,7,200,5,90,2  ; n4981 t=133.317s dur=181ms, freq=1480Hz, sample=90, buffer_id=02:5A [TRUNCATE prev:ch7 @133135.3ms -> 133317.2ms]
    db 0,0,181,0,74,127,4,9,75,2,74,4  ; n4982 t=133.317s dur=181ms, freq=587Hz, sample=74, buffer_id=04:4A [TRUNCATE prev:ch9 @133135.3ms -> 133317.2ms]
    db 0,0,181,0,78,127,4,10,228,2,78,4  ; n4983 t=133.317s dur=181ms, freq=740Hz, sample=78, buffer_id=04:4E [TRUNCATE prev:ch10 @133135.3ms -> 133317.2ms]
    db 0,0,181,0,66,127,5,11,114,1,66,5  ; n4984 t=133.317s dur=181ms, freq=370Hz, sample=66, buffer_id=05:42 [TRUNCATE prev:ch11 @133135.3ms -> 133317.2ms]
    db 141,3,181,0,62,127,6,12,38,1,62,5  ; n4985 t=133.317s dur=181ms, freq=294Hz, sample=62, buffer_id=05:3E [TRUNCATE prev:ch12 @133135.3ms -> 133317.2ms]
    db 0,0,100,0,85,127,2,0,220,3,85,2  ; n4986 t=134.226s dur=100ms, freq=988Hz, sample=85, buffer_id=02:55
    db 0,0,100,0,59,127,3,1,247,0,59,3  ; n4987 t=134.226s dur=100ms, freq=247Hz, sample=59, buffer_id=03:3B
    db 0,0,100,0,71,127,3,2,238,1,71,3  ; n4988 t=134.226s dur=100ms, freq=494Hz, sample=71, buffer_id=03:47
    db 0,0,100,0,59,127,4,3,247,0,59,4  ; n4989 t=134.226s dur=100ms, freq=247Hz, sample=59, buffer_id=04:3B
    db 0,0,100,0,70,127,4,4,238,1,70,4  ; n4990 t=134.226s dur=100ms, freq=494Hz, sample=70, buffer_id=04:46
    db 0,0,168,1,54,127,5,5,196,0,54,5  ; n4991 t=134.226s dur=424ms, freq=196Hz, sample=54, buffer_id=05:36
    db 0,0,32,1,54,127,12,6,196,0,54,11  ; n4992 t=134.226s dur=288ms, freq=196Hz, sample=54, buffer_id=0B:36
    db 150,0,175,1,43,127,13,7,98,0,43,13  ; n4993 t=134.226s dur=431ms, freq=98Hz, sample=43, buffer_id=0D:2B
    db 0,0,100,0,85,127,2,8,85,4,85,2  ; n4994 t=134.376s dur=100ms, freq=1109Hz, sample=85, buffer_id=02:55
    db 0,0,100,0,62,127,3,9,21,1,62,3  ; n4995 t=134.376s dur=100ms, freq=277Hz, sample=62, buffer_id=03:3E
    db 0,0,100,0,73,127,3,10,42,2,73,3  ; n4996 t=134.376s dur=100ms, freq=554Hz, sample=73, buffer_id=03:49
    db 0,0,100,0,61,127,4,11,21,1,61,4  ; n4997 t=134.376s dur=100ms, freq=277Hz, sample=61, buffer_id=04:3D
    db 150,0,100,0,73,127,4,12,42,2,73,4  ; n4998 t=134.376s dur=100ms, freq=554Hz, sample=73, buffer_id=04:49
    db 0,0,100,0,86,127,2,13,151,4,86,2  ; n4999 t=134.526s dur=100ms, freq=1175Hz, sample=86, buffer_id=02:56
    db 0,0,100,0,62,127,3,14,38,1,62,3  ; n5000 t=134.526s dur=100ms, freq=294Hz, sample=62, buffer_id=03:3E
    db 0,0,100,0,74,127,3,15,75,2,74,3  ; n5001 t=134.526s dur=100ms, freq=587Hz, sample=74, buffer_id=03:4A
    db 0,0,100,0,62,127,4,16,38,1,62,4  ; n5002 t=134.526s dur=100ms, freq=294Hz, sample=62, buffer_id=04:3E
    db 0,0,100,0,74,127,4,17,75,2,74,4  ; n5003 t=134.526s dur=100ms, freq=587Hz, sample=74, buffer_id=04:4A
    db 0,0,100,0,59,127,7,18,247,0,59,7  ; n5004 t=134.526s dur=100ms, freq=247Hz, sample=59, buffer_id=07:3B
    db 0,0,100,0,62,127,7,19,38,1,62,7  ; n5005 t=134.526s dur=100ms, freq=294Hz, sample=62, buffer_id=07:3E
    db 0,0,100,0,66,127,9,20,136,1,66,9  ; n5006 t=134.526s dur=100ms, freq=392Hz, sample=66, buffer_id=09:42
    db 0,0,100,0,66,127,9,21,238,1,66,9  ; n5007 t=134.526s dur=100ms, freq=494Hz, sample=66, buffer_id=09:42
    db 0,0,100,0,50,127,11,22,147,0,50,11  ; n5008 t=134.526s dur=100ms, freq=147Hz, sample=50, buffer_id=0B:32
    db 150,0,100,0,54,127,11,23,196,0,54,11  ; n5009 t=134.526s dur=100ms, freq=196Hz, sample=54, buffer_id=0B:36
    db 0,0,100,0,86,127,2,0,39,5,86,2  ; n5010 t=134.676s dur=100ms, freq=1319Hz, sample=86, buffer_id=02:56
    db 0,0,100,0,62,127,3,1,74,1,62,3  ; n5011 t=134.676s dur=100ms, freq=330Hz, sample=62, buffer_id=03:3E
    db 0,0,100,0,74,127,3,2,147,2,74,3  ; n5012 t=134.676s dur=100ms, freq=659Hz, sample=74, buffer_id=03:4A
    db 0,0,100,0,62,127,4,3,74,1,62,4  ; n5013 t=134.676s dur=100ms, freq=330Hz, sample=62, buffer_id=04:3E
    db 150,0,100,0,74,127,4,4,147,2,74,4  ; n5014 t=134.676s dur=100ms, freq=659Hz, sample=74, buffer_id=04:4A
    db 0,0,100,0,90,127,2,6,200,5,90,2  ; n5015 t=134.826s dur=100ms, freq=1480Hz, sample=90, buffer_id=02:5A
    db 0,0,100,0,66,127,3,8,114,1,66,3  ; n5016 t=134.826s dur=100ms, freq=370Hz, sample=66, buffer_id=03:42
    db 0,0,100,0,78,127,3,9,228,2,78,3  ; n5017 t=134.826s dur=100ms, freq=740Hz, sample=78, buffer_id=03:4E
    db 0,0,100,0,66,127,4,10,114,1,66,4  ; n5018 t=134.826s dur=100ms, freq=370Hz, sample=66, buffer_id=04:42
    db 0,0,100,0,78,127,4,11,228,2,78,4  ; n5019 t=134.826s dur=100ms, freq=740Hz, sample=78, buffer_id=04:4E
    db 0,0,194,1,54,127,5,12,185,0,54,5  ; n5020 t=134.826s dur=450ms, freq=185Hz, sample=54, buffer_id=05:36
    db 0,0,50,1,54,127,12,13,185,0,54,11  ; n5021 t=134.826s dur=306ms, freq=185Hz, sample=54, buffer_id=0B:36
    db 150,0,175,1,42,127,13,14,92,0,42,13  ; n5022 t=134.826s dur=431ms, freq=92Hz, sample=42, buffer_id=0D:2A
    db 0,0,100,0,86,127,2,1,151,4,86,2  ; n5023 t=134.976s dur=100ms, freq=1175Hz, sample=86, buffer_id=02:56
    db 0,0,100,0,62,127,3,0,38,1,62,3  ; n5024 t=134.976s dur=100ms, freq=294Hz, sample=62, buffer_id=03:3E
    db 0,0,100,0,74,127,3,3,75,2,74,3  ; n5025 t=134.976s dur=100ms, freq=587Hz, sample=74, buffer_id=03:4A
    db 0,0,100,0,62,127,4,2,38,1,62,4  ; n5026 t=134.976s dur=100ms, freq=294Hz, sample=62, buffer_id=04:3E
    db 150,0,100,0,74,127,4,5,75,2,74,4  ; n5027 t=134.976s dur=100ms, freq=587Hz, sample=74, buffer_id=04:4A
    db 0,0,100,0,90,127,1,4,200,5,90,1  ; n5028 t=135.126s dur=100ms, freq=1480Hz, sample=90, buffer_id=01:5A
    db 0,0,100,0,90,127,2,7,200,5,90,2  ; n5029 t=135.126s dur=100ms, freq=1480Hz, sample=90, buffer_id=02:5A
    db 0,0,100,0,66,127,3,15,114,1,66,3  ; n5030 t=135.126s dur=100ms, freq=370Hz, sample=66, buffer_id=03:42
    db 0,0,100,0,78,127,3,16,228,2,78,3  ; n5031 t=135.126s dur=100ms, freq=740Hz, sample=78, buffer_id=03:4E
    db 0,0,100,0,66,127,4,17,114,1,66,4  ; n5032 t=135.126s dur=100ms, freq=370Hz, sample=66, buffer_id=04:42
    db 0,0,100,0,78,127,4,18,228,2,78,4  ; n5033 t=135.126s dur=100ms, freq=740Hz, sample=78, buffer_id=04:4E
    db 0,0,100,0,59,127,7,19,247,0,59,7  ; n5034 t=135.126s dur=100ms, freq=247Hz, sample=59, buffer_id=07:3B
    db 0,0,100,0,62,127,7,20,38,1,62,7  ; n5035 t=135.126s dur=100ms, freq=294Hz, sample=62, buffer_id=07:3E
    db 0,0,100,0,66,127,9,22,114,1,66,9  ; n5036 t=135.126s dur=100ms, freq=370Hz, sample=66, buffer_id=09:42
    db 0,0,100,0,66,127,9,23,238,1,66,9  ; n5037 t=135.126s dur=100ms, freq=494Hz, sample=66, buffer_id=09:42
    db 0,0,100,0,50,127,11,21,147,0,50,11  ; n5038 t=135.126s dur=100ms, freq=147Hz, sample=50, buffer_id=0B:32
    db 150,0,100,0,54,127,11,24,185,0,54,11  ; n5039 t=135.126s dur=100ms, freq=185Hz, sample=54, buffer_id=0B:36
    db 0,0,100,0,94,127,1,6,184,7,94,1  ; n5040 t=135.276s dur=100ms, freq=1976Hz, sample=94, buffer_id=01:5E
    db 0,0,100,0,71,127,3,8,238,1,71,3  ; n5041 t=135.276s dur=100ms, freq=494Hz, sample=71, buffer_id=03:47
    db 0,0,100,0,85,127,3,9,220,3,85,3  ; n5042 t=135.276s dur=100ms, freq=988Hz, sample=85, buffer_id=03:55
    db 0,0,100,0,70,127,4,10,238,1,70,4  ; n5043 t=135.276s dur=100ms, freq=494Hz, sample=70, buffer_id=04:46
    db 150,0,100,0,83,127,4,11,220,3,83,4  ; n5044 t=135.276s dur=100ms, freq=988Hz, sample=83, buffer_id=04:53
    db 0,0,100,0,94,127,1,0,73,7,94,1  ; n5045 t=135.426s dur=100ms, freq=1865Hz, sample=94, buffer_id=01:5E
    db 0,0,100,0,94,127,2,1,73,7,94,2  ; n5046 t=135.426s dur=100ms, freq=1865Hz, sample=94, buffer_id=02:5E
    db 0,0,100,0,71,127,3,2,210,1,71,3  ; n5047 t=135.426s dur=100ms, freq=466Hz, sample=71, buffer_id=03:47
    db 0,0,100,0,85,127,3,3,164,3,85,3  ; n5048 t=135.426s dur=100ms, freq=932Hz, sample=85, buffer_id=03:55
    db 0,0,100,0,70,127,4,5,210,1,70,4  ; n5049 t=135.426s dur=100ms, freq=466Hz, sample=70, buffer_id=04:46
    db 0,0,100,0,81,127,4,13,164,3,81,4  ; n5050 t=135.426s dur=100ms, freq=932Hz, sample=81, buffer_id=04:51
    db 0,0,194,1,42,127,5,25,92,0,42,5  ; n5051 t=135.426s dur=450ms, freq=92Hz, sample=42, buffer_id=05:2A
    db 0,0,175,1,42,127,12,26,92,0,42,11  ; n5052 t=135.426s dur=431ms, freq=92Hz, sample=42, buffer_id=0B:2A
    db 150,0,175,1,30,127,13,27,46,0,30,13  ; n5053 t=135.426s dur=431ms, freq=46Hz, sample=30, buffer_id=0D:1E
    db 0,0,100,0,90,127,1,6,200,5,90,1  ; n5054 t=135.576s dur=100ms, freq=1480Hz, sample=90, buffer_id=01:5A
    db 0,0,100,0,90,127,2,4,200,5,90,2  ; n5055 t=135.576s dur=100ms, freq=1480Hz, sample=90, buffer_id=02:5A
    db 0,0,100,0,66,127,3,7,114,1,66,3  ; n5056 t=135.576s dur=100ms, freq=370Hz, sample=66, buffer_id=03:42
    db 0,0,100,0,78,127,3,8,228,2,78,3  ; n5057 t=135.576s dur=100ms, freq=740Hz, sample=78, buffer_id=03:4E
    db 0,0,100,0,66,127,4,9,114,1,66,4  ; n5058 t=135.576s dur=100ms, freq=370Hz, sample=66, buffer_id=04:42
    db 150,0,100,0,78,127,4,10,228,2,78,4  ; n5059 t=135.576s dur=100ms, freq=740Hz, sample=78, buffer_id=04:4E
    db 0,0,100,0,94,127,1,1,73,7,94,1  ; n5060 t=135.726s dur=100ms, freq=1865Hz, sample=94, buffer_id=01:5E
    db 0,0,100,0,94,127,2,0,73,7,94,2  ; n5061 t=135.726s dur=100ms, freq=1865Hz, sample=94, buffer_id=02:5E
    db 0,0,100,0,71,127,3,3,210,1,71,3  ; n5062 t=135.726s dur=100ms, freq=466Hz, sample=71, buffer_id=03:47
    db 0,0,100,0,85,127,3,2,164,3,85,3  ; n5063 t=135.726s dur=100ms, freq=932Hz, sample=85, buffer_id=03:55
    db 0,0,100,0,70,127,4,11,210,1,70,4  ; n5064 t=135.726s dur=100ms, freq=466Hz, sample=70, buffer_id=04:46
    db 0,0,100,0,81,127,4,5,164,3,81,4  ; n5065 t=135.726s dur=100ms, freq=932Hz, sample=81, buffer_id=04:51
    db 0,0,100,0,58,127,7,12,233,0,58,7  ; n5066 t=135.726s dur=100ms, freq=233Hz, sample=58, buffer_id=07:3A
    db 0,0,100,0,61,127,7,13,21,1,61,7  ; n5067 t=135.726s dur=100ms, freq=277Hz, sample=61, buffer_id=07:3D
    db 0,0,100,0,66,127,9,14,114,1,66,9  ; n5068 t=135.726s dur=100ms, freq=370Hz, sample=66, buffer_id=09:42
    db 0,0,100,0,66,127,9,15,210,1,66,9  ; n5069 t=135.726s dur=100ms, freq=466Hz, sample=66, buffer_id=09:42
    db 0,0,100,0,49,127,11,16,139,0,49,11  ; n5070 t=135.726s dur=100ms, freq=139Hz, sample=49, buffer_id=0B:31
    db 150,0,100,0,54,127,11,17,185,0,54,11  ; n5071 t=135.726s dur=100ms, freq=185Hz, sample=54, buffer_id=0B:36
    db 0,0,100,0,97,127,1,4,169,8,97,1  ; n5072 t=135.876s dur=100ms, freq=2217Hz, sample=97, buffer_id=01:61
    db 0,0,100,0,73,127,3,6,42,2,73,3  ; n5073 t=135.876s dur=100ms, freq=554Hz, sample=73, buffer_id=03:49
    db 0,0,100,0,85,127,3,7,85,4,85,3  ; n5074 t=135.876s dur=100ms, freq=1109Hz, sample=85, buffer_id=03:55
    db 0,0,100,0,73,127,4,8,42,2,73,4  ; n5075 t=135.876s dur=100ms, freq=554Hz, sample=73, buffer_id=04:49
    db 150,0,100,0,85,127,4,9,85,4,85,4  ; n5076 t=135.876s dur=100ms, freq=1109Hz, sample=85, buffer_id=04:55
    db 0,0,100,0,94,127,1,10,184,7,94,1  ; n5077 t=136.026s dur=100ms, freq=1976Hz, sample=94, buffer_id=01:5E
    db 0,0,69,2,95,127,2,18,184,7,95,2  ; n5078 t=136.026s dur=581ms, freq=1976Hz, sample=95, buffer_id=02:5F
    db 0,0,69,2,71,127,3,19,238,1,71,3  ; n5079 t=136.026s dur=581ms, freq=494Hz, sample=71, buffer_id=03:47
    db 0,0,69,2,85,127,3,20,220,3,85,3  ; n5080 t=136.026s dur=581ms, freq=988Hz, sample=85, buffer_id=03:55
    db 0,0,69,2,70,127,4,21,238,1,70,4  ; n5081 t=136.026s dur=581ms, freq=494Hz, sample=70, buffer_id=04:46
    db 0,0,69,2,83,127,4,22,220,3,83,4  ; n5082 t=136.026s dur=581ms, freq=988Hz, sample=83, buffer_id=04:53
    db 0,0,194,1,47,127,5,23,123,0,47,5  ; n5083 t=136.026s dur=450ms, freq=123Hz, sample=47, buffer_id=05:2F
    db 0,0,175,1,47,127,12,24,123,0,47,11  ; n5084 t=136.026s dur=431ms, freq=123Hz, sample=47, buffer_id=0B:2F
    db 44,1,175,1,35,127,13,28,62,0,35,13  ; n5085 t=136.026s dur=431ms, freq=62Hz, sample=35, buffer_id=0D:23
    db 0,0,100,0,59,127,7,0,247,0,59,7  ; n5086 t=136.326s dur=100ms, freq=247Hz, sample=59, buffer_id=07:3B
    db 0,0,100,0,62,127,7,1,38,1,62,7  ; n5087 t=136.326s dur=100ms, freq=294Hz, sample=62, buffer_id=07:3E
    db 0,0,100,0,66,127,9,2,114,1,66,9  ; n5088 t=136.326s dur=100ms, freq=370Hz, sample=66, buffer_id=09:42
    db 0,0,100,0,66,127,9,3,238,1,66,9  ; n5089 t=136.326s dur=100ms, freq=494Hz, sample=66, buffer_id=09:42
    db 0,0,100,0,50,127,11,4,147,0,50,11  ; n5090 t=136.326s dur=100ms, freq=147Hz, sample=50, buffer_id=0B:32
    db 42,1,100,0,54,127,11,5,185,0,54,11  ; n5091 t=136.326s dur=100ms, freq=185Hz, sample=54, buffer_id=0B:36
    db 2,0,84,1,47,127,10,6,123,0,47,10  ; n5092 t=136.624s dur=340ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 0,0,84,1,35,127,13,0,62,0,35,13  ; n5093 t=136.626s dur=340ms, freq=62Hz, sample=35, buffer_id=0D:23
    db 0,0,84,1,47,127,19,1,123,0,47,19  ; n5094 t=136.626s dur=340ms, freq=123Hz, sample=47, buffer_id=13:2F
    db 108,1,84,1,35,127,20,2,62,0,35,20  ; n5095 t=136.626s dur=340ms, freq=62Hz, sample=35, buffer_id=14:23
    db 0,0,100,0,92,127,1,3,125,6,92,1  ; n5096 t=136.990s dur=100ms, freq=1661Hz, sample=92, buffer_id=01:5C
    db 0,0,113,0,86,127,2,4,151,4,86,2  ; n5097 t=136.990s dur=113ms, freq=1175Hz, sample=86, buffer_id=02:56
    db 0,0,113,0,90,127,2,5,117,5,90,2  ; n5098 t=136.990s dur=113ms, freq=1397Hz, sample=90, buffer_id=02:5A
    db 0,0,100,0,78,127,3,7,63,3,78,3  ; n5099 t=136.990s dur=100ms, freq=831Hz, sample=78, buffer_id=03:4E
    db 0,0,100,0,85,127,3,8,220,3,85,3  ; n5100 t=136.990s dur=100ms, freq=988Hz, sample=85, buffer_id=03:55
    db 0,0,113,0,74,127,4,9,75,2,74,4  ; n5101 t=136.990s dur=113ms, freq=587Hz, sample=74, buffer_id=04:4A
    db 0,0,113,0,78,127,4,10,186,2,78,4  ; n5102 t=136.990s dur=113ms, freq=698Hz, sample=78, buffer_id=04:4E
    db 0,0,113,0,66,127,5,11,93,1,66,5  ; n5103 t=136.990s dur=113ms, freq=349Hz, sample=66, buffer_id=05:42
    db 0,0,113,0,62,127,6,12,38,1,62,5  ; n5104 t=136.990s dur=113ms, freq=294Hz, sample=62, buffer_id=05:3E
    db 0,0,100,0,59,127,7,13,247,0,59,7  ; n5105 t=136.990s dur=100ms, freq=247Hz, sample=59, buffer_id=07:3B
    db 0,0,100,0,71,127,7,14,238,1,71,7  ; n5106 t=136.990s dur=100ms, freq=494Hz, sample=71, buffer_id=07:47
    db 0,0,100,0,62,127,8,15,38,1,62,7  ; n5107 t=136.990s dur=100ms, freq=294Hz, sample=62, buffer_id=07:3E
    db 0,0,100,0,68,127,8,16,159,1,68,7  ; n5108 t=136.990s dur=100ms, freq=415Hz, sample=68, buffer_id=07:44
    db 0,0,100,0,65,127,9,17,93,1,65,9  ; n5109 t=136.990s dur=100ms, freq=349Hz, sample=65, buffer_id=09:41
    db 0,0,100,0,78,127,9,18,186,2,78,9  ; n5110 t=136.990s dur=100ms, freq=698Hz, sample=78, buffer_id=09:4E
    db 0,0,100,0,53,127,11,19,175,0,53,11  ; n5111 t=136.990s dur=100ms, freq=175Hz, sample=53, buffer_id=0B:35
    db 0,0,100,0,54,127,11,20,208,0,54,11  ; n5112 t=136.990s dur=100ms, freq=208Hz, sample=54, buffer_id=0B:36
    db 0,0,100,0,50,127,12,21,147,0,50,11  ; n5113 t=136.990s dur=100ms, freq=147Hz, sample=50, buffer_id=0B:32
    db 0,0,100,0,97,127,16,22,184,7,97,16  ; n5114 t=136.990s dur=100ms, freq=1976Hz, sample=97, buffer_id=10:61
    db 0,0,100,0,78,127,17,23,63,3,78,16  ; n5115 t=136.990s dur=100ms, freq=831Hz, sample=78, buffer_id=10:4E
    db 45,0,100,0,66,127,18,24,159,1,66,18  ; n5116 t=136.990s dur=100ms, freq=415Hz, sample=66, buffer_id=12:42
    db 0,0,100,0,92,127,1,25,224,6,92,1  ; n5117 t=137.035s dur=100ms, freq=1760Hz, sample=92, buffer_id=01:5C
    db 0,0,100,0,78,127,17,26,112,3,78,16  ; n5118 t=137.035s dur=100ms, freq=880Hz, sample=78, buffer_id=10:4E
    db 46,0,100,0,66,127,18,27,184,1,66,18  ; n5119 t=137.035s dur=100ms, freq=440Hz, sample=66, buffer_id=12:42
    db 0,0,100,0,94,127,1,28,73,7,94,1  ; n5120 t=137.081s dur=100ms, freq=1865Hz, sample=94, buffer_id=01:5E
    db 0,0,113,0,85,127,2,29,85,4,85,2  ; n5121 t=137.081s dur=113ms, freq=1109Hz, sample=85, buffer_id=02:55
    db 0,0,113,0,86,127,2,30,39,5,86,2  ; n5122 t=137.081s dur=113ms, freq=1319Hz, sample=86, buffer_id=02:56
    db 0,0,113,0,73,127,4,31,42,2,73,4  ; n5123 t=137.081s dur=113ms, freq=554Hz, sample=73, buffer_id=04:49
    db 0,0,113,0,74,127,4,6,147,2,74,4  ; n5124 t=137.081s dur=113ms, freq=659Hz, sample=74, buffer_id=04:4A [TRUNCATE prev:ch6 @136624.4ms -> 137080.8ms]
    db 0,0,113,0,62,127,5,0,74,1,62,5  ; n5125 t=137.081s dur=113ms, freq=330Hz, sample=62, buffer_id=05:3E [TRUNCATE prev:ch0 @136626.2ms -> 137080.8ms]
    db 0,0,113,0,61,127,6,1,21,1,61,5  ; n5126 t=137.081s dur=113ms, freq=277Hz, sample=61, buffer_id=05:3D [TRUNCATE prev:ch1 @136626.2ms -> 137080.8ms]
    db 0,0,100,0,85,127,17,2,164,3,85,16  ; n5127 t=137.081s dur=100ms, freq=932Hz, sample=85, buffer_id=10:55 [TRUNCATE prev:ch2 @136626.2ms -> 137080.8ms]
    db 45,0,100,0,73,127,18,3,210,1,73,18  ; n5128 t=137.081s dur=100ms, freq=466Hz, sample=73, buffer_id=12:49 [TRUNCATE prev:ch3 @136989.9ms -> 137080.8ms]
    db 0,0,100,0,94,127,1,4,184,7,94,1  ; n5129 t=137.126s dur=100ms, freq=1976Hz, sample=94, buffer_id=01:5E [TRUNCATE prev:ch4 @136989.9ms -> 137126.2ms]
    db 0,0,100,0,85,127,17,5,220,3,85,16  ; n5130 t=137.126s dur=100ms, freq=988Hz, sample=85, buffer_id=10:55 [TRUNCATE prev:ch5 @136989.9ms -> 137126.2ms]
    db 45,0,100,0,73,127,18,7,238,1,73,18  ; n5131 t=137.126s dur=100ms, freq=494Hz, sample=73, buffer_id=12:49 [TRUNCATE prev:ch7 @136989.9ms -> 137126.2ms]
    db 0,0,181,0,86,127,2,8,151,4,86,2  ; n5132 t=137.172s dur=181ms, freq=1175Hz, sample=86, buffer_id=02:56 [TRUNCATE prev:ch8 @136989.9ms -> 137171.7ms]
    db 0,0,181,0,90,127,2,9,117,5,90,2  ; n5133 t=137.172s dur=181ms, freq=1397Hz, sample=90, buffer_id=02:5A [TRUNCATE prev:ch9 @136989.9ms -> 137171.7ms]
    db 0,0,181,0,74,127,4,10,75,2,74,4  ; n5134 t=137.172s dur=181ms, freq=587Hz, sample=74, buffer_id=04:4A [TRUNCATE prev:ch10 @136989.9ms -> 137171.7ms]
    db 0,0,181,0,78,127,4,11,186,2,78,4  ; n5135 t=137.172s dur=181ms, freq=698Hz, sample=78, buffer_id=04:4E [TRUNCATE prev:ch11 @136989.9ms -> 137171.7ms]
    db 0,0,181,0,66,127,5,12,93,1,66,5  ; n5136 t=137.172s dur=181ms, freq=349Hz, sample=66, buffer_id=05:42 [TRUNCATE prev:ch12 @136989.9ms -> 137171.7ms]
    db 139,3,181,0,62,127,6,13,38,1,62,5  ; n5137 t=137.172s dur=181ms, freq=294Hz, sample=62, buffer_id=05:3E [TRUNCATE prev:ch13 @136989.9ms -> 137171.7ms]
    db 2,0,84,1,47,127,10,0,123,0,47,10  ; n5138 t=138.078s dur=340ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 0,0,84,1,35,127,13,1,62,0,35,13  ; n5139 t=138.081s dur=340ms, freq=62Hz, sample=35, buffer_id=0D:23
    db 0,0,84,1,47,127,19,2,123,0,47,19  ; n5140 t=138.081s dur=340ms, freq=123Hz, sample=47, buffer_id=13:2F
    db 108,1,84,1,35,127,20,3,62,0,35,20  ; n5141 t=138.081s dur=340ms, freq=62Hz, sample=35, buffer_id=14:23
    db 0,0,100,0,92,127,1,4,125,6,92,1  ; n5142 t=138.444s dur=100ms, freq=1661Hz, sample=92, buffer_id=01:5C
    db 0,0,113,0,86,127,2,5,151,4,86,2  ; n5143 t=138.444s dur=113ms, freq=1175Hz, sample=86, buffer_id=02:56
    db 0,0,113,0,90,127,2,6,200,5,90,2  ; n5144 t=138.444s dur=113ms, freq=1480Hz, sample=90, buffer_id=02:5A
    db 0,0,100,0,78,127,3,7,228,2,78,3  ; n5145 t=138.444s dur=100ms, freq=740Hz, sample=78, buffer_id=03:4E
    db 0,0,100,0,85,127,3,8,220,3,85,3  ; n5146 t=138.444s dur=100ms, freq=988Hz, sample=85, buffer_id=03:55
    db 0,0,113,0,74,127,4,9,75,2,74,4  ; n5147 t=138.444s dur=113ms, freq=587Hz, sample=74, buffer_id=04:4A
    db 0,0,113,0,78,127,4,10,228,2,78,4  ; n5148 t=138.444s dur=113ms, freq=740Hz, sample=78, buffer_id=04:4E
    db 0,0,113,0,66,127,5,11,114,1,66,5  ; n5149 t=138.444s dur=113ms, freq=370Hz, sample=66, buffer_id=05:42
    db 0,0,113,0,62,127,6,12,38,1,62,5  ; n5150 t=138.444s dur=113ms, freq=294Hz, sample=62, buffer_id=05:3E
    db 0,0,100,0,62,127,7,13,38,1,62,7  ; n5151 t=138.444s dur=100ms, freq=294Hz, sample=62, buffer_id=07:3E
    db 0,0,100,0,71,127,7,15,238,1,71,7  ; n5152 t=138.444s dur=100ms, freq=494Hz, sample=71, buffer_id=07:47
    db 0,0,100,0,66,127,9,14,114,1,66,9  ; n5153 t=138.444s dur=100ms, freq=370Hz, sample=66, buffer_id=09:42
    db 0,0,100,0,78,127,9,16,228,2,78,9  ; n5154 t=138.444s dur=100ms, freq=740Hz, sample=78, buffer_id=09:4E
    db 0,0,100,0,54,127,11,17,185,0,54,11  ; n5155 t=138.444s dur=100ms, freq=185Hz, sample=54, buffer_id=0B:36
    db 0,0,100,0,59,127,11,18,247,0,59,11  ; n5156 t=138.444s dur=100ms, freq=247Hz, sample=59, buffer_id=0B:3B
    db 0,0,100,0,50,127,12,19,147,0,50,11  ; n5157 t=138.444s dur=100ms, freq=147Hz, sample=50, buffer_id=0B:32
    db 0,0,100,0,97,127,16,20,184,7,97,16  ; n5158 t=138.444s dur=100ms, freq=1976Hz, sample=97, buffer_id=10:61
    db 0,0,100,0,78,127,17,21,63,3,78,16  ; n5159 t=138.444s dur=100ms, freq=831Hz, sample=78, buffer_id=10:4E
    db 46,0,100,0,66,127,18,22,159,1,66,18  ; n5160 t=138.444s dur=100ms, freq=415Hz, sample=66, buffer_id=12:42
    db 0,0,100,0,92,127,1,23,224,6,92,1  ; n5161 t=138.490s dur=100ms, freq=1760Hz, sample=92, buffer_id=01:5C
    db 0,0,100,0,78,127,17,24,112,3,78,16  ; n5162 t=138.490s dur=100ms, freq=880Hz, sample=78, buffer_id=10:4E
    db 45,0,100,0,66,127,18,25,184,1,66,18  ; n5163 t=138.490s dur=100ms, freq=440Hz, sample=66, buffer_id=12:42
    db 0,0,100,0,94,127,1,26,73,7,94,1  ; n5164 t=138.535s dur=100ms, freq=1865Hz, sample=94, buffer_id=01:5E
    db 0,0,113,0,85,127,2,27,85,4,85,2  ; n5165 t=138.535s dur=113ms, freq=1109Hz, sample=85, buffer_id=02:55
    db 0,0,113,0,90,127,2,28,117,5,90,2  ; n5166 t=138.535s dur=113ms, freq=1397Hz, sample=90, buffer_id=02:5A
    db 0,0,113,0,73,127,4,29,42,2,73,4  ; n5167 t=138.535s dur=113ms, freq=554Hz, sample=73, buffer_id=04:49
    db 0,0,113,0,78,127,4,30,186,2,78,4  ; n5168 t=138.535s dur=113ms, freq=698Hz, sample=78, buffer_id=04:4E
    db 0,0,113,0,66,127,5,31,93,1,66,5  ; n5169 t=138.535s dur=113ms, freq=349Hz, sample=66, buffer_id=05:42
    db 0,0,113,0,61,127,6,0,21,1,61,5  ; n5170 t=138.535s dur=113ms, freq=277Hz, sample=61, buffer_id=05:3D [TRUNCATE prev:ch0 @138078.5ms -> 138535.3ms]
    db 0,0,100,0,85,127,17,1,164,3,85,16  ; n5171 t=138.535s dur=100ms, freq=932Hz, sample=85, buffer_id=10:55 [TRUNCATE prev:ch1 @138080.8ms -> 138535.3ms]
    db 46,0,100,0,73,127,18,2,210,1,73,18  ; n5172 t=138.535s dur=100ms, freq=466Hz, sample=73, buffer_id=12:49 [TRUNCATE prev:ch2 @138080.8ms -> 138535.3ms]
    db 0,0,100,0,94,127,1,3,184,7,94,1  ; n5173 t=138.581s dur=100ms, freq=1976Hz, sample=94, buffer_id=01:5E [TRUNCATE prev:ch3 @138080.8ms -> 138580.8ms]
    db 0,0,100,0,85,127,17,4,220,3,85,16  ; n5174 t=138.581s dur=100ms, freq=988Hz, sample=85, buffer_id=10:55 [TRUNCATE prev:ch4 @138444.4ms -> 138580.8ms]
    db 45,0,100,0,73,127,18,5,238,1,73,18  ; n5175 t=138.581s dur=100ms, freq=494Hz, sample=73, buffer_id=12:49 [TRUNCATE prev:ch5 @138444.4ms -> 138580.8ms]
    db 0,0,181,0,86,127,2,6,151,4,86,2  ; n5176 t=138.626s dur=181ms, freq=1175Hz, sample=86, buffer_id=02:56 [TRUNCATE prev:ch6 @138444.4ms -> 138626.2ms]
    db 0,0,181,0,90,127,2,7,200,5,90,2  ; n5177 t=138.626s dur=181ms, freq=1480Hz, sample=90, buffer_id=02:5A [TRUNCATE prev:ch7 @138444.4ms -> 138626.2ms]
    db 0,0,181,0,74,127,4,9,75,2,74,4  ; n5178 t=138.626s dur=181ms, freq=587Hz, sample=74, buffer_id=04:4A [TRUNCATE prev:ch9 @138444.4ms -> 138626.2ms]
    db 0,0,181,0,78,127,4,10,228,2,78,4  ; n5179 t=138.626s dur=181ms, freq=740Hz, sample=78, buffer_id=04:4E [TRUNCATE prev:ch10 @138444.4ms -> 138626.2ms]
    db 0,0,181,0,66,127,5,11,114,1,66,5  ; n5180 t=138.626s dur=181ms, freq=370Hz, sample=66, buffer_id=05:42 [TRUNCATE prev:ch11 @138444.4ms -> 138626.2ms]
    db 141,3,181,0,62,127,6,12,38,1,62,5  ; n5181 t=138.626s dur=181ms, freq=294Hz, sample=62, buffer_id=05:3E [TRUNCATE prev:ch12 @138444.4ms -> 138626.2ms]
    db 0,0,100,0,85,127,2,0,220,3,85,2  ; n5182 t=139.535s dur=100ms, freq=988Hz, sample=85, buffer_id=02:55
    db 0,0,100,0,59,127,3,1,247,0,59,3  ; n5183 t=139.535s dur=100ms, freq=247Hz, sample=59, buffer_id=03:3B
    db 0,0,100,0,71,127,3,2,238,1,71,3  ; n5184 t=139.535s dur=100ms, freq=494Hz, sample=71, buffer_id=03:47
    db 0,0,100,0,59,127,4,3,247,0,59,4  ; n5185 t=139.535s dur=100ms, freq=247Hz, sample=59, buffer_id=04:3B
    db 0,0,100,0,70,127,4,4,238,1,70,4  ; n5186 t=139.535s dur=100ms, freq=494Hz, sample=70, buffer_id=04:46
    db 0,0,168,1,54,127,5,5,196,0,54,5  ; n5187 t=139.535s dur=424ms, freq=196Hz, sample=54, buffer_id=05:36
    db 0,0,32,1,54,127,12,6,196,0,54,11  ; n5188 t=139.535s dur=288ms, freq=196Hz, sample=54, buffer_id=0B:36
    db 0,0,175,1,43,127,13,7,98,0,43,13  ; n5189 t=139.535s dur=431ms, freq=98Hz, sample=43, buffer_id=0D:2B
    db 0,0,131,0,85,127,16,8,220,3,85,16  ; n5190 t=139.535s dur=131ms, freq=988Hz, sample=85, buffer_id=10:55
    db 0,0,131,0,70,127,17,9,238,1,70,16  ; n5191 t=139.535s dur=131ms, freq=494Hz, sample=70, buffer_id=10:46
    db 0,0,131,0,54,127,18,10,247,0,54,18  ; n5192 t=139.535s dur=131ms, freq=247Hz, sample=54, buffer_id=12:36
    db 0,0,25,1,54,127,19,11,196,0,54,19  ; n5193 t=139.535s dur=281ms, freq=196Hz, sample=54, buffer_id=13:36
    db 150,0,25,1,42,127,20,12,98,0,42,20  ; n5194 t=139.535s dur=281ms, freq=98Hz, sample=42, buffer_id=14:2A
    db 0,0,100,0,85,127,2,13,85,4,85,2  ; n5195 t=139.685s dur=100ms, freq=1109Hz, sample=85, buffer_id=02:55
    db 0,0,100,0,62,127,3,14,21,1,62,3  ; n5196 t=139.685s dur=100ms, freq=277Hz, sample=62, buffer_id=03:3E
    db 0,0,100,0,73,127,3,15,42,2,73,3  ; n5197 t=139.685s dur=100ms, freq=554Hz, sample=73, buffer_id=03:49
    db 0,0,100,0,61,127,4,16,21,1,61,4  ; n5198 t=139.685s dur=100ms, freq=277Hz, sample=61, buffer_id=04:3D
    db 0,0,100,0,73,127,4,17,42,2,73,4  ; n5199 t=139.685s dur=100ms, freq=554Hz, sample=73, buffer_id=04:49
    db 0,0,131,0,85,127,16,18,85,4,85,16  ; n5200 t=139.685s dur=131ms, freq=1109Hz, sample=85, buffer_id=10:55
    db 0,0,131,0,73,127,17,19,42,2,73,16  ; n5201 t=139.685s dur=131ms, freq=554Hz, sample=73, buffer_id=10:49
    db 150,0,131,0,66,127,18,20,21,1,66,18  ; n5202 t=139.685s dur=131ms, freq=277Hz, sample=66, buffer_id=12:42
    db 0,0,100,0,86,127,2,21,151,4,86,2  ; n5203 t=139.835s dur=100ms, freq=1175Hz, sample=86, buffer_id=02:56
    db 0,0,100,0,62,127,3,22,38,1,62,3  ; n5204 t=139.835s dur=100ms, freq=294Hz, sample=62, buffer_id=03:3E
    db 0,0,100,0,74,127,3,23,75,2,74,3  ; n5205 t=139.835s dur=100ms, freq=587Hz, sample=74, buffer_id=03:4A
    db 0,0,100,0,62,127,4,24,38,1,62,4  ; n5206 t=139.835s dur=100ms, freq=294Hz, sample=62, buffer_id=04:3E
    db 0,0,100,0,74,127,4,25,75,2,74,4  ; n5207 t=139.835s dur=100ms, freq=587Hz, sample=74, buffer_id=04:4A
    db 0,0,100,0,59,127,7,26,247,0,59,7  ; n5208 t=139.835s dur=100ms, freq=247Hz, sample=59, buffer_id=07:3B
    db 0,0,100,0,62,127,7,27,38,1,62,7  ; n5209 t=139.835s dur=100ms, freq=294Hz, sample=62, buffer_id=07:3E
    db 0,0,100,0,66,127,9,28,136,1,66,9  ; n5210 t=139.835s dur=100ms, freq=392Hz, sample=66, buffer_id=09:42
    db 0,0,100,0,66,127,9,29,238,1,66,9  ; n5211 t=139.835s dur=100ms, freq=494Hz, sample=66, buffer_id=09:42
    db 0,0,100,0,50,127,11,30,147,0,50,11  ; n5212 t=139.835s dur=100ms, freq=147Hz, sample=50, buffer_id=0B:32
    db 0,0,100,0,54,127,11,31,196,0,54,11  ; n5213 t=139.835s dur=100ms, freq=196Hz, sample=54, buffer_id=0B:36
    db 0,0,131,0,86,127,16,0,151,4,86,16  ; n5214 t=139.835s dur=131ms, freq=1175Hz, sample=86, buffer_id=10:56 [TRUNCATE prev:ch0 @139535.3ms -> 139835.3ms]
    db 0,0,131,0,74,127,17,1,75,2,74,16  ; n5215 t=139.835s dur=131ms, freq=587Hz, sample=74, buffer_id=10:4A [TRUNCATE prev:ch1 @139535.3ms -> 139835.3ms]
    db 150,0,131,0,66,127,18,20,38,1,66,18  ; n5216 t=139.835s dur=131ms, freq=294Hz, sample=66, buffer_id=12:42 [TRUNCATE prev:ch20 @139685.3ms -> 139835.3ms]
    db 0,0,100,0,86,127,2,2,39,5,86,2  ; n5217 t=139.985s dur=100ms, freq=1319Hz, sample=86, buffer_id=02:56
    db 0,0,100,0,62,127,3,3,74,1,62,3  ; n5218 t=139.985s dur=100ms, freq=330Hz, sample=62, buffer_id=03:3E
    db 0,0,100,0,74,127,3,4,147,2,74,3  ; n5219 t=139.985s dur=100ms, freq=659Hz, sample=74, buffer_id=03:4A
    db 0,0,100,0,62,127,4,8,74,1,62,4  ; n5220 t=139.985s dur=100ms, freq=330Hz, sample=62, buffer_id=04:3E
    db 0,0,100,0,74,127,4,9,147,2,74,4  ; n5221 t=139.985s dur=100ms, freq=659Hz, sample=74, buffer_id=04:4A
    db 0,0,131,0,87,127,16,10,39,5,87,16  ; n5222 t=139.985s dur=131ms, freq=1319Hz, sample=87, buffer_id=10:57
    db 0,0,131,0,74,127,17,1,147,2,74,16  ; n5223 t=139.985s dur=131ms, freq=659Hz, sample=74, buffer_id=10:4A [TRUNCATE prev:ch1 @139835.3ms -> 139985.3ms]
    db 150,0,131,0,66,127,18,20,74,1,66,18  ; n5224 t=139.985s dur=131ms, freq=330Hz, sample=66, buffer_id=12:42 [TRUNCATE prev:ch20 @139835.3ms -> 139985.3ms]
    db 0,0,100,0,90,127,2,6,200,5,90,2  ; n5225 t=140.135s dur=100ms, freq=1480Hz, sample=90, buffer_id=02:5A
    db 0,0,100,0,66,127,3,11,114,1,66,3  ; n5226 t=140.135s dur=100ms, freq=370Hz, sample=66, buffer_id=03:42
    db 0,0,100,0,78,127,3,12,228,2,78,3  ; n5227 t=140.135s dur=100ms, freq=740Hz, sample=78, buffer_id=03:4E
    db 0,0,100,0,66,127,4,13,114,1,66,4  ; n5228 t=140.135s dur=100ms, freq=370Hz, sample=66, buffer_id=04:42
    db 0,0,100,0,78,127,4,14,228,2,78,4  ; n5229 t=140.135s dur=100ms, freq=740Hz, sample=78, buffer_id=04:4E
    db 0,0,194,1,54,127,5,15,185,0,54,5  ; n5230 t=140.135s dur=450ms, freq=185Hz, sample=54, buffer_id=05:36
    db 0,0,50,1,54,127,12,16,185,0,54,11  ; n5231 t=140.135s dur=306ms, freq=185Hz, sample=54, buffer_id=0B:36
    db 0,0,175,1,42,127,13,17,92,0,42,13  ; n5232 t=140.135s dur=431ms, freq=92Hz, sample=42, buffer_id=0D:2A
    db 0,0,131,0,90,127,16,18,200,5,90,16  ; n5233 t=140.135s dur=131ms, freq=1480Hz, sample=90, buffer_id=10:5A
    db 0,0,131,0,78,127,17,19,228,2,78,16  ; n5234 t=140.135s dur=131ms, freq=740Hz, sample=78, buffer_id=10:4E
    db 0,0,131,0,66,127,18,21,114,1,66,18  ; n5235 t=140.135s dur=131ms, freq=370Hz, sample=66, buffer_id=12:42
    db 0,0,25,1,54,127,19,22,185,0,54,19  ; n5236 t=140.135s dur=281ms, freq=185Hz, sample=54, buffer_id=13:36
    db 150,0,25,1,42,127,20,23,92,0,42,20  ; n5237 t=140.135s dur=281ms, freq=92Hz, sample=42, buffer_id=14:2A
    db 0,0,100,0,86,127,2,0,151,4,86,2  ; n5238 t=140.285s dur=100ms, freq=1175Hz, sample=86, buffer_id=02:56
    db 0,0,100,0,62,127,3,2,38,1,62,3  ; n5239 t=140.285s dur=100ms, freq=294Hz, sample=62, buffer_id=03:3E
    db 0,0,100,0,74,127,3,3,75,2,74,3  ; n5240 t=140.285s dur=100ms, freq=587Hz, sample=74, buffer_id=03:4A
    db 0,0,100,0,62,127,4,4,38,1,62,4  ; n5241 t=140.285s dur=100ms, freq=294Hz, sample=62, buffer_id=04:3E
    db 0,0,100,0,74,127,4,5,75,2,74,4  ; n5242 t=140.285s dur=100ms, freq=587Hz, sample=74, buffer_id=04:4A
    db 0,0,131,0,86,127,16,7,151,4,86,16  ; n5243 t=140.285s dur=131ms, freq=1175Hz, sample=86, buffer_id=10:56
    db 0,0,131,0,74,127,17,8,75,2,74,16  ; n5244 t=140.285s dur=131ms, freq=587Hz, sample=74, buffer_id=10:4A
    db 150,0,131,0,66,127,18,9,38,1,66,18  ; n5245 t=140.285s dur=131ms, freq=294Hz, sample=66, buffer_id=12:42
    db 0,0,100,0,90,127,1,1,200,5,90,1  ; n5246 t=140.435s dur=100ms, freq=1480Hz, sample=90, buffer_id=01:5A
    db 0,0,100,0,90,127,2,10,200,5,90,2  ; n5247 t=140.435s dur=100ms, freq=1480Hz, sample=90, buffer_id=02:5A
    db 0,0,100,0,66,127,3,6,114,1,66,3  ; n5248 t=140.435s dur=100ms, freq=370Hz, sample=66, buffer_id=03:42
    db 0,0,100,0,78,127,3,11,228,2,78,3  ; n5249 t=140.435s dur=100ms, freq=740Hz, sample=78, buffer_id=03:4E
    db 0,0,100,0,66,127,4,12,114,1,66,4  ; n5250 t=140.435s dur=100ms, freq=370Hz, sample=66, buffer_id=04:42
    db 0,0,100,0,78,127,4,13,228,2,78,4  ; n5251 t=140.435s dur=100ms, freq=740Hz, sample=78, buffer_id=04:4E
    db 0,0,100,0,59,127,7,14,247,0,59,7  ; n5252 t=140.435s dur=100ms, freq=247Hz, sample=59, buffer_id=07:3B
    db 0,0,100,0,62,127,7,20,38,1,62,7  ; n5253 t=140.435s dur=100ms, freq=294Hz, sample=62, buffer_id=07:3E
    db 0,0,100,0,66,127,9,24,114,1,66,9  ; n5254 t=140.435s dur=100ms, freq=370Hz, sample=66, buffer_id=09:42
    db 0,0,100,0,66,127,9,25,238,1,66,9  ; n5255 t=140.435s dur=100ms, freq=494Hz, sample=66, buffer_id=09:42
    db 0,0,100,0,50,127,11,26,147,0,50,11  ; n5256 t=140.435s dur=100ms, freq=147Hz, sample=50, buffer_id=0B:32
    db 0,0,100,0,54,127,11,27,185,0,54,11  ; n5257 t=140.435s dur=100ms, freq=185Hz, sample=54, buffer_id=0B:36
    db 0,0,131,0,90,127,16,28,200,5,90,16  ; n5258 t=140.435s dur=131ms, freq=1480Hz, sample=90, buffer_id=10:5A
    db 0,0,131,0,78,127,17,29,228,2,78,16  ; n5259 t=140.435s dur=131ms, freq=740Hz, sample=78, buffer_id=10:4E
    db 150,0,131,0,66,127,18,30,114,1,66,18  ; n5260 t=140.435s dur=131ms, freq=370Hz, sample=66, buffer_id=12:42
    db 0,0,100,0,94,127,1,18,184,7,94,1  ; n5261 t=140.585s dur=100ms, freq=1976Hz, sample=94, buffer_id=01:5E
    db 0,0,100,0,71,127,3,19,238,1,71,3  ; n5262 t=140.585s dur=100ms, freq=494Hz, sample=71, buffer_id=03:47
    db 0,0,100,0,85,127,3,21,220,3,85,3  ; n5263 t=140.585s dur=100ms, freq=988Hz, sample=85, buffer_id=03:55
    db 0,0,100,0,70,127,4,31,238,1,70,4  ; n5264 t=140.585s dur=100ms, freq=494Hz, sample=70, buffer_id=04:46
    db 0,0,100,0,83,127,4,15,220,3,83,4  ; n5265 t=140.585s dur=100ms, freq=988Hz, sample=83, buffer_id=04:53 [TRUNCATE prev:ch15 @140135.3ms -> 140585.3ms]
    db 0,0,131,0,97,127,16,16,184,7,97,16  ; n5266 t=140.585s dur=131ms, freq=1976Hz, sample=97, buffer_id=10:61 [TRUNCATE prev:ch16 @140135.3ms -> 140585.3ms]
    db 0,0,131,0,85,127,17,17,220,3,85,16  ; n5267 t=140.585s dur=131ms, freq=988Hz, sample=85, buffer_id=10:55 [TRUNCATE prev:ch17 @140135.3ms -> 140585.3ms]
    db 150,0,131,0,73,127,18,22,238,1,73,18  ; n5268 t=140.585s dur=131ms, freq=494Hz, sample=73, buffer_id=12:49 [TRUNCATE prev:ch22 @140135.3ms -> 140585.3ms]
    db 0,0,100,0,94,127,1,0,73,7,94,1  ; n5269 t=140.735s dur=100ms, freq=1865Hz, sample=94, buffer_id=01:5E
    db 0,0,100,0,94,127,2,2,73,7,94,2  ; n5270 t=140.735s dur=100ms, freq=1865Hz, sample=94, buffer_id=02:5E
    db 0,0,100,0,71,127,3,3,210,1,71,3  ; n5271 t=140.735s dur=100ms, freq=466Hz, sample=71, buffer_id=03:47
    db 0,0,100,0,85,127,3,4,164,3,85,3  ; n5272 t=140.735s dur=100ms, freq=932Hz, sample=85, buffer_id=03:55
    db 0,0,100,0,70,127,4,5,210,1,70,4  ; n5273 t=140.735s dur=100ms, freq=466Hz, sample=70, buffer_id=04:46
    db 0,0,100,0,81,127,4,7,164,3,81,4  ; n5274 t=140.735s dur=100ms, freq=932Hz, sample=81, buffer_id=04:51
    db 0,0,194,1,42,127,5,8,92,0,42,5  ; n5275 t=140.735s dur=450ms, freq=92Hz, sample=42, buffer_id=05:2A
    db 0,0,175,1,42,127,12,9,92,0,42,11  ; n5276 t=140.735s dur=431ms, freq=92Hz, sample=42, buffer_id=0B:2A
    db 0,0,175,1,30,127,13,23,46,0,30,13  ; n5277 t=140.735s dur=431ms, freq=46Hz, sample=30, buffer_id=0D:1E
    db 0,0,131,0,97,127,16,16,73,7,97,16  ; n5278 t=140.735s dur=131ms, freq=1865Hz, sample=97, buffer_id=10:61 [TRUNCATE prev:ch16 @140585.3ms -> 140735.3ms]
    db 0,0,131,0,85,127,17,17,164,3,85,16  ; n5279 t=140.735s dur=131ms, freq=932Hz, sample=85, buffer_id=10:55 [TRUNCATE prev:ch17 @140585.3ms -> 140735.3ms]
    db 0,0,131,0,73,127,18,22,210,1,73,18  ; n5280 t=140.735s dur=131ms, freq=466Hz, sample=73, buffer_id=12:49 [TRUNCATE prev:ch22 @140585.3ms -> 140735.3ms]
    db 0,0,25,1,42,127,19,1,92,0,42,19  ; n5281 t=140.735s dur=281ms, freq=92Hz, sample=42, buffer_id=13:2A [TRUNCATE prev:ch1 @140435.3ms -> 140735.3ms]
    db 150,0,25,1,30,127,20,6,46,0,30,20  ; n5282 t=140.735s dur=281ms, freq=46Hz, sample=30, buffer_id=14:1E [TRUNCATE prev:ch6 @140435.3ms -> 140735.3ms]
    db 0,0,100,0,90,127,1,10,200,5,90,1  ; n5283 t=140.885s dur=100ms, freq=1480Hz, sample=90, buffer_id=01:5A
    db 0,0,100,0,90,127,2,11,200,5,90,2  ; n5284 t=140.885s dur=100ms, freq=1480Hz, sample=90, buffer_id=02:5A
    db 0,0,100,0,66,127,3,12,114,1,66,3  ; n5285 t=140.885s dur=100ms, freq=370Hz, sample=66, buffer_id=03:42
    db 0,0,100,0,78,127,3,13,228,2,78,3  ; n5286 t=140.885s dur=100ms, freq=740Hz, sample=78, buffer_id=03:4E
    db 0,0,100,0,66,127,4,14,114,1,66,4  ; n5287 t=140.885s dur=100ms, freq=370Hz, sample=66, buffer_id=04:42
    db 0,0,100,0,78,127,4,15,228,2,78,4  ; n5288 t=140.885s dur=100ms, freq=740Hz, sample=78, buffer_id=04:4E
    db 0,0,131,0,90,127,16,18,200,5,90,16  ; n5289 t=140.885s dur=131ms, freq=1480Hz, sample=90, buffer_id=10:5A
    db 0,0,131,0,78,127,17,19,228,2,78,16  ; n5290 t=140.885s dur=131ms, freq=740Hz, sample=78, buffer_id=10:4E
    db 150,0,131,0,66,127,18,20,114,1,66,18  ; n5291 t=140.885s dur=131ms, freq=370Hz, sample=66, buffer_id=12:42
    db 0,0,100,0,94,127,1,2,73,7,94,1  ; n5292 t=141.035s dur=100ms, freq=1865Hz, sample=94, buffer_id=01:5E
    db 0,0,100,0,94,127,2,0,73,7,94,2  ; n5293 t=141.035s dur=100ms, freq=1865Hz, sample=94, buffer_id=02:5E
    db 0,0,100,0,71,127,3,4,210,1,71,3  ; n5294 t=141.035s dur=100ms, freq=466Hz, sample=71, buffer_id=03:47
    db 0,0,100,0,85,127,3,3,164,3,85,3  ; n5295 t=141.035s dur=100ms, freq=932Hz, sample=85, buffer_id=03:55
    db 0,0,100,0,70,127,4,7,210,1,70,4  ; n5296 t=141.035s dur=100ms, freq=466Hz, sample=70, buffer_id=04:46
    db 0,0,100,0,81,127,4,5,164,3,81,4  ; n5297 t=141.035s dur=100ms, freq=932Hz, sample=81, buffer_id=04:51
    db 0,0,100,0,58,127,7,21,233,0,58,7  ; n5298 t=141.035s dur=100ms, freq=233Hz, sample=58, buffer_id=07:3A
    db 0,0,100,0,62,127,7,24,74,1,62,7  ; n5299 t=141.035s dur=100ms, freq=330Hz, sample=62, buffer_id=07:3E
    db 0,0,100,0,66,127,9,26,114,1,66,9  ; n5300 t=141.035s dur=100ms, freq=370Hz, sample=66, buffer_id=09:42
    db 0,0,100,0,66,127,9,27,210,1,66,9  ; n5301 t=141.035s dur=100ms, freq=466Hz, sample=66, buffer_id=09:42
    db 0,0,100,0,49,127,11,25,139,0,49,11  ; n5302 t=141.035s dur=100ms, freq=139Hz, sample=49, buffer_id=0B:31
    db 0,0,100,0,54,127,11,28,185,0,54,11  ; n5303 t=141.035s dur=100ms, freq=185Hz, sample=54, buffer_id=0B:36
    db 0,0,131,0,97,127,16,29,73,7,97,16  ; n5304 t=141.035s dur=131ms, freq=1865Hz, sample=97, buffer_id=10:61
    db 0,0,131,0,85,127,17,30,164,3,85,16  ; n5305 t=141.035s dur=131ms, freq=932Hz, sample=85, buffer_id=10:55
    db 150,0,131,0,73,127,18,31,210,1,73,18  ; n5306 t=141.035s dur=131ms, freq=466Hz, sample=73, buffer_id=12:49
    db 0,0,100,0,97,127,1,10,169,8,97,1  ; n5307 t=141.185s dur=100ms, freq=2217Hz, sample=97, buffer_id=01:61
    db 0,0,100,0,73,127,3,11,42,2,73,3  ; n5308 t=141.185s dur=100ms, freq=554Hz, sample=73, buffer_id=03:49
    db 0,0,100,0,85,127,3,12,85,4,85,3  ; n5309 t=141.185s dur=100ms, freq=1109Hz, sample=85, buffer_id=03:55
    db 0,0,100,0,73,127,4,13,42,2,73,4  ; n5310 t=141.185s dur=100ms, freq=554Hz, sample=73, buffer_id=04:49
    db 0,0,100,0,85,127,4,14,85,4,85,4  ; n5311 t=141.185s dur=100ms, freq=1109Hz, sample=85, buffer_id=04:55
    db 0,0,131,0,97,127,16,15,169,8,97,16  ; n5312 t=141.185s dur=131ms, freq=2217Hz, sample=97, buffer_id=10:61
    db 0,0,131,0,85,127,17,16,85,4,85,16  ; n5313 t=141.185s dur=131ms, freq=1109Hz, sample=85, buffer_id=10:55
    db 150,0,131,0,73,127,18,17,42,2,73,18  ; n5314 t=141.185s dur=131ms, freq=554Hz, sample=73, buffer_id=12:49
    db 0,0,100,0,94,127,1,1,184,7,94,1  ; n5315 t=141.335s dur=100ms, freq=1976Hz, sample=94, buffer_id=01:5E
    db 0,0,69,2,95,127,2,6,184,7,95,2  ; n5316 t=141.335s dur=581ms, freq=1976Hz, sample=95, buffer_id=02:5F
    db 0,0,69,2,71,127,3,18,238,1,71,3  ; n5317 t=141.335s dur=581ms, freq=494Hz, sample=71, buffer_id=03:47
    db 0,0,69,2,85,127,3,19,220,3,85,3  ; n5318 t=141.335s dur=581ms, freq=988Hz, sample=85, buffer_id=03:55
    db 0,0,69,2,70,127,4,20,238,1,70,4  ; n5319 t=141.335s dur=581ms, freq=494Hz, sample=70, buffer_id=04:46
    db 0,0,69,2,83,127,4,22,220,3,83,4  ; n5320 t=141.335s dur=581ms, freq=988Hz, sample=83, buffer_id=04:53
    db 0,0,194,1,47,127,5,8,123,0,47,5  ; n5321 t=141.335s dur=450ms, freq=123Hz, sample=47, buffer_id=05:2F [TRUNCATE prev:ch8 @140735.3ms -> 141335.3ms]
    db 0,0,175,1,47,127,12,9,123,0,47,11  ; n5322 t=141.335s dur=431ms, freq=123Hz, sample=47, buffer_id=0B:2F [TRUNCATE prev:ch9 @140735.3ms -> 141335.3ms]
    db 0,0,175,1,35,127,13,23,62,0,35,13  ; n5323 t=141.335s dur=431ms, freq=62Hz, sample=35, buffer_id=0D:23 [TRUNCATE prev:ch23 @140735.3ms -> 141335.3ms]
    db 0,0,100,0,97,127,16,29,184,7,97,16  ; n5324 t=141.335s dur=100ms, freq=1976Hz, sample=97, buffer_id=10:61 [TRUNCATE prev:ch29 @141035.3ms -> 141335.3ms]
    db 0,0,100,0,85,127,17,30,220,3,85,16  ; n5325 t=141.335s dur=100ms, freq=988Hz, sample=85, buffer_id=10:55 [TRUNCATE prev:ch30 @141035.3ms -> 141335.3ms]
    db 0,0,100,0,73,127,18,31,238,1,73,18  ; n5326 t=141.335s dur=100ms, freq=494Hz, sample=73, buffer_id=12:49 [TRUNCATE prev:ch31 @141035.3ms -> 141335.3ms]
    db 0,0,25,1,47,127,19,0,123,0,47,19  ; n5327 t=141.335s dur=281ms, freq=123Hz, sample=47, buffer_id=13:2F [TRUNCATE prev:ch0 @141035.3ms -> 141335.3ms]
    db 75,0,25,1,35,127,20,2,62,0,35,20  ; n5328 t=141.335s dur=281ms, freq=62Hz, sample=35, buffer_id=14:23 [TRUNCATE prev:ch2 @141035.3ms -> 141335.3ms]
    db 0,0,100,0,97,127,16,3,184,7,97,16  ; n5329 t=141.410s dur=100ms, freq=1976Hz, sample=97, buffer_id=10:61
    db 0,0,100,0,85,127,17,4,220,3,85,16  ; n5330 t=141.410s dur=100ms, freq=988Hz, sample=85, buffer_id=10:55
    db 75,0,100,0,73,127,18,5,238,1,73,18  ; n5331 t=141.410s dur=100ms, freq=494Hz, sample=73, buffer_id=12:49
    db 0,0,100,0,97,127,16,7,184,7,97,16  ; n5332 t=141.485s dur=100ms, freq=1976Hz, sample=97, buffer_id=10:61
    db 0,0,100,0,85,127,17,21,220,3,85,16  ; n5333 t=141.485s dur=100ms, freq=988Hz, sample=85, buffer_id=10:55
    db 75,0,100,0,73,127,18,24,238,1,73,18  ; n5334 t=141.485s dur=100ms, freq=494Hz, sample=73, buffer_id=12:49
    db 0,0,100,0,97,127,16,10,184,7,97,16  ; n5335 t=141.560s dur=100ms, freq=1976Hz, sample=97, buffer_id=10:61
    db 0,0,100,0,85,127,17,11,220,3,85,16  ; n5336 t=141.560s dur=100ms, freq=988Hz, sample=85, buffer_id=10:55
    db 75,0,100,0,73,127,18,12,238,1,73,18  ; n5337 t=141.560s dur=100ms, freq=494Hz, sample=73, buffer_id=12:49
    db 0,0,100,0,59,127,7,1,247,0,59,7  ; n5338 t=141.635s dur=100ms, freq=247Hz, sample=59, buffer_id=07:3B
    db 0,0,100,0,62,127,7,13,38,1,62,7  ; n5339 t=141.635s dur=100ms, freq=294Hz, sample=62, buffer_id=07:3E
    db 0,0,100,0,66,127,9,14,114,1,66,9  ; n5340 t=141.635s dur=100ms, freq=370Hz, sample=66, buffer_id=09:42
    db 0,0,100,0,66,127,9,15,238,1,66,9  ; n5341 t=141.635s dur=100ms, freq=494Hz, sample=66, buffer_id=09:42
    db 0,0,100,0,50,127,11,16,147,0,50,11  ; n5342 t=141.635s dur=100ms, freq=147Hz, sample=50, buffer_id=0B:32
    db 0,0,100,0,54,127,11,17,185,0,54,11  ; n5343 t=141.635s dur=100ms, freq=185Hz, sample=54, buffer_id=0B:36
    db 0,0,100,0,97,127,16,25,184,7,97,16  ; n5344 t=141.635s dur=100ms, freq=1976Hz, sample=97, buffer_id=10:61
    db 0,0,100,0,85,127,17,26,220,3,85,16  ; n5345 t=141.635s dur=100ms, freq=988Hz, sample=85, buffer_id=10:55
    db 75,0,100,0,73,127,18,27,238,1,73,18  ; n5346 t=141.635s dur=100ms, freq=494Hz, sample=73, buffer_id=12:49
    db 0,0,100,0,97,127,16,28,184,7,97,16  ; n5347 t=141.710s dur=100ms, freq=1976Hz, sample=97, buffer_id=10:61
    db 0,0,100,0,85,127,17,29,220,3,85,16  ; n5348 t=141.710s dur=100ms, freq=988Hz, sample=85, buffer_id=10:55
    db 75,0,100,0,73,127,18,30,238,1,73,18  ; n5349 t=141.710s dur=100ms, freq=494Hz, sample=73, buffer_id=12:49
    db 0,0,100,0,97,127,16,4,184,7,97,16  ; n5350 t=141.785s dur=100ms, freq=1976Hz, sample=97, buffer_id=10:61
    db 0,0,100,0,85,127,17,3,220,3,85,16  ; n5351 t=141.785s dur=100ms, freq=988Hz, sample=85, buffer_id=10:55
    db 75,0,100,0,73,127,18,7,238,1,73,18  ; n5352 t=141.785s dur=100ms, freq=494Hz, sample=73, buffer_id=12:49
    db 0,0,100,0,97,127,16,0,184,7,97,16  ; n5353 t=141.860s dur=100ms, freq=1976Hz, sample=97, buffer_id=10:61
    db 0,0,100,0,85,127,17,2,220,3,85,16  ; n5354 t=141.860s dur=100ms, freq=988Hz, sample=85, buffer_id=10:55
    db 73,0,100,0,73,127,18,21,238,1,73,18  ; n5355 t=141.860s dur=100ms, freq=494Hz, sample=73, buffer_id=12:49
    db 2,0,84,1,47,127,10,5,123,0,47,10  ; n5356 t=141.934s dur=340ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 0,0,100,0,35,127,13,1,62,0,35,13  ; n5357 t=141.935s dur=100ms, freq=62Hz, sample=35, buffer_id=0D:23
    db 0,0,84,1,47,127,19,10,123,0,47,19  ; n5358 t=141.935s dur=340ms, freq=123Hz, sample=47, buffer_id=13:2F
    db 108,1,84,1,35,127,20,11,62,0,35,20  ; n5359 t=141.935s dur=340ms, freq=62Hz, sample=35, buffer_id=14:23
    db 0,0,100,0,92,127,1,0,125,6,92,1  ; n5360 t=142.299s dur=100ms, freq=1661Hz, sample=92, buffer_id=01:5C
    db 0,0,113,0,86,127,2,1,151,4,86,2  ; n5361 t=142.299s dur=113ms, freq=1175Hz, sample=86, buffer_id=02:56
    db 0,0,113,0,90,127,2,2,117,5,90,2  ; n5362 t=142.299s dur=113ms, freq=1397Hz, sample=90, buffer_id=02:5A
    db 0,0,100,0,78,127,3,3,63,3,78,3  ; n5363 t=142.299s dur=100ms, freq=831Hz, sample=78, buffer_id=03:4E
    db 0,0,100,0,85,127,3,4,220,3,85,3  ; n5364 t=142.299s dur=100ms, freq=988Hz, sample=85, buffer_id=03:55
    db 0,0,113,0,74,127,4,6,75,2,74,4  ; n5365 t=142.299s dur=113ms, freq=587Hz, sample=74, buffer_id=04:4A
    db 0,0,113,0,78,127,4,7,186,2,78,4  ; n5366 t=142.299s dur=113ms, freq=698Hz, sample=78, buffer_id=04:4E
    db 0,0,113,0,66,127,5,8,93,1,66,5  ; n5367 t=142.299s dur=113ms, freq=349Hz, sample=66, buffer_id=05:42
    db 0,0,113,0,62,127,6,9,38,1,62,5  ; n5368 t=142.299s dur=113ms, freq=294Hz, sample=62, buffer_id=05:3E
    db 0,0,100,0,59,127,7,12,247,0,59,7  ; n5369 t=142.299s dur=100ms, freq=247Hz, sample=59, buffer_id=07:3B
    db 0,0,100,0,71,127,7,13,238,1,71,7  ; n5370 t=142.299s dur=100ms, freq=494Hz, sample=71, buffer_id=07:47
    db 0,0,100,0,62,127,8,14,38,1,62,7  ; n5371 t=142.299s dur=100ms, freq=294Hz, sample=62, buffer_id=07:3E
    db 0,0,100,0,68,127,8,15,159,1,68,7  ; n5372 t=142.299s dur=100ms, freq=415Hz, sample=68, buffer_id=07:44
    db 0,0,100,0,65,127,9,16,93,1,65,9  ; n5373 t=142.299s dur=100ms, freq=349Hz, sample=65, buffer_id=09:41
    db 0,0,100,0,78,127,9,17,186,2,78,9  ; n5374 t=142.299s dur=100ms, freq=698Hz, sample=78, buffer_id=09:4E
    db 0,0,100,0,53,127,11,18,175,0,53,11  ; n5375 t=142.299s dur=100ms, freq=175Hz, sample=53, buffer_id=0B:35
    db 0,0,100,0,54,127,11,19,208,0,54,11  ; n5376 t=142.299s dur=100ms, freq=208Hz, sample=54, buffer_id=0B:36
    db 0,0,100,0,50,127,12,20,147,0,50,11  ; n5377 t=142.299s dur=100ms, freq=147Hz, sample=50, buffer_id=0B:32
    db 0,0,100,0,97,127,16,21,184,7,97,16  ; n5378 t=142.299s dur=100ms, freq=1976Hz, sample=97, buffer_id=10:61
    db 0,0,100,0,78,127,17,22,63,3,78,16  ; n5379 t=142.299s dur=100ms, freq=831Hz, sample=78, buffer_id=10:4E
    db 45,0,100,0,66,127,18,23,159,1,66,18  ; n5380 t=142.299s dur=100ms, freq=415Hz, sample=66, buffer_id=12:42
    db 0,0,100,0,92,127,1,24,224,6,92,1  ; n5381 t=142.344s dur=100ms, freq=1760Hz, sample=92, buffer_id=01:5C
    db 0,0,100,0,78,127,17,25,112,3,78,16  ; n5382 t=142.344s dur=100ms, freq=880Hz, sample=78, buffer_id=10:4E
    db 46,0,100,0,66,127,18,26,184,1,66,18  ; n5383 t=142.344s dur=100ms, freq=440Hz, sample=66, buffer_id=12:42
    db 0,0,100,0,94,127,1,27,73,7,94,1  ; n5384 t=142.390s dur=100ms, freq=1865Hz, sample=94, buffer_id=01:5E
    db 0,0,113,0,85,127,2,28,85,4,85,2  ; n5385 t=142.390s dur=113ms, freq=1109Hz, sample=85, buffer_id=02:55
    db 0,0,113,0,86,127,2,29,39,5,86,2  ; n5386 t=142.390s dur=113ms, freq=1319Hz, sample=86, buffer_id=02:56
    db 0,0,113,0,73,127,4,30,42,2,73,4  ; n5387 t=142.390s dur=113ms, freq=554Hz, sample=73, buffer_id=04:49
    db 0,0,113,0,74,127,4,31,147,2,74,4  ; n5388 t=142.390s dur=113ms, freq=659Hz, sample=74, buffer_id=04:4A
    db 0,0,113,0,62,127,5,5,74,1,62,5  ; n5389 t=142.390s dur=113ms, freq=330Hz, sample=62, buffer_id=05:3E [TRUNCATE prev:ch5 @141933.5ms -> 142389.9ms]
    db 0,0,113,0,61,127,6,10,21,1,61,5  ; n5390 t=142.390s dur=113ms, freq=277Hz, sample=61, buffer_id=05:3D [TRUNCATE prev:ch10 @141935.3ms -> 142389.9ms]
    db 0,0,100,0,85,127,17,11,164,3,85,16  ; n5391 t=142.390s dur=100ms, freq=932Hz, sample=85, buffer_id=10:55 [TRUNCATE prev:ch11 @141935.3ms -> 142389.9ms]
    db 45,0,100,0,73,127,18,0,210,1,73,18  ; n5392 t=142.390s dur=100ms, freq=466Hz, sample=73, buffer_id=12:49 [TRUNCATE prev:ch0 @142299.0ms -> 142389.9ms]
    db 0,0,100,0,94,127,1,1,184,7,94,1  ; n5393 t=142.435s dur=100ms, freq=1976Hz, sample=94, buffer_id=01:5E [TRUNCATE prev:ch1 @142299.0ms -> 142435.3ms]
    db 0,0,100,0,85,127,17,2,220,3,85,16  ; n5394 t=142.435s dur=100ms, freq=988Hz, sample=85, buffer_id=10:55 [TRUNCATE prev:ch2 @142299.0ms -> 142435.3ms]
    db 45,0,100,0,73,127,18,3,238,1,73,18  ; n5395 t=142.435s dur=100ms, freq=494Hz, sample=73, buffer_id=12:49 [TRUNCATE prev:ch3 @142299.0ms -> 142435.3ms]
    db 0,0,181,0,86,127,2,4,151,4,86,2  ; n5396 t=142.481s dur=181ms, freq=1175Hz, sample=86, buffer_id=02:56 [TRUNCATE prev:ch4 @142299.0ms -> 142480.8ms]
    db 0,0,181,0,90,127,2,6,117,5,90,2  ; n5397 t=142.481s dur=181ms, freq=1397Hz, sample=90, buffer_id=02:5A [TRUNCATE prev:ch6 @142299.0ms -> 142480.8ms]
    db 0,0,181,0,74,127,4,7,75,2,74,4  ; n5398 t=142.481s dur=181ms, freq=587Hz, sample=74, buffer_id=04:4A [TRUNCATE prev:ch7 @142299.0ms -> 142480.8ms]
    db 0,0,181,0,78,127,4,8,186,2,78,4  ; n5399 t=142.481s dur=181ms, freq=698Hz, sample=78, buffer_id=04:4E [TRUNCATE prev:ch8 @142299.0ms -> 142480.8ms]
    db 0,0,181,0,66,127,5,9,93,1,66,5  ; n5400 t=142.481s dur=181ms, freq=349Hz, sample=66, buffer_id=05:42 [TRUNCATE prev:ch9 @142299.0ms -> 142480.8ms]
    db 139,3,181,0,62,127,6,12,38,1,62,5  ; n5401 t=142.481s dur=181ms, freq=294Hz, sample=62, buffer_id=05:3E [TRUNCATE prev:ch12 @142299.0ms -> 142480.8ms]
    db 2,0,84,1,47,127,10,0,123,0,47,10  ; n5402 t=143.388s dur=340ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 0,0,100,0,35,127,13,1,62,0,35,13  ; n5403 t=143.390s dur=100ms, freq=62Hz, sample=35, buffer_id=0D:23
    db 0,0,84,1,47,127,19,2,123,0,47,19  ; n5404 t=143.390s dur=340ms, freq=123Hz, sample=47, buffer_id=13:2F
    db 108,1,84,1,35,127,20,3,62,0,35,20  ; n5405 t=143.390s dur=340ms, freq=62Hz, sample=35, buffer_id=14:23
    db 0,0,100,0,92,127,1,1,125,6,92,1  ; n5406 t=143.754s dur=100ms, freq=1661Hz, sample=92, buffer_id=01:5C
    db 0,0,113,0,86,127,2,5,151,4,86,2  ; n5407 t=143.754s dur=113ms, freq=1175Hz, sample=86, buffer_id=02:56
    db 0,0,113,0,90,127,2,4,117,5,90,2  ; n5408 t=143.754s dur=113ms, freq=1397Hz, sample=90, buffer_id=02:5A
    db 0,0,100,0,78,127,3,6,63,3,78,3  ; n5409 t=143.754s dur=100ms, freq=831Hz, sample=78, buffer_id=03:4E
    db 0,0,100,0,85,127,3,7,220,3,85,3  ; n5410 t=143.754s dur=100ms, freq=988Hz, sample=85, buffer_id=03:55
    db 0,0,113,0,74,127,4,8,75,2,74,4  ; n5411 t=143.754s dur=113ms, freq=587Hz, sample=74, buffer_id=04:4A
    db 0,0,113,0,78,127,4,9,186,2,78,4  ; n5412 t=143.754s dur=113ms, freq=698Hz, sample=78, buffer_id=04:4E
    db 0,0,113,0,66,127,5,10,93,1,66,5  ; n5413 t=143.754s dur=113ms, freq=349Hz, sample=66, buffer_id=05:42
    db 0,0,113,0,62,127,6,11,38,1,62,5  ; n5414 t=143.754s dur=113ms, freq=294Hz, sample=62, buffer_id=05:3E
    db 0,0,100,0,59,127,7,12,247,0,59,7  ; n5415 t=143.754s dur=100ms, freq=247Hz, sample=59, buffer_id=07:3B
    db 0,0,100,0,71,127,7,14,238,1,71,7  ; n5416 t=143.754s dur=100ms, freq=494Hz, sample=71, buffer_id=07:47
    db 0,0,100,0,62,127,8,13,38,1,62,7  ; n5417 t=143.754s dur=100ms, freq=294Hz, sample=62, buffer_id=07:3E
    db 0,0,100,0,68,127,8,16,159,1,68,7  ; n5418 t=143.754s dur=100ms, freq=415Hz, sample=68, buffer_id=07:44
    db 0,0,100,0,65,127,9,15,93,1,65,9  ; n5419 t=143.754s dur=100ms, freq=349Hz, sample=65, buffer_id=09:41
    db 0,0,100,0,78,127,9,18,186,2,78,9  ; n5420 t=143.754s dur=100ms, freq=698Hz, sample=78, buffer_id=09:4E
    db 0,0,100,0,53,127,11,17,175,0,53,11  ; n5421 t=143.754s dur=100ms, freq=175Hz, sample=53, buffer_id=0B:35
    db 0,0,100,0,54,127,11,20,208,0,54,11  ; n5422 t=143.754s dur=100ms, freq=208Hz, sample=54, buffer_id=0B:36
    db 0,0,100,0,50,127,12,19,147,0,50,11  ; n5423 t=143.754s dur=100ms, freq=147Hz, sample=50, buffer_id=0B:32
    db 0,0,100,0,97,127,16,22,184,7,97,16  ; n5424 t=143.754s dur=100ms, freq=1976Hz, sample=97, buffer_id=10:61
    db 0,0,100,0,78,127,17,21,63,3,78,16  ; n5425 t=143.754s dur=100ms, freq=831Hz, sample=78, buffer_id=10:4E
    db 46,0,100,0,66,127,18,24,159,1,66,18  ; n5426 t=143.754s dur=100ms, freq=415Hz, sample=66, buffer_id=12:42
    db 0,0,100,0,92,127,1,23,224,6,92,1  ; n5427 t=143.799s dur=100ms, freq=1760Hz, sample=92, buffer_id=01:5C
    db 0,0,100,0,78,127,17,26,112,3,78,16  ; n5428 t=143.799s dur=100ms, freq=880Hz, sample=78, buffer_id=10:4E
    db 45,0,100,0,66,127,18,25,184,1,66,18  ; n5429 t=143.799s dur=100ms, freq=440Hz, sample=66, buffer_id=12:42
    db 0,0,100,0,94,127,1,28,73,7,94,1  ; n5430 t=143.844s dur=100ms, freq=1865Hz, sample=94, buffer_id=01:5E
    db 0,0,113,0,85,127,2,27,85,4,85,2  ; n5431 t=143.844s dur=113ms, freq=1109Hz, sample=85, buffer_id=02:55
    db 0,0,113,0,86,127,2,30,39,5,86,2  ; n5432 t=143.844s dur=113ms, freq=1319Hz, sample=86, buffer_id=02:56
    db 0,0,113,0,73,127,4,29,42,2,73,4  ; n5433 t=143.844s dur=113ms, freq=554Hz, sample=73, buffer_id=04:49
    db 0,0,113,0,74,127,4,31,147,2,74,4  ; n5434 t=143.844s dur=113ms, freq=659Hz, sample=74, buffer_id=04:4A [TRUNCATE prev:ch31 @142389.9ms -> 143844.4ms]
    db 0,0,113,0,62,127,5,0,74,1,62,5  ; n5435 t=143.844s dur=113ms, freq=330Hz, sample=62, buffer_id=05:3E [TRUNCATE prev:ch0 @143387.6ms -> 143844.4ms]
    db 0,0,113,0,61,127,6,2,21,1,61,5  ; n5436 t=143.844s dur=113ms, freq=277Hz, sample=61, buffer_id=05:3D [TRUNCATE prev:ch2 @143389.9ms -> 143844.4ms]
    db 0,0,100,0,85,127,17,3,164,3,85,16  ; n5437 t=143.844s dur=100ms, freq=932Hz, sample=85, buffer_id=10:55 [TRUNCATE prev:ch3 @143389.9ms -> 143844.4ms]
    db 46,0,100,0,73,127,18,1,210,1,73,18  ; n5438 t=143.844s dur=100ms, freq=466Hz, sample=73, buffer_id=12:49 [TRUNCATE prev:ch1 @143753.5ms -> 143844.4ms]
    db 0,0,100,0,94,127,1,4,184,7,94,1  ; n5439 t=143.890s dur=100ms, freq=1976Hz, sample=94, buffer_id=01:5E [TRUNCATE prev:ch4 @143753.5ms -> 143889.9ms]
    db 0,0,100,0,85,127,17,5,220,3,85,16  ; n5440 t=143.890s dur=100ms, freq=988Hz, sample=85, buffer_id=10:55 [TRUNCATE prev:ch5 @143753.5ms -> 143889.9ms]
    db 45,0,100,0,73,127,18,6,238,1,73,18  ; n5441 t=143.890s dur=100ms, freq=494Hz, sample=73, buffer_id=12:49 [TRUNCATE prev:ch6 @143753.5ms -> 143889.9ms]
    db 0,0,181,0,86,127,2,7,151,4,86,2  ; n5442 t=143.935s dur=181ms, freq=1175Hz, sample=86, buffer_id=02:56 [TRUNCATE prev:ch7 @143753.5ms -> 143935.3ms]
    db 0,0,181,0,90,127,2,8,117,5,90,2  ; n5443 t=143.935s dur=181ms, freq=1397Hz, sample=90, buffer_id=02:5A [TRUNCATE prev:ch8 @143753.5ms -> 143935.3ms]
    db 0,0,181,0,74,127,4,9,75,2,74,4  ; n5444 t=143.935s dur=181ms, freq=587Hz, sample=74, buffer_id=04:4A [TRUNCATE prev:ch9 @143753.5ms -> 143935.3ms]
    db 0,0,181,0,78,127,4,10,186,2,78,4  ; n5445 t=143.935s dur=181ms, freq=698Hz, sample=78, buffer_id=04:4E [TRUNCATE prev:ch10 @143753.5ms -> 143935.3ms]
    db 0,0,181,0,66,127,5,11,93,1,66,5  ; n5446 t=143.935s dur=181ms, freq=349Hz, sample=66, buffer_id=05:42 [TRUNCATE prev:ch11 @143753.5ms -> 143935.3ms]
    db 139,3,181,0,62,127,6,12,38,1,62,5  ; n5447 t=143.935s dur=181ms, freq=294Hz, sample=62, buffer_id=05:3E [TRUNCATE prev:ch12 @143753.5ms -> 143935.3ms]
    db 2,0,12,1,47,127,10,0,123,0,47,10  ; n5448 t=144.842s dur=268ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 0,0,100,0,35,127,13,1,62,0,35,13  ; n5449 t=144.844s dur=100ms, freq=62Hz, sample=35, buffer_id=0D:23
    db 0,0,11,1,47,127,19,2,123,0,47,19  ; n5450 t=144.844s dur=267ms, freq=123Hz, sample=47, buffer_id=13:2F
    db 30,1,11,1,35,127,20,3,62,0,35,20  ; n5451 t=144.844s dur=267ms, freq=62Hz, sample=35, buffer_id=14:23
    db 0,0,100,0,92,127,1,4,125,6,92,1  ; n5452 t=145.130s dur=100ms, freq=1661Hz, sample=92, buffer_id=01:5C
    db 0,0,100,0,86,127,2,5,151,4,86,2  ; n5453 t=145.130s dur=100ms, freq=1175Hz, sample=86, buffer_id=02:56
    db 0,0,100,0,90,127,2,6,117,5,90,2  ; n5454 t=145.130s dur=100ms, freq=1397Hz, sample=90, buffer_id=02:5A
    db 0,0,100,0,78,127,3,7,63,3,78,3  ; n5455 t=145.130s dur=100ms, freq=831Hz, sample=78, buffer_id=03:4E
    db 0,0,100,0,85,127,3,8,220,3,85,3  ; n5456 t=145.130s dur=100ms, freq=988Hz, sample=85, buffer_id=03:55
    db 0,0,100,0,74,127,4,10,75,2,74,4  ; n5457 t=145.130s dur=100ms, freq=587Hz, sample=74, buffer_id=04:4A
    db 0,0,100,0,78,127,4,9,186,2,78,4  ; n5458 t=145.130s dur=100ms, freq=698Hz, sample=78, buffer_id=04:4E
    db 0,0,100,0,66,127,5,12,93,1,66,5  ; n5459 t=145.130s dur=100ms, freq=349Hz, sample=66, buffer_id=05:42
    db 0,0,100,0,62,127,6,11,38,1,62,5  ; n5460 t=145.130s dur=100ms, freq=294Hz, sample=62, buffer_id=05:3E
    db 0,0,100,0,59,127,7,13,247,0,59,7  ; n5461 t=145.130s dur=100ms, freq=247Hz, sample=59, buffer_id=07:3B
    db 0,0,100,0,71,127,7,15,238,1,71,7  ; n5462 t=145.130s dur=100ms, freq=494Hz, sample=71, buffer_id=07:47
    db 0,0,100,0,62,127,8,14,38,1,62,7  ; n5463 t=145.130s dur=100ms, freq=294Hz, sample=62, buffer_id=07:3E
    db 0,0,100,0,68,127,8,17,159,1,68,7  ; n5464 t=145.130s dur=100ms, freq=415Hz, sample=68, buffer_id=07:44
    db 0,0,100,0,65,127,9,16,93,1,65,9  ; n5465 t=145.130s dur=100ms, freq=349Hz, sample=65, buffer_id=09:41
    db 0,0,100,0,78,127,9,19,186,2,78,9  ; n5466 t=145.130s dur=100ms, freq=698Hz, sample=78, buffer_id=09:4E
    db 0,0,100,0,53,127,11,18,175,0,53,11  ; n5467 t=145.130s dur=100ms, freq=175Hz, sample=53, buffer_id=0B:35
    db 0,0,100,0,54,127,11,21,208,0,54,11  ; n5468 t=145.130s dur=100ms, freq=208Hz, sample=54, buffer_id=0B:36
    db 0,0,100,0,50,127,12,20,147,0,50,11  ; n5469 t=145.130s dur=100ms, freq=147Hz, sample=50, buffer_id=0B:32
    db 0,0,214,0,97,127,16,23,184,7,97,16  ; n5470 t=145.130s dur=214ms, freq=1976Hz, sample=97, buffer_id=10:61
    db 0,0,100,0,78,127,17,22,63,3,78,16  ; n5471 t=145.130s dur=100ms, freq=831Hz, sample=78, buffer_id=10:4E
    db 36,0,100,0,66,127,18,26,159,1,66,18  ; n5472 t=145.130s dur=100ms, freq=415Hz, sample=66, buffer_id=12:42
    db 0,0,100,0,92,127,1,1,224,6,92,1  ; n5473 t=145.166s dur=100ms, freq=1760Hz, sample=92, buffer_id=01:5C
    db 0,0,100,0,78,127,17,24,112,3,78,16  ; n5474 t=145.166s dur=100ms, freq=880Hz, sample=78, buffer_id=10:4E
    db 36,0,100,0,66,127,18,27,184,1,66,18  ; n5475 t=145.166s dur=100ms, freq=440Hz, sample=66, buffer_id=12:42
    db 0,0,100,0,94,127,1,25,73,7,94,1  ; n5476 t=145.202s dur=100ms, freq=1865Hz, sample=94, buffer_id=01:5E
    db 0,0,100,0,85,127,2,28,85,4,85,2  ; n5477 t=145.202s dur=100ms, freq=1109Hz, sample=85, buffer_id=02:55
    db 0,0,100,0,86,127,2,29,39,5,86,2  ; n5478 t=145.202s dur=100ms, freq=1319Hz, sample=86, buffer_id=02:56
    db 0,0,100,0,73,127,4,30,42,2,73,4  ; n5479 t=145.202s dur=100ms, freq=554Hz, sample=73, buffer_id=04:49
    db 0,0,100,0,74,127,4,31,147,2,74,4  ; n5480 t=145.202s dur=100ms, freq=659Hz, sample=74, buffer_id=04:4A [TRUNCATE prev:ch31 @143844.4ms -> 145201.6ms]
    db 0,0,100,0,62,127,5,0,74,1,62,5  ; n5481 t=145.202s dur=100ms, freq=330Hz, sample=62, buffer_id=05:3E [TRUNCATE prev:ch0 @144842.1ms -> 145201.6ms]
    db 0,0,100,0,61,127,6,2,21,1,61,5  ; n5482 t=145.202s dur=100ms, freq=277Hz, sample=61, buffer_id=05:3D [TRUNCATE prev:ch2 @144844.4ms -> 145201.6ms]
    db 0,0,100,0,85,127,17,3,164,3,85,16  ; n5483 t=145.202s dur=100ms, freq=932Hz, sample=85, buffer_id=10:55 [TRUNCATE prev:ch3 @144844.4ms -> 145201.6ms]
    db 36,0,100,0,73,127,18,4,210,1,73,18  ; n5484 t=145.202s dur=100ms, freq=466Hz, sample=73, buffer_id=12:49 [TRUNCATE prev:ch4 @145130.1ms -> 145201.6ms]
    db 0,0,100,0,94,127,1,5,184,7,94,1  ; n5485 t=145.237s dur=100ms, freq=1976Hz, sample=94, buffer_id=01:5E [TRUNCATE prev:ch5 @145130.1ms -> 145237.3ms]
    db 0,0,100,0,85,127,17,6,220,3,85,16  ; n5486 t=145.237s dur=100ms, freq=988Hz, sample=85, buffer_id=10:55 [TRUNCATE prev:ch6 @145130.1ms -> 145237.3ms]
    db 36,0,100,0,73,127,18,7,238,1,73,18  ; n5487 t=145.237s dur=100ms, freq=494Hz, sample=73, buffer_id=12:49 [TRUNCATE prev:ch7 @145130.1ms -> 145237.3ms]
    db 0,0,125,0,86,127,2,8,151,4,86,2  ; n5488 t=145.273s dur=125ms, freq=1175Hz, sample=86, buffer_id=02:56 [TRUNCATE prev:ch8 @145130.1ms -> 145273.0ms]
    db 0,0,125,0,90,127,2,9,117,5,90,2  ; n5489 t=145.273s dur=125ms, freq=1397Hz, sample=90, buffer_id=02:5A [TRUNCATE prev:ch9 @145130.1ms -> 145273.0ms]
    db 0,0,125,0,74,127,4,10,75,2,74,4  ; n5490 t=145.273s dur=125ms, freq=587Hz, sample=74, buffer_id=04:4A [TRUNCATE prev:ch10 @145130.1ms -> 145273.0ms]
    db 0,0,125,0,78,127,4,11,186,2,78,4  ; n5491 t=145.273s dur=125ms, freq=698Hz, sample=78, buffer_id=04:4E [TRUNCATE prev:ch11 @145130.1ms -> 145273.0ms]
    db 0,0,125,0,66,127,5,12,93,1,66,5  ; n5492 t=145.273s dur=125ms, freq=349Hz, sample=66, buffer_id=05:42 [TRUNCATE prev:ch12 @145130.1ms -> 145273.0ms]
    db 143,0,125,0,62,127,6,13,38,1,62,5  ; n5493 t=145.273s dur=125ms, freq=294Hz, sample=62, buffer_id=05:3E [TRUNCATE prev:ch13 @145130.1ms -> 145273.0ms]
    db 0,0,100,0,92,127,1,1,125,6,92,1  ; n5494 t=145.416s dur=100ms, freq=1661Hz, sample=92, buffer_id=01:5C [TRUNCATE prev:ch1 @145165.8ms -> 145415.8ms]
    db 0,0,100,0,86,127,2,29,151,4,86,2  ; n5495 t=145.416s dur=100ms, freq=1175Hz, sample=86, buffer_id=02:56 [TRUNCATE prev:ch29 @145201.6ms -> 145415.8ms]
    db 0,0,100,0,90,127,2,9,117,5,90,2  ; n5496 t=145.416s dur=100ms, freq=1397Hz, sample=90, buffer_id=02:5A [TRUNCATE prev:ch9 @145273.0ms -> 145415.8ms]
    db 0,0,100,0,78,127,3,14,63,3,78,3  ; n5497 t=145.416s dur=100ms, freq=831Hz, sample=78, buffer_id=03:4E [TRUNCATE prev:ch14 @145130.1ms -> 145415.8ms]
    db 0,0,100,0,85,127,3,15,220,3,85,3  ; n5498 t=145.416s dur=100ms, freq=988Hz, sample=85, buffer_id=03:55 [TRUNCATE prev:ch15 @145130.1ms -> 145415.8ms]
    db 0,0,100,0,74,127,4,31,75,2,74,4  ; n5499 t=145.416s dur=100ms, freq=587Hz, sample=74, buffer_id=04:4A [TRUNCATE prev:ch31 @145201.6ms -> 145415.8ms]
    db 0,0,100,0,78,127,4,11,186,2,78,4  ; n5500 t=145.416s dur=100ms, freq=698Hz, sample=78, buffer_id=04:4E [TRUNCATE prev:ch11 @145273.0ms -> 145415.8ms]
    db 0,0,100,0,66,127,5,12,93,1,66,5  ; n5501 t=145.416s dur=100ms, freq=349Hz, sample=66, buffer_id=05:42 [TRUNCATE prev:ch12 @145273.0ms -> 145415.8ms]
    db 0,0,100,0,62,127,6,0,38,1,62,5  ; n5502 t=145.416s dur=100ms, freq=294Hz, sample=62, buffer_id=05:3E [TRUNCATE prev:ch0 @145201.6ms -> 145415.8ms]
    db 0,0,100,0,59,127,7,16,247,0,59,7  ; n5503 t=145.416s dur=100ms, freq=247Hz, sample=59, buffer_id=07:3B [TRUNCATE prev:ch16 @145130.1ms -> 145415.8ms]
    db 0,0,100,0,71,127,7,17,238,1,71,7  ; n5504 t=145.416s dur=100ms, freq=494Hz, sample=71, buffer_id=07:47 [TRUNCATE prev:ch17 @145130.1ms -> 145415.8ms]
    db 0,0,100,0,62,127,8,18,38,1,62,7  ; n5505 t=145.416s dur=100ms, freq=294Hz, sample=62, buffer_id=07:3E [TRUNCATE prev:ch18 @145130.1ms -> 145415.8ms]
    db 0,0,100,0,68,127,8,19,159,1,68,7  ; n5506 t=145.416s dur=100ms, freq=415Hz, sample=68, buffer_id=07:44 [TRUNCATE prev:ch19 @145130.1ms -> 145415.8ms]
    db 0,0,100,0,65,127,9,20,93,1,65,9  ; n5507 t=145.416s dur=100ms, freq=349Hz, sample=65, buffer_id=09:41 [TRUNCATE prev:ch20 @145130.1ms -> 145415.8ms]
    db 0,0,100,0,78,127,9,21,186,2,78,9  ; n5508 t=145.416s dur=100ms, freq=698Hz, sample=78, buffer_id=09:4E [TRUNCATE prev:ch21 @145130.1ms -> 145415.8ms]
    db 0,0,100,0,53,127,11,22,175,0,53,11  ; n5509 t=145.416s dur=100ms, freq=175Hz, sample=53, buffer_id=0B:35 [TRUNCATE prev:ch22 @145130.1ms -> 145415.8ms]
    db 0,0,100,0,54,127,11,23,208,0,54,11  ; n5510 t=145.416s dur=100ms, freq=208Hz, sample=54, buffer_id=0B:36 [TRUNCATE prev:ch23 @145130.1ms -> 145415.8ms]
    db 0,0,100,0,50,127,12,26,147,0,50,11  ; n5511 t=145.416s dur=100ms, freq=147Hz, sample=50, buffer_id=0B:32 [TRUNCATE prev:ch26 @145130.1ms -> 145415.8ms]
    db 0,0,214,0,97,127,16,24,184,7,97,16  ; n5512 t=145.416s dur=214ms, freq=1976Hz, sample=97, buffer_id=10:61 [TRUNCATE prev:ch24 @145165.8ms -> 145415.8ms]
    db 0,0,100,0,78,127,17,27,63,3,78,16  ; n5513 t=145.416s dur=100ms, freq=831Hz, sample=78, buffer_id=10:4E [TRUNCATE prev:ch27 @145165.8ms -> 145415.8ms]
    db 36,0,100,0,66,127,18,2,159,1,66,18  ; n5514 t=145.416s dur=100ms, freq=415Hz, sample=66, buffer_id=12:42 [TRUNCATE prev:ch2 @145201.6ms -> 145415.8ms]
    db 0,0,100,0,92,127,1,3,224,6,92,1  ; n5515 t=145.452s dur=100ms, freq=1760Hz, sample=92, buffer_id=01:5C [TRUNCATE prev:ch3 @145201.6ms -> 145451.6ms]
    db 0,0,100,0,78,127,17,4,112,3,78,16  ; n5516 t=145.452s dur=100ms, freq=880Hz, sample=78, buffer_id=10:4E [TRUNCATE prev:ch4 @145201.6ms -> 145451.6ms]
    db 36,0,100,0,66,127,18,25,184,1,66,18  ; n5517 t=145.452s dur=100ms, freq=440Hz, sample=66, buffer_id=12:42 [TRUNCATE prev:ch25 @145201.6ms -> 145451.6ms]
    db 0,0,100,0,94,127,1,5,73,7,94,1  ; n5518 t=145.487s dur=100ms, freq=1865Hz, sample=94, buffer_id=01:5E [TRUNCATE prev:ch5 @145237.3ms -> 145487.3ms]
    db 0,0,100,0,85,127,2,28,85,4,85,2  ; n5519 t=145.487s dur=100ms, freq=1109Hz, sample=85, buffer_id=02:55 [TRUNCATE prev:ch28 @145201.6ms -> 145487.3ms]
    db 0,0,100,0,86,127,2,8,39,5,86,2  ; n5520 t=145.487s dur=100ms, freq=1319Hz, sample=86, buffer_id=02:56 [TRUNCATE prev:ch8 @145273.0ms -> 145487.3ms]
    db 0,0,100,0,73,127,4,30,42,2,73,4  ; n5521 t=145.487s dur=100ms, freq=554Hz, sample=73, buffer_id=04:49 [TRUNCATE prev:ch30 @145201.6ms -> 145487.3ms]
    db 0,0,100,0,74,127,4,10,147,2,74,4  ; n5522 t=145.487s dur=100ms, freq=659Hz, sample=74, buffer_id=04:4A [TRUNCATE prev:ch10 @145273.0ms -> 145487.3ms]
    db 0,0,100,0,62,127,5,13,74,1,62,5  ; n5523 t=145.487s dur=100ms, freq=330Hz, sample=62, buffer_id=05:3E [TRUNCATE prev:ch13 @145273.0ms -> 145487.3ms]
    db 0,0,100,0,61,127,6,6,21,1,61,5  ; n5524 t=145.487s dur=100ms, freq=277Hz, sample=61, buffer_id=05:3D [TRUNCATE prev:ch6 @145237.3ms -> 145487.3ms]
    db 0,0,100,0,85,127,17,7,164,3,85,16  ; n5525 t=145.487s dur=100ms, freq=932Hz, sample=85, buffer_id=10:55 [TRUNCATE prev:ch7 @145237.3ms -> 145487.3ms]
    db 36,0,100,0,73,127,18,0,210,1,73,18  ; n5526 t=145.487s dur=100ms, freq=466Hz, sample=73, buffer_id=12:49 [TRUNCATE prev:ch0 @145415.8ms -> 145487.3ms]
    db 0,0,100,0,94,127,1,1,184,7,94,1  ; n5527 t=145.523s dur=100ms, freq=1976Hz, sample=94, buffer_id=01:5E [TRUNCATE prev:ch1 @145415.8ms -> 145523.0ms]
    db 0,0,100,0,85,127,17,2,220,3,85,16  ; n5528 t=145.523s dur=100ms, freq=988Hz, sample=85, buffer_id=10:55 [TRUNCATE prev:ch2 @145415.8ms -> 145523.0ms]
    db 36,0,100,0,73,127,18,9,238,1,73,18  ; n5529 t=145.523s dur=100ms, freq=494Hz, sample=73, buffer_id=12:49 [TRUNCATE prev:ch9 @145415.8ms -> 145523.0ms]
    db 0,0,125,0,86,127,2,29,151,4,86,2  ; n5530 t=145.559s dur=125ms, freq=1175Hz, sample=86, buffer_id=02:56 [TRUNCATE prev:ch29 @145415.8ms -> 145558.7ms]
    db 0,0,125,0,90,127,2,11,117,5,90,2  ; n5531 t=145.559s dur=125ms, freq=1397Hz, sample=90, buffer_id=02:5A [TRUNCATE prev:ch11 @145415.8ms -> 145558.7ms]
    db 0,0,125,0,74,127,4,31,75,2,74,4  ; n5532 t=145.559s dur=125ms, freq=587Hz, sample=74, buffer_id=04:4A [TRUNCATE prev:ch31 @145415.8ms -> 145558.7ms]
    db 0,0,125,0,78,127,4,12,186,2,78,4  ; n5533 t=145.559s dur=125ms, freq=698Hz, sample=78, buffer_id=04:4E [TRUNCATE prev:ch12 @145415.8ms -> 145558.7ms]
    db 0,0,125,0,66,127,5,14,93,1,66,5  ; n5534 t=145.559s dur=125ms, freq=349Hz, sample=66, buffer_id=05:42 [TRUNCATE prev:ch14 @145415.8ms -> 145558.7ms]
    db 143,0,125,0,62,127,6,15,38,1,62,5  ; n5535 t=145.559s dur=125ms, freq=294Hz, sample=62, buffer_id=05:3E [TRUNCATE prev:ch15 @145415.8ms -> 145558.7ms]
    db 0,0,100,0,92,127,1,3,125,6,92,1  ; n5536 t=145.702s dur=100ms, freq=1661Hz, sample=92, buffer_id=01:5C [TRUNCATE prev:ch3 @145451.6ms -> 145701.6ms]
    db 0,0,100,0,86,127,2,8,151,4,86,2  ; n5537 t=145.702s dur=100ms, freq=1175Hz, sample=86, buffer_id=02:56 [TRUNCATE prev:ch8 @145487.3ms -> 145701.6ms]
    db 0,0,100,0,90,127,2,11,117,5,90,2  ; n5538 t=145.702s dur=100ms, freq=1397Hz, sample=90, buffer_id=02:5A [TRUNCATE prev:ch11 @145558.7ms -> 145701.6ms]
    db 0,0,100,0,78,127,3,16,63,3,78,3  ; n5539 t=145.702s dur=100ms, freq=831Hz, sample=78, buffer_id=03:4E [TRUNCATE prev:ch16 @145415.8ms -> 145701.6ms]
    db 0,0,100,0,85,127,3,17,220,3,85,3  ; n5540 t=145.702s dur=100ms, freq=988Hz, sample=85, buffer_id=03:55 [TRUNCATE prev:ch17 @145415.8ms -> 145701.6ms]
    db 0,0,100,0,74,127,4,10,75,2,74,4  ; n5541 t=145.702s dur=100ms, freq=587Hz, sample=74, buffer_id=04:4A [TRUNCATE prev:ch10 @145487.3ms -> 145701.6ms]
    db 0,0,100,0,78,127,4,12,186,2,78,4  ; n5542 t=145.702s dur=100ms, freq=698Hz, sample=78, buffer_id=04:4E [TRUNCATE prev:ch12 @145558.7ms -> 145701.6ms]
    db 0,0,100,0,66,127,5,14,93,1,66,5  ; n5543 t=145.702s dur=100ms, freq=349Hz, sample=66, buffer_id=05:42 [TRUNCATE prev:ch14 @145558.7ms -> 145701.6ms]
    db 0,0,100,0,62,127,6,13,38,1,62,5  ; n5544 t=145.702s dur=100ms, freq=294Hz, sample=62, buffer_id=05:3E [TRUNCATE prev:ch13 @145487.3ms -> 145701.6ms]
    db 0,0,100,0,59,127,7,18,247,0,59,7  ; n5545 t=145.702s dur=100ms, freq=247Hz, sample=59, buffer_id=07:3B [TRUNCATE prev:ch18 @145415.8ms -> 145701.6ms]
    db 0,0,100,0,71,127,7,19,238,1,71,7  ; n5546 t=145.702s dur=100ms, freq=494Hz, sample=71, buffer_id=07:47 [TRUNCATE prev:ch19 @145415.8ms -> 145701.6ms]
    db 0,0,100,0,62,127,8,20,38,1,62,7  ; n5547 t=145.702s dur=100ms, freq=294Hz, sample=62, buffer_id=07:3E [TRUNCATE prev:ch20 @145415.8ms -> 145701.6ms]
    db 0,0,100,0,68,127,8,21,159,1,68,7  ; n5548 t=145.702s dur=100ms, freq=415Hz, sample=68, buffer_id=07:44 [TRUNCATE prev:ch21 @145415.8ms -> 145701.6ms]
    db 0,0,100,0,65,127,9,22,93,1,65,9  ; n5549 t=145.702s dur=100ms, freq=349Hz, sample=65, buffer_id=09:41 [TRUNCATE prev:ch22 @145415.8ms -> 145701.6ms]
    db 0,0,100,0,78,127,9,23,186,2,78,9  ; n5550 t=145.702s dur=100ms, freq=698Hz, sample=78, buffer_id=09:4E [TRUNCATE prev:ch23 @145415.8ms -> 145701.6ms]
    db 0,0,100,0,53,127,11,24,175,0,53,11  ; n5551 t=145.702s dur=100ms, freq=175Hz, sample=53, buffer_id=0B:35 [TRUNCATE prev:ch24 @145415.8ms -> 145701.6ms]
    db 0,0,100,0,54,127,11,26,208,0,54,11  ; n5552 t=145.702s dur=100ms, freq=208Hz, sample=54, buffer_id=0B:36 [TRUNCATE prev:ch26 @145415.8ms -> 145701.6ms]
    db 0,0,100,0,50,127,12,27,147,0,50,11  ; n5553 t=145.702s dur=100ms, freq=147Hz, sample=50, buffer_id=0B:32 [TRUNCATE prev:ch27 @145415.8ms -> 145701.6ms]
    db 0,0,214,0,97,127,16,4,184,7,97,16  ; n5554 t=145.702s dur=214ms, freq=1976Hz, sample=97, buffer_id=10:61 [TRUNCATE prev:ch4 @145451.6ms -> 145701.6ms]
    db 0,0,100,0,78,127,17,25,63,3,78,16  ; n5555 t=145.702s dur=100ms, freq=831Hz, sample=78, buffer_id=10:4E [TRUNCATE prev:ch25 @145451.6ms -> 145701.6ms]
    db 36,0,100,0,66,127,18,0,159,1,66,18  ; n5556 t=145.702s dur=100ms, freq=415Hz, sample=66, buffer_id=12:42 [TRUNCATE prev:ch0 @145487.3ms -> 145701.6ms]
    db 0,0,100,0,92,127,1,5,224,6,92,1  ; n5557 t=145.737s dur=100ms, freq=1760Hz, sample=92, buffer_id=01:5C [TRUNCATE prev:ch5 @145487.3ms -> 145737.3ms]
    db 0,0,100,0,78,127,17,6,112,3,78,16  ; n5558 t=145.737s dur=100ms, freq=880Hz, sample=78, buffer_id=10:4E [TRUNCATE prev:ch6 @145487.3ms -> 145737.3ms]
    db 36,0,100,0,66,127,18,7,184,1,66,18  ; n5559 t=145.737s dur=100ms, freq=440Hz, sample=66, buffer_id=12:42 [TRUNCATE prev:ch7 @145487.3ms -> 145737.3ms]
    db 0,0,100,0,94,127,1,1,73,7,94,1  ; n5560 t=145.773s dur=100ms, freq=1865Hz, sample=94, buffer_id=01:5E [TRUNCATE prev:ch1 @145523.0ms -> 145773.0ms]
    db 0,0,100,0,85,127,2,28,85,4,85,2  ; n5561 t=145.773s dur=100ms, freq=1109Hz, sample=85, buffer_id=02:55 [TRUNCATE prev:ch28 @145487.3ms -> 145773.0ms]
    db 0,0,100,0,86,127,2,29,39,5,86,2  ; n5562 t=145.773s dur=100ms, freq=1319Hz, sample=86, buffer_id=02:56 [TRUNCATE prev:ch29 @145558.7ms -> 145773.0ms]
    db 0,0,100,0,73,127,4,30,42,2,73,4  ; n5563 t=145.773s dur=100ms, freq=554Hz, sample=73, buffer_id=04:49 [TRUNCATE prev:ch30 @145487.3ms -> 145773.0ms]
    db 0,0,100,0,74,127,4,31,147,2,74,4  ; n5564 t=145.773s dur=100ms, freq=659Hz, sample=74, buffer_id=04:4A [TRUNCATE prev:ch31 @145558.7ms -> 145773.0ms]
    db 0,0,100,0,62,127,5,15,74,1,62,5  ; n5565 t=145.773s dur=100ms, freq=330Hz, sample=62, buffer_id=05:3E [TRUNCATE prev:ch15 @145558.7ms -> 145773.0ms]
    db 0,0,100,0,61,127,6,2,21,1,61,5  ; n5566 t=145.773s dur=100ms, freq=277Hz, sample=61, buffer_id=05:3D [TRUNCATE prev:ch2 @145523.0ms -> 145773.0ms]
    db 0,0,100,0,85,127,17,9,164,3,85,16  ; n5567 t=145.773s dur=100ms, freq=932Hz, sample=85, buffer_id=10:55 [TRUNCATE prev:ch9 @145523.0ms -> 145773.0ms]
    db 36,0,100,0,73,127,18,0,210,1,73,18  ; n5568 t=145.773s dur=100ms, freq=466Hz, sample=73, buffer_id=12:49 [TRUNCATE prev:ch0 @145701.6ms -> 145773.0ms]
    db 0,0,100,0,94,127,1,3,184,7,94,1  ; n5569 t=145.809s dur=100ms, freq=1976Hz, sample=94, buffer_id=01:5E [TRUNCATE prev:ch3 @145701.6ms -> 145808.7ms]
    db 0,0,100,0,85,127,17,4,220,3,85,16  ; n5570 t=145.809s dur=100ms, freq=988Hz, sample=85, buffer_id=10:55 [TRUNCATE prev:ch4 @145701.6ms -> 145808.7ms]
    db 36,0,100,0,73,127,18,8,238,1,73,18  ; n5571 t=145.809s dur=100ms, freq=494Hz, sample=73, buffer_id=12:49 [TRUNCATE prev:ch8 @145701.6ms -> 145808.7ms]
    db 0,0,125,0,86,127,2,10,151,4,86,2  ; n5572 t=145.844s dur=125ms, freq=1175Hz, sample=86, buffer_id=02:56 [TRUNCATE prev:ch10 @145701.6ms -> 145844.4ms]
    db 0,0,125,0,90,127,2,11,117,5,90,2  ; n5573 t=145.844s dur=125ms, freq=1397Hz, sample=90, buffer_id=02:5A [TRUNCATE prev:ch11 @145701.6ms -> 145844.4ms]
    db 0,0,125,0,74,127,4,12,75,2,74,4  ; n5574 t=145.844s dur=125ms, freq=587Hz, sample=74, buffer_id=04:4A [TRUNCATE prev:ch12 @145701.6ms -> 145844.4ms]
    db 0,0,125,0,78,127,4,13,186,2,78,4  ; n5575 t=145.844s dur=125ms, freq=698Hz, sample=78, buffer_id=04:4E [TRUNCATE prev:ch13 @145701.6ms -> 145844.4ms]
    db 0,0,125,0,66,127,5,14,93,1,66,5  ; n5576 t=145.844s dur=125ms, freq=349Hz, sample=66, buffer_id=05:42 [TRUNCATE prev:ch14 @145701.6ms -> 145844.4ms]
    db 143,0,125,0,62,127,6,16,38,1,62,5  ; n5577 t=145.844s dur=125ms, freq=294Hz, sample=62, buffer_id=05:3E [TRUNCATE prev:ch16 @145701.6ms -> 145844.4ms]
    db 0,0,100,0,92,127,1,5,125,6,92,1  ; n5578 t=145.987s dur=100ms, freq=1661Hz, sample=92, buffer_id=01:5C [TRUNCATE prev:ch5 @145737.3ms -> 145987.3ms]
    db 0,0,100,0,86,127,2,29,151,4,86,2  ; n5579 t=145.987s dur=100ms, freq=1175Hz, sample=86, buffer_id=02:56 [TRUNCATE prev:ch29 @145773.0ms -> 145987.3ms]
    db 0,0,100,0,90,127,2,11,117,5,90,2  ; n5580 t=145.987s dur=100ms, freq=1397Hz, sample=90, buffer_id=02:5A [TRUNCATE prev:ch11 @145844.4ms -> 145987.3ms]
    db 0,0,100,0,78,127,3,17,63,3,78,3  ; n5581 t=145.987s dur=100ms, freq=831Hz, sample=78, buffer_id=03:4E [TRUNCATE prev:ch17 @145701.6ms -> 145987.3ms]
    db 0,0,100,0,85,127,3,18,220,3,85,3  ; n5582 t=145.987s dur=100ms, freq=988Hz, sample=85, buffer_id=03:55 [TRUNCATE prev:ch18 @145701.6ms -> 145987.3ms]
    db 0,0,100,0,74,127,4,31,75,2,74,4  ; n5583 t=145.987s dur=100ms, freq=587Hz, sample=74, buffer_id=04:4A [TRUNCATE prev:ch31 @145773.0ms -> 145987.3ms]
    db 0,0,100,0,78,127,4,13,186,2,78,4  ; n5584 t=145.987s dur=100ms, freq=698Hz, sample=78, buffer_id=04:4E [TRUNCATE prev:ch13 @145844.4ms -> 145987.3ms]
    db 0,0,100,0,66,127,5,14,93,1,66,5  ; n5585 t=145.987s dur=100ms, freq=349Hz, sample=66, buffer_id=05:42 [TRUNCATE prev:ch14 @145844.4ms -> 145987.3ms]
    db 0,0,100,0,62,127,6,15,38,1,62,5  ; n5586 t=145.987s dur=100ms, freq=294Hz, sample=62, buffer_id=05:3E [TRUNCATE prev:ch15 @145773.0ms -> 145987.3ms]
    db 0,0,100,0,59,127,7,19,247,0,59,7  ; n5587 t=145.987s dur=100ms, freq=247Hz, sample=59, buffer_id=07:3B [TRUNCATE prev:ch19 @145701.6ms -> 145987.3ms]
    db 0,0,100,0,71,127,7,20,238,1,71,7  ; n5588 t=145.987s dur=100ms, freq=494Hz, sample=71, buffer_id=07:47 [TRUNCATE prev:ch20 @145701.6ms -> 145987.3ms]
    db 0,0,100,0,62,127,8,21,38,1,62,7  ; n5589 t=145.987s dur=100ms, freq=294Hz, sample=62, buffer_id=07:3E [TRUNCATE prev:ch21 @145701.6ms -> 145987.3ms]
    db 0,0,100,0,68,127,8,22,159,1,68,7  ; n5590 t=145.987s dur=100ms, freq=415Hz, sample=68, buffer_id=07:44 [TRUNCATE prev:ch22 @145701.6ms -> 145987.3ms]
    db 0,0,100,0,65,127,9,23,93,1,65,9  ; n5591 t=145.987s dur=100ms, freq=349Hz, sample=65, buffer_id=09:41 [TRUNCATE prev:ch23 @145701.6ms -> 145987.3ms]
    db 0,0,100,0,78,127,9,24,186,2,78,9  ; n5592 t=145.987s dur=100ms, freq=698Hz, sample=78, buffer_id=09:4E [TRUNCATE prev:ch24 @145701.6ms -> 145987.3ms]
    db 0,0,100,0,53,127,11,25,175,0,53,11  ; n5593 t=145.987s dur=100ms, freq=175Hz, sample=53, buffer_id=0B:35 [TRUNCATE prev:ch25 @145701.6ms -> 145987.3ms]
    db 0,0,100,0,54,127,11,26,208,0,54,11  ; n5594 t=145.987s dur=100ms, freq=208Hz, sample=54, buffer_id=0B:36 [TRUNCATE prev:ch26 @145701.6ms -> 145987.3ms]
    db 0,0,100,0,50,127,12,27,147,0,50,11  ; n5595 t=145.987s dur=100ms, freq=147Hz, sample=50, buffer_id=0B:32 [TRUNCATE prev:ch27 @145701.6ms -> 145987.3ms]
    db 0,0,100,0,97,127,16,6,184,7,97,16  ; n5596 t=145.987s dur=100ms, freq=1976Hz, sample=97, buffer_id=10:61 [TRUNCATE prev:ch6 @145737.3ms -> 145987.3ms]
    db 0,0,100,0,78,127,17,7,63,3,78,16  ; n5597 t=145.987s dur=100ms, freq=831Hz, sample=78, buffer_id=10:4E [TRUNCATE prev:ch7 @145737.3ms -> 145987.3ms]
    db 36,0,100,0,66,127,18,0,159,1,66,18  ; n5598 t=145.987s dur=100ms, freq=415Hz, sample=66, buffer_id=12:42 [TRUNCATE prev:ch0 @145773.0ms -> 145987.3ms]
    db 0,0,100,0,92,127,1,1,224,6,92,1  ; n5599 t=146.023s dur=100ms, freq=1760Hz, sample=92, buffer_id=01:5C [TRUNCATE prev:ch1 @145773.0ms -> 146023.0ms]
    db 0,0,100,0,78,127,17,2,112,3,78,16  ; n5600 t=146.023s dur=100ms, freq=880Hz, sample=78, buffer_id=10:4E [TRUNCATE prev:ch2 @145773.0ms -> 146023.0ms]
    db 36,0,100,0,66,127,18,9,184,1,66,18  ; n5601 t=146.023s dur=100ms, freq=440Hz, sample=66, buffer_id=12:42 [TRUNCATE prev:ch9 @145773.0ms -> 146023.0ms]
    db 0,0,100,0,94,127,1,3,73,7,94,1  ; n5602 t=146.059s dur=100ms, freq=1865Hz, sample=94, buffer_id=01:5E [TRUNCATE prev:ch3 @145808.7ms -> 146058.7ms]
    db 0,0,100,0,85,127,2,28,85,4,85,2  ; n5603 t=146.059s dur=100ms, freq=1109Hz, sample=85, buffer_id=02:55 [TRUNCATE prev:ch28 @145773.0ms -> 146058.7ms]
    db 0,0,100,0,86,127,2,10,39,5,86,2  ; n5604 t=146.059s dur=100ms, freq=1319Hz, sample=86, buffer_id=02:56 [TRUNCATE prev:ch10 @145844.4ms -> 146058.7ms]
    db 0,0,100,0,73,127,4,30,42,2,73,4  ; n5605 t=146.059s dur=100ms, freq=554Hz, sample=73, buffer_id=04:49 [TRUNCATE prev:ch30 @145773.0ms -> 146058.7ms]
    db 0,0,100,0,74,127,4,12,147,2,74,4  ; n5606 t=146.059s dur=100ms, freq=659Hz, sample=74, buffer_id=04:4A [TRUNCATE prev:ch12 @145844.4ms -> 146058.7ms]
    db 0,0,100,0,62,127,5,16,74,1,62,5  ; n5607 t=146.059s dur=100ms, freq=330Hz, sample=62, buffer_id=05:3E [TRUNCATE prev:ch16 @145844.4ms -> 146058.7ms]
    db 0,0,100,0,61,127,6,4,21,1,61,5  ; n5608 t=146.059s dur=100ms, freq=277Hz, sample=61, buffer_id=05:3D [TRUNCATE prev:ch4 @145808.7ms -> 146058.7ms]
    db 0,0,100,0,85,127,17,8,164,3,85,16  ; n5609 t=146.059s dur=100ms, freq=932Hz, sample=85, buffer_id=10:55 [TRUNCATE prev:ch8 @145808.7ms -> 146058.7ms]
    db 36,0,100,0,73,127,18,0,210,1,73,18  ; n5610 t=146.059s dur=100ms, freq=466Hz, sample=73, buffer_id=12:49 [TRUNCATE prev:ch0 @145987.3ms -> 146058.7ms]
    db 0,0,100,0,94,127,1,5,184,7,94,1  ; n5611 t=146.094s dur=100ms, freq=1976Hz, sample=94, buffer_id=01:5E [TRUNCATE prev:ch5 @145987.3ms -> 146094.4ms]
    db 0,0,100,0,85,127,17,6,220,3,85,16  ; n5612 t=146.094s dur=100ms, freq=988Hz, sample=85, buffer_id=10:55 [TRUNCATE prev:ch6 @145987.3ms -> 146094.4ms]
    db 36,0,100,0,73,127,18,7,238,1,73,18  ; n5613 t=146.094s dur=100ms, freq=494Hz, sample=73, buffer_id=12:49 [TRUNCATE prev:ch7 @145987.3ms -> 146094.4ms]
    db 0,0,125,0,86,127,2,29,151,4,86,2  ; n5614 t=146.130s dur=125ms, freq=1175Hz, sample=86, buffer_id=02:56 [TRUNCATE prev:ch29 @145987.3ms -> 146130.1ms]
    db 0,0,125,0,90,127,2,11,117,5,90,2  ; n5615 t=146.130s dur=125ms, freq=1397Hz, sample=90, buffer_id=02:5A [TRUNCATE prev:ch11 @145987.3ms -> 146130.1ms]
    db 0,0,125,0,74,127,4,31,75,2,74,4  ; n5616 t=146.130s dur=125ms, freq=587Hz, sample=74, buffer_id=04:4A [TRUNCATE prev:ch31 @145987.3ms -> 146130.1ms]
    db 0,0,125,0,78,127,4,13,186,2,78,4  ; n5617 t=146.130s dur=125ms, freq=698Hz, sample=78, buffer_id=04:4E [TRUNCATE prev:ch13 @145987.3ms -> 146130.1ms]
    db 0,0,125,0,66,127,5,14,93,1,66,5  ; n5618 t=146.130s dur=125ms, freq=349Hz, sample=66, buffer_id=05:42 [TRUNCATE prev:ch14 @145987.3ms -> 146130.1ms]
    db 143,0,125,0,62,127,6,15,38,1,62,5  ; n5619 t=146.130s dur=125ms, freq=294Hz, sample=62, buffer_id=05:3E [TRUNCATE prev:ch15 @145987.3ms -> 146130.1ms]
    db 0,0,100,0,92,127,1,1,125,6,92,1  ; n5620 t=146.273s dur=100ms, freq=1661Hz, sample=92, buffer_id=01:5C [TRUNCATE prev:ch1 @146023.0ms -> 146273.0ms]
    db 0,0,100,0,86,127,2,10,151,4,86,2  ; n5621 t=146.273s dur=100ms, freq=1175Hz, sample=86, buffer_id=02:56 [TRUNCATE prev:ch10 @146058.7ms -> 146273.0ms]
    db 0,0,100,0,90,127,2,11,117,5,90,2  ; n5622 t=146.273s dur=100ms, freq=1397Hz, sample=90, buffer_id=02:5A [TRUNCATE prev:ch11 @146130.1ms -> 146273.0ms]
    db 0,0,100,0,78,127,3,17,63,3,78,3  ; n5623 t=146.273s dur=100ms, freq=831Hz, sample=78, buffer_id=03:4E [TRUNCATE prev:ch17 @145987.3ms -> 146273.0ms]
    db 0,0,100,0,85,127,3,18,220,3,85,3  ; n5624 t=146.273s dur=100ms, freq=988Hz, sample=85, buffer_id=03:55 [TRUNCATE prev:ch18 @145987.3ms -> 146273.0ms]
    db 0,0,100,0,74,127,4,12,75,2,74,4  ; n5625 t=146.273s dur=100ms, freq=587Hz, sample=74, buffer_id=04:4A [TRUNCATE prev:ch12 @146058.7ms -> 146273.0ms]
    db 0,0,100,0,78,127,4,13,186,2,78,4  ; n5626 t=146.273s dur=100ms, freq=698Hz, sample=78, buffer_id=04:4E [TRUNCATE prev:ch13 @146130.1ms -> 146273.0ms]
    db 0,0,100,0,66,127,5,14,93,1,66,5  ; n5627 t=146.273s dur=100ms, freq=349Hz, sample=66, buffer_id=05:42 [TRUNCATE prev:ch14 @146130.1ms -> 146273.0ms]
    db 0,0,100,0,62,127,6,16,38,1,62,5  ; n5628 t=146.273s dur=100ms, freq=294Hz, sample=62, buffer_id=05:3E [TRUNCATE prev:ch16 @146058.7ms -> 146273.0ms]
    db 0,0,100,0,59,127,7,19,247,0,59,7  ; n5629 t=146.273s dur=100ms, freq=247Hz, sample=59, buffer_id=07:3B [TRUNCATE prev:ch19 @145987.3ms -> 146273.0ms]
    db 0,0,100,0,71,127,7,20,238,1,71,7  ; n5630 t=146.273s dur=100ms, freq=494Hz, sample=71, buffer_id=07:47 [TRUNCATE prev:ch20 @145987.3ms -> 146273.0ms]
    db 0,0,100,0,62,127,8,21,38,1,62,7  ; n5631 t=146.273s dur=100ms, freq=294Hz, sample=62, buffer_id=07:3E [TRUNCATE prev:ch21 @145987.3ms -> 146273.0ms]
    db 0,0,100,0,68,127,8,22,159,1,68,7  ; n5632 t=146.273s dur=100ms, freq=415Hz, sample=68, buffer_id=07:44 [TRUNCATE prev:ch22 @145987.3ms -> 146273.0ms]
    db 0,0,100,0,65,127,9,23,93,1,65,9  ; n5633 t=146.273s dur=100ms, freq=349Hz, sample=65, buffer_id=09:41 [TRUNCATE prev:ch23 @145987.3ms -> 146273.0ms]
    db 0,0,100,0,78,127,9,24,186,2,78,9  ; n5634 t=146.273s dur=100ms, freq=698Hz, sample=78, buffer_id=09:4E [TRUNCATE prev:ch24 @145987.3ms -> 146273.0ms]
    db 0,0,100,0,53,127,11,25,175,0,53,11  ; n5635 t=146.273s dur=100ms, freq=175Hz, sample=53, buffer_id=0B:35 [TRUNCATE prev:ch25 @145987.3ms -> 146273.0ms]
    db 0,0,100,0,54,127,11,26,208,0,54,11  ; n5636 t=146.273s dur=100ms, freq=208Hz, sample=54, buffer_id=0B:36 [TRUNCATE prev:ch26 @145987.3ms -> 146273.0ms]
    db 0,0,100,0,50,127,12,27,147,0,50,11  ; n5637 t=146.273s dur=100ms, freq=147Hz, sample=50, buffer_id=0B:32 [TRUNCATE prev:ch27 @145987.3ms -> 146273.0ms]
    db 0,0,100,0,97,127,16,2,184,7,97,16  ; n5638 t=146.273s dur=100ms, freq=1976Hz, sample=97, buffer_id=10:61 [TRUNCATE prev:ch2 @146023.0ms -> 146273.0ms]
    db 0,0,100,0,78,127,17,9,63,3,78,16  ; n5639 t=146.273s dur=100ms, freq=831Hz, sample=78, buffer_id=10:4E [TRUNCATE prev:ch9 @146023.0ms -> 146273.0ms]
    db 36,0,100,0,66,127,18,0,159,1,66,18  ; n5640 t=146.273s dur=100ms, freq=415Hz, sample=66, buffer_id=12:42 [TRUNCATE prev:ch0 @146058.7ms -> 146273.0ms]
    db 0,0,100,0,92,127,1,3,224,6,92,1  ; n5641 t=146.309s dur=100ms, freq=1760Hz, sample=92, buffer_id=01:5C [TRUNCATE prev:ch3 @146058.7ms -> 146308.7ms]
    db 0,0,100,0,78,127,17,4,112,3,78,16  ; n5642 t=146.309s dur=100ms, freq=880Hz, sample=78, buffer_id=10:4E [TRUNCATE prev:ch4 @146058.7ms -> 146308.7ms]
    db 36,0,100,0,66,127,18,8,184,1,66,18  ; n5643 t=146.309s dur=100ms, freq=440Hz, sample=66, buffer_id=12:42 [TRUNCATE prev:ch8 @146058.7ms -> 146308.7ms]
    db 0,0,100,0,94,127,1,5,73,7,94,1  ; n5644 t=146.344s dur=100ms, freq=1865Hz, sample=94, buffer_id=01:5E [TRUNCATE prev:ch5 @146094.4ms -> 146344.4ms]
    db 0,0,100,0,85,127,2,28,85,4,85,2  ; n5645 t=146.344s dur=100ms, freq=1109Hz, sample=85, buffer_id=02:55 [TRUNCATE prev:ch28 @146058.7ms -> 146344.4ms]
    db 0,0,100,0,86,127,2,29,39,5,86,2  ; n5646 t=146.344s dur=100ms, freq=1319Hz, sample=86, buffer_id=02:56 [TRUNCATE prev:ch29 @146130.1ms -> 146344.4ms]
    db 0,0,100,0,73,127,4,30,42,2,73,4  ; n5647 t=146.344s dur=100ms, freq=554Hz, sample=73, buffer_id=04:49 [TRUNCATE prev:ch30 @146058.7ms -> 146344.4ms]
    db 0,0,100,0,74,127,4,31,147,2,74,4  ; n5648 t=146.344s dur=100ms, freq=659Hz, sample=74, buffer_id=04:4A [TRUNCATE prev:ch31 @146130.1ms -> 146344.4ms]
    db 0,0,100,0,62,127,5,15,74,1,62,5  ; n5649 t=146.344s dur=100ms, freq=330Hz, sample=62, buffer_id=05:3E [TRUNCATE prev:ch15 @146130.1ms -> 146344.4ms]
    db 0,0,100,0,61,127,6,6,21,1,61,5  ; n5650 t=146.344s dur=100ms, freq=277Hz, sample=61, buffer_id=05:3D [TRUNCATE prev:ch6 @146094.4ms -> 146344.4ms]
    db 0,0,100,0,85,127,17,7,164,3,85,16  ; n5651 t=146.344s dur=100ms, freq=932Hz, sample=85, buffer_id=10:55 [TRUNCATE prev:ch7 @146094.4ms -> 146344.4ms]
    db 36,0,100,0,73,127,18,0,210,1,73,18  ; n5652 t=146.344s dur=100ms, freq=466Hz, sample=73, buffer_id=12:49 [TRUNCATE prev:ch0 @146273.0ms -> 146344.4ms]
    db 0,0,100,0,94,127,1,1,184,7,94,1  ; n5653 t=146.380s dur=100ms, freq=1976Hz, sample=94, buffer_id=01:5E [TRUNCATE prev:ch1 @146273.0ms -> 146380.1ms]
    db 0,0,100,0,85,127,17,2,220,3,85,16  ; n5654 t=146.380s dur=100ms, freq=988Hz, sample=85, buffer_id=10:55 [TRUNCATE prev:ch2 @146273.0ms -> 146380.1ms]
    db 36,0,100,0,73,127,18,9,238,1,73,18  ; n5655 t=146.380s dur=100ms, freq=494Hz, sample=73, buffer_id=12:49 [TRUNCATE prev:ch9 @146273.0ms -> 146380.1ms]
    db 0,0,125,0,86,127,2,10,151,4,86,2  ; n5656 t=146.416s dur=125ms, freq=1175Hz, sample=86, buffer_id=02:56 [TRUNCATE prev:ch10 @146273.0ms -> 146415.8ms]
    db 0,0,125,0,90,127,2,11,117,5,90,2  ; n5657 t=146.416s dur=125ms, freq=1397Hz, sample=90, buffer_id=02:5A [TRUNCATE prev:ch11 @146273.0ms -> 146415.8ms]
    db 0,0,125,0,74,127,4,12,75,2,74,4  ; n5658 t=146.416s dur=125ms, freq=587Hz, sample=74, buffer_id=04:4A [TRUNCATE prev:ch12 @146273.0ms -> 146415.8ms]
    db 0,0,125,0,78,127,4,13,186,2,78,4  ; n5659 t=146.416s dur=125ms, freq=698Hz, sample=78, buffer_id=04:4E [TRUNCATE prev:ch13 @146273.0ms -> 146415.8ms]
    db 0,0,125,0,66,127,5,14,93,1,66,5  ; n5660 t=146.416s dur=125ms, freq=349Hz, sample=66, buffer_id=05:42 [TRUNCATE prev:ch14 @146273.0ms -> 146415.8ms]
    db 143,0,125,0,62,127,6,16,38,1,62,5  ; n5661 t=146.416s dur=125ms, freq=294Hz, sample=62, buffer_id=05:3E [TRUNCATE prev:ch16 @146273.0ms -> 146415.8ms]
    db 0,0,100,0,92,127,1,3,125,6,92,1  ; n5662 t=146.559s dur=100ms, freq=1661Hz, sample=92, buffer_id=01:5C [TRUNCATE prev:ch3 @146308.7ms -> 146558.7ms]
    db 0,0,100,0,86,127,2,29,151,4,86,2  ; n5663 t=146.559s dur=100ms, freq=1175Hz, sample=86, buffer_id=02:56 [TRUNCATE prev:ch29 @146344.4ms -> 146558.7ms]
    db 0,0,100,0,90,127,2,11,117,5,90,2  ; n5664 t=146.559s dur=100ms, freq=1397Hz, sample=90, buffer_id=02:5A [TRUNCATE prev:ch11 @146415.8ms -> 146558.7ms]
    db 0,0,100,0,78,127,3,17,63,3,78,3  ; n5665 t=146.559s dur=100ms, freq=831Hz, sample=78, buffer_id=03:4E [TRUNCATE prev:ch17 @146273.0ms -> 146558.7ms]
    db 0,0,100,0,85,127,3,18,220,3,85,3  ; n5666 t=146.559s dur=100ms, freq=988Hz, sample=85, buffer_id=03:55 [TRUNCATE prev:ch18 @146273.0ms -> 146558.7ms]
    db 0,0,100,0,74,127,4,31,75,2,74,4  ; n5667 t=146.559s dur=100ms, freq=587Hz, sample=74, buffer_id=04:4A [TRUNCATE prev:ch31 @146344.4ms -> 146558.7ms]
    db 0,0,100,0,78,127,4,13,186,2,78,4  ; n5668 t=146.559s dur=100ms, freq=698Hz, sample=78, buffer_id=04:4E [TRUNCATE prev:ch13 @146415.8ms -> 146558.7ms]
    db 0,0,100,0,66,127,5,14,93,1,66,5  ; n5669 t=146.559s dur=100ms, freq=349Hz, sample=66, buffer_id=05:42 [TRUNCATE prev:ch14 @146415.8ms -> 146558.7ms]
    db 0,0,100,0,62,127,6,15,38,1,62,5  ; n5670 t=146.559s dur=100ms, freq=294Hz, sample=62, buffer_id=05:3E [TRUNCATE prev:ch15 @146344.4ms -> 146558.7ms]
    db 0,0,100,0,59,127,7,19,247,0,59,7  ; n5671 t=146.559s dur=100ms, freq=247Hz, sample=59, buffer_id=07:3B [TRUNCATE prev:ch19 @146273.0ms -> 146558.7ms]
    db 0,0,100,0,71,127,7,20,238,1,71,7  ; n5672 t=146.559s dur=100ms, freq=494Hz, sample=71, buffer_id=07:47 [TRUNCATE prev:ch20 @146273.0ms -> 146558.7ms]
    db 0,0,100,0,62,127,8,21,38,1,62,7  ; n5673 t=146.559s dur=100ms, freq=294Hz, sample=62, buffer_id=07:3E [TRUNCATE prev:ch21 @146273.0ms -> 146558.7ms]
    db 0,0,100,0,68,127,8,22,159,1,68,7  ; n5674 t=146.559s dur=100ms, freq=415Hz, sample=68, buffer_id=07:44 [TRUNCATE prev:ch22 @146273.0ms -> 146558.7ms]
    db 0,0,100,0,65,127,9,23,93,1,65,9  ; n5675 t=146.559s dur=100ms, freq=349Hz, sample=65, buffer_id=09:41 [TRUNCATE prev:ch23 @146273.0ms -> 146558.7ms]
    db 0,0,100,0,78,127,9,24,186,2,78,9  ; n5676 t=146.559s dur=100ms, freq=698Hz, sample=78, buffer_id=09:4E [TRUNCATE prev:ch24 @146273.0ms -> 146558.7ms]
    db 0,0,100,0,53,127,11,25,175,0,53,11  ; n5677 t=146.559s dur=100ms, freq=175Hz, sample=53, buffer_id=0B:35 [TRUNCATE prev:ch25 @146273.0ms -> 146558.7ms]
    db 0,0,100,0,54,127,11,26,208,0,54,11  ; n5678 t=146.559s dur=100ms, freq=208Hz, sample=54, buffer_id=0B:36 [TRUNCATE prev:ch26 @146273.0ms -> 146558.7ms]
    db 0,0,100,0,50,127,12,27,147,0,50,11  ; n5679 t=146.559s dur=100ms, freq=147Hz, sample=50, buffer_id=0B:32 [TRUNCATE prev:ch27 @146273.0ms -> 146558.7ms]
    db 0,0,100,0,97,127,16,4,184,7,97,16  ; n5680 t=146.559s dur=100ms, freq=1976Hz, sample=97, buffer_id=10:61 [TRUNCATE prev:ch4 @146308.7ms -> 146558.7ms]
    db 0,0,100,0,78,127,17,8,63,3,78,16  ; n5681 t=146.559s dur=100ms, freq=831Hz, sample=78, buffer_id=10:4E [TRUNCATE prev:ch8 @146308.7ms -> 146558.7ms]
    db 36,0,100,0,66,127,18,0,159,1,66,18  ; n5682 t=146.559s dur=100ms, freq=415Hz, sample=66, buffer_id=12:42 [TRUNCATE prev:ch0 @146344.4ms -> 146558.7ms]
    db 0,0,100,0,92,127,1,5,224,6,92,1  ; n5683 t=146.594s dur=100ms, freq=1760Hz, sample=92, buffer_id=01:5C [TRUNCATE prev:ch5 @146344.4ms -> 146594.4ms]
    db 0,0,100,0,78,127,17,6,112,3,78,16  ; n5684 t=146.594s dur=100ms, freq=880Hz, sample=78, buffer_id=10:4E [TRUNCATE prev:ch6 @146344.4ms -> 146594.4ms]
    db 36,0,100,0,66,127,18,7,184,1,66,18  ; n5685 t=146.594s dur=100ms, freq=440Hz, sample=66, buffer_id=12:42 [TRUNCATE prev:ch7 @146344.4ms -> 146594.4ms]
    db 0,0,100,0,94,127,1,1,73,7,94,1  ; n5686 t=146.630s dur=100ms, freq=1865Hz, sample=94, buffer_id=01:5E [TRUNCATE prev:ch1 @146380.1ms -> 146630.1ms]
    db 0,0,100,0,85,127,2,28,85,4,85,2  ; n5687 t=146.630s dur=100ms, freq=1109Hz, sample=85, buffer_id=02:55 [TRUNCATE prev:ch28 @146344.4ms -> 146630.1ms]
    db 0,0,100,0,86,127,2,10,39,5,86,2  ; n5688 t=146.630s dur=100ms, freq=1319Hz, sample=86, buffer_id=02:56 [TRUNCATE prev:ch10 @146415.8ms -> 146630.1ms]
    db 0,0,100,0,73,127,4,30,42,2,73,4  ; n5689 t=146.630s dur=100ms, freq=554Hz, sample=73, buffer_id=04:49 [TRUNCATE prev:ch30 @146344.4ms -> 146630.1ms]
    db 0,0,100,0,74,127,4,12,147,2,74,4  ; n5690 t=146.630s dur=100ms, freq=659Hz, sample=74, buffer_id=04:4A [TRUNCATE prev:ch12 @146415.8ms -> 146630.1ms]
    db 0,0,100,0,62,127,5,16,74,1,62,5  ; n5691 t=146.630s dur=100ms, freq=330Hz, sample=62, buffer_id=05:3E [TRUNCATE prev:ch16 @146415.8ms -> 146630.1ms]
    db 0,0,100,0,61,127,6,2,21,1,61,5  ; n5692 t=146.630s dur=100ms, freq=277Hz, sample=61, buffer_id=05:3D [TRUNCATE prev:ch2 @146380.1ms -> 146630.1ms]
    db 0,0,100,0,85,127,17,9,164,3,85,16  ; n5693 t=146.630s dur=100ms, freq=932Hz, sample=85, buffer_id=10:55 [TRUNCATE prev:ch9 @146380.1ms -> 146630.1ms]
    db 36,0,100,0,73,127,18,0,210,1,73,18  ; n5694 t=146.630s dur=100ms, freq=466Hz, sample=73, buffer_id=12:49 [TRUNCATE prev:ch0 @146558.7ms -> 146630.1ms]
    db 0,0,100,0,94,127,1,3,184,7,94,1  ; n5695 t=146.666s dur=100ms, freq=1976Hz, sample=94, buffer_id=01:5E [TRUNCATE prev:ch3 @146558.7ms -> 146665.8ms]
    db 0,0,100,0,85,127,17,4,220,3,85,16  ; n5696 t=146.666s dur=100ms, freq=988Hz, sample=85, buffer_id=10:55 [TRUNCATE prev:ch4 @146558.7ms -> 146665.8ms]
    db 36,0,100,0,73,127,18,8,238,1,73,18  ; n5697 t=146.666s dur=100ms, freq=494Hz, sample=73, buffer_id=12:49 [TRUNCATE prev:ch8 @146558.7ms -> 146665.8ms]
    db 0,0,125,0,86,127,2,29,151,4,86,2  ; n5698 t=146.702s dur=125ms, freq=1175Hz, sample=86, buffer_id=02:56 [TRUNCATE prev:ch29 @146558.7ms -> 146701.6ms]
    db 0,0,125,0,90,127,2,11,117,5,90,2  ; n5699 t=146.702s dur=125ms, freq=1397Hz, sample=90, buffer_id=02:5A [TRUNCATE prev:ch11 @146558.7ms -> 146701.6ms]
    db 0,0,125,0,74,127,4,31,75,2,74,4  ; n5700 t=146.702s dur=125ms, freq=587Hz, sample=74, buffer_id=04:4A [TRUNCATE prev:ch31 @146558.7ms -> 146701.6ms]
    db 0,0,125,0,78,127,4,13,186,2,78,4  ; n5701 t=146.702s dur=125ms, freq=698Hz, sample=78, buffer_id=04:4E [TRUNCATE prev:ch13 @146558.7ms -> 146701.6ms]
    db 0,0,125,0,66,127,5,14,93,1,66,5  ; n5702 t=146.702s dur=125ms, freq=349Hz, sample=66, buffer_id=05:42 [TRUNCATE prev:ch14 @146558.7ms -> 146701.6ms]
    db 143,0,125,0,62,127,6,15,38,1,62,5  ; n5703 t=146.702s dur=125ms, freq=294Hz, sample=62, buffer_id=05:3E [TRUNCATE prev:ch15 @146558.7ms -> 146701.6ms]
    db 0,0,100,0,92,127,1,5,125,6,92,1  ; n5704 t=146.844s dur=100ms, freq=1661Hz, sample=92, buffer_id=01:5C [TRUNCATE prev:ch5 @146594.4ms -> 146844.4ms]
    db 0,0,100,0,86,127,2,10,151,4,86,2  ; n5705 t=146.844s dur=100ms, freq=1175Hz, sample=86, buffer_id=02:56 [TRUNCATE prev:ch10 @146630.1ms -> 146844.4ms]
    db 0,0,100,0,90,127,2,11,117,5,90,2  ; n5706 t=146.844s dur=100ms, freq=1397Hz, sample=90, buffer_id=02:5A [TRUNCATE prev:ch11 @146701.6ms -> 146844.4ms]
    db 0,0,100,0,78,127,3,17,63,3,78,3  ; n5707 t=146.844s dur=100ms, freq=831Hz, sample=78, buffer_id=03:4E [TRUNCATE prev:ch17 @146558.7ms -> 146844.4ms]
    db 0,0,100,0,85,127,3,18,220,3,85,3  ; n5708 t=146.844s dur=100ms, freq=988Hz, sample=85, buffer_id=03:55 [TRUNCATE prev:ch18 @146558.7ms -> 146844.4ms]
    db 0,0,100,0,74,127,4,12,75,2,74,4  ; n5709 t=146.844s dur=100ms, freq=587Hz, sample=74, buffer_id=04:4A [TRUNCATE prev:ch12 @146630.1ms -> 146844.4ms]
    db 0,0,100,0,78,127,4,13,186,2,78,4  ; n5710 t=146.844s dur=100ms, freq=698Hz, sample=78, buffer_id=04:4E [TRUNCATE prev:ch13 @146701.6ms -> 146844.4ms]
    db 0,0,100,0,66,127,5,14,93,1,66,5  ; n5711 t=146.844s dur=100ms, freq=349Hz, sample=66, buffer_id=05:42 [TRUNCATE prev:ch14 @146701.6ms -> 146844.4ms]
    db 0,0,100,0,62,127,6,16,38,1,62,5  ; n5712 t=146.844s dur=100ms, freq=294Hz, sample=62, buffer_id=05:3E [TRUNCATE prev:ch16 @146630.1ms -> 146844.4ms]
    db 0,0,100,0,59,127,7,19,247,0,59,7  ; n5713 t=146.844s dur=100ms, freq=247Hz, sample=59, buffer_id=07:3B [TRUNCATE prev:ch19 @146558.7ms -> 146844.4ms]
    db 0,0,100,0,71,127,7,20,238,1,71,7  ; n5714 t=146.844s dur=100ms, freq=494Hz, sample=71, buffer_id=07:47 [TRUNCATE prev:ch20 @146558.7ms -> 146844.4ms]
    db 0,0,100,0,62,127,8,21,38,1,62,7  ; n5715 t=146.844s dur=100ms, freq=294Hz, sample=62, buffer_id=07:3E [TRUNCATE prev:ch21 @146558.7ms -> 146844.4ms]
    db 0,0,100,0,68,127,8,22,159,1,68,7  ; n5716 t=146.844s dur=100ms, freq=415Hz, sample=68, buffer_id=07:44 [TRUNCATE prev:ch22 @146558.7ms -> 146844.4ms]
    db 0,0,100,0,65,127,9,23,93,1,65,9  ; n5717 t=146.844s dur=100ms, freq=349Hz, sample=65, buffer_id=09:41 [TRUNCATE prev:ch23 @146558.7ms -> 146844.4ms]
    db 0,0,100,0,78,127,9,24,186,2,78,9  ; n5718 t=146.844s dur=100ms, freq=698Hz, sample=78, buffer_id=09:4E [TRUNCATE prev:ch24 @146558.7ms -> 146844.4ms]
    db 0,0,100,0,53,127,11,25,175,0,53,11  ; n5719 t=146.844s dur=100ms, freq=175Hz, sample=53, buffer_id=0B:35 [TRUNCATE prev:ch25 @146558.7ms -> 146844.4ms]
    db 0,0,100,0,54,127,11,26,208,0,54,11  ; n5720 t=146.844s dur=100ms, freq=208Hz, sample=54, buffer_id=0B:36 [TRUNCATE prev:ch26 @146558.7ms -> 146844.4ms]
    db 0,0,100,0,50,127,12,27,147,0,50,11  ; n5721 t=146.844s dur=100ms, freq=147Hz, sample=50, buffer_id=0B:32 [TRUNCATE prev:ch27 @146558.7ms -> 146844.4ms]
    db 0,0,100,0,97,127,16,6,184,7,97,16  ; n5722 t=146.844s dur=100ms, freq=1976Hz, sample=97, buffer_id=10:61 [TRUNCATE prev:ch6 @146594.4ms -> 146844.4ms]
    db 0,0,100,0,78,127,17,7,63,3,78,16  ; n5723 t=146.844s dur=100ms, freq=831Hz, sample=78, buffer_id=10:4E [TRUNCATE prev:ch7 @146594.4ms -> 146844.4ms]
    db 36,0,100,0,66,127,18,0,159,1,66,18  ; n5724 t=146.844s dur=100ms, freq=415Hz, sample=66, buffer_id=12:42 [TRUNCATE prev:ch0 @146630.1ms -> 146844.4ms]
    db 0,0,100,0,92,127,1,1,224,6,92,1  ; n5725 t=146.880s dur=100ms, freq=1760Hz, sample=92, buffer_id=01:5C [TRUNCATE prev:ch1 @146630.1ms -> 146880.1ms]
    db 0,0,100,0,78,127,17,2,112,3,78,16  ; n5726 t=146.880s dur=100ms, freq=880Hz, sample=78, buffer_id=10:4E [TRUNCATE prev:ch2 @146630.1ms -> 146880.1ms]
    db 36,0,100,0,66,127,18,9,184,1,66,18  ; n5727 t=146.880s dur=100ms, freq=440Hz, sample=66, buffer_id=12:42 [TRUNCATE prev:ch9 @146630.1ms -> 146880.1ms]
    db 0,0,100,0,94,127,1,3,73,7,94,1  ; n5728 t=146.916s dur=100ms, freq=1865Hz, sample=94, buffer_id=01:5E [TRUNCATE prev:ch3 @146665.8ms -> 146915.8ms]
    db 0,0,100,0,85,127,2,28,85,4,85,2  ; n5729 t=146.916s dur=100ms, freq=1109Hz, sample=85, buffer_id=02:55 [TRUNCATE prev:ch28 @146630.1ms -> 146915.8ms]
    db 0,0,100,0,86,127,2,29,39,5,86,2  ; n5730 t=146.916s dur=100ms, freq=1319Hz, sample=86, buffer_id=02:56 [TRUNCATE prev:ch29 @146701.6ms -> 146915.8ms]
    db 0,0,100,0,73,127,4,30,42,2,73,4  ; n5731 t=146.916s dur=100ms, freq=554Hz, sample=73, buffer_id=04:49 [TRUNCATE prev:ch30 @146630.1ms -> 146915.8ms]
    db 0,0,100,0,74,127,4,31,147,2,74,4  ; n5732 t=146.916s dur=100ms, freq=659Hz, sample=74, buffer_id=04:4A [TRUNCATE prev:ch31 @146701.6ms -> 146915.8ms]
    db 0,0,100,0,62,127,5,15,74,1,62,5  ; n5733 t=146.916s dur=100ms, freq=330Hz, sample=62, buffer_id=05:3E [TRUNCATE prev:ch15 @146701.6ms -> 146915.8ms]
    db 0,0,100,0,61,127,6,4,21,1,61,5  ; n5734 t=146.916s dur=100ms, freq=277Hz, sample=61, buffer_id=05:3D [TRUNCATE prev:ch4 @146665.8ms -> 146915.8ms]
    db 0,0,100,0,85,127,17,8,164,3,85,16  ; n5735 t=146.916s dur=100ms, freq=932Hz, sample=85, buffer_id=10:55 [TRUNCATE prev:ch8 @146665.8ms -> 146915.8ms]
    db 36,0,100,0,73,127,18,0,210,1,73,18  ; n5736 t=146.916s dur=100ms, freq=466Hz, sample=73, buffer_id=12:49 [TRUNCATE prev:ch0 @146844.4ms -> 146915.8ms]
    db 0,0,100,0,94,127,1,5,184,7,94,1  ; n5737 t=146.952s dur=100ms, freq=1976Hz, sample=94, buffer_id=01:5E [TRUNCATE prev:ch5 @146844.4ms -> 146951.6ms]
    db 0,0,100,0,85,127,17,6,220,3,85,16  ; n5738 t=146.952s dur=100ms, freq=988Hz, sample=85, buffer_id=10:55 [TRUNCATE prev:ch6 @146844.4ms -> 146951.6ms]
    db 36,0,100,0,73,127,18,7,238,1,73,18  ; n5739 t=146.952s dur=100ms, freq=494Hz, sample=73, buffer_id=12:49 [TRUNCATE prev:ch7 @146844.4ms -> 146951.6ms]
    db 0,0,125,0,86,127,2,10,151,4,86,2  ; n5740 t=146.987s dur=125ms, freq=1175Hz, sample=86, buffer_id=02:56 [TRUNCATE prev:ch10 @146844.4ms -> 146987.3ms]
    db 0,0,125,0,90,127,2,11,117,5,90,2  ; n5741 t=146.987s dur=125ms, freq=1397Hz, sample=90, buffer_id=02:5A [TRUNCATE prev:ch11 @146844.4ms -> 146987.3ms]
    db 0,0,125,0,74,127,4,12,75,2,74,4  ; n5742 t=146.987s dur=125ms, freq=587Hz, sample=74, buffer_id=04:4A [TRUNCATE prev:ch12 @146844.4ms -> 146987.3ms]
    db 0,0,125,0,78,127,4,13,186,2,78,4  ; n5743 t=146.987s dur=125ms, freq=698Hz, sample=78, buffer_id=04:4E [TRUNCATE prev:ch13 @146844.4ms -> 146987.3ms]
    db 0,0,125,0,66,127,5,14,93,1,66,5  ; n5744 t=146.987s dur=125ms, freq=349Hz, sample=66, buffer_id=05:42 [TRUNCATE prev:ch14 @146844.4ms -> 146987.3ms]
    db 100,3,125,0,62,127,6,16,38,1,62,5  ; n5745 t=146.987s dur=125ms, freq=294Hz, sample=62, buffer_id=05:3E [TRUNCATE prev:ch16 @146844.4ms -> 146987.3ms]
    db 80,0,100,0,47,127,10,0,123,0,47,10  ; n5746 t=147.855s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 80,0,100,0,47,127,10,1,123,0,47,10  ; n5747 t=147.935s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 79,0,100,0,47,127,10,2,123,0,47,10  ; n5748 t=148.015s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 80,0,100,0,47,127,10,3,123,0,47,10  ; n5749 t=148.094s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 79,0,100,0,47,127,10,4,123,0,47,10  ; n5750 t=148.174s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 79,0,100,0,47,127,10,5,123,0,47,10  ; n5751 t=148.254s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 79,0,100,0,47,127,10,6,123,0,47,10  ; n5752 t=148.332s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 80,0,100,0,47,127,10,7,123,0,47,10  ; n5753 t=148.412s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 80,0,100,0,47,127,10,8,123,0,47,10  ; n5754 t=148.492s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 79,0,100,0,47,127,10,9,123,0,47,10  ; n5755 t=148.572s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 79,0,100,0,47,127,10,10,123,0,47,10  ; n5756 t=148.651s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 79,0,100,0,47,127,10,11,123,0,47,10  ; n5757 t=148.730s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 80,0,100,0,47,127,10,12,123,0,47,10  ; n5758 t=148.809s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 80,0,100,0,47,127,10,13,123,0,47,10  ; n5759 t=148.889s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 80,0,100,0,47,127,10,14,123,0,47,10  ; n5760 t=148.969s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 80,0,100,0,47,127,10,15,123,0,47,10  ; n5761 t=149.048s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 80,0,100,0,47,127,10,16,123,0,47,10  ; n5762 t=149.129s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 78,0,100,0,47,127,10,17,123,0,47,10  ; n5763 t=149.208s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 80,0,100,0,47,127,10,18,123,0,47,10  ; n5764 t=149.286s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 79,0,100,0,47,127,10,19,123,0,47,10  ; n5765 t=149.367s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 80,0,100,0,47,127,10,20,123,0,47,10  ; n5766 t=149.446s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 79,0,100,0,47,127,10,21,123,0,47,10  ; n5767 t=149.526s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 176,1,100,0,47,127,10,22,123,0,47,10  ; n5768 t=149.605s dur=100ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 2,0,84,1,47,127,10,23,123,0,47,10  ; n5769 t=150.037s dur=340ms, freq=123Hz, sample=47, buffer_id=0A:2F
    db 0,0,100,0,47,127,12,0,123,0,47,11  ; n5770 t=150.039s dur=100ms, freq=123Hz, sample=47, buffer_id=0B:2F
    db 0,0,100,0,35,127,13,1,62,0,35,13  ; n5771 t=150.039s dur=100ms, freq=62Hz, sample=35, buffer_id=0D:23
    db 0,0,100,0,47,127,19,2,123,0,47,19  ; n5772 t=150.039s dur=100ms, freq=123Hz, sample=47, buffer_id=13:2F
    db 108,1,100,0,35,127,20,3,62,0,35,20  ; n5773 t=150.039s dur=100ms, freq=62Hz, sample=35, buffer_id=14:23
    db 0,0,100,0,92,127,1,0,125,6,92,1  ; n5774 t=150.403s dur=100ms, freq=1661Hz, sample=92, buffer_id=01:5C
    db 0,0,113,0,86,127,2,1,151,4,86,2  ; n5775 t=150.403s dur=113ms, freq=1175Hz, sample=86, buffer_id=02:56
    db 0,0,113,0,90,127,2,2,200,5,90,2  ; n5776 t=150.403s dur=113ms, freq=1480Hz, sample=90, buffer_id=02:5A
    db 0,0,159,0,85,127,3,3,220,3,85,3  ; n5777 t=150.403s dur=159ms, freq=988Hz, sample=85, buffer_id=03:55
    db 0,0,113,0,74,127,4,4,75,2,74,4  ; n5778 t=150.403s dur=113ms, freq=587Hz, sample=74, buffer_id=04:4A
    db 0,0,113,0,78,127,4,5,228,2,78,4  ; n5779 t=150.403s dur=113ms, freq=740Hz, sample=78, buffer_id=04:4E
    db 0,0,113,0,66,127,5,6,114,1,66,5  ; n5780 t=150.403s dur=113ms, freq=370Hz, sample=66, buffer_id=05:42
    db 0,0,113,0,62,127,6,7,38,1,62,5  ; n5781 t=150.403s dur=113ms, freq=294Hz, sample=62, buffer_id=05:3E
    db 0,0,120,0,62,127,7,8,38,1,62,7  ; n5782 t=150.403s dur=120ms, freq=294Hz, sample=62, buffer_id=07:3E
    db 0,0,159,0,71,127,7,9,238,1,71,7  ; n5783 t=150.403s dur=159ms, freq=494Hz, sample=71, buffer_id=07:47
    db 0,0,159,0,66,127,9,10,114,1,66,9  ; n5784 t=150.403s dur=159ms, freq=370Hz, sample=66, buffer_id=09:42
    db 0,0,159,0,78,127,9,11,228,2,78,9  ; n5785 t=150.403s dur=159ms, freq=740Hz, sample=78, buffer_id=09:4E
    db 0,0,159,0,54,127,11,12,185,0,54,11  ; n5786 t=150.403s dur=159ms, freq=185Hz, sample=54, buffer_id=0B:36
    db 0,0,159,0,59,127,11,13,247,0,59,11  ; n5787 t=150.403s dur=159ms, freq=247Hz, sample=59, buffer_id=0B:3B
    db 0,0,100,0,50,127,12,14,147,0,50,11  ; n5788 t=150.403s dur=100ms, freq=147Hz, sample=50, buffer_id=0B:32
    db 0,0,159,0,47,127,13,15,123,0,47,13  ; n5789 t=150.403s dur=159ms, freq=123Hz, sample=47, buffer_id=0D:2F
    db 0,0,159,0,97,127,16,16,184,7,97,16  ; n5790 t=150.403s dur=159ms, freq=1976Hz, sample=97, buffer_id=10:61
    db 0,0,100,0,78,127,17,17,63,3,78,16  ; n5791 t=150.403s dur=100ms, freq=831Hz, sample=78, buffer_id=10:4E
    db 0,0,100,0,66,127,18,18,159,1,66,18  ; n5792 t=150.403s dur=100ms, freq=415Hz, sample=66, buffer_id=12:42
    db 0,0,159,0,59,127,19,19,247,0,59,19  ; n5793 t=150.403s dur=159ms, freq=247Hz, sample=59, buffer_id=13:3B
    db 45,0,159,0,47,127,20,20,123,0,47,20  ; n5794 t=150.403s dur=159ms, freq=123Hz, sample=47, buffer_id=14:2F
    db 0,0,100,0,92,127,1,21,224,6,92,1  ; n5795 t=150.448s dur=100ms, freq=1760Hz, sample=92, buffer_id=01:5C
    db 0,0,100,0,78,127,17,22,112,3,78,16  ; n5796 t=150.448s dur=100ms, freq=880Hz, sample=78, buffer_id=10:4E
    db 46,0,100,0,66,127,18,24,184,1,66,18  ; n5797 t=150.448s dur=100ms, freq=440Hz, sample=66, buffer_id=12:42
    db 0,0,100,0,94,127,1,25,73,7,94,1  ; n5798 t=150.494s dur=100ms, freq=1865Hz, sample=94, buffer_id=01:5E
    db 0,0,113,0,85,127,2,26,85,4,85,2  ; n5799 t=150.494s dur=113ms, freq=1109Hz, sample=85, buffer_id=02:55
    db 0,0,113,0,90,127,2,27,117,5,90,2  ; n5800 t=150.494s dur=113ms, freq=1397Hz, sample=90, buffer_id=02:5A
    db 0,0,113,0,73,127,4,28,42,2,73,4  ; n5801 t=150.494s dur=113ms, freq=554Hz, sample=73, buffer_id=04:49
    db 0,0,113,0,78,127,4,29,186,2,78,4  ; n5802 t=150.494s dur=113ms, freq=698Hz, sample=78, buffer_id=04:4E
    db 0,0,113,0,66,127,5,30,93,1,66,5  ; n5803 t=150.494s dur=113ms, freq=349Hz, sample=66, buffer_id=05:42
    db 0,0,113,0,61,127,6,31,21,1,61,5  ; n5804 t=150.494s dur=113ms, freq=277Hz, sample=61, buffer_id=05:3D
    db 0,0,100,0,85,127,17,23,164,3,85,16  ; n5805 t=150.494s dur=100ms, freq=932Hz, sample=85, buffer_id=10:55 [TRUNCATE prev:ch23 @150036.9ms -> 150493.8ms]
    db 45,0,100,0,73,127,18,0,210,1,73,18  ; n5806 t=150.494s dur=100ms, freq=466Hz, sample=73, buffer_id=12:49 [TRUNCATE prev:ch0 @150402.8ms -> 150493.8ms]
    db 0,0,141,0,94,127,1,1,184,7,94,1  ; n5807 t=150.539s dur=141ms, freq=1976Hz, sample=94, buffer_id=01:5E [TRUNCATE prev:ch1 @150402.8ms -> 150539.2ms]
    db 0,0,159,0,85,127,17,2,220,3,85,16  ; n5808 t=150.539s dur=159ms, freq=988Hz, sample=85, buffer_id=10:55 [TRUNCATE prev:ch2 @150402.8ms -> 150539.2ms]
    db 46,0,159,0,73,127,18,3,238,1,73,18  ; n5809 t=150.539s dur=159ms, freq=494Hz, sample=73, buffer_id=12:49 [TRUNCATE prev:ch3 @150402.8ms -> 150539.2ms]
    db 0,0,159,0,86,127,2,4,151,4,86,2  ; n5810 t=150.585s dur=159ms, freq=1175Hz, sample=86, buffer_id=02:56 [TRUNCATE prev:ch4 @150402.8ms -> 150584.7ms]
    db 0,0,159,0,90,127,2,5,200,5,90,2  ; n5811 t=150.585s dur=159ms, freq=1480Hz, sample=90, buffer_id=02:5A [TRUNCATE prev:ch5 @150402.8ms -> 150584.7ms]
    db 0,0,159,0,74,127,4,6,75,2,74,4  ; n5812 t=150.585s dur=159ms, freq=587Hz, sample=74, buffer_id=04:4A [TRUNCATE prev:ch6 @150402.8ms -> 150584.7ms]
    db 0,0,159,0,78,127,4,7,228,2,78,4  ; n5813 t=150.585s dur=159ms, freq=740Hz, sample=78, buffer_id=04:4E [TRUNCATE prev:ch7 @150402.8ms -> 150584.7ms]
    db 0,0,159,0,66,127,5,8,114,1,66,5  ; n5814 t=150.585s dur=159ms, freq=370Hz, sample=66, buffer_id=05:42 [TRUNCATE prev:ch8 @150402.8ms -> 150584.7ms]
    db 0,0,159,0,62,127,6,9,38,1,62,5  ; n5815 t=150.585s dur=159ms, freq=294Hz, sample=62, buffer_id=05:3E [TRUNCATE prev:ch9 @150402.8ms -> 150584.7ms]
    db 255,255,255,255,255,255,255,255,255,255,255,255  ; End marker

; 1 Shift
    bit 0,(ix+0)
    jp z,@F
@@:
; 2 Ctrl
    bit 1,(ix+0)
    jp z,@F
@@:
; 3 Alt
    bit 2,(ix+0)
    jp z,@F
@@:
; 4 LeftShift
    bit 3,(ix+0)
    jp z,@F
@@:
; 5 LeftCtrl
    bit 4,(ix+0)
    jp z,@F
@@:
; 6 LeftAlt
    bit 5,(ix+0)
    jp z,@F
@@:
; 7 RightShift
    bit 6,(ix+0)
    jp z,@F
@@:
; 8 RightCtrl
    bit 7,(ix+0)
    jp z,@F
@@:
; 9 RightAlt
    bit 0,(ix+1)
    jp z,@F
@@:
; 10 MouseSelect
    bit 1,(ix+1)
    jp z,@F
@@:
; 11 MouseMenu
    bit 2,(ix+1)
    jp z,@F
@@:
; 12 MouseAdjust
    bit 3,(ix+1)
    jp z,@F


@@:
; 17 Q
    bit 0,(ix+2)
    jp z,@F
@@:
; 18 Num3
    bit 1,(ix+2)
    jp z,@F
@@:
; 19 Num4
    bit 2,(ix+2)
    jp z,@F
@@:
; 20 Num5
    bit 3,(ix+2)
    jp z,@F
@@:
; 21 F4
    bit 4,(ix+2)
    jp z,@F
@@:
; 22 Num8
    bit 5,(ix+2)
    jp z,@F
@@:
; 23 F7
    bit 6,(ix+2)
    jp z,@F
@@:
; 24 Minus
    bit 7,(ix+2)
    jp z,@F
@@:
; 25 Hat
    bit 0,(ix+3)
    jp z,@F
@@:
; 26 Left
    bit 1,(ix+3)
    jp z,@F
@@:
; 27 Kpd6
    bit 2,(ix+3)
    jp z,@F
@@:
; 28 Kpd7
    bit 3,(ix+3)
    jp z,@F
@@:
; 29 F11
    bit 4,(ix+3)
    jp z,@F
@@:
; 30 F12
    bit 5,(ix+3)
    jp z,@F
@@:
; 31 F10
    bit 6,(ix+3)
    jp z,@F
@@:
; 32 ScrollLock
    bit 7,(ix+3)
    jp z,@F
@@:
; 33 F0
    bit 0,(ix+4)
    jp z,@F
@@:
; 34 W
    bit 1,(ix+4)
    jp z,@F
@@:
; 35 E
    bit 2,(ix+4)
    jp z,@F
@@:
; 36 T
    bit 3,(ix+4)
    jp z,@F
@@:
; 37 Num7
    bit 4,(ix+4)
    jp z,@F
@@:
; 38 I
    bit 5,(ix+4)
    jp z,@F
@@:
; 39 Num9
    bit 6,(ix+4)
    jp z,@F
@@:
; 40 Num0
    bit 7,(ix+4)
    jp z,@F
@@:
; 41 Underscore
    bit 0,(ix+5)
    jp z,@F
@@:
; 42 Down
    bit 1,(ix+5)
    jp z,@F
@@:
; 43 Kpd8
    bit 2,(ix+5)
    jp z,@F
@@:
; 44 Kpd9
    bit 3,(ix+5)
    jp z,@F
@@:
; 45 Break
    bit 4,(ix+5)
    jp z,@F
@@:
; 46 Tilde
    bit 5,(ix+5)
    jp z,@F
@@:
; 48 Backspace
    bit 7,(ix+5)
    jp z,@F
@@:
; 49 Num1
    bit 0,(ix+6)
    jp z,@F
@@:
; 50 Num2
    bit 1,(ix+6)
    jp z,@F
@@:
; 51 D
    bit 2,(ix+6)
    jp z,@F
@@:
; 52 R
    bit 3,(ix+6)
    jp z,@F
@@:
; 53 Num6
    bit 4,(ix+6)
    jp z,@F
@@:
; 54 U
    bit 5,(ix+6)
    jp z,@F
@@:
; 55 O
    bit 6,(ix+6)
    jp z,@F
@@:
; 56 P
    bit 7,(ix+6)
    jp z,@F
@@:
; 57 LeftBracket
    bit 0,(ix+7)
    jp z,@F
@@:
; 58 Up
    bit 1,(ix+7)
    jp z,@F
@@:
; 59 KpdPlus
    bit 2,(ix+7)
    jp z,@F
@@:
; 60 KpdMinus
    bit 3,(ix+7)
    jp z,@F
@@:
; 61 KpdEnter
    bit 4,(ix+7)
    jp z,@F
@@:
; 62 Insert
    bit 5,(ix+7)
    jp z,@F
@@:
; 63 Home
    bit 6,(ix+7)
    jp z,@F
@@:
; 64 PgUp
    bit 7,(ix+7)
    jp z,@F
@@:
; 65 Caps
    bit 0,(ix+8)
    jp z,@F
@@:
; 66 A
    bit 1,(ix+8)
    jp z,@F
@@:
; 67 X
    bit 2,(ix+8)
    jp z,@F
@@:
; 68 F
    bit 3,(ix+8)
    jp z,@F
@@:
; 69 Y
    bit 4,(ix+8)
    jp z,@F
@@:
; 70 J
    bit 5,(ix+8)
    jp z,@F
@@:
; 71 K
    bit 6,(ix+8)
    jp z,@F
@@:
; 72 At
    bit 7,(ix+8)
    jp z,@F
@@:
; 73 Colon
    bit 0,(ix+9)
    jp z,@F
@@:
; 74 Enter
    bit 1,(ix+9)
    jp z,@F
@@:
; 75 KpdFwdSlash
    bit 2,(ix+9)
    jp z,@F
@@:
; 76 KpdDel
    bit 3,(ix+9)
    jp z,@F
@@:
; 77 KpdDot
    bit 4,(ix+9)
    jp z,@F
@@:
; 78 NumLock
    bit 5,(ix+9)
    jp z,@F
@@:
; 79 PgDn
    bit 6,(ix+9)
    jp z,@F
@@:
; 81 ShiftLock
    bit 0,(ix+10)
    jp z,@F
@@:
; 82 S
    bit 1,(ix+10)
    jp z,@F
@@:
; 83 C
    bit 2,(ix+10)
    jp z,@F
@@:
; 84 G
    bit 3,(ix+10)
    jp z,@F
@@:
; 85 H
    bit 4,(ix+10)
    jp z,@F
@@:
; 86 N
    bit 5,(ix+10)
    jp z,@F
@@:
; 87 L
    bit 6,(ix+10)
    jp z,@F
@@:
; 88 Semicolon
    bit 7,(ix+10)
    jp z,@F
@@:
; 89 RightBracket
    bit 0,(ix+11)
    jp z,@F
@@:
; 90 Delete
    bit 1,(ix+11)
    jp z,@F
@@:
; 92 KpdStar
    bit 3,(ix+11)
    jp z,@F
@@:
; 93 KpdComma
    bit 4,(ix+11)
    jp z,@F
@@:
; 94 KpdPlus
    bit 5,(ix+11)
    jp z,@F
@@:
; 96 Underscore1
    bit 7,(ix+11)
    jp z,@F
@@:
; 97 Tab
    bit 0,(ix+12)
    jp z,@F
@@:
; 98 Z
    bit 1,(ix+12)
    jp z,@F
@@:
; 99 Space
    bit 2,(ix+12)
    jp z,@F
@@:
; 100 V
    bit 3,(ix+12)
    jp z,@F
@@:
; 101 B
    bit 4,(ix+12)
    jp z,@F
@@:
; 102 M
    bit 5,(ix+12)
    jp z,@F
@@:
; 103 Comma
    bit 6,(ix+12)
    jp z,@F
@@:
; 104 Dot
    bit 7,(ix+12)
    jp z,@F
@@:
; 105 ForwardSlash
    bit 0,(ix+13)
    jp z,@F
@@:
; 106 CopyEnd
    bit 1,(ix+13)
    jp z,@F
@@:
; 107 Kpd0
    bit 2,(ix+13)
    jp z,@F
@@:
; 108 Kpd1
    bit 3,(ix+13)
    jp z,@F
@@:
; 109 Kpd3
    bit 4,(ix+13)
    jp z,@F
@@:
; 113 Escape
    bit 0,(ix+14)
    jp z,@F
@@:
; 114 F1
    bit 1,(ix+14)
    jp z,@F
@@:
; 115 F2
    bit 2,(ix+14)
    jp z,@F
@@:
; 116 F3
    bit 3,(ix+14)
    jp z,@F
@@:
; 117 F5
    bit 4,(ix+14)
    jp z,@F
@@:
; 118 F6
    bit 5,(ix+14)
    jp z,@F
@@:
; 119 F8
    bit 6,(ix+14)
    jp z,@F
@@:
; 120 F9
    bit 7,(ix+14)
    jp z,@F
@@:
; 122 Right
    bit 1,(ix+15)
    jp z,@F
@@:
; 123 Kpd4
    bit 2,(ix+15)
    jp z,@F
@@:
; 124 Kpd5
    bit 3,(ix+15)
    jp z,@F
@@:
; 125 Kpd2
    bit 4,(ix+15)
    jp z,@F
@@:
; 126 WinLeft
    bit 5,(ix+15)
    jp z,@F
@@:
; 127 WinRight
    bit 6,(ix+15)
    jp z,@F
@@:
; 128 WinMenu22223
    bit 7,(ix+15)
    jp z,@F
@@:

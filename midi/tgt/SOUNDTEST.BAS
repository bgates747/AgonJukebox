    1 FOR I = 3 TO 31 : VDU 23,0,&85,I,8 : NEXT I
    2 FOR I = 0 TO 31 : VDU 23,0,&85,I,4,1 : NEXT I
   10 FOR I = 0 TO 31
   20   CH = I : PCH = I * 4 + 30
   30   SOUND CH, -15, PCH, 20
   40   PRINT I
   50 NEXT I

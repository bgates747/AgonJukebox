10 INPUT"Song file name" ; filename$
20 compat=OPENUP(filename$)
30 IF compat=0 THEN PRINT "File "; filename$; " not found, try again.": GOTO 10
40 PRINT "File "; filename$; " opened as handle ";compat
50 PRINT
60 PRINT " CHANNEL"," VOLUME"," FREQUENCY"," DURATION"," WAIT"
70 PRINT " -------"," ------"," ---------"," --------"," ----"
80 REPEAT
90 cha=VAL(FN_read) : vol=VAL(FN_read) : fre=VAL(FN_read) : dur=VAL(FN_read) : wai=VAL(FN_read)
100 PRINT cha,vol,fre,dur,wai
110 UNTIL FALSE
340 DEF FN_read
350 LOCAL data$,byte$,byte
360 data$=""
370 REPEAT
380 byte=BGET#compat
390 IF byte=&1A OR EOF#compat THEN CLOSE#compat: END
400 IF NOT(byte=&0A OR byte=&0D OR byte=&2C) THEN data$=data$+CHR$(byte)
410 UNTIL byte=&0D OR byte=&2C
420 =data$

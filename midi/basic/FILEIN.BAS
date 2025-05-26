 10 REM F-RSTD
 20 :
 30 REM EXAMPLE OF READING A COMPATIBLE FILE
 40 :
 50 REM This program opens a data file and reads
 60 REM numeric and character data from it.  The
 70 REM data is read a byte at a time and the
 80 REM appropriate action taken depending on
 90 REM whether it is a character, a comma, or
100 REM a control char.
110 compat=OPENUP("COMPAT")
120 PRINT "File Name COMPAT Opened as Handle ";compat
130 PRINT
140 REPEAT
150   name$=FN_read
160   PRINT "Name ";name$
170   age=VAL(FN_read)
180   PRINT "Age ";age
190   height=VAL(FN_read)
200   PRINT "Height in centimetres ";height
210   sex$=FN_read
220   IF sex$="M" THEN PRINT "Male" ELSE PRINT "Female"
230   PRINT
240 UNTIL FALSE
250 :
260 :
270 REM Read a data item from the file.  Treat
280 REM commas and CRs as data item terminators
290 REM and Control Z as the file terminator.
300 REM Since we are not interested in reading a
310 REM record at a time, the record terminator
320 REM CR LF is of no special interest to us.
330 REM We use the CR, along with commas, as a
332 REM data item separator and discard the LF.
334 :
340 DEF FN_read
350 LOCAL data$,byte$,byte
360 data$=""
370 REPEAT
380   byte=BGET#compat
390   IF byte=&1A OR EOF#compat THEN CLOSE#compat: END
400   IF NOT(byte=&0A OR byte=&0D OR byte=&2C) THEN data$=data$+CHR$(byte)
410 UNTIL byte=&0D OR byte=&2C
420 =data$
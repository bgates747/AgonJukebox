  10 REM F-WSTD
  20 :
  30 REM EXAMPLE OF WRITING A COMPATIBLE FILE
  40 :
  50 REM This program opens a file and writes
  60 REM numeric and character data to it in a
  70 REM compatible format.  Numerics are changed
  80 REM to strings before they are written and
  90 REM the data items are separated by commas.
 100 REM Each record is terminated by CR LF and
 110 REM the file is terminated by a Control Z.
 120 :
 130 REM Functions are used to accept and
 140 REM validate the data before writing it to
 150 REM the file.
 160 :
 170 record$=STRING$(100," "): REM Reserve room for the longest
 180 name$=STRING$(20," "): REM record necessary.
 190 : REM It saves on string space.
 200 compat=OPENOUT("COMPAT")
 210 PRINT "File Name COMPAT Opened as Handle ";compat
 220 PRINT
 230 REPEAT
 240   name$=FN_name
 250   IF name$="" THEN PROC_end
 260   age=FN_age
 270   height=FN_height
 280   sex$=FN_sex
 290   PRINT
 300   record$=name$+","+STR$(age)+","+STR$(height)+","+sex$
 310   PRINT#compat,record$
 320   BPUT#compat,&0A
 330 UNTIL FALSE
 340 :
 350 DEF PROC_end
 360 BPUT#compat,&1A
 370 CLOSE#compat
 380 END
 390 :
 400 :
 410 REM Accept a name from the keyboard and make
 420 REM sure it consists only of spaces and
 430 REM upper or lower case characters. Leading
 440 REM spaces are ignored on input.
 450 :
 460 DEF FN_name
 470 LOCAL name$,FLAG,n
 480 REPEAT
 490   FLAG=TRUE
 500   INPUT "Name ? " name$
 510   IF name$="" THEN 570
 520   FOR I=1 TO LEN(name$)
 530     n=ASC(MID$(name$,I,1))
 540     IF NOT(n=32 OR n>64 AND n<91 OR n>96 AND n<123) THEN FLAG=TRUE
 550   NEXT
 560   IF NOT FLAG THEN PRINT "No funny characters please !!!"
 570 UNTIL FLAG
 580 =name$
 590 :
 600 :
 610 REM Accept the age from the keyboard and
 620 REM round to one place of decimals.  Ages
 630 REM of 0 or less or 150 or more are
 640 REM considered to be in error.
 650 DEF FN_age
 660 LOCAL age
 670 REPEAT
 680   INPUT "What age ? " age
 690   IF age<=0 OR age >=150 THEN PRINT "No impossible ages please !!!"
 700 UNTIL age>0 AND age<150
 710 =INT(age*10+.5)/10
 720 :
 730 :
 740 REM Accept the height in centimetres from
 750 REM the keyboard and round to an integer.
 760 REM Heights of 50 or less and 230 or more
 770 REM are considered to be in error.
 780 DEF FN_height
 790 LOCAL height
 800 REPEAT
 810   INPUT "Height in centimetres ? " height
 820   IF height<=50 OR height>=230 THEN PRINT "Very funny !!!"
 830 UNTIL height>50 AND height<230
 840 =INT(height+.5)
 850 :
 860 :
 870 REM Accept the sex from the keyboard. Only
 880 REM words beginning with upper or lower
 890 REM case M or F are valid.  The returned
 900 REM string is truncated to 1 character.
 910 DEF FN_sex
 920 LOCAL sex$,FLAG
 930 REPEAT
 940   FLAG=TRUE
 950   INPUT "Male or Female - M or F ? " sex$
 960   IF sex$<>"" THEN sex$=CHR$(ASC(MID$(sex$,1,1)) AND 95)
 970   IF sex$<>"M" AND sex$<>"F" THEN FLAG=FALSE
 980   IF NOT FLAG THEN PRINT "No more sex(es) please !!!"
 990 UNTIL FLAG
1000 =sex$
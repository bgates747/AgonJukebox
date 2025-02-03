CFLAGS = -O6 -Wall -fomit-frame-pointer -funroll-loops
NAME = szip_112b_$(shell uname)_$(shell uname -m).tar
%.exe : %

all: $(NAME).gz test
szip: bitmodel.c bitmodel.h comp.c port.h qsmodel.c qsmodel.h rangecod.c rangecod.h reorder.c reorder.h sz_bit.c sz_bit.h sz_err.h sz_mod4.c sz_mod4.h qsort_u4.c sz_srt.c sz_srt.h szip.c
	$(CC) $(CFLAGS) comp.c -o szip
	strip szip
check: check.c
	$(CC) $(CFLAGS) check.c -o check
test: szip check
	echo The following files had an error: >logfile
	find . -type f -exec ./testszip '{}' logfile ';'
	echo -- end of list -- >>logfile
	more logfile
fulltest: szip check
	echo full test: The following files had an error: >logfile
	find / -mtime +1 -type f -perm +4 -exec ./testszip '{}' logfile ';'
	echo -- end of list -- >>logfile
	more logfile
$(NAME).gz: szip readme.txt techinfo.txt history.txt
	tar -cf $(NAME) szip readme.txt techinfo.txt history.txt
	gzip $(NAME)
clean:
	-rm *.o szip check logfile
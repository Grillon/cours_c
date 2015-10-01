.PHONY: help clean reset list

help:
	@echo "Choose clean, reset, list"

clean:
	\rm -f *~ *.bak

reset: clean
	\rm -f *.o

list:
	@echo "fichiers .c : ";
	@ls *.c ;
	@echo "fichiers .h : ";
	@ls *.h

proc: proc-main.o proc-sign.o proc-fils.o proc-mesg.o
	gcc proc-main.o proc-sign.o proc-fils.o proc-mesg.o -o proc

proc-main.o: proc-main.c proc-fils.h proc-sign.h proc-mesg.h
	gcc proc-main.c -c

proc-sign.o: proc-sign.c proc-sign.h proc-mesg.h
	gcc proc-sign.c -c

proc-mesg.o: proc-mesg.c proc-mesg.h
	gcc proc-mesg.c -c

proc-fils.o: proc-fils.c proc-fils.h proc-mesg.h
	gcc proc-fils.c -c

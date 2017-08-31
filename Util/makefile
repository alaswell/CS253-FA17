#example makefile provided by Bruce in lecture

CC=g++
LFLAGS=-o PA1
CFLAGS=-g -Wall -I. -c

PA1: histogram.o main.o
	$(CC) main.o histogram.o $(LFLAGS)

main.o: main.cpp histogram.h
	$(CC) main.cpp $(CFLAGS)

histogram.o: histogram.cpp histogram.h
	$(CC) histogram.cpp$(CFLAGS)

clear:
	rm -f *.o
	rm -f PA1

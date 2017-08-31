# CS253 Program makefile

CC = g++
INCLUDE = -g -c -Wall -I.

exec: main.o Histogram.o
	$(CC) main.o Histogram.o -o exec1

main.o: main.cpp Histogram.h
	$(CC) $(INCLUDE) main.cpp

Histogram.o: Histogram.cpp Histogram.h
	$(CC) $(INCLUDE) Histogram.cpp

clean: 
	rm -rf *.o exec1

tar: 
	tar -cvf PA1.tar *.cpp *.h makefile

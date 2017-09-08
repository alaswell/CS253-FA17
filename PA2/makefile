# CS253 Program makefile

CC = g++
INCLUDE = -g -c -Wall -I.

exec: main.o Histogram.o
	$(CC) main.o Histogram.o -o exec

main.o: main.cpp Histogram.h
	$(CC) $(INCLUDE) main.cpp

Histogram.o: Histogram.cpp Histogram.h
	$(CC) $(INCLUDE) Histogram.cpp

clean: 
	rm -rf *.o exec 

tar:
	cd ../ && tar -cvf PA2/PA2.tar PA2/*.cpp PA2/*.h PA2/makefile

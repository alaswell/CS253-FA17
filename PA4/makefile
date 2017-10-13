# CS253 Program makefile

PNAME = PA4
CC = g++
CFLAGS = -std=c++11 -g -c -Wall -I.
LFLAGS =-o $(PNAME)

exec: main.o Histogram.o Porter.o
	$(CC) main.o Histogram.o Porter.o $(LFLAGS)

main.o: main.cpp Histogram.h
	$(CC) $(CFLAGS) main.cpp

Histogram.o: Histogram.cpp Histogram.h
	$(CC) $(CFLAGS) Histogram.cpp

Porter.o: Porter.cpp Porter.h
	$(CC) $(CFLAGS) Porter.cpp

clean: 
	rm -f *.o 
	rm -f $(PNAME)

tar:
	cd ../ && tar -cvf $(PNAME)/$(PNAME).tar $(PNAME)/*.cpp $(PNAME)/*.h $(PNAME)/makefile

# CS253 Program makefile

PNAME = PA3
CC = g++
CFLAGS = -g -c -Wall -I.
LFLAGS =-o $(PNAME)

exec: main.o Histogram.o
	$(CC) main.o Histogram.o $(LFLAGS)

main.o: main.cpp Histogram.h
	$(CC) $(CFLAGS) main.cpp

Histogram.o: Histogram.cpp Histogram.h
	$(CC) $(CFLAGS) Histogram.cpp

clean: 
	rm -f *.o 
	rm -f $(PNAME)

tar:
	cd ../ && tar -cvf $(PNAME)/$(PNAME).tar $(PNAME)/*.cpp $(PNAME)/*.h $(PNAME)/makefile

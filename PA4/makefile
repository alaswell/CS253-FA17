# CS253 Program makefile

PNAME = PA4
CC = g++
CFLAGS = -g -c -Wall -I.
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
	rm -f gtest

tar:
	cd ../ && tar -cvf $(PNAME)/$(PNAME).tar $(PNAME)/*.cpp $(PNAME)/*.h $(PNAME)/makefile

gtest:	Porter.o porterTests.o
	$(CC) $^ -o $@ -lpthread -lgtest

porterTests.o: porterTests.cpp Porter.h
	$(CC) $(CFLAGS) porterTests.cpp

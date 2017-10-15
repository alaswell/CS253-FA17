# CS253 Program makefile

PNAME = PA4
CC = g++
CFLAGS = -std=c++11 -g -c -Wall -Wextra -Wpedantic -Werror -Wfatal-errors -Winit-self -Wshadow -Wlogical-op -Wcomment -Wctor-dtor-privacy -Wold-style-cast -D_GLIBCXX_DEBUG -fno-diagnostics-show-option -I.
LFLAGS =-o $(PNAME)
GFLAGS = -lpthread -lgtest

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
	rm -f gtest*

tar:
	cd ../ && tar -cvf $(PNAME)/$(PNAME).tar $(PNAME)/*.cpp $(PNAME)/*.h $(PNAME)/makefile

gtestPorter: Porter.o porterTests.o
	$(CC) $^ -o $@ $(GFLAGS)

porterTests.o: porterTests.cpp Porter.h
	$(CC) $(CFLAGS) porterTests.cpp

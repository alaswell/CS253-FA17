# CS253 Program makefile

PNAME = PA6
CC = g++
CFLAGS = -std=c++11 -c -I.
WIPFLAGS = -std=c++11 -g -c -I. -Wall -Wextra -Wpedantic -Werror -Wfatal-errors -Winit-self -Wshadow -Wlogical-op -Wcomment -Wctor-dtor-privacy -Wold-style-cast -D_GLIBCXX_DEBUG -fno-diagnostics-show-option
FLAGS = $(CFLAGS)
LFLAGS =-o $(PNAME)
GFLAGS = -lpthread -lgtest

exec: main.o Histogram.o Porter.o Cluster.o
	$(CC) main.o Histogram.o Porter.o Cluster.o $(LFLAGS)

main.o: main.cpp Histogram.h 
	$(CC) $(FLAGS) main.cpp

Histogram.o: Histogram.cpp Histogram.h
	$(CC) $(FLAGS) Histogram.cpp

Porter.o: Porter.cpp Porter.h
	$(CC) $(FLAGS) Porter.cpp

Cluster.o: Cluster.cpp Cluster.h
	$(CC) $(FLAGS) Cluster.cpp

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

# CS253 Program makefile

PNAME = PA9
CC = g++
CFLAGS = -O3 -fopenmp -std=c++14 -c -I.
WIPFLAGS = -std=c++14 -g -c -I. -Wall -Wextra -Wpedantic -Werror -Wfatal-errors -Winit-self -Wshadow -Wlogical-op -Wcomment -Wctor-dtor-privacy -Wold-style-cast -D_GLIBCXX_DEBUG -fno-diagnostics-show-option
FLAGS = $(CFLAGS)
LFLAGS = -fopenmp -o $(PNAME)
GFLAGS = -lpthread -lgtest

all: main.o Histogram.o Porter.o Cluster.o ColemanLiau.o
	$(CC) main.o Histogram.o Porter.o Cluster.o ColemanLiau.o $(LFLAGS)

main.o: main.cpp Histogram.h 
	$(CC) $(FLAGS) main.cpp

Histogram.o: Histogram.cpp Histogram.h
	$(CC) $(FLAGS) Histogram.cpp

Porter.o: Porter.cpp Porter.h
	$(CC) $(FLAGS) Porter.cpp

Cluster.o: Cluster.cpp Cluster.h
	$(CC) $(FLAGS) Cluster.cpp

ColemanLiau.o: ColemanLiau.cpp ColemanLiau.h
	$(CC) $(FLAGS) ColemanLiau.cpp

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

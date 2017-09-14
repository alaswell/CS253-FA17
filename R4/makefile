CC=g++
CFLAGS= -Wall -I . -c -g

PA1: main.o Counter.o
	$(CC) -o PA1 Counter.o main.o

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

Counter.o: Counter.cpp Counter.h
	$(CC) $(CFLAGS) Counter.cpp 

clean:
	rm -rf *.o PA1



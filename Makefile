CC = g++
CFLAGS = -c -Wall -Wextra
TARGET = main

all: $(TARGET)

$(TARGET): main.o SortingAlgorithms.o
	$(CC) -g -Wall -Wextra -o $(TARGET) main.o SortingAlgorithms.o

main.o: main.cpp
	$(CC) -g $(CFLAGS) main.cpp

SortingAlgorithms.o: SortingAlgorithms.h SortingAlgorithms.cpp
	$(CC) -g $(CFLAGS) SortingAlgorithms.cpp

clean:
	$(RM) $(TARGET) *.o *~
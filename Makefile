CC = gcc
CFLAGS = -Wall -Wextra -g -Iinclude

# default target
all: test

# compile object file for myqueue
myqueue.o: src/myqueue.c include/myqueue.h
	$(CC) $(CFLAGS) -c src/myqueue.c -o myqueue.o

# build test executable
test: myqueue.o tests/test.c include/myqueue.h
	$(CC) $(CFLAGS) tests/test.c myqueue.o -o test
	@del /Q myqueue.o 2>nul

# clean up build artifacts
clean:
	del Q/ -f *.o test.exe
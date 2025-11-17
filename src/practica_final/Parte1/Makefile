CC = gcc
CFLAGS = -Wall -Wextra -std=c11

all: main

main: main.o regresion.o
	$(CC) $(CFLAGS) -o main main.o regresion.o

main.o: main.c regresion.h
regresion.o: regresion.c regresion.h

clean:
	rm -f *.o main
CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -lm

all: main

main: main.o simulacion.o
	$(CC) $(CFLAGS) -o main main.o simulacion.o

main.o: main.c simulacion.h
simulacion.o: simulacion.c simulacion.h

clean:
	rm -f *.o main
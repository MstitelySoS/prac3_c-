CC      := gcc
CFLAGS  := -std=c89 -Wall -Wextra -O2

.PHONY: all clean
all: prog1 process

prog1: prog1.c
	$(CC) $(CFLAGS) prog1.c -o prog1

process: process.c
	$(CC) $(CFLAGS) process.c -o process

clean:
	rm -f prog1 process

# Makefile

CC = gcc
CFLAGS = -Wall -Wextra -g -std=gnu89

all: unsafe_functions

unsafe_functions: unsafe_functions.c
	$(CC) $(CFLAGS) unsafe_functions.c -o unsafe_functions

clean:
	rm -f unsafe_functions

CC=gcc     # set the compiler
CFLAGS=-I  # include path flag

all: q1

q1: q1.c q1.h
	$(CC) -I./ q1.c -o q1
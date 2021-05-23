CC = gcc
CFLAGS = -m32 -g -w -Wall -Wextra -pedantic -ansi

all: test_karatsuba

test_karatsuba: test_karatsuba.o
	$(CC) $(CFLAGS) -o test_karatsuba test_karatsuba.o

test_karatsuba.o: tests/test_karatsuba.c sh_karatsuba.h
	$(CC) -c $(CFLAGS) -o test_karatsuba.o -I. tests/test_karatsuba.c

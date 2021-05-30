CC = gcc
CFLAGS = -m32 -g -w -Wall -Wextra -pedantic -ansi

all: test_karatsuba test_bisect

test_karatsuba: test_karatsuba.o
	$(CC) $(CFLAGS) -o test_karatsuba test_karatsuba.o

test_karatsuba.o: tests/test_karatsuba.c sh_karatsuba.h
	$(CC) -c $(CFLAGS) -o test_karatsuba.o -I. tests/test_karatsuba.c

test_bisect: test_bisect.o
	$(CC) $(CFLAGS) -o test_bisect test_bisect.o

test_bisect.o: tests/test_bisect.c sh_bisect.h
	$(CC) -c $(CFLAGS) -o test_bisect.o -I. tests/test_bisect.c


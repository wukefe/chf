
CC = clang
CFILES = main.c token.c
HFILES = token.h common.h
CFLAGS = -std=c99 -g
DEBUG  = lldb

all: main.c token.o parser.o common.h
	$(CC) -o e main.c token.o parser.o $(CFLAGS)


token.o: token.c common.h
	$(CC) -c token.c common.h $(CFLAGS)

parser.o: parser.c parser.h common.h
	$(CC) -c parser.c common.h $(CFLAGS)


r: all
	./e

g: all
	$(DEBUG) ./e
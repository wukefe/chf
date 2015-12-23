
CC = clang
CFILES = main.c token.c
HFILES = token.h common.h

all: main.c token.o common.h
	$(CC) -o token main.c token.o -std=c99


token.o: token.c common.h
	$(CC) -c token.c common.h -std=c99


r: all
	./token
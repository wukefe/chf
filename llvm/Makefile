cc = clang

CFILES = corelib.c main.c
HFILES = chf.h
CFLAGS = -std=c99 -g

main: $(CFILES) $(HFILES) libcore.a
	$(cc) -o main main.c -L. -lcore $(CFLAGS)

libcore.a: $(CFILES) $(HFILES)
	clang -c -fPIC corelib.c -o corelib.o -O2
	ar -rcs libcore.a corelib.o

r: main
	./main
	
clean:
	rm -f *.o main
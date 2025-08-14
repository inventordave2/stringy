 # Makefile for 'Stringy'

compiler=gcc
cflags=-Wpedantic -Wall
debug=-g -DDEBUG
optim=-O0
name=stringy
noexe=-c

tests: stringyd colour
	$(compiler) $(cflags) $(debug) $(optim) -o tests.exe ./$(name)d.o ./tests.c

stringy_d: ./stringy.c ./stringy.h ./str_concat.c ./str_concat.h
	$(compiler) $(cflags) $(debug) $(optim) $(noexe) -o ./$(name)_d.o ./stringy.c

stringy: ./stringy.c ./stringy.h ./str_concat.c ./str_concat.h
	$(compiler) -O3 $(noexe) -o ./$(name).o ./stringy.c

colour:
	$(maketool) -C ./../colour/ colour_d

clean:
	del ./*.o

wipe: clean


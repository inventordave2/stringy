 # Makefile for 'Stringy'

compiler=gcc
cflags=-Wpedantic -Werror -Wall
debug=-g -DDEBUG
optim=-O0
name=stringy
noexe=-c

stringyd: ./stringy.c ./stringy.h ./str_concat.c ./str_concat.h
	$(compiler) $(cflags) $(debug) $(optim) $(noexe) -o ./$(name)d.o ./stringy.c

stringy: ./stringy.c ./stringy.h ./str_concat.c ./str_concat.h
	$(compiler) -O3 $(noexe) -o ./$(name).o ./stringy.c

clean:
	del ./*.o

wipe: clean


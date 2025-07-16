# Makefile for 'Stringy'

compiler=gcc
analysis=-g -DDEBUG -O0
name=stringy
noexe=-c

stringyd: str_concat ./stringy.c ./stringy.h
	$(compiler) $(analysis) ./stringy.c ./$(name)_concat.o $(noexe) -o ./$(name)d.o

str_concat: ./str_concat.c ./str_concat.h
	$(compiler) $(analysis) ./str_concat.c $(noexe) -o ./$(name)_concat.o

clean:
	rm *.o

wipe: clean


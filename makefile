CC = gcc
AR = ar
FLAG = -Wall -g -fPIC

#compile and link all the files
all: StrList

#compile program
StrList: main.o libStrList.a
	$(CC) $(FLAG) -o StrList main.o libStrList.a

#compile library
libStrList.a: StrList.o
	$(AR) -rcs libStrList.a StrList.o

#compile main file
main.o: Main.c StrList.h
	$(CC) $(FLAG) -c Main.c -o main.o

#compile object file
StrList.o: StrList.c StrList.h
	$(CC) $(FLAG) -c StrList.c -o StrList.o


#to ensure that there isnt a "clean"/"all" file in the directory
.PHONY: clean all

#clean all the compiled files and leave the .txt/ .c / .h files
clean:
	rm -f *.o *.a *.so StrList
CC = gcc
AR = ar
FLAG = -Wall -g -fPIC

#compile and link all the files
all: StrList

#compile the main
Strlist: Main.o 
	$(CC) $(FLAG) -o my_graph my_graph.o 

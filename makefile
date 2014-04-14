CC=g++
CFLAGS = -W -Wall -pedantic -ansi
PROG = prog

CODE = main.cpp heap.cpp

prog: main.cpp heap.cpp
	$(CC) -o $(PROG) $(CODE) $(CFLAGS)
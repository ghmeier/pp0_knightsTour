knightsTour: main.o
	gcc main.o -o knightsTour

main.o: main.h main.c
	gcc main.c -c -Wall

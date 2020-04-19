all: program

program: main QuickSort
	gcc -o Ordenamientos QuickSort main.o QuickSort.o

QuickSort: QuickSort.c QuickSort.h
	gcc -c QuickSort.c

main: main.c QuickSort.h
	gcc -c main.c
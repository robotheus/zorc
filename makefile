all: tp2

file.o: file.h file.c
	gcc -c file.c

grafo.o: grafo.h grafo.c
	gcc -c grafo.c

main.o: main.c	
	gcc -c main.c

tp2: main.o file.o grafo.o
	gcc main.o file.o grafo.o -o tp2

clean: 
	rm -rf main.o file.o grafo.o saida.txt tp2
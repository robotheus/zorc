all: tp2

file.o: file.h file.c
	gcc -c file.c

estrutura.o: estrutura.h estrutura.c
	gcc -c estrutura.c

heuristica.o: heuristica.h heuristica.c
	gcc -c heuristica.c

main.o: main.c	
	gcc -c main.c

tp2: main.o file.o estrutura.o heuristica.o
	gcc main.o file.o estrutura.o heuristica.o -o tp2

clean: 
	rm -rf main.o file.o estrutura.o heuristica.h saida.txt tp2
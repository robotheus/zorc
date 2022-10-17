#include <stdio.h>
#include "file.h"

FILE *fileInput, *fileOutput;

void open_file(char argv1[], char argv2[]){
    fileInput = fopen(argv1, "r");
    fileOutput = fopen(argv2, "w");

    if(fileInput == NULL) printf("ERRO AO ABRIR O ARQUIVO.\n");
}

int read_file(){
    int x;
    fscanf(fileInput, "%d", &x);
    return x;
}

void close_file(){
    fclose(fileInput);
    fclose(fileOutput);
}

void output1(int habilidade){
    fprintf(fileOutput, "%d ", habilidade);
}

void output2(int vertice, int selecionados){
    fprintf(fileOutput, "%d %d ", vertice, selecionados);
}

void output3(){
    fprintf(fileOutput, "\n");
}
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

void output(int output){
    int write = output;
    fprintf(fileOutput, "%d\n", write);
}
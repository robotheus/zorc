#include <stdio.h>
#include <stdlib.h>
#include "file.h"
#include "grafo.h"

void main(int argc, char *argv[]){
    int **matriz;
    
    open_file(argv[2], argv[4]);
    grafo(matriz);
    close_file();

}
#include <stdio.h>
#include <stdlib.h>
#include "file.h"
#include "estrutura.h"
#include "heuristica.h"

void main(int argc, char *argv[]){
    open_file(argv[2], argv[4]);

    int instancias = read_file(), **matriz, qtdpovos, distancia, peso, qtdcaminhos;
    Povo *povos, *copia_p;
    
    for (int i = 0; i < instancias; i++){
        qtdpovos = read_file();
        distancia = read_file();
        peso = read_file();
        qtdcaminhos = read_file();

        matriz = (int**) malloc(qtdpovos * sizeof(int*));
        povos = malloc(qtdpovos * sizeof(Povo));
        copia_p = malloc(qtdpovos * sizeof(Povo));

        monta_estrutura(matriz, povos, qtdpovos, qtdcaminhos);
        copia_povos(copia_p, povos, qtdpovos);
        heuristica(copia_p, matriz, peso, distancia, qtdpovos);
        limpa_estrutura(qtdpovos, matriz, povos, copia_p);
    }

    close_file();
}
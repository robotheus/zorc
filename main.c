#include <stdio.h>
#include <stdlib.h>
#include "file.h"
#include "estrutura.h"
#include "heuristica.h"

void main(int argc, char *argv[]){
    open_file(argv[2], argv[4]);

    int instancias = read_file(), **matriz, qtdpovos, distancia, peso, caminhos;
    Povo *povos, *copia_povos;
    
    for (int i = 0; i < instancias; i++){
        qtdpovos = read_file();
        distancia = read_file();
        peso = read_file();
        caminhos = read_file();

        matriz = (int**) malloc(qtdpovos * sizeof(int*));
        povos = malloc(qtdpovos * sizeof(Povo));
        copia_povos = malloc(qtdpovos * sizeof(Povo));

        monta_estrutura(matriz, povos, qtdpovos, caminhos);
        copia_estrutura(copia_povos, povos, qtdpovos);
        heuristica(copia_povos, peso, distancia, qtdpovos);
        limpa_estrutura(qtdpovos, matriz, povos, copia_povos);
    }

    close_file();
}
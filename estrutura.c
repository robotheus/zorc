#include <stdio.h>
#include <stdlib.h>
#include "file.h"
#include "estrutura.h"

void monta_estrutura(int **matriz, Povo *povo, int qtdpovos, int caminhos){
    int povoi, povoj;

    //preenche os povos e seus atributos
    for(int i = 0; i < qtdpovos; i++){
        (*(povo + i)).id = read_file();
        (*(povo + i)).peso = read_file();
        (*(povo + i)).habilidade = read_file();
        (*(povo + i)).razao = (double)((*(povo + i)).peso) / ((*(povo + i)).habilidade);
    }

    //aloca a matriz adjacencia
    for(int l = 0; l < qtdpovos; l++){
        *(matriz + l) = (int*) malloc(qtdpovos * sizeof(int*));
    }

    //preenche a matriz de adjacencia com distancia nao utilizada
    for(int m = 0; m < qtdpovos; m++){
        for(int j = 0; j < qtdpovos; j++){
            *(*(matriz + m) + j) = -1;
        }
    }
    
    //adiciona as arestas na matriz de adjacencia
    for(int n = 0; n < caminhos; n++){
        povoi = read_file();
        povoj = read_file();

        *(*(matriz + (povoi - 1)) + (povoj - 1)) = read_file();      
    }
}

void limpa_estrutura(int qtdpovos, int **matriz, Povo *povos, Povo *copia_povos){
    for(int r = 0; r < qtdpovos; r++){
        free(*(matriz + r));
    }

    free(povos);
    free(matriz);
    free(copia_povos);  
}

void copia_estrutura(Povo *primeiro, Povo *segundo, int qtdepovos){
    for(int i = 0; i < qtdepovos; i++){
        *(primeiro + i) = *(segundo + i);
    }

    for (int l = 0; l < qtdepovos; l++){
        printf("%d %d %d %lf\n", (*(primeiro + l)).id, (*(primeiro + l)).peso, (*(primeiro + l)).habilidade, (*(primeiro + l)).razao);
    }
    printf("\n");

    for (int l = 0; l < qtdepovos; l++){
        printf("%d %d %d %lf\n", (*(segundo + l)).id, (*(segundo + l)).peso, (*(segundo + l)).habilidade, (*(segundo + l)).razao);
    }
    printf("\n");
}
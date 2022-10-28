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

    //preenche a matriz de adjacencia com uma distancia nao utilizada
    for(int m = 0; m < qtdpovos; m++){
        for(int j = 0; j < qtdpovos; j++){
            if(m == j) *(*(matriz + m) + j) = 0;
            else *(*(matriz + m) + j) = -1;
        }
    }
    
    //adiciona as arestas na matriz de adjacencia
    for(int n = 0; n < caminhos; n++){
        povoi = read_file();
        povoj = read_file();

        *(*(matriz + (povoi - 1)) + (povoj - 1)) = read_file();  
        *(*(matriz + (povoj - 1)) + (povoi - 1)) = *(*(matriz + (povoi - 1)) + (povoj - 1));    
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

void copia_povos(Povo *primeiro, Povo *segundo, int qtdepovos){
    for(int i = 0; i < qtdepovos; i++){
        *(primeiro + i) = *(segundo + i);
    }
}

//ordena os povos da maior razao entre peso e habilidade para a menor
void ordena_povos(Povo *povo, int qtdpovos){
    Povo povo_aux;
    int max;
    
    for(int i = 0; i < (qtdpovos - 1); i++){
        max = i;
        
        for(int j = (i + 1); j < qtdpovos; j++){
            if((*(povo + j)).razao > (*(povo + max)).razao){
                max = j;
            }
        }
        
        if(i != max){
            povo_aux = *(povo + i);
            *(povo + i) = *(povo + max);
            *(povo + max) = povo_aux;
        }
    }
}

//verifica se tem aresta entre dois vertices
int tem_caminho(int **matriz, int v1, int v2){
    if(*(*(matriz + (v1 - 1)) + (v2 - 1)) != -1 || *(*(matriz + (v2 - 1)) + (v1 - 1)) != -1) return 1;
    else return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include "estrutura.h"
#include "heuristica.h"

void heuristica(Povo *povo, int peso, int distancia, int qtdpovos){
    ordena_povos(povo, qtdpovos);
    
    for (int l = 0; l < qtdpovos; l++){
        printf("%d %d %d\n", (*(povo + l)).id, (*(povo + l)).peso, (*(povo + l)).habilidade);
    }
    printf("\n");
}

void ordena_povos(Povo *povo, int qtdpovos){
    Povo *povo_aux;
    int min;
    double *razoes;
    
    povo_aux = malloc(sizeof(Povo));
    razoes = malloc(qtdpovos * sizeof(double));

    for(int k = 0; k < qtdpovos; k++){
        *(razoes + k) = (double)((*(povo + k)).peso) / ((*(povo + k)).habilidade);
    }
    
    for(int i = 0; i < (qtdpovos - 1); i++){
        
        min = i;

        for(int j = (i + 1); j < qtdpovos; j++){
            if((*(razoes + j)) < (*(razoes + min))) {
                min = j;
            }
        }

        printf("menor razao: %lf\n", (*(razoes + min)));
        printf("menor povo: %d %d %d\n", (*(povo + min)).id, (*(povo + min)).peso, (*(povo + min)).habilidade);
        
        if(i != min){
            *(povo_aux) = *(povo + i);
            *(povo + i) = *(povo + min);
            *(povo + min) = *(povo_aux);
        }
    }

    free(povo_aux);
    free(razoes);
}
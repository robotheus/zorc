#include <stdio.h>
#include <stdlib.h>
#include "estrutura.h"
#include "heuristica.h"

void heuristica(Povo *povo, int peso, int distancia, int qtdpovos){
    ordena_povos(povo, qtdpovos);

    for (int l = 0; l < qtdpovos; l++){
        printf("%d %d %d %lf\n", (*(povo + l)).id, (*(povo + l)).peso, (*(povo + l)).habilidade, (*(povo + l)).razao);
    }
    printf("\n");
}

void ordena_povos(Povo *povo, int qtdpovos){
    Povo *povo_aux;
    int min;
    
    povo_aux = malloc(sizeof(Povo));

    for(int i = 1; i < (qtdpovos - 1); i++){
        min = i;
        
        for(int j = (i + 1); j < qtdpovos; j++){
            if((*(povo + j)).razao < (*(povo + min)).razao){
                min = j;
            }
        }

        if(i != min){
            *(povo_aux) = *(povo + i);
            *(povo + i) = *(povo + min);
            *(povo + min) = *(povo_aux);
        }
    }

    free(povo_aux);
}
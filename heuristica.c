#include <stdio.h>
#include <stdlib.h>
#include "estrutura.h"
#include "heuristica.h"
#include "file.h"

void heuristica(Povo *povo, int **matriz, int peso, int distancia, int qtdpovos){
    int anterior = -2, habilidade, selecionados, i = 0;
    Solucao_h *solucao;
    solucao = malloc(qtdpovos * sizeof(Solucao_h));
    Povo atual;

    ordena_povos(povo, qtdpovos);
    
    while(qtdpovos > 0){
        atual = *(povo + (qtdpovos - 1));
        
        if(anterior == -2){
            selecionados = (peso / atual.peso);
            peso -= (selecionados * atual.peso);
            habilidade = selecionados * atual.habilidade;
            anterior = atual.id;
            qtdpovos--;
            
            (*(solucao + i)).id = atual.id;
            (*(solucao + i)).selecionados = selecionados;
            i++;
        } else if(tem_caminho(matriz, atual.id, anterior) == 1 && distancia >= (*(*(matriz + (atual.id - 1)) + anterior - 1))){
            distancia -= *(*(matriz + (atual.id - 1)) + (anterior - 1));            
            selecionados = (peso / atual.peso);
            peso -= (selecionados * atual.peso);
            habilidade += (selecionados * atual.habilidade);
            anterior = atual.id;
            qtdpovos--;
            
            (*(solucao + i)).id = atual.id;
            (*(solucao + i)).selecionados = selecionados;
            i++;
        } else qtdpovos--;
    }

    output1(habilidade);
    for(int k = 0; k < i; k++){
        output2((*(solucao + k)).id, (*(solucao + k)).selecionados);
    }
    output3();

    free(solucao);
}

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

int tem_caminho(int **matriz, int v1, int v2){
    if(*(*(matriz + (v1 - 1)) + (v2 - 1)) != -1 || *(*(matriz + (v2 - 1)) + (v1 - 1)) != -1) return 1;
    else return 0;
}

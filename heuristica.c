#include <stdio.h>
#include <stdlib.h>
#include "estrutura.h"
#include "heuristica.h"
#include "file.h"

void heuristica(Povo *povo, int **matriz, int peso, int distancia, int qtdpovos){
    int anterior = -2, habilidade, selecionados, i = 0;
    Solucao *solucao;
    solucao = malloc(qtdpovos * sizeof(Solucao));
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
    for(int k = i-1; k >= 0; k--){
        output2((*(solucao + k)).id, (*(solucao + k)).selecionados);
    }
    output3();

    free(solucao);
}
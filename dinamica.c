#include <stdio.h>
#include <stdlib.h>
#include "estrutura.h"
#include "dinamica.h"

void dinamica(int **matriz, Povo *povo, int qtdpovos, int distancia, int peso){
    Quatro_upla **conjunto;
    conjunto = (Quatro_upla**) malloc(qtdpovos * sizeof(Quatro_upla*));
    int selecionados;
    
    //corresponde aos calculos feitos apenas com 1 unico vertice
    for(int i = 0; i < qtdpovos; i++){
        selecionados = (peso / (*(povo + i)).peso);
        (*(*(conjunto + i) + i)).peso_atual = (selecionados * (*(povo + i)).peso);
        (*(*(conjunto + i) + i)).habilidade_atual = (selecionados * (*(povo + i)).habilidade);
        (*(*(conjunto + i) + i)).distancia_atual = distancia;
        (*(*(conjunto + i) + i)).caminho_anterior = (*(povo + i)).id;
    }

    

}
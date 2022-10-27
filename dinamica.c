#include <stdio.h>
#include <stdlib.h>
#include "estrutura.h"
#include "dinamica.h"
#include "file.h"

void dinamica(int **matriz, Povo *povo, int qtdpovos, int distancia, int peso){
	int *tabela, aux_s, qtdsoldados = 0;
	Solucao_dp **solucao;
	Solucao_dp *aux;
	tabela = (int *) malloc((peso + 1) * (sizeof(int)));
	solucao = (Solucao_dp **) malloc((peso + 1) * (sizeof(Solucao_dp *)));
	
	tabela[0] = 0;
	solucao[0] = NULL;
    
	for(int x = 1; x <= peso; x++){
		tabela[x] = 0;
		solucao[x] = NULL;
		
		for(int i = 0; i < qtdpovos; i++){
			if(povo[i].peso <= x){
				if((tabela[x - povo[i].peso] + povo[i].habilidade) > tabela[x]){
					tabela[x] = tabela[x - povo[i].peso] + povo[i].habilidade;
					solucao[x] = solucao[x - povo[i].peso];
					
					aux = (Solucao_dp *) malloc(sizeof(Solucao_dp));
					aux->item = i;
					aux->next = solucao[x];
					solucao[x] = aux;
				}
			}
		}
	}
	
	printf("\nhabilidade maxima %d.\nCaminho: ", tabela[peso]);
	aux_s = (solucao[peso]->item) + 1;
	printf("%d ", (solucao[peso]->item) + 1);
	
	while(solucao[peso] != NULL){
		qtdsoldados++;
		
		if(((solucao[peso]->item) + 1) != aux_s){
			printf("%d ", qtdsoldados-1);
			printf("%d ", (solucao[peso]->item) + 1);
			aux_s = (solucao[peso]->item) + 1;
			qtdsoldados = 1;
		}
		
		solucao[peso] = solucao[peso]->next;
	}
	
	printf("%d", qtdsoldados);
	printf("\n");

	free(tabela);
	free(aux);
	
	for(int j = 0; j <= peso; j++) {
		free(solucao[j]);
	}
}

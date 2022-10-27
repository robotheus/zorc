#include <stdio.h>
#include <stdlib.h>
#include "estrutura.h"
#include "dinamica.h"
#include "file.h"

void dinamica(int **matriz, Povo *povo, int qtdpovos, int distancia, int peso){
	int *tabela, aux_s, qtdsoldados = 0;
	Solucao_dp **solucao;
	Solucao_dp *aux;
	tabela = malloc((peso + 1) * (sizeof(int)));
	solucao = malloc((peso + 1) * (sizeof(Solucao_dp)));
	
	*(tabela) = 0;
	*(solucao) = NULL;
	
	for(int x = 1; x <= peso; x++){
		*(tabela + x) = 0;
		*(solucao + x) = NULL;
		
		for(int i = 0; i < qtdpovos; i++){
			if((*(povo + i)).peso <= x){
				if(*(tabela + (x - (*(povo + i)).peso)) + (*(povo + i)).habilidade > *(tabela + x)){
					*(tabela + x) = *(tabela + (x - (*(povo + i)).peso)) + (*(povo + i)).habilidade;
					*(solucao + x) = *(solucao + (x - (*(povo + i)).peso));
					
					aux = malloc(sizeof(Solucao_dp));
					aux->item = i;
					aux->proximo = *(solucao + x);
					*(solucao + x) = aux;
				}
			}
		}
	}

	for(int l = 0; l <= peso; l++) printf("%d) %d\n", l, tabela[l]);
	printf("\n\n");
	output1(*(tabela + peso));
	aux_s = (*(solucao + peso))->item + 1;
	output1(aux_s);
	
	while(*(solucao + peso) != NULL){
		qtdsoldados++;
		
		if(((*(solucao + peso))->item + 1) != aux_s){
			output1(qtdsoldados - 1);
			output1((*(solucao + peso))->item + 1);
			aux_s = ((*(solucao + peso))->item) + 1;
			qtdsoldados = 1;
		}
		
		*(solucao + peso) = ((*(solucao + peso))->proximo);
	}
	
	output1(qtdsoldados);
	output3();

	free(tabela);
}

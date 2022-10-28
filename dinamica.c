#include <stdio.h>
#include <stdlib.h>
#include "estrutura.h"
#include "dinamica.h"
#include "file.h"

void dinamica(int **matriz, Povo *povo, int qtdpovos, int distancia, int peso){
	int *tabela, aux_s, qtdsoldados = 0, menor_p, cp_peso = peso;
	Solucao_dp **solucao;
	Solucao_dp *solucao_aux;
	Solucao_dp *aux;
	
	tabela = (int *) malloc((peso + 1) * (sizeof(int)));
	solucao = (Solucao_dp **) malloc((peso + 1) * (sizeof(Solucao_dp *)));
	solucao_aux = malloc(sizeof(Solucao_dp));
	
	*(tabela) = 0;
	*(solucao) = NULL;
	
	for(int x = 1; x <= peso; x++){
		*(tabela + x) = 0;
		*(solucao + x) = NULL;
		
		for(int i = 0; i < qtdpovos; i++){
			if((*(povo + i)).peso <= x){
				if(*(tabela + (x - (*(povo + i)).peso)) + (*(povo + i)).habilidade >= *(tabela + x)){
					*(tabela + x) = *(tabela + (x - (*(povo + i)).peso)) + (*(povo + i)).habilidade;
						
					free(*(solucao + x));
					*(solucao + x) = *(solucao + (x - (*(povo + i)).peso));
						
					aux = malloc(sizeof(Solucao_dp));
					aux->item = i;
					aux->proximo = *(solucao + x);
					*(solucao + x) = aux;
				}
			}
		}
	}
	
	//checa e encontra a solucao ideal que respeite os caminhos entre os povos e a distancia
	cp_peso = checa_caminho(solucao_aux, solucao, peso, matriz, distancia);

	output1(*(tabela + cp_peso));
	aux_s = (*(solucao + cp_peso))->item + 1;
	output1(aux_s);
	
	while(*(solucao + cp_peso) != NULL){
		qtdsoldados++;
		
		if(((*(solucao + cp_peso))->item + 1) != aux_s){
			output1(qtdsoldados - 1);
			output1((*(solucao + cp_peso))->item + 1);
			aux_s = ((*(solucao + cp_peso))->item) + 1;
			qtdsoldados = 1;
		}
		
		*(solucao + cp_peso) = ((*(solucao + cp_peso))->proximo);
	}
	
	output1(qtdsoldados);
	output3();
	
	free(tabela);
	free(aux);
	free(solucao_aux);
	for(int k = 0; k <= cp_peso; k++) free(*(solucao + k));
	free(solucao);
	
}

int checa_caminho(Solucao_dp *solucao_aux, Solucao_dp **solucao, int peso, int **matriz, int distancia){
	int c = 0, count = 0;

	while(c == 0){
		for(solucao_aux = solucao[peso]; solucao_aux != NULL; solucao_aux = solucao_aux->proximo){
			if(solucao_aux->proximo != NULL){
				if(matriz[solucao_aux->item][solucao_aux->proximo->item] != -1){ 
					if((distancia - matriz[solucao_aux->item][solucao_aux->proximo->item]) >= 0){
						c = 1;
						distancia -= matriz[solucao_aux->item][solucao_aux->proximo->item];
					} else {
						peso--;
						c = 0;
						break;
					}
				} else {
					peso--;
					c = 0;
					break;
				}
			}
		}
	}

	return peso;
}
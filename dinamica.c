#include <stdio.h>
#include <stdlib.h>
#include "estrutura.h"
#include "dinamica.h"

void dinamica(int **matriz, Povo *povo, int qtdpovos, int distancia, int peso){
    int *t;
    Solucao **s;
    Solucao *n;

    t = (int *)malloc((peso+1)*(sizeof(int)));
	s = (Solucao **)malloc((peso+1)*(sizeof(Solucao *)));
	
    t[0]=0;
	s[0]=NULL;
    
    for(int x = 1; x <= peso; x++){
		t[x] = 0;
		s[x] = NULL;
		
		for(int i = 0;i < qtdpovos; i++){
			if(povo[i].peso <= x){
				if((t[x-povo[i].peso] + povo[i].habilidade) > t[x]){
					t[x] = t[x-povo[i].peso] + povo[i].habilidade;
					s[x] = s[x-povo[i].peso];
					n = (Solucao *)malloc(1 * (sizeof(Solucao)));
					n->item = i;
					n->next = s[x];
					s[x] = n;
				}
				
			}
		}
	}
    
    printf("\nTotal value of the items in the Knapsack is %d.\nThe knapsack containts the following items :\n", t[peso]);

    while(s[peso] != NULL){
		printf("Item- %d\n", (s[peso]->item)+1);
		s[peso] = s[peso]->next;
	}
}
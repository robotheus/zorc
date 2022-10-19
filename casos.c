#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "estrutura.h"
#include "casos.h"

void main(){
    srand(time(NULL));

    int povos, distancia, peso, caminhos;

    povos = rand() % 21;
    distancia = rand() % 31;
    peso = rand() % 1001;
    caminhos = rand() % 21;

    Povo p[povos];
    Caminhos c[caminhos];

    for(int i = 1; i <= povos; i++){
        p[i].id = i+1;
        p[i].peso = rand() % 111;
        p[i].habilidade = rand() % 11;
        p[i].razao = 0;
    }

    for(int i = 1; i <= caminhos; i++){
        c[i].povoi = rand() % (povos + 1);
        c[i].povoj = rand() % (povos + 1);
        c[i].distancia_pi_pj = 0;
        while(c[i].distancia_pi_pj == 0) c[i].distancia_pi_pj = rand() % 10;
    }

    printf("%d %d %d %d\n", povos, distancia, peso, caminhos);
    
    for(int i = 0; i < povos; i++){
        printf("%d %d %d\n", p[i].id, p[i].peso, p[i].habilidade);
    }

    for(int i = 0; i < caminhos; i++){
        printf("%d %d %d\n", c[i].povoi, c[i].povoj, c[i].distancia_pi_pj);
    }
}
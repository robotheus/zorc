#include <stdio.h>
#include <stdlib.h>
#include "file.h"
#include "grafo.h"

void grafo(int **matriz){
    open_file();

    int instances, povos, distancia, peso, caminhos, pi, pj;
    instances = read_file();
    
    for(int k = 0; k < instances; k++){
        povos = read_file();
        distancia = read_file();
        peso = read_file();
        caminhos = read_file();
        matriz = (int**) malloc(povos * sizeof(int*));
        
        //aloca o vetor de povos
        Povo *povo;
        povo = malloc(povos * sizeof(Povo));

        //aloca os povos
        for(int i = 0; i < povos; i++){
            (*(povo + i)).id = read_file();
            (*(povo + i)).peso = read_file();
            (*(povo + i)).habilidade = read_file();
        }

        //aloca a matriz adjunta
        for(int l = 0; l < povos; l++){
            *(matriz + l) = (int*) malloc(povos * sizeof(int*));
        }

        //preenche a matriz adjunta com distancia nao utilizada
        for(int m = 0; m < povos; m++){
            for(int j = 0; j < povos; j++){
                *(*(matriz + m) + j) = -1;
            }
        }
    
        //adiciona as arestas na matriz adjunta
        for(int n = 0; n < caminhos; n++){
            pi = read_file();
            pj = read_file();

            *(*(matriz + (pi - 1)) + (pj - 1)) = read_file();      
        }

        for(int p = 0; p < povos; p++){
            for(int q = 0; q < povos; q++){
                printf("%d ", *(*(matriz + p) + q));
            }
            printf("\n");
        }

        for(int r = 0; r < povos; r++){
            free(*(matriz + r));
        }

        free(povo);
        free(matriz);

        printf("\n");
    }
}
struct solu {
    int item;
    int qtd ;
    struct solu *next;
};

typedef struct solu Solucao_dp;

void dinamica(int **, Povo *, int, int, int);
int max(Povo *povo, int **tabela, int i, int j);
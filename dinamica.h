struct solucao {
    int item;
    struct solucao *next;
};

typedef struct solucao Solucao;

void dinamica(int **, Povo *, int, int, int);
int max(Povo *povo, int **tabela, int i, int j);
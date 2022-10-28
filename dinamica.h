struct solu {
    int item;
    struct solu *proximo;
};

typedef struct solu Solucao_dp;

void dinamica(int **, Povo *, int, int, int);
int checa_caminho(Solucao_dp *, Solucao_dp **, int, int **);
struct sol {
    int id;
    int selecionados;
};

typedef struct sol Solucao_h;

void heuristica(Povo *, int **, int, int, int);
void ordena_povos(Povo *, int);
int tem_caminho(int **, int, int);
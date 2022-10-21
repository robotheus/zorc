//essa struct vai armazenar os valores atualizados dos calculos ja realizados evitando o recalculo
struct s {
    int id;
    int habilidade;
    int peso;
    int distancia;
};

typedef struct s Solucao_pd;

void dinamica(int **, Povo, int, int, int, int);
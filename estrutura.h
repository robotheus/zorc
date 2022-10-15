//os vertices sao os povos e as arestas sao as ligacoes entre os povos
struct povo {
    int id;
    int peso;
    int habilidade;
};

typedef struct povo Povo;

void monta_estrutura(int **, Povo *, int, int);
void limpa_estrutura(int, int **, Povo *, Povo *);
void copia_estrutura(Povo *, Povo *, int);
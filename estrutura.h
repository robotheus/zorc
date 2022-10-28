//os vertices sao os povos e as arestas sao as ligacoes entre os povos
struct povo {
    int id;
    int habilidade;
    int peso;
    double razao; //quanto menor maior a prioridade para esse vertice
};

typedef struct povo Povo;

void monta_estrutura(int **, Povo *, int, int);
void limpa_estrutura(int, int **, Povo *, Povo *);
void copia_povos(Povo *, Povo *, int);
void copia_caminhos(int **, int **, int);
void ordena_povos(Povo *, int);
int tem_caminho(int **, int, int);

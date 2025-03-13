typedef struct{
    int matricula;
    char nome[30];
    float n1, n2, n3;
} aluno_t;

typedef struct fila Fila;

Fila* criarFila(void);
void liberarFila(Fila *fi);

int insereFila(Fila *fi, aluno_t *al);
int RemoveFila(Fila *fi);
int consultaFila(Fila *fi, aluno_t *al);
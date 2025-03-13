#define MAX 100

typedef struct{
    int matricula;
    char nome[30];
    float n1, n2, n3;
} aluno_t;

typedef struct fila Fila;

Fila* criarFila();
void liberarFila(Fila *fi);

int tamanhoFila(Fila *fi);
int filaCheia(Fila *fi);

int insereFila(Fila *fi, aluno_t *al);
int removeFila(Fila *fi);
int consultaFila(Fila *fi, aluno_t *al);

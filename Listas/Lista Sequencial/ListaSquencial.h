#define MAX 100

typedef struct{
    int matricula;
    char nome[30];
    float n1,n2,n3;
} aluno_t;

/* Implementação da lista estática*/
typedef struct lista Lista_t;

Lista_t* cria_lista(void);
void lista_free(Lista_t *li);

/* Informação da lista */
int tamanho_lista(Lista_t *li);
int lista_cheia(Lista_t *li);

/* Inserção na lista */
int insere_lista_final(Lista_t *li, aluno_t *al);
int insere_lista_inicio(Lista_t *li, aluno_t *al);
int insere_lista_ordenada(Lista_t *li, aluno_t *al);

/* Remoção na lista */
int remove_lista_final(Lista_t *li);
int remove_lista_inicio(Lista_t *li);
int remove_lista(Lista_t *li, int mat);

/* Consulta na lista */
int consulta_lista_pos(Lista_t *li, int pos, aluno_t *al);
int consulta_lista_matricula(Lista_t *li, int mat, aluno_t *al);
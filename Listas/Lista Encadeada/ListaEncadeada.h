typedef struct{
    int matricula;
    char nome[30];
    float n1,n2,n3;
} aluno_t;

typedef struct elemento* pLista_t;

// Implementação da lista
pLista_t* CriaLista();
void LiberaLista(pLista_t *li);
void show(pLista_t *li);

// Informações da lista
int TamanhoLista(pLista_t *li);
int ListaCheia(pLista_t *li);
int ListaVazia(pLista_t *li);

// Inserção na lista
int InsereInicio(pLista_t *li, aluno_t *al);
int InsereFim(pLista_t *li, aluno_t *al);
int InsereMeio(pLista_t *li, aluno_t *al);

// Remoção da lista
int RemoveInicio(pLista_t *li);
int RemoveFim(pLista_t *li);
int RemoveMeio(pLista_t *li, int mat);

// Consulta na lista
int ConsultaPosicao(pLista_t *li, int pos, aluno_t *al);
int ConsultaConteudo(pLista_t *li, int mat, aluno_t *al);
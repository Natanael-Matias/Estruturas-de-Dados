typedef struct{
    char nome[30];
    int matricula;
    float n1, n2, n3;
} aluno_t;

// Implementação da Lista
typedef struct elemento_t* pLista_t;

pLista_t* CriarLista();
void LiberaLista(pLista_t *li);

// Informação da lista
int ShowLista(pLista_t *li);
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
int RemoveItem(pLista_t *li, int mat);

// Consulta na lista
int ConsultaPosicao(pLista_t *li, aluno_t *al, int pos);
int ConsultaConteudo(pLista_t *li, aluno_t *al, int mat);
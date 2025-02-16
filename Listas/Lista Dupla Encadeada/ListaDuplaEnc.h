typedef struct aluno
{
    int matricula;
    char nome[30];
    float n1,n2,n3;
} aluno_t;

// Implementação da lista
typedef struct elemento* pLista;
pLista* CriarLista(void);
void LiberaLista(pLista *li);

// Informações
int TamanhoLista(pLista *li);
int ListaCheia(pLista *li);
int ListaVazia(pLista *li);
int ShowLista(pLista *li);

// Inserção na lista
int InsereInicio(pLista *li, aluno_t *al);
int InsereFim(pLista *li, aluno_t *al);
int InsereMeio(pLista *li, aluno_t *al);

// Remoção da lista
int RemoveInicio(pLista *li);
int RemoveFim(pLista *li);
int Remove(pLista *li, int mat);
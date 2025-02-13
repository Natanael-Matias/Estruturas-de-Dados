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
void ShowLista(pLista *li);
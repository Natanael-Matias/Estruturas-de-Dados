typedef struct aluno_t{
    int matricula;
    char nome[30];
    float n1, n2, n3;
} aluno_t;

// Implementação da lista
typedef struct descritor_t Lista_t;

Lista_t* CriarLista(void);
void LiberaLista(Lista_t *li);

// Informação
int TamanhoLista(Lista_t *li);
void ShowLista(Lista_t *li);

// Inserção
int InserirInicio(Lista_t *li, aluno_t *al);
int InserirFim(Lista_t *li, aluno_t *al);
int Inserir(Lista_t *li, aluno_t *al);
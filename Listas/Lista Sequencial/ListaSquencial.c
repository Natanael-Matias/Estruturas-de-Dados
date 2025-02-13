#include <stdlib.h>
#include "ListaSquencial.h"

struct lista{
    int qtd;
    aluno_t *dados_alunos[MAX];
};

Lista_t* cria_lista(void){
    Lista_t *li = (Lista_t *) malloc(sizeof(Lista_t));
    if(li != NULL)
        li -> qtd = 0;
    return li;
}

void lista_free(Lista_t *li){
    free(li);
}

int tamanho_lista(Lista_t *li){
    if(li == NULL)
        return -1;
    
    return (li -> qtd);
}

int lista_cheia(Lista_t *li){
    if(li == NULL)
        return -1;

    return (li->qtd == MAX);
}

int insere_lista_final(Lista_t *li, aluno_t *al){
    if(li == NULL)
        return -1; // ponteiro inválido.
    if(lista_cheia(li))
        return 0;
    
    li->dados_alunos[li->qtd] = al;
    li->qtd++;
    
    return 1;
}

int insere_lista_inicio(Lista_t *li, aluno_t *al){
    if(li == NULL)
        return -1;
    if(lista_cheia(li))
        return 0;

    int i = li->qtd - 1;
    for(i; i > -1; i--)
        li->dados_alunos[i+1] = li->dados_alunos[i];
    
    li->dados_alunos[0] = al;
    li->qtd++;
    
    return 1;
}

int insere_lista_ordenada(Lista_t *li, aluno_t *al){
    if(li == NULL) return -1;
    if(lista_cheia(li)) return 0;

    int k = li->qtd - 1;
    int i = 0;

    while(i < li->qtd && li->dados_alunos[i]->matricula < al->matricula) i++;

    for(k; k >= i; k--)
        li->dados_alunos[k+1] = li->dados_alunos[k];

    li->dados_alunos[i] = al;
    li->qtd++;

    return 1;
}

int remove_lista_final(Lista_t *li){
    if(li == NULL) return -1;
    if(li->qtd == 0) return 0;

    li->qtd--;

    return 1;
}

int remove_lista_inicio(Lista_t *li){
    if(li == NULL) return -1;
    if(li->qtd == 0) return 0;

    int i = li->qtd - 1;
    for(int k = 0; k < i; k++)
        li->dados_alunos[k] = li->dados_alunos[k+1];
    li->qtd--;
    
    return 1;
}

int remove_lista(Lista_t *li, int mat){
    if(li == NULL) return -1;
    if (li->qtd == 0) return 0;

    int k, i = 0;
    while(i < li->qtd && li->dados_alunos[i]->matricula != mat) i++;

    if(i == li->qtd) return 0; // Elemento não encontrado.

    for(k = i; k < li->qtd - 1; k++)
        li->dados_alunos[k] = li->dados_alunos[k+1];
    li->qtd--;

    return 1;
}

int consulta_lista_pos(Lista_t *li, int pos, aluno_t *al){
    if(li == NULL) return -1;

    if(pos <= 0 || pos > li->qtd) return 0;

    *al = *(li->dados_alunos[pos - 1]);

    return 1;
}

int consulta_lista_matricula(Lista_t *li, int mat, aluno_t *al){
    if(li == NULL) return -1;

    int k, i = 0;
    while(i < li->qtd && li->dados_alunos[i]->matricula != mat) i++;

    if(i == li->qtd) return 0;

    *al = *(li->dados_alunos[i]);

    return 1;
}

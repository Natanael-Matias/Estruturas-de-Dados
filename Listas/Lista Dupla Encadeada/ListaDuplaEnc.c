#include <stdlib.h>
#include <stdio.h>
#include "ListaDuplaEnc.h"

typedef struct elemento{
    aluno_t *dados_aluno;
    struct elemento *prev;
    struct elemento *next;
} elemento_t;

pLista* CriarLista(void){
    pLista *li = (pLista *) malloc(sizeof(pLista));
    if(li != NULL)
        *li = NULL;
    
    return li;
}

void LiberaLista(pLista *li){
    if(li != NULL){
        elemento_t *no;
        while((*li) != NULL){
            no = *li;
            *li = (*li)->next;
            free(no);
        }
        free(li);
    }
}

int TamanhoLista(pLista *li){
    if(li == NULL) return -1;
    elemento_t *no = *li;
    int i = 0;
    while(no != NULL){
        i++;
        no = no->next;
    }
    return i;
}

int ListaCheia(pLista *li){
    return 0;

    
}

int ListaVazia(pLista *li){
    if(li == NULL) return -1;
    if(*li == NULL) return 1;
    return 0;
}

void ShowLista(pLista *li){
    if(li == NULL) return;

    elemento_t *no = *li;
    while(no != NULL){
        printf("%d\n", no->dados_aluno->matricula);
        no = no->next;
    }
}
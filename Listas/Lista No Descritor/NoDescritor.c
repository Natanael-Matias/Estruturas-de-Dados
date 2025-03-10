#include <stdlib.h>
#include <stdio.h>
#include "NoDescritor.h"

typedef struct elemento_t{
    aluno_t *pData;
    struct elemento_t *next;
} elemento_t;

typedef struct descritor_t{
    elemento_t *inicio;
    elemento_t *final;
    int qtd;
} descritor_t;

Lista_t* CriarLista(void){
    Lista_t *li = (Lista_t *) malloc(sizeof(Lista_t));
    if(li != NULL){
        li->inicio = NULL;
        li->final = NULL; 
        li->qtd = 0;
    }
    return li;        
}

void LiberaLista(Lista_t *li){
    elemento_t *no;
    int i = 0;
    for(i; i < li->qtd; i++){
        no = li->inicio;
        li->inicio = no->next;
        free(no);
    }
    free(li);
}

int TamanhoLista(Lista_t *li){
    if(li == NULL) return -1;

    return li->qtd;
}

void ShowLista(Lista_t *li){
    if(li == NULL) return;

    elemento_t *temp = li->inicio;
    while(temp->next != NULL){
        printf("%d -> ", temp->pData->matricula);
        temp = temp->next;
    }
    printf("%d\n", temp->pData->matricula);
}

int InserirInicio(Lista_t *li, aluno_t *al){
    if(li == NULL) return -1;

    elemento_t *no = (elemento_t *) malloc(sizeof(elemento_t));
    if(no == NULL) return 0;
    
    no->pData = al;
    no->next = li->inicio;
    if(li->inicio == NULL)
        li->final = no;
    li->inicio = no;
    li->qtd++;

    return 1;
}

int InserirFim(Lista_t *li, aluno_t *al){
    if(li == NULL) return -1;

    elemento_t *no = (elemento_t *) malloc(sizeof(elemento_t));
    if(no == NULL) return 0;

    no->pData = al;
    no->next = NULL;

    if(li->inicio == NULL)
        li->inicio = no;
    else
        li->final->next = no;
    li->final = no;
    li->qtd++;
    
    return 1;
}

int Inserir(Lista_t *li, aluno_t *al){
    if(li == NULL) return -1;

    elemento_t *no = (elemento_t *) malloc(sizeof(elemento_t));
    if(no == NULL) return 0;
    no->pData = al;
    no->next = NULL;

    if(li->inicio == NULL){
        li->inicio = no;
        li->final = no;
    }
    else{
        elemento_t *prev = NULL, *temp = li->inicio;
        while(temp != li->final && temp->pData->matricula < al->matricula){
            prev = temp;
            temp = temp->next;
        }
            
        if(prev == NULL){
            if(temp->pData->matricula > al->matricula){
                no->next = temp;
                li->inicio = no;
            }
            else{
                no->next = temp->next;
                temp->next = no;
                if(temp == li->final)
                    li->final = no;
            }
        }    
        else{
            if(temp->pData->matricula < al->matricula){
                temp->next = no;
                li->final = no;
            }
            else{
                no->next = prev->next;
                prev->next = no;
            }
        }
    }

    li->qtd++;
    return 1;
}
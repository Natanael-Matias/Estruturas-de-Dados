#include <stdlib.h>
#include <stdio.h>
#include "ListaEncadeada.h"

typedef struct elemento{
    aluno_t *dados_alunos;
    struct elemento *next;
} elemento;

pLista_t* CriaLista(){
    pLista_t *li = (pLista_t *) malloc(sizeof(pLista_t));
    if (li != NULL)
        *li = NULL;

    return li;
}

void LiberaLista(pLista_t *li){
    if(li == NULL){
        elemento *no;
        while((*li) != NULL){
            no = *li;
            *li = (*li)->next;
            free(no);
        }
        free(li);
    }

}

void show(pLista_t *li){
    elemento *temp = *li;
    while(temp != NULL){
        printf("%d\n", temp->dados_alunos->matricula);
        temp = temp->next;
    }
}

int TamanhoLista(pLista_t *li){
    if(li == NULL) return -1;
    int cont = 0;

    elemento *no = *li;
    while(no != NULL){
        cont++;
        no = no->next;
    }
    return cont;
}

int ListaCheia(pLista_t *li){
    return 0;
}

int ListaVazia(pLista_t *li){
    if(li == NULL)
        return -1;
    
    if(*li == NULL)
        return 1; // Lista vazia.
    
    return 0; // Lista não vazia.
}

int InsereInicio(pLista_t *li, aluno_t *al){
    if(li == NULL) return -1;

    elemento *no = (elemento *) malloc(sizeof(elemento));
    if(no == NULL) return 0;

    no->dados_alunos = al;
    no->next = *li;
    *li = no;

    return 1;
}

int InsereFim(pLista_t *li, aluno_t *al){ //TODO: Arrumar bug de lista vazia.
    if(li == NULL) return -1;

    elemento *no = (elemento *) malloc(sizeof(elemento));
    if(no == NULL) return 0;

    no->dados_alunos = al;
    no->next = NULL;

    elemento *aux = *li;

    if(aux == NULL){
        *li = no;
        return 1;
    }

    while(aux->next != NULL)
        aux = aux->next;
    aux->next = no;

    return 1;
}

int InsereMeio(pLista_t *li, aluno_t *al){
    if(li == NULL) return -1;

    elemento *no = (elemento *) malloc(sizeof(elemento));
    if(no == NULL) return 0;

    no->dados_alunos = al;

    elemento *anterior, *atual = *li;

    while(atual->next != NULL && atual->dados_alunos->matricula < al->matricula){
        anterior = atual;
        atual = atual->next;
    }
    
    anterior->next = no;
    no->next = atual;

    return 1;
}

int RemoveInicio(pLista_t *li){
    if(li == NULL) return -1;
    if(*li == NULL) return 0;

    elemento *no = *li;
    *li = no->next;
    free(no);

    return 1;
}

int RemoveFim(pLista_t *li){
    if(li == NULL) return -1;
    if(*li == NULL) return 0;

    elemento *anterior, *no = *li;
    while (no->next != NULL){
        anterior = no;
        no = no->next;
    }
    
    anterior->next = NULL;
    free(no);

    return 1;
}

int RemoveMeio(pLista_t *li, int mat){
    if(li == NULL) return -1;
    if(*li == NULL) return 0;

    elemento *anterior = *li, *no = *li;
    while(no != NULL && no->dados_alunos->matricula != mat){
        anterior = no;
        no = no->next;
    }
    
    if(no == NULL) return 0;

    if(no == *li){
        *li = no->next;
    }
    else
        anterior->next = no->next;
    
    free(no);

    return 1;
}

int ConsultaPosicao(pLista_t *li, int pos, aluno_t *al){
    if(li == NULL) return -1;
    if(*li == NULL || pos <= 0) return 0;

    elemento *no = *li;
    int cont = 1;

    while(no != NULL && cont < pos){
        cont++;
        no = no->next;
    }

    if(no == NULL) return 0; // posição fora da lista

    *al = *(no->dados_alunos);
    
    return 1;
}

int ConsultaConteudo(pLista_t *li, int mat, aluno_t *al){
    if(li == NULL) return -1;
    if(*li == NULL) return 0;

    elemento *no = *li;
    while(no != NULL && no->dados_alunos->matricula != mat)
        no = no->next;

    if(no == NULL) return 0; // Não encontrado.

    *al = *(no->dados_alunos);
    
    return 1;
}
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

int ShowLista(pLista *li){
    if(li == NULL) return -1;
    if(*li == NULL) return 0;

    elemento_t *no = *li;
    while(no != NULL){
        printf("%d\n", no->dados_aluno->matricula);
        no = no->next;
    }
    return 1;
}

int InsereInicio(pLista *li, aluno_t *al){
    if(li == NULL) return -1;
    
    elemento_t *no = (elemento_t *) malloc(sizeof(elemento_t));
    if(no == NULL) return 0;

    no->next = *li;
    no->prev = NULL;
    no->dados_aluno = al;

    if(*li != NULL)
        (*li)->prev = no;

    *li = no;
    return 1;
}

int InsereFim(pLista *li, aluno_t *al){
    if(li == NULL) return -1;

    elemento_t *no = (elemento_t *) malloc(sizeof(elemento_t));
    if(no == NULL) return 0;

    no->dados_aluno = al;
    no->next = NULL;
    no->prev = NULL;
    
    elemento_t *temp = *li;

    if(temp == NULL)
        *li = no;
    else{
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = no;
        no->prev = temp;
    }

    return 1;
}

int InsereMeio(pLista *li, aluno_t *al){
    if(li == NULL) return -1;

    elemento_t *no = (elemento_t *) malloc(sizeof(elemento_t));
    if(no == NULL) return 0;

    no->dados_aluno = al;
    no->next = NULL;
    no->prev = NULL;

    elemento_t *temp = *li;
    if(temp == NULL){
        *li = no;
        return 1;
    }

    while(temp->next != NULL && al->matricula > temp->dados_aluno->matricula)
        temp = temp->next;
    
    if(al->matricula > temp->dados_aluno->matricula){
        no->prev = temp;
        temp->next = no;
        return 1;
    }

    no->next = temp;
    if (temp->prev == NULL){
        temp->prev = no;
        *li = no;
    }
    else{
        no->prev = temp->prev;
        temp->prev->next = no;
        temp->prev = no;
    }
    return 1;      
}

int RemoveInicio(pLista *li){
    if(li == NULL) return -1;
    if(*li == NULL) return 0;

    elemento_t *no = *li;

    *li = no->next;
    if(no->next != NULL)
        (*li)->prev = NULL;

    free(no);
    
    return 1;
}

int RemoveFim(pLista *li){
    if(li == NULL) return -1;
    if(*li == NULL) return 0;

    elemento_t *no = *li;
    while(no->next != NULL)
        no = no->next;
    
    if(no->prev != NULL)
        no->prev->next = NULL;
    else
        *li = no->next;
    
    free(no);
    
    return 1;
}

int Remove(pLista *li, int mat){
    if(li == NULL) return -1;
    if(*li == NULL) return 0;

    elemento_t *no = *li;
    while(no->next != NULL && no->dados_aluno->matricula != mat)
        no = no->next;
    
    if(no->dados_aluno->matricula != mat) return 0;
    
    if(no->prev == NULL)
        *li = no->next;
    else
        no->prev->next = no->next;
    
    if(no->next != NULL)
        no->next->prev = no->prev;

    free(no);
    
    return 1;
}

int ConsultaPosicao(pLista *li, int pos, aluno_t *al){
    if(li == NULL) return -1;
    if(*li == NULL || pos <= 0) return 0;

    elemento_t *no = *li;
    int i = 1;

    while(no != NULL && i < pos){
        no = no->next;
        i++;
    }

    if(no == NULL) return 0;

    *al = *(no->dados_aluno);
    
    return 1;
}

int ConsultaConteudo(pLista *li, int mat, aluno_t *al){
    if(li == NULL) return -1;
    if(*li == NULL) return 0;

    elemento_t *no = *li;
    while(no != NULL && no->dados_aluno->matricula != mat)
        no = no->next;

    if(no == NULL) return 0;

    *al = *(no->dados_aluno);
    
    return 1;
}

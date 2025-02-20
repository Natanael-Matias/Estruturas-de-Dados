#include <stdlib.h>
#include <stdio.h>
#include "ListaEncadCirc.h"

typedef struct elemento_t{
    aluno_t *pData;
    struct elemento_t *next;
} elemento_t;

pLista_t* CriarLista(){
    pLista_t *li = (pLista_t *) malloc(sizeof(pLista_t));
    if(li != NULL)
        *li = NULL;
    return li;
}

void LiberaLista(pLista_t *li){
    if(li != NULL && *li != NULL){
        elemento_t *temp, *no = *li;
        while((*li) != no->next){
            temp = no;
            no = no->next;
            free(temp);
        }
        free(no);
        free(li);
    }
}

int ShowLista(pLista_t *li){
    if(li == NULL) return -1;

    if(*li != NULL){
        elemento_t *temp = *li;
        while(temp->next != *li){
            printf("%d -> ", temp->pData->matricula);
            temp = temp->next;
        }
        printf("%d\n", temp->pData->matricula);
        return 1;
    }
    return 0;
}

int TamanhoLista(pLista_t *li){
    if(li == NULL) return -1;
    int cont = 1;
    elemento_t *temp = *li;
    if(temp == NULL) return 0;
    while(temp->next != *li){
        cont++;
        temp = temp->next;
    }
    return cont;
}

int ListaCheia(pLista_t *li){
    if(li == NULL) return -1;
    return 0;
}

int ListaVazia(pLista_t *li){
    if(li == NULL) return -1;
    if(*li == NULL) return 1;
    return 0;
}

int InsereInicio(pLista_t *li, aluno_t *al){
    if(li == NULL) return -1;

    elemento_t *no = (elemento_t *) malloc(sizeof(elemento_t));
    if(no == NULL) return 0;

    no->pData = al;

    if(*li == NULL)
        no->next = no;
    else{
        no->next = *li;
        elemento_t *temp = *li;
        while(temp->next != *li)
            temp = temp->next;
        temp->next = no;
        no->next = *li;
    }
    *li = no;
    
    return 1;
}

int InsereFim(pLista_t *li, aluno_t *al){
    if(li == NULL) return -1;

    elemento_t *no = (elemento_t *) malloc(sizeof(elemento_t));
    if(no == NULL) return 0;
    
    no->pData = al;
    if(*li == NULL){
        no->next = no;
        *li = no;
    }   
    else{
        elemento_t *temp = *li;
        while(temp->next != *li)
            temp = temp->next;
        temp->next = no;
        no->next = *li;
    }
    
    return 1;
}

int InsereMeio(pLista_t *li, aluno_t *al){
    if(li == NULL) return -1;

    elemento_t *no = (elemento_t *) malloc(sizeof(elemento_t));
    if(no == NULL) return 0;

    no->pData = al;
    
    if(*li == NULL){
        no->next = no;
        *li = no;
    }
    else{
        elemento_t *prev = NULL;
        elemento_t *temp = *li;
        while(temp->next != *li && temp->pData->matricula < al->matricula){
            prev = temp;
            temp = temp->next;
        }
        if(prev == NULL){ // Primeiro item da lista
            prev = temp;
            no->next = temp;
            while(temp->next != *li)
                temp = temp->next;
            temp->next = no;
            if(prev->pData->matricula > al->matricula)
                *li = no;
            return 1;
        }

        if(temp->next == *li){ // Último elemento da lista.
            if(temp->pData->matricula > al->matricula){
                prev->next = no;
                no->next = temp;
            }
            else{
                no->next = temp->next;
                temp->next = no;
            }
        }
        else{
            no->next = temp;
            prev->next = no;            
        }
    }
    
    return 1;
}

int RemoveInicio(pLista_t *li){
    if(li == NULL) return -1;
    if(*li == NULL) return 0;

    elemento_t *no = *li;    
    elemento_t *temp = no;
    while(temp->next != *li)
        temp = temp->next;
    
    temp->next = no->next;
    
    if(no->next == *li)
        *li = NULL;
    else
        *li = temp->next;
    free(no);
    
    return 1;
}

int RemoveFim(pLista_t *li){
    if(li == NULL) return -1;
    if(*li == NULL) return 0;

    elemento_t *no = *li;
    elemento_t *temp = no;

    while(no->next != *li){
        temp = no;
        no = no->next;
    }
        
    if(temp->next == *li)
        *li = NULL;
    else
        temp->next = *li;
    free(no);

    return 1;
}

int RemoveItem(pLista_t *li, int mat){
    if(li == NULL) return -1;
    if(*li == NULL || mat < 1) return 0;

    elemento_t *no = *li;
    elemento_t *prev = NULL;

    while(no->next != *li && no->pData->matricula != mat){
        prev = no;
        no = no->next;
    }

    if(prev == NULL){
        if(no->pData->matricula == mat){
            if(no->next == *li)
                *li = NULL;
            else{
                elemento_t *temp = no;
                while(temp->next != *li)
                    temp = temp->next;
                temp->next = no->next;
                *li = no->next;
            }
        }
        else
            return 0;
    }
    else{
        if(no->pData->matricula == mat)
            prev->next = no->next;
        else
            return 0;
    }

    free(no);
    
    return 1;
}

int ConsultaPosicao(pLista_t *li, aluno_t *al, int pos){
    if(li == NULL) return -1;
    if(*li == NULL || pos < 1) return 0;

    elemento_t *temp = *li;
    int i = 1;
    while(temp->next != *li && i != pos){
        i++;
        temp = temp->next;
    }

    if(i == pos)
        *al = *(temp->pData);
    else
        return 0;
    
    return 1;
}

int ConsultaConteudo(pLista_t *li, aluno_t *al, int mat){
    if(li == NULL) return -1;
    if(*li == NULL) return 0;

    elemento_t *temp = *li;
    while(temp->next != *li && temp->pData->matricula != mat)
        temp = temp->next;
    
    if(temp->pData->matricula == mat)
        *al = *(temp->pData);
    else
        return 0;
    
    return 1;
}
#include <stdlib.h>
#include "FilaDinamica.h"

struct fila{
    elemento_t *inicio;
    elemento_t *final;
};

typedef struct elemento{
    aluno_t dados;
    struct elemento *next;
} elemento_t;

Fila* criarFila(void){
    Fila *fi = (Fila*) malloc(sizeof(Fila));
    if(fi != NULL){
        fi->inicio = NULL;
        fi->final = NULL;
    }
    return fi;
}

void liberarFila(Fila *fi) {
    if(fi != NULL){
        elemento_t *temp;
        while(fi->inicio != NULL){
            temp = fi->inicio;
            fi->inicio = fi->inicio->next;
            free(temp);
        }
        free(fi);
    }
}

int insereFila(Fila *fi, aluno_t *al){
    if(fi == NULL) return -1;

    elemento_t *no = (elemento_t*) malloc(sizeof(elemento_t));
    if(no == NULL) return 0;

    no->dados = *al;
    no->next = NULL;
    if(fi->final = NULL)
        fi->inicio = no;
    else
        fi->final->next = no;
    fi->final = no;

    return 1;
}

int RemoveFila(Fila *fi){
    if(fi == NULL) return -1;

    if(fi->inicio == NULL) return 0;

    elemento_t *temp = fi->inicio;
    fi->inicio = fi->inicio->next;
    if(fi->inicio == NULL)
        fi->final == NULL;
    free(temp);

    return 1;
}

int consultaFila(Fila *fi, aluno_t *al){
    if(fi == NULL) return -1;
    if(fi->inicio == NULL) return 0;

    *al = fi->inicio->dados;
    return 1;
}
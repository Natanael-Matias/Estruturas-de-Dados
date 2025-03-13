#include <stdlib.h>
#include <stdio.h>
#include "FilaEstatica.h"

typedef struct fila{
    int inicio, final, qtd;
    aluno_t dados[MAX];    
};

Fila* criarFila(){
    Fila *fi = (Fila*) malloc(sizeof(Fila));
    if(fi != NULL){
        fi -> final = 0;
        fi -> inicio = 0;
        fi -> qtd = 0;
    }
    return fi;
}

void liberarFila(Fila *fi){
    free(fi);
}

int tamanhoFila(Fila *fi){
    if(fi == NULL) return -1;

    return fi->qtd;
}

int filaCheia(Fila *fi){
    if(fi == NULL) return -1;

    if(fi->qtd == MAX) return 1;
    return 0;
}

int insereFila(Fila *fi, aluno_t *al){
    if(fi == NULL) return -1;
    if(filaCheia(fi)) return 0;

    fi->dados[fi->final] = *al;
    fi->final = (fi->final + 1) % MAX;
    fi->qtd++;
    return 1;
}

int removeFila(Fila *fi){
    if(fi == NULL) return -1;
    if(fi->qtd == 0) return 0;

    fi->inicio = (fi->inicio + 1) % MAX;
    fi->qtd--;
    return 1;
}

int consultaFila(Fila *fi, aluno_t *al){
    if(fi == NULL) return -1;
    if(fi->qtd == 0) return 0;

    *al = fi->dados[fi->inicio];
    return 1;
}
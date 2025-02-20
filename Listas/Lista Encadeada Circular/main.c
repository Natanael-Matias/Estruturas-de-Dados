#include <stdio.h>
#include "ListaEncadCirc.h"

void main(void){
    pLista_t *head;
    head = CriarLista();

    aluno_t aluno1, aluno2, aluno3, aluno4, aluno5, aluno6, aluno7;
    aluno1.matricula = 10;
    aluno2.matricula = 15;
    aluno3.matricula = 13;
    aluno4.matricula = 9;
    aluno5.matricula = 12;
    aluno6.matricula = 20;
    aluno7.matricula = 8;

    InsereMeio(head, &aluno1);
    InsereMeio(head, &aluno2);
    InsereMeio(head, &aluno3);
    InsereMeio(head, &aluno4);
    InsereMeio(head, &aluno5);
    InsereMeio(head, &aluno6);
    InsereMeio(head, &aluno7);
    if(!ShowLista(head))
        printf("Lista vazia.\n");
    printf("\n");

    RemoveItem(head, 8);
    if(!ShowLista(head))
        printf("Lista vazia.\n");
    printf("\n");

    RemoveItem(head, 3);
    if(!ShowLista(head))
        printf("Lista vazia.\n");
    printf("\n");
    

    LiberaLista(head);
}
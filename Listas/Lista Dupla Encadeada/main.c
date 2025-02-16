#include <stdio.h>
#include "ListaDuplaEnc.h"

void main(void){
    pLista *head;
    head = CriarLista();

    aluno_t aluno1, aluno2, aluno3, aluno4, aluno5;
    aluno1.matricula = 10;
    aluno2.matricula = 15;
    aluno3.matricula = 13;
    aluno4.matricula = 9;
    aluno5.matricula = 12;

    InsereInicio(head, &aluno1);
    /*InsereMeio(head, &aluno3);
    InsereMeio(head, &aluno4);
    InsereFim(head, &aluno2);
    InsereMeio(head, &aluno5);*/

    if(!ShowLista(head))
        printf("Lista vazia.\n");
    printf("\n");

    Remove(head, 10);

    if(!ShowLista(head))
        printf("Lista vazia.\n");
    printf("\n");

    Remove(head, 13);

    if(!ShowLista(head))
        printf("Lista vazia.\n");
    printf("\n");

    LiberaLista(head);
}
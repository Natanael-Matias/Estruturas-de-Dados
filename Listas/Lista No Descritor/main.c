#include <stdio.h>
#include "NoDescritor.h"

void main(void){
    Lista_t *head;
    head = CriarLista();

    aluno_t a1, a2, a3, a4, a5;
    a1.matricula = 5;
    a2.matricula = 10;
    a3.matricula = 15;
    a4.matricula = 20;
    a5.matricula = 13;

    Inserir(head, &a2);
    Inserir(head, &a3);
    
    ShowLista(head);

    Inserir(head, &a1);
    Inserir(head, &a4);
    Inserir(head, &a5);

    ShowLista(head);
}
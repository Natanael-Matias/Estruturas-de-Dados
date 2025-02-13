#include <stdio.h>
#include "ListaEncadeada.h"

void main(void){
    pLista_t *head;
    head = CriaLista();

    aluno_t aluno1, aluno2, aluno3, aluno4, aluno5, aluno6;
    aluno1.matricula = 10;
    aluno2.matricula = 20;
    aluno3.matricula = 30;
    aluno4.matricula = 25;
    aluno5.matricula = 29;
    aluno6.matricula = 27;

    InsereInicio(head, &aluno1);
    InsereFim(head, &aluno3);
    InsereMeio(head, &aluno2);
    InsereMeio(head, &aluno4);
    InsereMeio(head, &aluno5);
    InsereMeio(head, &aluno6);
    InsereFim(head, &aluno4);

    aluno_t recuperaAluno;
    if(ConsultaConteudo(head, 27, &recuperaAluno))
        printf("%d\n", recuperaAluno.matricula);
    else
        printf("Falha.\n");

    LiberaLista(head);
}
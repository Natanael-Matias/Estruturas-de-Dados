#include <stdio.h>
#include <string.h>
#include "ListaSquencial.h"

int main(void){
    Lista_t *li;

    li = cria_lista();

    aluno_t aluno1, aluno2, aluno3;

    aluno1.matricula = 1;
    aluno2.matricula = 2;
    aluno3.matricula = 3;
    
    insere_lista_final(li, &aluno3);
    insere_lista_inicio(li, &aluno1);
    insere_lista_ordenada(li, &aluno2);

    int i = tamanho_lista(li);
    

    lista_free(li);
    return 0;
}
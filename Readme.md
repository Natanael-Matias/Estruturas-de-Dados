# Estruturas de Dados
## Tipo abstrato de dado
Tipo de dado: Define o conjunto de valores (domínio) que uma variável pode assumir.
Ex.: int
... -2, -1, 0, 1, 2, ...

Estruturas de dados: trata-se de um relacionamento lógico entre tipos de dados.
Ex.:
```C
struct pessoa{
    int idade;
    char nome[];
    float peso;
};
```
Tipo abstrato de dado (TAD): incluem as operações para a manipulação dos dados.
Ex.: 
- criação da estrutura
- inclusão de um elemento
- remoção de um elemento
- acesso a um elemento
- etc

Vantagens:
- Encapsulamento e segurança: o usuário não tem acesso direto aos dados.
- Flexibilidade e reutilização: podemos alterar o TAD sem alterar as aplicações que o utilizam.

Exemplo de TAD: arquivos em C.
FILE *fp;
Os dados em "fp" somente podem ser acessados pelas funções de manipulação do tipo:
- fopen()
- fclose()
- fputc()
- feof()
- ...

## Modularização
A convenção em linguagem C é preparar dois arquivos para implementar um TAD: 
- Arquivo *.h: protótipos das funções, tipos de ponteiro e dados gobalmente acessíveis.
- Arquivo *.c: declaração do tipo de dado e implementação das suas funções.

Assim separamos o **conceito** (definição do tipo) de sua **implementação**.
Exemplo de TAD: um ponto definido por suas coordenadas **x** e **y**.
```C
struct ponto{
    float x;
    float y;
};
```

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

## Listas
Uma estrutura do tipo **Lista** é uma sequência de elementos do mesmo tipo. Seus elementos possuem estrutura interna abstraída, ou seja, sua complexidade é arbitrária e não afeta seu comportamento.
Uma lista pode possuir N (N >= 0) elementos. Se N = 0 diz-se que a lista está vazia.
Aplicações:
- Cadastro de funcionários
- Itens em estoque
- Cartas de baralho
- etc.

Em uma lista é possível realizar as seguintes aplicações básicas:
- Criação da lista
- Inserção de um elemento
- Exclusão de um elemento
- Acesso a um elemento
- Destruição da lista
- etc

Essas operações dependem do tipo de alocação de memória usada:
- Estática: 
    - O espaço de memória é alocado no momento da compilação.
    - Exige a definição do número máximo de elementos na lista.
    - Acesso sequencial: elementos consecutivos na memória.
- Dinâmica:
    - O espaço de memória é alocado em tempo de execução.
    - A lista cresce à medida que novos elementos são armazenados, e diminui à medida que elementos são removidos
    - Acesso encadeado: cada elemento pode estar em uma área distinta da memória. Para acessar um elemento é necessário percorrer todos os seus antecessores na lista.

### Lista sequencial (ou linear) estática
Tipo de lista onde o sucessor de um elemento é adjacente a este, ou seja, ocupa a posição física seguinte do memso. (uso de **array**).
Vantagens do uso de arrays:
- Acesso rápido e direto aos elementos (índice).
- Tempo constante para acessar um elemento.
- Facilidade em modificar informações

Desvantagens do uso de arrays:
- Definição prévia do tamanho do array.
- Dificuldade de inserir ou remover um elemento entre outros dois elementos: é necessário deslocar os elementos.

Quando utilizar essa lista?
- Listas pequenas.
- Inserção/remoção apenas no final da lista.
- Tamanho máximo bem definido.
- A busca é a operação mais frequente.

```C
struct dados{
    int quantidade; //indica se a lista está cheia ou vazia
    Tipo dado; // struct com o TAD armazenado na lista
};
```

### Lista dinâmica encadeada
Tipo de lista onde cada elemento aponta para o seu sucessor na lista. Usa um ponteiro especial para o primeiro elemento da lista e uma indicação de final da lista.
Cada elemento é tratado como um ponteiro que é alocado dinamicamente à medida que os dados são inseridos. Para guardar o primeiro elemento é utilizado um **ponterio para ponteiro**, assim fica fácil mudar quem está no começo da lista, apenas mudadno o conteúdo do ponteiro para ponteiro.
Vantagens:
- Melhor utilização dos recursos de memória.
- Não precisa movimentar os elementos nas operações de inserção e remoção.

Desvantagens:
- Acesso indireto aos elementos.
- Necessidade de percorrer a lista para acessar um elemento.

Quando utilizar essa lista?
- Não há necessidade de garantir um espaço mínimo para a execução do aplicativo.
- Inserção e remoção em lista ordenada são as operações mais frequentes.
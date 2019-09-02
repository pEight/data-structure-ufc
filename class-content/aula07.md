# Aula 7

# Pilhas

Observe que, no programa da aula passada, embora nós utilizamos vetores para armazenar os números e operadores da expressão digitada. Entretanto, embora os elementos de um vetor possam ser acessados individualmente a partir dos respectivos índices, nós só utilizávamos os elementos finais do vetor. Mais especificamente, é fácil observar que nós utilizávamos os números e operadores como se eles estivessem em pilhas: `((3+4)*(5-3...`

```
      | 0 | 1 | 2 | ...
      |----------------
vnum: | 7 | 5 | 3 | ...

     | 0 | 1 | ...
     |----------------
vop: | * | - | ...

vnum:  ___
      | 3 | -> último operando inserido na pilha.
      |---|
      | 5 |
      |---|
      | 7 |

vop:  ___
     | - | -> último operador inserido na pilha.
     |---|
     | * |
```

## Tipos abstratos de dados

Um tipo abstrato de dados é um modelo/especificação "abstrata" de um tipo de dados, no sentido de que especifica como o tipo deve funcionar do ponto de vista de quem o utiliza. A definição de um TAD tipicamente informa, por exemplo, que valores são armazenados pelo tipo, quais são as operações associadas, quais são os comportamentos esperados e restrições dessas operações, etc. Em constrate, uma estrutura de dados é uma especificação "concreta" de como certos dados podem ser armazenados, de como as operações associadas aos dados podem ser implementadas, etc. Assim, por exemplo, no programa da aula passada, nós precisávamos de uma pilha para os números e outra para os operadores(A pilha era o TAD), e nós utilizamos vetores para implementá-las (o vetor era a estrutura de dados).

## O TAD pilha

O TAD pilha é um contêiner, ou seja, serve para armazenar elementos de um certo tipo. A pilha possui duas operações essenciais:

1. Empilhar(P, e): insere o elemento e na pilha p.
2. Desempilhar(P): remove de P, dentre os elementos em P, aquele que foi inserido por último.

Diferentes implementações de pilha podem ter diferentes comportamentos adicionais associados às operações acima. Assim, por exemplo, como não faz sentido desempilhar de uma pilha vazia, uma implementação pode estipular que a operação desempilhar possui a pré-condição de que a pilha não está vazia (nesse caso, é um erro de programação desempilhar de uma pilha vazia), e qualquer coisa pode acontecer se isso for feito em tempo de execução); Já outra implementação pode permitir que se desempilhe de uma pilha vazia, retornando um código de erro(uma exceção) se isso acontecer.

## Outras operações típicas de pilha

1. Vazia(P): retorna um booleano, que  será verdadeiro se e somente se P estiver vazia.
2. Topo(P): retorna o elemento do topo de P.

## Tipos de pilha

1. Limitada: possui uma capacidade máxima, tipicamente estipulada na criação da pilha; Empilhar além desse limite é/gera um erro.
2. Ilimitada: não tem tamanho máximo pré-estabelecido.

## Exemplo de uso
```
p <- criar_pilha_limitada_de_inteiros();

empilhar(p, 1);
empilhar(p, 2);
empilhar(p, 3);

// Suponha que "desempilhar" retorna o removido.
imprimir(desempilha(p)); // 3
imprimir(desempilha(p)); // 2
imprimir(desempilha(p)); // 1

terminar(p);
```

## Exercício

Sabendo que fib = { 
  n, se n <= 1
  fib(n-2) + fib(n-1), se n >= 2
}

**Escreva, em pseudocódigo, uma implementação não recursiva da função de fibonacci. (Dica: use pilha(s))**



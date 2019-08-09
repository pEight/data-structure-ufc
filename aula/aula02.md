# Aula 2

## Estrutura de repetições em C++

Em C++ temos:

```cpp
while(<condition>) {
  ...
}
```

```cpp
do {

} while (<condition>)
```

Nos dois modelos acima, `<condition>` representa uma condição de continuidade do laço.

```cpp
int i;
for (i=0;i<=10;i+=1) {
  ...
}
```

## Funções em C++

As funções em C++ seguem o seguinte modelo:
```cpp
<tipo-retorno> <func-name>(<args>) {
  ...
}
```

Exemplo:
```cpp
int resto(int a, int b) {
  return a%b;
}
```

## Chamada de funções

Dada a função abaixo:

```cpp
int fatorial(int n) {
  return (n == 0) ? 1 : n*fatorial(n-1);
}
```

[FOTO AQUI!]

## Ponteiros

Ponteiros guardam a posição de memória de um certo valor. Ponteiros servem para "apontar", isto é , se referir a algum (1)"objeto" na memória.

(1) Váriavel ou outra região que guarde um valor de um certo tipo.

Ná prática, um ponteiro armazena na memória apenas um endereço de memória, o qual é simplesmente um número natural. Esse número será retornado em base 16.

O tipo de um ponteiro traz dele o tipo do objeto apontado.

### Operadores básicos:

Operador "*": Se P é um ponteiro, então "*P" é uma expressão que denota o objeto apontado por "P".

Operador "&": Se V denota um objeto da memória, então "&V" é uma expressão que denota um ponteiro apontando para o objeto em questão. "&V" é uma expressão que representa a posição de memória do objeto V.

Declarar um ponteiro: `int *point_int` é diferene da expressão "*V". A segunda se refere ao valor da posição de memória V(V tem que ser um ponteiro).

**Observação**: Uma variavel não pode "apontar para outro canto de memória". Considerando uma variável como uma """"""abstração"""""" de um ponteiro. **Cuidado com essa observação. Pode estar muito errado**.

### Declaração de ponteiros

Regra Geral: Se "t" é o texto da declaração de uma variável "v" de tipo "T", e se "t'" é o resultado da substituição de "v" por "(*p)" em "t", então "t'" é a declaração de um ponteiro "p" de tipo "ponteiro para T".

**Observação**: Os parênteses de "(*p)" as vezes podem ser omitidos, a depender da precedência dos operadores em "t".













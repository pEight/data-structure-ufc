# Aula 3

## Ponteiros

**Complemento sobre a forma da declaração de ponteiros**: a intuição na declaração de um ponteiro P de tipo T é que, depois da declaração, a expressão *p terá tipo T.

Além disso, será possível omitir os parênteses da declaração de p quando não houver outros "operadores" de maior precedência presentes e que alterariam o significado da declaração sem os parênteses(Como "[]").

Exemplo:

```cpp
int *p; // ponteiro para int

int *v[3]; // vetor de 3 ponteiros para int*

int (*pv)[3] // ponteiro para vetor de 3 int
```

`pv` é um ponteiro.
`*pv` é um vetor de 3 inteiros.
`(*pv)[2]` é um inteiro.

## Aritmética de ponteiros

Ponteiro + inteiro: se p aponta para v[i], sendo v um vetor de n elementos, e se j é um inteiro, então `p + j` é uma expressão que denota um ponteiro para v[i+j], desde que 0 <= i+j <= n.

```
      0   1   2   3   4   5
v : |   |   |   |   |   |   |
                          ^
                          |
                         p+3
```

**Observação 1**: um inteiro contêm 4 bytes.
**Observação 2**: Não podemos realizar a soma de dois ponteiros.
**Observação 3**: Não podemos somar inteiro + ponteiro, mas podemos somar ponteiro + inteiro.

## Comparação de ponteiros

Se p aponta para v[i], sendo v um vetor de n elementos, e se q aponta para  v[j], então:
  `p < q` se e somente se i < j,
e o mesmo vale para `<=`, `>`, `>=`, `==` e `!=`. Além disso, dois ponteiros p e q podem ser comparados via `==` e `!=` mesmo que não apontem para elementos de um mesmo vetor.

## Subtração entre ponteiro

Se p aponta para v[i], sendo v vettor de n elementos, e q aponta para v[j], então o valor de p-q é igual ao de i - j (embora o tipo de p - q seja ptrdiff_t, que é um inteiro com sinal grande o suficiente).

## Exemplo de percurso de vetor via ponteiros

```cpp
#include <iostream>

using std:cout;

int main() {
  int v[3] = {1, 2, 3};

  int *prim = &v[0], *ult = &v[2], *p; // ou ... = v+0, ... v+2

  for (p=prim; p < ult; p+=1) {
    cout << "v[" << p - prim << "]: " << *p << '\n';
  }
}
```

**Observação**: Observe o laço acima. Ele realizar uma iteração a mais. Logo teremos a posição p+1 em p. Mas não podemos ler, nem escrever o valor de (p+1). Se o laço fizer um decremento, o mesmo caso não ocorre.
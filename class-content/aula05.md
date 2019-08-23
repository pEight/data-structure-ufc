# Aula 5

## Teste do sucesso da alocação

```cpp
#include <iostream>
#include <new>

using std::cin;
using std::cout;
using std::nothrow;

int main() {
  int n;
  cout << "n: ";
  cin >> n;

  double* v = new(nothrow) double[n];

  if(v == nullptr) {
    cout << "Sem memória!\n";
    return 1;
  }

  ... uso normal de v...
  delete[] v;
}
```

## Avaliação de expressão aritméticas

2. Problema: escreva um programa em C++ que leia do usuário uma expressão arittmética envolvendo números naturais e as operações `+`, `-`, `*`, `/`, e que escreva o resultado(racional) da expressão. Restrição da entrada: a expressão possuirá todos os parênteses, um par para cada operador.

**Exemplo de entrada**:

((5/2) + (0-3)) * (((2-7)/10)/(2*5))

O número de caracteres da expressão não é conhecido a priori. No caso, o programa deve solicitar ao usuário, no início da execução, a digitação de um limite superior `n` para o número de caracteres da expressão.

**Estratégia para resolução do exemplo acima**:

1. Ler a linha caractere-a-caractere.
2. Transformar o caractere "c" de um dígito "d" em inteiro, basta fazer d = c - '0'
3. Para transformar uma sequência de dígitos num único inteiro: 1234 = (((1*10) + 2) * 10 + 3) * 10 + 4;

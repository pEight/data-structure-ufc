# Aula 11

## TAD Fila

### Introdução

Uma fila é, assim como uma pilha, um contêiner, de forma que elementos podem nela serem inseridos e removidos. A diferença essencial entre as duas é que, enquanto numa pilha a operação de remoção remove o último elemento inserido, numa fila a remoção retira o primeiro elemento inserido (dentre aqueles ainda presentes na estrutura)

### Exemplos

inicializar  -----------> vazia
enfilar(A)   -----------> <A>
enfilar(B)   -----------> <A B>
enfilar(C)   -----------> <A B C>
desenfilar() -----------> <B C> (A saiu)
enfilar(D)   -----------> <B C D>
desenfilar() -----------> <C D> (B saiu)
desenfilar() -----------> <D> (C saiu)
desenfilar() -----------> < > (D saiu)

### Discussão sobre representação

Imagens no pdf fornecido pelo professor

### Estratégia

1. Usar índices "circulares" para utilizar o vetor inteiro sempre.
2. Ao expandir ou contrair, copiar os elementos para o início do novo vetor, **na ordem de enfilamento**.
3. Fila vazia <----> início = -1

### Exemplo de uso de uma fila ("main.cpp")

```cpp
#include <iostream>
#include "fila.hpp"

using std::cout;
using std::cin;

int main() {
  fila<double> f;

  if(f.inicializar()) return 1;

  for(;;) {
    cout << "Digite um número" << "(negativo para sair): ";
    double num; cin >> num;
    if (num < 0) break;
    
    if (f.enfilar(num)) return 2;
  }

  cout << "Aqui estão os números: ";
  while(!f.vazia()) {
    cout << ' ' << f.primeiro();
    
    if (f.desenfilar()) return 3;
  }

  f.terminar();
}
```
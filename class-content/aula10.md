# Aula 10

## Pilha via vetor


### Exemplo
```cpp
#include <iostream>

using std::cin;
using std::cout;

#include "pilha.hpp"

int main() {
  pilha<double> p;

  if (p.inicializar()) return 1;

  for (;;) {
    cout << "Número para empilhar(negativo para terminar): ";

    double num;
    cin >> num;

    if (num < 0) {
      break;
    }

    if (p.empilhar(num)) return 2;
  }

  cout << "Os números digitados, do último para o primeiro, foram: ";
  while(!p.vazia()) {
    cout << ' ' << p.topo();
    if (p.desempilhar()) return 3;
  }

  p.terminar();
}
```

### Uma implementação de pilha ("pilha.hpp")

```cpp
#include <new>

using std:nothrow;

template <typename T>
struct Pilha {
  T* v;
  int ult;
  int tam_v;

  bool inicializar() {
    v = new(nothrow) T[1];

    if (v == nullptr) {
      return true;
    }

    ult = -1;
    tam_v = 1;
    return false;
  };

  void terminar() {
    delete[] v;
  }

  bool vazia() {
    return ult == -1;
  }

  T topo() {
    return v[ult];
  }

  bool redimensionar(int tam_w) {
    T* w = new(nothrow) T[tam_w];

    if (w == nullptr) {
      return true;
    }

    for (int i = 0; i <= ult; i += 1) {
      w[i] = v[i];
    }
    delete[] v;
    v = w;
    tam_v = tam_w;
    return false;
  }

  bool empilhar(T elem) {
    if (ult == (tam_v - 1)) {
      if (redimensionar(tam_v*2)) {
        return true
      }
    }
    ult += 1;
    v[ult] = elem;
    return false;
  }

  bool desempilhar() {
    ult -= 1;

    if(!vazia() && 4*(ult+1) <= tam_v) {
      if (redimensionar(tam_v / 2)) {
        return true;
      }
    }

    return false;
  }
}
```


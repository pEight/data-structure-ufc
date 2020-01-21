# Aula 17

## Deque via lista encadeada

### Representação

< A B > <---> |_A_|___| ---> |_B_|___| ---> NULL

< C A B > <---> |___|_C_|___| ---> <--- |___|_A_|___| ---> <--- |___|_B_|___|

### Implementação("Deque.hpp")

```cpp
#ifndef DEQUE_HPP
#define DEQUE_HPP

#include <new>
using std::nothrow;

struct Deque {
  struct Node {
    T elem;
    Node* ant;
    Node* prox;
  };

  Node *esq, *dir;

  void inicializar() {
    esq = dir = nullptr;
  }

  bool vazio() {
    return esq == nullptr && dir == nullptr;
  }

  bool inserir_esq(T e) {
    Noh *n = new(nothrow) Noh;
    if(n == nullptr) return true;

    (*n).ant = nullptr;
    (*n).elem = e;
    (*n).prox = esq;

    if(vazio()) {
      dir = n;
    } else {
      (*esq).ant = n;
    }

    esq = n;
    return false;
  }

  T remover_esq() {
    Noh* n = esq;
    T e = (*n).elem;
    esq = (*n).prox;

    if(esq == nullptr) {
      dir = nullptr;
    } else {
      (*esq).ant = nullptr;
    }
  }
};


#endifn
```
# Aula 16

## Pilha via lista encadeada

### Continuação da implementação

Código da aula anterior:

```cpp
#include <new>

using std::nothrow;

template<typename T>
struct Pilha {
  struct Noh {
    T elem; Noh *prox;
  };

  Noh *topo;

  void inicializar() {
    topo = nullptr
  }

  void vazia() {
    return  topo == nullptr;
  }

  T consultar_topo() {
    return (*topo).elem; // return topo->elem;
  }

  bool empilhar(T elem) {
    Noh *n = new(nothrow) Noh;

    if (n == nullptr) return true;

    n->prox = topo;
    n->elem = elem;
    topo = n;
    return false;
  }
};
```

Continuando:

```cpp

T desempilhar() {
  T e = (*topo).elem;
  Noh* n = topo;
  topo = (*topo).prox;
  delete n;
  return e;
}

void terminar() {
  while(!vazia()) {
    desempilhar();
  }
}
```

### Fila via lista encadeada

**Representação**:

Debate em sala de aula.

```cpp
#ifndef FILA_HPP
#define FILA_HPP

#include <iostream>
#include <new>

using std::nothrow;

template <typename T>
struct Queue {
  struct Node {
    T elem;
    Node* next;
  };

  Node* begin;
  Node* end;

  void initQueue() {
    begin = nullptr;
    end = nullptr;
  }

  bool isEmpty() {
    return begin == nullptr;
  }

  bool enqueue(T elem) {
    Node* node = new(nothrow) Node;

    if(node == nullptr) return true;

    (*node).elem = elem;
    (*node).next = nullptr;

    if (isEmpty()) {
      end = node;
      begin = end;
    } else {
      (*end).next = node;
      end = node;
    }

    return false;
  }

  T dequeue() {
    Node* auxptr = begin;
    T elem = (*begin).elem;
    begin = (*begin).next;
    delete auxptr;

    return elem;
  }

  void deleteQueue() {
    while(!isEmpty()) {
      dequeue();
    }
  }

  T getHead() {
    return (*begin).elem;
  }
};

#endif
```
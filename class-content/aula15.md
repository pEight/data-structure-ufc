# Aula 15

## Lista encadeada

### Motivação

Uma operação de redimensionar um array pode ser muito custoso, pois é necessário criar um novo vetor, passar os elementos dos antigos para o novo e então atribuir esse novo vetor ao antigo.

Com listas encadeadas, temos o valor e um ponteiro para o próximo nó com a mesma estrutura do atual.

### Implementação ("Pilha.h")

Aqui será implementado parte de uma pilha com lista encadeada.

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
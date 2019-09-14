# Aula 14

## Iteradores

### Continuando iteradores

Dado o código da aula passada de iteradores, vamos desenvolver as funções de `inicio` e `fim`.

```cpp
int main() {
  Conjunto<double> C;
  ... Adicionando elementos em C ...
  auto fim = C.fim();

  for (auto i = C.inicio; i != fim; i += 1) {
    cout << ' ' << *i;
  }

  C.terminar();
}
```

```cpp
struct Conjunto {
  ...
  // CONJUNTOS
  struct Iterador {
    T *p;

    bool operator!= (const Iterador &j) {
      return (p != j.p);
    }

    T& operator*() {
      return *p;
    }

    Iterador& operator+=() {
      p += 1;
      return *this;
    }
  };

  Iterador inicio() {
    Iterador i;
    i.p = &(v[0]);
    return i;
  }

  Iterador fim() {
    Iterador i;
    i.p = &(v[ult+1]);
    return i;
  }
}
```

## Dicionários

### Introdução

Um dicionário é um contêiner, assim como um conjunto, mas a operação de busca é diferente da operação "pertence": ao invés de receber um elemento inteiro, recebe apenas uma *chave*, que identifica um elemento de forma única, e então retorna os *dados-satélite* (informações complementares) correspondentes.

As principais operações de um dicionário são:

1. inserir(D, c, d): insere a chave c e o dado-satélite d como um novo par no dicionário D.

2. procurar(D, c): retorna o dado satélite correspondente à chave c no dicionário D.

3. remover(D, c): remove de D o par/elemento de chave c.

### Uma implementação ("dicionario.hpp")

```cpp
#include <new>
using std::nothrow;

template <typename X, typename Y>
struct Par {
  X x;
  Y y;
};

template <typename TC, typename TD>
struct Dicionario {
  Par<TC, TD> *v;
  int ult, size;

  bool inicializar() {
    v = new(nothrow) Par<TC, TD>[1];

    if (v == nullptr) return true;

    ult = -1;
    size = 1;
    return false;
  }

  void terminar() {
    delete[] v;
  }

  bool vazio() {
    return (ult == -1);
  }

  Par<bool, TD> procurar(TC c) {
    for (int i = 0; i <= ult; i += 1) {
      if (v[i].x == c) {
        Par<bool, TD> p;
        p.x = true;
        p.y = v[i].y;
        return p;
      }
    }

    Par p<bool, TD> p; 
    p.x = false;
    return p;
  }

  Par <bool, bool> inserir(TC c, TD d) {
    Par<bool, TD> p = procurar(c); // auto p

    if(p.x) {
      Par<bool, bool> r;
      r.x = true;
      return r;
    }

    if (ult == size - 1) {
      if (redimensionar) {
        Par<bool, bool> r;
        r.x = false;
        ry = true;
        return r;
      }
    }

    ult += 1;
    v[ult].x = c
    v[ult].y = d;
    Par<bool, bool> r = { false, false };
    return r;
  }
}
```

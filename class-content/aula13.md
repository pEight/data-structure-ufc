# Aula 13

## Iteradores

O ponteiro this: dentro de uma função membro, a expressão this denota um ponteiro para a estrutura a partir da qual a função foi chamada.

```cpp
#include <iostream>
struct TipoQQ {
  int campo_QQ;

  TipoQQ* meu_endereco() {
    return this;
  }
}

int main() {
  TipoQQ a, b;
  cout << "Endereço de a: " << a.meu_endereco() << "\n";

  if (&a != a.meu_endereco() || a.meu_endereco() == b.meu_endereco()) {
    cout << "Absurdo!\n";
  }
}
```

### Referências

em C++, uma referência é outro nome para um objeto na memória. Elas compartilham parte da utilidade dos ponteiros, por exemplo a possibilidade de se acessar uma variável num contexto em que ela não pode ser referida pelo nome, e com vantagens, como a não necessidade do uso do operador * para o acesso. Por outro lado, referências são mais restritas que ponteiros, no sentido de que, enquanto ponteiros podem ser redirecionados, uma referência sempre aponta para o mesmo endereço, a saber, o endereço da inicialização.

```cpp
void trocar(int &a, int &b) {
  int copia_de_a = a;
  a = b;
  b = copia_de_a;
}

int main() {
  int x = 10;
  int &rx = x;
  rx = 5; // x == 5
  int y = 0;
  trocar(x, y);
  // x == 0 && y == 5
}
```

### Sobrecarga de operadores

Em C++ podemos dar "novos significados" aos operadores.

```cpp
struct Vetor {
  double x,y;
  vetor2D operator+ (const Vetor2D &v) {
    vetor2D novo;
    novo.x = x + v.x;
    novo.y = y + v.y;
    return novo;
  }
}
```

### Finalmente iteradores

São uma maneira não intrusiva de se percorrer coleções.

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

### Implementação de iteradores

```cpp
...
// CONJUNTOS
struct Iterador {
  T *p;

  bool operator!= (const Iterador &j) {
    return (p != j.p)
  }

  T& operator*() {
    return *p;
  }

  Iterador& operator+=() {
    p += 1;
    return *this;
  }
};
```
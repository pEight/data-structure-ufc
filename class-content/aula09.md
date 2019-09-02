# Aula 9

## Complemento

(A Solução das torres de hanói. Sabemos que devemos mover para a torre de destino. Assim fazemos o movimento dos discos menores para o auxiliar, objetivando conseguir colocar o maior disco na torre de destino.) Pesquisa melhor isso.

## Polimorfismo paramétrico

```cpp

int soma_vint(int* v, int n) {
  int soma = 0, i;
  for (i = 0; i < n; i += 1) {
    soma += v[i];
  }

  return soma;
}

double soma_vdouble(double* v, int n) {
  double soma = 0, i;

  for (i = 0; i < n; i += 1) {
    soma += v[i];
  }

  return soma;
}

```cpp
template <typename T>
T soma_vet(T* v, int n) {
  T soma = 0;
  int i;

  for (i = 0; i < n; i += 1) {
    soma += v[i];
  }

  return soma;
}

int main() {
  int v[3] = { 1, 2, 3 };
  double w[3] = { 4, 5, 6 };
  int si = soma_vet<int>(v, 3); // ou = soma_vet(v, 3)
  double sd = soma_vet<double>(w, 3); // ou = soma_vet(w, 3)
}
```

## Tipos paramétrizados

```cpp
template <typename X, typename Y>
struct Par {
  X x;
  Y y;
};


Par<int, int> div_int(int a, int b) {
  Par<int, int> p;
  p.x = a / b;
  p.y = a % b;
  return p;
}

int main() {
  Par<int, int> p = div_int(7, 3);
}

template <typename X, typename Y>
X primeiro(Par<X,Y> p) {
  return p.x;
}

template <typename X, typename Y>
Y segundo(Par<X,Y> p) {
  return p.y;
}
```

## Funções membros

```cpp
template<typename X, typename Y>
struct Par {
  X x; Y y;
  X primeiro() { return x; }
  Y segundo() { return y; }
}

int main() {
  Par<double, char> p;
  p.x = 3.14;
  p.y = '!';
  double qq_coisa = p.primeiro() - p.segundo;
}
```


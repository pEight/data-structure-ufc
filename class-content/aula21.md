# Aula 21

## Conjunto via lista encadeada

### Implementação (Cont):

*Talvez não seja a melhor maneira*

```cpp
Iterador procurar(T e) {
  Noh *n = sent.prox;
  for (;n != &sent; n = (*n).prox) {
    if ((*n).elem = e) {
      Iterador i; i.p = n;
      return i;
    }
  }
}
```

Talvez seja a melhor maneira:

```cpp
Iterador procurar(T e) {
  Noh *n = sent.prox;
  sent.elem = e;
  while((*n).elem != e) {
    n = (*n).prox;
  }

  if (n == &sent) {
    return fim();
  }

  Iterador i;
  i.p = n;
  return i;
}
```

Outra forma seria:

```cpp
Iterador procurar(T e) {
  Noh *n = sent.prox;
  sent.elem = e;
  while((*n).elem != e) {
    n = (*n).prox;
  }

  Iterador i;
  i.p = n;
  return i;
}
```

Nessa ultima forma, observe que se o elemento não encontrar o elemento, ele volta para a sentinela e isso faz com que seja o mesmo retorno de uma chamada da função membro `fim()`.

Agora, é possível criar uma função de `pertence` de uma forma mais simples.

```cpp
bool pertence(T e) {
  Iterator i = procurar(e);
  return i.p != &sent;
}
```

Enfim, escrevemos a função membro terminar de um conjunto implementado via lista encadeada.

```cpp
void terminar() {
  Noh *n = sent.prox;
  while (n != &sent) {
    Noh *aux = n;
    n = (*n).prox;
    delete aux;
  }
}
```

## Notação assintótica

### Motivação

Compare estas duas otimizações que fizemos antes;

1. Utilizar a sentinela para reduzir de 2 para 1 o número de comparações do laço da remoção de um conjunto via lista encadeada.

2. Na remoção de conjunto via vetor, substituir v[i] por v[ult].

Qual é mais significativa?

Para o primeiro caso, a versão otimizada possui n operações, logo seu tempo é de kn. Onde k é o número de instruções de máquina e n é o número de instruções do código feito pelo progamador. A versão não otimizada leva kn + n. O tempo do anterior mais n operações.

Para o segundo caso, Analisando o pior caso, ou seja, o primeiro elemento removido, na versão otimizada teriamos 2 operações. Na versão não otimizada(remover o primeiro elemento envolve mover todos os anteriores uma posição a menos) levariamos kn de tempo. Portanto a otimização é bem mais impactante.

O texto acima é uma conclusão feita por mim.

### Definição

Se g: N -> N, então

O(g) = { f: N -> N | existem m pertence N* e c pertence a R*+ tais que, para todo n>=m, 0 <= f(n) <= c.g(n) }

N* => naturais != 0
R*+ => reais > 0

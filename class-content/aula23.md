# Aula 23

## Complexidade de Algoritmos

**Exercício**: expresse, em termos de "n", a complexidade assintótica do tempo de execução da função abaixo

```cpp
double soma(double *v, int n) {
  double s = 0;
  for(int i = 0; i < n; i+=1) {
    s += v[i];
  }
  return s;
}
```

**Solução**: Podemos separar o tempo de execução da função em:

1. inicialização da função. { `double s = 0`, `i=0` } ==> a

2. { `i < n`, `s+=v[i]`, i++ } ==> b -> n vezes

3. { `i < n`(último teste), `return s`, finalização da função } ==> c

a + b*n + c

**Exercício**: qual é a complexidade do tempo de execução desta função

```cpp
int buscar_linear(double *v, int n, double e) {
  for(int i = 0; i < n; i += 1) {
    if(v[i] == E) return i;
  }

  return -1;
}
```

**Solução**: é fácil observar que o tempo de execução da função não depende só de "n", mas também de "v" e "e". Porém, para expressar o tempo de execução em termos da notação "O" aplicada a alguma função g(n), podemos considerar uma função f(n) que dê o tempo de execução da função no pior caso e nesse caso encontrar g(n) tal que f = O(g). Nesse caso, é evidente que, assim como no exercício anterior, existem constantes "a" e "b" tais que (fn)=a * n+b. Além disso, é o caso que f(n)=O(n). Logo, nós dizemos que o tempo de execução do algoritmo é O(n).

**Exercício**: qual é o tempo de execução do algoritmo abaixo:

```cpp
/*pre-condição: para todo i pertencente a [0...n-2], v[i+1]=v[i]+2*/

double soma(double *v, int n) {
  return (v[0]+v[n-1])*n/2;
}
```

**Solução curta**: a função executa em tempo constante(independente de n), e portanto executa em tempo O(1).

**Solução longa**: é fácil ver que existe uma constante positiva "a" tal que o tempo de execução da função é f(n) = a. Como f(n)=O(1), então a função executa em tempo O(1).

**Observação:** para todo a pertencente a N*, a = O(1).
**Prova**: Sejam m = 1, c=a e n >= m. Temos 0 <= a <= c*n

## Tempo de execução das implementações via vetor

| ---------- | Consulta | Inserção                             | Remoção                              |
| ---------- | -------- | ------------------------------------ | ------------------------------------ |
| Pilha      | `O(1)`   | `O(n)` -> pc e `O(1)` -> amortizado  | `O(n)` -> pc e `O(1)` -> amortizado  |
| Fila       | `O(1)`   | `O(n)` -> pc e `O(1)` -> amortizado  | `O(n)` -> pc e `O(1)` -> amortizado  |
| Deque      | `O(1)`   | `O(n)` -> pc e `O(1)` -> amortizado  | `O(n)` -> pc e `O(1)` -> amortizado  |
| Conjunto   | `O(n)`   | `O(n)` -> pc e `O(1)` -> amortizado  | `O(n)`                               |
| Dicionário | `O(n)`   | `O(n)`                               | `O(n)`                               |
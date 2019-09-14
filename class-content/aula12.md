# Aula 12

## Conjuntos dinâmicos

### Introdução

o TAD Conjunto dinâmico é um contêiner, assim como pilhas e filas. Um conjunto dinâmico se difere dos conjuntos "matemáticos" por estes últimos serem estáticos, no sentido de que não têm seus elementos alterados (Assim, por exemplo, na teoria dos conjuntos se C = A [união] {x} e x não pertence a A, então C, que é o resultado da "inserção" de x em A é outro conjunto: C != A).

Conjuntos dinâmicos têm uma diferença crucial em relação a pilhas e filas: neles, qualquer elemento armazenado pode ser removido. Além disso, é possível consultar se um elemento qualquer está ou não no conjunto.

As seguintes operações são, então, essenciais em conjuntos dinâmicos:

1. Inserir(C, e): Insere o elemento "e" no conjunto C.
2. Pertence(C, e): informa se "e" pertence a C ou não.
3. remover(C, e): remove "e" de C.

O percurso dos elementos de um conjunto será estudado na próxima aula; outras operações, como a união e a interseção, são típicas, mas omitiremos.

### Representação via vetor

Inserção ocorre um após o outro elemento. Na remoção, por questão de performance, podemos remover um elemento de qualquer posição e colocar o último na posição do removido, já que um conjunto não é ordenado.

### Implementação

Especificação:
```cpp
template <typename T>
struct Conjunto {
    ...campos/dados...
    bool inicializar() { ... } true <-> erro
    // pre-cond.: "e" não pertence
    bool inserir(T e) { ... } true <-> erro de alocação
    bool pertence(T e) { ... } true <-> pertence
    bool remover(T e) { ... } true <-> elemento removido
};
```
# Aula 33

## O que fazer para evitar árvores assim

```
						2
						 \
						  5
							 \
							  8
								 \
								  16
									 \
									  21
										 \
										  34
```

## Árvores binárias de busca balanceadas

### O critério de balanceamento AVL

Uma árvore binária de busca é AVL se somente se, para toda subárvore r de A,
																																		/ \
																																	 /   \
																																	/     \
																																 /       \
																																/\       /\
																															 /  \     /  \
																															/ es \	 / di \
																														 /______\ /______\

| h(e) - h(d) | <= 1

### Exercício
Para cada altura h, qual é o menor número n de vértices de uma árvore AVL de altura h?

h = 0 --> vazio

h = 1 -->   *
           / \

h = 2 -- >  *     *       *
           /     / \       \
					*     *   *       *

h = 3 -->  *
          / \
				 *   *
				      \
							 *

h = 4

As árvores com menor número de nós AVL é uma sequência de fib das arvores com h menor que a atual.

numero de nós da árvore AVL de altura 5 = (nº de nós da árvore AVL de altura 4) + (nº de nós da árvore AVL de altura 3) + 1

| h | n min | n máx |
| - | ----- | ----- |
| 1 | 1     | 1     |
| 2 | 2     | 3     |
| 3 | 4     | 7     |
| 4 | 7     | 15    |
| 5 | 12    | 31    |
| 6 | 20    | 63    |
| 7 | 33    | 127   |
| 8 | 54    | 255   |
| 9 | 88    | 511   |

### Teorema 

Para toda árvore "de fibonacci" temos n >= 2 ^ floor(h/2) desde que h >= 1.

**prova**:

caso base:

- Seja h = 1/ => 2 ^ floor(1/2) => 2 ^ 0 = 1 = n, como queriamos demonstrar.
- Seja h = 2: 2 ^ floor(2/2) => 2 ^ 1 = 2 <= n, como queriamos demonstrar.

**Tentar provar sozinho**

**Observação**: floor(x) >= x - 1





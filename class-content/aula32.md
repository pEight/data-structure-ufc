# Aula 32

## Operações em árvores binárias

### Resumo dos percursos completo estudados

**Percurso em ordem**:

- Se árvore vazia: fim
- Senão:
	1. Percora a subárvore esquerda em ordem
	2. Visite a raiz
	3. Percorra a subárvore direita em ordem

**Percurso pré-ordem**:

- Se árvore vazia: fim
- Senão:
	1. Visite a raiz
	2. Percorra a subárvore esquerda em pré-ordem
	3. Percorra a subárvore direita em pré-ordem

**Percurso pós-ordem**:

- Se vazia: fim.
- Senão:
	1. Subárvore esquerda pós-ordem
	2. Subárvore direita pós-ordem
	3. Visite a raiz

### Remoção em árvores binárias de busca

Árvore atual:
```
							15
						 /  \
				    8   22
				   /   /  \
					3   20  30
					 \
					  5
					 /
				  4
```

Remover 4:
```
							15
						 /  \
				    8   22
				   /   /  \
					3   20  30
					 \
					  5
```

Remover 8:
```
							15
						 /  \
				    /   22
				   /   /  \
					3   20  30
					 \
					  5
```

**Uma estratégia**:

```
      							n
						       / \
                  /   \
                 /     \
                /       \
							 /         \
							/           \
						 /             \
						/\             /\
					 /  \           /  \
					/    \         /    \
				 / esqu \       / dire \
				/________\     /________\
```

**a)** Se E = D = vazio,a remoção é trivial

**b)** Se E != vazio = D, então basta colocar "E" no lugar de n. (Idem para E = vazio != D).

**c)** Se E != vazio != D, Basta encontrar o sucessor "s" de n(que é o menor de "D"), removê-lo e colocá-lo no lugar de n.

- Observe que "s" necessariamente não tem filho esquerdo.
- Observe que o antecessor de n também serve(é possível alternar)

### Custo das Operações

| Operação | O(h)  |
| -------- | ----- |
| Busca    | O(h)  |
| Inserção | O(h)  |
| Remoção  | O(h)  |




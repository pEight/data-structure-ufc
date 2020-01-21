# Aula 34

## Revisão sobre árvores AVL

### Definição

Uma árvore binária de busca A é AVL, para toda subárvore x de A,
```																											/ \
																											 /   \
																											/     \
																										 /       \
																										/\       /\
                                                   /  \     /  \
																									/ Ex \   / Dx \
																								 /______\ /______\
```

| h(Ex) - h(Dx) | <= 1

### Árvore de Fibonacci (AVL de menor n para cada h)

h = 0 ----------> `vazio`

h = 1 ---------->  `*`

h = 2 ---------->```*
                     \
										  *
```

h = 3 ---------->```*
                   / \
									*   *
									     \
											  *```

h = 4 ---------->```*
                   / \
									/   \
								 *     *
									\   / \
									 * *   *
									        \
													 *```

h = 5 ---------->```*
                   / \
									/   \ 
								A(3) A(4)```

Onde A(3) é a árvore de h = 3 e A(4) é a árvore de h = 4.

### Teorema

Toda árvore de Fibonacci de altura h >= 2 e n nós é tal que n >= 2 ^ floor(h/2).

**prova**: Por indução em h:

- caso base: Seja h = 1. 2 ^ floor(h/2) = 2 ^ floor(1/2) = 1 = n, como queriamos provar.
Seja h = 2. 2 ^ floor(h/2) = 2 ^ floor(2/2) = 2 = n, como queriamos provar.

**passo de indução**: considere umma árvore de fibonacci de altura h+2, com h >= 1

								*
							 / \
							/   \
						h{.....}h+1

E seja n(h) o número de nós de uma árvore de fibonacci de altura h. Temos então:

n(h+2) = 1 + n(h) + n(h+1) // Definição de árvore de fibonacci
       > 1 + 2 * n(h) // n(h+1) > n(h)
			 > 2 * n(h)
			>= 2 * 2 ^ floor(h/2) // Pela hipótese de indução

Analisemos a paridade de h:

1. Se h for par: Logo, h = 2k, para algum k >= 1. Temos:

n(h+2) >= 2 * 2 ^ floor(h/2) = 2 * 2 ^ floor(2k/2) = 2 * 2 ^ k = 2 ^ k+1 = 2 ^ floor((2k + 2)/2), como queriamos demonstrar

2. Se h for impar: logo, h = 2k + 1 para algum k >= 0. Temos:

n(h+2) > 2 * 2 ^ floor(h/2) = 2 * 2 ^ floor((2k+1)/2) = 2 * 2 ^ k = 2 ^ k+1 = 2 ^ floor((2k+1) / 2), como queriamos demonstrar.

Logo, o passo está provado, concluindo a prova.

### Corolário

Toda árvore AVL de altura h >= 2 e n nós é tal que n >= 2 ^ floor(h/2).

**prova**: segue do lema anterior, uma vez que tod árvore AVL de altura h possui pelo mens o número de nós de uma árvore de fibonacci de altura h.

### Teorema

Para árvores AVL, sendo h a altura de n o número de nós, h = O(log n)

**prova**: Pelo corolário anterior,

2 ^ floor(h/2) <= n
floor(h/2) < log n
h/2 <= 1 + log n
h <= 2 + 2 * log n
h = O(log n)

## Inserção em árvore AVL

### Inserção AVL

**Árvore vazia**: trivial. Apontamos raiz para o novo elemento.


**Árvore não-vazia**:
											 x
											/ \
										 /   \
										/     \
									 /       \
									/\       /\
                 /  \     /  \
								/ Ex \   / Dx \
							 /______\ /______\

Suponha, sem perda de generalidade(pela simetria), que a inserção do novo elemento aconteceu à direita, transformando DX em DX'.

											 x                                       x
											/ \                                     / \
										 /   \                                   /   \
										/     \           Após inserção         /     \
									 /       \   ------------------------->  /       \
									/\       /\                             /\       /\
                 /  \     /  \                           /  \     /  \
								/ Ex \   / Dx \                         / Ex \   / Dx'\
							 /______\ /______\                       /______\ /______\

São 2 casos:

**1** => h(Dx') = H(Dx). Nesse caso, nada mais precisa ser feito e a altura da árvore enraizada em x não mudou.

**2** => H(Dx1 = H(Dx) + 1. São 3 casos:

1. h(Ex) = h + 1 = h(Dx) + 1: Nesse caso,

											 x                                       x
											/ \                                     / \
										 /   \                                   /   \
										/     \           Após inserção         /     \
									 /       \   ------------------------->  /       \
									/\       /\                             /\       /\
                 /  \     /  \                           /  \     /  \
						h+1	/ Ex \   / Dx \ h                   h+1 / Ex \   / Dx'\ h+1
							 /______\ /______\                       /______\ /______\

Nada mais precisa ser feito, e a altura da subárvore enraizada em x não mudou.

2. h(Ex) = h = h(Dx):

											 x                                       x
											/ \                                     / \
										 /   \                                   /   \
										/     \           Após inserção         /     \
									 /       \   ------------------------->  /       \
									/\       /\                             /\       /\
                 /  \     /  \                           /  \     /  \
						  h / Ex \   / Dx \ h                     h / Ex \   / Dx'\ h+1
							 /______\ /______\                       /______\ /______\

Nesse caso, a árvore continua AVL, mas a altura aumentou!

3. h(Dx) = h + 1 = h(Ex) + 1

											 x                                       x
											/ \                                     / \
										 /   \                                   /   \
										/     \           Após inserção         /     \
									 /       \   ------------------------->  /       \
									/\       /\                             /\       /\
                 /  \     /  \                           /  \     /  \
						  h / Ex \   / Dx \ h+1                   h / Ex \   / Dx'\ h+2
							 /______\ /______\                       /______\ /______\

Como h(Dx') != 0,



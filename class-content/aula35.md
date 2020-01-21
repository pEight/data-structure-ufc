# Aula 35

## Inserção em AVL

### Revisão

- Desejamos inserir um elemento numa árvore AVL A, gerando uma nova árvore AVL A'. O procedimento será recursivo.

- Se A = ø, a inserção é trivial, gerando uma árvore AVL de 1 nó e altura 1. Logo, h(A') > h(A): é necessário checar se os ascendentes do nó inserido é ficaram desbalanceados.

- Se A != ø, então A = x e nós trataremos o caso de inserção à dieita de x(o caso à esquerda é simétrico). Suponhamos que a inserção em Dx leva a uma nova árvore AVL Dx'.

- SE h(Dx') = h(Dx), então x continua balanceado após a inserção, pois já estava antes e basta fazer

                x
               / \
              /   \
             /     \
A' = 				/       \ 
           /\       /\
          /  \     /  \
         / Ex \   / Dx'\
				/______\ /______\

Observe que h(A') = h(A), logo os ascendentes de  certamente ficaram desbalanceados.

- Se h(Dx') > h(Dx), então h(Dx') = h(Dx) + 1

- Os casos h(Ex) = h(Dx) são triviais, pois a árvore já é AVL, mas h(A') = h(A)+1 no caso h(Ex) = h(Dx).

                x
               / \
              /   \
             /     \
A' = 				/       \ 
           /\       /\
          /  \     /  \
         / Ex \   / Dx'\
				/______\ /______\

- O caso h(Dx) = h(Ex) + 1 precisa de tratamento, pois a árvore

                x
               / \
              /   \
             /     \
A' = 				/       \                não é AVL
           /\       /\
          /  \     /  \
       h / Ex \   / Dx'\ h+2
				/______\ /______\

### Correção da Árvore AVL na inserção AVL:

                x
               / \
              /   \
             /     \
A' = 				/       \
           /\       /\
          /  \     /  \
       h / Ex \   / Dx'\ h+1
				/______\ /______\

Inserção

                x
               / \
              /   \
             /     \
A' = 				/       \
           /\       /\
          /  \     /  \
       h / Ex \   / Dx'\ h+2
				/______\ /______\

Sugestão da aula passada: obser que Dx' != ø,

logo Dx' =   y
            / \
					 /   \
					/     \
				 /       \
        /\       /\
       /  \     /  \
      / Ey \   / Dy \
		 /______\ /______\


e 
                x
               / \
              /   \
             /     \
A' = 				/       \
           /\        y
          /  \      / \
         / Ex \    /   \
				/______\  /     \
			           /       \
                /\       /\
               /  \     /  \
              / Ey \   / Dy \
		         /______\ /______\


Sugestão

                y
               / \
              /   \
             /     \
A'' = 			/       \
           x        /\
					/ \      /  \
				 /   \    / Dy \
				/     \  /______\
			 /       \
      /\       /\ 
     /  \     /  \
    / Ex \   / Ey \
	 /______\ /______\

**Olhar 1.2 e 1.3 da foto de aula 35**.

### Observação final sobre inserção AVL

O caso 1.2 é impossível! De fato, observe que, em todos os casos do algoritmo de inserção, não acontece simultaneamente de:

1. A altura da árvore resultante ser maor que a da original.

2. A raiz da árvore resultante ter subárvores de mesma altura, sendo essa altura > 0.

# Aula 18

## Conjunto Dinâmico via Lista Encadeada

### Objetivos:

Desejamos implementar as operações "inserir(C, e)", "pertence(C, e)", "remover(C, e)" e também percuso.

Diferentemente de antes, a operação de remoção receberá um iterador para o elemento a ser removido(útil em aplicações nas quais são guardadas "referências"(ponteiros, iteradores, etc) aos elementos do conjunto).

Devido ao item anterior, as operações de inserção e consulta retornam iteradores(apontando para o fim, em caso de erro ou de não pertencimento).

### Representação



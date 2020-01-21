# Aula 22

## Recapitulando Definição

Dada g: N -> N

O(g) = { f: N -> N | existem m pertecente a N* e c pertencente a R*+ tais que, para todo n >= m, 0 <= f(n) <= c * g(n) }

Como um abuso de notação, dadas "f" e "g", se f pertence O(g), nós dizemos que "f=O(g)" (Com intenção de dizer "f é da ordem de g, no máximo").

f(n) <= g(n)

**Teorema 1**: 1000n = O(5n^2)

1000n <= c * 5n^2
1000 <= c * 5n
200 <= c * n
c * n >= 200

Solução 1:
m = 200 e c = 1.

Solução 2:
m = 1
c = 200

**Prova 1**: Sejam f(n) = 1000n e g(n) = 5n^2. Temos que mostrar então que existem m pertence a N* e c pertence a R*+ tais que, para todo n >= m, 0 <= f(n) <= g(n). Sejam então m = 200, c = 1 e n >=m, temos:

1. 0 <= 1000
     <= 1000n, pois n >= 1

2. 200 <= 200
       <= n   (n >= m = 200)
       <= c*n (c >= 1)
  => 200n <= c*n^2 (n >= 0)
  => 1000n <= c*n^2*5

**Prova 2**: Sejam então m = 1, c = 200 e n >= m. Temos então:

1. 0 <= 1000
     <= 1000n, pois n >= 1

2. 200 <= 200
       <= c    (c >= 200)
       <= c*n  (n >= 1)
  => 200n <= c*n^2 (n >= 0)
  => 1000n <= c*5*n^2

**Teorema 2**: 5*n^2 = O(n^2)
**prova**: trivial, com c=5 e m=1

**Teorema 3**: n = O(5n + 7)
**prova**: trivial, com c=1 e m=1

**Teorema 4**: 5n+7 = O(n)

5 * n + 7 <= c * n

7 <= c * n - 5 * n
7 <= n(c - 5)

Sendo n >= 1, isso vale por que m >= 1 e n >= m. Como m >= 1, podemos afirmar isso.
c >= 12

**prova**: com f(n) = 5*n+7 e g(n) = n.
Sejam então n = 1, c = 12 e n >= m. Temos

1. 0 <= 7 <= 7+5*n pois n >= 0

2. 12 <= c
 =>7 >= c-5
 =>7 <= n(c-5) pois n >= 1
 =>5n+7 <= c*n

**Teorema 5**: n^2 != O(n), isto é, não é o caso que n^2 = O(n)

n^2 <= c*n
n <= c (n > 0)

falso para n = teto de c+1

**prova**: Suponha, por absurdo que n^2 = O(n). Logo, existe m pertencente a N* e c pertencente a R*+ tais que, para todo n >= m,

0 <= n^2 <= c*n

Seja então n = máx{teto de c+1, m}. Como n >= m então

    n^2 <= c*n
n>0
=>  n <= c
=> max{teto de c+1, m} <= c
=> teto de c+1 <= c
=> c+1 <= c, um absurdo!


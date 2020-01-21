# Aula 27

## Método da multiplicação

### Implementação

**Passo 1**: não representar A em ponto flutuante, mas sim por meio de um inteiro sem sinal "s" tal que A = s / (2^w), sendo "w" o número de bits da palavra de memória("word")

**Exemplo**: A = 0,101 = 0,5 + 0,125  0,625

```
s = | 1 | 0 | 1 | ...
```

**Passo 2**: para calcular c * A - floor(c * A), observar que o resultado está em c * s, faltando apenas dividir por 2^w

```
c: |  |  |  |  |  |  |  |  |

s: |  |  |  |  |  |  |  |  |
```

```(c * A) / (2^w):
                         2^w          c * s
|  |  |  |  |  |  |  |  |, |  |  |  |  |  |  |  |  |
```

**Passo 3:** para multiplicar por "m" e tirar o piso, observe que isso é muito mais fácil sem `m = 2^p`, para algum "p".

```
c * s: |//////////|
```

```
m = 2^p
                |p bits|    |w - p bits| p zeros |
c * s * m |     |//////|    |//////////|         |
```

Além disso, tirar o piso do resultado significa considerar peas os p bits mais significativos do resultado, e isso é o mesmo que deslocar c * s à direita por w - p bits (com p != 0).

```
        p bits
c * s: |//////|//////////|
               w - p bits
```

```
                                p bits
(c * s) >> (w - p): |//////////|//////|
                      w-p zeros
```

Em resumo: fazendo

- A = s / (2^w), sendo s > 1
- m = 2^p, sendo p != 0 (m != 1),

então

```
floor((c * A - floor(c * A)) * m)
```

pode ser encontrado via 

```
(c * s) >> (w - p)
```

### Observações

1. s ímpar (Evitar fator 2 comum entre c * s e w - p, tendo em vista que `>> (w-p)` é o mesmo que `/2^p`)

2. p != 0, isto é, m != 1, pois `>>w` é "undefined behaviour" em c++.

3. Knuth sugere A ser aproximadamente (sqrt(5) - 1) / 2, isto é, 0,6180339887 e 32 bits, então s = 2654435769

4. Se s for escolhido aleatoriamente, então o método da multiplicação gera uma coleção universal de funções de dispersão.

## Endereçamento aberto

Introdução: o método de resolução de colisões por 
**endereçamento aberto** leva a ideia de "calcular a posição das chaves" um passo adiante: se uma chave não estiver na posição inicialmente esperada, então nós calculamos a próxima posição a consultar.

Mais especificamente, o endereçamento aberto utiliza uma **função de sondagem** tal que

```h(c, i)```

Dá a i-ésima posição onde a chave c pode estar, com i pertencente ao intervalo [0...m-1]

Toda função de sondagem tem que ser tal que

< h(c,0), h(c, 1), ..., h(c, m-1) >

é uma permutação de < 0, 1, 2, ..., m-1 >
# Aula 26

## Funções de dispersão

### Observações sobre o método da divisão

Se m=2^p, para algum p(ou seja, m potência de 2), então nem todos os **w** bits da chave serão usados: só o serão os **p** bits menos significativos.

```
chave c
  0   1   2   3   4   5   6   7
|   |   |   |   |   |   |   |   |
```

0 a 3 => ignorados
4 a 7 => usados

p = 4
w = 8

Veja que ao fazer (x*100 + y) % 100 = y. O mesmo vale para (x*8 + y) % 8 = y. E assim para cada caso que eu pegar o resto da divisão de um número por seu múltiplo. Isso faz com que ignoremos os primeiros bits de uma chave e que assim os elementos caiam em uma mesma posição no vetor da tabela de dispersão. **Tirando raciocínio a partir de uma explicação dada em sala de aula**.

Essa situação tende a ser ruim, pois os w - p bits mais à esquerda poderiam ajudar a fonecer variação entre as chaves.

m = 12

| chaves | 0 | 4 | 8 | 12 | 16 | 20 | 24 |
|------- |---|---|----|---|----|----|----|
|  h(c)  | 0 | 4 | 8  | 0 | 4  | 8  | 0  |

Veja que os casos estão caindo em multiplos de 2.

Além disso, se as chaves em tiverem um fator comum k, então apenas as posições da tabela que são múltiplas de k serão preenchidas.

Para evitar a possibilidade de haver fatores comuns entre m e as chaves, o método da divisão é tipicamente acompanhado pela  escolha de números **primos** para m, os quais na prática são pré-computados e inseridos diretamente no código.

Por fim, são escolhidos primos "longe" de potências de 2, ou seja, próximos de:

```
(2^i + 2^i+1) / 2, para algum i
```

### Método da multiplicação de dispersão

```
h(c) = floor((c*A - floor(c*A))*m)
```

1. Multiplicar "c" e "A"
2. Pegar a parte fracionária do resultado(descartar a parte inteira): `c*A - floor(c*A)`

**Intuição**: se 0 < A < 1, então

A = 0, ... ou seja:

```
c : |   |   |   |   |   |
A : 0,1001001 <- exemplo
```

(**Olhar as fotos de aula colocadas no sigaa pelo professor**)

Podemos observar que, partindo de uma representação de A na base 2:

* Os dígitos1 de A correspondem a cópias de c no algoritmo "matemático" de multiicação.
* As posições desses 1's dirão os deslocamentos à esquerda das cópias de c.

De forma geral, a intenção com multiplicar por A é somar c consigo mesma algmas vezes, de forma "imprevisível/desordenada", devido aos deslocamentos à esquerda.

Depois disso, "c * A - floor(c * A)" é um número de 0 a 1, e multiplicar por m é uma maneira de obter algo no intervalo das chaves ([0...m]). O piso final é apenas uma maneira de garantir um número natural.

**Computação na prática**

```
Passo 1 - representação de A:
  A = s / 2^w, onde w é o número de bits da palavra de memória e **s** e { 1, ..., (2^w) - 1 }

  0,1001 = (1/2 + 1/16) = 9/16 = (1001 na base 10 / 2^4)

Passo 2 - c * A = c * (s / 2^w)
```

(**Olhar foto da aula para o passo 2**)


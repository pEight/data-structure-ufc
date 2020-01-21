# Aula 28

## Endereçamento aberto

### Introdução

**Ideia central**: resolver colisões não via listas encadeadas, mas sim calculando uma 2ª, 3ª, 4ª, ..., m - 1ª posições para cada chave, e usando-as quando necessário.

No caso geral, **h(c, t)** dá a **t**-ésima posição possível para a chave **c**, com t pertencente a [0...m-1].

Nesse caso, as chaves/elementos ficam na própria tabela(vetor), e algumas posições possuirão chaves e outras não.

A expansão da tabela se dá quando alpha = n/m, o **fator de carga**, ultrapassa um certo limite alpha max, havendo contração quando alpha < alpha min.

### Sondagem linear

h(c, t) = (h'(c) + t) % m

### Exemplo inicial

- h'(c) = c % m
- alpha max = 0,75
- alpha min = 0,25

### Como representar "vazio" e "apagado"

**Valores especiais**: se houver 2 valores do tipo T dos elementos da tabela que não correspondem a chaves, então eles podem ser usados para representar "vazio" e "apagado". Exemplo: se as chaves têm tipo **unsigned int** e todas são menores que "UINT_MAX - 1", então  UNINT_MAX -> "vazio" e UNINT_MX - 1 -> "apagado"
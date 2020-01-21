# Aula 25

## Tabelas de dispersão

### Introdução

A ideia central é armazenar uma chave numa posição de vetor que  guarde alguma relação com a chave, e não numa posição puramente circunstancial. Mais especificamente, nós desejamos **calcular** a posição a partir da chave.

Tecnicamente, nós chamamos o mapeamento das chaves nas posições do vetor de **função de dispersão**.

Um exemplo simples é o **método da divião**: se a chave é um número natural **c** e o vetor (tabela) possui **m** posições, então a posição de "c" é h(C) = c % m ("h" de "hash function").

### Observações sobre o tipo das chaves

Muitas vezes, as chaves já são números naturais (como CPF)

Em outras, é fácil criar, artificialmente, chave que são números naturais (como o número de mátricula: antes de entrar na UFC, o aluno não possui um número de matrícula, mas ganha um ao entrar).

Quando a chave não é um número natural, será necessário, convertê-la em um. Nesse sentido, cabe lembrar que, num computador digital moderno, todo dado é amazenado em dígitos binários, logo tal conversão em princípio é possível e até **já existe de alguma forma**. Uma string por exemplo, pode ser entendida como uma gande sequência de dígitos na base 2, um como um número numa base em que cada símbolo é um dígito.

De forma geral, é importante que a função de dispersão consiga utilizar o que há de **diferente** entre as chaves, de forma a conseguir espalhá-las na tabela.

Assim, por exemplo, se as chaves forem as matrículas de alunos que entraram num mesmo curso da UFC num mesmo período letivo, então os dígitos iniciais serão provavelmente os mesmos, e os dígitos finais serão aqueles que fornecerão a maior **variação**.

### Resolução de colisões

Tipicamente, uma função de dispersão será uma função

h: U -> { 0, ..., m-1 },

em que |U| é muito maior que "m". Logo, haverá **colisões**. Uma maneira de resolver colisões é faze um **encadeamento externo**: uma lista encadeada para cada posição **i** da tabela, contendo as chaves **c** tais que h(c) = i.

### Exemplo

Abaixo, ilustraremos uma tabela com dispersão pelo método da divisão, resolução de colisões via encadeamento externo, e redimensionamento para o dobro ou a metade.

T = Tabela de  dispersão

**Ver foto das aulas colocada pelo professor no sistema**

**Observação 1**: Veja que se eu colocar elementos que são potência de m mais + um x, sendo x um número natural, então os números cairão no índice x do vetor da tabela de dispersão. **Analisar o desenho**.
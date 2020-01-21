# Aula 38

## Filas de prioridade

### Introdução

A fila de prioridades é um TAD no qual estamos sempre interessados no maior(ou num máximo) dentre os elementos correntemente armazenados. As operações principais são:

**Inserir(F, e)**: insere o elemento E na fila de prioridades F.

**Consultar_max(F)**: Retorna, sem remover, um elemento máximo de F.

**Remover_max(F)**: Remove um elemento máximo de F.


| Estrutura               | Inserir  | Consultar | Remover  |
| ----------------------- | -------- | --------- | -------- |
| vertor ñ ordernado      |  O(1)    |    O(1)   |   O(n)   |
| vetor ordenado          |  O(n)    |    O(1)   |   O(1)   |
| lista encad. ñ ord.     |  O(1)    |    O(1)   |   O(n)   |
| lista encad. ord.       |  O(n)    |    O(1)   |   O(1)   |
| tabela disp. enc ext.   |  O(1)    |    O(1)   |   O(n)   |
| tabela disp. end aberto |  O(n)    |    O(1)   |   O(n)   |
| árv. bin. de busca      |  O(n)    |    O(1)   |   O(n)   |
| árvore AVL              | O(log n) |    O(1)   | O(log n) |


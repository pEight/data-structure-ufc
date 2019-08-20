# Aula 4

## Conversão vetor-ponteiro

Uma expressão de tipo "vetor de (elementos de tipo) T" pode ser implicitamente convertida para o tipo "ponteiro para T". Informalmente, tal conversão acontecerá quando a expressão for usada num contexto em que um ponteiro, mas não um vetor, é esperado. O ponteiro resultante aponta para o 1º elemento do vetor.

**Exemplo**: 

```cpp
int v[5];

int* primeiro = v; // O mesmo que &v[0]
int* ultimo = v+4; // O mesmo que &v[4]

/* Observe que "v" continua sendo um vetor de inteiros; Apenas as ocorrências de "v"
nas 2 linhas anteriores são expressões que sofrem conversão implícita */
```

## Definição do operador []

Se p é um ponteiro e i é um inteiro, então:

```cpp
p[i] = *(p+i)
```

**Exemplo**:
```cpp
#include <iostream>

double soma(double* v, int n) {
  double s = 0; int i;
  for(i = 0; i < n; i++) {
    s += v[i]
  }

  return s;
}

int main() {
  double v[5] = {1, 2, 3, 4, 5};
  std::cout << soma(v,5) << '\n';
}
```

## Ponteiro nulo

Um ponteiro pode armazenar o valor zero; Nesse caso, é garantido que ele não estará apontando para qualquer variável ou semelhante objeto do programa, pois nenhum objeto estará armazenado neste endereço. O valor zero é, portanto, um valor especial para um ponteiro, e como tal é utilizado para indicar circunstâncias especiais (um exemplo típico será apresentado a seguir).

Embora seja completamente válido atribuir e comparar ponteiros e a constante inteira "0", é preferível usar a constante `nullptr`, que serve especificamente para representar um ponteiro nulo, e não se converte implicitamente para inteiro.

**Exemplo**:
```cpp
int i;

if (&i == nullptr) {
  cout << "Absurdo!\n";
}

int* p = nullptr; // ou "... = ;0"

if (p != &i) {
  cout << "Sempre true!\n";
}
```

## Alocação dinâmica

### Duração de armazenamento

É a informação da duração mínima de um objeto na memória de um programa em C++. Os quatro tipos são:

1. Estática: o objeto dura por toda a execução do programa.
2. "Thread": o objeto dura enquanto a "thread" a que ele pertence estiver sendo executada.
3. Automática: o objeto dura até o fluxo da execução do programa sair do bloco em que o objeto foi criado (o objeto é criado após o fluxo entrar no bloco)
4. Dinâmica: tanto a criação (reserva da memória) do objeto quanto a "destruição" (desassociação da memória ao programa) do mesmo acontecem em momentos determinados pelo programador.

**Observações**: Variáveis declaradas na função `main` são automáticas. Podemos pensar que é estática por que ela dura até o final da execução do programa, mas esse fator é coincidência. Elas são automáticas porque duram até o fim do fluxo de execução do bloco na função `main`. E essa função `main` dura até o fim da execução do programa.

**Exemplo**:

```cpp
#include <iostream>

int ie = 3; double de=3.14; // Duração estática

bool eh_zero(int n) {
  return (n == 0);
}

int main() {
  double x = n;
  if(eh_zero(ie)) {
    cout << "Nunca ocorre!\n";
  }
}
```

### Alocação dinâmica

1. Não-vetores:
```cpp

int main() {
  double* p = new double;
  *p = 3.14;
  delete p;
}
```

2. Vetores:
```cpp
#include <iostream>

using std::cin; using std::cout;

double soma(double* v, int n) {
  ... como antes ...
}

double* ler_vetor(int n) {
  double *v = new double[n];
  int i;
  for (i = 0; i < n; i += 1) {
    cout << "v[" << i << "]: ";
    cin >> v[i];
  }
}

int main() {
  int n = 5;
  double* v = ler_vetor(n);
  cout << "Soma: " << soma(v,n) << '\n';
  delete[] v;
}
```
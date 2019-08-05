# Aula 01

## Introdução a C++

Para iniciarmos a programar em C++, criamos um arquivo com extensão `cpp`. Por exemplo, `meu-prog.cpp`. Todo arquivo tem uma função main. Toda vez que o programa for executada, a função main é executada. Uma função em C++ segue a seguinte sintaxe:

```cpp
<tipo> <func-name>([args]) {
  <body>
}
```

exemplo:
```cpp
int main() {
  return 13;
}
```

Para compilarmos o programo em C++, usamos:

```shellscript
$ g++ <nome-arquivo>.cpp
```

Esse comando gera o `<nome-arquivo>.out`.

Em C++, um retorno 0, significa que a operação foi bem sucedida. Caso retorne 1, a operação não foi bem sucedida. Caso não exista nenhum expressão de retorno na função, é retornado o valor 0.

Utilizando a flag `-Wall` e `-Wextra`, o processo de compilação nos retorna warnings que possivelmente podem ser gerado por nossos arquivos. Podemos também definir a versão que queremos usar. Fazemos isso com `-std=c++17`.

Pode ser que queiramos imprimir na tela do terminal algum valor. No python usamos o `printf`. No C++ usamos o `cout` da biblioteca `iostream`:

```cpp
cout << "Olá, mundo!\n";
```

ou

```cpp
cout << "Olá"
     << ",mundo!"
     << "\n";
```

Antes de usar esse "printf" do C++, é necessário importar a biblioteca iostream.

```cpp
#include <iostream>
```

Em C, tudo que é importado fica no escopo global. Ou seja, caso seja importando uma biblioteca com função `sum` e depois criarmos uma função de mesmo nome, a primeira função será sobrescrita. Em C++, podemos escrever uma expressão que diga de onde vem aquela função, assim não sobrescrevendo alguma outra função de mesmo nome. Basicamente, dizemos de onde vem aquela função usando:
```cpp
using std::cout;
```

Caso quisermos utilizar tudo da biblioteca(Não recomendado), usamos:
```cpp
using namespace std
```

Outra situação que pode ser comum é a de querer pegar uma informação via teclado do usuário. Semelhante ao `scanf` do C, utilizamos o `cin`. Observe o código abaixo:

```cpp
cin >> <nome-variavel>
```

## Tipos primitivos em C++

| Tipos | exemplo |
| ----- | ------- |
| int | `int x = 0` |
| double | `double x = 3.14` |
| float | `float x = 3.14` |
| char | `char x = 'p'` |
| bool | `bool isTrue = true` |

Podemos criar listas de valores primitivos em C++. A sintaxe é parecida com linguagens como Java e Dart. Precisamos obrigatoriamente passar o tamanho do vetor. Observe o código abaixo:

```cpp
double arr[10];

arr[0] = 3.14;
```

**Declarando um vetor**: int <nome-vetor>[<numero-de-itens>].

## Struct

Em C++ podemos criar estrutura de registros da seguinte forma:

```cpp
struct Par {
  double x, y;
};
```

**Criando vetores de registros**:
```cpp
Par vp[30];
vp[0].x = 3.14;
vp[0].y = 6.28;
```

## EStrutura de fluxo

Parecido com a sintaxe de outras linguagens, no C++ utilizamos:
```cpp

if (<condition>) {

} else {

}
```

ou

```cpp
switch(<condition>) {
  case <case1>:
    ...
    break;
  case <case2>:
    ...
    break;
  default:
    ...
    break;
}
```
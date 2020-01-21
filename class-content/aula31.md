# Aula 31

## Árvore binárias de busca

## Busca

```cpp
template <typename T>
struct Noh {
	T elem;
	Noh<T> *fesq, *fdir
};

template <typename T>
bool pertence (Noh<T> *raiz, T e) {
	if(raiz == nullptr) return false;

	if(e == raiz->elem) return true;

	if (e < raiz->elem) {
		return pertence(raiz->fesq, e);
	} else {
		return pertence(raiz->fdir, e);
	}
}
```

### Altura
A altura de uma árvore é o número de níveis que uma árvore possui.

```cpp
template <typename T>
int altura(Noh<T> *raiz) {
	if (raiz == nullptr) return 0;
	
	int hE = altura(raiz->fesq);
	int hD = altura(raiz-fdir);

	if (hE < hD) return 1 + hD;

	return 1 + hE;
}
```

### Exemplo de percurso pós-ordem

```cpp
template <typename T>

int imprimir_alturas(Noh<T> *raiz) {
	if (raiz == nullptr) return 0;

	int hE = imprimir_alturas(raiz->fesq);
	int hD = imprimir_alturas(raiz->fdir);

	int h;
	if (hE < hD) {
		h = 1 + hD;
	} else {
		h = 1 + hE;
	}

	cout << "h(" << raiz->elem << "): " << h << "\n";
	return h;
}
```

Analisar o código acima!

### Exercício em sala

```cpp
template <typename T>
void imprimir_profundidade(Noh<T> *raiz, int prof_pai) {
	if (raiz == nullptr) return;

	int p = prof_pai + 1;
	cout << "prof(" raiz->elem << "): " << p << "\n";
	
	imprimir_profundidade(raiz->fesq, p);
	imprimir_profundidade(raiz->fdir, p);
}
```

Percurso pré-ordem!








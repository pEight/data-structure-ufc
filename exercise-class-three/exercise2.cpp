#include <iostream>

using std::cout;
using std::cin;

int sizeOfArr(double* first, double* last) {
  double* i;
  int count = 0;

  for(i = first; i <= last; i += 1) {
    count += 1;
  }

  return count;
}

void reverse(double* first, double* last) {
  double temp;
  int size = sizeOfArr(first, last);
  double* sizeIteration;

  if (size % 2 == 0) {
    sizeIteration = first + (size / 2);
  } else {
    sizeIteration = first + ((size - 1) / 2);
  }

  while(first < sizeIteration) {
    temp = *first;
    *first = *last;
    *last = temp;

    first += 1;
    last -= 1;
  }
}

void printArr(double* arr, int n) {
  cout << "Array: [ ";
  for (int i = 0; i < n; i += 1) {
    cout << arr[i] << " ";
  }

  cout << "]\n";
}

void writeArr(double* arr, int n) {
  double* i;
  double* size = arr + n;

  for (i = arr; i < size; i += 1) {
    cout << "Digite um valor: ";
    cin >> *(i);
  }
}

int main() {
  int size;
  cout << "Digite o tamanho da array: ";
  cin >> size;

  double arr[size];

  writeArr(arr, size);
  printArr(arr, size);

  reverse(&(arr[0]), &(arr[size - 1]));
  printArr(arr, size);


  return 0;
}
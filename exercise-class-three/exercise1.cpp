#include <iostream>

using std::cout;
using std::cin;

int numbOfRepeat(double* arr, int n, double x) {
  int count = 0;
  double* i;
  double* size = arr + n;

  for (i = arr; i < size; i += 1) {
    if (*(i) == x) {
      count += 1;
    }
  }

  return count;
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


  double numberToSearch;
  cout << "Pesquisar número: ";
  cin >> numberToSearch;
  cout << "Numero de repetições do número " << numberToSearch << ": "
       << numbOfRepeat(arr, size, numberToSearch) << "\n";

  return 0;
}
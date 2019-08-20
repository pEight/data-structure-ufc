#include <iostream>

using std::cout;
using std::cin;

void reverse(int* arr) {
  int temp;
  for(int i = 0; i <= 3; i += 1) { 
    temp = arr[i];
    arr[i] = arr[6 - i];
    arr[6 - i] = temp;
  }
}

void printArr(int* arr) {
  cout << "Array: [ ";
  for (int i = 0; i < 7; i += 1) {
    cout << arr[i] << " ";
  }

  cout << "]\n";
}

int main() {
  int arr[7];

  for (int i = 0; i < 7; i += 1) {
    cout << "Valor de vetor[" << i << "]: ";
    cin >> arr[i];
  }

  printArr(arr);
  reverse(arr);
  printArr(arr);

  return 0;
}
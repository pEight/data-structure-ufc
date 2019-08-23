#include <iostream>

using std::cout;
using std::cin;

char* initArray(int n) {
  return new char[n];
}

void deleteArray(char* arr) {
  delete[] arr;
}

char* resizedArray(char* oldArr, int n) {
  char* arr = new char[n];

  for(int j = 0; j < n; j += 1) {
    arr[j] = oldArr[j];
  }

  deleteArray(oldArr);
  return arr;
}

void printMsg(char* arr, int n) {
  cout << "\nMensagem digitada:\n";
  for(int i = 0; i < n; i += 1) {
    cout << arr[i];
  }
  cout << "\n";
}

int main() {
  int size = 20;
  char* msg = initArray(size);

  cout << "Digite uma linha de texto:\n";

  int i = 0;
  do {
    cin.get(msg[i]);

    if (i == size - 1 && msg[i] != '\n') {
      size += 5;
      msg = resizedArray(msg, size);
    }

    i += 1;
  } while(msg[i-1] != '\n');

  printMsg(msg, size);

  return 0;
}
#include <iostream>

using std::cout;
using std::cin;

double* create_points(int n) {
  double* arr = new double[n];

  for(int i = 0; i < n; i += 1) {
    cout << "Digite o valor para v[" << i << "]: ";
    cin >> arr[i];
  }

  return arr;
}

double arrMedia(double* arr, int n) {
  double s = 0;
  for(int i = 0; i < n; i += 1) {
    s += arr[i];
  }

  return s / n;
}

void diffMedia(double* arr, double media, int n) {
  for (int i = 0; i < n; i += 1) {
    if (arr[i] > media) {
      double diff = arr[i] - media;
      cout << "O aluno " << i << " está " << diff << " acima da média\n";
    } else {
      double diff = media - arr[i];
      cout << "O aluno " << i << " está " << diff << " abaixo da média\n";
    }
  }
}

int main() {
  int n;
  double media;

  cout << "Número de alunos: ";
  cin >> n;
  cout << "\n";

  double* arr = create_points(n);
  media = arrMedia(arr, n);

  cout << "\nMédia: " << media << "\n\n";
  
  diffMedia(arr, media, n);

  cout << arr[0];
  return 0;
}
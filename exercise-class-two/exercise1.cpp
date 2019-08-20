#include <iostream>

using std::cout;
using std::cin;

void change(int* x, int* y) {
  int temp = *x;
  *x = *y;
  *y = temp;
}

int main() {
  int a = 1;
  int b = 2;

  cout << "'A' before change: " << a << "\n";
  cout << "'B' before change: " << b << "\n";

  change(&a, &b);

  cout << "'A' after change: " << a << "\n";
  cout << "'B' after change: " << b << "\n";

  return 0;
}
#include <iostream>
#include <math.h>
#include "headers/stack.h"
#include "headers/stackInt.h"

using std::cout;
using std::cin;
using std::pow;

double calculate(double operand1, double operand2, char myOperator) {
  double result = 0;
  switch(myOperator) {
    case '+':
      result  = operand1 + operand2;
      break;
    case '-':
      result  = operand1 - operand2;
      break;
    case '*':
      result = operand1 * operand2;
      break;
    case '/':
      result = operand1 / operand2;
      break;
  }

  return result;
}

int main() {
  char msg[] = "(((5/2)+(0-3))*(((2-7)/10)/(2*5)))\n";

  Stack* operatorStack = createStack(40);
  StackInt* operandStack = createStackInt(40);

  int i = 0;
  double num = 0;
  double result = 0;
  bool findParenthesis;
  while(msg[i] != '\n') {
    if (msg[i] == '+' || msg[i] == '-' || msg[i] == '*' || msg[i] == '/') {
      pushToStack(operatorStack, msg[i]);
    }

    if (msg[i] >= '0' && msg[i] <= '9') {
      findParenthesis = false;
      num = num*10 + (msg[i] - '0');
    }

    if ((msg[i] == '+' || msg[i] == '-' || msg[i] == '*' || msg[i] == '/') && findParenthesis == false) {
      pushToStackInt(operandStack, num);
      num = 0;
    }

    if (msg[i] == ')') {
      num = (findParenthesis) ? popToStackInt(operandStack) : num;
      double value = popToStackInt(operandStack);
      char myOperator = popToStack(operatorStack);

      result = calculate(value, num, myOperator);
      cout << "Operando 1: " << value << "\n";
      cout << "Operando 2: " << num << "\n"; 
      cout << "Resultado: " << result << "\n\n";

      pushToStackInt(operandStack, result);

      num = 0;
      findParenthesis = true;
    }

    i+= 1;
  }

  cout << "\n" << "Resultado: " << result << "\n";
  deleteStack(operatorStack);
  deleteStackInt(operandStack);

  return 0;
}

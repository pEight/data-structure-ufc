#include "../headers/stackInt.h"
#include <iostream>

using std::cout;

StackInt* createStackInt(int size) {
  StackInt* myStack = new StackInt;

  myStack->arr = new double[size];
  myStack->top = 0;
  myStack->stackSize = size;

  return myStack;
}

bool deleteStackInt(StackInt* myStack) {
  delete myStack;
  return true;
}

bool pushToStackInt(StackInt* myStack, double value) {
  int index = myStack->top + 1;
  (myStack->arr)[index] = value;

  myStack->top += 1;

  return true;
}


double popToStackInt(StackInt* myStack) {
  double value = myStack->arr[myStack->top];
  myStack->top -= 1;

  return value;
}


bool isEmptyInt(StackInt* myStack) {
  if(myStack->top == 0) {
    return true;
  }

  return false;
}

bool isFullInt(StackInt* myStack) {
  if (myStack->top == myStack->stackSize - 1) {
    return true;
  }

  return false;
}

void printStackInt(StackInt* myStack) {
  double* arr = myStack->arr;

  int size = myStack->stackSize;

  for(int i = 0; i < size; i += 1) {
    cout << arr[i] << " ";
  }
}

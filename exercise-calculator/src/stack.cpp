#include "../headers/stack.h"
#include <iostream>

using std::cout;

Stack* createStack(int size) {
  Stack* myStack = new Stack;

  myStack->arr = new char[size];
  myStack->top = 0;
  myStack->stackSize = size;

  return myStack;
}

bool deleteStack(Stack* myStack) {
  delete myStack;
  return true;
}

bool pushToStack(Stack* myStack, char value) {
  int index = myStack->top + 1;
  (myStack->arr)[index] = value;

  myStack->top += 1;

  return true;
}


char popToStack(Stack* myStack) {
  int index = myStack->top;
  myStack->top -= 1;

  return myStack->arr[index];
}


bool isEmpty(Stack* myStack) {
  if(myStack->top == 0) {
    return true;
  }

  return false;
}

bool isFull(Stack* myStack) {
  if (myStack->top == myStack->stackSize - 1) {
    return true;
  }

  return false;
}

void printStack(Stack* myStack) {
  char* arr = myStack->arr;

  int size = myStack->stackSize;

  for(int i = 0; i < size; i += 1) {
    cout << arr[i] << " ";
  }
}

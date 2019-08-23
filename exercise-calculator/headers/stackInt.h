struct StackInt {
  double* arr;
  int top;
  int stackSize;
};


StackInt* createStackInt(int size);


bool deleteStackInt(StackInt* myStack);


bool pushToStackInt(StackInt* myStack, double value);


double popToStackInt(StackInt* myStack);


bool isEmptyInt(StackInt* myStack);


bool isFullInt(StackInt* myStack);


void printStackInt(StackInt* myStack);

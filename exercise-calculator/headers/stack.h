struct Stack {
  char* arr;
  int top;
  int stackSize;
};


Stack* createStack(int size);


bool deleteStack(Stack* myStack);


bool pushToStack(Stack* myStack, char value);


char popToStack(Stack* myStack);


bool isEmpty(Stack* myStack);


bool isFull(Stack* myStack);


void printStack(Stack* myStack);

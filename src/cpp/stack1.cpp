#include <iostream>
using namespace std;

struct ArrayStack {
  int peek; // stores the element at the top of the stack, -1 if empty.
  int capacity;  //
  int *array; // Underlying array which is used to store elements of stack.
};
// Initialise a stack.
ArrayStack* CreateStack(int capacity=1){
  ArrayStack* S = (ArrayStack*)malloc(sizeof(ArrayStack));
  if (!S){ // if no memory is allocated then return null.
    return nullptr;
  }
  S->capacity = capacity;
  S->peek = -1;
  S->array = (int*)malloc(S->capacity * sizeof(int));
  if (!S->array){
    return nullptr;
  }
  return S;
}
// return whether the stack is empty or not.
bool isEmpty(ArrayStack* S){
  return (S->peek == -1); // if element at the top is -1, then stack is empty.
}
// return whether the stack is full or not.
bool isFull(ArrayStack* S){
  return (S->peek == S->capacity -1);
}
// push data onto stack.
void push(ArrayStack* S, int data){
  if(isFull(S)){ // if stack is full,
    cout << "Stack OverFlow" << "\n";
  }
  else{
    S->array[++S->peek] = data;
  }
}

int pop(ArrayStack* S){
  if(isEmpty(S)){
    cout << "Stack UnderFlow" <<"\n";
    return -2;
  }
  else{
    return (S->array[S->peek--]);
  }
}
// driver function.
int main(){
  ArrayStack *S = CreateStack(10);
  cout << "Stack capacity :" << S->capacity << "\n";
  cout << "Element at top of Stack " << S->peek << "\n";
  cout << "Whether stack is empty " << isEmpty(S) << "\n";
  cout << "Whether stack is full " << isFull(S) << "\n";
  for(int i=0; i<12; i++){
    push(S, i);
    cout << S->peek << "\n";
  }

  return 0;
}

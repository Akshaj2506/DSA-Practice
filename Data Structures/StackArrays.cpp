#include <iostream>
using namespace std;

class MyStack {
   private:
      int capacity;
      int* arr;
      int top;

   public:
      MyStack(int capacity) {
         arr = new int[capacity];
         this -> capacity = capacity;
         top = -1;
   }

   void push(int num) {
      if (top == capacity - 1) {
         cout << "Stack Overflow" << endl;
         return;
      }
      else arr[++top] = num;
   }

   int pop() {
      if (top == -1) {
         cout << "Stack Underflow" << endl;
         return -1;
      }
      return arr[top--];
   }

   int peek() {
      if (top == -1) {
         cout << "Stack is empty" << endl;
         return -1;
      }
      return arr[top];
   }
};

int main() {
   MyStack stack(5);

   stack.push(5);
   stack.push(7);
   stack.push(8);
   stack.push(4);
   stack.push(3);
   cout << stack.pop() << endl;
   cout << stack.pop() << endl;
   cout << stack.pop() << endl;
   cout << stack.pop() << endl;
   cout << stack.pop() << endl;
   return 0;
}
#include <iostream>
using namespace std;

#define MAX 100
class DoubleEndedQueue {
   private:
      int front, rear, capacity;
      int queue[MAX];

   public:
      DoubleEndedQueue(int capacity) {
         this -> capacity = capacity;
         front = rear = -1;
      }

      int getFront() {
         if (front == -1) {
            cout << "Queue is empty" << endl;
            return -1;
         }
         return queue[front];
      }

      int getRear() {
         if (front == -1) {
            cout << "Queue is empty" << endl;
            return -1;
         }
         return queue[rear];
      }

      bool isFull() {
         return ((front == 0 && rear == capacity - 1) || front == rear + 1);
      }
      bool isEmpty() {
         return (rear == front == -1);
      }

      void pushFront(int num) {
         if (front == rear) {
            cout << "Queue is full" << endl;
            return;
         }
         if (front == -1) {
            front = rear = 0;
         }
         for (int i = 0; i < capacity; i++) {
            queue[i+1] = queue[i];
         }
         queue[front] = num;
         rear++;
      }

      void pushBack(int num) {
         
      }

      void popFront() {

      }

      void popBack() {
         
      }
};

int main() {
   DoubleEndedQueue q(5);
   return 0;
}
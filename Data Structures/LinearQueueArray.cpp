#include <iostream>
using namespace std;

class LinearQueue {
   private:
      int* queue;
      int front, rear, capacity;

   public:
      LinearQueue(int capacity) {
         this -> capacity = capacity;
         queue = new int[capacity];
         front = rear = 0;
      }

      void enqueue(int num) {
         if (rear == capacity) {
            cout << "Queue is full" << endl;
            return;
         }
         queue[rear++] = num;
      }

      void dequeue() {
         if (front == rear) {
            cout << "Queue is empty" << endl;
            return;
         }
         for (int i = 0; i < rear - 1; i++) {
            queue[i] = queue[i + 1];
         }
         rear--;
      }

      void print() {
         if (front == rear) {
            cout << "Queue is empty" << endl;
            return;
         }
         for (int i = front; i < rear; i++) {
            cout << " <- " << queue[i];
         }
         cout << endl;
      }
};

int main() {
   LinearQueue queue(5);
   queue.dequeue();
   queue.print();
   queue.enqueue(25);
   queue.enqueue(30);
   queue.enqueue(35);
   queue.enqueue(40);
   queue.enqueue(45);
   queue.enqueue(50);
   queue.print();
   queue.dequeue();
   queue.print();
   queue.dequeue();
   queue.print();
   queue.dequeue();
   queue.print();
   queue.dequeue();
   queue.print();
   queue.dequeue();
   queue.print();
   queue.dequeue();
   return 0;
}
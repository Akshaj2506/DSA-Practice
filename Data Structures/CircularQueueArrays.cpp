#include <iostream>
using namespace std;

class CircularQueue {
   private:
      int* queue;
      int front, rear, capacity;

   public:
      CircularQueue(int capacity) {
         this -> capacity = capacity;
         queue = new int[capacity];
         front = rear = -1;
      }

      void enqueue(int num) {
         if ((rear + 1) % capacity == front) { //Checking if queue is full
            cout << "Queue is full" << endl;
            return;
         }
         if (front == -1) {   // set front to 0 if first element of queue has been added
            front = 0;
         }
         rear = (rear + 1) % capacity;
         queue[rear] = num;
      }

      void dequeue() {
         if (front == -1) {  // if queue is empty
            cout << "Queue is empty" << endl;
            return;
         }
         if (front == rear) {  // if only one element is left inside the queue
            front = rear = -1;
         }
         else {
            front = (front + 1) % capacity;
         }
      }

      void displayQueue() {
         if (front == rear) {
            cout << "Queue is empty" << endl;
            return;
         }
         for (int i =0; i < capacity; i++) {
            cout << "<-- " << queue[i];
         }
         cout << endl;
      }
};

int main() {
   CircularQueue q(5);

   q.enqueue(1);
   q.enqueue(2);
   q.enqueue(3);
   q.enqueue(4);
   q.enqueue(5);
   q.dequeue();
   q.enqueue(6);
   q.dequeue();
   q.dequeue();
   q.dequeue();
   q.enqueue(7);
   q.enqueue(8);
   q.dequeue();
   q.dequeue();
   q.dequeue();
   q.dequeue();
   q.dequeue();
   q.displayQueue();
   return 0;
}
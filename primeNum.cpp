#include <iostream>
using namespace std;

int main() {
   int lower= 10;
   int higher = 20;

   for (int i = lower; i <= higher; i++) {
      for (int j = 2; j < i; j++) { //divisibility 
         if (i % j == 0) break;
         if (j == i - 1) cout << i << " ";
      }
   }
   return 0;
}
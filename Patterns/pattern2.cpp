#include <iostream>
using namespace std;

int main() {
   /* 
   Outputs:
   *
   * *
   * * *
   * * * *
   */
   int i = 1;
   while (i <= 4) {
      int j = 1;
      while (j <= i) {
         cout << "* ";
         j++;
      }
      cout << endl;
      i++;
   }
}
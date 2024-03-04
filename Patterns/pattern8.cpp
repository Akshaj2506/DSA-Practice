#include <iostream>
using namespace std;

int main() {
   int row = 1;
   int n;
   cout<< "Enter a number: ";
   cin >> n;

   while (row <= n) {
      int columns = 0;
      while (columns < n) {
         char ch = 'A' + columns;
         cout << ch;
         columns++;
      }
      cout << endl;
      row++;
   }
}
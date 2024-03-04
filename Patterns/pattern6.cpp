#include <iostream>
using namespace std;

int main() {
   int row = 1;
   int n;
   cout << "Enter row Limit: ";
   cin >> n;

   while (row <= n) {
      int columns = row;
      while (columns >= 1) {
         cout << columns << " ";
         columns--;
      }
      cout << endl;
      row++;
   }
}
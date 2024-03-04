#include <iostream>
using namespace std;

int main() {
   int i = 0;
   int limit;
   int sum = 0;
   cout << "Enter the limit: ";
   cin >> limit;
   while (sum < limit) {
      int j = 1;
      while (j <= 3) {
         sum = (3*i) + j;
         if (sum > limit) break;
         cout << sum << " ";
         j++;
      }
      i++;
      cout << endl;
   }
}
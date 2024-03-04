#include <iostream>
using namespace std;

int main()
{
   /*
   outputs:
   1
   2 3
   4 5 6
   7 8 9 10
   */
   cout << "Enter max limit: ";
   int limit;
   cin >> limit;
   int i = 1;
   int rows = 1;

   while (i <= limit)
   {
      int columns = 0;
      while (columns < rows) {
         if (i > limit) break;
         cout << i << " ";
         i++;
         columns++;
      }
      rows++;
      cout << endl;
   }
}
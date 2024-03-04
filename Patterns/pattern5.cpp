#include <iostream>
using namespace std;

int main()
{
   int rows = 1;
   int rowLimit;
   cout << "Enter row limit: ";
   cin >> rowLimit;

   while (rows <= rowLimit)
   {
      int columns = 0;
      while (columns < rows)
      {
         cout << rows + columns << " ";
         columns++;
      }
      cout << endl;
      rows++;
   }
}
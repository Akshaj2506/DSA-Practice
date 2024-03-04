#include <iostream>
using namespace std;

int main()
{
   int n;
   cout << "Enter a number: ";
   cin >> n;
   int row = 0;

   while (row < n)
   {
      char ch = 'A' + row;
      int columns = 0;
      while (columns < n)
      {
         cout << ch;
         columns++;
      }
      cout << endl;
      row++;
   }
}
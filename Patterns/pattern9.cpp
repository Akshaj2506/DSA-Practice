#include <iostream>
using namespace std;

int main()
{
   int value = 0;
   int row = 1;
   int n;
   cin >> n;
   char ch = 'A';

   while (value < n)
   {
      int columns = 0;
      while (columns < n)
      {
         cout << ch << " ";
         ch++;
         columns++;
      }
      cout << endl;
      value++;
   }
}
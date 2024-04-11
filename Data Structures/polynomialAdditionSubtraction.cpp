#include <iostream>
using namespace std;

int polynomialOperation(int operation, int *vector1, int *vector2, int i)
{
   if (operation == 0)
      return vector1[i] + vector2[i]; // addition
   return vector1[i] - vector2[i];    // subtraction
}

int main()
{
   int vector1[] = {4, 5, 6};
   int vector2[] = {2, 3, 1};
   int result[sizeof(vector1) / sizeof(vector1[0])];
   int result1[sizeof(vector1) / sizeof(vector1[0])];

   cout << "Addition: ";
   for (int i = 0; i < sizeof(vector1) / sizeof(vector1[0]); i++)
   {
      result[i] = polynomialOperation(0, vector1, vector2, i);
      cout << result[i] << " ";
   }
   cout << endl;
   cout << "Subtraction: ";
   for (int i = 0; i < sizeof(vector2) / sizeof(vector2[0]); i++)
   {
      result1[i] = polynomialOperation(1, vector1, vector2, i);
      cout << result1[i] << " ";
   }
   return 0;
}
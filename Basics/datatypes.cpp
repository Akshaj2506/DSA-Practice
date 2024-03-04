#include <iostream>
using namespace std;

int main() {
   int a = 78;
   cout << a << endl;

   char ch = 'a';

   // Typecasting
   char ch1 = 98;  // Outputs: b which is 
   int int1 = 'b'; // Outputs: 98 which is the ASCII value of 'b' 
   cout << "Character stored in ch is: " << ch1 << endl;
   cout << "Character stored in int1 is: " << int1 << endl;

   float f = 1.247;
   double d = 1.256;

   cout << "Float: " << f << endl;
   cout << "Double: " << d << endl;

   signed int signedinteger = -112;
   unsigned int usignedInt = -112; // Outputs the 2's complement version without the sign

   cout << "Signed Integer: " << signedinteger<< endl;
   cout << "Unsigned Integer: " << usignedInt;
}
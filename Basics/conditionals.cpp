#include <iostream>
using namespace std;

int main() {
   char ch;
   cin >> ch;
   int asciiCode = ch;
   if (asciiCode >= 48 && asciiCode <= 57) {
      cout << ch << " is numeric." << endl;
   }
   else if (asciiCode >= 65 && asciiCode <= 90) {
      cout << ch << " is capitalised." << endl;
   }
   else if (asciiCode >= 97 && asciiCode <= 122) {
      cout << ch << " is small." << endl;
   } else {
      cout << "Invalid character found" << endl;
   }
}
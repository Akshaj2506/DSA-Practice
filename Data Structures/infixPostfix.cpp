#include <iostream>
#include <string>
using namespace std;

char operatorStack[20];
int top = -1;

void push(char ch)
{
   top += 1;
   operatorStack[top] = ch;
}

char pop()
{
   char poppedChar = operatorStack[top];
   top -= 1;
   return poppedChar;
}

char getTop()
{
   return operatorStack[top];
}

int checkPrecedence(char ch)
{
   if (ch == '^')
      return 3;
   if (ch == '*' || ch == '/')
      return 2;
   if (ch == '+' || ch == '-')
      return 1;
   else
      return -1;
}
char associativity(char ch)
{
   if (ch == '^')
      return 'R';
   return 'L';
}
void convertinfixToPostfix(string str)
{
   string result = "";
   cout << "String: " << str << endl;
   for (int i = 0; i < str.length(); i++)
   {
      char ch = str[i];
      if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
         result += ch; // print if operand
      else if (ch == '(')
         push(ch);
      else if (ch == ')')
      {
         while (getTop() != '(')
         {
            result += getTop();
            pop();
         }
         pop();
      }
      else
      { // handling operators
         while (top != -1 && checkPrecedence(ch) <= checkPrecedence(getTop()) && associativity(ch) == 'L')
         {
            result += getTop();
            pop();
         }
         push(ch);
      }
   }
   while (top != -1)
   {
      result += getTop();
      pop();
   }
   cout <<"Postfix: "<< result << endl;
}

int main()
{
   string str = "a+b*(c^d-e)^(f+g*h)-i";
   convertinfixToPostfix(str);
   return 0;
}
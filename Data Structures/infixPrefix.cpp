#include <iostream>
#include <string>
using namespace std;

class CharacterStack
{
private:
   char *stack;

public:
   int top;
   int capacity;

   CharacterStack(int capacity)
   {
      this->capacity = capacity;
      stack = new char[capacity];
      top = -1;
   }

   void push(char ch)
   {
      if (top == capacity - 1)
         cout << "Stack Overflow" << endl;
      stack[++top] = ch;
   }

   char peek()
   {
      if (top == -1)
      {
         cout << "Stack is empty" << endl;
         return ' ';
      }
      return stack[top];
   }

   char pop()
   {
      if (top == -1)
      {
         cout << "Stack Underflow" << endl;
         return ' ';
      }
      return stack[top--];
   }
};

int checkPrecedence(char ch)
{
   if (ch == '-' || ch == '+')
      return 1;
   if (ch == '*' || ch == '/')
      return 2;
   if (ch == '^')
      return 3;
   return 0;
}

string convertInfixToPostfix(string infixStr)
{
   infixStr = '(' + infixStr + ')';
   CharacterStack chStack(infixStr.length());
   string output;

   for (int i = 0; i < infixStr.length(); i++)
   {
      char ch = infixStr[i];
      if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
         output += ch;
      else if (ch == '(')
         chStack.push(ch);
      else if (ch == ')')
      {
         while (chStack.peek() != '(')
         {
            output += chStack.peek();
            chStack.pop();
         }
         chStack.pop();
      }
      else
      {
         while ((chStack.peek() != ' ') && (checkPrecedence(chStack.peek()) >= checkPrecedence(ch)))
         {
            output += chStack.peek();
            chStack.pop();
         }
         chStack.push(ch);
      }
   }
   while (chStack.top != -1)
   {
      output += chStack.peek();
      chStack.pop();
   }
   return output;
}

char inverseParenthesis(char ch)
{
   if (ch == '(')
      return ')';
   if (ch == ')')
      return '(';
   return ch;
}
string reverse_str(string str)
{
   for (int i = 0; i < (str.length() / 2); i++)
   {
      if (str.length() % 2 != 0 && i == ((str.length() / 2)))
         break;
      char temp = str[str.length() - i - 1];
      str[str.length() - i - 1] = str[i];
      str[i] = temp;
   }
   for (int j = 0; j < str.length(); j++) {
      str[j] = inverseParenthesis(str[j]);
   }
   return str;
}

int main()
{
   string str = "(A-B/C)*(A/K-L)";
   cout << "Postfix: " << convertInfixToPostfix(str) << endl;
   cout << "Prefix: " <<  reverse_str(convertInfixToPostfix(reverse_str(str))) << endl;
}
#include <iostream>

struct Node
{
   int info;
   Node *link;
};

Node *addNode(Node *start, int data)
{
   Node *newNode = new Node{data, NULL};
   if (start == NULL)
   {
      start = newNode;
   }
   else
   {
      Node *temp = start;
      while (temp->link != NULL)
      {
         temp = temp->link;
      }
      temp->link = newNode;
   }
   return start;
}

Node *splitList(Node *start, Node *&pList, Node *&nList)
{
   Node *move = start;
   Node *temp;
   Node *temp1;

   pList = NULL;
   nList = NULL;

   while (move != NULL)
   {
      if (move->info < 0)
      {
         if (nList == NULL)
         {
            nList = move;
            temp = nList;
         }
         else
         {
            temp->link = move;
            temp = temp->link;
         }
      }
      else
      {
         if (pList == NULL)
         {
            pList = move;
            temp1 = pList;
         }
         else
         {
            temp1->link = move;
            temp1 = temp1->link;
         }
      }
      move = move->link;
   }

   if (temp != NULL)
   {
      temp->link = NULL;
   }
   if (temp1 != NULL)
   {
      temp1->link = NULL;
   }

   return start;
}

void displayList(Node *head)
{
   while (head != NULL)
   {
      std::cout << head->info << " ";
      head = head->link;
   }
   std::cout << std::endl;
}

int main()
{
   Node *start = NULL;
   Node *pList = NULL;
   Node *nList = NULL;

   int choice, data;

   do
   {
      std::cout << "Choose an option:\n";
      std::cout << "1. Add\n";
      std::cout << "2. Split\n";
      std::cout << "3. Display Positive List\n";
      std::cout << "4. Display Negative List\n";
      std::cout << "5. Exit\n";

      std::cin >> choice;

      switch (choice)
      {
      case 1:
         std::cout << "Enter data to add: ";
         std::cin >> data;
         start = addNode(start, data);
         break;
      case 2:
         start = splitList(start, pList, nList);
         break;
      case 3:
         std::cout << "Positive List: ";
         displayList(pList);
         break;
      case 4:
         std::cout << "Negative List: ";
         displayList(nList);
         break;
      case 5:
         std::cout << "Exiting...\n";
         break;
      default:
         std::cout << "Invalid choice!\n";
      }

   } while (choice != 5);

   return 0;
}
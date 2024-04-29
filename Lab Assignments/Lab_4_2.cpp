#include <iostream>

struct Node
{
   int data;
   Node *next;
};

Node *insertAscending(Node *head, int newData)
{
   Node *newNode = new Node{newData, nullptr};

   if (head == nullptr || head->data >= newData)
   {
      newNode->next = head;
      head = newNode;
   }
   else
   {
      Node *current = head;
      while (current->next != nullptr && current->next->data < newData)
      {
         current = current->next;
      }
      newNode->next = current->next;
      current->next = newNode;
   }

   return head;
}

void displayList(Node *head)
{
   while (head != nullptr)
   {
      std::cout << head->data << " ";
      head = head->next;
   }
   std::cout << std::endl;
}

int main()
{
   Node *head = nullptr;

   int choice, data;

   do
   {
      std::cout << "Choose an option:\n";
      std::cout << "1. Insert Element in Ascending Order\n";
      std::cout << "2. Display List\n";
      std::cout << "3. Exit\n";

      std::cin >> choice;

      switch (choice)
      {
      case 1:
         std::cout << "Enter data to insert: ";
         std::cin >> data;
         head = insertAscending(head, data);
         break;
      case 2:
         std::cout << "List: ";
         displayList(head);
         break;
      case 3:
         std::cout << "Exiting...\n";
         break;
      default:
         std::cout << "Invalid choice!\n";
      }

   } while (choice != 3);

   return 0;
}
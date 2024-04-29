#include <iostream>
using namespace std;

// Node structure for a linked list
struct Node
{
   int data;
   Node *next;
};

// Function to insert a node into a linked list in ascending order
void insertNode(Node *&head, int value)
{
   Node *newNode = new Node;
   newNode->data = value;
   newNode->next = nullptr;

   if (head == nullptr || head->data >= value)
   {
      newNode->next = head;
      head = newNode;
   }
   else
   {
      Node *current = head;
      while (current->next != nullptr && current->next->data < value)
      {
         current = current->next;
      }
      newNode->next = current->next;
      current->next = newNode;
   }
}

// Function to merge two sorted linked lists into one sorted linked list
Node *mergeLists(Node *list1, Node *list2)
{
   Node *mergedList = nullptr;
   Node *tail = nullptr;

   while (list1 != nullptr && list2 != nullptr)
   {
      if (list1->data <= list2->data)
      {
         insertNode(mergedList, list1->data);
         list1 = list1->next;
      }
      else
      {
         insertNode(mergedList, list2->data);
         list2 = list2->next;
      }
   }

   while (list1 != nullptr)
   {
      insertNode(mergedList, list1->data);
      list1 = list1->next;
   }

   while (list2 != nullptr)
   {
      insertNode(mergedList, list2->data);
      list2 = list2->next;
   }

   return mergedList;
}

// Function to display a linked list
void displayList(Node *head)
{
   Node *temp = head;
   while (temp != nullptr)
   {
      cout << temp->data << " ";
      temp = temp->next;
   }
   cout << endl;
}

int main()
{
   Node *list1 = nullptr;
   Node *list2 = nullptr;
   int value;

   cout << "Enter nodes for the first list (enter -1 to stop):\n";
   while (true)
   {
      cin >> value;
      if (value == -1)
         break;
      insertNode(list1, value);
   }

   cout << "Enter nodes for the second list (enter -1 to stop):\n";
   while (true)
   {
      cin >> value;
      if (value == -1)
         break;
      insertNode(list2, value);
   }

   cout << "First List: ";
   displayList(list1);

   cout << "Second List: ";
   displayList(list2);

   Node *mergedList = mergeLists(list1, list2);

   cout << "Merged List: ";
   displayList(mergedList);

   return 0;
}
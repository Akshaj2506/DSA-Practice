#include <iostream>
using namespace std;

void swapping(int arr[], int x, int y)
{
   int temp = arr[x];
   arr[x] = arr[y];
   arr[y] = temp;
}

void heapify(int a[], int i, int n)
{
   int largest = i;
   int left = (2 * i + 1 < n)? 2 * i + 1 : -1;
   int right = (2 * i + 2 < n)? (2 * i) + 2 : -1;

   if ((left != -1) && (left < n) && (a[left] > a[largest]))
   {
      largest = left;
   }
   if ((right != -1) && (right < n) && (a[right] > a[largest]))
   {
      largest = right;
   }

   if (largest != i)
   {
      swapping(a, largest, i);
      heapify(a, largest, n);
   }
}

void buildMaxHeap(int arr[], int n)
{
   for (int i = (n / 2) - 1; i >= 0; i--)
   {
      heapify(arr, i, n);
   }
}

int main()
{
   int arr[] = {34, 45, 21, 6, 55, 31};
   int n = sizeof(arr) / sizeof(arr[0]);
   buildMaxHeap(arr, n);

   for (int i = 0; i < n; i++) {
      cout<< arr[i] << " ";
   }
   cout << endl;
   return 0;
}

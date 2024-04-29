#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Graph
{
private:
   int V;                   // Number of vertices
   vector<vector<int>> adj; // Adjacency list

public:
   Graph(int V) : V(V)
   {
      adj.resize(V);
   }

   void addEdge(int u, int v)
   {
      adj[u].push_back(v);
   }

   // Breadth-First Traversal (BFT)
   void BFT(int start)
   {
      vector<bool> visited(V, false);
      vector<int> queue;

      visited[start] = true;
      queue.push_back(start);

      while (!queue.empty())
      {
         int u = queue.front();
         queue.erase(queue.begin());
         cout << u << " ";

         for (int v : adj[u])
         {
            if (!visited[v])
            {
               visited[v] = true;
               queue.push_back(v);
            }
         }
      }
      cout << endl;
   }

   // Depth-First Traversal (DFT)
   void DFT(int start)
   {
      vector<bool> visited(V, false);
      vector<int> stack;

      visited[start] = true;
      stack.push_back(start);

      while (!stack.empty())
      {
         int u = stack.back();
         stack.pop_back();
         cout << u << " ";

         for (int v : adj[u])
         {
            if (!visited[v])
            {
               visited[v] = true;
               stack.push_back(v);
            }
         }
      }
      cout << endl;
   }
};

int main()
{
   Graph g(4);
   g.addEdge(0, 1);
   g.addEdge(0, 2);
   g.addEdge(1, 2);
   g.addEdge(2, 0);
   g.addEdge(2, 3);
   g.addEdge(3, 3);

   cout << "Breadth-First Traversal (BFT): ";
   g.BFT(2); // Starting traversal from vertex 2
   cout << "Depth-First Traversal (DFT): ";
   g.DFT(2); // Starting traversal from vertex 2

   return 0;
}

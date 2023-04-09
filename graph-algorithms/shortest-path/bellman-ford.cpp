#include <bits/stdc++.h>
using namespace std;

// Bellman Ford Algorithm
// Time Complexity: O(V*E - 1)
// Space Complexity: O(V)

// Bellman ford is a single source shortest path algorithm which can handle -ve edge weights
// It can also detect -ve edge weight cycles, IT DOES NOT WORK FOR -ve weight cycles
// It works by relaxing all the edges V-1 times, where V is the number of vertices

// We run a loop again and try to relax the edges one more time, if we are able to relax any edge, then we have a -ve edge weight cycle
// and we can return -1 to indicate that the graph has a -ve edge weight cycle

// Bellman ford is considered to be a more general version of Dijkstra's algorithm and is slower than Dijkstra's algorithmm

// Step 1: Create a structure variable to house the properties of an edge
//         int source;
//         int weight;
//         int destination;
struct edge
{
  int source;
  int weight;
  int destination;
};

// Step 2: Create a function to implement bellman ford algorithm
//         it takes the following parameters
//         vector of edges
//         number of nodes
//         source node
int bellman_ford(vector<edge> edges, int nums_nodes, int source)
{
  int nums_edges = edges.size();

  // Step 3: Create a vector to store the distances from the source node to every other node
  vector<int> distances(nums_nodes, INT_MAX);
  // Set the distance of the source node to itself to be 0 as it is the source node
  distances[source] = 0;

  // According to the bellman ford algorithm we need to relax all the edges V-1 times
  // where V is the number of vertices
  // We run a loop V-1 times and relax all the edges

  // Step 4: Start a loop to relax the all the edges nums_nodes-1 times
  for (int i = 0; i < nums_nodes; i++)
  {
    // Here we are relaxing all the edges
    for (int j = 0; j < nums_edges; j++)
    {
      int source = edges[j].source;
      int weight = edges[j].weight;
      int destination = edges[j].destination;
      // In the first part of this condition we are making sure that source and desination are not INT_MAX
      // Since infinity + something is still infinity, we need to make sure that we are not adding infinity to something

      // The second part of the condition is the actual relaxation condition
      if (source != INT_MAX && destination != INT_MAX && distances[source] + weight < distances[destination])
      {
        distances[destination] = weight + distances[source];
      }
    }
  }

  // Step 5: We run a loop again and try to relax the edges one more time, if we are able to relax any edge, then we have a -ve edge weight cycle
  //        and we can return -1 to indicate that the graph has a -ve edge weight cycle
  for (int i = 0; i < nums_edges; i++)
  {
    int source = edges[i].source;
    int weight = edges[i].weight;
    int destination = edges[i].destination;
    if (source != INT_MAX && destination != INT_MAX && distances[source] + weight < distances[destination])
    {
      cout << "the graph has a -ve edge weight cycle and hence bellman ford cant give a correct answer for this \n";
      return -1;
    }
  }

  // Step 6: Print the distances from the source node to every other node
  cout << "Vertex\tDistance from source\n";
  for (int i = 0; i < distances.size(); i++)
  {
    cout << i << "\t\t" << distances[i] << "\n";
  }
  return 0;
}

int main()
{
  int num_edges, num_vertices, source;
  cout << "Enter the number of vertices in graph : ";
  cin >> num_vertices;
  cout << "Enter the number of edges in graph : ";
  cin >> num_edges;

  vector<edge> edges(num_edges);

  cout << "enter the source, weight and destination of every edge (in that format) : \n";

  for (int i = 0; i < num_edges; i++)
  {
    cin >> edges[i].source >> edges[i].weight >> edges[i].destination;
  }

  cout << "enter the source vertex : ";
  cin >> source;
  bellman_ford(edges, num_vertices, source);

  return 0;
}
#include <iostream>
#include <vector>

using std::vector;

void floyd_warshall(vector<vector<int>> &graph, int nums_vertices)
{
  // Step 1: Initialize the distance matrix and set it to the graph
  vector<vector<int>> distances(nums_vertices, vector<int>(nums_vertices, INT_MAX));

  for (int i = 0; i < nums_vertices; i++)
  {
    for (int j = 0; j < nums_vertices; j++)
    {
      if (graph[i][j] != -1)
      {
        distances[i][j] = graph[i][j];
      }
    }
  }

  // Step 2: Set the diagonal elements to zero

  for (int i = 0; i < nums_vertices; i++)
  {
    distances[i][i] = 0;
  }

  // Step 3: Update the distance matrix with shortest distances between every paor of vertices
  for (int k = 0; k < nums_vertices; k++)
  {
    for (int i = 0; i < nums_vertices; i++)
    {
      for (int j = 0; j < nums_vertices; j++)
      {
        if (distances[i][k] != INT_MAX && distances[k][j] != INT_MAX && distances[i][k] + distances[k][j] < distances[i][j])
        {
          distances[i][j] = distances[i][k] + distances[k][j];
        }
      }
    }
  }

  // Step 4: Check for -ve edge weight cycles

  for (int k = 0; k < nums_vertices; k++)
  {
    for (int i = 0; i < nums_vertices; i++)
    {
      for (int j = 0; j < nums_vertices; j++)
      {
        if (distances[i][k] != INT_MAX && distances[k][j] != INT_MAX && distances[i][k] + distances[k][j] < distances[i][j])
        {
          std::cout << "graph contains a -ve edge weight cycle"
                    << "\n";
          return;
        }
      }
    }
  }

  // Step 5: Print the solution

  for (int i = 0; i < nums_vertices; i++)
  {
    for (int j = 0; j < nums_vertices; j++)
    {
      if (distances[i][j] == INT_MAX)
      {
        std::cout << "∞ ";
      }
      else
      {
        std::cout << distances[i][j] << " ";
      }
    }
    std::cout << "\n";
  }
}

int main()
{
  int nums_vertices, infinity_value;
  std::cout << "Enter the number of vertices : ";
  std::cin >> nums_vertices;
  std::cout << "Enter the value you will use to denote INF (or no direct edge) : ";
  std::cin >> infinity_value;
  vector<vector<int>> graph(nums_vertices, vector<int>(nums_vertices, INT_MAX));

  for (int i = 0; i < nums_vertices; i++)
  {
    for (int j = 0; j < nums_vertices; j++)
    {
      std::cin >> graph[i][j];
      if (graph[i][j] == infinity_value)
      {
        graph[i][j] = INT_MAX;
      }
    }
  }

  floyd_warshall(graph, nums_vertices);
}
#include <bits/stdc++.h>
using namespace std;

bool bfs(vector<vector<int>> &residue_graph, int source, int sink, vector<int> &parent, int nums_vert)
{
  vector<bool> visited(nums_vert, false);

  queue<int> q;
  q.push(source);
  visited[source] = true;
  parent[source] = -1;

  while (!q.empty())
  {
    int front = q.front();
    q.pop();

    for (int vertex = 0; vertex < nums_vert; vertex++)
    {
      if (!visited[vertex] && residue_graph[front][vertex] > 0)
      {
        if (vertex == sink)
        {
          parent[vertex] = front;
          return true;
        }
        q.push(vertex);
        parent[vertex] = front;
        visited[vertex] = true;
      }
    }
  }
  return false;
}

int edmond_karp(vector<vector<int>> graph, int source, int sink, int nums_vert)
{
  int max_flow = 0;
  vector<vector<int>> residue_graph(nums_vert, vector<int>(nums_vert));

  for (int i = 0; i < nums_vert; i++)
  {
    for (int j = 0; j < nums_vert; j++)
    {
      residue_graph[i][j] = graph[i][j];
    }
  }

  vector<int> parent(nums_vert);
  while (bfs(residue_graph, source, sink, parent, nums_vert))
  {
    int path_bottleneck = INT_MAX;

    for (int vertex = sink; vertex != source; vertex = parent[vertex])
    {
      int parent_vertex = parent[vertex];
      path_bottleneck = min(path_bottleneck, residue_graph[parent_vertex][vertex]);
    }

    for (int vertex = sink; vertex != source; vertex = parent[vertex])
    {
      int parent_vertex = parent[vertex];
      residue_graph[parent_vertex][vertex] -= path_bottleneck;
      residue_graph[vertex][parent_vertex] += path_bottleneck;
    }

    max_flow += path_bottleneck;
  }
  return max_flow;
}

int main()
{
  // Let us create a graph shown in the above example
  vector<vector<int>> graph = {{0, 16, 13, 0, 0, 0}, {0, 0, 10, 12, 0, 0}, {0, 4, 0, 0, 14, 0}, {0, 0, 9, 0, 0, 20}, {0, 0, 0, 7, 0, 4}, {0, 0, 0, 0, 0, 0}};

  cout << "The maximum possible flow is " << edmond_karp(graph, 0, 5, 6);

  return 0;
}

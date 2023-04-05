#include <bits/stdc++.h>
using namespace std;

// Step 1: Create a function to print the solution vector (colors)
void print_solution(vector<int> colors)
{
  for (int i = 0; i < colors.size(); i++)
  {
    cout << colors[i] << " ";
  }
  cout << "\n";
}

// Step 2: Create a function to check if the solution is safe
//         (no adjacent nodes have the same color)
//         This function is similar to the one in subset-sum.cpp
//         The only difference is that we are checking the graph

// The reason we initialize the value of j = i + 1 is because we don't want to check the same node twice
// for example if we have a graph like this
// 0 1 1
// 1 0 1
// 1 1 0
// we don't want to check if graph[0][0] && colors[0] == colors[0] since that is the same node
// so we start at j = i + 1

// the condition graph[i][j] && colors[i] == colors[j] basically checks this
// it checks if there is a edge between those two nodes and if so then it checks if they have the same color
// if they have the same color and have a edge between them then it returns false since the
// solution is not safe
bool isSafe(vector<vector<int>> graph, vector<int> colors)
{
  for (int i = 0; i < graph.size(); i++)
  {
    for (int j = i + 1; j < graph.size(); j++)
    {
      if (graph[i][j] && colors[i] == colors[j])
      {
        return false;
      }
    }
  }
  return true;
}

// Step 3: Create a function to solve the problem
//         It takes the following inputs:
//         graph: the graph we are coloring
//         nums_colors: the number of colors we are using
//         index: the index of the node we are coloring
//         colors: the vector that holds the colors of the nodes

bool graph_coloring(vector<vector<bool>> graph, int nums_colors, int index, vector<int> colors)
{
  // Step 3.1: Base case when we have colored all the nodes
  if (nums_colors == index)
  {
    // Call the print_solution function to print the solution and return true since we
    // have found a solution and colored the graph
    print_solution(colors);
    return true;
  }

  // Since the base case condition has not been triggered we know that we have not colored all the nodes
  // Step 3.2: Loop through all the colors and try to color the node with each color
  for (int i = index; i <= nums_colors; i++)
  {
    // Set the color of current node (index) to i (the color we are trying)
    colors[index] = i;
    // Check if the solution is safe
    // Call the same function for the next node (index + 1)
    if (graph_coloring(graph, nums_colors, index + 1, colors))
    {
      // If this returns true we know the graph has been colored and we can return true
      return true;
    }
    // Backtracking step (reset the color of the node to 0)
    colors[index] = 0;
  }
  // This would only ever be reached if there is no solution
  return false;
}

int main()
{
  vector<vector<bool>> graph = {{0, 1, 1, 1},
                                {1, 0, 1, 0},
                                {1, 1, 0, 1},
                                {1, 0, 1, 0}};
  int nums_colors = 3;
  int index = 0;
  vector<int> colors(graph.size(), 0);
  bool solved = graph_coloring(graph, nums_colors, index, colors);
  if (!solved)
    cout << "No solution found\n";
  return 0;
}
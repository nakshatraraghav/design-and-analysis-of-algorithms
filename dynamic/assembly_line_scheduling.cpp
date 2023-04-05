#include <bits/stdc++.h>
using namespace std;

// The assembly line problem is a special case of the shortest path problem.
// it is implemented using dynamic programming. The problem is to find the minimum cost path from the entry point to the exit point.
// in this variation of the problem i have also found the optimal path to be taken

// Step 1: Create the assembly function that takes the following inputs
//         processing: the time taken to process a part at each station
//         transportation: the time taken to transport a part from one line to another
//         transportation[0][i] means transporting a part from line 1 to line 2 at station i and
//         transportation[1][i] means transporting a part from line 2 to line 1 at station i
//         entry: the cost to enter the assembly line
//         exit: the cost to exit the assembly line
void assembly(vector<vector<int>> processing, vector<vector<int>> transportation, vector<int> entry, vector<int> exit, int nums_stations)
{
  // Step 1: Create the first_line and second_line vectors to store the minimum cost to reach each station
  //         the final value (value stored at nums_stations - 1) will be added to exit cost to get the total cost
  //         minimum of these values will be the minimum cost to reach the exit point
  vector<int> first_line(nums_stations, 0);
  vector<int> second_line(nums_stations, 0);

  // Step 2: Create the path vector to store the path taken to reach each station
  vector<vector<int>> path(nums_stations, vector<int>(nums_stations, 0));
  int same_line = 0, change_line = 0;

  // Step 3: Initialize the first station values in first_line and second_line vectors
  first_line[0] = entry[0] + processing[0][0];
  second_line[0] = entry[1] + processing[1][0];

  // Step 4: Create a for loop to iterate through the stations
  for (int i = 1; i < nums_stations; i++)
  {
    // calulating the cost if we stay on the same line
    same_line = first_line[i - 1] + processing[0][i];
    // calculating the cost if we change the line
    change_line = second_line[i - 1] + transportation[1][i] + processing[0][i];

    // Whichever is the minimum, store it in the first_line vector
    if (same_line < change_line)
    {
      // if we stay on the same line, store 1 in the path vector, that means we came from the same line
      first_line[i] = same_line;
      path[0][i] = 1;
    }
    else
    {
      // otherwise we came from the opposite line and hence we store 2 in the path vector
      first_line[i] = change_line;
      path[0][i] = 2;
    }

    // Similarly do the same for the second line
    same_line = second_line[i - 1] + processing[1][i];
    change_line = first_line[i - 1] + transportation[0][i] + processing[1][i];

    if (same_line < change_line)
    {
      second_line[i] = same_line;
      path[1][i] = 2;
    }
    else
    {
      second_line[i] = change_line;
      path[1][i] = 1;
    }
  }
  // Step 5: Print the minimum cost to reach the exit point
  //         in the first_line and second_line vectors at the index nums_stations - 1, we have the minimum cost to reach the exit point
  //         that value is added to the exit cost and the minimum of these two values is the minimum cost to reach the exit point

  //         if total cost of line 1 is less than line 2, print the path taken in line 1
  //         otherwise print the path taken in line 2
  if (first_line[nums_stations - 1] + exit[0] < second_line[nums_stations - 1] + exit[1])
  {
    cout << "The total cost is : " << first_line[nums_stations - 1] + exit[0] << "\n";
    cout << "The path taken is : ";
    for (int i = 0; i < nums_stations; i++)
    {
      cout << path[0][i] << "->";
    }
  }
  else
  {
    cout << "The total cost is : " << second_line[nums_stations - 1] + exit[1] << "\n";
    cout << "The path taken is : ";
    for (int i = 0; i < nums_stations; i++)
    {
      cout << path[1][i] << "->";
    }
  }
}

int main()
{
  int nums_stations;
  cout << "Enter the number of stations : ";
  cin >> nums_stations;
  vector<vector<int>> processing(nums_stations, vector<int>(nums_stations, 0));
  vector<vector<int>> transportation(nums_stations, vector<int>(nums_stations, 0));
  vector<int> entry(2, 0);
  vector<int> exit(2, 0);

  cout << "Enter the processing time for each station in each line : \n";
  for (int i = 0; i < 2; i++)
  {
    for (int j = 0; j < nums_stations; j++)
    {
      cin >> processing[i][j];
    }
  }

  cout << "Enter the transportation time for each station in each line : \n";
  for (int i = 0; i < 2; i++)
  {
    for (int j = 0; j < nums_stations; j++)
    {
      cin >> transportation[i][j];
    }
  }

  cout << "Enter the entry time for each line : ";
  for (int i = 0; i < 2; i++)
  {
    cin >> entry[i];
  }

  cout << "Enter the exit time for each line : ";
  for (int i = 0; i < 2; i++)
  {
    cin >> exit[i];
  }

  assembly(processing, transportation, entry, exit, nums_stations);

  return 1;
}

// int main()
// {
//   vector<vector<int>> processing = {{8, 10, 4, 5, 9}, {9, 6, 7, 5, 6}};
//   vector<vector<int>> transportation = {{0, 2, 3, 1, 3}, {0, 2, 1, 2, 2}};
//   vector<int> entry = {3, 5};
//   vector<int> exit = {2, 1};
//   int nums_stations = 5;
//   assembly(processing, transportation, entry, exit, nums_stations);
//   return 0;
// }
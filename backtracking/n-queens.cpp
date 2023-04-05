#include <bits/stdc++.h>
using namespace std;

// N-Queens Problem Using Backtracking

// The N Queen is the problem of placing N chess queens on an N×N chessboard so that no two queens attack each other.
// For example, following is a solution for 4 Queen problem.
// The expected output is a binary matrix which has 1s for the blocks where queens are placed. For example, the following is the output matrix for above 4 queen solution.
// { 0,  1,  0,  0}
// { 0,  0,  0,  1}
// { 1,  0,  0,  0}
// { 0,  0,  1,  0}

void print_solution(vector<vector<int>> board, int nums)
{
  for (int i = 0; i < nums; i++)
  {
    for (int j = 0; j < nums; j++)
    {
      if (board[i][j])
      {
        cout << "Q ";
      }
      else
      {
        cout << ". ";
      }
    }
    cout << "\n";
  }
}

bool isSafe(vector<vector<int>> board, int row, int col, int nums)
{
  int orignal_row = row, orignal_col = col;
  // Step 1: Check for another queens in Upper Diagonal
  while (row >= 0 && col >= 0)
  {
    if (board[row][col])
    {
      return false;
    }
    row--;
    col--;
  }
  row = orignal_row;
  col = orignal_col;
  // Step 2: Check for another queen in the same row
  while (col >= 0)
  {
    if (board[row][col])
    {
      return false;
    }
    col--;
  }
  row = orignal_row;
  col = orignal_col;
  // Step 3: Check for the another queen in the Lower Diagonal
  while (row < nums && col >= 0)
  {
    if (board[row][col])
    {
      return false;
    }
    row++;
    col--;
  }

  return true;
}

void solve(vector<vector<int>> &board, int col, int nums)
{
  if (col == nums)
  {
    // Solution Found
    print_solution(board, nums);
    return;
  }

  for (int row = 0; row < nums; row++)
  {
    if (isSafe(board, row, col, nums))
    {
      board[row][col] = 1;
      solve(board, col + 1, nums);
      board[row][col] = 0;
    }
  }
  return;
}

int main()
{
  int nums;
  cin >> nums;
  vector<vector<int>> board(nums, vector<int>(nums, 0));
  solve(board, 0, nums);
  return 0;
}
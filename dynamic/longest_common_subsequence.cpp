#include <bits/stdc++.h>
using namespace std;

// Longest Common Subsequence
// Given two strings, find the length of longest common subsequence present in both of them.
// A subsequence is a sequence that appears in the same relative order, but not necessarily contiguous.
// For example, “abc”, “abg”, “bdf”, “aeg”, ‘”acefg”, .. etc are subsequences of “abcdefg”.

// Step 1: Creating the longest common subsequences function
//         which takes two strings as input and returns the length of longest common subsequence
int longest_common_subsequence(string x, string y)
{
  int xlen = x.length(), ylen = y.length();
  // Step 2: Creating the lookup table
  vector<vector<int>> dp(xlen + 1, vector<int>(ylen + 1, 0));

  // Step 3: Starting the loop
  for (int i = 0; i <= xlen; i++)
  {
    for (int j = 0; j <= ylen; j++)
    {
      // Step 4: Checking the base condition
      if (i == 0 || j == 0)
      {
        dp[i][j] = 0;
      }
      // Step 5: Checking if the characters are same
      else if (x[i - 1] == y[j - 1])
      {
        // Step 6: If the characters are same then we will add 1 to the previous value
        dp[i][j] = 1 + dp[i - 1][j - 1];
      }
      else
      {
        // Step 7: If the characters are not same then we will take the maximum of previous values
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }
  return dp[xlen][ylen];
}

int main()
{
  string x, y;
  cout << "Enter the first string : ";
  cin >> x;
  cout << "Enter the second string : ";
  cin >> y;

  cout << "longest common subsequence length is : " << longest_common_subsequence(x, y);
  return 0;
}
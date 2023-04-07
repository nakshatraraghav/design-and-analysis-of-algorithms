#include <bits/stdc++.h>
using namespace std;

// Knuth-Morris-Pratt Algorithm
// Time Complexity: O(N + M)

// The Knuth-Morris-Pratt algorithm is a string matching algorithm that uses the concept of longest prefix suffix array
// it works by calculating the longest prefix that is also a suffix in the pattern string
// it then uses this array to skip the characters that are already matched in the pattern string
// it then checks if the next character in the pattern string matches the next character in the main string
// if it does then it moves on to the next character in the pattern string
// if it does not then it skips the characters that are already matched in the pattern string

void calculate_lps(std::string pattern, std::vector<int> lps)
{
  int i = 0, j = 1;
  lps[0] = 0;

  while (j < pattern.length())
  {
    if (pattern[i] == pattern[j])
    {
      i++;
      j++;
    }
    else
    {
      if (i == 0)
      {
        lps[j] = 0;
        j++;
      }
      else
      {
        i = lps[i - 1];
      }
    }
  }
}

int knuth_morris_pratt(std::string str, std::string pat)
{
  int slen = str.length(), plen = pat.length();
  int i = 0, j = 0;
  int count = 0;

  std::vector<int> lps(plen, 0);
  calculate_lps(pat, lps);

  while (i < slen)
  {
    if (str[i] == pat[j])
    {
      i++;
      j++;
    }

    if (plen == j)
    {
      std::cout << "pattern found at " << i - plen << "\n";
      j = lps[j - 1];
      count++;
    }
    else if (i < slen && str[i] != pat[j])
    {
      if (j == 0)
      {
        i++;
      }
      else
      {
        j = lps[j - 1];
      }
    }
  }
  return count - 1;
}
int main()
{
  string str = "abcabcabcabcabc";
  string pat = "abc";
  cout << "total occurences of pattern are : " << knuth_morris_pratt(str, pat);
  return 0;
}
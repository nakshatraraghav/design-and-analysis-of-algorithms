#include <bits/stdc++.h>
using namespace std;

// Naive String Matching Algorithm
// Time Complexity: O(N * M)
// The naive string matching algorithm is a simple algorithm that compares the pattern with all the substrings
// of the text of length M. If the pattern is found, the algorithm returns the index of the first character of
// the substring that matches the pattern. Otherwise, the algorithm returns -1.

// Since the time complexity of this naive string matching algorithm is O(N * M), it is not suitable for large
// and it is recommended that we use the KMP algorithm or the Rabin-Karp algorithm for large strings.
// Time Complexity of KMP Algorithm: O(N + M)
// Time Complexity of Rabin-Karp Algorithm: O(N + M)

// Step 1: naive_string_matching function returns the number of times the pattern string occurs in the main string
//         if the string does not occur in the main string, it returns -1

//         Inputs: Main String and the Pattern String
int naive_string_matching(string str, string pat)
{
  // Step 2: Initialize the length of the main string and the pattern string
  int slen = str.length(), plen = pat.length();
  // Step 3: Initialize the count variable to 0 and set j to 0 for the inner loop
  int j = 0, count = 0;
  for (int i = 0; i <= slen - plen; i++)
  {
    // In this loop we are basically checking if the i + jth character of the main string is equal to the jth
    // while simeultanesouly j should be less then plen
    // this loop would terminate iff
    // 1. j becomes equal to plen
    // 2. the i + jth character of the main string is not equal to the jth character of the pattern string

    while (j < plen && str[i + j] == pat[j])
    {
      j++;
    }

    // in this part we check if j is equal to plen if so then we know that the pattern string has been found
    // and we increment the count variable by 1 to indicate the number of occurence of the pattern string
    if (j == plen)
    {
      cout << "pattern found at index : " << i << "\n";
      count++;
    }

    j = 0;
  }

  // if the count variable is 0 then we know that the pattern string does not occur in the main string
  if (count == 0)
  {
    return -1;
  }

  // otherwise we return the count variable which indicates the number of occurences of the pattern string
  return count;
}

int main()
{
  string x, y;
  cout << "enter the first string : ";
  cin >> x;
  cout << "enter the second string: ";
  cin >> y;

  int occurences = naive_string_matching(x, y);
  if (occurences != -1)
  {
    cout << "the pattern string occured " << occurences << " times in the main string \n";
  }
  else
  {
    cout << "pattern string does not occur in the main string";
  }
  return 0;
}